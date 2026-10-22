
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

## 深度功能测试（2026-09-04，round three，shop + 拜师）

新角度：扬州醉仙楼购物 + 丐帮空空儿拜师。sibling `nte` 在 2026-08-21
round four 已经走过 `buy baozi` + `bai kong`；`ntii` 自己的 2026-08-12
round two 只测了「流氓头」organic 拒绝 + `copyskill` 捷径，没有真实商店
购买，也没有真实门派收徒。`score` 对未投胎的巫师账号仍回「还没有出生呐」
（2026-08-12 已记录的内容门槛），所以本轮用 `title` 和 `user.o` 的
`family` 字段确认拜师写入。

### 本轮修的 bug

**`log_file()` 不 `assure_file()`，缺目录的 `log/nosave/` 会把巫师
`clone` 打成运行时错误**（AGENTS.md 已有的 unguarded-`log_file` 形状，
sibling `nte` 的 `adm/simul_efun/file.lpc` 早已加上 forward 声明 +
`assure_file(LOG_DIR + file)`，这里还是裸 `write_file`）。现场：
`clone /clone/money/gold` 立刻

```
执行时段错误：*Wrong permissions for opening file /log/nosave/clone
for append. "No such file or directory"
```

错误出在 `clone.lpc` 的 `log_file("nosave/clone", ...)`，发生在
`move()` 之前，所以黄金根本没进物品栏。`.gitignore` 排除整个
`work/log/`，不能靠提交空目录蒙混。修复与 `nte` 逐行相同：在
`log_file()` 上方加 `void assure_file(string file);`，调用
`write_file()` 之前 `assure_file(LOG_DIR + file)`。档案是 LF。

驱动重启后同一条 `clone /clone/money/gold` 成功（「黄金复制成功，放在
你的物品栏。」），`work/log/nosave/clone` 被自动创建。`is_admin()` 在
这份档案是 `VERSION_D->is_release_server() || admin_flag == 21 ||
getuid() == "lonely"`，`is_release_server()` 为真，wizlist `(admin)`
可以 clone——和 `xkxc98sj` 那种还要 `admin_flag == 1222` 的门不同，
不要把那边的 clone 拒绝套过来。

### 实测过程

管理员 `fluffos` / `Mud@2026` / 凌霄。第一行是
`Select 国标码 GB or BIG5 (gb/big5)：`，但 `input_to` 直接进 `get_id`；
`gb` 只有两个字母，会被 `check_legal_id` 拒绝。默认就是 GB，第一条发
`fluffos` 即可。没有 `wizpwd`。端口 40151。提示符是普通 `>`（不是每秒
时钟）。

先拜后买：`d/city/npc/xiaoer2.lpc` 没有丐帮穷叫化踢人（和襄阳/大理那些
`xiaoer2` 不同）。`goto /d/city/lichunyuan`，空空儿在场（id `kong`，
`kungfu/class/gaibang/kongkong.lpc`，会 `random_move()`）。
`apprentice kong` 一次成功：空空儿收徒，「恭喜您成为丐帮的第二十代弟子。」
`user.o` 立刻带上 `family_name":"丐帮"` / `master_name":"空空儿"` /
`generation":20` / `title":"丐帮第二十代传人"`。驱动重启后 `title` 仍是
「你现在的江湖称号：丐帮第二十代传人」。`permit_recruit` 只拒叛师/已有
别派。

然后 `goto /d/city/zuixianlou`，`list` 包子五十文铜板 / 烤鸡腿八十文 /
烤鸭一两白银又五十文。`buy baozi` 成功（「你从店小二那里买下了一个包子」）。
`i` 剩九十九两白银 + 五十文铜钱 + 包子（10000−50 = 9950），找零数学正确。
扬州店小二对已入丐帮的巫师没有穷叫化拒绝（本轮先拜后买仍买成）。

