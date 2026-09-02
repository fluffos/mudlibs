
## WASM 修复摘要（迁移自 meta.json 的 group_note）

金庸题材 mudlib（金庸群侠传2013_服务器版），jyqxc/jyqxc2 的手足档案（同一架构家族；不是文件级完全相同）。修复了两个 bug，都在 adm/daemons/combatd.lpc：（1）#include </quest/quest.h> 用了尖括号绝对路径写法，这个驱动会把它解析成相对于配置好的 include 目录（/include），而不是 mudlib 根目录——这份代码库里其它所有绝对路径 include 都正确使用带引号的写法（#include "/path.h"），只有这一处用了尖括号，导致"Cannot #include /quest/quest.h"，接着连锁触发"Undefined function quest_finished"，让 combatd.lpc 整个编译失败（"No program in object"），破坏了每个玩家的战绩显示。已改成带引号写法修复。（2）include 路径解决之后，又暴露出 quest.h 顶层的 mapping quest_name = ([...]); 定义抢在了 combatd.lpc 的 inherit F_DBASE; 之前（因为 #include 写在 inherit 之上），这个驱动不允许这样（"Illegal to inherit after defining global variables"）——已把 #include 挪到 inherit 语句之后修复。另外也照搬了 jyqxc/jyqxc2 已知的 feature/name.lpc 里 short()/capitalize(query("id")) 防护修复（同样的旧式二进制存档格式留言板崩溃）。通过 adm/etc/wizlist 把 fluffos/Mud2026Adm 播种为 (admin)（原始档案末尾没有换行符，加了一个以保证两条条目分行）。完整的注册→look→score→quit 流程和管理员流程在排版格式化前后都验证过；格式化工具还原了 3 个损坏的 ASCII 地图档案，和 jyqxc/jyqxc2 同样的模式。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 19 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（§10.7，2026-08-08）

### 血统确认：与 `jyqxc`/`jyqxc2` 是同一架构家族，但不是同一份存档的重复

用 `diff -rq` 逐文件核对 `work/` 目录树：本档案 3942 个文件，
`jyqxc`（3693 个）/`jyqxc2`（3694 个）明显不同；抽查
`adm/daemons/{chard,combatd,logind,updated}.lpc`、
`adm/etc/{motd,welcome,wizlist}`、`config.cfg` 等核心文件均与
`jyqxc` 存在实质差异（不是格式/换行差异，是内容差异），只有
`d/death/npc/{bgargoyle,wgargoyle,newgargoyle}.lpc`、
`d/death/{gateway,road1,road2,road3,inn1,inn2,block}.lpc` 等少数文
件恰好逐字节相同。结论：**这不是"漏网的浏览器重复下载"（不同于
`jyqxc2` 相对 `jyqxc` 的关系），而是同一套架构衍生出的、内容各自
独立的第三份存档快照**（"2013fwq" 命名对应 2013 年的一个服务器端
备份/服务器版本），`meta.json` 的 `duplicate_of: null` 准确，无需
改动。

### 管理员账号：README 记录与实际存档不符，已重新播种（本 session 第 N 次遇到同一类陷阱）

README 此前记录 `fluffos`/`Mud2026Adm`/(admin) 且称"账号本身通过正
常注册流程创建，已在游戏内确认"，但 `work/data/login/f/` 和
`work/data/user/f/` 下都没有 `fluffos.o`——`adm/etc/wizlist` 确实已
有 `fluffos (admin)` 一行，但从未真正走过注册流程。本次用标准
`fluffos`/`Mud@2026` 走了完整正常注册流程（英文 id → y 确认 → 中文
名"沙河生" → 密码×2 → 系统随机天赋展示 → y 接受 → 邮箱 → 性别
m），`目前权限：(admin)` 立即生效，已更新 README 记录正确密码。

### 修复零：§8.9 食物/饮水初始化用错对象 + §7.34 `printf` 调试残留（`logind.lpc`，逐字节复现 `jyqxc`/`jyqxc2` 已知修复前状态）

