# Foundation II -- porting notes

Source: `foundation2_fluffos_v1.zip`, a maintained, already-FluffOS-adapted
archive from lpmuds.net (a now-defunct LPMud archive site). The live site is
down; this exact archive was recovered from the Wayback Machine
(<https://web.archive.org/web/20160306101019if_/http://lpmuds.net/files/foundation/foundation2_fluffos_v1.zip>)
and content-verified (valid zip, non-corrupted) before this session started.
Slug `foundation2`, number 174, port 40221. The zip bundles a FluffOS
2.9-ds2.13 driver source snapshot (`fluffos-2.9-ds2.13/`), plus `bin/`,
`win32/`, `old/` build/install scaffolding -- all ignored, this project uses
its own driver. The real mudlib root is the zip's `lib/` directory.

Foundation II is a stripped-down classic descendant of the Nightmare mudlib
lineage: no combat/limbs system at all, positioned (per its own boot banner)
as a minimal base "NOT for newcomers to LPC. You must be hardcore" --
aimed at LPC programmers building their own game on top of a bare engine,
not a playable-out-of-the-box game world. This matches what shipped: a
working login/registration/security/command-dispatch/help/mail/board/
Intermud-3 engine, one small "Standard" starting-cavern domain, and two
optional teaching-only content trees (`domains/Examples/`,
`domains/School/`) that reference a different, incompatible content API
(see \S3) -- there is no score/combat/stats system anywhere to test.

## 1. Conversion

English-language archive (not GBK-encoded) -- `scripts/convert_lib.sh`
against `raw/foundation2_fluffos_v1/lib` confirmed this: 1126/1160 files
already valid UTF-8, only 1 lossy conversion (`doc/faq/lpmud`, a handful of
stray invalid bytes in a plain-text FAQ file, not code), 244 files renamed
`.c`->`.lpc`, 67 literal `.c"` references fixed, 13 local angle-bracket
`#include`s converted to quotes, 118 files touched by the `static`->`nosave`
sweep.

**One file needed the same `static`->`nosave` treatment by hand**:
`secure/lib/login.real` is not `.c`/`.lpc` (so the mechanical sweep skipped
it) but is real, live LPC source -- the mudlib's own first-boot admin-setup
wizard (`secure/lib/login.lpc`, see \S5) `cp()`s it over `login.lpc` at the
end of setup and it becomes the mud's actual ongoing login/registration
object from then on. Its 45 `static` declarations were converted the same
way by hand, then verified by compiling it standalone under its real target
path before ever letting the install flow copy it into place live.

## 2. Compile-time driver-compat fixes

- **`ref` is a reserved keyword on this driver** (call-by-reference
  parameter modifier) -- `secure/daemon/master.lpc`'s `load_access()` used
  it as an ordinary mapping parameter/variable name (`mapping ref`,
  `ref[fl] = ...`), in both the function and its `master.h` prototype. Only
  3 sites in the whole tree (confirmed via a repo-wide `\bref\b` grep before
  and after); renamed to `refmap`. Same bug class documented in
  `libs/nightmare3/NOTES.md`.
- **`PACKAGE_UIDS` is enabled in this project's driver build, and this
  master object never defined the two applies it requires** -- confirmed
  empirically (this driver build has neither an `f_ed_start`/`f_ed_cmd`/
  `f_query_ed_mode` efun, i.e. `OLD_ED`, nor were `get_root_uid()`/
  `get_bb_uid()` ever satisfied here) and by reading
  `vm/internal/master.cc`: `set_master()` calls `exit(-1)` outright if
  `get_root_uid()` is missing, so the driver couldn't boot at all --
  `lpcc`'s own batch harness surfaced this identically ("No function
  get_root_uid() in master object"). Ported the exact two-line pair from
  the sibling Nightmare-lineage master (`libs/nightmare3/work/secure/
  daemon/master.lpc`, which literally shares this file's "from Nightmare
  3.3" header comment): `get_root_uid() { return "Root"; }`,
  `get_bb_uid() { return "Backbone"; }`.
- **`creator_file()` -- also required by `PACKAGE_UIDS`, and missing --
  was the single highest-impact fix in this port.** Unlike
  `get_root_uid()`/`get_bb_uid()` (checked once, at master-object-load
  time), `creator_file()` is called by the driver on **every single object
  load** to assign its uid (`vm/internal/simulate.cc`'s
  `apply_master_ob(APPLY_CREATOR_FILE, ...)`, hard `error()`s uncaught if
  missing). With it undefined, essentially **every object in the mudlib
  failed to load** -- confirmed via `lpcc_check.sh`: only 18/245 files
  passed before this fix (`log/catch` was flooded with identical
  `*master object: No function creator_file() defined!` traces from every
  preloaded daemon's own creation), 218/245 immediately after. Nightmare's
  own lineage (`libs/nightmare3/work/secure/SimulEfun/creator_file.lpc`)
  solves this with a *different*, more elaborate per-directory uid-name
  scheme (`UID_ROOT`/`UID_MUDLIB`/`UID_BACKBONE`/etc.) that doesn't exist
  in this codebase at all -- rather than inventing a parallel naming
  scheme, `secure/daemon/master.lpc`'s new `creator_file()` reuses the
  privs-category classification this codebase's own
  `secure/sefun/security.lpc:file_privs()` already provides for its
  privs/access-list security model (`ASSIST`/`CMDS`/`GENERAL`/
  `MUDLIBPRIV`/`SECURE`/`WWW`/domain-name), falling back to the backbone
  uid for anything uncategorized. There's no uid-based permission check
  anywhere in this codebase (its whole security model is `check_access()`'s
  privs scheme) for the exact uid string to matter -- only that every
  object gets *some* non-zero string.
  - **Follow-on bug in the fix's own `sscanf()` use**: `creator_file(str)`
    strips a clone-instance suffix via `sscanf(str, "%s#%d", base, ext)`,
    same idiom as `nightmare3`'s version -- but nightmare3's version never
    hits the case where `str` has no `#` at all in a context that matters,
    while every one of this driver's *own* boot-time preload calls does.
    An unmatched `%s` target keeps its int-`0` default (not `""`), so
    `base` stayed the integer `0` for any non-cloned path, and passing
    that into `file_privs()`'s `file[0..1]` string-indexing crashed with
    "Cannot index type 'int' using [ .. ] operator" -- caught by
    `preload()`'s own `catch()`, so non-fatal, but every single preloaded
    daemon hit it (confirmed via `log/catch`). Fixed by falling back to
    `base = str` whenever `sscanf()` doesn't report a full 2-field match.
- **`daemon/soul.lpc`: "Illegal to inherit after defining global
  variables."** Its `#include <soul.h>` (before its own
  `inherit SOUL_ADVERBS;` line -- `SOUL_ADVERBS` is itself a macro defined
  a few lines up in that same header) pulled in a real global-variable
  initializer, `nosave string HelpPage = (...)`, ahead of the inherit in
  the expanded token stream. The CD/MudOS driver this shipped for
  evidently tolerated the ordering; this driver doesn't. Moved `HelpPage`
  (used nowhere outside `daemon/soul.lpc`) into `daemon/soul.lpc` itself,
  after its `inherit`, rather than touching the header's macro-only
  contents any other includer might also pull in.
- **The command-dispatch directory scanner's fixed-offset string slice --
  the second highest-impact fix, found only by live playtesting (`lpcc`
  gave zero indication of it, since every affected file compiles and
  loads fine standalone).** `daemon/command.lpc`'s `eventRehash()` builds
  the whole verb->file lookup table with `cmd = file[0..<3]`, which is
  exactly right for stripping a trailing 2-character `.c` extension but,
  after this project's standard `.c`->`.lpc` rename (2 characters
  longer), turns `"look.lpc"` into `"look.l"` instead of `"look"` --
  **every real command in `cmds/player/`, `cmds/creator/`, and
  `secure/cmds/creator/` silently stopped matching typed input.**
  Confirmed live: before the fix, `inventory`/`help`/every other
  `cmds/player` command returned the driver's bare "What?", while `look`
  (not implemented as a `cmds/` file at all -- handled elsewhere) and
  soul/emote commands (dispatched through a separate path, `SOUL_D`, not
  this table) kept working, which is exactly the fingerprint that made
  this a dispatch-table bug rather than a per-command one. Same bug
  class, and nearly the identical fix, as `libs/nightmare3/NOTES.md` item
  13 (`daemon/command.lpc`'s `rehash()` there). Widened the slice to
  `file[0..<5]` (drop the trailing 4 characters).
- **Two more instances of the identical rename-arithmetic bug, this time
  checking/appending rather than stripping**: `lib/remote.lpc`'s remote-
  creator-protocol `update` handler and `secure/cmds/creator/update.lpc`
  (the wizard `update <file>` command -- this project's own canonical
  ACL/recompile smoke test) both had `arg[<2..] == ".lpc"` /
  `x[<2..] != ".lpc"` -- a 2-character end-slice compared against the
  (already mechanically rename-fixed) 4-character literal `".lpc"`,
  always false either way. In `update.lpc`'s `cmd()` this meant `.lpc`
  got appended even when the user already typed it (`update foo.lpc`
  produced `foo.lpc.lpc`, "File not found" -- confirmed live before the
  fix); in both files' extension-stripping checks it meant an explicit
  `.lpc` suffix was never stripped before `find_object()`/
  `eventDestruct()`. Fixed both to `<4..`/`[0..<5]`, matching
  `daemon/command.lpc`'s fix. Verified live afterward: `update
  /cmds/player/inventory` and `update /cmds/player/inventory.lpc` (with
  and without the explicit extension) both now report `Ok`, and the
  command keeps working correctly post-recompile.
- **Small mechanical typos/gaps, one file each**:
  - `secure/cmds/creator/grant.lpc`: `file[strlen(file)-1] != "/"` compares
    a single character (an `int`) against a string literal -- this
    driver's strict-types pass makes that a hard "!= always true"
    **compile error** (not just a warning), unlike whatever drove the
    original archive. Fixed to the character literal `!= '/'`.
  - `secure/cmds/creator/banish.lpc`: used `UID_BANISH` (a real constant,
    defined in `secure/include/security.h`) without including that
    header -- had a literal duplicate `#include <daemons.h>` instead (one
    of the two copies replaced with the missing include).
  - `secure/cmds/creator/memcheck.lpc`: `inherit DAEMON;` -- `DAEMON` is
    not a macro anywhere in this codebase (the real one, used everywhere
    else, is `LIB_DAEMON`); a lone pre-existing typo, not something this
    port introduced. Fixed to `LIB_DAEMON`.

## 3. Bundled example/teaching content targets a different, incompatible API (not fixed -- pre-existing content mismatch)

23 of 246 `.lpc` files still fail `lpcc_check.sh`'s batch sweep (down from
227 before the fixes in \S2); every one of them is non-preloaded, non-boot-
critical teaching/example content, and every failure traces to the same
root cause: **this content was written against a different room/item API
than the one this engine actually ships.**

