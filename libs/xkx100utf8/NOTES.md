# 侠客行一百 UTF-8 (xkx100utf8) — porting notes

Source: `git clone https://github.com/fluffos/xkx100` (commit
`ee022c90aabbbed6413acc6e10254e5a00f511fd`, “Add WASM pack script +
GitHub Pages deploy workflow”, 2026-07-29; converted 2026-09-05).
In-game name `侠客行` / banner `侠客行一百`. Slug `xkx100utf8`,
number **110-1**, port 40275.

This collection’s copy is a snapshot, not a live mirror. Local
login-encoding and preload patches mean it has diverged from
upstream. Upstream is `github.com/fluffos/xkx100` (fluffos org) —
genuine driver-compat fixes found later belong in an upstream PR as
well as here (AGENTS.md §2.3).

`MudRen/xkx100` is the same tree with a MudCore wrap. Do not onboard
it again.

## 0. Relation to collection `xkx100` (110)

Collection `xkx100` is the Coollizard `侠客行一百.rar` (14255 `.lpc`,
master `/adm/obj/master`). This GitHub tree is a UTF-8 FluffOS
modernization of the **same 侠客行一百 game** (banner credits
“CopyRight Coollizard & xkx100 2003-2004” and
`https://github.com/MudRen/xkx100`). Core files are not byte-identical
(`adm/single/master` vs `adm/obj/master`; 12192 `.c` vs 14255 `.lpc`;
logind/chinesed/securityd all differ). Numbered **110-1**, not a new
unique game.

## 1. Convert (2026-09-05)

`rsync --exclude .git` into `raw/` (do not copy `.git` into `work/` —
that registers as a submodule). `convert_lib.sh` UTF-8:
`already_utf8=12993 converted=0 lossy=994 skipped_binary=35`. Lossy hits
were leftover `.old`/`.bak`/`.tmp` sidecars, not live `.c`. 12192
`.lpc`. 606 `.c"` refs. 11 local angle-bracket includes. 17 files
`static`→`nosave`. Exit 0.

`is_chinese()` is already `pcre_match(..., "^\\p{Han}+$")`.
`check_legal_name` uses `strwidth` 4–10 (2–5 Han). 秦风 passed.

## 2. Always-UTF-8 login

Upstream `connect()` set GBK only on port 5555 (6666/websocket left
as driver default). This project uses a single telnet port: always
`set_encoding("utf-8")`.

## 3. Preload I3

`adm/etc/preload` listed `/adm/daemons/network/dns_master`. Commented
out (AGENTS.md §7.6). Do not put this lib on a high-frequency reboot
loop if that line is ever re-enabled — it is a real outbound I3
socket.

## 4. Bugs fixed this onboard

1. **`log_error()` warning filter (AGENTS.md §7.10).**
   `strsrch(..., "Warning")` → `"arning:"`.
2. **`howmany_visitor()` / `howmany_card()` unguarded `sscanf`
   (same shape as collection `xkx100` §7.9).**
   `read_file("/log/MUDVISITOR")` is present in this snapshot
   (`VISITORS 999`), so first login did not hang. Still added
   `if (!stringp(content)) return 0;` on both helpers. `/log/GIFTCARD`
   is missing; the card helper is not on the login path.

`command_hook` is already `protected nomask`. `wizlist` already
ships `fluffos (admin)` and `mudren (admin)`.

## 5. Registration / admin

Flow: unused English id → `y` → Chinese name (2–5 Han) → password
(≥5) → confirm → hometown region `1`–`5` (city random) → 膂力/悟性/
根骨 (80-point budget, 10–30) → accept `y` → character `0`–`5` →
email (`id@address`) → `m`/`f`.

Live: `fluffos` / `秦风` / `Mud@2026` / hometown 3 → 苏州客店 /
stats 20/20/20/20 / 普通. `目前权限：(admin)` (天帝). `look` /
`score` (food/water full) / `quit`.

`LOGIN_TIMEOUT` is 300 seconds.

## 6. Not done

No §10.7 shop/拜师/combat. No full §9 format of 12192 files. WASM
status **playable** (no MySQL). Native play verified.

## 7. Local run

```
cd libs/xkx100utf8
~/src/fluffos/build-debug/src/driver config.fluffos
```

Game port: **40275**.

```
python3 scripts/mudclient.py 127.0.0.1 40275 --timeout 55 --idle 0.45 \
  --send "fluffos" --send "Mud@2026" \
  --send "look" --send "score" --send "quit"
```
