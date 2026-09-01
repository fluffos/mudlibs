
## WASM 修复摘要（迁移自 meta.json 的 group_note）

侠客行I（"The Quest of Oriental Chivalry"），XiaKeXing Gaming Group 1996-1999，MudOS v22b25 世系，由 sdong 移植。WASM 修复：（1）§7.52 类的从零手写 HTTP 服务器：adm/daemons/network/http.lpc（经典的 Truilkan/Jacques Interstice httpd.c，AGENTS.md 里 mnhf 已经记载过同一血统）直接呼叫 socket_create()/socket_bind()/socket_close()，没有任何存在性判断，导致整个精灵在 WASM 下编译失败。没有任何其它档案呼叫这个精灵（已 grep 确认零外部呼叫者），按 §7.52 的默认做法，把每一个碰 socket 的函式（setup()、write_data_retry()、store_client_info()、listen_callback()、close_connection() 里的 socket_close 呼叫）都掏空成 no-op，而不是逐个呼叫点修补。（2）adm/daemons/logind.lpc 里 §8.1 类的 check_legal_name() bug：按字节数算的长度界限（2-8，本意是 1-4 个字符）加上一个 i%2 奇偶门槛，外加一个破坏性的"修正"骇客（对任何被那个——已经被禁用、注释掉的——is_chinese() 检查标记的字符做 name[j]+=128），在 UTF8 码点索引下会把合法名字搞坏——已把长度界限改成按字符数（1-4），并彻底删掉 +=128 这个变异（原本基于 is_chinese() 的拒绝逻辑本来就已经被原作者注释掉了，这里只是去掉遗留下来的破坏性副作用，没有恢复任何主动校验）。adm/simul_efun/chinese.lpc 的 is_chinese() 本来就是正确的逐码点检查。管理员账号通过 securityd.lpc 真正持久化的存档档案（data/securityd.o，一份纯文本的存档映射字面量，不是那两个从未在实际代码里被读取过的遗留 adm/etc/wizlist.h/wizlist 文本档案）播种——把 fluffos 同时加入 wiz_status（'(admin)'）和 wiz_sites（'.*'，不受限，匹配既有的 'npc' 引导条目的写法），因为 logind.lpc 的 get_id() 会对任何巫师等级的 id 呼叫 SECURITY_D->valid_wiz_login()，如果 euid 在 wiz_sites 里完全没有条目就会拒绝登录，不管 get_status() 的等级是什么——既有的 waiwai/xgslxz 管理员账号被锁定在特定的 192.168.0.40 地址，如果照抄会挡住 WASM 测试/127.0.0.1 的登录。注册流程在一次连续的 WASM 客户端会话里完整验证过：GB/BIG5 编码选择→英文 id→y/n 创建确认→中文名字→密码+确认→接受天赋赠礼（y）→电子邮件（id@address 格式）→性别→带着完整角色属性表和可用的 score/look 指令进入游戏世界，全程没有任何意外错误。管理员权限已直接通过 'wizlist' 指令输出确认"目前权限：(admin)"，没有站点检查拒绝。LPC 格式化工具对全部 8096 个档案运行（写入 8021 个，24 个因为杂乱的历史代码报错，51 个未改动）；还原了 1 个档案（d/taihu/gumu/houtang.lpc）确认有转档之前就存在（作者一方，早于本轮）的未结束字符串损坏（它的 item_desc 映射里两处 'hua1'/'hua2' 条目缺少闭合引号），被格式化工具的分词器进一步重新加了空格。没有 :: 父类呼叫拆分命中，没有 case 标签带尾随注释的候选。全部 7 个 map.lpc 档案确认内容完全相同（只是空白差异）。格式化后用同样的完整注册流程重新验证过——干净，管理员权限依然是 (admin)，没有站点检查拒绝。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 39 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（2026-08-17，round one）——干净通过，零 bug