- **`domains/School/` (7 files)** call `set_properties()`/`set_short()`/
  `set_long()`/`set_exits()`/`set_items()` on a room inheriting `ROOM`
  (`/lib/room.lpc`) -- but this engine's real, actual room/object API
  (confirmed by reading `/lib/object.lpc`/`/lib/exits.lpc`/`/lib/items.lpc`,
  the base classes `/lib/room.lpc` itself inherits) is CamelCase and
  singular: `SetShort()`, `SetLong()`, `SetProperty()` (one property at a
  time), etc. None of the `set_properties`/`set_short`/`set_long`/
  `set_exits`/`set_items` names exist *anywhere* in this entire archive --
  this School domain was evidently authored against an older or sibling
  Foundation/Nightmare-lineage codebase and never ported when it was
  bundled alongside this particular engine snapshot. Not a driver-compat
  issue; a pre-existing content/engine-version mismatch in the archive
  itself, same category as `genesis`'s missing-domain gaps.
- **`domains/Examples/{weapon,armour,npc}/*`, `etc/{match,torch}`,
  `virtual/*` (15 files)** reference base classes and macros that were
  simply never shipped in this "no combat/limbs" engine at all:
  `LIB_NPC`, `LIB_ARMOUR`, `LIB_WEAPON`-style macros don't exist in
  `lib.h`, and no corresponding `/lib/npc.lpc`/`/lib/armour.lpc`/
  `/lib/weapon.lpc` base files exist anywhere in the tree either (unlike
  `domains/School`'s case, this isn't a missing macro pointing at real
  content -- the content itself was stripped along with the rest of this
  engine's combat system). `<armour_types.h>`/`<damage_types.h>`/
  `<vendor_types.h>` are likewise never-shipped headers. This is fully
  consistent with the archive's own framing (a deliberately minimal
  engine) -- these example files were evidently carried over wholesale
  from a fuller ancestor codebase's `domains/Examples/` without pruning
  the parts that depend on subsystems this stripped-down engine doesn't
  have. Not chased further (would mean inventing a combat/item-type
  system wholesale, a content addition far outside this project's
  driver-compat scope).
