
## WASM 修复摘要（迁移自 meta.json 的 group_note）

hy2000 的演进/后期手足档案（hy2000 的 10630/10632 个档案按路径重合；hy2002 是一个多出约 3000 个档案的超集）——同一套 ES2/金庸血统"海洋II"（Ocean II）代码库。修复的 bug（多数是主动套用已知的 hy2000 修法并确认这里同样存在）：（1）过时的 MASTER_OB/SIMUL_EFUN_OB 宏指向 /adm/single/ 死代码副本（§7.56 类）；（2）logind.lpc 的 howmany_visitor()/howmany_card() 和 uptime.lpc 的 LASTCRASH 显示里 §7.54 类的 sscanf(read_file(缺失档案)) 崩溃；（3）adm/daemons/network/dns_master.lpc 的 startup_udp()/send_udp()/send_shutdown() 里那行 socket_close() 的 §7.52 类 socket 掏空——这里特别关键，因为 logind.lpc 的 gb_big5() 流程中途会呼叫 DNS_MASTER->query_muds()/query_svc()，一旦这个精灵编译失败，会静默中止 gb_big5() 剩下的代码，包括最后显示英文名字提示的 write()，导致注册完全无法开始，且没有任何可见错误；（4）logind.lpc 里经典的 §8.1 check_legal_name() 字节数没减半的长度界限（4/10 字符→2/5）加上 i%2==0 门槛和 name[i..<0] 尾部切片（is_chinese() 本身已经是正确的）。GB 和 BIG5 两个编码选单选项都实测正常，不用修。管理员引导既偏离常规的 wizlist 模式，也和 hy2000 的不同：securd.lpc 在 restore_list() 里硬编码了引导用管理员 id "hxsd"，但这个 id 已经是档案里一个真实存在的旧玩家账号（密码未知——新增 AGENTS.md §1.5 bug 类型）——已在旁边追加一行 set("wiz_status/fluffos","(admin)")，用 fluffos/Mud@2026Pass1 正常注册，游戏内"目前权限：(admin)"显示确认生效。完整的注册→look→score→quit 流程在排版格式化前后各验证过一次，用的是真实中文名字。格式化工具发现 2 个真正损坏的档案（cmds/usr/setbak.lpc 的 heredoc 帮助文字，以及 help/help/menpai.lpc——一份被压成一行、每个字符都被重新加空格的纯文本帮助内容档案）——两者都用 git checkout 还原。另外记录：同一 IP 60 秒内只能注册一次新角色，是真实存在的反滥用限制（§10.1 类的有意设计，不是 bug）。

## §10.7 深度功能测试（本次新增）

此前只做过注册→look→score→quit 的浅层验证。本次用 `fluffos` 管理员
账号和一个全新普通角色 `testerxyz`（浮浮二）实际走通了注册→新手引导
→平安城/平安武馆探索→出城→中央广场战斗→死亡→鬼门关复活的完整流程。

### 修复 1：§8.9 食物/饮水年龄检查错对象

`adm/daemons/logind.lpc` 的 `enter_world()`：
`if (!user->query("food") && !user->query("water") && ob->query("age") == 14)`
——`ob` 是登录对象（login object），不是角色本体 `user`，`ob->query("age")`
永远是 undefined，这道门槛永久为假，每个新角色的食物/饮水会静默永远
保持 0。已改为 `user->query("age") == 14`，实测新角色食物/饮水栏正确
显示为接近满格（18/20），确认修复生效。

### 修复 2：两处 §7.68 复活软锁（d/death/npc/{b,w}gargoyle.lpc）

`death_stage(object ob, int stage)` 原代码
`if (!ob || !present(ob)) return;` 把"鬼魂对象已经不存在了"和"鬼魂此
刻只是暂时不在这个房间里（延迟/网络卡顿）"混为一谈，一旦判定瞬间鬼
魂碰巧不在场就永久放弃后续引导，把鬼魂永久卡住。按标准修法拆开：
`!ob` 才是真正放弃，`!present` 改为 5 秒后重试。本次死亡测试里，白无常
(wgargoyle) 的完整六段对话（"你叫什么名字" → ... → "阳寿未尽" → 阴冷
浓雾包围你）全部顺利播放完毕，角色被正确送到复活点（武庙），未卡死。

### 修复 3：新发现的 bug——securd.lpc 的 file_size 被自定义 ACL 误拒（AGENTS.md §7.5 新增变体）

深度测试中，一个全新角色第一次踏入"平安武馆"（新手学武场地）时触发了
一个此前完全没被发现的严重 bug：

```
执行时段错误：*F_SKILL: No such skill (dodge)
物件: /d/pingan/npc/chen2
呼叫来自：/feature/skill.lpc 的 set_skill() 第 20 行
```

根因：`feature/skill.lpc` 的 `set_skill()` 用
`!find_object(SKILL_D(skill)) && file_size(SKILL_D(skill)+".lpc") < 0`
判断技能档案是否存在——本局游戏第一次有人引用某个技能（如 "dodge"）
时，`find_object()` 正确返回 0（还没编译过），于是继续检查
`file_size()`；但 `adm/daemons/securd.lpc` 的自定义 `valid_read()` 对
`file_size` 这个 func 没有像 `load_object`/`include` 一样放行，而是走
了普通的 euid/权限判断——此时触发调用的 NPC（chen2）自己还在
`create()` 执行中途，euid 尚未建立，于是这次 `file_size()` 被 ACL 拒
绝，返回 -1（"文件不存在"的假象），导致 `set_skill()` 误判"dodge"这
个技能压根不存在而 `error()`，chen2 的 `create()` 从这一行起彻底中
断（后续所有 `set_skill()` 调用、装备发放等全部跳过）。

