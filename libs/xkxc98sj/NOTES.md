
## WASM 修复摘要（迁移自 meta.json 的 group_note）

「侠客新传」v0.1b，MudOS v22pre11，Xkxz MUD Wizard Group 2000-2001，由 jjgod 维护。WASM 修复了 5 个各自独立的 bug：（1）和 wdxtym 上已经修过的同一个 eventd.lpc off-by-one：event_name = map_array(event_name, (: $1[0..<3] :)) 想去掉 4 个字符的".lpc"后缀，却只去掉了 2 个字符（"emei.lpc"变成"emei.l"），导致 collect_all_event() 对每一个事件档案的 call_other() 都失败——已改成 [0..<5]。（2）adm/simul_efun/chinese.lpc（只检查前 2 个原始字节，对照一个固定字节区间，在 UTF8 码点索引下永远失败）和 adm/daemons/logind.lpc 自己的长度界限（最小 2/最大传 8，本意是最小 1/最大 4，对应注册提示文字"名字的长度不能大于四个汉字"）里 §8.1 类的 check_legal_name()/is_chinese() GBK 字节区间 bug——已把 is_chinese() 改写成逐码点循环，并把长度界限和 check_legal_name(arg, 8) 呼叫点都改成 4。（3）一个系统性的 is_killing(object) 对 is_killing(string) 类型不匹配，波及 18 个档案（feature/attack.lpc 声明 is_killing(string id)，但 kungfu 技能和城市 NPC 里的很多呼叫点直接传物件：is_killing(me)/is_killing(who)/is_killing(ob)/is_killing(ob[i])）——和之前在这一轮里已经修过的 sjecl/sje 完全同一类 bug，这里波及范围大得多；已把所有活跃呼叫点都改成传 ->query('id')（haotian-zhang/ju.lpc 和 quanzhen-jianfa/ding.lpc 里各有一处已经被作者自己注释掉的呼叫点保持原样，因为是死代码）。（4）+（5）§7.41 类损坏的存档 bug：adm/daemons/emoted.lpc 的 create() 对一份真正损坏的 emote.o（"Illegal mapping format"）未加保护地呼叫了 restore()，adm/daemons/newsd.lpc 的 create() 对一份损坏的 dbase 存档也有完全相同的未加保护 restore()——两处都已包上 catch()，让异常不再在 create() 到达（或者对 emoted 来说完全跳过）空映射兜底之前就中止；已通过驱动自己的错误堆栈确认两处现在都被本地捕获（精灵自己 create() 里的 CATCH() 帧），而不是传播到很远的外层 catch，下游也没有观察到任何进一步的错误。管理员账号播种：fluffos (admin) 加入 adm/etc/wizlist（已通过源码确认 SECURITY_D 真的会在开机时读取 WIZLIST）。注册流程在一次连续的 WASM 客户端会话里完整验证过：BIG5/GB 提示→英文 id→y/n 创建确认→密码+确认→中文名字→角色类型选择（1-5）→性别→带着可用的 score/look 进入游戏世界，没有残留的运行时错误。管理员权限已直接通过"您目前的权限是：(admin)"确认。LPC 格式化工具对全部 6905 个档案运行（写入 6829 个，44 个因为杂乱的历史代码报错，32 个未改动）。没有 :: 父类呼叫拆分命中，没有 CJK 重新加空格命中，没有 case 标签带尾随注释的候选。全部 3 个 map.lpc 档案确认内容完全相同（只是空白差异）。格式化后用同样的完整注册流程重新验证过——干净，管理员权限依然是 (admin)，除了那两处已知已捕获的错误外没有其它 restore 错误。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 27 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（§10.7，2026-08-09）

