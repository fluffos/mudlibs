# chongchujianghu — archive #86 (重出江湖.rar)

## Status: **not mudlib** — no FluffOS/LPC pipeline work possible

This archive is **not an LPC/MudOS/FluffOS mudlib**. It is a compiled,
closed-architecture Windows MUD server ("MUDSERVER") built on a **custom C++
engine (MFC-based)**, completely unrelated to the LPC object model that every
other archive in this project uses. No `.c`/`.lpc` source of any kind exists
in this archive. This is the same category already documented in AGENTS.md's
"Non-mudlib / needs-triage files at repo root" section for archives #24
(TOMud_VC源代码.rar — MFC client) and #31/#64 (DikuMud/Merc/EnvyMud C
servers) — a different, incompatible server architecture, not something the
GBK→UTF-8/`.c`→`.lpc`/driver-compat pipeline applies to at all.

## What's actually in `archives/重出江湖.rar`

Extracted to `libs/chongchujianghu/raw/` (173 files). Top level is a single
`MUDSERVER/` directory containing:

- `mud.exe` — a **PE32 GUI executable for Windows** (`file` confirms; not
  ELF, not a MudOS/FluffOS driver binary of any kind). This is the compiled
  server itself, source not included in this archive.
- `MSVCRTD.DLL`, `MSVCP60D.DLL`, `MFCO42D.DLL`, `MFC42D.DLL`, `MFCN42D.DLL` —
  Microsoft Foundation Class (MFC) runtime DLLs the server links against,
  confirming this is a native C++/MFC Windows application, not an
  LPC-interpreting driver.
