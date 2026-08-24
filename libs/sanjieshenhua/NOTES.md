# 三界神话-春节.rar → `sanjieshenhua`

- Archive: `archives/三界神话-春节.rar` ("Spring Festival" snapshot of 三界
  神话 / "SanJie Myth"), nested at `sanjie/` inside the RAR. ~15.7k raw
  files, 12,871 `.lpc` files after conversion. This is a "Century/
  adm-single family"-shaped custom-securityd lib (per AGENTS.md §11) —
  bundles the ORIGINAL MudOS v22pre11 driver's own C source under
  `bin/v22pre11/` (harmless dead weight — never referenced by
  `master`/`mudlib directory`, our own driver is used instead; left in
  place rather than deleted, per AGENTS.md §3's "ignore bundled driver
  source" guidance).
- Proposed number: **060** (new, unique — see "Lineage/triage" below).
- Port: **40098** (as assigned; confirmed free).
- Status: **DONE** — boots clean, full registration verified end-to-end
  with a real Chinese name (云飞) natively AND under WASM, admin
  (`fluffos`) verified via `update` on both drivers (after a data-file
  fix — see below).

## Triage / lineage

Genuine LPC mudlib (`inherit` everywhere). Diffed core files against
sibling `sjcs` (also in this batch, shares the "三界" title
prefix) — substantially different `master.lpc`/`securityd.lpc`/
`logind.lpc` (416/747/1179 lines here vs 495/316/1718 there) — **not** a
derivative pair, same conclusion as documented in `sjcs`'s
NOTES.md. Treated as a fully independent unique game.

## State at handoff (this session)

A previous agent session had already: extracted the archive, converted
encoding/renamed `.c`→`.lpc`, written `config.fluffos` (port 40098),
applied the loopback-allow patch to `sited.lpc`/`band.lpc`, exempted
loopback from the login-count anti-flood check in `logind.lpc`, fixed the
`protected`→`nomask` `command_hook`, and appended `fluffos (admin)` to
`adm/etc/wizlist`. No `fluffos` player-save existed yet (registration not
attempted), no NOTES.md/README.md. This session completed the pipeline.

## Fixes applied this session

1. **1 corrupted file**, same exact corruption as sibling
   `sjcs`: `d/sea/npc/beast1.lpc` — 2 trailing garbage bytes
   (`\xff\xba`) right after a clean `}\n\n` ending, confirmed present in
   the raw archive itself. Truncated the 2 bytes.
2. **Wizard write-ACL default was fully deny-by-default, so a freshly
   seeded `(admin)` account could log in, show `(admin)` status, but
   could not actually write/compile anything** — a new bug class worth
   flagging for AGENTS.md. `adm/daemons/securityd.lpc`'s
   `query_security("default_trusted_write")` returns an ENTIRELY EMPTY
   mapping (its only line, `"/" : ({"(admin)"})`, is commented out in the
   source — an authoring artifact, not something the conversion touched);
   `valid_write()`'s directory-walk ACL therefore finds no `trusted_write`
   entry at any level and denies every write outside a few hardcoded
   exceptions (own `/u/<id>/`, save-file paths, `/binaries` removal).
   The lineage's own runtime mechanism for granting broader write access
   (`cmds/adm/auth.lpc`, which edits `extend_trusted_write` and persists
   it via `SECURITY_D->save()`) is itself gated to two hardcoded
   historical uids (`mudring`/`stey`) — `fluffos` cannot invoke it.
   Confirmed root cause via `update /adm/obj/master.lpc` failing with
   `读写权限不够无法更新！` despite `(admin)` status.
   **Fix** (data, not code, per AGENTS.md §1.5's "prefer editing data"):
   wrote `data/static/securityd.o` (the save file `query_save_file()`
   points at — did not exist in the archive at all) seeding
   `extend_trusted_write (["/":({"(admin)",}),])`, restoring exactly what
   the commented-out default would have granted. `securityd.lpc`'s own
   `restore()`/`::restore()` (via `inherit F_SAVE`) picks this up
   automatically on every boot. Verified: `update` now succeeds for
   `fluffos` both natively and under WASM. **This same "commented-out
   default, no seed data" shape may recur on other Century/adm-single
   family libs with dead admin write-ACLs — worth checking
   `default_trusted_write`/`default_trusted_read` for a fully-empty
   result on any future lib in this family, even if `(admin)` status
   displays correctly at login.**

## Verification (native)

Booted `cd libs/sanjieshenhua && ~/src/fluffos/build-debug/src/driver
config.fluffos` — clean boot, zero fatal errors in `log/debug.log`.

Full registration flow (fresh id `yunhang`, real Chinese name **云飞**):
English id (3-8 lowercase letters) → `new` → id again → admin/recovery
password (5+ chars) → confirm → normal password (5+ chars, must differ
from admin password) → confirm → Chinese name → email (must contain `@`
and `.`, length ≥ 9) → character type (1-6) → gender (m/f) → entered
`南城客栈`. `look`, `score` (full 个人档案 card), and `quit` all correct
(tested via reconnect after this lib's 60-second same-account
quit-retention gate elapsed — a normal game-design timer exempting
wizards, per AGENTS.md §1.3e's "keep in-game content timers" rule, not a
hosting-protection gate to bypass).

Admin: registered `fluffos` through the SAME normal "new" flow (id
`fluffos`, admin/recovery password + normal password `Mud@2026`, display
name 浮浮) — the pre-seeded `fluffos (admin)` wizlist line was picked up
immediately, "您的系统权限目前是：(admin)" shown on first login. This
lineage has a THIRD password (`WIZPWD`) for wizard-level accounts, but
`NO_CHECK_WIZPWD` is `#define`d in `logind.lpc`, so any input (including
empty) bypasses it. After the `securityd.o` seed fix above,
`update /adm/obj/master.lpc` → `重新编译 /adm/obj/master.lpc ...成功！`.
`quit` clean.

## Verification (WASM)

`node scripts/wasm_client.js ~/src/fluffos/build-wasm/src
libs/sanjieshenhua` — same full registration flow (fresh id `wasmtes`,
name 沐晨) reached the same starting room; `look`/`score`/`quit` all
correct. Admin login as `fluffos` + `update /adm/obj/master.lpc` also
succeeded under WASM (reads the same `data/static/securityd.o` seed via
the MEMFS copy of `work/`). **This lib is fully playable under WASM.**

Testing gotcha worth recording: this lineage's post-login prompt embeds a
live `HH:MM:SS` clock that updates every second, so a single mudclient/
wasm_client invocation needs a SMALL `--idle` (~0.3-0.5s) to catch the
gap between commands once in the world — but the async "首次登录天赋
分配" (first-login stat-allocation) dialog that fires right after
character creation needs a LARGER idle (~1.0-1.5s) to avoid a race where
`9`/`y` are sent before the menu has actually printed (landing as bare
invalid commands instead). Used two separate connections (registration+
gift-confirm with large idle, then a reconnect with small idle for
look/score/quit) to work around this natively; for the WASM one-shot test,
`--idle 0.5` plus one extra blank "absorber" send between gender and `9`
was enough to make both phases work in a single continuous session.

## Known remaining issues (documented, not fixed)

- `bin/v22pre11/` (the archive's bundled original driver C source) is
  inert dead weight in the tree — never loaded by our driver, left as-is
  per AGENTS.md §3.
- lpcc sweep not re-run this session (no `lpcc_fail.log` was left by the
  prior session); the real boot + full interactive registration/admin
  test is the verification gate actually used, per AGENTS.md §10.4's
  guidance for large trees.

## 深度功能测试（第二轮，2026-08-03）

之前只做过注册流程 + 管理员权限验证的浅层测试，本轮做了完整的
§10.7 深度功能测试。proactive 检查了 AGENTS.md 已归档的四类常见坏
味道（private command_hook、未防护的 MESSAGE_D->、stat/water vs
stat/drink 键名、logind.lpc 里的 printf("%O") 调试残留、§8.9 的坏
age 判断）——只命中了一个：`printf("%O\n", ob)` 调试残留。

**发现并修复的两个真实 bug：**

1. **`adm/daemons/logind.lpc` 的 `get_name()` 里有一行调试残留
   `printf("%O\n", ob)`**，把登录连线物件的内部路径直接打在"您的中
   文名字："和"您的电子邮件地址："两个提示之间，每一个新玩家注册时
   都会看到（AGENTS.md §7.34，新增本 lib 到确认实例列表）。已删除。
2. **角色职业选择菜单的显示文字和实际赋值对不上**——菜单显示
   `5. 均衡型`，但 `get_type()` 的 `switch` 语句里 `case 5` 实际赋
   值的是 `"野蛮人"`（一个菜单上根本没出现过的名字）。选 5 号会立
   刻看到"您选择了野蛮人的角色"，而不是"均衡型"。往下查发现
   `enter_world()` 把这个值存进 `user->set("hell_type", ...)`——
   "hell_type" 这个字段名本身就是线索：这个值其实是喂给这个 lib 独
   立的 `daemon/hellfire/`（地狱业火）战斗子系统的，"野蛮人"在那整
   套系统里（攻击效率表、职业专属 NPC 逻辑）被大量引用，而"均衡
   型"在全库搜索不到第二处引用。另外还找到一份姊妹菜单
   （`d/wiz/init2.lpc`，同一套 hellfire 系统的另一个旧入口）显示的
   同样六项菜单，5 号原本就叫"野蛮人"——足以确认是显示文字漂移，不
   是 switch 语句写错。已把菜单文字改成"野蛮人"，和 switch 语句、
   姊妹菜单保持一致；switch 语句本身没动（新增 AGENTS.md §7.67）。
   用两个全新注册角色对照验证：修复前选 5 号看到"您选择了野蛮人"
   （和菜单文字矛盾），修复后菜单文字和确认文字一致，`score` 里"你
   现在的角色"字段也正确显示"野蛮人"。

**完整流程验证**：连续注册两个全新中文名角色（沐清风/id `sjfour`、
沐战/id `sjfive`），从"gb"选码一路走到分配天赋（0-3可调，9接受），
进入起始房间南城客栈；`hp`/`score`/`i` 均正确（气血、精神、食物、
饮水槽满，装备栏为空，角色类型正确显示）；西行至朱雀大街，向"疥顶
小僧"NPC 发起战斗（`kill xiaoseng`），完整交手数回合（双方攻击叙
述、伤害结算、"似乎有些疲惫"体力消耗提示均正常渲染，我方未受到实
质伤害），战斗系统工作正常；`quit` 干净退出（"欢迎下次再来！"），
debug.log 全程无报错。

**测试环境细节记录**：这套引擎的登录后提示符自带一个每秒刷新的
`HH:MM:SS` 实时时钟，几乎不会出现真正的空闲间隙——用较大的
`--idle`（如 2.5s）反而会让 `mudclient.py` 因为一直等不到空闲而被
`--timeout` 硬截断，命令来不及送达；已验证的做法是用较小的
`--idle`（0.3-0.5s）配合足够长的 `--timeout`。另外还发现一个独立于
60 秒退出冷却期之外的"重新连线冷却"（"你距上一次重新连线时间只有
X秒钟，请稍候再登录"），短时间内反复断线重连也会被挡——多次连接测
试时最好用不同的全新角色，而不是反复重连同一个角色。

**未覆盖范围（诚实记录）**：`help newbie` 文档写的是"刚进入时，你
的食物和饮水都是空的"，但实测两个新角色的食物/饮水槽在创建时就是
满的（200/200，正常）——这是文档和实际行为不一致，但不影响任何功
能（不会导致挨饿死亡或报错），判断为文档陈旧而非程序 bug，未做处
理，留待有余力时再核实是否值得更新文档措辞。商店购买、门派加入、
帮会系统本轮未实测。

## How to run

```
cd libs/sanjieshenhua
~/src/fluffos/build-debug/src/driver config.fluffos
python3 ../../scripts/mudclient.py 127.0.0.1 40098 --timeout 20 --idle 1.2 \
  --send "gb" --send "new" --send "yourid" \
  --send "adminpass1" --send "adminpass1" \
  --send "yourpass1" --send "yourpass1" \
  --send "你的中文名" --send "you@example.com" \
  --send "1" --send "m" --send "9" --send "y"
```

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 98 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## §7.100 跨库扫描修复（`ROOM` 基类同款 `replace_program()` 致命形状）

- 同一 `inherit ROOM; ... replace_program(ROOM);` 冗余自替换形状（AGENTS.md
  §7.100）覆盖了几乎全部房间对象：`work/` 下共 1,335 处存活匹配。用二进制
  模式脚本删除了 1,331 处标准形式的独立行；另有 4 处不规则形状手动修复：
  1 处房间文件 `d/dongying/dahai.lpc` 里该行末尾多了一个空格
  （`replace_program(ROOM) ;`）导致脚本按精确匹配未命中；另外 3 份房间生成
  工具（`obj/misc/roommaker.lpc`、`obj/obj/roommaker.lpc`、
  `obj/obj/misc/roommaker.lpc`，字符串拼接变体，`str += "...replace_program
  (ROOM);..."` 写死在生成模板里）——修复后新造的房间不会再继承这个地雷。
  修复后 `work/` 下 `grep -rn "replace_program(ROOM)"` 排除注释后为零匹配。
  验证：真实 debug 驱动干净编译启动、端口正常监听，`debug.log` 无新增
  "cannot replace"/错误行；启动一次注册流程走到取名环节确认无崩溃（该库
  提示流程与其他库不同，未走完整注册，但编译验证已足够）。

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

## 深度功能测试（第三轮，2026-08-23）——补测商店购买/拜师/帮会

本轮先核对了同批「三界神话」姊妹库（sjsh/sjshv150/sjshv2578bb/
sjshwzb/sjshwzjqb）本次测试中发现的两个已知坏味道是否在本 lib
重现：

1. `adm/daemons/combatd.lpc` 的 `killer_reward()`：本 lib 在
   `killer->add("PKS", 1);` 之后紧跟着就有
   `victim->add("DIE",1);`（第 1004-1005 行），而 `score` 里"被杀
   害"字段读的正是 `DIE`（`cmds/usr/score.lpc` 第 135-136 行）——
   姊妹库缺的那两行这里本来就有，**不受影响，未发现同款 bug**。
2. `d/lingtai/obj/shengmao.lpc` 的 `set_name()` 字符串完整闭合，
   **不受影响**。

随后补测了 NOTES.md 之前标记为"未覆盖范围"（商店购买、门派加入、
帮会系统）的三项：

### 1. 商店 `buy`——正常，未发现 bug

`d/city/dangpu.lpc`（董记当铺）是空的 `HOCKSHOP`（要有人先
`pawn`/`sell` 东西进去才有货），新号身上也没有初始钱财（游戏内
提示本身就写"新手：没有钱怎么办？不要问巫师，向老玩家讨"，是
设计如此，不是 bug）。改用 `回春药铺`（`/obj/boss/city_yang.lpc`，
`F_VENDOR_SALE` 型真实店铺，卖金创药/混元丹/眼泪/清心散血丸）做
测试：用 admin 帐号 `clone`+`give` 了六两白银（值 600）给测试号，
`list` 显示"金创药(yao)：六两白银"，`buy yao from yang` 后 `i`
显示白银消失、金创药精确到手一份——扣款金额与商品标价完全一致，
没有找零误差也没有多扣/少扣。购买流程（`cmds/std/buy.lpc` 的
`can_afford`/`pay_money`/`complete_trade`）工作正常。

### 2. 门派拜师——正常，未发现 bug

用 `南海普陀山`（`d/nanhai/npc/bonze.lpc`，无条件收徒的
`attempt_apprentice()`）测试：`apprentice heshang` 后立即收徒成
功，`score` 里"师承"从"还未曾拜师学艺"变为"南海普陀山和尚"，职
称也正确显示"南海普陀山第四代弟子"。`cmds/std/apprentice.lpc` 的
拜师逻辑工作正常。

### 3. 帮会系统——发现两个问题，一个已修复，一个记录为已知限制

本 lib 的"帮会"实际上是**两套互不相干、从未整合过的并行系统**：

**(a) 旧的玩家互邀系统 `cmds/std/bang.lpc`**（`marks/帮派` 字
段）——**发现并修复一个真实 typo bug**：两处 `ob->dellete_temp
("pending/bang")` 把 `delete_temp` 拼错成了 `dellete_temp`（第
48、63 行），这是一个未定义函数——只要 `bang with` 走到"双方都
已入帮"或"邀请/申请成功"的分支就会触发运行时错误。已修正为
`delete_temp`；`update /cmds/std/bang.lpc` 编译成功验证。**未能
端到端活体验证该分支**，因为这套系统本身还有一个更大的问题：只
有已经是"舵主"的人才能邀请别人入帮，而全库搜索"舵主"这个头衔，
除了 `bang.lpc` 自己拿来比较之外，**没有任何代码路径会把这个头
衔赋给任何角色**——也就是说全新开的档在这套系统里永远造不出第
一个帮会，这个 bug 本身修复了但该系统仍然实际不可达，判断为设
计/内容缺口而非可继续修的程序 bug。

**(b) 新的 `club`/`club_master` 系统**（`cmds/usr/joinclub.lpc`
+ `cmds/skill/club/capprove.lpc` + `cmds/adm/setclub.lpc`）——
**严重发现，未修复**：这三个文件全部依赖 `CLUB_D`
(`/adm/daemons/clubd`)，但**这个守护进程文件在整个归档里根本不
存在**（`work/` 和原始 `raw/` 都确认没有 `clubd.lpc`/`clubd.c`，
不是转换时丢的，原始压缩包里就没有）。用两个全新普通玩家号实测
`joinclub` 命令，触发了真实运行时错误，`debug.log` 记录：
```
执行时段错误：*call_other() couldn't find object '/adm/daemons/clubd'.
程式：/cmds/usr/joinclub.lpc 第 20 行
```
玩家端看到的是引擎的通用兜底提示"你发现事情不大对了，但是又说
不上来。"（没有崩溃、没有断线，但功能完全不可用）。`setclub`（管
理员建帮命令）走的是同一个缺失的 `CLUB_D`，所以连管理员也没有
办法手工建立第一个帮会来引导这套系统。**判断为超出"修 bug"范围
未处理**：修复需要从零实现整个 `clubd.lpc` 守护进程（`find_
player_club`/`add_club`/`set_member`/`set_club_leader` 等接
口），这是补全一整块缺失内容而不是修正一个具体错误，原始设计细
节（每帮的数据结构、持久化格式等）也无从考证，不属于本轮"只修
真实程序 bug"的范围。记录在此供后续会话参考——**这个 lib 的帮会
系统（无论新旧）对全新档案实际都是不可用的**，可以视为"三界神
话"家族里未来检查同款 `CLUB_D` 缺失的一个信号。

**清理**：测试用的两个全新角色（`sjbuya`/`沐买一`、`sjbuyc`/`沐
买二`）测试完毕后均已 `suicide -f` 永久删除，`sjbuyc` 的存档因
为断线在 30 秒倒计时完成前被中断，已手工删除
`work/data/{login,user}/s/sjbuyc.o` 两个残留档案。管理号
`fluffos` 的存档正常保留（是常驻管理账号，不是测试角色）。
