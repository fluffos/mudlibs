
## WASM 修复摘要（迁移自 meta.json 的 group_note）

金庸题材 mudlib，游戏内标题为"江湖风云II 之 辽宁风云再起"（Jianghu Fengyun II）。异常干净：完全没有发现 mudlib 代码 bug——宏本来就和 config.fluffos 一致，is_chinese()/check_legal_name() 本来就是正确的码点判断，指令表开箱即用，也没有 this_player()/previous_object() 覆盖问题。完整的注册→look→score→quit 流程第一次真实尝试就顺利跑通。唯一需要做的是管理员播种：把 fluffos/loginpass1 加入既有的 CRLF 格式 adm/etc/wizlist，游戏内"★ 您目前权限：(admin)"显示确认生效。排版格式化后也重新验证过完整流程。格式化工具发现 2 个真正损坏的档案（d/huashan/map.lpc，一张 ASCII 地图，和手足档案里见过的同一种分词器混淆模式；d/player/fyue_room.lpc，一段房间描述）——两者都用 git checkout 还原。d/city/sj.lpc 有和 ffxymud 完全相同路径下那份档案一样的、转档之前就存在的、无法到达的缺引号损坏——未修，不是格式化工具造成的。

## 深度功能测试（§10.7，2026-08-04）

此前的会话确实完整走通了注册→look→score→quit，但"没有发现任何需
要修改的 mudlib 代码"这个结论是没有经过战斗/死亡测试就下的——本轮
原生 driver（端口 40137）实际玩到了移动、留言板、战斗、以及一轮完
整的死亡→复活验证，结果发现这份档案并不像此前记录的那样"完全干
净"，找到并修复了三类真实 bug，全部是本项目已经归档的常见模式。

**主动检查（对照 AGENTS.md 已归档的 bug 类），发现并修复三处真实
bug**：

1. **§7.34 printf 调试泄漏（新实例，两条并行代码路径都有）**：
   `adm/daemons/logind.lpc` 的 `get_name()`（自己输入中文名字的路
   径）和 `get_resp()`（接受系统随机中文名字的路径）里各有一行
   `printf("%O\n", ob);`，紧跟在中文名字确认之后、设定密码之前，
   两条路径都会把连线对象的原始调试信息直接打到玩家屏幕上。此前
   那一轮 WASM 验证很可能测的是同一条路径没有触发第二条、或者没
   有留意这行输出，才被记成"零 bug"。已删除两处。
2. **第 15 例 §7.68 复活软锁死**：`d/death/npc/{wgargoyle,
   bgargoyle}.lpc`（鬼门关的白无常/黑无常，`DEATH_ROOM`
   `/d/death/gate` 直接摆着白无常，其 `north` 出口
   `/d/death/gateway` 摆着黑无常，两者均可达）的 `death_stage()`
   把"玩家暂时不在场"和"对象已销毁"合并成同一个提前 `return`。已
   拆分为标准修法：`!ob` 永久放弃，`!present(ob)` 改为 5 秒后重
   试。这次 `REVIVE_ROOM`（`/d/city/wumiao`，武庙）和 `DEATH_ROOM`
   指向的文件都确认存在——不是上上一轮 `fys` 那种宏指错文件的情
   况。白无常/黑无常两份文件里的"合上册子"台词本身没有损坏（和
   `fys`/`njhhdxdes2hx` 那两次遇到的"阁上册子"/"□上册子"不同，
   这份档案的拷贝是干净的）。
3. **§8.9 食物/饮水错误对象判断（新实例）**：`enter_world()` 里
   `if (ob->query("age") == 14)` 查询的是临时连线对象 `ob`，不是
   持久角色对象 `user`——`ob` 从来没有 `age` 属性，这个条件永远为
   假，食物/饮水初始化代码块从未真正执行过。改成
   `user->query("age") == 14` 后现场验证生效。**注意**：本轮注册
   测试时 `score` 显示食物/饮水两条本来就是满格——说明这个 bug 在
   这份档案里目前是"哑火但无害"的（角色的食物/饮水另有默认值来源
   ，不完全依赖这段代码），但判断逻辑本身确实是错的、和本项目其
   它 6 个已确认的同款实例（`jyqxc`/`bixiecanyang`/`ldtxii` 等）
   写法一致，按既定原则修正，不因为"目前没造成可观察后果"就跳过。

**完整游玩记录**：
1. 用真实中文名字"秦风"（id `qinfeng`）注册成功，落地"客店"（这
   份档案的出生点似乎是随机的几家客栈/客店之一——本轮和更早那次
   注册测试落地的不是同一家），场景里有真正可读的留言板和店小二。
