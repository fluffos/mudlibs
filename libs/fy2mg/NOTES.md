
## WASM 修复摘要（迁移自 meta.json 的 group_note）

adm/obj/master.lpc 和 jyqxc（086）/jyqxc2（087）/jyqxc2013fwq（088）/xkx2017（112）逐字节相同——同一个"金庸群侠传"/XKX 框架家族，游戏内容不同，按本项目对这个家族已有的惯例单独编号；启动干净，零修复。完整 WASM 修复：给 band.lpc 加了本地回环放行；修复了 logind.lpc 的 make_body() 里 seteuid(getuid()) 把 euid 重置掉的 bug；修复了 check_legal_name() 过时的 GBK 字节长度界限，去掉了 i%2==0 门槛；给 securityd.lpc 的 get_status() 加上了防御。注册流程里有两步是本次会话其它血统档案里没见过的：密码复杂度要求（必须同时包含大小写字母和特殊符号，不只是长度下限），以及性别之后、进入游戏前的民族选择（0-3）——需要照实读取 input_to() 调用链，不能假设它和 jym/hy 系那种更短的流程一样。管理员账号通过纯文本的 adm/etc/wizlist 播种。注册流程到进入游戏世界、look/score/quit、管理员权限识别都已干净验证。

## 深度功能测试（§10.7，2026-08-04）

原生 driver（端口 40198）跑了一遍超出注册流程的完整游玩，先读了
`doc/help/newbie`（风云系《新手指南》，和 `fy330` 的版本几乎同源但不
完全相同）作为测试路线图——这一版明确给出了一份从弱到强排序的安全
陪练对象列表（"无知小童，教书先生，落第书生，乞丐，收破烂的，醉汉，
农夫．．．"），本轮据此思路（虽然这几个具体名字在这份档案自己的地图
里大多没被实际放置，是家族共享的文档模板，不是这份档案专属的内容）
挑选了地图上实际存在、战力由弱到强的几个 NPC 做陪练。

**主动检查命中 2 处，都在 `adm/daemons/logind.lpc` 里**（AGENTS.md
§7.34）：随机姓名分支和手动输入姓名分支各有一处紧挨在
`ob->set("name", ...)` 之前的 `printf("%O\n", ob)` 调试残留，和
`fy330`（同一 XKX 框架家族的姊妹档案）逐字节相同，已一并删除。
`command_hook` 是干净的 `nomask`，没有 MESSAGE_D-> 未防护调用、
stat/water 键名不一致、或 §8.9 食物/饮水按错误对象 age 初始化的问题。

**注册与地图探索**：注册测试角色（秦北 / id `qinbei`），落在"凤求凰
客栈"。`i`/`hp`/`score` 输出格式和数值范围与新手指南的范例基本一致。
探索了风云城的主要街道——南风大街（注意同名但内容不同的两个"南风
大街"房间前后相邻，靠东西方向区分，不是 bug，只是两段街道恰好同
名）、风云广场、西云大路、天主教堂（`no_fight`，"这里不准战斗。"，
符合宗教场所设定）、风云衙门、玉龙珠宝店等，移动和出口全部正常。

**商店测试**：玉龙珠宝店的 `list` 正确显示商品和黄金标价（玉指/玉
簪/玉花/玉镯），vendor 链路工作正常。

**战斗测试（三个不同强度的目标）**：
- 凤求凰客栈的"店小二"（combat_exp 5，`attitude` friendly）——用
  `kill` 绕开 friendly 的 fight-拒绝判定（和 `bixiecanyang`/`fy330`
  发现的技巧一致），双方命中率都很低，气血从 250 缓慢降到 137 后主
  动移动脱离战斗，气血随即回升——确认战斗判定和脱离机制正常。
- 考场的"考生"（combat_exp 50000，friendly）——发现但受时间限制未
  实际交手。
