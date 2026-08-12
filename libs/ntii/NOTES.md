
## WASM 修复摘要（迁移自 meta.json 的 group_note）

泥潭II——和 nte（泥潭二）同一个 ES2/Annihilator 架构家族，本轮改动的每一个档案（logind.lpc、named.lpc、versiond.lpc、dns_master.lpc、clone/user/user.lpc）都确认和 nte 修复前的版本逐字节相同——不是整个档案的重复（全库约 14-16k 个档案里有 10731 个不同，主要是游戏内容），但这一组基础设施档案是逐字共享的。直接复制了 nte 已验证过的修复档案，而不是重新推导相同的补丁：is_chinese() 的 GBK 字节区间修复、logind.lpc 里 check_legal_name() 没减半的长度界限（2 处呼叫点+姓名合并检查）、named.lpc 的 invalid_new_name() 空名字界限、uptime()<30 回环放行、dns_master.lpc（整个掏空）和 versiond.lpc（选择性掏空——13 个碰 socket 的函式，约 32 个呼叫者的非 socket 公开接口如 is_version_ok()/query() 保留）的 §7.52 socket 精灵掏空，以及 user.lpc 的 accept_kill() 里 is_killing() 物件/字符串不匹配（§7.50）。在这份档案自己身上独立通过一次真实的 WASM 注册验证：完整注册流程零编译错误完成，look/quit 也已验证（包括 quit 的新账号删除确认流程），wizlist 里的管理员 id（fluffos）重新注册后也被正确带到巫师专属起始房间。完整流程在排版格式化前后都验证过；格式化工具没有引入任何损坏（三类盲点检查都干净——和 nte 相同的两处大 diff，都已确认不是损坏：versiond.lpc 自己的掏空、combatd.lpc 合法的 if-else-if 讯息阶梯合并）。和 nte/nt6 相同的游戏内出生仪式内容关卡会影响刚注册角色的 score——不是 bug。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 55 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 2026-08-12 深度功能测试 / Deep functional test (AGENTS.md §10.7)

**这是这份档案第一次真正的 §10.7 round-two 完整游玩测试**（此前只有上面的
WASM 注册验证和 §7.86 跨库编译扫描，均未做过完整游玩）。ntii 本身不依赖
MySQL 才能游玩——虽然 `include/ntsql.h` 定义了 `DB_SAVE 1`，`databased.lpc`
的 `connect_to_database()` 呼叫的是这个驱动构建里真实存在的 `db_connect()`
efun（`~/src/fluffos/src/packages/db/db.cc`），但驱动没有编译进任何具体的
SQL 后端（`USE_MYSQL` 等未定义），所以 `db_connect()` 在没有真实数据库时
只是优雅地返回 `0`（不抛错），`db_set_player()`/`db_query_player()` 随之
优雅降级为 0，`TX_SAVE 1` 的文字档存档照常工作——和 `nitan170911`（真正
`#ifdef DB_SAVE` 硬依赖、本环境没装 MySQL 时连注册都会被挡下）不是同一种
情况，属于确认过的假阳性排除，不需要 nitan170911 式的本地 MySQL 基础设施。

### 驱动升级 + 干净启动

用新编译的 `~/src/fluffos/build-debug/src/driver`（含最新合并的 PR）启动
（`cd libs/ntii && ~/src/fluffos/build-debug/src/driver config.fluffos`）。
第一次干净启动就发现了严重的登录期错误洪流（见下「新发现并修复的 bug」第
1/3 条），修复后重新启动确认：`log/debug.log`（此档案自己的 debug-log 文件
名，见 `config.fluffos`）不再出现任何 `Bad argument`/`couldn't find object`/
级联错误，端口 40151 正常监听。本轮共重启驱动 4 次（每次修复后重新验证一
次干净启动），最后一次额外确认了 `config.fluffos` 的 `maximum evaluation
cost`（700000→5000000，本会话中途被外部改动，非本次改动，遵照惯例未回退）
生效后依旧干净启动。

### `to_int()` 任务计数器修复验证：一次性测试对象直接复现