这个 bug 极其隐蔽：**每个技能文件在本局游戏中只会踩中一次**——一旦任
意对象成功 `load_object()` 过一次该技能档（比如巫师手动 `update` 过），
`find_object()` 此后总能命中已驻留的 blueprint，短路掉那条永远出错的
`file_size()` 分支，同一技能不会再触发。这意味着每次全新重启这个 lib
后，第一个踏入武馆（或任何首次引用某项技能的场景）的玩家，会看到该
NPC 的技能/装备初始化在技能列表中间某处神秘"卡住"，而且没有任何面向
玩家的错误提示（只有服务端 debug 才看得到），后续的战斗/招式效果因
此可能整段缺失。这不是 AGENTS.md §7.5 已记录的"编译期访问被拒绝崩
溃"那种硬性崩溃形态，而是同一根因（自定义 ACL 没有放行编译期/文件探
测类操作）的一个安静得多的变体——已把 `file_size` 和
`load_object`/`recompile_object`/`include` 一起加入
`securd.lpc` `valid_read()` 的放行名单，写入 AGENTS.md §7.5 作为新确
认的变体。修复后重启驱动，全新角色第一次进入武馆，`chen2` 的
`create()`（含 `set_skill("dodge", ...)` 等全部技能设置）完整执行、
无任何报错；同样在中央广场首次触发 `dodge.lpc` 的战斗中也确认干净编
译、无报错。

### 战斗与死亡

出城后在（城市）中央广场对"流氓头"（帮派头目 NPC，`combat_exp` 明显
高于新手角色）发起攻击，几回合内被击杀——死亡提示、"江湖谣言"广播、
送入鬼门关的整个链路均正常触发，紧接着完整验证了上面第 2 项的复活
流程。

### 其它检查、确认不适用的已知 bug 类别

- CHARACTER 的 F_* 混入档缺 F_DBASE inherit（§7.78 结构相符检查）：
  本次因时间关系未对 hy2002 单独重复验证，但其 `feature/dbase.lpc`
  与近期在 `shujian3`（同为 ES2 血统）上live-verify过的版本几乎逐字
  节相同（唯有极小差异），且该次调查已确认这个具体驱动/ES2 代码库组
  合下该 bug 并不会真正复现（damage.lpc 的裸 set/query 实测确实写入
  了角色真正的 dbase）。留待未来某次针对 hy2002/hy2000 的后续 pass
  用同样方法直接验证，而非直接照搬结论。
- 夜晚"天色太黑了，看不清明显的出路"会让裸方向词（north/south 等）
  失效、只能用 `go <方向>`——这是有意的昼夜可见度设计（游戏内容，不
  是 bug），已用 `go` 系列指令正常绕过。


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

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 57 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（2026-08-13，round two，新驱动重测）

Re-tested against the freshly-rebuilt `build-debug/src/driver`（post
全库 `quest_times`/`win_times` `%`-operator 修复 + Warning/warning
驱动文本回退）。管理员账号（`fluffos`/`Mud@2026Pass1`，通过并列
`wiz_status/fluffos` 授权行解决 `hxsd` 被真实旧账号占用的问题）和
`log_file()`/`assure_file()` 相关的 §1.5 处理此前已经做过，本轮复用
并只做真实登录 + `update` 复测，未发现回归。本轮只发现一处新 bug：

### 发现并修复的 PROGRAMMING bug

1. **`log_error()`（`adm/obj/master.lpc`）完全没有严重度检查（AGENTS.md
   §7.34-class，与本轮 `wdxtym`/`ffxymud`/`fy2mg`/`fys`/`hc`/`hy`/
   `hy2000` 同一原始形状）**：`if (this_player(1))
   efun::write(...)`——不区分巫师/玩家，也不区分警告/错误。修复：
   加上 `strsrch(message, "arning:") == -1` 判断。

### Proactive checks（无需改动）

- `log_file()`（`adm/simul_efun/file.lpc`）此前没有 `assure_file()`
  保护，`nosave/CRASHES`/`nosave/addobj`/`nosave/tenrich` 等管理指
  令路径会在首次使用时未捕获抛出（AGENTS.md §7.11-class）；注册/
  登录本身只写 `log_file("USAGE", ...)`（无子目录），不受影响。本
  轮补上 `assure_file(LOG_DIR + file);`（含前向声明）。
- `win_times` 修复确认存在且正确：`d/city2/npc/refereew.lpc:177`。
- 未发现 `message()` simul_efun 包装函数——不适用
  message()-missing-varargs 这一类 bug。
- 管理员账号真正可用（不是仅凭旧记录假设）：登录时有 GB/Big5 选码
  提示（选 `g`），用已提交的 `fluffos`/`Mud@2026Pass1` 登录，
  `score` 确认"目前权限：(admin)"，
  `update /adm/simul_efun/file`（就是本轮改过的文件）确认可正常
  重新编译。`adm/log/debug.log`（含 `debuglog.bak/` 备份）时间戳全
  程未变化（`Jul 30`，早于本次会话），确认无新增未捕获运行期错
  误。登录本身产生的存档时间戳类微小 diff（`data/user/f/
  fluffos.o` 的 `last_on` 字段）已用 `git checkout` 撤销，不提交。
  驱动最终按精确 PID kill，`ps -p` 确认已退出。

## AGENTS.md §7.100 修复（2026-08-19，批次三）

`ROOM` 基类冗余 `replace_program(ROOM);` 自崩溃地雷（详见 AGENTS.md
§7.100）：4436 处命中。除标准脚本删除的 4431 处外，另有 5 处不规
则格式手动修复：`adm/roommaker.lpc` 两个代码生成模板里的三处字符
串拼接、`clone/misc/roommaker.lpc` 的一处，以及 `d/happy/workroom.lpc`
里一行与空 `//` 注释共享同一行的 `replace_program(ROOM);  //`（严
格脚本按设计不匹配这种形状，手动二进制安全删除）。

`git diff --stat`：4433 files changed, 4 insertions(+), 4436 deletions(-)，
与预期精确吻合。

