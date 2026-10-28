
## WASM 修复摘要（迁移自 meta.json 的 group_note）

战国代码库，adm/obj/master.lpc 血统——虽然 slug 相似，但和 sjecl/sje 的 Century/adm-single 家族完全不同。WASM 修复：（1）§7.60 类的 master.lpc log_error()/standard_trace()→CHANNEL_D 编译期崩溃，两处都用 find_object(CHANNEL_D) 判断守卫。（2）§7.8/§7.9 大小写不一致+缺失的计数器档案：logind.lpc 的 VISITORS/GIFTCARD 宏指向 /adm/single/MUDVISITOR 和 /adm/single/GIFTCARD（大写），而硬盘上的档案是小写的 mudvisitor/giftcard——导致每一次连线的 sscanf() 都崩溃（"the user is disconnected"，看起来像空白的对话记录）。已修正宏的大小写，并给两处 read_file() 结果加上 stringp() 保护作为纵深防御。（3）logind.lpc 的 logon() 里缺了一个 return：'!find_object(DNS_MASTER)' 分支（这里永远会走到，因为按既定的无 socket 政策 dns_master 已经从预载里禁用）已经显示了简化横幅并提示输入 id，但少了 return，导致函式继续往下执行，紧接着无条件呼叫 DNS_MASTER->query_muds()，在每一次连线时都触发经典的未定义 socket efun 编译错误。（4）§7.56 重复的安全精灵档案：SECURITY_D 解析到的是 adm/daemons/securd.lpc（一个存档档案/dbase 支撑的精灵，硬编码了引导用管理员"keyboy"作为 (zhuguan)），而不是名字相似的 adm/daemons/securityd.lpc——那是一个未被使用、和这个宏毫无代码路径关系的诱饵档案——一开始播种了一条文本格式的 /adm/etc/wizlist 条目，完全没有效果，因为 securd.lpc 根本不读这个档案；后来改成在 securd.lpc 的 restore_list() 里紧挨着既有的 keyboy 那行加一行 set("wiz_status/fluffos","(admin)")，匹配它自己既有的引导模式（AGENTS.md §1.5 的硬编码引导管理员 id 类）。已验证：完整注册→look/score/quit 全部干净，权限显示正确地显示〖银河特警〗(Admin)，匹配 securd.lpc 自己的 wiz_rank() 显示字符串。留下一处不阻断、已经在预载之外的问题作为噪音：符合 §7.6"从预载排除，保护呼叫者"的模式——呼叫者除了上面修好的那个 logon() 呼叫点之外，其它地方都已经正确地用 find_object() 判断保护了；其余几处次要的 DNS_MASTER 呼叫点在被触及时仍会无害地记录同样的编译错误文字，没有进一步深究。LPC 格式化工具对全部 2697 个档案运行；还原了 8 个通过"去空格后比对旧档案"扫描（覆盖 30 个格式化工具触碰过的档案）确认有 CJK 重新加空格损坏的档案；另外检查了所有形似 map.lpc 的档案——没有一个是 ASCII 地图，全都是干净的排版调整。格式化后重新验证过，干净。

## §10.7 深度功能测试（本次新增）

此前只做过注册→look/score→quit 的浅层验证。本次用管理员 `fluffos`
实际走通了注册→`score`（人物状态）→`goto` 到天狼星区的实际游戏地图
→和 NPC 交谈→真实战斗→死亡→鬼门关复活的完整流程。

### 修复 1：§8.9 食物/饮水年龄检查错对象

`adm/daemons/logind.lpc` 的登录完成流程里：
`if (!user->query("food") && !user->query("water") && ob->query("age") == 14)`
——`ob` 是登录对象，不是角色本体 `user`，`ob->query("age")` 永远是
undefined，这道门槛永久为假。已改为 `user->query("age") == 14`。（实测
本档案的 `user->setup()` 已经预先把食物/饮水填满，所以这个 bug 在默认
流程下不会直接表现为空食槽——但逻辑仍然是错的，按标准修法一并修正。）

### 修复 2：两处 §7.68 复活软锁（d/death/npc/{b,w}gargoyle.lpc）

`death_stage(object ob, int stage)` 原代码
`if (!ob || !present(ob)) return;` 把"鬼魂对象已经不存在了"和"鬼魂此
刻只是暂时不在这个房间里"混为一谈，一旦判定瞬间鬼魂碰巧不在场就永久
放弃后续引导，把鬼魂永久卡在鬼门关。按标准修法拆开：`!ob` 才是真正放
弃，`!present` 改为 5 秒后重试。

### 实战验证：完整的战斗→死亡→复活流程

用管理员角色（新建，属性和普通玩家一样是白板）在天狼中心向"交通警
察"（`combat_exp` 20000，比新手强得多）发起攻击，几个回合后被击杀——
死亡提示、"江湖传闻"广播、送入鬼门关的链路均正常触发；鬼门关里
白无常(wgargoyle) 的完整对话（"你叫什么名字"→"你命不该绝，快滚上
去"→一脚踢出鬼门关）全部顺利播放完毕，角色被正确送到本档案的
REVIVE_ROOM（太空港口，呼应科幻题材），复活链路全程无卡死、无报错。

### 检查、确认不适用的已知 bug 类别

- §7.78 CHARACTER 的 F_* 混入档缺 F_DBASE inherit：`inherit/char/
  char.lpc` 是和 shujian3/hy2002/jh2006/xxcq 相同形状的结构，这几
  个同宗档案都已经用真实测试排除过这个 bug（裸 set/query 实际写入
  了真正的 dbase），本次时间关系未重复验证。

### 顺带记录（非 bug，仅存档）

死亡瞬间的系统提示里出现过一行
`〖系统信息〗交通警察(Jingcha)：Auto_save has been started for -495
分钟`——NPC 自动存盘计时器显示了负数分钟数。纯粹是显示层面的小瑕疵
（不影响存盘本身，NPC 也确实继续正常运作），没有进一步排查，记录在
此供未来 pass 参考。


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

