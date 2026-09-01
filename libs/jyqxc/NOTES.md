
## WASM 修复摘要（迁移自 meta.json 的 group_note）

金庸题材 mudlib（金庸群侠传），游戏内标题为"The Story of Hero"。修复了两个 bug：feature/name.lpc 的 short() 呼叫 capitalize(query("id")) 没做保护——只要有物件在没设置"id"属性的情况下走到 short()，就会崩溃报"Bad argument 1 to capitalize()"，这份档案里约 49 个留言板分身（data/board/*.o 存档用一种这个驱动的 restore_object() 解析不了的旧式紧凑二进制编码，魔术字节"#inh"/"?inh"）全都会撞上这个问题——"Illegal file format"失败在抛出异常之前会先清空物件的 dbase 映射（包括刚在 create() 里设置好的"id"），导致每次 look 一个摆着留言板的房间都会崩溃。已改成让 short() 的兜底逻辑用 stringp(id) 判断，而不是重新格式化这约 49 个旧式存档档案。另外通过 adm/etc/wizlist 把 fluffos/Mud2026Adm 播种为 (admin)。没有发现中文名字/宏定义/指令表相关的 bug（is_chinese() 本来就用正确的 Unicode 码点区间；check_legal_name() 的 i%2==0 隔字检查会漏检奇数位置的非中文字符，但从不会拒绝真实的中文名字，所以保持原样）。完整的注册→look→score→quit 流程在排版格式化前后各验证过一次；管理员流程通过可见的"目前权限：(admin)"显示验证。格式化工具还原了 3 个损坏的档案，都是 ASCII 地图（d/huashan/map.lpc、d/shaolin/npc/obj/map.lpc 及其在 d/shaolin/obj/map.lpc 下的副本）——和这条血统里手足档案同样的分词器混淆模式。

## 深度功能测试（§10.7，2026-08-04）

原生 driver（端口 40129）跑了一遍超出注册流程的完整游玩。读了
`doc/help/newbie`——比这批档案里常见的官方模板丰富得多，是一篇由
玩家（武痴/Hop）写的天资/练功攻略，明确解释了 `set wimpy`（逃跑系
数）、`fight`（较量，双方气/精跌到 50% 会自动停手）vs `kill`（死战，
打到一方死亡为止，"倘若对手比你强，你便会十分危险"）的区别——这份
文档直接解释了前两轮（`fy330`/`fy2mg`）会话里反复观察到的"自动逃跑
安全网"机制的设计意图和触发阈值。

**主动检查命中 2 处**：`adm/daemons/logind.lpc` 单一姓名输入路径
（没有随机取名的平行分支）紧挨在 `ob->set("name", arg)` 之前的
`printf("%O\n", ob)` 调试残留（AGENTS.md §7.34）；同一文件
`enter_world()` 里食物/饮水初始化用错对象的经典 §8.9 bug——
`ob->query("age") == 14` 应为 `user->query("age")`，紧跟在
`user->setup()` 之后。两处都已修复；注册后食物/饮水显示 279/280
（接近满值），确认 §8.9 修复生效。`command_hook` 有两份拷贝
（`feature/command.lpc` 是 `F_COMMAND` 宏实际指向的活文件，
`home/command.lpc` 是未被引用的死拷贝），两份都是干净的
`nomask`，没有 `private`，不是 bug。没有 MESSAGE_D-> 未防护调用或
stat/water 键名不一致的问题。

**注册流程**：`get_id` → `confirm_id`(y/n) → `get_name` → `new_password`
→ `confirm_password` → `get_gift`（随机天赋展示，y/n 决定接受或重
摇，不是选择固定档位）→ `get_email` → `get_gender` →
`enter_world()`，没有民族选择这一步（和 `fy330`/`fy2mg` 不同）。
注册了测试角色（秦冬 / id `qindongxi`），落在"客店"，自带专属邮箱
（"秦冬的信箱"）。

**邮件/留言板测试**：`look mailbox` 正确列出 mail/forward/from/
read/discard 指令说明；客店留言板 `post`/`read new` 正常工作
（用内建列编辑器"~e"/"~q"/"."结束的输入方式），验证完毕后
`discard` 掉了测试留言，没有留下痕迹。

**战斗测试：真实死亡+复活全流程现场验证（本项目 §7.68 系列里少见
的完整现场复现）**：客店门外北大街站着"欧阳克"（金庸小说里的反派
角色，白驼山少庄主）。按新手指南的建议先用较为"安全"的 `fight`
指令交手——结果一招"白蛇吐信"就直接把测试角色从满血打死，"较量"
的 50% 自动停手阈值根本来不及触发（这是内容强度问题，欧阳克本来
就不是新手陪练对象，不是 bug，故未做任何代码改动）。角色死亡后被
送到"鬼门关"，"实习无常"（本轮刚修复的 `newgargoyle.lpc`）和
"白无常"同时在场。**没有主动断线或制造中断**，让复活序列完整跑完，
重连后确认角色已经复活、站在"武庙"，`score` 显示精/气降到
40%（符合死亡惩罚），食物/饮水满格——这是目前这一系列里第一次
（`bixiecanyang`/`fy330`/`fy2mg` 都因为自动逃跑机制没能真正死亡）
现场完整验证了 §7.68 修复后undisturbed 路径的正确性，虽然仍然没有
专门复现"复活过程中被强制挪走"这个原始触发场景。

**死亡/复活系统：发现并修复 §7.68 的又一实例，外加一个全新变体
（新增归档条目）**：`d/death/npc/{newgargoyle,bgargoyle,wgargoyle}.lpc`
（实习无常/黑无常/白无常，和 `bixiecanyang`/`fy2mg` 同宗的死亡系统，
这里多了"实习无常"这个第三种鬼差角色，"白无常"死讯提示还带一段随
机游走的 chat_msg）都有同样的 `if (!ob || !present(ob)) return;`
复活软锁死守卫，`bgargoyle.lpc` 和 `fy2mg` 一样在多阶段复活循环前
多一段"活人闯入阴间就攻击"的判断。三个文件都已按已验证的修法拆分。

**全新变体，与死亡系统无关**：`d/shaolin/npc/yu-zu2.lpc`（"狱卒"，
少林寺地牢的看守）的 `death_stage()` 是同一个 bug 类在完全不同场
景下的实例——这不是阴曹地府的复活序列，而是少林寺对犯规弟子的"关
禁闭"惩罚机制：多阶段 `call_out` 链每 60 秒推进一次狱卒的台词，最
终把人放出监狱（`move("/d/shaolin/woshi1")`）。同样的
`if (!ob || !present(ob)) return;` 守卫意味着服刑期间任意一瞬间
"人不在场"（不只是真正离线，也可能是暂时的场景切换）就会让这个人
永久放弃出狱资格，卡在监狱里出不来，没有任何提示。已用同样的拆分
修法处理。这说明 §7.68 这个 bug 类不止出现在"阴曹地府"这一种叙事
包装里，任何"多阶段 call_out 链 + `!present(ob)` 兜底守卫"的组合都
值得同样检查——已经据此更新 AGENTS.md §7.68 的归纳表述。

`quit` 正常退出（"当你下次连线进来时，会从这里开始。欢迎下次再
来！"），formatter 检查（五个改动文件均已是干净格式，无需重排
版）、`git status --short libs/jyqxc/` 复查均确认改动范围干净——
只有五处源码修改是跟踪变更，测试角色的新存档保持未跟踪、未提交。
`debug.log` 全程没有真实的 `error:`/`denied`/`Bad argument`/
`Too deep recursion` 行。


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

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 18 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## §7.100 扫描修复（`ROOM` 基类多余 `replace_program()`）

`#define ROOM "/inherit/room/room"`：删除 803 处多余的、独立成行的
`replace_program(ROOM);`（保留 `inherit ROOM;`），与 `jqxz2008`
系列同一血统同一形状。`clone/misc/roommaker.lpc` 同样有两套模
板——"造一间空房间"的 heredoc 本来干净，"克隆我所在的房间"命令的
字符串拼接模板把同一枚多余的 `replace_program(ROOM);` 烤进了每一
个新克隆的房间，已同步修正。已用 `build-debug` 驱动干净启动验证
（0 个新增编译错误，端口正常监听）；未做完整 §10.7 深度游玩测
试。预先存在的 `work/data/{login,user}/q/qindongxi.o` 未跟踪测试
存档未受触碰。

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

## §10.7 深度功能测试第二轮（2026-09-01）：门派拜师、商店买卖、PvP `kill`
——四处未受保护的 `write_file()`/`log_file()` 写入不存在的
`/log/nosave/` 目录，导致真实死亡结算和玩家互殴全部崩溃

本轮测试角度和 2026-08-04 那次刻意不同：全程用原生 Python socket
脚本（未用 `scripts/tmux_mud.sh`），注册了新测试角色（秦风武 /
`qinfengwu`），额外注册了一个 `fluffos`/`Mud2026Adm`（按
`adm/etc/wizlist` 早先播种的凭据登记，登记后自动获得 (admin) 权限，
用作第二条并行连线，负责 `goto`/`summon`/`call` 等测试用快捷操作，
不代表这是给普通玩家开的后门）。测试了上一轮明确跳过的三个角度：

**拜师/门派测试**：`cmds/skill/bai.lpc`（`apprentice`/`bai` 指令，
`cmds/skill/apprentice.lpc` 是字节相同的拷贝）配合
`feature/apprentice.lpc`。`d/baituo/npc/li.lpc`（白驼山"李教头"）是
一个会自动收徒的 NPC（`attempt_apprentice()` 直接 `command("recruit
...")`，不需要额外确认）。现场对秦风武执行 `bai li`，一次成功——
`score` 正确显示"白驼山派第三代弟子"、"你的师父是李教头"，
`family/generation`（师父的 2 代 +1）与 `family/master_name` 都正确
写入。同一房间东侧的"练功房"里还有个"教练"NPC（本局首次被访问），
连带验证了下面提到的 §7.19 检查，干净。

**商店买卖测试**：`d/city/zahuopu.lpc`（杨永福，`F_DEALER`，只挂了
`buy`/`list` 两个 `add_action`，没挂 `sell`）用来买东西，
`d/city/dangpu.lpc`（唐楠，`F_DEALER` + 自己额外挂了
`sell`/`value`/`redeem`）用来卖东西——先用 `value`/id 关键字踩了个
自己的坑："草鞋"的 `id()` 列表是 `({"sandals","cao xie","xie"})`，
没有不带空格的 `"caoxie"`，第一次拿这个打的 `buy caoxie` 自然失败
（`present()`/`is_vendor_good()` 找不到东西，不是 bug，是我的指令
打错了）。改用 `buy sandals` 后走通了完整一轮：`杨永福` 处
"你从杨永福那里买下了一双草鞋。"（花掉 1 两白银），带着这双草鞋走
到 `dangpu`，`sell sandals` 得到 "你卖掉了一双草鞋给唐楠。"
并进账 70 文铜板，跟 `feature/dealer.lpc::do_sell()` 的
`value*70/100` 折算一致。全程 `debug.log` 干净。

**§7.19 检查（AGENTS.md §7.19：`init()`→`setup()`→
`enable_player()` 链条造成同栈重入）**：静态审查全档案（`grep` 所有
`enable_player(`/`enable_commands(`/`setup(` 调用点，脚本化提取每个
`void init()` 函数体检查是否直接调用了 `setup()`/`enable_player()`/
`enable_commands()`）——零命中；`feature/damage.lpc::revive()` 里那
处 `this_object()->enable_player();` 是从 `call_out("revive", ...)`
触发的独立调用栈，不是 `init()` 链条内重入，符合 AGENTS.md §7.19
"合法的 disable/re-enable 场景"描述，不是 bug。现场访问的全新
NPC（欧阳克、流氓×2、流氓头、菩提子、杨永福、唐楠、李教头、
"教练"）首次进入房间时全部干净，没有 "Too deep recursion"。

**发现并修复的真 bug——AGENTS.md §7.x 已知模式家族（`log_file()`/
`write_file()` 写入不存在的 `/log/nosave/` 目录，异常未捕获，整段
调用链被吞掉）在本档案里至少 4 处，此前完全未修**：

1. `cmds/adm/call.lpc`（`cmds/arch/call.lpc` 是字节相同拷贝，两份都
   活跃，分别对应 `(admin)`/`(arch)` 两级指令搜索路径）——管理员
   `call <玩家>-><函数>(...)` 指令，只要目标是玩家，就会先执行
   `log_file("nosave/CALL_PLAYER", ...)`，此调用先于真正的
   `call_other()`。现场复现：`call qinfengwu->die()` 直接抛出
   `*Wrong permissions for opening file /log/nosave/CALL_PLAYER for
   append. "No such file or directory"`，`die()` 根本没被调用到。
2. `adm/daemons/combatd.lpc::killer_reward()`——**AGENTS.md 在 6th+
   实例那条已经点名"`jyqxc`/`jyqxc2`... 携带同样未受保护的
   `write_file()`... 截至目前仍未修复"**，本轮就是把这条已知欠账
   补上。写入点在 `if (userp(victim)) { ... if (userp(killer))
   write_file("/log/nosave/KILL_PLAYER", ...) ... }` 内，被 gate 在
   "玩家杀玩家"分支，所以之前两轮打 NPC 的测试从没触发过。真正
   PvP 死亡时，这次 `write_file()` 抛出的异常会把 `killer_reward()`
   连同调用它的 `die()` 一起中断在 `this_object()->move(DEATH_ROOM)`
   之前——受害玩家会卡在"已昏迷/已死亡但从未真正移出房间"的状态，
   与 AGENTS.md 描述的"死亡循环"是同一类症状。
3. `cmds/std/kill.lpc`——`kill <目标>` 指令本体，`me->kill_ob(obj)`
   （发起攻击）之后紧跟着对玩家目标做
   `write_file("/log/nosave/ATTEMP_KILL", ...)`，同样没有保护。现场
   复现：`kill fluffos`（对方也是真玩家）打过去，`me` 一方攻击已经
   生效，但异常把 `obj->fight_ob(me)`（受害者的反击注册）和警告
   提示整段吞掉——也就是说，**任何玩家对任何玩家使用 `kill` 指令，
   受害一方永远不会反击**，是个非常常见指令路径上的真实功能性
   bug，不是罕见分支。
4. `cmds/skill/bai.lpc` / `cmds/skill/apprentice.lpc`（字节相同）——
   `attempt_apprentice`/`recruit` 流程里，专门给"风清扬"这个隐藏
   NPC 准备的徒弟计数彩蛋逻辑，`write_file("/log/nosave/FENG", ...)`
   同样没保护；顺手发现同一行还有一个独立的运算符优先级 typo——
   `me->query("family/master_id" == "feng qingyang")` 把 `==`
   写在了 `query()` 的参数里面，实际上先算出恒假的字符串比较，再拿
   结果（永远是 `0`）去调 `query(0)`，导致这个分支根本永远进不去
   （这条彩蛋逻辑本来就因为这个 typo 而完全死代码，`write_file()`
   的 bug 本身反而从未被触发过）。

**修复方式**：优先修共享入口——`adm/simul_efun/file.lpc` 的
`log_file()` 本来就是裸 `write_file(LOG_DIR + file, text)`，同一份
文件里下面几行就有现成、正确、但从未被用到的 `assure_file()`
辅助函数（跟 AGENTS.md 记录的其它几个姊妹档案一模一样的"帮手函数
就在旁边却没人用"形状）。把 `assure_file()` 挪到 `log_file()`
前面定义（避免同驱动下"函数须先声明才能调用"的编译顺序坑，
AGENTS.md 已记录过这个坑），再让 `log_file()` 内部先
`assure_file(LOG_DIR + file);` 再 `write_file(...)`——这一次性修好
了全档案所有经由 `log_file()` 写 `nosave/` 的调用点（`securityd.lpc`
的升级日志、`master.lpc`/`adm/single/master.lpc` 的崩溃日志、
`suicide.lpc`、`cmds/arch|adm/purge.lpc`、`call.lpc` 两份拷贝等），
不用逐一点名修。上面第 2/3/4 条是绕开 `log_file()` 直接裸调
`write_file()` 的独立调用点，各自在 `write_file()` 前补一行
`assure_file("/log/nosave/XXX");`；第 4 条顺带把误放的 `==`
挪回 `query()` 外面。

**现场验证（修复后重启 `build-debug` 驱动）**：
- `call qinfengwu->die()` 不再抛异常，返回 `= 0`；`/log/nosave/`
  目录被自动建出来，`CALL_PLAYER` 文件正确写入一行记录；被强制
  处死的秦风武完整走完"死了→鬼门关（实习无常+白无常五段对话，
  每段 5 秒 `call_out`）→功德箱一闪→复活于武庙"全流程，`score`
  显示精/气降到约 16%（符合死亡惩罚），`实战经验` +1。
- 用 `age_modify` 字段把 `fluffos` 的有效年龄推过 15 岁下限
  （`kill` 指令自带一个"未成年玩家禁止被 kill"的设计性门槛，
  跟本次要修的 bug 无关，纯粹是测试需要绕开——顺带确认
  `clone/user/user.lpc::update_age()` 每次 `heart_beat` 都会用
  `14 + age_modify + mud_age/86400` 重算 `age`，直接 `set("age",
  N)` 几秒内就会被冲掉，这是有意的"在线时长决定年龄"机制，不是
  bug），随后现场发起一场真正的玩家对玩家 `kill fluffos`：多回合
  拳脚交锋消息正常双向输出，秦风武被打到昏迷倒地
  （`unconcious()`），确认 `last_damage_from` 记录为 `fluffos` 后
  用 `call qinfengwu->die()` 补一刀触发真正死亡结算——
  `killer_reward()` 的玩家互杀分支完整跑完，谣言频道正确广播
  "秦风武被福来福杀死了"，`/log/nosave/KILL_PLAYER` 与
  `/log/nosave/ATTEMP_KILL` 都正确写入，全程 `debug.log`
  零新增运行时错误（只有已知的、无害的首次编译告警噪音）。

**断线/重连对照测试（本轮新增角度，上一轮明确没测）**：用
`call qinfengwu->die()` 触发一次死亡，让"实习无常"五段对话跑到
第二段左右时主动断开测试连线（模拟真实掉线），空等超过一个
`call_out` 周期后重新登录——`death_stage()` 的
`if (!ob || !present(ob)) return;` 单次判定（此前 §7.68 更正说明
里明确保留、判定为设计而非 bug 的写法）在断线期间因为角色对象本身
仍然 `present()` 在鬼门关房间里（断线不移除角色，只是标记
"断线中"）而完全不受影响，对话链在后台正常继续推进，重连后
`look`/`score` 都显示已经复活、状态正常——没有新问题，符合预期。

**范围说明**：本轮修复严格限定在"未受保护的 I/O 导致崩溃"这一类
程序性 bug（并顺手带了一个同一行上的运算符优先级 typo），没有触碰
任何战斗强度/门派设定/NPC 性格等内容设计；`kill` 指令自带的
"未成年玩家保护"门槛、`age_modify`/`mud_age` 计龄机制均予保留，
只是测试时借用来快速绕过门槛，不代表对其做了任何修改。
