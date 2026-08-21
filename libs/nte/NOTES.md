
## WASM 修复摘要（迁移自 meta.json 的 group_note）

泥潭二——一个和 nt6/nitan 不同的 ES2/Annihilator 衍生血统（feature/dbase.lpc 自己已经有完整的双参数 set/query/delete 架构，没有 §7.15 那个 bug）。WASM 修复：（1）经典的 §8.1 GBK 字节区间 is_chinese() bug（生效的那份和一份注释掉的死代码副本都用字节区间判断；已把生效的那份换成码点检查）加上两处独立反复出现的长度界限没减半变体——logind.lpc 的 check_legal_name(arg, 4)（应为 2，对应它自己"不超过两个汉字"的提示）在 2 处呼叫点、它的姓名合并检查 strlen(fname) < 4（应为 < 2）、以及 named.lpc 的 invalid_new_name() 里 strlen(name) < 2（应为 < 1，会把任何单字给名当成"空名字"拒绝）。（2）logind.lpc 的 logon() 里 §1.3e 的 uptime()<30 闸门——对本地回环放行。（3）在两个各自独立的精灵上做了 §7.52 socket 精灵掏空：dns_master.lpc（小型、单一用途，整个掏空）和 versiond.lpc（大型多用途的版本同步精灵，它的 is_version_ok()/query() 等非 socket 函式有 32 个外部呼叫者——只掏空了 13 个碰 socket 的函式/回呼，按既定的"大型多用途精灵"方针保留了其余公开接口）。（4）user.lpc 的 accept_kill() 里 §7.50 的 is_killing(ob) 物件/字符串不匹配——和 nt1/wxddym/zjmudhell/hell 上看到的同一个反复出现的复制粘贴 bug。通过 adm/etc/wizlist 把 fluffos/AdminPass1+loginpw1（双密码机制）播种为管理员，确认注册后被带到巫师专属起始房间。完整的注册→look→quit（包括 quit 的新账号删除确认）流程在排版格式化前后都验证过；格式化工具没有引入任何损坏（三类盲点检查都干净——两处大 diff 分别是 versiond.lpc 自己的掏空和 combatd.lpc 合法的 if-else-if 伤害讯息阶梯合并，不是损坏）。和 nt6/nt6nitan6win 相同的、游戏内"完成出生仪式对话之前不算出生"的内容关卡会影响刚注册角色的 score——不是 bug，不在本轮范围内。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 55 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 2026-08-12 深度功能测试 / Deep functional test (AGENTS.md §10.7)

**这是这份档案第一次真正的 §10.7 round-two 完整游玩测试**（此前只有上面的
WASM 注册验证和 §7.86 跨库编译扫描，均未做过完整游玩）。nte 和 ntii（泥潭
II）共享同一套基础设施档案家族（§7.42/§7.81 记录的"content NPC named
master.c"自动检测陷阱，两者互为近亲），本轮逐一验证 ntii 那份 §10.7 记录
的四类 bug 是否在 nte 上独立复现——全部确认复现，逐一修复，详见下文。

**DB_SAVE 检查**：`include/ntsql.h` 第 9/13 行定义了 `DB_SAVE 1`/
`AUTO_SAVE 1`，和 ntii 完全相同的假阳性——这个驱动构建没有编译进任何 SQL
后端，`db_connect()`/`db_set_player()`/`db_query_player()` 优雅降级为 0，
`TX_SAVE` 文字档存档照常工作，不是 `nitan170911` 式的硬依赖，不需要本地
MySQL 基础设施。

### 驱动升级 + 干净启动

用新编译的 `~/src/fluffos/build-debug/src/driver` 启动
（`cd libs/nte && ~/src/fluffos/build-debug/src/driver config.fluffos`，
端口 40115）。第一次干净启动就命中了和 ntii 完全相同的 `message()` 4 参数
错误洪流（见下文第 1 条），先修复四类 bug 后再重新启动，确认
`log/debug.log` 干干净净：543 行（和 ntii 记录的"修复后同样的启动流程仅
543 行"逐字吻合，进一步印证两份档案这批基础设施档案确实逐字节共享），零
`Bad argument`/`couldn't find object`/级联错误，端口正常监听。本轮共启动
驱动 3 次（每次修复后重新验证一次干净启动，含最后为拾取手动修复的
`adm/etc/wizlist` 而做的第三次重启，见下文）。

### `to_int()` 任务计数器修复验证：一次性测试对象直接复现

会话上文诊断出的生产崩溃（`killer->query("questXX_times") % 500` 在拿到
损坏成 float 的属性值时因 `%` 运算符拒绝 float 左操作数而崩溃）复核确认
`to_int(...) % 500` 的正确形状已经存在于：`adm/daemons/combatd.lpc`（第
2476/2547/2619 行）、`cmds/std/whisper.lpc`（第 185/190/195/200 行）、
`kungfu/class/ultra/{dugu,huang,kuihua,shenni}.lpc`（各自的 quest_count
计算行）——全部已经是修复后的形状，无需改动。

