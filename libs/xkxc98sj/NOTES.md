
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

## §7.30 uninitialized-mapping accessor sweep (2026-08-20)

Corpus-wide mechanical sweep of the `feature/skill.lpc` shared-lineage
bug (confirmed independently on `xiakexing2017`/`jqxz2015`/`haiyang2`
via round-four testing): 5 accessor(s) in this file returned a raw
never-initialized `mapping` instance variable (defaults to `int 0`,
not `([])`, until first assigned), crashing any unguarded
`keys()`/`sizeof()`/indexing caller for a fresh/untrained character.
Fixed at the accessor level (`mapp(x) ? x : ([])`) per the documented
remedy. Verified via `lpcc --batch` static compile check only (not a
live boot) as part of a large mechanical sweep; not individually
functionally re-tested live on this lib.

## 深度功能测试（2026-09-04，round three，shop + 拜师）

新角度：扬州醉仙楼购物 + 武当谷虚道长拜师。和 sibling `xkxz2` 同一份
「侠客新传」v0.1b / hell / Doing Lu 血统；`xkxz2` 2026-07-24 round two
已经走过茶馆 `buy huasheng` + `bai guxu`，这份档案的 heading 从未写过
shop/拜师，round one（2026-08-09）只做到注册+死亡复活。

### 本轮修的 bug

**`enter_world()` 无条件用 per-connection login 物件上永远过期的
`registered:0` 覆盖刚 restore 好的 user 物件（`xkxz2` Bug 2，这里原样
还在）**：`d/register/npc/shuisheng.lpc` 的 `do_decide()` 只
`me->set("registered", 1); me->save();`（`this_player()` 是 user 身体，
从不写 `link_ob`）。`cmds/usr/save.lpc` 会 `link_ob->save()` 但并不把
user 上的 flag 抄回去；只有 `quit.lpc` 才
`link_ob->set("registered", me->query("registered"))`。于是任何一次
断线/驱动重启（不走 `quit`）都会让 `data/login/f/fluffos.o` 停在
`registered:0`。下一轮 `enter_world()` 原先第 513 行是

```
user->set("registered", ob->query("registered"));
```

把已经是 1 的 user 旗标打回 0，再被送到 `REGISTER_ROOM`，屏幕上重新
出现「您还没有注册」/ `score`「还没有出生呐」。本轮开机后立刻复现：
2026-08-09 已经走完 register+born 的 `fluffos` 存档，`user.o` 仍是
`registered:0`（上次驱动重启后被这段代码洗过）。

修复与 `xkxz2` 相同：把 `registered` 当成单调旗标，任一侧为真就两边
都写成 1。档案是 CRLF，按二进制改。驱动必须重启（`logind` 开机已加载）。

现场验证：修完后重新 `register`+`decide`+品质+`wash`+`born 扬州人氏`，
`save` 后**不 `quit` 直接丢 socket**（此时磁盘上 `user.o` `registered:1`、
`login.o` 仍是 0），再 **重启驱动** 强迫走 `enter_world()` 而不是
net-dead 重连（`NET_DEAD_TIMEOUT` 是 900 秒）。重连后落地
`/d/wudang/guangchang` 武当广场，注意事项横幅是普通「半开放测试」而不
是「您还没有注册」，`score` 仍是武当派第四代弟子 / 师父谷虚道长 /
扬州人氏。`login.o` 也被 `enter_world()` 末尾的 `ob->save()` 写成 1。

### 实测过程

管理员 `fluffos` / `Mud@2026` / 中文名存档里是「水笙」。第一输入是
`Are you using BIG5 font [Y|N]?`，回 `n`。端口 40126。`env/prompt` 是
`time`（每秒刷新），脚本 idle 用 0.45s。`log_error()` 已有 `arning:`
闸门，本轮屏幕上没有编译警告倾泻。

`clone /clone/money/gold` 被拒：「你不能复制物品」。`cmds/wiz/clone.lpc`
在 wizlist `(admin)` 之外还要 `me->is_admin()`（`admin_flag == 1222` 或
`getuid() == "jjgod"`），显示「您目前的权限是：(admin)」并不能过这道
门。这是 `xkxz2` 已经记录过的 nested-condition 设计，不是 bug，不改。
城隍庙 `d/city/npc/monk.lpc` 的 `ask monk about 领钱` 实际 `give`/
`add_money` 整段注释掉（永远「来迟了」/「要钱没有」），同样是内容设计。

巫师 `call` 对 `(admin)` 开放。在醉仙楼对跑堂
`call paotang->add_money("gold", 1)` 再 `force paotang do give gold to
fluffos`，得到一两黄金，然后走普通玩家购买。`F_DEALER` 对丐帮+begging>10
会把人踢出酒馆，本轮先买再拜。

`goto /d/city/zuixianlou`，`list`：包子五十文 / 烤鸡腿八十文 / 烤鸭一两
白银又五十文 / 牛皮酒袋一两白银 / 花雕酒袋一两白银又二十文。`buy jitui`
成功（「你从跑堂那里买下了一根烤鸡腿」）。`i` 剩二十文铜钱 + 九十九两
白银（10000−80 = 9920），黄金条目消失，找零数学正确。

丐帮左全按设计关闭：`cmds/skill/apprentice.lpc` 第 7 行
`string *familys = ({ "武当派", });`，`apprentice zuo` 会得到「对不起，
这个门派还没有开放。」拜师目标是武当广场 `/d/wudang/guangchang` 的
谷虚道长（`kungfu/class/wudang/guxu.lpc`，id `guxu`）。
`apprentice guxu` 一次成功：谷虚收徒，`score`「武当派第四代弟子」、
师父谷虚道长。`attempt_apprentice` 只拒 `shen < 0`。`save.lpc` 是真正的
双 `save()`，有 60 秒节流。

驱动重启后银子/铜钱还在（`autoload` 写了 silver:99 / coin:20）；烤鸡腿
是 `F_FOOD`，不进 autoload，重启后不在身上——不是存档 bug。门派/师傅/
`registered` 都还在。

live `debug.log` 是 `libs/xkxc98sj/log/debug.log`（Boot Time Fri Sep 4
02:56:44 2026），无 `error:` / `Too deep recursion`。mudlib 自己的
`work/log/log`（`error_handler` 写入 `LOG_DIR + "log"`）只有开机编译
警告，没有本轮操作触发的运行时错误。管理员存档未提交。

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 4 line(s) in 1 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-04）— paths named in another case

