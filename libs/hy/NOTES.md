
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

### ```§7.112``` residual-gap closure (2026-08-20)

Corpus re-scan (`grep -rl 'call_out("death_stage"' ... | filter for missing guard`) found unguarded `init()`-scheduled `death_stage()` call_out chain(s) in `海洋2002/hy3/d/death/npc/bgargoyle.lpc`, `海洋2002/hy3/d/death/npc/wgargoyle.lpc` that the original two-wave sweep (see AGENTS.md §7.112) missed -- same reconnect-triggered duplicate-chain bug, different filename/lineage. Added the standard `query_temp("death_stage_active")`/`set_temp`/`delete_temp` re-entry guard, adapted per file's own exit points. Compile-verified via `lpcc --batch`.

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
都写明没测商店和拜师。这是海洋II/ES2 金庸血统，端口 40182。第一输入
是 BIG5 选单，发 `g`，再英文 id。密码 `Mud@2026`。登录对象没有
`wizpwd`。`(player)` 退出后 20 秒内不能再 login；本轮管理员不受这条
限制。`work/` 下嵌着一份 `海洋2002/hy3/` 副本，本轮没动它。

### 实测过程

管理员 `fluffos` / `Mud@2026`（权限 `(admin)`，落地 `/d/welcome/welcome`）。
身上没钱，`clone /clone/money/gold` 可用。

`goto /d/city/zuixianlou`（醉仙楼，店小二 `d/city/npc/xiaoer2.lpc`，
`F_DEALER`）。`list` 烤鸡腿八十文铜板 / 牛皮酒袋一两白银 / 包子五十文
铜板。`buy jitui` 成功（「你从店小二那里买下了一根烤鸡腿」）。一两黄
金换成九十九两白银 + 二十文铜钱。`feature/dealer.lpc` 里丐帮拒买那段
是注释掉的，买完再拜仍更稳妥。

`goto /d/gaibang/inhole`，左全源码是 `kungfu/class/gaibang/zuo-qu.lpc`
（文件名少一个 n），`apprentice zuo` 一次成功：恭喜成为丐帮第二十代
弟子。`score` 称谓「丐帮第二十代弟子」、师傅左全。`cmds/usr/save.lpc`
真正写盘。save 后杀驱动冷启动再登录，称谓/师傅/九十九两白银/二十文铜
钱都在。烤鸡腿未进 autoload。左全只收男性。

### 发现并修复的 PROGRAMMING bug

1. **华山收徒计数拼写**（与 `jhfy2`/`wmkj`/`hy2002` 同形，静态对照
   修，本轮拜师走的是左全不是华山）：
   `kungfu/class/huashan/{yue-buqun,yue-wife,feng-buping}.lpc`、
   `kungfu/class/yue-buqun.lpc`、`d/biwu/feng-buping.lpc` 的
   `recruit_apprentice()` 写 `add("apprentice_availavble", -1)`，永远
   减不到 `set("apprentice_available", 3)` 那个字段。五处都改成
   `apprentice_available`。嵌套的 `海洋2002/hy3/` 同形未改，留给
   `hy3` 自己的 pass。

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 10 line(s) in 4 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— 任务表里的 `.c` 路径与任务守护进程的防护

