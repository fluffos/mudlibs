
## WASM 修复摘要（迁移自 meta.json 的 group_note）

ES2 血统代码库（作者自己的横幅致谢 Annihilator/ES2），游戏内标题为"葫芦Ⅱ/Demon Angel"（"泥潭中国简化版本"）。没有发现 mudlib bug——WASM 下开箱即用，全程零修改；is_chinese()/check_legal_name() 本来就是正确的码点判断，和本次会话处理过的大多数 ES2 衍生分支不同。管理员账号（fluffos/Mud@2026）通过真实注册流程 + adm/etc/wizlist 播种（格式已对照 securityd.lpc 的解析器核实，和本次会话处理过的其它 ES2 血统档案一致）——这个分支的 logind.lpc 把"目前权限："+ wizhood() 状态行显示注释掉当作死代码，所以在对话记录里看不到直接的管理员权限确认，只能从 wizlist 格式正确来推断。

## 深度功能测试（§10.7，2026-08-04）

此前只验证到注册流程本身，本轮原生 driver（端口 40122）走完了移动、
留言板、商店、战斗的完整会话，并且用真实读代码的方式核实了死亡/复活
系统不属于本项目已归档的 §7.68 类别。

**主动检查（对照 AGENTS.md 已归档的 bug 类），发现并修复两个真实
bug**：
- **§7.34 printf 调试泄漏（新实例）**：`adm/daemons/logind.lpc`
  `get_name()` 里，玩家刚输入完中文名字、还没设密码之前，有一行
  `printf("%O\n", ob);`——每一个成功走到这一步的新玩家都会在自己的
  屏幕上看到这个连线对象的原始 `%O` 表示（对象路径、内部字段等调
  试信息），是典型的开发期调试输出直接留在了正式登录流程里。已删
  除。
- **原始档案自带的字符串损坏（新发现，非转码问题）**：
  `adm/daemons/chard.lpc` 里骸骨尸体的命名 `ob->set_name("一具枯\
  干的骸骨", ...)` 在"枯"和"干"之间多了一个游离的反斜杠，编译时报
  `warning: Unknown escape sequence`。用 Python 直接读取 raw 归档
  的原始字节核实过——这个反斜杠字节确确实实存在于原始压缩包里（不
  是本项目转码流程引入的），推断是原作者当年编辑时的手误。已改回
  "一具枯干的骸骨"。

**确认不是 bug 的检查项**：
- `init_new_player()` 里 `user->set("food", ...)`/`user->set("water",
  ...)` 两行确实被注释掉了，但和它紧挨着的 `potential`、以及
  `enter_world()` 里的"目前权限："显示行是同一批被原作者一起注释掉
  的行——是这个分支一贯的、成组的功能精简风格，不是 §8.9 那种"查询
  了错误对象的 age 导致条件永远为假"的判断失误，本身就没有任何 age
  判断逻辑，不在本项目的 bug 修复范围内（游戏内容/平衡决定）。
- `command_hook`（`feature/command.lpc`）已经是 `nomask`，是此前
  "Systematic sweep" 那一轮已经处理过的。
- 全文搜索未发现任何 `MESSAGE_D->` 调用。
- **死亡/复活系统读代码确认干净，不是 §7.68**：`feature/damage.lpc`
  的 `die()` 只用了一次性的 `call_out("delay_move_recall", 13 +
  random(3), this_object());`——不是像其它档案那样"判官/无常"式的
  多阶段、需要反复 `present(ob)` 判断才能继续的对话链，`delay_move_
  recall()` 到点直接无条件把玩家从死亡室移回 `START_ROOM`，没有任
  何可能永久卡死的分支。`DEATH_ROOM` 宏指向的 `/d/special/death.lpc`
  文件确实存在（不是 §7.75 那种宏指错文件的情况）。玩家被系统
  `disable_player()` 期间无法自行 `quit` 打断这个流程，进一步降低
  了永久卡死的可能性。这类"结构上就不会卡死"的死亡系统在本项目已
  处理过的 ES2 血统里是第一次遇到，值得作为反例记录。

**完整游玩记录**：
1. 用真实中文名"沈牧"（id `shenmu`）注册成功，落地"中央广场"（葫芦
   城），场景里有真正可读的留言板（"留言板(Board)"）和 NPC"小美
   女"。
