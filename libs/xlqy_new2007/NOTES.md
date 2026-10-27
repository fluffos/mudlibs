# xlqy_new2007 — 新仙侣情缘之飘渺纪元 (New Immortal Companion's Fated Love: Ethereal Era)

Archive: `xlqy_new2007.rar`. Port: 40022. Status: **done** (boots clean,
connects, plays through GB/BIG5 selection and into the age-verification
gate with zero fatal errors).

## What this is

"ES II mudlib" lineage again (`adm/obj/master.c`'s header comment:
"for ES II mudlib... rewritten by Annihilator"), same family as `rzrmud`
(#23) and `xkx2001` (#25). Archive extracts to a `复件 xlqy_new/`
("copy of xlqy_new") folder — note the leading Chinese text + space in
the directory name, handled fine by `convert_lib.sh`/`cp -r` as long as
it's quoted throughout.

**Found and fixed a real bug in `extract.sh` while processing this
archive**: the `.rar` extraction branch `cd`s into the destination before
referencing the (relative) archive path, so `unrar` couldn't find it and
silently produced an empty `raw/` while the script still reported success
(no `-e`, exit 0 either way). Fixed in `scripts/extract.sh` — `ARCHIVE` is
now resolved to an absolute path up front, and the script now checks
`raw/` actually has files and fails loudly if not, for any archive type.
See AGENTS.md's "Archive tooling" section for the writeup; this could in
principle have silently affected other `.rar` archives run through the
old script, though every previously-committed lib's `work/` already
passed its own boot test, so nothing already marked `done` is suspect.

## Fixes applied

1. **`extract.sh`** (see above — a tooling fix, not lib-specific).
2. **`adm/daemons/convertd.lpc:258`**: the exact AGENTS.md §8h stray-
   trailing-backslash-before-closing-quote typo in the Greek-alphabet
   conversion table (`"Ρ\",` → `"Ρ",` — this lib's specific character was
   Rho, not Alpha like the previously-seen instances), recurring for the
   third time in this "西游记/ES"-adjacent family (`xyj2000f`,
   `mhxy`, now here). This file has plain LF line endings (not CRLF like
   `mhxy`'s copy) — used `sed -i -E 's/\\"(,)?$/"\1/'` directly; **caught
   and had to correct a mistake**: initially reused the CRLF-safe pattern
   from AGENTS.md §8h verbatim (`s/\\"(,)?\r?$/"\1\r/`), which
   unconditionally appends `\r` in the replacement even when the original
   line had none, injecting a spurious `\r` into this LF-only file's one
   fixed line. Verified with `cat -A` before and after; stripped the
   stray `\r` back out. **Lesson for next time this recurs**: check
   whether the file actually has CRLF (`file <path>` or `cat -A` a
   sample line) BEFORE choosing which of the two sed patterns to use —
   don't default to the CRLF-safe one "just in case", since its
   replacement isn't actually conditional on the match.
   `convertd.lpc` is `#include`d into many other daemon files, so this
   one fix should improve the lpcc pass rate substantially (initial sweep
   pre-fix: 8845/9060 = 97.6%, with hundreds of the failures being
   "In file included from .../convertd.lpc" cascades — re-swept after
   the fix, see below).

## Observed but not diagnosed: one non-fatal runtime error during login

The connect-time banner sequence prints the configured `default error
message` string ("你发现事情不大对了，但是又说不上来。") once, between the
Beijing-time line (`chinesed.lpc`'s `bj_time()`) and the registered-
player-count line — i.e. some error is happening around
`logind.lpc`'s `UPTIME_CMD->report()` call, but it's evidently caught/
non-fatal (execution continues normally to the age-verification prompt
and beyond) and produced **no trace at all in `debug.log`** (same
silent-error shape as AGENTS.md §15d, though not chased down with the
same catch()-instrumentation technique here since it isn't blocking
anything). Flagging for whoever revisits this lib's `cmds/usr/uptime.lpc`
or `UPTIME_CMD->report()` next.

## Interactive test result

Boots clean, connects; ASCII-art banner + Chinese render correctly,
GB/BIG5 selection prompt works, uptime/registration-count lines print
(with the one non-fatal error noted above), reaches the age-verification
("are you a student?") gate with zero fatal errors. Did not proceed
further into character creation (out of scope for this pass).

## lpcc sweep

Initial sweep (before the convertd.lpc fix): 9060 files, 8845 pass / 215
fail (97.6%), with a large fraction of the failures being `convertd.lpc`
inclusion cascades. Re-run after the fix — see the fresh numbers in this
lib's `lpcc_fail.log` (not hand-copied here to avoid this note going
stale relative to the regenerable file itself).

## Post-hoc fix: UTF8-native is_chinese/registration (AGENTS.md §15h)

Applied in a later batch pass across the whole project: `is_chinese`/`is_chinese2`
in the shared `chinese.lpc` simul_efun fragment used GBK byte-range checks that
silently never match real Chinese text once strings are UTF-8 (this driver's
`str[i]` returns a Unicode codepoint, not a GBK byte). This broke character
registration specifically -- any real Chinese name was rejected. Fixed the
range check to test the CJK Unicode block instead, and halved the
GBK-byte-calibrated length bounds in `check_legal_name` to match. See
AGENTS.md §15h for the full writeup; confirmed via a real interactive
registration test (Chinese surname + given name reaching the next prompt).

## 2026-07-23: driver rebuild retest + LPC formatter + WASM check

- **Formatter**: ran `tools/lpc-syntax`'s `format-corpus.mjs` over all
  9060 `.lpc` files in `work/`; 9043 written, 6 already-conformant, 11
  errors (files the formatter refused to touch — expected/fine on
  messy legacy code, not chased individually).
- **Native retest**: rebuilt `~/src/fluffos/build-debug/src/driver`
  booted this lib clean (zero fatal errors in `log/debug.log`). Went
  further than the previous pass's testing (which stopped at the
  age-verification gate) into a **full end-to-end registration**: real
  Chinese name 秦淑, gb/no/new/english-id/Chinese-name/password/email/
  gender/gift-allocation (`9`+`y` confirm) all completed, landed in
  聚见亭; `look` showed the correct room, `score` produced a correct
  full character sheet, `quit` gave the correct farewell text. Zero
  `debug.log` errors this session — the previously-noted "one
  non-fatal unexplained runtime error during login" from the original
  pass did not reproduce here.
- **WASM**: booted cleanly under `build-wasm` (only expected non-fatal
  preload warnings). Full registration flow (real Chinese name 秦岚)
  completed successfully end-to-end under WASM too, reaching 聚见亭;
  `look`/`quit` worked correctly. Same cosmetic
  `query_ip_number()`-under-WASM glitch as its `xlqy_early` sibling
  (last-connected-address line shows a garbled/timestamp-like value
  instead of an IP) — non-fatal, doesn't gate login. **Verdict: fully
  playable under WASM.**

## WASM-enablement pass (loopback-allow / gate bypass / admin seed)

Standard WASM-first pass per AGENTS.md §1.3b/e and §1.5. Gates patched
(same shapes as sibling `xlqy_early`):

- `adm/daemons/band.lpc` — added `is_loopback_site(string)` helper
  (loopback / empty / malformed-IP → local) and short-circuit `return 0;`
  at the top of `is_banned()`, `create_char_banned()`,
  `is_strict_banned()`.
- `adm/daemons/logind.lpc` — added `is_loopback_conn(object)` helper and:
  - `logon()` reconnect-flood throttle (`last_ip==ip && time+10>time`,
    ~line 96) — loopback exempt.
  - `logon()` per-IP connection cap (`logon_cnt > 10`, ~line 113) —
    loopback exempt.
  - `encoding()` `!ip_name` destruct + dotted-quad char-loop validator
    (~lines 195-207) — wrapped in `if (!is_loopback_conn(ob))`; this was
    the WASM-fatal gate.
  - No `uptime()` startup-grace destruct gate; the `uptime()` at ~line
    155 is the 300s newid registration window (content) — left intact.

Admin account seeded: id `fluffos`, pw `Mud@2026`, name 浮浮, granted
`(admin)` via `fluffos (admin)` line prepended to `adm/etc/wizlist`.
Verified: real registration flow (gb/no/new/fluffos/浮浮/pw×2/email/m/
9/y → entered world), then relogin as fluffos → status `(admin)`,
`update /adm/daemons/logind` → 成功. Retest: fresh normal registration
(秦风, gender f) end-to-end with look/score/quit all correct; test char
save removed; zero new debug.log errors. Save file:
`work/data/user/f/fluffos.o` (NOT gitignored — orchestrator adds
normally, no force-add needed).


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

## 深度功能测试 / Deep functional test (2026-07-24)

First real *playthrough* pass on this lib (all prior passes stopped at
registration + `look`/`score`/`quit`; see AGENTS.md §10.7). Native driver
(`build-debug`), one continuous `scripts/mudclient.py` session per test
step (state persists across steps via the lib's own save/relogin path).

**Test character**: id `shenlim`, Chinese name 沐阳 (Muyang), password
`MudPass123`, email `shenlim@example.com`, gender male, gift allocation
accepted as rolled (体格20/根骨20/悟性25/灵性25). Final state left behind:
joined 东方武馆 (Dongfang Martial Hall, via 东方博玉's `ask boyu about
join`), learned 扑击格斗之技 (unarmed, level 1) from teacher NPC 东方聪
via the organic `learn unarmed from dongfang cong` path, `combat_exp` 6
(from one real fight, see below), one `粗布衣` (linen robe) in inventory,
died once and was successfully reincarnated (气/血 currently 重伤/受伤
from that), sitting at `聚见亭` (START_ROOM) after a final clean `quit`.
Save files: `work/data/user/s/shenlim.o`, `work/data/login/s/shenlim.o`
— kept intentionally as evidence of a working end-to-end playthrough.

### What was tested and confirmed working

- **Read `help newbie` first** (`work/doc/help/newbie`) — correctly
  described the actual starting flow (南城客栈 is flavor-text/legacy;
  the real, current onboarding path is 聚见亭 → `out` → 仙石 in 花果山)
  and named the real command set (`learn X from Y`, `wimpy`, `skills`,
  `fight`/`kill`).
- **Registration**: real Chinese name (沐阳), full flow (gb/big5 →
  age-gate → `new` → English id → Chinese name → password×2 → email →
  gender → talent roll `9`+confirm `y`) — reached 聚见亭, `look`/`score`
  both correct.
- **Exploration / navigation**: read room `.lpc` source
  (`d/ourhome/xiaoting.lpc`, `d/dntg/hgs/*.lpc`) to route from 聚见亭
  through `out` (→ 仙石/花果山, the actual "leave home, start the
  journey" transition — confirmed intentional, not a bug, via
  `work/doc/help/start`'s narrative text) through 后山小路 → 林间小路 →
  花果山 → 傲来国 → 北城门 → 北菀街 → 傲来台 → 东苑街 → 东方武馆, ~15
  rooms total. Compound diagonal exit names (`eastup`, `southdown`, …)
  initially looked like a rendering bug (`这里明显的出口是 eastup、down
  和 southdown`) but are a confirmed, lib-wide intentional convention
  (hundreds of legitimate uses across `work/d/`), not a bug.
- **Combat**: no dedicated safe-sparring dummy is actually reachable —
  `d/city/obj/muren.lpc` and `d/obj/misc/muren.lpc` (the stat-mirroring
  `accept_fight()` training-dummy pattern AGENTS.md §10.7 recommends
  looking for) exist but are never placed in any room's `"objects"` map
  (grepped the whole `work/d/` tree for both paths — zero references);
  orphaned/dead content, not chased further (content gap, not a
  programming bug). Used `help newbie`'s own recommended fallback
  instead — the weakest listed mob shape (`小猴子`/monkey,
  `combat_exp` 50, `daoxing` 0) at 后山小路 — `kill xiao houzi` produced
  a full real fight with correct turn-by-turn narration, skill-up
  message, and (since the character had no armor/skill yet) an actual
  **death**, which flowed into a full live test of the death/
  reincarnation system (see below) rather than a wimpy-flee.
- **Death/reincarnation**: `feature/damage.lpc`'s `check_gameover()` →
  `DEATH_ROOM` (`/d/death/gate`) → `d/death/npc/pang.lpc`'s
  `init()`-triggered `death_stage()` `call_out` chain (5 staged
  messages, 5s apart) → `reincarnate()` → move to `REVIVE_ROOM`
  (`/d/ourhome/kedian`, 荒郊小店) all fired correctly and automatically
  (no player input needed, matching the design). Confirmed the
  player's saved `startroom` field was **not** touched by any of this
  (`grep -o '"startroom"' work/data/user/s/shenlim.o` → no match, both
  before and after) — no instance of the AGENTS.md §7.24 death-code-
  overwrites-startroom bug class here.
- **Sect/faction join**: `ask dongfang boyu about join` (东方博玉,
  馆主/hall master, in 前厅) — age/combat_exp gate checked and passed,
  `wuguan/join` flag set, confirmed via the teacher NPC's `skills`
  command then unlocking (`只有巫师或有师徒关系的人能察看他人的技能`
  before joining → full skill list after).
- **Skill learning, organic teacher path**: `learn unarmed from
  dongfang cong` in 武馆教练场 — real skill-up message, `skills`
  confirms the new skill persisted.
- **Shop purchase**: `buy jitui from xiao er` in 荒郊小店 (`list`
  showed prices in 文钱/两银子, purchase correctly deducted mixed
  coin+silver currency) then `eat jitui` correctly raised the 食物 stat
  (confirmed via `hp`) and correctly refused once full
  (`你已经吃太饱了，再也塞不下任何东西了`).
- **Quit / relogin / state persistence**: clean `quit` → immediate
  `debug.log` grep (zero new `错误`/`error`/`Fatal`/`recursion` lines)
  → relogin confirms skill + inventory persisted (location resets to
  `START_ROOM` on a clean quit+relogin, since `startroom` was never
  explicitly saved by this character — confirmed this is the lib's
  actual intended behavior, not a bug: `cmds/usr/quit.lpc` never writes
  `"startroom"`, and no `valid_startroom`-flagged room's "make this
  home" command was ever invoked in this playthrough).
- **Net-dead (unclean disconnect) + reconnect**: tested both a prompt
  reconnect (well inside the 15s `do_net_dead` grace) and a reconnect
  after a real ~150s wall-clock wait (well past the grace, short of the
  600s `NET_DEAD_TIMEOUT`) — both correctly restored the exact prior
  room/state via `obj/user.lpc`'s `reconnect()` (`remove_call_out`s the
  pending dumps, prints `重新连线完毕`). No instance of the AGENTS.md
  §7.20/§7.21 void-parking or stuck-wizard-flow classes.
- **Full-duration net-dead timeout**: happened for real (if
  accidentally, from research time between test steps rather than a
  deliberate sleep) partway through this pass and **found the two real
  bugs below** — see write-up. Re-verified the fix afterward with a
  *deliberate*, short-duration repro (`NET_DEAD_TIMEOUT` temporarily
  patched from 600 to 20 in `include/user.h`, reverted immediately
  after — confirmed clean via `git diff` showing no residual change).

### Bugs found

**1. Fixed — `adm/simul_efun/message.lpc`'s `tell_room()` wrapper passes
a raw `int 0` as `message()`'s exclude argument on every 2-arg call.
This is AGENTS.md §7.12 ("Shared message/wrapper argument bugs"),
recurring on a new lineage — not a new bug class.**

- Symptom, found live: `debug.log`/stdout showed
  `执行时段错误：*Bad argument 4 to EFUN message() Expected: object,
  array, Got: int(0).`, thrown from `obj/user.lpc:236`'s
  `tell_room(environment(), ...)` inside `user_dump(DUMP_NET_DEAD)` —
  the exact same file/function AGENTS.md §7.12 already documents from
  `dtsl`'s deep functional test. Per that section, this abort happens
  in a `call_out`-driven context with no enclosing `catch()`, so it
  doesn't just log an ugly line — it **aborts the rest of
  `user_dump()`**, at minimum `case DUMP_NET_DEAD`'s follow-up
  `QUIT_CMD->main(...)` call right after it (the actual force-quit).
  Moments later in the same driver session, the whole native process
  **crashed** (see bug 2) — matching §7.12's already-documented
  escalation almost exactly (that section's own dtsl finding: "two
  characters hitting the aborted `user_dump()` at nearly the same real
  moment ... immediately followed by an actual native driver process
  crash — a C-level double-free abort ... inside
  `dealloc_object()`/`free_svalue()`"). This session had several
  overlapping net-dead/abandoned-registration connections in quick
  succession right before the crash (multiple registration attempts —
  `linqing`, `muyang`, `shenlin` — each left an interactive object
  net-dead when `mudclient.py`'s connection timed out), so the
  "multiple simultaneous aborted `user_dump()`s" precondition plausibly
  applies here too.
- Root cause: `varargs void tell_room(mixed ob, string str, object
  *exclude)` (`adm/simul_efun/message.lpc:48`) forwards `exclude`
  straight into `message("tell_room", str, ob, exclude)` — an omitted
  `varargs` array parameter is the LPC value `0`, not `({})`, and
  `message()` accepts an *omitted* 4th argument but rejects one
  explicitly passed as the wrong type. Every 2-arg `tell_room()` call
  site in the whole lib (717 total call sites of `tell_room(`, an
  unknown but nonzero fraction of them 2-arg) was a live, if
  intermittent, crash risk — not just the two in `user_dump()`.
- Fix (`adm/simul_efun/message.lpc:48-56`):
  ```lpc
  // BEFORE:
  varargs void tell_room(mixed ob, string str, object *exclude) {
    if (ob) {
      message("tell_room", str, ob, exclude);
  // AFTER:
  varargs void tell_room(mixed ob, string str, object *exclude) {
    if (ob) {
      if (!exclude) exclude = ({});
      message("tell_room", str, ob, exclude);
  ```
  Fixing the single shared wrapper (per AGENTS.md §7.12's own
  prescribed remedy) covers all 717 call sites at once, rather than
  patching individual call sites piecemeal (an earlier draft of this
  fix instead null-guarded the three `tell_room(environment(), ...)`
  call sites in `obj/user.lpc` directly — reverted once the actual
  root cause was traced to the shared wrapper, since a per-call-site
  guard would have left every *other* 2-arg `tell_room()` call in the
  lib equally exposed).
- Verified: reproduced-then-fixed via a deliberate, short repro —
  temporarily changed `include/user.h`'s `NET_DEAD_TIMEOUT` from `600`
  to `20`, rebooted, net-deaded `shenlim`, waited ~45s (past the 15s
  `do_net_dead` grace + 20s timeout). Pre-fix this reliably reproduced
  the exact `Bad argument 4` trace; post-fix (this wrapper patched),
  the same repro produced **zero** `错误`/`Bad argument` output, the
  character was cleanly force-quit (confirmed via a normal fresh
  relogin working immediately after), and the driver process stayed
  alive. Reverted `NET_DEAD_TIMEOUT` back to `600` immediately after
  (confirmed via `git diff` — no residual change) and did one final
  clean reboot + full relogin (`look`/`score`/`skills`/`i`/`quit`) to
  confirm the fix in isolation, zero new `debug.log` errors.

**2. Observed, not independently fixable at the LPC level — a genuine
native driver crash, matching AGENTS.md §10.8's already-cataloged
"driver-fatal ref-count-0 `free_svalue()` abort" class (third
corroborating occurrence, and — per bug 1 above — plausibly the exact
mechanism §7.12's own severity-escalation paragraph already predicts,
not a fresh mystery).**

- What happened: partway through this session (naturally, from an
  extended real-wall-clock gap between test steps rather than a
  deliberate wait — see AGENTS.md §10.7 checklist item 8's honesty
  requirement: this was NOT a scripted repro, it just happened), the
  driver's own stdout (captured to `/tmp/xlqy_new2007_stdout.log`,
  outside the repo) showed:
  ```
  执行时段错误：*Bad argument 4 to EFUN message()
  ...
  呼叫来自：/obj/user.lpc 的 user_dump() 第 236 行 ...
  ******** FATAL ERROR: FATAL: Object 0x55c032a76368 /std/skill ref
  count 0, but not destructed (from free_svalue).
  (current object was /d/ourhome/kedian2)
  ...
  crash() in master called successfully.  Aborting.
  ```
  The process exited outright — every connection dropped, `ss -tlnp`
  showed nothing on port 40022, the driver PID was simply gone.
  `debug.log` showed **zero** trace of any of this (same total
  silence AGENTS.md §10.8 already documents) — the only reason this
  was caught at all was having the driver's own stdout redirected to a
  file, per that section's own "actionable takeaway."
- Secondary, compounding finding matching AGENTS.md §7.11 (missing
  runtime directory): the driver's own crash handler
  (`adm/obj/master.lpc`'s `crash()` → `log_file("nosave/CRASHES", ...)`)
  itself failed with `*Wrong permissions for opening file
  /log/nosave/CRASHES for append. "No such file or directory"` because
  `work/log/nosave/` doesn't exist in this checkout — meaning even the
  driver's own attempt to leave a permanent crash record for next time
  silently failed too. **Not fixed as a committable change**: the
  entire `libs/*/work/log/` tree is gitignored project-wide
  (`.gitignore:12-14`), so creating this one directory locally doesn't
  persist past this session and isn't a real fix at the lib level —
  flagging for the orchestrator in case a project-wide fix (e.g.
  `scripts/pack_lib_for_web.sh` or a boot-prep step always `mkdir -p`
  `log/nosave/`) is worth doing centrally.
- Not fixed / not independently root-caused at the LPC level, same as
  the two prior §10.8 occurrences (`xjcq2000`, `shiji`) — this
  is a driver-level internal-consistency failure, not a mudlib source
  pattern. Bug 1's fix removes ONE plausible contributing trigger (the
  aborted `user_dump()` mid-execution) but is not proven to be the
  sole cause; re-verifying bug 1's fix in isolation (see above) did
  *not* reproduce the FATAL crash in a short (~45s) repro window, which
  is weakly consistent with bug 1 being at least a contributing factor,
  but 45s of post-fix uptime is nowhere near a rigorous disproof.

### Observed, deliberately not touched (out of scope: not a crash, not wrong behavior)

- `feature/damage.lpc:535` (and two identical copies,
  `feature/damagedie.lpc:217`, `u/dianel/damagedie.lpc:199`):
  `DEATH_ROOM->start_death(this_object())` calls a function that
  doesn't exist anywhere in this archive (`/d/death/gate.lpc` has no
  `start_death()`, grepped the whole lib). Confirmed harmless: a
  `call_other()` to an undefined function is a silent no-op on this
  driver (confirmed — zero `debug.log`/stdout trace during an actual
  live death), and the real reincarnation trigger already happens via
  a completely different path (`d/death/npc/pang.lpc`'s
  `init()`-triggered `call_out` chain, fired automatically when the
  ghost is moved into the room). Dead/vestigial code from an earlier
  version of the death room, not a functional bug — left alone per
  this pass's scope (programming bugs that actually crash or misbehave
  only, not speculative cleanup).
- One unrelated caught error surfaced ambiently during the same
  session, from a completely different, unvisited zone: `*Illegal to
  move or destruct an object (/d/moon/obj/luoyi#346) defining actions
  from a verb function(give teapot to fei zei) in
  object(/d/qujing/wuzhuang/npc/mingyue#144) which returns zero.` —
  this fired from ambient NPC/quest simulation in 五庄观
  (`d/qujing/wuzhuang/`), a late-game zone this playthrough never
  visited. Not chased — out of the tested path, and root-causing it
  properly would need a separate deep pass through that zone's own
  quest scripts.
- `d/ourhome/kedian.lpc:20` — the `"exits"` mapping's `sizeof() == 2`
  comment doesn't match its actual single `"south"` key. Stale comment
  from a prior edit, not a functional bug (the room's actual exits
  work correctly as coded) — left alone.

## WASM 修复摘要（迁移自 meta.json 的 group_note）

仙侣情缘 XLQY 基础版（2007）。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BBS_BOARD`、`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 40 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试第二轮 / Deep functional test round two (2026-08-15, post driver-upgrade re-test)

驱动于 2026-08-12 升级后的重测。标准检查清单发现并修复四处问题：

1. **`config.fluffos`**：`maximum evaluation cost` 从 `500000`（已知
   风险区间）提升到 `5000000`。
2. **`adm/obj/master.lpc::log_error()`（AGENTS.md §7.10 大小写坑的
   又一实例）**：判定用的是 `strsrch(message, "warning: ")`（小写
   w，且要求紧跟一个空格），而本驱动实际吐出的是大写
   `Warning: Unused local variable` 一类文字，逐字节对不上，等于
   完全没有过滤——每次惰性编译遇到警告都会把原始编译诊断广播给连
   线玩家。改成不含开头 w/W 的 `"arning:"` 子串匹配（§7.10 记录的
   标准写法，同时兼容大小写两种历史形态）。
3. **`adm/simul_efun/file.lpc`**：`log_file()` 没有 `assure_file()`
   目录预建保护，补上调用及前向声明；`cat()` 补上
   `read_file() || ""` 空值防护。
4. **`obj/user.lpc::reconnect()`（AGENTS.md §7.108，第十五条独立确
   认的血统）**：`adm/daemons/logind.lpc` 有同款 `exec(old_link,
   user);` 踢掉重复登录写法，`reconnect()` 缺少
   `enable_commands()`。按 §7.108 记录的写法预防性修复，现场用两个
   真实连线复现"保持第一个连线不断开→第二个连线登录→答 y 踢掉旧连
   线"验证：`score` 修复后立即正常显示完整角色档案。

`cmds/wiz/update.lpc`（§7.106）已经是正确写法，无需改动。

### 现场验证摘要

驱动干净启动，管理员 `fluffos`/`Mud@2026` 登录（GB/BIG5 选择→未成
年人关卡"no"→id+密码）确认 `您的系统权限目前是：(admin)`，
`update /adm/daemons/logind` 成功验证真实写入权限，现场未观察到编
译警告泄漏（确认 log_error 修复生效）。踢掉重复登录重连路径现场验
证通过（见上）。`debug.log` 全程干净（876 行，无真实错误）。

### 本轮修改的文件

- `config.fluffos`
- `work/adm/obj/master.lpc`
- `work/adm/simul_efun/file.lpc`
- `work/obj/user.lpc`

## §7.100 sweep (2026-08-19)

Fixed the corpus-wide `inherit ROOM; ... replace_program(ROOM);` redundant-replace bug (AGENTS.md §7.100). 337 live occurrences deleted: 336 via scripted sweep (`fix_710_room.py`), plus 1 hand-fixed roommaker-tool template (`obj/roommaker.lpc`, simple string-builder variant). 5 already-commented-out instances left untouched. No real `.lpc` source found under `work/data/`. Verified via `build-debug` driver boot: clean compile, port 40022 listening, zero new "cannot replace"/"cannot bind" debug.log lines.

## §7.30 uninitialized-mapping accessor sweep (2026-08-20)

Corpus-wide mechanical sweep of the `feature/skill.lpc` shared-lineage
bug (confirmed independently on `xiakexing2017`/`jqxz2015`/`haiyang2`
via round-four testing): 3 accessor(s) in this file returned a raw
never-initialized `mapping` instance variable (defaults to `int 0`,
not `([])`, until first assigned), crashing any unguarded
`keys()`/`sizeof()`/indexing caller for a fresh/untrained character.
Fixed at the accessor level (`mapp(x) ? x : ([])`) per the documented
remedy. Verified via `lpcc --batch` static compile check only (not a
live boot) as part of a large mechanical sweep; not individually
functionally re-tested live on this lib.


## AGENTS.md §7.19 fix: enable_player() reentrancy from init()

`feature/command.lpc`'s `enable_player()` (wrapper around
`enable_commands()`) was reachable from an NPC's `init()` (via the
shared `std/char.lpc` `setup()` chain), and `enable_commands()` is only
safe to call from `create()` -- calling it again on an object already
`living()` makes the driver re-invoke that same object's `init()` as a
side effect, which recursed back into `enable_player()` on the same call
stack until "Too deep recursion" aborted the boot on a room's first-ever
visit. Fixed with a true reentrancy flag (`in_enable_player_now`, set at
entry, cleared before every return), NOT a `living()`-gated guard --
`disable_player()` in the same file legitimately re-calls
`enable_commands()` while already `living()` (sleep/wakeup via
`cmds/std/sleep.lpc`, revive via `feature/damage.lpc`), which a
`living()` guard would silently break. Verified via `lpcc --batch`
single-file compile check (PASS). Part of the corpus-wide §7.19 sweep
(Batch C).

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.


## 深度功能测试（§10.7，2026-10-04）— undefined macro and simul_efun gaps

- 2 file(s) `inherit F_SSERVER;` and no header defines it (2 did not compile: `syntax error, unexpected L_IDENTIFIER, expecting L_STRING or '('`). `#define F_SSERVER SSERVER` in `include/globals.h` (KB 04 §6.2, `scripts/lpc_alias_macro.py`). 0 still fail.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 1 here-document block(s) repaired (1 with the terminator glued to the last text line, 0 with it indented), so `End of file in text block` no longer hides the room or object behind them: `d/moon/bedroom.lpc`. The terminator must start its line (the lexer's own test, KB 04 §6.10); a glued one lost its newline in the GBK -> UTF-8 conversion together with a half character, which stays out.

## 深度功能测试（§10.7，2026-10-04）— paths named in another case

The archive comes from a case-insensitive host: files are stored as `BAGUA0.lpc`, `longjing.C`, `d/SHAOLIN/`, the code names them in lower
case (`__DIR__ "bagua0"`, `"tea/longjing"`, `"/d/shaolin/..."`), so the rooms, NPCs and items behind them could not be loaded (a `.C` file is
not an `.lpc` file; KB 03 §4.5). `scripts/lpc_case_paths.py --convert --apply xlqy_new2007`: 1 file(s) renamed to lower case (`.C` -> `.lpc`,
`.H` -> `.h`) and 5 path reference(s) in 5 file(s) rewritten to the new spelling; 0 skipped, 0 ambiguous. Load check of the 5 objects that were renamed, edited or name a renamed path (HEAD against the working tree, an object is the same under any spelling of its path): 4 PASS -> 5 PASS, 0 that loaded before fail now, 1 more load.

1 files moved (1 `.lpc`); mostly under `adm/daemons/Diabloset.lpc` (1). A rescan with `scripts/lpc_warnings.py xlqy_new2007` is still due: the renamed files are compiled for the first time.

## 深度功能测试（§10.7，2026-10-05）— room base survives a raising NPC

`scripts/lpc_resilient_room.py --apply`: `make_inventory()` of `std/room.lpc` loads each inventory object as `if (catch(ob = new(file)) || !objectp(ob)) return 0;`. `new()` of a file that is not there returns 0 (the room just lacks that NPC), but `new()` of a file whose `create()` raises (a skill file for `set_skill()` this archive never had, a `carry_object()` item that is not there, a header that never shipped) raised inside the room and the room did not load at all. The wrong-case renames of this lib (the section above) make the NPCs behind them reachable for the first time, so a room that holds one with such a content gap would have gone from "NPC missing" to "room missing"; now it loads without that NPC, as it did before. The room base compiles and loads with the change (HEAD against the working tree). KB 03 §4.5.

## 深度功能测试（§10.7，2026-10-05）— tail() simul_efun

`scripts/lpc_add_tail.py --apply`: `cmds/wiz/tail.lpc` calls `tail(file)`, an efun of the MudOS this archive ran on that FluffOS does not have (`Undefined function tail`: the command did not compile). `adm/simul_efun/file.lpc` now defines `void tail(string file)`: the last 10 lines of the file, written to the player. Load check (HEAD against the working tree): 1 of the 1 tail command file(s) failed to load at HEAD, all load now, and the simul_efun file loads. KB 04 §6.2.

## 深度功能测试（§10.7，2026-10-05）— 任务表里的 `.c` 路径与任务守护进程的防护

`scripts/lpc_dynamic_quest_guard.py`：1 处 `spread_quest()` 调用（`init_dynamic_quest()` 的循环里）包进 `catch()`，缺失的任务物品或编译不过的房间只跳过那一个任务，守护进程照常加载、其余任务照常生成。
验证：改动过的 `adm/daemons/questd.lpc` 在新进程里加载，HEAD 通过 1 个、工作树通过 1 个（共 1 个），无回退。

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `std/room.lpc`：`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 OK，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-06）— 编译警告整理

先用 `scripts/lpc_twin_port.py adopt xlqy_early xlqy_new2007` 把 xlqy_early 同一提交里的改动搬到 731 个修改前与它一致的文件（112 个按块拼接；逐文件核对非 ASCII 文字：除 xlqy_early 自己删掉的以外没有丢失或改动）。剩下的再跑 `scripts/lpc_warnings.py xlqy_new2007 --fix`：无用局部变量 783 个、`varargs` 21 处、`nosave` 函数 5 个改 `protected` 等，共改动 984 个 `.lpc` 和若干 `.h`。HEAD 与工作树分别加载（新进程）：959 -> 959 通过，无回退；改过的头文件的 401 个包含者 385 -> 385 通过。
手工：`adm/daemons/logind.lpc` 有意用自己的 `localhosts` 地址覆盖 `include/mudlib.h` 的那个，前面补 `#undef localhosts`。

启动时警告 116 -> 0；新进程登录（编码选择、新人物提问）正常。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 21 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 9 个，只在 #if 分支用的声明移进分支 0 个文件；改动 28 个文件，HEAD 与工作树各载入一次无回退（28 objects; HEAD PASS 27, tree PASS 27; regress 0; newly loading 0），这些文件的警告 52 -> 22。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。21 个文件 45 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。
- 2026-10-14（同一次重扫，手工部分，与 wuhanzhan/xlqy_early 同源同修）：
  - `d/kaifeng/ground.h` 加 `GROUND_TABLES_INHERITED` 守卫；`colors.h` 加防重复包含。
  - `jiasha.lpc` 的 `init()` 先后调用 `cloth::init()` 与 `unique::init()`。
  - `yaoguai_type` 的重复声明去掉。
  - `feature/alias.lpc` 的 `last_time` 改名 `last_cmd_time`，与 `sanhua-counter` 自己存档的字段分开。
  - `lijing`/`xiwangmu` 的 `die`/`unconcious` 和 `yutu`/`jinren` 的 `kill_ob` 改 `void`。
  - `reporting.lpc` 各份删去未用的 `str`。
  - `std/equip.lpc` 的 `query_autoload()` 由 `int` 改为 `mixed`：物品子类返回自己的存档字符串。
  - `d/dntg/yunlou/npc/yaoguai.lpc` 灭妖奖励的倍率 `reward`（0.8、1.2、1.8、2.6、3.8）原声明为 `int`，小数被截掉；现改为 `float`，奖励用 `to_int()` 取整。**玩家可见**：七彩奖励按原倍率发放。
  - `cmds/arch/make_npc.lpc` 去掉字符串里多余的反斜杠。
  - 改动的 59 个对象 HEAD 与工作树各载入一次，无回退；定义 `query_autoload` 的 68 个文件重编译后没有警告。

- 2026-10-14：2 个文件用了颜色宏（`HIW`、`NOR`）却没有 `#include <ansi.h>`（首个错误 `syntax error, unexpected L_STRING`）；开头补上（KB 04 §6.1、§6.3）。新进程比对 HEAD 与工作树：2 个对象，新增载入 2，回退 0。

## 内力/精力当作伤害种类（2026-10-15，KB 06 §7.241 第二类）

本库 `feature/damage.lpc` 的 `receive_damage()` 不接受 `jingli`/`neili`/`force` 等种类，`me->receive_damage("jingli", 30)` 之类在练功、绝招、吸取时报 `F_DAMAGE: 伤害种类错误`。2 处改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py` 第二步）。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。2 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

1 个文件（技能、绝招、兵器、书籍、区域 NPC 等）来自侠客行体系（qi/jing/neili），而本库人物是 gin/kee/sen/force：`receive_damage("qi", ...)` 报 `伤害种类错误`，`query("neili")` 永远为 0。按 qi→kee、jing→sen（本库学习/读书指令消耗的就是它）、neili→force、max_neili→max_force、jiali→force_factor 改名（`scripts/lpc_port_es_props.py --any-file`）。

## 转码吃掉的引号（2026-10-15，KB 03）

原档在右引号前有一个孤立的 GBK 前导字节，转 UTF-8 时连引号一起丢了（如 `return name + HIM "发作身亡了;`），字符串一直延续到后面，文件编译失败：`/d/obj/books-nonskill/hmeng014`。补回引号（`scripts/lpc_fix_eaten_quote.py`）。

## iori-sword 取招越界（2026-10-15，KB 06 §7.243）

同 xlqy_early：`action[random(7)]` → `random(sizeof(action))`。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`zuixian-steps`→`zuixiansteps`（`/d/shushan/npc/jiyin`）。

## 技能名拼错：技能文件里拼错自己的名字（2026-10-15，KB 06 §7.249）

技能自己的文件（或它的绝招目录）里，`query_skill()` 读的是差一个字母的自己的名字，永远得 0：“基本功夫要高过本技能”之类的限制从不生效，按等级取招、计算伤害的那一项一直是 0。改为本技能的名字（`scripts/lpc_fix_skill_typo.py` 的 self 判据）：`wanxi-spell`→`wanxi-spells`（`/daemon/conjure/dengxian-dafa/juanbi`）。

## 存档读不出来：字符串里的换行、空行（2026-10-15，KB 03 §4.4）

`d/moon/emoted.o`、`d/qujing/yizi.oo.o`：字符串里有原样的换行（`save_object()` 存成 `\r`，`restore_object()` 逐行读，原样的换行让字符串收不了尾），或有空行（`Illegal file format`），读档的对象（留言板、NPC、玩家）从空白开始。换行改写成 `\r`、删去空行（`scripts/lpc_save_encoding.py --from-raw`），驱动核对全部能读回（`scripts/lpc_save_restore_check.py`）。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

11 个文件、15 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`），多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/d/city/npc/obj/choupao`、`/d/city/npc/obj/bingfu`、`/d/city/npc/obj/sengpao`）。本库 NPC 基类 `std/char/npc.lpc` 的 `carry_object()` 第一句是 `if (file->query_unique())`，对不存在的文件直接 call_other，驱动在这里报 `call_other() couldn't find object`，`new()` 来不及返回 0，所以只要 NPC 带着一件本库没有的物品就载入不了（调用处加判断对它无效）。在它前面补 `if (!objectp(load_object(file))) return 0;`（`--base`），缺的物品就跳过，NPC 照常载入；上面那些调用处同样改成带判断的块（基类以后改回去也不怕）。载入检查：改动的文件改前能载入 1 个，改后 12 个（11 个原来载入不了），没有退步。

## 去掉的预定义宏 `SAVE_EXTENSION`（2026-10-18，KB 04 §6.11）

老版 MudOS 给每个 LPC 对象预先定义了 `SAVE_EXTENSION`（`".o"`）；FluffOS 的 ChangeLog（COMPAT_BUSTER 一条）把它删了，改用 `__SAVE_EXTENSION__`。本库没有自己 `#define` 这个宏，用到它的文件一律 `Undefined variable 'SAVE_EXTENSION'`，整个对象载入不了。改成 `__SAVE_EXTENSION__`（`scripts/lpc_fix_predefined_macro.py`）：`adm/daemons/network/netmail.lpc`。`netmail` 是网络邮件守护进程（本库缺 `mailer.h` 等头文件，改后仍载入不了）。改后用 `lpcc` 逐个载入这些对象：0 个通过，1 个还有别的错误（`adm/daemons/network/netmail`：/adm/daemons/network/netmail.lpc:18: error: Cannot #include mailer.h）。

## 蓬莱三星的 `ref()` 是保留字（2026-10-18，KB 04 §6.14）

福星、禄星、寿星（`d/penglai/npc/`）里有一个函数叫 `int ref ()`，`call_out("ref", 20)` 去调它；`ref` 在 FluffOS 里是关键字（引用），`unexpected L_REF`，三个 NPC 都载入不了。函数和 `call_out` 都改叫 `reff`（本系里 dtxyzjb、zitengzhan 早就这么改，`call_out` 却没跟着改）：`d/penglai/npc/luxing.lpc`、`d/penglai/npc/shouxing.lpc`。改后载入：2/2 通过。

## `d/moon/obj/poem` 两句诗丢了收尾的引号（2026-10-18，KB 03 §4.6）

`string *poem` 数组里 `"不放玉花飞堕地，留在广寒宫阙。,` 和 `"把酒送春春不语，黄昏却下潇潇雨。,` 的收尾引号没了（转码时跟半个汉字一起丢了），下一行的开引号把字符串合上，后面的诗句成了代码：`Illegal character 0xe6`，整个物件载入不了。补回 `",`。载入：通过。

## `d/shendian/obj/niepan` 的收尾引号变成了私用字符（2026-10-18，KB 03 §4.6）

`set("long", HIR"……五种符号<U+E4D4>NOR);` 里本该是 `"` 的位置是一个私用区字符（转码时半个汉字加引号被换成了它），`Illegal character 0xee`，整个物件载入不了。换回 `"`。载入：通过。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 1 个对象设了本库没有文件的武功（7 个名字，最多的是 `xuanzong-force`、`yuxu-spells`、`lingyunbu`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：1 个里 1 个通过。（`scripts/lpc_guard_set_skill.py`）

## 补回本库没有的基类文件（2026-10-18，KB 04 §6.15）

下面这些基类本库没有，继承它们的对象（房间、NPC、物品）整批载入不了（`inherit XXX;` 的宏没定义，或者 `inherit "/std/…";` 的文件不在）。同系的库里有同名文件，两库有大量逐字节相同的文件（亲缘关系），所以从那边原样拷来，缺的宏补进全局头文件 `include/globals.h`：`/std/weapon/unarmed`（宏 `UNARMED`）←shenmo，1 个对象继承它，抽样 1/1 载入。每个基类补回后单独载入、再抽样载入使用它的对象，基类载不进来或者一个用户也载不进来的就撤掉（本库撤掉了它们，不再补）。（`scripts/lpc_restore_bases.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 21 处、21 个文件：`dagonforce`→`dragonforce`（6 处）、`hellfire_whip`→`hellfire-whip`（4 处）、`lahua-shou`→`lanhua-shou`（4 处）、`yange_blade`→`yange-blade`（2 处）、`dragon-step`→`dragonstep`（2 处）、`moyunshou`→`moyun-shou`（1 处）、`changqaun`→`changquan`（1 处）、`cuixi-zhang`→`cuixin-zhang`（1 处）。（`scripts/lpc_fix_skill_names.py`）

## 调用了父类没有的函数的对象（2026-10-19，KB 06 §7.259）

`::create();`、`::init();`、`return ::buy_object(who, item);` 这类调用写的是父类里有这个函数的版本；本库的父类没有，旧驱动把它当空操作（返回 0），现在的驱动在编译时就报 `Unable to find the inherited function`，整个对象载入不了。单独成句的调用删掉，`return ::f(...)` 改成 `return 0;`（void 函数里是 `return;`），与旧驱动的行为一致。共 1 处、1 个文件：`::buy_object()`（1 处）。只改了出错原因全是这一类的文件；还带着别的错误（多半是父类本身没了）的文件没动，等父类补回后再看。（`scripts/lpc_fix_dangling_super.py`）

## 全局头文件丢了 2 个宏（2026-10-19，KB 04 §6.16）

`/include/globals.h` 里没有定义 `LOG_HTTP_ERR`、`WEAPON_OB`，用到它们的物件（名单里 2 个）编译时报 `Undefined variable`/`Undefined function`，整个物件载入不了（编译器在第一个未定义的名字上停下，后面的错误和警告都看不到）。同系的库在各自的头文件里都有这几行：照其中和本库共有文件最多的那个库，原样补到 `/include/globals.h` 最后一个 `#define` 之后，宏体里出现的路径在本库里都存在。名单里的物件除了这几个宏之外还有别的错误，暂时仍载入不了。（`scripts/lpc_restore_defines.py`）

## 出口指向不存在的房间（2026-10-19，KB 06 §7.257）

下列房间的出口写的文件不存在，而对面恰好只有一个房间的出口指回本房间，所以按对面的房间改正（笔误、大小写、路径少了一级）：

- `/d/qujing/wuji2/shandao3.lpc` 的 `west` 出口：`guankou` → `goukano`
- `/d/qujing/wuji2/shandao4.lpc` 的 `east` 出口：`guankou` → `goukano`

改后房间照常载入（与 HEAD 逐个对比，没有退步），出口现在指向存在的房间。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 手工收尾（2026-10-19，KB 04 §6.10）

- `adm/daemons/ftpdd.lpc`：`read_connection()` 里的 `ret` 只在 `if (0) { … }` 的死分支里用（`socket_connect()` 那行早就注释掉了），声明和死分支里的 `socket_error(ret)` 一行删掉。
- `u/efflux/bf.lpc`、`u/jame/obj/flower.lpc`：`query_autoload()` 的返回类型改成 `mixed`（标准整理轮，基类声明 string）。

逐个与 HEAD 对比载入，没有退步。

## 补回丢失的标点，另一个版本的完好副本（2026-10-19，KB 03 §4.6 第四轮）

`/d/jz/npc/jiang.lpc`：`set("daoxing", 1500000)` 丢了分号；补回后载入，没有警告。完好副本在 dtxyzjb，只有文件头的署名注释不同。

## `x == "a" || "b"`：后面的字符串常量永远为真（2026-10-19，KB 06 §7.281）

`if (arg == "yuyou" || "yu you")` 里的 `"yu you"` 是非空字符串，永远为真，整个条件对任何 `arg` 都成立；作者要的是每个字符串都和变量比较。具体是：驿站把任何输入都当成合法的去处。在每个字符串前补上变量和运算符（`scripts/lpc_fix_literal_or.py`；`forrest2.lpc` 是 `dir == "north" && "south"`，手工改成 `(dir == "north" || dir == "south") && ...`）：`/std/room/yizhan.lpc`（7 处）。

## `member_array('/', str)` 改为 `strsrch(str, "/")`：字符字面量的 member_array 按字节搜索（2026-10-20，KB 06 §7.283）

`member_array('/', str)` 里的 `'/'` 是整数，驱动按 UTF-8 **字节**搜索，返回字节偏移（带第三个参数时起点也是字节）；最新的 FluffOS（923cdbc0）在字符串里有非 ASCII 文字时，对每个调用点警告一次（`Warning: member_array(int, string) searches BYTES`）。而 `str[0..idx-1]` 按字符切，中文字符串会在错误的位置截断。改为 `strsrch(str, "/")`（找不到同样返回 -1，按字符计数；`scripts/lpc_fix_member_array_char.py`，JSON 编码器等少数几处手改）。改动：`/adm/daemons/vrm_server.lpc`（1 处）。

## `call_out_info()` 的每一项只有 3 个元素（2026-10-20，KB 06 §7.287）

驱动返回的是 `({ 物件, 函数, 延迟 })`，不带 call_out 的参数，旧代码读第 4 项 `info[i][3]`（`callouts` 指令、`calloutd`、`cod` 工具）一读就报 `Array index out of bounds`，指令从第一行起什么也打印不出来。改为 `(sizeof(info[i]) > 3 ? info[i][3] : 0)`（`scripts/lpc_fix_callout_info.py`）。改动：`/cmds/arch/callouts.lpc`（1 处）、`/cmds/wiz/callouts.lpc`（1 处）。

## 浩劫系统 `verdict_time()`：领头玩家已经离线时 `lead->name()` 报错，戒严不解除（2026-10-20）

三十分钟后收场时 `lead`（接战书的玩家）若已退出游戏就是 0，`lead->name()` 在宣布战果的 `message()` 里报错，后面的 `LOGIN_D->set_madlock(0)` 不再执行，戒严一直保持，`quit` 指令因此对所有人关闭。改为 `(lead ? lead->name() : "各派豪杰")`。改动：`/feature/disaster.lpc`（2 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 14 处）。改动：`/cmds/wiz/dns.lpc`（1 处）、`/d/city/mjlady3.lpc`（3 处）、`/d/shendian/babu/obj/longzhua.lpc`（4 处）、`/daemon/class/pfm/NO.1_skill/fengyun.lpc`（3 处）、`/daemon/class/pfm/NO.1_skill/lmsj.lpc`（3 处）。

## `callouts`：`sizeof(info[i]) == 4` 把每一行都挡掉了（2026-10-20，KB 06 §7.287）

驱动的 `call_out_info()` 每项只有 3 个元素，输出行前的守卫 `if (sizeof(info[i]) == 4)` 永远不成立，指令只打印表头。改为 `>= 3`。改动：`/cmds/arch/callouts.lpc`（1 处）、`/cmds/wiz/callouts.lpc`（1 处）。

## `socket` / `dumpsocket` 指令：`dump_socket_status()` 驱动里没有（2026-10-20，KB 06 §7.291）

这些巫师指令 `write(dump_socket_status());`，MudOS 的 efun 在 FluffOS 里不存在，指令编译不过。在模拟 efun 文件里补了 `dump_socket_status()`：用 `socket_status()` 排出同样的表（没有 sockets 包的构建，比如 WASM，只有表头；`scripts/lpc_add_sefun.py dump_socket_status`）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/obj/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库现有的 NPC 文件里没有字面写成空 `chat_msg` 的（扫描只认 `set("chat_msg", ({ }))`）；守卫挡的是运行时才为空的列表和以后新增的 NPC。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/std/char/jobnpc.lpc`、`/std/char/npc.lpc`（共 2 个文件）。

## 巫师命令不带参数时对 0 调用 efun（2026-10-21，KB 06 §7.336）

巫师（管理员）把命令敲成不带参数时，驱动把 0 传给字符串参数；下面的命令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`，这条指令从来没有用过。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py` 在第一处使用参数的语句前加守卫：文件自带 `int help(object me)` 的，守卫是 `if (!arg) return help(me);`（`help()` 定义在 `main()` 之后的 1 个文件补了原型 `int help(object me);`，否则编译报 `Undefined function help`）。改动（1 个文件，括号里是接住 0 的 efun）：`/cmds/adm/dumpprog.lpc`（`new`）。加载检查 HEAD 与工作树对照，没有退步。

## 观礼台 `d/city/under.lpc`：`wait_and_start()` 里的 `fan` 没赋值，比武开不了（2026-10-21，KB 06 §7.346）

接受挑战（`defend`）两秒后 `wait_and_start()` 调用 `fan->command("chat ...比武开始")`，`object fan;` 声明了却没有 `fan = load_object(__DIR__ "npc/fan");`（dtxywzxzb 的同一份文件有），抛错之后两条 `kill` 和 `call_out("finish_match", 300)` 都不执行，比赛不开始。补上这一句（`npc/fan.lpc`、`ground.lpc` 本库都有）。

## 拼错的 `call_out()` / `input_to()` 目标（KB 06 §7.349，2026-10-21）

计时器或输入提示给驱动的函数名和文件里定义的差一个字母；驱动对不存在的函数静默不理，所以对应的计时从来没有触发过。调用和配套的 `remove_call_out()` 改成已定义的拼法：`find_seal`：`disapprear` → `disappear`（法术产生的封印十分钟后从不消失）。改动：`/d/jjf/obj/find_seal.lpc`。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 22 条注册（15 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/d/changan/pinqiting.lpc`（`do_pass`、`do_resign`）、`/d/city/npc/doctor.lpc`（`do_block`）、`/d/city/npc/duguoyin.lpc`（`do_vendor_list`）、`/d/city/npc/guan.lpc`（`do_improve`）、`/d/eastway/npc/petboss.lpc`（`do_cost`、`do_list`、`do_upgrade`）、`/d/eastway/petboss.lpc`（`do_cost`、`do_list`、`do_upgrade`）、`/d/jjf/npc/baifalaoren.lpc`（`do_improve`）、`/d/jjf/npc/luocheng.lpc`（`do_improve`）、`/d/lingtai/npc/puti.lpc`（`do_improve`）、`/d/pansi/npc/qingxia.lpc`（`do_yes`） 等共 15 个文件。最多的函数名：`do_improve` 4 处、`do_bian` 3 处、`do_cost` 2 处、`do_list` 2 处、`do_upgrade` 2 处。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 还剩 2 个函数没有补（inquiry 1, chat_msg_combat 1）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/d/quest/dajiu/jiangziya_bak.lpc`:`ask_jianxi`、`/d/xueshan/obj/hufabird.lpc`:`saysth`。

## 运行期目录 `log/nosave` 不存在，写日志的 `write_file()` 直接报错（2026-10-22，KB 03 §4.3 补充）

这个库的 16 个文件里有 21 处 `write_file("/log/nosave/...")` / `log_file("nosave/...")`（`static` 改 `nosave` 时连字符串里的日志路径一起改了，原来是 `log/static/`）：`nosave/PURGE`、`nosave/CRASHES`、`nosave/CALL_PLAYER` 等。压缩包和站点包里没有这个目录，`write_file()` 在目录不存在时抛 `*Wrong permissions for opening file /log/nosave/... for append. "No such file or directory"`，调用它的函数（杀人记录、重启记录、`call` 日志……）当场中断。把 `log/nosave` 记进 `scripts/wasm_keep_dirs.txt`（站点和 pristine 树都按它建空目录）；没有把字符串改回 `static`。证明（`scripts/lpcc_eval.py`，`catch(write_file("/log/nosave/ZZTEST", ...))`，fqyy2 / hy5 / bmxkx2001 的新进程）：补目录前报上面的错误，补后写成功。

## 汉字按字节切片的老写法没有换成按字符：改法名 `"澄" + name[2..3]`、辈分判断 `name[0..1] == "澄"` 等 2 处（2026-10-22，KB 06 §7.360）

原档按字节算字符串区间（一个汉字 2 字节）：`name[2..3]` 是名字的第二个字，`name[0..1] == "澄"` 问名字是不是以「澄」开头。转成 UTF-8 之后，这个驱动的区间和 `strlen()` 都按字符算（`strlen("澄观")` 是 2，`"澄观"[0..1]` 是两个字），老算术原样留着、意思全变：拜入少林 / 武当 / 峨嵋等派的玩家被改成错误的法名（二字名 `张三` 变成一个字的 `澄`，更长的名字取到第三个字）。

本库 2 处（1 个文件）：拼名字的赋值 2 处。例：`name[0..1]` → `name[0..0]`（`/d/nanhai/npc/tidu.lpc:127`）。`scripts/lpc_fix_gbk_slice.py` 把下标按字符重算（社区的 UTF-8 版 `xkx100utf8` 里就是同样的写法，作对照）；没有改的：截断（`name = name[0..7]`，现在最多 8 个字，只是放宽）、ASCII 的区间（`fname[0..3] == "room"`、`ctime(time())[4..19]`）和上下文看不出是汉字的区间。证明（`scripts/lpcc_eval.py`，bixiecanyang；其余各库是同一份文本）：让澄字辈掌门 `attempt_apprentice()` 一个名叫「张三」的访客，HEAD 的法名是 `慧`，改后是 `慧三`；抽样 28 个库的 HEAD / 工作树加载对比 0 退步。工具不幂等（`[0..3]` 折半得 `[0..1]`，又是对齐区间），改过的文件记在 `scripts/gbk_slice_converted.txt`，不要重跑。

## 长度检查按字节写，旁边的提示按汉字写：4 处（2026-10-22，KB 06 §7.362）

老档的 `strlen()` 数字节（一个汉字 2 字节），转成 UTF-8 后它数字符：提示写「必须是 2 到 6 个中文字」的检查还是 `strlen(name) < 4 || strlen(name) > 12`，于是两三个字的房名、帮会名、群名、聊天室名、称号被提示自己说允许的那句话拒绝，上限却是提示的两倍；留言板的标题检查 `i < 4 || i > 24 || i % 2` 还会拒绝所有奇数个字的标题（`post 你好吗`）。本库 4 处（2 个文件）：`if ((strlen(name) < 2) || (strlen(name) > 12)) {`（`/adm/daemons/logind1.lpc:929`）。`scripts/lpc_fix_strlen_gate.py` 以提示为准：条件里每个 `strlen` 门槛都恰是提示所说数字的两倍才折半，存长度的变量（`i = strlen(arg);`）的门槛和 `|| i % 2` 奇偶项、其后循环的 `i % 2 == 0 &&` 一并处理；提示里有英文 / 字母 / 字节的不动。证明（`scripts/lpcc_eval.py`，bxsj 的留言板，求值对象继承 NPC 并重写 `edit()` 记录调用，`command("post 标题")`）：HEAD 拒绝「你好」和「你好吗」、放行 23 个字的标题；改后接受前两个、拒绝第三个；shenmo 的 `named.lpc invalid_new_name("张三")`：HEAD 回 `名字只能是2-4个中文字。`，改后回 0。抽样 24 + 15 个库的 HEAD / 工作树加载对比 0 退步。

## 按字节写的汉字循环、茶馆猜诗和同盟频道标题（2026-10-23，KB 06 §7.363）

老档按字节做「一个汉字」：`while (i--) if (i % 2 == 0 && !is_chinese(name[i..<0]))` 只检查偶数下标，奇数位上的拉丁字母（`张a`）会过；茶馆猜诗 `mixup()` 用 `strlen(str)/2` 再 `j=j+j`、`str[k..k+1]` 交换两字节；泥潭系 `channeld` 的 `switch (strlen(fname)) case 4/6/8/10` 和 `strlen(family)==4/6` 按字节长度给同盟 / 门派名加空格。本驱动的 `strlen()` 和区间都按字符算。`scripts/lpc_fix_byte_char.py`：去掉奇偶项、把区间改成 `name[i..i]`，按字符重写 `mixup()` 并把 `strlen(first)>=14` 折成 7，频道标题的 case / 门派长度改成字符数（对照 aoxiangtianji）。本库 汉字循环 / `is_chinese` 区间 8 个文件；茶馆猜诗 `mixup` 1 个文件。证明（`scripts/lpcc_eval.py`）：sjplii 的 `check_legal_name` 在 HEAD 接受「张a」、改后拒绝，两边都接受「张三」；xkx100 的 `clubpoem->mixup("离离原上草")` 得到「离离原草上」（真交换汉字）；nitan_san 两字同盟名得到 `【 兄  弟 】`。关键对象加载通过。

## 血条 / 表情标题按字节算显示宽度（2026-10-23，KB 06 §7.365）

老档把汉字当两字节：`bar_string[0..(val * N / max) * 2 - 1]` 把「格数」换成字节下标，半格血条在本驱动（按字符算区间）上会整条画满；巫师表情 `edemote` 的 `repeat_string("─", 13 - (strlen(emotion) / 2))` 也会少减汉字宽度。`scripts/lpc_fix_display_pad.py`：去掉 CJK 血条 / 空白条上的 `* 2`（`jings`/`qis` 赋值和 `blank_string3[0..(23-a)]` 的 23→11 一并改），表情标题去掉 `/ 2`；ASCII 空格的 `none_string` / `empty_string` 仍保留 `* 2`（一格两个空格）。本库 14 处（7 个文件）。证明（`lpcc_eval.py` hhsj）：`tribar_graph(6,9,12)` 在 HEAD 画出整条 12 个■，改后为 6 个■+3 个□；麻将 `strlen(tempB)/2` 是两字符牌码，未改。


## 巫师区出口 faceoff / rence / niulang / yihua（2026-10-23，KB 06 §7.372）

`/u/f/faceoff/`、`/u/r/rence/`、`/u/onskyer/niulang/`、`/u/skinys/yihua/` 对应区域已在 `/open/world1/faceoff/bird/`、`/open/prayer/`、`/d/niulang/`、`/d/yihua/`。`scripts/lpc_fix_wizard_area_exits.py` 在目标存在时改写，仍缺失的出口行删除。本库 4 处。证明：dreamofseven wood5 四向可加载；xlqy_new2007 天河东西向 niulang；kxkj kitchen7 → prayer。


## 家丁 CLOTH_OB()/WEAPON_OB() 调用式宏（2026-10-27，KB 04 §6.16 Also）

`d/wuguan/npc/jiading.lpc`（及 `jiading1`，xlqy 系在 `d/dntg/hgs/wuguan/npc/`）写 `carry_object(CLOTH_OB("cloth"))` / `WEAPON_OB("changjian")`：库中没有带参的 `CLOTH_OB`，`WEAPON_OB` 在 `globals.h` 只是裸路径 `"/d/obj/weapon/"`，展开成 `"/d/obj/weapon/"("changjian")` 语法错误，NPC 无程序。同目录其它 NPC 用 `__DIR__ "obj/cloth"`；剑在 `/d/obj/weapon/sword/changjian`。改成这两条（目标文件均在树内）。证明：HEAD `Undefined function CLOTH_OB`；改后 `new()` 成功且 inventory 为 2。


## 黑风山 pusa1 用未声明的 ob 且函数外残留 call_out（2026-10-27，KB 06 §7.348 Also）

`d/qujing/heifeng/npc/pusa1.lpc` 的 `announce_success(object who)` 写成 `if (!ob->query("obstacle/hf"))`（`Undefined variable 'ob'`），同目录 `pusa.lpc` 是 `who->query("obstacle/hf") == "done"`；`who->save(); }` 之后还残留 `call_out("die"...); return; }`，落在函数外（`unexpected L_STRING`），对象无程序。改成与 `pusa` 相同的门，并删掉残留语句。证明：HEAD 加载失败；改后加载成功。


## 雪山 obj/hufabird set_level 缺 }（2026-10-27，KB 04 §6.28 Also）

`d/xueshan/obj/hufabird.lpc` 的 `set_level` 在 `setup();` 后少了一个 `}`，后面的 `int heal_up()` / `leave` / `invocation` / `die` 都嵌进了 `set_level`（`unexpected '('`），对象无程序；同目录 `npc/hufabird.lpc` 正常关闭。顺带：`messege_vision`→`message_vision`，`return : die()`→`return ::die()`，以及无 `saysth` 的 `(: saysth :)` 按 7.355 注释掉。证明：HEAD 加载失败；改后加载成功。


## 洗衣盆 is_container 映射缺值编不过（2026-10-27，KB 04 §6.28 Also）

`d/gao/obj/pen.lpc`（或 `d/qujing/gao/obj/pen`）的 `is_container()` 写成 `set("objects", ([ "/u/bula/gao/obj/kaoji" ]));`：映射只有键没有值（`unexpected ']'`），对象无程序。同族 hy5 / xyj2000 已把该函数注释掉。改成标准的 `return 1;`。证明：HEAD 加载失败；改后加载成功。


## 月宫 quest/road 模板缺 index（2026-10-27，KB 06 §7.348 Also）

`d/moon/quest/road.lpc`（及误放在 `npc/road.lpc` 的副本）出口写 `sprintf("%d", index ± 1)`，却没有像 `road1`…`road10` 那样声明 `int index = N;`（`Undefined variable 'index'`），对象无程序。补上 `int index = 5;`（中间段，东西出口都能落到已有房间）。证明：HEAD 加载失败；改后加载成功。


## 星君/罗汉模板缺 ID 宏（2026-10-27，KB 06 §7.348 Also）

`d/dntg/sky/stars/star.lpc` 与 `d/nanhai/luohan/npc/luohan.lpc` 用 `title[ID]` / `first_name[ID]`，真正带号的副本是 `#define ID N` 再 `#include` 本文件；单独编译模板时 `Undefined variable 'ID'`。加 `#ifndef ID` / `#define ID 0` / `#endif`，带号 include 仍用各自的 N。证明：HEAD 模板加载失败；改后模板与 `stars/5`、`luohan5` 均加载成功。


## 雷神 check 在 stop_fight 定义之前调用且 call_out 缺逗号（2026-10-27，KB 04 §6.28 Also）

`d/qujing/start/24/1.lpc` 的 `check()` 里调用 `stop_fight(who)`，函数却写在后面（`Undefined function stop_fight`）；`call_out("lost", 1 who)` 少了逗号（`unexpected L_DEFINED_NAME`）。把 `stop_fight` 挪到 `check` 之前，并改成 `call_out("lost", 1, who)`。证明：HEAD 加载失败；改后加载成功。

## 悬空 ::init / unique::init（2026-10-27，KB 06 §7.259 Also）

`kugu-1/2/3`、`kunxian-suo` 写 `::init();`，`tianyi` 写 `unique::init();`，而 `F_UNIQUE` / `ITEM` / `feature/unique` 没有 `init`；本驱动编译报 `Unable to find the inherited function 'init'`（tianyi 带 `in file 'unique'`），物件无法加载。老驱动把空父调用当返回 0。`lpc_fix_dangling_super.py` 删掉这些语句；`cloth::init()` 保留。证明：HEAD 加载失败；改后加载成功。

## dami 误调 init_unarmed（2026-10-27，KB 04 §6.25 Also）

`d/obj/food/dami.lpc` 继承 `ITEM`+`F_FOOD` 却调用 `init_unarmed(5)`（并 `#include <weapon.h>`），未继承空手兵器基类，驱动报 `Undefined function init_unarmed`。手足 hymud 已注释该行。删掉该调用与无用的 weapon 头。证明：HEAD 加载失败；改后加载成功。
