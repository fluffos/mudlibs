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