`clone/quest/shen` 的 `*No program in object` 开机噪音 2026-08-12 已记录，
本轮未再动。live 驱动 `debug.log` 是 `libs/ntii/log/debug.log`（Boot Time
Fri Sep 4 03:02:17 2026），修复后无 `error:` / `Too deep recursion` /
`Wrong permissions`。mudlib `error_handler` 写 `work/log/debug.log`，里面
只有修复前那一次 clone 崩溃，重启后没有新行。管理员存档未提交。

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 4 line(s) in 1 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `inherit/room/room.lpc`：`make_inventory()` 用 `catch()` 包住 `new(file)`，做不出来就返回 0；`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-06）— 与 zhonghua2 同源的三处编译警告

- `include/npc/indian.lpc` 与 `masia.lpc` 共用全局名 `ma_sname`/`ma_pname`；两个头文件被同一个守护进程（`npcd` 等）一起包含时，后包含的印度名表覆盖马来名表，`generate_ma_name()` 生成的是印度名字。印度表改名 `in_sname`/`in_pname`（KB 04 §6.10）。
- `cmds/std/team/bunch.lpc`：结义失败提示被多余的 `;` 截成两句，`fail` 只剩"……可惜现在有人不在，$N"，后半句"的提议只好作罢。"丢了；接回去。
- `clone/drug/fengdong.lpc`：`if (... < 10000) max1 / 2;` 是空语句，改成 `max1 /= 2;`（经验不足一万的对手，分身技能减半）。

验证：改动的文件和包含 `npc/indian` 的守护进程在 HEAD 与工作树分别加载（`scripts/lpc_listcheck.sh`，新进程），无回退。

## 深度功能测试（§10.7，2026-10-07）— 编译警告整理

先用 `scripts/lpc_twin_port.py adopt nitan_ceshi ntii` 把 nitan_ceshi 警告整理提交（ae7fbb619a5）里的改动搬到约 980 个修改前与它一致的文件（逐文件核对非 ASCII 文字：除 nitan_ceshi 自己删掉的以外没有丢失或改动）。剩下的再跑 `scripts/lpc_warnings.py ntii --fix`：无用局部变量 698 个、`varargs` 14 处，共改动 1251 个 `.lpc` 和若干 `.h`。
手工（与 nitan_ceshi 相同）：`adm/daemons/logind.lpc`、`fingerd.lpc` 里只在 `#ifdef DB_SAVE` 或 `#ifndef NO_FEE` 分支用的局部变量，声明挪进同样的条件里；`adm/daemons/combatd.lpc` 删去空语句 `your_temp["guarding"];`。`cmds/std/team/swear.lpc` 结义失败提示"的提议只好作罢。"与上一句隔着空行，前次的整理漏了它；接回去（`lpc_fix_no_effect.py` 原先会把它当作无用语句删掉，已改为只删空的 `"\n";`）。
HEAD 与工作树分别加载（新进程）：1245 -> 1245 通过，无回退；改过的头文件的 290 个包含者 289 -> 289 通过。

启动时警告 112 -> 0；新进程登录（英文名、新人物确认）正常。

## 深度功能测试（§10.7，2026-10-08）— `.lpc` 后缀的定宽切片

`.c` 改名 `.lpc` 时只改了字符串没改切片宽度：`f[<2..] == ".lpc"` 拿两个字符比四个字符，永远不成立（`!=` 永远成立），按后缀筛文件、去后缀的代码因此从不运行或截成 `x.l`（KB 06 §7.238）。`scripts/lpc_lpc_suffix_slice.py --apply` 改了 4 处比较、0 处去后缀（如 `adm/daemons/taskd.lpc`）；改动的文件 HEAD 与工作树分别加载（新进程），无回退。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 2 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 1 个，只在 #if 分支用的声明移进分支 4 个文件；改动 7 个文件，HEAD 与工作树各载入一次无回退（7 objects; HEAD PASS 7, tree PASS 7; regress 0; newly loading 0），这些文件的警告 8 -> 0。

- 2026-10-12：`adm/npc/obj/xiang.lpc` 写着 `int remove() { save(); }`，盖掉了 `feature/move.lpc` 的 `remove(string euid)`——这些存盘箱子/柜子被销毁时不从携带者身上减负重、不清 handing（KB 06 §7.239 变体，nitan_ceshi/tianxiawuxue 同类）。改成 `varargs void remove(string euid) { save(); ::remove(euid); }`。HEAD 与工作树各载入一次，regress 0（载不进的文件在 HEAD 就载不进）。

## 深度功能测试（§10.7，2026-10-12）：编译警告收尾

能编译的文件里的警告 9 条（7 个文件）-> 0（`lpc_warnings.py ntii` 重扫：13040 个文件可编译，剩下的诊断都在本来就编译不过的文件里）。与 nte 同码：nte 当天的修复（提交 7b93d60fe9b）改的 7 个文件在这里都是 token 级孪生，用 `lpc_twin_port.py adopt` 搬过来，详见 nte 的 NOTES.md 同名一节；本库自己的扫描同样报了 `pldan.lpc` 的 `clean_up()` 双重继承，删掉的 inherit 在本库确实重复。

**真问题（与 nte 相同）：**
- `clone/misc/swmuding.lpc` 神木王鼎自己的毒虫表从来没被基类 `muding.lpc` 用上 -> 改名 `sw_insects`，`create()` 里交给基类的 `insects`。
- `d/mingjiao/npc/hu.lpc` 胡青牛的疗伤回调 `recover(object ob)` 盖掉了 NPC 基类的 `recover()` -> 改名 `heal_patient`。
- `clone/misc/cruise-ob.h` 的 `remove() { save(); }` 盖掉了 F_MOVE 的 `remove(euid)`（不卸装备、不扣负重）-> 删掉，F_OBSAVE 物件由 F_MOVE 先存盘。

**其余：** food/liquid 的 `do_effect()` 改 `varargs int`；`genmap.lpc` 函数内不用的 `harbor.h` 包含；`pldan.lpc` 多余的 inherit。

