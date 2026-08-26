# TMI-2 -- porting notes

Source: a maintained, already-FluffOS-adapted ZIP (`tmi2_fluffos_v3.zip`)
originally distributed from `lpmuds.net` (now defunct). The live site is
down; this exact archive was recovered from the Wayback Machine snapshot
`https://web.archive.org/web/20160306040625if_/http://lpmuds.net/files/tmi2_fluffos_v3.zip`
and content-verified before use (real, dated 1996-era LPC source, e.g.
`lib/cmds/file/_tsh.c`). Slug `tmi2`, number 173, port 40220.

TMI-2 (The Mud Institute) is one of the historically significant, widely
descended-from LPMud codebases of the early-to-mid 1990s -- this project's
own AGENTS.md already refers to a "TMI-2/Falcon family" of later mudlibs
because so much of the LPMud ecosystem traces its `std/`, command-soul,
and security-daemon conventions back to it. The archive itself bundles a
full FluffOS 2.16-ds05 driver source tree (`fluffos-2.16-ds05/`) and
prebuilt Windows binaries (`win32/`, `bin/`) alongside the actual mudlib
(`lib/`) -- both ignored per this project's standard convention of using
its own driver rather than whatever a bundled archive shipped.

## 1. Extraction and conversion

Mudlib root: `raw/tmi2_fluffos_v3/lib/`. Master file `/adm/obj/master`,
simul_efun `/adm/obj/simul_efun`, global include `<mudlib.h>` (looked up
via `/include`) -- a CD-lib-style layout (`/adm/obj/`, `/adm/etc/`,
`/adm/daemons/`) distinct from the `/secure/`-rooted layout `genesis`
uses, but recognizably the direct ancestor of it.

`scripts/convert_lib.sh` on `raw/tmi2_fluffos_v3/lib` -> `work`: this is
a genuinely English-language, already-ASCII archive (1677 of 1712 files
already valid UTF-8, 0 real lossy conversions -- the 2 "LOSSY" hits were
a stray invalid byte each in two `doc/` prose files, not source), so the
encoding step was a no-op as expected. 715 files renamed `.c`->`.lpc`,
217 literal `.c"` references fixed, 14 local angle-bracket includes
converted to quotes, 115 files `static`->`nosave`.

## 2. Compile-time / boot-time driver-compat fixes

