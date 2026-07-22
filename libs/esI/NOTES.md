# esI.rar → `esI`

- Archive: `archives/esI.rar` (10.2MB — "东方故事"/"Eastern Story", themed
  "屠龙之战"/"Dragon Slaying War" per the live banner; up since May 2001
  per its own credits). Same 东方故事 lineage as archive #12 (es1_win),
  different snapshot/branch.
- Mudlib root: `esI/` at archive top level. Config at top-level
  `config.cfg`.
- Port: **40010**.

## Status: DONE — boots clean, playable over telnet

Full flow confirmed: banner, staff/admin credits, uptime status,
name-length validation, name-not-taken confirmation prompt.

## What was fixed

Applied both fixes discovered on lib #12 (same lineage) **proactively**,
before the first boot attempt, since a quick grep confirmed both patterns
present in the raw archive:
1. `std/object/prop.lpc`'s `#include </std/object/prop_logic.c>` (angle
   brackets, local directory, reached via preload) — `convert_lib.sh`'s
   automated `.c>`→`.lpc>` fix only fixes the extension, not the
   bracket-vs-quote distinction, so this still needed the manual switch
   to quotes (`#include "/std/object/prop_logic.lpc"`) per AGENTS.md §8d's
   preload-timing addendum. **Worth teaching `convert_lib.sh` to convert
   local angle-bracket `#include`s to quotes automatically** the next time
   this pattern recurs in enough libs to justify it (seen twice now).
2. `master.lpc`'s `domain_file()` — same `explode("/", "/")` returning a
   zero-length array, `!path` guard not catching it — added
   `|| !sizeof(path)`.

Both fixes applied before ever attempting a boot; booted clean on the
first real attempt. Plus the routine per-lib steps: encoding (8471
converted, 1741 already UTF-8/ASCII, 107 skipped binary, 14 lossy),
`.c`→`.lpc` (7035 files, 1009 refs + 1 angle-bracket ref auto-fixed),
`static`→`nosave` (121 files).

## Known remaining issues (documented, not fixed)

- 1195 lpcc-sweep failures (of 7035) — not triaged past confirming the
  lib boots and plays; given the time budget across ~90 remaining
  archives, not chasing every failure category individually this time
  (same call as es1_win's NOTES.md documents for its own long tail).

## How to run

```
cd libs/esI
~/src/fluffos/build-debug/src/driver config.fluffos
python3 ../../scripts/mudclient.py 127.0.0.1 40010 --timeout 10 --send "" --send "look" --send "quit"
```