**血统确认**：`adm/single/master.lpc` 的档头注释（"for ES II mudlib /
original from Lil / rewritten by Annihilator (11/07/94) / modified by
Xiang for XKX (12/15/95) / updated by Doing Lu for hell (2K)"）与
`libs/hell/work/adm/single/master.lpc` **逐字节完全相同**（忽略 CRLF
差异）——`xkxc98sj` 是 AGENTS.md §11「"hell" / Doing Lu」这一支
ES II → XKX → hell 血统的确认成员，和 `zjdyaryl`/`zjdyzj`/`hell` 同源
（§7.42 记录的"Century/adm-single 批量转换"那批：`zjdywzb`/
`zjdy2008wzb`/`hell`/`xkxc98sj`/`ntii`/`nte`，当年共享同一个自动配置
生成器，都踩过"错把内容 NPC 当成 master 文件"的坑）。**特别核对过和
`xkx100`/`xkx2017`（本轮此前已深挖过的另一支"侠客行"血统）是否同源
——不是**：`xkx100`/`xkx2017` 自己的 `master.lpc` 档头只到"modified by
Xiang for XKX (12/15/95)"就结束，没有"updated by Doing Lu for hell"这
一行；`securd.lpc` 也和 hell 支系形状不同。「侠客新传」和「侠客行」共
享的只是"XKX"/"侠客"命名巧合（README 里早已记录过和"书剑"系列 `sjecl`/
`sje` 等的巧合是同一类情况），不是代码血统——本项目反复验证过命名不
是血统信号，这里再添一例。`securd.lpc` 本身相对 `hell` 已经独立漂移
（813 行 vs 796 行，注释翻成中文并加了"Last modified by Jjgod Jiang
for FYTX"的落款），是同根不同支的独立分叉，不是逐字节拷贝。

`cmds/std/go.lpc` 的移动派发也是同一血统的典型形状（先查房间自己
`exits` 映射里键是否存在，存在才调用 `valid_leave()`），所以专门按
§7.101（`kxkjii2` 发现的死亡出口 bug）核对过死亡/复活房间——**不适
用**：`阎罗大殿`（`d/death/gateway.lpc`）、`鬼门关`（`d/death/gate.lpc`）、
`孟婆亭`（`d/death/mpting.lpc`）三个死亡区房间的 `exits` 映射和各自
`valid_leave()` 里能处理的方向完全一致（都只有一个入口/出口方向，没
有被注释掉、`exits` 里缺失但 `valid_leave()` 仍在处理的"死代码"分
支），不是这个 bug。另外专门核对了 §7.68（`bmxkx2001` 确认、随后在
28 个库上撤销的"present() 守卫放弃复活"模式）——`d/death/npc/
{yanluo,mengpo}.lpc` 的 `death_stage()` 确实是同一个 `if (!ob ||
!present(ob)) return;` 守卫形状，但两个死亡区房间的 `valid_leave()`
对非巫师玩家统一拒绝唯一的出口方向（"没有回头路了！"/"喝了它，就什
么都忘记了！"），即鬼魂在这几个房间里**完全无法自主移动**；全档案没
有找到任何类似 `bmxkx2001` 那个"导游 NPC 强制拖走玩家"的强制位移机
制。按照 §7.68 撤销说明的两个前提（鬼魂真的无法自主移动 **且** 确实
存在别的系统会强制移动鬼魂）——第一条成立，第二条找不到证据——因此
**没有套用那个 fix**，维持原样，与本轮此前 `xkx100`/`xkx2017` 等 28
个库上撤销的结论一致。现场验证详见下文：两次完整的、无干扰的死亡→
复活循环都顺利走完，没有出现卡死。

**本轮修复的 bug**：

1. **§7.103：`master.lpc` 的 `log_error()` 把普通编译警告也原样吐给
   每一个在线玩家**：`adm/single/master.lpc` 的 `log_error()`
   对 `this_player(1)`/`this_player()` 无条件 `write()`/`tell_object()`
   编译诊断信息，包括警告——现场验证：刚连线看到开机横幅后，注册流
   程的id提示符前面就先刷了两条 `编译时段错误：/cmds/usr/uptime.lpc:
   ...warning: Unused local variable 'y'` 之类的原始编译警告，此后
   每碰到一个本局第一次冷编译的档案都会再刷一遍。和 AGENTS.md §7.103
   （`zzfy3` 发现）完全同一形状，用同样的
   `strsrch(message, "warning:") == -1` 门槛修复。现场验证：修复并重
   启驱动后，同样的连线+注册流程（会触碰大量此局第一次冷编译的档
   案）不再出现任何 `编译时段错误：...warning:` 前缀的行，真正的运行
   时错误（未改动）仍然正常出现。