`adm/daemons/logind.lpc::enter_world()` 携带了和 `jyqxc`/`jyqxc2`
（该 bug 类的第六、第十例，AGENTS.md §8.9）逐字节相同的错误代码：
`if (!user->query("food") && !user->query("water") && ob->query("age")
== 14)` 最后一项读的是登录桩物件 `ob` 而不是刚 `setup()` 过的角色
本体 `user`，永远为假，新角色食物/饮水永远卡在 0。同一文件
`get_name()` 里紧接着中文名字设定前也有一行调试残留 `printf("%O\n",
ob);`（AGENTS.md §7.34），会把 `/clone/user/login#0` 这样的内部路
径直接印在中文名字提示的正下方。**现场验证**：用管理员账号 `fluffos`
注册时（修复前）确实在屏幕上看到裸露的 `/clone/user/login#0`；修复
（`ob->query("age")` → `user->query("age")`、删掉 `printf` 那行）
并 `update /adm/daemons/logind` 热编译后，另注册测试角色"阿珍"
（`testchar`），注册过程中不再出现 `/clone/user/login` 字样，
`score` 显示食物/饮水两栏全满（■×25），确认两处修复均生效。

### 修复一：§7.11 新变体——`combatd.lpc::killer_reward()` 无保护 `write_file()` 打断死亡→复活流程本身（新增 AGENTS.md §7.11 条目）

用非管理员测试角色"阿珍"（英文 id `testchar`；中文名字经
`scripts/tmux_mud.sh` 本地 telnet 转发时"珍"字被 §10.2 记录的 CJK
字节转发问题损坏，实际存档显示为"阿�"——纯测试工具副作用，与
`is_chinese()`/注册逻辑无关，不影响本次验证结论）、`set wimpy 0`
后在中央广场主动 `kill` 流氓头，几回合后死亡。**死亡没有正常进入
鬼门关**，而是原地反复打印"你死了"、持续被流氓头攻击，每次心跳都
在玩家屏幕上抛出：

```
执行时段错误：*Wrong permissions for opening file /log/nosave/KILLRECORD for append.
"No such file or directory"
程式：/adm/daemons/combatd.lpc 第 750 行
呼叫来自：/feature/damage.lpc 的 die() 第 145 行
呼叫来自：/adm/daemons/combatd.lpc 的 killer_reward() 第 750 行
```

追查：`killer_reward()`（被 `feature/damage.lpc::die()` 无条件调用，
每次死亡都会触发，不限于玩家间 PK）结尾有一处
`write_file("/log/nosave/KILLRECORD", ...)`，`/log/nosave/` 目录本
档案从未存在过。这个 `write_file()` 没有 `catch()` 保护，抛出的异
常会一路向上打断整条调用链——不仅打断 `killer_reward()` 自己剩下
的逻辑，还打断了调用它的 `die()`，导致 `die()` 里紧跟在
`killer_reward()` 调用之后的 `this_object()->move(DEATH_ROOM);
DEATH_ROOM->start_death(this_object());` 两行永远执行不到，玩家永
远走不出死亡循环。修法：本档案 `adm/simul_efun/file.lpc` 已有现成
的 `assure_file()` simul_efun（和 `jyqxc`/`jyqxc2` 系列已知修法用的
是同一个 helper），在 `write_file()` 前补一行
`assure_file("/log/nosave/KILLRECORD");` 即可。

**现场验证**：测试角色卡在死循环中时，用管理员账号 `update
/adm/daemons/combatd` 热编译修复后的代码，紧接着的下一次心跳死亡
就正常解决——玩家被移到"鬼门关"，"白无常"完整跑完对话链
（"哼"→翻查生死簿→"阳寿未尽？怎么可能？"→"罢了罢了，你走吧"），
`reincarnate()` 后被送到"武庙"复活，`score` 显示精/气降到约
56%（14/25 格，符合死亡惩罚），食物/饮水仍全满——完整、无中断的
死亡→复活流程验证通过。`work/log/nosave/KILLRECORD` 也确认生成且
写入了正确的击杀记录（该目录属于 `.gitignore` 排除的运行期状态，
不需要提交）。