`scripts/lpc_dynamic_rows.py`：`quest/dynamic_location` 里 833 行写的是原档案的 `.c` 路径。转档时文件已改名 `.lpc`，而显式后缀按原样解析，`load_object("/d/x.c")`、`new("/d/obj/quest/x.c")` 返回 0 且不报错（KB 03 §4.2，KB 06 §7.220），所以 `adm/daemons/questd.lpc`、`cmds/std/questd.lpc` 读到的每一行都加载不出来：随机任务和任务物品从未生成，在 `create()` 里直接对结果调用 `tar->set()` 的版本还会崩溃，连带加载它的 cron 守护进程和 `give` 的任务钩子。这些行已改为 `.lpc`。
`scripts/lpc_dynamic_quest_guard.py`：4 处 `spread_quest()` 调用（`init_dynamic_quest()` 的循环里）包进 `catch()`，缺失的任务物品或编译不过的房间只跳过那一个任务，守护进程照常加载、其余任务照常生成；`cmds/std/look.lpc` 夜间检查的 `!present("fire", this_player())` 前加 `objectp(this_player()) &&`（房间 `reset()` 销毁物品时 `/feature/move.lpc` 的 `remove()` 会调用 `look_room()`，此时没有 this_player()，`present(…, 0)` 报 `Bad argument 2 to present()`）。
验证：`adm/daemons/questd.lpc`、`cmds/std/questd.lpc`和 cron 守护进程在新进程里加载（HEAD 一次，工作树三次，选房是随机的）：HEAD 通过 2 个，工作树三次分别通过 2、2、2 个（共 3 个），无回退；`cmds/std/questd.lpc` 在 HEAD 与工作树都加载失败，另有原因，与本次无关。
验证：改动过的 `adm/daemons/questd.lpc`、`cmds/std/look.lpc`、`cmds/std/questd.lpc`、`海洋2002/hy3/adm/daemons/questd.lpc`、`海洋2002/hy3/cmds/std/look.lpc`、`海洋2002/hy3/cmds/std/questd.lpc` 在新进程里加载，HEAD 通过 3 个、工作树通过 3 个（共 6 个），无回退。

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `inherit/room/room.lpc`：`make_inventory()` 用 `catch()` 包住 `new(file)`，做不出来就返回 0；`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-06）— 所有对象的 uid 都是空字符串

与 hy5 相同（KB 06 §7.235）：`config.fluffos` 的 simul_efun 写成 `/adm/obj/simul_efun`，主控 `creator_file()` 的保护查的是 `globals.h` 里的 `/adm/single/simul_efun`（原始配置也是这个），从未载入，于是每个对象的 uid/euid 都是 `""`，`Root` 权限的判断全部失败（断线玩家无法被 `quitgame` 清除，守护进程大多写不了文件）。配置改回 `/adm/single/simul_efun` 后，`/cmds/usr/quit` 的 uid 为 `Root`；临时副本新进程登录、`score`、`save`、`quit` 无错误。


## 深度功能测试（§10.7，2026-10-06）— 白驼山掌门欧阳锋编译不过

`d/baituo/ouyangfeng.lpc` 有两处笔误，整个 NPC 从未编译成功：`greeting()` 里 `write("你是谁？我要杀了你！哈￣哈￣哈￣") break;` 缺分号，`inquiry_map()` 里 `object me = this - player();`（应为 `this_player()`）。白驼山派的掌门因此不存在，拜师、问路（`inquiry_map`）都无从谈起。两处改正后，新进程里 HEAD 加载失败、工作树加载成功。同一文件在 14 个 xkx 系的库里一字不差。

## 深度功能测试（§10.7，2026-10-07）— 空的 `if (current_water == 0) {}`

3 个房间的 `valid_leave()` 里有一行什么也不做的 `if (current_water == 0) {}`（编译警告 `Expression has no side effects`），删去，行为不变：`d/xingxiu/nanjiang2.lpc`、`d/xingxiu/nanjiang3.lpc`、`d/xingxiu/shanjiao.lpc`。

## 深度功能测试（§10.7，2026-10-07）— 编译警告整理

`scripts/lpc_warnings.py hy --fix` 加 `scripts/lpc_fix_no_effect.py --apply`，共改动 665 个 `.lpc` 和若干 `.h`。HEAD 与工作树分别加载（新进程）：648 -> 648 通过，无回退；改过的头文件的 343 个包含者 334 -> 334 通过。剩下的告警都在 `海洋2002/hy3/` 下——库里夹带的另一份 hy3 源码，不加载，未动。

启动时警告 65 -> 0；新进程登录（编码选择、新人物确认）正常。
（警告整理也改了 `海洋2002/` 下 1038 个文件的无用局部变量等——那份夹带的源码不加载，这些改动没有进 HEAD/工作树对比加载。）

- 2026-10-11：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 42 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 5 个，只在 #if 分支用的声明移进分支 0 个文件；改动 33 个文件，HEAD 与工作树各载入一次无回退（33 objects; HEAD PASS 30, tree PASS 30; regress 0; newly loading 0），这些文件的警告 48 -> 1。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查（批 4）

- `liangyi-jian.bak.lpc`：`int i; level;` 去掉无用的 `level;`。
- `d/xingxiu/nanjiang2/3.lpc`、`shanjiao.lpc`：删去空的 `if (current_water == 0) {}`（行为不变）。
- 改动的对象 HEAD 与工作区都能载入，无回退。

## 编译警告收尾（2026-10-13）

`scripts/toolkit_fix.sh` 一轮去掉 16 处多余继承，其余手工，能编译的文件警告清零；改动的对象在 HEAD 与工作树各载入一次（27 objects; HEAD PASS 19, tree PASS 19; regress 0; newly loading 0）。

- `adm/roommaker.lpc` 与 `海洋2002/hy3/adm/roommaker.lpc` 把 `special_props` 声明两次，代码用的是后一份（多 `file_name`），删去前一份（同 wqfy）。
- 四间书库（`d/city/library`、`d/city2/library` 及 `海洋2002/hy3/` 下两间）自己的 `STORY_DIR` 覆盖 `globals.h` 的同名宏，先 `#undef`。
- `海洋2002/hy3/d/pk/sjsz/obj/control.lpc` 在开头把 `auto_check()` 原型写成 `int`，中间又写了两条 `varargs void auto_check(...)`，定义是 `int auto_check()`；删去两条 `void` 原型。
- `海洋2002/hy3/quest/guojob/guo.lpc` 同时包含 `zzzjob.lpc`、`teamjob.lpc`，两者都声明 `names`：`teamjob.lpc` 的改名 `team_names`（同 yxjh）；天书任务 `quest/shenshu/npc/man.lpc`、`testman.lpc` 的 `kill_ob()` 改 `void`（同 jh2006）。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。12 个文件 12 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）；`x op= 浮点` 先把浮点转成整数再运算（系数小于 1 时 x 直接变 0），改为 `x = to_int(x op ...)`：`/kungfu/skill/fengyun-shou/foguang.lpc`（`damage *=`）、`/kungfu/skill/taiji-quan/zhenup.lpc`（`damage *=`）、`/海洋2002/hy3/kungfu/skill/fengyun-shou/foguang.lpc`（`damage *=`）、`/海洋2002/hy3/kungfu/skill/taiji-quan/zhenup.lpc`（`damage *=`）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。
- 2026-10-14：1 个存档文件（其他 1 个；`海洋2002/hy3/adm/daemons/securd.o`）还是原档案的 GBK 编码，没有转成 UTF-8，`restore_object()` 报 `Invalid utf8 string` 后对象以空数据启动（表情守护进程没有表情、留言板没有帖子、玩家无法载入）。`scripts/lpc_save_encoding.py` 逐个按 GB18030 解码，结果按存档格式解析通过才写回（KB 03 §4）。

