
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

## 深度功能测试（2026-09-04，round three，shop + 拜师）

新角度：醉仙楼购物 + 丐帮左全拜师。2026-08-08 / 2026-09-01 两轮都没
测这两步。`F_DEALER` 对丐帮拒绝购买（穷叫化）是活的，必须先买再拜。

### 发现并修复的 PROGRAMMING bug

1. **`log_error()`（`adm/obj/master.lpc`，config 的 master file）完全
   没有严重度检查（AGENTS.md §7.34-class，与本轮 `fy330`/`fy2mg` 同一
   原始形状）**：`if (this_player(1)) efun::write("编译时段错误：" +
   message + "\n");`。真实复现：全新驱动进程下 `fluffos` 登录触发的
   冷编译级联，屏幕连续刷出 Unused local variable / Unknown escape
   sequence 诊断（`/feature/damage`、`combatd`、`dealer`、`apprentice`
   等）。修复：加上 `strsrch(message, "arning:") == -1` 判断。已用
   重启驱动后的重登复测：零次 `编译时段错误` 刷屏。`log_file()` 在
   2026-09-01 那一轮已经有 `assure_file()`，未再改。
2. **`data/board/*.o` 里 8 份存档是旧式二进制格式（AGENTS.md §7.7，
   与 `xkx2017` round two 同一形状）**：`bonze_b`、`gaibang_r`、
   `huashan_b`、`kedian_b`、`taohua_b`、`wiz_b`、`wudang_b`、
   `xingxiu_b` 开头是 `?inh...` 而不是 `#inherit/misc/bboard.c`。
   `restore_object()` 把 `create()` 里 `set_name("客店留言板")` 刚设
   好的 dbase 整份替换掉，live `look` 客店显示
   `/clone/board/kedian_b [ 没有任何留言 ]`。`feature/name.lpc` 的
   `capitalize()` 防护让它不再崩溃，但名字仍是裸路径。删除这 8 份
   无法解析的损坏存档后重测，正确显示 `客店留言板(Board) [ 没有任
   何留言 ]`。另外 10 份（`baituo_b`、`gaibang_b`、`kedian2_b`、
   `lingjiu_b`、`shaolin_b`、`tiandi_b`、`towiz_b`、`xiaoy_b`、
   `xiaoyao_b`、`xueshan_b`）有 `#` 存档头，未触碰。

### 实测过程

管理员 `fluffos` / `Mud@2026`（中文名 沙河生）。第一输入是「您的英
文名字：」，落地客店。`goto /d/city/zuixianlou`，`list` 烤鸡腿八十
文铜板 / 牛皮酒袋一两白银 / 包子五十文 / 鲸鱼十两黄金。
`clone /clone/money/gold` 后 `buy jitui` 成功。当场 `i` 还挂着「一
两黄金」；重启驱动再连只剩九十九两白银 + 二十文铜板（10000−80 =
9920），找零数学正确。烤鸡腿未进 autoload。

`goto /d/gaibang/inhole`，`apprentice zuo` 一次成功：左全收徒，
`score` 「丐帮第二十代弟子」、师父左全。`cmds/usr/save.lpc` 真正调
用两个 `save()`。重启驱动再连，`score` 仍是丐帮 / 左全，银子还在。
左全只收男性。

live `debug.log` 是 `libs/jyqxc2013fwq/log/debug.log`（复测 Boot
Time Fri Sep 4 01:27:54 2026），无 `error:` / `Too deep recursion`。
`error_handler` 把轨迹交回驱动 debug.log。管理员存档未提交（本轮
只修 master + 损坏留言板存档）。

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— tail() simul_efun