2. **§7.90 第七个实例：`maximum evaluation cost` 700000 默认值在角色
   创建阶段（`make_body()`）就 100% 必现地打断注册**：`config.fluffos`
   沿用本项目最常见的 700000 默认值，但 `logind.lpc` 的
   `get_gender()`（性别选择后紧接着调用 `make_body()`）第一次冷编译
   `inherit/char/char.lpc` 整条特性继承链（`feature/damage.lpc`、
   `feature/skill.lpc` 等一大批档案）时稳定撞上
   `Eval interrupted: object adm/single/master cost limit reached,
   limit: 700000 usec`，玩家侧毫无提示，静默卡在性别提示符之后。和
   `xyj2000f`/`xiyouji450` 那种"每次全新驱动进程 100% 复现"的严重变体
   同形状，只是血统不同（这里是 ES II → XKX → hell 支系，§7.90 第五
   个实例 `zjdyaryl` 也是同一支系，但触发点不同——那边是背景任务
   `heart_beat()`，这里是注册流程本身）。修复：`maximum evaluation
   cost` 从 700000 提到 5000000（本项目已有 30+ 库使用的常规补救
   值）。现场验证：修复前，连续两个全新驱动进程各自的第一次注册都
   在 `get_gender()` 后稳定复现该错误；修复并重启驱动后，完整的
   id→密码→中文名字→角色类型→性别注册流程顺利进入游戏世界，随后
   完整的移动、战斗、两次完整死亡/复活循环全程都没有再出现
   `cost limit reached`。（注：这份档案的 `master.lpc` 把编译/运行
   时诊断写进 `LOG_DIR + "log"`，也就是 `work/log/log`，不是标准的
   `work/log/debug.log`——排查时按这个路径找。）
3. **§7.81 第四个实例：`inherit/misc/quest.lpc` 的 `set_information()`
   包装函数把 `string` 类型声明得比它转发的 `QUEST_D` 后端更窄，
   拒绝任务档案传闭包**：`include/quest.h` 的原型和
   `inherit/misc/quest.lpc` 的实现都声明
   `set_information(string key, string info)`，但 `clone/quest/
   {search,shen,judge,supply,deliver,explore,defend}.lpc`（7 个档
   案）调用时传的是 `(: ask_npcN :)` 闭包，编译报
   `Bad type for argument 2 of set_information ( string vs
   function )`——和 AGENTS.md §7.81 记录的 `nt1`/`yhwhpublicfi`/
   `zjdy2008wzb` 完全同一形状（`yhwhpublicfi`/`zjdy2008wzb` 恰好也
   是"hell"支系，这是第四个确认实例）。零运行时症状：受影响档案各
   自的任务精灵（`adm/daemons/quest/{search,supply,deliver}.lpc`）
   周期性 `heart_beat()` 只是静默往 `log/log` 里写
   `*No program in object '/clone/quest/search'!`，玩家侧完全无
   感，只有主动读日志才能发现。修复：`include/quest.h` 的原型和
   `inherit/misc/quest.lpc` 的实现都把 `string info` 改成
   `mixed info`（和它实际转发的 `QUEST_D->set_information(object,
   string, mixed)` 签名对齐）。现场验证：巫师账号对全部 7 个受影响
   档案逐一 `update`，全部回报"重新编译 ... 成功！"，日志里再也没
   有 `Bad type for argument 2 of set_information` 的行。`clone/
   quest/{defend,block}.lpc` 各自还有另外的、和这个 bug 无关的编译
   错误（`Undefined variable 'ENEMYS'`/`'my'`/`'i'`、`Illegal
   lvalue`、`Illegal to use local variable in a functional`、
   `Too few arguments to 'message'`）——看起来是原始档案里本来就没
   写完/损坏的任务脚本，不是这个 bug 类的又一个拷贝，只记录、未修
   复。

**现场游玩验证**（一次连续会话，`sunycta`/`verifyq` 两个测试角色 +
`fluffos` 管理员账号，均为本轮临时注册，`sunycta`/`verifyq` 的存档
已在收尾前删除，`fluffos` 按 §1.5 保留）：

- 完整注册流程（英文 id → y/n 创建确认 → 密码+确认 → 中文名字
  "秦风二" → 角色类型 1-5 → 性别）一次性走完，进入"世外桃源"登记
  室；`register <email>` → `decide` → 分别走 `west`（选中"阴险奸诈"
  品质）→`wash`（忘忧池掷四维）→`born 中原人氏`（投胎选籍贯）全套
  流程，最终落地在"悦来客栈"，`look`/`score` 都正常输出，食物/饮水
  条满格（没有 §8.9 那种错对象食水检查 bug）。
- 移动测试：`west`（客栈→南阳城）等若干步，无异常。
- 留言板：`武馆大院` 的"武馆花名册(board)"能正常 `look board`
  查看描述，`post` 被"你现在的江湖阅历不够在这里留言。"正常拒绝
  （游戏内容门槛，不是崩溃，§7.86 已在 WASM 阶段修过、这里复测未
  回归）。
