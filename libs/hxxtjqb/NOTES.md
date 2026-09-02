
## WASM 修复摘要（迁移自 meta.json 的 group_note）

西游记题材的 ES 血统 mudlib（MudOS v22pre11 MudLib Build 3310），游戏内标题为"西行战记"，连线时有一个实时的 GB/BIG5 双编码选单。修复的 bug：（1）经典的 §6.6 convertd.lpc 希腊字母表漏斜杠错字，45 处，导致每次连线的横幅 cat() 都会崩溃；（2）logind.lpc 里经典的 §8.1 check_legal_name() 字节数没减半的长度界限+i%2==0 门槛+尾部切片 bug（is_chinese() 本身已经是正确的码点判断）；（3）实时存在的 GB/BIG5 编码选单 bug（§8.7）——选 BIG5 会在之后每一行都刷出"Invalid GB code"，已把两个选单选项都对应到 GB 直通编码修复。管理员账号（fluffos/Mud@2026）通过真实注册流程 + adm/etc/wizlist 播种，游戏内"目前权限：(admin)"显示确认生效。完整的注册→look→score→quit 流程在排版格式化前后各验证过一次，用的是真实中文名字（秦风）。格式化工具发现 2 个档案（d/moon/obj/poem.lpc、u/bmw/task/taskd.lpc）带有转档之前就存在的损坏字符串字面量（一段没有结束的诗词字符串，和一段写死在源码里的分页器输出痕迹）——已还原格式化工具对这两处的重新加空格处理，而不是在已有损坏之上继续叠加，其余问题按 WASM 验证范围之外处理，未修。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BBS_BOARD`、`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 32 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（2026-08-17，round one）——干净通过，零 bug，但揭穿了一个 tmux/telnet 测试工具的严重可靠性问题

第一次对这份档案做完整的 §10.7 深度游玩测试（注册→探索→战斗→死亡/
复活→留言板发帖），全程零真实 bug：

- **注册/look/score/hp/inventory/探索**：全部干净通过。
- **战斗**：巫师账号（`fluffos`/`Mud@2026`，真实注册，wizlist 播种的
  管理员身份现场确认生效）用 `goto` 直达 `/d/xueshan/xihai`（一个有
  `attitude: aggressive` 怪物"朱睛冰蟾"的房间），进房间后怪物主动攻
  击，几回合内被杀死——纯属测试过程中的意外，不是刻意安排的，但正好
  覆盖了死亡/复活这一步。
- **死亡处理**：死亡讯息、"某人被杀死了"的谣言广播、移动到
  `/d/death/gate`（阴阳界），全部正确无误。
- **复活**：`/d/death/npc/pang.lpc`（崔判官）的复活流程是**全自动**
  的——`init()` 里对刚进房的鬼魂启动一条 `call_out("death_stage", 5,
  ...)` 链，5 个阶段各间隔 5 秒播放一句判官台词，最后一步调用
  `ob->reincarnate()` 并移动到 `REVIVE_ROOM`，全程不需要玩家任何输
  入。现场验证：断线约 30 秒后重新连线，角色已经在复活点
  `/d/ourhome/kedian`，血量正确地是满血的四分之一（符合
  `pang.lpc` 里 `kee = max_kee/4` 的设定），无任何报错。
- **留言板发帖**：`post <标题>`（标题必须跟在同一行，不是交互式追
  问）触发内建编辑器（`结束离开用 '.'，取消输入用 '~q'`），逐行输入
  正文，单独一行 `.` 结束保存——`read <编号>` 验证发的贴子标题、正
  文、作者字段全部正确落盘。

### 重要的工具方法教训：tmux + telnet 对这份档案（也可能更广泛）不
可靠到会制造假 bug