`scripts/lpc_add_tail.py --apply`: `cmds/wiz/tail.lpc` calls `tail(file)`, an efun of the MudOS this archive ran on that FluffOS does not have (`Undefined function tail`: the command did not compile). `adm/simul_efun/file.lpc` now defines `void tail(string file)`: the last 10 lines of the file, written to the player. Load check (HEAD against the working tree): 1 of the 1 tail command file(s) failed to load at HEAD, all load now, and the simul_efun file loads. KB 04 §6.2.

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `inherit/room/room.lpc`：`make_inventory()` 用 `catch()` 包住 `new(file)`，做不出来就返回 0；`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-05）— 巫师留言板存档 `data/board/*.o.gz`

巫师留言板 `wiz_b` / `towiz_b` 以 `.o.gz` 存档（1996 年的帖子）。本机驱动 `restore_object()` 优先读 `.o.gz`，而留言板用 `save_object(file)` 写明文 `.o`，所以本机上新帖每次重启都退回旧快照；网页版驱动没有 zlib，只读 `.o`，而归档自带的 `.o` 是读不出的二进制。`.gz` 内容为 GB18030（转码时没被处理），转成 UTF-8 写成 `.o`，替换归档里那个读不出的二进制 `.o`；`towiz_b` 原文有 4 个残字节，转为替换符。删除 `.o.gz`（KB 01）。用 lpcc 载入留言板核对条数（jqxz2008：wiz_b 47 条、towiz_b 115 条）。

## 深度功能测试（§10.7，2026-10-06）— 白驼山掌门欧阳锋编译不过

`d/baituo/ouyangfeng.lpc` 有两处笔误，整个 NPC 从未编译成功：`greeting()` 里 `write("你是谁？我要杀了你！哈￣哈￣哈￣") break;` 缺分号，`inquiry_map()` 里 `object me = this - player();`（应为 `this_player()`）。白驼山派的掌门因此不存在，拜师、问路（`inquiry_map`）都无从谈起。两处改正后，新进程里 HEAD 加载失败、工作树加载成功。同一文件在 14 个 xkx 系的库里一字不差。

## 深度功能测试（§10.7，2026-10-07）— 空的 `if (current_water == 0) {}`

3 个房间的 `valid_leave()` 里有一行什么也不做的 `if (current_water == 0) {}`（编译警告 `Expression has no side effects`），删去，行为不变：`d/xingxiu/nanjiang2.lpc`、`d/xingxiu/nanjiang3.lpc`、`d/xingxiu/shanjiao.lpc`。

## 深度功能测试（§10.7，2026-10-07）— 编译警告整理

`scripts/lpc_warnings.py jyqxc2013fwq --fix` 加 `scripts/lpc_fix_no_effect.py --apply`，共改动 265 个 `.lpc` 和 10 个 `.h`（多为删去未用的局部变量）。HEAD 与工作树分别加载（新进程）：249 -> 249 通过，无回退；改过的头文件的 67 个包含者 67 -> 67 通过。启动时警告 17 -> 0；新进程登录（输入名字）正常。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 6 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 1 个，只在 #if 分支用的声明移进分支 0 个文件；改动 6 个文件，HEAD 与工作树各载入一次无回退（6 objects; HEAD PASS 6, tree PASS 6; regress 0; newly loading 0），这些文件的警告 6 -> 0。

- 2026-10-10（续）：第二轮编译警告整理（`lpc_fix_unused_init.py`）删掉了只在不启用的 `#if` 分支里用到的局部变量声明（如 `include/net/ftpdsupp.h` 中 `#ifdef GUEST_WIZARD_FTP` 分支的 `file`），启用该选项时会编译失败；声明已放回所用的分支里，工具已改为跳过这种情况（交给 `lpc_move_decl.py`）。

## 编译警告收尾（2026-10-13）

`scripts/toolkit_fix.sh` 一轮去掉 16 处多余继承；`include/net/ftpdconf.h` 把 `VALID_READ`、`VALID_WRITE` 定为 1，覆盖 `ftpd.h` 的 0，先 `#undef`（同 xiakexing2017），行为不变。能编译的文件警告清零；改动的对象在 HEAD 与工作树各载入一次（16 objects; HEAD PASS 12, tree PASS 12; regress 0; newly loading 0）。
- 2026-10-14：2 个存档文件（留言板 2 个；`data/board/gaibang_b.o`, `data/board/tiandi_b.o`）还是原档案的 GBK 编码，没有转成 UTF-8，`restore_object()` 报 `Invalid utf8 string` 后对象以空数据启动（表情守护进程没有表情、留言板没有帖子、玩家无法载入）。`scripts/lpc_save_encoding.py` 逐个按 GB18030 解码，结果按存档格式解析通过才写回（KB 03 §4）。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。2 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

另有 3 个文件（绝招、状态、物品、NPC 等，不限于 kungfu/skill）来自 gin/kee/sen/force 体系，同样按 kee→qi、gin/sen→jing、force→neili 改名（`scripts/lpc_port_es_props.py --any-file`）。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。5 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`mizongxinfa`→`mizong-xinfa`（`longxiang/fanchang`）；`qiankundanuoyi`→`qiankun-danuoyi`（`/cmds/std/nuoyi`）。

## family 映射内联取下标（2026-10-15，KB 05 §7.30）

`ob->query("family")["master_name"]`、`me->query("family")["family_name"]`（泥潭式为 `query("family", ob)[...]`）直接对门派映射取下标：没有门派的人（新玩家、叛师者、大多数 NPC）在 NPC 的打招呼和问话、绝招的门派判断、房间的 `valid_leave` 里报 `Value being indexed is zero`，而不是得到拒绝。7 处（6 个文件）改为 dbase 路径查询 `query("family/master_name")`：有门派时值相同，没有时得 0；原有的判断照常生效（`scripts/lpc_fix_family_index.py`）。给映射赋值的写法未动。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

3 个文件、3 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/d/city/obj/tudao`、`/clone/cloth/female-cloth`、`/clone/cloth/cloth`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 0 个，改后 2 个（2 个原来载入不了），没有退步；其余 1 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## 去掉的预定义宏 `SAVE_EXTENSION`（2026-10-18，KB 04 §6.11）

老版 MudOS 给每个 LPC 对象预先定义了 `SAVE_EXTENSION`（`".o"`）；FluffOS 的 ChangeLog（COMPAT_BUSTER 一条）把它删了，改用 `__SAVE_EXTENSION__`。本库没有自己 `#define` 这个宏，用到它的文件一律 `Undefined variable 'SAVE_EXTENSION'`，整个对象载入不了。改成 `__SAVE_EXTENSION__`（`scripts/lpc_fix_predefined_macro.py`）：`adm/daemons/network/netmail.lpc`、`cmds/arch/purge.lpc`、`d/quanzhou/npc/tang.lpc`、`d/quanzhou/npc/tang3.lpc`、`d/taishan/tang3.lpc`、`include/net/ftpdsupp.h`。`tang3`/`tang`/`meng-zhu` 是武林盟主一类的 NPC，原来一个都载入不了；`purge` 是清除玩家档案的巫师指令；`netmail` 是网络邮件守护进程（本库缺 `mailer.h` 等头文件，改后仍载入不了）。改后用 `lpcc` 逐个载入这些对象：4 个通过，1 个还有别的错误（`adm/daemons/network/netmail`：/adm/daemons/network/netmail.lpc:17: error: Cannot #include mailer.h）。


## 水潭里 `ging_cost` 是 `jing_cost` 的笔误（2026-10-18）

`shuitan` 先算 `jing_cost`，倒水时却扣 `receive_damage("jing", ging_cost)`，`ging_cost` 从没声明过：`Undefined variable 'ging_cost'`，整个物件载入不了。改成 `jing_cost`：`d/shaolin/obj/shuitan.lpc`。改后用 `lpcc` 逐个载入这些对象：1 个通过。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 9 个对象设了本库没有文件的武功（2 个名字，最多的是 `xuanyuan-arrow`、`liangyi-jian`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：9 个里 9 个通过。（`scripts/lpc_guard_set_skill.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 6 处、5 个文件：`xinxiu-duzhang`→`xingxiu-duzhang`（2 处）、`tiaji-jian`→`taiji-jian`（2 处）、`jinyin-baiguzhao`→`jiuyin-baiguzhao`（1 处）、`qishang--quan`→`qishang-quan`（1 处）。（`scripts/lpc_fix_skill_names.py`）

## 全局头文件丢了 1 个宏（2026-10-19，KB 04 §6.16）

`/include/globals.h` 里没有定义 `MAILDIR`，用到它们的物件（名单里 1 个）编译时报 `Undefined variable`/`Undefined function`，整个物件载入不了（编译器在第一个未定义的名字上停下，后面的错误和警告都看不到）。同系的库在各自的头文件里都有这几行：照其中和本库共有文件最多的那个库，原样补到 `/include/globals.h` 最后一个 `#define` 之后，宏体里出现的路径在本库里都存在。名单里的物件除了这几个宏之外还有别的错误，暂时仍载入不了。（`scripts/lpc_restore_defines.py`）

## 标准整理轮（2026-10-19，`scripts/toolkit_fix.sh`）

本库在新驱动下重扫，机械修复：9 处浮点数赋给 int 的地方改成 to_int()。修后与 HEAD 逐个物件对比载入，没有退步。另有 13 处浮点数赋值要手工改（`lpc_fix_float_hooks.py` 列出）。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 技能的 `power_point()` 返回类型（2026-10-19，KB 04 §6.10）

`kungfu/skill/` 下 11 个技能的 `int power_point(object me) { return 1.5; }` 返回的是浮点数，新驱动按 `int` 声明截成 1。声明改成 `float`，值回到设计的 1.1、1.5…。这个库里读 `power_point()` 的只有遗留的 `combatd.b`（二进制，不加载），`combatd.lpc` 不调用，所以对运行没有别的影响。

## 玩家打造兵器模板没有打造者时（2026-10-19，KB 06 §7.275）

`/d/npc/m_weapon/weapon/m_blade.lpc`、`/d/npc/m_weapon/weapon/m_club.lpc`、`/d/npc/m_weapon/weapon/m_staff.lpc`、`/d/npc/m_weapon/weapon/m_sword.lpc`、`/d/npc/m_weapon/weapon/m_whip.lpc`（共 5 个）的 `create()` 开头 `me = this_player();` 之后无条件读 `me->query("weapon/name")` 等打造数据。房间刷新时没有人在场（`me` 为 0），或者 NPC 在别的 NPC 的命令环境里 `carry_object()` 这个模板（NPC 的 `weapon` 属性是文件名字符串），旧驱动里读出来是 0 或字符串，`switch` 照样落到 default；新驱动报 `Bad argument 1 to EFUN call_other()` / `Bad argument 1 to switch`，NPC 和它所在的房间载入不了（`--walk` 普查里一个玩家走进房间就触发）。在 `//读入数据` 之后加 `if (!me || !mapp(me->query("weapon"))) { setup(); return; }`：没有打造者就留一个没有名字的空模板，玩家打造的流程不变。

## 补回丢失的标点（2026-10-19，KB 03 §4.6）

转换时丢掉的分号、逗号、引号或文件末尾的 `}`，共 3 个文件，修前 HEAD 载入失败。别的库里同路径的完好副本只比这里少几个标点，按它补回（括号里是那个库）：`/d/baituo/npc/obj/bowl.lpc`（cctx）、`/d/baituo/obj/bowl.lpc`（cctx）、`/d/city2/npc/zhengmen.lpc`（jqxz2008）。修后与 HEAD 逐个对比载入：这 3 个物件全部载入，没有退步（`scripts/lpc_restore_from_twin.py`、`lpc_fix_eaten_quote.py --comma`、`lpc_fix_eof_braces.py`）。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。改动：`/d/mingjiao/shanmen.lpc`（1 处）。

## 行编辑器指令编译失败：`(: this_object(), ({ "do_to", me, arg }) :)`（2026-10-20，KB 06 §7.284）

`Illegal to use local variable in functional.`：call_other 形式的函数指针 `(: ob, ({ "函数", 参数 }) :)` 的数组里只能是常量，写了局部变量 `me` / `arg` 整个指令就编译不过，`to` 这类先开编辑器、再回调自己的指令因此从未能用。改成 `(: call_other, this_object(), "do_to", me, arg :)`（参数在建立指针时绑定，编辑器再把输入的文字接在最后，`do_to(me, arg, text)` 收到全文；`scripts/lpc_fix_functional_locals.py`）。改动：`/cmds/usr/to.lpc`（1 处）、`/cmds/wiz/to.lpc`（1 处）。

## `call_out_info()` 的每一项只有 3 个元素（2026-10-20，KB 06 §7.287）

驱动返回的是 `({ 物件, 函数, 延迟 })`，不带 call_out 的参数，旧代码读第 4 项 `info[i][3]`（`callouts` 指令、`calloutd`、`cod` 工具）一读就报 `Array index out of bounds`，指令从第一行起什么也打印不出来。改为 `(sizeof(info[i]) > 3 ? info[i][3] : 0)`（`scripts/lpc_fix_callout_info.py`）。改动：`/cmds/arch/callouts.lpc`（1 处）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/obj/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## sefun `cat()`：缺文件时 `write(0)` 报错（2026-10-20，KB 06 §7.297）

`void cat(string file) { write(read_file(file)); }`：文件不存在（压缩包没带的欢迎/公告文件，或只有运行中的 mud 才会写的日志）时 `read_file()` 回 0，`write(0)` 在本驱动里报 `Bad argument 1 to receive()`，调用者（登录对话、`cat` 指令）被中断；老驱动什么也不打印。改成 `write(read_file(file) || "");`（`scripts/lpc_fix_cat_unchecked.py`）。改动：`/adm/simul_efun/file.lpc`。

## 翻页器 `start_more(read_file(...))`：文件缺失时 `explode(0)`（2026-10-20，KB 06 §7.300）

东方故事系的翻页器 `void start_more(string msg) { ... explode(msg, "\n") ... }` 被这样调用：`start_more(read_file(HELP_DIR + "help/topics"))`、`start_more(read_file(NEWS))`。压缩包没带的文件使 `read_file()` 回 0，`explode(0, ...)` 在本驱动里报 `Bad argument 1 to explode()`（不带参数的 `help` 指令就是这样出错的），老驱动把 0 当空文本。在 `start_more` 开头加了 `if (!stringp(msg)) return;`（`scripts/lpc_fix_start_more.py`）。改动：`/feature/more.lpc`。

## 存档里的乱码文件：`restore_object()` 报 `Illegal file format`（2026-10-20，KB 06 §7.316）

存档里有一批数据文件是乱码：开头是 `?adm`、`?inh`、`?clo`、`?obj`（`#/adm/…` 的第一个字节被换成了 `?`），后面是随机字节，没有任何驱动读得了。`adm/daemons/chinesed` 在预载时 `restore()` 读 `data/e2c_dict.o`，首次登录时起始房间的留言板 `/clone/board/kedian_b` 读 `data/board/*_b.o`；`restore_object()` 对不是文本的文件抛 `Illegal file format`，调用处的 `catch()`（KB 06 §7.255）保住了房间和精灵，但本库 master 的 `error_handler()` 把调用栈返回给驱动，每次启动和首次登录都在控制台打印一次或两次 `错误讯息被拦截`。现在共用的 `feature/save.lpc` 的 `restore()` 先读文件第一个字节，不是 `#` 就返回 0（读被 master 拒绝时 `read_bytes()` 返回 0，仍由 `restore_object()` 决定，和以前一样）；留言板和字典从空开始，第一次 `save()` 写出合法文件，乱码文件原样留在树里。实测：启动和登录都没有报错，已保存的角色重新连线照常加载。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库现有的 NPC 文件里没有字面写成空 `chat_msg` 的（扫描只认 `set("chat_msg", ({ }))`）；守卫挡的是运行时才为空的列表和以后新增的 NPC。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/inherit/char/npc.lpc`（共 1 个文件）。

## 存档里的 `.c` 文件名改成 `.lpc`（2026-10-21，KB 03 §4.2 第 9 项）

存档里写着 `"/d/city/npc/wei.c"` 这样的文件名；extract 时源文件已经全部改成 `.lpc`，而驱动对带扩展名的路径只认字面，`new()` / `load_object()` / `move()` 都找不到它，调用方多半把失败当成「没有这个东西」悄悄跳过。本库 3 个存档共 6 处按 `scripts/lpc_fix_save_dotc.py` 改成 `.lpc`（只改 `.lpc` 存在而 `.c` 不存在的字符串；玩家存档、备份、留言板、巫师目录和文件索引缓存不动）。改动：`/d/shaolin/npc/obj/kat.o`（1 处）、`/d/shaolin/obj/kat.o`（1 处）、`/d/shenlong/obj/lxlx.o`（4 处）（共 3 个存档）。

## 巫师命令不带参数时对 0 调用 efun（2026-10-21，KB 06 §7.336）

巫师（管理员）把命令敲成不带参数时，驱动把 0 传给字符串参数；下面的命令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`，这条指令从来没有用过。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py` 在第一处使用参数的语句前加守卫：文件自带 `int help(object me)` 的，守卫是 `if (!arg) return help(me);`（`help()` 定义在 `main()` 之后的 1 个文件补了原型 `int help(object me);`，否则编译报 `Undefined function help`）。改动（1 个文件，括号里是接住 0 的 efun）：`/cmds/wiz/test.lpc`（`present`）。加载检查 HEAD 与工作树对照，没有退步。

## `blockade` / `recover`：`data/keep` 不存在，解封之后世界仍然锁着（2026-10-21，KB 06 §7.340）

管理员扫描里 `blockade` 报 `Error copying file from /data/user/f/fluffos.o to /data/keep/fluffos, Error: No such file or directory`，随后的 `recover` 在第一个 `cp()` 上死于 `*/data/keep/fluffos: lstat failed`，来不及执行最后的 `LOGIN_D->set_madlock(0)`：封锁解不开。`data/keep/` 是运行时目录，git 克隆里没有空目录。`blockade` 在第一次写之前 `if (file_size("/data/keep") != -2) mkdir("/data/keep");`（`mkdir()` 失败答 0，不抛错），`recover` 对没有保存档的玩家 `if (file_size(src) < 0) continue;`，其余照常恢复、照常解锁（`scripts/lpc_fix_keep_dir.py`，hy5 上实测：没有保存档时 `recover` 答“时空解封完毕”，`blockade` 建出 `data/keep` 并保存，`recover` 取回并删除）。改动（2 个文件）：`/cmds/adm/recover.lpc`、`/cmds/arch/blockade.lpc`。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 15 条注册（15 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/d/mingjiao/npc/changjinpeng.lpc`（`do_join`）、`/d/mingjiao/npc/lengqian.lpc`（`do_join`）、`/d/mingjiao/npc/pengyingyu.lpc`（`do_join`）、`/d/mingjiao/npc/shuobude.lpc`（`do_join`）、`/d/mingjiao/npc/tangyang.lpc`（`do_join`）、`/d/mingjiao/npc/wensong.lpc`（`do_join`）、`/d/mingjiao/npc/yanyuan.lpc`（`do_join`）、`/d/mingjiao/npc/yinwufu.lpc`（`do_join`）、`/d/mingjiao/npc/yinwulu.lpc`（`do_join`）、`/d/mingjiao/npc/yinwushou.lpc`（`do_join`） 等共 15 个文件。最多的函数名：`do_join` 13 处、`do_list` 1 处、`do_qiecuo` 1 处。

