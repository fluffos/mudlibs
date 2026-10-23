
## WASM 修复摘要（迁移自 meta.json 的 group_note）

ES2/金庸血统 mudlib，游戏内标题为"海洋II"（Ocean II）。修复的 bug：（1）过时的 MASTER_OB/SIMUL_EFUN_OB 宏指向 /adm/single/ 下的死代码副本，而不是真正的 /adm/obj/ 档案（config.fluffos 里指定的那份，§7.56 类）；（2）§7.54 类的 sscanf(read_file(缺失档案)) 崩溃，出现在 logind.lpc 的 howmany_visitor()/howmany_card() 读取全新安装下不存在的 /log/mud/MUDVISITOR 和 GIFTCARD；（3）新的 §7.54 补充案例：uptime.lpc 的 LASTCRASH 显示里 write(read_file(缺失档案)) 崩溃，导致英文名字提示根本不会出现（没有编译错误，没有可捕获的异常——静默阻止了整个注册流程的开始）；（4）新增 AGENTS.md §7.63：quit.lpc 的 new('/clone/topten/magic-rice') 缺少其它所有同类呼叫点（top10.lpc、topboard.lpc、topten.lpc、topdel.lpc——最后这个档案甚至留了一句注释承认这个确切的失败）都有的防御性判断 if(ob=new(...))，导致每次退出游戏都会因为对 int 0 做了一次错误的 call_other 而崩溃——已比照其它同类呼叫点的写法修复，而不是去深究 new() 失败的根本原因（深入调查确认档案本身编译干净，create() 甚至从未真正开始执行——这是一个原始档案本来就有、原作者已经在除这一处之外的所有地方都防御过的驱动/mudlib 特性）。管理员账号的引导方式偏离了常规模式：securd.lpc 在 restore_list() 里直接硬编码了一个引导用管理员 id "wuyou"（set("wiz_status/wuyou","(admin)")），而不是像本合集大多数档案那样使用纯文本的 adm/etc/wizlist 档案。管理员账号以 id "wuyou"（中文名"无忧"）、密码 Mud@2026 注册，游戏内"目前权限：(admin)"显示确认生效。完整的注册→look→score→quit 流程在排版格式化前后各验证过一次，用的是真实中文名字。格式化工具发现 1 个档案（cmds/usr/setbak.lpc）在一段 heredoc 帮助文字块里有真正的损坏（每个中文字都被重新加了空格）——已用 git checkout 还原。

## 深度功能测试（§10.7，2026-08-05）

- **printf 调试残留**：`adm/daemons/logind.lpc` 里的两处 `printf("%O\n", ob)`
  已经在这份档案自己的历史里被前任巫师注释掉了（`//        printf(...)`），
  不是活代码，未做改动。
- **§8.9 食物/饮水年龄检查错对象**：`enter_world()` 里的判断是
  `if (!user->query("food") && !user->query("water") && ob->query("age") == 14)`
  ——用 `user` 检查食物/饮水是否为空是对的，但年龄判断仍然错误地用了
  登录对象 `ob` 而不是角色对象 `user`，导致这个判断永远不成立。已改
  为 `user->query("age") == 14`。
- **留言板 `post` 崩溃 bug（AGENTS.md §7.86，跨家族第三次确认）**：
  这个 bug 之前只在"天涯"系家族（`tybxjh`/`xhcii`/`zxty`）见过，这
  次在完全不同的 ES2/金庸血统"hy/海洋"家族里也发现了一模一样的形
  状——全档案 53 份留言板文件都同时 `inherit BULLETIN_BOARD` 又多余
  地对自己 `replace_program(BULLETIN_BOARD)`，导致 `post` 指令必然
  崩溃（`*cannot bind an lfun fp to an object with a pending
  replace_program()`）。已删除全部 53 处多余调用，live 验证过
  `post` 正常打开编辑器、"留言完毕"保存成功。这证实 §7.86 不是某个
  家族的特有问题，而是这一整代 ES2 衍生代码库里一个相当常见的复制
  粘贴习惯——以后遇到任何"留言板能看不能写"的报告，第一时间就该查
  这个模式。
- **一个从未被记录过的新 bug（已写入 AGENTS.md §7.5 追加条目）**：
  在中央广场周边地图第一次巡逻/populate 时，`debug.log` 报出
  `*F_SKILL: No such skill (strike)` / `(unarmed)` 等一系列"技能不
  存在"的运行时错误——但对应的技能档案（`kungfu/skill/strike.lpc`、
  `kungfu/skill/unarmed.lpc` 等）明明就存在于硬盘上。用临时埋点插桩
  排查后发现：这正是 `hy2002`（同一"hy"家族的手足档案）已经确认过
  的 `securd.lpc` `valid_read()` bug——`file_size()` 检查一个技能文
  件是否存在时，会经过和真正的敏感数据读取一样的 ACL 检查，而这个
  自定义 `valid_read()` 没有像本项目其它档案的标准 ACL 那样为
  `load_object`/`include`/`file_size` 这类"纯粹检查/编译"用途放行；
  当触发调用的 NPC 对象自己还在 `create()` 内部、euid 尚未设置好
  时，`geteuid(user)` 返回空，`valid_read()` 直接拒绝，`file_size()`
  因此表现得就像文件根本不存在——`set_skill()` 就误判技能缺失并抛
  出错误，中断了那个 NPC `create()` 剩下的部分。比照 `hy2002` 已经
  验证过的修法，在 `euid = geteuid(user);` 之前加上对
  `load_object`/`recompile_object`/`include`/`file_size` 的放行判
  断。修复后重新走一遍同样的巡城路线，`debug.log` 里不再出现任何
  `F_SKILL` 错误。
- **一个重要的测试方法论教训**：管理员测试账号"无忧"死亡后卡在鬼门
  关，`白无常` 只播放随机闲聊台词，死亡对话流程（`death_stage()`）
  一直没有推进，一度怀疑是 §7.68 类的复活软锁。读源码才发现
  `d/death/npc/wgargoyle.lpc` 的 `init()` 本来就有意排除巫师：
  `if (!previous_object() || !userp(previous_object()) ||
  wizardp(previous_object())) return;`——管理员角色本身就是
  wizardp()，所以从一开始就没有被排进复活流程，这是有意的设计（巫
  师有自己的手段自救，不需要占用这套 NPC 对话驱动的复活系统），不
  是 bug。另开一个非管理员测试账号（`testchar`）重新走一遍死亡流
  程，确认 `death_stage()` 的五个阶段正常播放、`reincarnate()` 正
  确执行、最终落地在武庙——复活系统本身完全正常。**教训**：以后任
  何一次死亡/复活测试如果用的是管理员测试账号，卡住不动时要先检查
  死亡 NPC 的 `init()`/`death_stage()` 有没有 `wizardp()` 排除判
  断，而不是直接假设是 §7.68 类的 bug；必要时另开一个非管理员账号
  重新验证。