- 风云衙门的"风云衙役"（combat_exp random(500000)，`attitude`
  heroism）——连续三次 `kill`，每次都在气血逼近临界值时触发角色自
  身的自动逃跑（"看来该找机会逃跑了..."），但这个对手会主动跟到玩
  家撤离的房间（"风云衙役走了过来。"）——和 `fy330`/`bixiecanyang`
  遇到的"逃跑必定安全"不同，这里首次观察到追击行为，气血/气血上限
  一度降到 4/29（11%），角色进入"半昏迷"重伤状态但最终还是在下一次
  自动逃跑里脱险，全程没有真正死亡。气血上限随着伤势加重而持续下
  降（250→163→29）是这条血统的负伤机制，不是数值错乱。

**死亡/复活系统：发现并修复 §7.68 的又一实例（未做到现场完整复
现）**：虽然被追杀到气血 11% 也没有真正死亡，但主动读了死亡系统代
码，`d/death/npc/{wgargoyle,bgargoyle}.lpc`（白无常/黑无常）和
`bixiecanyang`/`fy330` 的死亡系统同宗（`revive_loc`/`death_msg` 文
本逐字节相同），`death_stage()` 都有同样的 `if (!ob || !present(ob))
return;` 复活软锁死守卫（AGENTS.md §7.68 第四例）。已按已验证过的
修法拆分：`!ob` 仍然永久放弃，`!present(ob)` 改为 5 秒后重试同一阶
段。两个文件的改动逻辑与 `bixiecanyang` 完全对应——`wgargoyle.lpc`
是纯粹的多阶段复活序列，`bgargoyle.lpc` 在复活序列之前还多一段"活
人闯入阴间就攻击"的判断，两处guard 都属于同一个多阶段流程的一部
分，都需要修。

**诚实记录**：本轮三场战斗测试都没能把角色真正打死（自动逃跑机制
即使在被追击、气血跌到 11% 的极端情况下依然生效），所以
`wgargoyle.lpc`/`bgargoyle.lpc` 的修复是照抄已经在 `bixiecanyang`/
`fy330` 现场验证过的修法应用的，不是本轮独立复现死亡→鬼门关→复活
全流程后现场验证的。这个自动逃跑安全网在两个不同的姊妹档案
（`fy330`、本档案）里都表现得相当可靠，值得作为这整个 ES2 大家族的
一个共性记录下来。

`quit` 正常退出（丢下一件不值钱的布衣，"欢迎下次再来！"），
formatter 检查（三个改动文件均已是干净格式，无需重排版）、
`git status --short libs/fy2mg/` 复查均确认改动范围干净——只有
`logind.lpc`/`wgargoyle.lpc`/`bgargoyle.lpc` 三处源码修改是跟踪变
更，测试角色的新存档保持未跟踪、未提交。`debug.log` 全程没有真实
的 `error:`/`denied`/`Bad argument`/`Too deep recursion` 行。


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

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 7 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（2026-08-12，round two，新驱动重测）

Re-tested against the freshly-rebuilt `build-debug/src/driver`（post
全库 `quest_times`/`win_times` `%`-operator 修复 + Warning/warning
驱动文本回退）。

### 发现并修复的 PROGRAMMING bug

1. **`log_error()`（`adm/obj/master.lpc`）完全没有严重度检查（AGENTS.md
   §7.34-class，与本轮 `wdxtym`/`ffxymud`/`fqyy2` 同一原始形状）**：
   `if (this_player(1)) efun::write("编译时段错误：" + message +
   "\n");`——不区分巫师/玩家，也不区分警告/错误，无条件把所有编译诊断
   转发给当前连线的任何人。真实复现：全新驱动进程下首次注册
   `fluffos` 管理员账号触发的冷编译级联（`/std/char` 及其十余个
   `feature/*.lpc` inherit 链首次编译），修复前屏幕上连续刷出二十多
   行原始 "Warning: Unused local variable"/"Unknown #pragma" 诊断。
   修复：加上 `strsrch(message, "arning:") == -1` 判断，只有真正的错
   误才转发。已用同一新驱动进程下的完整重新注册复测：零次诊断刷屏。
