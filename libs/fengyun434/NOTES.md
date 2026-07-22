# fengyun4-3-4.rar → `fengyun434`

- Archive: `archives/fengyun4-3-4.rar` (6MB — "风云Ⅳ"/"Storm Riders 4",
  Sumxin Fengyun, `www.sumxin.com`). Mudlib root at `Fengyun/fy4/`, config
  at `Fengyun/bin/config.cfg`. Different lineage from the 东方故事/
  simple-style libs seen so far (its own `master.lpc` shape).
- Port: **40011**.

## Status: DONE — boots clean, playable over telnet

Zero fixes needed to boot — clean on the first attempt (checked
proactively for the known `load_object`/`domain_file`/angle-bracket-
include patterns beforehand; none present in this lineage). GB/BIG5
encoding-selection prompt (same legacy pattern as other libs), then full
login flow.

## What was fixed

Nothing needed for boot. Routine conversion only: encoding (8801
converted, 255 already UTF-8/ASCII, 151 skipped binary, 30 lossy),
`.c`→`.lpc` (8238 files, 465 refs auto-fixed), `static`→`nosave` (50
files, notably low ratio vs other libs of similar size — this codebase
barely uses the idiom).

## Known remaining issues

- 85 lpcc-sweep failures (of 8238) — 99% pass rate, the cleanest lib so
  far. Not triaged given the small remaining count and time budget; none
  blocked booting or the login flow.

## How to run

```
cd libs/fengyun434
~/src/fluffos/build-debug/src/driver config.fluffos
python3 ../../scripts/mudclient.py 127.0.0.1 40011 --timeout 10 --send "0" --send "" --send "quit"
```
(the `"0"` selects GB encoding at the legacy GB/BIG5 prompt)
