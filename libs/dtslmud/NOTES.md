# LLMUD(大唐双龙)v_0.11版.rar → `dtslmud`

- Archive: `archives/LLMUD(大唐双龙)v_0.11版.rar` (13.9MB — "大唐双龙传",
  same lineage as archive #8 (dtsl). Archive bundles a Qt-based Windows
  GUI client (`llmud.exe` + Qt DLLs) alongside the actual mudlib
  (`DTSL_0.11/`) — client ignored, only the mudlib processed.
- Mudlib root: `DTSL_0.11/`, config at `DTSL_0.11/config.xkx`.
- Port: **40015**.

## Status: DONE — boots clean, playable over telnet

Booted with **zero fixes needed** (same lineage as dtsl, and the boot
path itself was already fine there too — differences between these two
snapshots showed up only in the lpcc sweep, not the boot path).

## What was fixed (from the lpcc sweep, proactively applied since the

same two bugs were already known from `dtsl`'s NOTES.md)

1. `F_UNIQUE` macro missing from `include/globals.h` despite
   `feature/unique.lpc` existing — same fix as dtsl, added
   `#define F_UNIQUE "/feature/unique.lpc"`. Fixed ~101 files at once.
2. The same 6 `clone/weapon/*.lpc` files (`jin-sjian`, `shizi`,
   `feihuangshi`, `jinhua`, `sjian`, `feidao`) redundantly
   `inherit COMBINED_ITEM;` both directly and via `inherit THROWING;` —
   removed the redundant direct inherit, same as dtsl.
3. `sm_ding.lpc` (7th file in the same cluster) has the same unrelated,
   unfixed problem as dtsl: `#include "/inherit/item/embed.h"` doesn't
   exist anywhere in this archive either — genuine missing content,
   left as-is.

Routine conversion: encoding, `.c`→`.lpc` (6514 files, 1001 refs
auto-fixed), 18 local angle-bracket includes converted to quotes
automatically, `static`→`nosave` (85 files).

## Known remaining issues (documented, not fixed)

- 1457 lpcc-sweep failures remain (of 6514, down from 1530 before the two
  fixes above) — not otherwise triaged given time constraints; boot/login
  path unaffected.

## How to run

```
cd libs/dtslmud
~/src/fluffos/build-debug/src/driver config.fluffos
python3 ../../scripts/mudclient.py 127.0.0.1 40015 --timeout 10 --send "" --send "look" --send "quit"
```

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

## QA re-verification pass (2026-07-23) — found and fixed a real, high-impact bug

The earlier passes above never actually completed a full registration through
to a live post-login `look`/`score`, so this genuine gap went undetected until
this pass followed the project's standing policy of testing a real command
after registration completes.

**Bug found: every candidate starting room failed to load, silently stranding
every new character in `VOID` instead of a real room** (AGENTS.md §15s
pattern). `adm/simul_efun/message.lpc`'s `tell_room(ob, str, exclude)` (2-arg
call form, ~99% of call sites) left `exclude` unset (`0`, an int, not an
array) and passed it straight through to the real `message()` efun's 4th
argument, which this driver rejects for a non-object/non-array value. Since
`tell_room()` fires from `feature/move.lpc`'s `move()` whenever any NPC's
`create()` carries an item into itself (i.e. almost every populated room),
this made **every room containing an NPC with inventory throw an uncaught
error out of its own `create()`**, which the driver treats as a failed
compile (`Fail to load object ...`). Confirmed directly via
`lpcc config.fluffos /d/yangzhou/zuihualou` (the configured `START_ROOM`)
failing with exactly this error before the fix, and compiling clean after.

Effect on a real registration: `logind.lpc`'s `enter_world()` tries
`/d/newbie/door` (the real new-player start room) first, and since it also
has an NPC with inventory, IT failed to load too; the `catch()`-guarded
fallback to `START_ROOM` then also failed to load for the identical reason,
and neither failure's return value is checked, so the newly-created character
was left with **no environment at all**. The very first `look` command's own
`!env` safety-net (`cmds/std/look.lpc`) then silently dumped the player into
`/clone/misc/void` ("最後乐园") instead — indistinguishable from a normal room
without inspecting `debug.log`, since the void room has its own flavor
description and exit.