- **战斗测试**：在"崔家大门"和自动索敌的"大狼狗"打了两场，一场（管
  理员账号）被秒得很快就死了，另一场（测试账号）也很快落败——这两
  只狼狗对新手角色明显偏难，符合"江湖险恶"的设计但值得注意，不作为
  bug 处理（战斗力数值属于游戏平衡，不在本项目 §10.7 的修复范围内）。
- **本次没有测试**：拜师/门派（扬州武馆已找到，未深入）、商店。

## 深度功能测试（2026-08-13，round two，新驱动重测）

Re-tested against the freshly-rebuilt `build-debug/src/driver`（post
全库 `quest_times`/`win_times` `%`-operator 修复 + Warning/warning
驱动文本回退）。

### 发现并修复的 PROGRAMMING bug

1. **`log_error()`（`adm/obj/master.lpc`）完全没有严重度检查（AGENTS.md
   §7.34-class，与本轮 `wdxtym`/`ffxymud`/`fy2mg`/`fys`/`hc`/`hy`
   同一原始形状）**：`if (this_player(1)) efun::write(...)`——不区
   分巫师/玩家，也不区分警告/错误。修复：加上
   `strsrch(message, "arning:") == -1` 判断。
2. **`log_file()`（`adm/simul_efun/file.lpc`）完全没有 `assure_file()`
   保护（AGENTS.md §7.11-class 的又一确认实例）**：注册/登录本身只
   写 `log_file("USAGE", ...)`（无子目录，本来就存在），不受影响，
   但 `nosave/CRASHES`/`nosave/addobj` 等管理指令路径会在首次使用
   时未捕获抛出。已补上 `assure_file(LOG_DIR + file);`（含前向声
   明）。

### 管理员账号：核实此前的"已确认生效"记录

上一轮（2026-08-05）WASM 修复摘要明确写着"管理员账号以 id `wuyou`
注册，游戏内'目前权限：(admin)'显示确认生效"——`git log` 确认这个
存档从未被提交过，本地 `work/` 目录里也不存在。按本轮 `hy` 学到的
教训（"验证过"的记录如果只是凭存档文件内容或旧会话记忆，不能直接
信任），重新用真实注册流程创建了 `wuyou`/`Mud@2026` 账号：`score`
确认"目前权限：(admin)"，`update /adm/simul_efun/file`（就是本轮改
过的文件）确认可正常重新编译。这次是**真正的**live 验证（不是凭
旧记录），且这份档案的管理员机制本身没有 `hy`/`fqyy2` 那种
"nosave + 硬编码单一 id 被真实玩家占用"的问题——`wuyou` 本身就是硬
编码授权的那个 id，直接注册就能拿到权限，机制上更简单也更可靠，此
次核实结果是正面的（此前的记录内容是真的，只是存档从未被提交，现
已一并提交存档）。

### Proactive checks（无需改动）

- `win_times` 修复确认存在且正确：`d/city2/npc/refereew.lpc:177`。
- 未发现 `message()` simul_efun 包装函数——不适用
  message()-missing-varargs 这一类 bug。

### 实测过程

登录时有一个 GB/Big5 选码提示（选 `g`）。注册 `wuyou`/无忧
（英文 id → 确认建立 → 中文名，直接设定不需要二次确认 → 密码 →
确认密码 → 天赋 0 随机 → 接受 → 邮箱 → 性别）完整进入游戏，屏幕上
出现"有人使用过权限命令，立即查看 /log/nosave/promotion"（`securd.
lpc` 的晋升日志写入，本轮修复的 `log_file()` 让这条路径正常工作，
未见崩溃）。`adm/log/debug.log` 时间戳全程未变化（`Jul 30`，早于本
次会话），确认无新增未捕获运行期错误。驱动最终按精确 PID kill，
`ps -p` 确认已退出。

### 已清理

- 管理员 `wuyou` 的存档已提交（`data/{login,user}/w/wuyou.o`）。

## AGENTS.md §7.100 修复（2026-08-19，批次五）

`ROOM` 基类冗余 `replace_program(ROOM);` 自崩溃地雷（详见 AGENTS.md
§7.100）：2867 个房间文件的 `create()` 里紧跟 `inherit ROOM;` 之后
都有这一行多余调用，永久设下"待替换"标记，第一次对该房间对象绑
定闭包就会崩溃。自带建房工具有 2 处模板（`clone/misc/roommaker.lpc`
简单字符串拼接写法、`adm/roommaker.lpc` 三处独立拼接的"Lonely"变
体）。手动修复了一处不规则格式：`d/happy/workroom.lpc` 的冗余调用
和一个空的尾随 `//` 注释共享同一行（`replace_program(ROOM);  //`），
严格的独立成行脚本正确跳过了它。累计 2870 处 live 调用删除，和
survey 记录的数字精确吻合，修复后 0 处遗留。

验证：`build-debug` 驱动真实冷启动，端口 40174 正常监听，
`debug.log` 全程干净。用这份档案自己播种的管理员账号
`wuyou`/`Mud@2026`（不是 fluffos）登录正常（落地海洋之初，
look/quit），全程无新增 "cannot replace"/"cannot bind" 日志行。

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

新角度：扬州醉仙楼购物 + 丐帮左全拜师。2026-08-05 / 2026-08-13 两轮
都写明没测商店和拜师。这是海洋II/ES2 金庸血统，端口 40174。第一输入
是 BIG5 选单，发 `g`，再英文 id。管理员是硬编码的 `wuyou`/`Mud@2026`
（无忧），不是 fluffos。登录对象没有 `wizpwd`。`(player)` 退出后 20
秒内不能再 login；巫师只警告。横幅里有北京时间心跳，`mudclient`
固定 idle 不受影响。

### 实测过程

管理员 `wuyou` / `Mud@2026`（权限 `(admin)`，落地 `/d/welcome/welcome`）。
身上没钱。第一次 `clone /clone/money/gold` 在
`cmds/wiz/clone.lpc` 第 58 行 `write_file("/log/cmds/clone", …)` 未捕获
崩溃（`/log/cmds` 目录不存在）。修好并 `update` 后 clone 成功。