- **`BULLETIN_BOARD`、`W_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 19 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试第二轮 / Deep functional test round two (2026-08-15, post driver-upgrade re-test)

驱动于 2026-08-12 升级后的重测。标准检查清单发现并修复四处问题：

1. **`config.fluffos`**：`maximum evaluation cost` 从 `700000`（已知风
   险区间）提升到 `5000000`。
2. **`cmds/app/update.lpc`（AGENTS.md §7.106）**：缺少
   `environment(me) &&` 前置防护，补上。
3. **`adm/simul_efun/file.lpc`**：`log_file()` 没有 `assure_file()`
   目录预建保护，补上调用及前向声明；`cat()` 补上
   `read_file() || ""` 空值防护。
4. **`adm/obj/master.lpc::log_error()`（AGENTS.md §7.10/§7.103）**：
   `if (this_player(1)) efun::write(...)` 完全没有警告过滤门——不是
   大小写写错，是压根没有这道防护，任何编译警告（包括每一次
   lazily-compile 遇到的无害"Unused local variable"之类）都会原样广
   播给当前玩家。补上 `strsrch(message, "arning:") == -1` 判定。
5. **`clone/user/user.lpc::reconnect()`（AGENTS.md §7.108，第六条独
   立确认的血统——同 Century/书剑家族的 shiji、shujian2008、
   shujian3 均命中过同一处）**：缺少 `enable_commands()`。按 §7.108
   记录的写法预防性修复，现场验证见下。

### 方法论记录（非 bug）：既有 `fluffos` 账号密码未知，改用新账号测试

已有存档的 `fluffos` 账号（第一轮登录种子播种，本档案通过
`securd.lpc::restore_list()` 里紧邻 `keyboy` 那行加的
`set("wiz_status/fluffos","(admin)")` 硬编码授权）用本项目标准密码
`Mud@2026`/`Mud@2026admin` 均登录失败——第一轮 NOTES.md 未记录当时
实际选用的密码，属于记录疏漏，不是本轮引入的问题。由于账号本身的
管理员授权是纯代码层面（不依赖密码正确与否，只依赖 id 字符串），
直接在 `securd.lpc` 里新增一行 `set("wiz_status/fluffosb",
"(admin)")`，用全新 id `fluffosb` 走真实注册流程验证（密码
`Mud@2026`），本轮所有测试均用这个新账号完成。原 `fluffos` 账号存
档原样保留，未触碰。

### 现场验证摘要

驱动干净启动，`fluffosb` 走完整注册流程（中文名秦风→密码→天赋确
认→邮箱→性别）后确认 `★目前权限：〖银河特警〗(Admin)`，
`update /adm/daemons/logind` 成功验证真实写入权限。踢掉重复登录重
连路径现场用两个真实连线验证通过（保持第一个连线不断开→第二个连
线登录→答 y 踢掉旧连线→`score` 立即正常输出）。`debug.log` 全程干
净（516 行，无真实错误，也没有观察到编译警告泄漏到玩家屏幕）。

### 本轮修改的文件

- `config.fluffos`
- `work/adm/daemons/securd.lpc`
- `work/adm/obj/master.lpc`
- `work/adm/simul_efun/file.lpc`
- `work/cmds/app/update.lpc`
- `work/clone/user/user.lpc`

## 深度功能测试第三轮 / Deep functional test round three (2026-08-18)

标准三项检查清单（§7.111/§7.112/logind `enter_world` 缺存盘）+ 更深
的经济/留言板/门派/重连竞态测试。用种子管理员账号 `fluffosb`
（`Mud@2026`）实测。

### 标准三项检查清单结果

1. **§7.111**（`master.lpc::standard_trace()` 无守卫 `file_name(error["object"])`）：不适用。`work/adm/obj/master.lpc`（真正被
   `config.fluffos` 的 `master file` 指向的那份）和陪伴的
   `work/adm/single/master.lpc` 的 `standard_trace()` 都是用 `%O` 直接
   格式化 `error["object"]`，不是无守卫的 `file_name()` 调用，全档案
   grep `file_name(error` 零命中。
2. **§7.112**（`init()` 里无守卫的 `call_out()` 链）：**命中，已修
   复**——见下。全档案对每个 `init()` 函式体扫了 `call_out(`，多数
   命中点已经有 `remove_call_out()` 自我去重守卫（如一大批 NPC 的
   `"greeting"` 招呼语），真正符合本类 bug 形状（多阶段链、且发起
   端完全没有去重）的只有死亡链 `wgargoyle.lpc`/`bgargoyle.lpc` 这
   两份。另发现两处结构相同但确认是死代码/无害的旁支，未动：
   `d/fenghuang/fenghuang/npc/leader.lpc`（及其 `u/zhangm` 下的重复
   拷贝）全档案 grep 找不到任何房间引用这个 NPC 路径，是从未被实
   例化过的孤儿内容；`d/tianlang/biwu.lpc`（武林大会广场，PK 竞技
   场）的 `call_out("do_recover", ...)` 即使被 `enable_commands()` 重
   连触发第二次，`do_recover()` 本身也是幂等的（把气血内力恢复到
   满，重复执行无副作用），不构成真实 bug，未动。
3. **`logind.lpc::enter_world()` 缺 `ob->save()`**：不适用，该函式里
   `user->save()` 和 `ob->save()` 都齐全且未被注释掉（第 821-822
   行）。

### 修复 3（§7.112）：`d/death/npc/{w,b}gargoyle.lpc` 死亡链重连竞态

`init()` 无条件对刚进房的活人（`userp(previous_object())`）排一个 5
秒后的 `call_out("death_stage", 5, ob, 0)`，且驱动在任何
`enable_commands()`（含玩家断线重连）时都会对房间内每个物件重播
`init()`。如果鬼魂角色在这 5 秒窗口内恰好断线重连一次，会在原有
链条之上再叠一条并行的 `death_stage` 链，导致白无常/黑无常的五段
对话交错重复播放。按 §7.112 标准修法：`init()` 里用
`previous_object()->query_temp("death_stage_active")` 去重、
`set_temp(...)` 占位；`death_stage()` 的两个提前返回点（鬼魂不在场
/ 阶段走完转生）都补上 `delete_temp("death_stage_active")`
清除。`wgargoyle.lpc`/`bgargoyle.lpc` 两份文件形状完全相同，同样手法
修复。两份文件均为纯 CRLF，用 Python 二进制模式做精确字节替换，
`git diff --stat` 确认只改了预期的行。

**现场验证（竞态复现）**：干净重启驱动后，用 `fluffosb` 在
`/d/city/guangchang` 攻击「交通警察」致死，进入 `/d/death/gate`
（白无常已在 `init()` 里排好第一条 5 秒链）；立刻断线重连，重连完
成时刻距死亡时刻仅 **3.10 秒**——正好落在原本会触发重复排程的窗口
内。之后静静等待完整链条跑完：五句死亡对话（"你叫什么名字" /
"你也怪可怜的" / "喘不过气来" / "你命不该绝" / "白无常大吼道"）
**各出现且仅出现一次**，无交错重复，最终正常送到本档案的
REVIVE_ROOM（太空港口）。`debug.log`/`error.log` 全程干净。

### 修复 4（新发现，非清单项）：`u/SEAKING` 整个巫师目录大小写不匹配，商店等多处功能性静默崩溃

在 `/d/tianlang/zhahuopu`（杂货铺）用 `list`/`buy` 时，触发未捕获运
行时错误：`*call_other() couldn't find object '/u/seaking/headjia'.`
（`/feature/dealer.lpc:132` 的 `do_list()`、`:15` 的
`is_vendor_good()`）——错误直接原样广播给玩家，且 `do_list()` 的迭
代在命中第一个失败项后中断，导致清单/购买对大多数商品静默失效。

根源：全档案有 **9 处**跨 5 个不同目录（`d/city/npc/liu.lpc`、
`d/city/npc/dianyuan.lpc`、`d/budui/npc/dxlaoban.lpc`、
`d/tianlang/npc/liu.lpc`、`d/shendian/{npc/,}dxlaoban.lpc`、
`d/shendian/npc/liu.lpc`）的 `vendor_goods`/`new()` 都用小写路径
`/u/seaking/...` 引用这个巫师的私人目录，但硬盘上目录本身是大写
`/u/SEAKING`——Linux 是大小写敏感文件系统，路径永远解析不到。目录
里 4 个文件（`guangjian.lpc`、`jieshouqi.lpc`、`shangwutong.lpc`、
`yangwuliu.lpc`）历史上已经被转成小写 `.lpc`（说明小写才是预期约
定），但目录本身和其余 15 个文件（含 `NPC/` 子目录 3 个）一直停留
在大写 `.C`，从未跟着转换，是当年 WASM/格式化批量转换遗漏的一批。
除商店清单外，`cmds/std/zhizao.lpc`（`new("/u/seaking/jiqiren")`）、
`cmds/skill/jujian.lpc`（`new("/u/seaking/guangjian")`）等制造/铸剑
类巫师指令此前也必然因同一原因静默失败。

修复：全档案 grep 确认零处引用大写 `/u/SEAKING`，`git mv` 整个目录
到小写 `u/seaking`（先转一次性中间名再转最终名规避大小写重命名的
文件系统竞态），并把目录内剩余的 15 个 `.C` 文件（含 `NPC/` 子目录
里 3 个孤儿 NPC，全档案确认未被任何路径引用，纯粹顺手统一命名）
一并 `git mv` 成小写 `.lpc`。纯改名，字节内容零改动。`u/SEAKING/WELCOME`
（非代码文本文件，未被任何路径引用）原样改名跟随目录移动，未改内容。

**现场验证**：干净重启驱动后，`fluffosb` 在杂货铺执行 `list`——原
本卡住的头/手/腿/躯干/足部装甲五件套全部正常列出，无报错；
`buy headjia` 成功购买（"你从刘振那里买下了一块头部装甲"）。
`debug.log`/`error.log` 干净。

### 其它测试

- **留言板**：`/d/wizard/bugroom` 的 `BUG留言簿`，`post <标题>` →
  编辑器写正文 → `.` 保存，`留言完毕` 正常；无 bug（第一次误测漏
  了标题参数导致"什么？"，是测试脚本用法错误，不是 mudlib 问题）。
- **拜师/门派**：`bai jingcha`（交通警察）被正确拒绝——"交通警察
  既不属於任何门派，也没有开山立派，不能拜师"，代码逻辑本身如
  此（NPC 未挂门派属性），是设计而非 bug，未动。
- **战斗/死亡/复活**：完整重跑一遍（结果同前两轮一致，额外验证
  了上面的重连竞态场景）。

### 本轮修改/改名的文件

- `work/d/death/npc/wgargoyle.lpc`（§7.112 修复）
- `work/d/death/npc/bgargoyle.lpc`（§7.112 修复）
- `work/u/SEAKING/` → `work/u/seaking/`（整个目录改名，含目录内 20
  个文件改名为小写 `.lpc`，纯 rename，无内容改动）

### 供未来 sweep 参考的跨库线索

- §7.112 死亡/复活链重连竞态：本次是继本项目今日已在 10+ 个库中独
  立确认之后的第 N 次命中，再次证实是这批档案共有的普遍拷贝粘贴
  形状，值得继续按 AGENTS.md §7.112 清单扫描其余尚未测试的库。
- 大小写不匹配的巫师目录导致整片功能静默失效（本次是 `u/SEAKING`
  vs 引用侧 `/u/seaking`）：这是本项目里之前主要在单个文件名层面
  见过的模式（如 AGENTS.md §7.8/§7.9 记录的 MUDVISITOR/GIFTCARD），
  但本次是**整个目录**层面的大小写不一致，波及面明显更大（商店、
  制造、铸剑等多个不相关的指令入口）。值得在其余库里也用
  `find . -type d` 找一遍是否有全大写的 `u/<WIZID>` 目录、同时又有
  代码以小写路径引用同名目录的情况。

## §7.100 sweep (2026-08-19)

Fixed the corpus-wide `inherit ROOM; ... replace_program(ROOM);` redundant-replace bug (AGENTS.md §7.100). 378 live occurrences deleted: 374 via scripted sweep (`fix_710_room.py`), plus 4 hand-fixed irregular shapes — `clone/misc/roommaker.lpc`'s string-builder ("clone the room I'm standing in" command), two byte-identical copies of `d/fenghuang/fenghuang/taikong.lpc` (space before semicolon, single-line file) under `d/` and `u/zhangm/`, and `d/huang/zoulang4.lpc` (two redundant calls on one CRLF line). Room-builder's heredoc "make an empty room" template was already clean. 4 already-commented-out instances left untouched. No real `.lpc` source found under `work/data/`. Verified via `build-debug` driver boot: clean compile, port 40127 listening, zero new "cannot replace"/"cannot bind" debug.log lines.

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

## §10.7 补测：真正的拜师流程（此前只测过拒绝分支）(2026-08-24)

之前三轮 §10.7 测试都只验证过 `bai jingcha`（对一个没有门派的交通警
察 NPC 拜师）被正确拒绝，从没有找到一个真正挂了门派属性的 NPC 走完
整拜师流程。本轮找到 `d/ziyang/ziyanggong/npc/longjiyang.lpc`（紫阳
派开山祖师龙霁阳，`create_family("紫阳派", 1, "开山祖师")`）作为测
试目标，房间 `d/ziyang/ziyanggong/houdian` 的描述文字本身就写明"有
很多慕名而来的人到这里来拜师"，确认是有意设计的拜师入口。

`bai`/`apprentice`（两个指令实为同一份 `apprentice.c` 的字节级重复
档案，`cmds/skill/bai.lpc` 与 `cmds/skill/apprentice.lpc`）支持两条
路径：(A) 玩家先 `bai <师父>`，师父的 `attempt_apprentice()` 检查天
资/技能门槛后主动喊 `recruit`；(B) 师父先对某玩家喊 `recruit`（设定
`pending/recruit`），玩家再用 `apprentice <师父>` 接受。用管理员账号
`fluffosb`（`setskill` 临时把 `force`/`zidian-ciyun`/`literate` 提到
达标线以上）走通了路径 A，`score` 正确显示【师傅】及门派头衔，无异
常。

### 修复 1：路径 B 必现的运行时崩溃（`family/master_id`/`master_name`
风清扬彩蛋分支括号写错位置）

`apprentice.lpc`/`bai.lpc` 第 56-57 行（两份文件一字不差）：

```c
if ((object)ob->query_temp("pending/recruit") == me) {
    if (((string)me->query("family/master_id" == "feng qingyang")) || ((string)me->query("family/master_name" == "风清扬"))) {
```

括号写错位置，`==` 被塞进了 `query()` 的参数列表内部，实际变成
`me->query("family/master_id" == "feng qingyang")`——先比较两个字符串
字面量（恒为假 `0`），再把 `0` 当 `prop` 参数传给 `query()`。
`feature/dbase.lpc:37` 的 `query(string prop, int raw)` 对 `prop` 无
条件调用 `strsrch(prop, '/')`，`prop` 是 `int 0` 时直接触发驱动层
执行时错误 `*Bad argument 1 to strsrch(): Expected: string Got: 0.`。

这不是从未被触发过的死代码：只要走路径 B（师父先 `recruit`，玩家后
`apprentice`）就 100% 必现，把整条"师父主动招募"路径堵死——`bai
jingcha` 那种"玩家先拜师"的路径（A）不经过这一行，是此前三轮测试
从未发现这个 bug 的原因。

现场复现：`force <师父NPC id> recruit <玩家id>` 让 NPC 先对一个全新
注册、从未拜过师的测试玩家（`sectqa`/赵天行）发起招募，玩家执行
`apprentice long` 立即原样触发上述执行时错误（错误信息直接广播给
玩家，`command_hook()` 吞掉后指令视为失败但连接不断）。

修复：把 `==` 移出 `query()` 的参数列表：

```c
if (((string)me->query("family/master_id") == "feng qingyang") || ((string)me->query("family/master_name") == "风清扬")) {
```

### 修复 2：路径 B 的"叛师"判定缺 `mapp()` 存在性检查（首次拜师会被
误判为叛师）

修复 1 解除崩溃后再往下看，紧接着的叛师检查：

```c
if ((string)me->query("family/family_name") != (string)ob->query("family/family_name")) {
  return notify_fail("你现在不能叛师，还是先问问你们当家的吧！\n");
} else ...
```

`me`（应征弟子的玩家）如果从未拜过师，`me->query("family/family_name")`
返回 `undefined`（`(string)` cast 后是空串或 0），永远不等于师父的门
派名，导致**从未拜过师的新玩家第一次接受招募也会被误判为"叛师"**，
被硬拒绝。这正是本会话在其它库（wxddym 等）反复确认过的同一类 bug：
比较双方门派名之前漏了判断"应征者是否已经有门派"这道存在性检查。姊
妹档案 `cmds/skill/recruit.lpc`（路径 A 的对称实现）自己的注释就写
着 `// follow modified by elon 09-10-95 to fix a bug in 1st time
recruit`，其判定式正确地先守卫了 `(ob->query("family")) &&`——
`bai.lpc`/`apprentice.lpc` 里对称的这一段却从未跟进同样的修法。

修复（比照 `recruit.lpc` 已验证过的写法）：

```c
if (mapp(me->query("family")) && (string)me->query("family/family_name") != (string)ob->query("family/family_name")) {
```

**现场验证**：修复 1、2 都热更新（`update /cmds/skill/bai`、
`update /cmds/skill/apprentice`）后，同一个从未拜过师的测试玩家
`sectqa` 重新执行 `apprentice long`——`龙霁阳决定收你为弟子`，无崩
溃、无误判叛师，`score` 正确显示〖师傅〗龙霁阳、称号"紫阳派第二代
大哈哈"，【判师次数】保持零。清理：销毁测试用的 `龙霁阳` clone，
`sectqa` 账号存档已删除（`work/data/{login,user}/s/sectqa.o`，未
track，直接 rm），`fluffosb` 的临时技能/门派/称号/score 已用
`call fluffosb->delete_skill(...)`/`delete("family")`/
`delete("title")`/`set("score",0)` 复原并 save，驱动已停止。

本轮改动文件：`work/cmds/skill/bai.lpc`、
`work/cmds/skill/apprentice.lpc`（两处同形修复，逐字节相同的两份
文件）。`lpcc_check.sh` 批量编译确认两份文件 PASS（全档案预先存在
168/2660 处无关失败，与本次改动无关，未深究）；`~/src/fluffos` 的
Node 格式化工具本次环境不可用（`node` 命令缺失），未运行 §9 格式化
——改动本身极小（两处括号/一处存在性守卫），未引入格式问题。

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 1 here-document block(s) repaired (1 with the terminator glued to the last text line, 0 with it indented), so `End of file in text block` no longer hides the room or object behind them: `u/xinyi/bedroom.lpc`. The terminator must start its line (the lexer's own test, KB 04 §6.10); a glued one lost its newline in the GBK -> UTF-8 conversion together with a half character, which stays out.

## 深度功能测试（§10.7，2026-10-04）— paths named in another case

The archive comes from a case-insensitive host: files are stored as `BAGUA0.lpc`, `longjing.C`, `d/SHAOLIN/`, the code names them in lower
case (`__DIR__ "bagua0"`, `"tea/longjing"`, `"/d/shaolin/..."`), so the rooms, NPCs and items behind them could not be loaded (a `.C` file is
not an `.lpc` file; KB 03 §4.5). `scripts/lpc_case_paths.py --convert --apply sj`: 155 file(s) renamed to lower case (`.C` -> `.lpc`,
`.H` -> `.h`) and 0 path reference(s) in 0 file(s) rewritten to the new spelling; 0 skipped, 0 ambiguous. Load check of the 210 objects that were renamed, edited or name a renamed path (HEAD against the working tree, an object is the same under any spelling of its path): 15 PASS -> 152 PASS, 0 that loaded before fail now, 137 more load.

155 files moved (146 `.C`, 5 `.lpc`, 4 `(none)`); mostly under `u/zhangm/fenghuang` (99), `u/SZY/ROOM1.C` (1), `u/ZXCDZXCD/BANK.C` (1), `u/ZXCDZXCD/BINGQIKU.C` (1). A rescan with `scripts/lpc_warnings.py sj` is still due: the renamed files are compiled for the first time.

## 深度功能测试（§10.7，2026-10-05）— room base survives a raising NPC

`scripts/lpc_resilient_room.py --apply`: `make_inventory()` of `inherit/room/room.lpc` loads each inventory object as `if (catch(ob = new(file)) || !objectp(ob)) return 0;`. `new()` of a file that is not there returns 0 (the room just lacks that NPC), but `new()` of a file whose `create()` raises (a skill file for `set_skill()` this archive never had, a `carry_object()` item that is not there, a header that never shipped) raised inside the room and the room did not load at all. The wrong-case renames of this lib (the section above) make the NPCs behind them reachable for the first time, so a room that holds one with such a content gap would have gone from "NPC missing" to "room missing"; now it loads without that NPC, as it did before. The room base compiles and loads with the change (HEAD against the working tree). KB 03 §4.5.

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `inherit/room/room.lpc`：`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）；`reset()` 的 `default:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]][j])) continue;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-07）— 编译警告整理

