# Dock 9 -- porting notes

Source: `dyher/dock9` on GitHub (`git clone https://github.com/dyher/dock9`),
cloned into `raw/dock9/`. Built on the same LPUniversity/Sapidlib engine as
this project's already-onboarded `lpuni` -- same `adm/obj/master.lpc`
lineage, same `Groups`/`access` ACL scheme, same login/registration flow,
same `%^TAG%^` pinkfish colour system. The real mudlib root is the repo's
`lib/` directory; `bin/`, `driver/` (a bundled MudOS/FluffOS/rth driver
source snapshot), and `etc/` (build/install scaffolding) are all ignored,
same as every other archive in this project.

Genuinely distinct bespoke content, not a duplicate of `lpuni`:
`lib/areas/trepi/docks/` (24 files across `obj/npc/room`) -- a small,
fully authored dock-town area ("Trepi") with real room descriptions,
exits, an NPC, and author/date comments, none of it present in `lpuni`'s
own starting area. Small footprint, so this was a quick onboarding
relative to a full raw-archive bring-up.

Slug `dock9`, number 964, port 40266. No slug/port/number collision with
any existing lib (checked before starting). No LDMud tells found (no
`efun::`-as-scope-resolution outside the expected simul_efun-override
files, no `#pragma strict_types`, no LDMud-only applies) -- confirmed via
direct grep of the raw source, consistent with prior research.

## 1. Conversion

English-language archive (not GBK-encoded), same as `lpuni` --
`scripts/convert_lib.sh` against `raw/dock9/lib` confirmed this:
1395/1413 files already valid UTF-8, only 2 lossy conversions (a stray
non-ASCII byte in `doc/license` and in one archived Intermud-3 chat log
under `data/daemons/history_d/`, neither code), 14 skipped as genuine
binaries. 218 `.lpc` files after the `.c`->`.lpc` rename, 174 literal
`.c"` references fixed, 0 local angle-bracket `#include`s needed
converting, 1 file touched by the `static`->`nosave` sweep.

The archive also ships a handful of stray editor backup files
(`*.c.~1~`, `*.c~`) committed upstream in the repo's own initial commit
-- e.g. `std/user/mobile.c.~1~`, four files under
`areas/trepi/docks/{npc,room}/`. Left as-is: they don't end in `.c` or
`.lpc` so neither the driver's own file resolution nor
`scripts/lpcc_check.sh` ever touches them; they're harmless dead weight
carried over from upstream, not a conversion artifact.

## 2. Compile-time driver-compat fixes

- **`PACKAGE_UIDS` is enabled in this project's driver build, and this
  master object never defined any of the three applies it requires** --
  identical bug to `lpuni` (same master.lpc lineage). Confirmed via the
  driver's own boot message ("No function get_root_uid() in master
  object..."). Added the same fix:
  ```lpc
  string get_root_uid() { return "[admin]"; }
  string get_bb_uid() { return "[backbone]"; }
  string creator_file(string str) {
      string ret;
      ret = privs_file(str);
      if (!stringp(ret) || ret == "") ret = get_bb_uid();
      return ret;
  }
  ```
  (needed a forward prototype for `privs_file()`, since `creator_file()`
  was inserted above its definition in `master.lpc`).

- **`foreach (array item in ...)` is not valid syntax on this driver** --
  same bug class as `lpuni`'s `socket.lpc`, same file even:
  `adm/simul_efun/socket.lpc`'s `dump_socket_status()`. Fixed to
  `foreach (mixed *item in socket_status())`. This one blocks the whole
  simul_efun object from loading (it's `#include`d straight into
  `adm/obj/simul_efun.lpc`), so nothing else can load until it's fixed.

