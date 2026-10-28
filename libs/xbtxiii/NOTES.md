
## WASM 修复摘要（迁移自 meta.json 的 group_note）

按它自己的说明是真正的 1997-2001 年代 mudlib（一个"风云"衍生分支）；以 4 个分卷 zip（XB.ZIP.1-4）形式提供，需要二进制拼接，内部是 12 个按目录拆分的嵌套 tar.gz，而不是扁平目录树——转档前已经拼接解压；启动干净，零修复。完整 WASM 修复：修复了 logind.lpc 的 make_body() 里 seteuid(getuid()) 把 euid 重置掉的 bug；修复了 check_legal_name() 过时的 GBK 字节长度界限；给 securityd.lpc 的 get_status() 加上了防御性保护；这份档案里完全没有 band.lpc（logind.lpc 从未引用过 BAN_D，所以没有什么可保护的）。两个依赖 socket 的精灵编译失败，各自独立破坏了游戏的不同部分：adm/daemons/network/dns_master.lpc（跨服 intermud UDP，因为开机流程间接碰到它，破坏了每一次连线的登录）和 adm/daemons/network/smtp.lpc（原始 SMTP 发信，破坏了 natured.lpc 的周期性检查）——都按 AGENTS.md §7.52 掏空成 no-op。另外发现并修复了：一个缺失的 /topten/ 目录导致 toptend.lpc 在每次进入游戏世界时存档崩溃（已 mkdir -p 补上）；cmds/usr/score.lpc 对 EXPLORE_D->query_total_explore() 做除法没有保护，而这个值在任何探索数据被扫描之前合法地是 0，导致全新安装下每一次 score 指令都崩溃（已用三元运算符保护）。注册流程到进入游戏世界、look/score/quit、管理员权限识别都已干净验证。注意注册流程既包含职业选择（enchanter 魔法师/fighter 武士，英文拼写）加上对这个选择的 y/n 确认，还有一个正式起始区域之前的新手教程房间。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 22 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（§10.7，2026-08-08）

WASM 阶段和 §7.86 扫描都只做过编译检查/浅层注册测试，没有真正玩过。这次用原生驱动（`build-debug/src/driver`）通过 `scripts/tmux_mud.sh` 完整走了一遍：注册（含中文名"风灵"、密码、性别、email、A-L 属性类别、天赋确认、fighter 职业选择）→ 新手教程房间（`d/start_room/start_room1`~`start_room6`，含 `southdown`/`southeast`/`southwest` 三个复合方向出口——确认这些不是 typo，而是 `cmds/std/go.lpc` 方向表里真实存在的合法方向，和 `up`/`down` 组合出的对角方向同一套设计）→ 真正的起始区域"有一间客栈"（`d/fy/fqkhotel`）→ 留言板 `post`/`look board` → 友好切磋 `fight` → 真实战斗 `kill` → 死亡/复活全流程 → `quit`/重新登录 → 管理员 `update` 写权限验证。全程无 driver 崩溃，`debug.log` 除下面两条外无异常。此档案和本轮会话已深挖过的其它库都没有确认的同源关系（README 自称"风云"衍生分支，但 AGENTS.md §11 的血统表里没有把它归入 风云3/风云Ⅳ/风云再起Ⅱ/夕阳再现 任何一支——本次没有发现和这些分支共享的 master.lpc/securityd.lpc/logind.lpc 结构证据），因此按 AGENTS.md 已知 bug 类别清单逐项排查，而非 sibling-check。

- **§8.12（本次新增）属性类别选择菜单提示大写 A-L，但校验只认小写，玩家照提示输入反而被拒**：`adm/daemons/logind.lpc` 的 `get_kind()` 用 `请您选择您的人物的属性类别,有12种类型(A,B,C,D,E,F,G,H,I,J,K,L)` 提示，被拒时的重复提示也写着 `你只能在(A--L)中选择一种人物类型`——两处都是大写。但实际判断 `if (kind < "a" || kind > "l")` 比较的是小写边界，`"A" < "a"` 在 LPC 字符串序里成立（'A'=65 < 'a'=97），导致大写 `A` 被拒、循环回同一个仍然写着大写的提示，玩家如果老老实实照提示打字会陷入打不过去的死循环，只有误打误撞试小写才能过关。实测确认：`A` 反复触发"你只能在(A--L)中选择"拒绝消息；`a`（提示文字从未提到的写法）正常通过，进入天赋数值展示。下游 `choice_gift()` 本身也只认小写字母表（`"abcdefghijklmnopqrstuvwxyz"`），证明真正该修的是提示/校验的大小写不一致，不是反过来让下游改认大写。修复：在 `get_kind()` 顶部先 `kind = lower_case(kind)` 再做范围判断。重启驱动后原样重测：大写 `A` 直接进入天赋展示，不再触发拒绝循环。已更新 AGENTS.md，新增 §8.12。
- **§7.95（本次新增）`cmds/std/fight.lpc` 的"讨教/切磋"指令：NPC 婉拒时该显示的 `notify_fail()` 提示永远不会出现**：`fight <NPC>` 在目标是"可对话"（`can_speak`）NPC 时会先显示挑战台词，再判断 `obj->accept_fight(me)`；婉拒分支写的是 `notify_fail("看起来...并不想跟你较量。\n"); if (!userp(obj) && !obj->accept_fight(me)) return 1;`——同一个文件里所有其它拒绝分支（没有目标、目标不是生物、目标已在和自己交手等）都正确用 `return notify_fail(...)` 的写法（`notify_fail()` 本身返回 0，driver 只有在整条指令链最终返回 0 时才会真的把排队的失败消息显示出来），唯独这一分支先把 `notify_fail()` 当成普通语句调用，再手动 `return 1`（成功），排队的婉拒消息因此永远没有机会显示。实测：对本档案第一个客栈（有一间客栈）里友好属性的"店小二"（`obj/npc/waiter.lpc`，`attitude: friendly`）打 `fight waiter`，修复前只看到玩家自己喊出的"领教...高招"挑战台词，之后彻底沉默，和网络卡顿/挂起没有任何区别；`debug.log` 也没有任何报错（不是崩溃，是纯逻辑死角）。修复：把这一分支的 `return 1;` 改成 `return 0;`（等价于直接 `return notify_fail(...)`），保留 `accept_fight()` 成立时继续走 `fight_ob()` 的分支不变。重启驱动后重测：同样的 `fight waiter` 现在正确显示"看起来店小二并不想跟你较量。"。已更新 AGENTS.md，新增 §7.95。
- **§7.90（追加确认，非新增条目）本档案 `maximum evaluation cost : 700000`（本项目常见默认值）不够用，但触发方式是第三种新形态——纯后台精灵行为，玩家从未去过现场**：一次和角色行动完全无关的会话期间，`debug.log` 记录了一次 `Eval interrupted: object d/shaolin/npc/cheng-xin1#65 cost limit reached, limit: 700000 usec`，调用栈显示是 `adm/daemons/taskd.lpc` 的 `send_task()`/`find_target()` 在后台扫描任务目标时，顺带懒编译了少林寺一个从未被玩家造访过的房间（`d/shaolin/banruo1.lpc`）连带其中的 NPC。已按已确认的补救方式把 `config.fluffos` 的 `maximum evaluation cost` 从 `700000` 提到 `5000000`（本项目另有 30+ 档案在用这个值）。重启驱动后完整走完一轮注册→移动→留言板→切磋→实战 `kill`→死亡复活→`quit`→重连的会话，加上约 90 秒纯 idle 观察期，`debug.log` 再无 `cost limit reached`/崩溃记录。已在 AGENTS.md §7.90 追加"第六实例"记录，未新增条目号（该模式本身已有充分先例，这里只是第三种触发形态的又一佐证）。
- **战斗与死亡/复活全流程实测通过，§7.68 类"鬼魂卡死"不适用**：用管理员测试角色对南风大街的"风兵首领"（`d/fy/npc/solider_captain.lpc`）打 `kill captain`，多回合真实攻防判定正常（命中部位、伤害描述、体力下降提示逐条推进），角色被击杀后完整走完"鬼门大道→奈何桥→酆都城门→森罗殿→地狱入口"五段场景（各段场景都有白无常 NPC 陪同引导对白），阎罗王在森罗殿判定"阳寿未尽"，最终被推入冥海直接复活，落地在城内"天主教堂"，`score` 显示精/气/神条按预期打了折扣（惩罚），食物/饮水条满格未受影响。全程一次性顺畅走完，没有任何环节需要重试或卡在中途——不属于 AGENTS.md §7.68 描述的"present() 守卫吞掉重试"的情形，本档案压根没有触发那类分阶段 `call_out` 守卫的机会。
- **§8.9（食物/饮水初始化）不适用**：`score` 全程食物/饮水条都是满格，未观察到"新角色永远处于挨饿状态"的症状；`enter_world()`/`init_new_player()` 直接对 `user` 赋固定值 `2000`，没有 `ob`/`user` 混用的对象读取。
- **§8.3a/§8.3b（`private nomask command_hook`/`.c` 后缀 sscanf）均不适用**：`feature/command.lpc` 本来就是 `protected nomask int command_hook(...)`，不是 `private`；`look`/`score`/`kill`/`fight`/`post`/`buy`/`goto`/`update` 等指令全程响应正常，指令表健康。
- **留言板、商店、管理员权限全部实测通过**：`post`（在"有一间客栈"的一般用途留言板）留言完毕，`look board` 未读数正确更新为"1 张留言，1 张未读"；`list`/`buy dumpling from waiter` 购买成功；`update /std/room.lpc` 以 `fluffos` 管理员身份重编译成功，确认 §1.5 的 write ACL（`trusted_write` 里 `"/"` 目录本来就允许 `(admin)`）本来就是通的，不需要额外补种。
- **未覆盖**：邮件系统（`help mail` 未命中任何帮助主题，本档案似乎没有独立的玩家间邮件指令，或者命令名不在常见猜测范围内，本轮时间有限未继续深挖）、正式门派拜师流程（起始区域的 1-13 传送点直达各门派，本轮选了`1`号"有一间客栈"入口熟悉环境，未继续走完某个具体门派的拜师/学技能全流程）。

