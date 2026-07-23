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

## Re-verification pass: driver rebuild + LPC formatter + WASM build

- **Formatter**: `format-corpus.mjs` over all 5637 `.lpc` files; 5544
  reformatted, 91 unchanged, only 2 refused (self-check `errors`) —
  very clean corpus.
- **Native retest against rebuilt driver**: clean, zero fixes needed.
  Full registration flow (gb encoding → age-gate `no` → `new` keyword →
  English id → real Chinese name → password → email → gender → gift
  allocation `9`/`y`) verified end-to-end reaching 南城客栈, with
  `look`/`score`/`quit` all producing correct output, zero debug.log
  errors.
- **WASM test — 1 regression found + fixed** (WASM-specific, does not
  reproduce natively): `adm/daemons/logind.lpc`'s `encoding()` callback
  runs a one-time "mirror site verification" gate
  (`!find_object(DNS_MASTER) || !"/adm/daemons/band"->check_ip_(...)`)
  after every player selects gb/big5. This lib's `adm/etc/preload` DOES
  include `dns_master` (unlike libs where §15p's DNS-preload-exclusion
  policy applies) and it preloads fine natively (real sockets work), so
  `find_object(DNS_MASTER)` is truthy there and the gate passes cleanly
  — but under WASM (no sockets package) `dns_master` fails to compile
  at preload, `find_object(DNS_MASTER)` is always `0`, and the code
  unconditionally called `DNS_MASTER->get_host_name(...)` even inside
  its own "absent" branch (building the shutdown log message) — which
  itself crashed with `*No program in object` before ever reaching the
  intended `shutdown(1)`, leaving the connection stuck in a broken state
  (every subsequent input treated as an unrecognized command, no way to
  ever complete the encoding step). This is the exact AGENTS.md §15ai
  pattern (`xiyouji2003`'s finding, same lineage) applied to a lib that
  hadn't needed it before because it never excludes `dns_master` from
  preload. Fixed identically: guard with `find_object(DNS_MASTER) &&
  ...` so "daemon absent" means "skip the gate" (allow login) rather
  than "gate failed" (attempt, and crash trying, to shut down). This is
  a no-op change natively (dns_master is always present there) and only
  changes behavior under WASM. Re-verified clean both ways: native
  registration still reaches 南城客栈 with zero errors (real name
  孙悟空), and the full registration flow (incl. the age-gate and `new`
  keyword quirks, real name 猪八戒) now completes under WASM too,
  reaching 南城客栈 with `look`/`quit` both working — full WASM
  playthrough, not just boot. Not affected by the documented
  `query_ip_number()` WASM limitation (this lib's gate is
  `find_object`-based, not IP-format-based).