拜师门派 NPC（独孤求败/黄裳/魁花/南海神尼）都在扬州新手区以外的深山，预算
内不现实，改用一次性测试对象直接复现同一个表达式形状：`adm/daemons/
qftest.lpc`（临时脚手架，测试完已删除，`git status` 确认未残留）：

```lpc
mapping bad_data = (["k": 97467776479476432.000000]);
mixed bad = bad_data["k"];
```

用巫师账号 `fluffos` 的 `update` 指令触发 `create()`：

- **修复前形状**（`bad % 500`）：`执行时段错误：*Bad argument 1 to %
  Expected: int Got: 97467776479476432.000000.`——与生产崩溃报告的错误文
  本逐字一致。
- **修复后形状**（`to_int(bad) % 500`）：`create()` 把结果写入
  `/qftest_result.log`：`test_fix returned: 432`，独立验证
  `int(97467776479476432.0) % 500 == 432`。

结论：`to_int()` 修复针对确切的报告故障条件被直接验证有效——目标性复现
（targeted repro），不是靠一次真实完整任务达成。

### ntii 血统四类候选 bug：全部独立复现，逐一修复

1. **`adm/simul_efun/message.lpc` 的 `message()` 包装函式非 varargs**：
   diff 确认修复前和 ntii 修复前的版本逐字节相同。第一次干净启动就在注册
   期间狂刷"Bad argument 4 to EFUN message() Expected: object, array, Got:
   int(0)."。修复（第 315-317 行）：
   ```lpc
   varargs void message(mixed arg, string message, mixed target, mixed exclude) {
     efun::message(arg, message, target, exclude || ({}));
   }
   ```
   修复后重启验证：干净启动，零 `Bad argument` 错误。

2. **`inherit/misc/quest.lpc` 的 `set_information()` 把第二参数声明为
   `string`，`QUEST_D->set_information()` 本身已经正确接受 `mixed`**：
   `clone/quest/{search,capture,shen,supply,defend,deliver,judge,trace,
   explore}.lpc` 九个任务档案全部用闭包 `(: ask_xxx :)` 呼叫，被这个过窄
   的本地包装函式硬性拒绝，编译错误"Bad type for argument 2 of
   set_information ( string vs function )"，随机任务生成子系统从这份档案
   第一次编译起就完全瘫痪，无启动期崩溃症状（AGENTS.md §7.81 已有先例，
   本次是 nitan 血统家族内的第二个独立确认实例，紧接着 ntii）。修复
   （第 111 行）：`string info` → `mixed info`。**现场验证**：修复后用
   `fluffos` 账号 `update /adm/daemons/eventd` 时，紧接着的心跳周期里就
   看到"【系统报告】任务精灵：进程(DELIVER)利用布料创建了一个任务。"这
   类此前从未出现过的系统报告消息；后续测试过程中陆续见到 SEARCH/TRACE/
   CAPTURE/JUDGE 等多个进程的任务创建报告——随机任务系统第一次真正开始
   运作。

3. **`adm/single/master.lpc` 的 `log_error()` 无条件把编译诊断（含纯
   warning）转发给 `this_player()`**（AGENTS.md §7.103 已有先例）：新注
   册流程期间，`/include/globals.h:4` 的"Unknown #pragma, ignored."
   warning 在每一个被懒编译的档案上都原样刷屏给刚注册的新玩家，带着吓人
   的"编译时段错误："前缀。修复（第 184-189 行）：加
   `strsrch(message, "warning:") == -1` 守卫，纯 warning 不再转发给玩家
   （仍写入 log 档案），真正的 error 转发行为不变。

4. **`str[0..<N]` 后缀切片 off-by-(N-1) 错误**（AGENTS.md §7.80 已有先
   例）：全档案定点核对 ntii 记录的 7 处命中位置，逐一确认同样命中：
   `adm/daemons/eventd.lpc` 第 22 行、`adm/daemons/storyd.lpc` 第 50 行
   （`get_dir(*.lpc)` 结果用 `[0..<3]` 剥离扩展名，只剥掉 2 个字符而不是
   4 个）、`adm/npc/luban.lpc` 第 1431/2573 行、`cmds/wiz/mem1.lpc` 第
   80 行、`cmds/adm/refsum.lpc` 第 37/43 行。全部改成 `[0..<5]`。**验
   证**：`fluffos` 账号 `update /adm/daemons/eventd`/`/storyd` 均"重新编
   译...成功！"，`/luban`/`/mem1`/`/refsum` 三个也确认编译通过。

### 新发现的第五类 bug：`force_quit()` 无确认静默删除新账号（本轮实测踩中，非猜测）

**`cmds/usr/quit.lpc` 的 `force_quit()`（由 `clone/user/user.lpc` 的
`net_dead()`→`user_dump(DUMP_NET_DEAD)` 在断线 `NET_DEAD_TIMEOUT`
=900 秒/15 分钟后自动呼叫）对"在线时长不满 30 分钟"（`mud_age < 1800`）
的账号无条件 `UPDATE_D->remove_user()` 删除，完全没有交互式 `quit` 路径
（`cmds/usr/quit.lpc` 第 51-56 行 + `confirm()`）要求的"y/n 确认"。**

