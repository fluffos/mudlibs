
## WASM 修复摘要（迁移自 meta.json 的 group_note）

和本合集里现有的任何一个"风云"系档案（fy2/fys/fysjmb/jhfy2/jhfy3/fyzfqyy/fy2qh/fy3dz/fy3xd/jhfy/zzfy/zzfy3/fengyun434/fy2005）都没有 master-hash 匹配——虽然标题相似，但是完全不同的代码库；启动干净，零修复。和 fy2mg（151）是同一个"金庸群侠传"/XKX 框架家族——euid 重置 bug 和 check_legal_name 的问题逐字节相同，密码复杂度要求、性别之后的民族选择步骤也相同。完整 WASM 修复：给 band.lpc 加了本地回环放行；修复了 logind.lpc 的 make_body() 里 seteuid(getuid()) 把 euid 重置掉的 bug；修复了 check_legal_name() 过时的 GBK 字节长度界限，去掉了 i%2==0 门槛；给 securityd.lpc 的 get_status() 加上了防御。管理员账号通过纯文本的 adm/etc/wizlist 播种。注册流程到进入游戏世界、look/score/quit、管理员权限识别都已干净验证（这个血统的新手房间有持续的 NPC 心跳对话——不要把 --idle 节奏测试送指令时被岔开的对话误判为回归，测试时要给和已知正常运行时一样多的中间指令）。

## 深度功能测试（§10.7，2026-08-04）

原生 driver（端口 40199）跑了一遍超出注册流程的完整游玩，先读了
`doc/help/newbie.txt`（风云系《新手指南》）作为测试路线图——它详细写
出了注册流程范例、look/i/hp/score 的期望输出、拜师学艺、吃喝、典当
等系统的操作方式，本轮基本照着这份指南走。

**主动检查命中 2 处，都在 `adm/daemons/logind.lpc` 里**（AGENTS.md
§7.34）：随机姓名分支和手动输入姓名分支各有一处紧挨在
`ob->set("name", ...)` 之前的 `printf("%O\n", ob)` 调试残留，与
`bixiecanyang`/`hc`/`yxjh`/`xkyx3b`/`mnhf` 是同一形状（两条平行姓名
输入路径各一处），已一并删除。`command_hook` 是干净的 `nomask`（没有
多余的 `private`），没有 MESSAGE_D-> 未防护调用，没有 stat/water 与
stat/drink 键名不一致的问题，也没有 §8.9 那种食物/饮水按错误对象的
age 初始化的写法（这个血统的食物/饮水似乎是无条件初始化的，注册后
`hp` 显示 97-99%，不是从 0 开始，符合正常表现）。

**注册与基础状态验证**：注册了测试角色（秦南 / id `qinnan`），落在
"沉香镇中心"（《新手指南》列出的候选起始房间之一）。`i`/`hp`/`score`
输出的格式和数值范围与新手指南里给出的范例基本一致（精力/气血/心神
满值，食物饮水接近满值，参数点 5，属性初始值也吻合）。

**地图探索**：从沉香镇中心出发，向北到沉香镇石桥，向南到沉香镇南街，
再往西经山门可以看到黄山方向的入口，向西另一条路能走到"沉香南宫"
（南宫钱庄，一个死路房间，唯一出口向东）。移动、房间描述、出口列表
全部正常，没有发现坏引用或崩溃。

**商店测试**：中心广场的"卖鱼的"是个 vendor（`F_VENDOR`），`list` 正
确显示"鲜鱼 freshfish：8文钱"，`buy freshfish from fishseller` 正确
因为身上没钱被拒绝（"你的钱不够。"）——这是新角色没有初始资金的正常
内容状态，不是程序 bug；vendor 的 list/buy 指令链路本身工作正常。

