# LPmud 2.4.5 -- porting notes

Source: `other/2.4.5.tar.gz`, recovered directly from the still-live
`ftp.lysator.liu.se` LPMud archive mirror
(`https://ftp.lysator.liu.se/pub/lpmud/mudlibs/other/2.4.5.tar.gz`).
Slug `lpmud245`, number 960, port 40262. 582 raw files (286 `.c`
sources), mudlib root at the archive's own top level. No `driver_hook`/
`set_driver_hook`/`H_[A-Z_]+` usage anywhere (confirmed by grep) --
genuinely a pre-LDMud, MudOS-line-compatible snapshot, unlike the
LDMud-ported Docker Hub `ldmuddev/lp245` image of nominally the same
version. `obj/master.lpc`'s own header comment: "This is the LPmud
master object, used from version 3.0... designed to be used with
mudlib 2.4.6 or earlier."

## 1. Extraction and conversion

Pure ASCII/English archive, 0 lossy conversions. 286 files renamed
`.c`->`.lpc`, 5 literal `.c"` references fixed, 8 files
`static`->`nosave`.

## 2. Proactive on-sight checklist findings

- `status` used as a declared type (AGENTS.md §6.8) in 8 files:
  `obj/weapon.lpc` (`wielded`), `obj/monster.lpc` +
  `obj/monster.talk.lpc` (`healing`), `obj/torch.lpc` (`is_lighted`),
  `room/pub2.lpc` (`drink`), `obj/simul_efun.lpc` (`trunc_flag`).
  Fixed to `int`.
- `new` used as an ordinary variable in `room/post.lpc` (a mail-status
  string) -- renamed to `newmsg`. `function`/`class` used as ordinary
  variable names in `room/pub2.lpc`/`room/vill_road2.lpc`/
  `room/yard.lpc` (renamed to `funclist`) and `room/orc_vall.lpc`/
  `room/fortress.lpc` (renamed to `wclass`) -- all three are the
  hard-reserved-keyword class documented in this session's new
  AGENTS.md §6.2 entry (added while onboarding the sibling `basis`).
  `bull_board.lpc`'s `new(hd) {...}` command handler (wired via
  `add_action("new", "note")`) hit the same `new` collision -- renamed
  the function AND the add_action string to `post_new`.
- `in(str) {...}` (an unreferenced dead command handler) in
  `obj/trace.lpc`/`obj/trace2.lpc` -- `in` is also a hard-reserved
  keyword (the `foreach ... in` clause). Renamed to `go_in` (dead
  code, never wired via add_action, so purely a compile-blocker fix).

## 3. Compile-time / boot-time driver-compat fixes