验证：`build-debug` 驱动真实冷启动，端口 40116 正常监听。既有管理
员账号 `fluffos`/`Mud@2026Pass1` 通过 `oldplayer` 路径登录，落地
〖客店〗，多房间走访无误，`quit` 自动存档、干净退出，全程无新增
"cannot replace"/"cannot bind" 日志行。

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

新角度：扬州醉仙楼购物 + 丐帮左全拜师。2026-08-13 第二轮只测了
`log_error`/`log_file`，没有买东西、也没有拜师。这是海洋II/ES2 金庸
血统，端口 40116。第一输入是 GB/BIG5 选单，发 `g`，再英文 id。密码是
`Mud@2026Pass1`，不是 `Mud@2026`。登录对象没有 `wizpwd`，不会多问一
层巫师口令。同一 IP 退出后 30 秒内不能再 login（`last_on` 冷却），本
轮用杀驱动冷启动做持久验证，没有踩到这条。

### 实测过程

管理员 `fluffos` / `Mud@2026Pass1`（权限 `(admin)`）。`clone
/clone/money/gold` 可用。

`goto /d/city/zuixianlou`（醉仙楼，店小二 `d/city/npc/xiaoer2.lpc`，
`F_DEALER`）。`list` 烤鸡腿一两白银又十二文铜板 / 包子七十文铜板。
`buy jitui` 成功（「你从店小二那里买下了一根烤鸡腿」），顺带涨了
「讨价还价」。当场 `i` 是九十八两白银 + 八十八文铜钱 + 烤鸡腿。本档
`feature/dealer.lpc` 没有丐帮拒买门，但买完再拜仍更稳妥。

`goto /d/gaibang/inhole`，左全源码是 `kungfu/class/gaibang/zuo-qu.lpc`
（文件名少一个 n），`apprentice zuo` 一次成功：恭喜成为丐帮第二十代
弟子。`score` 称谓「丐帮第二十代弟子」、师傅左全。`cmds/usr/save.lpc`
真正写盘。save 后杀驱动冷启动再登录，称谓/师傅/银子铜钱都在。烤鸡腿
未进 autoload。左全只收男性。

### 发现并修复的 PROGRAMMING bug

1. **华山收徒计数拼写**（与 `jhfy2`/`wmkj`/`nitan_ceshi` 同形，静态
   对照修，本轮拜师走的是左全不是华山）：
   `kungfu/class/huashan/{yue-buqun,yue-wife,feng-buping}.lpc` 以及
   `quest/menpaijob/huashan/yue-buqun.lpc` 的 `recruit_apprentice()`
   写 `add("apprentice_availavble", -1)`，计数键名拼错，永远减不到
   `set("apprentice_available", 3)` 那个字段。四处都改成
   `apprentice_available`。

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

## 深度功能测试（§10.7，2026-10-06）— 编译警告整理

`scripts/lpc_warnings.py hy2002 --fix`：无用局部变量 2056 个、`varargs` 35 处、转义 48 处、`nosave` 函数 50 个改 `protected`；`scripts/lpc_fix_no_effect.py` 删去 `return "...";` 之后遗留的 `"\n";` 等 12 处。手工：`quest/shenshu/npc/man.lpc` 的 `int kill_ob()` 覆盖 `/feature/attack.lpc` 的 `void kill_ob()`，改 `void`（没有调用者读返回值）；`d/xingxiu/shanjiao.lpc`、`nanjiang3.lpc` 里空的 `if (current_water == 0) {}` 删去。共改动 977 个 `.lpc`，HEAD 与工作树分别加载（新进程）：949 -> 949 通过，无回退；`scripts/lpc_audit_removed_locals.py HEAD` 的 20 条候选都是声明被重建。启动时警告 387 -> 0。

## 深度功能测试（§10.7，2026-10-07）— 空的 `if (current_water == 0) {}`

1 个房间的 `valid_leave()` 里有一行什么也不做的 `if (current_water == 0) {}`（编译警告 `Expression has no side effects`），删去，行为不变：`d/xingxiu/nanjiang2.lpc`。

## 深度功能测试（§10.7，2026-10-07）— 郭靖任务的名单被覆盖

`quest/guojob/guo.lpc` 先后 `#include "zzzjob.lpc"` 和 `"teamjob.lpc"`，两个文件都声明全局 `mixed names`、内容不同（`Redeclaration of global variable 'names'`），后包含的 teamjob 名单覆盖了 zzzjob 的，"保护"任务的目标其实从 teamjob 的名单里抽。teamjob 的表改名 `team_names`（KB 04 §6.10）。`guo.lpc` 在 HEAD 与工作树分别加载（新进程）通过。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 14 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 4 个，只在 #if 分支用的声明移进分支 0 个文件；改动 10 个文件，HEAD 与工作树各载入一次无回退（10 objects; HEAD PASS 9, tree PASS 9; regress 0; newly loading 0），这些文件的警告 18 -> 0。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查（批 3）

- `kungfu/skill/liangyi-jian.bak.lpc`：`int i; level;` 去掉无用的 `level;`。
- 改动的对象 HEAD 与工作区都能载入，无回退。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。7 个文件 7 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）；`x op= 浮点` 先把浮点转成整数再运算（系数小于 1 时 x 直接变 0），改为 `x = to_int(x op ...)`：`/kungfu/skill/fengyun-shou/foguang.lpc`（`damage *=`）、`/kungfu/skill/taiji-quan/zhenup.lpc`（`damage *=`）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。
- 2026-10-14：同一次重扫的其余 15 条：8 个文件在基类已有的情况下又 `inherit F_CLEAN_UP`，删去；`quest/shenshu/npc/testman.lpc` 的 `kill_ob` 改 `void`；宏重定义前加 `#undef`。改动的对象新进程各载入一次，无回退。