## 对象路径里的 `..`：`new(__DIR__ "../obj/x")` 报 `Read access denied`（2026-10-22，KB 06 §7.351）

`__DIR__` 是当前文件所在目录（带结尾斜杠），`__DIR__ "../obj/x"` 就是 `/d/zhiye/npc/../obj/x`；驱动的 `legal_path()` 不接受带 `..` 的路径，`new()` / `load_object()` 直接抛 `*Read access denied.`（实测，`find_object()` 对它答 0）。走库自己的 `carry_object()` / 房间 `objects` 表的路径，库的基类会先规范化，能用；直接把路径交给 `new()` / `clone_object()` / `load_object()` / `move()` 的不行，调用到那一步才报错。改成规范化后的绝对路径（`scripts/lpc_fix_dotdot_dir.py --direct`）：`/d/wudang/npc/xiaocui.lpc`（`__DIR__ "../obj/nuerxiang"` → `"/d/wudang/obj/nuerxiang"`）。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 还剩 1 个函数没有补（inquiry 1）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/d/huashan/npc/teller.lpc`:`tell_fortune`。

## `(: 函数名 :)` 指针指向本库没有的函数：只含这个指针的行加了注释（2026-10-22，KB 06 §7.355 补充）

`inquiry` / `item_desc` / `chat_msg*` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：用到时（`ask`、`look`、NPC 闲聊）驱动抛 `*Undefined lfun pointer called: 函数名`，这一拍心跳的后半段被跳过。这些函数没有可以补回的来源（别的库同一路径的文件里没有，或者它还要用本库没有的东西），所以 1 个文件里 1 行只含这个指针的行（`"算命": (: tell_fortune :),`）加了注释，原文保留并写明原因，这一项当作没有这个话题 / 物品 / 闲聊条目（`scripts/lpc_fix_dangling_lfun.py`；`#include` 的文件在库里缺失的对象、指针不在整行上的写法没动）。 前提（`function_exists()`）和加载检查（HEAD 与工作区对比，本库改动的 `.lpc` 文件）的结果见 KB 06 §7.355：没有一个回归。

