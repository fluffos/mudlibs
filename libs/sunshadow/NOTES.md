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
