
## WASM 修复摘要（迁移自 meta.json 的 group_note）

海洋题材，和 hy2000（079）/hy2002（080）/hy5 是不同的代码库——master 哈希和任何现有档案都不匹配，没有确认的血统关系；完成了一次中断的转档（残留的 static 关键字，大写的 .C 档案），移除了一处重复的 create() 文字型 ftpd.lpc include（§7.40），并给 master.lpc 的 creator_file/domain_file/author_file() 加上了防止编译期递归加载的保护（find_object(SIMUL_EFUN_OB) 判断），否则会让整个开机流程崩溃。完整 WASM 修复：修好了 is_chinese() 码点判断 bug、check_legal_name() 长度界限，给 band.lpc 加了本地回环放行，修复了 adm/daemons/securityd.lpc 里一个真正的笔误（这是和真正的安全精灵 adm/daemons/securd.lpc 无关的死代码副本——SECURITY_D 宏实际指向的是 securd.lpc）。在 adm/daemons/logind.lpc 里发现并修复了两个更深的 bug：（1）create() 没有设置这个精灵的 euid，之后 howmany_user()/make_body() 里的 seteuid(getuid()) 呼叫又把它重置回空，因为这个精灵的真实 uid 本来就解析不出来——已把全部三处呼叫点都改成显式的 seteuid(ROOT_UID)；（2）howmany_visitor()/howmany_card() 在各自的计数档案（/log/mud/MUDVISITOR、GIFTCARD）还不存在时会通过 sscanf(0,...) 崩溃——这是一个真实的、任何全新开局都会撞上的 bug（libs/*/work/**/log 是被 gitignore 掉的，不只是 WASM 沙箱的 artifact），已改成 read_file() 返回假值时直接回传 0。另外修复了 adm/daemons/securd.lpc 的 get_status() 里一个防重入编译崩溃：member_array(euid, wiz_levels) 在这个物件自己的变量初始化还没跑完时被呼叫就会崩溃（wiz_levels 声明在 wiz_status 之后，所以 create() 的 restore()->valid_read() 链条中的一次重入呼叫会看到它仍未赋值）——已用 arrayp(wiz_levels) 加上防御。管理员账号直接播种进了 adm/daemons/securd.o 存档文件自身的 wiz_status 映射（不是 /adm/etc/wizlist，这条血统真正的安全精灵从不读取它）——用二进制模式编辑，因为这条血统把映射键里的"/"编码成字面的 CR（0x0D）字节，Python 默认的文本模式换行符转换会悄悄把它弄坏。注册流程到进入游戏世界，对普通玩家和 fluffos/admin 账号都完整验证过（管理员专属的进场提示确认触发）；登录后的 look/score/quit 回显偶尔会和异步的进场横幅 call_out 在脚本化 WASM 测试里抢跑（和 nt6/nt6nitan6win 已记录过的同一类无害测试节奏 artifact），不是 mudlib 的 bug。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 110 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（§10.7，2026-08-08）

本次是 `hy` 第一次真正的 §10.7 深度功能测试（此前只做过登记/浅层验
证）。用标准管理员账号 `fluffos`（正常注册流程创建，`securd.o` 的
`wiz_status` 已确认播种过 `"fluffos":"(admin)"`，密码 `Mud@2026` 直
接可用，无需改动）和一个新建的非巫师测试账号 `testerxyz`（浮浮）实
际走通了注册→新手引导→平安街区探索→扬州武馆（触发 F_SKILL 首次编
译）→中央广场战斗→死亡→鬼门关五段对话→复活送回武庙的完整流程，另
外验证了留言板 `look board`/`post`。

先说明背景更正：虽然 `hy` 和 `hy2000`/`hy2002` 共享"海洋"命名，但本
档案自己 WASM 阶段的 NOTES 已经确认三者 master 哈希互不相同、没有
确认的血统关系——这次深度测试独立验证到同一类 `securd.lpc`/
`feature/skill.lpc` bug，但代码本身并非同一份拷贝（下面每一条都单
独确认过 `hy` 自己的实际代码形状，不是照抄 hy2000/hy2002 的修法）。

### §8.9 食物/饮水年龄检查错对象——适用，已修复（但影响被另一处默认值掩盖）

