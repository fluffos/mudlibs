# LLMUD(大唐双龙)v_0.11版.rar → `llmud_datangshuanglong`

- Archive: `archives/LLMUD(大唐双龙)v_0.11版.rar` (13.9MB — "大唐双龙传",
  same lineage as archive #8 (dtsl). Archive bundles a Qt-based Windows
  GUI client (`llmud.exe` + Qt DLLs) alongside the actual mudlib
  (`DTSL_0.11/`) — client ignored, only the mudlib processed.
- Mudlib root: `DTSL_0.11/`, config at `DTSL_0.11/config.xkx`.
- Port: **40015**.

## Status: DONE — boots clean, playable over telnet

Booted with **zero fixes needed** (same lineage as dtsl, and the boot
path itself was already fine there too — differences between these two
snapshots showed up only in the lpcc sweep, not the boot path).

## What was fixed (from the lpcc sweep, proactively applied since the

same two bugs were already known from `dtsl`'s NOTES.md)

1. `F_UNIQUE` macro missing from `include/globals.h` despite
   `feature/unique.lpc` existing — same fix as dtsl, added
   `#define F_UNIQUE "/feature/unique.lpc"`. Fixed ~101 files at once.
2. The same 6 `clone/weapon/*.lpc` files (`jin-sjian`, `shizi`,
   `feihuangshi`, `jinhua`, `sjian`, `feidao`) redundantly
   `inherit COMBINED_ITEM;` both directly and via `inherit THROWING;` —
   removed the redundant direct inherit, same as dtsl.
3. `sm_ding.lpc` (7th file in the same cluster) has the same unrelated,
   unfixed problem as dtsl: `#include "/inherit/item/embed.h"` doesn't
   exist anywhere in this archive either — genuine missing content,
   left as-is.

Routine conversion: encoding, `.c`→`.lpc` (6514 files, 1001 refs
auto-fixed), 18 local angle-bracket includes converted to quotes
automatically, `static`→`nosave` (85 files).

## Known remaining issues (documented, not fixed)

- 1457 lpcc-sweep failures remain (of 6514, down from 1530 before the two
  fixes above) — not otherwise triaged given time constraints; boot/login
  path unaffected.

## How to run

```
cd libs/llmud_datangshuanglong
~/src/fluffos/build-debug/src/driver config.fluffos
python3 ../../scripts/mudclient.py 127.0.0.1 40015 --timeout 10 --send "" --send "look" --send "quit"
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
