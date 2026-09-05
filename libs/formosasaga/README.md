# 源流福爾摩沙 (formosasaga)

A Taiwan-history exploration MUD cloned from
`https://github.com/wade-fs/FormosaSaga` (commit `a700cf5`, 2026-06-28).
This collection’s copy is a snapshot as of 2026-09-05, not a live
mirror. Slug `formosasaga`, number **967**, port 40276.

Upstream is a Go MudOS-v22 simulator with a browser client. This
project runs the mudlib on FluffOS telnet. In-game text is Traditional
Chinese (`look` / `info` / `quit`). New characters start in 民雄鄉
(Minxiong / 打貓社) and travel between named historical sites.

## Registration flow

Language `1` English / `2` 繁體中文 / `3` 简体中文 → id → password →
nickname → race (`1`–`4`) → nature (`1`–`4`). The first player names
the mud and becomes god.

## Admin account

- **id**: `fluffos`
- **password**: `Mud@2026`
- **privilege**: first-player **god** (seeded)

Verified live: `2` → fluffos / Mud@2026 → 秦風 in 打貓社; `info`
shows level 1; `quit` saves and returns to the language prompt.

## Local run

```
cd libs/formosasaga
~/src/fluffos/build-debug/src/driver config.fluffos
```

Game port: **40276**. Setup after password can take several seconds.

```
python3 scripts/mudclient.py 127.0.0.1 40276 --timeout 70 --idle 8 \
  --send "2" --send "fluffos" --send "Mud@2026" \
  --send "look" --send "info" --send "quit"
```
