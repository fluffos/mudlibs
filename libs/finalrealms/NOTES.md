# Final Realms -- porting notes

Source: `git clone https://github.com/quixadhal/fr` (commit `16308bd`, cloned
2026-08-25). Slug `finalrealms`, number 168, port 40216. Mudlib root is the
clone's `mudlib/` subdirectory (`mudos/` alongside it is a bundled v21.7b21
MudOS driver source tree, ignored -- this project uses its own driver).
Original repo history stops in 1998 (`git log -1` on the clone shows a
1998-11-10 commit date), making this the oldest-vintage lib onboarded this
session -- a genuine late-generation classic MudOS mudlib (not a CD-driver
codebase like `genesis`), so the compat gap with FluffOS was narrower than
`genesis`'s in kind (no `&operator`/`@` composition, no uid:euid string-pair
model) but the archive itself had more incidental bitrot/lost-content gaps.

## 1. Conversion

`scripts/convert_lib.sh` on `raw/mudlib` -> `work`: all-ASCII source (0
lossy conversions except 4 pre-existing corrupted bytes in two duplicate
`ave8.c` files and two already-empty `intermud.o` save files), 3273 files
renamed `.c`->`.lpc`, 2933 literal `.c"` references fixed, 6 local
angle-bracket includes converted to quotes, 7 files `static`->`nosave`.

## 2. Compile-time driver-compat fixes

- **`switch` with only `default:`** (AGENTS.md §6.3): `secure/simul_efun/
  mud_long_name.lpc`'s `switch (mud_name()) { default: ... }` -- collapsed
  to a plain `return`.
- **`status` as a legacy type keyword**: this MudOS-era codebase uses
  `status` (an old LPmud alias for `int`, signalling boolean intent) as a
  return/parameter type throughout -- FluffOS has no such type at all, so
  every use was a hard "unexpected L_IDENTIFIER" parse error. Swept
  `\bstatus\b` -> `int` across the 16 files that used it as a genuine type
  (verified none of the ~90 other `status` hits repo-wide are type
  positions -- the rest are English prose in comments/strings/identifier
  substrings like `"ansi-status"`, left untouched).
- **`add_item()`/`add_feel()` declared `string`, called with an array**:
  `std/room.lpc`'s `add_item(string str, string desc)` and `std/senses.lpc`'s
  `add_feel(string feel, string feel_desc)` were both declared narrower than
  the type their own bodies actually branch on (`setup_item()`/`feels[]`
  handling already used `pointerp()`/`mixed` internally) -- 1200+ and 190+
  call sites respectively pass `({"a","b"})`-style arrays (the documented
  "give many items the same description" idiom). Widened both to `mixed`.
  `add_feel()` specifically had a pre-existing internal inconsistency: its
  own forward declaration already said `mixed`, only the definition said
  `string`.
- **Missing base case for the `int_query_static_auto_load`/
  `query_dynamic_auto_load`/`init_static_arg`/`init_dynamic_arg` `::`-chain**:
  `obj/weapon.lpc`, `obj/armour.lpc`, `std/chest.lpc`, `obj/label.lpc` each
  define these and call `::`-qualified versions of themselves to walk up to
  a parent's saved state, but no ancestor anywhere in this codebase ever
  defined a base case -- "Unable to find the inherited function". Added
  no-op/empty-mapping terminators to `std/item.lpc` (the common ancestor).
- **`condition::create()` calling a function that doesn't exist**:
  `obj/weapon.lpc`/`obj/armour.lpc`'s `create()` both call
  `condition::create()`, but `std/basic/condition.lpc` never defined one.
  Added a no-op `create()` there.