这不是代码审查猜出来的，是本轮测试真实踩中的：第一个测试角色"秦云舒"
（`nteqingxue`）走完了注册/性格/天赋/投胎/新手礼物/安全切磋/拜师两条路径
后，因为每次 `mudclient.py` 调用都开一条新连线、测试间隔用 `--timeout` 让
连线自然断开而非显式 `quit`，多次这样的断线累计超过 15 分钟净空窗口、而
角色的真实在线时长（`mud_age`）始终没攒够 30 分钟——于是在某次测试之间，
`data/login/n/`、`data/user/n/` 下这个角色的存档被静默、完整地删除了，没
有任何警告，也没有走过交互式 quit 那句"退出该游戏将删除你的账号，你确定
要放弃该帐号而退出吗？（y/n）"的确认（我们对这个提示始终选择的是 `n`，即
明确拒绝删除）。这直接违反了 §10.1 验证栏要求的"reconnect 验证状态"前提
——账号本身都不在了。

对照交互式路径（`cmds/usr/quit.lpc` `confirm()`）：选 `n` 只会打印"您选择
了放弃退出(quit)，继续游戏。"，完全不会删除，也不会真的断线——新账号如果
不想被删，交互路径下唯一的办法是"不要真的 quit"。`force_quit()` 本该是
"玩家事实上已经不在了（真断线超时），系统代为收尾"的兜底路径，却把这个场
景直接等同于交互式确认过的"y"，在完全没有征得同意（甚至没有机会征得同
意——此时根本没有真人在线可以回答）的情况下执行了相同的破坏性操作。这不
是"内容/设计判断"（真正的交互式确认机制清楚地表明设计意图是"要问过玩家"，
`force_quit()` 只是漏掉了这个安全阀），判定为程序 bug，修复：

```lpc
// cmds/usr/quit.lpc 第 178-182 行（修复前）
if (me->query("mud_age") < 1800 && !me->query("jieti")) {
  UPDATE_D->remove_user(me->query("id"));
  return 1;
}

me->save();
```

删除整个无确认删除分支，直接落入下面已有的安全 `save()` + `move(VOID_OB)`
+ `destruct()` 收尾路径（和"账号 ≥30 分钟"账号走的是同一条安全收尾逻辑，
只是不再对"账号 <30 分钟"这个子集特殊处理成删除）。

**现场验证**：注册全新测试账号 `fqverify`（验证，`mud_age`=0），用巫师账
号直接呼叫 `ob->user_dump(1)`（`DUMP_NET_DEAD`，和真实 15 分钟断线超时触
发的完全同一条代码路径：`user_dump()`→`command("quit")` 失败后
→`QUIT_CMD->force_quit()`），修复前这个调用会经由
`UPDATE_D->remove_user()` 删除 `data/login/f/fqverify.o`、
`data/user/f/fqverify.o` 两个存档；修复后再次执行同样的调用，两个存档文
件依然存在（用 `ls` 直接确认）。测试完删除了 `adm/daemons/fqtest.lpc` 这
个一次性验证脚手架和 `fqtest_result.log`。

**AGENTS.md 新 bug class 候选**：这类"交互路径有确认，自动/超时收尾路径
复用同一段销毁逻辑却跳过确认"的模式，很可能不止 nte/ntii 这一个血统会有
（任何带"新账号断线锁定/删除"策略、且实现了 netdead 自动收尾的 ES2 系血
统都值得一查）——本轮时间有限，未去 sibling 档案里逐一排查，留给下一轮或
sibling 命中时再确认是否要提升为正式 §7.x 条目。

### 完整游玩测试

**第一个角色 秦云霞→秦云舒（`nteqingxue`）**（因为上一段记录的 bug，此角
色在测试过程中途被静默删除，下方记录的所有交互结果本身仍然真实有效——问
题只出在"角色事后消失了"，不是"交互当时就有问题"）：`register` 邮箱 →
`choose 均衡型` → `select 光明磊落` → `wash`（先天天赋 19/24/18/19）→
`born 扬州人氏`，全程零编译错误落地客店，`look`/`score` 均输出正确。武庙
南贤处 `ask nan about gift` 拿到开站礼物，`fen 悟性 4` 后 `score` 确认悟
性 24→28（真实数值变化）。

- **安全切磋机制**：南大街（`/d/city/nandajie1`）的"流氓头"
  （`attitude: peaceful`）接受切磋，`fight liu` 完整走完拳脚交替的回合序
  列，气血/精神耗尽后角色正确触发"看来该找机会逃跑了..."自动脱战逃入相
  邻房间，全程无崩溃——和 ntii 记录的结论完全一致（同一个 NPC、同一个
  房间、同一段判定逻辑）。
