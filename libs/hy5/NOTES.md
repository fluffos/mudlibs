
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