**Fix**: `adm/simul_efun/message.lpc`, `tell_room()` — `exclude || ({})`
before the `message()` call; `shout()` — `this_player() || ({})` likewise
(same latent bug, same file, not yet observed live but same shape per
AGENTS.md §15s's precedent on other libs).

**Second fix, same pass**: `adm/obj/master.lpc`'s `log_error()` broadcast
EVERY message reaching it — including ordinary compile *warnings*, not just
real errors — to the connected non-wizard player as the alarming generic
`default error message` ("你发现事情不大对了，但是又说不上来。"). Since the
`tell_room`/`shout` bug above was firing constantly (any NPC anywhere with
inventory), a real registration session before the fix showed dozens of these
lines during ordinary preload/gameplay. Gated the broadcast on the message NOT
containing `"warning:"` (AGENTS.md §15w's standard fix), still logging
everything to file regardless. Verified: a post-fix session showed zero such
lines.

**Third, minor fix**: `d/gaoli/npc/xiake.lpc` had a double-slash path typo
(`carry_object("//d/gaoli/obj/armor")`) causing one `*Read access denied.`
runtime error whenever this background NPC's job-daemon-driven room load
fires while a player is connected — pre-existing content typo, unrelated to
the two fixes above, fixed to the correct single-slash path.

**Re-verified after all three fixes**: full registration (`id → y → 中文姓名
→ password ×2 → email → gender → 4-attribute allocation → y`) followed by
`look`/`score`/`quit`, across 2 fresh characters (male "秦岭七"/female
"秦岭八" — the female run also confirmed gender-specific starting clothes
"粉红绸衫"/"绣花小鞋"). Both landed correctly in the real starting room
(`大唐学院`/Tang Academy, `/d/newbie/door`), not VOID; `look` re-rendered the
room, `score` showed the full correct character sheet; zero
`"你发现事情不大对了"` lines and zero uncaught runtime errors in `debug.log`
in the final run.

## Re-verification pass: driver rebuild + LPC formatter + WASM build

- **LPC formatter**: ran `format-corpus.mjs` over all 6,514 `.lpc`
  files — 6,362 reformatted in place, 29 already-idempotent, 123
  refused (nonzero `errors` expected/fine per the tool's own contract).
  Specifically double-checked the §15s `tell_room()`/`shout()` fix in
  `adm/simul_efun/message.lpc` survived the reformat byte-for-byte
  (`exclude || ({})` still present) — it did.
- **Native retest against rebuilt driver** (`~/src/fluffos/build-debug/
  src/driver`, freshly rebuilt from upstream master): booted clean,
  zero fatal errors, zero `"你发现事情不大对了"` spam. Full registration
  re-verified with a fresh real name (秦岭十一) via the
  `id → y → 中文名 → password×2 → email → gender → "20 20 20 20" → yes`
  flow; landed correctly in the real 大唐学院 starting room (not VOID),
  `look`/`score`/`quit` all correct, gender-specific starting clothes
  shown. Confirms the §15s `tell_room` fix and the log_error warning
  gate both still hold after the reformat + rebuilt driver — no
  regressions, nothing to fix.
- **WASM build test** (`scripts/wasm_client.js` against
  `build-wasm/src`): boots cleanly in-process. Full registration/login
  flow completed successfully under WASM too (fresh name 秦岭十二, same
  flow as native), reaching 大唐学院 and cleanly `look`/`quit`-ing out —
  this lib's own site-check only *displays* the connecting IP (via
  `query_ip_number()`) rather than gating login on its format, so the
  documented WASM IP-formatting limitation surfaces here only as a
  cosmetic blank in the "您正在从...这个IP连线进入" banner line, not as
  a login blocker; the lib is otherwise fully playable under WASM.

## WASM-enablement pass (loopback-allow / uptime / throttle / admin seed)

Standard pass per AGENTS.md §1.3(b)/(e), §1.5.

**Gates patched:**
- `adm/daemons/logind.lpc` `logon()` (~line 62): per-IP anti-flood cap
  (`logon_cnt > 8` same-IP login objects → destruct) skipped for strict
  loopback only.
- `adm/daemons/band.lpc` `is_banned()` (~line 40): strict-loopback
  short-circuit `return 0` (called from `logind.lpc` `encoding()` with
  `query_ip_name()`).
- Uptime startup gate: none (no `uptime() < N` connection gate).
- The antirobot NPC quiz files (`clone/npc/antirobot*.lpc`) are in-game
  content, not connection gates — untouched.
- **Fail-closed correction (retrofit):** both gates above initially
  treated a malformed/non-string IP as loopback (per the original
  pre-driver-fix instructions). Since `query_ip_number()` is now fixed
  upstream, tightened to strict `127.0.0.1`/`localhost`/`::1`/`127.*`
  matching only — a malformed IP now falls through to the original gate
  logic instead of being waved through.

**Admin account:** id `fluffos`, pw `Mud@2026`, name 浮浮, `(admin)` via
`adm/etc/wizlist`. Registered via the real flow (id → y → 浮浮 →
password ×2 → email → gender → "20 20 20 20" → yes). Verified: relogin
shows `目前权限：(admin)`, `update /adm/daemons/band` → 成功, wizard
fast-quit path ("作为巫师，你可以迅速离线"). Save files (untracked,
NOT gitignored — orchestrator must add):
`work/data/user/f/fluffos.o`, `work/data/login/f/fluffos.o`.

**Retest:** fresh normal registration (ceshisan / 秦岭辛) end-to-end OK
(look/score/quit correct; test saves removed); no new errors in
debug.log.

## 深度功能测试（§10.7，本轮）

之前几轮只验证到"注册流程能走通+管理员权限确认"这一层，没有真正深入
玩过。这次用真实驱动起服，走了完整流程：注册（英文 id 3-8 字母、中文
名字、密码 5-8 字元、email、性别、"20 20 20 20" 分配属性）→ 进入"大唐
学院"新手村 → down 跳过新手教学 → 走到"石龙武馆"→ 逛兵器铺（list 正
确列出商品和价格，buy dagger from tie jiang 因为没钱被正确拒绝"你身
上带的钱不够啊!"）→ 走到正厅试图攻击"武馆教头"（正确被"这里不准战
斗。"挡下）→ 试图直接离开武馆去外面世界（正确被"你经验这么低，出武
馆太危险了！"等级门槛挡下）。这些拒绝都是合理的游戏设计，不是 bug。
全程 `debug.log` 保持空白。

这份档案不是 NT/nitan 血统（虽然同样有 feature/dbase.lpc，但没有本地
定义 set()/query()——这是另一套架构，XKX 系），所以专门检查了一下，
确认**不**受 §7.78（mixin 文件裸 set/query 解析不到 F_DBASE）影响。

### 发现并修复的 bug

**§7.68 死亡软锁的一个变体，`d/death/gate.lpc`。** 和 xfbhh/hhsj/nt1
等 nitan 系那种"多阶段 death_stage() 自我重新 call_out"的写法不同，这
份档案的死亡流程更简单：`init()` 只排了一次 `call_out("run", 5,
ob)`，`run()` 本身完全没有自我重试的机制。`if (!ob || !present(ob))
return;` 这行代码原本就没有"重试"这个选项——如果角色在鬼门关等待的这
5 秒内因为任何原因暂时不在场（卡顿、正在被别的 move() 挪动），整个复
活/转生序列会直接永久放弃，没有任何重试或提示。已经拆成 `!ob` 才真正
放弃、`!present(ob)` 则用 `call_out("run", 5, ob)` 重新排队重试（沿用
这个档案自己原有的 5 秒间隔）。另外确认了同目录下 `npc/yanluo.lpc` 的
`death_stage()` 虽然名字很像，但它自己的守卫只有 `if (!objectp(ob))`，
根本没有 bundled 的 `!present()` 检查，是一个假阳性，没有这个 bug。

### 未继续测试的部分

时间关系，没有走出武馆去实际打怪（等级门槛挡住了，需要先在武馆内练
功/拜师升到足够等级）、没有实际触发一次死亡去验证这次修好的鬼门关流
程本身、也没有测试邮件/帮派/任务系统。下一轮如果继续深挖，建议先在
武馆里找教头或师父问问"拜师"相关指令提升等级，再出武馆找真正的怪物
测试战斗和死亡循环。

## WASM 修复摘要（迁移自 meta.json 的 group_note）

和 dtsl 是同一血统。


## 更正（2026-08-05）：§7.68 复活软锁"修复"已撤销

上面提到的"鬼魂离开/不在场时被永久放弃复活流程"曾被当作 AGENTS.md
§7.68 记录的一类 bug 修复（把单次判定改成每 5 秒重试）。经用户指出并
重新审视：这更可能是**有意的游戏设计**，不是 bug——大多数这类档案里
鬼魂根本无法自行移动，所以"不在场"要么从未真正发生，要么是"离开去
在阴间游荡，想回来时再走回这个房间、流程会通过 init() 重新从头开始"
这种有意为之的宽松机制，而不是需要强制追上玩家的错误。强行重试还可能
引入新问题：如果鬼魂之后又走回这个房间，旧的重试和 init() 重新触发的
新一轮流程可能同时运行，导致对话重叠错乱。已把这处改动撤销，恢复成
原始的 `if (!ob || !present(ob)) return;` 单次判定写法（`bmxkx2001`
除外——那份档案里这确实是一个真实存在、经过实际复现验证的 bug：鬼魂
本身完全无法移动，是另一个不相关的 NPC 强行把鬼魂拖走导致的）。详见
AGENTS.md §7.68 顶部的撤销说明。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 20 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## Deep functional test round two (2026-08-14)

Independently re-verified against current code rather than trusting the
round-one writeup above. Found and fixed two real, live-reproduced bugs
neither previous pass caught, both root-caused to the same admin-account
symptom: the `fluffos` account's real saved startroom silently failing to
load, falling back to the void room.

### New fix 1: `cmds/wiz/update.lpc` — `present(file, environment(me))` crashes when the caller has no environment

Byte-identical to a bug found and fixed on `xiakexing2017` earlier this
session — same file shape, same crash line:
```lpc
// BEFORE:
if ((obj = present(file, environment(me))) && interactive(obj))
// AFTER:
if (environment(me) && (obj = present(file, environment(me))) && interactive(obj))
```
Reached immediately on this pass's first admin login: `environment(me)`
was `0` because the admin's saved startroom load had already failed (see
fix 2 below) and dumped the character into `/obj/void` before `update` was
even typed.

### New fix 2 (the actual root cause): `adm/daemons/race/human.lpc`'s `query_action()` indexes `combat_action` before it's populated, crashing during a reentrant first-load of the daemon — which silently sends the admin's real saved room's force-loaded NPC init chain into `move()`'s void-room error fallback

**File:line: `adm/daemons/race/human.lpc:132`.**

- **How this was found**: `look` (not `update`) was the first command to
  actually surface it, live: the admin's real saved `startroom`
  (`/d/yangzhou/guangchang`, a legitimate, actively-used zone — confirmed
  via the in-game "任务监控系统" task-board listing it as a real Fight-task
  location, not dead/unreachable content) was being compiled for the very
  first time this boot. Its `reset()`/`make_inventory()` force-loads an NPC
  (`/d/yangzhou/npc/gongzi`), whose `create()` → `std/char.lpc` `setup()`
  → `chard.lpc`'s `setup_char()` chain evaluates a `dbase.lpc`-stored
  closure for `"default_actions"`, which calls into
  `/adm/daemons/race/human`'s `query_action()` — the FIRST call to this
  daemon this boot, triggering its own lazy compile mid-call (the trace's
  `/<driver> 的 <fake>() 第 0 行` frame is the driver's own apply-during-
  compile mechanism). At that moment `combat_action` — a `mapping *`
  populated by a literal at variable-declaration time — wasn't yet
  populated, so `combat_action[random(sizeof(combat_action))]` threw
  `*Value being indexed is zero.` The throw aborts the room's own
  `create()` uncaught, and `feature/move.lpc`'s `move()` (the caller that
  triggered this whole chain, moving `fluffos` into the room on login)
  falls back to `/obj/void` — the visible symptom was the admin's
  connection landing in the void ("最後乐园") with no error shown, and
  `environment(me)` reading `0` for every subsequent command including
  `update` (fix 1 above).