验证：改动文件、所有继承 F_FOOD/F_LIQUID 的物品、包含 `pigpart.h`/`cruise-ob.h` 的文件、muding、eat/drink 共 308 个对象，HEAD 与工作树各用新进程载入：307 -> 307 通过，regress 0；删除声明审计 0 项待看。308 个对象载入无回退。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。13 个文件 20 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）；`x op= 浮点` 先把浮点转成整数再运算（系数小于 1 时 x 直接变 0），改为 `x = to_int(x op ...)`：`/adm/daemons/combatd.lpc`（`gain *=`）、`/kungfu/class/generate/killed.lpc`（`exp *=`）、`/kungfu/class/generate/killed.lpc`（`pot *=`）、`/kungfu/class/generate/killed.lpc`（`weiwang *=`）、`/kungfu/class/generate/killed.lpc`（`score *=`）、`/kungfu/skill/yunv-xinfa/xiuxi2.lpc`（`xj_gain *=`）、`/kungfu/skill/yunv-xinfa/xiuxi2.lpc`（`xj_gain *=`）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。

- 2026-10-14：2 个文件用了颜色宏（`HIW`、`NOR`）却没有 `#include <ansi.h>`（首个错误 `syntax error, unexpected L_STRING`）；开头补上（KB 04 §6.1、§6.3）。新进程比对 HEAD 与工作树：2 个对象，新增载入 2，回退 0。

## 负数伤害当作消耗（2026-10-15，KB 06 §7.241）

`receive_damage("neili", -52)`、`receive_damage("qi", -12)` 之类把 `add()` 的负数写进了 `receive_damage()`：本库 `feature/damage.lpc` 对负数伤害报错（或归零），练功/运功时报 `F_DAMAGE: 伤害值为负值` 或消耗失效。已改为正数伤害，内力/精力类改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py`）：`/kungfu/skill/duanyun-fu`、`/kungfu/skill/feifeng-whip`、`/kungfu/skill/pangen-cuojiefu`、`/kungfu/skill/yiwei-dujiang`。

## 内力/精力当作伤害种类（2026-10-15，KB 06 §7.241 第二类）

本库 `feature/damage.lpc` 的 `receive_damage()` 不接受 `jingli`/`neili`/`force` 等种类，`me->receive_damage("jingli", 30)` 之类在练功、绝招、吸取时报 `F_DAMAGE: 伤害种类错误`。17 处改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py` 第二步）。

## 东方故事/西游记体系的技能文件（2026-10-15，KB 06 §7.241 第三类）

这些 `kungfu/skill` 文件来自 gin/kee/sen/force 体系，本库人物只有 jing/qi/neili：`receive_damage("kee", 30)` 报 `伤害种类错误`，`query("force")` 永远为 0，技能学不了也练不了。按 kee→qi、gin/sen→jing、force→neili、max_force→max_neili、force_factor→jiali 改了属性名（`scripts/lpc_port_es_props.py`），共 1 个文件。

## 转码吃掉的引号（2026-10-15，KB 03）

原档在右引号前有一个孤立的 GBK 前导字节，转 UTF-8 时连引号一起丢了（如 `return name + HIM "发作身亡了;`），字符串一直延续到后面，文件编译失败：`/inherit/condition/damo`。补回引号（`scripts/lpc_fix_eaten_quote.py`）。其中 `/inherit/condition/damo.lpc` 不能编译时，所有 `damo_*`（达摩）中毒状态都载入失败。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。3 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。

## `find_player()` 只认在世界里的身体（2026-10-15，KB 07 §8.26）

simul_efun 的 `filter_player()` 加上 `environment(ob)`：注册中途断线留下的、不在任何房间的身体不再被当成玩家，两个以上时 `find_player()` 不会再报 `The player(<id>) has existed in the world.`（wllz3 实测过的问题）。本库若注册流程不会留下带玩家 uid 的身体，这一改动不改变行为。

## 空手使用兵器绝招（2026-10-15，KB 06 §7.246）

`perform` 指令允许直接点名招式（如 `perform stick.ban`），这些绝招读了 `me->query_temp("weapon")` 却从不检查，空手时 `weapon->name()` 报错（有的已先扣了内力）。在赋值后补 `if (!objectp(weapon)) return notify_fail("你必须手持兵器才能使用这一招。\n");`（`scripts/lpc_fix_perform_weapon.py`）：`bingpo-blade/ningxie`、`duanyun-fu/hong`、`huashan-sword/long.bak`、`xue-dao/xuemo`、`yunu-sword/yijian`。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`matrial-cognize`→`martial-cognize`（`qiankun-danuoyi/nuoyi`、`qiankun-danuoyi/yi`）；`qianzhu-wandu`→`qianzhu-wandushou`（`/kungfu/class/emei/zh`、`qianzhu-wandushou/tuxi`）；`xuantian-wuji`→`xuantian-wujigong`（`liangyi-jian`、`taxue-wuhen`）；`choushui-zhang`→`chousui-zhang`（`chousui-zhang`）；`cuhixiao-jifa`→`chuixiao-jifa`（`xiaoao-jianghu`）；`feilong--cuff`→`feilong-cuff`（`feilong-cuff/dan`）；`hengshan-jianfa`→`hengshan-jian`（`/d/henshan/tianquan-hole`）；`lenyue-shengong`→`lengyue-shengong`（`lengyue-shengong`）；`xiawuxiang`→`xiaowuxiang`（`jidao-shaqi`）；`yaowang-mishu`→`yaowang-miaoshu`（`yaowang-miaoshu`）。

