# es1_win.rar → `es1_win`

- Archive: `archives/es1_win.rar` (10MB — "东方故事(蓝天)"/"Eastern Story
  (Blue Sky)". **东方故事 (Dongfang Gushi / "Eastern Story") is one of
  the foundational Chinese wuxia mudlib bases** — several other archives
  in this collection reference/derive from it (`东方故事二.rar` is a
  direct sequel; lib #1's includes mention it too).
- Mudlib root: `es1/` at archive top level. Config at top-level
  `config.cfg`.
- Port: **40009**.

## Status: DONE — boots clean, playable over telnet

Full flow confirmed: banner, "东方故事现在没人." (no one online) status
line, name-length validation, name re-prompt.

## What was fixed

1. Encoding: 8238 converted, 1674 already UTF-8/ASCII, 82 skipped binary,
   17 lossy. `.c`→`.lpc`: 6933 files, 1101 refs + 2 angle-bracket
   `#include<x.c>` refs auto-fixed.
2. `master.lpc`'s `domain_file()`: `explode("/", "/")` (called by the
   DRIVER ITSELF during its own bootstrap domain-assignment, per
   `mudlib_stats.cc`) returns a **zero-length array** in this driver
   rather than `({ "", "" })`, and the existing `if(!path) return
   "NONAME";` guard doesn't catch a non-null-but-empty array — `path[0]`
   threw "Array index out of bounds", failing master's own compile.
   Added `|| !sizeof(path)` to the guard.
3. `std/object/prop.lpc` had `#include </std/object/prop_logic.lpc>`
   (angle brackets, file in the SAME directory) — the exact §8d pattern
   from lib #3, but with an important addition to that lesson: **the
   `master::get_include_path()` fix does NOT help here**, because this
   particular file gets compiled during PRELOAD, before
   `compiler_vm_context` is set (confirmed via the driver source,
   `lexer_utils.cc`'s `init_include_path()`: "No VM context: keep the
   config-file include path as-is -- there is no master object to ask").
   `get_include_path()` silently never gets consulted for preload-time
   compiles. **Fixed by changing the include to quotes instead**
   (`#include "/std/object/prop_logic.lpc"`) — quote-style local-directory
   resolution doesn't depend on any master apply/VM context at all, so
   it's the more robust fix regardless of when a file happens to compile.
   Also added the `get_include_path()` apply to this lib's master.lpc
   anyway (harmless, helps genuinely-dynamic compiles), but the REAL fix
   for this specific case was the quote change.
   **This failed to reach the login prompt with NO error output at all**
   until traced with temporary `write("DEBUG X\n")` statements inserted
   into `logind.lpc`'s `logon()` — the actual error (`_query`/`_delete`/
   `_set` undefined, cascading from the broken include, inherited all the
   way from `/std/room/room` down to `/d/std/rooms/netdead`) was being
   thrown during the very first connection's `active_users()` call, and
   the DRIVER's own `new_conn_handler` catches ANY error escaping
   `logon()` and just silently disconnects the user with zero message —
   so a real compile-cascade bug during first-connect can look exactly
   like a hung/dead server with nothing in reach except the debug.log.

## Known remaining issues (documented, not fixed)

- 1260 lpcc-sweep failures (of 6933). A meaningful chunk (`inherit ROOM;`
  failing with "unexpected L_IDENTIFIER" in `d/noden/drow/*`,
  `d/noden/hawk/*`, `std/adt/iqueue.lpc`, and others) trace to files that
  rely on the auto-included `global include file` (`globals.h`) for
  macros like `ROOM`, but `globals.h`'s own `ROOM` definition is
  commented out with a DIFFERENT (stale/wrong) value than the real one in
  `include/mudlib.h` (`"/std/room"` vs `"/std/room/room"`) — so
  uncommenting it isn't a safe fix; the affected files are missing an
  explicit `#include <mudlib.h>` instead. Zone names (`noden`, `drow`,
  `hawk`) suggest legacy/template filler content possibly never used in
  the live wuxia game, not something actively maintained — not fixed
  given the scale (dozens of files, no single-point fix) and that it's
  off the critical boot/login path.
- Not otherwise triaged past a category scan given time constraints.

## How to run

```
cd libs/es1_win
~/src/fluffos/build-debug/src/driver config.fluffos
python3 ../../scripts/mudclient.py 127.0.0.1 40009 --timeout 10 --send "" --send "look" --send "quit"
```
