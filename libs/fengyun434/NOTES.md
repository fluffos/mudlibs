# fengyun4-3-4.rar → `fengyun434`

- Archive: `archives/fengyun4-3-4.rar` (6MB — "风云Ⅳ"/"Storm Riders 4",
  Sumxin Fengyun, `www.sumxin.com`). Mudlib root at `Fengyun/fy4/`, config
  at `Fengyun/bin/config.cfg`. Different lineage from the 东方故事/
  simple-style libs seen so far (its own `master.lpc` shape).
- Port: **40011**.

## Status: DONE — boots clean, playable over telnet

Zero fixes needed to boot — clean on the first attempt (checked
proactively for the known `load_object`/`domain_file`/angle-bracket-
include patterns beforehand; none present in this lineage). GB/BIG5
encoding-selection prompt (same legacy pattern as other libs), then full
login flow.

## What was fixed

Nothing needed for boot. Routine conversion only: encoding (8801
converted, 255 already UTF-8/ASCII, 151 skipped binary, 30 lossy),
`.c`→`.lpc` (8238 files, 465 refs auto-fixed), `static`→`nosave` (50
files, notably low ratio vs other libs of similar size — this codebase
barely uses the idiom).

## Known remaining issues

- 85 lpcc-sweep failures (of 8238) — 99% pass rate, the cleanest lib so
  far. Not triaged given the small remaining count and time budget; none
  blocked booting or the login flow.

## How to run

```
cd libs/fengyun434
~/src/fluffos/build-debug/src/driver config.fluffos
python3 ../../scripts/mudclient.py 127.0.0.1 40011 --timeout 10 --send "0" --send "" --send "quit"
```
(the `"0"` selects GB encoding at the legacy GB/BIG5 prompt)

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

## Re-verification pass: driver rebuild + LPC formatter + WASM build

- **Formatter**: `format-corpus.mjs` over all 8238 `.lpc` files; 6477
  reformatted, 4 unchanged, 1757 refused (self-check `errors`/token
  mismatches, expected on a mega-lib this size — not chased down
  individually). One explicit `TOKEN MISMATCH` reported for
  `d/for_martea/neon_playground/migong/adm/daemons/vrm_server.lpc`
  (left untouched by the formatter itself, per its own refuse-don't-guess
  policy).
- **Proactive fix applied before the first boot attempt of this pass**:
  same `adm/daemons/securityd.lpc` `resolve()`-before-`wiz_status`
  ordering bug as `fy3dz`/`fy3xd` (same 风云 engine
  family) — fixed proactively before booting. (A second, empty
  `adm/securityd.lpc` file also exists in this lib but is dead/unused —
  `SECURITY_D` in `globals.h` points at `adm/daemons/securityd`, not it —
  left alone.)
- **Native retest against rebuilt driver**: clean, zero fixes needed
  beyond the proactive one. Full registration + `look`/`score`/`quit`
  verified with a real Chinese name (杨过), zero debug.log errors.
- **WASM test**: boots and plays fully. Only non-fatal errors are the
  expected no-sockets-package ones (`ftpd.lpc` and
  `network/dns_master.lpc` both fail to compile with `Undefined function
  socket_create`/`socket_bind`/`socket_close`, `*No program in object`
  at preload — caught, non-cascading). Full registration with a real
  Chinese name (郭靖), `look`, and `quit` all completed cleanly. Not
  affected by the documented `query_ip_number()` WASM limitation.

## WASM-enablement pass (loopback / admin seeding)

- **Loopback ban bypass** (§1.3b): two gates patched.
  1. `adm/daemons/band.lpc` `is_banned()` (~line 46) — short-circuit for
     non-string / empty / `127.0.0.1` / `localhost` / `127.`-prefix.
     Called from `adm/daemons/logind.lpc:80-81`.
  2. `adm/daemons/logind.lpc` `valid_wiz_login()` (~line 528) — the
     wizard-IP whitelist gate (`/adm/etc/wizip/<id>`) destructs wizard
     logins from unlisted IPs; loopback/empty/non-string IPs now always
     pass (this gate feeds on `query_ip_number()`, garbage under WASM).
- **Uptime gate / anti-flood throttle**: none found.
- **Admin account** (§1.5): `fluffos` / `Mud@2026`, display 浮浮, status
  `(admin)` via `fluffos (admin)` appended to `/adm/etc/wizlist`. No
  `/adm/etc/wizip/fluffos` file exists (= unrestricted). Verified
  re-login + `update /adm/daemons/combatd` → 成功.
- **Retest**: fresh normal registration (秦风) works, `look`/`score` OK,
  test char saves removed; no new debug.log errors.
- **Fail-closed retrofit** (2026-07-24 security correction): the loopback
  check(s) above originally also treated an empty/non-string IP as
  loopback (defensive fallback for the then-broken `query_ip_number()`).
  Since the driver's IP-reporting bug is now fixed upstream (WASM
  reports a clean `127.0.0.1` like native), that fallback was removed —
  loopback is now strictly `stringp(ip) && (ip=="127.0.0.1" ||
  ip=="::1" || ip[0..3]=="127.")`; anything unparseable/empty is
  untrusted/remote and goes through the original gate logic. Retested:
  fluffos login + `look`/`quit` still clean over loopback.
- **Save files to force-add** (untracked, NOT gitignored):
  `libs/fengyun434/work/data/user/f/fluffos/fluffos.o`,
  `libs/fengyun434/work/data/login/f/fluffos/fluffos.o`.

## 深度功能测试 / Deep functional test (2026-07-24, round two)