- 2026-10-14：`kungfu/skill/liu-unarmed.lpc` 的 `query_action()` 里取等级与 `for` 循环两行被注释掉，剩下 `if (level > action[i - 1]["lvl"])`，i 为 0，每次出招都报 `Array index must be positive or zero`；恢复这两行（与其他武功相同的写法）。逐个武功调用 query_action/valid_learn/practice_skill 的运行期探针发现。

## 负数伤害当作消耗（2026-10-15，KB 06 §7.241）

`receive_damage("neili", -52)`、`receive_damage("qi", -12)` 之类把 `add()` 的负数写进了 `receive_damage()`：本库 `feature/damage.lpc` 对负数伤害报错（或归零），练功/运功时报 `F_DAMAGE: 伤害值为负值` 或消耗失效。已改为正数伤害，内力/精力类改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py`）：`/kungfu/skill/shaolin-tantui`。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。2 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。


## 东方故事/西游记体系的技能文件（2026-10-15，KB 06 §7.241 第三类）

这些 `kungfu/skill` 文件来自 gin/kee/sen/force 体系，本库人物只有 jing/qi/neili：`receive_damage("kee", 30)` 报 `伤害种类错误`，`query("force")` 永远为 0，技能学不了也练不了。按 kee→qi、gin/sen→jing、force→neili、max_force→max_neili、force_factor→jiali 改了属性名（`scripts/lpc_port_es_props.py`），共 12 个文件。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

另有 9 个文件（绝招、状态、物品、NPC 等，不限于 kungfu/skill）来自 gin/kee/sen/force 体系，同样按 kee→qi、gin/sen→jing、force→neili 改名（`scripts/lpc_port_es_props.py --any-file`）。


## family 映射（补）（2026-10-15）

`mapping fam = (mapping)me->query("family");`（带类型转换的写法）同样直接取下标，2 处补上 `if (!mapp(fam)) fam = ([ ]);`。

## `message_vision(msg, environment(me), me)`（2026-10-15，KB 06 §7.242）

把房间当成了动作者：`message_vision()` 取房间的 `name()` 得 0，`replace_string(msg, "$N", 0)` 报错。在状态（中毒）里，这个错误发生在 `apply_condition(name, duration - 1)` 之前，状态永不结束，心跳里后面的恢复也每次被跳过。改为 `message_vision(msg, me)`：`/kungfu/condition/sanpoison`。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。10 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。

## 妙手回春的银针检查（2026-10-15）

`miaoshouhuichun` 的 `valid_learn()` 用了未赋值的 `object ob`（`ob->query_temp("weapon")` 报错），还把兵器对象和字符串 "银针" 比较。改为 `ob = me->query_temp("weapon")`，再用 `id("yin zhen")`/`id("yinzhen")` 判断是否银针。

## 叠掌与飞雪（2026-10-15，绝招探测）

`kungfu/skill/kongming-quan/diezhang.lpc` 函数结束后残留一段重复的尾巴（`on(GRN ... return 0; }`），文件不能编译，已删除。`liangyi-jian/feixue.lpc` 末尾的 `else destruct(obj);` 在前一分支已销毁兵器时对 0 调用，改为 `else if (objectp(obj))`。

## 空手使用兵器绝招（2026-10-15，KB 06 §7.246）

`perform` 指令允许直接点名招式（如 `perform stick.ban`），这些绝招读了 `me->query_temp("weapon")` 却从不检查，空手时 `weapon->name()` 报错（有的已先扣了内力）。在赋值后补 `if (!objectp(weapon)) return notify_fail("你必须手持兵器才能使用这一招。\n");`（`scripts/lpc_fix_perform_weapon.py`）：`dagou-bang/ban`、`murong-jianfa/kuangjian`、`tianyu-qijian/kuangwu`、`wuyue-blade/jiao`。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`buddhsim`→`buddhism`（`qianye-shou`）；`douzhuan-xignyi`→`douzhuan-xingyi`（`/d/mr/obj/shu1`）；`jinwu-dao`→`jinwu-daofa`（`jinwu-daofa`）；`quanzhen-jianfa`→`quanzhen-jian`（`quanzhen-jian/ding`）；`yinyun_ziqi`→`yinyun-ziqi`（`yinyun-ziqi/cure`）。

## 技能名拼错：技能文件里拼错自己的名字（2026-10-15，KB 06 §7.249）

技能自己的文件（或它的绝招目录）里，`query_skill()` 读的是差一个字母的自己的名字，永远得 0：“基本功夫要高过本技能”之类的限制从不生效，按等级取招、计算伤害的那一项一直是 0。改为本技能的名字（`scripts/lpc_fix_skill_typo.py` 的 self 判据）：`chanyun-tui`→`chuanyun-tui`（`chuanyun-tui/shuangjue`）。

## family 映射内联取下标（2026-10-15，KB 05 §7.30）

`ob->query("family")["master_name"]`、`me->query("family")["family_name"]`（泥潭式为 `query("family", ob)[...]`）直接对门派映射取下标：没有门派的人（新玩家、叛师者、大多数 NPC）在 NPC 的打招呼和问话、绝招的门派判断、房间的 `valid_leave` 里报 `Value being indexed is zero`，而不是得到拒绝。4 处（3 个文件）改为 dbase 路径查询 `query("family/master_name")`：有门派时值相同，没有时得 0；原有的判断照常生效（`scripts/lpc_fix_family_index.py`）。给映射赋值的写法未动。


## 用兵器的绝招空手施展时报错（内联写法）（2026-10-15，KB 06 §7.246）

绝招不存兵器变量，直接写 `(me->query_temp("weapon"))->query("name")`（或在拒绝判断里写 `(weapon = me->query_temp("weapon"))->query("skill_type")`），之前又没检查兵器：空手 `perform` 时报 `Bad argument 1 to EFUN call_other()`，内力等往往已经扣掉。在第一次用到它的那条语句前补上“你必须手持兵器才能使用这一招”的拒绝（`scripts/lpc_fix_perform_weapon.py`）：`yunv-jian/suxin`。


## 存档读不出来：字符串里的换行、空行（2026-10-15，KB 03 §4.4）

`clone/gift/npc/bingqipu.o`、`data/board/yipin_b.o`：字符串里有原样的换行（`save_object()` 存成 `\r`，`restore_object()` 逐行读，原样的换行让字符串收不了尾），或有空行（`Illegal file format`），读档的对象（留言板、NPC、玩家）从空白开始。换行改写成 `\r`、删去空行（`scripts/lpc_save_encoding.py --from-raw`），驱动核对全部能读回（`scripts/lpc_save_restore_check.py`）。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

8 个文件、9 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/d/shaolin/obj/heibian`、`/clone/obj/demon_staff`、`/d/city/obj/tudao`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 0 个，改后 7 个（7 个原来载入不了），没有退步；其余 1 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## `kungfu/skill/qingyi-jian` 第一式的 `skill_name` 丢了收尾引号（2026-10-18，KB 03 §4.6）