管理员账号（`fluffos`/`Mud@2026`）本次通过正常注册流程重新走了一遍确认——`adm/etc/wizlist` 里已有 `fluffos (admin)` 一行（应为更早的 WASM 阶段留下），注册后立即显示"目前权限：(admin)"，`update` 验证 write ACL 正常，说明 §1.5 的既有 README 记录依然准确、无需改动或标记为过期声明。

## 深度功能测试（2026-08-13，round two，新驱动重测）

针对驱动升级（`quest_times`/`win_times` `%`-operator 修复 + Warning/warning
大小写回退兼容）做的重测，覆盖此前两轮（WASM 阶段、2026-08-08 的
§10.7）之后新出现或新引入的问题。

### 发现并修复的 PROGRAMMING bug

1. **`log_file()`（`adm/simul_efun/file.lpc`）完全没有 `assure_file()`
   保护（AGENTS.md §7.11-class）**：`write_file(LOG_DIR + file, text)`
   直接写，`LOG_DIR` 下的子目录若不存在会未捕获抛出。已加上
   `assure_file(LOG_DIR + file);`（含前向声明，因为 `assure_file()`
   本身定义在同一文件后面）。

### Proactive checks（无需改动）

- `log_error()`（`adm/obj/master.lpc`）已经用 `if (me &&
  wizardp(me))` 把编译期诊断限制在巫师身上，不是 §7.34-class 那种
  "任何玩家都能看到" 的形状——这份档案里编译诊断本来就只给巫师看，
  属于合理的调试辅助设计，不是 bug，未改动。
- `feature/dbase.lpc` 没有 tybxjh/wlhd 那种基于 `wizhood()` 的密码
  写保护，不适用那一类 bug。
- `win_times` 的 `%`-operator 修复确认存在且正确：
  `d/city2/npc/refereew.lpc:176` 已用 `to_int(query("win_times")) %
  5`；同一文件姊妹档 `d/huashan/npc/refereew.lpc` 里对应位置根本不
  用 `%`，不适用。
- `maximum evaluation cost`（此前已从 700000 提到 5000000）在本轮
  完整会话（注册→移动→look→score→quit→重连→look→score）中未再触发
  eval-cost 相关崩溃。

### 实测过程

新角色 `xbtest`/中文名"风灵二"，完整走了一遍注册流程（id → 确认 y
→ 中文名 → 密码 → 确认密码 → 性别 m → email → 属性类别 a → 接受 y
→ 职业 fighter → 确认 y），进入"时空通道"新手教程房间，食物/饮水槽
满格，`look`/`score` 输出正常，`quit` 干净退出。随后**单独一步**做
了真实的断线重连+密码验证：用刚设的密码 `xbtest`/`test12345` 重新
连线，成功登录，存档位置（"文庙"）正确持久化，`score` 数据一致。
全程 `debug.log` 只有正常的编译期 Warning/note（`Unknown #pragma`、
未使用局部变量等）和三处已知的 "cannot replace a program with
function references, ignored"（预加载阶段的良性提示，不是崩溃，出
现在房间文件而非留言板文件上，和此前 §7.86 扫描修复的留言板
`replace_program()` 死形状不是同一类，未处理）。驱动按精确 PID 结
束。测试角色存档（`xbtest`）及聊天名字缓存增量未提交，仅提交
`file.lpc` 的实际修复。

## §7.100 房间基类 replace_program() 扫尾修复（2026-08-19）

`ROOM` 宏（`/std/room`）在本档案 2,174 处房间文件的 `create()` 里
紧跟 `inherit ROOM;` 之后又多余调用了一次 `replace_program(ROOM);`
——AGENTS.md §7.100 记录的同一个休眠 bug（多余调用给对象打上永久
"pending replace"标记，对象一旦绑定任何闭包就会崩溃）。这份档案
有 3 份房间生成工具副本（`obj/misc/roommaker.lpc`、
`cmds/wiz/roommaker.lpc`、`d/ny/obj/roommaker.lpc`），全部同一形
状。用 `fix_710_room.py` 扫过 `work/`，删除 2,171 处标准形状；三
份工具各剩 1 处字符串拼接变体 `str +=
"...replace_program(ROOM);..."`，手工改成
`str += "\n\tsetup();\n}\n";`。修复后 `work/` 下 0 处存活残留，
162 处转档之前已注释掉的 `//` 行原样保留，`work/data/` 下没有真
实 `.lpc` 源码命中。`git diff --stat` 显示 2171 个文件净删 2174
行，与脚本自报数字 + 3 处手工编辑吻合。

驱动干净启动（零新增编译错误、端口正常监听、`debug.log` 无任何
"cannot replace"/"cannot bind"行），巫师账号 `fluffos`/`Mud@2026`
登录后确认"目前权限：(admin)"，`look`/`goto` 走读了 2 个曾经命中
过这个 bug 的房间（`u/quicksand/saiwai2.lpc`、
`u/quicksand/sandroad.lpc`）均正常，`quit` 走完退出流程。登录存
档的时间戳增量已用 `git checkout HEAD --` 撤销，未落入提交。

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

## 深度功能测试补完（2026-08-23）：邮件系统 + 门派拜师

补完前两轮 NOTES.md 里一直标记"未覆盖"的两项，均确认为**正常可用，
没有发现真正的程序错误**。用原生驱动（`build-debug/src/driver`）通
过 `scripts/tmux_mud.sh`，管理员账号 `fluffos`（游戏内中文名"风
灵"）实测。

### 邮件系统——确认存在，此前"help mail 未命中"是正常的（不是 bug）

- 全库搜索确认这份档案**确实有玩家间邮件系统**，只是不通过
  `help`（`doc/help/` 目录下完全没有任何邮件相关主题），而是通过
  一个自动发放的信箱物件实现：`adm/daemons/logind.lpc:778-780` 在
  **每次登录**都会 `new(MAILBOX_OB)` 克隆一个信箱并
  `->move(user)`，`MAILBOX_OB` 定义在 `include/globals.h:72` 为
  `/obj/mailbox`。这个物件的 `init()`（当它进入玩家背包时触发）用
  `add_action` 注册了 `mail_to`/`forward`/`from`/`read_mail`/
  `discard` 五个指令，物件本身的 `long` 描述里也写明了这几个指令
  名——即物件说明文档就是这份档案事实上的"帮助文档"，`help mail`
  查无此主题是预期行为，不是缺陷。