`goto /d/city/zuixianlou`（醉仙楼，店小二 `d/city/npc/xiaoer2.lpc`，
`F_DEALER`）。`list` 烤鸡腿八十文铜板 / 牛皮酒袋一两白银 / 包子五十文
铜板。`buy jitui` 成功（「你从店小二那里买下了一根烤鸡腿」）。一两黄
金换成九十九两白银 + 二十文铜钱。`feature/dealer.lpc` 里丐帮拒买那段
是注释掉的；本轮先拜师后买，店小二没有拒。

`goto /d/gaibang/inhole`，左全源码是 `kungfu/class/gaibang/zuo-qu.lpc`
（文件名少一个 n），`apprentice zuo` 一次成功：恭喜成为丐帮第二十代
弟子。`score` 称谓「丐帮第二十代弟子」、师傅左全。`cmds/usr/save.lpc`
真正写盘。save 后杀驱动冷启动再登录，称谓/师傅/九十九两白银/二十文铜
钱都在。烤鸡腿未进 autoload。左全只收男性。

### 发现并修复的 PROGRAMMING bug

1. **`clone` 写日志不建目录就崩溃**（`cmds/wiz/clone.lpc`）：裸
   `write_file("/log/cmds/clone", str)`，新鲜 `work/log/` 没有 `cmds/`
   子目录时驱动抛「Wrong permissions for opening file … No such file
   or directory」，整条指令中断，金子也不会进背包。补上
   `assure_file("/log/cmds/clone")`（与 2026-08-13 已修的 `log_file()`
   §7.11 同形）。现场 `update` 后再 clone 验证通过。档案是 CRLF，按
   字节改的。

2. **华山收徒计数拼写**（与 `hy`/`hy2002` 同形，静态对照修，本轮拜
   师走的是左全不是华山）：
   `kungfu/class/huashan/{yue-buqun,yue-wife,feng-buping}.lpc`、
   `kungfu/class/yue-buqun.lpc`、`d/biwu/{feng-buping,yue-buqun}.lpc`、
   `quest/menpaijob/huashan/yue-buqun.lpc` 的 `add("apprentice_availavble",
   -1)` 改成 `apprentice_available`。

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— 任务表里的 `.c` 路径与任务守护进程的防护

`scripts/lpc_dynamic_rows.py`：`quest/dynamic_location` 里 832 行写的是原档案的 `.c` 路径。转档时文件已改名 `.lpc`，而显式后缀按原样解析，`load_object("/d/x.c")`、`new("/d/obj/quest/x.c")` 返回 0 且不报错（KB 03 §4.2，KB 06 §7.220），所以 `adm/daemons/questd.lpc`、`cmds/std/questd.lpc` 读到的每一行都加载不出来：随机任务和任务物品从未生成，在 `create()` 里直接对结果调用 `tar->set()` 的版本还会崩溃，连带加载它的 cron 守护进程和 `give` 的任务钩子。这些行已改为 `.lpc`。
`scripts/lpc_dynamic_quest_guard.py`：2 处 `spread_quest()` 调用（`init_dynamic_quest()` 的循环里）包进 `catch()`，缺失的任务物品或编译不过的房间只跳过那一个任务，守护进程照常加载、其余任务照常生成；`cmds/std/look.lpc` 夜间检查的 `!present("fire", this_player())` 前加 `objectp(this_player()) &&`（房间 `reset()` 销毁物品时 `/feature/move.lpc` 的 `remove()` 会调用 `look_room()`，此时没有 this_player()，`present(…, 0)` 报 `Bad argument 2 to present()`）。
验证：`adm/daemons/questd.lpc`、`cmds/std/questd.lpc`和 cron 守护进程在新进程里加载（HEAD 一次，工作树三次，选房是随机的）：HEAD 通过 3 个，工作树三次分别通过 3、3、3 个（共 3 个），无回退。
验证：改动过的 `adm/daemons/questd.lpc`、`cmds/std/look.lpc`、`cmds/std/questd.lpc` 在新进程里加载，HEAD 通过 3 个、工作树通过 3 个（共 3 个），无回退。

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `inherit/room/room.lpc`：`make_inventory()` 用 `catch()` 包住 `new(file)`，做不出来就返回 0；`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-06）— 白驼山掌门欧阳锋编译不过

`d/baituo/ouyangfeng.lpc` 有两处笔误，整个 NPC 从未编译成功：`greeting()` 里 `write("你是谁？我要杀了你！哈￣哈￣哈￣") break;` 缺分号，`inquiry_map()` 里 `object me = this - player();`（应为 `this_player()`）。白驼山派的掌门因此不存在，拜师、问路（`inquiry_map`）都无从谈起。两处改正后，新进程里 HEAD 加载失败、工作树加载成功。同一文件在 14 个 xkx 系的库里一字不差。

## 深度功能测试（§10.7，2026-10-07）— 空的 `if (current_water == 0) {}`

3 个房间的 `valid_leave()` 里有一行什么也不做的 `if (current_water == 0) {}`（编译警告 `Expression has no side effects`），删去，行为不变：`d/xingxiu/nanjiang2.lpc`、`d/xingxiu/nanjiang3.lpc`、`d/xingxiu/shanjiao.lpc`。

## 深度功能测试（§10.7，2026-10-07）— 郭靖任务的名单被覆盖

`quest/guojob/guo.lpc` 先后 `#include "zzzjob.lpc"` 和 `"teamjob.lpc"`，两个文件都声明全局 `mixed names`、内容不同（`Redeclaration of global variable 'names'`），后包含的 teamjob 名单覆盖了 zzzjob 的，"保护"任务的目标其实从 teamjob 的名单里抽。teamjob 的表改名 `team_names`（KB 04 §6.10）。`guo.lpc` 在 HEAD 与工作树分别加载（新进程）通过。

## 深度功能测试（§10.7，2026-10-07）— 编译警告整理

`scripts/lpc_warnings.py hy2000 --fix` 加 `scripts/lpc_fix_no_effect.py --apply`：共改动 838 个 `.lpc` 和若干 `.h`；`d/tiezhang/pingtai.lpc`、`wmfeng.lpc`、`wztang.lpc` 删去 `return` 后面永远执行不到的 `"\n";`，`kungfu/skill/xuanyuan-arrow.lpc` 删去什么也不做的 `(: throw_weapon :);`。手工：`kungfu/skill/liangyi-jian.bak.lpc` 删去空语句 `level;`。郭靖任务名单（`quest/guojob/teamjob.lpc`）见同日一节。
HEAD 与工作树分别加载（新进程）：812 -> 812 通过，无回退；改过的头文件的 170 个包含者 170 -> 170 通过。

