
## WASM 修复摘要（迁移自 meta.json 的 group_note）

侠客行一百（Coollizard & xkx100，2003-2004，yoyo.xm.fj.cn/xkx100）。和另一个独立完成的 GitHub fluffos/xkx100 仓库不同（不同代码库，无关）。WASM 修复了 6 个各自独立的编译/运行时 bug：（1）§7.48 类的"private"函式被继承档案呼叫：feature/treemap.lpc 的 _set()/_query()/_delete() 声明为 private，但继承了 F_TREEMAP 的 feature/dbase.lpc 直接呼叫它们——已改成 protected，和 AGENTS.md 记载的模式完全对应。（2）同样的 §7.48 模式又独立出现在 feature/action.lpc 的 continue_action() 和 feature/attack.lpc 的 attack() 里，都被 /inherit/char/char.lpc 呼叫——也改成了 protected。（3）feature/team.lpc 的 follow_path() 里 §7.47 类的 origin()==ORIGIN_X 整数位掩码比较（这个驱动的 origin() 回传字符串）——已改成按文档记载的映射 origin()=="local"/"internal"。（4）adm/daemons/logind.lpc 里一个真正的缺失档案健壮性 bug：howmany_visitor()/howmany_card() 对 read_file() 的结果做 sscanf() 前没有先检查它是不是字符串——log/MUDVISITOR 在这份档案里真的完全不存在（连 raw/ 里都确认没有），所以一次真正全新的安装第一次连线就会撞上（英文名字提示还没出现之前），sscanf(0, ...) 的类型不匹配错误会在 logon() 执行过程中被驱动静默吞掉，连线卡死，没有任何错误文字也没有提示——已加上 stringp(content) 判断，文件不存在时回传 0，匹配这份档案自己代码明显预期（num 默认为 0）但没有安全实现的情形。（5）adm/daemons/combatd.lpc 里一处错误的 #include 路径：'#include </quest/quest.h>'（绝对路径写法）在这个驱动的 include 目录搜索规则下解析不了；这份代码库里其它所有需要同样的 quest_finished()/quest_failed()/lock_quest() 辅助函式的档案都已经用 '#include <quest.h>'（解析到 /include/quest.h，一份几乎相同的更新副本）——已把 combatd.lpc 改成一致写法。（6）修好（5）之后连锁出现的"Illegal to inherit after defining global variables"：quest.h 声明了一个全局 quest_name 映射，落在了 combatd.lpc 的 'inherit F_DBASE;' 之前——已把 #include 挪到 inherit 语句之后（最安全的位置，因为 #include 是纯文本替换，只需要满足"先 inherit 后全局变量"这条排序规则）。adm/simul_efun/chinese.lpc 里 §8.1 类的 is_chinese() 本来就是正确的逐码点检查；只有 check_legal_name() 自己独立的 i%2 门槛和按字节数算的长度界限（4-10，本意是 2-5 个字符）需要同样的标准修复（逐字符呼叫 is_chinese(name[i..i])，长度界限改成 2-5）。管理员账号播种：fluffos (admin) 加入 adm/etc/wizlist（已有多个 (admin)/(arch)/(wizard) 账号；SECURITY_D 正确指向 /adm/daemons/securityd）。注册流程在一次连续的 WASM 客户端会话里完整验证过：英文 id→y/n 创建确认→中文名字→密码+确认→出生地选择（1-5）→属性点数分配（3 项明确输入，第 4 项自动算出剩余）→y 接受→性格特质菜单（0 为不设定）→电子邮件（id@address 格式）→性别→带着完整角色属性表和可用的 'score'/'look' 指令进入游戏世界，全程没有任何意外错误。管理员权限已直接通过 'wizlist' 指令输出确认"目前权限：(admin)"，fluffos 出现在最高的 (admin) 阶层里。LPC 格式化工具对全部 14255 个档案运行（写入 14237 个，2 个报错，16 个未改动）。没有 :: 父类呼叫拆分命中，没有 CJK 重新加空格命中，没有 case 标签带尾随注释的候选。全部 8 个 map.lpc 档案确认内容完全相同（只是空白差异）。格式化后用同样的完整注册流程重新验证过——干净，管理员权限依然是 (admin)。

## 深度功能测试（§10.7，本轮）：核对并确认这份档案同样带着 jqxz2008/xkx2017 家族的大部分 bug

这份档案自己此前只做过 WASM 修复级别的注册流程验证，没有玩到移动/
战斗/死亡这些更深内容。这次先核对了最近几轮在 `jqxz2008` 系列和同
属"MudOS v21 世系"的 `xkx2017` 上依次确认的 5 个 bug，逐一核对后：

**命中的（已修复）：**
1. `adm/daemons/logind.lpc`（§8.9）：`ob->query("age") == 14` 检查
   了错误的对象（应该是 `user`），每个新角色的食物/饮水从创建起就
   永远是空的。改成 `user->query("age") == 14`。
2. `adm/daemons/combatd.lpc`/`cmds/std/kill.lpc`（§7.11）：
   `/log/nosave/` 目录不存在，`combatd.lpc` 的 `killer_reward()`
   （每次死亡都会跑到）对着这个不存在的目录裸调 `write_file()`。加
   了 `assure_file()`。

**没有命中的（核对后确认不需要修）：**
3. `chinesed.lpc` 的 `create()` 虽然也是未加保护的 `restore()`，但
   这份档案里 `data/e2c_dict.o` 这个档案根本不存在（不是"存在但损
   坏"，是压根没有）——`restore_object()` 对着一个不存在的档案只是
   正常返回失败，不会抛出异常，所以 `create()` 能正常走完，`dict`
   保留着自己声明时的 `([])` 初始值。用真实驱动实测（打死一次角色，
   战斗/死亡讯息大量用到中文格式化）确认全程没有任何相关报错，没
   有修改这个档案。
4. `bai.lpc`/`apprentice.lpc` 里判断"是否从风清扬门下叛出"的逻辑，
   这份档案是完全不同的、写法正确的独立实现（用
   `present("feng qingyang", room)` 而不是共享计数档案），没有那处
   括号位置错误。

**这次额外发现了本档案独有的 4 处 §7.68 死亡/复活软锁**：
`d/death/npc/{mengpo,bgargoyle,wgargoyle,chacha}.lpc`——其中孟婆
（`mengpo.lpc`）的函式名不叫 `death_stage()` 而是 `tea_give()`（喂
孟婆汤的多阶段对话），但是同样的 bug 形状：`if (!ob || !present(ob))
return;` 把"角色永久离开"和"暂时不在场"混在一起，没有重试路径。全部
按各文件自己原有的重试间隔（`mengpo`/`chacha` 3 秒，`bgargoyle`/
`wgargoyle` 5 秒）拆分成"暂时不在场则重试"。

