# xo_final — 笑傲江湖最终版1.2 (The Smiling, Proud Wanderer — "Final" Edition)

Archive: `xo最终版1.2.rar`. Port: 40024. Status: **done** (boots clean,
full registration flow verified end-to-end including a real Chinese name).

## What this is

Same TMI-2/ES2 (Falcon) lineage as `xo` (#28), but the full, un-trimmed
"final" build — ~7,174 `.c` files vs `xo`'s 1395 "mini edition". Same
`secure/daemon/{master,sefun}` layout. A homebrew test-station banner
("自玩测试站... 本lib是在mini xo基础之上，全新设计开发而成") confirms this
is a fork built on top of the mini edition.

## Fixes applied

1. **AGENTS.md §4 (lazy security-daemon load)**: applied proactively to
   `secure/daemon/master.lpc`'s `valid_write`/`valid_read`, same shape as
   `xo`.
2. **AGENTS.md §15h (GBK byte-range Chinese detection)**: `secure/sefun/
   chinese.lpc`'s `is_chinese`, `system/daemon/band.lpc`'s `IsLegalName`,
   and `system/daemon/logind.lpc`'s length checks all fixed to the CJK
   codepoint range / halved character-count bounds, applied proactively
   from the catalog before first boot.
3. **New: "comment eats next line" typo**, found twice — a Chinese-text
   comment line with no leading whitespace runs `//` right into the start
   of the *next* physical line's code, silently deleting a function
   declaration and leaving a dangling `{`:
   - `system/skill/basic/kongshou.lpc`: `// ...int is_native_skill()\n{`
   - `d/menpai/shaolin/npc3/hui_quest.lpc`: `// ...if ( random(...) < 100 )`
   Both fixed by moving the comment to its own line above the code.
4. **Lossy GBK→UTF8 conversion corruption**: `convert_lib.sh`'s `iconv -c`
   pass silently drops genuinely-invalid byte sequences in some raw `.c`
   files, occasionally eating a string literal's closing quote (breaking
   syntax) and sometimes leaving behind invisible Unicode Private-Use-Area
   characters (``, ``) that defeat exact-string `Edit` calls.
   Surveyed the whole tree with `iconv -f GBK -t UTF-8` against the RAW
   pre-conversion files to find every instance (33 total flagged,
   most cosmetic/non-fatal); confirmed and fixed the ~8 in `system/skill`
   that actually broke compilation, reconstructing each closing quote
   from context (sibling "action"/"lian"/"zhaoshi" fields' patterns):
   `mohe-zhi.lpc`, `yuanyang-dao.lpc`, `taizu-quan.lpc` (two spots),
   `dagou-bangfa.lpc`, `dugu-jiujian.lpc`, `baye-zhui.lpc`. The two with
   hidden PUA characters needed Python line-index read/write instead of
   the `Edit` tool's exact-substring match.

## Interactive test result — full registration flow

Verified the complete registration path in one continuous connection
(critical per the user's explicit instruction not to stop at "reaches a
prompt"):

1. `new` → `欢迎光临笑傲江湖3` / English-name prompt.
2. English id (`myxoidfull`) → passes `IsLegalID`, reaches the
   "确定吗(y/n)？" confirmation.
3. `y` → reaches the Chinese-name prompt.
4. **Real Chinese name `赵云`** → accepted (no rejection message),
   proceeds straight to "请设定您的密码：" — this is the actual proof the
   §15h fix works, not just that the prompt renders.

Also confirmed (as expected, not a bug): empty input at the English-name
prompt triggers a polite disconnect; `BAN_D->IsTimeAllowed`'s anti-flood
throttle (3 real minutes between `new` registrations from the same IP,
enforced via an in-memory `NewIps` mapping in `band.lpc`, cleared by
restarting the driver) rejects a second `new` attempt from the same
source within the window with **no output at all** (`die()`'s error
message is commented out at `logind.lpc` — this is intentional silence,
not a swallowed error; don't mistake it for a bug when retesting).

## lpcc sweep

**Memory warning (new data point for AGENTS.md §6b)**: this ~7,174-file
lib drove the host to ~214MB free / 18.8GB RSS on the `lpcc` process
after ~12 minutes despite being far smaller than the previously-documented
"tens of thousands of files" nitan-family threshold — file count alone
does not predict memory blowup risk. Monitor `free -h`/process RSS on
*any* sweep, not just presumed-large ones, and kill proactively if
pressure gets severe. Reached a clean boot (zero compile errors in the
boot log) after the fixes above.

## 2026-07-23: driver rebuild retest + LPC formatter + WASM check

- **Formatter**: ran `tools/lpc-syntax`'s `format-corpus.mjs` over all
  7174 `.lpc` files in `work/`; 7154 written, 9 already-conformant, 11
  errors (files it refused to touch, expected/fine on legacy code).
  Confirmed the `__OLD_ED__`-compat rewrite in `system/feature/user/
  editor.lpc` and the (disabled) `private`/`nosave` compatibility shim
  in `include/globals.h` both survived the reformat unchanged in
  substance.
- **Native retest**: rebuilt `~/src/fluffos/build-debug/src/driver`
  booted clean (zero fatal `debug.log` errors). Ran a **full
  end-to-end registration + play session** in one continuous
  connection with a real Chinese name (赵云): English id `zhaoyun` →
  confirm → Chinese name → password → email → gender all completed,
  dropped into the newbie training area (新手培训站); `look` showed the
  correct room, `score` produced a correct full character sheet,
  `quit` correctly enforced the "10 real minutes before saving" gate.
  One operational note (not a bug): this lib's `BAN_D->IsTimeAllowed`
  anti-flood throttle (documented in the original pass) meant a second
  `new` attempt shortly after a first one from this same host got
  silently ignored — resolved by restarting the driver (clears the
  in-memory throttle map) rather than waiting out the real-time window.
- **WASM**: booted cleanly (only the expected non-fatal
  `socket_create`/`socket_bind`/`socket_connect` preload warnings from
  the missing `sockets` package). **Full registration + play flow
  completed successfully end-to-end under WASM** — real Chinese name
  赵云乙, English id/confirm/Chinese name/password/email/gender all
  completed, dropped into 新手培训站 exactly like the native run;
  `look` and `quit` both worked correctly (10-minute save gate
  correctly triggered its confirmation prompt). Notably, this lib's own
  `enter_world()`/registration chain — despite being near-identical in
  shape to its `xo` (#28) sibling's — does **not** exhibit the
  world-entry hang `xo` shows under the identical WASM harness (see
  `xo`'s own NOTES.md). **Verdict: fully playable under WASM**, no
  issues found.

## WASM-enablement pass (loopback-allow / gate bypass / admin seed)

Standard WASM-first pass per AGENTS.md §1.3b/e and §1.5. Gates patched
(all in `system/daemon/band.lpc`, the live BAN_D — `xoban.lpc` is
orphaned/unreferenced, left untouched):

- Added `IsLoopbackSite(string)` helper (loopback / empty / malformed-IP
  → local).
- `IsBannedSite()` (~line 126) — loopback short-circuit `return 0;`.
- `IsMultiLogin()` (~line 214) — loopback exempt (`return 0;` = allowed).
- `IsTimeAllowed()` (~line 244, the 3-minute per-IP new-registration
  throttle whose rejection used to look like a silent stall) — loopback
  exempt (`return 1;` = allowed). Verified: two back-to-back `new`
  registrations from 127.0.0.1 both succeeded.
- `logind.lpc`'s `LOGIN_DELAY` startup gate is compiled out (macro never
  defined) — noted, no change. `uptime() < 10` there is cosmetic banner
  text, kept. The 10-minute new-account quit-retention prompt is a
  content timer, kept per policy.

Admin account seeded: id `fluffos`, pw `Mud@2026`, name 浮浮, granted
`(admin)` via `fluffos (admin)` appended to `secure/etc/wizlist`.
Verified: real registration (new/fluffos/y/浮浮/pw×2/email/m → landed in
新手培训站, auto-save fired), relogin as fluffos →
`update /system/daemon/band` → 成功, `score` correct. Retest: two fresh
normal registrations (秦风 m, 秦岚 f) end-to-end; test char saves
removed; zero new debug.log errors. Note: this lib's email prompt
actually validates format — `a@b.c` is rejected, use a normal-looking
address. Save file: `work/data/user/f/fluffos.o` (NOT gitignored —
normal add, no force-add needed).


## Fail-closed retrofit for the loopback-allow gate (2026-07-24)

The loopback helper above was originally written matching the
project-wide convention at patch time (AGENTS.md §1.3b), which also
treated an empty/non-string/malformed `query_ip_number()` result as
loopback, defensively, because the WASM driver used to return garbage
there. That underlying driver bug is now fixed (fluffos commits
`e33bb5da` "fix: query_ip_number() returned uninitialized garbage under
WASM" and `007bb863` "feat: synthetic resolve() on WASM instead of
raising an LPC error", both 2026-07-23; the locally-built
`build-debug`/`build-wasm` binaries already postdate both commits), so
treating unparseable IPs as trusted is a fail-open gap with no remaining
justification. Retrofitted to fail-closed: loopback is now strictly
`ip == "127.0.0.1" || ip == "::1" || ip[0..3] == "127."` (with a
`stringp()` guard before the slice) — a malformed/empty IP now falls
through to the NORMAL gate instead of being treated as local. Retested
after tightening: fresh driver boot clean, `fluffos` loopback login and
its wizard `update` command both still work; zero new debug.log errors.