**`jyqxc`/`jyqxc2` 同样带有这处未修复代码**：两份姊妹档案的
`combatd.lpc` 里有逐字节相同的 `write_file("/log/nosave/KILL_PLAYER"
, ...)`，但套在 `if (userp(killer))` 判断里（只在玩家杀玩家时触
发），本档案这处判断被去掉了，变成无条件执行——这正是两份姊妹档
案自己的 §10.7 测试都杀的是 NPC、从未触发到这段代码、因而遗漏此
bug 的原因。后续如再碰到 `jyqxc`/`jyqxc2`，可直接照搬本次修法。

### 修复二：§8.14 IP 封禁检查参数错误（regexp 匹配变体，失效而非误封）

`adm/daemons/logind.lpc::logon()` 里 `BAN_D->is_banned(query_ip_name
(ob))`——传的是反向 DNS 主机名，而不是点分十进制 IP。
`band.lpc::is_banned()` 用 `regexp(({site}), Sites[i])` 逐条匹配
`banned_sites` 文件里的点分十进制模式（如 `202.112.111.82`），不像
`hy3` 那样有"解析失败即视为已封禁"的兜底逻辑，所以本档案这处错误
的表现是**封禁列表整体失效**（主机名字符串永远不会匹配点分十进制
的正则模式），而不是`hy3`那样"误封所有人"——方向相反，根因相同。
同一文件里 206 行附近另有一处 `query_ip_number(ob)` 用法正确，确认
是参数传错而非有意为之。修法：把 `query_ip_name(ob)` 改成
`query_ip_number(ob)`。修复后 `update /adm/daemons/logind` 编译干
净通过；因沙盒环境无法模拟真实的封禁 IP 连接，未做端到端的"确实
被封"现场验证，但已确认改动后编译/加载都正常，且不影响任何本次
测过的正常登录路径。`jyqxc`/`jyqxc2` 的 `logind.lpc` 同样带有这处
未修复的 `query_ip_name(ob)` 误用，供后续参考。

### 死亡/复活系统：§7.101、§7.68 形状均不适用（有意设计，现场核实）

`d/death/` 全目录只有 `gate.lpc` 与 `jyqxc` 有一处内容差异（本档案
"objects" 里注释掉了 `newgargoyle` 的生成，只留"白无常"一位鬼差；
`newgargoyle.lpc`/`wgargoyle.lpc` 各自都有完整独立的
`death_stage()`→`reincarnate()`→`move(REVIVE_ROOM)` 逻辑，缺一个不
影响另一个能不能完整走完复活流程，是内容差异不是 bug），其余全部
死亡区文件（`gateway`/`road1`/`road2`/`road3`/`inn1`/`inn2`/`block`
及三个鬼差 NPC）与 `jyqxc` 逐字节相同。

- **§7.101（`exits` 缺失 `valid_leave()` 已实现的方向）不适用**：逐
  文件读了 `gate.lpc`/`gateway.lpc`/`road2.lpc` 的 `exits` 与
  `valid_leave()`——`gateway.lpc` 判断 `dir=="south"`，`exits` 确实
  有 `"south"` 键；`road2.lpc` 判断 `dir=="north"`/`"south"`，
  `exits` 也都有对应键。没有发现任何"`valid_leave()` 实现了但
  `exits` 里没有对应键"的缺口。
- **§7.68（`present()` 守卫误伤"暂时不在场"）不适用**：三个鬼差
  NPC 与 `jyqxc`（该 bug 类已在 `jyqxc` 自己的 §10.7 里独立核实、
  后又撤销、确认为有意设计）逐字节相同，本次现场完整、无中断的死
  亡→复活流程也顺利走完，不存在强制把鬼魂从鬼门关移走的第二套机
  制，与 `jyqxc` 此前的最终结论一致，不套用旧修复。