## 技能名拼错：技能文件里拼错自己的名字（2026-10-15，KB 06 §7.249）

技能自己的文件（或它的绝招目录）里，`query_skill()` 读的是差一个字母的自己的名字，永远得 0：“基本功夫要高过本技能”之类的限制从不生效，按等级取招、计算伤害的那一项一直是 0。改为本技能的名字（`scripts/lpc_fix_skill_typo.py` 的 self 判据）：`xuanyuan-arror`→`xuanyuan-arrow`（`xuanyuan-arrow`）。

## 密宗猴拳「震」最重的一档报错（2026-10-15）

`/kungfu/skill/mizong-houquan/zhen` 按伤害分档写描述：前几档都是 `pmsg = ...`，最后一档（伤害 ≥ 80，也就是最重的一击）却写成 `pmsg += ...`，而 `pmsg` 没有初值，本驱动里 `0 += 字符串` 直接报错，这一招打得最狠时反而中断。改为 `pmsg = ...`。

## 地图数据库 mapdb 的空档防护（2026-10-15，KB 06 §7.250）

genmap 第一次载入时 `if (!restore()) save();` 会在地图建好之前写出只有文件头的 `data/npc/map.o`；mapdb 读它成功后 `map` 为 0，所有查询都对 0 取下标（nitan170911、shenzhou 等 10 个库就带着这样的文件）。没有 map.o 时 `query_random_room_path()` 又对空数组取下标。mapdb（`/clone/obj/mapdb.lpc`）加一个 `restore()`：读档后 `map` 不是映射就重置为 `([])`；地图为空时 `query_random_room_path()` 返回 0。


## 临济庄「幽冥桩」的两处笔误（2026-10-15，KB 06 §7.245、§7.250）

`linji-zhuang/youming`：`killer->querry(...)`、`me->querry(...)` 调用的是不存在的函数，永远得 0，恶人比值只按 PK 数算，改为 `query`；`visit_room()` 先拿 `range` 作判断、后从参数里取 `range`，判断时它还是 0，效果遇到没载入的房间就停，两行取值挪到前面。


## 柔云步法「柔云纵」有时报错（2026-10-15，KB 06 §7.251）

`rouyun-steps/zong` 随机把人送到三个房间之一：精、精力已经扣了，“乘云而去了”也说了，送不过去时人留在战斗里并报错。第三个是巫师的测试房 `/u/deaner/test1`，库里没有；改为 `/d/city/guangchang`（hy、jym 等库原本就用这个）。


## 秋林拾叶「随风而舞」成功时报错（2026-10-15，KB 06 §7.252）

`qiulin-shiye/wu` 把房间的出口映射当数组：`mapping *obb = query("exits", env)`，成功时 `me->move(obb[0])`，映射里没有键 0，移动到 0 报错（没有出口的房间则是对 0 取下标）。改为 yanhuangwuhun 一系的写法：从 `values(exits)` 里随机选一个出口。

## 用兵器的绝招空手施展时报错（内联写法）（2026-10-15，KB 06 §7.246）

绝招不存兵器变量，直接写 `(me->query_temp("weapon"))->query("name")`（或在拒绝判断里写 `(weapon = me->query_temp("weapon"))->query("skill_type")`），之前又没检查兵器：空手 `perform` 时报 `Bad argument 1 to EFUN call_other()`，内力等往往已经扣掉。在第一次用到它的那条语句前补上“你必须手持兵器才能使用这一招”的拒绝（`scripts/lpc_fix_perform_weapon.py`）：`shenlong-jian/anxi`。


## 存档读不出来：字符串里的换行、空行（2026-10-15，KB 03 §4.4）

`help/newsd.o`：字符串里有原样的换行（`save_object()` 存成 `\r`，`restore_object()` 逐行读，原样的换行让字符串收不了尾），或有空行（`Illegal file format`），读档的对象（留言板、NPC、玩家）从空白开始。换行改写成 `\r`、删去空行（`scripts/lpc_save_encoding.py --from-raw`），驱动核对全部能读回（`scripts/lpc_save_restore_check.py`）。

## 移进不存在的巫师房间（2026-10-15，KB 06 §7.251）