启动时警告 73 -> 0；新进程登录正常。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 11 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 0 个，只在 #if 分支用的声明移进分支 0 个文件；改动 5 个文件，HEAD 与工作树各载入一次无回退（5 objects; HEAD PASS 5, tree PASS 5; regress 0; newly loading 0），这些文件的警告 11 -> 0。

## 深度功能测试（§10.7，2026-10-12）：编译警告收尾

能编译的文件里的警告 11 -> 0（`toolkit_fix.sh hy2000` 后重扫：9333 个文件可编译，剩下的诊断都在本来就编译不过的文件里）。

- 8 个文件多余的 `inherit F_CLEAN_UP;`（`NPC`/`BLADE` 基类已经带了），`toolkit_fix.sh`（`lpc_diamonds.py --fix-redundant`）删掉：`adm/daemons/network/services/temp.lpc`、`d/npc/tie-ren.lpc`、`d/quanzhou{,.old}/npc/tang{,3}.lpc`、`d/shaolin/npc/obj/mu-ren.lpc`、`d/working/obj/mu-ren.lpc`。同一份代码，删哪份都不改变行为。
- `adm/roommaker.lpc`：`special_props` 声明了两次（`({"short","long"})` 与 `({"short","long","file_name"})`），后面的代码只用后一份，删掉前一份死声明。
- `d/city/library.lpc`、`d/city2/library.lpc`：全局 `include/globals.h` 定义 `STORY_DIR` 为 `/clone/gift/`，这两个书房有意改成 `/doc/story/`，在重定义前加 `#undef STORY_DIR`，行为不变。

本轮没有发现玩法层面的真问题。`d/quanzhou{,.old}/npc/tang{,3}.lpc` 在批量载入里 HEAD 与工作树都失败，原因是 `create()` 里 `restore()` 读 `/data/npc/meng-zhu.o` 在 lpcc 的权限环境下被拒（与这次改动无关）。

验证：11 个改动对象 HEAD 与工作树各用新进程载入：7 -> 7 通过，regress 0；删除声明审计 0 项待看。11 个对象载入无回退。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。6 个文件 6 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）；`x op= 浮点` 先把浮点转成整数再运算（系数小于 1 时 x 直接变 0），改为 `x = to_int(x op ...)`：`/kungfu/skill/fengyun-shou/foguang.lpc`（`damage *=`）、`/kungfu/skill/taiji-quan/zhenup.lpc`（`damage *=`）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。

## 内力/精力当作伤害种类（2026-10-15，KB 06 §7.241 第二类）

