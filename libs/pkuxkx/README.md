# 北大侠客行 (pkuxkx)

A Chinese wuxia mudlib (北大侠客行 / PKUXKX), cloned from
`https://github.com/ly19811105/pkuxkx-utf8` (commit `0eaf237`,
2021-04-09 “清理备份文件”). This collection’s copy is a snapshot as
of 2026-09-05, not a live mirror — local UTF-8 login and driver-compat
fixes mean it has diverged from upstream. Slug `pkuxkx`, number 966,
port 40274.

The repo root is the mudlib (~21981 `.lpc` after convert). Upstream
already shipped UTF-8; `convert_lib.sh` renamed `.c` → `.lpc` and
left the text alone. Original config listened on 5555 (GBK), 6666
(UTF-8), and 8888 (websocket). This project uses a single telnet
port.

Not the same codebase as this collection’s `xkx100` / `xkx2017` /
`xkx2001` (侠客行一百). Same distant ES-II ancestry, different game.

## Registration flow

`您的英文名字（要注册新人物请输入new）：` → `new` → English id →
`y` → Chinese name (1–6 Han characters) → password (≥6 chars, ≥2 of
upper/lower/digit/special) → confirm password → email (`id@address`)
→ `m`/`f`.

New characters start in **未明谷** (Weiming Valley, the PKU-themed
newbie area), not the Yangzhou inn, until they finish the newbie
village or pass 2000 exp.

## Admin account

- **id**: `fluffos`
- **password**: `Mud@2026`
- **privilege**: `adm/etc/wizlist` → `(admin)` (天神)

Verified live: enter_world prints `目前权限：(admin)`; `who` lists
秦风 as 巫师; `look` / `score` / `quit` work.

## Local run

```
cd libs/pkuxkx
~/src/fluffos/build-debug/src/driver config.fluffos
```

Game port: **40274**.

```
python3 scripts/mudclient.py 127.0.0.1 40274 --timeout 25 --idle 0.5 \
  --send "fluffos" --send "Mud@2026" \
  --send "look" --send "score" --send "quit"
```