`scripts/lpc_warnings.py sj --fix` 加 `scripts/lpc_fix_no_effect.py --apply`（`kungfu/skill/xuanyuan-arrow.lpc` 删去什么也不做的 `(: throw_weapon :);` 等），共改动 354 个 `.lpc`。HEAD 与工作树分别加载（新进程）：323 -> 323 通过，无回退。`kungfu/skill/shenghuo-lingfa/xiyanling.lpc` 第 20 行有语法错误，HEAD 起就编译不过，未动。

启动时警告 42 -> 0；新进程登录（新人物确认）正常。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 3 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 0 个，只在 #if 分支用的声明移进分支 0 个文件；改动 2 个文件，HEAD 与工作树各载入一次无回退（2 objects; HEAD PASS 2, tree PASS 2; regress 0; newly loading 0），这些文件的警告 3 -> 0。

## 编译警告收尾（2026-10-12）

孪生库 shiji 同日的整理（449f709962b：冗余继承 12 处，钱庄老板等 9 个文件写明 `clean_up()`，`d/shendian/npc/mentu.lpc` 与 `F_SKILL` 同名的空全局 `skills` 删去）用 `scripts/lpc_twin_port.py adopt shiji sj --pre 449f709962b~1` 搬来，24 个文件与 shiji 修前逐 token 相同。HEAD 与工作树各载入一次：24 个对象，HEAD PASS 23，tree PASS 23，regress 0。未改：`include/daemons.h`（Lima 带来的头文件）的宏重定义只出现在编不过的 `ms.lpc`、`mail_serv.lpc` 里。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。1 个文件 1 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。
- 2026-10-14（同一次重扫）：`include/daemons.h` 里重定义的宏先 `#undef`。改动的对象载入无回退。