The archive comes from a case-insensitive host: files are stored as `BAGUA0.lpc`, `longjing.C`, `d/SHAOLIN/`, the code names them in lower
case (`__DIR__ "bagua0"`, `"tea/longjing"`, `"/d/shaolin/..."`), so the rooms, NPCs and items behind them could not be loaded (a `.C` file is
not an `.lpc` file; KB 03 §4.5). `scripts/lpc_case_paths.py --convert --apply xkxc98sj`: 16 file(s) renamed to lower case (`.C` -> `.lpc`,
`.H` -> `.h`) and 0 path reference(s) in 0 file(s) rewritten to the new spelling; 0 skipped, 0 ambiguous. Load check of the 18 objects that were renamed, edited or name a renamed path (HEAD against the working tree, an object is the same under any spelling of its path): 2 PASS -> 2 PASS, 0 that loaded before fail now, 0 more load.

16 files moved (16 `.C`); mostly under `kungfu/skill/never-defeated` (9), `kungfu/skill/kuihua-mogong` (7). A rescan with `scripts/lpc_warnings.py xkxc98sj` is still due: the renamed files are compiled for the first time.

## 深度功能测试（§10.7，2026-10-05）— room base survives a raising NPC

`scripts/lpc_resilient_room.py --apply`: `make_inventory()` of `inherit/room/room.lpc` loads each inventory object as `if (catch(ob = new(file)) || !objectp(ob)) return 0;`. `new()` of a file that is not there returns 0 (the room just lacks that NPC), but `new()` of a file whose `create()` raises (a skill file for `set_skill()` this archive never had, a `carry_object()` item that is not there, a header that never shipped) raised inside the room and the room did not load at all. The wrong-case renames of this lib (the section above) make the NPCs behind them reachable for the first time, so a room that holds one with such a content gap would have gone from "NPC missing" to "room missing"; now it loads without that NPC, as it did before. The room base compiles and loads with the change (HEAD against the working tree). KB 03 §4.5.

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `inherit/room/room.lpc`：`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 OK，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-06）— 与 zhonghua2 同源的三处编译警告

- `include/npc/indian.lpc` 与 `masia.lpc` 共用全局名 `ma_sname`/`ma_pname`；两个头文件被同一个守护进程（`npcd` 等）一起包含时，后包含的印度名表覆盖马来名表，`generate_ma_name()` 生成的是印度名字。印度表改名 `in_sname`/`in_pname`（KB 04 §6.10）。
- `cmds/std/team/swear.lpc`：结义失败提示被多余的 `;` 截成两句，`fail` 只剩"……可惜现在有人不在，$N"，后半句"的提议只好作罢。"丢了；接回去。

验证：改动的文件和包含 `npc/indian` 的守护进程在 HEAD 与工作树分别加载（`scripts/lpc_listcheck.sh`，新进程），无回退。

## 深度功能测试（§10.7，2026-10-07）— 编译警告整理

`scripts/lpc_warnings.py xkxc98sj --fix` 加 `scripts/lpc_fix_no_effect.py --apply`（`d/tiezhang` 三个房间删去 `return` 后面的 `"\n";` 等），再用 `scripts/lpc_nitan_family_fixes.py xkxc98sj`（`natured.lpc` 的空语句 `lt[LT_MON];`、`combatd.lpc` 的空语句 `your_temp["guarding"];`），并删去 `adm/daemons/logind.lpc` 没用到的 `string ip = query_ip_number(ob);`。共改动 410 个 `.lpc`。HEAD 与工作树分别加载（新进程）：382 -> 382 通过，无回退；改过的头文件的 25 个包含者 25 -> 25 通过。
记录、未改：`clone/quest/block.lpc` 的 `STORY_DIR + "yanmen"->prompt()` 因为 `->` 比 `+` 优先，调用的是名叫 `"yanmen"` 的物件（应写 `(STORY_DIR + "yanmen")->prompt()`）；但这个文件本身有多处编译错误（未定义的 `my` 等），HEAD 起就加载不了。`d/tdh/job1/yi.lpc` 把保留字 `do` 当变量名，同样编译不过。

启动时警告 32 -> 0；新进程登录（字体选择、英文名、新人物确认）正常。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 2 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 0 个，只在 #if 分支用的声明移进分支 0 个文件；改动 2 个文件，HEAD 与工作树各载入一次无回退（2 objects; HEAD PASS 2, tree PASS 2; regress 0; newly loading 0），这些文件的警告 3 -> 1。

- 2026-10-12：`clone/misc/swmuding.lpc`（神木王鼎）自己声明了一张 `mapping insects` 虫表，与继承的 `clone/misc/muding.lpc` 的 `insects` 同名；读表的是木鼎的代码，读到的是木鼎自己的表，神木王鼎的虫表从来没用上（`Redeclaration of global variable 'insects'`）。改名 `sw_insects`，`create()` 里 `insects = sw_insects;` 交给木鼎（nitan170911、wxddym、zjdy 系同修）。HEAD 与工作树各载入一次，regress 0。

## 编译警告收尾（2026-10-13）

`scripts/toolkit_fix.sh` 一轮去掉 13 处多余继承，其余手工，能编译的文件警告清零。改动的 20 个对象在 HEAD 与工作树各载入一次：HEAD PASS 10，tree PASS 20，regress 0，新载入 10 个。

- 暗器类 10 个（`clone/weapon/feidao`、`jinhua`、`sjian`、`jin-sjian`，`d/city/bqp_obj/feibiao` 及 `npc/bqp_obj/feibiao`，桃花岛/归云庄的石子 `shizi` 等）在 `inherit THROWING;` 之外又继承 `COMBINED_ITEM`，而 `THROWING` 已经带着它：`Illegal to redefine 'nomask' function '_set'`，这些物件从没载入过，商店、NPC 给不出来。去掉多余的一行后都能载入。
- 酒楼五间（`d/city/jiulou2`、`zuixianlou2`、`d/dali/jiulou`、`d/quanzhen/jiulou2`、`d/shaolin/jiulou2`）同时继承 `ROOM` 和 `F_DEALER`，两者都有 `reset()`，驱动只用 `dealer` 的（清理过多的货物），房间自己的 `reset()` 从不运行，店小二等 `objects` 走失或被杀后不再刷新。房间里写 `void reset() { room::reset(); dealer::reset(); }`，两个都跑。
- `d/rooms/npc/obj/jia.lpc` 写明用驱动原先选的 `clean_up()`；`d/xiangyang/npc/shanzei0.lpc` 自己的 `MAX` 宏与 `globals.h` 的相同，删去。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。1 个文件 1 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）；`x op= 浮点` 先把浮点转成整数再运算（系数小于 1 时 x 直接变 0），改为 `x = to_int(x op ...)`：`/kungfu/skill/jieshou-jiushi/foguang.lpc`（`damage *=`）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。

- 2026-10-14：2 个文件因 `Type of returned value doesn't match function return type ( int vs void )` 整份不编译：声明为 `void`（或没写类型）的函数却返回值，旧驱动照样把值交给调用者。调用者要用返回值的（add_action 处理函数、命令、辅助函数）改为它实际返回的类型：`attempt_apprentice()`、`check_reply()`、`remove_effect()`。新进程比对 HEAD 与工作树：2 个对象，新增载入 2，回退 0（`scripts/lpc_fix_void_return.py`，KB 04 §6.3）。