用完的物品、要“离开”的 NPC、掷在空中的兵器被移进巫师的工作室（`/u/aln/`、`/u/lonely/`、`/u/smallfish/`），本库没有这些房间。本库的 `move()` 用 `call_other(dest, "???")` 载入目的地，找不到文件就报 `call_other() couldn't find object`，后面的语句都不执行：药（人参，`clone/drug/cb_renshen`）吃下后药效已经生效，随后报错：`call_out("destroy", 31)` 没有排上，药一直留在身上，药效过去后可以再吃；婚礼最后一步（`adm/npc/hongniang`、`adm/npc/meipo`、`d/suzhou/npc/meipo` 的 `last_marry`）先把月老送走，在这里报错：新人不会被送上花轿去迎宾楼，喜宴没有了；喜宴结束、礼金付出之后，喜来福（`d/suzhou/npc/xi-laifu`）退回内堂时报错，留在楼上。5 个文件改为移进本库的虚空房间 `VOID_OB`（`/clone/misc/void`），与原作把它们“停放”在巫师房间的用意相同（haiyang2 的维护者把月老送进 `/d/city/empty`，也是同样的做法）。

## 物品清单把名字的第一个字吃掉（2026-10-18，KB 07 §8.1）

`inventory`、房间的物品列表（`feature/move`）和部分 `look` 把同名物品合并计数，键是 `query("unit") + short()`，只有一件时按 `key[2..]` 去掉量词。量词是一个汉字，在原来的 GBK 里占 2 字节，`[2..]` 正好去掉量词；转成 UTF-8 以后一个汉字只占一个下标，这一刀把名字的第一个字也切掉了（「把长剑」只显示「剑」，带颜色的名字切掉的是转义序列开头）。改为 `[1..]`（`scripts/lpc_fix_unit_cut.py`）：`d/city2/look.lpc`。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 3 个对象设了本库没有文件的武功（15 个名字，最多的是 `xinyuegong`、`taizuquan`、`liangyi-dao`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：3 个里 3 个通过。（`scripts/lpc_guard_set_skill.py`）

## 通向不存在房间的出口，按对面房间的回头出口改正（2026-10-18，KB 06 §7.257）

房间出口 `"west": __DIR__"xxx"` 指向的文件本库没有，玩家走过去就被卡住（笔误、改过名的房间，或者没带进档案的编号房间）。对面的房间存在、并且它相反方向的出口正好指回这个房间，说明出口原本就是通向它：`/d/dragon/lake` 的 `east`：`/d/tulong/lake1` → `/d/dragon/lake1`；`/d/dragon/lake2` 的 `northeast`：`/d/tulong/lake1` → `/d/dragon/lake1`。改动后每个出口都能解析到本库的文件（`scripts/lpc_fix_dead_exits.py`；目标在运行时本来就能载入的库——虚拟房间——不动）。

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 25 处、13 个文件：`yunu-xinjing`→`yunv-xinjing`（7 处）、`jinyin-baiguzhao`→`jiuyin-baiguzhao`（4 处）、`changquana`→`changquan`（4 处）、`tiaji-jian`→`taiji-jian`（2 处）、`shenkongxing`→`shenkong-xing`（2 处）、`taiji-shenfong`→`taiji-shengong`（1 处）、`shaolin-shnfa`→`shaolin-shenfa`（1 处）、`yan-fly`→`yanfly`（1 处）等共 11 个名字。（`scripts/lpc_fix_skill_names.py`）

## die_reason 的参数个数（2026-10-19，KB 04 §6.10）

`/kungfu/condition/damo_luanqi.lpc`、`/kungfu/condition/damo_shangshen.lpc`、`/kungfu/condition/damo_zheyuan.lpc` 里的 `string die_reason()` 覆盖了基类的 `die_reason(string name)`，驱动报 `Number of arguments to 'die_reason' disagrees with previous definition`。补上 `varargs`，调用处不用改；改后与 HEAD 逐个物件对比载入，没有退步。

## 出口指向不存在的房间（2026-10-19，KB 06 §7.257）

下列房间的出口写的文件不存在，而对面恰好只有一个房间的出口指回本房间，所以按对面的房间改正（笔误、大小写、路径少了一级）：

- `/d/huanggon/qihedian.lpc` 的 `south` 出口：`/d/city2/zhengmen` → `/d/huanggon/tinglang3`

改后房间照常载入（与 HEAD 逐个对比，没有退步），出口现在指向存在的房间。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 被注释吞掉的语句（2026-10-19，KB 06 §7.274）

- `/d/baituo/obj/lingshezhang.lpc`：`set("wposition", "/d/baituo/obj/lingshezhang.lpc")` 被 `//***** ADDED BY SCATTER *****` 注释吞掉

`scripts/lpc_fix_swallowed_statement.py` 把换行放回去。逐个载入与 HEAD 对比，没有退步。

## 补回丢失的标点（2026-10-19，KB 03 §4.6）

转换时丢掉的分号、逗号、引号或文件末尾的 `}`，共 1 个文件，修前 HEAD 载入失败。别的库里同路径的完好副本只比这里少几个标点，按它补回（括号里是那个库）：`/d/baituo/npc/obj/bowl.lpc`（cctx）。修后与 HEAD 逐个对比载入：这 1 个物件全部载入，没有退步（`scripts/lpc_restore_from_twin.py`、`lpc_fix_eaten_quote.py --comma`、`lpc_fix_eof_braces.py`）。