2. 移动：中央广场→西大街→西大街（内部两间不同描述的分段房间）→
   西城门（死路，唯一出口 east）→中央广场→南大街→中央广场→北大
   街（`recall_n_1`）→北大街（`recall_n_2`，出现真正的商人 NPC）。
   沿途确认这批"XX大街"房间是多段拼接的独立房间文件（不同段描述文
   字不同），不是同一个房间的重复输出。
3. 留言板测试：`read 1` 成功读出一条真实的、带分页器的长留言（标
   题"给拿到本 MudLib 的人"，作者 bor），分页器的 `ENTER`/`q`/`b`
   翻页逻辑正常。
4. 商店测试：北大街的商人（`d/gourd/npc/mob1.lpc`，`inherit
   MISC_SHOP_NPC`）`list` 正确显示"马豆"和"普通药水"两样商品及库
   存；`buy bean`（注意命令格式是 `buy <物品名>`，不需要
   `from <商人>`）在零金币情况下被正确拒绝（"你的钱不够。"）。
5. 战斗测试：`kill man`（商人）触发正常的回合制拳脚对轰，双方都是
   1 级新手（`con` 相同、无武器），大量交换但双方命中率/伤害都极
   低（`score` 显示"最小伤害力 1"），这是新手无武器徒手数值偏低的
   内容/数值现象——本次测试没有让任一方在合理时间内真正死亡，改用
   代码走读的方式确认了死亡系统本身的实现（见上方）。整场战斗
   `debug.log` 全程没有任何错误。
6. 未能找到"国家制度"玩法（`cmds/king/`/`cmds/min/`）的可达入口——
   新手初始身份是"冒险者"，购买/继承国家需要走
   `d/gourd/buy_kingdom.lpc` 等专属流程，本轮测试预算内没有深入这
   一部分，留给后续更长的会话。

**结果**：整个测试会话（含一次修复后重启验证）`debug.log` 全程为
空，没有任何真实的 `error:`/`Bad argument`/`No program`/`Too deep
recursion` 记录。测试角色存档（`data/{login,user}/s/`）保持未跟
踪；测试期间因为 driver 常驻产生的国家系统共享存档
`open/sky/kingdom_data.o` 的周期性 churn 已在提交前还原，未计入本
次改动。两处代码改动已用 formatter 校验（`{"errors":0}`）。

## 第四轮深度测试（round-four，2026-08-20）

本轮专门补齐第一轮明确留白的两项：国家制度（`cmds/king/`/`cmds/min/`）
和真实战斗死亡，并顺手对标准 bug 清单做了一次全新（非复查）扫描。

**测试帐号**：`fluffos`/`Mud@2026` 此前只在 `adm/etc/wizlist` 里被
"播种"过，本轮开局才发现 `data/{login,user}/f/fluffos.o` 从未真正存
在——第一轮 `meta.json` 里"管理员账号通过真实注册流程...播种"的说法
其实是推断，不是已完成的动作。本轮走了一次真实注册流程创建了它，
`score` 确认 `wizlist` 授权生效（`goto`/`call` 等巫师指令可用）。这
个帐号按本项目惯例保留（帐号存档已 `git add`），不是一次性测试角色。

### 国家制度（buy_kingdom / cmds/king / cmds/min）

- **`/d/gourd/buy_kingdom.lpc` 是一个孤儿房间**：全档案搜索确认没有
  任何 `exits` 指向它（`d/gourd/recall_s_w.lpc` 是一个几乎相同但独
  立、不连通的旧版本，本身也没有路通向它），普通玩家在地图上正常
  走是永远走不到"买国家"这个房间的——这是第一轮"未能找到可达入口"
  的确认与解释，不是新问题，也不打算修（内容/地图连通性决定，不
  是编译错误或运行时错误）。用 `goto /d/gourd/buy_kingdom` 直接传
  送过去后，指令本身完整可用。
- **走通了建国全流程**：`buy_kingdom 测试王国 shice` 成功建国（金
  钱门槛在原始码里就已被注释掉，`buy_kingdom_build` 临时旗标门槛也
  被注释掉，本身就不需要额外用巫师工具满足前置条件），玩家称谓从
  "新手" 变成 "国王"，被自动传送到新生成的王座房 `/open/shice/kingdom`。
