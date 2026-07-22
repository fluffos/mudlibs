# MUD侠客行2017完整版.zip → `xiakexing2017`

- Archive: `archives/MUD侠客行2017完整版.zip` (4.7MB — "侠客行"/"Ode to
  Gallantry" [Jin Yong novel], 2017 complete edition, MudOS v21). Mudlib
  root at `xkx/` (archive top level), config at top-level `config.cfg`.
  Note: `xkx/` directory name here is coincidental — unrelated to the
  "xkx" zone-name reuse seen inside other libs' `/d/` trees.
- Port: **40017**.

## Status: DONE — boots clean, playable over telnet

Zero fixes needed — clean boot and full login flow on the first attempt.

## What was fixed

Nothing needed for boot. Routine conversion: encoding (3330 converted,
521 already UTF-8/ASCII, 59 skipped binary, 15 lossy), `.c`→`.lpc` (3266
files, 146 refs auto-fixed), 8 local angle-bracket includes converted to
quotes automatically, `static`→`nosave` (42 files).

## Known remaining issues

- 79 lpcc-sweep failures (of 3266, 97.6% pass) — not triaged given the
  small count; boot/login path unaffected.

## How to run

```
cd libs/xiakexing2017
~/src/fluffos/build-debug/src/driver config.fluffos
python3 ../../scripts/mudclient.py 127.0.0.1 40017 --timeout 10 --send "" --send "look" --send "quit"
```