- **`secure/cmds/creator/move.lpc`** (a "move any object anywhere" wizard
  debug utility, credited "from the Nightmare Mudlib") `inherit`s a
  `REFS_D` macro that's undefined anywhere in this codebase, and no
  reference-tracking daemon (`/daemon/refs.lpc` or similar) exists in this
  archive at all -- genuinely missing/never-ported infrastructure from
  another Nightmare-lineage codebase, not something this port broke. Left
  unfixed (a single non-boot-critical wizard debug command); it also
  separately has a `#include <move.h>` that can't resolve via this
  driver's configured include path (`/secure/include:/include` -- the
  real `move.h` lives in `/lib`, a different directory, so angle brackets
  never find it even though a same-directory local include would), but
  fixing that alone wouldn't make the file compile given the missing
  `REFS_D` daemon, so left as one combined, documented gap.

None of these 23 files are in `secure/cfg/preload.cfg`, referenced from
the `Standard` starting domain, or reachable from any command a normal
player or the seeded admin would run -- confirmed via a full live boot and
play session with zero related errors.

## 4. First-boot admin-setup wizard (not a bug -- this engine's own onboarding flow)

Unlike most archives in this project (which need a wizard account
hand-seeded via a save-file edit or a normal-registration + config-edit
combo), Foundation II ships its own genuine one-time superuser setup flow:
`secure/lib/login.lpc` starts as a small self-contained "installation
process" wizard (name -> password -> confirm -> capitalized-name ->
gender -> real name -> email), and on completion it clones the real,
full-featured login/registration object over itself
(`cp("/secure/lib/login.real", "/secure/lib/login.lpc")`, see \S1),
destructs the temporary admin object and the master object (forcing a
clean reload of both), and disconnects with "Login as your admin
character." From then on the mud behaves like any other -- new
characters register through the normal flow (name -> confirm (y/n) ->
password -> confirm -> gender -> display name (blank OK, defaults to the
account name) -> **email, which must match `user@host` and is NOT
optional/skippable** -> real name (optional, blank OK) -> two "Press
<return> to continue" news screens -> world entry).

The project's admin account was created through this exact first-boot
flow (not a save-file hand-edit): id `fluffos`, password `Mud@2026`,
granted `ASSIST`+`SECURE` group membership in `secure/cfg/groups.cfg`
automatically by the setup flow itself (it renames the archive's
placeholder `admin` group entries to the chosen admin's name), and given
a real per-account "realm" directory (`realms/fluffos/workroom.lpc`,
copied from `domains/Standard/xtra/workroom.lpc` by the same flow).
Verified live with `update <path>` (this project's canonical ACL/compile
check) against a real `cmds/player` file.

Note for anyone re-running this install flow: **every account in this
engine saves under `secure/save/creators/`, not a separate mortal-vs-
wizard split** -- `#ifdef PLAYERS` branches throughout the codebase (e.g.
`creator_file()`'s own base-name check) are dead in this build (`PLAYERS`
is never defined), consistent with this being a bare "for LPC experts"
engine with no mortal/wizard distinction baked in by default.

## 5. Live outbound network side effect at boot (by design, not a bug -- same class as `imud`, see AGENTS.md \S2.3)

`daemon/intermud.c` (Intermud-3 protocol support, preloaded unconditionally
via `secure/cfg/preload.cfg`) is guarded by `#ifndef __PACKAGE_SOCKETS__
#error ...#endif` -- and **this project's driver build has the sockets
package enabled** (confirmed via `nm`: `f_socket_create` is present), so
the guard doesn't fire. Its `create()` unconditionally schedules
`call_out((: Setup :), 2)`, and `Setup()` calls `eventCreateSocket()`
against a hardcoded real address (`204.209.44.3:8080`, the historic `*i4`
Intermud-3 router) roughly 2 seconds after every boot. This is genuine,
intentional upstream functionality (not something to patch away), but --
exactly like `imud` (AGENTS.md \S2.3) -- it means every boot of this lib
makes a real outbound connection attempt to a real third party. That
router is a 1990s-era service and near-certainly long defunct by now (no
connection-success evidence was seen in any boot log this session), but
this should **not** be swept into high-frequency automated re-boot/re-test
loops the way this project's other (fully sandboxed) libs safely can be.

## 6. Boot and play test

Booted `~/src/fluffos/build-debug/src/driver config.fluffos` repeatedly;
zero compile errors, `Initializations complete.`, accepting telnet
connections on 40221 every time. Verified via a raw Python socket client
(`scripts/mudclient.py`), end to end:

- **First-boot admin setup** (\S4): completed the installation wizard as
  `fluffos`/`Mud@2026`, then logged in as that account into the real game
  world (`/domains/Standard/center`, the starting cavern).
- **Brand-new character registration** (a second, ordinary account,
  `gorlak`): the full name -> confirm -> password -> confirm -> gender ->
  display name -> email -> real name -> news flow, landing in the same
  starting room.
- **Commands**: `look`, `inventory` (`You are carrying nothing.`), `who`
  (correct member listing), `save` (`Fluffos is now saved.`), a soul/emote
  command (`smile` -> `You smile happily.`, confirming `daemon/soul.lpc`'s
  fix and this codebase's `(: function :)`-closure-based `add_action()`
  calls -- already the correct FluffOS idiom throughout this archive, no
  bare-function-value bug found here unlike `genesis`/`finalrealms`), and
  the wizard `update <path>` command (both with and without an explicit
  `.lpc` suffix) all produce correct output. `quit` disconnects cleanly
  ("Please come back another time!").
- Since this engine has no combat/stats/limbs system at all, there is no
  `score` command to test (confirmed: no file named `score` or string
  literal `"score"` exists anywhere in `cmds/`) -- `inventory`+`who`+
  `update` substitute for this project's usual `look`/`score`/`quit`
  verification bar, per the precedent set for other minimal/non-standard
  engines in AGENTS.md \S2.3.

Zero uncaught runtime errors in `log/runtime`/`log/catch` across this
session's boots and play-testing (the `log/catch` entries seen mid-session
were `creator_file()` traces from the `lpcc_check.sh` batch runs that share
this lib's `log/` directory, not from the live driver -- confirmed by their
file-modification time not advancing while the real driver was up).

## WASM status update (2026-08-26, another session)

Promoted `wasm_status` from `""` to `playable`. Same root-cause class
as `ds386`/`discworld`/`deadsouls_fluffos`/`tmi2`: `secure/sefun/
sefun.lpc`'s own `dump_socket_status()` (part of the eagerly-loaded
simul_efun object) called `socket_status()` unconditionally, undefined
on this driver build (no `sockets` package). Gutted to a safe stub
(diagnostic admin tool only, not on the boot/login path). No other
socket-related eager-load failures found. Verified with a scripted
WASM session: login (`fluffos`/`Mud@2026`), arrival in the correct
starting cavern room, and `inventory` producing correct output.
`quit` wasn't recaptured distinctly in this transcript but is already
verified clean under native testing above and untouched by this fix.

