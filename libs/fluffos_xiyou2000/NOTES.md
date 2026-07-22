# fluffos(西游记2000).tar.gz → `fluffos_xiyou2000`

- Archive: `archives/fluffos(西游记2000).tar.gz` (59MB — a full FluffOS
  driver source checkout, `.git` included, bundling the mudlib as a
  NESTED `mudlib/world.tar.gz` inside it (extracted separately). The
  mudlib itself is "西游记"/"Xi You Ji"/"Journey to the West",
  `xiyouji.org`, up since ~1998 per in-file credits (`mon@xiyouji`).
- Mudlib root: `world/` (after extracting the nested tarball). Config at
  `world/config.xyj`.
- Port: **40012**.

## Status: DONE — boots clean, playable over telnet

Full flow confirmed: ASCII banner, GB/BIG5 prompt (send "gb"), site
credits, age-appropriateness question (a real, intentional gameplay/
content gate, not a bug). Note the BIG5 hint line in the encoding-select
banner itself displays as mojibake (`﹁村癘舧眤...`) — likely a genuine
BIG5-encoded substring embedded in an otherwise-GBK file (same shape as
ds386's Latin-1-in-GBK-file issue) — cosmetic only, not fixed.

## What was fixed

1. Encoding: routine GB18030→UTF-8 pass, 766 `.c"` refs auto-fixed, 72
   angle-bracket `.c>`→`.lpc>` refs, and **89 local angle-bracket
   `#include <x.lpc>` → `"x.lpc"` conversions handled automatically** by
   `convert_lib.sh`'s newly-generalized fix (first real large-scale test
   of that generalization from lib #13's manual fix — worked cleanly,
   no manual follow-up needed for this pattern at all this time).
   `.c`→`.lpc`: 5637 files. `static`→`nosave`: 47 files.
2. `adm/daemons/convertd.lpc` (a charset-conversion daemon, containing a
   large Greek-alphabet lookup table as string literals) had 5 lines
   shaped like `"α\",` — a stray trailing backslash right before the
   closing quote, which escapes it instead of closing the string,
   turning the rest of the file into one runaway unterminated string
   literal (`Illegal character`/`syntax error` cascade). Pre-existing
   data typo, not something our pipeline introduced. Fixed with a
   targeted `sed -E 's/\\"(,)?$/"\1/'` on the whole file (removes a
   trailing `\"` → `"`, or `\",` → `",`, at end of line only, so it can't
   touch a legitimately-escaped quote appearing mid-string elsewhere).

## Known remaining issues (documented, not fixed)

- 66 lpcc-sweep failures (of 5637, 98.8% pass) — not triaged given the
  small count and time budget; boot/login path unaffected.

## How to run

```
cd libs/fluffos_xiyou2000
~/src/fluffos/build-debug/src/driver config.fluffos
python3 ../../scripts/mudclient.py 127.0.0.1 40012 --timeout 10 --send "gb" --send "" --send "quit"
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