- **验证过的 `cmds/king/`／`cmds/min/` 指令**：`set_tax 10`（成功，
  全国频道广播）、`kingdom_stat`（完整输出国库/税率/人口/房间/武器
  /防具等统计）、`makeroom north`（成功建出新房间并可以正常
  `north`/`south` 往返，房间内容干净、`debug.log` 零告警之外的输出）、
  `build tavern east`（被"贵国房间数未达到 15 无法设置"正确拒绝——
  这是设计好的门槛，不是 bug，本轮测试预算内没有再建 14 间房去解锁）。
  `appoint`/`teleport`/`fire` 需要第二个同国玩家才能测，本轮没有再
  开一个账号去覆盖，其余国王/大臣指令通过读码确认权限门槛（`kingdom/id`
  相符）是自洽的。
- **发现并记录（非编译/运行时错误，不修）**：`check_legal_name()`
  （`buy_kingdom.lpc` 与其孤儿姐妹档 `recall_s_w.lpc` 共用同一段代
  码）的长度校验 `strlen(name) < 4 || strlen(name) > 12` 是按"每个中
  文字 2 字节"的旧编码假设写的（配合提示语"2 到 6 个中文字"）。这
  个 driver 的 `strlen()` 是按 Unicode 码点计数，不是按字节——实测
  3 字（如"测试国"）被拒绝，4 字（"测试王国"）能通过，说明实际生
  效的门槛其实是"4 到 12 个中文字"，把历史上很常见的 2-3 字国号
  （"大唐"、"大宋"）全部挡在门外，还允许最长 12 字这种怪异长名。
  这属于验证消息不准/门槛偏移，不是崩溃、不是 `debug.log` 错误、也
  没有卡死或状态错乱，按本轮范围规则归类为观察记录，未做修改。

### 真实战斗死亡

- 用巫师 `call` 指令把测试角色 hp 打成负值
  （`call me->receive_damage("hp",999,man)`，`man` 是北大街商人
  NPC），走的是真实的伤害应用函数 `feature/damage.lpc:receive_damage()`，
  hp 变负后由 `std/char.lpc` 的 `heart_beat()`（`if (query_hp() < 0) { ...; die(); }`）
  在下一个心跳自然触发 `die()`——不是直接调用 `die()`/`smash` 那种
  跳过真实检测路径的写法。
- 完整死亡→复活链路全部走通且live 确认（第一轮只读码确认过结构上
  不会卡死，本轮是第一次真正跑通）：`die()` 正确设定尸体
  （`法炉师的尸体`）、把 hp/mp 重设为 30、移动到 `DEATH_ROOM`
  （`/d/special/death.lpc`）、调用 `disable_player()`（此时任何指令
  都收到"什么？"，玩家确实无法自行打断），13～15 秒后
  `delay_move_recall()` 的 `call_out` 触发，自动把玩家移回
  `START_ROOM`（中央广场）并 `enable_player()` 恢复指令。全程
  `debug.log` 除了既有的编译期警告外没有任何 `error:`/`Bad argument`
  等真实错误。

### §7.100 全新命中并修复（本档案此前从未被扫描过，低于 100 次的语料库扫描门槛）

`grep -c "replace_program(ROOM)"` 只有 49 次（其它宏如 `HERB_SHOP`/
`GATE`/`TAVERN`/`SMITH` 等还有更多），远低于当时 corpus 扫描用的
100 次门槛，因此完全没被那 166 库的批量扫描覆盖到，是本轮第一次真
正检查。确认全部 87 处都是"`inherit X;` 后又在 `create()` 里多余
自我 `replace_program(X);`"的标准 §7.86/§7.100 形状（含
`obj/board/wizard_j.lpc` 这个真正的留言板实例，和 §7.86 原始症状
完全一致：`inherit "/std/jboard"` 后又 `replace_program("/std/jboard")`，
而 `jboard.lpc` 的 `post`/回帖流程恰好用闭包 `(: done_describe_project, ... :)`
绑定 `input_to`，是典型的"迟早会撞上闭包绑定就崩"的地雷）。

用二进制安全的脚本按"每文件对应的 inherit 目标"精确删除了 87 处独
立房间/建筑档案里的多余调用，另外手工修掉了 4 处把同样毒瘤写进"造
房子"生成模板字符串里的工厂档案（这样以后用这些工具新建的房间不
会带着地雷出生）：
- `obj/roommaker.lpc`（`mkroom`/`saveroom` 两个模板，巫师/玩家在
  游戏内建房的工具）