- **拜师/门派——两条路径都测了**：organic 路径对"流氓头"（无 `family`
  属性）正确报错"流氓头既不属於任何门派，也没有开山立派，不能拜师。"，
  不崩溃；admin 捷径路径用巫师账号 `fluffos`（`goto` 传送到"流氓头"身
  边）执行 `copyskill liu`，成功触发复制效果（"凌霄口中念念有词，只见
  一道红光笼罩了你和流氓头。"）。真正拥有 `family` 的门派 NPC 都在远离
  新手区的深山，预算内未能走到。
- **quit 保留窗口**：`mud_age`/在线时长不满 30 分钟，`quit` 触发"退出该
  游戏将删除你的账号，你确定要放弃该帐号而退出吗？"——选择 `n` 保留账
  号，即时反馈"您选择了放弃退出(quit)，继续游戏。"，交互路径本身没有问
  题（问题出在上面记录的 `force_quit()` 非交互兜底路径）。
- **`tmux_mud.sh` 的 CJK 传输损坏再次命中**（非 bug，AGENTS.md §10.2 已
  有前例，和 ntii 记录的几乎一模一样）：`choose 均衡型` 通过
  `tmux_mud.sh` 发送后，本地 telnet 客户端掉进自己的 `telnet>` 命令提示
  符（"衡型"/"?Invalid command"），后续同样的 `choose 均衡型` 命令重发
  也再次触发。改用 `scripts/mudclient.py`（原始 socket，无本地
  telnet/pty）在新连线上重发完全相同的输入序列一次成功，且全程用
  `mudclient.py` 走完了注册到出生的完整仪式，验证了这确实是本地
  telnet CLI 的传输层问题，不是 `is_chinese()` 或注册逻辑的 bug。

**第二个角色 德标（`dbgtestx`）**：注册 → `choose 均衡型` → `select
光明磊落` → `wash`（先天天赋 膂力24/悟性21/根骨17/身法18）→ `born
扬州人氏`，全程零编译错误落地客店，`look`/`score` 正确。**这个角色专门
用来补做"quit/reconnect 隔一段真实时间"这一项**（避免重蹈"秦云舒"的覆
辙——本次测试前已经修好了 `force_quit()`，但为保险起见仍然选择"显式
`save` + 断线，不主动 `quit`"的路径）：`save` 后（"档案储存完毕。"）断
开连线，用 `Monitor`/后台等待了 80 秒真实墙钟时间（远小于 15 分钟
netdead 阈值，但足以验证真实断线重连，不是同一进程内的状态残留），重新
连线走了完整登录流程（"这个角色已经存在，请输入该角色的密码" → 密码验
证 → 正常登入，非静默重连），`look`/`score` 显示的房间与数值（膂力
24/悟性 21/根骨 17/身法 18）与断线前完全一致——确认标准的存档/重连路径
本身没有问题。全程 `debug.log` 复核：除了下面记录的两处已知/自愈的噪音
外没有新的 `Bad argument`/`couldn't find object`/级联错误。

### 管理员账号种子

`fluffos`（凌霄）/普通密码 `Mud@2026`、管理密码 `Admin@2026`，`(admin)`
权限已由既有 `adm/etc/wizlist` 条目（第 11 行 `fluffos (admin)`，来自更
早一轮 WASM 验证时播种的记录）授予——但该条目此前从未有对应的原生存档
（`data/login/f/`、`data/user/f/` 都不存在），本轮走正常注册流程种下。

- **密码字段未持久化**（和 ntii 记录的完全同一个现象）：注册流程走完
  性别选择、正常落地巫师休息室之后，`clone/user/login.lpc` 的密码字段
  （`password`/`ad_password`）没有被写入 `data/login/f/fluffos.o`（只有
  `purename`/`surname`/`id`/`body` 等字段），具体根因未深挖。按 §1.5 建
  议的"编辑存档数据而不是 code"方案处理：用**驱动自己的 `crypt()` efun**
  （不是外部工具算出来再猜）——写一个一次性脚手架 `adm/daemons/
  pwtest.lpc`，`create()` 里呼叫 `crypt("Mud@2026", "$1$fluffos1$")`/
  `crypt("Admin@2026", "$1$fluffos2$")` 并把结果写到日志档案，再把这两
  个真实由驱动算出的哈希直接写入 `data/login/f/fluffos.o` 的
  `password`/`ad_password` 字段。验证：`fluffos`/`Mud@2026` 登录成功
  （"重新连线完毕"），`update` 指令确认写 ACL 真实可用。测试完删除了
  `pwtest.lpc`。
- **`wizlist` 条目在测试过程中途丢失**（未完全查明根因，记录为观察
  项）：`update` 指令某一刻突然全部返回"什么？"（未识别指令），排查发现
  `adm/etc/wizlist` 里 `fluffos (admin)` 那一行不见了（`securityd.lpc`
  只在驱动启动时读取一次 `WIZLIST` 建立内存态 `wiz_status`，之后任何
  `set_status()` 调用都会用内存态整体重写这个文件——如果内存态在某个时
  点丢失了 `fluffos` 这一条，随后任何人触发的一次 `set_status()` 都会把
  这次"丢失"写实到磁盘）。怀疑和更早一次"用错误密码登录导致
  `destruct(ob)`"的失败尝试有关（有一次在密码字段还没修好之前尝试登录
  `fluffos` 触发了 `密码错误！` 断线），但没有在代码里定位到确切的
  "登录失败→撤销 wizlist 权限"的因果链，未在 code 层面动手，只是手动把
  `fluffos (admin)` 那一行重新加回 `adm/etc/wizlist`，重启驱动令
  `securityd.lpc` 重新读取生效（验证：`update` 恢复正常）。留给以后需要
  时再深挖确切根因。