First real *playthrough* pass on this lib (all prior passes verified only
registration + `look`/`score`/`quit` + admin login, or watched boot
output). Played as an ordinary new player through registration,
exploration, organic sect-joining and skill-learning, a real `quit`
with a debug.log grep, a native driver *restart* (stronger than a mere
reconnect — full disk round-trip) to confirm save persistence, a prompt
net-dead/reconnect cycle, and a shop-purchase attempt. Native driver
(`build-debug`) only — WASM not re-verified this pass (out of time
budget after the RSS investigation below; the fix is a one-line change
to a shared simul_efun with no WASM-specific risk, so this is a low-risk
gap, but stated explicitly rather than silently skipped).

Test character: id `shenqin`, Chinese name 沈青梧, password `TestPw123`
— **kept** (not cleaned up) as playthrough evidence. State at time of
writing: 峨嵋派 (Emei sect) 弟子 (disciple) under master 雷一鸣
(6th generation), skill 扑击格斗之技/unarmed at level 1 (learned via the
organic teacher-NPC path), located at 凤求凰客栈 (风云城, the Han-ethnicity
start room), inventory: 布衣 (cloth, worn), 0 money. Save files:
`work/data/user/s/shenqin/shenqin.o`, `work/data/login/s/shenqin/shenqin.o`.

### Bug found and fixed

**`adm/simul_efun/message.lpc:38-40` — the shared `tell_room()` wrapper
passed a raw, unset `int 0` as `message()`'s 4th (`exclude`) argument on
every 2-argument call site, crashing with `*Bad argument 4 to EFUN
message()` — this is AGENTS.md's already-cataloged §7.12 "Shared
message/wrapper argument bug" class, not a new one.**

