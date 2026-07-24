# shujianpiaoling2 — 「书剑飘零」Ⅱ ("Stray Book & Sword" II)

Archive: `书剑飘零II .zip`. Port: 40031. Status: **done** (boots clean,
full registration flow verified end-to-end including a real Chinese
name).

## What this is

"【书剑飘零Ⅱ】", English tagline "Stray Book & Sword", credited to
"飞白工作室" (Feibai Studio), http://sjpl.sq.sh.cn. Mudlib root at the
archive top level (`config.wd` at the root, not nested in a subfolder).
Uses `adm/obj/{master,simul_efun}` — despite the similarly-named "书剑"
title, this is a genuinely **different, unrelated codebase** from
`shujian2008`/`shujiantianxia` (archives #35/#36, `adm/single/` layout):
different directory convention, no `named.c` daemon, and a `securityd.c`
with different internal logic. Don't assume shared lineage from a
similar Chinese title alone — always verify via layout/file diff.
~13,022 raw files, 12,349 after `.c`→`.lpc` rename.

## Fixes applied

1. **AGENTS.md §15h (GBK byte-range Chinese detection)**, standard
   shape: `adm/simul_efun/chinese.lpc`'s `is_chinese()` (GBK lead-byte
   range → CJK codepoint range) and `adm/daemons/logind.lpc`'s
   `check_legal_name()` (byte-count bound `< 2 || > 12` → character-count
   bound `< 1 || > 6`, removed the `i%2==0` even-byte-offset gate). The
   `name[i..<0]` slice syntax was already a clean single-character-to-end
   slice — no change needed there, unlike some other libs that used a
   multi-byte suffix relying on `is_chinese` reading only the first 2
   bytes.
2. **Proactively added `get_include_path()` to `master.lpc`** (the
   standard §15o/§8d shape) as cheap insurance, even though this specific
   symptom was never actually observed — the lib booted clean and the
   full registration flow worked without it being strictly proven
   necessary. Left in as prophylactic protection for any future
   mid-connection lazy compile.
