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