- 2026-10-14（补）：上面改成有返回值的函数里残留的空 `return;` 改为 `return 0;`（值不变，消除 `Non-void functions must return a value`）。

- 2026-10-14：2 个文件用了颜色宏（`HIW`、`NOR`）却没有 `#include <ansi.h>`（首个错误 `syntax error, unexpected L_STRING`）；开头补上；1 个文件的函数声明为 `int`（或 `void`）却返回字符串、对象（`int query_seal() { return "…"; }`），旧驱动照样把值交给调用者；改为实际返回的类型（`scripts/lpc_fix_void_return.py`）（KB 04 §6.1、§6.3）。新编译出来的文件露出的警告一并清掉（删去未用局部变量，有返回值函数里的空 `return;` 改为 `return 0;`）。新进程比对 HEAD 与工作树：3 个对象，新增载入 3，回退 0。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。4 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。

## family 映射（补）（2026-10-15）

`mapping fam = (mapping)me->query("family");`（带类型转换的写法）同样直接取下标，8 处补上 `if (!mapp(fam)) fam = ([ ]);`。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。8 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。


## `->query_(` 笔误（2026-10-15，KB 06 §7.245）

调用不存在的函数 `query_`，call_other 静默返回 0，相关判断永远按 0 计算。改为 `->query(`：`jinshemiji`、`jsmj`。

## `find_player()` 只认在世界里的身体（2026-10-15，KB 07 §8.26）

simul_efun 的 `filter_player()` 加上 `environment(ob)`：注册中途断线留下的、不在任何房间的身体不再被当成玩家，两个以上时 `find_player()` 不会再报 `The player(<id>) has existed in the world.`（wllz3 实测过的问题）。本库若注册流程不会留下带玩家 uid 的身体，这一改动不改变行为。

## 空手使用兵器绝招（2026-10-15，KB 06 §7.246）

`perform` 指令允许直接点名招式（如 `perform stick.ban`），这些绝招读了 `me->query_temp("weapon")` 却从不检查，空手时 `weapon->name()` 报错（有的已先扣了内力）。在赋值后补 `if (!objectp(weapon)) return notify_fail("你必须手持兵器才能使用这一招。\n");`（`scripts/lpc_fix_perform_weapon.py`）：`dagou-bang/ban`、`dagou-bang/sansha`。

## 独孤九剑列不出剑法目录（2026-10-15）

`lonely-sword` 的 `query_action()` 用 `get_dir("/kungfu/skill/*.lpc")` 列出所有剑法，再随机借一招；但 `/kungfu` 下对象的 euid 是 `Domain`，安全守护（securityd 的默认规则只许 ADM/ARC/WIZ 读）不给它列目录，`get_dir()` 返回 0，`filter_array(0, ...)` 每次出招都报错。改为：列不出目录时借出手者自己会的剑法（找不到技能文件的跳过），一门也没有就用兵器本身的招式，再没有就用 weapond 的「刺」。目前这门功夫没有实际入口：唯一会它的 NPC 是黑木崖的 `npc/linghu`（令狐冲），没有房间放置他，而且他 `set_skill()` 了本库没有的 `feiyan-huixiang`、`huashan-sword`，一载入就报错。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`jinhse-jianfa`→`jinshe-jianfa`（`/d/jinshe/skill/jinshe`）；`xixing-dafa`→`xixin-dafa`（`qiantian-yiyang`）；`yinyun_ziqi`→`yinyun-ziqi`（`yinyun-ziqi/cure`）。

## family 映射内联取下标（2026-10-15，KB 05 §7.30）

`ob->query("family")["master_name"]`、`me->query("family")["family_name"]`（泥潭式为 `query("family", ob)[...]`）直接对门派映射取下标：没有门派的人（新玩家、叛师者、大多数 NPC）在 NPC 的打招呼和问话、绝招的门派判断、房间的 `valid_leave` 里报 `Value being indexed is zero`，而不是得到拒绝。8 处（7 个文件）改为 dbase 路径查询 `query("family/master_name")`：有门派时值相同，没有时得 0；原有的判断照常生效（`scripts/lpc_fix_family_index.py`）。给映射赋值的写法未动。


## 存档读不出来：字符串里的换行、空行（2026-10-15，KB 03 §4.4）

`adm/daemons/securd.o`、`data/board/player_b.o`、`data/emoted.o`、`data/newsd.o`：字符串里有原样的换行（`save_object()` 存成 `\r`，`restore_object()` 逐行读，原样的换行让字符串收不了尾），或有空行（`Illegal file format`），读档的对象（留言板、NPC、玩家）从空白开始。换行改写成 `\r`、删去空行（`scripts/lpc_save_encoding.py --from-raw`），驱动核对全部能读回（`scripts/lpc_save_restore_check.py`）。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

