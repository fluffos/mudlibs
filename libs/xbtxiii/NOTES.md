
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