- **`goto` 后跨驱动重启环境异常**：巫师账号用 `goto /d/city/nandajie1`
  离开巫师休息室后，`save`/`quit` 不会自动写入 `startroom`（`startroom`
  只在 `valid_startroom` 的房间里由 `save` 命令主动写入，`goto` 本身不
  设置），驱动重启后重新连线，环境变成"你的四周灰蒙蒙地一片，什么也没
  有。"（`environment(me)` 为 0，之前触发过一次 `update` 的
  `present(file, environment(me))` 传参 0 报"Bad argument 2 to
  present()"）。手动 `goto /d/wizard/wizard_room` 后自愈，纯粹是巫师测
  试工具使用习惯问题（`goto` 到非 `valid_startroom` 房间后没有存盘），
  不影响任何真实玩家路径，未修改代码。

### 未修复的观察项

- **`AUTO_SAVE` 宏定义了（`include/ntsql.h` 第 13 行）但全档案没有任何
  地方真的检查这个宏或据此设置周期性存档，`master.lpc` 也没有
  `shutdown()` apply 在驱动优雅关闭时统一存档所有在线玩家**：和 ntii 记
  录的完全同一个观察，未验证是否本轮又实测命中（本轮驱动重启前均已显式
  `save`/未挂起真实进度），只是确认这份档案本身也缺这套保障，留给以后
  评估。
- **心跳级冷启动开销**：随机任务系统修复后同样触发了 AGENTS.md §10.8
  记录的既有类别——`debug.log` 里出现约 34 处 `Eval interrupted`/
  `Too long evaluation`（`maximum evaluation cost` 700000，比 ntii 会话
  中途被外部调高到 5000000 的那份低）；均为懒编译大片地图触发的瞬时超
  时，自愈（后续同一账号照常登入/存档），不是可以钉死到具体 file:line
  的独立 bug，按 §10.8 惯例记录、未修。
- **`help newbie` 内容与实际注册流程不符**（水笙/`decide`/桃源四出口 vs
  实际的盘古/`choose`/`select`/`wash`/`born`）：和 ntii 记录的完全同一个
  内容/文档过时问题，不是程序 bug，未修改。

### 本轮结论

这是 `nte` 第一次真正的 §10.7 round-two 完整游玩测试。驱动升级后逐一核对
了 ntii 那份 §10.7 记录的四类 bug（`message()` 4 参数、`set_information()`
类型收窄、`log_error()` 警告泄露、`str[0..<N]` 切片 off-by），**全部独立
确认在 nte 上复现**，逐一用相同的最小改动修复并现场验证（含随机任务系统
修复后现场看到任务精灵开始正常产生任务）。`to_int()` 任务计数器修复复核
确认已在生产诊断点亮的三个文件里正确落地，并用一次性测试对象做了目标性
复现验证。**额外独立发现并修复了第五类 bug**：`force_quit()`（netdead 超
时自动收尾路径）无确认静默删除 <30 分钟账号，本轮测试自己的第一个角色
"秦云舒"就是真实受害者，修复后用 `user_dump(1)` 直接复现验证存档不再被删
除。完整走通了注册→性格选择→天赋分配→投胎→新手礼物→安全切磋→拜师
（organic 失败路径 + admin 捷径成功路径）→显式 save+真实断线 80 秒 + 重
连持久化（第二个角色）的连续会话。整体信心：高——核心系统（注册、任务奖
励防崩溃、随机任务生成、战斗、拜师两条路径、断线重连持久化、巫师权限）均
已验证正常，五类 bug 全部修复并现场验证，唯一遗留的是需要更大范围基础设
施改动（周期性存档、地图冷启动开销）或属于内容/设计判断（`help newbie`
过时文本、`goto` 后未设 startroom）而未动手的观察项，均已诚实记录。

## AGENTS.md §7.100 修复（2026-08-19，批次五）

`ROOM` 基类冗余 `replace_program(ROOM);` 自崩溃地雷（详见 AGENTS.md
§7.100）：3252 个房间文件的 `create()` 里紧跟 `inherit ROOM;` 之后
都有这一行多余调用，永久设下"待替换"标记，第一次对该房间对象绑
定闭包就会崩溃。自带建房工具 `clone/misc/roommaker.lpc` 的字符串
拼接代码生成模板里也烤了同一个地雷。

修复：脚本化删除所有房间文件里独立成行的 `replace_program(ROOM);`，
加上 roommaker.lpc 里手动摘除字符串拼接片段。`git diff --stat`：
3252 files changed，与预期精确吻合（85 处仍存在的匹配全部是既有
注释，未改动）。