- **Missing `global include file`** (same class as `basis`'s finding):
  this archive ships no dedicated mudlib-wide header at all. Added
  `include/empty.h` (a placeholder, not original content) and pointed
  `global include file : <empty.h>` at it.
- **Quoted-relative-header resolution**: `obj/living.h`/`obj/debug.h`
  resolve fine next to their own `.lpc` files once `master.lpc`
  implements `get_include_path()` (AGENTS.md §6.1's standard fix,
  added since this archive had none) -- but `obj/living.lpc` (and
  its dependents `obj/monster.lpc`/`obj/monster.talk.lpc`/
  `obj/player.lpc`/`obj/shut.lpc`/`obj/leo.lpc`) quote-includes
  `"log.h"`, which actually lives in `room/log.h`, NOT next to
  `living.lpc` -- a genuine cross-directory shared header in the
  original archive. Fixed by adding `/room` to `include directories`
  (get_include_path()'s `:DEFAULT:` fallback then finds it there).
- **`get_root_uid()`/`get_bb_uid()` missing** (AGENTS.md §7.2's
  documented class): this driver's `PACKAGE_UIDS` build unconditionally
  `exit(-1)`s at boot without them; this archive predates the uid/euid
  system entirely (only one incidental `seteuid()` call in the whole
  mudlib). Added flat stubs returning `"ROOT"`/`"BACKBONE"`.
- **`creator_file()` missing -- a related but DISTINCT requirement
  from `get_root_uid()`/`get_bb_uid()`, not previously catalogued this
  precisely**: `vm/internal/simulate.cc`'s `apply_master_ob(APPLY_CREATOR_FILE,
  ...)` is called for EVERY object load (to assign a euid) whenever
  `PACKAGE_UIDS` is on, unconditionally required, `error()`ing
  ("master object: No function creator_file() defined!") the first
  time ANY object beyond master/simul_efun itself gets loaded --
  unlike `author_file()`/`domain_file()`, which only warn-and-fall-back.
  Added a flat `"ROOT"` stub.
- **`valid_override()` missing**: this driver requires explicit master
  permission before any object may define a function sharing a real
  efun's name, or even call `efun::something()` at all (AGENTS.md
  §6.2's existing note on this, previously only seen via the
  `REF_RESERVED_WORD`-adjacent case) -- needed the moment the
  `move_object(dest){efun::move_object(dest);}` shims (below) got
  added to every object file. Added a permissive always-1 stub (a
  small, fully-trusted single-owner mudlib, no untrusted-wizard
  threat model).
- **`move_object()` 2-arg vs 1-arg dialect gap** (AGENTS.md §7.158):
  111 call sites across the whole mudlib used the classic
  `move_object(item, dest)` form; this driver's efun takes exactly one
  argument (the destination) and always moves `this_object()`.
  Mechanically rewrote every call site: `move_object(this_object(),
  X)` -> `efun::move_object(X)` (8 sites, no call_other needed), all
  other `move_object(A, B)` -> `A->move_object(B)` (111 sites) --
  BUT since `call_other()` never falls back to a same-named efun on a
  miss (confirmed the hard way: this exact "silent no-op" is
  documented in §7.158 as "the single worst finding, with zero error
  output of any kind"), every object that could ever be the "item"
  argument needed ITS OWN `move_object(dest) { return
  efun::move_object(dest); }` method. Since this archive has NO shared
  base class at all (confirmed: zero `inherit` statements anywhere
  under `obj/`/`players/`), added this mechanically to all 59 files
  under `obj/` and `players/` (excluding `master.lpc`/`simul_efun.lpc`)
  as a blanket precaution rather than hand-tracing every call site's
  actual argument type.
- **`transfer(item, dest)` -- a second, distinct old MudOS efun for
  the exact same "privileged move" concept, not previously
  catalogued**: 12 call sites (`room/fortress.lpc`, `room/orc_vall.lpc`,
  `room/bank.lpc`, `room/vill_road2.lpc`, `obj/player.lpc`,
  `obj/trace.lpc`/`obj/trace2.lpc`). Not a real efun on this driver
  either. Rewritten identically to `move_object()`'s treatment:
  `transfer(A, B)` -> `A->move_object(B)`, reusing the same
  per-file shim added for the `move_object()` fix above. Known
  imprecision: a few call sites check the OLD efun's return value
  for success (`if (transfer(...) != 0)`); our shim's return value
  doesn't perfectly preserve that signal (see §7 below) -- acceptable
  for these low-stakes wizard-utility/NPC-equip call sites, not
  chased further.
- **`command(str, ob)` 2-arg vs 1-arg dialect gap -- a new bug class,
  not previously catalogued**: old MudOS's `command(str, ob)` ran
  `str` as if `ob` had typed it; this driver's `command(str)` (single
  arg only) always runs `str` as if `current_object` (the object
  whose OWN code is calling command(), NOT necessarily
  command_giver/this_player()) had typed it. ~12 call sites across
  `obj/quicktyper.lpc` (a heartbeat-driven queued-auto-typer wizard
  utility), `obj/trace.lpc`/`obj/trace2.lpc`, `obj/player.lpc`, and
  `room/fortress.lpc`/`room/orc_vall.lpc` (an NPC forced to `wield` a
  weapon) all needed to run a command AS SOME OTHER, specific object
  -- impossible directly on this driver (same "call_other() never
  falls back to an efun" root cause as `move_object()`/`transfer()`
  above: a bare `ob->command(str)` would silently no-op). Fixed with
  a `do_command(str) { return command(str); }` wrapper added to
  `obj/player.lpc` and `obj/monster.lpc` (the two classes ever
  targeted), then called via `target->do_command(str)`. Also fixed
  `obj/player.lpc`'s own `snoop_on()`: the bare 0-arg `snoop();` and
  the "start snooping" `snoop(ob);` both needed updating for this
  driver's real `snoop(snooper, snoopee)` signature (single-arg form
  STOPS snooping by that snooper, the OPPOSITE of what the original
  1-arg `snoop(ob)` call intended) -- fixed to `snoop(this_player())`
  and `snoop(this_player(), ob)` respectively.
- **`add_action("fun"); add_verb("cmd");` -- the archaic 2-statement
  form of command registration, not previously catalogued**: 366 call
  sites across 111 files use this pair (an implicit-verb `add_action`
  immediately followed by a separate `add_verb` call setting the real
  verb text) instead of the 2-argument `add_action(fun, cmd)` this
  driver requires (`void add_action(string|function, string|string*,
  void|int)` -- the 2nd/cmd parameter is NOT optional here). `add_verb`
  itself is not a real efun on this driver either, so this failed as
  "Too few arguments to add_action" for the 358 add_action(fun) calls,
  while the immediately-following add_verb() calls, sharing the same
  compiled statement's error-recovery, escaped a distinct diagnostic.
  Mechanically merged every `add_action("X"); add_verb("Y");` pair
  (any whitespace) into `add_action("X", "Y");`.
- **A genuine, severe infinite-recursion bug in the ORIGINAL 1990s
  source, exposed (not introduced) by this driver's `file_name()`
  convention** -- the most severe and interesting finding in this
  lib. `room/room.lpc` (the shared base every real room `inherit`s)
  implements `convert_number()`/`query_numbers()` as a shared cache:
  the FIRST time any room needs to spell out its exit count in words
  ("There are three obvious exits..."), it calls
  `query_numbers()`, which -- to avoid every room duplicating the same
  10-word array -- delegates to a SINGLE shared instance at the path
  `/room/room` itself (loaded as a real, standalone object, not
  through inheritance) via `call_other("room/room", "query_numbers")`.
  That shared instance is supposed to recognize itself and populate
  the array directly instead of delegating again, via
  `if (file_name(this_object()) == "room/room") ...`. This driver's
  `file_name()` efun **always returns a leading slash**
  (`efuns_main.cc`'s own comment: "This function now returns a leading
  '/'") -- so the comparison against the bare `"room/room"` (no
  slash) was ALWAYS false, even for the `/room/room` object itself,
  meaning its own `query_numbers()` call always took the "delegate to
  room/room" branch -- calling ITSELF, via call_other, forever. This
  is a genuine "Too deep recursion" stack overflow, hit by literally
  every room's long-form description whose exit list needed to be
  spelled out, i.e. every room with more than one exit --
  reproducible on the SECOND room a new player ever enters
  (`room/vill_green`, reached via `south` from the starting
  `room/church`). Made much harder to spot than a typical crash
  because this driver's own `mudlib error handler` config option
  (default ON) actively SUPPRESSES the real error text from ordinary
  (non-wizard) players, replacing it with the configured
  `default error message` ("Something is wrong.") -- the crash was
  fully logged to `debug.log` with a complete "Too deep recursion"
  trace the whole time, but nothing about the player-facing symptom
  hinted that an error had occurred at all (no "Undefined function",
  no visible stack trace, just a game message that read like
  legitimate (if terse) content). Diagnosed by directly reading
  `debug.log` in full after a live repro, not by trusting the
  player-facing output. Fixed by comparing against `"/room/room"`
  (leading slash) instead. **New AGENTS.md catalog entry this
  session** (see §7 below) -- both for the `file_name()`
  leading-slash gotcha itself, and for the "a non-wizard player's
  error output can be a complete red herring; always check debug.log
  directly" methodology point.
- **`obj/player.lpc` called `move_player()` -- literally the function
  every single instance of room-to-room movement in the entire
  mudlib funnels through -- but never defined it, and doesn't
  inherit anything that does** (confirmed: zero `inherit` statements
  anywhere in this archive's `obj/`/`players/` trees). The real
  implementation exists, complete and directly reusable (byte-
  identical variable names to what player.lpc itself already
  declares: `msgout`/`msgin`/`ghost`/`cap_name`/`mmsgout`/`mmsgin`/
  `is_invis`/`attacker_ob`/`hunted`/`brief`), in `obj/living.lpc` --
  a separate, apparently-unfinished file that looks like early
  work-in-progress toward a shared "living" base class that never got
  wired up to the actual player object. Every room's own `move()`
  command handler, plus `obj/shut.lpc`, `obj/roommaker.lpc`,
  `obj/master.lpc`, and `room/doorway.lpc`, all call
  `this_player()->move_player(...)` expecting it to just work.
  Confirmed live: since this driver only errors on an undefined bare
  function call AT THE POINT IT'S ACTUALLY INVOKED (not at compile
  time -- every one of this session's "missing classic efun"
  discoveries, `extract`/`log_file`/`cat`/`creator`/`previous_file`/
  `transfer`, surfaced the identical way), the ENTIRE compile sweep
  (283/286, all real failures accounted for -- see §4) stayed clean
  despite this, and the break was only caught by an actual live walk
  between two rooms. Fixed by copying `move_player()`'s full body
  from `obj/living.lpc` into `obj/player.lpc` verbatim, adding the
  two genuinely-missing globals it also needs
  (`int is_npc, hunting_time;` -- `NAME_OF_GHOST` was already
  available via player.lpc's existing `#include "living.h"`).

## 4. Compile-sweep triage: known-acceptable remaining failures (3 of 286)

- `players/lars/test.lpc` -- Lars Pensjö's own personal scratch/test
  room (`players/lars/`), containing literal `1/0;` statements as
  intentional driver-crash-testing debug code (a genuine 1990s
  development habit, not conversion damage -- confirmed against the
  raw archive bytes). This driver catches it at COMPILE time (constant
  folding) rather than the original driver's presumed runtime-only
  behavior. Left as-is: it's the author's own private test file, never
  referenced by anything else, not reachable by an ordinary player.
- `room/def_castle.lpc` -- a genuine TEMPLATE file, never meant to
  compile standalone. `obj/master.lpc`'s `master_create_wizard()`
  reads this file's SOURCE TEXT at runtime and prepends
  `#define NAME "..."`/`#define DEST "..."` lines before writing the
  result out as a brand-new wizard's own castle file -- confirmed by
  reading that function directly. `lpcc_check.sh`'s blind file-list
  sweep has no way to know to inject those defines; this is the
  template-file counterpart to AGENTS.md §10.4's "genuinely missing
  content" false-positive class, not a bug.
- `obj/explore_xp.lpc` -- a standalone experience-tracking utility,
  confirmed completely unreferenced by anything else in the archive
  (`grep -rl "explore_xp"` finds nothing outside its own file). Its
  own `set_name()` has a defensive self-destruct
  (`if (... && !creator(...) && !creator(previous_file())) { ...
  destruct(this_object()); }`) that fires under `lpcc_check.sh`'s
  isolated instantiation (no real `previous_object()` calling
  context) but would not fire under a normal load in real play.
  Matches AGENTS.md §10.4's documented isolated-load false-positive
  class.

## 5. Live playthrough (native driver)

Full flow verified in one continuous session, port 40262: fresh
registration (name / password twice / email `none` / gender) reaching
`room/church` -> `look` (correct room description, all objects
mentioned) -> `south` (moves to `room/vill_green`, correct room
description including "There are three obvious exits: north, west
and east" -- the exact code path the `room/room.lpc` recursion bug
above broke) -> `look` again (correct) -> `score` (correct XP/gold/HP/
spell-points/age display) -> `quit` (clean save + disconnect). Tested
with both `m`/`f` gender selections. Re-login (existing-password
path) verified separately: password accepted, correct room
reached, movement and `score` both still correct. `debug.log` fully
clean (zero error lines) across every test session after all fixes
above.

## 6. WASM

Boots and plays identically under the WASM build
(`~/src/fluffos/build-wasm/src`, via `scripts/wasm_client.js`): full
registration -> `look` -> `quit`, correct output throughout.
`wasm_status: playable`.

## 7. New AGENTS.md catalog entries added this session

(Alongside the `basis`-onboarding entries for the closure/function-
pointer gap, `new`/`class` reserved words, and the `extract`/
`log_file`/`privp`/`cat` missing-efun list.)

1. **`file_name()` always returns a leading `/` on this driver** --
   any archive comparing `file_name(ob) == "bare/path"` (no leading
   slash) against a literal path constant will silently ALWAYS be
   false. Watch for this specifically in "am I my own shared
   singleton instance" self-identity checks, where a false negative
   causes infinite self-delegation (a "Too deep recursion" crash) --
   as opposed to the more common case of just silently failing to
   match, which tends to surface as a missing-feature symptom instead
   of a crash.
2. **A non-wizard player's visible error output can be a complete red
   herring when `mudlib error handler` is on (the default)**: this
   driver replaces the real error text with the configured
   `default error message` for any non-wizard `command_giver`,
   while still logging the FULL real error (including a complete
   stack trace) to `debug.log` every time, unconditionally. A crash
   whose player-facing symptom looks like ordinary (if terse) game
   content -- not an obvious error message -- should still prompt a
   direct `debug.log` read before concluding "no bug here." This
   generalizes AGENTS.md §10.3's existing point about `logon()`
   swallowing errors to a much broader, config-driven case that can
   apply to literally any command.
3. **`command(str, ob)` (run a command as a specific, non-current
   object) is not supported on this driver at all** -- `command(str)`
   always runs against `current_object`, never `command_giver`/
   `this_player()`. Needs the same per-target `do_command()`-wrapper
   treatment as `move_object()`'s 2-arg dialect gap (§7.158).
4. **`transfer(item, dest)`** -- a second classic MudOS efun for the
   same "move an arbitrary object" concept `move_object()` also
   covers on old drivers; not real on this driver either. Fix
   identically: `A->move_object(B)` via the same per-object shim.
5. **`add_action("fun"); add_verb("cmd");`** -- a two-statement legacy
   idiom for what modern `add_action(fun, cmd)` (2-arg, both required
   on this driver) does in one call. Mechanically mergeable via a
   regex over adjacent statement pairs.
6. **`creator_file()` is required by this driver's `PACKAGE_UIDS`
   build for literally every object load**, not just at boot like
   `get_root_uid()`/`get_bb_uid()` (§7.2's existing entry) --
   `creator_file()` deserves its own line in that catalog entry since
   its absence blocks ALL subsequent loading, not just initial boot.

## 8. §10.7 deep functional test (2026-08-31)

Full continuous-session playthrough on the native driver (port 40262):
fresh registration -> walked the ENTIRE village crossroads area
(church -> vill_green -> vill_track -> vill_road1 -> vill_road2 ->
shop -> adv_guild -> yard) rather than just the two rooms §5's original
pass covered, tested the shop's `list`/`buy`/`value` commands, the
guild's `list`/`cost`/`advance` commands, a real multi-round combat
against the yard's `Beggar` NPC (hit/miss/damage messages both
directions, correct HP tracking), `quit` mid-combat, and a fresh
reconnect (password accepted, HP correctly persisted at the
damaged value, room reset to the starting `room/church` matching this
lib's existing documented save-data scope). Also ran a 200s WASM
`scripts/wasm_boot_watch.sh lpmud245 200` long-sit.

### Severe bug found and fixed: ~80% of the whole game world (70 of 88
rooms) started dark and/or completely exit-less on every fresh boot,
for up to 30 minutes, because the `create() { reset(0); }` fix already
applied by hand to a handful of custom rooms (§3's `room/church.lpc`
writeup) was never extended to the two shared macro headers
(`room/room.h`'s `ONE_EXIT`/`TWO_EXIT`/`THREE_EXIT`/`FOUR_EXIT` and
`room/std.h`'s identically-named but independent macro set) that
generate the vast majority of this archive's actual room files

Found by simply continuing the walk past where §5's original pass
stopped: `south` from the church into `room/vill_green` worked exactly
as documented, but the very next room east (`room/vill_track`, one hop
from spawn) printed `"A dark room."`, `look` said `"It is too dark."`,
and **every direction command including the one that had just been
used to enter the room returned `"What?"`** -- a genuine dead-end
softlock for any new player who wandered one room past the tested
path, not a cosmetic darkness issue.

Root cause: this whole archive uses the classic `reset(arg){ if
(!arg) {...} }` idiom as its room constructor (exits, light, and
descriptions are all populated inside `reset()`, only on the very
first, `arg==0` call) -- but this driver's `call_create()` always
marks a freshly-loaded object as "already reset" and defers ITS real
first `reset()` call for up to `"time to reset"` seconds (`room/
church.lpc`'s own extensive comment, §3, already documents this
exactly). `church.lpc` (and a handful of other hand-written rooms:
`bankroom`, `elevator`, `wiz_hall`) got an explicit `create() {
reset(0); }` added individually to force synchronous initialization --
but this archive's OTHER 88 room files are almost all generated by one
of two near-identical macro-header systems (`room/room.h`, inherited
via `#include "room.h"` + `inherit "room/room"`, used by 68 files;
`room/std.h`, a fully standalone macro set with no inheritance, used
by 13 files, 4 of which -- including `church.lpc` itself -- override
the macro entirely with hand-written code and already had the fix).
**Neither macro header itself was ever given the `create()` fix**, so
every room instantiated purely by invoking `ONE_EXIT(...)`/
`TWO_EXIT(...)`/etc. (which is the OVERWHELMING MAJORITY of the
explorable map: every `forest*`/`plane*`/`eastroad*`/`giant_*` room,
plus the shop, the bank, and the adventurers guild) never ran its
`reset()` until the driver's own lazy scheduler eventually got to it.

The two macro systems differ in how bad the resulting symptom is:
- **`room/room.h`-based rooms** (68 files) register their exits'
  `add_action()` calls INSIDE `reset()` itself (`init()` isn't used for
  movement at all here) -- so an unreset room has **NO command
  handlers for any direction whatsoever**, a hard, un-escapable dead
  end (confirmed live on `room/vill_track`).
- **`room/std.h`-based rooms** (13 files, e.g. `room/shop`,
  `room/adv_guild`) register movement via `init()` instead, which this
  driver DOES call synchronously every time a player enters -- so
  these rooms remain fully navigable even before their real `reset()`
  fires, just permanently dark (`"A dark room."`/`"It is too dark."`,
  no short/long description text) until it does. Confirmed live on
  both `room/shop` and `room/adv_guild`, one and two hops respectively
  from the village's own main crossroads -- i.e. content every single
  new player would reach within their first few moves.

**Fix**: added `create() { reset(0); }` directly inside each of the 8
macro definitions (4 in `room/room.h`, 4 in `room/std.h`) rather than
hand-editing 81 individual room files -- confirmed no macro-generated
file already defines its own `create()` (would be a duplicate-function
compile error) and no already-fixed hand-written file (`church`,
`bankroom`, `elevator`, `wiz_hall`) invokes either macro. Verified
live, post-fix: `room/vill_track` is lit with both exits working on
the very first visit after a fresh boot; `room/shop` and
`room/adv_guild` are fully described (list/buy/cost/advance all
producing correct output) on first entry too. New AGENTS.md catalog
entry, §7.185 (this is a coverage gap in an ALREADY-catalogued fix
pattern -- §3's own writeup already explains the underlying mechanism
correctly -- rather than a new root cause, but the specific "a shared
macro header used by the vast majority of content files was missed by
a fix applied file-by-file to only the hand-written exceptions" shape
is worth its own entry so a future sweep checks macro headers first).

### Confirmed NOT a bug -- one remaining gap, low priority, left alone

`obj/quicktyper.lpc` (a heartbeat-driven wizard debug/auto-typer
utility, not player-facing content) is the ONLY file under `obj/`/
`players/` still missing its own `create()` fix (every other file in
those trees already has one, confirming this archive's original
onboarding pass thoroughly covered `obj/` by hand -- the miss was
specifically the two room macro headers, not a general gap). Its
`reset()` only sets an `owner` name and allocates a history array for
its own debug/logging use, both of which the driver's own eventual
lazy reset (or the object's own later use) still populate correctly
before they matter; no observed player-facing symptom. Not fixed,
noted here for completeness.

### Regression check

Full re-walk of the fixed rooms plus every other already-verified
command (score, inventory, combat, quit, reconnect) in one final
continuous session: zero errors in the driver's own captured stdout
(this native build's `debug.log` is dead for the process's whole life
per AGENTS.md §10.9, so stdout is the only reliable error channel).
