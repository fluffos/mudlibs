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

## Re-verification pass (2026-07-23) — ported shujian2008's two new bug fixes

The original pass above never tested a post-login command (same gap as
`shujian2008`'s original pass, since it predates AGENTS.md §15ae's standing
policy). Re-testing found this lib had the exact same TWO compounding bugs
already found+fixed in `shujian2008` this same pass (unsurprising, given
the byte-identical source): `feature/command.lpc`'s `private nomask int
command_hook(string arg)` (§15ae — `private` hides it from `add_action`'s
external dispatch on this driver) and `adm/daemons/commandd.lpc`'s
`sscanf(cmds[i]+"$", "%s.c$", cmds[i])` (§15ar — matches zero files after
the `.c`→`.lpc` rename, leaving the command table permanently empty).
Ported both fixes directly (drop `private`; `.c$`→`.lpc$`). Verified with a
full fresh registration (id `sjtxee`, real Chinese name `秦风十一`, male)
through to `look`/`score`/`quit`, all producing correct real output.
`debug.log` clean.

## Interactive test result — full registration flow (original pass)

Verified the complete registration path in one continuous connection:
id `tianxiab` → confirm `y` → password `Pass1234` (twice) → real Chinese
name **`秦风`** (an invented name, avoiding Jin Yong novel characters per
this game's own rule, same as verified on `shujian2008`) → accepted →
reached character attribute selection (根骨/膂力/悟性/身法 stat prompt).

## lpcc sweep

9,936 files, 9,860 pass / 76 fail (99.2%) — identical numbers to
`shujian2008`, as expected from identical source. Memory stayed healthy
throughout (~16GB free).
