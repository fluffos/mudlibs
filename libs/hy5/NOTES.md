
## WASM 修复摘要（迁移自 meta.json 的 group_note）

和 146/hy（海洋基础档案）同一血统——同样的重复 create() ftpd.lpc 修复（§7.40）和 author_file() 防递归；完成了一次中断的转档（58882 个档案的压缩包最初转档超时中断）；修复了 tell_room() 里 efun::message() 对 exc_target=0 的拒绝；启动干净。完整 WASM 修复：给 band.lpc 的 is_banned() 加了本地回环放行；修复了和 146/hy 完全相同的 adm/daemons/logind.lpc 里 seteuid(getuid()) 把 euid 重置掉的 bug（create()、howmany_user()、make_body() 都改成显式的 seteuid(ROOT_UID)）；给 howmany_visitor()/howmany_card() 加上了缺失计数档案的防护；修复了 check_legal_name() 过时的 GBK 字节长度界限（4-10→2-5，去掉 i%2==0 门槛，is_chinese() 改成逐字符呼叫）；给 adm/daemons/securd.lpc 的 get_status() 加上了和 146/hy 相同的防重入编译崩溃保护（arrayp(wiz_levels) 判断）。另外发现了一个 146/hy 没有的新 bug：adm/daemons/network/dns_master.lpc 的 startup_udp()/send_udp()/send_shutdown() 无条件呼叫 socket_create/socket_bind/socket_close（WASM 下没有 sockets 包），导致整个档案编译失败——由于 gb_big5() 间接碰到这个精灵，编译失败会静默破坏整个注册流程（input_to(get_id) 从未真正注册过，之后所有输入都落进普通的指令解析器）。已把涉及 socket 的函式体掏空成 no-op 修复，和 §7.52 里 mudlistd.lpc 的模式相同。管理员账号直接播种进了 adm/daemons/securd.o 的 wiz_status 映射（和 146/hy 相同的非 wizlist 机制），用二进制模式编辑。注册流程到进入游戏世界、管理员权限识别都已验证；这条血统的 Big5 提示实际上要求输入 g/gb 或 b/big5（不是 y/n）——不要照搬另一份措辞相似的 146/hy 提示的语义假设。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 62 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（§10.7，2026-08-08）

### 血统确认

`hy5` 与 `146/hy`（海洋基础档案）的 `adm/obj/master.lpc` 逐字节完全相同
（`diff` 输出为空），确认两者共享同一份原始代码根源，与本档案 README
"与 146/hy 同源但代码内容已大幅分叉" 的说法一致——但 `adm/daemons/
securd.lpc` 已被独立重写（与 `hy` 的对应文件 `diff` 有 786 行差异，安
全模型的具体实现形状完全不同：`hy` 用 `switch(func)` 分派，`hy5` 用
`trusted_read`/`exclude_read` 目录前缀表）。本次深度测试里每一条"适
用"的判定都各自独立在 `hy5` 自己的代码里重新确认过，没有直接照搬
`hy`/`hy2000`/`hy2002` 任何一份的具体行号或修法。

管理员账号：`securd.o` 的 `wiz_status` 映射里早就有
`"fluffos":"(admin)"`（WASM 阶段已播种），但翻遍 `work/data/{login,
user}` 都找不到实际的 `fluffos.o` 存档——说明只播种过权限表，从未真
正走过注册流程。本次用标准 `fluffos`/`Mud@2026` 组合走完整个正常注
册流程，创建了真正的存档文件，`(admin)` 权限确认生效，`update` 系
列指令验证正常。

### §8.9 食物/饮水年龄检查错对象——适用，已修复

`adm/daemons/logind.lpc` 的 `enter_world()`：
`if (!user->query("food") && !user->query("water") && ob->query("age") == 14)`
——`ob` 是登录对象，`age` 属性从未在它身上被设置过，判断永远为假。
已改为 `user->query("age") == 14`。

### §7.86 留言板 post 崩溃——不适用，本档案已干净

全档案 grep 未发现任何 `inherit BULLETIN_BOARD` 又多余
`replace_program(BULLETIN_BOARD)` 的活代码（早前的跨库扫描已处理过
62 处）。实测 `look board`（古村留言板，20 条历史留言）和 `post
<标题>` 全链路正常：`post` 打开内建列编辑器，`.` 结束后"留言完毕"，
`look board` 能看到新留言，未观察到任何崩溃。

### §7.5 自定义 ACL 未放行编译期/存在性探测——适用，两个变体同时命中

`adm/daemons/securd.lpc` 的 `valid_read()` 是
`trusted_read`/`exclude_read` 目录前缀表模型，`euid = geteuid(user);
if (!euid) return 0;` 无条件拒绝没有 euid 的调用者，完全没有为
"纯编译期/存在性探测"用途放行。

- **变体一（`file_size`）**：`feature/skill.lpc` 的 `set_skill()` 用
  `file_size(...) < 0` 探测技能档案是否存在，管理员账号在扬州
  武馆触发 `chen2`（陈有德）`create()` 时首次命中——未加防御前会中断
  该 NPC 剩余的技能/装备设置。
- **变体二（`stat`，此前只在 `hy` 上见过）**：`commandd.lpc` 的
  `rehash()` 用 `get_dir()` 列出 `/cmds/std/` 等目录建立指令表，
  `get_dir()` 底层用 `func=="stat"` 走 ACL 检查——`commandd.lpc` 自己
  从不 `seteuid()`，preload 阶段这个调用被拒绝，整张指令表建不起
  来，导致**每一条指令，包括 `look`/`score`，全部回应"什麼？"**，且
  debug.log 没有任何报错信号。这两个症状在同一次 boot 里同时命中
  （不同于 `hy2000`/`hy2002` 只踩中 `file_size` 一种）。

修法：在 `valid_read()` 靠前位置加入
`switch (func) { case "load_object": case "recompile_object": case
"include": case "file_size": case "stat": return 1; }`（放在
`euid = geteuid(user)` 判断之前）。修复后重启，`look`/`score`/
`kill`/`post` 全部正常响应，扬州武馆 NPC 装备/技能设置完整无报错。

### §7.98 daemon `create()` 忘记 `seteuid()`——适用，且有一个此前未见过的变体

驱动启动阶段（早于任何玩家连线）`debug.log` 报出两个和 `hy` 一模一样
的崩溃形状：

```
执行时段错误：*Bad argument 1 to explode()
Expected: string Got: 0.
程式：/adm/daemons/questd.lpc 第 1315 行
呼叫来自：/adm/daemons/questd.lpc 的 create() 第 67 行
呼叫来自：/adm/daemons/questd.lpc 的 read_table() 第 1315 行
```

以及 `adm/daemons/natured.lpc` 的 `create()` → `read_table()` →
`explode(read_file(file), "\n")` 同样的形状——行号和 `hy` 不同（代码
独立重写过），但根因完全一样：`read_file()` 经过 `securd.lpc` 的
`valid_read()`（func 是 `"read_file"`），两个精灵自己都从来没有呼叫
过 `seteuid()`，preload 阶段 euid 为空，被 `if (!euid) return 0;` 拒
绝。`ls -la` 确认 `/quest/dynamic_quest`（3.4KB）和涉及的
`/adm/etc/nature/*` 档案都确实存在于硬盘上，不是档案缺失。修法：在
两个 `create()` 开头各加一行 `seteuid(ROOT_UID);`。

**新变体（`hy`/`hy2000`/`hy2002` 都没有）**：`adm/daemons/bgift.lpc`
**完全没有 `create()` 函数**，它的 `killer_rewardboss()`（只有玩家
击杀特定"boss"级 NPC、掉落宝物/药材奖励时才会被呼叫）里同样有
`read_file("/clone/medicine/ycgift")`/`read_file("/clone/medicine/
wgift")`，同样会被这条 ACL 拒绝——但因为这个函数不在 preload 阶段
执行，只有实际打死对应的 boss NPC 才会触发，boot 阶段完全看不出问
题。已给 `bgift.lpc` 加上一个全新的
`create() { seteuid(ROOT_UID); }`。已写入 AGENTS.md §7.98 追加段落。

### 新发现且大规模复现的 bug：`room2 = load_object(location); local = room2->query("short");` 到处缺少 `objectp()` 防御（已写入 AGENTS.md §7.63 追加段落）

