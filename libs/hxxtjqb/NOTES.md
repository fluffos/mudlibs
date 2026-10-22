
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

## 深度功能测试（2026-09-04，round three，shop + 拜师）

新角度：南城客栈购物 + 方寸山云清拜师。2026-09-01 测过货币 quit 持久
和邮件，没有走 `list`/`buy`，也没有拜师。这是 ES/幻想西天血统（游戏
内标题「幻想西天」），不是夕阳再现。端口 40177。第一输入是 GB/BIG5
选单，发 `gb`，然后「是否中小学学生」发 `no`，再英文 id。

### 实测过程

管理员 `fluffos` / `Mud@2026`（权限 `(admin)`）。既有存档带着
`kee:-1` / `disable_type:"<昏迷不醒>"`（2026-08-17 被朱睛冰蟾打死留下
的），登录后会立刻「眼前一黑」；等「又有了知觉」再 `full` 才恢复。
`clone /obj/money/gold` 可用。

`goto /d/city/kezhan`（南城客栈，店小二 `d/city/npc/xiaoer.lpc`，
`F_VENDOR_SALE`）。`list` 炸鸡腿八十文钱 / 桂花酒袋一两银子 / 花生豆
二十文钱等。本库 `buy` 格式是 `buy <物> from <人>`，不是光 `buy jitui`。
`buy jitui from xiaoer` 成功（「你向店小二买下一根炸鸡腿」）。当场
`i` 是九十九两银子 + 二十文钱 + 炸鸡腿。

`goto /d/lingtai/inside6`，云清（`d/lingtai/npc/yunqing.lpc`）无门槛
收徒。`apprentice yun` 一次成功：恭喜成为方寸山三星洞第四代弟子。
`score` 职称「方寸山三星洞第四代弟子」、师承云清。菩提祖师只收本门
高道行弟子，不要拿他当新手拜师点。`cmds/usr/save.lpc` 真正写盘，10
秒内再 save 是「你迟点才可以储存」。save 后杀驱动冷启动再登录，门派/
师傅/银子铜板都在。炸鸡腿未进 autoload。

本轮没有新的 programming bug。巫师登录时大量「编译时段错误」其实是
`#pragma` 警告被 `log_error()` 打到巫师屏幕上，不是执行时段崩溃。

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.


## 深度功能测试（§10.7，2026-10-04）— undefined macro and simul_efun gaps

