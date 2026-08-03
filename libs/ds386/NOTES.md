# ds3.8.6.zip → `ds386`

- Archive: `archives/ds3.8.6.zip` — **"Dead Souls" mudlib** (Nightmare-
  mudlib lineage), an English-language, generic (non-wuxia) codebase.
  Different from every other archive in this collection (all Chinese
  wuxia MUDs) — bundles its own fluffos-2.23-ds03 driver source plus
  Windows/binary distributions.
- Mudlib root: `ds3.8.6/lib/`. Config at `ds3.8.6/bin/mudos.cfg` (uses
  the modern `external_port_1 : telnet PORT` style, unlike every other
  archive's old `port number : PORT`).
- Port: **40007**.

## Status: PARTIAL — boots, admin setup wizard runs interactively; deprioritized per user direction ("ignore english libs, focus on chinese ones")

Confirmed: driver boots, listens, and the Dead Souls first-time
admin-account setup wizard runs and responds correctly to input
(username validation works). Not pursued to full completion/polish since
this project's actual priority is the Chinese wuxia archives. Left in a
working-but-not-exhaustively-verified state; safe to resume later if
ever wanted.

## What was fixed (real, reusable findings — kept even though deprioritized)

1. `TYPE array name` (bare, e.g. `object array foo`) doesn't work at all
   grammar positions in this driver (parameter lists, prototypes) even
   though it does in some. Blanket-normalized ALL 515 occurrences of
   `(int|string|object|mixed|float|mapping|buffer) array` → `\1 *`
   across the lib, plus the 2 bare-`array`-as-type occurrences → `mixed *`.
2. `#define __MAX_EVAL_COST__` and friends: Dead Souls bundled its OWN
   `secure/include/runtime_config.h` (a snapshot from its original
   `fluffos-2.23-ds03`), with a DIFFERENT `BASE_CONFIG_INT` computation
   than this modern driver's numbering scheme — `get_config()` calls
   returned wrong/empty values (`Bad argument 1 to /` dividing an empty
   string). **Fixed by replacing DS's copy with the driver's own
   canonical `~/src/fluffos/src/include/runtime_config.h`** (verified all
   but 5 rarely-used deprecated symbols still resolve; DS's original
   kept alongside as `runtime_config.h.orig_ds` for reference).
3. Dead Souls has NO uid/euid ownership model at all (no `ROOT_UID`/
   `BACKBONE_UID` concept anywhere) — but `PACKAGE_UIDS` is on in this
   driver build, and `set_master()`/`clone_object()` require
   `get_root_uid()`, `get_bb_uid()`, AND `creator_file()` to exist, else
   `exit(-1)` (confirmed: unlike some Chinese libs where this warning was
   non-fatal, here it was a REAL, immediate process exit) or every new
   connection fails with "No function creator_file() defined!". Added
   minimal stubs (all return `"ROOT"`) to `secure/daemon/master.lpc`.
4. `class TYPENAME array Foo(){...}` (custom class type + bare `array`) —
   a DIFFERENT grammar path than basic types, not covered by fix #1's
   regex. Only 2 occurrences (`lib/body.lpc`, `secure/daemon/finger.lpc`)
   but `body.lpc` is inherited by ~299 other files, so this ONE syntax
   error cascaded into 299 lpcc-sweep failures that all vanished once
   fixed. **High-leverage lesson**: when an lpcc-sweep error is IDENTICAL
   across dozens of unrelated-looking files, check whether they all
   share one inherited base file first, before assuming dozens of
   separate bugs.
5. **Found and partially reverted a real problem with my own fix #1's
   approach**: blanket sed-replacing `TYPE array` → `TYPE *` assumes
   EVERY comma-adjacent name in `TYPE * a, b` was meant to be an array,
   which is not always true (`string *shorts, cwd` — `cwd` was correctly
   scalar; `int *t, offset` — `offset` was correctly scalar). Caught via
   lpcc regressions (`wild_card.lpc`, `timestamp.lpc`) and reverted those
   2 specific instances by checking actual variable usage. **Not fully
   re-audited past those 2** given the deprioritization -- if resuming
   this lib, re-check the other ~31 files fix #1 touched the same way.

## Known remaining issues (not resolved -- deprioritized)

- 407 lpcc-sweep failures as of the last run (before the `class X array`
  fix, which should remove ~299 of these on a re-run — not re-verified).
  Remaining categories include a `SetLong(string str)` /
  `SetInternalDesc(string str)` parameter-type mismatch (documented as
  accepting `string | function` but declared as plain `string` in ~5-6
  base implementation files that many objects inherit — likely another
  high-leverage single-digit-file fix, NOT completed), missing `ed_cmd`/
  `ed_start`/`query_ed_mode` editor-integration efuns, and others not
  triaged.
- The first-time admin setup wizard was only smoke-tested (username
  prompt reached and validated), not driven to completion.

## How to run

```
cd libs/ds386
~/src/fluffos/build-debug/src/driver config.fluffos
# first connection ever triggers the Dead Souls admin setup wizard
python3 ../../scripts/mudclient.py 127.0.0.1 40007 --timeout 15 --send "admin" --send "pass" --send "pass" --send "quit"
```

## WASM 修复摘要（迁移自 meta.json 的 group_note）

英文版 Dead Souls；已降级/部分处理。
