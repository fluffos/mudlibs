# Sundering Shadows -- porting notes

Source: `git clone https://github.com/MudRen/SunderingShadows` (a fork of
`SuS-Tsera/SunderingShadows`, commit `0fb3102f9058f7d756be6c81f88a6bee04a5c8ff`,
cloned 2026-08-26). The repo's own `README` says it best: "This repository is
synced with the mud every 30 minutes, so any changes made in game will be
reflected here." Real, currently-live English-language content: 43,147 files,
~47MB, a Nightmare/TMI-lineage mudlib heavily customized over what looks like
decades of active development. Slug `sunshadow`, number 930, port 40232.

## 1. Conversion

Pure ASCII archive -- no encoding-normalization work needed. `convert_lib.sh`
renamed every `.c` to `.lpc` (roughly 41,000 files) and ran the usual
`static`->`nosave`/`protected` sweep with no collisions found. All headers
resolve through `/adm/include/` (a handful of files also use local
`#include "dieties.h"`-style relative includes, which resolved fine as-is).

## 2. The pervasive same-file forward-reference gap

This driver compiles each file in a single top-to-bottom pass, unlike the
two-pass compiler the original archive was clearly written against: calling
a function defined *later* in the same file, with no forward declaration,
is a hard compile error here. A corpus-wide scan (`scan_forward_calls.py`)
found 3,212 files with at least one such call (8,453 sites total); a
de-duplication pass found the archive's own authors had already added the
*correct* forward declaration in ~65% of cases (5,465 of ~8,438 inserted
lines were exact duplicates of an existing declaration elsewhere in the same
file) -- removed those duplicates, leaving ~2,973 genuine fixes applied
mechanically.

## 3. `map_delete()` dialect: void/in-place here, not return-the-mapping

Classic MudOS/LDMud-vintage code assumes `map_delete()` returns the
resulting mapping; on this driver it's `void` and mutates in place. Found
live via `daemon/multi_d.lpc:169`'s `whoWhen = map_delete(whoWhen,who);`
breaking that whole file's compile -- which mattered immediately, because
`login.lpc`'s `get_name()` calls `MULTI_D->is_allowed(...)` uncaught, so a
broken `multi_d.lpc` silently aborted every new registration mid-flow with
no visible symptom. Swept the whole corpus: 245 files renamed off the
`m_delete()` MudOS alias, plus 9 files (20 sites) assigning `map_delete()`'s
result to a variable.

## 4. The set_short()/set_long() closure gap -- blocked EVERY new registration

The single most impactful bug in this port, and the reason no new character
could ever get past the very first room. `std/Object.lpc`'s
`set_short(string str)`/`set_long(string str)` only accepted plain strings,
but 291 files (`set_long`) and 20 files (`set_short`) call them with
old-style closures for dynamic descriptions, e.g.
`set_long((:TO, "my_long":));`. That exact call is in
`d/shadowgate/setter.lpc` -- `ROOM_SETTER`, the literal first room every
brand-new character is moved into by `std/user/setup()`. Since the room
object simply failed to compile, `move()` into it silently failed with zero
driver-level crash, leaving new connections commandless with no error
anywhere obvious.

Fixed by widening both setters to `mixed` and teaching `query_short()`/
`query_long()` to evaluate a `functionp()` case:

```lpc
if (tmd = query_property("function_long")) {
    if (!tmd = call_other(TO, tmd)) {
        tmd = "A function messed up in query_long() in Object.lpc";
    }
}else if (functionp(ob_data["long"])) {
    tmd = (string)(*ob_data["long"])();
}else {
    tmd = ob_data["long"];
}
```

This exact pattern already existed elsewhere in the same file (the
"cap_name" derivation), confirming it's the established calling convention
for this codebase, not a new invention. Also had to widen four dependent
override files that had their own stale `string`-typed `set_short`/
`set_long` wrappers: `std/room.lpc`, `std/tobj.lpc`, `cmds/mortal/room.lpc`,
and three duplicate `Object.lpc` copies under dead/failsafe test paths.

## 5. The command-dispatch filename-slice bug -- blocked EVERY ordinary command