会话上文诊断出的生产崩溃（`killer->query("questXX_times") % 500` 在拿到
损坏成 float 的属性值时因 `%` 运算符拒绝 float 左操作数而崩溃）已在
`combatd.lpc`（第 2476/2547/2619 行）、`whisper.lpc`（第 185/190/195/200
行）、`kungfu/class/ultra/{dugu,huang,kuihua,shenni}.lpc`（各自的
quest_count 计算行）确认为 `to_int(...) % 500` 的正确形状——`to_int()` 是
运行期真实转换，不是 `(int)` 那种仅编译期标注、这个驱动方言里不做任何运行
期转换的写法。

触发这段代码需要先在 whisper quest 链（独孤求败/黄裳/魁花/南海神尼四个门
派 NPC 各自的带口令任务）里拿到任务，而这些门派 NPC 本身都在扬州新手区以
外的深山（如峨嵋），预算内不现实（与 sibling `zhonghua2` 的结论一致）。
按 sibling 已验证过的方案，改用**一次性测试对象**（`adm/daemons/qftest.lpc`
临时脚手架，测试完已删除，`git status` 确认未残留）直接复现同一个表达式
形状：`mapping bad_data = (["k": 97467776479476432.000000]); mixed bad =
bad_data["k"];`（用 mapping 间接取值让编译期类型保持 `mixed`，忠实模拟
`query()` 返回值场景，而不是像 `float bad = ...;` 那样在编译期就被拒绝）。
用巫师账号 `fluffos` 的 `update` 指令触发 `create()` 直接调用测试函数：

- **修复前**（`bad % 500`，未加 `to_int()`）：
  ```
  执行时段错误：*Bad argument 1 to %
  Expected: int Got: 97467776479476432.000000.
  程式：/adm/daemons/qftest.lpc 第 7 行
  ```
  与生产崩溃报告的错误文本逐字一致。
- **修复后**（`to_int(bad) % 500`）：`update` 显示"重新编译...成功！"，
  `create()` 把结果写入 `/qftest_result.log`：`test_fix returned: 432`。
  独立验证 `int(97467776479476432.0) % 500 == 432`，与驱动内计算结果一致。

结论：`to_int()` 修复针对确切的报告故障条件被直接验证有效——不是通过一次
真实的完整任务达成，而是用完全相同的表达式与完全相同的损坏输入做了目标性
复现（targeted repro），不是仅靠代码阅读。

### 完整游玩测试

新注册角色 `qinyunxia`（秦云霞，女，均衡型，光明磊落，扬州人氏）：
`register` 邮箱 → `choose 均衡型` → `select 光明磊落` → `wash`（先天天赋
20/19/20/21）→ `born 扬州人氏`，全程零编译错误落地客店，`look`/`score`
均输出正确（无乱码/无错误）。武庙南贤处 `ask nan about gift` 拿到开站礼物，
`fen 悟性 4` 后 `score` 确认悟性 19→23（真实数值变化，不是摆设）。

- **先读了 `help newbie`**：文本描述的注册流程（水笙、`decide` 指令、桃源
  四个出口）和这份档案自己 `d/register/entry.lpc` 实际走的流程（盘古、
  `choose`/`select`/`wash`/`born`）明显不符——这是内容/文档过时问题，不是
  程序 bug，未做修改，只记录避免下一轮误判。
- **安全切磋机制**：南大街（`/d/city/nandajie1`）的"流氓头"
  （`attitude: peaceful`）接受切磋，`fight liu` 完整走完拳脚交替的回合序列，
  气血/精神耗尽后角色正确触发"看来该找机会逃跑了..."自动脱战逃入相邻房间，
  全程无崩溃。武庙本身是 `no_fight` 房间，北大街/中央广场沿途 NPC 多为
  `attitude: friendly`（`accept_fight()` 对 friendly 属性在气血精神 ≥75%
  时必定拒绝），与已知 sibling 结论一致。
