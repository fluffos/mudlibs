# PaoMUD (paomud) — porting notes

Source: `git clone https://github.com/dzpao/pao-mud` (commit
`f855715a97caa5171f3e7cf5696f5f68ae1a9f94`, “feat(GA): 进入副本时，去掉主站冗余的
GA”, 2022-12-14; converted 2026-09-05). Config name `PaoMUD`. Slug
`paomud`, number **972**, port **40281**.

This collection’s copy is a snapshot, not a live mirror.

Tiny from-scratch FluffOS learning lib (“LPC 练习场，从零开始写 MUD”).
Five LPC files: master, simul, user, unused login, and one `test`
command. No rooms, accounts, or combat. Not a duplicate of `scratch`
(rmanis three-file echo chamber) or `imud`. Do not onboard
`dzpao/pao-mud` again.

## 0. Layout

Repo root **is** the mudlib. Master `/single/master`, simul
`/single/simul_efun`, connect object `/clone/user` (`LOGIN_OB` is
defined but unused). `command/test` is loaded on demand by the `test`
verb. Archive `etc/config-fb` is a second instance on port 8000 for the
`fb` 副本 tunnel; this collection does not boot it. `raw/` is
gitignored.

## 1. Convert (2026-09-05)

`convert_lib.sh` UTF-8: `already_utf8=12 converted=0 lossy=0
skipped_binary=0`. 5 `.lpc`. No `.c"` rewrites. No `static`→`nosave`.

## 2. FluffOS port

The archive master was only `connect()` / uids / `valid_socket`.
FluffOS needs `valid_read`/`valid_write`/`valid_*` and an error
handler. `new(USER_OB)` failure is caught and returns 0 (does not
destruct the master). Original saved as `master_orig.lpc`.

`global include file` in the main archive config already quoted
`"/include/globals.h"`. `etc/config-fb` does not (questmud empty-include
trap) — unused here.

`prompt_on()` / `prompt_off()` in archive `fb()` are not efuns on this
driver (`Undefined function`; user object would not compile). Empty
simul stubs.

Echo-chamber catalog bar: added `look` / `score` (`l`/`sc` aliases) and
`enable_commands()` so `add_action` verbs run. Archive already had
`quit`/`exit`, `hello`, `test`, `fb`.

### Bugs fixed

- **`fb()` used `on_backend_close` as `socket_connect` write_callback.**
  STREAM connect-ready is the write callback. Combined with printing
  “已经进入副本” immediately on `socket_connect()==0` (async in
  progress), a refused `127.0.0.1:8000` printed success then immediately
  “已经离开副本”. Write callback is now `on_backend_connected`; success
  text only fires there. With nothing listening on 8000: “正在连接副本”
  then the close callback’s “已经离开副本”.

### Live-verified (native, port 40281)

No accounts. Connect → `欢迎！`; `look` / `score` / `hello` / `test`
(compiles `/command/test`, table + ANSI; `call_out` “hello world [20]”
after 3s) / `fb` (no listener on 8000) / `quit` (“再见！”). Cold-boot
after the `fb` fix still works.

WASM not verified. `unique_games` stays counting numbers `< 900`; 972
is still listed as a lib.