## 负数伤害当作消耗（2026-10-15，KB 06 §7.241）

`receive_damage("neili", -52)`、`receive_damage("qi", -12)` 之类把 `add()` 的负数写进了 `receive_damage()`：本库 `feature/damage.lpc` 对负数伤害报错（或归零），练功/运功时报 `F_DAMAGE: 伤害值为负值` 或消耗失效。已改为正数伤害，内力/精力类改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py`）：`/海洋2002/hy3/kungfu/skill/shaolin-tantui`。

## 内力/精力当作伤害种类（2026-10-15，KB 06 §7.241 第二类）

本库 `feature/damage.lpc` 的 `receive_damage()` 不接受 `jingli`/`neili`/`force` 等种类，`me->receive_damage("jingli", 30)` 之类在练功、绝招、吸取时报 `F_DAMAGE: 伤害种类错误`。29 处改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py` 第二步）。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。4 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。


## 东方故事/西游记体系的技能文件（2026-10-15，KB 06 §7.241 第三类）

这些 `kungfu/skill` 文件来自 gin/kee/sen/force 体系，本库人物只有 jing/qi/neili：`receive_damage("kee", 30)` 报 `伤害种类错误`，`query("force")` 永远为 0，技能学不了也练不了。按 kee→qi、gin/sen→jing、force→neili、max_force→max_neili、force_factor→jiali 改了属性名（`scripts/lpc_port_es_props.py`），共 6 个文件。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

