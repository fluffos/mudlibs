
## WASM 修复摘要（迁移自 meta.json 的 group_note）

侠客英雄传 II/III（"欢乐天地"，五邑无尽豪情），一个金庸小说/欧洲中世纪/漫画风混搭的世界观设定。WASM 修复了两处经典的 §8.1 GBK 字节区间 is_chinese() bug：adm/daemons/chinesed.lpc 的 is_chinese()（CHINESE_D 委托的真正实现——只检查 str[0] 的原始字节区间，还要求总长度是偶数，在 UTF8 码点索引下永远失败）和 adm/daemons/logind.lpc 自己的 check_legal_name()（i%2 奇偶门槛，加上按字节数算的长度界限 2-12，本意是按用户提示"1 到 6 个中文字"应为 1-6 个字符）。已把 chinesed.lpc 的 is_chinese() 重写成逐码点 0x4e00-0x9fff 区间循环，check_legal_name() 改成通过 CHINESE_D->is_chinese(name[i..i]) 逐字符检查，长度界限修正为 1-6。管理员账号播种：fluffos (admin) 加入 adm/etc/wizlist（已通过源码确认 SECURITY_D 真的会在开机时读取 WIZLIST；wiz_levels 顶层是 (admin)）。注册流程在多次连续的 WASM 客户端会话里完整验证过：英文 id→y/n 确认创建→中文名字→密码+确认→性别（m/f）→种族选择（0-5）→带着完整角色属性表和可用的 score/look 指令进入游戏世界，全程没有任何意外错误。测试笔记：性别/种族选择正好接在 /std/char.lpc 首次编译的大量负荷之后（加载 feature/damage.lpc、feature/skill.lpc 等），引发了和 xhcii 上记载过的同一类测试工具时序竞争——不论 --idle 设多少，'m' 有时会被当作无法识别的输入吞掉；补发一次重复的 'm'/'0' 能可靠绕过，这是客户端时序上的假象，不是 mudlib 本身的缺陷（一次完全干净的运行在注册流程里没有捕获到任何异常，可以证实这一点）。管理员权限已直接通过 'wizlist' 指令输出确认"目前权限：(admin)"，fluffos 出现在最高阶层里。LPC 格式化工具对全部 3178 个档案运行（写入 3145 个，12 个报错，21 个未改动）。没有 :: 父类呼叫拆分命中，没有 CJK 重新加空格命中，没有 case 标签带尾随注释的候选，这份快照里没有 map.lpc 档案。格式化后用同样的完整注册流程重新验证过——干净，管理员权限依然是 (admin)。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 4 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（2026-08-17，round one）——严重 bug：AGENTS.md §7.11 类，新角色永久没有出生房间

第一次对这份档案做完整 §10.7 深度游玩测试，发现并修复一个严重的、
每个新角色都会撞上的 bug——不计其数（这份档案没有任何存活的角色曾
经真正进入过一个房间）。

- **症状**：无论用普通玩家账号还是巫师账号，走完完整注册流程（英
  文id→中文名字→密码→电子邮件→性别→种族）之后，`score` 正常显示
  完整属性面板，但 `look` 只回传 `cmds/std/look.lpc` 自己对
  `environment(me)` 为空时的兜底文字"你的四周灰蒙蒙地一片，什麽也
  没有。"——角色事实上从未被放进任何房间。走 `east`（起始房间自
  己声明的真实出口）也只得到"什麼？"，`goto`（巫师指令）在这个角
  色身上执行时会因为 `environment(me)` 是 0 而在
  `cmds/imm/goto.lpc` 第 11 行的 `file_name(where_me)` 抛出
  "*Bad argument 1 to file_name()"。断线重连、换用全新账号、换用
  巫师账号，症状完全一致，可稳定复现。
- **根因**：`adm/daemons/logind.lpc` 的 `enter_world()`，在
  `cat(MOTD)`/房间选择/`user->move(startroom)` 那一段代码**之前**，
  有一段"经验值/潜能值异常侦测"逻辑——`combat_exp` 和 `exp` 差值
  ≥1000，或 `potential` 和 `pot` 差值 ≥500，就会
  `log_file("nosave/WARNING", ...)`，完全没有 `catch()` 保护。
  这份档案的 `adm/simul_efun/file.lpc` 里 `log_file()` 的实现是
  裸 `write_file(LOG_DIR + file, text)`，同样没有目录存在性检查；
  而这份档案的原始压缩包**从未打包过 `/log/nosave/` 这个目录**。
  结果就是：几乎每一个新创建的角色（`combat_exp`/`exp`、
  `potential`/`pot` 默认值的落差天然就会超过这两个阈值）在
  `enter_world()` 执行到这个日志调用时就会因为
  "Wrong permissions for opening file /log/nosave/WARNING for
  append" 而未捕获地中止整个函式——包括它之后的一切，尤其是
  `user->move(startroom)`。角色从此永久卡在没有环境的状态，
  `score` 等不依赖 `environment()` 的指令仍然正常，制造出"部分功
  能正常，部分彻底失效"的迷惑现象。这正是 AGENTS.md §7.11 已经归
  档的"未打包的运行时目录 + 无保护的 write_file()/log_file()"类，
  但打击面比该条目里记录过的任何一个先例都更广——它不是命中某个
  边角功能，而是命中**每一个新角色的世界入口本身**。