- **拜师/门派——两条路径都测了**：organic 路径对"流氓头"（无 `family`
  属性）正确报错"流氓头既不属於任何门派，也没有开山立派，不能拜师。"，不
  崩溃；admin 捷径路径用巫师账号 `fluffos`（`goto` 传送到"流氓头"身边）执行
  `copyskill liu`，成功触发复制效果（"凌霄口中念念有词，只见一道红光笼罩
  了凌霄和流氓头。"），验证了这份档案的巫师武功复制捷径本身可用。真正拥有
  `family` 的门派 NPC（独孤求败等）都在远离新手区的深山，预算内未能走到，
  与 whisper quest 链的结论一致。
- **quit 保留窗口**：新账号 `qinyunxia` 因为在线时长不满 30 分钟，`quit`
  触发"退出该游戏将删除你的账号，你确定要放弃该帐号而退出吗？"——选择
  `n` 保留账号，改用 `save`（"档案储存完毕。"）+ 断线重连来验证持久化：
  `save` 后主动断开连线（关闭 `tmux_mud.sh` 会话），等待 20 秒后重新连线，
  走了完整登录流程（非静默重连），`score` 显示的数值与 `save` 前完全一致
  ——确认标准的存档路径本身没有问题。
- **`tmux_mud.sh` 的 CJK 传输损坏再次命中（非 bug，AGENTS.md §10.2 已有前
  例）**：`choose 均衡型` 通过 `tmux_mud.sh` 发送后，本地 telnet 客户端掉
  进了自己的 `telnet>` 命令提示符（"衡型" 和 "?Invalid command"），怀疑是
  "均"/"衡"/"型" 里某个字符触发的传输层问题（不是 `^]` 转义字节本身，UTF-8
  字节里没有 `0x1D`，具体机制未深究）。改用 `scripts/mudclient.py`（原始
  socket，无本地 telnet/pty）在新连线上重发完全相同的 `choose 均衡型` 一次
  成功。之后角色的中文姓名"云霞"里的"霞"字同样在早前通过 `tmux_mud.sh` 注
  册时被写入存档为损坏的替代字符（`data/login/q/qinyunxia.o` 里
  `"purename":"云�"`），独立用 `mudclient.py` 对一个全新的 throwaway
  测试账号（`cjktestx`，用完已删除其 `data/user/c/`、`data/login/c/` 存档）
  重放同样的"云"/"霞"输入，验证存档正确写入"霞"（无损坏）——确认这是本地
  telnet CLI 的传输层问题，不是 `is_chinese()`/存档逻辑的 bug，`qinyunxia`
  的姓名显示损坏是测试工具artifact，非游戏本身缺陷。

### 管理员账号种子

`fluffos`（凌霄）/ 普通密码 `Mud@2026`、管理密码 `Admin@2026`，
`(admin)` 权限已由既有 `adm/etc/wizlist` 条目（第 11 行 `fluffos
(admin)`）授予——但该条目此前从未有对应的存档（`data/login/f/`、
`data/user/f/` 都不存在），本轮走正常注册流程种下。种下过程中发现一个
需要绕过的行为：新注册流程走完性别选择、正常落地巫师休息室之后，
`clone/user/login.lpc` 的密码字段（`password`/`ad_password`）没有被
持久化到 `data/login/f/fluffos.o`（`purename`/`surname`/`id` 等其它字
段都正常存档，唯独密码字段缺失，具体原因未深挖——不排除
`logind.lpc` 的 `enter_world()`→`ob->save()` 链路里某处对 `ob` 的
temp/dbase 状态处理有微妙问题，值得未来某次深挖时留意，但没有找到确
凿的单一根因，未在 code 层面动手，改用 AGENTS.md §1.5 建议的"编辑存档
数据而不是code"方案：直接向 `data/login/f/fluffos.o` 写入
`crypt()`（`$1$` MD5-crypt 格式，与这个驱动构建的 `f_crypt()`
兼容）生成的 `password`/`ad_password` 字段。写入后验证：`fluffos`/
`Mud@2026` 登录成功（"重新连线完毕"），`update /adm/daemons/eventd`
成功触发重新编译（确认 `(arch)`/`(admin)` 写入 ACL 真实可用，不只是
`(admin)` 招牌），符合 §1.5 第 3 步的验证要求。