3. **Confirmed NOT needed, verified via source reading rather than by
   hitting and diagnosing a crash**:
   - **§4** (lazy security-daemon load): `master.lpc`'s
     `valid_write`/`valid_read` already gate via `find_object(SECURITY_D)`
     only (no unconditional `load_object`).
   - **§15n** (custom-securityd func-discrimination gap): this lib's
     `securityd.c`'s `valid_read` does NOT override the `user` parameter
     with `this_player()` (unlike `shujian2008`'s), so compile-time reads
     (which the driver attributes to `master_ob`, per
     `check_valid_path(..., master_ob, "load_object"/"include", ...)`)
     see `master_ob`'s own euid — presumably Root — and hit this
     `securityd`'s early `if (euid==ROOT_UID) return 1;` check before any
     directory-based ACL is even consulted. Confirmed by reading the
     source rather than needing to reproduce the crash first, per the
     lesson learned on `shujian2008`.

## Re-verification pass (2026-07-23) — found and fixed a §15w-class bug

The original pass above never tested a post-login command. Re-testing the
full flow through `look`/`score`/`quit` found `adm/obj/master.lpc`'s
`log_error()` unconditionally broadcasting every compile *warning* (not
just real errors) to the connected player — wizards saw `编译时段错误：...`,
and ordinary players saw an even vaguer but equally alarming
`你发现事情不大对了，但是又说不上来。`("something's wrong, but I can't
say what") on literally every lazily-compiled file's first warning,
which in practice fired repeatedly right after registration and on every
`look`/`score` in a fresh session (AGENTS.md §15w). Fixed by gating both
branches on the message not containing `"warning:"` (still always logged
to file). **Also checked, not a live bug**: `feature/command_new.lpc` has
the exact §15ae `private nomask int command_hook` shape, but it's dead
code — nothing in the whole lib references `command_new` by path; the
actually-inherited command feature (`F_COMMAND` = `feature/command.lpc`,
confirmed via `std/char.lpc`) already declares `command_hook` as plain
`nomask`, no `private`. Verified via 2 full registration sessions
(id `sjplhh`/`sjplii`, real Chinese names `秦风十四`/`秦风十五`) that
`look`/`score`/`quit` all produce correct real output with zero spurious
"something's wrong" messages after the fix. `debug.log` clean of
`denied`/`cannot`/`undefined function`/`error in error handler` in both
sessions.

## Interactive test result — full registration flow (original pass)

Verified the complete registration path in one continuous connection:

1. `sjplbtest` → passes `check_legal_id`, reaches the "确定吗(y/n)？"
   confirmation.
2. `y` → reaches the Chinese-name prompt.
3. **Real Chinese name `秦风`** → accepted (no rejection message),
   proceeds straight to "请设定您的密码：" — the actual proof the §15h
   fix works. No novel-character-name restriction found in this lib's
   `banned_name` list (unlike `shujian2008`) — just game-title words
   ("书剑", "书剑飘零", "飘零", "飞白") and pronouns.

## lpcc sweep

12,349 files, 11,772 pass / 577 fail (95.3%). Failure tail is the usual
shape (a large syntax-error cluster, missing `MONEY_D`/`prepare_skill`
globals, a handful of type-mismatch returns) — not triaged individually
per AGENTS.md §6b/§13, boot + full interactive registration test is the
verification gate. Memory stayed healthy throughout (~15GB free
consistently, no pressure).

## Rebuilt-driver / formatter / WASM re-verification pass (2026-07-23)

1. **LPC formatter** applied across all 12,349 `.lpc` files in `work/`:
   `{"total":12349,"written":12291,"wouldChange":0,"unchanged":4,
   "errors":54}`. Verified post-format that `feature/command.lpc`'s
   `command_hook` is still plain `nomask` and `master.lpc`'s §15w
   `strsrch(message, "warning:") == -1` guard is intact.
2. **Native re-test against the rebuilt `build-debug/src/driver`**:
   booted clean (zero fatal errors). Full registration verified
   end-to-end via `mudclient.py`: id `sjplfmtc` → confirm → real Chinese
   name **`秦风廿二`** → password ×2 → email `abc@abc.com` → gender `m`
   → birth-family choice `0` (书香门第) → entered the game world at
   民居, `look` displayed the room, `score` showed a correct character
   sheet (才智/体质/... matching a 书香门第 background), `quit` dropped
   items and printed "欢迎下次再来！". `debug.log`: zero `error in error
   handler`/`denied`/`undefined function`/`bad argument` lines. (Noted
   in passing, not a regression: `get_name()`/`get_resp()` in
   `logind.lpc` both contain a pre-existing `printf("%O\n", ob);`
   debug leftover from the original archive that echoes the login
   object's `/obj/login#N` identifier to the player right after a valid
   Chinese name is entered — harmless, doesn't block registration,
   present before this pass and left as-is per the project's "don't fix
   unrelated cosmetic content" convention.)
3. **WASM test**: boots cleanly (only the expected non-fatal preload
   noise — an `Invalid utf8 string while restoring emote` on
   `restore_object()`, same class of harmless save-data quirk as other
   libs, and the usual missing-sockets-package compile errors for any
   network daemons). **Full registration completed successfully under
   wasm**: id → confirm → Chinese name → password ×2 → email → gender →
   birth-family choice → entered 民居 → `look`/`quit` both produced
   correct real output, ending with the same "欢迎下次再来！" farewell as
   the native session. This lib has **no IP-format-dependent login gate**
   (no `sited`-style `query_ip_number()` check blocking new
   connections), so it is **fully playable under wasm**, unlike several
   sibling libs in this batch — the best-case wasm result observed this
   pass.

## WASM-enablement pass (2026-07-24)

Standard four-change pass (AGENTS.md §1.3b/§1.3e/§1.5):

1. **Loopback-allow**: `adm/daemons/logind.lpc` `logon()` (~line 74) —
   the `BAN_D->is_banned(query_ip_name/query_ip_number)` gate is skipped
   when `query_ip_number(ob)` is empty/non-string/`127.*`.
   `adm/daemons/band.lpc` `is_banned()` also short-circuits to 0 for
   loopback/localhost/malformed sites.
2. **Uptime gate / anti-flood throttle**: none present at connection
   time (the per-command flood counters in `feature/alias.lpc` are
   in-game robot protection, left alone per the KEEP-content-timers
   rule).
3. **Admin seeded**: `fluffos` / `Mud@2026` / 浮浮 → `(admin)` appended
   to `/adm/etc/wizlist`. Save files: `work/data/login/f/fluffos/fluffos.o`
   and `work/data/user/f/fluffos/fluffos.o` (per-id subdirectory layout;
   data/ not gitignored). Verified: login shows 目前权限：(admin);
   `update /cmds/usr/score.lpc` → 成功; `cd`/`whoami` work.
   Gotcha discovered while verifying: `update` on its OWN file
   (`/cmds/wiz/update.lpc`) silently no-ops — main() destructs the
   command object it is executing from before reaching the write();
   original behavior, not a bug introduced here.
4. Retest: fresh registration (sjplqf/秦风, deleted after test) into the
   start room with look/score/quit OK. debug.log: only pre-existing
   noise (`restore_object(): Invalid utf8 string ... emote` from
   emoted.o — known; `/cmds/wiz/tail` uses the never-existed `tail()`
   efun (§6.2 class) — pre-existing, hit only by my probe command).

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