本库 `feature/damage.lpc` 的 `receive_damage()` 不接受 `jingli`/`neili`/`force` 等种类，`me->receive_damage("jingli", 30)` 之类在练功、绝招、吸取时报 `F_DAMAGE: 伤害种类错误`。13 处改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py` 第二步）。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。3 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。


## 东方故事/西游记体系的技能文件（2026-10-15，KB 06 §7.241 第三类）

这些 `kungfu/skill` 文件来自 gin/kee/sen/force 体系，本库人物只有 jing/qi/neili：`receive_damage("kee", 30)` 报 `伤害种类错误`，`query("force")` 永远为 0，技能学不了也练不了。按 kee→qi、gin/sen→jing、force→neili、max_force→max_neili、force_factor→jiali 改了属性名（`scripts/lpc_port_es_props.py`），共 6 个文件。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

另有 3 个文件（绝招、状态、物品、NPC 等，不限于 kungfu/skill）来自 gin/kee/sen/force 体系，同样按 kee→qi、gin/sen→jing、force→neili 改名（`scripts/lpc_port_es_props.py --any-file`）。


## family 映射（补）（2026-10-15）

`mapping fam = (mapping)me->query("family");`（带类型转换的写法）同样直接取下标，2 处补上 `if (!mapp(fam)) fam = ([ ]);`。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。8 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。

## 妙手回春的银针检查（2026-10-15）

`miaoshouhuichun` 的 `valid_learn()` 用了未赋值的 `object ob`（`ob->query_temp("weapon")` 报错），还把兵器对象和字符串 "银针" 比较。改为 `ob = me->query_temp("weapon")`，再用 `id("yin zhen")`/`id("yinzhen")` 判断是否银针。

## 叠掌与飞雪（2026-10-15，绝招探测）

`kungfu/skill/kongming-quan/diezhang.lpc` 函数结束后残留一段重复的尾巴（`on(GRN ... return 0; }`），文件不能编译，已删除。`liangyi-jian/feixue.lpc` 末尾的 `else destruct(obj);` 在前一分支已销毁兵器时对 0 调用，改为 `else if (objectp(obj))`。

## 空手使用兵器绝招（2026-10-15，KB 06 §7.246）

`perform` 指令允许直接点名招式（如 `perform stick.ban`），这些绝招读了 `me->query_temp("weapon")` 却从不检查，空手时 `weapon->name()` 报错（有的已先扣了内力）。在赋值后补 `if (!objectp(weapon)) return notify_fail("你必须手持兵器才能使用这一招。\n");`（`scripts/lpc_fix_perform_weapon.py`）：`dagou-bang/ban`、`murong-jianfa/kuangjian`、`tianyu-qijian/kuangwu`、`wuyue-blade/jiao`。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`douzhuan-xignyi`→`douzhuan-xingyi`（`/d/mr/obj/shu1`）；`jinwu-dao`→`jinwu-daofa`（`jinwu-daofa`）；`quanzhen-jianfa`→`quanzhen-jian`（`quanzhen-jian/ding`）；`yinyun_ziqi`→`yinyun-ziqi`（`yinyun-ziqi/cure`）。

## 技能名拼错：技能文件里拼错自己的名字（2026-10-15，KB 06 §7.249）

技能自己的文件（或它的绝招目录）里，`query_skill()` 读的是差一个字母的自己的名字，永远得 0：“基本功夫要高过本技能”之类的限制从不生效，按等级取招、计算伤害的那一项一直是 0。改为本技能的名字（`scripts/lpc_fix_skill_typo.py` 的 self 判据）：`chanyun-tui`→`chuanyun-tui`（`chuanyun-tui/shuangjue`）。

## family 映射内联取下标（2026-10-15，KB 05 §7.30）

`ob->query("family")["master_name"]`、`me->query("family")["family_name"]`（泥潭式为 `query("family", ob)[...]`）直接对门派映射取下标：没有门派的人（新玩家、叛师者、大多数 NPC）在 NPC 的打招呼和问话、绝招的门派判断、房间的 `valid_leave` 里报 `Value being indexed is zero`，而不是得到拒绝。4 处（3 个文件）改为 dbase 路径查询 `query("family/master_name")`：有门派时值相同，没有时得 0；原有的判断照常生效（`scripts/lpc_fix_family_index.py`）。给映射赋值的写法未动。


## 用兵器的绝招空手施展时报错（内联写法）（2026-10-15，KB 06 §7.246）

绝招不存兵器变量，直接写 `(me->query_temp("weapon"))->query("name")`（或在拒绝判断里写 `(weapon = me->query_temp("weapon"))->query("skill_type")`），之前又没检查兵器：空手 `perform` 时报 `Bad argument 1 to EFUN call_other()`，内力等往往已经扣掉。在第一次用到它的那条语句前补上“你必须手持兵器才能使用这一招”的拒绝（`scripts/lpc_fix_perform_weapon.py`）：`yunv-jian/suxin`。


## 存档读不出来：字符串里的换行、空行（2026-10-15，KB 03 §4.4）

`data/board/yipin_b.o`：字符串里有原样的换行（`save_object()` 存成 `\r`，`restore_object()` 逐行读，原样的换行让字符串收不了尾），或有空行（`Illegal file format`），读档的对象（留言板、NPC、玩家）从空白开始。换行改写成 `\r`、删去空行（`scripts/lpc_save_encoding.py --from-raw`），驱动核对全部能读回（`scripts/lpc_save_restore_check.py`）。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

4 个文件、5 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/clone/obj/demon_staff`、`/d/city/obj/tudao`、`/d/guanwai/obj/cwbdao`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 0 个，改后 3 个（3 个原来载入不了），没有退步；其余 1 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 8 个对象设了本库没有文件的武功（3 个名字，最多的是 `shenlong-quanfa`、`xingxiu-duzhang`、`meiren-sanshi`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：8 个里 8 个通过。（`scripts/lpc_guard_set_skill.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 38 处、36 个文件：`kunlun-shnfa`→`kunlun-shenfa`（15 处）、`shaolin-shnfa`→`shaolin-shenfa`（10 处）、`lingbo-weibu`→`lingboweibu`（3 处）、`yunu-xinfa`→`yunv-xinfa`（3 处）、`tiaji-jian`→`taiji-jian`（2 处）、`yan-fly`→`yanfly`（2 处）、`shenhuo-shengong`→`shenghuo-shengong`（1 处）、`taiji-shenfong`→`taiji-shengong`（1 处）等共 9 个名字。（`scripts/lpc_fix_skill_names.py`）

## set_name 的 id 参数传成字符串（2026-10-19，KB 06 §7.260）

`set_name("海口大碗", "bowl");` 把物品的 id 写成了字符串，本库的 `set_name(string name, string *id)` 要的是数组，驱动在编译时报 `Bad type for argument 2 of set_name ( string * vs string )`，整个物件载入不了；旧驱动不检查参数类型，字符串里照样找得到这个词，物品能用 id 称呼。改成 `({ "bowl" })`，共 2 个文件：`/d/baituo/npc/obj/bowl.lpc`、`/d/baituo/obj/bowl.lpc`。（`scripts/lpc_fix_set_name_id.py`）

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 载入不了的零碎文件（2026-10-19，KB 03 §4.7、KB 04 §6.10）

- `d/hangzhou/npc/tangzi.lpc`：整个文件只是 UTF-16 的空格（`\x00 \x00 …`，作者把这个物件清空了），驱动报 `Illegal embedded NUL byte (0x00) in source`；旧驱动编出一个空程序。改成一个换行，行为和原来一样（空程序），不从 xkx100 抄回同名 NPC。

逐个载入与 HEAD 对比，没有退步。

## 玩家打造兵器模板没有打造者时（2026-10-19，KB 06 §7.275）

`/d/npc/m_weapon/weapon/m_blade.lpc`、`/d/npc/m_weapon/weapon/m_club.lpc`、`/d/npc/m_weapon/weapon/m_hammer.lpc`、`/d/npc/m_weapon/weapon/m_staff.lpc`、`/d/npc/m_weapon/weapon/m_sword.lpc`、`/d/npc/m_weapon/weapon/m_whip.lpc`（共 6 个）的 `create()` 开头 `me = this_player();` 之后无条件读 `me->query("weapon/name")` 等打造数据。房间刷新时没有人在场（`me` 为 0），或者 NPC 在别的 NPC 的命令环境里 `carry_object()` 这个模板（NPC 的 `weapon` 属性是文件名字符串），旧驱动里读出来是 0 或字符串，`switch` 照样落到 default；新驱动报 `Bad argument 1 to EFUN call_other()` / `Bad argument 1 to switch`，NPC 和它所在的房间载入不了（`--walk` 普查里一个玩家走进房间就触发）。在 `//读入数据` 之后加 `if (!me || !mapp(me->query("weapon"))) { setup(); return; }`：没有打造者就留一个没有名字的空模板，玩家打造的流程不变。

## 补回丢失的标点（2026-10-19，KB 03 §4.6）

转换时丢掉的分号、逗号、引号或文件末尾的 `}`，共 1 个文件，修前 HEAD 载入失败。别的库里同路径的完好副本只比这里少几个标点，按它补回（括号里是那个库）：`/d/city2/npc/zhengmen.lpc`（jqxz2008）。修后与 HEAD 逐个对比载入：这 1 个物件全部载入，没有退步（`scripts/lpc_restore_from_twin.py`、`lpc_fix_eaten_quote.py --comma`、`lpc_fix_eof_braces.py`）。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。改动：`/d/mingjiao/shanmen.lpc`（1 处）。

## `call_out_info()` 的每一项只有 3 个元素（2026-10-20，KB 06 §7.287）