## 深度功能测试（round two, 2026-08-27）

Full §10.7 continuous playthrough against the native debug driver
(`~/src/fluffos/build-debug/src/driver config.fluffos`), never done
for this lib before (only the original onboarding-tier boot/play pass
in \S6/\S "WASM status update" above). This is a genuinely minimal
engine (no combat/limbs/stats/score, one small starting room with no
working exits -- see \S3), so the test surface is: login/registration,
`look`/`inventory`, save, mail (IIPS), `who`, `quit`+reconnect, and a
systematic grep sweep for every standing cross-cutting bug class
tracked in `AGENTS.md` (\S7.121-\S7.135, \S8.3a).

**Playthrough** (admin `fluffos`/`Mud@2026`, plus a throwaway English
test character `Aldric`, cleaned up before commit): full first-boot
admin login and a brand-new registration (name -> confirm -> password
-> confirm -> gender -> display name -> email -> real name -> news
screen -> world) both landed cleanly in `/domains/Standard/center`
with correct `look`/`inventory` output. `save`, the `mail` command
(IIPS letter reader, empty folder, clean `q`-driven exit), and `who`
all worked correctly. `quit` printed the normal "Please come back
another time!" with zero `log/runtime` growth; reconnected after a
real multi-minute wall-clock gap and got a genuinely fresh `Setup()`
run (not a `"Reconnected."` link-restore), landing back in the same
room with the same empty inventory -- no state loss, no duplication.
Confirmed (per \S3) that the starting room's own pool-spawning code is
commented out in `domains/Standard/center.lpc`'s `create()`, and even
if it were re-enabled both pool destinations are dead ends (one points
at a non-existent `/domains/Discussion/MudOS`, the other at
`domains/School/room/entrance` -- one of the already-documented
incompatible-API School files that doesn't compile) -- so the starting
cavern legitimately has zero working exits; this is pre-existing
content/archive state, not something introduced by this port, and not
a programming bug to invent a fix for.

**Cross-cutting pattern sweep** -- grepped systematically for every
class in AGENTS.md \S7.121-\S7.135 and \S8.3a. Confirmed genuinely not
applicable/structurally clean on this lib for: \S7.121 (only float
usage in the whole tree is `secure/sefun/percent.lpc`'s own correctly-
`float`-declared `percent()`), \S8.3a (zero `private` command-dispatch/
call_out-target functions anywhere -- every `add_action`/`call_out`
target checked is a plain public/`nomask` function), \S7.112 (no NPCs
at all outside the non-compiling `domains/Examples/npc`), \S7.122
(`lib/autosave.lpc`'s `AutoLoad` item-reload mechanism is correctly
gated by `lib/interactive.lpc`'s own `Setup` re-entry guard --
`net_dead()`/reconnect via `boot_copy()` never re-invokes `Setup()` at
all, so the autoload-on-Setup path only ever runs once per genuinely
fresh login), \S7.123 (the one raw grep hit,
`secure/cmds/player/tell.lpc:109`'s `morse()` local variable
assignment, is inside a function body, not file scope -- false
positive), \S7.124 (no percentage/threshold fields of this shape exist
at all -- no combat/wimpy system), \S7.126 (no coordinate-area door
save-data of this shape), \S7.129 (`secure/sefun/communications.lpc`'s
`tell_room()`/`say()`/`shout()` wrappers all explicitly convert a
falsy/omitted `exclude` to `({})` before forwarding to `message()` --
already safe, unlike the buggy `es1` shape this class describes),
\S7.130 (disconnect handling goes through the `net_dead()` apply
directly, no `heart_beat()`-based `query_idle()` polling anywhere),
\S7.131 (`lib/interactive.lpc:63` calls `set_living_name(GetKeyName())`
inside `Setup()`, and `find_player()`/`find_living()` lookups were
directly exercised live via `secure/lib/login.lpc`'s own reconnect-
detection and `secure/cmds/creator/call.lpc`/`whisper`/`tell` --
already confirmed working), \S7.132 (no `map()` over a mapping
anywhere in the tree -- every `map()` call site targets an array),
\S7.133 (`net_dead()` -- the correct apply name for this driver -- is
genuinely defined in `lib/interactive.lpc`/`lib/creator.lpc`/
`lib/chat.lpc`), \S7.134 (`lib/room.lpc`'s own "extra descriptions
contributed by present items" accumulator, `ExtraLongs`, IS
initialized at its declaration site in `create()` -- structurally the
same feature class as the `arkadia`/`genesis` bug but already safe
here), \S7.135 (checked every lazily-guarded global family found via
grep -- `lib/nmsh.lpc`'s `Nicknames`/`Aliases`/`Xverbs`,
`lib/access.lpc`'s `__ReadAccess`/`__WriteAccess`,
`secure/daemon/master.lpc`'s `Groups`/`ReadAccess`/`WriteAccess`,
`daemon/banish.lpc`'s `__Names`/`__TmpBanish`/etc. -- every one is
unconditionally initialized in its own file's `create()`, not merely
guarded lazily per-accessor, so there's no "one accessor forgot the
guard" gap to find).

**New bug found and fixed**: `secure/daemon/events.lpc` (the reboot-
warning/scheduled-event daemon, `EVENTS_D`) defines `GetEvents()` and
`GetRebootInterval()` as its real query accessors, but two OTHER files
call a same-purpose function under a different name that is never
defined anywhere in the whole tree: `cmds/creator/events.lpc`'s `cmd()`
(the player-facing `events <wizard>` command, reachable by any
arch/creator) called `EVENTS_D->query_events()` at its second branch
(the `events` command's first branch, no argument, already correctly
calls `GetEvents()` -- so this is an internal naming inconsistency
within the SAME file, not a guess), and `secure/sefun/events.lpc`'s
(dead, uncalled) `event_pending()` made the identical mistake. This
predates this project's port entirely -- confirmed via `raw/
foundation2_fluffos_v1/lib/{cmds/creator,secure/sefun}/events.c`, the
pristine 1990s archive already has this exact mismatch, byte for byte.
On this driver, a call to an undefined function via `->` returns a
bare `int(0)`, and `(mapping)0`'s cast is a no-op (this driver's
`(type)` casts are compile-time hints only, see the `reference_lpc_
int_cast_is_compile_time_only` note) -- so `mp` stayed `int(0)`, and
the very next line's `keys(mp)` crashed uncaught: **reproduced live**,
`events somebody` as the seeded `fluffos` admin threw `*Bad argument 1
to keys() Expected: mapping Got: 0` (`log/runtime`, `/cmds/creator/
events` line 36), aborting the command with no player-facing
indication beyond the raw driver error text. **Fix**: both call sites
changed from `EVENTS_D->query_events()` to `EVENTS_D->GetEvents()`,
matching the daemon's own real, only accessor and the working sibling
branch already right above it in the same file
(`cmds/creator/events.lpc:35`, `secure/sefun/events.lpc:16`). Verified
live post-fix: `events somebody` now correctly prints "somebody
doesn't have any events pending." with zero `log/runtime` growth; a
full re-boot-and-retest after running the \S9 LPC formatter on both
touched files (all three formatter blind-spots checked clean: no `::`
mis-split, no case/comment merge -- neither file has a `switch`, no
CJK/escape re-spacing) reconfirmed the fix.

**Related gap found, NOT fixed (documented per this section's own
"when unsure, don't guess" rule)**: `cmds/player/nextreboot.lpc` (a
real, reachable player command) calls `EVENTS_D->query_next_reboot()`,
which also does not exist anywhere in the tree -- and unlike
`query_events()`, there is no matching same-purpose sibling function
to redirect it to (`GetRebootInterval()` only returns the configured
*interval* in hours, not an absolute next-reboot timestamp). This
doesn't crash (the undefined-function call_other returns `0` and the
command just prints a bogus "Wed Dec 31 16:00:00 1969 PST" instead --
confirmed live), but fixing it correctly would mean inventing new
bookkeeping (e.g. tracking mud-start time and deriving `boot_time +
RebootInterval*3600`) rather than just correcting a mistaken function
name, and the entire auto-reboot subsystem it would report on is
already dormant by original-archive design: `secure/daemon/
events.lpc`'s own `eventPollEvents()` self-rescheduling poll loop --
the only code path that ever checks `uptime() > RebootInterval*3600`
and triggers `eventReboot()` -- is never started at all, because its
sole `call_out((: eventPollEvents :), 60)` in `create()` is commented
out. Confirmed via `raw/foundation2_fluffos_v1/lib/secure/daemon/
events.c` that this `call_out` was ALREADY commented out in the
pristine 1990s archive, not something broken by this port. Left
untouched as a pre-existing, structurally dormant feature gap rather
than guessed at. (A third, related latent bug in the same dead
subsystem, also pre-existing and also left untouched: `secure/sefun/
events.lpc`'s `event()` wrapper calls `EVENTS_D->AddEvent(f, when,
reg)` with 3 arguments of the wrong types against `AddEvent()`'s real
6-parameter `(string c, string s, string f, mixed *a, int w, int r)`
signature -- but `event()` itself is never called by anything anywhere
in the tree, so this is unreachable dead code, not a live crash.)

**Evidence left in place**: the seeded admin account
`secure/save/creators/f/fluffos.o` (age/login-time counters naturally
advanced by this session's repeated logins). The throwaway test
character `Aldric` (`secure/save/creators/a/aldric.o`,
`secure/save/postal/a/aldric/`) was deleted before committing, per
this project's standing cleanup convention.

## Shop + 拜师 (2026-09-04 librarian slice)

Content-absent, same class as `foundation1`. Bare 1995 engine: no
combat, no stats, no currency, no vendor objects, no apprentice
verbs. Live on 40221 as seeded admin `fluffos` / `Mud@2026` in
`/domains/Standard/center`: `buy`, `list`, `shop`, `apprentice`,
`join`, `become`, and `拜师` all printed `What?`. `look`/`inventory`
still work. Left as-is.