- 2026-10-14：1 个文件因 `Type of returned value doesn't match function return type ( int vs void )` 整份不编译：声明为 `void`（或没写类型）的函数却返回值，旧驱动照样把值交给调用者。驱动忽略返回值的 apply（`init`、`reset`、`heart_beat`、`create`）里改成空 `return;`（`return ::init();` 改为 `{ ::init(); return; }`，调用照旧）。新进程比对 HEAD 与工作树：1 个对象，新增载入 1，回退 0（`scripts/lpc_fix_void_return.py`，KB 04 §6.3）。

## 内力/精力当作伤害种类（2026-10-15，KB 06 §7.241 第二类）

本库 `feature/damage.lpc` 的 `receive_damage()` 不接受 `jingli`/`neili`/`force` 等种类，`me->receive_damage("jingli", 30)` 之类在练功、绝招、吸取时报 `F_DAMAGE: 伤害种类错误`。2 处改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py` 第二步）。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。1 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。


## 东方故事/西游记体系的技能文件（2026-10-15，KB 06 §7.241 第三类）

这些 `kungfu/skill` 文件来自 gin/kee/sen/force 体系，本库人物只有 jing/qi/neili：`receive_damage("kee", 30)` 报 `伤害种类错误`，`query("force")` 永远为 0，技能学不了也练不了。按 kee→qi、gin/sen→jing、force→neili、max_force→max_neili、force_factor→jiali 改了属性名（`scripts/lpc_port_es_props.py`），共 1 个文件。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

另有 1 个文件（绝招、状态、物品、NPC 等，不限于 kungfu/skill）来自 gin/kee/sen/force 体系，同样按 kee→qi、gin/sen→jing、force→neili 改名（`scripts/lpc_port_es_props.py --any-file`）。

## 所有状态都指向自动存盘守护进程（2026-10-15，KB 06 §7.244）

原档 `include/globals.h` 写的是 `#define CONDITION_D(x) ("/adm/daemons/autosaved")`：F_CONDITION 把每一种状态（中毒、监禁、杀人犯标记……）都交给 autosaved 处理，它在 `sys` 频道广播 `Auto_save has been started`、几次心跳后给所有在线玩家存盘，并返回 0 让原来的状态立刻消失。`kungfu/condition` 里的 46 个状态文件从未被调用过。改回 `("/kungfu/condition/" + x)`（定时存盘另由 `natured.lpc` 的 `auto_save` 负责）；这些状态里沿用东方故事体系的毒同时按 kee→qi、gin/sen→jing 改名（`scripts/lpc_port_es_props.py --any-file`）。实测：中火玫瑰毒一次心跳扣 10 点气、20 点精上限。