`adm/daemons/taskd.lpc` 的 `give_gift()`（`call_out("auto_save", 88 +
random(20), ...)` 驱动的周期性随机任务/礼物精灵）里，从
`read_file("/clone/medicine/map1")` 随机挑一行地点、`load_object()`
之后立刻 `room2->query("short")`，中间完全没有判断 `room2` 是否真的
成功产生——只要地点列表里有一行是过期/打错的路径，`load_object()`
返回 0，下一行 `->query("short")` 就崩溃
（`*Bad argument 1 to EFUN call_other()`）。这个精灵大约每 90 秒自
动触发一次，不需要玩家做任何事，本次测试的十来分钟窗口内就在
debug.log 里复现了好几次。逐一 grep 后发现这是一个被大量拷贝粘贴的
模式：`taskd.lpc` 本身 19 处、`p/npc/teamjob.lpc` 12 处、
`quest/menpai/teamjob.lpc`（几乎是前者的翻版，走不同 `#include`）12
处、`adm/daemons/natured.lpc`（和上面 §7.98 是同一个档案）4 处、
`cmds/std/ask.lpc` 7 处，全库共 54 处完全相同的裸调用。`u/hxsd/`
下有两份同样未修的历史备份拷贝（`u/hxsd/taskd.lpc/taskd.lpc` 等），
确认不在任何真实加载路径上（没有其它档案以路径字串引用它们），比
照本项目已有的备份档案惯例不予处理。

考虑到 54 处的规模，没有逐一重写控制流（每处后面紧跟的都已经是
`if (local) { ... }`），而是统一做一处不改变行为的替换：
`local = room2->query("short");` → `local = objectp(room2) ?
room2->query("short") : 0;`——让 `local` 在 `load_object()` 失败时正
确落到假值，`if (local)` 分支天然跳过，不需要改任何花括号结构。修复
后重启，同一个随机任务精灵连续运行超过十分钟未再触发任何崩溃。

### 新发现：`kungfu/class/qingcheng/yu.lpc` 里的一处大小写不一致（已写入 AGENTS.md §8.15 追加段落）

用管理员账号触发 `update /adm/daemons/questd`（`questd.lpc` 的
`create()` 会呼叫 `init_dynamic_quest()` → `spread_quest()`，在地图上
随机复制门派掌门 NPC 当作巡游任务发布者）后必现同一个崩溃：

```
执行时段错误：*Bad argument 1 to EFUN call_other()
程式：/kungfu/class/qingcheng/yu.lpc 第 91 行
```

`yu.lpc`（青城派掌门余沧海）的 `create()` 有 `int i = random(2);` 一
半概率的分支：`i==0` 时佩戴 `changjian`（长剑，档案存在），否则佩戴
`carry_object(__DIR__ "whammer")`——但硬盘上实际档案名是
`Whammer.lpc`（首字母大写）。`carry_object()` 自己已经对 `new()`
失败做了 `if (!objectp(ob = new(file))) return 0;` 防御，但调用方没
有检查返回值就直接 `->wield()`，大小写不匹配导致 `new()` 静默失败、
下一行对 `int(0)` 调 `->wield()` 崩溃。全库唯一一处引用，已改字符串
字面量为 `"Whammer"` 与硬盘文件名一致。这个 bug 大约每次
`questd.lpc` 重新编译（含每次开机的 preload）都有 50% 概率命中。

### 死亡/复活：完整验证，但新手保护层数远超预期，靠管理员辅助才走完整个流程

`feature/damage.lpc` 的 `die()` 里叠了至少 5 层"不死"保护（新手
`combat_exp<3000000`、被挑战、擂台比武、平安城 `age<=17`、比武区），
另外还有一层**此前任何 hy 家族笔记都没记录过**的"玩家保护"（第一次
濒死且 `is_fighting()` 时自动满血复活并打上 `isdeads` 一次性标记，
和 `combat_exp` 完全无关）。管理员账号 `fluffos` 和新建的非巫师测试
账号 `testerhy`（毛毛熊）分别在"后村小路"打野兔，两次死亡都触发了
第一层"新手不死"白光效果（"你本来死定了，但一阵白光包围了你"），
被送回平安广场——这是**有意设计**，不是 bug。

为了真正验证鬼门关全流程，用管理员账号对 `testerhy` 执行
`call testerhy->set("combat_exp",5000000)`（跳过第一层保护）、传送
到少林寺厨房（`/d/shaolin/chufang`，不带 `pingan`/`no_fight` 标记）
和"烧饭僧"打起来，再用 `call testerhy->die()` 两次强制触发死亡——第
一次命中了"玩家保护"层（满血复活，`isdeads` 标记消耗掉），第二次才
真正进入死亡分支：`ghost` 置 1、移动到 `/d/death/gate.lpc`（鬼门
关），`白无常`（`wgargoyle.lpc`）的房间 `init()` 自动播放对话，最终
"一股阴冷的浓雾突然出现，很快地包围了你"，正确送到复活点武庙，
`is_ghost()` 确认回到 0——**复活系统本身完全正常**，没有套用 AGENTS.md
§7.68 已撤销的"重试"补丁（`wgargoyle.lpc`/`bgargoyle.lpc` 的
`if (!ob || !present(ob)) return;` 原样保留）。

**副产品发现**：`feature/damage.lpc`/`quest/jianghu/damage.lpc`/
`d/bwdh/damage.lpc`/`d/pk/pk/other/feature/damage.lpc` 四个文件的
`die()` 末尾都有一行 `DEATH_ROOM->start_death(this_object());`，但全
库任何地方都没有定义过 `start_death()` 这个函数（`grep -rn
"start_death"` 只命中这四处调用，没有任何定义）。live 验证过这不是
一个会崩溃/报错的 bug——LPC/FluffOS 的 `call_other()` 对不存在的函数
静默返回 0，不抛异常（本次测试全程 debug.log 没有任何相关报错），
而且真正驱动鬼门关对话的是 `wgargoyle.lpc` 房间 `init()` 的定时器逻
辑，和这个死代码调用完全无关。判定为无害的历史遗留死代码（大概率是
早期版本 `DEATH_ROOM` 自己有 `start_death()`、后来重构掉了但调用点
没清理），未做修改，仅记录。

### 新发现：`config.fluffos` 的 `maximum evaluation cost` 偏低导致任务精灵首次编译重型 NPC 时中断（AGENTS.md 已有 §7.90 同类记录，本次为新确认实例）

深度测试期间 debug.log 出现一次
`Eval interrupted: object quest/haojie/jobnpc/22#1509 cost limit
reached, limit: 700000 usec.` / `执行时段错误：*Too long evaluation.`，
触发点是背景"随机任务系统"（`adm/daemons/jobd.lpc`）编译一个较重的
任务 NPC（`quest/haojie/jobnpc/22.lpc`）。已比照 AGENTS.md §7.90 的
标准修法，把 `config.fluffos` 的 `maximum evaluation cost` 从
700000 提到 5000000（和本项目其它同类修复一致）。修复后重启未再复
现。

### 战斗与移动

平安城→无厘头村→少林寺厨房的多段移动均正常；"练武场"训练用 NPC
武伯未见 `accept_fight` 陪练形状；用野兔（十四只野兔）和烧饭僧分别
做了两场新手向的普通战斗，命令响应、战报格式均正常。

### 其它检查、确认不适用的已知类别

- §7.90（原始 `700000` 的 eval-cost 上限）：见上，已修复为新确认实
  例。
- §8.3a/§8.3b（`command_hook`/`rehash()` 死代码类）：`feature/
  command.lpc` 和 `commandd.lpc` 的对应代码形状本身干净，本档案实
  测到的"什麼？"问题根因是 §7.5 的 `stat` ACL 拒绝，不是这两条。
- printf/debug 泄漏：全库 grep 未发现活的调试输出泄漏进正常游玩路径。
- 本次没有测试：拜师/门派系统深入验证、商店/交易、邮箱（虽然新手礼
  包正常发放）。留给未来某次针对 `hy5` 的后续 pass。

## 深度功能测试（2026-08-13，round two，新驱动重测）