用真实驱动完整验证了两次全新注册（走完出生地选择→膂力/悟性/根骨/
身法分点→性格选择→email→性别的完整流程，比 `xkx2017`/`jqxz2008` 系
列多两个步骤），`score` 正确显示食物/饮水两条状态全满、属性数值和
输入一致；用测试角色（小九）在南阳城实际攻击 NPC"小贩"，角色被打
死，干净地触发"你死了"→"鬼门关"死亡场景→NPC"白无常"打招呼——
`debug.log` 全程保持空白，确认 `combatd.lpc` 的修复生效。

### 未继续测试的部分

时间关系，没有测试拜师、购物、留言板。


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

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 70 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（2026-08-13，round two，新驱动重测）

针对驱动升级（`quest_times`/`win_times` `%`-operator 修复 + Warning/warning
大小写回退兼容）做的重测。这份档案的注册流程比大多数同类档案多两
步（出生地选择、天赋点数手动分配 80 点预算），完整走了一遍：id →
y → 中文名 → 密码 ×2 → 出生地(1) → 膂力/悟性/根骨各输入 20（身法
自动算出 20）→ 接受 y → 性格(0) → email → 性别(m)。

### 发现并修复的 PROGRAMMING bug

1. **`log_error()`（`adm/obj/master.lpc`，实际生效的 master file）
   完全没有严重度检查（AGENTS.md §7.34-class）**：`if
   (this_player(1))` 无条件回显。已加上 `strsrch(message, "arning:")
   == -1` 判断。
2. **`log_file()`（`adm/simul_efun/file.lpc`）完全没有
   `assure_file()` 保护（AGENTS.md §7.11-class）**：已加上前向声明
   + `assure_file(LOG_DIR + file);`。
3. **`inherit/char/char.lpc` 第 111 行 `heart_beat()` 里
   `environment()->is_chat_room()` 没有先判断 `environment()`
   是否为空，`call_other()` 拿到 int(0) 直接崩溃**：live 测试注册流
   程进入"北京"区域时，`clone/quest/questyinshi#4`（"江湖豪客"）连
   续多个心跳周期反复抛出 `*Bad argument 1 to EFUN call_other()
   Expected: object... Got: int(0).`——该 NPC 在这一刻没有
   `environment()`（不在任何房间容器里）。这份档案自己在
   `feature/command.lpc:46` 已经有 `environment() && ...` 的标准写
   法，说明这是本代码库自己认可的惯用防护模式，只是这一处漏加。已
   改成 `if (!environment() || !environment()->is_chat_room() ||
   ...)`。修复后同样流程的完整会话（含约 90 秒纯 idle 观察期）里
   debug.log 里这个错误没有再出现过。
4. **冷启动 eval-cost 耗尽（AGENTS.md §7.90/§10.8-class）**：注册流
   程首次进入"北京"区域时大量档案第一次编译，`maximum evaluation
   cost`（默认 700000）在注册会话期间连续触发了近 20 次 `Eval
   interrupted`/`Too long evaluation`——比典型的"仅冷启动一次"更严
   重，属于这份档案自己文件规模较大触发的更严重实例。按已确认的补
   救方式把 `config.fluffos` 的这个值从 700000 提到 5000000（本项
   目另有 30+ 档案在用这个值）。修复后重新走一遍同样的注册+同一区
   域访问流程，debug.log 里零 `Eval interrupted`/`Too long
   evaluation`。

### Proactive checks（无需改动）

- `win_times` 的 `%`-operator 修复确认存在且正确：
  `d/city/npc/jinyong.lpc:197`、`d/beijing/npc/refereew.lpc:177`、
  `d/city/npc/gulong.lpc:246` 均已用 `to_int(query("win_times")) %
  5`；`d/huashan/npc/referee.lpc`/`.old` 不涉及 `%`，不适用。
- `feature/dbase.lpc` 未发现 tybxjh/wlhd 那种密码写保护，不适用。

### 实测过程

`adm/etc/wizlist` 里的 `fluffos (admin)` 一直没有对应存档（此前只
做过 WASM 阶段的结构性核实）。本轮通过完整注册流程创建（含出生地/
天赋点数分配这两步本档案独有的额外流程），落地"北京"客店，`score`
显示"目前权限：(admin)"，食物/饮水满格。随后**单独一步**做了真实
断线重连+密码验证：用刚设的密码重新连线成功登录，存档数据一致。全
程（含 90 秒 idle 观察期）`debug.log` 干净，无运行时错误。驱动按精
确 PID 结束；管理员存档（`data/{login,user}/f/fluffos.o`，此前从
未真正注册过）已提交。

## §7.100 跨库扫描修复（ROOM 冗余 replace_program() 关闭包炸弹，2026-08-19）

同一形状覆盖到几乎所有房间基类（机制详见 AGENTS.md §7.100）。本库属
于该扫描已知最大规模的 10 个库之一。二进制模式脚本机械删除了 5928
个文件里 5929 处独立、未注释的 replace_program(ROOM); 整行（其中
`d/huangshan/banshan.lpc` 和 haiyang2 一样，同一 create() 里有两处
独立冗余调用）。另外手工清理了造房工具 clone/misc/roommaker.lpc 代
码生成模板里内嵌的同一形状（1 处 heredoc 已被脚本一并捕获、1 处字
符串拼接手工清理）。删除总计 5930 行，与本次扫描 FINDINGS.md 记录
的 xkx100 存活命中数完全一致。

验证：干净启动一次真实调试驱动，端口 40117 正常监听，
work/log/debug.log 全程无新增内容。用已播种的 `fluffos`/`Mud@2026`
管理员账号连线（密码与本项目标准约定一致，权限确认为 (admin)），从
`d/beijing/kedian` 出发往返走了 10 余个房间（客栈/南大街/马厩/天安
门广场），look/score/who 均正常。启动期间某个后台精灵在
`data/` 下产生的三个 1 字节临时文件（`HUICHUN`/`XUMING`/`YANGYAN`，
与本次登录无关）连同存档时间戳 diff 一起清理/撤销，不提交。驱动按
精确 PID kill。

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

## 深度功能测试（2026-09-04，round three，shop + 拜师）

新角度：扬州醉仙楼购物 + 丐帮左全拜师。§10.7 原文明确写「没有测试拜
师、购物」；2026-08-13 round two 没有补这两步。角色出生地是北京客店
`/d/beijing/kedian`，商店仍用扬州 `/d/city/zuixianlou`（店小二货单很
长，`list` 走 `start_more` 分页，脚本必须先 `q` 退出分页再买）。

### 实测过程

管理员 `fluffos` / `Mud@2026`。第一输入是「您的英文名字：」，落地北京
客店，留言板显示「客店留言板(Board) [ 没有任何贴子 ]」。登录横幅带活
时钟（「现在的 北京 时间」），脚本 idle 0.45s。