- **发现一份完全无法触达的死代码**：`obj/misc/mailbox.lpc` 是另一
  份不同的信箱实现（指令名是 `mail`/`read`，不是
  `mail_to`/`read_mail`），被 `d/fy/npc/officer.lpc`（风云绎站的驿
  长"王风"）的 `send_mail()`/`receive_mail()` 对话分支引用
  （`mbox = new(MAILBOX_OB); ...`——注意这里其实引用的也是
  `MAILBOX_OB` 宏，即 `/obj/mailbox`，`obj/misc/mailbox.lpc` 本身
  并未被这个宏指向，是彻底的孤立文件）。由于每个玩家一登录就已经
  拿到了 `/obj/mailbox`，`query_temp("mbox_ob")` 恒为真，驿长的
  "寄信/收信"对话分支的判断 `if
  (this_player()->query_temp("mbox_ob"))` 永远会命中"你的信箱还在
  吧"这条早退分支，`new(MAILBOX_OB)` 那行永远执行不到——不是崩
  溃，纯粹是一段游戏内容层面的历史遗留死码（大概率是从更早版本
  遗留），**未改动**（无错误信号，不在本轮"只修程序错误"的范围
  内，仅记录在案）。
- **完整实测跑通收发信全流程**：以管理员角色（id `fluffos`，score
  显示为 `Fluffos`）用 `mail_to fluffos` 给自己写信——标题、正文
  （驱动自带的行编辑器，`.` 结束）、"是否自留备份"三步走完，`from`
  正确列出信件、`read_mail 1` 正确显示标题/寄信人/正文，`forward`/
  `discard` 未逐一测试但代码结构和已验证的 `do_mail`/`do_from`/
  `do_read` 同构，判定为低风险直接豁免。**注意一个纯粹的操作细
  节，不是 bug**：`do_mail()`（`obj/mailbox.lpc`）把收件人参数原样
  传给 `FINGER_D->acquire_login_ob()` / `find_player()`，两者都区
  分大小写；用 score 屏幕显示的大写形式 `mail_to Fluffos` 会得到
  "没有这个人存在。"，必须用登录时敲的小写 id `mail_to fluffos` 才
  行。核对了 `cmds/std/tell.lpc`（`tell <人名>` 的同款
  `find_player(target)` 调用）确认这是全库统一的既有约定——不对输
  入做大小写归一化——不是 `mailbox.lpc` 独有的缺陷，未改动。

### 门派拜师——完整走通一次，score 正确反映新门派

- 起始区域 `d/start_room/start_room.lpc` 的空间传送器 1-13 号入口
  第一轮只走过 1 号（有一间客栈熟悉环境），这次选了 **8 号"华山
  派"**（`/d/huashan/buwei1`）。该房间实际站着的是大师兄令狐冲
  （`daemon/class/huashan/linghu.lpc`），不是掌门岳不群本人——掌门
  在里屋，新弟子进不去（`buwei1.lpc` 的 `valid_leave()` 挡着，要
  先拜入门下才能进）。
- 用 `apprentice ling` 对令狐冲发起拜师请求。`cmds/std/apprentice.lpc`
  走到 `ob->attempt_apprentice(me)` 分支，`linghu.lpc:113` 的
  `attempt_apprentice()` 检查 `ob->query_int() < 14`（对应属性面
  板上的"悟性"）——测试角色悟性 15，达标，NPC 立即 `command("say
  ...")` + `command("recruit " + id)` 完成收徒，一次性走完、无需
  第二条指令。`score` 复测确认标题从"普通百姓"变为"华山派第十五
  代弟子"，新增一行"你的师父是令狐冲。"，`skills` 指令干净返回
  "你目前并没有学会任何技能。"（没有崩溃——拜师本身只给门派身
  份，学技能是另一道独立的、大概率有忠诚度/资历门槛的流程，这次
  没有继续深挖，不在本轮范围内）。
- 顺带确认了 `daemon/class/wudang/zhangsanfeng.lpc`（9 号入口武当
  派掌门）和 `daemon/class/huashan/master.lpc`（岳不群本人）的拜
  师门槛明显更高（前者要求 `fealty >= 2000`，后者的
  `do_recruit()` 甚至要求拜师前就已经 `family/family_name ==
  "华山派"`，对全新角色而言这个联通门只能靠先拜其弟子再转投）——
  这些都是有意为之的师门声望梯度设计，不是 bug，未改动。

### 结论

两个此前"未覆盖"项均已补测，**均为设计/文档缺口而非程序错误，未
做任何代码修改**。测试用的是持久化的管理员账号 `fluffos`，其存档
（`data/login/f/fluffos.o`、`data/user/f/fluffos.o`）和测试期间新
建的 `data/mail/` 目录均已用 `git checkout HEAD --` / `rm -rf` 清
理干净，不落入本轮任何提交。

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.


## 深度功能测试（§10.7，2026-10-04）— undefined macro and simul_efun gaps

- `message_combatd(msg, me, you)` is called by 133 file(s) (the perform files) and defined nowhere in this archive (a simul_efun of the original server): 133 of them did not compile (`Undefined function message_combatd`). `adm/simul_efun/message.lpc` now has `varargs void message_combatd(string msg, object me, object you, mixed extra)` calling `message_vision()`, placed after `message_vision`'s definition (KB 04 §6.2). All callers compile.

## 深度功能测试（§10.7，2026-10-04）— compile-warning and load-failure pass

`scripts/lpc_warnings.py xbtxiii` (8372 `.lpc`): 6341 distinct diagnostics and 580 files that did not compile at the start, 227
diagnostics and 418 files at the end (7954 compile). A load check of every `.lpc` (700 per VM boot) at HEAD and in the working tree:
7908 PASS -> 7939 PASS, 33 more load. The two files that flip the other way, `d/npc/walker.lpc` (one of its random branches sets a
skill, `spicyclaw`, that this lib does not have) and `d/shenlong/npc/yunsumei.lpc` (it passed in the HEAD batch and fails at HEAD when loaded alone: the
`/d/city/obj/duanjian` it carries was never shipped), are batch artifacts, not regressions. 4964 files changed. The code is a
Fengyun/xkx mixture, so the root's tools ran as they are (libs/xkx2001/NOTES.md has the classes), in the order of
`scripts/lpc_family_pass.py` (the name-winner tool only after the redundant inherits were gone; run before that it wrote
`skill::fn()` wrappers for 24 files whose inherit no longer existed, they were removed again).

**Bulk.** 4846 `#pragma` lines in 4714 files (`save_binary`, `optimize all` ...: `Unknown #pragma, ignored`), unused locals, 36
redundant leaf inherits, 21 `int init()`-style overrides of `void` hooks made `void`, 15 prototypes whose return type disagreed with the
definition, 2 `#undef` lines for macros that two headers define (`ROOM`, `STORY_DIR`), 35 diamonds named (27 `type()`, 6
`clean_up()`, 2 `NewRandom()`), one here-document terminator; `adm/object/bmm.lpc` `transfer`'s declaration moved into its branch. The two stray string statements after the
`return` in `d/secret/secret1/npc/king.lpc` (`"爱卿拿去吧。\n";` ...) never ran and are gone.

