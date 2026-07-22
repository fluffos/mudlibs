# shujiantianxia — 「书剑天下」("小熊泥苑" snapshot)

Archive: `书剑天下.rar`. Port: 40030. Status: **done** (boots clean, full
registration flow verified end-to-end).

## What this is

The exact same underlying codebase as `shujian2008` (archive #35,
processed just before this one) — confirmed via `diff` that every core
`.c` file (`chinese.c`, `logind.c`, `named.c`, `master.c`, `securityd.c`,
`band.c`, `adm/etc/preload`) is byte-identical between the two raw
archives. Only runtime state differs (logs, save files, wizlist). This
snapshot is branded "小熊泥苑" ("Little Bear Mud Garden",
http://dtxy.126.com) rather than shujian2008's site branding, but it's
the same "「书剑天下」" ShuJian game — a genuinely different, non-
duplicate archive (different md5sum) worth its own entry, just not worth
re-diagnosing from scratch.

## Fixes applied

All 7 fixes already proven on `shujian2008` were **ported directly**
(copied from `libs/shujian2008/work/`) rather than rediscovered:
`adm/simul_efun/chinese.lpc`'s `is_chinese`, `adm/daemons/logind.lpc`'s
`check_legal_name` bound/gate fix + `gb_big5()`'s `catch()`-wrapping,
`adm/daemons/named.lpc`'s `valid_name` character-stepping fix,
`adm/daemons/securityd.lpc`'s `valid_read` §15n allowlist
(`load_object`/`recompile_object`/`include`), `adm/single/master.lpc`'s
§15o `get_include_path()` apply, and `adm/daemons/band.lpc`'s
`load_sites()` `catch()`-wrapping. See `libs/shujian2008/NOTES.md` and
AGENTS.md §15n/§15o for the full technical writeup of these bug classes
— not repeated here.

**Booted clean on the very first attempt** (zero errors), confirming the
ported fixes transfer correctly to a byte-identical codebase — a much
faster pass than `shujian2008`'s multi-round diagnostic process.

## Interactive test result — full registration flow

Verified the complete registration path in one continuous connection:
id `tianxiab` → confirm `y` → password `Pass1234` (twice) → real Chinese
name **`秦风`** (an invented name, avoiding Jin Yong novel characters per
this game's own rule, same as verified on `shujian2008`) → accepted →
reached character attribute selection (根骨/膂力/悟性/身法 stat prompt).

## lpcc sweep

9,936 files, 9,860 pass / 76 fail (99.2%) — identical numbers to
`shujian2008`, as expected from identical source. Memory stayed healthy
throughout (~16GB free).