`goto /d/city/zuixianlou`，`list` 烤鸡腿三十文铜板（还有酒袋/茶叶/烤
鸭/各种包子）。`F_DEALER` 对丐帮拒绝购买（穷叫化），先买再拜。
`clone /clone/money/gold` 后 `buy jitui` 成功（「你从店小二那里买下了
一根烤鸡腿」）。`i` 剩七十文铜钱 + 九十九两白银（10000−30 = 9970），
黄金条目消失，找零数学正确。

`goto /d/gaibang/inhole`，左全源码是 `kungfu/class/gaibang/zuo-qu.lpc`，
`apprentice zuo` 一次成功：左全收徒，`score` 「丐帮第二十代弟子」、
师父左全。`cmds/usr/save.lpc` 对巫师无 30 秒节流，真正调用两个
`save()`。`user.o` 立刻带上 `family_name":"丐帮"` / `master_name":"左
全"` / `generation":20`。断线后再连，称谓/师傅/银子还在。左全只收男性。

本轮没有新的 programming bug。`log_error()` 已有 `"arning:"` 闸门。
live `debug.log` 是 `libs/xkx100/log/debug.log`（Boot Time Fri Sep 4
02:04:34 2026），无 `error:` / `Too deep recursion`。`error_handler`
把轨迹交回驱动 debug.log。管理员存档未提交。

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 4 line(s) in 1 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators (opener line, case)

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 2 more block(s) repaired: 2 where the text sits on the opener's line (`@LONG   text...LONG`, the newlines were lost): `open/task1/huodu.lpc`, `d/city/task1/huodu.lpc`.

## 深度功能测试（§10.7，2026-10-05）— 任务表里的 `.c` 路径与任务守护进程的防护