**Fixed by hand (each read first).**
- `include/globals.h` defines `SAVE_EXTENSION` (`".o"`, the driver's default `save file extension`): `d/death/npc/hoo.lpc`,
  `obj/npc/horse.lpc`, `d/green/try.lpc`, `d/jiangnan/yangzhou/qianzhuang.lpc` and three more name it and did not compile.
- Five headers use `HIG` / `NOR` / `MAG` and rely on the includer's `<ansi.h>`, which the NPCs of this lib do not include
  (the same NPCs in `chidi`, `bixiecanyang`, `hc` have it on line 2): `d/mingjiao/npc/zhangqishi.h`, `d/mingjiao2/npc/zhangqishi.h`
  (10 NPCs) and `daemon/class/shaolin/{cheng,dao,hui}.h` (the shaolin masters) now `#include <ansi.h>` themselves.

**What is left, and why (content gaps, not code).** 418 files still do not load; 83 have a compile error, the rest die in `create()`.
- The archive has **no `/clone` tree**: 128 of the 152 distinct `carry_object()` / `new()` lines that raise `Bad argument 1 to call_other`
  name a file under `clone/misc`, `clone/weapon` or `clone/cloth` (the xkx NPCs this lib took over carry xkx items), the others a few
  `d/city` / `d/ustc` objects that are not there (`/d/city/obj/duanjian`).
- 96 files raise `F_SKILL: No such skill (..)`: `set_skill()` needs `/daemon/skill/<name>.lpc`; 56 of the files use skills that exist only in
  `/daemon/gongfu/` (a second, xkx-style skill directory no code of this lib refers to) and 72 use skills that exist nowhere.
- `inherit F_DEALER;` / `inherit CLUB;` / `BUNCHER` ...: the std objects were never part of the archive. The TMI-2 network daemons under
  `adm/daemons/network/` lack their headers (`uid.h`, `config.h`, `mailer.h` ...). Nothing was written new for any of them.

## 深度功能测试（§10.7，2026-10-05）— room base survives a raising NPC

`scripts/lpc_resilient_room.py --apply`: `make_inventory()` of `std/room.lpc` loads each inventory object as `if (catch(ob = new(file)) || !objectp(ob)) return 0;`. `new()` of a file that is not there returns 0 (the room just lacks that NPC), but `new()` of a file whose `create()` raises (a skill file for `set_skill()` this archive never had, a `carry_object()` item that is not there, a header that never shipped) raised inside the room and the room did not load at all. This lib has no wrong-case paths; the change is the one made in the libs whose renames made such NPCs reachable (KB 03 §4.5), and keeps a room loadable when an NPC in its inventory has a content gap: it loads without that NPC. The room base compiles and loads with the change (HEAD against the working tree).

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `std/room.lpc`：`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 OK，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-06）— 白驼山掌门欧阳锋编译不过

`d/baituo/ouyangfeng.lpc` 有两处笔误，整个 NPC 从未编译成功：`greeting()` 里 `write("你是谁？我要杀了你！哈￣哈￣哈￣") break;` 缺分号，`inquiry_map()` 里 `object me = this - player();`（应为 `this_player()`）。白驼山派的掌门因此不存在，拜师、问路（`inquiry_map`）都无从谈起。两处改正后，新进程里 HEAD 加载失败、工作树加载成功。同一文件在 14 个 xkx 系的库里一字不差。

## 深度功能测试（§10.7，2026-10-07）— 空的 `if (current_water == 0) {}`

3 个房间的 `valid_leave()` 里有一行什么也不做的 `if (current_water == 0) {}`（编译警告 `Expression has no side effects`），删去，行为不变：`d/xingxiu/nanjiang2.lpc`、`d/xingxiu/nanjiang3.lpc`、`d/xingxiu/shanjiao.lpc`。

## 深度功能测试（§10.7，2026-10-07）— 皇帝的两句话

`d/secret/secret1/npc/king.lpc`：`msg = "……这里是200两黄金。\n";` 后面单独一行 `"爱卿拿去吧。\n";`，`msg = "……去后宫了。\n";` 后面单独一行 `"不过临走之前给了$N一个免死金牌\n";`——多余的 `;` 把消息截成两句，后半句从来没显示过。2026-10-05 的警告整理（a68352ca1f6）把这两行当作无用语句删了；现在接回 `msg` 上。新进程加载通过。

## 深度功能测试（§10.7，2026-10-07）— 兵器的 `actions` 函数指针

`set("actions", (: WEAPON_D, "query_action" :));`：旧 MudOS 把 `(: 字符串, "函数" :)` 当作 call_other 函数指针，本驱动把它当作表达式函数指针，求值只得到字符串 `"query_action"`。没有对应兵器技能时 `feature/attack.lpc` 直接用兵器的 `actions`，`COMBAT_D` 拿到的不是 mapping，`reset_action()` 后仍不是，记一条 bad action 就不出招——拿着这些兵器打不出攻击。改成别的兵器早已用的 `(: call_other, WEAPON_D, "query_action" :)`（KB 04 §6.10）：`d/npc/m_weapon/weapon/m_club.lpc`、`d/npc/m_weapon/weapon/m_blade.lpc`、`d/npc/m_weapon/weapon/m_whip.lpc`、`d/npc/m_weapon/weapon/m_sword.lpc`、`d/npc/m_weapon/weapon/m_staff.lpc`。改动的文件在 HEAD 与工作树分别加载（新进程），无回退。

- 2026-10-10：`/cmds/wiz/roommaker.lpc` 生成新文件用的 here-document 模板（`@ROOM_CODE`/`@OBJ_CODE`）里的 `inherit` 行，被 a68352ca1f6 的重复继承清理当成代码删掉了（`lpc_diamonds.py` 当时不识别 here-document），用它生成的房间/物品会因缺少继承而无法编译。已恢复该行；工具已修正。

- 2026-10-10：`/d/ny/obj/roommaker.lpc` 生成新文件用的 here-document 模板（`@ROOM_CODE`/`@OBJ_CODE`）里的 `inherit` 行，被 a68352ca1f6 的重复继承清理当成代码删掉了（`lpc_diamonds.py` 当时不识别 here-document），用它生成的房间/物品会因缺少继承而无法编译。已恢复该行；工具已修正。

- 2026-10-10：`/obj/misc/roommaker.lpc` 生成新文件用的 here-document 模板（`@ROOM_CODE`/`@OBJ_CODE`）里的 `inherit` 行，被 a68352ca1f6 的重复继承清理当成代码删掉了（`lpc_diamonds.py` 当时不识别 here-document），用它生成的房间/物品会因缺少继承而无法编译。已恢复该行；工具已修正。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 0 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 3 个，只在 #if 分支用的声明移进分支 0 个文件；改动 3 个文件，HEAD 与工作树各载入一次无回退（3 objects; HEAD PASS 3, tree PASS 3; regress 0; newly loading 0），这些文件的警告 3 -> 0。

## 深度功能测试（§10.7，2026-10-11）：dns_master 空 if

- `adm/daemons/network/dns_master.lpc` `query_services()`：`if (! (mud_svc[mud]["tell"/"finger"] & SVC_KNOWN)) {` 里只有 `#if PREF_X & SVC_TCP … #endif`，选项关闭时 if 体为空（“无副作用”警告）；把 `#if`/`#endif` 挪到 if 外面（KB 04 §6.10，2026-10-07 那次扫描漏掉了 `! (` 带空格、大括号另起一行的写法）。载入无回退。

## 深度功能测试（§10.7，2026-10-11）：dns_master 空 if

- `adm/daemons/network/dns_master.lpc` `query_services()`：`if (! (mud_svc[mud]["finger"/"tell"] & SVC_KNOWN))` 块里只有 `#if PREF_X & SVC_TCP … #endif`，选项关闭时 if 为空（“无副作用”警告报在下一句）；把 `#if`/`#endif` 挪到 if 外面（KB 04，2026-10-07 那次扫描漏了 `! (` 加括号换行这种写法）。载入无回退。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查

- `d/baituo/shulin.lpc` 砍柴：`if (i < 1);` 多了分号，“请适量砍伐！”无条件返回，柴永远砍不成；去掉分号。
- `d/foshan/npc/chaofeng.lpc`：战斗出招列表丢了 `set("chat_msg_combat", ({ … }));` 外壳，五个函数指针被逗号并进 `set_skill()`，战斗中从不出招；补回外壳。
- `daemon/gongfu/xuanyuan-arrow.lpc` `practice_skill()` 的死语句 `(: throw_weapon :);` 删去。载入无回退。

## 编译警告收尾（2026-10-13）

手工清零；改动的 15 个对象在 HEAD 与工作树各载入一次，regress 0。

- 七处 `item_desc`/问答写成 `(: "一段高高的院墙……" :)`，是只返回字符串常量的函数指针；改成字符串本身，显示不变（`d/city/newstreet4`、`street3`、两处 `walker`、两处 `kefang`、`d/waterfog/servant_room`）。
- `cmds/std/look.lpc` 声明了两张 `per_msg_beast3`（野兽第三档相貌描述），代码用的是后一张；前一张改名 `per_msg_beast3_old` 保留原文。
- `obj/npc/zombie.lpc`、`u/quicksand/npc/snake.lpc` 的 `die()` 改 `void`；`adm/daemons/network/services/dns_master.lpc`、`dns_master1.lpc` 里 `#if PREF_TELL & SVC_TCP` 挪到 `if` 外面（同 shujian3），不再剩一个空 `if`；`d/shaolin/damo-mi.lpc`、`daemon/gongfu/huashan-jian*.lpc` 多余的 `;` 删去。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。2 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

33 个文件（技能、绝招、兵器、书籍、区域 NPC 等）来自侠客行体系（qi/jing/neili），而本库人物是 gin/kee/sen/force：`receive_damage("qi", ...)` 报 `伤害种类错误`，`query("neili")` 永远为 0。按 qi→kee、jing→sen（本库学习/读书指令消耗的就是它）、neili→force、max_neili→max_force、jiali→force_factor 改名（`scripts/lpc_port_es_props.py --any-file`）。

## 治疗/疗伤的属性名（2026-10-15，KB 06 §7.241）

`receive_heal()`/`receive_curing()` 也只接受本库的种类。5 个文件（多为只调用 `receive_heal`/`receive_curing` 的药物、NPC）来自侠客行体系，按 qi→kee、jing→本库学习指令消耗的池、neili→force 改名（`scripts/lpc_port_es_props.py --any-file`）。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。4 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。

## 空手使用兵器绝招（2026-10-15，KB 06 §7.246）

`perform` 指令允许直接点名招式（如 `perform stick.ban`），这些绝招读了 `me->query_temp("weapon")` 却从不检查，空手时 `weapon->name()` 报错（有的已先扣了内力）。在赋值后补 `if (!objectp(weapon)) return notify_fail("你必须手持兵器才能使用这一招。\n");`（`scripts/lpc_fix_perform_weapon.py`）：`bahuang-qiangfa/throw`、`pixie-sword/caidie`、`xiangmo-chu/xiangmo`。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`mizongxinfa`→`mizong-xinfa`（`/daemon/gongfu/longxiang/fanchang`）。

## 柔云步法「柔云纵」有时报错（2026-10-15，KB 06 §7.251）

`rouyun-steps/zong` 随机把人送到三个房间之一：精、精力已经扣了，“乘云而去了”也说了，送不过去时人留在战斗里并报错。本库的武庙、客店、中央广场在 `/d/yangzhou/`，`/d/city/` 下没有，三处都会报错；改为 `/d/yangzhou/wumiao`、`/d/yangzhou/kedian`、`/d/yangzhou/guangchang`。

## family 映射内联取下标（2026-10-15，KB 05 §7.30）

`ob->query("family")["master_name"]`、`me->query("family")["family_name"]`（泥潭式为 `query("family", ob)[...]`）直接对门派映射取下标：没有门派的人（新玩家、叛师者、大多数 NPC）在 NPC 的打招呼和问话、绝招的门派判断、房间的 `valid_leave` 里报 `Value being indexed is zero`，而不是得到拒绝。4 处（3 个文件）改为 dbase 路径查询 `query("family/master_name")`：有门派时值相同，没有时得 0；原有的判断照常生效（`scripts/lpc_fix_family_index.py`）。给映射赋值的写法未动。


## 血刀刀法「祭血神刀」正神时报错（2026-10-15，KB 06 §7.241）

`xue-dao/shendao` 的伤害是 `random(shen / -1000) + shen / -3000`，越邪恶伤害越高；正神的人算出负数，`receive_damage()` 报“伤害值为负值”。补 `if (damage < 0) damage = 0;`，设计不变（正派用不出伤害），不再报错。


## 贴身对手不在时绝招报错（2026-10-15）

本库是方位战斗：没有敌人贴身时 `select_opponent()` 返回 0，但仍处于战斗状态。`dugu-jiujian/po`、`dugu-jiujian/poqi`、`hunyuan-zhang/wuji`、`zhemei-shou/duo` 取了对手就直接用，敌人不在身边时报错。取对手后补“你身边没有可以出手的对手”的拒绝（不在战斗中时仍是原来的提示）。（更正：本日较早记下的「柔云纵」修正改的是 `daemon/gongfu/`，那是没有被使用的旧目录，`SKILL_D` 指向 `daemon/skill/`；改了无害，但不影响游戏。）

## 绝情谷（d/ultimate/first）是没有完成的区域（2026-10-15，KB 06 §7.253）

从 `d/ny/droad2` 往北可以走进去，但这条任务链在原档案里就走不通：`secret_house` 编译不过（`__DIR__"npc/xiaolongnv:1,` 少了引号，`greeting()` 里 `npc` 从未赋值、`thank_player(object me)`、`if(temp=0)`），而它是唯一放小龙女的地方；`npc/xiaolongnv.lpc` 其实是杨过的副本（`set_name("杨过", ({ "yang guo" ...`），`climb_up()` 要找的 `xiao long nv` 根本不存在；`come_shuitan()` 声明时只有 `me` 一个参数（call_out 传了 `me, yangguo, xiaolongnv`），区域搬进 `first/` 之后 `/d/ultimate/shuitan`、`gu_di1`、`jueqinggu` 这些路径也没改；最后挖出的奖励 `/d/ultimate/obj/first_stone` 不存在。补全要写新的内容（小龙女、奖励），超出修程序错误的范围，这次没有改动，记在这里。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

191 个文件、233 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/clone/misc/cloth`、`/clone/weapon/changjian`、`/d/city/obj/duanjian`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 1 个，改后 145 个（144 个原来载入不了），没有退步；其余 46 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## `for (int i ...)` 的循环变量在循环外还在用（2026-10-18，KB 04 §6.12）

当铺／商店的 `do_buy()` 写成 `for (int i = 0; ...) if (...) break;`，循环一结束又读 `if (i == sizeof(inv))`。FluffOS 里 `for` 头里声明的变量只在循环内有效，所以 `Undefined variable 'i'`，整个房间（NPC）载入不了，当铺根本进不去。把 `i` 声明挪到函数开头（`int i, index;`），循环改成 `for (i = 0; ...)`：`d/snow/npc/hocker.lpc`。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 83 个对象设了本库没有文件的武功（78 个名字，最多的是 `xuanyuan-arrow`、`fall-steps`、`snowshade-sword`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：30 个里 29 个通过，其余 1 个停在别的错误上（`d/green/npc/master`：*No program in object '/d/green/npc/master'!）。（`scripts/lpc_guard_set_skill.py`）

## 通向不存在房间的出口，按对面房间的回头出口改正（2026-10-18，KB 06 §7.257）

房间出口 `"west": __DIR__"xxx"` 指向的文件本库没有，玩家走过去就被卡住（笔误、改过名的房间，或者没带进档案的编号房间）。对面的房间存在、并且它相反方向的出口正好指回这个房间，说明出口原本就是通向它：`/d/mingjiao/jmqshulin6` 的 `west`：`jmqjiguan` → `jmqshenmu`；`/d/ny/nroad0` 的 `west`：`/d/snow/nroad6` → `/d/ny/nroad5`。改动后每个出口都能解析到本库的文件（`scripts/lpc_fix_dead_exits.py`；目标在运行时本来就能载入的库——虚拟房间——不动）。

## 补回本库没有的基类文件（2026-10-18，KB 04 §6.15）

下面这些基类本库没有，继承它们的对象（房间、NPC、物品）整批载入不了（`inherit XXX;` 的宏没定义，或者 `inherit "/std/…";` 的文件不在）。同系的库里有同名文件，两库有大量逐字节相同的文件（亲缘关系），所以从那边原样拷来，缺的宏补进全局头文件 `include/globals.h`：`/feature/dealer`（宏 `F_DEALER`）←njhhdxdes2hx，8 个对象继承它，抽样 8/8 载入。每个基类补回后单独载入、再抽样载入使用它的对象，基类载不进来或者一个用户也载不进来的就撤掉（本库撤掉了它们，不再补）。（`scripts/lpc_restore_bases.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 8 处、5 个文件：`tiaji-jian`→`taiji-jian`（4 处）、`bolomiduo`→`boluomiduo`（2 处）、`jinggang-quan`→`jingang-quan`（1 处）、`huashan_shenfa`→`huashan-shenfa`（1 处）。（`scripts/lpc_fix_skill_names.py`）

## set_name 的 id 参数传成字符串（2026-10-19，KB 06 §7.260）

`set_name("海口大碗", "bowl");` 把物品的 id 写成了字符串，本库的 `set_name(string name, string *id)` 要的是数组，驱动在编译时报 `Bad type for argument 2 of set_name ( string * vs string )`，整个物件载入不了；旧驱动不检查参数类型，字符串里照样找得到这个词，物品能用 id 称呼。改成 `({ "bowl" })`，共 2 个文件：`/d/baituo/npc/obj/bowl.lpc`、`/d/baituo/obj/bowl.lpc`。（`scripts/lpc_fix_set_name_id.py`）

## 出口指向不存在的房间（2026-10-19，KB 06 §7.257）

下列房间的出口写的文件不存在，而对面恰好只有一个房间的出口指回本房间，所以按对面的房间改正（笔误、大小写、路径少了一级）：

- `/d/foshan/dangpu.lpc` 的 `north` 出口：`westjie1` → `street5`

改后房间照常载入（与 HEAD 逐个对比，没有退步），出口现在指向存在的房间。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 载入不了的零碎文件（2026-10-19，KB 03 §4.7、KB 04 §6.10）

- `d/city2/npc/cheng.lpc`（程老板）的 `set("vendor_goods", ([ "路径", ... ]))` 是只有键没有值的映射，语法错误；`feature/dealer.lpc` 读的是数组，改成 `({ ... })`。货物 `/d/city2/obj/hdjiudai` 档案里没有，买到它时才会出错。

逐个载入与 HEAD 对比，没有退步。

## 玩家打造兵器模板没有打造者时（2026-10-19，KB 06 §7.275）

`/d/npc/m_weapon/weapon/m_blade.lpc`、`/d/npc/m_weapon/weapon/m_club.lpc`、`/d/npc/m_weapon/weapon/m_staff.lpc`、`/d/npc/m_weapon/weapon/m_sword.lpc`、`/d/npc/m_weapon/weapon/m_whip.lpc`（共 5 个）的 `create()` 开头 `me = this_player();` 之后无条件读 `me->query("weapon/name")` 等打造数据。房间刷新时没有人在场（`me` 为 0），或者 NPC 在别的 NPC 的命令环境里 `carry_object()` 这个模板（NPC 的 `weapon` 属性是文件名字符串），旧驱动里读出来是 0 或字符串，`switch` 照样落到 default；新驱动报 `Bad argument 1 to EFUN call_other()` / `Bad argument 1 to switch`，NPC 和它所在的房间载入不了（`--walk` 普查里一个玩家走进房间就触发）。在 `//读入数据` 之后加 `if (!me || !mapp(me->query("weapon"))) { setup(); return; }`：没有打造者就留一个没有名字的空模板，玩家打造的流程不变。

## 补回本库没有的基类文件，第二轮（2026-10-19，KB 04 §6.15、§6.18）

宏有定义、基类文件却不在档案里：继承它的对象载入时报 `Inherited file '…' does not exist!`，编译扫描看不到这一类（`scripts/lpc_missing_inherits.py` 能列出）。同系的库里有同一个文件，原样拷来（`scripts/lpc_restore_bases.py`）；基类和继承它的对象 include 而本库没有的头文件一起带来。每个基类补回后单独载入，再载入使用它的对象，载不进来、或一个用户也载不进来的撤掉了。

- `/feature/bankowner`←zzfy3：1/1 个继承它的对象载入

逐个与 HEAD 对比载入，没有退步。

## 标准整理轮，第二轮（2026-10-19，`scripts/toolkit_fix.sh`）

本库在新驱动下重扫，机械修复：2 个未使用的局部变量，2 个文件的 void 函数返回值，1 处 inherit 顺序。修后与 HEAD 逐个物件对比载入，没有退步。

## 补回丢失的标点（2026-10-19，KB 03 §4.6）

转换时丢掉的分号、逗号、引号或文件末尾的 `}`，共 2 个文件，修前 HEAD 载入失败。别的库里同路径的完好副本只比这里少几个标点，按它补回（括号里是那个库）：`/d/city2/npc/zhengmen.lpc`（jqxz2008）、`/d/oldpine/obj/leather.lpc`（es2）。修后与 HEAD 逐个对比载入：这 2 个物件全部载入，没有退步（`scripts/lpc_restore_from_twin.py`、`lpc_fix_eaten_quote.py --comma`、`lpc_fix_eof_braces.py`）。

## 旧驱动的类型宽松：缺省参数、无类型形参、数组初始化、`class` 变量（2026-10-19，KB 04 §6.19、§6.20）

原来的 MudOS 把调用少传的参数补 0、把没写类型的形参当 `mixed`、不检查变量的声明类型与初始值，也允许变量叫 `class`；这个驱动在编译时全部拒绝，整个物件载入失败。修了 1 个文件：`/d/heimuya/ren.lpc`（`scripts/lpc_round_files.py` 的修复轮：调用处补写 `0`、无类型形参补 `mixed`、`string X = ({...})` 补星号、void 函数的返回值，以及 `class` 变量改名 `pick_class`）。逐个文件在 HEAD 和改后载入对比：这些文件里 1 个原来载入失败、现在载入，没有退步。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。改动：`/d/mingjiao/shanmen.lpc`（1 处）、`/d/mingjiao2/shanmen.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 6 处）。改动：`/d/gameroom/puke-room.lpc`（4 处）、`/d/ultimate/first/small_house.lpc`（1 处）、`/std/magic.lpc`（1 处）。

## `socket` / `dumpsocket` 指令：`dump_socket_status()` 驱动里没有（2026-10-20，KB 06 §7.291）

这些巫师指令 `write(dump_socket_status());`，MudOS 的 efun 在 FluffOS 里不存在，指令编译不过。在模拟 efun 文件里补了 `dump_socket_status()`：用 `socket_status()` 排出同样的表（没有 sockets 包的构建，比如 WASM，只有表头；`scripts/lpc_add_sefun.py dump_socket_status`）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/obj/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## sefun `cat()`：缺文件时 `write(0)` 报错（2026-10-20，KB 06 §7.297）

`void cat(string file) { write(read_file(file)); }`：文件不存在（压缩包没带的欢迎/公告文件，或只有运行中的 mud 才会写的日志）时 `read_file()` 回 0，`write(0)` 在本驱动里报 `Bad argument 1 to receive()`，调用者（登录对话、`cat` 指令）被中断；老驱动什么也不打印。改成 `write(read_file(file) || "");`（`scripts/lpc_fix_cat_unchecked.py`）。改动：`/adm/simul_efun/file.lpc`。

## 翻页器 `start_more(read_file(...))`：文件缺失时 `explode(0)`（2026-10-20，KB 06 §7.300）

东方故事系的翻页器 `void start_more(string msg) { ... explode(msg, "\n") ... }` 被这样调用：`start_more(read_file(HELP_DIR + "help/topics"))`、`start_more(read_file(NEWS))`。压缩包没带的文件使 `read_file()` 回 0，`explode(0, ...)` 在本驱动里报 `Bad argument 1 to explode()`（不带参数的 `help` 指令就是这样出错的），老驱动把 0 当空文本。在 `start_more` 开头加了 `if (!stringp(msg)) return;`（`scripts/lpc_fix_start_more.py`）。改动：`/feature/more.lpc`。

## `learn`、`practice`、`study`、`selflearn`、`research`、`steal` 除以零（2026-10-21，KB 06 §7.331）

这六个命令一开头就算 `100 * me->query_explore_points() / EXPLORE_D->query_total_explore()`（`steal` 对双方各算一次）。`explored` 守护进程的存档 `/data/explored.o` 不在归档里，`explores` 是空映射，`query_total_explore()` 恒答 0；探索点只能由巫师登记（`log_explore()`，库里没有调用它的命令），所以新树里每个玩家敲这几个命令都是 `*Division by zero`（实测：`learn`、`practice`、`study`、`selflearn`、`research` 全部抛错）。`score` 对同一个除数早就写了 `EXPLORE_D->query_total_explore() ? ... : 0`，六个命令照改（共 7 处），总数为 0 时探索度按 0 算（它在熟练度上限公式里只是 `explore * 2` 一项）。实测：六个命令都给出各自的提示，控制台没有错误。逐个命令扫描时只有 `learn` 报了错：它后面的 `lockscreen` 把会话留在密码提示上，`practice` 之后的命令没有真正执行，见 KB 08 §10.16。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库现有的 NPC 文件里没有字面写成空 `chat_msg` 的（扫描只认 `set("chat_msg", ({ }))`）；守卫挡的是运行时才为空的列表和以后新增的 NPC。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/std/char/npc.lpc`、`/std/charr/npc.lpc`、`/std/charr/npcc.lpc`（共 3 个文件）。

## 存档里的 `.c` 文件名改成 `.lpc`（2026-10-21，KB 03 §4.2 第 9 项）

存档里写着 `"/d/city/npc/wei.c"` 这样的文件名；extract 时源文件已经全部改成 `.lpc`，而驱动对带扩展名的路径只认字面，`new()` / `load_object()` / `move()` 都找不到它，调用方多半把失败当成「没有这个东西」悄悄跳过。本库 1 个存档共 1 处按 `scripts/lpc_fix_save_dotc.py` 改成 `.lpc`（只改 `.lpc` 存在而 `.c` 不存在的字符串；玩家存档、备份、留言板、巫师目录和文件索引缓存不动）。改动：`/d/green/k.o`（1 处）（共 1 个存档）。

## xbtxiii：谢剑的 `init()`、杨过和小龙女的两个 call_out（2026-10-21，KB 06 §7.348）

`xiejian.lpc` 的 `init()` 读没赋值的 `me` 和 `ob`：每个进房间的人都抛错，`add_action("do_name", "杀")` 也没执行；补 `ob = this_player(); me = this_object();`。`xiaolongnv.lpc` / `yangguo.lpc` 的 `dest_it()` 对没赋值的 `object *npc` 取下标（补 `npc = all_inventory(environment(this_object()))`）；`come_shuitan(object me)` 声明了 `xiaolongnv`、`yangguo` 两个局部，而 `call_out("come_shuitan", 3, me, yangguo, xiaolongnv)` 把它们当参数传：参数表补上，局部去掉。改动：`/d/ultimate/first/npc/xiaolongnv.lpc`、`/d/ultimate/first/npc/yangguo.lpc`、`/d/village/npc/xiejian.lpc`。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 46 条注册（25 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/d/baituo/npc/snaker.lpc`（`do_buy`、`do_vendor_list`）、`/d/biao/gmaster.lpc`（`do_accept`）、`/d/city2/npc/cheng.lpc`（`do_buy`、`do_vendor_list`）、`/d/city2/npc/hu.lpc`（`do_buy`、`do_list`）、`/d/city2/npc/jia.lpc`（`do_buy`、`do_list`、`do_sell`、`do_value`）、`/d/city2/npc/smith.lpc`（`do_buy`、`do_list`）、`/d/city2/npc/xiaofan.lpc`（`do_buy`、`do_list`）、`/d/fy/gamebox22.lpc`（`do_flee`）、`/d/fy/gamebox23.lpc`（`do_flee`）、`/d/fy/npc/governor.lpc`（`give_quest`） 等共 25 个文件。最多的函数名：`do_buy` 10 处、`do_list` 8 处、`give_quest` 5 处、`do_sell` 3 处、`do_vendor_list` 2 处。改名：`/obj/prize/pet.lpc` 的注册 `do_order` → `do_oxrder`（文件里定义的是 `do_oxrder`）。没有动（读过）：`/d/ny/npc/a_book.lpc` 的 `do_query`（对象本身编译不过，登记留着，等对象能加载再处理）、`/d/ny/npc/a_book.lpc` 的 `do_bank`（对象本身编译不过，登记留着，等对象能加载再处理）、`/d/shenlong/npc/zhang3.lpc` 的 `do_join`（对象本身编译不过，登记留着，等对象能加载再处理）、`/d/snow/npc/a_book.lpc` 的 `do_query`（对象本身编译不过，登记留着，等对象能加载再处理）、`/d/snow/npc/a_book.lpc` 的 `do_bank`（对象本身编译不过，登记留着，等对象能加载再处理）。

## 基类的 `add_action` 登记：处理函数只在后代里定义，基类自己被加载时报错（2026-10-21，KB 06 §7.349）

房间、NPC、公告板这类基类，`init()` 里登记的 `add_action("函数", "动词")` 的函数只由继承它的后代定义；基类对象自己被直接加载（房间可以走进去、NPC 可以克隆）时，访客输入这个动词，驱动报 `*Function for verb 'x' not found.`（第一轮扫描把这些当成“有后代定义，是活的”放过了，`scripts/lpc_verify_handlers.py` 在基类对象上跑 `function_exists()` 才看出来）。登记前加 `if (function_exists("函数", this_object(), 1))`（第三个参数 1：默认 `function_exists()` 把 `protected` / `private` 函数当作没有定义），后代照常登记。共 1 处、1 个文件（`scripts/lpc_fix_dead_add_action.py --guard`）：`/d/manglin/npc/master.lpc`（`give_quest`）。

## 对象路径里的 `..`：`new(__DIR__ "../obj/x")` 报 `Read access denied`（2026-10-22，KB 06 §7.351）

`__DIR__` 是当前文件所在目录（带结尾斜杠），`__DIR__ "../obj/x"` 就是 `/d/zhiye/npc/../obj/x`；驱动的 `legal_path()` 不接受带 `..` 的路径，`new()` / `load_object()` 直接抛 `*Read access denied.`（实测，`find_object()` 对它答 0）。走库自己的 `carry_object()` / 房间 `objects` 表的路径，库的基类会先规范化，能用；直接把路径交给 `new()` / `clone_object()` / `load_object()` / `move()` 的不行，调用到那一步才报错。改成规范化后的绝对路径（`scripts/lpc_fix_dotdot_dir.py --direct`）：`/d/wudang/npc/xiaocui.lpc`（`__DIR__ "../obj/nuerxiang"` → `"/d/wudang/obj/nuerxiang"`）。

## 调用了、但这个库自己的守护进程里没有的函数（2026-10-22，KB 06 §7.354）

`MACRO->函数()` 调用的函数在这个库的守护进程里不存在：`call_other()` 对不存在的函数不报错、只返回 0，所以这些功能（时间显示、昼夜事件、名字检查、价格文字……）一直没起作用。同一血统另一个库的同名守护进程里有这些函数，原文照抄到本库守护进程末尾（`scripts/lpc_port_function.py`；调用处传的参数个数、函数体用到的函数 / 全局变量 / 宏 / 字符串键都在本库里有，已核对；守护进程在 HEAD 和工作区都能加载，每个函数用固定参数各调用一次：HEAD 返回 0，现在返回正常的值）：`/adm/daemons/chinesed.lpc` ← aoxiangtianji：`chinese_month()`（2 处调用）。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 还剩 4 个函数没有补（inquiry 2, other 2）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/d/chaoting/bingying/npc/zhiqin_bing.lpc`:`back_home`、`/d/goathill/npc/obj/dead_leech.lpc`:`eat_tonic`、`/d/huashan/npc/teller.lpc`:`tell_fortune`、`/d/obj/dead_leech.lpc`:`eat_tonic`。

## 运行期目录 `log/nosave` 不存在，写日志的 `write_file()` 直接报错（2026-10-22，KB 03 §4.3 补充）

这个库的 24 个文件里有 31 处 `write_file("/log/nosave/...")` / `log_file("nosave/...")`（`static` 改 `nosave` 时连字符串里的日志路径一起改了，原来是 `log/static/`）：`nosave/CRASHES`、`nosave/SUICIDE`、`nosave/WIZ_EDIT` 等。压缩包和站点包里没有这个目录，`write_file()` 在目录不存在时抛 `*Wrong permissions for opening file /log/nosave/... for append. "No such file or directory"`，调用它的函数（杀人记录、重启记录、`call` 日志……）当场中断。把 `log/nosave` 记进 `scripts/wasm_keep_dirs.txt`（站点和 pristine 树都按它建空目录）；没有把字符串改回 `static`。证明（`scripts/lpcc_eval.py`，`catch(write_file("/log/nosave/ZZTEST", ...))`，fqyy2 / hy5 / bmxkx2001 的新进程）：补目录前报上面的错误，补后写成功。

## 读不到的留言板：`"/clone/board/x"->foo();` 在 `create()` 里报错（2026-10-22，KB 06 §7.357）

xkx 系的房间在 `setup()` 之后写 `"/clone/board/gaibang_r"->foo();` 来加载留言板（`foo()` 本来就没有定义，只为了触发加载）。这个库没有这个文件，`call_other()` 报 `*call_other() couldn't find object '/clone/board/gaibang_r'`，对象留在内存里、`load_object()` 却抛错：玩家第一次走进房间就看到错误，写在 `create()` 中间的还会切掉后半段。`scripts/lpc_fix_missing_foo.py` 把 9 条单独成行的语句（`/clone/board/emei_b`、`/clone/board/guiyun_b`、`/clone/board/gaibang_r`、`/clone/board/kedian_b`；`/d/emei/hcaguangchang.lpc`、`/d/guiyun/qianyuan.lpc`、`/d/jiangnan/yangzhou/gbxiaowu.lpc`）注释掉并写明原因（别的房间里同样的语句本来就是作者自己注释掉的）。证明和 45 个库的整体加载检查见 KB 06 §7.357。

## 不带前导斜杠的物品路径：缺失物品的 `new()` / `carry_object()` 调用链加了保护（2026-10-22，KB 06 §7.73 补充）

`carry_object("d/city/obj/jiasha")->wear();` 这类路径不带前导斜杠的写法在这个驱动里按根目录解析（`new("d/city/obj/changjian")` 能加载 `/d/city/obj/changjian`），所以和带斜杠的一样：文件不在压缩包里时 `new()` 返回 0，`->wear()` 在 0 上报 `Bad argument 1 to EFUN call_other()`，整个 NPC 加载不了。此前的保护工具把这种写法当作「相对当前目录，没法判断」跳过了。2 个文件里 2 处（`clone/misc/cloth`、`d/city/obj/gangjian`）改成带保护的块（`scripts/lpc_guard_carry_object.py`）。 对这 2 个改动文件做加载检查（HEAD 与工作区对比）：HEAD 能加载 0 个，现在 2 个（新增可加载 2 个，回归 0 个）。

## `(: 函数名 :)` 指针指向本库没有的函数：只含这个指针的行加了注释（2026-10-22，KB 06 §7.355 补充）

`inquiry` / `item_desc` / `chat_msg*` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：用到时（`ask`、`look`、NPC 闲聊）驱动抛 `*Undefined lfun pointer called: 函数名`，这一拍心跳的后半段被跳过。这些函数没有可以补回的来源（别的库同一路径的文件里没有，或者它还要用本库没有的东西），所以 2 个文件里 2 行只含这个指针的行（`"回去": (: back_home :),` `"算命": (: tell_fortune :),`）加了注释，原文保留并写明原因，这一项当作没有这个话题 / 物品 / 闲聊条目（`scripts/lpc_fix_dangling_lfun.py`；`#include` 的文件在库里缺失的对象、指针不在整行上的写法没动）。 前提（`function_exists()`）和加载检查（HEAD 与工作区对比，本库改动的 `.lpc` 文件）的结果见 KB 06 §7.355：没有一个回归。

## 汉字按字节切片的老写法没有换成按字符：改法名 `"澄" + name[2..3]`、辈分判断 `name[0..1] == "澄"` 等 38 处（2026-10-22，KB 06 §7.360）

原档按字节算字符串区间（一个汉字 2 字节）：`name[2..3]` 是名字的第二个字，`name[0..1] == "澄"` 问名字是不是以「澄」开头。转成 UTF-8 之后，这个驱动的区间和 `strlen()` 都按字符算（`strlen("澄观")` 是 2，`"澄观"[0..1]` 是两个字），老算术原样留着、意思全变：拜入少林 / 武当 / 峨嵋等派的玩家被改成错误的法名（二字名 `张三` 变成一个字的 `澄`，更长的名字取到第三个字）；各派掌门的辈分判断（`name[0..1] == "澄"`）永远不成立。

本库 38 处（27 个文件）：拼名字的赋值 21 处、与汉字常量比较 17 处。例：`name[2..3]` → `name[1..1]`（`/d/shaolin/npc/cheng.h:156`）；`name[0..1]` → `name[0..0]`（`/d/shaolin/npc/qf.lpc:127`）；`name[0..1] == "慧"` → `name[0..0] == "慧"`（`/d/shaolin/npc/cheng.h:140`）。`scripts/lpc_fix_gbk_slice.py` 把下标按字符重算（社区的 UTF-8 版 `xkx100utf8` 里就是同样的写法，作对照）；没有改的：截断（`name = name[0..7]`，现在最多 8 个字，只是放宽）、ASCII 的区间（`fname[0..3] == "room"`、`ctime(time())[4..19]`）和上下文看不出是汉字的区间。证明（`scripts/lpcc_eval.py`，bixiecanyang；其余各库是同一份文本）：让澄字辈掌门 `attempt_apprentice()` 一个名叫「张三」的访客，HEAD 的法名是 `慧`，改后是 `慧三`；抽样 28 个库的 HEAD / 工作树加载对比 0 退步。工具不幂等（`[0..3]` 折半得 `[0..1]`，又是对齐区间），改过的文件记在 `scripts/gbk_slice_converted.txt`，不要重跑。

## 长度检查按字节写，旁边的提示按汉字写：6 处（2026-10-22，KB 06 §7.362）

老档的 `strlen()` 数字节（一个汉字 2 字节），转成 UTF-8 后它数字符：提示写「必须是 2 到 6 个中文字」的检查还是 `strlen(name) < 4 || strlen(name) > 12`，于是两三个字的房名、帮会名、群名、聊天室名、称号被提示自己说允许的那句话拒绝，上限却是提示的两倍；留言板的标题检查 `i < 4 || i > 24 || i % 2` 还会拒绝所有奇数个字的标题（`post 你好吗`）。本库 6 处（3 个文件）：`if ((strlen(name) < 2) || (strlen(name) > 40)) {`（`/d/fy/npc/petowner.lpc:151`）。`scripts/lpc_fix_strlen_gate.py` 以提示为准：条件里每个 `strlen` 门槛都恰是提示所说数字的两倍才折半，存长度的变量（`i = strlen(arg);`）的门槛和 `|| i % 2` 奇偶项、其后循环的 `i % 2 == 0 &&` 一并处理；提示里有英文 / 字母 / 字节的不动。证明（`scripts/lpcc_eval.py`，bxsj 的留言板，求值对象继承 NPC 并重写 `edit()` 记录调用，`command("post 标题")`）：HEAD 拒绝「你好」和「你好吗」、放行 23 个字的标题；改后接受前两个、拒绝第三个；shenmo 的 `named.lpc invalid_new_name("张三")`：HEAD 回 `名字只能是2-4个中文字。`，改后回 0。抽样 24 + 15 个库的 HEAD / 工作树加载对比 0 退步。

## 按字节写的汉字循环、茶馆猜诗和同盟频道标题（2026-10-23，KB 06 §7.363）

老档按字节做「一个汉字」：`while (i--) if (i % 2 == 0 && !is_chinese(name[i..<0]))` 只检查偶数下标，奇数位上的拉丁字母（`张a`）会过；茶馆猜诗 `mixup()` 用 `strlen(str)/2` 再 `j=j+j`、`str[k..k+1]` 交换两字节；泥潭系 `channeld` 的 `switch (strlen(fname)) case 4/6/8/10` 和 `strlen(family)==4/6` 按字节长度给同盟 / 门派名加空格。本驱动的 `strlen()` 和区间都按字符算。`scripts/lpc_fix_byte_char.py`：去掉奇偶项、把区间改成 `name[i..i]`，按字符重写 `mixup()` 并把 `strlen(first)>=14` 折成 7，频道标题的 case / 门派长度改成字符数（对照 aoxiangtianji）。本库 汉字循环 / `is_chinese` 区间 4 个文件。证明（`scripts/lpcc_eval.py`）：sjplii 的 `check_legal_name` 在 HEAD 接受「张a」、改后拒绝，两边都接受「张三」；xkx100 的 `clubpoem->mixup("离离原上草")` 得到「离离原草上」（真交换汉字）；nitan_san 两字同盟名得到 `【 兄  弟 】`。关键对象加载通过。

## 血条 / 表情标题按字节算显示宽度（2026-10-23，KB 06 §7.365）

老档把汉字当两字节：`bar_string[0..(val * N / max) * 2 - 1]` 把「格数」换成字节下标，半格血条在本驱动（按字符算区间）上会整条画满；巫师表情 `edemote` 的 `repeat_string("─", 13 - (strlen(emotion) / 2))` 也会少减汉字宽度。`scripts/lpc_fix_display_pad.py`：去掉 CJK 血条 / 空白条上的 `* 2`（`jings`/`qis` 赋值和 `blank_string3[0..(23-a)]` 的 23→11 一并改），表情标题去掉 `/ 2`；ASCII 空格的 `none_string` / `empty_string` 仍保留 `* 2`（一格两个空格）。本库 2 处（1 个文件）。证明（`lpcc_eval.py` hhsj）：`tribar_graph(6,9,12)` 在 HEAD 画出整条 12 个■，改后为 6 个■+3 个□；麻将 `strlen(tempB)/2` 是两字符牌码，未改。


## jmqshenmu 截断 init（2026-10-27，KB 04 §6.25 Also）

`d/mingjiao/jmqshenmu` 在 `void init() {` 处文件结束。补上 `}` 使房间可加载（本库未收齐 climb/`jmqdating` 时不做内容补写）。证明：HEAD 失败；改后加载。

## 深度功能测试（2026-10-27，§6.25 tell_object 缺 me（自动放弃/愿否））

一参 `tell_object("…")` 在已有 `me` 时改为 `tell_object(me, "…")`（xiaolongnv.lpc, yangguo.lpc）。证明：抽样 city / xiaolongnv 加载。

## 深度功能测试（2026-10-27，§6.25 bahuang throw 缺 me + xiaolong 愿否已并入 190）

`kungfu`/`daemon` `bahuang-qiangfa/throw` 的 `tell_object("你手中拿的不是枪…")` 改为 `tell_object(me, …)`。证明：改后加载。

## 深度功能测试（2026-10-27，§6.25 one-arg tell_object 残渣）

alarm_condi / wuzitianshu：补 `me`。


## 深度功能测试（2026-10-27，§6.25 one-arg message_vision）

`message_vision("…")` 补第二参（`me` / `TP` / `this_player()`）。


## 深度功能测试（2026-10-27，§6.10 未知 pragma save_binary/optimize）

删除本库中 FluffOS 不认的 `#pragma save_binary` / `#pragma optimize…` 行。

