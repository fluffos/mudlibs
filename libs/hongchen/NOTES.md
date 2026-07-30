# 红尘.rar → `hongchen`

- Archive: `红尘.rar` (from the 2026-07-29 bulk `mudlib.rar` drop). ES-II
  lineage ("change by Fan@wanxia" per `master.c`'s header), standalone
  "红尘录" (Chapters of the Red Dust) wuxia game.
- Mudlib root in archive: `hc/hc/` (two levels down; the outer `hc/`
  also has a `MUDOS.EXE`, a `架站帮助.txt` (setup help) and `小熊泥苑.txt`
  — the "小熊泥苑" hosting-site branding also seen on `bxsj`/`shujiantianxia`).
- Ships `config.hc` with the usual stale Windows absolute paths.
- Port: **40107**.

## Status: DONE — boots clean, full registration with a real Chinese name verified, playable

## What was fixed

1. Standard encoding + `.c`→`.lpc` rename via `convert_lib.sh`.
2. **New instance of AGENTS.md §4.3's shim-collision class**:
   `adm/obj/master.lpc` (and 4 other files sharing the same header) had
   `#ifndef __SENSIBLE_MODIFIERS__ / #define nosave static / #define
   protected static / #endif`. The blanket `static`→`nosave` sed turned
   this into `#define protected nosave` — silently aliasing `protected`
   to `nosave` even though both are real, distinct keywords on this
   driver. Deleted both now-nonsensical `#define` lines (`nosave nosave`
   / `protected nosave`) from all 5 affected files (`include/globals.h`,
   `adm/obj/master.lpc`, `adm/obj/simul_efun.lpc`, `adm/obj/
   simul_efun.ahxia.lpc`, `adm/obj/simul_efun_bak.lpc`).
3. **§8.1 class**: `adm/simul_efun/chinese.lpc`'s `is_chinese()` (GBK
   byte-range test) and `adm/daemons/logind.lpc`'s `check_legal_name()`
   (byte-oriented 2-10 bound + `i%2==0` window, message said "1 到 5 个
   中文字") — standard fix. Verified: real Chinese name 秦风六 registers
   correctly end-to-end into the game world (武庙/Wu Temple).
4. `adm/daemons/network/dns_master` and `adm/daemons/ftpd` were actively
   preloaded — commented out per the standing no-sockets-package policy.
5. Admin seeding: registered `fluffos` through the normal flow, appended
   `fluffos (admin)` to `adm/etc/wizlist`. Verified: `update /adm/obj/
   master` succeeds as `fluffos` ("重新编译 /adm/obj/master.lpc：成功！").

## Compile sweep

10014 pass / 150 fail out of ~10164 files. All core system files
(master/simul_efun/logind/chinesed/securityd) compile and run correctly;
remaining failures are individual room/NPC/item content files, not
chased further per the standing "content bugs are logged, not
exhaustively fixed" convention. `adm/daemons/restartd.lpc` has a couple
of undefined-variable errors (`CALLOUT_INTERVAL`/`RESTART_INTERVAL`) —
non-fatal at boot (preload catches the failure), not fixed.

## Full registration/gameplay verification

New character with a real Chinese name (秦风六) registers end-to-end:
gender selection, attribute roll+confirm, email, into the game world at
武庙 (Wu Temple, with 诸葛亮/Zhuge Liang and a NPC magician present).
`look` and `score` (full character sheet: attributes, HP/food/water
bars, combat exp) both work correctly. `quit` drops starting items and
prints a clean farewell message with no errors.

## Not yet done (out of scope for this pass)

WASM export / GitHub Pages packaging — deferred to a later batch pass.
