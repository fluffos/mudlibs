# xo — 笑傲江湖迷你版 (The Smiling, Proud Wanderer — Mini Edition)

Archive: `xo.zip`. Port: 40023. Status: **done** (boots clean, connects,
plays through login into "create new character?" confirmation with zero
crashes).

## What this is

A different, smaller lineage from everything else processed so far in
this batch: `secure/daemon/master.c` header says "Original from TMI-2 and
ES2, Rewritten by Falcon 96-10-02" — TMI-2 ("The Mud International 2") is
another classic MudOS-era mudlib base, distinct from the "ES II"/nitan
families seen in archives #21-#26. Uses the `secure/daemon/{master,
sefun}` path convention (not `adm/obj/` or `adm/single/`). Small lib —
1395 `.c` files, "mini edition" as the name says. No `set`/`query`/
`delete` global simul_efun defined (like `rzrmud`/`xkx2001`) — every
object provides its own via inheritance, the architecturally correct
pattern (see AGENTS.md §15).

## Fixes applied

1. **AGENTS.md §4 (lazy security-daemon load)**: `secure/daemon/
   master.lpc`'s `valid_write`/`valid_read` called `load_object(SECURITY_D)`
   unconditionally on every single call (not gated behind `find_object()`
   first), wrapped in `catch()` but with no re-entrancy guard. Added the
   full guard (nosave flag + `find_object()` check before attempting
   `load_object()`) per the established §4 fix shape, applied proactively
   before the first boot attempt given the exact matching pattern.
2. **New bug (case-sensitivity, Windows-origin archive on a
   case-sensitive Linux filesystem)**: 3 files (`system/feature/char/
   command.lpc`, `cmds/arch/ll.lpc`, `cmds/arch/localcmds.lpc`)
   `#include <Action.h>` (capital A), but the actual file on disk is
   `include/action.h` (lowercase) — silently resolves on Windows'
   case-insensitive filesystem, hard-fails here. This was responsible for
   the overwhelming majority of the initial lpcc sweep's failures (762
   "Undefined class 'Action'" + 155 "Cannot #include Action.h" out of
   1395 files, cascading from just those 3 root includes via inheritance)
   — fixing the 3 `#include` lines dropped the failure count from 209 to
   72 in one shot (85.0% → 94.8% pass). Checked the whole tree for any
   other same-shape case-only filename mismatches (`find -iname` +
   case-insensitive dedup) — none found, this was the only instance.

## Interactive test result

Boots clean, connects; welcome message + "last modified 1999.11" credit
line render correctly, empty input at the username prompt correctly
triggers a polite disconnect ("欢迎下次再来" — not a bug), `new` +
a valid English name reaches the "create new character?" (y/n)
confirmation with zero crashes. Did not create a full character or play
further (out of scope).

## lpcc sweep

1395 files, 1323 pass / 72 fail (94.8%, after the Action.h fix). Remaining
72 failures are the usual long tail (a handful of syntax typos in
individual files, a few missing daemons like `TASK_D`/`SendToUser`/
`SendToMud` referenced but not present in this "mini" trimmed-down
archive) — not triaged individually, consistent with AGENTS.md §6b/§13.