2. **`log_file()`（`adm/simul_efun/file.lpc`）完全没有 `assure_file()`
   保护（AGENTS.md §7.11-class 的又一确认实例，与 `fqyy2` 同一形
   状）**：`LOG_DIR` 下的 `nosave/` 子目录在全新检出里不存在，
   `suicide`/崩溃日志/`purge`/巫师晋升等管理指令路径的
   `log_file("nosave/...", ...)` 调用会在首次使用时未捕获抛出。注册
   /登录本身只写顶层文件（`USAGE`/`ATTEMPT_LOGIN`，无子目录，本来就
   存在），不受影响，但这是一个明确存在的 bug，按标准模式补上
   `assure_file(LOG_DIR + file);`（含前向声明）。
3. **管理员账号从未真正创建（AGENTS.md §1.5 的"wizlist 有记录但角色
   从未真正建立"形状，与本次会话开头几个档案的 commit 记录同一
   模式）**：`adm/etc/wizlist` 里早就有 `fluffos (admin)` 这一行，
   但 `wizlist` 只决定权限等级，不会凭空创建这个 id 的角色本身——用
   README 记录的密码尝试登录时，系统把它当成一个**从未注册过的全新
   id**（提示"这个名字将会创造一个新的人物"），而不是要求密码，证
   实此前从未有人真正走完注册流程。已用真实注册流程完整创建
   `fluffos` 角色（密码沿用 README 已记录的 `Mud@2026x`，本代码线密
   码复杂度要求最严格，需同时含大小写字母+特殊符号），`score` 确认
   显示"目前权限：(admin)"，`update /adm/daemons/securityd` 确认可
   正常重新编译（验证的是真正的写权限，不只是"看起来是 admin"）。
   README 已同步更正这段记录。

### Proactive checks（无需改动）

- `win_times` 修复确认存在且正确：`u/wind/refereew.lpc:176`
  `(string)(to_int(query("win_times")) % 5)`；姊妹文件
  `u/wind/refereew2.lpc:184` 同样已修（`% 3`）。
- 未发现 `message()` simul_efun 包装函数——不适用
  message()-missing-varargs 这一类 bug。

### 实测过程

`fluffos` 管理员账号完整注册（英文 id → 确认建立 → 中文名，直接设定
不需要二次确认 → 密码 → 确认密码 → 邮箱 → 性别 → 民族选择 0-3，此前
未在 README 的注册流程摘要之外单独强调过这一步是新号注册流程的最后
一环）进入"凤求凰客栈"起始区域。修复前后各做一次全新驱动进程下的完
整注册；修复前复现了上述诊断刷屏，修复后干净。`log/debug.log`
全程时间戳未变化，确认无新增未捕获运行期错误。中途一度因为清理测试
存档时用错了路径（这份档案的 `query_save_file()` 比大多数档案多嵌套
一层：`/data/user/f/fluffos/fluffos.o`，不是常见的
`/data/user/f/fluffos.o`）而误以为存档失败，重新确认路径后排除是自
己的操作失误，非真实 bug。驱动最终按精确 PID kill，`ps -p` 确认已
退出。

### 已清理

- 管理员 `fluffos` 的存档已提交（`data/{login,user}/f/fluffos/
  fluffos.o`，注意这份档案的嵌套路径）。

## §7.100 扫描修复（`ROOM` 基类多余 `replace_program()`）

`#define ROOM "/std/room"`：删除 525 处多余的、独立成行的
`replace_program(ROOM);`（保留 `inherit ROOM;`），524 处脚本自动
删除；另 1 处在本库房间建造工具 `obj/roommaker.lpc`"克隆我所在的
房间"命令的字符串拼接模板里，与手足档案 `fy2`/`fy2qh` 同一形状，
已同步手动修正。`work/data` 下未找到额外 `.lpc` 源文件（与
`fy2`/`fy2qh` 不同，本库这里没有该变体）。修复后全库仅剩 3 处历史
遗留的 `//`-注释掉实例，均确认无害、未改动。已用 `build-debug` 驱
动干净启动验证（0 个新增编译错误，端口 40198 正常监听，
`debug.log` 无新增 "cannot replace"/"cannot bind" 行）；未做完整
§10.7 深度游玩测试。

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
`list` 过珠宝店，没有买成、也没有拜师。这是风云/fy 血统，不是
tianya 的醉仙楼/左全路线。

### 实测过程