The second silent, total blocker, and the hardest to find: after fixing
\S4, new characters could finish the full 15-stage creation wizard and land
in the world, but `look`, `score`, `say`, `inventory` -- every single
ordinary player command -- failed with the driver's generic `default fail
message` ("Why?") and *zero* log signature. Verb-specific `add_action`
calls (character-creation's `select`/`press`/`finalize`, room-specific
`quit`/`bypass`) kept working throughout, which is what made this so
confusing: the wildcard catch-all itself (`std/living.lpc`'s
`add_action("cmd_hook", "", 1)`) was clearly registering and running (added
`debug_message()`/`tell_object()` instrumentation to confirm), but every
lookup through it came back empty.

Root cause: `daemon/command.lpc` (a Nightmare-style command-dispatch
daemon) scans each command directory for `_*.lpc` files and derives the
verb name with:

```lpc
choses[j] = choses[j][1..strlen(choses[j])-3];
```

This strips a leading `_` (1 char) and a trailing extension of exactly 2
characters -- correct for the archive's *original* `_look.c` naming, where
`strlen("_look.c")-3` lands exactly on `"look"`. This port's mechanical
`.c`->`.lpc` rename lengthened every extension by two characters, so the
same arithmetic on `_look.lpc` (a 4-character extension) sliced off
`"look.l"` instead of `"look"` -- silently corrupting the command-name key
for literally every command in every scanned directory, while the
*directory* itself still got recorded as "already processed" so it was
never retried. Fixed with an extension-agnostic replacement:

```lpc
choses[j] = explode(choses[j][1..], ".")[0];
```

This is the same *class* of bug already seen in another lib onboarded this
session (a fixed-width filename-slice tied to the `.c`/`.lpc` rename), but
a distinct instance/formula, found independently here.

## 6. Missing runtime directories silently aborting callers

Same `write_file()`/`save_object()`-into-a-missing-directory pattern
documented elsewhere in this project's AGENTS.md: a failing write throws an
error that, if the caller isn't wrapped in `catch()`, silently aborts the
*entire* calling function with no driver-level crash. Found via the
mudlib's own separate error log (`work/log/debug.log`/`debug.heavy`,
written by `adm/daemon/error_handler_d.lpc`, distinct from the driver's
native log). Created:

- `log/adm/jail`, `log/errors`, `log/living`, `log/pkill`, `log/player`,
  `log/reports`, `log/tshlog/{avatar,player,wizard}`, `log/watch`,
  `d/antioch/antioch2/logs` -- aborted `enter_email()`/registration logging.
- `daemon/save/saved_descriptions/<a-z>` -- aborted
  `daemon/description_d.lpc`'s per-character description save during
  `finalize()`.
- `d/save/quests` -- aborted the high/mid/low random-quest daemons'
  periodic saves (background, non-blocking, but a real recurring error).

`daemon/treesave_d.lpc`, `daemon/letter.lpc`, `daemon/localpost.lpc`, and
`daemon/yuck_d.lpc` all self-heal their own save directories with
`mkdir()`/`dir_exists()` checks already, so those were left alone.

## 7. Missing `ansi_str()` simul_efun

Referenced by `cmds/mortal/_look.lpc`, `_glance.lpc`, `_spy.lpc`, and one
NPC file, but implemented nowhere in the entire 43,000-file archive -- a
genuine gap, not something the port broke. This driver already
auto-translates this mudlib's `%^COLOR%^` markup to real ANSI escapes at
the `write()`/`tell_object()`/`more()` layer (confirmed: plenty of other
output renders color correctly with no explicit `ansi_str()` call), so
added a minimal passthrough simul_efun (`adm/simul_efun/ansi_str.lpc`)
rather than inventing real behavior for a function whose original
implementation is simply lost.

## 8. Smaller one-off compile bugs

All the usual "stray or missing type" classes seen elsewhere in this
session's work, collected here rather than given their own section:

- `daemon/filters_d.lpc`: `int *is_living(object ob)` declared to return an
  array but returns a plain `0`/`1` -- stray `*`, matching this archive's
  recurring `TYPE *a` declaration-binding typo class. This one mattered:
  it broke the whole file, which is called every heartbeat from
  `std/user.lpc`'s passive-perception check, spamming the log continuously.
- `daemon/chat.lpc`: `ipc_chat()`'s call to `format_chat()` was missing its
  final `emote` argument (driver requires exact arg counts for non-varargs
  params); added a `0` default.
- `daemon/guilds_d.lpc`: `query_guild()` returned `({ })` (array) from a
  `mapping`-returning function; `delete_player()` (`void`) had a stray
  `return 1;`.
- `d/shadowgate/void.lpc`, `d/common/obj/daily/compiler.lpc`,
  `d/atoyatl/tecqumin/tabaxi/obj/tabaxi_battler.lpc` (5 sites): called
  `get_eval_cost()`; this driver's efun is `eval_cost()` (no `get_` prefix).
- `daemon/bonus_d.lpc`: `varargs effective_ac(object who)` and
  `varargs ac_bonus(...)` omitted their return type entirely -- this driver
  treats a bare `varargs FUNC(...)` as an unparseable/`unknown` return type
  rather than defaulting to `mixed`. Swept the same pattern corpus-wide:
  `receive_objects()` (5 files), `init_treasure_for_area()` (1 file, 2
  sites), `cmd_gossip()` (1 file) all had the same gap.
- `adm/daemon/advance_d.lpc`, `adm/daemon/titles.lpc`,
  `cmds/creator/_scan.lpc` (5 sites total): `return notify_fail(...)` used
  inside `string`/`object`-returning functions. This driver declares
  `notify_fail()` `void` (not the classic MudOS int-returning idiom), so
  the pattern only compiles inside `int`/`void` functions; fixed the 5
  sites that live in other return types.
- `d/magic/symbols/holy_symbol_inherit.lpc` (cleric/paladin holy-symbol
  logic): a `void` function with a stray `return 1;`; a `string tmp`
  reused for array-building (`tmp = ({})`) in one function and assigned an
  `int` (`in_mind[x]`) in another -- widened to `mixed`; and a bare
  `(int)CLERIC_CALCS->query_max_spell_array(...)` cast truncating an
  array-returning call that's immediately indexed afterward -- fixed to
  `(int*)`.
- `daemon/language_d.lpc`: `string word = ({});` in `fakeWord()` -- the
  empty-array-literal-defaults-wrong-type class; fixed to `""`.
- `cmds/mortal/_save.lpc`: `if (!TP->query(...) != file)` -- a stray `!`
  making the comparison always-true (int vs string, flagged as a hard
  compile error, not just a logic bug); removed the errant `!`.
- `cmds/mortal/_inventory.lpc`: `sort_by_name()`'s swap temp was declared
  `object tmp` while sorting a `string*` array; fixed to `string tmp`.
- `d/common/obj/potion/advanced_heal.lpc`: `void new_do_effect(...)` had
  two stray `return 1;` sites.
- `d/dagger/marsh/tower/mon/knight.lpc`: `void set_paralyzed(...)` had a
  stray `return 1;`.
- `d/magic/spellbook.lpc` (mage class starting item): a `(string)` cast on
  an array-returning call (should be `(string*)`), a `string tmp` assigned
  `({})` and otherwise unused (removed), and three `void` functions
  (`flip()`, `set_owner()`) with stray `return 1;` sites.

## 9. Verification

Booted the real FluffOS driver (`~/src/fluffos/build-debug/src/driver`)
against `config.fluffos` and drove it end-to-end with a raw Python socket
client (no `mudclient.py`/`tmux_mud.sh` shortcuts): fresh registration
(name/password/ANSI test/screen-reader/email) through the full 15-stage
`ROLL_CHAIN` creation wizard (class, gender, race, subrace, template, age,
stat rolling via `recommended`+`done`, body type, hair/eye color, language,
alignment, deity), `finalize`, the scripted basic-commands tutorial
(`skip`), and then `look`, `score`, `who`, `say hello world`, and a clean
`quit` -- all producing correct, fully-rendered output. Confirmed the
character actually persists (`adm/save/users/<letter>/<name>.o` written
only once `query_level() >= 1`, i.e. only after creation genuinely
completes -- intentional, not a bug) and that `daemon/save/saved_descriptions`
saves cleanly post-\S6 fix. `debug.log` is clean of errors on this full
path after all fixes above; a background random-quest daemon and the
`bonus_d.lpc`/`filters_d.lpc` heartbeat spam are the only things that
appeared during testing, both fixed.

## 10. Known gaps -- documented, not invented or exhaustively chased

- `/cmds/soul/atmos.lpc` (`SOUL_D`, the emote/soul-verb fallback used when
  no real command matches) is referenced by `std/living.lpc`'s command
  dispatcher but does not exist anywhere in the 43,147-file archive. Not
  invented; emote-only input (not matching any real command or the chat
  daemon) will fail until a real implementation is written or restored.
- A handful of specific content files encountered via non-core background
  daemons still fail to compile and were left for a future pass rather
  than chased indefinitely, since none of them block registration or
  ordinary play: `daemon/magic_d.lpc` (several return-type/cast
  mismatches, pulled in transitively by the mage spellbook), and two NPC
  files in `d/dagger/marsh/tower/` (`bishimon.lpc`, `avenger.lpc`) and
  `d/attaya/mon/` reached via `knight.lpc`'s inherit chain.
- This is a live, actively-developed 43k-file mudlib; a full corpus-wide
  `lpcc_check.sh --batch` sweep was not run to completion (an earlier
  partial run reached ~19,800/43,147 files at 14,041 PASS / 5,753 FAIL
  before being proactively stopped per this session's memory-safety
  protocol). The fixes above target every bug that surfaced on the actual
  registration/character-creation/basic-command path, not a full-corpus
  clean compile.

## 深度功能测试 / Deep functional test (round two, AGENTS.md §10.7)

First genuine hands-on *playthrough* pass on the real driver (the earlier
"Verification" section above only exercised registration through the
15-stage creation wizard, tutorial-skip, and `look`/`score`/`who`/`say`/
`quit` -- never a continuous session with real movement, combat, skill
acquisition, or economy). One continuous session on
`~/src/fluffos/build-debug/src/driver`, a raw Python socket client
throughout (a persistent background process reading commands from a
named pipe, since a single Python invocation per command would have lost
in-progress creation-wizard/`input_to()` state across reconnects), plus a
second connection for a `fluffos`/`Mud@2026` admin account (registered
fresh through the normal flow -- this lib had never been seeded before;
granted via directly editing the freshly-registered save file's
`position` field to `"Admin"`, matching the exact string `std/user.lpc`'s
`enable_wizard()` gate checks, since the in-game `set_position()` path to
grant a non-mortal position itself requires calling from an existing
wizard's own `_xmote`/`_avmaker` command -- a chicken-and-egg the data-edit
sidesteps, per AGENTS.md §1.5's own guidance to prefer editing the save
data over the code).

**Newbie path**: `help newbie` and the community-authored
`doc/help/user/newbie_tutorial` (a step-by-step guide to a wood-elf
fighter, explicitly recommending `sweepingblow`/`impale` as the first
feats to buy) gave a clear, well-signposted test path: register, land in
the Offestry newbie tutorial, `skip` it, reach the town square, then
travel west/northwest to "the keep" to fight xvarts for early XP.

Test character: `Testwind`, a wood-elf fighter (soldier style),
password `Test@2026` -- kept as a representative playthrough character.
A second throwaway character (`Feattest`, a random saurian fighter) was
registered specifically to verify the feat-acquisition fix on a clean
slate, uncontaminated by the counter-desync the live bug left on
`Testwind`'s save (see Bug 3 below); both are left in place as evidence.

### Bug 1: a bare top-level `IDENT = (mapping-or-array-literal);` statement outside any function is not a valid initializer on this driver -- broke `look` in every outdoor room, game-wide, plus two spells and the `rumors` command (new AGENTS.md §7.123)

`adm/daemon/astronomy_d.lpc` declared `nosave mapping moons;` (and
siblings `moonstate`/`moonphase`/`moonorbit`, plus two globals never even
declared at all, `moonvisibility`/`moonillumination`) and then assigned
their real values via ordinary-looking top-level statements later in the
same file, outside `create()` -- a MudOS/LDMud-era convention this
driver does not support: a bare `IDENT = EXPR;` outside a function is
parsed as a type-less attempt to *redeclare* the global, producing
`error: Type mismatch ( unknown vs mapping ) when initializing moons`
and leaving the whole file uncompiled. Since
`adm/simul_efun/total_light.lpc`'s `total_light()` -- called from every
single `look`/room-entry via `describe_current_room()` ->
`light_blind()` -> `light_blind_remote()` -- calls
`ASTRONOMY_D->query_eclipse()` unconditionally and uncaught, every
outdoor `look` in the entire game silently printed nothing past the
point of failure (no room description, no exits, no items) from the very
first fresh boot. Reproduced live: a fresh character's very first `look`
at the Offestry town square (an outdoor room) printed only a blank
`-> ` prompt.

Fixed by merging the bare declaration and its later top-level assignment
into a single proper declaration-with-initializer inside `create()`
(this file already had one), and adding the two missing declarations:

```lpc
nosave mapping moons;
nosave mapping moonstate, moonphase, moonorbit, moonvisibility, moonillumination;
nosave string* moonphases;
int in_eclipse;

