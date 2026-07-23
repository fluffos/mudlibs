# chongchujianghu_linux_src — archive #88 (重出江湖完整源码linunx_2.71原版.rar)

## Status: **not mudlib** — no FluffOS/LPC pipeline work possible

This archive is **not an LPC/MudOS/FluffOS mudlib**, despite its title
claiming "complete source code, Linux, v2.71 original" and despite its
directory layout at first glance strongly resembling a classic wuxia LPC
mudlib (`d/` per-city zone folders, `npc/`, `item/`, `std/`, `daemons/`,
`combat/`, `table/`). It is the genuine **C++ source** for the same custom
engine already established as non-LPC for archives #86/#87
(`libs/chongchujianghu/NOTES.md`, `libs/chongchujianghu_win/NOTES.md`) — a
bespoke, natively-compiled game server that *imitates the LPC
zone-file-per-room/skill/npc authoring convention using C preprocessor
macros over C++ classes*, and is built with a plain `g++`/`Makefile`
pipeline into a native ELF binary. There is no LPC virtual machine, no
`inherit` keyword, and no `.c`/`.lpc` LPC source anywhere in this archive's
5,961 files. Same category as archives #24, #31, #64, #86, #87 in
AGENTS.md's "Non-mudlib" list.

**This one deserves the closest look of the three "重出江湖" archives** —
its directory shape really is LPC-mudlib-shaped (this is presumably *why*
the archive is titled the way it is, and why #86/#87's cross-reference note
flagged it for extra scrutiny) — so the evidence below is deliberately
more thorough than usual.

## What's actually in `archives/重出江湖完整源码linunx_2.71原版.rar`

Extracted to `libs/chongchujianghu_linux_src/raw/` (5,961 files, much
larger than #86/#87 since this is a full source tree plus save-data plus a
prebuilt static library).

### Extension histogram (whole tree)
```
   5666 .h      <- "room"/"npc"/"skill"/"item" definition files (one per game object)
    139 .cpp    <- factory/aggregator files (one per zone/category, #includes the .h files)
     75 .txt
     45 .lgn    (login/password save files)
     28 .o      (save-data, LPC-style mapping-literal text)
      2 .rar
      1 .ini
      1 .c      <- daemons/skill/high_skill/shaolin/meifeng_dao.c (see below — still C++, not LPC)
      1 .a      <- libmudos.a, a 98MB prebuilt static archive (ar format, confirmed via `file`)
      1 .1      <- server/Item.cpp.1 (a backup/alt copy of Item.cpp)
```
**Not a single `.lpc` file.** The lone `.c` file is not LPC either (see
below) — it uses the exact same C++ macro convention as every `.h` file in
the tree, just with a `.c` extension by whatever mistake/convention its
author used.

### `grep -rIl "inherit" .` across all 5,961 files: **0 matches**
This is the single most decisive check for this archive, precisely
*because* its directory layout looks so LPC-like. LPC's `inherit` statement
— unavoidable in any real LPC object (`inherit ROOM;`, `inherit NPC;`,
etc.) — appears **zero times** anywhere in this entire 5,961-file, ~99MB
(counting `libmudos.a`) tree.

### The directory shape *looks* like LPC but is actually a macro-based C++ mimicry
Top-level of the extracted tree:
```
combat/  d/  daemons/  data/  item/  list/  log/  npc/  server/
setup_item/  setup_npc/  setup_room/  setup_skill/  sql/  std/  table/
config.h  datastruct.h  genconfig.h  libmudos.a  libmudos.rar  Makefile
说明.txt
```
`d/` contains ~65 per-city zone subdirectories (`beijing/`, `chang_an/`,
`huashan/`, `wudang/`, `shaolinsi/`, `xiaoyaogu/`, etc.) each full of
per-room `.h` files (e.g. `d/beijing/beijingcity.h`,
`d/beijing/beijing_qianzhuang.h`) — exactly the zone-folder convention used
by dozens of genuinely-LPC wuxia mudlibs already converted in this project.
`npc/`, `item/`, `std/`, `daemons/` are likewise organized the same way a
real LPC mudlib would be.