- `客户端/X-MUD文字版.exe` — a bundled Windows GUI **client** ("X-MUD text
  version"), another PE32 executable. `客户端/color.txt`, `Users.dat` are
  client-side config/data.
- `新手指南.rar` — just a `.chm` (Windows compiled help) newbie guide, not
  source.
- `说明文件.txt` (GB18030, decoded) — setup instructions: run `mud.exe`
  directly, default wizard account is ID `1`/password `12345`, regular
  characters are ID `1001`-`1050` (pre-made saves shipped in the archive),
  client connects to `127.0.0.1:6600`. Confirms port `6600` is hardcoded
  into the compiled binary (not configurable via any text config we can
  edit — there is no equivalent of `config.fluffos` here at all).
- `data/` — save-game state only: `data/user/<id>.o`, `data/login/<id>.lgn`
  (password files), `data/npc/*.o`, `data/room/*.o` (single file
  `佛山.o`), `data/item/*.o`, `data/bak/{0,1,2}` (empty), `data/box`
  (empty), `data/config.txt` (a tiny 4-line file: port `6600`, mud name
  `烟雨红尘` ["Misty Rain, Red Dust" — apparently this server's actual
  in-game/branding name, distinct from the archive's title "重出江湖"
  ["Return to Jianghu"]], and two numeric flags).

**Confirmed these `.o` save files ARE genuine LPC-style `save_object()`
mapping-literal text** (e.g. `data/user/1.o` contains
`(["learned":(["...":900,...]),"skills":(["unarmed":500,...]),"dbase":(["potential":123,...` —
recognizably the same "dbase"/skills/ES-II-lineage save shape seen across
dozens of other archives in this project) — so the **game world/ruleset**
behind this binary probably does descend from the same 金庸/wuxia LPC
mudlib gene pool as everything else here. But that doesn't help us: the
actual `.c` room/npc/skill definition files that produced this save-data
shape are simply **not present** in this archive — only the compiled
driver binary and its output data are.

## Why no pipeline step could proceed

1. **Extract** (step 1) — done; see above.
2. **Convert `.c`→`.lpc`** (step 2) — **N/A, zero `.c`/`.lpc` files exist**
   anywhere in the archive (`find raw -iname '*.c'` — empty).
3. **Port/`config.fluffos`** (step 3) — **not written**. There is nothing
   for `~/src/fluffos`'s driver to load; a `config.fluffos` pointing at an
   empty/non-existent mudlib tree would be meaningless. Port **40081 is NOT
   consumed by this archive** — it remains free for the next archive that
   actually has LPC source.
4. **Proactive AGENTS.md fix patterns** (step 4) — N/A, no LPC source to
   patch.
5. **Boot the driver** (step 5) — **not attempted**. `mud.exe` is a Windows
   PE32 binary; it cannot be executed by (or converted into) our FluffOS
   Linux driver build. There is no LPC entry point (`master.lpc`,
   `simul_efun.lpc`) anywhere to hand to `~/src/fluffos/build-debug/src/driver`.
6. **Registration-flow test via mudclient.py** (step 6) — **not possible**,
   same reason.
7. **`lpcc_check.sh` sweep** (step 7) — **not run**, there are zero
   `.lpc`/`.c` files under any `work/` tree (none exists) to sweep.
8. **Kill driver** (step 8) — N/A, nothing was ever started.

No scratch files (`boot_stdout.log`, `trace_lpcc.json`, etc.) were created,
since no boot/compile step was ever attempted.

## Cross-check against the two related archives already in the queue

Per the task's own framing, two more "重出江湖"-titled archives are queued
later (#87, #88) and were **not processed** this session — only their
top-level file listings were peeked at (non-destructively, `unrar lb`, no
extraction) to inform this note:

- **`archives/重出江湖WIN完全版.rar` (#87)** — listing shows the same shape
  as this archive: `MUDSERVER/data/...` (`.o` save files, `.lgn` login
  files, `config.txt`). Strongly looks like another binary+data-only
  "complete Windows version" release, **not source** either — but this
  session did not extract it or confirm whether it also bundles `mud.exe`
  further down the file list; **a later agent processing #87 should verify
  this explicitly before assuming it's identical to #86**.
- **`archives/重出江湖完整源码linunx_2.71原版.rar` (#88, "complete source
  code, Linux, v2.71 original")** — listing shows **genuine `.cpp`/`.h`
  files** (`setup_npc/NpcSetup.cpp`, `setup_room/beijing.cpp`,
  `setup_room/changan.cpp`, etc.). Pulled and inspected two of these files
  directly (`setup_room/beijing.cpp`, `setup_npc/NpcSetup.cpp`) to confirm
  what kind of "source" this actually is: **it is real, compiled C++ —
  `#include "stdafx.h"`, `#include "../std/RField.h"` /
  `"../std/resident.h"` / `"../std/FightRoom.h"`, `CNpc * LoadNPC_pub1(...)`
  factory functions, etc.** — an MFC-flavored native C++ room/NPC
  definition system (one `.cpp` file per city/zone, `#include`ing dozens of
  per-room `.h` headers), **not LPC** (no `inherit`, no `create()`-object
  model, no LPC syntax anywhere). This confirms `mud.exe` in #86/#87 is a
  compiled build of *this* C++ codebase, not a MudOS/FluffOS-family driver
  with a normal LPC mudlib on top.

**Conclusion for whoever picks up #87/#88 next: the entire "重出江湖" family
(archives #86, #87, #88) is very likely a genuinely non-LPC MUD
engine (custom C++/MFC), the same "confirmed not a mudlib, skip entirely"
category as archives #24/#31/#64 in AGENTS.md's non-mudlib list — not
merely "source missing from this particular archive."** #88 should still be
opened fully (not just listed) to double check there isn't an LPC mudlib
*layered on top of* the C++ engine somewhere in its tree (e.g. a scripting
subsystem) before finalizing that classification project-wide, but the
sampled files give no indication of one.

## Recommendation for TODO.md (not edited by this session, per instructions)

- Archive #86 (重出江湖.rar): status **`not mudlib`** (compiled Windows
  C++/MFC binary + save data only, no LPC source — see detail above).
- Port **40081 was NOT assigned/consumed** — the "next free port" should
  remain 40081 for the next archive that actually has LPC source, unless
  #87/#88 (once opened fully) turn out to need one.
- Flag: #87 needs its own extraction/verification (this session only
  listed it); #88 needs a fuller read before permanently classifying the
  whole "重出江湖" family as non-LPC, though current evidence strongly
  points that way.

## Testing performed

None of the mandatory registration-flow / post-login-command tests
(§15ae policy) apply — there is no driver to boot and no LPC code to run.
This is documented explicitly rather than skipped silently, per the
project's standing policy of never marking a lib "done" without real
verification: this lib is not "done", it is **not a convertible mudlib at
all**.