驱动返回的是 `({ 物件, 函数, 延迟 })`，不带 call_out 的参数，旧代码读第 4 项 `info[i][3]`（`callouts` 指令、`calloutd`、`cod` 工具）一读就报 `Array index out of bounds`，指令从第一行起什么也打印不出来。改为 `(sizeof(info[i]) > 3 ? info[i][3] : 0)`（`scripts/lpc_fix_callout_info.py`）。改动：`/cmds/arch/callouts.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 10 处）。改动：`/adm/daemons/combatd.lpc`（1 处）、`/d/city4/obj/mj.lpc`（3 处）、`/d/city4/puke-room.lpc`（4 处）、`/d/hangzhou/npc/meipo.lpc`（1 处）、`/kungfu/class/emei/tobebonze.h`（1 处）。

## `callouts`：`sizeof(info[i]) == 4` 把每一行都挡掉了（2026-10-20，KB 06 §7.287）

驱动的 `call_out_info()` 每项只有 3 个元素，输出行前的守卫 `if (sizeof(info[i]) == 4)` 永远不成立，指令只打印表头。改为 `>= 3`。改动：`/cmds/arch/callouts.lpc`（1 处）。

## `mcheck`：`query_ip_rport()` 驱动里没有（2026-10-20，KB 06 §7.291）

指令要显示连线的远端端口，MudOS 时代的 `query_ip_rport()` 在 FluffOS 里不存在（`query_ip_port()` 给的是本地端口），指令编译不过。文件里加了一个返回 `"?"` 的占位函数（dtsl 的同名指令早就这么做）。改动：`/cmds/imm/mcheck.lpc`。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/obj/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## sefun `cat()`：缺文件时 `write(0)` 报错（2026-10-20，KB 06 §7.297）

`void cat(string file) { write(read_file(file)); }`：文件不存在（压缩包没带的欢迎/公告文件，或只有运行中的 mud 才会写的日志）时 `read_file()` 回 0，`write(0)` 在本驱动里报 `Bad argument 1 to receive()`，调用者（登录对话、`cat` 指令）被中断；老驱动什么也不打印。改成 `write(read_file(file) || "");`（`scripts/lpc_fix_cat_unchecked.py`）。改动：`/adm/simul_efun/file.lpc`。

## 翻页器 `start_more(read_file(...))`：文件缺失时 `explode(0)`（2026-10-20，KB 06 §7.300）

东方故事系的翻页器 `void start_more(string msg) { ... explode(msg, "\n") ... }` 被这样调用：`start_more(read_file(HELP_DIR + "help/topics"))`、`start_more(read_file(NEWS))`。压缩包没带的文件使 `read_file()` 回 0，`explode(0, ...)` 在本驱动里报 `Bad argument 1 to explode()`（不带参数的 `help` 指令就是这样出错的），老驱动把 0 当空文本。在 `start_more` 开头加了 `if (!stringp(msg)) return;`（`scripts/lpc_fix_start_more.py`）。改动：`/feature/more.lpc`。

## `setbak` 指令编译不过：文件末尾粘了半截 `help()`（2026-10-20，KB 06 §7.264）

`cmds/usr/setbak.lpc` 在完整的 `help()` 之后又重复了帮助文字的结尾（`取消变数设定请用 unset 指令。……TEXT ); return 1; }`，没有函数头）：`Illegal character 0xe5`。在第一个完整函数结尾处截断（去掉 8 行）。加载检查：HEAD FAIL → tree PASS。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库现有的 NPC 文件里没有字面写成空 `chat_msg` 的（扫描只认 `set("chat_msg", ({ }))`）；守卫挡的是运行时才为空的列表和以后新增的 NPC。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/inherit/char/npc.lpc`（共 1 个文件）。

## 巫师命令不带参数时对 0 调用 efun（2026-10-21，KB 06 §7.336）

巫师（管理员）把命令敲成不带参数时，驱动把 0 传给字符串参数；下面的命令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`，这条指令从来没有用过。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py` 在第一处使用参数的语句前加守卫：文件自带 `int help(object me)` 的，守卫是 `if (!arg) return help(me);`（`help()` 定义在 `main()` 之后的 1 个文件补了原型 `int help(object me);`，否则编译报 `Undefined function help`）。改动（1 个文件，括号里是接住 0 的 efun）：`/cmds/wiz/test.lpc`（`present`）。加载检查 HEAD 与工作树对照，没有退步。

## `home`：模板 `/clone/misc/wizroom.lpc` 档案里没有（2026-10-21，KB 06 §7.310）

管理员扫描里 `home` 报 `Bad argument 1 to EFUN replace_string() Got: int(0)`（`cmds/imm/home.lpc` 第 30 行）：巫师还没有工作室时，`home` 从 `/clone/misc/wizroom.lpc` 读模板，把 `NAME` 换成名字写进 `/u/<id>/workroom.lpc`；本库没有这个模板，`read_file()` 答 0，第一次敲 `home` 的巫师就是系统错误。`wizroom.lpc` 是这一系的公用文件（hy3、chidi、wmkj、yxcs 等 28 个库都带，内容相同，只差换行符：“没有建造工作室的巫师的临时住处”，出口 `north` 通 `/d/wizard/wizard_room`，本库有这个房间），从 hy3 原样复制过来，加载检查通过。

## `lsusers`：用档案里没有的 `/clone/misc/player`（2026-10-21，KB 06 §7.299）

管理员扫描里 `lsusers` 报 `Bad argument 1 to EFUN call_other() Got: int(0)`（`cmds/adm/lsusers.lpc`）：指令 `new("/clone/misc/player")` 一个对象，用它的 `new_object(name)` 逐个还原玩家存档；本库没有 `/clone/misc/player.lpc`（同系的 hy3、jhfy、xyzx 等 27 个库带着它，`new_object()` 只定义在那里），`new()` 答 0，后面就是对 0 的调用。`new()` 之后加 `if (!ob) return notify_fail(...)`，指令回一句话而不是系统错误；文件本身补不上，那个旧的玩家对象已经不是本库的用户对象了。

## `refresh`（`retask`）：动词函数不返回 1，搬动或销毁带动作的物件时报错（2026-10-21，KB 06 §7.339）

管理员扫描里 `refresh` 在重新分布使命之后报 `Illegal to move or destruct an object (/questobj/...) defining actions from a verb function(refresh) in object(/obj/user#...) which returns zero.`：`main()` 以第二条 `message()` 结尾、没有 `return`，答 0，而 `TASK_D->init_dynamic_quest(1)` 销毁了给玩家定义过动作（`init()` 里的 `add_action`）的使命物件：驱动只在动词答非 0 时才允许这样搬动或销毁，否则它接着遍历的动作表会悬空；答 0 还会让解析器在指令做完之后再补一句“什么？”。`main()` 末尾加 `return 1;`（同系已经返回 1 的 11 个同名文件没有动）。

## `blockade` / `recover`：`data/keep` 不存在，解封之后世界仍然锁着（2026-10-21，KB 06 §7.340）