### 留言板：post/read/discard 全流程验证通过（改用 mudclient.py）

`scripts/tmux_mud.sh` 走本地 telnet 二进制，在提交多行内建列编辑器
输入（主题行+正文+`.`结束）时触发了 §10.2 记录过的问题：本地
telnet 客户端把某个字节序列误判成了自己的转义序列，会话跌回本地
`telnet>` 提示符，输入的中文内容也没有正确发送。改用
`scripts/mudclient.py`（原始 socket，绕开本地 telnet 二进制）后，
`post kedian_b` → 主题"测试留言二" → 正文"第二次测试留言。" → `.`
结束、`read kedian_b 1` 显示内容正确、`discard 1` 成功删除，全程
无崩溃、无残留（客店留言板测试后恢复"没有任何留言"）。

### 其余检查

- `mailbox`：`look mailbox` 正常列出 `mail`/`forward`/`from`/
  `read`/`discard` 指令说明。
- §7.5（`securd.lpc`/`securityd.lpc` 的 `valid_read()` ACL）：本档
  案 `securityd.lpc` 只定义了 `valid_write()`/`valid_seteuid()`，没
  有 `valid_read()` 覆写，整个测试会话（含 `update`、`load_object`
  隐式触发的编译）都没有出现任何 ACL 拒绝，不适用。
- §7.90（eval-cost 上限过低）：`config.fluffos` 的 `maximum
  evaluation cost` 是本项目常见默认值 700000，本次注册、移动进入
  多个未预编译房间、战斗、死亡、复活全程没有触发任何 eval-cost 中
  止提示，不适用。
- §8.13（wizlist WIZ 密码二次登录死锁）：管理员账号多次断线重连测
  试均未触发额外的 WIZ 密码询问环节，本档案登录流程没有这道独立
  的二次密码关卡，不适用。
- `debug.log`（实际输出重定向到本次启动日志）全程没有出现
  §7.11 KILLRECORD 之外的任何 `执行时段错误`，唯一一条系统级信息是
  `System Error: init_addr_server: connect:No such file or
  directory`（沙盒环境无外部网络导致，与 mudlib 代码无关，历次测
  试都会出现）。
- `quit` 两个测试角色（`fluffos`、`testchar`/阿珍）均正常退出。

修改文件：`adm/daemons/combatd.lpc`（§7.11 KILLRECORD `assure_file()`
修复）、`adm/daemons/logind.lpc`（§8.9 食物/饮水初始化用错对象、
§7.34 `printf` 调试残留、§8.14 IP 封禁参数错误，共三处修复）。
新增未跟踪存档：`work/data/login/f/fluffos.o`、
`work/data/user/f/fluffos.o`（管理员种子账号，按 AGENTS.md §1.5 约
定提交）。测试用抛弃角色 `testchar`/阿珍的存档已删除，未提交。

## §7.100 扫描修复（`ROOM` 基类多余 `replace_program()`）

`#define ROOM "/inherit/room/room"`：删除 818 处多余的、独立成行的
`replace_program(ROOM);`（保留 `inherit ROOM;`），与 `jqxz2008`/
`xkx2017` 系列同一血统同一形状。`clone/misc/roommaker.lpc` 同样有
两套模板——"造一间空房间"的 heredoc 本来干净，"克隆我所在的房间"
命令的字符串拼接模板把同一枚多余的 `replace_program(ROOM);` 烤进
了每一个新克隆的房间，已同步修正。已用 `build-debug` 驱动干净启
动验证（0 个新增编译错误，端口正常监听）；未做完整 §10.7 深度游
玩测试。

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