`score`/`hp`/`inventory`，以及任何不存在的指令，透过
`scripts/tmux_mud.sh`（`telnet -E` 起的会话）测试时**全部只显示空白**
——没有任何报错、没有"什么？"，看起来像是一个极其严重的"指令派发
静默失效"的 bug。深挖了 `query_entire_dbase()`、`error_handler()`、
`default error message` 配置、`report_error()` 频道广播等好几层，
一度高度怀疑是驱动侧的静默吞错误配置缺陷。**最终用一个独立的原始
Python socket 连线重现同一操作序列，`score`/`hp`/`inventory` 全部
返回完整、正常的内容**——证明这完全是本地 telnet 客户端的问题，不
是这份档案的 bug，和 nt6 round four 发现的 `^]` escape 模式问题是
同一类，但这次是**静默丢弃后续输出、不显示任何提示**，比那次更隐
蔽，`telnet -E` 也没能解决它。

本轮之后改用单次 Python `socket.create_connection()` 脚本驱动整段
测试（一个脚本内完成"连线→登录→若干条指令→断线"这一整个逻辑阶
段，而不是每条指令都开一条新连线）——既保留了跨指令的会话延续性
（不违反"别用一次性 Python 脚本"的既有教训的精神），又完全避开了
telnet 客户端这层不可靠的中间人。**建议以后凡是在这个项目里做
`§10.7` 深度游玩测试，默认就用这个原始 socket 脚本方式，而不是
`scripts/tmux_mud.sh`**——tmux+telnet 现在已经在两个互不相关的档案
上各自制造过一次足以误导排查方向的假象。

## §7.100 sweep (2026-08-19)

Fixed the corpus-wide `inherit ROOM; ... replace_program(ROOM);` redundant-replace bug (AGENTS.md §7.100). 295 live occurrences deleted: 291 via scripted sweep (`fix_710_room.py`), plus 4 hand-fixed roommaker-tool occurrences across 2 tool copies (`clone/misc/roommaker.lpc` — simple variant; `obj/roommaker.lpc` — "room_code"/`str` 3-occurrence variant). 3 already-commented-out instances left untouched. No real `.lpc` source found under `work/data/`. Verified via `build-debug` driver boot: clean compile, port 40177 listening, zero new "cannot replace"/"cannot bind" debug.log lines. Pre-existing untracked test-account debris (`data/{login,user}/{f/fluffos,q/qintest}.o`) confirmed left untouched by `git status` review before staging.

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

## AGENTS.md §7.19: enable_player() reentrancy guard (2026-09-01)

Same corpus-wide bug class as `mhxy`/`wuhanzhan`: `feature/command.lpc`'s
`enable_player()` wraps `enable_commands()` and is unconditionally
reachable from an NPC's `init()` via `setup()`/`reset_me()` (confirmed
on this lib's own `d/*/npc/zhangmen*.lpc`-family NPCs, matching
`mhxy`'s originally-documented `d/xueshan/npc/zhangmen.lpc` pattern).
Calling `enable_commands()` on an object that's already `living()`
makes the driver re-invoke that object's `init()` as a side effect;
since `init()` calls back into `enable_player()`, that is genuine
same-call-stack reentrancy that repeats until "Too deep recursion"
aborts a room's first-ever visit.