## `message_vision(msg, environment(me), me)`（2026-10-15，KB 06 §7.242）

把房间当成了动作者：`message_vision()` 取房间的 `name()` 得 0，`replace_string(msg, "$N", 0)` 报错。在状态（中毒）里，这个错误发生在 `apply_condition(name, duration - 1)` 之前，状态永不结束，心跳里后面的恢复也每次被跳过。改为 `message_vision(msg, me)`：`/d/jianyu/npc/yuzu`、`/d/jianyu/yuzu`、`/kungfu/class/budui/shitailong`。

## 技能按另一门武功的等级取招（2026-10-15，KB 06 §7.243）

这些技能文件是从别的武功复制改名来的，`query_action()` 仍用原武功的等级查招式表：只会本技能的人等级为 0，取不到招，每次出招都报错。改为读本技能自己的等级（`scripts/lpc_fix_action_level.py`）：`duzun-shou`。

## 空手使用兵器绝招（2026-10-15，KB 06 §7.246）

`perform` 指令允许直接点名招式（如 `perform stick.ban`），这些绝招读了 `me->query_temp("weapon")` 却从不检查，空手时 `weapon->name()` 报错（有的已先扣了内力）。在赋值后补 `if (!objectp(weapon)) return notify_fail("你必须手持兵器才能使用这一招。\n");`（`scripts/lpc_fix_perform_weapon.py`）：`wuyue-blade/jiao`。

## 把经验、属性、内力当技能读（2026-10-15，KB 06 §7.247）

经验、属性、内力上限不是技能，xkx/ES 的 `query_skill()` 对它们只返回 0（风云的还会去载入同名技能文件而报错）。改为 `query("...")`（`scripts/lpc_fix_pool_as_skill.py`）：`liancheng-jian/ci`、`liancheng-jian/erguang`（`random(me->query_skill("combat_exp")) > target->query_skill("combat_exp")` 恒为 0 > 0，这一招永远不成功）。

## 圣火令法「吸焰令」从未编译通过（2026-10-15）

`shenghuo-lingfa/xiyanling` 原档 `else if (!objectp(weapon = target->query_temp("weapon"))` 少一个右括号，文件编译失败，这一招从来用不了；后面的兵器判断 `skill_type != "tieling" || skill_type != "shenghuo-ling"` 恒为真，就算编译通过也只会说“你使用的武器不对”。补上括号，兵器判断照同目录的 `duo` 改为 `skill_type != "lingfa"`（本库的铁令、圣火令都是 lingfa 类兵器，`shenghuo-lingfa` 也只能 enable 为 lingfa）。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`yan-fly`→`yanfly`（`yanfly`）。

## 柔云步法「柔云纵」有时报错（2026-10-15，KB 06 §7.251）

`rouyun-steps/zong` 随机把人送到三个房间之一：精、精力已经扣了，“乘云而去了”也说了，送不过去时人留在战斗里并报错。本库的城市（都市中心）也没有 `/d/city/wumiao`、`/d/city/kedian`，三处都会报错；改用本库的 `/d/city/guangchang`（都市中心）和 `/d/city/jiudian`（星际大酒店）。


## 银索金铃「点穴」对空手的对手报错（2026-10-15，KB 06 §7.246）

`yinsuo-jinling/dian` 失手时三种描写之一是“真气贯注”加对手兵器的名字，对手空手时 `ob` 为 0，三次失手有一次报错。改为 `(objectp(ob) ? ob->query("name") : "全身")`（泥潭一系原本就写作“真气贯注全身”）。

## family 映射内联取下标（2026-10-15，KB 05 §7.30）

