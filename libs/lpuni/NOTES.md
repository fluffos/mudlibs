# LPUniversity Mudlib -- porting notes

Source: `lpuni_fluffos_v1.zip`, a maintained, already-FluffOS-adapted
archive from lpmuds.net (a now-defunct LPMud archive site). The live site
is down; this exact archive was recovered from the Wayback Machine
(<https://web.archive.org/web/20160306051537if_/http://lpmuds.net/files/lpuni_fluffos_v1.zip>)
and content-verified (valid zip, non-corrupted, real content such as
`bin/config.lpuni` and `license`) before this session started. Slug
`lpuni`, number 177, port 40224. The zip bundles a FluffOS 2.9-ds2.07
driver source snapshot (`fluffos-2.9-ds2.07/`), plus `bin/`, `win32/`,
`etc/` build/install scaffolding -- all ignored, this project uses its own
driver. The real mudlib root is the zip's `lib/` directory.

LPUniversity is positioned by its own lpmuds.net description as a teaching/
reference base -- "not ready for play... provides a chance to build a lib
from the ground up without having to deal much with the driver" -- so a
minimal/skeletal feel was expected going in (similar in spirit to
`libs/genesis/`). In practice it's less skeletal than that framing
suggests: it ships a complete login/registration/security/command-dispatch/
help/mail/message-board/news/channel/Intermud-3 engine (a real
`adm/etc/new_install`-driven first-boot admin wizard included) *and* one
small real starting domain (`areas/lpuni/`, "LPUniversity Cafe" -- an
entrance, three floors, a bar/lounge/cafe/bathroom, and a greeter NPC with
real dialogue). No genesis-style from-scratch bootstrap was needed. There is
no combat/stats system at all, so (like `foundation2`) there is no `score`
command to test -- confirmed via grep, not a gap in this port.

## 1. Conversion

English-language archive (not GBK-encoded) -- `scripts/convert_lib.sh`
against `raw/lpuni_fluffos_v1/lib` confirmed this: 897/902 files already
valid UTF-8, only 1 lossy conversion (a stray non-ASCII byte in a plain
text/doc file, not code), 4 skipped as genuine binaries. 151 `.lpc` files
after the `.c`->`.lpc` rename, 110 literal `.c"` references fixed, 0 local
angle-bracket `#include`s needed converting, 7 files touched by the
`static`->`nosave` sweep (no collisions: no `"static...` path-literal hits,
no `#define nosave static`/`#define protected static` shims to neutralize).

## 2. Compile-time driver-compat fixes

- **`foreach (array item in ...)` is not valid syntax on this driver** --
  `adm/simul_efun/socket.lpc`'s `dump_socket_status()` declared the loop
  variable with the bare word `array` (old-MudOS shorthand); this driver
  requires a real type (`mixed *item`, since each element of
  `socket_status()`'s result is itself an array). Fixed the one instance;
  this broke loading the whole simul_efun object (`socket.lpc` is
  `#include`d straight into `adm/obj/simul_efun.lpc`), so nothing else in
  the mudlib could load until this was fixed.
- **`TYPE array NAME`, the second old-MudOS array-declaration dialect
  (AGENTS.md \S6.3)** -- a type keyword directly followed by the literal
  word `array` (e.g. `string array arr = parse(...)`), distinct from bare
  `array x;`. 13 occurrences across 4 files: `adm/obj/master/valid.lpc` (2,
  including the group/access-list parser inherited straight into
  `master.lpc` -- this alone blocked master from loading at all),
  `adm/obj/security_editor.lpc` (4), `cmds/std/channel.lpc` (1),
  `cmds/adm/access.lpc` (5, the wizard-facing twin of `valid.lpc`'s
  parser). Fixed by dropping the `array` keyword and using real array
  syntax (`string *arr`); multi-declarator lines needed a `*` prefix on
  every subsequent name too (e.g. `string array accessList = keys(access),
  keys, arr = ({});` -> `string *accessList = keys(access), *keys, *arr =
  ({});`).
- **`PACKAGE_UIDS` is enabled in this project's driver build, and this
  master object never defined any of the three applies it requires.**
  Confirmed via the driver's own boot message ("No function get_root_uid()
  in master object; possibly the mudlib doesn't want PACKAGE_UIDS to be
  defined") and by the `__PACKAGE_UIDS__` predefine in the boot's LPC
  Predefines dump. Without `get_root_uid()`/`get_bb_uid()` the driver
  refuses to boot at all; without `creator_file()` (called on **every**
  object load) essentially every object load would hard-error the moment
  boot got that far. This codebase's own security model is entirely the
  privs/access-list scheme already in `master.lpc`'s `privs_file()`
  (classifies a path into `[daemon]`/`[adm_obj]`/`[cmd_wiz]`/etc.) --
  there's no separate driver-native-uid concept anywhere in the archive.
  Added:
  ```
  string get_root_uid() { return "[admin]"; }
  string get_bb_uid() { return "[backbone]"; }
  string creator_file(string str) {
      string ret;
      ret = privs_file(str);
      if (!stringp(ret) || ret == "") ret = get_bb_uid();
      return ret;
  }
  ```
  (Same fix class as `foundation2`/`merentha`, this session's other
  lpmuds.net onboardings -- see AGENTS.md \S2.2's checklist.)
- **`file[<2..<1] != ".lpc"` -- a `.c`->`.lpc` rename side effect,
  AGENTS.md \S6.3's fixed-width filename-slice bug class.** `<2..<1>` is a
  2-character slice, sized for the old 2-character `.c` suffix; after the
  literal was updated to the 4-character `.lpc` string the slice was never
  widened, so the comparison is **always true** (a 2-char slice can never
  equal a 4-char string) and the code always appends a redundant `.lpc`,
  producing e.g. `master.lpc.lpc does not exist`. Found in 5 wizard/object
  commands -- `cmds/object/clone.lpc`, `cmds/object/dest.lpc`,
  `cmds/object/update.lpc`, `cmds/object/clean.lpc`, `cmds/wiz/goto.lpc` --
  all fixed to `<4..<1>`. Confirmed live before the fix: `update
  /adm/obj/master.lpc` failed with `/adm/obj/master.lpc.lpc does not
  exist`; after the fix it succeeds.
  - **Opposite-direction instance, same root cause**: `cmds/file/more.lpc`
    used `== ".lpc"` (not `!=`) with the same undersized 2-char slice, so
    the pager's syntax-highlighted-paging branch for `.lpc` files could
    *never* match -- it silently fell through to plain unhighlighted
    paging for every `.lpc`/`.h` source file. Fixed the same way.
  - **Structurally different instance, same root cause**:
    `cmds/file/ls.lpc`'s `filename_prefix()` used a `switch()` on a single
    fixed 2-char slice with a `case ".lpc":` arm that could never match
    (the file's own comment even lampshades this: `//Will hit default if
    size>2`) -- every `.lpc` file in a directory listing colorized as
    plain white/unmarked instead of green. A `switch()` can't have
    per-case slice widths, so rewrote as an if/else chain: a `<4..<1>`
    check for `.lpc` first, then the original `<2..<1>` checks for `.h`
    and `__SAVE_EXTENSION__` (both genuinely 2 characters, not bugs).
  - Grepped the whole tree afterward for any other `[<N..<1] <op> ".lpc"`
    or `[<N..<1] <op> ".h"` shape at any width -- these 7 sites (the 5
    `!=` command fixes + `more.lpc` + `ls.lpc`) were the complete set.

## 3. Runtime/hygiene fixes (found via live boot + play testing)

- **Missing `/home/l/login/` directory crashed the first-boot admin-grant
  flow with a raw, player-visible driver traceback (AGENTS.md \S7.11).**
  `adm/obj/login.lpc`'s `query_name()` hardcodes `"login"` for the
  transient pre-authentication connection object; `master.lpc`'s
  `log_error()` writes any caught compile/runtime diagnostic to
  `user_path(this_player()->query_name()) + "log"` when `this_player()` is
  set. During the very first registration on a fresh install, `login.lpc`
  calls `security_editor->enable_membership(...)` twice (developer, then
  admin) to grant the new account admin rights; something in that call
  chain triggers a caught error while `this_interactive()` is still the
  bare `login` object, and `log_error()`'s own `write_file()` into the
  never-shipped `/home/l/login/` then throws *itself* ("Wrong permissions
  for opening file /home/l/login/log for append. No such file or
  directory") -- visible to the connecting player as a raw traceback in
  the middle of an otherwise-successful registration. Fixed by seeding
  `work/home/l/login/.gitkeep` (this project's established empty-directory
  placeholder convention -- a bare `log` placeholder would itself be swept
  up by this repo's own `.gitignore` rule for runtime log dirs,
  `libs/*/work/**/log`, and silently vanish from every future clone).
  Confirmed fixed: re-ran the exact same registration flow against a fresh
  install (`adm/etc/new_install` restored, account data cleared) and the
  traceback no longer appears; `"Success [login]: You are now an admin."`
  now prints cleanly with no error noise around it.
- **`log_error()` funnels compile WARNINGS to the player too, unguarded
  (AGENTS.md \S7.10, the exact documented class).** The very first lazy
  compile of `/obj/mudlib/mail_clients/mail_client.lpc` (triggered by
  `enter_world()` checking for new mail) throws 27 "Illegal to declare
  nosave function" warnings (the harmless, expected fallout of this
  driver's `static`->`nosave` conversion applied to old-MudOS `static`
  function declarations, AGENTS.md \S4.3) straight into the connecting
  player's screen, looking exactly like a crash in the middle of normal
  play. Gated `log_error()`'s `tell_object()` call on the message not
  containing the (case-agnostic) substring `"arning:"`, matching this
  project's established fix for this driver-wide class; warnings still get
  written to the player's private log file, only the live broadcast is
  suppressed. Confirmed fixed: re-tested the same first-mail-check trigger
  on a fresh boot and the workroom-entry output is now clean.

## 4. Checked, present but inert (no fix needed)

- **`runtime_config.h`'s `get_config()` index numbering is stale**
  (`adm/include/driver/runtime_config.h` uses the old compact scheme --
  string constants 0-14, then `BASE_CONFIG_INT` starting at 15 -- while
  this driver's canonical header reserves string-constant slots up to 255
  before the int base starts, per AGENTS.md \S7.89's class of bug).
  Confirmed the mismatch would misdirect any `get_config()` call using
  this bundled header's constants -- but grepped the whole mudlib and
  `get_config(` is never called anywhere, so this is dead, unexercised
  code, left as-is (matches the archive's own shipped header, not
  something this port should silently "fix" without a live symptom to
  verify against).

## 5. Checked, not present (from this session's recurring-bug checklist)

- `NO_ADD_ACTION`: `#undef`'d in `etc/local_options` -- this build targets
  native `add_action()` support, which matches this driver's actual
  compile-time config; no `skylib`-style mismatch.
- `ed_start()`/`ed_cmd()`/`query_ed_mode()`: never used: this codebase
  calls the old-style `ed()` exclusively throughout (`cmds/file/ed.lpc`,
  the mail/news clients' editor integration), which is exactly what this
  driver build supports -- no `foundation2`/`finalrealms`-style mismatch.
- `ref` used as an ordinary identifier: none found (`\bref\b` grep across
  the whole tree, ignoring `reference`/`refer`-family words, is clean).
- `explode()` on a `SANE_EXPLODE_STRING` edge case (e.g.
  `explode('/','/')`): none found.
- `add_action()` with a bare function value instead of a string: none
  found -- all 4 call sites in the archive already pass a string function
  name, the correct idiom for this driver.

## 6. Live outbound network side effect at boot (by design, not a bug -- same class as `imud`/`tmi2`/`skylib`, see AGENTS.md \S2.3)

**Confirmed live**, not just read from source: `adm/etc/preload` loads
`/adm/daemons/chan_d` unconditionally, which pulls in
`adm/daemons/chmodules/chdmod_i3.lpc` (Intermud-3 chat-network support).
Within a couple of seconds of every boot, `log/i3.log` records a real
outbound `socket_create()`/`socket_connect()` to a live public I3 router:

```
Notice [I3/socket]: Connecting to *yatmim, 149.152.218.102 23
Success [I3]: Connected.
Notice [I3]: Sending connection details.
Notice [I3]: Sending 'startup-req-3'
```

This repeated (a fresh connect-and-handshake) on every single boot this
session. This is genuine, intentional upstream functionality (not
something to patch away), but it means every boot of this lib makes a
real outbound connection attempt to a real third-party service --
**this lib should NOT be swept into high-frequency automated re-boot/
re-test loops** the way this project's other (fully sandboxed) libs
safely can be. The `lpcc_check.sh` compile sweep does NOT trigger this
(it never runs `create()`/preload, so it's safe to re-run freely); only a
real driver boot does.

## 7. Boot and play test

Booted `~/src/fluffos/build-debug/src/driver config.fluffos` repeatedly
(a small, deliberately-minimized number of boots given \S6 above); zero
compile errors, `Initializations complete.`, accepting telnet connections
on 40224 every time. Verified live with a raw Python socket client:

- **First-boot admin install**: registered a brand-new account `fluffos`
  through the real registration flow (name -> password -> confirm
  password -> email -> the archive's own `adm/etc/new_install`-gated
  wizard). Landed in a real per-account workroom
  (`cp("/areas/std/workroom.lpc", ...)`), automatically granted admin
  (`"Success [login]: You are now an admin."`), confirmed via `who`
  showing `[ Admin ] Fluffos`.
- **Commands**: `look`, `inventory` (`You are not currently carrying
  anything.`), `who`, `ls` (directory listing with correct `.lpc`/`.h`/dir
  colorization after the \S2 fix), `more <file>` (correct paged,
  syntax-aware output after the \S2 fix), and the wizard `update <path>`
  command (`Successful [update]: /adm/obj/master.lpc was updated.` --
  broken before the \S2 slice-width fix). `quit` disconnects cleanly
  (`Thank you for visiting LPUniversity`).
- **Real shipped content**: moved from the workroom into `areas/lpuni/`'s
  "LPUniversity Cafe" starting domain (`entrance.lpc`'s exit verb
  `cafe`) -- a real room description and a greeter NPC (`Johnathon`) with
  real scripted dialogue ("Welcome to the LPUniversity Cafe. Please feel
  free to make your way inside."), confirming this archive ships genuine
  playable content, not just an empty engine.
- No `score` command exists anywhere in this archive (grepped `cmds/` for
  a file or string literal named `score`) -- there is no stats/combat
  system at all, consistent with this being a deliberately bare teaching
  base; `inventory`/`who`/`ls`/`more`/`update` substitute for this
  project's usual `look`/`score`/`quit` bar, same precedent as
  `foundation2`.

Zero uncaught runtime errors in `log/log` (this codebase's
`error_handler()` log target) across this session's boots and
play-testing, beyond the two fixed issues in \S3 above (confirmed absent
on the final re-test boots).

## Admin account

- **id**: `fluffos`
- **password**: `testpass123`
- **privilege**: admin (granted automatically by the archive's own
  first-boot install wizard, `adm/etc/new_install` -- now consumed/deleted
  as designed, so this is the mudlib's one standing seeded admin, not a
  save-file hand-edit)

Verified live: `update <path>` (this project's canonical ACL/compile-
permission check) against a real `adm/obj/master.lpc` file succeeds.

## WASM status

Not attempted this session -- `wasm_status` left `""`.