- **`TYPE array NAME`, the old-MudOS array-declaration dialect
  (AGENTS.md \S6.3)** -- MUCH more widespread here than on `lpuni` (which
  had only 13 occurrences across 4 files): 220 occurrences across 42
  files throughout the whole codebase (`adm/simul_efun/*`,
  `adm/daemons/*` including the whole Intermud-3 `chmodules/` tree,
  several `cmds/*`). Bulk-fixed with a script
  (`TYPE array NAME` -> `TYPE *NAME`), then hand-fixed 7 multi-declarator
  lines the bulk regex couldn't safely touch (e.g.
  `string array accessList = keys(access), keys, arr = ({});` ->
  `string *accessList = keys(access), *keys, *arr = ({});`, in
  `adm/obj/security_editor.lpc` and `cmds/adm/access.lpc`). One
  additional oddity found only here: `adm/daemons/finger_d.lpc` had
  `string array *users;` -- the redundant/malformed original combination
  of the `array` keyword AND a `*` on the same declarator (a latent typo
  in the ORIGINAL archive, not a rename side effect) -- fixed to
  `string *users;`.

- **Two content-authoring typos broke loading two of the bespoke Trepi
  rooms and one shared `make/` utility room** -- genuine programming bugs
  (syntax errors that abort the whole file's compile), not content/design
  issues, found via `lpcc_check.sh`:
  - `areas/trepi/docks/room/dock11.lpc`: a stray extra pair of empty
    quotes before a real string literal --
    `({"dock","dock 11"}):""This is Dock 11...` -- syntax error, fixed by
    removing the stray `""`.
  - `areas/trepi/docks/room/dock7.lpc`: a missing comma between two
    `set_items()` mapping entries (one multi-line string literal ran
    straight into the next `({...}):"..."` entry with no separator) --
    fixed by adding the comma.
  - `areas/make/management/towns.lpc`: mismatched closing
    brace/parenthesis on `set_chats(({ ... }});` (should close as `}));`
    to match the `(({` opener) -- fixed.

  (Confirmed this driver DOES support C-style adjacent string-literal
  auto-concatenation across lines with no `+`/comma between them --
  several other room files in this same area rely on that, and none of
  them errored -- so that shape is not a bug and was left untouched.)

## 3. Runtime bugs found via live boot + play testing

Two bugs in this exact shape were already catalogued in AGENTS.md \S7.140
from onboarding `lpuni` (same master/valid.lpc + login.lpc lineage), and
both are also present here -- ported the same fixes proactively rather
than waiting to rediscover them live:

- **`adm/obj/master/valid.lpc`'s `valid_read()` had no `func=="include"`
  exemption.** This driver's global-include-file injection issues the
  exact same `valid_read()` gate (with `func=="include"`) for every
  single compile, using the CURRENTLY CONNECTED PLAYER's own privileges
  as the read identity -- correct for a genuine player-facing file read,
  wrong for this compiler-internal, non-player-facing one. Without the
  exemption, the first never-yet-compiled file a non-admin player
  triggers (their first `inventory`/`help`) would permanently fail to
  `#include adm/include/global.h` (`/adm/` is admin-only in
  `/adm/etc/access`), aborting that whole compile for the rest of the
  boot. Fixed the same way as `lpuni`: added
  `if (func == "include") return 1;` alongside the existing
  `func=="file_size"`/`func=="restore_object"` exemptions.
- **`adm/obj/login.lpc`'s `idle_email()` only created a new account's
  `/home/<letter>/<name>/` directory inside the
  `if(file_exists("/adm/etc/new_install"))` block** -- true exactly once
  per install (this archive's `/adm/etc/new_install` flag file was
  already consumed/deleted by the original developers, so this path
  never fires again at all here). Every newly registered account was
  left with no home directory, and `master.lpc`'s `log_error()`
  unconditionally `write_file()`s into it on every compile diagnostic
  (even a harmless warning). Fixed by hoisting the
  `mkdir`/workroom-copy/journal-link lines out of the `new_install`
  gate, same as `lpuni`; kept the actual admin-rights-granting lines
  (`add_path`, `security_editor`, `rm("/adm/etc/new_install")`) inside
  the original gate. Also added a `directory_exists()` guard to
  `master.lpc`'s `log_error()` as a belt-and-suspenders measure.

One further, previously-uncatalogued bug found live (see the new
AGENTS.md \S7.179 entry -- this is genuinely wider than just this lib,
see below):

- **`adm/obj/login.lpc`'s `setupNew()` `mkdir()`s a brand-new player's
  save-data directory in a single call, but this driver's `mkdir()`
  doesn't create intermediate directories, and this archive's
  `/data/users/` tree only ships letter-bucket directories for letters
  that already had a registered player** (only `a/e/f/h/p/x` here).
  Reproduced live 100% of the time registering a fresh account whose
  name starts with any other letter (`sailor` was the test case):
  `Error: *Could not open /data/users/s/sailor/sailor.o.tmp for a save.`
  right after account creation. Fixed by ensuring the letter-bucket
  directory exists before the leaf directory, same two-step pattern
  already used for `/home/` right above it in the same function.
  **The exact same latent bug is also present in `lpuni`**, but is
  masked there because that archive happens to ship all 26 letter-bucket
  directories under `/data/users/` pre-created -- not fixed in `lpuni`
  as part of this session (out of this onboarding's scope), but flagged
  here and in AGENTS.md for the next agent that touches that lib.

- **The `.c`->`.lpc` rename fixed-width filename-slice bug (AGENTS.md
  \S6.3, first found on `lpuni`)** -- also present here, in MORE files
  than on `lpuni`: `cmds/object/update.lpc`, `cmds/object/clone.lpc`,
  `cmds/object/clean.lpc`, `cmds/object/dest.lpc`, `cmds/wiz/goto.lpc`
  (all `file[<2..<1] != ".lpc"` -> widened to `<4..<1>`), plus the
  opposite-direction instance in `cmds/file/more.lpc`
  (`file[<2..<1] == ".lpc"` -> `<4..<1>`; its sibling `== ".h"` check on
  the same line is untouched -- `.h` really is 2 characters, not a bug).
  A NEW instance not seen on `lpuni`: `cmds/file/ls.lpc`'s
  `filename_prefix()` used a single fixed 2-char slice as a `switch`
  discriminant across THREE differently-sized extension cases (`".lpc"`
  4 chars, `".h"` 2 chars, `__SAVE_EXTENSION__` i.e. `".o"` 2 chars) --
  no single slice width can satisfy all three, so the `.lpc` case could
  never match (files were never colourized green) while `.h`/`.o` still
  worked correctly by coincidence. Rewritten as three independent,
  correctly-sized suffix checks (see the code for the exact form) rather
  than trying to force it back into one switch. Verified live:
  `update /adm/obj/master.lpc` now succeeds (was
  `Error: File /adm/obj/master.lpc.lpc not found.`), and `ls /adm/obj/`
  now shows `.lpc` files highlighted green/bold as intended.

## 4. Checked, present but inert / not present

- Chinese-detection (\S8.1): N/A, English-only lib, same as `lpuni`.
- `switch` with only `default:` (\S6.3): none found.
- `TYPE * a, b` first-declarator-only bug: none found.
- Hardcoded `MUD_PORT`/`PORTNO`: none found.
- `shutdown`/`rm`/`unlink` outside `valid_*` gates in the security
  daemon: none found.
- `ed_start`/`ed_cmd`/`query_ed_mode`, private `command_hook`: none
  found.
- `efun::exec`/`efun::destruct`/`efun::shutdown`/`efun::set_privs`/
  `efun::debug_info`/`efun::query_idle` overrides in
  `adm/simul_efun/overrides.lpc` and `adm/simul_efun/user.lpc` --
  legitimate simul_efun overrides, `#include`d straight into
  `adm/obj/simul_efun.lpc` (never meant to compile standalone). These are
  the expected \S7.15-adjacent false positives from
  `lpcc_check.sh`'s per-file batch compile (`lpcc` compiles them outside
  the real simul_efun context, where `efun::` scope resolution isn't
  valid) -- both load and work fine as part of the real simul_efun
  object, confirmed by the live boot loading `simul_efun` cleanly with
  zero errors.

## 5. Live outbound network side effect at boot (by design, not a bug -- same class as `lpuni`/`imud`/`tmi2`/`skylib`)

Same as `lpuni`: `adm/daemons/chmodules/i3.lpc`'s Intermud-3 module makes
a real outbound socket connection to the public `*i4` router within a few
seconds of boot, and receives real `mudlist` packets back from other real
muds currently on that network (observed live: a real reply describing
`Lima 1.1a3` from `192.9.170.24`). This mudlib doesn't implement a
`mudlist` service handler (`i3_rec_unsupported()` logs it and moves on),
so this is harmless but IS a genuine live network event against a real
third party -- do not sweep this lib into high-frequency automated
re-boot loops.

## 6. `lpcc_check.sh` batch-compile results

207/220 pass. The 13 that fail are all expected, not bugs:
- 10 files under `www/` (`htdocs/index.lpc`, `error/*.lpc`) -- these are
  raw HTML/XML page templates that happen to ship with a `.lpc`
  extension in the ORIGINAL upstream source (not a rename side effect --
  `std/net/httpd/thread.lpc` already referenced them as `.lpc` before
  any conversion ran). They're `read_file()`+`parse_lpc()`'d as text by
  the httpd, never compiled/loaded as LPC objects -- `lpcc_check.sh`
  naively tries to compile every `.lpc` file it finds, so these are
  guaranteed false positives for this file layout.
- `adm/simul_efun/overrides.lpc`, `adm/simul_efun/user.lpc` -- see \S4
  above.
- `obj/mudlib/newsclients/std_newsclient.lpc` -- `create()` calls
  `user_data_directory(query_privs(this_player()))`, which needs a real
  interactive player context that the headless `lpcc --batch` harness
  doesn't provide (same lpcc-vs-live-driver artifact class noted
  elsewhere in this project's AGENTS.md). Confirmed genuinely fine live:
  the `news` command loads and runs this exact object correctly for a
  real logged-in player.

**IMPORTANT**: while re-testing this lib, don't run `lpcc_check.sh`
concurrently with a live driver instance still bound to port 40266 --
`adm/daemons/http_d.lpc` will spuriously fail to load with a port-bind
conflict, which looks like (but isn't) a real regression. Kill any
running driver first.

## 7. Boot and play test

Boots clean (native driver, `~/src/fluffos/build-debug/src/driver
config.fluffos` from `libs/dock9/`): "Loading preload files..." through
every daemon, then "Accepting telnet connections on 0.0.0.0:40266." /
"Initializations complete." with zero errors in `log/debug.log`.

Verified live with a raw Python socket client through the full flow:
- Fresh registration (`sailor` / password / confirm / e-mail) all the
  way into the world, landing in **Dock 9** itself (the bespoke starting
  room, named after the mud) with a real description and a real single
  exit (`south`).
- `inventory` and `help` both work correctly as a brand-new player's
  first-ever commands (this is the exact reproduction case for the
  \S7.140 `valid_read()` include-gate bug -- confirmed clean with the fix
  applied).
- Movement through the bespoke `areas/trepi/docks/` content: Dock 9 ->
  Pier (south) -> Dock 12 / Dock 8 / Dock 10 / Shipping Area (cargo1),
  each with real room descriptions and exits; a scripted NPC ("A helpful
  sailor") present and delivering real dialogue on room entry.
  Explicitly re-verified `dock11.lpc`/`dock7.lpc`/`towns.lpc` load and
  render correctly post-fix.
- `quit` disconnects cleanly ("Thank you for visiting Dock 9"); a
  subsequent connection with the same id/password reconnects correctly
  ("Success: Reconnected.") back into the last room.
- `news` command exercises `std_newsclient.lpc` live (the one `lpcc_check`
  false-positive from \S6) -- works correctly with a real player.
- No `score` command exists (grepped, confirmed, same as `lpuni` --
  this engine has no combat/stats system at all).
- One content-completeness gap, NOT a bug: `cargo1.lpc`'s `north`/
  `northeast` exits point at `trepi_lane1.lpc`/`trepi_lane2.lpc`, which
  don't exist anywhere in this archive (the wider "Trepi" town beyond
  the docks was apparently never built). Moving that direction fails
  gracefully with `Error [move]: Unable to move through that exit.`
  (an intentional, caught fallback in `std/user/mobile.lpc`, not a
  crash) -- this is exactly the documented "small bespoke footprint"
  scope of this archive, left as-is. Similarly, the new-player welcome
  banner references `help rules`, which has no helpfile
  (`Error [help]: Unable to find helpfile for: rules`) -- also a
  content gap, not a programming bug, left as-is.

WASM status: not attempted this session (`wasm_status` left `""`) --
scope was native-only per this onboarding's assignment.

## Admin account

- **id**: `fluffos`
- **password**: `MudAt2026`
- Registered through the normal registration flow (this archive's own
  `/adm/etc/new_install` first-boot auto-admin flag was already
  consumed/removed by the original upstream developers, so it could not
  be used here). Granted admin by adding `fluffos` to the `(admin)` group
  line in `/adm/etc/groups` (the actual ACL store `isMember()`/`adminp()`
  read) -- preferred editing the data over the code, per AGENTS.md \S1.5.
  Also had to manually add the wizard command directories
  (`/cmds/wiz/`, `/cmds/object/`, `/cmds/file/`, `/cmds/adm/`) to the
  `path` array in the account's own body save file
  (`data/users/f/fluffos/fluffos_mob.o`) -- this codebase resolves
  command dispatch from a per-player saved `path` list, not live from
  `adminp()` status, and that list is normally only ever extended via
  `add_path()` calls inside the (consumed) `new_install` bootstrap path
  or by an already-privileged wizard's own `chpath`-style command.
  Verified live: `update <path>` against a real `adm/obj/master.lpc`
  file succeeds, and `ls` shows the corrected `.lpc` colour-highlighting.

## 深度功能测试 / §10.7 deep functional test (2026-08-31)

Round-two pass, adapted for this lib's real scope (no combat/stats
system, per \S0). One continuous session, native driver
(`~/src/fluffos/build-debug/src/driver config.fluffos` from
`libs/dock9/`, port 40266), driven via `scripts/tmux_mud.sh` across
several parallel sessions (the seeded admin `fluffos`/`MudAt2026`, plus
two throwaway fresh registrations `mailerone`/`mailertwo` created
specifically to exercise mail/channel between two real accounts and
cleaned up before committing). Everything the original onboarding
already covered (registration through world entry, movement through
Trepi/docks, inventory/help, quit/reconnect, news, the letter-bucket
save-directory fix) was not re-run in full; this pass targeted what
NOTES.md flagged as not yet deeply tested.

### Six bugs found and fixed

**1. `adm/daemons/mail_d.lpc` + `adm/obj/master/valid.lpc` -- the
entire mail system was completely unusable, in two compounding ways**
(new AGENTS.md \S7.190 -- full root-cause writeup there):
- `valid_read()`'s hard-coded daemon-trust exemption for `restore_object`
  only ever listed `finger_d`, so `mail_d`'s own `restore(user)` -- which
  needs to `restore_object()` a mailbox file on behalf of
  `this_interactive()`, including the SENDER'S OWN mailbox -- was denied
  outright: `Error: *restore_object: read permission denied:
  /data/users/m/mailerone/mailerone.mail.o.` on the very first `mail
  <recipient>` invocation, before any message could even be composed.
- `valid_write()` had NO daemon-trust mechanism at all (not even a
  finger_d-style one), so once the read side was fixed, `save_object()`
  of the composed message -- including into the RECIPIENT's inbox for
  delivery, a different user's directory entirely -- would have failed
  the identical way.
- Fixed by adding a `mail_d`-scoped exemption to `valid_read()`
  (mirroring the existing `finger_d` one exactly) and a brand-new
  `func=="save_object"` exemption to `valid_write()` for `mail_d`.
  Verified live end-to-end: composed and sent a full message (subject,
  empty CC, multi-line body via the in-editor `a`/`.`/`w`/`q` flow) from
  `mailerone` to `mailertwo`, then logged in as `mailertwo` and read the
  delivered message back via `mail` -> `1` (inbox) -> `1` (message) --
  correct sender, subject, date, and body every time.
- **Same bugs confirmed still present, unfixed, in the sibling `lpuni`**
  (identical `master/valid.lpc` finger_d-only allowlist, identical
  missing `valid_write()` mechanism) -- flagged in AGENTS.md \S7.190 for
  whoever next deep-tests `lpuni`'s mail system, not fixed here (out of
  this session's scope).

**2. `adm/daemons/mail_d.lpc`'s own internal "only the real mail client
may call this" guard was ALSO broken, independently, by the standard
\S6.3 `.c`->`.lpc` rename-slice bug** -- `send_message()`/
`delete_message()` both compared `file_name(previous_object())[0..index
- 1]` (a bare clone name with no extension) against
`OBJ_MAIL_CLIENT[0..<3]`, where `OBJ_MAIL_CLIENT` is
`"/obj/mudlib/mail_clients/mail_client.lpc"` -- `[0..<3]` only strips 2
characters, correct for the ORIGINAL `.c` extension but leaving a
stray `.l` on the right-hand side after the rename, so the two sides
could never match. Every legitimate call through the real mail client
was rejected with `Error [mail]: You can only do that through the mail
client!`, masking bug \#1 above until that was fixed first. Widened
both occurrences to `[0..<5]` (correctly drops the full 4-character
`.lpc` extension). **Same bug confirmed still present, unfixed, in
`lpuni`'s own copy of this exact file** (also flagged, not fixed, per
AGENTS.md \S7.190).