管理员 `fluffos` / `Mud@2026x`。第一输入是 `您的英文名字：`，密码
后有 MOTD + `请敲回车键［ＲＥＴＵＲＮ］`。落地凤求凰客栈。

`goto /d/fy/yuljade`，`list` 黄金标价（玉指 1 两 / 玉簪 2 两 /
玉花 2 两 / 玉镯 3 两）。`clone /obj/money/gold` 后
`buy jade ring from seller` 成功（「你向商玉龙买下一个玉指」）。
1 两黄金刚好等于玉指 `value` 10000；`cmds/std/buy.lpc` 的
`pay_him()` 在找零 `< 1` 时硬给一文钱，所以 `i` 剩「一文钱」+
玉指。这是这条 fy `buy.lpc` 的既有找零地板，不是新崩溃，未改。

`goto /d/fy/jbang`，荆无命 id 是 `master jin`（不是单独的
`jin`），`apprentice jin` 会「你想拜谁为师？」——`id()` 做精确
匹配，内容规则。`apprentice master jin` 一次成功：荆无命收徒，
`score` 「金钱帮第三代弟子」、师父荆无命。`cmds/usr/save.lpc`
真正调用两个 `save()`（没有 fy3xd 那种 `cmds/std/save.lpc` 影子
文件）。`user.o`（嵌套路径
`work/data/user/f/fluffos/fluffos.o`）立刻带上
`family_name":"金钱帮"` / `master_name":"荆无命"`。玉指未进
autoload，quit 后不在身上，符合该血统普通物件惯例。

本轮没有新的 programming bug。`securityd` 没有 tianya 那种
`/log/` + `log_file` 再入。live `debug.log` 是
`libs/fy2mg/log/debug.log`（Boot Time Fri Sep 4 00:38:46 2026），
无 `error:` / `Too deep recursion`。`work/log/debug.log` 停在
2026-08-18，是死文件；`error_handler` 把轨迹交回驱动 debug.log。
`work/log/log` 只有编译期 Unused local variable 警告。

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 9 line(s) in 3 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— tail() simul_efun

`scripts/lpc_add_tail.py --apply`: `cmds/wiz/tail.lpc` calls `tail(file)`, an efun of the MudOS this archive ran on that FluffOS does not have (`Undefined function tail`: the command did not compile). `adm/simul_efun/file.lpc` now defines `void tail(string file)`: the last 10 lines of the file, written to the player. Load check (HEAD against the working tree): 1 of the 1 tail command file(s) failed to load at HEAD, all load now, and the simul_efun file loads. KB 04 §6.2.

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `std/room.lpc`：`make_inventory()` 用 `catch()` 包住 `new(file)`，做不出来就返回 0；`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-07）— 编译警告整理

`scripts/lpc_warnings.py fy2mg --fix` 加 `scripts/lpc_fix_no_effect.py --apply`，共改动 245 个 `.lpc`（多为删去未用的局部变量）。HEAD 与工作树分别加载（新进程）：230 -> 230 通过，无回退。启动时警告 16 -> 0；新进程登录（输入名字）正常。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 3 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 0 个，只在 #if 分支用的声明移进分支 1 个文件；改动 3 个文件，HEAD 与工作树各载入一次无回退（3 objects; HEAD PASS 1, tree PASS 1; regress 0; newly loading 0），这些文件的警告 3 -> 0。

## 深度功能测试（§10.7，2026-10-12）：编译警告收尾

能编译的文件里的警告 131 -> 0（`scripts/lpc_warnings.py fy2mg` 重扫：3626 个文件可编译，0 条警告）。fys 同日也收尾，但两库不是同码（`lpc_twin_port.py classify`：fys 改过的 52 个文件在本库 48 个没有、3 个头文件内容不同），没有可直接搬的修改。

**真问题：** `std/weapon/_dagger.lpc` 本应是“作为 feature 继承”的匕首（同目录 `_sword.lpc`、`_blade.lpc` 等以及 fy330/fys/zzfy 等兄弟库的 `_dagger.lpc` 都是两行 `#define AS_FEATURE` + `#include "dagger.lpc"`），这里却是一份 `dagger.lpc` 的旧拷贝，自己 `inherit EQUIP`。唯一用它的 `d/qianfo/obj/silver_clasp.lpc` 银簪（`inherit HEAD; inherit F_DAGGER;`，可戴可当匕首用）因此把 `F_DBASE`/`F_MOVE`/`F_NAME` 等继承两份（7 条 `Redeclaration`：`dbase`、`weight`、`my_id`……两套变量）。按兄弟库改回两行，银簪只剩一套。