管理员扫描里 `blockade` 报 `Error copying file from /data/user/f/fluffos.o to /data/keep/fluffos, Error: No such file or directory`，随后的 `recover` 在第一个 `cp()` 上死于 `*/data/keep/fluffos: lstat failed`，来不及执行最后的 `LOGIN_D->set_madlock(0)`：封锁解不开。`data/keep/` 是运行时目录，git 克隆里没有空目录。`blockade` 在第一次写之前 `if (file_size("/data/keep") != -2) mkdir("/data/keep");`（`mkdir()` 失败答 0，不抛错），`recover` 对没有保存档的玩家 `if (file_size(src) < 0) continue;`，其余照常恢复、照常解锁（`scripts/lpc_fix_keep_dir.py`，hy5 上实测：没有保存档时 `recover` 答“时空解封完毕”，`blockade` 建出 `data/keep` 并保存，`recover` 取回并删除）。改动（2 个文件）：`/cmds/arch/blockade.lpc`、`/cmds/arch/recover.lpc`。

## `selfthinking`、`qlian`：缺乏实战经验的提示读了不存在的老师（2026-10-21，KB 06 §7.348）

自创武功的自习指令在“技能等级³/10 大于实战经验”时打印 `printf("也许是缺乏实战经验，你对%s的回答总是无法领会。\n", ob->name())`。这一句是从 `learn` 抄来的，`ob` 是老师；自习没有老师，`object ob;` 从没赋值，`ob->name()` 抛 `call_other() ... Got: int(0)`。改成 `你对「%s」的疑问总是无法领会` 加 `to_chinese(skillname)`，去掉没用的 `object ob;`。改动：`/cmds/skill/selfthinking.lpc`。

## 瓦耳拉齐 `ask_back`：送回去的是没赋值的 `ob`（2026-10-21，KB 06 §7.348）

带着地图问“回去”时 `ob->move(__DIR__ "entrance")`：`ob` 没赋值，路径也错成了 `/d/gaochang/npc/entrance`。xkx100 的原文是 `me->move("/d/gaochang/entrance");`，照改，去掉 `object ob;`。改动：`/d/gaochang/npc/wuaer.lpc`。

## 妙手回春 `valid_learn()`：先读 `ob->query_temp("weapon")` 再给 `ob` 赋值（2026-10-21，KB 06 §7.348）

学这门暗器技能时 `valid_learn()` 第一个武器检查读的是没赋值的 `ob`，`xue` / `learn` 在这里抛错；后面 `ob = me->query_temp("weapon")` 的检查才是对的。有两种写法：`if (!ob->query_temp("weapon"))` 改成 `me->query_temp("weapon")`；`if ((string)ob->query_temp("weapon") != "银针")`（拿一个对象和字符串比较，永远不等，补上 `ob` 之后这门技能也学不成）改成后一种写法里的 `!objectp(ob = me->query_temp("weapon")) || !(ob->id("yin zhen") || ob->id("yinzhen"))`。改动：`/d/hxsd/pingan/shenzhen/skills/miaoshouhuichun.lpc`、`/d/pingan/pingan/shenzhen/skills/miaoshouhuichun.lpc`、`/d/pingan/shenzhen/skills/miaoshouhuichun.lpc`。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 17 条注册（7 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/d/city/leitai.lpc`（`do_quit`）、`/d/city4/qishi.lpc`（`do_pass`、`do_resign`）、`/d/hxsd/pingan/npc/sighmoon.lpc`（`do_vendor_list`）、`/d/mr/shuichi.lpc`（`do_strike`）、`/d/pingan/npc/sighmoon.lpc`（`do_vendor_list`）、`/d/pingan/pingan/npc/sighmoon.lpc`（`do_vendor_list`）、`/inherit/misc/fboard.lpc`（`do_list`）。最多的函数名：`do_quit` 9 处、`do_vendor_list` 3 处、`do_strike` 2 处、`do_pass` 1 处、`do_resign` 1 处。

## 对象路径里的 `..`：`new(__DIR__ "../obj/x")` 报 `Read access denied`（2026-10-22，KB 06 §7.351）

`__DIR__` 是当前文件所在目录（带结尾斜杠），`__DIR__ "../obj/x"` 就是 `/d/zhiye/npc/../obj/x`；驱动的 `legal_path()` 不接受带 `..` 的路径，`new()` / `load_object()` 直接抛 `*Read access denied.`（实测，`find_object()` 对它答 0）。走库自己的 `carry_object()` / 房间 `objects` 表的路径，库的基类会先规范化，能用；直接把路径交给 `new()` / `clone_object()` / `load_object()` / `move()` 的不行，调用到那一步才报错。改成规范化后的绝对路径（`scripts/lpc_fix_dotdot_dir.py --direct`）：`/d/wudang/npc/xiaocui.lpc`（`__DIR__ "../obj/nuerxiang"` → `"/d/wudang/obj/nuerxiang"`）。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 还剩 4 个函数没有补（item_desc 3, other 1）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/cmds/imm/help2.lpc`:`confirm_l_choice`、`/d/city/ximenroad.lpc`:`look_gaoshi`、`/d/gaochang/zoulang2.lpc`:`look_writing`、`/d/gaochang/zoulang_1.lpc`:`look_writing`。

## 读不到的留言板：`"/clone/board/x"->foo();` 在 `create()` 里报错（2026-10-22，KB 06 §7.357）

xkx 系的房间在 `setup()` 之后写 `"/clone/board/gaibang_r"->foo();` 来加载留言板（`foo()` 本来就没有定义，只为了触发加载）。这个库没有这个文件，`call_other()` 报 `*call_other() couldn't find object '/clone/board/gaibang_r'`，对象留在内存里、`load_object()` 却抛错：玩家第一次走进房间就看到错误，写在 `create()` 中间的还会切掉后半段。`scripts/lpc_fix_missing_foo.py` 把 1 条单独成行的语句（`/clone/board/jail_b`；`/d/city2/jail.lpc`）注释掉并写明原因（别的房间里同样的语句本来就是作者自己注释掉的）。证明和 45 个库的整体加载检查见 KB 06 §7.357。

## `(: 函数名 :)` 指针指向本库没有的函数：只含这个指针的行加了注释（2026-10-22，KB 06 §7.355 补充）

`inquiry` / `item_desc` / `chat_msg*` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：用到时（`ask`、`look`、NPC 闲聊）驱动抛 `*Undefined lfun pointer called: 函数名`，这一拍心跳的后半段被跳过。这些函数没有可以补回的来源（别的库同一路径的文件里没有，或者它还要用本库没有的东西），所以 3 个文件里 3 行只含这个指针的行（`"gaoshi": (: look_gaoshi :),` `"writing": (: look_writing :),`）加了注释，原文保留并写明原因，这一项当作没有这个话题 / 物品 / 闲聊条目（`scripts/lpc_fix_dangling_lfun.py`；`#include` 的文件在库里缺失的对象、指针不在整行上的写法没动）。 前提（`function_exists()`）和加载检查（HEAD 与工作区对比，本库改动的 `.lpc` 文件）的结果见 KB 06 §7.355：没有一个回归。

