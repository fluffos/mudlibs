# 红尘.rar → `hongchen`

- Archive: `红尘.rar` (from the 2026-07-29 bulk `mudlib.rar` drop). ES-II
  lineage ("change by Fan@wanxia" per `master.c`'s header), standalone
  "红尘录" (Chapters of the Red Dust) wuxia game.
- Mudlib root in archive: `hc/hc/` (two levels down; the outer `hc/`
  also has a `MUDOS.EXE`, a `架站帮助.txt` (setup help) and `小熊泥苑.txt`
  — the "小熊泥苑" hosting-site branding also seen on `bxsj`/`sjtx2`).
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

## WASM pass (follow-up)

Native boot above was already clean; the WASM sandbox surfaced two gaps
the native driver doesn't hit:

1. `include/restart.h` is genuinely empty (0 bytes) in both the raw
   archive and the converted source -- a pre-existing incomplete-source
   bug in the original codebase, not something the conversion lost.
   `adm/daemons/restartd.lpc`'s `SHUTDOWN`/`REBOOT`/`HALT`/
   `CALLOUT_INTERVAL`/`RESTART_INTERVAL` were all undefined as a result
   (previously masked because `restartd.lpc` fails to compile silently
   at preload and isn't load-bearing for boot). Reconstructed all six
   constants from the daemon's own usage.
2. `adm/daemons/logind.lpc`'s very first per-connection banner line used
   `socket_address(ob)` (sockets package efun, undefined on this driver)
   to extract the connecting port -- broke EVERY connection attempt
   under WASM. Switched to `query_ip_port(ob)`, already used elsewhere
   in this same codebase.

Also upgraded the admin wizlist entry from `fluffos (admin)` (seeded in
the native pass above) to `fluffos (boss)` -- this lineage's
`wiz_levels` ranks `(boss)` above `(admin)` as the actual top tier, and
`securityd.lpc`'s `trusted_read`/`trusted_write["/"]` both include
`(boss)`. Verified: `update /adm/daemons/securityd.lpc` succeeds as
`fluffos` ("重新编译 ... ：成功！").

LPC formatter run across all 10328 `.lpc`/`.h` files (10141 written).
Blind-spot check found 2 files with the classic stray-`\ n`/unquoted-
string corruption (`cmds/adm/hbless.lpc`, `d/city/diaoyuchi1.h`) and,
via a same-text-despaced-matches-old-file scan across all 112
formatter-touched files containing CJK-space-CJK sequences, 1 file with
confirmed genuine re-spacing corruption (`d/player/fyue_room.lpc`); all
3 reverted. The other 109 flagged files were pre-existing author
spacing, unchanged by the diff. Post-formatter: clean boot, zero compile
errors, registration and `(boss)` permission display both re-verified.

## Status: WASM playable

GitHub Pages packaging for this lib specifically is still deferred to a
later batch pass; the WASM boot/gameplay/admin verification above is
now complete.
