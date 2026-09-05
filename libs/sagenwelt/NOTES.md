# Sagenwelt (sagenwelt) — porting notes

Source: `git clone https://github.com/Shea690901/Sagenwelt-Lib`
(default branch `develop`; playable snapshot is `feature/player` commit
`77266da70c4103890effa3f20c0cadabbed388c3`, “moved struct's *.c ->
*.h”, 2016-04-03; converted 2026-09-05). Config name `Sagenwelt`. Slug
`sagenwelt`, number **973**, port **40282**.

This collection’s copy is a snapshot, not a live mirror.

Unfinished FluffOS skeleton by Gwenhwyvar (“Once ready, this lib will
contain everything needed to setup a new mud…”). `Domains/` is empty.
No shipped rooms or combat. Not a duplicate of collection
`morgengrauen` / `MorgenGrauen/mg-mudlib` (that is a different
Shea690901 repo). Do not onboard `Shea690901/Sagenwelt-Lib` again.

## 0. Layout

Mudlib root is `src/`. Master `/secure/obj/master`, simul
`/secure/obj/simul_efun`, intended login `/secure/obj/player/login`.
`raw/` is the full git tree (gitignored). Bundled `gamedriver`
gitmodules (`fluffos/fluffos`) was not cloned.

`feature/player` is further along than `develop` (player/login, racesd,
Lima-style shell). Both have empty `Domains/`.

## 1. Convert (2026-09-05)

`convert_lib.sh` UTF-8: `already_utf8=75 converted=2 lossy=0
skipped_binary=88`. 16 `.lpc`. 11 `.c"` rewrites (preload `*.lpc`).

## 2. FluffOS port

Archive master/simul do not boot on this driver.

### Archive bugs (kept in `master_orig.lpc` / `master_feature.lpc` /
`simul_efun_orig.lpc`)

- `SECCURE_DIR` / `DAEMKN_DIR` typos in `std_paths.h` (LOGIN_OB path
  would be wrong).
- Master: `switch driver_flag` missing parens; `return("%s:%s",…)`
  instead of `sprintf`; `*uids` missing comma; `if(a) || (b)` missing
  parens; `ORIGIN_DIVER` (not in origin.h); `valid_write` consulted
  `_READ`.
- Simul header `#include <messages.h>` (file is `message.h`); several
  prototypes missing `;`.
- `/var/cfg/*.acl` unfinished (own TODO). `Privs.cfg` is a single `/`.
- `player.c` concatenates a second leftover login.c at the bottom.
- Login never reaches a room.

### Catalog overlay

Original master needs the unfinished simul (author_of, syslog, ACL,
…). Catalog `master.lpc` + empty `simul_efun.lpc` +
`catalog_user.lpc` boot and implement `look` / `score` / `quit`.
Global include is `globals_catalog.h` because archive `std.h` pulls
the broken simul header.

Patched-but-still-unbootable archive master saved as
`master_feature.lpc`.

### Live-verified (native, port 40282)

No accounts. Connect → catalog landing; `look` / `score` / `quit`
(“Goodbye.”).

WASM not verified. `unique_games` stays counting numbers `< 900`; 973
is still listed as a lib.