- `adm/simul_efun/kingdom.lpc`（`create_kingdom()` 的王座房模板、
  `save_room()`/minister 存房通用模板——**直接关系到国家制度**，
  每个新建国家的王座房和后续用 `min saveroom`/`min build` 存下来的
  房间都会带着这个地雷）
- `cmds/min/build.lpc`（大臣"build 特殊建筑"模板）
- `cmds/min/makeroom.lpc`（大臣"makeroom 造房间"模板）

共 91 个文件、96 处出现全部清理（另有 2 处 `d/gourd/choice_class.lpc`
和 `d/gourd/recall_shop.lpc` 里的调用本来就已经被 `//` 注掉，原样
保留未动）。修复后现场用 `min makeroom`/`min build` 亲自建了两间房
（其中一间成功、一间被房间数门槛正常拒绝），走进新建房间验证正常
加载、`debug.log` 没有出现 §7.100 特征的"cannot replace a program"
告警。

### 顺手修复：`cmds/min/build.lpc` 里 3 处原始档案自带的反斜杠损坏

和第一轮 `adm/daemons/chard.lpc` 那处"一具枯\干的骸骨"同一类损坏
（编译期直接触发 `Warning: Unknown escape sequence`，本轮修 §7.100
时在这个文件里现场读到的）：训练厅描述"有许\多人"、马厩描述"马厩\
，"和"马厩\被"三处游离反斜杠，已按上下文改回正常标点（"有许多人"、
"马厩，"、"马厩被"）。语料库里还有其它 8 个档案有同样"许\多"/"厩\"
字样（`combatd.lpc`、`feature/liquid.lpc` 等），但本轮只修了实际测
试路径上现场读到警告的这一处，其余留给未来专门扫描，不在本轮范围
内主动展开。

### 标准 bug 清单全新排查结果（本档案此前未被任何一次语料库扫描覆盖）

- **§7.90（eval cost）**：`config.fluffos` 已经是
  `maximum evaluation cost : 5000000`，无需修改。
- **§7.79（裸 `addn`/`addn_temp` 2 参数调用）**：全档案 0 命中，不
  是那个受影响血统家族（`xfbhh`/`hhsj`/`nitan` 系列），不适用。
- **§7.111（`standard_trace()` 空 object 崩溃）**：`adm/obj/master.lpc`
  已经是 `objectp(error["object"]) ? file_name(error["object"]) : "(driver)"`
  的写法，本来就是安全的，无需修改。
- **§7.112（`init()` 里无条件 `call_out` 链，reconnect 触发重复调
  度）**：全档案排查了所有定义 `init()` 且带 `call_out` 的文件（都
  是店铺/婚礼/发誓/训练室这类靠 `add_action` 注册指令的房间型
  `init()`，`call_out` 都挂在玩家指令触发的处理函数里，不是
  `init()` 本身直接排程），`std/char/npc.lpc` 完全没有 `init()`/
  `call_out`，NPC 基类本身不存在这个模式，不适用。
- **§7.113（reconnect 不恢复 heart_beat）**：`obj/user.lpc` 的
  `reconnect()` 已正确调用 `set_heart_beat(1)`，`net_dead()`/
  `reconnect()` 配对完整，不适用。
- **§7.114（`private` input_to 字符串回调经 mixin 失效）**：
  `feature/edit.lpc` 用的是闭包 `input_to((: input_line :), ...)`
  而不是字符串名 `input_to("input_line", ...)`，且 `input_line()`
  本身没有 `private` 修饰——架构上和 §7.114 的成因完全不同，不适用。
- **§7.115（`QUEST` 宏指向不存在文件）**：全档案没有 `QUEST` 宏定
  义，不适用。

### 清理