另有 3 个文件（绝招、状态、物品、NPC 等，不限于 kungfu/skill）来自 gin/kee/sen/force 体系，同样按 kee→qi、gin/sen→jing、force→neili 改名（`scripts/lpc_port_es_props.py --any-file`）。


## family 映射（补）（2026-10-15）

`mapping fam = (mapping)me->query("family");`（带类型转换的写法）同样直接取下标，4 处补上 `if (!mapp(fam)) fam = ([ ]);`。

## `message_vision(msg, environment(me), me)`（2026-10-15，KB 06 §7.242）

把房间当成了动作者：`message_vision()` 取房间的 `name()` 得 0，`replace_string(msg, "$N", 0)` 报错。在状态（中毒）里，这个错误发生在 `apply_condition(name, duration - 1)` 之前，状态永不结束，心跳里后面的恢复也每次被跳过。改为 `message_vision(msg, me)`：`/海洋2002/hy3/kungfu/condition/sanpoison`。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。18 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。

## 妙手回春的银针检查（2026-10-15）

`miaoshouhuichun` 的 `valid_learn()` 用了未赋值的 `object ob`（`ob->query_temp("weapon")` 报错），还把兵器对象和字符串 "银针" 比较。改为 `ob = me->query_temp("weapon")`，再用 `id("yin zhen")`/`id("yinzhen")` 判断是否银针。

## 空手使用兵器绝招（2026-10-15，KB 06 §7.246）

`perform` 指令允许直接点名招式（如 `perform stick.ban`），这些绝招读了 `me->query_temp("weapon")` 却从不检查，空手时 `weapon->name()` 报错（有的已先扣了内力）。在赋值后补 `if (!objectp(weapon)) return notify_fail("你必须手持兵器才能使用这一招。\n");`（`scripts/lpc_fix_perform_weapon.py`）：`duanyun-fu/hongtianza`、`murong-jianfa/kuangjian`、`tianyu-qijian/kuangwu`、`wuyue-blade/jiao`。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`douzhuan-xignyi`→`douzhuan-xingyi`（`/d/mr/obj/shu1`、`/海洋2002/hy3/d/mr/obj/shu1`）；`jinwu-dao`→`jinwu-daofa`（`jinwu-daofa`、`/海洋2002/hy3/kungfu/skill/jinwu-daofa`）；`quanzhen-jianfa`→`quanzhen-jian`（`quanzhen-jian/ding`、`/海洋2002/hy3/kungfu/skill/quanzhen-jian/ding`）；`yinyun_ziqi`→`yinyun-ziqi`（`yinyun-ziqi/cure`、`/海洋2002/hy3/kungfu/skill/yinyun-ziqi/cure`）；`buddhsim`→`buddhism`（`/海洋2002/hy3/kungfu/skill/qianye-shou`）。

## 技能名拼错：技能文件里拼错自己的名字（2026-10-15，KB 06 §7.249）

技能自己的文件（或它的绝招目录）里，`query_skill()` 读的是差一个字母的自己的名字，永远得 0：“基本功夫要高过本技能”之类的限制从不生效，按等级取招、计算伤害的那一项一直是 0。改为本技能的名字（`scripts/lpc_fix_skill_typo.py` 的 self 判据）：`chanyun-tui`→`chuanyun-tui`（`chuanyun-tui/shuangjue`、`/海洋2002/hy3/kungfu/skill/chuanyun-tui/shuangjue`）。

## family 映射内联取下标（2026-10-15，KB 05 §7.30）

`ob->query("family")["master_name"]`、`me->query("family")["family_name"]`（泥潭式为 `query("family", ob)[...]`）直接对门派映射取下标：没有门派的人（新玩家、叛师者、大多数 NPC）在 NPC 的打招呼和问话、绝招的门派判断、房间的 `valid_leave` 里报 `Value being indexed is zero`，而不是得到拒绝。11 处（8 个文件）改为 dbase 路径查询 `query("family/master_name")`：有门派时值相同，没有时得 0；原有的判断照常生效（`scripts/lpc_fix_family_index.py`）。给映射赋值的写法未动。