`adm/daemons/logind.lpc` 的 `enter_world()`：
`if (!user->query("food") && !user->query("water") && ob->query("age") == 14)`
——`ob` 是登录对象，`age` 属性从未在它身上被设置过，这个判断永远为
假。已改为 `user->query("age") == 14`。**注意**：本档案的
`init_new_player()`（在注册最后一步、`enter_world()` 之前呼叫）会
提前把 `food`/`water` 设成 `(str+10)*10` 这个非零默认值，所以修复
前用 `score` 实测并没有看到食物/饮水栏归零——这个 bug 目前是"隐
性"的。但按 AGENTS.md §8.9 已有的教训（这个模式在 `jhfy2` 上也遇到
过一次），一个条件被别处的默认值意外掩盖不代表底层的"读错对象"是
正确的，未来任何人动到 `init_new_player()` 那行默认值就会让这个
bug 突然显形——照标准修法修正。

### §7.86 留言板 post 崩溃——不适用，已在更早一次跨库扫描中修复干净

全档案唯一匹配"`inherit BULLETIN_BOARD` 又多余 `replace_program()`"
形状的文件是 `clone/board/huashan_b.old`——文件名是 `.old` 后缀，是
一份历史备份，驱动器不会加载它（真正生效的 `huashan_b.lpc` 已经是
干净的，只有 `inherit`，没有多余的 `replace_program()`）。`git log`
确认这份档案在更早的一次 §7.86 跨库扫描提交（`529649b16c9`）里已经
处理过。本次用管理员账号实测 `客店留言板`：`look board` 正常列出
41 条历史留言，`post <标题>` 正常打开内建列编辑器，输入正文后 `.`
结束、正常存盘，`look board` 能看到新留言——全链路确认正常。

### §7.5 自定义 ACL 未放行编译期/存在性探测——适用，两个变体，其中一个是本次最严重的发现

`adm/daemons/securd.lpc` 是真正生效的安全精灵（`SECURITY_D` 宏指向
它，`securityd.lpc` 是未被引用的死代码副本，和 README 已有记录一
致）。它的 `valid_read()` 完全没有为 `load_object`/
`recompile_object`/`include`/`file_size` 这类"纯编译期/存在性探测"
用途放行，对没有 euid 的调用者一律 `if (!euid) return 0;` 拒绝。

- **变体一（`file_size`，和 hy2000/hy2002 相同的形状）**：
  `feature/skill.lpc` 的 `set_skill()` 用 `file_size(...) < 0` 探测
  技能档案是否存在，NPC 首次引用某个还没被 `load_object()` 过的技
  能时会被误判"不存在"而中断 `create()`。走到"扬州武馆"触发
  `d/city/npc/chen.lpc`（`陈有德`，`create()` 里连续 14 次
  `set_skill()`，全部是本局第一次被引用的技能）后，`debug.log` 全
  程没有任何 `F_SKILL` 报错，确认此前已经放行 `file_size` 生效（该
  放行本身也是本次一并加上的，见下）。
- **变体二（`stat`，此前从未被记录过，本次新增 AGENTS.md §7.5 追
  加段落）**：驱动器的 `get_dir()` 效率函式底层实际是用
  `func=="stat"` 走 ACL 检查（读了 fluffos 驱动源码
  `packages/core/file.cc` 确认，不是猜测）——而 `securd.lpc` 原本
  完全没有放行这个 func。`adm/daemons/commandd.lpc`（指令表精灵）
  自己 `create()` 里从来没有 `seteuid()` 过，它的 `rehash()` 每次
  呼叫 `get_dir()` 列出 `/cmds/std/` 等目录时都会被这条 ACL 拒绝，
  返回结果被当成空目录，`search[dir]` 永远建不起来——**表现为每个
  刚注册的新角色、每一条指令（包括 `look`、`score`）全部回应驱动器
  的通用失败讯息"什麼？"，而且 debug.log 没有任何报错信号**。用
  tmux 和 mudclient.py 两种客户端各自独立复现过（排除了 telnet 本
  地客户端的 CJK 转码假象）。已把 `stat` 和
  `load_object`/`recompile_object`/`include`/`file_size` 一起加入
  `valid_read()` 的放行名单。修复后重启驱动，同一账号
  `look`/`score`/`kill`/`post` 全部正常响应。

