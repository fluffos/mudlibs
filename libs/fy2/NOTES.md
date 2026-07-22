# fy2.rar → `fy2`

- Archive: `archives/fy2.rar` (2.8MB — "风云再起Ⅱ"/"Storm Rises Again
  II", 河海大学计算机及信息工程学院/Hohai University). Mudlib root at
  `fy/fy/`, config in the same directory (`config.FY2`). Same `fy4`-style
  master.lpc lineage as fengyun434/fy2005 (default-allow `valid_override`,
  no `load_object` in `valid_read`/`valid_write`).
- Port: **40014**.

## Status: DONE — boots clean, playable over telnet

Zero fixes needed to boot — clean on the first attempt. Full login flow
confirmed (name-length validation, re-prompt).

## What was fixed

Nothing needed for boot. Routine conversion: `.c`→`.lpc` refs auto-fixed,
9 local angle-bracket includes converted to quotes automatically,
`static`→`nosave` (39 files).

## Known remaining issues

- 73 lpcc-sweep failures (of 2839, 97.4% pass) — not triaged given the
  small count; boot/login path unaffected.

## How to run

```
cd libs/fy2
~/src/fluffos/build-debug/src/driver config.fluffos
python3 ../../scripts/mudclient.py 127.0.0.1 40014 --timeout 10 --send "" --send "look" --send "quit"
```