第一次对这份档案做完整 §10.7 深度游玩测试（注册 → 探索 → 战斗 →
死亡 → 留言板发帖），全程零真实 bug。

**批量编译扫描先行**：`lpcc_check.sh` 全档案 8096 个文件（933 个通
过，144 个失败）——绝大多数失败是孤立的孤儿内容/未接线的网络精灵
（和早前 WASM 阶段已记录的模式一致，未逐个重新核实每一个）。其中
4 处（`/adm/daemons/languanged`、`/adm/daemons/languaged`）撞上
`Eval interrupted: ... cost limit reached, limit: 700000 usec.`——
但读过 `languaged.lpc` 的 `create()`（只有两个单行 `read_file()`
呼叫，完全不昂贵）后怀疑是 lpcc 批量编译共享同一进程、跨数千个档
案累积 eval-cost 债务导致的**纯批量扫描artifact**，不是真实可达
的 bug（`languanged`——带错字的那份——甚至没有任何调用者，是孤
儿档案；只有 `languaged` 被 `feature/message.lpc`/`logind.lpc`/
`adm/simul_efun/message.lpc` 真正呼叫）。

**现场验证排除了这个疑虑**：重开一个全新驱动进程，完整走一遍真实
注册流程（GB/BIG5→英文id→y/n→中文名字→密码+确认→天赋赠礼→电子
邮件→性别→进入游戏世界），全程会自然触发 `logind.lpc`/
`feature/message.lpc` 里对 `languaged.lpc` 的呼叫（每次 `message()`
广播都会用到），也会触发本档案角色基类 `inherit/char/char.lpc` 自
己的冷启动首次编译——两者都干净通过，`debug.log` 全程零
`cost limit reached`。**结论：这 4 处失败确认是批量扫描本身的产
物，不是真实 bug，未修改任何配置或代码。**

**发现的真实设计（非 bug）**：新注册的普通玩家会先落在"侠客岛挂
名处"，`score`/`hp`/`i` 等状态指令在这个阶段**返回空字符串**——
不是崩溃，是因为角色还没走完这份档案自己的游戏内"register
<email>"验证步骤（和账号创建时填的 email 是分开的两步）；完成
`register` 后，服务器会主动断线（"一封包括随机密码的 email 将在
一分钟内寄给您……请用新的密码连线"），要求玩家用新密码重新登录。
这个测试环境收不到真实邮件，所以没能验证一个走完这整套流程的普通
玩家账号；改用巫师账号（`fluffos`，`wiz_sites` 播种为 `.*` 不受
限）来绕过这道验证——巫师直接跳过挂名处，落在真实的沙滩起始房间，
`score`/`hp`/`i` 立即可用（完整属性面板正确渲染）。

**战斗/死亡**：`goto /d/island/icefire3`（冰火岛），两只"白熊"
（`attitude: aggressive`）当场主动攻击，完整交手数回合直至角色死
亡（"你倒在地上，挣扎了几下就死了"），正确移动到死亡区"鬼门关"
（`/d/death/gate`），谣言广播正确。**复活**：确认 `/d/death/npc/
wgargoyle.lpc` 的自动复活 `call_out` 链**明确排除巫师**
（`init()` 里 `if (... || wizardp(previous_object())) return;`）
——所以巫师角色死后不会自动复活，这是有意设计（巫师通常有独立的
复活/immortal 处理），不是本档案独有的 bug；受限于邮件验证步骤
无法用真正的普通玩家账号走完自动复活流程，留给以后有办法收发测
试邮件时再验证。

**留言板**：`goto /d/xiakedao/dadong`（大山洞，有"侠客岛告示牌"），
`post <标题>`（标题跟在同一行）→ 内建行编辑器（`结束离开用 '.'`）
→ `read new` 验证标题、正文、作者全部正确落盘。

测试账号（`fluffos`、`qintestk`）存档留在 `data/` 下作为佐证，均
为未跟踪文件，未纳入本次提交。