## 深度功能测试第二轮（§10.7 round three batch 4，2026-09-01）：`convert_lib.sh` `static`→`nosave` 误伤（AGENTS.md §4.3），third independent lineage — 三处直接 `write_file()` 崩溃 + 一处共享 NPC 头文件的未初始化 mapping 崩溃

本轮的直接触发原因：姊妹档案 `jyqxc`（round-three batch 2）和不相关
血统 `hxxtjqb`（本轮 batch 4）都各自独立确认了同一枚 `convert_lib.sh`
转档脚本的 `\bstatic\b`→`nosave` 全局替换误伤字符串字面量的 bug
（AGENTS.md §4.3），本档案自己 2026-08-08 那次 §10.7 也真的踩过同一个
形状（`combatd.lpc::killer_reward()` 的 `KILLRECORD` 写入崩溃），但当
时的修法是「就地建出 `/log/nosave/` 目录」而不是「查 `raw/` 确认原始
路径应该是 `static/` 再改回去」——本轮用 `raw/jy/` 原始未转档源码逐一
核对，证实那次修法虽然消除了崩溃，却让新数据写偏了目录（`log/static/`
里其实早就有对应的、可回溯到 1997/2013 年的真实历史记录，`log/nosave/`
从未存在过、也不该存在）。

**全档案 grep 复查**（`grep -rn '"nosave/\|nosave/'`，排除 `nosave int/
string/object/mapping/...`/`nosave void` 这些合法的变量与函数修饰符用
法）：命中 **12 个文件 / 17 处调用点**，逐一对照 `raw/jy/` 原始 `.c`
源码确认全部应为 `static/`：

- `adm/daemons/securityd.lpc`（`promotion`，1 处）
- `adm/obj/master.lpc` / `adm/single/master.lpc`（`crash()` 里的
  `CRASHES`，各 3 处，两份文件字节相同）
- `cmds/adm/call.lpc` / `cmds/arch/call.lpc`（`CALL_PLAYER`，字节相同
  拷贝，各 1 处）
- `cmds/adm/recover.lpc`（`RECOVER`，1 处，`raw/` 原文件里这行本来就
  带一个多余的前导 `/`——`log_file("/static/RECOVER", ...)`——是原始
  设计里就有的、无害的路径拼接小瑕疵，不是转档引入的，本次原样保留
  只改 `nosave`→`static`）
- `cmds/arch/purge.lpc`（`PURGE`，2 处）
- `cmds/usr/suicide.lpc`（`SUICIDE`，1 处）
- `cmds/std/kill.lpc`（`ATTEMP_KILL`，1 处，直接裸 `write_file()`，不
  经过 `log_file()`）
- `cmds/skill/bai.lpc` / `cmds/skill/apprentice.lpc`（`FENG`，字节相同
  拷贝，各 2 处，同样是直接裸 `write_file()`/`read_file()`）
- `adm/daemons/combatd.lpc`（`KILLRECORD`，2 处，2026-08-08 那次已经
  用「就地建目录」的方式堵住了崩溃，本轮改成查 `raw/` 后确认的正确
  路径）

`work/log/static/` 目录本身确实包含这些文件的真实历史种子数据（例如
`CALL_PLAYER` 最老一条是 2013 年的记录，`KILLRECORD` 最老一条能追溯到
1997 年），`work/log/nosave/` 在 git 里从未存在、`.gitignore` 也确认
是运行期目录——这就是 AGENTS.md §4.3 描述的两种表现之一：不是「立刻
崩溃」就是「静默地把新数据写偏进一个从未被任何人读取的目录，旧数据被
晾在原地」。本档案是两种表现都占了：`CALL_PLAYER`/`ATTEMP_KILL`/
`KILLRECORD` 三处一旦真正触发就会抛出 `*Wrong permissions for opening
file /log/nosave/XXX for append. "No such file or directory"`
未捕获异常（`KILLRECORD` 那处 2026-08-08 已经先用 `assure_file()`
堵过一次，但堵的是错误的目录）；其余几处（`CRASHES`/`PURGE`/
`SUICIDE`/`promotion`/`RECOVER`/`FENG`）走 `log_file()`，此前从未被
命中过，属于静默数据丢失类型，直到本轮才被系统性挖出来。