- **修复**：`adm/simul_efun/file.lpc` 里 `log_file()` 补一行
  `assure_file(LOG_DIR + file);`（这份档案自己已经有
  `assure_file()` 这个帮助函式，委托给 `FILE_D->assure_file()`），
  和 AGENTS.md §7.11 里 `xajhxo` 那个实例用的是完全一致的修复手
  法。由于 `assure_file()` 在同一个档案里的文字位置**晚于**
  `log_file()`，这个编译器不会自动解析后向引用（和 §7.11 `xajhxo`
  条目记录的现象完全一样）——额外加了一行前向声明
  `void assure_file(string file);`，否则编译报
  "Undefined function assure_file" 并直接打断整个
  `simul_efun` 的载入（连驱动开机都会失败，`lpcc_check.sh` 全档
  案批量编译检查直接从 total=3178 变成 total=0）。
- **现场验证**：重开一个全新驱动进程，两个完全独立的角色（普通
  玩家 `qintestz`/`秦侠三`，和管理员 `fluffos`/`巫侠`）都干净地
  走完注册流程，`look` 正确显示起始房间"如何移动"（新手教程室）
  的完整描述、出口 `east`、以及会主动打招呼的 NPC"小花狗"；
  `debug.log` 全程零 "Wrong permissions"/"nosave" 记录。用巫师
  账号 `goto` 到有主动攻击型 NPC 的场景（扬州"异娼庙"的"疯狗"），
  完整交手数十回合，攻防/命中/闪避判定全部正常，疯狗被击晕
  （"跌在地上一动也不动了"）。因为这个 bug 已经严重到本轮大部分
  时间都花在定位它上，死亡/复活循环和留言板发帖本轮未覆盖，留给
  下一轮。
- **和早前 WASM 阶段记录的矛盾**：本文件顶部的 WASM 修复摘要写
  着"带着完整角色属性表和可用的 score/look 指令进入游戏世界，全
  程没有任何意外错误"——这条记录和本轮观察到的情况矛盾。由于这
  段"经验值异常侦测"逻辑是**基于角色具体属性差值的条件触发**，不
  是每次注册都 100% 必然命中，推测早前那次测试用的角色属性差值凑
  巧落在阈值以下，侥幸没有撞上——不代表这份档案曾经真的对所有角
  色都安全过。这也是本次能找到这个 bug 的关键：早前的测试只覆盖
  了"注册流程走没走通"，没有像本轮这样进一步验证"注册完之后
  `look` 是否真的显示了一个房间"。

## 深度功能测试（2026-08-17，round two）——补完死亡/复活、留言板，另发现并修复两个新问题

补完上一轮留下的死亡/复活循环和留言板发帖测试，过程中额外发现并
修复两个此前未覆盖到的问题。

- **AGENTS.md §7.90 类新实例，`/d/jiangjunfu/main-05`/`main-06`
  真实的 eval-cost 崩溃**：上一轮 `lpcc_check.sh` 批量编译扫描曾
  在这两个房间报过 eval-cost 命中，当时判断优先级不够、未深入调
  查（详见 `feedback_lpcc_sweep_eval_cost_artifact` 的方法论教
  训——批量编译的共享 eval-cost 预算可能对本身廉价的档案产生假阳
  性）。本轮用巫师账号 `goto /d/jiangjunfu/main-05` 复现，确认是
  真实崩溃而非批量编译假象："执行时段错误：*Too long evaluation.
  Execution aborted."，崩在房间 `create()` 载入多个"将军"NPC、每
  个 NPC 的 `create()` 又要 `wear()` 装备的连锁编译成本上。这份档
  案的 `config.fluffos` 和大多数本项目档案一样用着
  `maximum evaluation cost : 700000`（本项目最常见的模板默认值，
  但同时也是本项目实际使用范围里偏低的一档）。修复：按
  AGENTS.md §7.90 已确立的手法，调到 `5000000`（本项目内 30+ 档
  案已经在用的同一个值）。重启驱动后现场验证：`main-05` 和
  `main-06` 两个房间都能干净载入，NPC 列表正常显示，
  `debug.log` 里零 "Too long evaluation"/"cost limit reached" 记
  录。
