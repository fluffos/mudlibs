# 侠客行一百 UTF-8 (xkx100utf8)

A UTF-8 FluffOS snapshot of 侠客行一百, cloned from
`https://github.com/fluffos/xkx100` (commit `ee022c9`, 2026-07-29).
This collection’s copy is a snapshot as of 2026-09-05, not a live
mirror. Slug `xkx100utf8`, number **110-1**, port 40275.

Same game as collection `xkx100` (Coollizard `侠客行一百.rar`, number
110) — not a byte-identical archive. The login banner still reads
侠客行一百 and credits Coollizard & xkx100 2003-2004.
`MudRen/xkx100` is this same GitHub tree with a MudCore wrap; do not
onboard it again.

Repo root is the mudlib (12192 `.lpc` after convert). Upstream already
shipped UTF-8. Original config listened on 5555 (GBK), 6666 (UTF-8),
and 8888 (websocket). This project uses a single telnet port.

## Registration flow

English id → `y` → Chinese name (2–5 Han characters) → password (≥5)
→ confirm → hometown region `1`–`5` (city chosen at random) → allocate
80 attribute points (膂力/悟性/根骨, 身法 fills the rest) → accept →
character type `0`–`5` → email → `m`/`f`.

## Admin account

- **id**: `fluffos`
- **password**: `Mud@2026`
- **privilege**: already in `adm/etc/wizlist` as `(admin)` (天帝)

Verified live: enter_world prints `目前权限：(admin)`; `look` in 苏州
客店; `score` shows 秦风 with food/water full; `quit` works.

## Local run

```
cd libs/xkx100utf8
~/src/fluffos/build-debug/src/driver config.fluffos
```

Game port: **40275**.