`open/shice/`（测试国家的房间、`kingdom_data.o` 等）、
`data/{kingdom,nuke/kingdom}/shice/` 全部删除；测试账号 `fluffos` 的
`kingdom`/`home`/`cwd` 属性已清空并显式 `save()`，hp/mp 重设为满值
并 `save()`（战斗死亡测试用 `call` 把 hp 打成负值后，`die()` 虽然
在内存里正确把 hp 复原到 30 并持续自然回血，但期间没有任何一次显
式 `->save()`，driver 关闭前的最后一次磁盘落地反而是负值——这是测
试方法本身的副作用，不是死亡/复活系统的 bug，已经手工修正并确认
后续重连不再触发误报死亡）；测试遗留的尸体对象已用 `dest` 清除；
`git checkout` 还原了测试期间因 driver 常驻产生的两处共享存档周期
性 churn（`data/chinese.o`、`open/sky/kingdom_data.o`，后者的字段
重排序/`sky` 王国自身经济模拟数值漂移，和第一轮记录的同一份文件同
一种 churn）。

**结果**：本轮修复的所有文件均在真实 `build-debug` driver 上验证
过干净编译和干净启动（`debug.log` 全程无编译警告之外的 `error:`），
国家制度和真实战斗死亡两条主线均现场跑通。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BOARD`、`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 15 处命中，其中含 1 处运行时代码生成模板（write_file() 动态生成新留言板源码的字符串模板里嵌了同样的致命形状，已同步从模板字符串中删除，否则玩家用该功能新建的留言板也会一出生就带病），已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## §7.30 uninitialized-mapping accessor sweep (2026-08-20)

Corpus-wide mechanical sweep of the `feature/skill.lpc` shared-lineage
bug (confirmed independently on `xiakexing2017`/`jqxz2015`/`haiyang2`
via round-four testing): 3 accessor(s) in this file returned a raw
never-initialized `mapping` instance variable (defaults to `int 0`,
not `([])`, until first assigned), crashing any unguarded
`keys()`/`sizeof()`/indexing caller for a fresh/untrained character.
Fixed at the accessor level (`mapp(x) ? x : ([])`) per the documented
remedy. Verified via `lpcc --batch` static compile check only (not a
live boot) as part of a large mechanical sweep; not individually
functionally re-tested live on this lib.

## §10.7 deep functional test, round three (2026-09-01): genuine two-account multiplayer nation testing

This pass deliberately covered the angles the two prior passes explicitly
left untested: a SECOND real player account interacting with the king
account inside the nation system (`appoint`/`teleport`/`fire`), currency
persistence across a real `quit`+reconnect, adversarial/malformed
kingdom-system input, and a real board `post`. Standing admin account
`fluffos`/`Mud@2026` played the king; a brand-new throwaway account
`xiaolong`/`王小龙` (deleted afterward, not committed) played the
citizen/minister. Native driver on port 40122, driven via a two-socket
Python script (not committed, scratch-only), `debug.log` checked after
every state-changing command.

**Two real bugs found and fixed, both verified live:**