Fixed with a true reentrancy flag (`nosave private int
in_enable_player_now;`), NOT a bare `if (living(this_object()))
return;` guard — this lib's `feature/damage.lpc` `revive()` and
`cmds/std/sleep.lpc` `wakeup()`/`wakeup2()` all legitimately
re-invoke `enable_player()` while the object is still `living()`
(that's how a fainted/asleep character gets commands back), so a
living()-gated guard would silently break every one of those real
re-enables. `enable_player()`'s single body has no early `return`
statements, so the flag is set at entry and cleared once, before the
function's fall-through end. Verified with a single-file `lpcc`
compile check (exit 0, no errors) against `feature/command.lpc`.

## 深度功能测试 round three batch 4 新角度测试 (2026-09-01)

Round one（2026-08-17）已经完整跑过注册→探索→战斗→死亡/复活→留言板
发帖这条主线，且干净通过。本轮刻意换一个完全不同的测试角度，按照
项目当前的对抗式/边缘输入 + 断线时序 + 经济系统 + 邮件系统的清单来
测试，使用原始 Python `socket.create_connection()` 脚本驱动（继承
round one 自己踩过的教训：`scripts/tmux_mud.sh` 的 `telnet -E` 在这
份档案上会静默吞掉部分指令输出，不可靠）。驱动跑在 `config.fluffos`
（端口 40177），全程逐动作 grep `log/debug.log`。

**测试角度**：注册流程对抗式输入（超长英文 ID、非 UTF-8 垃圾字节、
空输入、连续非法 ID 触发洪水防护 `id_count>6` 踢线）、中文名字边界
（空、纯 ASCII、单字合法名）、`std/money.lpc` 的 `query_autoload()`/
`autoload()` 契约是否像 `fysjmb` 一样被注释掉（AGENTS.md §7.99 严重
货币销毁类 bug）、邮件系统（`obj/mailbox.lpc` 的 `mail`/`from`/
`readmail`/`discard`）、金钱经济在 quit/重连后的持久性、巫师 `call`
指令对在线玩家对象的跨对象调用。

### 发现 1（已修复）：`adm/daemons/logind.lpc` 的 `get_name()` 里一
条遗留的 `printf("%O\n", ob)` 调试输出，直接把登入物件的内部路径
（如 `/obj/login#25`）打印到刚设定好中文名字的新玩家屏幕上——AGENTS.md
既有的 §7.34 bug class 的一个新实例

用真实中文名字（"秦风测二"）走完整注册流程，在设定名字、系统提示
"请设定您的密码："之前，屏幕上先额外多打印了一行 `/obj/login#25`
（活体验证，round three batch 4 之前从未在这份档案上确认过，
AGENTS.md §7.34 现有清单里也没有 `hxxtjqb`）。定位到
`adm/daemons/logind.lpc:1191`（修复前）：

```lpc
  printf("%O\n", ob);

  ob->set("name", arg);
```

`printf("%O` 是没有任何说明注释的开发期调试语句，混在一串正常的玩家
提示 `write()` 之间，直接把驱动内部的对象路径吐到连线画面上。按
§7.34 已确认的标准修法，整行删除。修复前后各跑一次完整注册（`gb`→
`no`→`new`→英文 ID→中文名字），修复后画面干净地直接跳到"请设定您的
密码："，`log/debug.log` 全程无新增报错。

### 发现 2（已修复，AGENTS.md §4.3 既有 bug class 的新实例）：
`adm/simul_efun/file.lpc` 的 `log_file()` 引用一个从未真正创建的
`/log/nosave/` 目录，导致巫师 `call <玩家>-><函数>(...)` 指令对任何
在线玩家对象的跨对象调用都会执行时段报错并整个中止——`call_other()`
本身根本没机会执行

用管理员账号（`fluffos`/`Mud@2026`，真实注册+wizlist 播种）对着一个
同房间的在线测试角色（`advteste`）执行
`call advteste->add_money("coin",500)`，屏幕上直接报出：

```
执行时段错误：*Wrong permissions for opening file /log/nosave/CALL_PLAYER for append.
"No such file or directory"
...
呼叫来自：/adm/obj/simul_efun.lpc 的 log_file() 第 8 行
调用参数：log_file("nosave/CALL_PLAYER", "秦道人(fluffos) call 秦风测二(advteste)->add_money(...)...")
呼叫来自：/cmds/wiz/call.lpc 的 main() 第 42 行
```

这正是 AGENTS.md §4.3 已经记录过的经典形状：`convert_lib.sh` 的
`\bstatic\b`→`nosave` 全局替换是按单词边界做的正则，连字符串字面量
里的 `"static/..."` 路径前缀也被一起改成了 `"nosave/..."`，但仓库里
真正被播种的目录是 `log/static/`（`ls log/static/` 能看到
`CALL_PLAYER`、`CRASHES`、`force_player`、`promote`、`promotion`、
`PURGE`、`SUICIDE` 这些真实的历史日志种子文件），`log/nosave/` 从未
存在过。对照 `raw/hxxt/cmds/wiz/call.c` 确认原始未转档源码里这一行
本来就是 `log_file("static/CALL_PLAYER", ...)`——证实是转档期间的
误伤，不是原始设计。

全档案 grep `"nosave/` 命中 **13 个文件 / 17 处**，逐一对照
`raw/hxxt/` 里的原始 `.c` 源码确认都应该是 `"static/...`（`vi.c` 的
`#define LOGFILE "static/VI"` 也同样确认）：`adm/daemons/logind.lpc`
（本条已单独按发现 1 处理）、`adm/daemons/securityd.lpc`、
`adm/obj/master.lpc`（4 处 `CRASHES`）、`cmds/adm/promote.lpc`、
`cmds/adm/xpass.lpc`、`cmds/arch/purge.lpc`（2 处）、
`cmds/arch/purge2.lpc`（2 处）、`cmds/arch/purgehouse.lpc`、
`cmds/eld/full.lpc`（已注释掉的调用，一并改正）、
`cmds/std/suicide.lpc`、`cmds/usr/suicide.lpc`、`cmds/wiz/call.lpc`、
`cmds/wiz/force.lpc`、`feature/vi.lpc`。全部机械改回
`"static/...`。

另外按 AGENTS.md §4.3 已确立的加固手法，给共享的 `log_file()`
simul_efun 本身也加了一道 `assure_file()` 前置调用（`file.lpc` 里
`assure_file()` 定义在 `log_file()` 之后，补了一行前向声明）：

```lpc
void assure_file(string file);

void log_file(string file, string text) {
  assure_file(LOG_DIR + file);
  write_file(LOG_DIR + file, text);
}
```

这样以后任何一个引用了从未创建过的目录的 `log_file()` 调用点都会
自愈而不是崩溃。**活体验证**：修复前对在线测试角色执行
`call advteste->add_money(...)` 直接执行时段报错、`call_other()`
从未真正执行；重启驱动加载修复后的代码，同样的指令干净地打印出
`/obj/user#28 ("秦风测二")->add_money("coin", 500) = 0`，
`log/debug.log` 全程无新增报错。

### 排查过程中澄清的两个误报（记录以免以后重复踩坑）

- **`add_money()`/`carry_object()` 对玩家对象"不起作用"，不是
  bug**：`call <玩家>-><...>` 修好之后，多次 `call
  advteste->add_money("coin",500)` 都返回 `= 0` 且玩家 `i` 里始终没
  有钱——一度怀疑 `carry_object()` 内部的 `query_unique()` 判断或
  euid 权限挡住了新建的钱物件。用同样的 `call
  bigeye->add_money("coin",999)` 对着一只克隆出来的 NPC
  （`d/ourhome/npc/bigeye.lpc`）测试，钱确实正常出现在 NPC 身上
  （"九百九十九文钱(Coin)"）——证实 `add_money()`/`carry_object()`
  这两个函数本身完全正常。根源查到玩家物件 `obj/user.lpc` 只
  `inherit CHARACTER;`（`/std/char.lpc`），并不 `inherit`
  `std/char/npc.lpc`（`add_money`/`carry_object` 定义所在），
  `std/char.lpc` 本身没有这两个函数——所以 `call advteste->add_money`
  从一开始调用的就是一个玩家物件上根本不存在的函数，`call_other`
  对未定义函数静默返回 `0`，不是任何形式的崩溃或数据损坏，是我自己
  测试方法一开始的错误假设。玩家类角色真正获得金钱只能走
  `pay_player()`（卖东西给当铺）等游戏内正规渠道——改用"管理员
  `clone`+`call set_amount`+`drop`，玩家 `get`"这条完全走正常
  `move()`/组合逻辑的路径重新验证了一次货币的 quit/重连持久性
  （见下）。
- **`obj/mailbox.lpc`（信箱）每次 `quit` 后都会消失，下次上线要重新
  向邮差要一次——确认是原始 1996 年源码就有的设计，不是转档引入的
  bug，未修**：观察到测试角色在拿到信箱、寄信之后，`quit` 一次再
  重连，`i` 里的信箱物件完全消失了（信件内容本身没丢——`mails`
  数组是通过 `set_owner()`→`restore()` 走独立的 `data/mail/<首字母>/
  <账号>` 存档路径持久化的，与 `quit.lpc` 的 autoload 分类逻辑无
  关）。根源是 `obj/mailbox.lpc` 从未定义 `query_autoload()`，且
  `set("no_drop", 1)`；`cmds/usr/quit.lpc` 对不支持 autoload 的物品
  会先尝试 `DROP_CMD->do_drop()`，`no_drop` 物品掉落必然失败，于是
  转入"化成粉末消失"分支——信箱因此在每次 `quit` 时都必然被销毁，且
  没有任何登入时自动重新发放的机制，只能靠玩家记得再向邮差要一次。
  对照 `raw/hxxt/obj/mailbox.c` 和 `raw/hxxt/cmds/usr/quit.c`，两份
  原始未转档源码里这个形状就已经存在（`mailbox.c` 从来没有
  `query_autoload()`），确认是原游戏 1996 年设计本身如此，不是
  §7.199 那种转档引入的契约缺失，按项目规则（只修程序 bug，不动
  内容/设计取舍）不予修改，仅记录在案。

### 未发现问题的角度（活体验证过，诚实记录）

- 注册流程对抗式输入：超长（300 字符）英文 ID、非 UTF-8 垃圾字节、
  空字符串、纯 ASCII 中文名、单字中文名（"秦"，符合
  `check_legal_name()` 1-6 字的既定边界）——全部按预期提示错误消息
  重新提示，无崩溃、无 `debug.log` 报错。
- 连续 7 次非法英文 ID 会在第 7 次触发 `id_count>6` 洪水防护，
  `destruct(ob)` 干净断线，无崩溃。
- `std/money.lpc` 的 `query_autoload()`/`autoload()` 契约完整
  （两者都是活代码，没有被注释掉），不是 §7.99/fysjmb 那种货币销毁
  类 bug。用"管理员 `clone`+`call set_amount(500)`+`drop`，玩家
  `get`"重新验证了一次真实携带的 500 文钱在 `quit`→重连之后完整
  保留（`quit` 消息里正确地没有提到丢弃钱，只提到丢弃不支持
  autoload 的粗布衣），round-trip 确认正常。
- 邮件系统 `mail`/`from`/`readmail`/`discard` 基本可用（用 `read`
  代替 `readmail` 会像信箱自己 `long` 描述里提示的那样被同房间留言
  板的 `read` 指令抢先接管，这是信箱自己文档里就说明了的已知行为，
  不是 bug）。`discard 0`（怀疑的越界低位下标）因为信箱在两次尝试
  之间都被上面发现 2 附带澄清的"quit 必销毁"行为清空/移除，未能在
  真正持有多封信件的状态下完整复现到底，留作诚实的未尽事项而非
  臆造结论。

本轮共发现并修复 2 个真实程序 bug（§7.34 调试信息泄露的新实例、
§4.3 `log_file()` 缺失目录导致 `call` 指令崩溃的新实例），均已现场
用修复前/修复后的 `debug.log` 对比 + 实际游戏内指令输出验证。两个
bug class 都已经在 AGENTS.md 里有完整记录，本次不需要再新开
bug-class 条目，仅需要在这两节里补充 `hxxtjqb` 这个新实例（如果后续
批次也在别的库发现，再由那个批次自己写补充说明）。