**But every one of these `.h` files is C++, not LPC.** Sample,
`d/beijing/beijingcity.h`:
```c
//beijingcity.h
//Sample for room:  北京饭庄
//coded by Fisho
//data: 2000-11-2

ROOM_BEGIN(CRbeijingcity);

virtual void create()
{
	set_name( "北京饭庄");
	add_npc("pub_kunlunnu");
	add_npc("pub_boy");
	...
	add_door("上北京城东", "东北京城", "北京饭庄");
	...
};

ROOM_END;
```
`ROOM_BEGIN(name)` / `ROOM_END` are **C preprocessor macros**, not LPC
syntax. Their expansion is defined in the C++ headers under `server/`, e.g.
`server/Npc.h`:
```c
#define NPC_BEGIN(npc_name)   class npc_name : public CNpc { public: \
    npc_name(){}; virtual ~npc_name(){}; ...
```
i.e. `ROOM_BEGIN(CRbeijingcity)` expands to `class CRbeijingcity : public
CRoom { ... virtual void create() { ... } ...`, straightforward C++
inheritance (`class X : public Y`), not LPC's `inherit` object model. Every
"room"/"npc"/"skill" file is a C++ class body wrapped in a macro to *look*
like a compact per-object definition, aggregated per-zone by a `.cpp` file
that `#include`s dozens of these `.h` files as raw text
(`setup_room/beijing.cpp` `#include`s `../d/beijing/beijing_aobai.h`,
`..._dangpu.h`, etc. — 25+ headers) and is then compiled by `g++` as one
translation unit.

`std/Corpse.h` shows the same pattern used for "std" base classes:
```cpp
#include "../server/Char.h"
class CCorpse : public CChar
{
public:
	static CCorpse * MakeCorpse(CChar * victim, CChar * killer);
	virtual void heart_beat();
	...
};
```
Plain C++ interface header, MFC-flavored include guards
(`AFX_CORPSE_H__091ECDA0_79A7_11D4_98AB_0050BABC5212__INCLUDED_`), matching
the `stdafx.h`/MFC-guard style already identified in #86's cross-reference
of this same archive.

### The `Makefile` confirms this compiles with plain `g++`, producing a native binary
```makefile
all:
	g++ -g -D_REENTRANT -Wall -lresolv -lpthread -lmysqlclient -lnsl \
	    *.c ./server/*.cpp ./std/*.cpp ./client/*.c ./list/*.c \
	    ./setup_item/*.cpp ./setup_npc/*.cpp ./setup_room/*.cpp \
	    ./setup_skill/*.cpp -o test
...
lib:
	c++ -Wall -c -g -D_GNU_SOURCE ./server/*.cpp
	...
	ar r libmudos.a *.o
	c++ ... libmudos.a libmysqlclient.so -o esii
```
This is an ordinary `g++`/`ar` static-library build producing a native ELF
executable (`test`/`esii`/`lt`, depending on target) that links against
MySQL (`-lmysqlclient`), not a FluffOS/MudOS driver invocation of any kind.
`libmudos.a` (98MB, confirmed `current ar archive` via `file`) is a
prebuilt static archive of this exact same source, i.e. the archive ships
both source and a prebuilt binary blob of it — the name "mudos" here is
just this codebase's own internal branding, unrelated to the real MudOS
LPC driver lineage.