**其余：** `toolkit_fix.sh` 删去 10 个多余的 `inherit`（`d/city/npc/*` 等 NPC 再继承 `F_SKILL`/`F_CLEAN_UP`，`std/char/npc.lpc` 已带上）；`daemon/skill/hubo.lpc`（`ITEM`+`SKILL` 双继承）点名 `clean_up()` 的赢家 `skill::clean_up()`，行为不变。

验证：改动的 13 个对象 HEAD 与工作树各用新进程载入：12 -> 13 通过，regress 0（银簪原先编译不过，现在能载入）。删除声明审计 0 项待看。13 个对象载入无回退。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。1 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

73 个文件（技能、绝招、兵器、书籍、区域 NPC 等）来自侠客行体系（qi/jing/neili），而本库人物是 gin/kee/sen/force：`receive_damage("qi", ...)` 报 `伤害种类错误`，`query("neili")` 永远为 0。按 qi→kee、jing→sen（本库学习/读书指令消耗的就是它）、neili→force、max_neili→max_force、jiali→force_factor 改名（`scripts/lpc_port_es_props.py --any-file`）。

## 治疗/疗伤的属性名（2026-10-15，KB 06 §7.241）

`receive_heal()`/`receive_curing()` 也只接受本库的种类。4 个文件（多为只调用 `receive_heal`/`receive_curing` 的药物、NPC）来自侠客行体系，按 qi→kee、jing→本库学习指令消耗的池、neili→force 改名（`scripts/lpc_port_es_props.py --any-file`）。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`beimin-shengong`→`beiming-shengong`（`jiuyang-shengong`、`liumai-shenjian`、`taiji-shengong`）。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

31 个文件、35 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/d/city2/obj/jinduan`、`/clone/misc/cloth`、`/clone/weapon/gangzhang`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 0 个，改后 29 个（29 个原来载入不了），没有退步；其余 2 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## 去掉的预定义宏 `SAVE_EXTENSION`（2026-10-18，KB 04 §6.11）

老版 MudOS 给每个 LPC 对象预先定义了 `SAVE_EXTENSION`（`".o"`）；FluffOS 的 ChangeLog（COMPAT_BUSTER 一条）把它删了，改用 `__SAVE_EXTENSION__`。本库没有自己 `#define` 这个宏，用到它的文件一律 `Undefined variable 'SAVE_EXTENSION'`，整个对象载入不了。改成 `__SAVE_EXTENSION__`（`scripts/lpc_fix_predefined_macro.py`）：`adm/daemons/network/netmail.lpc`、`cmds/arch/purge.lpc`、`include/net/fs.h`、`include/net/ftpdsupp.h`、`obj/token.lpc`。`token` 是帮派领袖信物；`purge` 是清除玩家档案的巫师指令；`netmail` 是网络邮件守护进程（本库缺 `mailer.h` 等头文件，改后仍载入不了）。改后用 `lpcc` 逐个载入这些对象：2 个通过，1 个还有别的错误（`adm/daemons/network/netmail`：/adm/daemons/network/netmail.lpc:17: error: Cannot #include mailer.h）。

## 补回丢掉的基类宏（2026-10-18，KB 04 §6.13）