`"skill_name" : "大悲式,` 的收尾引号没了（转码时跟半个汉字一起丢了），字符串连到下一行，`damage_type` 成了代码：`Illegal character 0xe5`，整个武功载入不了。补回 `",`（同系的 bixiecanyang、syxjl 等库里有完好的同名文件）。载入：通过。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 7 个对象设了本库没有文件的武功（3 个名字，最多的是 `shenlong-quanfa`、`xingxiu-duzhang`、`meiren-sanshi`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：7 个里 7 个通过。（`scripts/lpc_guard_set_skill.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 45 处、42 个文件：`kunlun-shnfa`→`kunlun-shenfa`（16 处）、`shaolin-shnfa`→`shaolin-shenfa`（12 处）、`lingbo-weibu`→`lingboweibu`（3 处）、`yunu-xinfa`→`yunv-xinfa`（3 处）、`tiaji-jian`→`taiji-jian`（2 处）、`yan-fly`→`yanfly`（2 处）、`meimv-quan`→`meinv-quan`（1 处）、`canhhe-zhi`→`canhe-zhi`（1 处）等共 13 个名字。（`scripts/lpc_fix_skill_names.py`）

## set_name 的 id 参数传成字符串（2026-10-19，KB 06 §7.260）

`set_name("海口大碗", "bowl");` 把物品的 id 写成了字符串，本库的 `set_name(string name, string *id)` 要的是数组，驱动在编译时报 `Bad type for argument 2 of set_name ( string * vs string )`，整个物件载入不了；旧驱动不检查参数类型，字符串里照样找得到这个词，物品能用 id 称呼。改成 `({ "bowl" })`，共 2 个文件：`/d/baituo/npc/obj/bowl.lpc`、`/d/baituo/obj/bowl.lpc`。（`scripts/lpc_fix_set_name_id.py`）

## 全局头文件丢了 2 个宏（2026-10-19，KB 04 §6.16）

`/include/globals.h` 里没有定义 `EVENT_D`、`EVENT_DIR`，用到它们的物件（名单里 6 个）编译时报 `Undefined variable`/`Undefined function`，整个物件载入不了（编译器在第一个未定义的名字上停下，后面的错误和警告都看不到）。同系的库在各自的头文件里都有这几行：照其中和本库共有文件最多的那个库，原样补到 `/include/globals.h` 最后一个 `#define` 之后，宏体里出现的路径在本库里都存在。名单里的物件除了这几个宏之外还有别的错误，暂时仍载入不了。（`scripts/lpc_restore_defines.py`）

## 全局变量重复声明（2026-10-19，KB 04 §6.10）

`d/pingan/shenzhen/npc/shenyi.lpc`（以及 `d/hxsd/…`、`d/pingan/pingan/…` 的两份拷贝）的 `int last_time = -100000;` 与 `feature/alias.lpc` 防刷命令用的 `nosave int last_time` 同名，但是两回事（三分钟冷却的时间戳）：改名 `last_cure_time`。改后警告消失，与 HEAD 逐个对比载入，没有退步。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 载入不了的零碎文件（2026-10-19，KB 03 §4.7、KB 04 §6.10）

- `d/hangzhou/npc/tangzi.lpc`：整个文件只是 UTF-16 的空格（`\x00 \x00 …`，作者把这个物件清空了），驱动报 `Illegal embedded NUL byte (0x00) in source`；旧驱动编出一个空程序。改成一个换行，行为和原来一样（空程序），不从 xkx100 抄回同名 NPC。

逐个载入与 HEAD 对比，没有退步。

## 玩家打造兵器模板没有打造者时（2026-10-19，KB 06 §7.275）

`/d/npc/m_weapon/weapon/m_blade.lpc`、`/d/npc/m_weapon/weapon/m_club.lpc`、`/d/npc/m_weapon/weapon/m_hammer.lpc`、`/d/npc/m_weapon/weapon/m_staff.lpc`、`/d/npc/m_weapon/weapon/m_sword.lpc`、`/d/npc/m_weapon/weapon/m_whip.lpc`（共 6 个）的 `create()` 开头 `me = this_player();` 之后无条件读 `me->query("weapon/name")` 等打造数据。房间刷新时没有人在场（`me` 为 0），或者 NPC 在别的 NPC 的命令环境里 `carry_object()` 这个模板（NPC 的 `weapon` 属性是文件名字符串），旧驱动里读出来是 0 或字符串，`switch` 照样落到 default；新驱动报 `Bad argument 1 to EFUN call_other()` / `Bad argument 1 to switch`，NPC 和它所在的房间载入不了（`--walk` 普查里一个玩家走进房间就触发）。在 `//读入数据` 之后加 `if (!me || !mapp(me->query("weapon"))) { setup(); return; }`：没有打造者就留一个没有名字的空模板，玩家打造的流程不变。