**3. `adm/obj/master.lpc`'s `log_file()` had no missing-directory guard,
so the FIRST-ever `force`/`makedev`/`revdev`/`nuke` each boot crashed**
-- `LOG_FORCE`/`LOG_PROMOTE`/`LOG_NUKE` (in `include/logs.h`) all resolve
to a path one level below `LOG_DIR` (`adm/force`, `adm/promote`,
`adm/nuke`), inside a `/log/adm/` subdirectory this archive never ships.
`write_file()` doesn't create missing parent directories, so the very
first invocation of any of those four admin commands each boot threw
`Error: *Wrong permissions for opening file /log/adm/force for append.:
No such file or directory` (the command's own effect -- e.g. `force`
actually forcing the target -- still happened; only the after-the-fact
logging side effect crashed, visibly, to the admin). Fixed with a
`directory_exists()`/`mkdir()` guard in `log_file()` before the
`write_file()` call, same pattern already used in `adm/obj/login.lpc`'s
home/data-directory setup. Verified live: `force`, `makedev`, and
`revdev` (against the throwaway `mailerone` account) all ran clean with
zero error traces post-fix, and `log/adm/force`/`log/adm/promote` now
contain the expected log lines. **Same latent gap also exists in
`lpuni`'s identical `log_file()`** -- masked there only because that
archive happens to ship a pre-created (empty) `/log/adm/` directory,
same "masked by a pre-existing directory" shape as the already-known
`/data/users/` letter-bucket bug from this lib's own onboarding
section (\S3) -- not fixed there, just noted for the next agent, same
as that earlier precedent.