验证：`build-debug` 驱动真实冷启动，端口 40115 正常监听，
`debug.log` 全程干净。既有管理员账号 `fluffos`/`Mud@2026` 登录正常
（巫师休息室/巫师会客室多房间走访 down/up），`quit` 干净退出，全程
无新增 "cannot replace"/"cannot bind" 日志行。

### ```§7.112``` residual-gap closure (2026-08-20)

Corpus re-scan (`grep -rl 'call_out("death_stage"' ... | filter for missing guard`) found unguarded `init()`-scheduled `death_stage()` call_out chain(s) in `d/death/npc/bai.lpc`, `d/death/npc/hei.lpc` that the original two-wave sweep (see AGENTS.md §7.112) missed -- same reconnect-triggered duplicate-chain bug, different filename/lineage. Added the standard `query_temp("death_stage_active")`/`set_temp`/`delete_temp` re-entry guard, adapted per file's own exit points. Compile-verified via `lpcc --batch`.

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

## 2026-08-21 深度功能测试 / Deep functional test round-four (AGENTS.md §10.7)

本轮补做上一轮 round-two 测试预算内没走到的三项真实游玩：真实战斗
死亡/复活、真实商店购物、真实拜师门派（非 `copyskill` 捷径）。用既
有巫师账号 `fluffos`（密码见上文，未变）和新注册的测试角色
`nteqzco`（`秦紫辰`，密码已设置，此处不重复记录明文）。

### 第六类 bug：`adm/simul_efun/file.lpc` 的 `log_file()` 未加
`assure_file()` 守卫（AGENTS.md §7.11 实例）

**本轮测试真实踩中，不是猜测。** 为准备商店购物测试，巫师账号
`clone /clone/money/gold` 时直接崩出一段执行时段错误：

```
执行时段错误：*Wrong permissions for opening file /log/nosave/clone for append.
"No such file or directory"
物件：/adm/single/simul_efun
呼叫来自：/cmds/wiz/clone.lpc 的 main() 第 76 行
呼叫来自：/adm/single/simul_efun.lpc 的 log_file() 第 13 行
```

`adm/simul_efun/file.lpc` 的 `log_file()`（第 11-14 行）直接
`write_file(LOG_DIR + file, text)`，完全没有目录守卫，而它自己的
`assure_file()` 帮助函式（第 16-38 行）就定义在正下方，却从未被呼
叫——AGENTS.md §7.11 已经记录过至少 6 个互不相关血统的同一拷贝粘
贴形状（`xajhxo`/`zjmudhell`/`ldtx`/`jyqxc2013fwq` 等）。归档从未
带上 `/log/nosave/` 目录（`.gitignore` 里 `libs/*/work/log/` 整棵
子树都不追踪，纯属驱动运行期产物），所以任何触发 `log_file()` 的操
作（`clone` 指令的审计记录只是第一个撞上的）都会抛出未捕获错误。
修复（第 11-15 行）：

```lpc
void assure_file(string file);

void log_file(string file, string text) {
  seteuid(ROOT_UID);
  assure_file(LOG_DIR + file);
  write_file(LOG_DIR + file, text);
}
```

**验证**：干净重启驱动（`debug.log` 543 行基线不变），巫师账号
`clone /clone/money/gold` 不再报错，正常显示"黄金复制成功，放在你
的物品栏。"。已提交（commit `4041d1f9ccb`）并推送。

**观察项，本轮未确认/未修**：同一 `write_file(..., 1)`（覆写模式，
AGENTS.md §7.11 记录过这个变体是硬抛错而不是优雅返回 0）硬编码形
状还出现在 `d/city2/npc/liu.lpc`、`d/city2/song/obj/{bingfu,
lingjian}.lpc`、`adm/daemons/ward.lpc`，全部写入
`/quest/quest_jun/song/...` 系列路径——`work/quest/quest_jun/song/`
目录在这份归档里确实不存在（`ls` 确认）。这是「宋朝守城/军粮」支线
任务（`d/city2` 是另一个城区，不在扬州新手区），本轮未实际触发（未
走到那条任务线），按项目一贯纪律不做未经现场复现的预防性修复，留
给以后走到 `city2` 那条任务线时再确认/修。`toptend.lpc` 的排行榜
写入路径（AGENTS.md §7.11 举过的另一个实例）本档案 `data/topten/`
五个文件已经存在，未受影响。

### 真实战斗 → 死亡 → 复活（非安全切磋）

**流氓头（南大街 `/d/city/nandajie1`）只支持非致命切磋——真正会死人的目
标是"财主大门"（`/d/city/caizhu`）的两只"大狼狗"（`wolfdog.lpc`）**：
`attitude: peaceful` 但 `init()` 里对任何进入房间的 interactive 玩家无
条件排 `call_out("kill_ob", 1, ob)`，真正会主动扑上来，且 `cmds/std/
kill.lpc` 对 NPC 目标确认没有任何安全闸门（和本次会话其余 10+ 个已确认
的同类库一致）——`kill wolf` 直接开打，不问玩家意愿。

