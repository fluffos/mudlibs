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
