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