## `x == "a" || "b"`：后面的字符串常量永远为真（2026-10-19，KB 06 §7.281）

`if (arg == "yuyou" || "yu you")` 里的 `"yu you"` 是非空字符串，永远为真，整个条件对任何 `arg` 都成立；作者要的是每个字符串都和变量比较。具体是：吃任何东西（`eat` 后面不管写什么）都会吃掉紫草；`valid_combo()` 对任何组合都返回真。在每个字符串前补上变量和运算符（`scripts/lpc_fix_literal_or.py`；`forrest2.lpc` 是 `dir == "north" && "south"`，手工改成 `(dir == "north" || dir == "south") && ...`）：`/clone/medicine/zicao.lpc`（1 处）、`/kungfu/skill/meinv-quan.lpc`（1 处）。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。具体是：`valid_learn()` 对任何性格都拒绝。改动：`/kungfu/skill/qiankundanuoyi.lpc`（1 处）、`/kungfu/skill/zhonghua-aojue.lpc`（1 处）。

## `member_array('/', str)` 改为 `strsrch(str, "/")`：字符字面量的 member_array 按字节搜索（2026-10-20，KB 06 §7.283）

`member_array('/', str)` 里的 `'/'` 是整数，驱动按 UTF-8 **字节**搜索，返回字节偏移（带第三个参数时起点也是字节）；最新的 FluffOS（923cdbc0）在字符串里有非 ASCII 文字时，对每个调用点警告一次（`Warning: member_array(int, string) searches BYTES`）。而 `str[0..idx-1]` 按字符切，中文字符串会在错误的位置截断。改为 `strsrch(str, "/")`（找不到同样返回 -1，按字符计数；`scripts/lpc_fix_member_array_char.py`，JSON 编码器等少数几处手改）。改动：`/adm/daemons/vrm_server.lpc`（1 处）、`/cmds/arch/sameip.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 3 处）。改动：`/adm/daemons/competed.lpc`（1 处）、`/adm/daemons/xinruid.lpc`（1 处）、`/cmds/wiz/roomlong.lpc`（1 处）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/single/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## `ctell`：`MTEXT` 在没选中的头文件分支里（2026-10-21，KB 04 §6.16）

`include/globals.h` 末尾 `#ifdef DOING_IMPROVED #include "ntsql.h" #else #include "tomud.h" #endif`；`DOING_IMPROVED`（带数据库的版本）没有定义，用的是 `tomud.h`，它没有 `MTEXT`（`ntsql.h` 里有：`#define MTEXT(x) TMI("ptext "+x)`，和 `PTEXT` 同形，同系的 dtsl2、xyzx3、xyj2006zzzhx 的 `tomud.h` 都有这一行）。`cmds/std/ctell.lpc` 四处用 `MTEXT(...)`：`Undefined function MTEXT`，整个命令加载失败。在 `tomud.h` 补上这一行。nte 和 ntii 的 `ctell.lpc` 逐字节相同，同一处改法；加载检查 HEAD 0、树 1。没有改：`fee`（`DB_STR` 和 `DATABASE_D` 只在数据库版本里，没有数据库，整个命令是死功能）。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库现有的 NPC 文件里没有字面写成空 `chat_msg` 的（扫描只认 `set("chat_msg", ({ }))`）；守卫挡的是运行时才为空的列表和以后新增的 NPC。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/inherit/char/npc.lpc`（共 1 个文件）。

## `blockade` / `recover`：`data/keep` 不存在，解封之后世界仍然锁着（2026-10-21，KB 06 §7.340）

管理员扫描里 `blockade` 报 `Error copying file from /data/user/f/fluffos.o to /data/keep/fluffos, Error: No such file or directory`，随后的 `recover` 在第一个 `cp()` 上死于 `*/data/keep/fluffos: lstat failed`，来不及执行最后的 `LOGIN_D->set_madlock(0)`：封锁解不开。`data/keep/` 是运行时目录，git 克隆里没有空目录。`blockade` 在第一次写之前 `if (file_size("/data/keep") != -2) mkdir("/data/keep");`（`mkdir()` 失败答 0，不抛错），`recover` 对没有保存档的玩家 `if (file_size(src) < 0) continue;`，其余照常恢复、照常解锁（`scripts/lpc_fix_keep_dir.py`，hy5 上实测：没有保存档时 `recover` 答“时空解封完毕”，`blockade` 建出 `data/keep` 并保存，`recover` 取回并删除）。改动（1 个文件）：`/cmds/arch/recovermud.lpc`。

## 不带参数的指令对 0 调用 efun：不在 wiz / adm 目录里的指令（2026-10-21，KB 06 §7.336）

指令敲成不带参数时，驱动把 0 传给字符串参数；下面的指令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`。它们在 `cmds/std`、`cmds/usr`、`cmds/bos`、`cmds/app` 这类目录里，上一轮的扫描只看巫师目录。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py --all-dirs` 在第一处使用参数的语句前加守卫：没有 `help()` 的是 `return notify_fail("…\n");`。改动（1 个文件，括号里是接住 0 的 efun）：`/cmds/std/actionavailable.lpc`（`sscanf`）。加载检查 HEAD 与工作树对照，没有退步。