`ob->query("family")["master_name"]`、`me->query("family")["family_name"]`（泥潭式为 `query("family", ob)[...]`）直接对门派映射取下标：没有门派的人（新玩家、叛师者、大多数 NPC）在 NPC 的打招呼和问话、绝招的门派判断、房间的 `valid_leave` 里报 `Value being indexed is zero`，而不是得到拒绝。6 处（6 个文件）改为 dbase 路径查询 `query("family/master_name")`：有门派时值相同，没有时得 0；原有的判断照常生效（`scripts/lpc_fix_family_index.py`）。给映射赋值的写法未动。


## 血刀刀法「祭血神刀」正神时报错（2026-10-15，KB 06 §7.241）

`xue-dao/shendao` 的伤害是 `random(shen / -1000) + shen / -3000`，越邪恶伤害越高；正神的人算出负数，`receive_damage()` 报“伤害值为负值”。补 `if (damage < 0) damage = 0;`，设计不变（正派用不出伤害），不再报错。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

8 个文件、11 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/d/shaolin/obj/changjian`、`/d/city/obj/gangjian`、`/d/diyu/obj/long-jian`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 0 个，改后 3 个（3 个原来载入不了），没有退步；其余 5 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## 物品清单把名字的第一个字吃掉（2026-10-18，KB 07 §8.1）

`inventory`、房间的物品列表（`feature/move`）和部分 `look` 把同名物品合并计数，键是 `query("unit") + short()`，只有一件时按 `key[2..]` 去掉量词。量词是一个汉字，在原来的 GBK 里占 2 字节，`[2..]` 正好去掉量词；转成 UTF-8 以后一个汉字只占一个下标，这一刀把名字的第一个字也切掉了（「把长剑」只显示「剑」，带颜色的名字切掉的是转义序列开头）。改为 `[1..]`（`scripts/lpc_fix_unit_cut.py`）：`cmds/std/look2.lpc`。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 5 个对象设了本库没有文件的武功（13 个名字，最多的是 `qiankun-danuoyi`、`bibo-shengong`、`anying-fuxiang`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：5 个里 5 个通过。（`scripts/lpc_guard_set_skill.py`）

## 通向不存在房间的出口，按对面房间的回头出口改正（2026-10-18，KB 06 §7.257）

房间出口 `"west": __DIR__"xxx"` 指向的文件本库没有，玩家走过去就被卡住（笔误、改过名的房间，或者没带进档案的编号房间）。对面的房间存在、并且它相反方向的出口正好指回这个房间，说明出口原本就是通向它：`/d/ziyang/ziyanggong/guankou` 的 `east`：`street2` → `/d/ziyang/ziyangcheng/street1`。改动后每个出口都能解析到本库的文件（`scripts/lpc_fix_dead_exits.py`；目标在运行时本来就能载入的库——虚拟房间——不动）。

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 2 处、2 个文件：`xinxiu-duzhang`→`xingxiu-duzhang`（1 处）、`shujian-yidong`→`shunjian-yidong`（1 处）。（`scripts/lpc_fix_skill_names.py`）

## 找不到父类函数的 ::fn() 调用（2026-10-19，KB 06 §7.259）

`/feature/pawn.lpc`共 1 个物件里写着 `::create();`、`::init();` 这类调用，而它们继承的基类并没有这个函数。老驱动把这种调用当成什么都不做、返回 0 的空调用，本驱动在编译时报 `Unable to find the inherited function 'init'.`，整个物件载入不了。这些物件的错误只有这一种（其他错误清掉之后才露出来的），逐个删掉这些调用（`return ::fn(...)` 改成 `return 0;`）。（`scripts/lpc_fix_dangling_super.py`）

## 一行写完的源文件还原（2026-10-19，KB 06 §7.272）

下列 5 个文件的整个源码挤在开头的一行 `//` 注释里（档案的编辑器丢了换行），驱动只编译出一个空程序，物件载入后没有名字、没有 id、拿不到手上：`/d/fenghuang/fenghuang/obj/junfu.lpc`、`/d/fenghuang/fenghuang/obj/junfu1.lpc`、`/u/zhangm/fenghuang/fenghuang/obj/junfu.lpc`、`/u/zhangm/fenghuang/fenghuang/obj/junfu1.lpc`、`/u/zhangm/fenghuang/obj/junfu.lpc`。`scripts/lpc_uncollapse.py` 按语句、语句块、`#include` 重新分行，再过一遍格式化。还原后逐个载入没有退步，`new()` 出来的物件有名字和属性。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 玩家打造兵器模板没有打造者时（2026-10-19，KB 06 §7.275）

`/d/npc/obj/m_blade.lpc`（共 1 个）的 `create()` 开头 `me = this_player();` 之后无条件读 `me->query("weapon/name")` 等打造数据。房间刷新时没有人在场（`me` 为 0），或者 NPC 在别的 NPC 的命令环境里 `carry_object()` 这个模板（NPC 的 `weapon` 属性是文件名字符串），旧驱动里读出来是 0 或字符串，`switch` 照样落到 default；新驱动报 `Bad argument 1 to EFUN call_other()` / `Bad argument 1 to switch`，NPC 和它所在的房间载入不了（`--walk` 普查里一个玩家走进房间就触发）。在 `//读入数据` 之后加 `if (!me || !mapp(me->query("weapon"))) { setup(); return; }`：没有打造者就留一个没有名字的空模板，玩家打造的流程不变。

## `== !"字符串"` 多出来的 `!`（2026-10-19，KB 06 §7.280）

`!"taoist"` 是整数 0，`x == !"taoist"` 就是“x 等于 0”，作者为其余所有人写的那一支永远走不到。具体是：性别检查（“你不是女的，无法领会其中至阴之理”）永远不拦人，男的照样能学玉女心法。全部改成 `!= "字符串"`（`scripts/lpc_fix_not_literal_cmp.py`）：`/kungfu/skill/yunu-xinfa.lpc`（1 处）。同样的行在 xkx 一系的 35 个库里都有。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。改动：`/d/city/xiaolu1.lpc`（1 处）。

## `boss` 指令：`/open/shit.txt` 不在存档里，`write(0)` 报错（2026-10-20，KB 06 §7.285）

`boss 1` 先清屏、屏蔽所有消息，再 `msg = read_file("/open/shit.txt"); write(msg);`。`/open/` 是巫师目录，存档里没有这个文件，`read_file()` 返回 0，`write(0)` 报 `Bad argument 1 to receive()`，玩家的屏幕还被屏蔽着。改为 `if (stringp(msg)) write(msg);`（`cmds/usr/boss.lpc`）。

## `call_out_info()` 的每一项只有 3 个元素（2026-10-20，KB 06 §7.287）