**战斗测试**：中心广场的"沉香镇的地头蛇"（Gangster，combat_exp
1000）和"半仙兽 高人"（Gaoren，combat_exp 5000）都没有显式设置
`attitude`（地头蛇）或设成 "friendly"（高人）——`fight` 指令会被
friendly 目标拒绝，但确认 `kill` 指令能绕开这层同意判定直接开战，与
`bixiecanyang` 那次发现的机制一致。和地头蛇打了两场、和高人打了一场，
每次都在气血降到临界值附近时触发了角色自身的自动逃跑机制（"看来该
找机会逃跑了..."，随即被挪到相邻房间），从未真正把角色打死——这个
自动逃跑的安全网在本轮尝试的三场战斗里都可靠地生效，没有让角色的气
血归零过。战斗过程本身（命中/闪避/招架判定、伤害数值、逃跑触发）表
现正常，`debug.log` 全程没有真实的 `error:`/`denied`/`Bad argument`/
`Too deep recursion` 行。

**死亡/复活系统：发现并修复 §7.68 的又一实例（未做到现场完整复现）**：
虽然没能在本轮战斗中把角色真正打死，但主动读了死亡系统代码
（`d/death/npc/panguan.lpc`，"朱笔判官"），发现了和
`bixiecanyang`/`bmxkx2001` 完全同形状的复活软锁死 bug（AGENTS.md
§7.68 第三例）：`death_stage()` 的守卫是 `if (!ob || !present(ob) ||
(int)ob->query("combat_exp") > MAX_EXP) return;`——`!present(ob)`（此
刻只是不在场）和另外两个真正应该永久放弃的条件（对象已销毁、角色战
力超出这位判官能处理的范围）混在同一个 `return` 里，导致复活序列一
旦被打断就会永久卡死，没有任何提示。已按已验证过的修法拆开：
`!ob`/`combat_exp` 超限仍然永久放弃，`!present(ob)` 改为 5 秒（原代
码是 3 秒）后重试同一阶段。同目录下的 `panguan2.lpc` 也有一模一样的
`if (!ob || !present(ob)) return;`，但读代码确认它是单次判断（没有
`stage` 参数，没有自我重新调度），只用来判断"闯入阴间的活人"要不要
被直接攻击，不存在"放弃一个进行中的多阶段流程"的问题，所以特意没有
改动它——是不同性质的守卫，不能只看文字形状就套用同一个修法。

**诚实记录**：这次的战斗测试里，角色的自动逃跑机制在气血归零之前
每次都可靠触发，没能在本轮里真正走到死亡→鬼门关→复活的完整流程，
所以 `panguan.lpc` 的修复是照抄已经在其他姊妹档案里现场验证过的修
法应用的，不是本轮独立复现并现场验证过的。如果以后有更方便强制角色
死亡的手段（比如更高战力的 NPC，或者被逼到真正的死路房间），值得回
来专门验证一次。

`quit` 正常退出（丢下一件不值钱的布衣，"欢迎下次再来！"），重连、
formatter 检查（两个改动文件均已是干净格式，无需重排版）、
`git status --short libs/fy330/` 复查均确认改动范围干净——只有
`logind.lpc`/`panguan.lpc` 两处源码修改是跟踪变更，测试角色的新存档
保持未跟踪、未提交。


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

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 8 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## §7.100 扫描修复（`ROOM` 基类多余 `replace_program()`）

`#define ROOM "/std/room"`：删除 638 处多余的、独立成行的
`replace_program(ROOM);`（保留 `inherit ROOM;`），全部由脚本自动
删除，无任何历史遗留的 `//`-注释实例、无异常格式。本库没有任何在
游戏内建造房间的工具（`roommaker`/`rmmaker` 等名称均未找到），因
此没有"工厂"侧需要修复。已用 `build-debug` 驱动干净启动验证（0 个
新增编译错误，端口 40199 正常监听，`debug.log` 无新增 "cannot
replace"/"cannot bind" 行）；未做完整 §10.7 深度游玩测试。

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

## 深度功能测试（2026-09-04，round three，shop + 拜师）