### 新发现并修复的 bug

1. **`adm/simul_efun/message.lpc` 的 `message()` 包装函式非 varargs、
   3 参数呼叫时缺省的第 4 参数 `exclude` 变成裸 `int(0)`，被逐字转发给
   `efun::message()`，该 efun 的第 4 参数类型是 `void | object |
   object*`，拒绝 `int(0)`（AGENTS.md §7.61/§7.88 已有的 bug class）**：
   第一次干净启动就在注册期间狂刷"Bad argument 4 to EFUN message()
   Expected: object, array, Got: int(0)."——`channeld.lpc`/`questd.lpc`
   等多处用 3 参数呼叫 `message()`（如 `tell_object()`/`write()` 内部）。
   修复（`adm/simul_efun/message.lpc` 第 315-317 行）：
   ```lpc
   varargs void message(mixed arg, string message, mixed target, mixed exclude) {
     efun::message(arg, message, target, exclude || ({}));
   }
   ```
   修复前后各重启驱动一次对比验证：修复前 1926 行错误日志（含级联的"错误
   讯息被拦截"自我报错循环），修复后同样的启动流程仅 543 行、零 `Bad
   argument` 错误。

2. **`inherit/misc/quest.lpc` 的 `set_information()` 包装函式把第二参数
   声明为 `string`，但它转发的 `adm/daemons/questd.lpc`
   `QUEST_D->set_information(object, string, mixed)` 本身已经正确接受
   `mixed`——`clone/quest/{search,capture,shen,supply,defend,deliver,
   judge,trace,explore}.lpc` 九个任务档案全部用闭包 `(: ask_xxx :)`
   （合法匹配 `mixed`）呼叫它，被这个过窄的本地包装函式硬性拒绝，编译
   错误"Bad type for argument 2 of set_information ( string vs
   function )"，导致这九种随机任务在每次 `new()` 时都产生"无程式"的空
   壳物件，`heart_beat()` 里持续静默报错"No program in object
   '/clone/quest/xxx'!"，整个随机任务生成子系统从这份档案第一次编译起
   就完全瘫痪，没有任何启动期崩溃症状（与 AGENTS.md §7.81 记录的
   `nt1`/`yhwhpublicfi`/`zjdy2008wzb` 三个先例完全同形，本次是第四个独
   立确认的实例，且是 nitan 血统家族内的首例）。修复（`inherit/misc/
   quest.lpc` 第 111 行）：`string info` → `mixed info`，单文件改动同
   时修好全部九个任务档案。**现场验证**：用 `fluffos` 账号对全部十个
   `clone/quest/*.lpc`（含 `avoid.lpc`）逐一 `update`，全部"重新编译
   ...成功！"；紧接着的自然 `heart_beat()` 周期里，亲眼看到多条此前从
   未出现过的"【系统报告】任务精灵：进程(JUDGE)创建了一个任务。"/
   "进程(DELIVER)利用木器创建了一个任务。"/"进程(SUPPLY)在群玉楼地点利
   用打手创建了一个任务。"/"进程(EXPLORE)利用猫之眼和唐掌柜创建了一个
   任务。"/"进程(TRACE)创建了一个任务。"/"进程(SHEN)创建了一个任务。"
   ——这是这份档案的随机任务系统第一次真正产生任务，修复效果立竿见影。

3. **`adm/single/master.lpc` 的 `log_error()`（驱动对每一次编译诊断的
   apply，包括纯 warning）无条件把讯息转发给 `this_player()`/
   `this_player(1)`，没有区分 warning 和真正的 error（AGENTS.md §7.103
   已有的 bug class）**：新注册流程期间，`/include/globals.h:4` 的
   "Unknown #pragma, ignored." warning 在几乎每一个被懒编译的档案
   （`autoload.lpc`/`business.lpc`/`updated.lpc`/`examined.lpc`/
   `newsd.lpc`/`analectad.lpc`/`toptend.lpc`/`moneyd.lpc` 等十几个）上
   都原样刷屏给刚注册的新玩家，每条都带着吓人的"编译时段错误："前缀
   （其实只是无害的编译警告）。修复（`adm/single/master.lpc` 第
   181-190 行）：仿照 §7.103 的既有修复形状，加 `strsrch(message,
   "warning:") == -1` 守卫——纯 warning 不再转发给玩家（仍然写入
   `log` 档案供巫师查阅），真正的 error 转发行为不变。修复前后各重
   启一次对比：修复前注册流程刷了十几条"编译时段错误：...warning:"，
   修复后同样的注册流程干干净净、零警告刷屏。

4. **`str[0..<N]` 后缀切片的 off-by-(N-1) 错误——`[0..<3]` 只删掉 2 个字
   符而不是预期的 3 个字符（这个驱动的 `str[0..<n]` 区间保留
   `sizeof(str)-n+1` 个字符而不是 `sizeof(str)-n` 个），AGENTS.md §7.80
   已有的 bug class**：全档案扫描找到 7 处命中，除已知的 `.lpc`（4 字
   符）后缀场景（§7.80 原始形状）外还发现了 3 处此前未记录的同款变体：
   - `adm/daemons/eventd.lpc` 第 22 行、`adm/daemons/storyd.lpc` 第 50
     行：`get_dir(*.lpc)` 结果用 `[0..<3]` 剥离扩展名，本该剥掉 4 个字
     符（".lpc"）却只剥掉 2 个（"pc"），`event_name`/`story_name` 里每
     一项都带着损坏的尾巴（如 `"emei.lpc"` → `"emei.l"`），
     `collect_all_event()`/`init_story()` 后续的 `call_other` 全部指向
     不存在的路径，事件/故事子系统在这份档案上同样从未真正工作过（和
     §7.80 记录的 `nt1`/`zjdy2008wzb` 完全同形，本次是第三个独立确认
     实例）。
   - `adm/npc/luban.lpc` 第 1431/2573 行（`demolish_room()`/
     `create_room()` 清理 `DBASE_D` 残留数据时用同样错误的切片计算
     `.lpc` 文件名）、`cmds/wiz/mem1.lpc` 第 80 行（巫师内存诊断指令
     `check_mem` 剥离用户输入里的 `.lpc` 后缀）、`cmds/adm/refsum.lpc`
     第 37/43 行（`召唤列表` 重建指令，用切片结果作为存到
     `can_summon/` 属性里的物件路径）——都是 §7.80 记录的同一个"配对
     已知固定后缀（`.lpc`）时手误按后缀长度而不是长度+1 来切片"检测
     模式命中，修复统一改成 `[0..<5]`。
   - 均验证 `update` 干净编译（`eventd`/`storyd` 用 `fluffos` 账号确认
     `create()` 里不再报 `couldn't find object` 错误；`luban`/`mem1`/
     `refsum` 三个未做深度功能验证的档案至少确认编译通过、没有语法层
     面的问题）。

### 未修复的观察项（不确定是否属于本轮范畴，或修复代价超出"小修补"）

- **`AUTO_SAVE` 宏定义了（`include/ntsql.h` 第 13 行"是否定时为玩家保存
  档案，定义了就表示要"）但全档案没有任何地方真的检查这个宏或据此设置
  周期性存档的 `call_out`/`heart_beat`**：`master.lpc` 也没有
  `shutdown()` apply 在驱动优雅关闭时统一存档所有在线玩家。实测命中：
  测试中途为排查 `fluffos` 密码存档问题而重启了一次驱动（用 `kill`
  发的是 SIGTERM，不是 SIGKILL），`qinyunxia` 在重启前刚用礼物加过的
  4 点悟性（19→23）在重启后回落到 19——因为那次改动之后一直没有显式
  `save`/`quit` 过。这是这份档案本身缺少自动/优雅关闭存档保障，不是
  这次测试引入的新问题；只是记录下来，避免以后的 pass 把杀掉驱动进程
  当成安全操作，或者误把"重启后数值倒退"当成别的什么 bug 来排查。是否
  要真的实现一套心跳周期存档机制超出了"小修补"的范畴（需要决定间隔、
  是否影响性能等设计判断），未动手，留给以后需要时再评估。
- **随机任务系统修好之后，`place_npc()` 把此前从未被任何测试角色走到过
  的整片新区域（如星宿/`d/xingxiu/`、图龙/`d/tulong/`）在同一次心跳里
  连锁懒编译，触发多次"Too long evaluation. Execution aborted."**：这
  是 AGENTS.md §7.90 记录的既有类别（"ambient NPC 漫游/系统行为强制懒
  编译大片地图，冷启动级联编译撑爆 `maximum evaluation cost`"）的又一个
  实例，不是本轮改动引入的新缺陷，也不是可以钉死到具体 file:line 的独
  立 bug——是这份档案随机任务系统一旦真正开始运作（本轮才第一次实现）
  就会暴露的、更大范围的地图冷启动开销问题，超出单文件修补的范畴，
  按 §7.90 惯例诚实记录、未修。会话中途 `config.fluffos` 的
  `maximum evaluation cost` 被外部从 700000 调到 5000000（非本次改动），
  重启验证过依旧干净启动，但没有专门验证这个提升是否足以消除这类冷启
  动级联报错。
- **`cmds/usr/score.lpc` 对没有 `born`（走完投胎仪式）的角色一律拒绝
  `score`（"还没有出生呐，察看什么？"）**：`fluffos` 巫师账号注册后直
  接落地巫师休息室、从未经过 `d/register/entry.lpc` 的
  `choose`/`select`/`wash`/`born` 仪式，因此 `score` 对它报错——这看起
  来是内部自洽的既有设计（`score` 面向的是走完角色创建的凡人角色，巫师
  有自己的管理工具），不属于 §10.7 明确排除的设计判断范畴之外的东西，
  未作修改，只记录避免误判成权限系统坏了。
- **`help newbie` 的文本内容（水笙/`decide` 指令/桃源四个出口）与这份档
  案实际的注册流程（`d/register/entry.lpc` 的盘古/`choose`/`select`/
  `wash`/`born`）不符**：内容/文档过时问题，不属于程序 bug，未修改。

### 本轮结论

这是 `ntii` 第一次真正的 §10.7 round-two 完整游玩测试。驱动升级后，第一次
干净启动就命中了一个会在几乎每一次注册流程里刷屏的 `message()` 4 参数
bug——修复后重新验证干净启动。`to_int()` 任务计数器修复通过一次性测试对象
的目标性复现（不是真实完整任务，但用了完全相同的表达式和损坏输入）确认
生效。完整走通了注册→性格选择→天赋分配→投胎→新手礼物→安全切磋→拜师
（organic 失败路径 + admin 捷径成功路径）→断线重连持久化的连续会话。除已
知的 `message()` 4 参数 bug 外，还独立发现并修复了三类此前未在这份档案上
记录过的、AGENTS.md 已有先例的 bug class：`log_error()` 编译警告泄露给
玩家（§7.103）、`str[0..<N]` 后缀切片的 off-by 错误（§7.80，新增 3 处此
前未记录的变体命中）、以及影响面最大的 `set_information()` 类型收窄导致
整个随机任务生成子系统从这份档案第一次编译起就完全瘫痪（§7.81，nitan 血
统家族内首例，现场验证修复后任务系统立即开始正常产生任务）。整体信心：
高——核心系统（注册、任务奖励防崩溃、战斗、拜师两条路径、断线重连持久
化、巫师权限）均已验证正常，新发现的四类 bug 全部修复并现场验证，唯一
遗留的是需要更大范围基础设施改动（周期性存档、地图冷启动开销）或属于
内容/设计判断（`help newbie` 过时文本、巫师账号 `score` 限制）而未动手
的观察项，均已诚实记录。