## 存档读不出来：字符串里的换行、空行（2026-10-15，KB 03 §4.4）

`海洋2002/hy3/clone/gift/npc/bingqipu.o`、`海洋2002/hy3/data/board/yipin_b.o`：字符串里有原样的换行（`save_object()` 存成 `\r`，`restore_object()` 逐行读，原样的换行让字符串收不了尾），或有空行（`Illegal file format`），读档的对象（留言板、NPC、玩家）从空白开始。换行改写成 `\r`、删去空行（`scripts/lpc_save_encoding.py --from-raw`），驱动核对全部能读回（`scripts/lpc_save_restore_check.py`）。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

3 个文件、262 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/d/migong/obj/cloth`、`/d/migong/obj/sword`、`/d/kaifeng/obj/yayifu`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 0 个，改后 141 个（141 个原来载入不了），没有退步；其余 19 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 170 个对象设了本库没有文件的武功（62 个名字，最多的是 `dragon`、`gedoushu`、`bingxue-xinfa`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：29 个里 28 个通过，其余 1 个停在别的错误上（`海洋2002/hy3/clone/guard/baoer`：*No program in object '/海洋2002/hy3/clone/guard/baoer'!）。（`scripts/lpc_guard_set_skill.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 87 处、78 个文件：`kunlun-shnfa`→`kunlun-shenfa`（28 处）、`shaolin-shnfa`→`shaolin-shenfa`（22 处）、`lingbo-weibu`→`lingboweibu`（6 处）、`yunu-xinfa`→`yunv-xinfa`（6 处）、`chang-quan`→`changquan`（6 处）、`tiaji-jian`→`taiji-jian`（4 处）、`yan-fly`→`yanfly`（4 处）、`shenhuo-shengong`→`shenghuo-shengong`（2 处）等共 15 个名字。（`scripts/lpc_fix_skill_names.py`）

## 全局头文件丢了 1 个宏（2026-10-19，KB 04 §6.16）

`/include/globals.h` 里没有定义 `MAILDIR`，用到它们的物件（名单里 2 个）编译时报 `Undefined variable`/`Undefined function`，整个物件载入不了（编译器在第一个未定义的名字上停下，后面的错误和警告都看不到）。同系的库在各自的头文件里都有这几行：照其中和本库共有文件最多的那个库，原样补到 `/include/globals.h` 最后一个 `#define` 之后，宏体里出现的路径在本库里都存在。名单里的物件除了这几个宏之外还有别的错误，暂时仍载入不了。（`scripts/lpc_restore_defines.py`）

## 和包含文件同目录的头文件，改成引号形式（2026-10-19，KB 04 §6.17）

5 个文件用尖括号写 `#include <hedi.h>` 这类头文件（`hunyin.h` 等），头文件其实就放在它们自己的目录里。老驱动对尖括号名字也会先找包含文件所在目录，本驱动只找 include 路径，所以报 `Cannot #include ...`，整个物件载入不了。改成 `#include "hedi.h"`（引号形式相对包含文件解析，预加载、`lpcc` 和运行时编译都一样）。（`scripts/lpc_fix_local_include.py`）

## bite.lpc 被截断（2026-10-19，KB 06 §7.266）

`d/city/bite.lpc`（忘尘居）在 `set("no_clean_up", 0);` 处结束，缺 `setup(); }`，驱动报 `syntax error, unexpected end of file`。同系的 hy2000/hy2002/hy5/haiyang2 带着完整的这个文件，补上 `setup();` 和结尾的 `}`。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 载入不了的零碎文件（2026-10-19，KB 03 §4.7、KB 04 §6.10）

- `d/hangzhou/npc/tangzi.lpc`（和 `海洋2002/hy3/` 里的旧副本）：整个文件只是 UTF-16 的空格（`\x00 \x00 …`，作者把这个物件清空了），驱动报 `Illegal embedded NUL byte (0x00) in source`；旧驱动编出一个空程序。改成一个换行，行为和原来一样（空程序），不从 xkx100 抄回同名 NPC。