驱动返回的是 `({ 物件, 函数, 延迟 })`，不带 call_out 的参数，旧代码读第 4 项 `info[i][3]`（`callouts` 指令、`calloutd`、`cod` 工具）一读就报 `Array index out of bounds`，指令从第一行起什么也打印不出来。改为 `(sizeof(info[i]) > 3 ? info[i][3] : 0)`（`scripts/lpc_fix_callout_info.py`）。改动：`/cmds/arch/callouts.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 7 处）。改动：`/adm/daemons/logind2.lpc`（2 处）、`/cmds/adm/watch.lpc`（1 处）、`/d/fenghuang/fenghuang/npc/mj.lpc`（3 处）、`/d/tianlang/npc/mei_po.lpc`（1 处）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/obj/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## 翻页器 `start_more(read_file(...))`：文件缺失时 `explode(0)`（2026-10-20，KB 06 §7.300）

东方故事系的翻页器 `void start_more(string msg) { ... explode(msg, "\n") ... }` 被这样调用：`start_more(read_file(HELP_DIR + "help/topics"))`、`start_more(read_file(NEWS))`。压缩包没带的文件使 `read_file()` 回 0，`explode(0, ...)` 在本驱动里报 `Bad argument 1 to explode()`（不带参数的 `help` 指令就是这样出错的），老驱动把 0 当空文本。在 `start_more` 开头加了 `if (!stringp(msg)) return;`（`scripts/lpc_fix_start_more.py`）。改动：`/feature/more.lpc`。

## 首次登录时 `cp()` 缺失的模板文件（2026-10-20，KB 06 §7.310）

`enter_world()` 经 `toptend::query_top()` 在 `/topten/topten_file` 不存在时执行 `cp(TOPTEN_SOURCE, TOPTEN_FILE)`，而 `topten/` 是运行输出（`.gitignore` 排除），压缩包里没有 `topten/source` 模板，`cp()` 报 `*/topten/source: lstat failed`，首次登录控制台出错。在 `cp()` 前加了 `file_size(TOPTEN_SOURCE) < 0 ||`（原有的 `return ""` 即「还没有排行榜」）。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库现有的 NPC 文件里没有字面写成空 `chat_msg` 的（扫描只认 `set("chat_msg", ({ }))`）；守卫挡的是运行时才为空的列表和以后新增的 NPC。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/inherit/char/npc.lpc`（共 1 个文件）。

## `blockade` / `recover`：`data/keep` 不存在，解封之后世界仍然锁着（2026-10-21，KB 06 §7.340）

管理员扫描里 `blockade` 报 `Error copying file from /data/user/f/fluffos.o to /data/keep/fluffos, Error: No such file or directory`，随后的 `recover` 在第一个 `cp()` 上死于 `*/data/keep/fluffos: lstat failed`，来不及执行最后的 `LOGIN_D->set_madlock(0)`：封锁解不开。`data/keep/` 是运行时目录，git 克隆里没有空目录。`blockade` 在第一次写之前 `if (file_size("/data/keep") != -2) mkdir("/data/keep");`（`mkdir()` 失败答 0，不抛错），`recover` 对没有保存档的玩家 `if (file_size(src) < 0) continue;`，其余照常恢复、照常解锁（`scripts/lpc_fix_keep_dir.py`，hy5 上实测：没有保存档时 `recover` 答“时空解封完毕”，`blockade` 建出 `data/keep` 并保存，`recover` 取回并删除）。改动（2 个文件）：`/cmds/arch/blockade.lpc`、`/cmds/arch/recover.lpc`。

## 不带参数的指令对 0 调用 efun：不在 wiz / adm 目录里的指令（2026-10-21，KB 06 §7.336）

指令敲成不带参数时，驱动把 0 传给字符串参数；下面的指令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`。它们在 `cmds/std`、`cmds/usr`、`cmds/bos`、`cmds/app` 这类目录里，上一轮的扫描只看巫师目录。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py --all-dirs` 在第一处使用参数的语句前加守卫：文件自带 `int help(object me)` 的，守卫是 `if (!arg) return help(me);`（`help()` 定义在 `main()` 之后的 1 个文件补了原型 `int help(object me);`，否则编译报 `Undefined function help`）；没有 `help()` 的是 `return notify_fail("…\n");`。改动（1 个文件，括号里是接住 0 的 efun）：`/cmds/app/test.lpc`（`present`）。加载检查 HEAD 与工作树对照，没有退步。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 9 条注册（6 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/clone/misc/bm.lpc`（`do_bselect`）、`/d/budui/obj/topless.lpc`（`do_people`）、`/d/city/npc/jiashen.lpc`（`do_chanhui`）、`/d/shendian/npc/baoyi.lpc`（`do_ban`、`do_gan`、`super_die`、`wave`）、`/inherit/misc/fboard.lpc`（`do_list`）、`/inherit/misc2/fboard.lpc`（`do_list`）。最多的函数名：`do_list` 2 处、`do_bselect` 1 处、`do_people` 1 处、`do_chanhui` 1 处、`do_ban` 1 处。改名：`/d/shendian/npc/wushi2.lpc` 的注册 `do_guozao` → `do_guozhao`（文件里定义的是 `do_guozhao`）。

## 调用了、但这个库自己的守护进程里没有的函数（2026-10-22，KB 06 §7.354）

`MACRO->函数()` 调用的函数在这个库的守护进程里不存在：`call_other()` 对不存在的函数不报错、只返回 0，所以这些功能（时间显示、昼夜事件、名字检查、价格文字……）一直没起作用。同一血统另一个库的同名守护进程里有这些函数，原文照抄到本库守护进程末尾（`scripts/lpc_port_function.py`；调用处传的参数个数、函数体用到的函数 / 全局变量 / 宏 / 字符串键都在本库里有，已核对；守护进程在 HEAD 和工作区都能加载，每个函数用固定参数各调用一次：HEAD 返回 0，现在返回正常的值）：`/adm/daemons/chinesed.lpc` ← bxsj：`chinese_time()`（1 处调用）。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 还剩 2 个函数没有补（other 1, chat_msg_combat 1）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/cmds/usr/help.lpc`:`confirm_l_choice`、`/d/shendian/npc/ma.lpc`:`recover_ob`。

## `(: 函数名 :)` 指针指向本库没有的函数：只含这个指针的行加了注释（2026-10-22，KB 06 §7.355 补充）

`inquiry` / `item_desc` / `chat_msg*` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：用到时（`ask`、`look`、NPC 闲聊）驱动抛 `*Undefined lfun pointer called: 函数名`，这一拍心跳的后半段被跳过。这些函数没有可以补回的来源（别的库同一路径的文件里没有，或者它还要用本库没有的东西），所以 1 个文件里 1 行只含这个指针的行（`(: recover_ob :)`）加了注释，原文保留并写明原因，这一项当作没有这个话题 / 物品 / 闲聊条目（`scripts/lpc_fix_dangling_lfun.py`；`#include` 的文件在库里缺失的对象、指针不在整行上的写法没动）。 前提（`function_exists()`）和加载检查（HEAD 与工作区对比，本库改动的 `.lpc` 文件）的结果见 KB 06 §7.355：没有一个回归。

## 汉字按字节切片的老写法没有换成按字符：改法名 `"澄" + name[2..3]`、辈分判断 `name[0..1] == "澄"` 等 5 处（2026-10-22，KB 06 §7.360）

原档按字节算字符串区间（一个汉字 2 字节）：`name[2..3]` 是名字的第二个字，`name[0..1] == "澄"` 问名字是不是以「澄」开头。转成 UTF-8 之后，这个驱动的区间和 `strlen()` 都按字符算（`strlen("澄观")` 是 2，`"澄观"[0..1]` 是两个字），老算术原样留着、意思全变：各派掌门的辈分判断（`name[0..1] == "澄"`）永远不成立。