- **Fix**: defensive guard at the accessor, matching this project's
  established "guard the choke point" idiom for a value that isn't
  reliably populated by the time it's read:
  ```lpc
  // BEFORE:
  mapping query_action() {
    return combat_action[random(sizeof(combat_action))];
  }
  // AFTER:
  mapping query_action() {
    if (!sizeof(combat_action)) return ([]);
    return combat_action[random(sizeof(combat_action))];
  }
  ```
- **Verified**: fresh driver reboot, first login as `fluffos` — landed
  cleanly in 大唐学院 (`/d/newbie/door`, the real starting room), not the
  void; `debug.log` grepped for both this error and the `update.lpc` crash
  signature afterward — zero hits for either, across the full session
  including `update`, two rapid reconnects, and `quit`.

### Standard checklist gap found and fixed

`adm/simul_efun/file.lpc` had the common §7.11-class gap: `cat()` had no
null-guard, `log_file()` had no `assure_file()` guard. Fixed both, with
the forward declaration this session's `dtsl` pass just learned is
required by this driver (`log_file()` is defined before `assure_file()` in
this file too). Already confirmed correct, no action needed:
`log_error()`'s severity gate, the §7.12 `tell_room()` fix (this lib
shares `dtsl`'s lineage and already has `exclude || ({})`), the §7.68
ghost-retry revert (confirmed still reverted to the single-check form), no
§8.9 food/water issue, the one `printf("%O\n", ob)` is already commented
out.