`inherit F_XXX;` 里的宏本库任何头文件都没有定义，报 `syntax error, unexpected L_IDENTIFIER, expecting L_STRING or '('`，整个对象载入不了；宏指向的基类文件本库其实有，别的库都把这个宏定义成同一个路径。在全局头文件 `include/globals.h` 里补上：`F_DEALER` → `/feature/dealer`（3 个文件）。（`scripts/lpc_restore_macros.py`）改后用 `lpcc` 逐个载入这些对象：3 个里 0 个通过，其余 3 个还有别的错误（`d/city/npc/obj/yang.lpc`：Undefined variable 'MONEY_D'；`d/city/obj/yang.lpc`：Undefined variable 'MONEY_D'；`d/city/zuixianlou2.lpc`：Undefined variable 'MONEY_D'）。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库目前没有对象设了缺失的武功；三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。（`scripts/lpc_guard_set_skill.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 1 处、1 个文件：`xinxiu-duzhang`→`xingxiu-duzhang`（1 处）。（`scripts/lpc_fix_skill_names.py`）

## 武功基类缺少 NewRandom()（2026-10-19，KB 06 §7.261）

基本武功（`boxing`、`houquan`、`westsword`、`taiji-quan` 等）用 `action[NewRandom(i, 20, level/5)]` 挑招式；`NewRandom()` 和它调用的 `sum()` 在别的库的武功基类里有，本库的 `/std/skill.lpc` 是更精简的版本，没有，于是这些武功全都报 `Undefined function NewRandom` 编译不过，有这门武功的人物只能空手。把这一对函数（115 个库共用的同一份文字）补进武功基类，受益武功 52 个：`/daemon/skill/banruo-zhang.lpc`、`/daemon/skill/cibei-dao.lpc`、`/daemon/skill/damo-jian.lpc`、`/daemon/skill/dashou-yin.lpc`。（`scripts/lpc_restore_skill_helpers.py`）

## 技能基类丢了“预备武功”那一段（2026-10-19，KB 06 §7.262）

`feature/skill.lpc` 有 `skill_map`/`map_skill()`，却没有预备武功（`prepare_skill`）这一块：变量 `skill_prepare`、`prepare_skill()`、`query_skill_prepared()`、`query_skill_prepare()`。来自 xkx 系列的 NPC 在 `create()` 里调用 `prepare_skill("cuff", ...)`，于是 `Undefined function prepare_skill` 整个 NPC 载入不了。从同系的 xkx100 把这一块原样补回（声明加在 `skill_map` 后面，函数加在文件末尾），受益 NPC 10 个：`d/huashan/npc/dayou`、`d/huashan/npc/gao`、`d/huashan/npc/laodenuo`、`d/huashan/npc/liangfa`。（`scripts/lpc_transplant_function.py`）

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 补回本库没有的基类文件，第二轮（2026-10-19，KB 04 §6.15、§6.18）

宏有定义、基类文件却不在档案里：继承它的对象载入时报 `Inherited file '…' does not exist!`，编译扫描看不到这一类（`scripts/lpc_missing_inherits.py` 能列出）。同系的库里有同一个文件，原样拷来（`scripts/lpc_restore_bases.py`）；基类和继承它的对象 include 而本库没有的头文件一起带来。每个基类补回后单独载入，再载入使用它的对象，载不进来、或一个用户也载不进来的撤掉了。

- `/inherit/weapon/weapon`（宏 `M_WEAPON`）←cctx：5/5 个继承它的对象载入
- 玩家打造兵器的模板（5 个文件）这回有了基类，照 KB 06 §7.275 加上没有打造者时的保护（`scripts/lpc_fix_forge_template.py`）。

逐个与 HEAD 对比载入，没有退步。

## 标准整理轮，第二轮（2026-10-19，`scripts/toolkit_fix.sh`）

本库在新驱动下重扫，机械修复：5 个未使用的局部变量。修后与 HEAD 逐个物件对比载入，没有退步。

## 行编辑器指令编译失败：`(: this_object(), ({ "do_to", me, arg }) :)`（2026-10-20，KB 06 §7.284）

`Illegal to use local variable in functional.`：call_other 形式的函数指针 `(: ob, ({ "函数", 参数 }) :)` 的数组里只能是常量，写了局部变量 `me` / `arg` 整个指令就编译不过，`to` 这类先开编辑器、再回调自己的指令因此从未能用。改成 `(: call_other, this_object(), "do_to", me, arg :)`（参数在建立指针时绑定，编辑器再把输入的文字接在最后，`do_to(me, arg, text)` 收到全文；`scripts/lpc_fix_functional_locals.py`）。改动：`/cmds/wiz/to.lpc`（1 处）。