### 新发现且此前未被记录的 bug 类别：daemon `create()` 忘记 `seteuid()`，导致自己读取配置档案被同一个自定义 ACL 拒绝（已新增 AGENTS.md §7.98）

驱动启动阶段（早于任何玩家连线）`debug.log` 就报出两个崩溃：

```
执行时段错误：*Bad argument 1 to explode()
Expected: string Got: 0.
程式：/adm/daemons/questd.lpc 第 698 行
呼叫来自：/adm/daemons/questd.lpc 的 create() 第 39 行
呼叫来自：/adm/daemons/questd.lpc 的 read_table() 第 698 行
```

以及 `adm/daemons/natured.lpc` 的 `create()` → `read_table()` →
`explode(read_file(file), "\n")` 一模一样的形状。乍看很像本项目已
经记录过的"档案缺失"类 bug（§7.9/§7.54：`read_file()` 对不存在的
档案返回 `0`，未加防御的 `explode()`/`sscanf()` 直接崩溃）——但
`ls -la` 确认 `/quest/dynamic_quest`（17KB）和
`/adm/etc/nature/day_phase`（1.5KB）两个档案都**确实存在**于硬盘
上。真正原因是：`read_file()` 本身也要经过 `securd.lpc` 的
`valid_read()`（func 是 `"read_file"`），而 `questd.lpc`/
`natured.lpc` 这两份档案自己从来没有呼叫过 `seteuid()`——preload
阶段 `create()` 执行时这两个精灵自己的 euid 是空的，被同一条
`if (!euid) return 0;` 拒绝，`read_file()` 因此返回 `0`，崩溃发生
在下游的 `explode()` 而不是权限判断本身。逐一 grep 了
`adm/daemons/*.lpc`（36 份档案）里同时有 `read_file(`/`read_table(`
调用、且全档案没有任何 `seteuid` 呼叫的文件，确认全库只有这两份档
案命中，不是更大范围的问题。修法是仿照本档案 `logind.lpc` 自己已
经有的写法（README 已记录的三处 `seteuid(ROOT_UID)`），在两个
`create()` 开头各加一行 `seteuid(ROOT_UID);`。修复后重启，两个崩溃
都消失，`quests`/`day_phase` 两张表正常载入非空内容（`day_phase`
如果继续空着，下游 `outdoor_room_description()` 等函数会对
`day_phase[current_day_phase]` 做 `sizeof()-1`/取模，存在这一项已
被 AGENTS.md 记录过的除零/越界连锁风险，虽然本次没有专门去复现这
一层）。

### 附带修复：`cmds/usr/uptime.lpc` 的"上次当机原因"崩溃

`main(int i)` 被以整数参数直接呼叫时（正常玩家输入 `uptime` 不带参
数不会触发，但 `call` 指令可以强制传入 `1`），
`write(read_file("/log/nosave/LASTCRASH"))` 在这份档案不存在的全新
安装上会崩溃：`*Bad argument 1 to receive()`（`/log/nosave/` 目录
本身都不存在）。用管理员账号 `call /cmds/usr/uptime->main(1)` 复现
后确认。全库没有找到任何自动呼叫 `uptime->main(1)` 的代码路径（不
像 hy2000/hy2002 的等价代码那样被 LOGIN_D 自动触发），所以这条路径
目前不会在正常游玩中触发，但仍按 §7.9 的标准写法加了 `stringp()`
防御，避免巫师用 `call` 或未来的调用方式意外触发。

### 战斗与死亡/复活

在"中央广场"对"流氓头"（帮派头目 NPC）发起攻击，管理员账号和
`testerxyz` 各打了一场，都在十几回合内落败——新手角色对这只 NPC 明
显偏难，符合"江湖险恶"设计，不作为 bug 处理（战斗数值属于游戏平
衡，不在 §10.7 范围内）。