- 6 file(s) `inherit F_SSERVER;` and no header defines it (4 did not compile: `syntax error, unexpected L_IDENTIFIER, expecting L_STRING or '('`). `#define F_SSERVER SSERVER` in `include/globals.h` (KB 04 §6.2, `scripts/lpc_alias_macro.py`). 3 still fail.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 1 here-document block(s) repaired (1 with the terminator glued to the last text line, 0 with it indented), so `End of file in text block` no longer hides the room or object behind them: `d/moon/bedroom.lpc`. The terminator must start its line (the lexer's own test, KB 04 §6.10); a glued one lost its newline in the GBK -> UTF-8 conversion together with a half character, which stays out.

## 深度功能测试（§10.7，2026-10-04）— paths named in another case

The archive comes from a case-insensitive host: files are stored as `BAGUA0.lpc`, `longjing.C`, `d/SHAOLIN/`, the code names them in lower
case (`__DIR__ "bagua0"`, `"tea/longjing"`, `"/d/shaolin/..."`), so the rooms, NPCs and items behind them could not be loaded (a `.C` file is
not an `.lpc` file; KB 03 §4.5). `scripts/lpc_case_paths.py --convert --apply hxxtjqb`: 2 file(s) renamed to lower case (`.C` -> `.lpc`,
`.H` -> `.h`) and 0 path reference(s) in 0 file(s) rewritten to the new spelling; 0 skipped, 0 ambiguous. Load check of the 7 objects that were renamed, edited or name a renamed path (HEAD against the working tree, an object is the same under any spelling of its path): 5 PASS -> 7 PASS, 0 that loaded before fail now, 2 more load.

2 files moved (2 `.C`); mostly under `d/qujing/kusong` (1), `d/shushan/xianjing.C` (1). A rescan with `scripts/lpc_warnings.py hxxtjqb` is still due: the renamed files are compiled for the first time.

## 深度功能测试（§10.7，2026-10-05）— room base survives a raising NPC

`scripts/lpc_resilient_room.py --apply`: `make_inventory()` of `std/room.lpc` loads each inventory object as `if (catch(ob = new(file)) || !objectp(ob)) return 0;`. `new()` of a file that is not there returns 0 (the room just lacks that NPC), but `new()` of a file whose `create()` raises (a skill file for `set_skill()` this archive never had, a `carry_object()` item that is not there, a header that never shipped) raised inside the room and the room did not load at all. The wrong-case renames of this lib (the section above) make the NPCs behind them reachable for the first time, so a room that holds one with such a content gap would have gone from "NPC missing" to "room missing"; now it loads without that NPC, as it did before. The room base compiles and loads with the change (HEAD against the working tree). KB 03 §4.5.

## 深度功能测试（§10.7，2026-10-05）— tail() simul_efun

`scripts/lpc_add_tail.py --apply`: `cmds/wiz/tail.lpc` calls `tail(file)`, an efun of the MudOS this archive ran on that FluffOS does not have (`Undefined function tail`: the command did not compile). `adm/simul_efun/file.lpc` now defines `void tail(string file)`: the last 10 lines of the file, written to the player. Load check (HEAD against the working tree): 1 of the 1 tail command file(s) failed to load at HEAD, all load now, and the simul_efun file loads. KB 04 §6.2.

## 深度功能测试（§10.7，2026-10-05）— 任务表里的 `.c` 路径与任务守护进程的防护

`scripts/lpc_dynamic_rows.py`：`d/obj/quest/dynamic_location`、`d/obj/quest/dynamic_quest` 里 254 行写的是原档案的 `.c` 路径。转档时文件已改名 `.lpc`，而显式后缀按原样解析，`load_object("/d/x.c")`、`new("/d/obj/quest/x.c")` 返回 0 且不报错（KB 03 §4.2，KB 06 §7.220），所以 `adm/daemons/questd.lpc` 读到的每一行都加载不出来：随机任务和任务物品从未生成，在 `create()` 里直接对结果调用 `tar->set()` 的版本还会崩溃，连带加载它的 cron 守护进程和 `give` 的任务钩子。这些行已改为 `.lpc`；另有 3 行指向的文件两种后缀都不存在（档案缺内容），保持原样。
`scripts/lpc_dynamic_quest_guard.py`：1 处 `spread_quest()` 调用（`init_dynamic_quest()` 的循环里）包进 `catch()`，缺失的任务物品或编译不过的房间只跳过那一个任务，守护进程照常加载、其余任务照常生成。
验证：`adm/daemons/questd.lpc`和 cron 守护进程在新进程里加载（HEAD 一次，工作树三次，选房是随机的）：HEAD 通过 2 个，工作树三次分别通过 2、2、2 个（共 2 个），无回退。

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `std/room.lpc`：`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 OK，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-06）— 编译警告清理；表情存档读不回

1. `scripts/lpc_warnings.py --fix` 机械修复 710 个文件，启动警告 519 → 0。HEAD 与修改后各编译一遍改动的文件：686 = 686，无回归。被删局部变量的审计 19 处只出现在注释或同名函数调用里（`piggy` 的 `#ifdef` 与相关函数无关）。手工：`adm/daemons/natured` 的 `for (i; …)` 改 `for (; …)`；`d/moon/npc/yutu` 的 `kill_ob` 改 `void`（与 `feature/attack` 一致）。
2. **表情守护启动时读档失败，所有表情丢失。** `data/emoted.o` 中 `nokiss` 一条原文是 `“` + 半个汉字（`0xBA`）+ `\"`；转 UTF-8 时 `BA 5C` 被当成一个字（`篭`），吃掉了转义用的反斜杠，剩下的裸引号让字符串提前结束，`restore_object()` 报 `Illegal mapping format while restoring emote`。把这个字还原成反斜杠（半个字无法保留）。修复后新进程启动无此错误，`nod` 显示「你点了点头」。
3. **钱币花到 0 不会消失。** `std/item/combined.lpc` 的 `destruct_me()` 是 `private`，继承它的银两、金子用 `call_out` 调用时被驱动拒绝（启动后即有 9 条 `apply() with insufficient permission ... destruct_me`）。改 `protected`，同一处改动扫了 77 个库（KB 07 §8.3）；修改后 0 条。
4. 验证（新进程，临时副本）：GB → 年龄问题答 `no` → `fluffos` 登录（admin）→ `look`、`nod`、`quit`。


- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 19 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 9 个，只在 #if 分支用的声明移进分支 0 个文件；改动 26 个文件，HEAD 与工作树各载入一次无回退（26 objects; HEAD PASS 26, tree PASS 26; regress 0; newly loading 0），这些文件的警告 50 -> 22。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查（批 3）

- `daemon/skill/*-archery.lpc` `practice_skill()`：`(: throw_weapon :);` 只造函数指针不调用（练习本就不该射箭），删去。
- 改动的对象 HEAD 与工作区都能载入，无回退。

## 深度功能测试（§10.7，2026-10-11）：dns_master 空 if

- `adm/daemons/network/dns_master.lpc` `query_services()`：`if (! (mud_svc[mud]["tell"/"finger"] & SVC_KNOWN)) {` 里只有 `#if PREF_X & SVC_TCP … #endif`，选项关闭时 if 体为空（“无副作用”警告）；把 `#if`/`#endif` 挪到 if 外面（KB 04 §6.10，2026-10-07 那次扫描漏掉了 `! (` 带空格、大括号另起一行的写法）。载入无回退。

## 深度功能测试（§10.7，2026-10-11）：dns_master 空 if

- `adm/daemons/network/dns_master.lpc` `query_services()`：`if (! (mud_svc[mud]["finger"/"tell"] & SVC_KNOWN))` 块里只有 `#if PREF_X & SVC_TCP … #endif`，选项关闭时 if 为空（“无副作用”警告报在下一句）；把 `#if`/`#endif` 挪到 if 外面（KB 04，2026-10-07 那次扫描漏了 `! (` 加括号换行这种写法）。载入无回退。
- 2026-10-14：同一次重扫的其余 39 条（与 wuhanzhan 同源，照它 2026-10-13 的修法）：`d/kaifeng/ground.h` 表加 `GROUND_TABLES_INHERITED` 守卫；`d/obj/cloth/jiasha.lpc` 的 `init()` 先后调用 `cloth::init()` 与 `unique::init()`（两个都是真钩子，只留一个会丢功能）；`d/city/npc/yg/yaoguai.lpc` 去掉与基类重复的 `yaoguai_type`；`d/kaifeng/npc/colors.h` 加防重复包含（`quest.lpc` 在自己的守卫外包含它）；`feature/alias.lpc` 的 `last_time` 改名 `last_cmd_time`（神医 NPC 自己存档的同名字段）；`lijing`/`xiwangmu` 的 `die`/`unconcious`、`jinren` 的 `kill_ob` 改 `void`；7 个文件多余的 `inherit F_CLEAN_UP` 删去；roommaker 死表、未用的局部变量。改动及受影响的对象（26 + 18）新进程各载入一次，无回退。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

5 个文件（技能、绝招、兵器、书籍、区域 NPC 等）来自侠客行体系（qi/jing/neili），而本库人物是 gin/kee/sen/force：`receive_damage("qi", ...)` 报 `伤害种类错误`，`query("neili")` 永远为 0。按 qi→kee、jing→sen（本库学习/读书指令消耗的就是它）、neili→force、max_neili→max_force、jiali→force_factor 改名（`scripts/lpc_port_es_props.py --any-file`）。

## 治疗/疗伤的属性名（2026-10-15，KB 06 §7.241）

`receive_heal()`/`receive_curing()` 也只接受本库的种类。3 个文件（多为只调用 `receive_heal`/`receive_curing` 的药物、NPC）来自侠客行体系，按 qi→kee、jing→本库学习指令消耗的池、neili→force 改名（`scripts/lpc_port_es_props.py --any-file`）。


## 转码吃掉的引号（2026-10-15，KB 03）

原档在右引号前有一个孤立的 GBK 前导字节，转 UTF-8 时连引号一起丢了（如 `return name + HIM "发作身亡了;`），字符串一直延续到后面，文件编译失败：`/d/obj/books-nonskill/hmeng014`、`/d/wusheng/shijie5`。补回引号（`scripts/lpc_fix_eaten_quote.py`）。

## `->query_(` 笔误（2026-10-15，KB 06 §7.245）

调用不存在的函数 `query_`，call_other 静默返回 0，相关判断永远按 0 计算。改为 `->query(`：`buhui`。

## family 映射内联取下标（2026-10-15，KB 05 §7.30）

`ob->query("family")["master_name"]`、`me->query("family")["family_name"]`（泥潭式为 `query("family", ob)[...]`）直接对门派映射取下标：没有门派的人（新玩家、叛师者、大多数 NPC）在 NPC 的打招呼和问话、绝招的门派判断、房间的 `valid_leave` 里报 `Value being indexed is zero`，而不是得到拒绝。1 处（1 个文件）改为 dbase 路径查询 `query("family/master_name")`：有门派时值相同，没有时得 0；原有的判断照常生效（`scripts/lpc_fix_family_index.py`）。给映射赋值的写法未动。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

15 个文件、19 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`），多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/d/city/npc/obj/choupao`、`/d/city/npc/obj/bingfu`、`/d/obj/weapon/staff/tc_staff`）。本库 NPC 基类 `std/char/npc.lpc` 的 `carry_object()` 第一句是 `if (file->query_unique())`，对不存在的文件直接 call_other，驱动在这里报 `call_other() couldn't find object`，`new()` 来不及返回 0，所以只要 NPC 带着一件本库没有的物品就载入不了（调用处加判断对它无效）。在它前面补 `if (!objectp(load_object(file))) return 0;`（`--base`），缺的物品就跳过，NPC 照常载入；上面那些调用处同样改成带判断的块（基类以后改回去也不怕）。载入检查：改动的文件改前能载入 1 个，改后 15 个（14 个原来载入不了），没有退步；其余 1 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## 去掉的预定义宏 `SAVE_EXTENSION`（2026-10-18，KB 04 §6.11）

老版 MudOS 给每个 LPC 对象预先定义了 `SAVE_EXTENSION`（`".o"`）；FluffOS 的 ChangeLog（COMPAT_BUSTER 一条）把它删了，改用 `__SAVE_EXTENSION__`。本库没有自己 `#define` 这个宏，用到它的文件一律 `Undefined variable 'SAVE_EXTENSION'`，整个对象载入不了。改成 `__SAVE_EXTENSION__`（`scripts/lpc_fix_predefined_macro.py`）：`adm/daemons/network/netmail.lpc`。`netmail` 是网络邮件守护进程（本库缺 `mailer.h` 等头文件，改后仍载入不了）。改后用 `lpcc` 逐个载入这些对象：0 个通过，1 个还有别的错误（`adm/daemons/network/netmail`：/adm/daemons/network/netmail.lpc:17: error: Cannot #include mailer.h）。

## 蓬莱三星的 `ref()` 是保留字（2026-10-18，KB 04 §6.14）

福星、禄星、寿星（`d/penglai/npc/`）里有一个函数叫 `int ref ()`，`call_out("ref", 20)` 去调它；`ref` 在 FluffOS 里是关键字（引用），`unexpected L_REF`，三个 NPC 都载入不了。函数和 `call_out` 都改叫 `reff`（本系里 dtxyzjb、zitengzhan 早就这么改，`call_out` 却没跟着改）：`d/penglai/npc/fuxing.lpc`、`d/penglai/npc/luxing.lpc`、`d/penglai/npc/shouxing.lpc`。改后载入：3/3 通过。

## `d/moon/obj/poem` 两句诗丢了收尾的引号（2026-10-18，KB 03 §4.6）

`string *poem` 数组里 `"不放玉花飞堕地，留在广寒宫阙。,` 和 `"把酒送春春不语，黄昏却下潇潇雨。,` 的收尾引号没了（转码时跟半个汉字一起丢了），下一行的开引号把字符串合上，后面的诗句成了代码：`Illegal character 0xe6`，整个物件载入不了。补回 `",`。载入：通过。

## `d/shendian/obj/niepan` 的收尾引号变成了私用字符（2026-10-18，KB 03 §4.6）

`set("long", HIR"……五种符号<U+E4D4>NOR);` 里本该是 `"` 的位置是一个私用区字符（转码时半个汉字加引号被换成了它），`Illegal character 0xee`，整个物件载入不了。换回 `"`。载入：通过。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 6 个对象设了本库没有文件的武功（7 个名字，最多的是 `qiankun-danuoyi`、`chanting`、`essencemagic`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：6 个里 6 个通过。（`scripts/lpc_guard_set_skill.py`）

## 补回本库没有的基类文件（2026-10-18，KB 04 §6.15）

下面这些基类本库没有，继承它们的对象（房间、NPC、物品）整批载入不了（`inherit XXX;` 的宏没定义，或者 `inherit "/std/…";` 的文件不在）。同系的库里有同名文件，两库有大量逐字节相同的文件（亲缘关系），所以从那边原样拷来，缺的宏补进全局头文件 `include/globals.h`：`/std/weapon/needle`（宏 `NEEDLE`）←mhxyqd，2 个对象继承它，抽样 2/2 载入；`/feature/dealer`（宏 `F_DEALER`）←sjshv150，1 个对象继承它，抽样 1/1 载入；`/std/weapon/unarmed`（宏 `UNARMED`）←sjsh，1 个对象继承它，抽样 1/1 载入。每个基类补回后单独载入、再抽样载入使用它的对象，基类载不进来或者一个用户也载不进来的就撤掉（本库撤掉了它们，不再补）。（`scripts/lpc_restore_bases.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 10 处、10 个文件：`dagonforce`→`dragonforce`（4 处）、`hellfire_whip`→`hellfire-whip`（2 处）、`dragon-step`→`dragonstep`（2 处）、`yange_blade`→`yange-blade`（1 处）、`cuixi-zhang`→`cuixin-zhang`（1 处）。（`scripts/lpc_fix_skill_names.py`）

## 全局头文件丢了 2 个宏（2026-10-19，KB 04 §6.16）

`/include/globals.h` 里没有定义 `MAILDIR`、`CITY_OB(city,room)`，用到它们的物件（名单里 2 个）编译时报 `Undefined variable`/`Undefined function`，整个物件载入不了（编译器在第一个未定义的名字上停下，后面的错误和警告都看不到）。同系的库在各自的头文件里都有这几行：照其中和本库共有文件最多的那个库，原样补到 `/include/globals.h` 最后一个 `#define` 之后，宏体里出现的路径在本库里都存在。补完后名单里有 1 个载入，其余还差别的东西。（`scripts/lpc_restore_defines.py`）

## 找不到父类函数的 ::fn() 调用（2026-10-19，KB 06 §7.259）

`/d/city/npc/duguoyin.lpc`共 1 个物件里写着 `::create();`、`::init();` 这类调用，而它们继承的基类并没有这个函数。老驱动把这种调用当成什么都不做、返回 0 的空调用，本驱动在编译时报 `Unable to find the inherited function 'init'.`，整个物件载入不了。这些物件的错误只有这一种（其他错误清掉之后才露出来的），逐个删掉这些调用（`return ::fn(...)` 改成 `return 0;`）。（`scripts/lpc_fix_dangling_super.py`）

## 出口指向不存在的房间（2026-10-19，KB 06 §7.257）

下列房间的出口写的文件不存在，而对面恰好只有一个房间的出口指回本房间，所以按对面的房间改正（笔误、大小写、路径少了一级）：

- `/d/shendian/kushi.lpc` 的 `east` 出口：`tianshentai` → `fengshentai`
- `/d/shendian/rongshi.lpc` 的 `west` 出口：`tianshentai` → `fengshentai`

改后房间照常载入（与 HEAD 逐个对比，没有退步），出口现在指向存在的房间。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 被注释吞掉的 inherit / include（2026-10-19，KB 06 §7.274）

`/daemon/class/moon/moonshentong/shiyue.lpc`：`inherit SSERVER;`。这些指令接在上一行 `//` 注释的末尾（档案里丢了换行），成了注释的一部分，驱动看不到：缺 `inherit` 的技能报 `Undefined function offensive_target`，缺 `#include <weapon.h>` 的兵器报语法错误。`scripts/lpc_fix_swallowed_directive.py` 把换行放回去。载入检查 1 个文件，1 个原来编译不过、现在载入，没有退步。

## 补回丢失的标点（2026-10-19，KB 03 §4.6）

转换时丢掉的分号、逗号、引号或文件末尾的 `}`，共 1 个文件，修前 HEAD 载入失败。别的库里同路径的完好副本只比这里少几个标点，按它补回（括号里是那个库）：`/d/obj/quest/quest_cl.lpc`（dtxywzxzb）。修后与 HEAD 逐个对比载入：这 1 个物件全部载入，没有退步（`scripts/lpc_restore_from_twin.py`、`lpc_fix_eaten_quote.py --comma`、`lpc_fix_eof_braces.py`）。

## 菩提祖师的银针：`last_time` 没有声明（2026-10-19）

`d/lingtai/npc/puti.lpc` 的 `give_zhen()` 用 `last_time` 限制银针发放速度，整个文件没有声明这个变量，编译不过（`Undefined variable 'last_time'`）。文件头加 `int last_time;`（`sjcs` 里是同一个文件，开机预装入时报这行错误）。

## `== !"字符串"` 多出来的 `!`（2026-10-19，KB 06 §7.280）

`!"taoist"` 是整数 0，`x == !"taoist"` 就是“x 等于 0”，作者为其余所有人写的那一支永远走不到。具体是：“你是怎么混进来的？给我滚！”只对没有门派的人生效（方寸山三星洞以外的门派的人反而放进来）。全部改成 `!= "字符串"`（`scripts/lpc_fix_not_literal_cmp.py`）：`/d/lingtai/npc/puti.lpc`（1 处）。同样的行在 xkx 一系的 35 个库里都有。

## `call_out_info()` 的每一项只有 3 个元素（2026-10-20，KB 06 §7.287）

驱动返回的是 `({ 物件, 函数, 延迟 })`，不带 call_out 的参数，旧代码读第 4 项 `info[i][3]`（`callouts` 指令、`calloutd`、`cod` 工具）一读就报 `Array index out of bounds`，指令从第一行起什么也打印不出来。改为 `(sizeof(info[i]) > 3 ? info[i][3] : 0)`（`scripts/lpc_fix_callout_info.py`）。改动：`/cmds/wiz/callouts.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 9 处）。改动：`/clone/medicine/liushen.lpc`（1 处）、`/cmds/wiz/dns.lpc`（1 处）、`/d/shendian/babu/obj/longzhua.lpc`（4 处）、`/d/wiz/npc/jing.lpc`（3 处）。

## `callouts`：`sizeof(info[i]) == 4` 把每一行都挡掉了（2026-10-20，KB 06 §7.287）

驱动的 `call_out_info()` 每项只有 3 个元素，输出行前的守卫 `if (sizeof(info[i]) == 4)` 永远不成立，指令只打印表头。改为 `>= 3`。改动：`/cmds/wiz/callouts.lpc`（1 处）。

## `socket` / `dumpsocket` 指令：`dump_socket_status()` 驱动里没有（2026-10-20，KB 06 §7.291）

这些巫师指令 `write(dump_socket_status());`，MudOS 的 efun 在 FluffOS 里不存在，指令编译不过。在模拟 efun 文件里补了 `dump_socket_status()`：用 `socket_status()` 排出同样的表（没有 sockets 包的构建，比如 WASM，只有表头；`scripts/lpc_add_sefun.py dump_socket_status`）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/obj/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## sefun `cat()`：缺文件时 `write(0)` 报错（2026-10-20，KB 06 §7.297）

`void cat(string file) { write(read_file(file)); }`：文件不存在（压缩包没带的欢迎/公告文件，或只有运行中的 mud 才会写的日志）时 `read_file()` 回 0，`write(0)` 在本驱动里报 `Bad argument 1 to receive()`，调用者（登录对话、`cat` 指令）被中断；老驱动什么也不打印。改成 `write(read_file(file) || "");`（`scripts/lpc_fix_cat_unchecked.py`）。改动：`/adm/simul_efun/file.lpc`。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库现有的 NPC 文件里没有字面写成空 `chat_msg` 的（扫描只认 `set("chat_msg", ({ }))`）；守卫挡的是运行时才为空的列表和以后新增的 NPC。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/std/char/npc.lpc`（共 1 个文件）。

## 巫师命令不带参数时对 0 调用 efun（2026-10-21，KB 06 §7.336）

巫师（管理员）把命令敲成不带参数时，驱动把 0 传给字符串参数；下面的命令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`，这条指令从来没有用过。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py` 在第一处使用参数的语句前加守卫：文件自带 `int help(object me)` 的，守卫是 `if (!arg) return help(me);`（`help()` 定义在 `main()` 之后的 1 个文件补了原型 `int help(object me);`，否则编译报 `Undefined function help`）。改动（1 个文件，括号里是接住 0 的 efun）：`/cmds/adm/dumpprog.lpc`（`new`）。加载检查 HEAD 与工作树对照，没有退步。

## `cron.lpc`：`emery()` 用循环外的下标，第一次越界就让 cron 停摆（2026-10-21，KB 06 §7.345）

怪兽入侵事件 `emery()`（`/adm/daemons/cron.lpc`）末尾 `for (m = 0; m < sizeof(user); m++) user[i]->set("kill_guaishou", 1);`：`i` 是前面随机选的地区下标，循环变量 `m` 没用上，同一个玩家被标记 `sizeof(user)` 次，在线人数不到 `i + 1` 时下标越界（`Array index out of bounds`，yueyingqiyuan 管理员扫描里的控制台行；`call /adm/daemons/cron->emery()` 一个人在线时四次里三次抛错）。`init_cron()` 在 15 分钟的整点调用 `emery()`，之后才 `call_out("init_cron", 60)` 重新排自己：抛错之后重排没有执行，玩家自动存盘（`autosave()`）、动态任务刷新（`TASK_D->init_dynamic_quest()`）和后面所有事件在这次启动里都停了。改成 `user[m]`（yueyingqiyuan 上实测：连续六次 `emery()` 都正常返回）。这个标记档案里没有任何地方读它（`go.lpc` 里的用法是注释掉的）。

## 拼错的 `call_out()` / `input_to()` 目标（KB 06 §7.349，2026-10-21）

计时器或输入提示给驱动的函数名和文件里定义的差一个字母；驱动对不存在的函数静默不理，所以对应的计时从来没有触发过。调用和配套的 `remove_call_out()` 改成已定义的拼法：`find_seal`：`disapprear` → `disappear`（法术产生的封印十分钟后从不消失）。改动：`/d/jjf/obj/find_seal.lpc`。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 11 条注册（6 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/d/changan/pinqiting.lpc`（`do_pass`、`do_resign`）、`/d/city/npc/duguoyin.lpc`（`do_vendor_list`）、`/d/eastway/npc/petboss.lpc`（`do_cost`、`do_list`、`do_upgrade`）、`/d/pansi/npc/qingxia.lpc`（`do_yes`）、`/d/qujing/jisaiguo/obj/luche.lpc`（`do_get`、`do_put`）、`/d/qujing/wudidong/cave2.lpc`（`do_push`）。最多的函数名：`do_push` 2 处、`do_pass` 1 处、`do_resign` 1 处、`do_vendor_list` 1 处、`do_cost` 1 处。没有动（读过）：`/d/qujing/chechi/wugu.lpc` 的 `do_kan`（不是单独一行的语句（`obj->add_action()`、宏或没有分号的写法））。

## 调用了、但这个库自己的守护进程里没有的函数（2026-10-22，KB 06 §7.354）

`MACRO->函数()` 调用的函数在这个库的守护进程里不存在：`call_other()` 对不存在的函数不报错、只返回 0，所以这些功能（时间显示、昼夜事件、名字检查、价格文字……）一直没起作用。同一血统另一个库的同名守护进程里有这些函数，原文照抄到本库守护进程末尾（`scripts/lpc_port_function.py`；调用处传的参数个数、函数体用到的函数 / 全局变量 / 宏 / 字符串键都在本库里有，已核对；守护进程在 HEAD 和工作区都能加载，每个函数用固定参数各调用一次：HEAD 返回 0，现在返回正常的值）：`/adm/daemons/chinesed.lpc` ← aoxiangtianji：`chinese_period()`（1 处调用）；`/adm/daemons/moneyd.lpc` ← aoxiangtianji：`price_str()`（3 处调用）。

## `/d/qujing/kusong/obj/WEAPON4` 大写文件名，随机兵器取不到（2026-10-22）

`/d/qujing/kusong/npc/yao1` 用 `str = "/d/qujing/kusong/obj/weapon0"; str[strlen(str)-1] = '0' + random(5); carry_object(str)->wield()` 随机挑一件兵器，`weapon0` 到 `weapon3` 是小写文件名，第五件存成了大写的 `WEAPON4.C`（压缩包来自不分大小写的系统，路径是运行时拼出来的，`scripts/lpc_case_paths.py` 看不到）：抽到 `weapon4` 时 `carry_object()` 返回 0，`->wield()` 报 `Bad argument 1 to EFUN call_other() Got int(0)`，五分之一的妖怪刷不出来（goto 探测在同系的 sjcs 里碰到，这个库的 `yao1` 写法一样）。`git mv` 成小写的 `weapon4.lpc`（`.C` 后缀的文件不会被无后缀的 `.lpc` / `.c` 查找命中；同系其他库里同一个文件是小写的 `weapon4.lpc`，内容一致）。证明（`scripts/lpcc_eval.py`，HEAD 与工作区各一个新进程）：`load_object("/d/qujing/kusong/obj/weapon4")` 在 HEAD 返回 0，改名后得到对象。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 还剩 2 个函数没有补（other 1, inquiry 1）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/cmds/usr/bbs.lpc`:`confirm_l_choice`、`/d/city/npc/job.lpc`:`give_dan`。 另有 3 处函数体被作者整段注释掉（指针没跟着删），是有意关掉的，没动。

## 运行期目录 `log/nosave` 不存在，写日志的 `write_file()` 直接报错（2026-10-22，KB 03 §4.3 补充）

这个库的 9 个文件里有 9 处 `write_file("/log/nosave/...")` / `log_file("nosave/...")`（`static` 改 `nosave` 时连字符串里的日志路径一起改了，原来是 `log/static/`）：`nosave/using`、`nosave/addobj`、`nosave/full` 等。压缩包和站点包里没有这个目录，`write_file()` 在目录不存在时抛 `*Wrong permissions for opening file /log/nosave/... for append. "No such file or directory"`，调用它的函数（杀人记录、重启记录、`call` 日志……）当场中断。把 `log/nosave` 记进 `scripts/wasm_keep_dirs.txt`（站点和 pristine 树都按它建空目录）；没有把字符串改回 `static`。证明（`scripts/lpcc_eval.py`，`catch(write_file("/log/nosave/ZZTEST", ...))`，fqyy2 / hy5 / bmxkx2001 的新进程）：补目录前报上面的错误，补后写成功。

## `log/` 下的日志子目录没有人建：写日志的 `write_file()` / `log_file()` 报错（2026-10-22，KB 06 §7.358）

这个库的代码往 `log/` 的 2 个子目录写日志：`log/dlog`（`adm/daemons/moneyd.lpc`）、`log/doc/register`（`cmds/usr/helpbbs.lpc`）。压缩包、`git clone` 和站点包里都没有这些目录（本地启动没有写过它们，`gen_keep_dirs.py` 没记），`write_file()` 对不存在的目录抛 `*Wrong permissions for opening file /log/dlog/money for append. "No such file or directory"`，调用它的函数在写日志那一行中断，后面的奖励、标志、步骤都没有执行。本库的 `log_file()` 会自己建目录（实测，或读源码：nitan 系的 `assure_file()`），所以这里只记了直接用 `write_file()` / `save_object()` 写的目录。把 `log/dlog`、`log/doc/register` 记进 `scripts/wasm_keep_dirs.txt`（`scripts/lpc_keep_log_dirs.py`；站点和 pristine 树按它建空目录）。证明（`scripts/lpcc_eval.py`，在 `/adm/daemons` 这类目录下的求值对象里写 `/log/zzdirprobe/...`，新进程）见 KB 06 §7.358 的实测表。

## `(: 函数名 :)` 指针指向本库没有的函数：只含这个指针的行加了注释（2026-10-22，KB 06 §7.355 补充）

`inquiry` / `item_desc` / `chat_msg*` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：用到时（`ask`、`look`、NPC 闲聊）驱动抛 `*Undefined lfun pointer called: 函数名`，这一拍心跳的后半段被跳过。这些函数没有可以补回的来源（别的库同一路径的文件里没有，或者它还要用本库没有的东西），所以 2 个文件里 4 行只含这个指针的行（`"复仇": (: avenge :),` `"漫天飞雪": (: ask_tian :),` `"下山": (: expell_me :),`）加了注释，原文保留并写明原因，这一项当作没有这个话题 / 物品 / 闲聊条目（`scripts/lpc_fix_dangling_lfun.py`；`#include` 的文件在库里缺失的对象、指针不在整行上的写法没动）。 前提（`function_exists()`）和加载检查（HEAD 与工作区对比，本库改动的 `.lpc` 文件）的结果见 KB 06 §7.355：没有一个回归。

## 汉字按字节切片的老写法没有换成按字符：改法名 `"澄" + name[2..3]`、辈分判断 `name[0..1] == "澄"` 等 3 处（2026-10-22，KB 06 §7.360）

原档按字节算字符串区间（一个汉字 2 字节）：`name[2..3]` 是名字的第二个字，`name[0..1] == "澄"` 问名字是不是以「澄」开头。转成 UTF-8 之后，这个驱动的区间和 `strlen()` 都按字符算（`strlen("澄观")` 是 2，`"澄观"[0..1]` 是两个字），老算术原样留着、意思全变：拜入少林 / 武当 / 峨嵋等派的玩家被改成错误的法名（二字名 `张三` 变成一个字的 `澄`，更长的名字取到第三个字）。

本库 3 处（2 个文件）：拼名字的赋值 3 处。例：`name[0..1]` → `name[0..0]`（`/d/nanhai/npc/master.lpc:104`）。`scripts/lpc_fix_gbk_slice.py` 把下标按字符重算（社区的 UTF-8 版 `xkx100utf8` 里就是同样的写法，作对照）；没有改的：截断（`name = name[0..7]`，现在最多 8 个字，只是放宽）、ASCII 的区间（`fname[0..3] == "room"`、`ctime(time())[4..19]`）和上下文看不出是汉字的区间。证明（`scripts/lpcc_eval.py`，bixiecanyang；其余各库是同一份文本）：让澄字辈掌门 `attempt_apprentice()` 一个名叫「张三」的访客，HEAD 的法名是 `慧`，改后是 `慧三`；抽样 28 个库的 HEAD / 工作树加载对比 0 退步。工具不幂等（`[0..3]` 折半得 `[0..1]`，又是对齐区间），改过的文件记在 `scripts/gbk_slice_converted.txt`，不要重跑。