2. 移动：客店→南大街（可以看到"天安门"这样的写实地标，和金庸江
   湖的门派场景混搭），沿途场景描述、出口、NPC 列表均正常渲染。
3. 战斗测试：`wimpy 0` 后 `kill xiao fan`（南大街的小贩），测试
   角色几拳都没打中对方就被一套连续动作打死（攻击力起始只有 1，
   内容/数值现象，不是 bug）。
4. 死亡→复活验证：死亡后正确落地"鬼门关"，白无常在场。**完全不
   打断地等待**（断开连线后静默等待 30 秒，再用新连接重新登录查
   看结果）确认：五段对话全部播完，`reincarnate()` 成功，角色正
   确落地"武庙"（`REVIVE_ROOM`），`score` 显示"你共死亡：1次"，
   食物/饮水恢复满格，可以正常继续游玩。

**结果**：整个测试会话（含一轮死亡复活循环、一次修复后重启）
`debug.log` 全程为空，没有任何真实的 `error:`/`Bad argument`/
`No program`/`Too deep recursion` 记录。测试角色存档
（`data/{login,user}/{q/qinfeng,s/shenmu}.o`，后者是命名冲突后弃
用的第一次尝试）保持未跟踪；三处代码改动均已用 formatter 校验
（`{"errors":0}`）。


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

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 93 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（2026-08-13，round two，新驱动重测）

Re-tested against the freshly-rebuilt `build-debug/src/driver`（post
全库 `quest_times`/`win_times` `%`-operator 修复 + Warning/warning
驱动文本回退）。与手足档案 `jhfy` 不同，这份档案的 `log_error()`
此前**没有**被修复过——两者虽是姊妹档案，`log_error()` 的修复状态
却各自独立，印证了"不能从血统关系假设 bug 状态"这条本轮反复验证过
的教训。

### 发现并修复的 PROGRAMMING bug

1. **`log_error()`（`adm/obj/master.lpc`）完全没有严重度检查（AGENTS.md
   §7.34-class，与本轮 `wdxtym`/`ffxymud`/`fy2mg`/`fys`/`hc`/`hy`/
   `hy2000`/`hy2002`/`hy3`/`hy5`/`hyiishzdscbb` 同一原始形状）**：
   `if (this_player(1)) efun::write(...)`——不区分巫师/玩家，也不区
   分警告/错误。修复：加上 `strsrch(message, "arning:") == -1` 判
   断。
2. **`log_file()`（`adm/simul_efun/file.lpc`）完全没有 `assure_file()`
   保护（AGENTS.md §7.11-class 的又一确认实例，和姊妹档案 `jhfy`
   完全同一形状）**：`adm/daemons/logind.lpc` 的 `get_gender()`
   （**新角色注册流程的最后一步**）紧跟着调用
   `log_file("login/newid.log", ...)`——`LOG_DIR` 下的 `login/`
   子目录若不存在，会在每一个全新角色注册完成的那一刻未捕获抛出。
   已补上 `assure_file(LOG_DIR + file);`（含前向声明）。

### Proactive checks（无需改动）

- `win_times` 修复确认存在且正确：`d/city2/npc/refereew.lpc:146`。
- 未发现 `message()` simul_efun 包装函数——不适用
  message()-missing-varargs 这一类 bug。

### 管理员账号：存档从未真正提交

README 记录"账号本身通过正常注册流程创建，已在游戏内确认权限显示
正确"——`git log` 确认这个存档从未被提交过，本地 `work/` 目录里也
不存在。已用真实注册流程（英文 id → 确认建立 → 中文名 → 密码
`loginpass1` → 确认密码 → 天赋 0 随机 → 接受 → 邮箱 → 性别）重新
创建 `fluffos`/浮浮，`score` 确认"★ 您目前权限：(admin)"。

### 一次测试方法论的排查记录（非 bug）

`update /adm/simul_efun/file` 报错 `*No program in object
'/adm/simul_efun/file'!`——排查后发现 `adm/simul_efun/file.lpc` 是
被 `#include` 进 `adm/obj/simul_efun.lpc`（`simulated efun file`
配置项指向的档案）的，本身不是一个独立编译单元，不能直接 `update`。
改用 `update /adm/obj/simul_efun` 也报错（`destruct()` 相关，热重
载 simul_efun 对象本身在多数驱动上都有特殊限制，属于测试方法的局
限，不是这份档案的 bug）。改用一个普通对象 `update
/adm/daemons/logind` 成功验证了真正的写权限。`log/debug.log` 里唯
一新增的两条运行期错误就是这两次排查性尝试留下的痕迹，均已确认与
本轮修复无关。驱动最终按精确 PID kill，`ps -p` 确认已退出。