**4. Three wizard commands unconditionally crashed instead of failing
gracefully whenever an Intermud-3 service module wasn't loaded**
(the normal state in this archive, since it implements no `mudlist`
service handler per \S5) -- `cmds/wiz/mudinfo.lpc`, `cmds/wiz/finger.lpc`
(the `user@mud` remote-finger form), and `cmds/wiz/i3seen.lpc` all did
`find_object(I3_MUDLIST or I3_UCACHE)` immediately followed by an
unguarded `->` call, with no null-check -- crashing every single
invocation with `Bad argument 1 to EFUN call_other() Expected: object,
string, array, Got: int(0)` instead of the already-correct
"Mudlist unavailable."/"module is currently not loaded" fallback this
codebase's OWN sibling implementations use correctly
(`cmds/wiz/mudlist.lpc`, `cmds/std/tell.lpc`, `cmds/std/reply.lpc`,
`cmds/wiz/rwho.lpc` all guard the identical lookup correctly). Fixed
all three by adding the missing null-check, matching the working
sibling pattern. Verified live (pre-fix crash reproduced first in every
case): `mudinfo test`, `finger fluffos@dock9`, and `i3seen fluffos` now
all correctly print a graceful unavailable-module message. Checked
`lpuni` for the same pattern -- NOT present there; `lpuni`'s
`cmds/std/mudinfo.lpc`/`cmds/std/finger.lpc` are an earlier,
differently-written revision (`load_object()` with its own guard, or no
I3 mudlist lookup at all) -- this looks like a regression introduced
when `dock9`'s later revision (dated 2007, `Tricky @ RtH`) was rewritten
against `find_object()`, not a lineage-wide bug, so no AGENTS.md entry
filed for this one.

