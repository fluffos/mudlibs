
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

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— tail() simul_efun

`scripts/lpc_add_tail.py --apply`: `cmds/wiz/tail.lpc` calls `tail(file)`, an efun of the MudOS this archive ran on that FluffOS does not have (`Undefined function tail`: the command did not compile). `adm/simul_efun/file.lpc` now defines `void tail(string file)`: the last 10 lines of the file, written to the player. Load check (HEAD against the working tree): 1 of the 1 tail command file(s) failed to load at HEAD, all load now, and the simul_efun file loads. KB 04 §6.2.

## 深度功能测试（§10.7，2026-10-05）— 任务表里的 `.c` 路径与任务守护进程的防护

`scripts/lpc_dynamic_rows.py`：`quest/dynamic_location` 里 1052 行写的是原档案的 `.c` 路径。转档时文件已改名 `.lpc`，而显式后缀按原样解析，`load_object("/d/x.c")`、`new("/d/obj/quest/x.c")` 返回 0 且不报错（KB 03 §4.2，KB 06 §7.220），所以 `adm/daemons/questd.lpc` 读到的每一行都加载不出来：随机任务和任务物品从未生成，在 `create()` 里直接对结果调用 `tar->set()` 的版本还会崩溃，连带加载它的 cron 守护进程和 `give` 的任务钩子。这些行已改为 `.lpc`。
`scripts/lpc_dynamic_quest_guard.py`：1 处 `spread_quest()` 调用（`init_dynamic_quest()` 的循环里）包进 `catch()`，缺失的任务物品或编译不过的房间只跳过那一个任务，守护进程照常加载、其余任务照常生成。
验证：`adm/daemons/questd.lpc`和 cron 守护进程在新进程里加载（HEAD 一次，工作树三次，选房是随机的）：HEAD 通过 2 个，工作树三次分别通过 2、2、2 个（共 2 个），无回退。

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `std/room.lpc`：`make_inventory()` 用 `catch()` 包住 `new(file)`，做不出来就返回 0；`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK；全库 3608 个对象 HEAD 对工作树的加载检查：3585 -> 3588，新增 3 个可加载，无回退。

## 深度功能测试（§10.7，2026-10-07）— 编译警告整理

`scripts/lpc_warnings.py fy330 --fix` 加 `scripts/lpc_fix_no_effect.py --apply`，共改动 277 个 `.lpc`。HEAD 与工作树分别加载（新进程）：270 -> 270 通过，无回退。

启动时警告 57 -> 0；新进程登录（新人物确认）正常。

- 2026-10-10：`include/net/ftpdsupp.h` 的 `check_access()` 里 `string file;` 只在 `#ifdef GUEST_WIZARD_FTP` 分支里用，声明移进该分支（编译警告第二轮；与 xkx 一系其他库相同）。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`putfiforce`→`putiforce`（`qiankunwuxing`）。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 1 个对象设了本库没有文件的武功（1 个名字，最多的是 `jiayiqoforce`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：1 个里 1 个通过。（`scripts/lpc_guard_set_skill.py`）

## 区域物件的零碎修正（2026-10-19，KB 06 §7.267–§7.271）

- `adm/simul_efun/file.lpc` 补上同系列（fy3dz、fy3xd）的 `write_file2()`：`adm/daemons/brd.lpc` 和订做衣服、打铁的 NPC 调用它，之前编不过

逐个物件与 HEAD 对比载入，没有退步。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 行编辑器指令编译失败：`(: this_object(), ({ "do_to", me, arg }) :)`（2026-10-20，KB 06 §7.284）

`Illegal to use local variable in functional.`：call_other 形式的函数指针 `(: ob, ({ "函数", 参数 }) :)` 的数组里只能是常量，写了局部变量 `me` / `arg` 整个指令就编译不过，`to` 这类先开编辑器、再回调自己的指令因此从未能用。改成 `(: call_other, this_object(), "do_to", me, arg :)`（参数在建立指针时绑定，编辑器再把输入的文字接在最后，`do_to(me, arg, text)` 收到全文；`scripts/lpc_fix_functional_locals.py`）。改动：`/cmds/wiz/to.lpc`（1 处）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/obj/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## sefun `cat()`：缺文件时 `write(0)` 报错（2026-10-20，KB 06 §7.297）

`void cat(string file) { write(read_file(file)); }`：文件不存在（压缩包没带的欢迎/公告文件，或只有运行中的 mud 才会写的日志）时 `read_file()` 回 0，`write(0)` 在本驱动里报 `Bad argument 1 to receive()`，调用者（登录对话、`cat` 指令）被中断；老驱动什么也不打印。改成 `write(read_file(file) || "");`（`scripts/lpc_fix_cat_unchecked.py`）。改动：`/adm/simul_efun/file.lpc`。

## 翻页器 `start_more(read_file(...))`：文件缺失时 `explode(0)`（2026-10-20，KB 06 §7.300）