## 汉字按字节切片的老写法没有换成按字符：改法名 `"澄" + name[2..3]`、辈分判断 `name[0..1] == "澄"` 等 21 处（2026-10-22，KB 06 §7.360）

原档按字节算字符串区间（一个汉字 2 字节）：`name[2..3]` 是名字的第二个字，`name[0..1] == "澄"` 问名字是不是以「澄」开头。转成 UTF-8 之后，这个驱动的区间和 `strlen()` 都按字符算（`strlen("澄观")` 是 2，`"澄观"[0..1]` 是两个字），老算术原样留着、意思全变：拜入少林 / 武当 / 峨嵋等派的玩家被改成错误的法名（二字名 `张三` 变成一个字的 `澄`，更长的名字取到第三个字）；各派掌门的辈分判断（`name[0..1] == "澄"`）永远不成立。

本库 21 处（13 个文件）：拼名字的赋值 13 处、与汉字常量比较 8 处。例：`name[0..1]` → `name[0..0]`（`/kungfu/class/emei/kong.lpc:134`）；`name[2..3]` → `name[1..1]`（`/kungfu/class/shaolin/cheng.h:157`）；`name[0..1] == "慧"` → `name[0..0] == "慧"`（`/kungfu/class/shaolin/cheng.h:140`）。`scripts/lpc_fix_gbk_slice.py` 把下标按字符重算（社区的 UTF-8 版 `xkx100utf8` 里就是同样的写法，作对照）；没有改的：截断（`name = name[0..7]`，现在最多 8 个字，只是放宽）、ASCII 的区间（`fname[0..3] == "room"`、`ctime(time())[4..19]`）和上下文看不出是汉字的区间。证明（`scripts/lpcc_eval.py`，bixiecanyang；其余各库是同一份文本）：让澄字辈掌门 `attempt_apprentice()` 一个名叫「张三」的访客，HEAD 的法名是 `慧`，改后是 `慧三`；抽样 28 个库的 HEAD / 工作树加载对比 0 退步。工具不幂等（`[0..3]` 折半得 `[0..1]`，又是对齐区间），改过的文件记在 `scripts/gbk_slice_converted.txt`，不要重跑。