## 汉字按字节切片的老写法没有换成按字符：改法名 `"澄" + name[2..3]`、辈分判断 `name[0..1] == "澄"` 等 26 处（2026-10-22，KB 06 §7.360）

原档按字节算字符串区间（一个汉字 2 字节）：`name[2..3]` 是名字的第二个字，`name[0..1] == "澄"` 问名字是不是以「澄」开头。转成 UTF-8 之后，这个驱动的区间和 `strlen()` 都按字符算（`strlen("澄观")` 是 2，`"澄观"[0..1]` 是两个字），老算术原样留着、意思全变：拜入少林 / 武当 / 峨嵋等派的玩家被改成错误的法名（二字名 `张三` 变成一个字的 `澄`，更长的名字取到第三个字）；各派掌门的辈分判断（`name[0..1] == "澄"`）永远不成立。

本库 26 处（21 个文件）：拼名字的赋值 18 处、与汉字常量比较 8 处。例：`name[2..3]` → `name[1..1]`（`/d/biwu/da-mo.lpc:152`）；`name[0..1]` → `name[0..0]`（`/d/mr/npc/bo.h:17`）；`name[0..1] == "慧"` → `name[0..0] == "慧"`（`/kungfu/class/shaolin/cheng.h:140`）。`scripts/lpc_fix_gbk_slice.py` 把下标按字符重算（社区的 UTF-8 版 `xkx100utf8` 里就是同样的写法，作对照）；没有改的：截断（`name = name[0..7]`，现在最多 8 个字，只是放宽）、ASCII 的区间（`fname[0..3] == "room"`、`ctime(time())[4..19]`）和上下文看不出是汉字的区间。证明（`scripts/lpcc_eval.py`，bixiecanyang；其余各库是同一份文本）：让澄字辈掌门 `attempt_apprentice()` 一个名叫「张三」的访客，HEAD 的法名是 `慧`，改后是 `慧三`；抽样 28 个库的 HEAD / 工作树加载对比 0 退步。工具不幂等（`[0..3]` 折半得 `[0..1]`，又是对齐区间），改过的文件记在 `scripts/gbk_slice_converted.txt`，不要重跑。

## 长度检查按字节写，旁边的提示按汉字写：18 处（2026-10-22，KB 06 §7.362）

老档的 `strlen()` 数字节（一个汉字 2 字节），转成 UTF-8 后它数字符：提示写「必须是 2 到 6 个中文字」的检查还是 `strlen(name) < 4 || strlen(name) > 12`，于是两三个字的房名、帮会名、群名、聊天室名、称号被提示自己说允许的那句话拒绝，上限却是提示的两倍；留言板的标题检查 `i < 4 || i > 24 || i % 2` 还会拒绝所有奇数个字的标题（`post 你好吗`）。本库 18 处（9 个文件）：`if ((strlen(name) < 2) || (strlen(name) > 10)) {`（`/adm/daemons/logind.lpc:929`）；`if ((strlen(name) < 2) || (strlen(name) > 20)) {`（`/cmds/usr/buildeat.lpc:70`）。`scripts/lpc_fix_strlen_gate.py` 以提示为准：条件里每个 `strlen` 门槛都恰是提示所说数字的两倍才折半，存长度的变量（`i = strlen(arg);`）的门槛和 `|| i % 2` 奇偶项、其后循环的 `i % 2 == 0 &&` 一并处理；提示里有英文 / 字母 / 字节的不动。证明（`scripts/lpcc_eval.py`，bxsj 的留言板，求值对象继承 NPC 并重写 `edit()` 记录调用，`command("post 标题")`）：HEAD 拒绝「你好」和「你好吗」、放行 23 个字的标题；改后接受前两个、拒绝第三个；shenmo 的 `named.lpc invalid_new_name("张三")`：HEAD 回 `名字只能是2-4个中文字。`，改后回 0。抽样 24 + 15 个库的 HEAD / 工作树加载对比 0 退步。

## 按字节写的汉字循环、茶馆猜诗和同盟频道标题（2026-10-23，KB 06 §7.363）

老档按字节做「一个汉字」：`while (i--) if (i % 2 == 0 && !is_chinese(name[i..<0]))` 只检查偶数下标，奇数位上的拉丁字母（`张a`）会过；茶馆猜诗 `mixup()` 用 `strlen(str)/2` 再 `j=j+j`、`str[k..k+1]` 交换两字节；泥潭系 `channeld` 的 `switch (strlen(fname)) case 4/6/8/10` 和 `strlen(family)==4/6` 按字节长度给同盟 / 门派名加空格。本驱动的 `strlen()` 和区间都按字符算。`scripts/lpc_fix_byte_char.py`：去掉奇偶项、把区间改成 `name[i..i]`，按字符重写 `mixup()` 并把 `strlen(first)>=14` 折成 7，频道标题的 case / 门派长度改成字符数（对照 aoxiangtianji）。本库 汉字循环 / `is_chinese` 区间 11 个文件；茶馆猜诗 `mixup` 1 个文件。证明（`scripts/lpcc_eval.py`）：sjplii 的 `check_legal_name` 在 HEAD 接受「张a」、改后拒绝，两边都接受「张三」；xkx100 的 `clubpoem->mixup("离离原上草")` 得到「离离原草上」（真交换汉字）；nitan_san 两字同盟名得到 `【 兄  弟 】`。关键对象加载通过。

## 血条 / 表情标题按字节算显示宽度（2026-10-23，KB 06 §7.365）

老档把汉字当两字节：`bar_string[0..(val * N / max) * 2 - 1]` 把「格数」换成字节下标，半格血条在本驱动（按字符算区间）上会整条画满；巫师表情 `edemote` 的 `repeat_string("─", 13 - (strlen(emotion) / 2))` 也会少减汉字宽度。`scripts/lpc_fix_display_pad.py`：去掉 CJK 血条 / 空白条上的 `* 2`（`jings`/`qis` 赋值和 `blank_string3[0..(23-a)]` 的 23→11 一并改），表情标题去掉 `/ 2`；ASCII 空格的 `none_string` / `empty_string` 仍保留 `* 2`（一格两个空格）。本库 2 处（1 个文件）。证明（`lpcc_eval.py` hhsj）：`tribar_graph(6,9,12)` 在 HEAD 画出整条 12 个■，改后为 6 个■+3 个□；麻将 `strlen(tempB)/2` 是两字符牌码，未改。