## 拼错的 `call_out()` / `input_to()` 目标（KB 06 §7.349，2026-10-21）

计时器或输入提示给驱动的函数名和文件里定义的差一个字母；驱动对不存在的函数静默不理，所以对应的计时从来没有触发过。调用和配套的 `remove_call_out()` 改成已定义的拼法：`ruanweijia` / `yuxiao`：`return_to_zhang` → `return_to_huang`（携带者在战斗时的重试从不发生，宝物一直留在玩家手里）；张无忌：`destrory` → `destroy`。改动：`/clone/lonely/ruanweijia.lpc`、`/clone/lonely/yuxiao.lpc`、`/kungfu/class/mingjiao/zhangwuji.lpc`。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 22 条注册（16 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/adm/npc/referee.lpc`（`do_halt`）、`/clone/drug/guiyuan.lpc`（`do_pour`）、`/clone/drug/huiyang-san.lpc`（`do_pour`）、`/clone/drug/shedan.lpc`（`do_pour`）、`/clone/drug/yangxin.lpc`（`do_pour`）、`/clone/drug/yulu-wan.lpc`（`do_pour`）、`/d/baituo/npc/obj/shedan.lpc`（`do_pour`）、`/d/baituo/npc/shedan.lpc`（`do_pour`）、`/d/beijing/npc/dangpuzhang.lpc`（`do_expiate`）、`/d/beijing/npc/tiegongji.lpc`（`do_bcun`、`do_bqu`） 等共 16 个文件。最多的函数名：`do_pour` 7 处、`do_bcun` 3 处、`do_bqu` 3 处、`do_halt` 2 处、`do_expiate` 2 处。

## 缺失物品的 `new()` / `carry_object()` 调用链加了保护（2026-10-22，KB 06 §7.73 补充）

`new(路径)->move(...);` / `carry_object(宏("x"))->wear();` 这类语句，路径指向的文件在这个压缩包里没有：`new()` 返回 0，`->move()` 在 0 上报 `Bad argument 1 to EFUN call_other()`。在 `create()` 里这个对象永远加载不了，在 `reset()` 里第一个缺失物品之后的刷新每次 reset 都被跳过。6 个文件里 11 处（`new`）改成 `{ object new_ob = new(路径); if (new_ob) new_ob->move(...); }`（`scripts/lpc_guard_carry_object.py --new`：路径按这个文件自己看到的宏解析，宏名冲突、虚拟对象路径一律跳过）。 对这 6 个改动文件做加载检查（HEAD 与工作区对比）：HEAD 能加载 6 个，现在 6 个（新增可加载 0 个，回归 0 个）。

## 调用了、但这个库自己的守护进程里没有的函数（2026-10-22，KB 06 §7.354）

`MACRO->函数()` 调用的函数在这个库的守护进程里不存在：`call_other()` 对不存在的函数不报错、只返回 0，所以这些功能（时间显示、昼夜事件、名字检查、价格文字……）一直没起作用。同一血统另一个库的同名守护进程里有这些函数，原文照抄到本库守护进程末尾（`scripts/lpc_port_function.py`；调用处传的参数个数、函数体用到的函数 / 全局变量 / 宏 / 字符串键都在本库里有，已核对；守护进程在 HEAD 和工作区都能加载，每个函数用固定参数各调用一次：HEAD 返回 0，现在返回正常的值）：`/adm/daemons/natured.lpc` ← aoxiangtianji：`outdoor_room_event()`（2 处调用）。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 还剩 3 个函数没有补（item_desc 3）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/d/yihua/lianhuachi.lpc`:`look_CAI`、`/d/yihua/lianhuachi1.lpc`:`look_CAI`、`/d/yihua/lianhuachi2.lpc`:`look_CAI`。

## 运行期目录 `log/nosave` 不存在，写日志的 `write_file()` 直接报错（2026-10-22，KB 03 §4.3 补充）

这个库的 71 个文件里有 126 处 `write_file("/log/nosave/...")` / `log_file("nosave/...")`（`static` 改 `nosave` 时连字符串里的日志路径一起改了，原来是 `log/static/`）：`nosave/using`、`nosave/party_quest`、`nosave/security` 等。压缩包和站点包里没有这个目录，`write_file()` 在目录不存在时抛 `*Wrong permissions for opening file /log/nosave/... for append. "No such file or directory"`，调用它的函数（杀人记录、重启记录、`call` 日志……）当场中断。把 `log/nosave/guilei` 记进 `scripts/wasm_keep_dirs.txt`（站点和 pristine 树都按它建空目录）；没有把字符串改回 `static`。证明（`scripts/lpcc_eval.py`，`catch(write_file("/log/nosave/ZZTEST", ...))`，fqyy2 / hy5 / bmxkx2001 的新进程）：补目录前报上面的错误，补后写成功。