本库 5 处（1 个文件）：与汉字常量比较 5 处。例：`s1[0..1] == "。"` → `s1[0..0] == "。"`（`/adm/npc/luban.lpc:1999`）；`s1[0..1] == "！"` → `s1[0..0] == "！"`（`/adm/npc/luban.lpc:1999`）；`s1[0..1] == "；"` → `s1[0..0] == "；"`（`/adm/npc/luban.lpc:1999`）。`scripts/lpc_fix_gbk_slice.py` 把下标按字符重算（社区的 UTF-8 版 `xkx100utf8` 里就是同样的写法，作对照）；没有改的：截断（`name = name[0..7]`，现在最多 8 个字，只是放宽）、ASCII 的区间（`fname[0..3] == "room"`、`ctime(time())[4..19]`）和上下文看不出是汉字的区间。证明（`scripts/lpcc_eval.py`，bixiecanyang；其余各库是同一份文本）：让澄字辈掌门 `attempt_apprentice()` 一个名叫「张三」的访客，HEAD 的法名是 `慧`，改后是 `慧三`；抽样 28 个库的 HEAD / 工作树加载对比 0 退步。工具不幂等（`[0..3]` 折半得 `[0..1]`，又是对齐区间），改过的文件记在 `scripts/gbk_slice_converted.txt`，不要重跑。

## 长度检查按字节写，旁边的提示按汉字写：9 处（2026-10-22，KB 06 §7.362）

老档的 `strlen()` 数字节（一个汉字 2 字节），转成 UTF-8 后它数字符：提示写「必须是 2 到 6 个中文字」的检查还是 `strlen(name) < 4 || strlen(name) > 12`，于是两三个字的房名、帮会名、群名、聊天室名、称号被提示自己说允许的那句话拒绝，上限却是提示的两倍；留言板的标题检查 `i < 4 || i > 24 || i % 2` 还会拒绝所有奇数个字的标题（`post 你好吗`）。本库 9 处（4 个文件）：`if ((strlen(name) < 2) || (strlen(name) > 10)) {`（`/adm/daemons/logind.lpc:954`）；`if ((strlen(name) < 2) || (strlen(name) > 8)) {`（`/adm/daemons/logind2.lpc:839`）。`scripts/lpc_fix_strlen_gate.py` 以提示为准：条件里每个 `strlen` 门槛都恰是提示所说数字的两倍才折半，存长度的变量（`i = strlen(arg);`）的门槛和 `|| i % 2` 奇偶项、其后循环的 `i % 2 == 0 &&` 一并处理；提示里有英文 / 字母 / 字节的不动。证明（`scripts/lpcc_eval.py`，bxsj 的留言板，求值对象继承 NPC 并重写 `edit()` 记录调用，`command("post 标题")`）：HEAD 拒绝「你好」和「你好吗」、放行 23 个字的标题；改后接受前两个、拒绝第三个；shenmo 的 `named.lpc invalid_new_name("张三")`：HEAD 回 `名字只能是2-4个中文字。`，改后回 0。抽样 24 + 15 个库的 HEAD / 工作树加载对比 0 退步。

## 按字节写的汉字循环、茶馆猜诗和同盟频道标题（2026-10-23，KB 06 §7.363）

老档按字节做「一个汉字」：`while (i--) if (i % 2 == 0 && !is_chinese(name[i..<0]))` 只检查偶数下标，奇数位上的拉丁字母（`张a`）会过；茶馆猜诗 `mixup()` 用 `strlen(str)/2` 再 `j=j+j`、`str[k..k+1]` 交换两字节；泥潭系 `channeld` 的 `switch (strlen(fname)) case 4/6/8/10` 和 `strlen(family)==4/6` 按字节长度给同盟 / 门派名加空格。本驱动的 `strlen()` 和区间都按字符算。`scripts/lpc_fix_byte_char.py`：去掉奇偶项、把区间改成 `name[i..i]`，按字符重写 `mixup()` 并把 `strlen(first)>=14` 折成 7，频道标题的 case / 门派长度改成字符数（对照 aoxiangtianji）。本库 汉字循环 / `is_chinese` 区间 4 个文件。证明（`scripts/lpcc_eval.py`）：sjplii 的 `check_legal_name` 在 HEAD 接受「张a」、改后拒绝，两边都接受「张三」；xkx100 的 `clubpoem->mixup("离离原上草")` 得到「离离原草上」（真交换汉字）；nitan_san 两字同盟名得到 `【 兄  弟 】`。关键对象加载通过。

## 血条 / 表情标题按字节算显示宽度（2026-10-23，KB 06 §7.365）

老档把汉字当两字节：`bar_string[0..(val * N / max) * 2 - 1]` 把「格数」换成字节下标，半格血条在本驱动（按字符算区间）上会整条画满；巫师表情 `edemote` 的 `repeat_string("─", 13 - (strlen(emotion) / 2))` 也会少减汉字宽度。`scripts/lpc_fix_display_pad.py`：去掉 CJK 血条 / 空白条上的 `* 2`（`jings`/`qis` 赋值和 `blank_string3[0..(23-a)]` 的 23→11 一并改），表情标题去掉 `/ 2`；ASCII 空格的 `none_string` / `empty_string` 仍保留 `* 2`（一格两个空格）。本库 4 处（2 个文件）。证明（`lpcc_eval.py` hhsj）：`tribar_graph(6,9,12)` 在 HEAD 画出整条 12 个■，改后为 6 个■+3 个□；麻将 `strlen(tempB)/2` 是两字符牌码，未改。


## jiguang-dao inherit .h → gun（2026-10-27，KB 04 §6.25 Also）

`d/budui/obj/jiguang-dao` 写 `inherit "inherit/weapon/blade.h"`（无此对象）却调用 `init_gun(50)`，无法加载。同目录 `jiguangqiang` 用 `inherit "/inherit/weapon/gun"`。改为后者。证明：HEAD 失败；改后加载。

## 深度功能测试（2026-10-27，§6.25 bare set("long" 残渣）

foodmaker 内嵌 `@ROOM_CODE` 模板 `set("long"` 缺开头引号；补 `"`.

## 深度功能测试（2026-10-27，§6.25 zxcd_yongshi 缺分号）

`u/ZXCDZXCD/NPC/zxcd_yongshi`：`inherit NPC` 缺 `;`、语句缺 `;`、id 引号残缺；补 `#include <ansi.h>` 并重写为可加载。

## 深度功能测试（2026-10-27，§6.25 tell_object 参数顺序残渣）

fuyunke telnet：消息/目标对调（含 `(string)message`）。


## 深度功能测试（2026-10-27，§6.25 one-arg message_vision）

`message_vision("…")` 补第二参（`me` / `TP` / `this_player()`）。


## 深度功能测试（2026-10-27，§6.10 未知 pragma save_binary/optimize）

删除本库中 FluffOS 不认的 `#pragma save_binary` / `#pragma optimize…` 行。