void create()
{
    seteuid(getuid());
    moons = (["sera" : "...", "tyrannos" : "..."]);
    moonphase = ([...]);
    moonvisibility = ([...]);
    moonillumination = (["sera":1, "tyrannos":0]);
    moonphases = ({ "new", ... });
}
```

Fixing this then exposed a second, previously-masked compile error in
the same file (`int query_moon_illumination(moon){` -- a parameter with
no declared type, which this driver rejects outright), fixed to
`string moon`.

**Three more independent instances of the exact same shape, found the
same session** (see new AGENTS.md §7.123 for the general pattern and
detection heuristic): `cmds/mortal/_rumors.lpc` (`arealist`/`areas` --
broke the `rumors` command referenced by the game's own
`doc/help/user/newbie` text, "`<rumors>` will tell you where people are
currently congregating"), and two mage/magus spells,
`cmds/spells/e/_elemental_aura.lpc` and `_elemental_body_i.lpc`
(`shortmap`/`colormap`/`elementmap`). All fixed the same way (merge
declaration+initializer into one statement). A targeted grep
(`^[a-zA-Z_][a-zA-Z0-9_]* = (\(\[|\(\{|\(:)` at column 0) found 18
candidate files corpus-wide; 14 were false positives (unindented code
inside a function, or inside a large `/* ... */` block of example
output/pseudocode) -- each hand-verified against its actual brace
context before deciding. A full corpus-wide sweep for this exact shape
was NOT attempted given the archive's 43,147-file size and this
project's standing memory-safety caution around full `lpcc_check.sh`
batch runs on this lib (see "Known gaps" below); the 4 confirmed
instances were all found via this one targeted grep pass plus whatever
the live playthrough itself happened to touch.

Verified live, before/after: before the fix, `look` in the Offestry town
square printed nothing past the prompt; after, it renders the full room
description, exits, and NPC list correctly. `rumors` now lists nearby
areas by level range instead of failing outright.

### Bug 2: `daemon/help.lpc` called an undefined `topic_dir()` (a typo for its own `topics_dir()`) -- broke `help` completely, for every player, from the very first boot

`daemon/help.lpc`'s `query_topics()` has one `case` per help category,
all calling the same local helper `topics_dir(DIR)` -- except
`case "*bloodlines"`, which calls `topic_dir(DIR_BLOODLINES_HELP+"/")`
(missing the `s`), an undefined function. This is a hard compile error
on this driver (`error: Undefined function topic_dir`), so
`daemon/help.lpc` itself never compiled, and `cmds/mortal/_help.lpc`
(the `help` command) failed every single invocation with
`*No program in object '/daemon/help'!` -- reproduced live: bare `help`,
`help newbie`, `help spar`, `help combat` all printed nothing at all,
game-wide, for every player, from the very first boot. Fixed the typo
(`topic_dir` -> `topics_dir`). While in the same function, also fixed an
adjacent `if(sizeof(statdata) && statdata[0] = myhold[i])` (a stray `=`
where `==` was clearly intended, in the `*spells`/`*feats` category's
file-validity filter -- an always-true condition that silently made the
filter a no-op, listing every directory entry rather than only the
stat-verified ones).

Verified live: `help` now renders the full category/topic menu; `help
*bloodlines` lists its 12 sub-topics; `help feats` renders its full
help text.

### Bug 3: `daemon/feat_d.lpc`'s directory scan used the exact §7.118 filename-slice bug already documented for this lib's own `daemon/command.lpc` -- silently disabled the ENTIRE feat/combat-technique system for every class in the game

The single most severe finding this session (see the extended
AGENTS.md §7.118 writeup for the full mechanism). `build_feat_list()`
scans every category folder under the feats directory and decides
whether each filename ends in `.lpc` with
`strsrch(files[y], ".lpc") != (strlen(files[y]) - 2)` -- correct only
for a 2-character `.c` extension, and since this port's mechanical
rename lengthened every extension to `.lpc` (4 characters), this check
is now false for every single file, so `continue` (skip) fires on
literally every feat file in the archive. `__ALL_FEATS` was permanently
empty, `is_feat()` returned false for every feat name in the game, and
`add_feat()` silently no-op'd on every `feats add`/`feats <type> <feat>`
call -- while the confirmation handler (`confirm_add_type()` in
`cmds/mortal/_feats.lpc`) prints "Congratulations, you have successfully
added..." UNCONDITIONALLY, never checking whether the daemon call
actually succeeded, so the player sees a convincing fake-success message
every time. Downstream, `std/living.lpc`'s central command dispatcher
gates every `/cmds/feats/*` verb behind `FEATS_D->usable_feat()`, so
every feat-granting command (including the game's own tutorial-
recommended `sweepingblow`) failed with the driver's generic "Why?"
default-fail message, indistinguishable from a nonexistent command. This
hits EVERY new character immediately: the automatic class-granted
feats every fighter/etc. receives at creation (light/medium/heavy armor
proficiency, shield/simple/martial weapon proficiency) were also
silently invisible to `feats known`/`has_feat()`/`usable_feat()`, even
though the "Adding fighter class levelling feat: ..." messages print
correctly during character creation.

Root-caused live via temporary `debug_message()` instrumentation in
`add_feat()` (note: this driver's `debug_message()` writes to the
driver's own stdout/stderr, NOT `debug.log` -- a real trap during
tracing) after ruling out `has_feat()`, `__FEAT_DATA` storage-key
mapping, and a first (wrong) theory that `query_player_feats()` was
missing a `"martial"` bucket read (it wasn't -- `"martial"`-type feats
are intentionally aliased to the pre-existing `"bonus"` bucket via
`get_feats()`/`set_feats()`'s own `case "martial": ... query_bonus_feats()`
mapping, already correctly read back; a would-be fix was drafted then
reverted once the real root cause -- `is_feat()` returning false because
`build_feat_list()` never populated `__ALL_FEATS` at all -- was found).

Fixed identically to §7.118's established extension-agnostic pattern:

```lpc
if (strlen(files[y]) < 4 || files[y][strlen(files[y]) - 4..] != ".lpc") {
    continue;
}
```

Fixing the scan then made `build_feat_list()` actually attempt to
compile all ~130 feat files under `cmds/feats/` for the first time ever
-- surfacing a second wave of ~25 files with their own independent,
ordinary compile bugs that had simply never been reached before. All
fixed, same session (grouped by shape, not per-file since most repeat):

- **Undefined `m_indices()`** (the MudOS alias for `keys()`, not an efun
  on this driver): `cmds/feats/a/_animal_companion.lpc`,
  `_arcane_bond.lpc`, `p/_pact_bond.lpc`, `p/_primal_companion.lpc` (4
  files, identical `implode(m_indices(valid_types), ",")` site) -> `keys()`.
- **`TYPE *a, b`/`TYPE a, *b` declaration-binding typos** (this
  archive's recurring class, already documented in this file's §8):
  `a/_augment_arrow.lpc` (`object weapons;` used as an array throughout
  -> `object *weapons`), `d/_defenders_presence.lpc` and
  `r/_radiant_aura.lpc` (`object* party=({}), healed=({});` -- `healed`
  silently scalar -> `*healed`), `j/_judgement.lpc` (`object inv;` used
  as an array -> `object *inv`), `s/_shapeshift.lpc`
  (`string myrace="",subrace="",oksubraces=({});` -> `*oksubraces`),
  `s/_swipe.lpc` (`object wielded;` -> `object *wielded`, plus a real
  logic bug found in the same line, see below), `obj/inspiration.lpc`
  (`object * diffout, diffin;` -> `*diffout, *diffin`).
- **`mapping` declared but assigned an array (`keys()`'s return)**:
  `c/_counterspell.lpc` and `p/_primal_scar.lpc` (`mapping available;`
  used with `pointerp`/`sizeof`/`available[i]` throughout -> `string
  *available`).
- **Stray `return N;` inside a `void`-declared function** (the same
  class already fixed repeatedly during this lib's original onboarding,
  §8 below): `d/_dazzling_display.lpc` (2 sites), `e/_enchant.lpc` (6
  sites, one revealed only after the first 5 were fixed and the
  function's tail became reachable), `s/_scribe.lpc` (7 sites, same
  reveal-in-waves pattern), `s/_shield_of_whirling_steel.lpc` (2),
  `s/_spinning_kick.lpc`, `w/_whirl.lpc`, `obj/flee.lpc`
  (`return remove();` inside `void execute_attack()` -> `{ remove();
  return; }`), `r/_resilient_arcana.lpc` (`return ::remove();` inside a
  `void remove()` override -- fixed to bare `::remove();`, matching the
  exact convention already used by two sibling overrides in this same
  codebase, `obj/judgement.lpc` and `obj/inspiration.lpc`, both of which
  already call `::remove();` as a bare statement).
- **One-off logic/argument bugs, each independently confirmed**:
  `c/_channel.lpc` (`attackers = attackers[i];` inside a `for` loop
  clearly meant to assign the singular `attacker` variable -- a real,
  distinct variable already declared two lines above -- fixed to
  `attacker = attackers[i];`; left unfixed this would have destructively
  overwritten the loop's own iteration array on every pass); `d/
  _dirty_trick.lpc` (`int bonus, effect, sickened;` where `sickened` is
  assigned `load_object(...)` and called via `->` -- an `object`, not an
  `int` -- split into its own `object sickened;`); `g/_greater_rage.lpc`
  (`set_required_for("mighty rage");` passing a bare string where the
  function requires `string*` -- wrapped `({ "mighty rage" })`); `i/
  _impale.lpc` (`strsrch(type, "pierc" == -1)` -- a misplaced
  parenthesis comparing the literal `"pierc"` to `-1` instead of
  comparing `strsrch(...)`'s result, permanently mis-scoring weapon
  damage type -- fixed to `strsrch(type, "pierc") == -1`); `s/_swipe.lpc`
  (beyond the array-declaration fix above, `if (!sizeof(wielded) == 1)`
  -- operator-precedence bug parsing as `(!sizeof(wielded)) == 1`, so the
  "you must be wielding a single one-handed weapon" gate only fired when
  wielding NOTHING, never when dual-wielding or empty-handed as intended
  -- fixed to `sizeof(wielded) != 1`); `obj/inspiration.lpc` (3 calls to
  `inspire_ally(ally, dir)` omitting the function's required 3rd
  `changeflag` argument -- this driver enforces exact non-`varargs` arg
  counts -- added the `0` default at each call site, matching this same
  lib's own established `daemon/chat.lpc` fix for the identical shape).

Verified live end-to-end on a fresh throwaway character (`Feattest`,
uncontaminated by `Testwind`'s pre-fix state): `feats known`
immediately after creation correctly lists all six automatic class
proficiencies; `feats martial sweepingblow` (`yes` to confirm) reports
success AND the `sweepingblow` command itself now actually runs (reaches
its own two-handed-weapon gameplay check, instead of the driver's
generic "Why?"); `feats known` afterward correctly shows `Sweepingblow`
under `TwoHandedWeapons`. `Testwind`'s own two attempts to add
`sweepingblow` (one before the fix, one shortly after, before this was
traced) both consumed the character's one-time "2 free martial bonus
feats" allowance via the `bonus_feats_gained` counter (which increments
unconditionally in `add_my_feat()`, independent of whether the feat
actually persisted) without ever storing the feat -- `Testwind` is left
in this state intentionally, as evidence of the pre-fix bug's exact
failure mode (a permanently fake-successful, resource-consuming, no-op
grant); a live wizard could restore the two consumed slots via
`ob->set_bonus_feats_gained(0)` if this character is ever used for
further testing, but that's a data-repair decision left to a human, not
made here.

### Bug 4: `d/laerad/mon/anti.lpc` (a level-22 mid-game boss NPC) failed to load at all, cascading from a stray `(string)` cast and several `void`-declared functions with stray `return 1;`/`return N;`, transitively taking down two dependent item files with it

Found while spot-checking a `daemon/quests_mid` background quest-daemon
reference in `debug.log` (`*No program in object
'/d/laerad/mon/anti'!`) during otherwise-unrelated testing --
`init()`'s aggro check cast `query_level()`'s int return to `(string)`
before comparing it against int literals (`(string)TP->query_level() >
18`), a hard type-mismatch error on this driver; `heart_beat()` and
`bolt()` were both declared `void` with several `return 1;` sites.
Compiling this one NPC file transitively attempted to load everything
its own `create()` clones (`new("/d/laerad/obj/lstealer")`, etc.),
surfacing two more independent bugs in the same load chain:
`d/laerad/obj/lstealer.lpc`'s `void save_me(string file){return 1;}` (a
deliberate no-op override to prevent this unique weapon from
auto-loading on restore, per its own header comment -- but declared
`void` while the base `std/Object.lpc`'s real `save_me()` returns `int`
and IS consumed by callers elsewhere, e.g. `std/bag_logic.lpc`'s
`j = inv[x]->save_me(fname);` -- fixed by widening to `int save_me(...)`,
preserving the intended no-op behavior exactly). Fixed the cast (removed
the stray `(string)`), the stray returns (changed to bare `return;` in
the two `void` functions), and the `lstealer.lpc` return type. This NPC
and its unique weapon are now reachable/loadable, though not personally
fought live this session (a level-22 boss well above a level-1 newbie
test character's reach) -- fix verified via a clean `lpcc --batch`
single-file compile only, not a live encounter.

### Bug 5: `daemon/virtual_room_d.lpc`'s player-room save/registration function was declared `void` but its ONE caller (`cmds/mortal/_save.lpc`) captures its return value -- broke the `save` command's virtual/player-built-room persistence path

`register_virtual_room()` computes and `return`s a `save_name` string,
but was declared `varargs void register_virtual_room(...)` -- the
identical bug already present (and left commented-out, itself with the
same `void`+`return save_name;` mismatch) in an EARLIER, abandoned
version of the same function directly above it in the file, suggesting
this was never actually fixed across a "recode" the file's own comment
describes ("attempting to recode to account for moving/linked virtual
rooms - Saide, April 2017"). `cmds/mortal/_save.lpc`'s only call site,
`file = "/daemon/virtual_room_d.lpc"->register_virtual_room(...)`,
needs that return value. Fixed by widening the declared return type to
`string` (matching the function's own `return save_name;`) and changing
its one early bare `return;` (for an invalid-object guard) to `return 0;`
to satisfy the new non-void signature.

### Bug 6: the general store's stock list was silently empty (`"I have nothing on hand."`) because two unrelated shared item classes it stocks failed to compile -- masked behind a generic, plausible-sounding shop message

Reached via the newbie tutorial's own recommended first stop ("s;w from
offestry center to get to the general store"). `list` at the Offestry
general store (`Odds and Ends`) printed only "I have nothing on hand." --
a message that reads as ordinary content (an understocked shop), not an
error, and would have been easy to accept as intentional. `debug.log`
told a different story: `d/common/obj/misc/book.lpc` and `d/common/obj/
misc/canvas.lpc` (two shared "writable item" classes this shop stocks,
alongside sacks/lanterns/tools/rope) both failed to compile, so the
shop's stock-loading silently skipped every reference to either.

- **`book.lpc`**: four `void`-declared functions (`set_stuff()`,
  `set_author()`, and the `case "title":` branch of a switch inside
  another) had stray `return 1;` sites, fixed to bare `return;`; a local
  variable-declaration line `string *chap_keys=({}),*page_keys=({}),
  new_keys=({}),tmp;` had the same `TYPE *a, b` binding typo as several
  feat files above (`new_keys` silently scalar despite being assigned
  `keys(...)` and indexed as an array) -- fixed to `*new_keys`.
- **`canvas.lpc`**: `end_long()` was called at line 73 but defined
  (with no forward declaration, and with NO declared return type at
  all -- a bare `end_long(object tp, string long) { ... }`) at line 86 --
  this driver's single-pass-per-file compiler treats that as calling an
  undefined function. Added a `void end_long(object tp, string long);`
  forward declaration and gave the definition itself an explicit `void`
  return type. This then surfaced a second bug: two SAME-OBJECT direct
  calls to `query_long()` with zero arguments, but the inherited
  `std/Object.lpc`'s `query_long(string str)` requires exactly one --
  fine when called via `->` `call_other` elsewhere in this same
  codebase (loosely checked), but a hard compile error for a same-object
  direct call (statically checked). Fixed both sites to `query_long("")`,
  matching this exact codebase's own established convention for the
  "give me the whole description" case (`std/bag_logic.lpc`'s
  `container::query_long("");`).

While tracing this, also found and fixed the SAME already-known,
already-partially-fixed potion bug class from this lib's own original
`§8` "Smaller one-off compile bugs" list (`void new_do_effect(...)` with
stray `return 1;` -- previously fixed only in
`d/common/obj/potion/advanced_heal.lpc`, apparently never swept across
its siblings): `healing.lpc`, `newbie_healing.lpc`, `epic_heal.lpc`,
`full_heal.lpc`, `legendary_heal.lpc`, `extra_heal.lpc` (6 more files,
identical shape, all fixed the same way). These weren't stock items in
this particular shop, but were caught by a quick sibling-file grep
(`awk '/^void new_do_effect/,/^}/' file | grep 'return 1;'`) run
immediately after finding the first instance, per this project's
standing "a bug found once has usually been copy-pasted" heuristic.

Verified live: the Offestry general store's `list` now shows all 16
real stock items (belt pouches, lanterns, rope, tools, the canvas, the
book, etc.) instead of "I have nothing on hand." A further, unrelated
`*No program in object '/d/common/obj/sheath/sheath_inherit'!` surfaced
in `debug.log` from a DIFFERENT background subsystem (a weapon-sheath
randomizer) while re-testing the shop -- confirmed not to block the shop
list itself, and left unfixed as a deliberate stopping point: this
43,147-file live archive has effectively unbounded further
transitively-reachable compile bugs in its shared item library once
lpcc actually starts reaching previously-dead code paths (the same
mechanism as Bug 3's "second wave"), and chasing every one of them is
out of scope for a single §10.7 pass — flagged here for whoever next
works this lib, not chased further.

### What was tested and confirmed working (Testwind's playthrough)

- **Registration + full 15-stage creation wizard** (class, gender, race,
  subrace, template, age, stat rolling via `recommended`, body type,
  hair/eye color, language, alignment, deity, class special), tutorial
  `skip`, landing in Offestry town square.
- **`look`/`score`/`i` at every major state change**: after register
  (post-Bug-1-fix, renders correctly), after first move, after gaining a
  feat, after combat, after quit/relogin.
- **Combat**: no dedicated PvP-safe sparring/training-dummy mechanism
  reachable from the newbie zone within this session's travel budget
  (the game's real training-dummy room, `d/shadow/coliseum/`, is in a
  different city, `Shadow`, not the newbie town `Offestry` -- reaching
  it would have required either significant travel or admin `goto`,
  which this lib's freshly-seeded admin account was used for other
  verification instead). Used the newbie-tutorial-recommended "keep"
  area's xvarts instead (level ~1, low threat) -- fought and killed two
  separate xvarts across two sessions with normal hit/miss/damage/death/
  corpse mechanics and correct XP gain (58, then another for a running
  total of 290), no `debug.log` errors during either fight.
- **Skill/feat acquisition**: `feats allowed`/`feats known`/`feats
  martial <feat>` (with its `yes` confirmation flow) all now function
  correctly post-Bug-3-fix, verified on a completely fresh character
  (see Bug 3 above for the full before/after).
- **`quit`, `debug.log` grep, then reconnect after a real wall-clock
  gap**: `Testwind` was quit and reconnected across 4 separate real
  driver-restart-and-reconnect cycles over the course of this session
  (each time a fix required a fresh boot to test); state (level, exp,
  HP, feats-known-counter, room position) persisted correctly across
  every cycle; `debug.log` was clean of error-level output at every
  `quit` (only routine compile warnings from unrelated lazily-loaded
  objects).
- **Economy**: reached the Offestry general store and confirmed its
  full stock list renders (see Bug 6); did not complete an actual
  purchase live since `Testwind` never accumulated any gold during this
  session's limited combat.

### Known gaps -- honestly unverified, not invented or guessed at

- **Death/resurrection**: NOT reached live this session. `Testwind`
  never dropped below ~50% HP fighting single newbie-zone xvarts, and
  deliberately seeking out a lethal fight (or using an admin `smash`/
  `die()` to force it) was not attempted given the time already spent on
  the six compile-bug chains above. Left as explicitly unverified rather
  than silently skipped.
- A full corpus-wide sweep for the §7.123 top-level-bare-assignment bug
  class (Bug 1) was NOT attempted (see Bug 1's own note on why) -- the
  four instances found are everything this session's targeted grep plus
  live playthrough happened to surface, not a proof of completeness.
- `Node.js` is not installed in this environment, so the required §9 LPC
  formatter pass (`format-corpus.mjs`) could not be run on any of the
  ~35 files touched this session. All edits were made by hand, matching
  each file's existing indentation/brace style as closely as possible;
  a formatter pass (plus the three documented post-format blind-spot
  checks) should be run on these files by whoever next has `node`
  available, before considering this pass's formatting fully compliant
  with the project's own §9 requirement.

## WASM verification (wasm_status audit)

First WASM pass for this lib (`wasm_status` had been left `""` since the
original port -- see AGENTS.md §1.4's triage playbook). Ran
`scripts/wasm_client.js` against `~/src/fluffos/build-wasm/src` with a
full fresh registration (name/password/ANSI/screen-reader/email) through
the entire 15-stage `ROLL_CHAIN` creation wizard -- `select fighter`,
`select male`, `select dwarf` chosen explicitly to keep the path
deterministic (dwarf isn't one of the two `is_statmod_race()` races
[`human`, `half-elf`], so the `stat_mod` stage auto-skips reliably;
`fighter` avoids caster-class complications), `select random` for the
remaining option-list stages, and `recommended` + `done` for the `stats`
stage specifically (it's the one `ROLL_CHAIN` stage that rejects the
generic `select`/`select random` verb outright -- `select_stats()`
always returns 0 and just reprints the stat-allocation help; confirmed
this live on a first attempt that sent `select random` into it and
watched the wizard stall repeating the same screen) -- then `finalize`,
tutorial `skip`, and `look`/`score`/`who`/`say hello world`/`quit`.

**Result: clean end-to-end with zero mudlib-side changes needed.** The
full chargen produced a real character (fighter/male/shield dwarf,
svelte body, silver eyes, gray hair, chaotic neutral, The Faceless One,
thug fighter-style), landed correctly in the tutorial room, `skip`
reached the rules room, and `score`/`who`/`say`/`quit` all rendered
correct output with no `debug.log`-equivalent errors, no `No program in
object`, and no driver-level crash anywhere in the transcript.

The only compile-time error seen during boot was the pre-existing,
already-documented `adm/daemon/ipc.lpc` (an admin chat-relay daemon using
raw `socket_create()`/`socket_bind()`/`socket_listen()`, which don't
exist in the `sockets`-less WASM build) -- confirmed via a full-corpus
grep that this file is referenced from nowhere else in the archive (not
preloaded, no `IPC_D`-style macro, no caller), so its compile failure is
inert noise, not a WASM blocker; left unguarded rather than adding a
speculative `#ifdef __PACKAGE_SOCKETS__` to a file nothing calls. The
only other socket-using file in the whole archive,
`cmds/creator/_netstat.lpc`, is a creator-only diagnostic command never
exercised by ordinary registration/play and wasn't touched either. No
`uptime()` startup-grace gates, no `pcre`/`regexp()` calls in
simul_efun/master, and no IP-parsing bans in `logind`'s equivalent
(`adm/obj/login.lpc`'s `BANISH_D`/`MULTI_D` chain: both start with empty
allow/deny lists on a fresh archive and have no IP-format-sensitive
logic that could reject a loopback WASM connection) -- none of the
usual §1.3 bug classes applied here. `std/user.lpc`'s `setup()` already
hardcodes `ip = "127.0.0.1";` for every logged-in player regardless of
driver mode, which incidentally makes this lib immune to any future
`query_ip_number()` regression on this specific field (unrelated to the
still-live `query_ip_number()` efun call itself, which was never an
issue here since nothing in the login/registration path parses it).

Set `wasm_status: "playable"` in `meta.json`. Also took this pass as the
opportunity (per the site's ongoing description-quality sweep) to
rewrite `meta.json`'s `english_description` and `README.md`'s intro
section, which had drifted into porting-bug narrative instead of game
content -- replaced with real specifics pulled from `std/races/` (43
race files, several `is_restricted()`-gated), `std/class/` (base vs.
`is_prestige_class()` roster), `d/shadowgate/dieties.h`'s ten-deity
NEWPANTHEON, and the `d/` zone tree (Tabor/Muuldaan, the city of Shadow
and its coliseum, Underdark, a Ravenloft-flavored domain, the
Atoyatl/Tecqumin jungle region, Dagger). Also stripped a stray
`**40232**` markdown-bold artifact from the README's "Local run" section
(the site's `parse_readme()` doesn't strip markdown, so it would have
rendered as literal asterisks on the site card).

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 1 line(s) in 1 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-04）— `<../x.h>` includes resolve

3 files in old areas (`d/dragon/old/sewer/fall1.lpc`, `d/dagger/derro/old/mon/elemental.lpc`,
`d/islands/common/eldebaro/eldebaro/ob/runestone.lpc`) include a header named relative to themselves in angle brackets; the
driver refuses `..` in a `<...>` name. `adm/obj/master.lpc` now answers `include_file()` with `"./" + path` (KB 04 §6.1) and
`runestone.lpc` loads; the other two include correctly now and fail for their own reasons (old code). The lib's warnings pass has
not been done (unused locals in the master and `std/room/terrain.lpc`).

## 深度功能测试（§10.7，2026-10-05）— 主控 author_file()/domain_file()

驱动的 mudlib_stats 包在主控载入时各调用一次 `author_file(<主控文件>)` 和 `domain_file("/")`，要求返回字符串。本库这两个 apply 只为 domains / realms 目录下的文件返回名字，其余返回 0，所以每次启动都打印 `author_file() in the master file does not work, using root_uid as fallback` 和 `domain_file() in the master file does not work, using bb_ui as fallback` 两行，网页版每位访客的终端里都看得到。`adm/obj/master.lpc` 改成与 fluffos 组织维护的 Dead Souls 上游（`deadsouls_fluffos`）相同的写法：其余文件的域返回 `"BACKBONE"`，作者返回 `"NONAME"`。域等于 backbone 域时驱动让对象沿用创建者的域，与返回 0 时相同；作者统计（`author_stats()`）多出一行 `NONAME`，汇总 realms 目录以外的对象（KB 06 §7.222）。用 `lpcc config.fluffos /nonexistent.lpc` 前后对比，主控载入段只少了这两行。

## 2026-10-06 — `protected private`

`adm/daemon/services.lpc` 的 `build_mudlist()` 声明为 `protected private`（早期把 `static` 换成 `protected` 时留下的两个访问修饰），FluffOS 报 `Multiple access modifiers`；改为 `private`。该文件仍因缺少 `NETWORK_D`（本驱动没有网络包下的互联服务）无法编译。

## Deep test (§10.7, 2026-10-07) — messages cut by a stray `;`

`std/class/shadowdancer.lpc` prerequisite text: a stray `;` ended the string early, so "10 Ranks spent in Athletics Skill" was never shown. Joined.

Changed files loaded at HEAD and in the tree in fresh processes: no regression.

## 深度功能测试（§10.7，2026-10-08）— `.lpc` 后缀的定宽切片

`.c` 改名 `.lpc` 时只改了字符串没改切片宽度：`f[<2..] == ".lpc"` 拿两个字符比四个字符，永远不成立（`!=` 永远成立），按后缀筛文件、去后缀的代码因此从不运行或截成 `x.l`（KB 06 §7.238）。`scripts/lpc_lpc_suffix_slice.py --apply` 改了 1 处比较、0 处去后缀（如 `cmds/system/_update.lpc`）；改动的文件 HEAD 与工作树分别加载（新进程），无回退。

## Deep test (§10.7, 2026-10-10) -- compile warnings, chunked rescan

Re-run with the chunked scanner (`LPCW_CHUNK=600`): the earlier pass predates it and its coverage could not be confirmed. `scripts/lpc_warnings.py sunshadow --fix` plus `scripts/lpc_fix_no_effect.py --apply` changed 3273 `.lpc` and 3 `.h` files (mostly unused locals). Loaded at HEAD and in the tree in fresh processes: 1781 -> 1782 PASS of 3265 changed files; the one "regression" is the `d/deku/keep/rooms/jail1` / `dungeon4` pair, which swap PASS/FAIL between batch runs (each loads alone). The 76 includers of the changed headers: 59 -> 59. Audit flags in files that do not compile at HEAD were read: all are calls (`east_limit(path)`, `uptime()`) or names kept in the rebuilt declaration. Boot warnings 50 -> 0.
By hand: `adm/include/conf.h` and `config.h` both define MUDLIB, MUDLIB_VERSION, MUD_IS_LOCKED, GMT_OFFSET, MAX_LOG_SIZE and MORTAL_POSITIONS with different values, and files include them in both orders (`Macro redefined`); each define is now preceded by `#undef`, so the header included last still wins exactly as before. `std/daemon.lpc` `clean_up()` is now `int` (returns 0, which is what the `void` meant to the driver) because 7 daemons override it as `int` and return 1 to stay loaded; the 19 daemons that overrode it as `void` are now `int` too, with `return 0;` (same value). Login on a fresh driver: same as HEAD.

## 深度功能测试（§10.7，2026-10-10）— 站点树缺 access.db；帝国卫兵的装备

- 上游自带的 `work/.gitignore` 忽略了 `adm/db/access.db`、`groups.db`、`privs.db`，仓库里只有 `.example`。本地工作树有这三个文件（从 `.example` 复制而来），而按 git 建出的树（站点 zip、`pristine_tree.sh`）没有。主控的 `load_access()` 对 `read_file()` 返回的 0 做 `explode()` 而出错，每次 `check_access()` 都失败；连错误处理守护进程写 `/log/debug.log` 时也要过这一关，于是原始错误被吞掉。结果是大部分 NPC 无法载入：`/d/azha/mon/` 的 40 个 NPC 在 git 树里 38 个载入失败。三个文件与 `.example` 逐字节相同，已用 `git add -f` 纳入版本库（shadowgate 本来就跟踪了它们）。之前用 git 树做的整库扫描（编译警告整理、§7.238）中，NPC 一侧两边同样失败，所以“无回退”的结论仍然成立，只是覆盖面比数字显示的小。
- `d/azha/mon/impguard.lpc`、`s-impguard.lpc`：随机三选一的装备里，`/d/tsarven/equip/ghalberd.lpc` 和 `gshield.lpc` 在存档里从来不存在，`new()` 出错使 `create()` 中断，三分之二的卫兵载入失败；`switch` 的三个 `case` 也没有 `break`，持戟的卫兵会把三套武器都拿上。改用现有的同系装备 `/d/tsarven/equip/ihalberd.lpc`（Tsarvani halberd）和 `/d/azha/equip/ishield.lpc`（Tsarvani medium shield），并补上 `break`。有 access.db 的树里，两个卫兵连续 4 次载入都通过（之前 HEAD 3 次全失败）。

- 2026-10-11：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 140 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 11 个，只在 #if 分支用的声明移进分支 2 个文件；改动 116 个文件，HEAD 与工作树各载入一次无回退（116 objects; HEAD PASS 54, tree PASS 54; regress 0; newly loading 0），这些文件的警告 392 -> 252。

- 2026-10-11：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 19 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 0 个，只在 #if 分支用的声明移进分支 0 个文件；改动 17 个文件，HEAD 与工作树各载入一次无回退（17 objects; HEAD PASS 4, tree PASS 4; regress 0; newly loading 0），这些文件的警告 71 -> 91。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查

把 shadowgate 提交 `6ae0f9a959f` 的 72 处 `Expression has no side effects` 修正移植过来：25 个与 shadowgate 代码逐词相同的文件用 `scripts/lpc_twin_port.py adopt` 原样套用，其余 33 个文件按 sunshadow 自己的文本手工移植或修正（共改动 58 个 `.lpc`）。`lpc_twin_port.py audit shadowgate sunshadow --pre 6ae0f9a959f~1` 复查后，只剩与本次无关的旧差异（sunshadow 的 `_heal` 已用 `rnd` 计算伤害；`quests_high/mid` 少一个 `test_quests()` 原型）。

- **影响玩法的**：`d/laerad/lgnolls` 的 `bloodfang`、`gnollhunter`（及原样套用的 gnollbarb/priest/warrior、`worg_tooth`）`do_damage("torso",(2,20)+20)` 改 `roll_dice(…)`，原先只取逗号右值、固定伤害；`d/deku/monster/bheur` 的四行 `list - …` 改 `-=`，瞬移时才会排除禁入房间、当前房间和 fire_tunnel；`daemon/search_d` 的 `is_item_locked()`（`if (locked > 0); return 1;` 对任何已登记物品都答“已锁定”）改为按标志返回；`std/tobj` 的 `do_trap()` 去掉 `if(...);` 的分号；`daemon/rumours_d` 三个来源后缀改为 `fb += …`；`std/battle.lpc` 与测试副本 `d/deku/hhouse/inherits/test/battle.lpc` 的 `reset_scrambles()` 改 `iteration = sizeof(combatants)`（原先循环一次不跑）；`tecqumin/rooms/spell` 的 `prof = FULL_EFFECT`；`tabaxi/obj/cauldron` 的 `desc += ", "`；`nymph_dress_in` 的 `yy = random(10)+1`（高魅力描述原先从不出现）；`archer` 的 `for(i=0;level, i<level;i++)`；两份 `river.lpc` 的 `direction += (ob, PORT)` 改标量赋值（`enter()` 无人调用）；`d/azha/daemon/overseer` 的 `resetMons = ({ })` 及 `add_timed_monster()` 里从未赋值的 `ob`。
- **无可见变化的**：6 个任务 NPC 的 `step3 = 1`（ghostking、ghostshaman、imp、sirith、grakulan、ulfgar；`step3` 从未被读取）；`maze_builder2/3` 的 `room_number = prev_room_number`；`std/vendor`、`std/assvendor` 的 `enchant = enchant ? enchant : 1`（在 if 内）；`std/races/orc` 的 `default: return 0;`；`_sweepingblow` 的 `num = -1`；`spell_research` 删去游离的 `keyword_index[words[j]];`；`demon_footman` 删去游离的属性数组；`daemon/multi_d`、`daemon/unique_d` 只含注释的 if 并入注释。
- **sunshadow 独有的**：`std/magic/spell.lpc` 的 `define_clevel()` 里一个空的 `if(spell_type == "psion") { }`，删去；`std/effects/effect.lpc` 的 `if(!prof) prof == FULL_EFFECT;` 改 `=`（与 `rooms/spell.lpc` 同形；该基类目前无人继承）。`std/assvendor.lpc` 见上。

HEAD 与工作树新进程分别载入改动的 58 个对象：regress 0。未通过的 25 个（`_freeze`、两份 `river`、`rooms/spell`、`cauldron`、豺狼人、`rumours_d`、`search_d`、`unique_d` 等）在 HEAD 同样无法载入，是本库原有的其它编译错误。`bheur` 在第一次批量载入里失败一次：其 `create()` 有一半机会 `new()` 出 `/d/deku/weapons/winters_chill.lpc`，后者 `void` 函数 `return charges;` 编译失败（shadowgate 同样），单独重载 3 次均通过，属随机伪影。改后这些文件的“无副作用”警告为 0。58 个对象载入无回退。

- 2026-10-11 补记：`d/deku/weapons/winters_chill.lpc`（冬寒法杖）`query_charges()` 声明为 void 却 `return charges;`，`failure()` 为 void 却 `return 1;`；sunshadow 下整份不编译，`d/deku/monster/bheur.lpc` 一半几率 clone 它而载入失败。改为 `int query_charges()`、`return;`（调用方不取返回值）。

## 深度功能测试（§10.7，2026-10-12）：编译警告收尾

能编译的文件中的警告从 27853 条（4003 个文件）降到约 100 条（1 个文件，`d/magic/obj/rebirther.lpc`，见下）。

本库与 shadowgate 是同一代码，先用 `scripts/lpc_twin_port.py adopt shadowgate sunshadow --pre a9c8e7aeead` 照搬 258 个代码相同的文件，余下 185 个有差异的文件中 134 个直接套用 shadowgate 的补丁，其余按同样的根源手改（详见 `libs/shadowgate/NOTES.md` 同日一节）：`adm/include/priest.h` 不再 `inherit SPELL`；`body.lpc` 的 `ac`/`size`、`room.lpc` 的 `flag`、`townsman`/`caravan` 的 `path`/`speed` 改名；巨魔七种的属性改在 create() 里赋值（此前每只巨魔都没有类型和描述）；tsh 的命令历史不再被 pushd 栈顶掉；`road10` 去掉会把房间整个清掉的 DAEMON；法术叶子不再重复声明 spell.lpc 的 `caster`/`place` 等，自身的时长 `duration` 改名 `spell_time`（本库另有 17 个）；字符串函数指针的消费者（search/items/read、`Object::set()`）认得真正的函数指针；重复继承与两个完整类的拼合；`d_robe` 改为 PARMOUR、`ring` 自带 artifact 的成员等。

本库自己的部分：

- **返回类型与基类不符**（约 220 条，shadowgate 不报这一类）：叶子把基类的 `void help()`、`void remove()`、`void execute_feat()`、`void init_disease()`、`void die()` 等写成 `int`。没有调用者使用返回值的改为 `void`、`return 1;` 改为 `return;`、`return ::remove();` 改为 `{ ::remove(); return; }`（约 218 个函数），残留的旧原型一并改正；基类为 string、叶子为 int 的 `query_broken()`、`get_serial_number()` 改为 `mixed`；`body.lpc` 返回武器数组的 `query_wielded()` 与 `ammo.lpc` 返回数组的 `query_wc()` 改为 `mixed`。错的重复原型删去：`combat.lpc` 的 `doProtection`、`_note`/`_pcnote` 的 `format_notes`、`government.lpc` 的 `query_offices`、`tunnels/rooms/library` 的 `set_long`。
- **真错误**：`d/guilds/order/` 下 84 个守卫/兵士的 `object *query_party()` 覆盖了 living.lpc 返回队伍名的同名函数，改名 `query_guard_party()`（无调用者；shadowgate 同改）。`std/plate.lpc` 的 `wearit()` 是 void：body.lpc 在穿戴函数答 0 时拒绝穿上，所有用基类 `wearit` 的板甲都穿不上，改为返回 1（shadowgate 同改）。`d/common/mons/questor.lpc` 的 `string thanklist` 存的是数组，本库严格类型下整份不能编译，导致 `newtharis/rooms/north5` 的任务房间（现在 rquestroom 的 create 才真正执行）载入失败；改为 `string *`（shadowgate 同改）。`std/magic/spell.lpc` 的反射段里两个嵌套的 `/*`。
- `?:` 两支类型不同（`_date`、`_pcnote`、`jailer` 的分钟补零，`_mmap` 的出口数）：数字一支加 `"" +`，输出不变。`verdant_hammer` 的 `set_wield`/`set_unwield`/`set_hit` 会立即求值指针取得处理函数名，改为本库通用的 `(: TO, "name" :)` 写法。`d/magic/obj/jaunter.lpc` 删掉 `#include <user.h>`，自己补 `query_invis()`/`set_invis()`（它只用到这两个）；`assassinhall` 去掉从未用到的 assassin（VAULT）继承；`graez/rooms/battle/86` 的 `CORE` 已在 scrubland 里；`newuser.lpc` 重复的 `more` 继承与 `diety`/`retinue` 声明；`graez/obj/sword` 声明了两次 `room`。

遗留：`d/magic/obj/rebirther.lpc` 同 shadowgate（从 user.lpc 抄来的死亡代码作用在它自己身上，去掉 user.h 就无定义，未动）。

验证：改动的 719 个文件加包含改动头文件的文件，共 3250 个对象在 HEAD 与工作树的新进程中分别载入：回退 5 个，逐个核对：`newtharis/rooms/north5` 因 questor 编译错误，已修；`deku/hhouse/rooms/ffr7`、`sfr3/5/6` 随机生成的 `good_host`/`monster_feat_d` 本身就编译失败（文件未改动），单独重载 sfr3/5/6 通过、ffr7 视随机结果而定。其余 3245 个对象载入无回退。`lpc_audit_removed_locals.py` 列出的 85 条中 83 条是巨魔叶子改成赋值的声明，另两条核对无误。

- 2026-10-14: FluffOS 970d9f09 warns `Float value truncated to int` (#1426). 11 sites in 9 files: assignments, initializers and returns now spell the truncation `to_int(...)` (same value); `x op= <float>` converted the float before the operation (zeroing `x` for a factor below 1) and is now `x = to_int(x op ...)`: `/daemon/combat_d.lpc`（`defend *=`）, `/daemon/world_events_d.lpc`（`mod *=`）, `/daemon/world_events_d.lpc`（`exp +=`）, `/daemon/world_events_d.lpc`（`exp -=`）. Changed objects loaded before and after in fresh drivers, no regressions (`scripts/lpc_fix_float_trunc.py`, KB 04 §6.10).
- 2026-10-14 (same rescan, by hand): `d/atoyatl/tecqumin/test/guardcham.lpc` (an old draft of `rooms/guardcham.lpc`) declared its own `int entered` on top of the one in `zig_int_base.lpc`. The base never reads its own copy, so the leaf's copy is dropped and the leaf now uses the base's. `d/magic/obj/rebirther.lpc` stays as noted above: naming winners for its 60 overlapping functions would not remove the variable redeclarations. The 10 changed objects load at HEAD and in the tree, with no regressions.

- 2026-10-14: 41 files did not compile with `Illegal to inherit after defining global variables`: FluffOS takes every `inherit` before the first global, MudOS did not care. `scripts/lpc_fix_inherit_order.py` moved the globals (and `#include`s of headers that declare globals) written above the `inherit` to just below the last one (KB 04 §6.3). The toolkit round then cleared the warnings the newly loading files showed (0 nosave functions, 746 bare returns, 79 unused locals). HEAD vs tree in fresh drivers: 1664 objects, 1333 newly loading, 0 regressions.

- 2026-10-14: 1315 files did not compile with `Type of returned value doesn't match function return type ( int vs void )`: a function declared `void` (or with no type) returns a value, which the old driver passed to the caller. Functions whose value a caller reads (add_action handlers, commands, helpers) now carry the type they return: `CloseDoor()`, `GoJungle()`, `GoSwamp()`, `OpenDoor()`, `Query()`, `__Help()`, `action()`, `add_base_class()`, `add_horse_name()`, `add_option()`, `add_stuff()`, `add_title()` …. In driver applies whose value is ignored (`init`, `reset`, `heart_beat`, `create`) the return is now bare (`{ ::init(); return; }` keeps a call). HEAD vs tree in fresh drivers: 1673 objects, 1344 newly loading, 0 regressions (`scripts/lpc_fix_void_return.py`, KB 04 §6.3).

- 2026-10-14: this config has no `old type behavior : 1` (shadowgate's does), so the type errors that config hides stopped 1,294 files outright. Fixed: `void` functions returning a value (add_action handlers, specials, `query_*` hooks) take the type they return, or a bare `return;` in applies. `int` functions returning strings take `string`: the signet rings' `query_seal()`, `query_symbol()`, `query_mysize()` and others, 269 files. `void` overrides of `void` bases (`set_paralyzed`, `spell_effect`, `set_tripped`, `set_bound`, `catch_say`) stay `void`. The toolkit round's HEAD-vs-tree check: 1,673 objects, 1,344 newly loading, 0 regressions.
- Base signatures narrower than their callers: `add_id()` in `std/Object.lpc`, `std/tobj.lpc` and `std/living.lpc` took a `string`, while `add()` accepts an array and 55 items call `add_id(({...}))`; it now takes `mixed`. `std/room/items.lpc` had two contradicting `remove_item()` prototypes (string / string array), so 38 rooms passing one name did not compile; it now takes `mixed`, and the single-name branch returns instead of falling into the array loop over the string's characters. In `std/psionportal.lpc`, `add_location()` declared the destination `int` while every caller passes a room path; it is now `string`. A list check of the 113 callers: 84 newly loading, 0 regressions.
- 12 monsters called `set_new_exp("boss", 70)` with the arguments swapped (the signature is `set_new_exp(int level, string perc)`): the level fell back to `query_level()` and the percentile to `"normal"`, so bosses gave normal experience. They now read `set_new_exp(70, "boss")`. The eldebaro `npc_creator.lpc` passed `"35"` as a string; it now passes `35`.
- Left failing on purpose: the newseneca tattoos (each file pasted several times) and `tecqumin/obj/table.lpc` (class diamond, see above). Making them compile only trades the error for dozens of redeclarations.

- 2026-10-14: some monsters call `set_mlevel(39)` with only a level. A 2016 override in `std/monster.lpc` meant to handle that (the comment says so) was left commented out, because its `string` parameter made the `intp()` test impossible. It is back with a `mixed` parameter: a bare level goes to the monster's first class (or fighter), and calls with a class name are unchanged. 9 of the 11 callers newly load; 80 random monsters load the same at HEAD and in the tree.

## Restored base-class macros (2026-10-18, KB 04 6.13)

`inherit IDENT;` named a macro that no header of this lib defines (`syntax error, unexpected L_IDENTIFIER, expecting L_STRING or '('`), so the object never loaded; the base file is in the lib and other libs map the macro to it. Added to the global header `adm/include/std.h`: `ALLEY` -> `/d/tharis/alley` (23 file(s)) (`scripts/lpc_restore_macros.py`). Loaded one by one with `lpcc` afterwards: 23 of 23 pass.

## Exits to rooms that do not exist, repaired from the room on the other side (2026-10-18, KB 06 7.257)

A room exit named a file the lib does not have, so the player was stuck (a typo, a renamed room, a numbered room the archive lacks). The room at the other end exists and its opposite exit points back, so that is where the exit was meant to go: `/d/attaya/crafters/desert/des201` `southeast`: `/d/attaya/crafters/desert/des222.lpc` -> `/d/attaya/crafters/desert/des223`; `/d/attaya/crafters/desert/des268` `northeast`: `/d/attaya/crafters/desert/des291` -> `/d/attaya/crafters/desert/des246`; `/d/khalian/stresa/cicatrice/room115` `northeast`: `/d/khalian/stresa/cicatrice/room/108` -> `/d/khalian/stresa/cicatrice/room116`; `/d/khalian/stresa/cicatrice/room134` `west`: `/d/khalian/stresa/cicatraice/room133` -> `/d/khalian/stresa/cicatrice/room133`; `/d/khalian/stresa/cicatrice/room85` `south`: `/d/khalian/stresa/cicatrirce/room100` -> `/d/khalian/stresa/cicatrice/room100`; `/d/khalian/stresa/cicatrice/room92` `west`: `/d/khalian/stresa/cicatraice/room91` -> `/d/khalian/stresa/cicatrice/room91`; `/d/magic/temples/cevahir/archery` `south`: `/d/magic/temples/cevhair/cevahir_training` -> `/d/magic/temples/cevahir/cevahir_training`; `/d/tharis/Tharis/market5` `south`: `/d/tharis/palace/mountain/m32` -> `/d/tharis/Tharis/market8`. Every repaired exit now resolves to a file of the lib (`scripts/lpc_fix_dead_exits.py`; libs whose virtual rooms load anyway are left alone).

## Macros the global header lost (2026-10-19, KB 04 6.16)

`/adm/include/std.h` did not define `MOON_DESC`; the objects that use them (1 on the list) stopped at `Undefined variable`/`Undefined function`, and since the compiler stops at the first undefined name the errors and warnings behind it stayed hidden. The sibling libs of the same lineage carry these lines in their headers: the copy of the sibling with the most files in common was added after the last `#define` of `/adm/include/std.h`; every path in a macro body exists in this lib. the listed objects have other errors as well and still do not load. (`scripts/lpc_restore_defines.py`)

## Headers next to the including file, quoted (2026-10-19, KB 04 6.17)

23 files wrote `#include <area.h>` for a header that sits in their own directory (`area_stuff.h`, `boathouse.h`, `strongholds.h` ...). The old driver searched the includer's directory for an angle-bracket name; this one searches only the include path, so each stopped at `Cannot #include ...`. Rewritten to `#include "area.h"` (resolved against the includer everywhere: preload, `lpcc`, run-time compiles). (`scripts/lpc_fix_local_include.py`)

## Calls to an inherited function no parent has (2026-10-19, KB 06 7.259)

`/d/antioch/valley/val.lpc`, `/d/dagger/aketon/rooms/tree1/1one5.lpc` (2 objects) call `::create();`/`::init();` where the inherited bases have no such function. The old driver took such a call for a no-op returning 0; this one stops with `Unable to find the inherited function 'init'.`. These objects had only this error (it was uncovered once the others cleared); each call is deleted (`return ::fn(...)` becomes `return 0;`). (`scripts/lpc_fix_dangling_super.py`)

## Object paths with two leading slashes (2026-10-19, KB 06 §7.276)

5 file(s), 5 site(s) wrote an object path as `//…` (like `carry_object("//clone/cloth/hic_cloth")`): `/d/azha/town/market2.lpc`, `/d/azha/town/market3.lpc`, `/d/azha/town/market4.lpc`, `/d/azha/town/market5.lpc`, `/d/azha/town/market6.lpc`. The driver these games ran on did not mind (the path was normalised first); this one hands the string to the master's `valid_read()` as written, securityd looks up `//clone`, the NPC's euid has no entry and the answer is `Read access denied.`: the NPC does not load. One slash now.

## The rebirther object: a second copy of the player class and a player it never touched (2026-10-19, KB 06 7.278)

- `d/magic/obj/rebirther.lpc` is the same object as shadowgate's (see its NOTES): `<user.h>` (the player's inherit list) plus `inherit OBJECT;`, 100+ warnings, and death and rebirth code that called `save_player()` and the money functions on itself instead of the dying player. The same edit (no `<user.h>`, the calls go to `reborn`, `set_invis()` as the `set_hidden` / `set_magic_hidden` toggle, `query_invis()` kept); it loads with no warning (HEAD: 100+) and `do_rebirth()` / `do_death()` run to the end against a fake player in the shadowgate copy of the same code.

## Standard repair round (2026-10-19, `scripts/toolkit_fix.sh`)

Rescanned with the current driver; mechanical fixes: 53 files with values returned from void functions. Every changed object was loaded at HEAD and in the tree: no regression. 1 further float sites need a hand edit (listed by `lpc_fix_float_hooks.py`).

## Type slack of the old driver: core files and mechanical layers (2026-10-19, KB 04 6.19)

After the standard round 2,984 files still failed; the ones other files inherit were ranked by dependents and fixed by hand, the rest went through `scripts/lpc_round_files.py` (compile only the failing objects, run the fixers, repeat). 230 files changed, 146 objects that never loaded now load (loaded at HEAD and in the tree: no regression), the real warnings of the compiling files are gone.
- Core files: `d/deku/inherits/foresttraili.lpc` (238 rooms: `ob = "/d/magic/obj/treant"; ob->set_hp(...)` moved and fought the blueprint, now `new(...)`), the dinosaur island `jungle.lpc` / `lakefront.lpc` (114 rooms: `(mapping)TO->query_traps() == ({})` is always false, so no jungle trap was ever set; now `!sizeof(TO->query_traps())`), `d/mine2/mine.lpc` (29 rooms: a local named `class`), `d/dagger/Torm/mon/dayperson.lpc` / `dayvendor.lpc` (20 NPCs: `int time` holding "twilight"), `d/common/obj/sheath/sheath_inherit.lpc` (16 items: `return 1+write(...)`, `string inv = all_inventory(TO)`), `d/tharis/barrow/mound_inherit.lpc` and `rooms/mound1-6` (`object here = RPATH "inner1.lpc"` is a path used as a call_other and message target: `string`), `daemon/monster_feat_d.lpc` (`string *tmp` holding the level keys of a mapping, `(int)featOb->query_feat_type() == "instant"` never true: now `(string)`), `d/common/obj/misc/pipenew.lpc` (`(string)` cast on an array), `d/laerad/obj/wand_para.lpc` (`!TP->query_name() == "hansoth"`: the wand now asks to be wielded by everyone but Hansoth, as its own comment says), `daemon/crayon_d.lpc` (`string COLORS = ({...})`, and `str + S;` is now `str += S;`).
- Mechanical: 116 calls with the missing arguments written out (`query_long()` -> `query_long(0)`, 26 rooms and every spell that calls it), 39 untyped parameters typed `mixed` (and `object room, object, victim` repaired), 29+ array initializers given their star, void-return and prototype repairs, nine `int remove();` prototypes above `void remove()` definitions.
- Kept as the old driver ran it: seven `roll_dice((5,10+50), 0)` calls (serakii `echo.lpc` / `sliver.lpc`, tecqumin spells) pass ONE argument (the comma operator) and a missing second one, so the damage is flat 60 / 110 / 120 / 210; the pointless first operand is dropped, the intended `roll_dice(5,10)+50` is a person's call.
- Left (2,837 files with errors): 1,149 placeholder files named `x` (archive loss), the `./../../newbie.h` / `area_stuff.h` / `undead.h` / `castle.h` / `eldebaro_in.h` families in `old/` directories (headers the archive lacks), 36 `cmds/priest/godspells/*` spells calling the old `set_spell_level(3)` (the base takes a class mapping), `d/shadowgate/masters/masters.lpc` (KNIGHTALIGN / RANGERALIGN / DRUIDS lost), the pasted-together `alzar_*` tattoos, `d/atoyatl/tecqumin/obj/table.lpc` (two class stacks, 40 diamond warnings).

## Old-driver type slack: missing arguments, untyped parameters, array initializers, `class` variables (2026-10-19, KB 04 6.19, 6.20)

MudOS filled the missing arguments of a call with 0, took an untyped parameter as `mixed`, never compared a declared type with its initializer and let a variable be named `class`; this driver refuses all of it at compile time and the whole object fails. 22 file(s) fixed: `/cmds/skills/bak/_boost.lpc`, `/cmds/skills/bak/_cure.lpc`, `/cmds/skills/bak/_detect.lpc`, `/cmds/skills/bak/_feed.lpc`, `/cmds/skills/bak/_heal.lpc`, `/cmds/skills/bak/_lore.lpc`, `/cmds/skills/bak/_mend.lpc`, `/cmds/skills/bak/_offer.lpc` ... (22 in all) (the repair rounds of `scripts/lpc_round_files.py`: zeros written out at the call, `mixed` for untyped parameters, `string X = ({...})` given its star, void functions returning values, and `class` variables renamed `pick_class`). Loaded at HEAD and in the tree, per file: 15 of them failed before and load now, none regressed.

## One stray backslash after an include (2026-10-19, KB 04 6.1)

`d/antioch/valley/rooms/v6.lpc` began `#include <std.h>\`: the backslash joined the next line to the include directive, so `#include "../valley.h"` was swallowed and `inherit VALLEY;` was an undefined macro (the same file in shadowgate has it too; its siblings `v1`..`v5` have none). The backslash is removed: the room fails at HEAD and loads in the tree, no warning, no regression (its sibling `v5` loads in both).

## An unused local in a file that loads since the type-slack rounds (2026-10-19, KB 04 6.10)

`d/underdark/mines/spell/emgem.lpc`: `object obj;` in `die()` was never used, deleted (the final rescan found it; no other real warning is left in the compiling files except the two whole-class diamonds below the cap, `d/laerad/dojo/obj/shield.lpc` and `d/mine2/rooms/mine22.lpc`: two full classes inherited on purpose, see the shadowgate NOTES).

## `x == "a" || "b"`：后面的字符串常量永远为真（2026-10-19，KB 06 §7.281）

`if (arg == "yuyou" || "yu you")` 里的 `"yu you"` 是非空字符串，永远为真，整个条件对任何 `arg` 都成立；作者要的是每个字符串都和变量比较。具体是：`whisper` 的语言参数永远被改成 wizish。在每个字符串前补上变量和运算符（`scripts/lpc_fix_literal_or.py`；`forrest2.lpc` 是 `dir == "north" && "south"`，手工改成 `(dir == "north" || dir == "south") && ...`）：`/cmds/mortal/_whisper.lpc`（1 处）、`/d/dagger/phederia/rooms/v1.lpc`（2 处）、`/d/dagger/phederia/rooms/v15.lpc`（2 处）、`/d/darkwood/yntala/mon/centaur.lpc`（5 处）、`/d/darkwood/yntala/mon/centaurcl.lpc`（4 处）、`/d/darkwood/yntala/mon/centaurg.lpc`（3 处）、`/d/deku/hhouse/study.lpc`（1 处）、`/d/islands/giant/hill/rooms/r13.lpc`（1 处）、`/d/shadow/city/room/moffice.lpc`（1 处）、`/d/shadow/room/githyanki/27,17.desert.lpc`（1 处）、`/d/shadow/room/githyanki/rooms/0_0.lpc`（1 处）、`/d/shadow/virtual/desert/27,17.desert.lpc`（1 处）。

## `x != "a" || x != "b"` and `x == "a" && x == "b"`: comparison chains of one value that can never differ (2026-10-20, KB 06 7.282)

`if (arg != "wan" || arg != "pill") return notify_fail(...)` is true whatever `arg` is, `dir == "south" && dir == "north"` is never true: the guard under the test never opens, or never closes. The author meant "neither of these" (`&&`) or "either of these" (`||`). `!=` chains joined by `||` became `&&` (only where the statement under the test is a `return`, a refusal or a guard clause), `==` chains joined by `&&` became `||` (`scripts/lpc_fix_cmp_chain.py`). Changed: `/d/antioch/ruins/rooms/graveyard.lpc` (2), `/d/islands/dreams/rooms/fire.lpc` (1). Left as written (the body under the test does something else, `==` and `||` may have been meant): `/cmds/mortal/_abandon.lpc` (1), `/d/darkwood/forest/village/priv1.lpc` (1), `/d/darkwood/forest/village/priv2.lpc` (1), `/d/darkwood/forest/village/priv3.lpc` (1), `/d/darkwood/forest/village/priv4.lpc` (1), `/d/darkwood/forest/village/priv5.lpc` (1), `/d/darkwood/forest/village/priv6.lpc` (1), `/d/darkwood/forest/village/priv7.lpc` (1), `/d/darkwood/forest/village/room1.lpc` (1), `/d/darkwood/forest/village/room2.lpc` (1), `/d/darkwood/forest/village/room3.lpc` (1), `/d/darkwood/forest/village/room4.lpc` (1), `/d/darkwood/forest/village/room5.lpc` (1), `/d/darkwood/forest/village/room6.lpc` (1), `/d/darkwood/forest/village/room7.lpc` (1), `/d/darkwood/forest/village/well1.lpc` (1), `/d/darkwood/forest/village/well2.lpc` (1), `/std/weapon.lpc` (1).

## Type slack, second layer, and `(string)` casts of numbers (2026-10-20, KB 04 6.21, 6.22)

`scripts/lpc_round_files.py sunshadow --failing ...` with the three new fixers: `lpc_fix_bad_assign.py` (a variable that was handed a number, a string or an object it was not declared for is declared `mixed`), `lpc_fix_void_return.py` widened to every declared type (a function whose `return` contradicts its declared type becomes `mixed`; the `string *query_guild() { return "Iron Fist"; }` of the 45 Fist troopers is `string query_guild()` by hand), and `lpc_fix_cast_cmp.py` (`(string)TP->query_level() > 12` is `(int)`, `string light_level` that holds `test_dark()` is `mixed`). 314 files changed; HEAD loads 2 of them, the tree loads 203 (201 new), no regression, and no real warning in the objects that load. The 45 troopers (`d/guilds/fist/oldfist/troopers/*.lpc`; shadowgate has the same ones) compile now, but each `create()` calls `->set_property()` on `new("/realms/bane/closed/bracers5")` or `/realms/tristan/healing`, wizard-directory items the archive does not have, so none of them loads (KB 06 7.269).

By hand, in the objects that load since: `cmds/spells/f/_fell_flight.lpc` redeclared `heritage`, which the SPELL base declares (the spell now sets the base's, so the base's help text shows the pact); `d/magic/store_comp.lpc` and `d/magic/obj/store_comp.lpc` declared `int set_name` over the base's `void`; `d/islands/elf/mon/guard.lpc` had `?:` with an int and a string branch; `d/atoyatl/bridge_monitor_d.lpc` `bp = to_int(bp + 0.5)` (the conversion the driver does anyway, said out loud); `d/laerad/obj/ragnarok.lpc` `holder` holds the owner's name (`string holder`); `d/tharis/obj/trunk.lpc` `base_name(inven[i] == "...")` is `base_name(inven[i]) == "..."` (the misplaced parenthesis handed the result of a comparison to `base_name()`, so the check for the tree thing never worked; shadowgate has the same line).

Left: of the 2,829 objects that failed, 2,628 still do not compile (a dry round over the whole list): the 1,149 placeholder files named `x`, the missing `./../../newbie.h` (249), `./../inherits/area_stuff.h` (98), `undead.h` (69), `castle.h` (58), `eldebaro_in.h` (46), `drownew.h` (33), `areadefs.h` (25), the 119 files that hold an FTP `421 Timeout` line, and the 36 priest spells under `cmds/priest/godspells` and `old/weapons` that call the old `set_spell_level(3)` with an int where the base takes a mapping (`keys(levels)` has nothing to work on): archive loss and dead code, not slack.

## `member_array('/', str)` became `strsrch(str, "/")`: the character-literal member_array is a byte search (2026-10-20, KB 06 7.283)

`'/'` in `member_array('/', str)` is an int, so the driver searches the UTF-8 **bytes** and answers a byte offset (a third argument is a byte offset too). FluffOS 923cdbc0 warns once per call site (`Warning: member_array(int, string) searches BYTES`) when the string holds non-ASCII text before the match, and `str[0..idx-1]` counts characters, so a non-ASCII string was cut in the wrong place. Now `strsrch(str, "/")` (-1 when absent, a character index; `scripts/lpc_fix_member_array_char.py`, the JSON encoders and a few other sites by hand). Changed: `/adm/simul_efun/json.lpc` (11).

## `if (x = CONST)`: a comparison written as an assignment (2026-10-20, KB 06 7.290)

`if (arg = "button" || arg = "pill")`, `if (!arg || arg = "") return 0;`, `else if (check = 0 && tempB != "")`: `=` was typed for `==`, so the condition is the constant: the branch is always taken for a non-zero number or any string (even "") and never for 0, and the variable is overwritten; the driver does not warn. Every such `=` became `==` (`scripts/lpc_fix_cond_assign.py`, 31 terms). Changed: `/cmds/bard/_lore.lpc` (1), `/cmds/spells/a/_animate_object.lpc` (1), `/d/atoyatl/tecqumin/city/rooms/balcony.lpc` (1), `/d/atoyatl/tecqumin/rooms/spell.lpc` (1), `/d/common/obj/clothing/magerobe.lpc` (2), `/d/dagger/exchange/horse/storage/horse_master.lpc` (1), `/d/dagger/islands/wailing_isle/mon/mutt.lpc` (1), `/d/darkwood/watermargin/pator/H2Osword1.lpc` (3), `/d/darkwood/yntala/rooms/spassage2.lpc` (1), `/d/deku/fortress/throne.lpc` (1), `/d/deku/misc/pet.lpc` (3), `/d/islands/dreams/rooms/good2.lpc` (1) and 11 more (23 files).