**5. `adm/daemons/soul_d.lpc` had the identical unguarded-`find_object()`
bug in two places, reachable via any targeted emote at an `"@mud"`-style
target** -- `find_object(I3_UCACHE)->getUserCache()` (used to resolve an
i3 username match for the emote target) and, separately,
`find_object(I3_UCACHE)->getGender(...)` (used to pick a `$PT`/`$ST`
pronoun for the message), both with no null-guard. Fixed both:
the first now defaults to an empty mapping (`([])`) when the module
isn't loaded, which this function's own existing logic already handles
correctly (falls through to "no i3 match found"); the second now
defaults `gender` to `-1`, which the surrounding `switch` already
treats as its existing neutral "its"/"it" default case. Not
independently reproduced with a full remote-i3 round trip (would need a
live peer mud with a matching username), but the crash mechanism is
identical to \#4 above and the fix is a direct, mechanical application
of the same pattern.

**6. `std/object/object.lpc`'s `set_chats()` had a stray
`write(this_object());` debug leftover, executed on EVERY call to this
universally-inherited base-class method** (any room, NPC, or item that
sets ambient chat/emote messages) -- printed the raw object reference
(`OBJ(/path/to/file)`, or `OBJ(/path/to/file#N)` for a clone) directly
to whichever player's connection happened to trigger that particular
object's first compile/`create()` each boot, with no relationship
whatsoever to the function's actual job of storing the chat list and
interval. Reproduced live: moving south from Dock 9 into Pier, Trepi
for the first time in a fresh boot printed
`OBJ(/areas/trepi/docks/npc/greeter_sailor)OBJ(/areas/trepi/docks/npc/greeter_sailor#8)OBJ(/areas/trepi/docks/room/pier3)`
with no separators, immediately before the real "You move to Pier,
Trepi." message (three separate `set_chats()` calls: the NPC's
blueprint `create()`, the NPC's actual clone, and the room's own
ambient-chat setup). Fixed by deleting the stray line. Verified live
post-fix: the same first-ever move into a not-yet-compiled room (Dock
12, this time) produced clean output with no leaked object references.
Checked `lpuni`'s own copy of this file -- does NOT have this line, so
this looks like a `dock9`-specific debug leftover from this archive's
own author rather than an inherited lineage bug; no AGENTS.md entry
filed.

