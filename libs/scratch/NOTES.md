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
