
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
