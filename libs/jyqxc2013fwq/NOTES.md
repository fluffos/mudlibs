
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