**修法**：与 `hxxtjqb` 本轮同一手法——(1) 全部 12 个文件 17 处调用点
按 `raw/jy/` 原文核对后机械改回 `static/`；(2) 给共享的 `log_file()`
simul_efun（`adm/simul_efun/file.lpc`）本身也加一道
`assure_file(LOG_DIR + file)` 前置调用（文件里已有现成的
`assure_file()` helper，补一行前向声明避免"函数须先声明才能调用"的编
译顺序坑），这样以后任何新增的、引用了未创建目录的 `log_file()` 调用
点都会自愈；(3) 三处绕开 `log_file()` 直接裸 `write_file()` 的调用点
（`kill.lpc` 的 `ATTEMP_KILL`、`bai.lpc`/`apprentice.lpc` 的 `FENG`）
各自补一行 `assure_file()`，和 `combatd.lpc::killer_reward()` 里
2026-08-08 已经加过的那行做法保持一致（只是把路径也一并订正为
`static/`）。

**顺手修复一个同一行上的运算符优先级 typo**（`bai.lpc`/`apprentice.lpc`
两份字节相同拷贝，均已确认 `raw/jy/cmds/skill/bai.c` 原始代码里就带
这个 bug，不是转档引入的）：`(string)me->query("family/master_id" ==
"feng qingyang")` 把 `==` 误放在了 `query()` 的参数字符串里面，先算
出恒假的字符串比较结果（`0`）再拿去调 `query(0)`，导致这条给"风清扬"
准备的隐藏收徒彩蛋分支永远进不去、`nosave/FENG` 的 bug 本身反而从未
被真正触发过。已把 `==` 挪回 `query()` 外面：`(string)me->query
("family/master_id") == "feng qingyang"`。

**现场验证**（`build-debug` 驱动重启，端口 40108，全程原始 Python
socket 脚本，逐动作 grep `log/debug.log`；测试角色 `qftestc`/
"秦风测三"，管理员 `fluffos`/`Mud@2026`）：
- `call qftestc->query("id")` （管理员对在线玩家的跨对象调用，
  `cmds/adm/call.lpc`/`CALL_PLAYER` 路径）：修复前会直接执行时段报错
  中止；修复后干净返回 `= "qftestc"`，`log/static/CALL_PLAYER` 追加了
  一行新记录（紧接在 2013 年的历史记录后面）。
- 管理员对测试角色发起真实 `kill`（先用 `call qftestc->update_age()`
  把有效年龄推过 15 岁下限，绕开 `kill` 指令自带的"未成年玩家保护"设
  计性门槛——与本次要修的 bug 无关，纯粹是测试需要；在允许战斗的
  "中央广场"进行）：修复前 `write_file()` 异常会把 `obj->fight_ob(me)`
  和警告提示整段吞掉，受害玩家永远不会反击；修复后测试角色正确收到
  "看起来沙河生想杀死你！如果你要和沙河生性命相搏，请你也对这个人下
  一次 kill 指令。"提示并成功反击，双向多回合拳脚交锋消息正常输出，
  `log/static/ATTEMP_KILL` 追加了新记录（紧接在 1997 年的历史记录
  后面）。
- 用 `call qftestc->die()` 在真实对练中途强制触发死亡结算（此时
  `last_damage_from` 已经是管理员，走的是 `killer_reward()` 的玩家互
  杀分支）：`= 0` 干净返回，谣言频道正确广播"我看到秦风测三被沙河生
  击死了"，完整无中断地走完"死了→鬼门关（白无常对话链）→复活于武庙"
  全流程，`score` 显示潜能从 99 掉到 50（符合死亡惩罚），
  `log/static/KILLRECORD` 追加了新记录（紧接在 2013 年的历史记录
  后面）。全程 `log/debug.log` 零新增执行时段错误。

