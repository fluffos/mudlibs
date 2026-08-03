# sjtx2 — 「书剑天下」("小熊泥苑" snapshot)

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

## Rebuilt-driver / formatter / WASM re-verification pass (2026-07-23)

Same shape as `shujian2008`'s own re-verification pass this same day
(identical source, so identical results throughout):

1. **LPC formatter**: `{"total":9936,"written":9680,"wouldChange":0,
   "unchanged":102,"errors":154}` — identical summary to `shujian2008`.
   Confirmed the ported `command_hook` (still plain `nomask`),
   `commandd.lpc`'s `"%s.lpc$"` pattern, and `get_include_path()` all
   survived reformatting. **Same formatter bug as `shujian2008`** (see
   its NOTES.md / `tianxia/NOTES.md` for the full writeup — a bare
   `::fn(...)` immediately after `(` gets mis-lexed as a closure
   literal) hit in this lib's own byte-identical copies of
   `cmds/leitai/npc_leitai.lpc` and `d/tanggu/npc/npc_leitai.lpc`
   (`if(::move(dest, silently))`); hand-fixed identically. Re-verified
   via `lpcc_check.sh`: 9,860/9,936 pass (76 fail, matching the
   pre-format baseline), neither file in the failure log.
2. **Native re-test against the rebuilt driver**: booted clean (zero
   fatal errors). Full registration verified end-to-end: id `sjtxfmta`
   → password ×2 → real Chinese name **`秦风十八`** → attribute roll →
   email `test02@abcd.com` → gender `m` → entered the game world at
   武馆前院, `look`/`score`/`quit` all producing correct real output.
   `debug.log` clean (zero `error in error handler`/`denied`/`undefined
   function`/`bad argument`).
3. **WASM test**: boots cleanly (same caught `dns_master` preload
   failure as `shujian2008`, no sockets package under wasm). **Login
   blocked by the same documented `query_ip_number()` limitation** —
   this lib's `sited.lpc` is byte-identical to `shujian2008`'s, so the
   same `sscanf(ip, "%d.%d.%*d.%*d", ...) != 4` check rejects every
   login id under wasm with "对不起，这个英文名字不能从当前地址登录。"
   Not patched — known driver-side wasm limitation, not a mudlib bug
   (native login verified working above). See `shujian2008/NOTES.md`
   for the full technical writeup, not repeated here.

## WASM-enablement pass (2026-07-23)

Same codebase as `shujian2008` — its patched `adm/daemons/{logind,sited,
band}.lpc` were ported wholesale (files were byte-identical at HEAD) and
re-verified here. See shujian2008's NOTES for the per-gate detail:

1. Loopback-allow (empty/non-string/`127.*` IP): logind `logon()`
   flood cap, logind `get_passwd()` wrong-password per-IP lockout,
   sited `is_valid()` (the former WASM blocker + wizard address
   restriction), sited `is_multi()` throttle, band `is_banned()`.
2. Uptime gate: none present.
3. Admin seeded: `fluffos` / `Mud@2026` / 浮浮 → `(admin)` via
   `/adm/etc/wizlist` (was empty). Save files:
   `work/data/login/f/fluffos.o`, `work/data/user/f/fluffos.o`.
   Verified: login lands in 巫师休息室, `update /cmds/imm/update.lpc`
   succeeds.
4. Retest: fresh registration (sjtxqf/秦风, deleted after test) into
   武馆前院 with look/score/quit OK. debug.log: one pre-existing content
   error unrelated to login (`baoshid.lpc choose_baosi()` returns 0 →
   `call_other` on 0 when `/d/wudang/npc/th.lpc` loads — §7.14
   factory-call class, fires on random NPC load, also present before
   this pass).

### Retrofit: fail-closed loopback check (2026-07-24)

The loopback-allow gates above were originally written per the (now
superseded) defensive instruction to also treat an empty/non-string/
malformed `query_ip_number()` result as loopback, since older WASM
driver builds returned garbage. That driver bug is now fixed upstream
(`query_ip_number()`/`resolve()` return real values under WASM too), so
the "malformed IP = trust it" fallback was a fail-open bypass with no
remaining justification. Tightened every gate listed above to the
strict pattern: loopback is ONLY `ip == "127.0.0.1"`, `ip == "::1"`, or
a leading `"127."` prefix — a non-string/empty/malformed IP is now
treated as untrusted/remote and subject to the gate normally, not
silently allowed through. Retested: fluffos login (127.0.0.1, real
value under the current driver) still passes every gate; debug.log
stayed clean of `denied`/`undefined function`/`error in error handler`.

## WASM 修复摘要（迁移自 meta.json 的 group_note）

代码完全相同，只是"小熊泥苑"站点品牌不同。状态已从过时的 limited 修正——这份档案自己的 README 里从未记录过任何缺陷说明，本轮重新测试也没有发现：是 shiji（021）/shujian2008 的 Century 家族手足档案。管理员登录（fluffos/Mud@2026，先问 BIG5 字体）干净正常，"您目前的权限是：(admin)"。