### What was tested and confirmed working

- **Mail, full round trip**: compose (subject/CC/body via the in-editor
  `a`/`.`/`w`/`q` sequence) -> send -> "You have new mail!" notification
  on the recipient's live session -> inbox listing -> reading the
  message back, all between two independent real accounts
  (`mailerone`/`mailertwo`, both granted `/cmds/wiz/` path access purely
  for this test, since `mail` is wizard-only by design in this engine,
  same as `lpuni` -- not a bug).
- **Channel**: the default `chat` channel carries messages correctly in
  both directions between two independent live sessions in the same
  room.
- **Wizard commands** (`cmds/wiz/`): `eval`, `where`, `people`, `finger`
  (local form), `home`, `goto`, `echo`, `force`, `path` (implicitly, via
  the temporary grants above), `mudinfo`, `i3seen`, `finger` (remote
  `user@mud` form), `makedev`, `revdev`, `sockinfo`, `callouts` -- all
  exercised live (four found broken and fixed, see above; the rest
  worked correctly on first try).
- **File commands** (`cmds/file/`): `pwd`, `ls`, `cd`, `mkdir`, `cat`,
  `cp`, `mv`, `grep`, `tail`, `ln`, `rm`, `rmdir` -- full create-inspect-
  rename-delete lifecycle exercised in the admin's own home directory,
  cleaned up afterward.