新角度：玉龙珠宝店购物 + 金钱帮荆无命拜师。2026-08-04 那一轮只
在沉香镇对「卖鱼的」做过 `list` / 没钱 `buy`，没有进玉龙珠宝店，
也没有拜师。这是风云/fy 血统，不是 tianya 的醉仙楼/左全路线。

### 发现并修复的 PROGRAMMING bug

1. **`log_error()`（`adm/obj/master.lpc`）完全没有严重度检查（AGENTS.md
   §7.34-class，与 `fy2mg` 同一原始形状）**：
   `if (this_player(1)) efun::write("编译时段错误：" + message +
   "\n");`——不区分巫师/玩家，也不区分警告/错误。真实复现：全新
   驱动进程下首次注册 `fluffos` 触发的冷编译级联（`/std/char` 及
   `feature/*.lpc` inherit 链首次编译），屏幕连续刷出「Unknown
   #pragma」/「Unused local variable」诊断。修复：加上
   `strsrch(message, "arning:") == -1` 判断。master 物件开机加载，
   已用重启驱动后的重登 + `update /std/char` 复测：玩家侧不再出现
   `编译时段错误：` + warning 刷屏。
2. **`log_file()`（`adm/simul_efun/file.lpc`）完全没有 `assure_file()`
   保护（AGENTS.md §7.11-class）**：`write_file(LOG_DIR + file, text)`
   在 `nosave/` 子目录不存在时会未捕获抛出。本轮注册本身只写顶层
   `USAGE`，没有撞上，但仍按 `fy2mg` 同一修法补上前向声明 +
   `assure_file(LOG_DIR + file);`。

### 实测过程

`adm/etc/wizlist` 里早就有 `fluffos (admin)`，但磁盘上没有对应存档
（AGENTS.md §1.5：名单不等于角色）。本轮完整注册：id `fluffos` →
y → 中文名 `浮浮` → 密码 `Mud@2026x` ×2 → email `a@b.c` → m → 民族
`0`。第一输入是「您的英文名字：」，密码后有 MOTD +
`请敲回车键［ＲＥＴＵＲＮ］`。落地凤求凰客栈。存档是嵌套路径
`work/data/{login,user}/f/fluffos/fluffos.o`（不是常见的
`/data/user/f/fluffos.o`）。NPC 心跳对话不断，脚本 idle 用 0.45s。

`goto /d/fy/yuljade`，`list` 黄金标价（玉指 1 两 / 玉簪 2 两 /
玉花 2 两 / 玉镯 3 两）。`clone /obj/money/gold` 后
`buy jade ring from seller` 成功。1 两黄金刚好等于玉指 `value`
10000；`cmds/std/buy.lpc` 的 `pay_him()` 在找零 `< 1` 时硬给一文钱，
所以 `i` 剩「一文钱」+ 玉指。这是这条 fy `buy.lpc` 的既有找零地板，
不是新崩溃，未改。

`goto /d/fy/jbang`，荆无命 id 是 `master jin`（不是单独的 `jin`），
`apprentice master jin` 一次成功：荆无命收徒，`score` 「金钱帮第三
代弟子」、师父荆无命。`cmds/usr/save.lpc` 真正调用两个 `save()`
（没有 fy3xd 那种 `cmds/std/save.lpc` 影子文件）。`user.o` 立刻带上
`family_name":"金钱帮"` / `master_name":"荆无命"` /
`startroom":"/d/fy/jbang"`。

`securityd` 没有 tianya 那种 `/log/` + `log_file` 再入，未改。
live `debug.log` 是 `libs/fy330/log/debug.log`（Boot Time Fri Sep 4
01:16:27 2026，fd 指向该文件），无 `error:` / `Too deep recursion`。
`work/log/debug.log` 停在 2026-07-31，是死文件。`error_handler`
把轨迹交回驱动 debug.log。`work/log/log` 是 `log_error()` 写入的
编译期诊断。管理员存档未提交（本轮只修源码；嵌套 `fluffos.o` 留在
工作树，不进 git）。