**顺带发现并修复的独立 bug（未初始化 mapping 索引崩溃，与 §4.3 无关，
是本轮测试"进入中央广场"这一步意外撞见的）**：`d/mingjiao/npc/
mingjiao.h` 与 `kungfu/class/mingjiao/mingjiao.h`（两份字节相同拷贝，
被 19 个明教 NPC 文件 `#include`，含本次测试路过的"常遇春"）里共享的
`greeting(object me, object ob)` 函数，`if (ob->query("party")
["party_name"] == ...)` 直接对 `query("party")` 的返回值取下标，没有
先判空——任何没有加入门派的玩家（包括所有新建角色，`query("party")`
返回未初始化的 `int 0`）第一次和这些 NPC 同处一室、`init()` 触发
`call_out("greeting", 1, ...)` 时，都会抛出 `*Value being indexed is
zero.` 未捕获异常。同一文件夹里 `kungfu/class/mingjiao/zhangwuji.lpc`
（"张无忌"）自己内联的同一段逻辑已经正确写成 `if (ob->query("party")
&& ob->query("party")["party_name"] == ...)`——两份 `mingjiao.h` 显然
是从这份正确逻辑抄漏了判空这一步。现场复现：测试角色（未加入任何门
派）被管理员 `summon` 进中央广场（"常遇春"所在房间）后，`debug.log`
立即出现该运行时错误；补上 `ob->query("party") &&` 判空、重启驱动后
同样操作不再报错。已同步修复两份字节相同的头文件。

修改文件：`adm/daemons/securityd.lpc`、`adm/obj/master.lpc`、
`adm/single/master.lpc`、`cmds/adm/call.lpc`、`cmds/arch/call.lpc`、
`cmds/adm/recover.lpc`、`cmds/arch/purge.lpc`、`cmds/usr/suicide.lpc`、
`cmds/std/kill.lpc`、`cmds/skill/bai.lpc`、`cmds/skill/apprentice.lpc`、
`adm/daemons/combatd.lpc`（以上均为 §4.3 `nosave`→`static` 路径订正，
`combatd.lpc` 额外是订正 2026-08-08 那次的部分修复）、
`adm/simul_efun/file.lpc`（`log_file()` 加固）、`d/mingjiao/npc/
mingjiao.h`、`kungfu/class/mingjiao/mingjiao.h`（未初始化 mapping 判
空）。测试用抛弃角色 `qftestc`/"秦风测三"的存档已删除，未提交；管理
员账号 `fluffos` 因测试期间多次 `save()`/死亡/加钱而产生的存档更新
按 AGENTS.md §1.5 约定提交。另：现场也验证了 `inherit/item/money.lpc`
的 `query_autoload()`/`autoload()` 契约完整无误（不是 AGENTS.md §7.199
`fysjmb`-class 的货币销毁 bug）——用管理员 `clone`+`give` 塞给测试角
色 555 文铜板，`quit`/重新连线后 `i` 正确显示金钱原样保留。

**跨库信号**：这是 AGENTS.md §4.3 `static`→`nosave` 误伤模式第三次
在互不相关的血统家族独立确认（`jyqxc`/`jyqxc2`→本档案→`hxxtjqb`，外
加更早的 `yxsj`/`yxzsj`），已达到项目"3+ 独立血统 → 值得跑一次全档
案机械扫描"的标准线。建议后续扫描用这个 grep 起手：
`grep -rn '"nosave/\|nosave/' --include='*.lpc' --include='*.h' .`，
命中后逐条排除 `nosave int/string/object/mapping/mixed/float/function/
void`（这些是合法的变量/函数修饰符用法，不要动），剩下的字符串字面
量命中都需要去对应库的 `raw/` 原始源码核实是否应该是 `static/`，并
检查仓库里是否真的存在 `log/static/` 这个种子目录作为佐证。