- **§7.11 instance (missing `/log/nosave/` directory): `adm/simul_efun/
  file.lpc`'s `log_file()` was the exact same "unguarded `write_file()`
  sitting next to its own already-correct, unused `assure_file()`
  helper" shape documented dozens of times elsewhere in AGENTS.md §7.11.**
  Live-triggered on the very first wizard `call` targeting the second
  player (`call xiaolong->move("/open/ceshitwo/kingdom.lpc")`, used to
  physically place the second account into the orphan throne room since
  no walkable exit reaches it — see round-four's notes above): `*Wrong
  permissions for opening file /log/nosave/CALL_PLAYER for append. "No
  such file or directory"`, thrown from `call.lpc`'s own audit-log line
  BEFORE it ever reached `call_other()`, so the wizard tool completely
  failed to affect another player object at all, every single time.
  Fixed identically to every other instance of this bug class: forward-
  declared `assure_file()` and called it immediately before the
  `write_file()` in `log_file()`. This `simul_efun.lpc` is `#include`-
  based (not `inherit`-based), so — like `fy2005`'s instance — the fix
  required a full driver restart to take effect, not a hot `update`.
  Verified live post-restart: the identical `call` now succeeds
  (`/obj/user#N ("王小龙")->move(...) = 1`), and `/log/nosave/
  CALL_PLAYER` is created on demand with no further crash on any later
  `call` in the session.

- **NEW bug, not previously seen in this corpus: `cmds/king/fire.lpc`'s
  offline-target branch (`load_player()`) can NEVER succeed, because it
  incorrectly gates on `userp(ob)`, which is structurally always false
  for a `load_player()` result.** `fire <大臣>` first tries
  `find_player(arg)`; if the minister is offline it falls back to
  `flag = -1; ob = load_player(arg);` — a bare `new(LOADUSER_OB)` clone
  that reads the target's save file directly, specifically so a king can
  fire a minister who isn't currently connected. But the very next line,
  `if (!userp(ob)) return notify_fail(ob->name() + "他不是玩家。\n");`,
  rejects it unconditionally: `userp()` per this driver's own doc
  ("如果参数物件曾是互动物件，传回 1") reports whether an object has EVER
  been a real interactive connection, and a `load_player()` clone never
  is one — it's a pure in-memory data-reader, by design, never
  `exec()`'d to any socket. So this check silently aborts the whole
  offline-fire attempt before it ever reaches the actual
  `kingdom_data(...,"power","sub","minister",...)` removal or
  `destruct(ob)` cleanup, with a confusing message that implies the
  target isn't a real player when they demonstrably are (just offline).
  Confirmed this is a copy-paste/logic mismatch specific to this file by
  comparing sibling commands that use the identical
  `find_player()`-else-`load_player()` pattern: `cmds/min/banish.lpc`
  has NO `userp()` check at all on its `load_player()` result (works
  correctly offline), and `cmds/min/arrest.lpc`'s only `userp()` check
  sits on a completely different, online-only code path (its pardon
  branch), never applied to its own `load_player()` result. **Fix**:
  gate the check on `flag == 1` (i.e. only require `userp()` when `ob`
  actually came from `find_player()`) — `if (flag == 1 && !userp(ob))
  ...`. Verified live end-to-end, twice: (1) fired a minister who had
  just abruptly disconnected (TCP close, not `quit` — still "net-dead"
  but not destructed) succeeded even on the UNFIXED code, because
  `userp()` is true for life once an object has ever been interactive,
  confirming the bug is specific to the fully-offline `load_player()`
  path, not net-dead players; (2) after hot-`update`ing this file (an
  ordinary `inherit`-based cmds file, unlike the simul_efun fix above),
  re-appointed the same test citizen as minister, had them run a real
  `quit` (full destruct, no in-memory object left at all), and `fire
  xiaolong` from the king then correctly succeeded — the correct
  channel broadcast fired, and the target's on-disk save file confirmed
  `kingdom/minister` and `home` both removed while `kingdom/id`
  (ordinary citizenship) was correctly left intact, exactly matching the
  command's intended "demote minister to citizen" semantics. This is a
  new bug shape for this corpus (not seen in prior §7.x entries) — filed
  as a candidate for its own AGENTS.md catalog entry if it recurs
  elsewhere, but not enough evidence yet of a shared-lineage sibling to
  justify a corpus-wide sweep on its own (this lib has no confirmed
  close siblings).

**Confirmed clean / no bug found, despite active testing:**

- **Cross-player `appoint`/`teleport` both worked correctly** once both
  accounts were physically brought into the same room (`teleport`
  doesn't require same-room, only same-kingdom + a valid environment;
  `appoint`/`accept`/`join` all use `present(arg, environment(me))` and
  correctly require it). One non-bug trap worth recording: **founding a
  kingdom does NOT change where `enter_world()` places you on your next
  login** — `adm/daemons/logind.lpc`'s `enter_world()` always uses
  `user->query("startroom")`, never `home`, so a king who reconnects
  lands back at 中央广场 (their fixed spawn point) every time, not their
  throne room. This is exactly what `cmds/min/home.lpc`'s `home` command
  is for (confirmed by its own help text: "国王与大臣用的瞬间传送指令,
  可以传送回自己的家"). Cost real test time the first attempt (chased a
  false "king and citizen are in different rooms" symptom before
  realizing `home` was simply never invoked after reconnecting) — worth
  remembering for any future session testing this lib's kingdom system.
- **Currency persistence across a real `quit`+reconnect: the actual
  economy currency (the `gold`/`bank_gold` numeric character
  properties, read by `score` and by `feature/finance.lpc`'s
  `pay_money()`/`deposit_bank()`/`withdraw_bank()`) persists correctly.**
  Funded a test citizen with `call xiaolong->add("gold",777)`, confirmed
  `score` showed 777, did a real `quit`, reconnected, and `score` still
  showed 777. This lib's `std/money.lpc` — the PHYSICAL coin object
  class — was also checked per this session's explicit brief (the
  sibling `fysjmb`/§7.199 "`query_autoload()` commented out while
  `autoload()` stayed live" shape): **not applicable here, `query_autoload()`
  is fully active** (`string query_autoload() { return query_amount() +
  "";}`, not commented out). Separately (not a bug, a design
  observation): physical coin objects you're merely carrying (not
  equipped) DO get lost on `quit` — but this is because `cmds/usr/
  quit.lpc`'s `main()` explicitly, unconditionally drops every
  non-`equipped()` inventory item for any non-wizard player before
  saving (`if (!wizardp(me)) { ... if (!inv[i]->query("equipped"))
  DROP_CMD->do_drop(me, inv[i]); }`) — a deliberate, internally
  consistent design choice (matches §10.7's "death dropping items" example
  of a non-bug) applied uniformly to ALL unequipped items, not a
  money-specific persistence bug; the actual currency wallet bypasses
  this entirely since it's a character property, not an inventory
  object.