- **`cmds/imm/goto.lpc` 的 `file_name(environment(me))` 未做空值
  保护**：本轮为搭建死亡测试环境，用一个刚触发过上一轮 bug 的
  （测试用）巫师账号做 `goto` 时意外复现——`environment(me)` 为
  空时，`goto` 函式第 11 行无条件对其取 `file_name()`，在检查
  `arg` 参数之前就先崩了（"*Bad argument 1 to file_name(); Expected:
  object Got: 0"）。这个变量 `ll_me` 只在函式末尾的一条日志格式化
  字串里用到，完全没必要在函式最前面无条件计算——后果是任何巫师
  一旦自己的环境意外变成空（不论是本档案 §7.11 那类 bug 还是其他
  未知原因），`goto` 本身作为"自救"工具反而永久失效，连去别的房
  间重新落脚都做不到。修复：判空后再取 `file_name()`
  （`where_me ? (string)file_name(where_me) : "无环境"`）。跨库检
  查同一段代码（`ll_me = (string)file_name(where_me)`）只在
  `xkyxciii` 和 `xkyx3b`（很可能是同源姊妹档案）命中，命中率太低，
  未作为跨库扫描立项，仅在本档案修复并记录，供以后遇到同源档案时
  参考。
- **死亡/复活循环现场验证**：巫师账号在中央广场 `clone` 出一个
  "扬武将军"NPC，`force <测试角色> to kill yangwu` 逼真实战斗一
  击致死（"秦侠死死了。"），重新连线后角色正确复活于
  `REVIVE_ROOM`（`/d/center/chenghuangmiao`，城隍庙），
  `score` 显示的死亡惩罚符合预期：气血精气神清零至个位数、潜能
  从 500 降到 251、经验从 4000 降到 3961、"死亡"计数器正确 +1。
  全程无崩溃、无卡死、无未捕获错误。
- **留言板发帖/阅读现场验证**：巫师账号在中央广场对
  `中央广场留言板` 执行 `post <标题>`，走完编辑器交互
  （`.` 结束输入），提示"留言完毕。"，`read <序号>` 能正常读出
  历史留言内容。`debug.log` 全程干净。（测试产生的留言已从
  `work/data/board/guangchang.o` 存档里撤销，不作为本次改动的一
  部分提交。）
- 本轮结论：round one 修复的 §7.11 类 bug 是这份档案迄今为止影响
  面最大的问题；round two 补完的死亡/复活/留言板全部正常，另外顺
  手确认并修复了两个此前搁置的小问题（真实的 §7.90 eval-cost 崩
  溃、goto 自救失效）。这份档案目前没有已知未处理的发现。

## 深度功能测试（2026-08-18，round three）——发现并修复：信箱系统全域失效

本轮目标是比 round two 更深入地补完经济、拜师（宗门）、通信（邮
件）等此前未覆盖的子系统。重开全新驱动进程，用管理员账号
`fluffos`/`Mud@2026`（round two 留下的旧号密码未知/未追踪，已删
除重新注册）和一个全新普通玩家账号 `qintestv`/`秦测试三`
（纯字母 id——注意这份档案的 `check_legal_id()` 不允许数字，试
过带数字的 id 会被直接拒绝，这是设计限制不是 bug）分别验证。

- **注册流程回归**：`qintestv` 完整走完英文id→y/n确认→中文名字
  →密码+确认→电子邮件→性别→种族→进入游戏，`look` 正确显示新手
  培训室及出口、NPC，`score` 属性正常——确认 round one 修复的
  §7.11 类 bug（新角色永久没有出生房间）依然稳固，未回归。
- **经济系统（当铺）现场验证**：`/d/center/hockshop` 当铺老板
  （`hockman`，继承 `feature/pawnowner.lpc`）的 `value`、
  `sell`、`pawn`、`redeem`/`ransom` 四个指令全部正常：`value
  vase` 正确报价，`sell vase` 按 80% 估值换钱，`pawn vase` 按
  40% 估值当出并给当票，`ransom vase` 正确赎回物品并扣费。古玩
  店 `curio_seller`（继承 `feature/vendor.lpc`）的 `list`
  指令正常显示可购商品。全程 `debug.log` 干净。
- **拜师（宗门）机制现场验证**：`goto /d/wudangshan/wd-lwc` 后对
  真实宗门大师 NPC 宋远桥（`song_yuanqiao.lpc`）执行
  `apprentice song yuanqiao`（注意实际 id 是"song yuanqiao"带
  空格，不是文件名的下划线写法，也不能用中文名"宋远桥"本身——
  `feature/name.lpc` 的 `id()` 只认 `set_name()` 第二个参数指定
  的 id 阵列，不会自动把第一个参数（显示名）加进去，这是这份档
  案里所有具名角色的通用行为，不是 bug）。测试账号胆识
  （cor）/定力（cps）都是 16，低于 `song_yuanqiao.lpc` 里
  `attempt_apprentice()` 要求的 20 门槛，NPC 正确拒绝（"学剑之
  人必须胆大心细，依我看……的资质似乎不宜？"）——这是源码里明确
  的属性门槛判定，属于设计，不是 bug。`apprentice cancel` 也正
  常工作。