## 黑木崖脚下的老者：`init()` 里留着调试语句，每个走进 `/d/heimuya/road1` 的人都触发运行时错误（2026-10-22，KB 06 §7.361）

`d/heimuya/npc/laozhe.lpc` 的 `init()` 在 `::init()` 之后有 `what = new(__DIR__ "obj/yancao"); sprintf("%s aaa\n", what);`：调试遗留，`%s` 收字符串或数字、不收对象，于是 `(s)printf(): Incorrect argument to type %s. (arg: 0)` 每次有人进入乱石坡都抛一次，后面的 `call_out("greeting", ...)` 永远不执行，老者不再搭话（还每次白克隆一个烟草）。两行都注释掉（同系的 haiyang2 / hy / hy5 / cctx / fqyy2 早就注释了）。证明：`scripts/lpc_reach_census.py xiakexing2017 --load --walk`（一个普通 NPC 访客走进每个加载成功的房间）：HEAD 336/337，改后 337/337。

## 长度检查按字节写，旁边的提示按汉字写：2 处（2026-10-22，KB 06 §7.362）

老档的 `strlen()` 数字节（一个汉字 2 字节），转成 UTF-8 后它数字符：提示写「必须是 2 到 6 个中文字」的检查还是 `strlen(name) < 4 || strlen(name) > 12`，于是两三个字的房名、帮会名、群名、聊天室名、称号被提示自己说允许的那句话拒绝，上限却是提示的两倍；留言板的标题检查 `i < 4 || i > 24 || i % 2` 还会拒绝所有奇数个字的标题（`post 你好吗`）。本库 2 处（1 个文件）：`if ((strlen(name) < 2) || (strlen(name) > 12)) {`（`/adm/daemons/logind.lpc:512`）。`scripts/lpc_fix_strlen_gate.py` 以提示为准：条件里每个 `strlen` 门槛都恰是提示所说数字的两倍才折半，存长度的变量（`i = strlen(arg);`）的门槛和 `|| i % 2` 奇偶项、其后循环的 `i % 2 == 0 &&` 一并处理；提示里有英文 / 字母 / 字节的不动。证明（`scripts/lpcc_eval.py`，bxsj 的留言板，求值对象继承 NPC 并重写 `edit()` 记录调用，`command("post 标题")`）：HEAD 拒绝「你好」和「你好吗」、放行 23 个字的标题；改后接受前两个、拒绝第三个；shenmo 的 `named.lpc invalid_new_name("张三")`：HEAD 回 `名字只能是2-4个中文字。`，改后回 0。抽样 24 + 15 个库的 HEAD / 工作树加载对比 0 退步。