`scripts/lpc_dynamic_rows.py`：`quest/dynamic_location` 里 4141 行写的是原档案的 `.c` 路径。转档时文件已改名 `.lpc`，而显式后缀按原样解析，`load_object("/d/x.c")`、`new("/d/obj/quest/x.c")` 返回 0 且不报错（KB 03 §4.2，KB 06 §7.220），所以 `adm/daemons/questd.lpc`、`last_modify/quest/questd.lpc` 读到的每一行都加载不出来：随机任务和任务物品从未生成，在 `create()` 里直接对结果调用 `tar->set()` 的版本还会崩溃，连带加载它的 cron 守护进程和 `give` 的任务钩子。这些行已改为 `.lpc`。
`scripts/lpc_dynamic_quest_guard.py`：2 处 `spread_quest()` 调用（`init_dynamic_quest()` 的循环里）包进 `catch()`，缺失的任务物品或编译不过的房间只跳过那一个任务，守护进程照常加载、其余任务照常生成；`cmds/std/look.lpc` 夜间检查的 `!present("fire", this_player())` 前加 `objectp(this_player()) &&`（房间 `reset()` 销毁物品时 `/feature/move.lpc` 的 `remove()` 会调用 `look_room()`，此时没有 this_player()，`present(…, 0)` 报 `Bad argument 2 to present()`）。
验证：`adm/daemons/questd.lpc`、`last_modify/quest/questd.lpc`和 cron 守护进程在新进程里加载（HEAD 一次，工作树三次，选房是随机的）：HEAD 通过 3 个，工作树三次分别通过 3、3、3 个（共 3 个），无回退。
验证：改动过的 `adm/daemons/questd.lpc`、`cmds/std/look.lpc`、`last_modify/quest/questd.lpc` 在新进程里加载，HEAD 通过 3 个、工作树通过 3 个（共 3 个），无回退。

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `inherit/room/room.lpc`：`make_inventory()` 用 `catch()` 包住 `new(file)`，做不出来就返回 0；`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-06）— 编译警告整理

`scripts/lpc_warnings.py xkx100 --fix`：无用局部变量 1993 个、`varargs` 8 处、转义 34 处、`nosave` 函数 30 个；`scripts/lpc_fix_no_effect.py` 删去 `return "...";` 后遗留的 `"\n";` 等 6 处；`scripts/lpc_diamonds.py --fix-redundant` 删去 156 个多余的 `inherit F_SKILL;`（`NPC` 已经带进来，两份 `skill.lpc` 让技能变量变成 `nosave`，KB 06 §7.213），`d/city/pai9room.lpc` 多余的 `inherit F_CLEAN_UP;` 手工删去（它的 `::valid_leave()` 本来就落在 `ROOM` 上）。`feature/alias.lpc` 的 `if (str != "");`（空的 if，`last_input` 总被赋值）删去，与 `hy` 把这行注释掉的做法一致，行为不变。共改动 1039 个 `.lpc`，HEAD 与工作树分别加载（新进程）：1005 -> 1005 通过，无回退；可编译的文件 14126 -> 14138，诊断 4316 -> 146；启动时警告 189 -> 0；新进程启动后登录界面正常。

## 深度功能测试（§10.7，2026-10-07）— 空的 `if (current_water == 0) {}`

3 个房间的 `valid_leave()` 里有一行什么也不做的 `if (current_water == 0) {}`（编译警告 `Expression has no side effects`），删去，行为不变：`d/xingxiu/nanjiang2.lpc`、`d/xingxiu/nanjiang3.lpc`、`d/xingxiu/shanjiao.lpc`。

## 深度功能测试（§10.7，2026-10-08）— `.lpc` 后缀的定宽切片

`.c` 改名 `.lpc` 时只改了字符串没改切片宽度：`f[<2..] == ".lpc"` 拿两个字符比四个字符，永远不成立（`!=` 永远成立），按后缀筛文件、去后缀的代码因此从不运行或截成 `x.l`（KB 06 §7.238）。`scripts/lpc_lpc_suffix_slice.py --apply` 改了 5 处比较、2 处去后缀（如 `clone/npc/qingyun.lpc`）；改动的文件 HEAD 与工作树分别加载（新进程），无回退。

- 2026-10-10：`/d/wudujiao/mishi.lpc` 的技能判断用按位 `&` 连接两个比较（如 `tjss > 10000 & taoism > 10000`），改为逻辑 `&&`。两边都是 0/1 比较结果，行为不变，只是写法纠正。

- 2026-10-10：`/clone/misc/roommaker.lpc` 生成新文件用的 here-document 模板（`@ROOM_CODE`/`@OBJ_CODE`）里的 `inherit` 行，被 cb9eeb980cd 的重复继承清理当成代码删掉了（`lpc_diamonds.py` 当时不识别 here-document），用它生成的房间/物品会因缺少继承而无法编译。已恢复该行；工具已修正。

- 2026-10-11：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 12 处，返回类型/原型 41 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 0 个，只在 #if 分支用的声明移进分支 0 个文件；改动 42 个文件，HEAD 与工作树各载入一次无回退（42 objects; HEAD PASS 42, tree PASS 42; regress 0; newly loading 0），这些文件的警告 53 -> 0。

## 深度功能测试（§10.7，2026-10-11）：钱塘潮颜色

- `adm/daemons/event/qiantang.lpc`：`"…十分壮观。\n"; NOR;` 分号把 `NOR` 隔成独立语句，颜色不复位；改为 `"…" NOR;`。载入无回退。

## 深度功能测试（§10.7，2026-10-12）：黑木崖老者

- `d/heimuya/npc/laozhe.lpc` `init()`：残留调试行 `sprintf("%s \n", what);`，`what` 是对象，本驱动 `sprintf` 的 `%s` 遇对象报错，进房间时 `init()` 每次中断、招呼从不执行；删去（与 fys 同）。

- 2026-10-12：`open/xiangyang/task/teamjob.lpc` 的组队任务用 `names[0][random(40)]` 选地点，而这张表只有 34 个地名，`random()` 落到表外时数组越界报错、任务中断。改成 `random(sizeof(names[0]))`（shenmo `u/stey/newjob/teamjob.lpc` 同类）。HEAD 与工作树各载入一次，regress 0。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。11 个文件 14 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）；`x op= 浮点` 先把浮点转成整数再运算（系数小于 1 时 x 直接变 0），改为 `x = to_int(x op ...)`：`/kungfu/skill/bahuang-gong/powerup.lpc`（`skill *=`）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。
- 2026-10-14（同一次重扫，手工部分）：
  - 36 个技能文件的 `int power_point()` 返回 1.1–1.5 的浮点（含按内功等级分支的写法），经 `int` 返回一律被截成 1，改为 `float`。
  - `adm/daemons/combatd.lpc` 用到这个值：
    - 防守时读进 `float dpower`，限定在 1–1.5，乘到防御等级上，这里原本就是浮点写法。
    - 进攻时原写 `damage *= (int)SKILL_D(...)->power_point(me)`。`(int)` 对浮点只是编译期标注，不做转换，`damage` 会在运行时变成浮点。现改为 `damage = to_int(damage * ...)`。
  - **玩家可见**：带威力系数的武功和轻功按原设计的 1.1–1.5 倍计算伤害和防御。原先在本驱动下系数一直被截成 1。
  - `d/city/daxiaoroom.lpc` 去掉注释里嵌套的 `/*`；`mudlib/testsuite/tmp_eval_file.lpc` 补 `return`。

- 2026-10-14：3 个文件因 `Illegal to inherit after defining global variables` 整份不编译：FluffOS 要求所有 `inherit` 写在第一个全局变量之前，MudOS 不管。`scripts/lpc_fix_inherit_order.py` 把写在 `inherit` 之前的全局变量（以及声明全局变量的头文件的 `#include`）挪到最后一个 `inherit` 之后（KB 04 §6.3）。

## 内力/精力当作伤害种类（2026-10-15，KB 06 §7.241 第二类）

本库 `feature/damage.lpc` 的 `receive_damage()` 不接受 `jingli`/`neili`/`force` 等种类，`me->receive_damage("jingli", 30)` 之类在练功、绝招、吸取时报 `F_DAMAGE: 伤害种类错误`。5 处改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py` 第二步）。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。2 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

另有 7 个文件（绝招、状态、物品、NPC 等，不限于 kungfu/skill）来自 gin/kee/sen/force 体系，同样按 kee→qi、gin/sen→jing、force→neili 改名（`scripts/lpc_port_es_props.py --any-file`）。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。18 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。


## 技能按另一门武功的等级取招（2026-10-15，KB 06 §7.243）

这些技能文件是从别的武功复制改名来的，`query_action()` 仍用原武功的等级查招式表：只会本技能的人等级为 0，取不到招，每次出招都报错。改为读本技能自己的等级（`scripts/lpc_fix_action_level.py`）：`boruo-strike`、`cibei-blade`、`huashan-jianfa`、`huashan-zhangfa`。

## 空手使用兵器绝招（2026-10-15，KB 06 §7.246）

`perform` 指令允许直接点名招式（如 `perform stick.ban`），这些绝招读了 `me->query_temp("weapon")` 却从不检查，空手时 `weapon->name()` 报错（有的已先扣了内力）。在赋值后补 `if (!objectp(weapon)) return notify_fail("你必须手持兵器才能使用这一招。\n");`（`scripts/lpc_fix_perform_weapon.py`）：`taiji-jian/raozhi`。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`five_poison`→`five-poison`（`/clone/medicine/poison/redyao`、`/clone/medicine/poison/shenxiandao`、`/clone/medicine/poison/whiteyao`、`/clone/medicine/poison/wuxing`、`/clone/medicine/poison/yellowyao`）；`jinwu-dao`→`jinwu-daofa`（`jinwu-daofa`）。

## family 映射内联取下标（2026-10-15，KB 05 §7.30）

`ob->query("family")["master_name"]`、`me->query("family")["family_name"]`（泥潭式为 `query("family", ob)[...]`）直接对门派映射取下标：没有门派的人（新玩家、叛师者、大多数 NPC）在 NPC 的打招呼和问话、绝招的门派判断、房间的 `valid_leave` 里报 `Value being indexed is zero`，而不是得到拒绝。3 处（3 个文件）改为 dbase 路径查询 `query("family/master_name")`：有门派时值相同，没有时得 0；原有的判断照常生效（`scripts/lpc_fix_family_index.py`）。给映射赋值的写法未动。


## 达摩剑「达摩三绝剑」、反两仪刀「华岳三神峰」每次报错（2026-10-15，KB 06 §7.246）

两个绝招都声明了 `object weapon, ob;` 却从不给 `ob` 赋值：结尾 `if (!ob->is_fighting(me))` 在内力扣完后报错，`sanshen` 的三刀甚至都砍向 `ob`（0）。改为 `target`，并先判断 `objectp(target)`（循环里可能取不到对手）。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

97 个文件、162 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/d/migong/obj/cloth`、`/d/migong/obj/sword`、`/d/migong/obj/blade`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 0 个，改后 69 个（69 个原来载入不了），没有退步；其余 28 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## 去掉的预定义宏 `SAVE_EXTENSION`（2026-10-18，KB 04 §6.11）

老版 MudOS 给每个 LPC 对象预先定义了 `SAVE_EXTENSION`（`".o"`）；FluffOS 的 ChangeLog（COMPAT_BUSTER 一条）把它删了，改用 `__SAVE_EXTENSION__`。本库没有自己 `#define` 这个宏，用到它的文件一律 `Undefined variable 'SAVE_EXTENSION'`，整个对象载入不了。改成 `__SAVE_EXTENSION__`（`scripts/lpc_fix_predefined_macro.py`）：`cmds/usr/suicide.lpc`、`d/jiaxing/npc/tang.lpc`、`d/jiaxing/npc/tang3.lpc`、`d/quanzhou/npc/tang.lpc`、`d/quanzhou/npc/tang3.lpc`、`include/net/ftpdsupp.h`。`tang3`/`tang`/`meng-zhu` 是武林盟主一类的 NPC，原来一个都载入不了；`suicide` 是自杀指令。改后用 `lpcc` 逐个载入这些对象：5 个通过。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 80 个对象设了本库没有文件的武功（44 个名字，最多的是 `dragon`、`spells`、`westsword`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：30 个里 30 个通过。（`scripts/lpc_guard_set_skill.py`）

## 宠物商人 `d/city/npc/oldman` 的变量叫 `class`（2026-10-18，KB 04 §6.14）

`string *class = ({ "dragon", "phenix", ... })` 是全局变量，可 `class` 在 FluffOS 里是保留字（结构体），`syntax error, unexpected L_CLASS`，老头载入不了，城里的宠物买卖整个没了。变量改叫 `pet_class`（7 处；`pet->set("class", ...)` 里的是字符串，不动）。从起始房间沿出口走能到的房间和人物里，这是唯一一个载入失败的（`scripts/lpc_reach_census.py --load`：2,240 间房 2,240 间载入，786 个对象 785 个载入）。载入：通过。

## 补回本库没有的基类文件（2026-10-18，KB 04 §6.15）

下面这些基类本库没有，继承它们的对象（房间、NPC、物品）整批载入不了（`inherit XXX;` 的宏没定义，或者 `inherit "/std/…";` 的文件不在）。同系的库里有同名文件，两库有大量逐字节相同的文件（亲缘关系），所以从那边原样拷来，缺的宏补进全局头文件 `include/globals.h`：`/inherit/weapon/ring`（宏 `RING`）←haiyang2，2 个对象继承它，抽样 2/2 载入。每个基类补回后单独载入、再抽样载入使用它的对象，基类载不进来或者一个用户也载不进来的就撤掉（本库撤掉了它们，不再补）。（`scripts/lpc_restore_bases.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 42 处、25 个文件：`pixie-sword`→`bixie-sword`（12 处）、`pixie-jian`→`bixie-jian`（9 处）、`shaolin-shnfa`→`shaolin-shenfa`（5 处）、`choushui-zhang`→`chousui-zhang`（4 处）、`tiaji-jian`→`taiji-jian`（2 处）、`lingbo-weibu`→`lingboweibu`（2 处）、`shenxingbaibian`→`shenxing-baibian`（1 处）、`jingding-zhang`→`jinding-zhang`（1 处）等共 14 个名字。（`scripts/lpc_fix_skill_names.py`）

## set_name 的 id 参数传成字符串（2026-10-19，KB 06 §7.260）

`set_name("海口大碗", "bowl");` 把物品的 id 写成了字符串，本库的 `set_name(string name, string *id)` 要的是数组，驱动在编译时报 `Bad type for argument 2 of set_name ( string * vs string )`，整个物件载入不了；旧驱动不检查参数类型，字符串里照样找得到这个词，物品能用 id 称呼。改成 `({ "bowl" })`，共 2 个文件：`/d/baituo/npc/obj/bowl.lpc`、`/d/baituo/obj/bowl.lpc`。（`scripts/lpc_fix_set_name_id.py`）

## laozhe 的 command("give yancao to", me)（2026-10-19，KB 06 §7.266）

`d/heimuya/npc/laozhe.lpc`（黑木崖的老者）的 `init()` 里写着 `command("give yancao to", me);`，`command()` 只收一个字符串，驱动报 `Too many arguments to 'command'`，整个 NPC 载入不了。照 cctx、fys 等库已经改好的写法，改成 `command("give yancao to " + ob->query("id"));`（`ob` 是刚进房间的玩家）。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 被注释吞掉的 inherit / include（2026-10-19，KB 06 §7.274）

`/d/shaolin/npc/obj/heisuo.lpc`：`#include <weapon.h>`；`/d/shaolin/obj/heisuo.lpc`：`#include <weapon.h>`。这些指令接在上一行 `//` 注释的末尾（档案里丢了换行），成了注释的一部分，驱动看不到：缺 `inherit` 的技能报 `Undefined function offensive_target`，缺 `#include <weapon.h>` 的兵器报语法错误。`scripts/lpc_fix_swallowed_directive.py` 把换行放回去。载入检查 2 个文件，2 个原来编译不过、现在载入，没有退步。

## 载入不了的零碎文件（2026-10-19，KB 03 §4.7、KB 04 §6.10）

- `d/shenlong/jushi.lpc`、`sea.lpc`、`sea2.lpc` 里 `me->name() + "\241\243\n"` 的 `\241\243`（GBK 的「。」写成八进制转义，旧驱动把这两个字节原样发给 GBK 客户端）改成「。」；新驱动报 `Invalid UTF8 codepoint in string literal`，三个房间（共 4 处）载入不了。

逐个载入与 HEAD 对比，没有退步。

## 玩家打造兵器模板没有打造者时（2026-10-19，KB 06 §7.275）

`/last_modify/weapon/m_axe.lpc`、`/last_modify/weapon/m_blade.lpc`、`/last_modify/weapon/m_club.lpc`、`/last_modify/weapon/m_gou.lpc`、`/last_modify/weapon/m_hammer.lpc`、`/last_modify/weapon/m_staff.lpc` 等（共 8 个）的 `create()` 开头 `me = this_player();` 之后无条件读 `me->query("weapon/name")` 等打造数据。房间刷新时没有人在场（`me` 为 0），或者 NPC 在别的 NPC 的命令环境里 `carry_object()` 这个模板（NPC 的 `weapon` 属性是文件名字符串），旧驱动里读出来是 0 或字符串，`switch` 照样落到 default；新驱动报 `Bad argument 1 to EFUN call_other()` / `Bad argument 1 to switch`，NPC 和它所在的房间载入不了（`--walk` 普查里一个玩家走进房间就触发）。在 `//读入数据` 之后加 `if (!me || !mapp(me->query("weapon"))) { setup(); return; }`：没有打造者就留一个没有名字的空模板，玩家打造的流程不变。

## 帮派文件里丢掉的引号（2026-10-19，KB 03 §4.6）

- `d/yixing/doc/set_bang.h` 第 82、84 行：两句帮主的话，最后半个字连同结尾的引号一起丢了（`…景仰之情<乱码>);`），下一行的开头引号把它闭合，后面的汉字被当成代码（`Illegal character 0xe8`），宜兴帮主 `d/yixing/npc/bangzhu.lpc` 从来载入不了。字串照 nt7 里完好的拷贝补回（`犹如滔滔江水连绵不绝。`、`帮主的敬仰犹如黄河泛滥一发不可收拾。`），引号补上。
- 同一文件第 45 行 `level = ceil( pow( … ) ) * 4 / 5;` 把浮点数存进 int，补 `to_int()`。
- `d/yixing/doc/info_store.h`、`info_biao.h`、`info_guest.h` 没有重复包含的保护（本库其他拷贝有）：`bangzhu.lpc` 自己 include 一遍，`bangzhu_duty.h` → `guanjia.h` 又 include 一遍，四张表被声明两次；加上 `#ifndef __YIXING_INFO_*_H__`。`bangzhu.lpc` 同时继承 `NPC` 和 `F_SSERVER`，两条路都带来 `clean_up()`（`clean_up() inherited from both …`），写出 `int clean_up() { return sserver::clean_up(); }`，行为不变。

载入 `d/yixing/npc/` 的 bangzhu、biaotou、bangzhu2、cl_bei：HEAD 通过 3 个，现在通过 4 个（`bangzhu.lpc` 现在载入），没有退步。

## 标准整理轮（2026-10-19，`scripts/toolkit_fix.sh`）

本库在新驱动下重扫，机械修复：3 个未使用的局部变量。修后与 HEAD 逐个物件对比载入，没有退步。

## 同名全局表（2026-10-19，KB 04 §6.10）

`open/xiangyang/task/guo.lpc` 把 `zzzjob.lpc` 和 `teamjob.lpc` 两个片段 `#include` 进同一个对象，两个片段各有一张 `mixed names` 任务地点/人名表，后一张触发 `Redeclaration of global variable 'names'`。两个片段的函数按编译顺序各用各的那张，所以 `teamjob.lpc` 的表改名 `team_names`（`nosave`，一处引用同步），行为不变。`open/xiangyang/task/guo.lpc`、`teamjob.lpc` 修前修后都载入，警告消失。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。改动：`/d/baihuagu/yangfeng.h`（1 处）、`/d/gumu/liangong1.lpc`（1 处）、`/d/mingjiao/shanmen.lpc`（1 处）。另有 `/d/city/npc/majiang.lpc`（2 处） 的条件下面做的是别的事（`==` 和 `||` 也可能是本意），保持原样。

## 深度功能测试（§10.7，2026-10-20）：实机指令扫描（KB 08 §10.16）

在 FluffOS 923cdbc0 上用 `scripts/play_boot.sh` + `mudplay.py` + `playsweep.py` 起一个实例，对每条指令各发十种参数（空、`me`、`here`、`1`、`all`、三个词、`-h`、`?`、中文、300 个字符），同时看驱动控制台和玩家屏幕：普通玩家指令 147 条（1,470 行），巫师指令（`imm` / `wiz` / `arch` / `adm`）970 行。找到并修复的程序错误：

1. **`exit` / `quit` 永远退不出去**（KB 06 §7.286）。`cmds/usr/exit.lpc` 的 `savequit()` 里 `a = link_ob->save()` 之后判断 `a == 1 && me->save()`；`save_object()` 返回写出的字节数，不是 1，所以每个玩家 `quit` 都先显示再见，再显示“警告：档案保存失败，无法退出游戏”，连接不断开。xiakexing100 在 7 月修过，xkx100 漏了：改为 `if (a && me->save())`。实机：`exit` 之后连接关闭，重新登录是新的身体，控制台无错误。
2. **`adm/daemons/npcd.lpc` 从来没有编译过**。`random_move()` 里 `object dest;` 装的是 `exits[dir]` 的路径字符串，`find_object(dest)` / `load_object(dest)` 编译期就报 `Bad argument 1`，整个 NPC 精灵载入失败；`natured` 每天早晨的 `create_thief()` 因此报 `No program in object '/adm/daemons/npcd'`。改为 `string dest;`（xiakexing100 本来就是 `string`）。
3. **`feature/damage.lpc` `heal_up()`**：`environment(this_object())->is_chat_room()` 对没有环境的 NPC 每个心跳报一次 `Bad argument 1 to call_other`；加 `environment(this_object()) &&`（xkx100utf8 已有）。
4. **`boss 1`**（KB 06 §7.285）：`read_file("/open/shit.txt")` 的文件不在存档里，`write(0)` 报错，而屏幕已被清空、消息被屏蔽（`block_msg/all`）；改为 `if (stringp(msg)) write(msg);`。
5. **`news`**（KB 06 §7.285）：指令先 `call_other("/u/qingyun/workroom", "???")`，`inherit/misc/bboard.lpc` 的 `setup()` 又把更新公告板 `move()` 到那里；这个巫师目录存档里没有，每次 `news` 都报 `call_other() couldn't find object`。两处都加 `file_size(路径 + ".lpc") > 0 &&`，板子留在原地，`news` 照常读公告。
6. **`to`（`cmds/usr/to.lpc`、`cmds/wiz/to.lpc`）不能编译**（KB 06 §7.284）：`(: this_object(), ({ "do_to", me, arg }) :)` 里的局部变量让整个指令 `Illegal to use local variable in functional`。改为 `(: call_other, this_object(), "do_to", me, arg :)`。实机：`to say 第一行` / `这是第二行` / `.` 显示“你说道：第一行 这是第二行”。
7. **`callouts`**（KB 06 §7.287）：`call_out_info()` 的每一项只有 3 个元素，`info[i][3]` 在第一行就 `Array index out of bounds`；改为 `(sizeof(info[i]) > 3 ? info[i][3] : 0)`。
8. 其他巫师指令：`cip` 不带参数时 `sscanf(0, ...)`（加用法提示）；`w_lian` 无参数时 `(__DIR__ "enable")` 指向不存在的 `/cmds/wiz/enable`（改指 `/cmds/skill/enable`）；`clone` 里 `if (msg = "none") msg = "";`（赋值写成了比较，自定义复制讯息永远被清掉；改为 `==`）。
9. **任务 NPC 的 `random_move()`**（KB 06 §7.288）：`clone/quest/questyinshi`、`questman`、`questjianxi`、`questxuncheng`、`bwdhnpc` 和 `clone/haojie/shashou` 走动前先问目的地房间 `no_fight`，`find_object(dest)` 在房间还没载入时是 0，每个心跳报一次 `Bad argument 1 to call_other`，NPC 走不出第一个房间；改为 `(find_object(dest) || load_object(dest))->query("no_fight")`。
10. **浩劫 `adm/daemons/disaster.lpc` 的 `verdict_time()`**（KB 06 §7.289）：宣布战果的 `message()` 里 `lead->name()`，接战书的玩家若已离线 `lead` 是 0，报错后 `LOGIN_D->set_madlock(0)` 不再执行，戒严一直不解除，`cmds/usr/exit.lpc` 因此对所有人拒绝 `quit`。改为 `(lead ? lead->name() : "各派豪杰")`。

已查、不是错误：`task`、`help`、`map`、`sos`、`edemote`、`converse`、`wizmap` 是翻页器 / 编辑器 / 对话提示，扫描器按“需要退出”记录；`boss` 之后屏蔽消息是设计（`bossgone` 解除）。修复后同一份扫描重跑：控制台无新错误。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 16 处）。改动：`/d/changan/npc/majiang.lpc`（3 处）、`/d/changan/npc/matong.lpc`（3 处）、`/d/changan/puke-room.lpc`（4 处）、`/d/city/npc/matong.lpc`（3 处）、`/d/city/shufengguan.lpc`（1 处）、`/d/hangzhou/npc/meipo.lpc`（1 处）、`/quest/weixiaobao.lpc`（1 处）。

## `callouts`：`sizeof(info[i]) == 4` 把每一行都挡掉了（2026-10-20，KB 06 §7.287）

驱动的 `call_out_info()` 每项只有 3 个元素，输出行前的守卫 `if (sizeof(info[i]) == 4)` 永远不成立，指令只打印表头。改为 `>= 3`。改动：`/cmds/adm/callouts.lpc`（1 处）。

## `purge` 指令：`SAVE_EXTENSION` 未定义（2026-10-20，KB 04 §6.11）

`cmds/wiz/purge.lpc` 用了 MudOS 的预定义宏 `SAVE_EXTENSION`（4 处），FluffOS 里叫 `__SAVE_EXTENSION__`，指令编译不过；`lpc_fix_predefined_macro.py` 之前因为 `cmds/wiz` 路径含 `/wiz/` 被跳过，现在只跳过顶层的巫师家目录。已改。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/obj/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## sefun `cat()`：缺文件时 `write(0)` 报错（2026-10-20，KB 06 §7.297）

`void cat(string file) { write(read_file(file)); }`：文件不存在（压缩包没带的欢迎/公告文件，或只有运行中的 mud 才会写的日志）时 `read_file()` 回 0，`write(0)` 在本驱动里报 `Bad argument 1 to receive()`，调用者（登录对话、`cat` 指令）被中断；老驱动什么也不打印。改成 `write(read_file(file) || "");`（`scripts/lpc_fix_cat_unchecked.py`）。改动：`/adm/simul_efun/file.lpc`。

## 翻页器 `start_more(read_file(...))`：文件缺失时 `explode(0)`（2026-10-20，KB 06 §7.300）

东方故事系的翻页器 `void start_more(string msg) { ... explode(msg, "\n") ... }` 被这样调用：`start_more(read_file(HELP_DIR + "help/topics"))`、`start_more(read_file(NEWS))`。压缩包没带的文件使 `read_file()` 回 0，`explode(0, ...)` 在本驱动里报 `Bad argument 1 to explode()`（不带参数的 `help` 指令就是这样出错的），老驱动把 0 当空文本。在 `start_more` 开头加了 `if (!stringp(msg)) return;`（`scripts/lpc_fix_start_more.py`）。改动：`/feature/more.lpc`。

## `get_config(__MUD_PORT__)` 经旧版 `runtime_config.h` 得到字符串（2026-10-20，KB 06 §7.302）

本库的 `include/runtime_config.h` 是老 MudOS 的编号（整数设置从 15 起，本驱动从 256 起），`get_config(__MUD_PORT__)` 读到的是另一项设置（字符串），`(int)` 又只是编译期标注，于是 `socket_bind(fd, LOCAL_PORT())` 报 `Bad argument 2 to socket_bind()`，版本守护进程 `port = get_config(__MUD_PORT__) + VERSION_PORT` 是字符串相加。头文件自己的注释写明 `get_config(__MUD_PORT__) == __PORT__`，所以代码里的这个调用（连同外面的 `(int)` / `to_int()`）改成了驱动的预定义 `__PORT__`（`scripts/lpc_fix_mud_port.py`）。改动：`/include/getconfig.h`（1 处）。

## `d/luoyang/obj/xiang.lpc`：`chuangli` 先 `explode(read_file("/log/PARTY"))`（2026-10-20，KB 06 §7.326）

关帝像的 `chuangli`（`kaibang`）指令在检查年龄和经验之前就读 `/log/PARTY`，那是运行中的 mud 记录已创立帮派的文件，全新的树里没有，`explode(0)` 报 `Bad argument 1 to explode()`：任何人敲 `chuangli 什么` 都是系统错误，而不是“你还嫩着呢”。改成 `file = read_file("/log/PARTY") || "";`（空串的 `explode` 是空数组）。xkx100utf8 和 nt7 是 gitlink 库（fluffos-org 上游），同一行在那里没有改。加载检查各 1/1。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库有 1 个 NPC 文件写成 `set("chat_msg", ({ }))`（或 `chat_msg_combat`）并带正的 `chat_chance`（例如 `/d/city/npc/lulixian.lpc`），每次心跳有 `chat_chance`% 的概率 `random(0)` 为 0、`msg[0]` 报 `Array index out of bounds`（驱动捕获，心跳继续，但每次一条运行时错误），这个 NPC 在内存里就一直发生。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/inherit/char/npc.lpc`、`/migong/obj/npc1.lpc`（共 2 个文件）。

## 巫师命令不带参数时对 0 调用 efun（2026-10-21，KB 06 §7.336）

巫师（管理员）把命令敲成不带参数时，驱动把 0 传给字符串参数；下面的命令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`，这条指令从来没有用过。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py` 在第一处使用参数的语句前加守卫：没有 `help()` 的是 `return notify_fail("…\n");`。改动（1 个文件，括号里是接住 0 的 efun）：`/cmds/wiz/inittask.lpc`（`sscanf`）。加载检查 HEAD 与工作树对照，没有退步。

## `blockade` / `recover`：`data/keep` 不存在，解封之后世界仍然锁着（2026-10-21，KB 06 §7.340）

管理员扫描里 `blockade` 报 `Error copying file from /data/user/f/fluffos.o to /data/keep/fluffos, Error: No such file or directory`，随后的 `recover` 在第一个 `cp()` 上死于 `*/data/keep/fluffos: lstat failed`，来不及执行最后的 `LOGIN_D->set_madlock(0)`：封锁解不开。`data/keep/` 是运行时目录，git 克隆里没有空目录。`blockade` 在第一次写之前 `if (file_size("/data/keep") != -2) mkdir("/data/keep");`（`mkdir()` 失败答 0，不抛错），`recover` 对没有保存档的玩家 `if (file_size(src) < 0) continue;`，其余照常恢复、照常解锁（`scripts/lpc_fix_keep_dir.py`，hy5 上实测：没有保存档时 `recover` 答“时空解封完毕”，`blockade` 建出 `data/keep` 并保存，`recover` 取回并删除）。改动（2 个文件）：`/cmds/arch/blockade.lpc`、`/cmds/arch/recover.lpc`。

## 任务分配 `quest`：按顺序找目标的备用循环用了 `living[j]`（2026-10-21，KB 06 §7.347）

`/feature/quest.lpc`：先随机挑目标（`j = random(sizeof(living))`），挑不中再“按顺序找”：`for (i = 0; i < sizeof(living); i++) if (check(living[j], ...)) { target = living[j]; break; }`。下标写成了 `j`（上一个循环最后一次的随机下标），备用循环把同一个 NPC 检查 `sizeof(living)` 遍，世界小的时候任务就分不出去。xkx100 的原文就是这样，派生库照抄。改成 `living[i]`。

## 追杀任务 `killer1.lpc`：奖励循环里的 `me` 从没赋值（2026-10-21，KB 06 §7.348）

黑衣人 `die()` 对每个在场的追杀者发经验和潜能，循环里写的是 `me->add("combat_exp", exp)`（nitan 系是 `addn("combat_exp", exp, me)`），`me` 要到循环之后才被 `find_player(owner)` 赋值：xkx100 系抛 `Bad argument 1 to call_other()`，nitan 系把奖励悄悄记到 0 上，追杀者什么也拿不到。循环里先 `me = obs[i];`。改动：`/clone/quest/killer1.lpc`。

## 马钰 `waiting()`：等了 300 秒没等到的惩罚落在没赋值的 `ob` 上（2026-10-21，KB 06 §7.348）

七星阵的等待超时分支写的是 `ob->add("score", -5000)`（nitan6 系 `addn("score", -5000, ob)`），`ob` 在这个分支里还是 0：超时那一刻抛错，之后的 `do_back` 已经排好了所以只是少了惩罚。hhsj、nitan170911、xfbhh 里同一处写的是 `me`（带着任务的玩家），照改。改动：`/kungfu/class/quanzhen/ma.lpc`。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 12 条注册（9 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/clone/medicine/nostrum/gaoyao.lpc`（`do_eat`）、`/clone/misc/city/city.lpc`（`do_chakan`）、`/d/changan/qishi.lpc`（`do_pass`、`do_resign`）、`/d/city/weiqishi.lpc`（`do_pass`、`do_resign`）、`/d/shenlong/obj/sg_mianzhao.lpc`（`do_open`）、`/d/wudujiao/huxue2.lpc`（`do_train`）、`/inherit/misc/fboard.lpc`（`do_list`）、`/kungfu/class/yunlong/xutianchuan.lpc`（`do_skills`）、`/last_modify/questobj/yinzhen.lpc`（`do_bawan`）。最多的函数名：`do_pass` 2 处、`do_resign` 2 处、`do_skills` 2 处、`do_eat` 1 处、`do_chakan` 1 处。

