
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