### 已清理

- 管理员 `fluffos` 的存档已提交（`data/{login,user}/f/fluffos.o`）。
- `data/{login,user}/{q/qinfeng,s/shenmu}.o` 是此前会话遗留的未提
  交测试存档（`Aug 4` mtime，早于本次会话），未受本轮任何操作影
  响，未触碰。

## §7.100 房间基类 replace_program() 扫尾修复（2026-08-19）

`ROOM` 宏（`/inherit/room/room`）在本档案 2,070 处房间文件的
`create()` 里紧跟 `inherit ROOM;` 之后又多余调用了一次
`replace_program(ROOM);`——AGENTS.md §7.100 记录的同一个休眠 bug，
和 `yzxiiizylfy`/`xyzxiiylzymh`/`xyzx3`/`xysylmhb` 同一双 roommaker
副本血统（`clone/misc/roommaker.lpc`、`d/huanggon/obj/
roommaker.lpc` 目录结构完全一致）。用 `fix_710_room.py` 扫过
`work/`，删除 2,068 处标准形状；两份房间建造工具各剩 1 处字符串
拼接变体，手工改成 `str += "\n\tsetup();\n}\n";`。修复后 `work/`
下 0 处存活残留，`work/data/` 下没有真实 `.lpc` 源码命中。`git
diff --stat` 显示 2068 个文件净删 2070 行、增 2 行，与脚本自报数
字 + 2 处手工编辑吻合。

驱动干净启动（零新增编译错误、端口 40137 正常监听、`debug.log`
无任何"cannot replace"/"cannot bind"行）。管理员 `fluffos`/
`loginpass1`（本档案自己的密码，与其它 XYZX 血统档案的
`Mud@2026` 不同，也没有 '2060' 握手门槛）实机登录成功，`look`/
`score`/`quit` 均正常，全程 `debug.log` 保持干净。管理员存档的时
间戳漂移已用 `git checkout HEAD --` 还原，未提交；此前会话遗留的
无关测试存档（见上）未触碰。驱动按精确 PID 结束。

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

新角度：醉仙楼购物 + 丐帮左全拜师。2026-08-13 第二轮只测了战斗/死亡
和 `log_error`/`log_file`，没有买东西、也没有拜师。这是夕阳再现/江湖
风云血统（游戏内标题「江湖风云录II」），端口 40137。第一输入就是
「请输入您的英文名字：」，不要发 2060。密码是 `loginpass1`，不是
`Mud@2026`。

### 实测过程

管理员 `fluffos` / `loginpass1`（权限 `(admin)`）。`clone
/clone/money/gold` 可用。

`goto /d/city/zuixianlou`（醉仙楼，店小二 `d/city/npc/xiaoer2.lpc`，
`F_DEALER`）。`list` 烤鸡腿八十文钱 / 包子五十文钱。`buy jitui` 成功
（「你向店小二买下一根烤鸡腿」）。当场 `i` 是九十九两银子 + 二十个
铜板 + 鸡腿。F_DEALER 对丐帮拒绝购买（穷叫化），必须先买再拜。
`NATURE_D::room_event_fun()` 整段注释掉了，打烊判断拿不到
`event_night`，店开着——既有缺口，不是本轮要修的内容 bug。

`goto /d/gaibang/inhole`，左全源码是 `kungfu/class/gaibang/zuo-qu.lpc`
（文件名少一个 n），`apprentice zuo` 一次成功：恭喜成为丐帮第二十代
弟子。`score` 称谓「丐帮第二十代弟子」、师傅左全。`cmds/usr/save.lpc`
第一次真正调用 `link_ob->save()` / `me->save()`；60 秒内再 save 会假
写「档案储存完毕」但不落盘（`save_time` 冷却，不是 `notify_fail`）。
第一次 save 后 `user.o` 立刻带上 `family_name":"丐帮"` /
`master_name":"左全"` / `generation":20`。杀驱动冷启动再登录，称谓/
师傅/银子铜板还在。烤鸡腿未进 autoload。左全只收男性。

### 发现并修复的 PROGRAMMING bug