- **2-arg integer `exp(base, exp)` power function**: `obj/weapon.lpc`'s
  `set_value()` calls `exp(2, enchant-1)` expecting this codebase's own
  historical integer-power helper (`std/basic.old/misc.lpc`'s `int exp(int
  x, int y)`, "added by dank Feb 23, 93") -- but that file is in the dead
  `.old` tree, not part of the live inherit chain, and this driver's real
  `exp()` efun is the 1-arg float natural exponential. Added a small
  `private int int_pow(int x, int y)` helper directly in `obj/weapon.lpc`
  (the only live call site) rather than reviving the dead file.
- **`lowest_cond` used but never declared**: `obj/weapon.lpc`'s and
  `obj/armour.lpc`'s `query_dynamic_auto_load()`/`init_dynamic_arg()` both
  read/write a `lowest_cond` global that was never declared anywhere in
  either file -- "Undefined variable". Declared `int lowest_cond;` in both
  (342 downstream call sites across 133 weapon/armour-derived files were
  affected by the `obj/weapon.lpc` half alone).
- **Missing `ROOM`/other path macros in several newbie-zone `path.h`
  headers**: `d/newbie/grads/rooms/path.h` and its `cave1/` sibling never
  defined `ROOM` (every other zone's `path.h` does, e.g. `d/newbie/elf/
  rooms/path.h`) even though `add_exit(...)` calls in that zone's rooms use
  it; `d/newbie/new_halfelf/rooms/path.h` had `ROOMS` but not `ROOM`
  (`guild.lpc`/`shop.lpc` use the singular). `d/newbie/grads/npcs/` and
  `d/newbie/grads/temp/` had no `path.h` at all ("Cannot #include path.h"),
  as did `d/newbie/newelf/` (top level) and `d/newbie/newelf/npcs/`. Added/
  extended `path.h` in each, mirroring the sibling that already had one;
  `grads/npcs/wizard.lpc`'s `OBJ+"fr_arrow_learnable.lpc"` clone target
  doesn't exist anywhere in this archive (lost content, not this port's
  doing) -- `OBJ` itself still needed a definition to compile, so it's
  pointed at this zone's own (currently nonexistent) `obj/` directory,
  matching the convention other zones' path.h files use; the clone simply
  fails gracefully at runtime exactly as it would have upstream.
- **Missing per-domain `log/` directories**: `secure/master/error_handler.
  lpc` computes `"/d/"+domain+"/log/debug.err"` for any uncaught error
  inside domain code, but NONE of the four domains (`mudlib`, `vehicle`,
  `newbie`, `heaven`) shipped a `log/` directory (`newbie` had a `logs/`,
  plural, which doesn't match) -- every domain-code runtime error crashed
  the error handler ITSELF while trying to log the original error
  ("Wrong permissions for opening file ... for append", "No such file or
  directory"), masking the real error behind a secondary one. This is a
  previously-documented "lpcc-vs-live-driver artifact" pattern for this
  project, but it also affects a REAL boot (any domain-code runtime error,
  not just lpcc), so it's a genuine structural gap, not just a sweep
  artifact. Created `d/{mudlib,vehicle,newbie,heaven}/log/` (with
  `.gitkeep`).
- **`d/heaven/heaven/*` rooms inherit `/std/room` directly instead of
  `/std/shield_room`**: every admin-zone room in this directory (`ave1`
  through `ave16`, `admin2`, `admin3`, `entry`, `ntower1`, `palace1`,
  `palace2`) calls `shield_it(SHIELD, ...)` in `init()`, but `shield_it()`
  is only defined in `/std/shield_room.lpc` (itself a thin wrapper around
  `/std/room`) -- a pre-existing content bug (wrong base class), not
  something this port introduced, but compile-blocking regardless. Swapped
  the `inherit` in the 19 live files (`room/admin/heaven.nothere/*` has an
  identical-looking but entirely unreferenced duplicate set -- see \S4 --
  left untouched).
- **`std/newbieguild.lpc`'s `reset()` crashing every newbie-guild room**:
  `clone_object("/obj/misc/board")` can return 0 (confirmed under `lpcc`'s
  isolated single-object test harness, a previously-documented artifact of
  that harness lacking a real preload/euid context), and the following
  `board->set_datafile(...)` then hard-errors on `call_other()` against
  `int(0)`, taking down every `/std/newbieguild`-derived room's `create()`
  (~20 live guild rooms across the newbie zones). Guarded with `if
  (board)`.
- **`std/pub.lpc`'s `create()` crashing every tavern**: unconditionally
  calls `BAR_TRACKER->add_bar(...)` where `BAR_TRACKER` is `/d/aprior/
  guilds/bard/tools/bar_tracker.lpc` -- the "aprior" bard-guild domain
  never shipped anywhere in this archive (lost content), so this crashed
  `create()` for all 20+ live `/std/pub`-derived taverns with
  "call_other() couldn't find object". Wrapped in `catch()` so the
  (already-lost) songster-quest bar tracking silently no-ops.
- **`protected private` (multiple access modifiers)**: `secure/crerem/
  remote.lpc`'s `eventProcess()` declared both `protected` and `private`
  together -- every sibling function in the same file uses `protected`
  alone; dropped the redundant `private`. This file IS in the live
  preload list (`master.o`'s saved `preload` array includes `/secure/
  crerem/remote`), so this one mattered for a real boot, unlike most of
  the daemon-directory syntax errors found during the sweep (see \S4).
- **`query_ed_mode()`/`ed_start()`/`ed_cmd()` not available in this driver
  build**: this codebase's editor glue (`global/prompt.lpc`, `global/
  process_input.lpc`, `global/new_ed.lpc`) was written against FluffOS's
  "new" ed API (`ed_start`/`ed_cmd`/`query_ed_mode`, declared in `packages/
  core/core.spec`'s `#else` branch), but **this project's compiled driver
  binary was built with `OLD_ED` defined** (confirmed via `nm` on the
  driver: `f_ed()` is present, `f_ed_start()`/`f_ed_cmd()`/
  `f_query_ed_mode()` are not) -- meaning only the older single-efun `ed()`
  API is actually available. This broke compilation of `global/player.lpc`
  itself (`new_ed.lpc`/`process_input.lpc` are `#include`-fragments into
  it, not separate objects), which would have meant **no player could
  connect at all** -- easily the most severe single gap found in this
  port. Fixed in three parts:
  - `secure/simul_efun/query_ed_mode.lpc` (new): a simul_efun using the
    `in_edit(object)` efun (which IS available in this build) to
    approximate `query_ed_mode()` -- returns `0` while genuinely editing,
    `-1` otherwise. Loses the driver's finer sub-states (the `-2` "more"
    pagination prompt, per-line insert-mode prompts) but preserves the one
    behavior actually load-bearing across the codebase: the `!= -1` gate
    that routes input to the editor instead of normal commands.
  - `global/new_ed.lpc`'s `begin_editing()` rewritten against the real
    `ed(fname, exitfn_string, restricted)` efun. `ed()`'s exit-function
    argument is a plain string (a function *name*), not a closure, so a
    new `__ed_exit_dispatch()` entry point was added as that name, which
    then invokes the actual `function` closure callers already pass
    (preserving every existing caller's API, e.g. `global/line_ed.lpc`'s
    `(: editor_finish_ed :)`). One convenience lost: the original used
    `ed_cmd("$a")` right after starting to drop mortals/empty-file edits
    straight into insert mode; there's no LPC-level way to feed the
    just-started real `ed()` session a synthetic command, so editing now
    always starts at ed's normal command prompt. Low-severity: `ed` is
    documented in `global/line_ed.lpc` as an explicit opt-in advanced
    editor ("Please do not set your editor to ed unless you know what you
    are doing"), not the default player editing experience (that's a
    separate, unaffected pure-LPC "menu"/"command" editor in the same
    file).
  - `global/process_input.lpc`'s `ed_cmd()` call site (the branch that
    forwarded raw input to an in-progress ed session) neutralized to a
    defensive error message -- under the real `ed()` efun the driver
    handles an entire editing session internally (this apply isn't even
    invoked while genuinely editing), so this branch can't actually fire
    in practice, but it still needed to compile.
- **`secure/gods.lpc`/`secure/lords.lpc` missing `query_gods()`/
  `query_lords()`**: `secure/master.lpc`'s `create2()` calls
  `"/secure/gods.lpc"->query_gods() + "/secure/lords.lpc"->query_lords()`
  on every boot to build the `gods` array that `query_lord()`/
  `high_programmer()` (the mud's core admin-permission checks) test
  against -- but neither file ever defined those functions (only an
  unrelated per-name flavour-text lookup, `query_boo()`). This silently
  broke every `query_lord()`/`high_programmer()` check mud-wide (a
  `call_other()` to an undefined function returns 0, not an array, so
  `gods` never gained any entries). The boot banner itself instructs new
  installs to log in as `god`/`god` as the first admin, and the archive's
  shipped `players/g/god.o` already carries `creator 1` and inherits
  `/global/god.lpc` (a real, working god-rank player object) independent
  of this bug, which is why testing as `god` didn't immediately surface
  it -- but `promote`, `update all to <domain>`, and everything else
  gated on `query_lord()` for accounts *other* than the pre-blessed `god`
  were all silently broken. Added `query_gods() { return ({ "god",
  "fluffos" }); }` (this project's admin account, see the README) and
  `query_lords() { return ({ }); }` (no lord names survive anywhere in
  this archive -- the commented-out example in `lords.lpc` is template
  text, not lost content).
- **`secure/master.o`'s saved `preload`/`call_out_preload` arrays used
  literal `.c` paths**: `/global/thane.c`, `/global/patron.c`, `/global/
  god.c`, `/net/intermud3/intermud.c`, `/global/do_chat.c`, `/net/
  who_server.c` -- `convert_lib.sh`'s literal-`.c`-reference fixup only
  scans `.lpc`/`.h` *source*, not `.o` save-file *data*, so these six
  preload entries (saved player/master state, not code) were missed and
  failed to load every boot ("call_other() couldn't find object") --
  caught by `master.lpc`'s own `catch()` around each `preload()` call, so
  non-fatal, but meant the thane/patron/god persona objects, Intermud-3,
  do_chat, and the who-server never actually preloaded. Stripped the
  stray `.c` suffix from all six entries directly in `secure/master.o`.
  A handful of individual shop rooms' own save files (`d/newbie/*/rooms/
  shop.o` and similar, 6 files found via `grep -rl` for a quoted `.c`
  string in `*.o`) have the same class of stale reference in their
  saved-inventory item paths -- much lower-impact (per-room shop stock,
  not the boot-critical preload chain) and left unfixed given the time
  budget; flagged here for anyone doing deeper content testing later.

## 3. Compile-sweep summary

`scripts/lpcc_check.sh` against the full 3273-file tree: started at 0/3273
(master/simul_efun themselves failed to compile -- the `status`-type and
switch-only-default bugs above), reached 2400/3273 (73%) passing after the
fixes above. The remaining ~870 failures break down as:

- **Dead/unreferenced legacy content** (verified via repo-wide `grep` for
  any live reference before excluding, same methodology as `genesis`'s
  \S10): `releasefiles/` (a ~60-file backup snapshot of `secure/`, `d/
  mudlib`, `d/newbie`, `d/heaven`, `w/` duplicating already-live content
  byte-for-byte where diffed, referenced from nowhere live); every `*.old`
  directory and `*/old/*` path (`std/basic.old`, `cmds/creator.old`, `net/
  old`, `std/room/old`, etc.); `std/living/{dankequip,divstuff,baldy}/`
  (three complete, mutually-exclusive alternate equip/skills
  implementations -- the live one is the extensionless `std/living/
  living.lpc`, confirmed via `obj/monster.lpc`'s actual `inherit`, and
  zero files outside these three directories reference any of them);
  `std/adnd/` (an alternate D&D-stats race system, zero live references);
  `net/daemon/` (gopher/www/mail-queue/remote-post internet daemons --
  absent from both `preload` and `call_out_preload` in `master.o`, and
  zero live references outside `net/old/udp/`, itself already dead);
  `room/admin/heaven.nothere/` (a `d/heaven/heaven/`-shaped duplicate,
  the "nothere" name matching its actual status -- zero live references).
- **Template/fragment files, not standalone compilation units** (same
  category `genesis`'s \S10 documented): `std/creator/workroom{,2}.lpc`
  and `std/dom/{master,common,loader}.lpc` are `read_file()`d as raw text
  by `secure/master/create_dom_creator.lpc` and written out per-new-
  wizard/domain with a `#define` prepended -- never compiled at their own
  path (`std/dom/{com,domain_mas}.lpc` are unreferenced older variants of
  the same idea, dead per the point above). 95 files across 17 aggregators
  (`secure/master.lpc`, `secure/simul_efun.lpc`, `global/player.lpc`,
  `net/intermud3/services.lpc`, and others) are `#include`d as text
  fragments into their aggregator and compile fine as part of it but lack
  standalone context in a flat per-file sweep.
- **A repeatable `lpcc`-harness-only artifact, not a real bug**: `obj/
  monster.lpc`'s `set_level()` -> `init_command("init_race")` ->
  `call_out("do_command", 0, ...)` -> `command("init_race")` chain issues
  a delay-0 `call_out` on every single monster's `create()`. A real
  driver's event loop actually executes each pending `call_out` between
  object loads (unwinding the nesting depth); `lpcc --batch` loads
  hundreds of monster objects back-to-back in one continuous process with
  no event-loop yielding, so the nesting depth accumulates *across
  unrelated objects* until it trips the driver's hard 1000-level nesting
  cap ("Nesting call_out(0) level limit exceeded"). Confirmed via the
  per-domain `d/newbie/log/debug.err` this session's \S2 log-directory fix
  made visible for the first time -- every affected NPC shows the
  identical 7-frame trace, and the live driver boot (\S5) shows zero such
  errors across the full registration/play test. This is the same
  documented "lpcc-vs-live-driver artifact" class as \S2's log-directory
  point and `genesis`'s \S10 -- explains the large majority of the
  `d/newbie/*/npcs/*` and `*/monsters/*` "Fail to load object" entries
  with no visible compile error.
- **A handful of genuinely broken string literals**: `d/newbie/half-elf/
  newroomss/{F5,v5}.lpc` and a couple of siblings have literal stray `\`
  characters outside any string ("Illegal character '\\'") -- looks like
  archive-era authoring/transcription corruption in this one small
  subdirectory (~10 files), not something introduced by this port. Left
  as a documented content gap rather than hand-reconstructing each
  string.
- The remainder is ordinary individual room/NPC content bugs (a broken
  `int as[NUM_AS]` array-size declaration in the already-dead `std/adnd/`,
  isolated `Undefined function`s for guild-specific verbs like
  `add_main_skill`/`ChangeAbilityScore` in the dead skills variants, etc.)
  -- logged here as scope, not fixed exhaustively, per this project's
  standing "programming bugs only, not content" rule; deeper content
  testing can revisit `libs/finalrealms/lpcc_fail.log` if desired.

## 4. Boot and play test

Booted `~/src/fluffos/build-debug/src/driver config.fluffos` (memory-capped
per this project's own past-incident precaution) repeatedly; zero compile
errors on every boot after the fixes above, `Initializations complete.` and
accepting connections on 40216 every time.

Verified via a raw Python socket client (this project's established
method), end to end:

- **Existing account** (`god`/`god`, shipped in the archive with `creator
  1` already saved): logs in, lands in `/room/entryroom`, `look`/`score`/
  `quit` all produce correct output, clean save on quit.
- **Brand-new character registration** (name -> confirm -> password ->
  confirm password -> gender -> race selection): a fresh name registers
  all the way through `become human` into the actual game world (the
  "Entry Hall"), `look`/`score`/`inventory`/`quit` all correct. Name
  validation is real and was hit live during testing (max 11 chars, min 3,
  letters only -- no digits).
- **Wizard command access**: `promote <name>` (run as `god`, itself only
  possible after the \S2 `gods.lpc` fix) and `update <path>` (the
  canonical ACL check, exercising both read and compile permission) both
  verified working for the project's admin account.

Zero uncaught runtime errors logged anywhere (`log/errors/*.err`,
`d/{mudlib,vehicle,newbie,heaven}/log/debug.err`) across this whole
session's boots and play-testing.

## WASM status update (2026-08-25, another session)

Promoted `wasm_status` from `""` to `playable`. Hit a genuine, real
(non-test-artifact) bug: `secure/login.lpc`'s `logon()` has a hardcoded
`if(uptime() < 20) { ... refuse connection ... }` startup-grace gate.
This project's own WASM deployment boots a fresh in-browser instance
per visitor, so EVERY real player would hit this on EVERY page load
(not just an admin reconnecting moments after a manual reboot, which
is what the check is actually for) -- per AGENTS.md's standing policy
on legacy connection-time gates, bypassed for loopback:
`query_ip_number(this_object()) != "127.0.0.1" && uptime() < 20`
(current WASM builds correctly report `127.0.0.1`, confirmed via
AGENTS.md's own IP-format section).

Once past that, booted and played clean: login as `god`/`god`, `look`
and `score` both producing correct output matching native testing.
Also found (documented, not fixed -- non-blocking, same class as
`ds386`'s optional network tools): `/net/identd.lpc` (an ident-protocol
lookup daemon) fails to compile on connection due to `socket_error()`/
`socket_address()` being undefined (no `sockets` package on this
driver build) -- caught gracefully, game continues normally, not on
the boot/login/play path. `quit` wasn't recaptured in this WASM
transcript but is already verified clean under native testing above
and untouched by either fix.

## 5. Deep functional test (round two, 2026-08-27)

First full §10.7 round-two pass on this lib (confirmed via grep: no prior
`深度功能测试`/dated round-two heading existed). One continuous session,
English-named test characters per this lib's own naming convention
(`quillfrost`, `brackenfell`, plus throwaway `testerbrave`/`brytewind`
during earlier diagnosis -- all four deleted from `players/` before this
commit, keeping only the seeded `god` account). Booted
`~/src/fluffos/build-debug/src/driver config.fluffos` repeatedly via a raw
Python socket client; killed each instance by exact PID when done.

**Newbie help read first**: `help advance` (skill-training syntax) and
`help fighter` (guild locations/requirements) -- confirmed guild training
(`advance <skill>`) is gated on physically being inside a guild hall, not
available from the open newbie zone, matching the help text's own
"Location: various" framing; not a bug, just meant travel wasn't budgeted
this pass (see "not reached" list at the end).

Six real, confirmed, and fixed bugs, found in this order:

### 5.1 `room/raceroom.lpc`: every new character of every race was funneled into a generic admin/coding-school hub instead of their own race's fully-built starting room, and permanently got zero starting equipment

`do_become()`'s success branch had `startplace = "/room/entryroom.lpc";`
(with the ORIGINAL, correct `me->move("/room/start/"+race);` commented out
immediately above it) followed unconditionally by
`startplace->add_equipment();`. `/room/entryroom.lpc` (an
FR:Illumitech-branded admin/mudlib-coding-instruction hub, exits only to a
meeting-room and post office) never defines `add_equipment()`, so that
call_other silently no-op'd -- and since `entryroom.lpc` has NO exit into
any of the 12 fully-built `d/newbie/<race>/` zones this project's own
onboarding notes describe, EVERY new character was also permanently cut
off from all of that content. `room/start/<race>.lpc` (all 12 races have
one) is a real, still-fully-implemented starting room with its own
`add_equipment()` (or, for drow/duergar, `add_clone()` calls directly in
`setup()`) AND a real exit into that race's own newbie zone -- confirmed
this predates the port (byte-identical in `raw/mudlib/room/raceroom.c`),
not something this project's conversion introduced. **Fix**: restored
`startplace = "/room/start/"+race;` (this project's usual
scope: a hardcoded override + wrong call_other target defeating an
already-fully-implemented feature, not a content/design call -- the
original commented-out line proves the intended behavior). Verified live:
a fresh `human` character now lands in "Human entry room" (a real cottage
room with `leave`/`south`/`west` exits, `leave` reaching
`d/newbie/human/rooms/t05.lpc`) instead of the generic hall, `look`
correctly shows "Torch. Cloak. Dagger." lying on the floor, and `get
all`/`i` correctly picks them up ("Carrying: Dagger. Cloak. Two Torches."
-- the extra torch is leftover from repeat testing in the same shared
room instance, not a bug).

### 5.2 `obj/misc/torch.lpc`: a broken comment (`/` where `/*` was meant) hard-failed this file's compile, silently breaking every race's starting-equipment torch (and any other torch clone) project-wide

Line 43: `/ Will try add_action` (missing the second `*`) -- a genuine
pre-existing archive bug (confirmed present in `raw/mudlib`), not a
porting artifact; it was already a known FAIL in this lib's own
`lpcc_fail.log` from onboarding but wasn't reachable/prioritized then.
This is exactly why 5.1's `add_equipment()` fix alone wasn't enough: even
with routing fixed, `clone_object("/baseobs/misc/torch")` (called from
EVERY race's `add_equipment()`) returned 0, throwing "Bad argument 1 to
EFUN call_other()" the moment it tried `boo->move(this_object())` on the
failed clone. **Fix**: restored the missing `*`. Same missing-star typo
also found and fixed in `obj/misc/book.lpc` (6 sites, an otherwise
unreferenced/dead file, fixed for completeness), `d/heaven/heaven/
meeting.lpc`, and `room/admin/site_control.lpc` (reachable via
`d/heaven/heaven/admin3.lpc`) -- a corpus-wide `grep -n '); / [a-z]'`
sweep found no further live instances. Added as new AGENTS.md §7.146
(a genuinely new bug class, not covered by any existing entry). Verified
live: `update /baseobs/misc/torch` now compiles clean; the full 5.1
equipment flow above is the live end-to-end proof.

### 5.3 `global/player.lpc` `heart_beat()`: an abrupt disconnect crashed with an uncaught runtime error on every single heartbeat tick, forever (or until a delayed self-quit eventually finished) -- AGENTS.md §7.130, new confirmed instance with an added nuance

The old inline idle-kick `else` block had been commented out at some point
in this codebase's history, but the comment's own boundaries left
`last_command = time() - query_idle(this_object());` stranded INSIDE the
`if (!interactive(this_object()))` branch instead of removing/relocating
it -- an interactive-only efun called unconditionally on a path already
known to be non-interactive. Reproduced live via a genuine abrupt TCP
close (no `quit` sent): `log/errors/no_object.err` immediately began
accumulating "*Bad argument 1 to interactive() Expected: object Got: 0."
entries (see 5.3a below for why it's `interactive()`, not `query_idle()`,
in the final fixed version) roughly once per heart_beat tick, indefinitely
-- this project's own scattered leftover test-character disconnects from
earlier in this exact session had already been silently spamming this
error the whole time before it was noticed. **Fix**: guard with
`interactive(this_object())`, matching AGENTS.md §7.130's established
pattern exactly.

**5.3a -- second-order crash the naive §7.130 fix exposed**: guarding with
only `interactive(this_object())` was not sufficient here. This lib's
`quit()` calls `really_quit()` SYNCHRONOUSLY (immediate `dest_me()`) for a
non-fighting player, so the vulnerable line can be reached in the SAME
heart_beat() tick as the object's own destruction -- and `this_object()`
reads back as literal `int 0` once already destructed, so `interactive(0)`
itself THROWS rather than returning false, reproducing an equivalent
crash one line downstream. **Fix**: added an `objectp()` guard ahead of
`interactive()`. Verified live: a fresh abrupt-disconnect repro, left
running across a 20+ second wait (multiple heartbeat ticks), produced
zero further errors, and the netdead body was confirmed reaped (`who`
correctly shows only currently-connected players, the disconnected body
no longer lingers). Extended AGENTS.md §7.130 with this nuance.

### 5.4 `baseobs/monsters/healer.lpc` / ~20 race raiserooms: the entire death/resurrection ("raise") mechanic was silently broken for every race except the one using this NPC base's own default name -- new AGENTS.md §7.144

`healer.lpc`'s `setup()` unconditionally self-named via `set_name("james")`
at clone time; `/obj/monster.lpc`'s `set_name()` is a one-shot setter
(no-ops once `name` is already non-default). ~20 per-race raiseroom files
clone this SAME base object once as a persistent "nurse" NPC and then try
`helper->set_name(<real name>)` in their own `reset()` (e.g.
`d/newbie/human/rooms/v05.lpc` renames it to "june") -- every such rename
was a complete no-op, so `find_match(nurs, this_object())`/`find_living()`
lookups keyed on the intended name permanently failed, even though the
NPC was visibly present under that display name (`set_short()` isn't
gated the same way). Root-caused live via `debug_message()` tracing
(`log_file()` would have needed elevated euid this room's object doesn't
have -- see AGENTS.md §7.129's own note on this exact gotcha). Confirmed
via grep: 20 raiserooms across the whole newbie-zone corpus clone
`baseobs/monsters/healer.lpc`; at least 12 rename it to something other
than "james" (`d/newbie/newliz/rooms/raiserm.lpc`, `newelf/rooms/
raiseroom.lpc`, `newken/rooms/raiseroom.lpc`, `elf/rooms/raiseroom.lpc`,
`human/rooms/v05.lpc`, `half-elf/rooms/castle/d1.lpc`, `dwarf/{newrooms/
raiserm28,rooms/raiserm25}.lpc`, `new_halfelf/rooms/h1.lpc`, `guests/
rooms/raiseroom.lpc`, `lizard/rooms/raiserm.lpc`, `halfling/rooms/
raiseroom.lpc`) and were all affected. **Fix**: removed the self-naming
`set_name("james")` call from `healer.lpc`'s own `setup()`; the one caller
that relies on the "james" default without ever renaming it
(`std/raiseroom.lpc`'s `do_raise()`, which clones a disposable, never-
looked-up-by-name temporary priest) now explicitly calls
`priest->set_name("james")` itself. Verified live end-to-end on the human
zone: a test character (`quillfrost`) was killed by the "june" NPC, walked
(as a ghost) to the raiseroom, and `raise me` now correctly runs the full
sequence -- "The healer raises his hands...", "You reappear in a more
solid form.", "Saving...", the full nurse/priest dialogue -- and a
subsequent `score` shows the character alive again with real HP. Before
the fix, `raise me` produced zero output and left the character
permanently dead.

### 5.5 Five race-zone shops: `buy`/`sell` were completely dead (silent no-ops) because a broken "is the shopkeeper here" pre-check was wired as a direct verb override instead of through the base class's own dedicated hook -- new AGENTS.md §7.145

`std/shop.lpc` (the shared shop base) exposes `set_open_condition(mixed)`
specifically so a subclass can gate `buy()`/`sell()`/`list()`/`value()`/
`browse()` (all of which check it internally via `test_open()`) on a
custom precondition. `d/newbie/human/rooms/v02.lpc` (and 4 siblings:
`newelf/rooms/shop.lpc`, `newliz/rooms/shop.lpc`, `newken/rooms/
shop.lpc`, `halfling/rooms/shop.lpc`) each wrote a `do_check()` matching
that exact 0/1 contract, with the correct `set_open_condition("do_check")`
call sitting right there in `setup()` -- but COMMENTED OUT, replaced with
`add_action("do_check","buy"); add_action("do_check","sell");` in
`init()`. Since a subclass's own `init()` registrations are tried before
an inherited base class's same-verb registration, `do_check()` always won
and, since it `return(1)`s unconditionally whenever the shopkeeper is
merely present, completely swallowed every `buy`/`sell` (silent success,
nothing exchanged) -- `std/shop.lpc`'s real `buy()`/`sell()` never ran at
all. `d/newbie/half-elf/rooms/town/b3.lpc` has the identical broken shape
but already fully commented out (dead, unreachable) -- left untouched.
Root-caused live via `debug_message()` tracing after noticing `list`
worked (not registered via the broken `do_check` at all) while `buy`/
`sell`/`value` all produced zero output. **Fix**: deleted the shadowing
`add_action` pair, restored the commented-out `set_open_condition
("do_check")` call, in all 5 live-affected files.

**5.5a -- second, independent bug this one was hiding behind**:
`newelf/rooms/shop.lpc`'s `do_check()` checked `present("Old woman")`, but
this room's actual shopkeeper NPC (`chars/geldon.lpc`) is named "geldon"
-- a copy-paste leftover from the generic "Old woman" shop template used
elsewhere. Fixed the string to match. `newliz/rooms/shop.lpc` and
`newken/rooms/shop.lpc` clone/reference a shopkeeper NPC that doesn't
actually exist in this archive at all (`d/newbie/newliz/npcs/woman.lpc`
is missing; `newken/rooms/shop.lpc` never clones anyone) -- a genuine,
pre-existing missing-NPC CONTENT gap, left untouched per this project's
scope (documented with a code comment at each site); both shops will now
correctly and honestly report "shopkeeper not present" instead of
silently doing nothing, which is the right outcome for a real content
gap.

**5.5b -- a second, ALSO independent case-sensitivity bug, found only
after 5.5's fix made it newly visible**: `v02.lpc`'s (and the other
"Old woman" shops') `present("Old woman")` used the NPC's capitalized
DISPLAY name (`set_short()`), not its actual lowercase `id()`/`name`
(`set_name("old woman")`) -- `id()` on this driver
(`std/basic/id.lpc`) is a plain case-sensitive `==` compare, so even after
5.5's dispatch fix, EVERY shop command (including `list`/`value`/`browse`,
which don't go through `do_check` directly but do share the `test_open()`
gate) reported "shop closed" until this string was lowercased to match.
Fixed in `v02.lpc` and `halfling/rooms/shop.lpc` (the two live shops using
the real "old woman" NPC). Verified live, full end-to-end transaction on
`d/newbie/human/rooms/v02.lpc` (admin-granted test funds via `call
adjust_money(50,"silver") @brackenfell`): `list` shows real stock,
`buy torch` -> "You buy a Torch for 7 copper coins." with correct
inventory/purse updates, `value torch` -> "The Torch is valued at 5 copper
coins.", `sell torch` -> "You sell a Torch for 5 copper coins." with
correct purse update. Before either fix: all four silently did nothing.

### Observed, NOT fixed -- native `add_action`-registered command failures are silently swallowed somewhere in this lib's custom command-queue dispatch, distinct from and not fully root-caused

While diagnosing 5.4/5.5, repeatedly observed that when a command
registered via a NATIVE `add_action()` call (not a `cmds/`-directory file
dispatched through `CMD_HANDLER`) fails its own internal check and calls
`notify_fail("...")` before `return 0` (e.g. `raise bob` with no such
target, `value`/`sell` for an item not carried), NEITHER that
`notify_fail()` message NOR the driver's generic default fail message
displays at all -- total silence, no crash, nothing in any error log.
Meanwhile `notify_fail()`-based failures on `cmds/`-directory commands
(`cmds/player/kill.lpc`'s "Alas, your etherealness has little effect..."
when dead) display correctly. Traced as far as confirming
`std/living/action_queue.lpc`'s custom per-tick dispatcher (`command(
curr_act)`, called from `aq_add()`/`action_check()` rather than the
driver's own top-level `process_user_command()`) is the architecture
involved, and that this driver's own C source (`parse_command()` /
`user_parser()` / `notify_no_command()`) SHOULD still display either
message given how `command_giver` is threaded through `save_command_giver()`/
`restore_command_giver()` around the raw `command()` efun -- but could not
pin down why it empirically doesn't, within this pass's time budget.
**Does not block real functionality**: every SUCCESS path through this
same native-`add_action` mechanism (5.4/5.5's fixes, `kill`'s actual
attack) displays its own output correctly; this is specifically about
missing FEEDBACK TEXT on certain failure paths, not a functional
blocker. Documented here rather than guessed at or "fixed" blind, per
this project's own standing policy -- flagged for whoever next does a
deep dive on this lib (or a driver-level `command()`/`command_giver`
investigation) to pick up.

### Standing cross-cutting patterns checked systematically (grep + targeted live tests)

- **§7.121** (float arithmetic in a declared-`int` economy function): the
  entire money system (`obj/handlers/money_handler.lpc`,
  `std/shop.lpc`'s `scaled_value()`/`PAY_RATES`) is pure integer
  arithmetic throughout -- confirmed clean, no float anywhere in the
  currency path.
- **§8.3a** (`private` command-dispatch/callback function silently
  demoted once inherited): a script cross-referencing every
  `add_action("fn", "verb")` target against a `private`-declared
  function of the same name in the same file found zero matches --
  confirmed clean (this codebase doesn't use a single central
  `private nomask command_hook` idiom at all).
- **§7.112** (NPC `init()` unconditionally scheduling a `call_out()`
  chain with no re-entry guard): found 18 files with `init()`+`call_out`,
  all are simple one-shot "greeting" messages (a duplicate on reconnect
  would at most double-print a greeting line), none matches the
  death/reincarnation multi-stage state-corruption shape this pattern
  is about -- confirmed not applicable here (this lib's own death flow
  uses a completely different, NPC-command-driven `raise`/`do_raising()`
  mechanism, see 5.4).
- **§7.118** (`.c`->`.lpc` filename-slice arithmetic): grepped for both
  the hardcoded-offset-slice shape and the `+".c"` literal-concatenation
  variant -- zero hits, confirmed clean.
- **§7.122** (autoload/class-item duplication on reconnect): grepped for
  `query_auto_load`/`auto_load`/`compute_autoload_array`-style
  mechanisms -- none exist in this archive at all (no TMI-2/Nightmare-
  style reload-on-login system); confirmed not applicable.
- **§7.123** (bare file-scope `IDENT = (...)` statement): grepped for
  the shape corpus-wide -- zero real instances (the one syntactic match,
  `net/intermud3/cmds/tell.lpc`'s `morse()`, is a normal local-variable
  assignment inside a function, not file scope).
- **§7.126** (stale pre-`.c`-to-`.lpc` extension in `.o` save data):
  this project's own onboarding NOTES.md (§2) already flagged this
  exact gap in a handful of individual shop `.o` save files as a
  known, deliberately-deferred, low-impact item -- re-confirmed still
  present and still low-impact (per-room shop inventory, not the boot
  path); not re-investigated further this pass, no new instances found
  beyond what onboarding already documented.
- **§7.129** (`tell_room()` wrapper forwarding omitted `exclude` as
  literal `0`): `secure/simul_efun/modified_efuns.lpc`'s `tell_room()`
  uses `event()` (a `call_other`-based dispatcher), not the strict
  `message()` efun -- confirmed a structurally different, safe
  mechanism; `event_say()`'s own `pointerp(avoid)`/`avoid ==
  this_object()` guard already handles a bare `0` correctly.
- **§7.130**: confirmed instance, see 5.3/5.3a above.
- **§7.131** (`find_living()`/`find_player()` needing `set_living_name()`
  registration): confirmed ALREADY correctly called, twice
  (`global/player.lpc`'s `start_player()` and `set_name()`) --
  not the bug shape here (though a structurally adjacent bug, §7.144,
  was found and is new).
- **§7.132** (`map()`-over-mapping wrong-argument binding): grepped for
  the shape -- zero hits, this codebase doesn't appear to use `map()`
  over mappings in a way that would trigger this.
- **§7.133** (classic-driver `remove_interactive()` never bridged to
  this driver's real `net_dead()` apply): this lib's disconnect handling
  is inline in `heart_beat()` (the §7.130 shape, not a separate
  `net_dead()`/`remove_interactive()` split) -- confirmed not
  applicable, no dead `remove_interactive()` doc-comment/mechanism
  found anywhere.
- **§7.134/§7.135** (lazy-init/empty-accumulator guard missing):
  confirmed instance, see the new AGENTS.md §7.134 addendum
  (`obj/handlers/align_tracker.lpc`).
- **§7.136** (command-soul stripping with no re-grant path): not
  applicable -- this codebase's command architecture (native
  `add_action` everywhere, `soul_commands()` etc. called unconditionally
  from `start_player()`) doesn't use a race-content-gated soul-granting
  design at all.
- **§7.141** (MudOS-era `replace_program()` fold crashing on a pending-
  replace closure creation): FOUND a live instance of the fold itself
  (`std/room.lpc`'s `create()`, identical `replaceable()`+
  `inherit_list()`+`sizeof==1` shape) -- but traced its ENTIRE class
  hierarchy (`std/basic/{light,property,cute_look,desc}.lpc`,
  `std/senses.lpc`, `std/add_clone.lpc`) and found zero closure/function-
  pointer creation anywhere in it, unlike the `dsI` precedent's
  `eventHearTalk()` filter closure. Live-tested directly: `say`/`ask` in
  a genuinely trivial (`inherit "/std/room"` only) room within the first
  ~160 seconds of a fresh boot (squarely inside the vulnerable window)
  produced zero "pending replace_program()" errors. Left the fold in
  place -- confirmed-clean, not a live bug in this codebase, per this
  project's "verify empirically before fixing a pattern-matched bug"
  policy; documented here rather than removed speculatively.
- **§7.143** (`force_me()`+`add_action` NPC self-dispatch failing for
  room-`reset()`-spawned NPCs): `force_me()` is never called anywhere in
  this entire archive -- confirmed not applicable, the mechanism this
  pattern depends on doesn't exist here.

### Combat, quit/reconnect, shop -- what was and wasn't reached live

- **Combat**: no dedicated safe-sparring mechanism exists in this
  archive (no "dummy"/"practice" NPC found anywhere) -- used a genuinely
  weak wild newbie-zone monster instead (`d/newbie/human/monsters/
  cat.lpc`, level 3-6, `set_wimpy(10)`) per the methodology's documented
  fallback. A level-0 character (1 max HP) died to it almost
  immediately -- confirmed this is intended difficulty (help text
  explicitly frames level 0 as needing guild training before real
  combat), not a bug. A second combat test (`kill june`, an NPC with
  real HP) played out a full multi-round fight to death and back through
  a full resurrection (5.4).
- **Skill/guild training**: `advance <skill>` confirmed gated on
  physical guild-hall presence (matches `help advance`/`help fighter`);
  not reached live this pass (would require travel this session's time
  budget didn't cover) -- documented here as explicitly unverified-live
  rather than silently skipped.
- **Quit / debug.log / reconnect**: this lib has no `debug.log` at all
  (its own error handler, `secure/master/error_handler.lpc`, routes
  everything to `log/errors/<domain>.err` instead -- the `debug.log`
  write path is explicitly commented out there); checked `log/errors/*`
  after every `quit` throughout this pass, not just once. `quit` while
  dead (a ghost, mid-testing) was confirmed to correctly persist across
  a real reconnect after a wall-clock gap -- reconnecting showed the
  same disembodied-spirit state rather than silently reviving or
  corrupting the character.
- **Shop/economy**: fully reached and live-tested end-to-end, see 5.5.
- **Death/respawn**: fully reached and live-tested end-to-end, see 5.4.

Six files' fixes verified via targeted `lpcc` single-file/room compiles
plus full native driver boots (repeated ~13 times across this session,
each killed by exact PID); zero compile regressions, zero new runtime
errors in `log/errors/*` across the final clean boot's full test replay.
Throwaway test characters (`testerbrave`, `brytewind`, `quillfrost`,
`brackenfell`) deleted from `players/` before commit; only the seeded
`god` account's own incidental save-state drift (last-login timestamp,
playtime) and normal daemon/shop aggregate-stat drift (`save/
timekeeper.o`, `d/newbie/human/rooms/v02.o`'s sales counters, a
freshly-created `save/death.o` from this session's first-ever kills)
were left as ordinary collateral of live testing, matching this
project's usual convention.