## 手工收尾（2026-10-19，KB 04 §6.10）

- `adm/roommaker.lpc`：`special_props` 声明了两遍（同 sjshv150 `data/group/obj/ling.lpc`），删掉前一个。

逐个与 HEAD 对比载入，没有退步。

## 补回丢失的标点（2026-10-19，KB 03 §4.6）

转换时丢掉的分号、逗号、引号或文件末尾的 `}`，共 3 个文件，修前 HEAD 载入失败。别的库里同路径的完好副本只比这里少几个标点，按它补回（括号里是那个库）：`/d/city2/npc/zhengmen.lpc`（jqxz2008）。一行文字在逗号前丢了结尾的引号（下一行是同一个表的下一项），补上：`/kungfu/skill/emperor-unarmed.lpc`、`/kungfu/skill/kunlun-zhang.lpc`。修后与 HEAD 逐个对比载入：这 3 个物件全部载入，没有退步（`scripts/lpc_restore_from_twin.py`、`lpc_fix_eaten_quote.py --comma`、`lpc_fix_eof_braces.py`）。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。改动：`/d/mingjiao/shanmen.lpc`（1 处）。

## `call_out_info()` 的每一项只有 3 个元素（2026-10-20，KB 06 §7.287）

驱动返回的是 `({ 物件, 函数, 延迟 })`，不带 call_out 的参数，旧代码读第 4 项 `info[i][3]`（`callouts` 指令、`calloutd`、`cod` 工具）一读就报 `Array index out of bounds`，指令从第一行起什么也打印不出来。改为 `(sizeof(info[i]) > 3 ? info[i][3] : 0)`（`scripts/lpc_fix_callout_info.py`）。改动：`/cmds/arch/callouts.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 11 处）。改动：`/adm/daemons/combatd.lpc`（1 处）、`/d/city4/obj/mj.lpc`（3 处）、`/d/city4/puke-room.lpc`（4 处）、`/d/hangzhou/npc/meipo.lpc`（1 处）、`/kungfu/class/emei/tobebonze.h`（1 处）、`/kungfu/skill/meinv-quan.lpc`（1 处）。

## `callouts`：`sizeof(info[i]) == 4` 把每一行都挡掉了（2026-10-20，KB 06 §7.287）

驱动的 `call_out_info()` 每项只有 3 个元素，输出行前的守卫 `if (sizeof(info[i]) == 4)` 永远不成立，指令只打印表头。改为 `>= 3`。改动：`/cmds/arch/callouts.lpc`（1 处）。

## `mcheck`：`query_ip_rport()` 驱动里没有（2026-10-20，KB 06 §7.291）

指令要显示连线的远端端口，MudOS 时代的 `query_ip_rport()` 在 FluffOS 里不存在（`query_ip_port()` 给的是本地端口），指令编译不过。文件里加了一个返回 `"?"` 的占位函数（dtsl 的同名指令早就这么做）。改动：`/cmds/imm/mcheck.lpc`。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/obj/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## sefun `cat()`：缺文件时 `write(0)` 报错（2026-10-20，KB 06 §7.297）

`void cat(string file) { write(read_file(file)); }`：文件不存在（压缩包没带的欢迎/公告文件，或只有运行中的 mud 才会写的日志）时 `read_file()` 回 0，`write(0)` 在本驱动里报 `Bad argument 1 to receive()`，调用者（登录对话、`cat` 指令）被中断；老驱动什么也不打印。改成 `write(read_file(file) || "");`（`scripts/lpc_fix_cat_unchecked.py`）。改动：`/adm/simul_efun/file.lpc`。

## `setbak` 指令编译不过：文件末尾粘了半截 `help()`（2026-10-20，KB 06 §7.264）

`cmds/usr/setbak.lpc` 在完整的 `help()` 之后又重复了帮助文字的结尾（`取消变数设定请用 unset 指令。……TEXT ); return 1; }`，没有函数头）：`Illegal character 0xe5`。在第一个完整函数结尾处截断（去掉 8 行）。加载检查：HEAD FAIL → tree PASS。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库现有的 NPC 文件里没有字面写成空 `chat_msg` 的（扫描只认 `set("chat_msg", ({ }))`）；守卫挡的是运行时才为空的列表和以后新增的 NPC。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/clone/guard/baoer.lpc`、`/clone/guard/long2.lpc`、`/d/migong/obj/npc1.lpc`、`/inherit/char/npc.lpc`（共 4 个文件）。

## `home`：模板 `/clone/misc/wizroom.lpc` 档案里没有（2026-10-21，KB 06 §7.310）

管理员扫描里 `home` 报 `Bad argument 1 to EFUN replace_string() Got: int(0)`（`cmds/imm/home.lpc` 第 30 行）：巫师还没有工作室时，`home` 从 `/clone/misc/wizroom.lpc` 读模板，把 `NAME` 换成名字写进 `/u/<id>/workroom.lpc`；本库没有这个模板，`read_file()` 答 0，第一次敲 `home` 的巫师就是系统错误。`wizroom.lpc` 是这一系的公用文件（hy3、chidi、wmkj、yxcs 等 28 个库都带，内容相同，只差换行符：“没有建造工作室的巫师的临时住处”，出口 `north` 通 `/d/wizard/wizard_room`，本库有这个房间），从 hy3 原样复制过来，加载检查通过。

## `lsusers`：用档案里没有的 `/clone/misc/player`（2026-10-21，KB 06 §7.299）

管理员扫描里 `lsusers` 报 `Bad argument 1 to EFUN call_other() Got: int(0)`（`cmds/adm/lsusers.lpc`）：指令 `new("/clone/misc/player")` 一个对象，用它的 `new_object(name)` 逐个还原玩家存档；本库没有 `/clone/misc/player.lpc`（同系的 hy3、jhfy、xyzx 等 27 个库带着它，`new_object()` 只定义在那里），`new()` 答 0，后面就是对 0 的调用。`new()` 之后加 `if (!ob) return notify_fail(...)`，指令回一句话而不是系统错误；文件本身补不上，那个旧的玩家对象已经不是本库的用户对象了。