**先用巫师账号 `fluffos` 亲身撞了一次**（未预期，属于真实巧合）：`goto`
到财主大门后，大狼狗自动发起攻击，`fluffos` 战斗数值偏低（管理员身份不
等于战斗强度），几个回合后被真实打死——完整死亡文本链（"你的眼前一黑"→
"你扑在地上挣扎了几下，腿一伸，口中喷出几口鲜血，死了！"）→ 正确传送到
死亡结界"鬼门关"（`/d/death/gate`）。因为 `fluffos` 是巫师，`d/death/
npc/bai.lpc`/`hei.lpc`（本档案自己上面 §7.112 补丁刚修过的那两个文件）
的 `init()` 都显式跳过巫师（`wizardp(previous_object())` 为真时直接
`return`），巫师复活改走另一对专门给巫师用的 NPC
（`wgargoyle.lpc`/`bgargoyle.lpc`，条件相反，只在 `wizardp` 为真时触
发）——**核对后发现这两个档案在全档案任何房间的 `objects` 映射里都从未
被引用，是死代码**（`grep -rn` 全档案确认），巫师死后事实上卡在死亡结
界里无法通过 NPC 触发复活（真正的出路是十殿阎罗 `yanluo.lpc` 的问答闯
关小游戏，或孟婆汤 `mengpo.lpc` 需要 `combat_exp >= 1000000000` 的巫师
专属高门槛，均为大型内容子系统，超出本轮验证范围，不影响任何真实玩家路
径，未改代码）。

**改用新注册的普通测试角色 `nteqzco` 正式补做这项测试**：走到财主大门
`kill wolf`，完整真实战斗回合序列（无安全脱战），气血耗尽后同样真实死
亡→传送鬼门关。这次角色不是巫师，`bai.lpc`（鬼门关的"白无常"）的
`init()` 正常触发，`death_stage()` 五阶段对话（间隔 5 秒/次）现场逐条
观察完整跑完，**这是本档案 §7.112 补丁（2026-08-20 才修的 `bai.lpc`/
`hei.lpc` 补丁）第一次被真实死亡流程实际触发**——五个阶段每一个出口分
支都正确调用了 `delete_temp("death_stage_active")`，没有卡死或重入，
最终 `ob->reincarnate()` + 传送到 `REVIVE_ROOM`（武庙）成功落地，
`score` 确认状态正常。中途因为验证 §7.11 修复而重启过一次驱动，测试角
色当时刚好处于死亡对话流程中途，重连后存档位置卡在"鬼门关"→"酆都城
门"（重启前的存档时间点，`clone/user/user.lpc` 的 `die()` 在
`::die()` 后立刻 `save()`，但 `death_stage()` 复活时的位置变更本身不
会主动存盘）——这是我们自己驱动重启造成的测试假象，不是代码 bug（没有
任何错误讯号），继续沿死亡对话链往深处走，`hei.lpc`（酆都城门的"黑无
常"）同一套五阶段对话也完整跑完，成功复活。全程 `debug.log` 复核干净，
零新增错误。

### 真实商店购物

用巫师 `clone /clone/money/gold` + `give gold to nteqzco` 的既定资助模
式（触发并修复了上面第六类 bug），给测试角色一两黄金（合一万文铜钱）。
到"醉仙楼"（`/d/city/zuixianlou`）"店小二"（`xiaoer2.lpc`，真实
`F_DEALER`/`vendor_goods` 商店）`buy baozi`：「你从店小二那里买下了一
个包子。」价格五十文铜板，购买后 `i` 确认找零正确（一万文 → 九十九两
白银 + 五十文铜钱 = 9950 文，换算无误），包子实物到手。全程无错误。

### 真实拜师门派（非 `copyskill` 捷径）

**修正上一轮 NOTES 的一个不准确表述**："拜师门派 NPC 都在扬州新手区以
外的深山"——这只对"独孤求败/黄裳/魁花/南海神尼"这几个特定"7.90 到
`to_int()` 复现"顺手查过的名字成立，不是全局结论。实际上有一个真正可拜
（`attempt_apprentice()` 已实现、`permit_recruit()` 门槛很低）的门派招
募 NPC 就在新手区city范围内：**丐帮的"空空儿"（`kungfu/class/gaibang/
kongkong.lpc`），固定放置在"丽春院"（`/d/city/lichunyuan`，南大街东
侧）**。他的 `attempt_apprentice()` 只检查 `permit_recruit()`（未曾背
叛过丐帮、未同时拜过别的门派）——对全新角色直接通过，没有任何战斗力/声
望门槛（相比之下 `kungfu/class/quanzhen/*.lpc`、`.../tangmen/tangfang.
lpc` 等"全真七子"/"唐门"级别的招募 NPC 大多要求已有相当技能等级或声望，
更适合已入门玩家的"晋阶"而非"新手首次拜师"）。

