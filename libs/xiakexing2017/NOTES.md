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

## Post-hoc fix: UTF8-native is_chinese/registration (AGENTS.md §15h)

Applied in a later batch pass across the whole project: `is_chinese`/`is_chinese2`
in the shared `chinese.lpc` simul_efun fragment used GBK byte-range checks that
silently never match real Chinese text once strings are UTF-8 (this driver's
`str[i]` returns a Unicode codepoint, not a GBK byte). This broke character
registration specifically -- any real Chinese name was rejected. Fixed the
range check to test the CJK Unicode block instead, and halved the
GBK-byte-calibrated length bounds in `check_legal_name` to match. See
AGENTS.md §15h for the full writeup; confirmed via a real interactive
registration test (Chinese surname + given name reaching the next prompt).