Re-tested against the freshly-rebuilt `build-debug/src/driver`（post
全库 `quest_times`/`win_times` `%`-operator 修复 + Warning/warning
驱动文本回退）。

### 更正上一轮（2026-08-08）的一处不完整记录

上一轮的管理员账号记录只写了"已用真实注册流程创建并提交存档"，没
有意识到（也没有记录）`securd.lpc` 的 `wiz_status` 是 `nosave`——
这个存档文件本身对权限判定完全不起作用，每次开机都会被
`restore_list()` 里的硬编码赋值重置成只有一个 `hxsd`（已经是原始存
档里一个真实玩家）。也就是说，尽管 `fluffos` 角色确实存在，这个账
号登录后**从未真正拿到过 `(admin)` 权限**——和本轮 `hy`（同款 bug，
硬编码 id 是 `lywin`）完全一样的形状，只是 `hy5` 的姊妹档案
`hy2002` 那次的 pass 已经正确记录并修复了这一步，`hy5` 自己这次没
有。

### 发现并修复的 PROGRAMMING bug

1. **`log_error()`（`adm/single/master.lpc`）完全没有严重度检查
   （AGENTS.md §7.34-class，与本轮 `wdxtym`/`ffxymud`/`fy2mg`/`fys`/
   `hc`/`hy`/`hy2000`/`hy2002`/`hy3` 同一原始形状）**：
   `if (this_player(1)) efun::write(...)`——不区分巫师/玩家，也不区
   分警告/错误。修复：加上 `strsrch(message, "arning:") == -1` 判
   断。
2. **`log_file()`（`adm/simul_efun/file.lpc`）完全没有 `assure_file()`
   保护（AGENTS.md §7.11-class 的又一确认实例）**：`clone/family/
   {jiuzhuan,xiaobao}.lpc`/`quest/shenshu/man.lpc` 等文件多处
   `log_file("nosave/using", ...)`/`log_file("nosave/ZS", ...)` 调
   用依赖对应子目录存在。注册/登录本身只写 `log_file("USAGE", ...)`
   （无子目录，本来就存在），不受影响。已补上
   `assure_file(LOG_DIR + file);`（含前向声明）。
3. **管理员账号从未真正拿到 admin 权限（见上方"更正"一节，AGENTS.md
   §1.5 的"wiz_status 声明为 nosave"形状）**：已在 `hxsd` 那行旁边
   并列加一行 `set("wiz_status/fluffos", "(admin)");`。README 已同
   步更正此前不完整的记录。

### Proactive checks（无需改动）

- `win_times` 修复确认存在且正确：`d/city2/npc/refereew.lpc:177`/
  `d/beijing/npc/refereew.lpc:177`。
- 未发现 `message()` simul_efun 包装函数——不适用
  message()-missing-varargs 这一类 bug。

### 实测过程

登录时有一个 GB/Big5 选码提示（选 `g`），用已提交的 `fluffos`/
`Mud@2026` 登录，`score` 确认显示"目前权限：(admin)"（修复后新增
的这次登录才是真正验证过的，上一轮记录的"确认生效"实际上从未真正
生效过），`update /adm/simul_efun/file`（就是本轮改过的文件）确认
可正常重新编译。`u/hxsd/debug.log`/`adm/log/debug.log` 时间戳全程
未变化（`Jul 30`，早于本次会话），确认无新增未捕获运行期错误。登
录本身产生的存档时间戳类微小 diff（`data/user/f/fluffos.o` 的
`last_on` 字段）已用 `git checkout` 撤销，不提交。驱动最终按精确
PID kill，`ps -p` 确认已退出。

## §7.100 跨库扫描修复（`ROOM` 冗余 `replace_program()` 关闭包炸弹，2026-08-19）

`inherit ROOM;` + `create()` 结尾冗余调用 `replace_program(ROOM);` 的
致命形状（机制详见 AGENTS.md §7.100，与 §7.86 留言板崩溃同源，只是
覆盖对象换成了几乎所有房间基类）。本库属于该扫描已知最大规模的
10 个库之一。用二进制模式脚本机械删除了 12248 处独立、未注释的
`replace_program(ROOM);` 整行（`git diff --stat` 与脚本自报删除数
完全吻合），另手工修复了造房工具 `clone/misc/roommaker.lpc`/
`d/ny/obj/roommaker.lpc`/`adm/roommaker.lpc` 代码生成模板里内嵌的
同一形状（5 处，含一处 heredoc、四处字符串拼接），使新建房间不再
继承这颗地雷。删除总数 12253，与本次扫描 FINDINGS.md 记录的
`hy5` 存活命中数完全一致。

验证：干净启动一次真实调试驱动（`build-debug/src/driver`），端口
40183 正常监听，`work/log/debug.log` 全程无新增内容（无
"cannot replace"/"cannot bind"/crash 行）。用已播种的
`fluffos`/`Mud@2026` 管理员账号连线，在欢迎村一带往返走了十余个
房间（`welcome`↔`new1`↔`qianzhuang`↔`dangpu`），`look`/`score`/
`who` 均正常。测试产生的 `data/user/f/fluffos.o` 存档时间戳 diff
已 `git checkout` 撤销，不提交。驱动按精确 PID kill。

### ```§7.112``` residual-gap closure (2026-08-20)

Corpus re-scan (`grep -rl 'call_out("death_stage"' ... | filter for missing guard`) found unguarded `init()`-scheduled `death_stage()` call_out chain(s) in `d/death/npc/panguan2.lpc` that the original two-wave sweep (see AGENTS.md §7.112) missed -- same reconnect-triggered duplicate-chain bug, different filename/lineage. Added the standard `query_temp("death_stage_active")`/`set_temp`/`delete_temp` re-entry guard, adapted per file's own exit points. Compile-verified via `lpcc --batch`.

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

新角度：扬州醉仙楼购物 + 丐帮左全拜师。2026-08-08 / 2026-08-13 两轮
都写明没测商店和拜师。这是海洋V/星月传奇，和 hy 同一血统但登录选单
是 GB/Big5（发 `g`，不是 Y|N）。端口 40183。管理员 `fluffos` /
`Mud@2026`。没有拦登录的 wizpwd（只提示「请用WIZPWD设定」）。横幅有
北京时间心跳。落地 `/d/welcome/welcome`（世界之树 / 古村）。

### 实测过程

管理员 `fluffos` / `Mud@2026`（权限 `(admin)`，中文名毛毛虫）。身上没
钱，`clone /clone/money/gold` 一次成功（本档 `work/log/cmds` 已存在，
没复现 hy2000 那种 clone 崩溃；仍按兄弟库补了 `assure_file`）。

`goto /d/city/zuixianlou`（醉仙楼，店小二 `d/city/npc/xiaoer2.lpc`，
`F_DEALER`，货架比 hy 多酱香牛肉/烧酒壶/烧鸡/车马票）。`list` 烤鸡腿
一两白银又十二文铜板。`buy jitui` 成功（「你从店小二那里买下了一根烤
鸡腿」），讨价还价涨了三级。当场是九十八两白银 + 八十八文铜钱 + 烤鸡
腿。`feature/dealer.lpc` 没有丐帮拒买。

`goto /d/gaibang/inhole`，左全 `kungfu/class/gaibang/zuo-qu.lpc`，
`apprentice zuo` 一次成功：恭喜成为丐帮第二十代弟子。`score` 门派丐
帮、师承左全、称谓「丐帮第二十代弟子」。`save` 真正写盘。杀驱动冷启
动再登录：门派/师傅/九十八两白银/八十八文铜钱都在。烤鸡腿未进
autoload。左全只收男性。

### 发现并修复的 PROGRAMMING bug

1. **华山收徒计数拼写**（与 `hy`/`hy2000`/`hy2002` 同形，静态对照
   修，本轮拜师走的是左全不是华山）：
   `kungfu/class/huashan/{yue-buqun,yue-wife,feng-buping}.lpc`、
   `kungfu/class/yue-buqun.lpc`、`d/biwu/yue-buqun.lpc`、
   `quest/menpaijob/huashan/yue-buqun.lpc` 的
   `add("apprentice_availavble", -1)` 改成 `apprentice_available`。
   档案里还有一批非华山 NPC 同拼写，本轮没扫。