`kongkong.lpc` 会 `random_move()` 到处游荡，第一次到访扑空（"你想拜谁
为师？"——他人不在场），追过去几个房间也没追上；后来发现自己的命令用
错了目标别名——`set_name("空空儿", ({"kong kong", "beggar", "qi gai",
"kong"}))`，游戏内实际可用别名是"kong kong"（带空格）或"kong"，不是我
最初尝试的无空格"kongkong"（纯属操作失误，不是 bug）。改用 `bai
kong`，且巫师顺手 `clone` 了几个额外的"空空儿"副本帮忙"钉"在房间里避
免再次扑空，最终 `bai kong` 成功：

```
你想要拜空空儿为师。
空空儿说道：好吧，希望小兄弟能好好学习本门武功，将来在江湖中闯出一番作为。
空空儿决定收你为弟子。
你跪了下来向空空儿恭恭敬敬地磕了四个响头，叫道：「师父！」
恭喜您成为丐帮的第二十代弟子。
```

`score` 确认门派/师承字段真实写入：【门派】丐帮、【师承】空空儿、称号
"小叫化"/"丐帮第二十代传人"。全程无错误。

### 标准检查清单快速过一遍（§7.90/§7.100/§7.111/§7.112/§7.79/§7.108/§7.30 + 4 个已收尾的跨库 grep 模式）

全部干净，无新发现：

- **§7.90**：本档案上一轮已经记录过随机任务系统修复后的 `Eval
  interrupted` 冷启动噪音类别，本轮未见新增独立实例。
- **§7.100**：全档案 `grep -rn 'replace_program(ROOM)'` 只命中一处
  `d/heimuya/dating2.txt`（内容数据档案，非编译 `.lpc`，不受影响）。
- **§7.111**：`adm/single/master.lpc` 的 `standard_trace()` 第 277 行
  已经是 `error["object"] ? file_name(error["object"]) : "0"` 的守卫
  形状，干净。
- **§7.112**：`d/death/npc/{bai,hei,wgargoyle,bgargoyle}.lpc` 四个档
  案的 `death_stage()` 每个出口分支都正确清理重入守卫（详见上文真实死
  亡测试现场验证 `bai.lpc`/`hei.lpc`；`wgargoyle.lpc`/`bgargoyle.lpc`
  代码本身也干净但是全档案未引用的死代码，见上文）。
- **§7.79**：全档案没有任何裸 2 参数 `addn(` 呼叫，本条不适用。
- **§7.108**：`clone/user/user.lpc` 的 `reconnect()` 第 397 行已经有
  `enable_commands()`，干净。
- **§7.30**：`feature/skill.lpc` 的 5 个 accessor 已经是 2026-08-20
  当天早些时候的批次修复（`mapp(x) ? x : ([])`），干净。
- 四个已在别处全收尾的跨库模式：`combatd.lpc` 的 `bounce` 除零
  （grep 无命中）、`chacha.lpc`（`find` 无命中）、`natured.lpc` 的
  `!userp(ob[i])) destruct(ob[i])` 僵尸物件模式（grep 无命中）、
  `go.lpc` 的 `sizeof(exit[arg])` off-by-two（grep 无命中，现有形状
  是正常的 `undefinedp(exit[arg])` 检查）——全部干净。

### `force_quit()` 无确认删除 bug（上一轮第五类 bug）在 `ntii` 的核对结果：**未复现，`ntii` 本身是安全的**

按上一轮 NOTES 留下的"AGENTS.md 新 bug class 候选"去核对 sibling
`ntii` 的 `cmds/usr/quit.lpc`：`ntii` 的 `force_quit()`（第 165-189
行）**从未呼叫 `UPDATE_D->remove_user()`**——只有 `save()` +
`move(VOID_OB)` + `destruct(me)`，删除逻辑完全局限在交互式 `confirm()`
分支（第 191 行起，仅在玩家显式输入 `y` 时才触发）。也就是说 `ntii` 这
份档案的 `force_quit()`/`confirm()` 从一开始就是分离的两条独立逻辑，不
像 `nte`（修复前）那样把两条路径的销毁逻辑合并复用——**这不是同一个
bug 的另一个实例，是两份档案在这个函式上本来就是不同的代码形状**，
`ntii` 自己的 NOTES.md 也没有任何相关记录（说明它从未需要修）。范围缩
小：这个 bug class 候选在 `nte`/`ntii` 这对最近的 sibling 里只命中了
`nte` 一份，未来如果要跨库扫这个模式，`ntii` 可以从候选列表里排除，但
不代表其他更远的 ES2/Annihilator 血统档案同样安全，仍值得个别核实。

### 本轮结论

三项此前从未测试的真实游玩全部走通且验证正确：真实战斗死亡与复活（含
`§7.112` 补丁第一次真实触发验证）、真实商店购物（价格/找零/实物到手）、
真实拜师门派（非管理捷径，`bai kong` 完整走通，字段正确）。额外独立发
现并修复第六类 bug：`log_file()` 缺 `assure_file()` 守卫
（AGENTS.md §7.11 实例，已修复/验证/提交/推送）。标准检查清单全项通
过，无新发现。顺手核对 `ntii` 的 `force_quit()`，确认该档案本来就是安
全的代码形状，不需要移植修复。整体信心：高。