- Symptom: reproduced live by simply walking **out of the eastern city
  gate** (`west` from `/d/fy/egate.lpc`, matching the very first
  direction change any player takes when leaving the starting city) —
  every single `go` command out of that room threw a caught-but-real
  runtime error to the player's screen (`执行时段错误：*Bad argument 4
  to EFUN message()` plus a full backtrace), because
  `egate.lpc:47-48`'s `valid_leave()` unconditionally calls
  `tell_room("/d/fywall/eupgate", "...")` with only 2 arguments on
  *every* leave attempt in *any* direction, not just the ones the
  surrounding code apparently intended to gate it for. Unlike the
  §7.16/§8.3-style bugs this project has mostly been finding, this one
  is NOT silent — it's a visible on-screen stack trace — but it is
  still the kind of thing only a real walk-out-of-the-first-room test
  catches, since every earlier smoke pass only ever did `look`/`score`/
  `quit` from the login room itself.
- Root cause: `adm/simul_efun/message.lpc:38`, `varargs void
  tell_room(mixed ob, string str, object *exclude) { if (ob)
  message("tell_room", str, ob, exclude); }` — when a caller omits the
  optional `exclude` array (176 call sites in this lib do, including
  `message_vision()`'s own internal `tell_room(v_room[i], str3)` viewer
  fan-out at line 32 of the same file), the unset varargs parameter is
  `int 0`, not `({})`, and this driver's `message()` efun requires its
  4th argument to be `object|array`, not `int`. Confirmed against
  AGENTS.md §7.12, which documents the exact same shared-wrapper shape
  (there attributed to `yueyingqiyuan` and the ES II family) — this is
  the same bug class recurring in the unrelated 风云 engine lineage, not
  a new class. Notably, two OTHER 风云3-family siblings
  (`fy3xd`, `fy3dz`) already carry the fix
  (`exclude || ({})`) in their copy of this same file, but three more
  siblings in this lib's own immediate 风云Ⅳ/风云再起Ⅱ family
  (`fy2005`, `fy2`, `fy2qh`) plus `zzfy` (风云3) still have the
  unfixed version — worth porting centrally per this task's scope note
  (not done here, out of scope for this session).
- Fix (`adm/simul_efun/message.lpc:39`):
  ```lpc
  // BEFORE:
  varargs void tell_room(mixed ob, string str, object *exclude) {
    if (ob) message("tell_room", str, ob, exclude);
  }
  // AFTER:
  varargs void tell_room(mixed ob, string str, object *exclude) {
    if (ob) message("tell_room", str, ob, exclude || ({ }));
  }
  ```
- Verified: reproduced live pre-fix (`west` from the east gate threw the
  exact backtrace above, rooted at `egate.lpc:48` → `tell_room()` →
  `message.lpc:39`); killed and rebooted the native driver (simul_efun
  changes need a restart, not just `update`, to take effect reliably);
  re-walked the identical route (`west`×5, `north`, `east`×5 from the
  start room to the east gate, then `west` again) — clean, no error,
  normal room transition. Also grepped the rest of the lib for any
  OTHER "int 0 passed as message() exclude" shape beyond this one
  shared wrapper — none found; this single fix point covers all 176
  call sites since they all route through it.

### What was tested and confirmed working

- **Registration**: real Chinese name (沈青梧), full flow (encoding
  choice → id → confirm → Chinese name → password → confirm → email →
  gender → ethnicity), landing correctly in the Han-ethnicity start room
  (凤求凰客栈) per `doc/help/newbie.txt`'s own documented room list.
- **Movement/exploration**: walked a wide loop of the 风云城 starting
  zone (`d/fy/`) — the central square (风云天下), east/west/north
  market streets, the jewelry shop, the 私塾学堂 (private school, its
  "24-point" math minigame sign/NPC), the beggar-clan street NPC area,
  and a hidden alley (阴暗石巷 → 石巷尽头, gated by a closed 木门 door
  opened with `open door`) leading to a 峨嵋派 (Emei sect) safehouse.
  Room descriptions, exits, and NPC lists all rendered correctly
  throughout; `help newbie.txt` accurately describes both the
  registration flow and the starting zone.
- **`score`/`hp`/`i`**: all three correct at every stage (fresh,
  post-sect-join, post-skill-learn) and match `doc/help/newbie.txt`'s
  documented format exactly.
- **Sect-join mechanism**: `apprentice master lei` on 雷一鸣 (a genuine
  峨嵋派 recruiting master at `d/fy/sroom.lpc`, defining a proper
  `attempt_apprentice()`/`do_recruit()` auto-accept flow) completed
  correctly two calls later (`apprentice`, then a `call_out`-delayed
  `recruit`) — `score` afterward correctly showed "峨嵋派 弟子" title and
  "你的师父是雷一鸣". **Important negative finding along the way, NOT a
  bug**: the roadside "老乞丐" (Old Beggar, `d/fy/npc/beggar.lpc`) has
  `create_family("丐帮", ...)` set (giving it a sect-member title for
  flavor) but never defines `attempt_apprentice()`, so `apprentice old
  beggar` permanently sits at "pending" and never completes — this
  looks like a bug on first glance but isn't: cross-checking the other
  4 genuine 丐帮 NPCs in the lib (`d/jinan`, `d/songshan`, `d/qianfo`)
  confirms the *real* Beggar Clan recruiter lives elsewhere and this
  street NPC is intentionally decorative crowd-filler, not a broken
  recruitment path. Documented here so a future pass doesn't waste time
  re-diagnosing the same NPC.
- **Organic skill-learning**: `skills master lei` correctly listed the
  master's 15 skills (gated — `skills <other-player>` correctly refuses
  for non-family: "只有管理或有师徒/夫妻/结拜关系的人能察看他人的技能");
  `learn unarmed from master lei with 50` correctly consumed 精力(gin)
  and 潜能(potential) and raised 扑击格斗之技(unarmed) from unlearned to
  level 1, with the expected "你的「扑击格斗之技」进步了！" narration.
- **Combat**: no dedicated stat-mirroring training dummy found in the
  reachable starting zone (grepped `accept_fight` broadly — the
  `d/shaolin/npc/muren.lpc` "木人" pattern seen in sibling libs exists
  here too but is a strong, sect-gated NPC, not a newbie-safe sparring
  partner). Followed the checklist's documented fallback instead: found
  and fought the weakest roadside combat-capable NPC in the starting
  zone (无聊少年/`d/fy/npc/dtz1.lpc`, unarmed 20/dodge 20). `kill
  shaonian` correctly engaged combat (aggressive "heroism" attitude NPC
  accepted immediately), exchanged one round, and the built-in
  danger-avoidance logic auto-fled the character to an adjacent room
  before any real damage was taken (气血/HP unaffected: 300/300
  throughout) — confirms both the attack path and the auto-flee safety
  net work correctly.
- **Shop purchase**: `list` at 凤求凰客栈's 店小二 (Waiter) correctly
  rendered the price table (wineskin/dumpling/fried chicken leg);
  `buy dumpling from waiter` correctly refused with "你的钱不够"
  (insufficient funds) since a brand-new character starts with 0
  money. **Not completed live** — the purchase command path is
  confirmed working up to the funds check, but an actual successful
  purchase was not exercised since reaching real starting capital would
  have required a separate income grind (the 私塾学堂 24-point game, the
  长乐坊 conman, or quest rewards) outside this pass's time budget.
- **`quit` + debug.log grep**: `quit` from 凤求凰客栈 produced the
  expected on-screen "欢迎下次再来！" and correctly dropped the
  low-value 布衣 with a narrated reason; grepped `debug.log` for
  everything written during the quit — zero `error:`/`Too deep
  recursion`/`Too long evaluation`/`Bad argument`/`couldn't find
  object` lines, only routine compiler warnings from files touched
  during the session. Clean.
- **Net-dead / reconnect (prompt)**: opened a raw socket, logged in,
  disconnected uncleanly (socket close, no `quit`) mid-session, then
  reconnected within ~15 seconds — landed back in the exact same room
  with no void-parking or stranding, "重新连线完毕。" printed as
  expected. This lib's `obj/user.lpc` `net_dead()`/`reconnect()` design
  is structurally immune to the AGENTS.md §7.20 bug class by
  construction: it never `move()`s the disconnected player into a
  temporary void room at all (unlike the FF/ES2-style pattern §7.20
  describes) — the player object simply stays in its real room the
  whole time it's link-dead, `net_dead()` only does
  `set_heart_beat(0)`/schedules a `user_dump` call_out, and
  `reconnect()` only resets the heartbeat and cancels that call_out.
  Confirmed by reading `obj/user.lpc:121-149` in full, not just
  inferred from behavior.
- **State persistence across a real driver restart** (stronger than a
  same-boot reconnect — full disk round-trip): killed and rebooted the
  native driver, then logged back in as `shenqin` — location (凤求凰客栈),
  sect membership (峨嵋派弟子, 师父雷一鸣), and skill progress
  (unarmed level 1) all correctly restored from disk. Inventory showed
  the 布衣 again despite the earlier quit narration claiming it was
  dropped — harmless flavor-text quirk (the "丢下" message appears to
  be generic quit narration, not an actual inventory removal), not
  investigated further given it has no functional impact.

### Not verified live, and why

- **Long-wait (900s) net-dead timeout → forced quit → reconnect**: the
  code path was read in full (`obj/user.lpc`'s `user_dump()`,
  `NET_DEAD_TIMEOUT` = 900s in `include/user.h`) and, since this lib
  never void-parks a disconnected player (see above), `user_dump()`'s
  `catch(command("quit"))` runs from the player's real, undisturbed
  room — the same code path already verified clean via the manual
  `quit` test above. The **live** 900-second wait was started (real
  wall-clock blocking sleep, not a background watch) but was
  **deliberately aborted before completion** when the driver's own RSS
  climbed from ~40MB at boot to ~4.5GB after about 15 minutes of
  connected-idle wall-clock time (sustained ~4-5MB/s growth, worth
  flagging — see below) — killed per this project's process-hygiene
  policy rather than let it grow further, and a fresh driver was
  rebooted for the remaining checklist items. Given the code-review
  finding (no void room in this lib's design) and the already-verified
  prompt-reconnect + real-restart persistence tests, the residual risk
  from skipping the literal 900s live wait is assessed as low, but
  stated explicitly rather than silently presented as fully verified.
- **WASM re-verification of the `tell_room()` fix**: not re-run this
  pass (native-only). The fix is a one-line change to a shared,
  platform-agnostic simul_efun with no WASM-specific code path, so risk
  is assessed as low, but it hasn't been literally re-tested under
  `build-wasm`.
- **Death/respawn**: not reached — the one real combat attempt
  auto-fled before any damage, by design (see above), and deliberately
  seeking out a fight strong enough to kill a fresh, single-skill
  character felt like the wrong way to spend the remaining time budget
  once the `tell_room()` bug and the RSS finding had already emerged.
- **私塾学堂's 24-point math minigame**: read and understood
  (`d/fy/washroom.lpc`'s "sign" item text plus `npc/taipo.lpc`), and
  observed live once (given "3,3,3,4", the correct answer
  `(3*3-3)*4=24` was computed but not submitted in time before the
  character had already moved on to other test steps in the same
  session) — not confirmed to actually pay out; low-stakes flavor
  content, not chased further.

### RSS growth observation (not root-caused, flagged for awareness)

During the aborted long-wait test above, the native driver's RSS grew
from ~40MB shortly after boot to ~4.5GB after ~15 minutes of wall clock
time, at a sustained rate of roughly 4-5MB/s that showed no sign of
plateauing when killed. The admin `status` command's own memory
accounting (`Total accounted: ~5MB` — apply cache, objects, arrays,
mappings, strings, prog blocks, all trivially small) came nowhere close
to explaining the ~4.5GB `VmRSS`/`VmData` (confirmed via
`/proc/<pid>/status` — single-threaded, so not a thread-local leak
either), meaning the growth is happening entirely outside the LPC
driver's own object/memory accounting — almost certainly a native-level
leak in a C efun or the interpreter itself, not something an LPC-level
source fix in this mudlib can address. Circumstantial suspect: this
lib's `adm/daemons/network/dns_master` is in `adm/etc/preload`, and
`adm/daemons/whod.lpc` periodically (`call_out` every 3-15 minutes)
calls `DNS_MASTER->query_muds()`/`RWHO_Q->send_rwho_q()` against
long-dead remote hosts — a class of dead-end network activity this
project has flagged before (AGENTS.md §7.6) for hanging boots, though
not previously for sustained memory growth. **Not conclusively
root-caused** — the process was killed for safety before further
diagnosis, and a second, unrelated concurrent agent's driver (a
different lib entirely, `xjcq2000`) was independently observed
at a similarly elevated RSS at the same wall-clock time, so this may be
a broader phenomenon (driver build, host machine memory pressure, or
this specific test environment) rather than something specific to this
lib's own source. Left as an explicit open flag rather than guessing at
a fix; **not currently believed to be a new distinct AGENTS.md bug
class** since the root cause was not pinned down at the LPC-source
level (which is what that catalog is scoped to) — recorded here so a
future pass on this lib (or a sibling with the same `dns_master`/`whod`
setup) that hits the same symptom doesn't have to rediscover it from
scratch.

Separately (much lower severity, cosmetic only): the login banner's
"目前共有%d位人士正在游戏中" headline count is inflated by stale
shipped intermud/rwho snapshot data (`work/data/remote/name@*`,
`id@*` — real remote-mud player-name lists from the original
2000s-era game, read by `adm/daemons/whod.lpc`'s `query_num()` =
`sizeof(users()) + sizeof(REMOTE_NAMES)`) — showed "三百零七位人士"
online when the real, accurate count (confirmed via `who`, which
correctly uses live `users()` only) was 1-2. Same *spirit* as the
already-cataloged §7.16 "stale shipped real-timestamp" class (old
archive data misread as live), but a different, non-crashing mechanic
(a wrong cosmetic number, not a runaway loop) — not fixed this pass
given it's purely cosmetic and lower priority than the crashing
`tell_room()` bug, flagged here for a future pass.

## WASM 修复摘要（迁移自 meta.json 的 group_note）

风云Ⅳ 基础版。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 15 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## Deep functional test round two (2026-08-14)

Independently re-verified against current code rather than trusting the
round-one writeup above. Found and fixed two new gaps (both standard
checklist items, no new bug classes); re-confirmed round one's real find
(§7.12 `tell_room()`) live via the exact original crash route.

### New fix: `adm/simul_efun/file.lpc`'s `log_file()` missing `assure_file()`, plus `cat()` null-guard

Standard §7.11-class gap: `log_file()` wrote directly with no
directory-existence guard, `cat()` had no null-guard on `read_file()`.
Fixed both, with a forward declaration (this driver requires one when a
function is called before its own textual definition in the same file —
confirmed the hard way on `dtsl` earlier this session).

### New fix: two active `printf("%O\n", ob)` debug leaks in `logind.lpc`

Both in the Chinese-name-confirmation flow, right before the "请设定您的
密码：" password prompt — one in the manual-name-entry branch
(`get_name()`), one in the random-name-accept branch (`get_resp()`).
Matches this session's established checklist item to check both branches
independently. Removed both; `update /adm/daemons/logind` confirmed the
file still compiles cleanly afterward.

### Re-verified live: round one's §7.12 `tell_room()` fix still holds

Code-confirmed `exclude || ({ })` still present in
`adm/simul_efun/message.lpc`, then live-walked the exact original crash
route as admin: 凤求凰客栈 → across 风云城 → east through the 东云
corridor to 风云东城门 (the east gate), then `west` — the precise
`valid_leave()`/`tell_room()` call site round one's bug report cited.
Landed cleanly, zero new `debug.log` errors (only harmless compile
warnings from the newly-loaded gate-guard NPCs). Also noted: this lib's
actual live `debug.log` is at `log/debug.log` (the driver's launch-cwd
level), not `work/log/debug.log` — the latter contains only stale
content from a much earlier (`fluffos 20260721`) boot and is not written
to by the current driver; same quirk this project has documented before
on other libs (config's `log directory : /log` resolves against launch
cwd, not the mudlib root).

### Not re-investigated this pass: the RSS-growth flag and cosmetic online-count inflation

Round one's flagged-but-not-root-caused native RSS leak (unrelated to any
LPC-level fix, `~40MB → ~4.5GB` over 15 minutes) and the cosmetic
inflated "目前共有%d位人士" online-count (stale shipped rwho data) were
both left exactly as documented — neither is something this pass's
checklist-driven verification touches, and this pass's own driver was
killed well within a couple of minutes of uptime each boot, so the RSS
question wasn't (and didn't need to be) re-observed.

### Verification method

Booted native `build-debug` driver, admin login (`fluffos`/`Mud@2026`) —
note this lib's login flow (encoding choice → id → password) needs each
step sent as a separate paced call, not batched via a single rapid
`multi` — a batched attempt this pass left the session at the password
prompt with subsequent input silently misrouted as game commands
("什么？"), while individual `sendread` calls worked correctly both
times; not a mudlib bug, a test-harness pacing note for next time on
this lib. `update /adm/daemons/logind` as the real privileged-action
check. Two full rapid reconnects (each a fresh full login, not silent
resume — this lib's `net_dead()` design never void-parks a player, so
prompt reconnects go through the ordinary registration-shaped login
path), both clean. Driver killed by exact PID promptly after each boot;
incidental `fluffos.o` save-timestamp churn reverted before commit.

### Files modified this pass

- `work/adm/simul_efun/file.lpc` — `log_file()` `assure_file()` guard
  (with forward declaration), `cat()` null-guard.
- `work/adm/daemons/logind.lpc` — removed two `printf("%O\n", ob)` debug
  leaks (both name-confirmation branches).

## §7.100 跨库扫描修复（`ROOM` 基类同款 `replace_program()` 致命形状）

- 同款 `inherit ROOM; ... replace_program(ROOM);` 冗余自替换（AGENTS.md
  §7.100）：与 `xsfyssjb`（同为风云系血统）完全同构，`work/` 下 1,188 处
  存活匹配，全部标准独立行形式，脚本一次性删除，无不规则残留。没有房间
  生成类工具，不涉及工厂模板修复。`data/` 下额外核查过，无命中。验证：
  真实 debug 驱动干净编译启动、端口正常监听，`debug.log` 无新增
  "cannot replace"/错误行。

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

## 深度功能测试（2026-09-04，round three，paid shop）

新角度：补上 2026-08-14 round two 没做成的真实购买。那次
`buy dumpling from waiter` 停在「你的钱不够」（新角色身无分文）；
雷一鸣拜师已经完成，本轮不再拜师。

本轮没有新的 programming bug。`log_file()` 已有 `assure_file()`。
`log_error()` 已有 `arning:` 闸门。第一输入是 GB/BIG5 内码菜单
（`0` = GB，`1` = BIG5），不是把 id 直接喂给 `get_id`。

### 实测过程

管理员 `fluffos` / `Mud@2026` / 浮浮。端口 40011。先发 `0` 选 GB，
再发 id/密码。落地已经在凤求凰客栈（`/d/fy/fqkhotel`），店小二 id
`waiter`。`clone /obj/money/gold` 一次成功（这份档案的 `clone.lpc`
没有 `is_admin()` 门槛）。`list` 牛皮酒袋二十文 / 包子十五文 /
烤鸡腿三十文。`buy dumpling from waiter` 成功：「你向店小二买下一
个包子。」`i` 剩九十九两银子 + 八十五文钱（10000−15=9985）+ 包子。
`save`「档案储存完毕。」找零数学正确，不是钱被吞。

live `debug.log` 是 `libs/fengyun434/log/debug.log`（Boot Time Fri
Sep 4 03:43:50 2026），无 `error:` / `Too deep recursion`。管理员
存档未提交。


## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— compile-warning and load-failure pass, wrong-case paths

`scripts/lpc_warnings.py fengyun434` (9245 files): 2578 distinct diagnostics and 83 files that did not compile at the start, 127 diagnostics and
72 files at the end (8228 compile). 980 files changed. This is the root of the Fengyun family (`fengyun434`, `xsfyssjb`, `fysjmb`); the tools
are the ones of libs/xkx2001/NOTES.md (KB 04 §6.10): 2165 unused locals in 958 files, redundant leaf inherits (2), and the one class the xkx
family did not have, now `scripts/lpc_fix_forward_decl.py`: **87 `Called function 'f' not compiled with type testing` warnings in 15 files**
(`std/char/smart_npc.lpc`, the `smart_npc` copies of `d/taiping` and `d/eren2`, `d/fy/npc/fightnpc*.lpc`, `d/eren2/npc/wuya.lpc`): a function the
file calls before the place where it defines it has no declaration at the call under `#pragma strict_types`; the prototypes (`varargs void
single_busy(object target);`) now stand in front of the first function of each file (KB 04 §6.5).

**Wrong-case paths (KB 03 §4.5).** `scripts/lpc_case_paths.py --apply fengyun434`: 62 `.C` files renamed to `.lpc` (rooms and NPCs of `d/`) so that the names the code uses resolve; no reference needed to be rewritten. Load check of the 98 affected objects, HEAD against the
working tree: 29 PASS -> 98 PASS, 69 more load, none fewer.

**By hand.** `adm/simul_efun/file.lpc` defines `tail()` in LPC (the efun of the MudOS this archive ran on; `cmds/wiz/tail.lpc` called it and did not
compile).

**What is left (40 files with a compile error).** `ed.c`-style leftovers (`adm/daemons/ed.lpc`, `simulate.lpc`, `adm/obj/*`: `std.h`, `lpc_incl.h`,
`file_incl.h` ... are the MudOS driver's own headers), the TMI-2 network daemons without headers, drafts and pasted listings (`d/jinan/npc/temp.lpc`,
`/open/tempmask*`, `/quest/later.lpc`, `/daemon/damage-1.lpc` ...), and rooms/objects that call `setup()` without a base (`d/huangshan/obj/cq.lpc`,
`/newtask/*.lpc`). `d/eren2/npc/fighter1.lpc` and `fightnpc.lpc` declare their own 7-argument `auto_npc_setup()` next to the inherited 8-argument
one and call it with 7 (the driver checks the call against the inherited entry): not changed.

## 深度功能测试（§10.7，2026-10-05）— room base survives a raising NPC

`scripts/lpc_resilient_room.py --apply`: `make_inventory()` of `std/room.lpc` loads each inventory object as `if (catch(ob = new(file)) || !objectp(ob)) return 0;`. `new()` of a file that is not there returns 0 (the room just lacks that NPC), but `new()` of a file whose `create()` raises (a skill file for `set_skill()` this archive never had, a `carry_object()` item that is not there, a header that never shipped) raised inside the room and the room did not load at all. The wrong-case renames of this lib (the section above) make the NPCs behind them reachable for the first time, so a room that holds one with such a content gap would have gone from "NPC missing" to "room missing"; now it loads without that NPC, as it did before. The room base compiles and loads with the change (HEAD against the working tree). KB 03 §4.5.

## 深度功能测试（§10.7，2026-10-05）— 任务表里的 `.c` 路径与任务守护进程的防护

`scripts/lpc_dynamic_rows.py`：`quest/dynamic_location` 里 1509 行写的是原档案的 `.c` 路径。转档时文件已改名 `.lpc`，而显式后缀按原样解析，`load_object("/d/x.c")`、`new("/d/obj/quest/x.c")` 返回 0 且不报错（KB 03 §4.2，KB 06 §7.220），所以 `adm/daemons/taskd.lpc`、`adm/daemons/tasknpcd.lpc`、`adm/daemons/tasknpcd1.lpc`、`d/biancheng/taskd.lpc`、`d/for_martea/for_suu/tasknpcd.lpc` 读到的每一行都加载不出来：随机任务和任务物品从未生成，在 `create()` 里直接对结果调用 `tar->set()` 的版本还会崩溃，连带加载它的 cron 守护进程和 `give` 的任务钩子。这些行已改为 `.lpc`；另有 8 行指向的文件两种后缀都不存在（档案缺内容），保持原样。
`scripts/lpc_dynamic_quest_guard.py`：4 处 `spread_quest()` 调用（`init_dynamic_quest()` 的循环里）包进 `catch()`，缺失的任务物品或编译不过的房间只跳过那一个任务，守护进程照常加载、其余任务照常生成。
验证：`adm/daemons/taskd.lpc`、`adm/daemons/tasknpcd.lpc`、`adm/daemons/tasknpcd1.lpc`、`d/biancheng/taskd.lpc`、`d/for_martea/for_suu/tasknpcd.lpc`和 cron 守护进程在新进程里加载（HEAD 一次，工作树三次，选房是随机的）：HEAD 通过 5 个，工作树三次分别通过 5、5、5 个（共 6 个），无回退；`adm/daemons/tasknpcd1.lpc` 在 HEAD 与工作树都加载失败，另有原因，与本次无关。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 0 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 2 个，只在 #if 分支用的声明移进分支 0 个文件；改动 2 个文件，HEAD 与工作树各载入一次无回退（2 objects; HEAD PASS 2, tree PASS 2; regress 0; newly loading 0），这些文件的警告 2 -> 0。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查

- `d/tieflag/npc/drinkmonk.lpc` `go_in()`：`for (int i = 0; i < sizeof(enemy); i)` 没有自增，第一个敌人不在同一房间时死循环（直到 eval cost 报错）；改为 `i++`。
- 改动的对象 HEAD 与工作区都能载入，无回退。

## 深度功能测试（§10.7，2026-10-11）：dns_master 空 if

- `adm/daemons/network/dns_master.lpc` `query_services()`：`if (! (mud_svc[mud]["tell"/"finger"] & SVC_KNOWN)) {` 里只有 `#if PREF_X & SVC_TCP … #endif`，选项关闭时 if 体为空（“无副作用”警告）；把 `#if`/`#endif` 挪到 if 外面（KB 04 §6.10，2026-10-07 那次扫描漏掉了 `! (` 带空格、大括号另起一行的写法）。载入无回退。

## 深度功能测试（§10.7，2026-10-11）：dns_master 空 if

- `adm/daemons/network/dns_master.lpc` `query_services()`：`if (! (mud_svc[mud]["finger"/"tell"] & SVC_KNOWN))` 块里只有 `#if PREF_X & SVC_TCP … #endif`，选项关闭时 if 为空（“无副作用”警告报在下一句）；把 `#if`/`#endif` 挪到 if 外面（KB 04，2026-10-07 那次扫描漏了 `! (` 加括号换行这种写法）。载入无回退。

## 编译警告收尾（2026-10-12）

`scripts/toolkit_fix.sh` 一轮加手工收尾，能编译的文件警告清零。改动的 14 个对象 HEAD 与工作树各载入一次：HEAD PASS 14，tree PASS 14，regress 0。

- `kill_ob`（8 个 NPC/物件）、`die`（`d/huashan/npc/qing.lpc`）、`check_status`（`officer.lpc`、`waiter.lpc`）在 `void` 基类上写成 `int`；全库查过没有调用方读这些返回值，用 `lpc_fix_return_types.py --also` 改成 `void`。
- `d/bawang/npc/skill/snake-spear.lpc` 自己的招式表 `action` 与 `std/skill.lpc` 的同名变量重复；它有自己的 `query_action()` 只读自己的表，改名 `spear_action`，行为不变。`daemon/class/tieflag/ill-quan/qiankun.lpc` 的 `enemy` 与 `SSERVER` 的同名，改名 `foes`。
- `d/fy/npc/newsman.lpc`：`ask_question()` 在定义之前就被调用、没有原型，补上原型。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。5 个文件 10 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。

## 把经验、属性、内力当技能读（2026-10-15，KB 06 §7.247）

经验、属性、内力上限不是技能，xkx/ES 的 `query_skill()` 对它们只返回 0（风云的还会去载入同名技能文件而报错）。改为 `query("...")`（`scripts/lpc_fix_pool_as_skill.py`）：连击之术 `dual-attack` 的 `valid_learn()`（风云的 `query_skill()` 去载入 `/daemon/skill/combat_exp`，报错）。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

9 个文件、17 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/questnpc/obj/yueshenblade`、`/questnpc/obj/yueshencloth`、`/d/fy/obj/whitecloth`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 0 个，改后 10 个（10 个原来载入不了），没有退步。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 1 个对象设了本库没有文件的武功（1 个名字，最多的是 `qingfengsword`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：1 个里 1 个通过。（`scripts/lpc_guard_set_skill.py`）

## 通向不存在房间的出口，按对面房间的回头出口改正（2026-10-18，KB 06 §7.257）

房间出口 `"west": __DIR__"xxx"` 指向的文件本库没有，玩家走过去就被卡住（笔误、改过名的房间，或者没带进档案的编号房间）。对面的房间存在、并且它相反方向的出口正好指回这个房间，说明出口原本就是通向它：`/d/for_martea/neon_playground/grassland` 的 `south`：`shanpo` → `kezhan`。改动后每个出口都能解析到本库的文件（`scripts/lpc_fix_dead_exits.py`；目标在运行时本来就能载入的库——虚拟房间——不动）。

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 31 处、13 个文件：`dabei-trike`→`dabei-strike`（12 处）、`qingping-sword`→`qingpingsword`（10 处）、`fumotaff`→`fumostaff`（4 处）、`draginstrike`→`dragonstrike`（2 处）、`cloud-staff`→`cloudstaff`（2 处）、`qingfengsword`→`qingfeng-sword`（1 处）。（`scripts/lpc_fix_skill_names.py`）

## 全局头文件丢了 3 个宏（2026-10-19，KB 04 §6.16）

`/include/globals.h` 里没有定义 `ROOM_D`、`BACKUP_DIR`、`MONEY_D`，用到它们的物件（名单里 3 个）编译时报 `Undefined variable`/`Undefined function`，整个物件载入不了（编译器在第一个未定义的名字上停下，后面的错误和警告都看不到）。同系的库在各自的头文件里都有这几行：照其中和本库共有文件最多的那个库，原样补到 `/include/globals.h` 最后一个 `#define` 之后，宏体里出现的路径在本库里都存在。补完后名单里有 2 个载入，其余还差别的东西。（`scripts/lpc_restore_defines.py`）

## sanniang 的 query(environment(...))->query（2026-10-19，KB 06 §7.266）

`d/biancheng/npc/sanniang.lpc`（边城的三娘）里写成了 `query(environment(this_object()))->query("discussion_shen")`，多了外面一层 `query(`，驱动报 `Bad type for argument 1 of query ( string vs object )`，整个 NPC 载入不了；同一个文件另一处正确写成 `environment(ob)->query("discussion_shen")`。去掉多余的 `query(`。

## 一行写完的源文件还原（2026-10-19，KB 06 §7.272）

下列 2 个文件的整个源码挤在开头的一行 `//` 注释里（档案的编辑器丢了换行），驱动只编译出一个空程序，物件载入后没有名字、没有 id、拿不到手上：`/d/taoyuan/npc/kid.lpc`、`/daemon/condition/idiot.lpc`。`scripts/lpc_uncollapse.py` 按语句、语句块、`#include` 重新分行，再过一遍格式化。还原后逐个载入没有退步，`new()` 出来的物件有名字和属性。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 两个斜杠开头的物件路径（2026-10-19，KB 06 §7.276）

4 个文件、4 处物件路径写成 `//…`（如 `carry_object("//clone/cloth/hic_cloth")`）：`/d/bat/npc/dizi.lpc`、`/d/cave2/npc/dizi.lpc`、`/d/eren2/npc/dizi.lpc`、`/d/eren2/npc/dizi_a.lpc`。当年的驱动不介意（路径先被规范化）；新驱动把原样的字符串交给 master 的 `valid_read()`，securityd 按 `//clone` 查目录，NPC 的 euid 没有权限，报 `Read access denied.`，NPC 载入不了。改成一个斜杠。

## 标准整理轮，第二轮（2026-10-19，`scripts/toolkit_fix.sh`）

本库在新驱动下重扫，机械修复：2 个未使用的局部变量。修后与 HEAD 逐个物件对比载入，没有退步。

## 旧驱动的类型宽松：缺省参数、无类型形参、数组初始化、`class` 变量（2026-10-19，KB 04 §6.19、§6.20）

原来的 MudOS 把调用少传的参数补 0、把没写类型的形参当 `mixed`、不检查变量的声明类型与初始值，也允许变量叫 `class`；这个驱动在编译时全部拒绝，整个物件载入失败。修了 2 个文件：`/d/eren2/npc/fighter1.lpc`、`/d/eren2/npc/fightnpc.lpc`（`scripts/lpc_round_files.py` 的修复轮：调用处补写 `0`、无类型形参补 `mixed`、`string X = ({...})` 补星号、void 函数的返回值，以及 `class` 变量改名 `pick_class`）。逐个文件在 HEAD 和改后载入对比：这些文件里 1 个原来载入失败、现在载入，没有退步。

## `x == "a" || "b"`：后面的字符串常量永远为真（2026-10-19，KB 06 §7.281）

`if (arg == "yuyou" || "yu you")` 里的 `"yu you"` 是非空字符串，永远为真，整个条件对任何 `arg` 都成立；作者要的是每个字符串都和变量比较。具体是：战斗精灵里只该对 hatred / vendetta 出现的追杀提示对所有类型都出现；战斗精灵里只该对 hatred / vendetta 出现的追杀提示对所有类型都出现。在每个字符串前补上变量和运算符（`scripts/lpc_fix_literal_or.py`；`forrest2.lpc` 是 `dir == "north" && "south"`，手工改成 `(dir == "north" || dir == "south") && ...`）：`/adm/daemons/combatd-4-17.lpc`（1 处）、`/adm/daemons/combatd-4-20.lpc`（1 处）、`/daemon/skill/xuemo-blade.lpc`（1 处）、`/std/char/quest_npc.lpc`（1 处）。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。改动：`/d2/shanxi/obj/jiuwan.lpc`（1 处）、`/gift/jiuwan.lpc`（1 处）。另有 `/d/jinan/npc/1mj.lpc`（3 处）、`/d/jinan/npc/jiaoqi.lpc`（2 处）、`/d/jinan/npc/mj.lpc`（2 处） 的条件下面做的是别的事（`==` 和 `||` 也可能是本意），保持原样。

## `member_array('/', str)` 改为 `strsrch(str, "/")`：字符字面量的 member_array 按字节搜索（2026-10-20，KB 06 §7.283）

`member_array('/', str)` 里的 `'/'` 是整数，驱动按 UTF-8 **字节**搜索，返回字节偏移（带第三个参数时起点也是字节）；最新的 FluffOS（923cdbc0）在字符串里有非 ASCII 文字时，对每个调用点警告一次（`Warning: member_array(int, string) searches BYTES`）。而 `str[0..idx-1]` 按字符切，中文字符串会在错误的位置截断。改为 `strsrch(str, "/")`（找不到同样返回 -1，按字符计数；`scripts/lpc_fix_member_array_char.py`，JSON 编码器等少数几处手改）。改动：`/adm/daemons/vrm_server.lpc`（1 处）、`/d/for_martea/neon_playground/migong/adm/daemons/vrm_server.lpc`（1 处）、`/std/room/vrm_server.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 24 处）。改动：`/d/damage1.lpc`（2 处）、`/d/eren2/npc/obj/key.lpc`（1 处）、`/d/for_martea/maze/wood-room.lpc`（1 处）、`/d/huangshan/jiusi.lpc`（2 处）、`/d/jinan/mjroom.lpc`（1 处）、`/d/jinan/mjroomBUG.lpc`（1 处）、`/d/resort/teagarden.lpc`（2 处）、`/d/shanliu/npc/xiucai.lpc`（1 处）、`/d/taiping/npc/obj/key.lpc`（1 处）、`/d/yinghe/irongate.lpc`（1 处）、`/d/yinghe/irongate2.lpc`（1 处）、`/d/zangbei/cave.lpc`（2 处） 等 16 个文件。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/obj/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## `TASKNPC_D` 的路径少了一个 s：`/adm/daemon/tasknpcd`（2026-10-20，KB 06 §7.325）

`include/globals.h` 里 `#define TASKNPC_D "/adm/daemon/tasknpcd"`，守护进程文件是 `/adm/daemons/tasknpcd.lpc`：裸指令 `enroll` 在扫描里打印了 24 次 `call_other() couldn't find object '/adm/daemon/tasknpcd'`（任务 NPC 每次心跳问这个守护进程都是同样的错误）。同一棵树里 `d/for_suu/globals.h` 的写法是对的。改成 `/adm/daemons/tasknpcd`（fengyun434、fysjmb、xsfyssjb 三个飞扬系库同一处）。实测：`enroll` 显示用法，控制台无报错。`QUESTNPC_D`（`/adm/daemons/questnpcd`，`questnpc` 指令用）指向一个所有库都没带的守护进程，属于内容缺失，没动。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库有 93 个 NPC 文件写成 `set("chat_msg", ({ }))`（或 `chat_msg_combat`）并带正的 `chat_chance`（例如 `/d/biancheng/npc/bandit1.lpc`、`/d/biancheng/npc/tuozi.lpc`），每次心跳有 `chat_chance`% 的概率 `random(0)` 为 0、`msg[0]` 报 `Array index out of bounds`（驱动捕获，心跳继续，但每次一条运行时错误），这个 NPC 在内存里就一直发生。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/d/for_martea/for_suu/tasknpc.lpc`、`/std/char/quest_npc.lpc`、`/std/char/tasknpc.lpc`（共 3 个文件）。