- 战斗+死亡+复活：用管理员传送到 `d/shaolin/shulin10`（松树林，
  三位攻击性"护林僧兵"驻守），先是管理员账号 `fluffos` 自己被僧兵
  杀死（无意间验证了一遍非战斗触发路径），完整无干扰等待约 80 秒
  （5 段对话，每段间隔 5 秒 + 首次 60 秒延迟），`reincarnate()` 后
  正确落地在 `START_ROOM`（`/d/wuguan/dayuan`，武馆大院）；随后又
  专门用非管理员角色 `sunycta` 主动 `kill seng bing` 打了一场真实
  战斗（非脚本触发），力竭死亡，同样完整无干扰等待，`score` 确认
  "你到目前为止总共到黑白无常那里串门一次。你最后一次是被护林僧
  兵砍死了。"，属性/经验值完整保留，落地房间同样正确。两次循环
  （管理员+非管理员）都没有触发 §7.68/§7.101 相关的任何卡死。
  `REVIVE_ROOM`（`/d/city/chmiao`）和 `START_ROOM`（`/d/wuguan/
  dayuan`）两个宏都确认指向真实存在的档案，不是 §7.76 那种悬空
  路径。
- 管理员账号播种（§1.5）：`adm/etc/wizlist` 里 `fluffos (admin)`
  这一行本来就已存在（早前某轮迁移时写入），但没有对应存档——本
  轮用标准注册流程认领了这个 id（密码 `Mud@2026`），登录后确认
  "您目前的权限是：(admin)"，并用 `update /adm/single/master`
  验证了实际写权限（不只是显示的等级）。

**测试环境细节**：`scripts/tmux_mud.sh` 在发送 `born 中原人氏`（含
中文地名参数）时出现过一次会话卡死（后续任何命令包括空行都读不到
新输出）——按 AGENTS.md §10.2 的已知坑，换用 `scripts/mudclient.py`
原始 socket 客户端重新发送同样的指令，一次成功，确认是本地 telnet
传输层损坏了特定 CJK 字节，不是 `born` 命令本身的 bug。

**格式化**：仅对本轮实际改动的 3 个 `.lpc`/`.h` 档案
（`adm/single/master.lpc`、`include/quest.h`、`inherit/misc/quest.lpc`）
跑了 LPC 格式化工具（`master.lpc`、`quest.h` 被重新格式化，
`quest.lpc` 内容已符合格式未改动）；§9 三个已知盲点（`::` 拆分、
CJK 重新加空格、`case` 标签吞注释）逐一检查均为空，格式化后重启
驱动+完整重跑一遍注册+死亡/复活流程确认无回归。

## §7.100 sweep (2026-08-19): redundant `replace_program(ROOM);` landmine

Same corpus-wide bug as documented at AGENTS.md §7.100: rooms
inheriting `ROOM` (`/inherit/room/room`) had a redundant, harmful
`replace_program(ROOM);` call right after `inherit ROOM;` in `create()`,
setting a permanent "pending replace" flag that crashes the object the
first time anything binds a closure to it. This lib had **1,715 live
occurrences** (survey-ranked #85 of 166 candidates >=100, tied with and
byte-similar to sibling lib `xkxz2` — same daemon-content lineage but
NOT byte-identical, so verified independently rather than assuming a
free pass). Fixed with the sweep's binary-mode script
(`fix_710_room.py`) plus two hand-fixed room-building-tool copies
(`clone/misc/roommaker.lpc`, `cmds/debug/roommaker.lpc`, same shape as
`xkxz2`'s). `git diff --numstat` totals (2 insertions, 1715 deletions)
match the survey's live-occurrence count exactly. No `work/data/`
room-source false-negative found. Verified via a clean `build-debug`
boot (zero "cannot replace"/"cannot bind" `debug.log` lines, port 40126
listening) plus a live admin login (`fluffos`/`Mud@2026`, after
answering the BIG5-font prompt with `n`) — `look`/`quit` both worked
normally, `debug.log` stayed clean throughout. Incidental admin
save-timestamp drift from the spot-check reverted before committing.

### ```§7.112``` residual-gap closure (2026-08-20)

Corpus re-scan (`grep -rl 'call_out("death_stage"' ... | filter for missing guard`) found unguarded `init()`-scheduled `death_stage()` call_out chain(s) in `d/death/npc/yanluo.lpc` that the original two-wave sweep (see AGENTS.md §7.112) missed -- same reconnect-triggered duplicate-chain bug, different filename/lineage. Added the standard `query_temp("death_stage_active")`/`set_temp`/`delete_temp` re-entry guard, adapted per file's own exit points. Compile-verified via `lpcc --batch`.