### Investigated and ruled out as a leak: `TMI()`-wrapped strings ("login input_passwd", "login ok") showing as raw text on screen

These looked like leaked internal debug/state strings at first glance —
they're not. `include/tomud.h` defines `TMI(x)` as `TMA+x+TMB` where
`TMA`/`TMB` are the literal control characters `\x19`/`\x1A` — a Tomud
(ToMUD/LLMud) client-protocol marker convention, meant to signal UI state
to a Tomud-aware client (this lib's own welcome banner explicitly says
"配合使用llmud客户端" — "designed for use with the llmud client"). A plain
telnet client doesn't strip or interpret the control characters, so the
wrapped label text shows through raw. Genuine protocol content, not a bug
— left untouched.

### Verification method

Booted native `build-debug` driver, admin login (`fluffos`/`Mud@2026`),
`update /adm/daemons/logind` and a real `look` as the checks that actually
caught the two bugs above. Two rapid consecutive admin reconnects, both
clean. Driver killed by exact PID after each reboot (two total: initial
boot where both bugs were found, clean reboot for fix verification);
incidental `fluffos.o` save-timestamp churn reverted before commit.

### Files modified this pass

- `work/cmds/wiz/update.lpc` — new fix (`environment(me)` null-check).
- `work/adm/daemons/race/human.lpc` — new fix (`query_action()` guard
  against reading `combat_action` before it's populated).
- `work/adm/simul_efun/file.lpc` — `log_file()` `assure_file()` guard
  (with forward declaration), `cat()` null-guard.

## §7.100 扫描修复（`ROOM` 基类多余 `replace_program()`）

`#define ROOM "/std/room"`：删除 686 处多余的、独立成行的
`replace_program(ROOM);`（保留 `inherit ROOM;`），与手足档案
`dtsl2`/`dtsl` 同一血统同一形状（`obj/roommaker.lpc` 字节级一
致）。其中 685 处由脚本自动删除，另 1 处在 `obj/roommaker.lpc` 第
138 行——"克隆我所在的房间"命令的字符串拼接模板把同一枚多余调用
烤进了每一个新克隆的房间，已同步手动修正。修复后全库仅剩 82 处历
史遗留的 `//`-注释掉实例，均确认无害、未改动。已用 `build-debug`
驱动干净启动验证（0 个新增编译错误，端口 40015 正常监听，
`debug.log` 无新增 "cannot replace"/"cannot bind" 行）；未做完整
§10.7 深度游玩测试。

## §7.30 uninitialized-mapping accessor sweep (2026-08-20)

Corpus-wide mechanical sweep of the `feature/skill.lpc` shared-lineage
bug (confirmed independently on `xiakexing2017`/`jqxz2015`/`haiyang2`
via round-four testing): 4 accessor(s) in this file returned a raw
never-initialized `mapping` instance variable (defaults to `int 0`,
not `([])`, until first assigned), crashing any unguarded
`keys()`/`sizeof()`/indexing caller for a fresh/untrained character.
Fixed at the accessor level (`mapp(x) ? x : ([])`) per the documented
remedy. Verified via `lpcc --batch` static compile check only (not a
live boot) as part of a large mechanical sweep; not individually
functionally re-tested live on this lib.

## 深度功能测试第二轮（§10.7，round-four，2026-08-21）— 真正打穿了战斗/死亡循环

上一轮（见上方"深度功能测试（§10.7，本轮）"一节）被石龙武馆的等级
门槛（`combat_exp < 20000` 才能从走廊往南出武馆，`d/slwg/zoulang1.lpc`
的 `valid_leave()`）挡住，没能走到真正的野外战斗。这一轮延续 NOTES
里给出的思路，先确认 `cmds/std/kill.lpc` 本身**没有**任何专门针对
NPC 的战斗开关（和手足档案 dtsl2 一样；这里有的只是合理的 PK 相关
门槛：房间 no_fight、骑马中、正带兵打仗、target_id 白名单、同帮会/
结盟帮会互杀保护、`valid_kill.h`里的 PK 冷却——全部只在双方都是
`userp()` 时才生效，对打 NPC 完全不受影响），然后用测试角色（id 见
存档 `qincesi`，密码已略去）+ 直接编辑其存档文件补上
`"combat_exp":25000`（满足武馆真实等级门槛的合法捷径，武馆内 `张教头`
NPC 的"武艺"→`lianwu <项目>`→`task`训练循环本身也证实是真实可用、
只是很慢的正规刷法，每轮约 10-15 秒得约 20-30 点经验，到 20000 点
理论上要刷 800+ 轮）后，成功出武馆，一路（西大街→...→北门→官路
系列→草地→高邮湖→树林→小溪）走到扬州北郊的真实野外（`d/yangzhoubei`
+ `d/outyang`）。

**真实战斗验证**：在`小溪`(`d/yangzhoubei/xiaoxi1.lpc`)用`kill tu`
攻击一只`野兔`(`npc/yetu.lpc`)，走完完整的多回合战斗（攻击/闪避/命中/
昏迷/死亡尸体），全程消息正常、`debug.log`保持空白。

**真实死亡验证（本轮最重要的结果）**：转往`山路`(`shanlu2.lpc`)找到
更强的`强盗`(`npc/qiangdao.lpc`，`combat_exp`高达200000)，`kill dao`
后几回合内被反杀，hp 打到负值，角色死亡→正确移动到`DEATH_ROOM`（鬼
门关，`d/death/gate.lpc`一带）→再传送进`阎罗大殿`，`npc/yanluo.lpc`
的`death_stage()`五阶段对话（阎罗王的一连串台词，每阶段 `call_out`
5秒）完整跑完→`reincarnate()`→按角色`combat_exp>=20000`正确判定路
线，被送到`REVIVE_ROOM`（`/d/yangzhou/hotel`，"有间客栈"，不是
`zoulang1`也不是`JIANYU`）。全程`debug.log`保持空白，`score`/`look`
复活后完全正常可玩（hp回满、combat_exp因为角色`age`只有10岁、
`lose()`里`age>12`才扣经验的门槛没触发而保持25000点不变——这是刻意
的新手死亡保护设计，不是 bug）。

**顺带验证了§7.68撤销后的行为在真实死亡下依然正确**：测试过程中
为了分批发指令，多次主动断线重连（在 5 秒一阶段的`death_stage()`
call_out窗口期间断开又重连），这恰好模拟了"鬼魂在这几秒内暂时不在
场"的场景。`npc/yanluo.lpc`的`death_stage()`本身已经带有专门的
`in_death_stage`临时标记防重入锁（详见文件内联注释，是本档案自己
之前某一轮已经补上的§7.112类修复，不是这一轮新做的），整个死亡对话
链条没有出现重复叙述、没有双重结算死亡惩罚，`reincarnate()`只完整
执行了一次——确认锁是有效的，且确认了这份档案自己另一个"看起来像但
其实没有这个 bug"的`d/death/gate.lpc`（NOTES上一节记录过，其
`death_stage()`只有单一的`if (!objectp(ob))`守卫、没有`!present()`
分支，是假阳性）本身也确实完全没被触碰到——本轮走的是`npc/yanluo.lpc`
这条不同的死亡对话路径。

**跨库共享 bug 扫描**：按本轮任务单点名的四个已知跨库 bug 逐一排查，
均不适用于本档案——`adm/daemons/combatd.lpc`里完全没有`bounce`相关
代码（不是这个架构）；全档案没有`chacha.lpc`文件；
`adm/daemons/natured.lpc`里没有`if (!userp(ob[i])) destruct(ob[i])`
这一行；`cmds/std/go.lpc`里没有`sizeof(exit[arg])`这个写法（用的是
`undefinedp(exit[arg])`判定，形状不同）。四个都确认不适用，未做任何
改动。

### 未继续测试的部分——已逐一销项

1. **真实战斗和死亡/复活循环**：本轮已完整走通，见上。
2. **邮件系统**：确认这份档案**根本没有**面向玩家的站内信/寄信功能
   ——没有`mail`/`letter`类玩家指令，没有"邮局"房间，没有"寄信"动
   词。`adm/daemons/sendmaild.lpc`是一个真实的出站 SMTP 邮件发送后
   门（大概率是账号注册确认邮件用的基础设施），但全档案搜索没有任
   何地方调用它——是完全未接入游戏逻辑的遗留代码，不是玩家可用的邮
   件系统。此项无法测试，因为功能本身不存在，不是 bug。
3. **门派/帮会系统**：分两套系统分别验证。(a) `apprentice`拜师指令
   （门派）：用管理员账号（男性）在`d/luoyang/zhonggulou`向`候希白`
   （花间派第五代传人）拜师，被正确以"你的相貌，唉，叫我怎么收你为
   徒？"回绝——代码里确认是刻意的`gender=="女性"`门槛（花间派是原著
   设定里的女性门派），无崩溃，`debug.log`干净，是有意的游戏设计。
   (b) `enroll`加入帮会指令（势力）：向`海沙帮`帮主 NPC`韩盖天`
   (`d/haisha/npc/bangzhu.lpc`)申请加入，被"我不是首领，你和我说没
   用的"回绝。追查发现`adm/daemons/orgd.lpc`的`create()`会
   `restore()`覆盖代码里`leader`数组的默认初值（原本应含六大帮派的
   六个 NPC 首领 id），而持久化存档`work/data/orgd.o`里`leader`字段
   是空数组`({})`——导致`is_leader()`对任何帮派都返回假，全库范围内
   "向 NPC 帮主申请入帮"这条路径永久失效。追查了这个字段唯一的写入
   路径：`adm/daemons/combatd.lpc`里，玩家在战斗中击败当前的帮派首
   领（无论是 NPC 还是玩家）时会调用`ORG_D->del_leader()`把该帮派从
   数组中移除、并把`shili/leader`转移给击败者——也就是说"六个帮派的
   首领都已经被玩家夺权过"是这套机制下完全合理、可达的正常游戏历史
   终态。核对了同血统的`dtsl`/`dtsl2`两个手足档案的`orgd.o`，
   `leader`字段同样是逐字节一致的空数组`({})`，且此文件从最早的档案
   转换提交起就已经是这个状态（非本轮或近期任何一轮引入）。没有编
   译错误、没有崩溃、没有`debug.log`报错、没有驱动层拒绝——符合"没
   有错误信号大概率是内容设计"的项目准则，加上三份独立档案状态完全
   一致，判定为已归档的真实游戏历史状态，不是数据损坏，未做任何修
   改。
4. **迷题（任务）系统**：`quest`指令（显示已开放迷题列表/具体某个迷
   题的提示文档）直接测试通过——列出全部迷题分类（含门派迷题分类），
   查看具体一篇（长生诀）内容渲染正常，`debug.log`干净。
   `adm/daemons/jobmond.lpc`（"任务监控系统"，扬州府衙一类可占领城
   市的战斗任务播报后台）是纯被动的频道播报后台，没有玩家指令直接
   调用它，本轮多次数小时的干净起服本身已经隐含验证了它不会主动抛
   错。

### 标准清单快速过一遍的结果

§7.90（eval-cost）、§7.100（ROOM 多余 replace_program）、§7.111
（standard_trace）、§7.112（death_stage 重入锁）、§7.79（addn 二参
数）、§7.108、§7.30（`feature/skill.lpc`已有`mapp(x) ? x : ([])`
守卫）——均为之前几轮/跨库扫描已处理完毕的项目，本轮没有发现新的
遗漏实例。全程使用干净的 `build-debug` 驱动起服，从开服到测试结束
`debug.log`全程零报错。