死亡后两个账号的表现符合预期差异：管理员账号 `fluffos` 死亡后卡在
"鬼门关"，`白无常`（`d/death/npc/wgargoyle.lpc`）的 `init()` 本来
就用 `wizardp(previous_object())` 排除巫师角色，这是有意设计（巫师
有别的手段自救），不是 bug，和 hy2000/hy2002 已经记录过的同一条教
训一致。另开非巫师账号 `testerxyz` 重新走一遍：`白无常` 的五段对
话（"你叫什么名字" → ... → "阳寿未尽" → 阴冷浓雾包围你）全部按 5
秒一段的 `call_out` 节奏自动播放完毕（不需要玩家输入任何东西——这
个对话是纯计时器驱动的，之前误以为要靠玩家回答"你叫什么名字"是走
错了方向），最终 `reincarnate()` 正确执行，角色被送到武庙——复活系
统本身完全正常，没有套用 AGENTS.md §7.68 那条已撤销的"重试"补丁
（`bgargoyle.lpc`/`wgargoyle.lpc` 的 `if (!ob || !present(ob)) return;`
单次判定原样保留，没有改动）。

### 其它检查、确认不适用的类别

- §7.90（`maximum evaluation cost` 过低触发移动 eval-cost 中断）：
  `config.fluffos` 里已经是 `700000`，深度测试全程移动/战斗未观察
  到任何 eval-cost 中断报错，不适用。
- §8.3a（`private nomask command_hook`）：`feature/command.lpc` 第
  36 行已经是干净的 `nomask int command_hook(...)`（第 35 行留着一
  条 `private` 版本的历史注释，不是活代码），不适用。
- §8.3b（`commandd.lpc` `rehash()` 里残留 `.c` 后缀的 sscanf）：实
  测是 `sscanf(cmds[i], "%s.lpc", cmds[i])`，早就是 `.lpc` 后缀，不
  适用。
- printf 调试残留：全库 `printf("%O` 命中都是巫师用的
  `mem`/`where`/`ilist`/`call` 等指令的正常功能代码，或者
  `logind.lpc` 里两处早就被前任巫师注释掉的 `//printf(...)`，没有
  发现活的调试泄漏。
- §1.5（管理员账号是否被真实旧账号占用）：README 已记录的
  `fluffos`/`Mud@2026` 组合本次验证依然有效，`securd.o` 的
  `wiz_status` 映射本来就已经包含 `"fluffos":"(admin)"`，无需重新
  播种。
- 昼夜可见度：入夜后裸方向词（`north` 等）会提示"天色太黑了，看不
  清明显的出路"、失效，需要改用 `go <方向>`——这是有意的游戏内容设
  计，不是 bug，深度测试过程中用 `go` 系列指令正常绕过。
- 本次没有测试到：拜师/门派系统、商店/交易、邮箱（虽然注册时确认
  收到了新手礼包信）、task 系统。留给未来某次针对 `hy` 的后续 pass。

## 深度功能测试（2026-08-13，round two，新驱动重测）

Re-tested against the freshly-rebuilt `build-debug/src/driver`（post
全库 `quest_times`/`win_times` `%`-operator 修复 + Warning/warning
驱动文本回退）。

### 更正上一轮（2026-08-08）的一处误判

上一轮"没有发现的 bug"清单里写着"§1.5（管理员账号是否被真实旧账号
占用）：… `securd.o` 的 `wiz_status` 映射本来就已经包含
`"fluffos":"(admin)"`，无需重新播种"——**这个结论是错的**，是仅凭检
查存档文件内容得出、未做真实登录验证的判断失误。本轮读代码发现
`adm/daemons/securd.lpc` 的 `wiz_status` 声明为 `nosave mapping`
（第 6 行）——永远不会被存档持久化，无论 `securd.o` 文件里实际写了
什么都无关紧要，每次开机都会被 `restore_list()` 里的硬编码赋值重置
成只有一个 `lywin`。也就是说，即使 `fluffos` 角色本身早就注册并提
交了存档，这个账号登录后**从未真正拿到过 `(admin)` 权限**——这个误
判很可能正是当年检查存档文件内容（看到里面确实写着
`wiz_status:{"fluffos":"(admin)"}` 之类的内容）却没有意识到这个字
段是 `nosave`、从不会被真正 `restore()` 读取所致。这正是 AGENTS.md
§1.5 归档的"wiz_status 声明为 nosave"这一类 bug 的又一实例，和本轮
`fqyy2` 独立发现的同一类形状完全一致。

### 发现并修复的 PROGRAMMING bug

