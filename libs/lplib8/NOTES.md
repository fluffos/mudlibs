# LPlib8 -- porting notes

Source: `lplib8.tar.z`, recovered directly from the still-live
`ibiblio.org` mirror
(`https://ibiblio.org/pub/Linux/games/muds/lplib8.tar.z`). Slug
`lplib8`, number 961, port 40263. 120 raw files (54 `.c` sources),
mudlib root at the archive's own top level. No `driver_hook`/
`set_driver_hook`/`H_[A-Z_]+` usage anywhere. `secure/master.lpc`'s
own header: "This is the LPmud master object, used from version 3.0."
The archive's own `README`: "This is an experimental mudlib, using
the new features of LPmud game driver 3.0 ... It is not the 'much
talked about' CDlib for Genesis. I use it more as an experiment...
Mail ideas and suggestions to me (Lars Pensjö): lars@cd.chalmers.se" --
i.e. Lars Pensjö's own personal testbed, not a distributed/maintained
game codebase.

Structurally more modern than the sibling `basis`/`lpmud245` onboarded
this same session: real `inherit` is used throughout (a genuine
`basic/move.lpc`-style shared base class layer), `create()` is
already the primary constructor convention (not `reset()`-as-
constructor), and `secure/master.lpc` already defines
`get_root_uid()`/`get_bb_uid()`/`get_simul_efun()` on its own.

## 1. Extraction and conversion

Pure ASCII/English archive, 0 lossy conversions. 54 files renamed
`.c`->`.lpc`, 6 literal `.c"` references fixed, 8 files
`static`->`nosave`.

## 2. Proactive on-sight checklist findings

No `status`-as-type usage, no `new`/`class` variable-name collisions
found in the initial sweep. One `in(str) {...}` dead command handler
in `basic/player/trace.lpc` hit the `in` reserved-keyword collision
(the `foreach ... in` clause) -- confirmed dead (never wired via
`add_action`; only the capitalized `In` is actually registered,
matching the sibling `lpmud245`'s identical trace.lpc pair exactly).
Renamed to `go_in`.

## 3. Compile-time / boot-time driver-compat fixes

- **`get_include_path()` needed for cross-directory quoted headers**:
  this archive's headers (`config.h`, `move_failure.h`,
  `lock_logic.h`, `door_logic.h`, `door.h`, `stats.h`) all live in
  `/sys` but get quote-included from files elsewhere as bare
  `"config.h"` etc. Added the standard AGENTS.md §6.1 apply, plus
  `include directories : /sys` in `config.fluffos` for the
  `:DEFAULT:` fallback.
