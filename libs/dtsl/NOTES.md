# dtsl.rar → `dtsl`

- Archive: `archives/dtsl.rar` (3.4MB — "大唐双龙传"/"Twin Dragons of the
  Tang Dynasty", same "simple"/东方故事-ish lineage as lib #1
  (shanhaizhanshen) — `adm/obj/master.c`+`adm/obj/simul_efun.c` layout).
  **No config file shipped in this archive at all** — reused lib #1's
  `config.cfg` as a template (same lineage, same directive shapes) rather
  than reconstructing one from scratch.
- Port: **40008**.

## Status: DONE — boots clean, playable over telnet

Booted with **zero fixes needed on the first attempt** (matching lineage
to lib #1, and lib #1's proactive checks — no `load_object` in
`valid_read`/`valid_write`, `get_root_uid()` present — all held here too).

## What was fixed (all from the lpcc sweep, not the boot path)

1. Encoding: 6870 converted, 327 already UTF-8/ASCII, 377 skipped binary,
   4 lossy. `.c`→`.lpc`: 6521 files, 1037 refs auto-fixed. `static`→
   `nosave`: 87 files.
2. `F_UNIQUE` macro was referenced (`inherit F_UNIQUE;`) by ~91 clone
   item files but never `#define`d in `include/globals.h`, despite
   `feature/unique.lpc` (the file it should point to) existing —
   added `#define F_UNIQUE "/feature/unique.lpc"` alongside the other
   `F_*` macros. Fixed all ~91 files' "unexpected L_IDENTIFIER" errors
   in one shot (misleadingly, the error pointed at the NEXT line's
   `inherit F_UNIQUE`, since the undefined macro parses as a bare
   identifier where a string/path was expected).
3. 6 `clone/weapon/*.lpc` legendary-weapon files (`jin-sjian`, `shizi`,
   `feihuangshi`, `jinhua`, `sjian`, `feidao`) redundantly
   `inherit COMBINED_ITEM;` directly AND via `inherit THROWING;` (which
   already inherits `COMBINED_ITEM` itself) — a diamond that this driver's
   stricter `nomask` conflict detection rejects (`Illegal to redefine
   'nomask' function '_query'/'_delete'/'_set'/'weight'`), where an older/
   more permissive driver apparently just deduplicated it silently. Fixed
   by deleting the redundant top-level `inherit COMBINED_ITEM;` line (kept
   the one reached transitively via `THROWING`). **Gotcha while fixing**:
   these files use CRLF line endings — a `sed '/^inherit X;$/d'` silently
   no-ops on a line ending `;\r\n` because `$` doesn't absorb the `\r`;
   needed `/^inherit X;\r?$/d`.
4. `clone/weapon/sm_ding.lpc` (7th file in the same cluster) has a
   DIFFERENT, unrelated problem: `#include "/inherit/item/embed.h"`,
   which doesn't exist anywhere in this archive — genuine missing content,
   not fixed (not fabricating a header).

## Known remaining issues (documented, not fixed)

- 369 lpcc-sweep failures total (before the fixes above; not re-swept
  after — expect notably fewer on a re-run given F_UNIQUE alone likely
  accounted for close to a third of them). Not otherwise triaged past the
  categories above given time constraints.
- 3 `#include`-fragment false positives (`adm/simul_efun/{message,math,
  object}`, AGENTS.md §6b) plus one player-directory WIP file
  (`/u/fengfei/object`) under "Invalid simulated efunction override" —
  not investigated further (low priority, personal/test content).

## How to run

```
cd libs/dtsl
~/src/fluffos/build-debug/src/driver config.fluffos
python3 ../../scripts/mudclient.py 127.0.0.1 40008 --timeout 10 --send "" --send "look" --send "quit"
```