1. **`log_error()`（`adm/single/master.lpc`）完全没有严重度检查
   （AGENTS.md §7.34-class，与本轮 `wdxtym`/`ffxymud`/`fy2mg`/`fys`/
   `hc` 同一原始形状）**：`if (this_player(1)) efun::write(...)`——
   不区分巫师/玩家，也不区分警告/错误。修复：加上
   `strsrch(message, "arning:") == -1` 判断。
2. **`log_file()`（`adm/simul_efun/file.lpc`）完全没有 `assure_file()`
   保护（AGENTS.md §7.11-class 的又一确认实例）**：注册/登录本身只
   写 `log_file("USAGE", ...)`（无子目录，本来就存在），不受影响，
   但 `nosave/SUICIDE` 等管理指令路径会在首次使用时未捕获抛出。已
   补上 `assure_file(LOG_DIR + file);`（含前向声明）。
3. **管理员账号从未真正拿到 admin 权限（见上方"更正"一节，AGENTS.md
   §1.5 的"wiz_status 声明为 nosave"形状，与本轮 `fqyy2` 同一模
   式）**：已在 `lywin` 那行旁边并列加一行
   `set("wiz_status/fluffos", "(admin)");`。README 已同步更正此前
   错误的授权机制描述。

### Proactive checks（无需改动）

- `win_times` 修复确认存在且正确：`d/city2/npc/refereew.lpc:177`。
- 未发现 `message()` simul_efun 包装函数——不适用
  message()-missing-varargs 这一类 bug。

### 实测过程

登录时有一个 GB/Big5 选码提示（选 `g`），用已提交的 `fluffos`/
`Mud@2026` 账号登录，`score` 确认显示"目前权限：(admin)"（修复前
按代码分析必然显示较低权限，未做修复前的真实登录复现，因为已经确
信 bug 形状与 `fqyy2` 完全一致，直接应用了已验证过的修法），
`update /adm/simul_efun/file`（就是本轮改过的文件）确认可正常重新
编译。`adm/log/debug.log` 时间戳全程未变化（`Jul 30`，早于本次会
话），确认无新增未捕获运行期错误。登录本身产生的存档时间戳类微小
diff（`data/{login,user}/f/fluffos.o` 的 `last_on` 字段）已用
`git checkout` 撤销，不提交。驱动最终按精确 PID kill，`ps -p` 确认
已退出。

（本档案 `work/` 目录下还嵌着一份完整的姊妹档案 `海洋2002/hy3/` 副
本——不是这次任务的目标，未触碰，留给 `hy3` 自己的 pass。）

## §7.100 跨库扫描修复（ROOM 冗余 replace_program() 关闭包炸弹，2026-08-19）

同一形状覆盖到几乎所有房间基类（机制详见 AGENTS.md §7.100）。本库属
于该扫描已知最大规模的 10 个库之一。二进制模式脚本机械删除了 7847
处独立、未注释的 replace_program(ROOM); 整行；另有 2 处不规则形状需
要单独手工处理：`d/happy/workroom.lpc` 的调用行带一个空的尾随注释
标记（`replace_program(ROOM);  //`，没有实际注释文字，判定为噪音而
非"其它代码"，一并删除）；造房工具 `clone/misc/roommaker.lpc`/
`adm/roommaker.lpc` 代码生成模板里同样内嵌了这个形状（4 处）。**这
次连同上面这条记录提到的内嵌 `海洋2002/hy3/` 完整副本一起处理了**
——虽然那份副本本身是死代码（不在任何真实加载路径上，§7.112 记录已
确认），但同一套机械删除对它无害，为了不留一个"看起来没修但其实是
故意跳过"的死角，本次连副本一起修了（`d/happy/workroom.lpc`/两份
`roommaker.lpc` 在副本里各有一份同形状问题，同步清理）。删除总计
7857 行，与本次扫描 FINDINGS.md 记录的 `hy` 存活命中数完全一致。

验证：干净启动一次真实调试驱动，端口 40182 正常监听，
`work/log/debug.log` 全程无新增内容。用已播种的 `fluffos`/
`Mud@2026` 管理员账号连线，`look`/`who` 正常（`/d/welcome/welcome`
本身出口较少，多数方向回应"这个方向没有出路"，属于房间本身设计，
非本次修复引入的问题）。测试产生的 `data/{login,user}/f/fluffos.o`
存档时间戳 diff 已 `git checkout` 撤销，不提交。驱动按精确 PID
kill。