逐个载入与 HEAD 对比，没有退步。

## 玩家打造兵器模板没有打造者时（2026-10-19，KB 06 §7.275）

`/d/npc/m_weapon/weapon/m_blade.lpc`、`/d/npc/m_weapon/weapon/m_club.lpc`、`/d/npc/m_weapon/weapon/m_hammer.lpc`、`/d/npc/m_weapon/weapon/m_staff.lpc`、`/d/npc/m_weapon/weapon/m_sword.lpc`、`/d/npc/m_weapon/weapon/m_whip.lpc` 等（共 12 个）的 `create()` 开头 `me = this_player();` 之后无条件读 `me->query("weapon/name")` 等打造数据。房间刷新时没有人在场（`me` 为 0），或者 NPC 在别的 NPC 的命令环境里 `carry_object()` 这个模板（NPC 的 `weapon` 属性是文件名字符串），旧驱动里读出来是 0 或字符串，`switch` 照样落到 default；新驱动报 `Bad argument 1 to EFUN call_other()` / `Bad argument 1 to switch`，NPC 和它所在的房间载入不了（`--walk` 普查里一个玩家走进房间就触发）。在 `//读入数据` 之后加 `if (!me || !mapp(me->query("weapon"))) { setup(); return; }`：没有打造者就留一个没有名字的空模板，玩家打造的流程不变。

## 标准整理轮，第二轮（2026-10-19，`scripts/toolkit_fix.sh`）

本库在新驱动下重扫，机械修复：22 个未使用的局部变量。修后与 HEAD 逐个物件对比载入，没有退步。

## 手工收尾（2026-10-19，KB 04 §6.10）

- `海洋2002/hy3/d/kaifeng/`（本库里又收了一份开封擂台）：`ground1/2/3.lpc` 继承 `ground0.lpc`，又各自 include `ground.h`，三张表（`modes`、`mode_hints`、`families`）在每个 inherit 之后又声明一遍（`Redeclaration of global variable`）；照 xiyouji 系各库 `d/kaifeng/ground.h` 的办法，派生程序在 include 前 `#define GROUND_TABLES_INHERITED`，头文件用 `#ifndef` 把三张表包起来。
- 同目录的 `ground2.lpc`、`ground3.lpc`、`guanli.h` 写的是 `#include <ground.h>`，尖括号在 include 路径里找不到同目录的头文件（`Cannot #include ground.h`），这两个物件一直载入不了；改成 `#include "ground.h"`，现在载入得了，同时露出里面 21 个未使用的局部变量，留给下一轮标准整理。

载入 14 个相关物件（含 `d/*/marry/chen.lpc` 一类 include `hunyin.h` 的）：HEAD 通过 12 个，现在通过 14 个，没有退步。

## 补回丢失的标点（2026-10-19，KB 03 §4.6）

转换时丢掉的分号、逗号、引号或文件末尾的 `}`，共 4 个文件，修前 HEAD 载入失败。别的库里同路径的完好副本只比这里少几个标点，按它补回（括号里是那个库）：`/d/baituo/npc/obj/bowl.lpc`（cctx）、`/d/baituo/obj/bowl.lpc`（cctx）、`/d/city2/npc/zhengmen.lpc`（jqxz2008）。文件末尾少了 `}`（最后一个或两个字节丢了），补上：`/海洋2002/hy3/d/city2/npc/zhengmen.lpc`（2 个）。修后与 HEAD 逐个对比载入：这 4 个物件全部载入，没有退步（`scripts/lpc_restore_from_twin.py`、`lpc_fix_eaten_quote.py --comma`、`lpc_fix_eof_braces.py`）。

## 标准整理轮（2026-10-19，`scripts/toolkit_fix.sh`）

本库在新驱动下重扫，机械修复：17 个未使用的局部变量，4 个带初始化的未使用声明。修后与 HEAD 逐个物件对比载入，没有退步。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。改动：`/d/mingjiao/shanmen.lpc`（1 处）、`/海洋2002/hy3/d/changan/ca2.lpc`（1 处）、`/海洋2002/hy3/d/mingjiao/shanmen.lpc`（1 处）。