9 个文件、18 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/d/thd/obj/biyuxiao.lpc`、`/d/xueshan/obj/y-jiasha`、`/d/dali/obj/obj/panguanbi`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 1 个，改后 6 个（5 个原来载入不了），没有退步；其余 3 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## NPC 带着不存在的物品：simul_efun `unew()` 报错（2026-10-18，KB 06 §7.73）

`adm/simul_efun/object.lpc` 的 `unew(str)`（带 `unique` 判断的 `new()`）先 `ob = new(str)`，紧接着就读 `ob->query("unique")`。物品文件不存在时 `new()` 返回 0，读 0 的属性报 `Bad argument 1 to EFUN call_other()`，从 `carry_object()` 一路带出去：`create()` 里带着缺失物品的 NPC 载入不了（jh2006 的苗疆何铁手一类，该有 NPC 的房间少了人）。读属性之前补 `if (!ob) return ob;`（`int i = ob->query("unique"), j, k;` 拆成声明和赋值两句），缺的物品跳过，NPC 照常载入（`scripts/lpc_guard_carry_object.py --unew`）。载入检查：改动的文件改前能载入 3 个，改后 8 个，没有退步。

## 补回丢掉的基类宏（2026-10-18，KB 04 §6.13）

`inherit F_XXX;` 里的宏本库任何头文件都没有定义，报 `syntax error, unexpected L_IDENTIFIER, expecting L_STRING or '('`，整个对象载入不了；宏指向的基类文件本库其实有，别的库都把这个宏定义成同一个路径。在全局头文件 `include/globals.h` 里补上：`F_COAGENT` → `/feature/coagent`（1 个文件）。（`scripts/lpc_restore_macros.py`）改后用 `lpcc` 逐个载入这些对象：1 个里 1 个通过。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 36 个对象设了本库没有文件的武功（82 个名字，最多的是 `tianlong-shengong`、`medical`、`zixia-shengong`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：30 个里 11 个通过，其余 19 个停在别的错误上（`adm/daemons/story/anthem`：NOLOAD；`adm/daemons/story/baguadao`：NOLOAD……）。（`scripts/lpc_guard_set_skill.py`）

## 通向不存在房间的出口，按对面房间的回头出口改正（2026-10-18，KB 06 §7.257）

房间出口 `"west": __DIR__"xxx"` 指向的文件本库没有，玩家走过去就被卡住（笔误、改过名的房间，或者没带进档案的编号房间）。对面的房间存在、并且它相反方向的出口正好指回这个房间，说明出口原本就是通向它：`/d/heimuya/houting` 的 `northdown`：`yuemen` → `yunmen`；`/d/xiangyang/kedian2` 的 `down`：`tianxianglou` → `kedian`。改动后每个出口都能解析到本库的文件（`scripts/lpc_fix_dead_exits.py`；目标在运行时本来就能载入的库——虚拟房间——不动）。

## 补回本库没有的基类文件（2026-10-18，KB 04 §6.15）

下面这些基类本库没有，继承它们的对象（房间、NPC、物品）整批载入不了（`inherit XXX;` 的宏没定义，或者 `inherit "/std/…";` 的文件不在）。同系的库里有同名文件，两库有大量逐字节相同的文件（亲缘关系），所以从那边原样拷来，缺的宏补进全局头文件：`/inherit/char/punisher`←zjdywzb，18 个对象继承它，抽样 10/10 载入。每个基类补回后单独载入、再抽样载入使用它的对象，基类载不进来或者一个用户也载不进来的就撤掉（本库撤掉了它们，不再补）。（`scripts/lpc_restore_bases.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 49 处、47 个文件：`shaolin-shnfa`→`shaolin-shenfa`（19 处）、`kunlun-shnfa`→`kunlun-shenfa`（15 处）、`huashen-shenfa`→`huashan-shenfa`（5 处）、`lognxiang-gong`→`longxiang-gong`（4 处）、`yunv-shenfa`→`yunu-shenfa`（2 处）、`weiituo-gun`→`weituo-gun`（1 处）、`shenhuo-shengong`→`shenghuo-shengong`（1 处）、`yunv-xinjing`→`yunu-xinjing`（1 处）等共 9 个名字。（`scripts/lpc_fix_skill_names.py`）

## 调用了父类没有的函数的对象（2026-10-19，KB 06 §7.259）

`::create();`、`::init();`、`return ::buy_object(who, item);` 这类调用写的是父类里有这个函数的版本；本库的父类没有，旧驱动把它当空操作（返回 0），现在的驱动在编译时就报 `Unable to find the inherited function`，整个对象载入不了。单独成句的调用删掉，`return ::f(...)` 改成 `return 0;`（void 函数里是 `return;`），与旧驱动的行为一致。共 2 处、2 个文件：`::init()`（2 处）。只改了出错原因全是这一类的文件；还带着别的错误（多半是父类本身没了）的文件没动，等父类补回后再看。（`scripts/lpc_fix_dangling_super.py`）

## feature/damage.lpc 丢了 set_ghost()（2026-10-19，KB 06 §7.262）

`feature/damage.lpc` 里有 `int ghost` 和 `is_ghost()`，没有 `set_ghost(int i)`；木人、狼等 NPC 在 `create()` 里调用它，整个 NPC 报 `Undefined function set_ghost` 载入不了。从 xkx100 补回这一行函数，受益 NPC 10 个：`d/shaolin/npc/muren_fighter1`、`d/shaolin/npc/muren_fighter2`、`d/shaolin/npc/muren_fighter3`。（`scripts/lpc_transplant_function.py`）

## 全局头文件丢了 2 个宏（2026-10-19，KB 04 §6.16）

`/include/globals.h` 里没有定义 `MEDICINE(x)`、`CHAT_ROOM`，用到它们的物件（名单里 2 个）编译时报 `Undefined variable`/`Undefined function`，整个物件载入不了（编译器在第一个未定义的名字上停下，后面的错误和警告都看不到）。同系的库在各自的头文件里都有这几行：照其中和本库共有文件最多的那个库，原样补到 `/include/globals.h` 最后一个 `#define` 之后，宏体里出现的路径在本库里都存在。补完后名单里有 1 个载入，其余还差别的东西。（`scripts/lpc_restore_defines.py`）

## laozhe 的 command("give yancao to", me)（2026-10-19，KB 06 §7.266）

`d/heimuya/npc/laozhe.lpc`（黑木崖的老者）的 `init()` 里写着 `command("give yancao to", me);`，`command()` 只收一个字符串，驱动报 `Too many arguments to 'command'`，整个 NPC 载入不了。照 cctx、fys 等库已经改好的写法，改成 `command("give yancao to " + ob->query("id"));`（`ob` 是刚进房间的玩家）。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 补回本库没有的基类文件，第二轮（2026-10-19，KB 04 §6.15、§6.18）