## `(: 函数名 :)` 指针指向本库没有的函数：只含这个指针的行加了注释（2026-10-22，KB 06 §7.355 补充）

`inquiry` / `item_desc` / `chat_msg*` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：用到时（`ask`、`look`、NPC 闲聊）驱动抛 `*Undefined lfun pointer called: 函数名`，这一拍心跳的后半段被跳过。这些函数没有可以补回的来源（别的库同一路径的文件里没有，或者它还要用本库没有的东西），所以 3 个文件里 3 行只含这个指针的行（`"CAI": (: look_CAI :),`）加了注释，原文保留并写明原因，这一项当作没有这个话题 / 物品 / 闲聊条目（`scripts/lpc_fix_dangling_lfun.py`；`#include` 的文件在库里缺失的对象、指针不在整行上的写法没动）。 前提（`function_exists()`）和加载检查（HEAD 与工作区对比，本库改动的 `.lpc` 文件）的结果见 KB 06 §7.355：没有一个回归。

## 汉字按字节切片的老写法没有换成按字符：改法名 `"澄" + name[2..3]`、辈分判断 `name[0..1] == "澄"` 等 20 处（2026-10-22，KB 06 §7.360）

原档按字节算字符串区间（一个汉字 2 字节）：`name[2..3]` 是名字的第二个字，`name[0..1] == "澄"` 问名字是不是以「澄」开头。转成 UTF-8 之后，这个驱动的区间和 `strlen()` 都按字符算（`strlen("澄观")` 是 2，`"澄观"[0..1]` 是两个字），老算术原样留着、意思全变：拜入少林 / 武当 / 峨嵋等派的玩家被改成错误的法名（二字名 `张三` 变成一个字的 `澄`，更长的名字取到第三个字）；各派掌门的辈分判断（`name[0..1] == "澄"`）永远不成立；NPC 的称呼和提示里取到两个字而不是一个字。

本库 20 处（13 个文件）：拼名字的赋值 10 处、与汉字常量比较 9 处、`to_chinese()[..]` 1 处。例：`name[2..3]` → `name[1..1]`（`/kungfu/class/emei/fengling.lpc:133`）；`name[0..1]` → `name[0..0]`（`/kungfu/class/emei/tobebonze.h:41`）；`chk[0..1] == "你"` → `chk[0..0] == "你"`（`/adm/npc/ganjiang.lpc:542`）。`scripts/lpc_fix_gbk_slice.py` 把下标按字符重算（社区的 UTF-8 版 `xkx100utf8` 里就是同样的写法，作对照）；没有改的：截断（`name = name[0..7]`，现在最多 8 个字，只是放宽）、ASCII 的区间（`fname[0..3] == "room"`、`ctime(time())[4..19]`）和上下文看不出是汉字的区间。证明（`scripts/lpcc_eval.py`，bixiecanyang；其余各库是同一份文本）：让澄字辈掌门 `attempt_apprentice()` 一个名叫「张三」的访客，HEAD 的法名是 `慧`，改后是 `慧三`；抽样 28 个库的 HEAD / 工作树加载对比 0 退步。工具不幂等（`[0..3]` 折半得 `[0..1]`，又是对齐区间），改过的文件记在 `scripts/gbk_slice_converted.txt`，不要重跑。

## 长度检查按字节写，旁边的提示按汉字写：14 处（2026-10-22，KB 06 §7.362）

老档的 `strlen()` 数字节（一个汉字 2 字节），转成 UTF-8 后它数字符：提示写「必须是 2 到 6 个中文字」的检查还是 `strlen(name) < 4 || strlen(name) > 12`，于是两三个字的房名、帮会名、群名、聊天室名、称号被提示自己说允许的那句话拒绝，上限却是提示的两倍；留言板的标题检查 `i < 4 || i > 24 || i % 2` 还会拒绝所有奇数个字的标题（`post 你好吗`）。本库 14 处（7 个文件）：`if ((strlen(name) < 4) || (strlen(name) > 12)) {`（`/adm/npc/luban.lpc:1767`）；`if ((strlen(mission) < 4) || (strlen(mission) > 20)) {`（`/cmds/adm/mission.lpc:57`）。`scripts/lpc_fix_strlen_gate.py` 以提示为准：条件里每个 `strlen` 门槛都恰是提示所说数字的两倍才折半，存长度的变量（`i = strlen(arg);`）的门槛和 `|| i % 2` 奇偶项、其后循环的 `i % 2 == 0 &&` 一并处理；提示里有英文 / 字母 / 字节的不动。证明（`scripts/lpcc_eval.py`，bxsj 的留言板，求值对象继承 NPC 并重写 `edit()` 记录调用，`command("post 标题")`）：HEAD 拒绝「你好」和「你好吗」、放行 23 个字的标题；改后接受前两个、拒绝第三个；shenmo 的 `named.lpc invalid_new_name("张三")`：HEAD 回 `名字只能是2-4个中文字。`，改后回 0。抽样 24 + 15 个库的 HEAD / 工作树加载对比 0 退步。