东方故事系的翻页器 `void start_more(string msg) { ... explode(msg, "\n") ... }` 被这样调用：`start_more(read_file(HELP_DIR + "help/topics"))`、`start_more(read_file(NEWS))`。压缩包没带的文件使 `read_file()` 回 0，`explode(0, ...)` 在本驱动里报 `Bad argument 1 to explode()`（不带参数的 `help` 指令就是这样出错的），老驱动把 0 当空文本。在 `start_more` 开头加了 `if (!stringp(msg)) return;`（`scripts/lpc_fix_start_more.py`）。改动：`/feature/more.lpc`。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库现有的 NPC 文件里没有字面写成空 `chat_msg` 的（扫描只认 `set("chat_msg", ({ }))`）；守卫挡的是运行时才为空的列表和以后新增的 NPC。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/std/char/npc.lpc`（共 1 个文件）。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 2 条注册（2 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/d/huangshan/npc/xiangke.lpc`（`do_vendor_list`）、`/d/songshan/npc/xiangke.lpc`（`do_vendor_list`）。最多的函数名：`do_vendor_list` 2 处。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 还剩 1 个函数没有补（chat_msg 1）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/d/fy/npc/gangster2.lpc`:`goaway`。

## 运行期目录 `log/nosave` 不存在，写日志的 `write_file()` 直接报错（2026-10-22，KB 03 §4.3 补充）

这个库的 5 个文件里有 8 处 `write_file("/log/nosave/...")` / `log_file("nosave/...")`（`static` 改 `nosave` 时连字符串里的日志路径一起改了，原来是 `log/static/`）：`nosave/CRASHES`、`nosave/PURGE`、`nosave/promotion` 等。压缩包和站点包里没有这个目录，`write_file()` 在目录不存在时抛 `*Wrong permissions for opening file /log/nosave/... for append. "No such file or directory"`，调用它的函数（杀人记录、重启记录、`call` 日志……）当场中断。把 `log/nosave` 记进 `scripts/wasm_keep_dirs.txt`（站点和 pristine 树都按它建空目录）；没有把字符串改回 `static`。证明（`scripts/lpcc_eval.py`，`catch(write_file("/log/nosave/ZZTEST", ...))`，fqyy2 / hy5 / bmxkx2001 的新进程）：补目录前报上面的错误，补后写成功。

## 汉字按字节切片的老写法没有换成按字符：改法名 `"澄" + name[2..3]`、辈分判断 `name[0..1] == "澄"` 等 2 处（2026-10-22，KB 06 §7.360）

原档按字节算字符串区间（一个汉字 2 字节）：`name[2..3]` 是名字的第二个字，`name[0..1] == "澄"` 问名字是不是以「澄」开头。转成 UTF-8 之后，这个驱动的区间和 `strlen()` 都按字符算（`strlen("澄观")` 是 2，`"澄观"[0..1]` 是两个字），老算术原样留着、意思全变：拜入少林 / 武当 / 峨嵋等派的玩家被改成错误的法名（二字名 `张三` 变成一个字的 `澄`，更长的名字取到第三个字）；各派掌门的辈分判断（`name[0..1] == "澄"`）永远不成立。

本库 2 处（2 个文件）：拼名字的赋值 1 处、与汉字常量比较 1 处。例：`name[0..1]` → `name[0..0]`（`/d/qianfo/npc/master2.lpc:101`）；`things[0..13] == "天南地北双飞客"` → `things[0..6] == "天南地北双飞客"`（`/d/tieflag/magroom.lpc:46`）。`scripts/lpc_fix_gbk_slice.py` 把下标按字符重算（社区的 UTF-8 版 `xkx100utf8` 里就是同样的写法，作对照）；没有改的：截断（`name = name[0..7]`，现在最多 8 个字，只是放宽）、ASCII 的区间（`fname[0..3] == "room"`、`ctime(time())[4..19]`）和上下文看不出是汉字的区间。证明（`scripts/lpcc_eval.py`，bixiecanyang；其余各库是同一份文本）：让澄字辈掌门 `attempt_apprentice()` 一个名叫「张三」的访客，HEAD 的法名是 `慧`，改后是 `慧三`；抽样 28 个库的 HEAD / 工作树加载对比 0 退步。工具不幂等（`[0..3]` 折半得 `[0..1]`，又是对齐区间），改过的文件记在 `scripts/gbk_slice_converted.txt`，不要重跑。

## 长度检查按字节写，旁边的提示按汉字写：6 处（2026-10-22，KB 06 §7.362）

老档的 `strlen()` 数字节（一个汉字 2 字节），转成 UTF-8 后它数字符：提示写「必须是 2 到 6 个中文字」的检查还是 `strlen(name) < 4 || strlen(name) > 12`，于是两三个字的房名、帮会名、群名、聊天室名、称号被提示自己说允许的那句话拒绝，上限却是提示的两倍；留言板的标题检查 `i < 4 || i > 24 || i % 2` 还会拒绝所有奇数个字的标题（`post 你好吗`）。本库 6 处（3 个文件）：`if ((strlen(name) < 2) || (strlen(name) > 40)) {`（`/cmds/std/buildroom.lpc:68`）。`scripts/lpc_fix_strlen_gate.py` 以提示为准：条件里每个 `strlen` 门槛都恰是提示所说数字的两倍才折半，存长度的变量（`i = strlen(arg);`）的门槛和 `|| i % 2` 奇偶项、其后循环的 `i % 2 == 0 &&` 一并处理；提示里有英文 / 字母 / 字节的不动。证明（`scripts/lpcc_eval.py`，bxsj 的留言板，求值对象继承 NPC 并重写 `edit()` 记录调用，`command("post 标题")`）：HEAD 拒绝「你好」和「你好吗」、放行 23 个字的标题；改后接受前两个、拒绝第三个；shenmo 的 `named.lpc invalid_new_name("张三")`：HEAD 回 `名字只能是2-4个中文字。`，改后回 0。抽样 24 + 15 个库的 HEAD / 工作树加载对比 0 退步。