宏有定义、基类文件却不在档案里：继承它的对象载入时报 `Inherited file '…' does not exist!`，编译扫描看不到这一类（`scripts/lpc_missing_inherits.py` 能列出）。同系的库里有同一个文件，原样拷来（`scripts/lpc_restore_bases.py`）；基类和继承它的对象 include 而本库没有的头文件一起带来。每个基类补回后单独载入，再载入使用它的对象，载不进来、或一个用户也载不进来的撤掉了。

- `/inherit/item/medical-book`（宏 `MEDICAL_BOOK`）←zjdywzb：3/3 个继承它的对象载入，同时带来头文件 `/include/medical.h`
- `/inherit/misc/_xiao`←zjdywzb：1/1 个继承它的对象载入

逐个与 HEAD 对比载入，没有退步。

## 旧驱动的类型宽松：缺省参数、无类型形参、数组初始化、`class` 变量（2026-10-19，KB 04 §6.19、§6.20）

原来的 MudOS 把调用少传的参数补 0、把没写类型的形参当 `mixed`、不检查变量的声明类型与初始值，也允许变量叫 `class`；这个驱动在编译时全部拒绝，整个物件载入失败。修了 4 个文件：`/clone/npc/luohantang-shouzuo.lpc`、`/clone/user/loaduser.lpc`、`/d/thd/npc/loaduser.lpc`、`/inherit/char/waiter.lpc`（`scripts/lpc_round_files.py` 的修复轮：调用处补写 `0`、无类型形参补 `mixed`、`string X = ({...})` 补星号、void 函数的返回值，以及 `class` 变量改名 `pick_class`）。逐个文件在 HEAD 和改后载入对比：这些文件里 4 个原来载入失败、现在载入，没有退步。

## 比较链的人工修正（2026-10-20，KB 06 §7.282）

`d/mingjiao/bhd/xbkai.lpc`：爬岩石的判断 `arg != "yanshi" || arg != "岩石"` 永远为真，爬什么词都爬上岩石；本意是参数是 yanshi 或“岩石”，改成 `==` 和 `||`。

## `member_array('/', str)` 改为 `strsrch(str, "/")`：字符字面量的 member_array 按字节搜索（2026-10-20，KB 06 §7.283）

`member_array('/', str)` 里的 `'/'` 是整数，驱动按 UTF-8 **字节**搜索，返回字节偏移（带第三个参数时起点也是字节）；最新的 FluffOS（923cdbc0）在字符串里有非 ASCII 文字时，对每个调用点警告一次（`Warning: member_array(int, string) searches BYTES`）。而 `str[0..idx-1]` 按字符切，中文字符串会在错误的位置截断。改为 `strsrch(str, "/")`（找不到同样返回 -1，按字符计数；`scripts/lpc_fix_member_array_char.py`，JSON 编码器等少数几处手改）。改动：`/cmds/adm/sameip.lpc`（1 处）、`/inherit/room/vrm_server.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 12 处）。改动：`/cmds/skill/quanjia.lpc`（1 处）、`/d/mingjiao/npc/zhangwuji.lpc`（1 处）、`/d/rooms/npc/yy18q9.lpc`（1 处）、`/kungfu/class/emei/fengling.lpc`（1 处）、`/kungfu/skill/meinu-quanfa.lpc`（1 处）、`/kungfu/skill/qiankun-danuoyi.lpc`（7 处）。

## `socket` / `dumpsocket` 指令：`dump_socket_status()` 驱动里没有（2026-10-20，KB 06 §7.291）

这些巫师指令 `write(dump_socket_status());`，MudOS 的 efun 在 FluffOS 里不存在，指令编译不过。在模拟 efun 文件里补了 `dump_socket_status()`：用 `socket_status()` 排出同样的表（没有 sockets 包的构建，比如 WASM，只有表头；`scripts/lpc_add_sefun.py dump_socket_status`）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/single/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## 目录读出后的后缀截取宽度（2026-10-20，KB 06 §7.296）

`.c` 改名成 `.lpc` 之后，`get_dir("*.lpc")` 读出的文件名还按两个字符截取（`$1[0..<3]`）：`baguadao.lpc` 变成 `baguadao.l`，用它拼出的路径加载不到对象（故事、战场、事件、帮助、自造物品数据、召唤列表等）。改成 `[0..<5]`（`scripts/lpc_fix_getdir_strip.py`）。改动：`/adm/daemons/storyd.lpc`（1 处）。

## sefun `cat()`：缺文件时 `write(0)` 报错（2026-10-20，KB 06 §7.297）

`void cat(string file) { write(read_file(file)); }`：文件不存在（压缩包没带的欢迎/公告文件，或只有运行中的 mud 才会写的日志）时 `read_file()` 回 0，`write(0)` 在本驱动里报 `Bad argument 1 to receive()`，调用者（登录对话、`cat` 指令）被中断；老驱动什么也不打印。改成 `write(read_file(file) || "");`（`scripts/lpc_fix_cat_unchecked.py`）。改动：`/adm/simul_efun/file.lpc`。

## `get_config(__MUD_PORT__)` 经旧版 `runtime_config.h` 得到字符串（2026-10-20，KB 06 §7.302）

本库的 `include/runtime_config.h` 是老 MudOS 的编号（整数设置从 15 起，本驱动从 256 起），`get_config(__MUD_PORT__)` 读到的是另一项设置（字符串），`(int)` 又只是编译期标注，于是 `socket_bind(fd, LOCAL_PORT())` 报 `Bad argument 2 to socket_bind()`，版本守护进程 `port = get_config(__MUD_PORT__) + VERSION_PORT` 是字符串相加。头文件自己的注释写明 `get_config(__MUD_PORT__) == __PORT__`，所以代码里的这个调用（连同外面的 `(int)` / `to_int()`）改成了驱动的预定义 `__PORT__`（`scripts/lpc_fix_mud_port.py`）。改动：`/include/getconfig.h`（1 处）。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库现有的 NPC 文件里没有字面写成空 `chat_msg` 的（扫描只认 `set("chat_msg", ({ }))`）；守卫挡的是运行时才为空的列表和以后新增的 NPC。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/d/rooms/npc/npc.lpc`、`/inherit/char/npc.lpc`（共 2 个文件）。

## 不带参数的指令对 0 调用 efun：不在 wiz / adm 目录里的指令（2026-10-21，KB 06 §7.336）