## `blockade` / `recover`：`data/keep` 不存在，解封之后世界仍然锁着（2026-10-21，KB 06 §7.340）

管理员扫描里 `blockade` 报 `Error copying file from /data/user/f/fluffos.o to /data/keep/fluffos, Error: No such file or directory`，随后的 `recover` 在第一个 `cp()` 上死于 `*/data/keep/fluffos: lstat failed`，来不及执行最后的 `LOGIN_D->set_madlock(0)`：封锁解不开。`data/keep/` 是运行时目录，git 克隆里没有空目录。`blockade` 在第一次写之前 `if (file_size("/data/keep") != -2) mkdir("/data/keep");`（`mkdir()` 失败答 0，不抛错），`recover` 对没有保存档的玩家 `if (file_size(src) < 0) continue;`，其余照常恢复、照常解锁（`scripts/lpc_fix_keep_dir.py`，hy5 上实测：没有保存档时 `recover` 答“时空解封完毕”，`blockade` 建出 `data/keep` 并保存，`recover` 取回并删除）。改动（2 个文件）：`/cmds/arch/blockade.lpc`、`/cmds/arch/recover.lpc`。

## `selfthinking`、`qlian`：缺乏实战经验的提示读了不存在的老师（2026-10-21，KB 06 §7.348）

自创武功的自习指令在“技能等级³/10 大于实战经验”时打印 `printf("也许是缺乏实战经验，你对%s的回答总是无法领会。\n", ob->name())`。这一句是从 `learn` 抄来的，`ob` 是老师；自习没有老师，`object ob;` 从没赋值，`ob->name()` 抛 `call_other() ... Got: int(0)`。改成 `你对「%s」的疑问总是无法领会` 加 `to_chinese(skillname)`，去掉没用的 `object ob;`。改动：`/cmds/skill/selfthinking.lpc`。

## 瓦耳拉齐 `ask_back`：送回去的是没赋值的 `ob`（2026-10-21，KB 06 §7.348）

带着地图问“回去”时 `ob->move(__DIR__ "entrance")`：`ob` 没赋值，路径也错成了 `/d/gaochang/npc/entrance`。xkx100 的原文是 `me->move("/d/gaochang/entrance");`，照改，去掉 `object ob;`。改动：`/d/gaochang/npc/wuaer.lpc`。

## 黄蓉 `ask_husband`：找优胜者的那段被注释掉，`user` 没赋值（2026-10-21，KB 06 §7.348）

`ask rong about 丈夫` 对谁都抛 `Bad argument 1 to call_other() ... Got: int(0)`：优胜者（`nvxu->query("winner")`）不是提问的人时，原来先 `find_player(id)`，找不到就 `new(USER_OB, id)->restore()` 把离线的人读出来；这段被注释掉，下面的 `user->query("death_count")` 照用。默认没有优胜者（`winner` 为 0）。改成只找在线的优胜者（`user = stringp(id) ? find_player(id) : 0`），没有优胜者或优胜者离线时直接回答“我的丈夫就是”加女婿 NPC 的名字。hy5 上实测：HEAD 抛错，改后 “黄蓉说道：我的丈夫就是精确！”。hy2002 保留了读离线玩家的原段，只补上 `winner` 为 0 时的一支（`find_player(0)` 抛错）。改动：`/kungfu/class/taohua/rong.lpc`。

## 妙手回春 `valid_learn()`：先读 `ob->query_temp("weapon")` 再给 `ob` 赋值（2026-10-21，KB 06 §7.348）

学这门暗器技能时 `valid_learn()` 第一个武器检查读的是没赋值的 `ob`，`xue` / `learn` 在这里抛错；后面 `ob = me->query_temp("weapon")` 的检查才是对的。有两种写法：`if (!ob->query_temp("weapon"))` 改成 `me->query_temp("weapon")`；`if ((string)ob->query_temp("weapon") != "银针")`（拿一个对象和字符串比较，永远不等，补上 `ob` 之后这门技能也学不成）改成后一种写法里的 `!objectp(ob = me->query_temp("weapon")) || !(ob->id("yin zhen") || ob->id("yinzhen"))`。改动：`/d/hxsd/pingan/shenzhen/skills/miaoshouhuichun.lpc`、`/d/pingan/pingan/shenzhen/skills/miaoshouhuichun.lpc`、`/d/pingan/shenzhen/skills/miaoshouhuichun.lpc`。

## 守卫 `clone/guard/baoer.lpc`：`do_send()` 里丢了收尾引号，整个文件从来没编译过（2026-10-21，KB 03 §4.6 第五轮、KB 06 §7.349）