## 深度功能测试（2026-08-19，round four）——补完普通玩家自动复活验证，顺带修好巫师 `call` 指令

本轮的主要目标是解决 round one 留下的唯一缺口：**普通玩家（非巫
师）的死亡自动复活流程**，当时因为"卡在电子邮件验证"而没能用真
正的普通玩家账号走完。

**先弄清楚"电子邮件验证"到底是什么**：读了 `d/xiakedao/npc/
mux.lpc`（挂名室的登记使 NPC，`do_register()`）和它调用的
`adm/daemons/regid.lpc::register_char()`，发现这压根不是一个需要
真实 SMTP 的外部依赖——`register_char()` 只是：①把 `registered`
字段设成 `"yes"` 并存盘（这才是解锁 `score`/`hp`/`i` 等指令的真正
开关），②生成一个 5 字母随机密码，③用 `write_file()` **把这个明
文密码写进本地档案 `/queue/register`**（`REGDATA`，一行
`id:email:密码`），④告诉玩家"一封邮件将在一分钟内寄给您"然后主
动把连线断掉。全程没有任何 SMTP/mail-send efun 呼叫——这一行
`write_file()` 显然是设计给一个从未随这份档案一起出现的外部发信
脚本用的，纯粱本地文本档案，**测试环境完全可以直接读这个档案拿
到明文密码**，不需要真的收发邮件。

**"挂名处"的真实流程比 round one 记录的更复杂一层**：新注册玩家
落地的房间其实是 `/d/xiakedao/shatan1.lpc`（"沙滩"，张三/李四两
个引路 NPC 之一），而不是有 `register` 指令的那个房间；这个房间
的 `block_cmd()` 白名单里根本没有 `register`，只有 `follow`——
必须先 `follow zhang san`（或 `follow li si`）才能被带到真正挂
着"登记使"木老 NPC、允许 `register <email>` 指令的
`/d/xiakedao/register.lpc`（"侠客岛挂名处"）。round one 用巫师账
号绕过了整段流程，所以没碰到这层，这次用真正的新建账号
`qinfuhuo`/`test1234` 走了一遍完整流程才发现。

**完整验证过程**：①`register`创建新账号 `qinfuhuo`（GB→英文
id→中文名"秦复活"→密码→天赋→email `qinfuhuo@example.com`→
gender），落地 `shatan1`；②`follow zhang san` 被带到挂名处，
`register qinfuhuo@example.com` 成功，服务器提示"一封包括随机密
码的 email 将在一分钟内寄给您……"并断线；③直接读
`work/queue/register`，拿到明文新密码 `cecbx`；④用新密码重新连
线，确认 `registered` 已经生效——`score`/`hp`/`i` 全部正常返回完
整数值面板（不再是空字符串），落地到真正的新手海滩（渔夫 NPC 那
个"沙滩"，`/d/xiakedao/shatan`）。**至此电子邮件验证缺口彻底解
开，且证明它从来都不是一个真正的外部依赖。**

**死亡与自动复活的真实验证**：用巫师账号（新建 `fluffos`，
`wiz_sites` 早已播种为 `.*`）执行 `call qinfuhuo->move("/d/island/
icefire3")` 把 `qinfuhuo` 传送到冰火岛（跟 round one 巫师死亡测
试同一个危险房间，两只 `attitude: aggressive` 白熊），几秒内被
白熊咬死（"你倒在地上，挣扎了几下就死了"），正确移动到
`/d/death/gate`（鬼门关），`d/death/npc/wgargoyle.lpc`（白无常）
的 `init()`——因为 `qinfuhuo` 不是巫师，没有触发 wgargoyle 的巫师
排除分支——正常挂上 `death_stage` call_out 链，5 句对白按 30 秒
+4×5 秒的节奏播完，随后 `reincarnate()` 被呼叫：精/气/精力/内力
全部重置回满血，物品正确按 `DROP_CMD->do_drop()` 掉落在死亡房间，
角色被送回 `/d/xiakedao/shatan`（因为 `xkd/set` 标记为真）。断线
重连复核：`score` 显示"你到目前为止总共死了 1 次，其中 1 次是正
常死亡"，数值面板全部满血，`debug.log` 全程无任何报错——**一次
真实、完整、无 bug 的普通玩家自动复活循环，确认为设计正确**。