指令敲成不带参数时，驱动把 0 传给字符串参数；下面的指令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`。它们在 `cmds/std`、`cmds/usr`、`cmds/bos`、`cmds/app` 这类目录里，上一轮的扫描只看巫师目录。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py --all-dirs` 在第一处使用参数的语句前加守卫：文件自带 `int help(object me)` 的，守卫是 `if (!arg) return help(me);`（`help()` 定义在 `main()` 之后的 1 个文件补了原型 `int help(object me);`，否则编译报 `Undefined function help`）；没有 `help()` 的是 `return notify_fail("…\n");`。改动（1 个文件，括号里是接住 0 的 efun）：`/cmds/std/fill.lpc`（`present`）。加载检查 HEAD 与工作树对照，没有退步。

## 任务分配 `quest`：按顺序找目标的备用循环用了 `living[j]`（2026-10-21，KB 06 §7.347）

`/feature/quest.lpc`：先随机挑目标（`j = random(sizeof(living))`），挑不中再“按顺序找”：`for (i = 0; i < sizeof(living); i++) if (check(living[j], ...)) { target = living[j]; break; }`。下标写成了 `j`（上一个循环最后一次的随机下标），备用循环把同一个 NPC 检查 `sizeof(living)` 遍，世界小的时候任务就分不出去。xkx100 的原文就是这样，派生库照抄。改成 `living[i]`。

## 昆仑派 `banshuxian`、`hetaichong`、血刀门 `laozu` 的 `ask_me()`：`ob` 从来没赋值（2026-10-21，KB 06 §7.346）

`/kungfu/class/kunlun/banshuxian.lpc`、`/kungfu/class/kunlun/hetaichong.lpc`、`/kungfu/class/xueshan/laozu.lpc`：`object ob;` 之后直接 `ob->query("gender")` / `ob->query_skill(..)`，根上的 xkx100 在声明后有一句 `ob = this_player();`，这个派生库把它丢了，`ask <师傅> about <秘籍>` 一律抛 `call_other() ... Got: int(0)`。补上这句。

## 苗疆山谷 `shangu1`：第二条蛇写成了 `jinshe = new(..yinshe)`（2026-10-21，KB 06 §7.346）

烧灵芝兰（`do_shao`）引出两条蛇：`jinshe = new(__DIR__ "npc/jinshe"); jinshe = new(__DIR__ "npc/yinshe");`，第二句把第一条覆盖了，`yinshe` 一直是 0，后面的 `yinshe->move(...)` 抛错。第二句改成 `yinshe = new(...)`（sje、jym 的同一份文件是对的）。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 29 条注册（20 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/adm/npc/mdc.lpc`（`do_all`、`do_link`、`do_new`、`do_save`等）、`/adm/npc/referee.lpc`（`do_halt`）、`/d/city/leitai12.lpc`（`do_action`）、`/d/city/pinqiting.lpc`（`do_pass`、`do_resign`）、`/d/dali/anbian.lpc`（`do_tiao`）、`/d/dali/muwu1.lpc`（`do_tiao`）、`/d/dali/npc/duan2.lpc`（`do_vendor_list`）、`/d/dali/shanlin-6.lpc`（`do_tiao`）、`/d/gumu/gmqs.lpc`（`do_play`）、`/d/jinshe/husun1.lpc`（`do_pa`） 等共 20 个文件。最多的函数名：`do_tiao` 3 处、`do_strike` 3 处、`do_halt` 2 处、`do_all` 1 处、`do_link` 1 处。没有动（读过）：`/clone/misc/bargain.lpc` 的 `do_sign`（对象本身编译不过，登记留着，等对象能加载再处理）。

## 对象路径里的 `..`：`new(__DIR__ "../obj/x")` 报 `Read access denied`（2026-10-22，KB 06 §7.351）

`__DIR__` 是当前文件所在目录（带结尾斜杠），`__DIR__ "../obj/x"` 就是 `/d/zhiye/npc/../obj/x`；驱动的 `legal_path()` 不接受带 `..` 的路径，`new()` / `load_object()` 直接抛 `*Read access denied.`（实测，`find_object()` 对它答 0）。这个库的 NPC / 房间基类不先把路径规范化，调用它们的 NPC 在 `create()` 里就失败，克隆不出来（房间的 `objects` 表悄悄少了这些 NPC）。改成规范化后的绝对路径（`scripts/lpc_fix_dotdot_dir.py`）：`/d/dali/npc/zhang.lpc`（`__DIR__ "../obj/hammer"` → `"/d/dali/obj/hammer"`）, `/d/dali/npc/zhang.lpc`（`__DIR__ "../obj/hammer"` → `"/d/dali/obj/hammer"`）, `/d/wudang/npc/xiaocui.lpc`（`__DIR__ "../obj/nuerxiang"` → `"/d/wudang/obj/nuerxiang"`）, `/d/xiaoyao/npc/qingyun.lpc`（`__DIR__ "../obj/cloth"` → `"/d/xiaoyao/obj/cloth"`） 等共 5 处。

## 缺失物品的 `new()` / `carry_object()` 调用链加了保护（2026-10-22，KB 06 §7.73 补充）

`new(路径)->move(...);` / `carry_object(宏("x"))->wear();` 这类语句，路径指向的文件在这个压缩包里没有：`new()` 返回 0，`->move()` 在 0 上报 `Bad argument 1 to EFUN call_other()`。在 `create()` 里这个对象永远加载不了，在 `reset()` 里第一个缺失物品之后的刷新每次 reset 都被跳过。1 个文件里 1 处（`new`）改成 `{ object new_ob = new(路径); if (new_ob) new_ob->move(...); }`（`scripts/lpc_guard_carry_object.py --new`：路径按这个文件自己看到的宏解析，宏名冲突、虚拟对象路径一律跳过）。 对这 1 个改动文件做加载检查（HEAD 与工作区对比）：HEAD 能加载 1 个，现在 1 个（新增可加载 0 个，回归 0 个）。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 还剩 1 个函数没有补（inquiry 1）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/d/tdh/job1/yi.lpc`:`ask_ok`。 另有 2 处函数体被作者整段注释掉（指针没跟着删），是有意关掉的，没动。

## 运行期目录 `log/nosave` 不存在，写日志的 `write_file()` 直接报错（2026-10-22，KB 03 §4.3 补充）