`new_id=ob->query("id")+"'s bao er;` 少了字符串结尾的引号：字符串一直读到下一行的引号，后面的汉字全成了 `Illegal character 0xe5`（几千行错误，批量验证器里的表现是“没有答案”）。补成 `"'s bao er";`。文件第一次能编译后带出 11 个 `Unused local variable` 警告（`host_id`、`i`、`obj`、`shape`、`emotes`、`inv`、`msg`、`same_place`、`couple_id`、`couple_name`、`couple`），按 KB 04 §6.10 删掉。文件里的 `do_heji` / `do_lian` / `do_order` / `do_title` / `do_ticks` / `do_sha` / `do_shape` / `do_hulian` / `do_quit` 等处理函数都有定义（静态扫描因为引号没闭合把它们当成字符串里的文字，补引号后运行时 `function_exists()` 全部证实存在），所以这个文件的 `add_action` 不属于死登记，没有动。改动：`/clone/guard/baoer.lpc`。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 17 条注册（7 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/d/city/leitai.lpc`（`do_quit`）、`/d/city4/qishi.lpc`（`do_pass`、`do_resign`）、`/d/hxsd/pingan/npc/sighmoon.lpc`（`do_vendor_list`）、`/d/mr/shuichi.lpc`（`do_strike`）、`/d/pingan/npc/sighmoon.lpc`（`do_vendor_list`）、`/d/pingan/pingan/npc/sighmoon.lpc`（`do_vendor_list`）、`/inherit/misc/fboard.lpc`（`do_list`）。最多的函数名：`do_quit` 9 处、`do_vendor_list` 3 处、`do_strike` 2 处、`do_pass` 1 处、`do_resign` 1 处。

## 对象路径里的 `..`：`new(__DIR__ "../obj/x")` 报 `Read access denied`（2026-10-22，KB 06 §7.351）

`__DIR__` 是当前文件所在目录（带结尾斜杠），`__DIR__ "../obj/x"` 就是 `/d/zhiye/npc/../obj/x`；驱动的 `legal_path()` 不接受带 `..` 的路径，`new()` / `load_object()` 直接抛 `*Read access denied.`（实测，`find_object()` 对它答 0）。走库自己的 `carry_object()` / 房间 `objects` 表的路径，库的基类会先规范化，能用；直接把路径交给 `new()` / `clone_object()` / `load_object()` / `move()` 的不行，调用到那一步才报错。改成规范化后的绝对路径（`scripts/lpc_fix_dotdot_dir.py --direct`）：`/d/wudang/npc/xiaocui.lpc`（`__DIR__ "../obj/nuerxiang"` → `"/d/wudang/obj/nuerxiang"`）。

## 调用了、但这个库自己的守护进程里没有的函数（2026-10-22，KB 06 §7.354）

`MACRO->函数()` 调用的函数在这个库的守护进程里不存在：`call_other()` 对不存在的函数不报错、只返回 0，所以这些功能（时间显示、昼夜事件、名字检查、价格文字……）一直没起作用。同一血统另一个库的同名守护进程里有这些函数，原文照抄到本库守护进程末尾（`scripts/lpc_port_function.py`；调用处传的参数个数、函数体用到的函数 / 全局变量 / 宏 / 字符串键都在本库里有，已核对；守护进程在 HEAD 和工作区都能加载，每个函数用固定参数各调用一次：HEAD 返回 0，现在返回正常的值）：`/adm/daemons/chinesed.lpc` ← aoxiangtianji：`chinese_month()`（4 处调用）、`chinese_period()`（1 处调用）。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 还剩 4 个函数没有补（item_desc 3, other 1）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/cmds/imm/help2.lpc`:`confirm_l_choice`、`/d/city/ximenroad.lpc`:`look_gaoshi`、`/d/gaochang/zoulang2.lpc`:`look_writing`、`/d/gaochang/zoulang_1.lpc`:`look_writing`。

## 读不到的留言板：`"/clone/board/x"->foo();` 在 `create()` 里报错（2026-10-22，KB 06 §7.357）

xkx 系的房间在 `setup()` 之后写 `"/clone/board/gaibang_r"->foo();` 来加载留言板（`foo()` 本来就没有定义，只为了触发加载）。这个库没有这个文件，`call_other()` 报 `*call_other() couldn't find object '/clone/board/gaibang_r'`，对象留在内存里、`load_object()` 却抛错：玩家第一次走进房间就看到错误，写在 `create()` 中间的还会切掉后半段。`scripts/lpc_fix_missing_foo.py` 把 1 条单独成行的语句（`/clone/board/jail_b`；`/d/city2/jail.lpc`）注释掉并写明原因（别的房间里同样的语句本来就是作者自己注释掉的）。证明和 45 个库的整体加载检查见 KB 06 §7.357。

## `log/` 下的日志子目录没有人建：写日志的 `write_file()` / `log_file()` 报错（2026-10-22，KB 06 §7.358）

这个库的代码往 `log/` 的 1 个子目录写日志：`log/html`（`clone/npc/robot-judge.lpc`）。压缩包、`git clone` 和站点包里都没有这些目录（本地启动没有写过它们，`gen_keep_dirs.py` 没记），`write_file()` 对不存在的目录抛 `*Wrong permissions for opening file /log/dlog/money for append. "No such file or directory"`，调用它的函数在写日志那一行中断，后面的奖励、标志、步骤都没有执行。本库的 `log_file()` 会自己建目录（实测，或读源码：nitan 系的 `assure_file()`），所以这里只记了直接用 `write_file()` / `save_object()` 写的目录。把 `log/html` 记进 `scripts/wasm_keep_dirs.txt`（`scripts/lpc_keep_log_dirs.py`；站点和 pristine 树按它建空目录）。证明（`scripts/lpcc_eval.py`，在 `/adm/daemons` 这类目录下的求值对象里写 `/log/zzdirprobe/...`，新进程）见 KB 06 §7.358 的实测表。

## `(: 函数名 :)` 指针指向本库没有的函数：只含这个指针的行加了注释（2026-10-22，KB 06 §7.355 补充）

`inquiry` / `item_desc` / `chat_msg*` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：用到时（`ask`、`look`、NPC 闲聊）驱动抛 `*Undefined lfun pointer called: 函数名`，这一拍心跳的后半段被跳过。这些函数没有可以补回的来源（别的库同一路径的文件里没有，或者它还要用本库没有的东西），所以 3 个文件里 3 行只含这个指针的行（`"gaoshi": (: look_gaoshi :),` `"writing": (: look_writing :),`）加了注释，原文保留并写明原因，这一项当作没有这个话题 / 物品 / 闲聊条目（`scripts/lpc_fix_dangling_lfun.py`；`#include` 的文件在库里缺失的对象、指针不在整行上的写法没动）。 前提（`function_exists()`）和加载检查（HEAD 与工作区对比，本库改动的 `.lpc` 文件）的结果见 KB 06 §7.355：没有一个回归。