**过程中顺带抓到一个真实 bug（已修复并现场验证）**：第一次尝试
`call qinfuhuo->move(...)` 时，巫师 `call` 指令直接崩溃：
```
执行时段错误：*Wrong permissions for opening file /log/nosave/CALL_PLAYER.lpc for overwrite.
"No such file or directory"
```
这是 AGENTS.md §7.11（"未存在的运行期目录导致 write_file() 静默/
崩溃中止"）这个已知病灶家族的一个新实例：`cmds/wiz/call.lpc` 只
要目标物件是 `/clone/user/user`（也就是任何玩家角色本体——这是
`call` 指令最常见的使用场景），就会无条件呼叫
`log_file("nosave/CALL_PLAYER", ...)` 做审计记录；而这份档案的
`adm/simul_efun/message.lpc::log_file()` 是裸的
`efun::write_file(filename, str, 1)`（第三参数 1 = overwrite 模
式，会硬抛错而不是静默返回 0），完全没有 `assure_file()` 防护，
而这份档案从未附带 `/log/nosave/` 目录——导致巫师 `call` 指令**只
要目标是任何玩家角色就必崩**，这是巫师工具箱里最常用的指令之一。
检查过实际死亡流程本身（`feature/damage.lpc::die()` 里
`log_file("PLAYER_DEATH"/"PKILL_DATA", ...)`）——这几处目标都是
`/log/` 根目录下（已存在），不受影响，所以死亡/复活主线没被这个
bug 波及，只有巫师 `call` 指令本身。修复：仿照 AGENTS.md §7.11 里
反复验证过的标准做法，在 `message.lpc` 顶部加一行 `void
assure_file(string file);` 前向声明（因为 `assure_file()` 定义在
后编译的 `file.lpc` 里），并在两处 `efun::write_file()` 前各加一
行 `assure_file(filename)`/`assure_file(filename2)`。现场验证：
修复前 `call qinfuhuo->query("name")` 直接崩溃报错；重启驱动加载
修复后同一条指令正常返回 `"秦复活"`，之后的
`call qinfuhuo->move(...)` 也正常执行，`/log/nosave/` 目录被自动
创建。**这个具体实例未做跨库扫描**（不在本轮任务范围内），但同样
的 `log_file()`/`assure_file()` 缺口在这份档案的
`adm/simul_efun/message.lpc` 里只有这一处未加保护，`file.lpc` 自
己的 `assure_file()` 实现本身没问题。

**本轮 checklist 快速核对**（均为已跨库扫描过的项目，逐一确认本
档案没有异常）：
- §7.111（`master.lpc`/`standard_trace()` 的 `file_name(0)` 崩
  溃）：**不适用/天然安全**——`work/adm/single/master.lpc` 的
  `standard_trace()` 用的是 `%O` 格式化 `error["object"]`，根本没
  有呼叫 `file_name()`，不是这个漏洞的易感形状。
- §7.112（`init()` 里无重入保护的 `call_out("death_stage", ...)`
  链）：`d/death/npc/wgargoyle.lpc`、`bgargoyle.lpc` 以及
  `d/bwdh/sjsz{,2,3}/{east,west}_xiangfang.lpc` 全部已经带有
  `query_temp("death_stage_active")` 防护——干净。唯一没加防护的
  `d/death/npc/wgargoyle1.lpc` 经确认是**死代码**：全档案没有任何
  地方 `clone`/引用它，鬼门关（`gate.lpc`）和另一处死亡入口
  （`gateway.lpc`）分别用的是已加防护的 `wgargoyle.lpc`/
  `bgargoyle.lpc`，不影响任何真实游玩路径，未做修改。