这个库的 31 个文件里有 51 处 `write_file("/log/nosave/...")` / `log_file("nosave/...")`（`static` 改 `nosave` 时连字符串里的日志路径一起改了，原来是 `log/static/`）：`nosave/security`、`nosave/item`、`nosave/CRASHES` 等。压缩包和站点包里没有这个目录，`write_file()` 在目录不存在时抛 `*Wrong permissions for opening file /log/nosave/... for append. "No such file or directory"`，调用它的函数（杀人记录、重启记录、`call` 日志……）当场中断。把 `log/nosave` 记进 `scripts/wasm_keep_dirs.txt`（站点和 pristine 树都按它建空目录）；没有把字符串改回 `static`。证明（`scripts/lpcc_eval.py`，`catch(write_file("/log/nosave/ZZTEST", ...))`，fqyy2 / hy5 / bmxkx2001 的新进程）：补目录前报上面的错误，补后写成功。

## 读不到的留言板：`"/clone/board/x"->foo();` 在 `create()` 里报错（2026-10-22，KB 06 §7.357）

xkx 系的房间在 `setup()` 之后写 `"/clone/board/gaibang_r"->foo();` 来加载留言板（`foo()` 本来就没有定义，只为了触发加载）。这个库没有这个文件，`call_other()` 报 `*call_other() couldn't find object '/clone/board/gaibang_r'`，对象留在内存里、`load_object()` 却抛错：玩家第一次走进房间就看到错误，写在 `create()` 中间的还会切掉后半段。`scripts/lpc_fix_missing_foo.py` 把 1 条单独成行的语句（`/clone/board/xiaoyao_b`；`/d/xiaoyao/qingcaop.lpc`）注释掉并写明原因（别的房间里同样的语句本来就是作者自己注释掉的）。证明和 45 个库的整体加载检查见 KB 06 §7.357。

## `log/` 下的日志子目录没有人建：写日志的 `write_file()` / `log_file()` 报错（2026-10-22，KB 06 §7.358）

这个库的代码往 `log/` 的 2 个子目录写日志：`log/cmds`（`adm/npc/dan.lpc`）、`log/user`（`adm/daemons/examined.lpc`）。压缩包、`git clone` 和站点包里都没有这些目录（本地启动没有写过它们，`gen_keep_dirs.py` 没记），`write_file()` 对不存在的目录抛 `*Wrong permissions for opening file /log/dlog/money for append. "No such file or directory"`，调用它的函数在写日志那一行中断，后面的奖励、标志、步骤都没有执行。本库的 `log_file()` 是 `write_file(LOG_DIR + file, text)`，目录不存在就抛同样的错误（实测）。把 `log/cmds`、`log/user` 记进 `scripts/wasm_keep_dirs.txt`（`scripts/lpc_keep_log_dirs.py`；站点和 pristine 树按它建空目录）。证明（`scripts/lpcc_eval.py`，在 `/adm/daemons` 这类目录下的求值对象里写 `/log/zzdirprobe/...`，新进程）见 KB 06 §7.358 的实测表。

## `(: 函数名 :)` 指针指向本库没有的函数：只含这个指针的行加了注释（2026-10-22，KB 06 §7.355 补充）

`inquiry` / `item_desc` / `chat_msg*` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：用到时（`ask`、`look`、NPC 闲聊）驱动抛 `*Undefined lfun pointer called: 函数名`，这一拍心跳的后半段被跳过。这些函数没有可以补回的来源（别的库同一路径的文件里没有，或者它还要用本库没有的东西），所以 3 个文件里 3 行只含这个指针的行（`"比武大会": (: ask_me :),` `"以气御剑": (: ask_me :),` `"到了" : (: ask_ok :),`）加了注释，原文保留并写明原因，这一项当作没有这个话题 / 物品 / 闲聊条目（`scripts/lpc_fix_dangling_lfun.py`；`#include` 的文件在库里缺失的对象、指针不在整行上的写法没动）。 前提（`function_exists()`）和加载检查（HEAD 与工作区对比，本库改动的 `.lpc` 文件）的结果见 KB 06 §7.355：没有一个回归。

## 汉字按字节切片的老写法没有换成按字符：改法名 `"澄" + name[2..3]`、辈分判断 `name[0..1] == "澄"` 等 49 处（2026-10-22，KB 06 §7.360）

原档按字节算字符串区间（一个汉字 2 字节）：`name[2..3]` 是名字的第二个字，`name[0..1] == "澄"` 问名字是不是以「澄」开头。转成 UTF-8 之后，这个驱动的区间和 `strlen()` 都按字符算（`strlen("澄观")` 是 2，`"澄观"[0..1]` 是两个字），老算术原样留着、意思全变：拜入少林 / 武当 / 峨嵋等派的玩家被改成错误的法名（二字名 `张三` 变成一个字的 `澄`，更长的名字取到第三个字）；各派掌门的辈分判断（`name[0..1] == "澄"`）永远不成立；NPC 的称呼和提示里取到两个字而不是一个字。

本库 49 处（36 个文件）：拼名字的赋值 29 处、与汉字常量比较 18 处、对切片赋值 1 处、`to_chinese()[..]` 1 处。例：`old_name[2..3]` → `old_name[1..1]`（`/d/dali/npc/rong.lpc:70`）；`name[2..3]` → `name[1..1]`（`/d/job/obj/h1.lpc:284`）；`name[0..1]` → `name[0..0]`（`/d/mr/npc/bo.h:17`）。`scripts/lpc_fix_gbk_slice.py` 把下标按字符重算（社区的 UTF-8 版 `xkx100utf8` 里就是同样的写法，作对照）；没有改的：截断（`name = name[0..7]`，现在最多 8 个字，只是放宽）、ASCII 的区间（`fname[0..3] == "room"`、`ctime(time())[4..19]`）和上下文看不出是汉字的区间。证明（`scripts/lpcc_eval.py`，bixiecanyang；其余各库是同一份文本）：让澄字辈掌门 `attempt_apprentice()` 一个名叫「张三」的访客，HEAD 的法名是 `慧`，改后是 `慧三`；抽样 28 个库的 HEAD / 工作树加载对比 0 退步。工具不幂等（`[0..3]` 折半得 `[0..1]`，又是对齐区间），改过的文件记在 `scripts/gbk_slice_converted.txt`，不要重跑。

