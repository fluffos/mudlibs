
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