## 按字节写的汉字循环、茶馆猜诗和同盟频道标题（2026-10-23，KB 06 §7.363）

老档按字节做「一个汉字」：`while (i--) if (i % 2 == 0 && !is_chinese(name[i..<0]))` 只检查偶数下标，奇数位上的拉丁字母（`张a`）会过；茶馆猜诗 `mixup()` 用 `strlen(str)/2` 再 `j=j+j`、`str[k..k+1]` 交换两字节；泥潭系 `channeld` 的 `switch (strlen(fname)) case 4/6/8/10` 和 `strlen(family)==4/6` 按字节长度给同盟 / 门派名加空格。本驱动的 `strlen()` 和区间都按字符算。`scripts/lpc_fix_byte_char.py`：去掉奇偶项、把区间改成 `name[i..i]`，按字符重写 `mixup()` 并把 `strlen(first)>=14` 折成 7，频道标题的 case / 门派长度改成字符数（对照 aoxiangtianji）。本库 汉字循环 / `is_chinese` 区间 1 个文件。证明（`scripts/lpcc_eval.py`）：sjplii 的 `check_legal_name` 在 HEAD 接受「张a」、改后拒绝，两边都接受「张三」；xkx100 的 `clubpoem->mixup("离离原上草")` 得到「离离原草上」（真交换汉字）；nitan_san 两字同盟名得到 `【 兄  弟 】`。关键对象加载通过。
