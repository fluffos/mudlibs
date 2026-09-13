# Scratch (scratch) — porting notes

Source: `git clone https://github.com/rmanis/scratch` (commit
`4ac1a4ed898d217a9bb02508709694bd51ecbc76`, “Add contents to master
and what it needs.”, 2013-08-10; converted 2026-09-05). Config name
`Scratch`. Slug `scratch`, number **971**, port **40280**.

This collection’s copy is a snapshot, not a live mirror.

Minimal FluffOS starter by the Lil author (`rmanis`). Shipped README:
“If you consider Lil to have too much, start from Scratch.” Three LPC
files: master, empty simul, echo chamber. Not a game and not a
duplicate of `lil` (179; that archive is the MudOS testsuite lib). Do
not onboard `rmanis/scratch` again.

## 0. Layout

Repo root **is** the mudlib. Master `/single/master`, simul
`/single/simul_efun` (empty), connect object `/clone/echochamber`.
No rooms, accounts, or commands in the archive. `raw/` is gitignored.

## 1. Convert (2026-09-05)

`convert_lib.sh` UTF-8: `already_utf8=10 converted=0 lossy=0
skipped_binary=0`. 3 `.lpc`.

## 2. FluffOS port

The archive master was only `connect()`. FluffOS needs
`get_root_uid`/`creator_file`/`valid_*`. Original `connect()` did
`destruct(this_object())` on `new(ECHOCHAMBER)` failure — that is the
**master**, so a failed clone would take down the driver. Fixed: write
the error and return 0. Original saved as `master_orig.lpc`.

Empty `global include file` in the archive config is the questmud
trap (driver `#include`s `""`). Pointed at `"/include/globals.h"`.

`set_this_player()` in the archive `logon()` is not an efun on this
driver (`Undefined function`); dropped. Interactive connect already
sets `this_player()`.

Echo chamber: original `process_input` only `printf("%O\n", input)`.
Added `look` / `score` / `quit` so the catalog bar works; unknown
input still dumps `%O`.

### Live-verified (native, port 40280)

No accounts. Connect → echo chamber; `look` / `score` / `hello`
(echoes `"hello"`) / `quit` (“Goodbye.”). Cold-boot after formatter
still works.

WASM not verified. `unique_games` stays counting numbers `< 900`; 971
is still listed as a lib.

## 深度功能测试（§10.7，2026-09-13）

Catalog echo chamber only — the archive has no playable world (no
rooms, accounts, shop, or combat). Do not invent rooms. Source-
complete bar for a three-file starter.

Native boot (`~/src/fluffos/build-debug/src/driver config.fluffos`
from `libs/scratch`, port **40280**, PID owned by this session):

- Connect → banner; `look` / `l` → The echo chamber; `score` / `sc` →
  Guest (Scratch guest), no stats; unknown input `hello` echoes
  `"hello"` (`%O`); `look around` still `look` (rest ignored).
- `quit` → “Goodbye.”; driver stayed up. Fresh reconnect → same
  `look` / `score` / `quit` (no accounts / no persist).
- Shop / combat / guild / death: **N/A** (not in archive).

Logs this boot:

- Driver stdout (`Unable to open log file: "log/debug.log"` before
  chdir into `work/` — §10.9 / empty-debug-log launch limitation;
  no live `debug.log` fd). Captured stdout: boot warnings only
  (`domain_stats` / `author_stats` missing — expected for this
  starter); no LPC errors across play or quit.
- `/log/catch` (`work/log/catch`): empty across the clean
  playthrough; mtime matches this boot. Handler proven live earlier
  in the same session when a deliberate bad compile of
  `/clone/echochamber` produced
  `CAUGHT /single/master.lpc:42 *No program in object...` then
  reverted. No code fixes this pass.