2. **`clone` 写日志不建目录**（`cmds/wiz/clone.lpc`，CRLF）：按
   hy2000 刚撞过的崩溃补 `assure_file("/log/cmds/clone")`。本档
   `log/cmds` 已在，现场 clone 没踩到，属同形预防。

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 4 here-document block(s) repaired (4 with the terminator glued to the last text line, 0 with it indented), so `End of file in text block` no longer hides the room or object behind them: `d/tiezhang/taijie-2.lpc`, `d/dali/yuxu/yuxuguanmen.lpc`, `d/tianshui/yidao1.lpc`, `d/tianshui/zahuopu.lpc`. The terminator must start its line (the lexer's own test, KB 04 §6.10); a glued one lost its newline in the GBK -> UTF-8 conversion together with a half character, which stays out.

## 深度功能测试（§10.7，2026-10-04）— paths named in another case

The archive comes from a case-insensitive host: files are stored as `BAGUA0.lpc`, `longjing.C`, `d/SHAOLIN/`, the code names them in lower
case (`__DIR__ "bagua0"`, `"tea/longjing"`, `"/d/shaolin/..."`), so the rooms, NPCs and items behind them could not be loaded (a `.C` file is
not an `.lpc` file; KB 03 §4.5). `scripts/lpc_case_paths.py --convert --apply hy5`: 132 file(s) renamed to lower case (`.C` -> `.lpc`,
`.H` -> `.h`) and 7 path reference(s) in 3 file(s) rewritten to the new spelling; 0 skipped, 0 ambiguous. Load check of the 181 objects that were renamed, edited or name a renamed path (HEAD against the working tree, an object is the same under any spelling of its path): 14 PASS -> 181 PASS, 0 that loaded before fail now, 167 more load.

132 files moved (128 `.lpc`, 3 `.o`, 1 `.H`); mostly under `p/item/ritemtz3` (36), `d/sdxl/heizhao` (32), `d/yanmen/npc` (30), `d/sdxl/baihuagu` (29). A rescan with `scripts/lpc_warnings.py hy5` is still due: the renamed files are compiled for the first time.

## 深度功能测试（§10.7，2026-10-05）— room base survives a raising NPC

`scripts/lpc_resilient_room.py --apply`: `make_inventory()` of `inherit/room/room.lpc` loads each inventory object as `if (catch(ob = new(file)) || !objectp(ob)) return 0;`. `new()` of a file that is not there returns 0 (the room just lacks that NPC), but `new()` of a file whose `create()` raises (a skill file for `set_skill()` this archive never had, a `carry_object()` item that is not there, a header that never shipped) raised inside the room and the room did not load at all. The wrong-case renames of this lib (the section above) make the NPCs behind them reachable for the first time, so a room that holds one with such a content gap would have gone from "NPC missing" to "room missing"; now it loads without that NPC, as it did before. The room base compiles and loads with the change (HEAD against the working tree). KB 03 §4.5.

## 深度功能测试（§10.7，2026-10-05）— 任务表里的 `.c` 路径与任务守护进程的防护

`scripts/lpc_dynamic_rows.py`：`clone/medicine/dynamic_location`、`clone/medicine/dynamic_location1`、`clone/medicine/dynamic_location2`、`clone/medicine/dynamic_location3`、`clone/medicine/dynamic_location4`、`clone/medicine/dynamic_location5`、`quest/dynamic_location` 里 14171 行写的是原档案的 `.c` 路径。转档时文件已改名 `.lpc`，而显式后缀按原样解析，`load_object("/d/x.c")`、`new("/d/obj/quest/x.c")` 返回 0 且不报错（KB 03 §4.2，KB 06 §7.220），所以 `adm/daemons/natured.lpc`、`adm/daemons/questd.lpc`、`p/npc/teamjob.lpc`、`quest/menpai/teamjob.lpc`、`u/hxsd/npc1.lpc`、`u/hxsd/questd.lpc`、`u/hxsd/questnew.lpc`、`u/spraydew/teamjob.lpc/teamjob.lpc` 读到的每一行都加载不出来：随机任务和任务物品从未生成，在 `create()` 里直接对结果调用 `tar->set()` 的版本还会崩溃，连带加载它的 cron 守护进程和 `give` 的任务钩子。这些行已改为 `.lpc`；另有 5 行指向的文件两种后缀都不存在（档案缺内容），保持原样。
`scripts/lpc_dynamic_quest_guard.py`：3 处 `spread_quest()` 调用（`init_dynamic_quest()` 的循环里）包进 `catch()`，缺失的任务物品或编译不过的房间只跳过那一个任务，守护进程照常加载、其余任务照常生成。
验证：`adm/daemons/natured.lpc`、`adm/daemons/questd.lpc`、`p/npc/teamjob.lpc`、`quest/menpai/teamjob.lpc`、`u/hxsd/npc1.lpc`、`u/hxsd/questd.lpc`、`u/hxsd/questnew.lpc`、`u/spraydew/teamjob.lpc/teamjob.lpc`和 cron 守护进程在新进程里加载（HEAD 一次，工作树三次，选房是随机的）：HEAD 通过 7 个，工作树三次分别通过 7、7、7 个（共 9 个），无回退；`u/hxsd/questd.lpc`、`u/hxsd/questnew.lpc` 在 HEAD 与工作树都加载失败，另有原因，与本次无关。

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `inherit/room/room.lpc`：`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 OK，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-06）— 编译警告清理

1. `scripts/lpc_warnings.py --fix` 机械修复 5692 个文件（未用的局部变量、无效果的表达式、`#pragma save_binary` 等）。启动警告 774 → 0，启动错误不变。
2. 检查：HEAD 与修改后各编译一遍改动过的 5644 个 `.lpc`，结果只差 18 个迷宫（`migong`）NPC，它们的 `create()` 走 `random(2)` 分支，HEAD 自己连跑三次也有 9–11 个随机失败，不是回归。被删局部变量的审计 64 处全是注释里的同名词或同名函数调用（`message(`、`time(`），这些文件都没有 `#if`。两边都编译不过的 40 个文件，错误完全相同。
3. 手工：`quest/shenshu/npc/man2` 里 `order`、`data` 各声明了两次（后一个生效，前一个是旧的短名单），删去前一份；多余的 `int ask_job();` 原型与定义 `string ask_job()` 冲突，删去；`man`/`man2` 的 `kill_ob` 改 `void`，与 `feature/attack` 一致（函数本来就不返回值）。
4. `quest/menpaijob/mingjiao/zhangwuji` 少一个右引号（原文 `A3 22`，转码时连引号一起丢了），整个文件编译不过，明教张无忌从未载入；补回。hymud、haiyang2 同样修改。
5. 验证（新进程，临时副本）：GB 选码 → `fluffos` 登录 → `score`、`look`、`i`、`wiz` 频道、`quit` 正常。
6. **所有对象的 uid/euid 都是空字符串（KB 06 §7.235）。** `quit` 时报「你()不能摧毁其他的使用者」、离开消息打两遍，断线玩家永远留在世界里。原因：主控的 `creator_file()` 有一个启动保护 `if (!find_object(SIMUL_EFUN_OB)) return "";`，而 `config.fluffos` 写的是 `/adm/obj/simul_efun`，`globals.h` 和原始 `config.cfg` 都是 `/adm/single/simul_efun`（两个文件内容相同）。保护所查的对象从未载入，于是每个文件的 uid 都是 `""`，通不过 `ROOT_UID` 判断和 `securd` 的大部分写权限表。把配置改回 `/adm/single/simul_efun`：`/cmds/usr/quitgame` 的 uid 变为 `Root`；登录、`save`、`quit`、断线后重连再 `quit` 都没有错误。
7. **迷宫 NPC 有一半载入失败。** `d/migong/romnpc`、`romnpc2`、`romnpcboss`（被几百个迷宫/首领 NPC include）随机给 NPC 一把 `"/p/item/ritemtz3/wsword" + random(10)` 之类的武器，而这些文件在原 Windows 存档里是大写 `Wsword3.lpc`；早先的大小写修复只把代码里写死的几个（`wsword44`、`ahands42`……）改成了小写，拼出来的路径看不到。`carry_object()` 返回 0，`->wield()` 出错，整个 `create()` 中断：同一批 18 个 NPC 每次编译有 9–11 个失败。前缀改成大写（与 `d/npc/nanxian` 的写法一致），并在 `carry_object()` 失败时不再调用 `wield()`（`Wsword8` 只有小写版本）。修改后连续三次 0 失败。


## 深度功能测试（§10.7，2026-10-07）— 空的 `if (current_water == 0) {}`

3 个房间的 `valid_leave()` 里有一行什么也不做的 `if (current_water == 0) {}`（编译警告 `Expression has no side effects`），删去，行为不变：`d/xingxiu/nanjiang2.lpc`、`d/xingxiu/nanjiang3.lpc`、`d/xingxiu/shanjiao.lpc`。

## 深度功能测试（§10.7，2026-10-07）— 郭靖任务的名单被覆盖

`quest/guojob/guo.lpc` 先后 `#include "zzzjob.lpc"` 和 `"teamjob.lpc"`，两个文件都声明全局 `mixed names`、内容不同（`Redeclaration of global variable 'names'`），后包含的 teamjob 名单覆盖了 zzzjob 的，"保护"任务的目标其实从 teamjob 的名单里抽。teamjob 的表改名 `team_names`（KB 04 §6.10）。`guo.lpc` 在 HEAD 与工作树分别加载（新进程）通过。

## 深度功能测试（§10.7，2026-10-10）— 编译警告整理

`scripts/lpc_warnings.py hy5 --fix` 加 `scripts/lpc_fix_no_effect.py --apply`，共改动 12 个 `.lpc`（多为删去未用的局部变量）。HEAD 与工作树分别加载（新进程）：12 -> 12 通过，无回退。启动时警告 0 -> 0；新进程登录（输入名字）正常。

- 2026-10-11：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 76 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 12 个，只在 #if 分支用的声明移进分支 1 个文件；改动 72 个文件，HEAD 与工作树各载入一次无回退（72 objects; HEAD PASS 59, tree PASS 59; regress 0; newly loading 0），这些文件的警告 114 -> 32。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查

- `d/tieflag/npc/drinkmonk.lpc` `go_in()`：`for (int i = 0; i < sizeof(enemy); i)` 没有自增，第一个敌人不在同一房间时死循环（直到 eval cost 报错）；改为 `i++`。
- 改动的对象 HEAD 与工作区都能载入，无回退。

## 深度功能测试（§10.7，2026-10-11）：钱塘潮颜色

- `adm/daemons/event/qiantang.lpc`：`"…十分壮观。\n"; NOR;` 分号把 `NOR` 隔成独立语句，颜色不复位；改为 `"…" NOR;`。载入无回退。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查（批 3）

- `d/qujing/*/npc/` 下 NPC 的 `create()` 首行残留 `("baoxiang_lao_ban");` 之类的裸字符串（原档删了 `reload` 调用但没删参数，本库没有 `npcsave`），无作用，删去。
- `*/wudoumi-shengong/perform/gui.lpc`：多余的独立 `NOR;` 删去。
- `kungfu/skill/shier-strike.lpc`、`twelve-finger.lpc`：注释掉的 `case 2` 只注释了第一行，第二行 `"迫退至丈许开外。\n" NOR;` 留成独立语句；一并注释。
- 改动的对象 HEAD 与工作区都能载入，无回退。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。63 个文件 78 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）；`x op= 浮点` 先把浮点转成整数再运算（系数小于 1 时 x 直接变 0），改为 `x = to_int(x op ...)`：`/d/npc/beichou.lpc`（`pot +=`）、`/d/npc/beichou.lpc`（`pot +=`）、`/d/npc/beichou.lpc`（`pot +=`）、`/kfedit/skill/fengyun-shou/foguang.lpc`（`damage *=`）、`/kfedit/skill/longzhua-gong/sanzhua.lpc`（`damage *=`）、`/kfedit/skill/taiji-quan/zhan.lpc`（`damage *=`）、`/kfedit/skill/taiji-quan/zhenup.lpc`（`damage *=`）、`/kungfu/skill/fengyun-shou/foguang.lpc`（`damage *=`）、`/kungfu/skill/longzhua-gong/sanzhua.lpc`（`damage *=`）、`/kungfu/skill/taiji-quan/zhan.lpc`（`damage *=`）、`/kungfu/skill/taiji-quan/zhenup.lpc`（`damage *=`）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。
- 2026-10-14（同一次重扫，手工部分）：
  - `p/npc/baowu.lpc`、`boss2.lpc`、`quest/boss.lpc` 和 `quest/menpai`、`quest/task` 下各份 boss/baowu（共 7 个文件）在同一文件里把 `order`、`data` 两张表各定义了两次：前一份较短的旧表在后一份前面。代码只读后一份，所以删去前一份，行为不变。
  - `p/migong/` 下三个迷宫的 `unique_rooms` 与 `VRM_SERVER` 自己的同名变量重名。迷宫是通过 `set_unique_room()` 把表交给基类的，所以把迷宫里的改名 `maze_unique_rooms`，行为不变。
  - `feature/alias.lpc` 的命令计时 `last_time` 改名 `last_cmd_time`。平一指和神医 NPC 自己有存档字段 `last_time`，两者原来同名；`d/city/npc/ping.lpc` 里重复声明的那一行也删去。
  - 四份 `control.lpc` 的 `auto_check()` 定义为 `int`，却另有两条 `void` 原型；删去这两条原型。
  - 21 个 `kill_ob`/`die` 改 `void`，与基类一致（没有调用者用返回值）。
  - `adm/roommaker.lpc`：删去被后一份覆盖的 `special_props` 表。
  - `clone/box/gboxa.lpc`：一大段注释里嵌套的 `/*` 去掉，注释范围不变。
  - 改动的 148 个对象 HEAD 与工作树各载入一次，无回退。
  - 还剩的警告都在编译不过的文件里，是报错后的连带输出：`romnpc*` 等单独编译的包含片段、`maxim/`、`u/tod/job/cheng.lpc`、`wujincao.lpc`。
- 2026-10-14：技能文件里 40 处 `int power_point()`/`int hard_point()` 返回 1.3、1.75 之类的浮点，经 int 返回被截断；本库没有调用者，改成 `float` 返回值，保留原数值（`float_hooks.py`，KB 04 §6.10）。

## 负数伤害当作消耗（2026-10-15，KB 06 §7.241）

`receive_damage("neili", -52)`、`receive_damage("qi", -12)` 之类把 `add()` 的负数写进了 `receive_damage()`：本库 `feature/damage.lpc` 对负数伤害报错（或归零），练功/运功时报 `F_DAMAGE: 伤害值为负值` 或消耗失效。已改为正数伤害，内力/精力类改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py`）：`/kungfu/skill/shaolin-tantui`。

## 东方故事/西游记体系的技能文件（2026-10-15，KB 06 §7.241 第三类）

这些 `kungfu/skill` 文件来自 gin/kee/sen/force 体系，本库人物只有 jing/qi/neili：`receive_damage("kee", 30)` 报 `伤害种类错误`，`query("force")` 永远为 0，技能学不了也练不了。按 kee→qi、gin/sen→jing、force→neili、max_force→max_neili、force_factor→jiali 改了属性名（`scripts/lpc_port_es_props.py`），共 7 个文件。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

另有 17 个文件（绝招、状态、物品、NPC 等，不限于 kungfu/skill）来自 gin/kee/sen/force 体系，同样按 kee→qi、gin/sen→jing、force→neili 改名（`scripts/lpc_port_es_props.py --any-file`）。

## 治疗/疗伤的属性名（2026-10-15，KB 06 §7.241）

`receive_heal()`/`receive_curing()` 也只接受本库的种类。1 个文件（多为只调用 `receive_heal`/`receive_curing` 的药物、NPC）来自其他体系，按本库的属性名改名（`scripts/lpc_port_es_props.py --any-file`）。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。14 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。

## 空手使用兵器绝招（2026-10-15，KB 06 §7.246）

`perform` 指令允许直接点名招式（如 `perform stick.ban`），这些绝招读了 `me->query_temp("weapon")` 却从不检查，空手时 `weapon->name()` 报错（有的已先扣了内力）。在赋值后补 `if (!objectp(weapon)) return notify_fail("你必须手持兵器才能使用这一招。\n");`（`scripts/lpc_fix_perform_weapon.py`）：`tmjian/jianshen`、`wuyue-blade/jiao`。

## 把经验、属性、内力当技能读（2026-10-15，KB 06 §7.247）

经验、属性、内力上限不是技能，xkx/ES 的 `query_skill()` 对它们只返回 0（风云的还会去载入同名技能文件而报错）。改为 `query("...")`（`scripts/lpc_fix_pool_as_skill.py`）：屠龙刀法 `/kfedit/skill/yitian-tulong/tulong`、`/kungfu/skill/yitian-tulong/tulong`（比较经验时目标一侧读成 0）。

## 妙手回春的银针检查（2026-10-15）

`miaoshouhuichun` 的 `valid_learn()` 用了未赋值的 `object ob`，`ob->query_temp("weapon")` 每次都报错，谁也学不了；还把兵器对象和字符串 "银针" 比较。照 chidi 的修法改为 `ob = me->query_temp("weapon")`，再用 `id("yin zhen")`/`id("yinzhen")` 判断是否银针。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`yinyun_ziqi`→`yinyun-ziqi`（`/kfedit/skill/yinyun-ziqi/cure`、`yinyun-ziqi/cure`）；`buddhsim`→`buddhism`（`qianye-shou`）；`douzhuan-xignyi`→`douzhuan-xingyi`（`/d/mr/obj/shu1`）；`jinwu-dao`→`jinwu-daofa`（`jinwu-daofa`）；`zhengqi-jue`→`zhengqijue`（`/d/bwdh/human`）。

## 嵩山剑法「蓄力」没穿布衣时报错（2026-10-15）

`songshan-jian/xuli` 用 `cloth = me->query_temp("armor/cloth")` 取衣服，随后直接 `cloth->query("material")` 判断要不要显示“衣袖鼓起”的描写；身上没有布衣时（裸身或只穿铠甲）这里报错，而此时 `apply/speed` 已经扣掉、复原的 call_out 还没排上，身法就一直少了一截。两处判断前补 `objectp(cloth) &&`。

## 技能名拼错：技能文件里拼错自己的名字（2026-10-15，KB 06 §7.249）

技能自己的文件（或它的绝招目录）里，`query_skill()` 读的是差一个字母的自己的名字，永远得 0：“基本功夫要高过本技能”之类的限制从不生效，按等级取招、计算伤害的那一项一直是 0。改为本技能的名字（`scripts/lpc_fix_skill_typo.py` 的 self 判据）：`baniao-jian`→`bainiao-jian`（`/kfedit/skill/bainiao-jian/bnzh`、`bainiao-jian/bnzh`）；`chanyun-tui`→`chuanyun-tui`（`/kfedit/skill/chuanyun-tui/shuangjue`、`chuanyun-tui/shuangjue`）；`frht-hamer`→`frht-hammer`（`/kfedit/skill/frht-hammer/san`、`frht-hammer/san`）；`lenyue-shengong`→`lengyue-shengong`（`lengyue-shengong`）；`liuyan-dao`→`lieyan-dao`（`lieyan-dao`）；`shenhuo-ling`→`shenghuo-ling`（`shenghuo-ling`）；`xiyu-tiezhang`→`xiyu-tiezheng`（`xiyu-tiezheng`）。

## 银索金铃「点穴」对空手的对手报错（2026-10-15，KB 06 §7.246）

`yinsuo-jinling/dian` 失手时三种描写之一是“真气贯注”加对手兵器的名字，对手空手时 `ob` 为 0，三次失手有一次报错。改为 `(objectp(ob) ? ob->query("name") : "全身")`（泥潭一系原本就写作“真气贯注全身”）。


## 存档读不出来：转码损坏（2026-10-15，KB 03 §4.4）

`/data/mail/m/mmxnet.o` 在转码时坏了：原档里孤立的 GBK 前导字节被 `iconv -c` 连同后面的引号一起丢掉，`restore_object()` 报 `Illegal mapping format`，读档的对象（玩家、留言板、信件、表情）从空白开始。按 raw/ 原档重新解码（孤立字节丢掉、引号保留），驱动核对全部能读回（`scripts/lpc_save_encoding.py --from-raw`、`scripts/lpc_save_restore_check.py`）。

## family 映射内联取下标（2026-10-15，KB 05 §7.30）

`ob->query("family")["master_name"]`、`me->query("family")["family_name"]`（泥潭式为 `query("family", ob)[...]`）直接对门派映射取下标：没有门派的人（新玩家、叛师者、大多数 NPC）在 NPC 的打招呼和问话、绝招的门派判断、房间的 `valid_leave` 里报 `Value being indexed is zero`，而不是得到拒绝。2 处（1 个文件）改为 dbase 路径查询 `query("family/master_name")`：有门派时值相同，没有时得 0；原有的判断照常生效（`scripts/lpc_fix_family_index.py`）。给映射赋值的写法未动。


## 存档读不出来：字符串里的换行、空行（2026-10-15，KB 03 §4.4）

`clone/gift/npc/bingqipu.o`：字符串里有原样的换行（`save_object()` 存成 `\r`，`restore_object()` 逐行读，原样的换行让字符串收不了尾），或有空行（`Illegal file format`），读档的对象（留言板、NPC、玩家）从空白开始。换行改写成 `\r`、删去空行（`scripts/lpc_save_encoding.py --from-raw`），驱动核对全部能读回（`scripts/lpc_save_restore_check.py`）。

## 移进不存在的巫师房间（2026-10-15，KB 06 §7.251）

用完的物品、要“离开”的 NPC、掷在空中的兵器被移进巫师的工作室（`/u/wind/`），本库没有这些房间。本库的 `move()` 用 `call_other(dest, "???")` 载入目的地，找不到文件就报 `call_other() couldn't find object`，后面的语句都不执行：被雇来打晕或杀人的李凌（`d/jingzhou/npc/liling2`）办完事要离开时报错，留在原地。1 个文件改为移进本库的虚空房间 `VOID_OB`（`/clone/misc/void`），与原作把它们“停放”在巫师房间的用意相同。

## 燃木刀法「焚天」的效果一秒就消失（2026-10-15，KB 06 §7.246）

每秒检查的 `check_fight()` 声明了 `object weapon;` 却从不赋值，条件里的 `!weapon` 永远为真，效果在第一次检查时就被撤掉。把这一项改为 `!objectp(weapon = me->query_temp("weapon"))`，先存兵器再判断刀的种类。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

2 个文件、2 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/clone/obj/demon_staff`、`/d/city/obj/tudao`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 0 个，改后 1 个（1 个原来载入不了），没有退步；其余 1 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## 物品清单把名字的第一个字吃掉（2026-10-18，KB 07 §8.1）

`inventory`、房间的物品列表（`feature/move`）和部分 `look` 把同名物品合并计数，键是 `query("unit") + short()`，只有一件时按 `key[2..]` 去掉量词。量词是一个汉字，在原来的 GBK 里占 2 字节，`[2..]` 正好去掉量词；转成 UTF-8 以后一个汉字只占一个下标，这一刀把名字的第一个字也切掉了（「把长剑」只显示「剑」，带颜色的名字切掉的是转义序列开头）。改为 `[1..]`（`scripts/lpc_fix_unit_cut.py`）：`cmds/xmud/xnventory.lpc`。

## `kungfu/skill/qingyi-jian` 第一式的 `skill_name` 丢了收尾引号（2026-10-18，KB 03 §4.6）

`"skill_name" : "大悲式,` 的收尾引号没了（转码时跟半个汉字一起丢了），字符串连到下一行，`damage_type` 成了代码：`Illegal character 0xe5`，整个武功载入不了。补回 `",`（同系的 bixiecanyang、syxjl 等库里有完好的同名文件）。载入：通过。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 8 个对象设了本库没有文件的武功（42 个名字，最多的是 `moon-blade`、`yue-strike`、`anxiang-steps`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：8 个里 8 个通过。（`scripts/lpc_guard_set_skill.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 92 处、73 个文件：`bixie-sword`→`pixie-sword`（36 处）、`kunlun-shnfa`→`kunlun-shenfa`（16 处）、`shaolin-shnfa`→`shaolin-shenfa`（12 处）、`tiaji-jian`→`taiji-jian`（4 处）、`lingbo-weibu`→`lingboweibu`（4 处）、`yunu-xinfa`→`yunv-xinfa`（4 处）、`xiuluao-dao`→`xiuluo-dao`（3 处）、`yiyangzhi`→`yiyang-zhi`（2 处）等共 16 个名字。（`scripts/lpc_fix_skill_names.py`）

## set_name 的 id 参数传成字符串（2026-10-19，KB 06 §7.260）

`set_name("海口大碗", "bowl");` 把物品的 id 写成了字符串，本库的 `set_name(string name, string *id)` 要的是数组，驱动在编译时报 `Bad type for argument 2 of set_name ( string * vs string )`，整个物件载入不了；旧驱动不检查参数类型，字符串里照样找得到这个词，物品能用 id 称呼。改成 `({ "bowl" })`，共 1 个文件：`/d/baituo/npc/obj/bowl.lpc`。（`scripts/lpc_fix_set_name_id.py`）

## feature/damage.lpc 丢了 set_ghost()（2026-10-19，KB 06 §7.262）

`feature/damage.lpc` 里有 `int ghost` 和 `is_ghost()`，没有 `set_ghost(int i)`；木人、狼等 NPC 在 `create()` 里调用它，整个 NPC 报 `Undefined function set_ghost` 载入不了。从 xkx100 补回这一行函数，受益 NPC 9 个：`d/nanshaolin/npc/muren-fighter1`、`d/nanshaolin/npc/muren-fighter2`、`d/nanshaolin/npc/muren-fighter3`。（`scripts/lpc_transplant_function.py`）

## 全局头文件丢了 2 个宏（2026-10-19，KB 04 §6.16）

`/include/globals.h` 里没有定义 `EVENT_DIR`、`MAILDIR`，用到它们的物件（名单里 2 个）编译时报 `Undefined variable`/`Undefined function`，整个物件载入不了（编译器在第一个未定义的名字上停下，后面的错误和警告都看不到）。同系的库在各自的头文件里都有这几行：照其中和本库共有文件最多的那个库，原样补到 `/include/globals.h` 最后一个 `#define` 之后，宏体里出现的路径在本库里都存在。名单里的物件除了这几个宏之外还有别的错误，暂时仍载入不了。（`scripts/lpc_restore_defines.py`）

## 和包含文件同目录的头文件，改成引号形式（2026-10-19，KB 04 §6.17）

24 个文件用尖括号写 `#include <hedi.h>` 这类头文件（`allnpc.h`、`hedi.h`、`hunyin.h`、`obstacle.h`、`random_name.h` 等），头文件其实就放在它们自己的目录里。老驱动对尖括号名字也会先找包含文件所在目录，本驱动只找 include 路径，所以报 `Cannot #include ...`，整个物件载入不了。改成 `#include "hedi.h"`（引号形式相对包含文件解析，预加载、`lpcc` 和运行时编译都一样）。（`scripts/lpc_fix_local_include.py`）

## sanniang 的 query(environment(...))->query（2026-10-19，KB 06 §7.266）

`d/biancheng/npc/sanniang.lpc`（边城的三娘）里写成了 `query(environment(this_object()))->query("discussion_shen")`，多了外面一层 `query(`，驱动报 `Bad type for argument 1 of query ( string vs object )`，整个 NPC 载入不了；同一个文件另一处正确写成 `environment(ob)->query("discussion_shen")`。去掉多余的 `query(`。

## 出口指向不存在的房间（2026-10-19，KB 06 §7.257）

下列房间的出口写的文件不存在，而对面恰好只有一个房间的出口指回本房间，所以按对面的房间改正（笔误、大小写、路径少了一级）：

- `/d/xiyou/death/new-walk5.lpc` 的 `north` 出口：`/d/death/zhengtang` → `/d/xiyou/death/zhengtang`
- `/d/yanmen/shance.lpc` 的 `north` 出口：`CANYON7` → `canyon7`

改后房间照常载入（与 HEAD 逐个对比，没有退步），出口现在指向存在的房间。

## 一行写完的源文件还原（2026-10-19，KB 06 §7.272）

下列 1 个文件的整个源码挤在开头的一行 `//` 注释里（档案的编辑器丢了换行），驱动只编译出一个空程序，物件载入后没有名字、没有 id、拿不到手上：`/d/taoyuan/npc/kid.lpc`。`scripts/lpc_uncollapse.py` 按语句、语句块、`#include` 重新分行，再过一遍格式化。还原后逐个载入没有退步，`new()` 出来的物件有名字和属性。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 两个斜杠开头的物件路径（2026-10-19，KB 06 §7.276）

1 个文件、1 处物件路径写成 `//…`（如 `carry_object("//clone/cloth/hic_cloth")`）：`/d/gaoli/npc/xiake.lpc`。当年的驱动不介意（路径先被规范化）；新驱动把原样的字符串交给 master 的 `valid_read()`，securityd 按 `//clone` 查目录，NPC 的 euid 没有权限，报 `Read access denied.`，NPC 载入不了。改成一个斜杠。

## 玩家打造兵器模板没有打造者时（2026-10-19，KB 06 §7.275）

`/d/npc/m_weapon/weapon/m_blade.lpc`、`/d/npc/m_weapon/weapon/m_club.lpc`、`/d/npc/m_weapon/weapon/m_hammer.lpc`、`/d/npc/m_weapon/weapon/m_staff.lpc`、`/d/npc/m_weapon/weapon/m_sword.lpc`、`/d/npc/m_weapon/weapon/m_whip.lpc`（共 6 个）的 `create()` 开头 `me = this_player();` 之后无条件读 `me->query("weapon/name")` 等打造数据。房间刷新时没有人在场（`me` 为 0），或者 NPC 在别的 NPC 的命令环境里 `carry_object()` 这个模板（NPC 的 `weapon` 属性是文件名字符串），旧驱动里读出来是 0 或字符串，`switch` 照样落到 default；新驱动报 `Bad argument 1 to EFUN call_other()` / `Bad argument 1 to switch`，NPC 和它所在的房间载入不了（`--walk` 普查里一个玩家走进房间就触发）。在 `//读入数据` 之后加 `if (!me || !mapp(me->query("weapon"))) { setup(); return; }`：没有打造者就留一个没有名字的空模板，玩家打造的流程不变。

## 手工收尾（2026-10-19，KB 04 §6.10）

- 标准整理轮的第一轮删掉 5 个文件里 12 个未使用的局部变量：`d/marry/hunyin.h`、`d/pingan/marry/hunyin.h`、`d/pingan/pingan/marry/hunyin.h`（`do_lihun()` 的 `card`、`inv`、`i`，`do_jiehun()` 的 `card`、`mes1`；`d/pingan/` 里那份的 `diary_write` 等几行被注释掉，所以多出几个），`d/qujing/jingjiling/npc/allnpc.h`（`player_win()` 的 `obj`），`d/taoyuan/npc/kid.lpc`（`create()` 的 `i`、`amun`）。
- 这个库有 5.9 万个文件，第二轮重扫要一个多小时，超过整理脚本的时限，没有等；第二轮要做的诊断驱动修复也不适用（扫描里没有那几类）。

载入 include 这些头文件的 `d/marry/chen.lpc`、`CHENG.lpc`、`d/pingan/*/marry/chen.lpc`、`d/qujing/jingjiling/npc/` 的 bo、hui、song、zhu 和 `kid.lpc`：HEAD 通过 9 个，现在通过 9 个，没有退步。

## 补回丢失的标点（2026-10-19，KB 03 §4.6）

转换时丢掉的分号、逗号、引号或文件末尾的 `}`，共 8 个文件，修前 HEAD 载入失败。别的库里同路径的完好副本只比这里少几个标点，按它补回（括号里是那个库）：`/d/city2/npc/zhengmen.lpc`（jqxz2008）。一行文字在逗号前丢了结尾的引号（下一行是同一个表的下一项），补上：`/kungfu/skill/huanhe-dao.lpc`、`/kungfu/skill/kunlun-zhang.lpc`、`/quest/menpaijob/dali/quest.lpc`、`/quest/menpaijob/tiezhang/quest.lpc`、`/quest/newbie/qiandao/lagjobold.lpc`、`/quest/songhuo/quest.lpc`。文件末尾少了 `}`（最后一个或两个字节丢了），补上：`/kfedit/condition/wuhudu_poison.lpc`。修后与 HEAD 逐个对比载入：这 8 个物件全部载入，没有退步（`scripts/lpc_restore_from_twin.py`、`lpc_fix_eaten_quote.py --comma`、`lpc_fix_eof_braces.py`）。

## 补回标点后新载入的物件里的未使用局部变量（2026-10-19，KB 04 §6.10）

之前载入失败、补回丢失的标点后才载入的物件里还有未使用的局部变量警告，共 2 个文件：`/kungfu/skill/huanhe-dao.lpc`、`/kungfu/skill/kunlun-zhang.lpc`。删掉没有用到的声明；用 `scripts/lpc_listcheck.sh` 对比 HEAD 和改后，物件仍然载入，没有警告。

## 旧驱动的类型宽松：缺省参数、无类型形参、数组初始化、`class` 变量（2026-10-19，KB 04 §6.19、§6.20）

原来的 MudOS 把调用少传的参数补 0、把没写类型的形参当 `mixed`、不检查变量的声明类型与初始值，也允许变量叫 `class`；这个驱动在编译时全部拒绝，整个物件载入失败。修了 5 个文件：`/u/dhxy/gem.lpc`、`/u/dhxy/gem2.lpc`、`/u/guaf/gem.lpc`、`/u/hxsd/gemw.lpc`、`/u/hxsd/hxsdm.lpc`（`scripts/lpc_round_files.py` 的修复轮：调用处补写 `0`、无类型形参补 `mixed`、`string X = ({...})` 补星号、void 函数的返回值，以及 `class` 变量改名 `pick_class`）。逐个文件在 HEAD 和改后载入对比：这些文件里 5 个原来载入失败、现在载入，没有退步。

## `== !"字符串"` 多出来的 `!`（2026-10-19，KB 06 §7.280）

`!"taoist"` 是整数 0，`x == !"taoist"` 就是“x 等于 0”，作者为其余所有人写的那一支永远走不到。具体是：龙女的 class 判断永远走不到“不是道士”那一支；龙女的 class 判断永远走不到“不是道士”那一支。全部改成 `!= "字符串"`（`scripts/lpc_fix_not_literal_cmp.py`）：`/d/gumu/npc/longnv.lpc`（3 处）、`/quest/menpaijob/gumu/zf/longnv.lpc`（3 处）。同样的行在 xkx 一系的 35 个库里都有。

## `x == "a" || "b"`：后面的字符串常量永远为真（2026-10-19，KB 06 §7.281）

`if (arg == "yuyou" || "yu you")` 里的 `"yu you"` 是非空字符串，永远为真，整个条件对任何 `arg` 都成立；作者要的是每个字符串都和变量比较。具体是：离开时清除“砍柴”标记只在往北走时才生效，往南不清。在每个字符串前补上变量和运算符（`scripts/lpc_fix_literal_or.py`；`forrest2.lpc` 是 `dir == "north" && "south"`，手工改成 `(dir == "north" || dir == "south") && ...`）：`/d/xiyou/lingtai/forrest2.lpc`（1 处）。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。具体是：客栈小二从不拦住付了房钱又往南/往北走的客人。改动：`/d/changan/ca2.lpc`（1 处）、`/d/mingjiao/shanmen.lpc`（1 处）、`/d/sdxl/baihuagu/yangfeng.h`（1 处）、`/d/taiyuan/shanxi/obj/jiuwan.lpc`（1 处）。另有 `/d/city/npc/majiang.lpc`（2 处）、`/d/jinan/npc/mj.lpc`（2 处） 的条件下面做的是别的事（`==` 和 `||` 也可能是本意），保持原样。

## `member_array('/', str)` 改为 `strsrch(str, "/")`：字符字面量的 member_array 按字节搜索（2026-10-20，KB 06 §7.283）

`member_array('/', str)` 里的 `'/'` 是整数，驱动按 UTF-8 **字节**搜索，返回字节偏移（带第三个参数时起点也是字节）；最新的 FluffOS（923cdbc0）在字符串里有非 ASCII 文字时，对每个调用点警告一次（`Warning: member_array(int, string) searches BYTES`）。而 `str[0..idx-1]` 按字符切，中文字符串会在错误的位置截断。改为 `strsrch(str, "/")`（找不到同样返回 -1，按字符计数；`scripts/lpc_fix_member_array_char.py`，JSON 编码器等少数几处手改）。改动：`/adm/daemons/vrm_server.lpc`（1 处）、`/adm/daemons/vrm_server2.lpc`（1 处）、`/adm/daemons/vrm_serverbak.lpc`（1 处）、`/adm/daemons/vrm_servertnew.lpc`（1 处）。

## `call_out_info()` 的每一项只有 3 个元素（2026-10-20，KB 06 §7.287）

驱动返回的是 `({ 物件, 函数, 延迟 })`，不带 call_out 的参数，旧代码读第 4 项 `info[i][3]`（`callouts` 指令、`calloutd`、`cod` 工具）一读就报 `Array index out of bounds`，指令从第一行起什么也打印不出来。改为 `(sizeof(info[i]) > 3 ? info[i][3] : 0)`（`scripts/lpc_fix_callout_info.py`）。改动：`/cmds/arch/callouts.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 61 处）；其后 `x == "a" && x == "b"` / `x == "a" || "b"` 这类被 `==` 暴露出来的链也随之改成 `||` 或补全变量（`/d/hainan/npc/xiaohe.lpc`）。改动：`/adm/daemons/combatd.lpc`（11 处）、`/adm/daemons/combatdtest.lpc`（1 处）、`/clone/npc/man.lpc`（1 处）、`/cmds/usr/bangding.lpc`（1 处）、`/d/baiyun/shanliu/npc/xiucai.lpc`（1 处）、`/d/city/npc/matong.lpc`（3 处）、`/d/city/shufengguan.lpc`（1 处）、`/d/city4/mj/1mj.lpc`（3 处）、`/d/city4/mj/mj.lpc`（3 处）、`/d/city4/npc/majiang.lpc`（3 处）、`/d/city4/npc/matong.lpc`（3 处）、`/d/city4/obj/mj.lpc`（3 处） 等 29 个文件。

## `callouts`：`sizeof(info[i]) == 4` 把每一行都挡掉了（2026-10-20，KB 06 §7.287）

驱动的 `call_out_info()` 每项只有 3 个元素，输出行前的守卫 `if (sizeof(info[i]) == 4)` 永远不成立，指令只打印表头。改为 `>= 3`。改动：`/cmds/arch/callouts.lpc`（1 处）。

## `mcheck`：`query_ip_rport()` 驱动里没有（2026-10-20，KB 06 §7.291）

指令要显示连线的远端端口，MudOS 时代的 `query_ip_rport()` 在 FluffOS 里不存在（`query_ip_port()` 给的是本地端口），指令编译不过。文件里加了一个返回 `"?"` 的占位函数（dtsl 的同名指令早就这么做）。改动：`/cmds/imm/mcheck.lpc`。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/single/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## 目录读出后的后缀截取宽度（2026-10-20，KB 06 §7.296）

`.c` 改名成 `.lpc` 之后，`get_dir("*.lpc")` 读出的文件名还按两个字符截取（`$1[0..<3]`）：`baguadao.lpc` 变成 `baguadao.l`，用它拼出的路径加载不到对象（故事、战场、事件、帮助、自造物品数据、召唤列表等）。改成 `[0..<5]`（`scripts/lpc_fix_getdir_strip.py`）。改动：`/adm/daemons/eventdbak.lpc`（1 处）。

## sefun `cat()`：缺文件时 `write(0)` 报错（2026-10-20，KB 06 §7.297）

`void cat(string file) { write(read_file(file)); }`：文件不存在（压缩包没带的欢迎/公告文件，或只有运行中的 mud 才会写的日志）时 `read_file()` 回 0，`write(0)` 在本驱动里报 `Bad argument 1 to receive()`，调用者（登录对话、`cat` 指令）被中断；老驱动什么也不打印。改成 `write(read_file(file) || "");`（`scripts/lpc_fix_cat_unchecked.py`）。改动：`/adm/simul_efun/file.lpc`。