## 基类的 `add_action` 登记：处理函数只在后代里定义，基类自己被加载时报错（2026-10-21，KB 06 §7.349）

房间、NPC、公告板这类基类，`init()` 里登记的 `add_action("函数", "动词")` 的函数只由继承它的后代定义；基类对象自己被直接加载（房间可以走进去、NPC 可以克隆）时，访客输入这个动词，驱动报 `*Function for verb 'x' not found.`（第一轮扫描把这些当成“有后代定义，是活的”放过了，`scripts/lpc_verify_handlers.py` 在基类对象上跑 `function_exists()` 才看出来）。登记前加 `if (function_exists("函数", this_object(), 1))`（第三个参数 1：默认 `function_exists()` 把 `protected` / `private` 函数当作没有定义），后代照常登记。共 1 处、1 个文件（`scripts/lpc_fix_dead_add_action.py --guard`）：`/d/yixing/npc/bangzhu.lpc`（`do_xue`）。

## 对象路径里的 `..`：`new(__DIR__ "../obj/x")` 报 `Read access denied`（2026-10-22，KB 06 §7.351）

`__DIR__` 是当前文件所在目录（带结尾斜杠），`__DIR__ "../obj/x"` 就是 `/d/zhiye/npc/../obj/x`；驱动的 `legal_path()` 不接受带 `..` 的路径，`new()` / `load_object()` 直接抛 `*Read access denied.`（实测，`find_object()` 对它答 0）。走库自己的 `carry_object()` / 房间 `objects` 表的路径，库的基类会先规范化，能用；直接把路径交给 `new()` / `clone_object()` / `load_object()` / `move()` 的不行，调用到那一步才报错。改成规范化后的绝对路径（`scripts/lpc_fix_dotdot_dir.py --direct`）：`/d/wudang/npc/xiaocui.lpc`（`__DIR__ "../obj/nuerxiang"` → `"/d/wudang/obj/nuerxiang"`）。