- §7.113（断线重连不恢复 `heart_beat`）：干净——
  `adm/daemons/logind.lpc::reconnect()` 呼叫
  `user->reconnect()`，`clone/user/user.lpc::reconnect()` 在玩家
  本体上无条件 `set_heart_beat(1)`，属于已确认的正确谱系。
- §7.114（继承 mixin 里的 `private` `input_to()` 回调）：干净——
  `feature/edit.lpc` 的 `input_line()` 没有 `private` 修饰符。
- §7.115（`QUEST` 宏指向不存在的档案）：**不适用**——本档案
  `include/globals.h` 里根本没有 `QUEST` 宏定义，全档案也没有
  `QUEST->` 呼叫点。
- §7.90（eval-cost 默认值）：已是 `5000000`（round one 已修）。

测试账号 `qinfuhuo`（已注册、已完整走过死亡复活）和 `fluffos`（巫
师，用于 `call`/`goto` 操作）存档留在 `data/` 下作为本轮佐证，均
为未跟踪文件（`work/data/login|user/{q,f}/*.o`），未纳入本次提交；
`work/queue/register`、`work/log/` 均已被仓库 `.gitignore` 整体排
除，无需清理。

## §7.100 sweep (2026-08-19)

Fixed the corpus-wide `inherit ROOM; ... replace_program(ROOM);` redundant-replace bug (AGENTS.md §7.100). 2124 live occurrences deleted: 2123 via scripted sweep (`fix_710_room.py`), plus 1 hand-fixed roommaker-tool template (`clone/misc/roommaker.lpc`, simple string-builder variant). ~284 already-commented-out instances left untouched. Checked `work/data/` (incl. `d/shenlong/data/`) for real `.lpc` source false-negatives per this batch's standing gotcha — none found. Verified via `build-debug` driver boot: clean compile, zero new "cannot replace"/"cannot bind" debug.log lines; confirmed serving via raw-socket connect on port 40140. Pre-existing untracked test-account debris confirmed left untouched.

### ```§7.112``` residual-gap closure (2026-08-20)

Corpus re-scan (`grep -rl 'call_out("death_stage"' ... | filter for missing guard`) found unguarded `init()`-scheduled `death_stage()` call_out chain(s) in `d/death/npc/wgargoyle1.lpc` that the original two-wave sweep (see AGENTS.md §7.112) missed -- same reconnect-triggered duplicate-chain bug, different filename/lineage. Added the standard `query_temp("death_stage_active")`/`set_temp`/`delete_temp` re-entry guard, adapted per file's own exit points. Compile-verified via `lpcc --batch`.

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

## §7.19 enable_player() reentrancy fix (2026-09-01)

Corpus-wide mechanical fix (AGENTS.md §7.19, Batch F of 6). `feature/command.lpc`'s
`enable_player()` had no reentrancy guard at all: an NPC's `init()` (e.g.
`d/zhongnan/npc/killer.lpc`'s first-time `!query_temp("copied")` branch) reaches
`setup()` -> `enable_player()` -> `enable_commands()`, which the driver docs and
this project's own live-verified prior findings (mhxy/wuhanzhan) confirm can
re-invoke the same object's `init()` synchronously while the original call is
still on the stack -- genuine reentrancy, "Too deep recursion" on a room's first
visit. `feature/damage.lpc`'s `revive()` and `cmds/std/sleep.lpc`'s
`wakeup()`/`wakeup2()` also re-invoke `enable_player()` while already `living()`,
so a bare `living()` guard would have broken legitimate revive/wakeup re-enables.
Fixed with a true reentrancy flag (`nosave private int in_enable_player_now;`,
set at entry, cleared before the function's single return path), matching the
reference fix on `mhxy`. Verified via single-file `lpcc --batch` PASS.