## 长度检查按字节写，旁边的提示按汉字写：2 处（2026-10-22，KB 06 §7.362）

老档的 `strlen()` 数字节（一个汉字 2 字节），转成 UTF-8 后它数字符：提示写「必须是 2 到 6 个中文字」的检查还是 `strlen(name) < 4 || strlen(name) > 12`，于是两三个字的房名、帮会名、群名、聊天室名、称号被提示自己说允许的那句话拒绝，上限却是提示的两倍；留言板的标题检查 `i < 4 || i > 24 || i % 2` 还会拒绝所有奇数个字的标题（`post 你好吗`）。本库 2 处（1 个文件）：`if ((strlen(name) < 4) || (strlen(name) > 12)) {`（`/adm/npc/luban.lpc:1766`）。`scripts/lpc_fix_strlen_gate.py` 以提示为准：条件里每个 `strlen` 门槛都恰是提示所说数字的两倍才折半，存长度的变量（`i = strlen(arg);`）的门槛和 `|| i % 2` 奇偶项、其后循环的 `i % 2 == 0 &&` 一并处理；提示里有英文 / 字母 / 字节的不动。证明（`scripts/lpcc_eval.py`，bxsj 的留言板，求值对象继承 NPC 并重写 `edit()` 记录调用，`command("post 标题")`）：HEAD 拒绝「你好」和「你好吗」、放行 23 个字的标题；改后接受前两个、拒绝第三个；shenmo 的 `named.lpc invalid_new_name("张三")`：HEAD 回 `名字只能是2-4个中文字。`，改后回 0。抽样 24 + 15 个库的 HEAD / 工作树加载对比 0 退步。

## 按字节写的汉字循环、茶馆猜诗和同盟频道标题（2026-10-23，KB 06 §7.363）

老档按字节做「一个汉字」：`while (i--) if (i % 2 == 0 && !is_chinese(name[i..<0]))` 只检查偶数下标，奇数位上的拉丁字母（`张a`）会过；茶馆猜诗 `mixup()` 用 `strlen(str)/2` 再 `j=j+j`、`str[k..k+1]` 交换两字节；泥潭系 `channeld` 的 `switch (strlen(fname)) case 4/6/8/10` 和 `strlen(family)==4/6` 按字节长度给同盟 / 门派名加空格。本驱动的 `strlen()` 和区间都按字符算。`scripts/lpc_fix_byte_char.py`：去掉奇偶项、把区间改成 `name[i..i]`，按字符重写 `mixup()` 并把 `strlen(first)>=14` 折成 7，频道标题的 case / 门派长度改成字符数（对照 aoxiangtianji）。本库 `channeld` 同盟 / 门派标题 1 个文件。证明（`scripts/lpcc_eval.py`）：sjplii 的 `check_legal_name` 在 HEAD 接受「张a」、改后拒绝，两边都接受「张三」；xkx100 的 `clubpoem->mixup("离离原上草")` 得到「离离原草上」（真交换汉字）；nitan_san 两字同盟名得到 `【 兄  弟 】`。关键对象加载通过。

## 血条 / 表情标题按字节算显示宽度（2026-10-23，KB 06 §7.365）

老档把汉字当两字节：`bar_string[0..(val * N / max) * 2 - 1]` 把「格数」换成字节下标，半格血条在本驱动（按字符算区间）上会整条画满；巫师表情 `edemote` 的 `repeat_string("─", 13 - (strlen(emotion) / 2))` 也会少减汉字宽度。`scripts/lpc_fix_display_pad.py`：去掉 CJK 血条 / 空白条上的 `* 2`（`jings`/`qis` 赋值和 `blank_string3[0..(23-a)]` 的 23→11 一并改），表情标题去掉 `/ 2`；ASCII 空格的 `none_string` / `empty_string` 仍保留 `* 2`（一格两个空格）。本库 2 处（1 个文件）。证明（`lpcc_eval.py` hhsj）：`tribar_graph(6,9,12)` 在 HEAD 画出整条 12 个■，改后为 6 个■+3 个□；麻将 `strlen(tempB)/2` 是两字符牌码，未改。


## 中文名 / 验证码仍按 GBK 取「两字节一字」（2026-10-23，KB 06 §7.373）

`pname = pname[(random(sizeof(pname)) & 0xFFFE)..<1]; pname = pname[0..1];` 在按字符计下标时会取出两个汉字。`scripts/lpc_fix_pname_slice.py` 去掉掩码并把收尾改成 `[0..0]`（`pname`/`pname2`/`sec_name`/`str`/`str1`）。本库 4 处。证明：nt1 生成名长度 2–4；HEAD 常见 3–5。

## 天地会义士 yi 无法加载（2026-10-27，KB 04 §6.25 Also）

`d/tdh/job1/yi.lpc`：保留字 `int do`（驱动期望 `while`）、`query_temp("tdhbh_qiekou_ok)` 缺引号、未声明 `me`、第二个 `void init`、以及无引号中文的残缺 `do_say`。同目录手足 `yis.lpc` 是干净重写（inquiry 口令、`d` 非 `do`、`me = this_object()`、`ask_ok` / `ask_qiekou_*`）。用 `yis` 的字节覆盖 `yi`（xkxz2 / xkxc98sj 两份相同）。证明：HEAD 加载失败；改后加载成功。

## skill 基类补 F_SSERVER（2026-10-27，KB 04 §6.16 Also）

`inherit/skill/skill` 只 `inherit F_CLEAN_UP`，`yunu-jianfa` / `zhemei-shou` / `xianglong-zhang` / `xiaohun-zhang` / `baituo-shezhang` 调用 `offensive_target` 未定义。改为 `inherit F_SSERVER`（同 syxjl / 书剑手足）。证明：HEAD yunu-jianfa 失败；改后五件均加载。

## 深度功能测试（2026-10-27，§6.25 one-arg message_vision）

`message_vision("…")` 补第二参（`me` / `TP` / `this_player()`）。


## 深度功能测试（2026-10-27，§6.10 未知 pragma save_binary/optimize）

删除本库中 FluffOS 不认的 `#pragma save_binary` / `#pragma optimize…` 行。


## 深度功能测试（2026-10-27，§6.10 注释掉的 pragma 块）

`newsd.lpc` 里未闭合的 `/*#pragma optimize…save_binary*/` 整块去掉（原先已被注释，无行为变化）。对象可加载。