## 缺失物品的 `new()` / `carry_object()` 调用链加了保护（2026-10-22，KB 06 §7.73 补充）

`new(路径)->move(...);` / `carry_object(宏("x"))->wear();` 这类语句，路径指向的文件在这个压缩包里没有：`new()` 返回 0，`->move()` 在 0 上报 `Bad argument 1 to EFUN call_other()`。在 `create()` 里这个对象永远加载不了，在 `reset()` 里第一个缺失物品之后的刷新每次 reset 都被跳过。2 个文件里 3 处（`new`）改成 `{ object new_ob = new(路径); if (new_ob) new_ob->move(...); }`（`scripts/lpc_guard_carry_object.py --new`：路径按这个文件自己看到的宏解析，宏名冲突、虚拟对象路径一律跳过）。 对这 2 个改动文件做加载检查（HEAD 与工作区对比）：HEAD 能加载 2 个，现在 2 个（新增可加载 0 个，回归 0 个）。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 还剩 4 个函数没有补（other 2, inquiry 2）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/adm/daemons/npcd.lpc`:`exert_function`、`/adm/daemons/npcd.lpc`:`perform_action`、`/d/yixing/npc/bangzhu.lpc`:`ask_skills`、`/d/yubifeng/npc/huyidao.lpc`:`ask_book`。

## `(: 函数名 :)` 指针指向本库没有的函数：只含这个指针的行加了注释（2026-10-22，KB 06 §7.355 补充）

`inquiry` / `item_desc` / `chat_msg*` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：用到时（`ask`、`look`、NPC 闲聊）驱动抛 `*Undefined lfun pointer called: 函数名`，这一拍心跳的后半段被跳过。这些函数没有可以补回的来源（别的库同一路径的文件里没有，或者它还要用本库没有的东西），所以 2 个文件里 4 行只含这个指针的行（`"武功": (: ask_skills :),` `"skills": (: ask_skills :),` `"刀谱": (: ask_book :),`）加了注释，原文保留并写明原因，这一项当作没有这个话题 / 物品 / 闲聊条目（`scripts/lpc_fix_dangling_lfun.py`；`#include` 的文件在库里缺失的对象、指针不在整行上的写法没动）。 前提（`function_exists()`）和加载检查（HEAD 与工作区对比，本库改动的 `.lpc` 文件）的结果见 KB 06 §7.355：没有一个回归。