### The lone `.c` file is still C++, not LPC
`daemons/skill/high_skill/shaolin/meifeng_dao.c` uses `SKILL_BEGIN`/
`SKILL_END` macros, `virtual void create()`, `CMapping`, `CChar *`,
`Magic_t *`, `snprintf`, `Random()` — same macro-driven C++ convention as
every `.h` file, not LPC. (Text in this file is visibly corrupted/mojibake
under UTF-8, consistent with GBK-encoded Chinese source — but re-encoding
it wouldn't make it LPC; it would still be C++ needing g++, not `lpcc`.)

### `data/` — save-game state, same LPC-*looking* serialization format as #86/#87
`data/user/`, `data/login/*.lgn`, `data/npc/`, `data/room/`, `data/item/`,
`data/box/<1..25>` — same save-data shape as #86/#87, `.o` files containing
`save_object()`-style mapping-literal text. This is this compiled engine's
own serialization format (which happens to look LPC-flavored, same as
already noted for #86/#87), not evidence of an LPC interpreter — there is
no `.c`/`.lpc` anywhere that produced it, only this C++ codebase.

## Why no pipeline step could proceed

1. **Extract** (step 1) — done; see above (5,961 files).
2. **Convert `.c`→`.lpc`** (step 2) — **N/A**. The one `.c` file and all
   5,666 `.h`/139 `.cpp` files are C++, not LPC; there is nothing an
   LPC-targeted `.c`→`.lpc` conversion step could operate on.
3. **Port/`config.fluffos`** (step 3) — **not written**. Port **40081 is
   NOT consumed** by this archive.
4. **Proactive AGENTS.md fix patterns** (step 4) — N/A, no LPC source.
5. **Boot the driver** (step 5) — **not attempted**. There is no
   `master.lpc`/`simul_efun.lpc` entry point anywhere, and nothing here is
   valid LPC for `~/src/fluffos/build-debug/src/driver` to load. The only
   way to "run" this codebase is `g++`-compiling it into a native
   executable, which is out of scope for this project entirely.
6. **Registration-flow test via mudclient.py** (step 6) — **not
   possible**, same reason.
7. **`lpcc_check.sh` sweep** (step 7) — **not run**; not applicable since
   there is no LPC to sweep (and running an LPC compiler over 5,666 C++
   header files would simply fail across the board — not attempted, since
   the `inherit` grep already gives a decisive, cheaper answer).
8. **Kill driver** (step 8) — N/A, nothing was ever started.

No scratch files (`boot_stdout.log`, `trace_lpcc.json`, etc.) were created,
since no boot/compile step was ever attempted.

## Relationship to #86 and #87

Confirms the conclusion reached when #86 was processed (cross-referencing
this same archive without full extraction): `mud.exe` in #86/#87 is a
Windows/MFC-linked compile of this exact C++ codebase (or a close sibling
version — this archive is tagged "v2.71 original" and Linux-targeted,
while #86/#87 are Windows builds), not any MudOS/FluffOS-family driver.
The entire "重出江湖" family (#86, #87, #88) is now **confirmed** — not
merely suspected — to be a single non-LPC C++ game engine released three
times in different packagings (compiled-Windows-minimal, compiled-Windows-
complete-with-clients, and Linux-targeted C++ source respectively).

## Recommendation for TODO.md (not edited by this session, per instructions)

- Archive #88 (重出江湖完整源码linunx_2.71原版.rar): status **`not
  mudlib`** — genuine C++ source (5,666 `.h` + 139 `.cpp`, `g++`/`Makefile`
  build) for a custom macro-based game engine that imitates LPC zone-file
  conventions but contains zero `inherit` statements and no LPC syntax
  anywhere; not convertible by this project's pipeline.
- Port **not assigned/consumed** — next free port stays available for the
  next archive with actual LPC source.
- The "重出江湖" family (#86/#87/#88) can now be closed out as fully
  triaged and confirmed non-LPC across all three archives.

## Testing performed

None of the mandatory registration-flow / post-login-command tests
(§15ae policy) apply — there is no LPC driver to boot and no LPC code to
run; the only way to "run" this codebase is compiling it as a native C++
program, which is outside this project's scope. This is documented
explicitly rather than skipped silently: this lib is not "done", it is
**not a convertible mudlib at all**.