- **`domain_file()` array-index-out-of-bounds crash on every boot**
  (the severe one). `/adm/obj/master.lpc`'s `domain_file(string filename)`
  does `path = explode(filename, "/"); if (!path) return "NONAME";
  switch (path[0]) { ... }`. This driver builds with
  `__SANE_EXPLODE_STRING__`, under which `explode("/", "/")` returns
  `({})` (empty), not the old-MudOS `({"", ""})` -- and the driver itself
  calls `master::domain_file("/")` once at boot (to resolve the backbone
  uid, per `vm/internal/master.cc`'s `first_load` `PACKAGE_MUDLIB_STATS`
  setup). The original `!path` guard only ever catches a *null* return,
  never an *empty* one, so `path[0]` hard-errored ("Array index out of
  bounds") on that very first call.
  This was NOT a cosmetic warning -- it aborted the entire master load.
  The error happens deep inside `vm_start()`'s `init_master()`, before
  any mudlib-level error handler is installed, so the uncaught C++
  exception unwinds straight past every mudlib-side `catch()`/error
  logging and is caught only by the driver's own top-level guard, which
  prints just "The simul_efun and master objects must be loadable" with
  no further detail and calls `exit(-1)` -- a real boot-blocking crash
  with an extremely uninformative top-level message. Diagnosed by
  temporarily enabling `noninteractive stderr write` in the runtime
  config (off by default, so this driver's non-interactive `write()`
  calls -- which is nearly all of them, this early in boot -- go
  nowhere and are silently lost) and adding checkpoint `write()`s through
  `master.lpc`'s `valid_read`/`valid_write` and `access.lpc`/`groups.lpc`'s
  `load_access()`/`load_groups()`, which are what the driver's very first
  file-permission check ends up invoking; the mudlib's own error handler
  had in fact already caught and logged full tracebacks to
  `/log/runtime` all along (`*Array index out of bounds. ... 'domain_file'
  at /adm/obj/master`) -- the debugging difficulty was purely that
  nothing surfaced past that log file to the process's own stdout/stderr
  before the driver aborted the whole boot.
  Fixed by widening the guard to `if (!path || !sizeof(path)) return
  "NONAME";`. Confirmed live: repeated clean boots afterward with zero
  entries in `/log/runtime`.
- **`ref` used as a plain identifier, but reserved as a pass-by-reference
  parameter keyword on this driver** (`grammar.y`'s `ref: L_REF { ... }`
  production, e.g. `int foo(ref mixed x)`). Two real compile-blocking
  hits, both hard "syntax error" at points that don't look like the
  actual cause (the parser chokes downstream once `ref` is consumed as
  the reserved word instead of an identifier):
  - `adm/daemons/channels.lpc`: `create_channel()`'s `object ref`
    parameter and `register_channel()`'s `object ref;` local, plus every
    use of the identifier in between. This file IS in the live preload
    list (`/adm/daemons/channels`) and backs the real in-game channel
    system (`gossip`, etc.) -- a boot-blocking failure for a live
    feature, not dead code. Renamed the identifier to `refob` throughout
    (7 sites).
  - `adm/daemons/ref_d.lpc`'s `resolv_ref()`: local `string ref;`.
    Renamed to `refstr` (3 sites). This daemon backs the wizard `ref`/
    `refs`/`unref` reference-variable commands (`cmds/object/_ref.lpc`
    etc., which use "ref"/"refs" only as plain strings/mapping keys --
    those were never affected).
  - `cmds/file/_changelog.lpc`'s `pop_coder(int ref)`. Renamed the
    parameter to `refidx` (3 sites).
  Swept the whole tree for other bare `\bref\b` identifier uses
  afterward (`grep -rn '\bref\b'`) -- the remaining hits are all either
  `ref`/`refs` used purely as string literals/mapping keys (fine) or
  `refs`/`ref_help` as variable names (fine, not the reserved word
  itself), so no further sites needed changing.

## 3. Admin account

- **id**: `fluffos`
- **password**: `FluffOS2026Admin`
- Registered through the normal registration flow (name -> confirm ->
  password -> confirm -> gender -> race -> email -> real name -> drops
  into the game world). Being the very first character ever created on
  this fresh install, it was automatically granted the in-game "wizard
  status" flag during registration (`[You have been granted automatic
  wizard status]`) -- but that flag alone does **not** grant real file
  read/write privilege on this codebase; TMI-2's actual file-permission
  system is a separate `/adm/etc/groups` + `/adm/etc/access` group
  membership scheme (`domains` command showed `Fluffos`'s only
  affiliation as `guest`, and `update` on any root-owned file failed
  with "Fluffos is not allowed to destruct Root" until this was fixed).
  Added `fluffos` to the `(root)` group in `adm/etc/groups` (alongside
  the archive's own seed admin `cratylus`) so the account has real root
  file access, matching how `finalrealms` added `fluffos` to
  `secure/gods.lpc`'s admin list. `update /cmds/wiz/_goto` and
  `update /adm/daemons/quota` both verified live afterward ("Updated and
  loaded."). `update /adm/obj/simul_efun` itself still fails with "Can't
  load objects when no effective user" -- this is a narrower, pre-existing
  constraint on destructing/reloading the live singleton simul_efun
  object specifically (confirmed via `/log/runtime`: it's
  `overrides.lpc`'s `destruct()` override hitting the euid check, not an
  ACL denial), not a general permission gap; every other live-write test
  succeeded.

## 4. Compile-sweep tail (28 of 715 files)

`scripts/lpcc_check.sh` after the fixes above: 687 pass, 28 fail. Checked
every failure for live references (`grep -rn '/path/to/file\b'` across
the whole tree) before writing it off:

- **One likely lpcc-harness-only artifact, not a real bug**:
  `/obj/ed_guide` self-destructs in its own `create()` when
  `previous_object()` isn't the exact expected caller
  (`cmds/xtra/_ed_guide.lpc`, gated behind `teachers`-group membership,
  part of TMI-2's student/teacher tutorial subsystem) -- lpcc's isolated
  per-object load harness is never that caller, so this is the same
  "create()-guard makes lpcc FAIL where a real caller would succeed"
  class this project has documented before (see AGENTS.md's wxddym/bai
  note), not a driver-compat regression. Not independently re-verified
  live (the teacher-tutorial subsystem is out of scope for baseline
  boot/play verification) but the failure mode is the well-known artifact
  pattern, not a new one.
- **Everything else is unreferenced/dead content**: zero hits anywhere
  else in the tree for `/std/adt/istack` (a macro, `ISTACK_ADT`, defined
  in `include/adt_defs.h` but never actually called), `/obj/net/www`,
  `/obj/net/terminal`, `/obj/tools/barney`, `/obj/shells/{sbsh,shsh}`
  (old ANSI-terminal "shell" demo objects), `/u/l/leto/{nntp,blah}` and
  every `/adm/priv/{elephant,tk,dog,doh,bird,blah,cat}` file (individual
  wizards' personal home-directory scratch/test objects -- several still
  use the pre-FluffOS 2-argument `move_object(ob, dest)` form, "Too many
  arguments to move_object"), `/cmds/wiz/channels0505` and
  `/adm/daemons/network/I3-0505` (dated backup copies of the live
  `_channels.lpc`/`I3.lpc`, not the files actually loaded), `/ftp/_patch`
  and its duplicate `/cmds/file/_patch`, `/cmds/std/spells/
  missile_spell_j` (raw literal backslashes outside any string/comment --
  looks like corrupted/incomplete source, not something this port
  broke), `/adm/daemons/usage_d`/`usage_i` (explicitly commented out of
  `adm/etc/preload` in the archive's own shipped preload file --
  intentionally disabled upstream), `/doc/etc/func_spec` (a `/doc/`
  reference stub listing efun signatures with modern `type|type` union
  syntax, meant to be read, not compiled), `/adm/daemons/network/netmail`
  (a `/include/net/macros.h` syntax error; only reachable through the
  optional network-mail bounce path in `mailbox.lpc`, never during normal
  local play), and `/adm/daemons/virtual/{o_server,template/room}`
  (the latter is explicitly a *template*, `ROOM_TEMPLATE`, meant to be
  cloned/customized per-use by the virtual-room server, not loaded as a
  real room itself).
  None of this affects a real boot or normal play -- confirmed by a full
  live registration-to-gameplay session with zero entries in
  `/log/runtime` after the fixes in \S2.

## 5. Live outbound network connection at boot (Intermud-3)

Like `imud` (§2.3 in AGENTS.md), this lib has a genuine, intentional
live-network side effect at boot, unlike almost every other lib in this
corpus (which are all sandboxed with no outbound connections). `adm/
daemons/network/I3.lpc` is preloaded at boot (via the live `channels`
preload chain / first `check_router()` call) and connects out to a real,
hardcoded public Intermud-3 router (`include/net/i3.h`:
`I3_ROUTER "97.107.133.86 8787"`, `ROUTER_NAME "*dalet"`) using the real
`socket_create()`/`socket_connect()` efuns in `adm/daemons/network/
socket.lpc`. Confirmed live: booting this lib updates `adm/etc/I3.o`'s
saved `mudlist_id`/`mudlist` fields with a real, current snapshot of the
live public I3 mudlist (dozens of real other muds -- CoffeeMud, VargonMUD,
CircleMUD-family servers, etc. -- with real IPs/ports), i.e. a real
outbound connection and a real registration/mudlist exchange with a
public third-party service, not a local-only simulation.

This is correct, intended upstream behavior (not a bug introduced by this
port), but it means **this lib should NOT be swept into high-frequency
automated re-boot loops** (round-two/round-three-style long-sit scans,
periodic re-verification passes) the way every other sandboxed lib in
this corpus safely can be -- each boot is a real network event against a
real third party's infrastructure. Treat this the same way `imud` is
already flagged.

## 6. Status

Boots clean: zero compile errors, zero uncaught runtime errors in
`log/runtime` across repeated fresh-driver boots. Full registration (a
brand-new character all the way through gender/race/email/real-name into
the actual game world -- the "famous TMI-2 quad"), `look`/`score`/
`inventory`/`quit`, re-login as an existing character, and wizard-level
`update` (after the groups fix in \S3) all verified live with a raw
socket client.

Registration flow: `name` -> confirm (`y`/`n`) -> password -> confirm
password -> gender (`male`/`female`/`neuter`/`hermaphrodite`) -> race
(`dwarf`/`elf`/`gnome`/`human`/`orc`/`troll`/`halfling`/`sprite`/
`shadow`/`ent`/`siren`/`skeleton`/`zombie`) -> email address (validated,
`user@host` form required) -> real name -> drops into the game world.

## WASM status update (2026-08-26, another session)

Promoted `wasm_status` from `""` to `playable`. Same root-cause class
as `ds386`/`discworld`/`deadsouls_fluffos`: `adm/simul_efun/
dump_socket_status.lpc` (part of the eagerly-loaded simul_efun object)
called `socket_status()` unconditionally, undefined on this driver
build (no `sockets` package). Gutted to a safe stub (diagnostic admin
tool only, not on the boot/login path). No other socket-related
eager-load failures found. Verified with a scripted WASM session:
login as `fluffos`/`FluffOS2026Admin`, arrival in the famous TMI-2 quad
room with the correct description. `look`/`score`/`quit` weren't
recaptured distinctly in this transcript (absorbed by the first-login
news pager) but are already verified clean under native testing above
and untouched by this fix.

## Local run

```
cd libs/tmi2
~/src/fluffos/build-debug/src/driver config.fluffos
```

Game port: **40220**.