1. **华山收徒计数拼写**（与 `wmkj`/`nitan_ceshi`/`nitan_san` 同形，
   静态对照修，本轮拜师走的是左全不是华山）：
   `kungfu/class/huashan/{yue-buqun,yue-wife,feng-buping}.lpc` 的
   `recruit_apprentice()` 写 `add("apprentice_availavble", -1)`，计数
   键名拼错，永远减不到 `set("apprentice_available", 3)` 那个字段。
   三处都改成 `apprentice_available`。

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 5 here-document block(s) repaired (5 with the terminator glued to the last text line, 0 with it indented), so `End of file in text block` no longer hides the room or object behind them: `d/heimuya/shenggu.lpc`, `d/heimuya/tang.lpc`, `d/heimuya/npc/tang.lpc`, `d/quanzhen/manglin1.lpc`, `d/quanzhen/manglin2.lpc`. The terminator must start its line (the lexer's own test, KB 04 §6.10); a glued one lost its newline in the GBK -> UTF-8 conversion together with a half character, which stays out.

## 深度功能测试（§10.7，2026-10-05）— 任务表里的 `.c` 路径与任务守护进程的防护

`scripts/lpc_dynamic_rows.py`：`d/obj/quest/dynamic_location`、`d/obj/quest/dynamic_quest`、`quest/dynamic_location` 里 151 行写的是原档案的 `.c` 路径。转档时文件已改名 `.lpc`，而显式后缀按原样解析，`load_object("/d/x.c")`、`new("/d/obj/quest/x.c")` 返回 0 且不报错（KB 03 §4.2，KB 06 §7.220），所以 `adm/daemons/questd.lpc`、`adm/daemons/taskd.lpc` 读到的每一行都加载不出来：随机任务和任务物品从未生成，在 `create()` 里直接对结果调用 `tar->set()` 的版本还会崩溃，连带加载它的 cron 守护进程和 `give` 的任务钩子。这些行已改为 `.lpc`；另有 36 行指向的文件两种后缀都不存在（档案缺内容），保持原样。
`scripts/lpc_dynamic_quest_guard.py`：2 处 `spread_quest()` 调用（`init_dynamic_quest()` 的循环里）包进 `catch()`，缺失的任务物品或编译不过的房间只跳过那一个任务，守护进程照常加载、其余任务照常生成；`cmds/std/look.lpc` 夜间检查的 `!present("fire", this_player())` 前加 `objectp(this_player()) &&`（房间 `reset()` 销毁物品时 `/feature/move.lpc` 的 `remove()` 会调用 `look_room()`，此时没有 this_player()，`present(…, 0)` 报 `Bad argument 2 to present()`）。
验证：`adm/daemons/questd.lpc`、`adm/daemons/taskd.lpc`和 cron 守护进程在新进程里加载（HEAD 一次，工作树三次，选房是随机的）：HEAD 通过 2 个，工作树三次分别通过 2、2、2 个（共 3 个），无回退；`adm/daemons/taskd.lpc` 在 HEAD 与工作树都加载失败，另有原因，与本次无关。
验证：改动过的 `adm/daemons/questd.lpc`、`adm/daemons/taskd.lpc`、`cmds/look.lpc`、`cmds/std/look.lpc` 在新进程里加载，HEAD 通过 3 个、工作树通过 3 个（共 4 个），无回退。

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `inherit/room/room.lpc`：`make_inventory()` 用 `catch()` 包住 `new(file)`，做不出来就返回 0；`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）；`reset()` 的 `default:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]][j])) continue;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-07）— 空的 `if (current_water == 0) {}`

5 个房间的 `valid_leave()` 里有一行什么也不做的 `if (current_water == 0) {}`（编译警告 `Expression has no side effects`），删去，行为不变：`d/gaochang/room11.lpc`、`d/gaochang/room12.lpc`、`d/gaochang/room13.lpc`、`d/gaochang/room14.lpc`、`d/xingxiu/shanjiao.lpc`。

## 深度功能测试（§10.7，2026-10-07）— 编译警告整理

`scripts/lpc_warnings.py jhfy2 --fix` 加 `scripts/lpc_fix_no_effect.py --apply`，共改动 326 个 `.lpc` 和 3 个 `.h`（多为删去未用的局部变量）。HEAD 与工作树分别加载（新进程）：309 -> 309 通过，无回退；改过的头文件的 34 个包含者 34 -> 34 通过。启动时警告 7 -> 0；新进程登录（输入名字）正常。

## 深度功能测试（§10.7，2026-10-08）— `.lpc` 后缀的定宽切片

`.c` 改名 `.lpc` 时只改了字符串没改切片宽度：`f[<2..] == ".lpc"` 拿两个字符比四个字符，永远不成立（`!=` 永远成立），按后缀筛文件、去后缀的代码因此从不运行或截成 `x.l`（KB 06 §7.238）。`scripts/lpc_lpc_suffix_slice.py --apply` 改了 1 处比较、0 处去后缀（如 `cmds/wiz/ls.lpc`）；改动的文件 HEAD 与工作树分别加载（新进程），无回退。