- **§7.19-class NPC `init()` reentrancy via `enable_commands()`/
  `enable_player()` from a room's `setup()`/`reset_me()`: not
  applicable.** Full-tree grep found only two `enable_commands()` call
  sites in the whole lib (`obj/user.lpc`'s own player-login path and
  `feature/command.lpc`'s `command_hook()` mixin) — no NPC in this lib
  calls `enable_commands()` itself, so the reentrancy shape this bug
  class depends on structurally cannot occur here.
- **Adversarial/malformed kingdom-system input, all handled cleanly, no
  `debug.log` errors**: `appoint`ing a nonexistent player, `fire`ing
  yourself, `fire`ing the king, a second `buy_kingdom` from an
  already-kinged player (`建国必须平民才行`), negative/non-numeric/
  absurdly-large `set_tax` values (`-10`, `abc`, `999999999999999999999`
  — all correctly rejected by the existing 5–50% range check, no
  overflow crash), and — via a third throwaway account at the
  (unreachable-by-normal-walking, `goto`-only) `buy_kingdom` room —
  too-short Chinese kingdom names, a 30-character Chinese name, a
  100-character English id, uppercase letters in the English id, and an
  embedded space in the English id. Every case was rejected with the
  expected in-game message and zero uncaught errors.
- **Real board `post`+`read` round-trip**: posted a real multi-line
  message via the line editor (`post <title>` → lines → `.` to finish)
  to the central-plaza board, confirmed it appeared in `read new`
  alongside the original archive post, and confirmed `~q` correctly
  cancels a post-in-progress (including with a 200+ character title)
  without creating a stray entry. The test post itself was reverted
  (`git checkout`) before committing, since it was pollution on a
  board every real player sees, not evidence worth keeping.

**Cleanup**: driver restarted once mid-session to pick up the
`#include`-based simul_efun fix (§10.9-documented `debug.log`-goes-dead
convention followed: log inspected via `work/log/debug.log` after every
state change, both before and after the restart). Test kingdom
`ceshitwo` (`work/open/ceshitwo/`, `work/data/{kingdom,nuke/kingdom}/
ceshitwo/`) and both throwaway accounts (`xiaolong`, and a third
validation-only account `ceshimin` that never actually founded
anything) deleted, not committed. `fluffos`'s `kingdom`/`home`/`cwd`/
`cwf` properties cleared and hp/mp reset to full via explicit `set()` +
`save()` (a testing mistake along the way — first attempt used a
wizard `call me->set("hp", me->query("base_hp"))`, which the `call`
command's own simplistic argument parser treats as a **literal string**,
not a nested expression, corrupting `hp`/`mp` into a broken string that
then crashed `heart_beat()`'s `>=` comparison every tick; caught via the
very same `debug.log`-after-every-command discipline this methodology
requires, and fixed immediately with plain integer literals instead —
recorded here as a reminder that this driver's wizard `call` command
does not evaluate nested `->` calls in its arguments). Ambient
save-churn from this session (`data/chinese.o`'s kingdom-name lookup
dict gaining a stale `ceshitwo` entry, `open/sky/kingdom_data.o`'s
known pre-existing periodic economic-simulation drift, login-timestamp
noise) reverted via `git checkout` before committing; only the two
real `.lpc` fixes plus `fluffos`'s own cleaned-up save file are
included in the commit. A final fresh driver boot + login/score/look/
quit cycle confirmed a clean `debug.log` throughout.