- **`extract()`/`log_file()` were never real efuns on this driver**
  (AGENTS.md §6.2's existing entries) -- both reimplemented as
  simul_efuns in `secure/simul_efun.lpc`.
- **A real, previously-uncatalogued class-2-arg mismatch specifically
  in `mixed`-typed function locals**: `secure/master.lpc`'s `flag()`
  declared `string file, arg;` but used `arg` as BOTH an int (a
  speed-test loop counter, `sscanf(str, "for %d", arg)`) and a string
  (`sscanf(str, "echo %s", arg)`) within the SAME function -- a
  genuine 1990s loosely-typed-LPC habit, not conversion damage. This
  driver's stricter type checker rejected `i < arg` as an int-vs-string
  comparison. Fixed by splitting the declaration: `string file; mixed
  arg;`.
- **The ACL "read access denied at compile time" class**
  (AGENTS.md §7.5): master's own `valid_read()` denied ALL anonymous
  (`eff_user == 0`) reads unconditionally, before ever reaching its
  own per-directory allowlist -- blocking every `#include`/
  `load_object`/`recompile_object` this driver internally routes
  through `valid_read()`. Added the standard `func ==
  "load_object"/"recompile_object"/"include"` bypass at the top.
- **`get_root_uid()`/`get_bb_uid()` already existed** (unlike the
  sibling `basis`/`lpmud245`), so this archive's boot proceeded much
  further before hitting its first real permission wall -- see §7
  below for what that wall turned out to be.
- **`valid_override()` missing**: needed the moment `basic/move.lpc`
  got its own `move_object(dest) { return efun::move_object(dest);
  }` shim (below) -- any object defining a function sharing a real
  efun's name, or calling `efun::something()` at all, needs explicit
  master permission on this driver. Added a permissive always-1 stub.
- **`move_object()`/`transfer()` 2-arg dialect gap**
  (AGENTS.md §7.158/§7.173): only 8 real call sites across the whole
  archive (much smaller than `lpmud245`'s 111+12), and since this
  codebase actually uses real `inherit`, the fix is cleaner here: a
  single `move_object(dest) { return efun::move_object(dest); }`
  shim added to `basic/move.lpc` (the shared "movable object" base
  every clonable item/door/player already inherits) covers every
  legitimate item automatically, rather than needing a blanket
  per-file addition the way the non-inheriting `lpmud245` did.
  `basic/move.lpc`'s own `move()` and `obj/soul.lpc`'s `init_soul()`
  (both `move_object(this_object(), X)`) rewritten directly to
  `efun::move_object(X)`; `basic/player/trace.lpc`'s wizard tracer
  tools (operating on arbitrary found objects) rewritten to
  `X->move_object(Y)`/`X->move_object(this_player())`, relying on the
  shared shim.
- **`command(str, ob)` 2-arg dialect gap** (AGENTS.md §7.172): the
  `In()`/`go_in()` tracer commands and `move_object`'s own comment
  ("This will not work because command() only works for
  command_giver") both hit this. Since `this_player() ==
  this_object()` in these specific call sites (the code runs directly
  as part of the player's own inherited method), the fix was simpler
  than `lpmud245`'s: just drop the redundant 2nd argument rather than
  adding a `do_command()` wrapper.
- **`snoop()`'s 1-arg-vs-2-arg semantics** (AGENTS.md §6.2): the bare
  0-arg `snoop();` and the "start snooping" 1-arg `snoop(ob);` in
  `basic/player/wiz.lpc` both hit the identical shape already found
  on `lpmud245`. Fixed to `snoop(this_player())` and
  `snoop(this_player(), ob)` respectively.
- **`version()`/`wizlist()`/`localcmd()` were never real efuns on this
  driver** -- three MORE classic MudOS efuns, not previously
  catalogued. `version()` reimplemented as `"FluffOS " + __VERSION__`;
  `wizlist()` as `cat("/WIZLIST")` (the 1-arg name-filter form isn't
  reimplemented -- no call site needs it); `localcmd()` reimplemented
  via this driver's real `commands()` efun, whose 4-item-per-row shape
  (verb, flags, defining object, function) still matches.
- **A genuine ambiguity in this project's OWN `extract()`
  reimplementation, not the original archive**: `basic/player/save.lpc`'s
  `save_file_name()` called `extract(name, 0, 0)` -- a real 3-argument
  call meaning "just the character at index 0" (for bucketing save
  files by first letter). Our simul_efun's `varargs` "was `end`
  provided?" detection (`if (!end) end = len - 1`) can't distinguish
  an explicitly-passed `0` from an omitted argument (LPC coerces a
  missing `varargs` parameter to plain `int` `0`, identical to a real
  `0`), so this call was silently treated as the 2-argument
  "to end of string" form -- returning the player's WHOLE name
  instead of its first letter, bucketing every save file under
  `/players/<full name>/` instead of `/players/<first letter>/`.
  Confirmed via a live `debug_message` probe on `valid_write()`
  (temporarily un-`#if 0`-ing the archive's own commented-out debug
  line) showing the actual path requested. Fixed by rewriting the one
  real call site with unambiguous LPC range slicing (`name[0..0]`)
  instead of trying to make `extract()` itself disambiguate --
  confirmed no other 3-arg `extract()` call site in this archive uses
  an explicit `0` end. **New AGENTS.md §6.2 sub-entry this session**:
  any archive calling this project's `extract()` shim with an
  explicit `0` end needs the SAME per-call-site fix, not a change to
  the shared simul_efun (which cannot resolve the ambiguity in
  general).
- **The single most severe finding, and a genuinely new,
  previously-uncatalogued driver-vs-archive convention mismatch**:
  this driver's `valid_write()`/`valid_read()` master applies pass
  the CALLING OBJECT ITSELF as their 2nd argument
  (`packages/core/file.cc`'s `check_valid_path()`:
  `push_object(call_object)`, confirmed by reading the driver source
  directly), not a euid STRING the way the classic MudOS/LPmud-3.0
  driver this archive was written for did. `secure/master.lpc`'s
  entire security model compares this argument against uid strings
  throughout both functions (`eff_user == get_root_uid()`,
  `eff_user == dom`, domain-membership checks, etc.) -- every one of
  these comparisons was silently ALWAYS FALSE regardless of the real
  caller's actual identity, since LPC's dynamic typing lets an object
  value flow into a `string`-declared parameter without a runtime
  error. Confirmed live by temporarily re-enabling the archive's OWN
  pre-existing (but `#if 0`-disabled) debug `write()` line in
  `valid_write()`: it printed `eff_user: /obj/player#1` -- an object
  reference, not a uid string -- for every single call. This broke
  EVERY player's very first character save
  ("*Denied write permission in save_object()") and every subsequent
  login's restore attempt ("*restore_object: read permission
  denied"), with the only visible symptom being those two bare
  driver-level permission errors (logged fully to `debug.log`, but
  with no hint that the ROOT CAUSE was a parameter-type mismatch
  rather than a missing ACL rule). Fixed by converting the object
  argument to its real uid string
  (`if (objectp(eff_user)) eff_user = geteuid(eff_user) ||
  getuid(eff_user);`) at the top of both `valid_write()` and
  `valid_read()`. **New AGENTS.md catalog entry this session** (see
  §7 below) -- this is a general driver-vs-classic-MudOS convention
  difference that will recur verbatim on ANY archive whose
  `valid_write`/`valid_read` still declare their 2nd parameter as
  `string` rather than `object`/`mixed`.
- **A second, independent bug in the same permission subsystem,
  needed alongside the fix above before save/restore actually
  worked**: `valid_seteuid()` never granted a plain backbone-owned
  object (e.g. a freshly cloned `/obj/player` -- `creator_file()` has
  no special case for `/obj/` paths, so it gets the generic backbone
  owner uid) permission to `seteuid()` to `"root"`, even temporarily.
  `basic/player/save.lpc`'s `actually_restore_player()`/
  `actually_save_player()` both explicitly `seteuid(get_root_uid())`
  before their `restore_object()`/`save_object()` calls, expecting
  this exact grant -- and the function's OWN code comment admits the
  gap: *"the game driver has not been fixed to call these
  valid_functions instead of the ones in player.c yet, but I will fix
  that really soon (Lars)."* This is a genuine, author-acknowledged
  incompleteness in the original 1989-93 source, not conversion
  damage. Fixed by granting any backbone-owned object the same
  latitude root already has (`if (getuid(ob) == get_bb_uid()) return
  1;`) -- reasonable for this small, fully-trusted single-owner
  mudlib with no untrusted-wizard threat model.
- **Two genuine pre-existing bugs in `obj/mail_reader.lpc`, confirmed
  against the raw archive bytes**: `messages` used throughout
  `send_mail()` but never declared anywhere (added `string
  messages;`, distinct from the already-declared `arr_messages`
  array); and `move()`'s `if` block was missing its closing brace
  entirely (`move_object()`/`return MOVE_OK` were unreachable, nested
  inside the `if`, and the function's own closing brace was absent,
  corrupting the parse of `void create()` right after it in the
  file -- surfacing as the misleading "Illegal to declare local
  variable of type void" error). Also fixed a `MOVE_DESTRUCT` vs. the
  header's real `MOVE_DESTRUCTED` typo in the same function.
- **A dangling `if` with no body in `obj/roommaker.lpc`**: `if (ret !=
  0)` immediately followed by the function's own closing brace, a
  hard syntax error, confirmed genuine in the raw archive. Completed
  with the same "report the `catch()` failure" idiom `secure/master.lpc`'s
  own `get_simul_efun()` uses for the identical
  `catch(call_other(...))` pattern.
- **`obj/lockable_door.lpc`'s vestigial `reset() { door::reset(); }`
  called a function that genuinely does not exist anywhere in its own
  inherit chain** (`obj/door.lpc`, its direct parent, defines no
  `reset()` of its own either -- confirmed by reading both files).
  Removed rather than inventing a body: every other door/gateway
  class in this archive simply has no `reset()` at all, which this
  driver silently accepts.
- **A filename oddity, not conversion damage**: `obj/lockable_door.`
  (a literal trailing dot, no `.c` extension at all) was present in
  the RAW archive itself -- confirmed by checking the untouched
  `raw/` tree. Invisible to `convert_lib.sh`'s `.c`->`.lpc` rename
  glob, so this real, needed file (`sys/door.h`'s
  `MAKE_LOCKABLE_DOOR` macro `clone_object("/obj/lockable_door")`s it
  by path) never got renamed and would have silently failed to load
  the moment any door used the lockable variant. Renamed directly to
  `.lpc`.

## 4. Compile-sweep triage: known-acceptable remaining failure (1 of 55)

- `w/lars/yy.lpc` -- literally `a=a;=a;` followed by four lines of
  `sadd`/`adfdf` gibberish. Confirmed genuine garbage in the raw
  archive bytes (Lars's own throwaway scratch file, matching the
  identical "author's own personal test junk" pattern already seen on
  the sibling `basis` (`obj/quicktyper.lpc`'s test file) and
  `lpmud245` (`players/lars/test.lpc`'s intentional `1/0;` crash
  tests) -- Lars Pensjö's `/w/lars/` directory across BOTH his own
  archives in this session's batch contains real scratch/debug
  content the author never intended to be loadable code. Left as-is.

## 5. Live playthrough (native driver)

Full flow verified in one continuous session, port 40263: fresh
registration (name / password, no confirmation) landing directly on
the starting lawn -> `look` (correct room + item description) ->
`north` (moves to a different lawn area with different hedge/exit
layout, confirming real room-to-room movement works) -> `look` again
(correct) -> `score` (correct age/health/stats/skill display) ->
`take knife` (picks up the room's item, "Ok.") -> `say hello there`
("Ok.") -> `quit` (clean save + disconnect). Re-login (existing-
password path) verified separately: password accepted, correct
starting room reached again. **Confirmed the save/restore fix
actually persists real data**: read the resulting
`players/<letter>/<name>.o` file directly after a save --
contains genuine player state (`names`, `gender`, `hp`, `stats`,
`player_name`, `current_path`, `skill_structure`, `player_age`), not
an empty or default-only save. `debug.log` fully clean (zero error
lines) across every test session after all fixes above.

Also confirmed via the compile sweep: the "experimental map system"
(`w/lars/castle.lpc` moving into a procedurally-created
`/room/map/m0_1.lpc` tile, then the driver deleting that tile file
per `base.lpc`'s own `volatile()`-always-1 convention while the
in-memory object stays resident) now completes successfully end to
end -- this was one of the two failures still standing before the
`valid_write`/`valid_read` object-vs-string fix (the tile file's
`write_file()` was silently failing under the same broken ACL), and
resolved as a side effect of that fix rather than needing its own
separate change.

## 6. WASM

Boots and plays identically under the WASM build
(`~/src/fluffos/build-wasm/src`, via `scripts/wasm_client.js`): full
registration -> `look` -> `quit`, correct output throughout, and the
resulting save file confirmed written correctly. `wasm_status:
playable`.

## 7. New AGENTS.md catalog entries added this session

(Alongside this session's `basis`/`lpmud245` entries for the closure/
function-pointer gap, `new`/`class`/`in` reserved words, several
missing classic efuns, the `move_object`/`transfer`/`command()` 2-arg
dialect gaps, and `file_name()`'s leading-slash convention.)

1. **This driver's `valid_write()`/`valid_read()` master applies pass
   the calling OBJECT as their 2nd argument, not a euid STRING** --
   any classic-MudOS-sourced `master.lpc` still declaring that
   parameter as `string eff_user` will have every uid-string
   comparison in its own security logic silently always-false. Fix:
   `if (objectp(eff_user)) eff_user = geteuid(eff_user) ||
   getuid(eff_user);` at the top of both functions. Detect via a
   temporary debug `write()`/`efun::write()` printing the raw 2nd
   argument's `%O` representation -- a bare object reference where a
   string was expected is the tell.
2. **This project's own `extract()` simul_efun reimplementation
   cannot distinguish an explicit `0` end argument from an omitted
   one** -- any archive calling it as `extract(str, N, 0)` meaning
   "just character N" will silently get the "rest of string" 2-arg
   behavior instead. Fix per call site (rewrite with direct range
   slicing, e.g. `str[N..N]`), not in the shared shim.

## 8. §10.7 deep functional test (2026-08-31) -- verified clean

Full continuous-session playthrough on the native driver (port
40263), well beyond §5's original registration/look/move/score/quit
pass: fresh registration -> walked all four green-lawn rooms in a
full loop (north/south/east/west, confirming every room's own
exit/hedge description text matches its actual position rather than
just testing one hop) -> three `obj/soul.lpc` emote commands
(`smile`, `dance`, `giggle`, `applaud`, all producing correct
first-person + emote text) -> `take knife` -> `wield knife` (correctly
updated both `inventory`'s display, "A knife (wielded)", and
`score`'s skill line, "hands fighting" -> "knife fighting") -> `quit`
(clean save) -> reconnect after a real gap (password accepted
silently, matching the archive's own "no confirmation" registration
flow) -> `score`/`i` confirming persisted stats/age but empty
inventory. Also spot-checked several of `basic/player/wiz.lpc`'s
always-available wizard commands (`pwd`, `ls`, `Goto <path>`) since
this archive's own documented "no untrusted-wizard threat model"
design (§3) grants them to every player unconditionally -- `Goto
/room/start1` worked correctly (teleport + room re-description). Ran
a 200s WASM `scripts/wasm_boot_watch.sh lplib8 200` long-sit
afterward.

**Confirmed intentional, not a bug**: a fresh reconnect loses the
picked-up/wielded knife and reverts the skill display to "hands
fighting" -- `players/<letter>/<name>.o`'s actual save schema (already
documented in §5) only ever contained `names`/`gender`/`hp`/`stats`/
`player_name`/`current_path`/`skill_structure`/`player_age`; carried
items were never part of what gets saved in the first place. No error
signature anywhere, consistent scope both before and after this
session's testing -- documented per the "no error signature = design"
standard rather than "fixed."

**One genuine gap found, but confirmed out of scope (author's own
demo/scratch content, not reachable by an ordinary player)**:
`Goto /w/lars/castle` failed ("You remain where you are.") while
`Goto` against any real room worked correctly. Root cause: every real
room inherits `/complex/room` -> `/basic/container` (which provides
`receive_objects()`/`add_encumbrance()`, both required by
`basic/move.lpc`'s own `move()` for ANY destination); `w/lars/
castle.lpc` -- Lars's own "It is really only an example of how to make
a castle" demo file, explicitly never placed in any real room's exits
and never referenced anywhere else in the archive (confirmed by
grep) -- only inherits `/basic/move` + `/basic/id`, never
`/basic/container`, so `dest->receive_objects()` silently calls an
undefined function (returns 0, no error) and `move()` always returns
`MOVE_NOT_ALLOWED` for it. Since this object is unreachable through
ordinary play (no room links to it; even the wizard-only `Goto`
command can't successfully target it) and sits in the same `/w/lars/`
personal-scratch directory already flagged for `w/lars/yy.lpc`'s
literal garbage code (§4) -- the established pattern for this
specific author's demo content across every sibling archive this
session (`basis`'s `obj/quicktyper.lpc`, `lpmud245`'s `players/lars/
test.lpc`) -- left unmodified rather than "fixed" by adding an inherit
whose only effect would be making an already-undocumented, unlinked
demo object slightly more functional.

### Regression check

Zero errors in the driver's own captured stdout across the full
session (native builds' `debug.log` is dead for the process's whole
life per AGENTS.md §10.9, so stdout is the only reliable error
channel) and the WASM boot watch transcript.

## 9. §10.7 deep functional test, round two (2026-09-01) -- three real bugs found and fixed via a genuinely new angle

The 2026-08-31 pass (§8 above) tested a single player end-to-end
(movement, untargeted `obj/soul.lpc` emotes, wield/take, quit/relogin)
and found the lib clean. This pass deliberately took the angles §8
never touched: a **full command inventory sweep** (all 68
`obj/soul.lpc` emote verbs, not just 4), **two simultaneous live
connections** interacting with each other, **real PvP combat to
actual death** (this archive has no NPCs at all -- confirmed by grep,
combat is player-vs-player only, via `basic/living/attack.lpc`'s
`kill_command`), and **adversarial/malformed input** on `wield`/
`take`/`Goto`. This immediately surfaced three real, fixable bugs the
single-player pass structurally could not have found.

### 9.1 SEVERE: a dead `id()` in a wizard-toolkit mixin shadowed the player's real identity function, breaking ALL targeted commands archive-wide

**Symptom**: every targeted `obj/soul.lpc` emote (`hug bobqatest`,
`kiss bobqatest`, `slap bobqatest`, etc.) against a second, genuinely
connected, correctly-named player returned the driver's bare "What?"
fallback, as if the target didn't exist. `kill bobqatest` similarly
returned "Attack what ?". This is **the single most impactful bug
found this session** -- it silently disabled every player-to-player
interaction in the game (all directed emotes AND all combat) with zero
error signature, since `present()` returning `0` for "not found" looks
identical to "target genuinely absent."

**Root cause**: `obj/player.lpc` inherits both `/basic/id` (whose real
`id(str)` checks `member_array(str, names)` against
`set_id(({query_player_name()}))`, set in `move_player_to_start()`)
and `/basic/player/trace` (a "general purpose tracer" mixin providing
the always-available `Goto`/`Dump`/`Destruct`/`Call`/`Tell`/`Trans`/
`Set`/`In`/`Clean` wizard commands). `trace.lpc` **also** defined its
own `id(str) { return str == "tracer" || str == "trace"; }` -- a
leftover from when this file was apparently a standalone clonable item
(its neighboring `short()`/`long()`/`drop()`/`get()`/`query_value()`
functions all read exactly like one: a fixed value of 10, a `drop()`
that refuses to be dropped, a `get()` that self-destructs the item if
picked up by a player below level 20). Confirmed genuine in the raw
archive bytes (`raw/basic/player/trace.c`, `raw/obj/player.c`'s
inherit order) -- not conversion damage. This driver's own boot-time
compiler warning names the exact failure: `"id() inherited from both
/basic/player/trace.lpc and /basic/id.lpc; using the definition in
/basic/player/trace.lpc"` -- confirmed the tie-break is "whichever
`inherit` statement comes LAST in declaration order wins," which for
`player.lpc`'s own inherit list (`/basic/id` several lines before
`/basic/player/trace`) silently picks the useless one. Grepped the
whole archive for any caller of `present("tracer", ...)`/
`present("trace", ...)` against a player object: **zero** -- this
`id()` served no purpose whatsoever after being merged into
`player.lpc`, and was pure liability.

**Fix**: removed the dead `id()` entirely from
`basic/player/trace.lpc` (not chained via `id::id(str)` -- nothing
needs the "tracer" identity at all). The boot-time ambiguity warning
disappears entirely once removed.

**Live verification**: booted a fresh driver, opened two simultaneous
raw-socket connections (`aliceqatest`/`bobqatest`), and fired all 68
`obj/soul.lpc` emote verbs at the second player by full registered
name. Before the fix: every single targeted verb returned "What?" (68/68
failed). After the fix: `hug bobqatest` -> "You hug bobqatest." +
`bobqatest` sees "Aliceqatest hugs you.", and likewise for every other
verb tested (kiss/slap/poke/bow/smile/growl/wink/knee) -- all correct.
`kill bobqatest` also started working correctly for the first time
(see §9.2). New AGENTS.md §7.197.

### 9.2 SEVERE: a missing `valid_shadow()` master apply silently broke `die()`, leaving combat stuck in an infinite "already dead" loop forever

**Symptom**: once §9.1 unblocked real PvP combat, a live fight-to-death
between two connected players never actually ended. Health dropped
correctly hit-by-hit down to `-1` (death threshold), `die()` fired
(clones `/obj/shadow_death` and calls `init_shadow()`), but the
attacker's screen showed `"death_shadow: Failed to shadow
Bobqatest."` -- and the SAME message, plus a "You hit N points on
Bobqatest."/"Bobqatest hit you." exchange, repeated **every single
heartbeat indefinitely** (confirmed for 10+ consecutive heartbeats
before manually stopping the test), with `score` permanently frozen at
`Health: -1`. The dead player was never actually turned into a ghost
and combat never terminated.

**Root cause**: `obj/shadow_death.lpc`'s `init_shadow()`:
```
void init_shadow(object ob) {
  if (shadow(ob, 1) == 0) {
    write("death_shadow: Failed to shadow " + ob->query_player_cap_name() + ".\n");
    return;
  }
  shadowing = ob;
  write("You turn into an immaterial ghost.\n");
  this_object()->cease_all_attacks();
}
```
`shadow(ob, 1)` returned `0` every time, hitting the failure branch,
which `return`s WITHOUT ever calling `cease_all_attacks()`. Since the
victim's `hp` stayed at `-1` and its `attackers`/`any_attack` state was
never cleared, `basic/living/attack.lpc`'s `continue_attack()` called
`do_damage()` again on the next heart_beat -- and since `damage > hp`
is always true once `hp` is negative, `do_damage()` called `die()`
AGAIN, forever. Confirmed by reading this driver's own
`interpret.cc`'s `validate_shadowing()`: `shadow()` requires an
explicit master `valid_shadow(object)` apply to approve the call
(`master_approved()`'s `if (!v) return 0;` treats an **undefined**
apply identically to an explicit deny) -- and `secure/master.lpc` never
defined `valid_shadow()` at all. This is the exact same "deny by
default unless master explicitly opts in" shape already fixed twice
in this same lib for `valid_override()`/`valid_seteuid()` (§3/§7)
and once for `valid_write()`/`valid_read()` (§3's most severe finding)
-- just a fourth security apply this project hadn't catalogued yet.
The classic 1990s driver this archive targets never required this
apply at all.

**Fix**: added `int valid_shadow(object ob) { return 1; }` to
`secure/master.lpc`, matching the existing permissive
`valid_override()` stub's rationale (small, fully-trusted
single-owner mudlib, no untrusted-wizard threat model).

**Live verification**: rebooted with the fix, repeated a full
fight-to-death between two connected players. This time: `"You turn
into an immaterial ghost."` printed correctly, the attacker's next hit
showed `"You hit 1 points on a mist."` (confirming the target is now
genuinely the ghost object), immediately followed by `"The combat is
over."` -- `cease_all_attacks()` now fires and the fight correctly
terminates instead of looping forever. The ghost's own `score` command
correctly shows shadow_death.lpc's override (`"You are dead, and have
no score."`). New AGENTS.md §7.198.

**Not fixed (confirmed out of scope, matches this project's existing
"no design invention" rule)**: nothing anywhere in the archive ever
calls `shadow_death.lpc`'s own `revive()` -- there is no timer, no
automatic trigger, and no dedicated player command for it. A player
*could* self-revive via the always-available wizard `Call` command
(e.g. `Call <ownname> revive`, since "here" targets the room, which has
no `revive()`) if they knew the right object/function names, matching
this archive's own documented "no untrusted-wizard threat model"
design (§3) where every player already has unrestricted debug tooling.
Implementing an automatic revival trigger would mean deciding what the
game SHOULD do post-death (a timer? a command? a room?) -- a genuine
content/design question, not a programming bug -- so left alone,
consistent with the already-documented `Goto /w/lars/castle` and dead
`revive()` gaps found in earlier passes.

### 9.3 Minor/cosmetic: `knee`'s gender check called an undefined function, so its "male" flavor-text branch never fired for anyone

**Symptom**: `knee bobqatest` against a freshly registered (default
gender "male") target always printed `"You try to knee bobqatest. Not
very effective though."` -- the archive's OWN "without much effect"
branch, meant only for non-male targets, fired unconditionally.

**Root cause**: `obj/soul.lpc`'s `knee(str)` calls
`who->query_male()`, a function that does not exist anywhere in this
54-file archive (confirmed against the raw archive bytes -- genuine
pre-existing 1990s bug, not conversion damage) -- `basic/living/
gender.lpc` only ever defined `query_gender()`/`query_pronoun()`/
`query_possessive()`/`query_objective()`. Calling an undefined function
via `->` silently returns `0` on this driver (same shape as the
already-documented `Goto /w/lars/castle` gap), so the "male" branch
never fires for ANY target regardless of actual gender. Purely
cosmetic -- neither branch deals any damage or has any other mechanical
effect, only flavor text differs.

**Fix**: `who->query_male()` -> `who->query_gender() == "male"`, using
the archive's own real, already-used equivalent. Zero design decision
involved -- the intended behavior was already unambiguous from the
surrounding branch text.

**Live verification**: rebooted with the fix, `knee bobqatest2`
(freshly registered, default gender "male") against a live second
connection now correctly prints `"You hit bobqatest2 with your
knee."`/`"...writhing in pain!"` -- the male branch.

### 9.4 Minor robustness fix: an unvalidated force-load in the shared wizard-tool object resolver threw an uncaught runtime error on a bad absolute path

**Symptom**: `Goto /some/nonexistent/path` (or any of the other 7
wizard commands sharing `parse_list()`/`find_item()` --
`Dump`/`Destruct`/`Call`/`Tell`/`Trans`/`Set`/`In`/`Clean`) produced no
error visible to the player, but logged a full uncaught LPC runtime
error and stack trace: `"No error handler for error: *call_other()
couldn't find object '<path>'."` This did NOT crash the driver (all
live boots afterward continued normally) -- it's a robustness gap, not
a game-breaking bug -- but it's an unnecessarily ugly failure mode for
an admin tool every player has unrestricted access to (per this
archive's own "no untrusted-wizard threat model").

**Root cause**: `basic/player/trace.lpc`'s `find_item()`, the
`"/%s"` (bare absolute-path) branch: `call_other(tmp, "??"); /* Force
load */ return find_object(tmp);` -- never validates the target file
exists before calling `call_other()` on it. Confirmed genuine in the
raw archive bytes. This driver raises an uncaught runtime error when
`call_other()`'s target fails to load/compile, rather than silently
returning `0` the way the classic driver this archive targets did --
notably, the archive's OWN `w/lars/badload.lpc` scratch file
demonstrates the author already knew this exact operation needs a
`catch()` wrapper (`safe_load()`: `a = catch(safe_load(file));`), just
never applied it to this production call site.

**Fix**: wrapped the force-load in `catch()`:
`catch(call_other(tmp, "??"));`. Player-visible behavior is now
strictly better than before (a bad path now cleanly falls through to
the normal "What?"/"Attack what ?" fallback the way a legitimately
absent target already did, rather than producing no feedback at all).

**Live verification**: rebooted with the fix, `Goto
/this/path/does/not/exist` now cleanly shows "What?" and the session
continues normally; a subsequent successful `Goto /room/start2`
worked. The debug log still shows the caught error's stack trace
(expected -- this driver logs errors caught by `catch()` too, purely
informational) but the frame list now shows `in <catch>()`, confirming
it no longer propagates uncaught.

### 9.5 Other angles tried, confirmed clean

- **Full soul.lpc command inventory** (all 68 emote verbs, both
  untargeted and targeted forms): no crashes on any verb, bare or
  targeted, including deliberately garbage targets (empty, self,
  nonexistent, a 500-character string). All argument-optional verbs
  correctly fall back to their untargeted message when called bare;
  all argument-required verbs correctly no-op (driver default "What?")
  when called bare or against a nonexistent target.
- **`kiss`'s dead "frog curse" branch**
  (`call_other(who, "query_frog")`/`call_other(_, "frog_curse", _)`):
  both functions are undefined everywhere in the archive (confirmed
  genuine in raw bytes, an entire never-implemented sub-feature, not
  just a renamed accessor like §9.3's `query_male()`) -- always
  silently `0`, so `kiss` always falls through to its ordinary message.
  Not fixed: implementing an actual "turn into a frog" curse mechanic
  from scratch would mean inventing new content/design (what happens
  while cursed? for how long? what un-curses you?), not making
  already-intended logic work -- out of scope, unlike §9.3 where a
  real equivalent function already existed to redirect to.
- **Adversarial input on `wield`/`take`**: `wield knife` with nothing
  carried -> "You have no such thing!" (correct); `take
  nonexistentitem123` -> "What nonexistentitem123?" (correct); no
  crashes.
- **Other `/w/lars/` files beyond the already-documented
  `castle.lpc`/`yy.lpc`**: `badload.lpc` (a deliberate catch()-safety
  test script, see §9.4), `rand.lpc` (a standalone math test), `xx.lpc`
  (a treasure-item test clone with an intentionally-broken second
  command, `add_action("::foobar", "crash")`, wired to an undefined
  `crash()` function -- but "::foobar" is not a usable verb string
  through the normal parser, and nothing else references it),
  `workroom.lpc` (a real, correctly-`/complex/room`-inheriting personal
  room, unlike `castle.lpc`) -- all genuinely Lars's own `/w/lars/`
  scratch content, matching the already-established pattern for this
  author across every sibling archive this session. No new
  actually-reachable "undefined function silently returns 0" instance
  found beyond the already-documented, already-out-of-scope
  `castle.lpc` case.

### Regression check (round two)

Zero runtime errors (`No error handler`/`FATAL`) in the driver's own
captured stdout across the full corrected test session (fresh
registration x2, full 68-verb x2 emote sweep, adversarial input,
`Goto` adversarial paths, a complete real PvP fight to actual death,
and post-death `score`/`Call` probing) after all three fixes above.
One unrelated environmental incident during testing: the driver
process received an external `SIGTERM` while idling in `epoll_wait()`
(confirmed via its native crash-handler stack trace showing no LPC
code on the stack at the time) partway through an early test run --
almost certainly this sandboxed environment's own process management
and NOT caused by any lplib8 code (a subsequent isolated repro of the
specific command being tested at that moment did not reproduce any
crash on a fresh driver). Flagged here only for the record, not as a
mudlib bug.