- **Object commands** (`cmds/object/`): `clone`, `functions`, `dest` --
  cloned a real item (`areas/trepi/docks/obj/pebble.lpc`), inspected its
  function list, destroyed it, confirmed it was gone.
- **Admin commands** (`cmds/adm/`): `wall` (broadcast), `what` (online-
  users/last-command report), `force`, `makedev`, `revdev` (all three
  also part of the \#3 bug fix above).
- **NPC dialogue**: the greeter sailor in Pier, Trepi correctly greets a
  newly-arrived player by name (`catch_tell()` pattern-matching the
  room's own "X has entered" message) and correctly responds to the
  exact documented trigger phrase ("say Take me to the training area.")
  by teleporting the player to the Training Ground -- both paths
  confirmed live.
- **Intermud-3**: the same live outbound `*i4` router connection
  documented in \S5 was confirmed active again this session (real
  `i3.log` traffic); not hammered with additional reboots, per that
  section's own caution (same class as `lpuni`/`imud`/`tmi2`/`skylib`).
- **Two independent quit/reconnect cycles**: (a) `mailerone`/`mailertwo`
  quit and reconnected mid-session with the same password, restoring
  correctly into Dock 9; (b) the admin `fluffos` quit from the Training
  Ground, a ~220-second real wall-clock gap elapsed (concurrent with the
  long-sit boot watch below), then reconnected and was correctly
  restored to the exact same room (Training Ground) with `[announce]
  System: Fluffos has logged into Dock 9.` and no state loss.
- **Long-sit boot watch** (\S10.0, WASM not yet measured in that
  session -- done via one idle
  `scripts/mudclient.py` connection instead of
  `wasm_boot_watch.sh`): held one connection idle for ~220 seconds;
  driver stayed alive throughout (confirmed via `ps` uptime), and its
  own captured stdout was clean (no errors, no crashes) for the entire
  window.
- **Letter-bucket save-directory fix re-confirmed live**: both
  `mailerone` and `mailertwo` (letter `m`, not one of this archive's
  originally-shipped pre-existing buckets) registered and saved cleanly
  on the first try, re-verifying the onboarding-session fix in \S3 holds.
- `debug.log` was (as expected, per AGENTS.md \S10.9) never touched
  across this entire session -- the driver's own captured stdout was
  used as the actual error-signal source throughout, and stayed clean
  after every fix was applied and re-verified.

### Flagged unverified

- A genuine live round trip of the two `soul_d.lpc` i3-emote fixes
  (\#5 above) against a real second mud on the Intermud-3 network was
  not attempted (would require a live peer mud with a specific matching
  username, outside this session's control) -- the fix is a direct,
  mechanical application of the exact pattern already verified working
  in \#4, but is flagged here as code-reviewed rather than end-to-end
  live-tested.
- The remaining `cmds/wiz/` commands not explicitly listed above
  (`beep`, `edemote`, `jcheck`, `jlo`, `lazygun`, `locate`, `rwho`,
  `setplan`, `snowball`, `trans`, `which`, `i3seen` beyond the fix
  above) were read but not individually exercised live in this pass --
  time-budgeted in favour of the mail/ACL investigation, which turned
  out to be the highest-value finding.

### Test accounts

`mailerone`/`mailertwo` (both password-protected throwaway accounts
created solely to exercise mail/channel between two real sessions) were
deleted -- save files, `/home/m/` workroom copies, and dev journal links
-- before committing, keeping only the pre-existing seeded `fluffos`
admin account, per this project's established cleanup convention (see
`lpuni`'s own \S "Deep functional test round two" for the precedent).
`adm/etc/access`/`adm/etc/groups` picked up a purely-cosmetic
mapping-iteration-order diff from the `makedev`/`revdev` test cycle
(no actual ACL content changed) and were reverted rather than
committed. `data/daemons/history_d/` and
`data/daemons/chmodules/i3.o` (real Intermud-3 chat history and router
connection state, growing on every live boot) were added to the
project's root `.gitignore`, mirroring the existing `imud` precedent,
and the pre-fix churn in those paths was reverted rather than
committed.

## WASM measurement (2026-09-03)

`meta.json` was already `playable` from the 2026-08-31 deploy-unblock;
the README still said "not attempted." Cold-boot under the shared
`~/src/fluffos/build-wasm` failed on `adm/simul_efun/socket.lpc`
calling `socket_status()` from `dump_socket_status()` — same class as
`lpuni`. Stubbed the header behind `#ifndef __PACKAGE_SOCKETS__`. After
that, `scripts/wasm_client.js` logged in as `fluffos` / `MudAt2026`
into Training Ground, `look` and `quit` both worked. `http_d.lpc`
`socket_error` is a graceful preload skip (not on the login path).
I3 still tries an outbound connect at boot — do not loop-reboot.
Shop/combat/death were not exercised this pass.
