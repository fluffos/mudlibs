# longyunmeng_binary — 龙云梦-炎龙封印-二进制版 (archive #102) — confirmed NOT convertible

Archive: `龙云梦-炎龙封印-二进制版.rar` ("Flame Dragon Seal, binary version").
**Status: not mudlib source** (or more precisely: mudlib-*adjacent*, but not
convertible — see below). Extracted to `libs/longyunmeng_binary/raw/`. No
`work/`, no `config.fluffos`, no port assigned — do not attempt a boot here.

## What's actually inside

Root: `raw/xyzx/` (`config.jh` — a MudOS 0.9.20 config — plus `mudos.exe`
and a `ylfy/` subtree). 17,125 total files:

- **14,395 files under `ylfy/binaries/`** — compiled MudOS bytecode dumps
  (`"save binaries directory : /binaries"` in `config.jh`; confirmed via
  hex dump, every one of these starts with the literal 4-byte magic
  `MUDB`, e.g. `binaries/adm/obj/master.b` — this is MudOS's own binary
  program cache format for its specific VM/bytecode, NOT source, and NOT
  usable by FluffOS regardless of extension).
- **Only 2,013 real `.c` source files exist anywhere in the archive**, and
  critically: **`adm/obj/master.c` and `adm/obj/simul_efun.c` — the two
  files EVERY boot absolutely requires — do not exist anywhere in this
  archive**, only as compiled `.b` bytecode
  (`ylfy/binaries/adm/obj/master.b`, `.../simul_efun.b`). Every
  `feature/`, `std/`-equivalent (`inherit/`), and `adm/`-tree base class is
  similarly binary-only.
- The 2,013 `.c` files that DO exist are almost entirely two narrow
  categories: 1,500 auto-generated map/room files under `d/automap/*.c`
  (confirmed real LPC, `inherit ROOM;`, e.g. `d/automap/233.c`'s "迷雾森林"
  room) and 462 skill-description files under `kungfu/skill/*.c` (confirmed
  real LPC too, e.g. `whip.c`'s `inherit SKILL;`) — both categories
  `inherit` base classes (`ROOM`, `SKILL`) that themselves only exist as
  compiled `.b` bytecode in this archive, so even these 2,013 real source
  files **cannot be compiled standalone** — there is no `std/room`-
  equivalent source anywhere to satisfy the `inherit`.

## The archive says so itself

`ylfy/说明文档.txt` (the archive's own internal readme) states directly,
translated: *"This version is for internal use. It uses a specially
paired OS and LIB, running in a purely binary mode — most files are saved
`.b` files, with only a small number of `.c` files kept to allow dynamic
system calls... OS version: MudOS v22pre12 For Windows_Mysql_Bin. LIB:
夕阳再起之[炎龙封印]3.5. Last updated: 2006-03-20. By 龙云梦(Wenwu)."*

This is a deliberate compiled/binary distribution of a Windows-hosted
MudOS build wired to a MySQL backend — not a source release at all, and
not something any FluffOS conversion pipeline could act on even if the
`.b` format were reverse-engineered (it's tied to a specific MudOS
bytecode ABI, not portable to this project's driver in any form).

## Lineage (confirmed, ties directly into archive #103's writeup)

Top-level directory names `xyzx`/`ylfy` are the exact same "XYZX"/"YLFY"
pinyin-initial engine-family macros documented in `yanlongfengyin_xiaoao3`
(archive #68)'s and `longyunmeng` (archive #103, this archive's sibling
source-release)'s own NOTES.md — same author credit ("By 龙云梦(Wenwu)"),
same "夕阳再起/夕阳再现 之 炎龙封印" branding. This binary archive is a compiled
release snapshot of the SAME lib whose full source ships separately as
archive #103 (`龙云梦-炎龙封印源码版.rar`, "source code version") — which
was processed in full per the task brief's own instruction that the source
version is "very likely the genuine, complete LPC mudlib source, preferred
over the binary one" and should get the full pipeline instead. See
`libs/longyunmeng/NOTES.md` for that lib's complete writeup (port 40094,
status done).

## Disposition

No conversion attempted, per the task brief's explicit instruction: this
is flagged here (and should be recorded in `AGENTS.md`'s "Non-mudlib /
needs-triage" list by whoever next edits that file) rather than converted,
since archive #103 already supersedes it with genuine, complete LPC
source. Matches the same "compiled binary distribution, not source" shape
already documented for the `重出江湖` family (archive #86/#87), just with a
real, matching source-code sibling archive available this time (unlike
`重出江湖`, where no LPC source existed anywhere in the whole three-archive
family).
