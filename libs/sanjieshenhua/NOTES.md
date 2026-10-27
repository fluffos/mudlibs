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

## AGENTS.md §7.19 sweep (2026-09-01): `enable_player()` reentrancy from `init()`

Same corpus-wide bug class as `mhxy`/`wuhanzhan` (AGENTS.md §7.19): this
lib's `feature/command.lpc` `enable_player()` wrapper (around the raw
`enable_commands()` efun) is reachable from an NPC's `init()` via a
redundant `create()`-then-`init()`-calls-`setup()` (or `reset_me()`
calling `setup()`) chain -- confirmed live via a static scan of every
`init()` body in this lib: 73 NPC/item files call `setup()` directly
or via `reset_me()` from `init()`, after `create()` already called
`setup()` once (which already made the object `living()`). Calling
`enable_commands()` a second time on an already-`living()` object makes
the driver re-invoke that object's own `init()` as a side effect, which
re-enters this same chain while the original call is still on the
stack -- genuine reentrancy, crashing with "Too deep recursion" (most
likely to surface on an NPC's first-ever preload/compile).

`feature/damage.lpc`'s `revive()` call to `enable_player()` is dead/commented code in this lib, but `d/qujing/qujingren/qujingren.lpc`'s own `wakeup()` (and its siblings under `d/qujing/`) still call `me->enable_player()` on a `disable_player()`'d object that is still `living()`, confirming the same legitimate-re-enable-while-living pattern. This confirms a bare `if (living(this_object())) return;`
guard would be the WRONG fix (it would silently break that legitimate
re-enable) -- used the same true reentrancy-flag fix as `mhxy` instead:
a `nosave private int in_enable_player_now;` set for the duration of the
wrapper's body, guarding only genuine same-call-stack reentrancy while
leaving every legitimate re-enable (revive/wakeup/disguise) unaffected.
`feature/command.lpc`'s `enable_player()` had a single fall-through exit
(no early `return`s), so one guard-at-top + one clear-at-bottom pair was
sufficient. Verified via a single-file `lpcc --batch` compile check
(PASS) -- not individually live-boot-tested.

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 3 here-document block(s) repaired (3 with the terminator glued to the last text line, 0 with it indented), so `End of file in text block` no longer hides the room or object behind them: `d/linghai/cave1.lpc`, `d/linghai/masterroom.lpc`, `d/moon/bedroom.lpc`. The terminator must start its line (the lexer's own test, KB 04 §6.10); a glued one lost its newline in the GBK -> UTF-8 conversion together with a half character, which stays out.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators (opener line, case)

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 1 more block(s) repaired: 1 with the terminator spelled in another case than the opener (`@MING_PART ... MING_part`: the lexer compares case-sensitively, so the block never ended): `d/obj/club/bihai_mark.lpc`.

## 深度功能测试（§10.7，2026-10-04）— paths named in another case

The archive comes from a case-insensitive host: files are stored as `BAGUA0.lpc`, `longjing.C`, `d/SHAOLIN/`, the code names them in lower
case (`__DIR__ "bagua0"`, `"tea/longjing"`, `"/d/shaolin/..."`), so the rooms, NPCs and items behind them could not be loaded (a `.C` file is
not an `.lpc` file; KB 03 §4.5). `scripts/lpc_case_paths.py --convert --apply sanjieshenhua`: 1 file(s) renamed to lower case (`.C` -> `.lpc`,
`.H` -> `.h`) and 0 path reference(s) in 0 file(s) rewritten to the new spelling; 0 skipped, 0 ambiguous. Load check of the 2 objects that were renamed, edited or name a renamed path (HEAD against the working tree, an object is the same under any spelling of its path): 0 PASS -> 2 PASS, 0 that loaded before fail now, 2 more load.

1 files moved (1 `.lpc`); mostly under `d/calvin/armor` (1). A rescan with `scripts/lpc_warnings.py sanjieshenhua` is still due: the renamed files are compiled for the first time.

## 深度功能测试（§10.7，2026-10-05）— 任务表里的 `.c` 路径与任务守护进程的防护

`scripts/lpc_dynamic_rows.py`：`d/obj/quest/dynamic_location`、`d/obj/quest/dynamic_quest` 里 306 行写的是原档案的 `.c` 路径。转档时文件已改名 `.lpc`，而显式后缀按原样解析，`load_object("/d/x.c")`、`new("/d/obj/quest/x.c")` 返回 0 且不报错（KB 03 §4.2，KB 06 §7.220），所以 `adm/daemons/questd.lpc` 读到的每一行都加载不出来：随机任务和任务物品从未生成，在 `create()` 里直接对结果调用 `tar->set()` 的版本还会崩溃，连带加载它的 cron 守护进程和 `give` 的任务钩子。这些行已改为 `.lpc`；另有 3 行指向的文件两种后缀都不存在（档案缺内容），保持原样。
`scripts/lpc_dynamic_quest_guard.py`：2 处 `spread_quest()` 调用（`init_dynamic_quest()` 的循环里）包进 `catch()`，缺失的任务物品或编译不过的房间只跳过那一个任务，守护进程照常加载、其余任务照常生成。
验证：`adm/daemons/questd.lpc`和 cron 守护进程在新进程里加载（HEAD 一次，工作树三次，选房是随机的）：HEAD 通过 2 个，工作树三次分别通过 2、2、2 个（共 2 个），无回退。

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `std/room/room.lpc`：`make_inventory()` 用 `catch()` 包住 `unew(file)`（缺档时它在 simul_efun 里对 0 调用 `query("unique")`），`else` 分支只在确有克隆时才取 `[<1]`；`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-06）— 与 zhonghua2 同源的三处编译警告

- `cmds/std/team/party.lpc`、`cmds/std/team/swear.lpc`：结义失败提示被多余的 `;` 截成两句，`fail` 只剩"……可惜现在有人不在，$N"，后半句"的提议只好作罢。"丢了；接回去。

验证：改动的文件和包含 `npc/indian` 的守护进程在 HEAD 与工作树分别加载（`scripts/lpc_listcheck.sh`，新进程），无回退。

## 深度功能测试（§10.7，2026-10-06）— 编译警告整理

`scripts/lpc_warnings.py sanjieshenhua --fix`：无用局部变量 2790 个、`varargs` 103 处、转义 93 处、裸 `return` 3 处、`nosave` 函数 10 个改 `protected`，共改动 1375 个 `.lpc` 和若干 `.h`。`scripts/lpc_fix_no_effect.py --apply`：两份 `xuanyuan-archery.lpc` 删去什么也不做的 `(: throw_weapon :);`，`dns_master.lpc` 把 `#if PREF_* & SVC_TCP` 移到 `if` 外面。
手工：`adm/daemons/natured.lpc` 删去空语句 `lt[LT_MON];`；`adm/daemons/securityd.lpc` `valid_grant()` 删去没用到的 `string ip = query_ip_number(ob);`；`adm/daemons/channeld.lpc` `do_channel()` 里只在 `#ifdef XYJ` 分支用的四个局部变量，声明挪进同样的条件里。
HEAD 与工作树分别加载（新进程）：1330 -> 1330 通过，无回退；改过的头文件的 498 个包含者 473 -> 473 通过。`scripts/lpc_audit_removed_locals.py HEAD` 的 20 条候选都是声明被重建或同名 efun。
未动：`d/gumu/npc/zhangmen.lpc` 的 `fully_recover()` 中间缺了一段（恢复失败分支之后到重新装备武器之前，连同一个右括号），整个文件编译不过；但古墓掌门实际用的是 `obj/zhangmen/gumu.lpc`（`d/gumu/qianting.lpc` 加载它），这份是没人引用的旧稿。`d/quest/mofeng/npc/stey/` 下的文件同样是不加载的草稿。

启动时警告 119 -> 0；新进程登录（编码选择、英文名提示，新人物用 `new`）正常。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 41 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 13 个，只在 #if 分支用的声明移进分支 0 个文件；改动 52 个文件，HEAD 与工作树各载入一次无回退（52 objects; HEAD PASS 51, tree PASS 51; regress 0; newly loading 0），这些文件的警告 74 -> 20。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。2 个文件 3 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。
- 2026-10-14（同一次重扫，手工部分）：
  - `d/calvin/armor/rjl.lpc` 和 `d/wizz/calvin/armor/rjl.lpc`（日精轮）原来编译不过，原因有两个：同时 `inherit SHIELD; inherit NECK;`，两条路径各带进一份 EQUIP，`nomask` 函数被重定义；`offensive_target()` 的函数头丢了，只剩函数体。现只保留 `NECK`（原来生效的就是后继承的 `setup()`），并按 `d/9ct/zb/yjl.lpc` 补回函数头。两件现在都能载入。
  - `adm/daemons/network/mail_serv.lpc` 把 `tmp[i] == EOT+"."` 改成 `=`（原来是比较，不是赋值）。这个文件本身因缺头文件编译不过。
  - `d/longzhu/npc/long.lpc` 和 `d/quest/longzhu/npc/long.lpc` 删去没有定义、也没人调用的 `int long();` 原型（与 `/feature/name.lpc` 的 `string long()` 冲突）。
  - 与 wuhanzhan 同源的修法：
    - `d/kaifeng/ground.h` 加守卫；
    - `jiasha.lpc` 两个 `init()` 都调用；
    - 两份 `colors.h` 加防重复包含；
    - `alias.lpc` 的 `last_time` 改名；
    - 两组 `yg/yaoguai.lpc` 的 `yaoguai_type` 重复声明去掉；
    - `lijing` 的 `die`/`unconcious` 和 `yutu` 的 `kill_ob` 改 `void`；
    - 删去 `reporting.lpc` 未用的 `str`。
  - 改动的 32 个对象 HEAD 与工作树各载入一次：27 -> 29 通过，无回退。
  - 未动：`bin/v22pre11/`（附带的 MudOS 源码树）、`d/gumu/npc/zhangmen.lpc`、`d/quest/mofeng/npc/stey/`。这些是编译不过的文件，警告是报错后的连带输出（见上）。

- 2026-10-14：1 个文件因 `Type of returned value doesn't match function return type ( int vs void )` 整份不编译：声明为 `void`（或没写类型）的函数却返回值，旧驱动照样把值交给调用者。调用者要用返回值的（add_action 处理函数、命令、辅助函数）改为它实际返回的类型：`break_string()`。新进程比对 HEAD 与工作树：1 个对象，新增载入 0，回退 0（`scripts/lpc_fix_void_return.py`，KB 04 §6.3）。

- 2026-10-14：1 个文件把 `array` 单独当类型用（`array names;`），本驱动当成普通名字，报 `Illegal lvalue` 整份不编译；改为 `mixed *`，每个声明都带星号（`scripts/lpc_fix_array_type.py`）；3 个文件用了颜色宏（`HIW`、`NOR`）却没有 `#include <ansi.h>`（首个错误 `syntax error, unexpected L_STRING`）；开头补上（KB 04 §6.1、§6.3）。新进程比对 HEAD 与工作树：4 个对象，新增载入 3，回退 0。

## 内力/精力当作伤害种类（2026-10-15，KB 06 §7.241 第二类）

本库 `feature/damage.lpc` 的 `receive_damage()` 不接受 `jingli`/`neili`/`force` 等种类，`me->receive_damage("jingli", 30)` 之类在练功、绝招、吸取时报 `F_DAMAGE: 伤害种类错误`。4 处改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py` 第二步）。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

4 个文件（技能、绝招、兵器、书籍、区域 NPC 等）来自侠客行体系（qi/jing/neili），而本库人物是 gin/kee/sen/force：`receive_damage("qi", ...)` 报 `伤害种类错误`，`query("neili")` 永远为 0。按 qi→kee、jing→sen（本库学习/读书指令消耗的就是它）、neili→force、max_neili→max_force、jiali→force_factor 改名（`scripts/lpc_port_es_props.py --any-file`）。

## 治疗/疗伤的属性名（2026-10-15，KB 06 §7.241）

`receive_heal()`/`receive_curing()` 也只接受本库的种类。本库人物只有 kee/sen（连 gin 也没有）：药物的 `receive_heal("gin", 60)`、NPC 的 `receive_curing("gin", ...)` 和来自侠客行体系的 qi/jing 调用都报 `伤害种类错误`。7 个文件按 gin→sen、qi→kee、jing→sen、neili→force 改名（`scripts/lpc_port_es_props.py --any-file`）。


## 转码吃掉的引号（2026-10-15，KB 03）

原档在右引号前有一个孤立的 GBK 前导字节，转 UTF-8 时连引号一起丢了（如 `return name + HIM "发作身亡了;`），字符串一直延续到后面，文件编译失败：`/d/linghai/shishi2`、`/d/obj/books-nonskill/hmeng014`。补回引号（`scripts/lpc_fix_eaten_quote.py`）。

## `find_player()` 只认在世界里的身体（2026-10-15，KB 07 §8.26）

simul_efun 的 `filter_player()` 加上 `environment(ob)`：注册中途断线留下的、不在任何房间的身体不再被当成玩家，两个以上时 `find_player()` 不会再报 `The player(<id>) has existed in the world.`（wllz3 实测过的问题）。本库若注册流程不会留下带玩家 uid 的身体，这一改动不改变行为。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`qiusheng-blade`→`qiushen-blade`（`/d/wizz/passion/siqi`）。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

20 个文件、21 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/d/obj/armor/密林青衣`、`/d/leox/weapon/pa`、`/obj/longsword`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 0 个，改后 0 个（0 个原来载入不了），没有退步；其余 21 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## 去掉的预定义宏 `SAVE_EXTENSION`（2026-10-18，KB 04 §6.11）

老版 MudOS 给每个 LPC 对象预先定义了 `SAVE_EXTENSION`（`".o"`）；FluffOS 的 ChangeLog（COMPAT_BUSTER 一条）把它删了，改用 `__SAVE_EXTENSION__`。本库没有自己 `#define` 这个宏，用到它的文件一律 `Undefined variable 'SAVE_EXTENSION'`，整个对象载入不了。改成 `__SAVE_EXTENSION__`（`scripts/lpc_fix_predefined_macro.py`）：`adm/daemons/network/netmail.lpc`。`netmail` 是网络邮件守护进程（本库缺 `mailer.h` 等头文件，改后仍载入不了）。改后用 `lpcc` 逐个载入这些对象：0 个通过，1 个还有别的错误（`adm/daemons/network/netmail`：/adm/daemons/network/netmail.lpc:17: error: Cannot #include mailer.h）。

## 补回丢掉的基类宏（2026-10-18，KB 04 §6.13）

`inherit F_XXX;` 里的宏本库任何头文件都没有定义，报 `syntax error, unexpected L_IDENTIFIER, expecting L_STRING or '('`，整个对象载入不了；宏指向的基类文件本库其实有，别的库都把这个宏定义成同一个路径。在全局头文件 `include/globals.h` 里补上：`OTHERS` → `/std/armor/others`（19 个文件）、`FLOWER` → `/std/armor/flower`（2 个文件）。（`scripts/lpc_restore_macros.py`）改后用 `lpcc` 逐个载入这些对象：21 个里 0 个通过，其余 21 个还有别的错误（`obj/self/agate.lpc`：Undefined variable 'PROP_OTHERS'；`obj/self/cagate.lpc`：Undefined variable 'PROP_OTHERS'；`obj/self/ccrystal.lpc`：Undefined variable 'PROP_OTHERS'……）。


## 蓬莱三星的 `ref()` 是保留字（2026-10-18，KB 04 §6.14）

福星、禄星、寿星（`d/penglai/npc/`）里有一个函数叫 `int ref ()`，`call_out("ref", 20)` 去调它；`ref` 在 FluffOS 里是关键字（引用），`unexpected L_REF`，三个 NPC 都载入不了。函数和 `call_out` 都改叫 `reff`（本系里 dtxyzjb、zitengzhan 早就这么改，`call_out` 却没跟着改）：`d/penglai/npc/luxing.lpc`、`d/penglai/npc/shouxing.lpc`。改后载入：2/2 通过。

## `d/moon/obj/poem` 两句诗丢了收尾的引号（2026-10-18，KB 03 §4.6）

`string *poem` 数组里 `"不放玉花飞堕地，留在广寒宫阙。,` 和 `"把酒送春春不语，黄昏却下潇潇雨。,` 的收尾引号没了（转码时跟半个汉字一起丢了），下一行的开引号把字符串合上，后面的诗句成了代码：`Illegal character 0xe6`，整个物件载入不了。补回 `",`。载入：通过。

## `d/shendian/obj/niepan` 的收尾引号变成了私用字符（2026-10-18，KB 03 §4.6）

`set("long", HIR"……五种符号<U+E4D4>NOR);` 里本该是 `"` 的位置是一个私用区字符（转码时半个汉字加引号被换成了它），`Illegal character 0xee`，整个物件载入不了。换回 `"`。载入：通过。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 11 个对象设了本库没有文件的武功（14 个名字，最多的是 `anhei-blade`、`fumobashi`、`mizongbu`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：11 个里 9 个通过，其余 2 个停在别的错误上（`d/city/npc/dipi`：*No program in object '/d/city/npc/dipi'!；`d/wuguan/npc/master`：*No program in object '/d/wuguan/npc/master'!）。（`scripts/lpc_guard_set_skill.py`）

## 通向不存在房间的出口，按对面房间的回头出口改正（2026-10-18，KB 06 §7.257）

房间出口 `"west": __DIR__"xxx"` 指向的文件本库没有，玩家走过去就被卡住（笔误、改过名的房间，或者没带进档案的编号房间）。对面的房间存在、并且它相反方向的出口正好指回这个房间，说明出口原本就是通向它：`/d/jjf/front_yard` 的 `down`：`/d/quest/m_weapon/lianfushi` → `/d/quest/weapon_bk/lianfushi`；`/d/jjf/front_yard` 的 `up`：`/d/quest/m_weapon/lianmaceshi` → `/d/quest/weapon_bk/lianmaceshi`；`/d/lingtai/forrest2` 的 `south`：`/d/quest/m_weapon/liangunshi` → `/d/quest/weapon_bk/liangunshi`；`/d/luoyang/wroad4` 的 `north`：`bingyindamen` → `bingyingdamen`；`/d/moon/neartop` 的 `north`：`/d/quest/m_weapon/lianbianshi` → `/d/quest/weapon_bk/lianbianshi`；`/d/nanhai/tingjing` 的 `east`：`/d/quest/m_weapon/lianzhangshi` → `/d/quest/weapon_bk/lianzhangshi`；`/d/qujing/kusong/kusongjian` 的 `west`：`/d/quest/m_weapon/lianqiangshi` → `/d/quest/weapon_bk/lianqiangshi`；`/d/qujing/wuzhuang/juyuan` 的 `up`：`/d/quest/m_weapon/lianchuishi` → `/d/quest/weapon_bk/lianchuishi`；`/d/shushan/shanjiao` 的 `east`：`/d/quest/m_weapon/lianjianshi` → `/d/quest/weapon_bk/lianjianshi`。改动后每个出口都能解析到本库的文件（`scripts/lpc_fix_dead_exits.py`；目标在运行时本来就能载入的库——虚拟房间——不动）。

## 补回本库没有的基类文件（2026-10-18，KB 04 §6.15）

下面这些基类本库没有，继承它们的对象（房间、NPC、物品）整批载入不了（`inherit XXX;` 的宏没定义，或者 `inherit "/std/…";` 的文件不在）。同系的库里有同名文件，两库有大量逐字节相同的文件（亲缘关系），所以从那边原样拷来，缺的宏补进全局头文件 `include/globals.h`：`/std/char/kzznpc`（宏 `KZZNPC`）←dtxyzjb，1 个对象继承它，抽样 1/1 载入；`/u/helpler/npc/clubdd_master`←sjshv150，1 个对象继承它，抽样 1/1 载入；`/std/room/magicroom`（宏 `MAGIC_ROOM`）←xyj20032，10 个对象继承它，抽样 8/8 载入。每个基类补回后单独载入、再抽样载入使用它的对象，基类载不进来或者一个用户也载不进来的就撤掉（本库撤掉了它们，不再补）。（`scripts/lpc_restore_bases.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 30 处、30 个文件：`lahua-shou`→`lanhua-shou`（10 处）、`dagonforce`→`dragonforce`（7 处）、`hellfire_whip`→`hellfire-whip`（2 处）、`yange_blade`→`yange-blade`（2 处）、`dragon-step`→`dragonstep`（2 处）、`kongming--steps`→`kongming-steps`（1 处）、`changqaun`→`changquan`（1 处）、`lingyi-sword`→`liangyi-sword`（1 处）等共 12 个名字。（`scripts/lpc_fix_skill_names.py`）

## 武功基类缺少 NewRandom()（2026-10-19，KB 06 §7.261）

基本武功（`boxing`、`houquan`、`westsword`、`taiji-quan` 等）用 `action[NewRandom(i, 20, level/5)]` 挑招式；`NewRandom()` 和它调用的 `sum()` 在别的库的武功基类里有，本库的 `/std/skill.lpc` 是更精简的版本，没有，于是这些武功全都报 `Undefined function NewRandom` 编译不过，有这门武功的人物只能空手。把这一对函数（115 个库共用的同一份文字）补进武功基类，受益武功 5 个：`/daemon/skill/boxing.lpc`、`/daemon/skill/westsword.lpc`、`/daemon/skill_bk/boxing.lpc`、`/daemon/skill_bk/westsword.lpc`。（`scripts/lpc_restore_skill_helpers.py`）

## 技能基类丢了“预备武功”那一段（2026-10-19，KB 06 §7.262）

`feature/skill.lpc` 有 `skill_map`/`map_skill()`，却没有预备武功（`prepare_skill`）这一块：变量 `skill_prepare`、`prepare_skill()`、`query_skill_prepared()`、`query_skill_prepare()`。来自 xkx 系列的 NPC 在 `create()` 里调用 `prepare_skill("cuff", ...)`，于是 `Undefined function prepare_skill` 整个 NPC 载入不了。从同系的 xkx100 把这一块原样补回（声明加在 `skill_map` 后面，函数加在文件末尾），受益 NPC 1 个：`d/wuguan/npc/master`。（`scripts/lpc_transplant_function.py`）

## 同一个函数原样贴了两遍（2026-10-19，KB 06 §7.264）

同一个文件里同一个函数被原样贴了两遍（除空白外逐字相同），驱动报 `Redeclaration of function`，整个物件载入不了。删掉第二份及以后的副本，共 1 处：`/d/pkdao/room1.lpc` 的 `greeting()`。（`scripts/lpc_fix_dup_functions.py`）

## 全局头文件丢了 11 个宏（2026-10-19，KB 04 §6.16）

`/include/globals.h` 里没有定义 `PROP_OTHERS`、`TYPE_OTHERS`、`TYPE_FLOWER`、`TYPE_ARMBANDS`、`TYPE_CAPE`、`TYPE_LEGGINGS`、`TYPE_PANTS`、`TYPE_SHOULDER` 等共 11 个，用到它们的物件（名单里 18 个）编译时报 `Undefined variable`/`Undefined function`，整个物件载入不了（编译器在第一个未定义的名字上停下，后面的错误和警告都看不到）。同系的库在各自的头文件里都有这几行：照其中和本库共有文件最多的那个库，原样补到 `/include/globals.h` 最后一个 `#define` 之后，宏体里出现的路径在本库里都存在。补完后名单里有 4 个载入，其余还差别的东西。（`scripts/lpc_restore_defines.py`）

## 出口指向不存在的房间（2026-10-19，KB 06 §7.257）

下列房间的出口写的文件不存在，而对面恰好只有一个房间的出口指回本房间，所以按对面的房间改正（笔误、大小写、路径少了一级）：

- `/d/qujing/wuji2/shandao3.lpc` 的 `west` 出口：`guankou` → `goukano`
- `/d/qujing/wuji2/shandao4.lpc` 的 `east` 出口：`guankou` → `goukano`

改后房间照常载入（与 HEAD 逐个对比，没有退步），出口现在指向存在的房间。

## 区域物件的零碎修正（2026-10-19，KB 06 §7.267–§7.271）

- `/d/dntg/yunlou/npc/yaoguai.lpc` 的 `#include "/u/bird/obj/items.lpc"` 改成 `/d/quest/small/bcake/items.lpc`（巫师目录 `/u/…` 不在档案里，头文件的唯一副本在区域里）

逐个物件与 HEAD 对比载入，没有退步。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 标准整理轮（2026-10-19，`scripts/toolkit_fix.sh`）

本库在新驱动下重扫，机械修复：42 个未使用的局部变量。修后与 HEAD 逐个物件对比载入，没有退步。

## 补回本库没有的基类文件，第二轮（2026-10-19，KB 04 §6.15、§6.18）

宏有定义、基类文件却不在档案里：继承它的对象载入时报 `Inherited file '…' does not exist!`，编译扫描看不到这一类（`scripts/lpc_missing_inherits.py` 能列出）。同系的库里有同一个文件，原样拷来（`scripts/lpc_restore_bases.py`）；基类和继承它的对象 include 而本库没有的头文件一起带来。每个基类补回后单独载入，再载入使用它的对象，载不进来、或一个用户也载不进来的撤掉了。

- `/feature/encoding`←dtxyzjb：2/2 个继承它的对象载入

逐个与 HEAD 对比载入，没有退步。

## 标准整理轮，第二轮（2026-10-19，`scripts/toolkit_fix.sh`）

本库在新驱动下重扫，机械修复：1 个函数补上 varargs（调用处少传参数），1 个未使用的局部变量。修后与 HEAD 逐个物件对比载入，没有退步。

## 补回丢失的标点（2026-10-19，KB 03 §4.6）

转换时丢掉的分号、逗号、引号或文件末尾的 `}`，共 1 个文件，修前 HEAD 载入失败。别的库里同路径的完好副本只比这里少几个标点，按它补回（括号里是那个库）：`/d/jz/npc/jiang.lpc`（dtxyzjb）。修后与 HEAD 逐个对比载入：这 1 个物件全部载入，没有退步（`scripts/lpc_restore_from_twin.py`、`lpc_fix_eaten_quote.py --comma`、`lpc_fix_eof_braces.py`）。

## `x == "a" || "b"`：后面的字符串常量永远为真（2026-10-19，KB 06 §7.281）

`if (arg == "yuyou" || "yu you")` 里的 `"yu you"` 是非空字符串，永远为真，整个条件对任何 `arg` 都成立；作者要的是每个字符串都和变量比较。具体是：离开时清除“砍柴”标记只在往北走时才生效，往南不清。在每个字符串前补上变量和运算符（`scripts/lpc_fix_literal_or.py`；`forrest2.lpc` 是 `dir == "north" && "south"`，手工改成 `(dir == "north" || dir == "south") && ...`）：`/d/wizz/stey/npc/robber.lpc`（1 处）、`/d/lingtai/forrest2.lpc`（1 处）。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。改动：`/cmds/std/bian.lpc`（3 处）、`/d/lanling/yuhuayuan.lpc`（1 处）、`/d/wizz/calvin/lanling/yuhuayuan.lpc`（1 处）。

## `member_array('/', str)` 改为 `strsrch(str, "/")`：字符字面量的 member_array 按字节搜索（2026-10-20，KB 06 §7.283）

`member_array('/', str)` 里的 `'/'` 是整数，驱动按 UTF-8 **字节**搜索，返回字节偏移（带第三个参数时起点也是字节）；最新的 FluffOS（923cdbc0）在字符串里有非 ASCII 文字时，对每个调用点警告一次（`Warning: member_array(int, string) searches BYTES`）。而 `str[0..idx-1]` 按字符切，中文字符串会在错误的位置截断。改为 `strsrch(str, "/")`（找不到同样返回 -1，按字符计数；`scripts/lpc_fix_member_array_char.py`，JSON 编码器等少数几处手改）。改动：`/adm/daemons/vrm_server.lpc`（1 处）、`/bin/v22pre11/src/compat/simuls/process_string.lpc`（2 处）。

## `call_out_info()` 的每一项只有 3 个元素（2026-10-20，KB 06 §7.287）

驱动返回的是 `({ 物件, 函数, 延迟 })`，不带 call_out 的参数，旧代码读第 4 项 `info[i][3]`（`callouts` 指令、`calloutd`、`cod` 工具）一读就报 `Array index out of bounds`，指令从第一行起什么也打印不出来。改为 `(sizeof(info[i]) > 3 ? info[i][3] : 0)`（`scripts/lpc_fix_callout_info.py`）。改动：`/cmds/arch/callouts.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 12 处）。改动：`/cmds/skill/club/clublevel.lpc`（1 处）、`/d/city/mjlady3.lpc`（3 处）、`/d/city/npc/mjlady3.lpc`（3 处）、`/d/shendian/babu/obj/longzhua.lpc`（4 处）、`/d/shengdian/npc/rulai.lpc`（1 处）。

## `callouts`：`sizeof(info[i]) == 4` 把每一行都挡掉了（2026-10-20，KB 06 §7.287）

驱动的 `call_out_info()` 每项只有 3 个元素，输出行前的守卫 `if (sizeof(info[i]) == 4)` 永远不成立，指令只打印表头。改为 `>= 3`。改动：`/cmds/arch/callouts.lpc`（1 处）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/obj/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## 目录读出后的后缀截取宽度（2026-10-20，KB 06 §7.296）

`.c` 改名成 `.lpc` 之后，`get_dir("*.lpc")` 读出的文件名还按两个字符截取（`$1[0..<3]`）：`baguadao.lpc` 变成 `baguadao.l`，用它拼出的路径加载不到对象（故事、战场、事件、帮助、自造物品数据、召唤列表等）。改成 `[0..<5]`（`scripts/lpc_fix_getdir_strip.py`）。改动：`/cmds/std/cast.lpc`（1 处）、`/cmds/std/performtest.lpc`（1 处）。

## `get_config(__MUD_PORT__)` 经旧版 `runtime_config.h` 得到字符串（2026-10-20，KB 06 §7.302）

本库的 `include/runtime_config.h` 是老 MudOS 的编号（整数设置从 15 起，本驱动从 256 起），`get_config(__MUD_PORT__)` 读到的是另一项设置（字符串），`(int)` 又只是编译期标注，于是 `socket_bind(fd, LOCAL_PORT())` 报 `Bad argument 2 to socket_bind()`，版本守护进程 `port = get_config(__MUD_PORT__) + VERSION_PORT` 是字符串相加。头文件自己的注释写明 `get_config(__MUD_PORT__) == __PORT__`，所以代码里的这个调用（连同外面的 `(int)` / `to_int()`）改成了驱动的预定义 `__PORT__`（`scripts/lpc_fix_mud_port.py`）。改动：`/include/getconfig.h`（1 处）。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库现有的 NPC 文件里没有字面写成空 `chat_msg` 的（扫描只认 `set("chat_msg", ({ }))`）；守卫挡的是运行时才为空的列表和以后新增的 NPC。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/std/char/jobnpc.lpc`、`/std/char/npc.lpc`（共 2 个文件）。

## 观礼台 `d/city/under.lpc`：`wait_and_start()` 里的 `fan` 没赋值，比武开不了（2026-10-21，KB 06 §7.346）

接受挑战（`defend`）两秒后 `wait_and_start()` 调用 `fan->command("chat ...比武开始")`，`object fan;` 声明了却没有 `fan = load_object(__DIR__ "npc/fan");`（dtxywzxzb 的同一份文件有），抛错之后两条 `kill` 和 `call_out("finish_match", 300)` 都不执行，比赛不开始。补上这一句（`npc/fan.lpc`、`ground.lpc` 本库都有）。

## 七龙珠 `combine`：六次 `present()` 都存进了 `b`（2026-10-21，KB 06 §7.348）

每颗龙珠的 `do_combine()` 先检查身上有另外六颗：`if (!(b = present("liang longzhu", me))) ... if (!(b = present("fen longzhu", me))) ...`，六句都写成 `b =`，后面 `destruct(b); destruct(c); ... destruct(g)` 的 `c` 到 `g` 一直是 0。这几个库的 `destruct()` sefun 对 0 不抛错（原始 efun 也不抛），结果是合成神龙时只消耗了最后一颗和合成者自己，另外五颗还留在身上，可以反复合成。改成 `b, c, d, e, f, g`（shenmo 的 `/d/longzhu/obj/*` 是对的）。sjsh 上实测：HEAD 合成之后背包里还剩青、黄、蓝、粉、亮五颗，改后只剩神龙。改动：`/d/longzhu/obj/1.lpc`、`/d/longzhu/obj/2.lpc`、`/d/longzhu/obj/3.lpc`、`/d/longzhu/obj/4.lpc`、`/d/longzhu/obj/5.lpc`、`/d/longzhu/obj/6.lpc`、`/d/longzhu/obj/7.lpc`、`/d/quest/longzhu/obj/1.lpc`、`/d/quest/longzhu/obj/2.lpc`、`/d/quest/longzhu/obj/3.lpc`、`/d/quest/longzhu/obj/4.lpc`、`/d/quest/longzhu/obj/5.lpc`、`/d/quest/longzhu/obj/6.lpc`、`/d/quest/longzhu/obj/7.lpc`。

## 拼错的 `call_out()` / `input_to()` 目标（KB 06 §7.349，2026-10-21）

计时器或输入提示给驱动的函数名和文件里定义的差一个字母；驱动对不存在的函数静默不理，所以对应的计时从来没有触发过。调用和配套的 `remove_call_out()` 改成已定义的拼法：`find_seal`：`disapprear` → `disappear`（法术产生的封印十分钟后从不消失）。改动：`/d/jjf/obj/find_seal.lpc`。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 80 条注册（35 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/d/calvin/lanling/npc/guard1.lpc`（`do_bian`）、`/d/calvin/lanling/npc/gurad1.lpc`（`do_bian`）、`/d/calvin/lanling/x.lpc`（`do_swim`）、`/d/changan/pinqiting.lpc`（`do_pass`、`do_resign`）、`/d/city/misc/chatroom2.lpc`（`do_jump`）、`/d/city/npc/duguoyin.lpc`（`do_vendor_list`）、`/d/eastway/npc/petboss.lpc`（`do_cost`、`do_list`、`do_upgrade`）、`/d/eastway/petboss.lpc`（`do_cost`、`do_list`、`do_upgrade`）、`/d/gumu/huo.lpc`（`do_chop`）、`/d/gumu/jin.lpc`（`do_chop`） 等共 35 个文件。最多的函数名：`do_swim` 30 处、`do_no` 10 处、`do_bian` 9 处、`do_chop` 9 处、`do_list` 3 处。没有动（读过）：`/d/city/npc/petboss.lpc` 的 `do_list`（对象本身编译不过，登记留着，等对象能加载再处理）、`/d/city/npc/petboss.lpc` 的 `do_cost`（对象本身编译不过，登记留着，等对象能加载再处理）、`/d/city/npc/petboss.lpc` 的 `do_upgrade`（对象本身编译不过，登记留着，等对象能加载再处理）、`/d/wizz/stey/npc/rulai1.lpc` 的 `do_cancel`（对象本身编译不过，登记留着，等对象能加载再处理）、`/d/wizz/stey/npc/rulaim.lpc` 的 `do_cancel`（对象本身编译不过，登记留着，等对象能加载再处理）。

## 基类的 `add_action` 登记：处理函数只在后代里定义，基类自己被加载时报错（2026-10-21，KB 06 §7.349）

房间、NPC、公告板这类基类，`init()` 里登记的 `add_action("函数", "动词")` 的函数只由继承它的后代定义；基类对象自己被直接加载（房间可以走进去、NPC 可以克隆）时，访客输入这个动词，驱动报 `*Function for verb 'x' not found.`（第一轮扫描把这些当成“有后代定义，是活的”放过了，`scripts/lpc_verify_handlers.py` 在基类对象上跑 `function_exists()` 才看出来）。登记前加 `if (function_exists("函数", this_object(), 1))`（第三个参数 1：默认 `function_exists()` 把 `protected` / `private` 函数当作没有定义），后代照常登记。共 3 处、3 个文件（`scripts/lpc_fix_dead_add_action.py --guard`）：`/d/calvin/npc/wu.lpc`（`do_bian`）、`/d/quest/stey/yz_guai/guai.lpc`（`do_persuade`）、`/d/wizz/calvin/npc/wu.lpc`（`do_bian`）。

## 缺失物品的 `new()` / `carry_object()` 调用链加了保护（2026-10-22，KB 06 §7.73 补充）

`new(路径)->move(...);` / `carry_object(宏("x"))->wear();` 这类语句，路径指向的文件在这个压缩包里没有：`new()` 返回 0，`->move()` 在 0 上报 `Bad argument 1 to EFUN call_other()`。在 `create()` 里这个对象永远加载不了，在 `reset()` 里第一个缺失物品之后的刷新每次 reset 都被跳过。1 个文件里 2 处（`carry_object`）改成 `{ object new_ob = new(路径); if (new_ob) new_ob->move(...); }`（`scripts/lpc_guard_carry_object.py --new`：路径按这个文件自己看到的宏解析，宏名冲突、虚拟对象路径一律跳过）。 对这 1 个改动文件做加载检查（HEAD 与工作区对比）：HEAD 能加载 0 个，现在 0 个（新增可加载 0 个，回归 0 个）。

## 调用了、但这个库自己的守护进程里没有的函数（2026-10-22，KB 06 §7.354）

`MACRO->函数()` 调用的函数在这个库的守护进程里不存在：`call_other()` 对不存在的函数不报错、只返回 0，所以这些功能（时间显示、昼夜事件、名字检查、价格文字……）一直没起作用。同一血统另一个库的同名守护进程里有这些函数，原文照抄到本库守护进程末尾（`scripts/lpc_port_function.py`；调用处传的参数个数、函数体用到的函数 / 全局变量 / 宏 / 字符串键都在本库里有，已核对；守护进程在 HEAD 和工作区都能加载，每个函数用固定参数各调用一次：HEAD 返回 0，现在返回正常的值）：`/adm/daemons/natured.lpc` ← aoxiangtianji：`outdoor_room_event()`（2 处调用）。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 还剩 6 个函数没有补（chat_msg_combat 3, inquiry 2, chat_msg 1）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/d/9ct/npc/wuyazi.lpc`:`kick_back`、`/d/death/npc/yanluowang.lpc`:`ask_cancel`、`/d/obj/npc/girl.lpc`:`my_randommove`、`/d/quest/mofeng/npc/stey/yg-hell.lpc`:`perform_action`、`/d/quest/mofeng/npc/stey/yg-hell.lpc`:`cast_spell`、`/d/xueshan/obj/hufabird.lpc`:`saysth`。 另有 11 处函数体被作者整段注释掉（指针没跟着删），是有意关掉的，没动。

## 运行期目录 `log/nosave` 不存在，写日志的 `write_file()` 直接报错（2026-10-22，KB 03 §4.3 补充）

这个库的 1 个文件里有 1 处 `write_file("/log/nosave/...")` / `log_file("nosave/...")`（`static` 改 `nosave` 时连字符串里的日志路径一起改了，原来是 `log/static/`）：`/log/nosave/LASTCRASH` 等。压缩包和站点包里没有这个目录，`write_file()` 在目录不存在时抛 `*Wrong permissions for opening file /log/nosave/... for append. "No such file or directory"`，调用它的函数（杀人记录、重启记录、`call` 日志……）当场中断。把 `log/nosave` 记进 `scripts/wasm_keep_dirs.txt`（站点和 pristine 树都按它建空目录）；没有把字符串改回 `static`。证明（`scripts/lpcc_eval.py`，`catch(write_file("/log/nosave/ZZTEST", ...))`，fqyy2 / hy5 / bmxkx2001 的新进程）：补目录前报上面的错误，补后写成功。

## `log/` 下的日志子目录没有人建：写日志的 `write_file()` / `log_file()` 报错（2026-10-22，KB 06 §7.358）

这个库的代码往 `log/` 的 1 个子目录写日志：`log/dlog`（`adm/daemons/ran_moneyd.lpc`）。压缩包、`git clone` 和站点包里都没有这些目录（本地启动没有写过它们，`gen_keep_dirs.py` 没记），`write_file()` 对不存在的目录抛 `*Wrong permissions for opening file /log/dlog/money for append. "No such file or directory"`，调用它的函数在写日志那一行中断，后面的奖励、标志、步骤都没有执行。本库的 `log_file()` 会自己建目录（实测，或读源码：nitan 系的 `assure_file()`），所以这里只记了直接用 `write_file()` / `save_object()` 写的目录。把 `log/dlog` 记进 `scripts/wasm_keep_dirs.txt`（`scripts/lpc_keep_log_dirs.py`；站点和 pristine 树按它建空目录）。证明（`scripts/lpcc_eval.py`，在 `/adm/daemons` 这类目录下的求值对象里写 `/log/zzdirprobe/...`，新进程）见 KB 06 §7.358 的实测表。

## `(: 函数名 :)` 指针指向本库没有的函数：只含这个指针的行加了注释（2026-10-22，KB 06 §7.355 补充）

`inquiry` / `item_desc` / `chat_msg*` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：用到时（`ask`、`look`、NPC 闲聊）驱动抛 `*Undefined lfun pointer called: 函数名`，这一拍心跳的后半段被跳过。这些函数没有可以补回的来源（别的库同一路径的文件里没有，或者它还要用本库没有的东西），所以 5 个文件里 15 行只含这个指针的行（`"回去"    : (: kick_back :),` `"cancel" :(: ask_cancel :),` `"set" : (: set_max :),`）加了注释，原文保留并写明原因，这一项当作没有这个话题 / 物品 / 闲聊条目（`scripts/lpc_fix_dangling_lfun.py`；`#include` 的文件在库里缺失的对象、指针不在整行上的写法没动）。 前提（`function_exists()`）和加载检查（HEAD 与工作区对比，本库改动的 `.lpc` 文件）的结果见 KB 06 §7.355：没有一个回归。

## 汉字按字节切片的老写法没有换成按字符：改法名 `"澄" + name[2..3]`、辈分判断 `name[0..1] == "澄"` 等 2 处（2026-10-22，KB 06 §7.360）

原档按字节算字符串区间（一个汉字 2 字节）：`name[2..3]` 是名字的第二个字，`name[0..1] == "澄"` 问名字是不是以「澄」开头。转成 UTF-8 之后，这个驱动的区间和 `strlen()` 都按字符算（`strlen("澄观")` 是 2，`"澄观"[0..1]` 是两个字），老算术原样留着、意思全变：拜入少林 / 武当 / 峨嵋等派的玩家被改成错误的法名（二字名 `张三` 变成一个字的 `澄`，更长的名字取到第三个字）。

本库 2 处（1 个文件）：拼名字的赋值 2 处。例：`name[0..1]` → `name[0..0]`（`/d/nanhai/npc/tidu.lpc:135`）。`scripts/lpc_fix_gbk_slice.py` 把下标按字符重算（社区的 UTF-8 版 `xkx100utf8` 里就是同样的写法，作对照）；没有改的：截断（`name = name[0..7]`，现在最多 8 个字，只是放宽）、ASCII 的区间（`fname[0..3] == "room"`、`ctime(time())[4..19]`）和上下文看不出是汉字的区间。证明（`scripts/lpcc_eval.py`，bixiecanyang；其余各库是同一份文本）：让澄字辈掌门 `attempt_apprentice()` 一个名叫「张三」的访客，HEAD 的法名是 `慧`，改后是 `慧三`；抽样 28 个库的 HEAD / 工作树加载对比 0 退步。工具不幂等（`[0..3]` 折半得 `[0..1]`，又是对齐区间），改过的文件记在 `scripts/gbk_slice_converted.txt`，不要重跑。

## 长度检查按字节写，旁边的提示按汉字写：4 处（2026-10-22，KB 06 §7.362）

老档的 `strlen()` 数字节（一个汉字 2 字节），转成 UTF-8 后它数字符：提示写「必须是 2 到 6 个中文字」的检查还是 `strlen(name) < 4 || strlen(name) > 12`，于是两三个字的房名、帮会名、群名、聊天室名、称号被提示自己说允许的那句话拒绝，上限却是提示的两倍；留言板的标题检查 `i < 4 || i > 24 || i % 2` 还会拒绝所有奇数个字的标题（`post 你好吗`）。本库 4 处（2 个文件）：`if( (strlen(name) < 2) || (strlen(name) > 12 ) ) {`（`/adm/npc/wuji.lpc:185`）。`scripts/lpc_fix_strlen_gate.py` 以提示为准：条件里每个 `strlen` 门槛都恰是提示所说数字的两倍才折半，存长度的变量（`i = strlen(arg);`）的门槛和 `|| i % 2` 奇偶项、其后循环的 `i % 2 == 0 &&` 一并处理；提示里有英文 / 字母 / 字节的不动。证明（`scripts/lpcc_eval.py`，bxsj 的留言板，求值对象继承 NPC 并重写 `edit()` 记录调用，`command("post 标题")`）：HEAD 拒绝「你好」和「你好吗」、放行 23 个字的标题；改后接受前两个、拒绝第三个；shenmo 的 `named.lpc invalid_new_name("张三")`：HEAD 回 `名字只能是2-4个中文字。`，改后回 0。抽样 24 + 15 个库的 HEAD / 工作树加载对比 0 退步。

## 按字节写的汉字循环、茶馆猜诗和同盟频道标题（2026-10-23，KB 06 §7.363）

老档按字节做「一个汉字」：`while (i--) if (i % 2 == 0 && !is_chinese(name[i..<0]))` 只检查偶数下标，奇数位上的拉丁字母（`张a`）会过；茶馆猜诗 `mixup()` 用 `strlen(str)/2` 再 `j=j+j`、`str[k..k+1]` 交换两字节；泥潭系 `channeld` 的 `switch (strlen(fname)) case 4/6/8/10` 和 `strlen(family)==4/6` 按字节长度给同盟 / 门派名加空格。本驱动的 `strlen()` 和区间都按字符算。`scripts/lpc_fix_byte_char.py`：去掉奇偶项、把区间改成 `name[i..i]`，按字符重写 `mixup()` 并把 `strlen(first)>=14` 折成 7，频道标题的 case / 门派长度改成字符数（对照 aoxiangtianji）。本库 汉字循环 / `is_chinese` 区间 10 个文件；茶馆猜诗 `mixup` 1 个文件。证明（`scripts/lpcc_eval.py`）：sjplii 的 `check_legal_name` 在 HEAD 接受「张a」、改后拒绝，两边都接受「张三」；xkx100 的 `clubpoem->mixup("离离原上草")` 得到「离离原草上」（真交换汉字）；nitan_san 两字同盟名得到 `【 兄  弟 】`。关键对象加载通过。

## 从末尾按字节取汉字、书剑开帮长度（2026-10-23，KB 06 §7.364）

§7.360 只折了数字下标的 `[a..b]`，从末尾取的 `[<2..<1]`（GBK 下一个汉字）和 `[<4..<1]`（两个字）还留着：开帮 `gcreate` 的帮助写「二至六个汉字 / 3到8个英文字母」，检查却是 `(strlen%2)==1 || <4 || >12`，末字对 `({ "帮","会",… })` 用 `gname2[<2..<1]` 永远对不上；少林 / 峨嵋法名 `"明" + name[<2..<1]`、死讯 `killer[<2..<1] != "。"`、兵器改名的 `can_name` 同样坏掉。`scripts/lpc_fix_tail_slice.py` 只改汉字语境（对照非 ASCII 字面量、`can_name` / `valid_group_name`、拼名字），ASCII 补零 / ctime / 复数词尾 / `.lpc` 不动；`[<2..<1]`→`[<1..<1]`，`[<4..<1]`→`[<2..<1]`，开帮门槛按帮助改写。本库 从末尾切片 1 个文件。证明（`scripts/lpcc_eval.py` bxsj）：HEAD 上 `斧头帮[<2..<1]` 对不上「帮」；改后 `[<1..<1]` 对上；长度放行 `斧头帮`/`fut`；`"明"+"张三"[<1..<1]` 得「明三」。

## 血条 / 表情标题按字节算显示宽度（2026-10-23，KB 06 §7.365）

老档把汉字当两字节：`bar_string[0..(val * N / max) * 2 - 1]` 把「格数」换成字节下标，半格血条在本驱动（按字符算区间）上会整条画满；巫师表情 `edemote` 的 `repeat_string("─", 13 - (strlen(emotion) / 2))` 也会少减汉字宽度。`scripts/lpc_fix_display_pad.py`：去掉 CJK 血条 / 空白条上的 `* 2`（`jings`/`qis` 赋值和 `blank_string3[0..(23-a)]` 的 23→11 一并改），表情标题去掉 `/ 2`；ASCII 空格的 `none_string` / `empty_string` 仍保留 `* 2`（一格两个空格）。本库 2 处（1 个文件）。证明（`lpcc_eval.py` hhsj）：`tribar_graph(6,9,12)` 在 HEAD 画出整条 12 个■，改后为 6 个■+3 个□；麻将 `strlen(tempB)/2` 是两字符牌码，未改。


## 兰陵出口仍指向 /u/calvin、大殿北去 /u/fly（2026-10-23，KB 06 §7.367）

可玩的兰陵已在 `/d/lanling/`（`lldj1`、`beijiao4` 等），出口字符串还写着作者目录 `/u/calvin/兰陵/地区/…`，走动即死出口；皇宫大殿北向 `/u/fly/doublesword/houdian` 同样不存在。`scripts/lpc_fix_calvin_lanling.py` 在目标 `.lpc` 存在时改写为 `/d/lanling/<stem>`，并删掉大殿那条北向。本库 63 处。证明：sjshv2578bb 的 `lldj1` 北向加载 `beijiao4`；xianlvqiyuan 大殿 HEAD 有北向、改后没有。未映射：`书局`、`钦陵宫`（库内无对应文件）。


## 家丁 CLOTH_OB()/WEAPON_OB() 调用式宏（2026-10-27，KB 04 §6.16 Also）

`d/wuguan/npc/jiading.lpc`（及 `jiading1`，xlqy 系在 `d/dntg/hgs/wuguan/npc/`）写 `carry_object(CLOTH_OB("cloth"))` / `WEAPON_OB("changjian")`：库中没有带参的 `CLOTH_OB`，`WEAPON_OB` 在 `globals.h` 只是裸路径 `"/d/obj/weapon/"`，展开成 `"/d/obj/weapon/"("changjian")` 语法错误，NPC 无程序。同目录其它 NPC 用 `__DIR__ "obj/cloth"`；剑在 `/d/obj/weapon/sword/changjian`。改成这两条（目标文件均在树内）。证明：HEAD `Undefined function CLOTH_OB`；改后 `new()` 成功且 inventory 为 2。


## 黑风山 pusa1 用未声明的 ob 且函数外残留 call_out（2026-10-27，KB 06 §7.348 Also）

`d/qujing/heifeng/npc/pusa1.lpc` 的 `announce_success(object who)` 写成 `if (!ob->query("obstacle/hf"))`（`Undefined variable 'ob'`），同目录 `pusa.lpc` 是 `who->query("obstacle/hf") == "done"`；`who->save(); }` 之后还残留 `call_out("die"...); return; }`，落在函数外（`unexpected L_STRING`），对象无程序。改成与 `pusa` 相同的门，并删掉残留语句。证明：HEAD 加载失败；改后加载成功。


## 雪山 obj/hufabird set_level 缺 }（2026-10-27，KB 04 §6.28 Also）

`d/xueshan/obj/hufabird.lpc` 的 `set_level` 在 `setup();` 后少了一个 `}`，后面的 `int heal_up()` / `leave` / `invocation` / `die` 都嵌进了 `set_level`（`unexpected '('`），对象无程序；同目录 `npc/hufabird.lpc` 正常关闭。顺带：`messege_vision`→`message_vision`，`return : die()`→`return ::die()`，以及无 `saysth` 的 `(: saysth :)` 按 7.355 注释掉。证明：HEAD 加载失败；改后加载成功。


## 星君/罗汉模板缺 ID 宏（2026-10-27，KB 06 §7.348 Also）

`d/dntg/sky/stars/star.lpc` 与 `d/nanhai/luohan/npc/luohan.lpc` 用 `title[ID]` / `first_name[ID]`，真正带号的副本是 `#define ID N` 再 `#include` 本文件；单独编译模板时 `Undefined variable 'ID'`。加 `#ifndef ID` / `#define ID 0` / `#endif`，带号 include 仍用各自的 N。证明：HEAD 模板加载失败；改后模板与 `stars/5`、`luohan5` 均加载成功。