- **真实 bug：`adm/daemons/logind.lpc` 的 `enter_world()` 里一行
  多余的 `destruct(mail_box)` 导致信箱/邮件系统对每一个玩家、每
  一次登录都彻底失效**：`obj/misc/mailbox.lpc` 是一个完整的邮件
  子系统（`send`/`mail`/`forward`/`check`/`from`/`read`/
  `discard` 共 7 个指令，长描述里还专门列出了使用说明），设计上
  应该在登录时挂到玩家身上并常驻（提供指令、在 `init()` 里报告
  未读信件数）。但 `enter_world()` 里紧接着创建/取得这个信箱对
  象之后，无条件对它调用了 `destruct(mail_box)`——不管这个信箱
  是刚创建的还是玩家早就有的、里面存了信的那个，一律当场销毁。
  后果：`init()` 里注册的 `add_action` 全部随对象销毁失效，玩家
  当场就失去所有邮件指令，`check`/`from`/`read`/`discard`/
  `mail`/`send`/`forward` 全部返回"什麼？"（未知指令）——现场用
  管理员账号验证：修复前，全新登录后立即 `check`/`from`/`mail
  qintestz` 三个指令均返回"什麼？"，`i` 指令的物品栏列表里也完
  全看不到信箱这个物件。信件本身的磁盘存档（`F_SAVE`，按
  `USER_DIR + id[0..0] + "/" + id + "/mail"` 路径）不受影响（因
  为存信/读信/丢信各自会显式调用 `save()`），所以没有数据丢失风
  险，但整个邮件功能对所有玩家、所有会话都是彻底哑火的——这是一
  个全局性、每次必现的功能失效，不是边角案例。
  - **修复**：删掉 `enter_world()` 里那行多余的
    `destruct(mail_box);`，保留前面创建/取得信箱并 `move()` 进
    玩家身上的逻辑不变（这正是触发 `init()` 挂载指令、显示未读
    信件数的必要步骤）。
  - **现场验证**：重启全新驱动进程，修复前先复现（`check`/
    `from`/`mail qintestz` 均"什麼？"，`i` 里没有信箱），应用修
    复后重新登录，`check`/`from` 都能正常报告"你的信箱中目前没
    有任何信件"，`i` 里出现"巫侠的信箱 (mailbox)"物件；完整走了
    一次 `mail fluffos`（给自己写信）→标题→正文→`.`结束→`y`
    保留副本→`check`（正确显示信件列表）→`read 1`（正确显示标
    题/寄信人/正文）→`discard 1`（正确丢弃，`check` 数量正确减
    一）。全程 `debug.log` 零错误。（给自己写信且选择"保留副
    本"会看到 2 封相同的信——这是 `confirm_copy()` 自留一份加
    `send_mail()` 内部再存一份到同一个信箱的自然结果，只在"自己
    寄给自己"这种边角用法下出现，不影响正常的"寄给别人"流程，未
    作为 bug 处理。）
  - **跨库排查**：对全仓库 227 个档案的 `logind.lpc` 做了
    `grep -rl "destruct(mail_box)"` 全库扫描，命中且仅命中两份
    档案：本档案 `xkyxciii` 和它的姊妹档案 `xkyx3b`（round two
    笔记里已经记录过这两份档案同源，共享同一段 `goto.lpc` 自救
    失效 bug）。`xkyx3b` 尚未验证过是否真的触发（未启动它的驱动
    测试），但源码里那一行 `destruct(mail_box);` 与本档案修复前
    完全一致，逻辑上必然有同样的问题。因为全库范围只找到这两个
    实例（低于跨库批量扫描立项的门槛），本轮只修复了
    `xkyxciii`，未touch `xkyx3b`，留给下次测到 `xkyx3b` 时参考
    本条记录直接验证/修复。
- **邮件、当铺、拜师之外**：留言板/死亡复活已在 round two 验证过
  未重复测试；补充确认了 `redeem`/`ransom`（当铺赎回）此前两轮
  都没测过的指令，功能正常。
- 本轮结论：找到并修复了一个全局性、每次必现、影响全部玩家的真
  实 bug（邮件系统失效），是本档案迄今为止修复过的 bug 里第二严
  重的（仅次于 round one 的出生房间 bug）——同样是"score 等基础
  指令一切正常，但一整块子系统悄无声息地失效"的模式。经济（当
  铺/古玩店）、拜师门槛判定，均验证正常、无新发现。
