# rzrmud — 大唐西游 YWX人造人 (Great Tang Journey to the West)

Archive: `rzrmud.20130220.tar.gz`. Port: 40020. Status: **done** (boots
clean, connects, plays through the age-verification gate, MOTD, username
validation, and into new-player registration with zero crashes).

## What this is

A different lineage from the "NT/nitan/Lonely" family (archives #21/#22)
— generic-looking MudOS 0.9.20-era mudlib, 9096 `.c` files, bundled with
prebuilt 32-bit Linux driver binaries (`driver`, `driver_2s_64bit_int`,
ignored — we use our own fluffos build). Archive nests the actual mudlib
root one level down at `rzrmud/world/`.

Notably, this lib's `adm/obj/simul_efun.lpc` does **not** define a global
`set`/`query`/`delete` at all (unlike the nitan family) — every object
that uses bare `query(...)`/`set(...)` relies entirely on its own
`inherit NPC;`-style base class providing them locally. This is the
architecturally *correct* pattern (see AGENTS.md §15's writeup of why the
nitan family's simul_efun-based version is broken on this driver) — no
`this_object()`-during-simul_efun-call trap here since the fallback path
essentially isn't used.

## Fixes applied

None beyond the standard mechanical pipeline (`convert_lib.sh`'s
encoding/rename/ref-fix/static→nosave passes). Booted clean and reached
deep into the login flow (age gate → MOTD → username validation → "new
player" registration sub-flow asking for an English name) on the **first
attempt**, zero runtime or compile errors in `debug.log`.

## Known content gap (not fixed — see AGENTS.md §13)

`scripts/lpcc_check.sh` sweep: 9096 files, 8865 pass / 231 fail (97.5%).
The largest failure clusters are a genuine but narrow content gap, not an
engine bug:

- **~55 files** under `d/kaifeng/npc/quest_*.lpc` (e.g. `quest_wr.lpc`,
  `quest_wp.lpc`) `#include` a shared `quest.lpc` fragment that calls bare
  `query("id")` and `::setup()`, but — unlike their sibling NPC files in
  the same directory (e.g. `chen.lpc`, which correctly has `inherit NPC;`
  before its own `#include "quest_ak.lpc"`) — these ~55 files have **no
  `inherit` statement of their own at all**, so there's no base class to
  provide `query`/`setup` and no simul_efun fallback either (this lib
  doesn't have one, see above). Nothing else in the mudlib references
  these files by path, so this can't be diagnosed as "meant to be
  `#include`d elsewhere instead" — it looks like a genuine omission in
  the original archive (a missing `inherit NPC;` line), scoped to one
  city's quest-giver NPCs. **Not fixed** — 55 near-identical one-line
  fixes for content in a single zone is out of proportion to this pass's
  goal (verify the engine boots/connects/plays); note here in case a
  future pass wants to batch-fix it (`sed` in `inherit NPC;` as the first
  line after any leading `#include <ansi.h>` for each affected file,
  verify each doesn't already get a base class some other way first).
- The remaining ~176 failures are a typical long tail (missing
  `#include` headers for specific quest content, a handful of genuine
  one-off syntax typos in individual room/npc files, a few raw non-UTF8
  bytes that survived the lossy encoding pass) — not investigated
  individually, consistent with AGENTS.md §6b/§13's guidance on sweep
  noise at this scale.

## Interactive test result

Connects, full ASCII-art banner renders, no crashes through: age-
verification prompt → MOTD/rules screen → username prompt (validates
length/alphabetic correctly) → "new" registration path → English-name
sub-prompt (also validates correctly). Did not create a full character
or play further into the game world (out of scope for this pass).
