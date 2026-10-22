
## WASM 修复摘要（迁移自 meta.json 的 group_note）

时空游侠录（Roaming Swordsman）血统代码库，登入横幅为"非凡公子/新月传奇录II"。没有发现 mudlib bug——WASM 下开箱即用，全程零修复。唯一的门槛：get_id() 要求 id 提示后的第一个输入必须是字面字符串 "shikongyouxia3.0"（固定魔术字符串校验，不是加密），才会进入真正询问英文 id 的环节——不先发这个，每次注册尝试都会看到"你的客户端版本有问题"并断线。排版格式化工具的第三类盲点检查（CJK 重新加空格）在约 25 个"误报"里抓到了两处真正的损坏（d/huashan/map.lpc，一张 ASCII 地图，形态和 cctx 的一样；d/player/fyue_room.lpc，一段房间描述，格式化工具的分词器在这里失去同步）——两者都直接还原，没有手工修补。另外记录但没有修复：d/city/sj.lpc（一个无法到达、没有任何房间连向它的孤立房间）通篇有转档之前就存在的缺引号问题（该用字符串字面量的地方写成了裸词中文，比如 add_action(do_out, out) 应为 add_action("do_out", "out")）——如果真被加载会编译失败，但因为没有任何路径能到达这个房间，从不影响注册/游戏/退出流程。管理员账号（fluffos/Mud@2026）通过真实注册流程 + adm/etc/wizlist 播种。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 93 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试 / Deep functional test (AGENTS.md §10.7)

原生驱动（`~/src/fluffos/build/src/driver`，linux-debug + ASAN/UBSAN）从档案根目录启动，端口 40142 正常监听。WASM 验证跳过（emsdk 被代理拒绝，与其他档案一致，未在 WASM 下复测）。

**"天涯"血统关系确认**：本档案地图/门派内容与 `tybxjh`/`xhcii`/`zxty`/`jhfy2`/`xysylmhb`/`xyzxiiylzymh` 逐字节一致（README 已记录），AGENTS.md §7.68/§7.86/§8.9 的既有条目也已把 `ffxymud` 列为这条"天涯"血统的确认成员之一。**这不是本轮任务描述里猜测的"夕阳再现/XYZX"（`xyzxfy2`/`ylfyxa3`/`xajhzcjh` 那条，§7.11 反复确认的血统）**——AGENTS.md §11 的血统地图把"夕阳再现 family"（`xyzxfk`/`jhfy`/`xajhzcjh` 等）和"XYZX/炎龙封印 branch"（`xyzx3`/`ylfyxa3`/`longyunmeng`）列为两条独立血统，都不含 `ffxymud`；`ffxymud` 真正所属的"天涯"家族在 §11 里尚未有专门条目，但在 §7.68/§7.85/§7.86/§8.9 的正文叙述里反复被引用为独立于两者的第三条血统。误报的原因很好理解：三个家族名字/主题（夕阳、天涯、XYZX）字面上都容易联想到一起，但 `master.lpc`/`logind.lpc` 的具体实现互不相同。

### 发现并修复的 PROGRAMMING bug

1. **`log_file()` 缺少 `assure_file()` 目录保护（AGENTS.md §7.11 的又一确认实例，"天涯"家族第 N 次独立确认同一形状）**：`adm/simul_efun/file.lpc` 的 `log_file()` 直接 `write_file(LOG_DIR + file, text)`，全新检出 `work/log/` 下没有任何子目录。`adm/daemons/logind.lpc` 的 `get_gender()`（**新角色注册流程的最后一步**）紧跟着 `enter_world()` 之后调用 `log_file("login/newid.log", ...)`，`login/` 子目录不存在时抛出未捕获的 `*Wrong permissions for opening file /log/login/newid.log for append`。已确认这不会中断注册本身（`enter_world()` 已经先执行），但会在每一个全新角色的登录时刻在 debug.log 里留下一条未捕获运行期错误。修复：补上 `assure_file(LOG_DIR + file);`；因为同档案内 `assure_file()` 定义在 `log_file()` 之后，额外加了一行前向声明（AGENTS.md §6.5）。已用真实注册复现（修复前，见下方"实测过程"）并复测通过。
2. **`config.fluffos` 的 `maximum evaluation cost` 过低，导致注册流程 `get_email()→make_body()` 首次冷编译 `/clone/user/user` 整条继承链时中止（AGENTS.md §7.90 的 `xyj2000f`/`xiyouji450` 变体：`make_body()` 而非普通移动触发）**：本档案沿用项目模板默认值 `700000`，但 `/clone/user/user` 首次加载要拉入 `inherit/char/char.lpc` 及其近十个 `feature/*.lpc` 全部编译，加上 `securityd.lpc` 的 ACL 检查，实测**每一次全新注册**（新驱动进程、从未编译过这条继承链时）都在 `get_email()` 里以 `*Too long evaluation. Execution aborted.` 中止——连线对此没有任何提示，直接停在邮箱提示之后不再响应。修复：仿照项目里 30+ 档案的既有做法，将 `maximum evaluation cost` 提到 `5000000`。已用两次独立的全新驱动进程复现（修复前必然触发）并复测通过（修复后零次触发，含完整注册+战斗+死亡+退出+重连的整场会话）。
3. **`adm/daemons/logind.lpc` 的 `get_resp()`/`get_name()` 各有一处 `printf("%O\n", ob)` 调试输出泄漏给玩家（AGENTS.md §7.34 的又一确认实例，"天涯"家族里 `jhfy2` 的第九个 §8.9 实例报告里提到的"双路径 printf 变体"这次落在了取中文名字这一步，而不是 §8.9 那一行）**：玩家刚输入完中文名字，屏幕上会直接看到形如 `/clone/user/login#4` 的原始物件路径。已确认删除两处 `printf` 调用不影响任何后续逻辑（`ob->set("name", ...)` 紧跟在后面，未使用 `printf` 的返回值）。已用真实注册复现（修复前，见"实测过程"）并复测通过。
4. **新角色食物/饮水初始化门槛读了错误的物件（AGENTS.md §8.9 的第十个确认实例，"天涯"家族第二例——`jhfy2` 是第九例）**：`enter_world()` 里 `if (ob->query("age") == 14)`，`ob` 是登录用的临时连线物件，全档案没有任何地方对这个类别 `set("age", ...)`；真正的角色物件 `user` 才会在 `setup()` 里被设成 14 岁（`race/human.lpc` 的 `setup_human()`）。门槛永远为假，新角色的 `food`/`water` 从未被 `max_food_capacity()`/`max_water_capacity()` 初始化过。有意思的一点：和 `jhfy2` 一样（笔记里已记录"某些默认值另外把 food/water 填满了"），本档案的新角色在 `score` 里**看起来**食物/饮水是满的——这是 `race/human.lpc` 的 `setup_human()` 里另一段独立逻辑（`if (ob->query("mud_age") < 100) { if (!ob->query("water")) ob->set("water", ...); ... }`）顺带把新角色的 food/water 也填满了，掩盖了这个 bug 本该造成的"新角色一进游戏就挨饿"的直接症状——但 bug 本身（`enter_world()` 里那处门槛永远为假）依然是真实存在、需要修的逻辑错误：一旦这两个初始值被吃掉/清零（例如死亡+复活，或者未来任何一次修改动了 `race/human.lpc` 那段兜底逻辑），角色将永远无法再通过任何正常游戏内机制重新把食物/饮水填满，因为该走的那条初始化路径永远不会被触发。修复：`ob->query("age")` → `user->query("age")`。已用真实注册（`score` 复测确认食物/饮水两个条都能正确显示部分消耗后的中间值，证明修复后的门槛函数本身被正确执行且没有引入新的满/空判断错误）验证。
5. **`tribar_graph()` 的字节切片假设 UTF-8 字符仍是 2 字节宽（AGENTS.md §7.85 的又一确认实例，"天涯"家族原始实例）**：`cmds/usr/score.lpc`/`cmds/usr/sc.lpc`（玩家 `score`/`sc` 指令，逐字节相同的两份拷贝）和 `cmds/adm/score2.lpc`（管理员 `score2` 指令，25 格变体）三处 `tribar_graph()` 都残留 GBK 时代"每格 2 字节"的 `*2` 乘数，转成 UTF-8（每格 3 字节）后：`val=0` 时 `bar_string[0..-1]` 按本驱动的负索引惯例返回整个字串（空条显示成满条），且任何超过约 50% 的比例都会因切片越界被钳制成满条。**这个 bug 和上面第 4 条互相掩盖**：即使 §8.9 没被修，新角色食物/饮水条也会因为这个 bug 显示成满的；即使 §8.9 修复正确，食物/饮水条在真正接近满值之前也无法用来判断真实剩余量。修复：改写成不做字节假设的整数区间计算（`filled`/`shown` 两段直接按目标宽度线性换算，参考 AGENTS.md §7.85 记录的标准写法）。已用真实 `score`/`sc`/`score2` 三个指令复测：满值、约 94%（15/16、24/25 格）等中间值均正确显示部分消耗后的条形，未再出现"空/满不分"或过早封顶的现象。`cmds/usr/skills2.lpc` 也有一份同名函数，但实现方式完全不同（逐格 for 循环，未复用 `bar_string`/`*2` 那套算法），未发现同类问题，未改动。
6. **`cmds/adm/setskill.c.org` 丢失了正常的 `.lpc` 扩展名，管理员技能捷径指令实际不存在（AGENTS.md §7.94 的又一确认实例，此前已在 `xyzx3`/`dtxywzxzb` 独立确认）**：唯一候选文件（没有互相竞争的草稿版本，不涉及内容取舍），直接复制恢复为 `cmds/adm/setskill.lpc`。恢复后同时暴露了该文件自身的一处独立 copy-paste bug（同样是 `xyzx3`/`dtxywzxzb` 已确认过的形状）：非 `all` 的单一技能删除分支（`level==0`）里 `write()` 用的是只在 `all` 分支才赋值的 `skills[i]`，`setskill <目标> <单个技能> 0` 必定触发 `*Value being indexed is zero` 崩溃。已在同一次修复里改成引用真正的局部变量 `skill`。已用真实指令复现（对 `官兵` NPC 先 `setskill bing unarmed 0`，见"实测过程"）并复测通过，`setskill <目标> unarmed <正整数>` 的正常设置分支和 `all` 分支均未受影响。

### 实测过程（同一连续会话）

1. 读 README 记录的注册流程（登入横幅另称"非凡公子/新月传奇录II"），确认唯一门槛是连线后第一行必须原样输入字面量 `shikongyouxia3.0`（伪装成"请输入您的英文名字"提示，实际是 `get_id()` 的固定字串比对），验证通过后才真正问英文 id。
2. 全新注册真实中文名角色"夕阳侠客"（id `xiyangke`），走完整流程：`shikongyouxia3.0` → 英文名 → 确认建立 → 中文名 → 密码（≥5 字元）→ 确认密码 → 天赋（0 随机）→ 接受天赋 → 邮箱 → 性别。修复前在 `get_email()`→`make_body()` 首次冷编译时以 `*Too long evaluation` 中止（§7.90，见上）；修复并重启驱动后完整走完，MOTD、权限、上次登录时间正常显示，`look`/`score`/`i` 均正常。中文名提示后修复前会看到裸露的 `/clone/user/login#N` 调试输出（§7.34，见上）。
3. 战斗机制：`cmds/std/fight.lpc` 用 `can_speak` 判定安全切磋 vs 直接开打（`obj->query("can_speak")` 为真 → 走 `accept_fight()`/`fight_ob()`；否则走 `kill_ob()`），与本次会话在其他"天涯"血统档案里反复确认的变体一致。对新手客栈"店小二"（可讲话 NPC）使用 `fight`，正确触发协商对话，NPC 因未实现/拒绝切磋而回绝——机制本身（分支、`notify_fail`、无崩溃）验证通过。对北门"官兵"NPC 使用 `fight` 意外导致测试角色真正死亡——深入代码后确认 `d/city/npc/bing.lpc` 的 `accept_fight()` 是**有意**设计成"接受挑战但立刻反手用 `kill_ob()` 真打并给挑战者加上 500 回合通缉标记"的陷阱型 NPC（城市守卫，属于既有游戏内容设计，非程序 bug，已记录在下方"既有设计"一节）。改用 `d/city/npc/mu-ren.lpc`（练功木人，`no_die` 且 `accept_fight()` 会把自己的技能/属性同步成挑战者本人的等级）复测：连续多回合仅造成个位数伤害、`<气>` 条缓慢下降但远未见底、期间多次"你的「基本拳脚」进步了"，证实安全切磋机制在真正的安全 NPC 上工作正常。
4. 技能/门派获取，两条路径都验证：
   - **正常游戏内路径**：管理员 `goto /d/baituo/liangong`，对无条件接受的"李教头"（`d/baituo/npc/li.lpc`，`attempt_apprentice()` 无门槛）使用 `apprentice li`，成功拜师；`score` 确认头衔变为"白驼山派第三代弟子"、师父字段变为"李教头"。
   - **管理员捷径**：恢复出的 `cmds/adm/setskill.lpc`，`setskill fluffos unarmed 50`/`dodge 40` 成功设置（过程中发现并修复了上面第 6 个 bug 里的单技能删除崩溃，用 `setskill bing unarmed 0` 复现/复测）。`cmds/wiz/`、`cmds/adm/`、`cmds/arch/`（本档案没有 `cmds/arch/` 目录）范围内没有找到专门的"直接授予门派"指令；最接近的捷径是通用的 `force <NPC> to recruit <玩家id>`（借用 `apprentice`/`recruit` 同一套底层逻辑，而不是绕过它），如实记录未发现专门的门派授予指令。
5. quit 宽限期：全档案 grep `quit_time` 只在 `logind.lpc` 的重连门槛里被读取，从未被任何地方 `set()` 过（永远读到 0，门槛恒假，属于死代码而非会阻塞操作的 bug，记录在下方"既有设计"一节），未发现"新号退出即删号"逻辑，`cmds/usr/quit.lpc` 本身没有基于账号年龄的二次确认。因此对已复活的 `xiyangke` 直接发送真实 `quit` 指令（未使用"掐断连线模拟"这条备用路径）：非自动装载物品被正确丢弃、`欢迎下次再来` 正常显示、存档时间戳与退出时刻相符。
6. 等待真实时钟间隔（期间做静态代码审查、grep 血统关系、撰写本节笔记，实际间隔数分钟，驱动累计运行 30+ 分钟）后重新连线登录 `xiyangke`，`look`/`score`/`i` 确认角色位置、门派归属（未加入门派，符合预期）、死亡计数（1 次，符合修复前"官兵陷阱"那次真实死亡）、装备/背包状态全部正确持久化。
7. `grep` 全程 `log/debug.log`（本档案 `log directory` 配置解析到档案根目录下的 `log/`，而不是 `work/log/`——两处都检查过，本档案实际写入的是前者；`work/log/log`、`work/log/login/*` 是 mudlib 自己 `log_file()` 写的业务日志，不是驱动的 `debug.log`）：修复后的整场会话（含 2 次驱动重启、多次注册、战斗、死亡、setskill、拜师、quit、真实间隔重连）里未再出现任何未捕获运行期错误。

### 发现但判定为既有设计、未改动的现象

- **北门"官兵"NPC 的 `accept_fight()` 故意把"切磋"请求升级成真打并通缉挑战者**：`d/city/npc/bing.lpc` 第 61-66 行，`command("say 大爷我正想找人杀呐，今天算你倒霉。\n"); me->apply_condition("killer", 500); kill_ob(me); return 1;`——这是内容设计（城市守卫惩罚寻衅玩家），不是 `fight`/`can_speak` 机制本身的 bug；机制本身在安全 NPC（木人）身上验证正常。
- **`logind.lpc` 的 `quit_time` 重连冷却门槛永远不生效**：`get_passwd()` 里 `if (time() - (int)user->query("quit_time") < 50)` 是全档案唯一读取该字段的地方，没有任何 `set("quit_time", ...)` 调用——`quit.lpc` 本身也没有设置它。属于失效但"失效方向安全"（永远放行而不是永远拒绝）的死代码，不阻塞任何操作，未改动。
- **`d/city/sj.lpc`（"世界之巅"跳崖场景）通篇缺字符串引号**：此前 WASM 修复摘要已记录，孤立无法到达，本次深度测试同样未触及（没有任何房间路径能到达，不影响注册/战斗/拜师/退出/重连的完整流程）。

### 已清理

- 测试用一次性小号 `xiyangke` 的存档（`data/{login,user}/x/`）已删除，未提交。
- 管理员 `fluffos` 的存档已提交（`data/{login,user}/f/fluffos.o`），密码与 README 一致；账号在测试过程中拜入白驼山派并被设置了 unarmed/dodge 技能等级，属于走真实流程验证捷径/机制留下的痕迹，未额外清空。

## 深度功能测试（2026-08-12，round two，新驱动重测）

Re-tested against the freshly-rebuilt `build-debug/src/driver` (post
corpus-wide `quest_times`/`win_times` `%`-operator fix + the
Warning/warning driver-text revert).

### 发现并修复的 PROGRAMMING bug

1. **`log_error()`（`adm/obj/master.lpc:140`）完全没有严重度检查（AGENTS.md
   §7.34-class，与本轮此前 `wdxtym` 上修的形状完全相同——不是"算出
   severity 但没真正拿来 gate"，而是压根没有算）**：
   `if (this_player(1)) efun::write("编译时段错误：" + message + "\n");`
   把**所有**诊断信息（包括最普通的编译警告）无条件转发给当前连线的
   任何玩家，不区分是巫师还是普通玩家，也不区分警告还是错误。真实复现：
   一次全新驱动进程下的全新注册（首次冷编译级联，触发大量
   `Unknown #pragma, ignored.`/`Unused local variable` 一类的纯警告），
   新角色一进游戏前就先看到十几行原始编译诊断刷屏。修复：改成
   `if (this_player(1) && strsrch(message, "arning:") == -1) efun::write(...)`
   （沿用本轮项目统一的大小写无关 `"arning:"` 判断惯例）。已用同一新
   驱动进程下的第二次全新注册复测：debug.log 时间戳在整场会话前后
   均未变化（无新错误），且屏幕上不再出现任何编译诊断刷屏。

### Proactive checks（无需改动）

- `win_times` 修复确认存在且正确：`d/city2/npc/refereew.lpc:146`
  `(string)(to_int(query("win_times")) % 5)`。
- 未发现 `message()` simul_efun 包装函数（`void message(mixed` 全档案
  零命中）——不适用 message()-missing-varargs 这一类 bug。
- `adm/simul_efun/file.lpc` 的 `log_file()` 已经正确调用
  `assure_file()`（本档案第一轮测试里已修复过的 §7.11 实例）；
  `assure_file()` 本身末尾不做 `seteuid(getuid())` 重置，所以不属于
  `nitan_san`/`nt6nitan6win` 那种"assure_file 自己把 euid 重置掉"的
  形状，无需再修。

### 实测过程

新号 `chenmufb`/沐辰：`shikongyouxia3.0` → 英文 id → 确认建立 → 中文名
（无 y/n 确认，直接进密码环节，与档案内 `get_name()` 非空分支的实际
实现一致）→ 密码（≥5 字元）→ 确认密码 → 天赋（0 随机）→ 接受 → 邮箱
→ 性别，完整走通进入"北疆小镇"起始区域。修复前后各做一次全新注册；
修复前复现了上述编译诊断刷屏，修复后干净。`log/debug.log` 全程时间戳
未变化，确认无新增未捕获运行期错误。驱动最终按精确 PID kill，`ps -p`
确认已退出。

### 已清理

- 测试用一次性小号 `chenmufb` 的存档已删除，未提交。

## §7.100 房间基类 replace_program() 扫尾修复（2026-08-19）

`ROOM` 宏（`/inherit/room/room`）在本档案 2,087 处房间文件的
`create()` 里紧跟 `inherit ROOM;` 之后又多余调用了一次
`replace_program(ROOM);`——AGENTS.md §7.100 记录的同一个休眠 bug。
用 `fix_710_room.py` 扫过 `work/`，删除 2,085 处标准形状（净删
2,087 行，2 个文件各含 2 处）；`clone/misc/roommaker.lpc` 与
`d/huanggon/obj/roommaker.lpc`（两份独立的房间建造工具字符串拼接
模板）各剩 1 处 `str += "...replace_program(ROOM);..."` 变体，手工
改成 `str += "\n\tsetup();\n}\n";`。两份工具的 heredoc 模板本身已
经是干净的（没有这个 bug）。修复后 `work/` 下 0 处存活残留，其余
均为转档之前已注释掉的 `//` 行，原样保留；`work/data/` 下没有真实
`.lpc` 源码命中。`git diff --stat` 显示 2085 个文件净删 2085 行、
增 2 行，与脚本自报数字 + 2 处手工编辑吻合。

驱动干净启动（零新增编译错误、端口 40142 正常监听、`debug.log`
无任何"cannot replace"/"cannot bind"行）。管理员 `fluffos`
（`shikongyouxia3.0` 魔术字符串 + 密码 `Mud@2026`）实机登录成功，
`look`/`score`/`quit` 均正常，全程 `debug.log` 保持干净。管理员存
档的 last_on 时间戳漂移已用 `git checkout HEAD --` 还原，未提交。
驱动按精确 PID 结束。

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

## 深度功能测试（2026-09-04，shop）

Live pass, port **40142**. Prior §10.7 already did 白驼山李教头 `apprentice li`; this round is shop only. First send is the magic string `shikongyouxia3.0`, then id `fluffos` / `Mud@2026`. Current admin `score` shows 普通百姓 / 目前还没有师傅 (the 白驼山 title from the earlier pass is not on this save). `F_DEALER` 丐帮 refuse would not apply.

**Shop**: `goto /d/city/zuixianlou`. `clone /clone/money/gold` then `buy jitui` succeeded (“你向店小二买下一根烤鸡腿”, inventory 鸡腿 + 99 两银子 + 20 铜板). `list` initially crashed after printing 烤鸡腿: `shanzi.lpc` calls `init_shan(250, 2)` while `inherit SWORD` only defines `init_sword` — `Undefined function init_shan` then `*No program in object`. Fixed both copies (`d/city/npc/obj/shanzi.lpc` is the vendor path; `d/city/npc/shanzi.lpc` is a duplicate) to `init_sword`. After `update`, `list` shows the full board (鸡腿/扇子/酒袋/包子/养身丹) with no compile error.

No other code change.

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 5 here-document block(s) repaired (5 with the terminator glued to the last text line, 0 with it indented), so `End of file in text block` no longer hides the room or object behind them: `d/heimuya/shenggu.lpc`, `d/heimuya/tang.lpc`, `d/heimuya/npc/tang.lpc`, `d/quanzhen/manglin1.lpc`, `d/quanzhen/manglin2.lpc`. The terminator must start its line (the lexer's own test, KB 04 §6.10); a glued one lost its newline in the GBK -> UTF-8 conversion together with a half character, which stays out.

## 深度功能测试（§10.7，2026-10-05）— 任务表里的 `.c` 路径与任务守护进程的防护

`scripts/lpc_dynamic_rows.py`：`d/obj/quest/dynamic_location`、`d/obj/quest/dynamic_quest`、`quest/dynamic_location` 里 151 行写的是原档案的 `.c` 路径。转档时文件已改名 `.lpc`，而显式后缀按原样解析，`load_object("/d/x.c")`、`new("/d/obj/quest/x.c")` 返回 0 且不报错（KB 03 §4.2，KB 06 §7.220），所以 `adm/daemons/questd.lpc`、`adm/daemons/taskd.lpc` 读到的每一行都加载不出来：随机任务和任务物品从未生成，在 `create()` 里直接对结果调用 `tar->set()` 的版本还会崩溃，连带加载它的 cron 守护进程和 `give` 的任务钩子。这些行已改为 `.lpc`；另有 36 行指向的文件两种后缀都不存在（档案缺内容），保持原样。
`scripts/lpc_dynamic_quest_guard.py`：2 处 `spread_quest()` 调用（`init_dynamic_quest()` 的循环里）包进 `catch()`，缺失的任务物品或编译不过的房间只跳过那一个任务，守护进程照常加载、其余任务照常生成。
验证：`adm/daemons/questd.lpc`、`adm/daemons/taskd.lpc`和 cron 守护进程在新进程里加载（HEAD 一次，工作树三次，选房是随机的）：HEAD 通过 2 个，工作树三次分别通过 2、2、2 个（共 3 个），无回退；`adm/daemons/taskd.lpc` 在 HEAD 与工作树都加载失败，另有原因，与本次无关。

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `inherit/room/room.lpc`：`make_inventory()` 用 `catch()` 包住 `new(file)`，做不出来就返回 0；`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）；`reset()` 的 `default:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]][j])) continue;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-07）— 空的 `if (current_water == 0) {}`

5 个房间的 `valid_leave()` 里有一行什么也不做的 `if (current_water == 0) {}`（编译警告 `Expression has no side effects`），删去，行为不变：`d/gaochang/room11.lpc`、`d/gaochang/room12.lpc`、`d/gaochang/room13.lpc`、`d/gaochang/room14.lpc`、`d/xingxiu/shanjiao.lpc`。

## 深度功能测试（§10.7，2026-10-08）— 编译警告整理

`scripts/lpc_warnings.py ffxymud --fix` 加 `scripts/lpc_fix_no_effect.py --apply`，共改动 420 个 `.lpc` 和 3 个 `.h`（多为删去未用的局部变量）。HEAD 与工作树分别加载（新进程）：395 -> 395 通过，无回退；改过的头文件的 34 个包含者 34 -> 34 通过。启动时警告 8 -> 0；新进程登录（输入名字）正常。
（本库连线时检查专用客户端，裸 telnet 输入名字得到“你的客户端版本有问题!!”，与 HEAD 相同。）

## 深度功能测试（§10.7，2026-10-08）— `.lpc` 后缀的定宽切片

`.c` 改名 `.lpc` 时只改了字符串没改切片宽度：`f[<2..] == ".lpc"` 拿两个字符比四个字符，永远不成立（`!=` 永远成立），按后缀筛文件、去后缀的代码因此从不运行或截成 `x.l`（KB 06 §7.238）。`scripts/lpc_lpc_suffix_slice.py --apply` 改了 1 处比较、0 处去后缀（如 `cmds/wiz/ls.lpc`）；改动的文件 HEAD 与工作树分别加载（新进程），无回退。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 11 处，返回类型/原型 22 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 0 个，只在 #if 分支用的声明移进分支 1 个文件；改动 34 个文件，HEAD 与工作树各载入一次无回退（34 objects; HEAD PASS 34, tree PASS 34; regress 0; newly loading 0），这些文件的警告 34 -> 0。

- 2026-10-12：`adm/obj/xiang.lpc`、`p/obj/guizi.lpc` 写着 `int remove() { save(); }`，盖掉了 `feature/move.lpc` 的 `remove(string euid)`——这些存盘箱子/柜子被销毁时不从携带者身上减负重、不清 handing（KB 06 §7.239 变体，nitan_ceshi/tianxiawuxue 同类）。改成 `varargs void remove(string euid) { save(); ::remove(euid); }`。HEAD 与工作树各载入一次，regress 0（载不进的文件在 HEAD 就载不进）。

## 编译警告收尾（2026-10-12）

`scripts/toolkit_fix.sh` 一轮（冗余继承 7 处）后手工补四处（与 xyzx3、tianxiawuxue 同日的改法相同）：`d/city/library.lpc`、`d/city2/library.lpc`、`d/emei/user-room/host/home.lpc` 有意改 `STORY_DIR`，前加 `#undef`；`kungfu/skill/huashan-jian.lpc` 招式表后多余的 `;`。能编译的文件警告清零。改动的 11 个对象 HEAD 与工作树各载入一次：HEAD PASS 10，tree PASS 10，regress 0。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。2 个文件 5 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。

- 2026-10-15：`kungfu/skill/guangming-blade.lpc`（光明刀法）是从五虎断门刀抄来的，`query_action()` 里仍按 `wuhu-duanmendao` 的等级挑招式：没练五虎断门刀的人出招时一招都匹配不上，`a_action` 为 0，接着赋值报错。改为按 `guangming-blade` 自己的等级。（武功运行期探针发现。）

## 内力/精力当作伤害种类（2026-10-15，KB 06 §7.241 第二类）

本库 `feature/damage.lpc` 的 `receive_damage()` 不接受 `jingli`/`neili`/`force` 等种类，`me->receive_damage("jingli", 30)` 之类在练功、绝招、吸取时报 `F_DAMAGE: 伤害种类错误`。12 处改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py` 第二步）。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。3 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。


## 东方故事/西游记体系的技能文件（2026-10-15，KB 06 §7.241 第三类）

这些 `kungfu/skill` 文件来自 gin/kee/sen/force 体系，本库人物只有 jing/qi/neili：`receive_damage("kee", 30)` 报 `伤害种类错误`，`query("force")` 永远为 0，技能学不了也练不了。按 kee→qi、gin/sen→jing、force→neili、max_force→max_neili、force_factor→jiali 改了属性名（`scripts/lpc_port_es_props.py`），共 2 个文件。

## 治疗/疗伤的属性名（2026-10-15，KB 06 §7.241）

`receive_heal()`/`receive_curing()` 也只接受本库的种类。5 个文件（多为只调用 `receive_heal`/`receive_curing` 的药物、NPC）来自其他体系，按本库的属性名改名（`scripts/lpc_port_es_props.py --any-file`）。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。5 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。


## 技能按另一门武功的等级取招（2026-10-15，KB 06 §7.243）

这些技能文件是从别的武功复制改名来的，`query_action()` 仍用原武功的等级查招式表：只会本技能的人等级为 0，取不到招，每次出招都报错。改为读本技能自己的等级（`scripts/lpc_fix_action_level.py`）：`quanzhen-jian`。

## 空手使用兵器绝招（2026-10-15，KB 06 §7.246）

`perform` 指令允许直接点名招式（如 `perform stick.ban`），这些绝招读了 `me->query_temp("weapon")` 却从不检查，空手时 `weapon->name()` 报错（有的已先扣了内力）。在赋值后补 `if (!objectp(weapon)) return notify_fail("你必须手持兵器才能使用这一招。\n");`（`scripts/lpc_fix_perform_weapon.py`）：`dagou-bang/ban`、`dagou-bang/chuo`、`dagou-bang/pi`、`dagou-bang/tiao`、`dagou-bang/yin`。

## 把经验、属性、内力当技能读（2026-10-15，KB 06 §7.247）

当前内力、精这类名字有时指的是内功技能，逐处读过后手改：落英缤纷 `luoying-shenjian/lybf`：自己的注释说成功率由“精神高低”决定，两处 `query_skill("jing")` 改为 `query("jing")`。

## 碧海生潮曲空手报错（2026-10-15，KB 06 §7.246）

`iceforce/roar`（碧海生潮曲）先 `ob = me->query_temp("weapon")`，再直接拿 `base_name(ob)` 判断是不是玉箫；空手 `exert roar` 时 `base_name(0)` 报错，提示“你必须先找一只玉萧来才可以吹－－曲”根本出不来。条件前补 `!objectp(ob) ||`。

## iceforce「chillgaze」从未编译通过（2026-10-15）

`iceforce/chillgaze` 原档在第一个 `return notify_fail(...)` 后多了一个 `}`，`exert()` 就此结束，后面的语句全落在函数外，`skill`、`damage` 也没有声明，文件编译失败，这个 exert 从来用不了。照 bixiecanyang、hc、xyzx3 已修好的版本删去多余的 `}`、补上 `int skill, damage;`，其余字句不变，只是缩进进函数体。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`beimin-shengong`→`beiming-shengong`（`tiangang-zhengqi`、`xiantian-gong`）；`douzhuan-xignyi`→`douzhuan-xingyi`（`/d/mr/npc/obj/shu1`、`/d/mr/obj/shu1`）；`jinwu-dao`→`jinwu-daofa`（`jinwu-daofa`）；`mizongxinfa`→`mizong-xinfa`（`longxiang/fanchang`）；`yihua-jimu`→`yihua-jiemu`（`yihua-jiemu`）；`zhenfen-xinfa`→`zhenfeng-xinfa`（`zfwy-bu`）。

## 技能名拼错：技能文件里拼错自己的名字（2026-10-15，KB 06 §7.249）

技能自己的文件（或它的绝招目录）里，`query_skill()` 读的是差一个字母的自己的名字，永远得 0：“基本功夫要高过本技能”之类的限制从不生效，按等级取招、计算伤害的那一项一直是 0。改为本技能的名字（`scripts/lpc_fix_skill_typo.py` 的 self 判据）：`hujian-daofa`→`hujia-daofa`（`hujia-daofa`）；`jinggang-quan`→`jingang-quan`（`jingang-quan`）；`xuantie-jiafa`→`xuantie-jianfa`（`xuantie-jianfa`）；`xuanxie-jianfa`→`xuantie-jianfa`（`xuantie-jianfa`）。

## family 映射内联取下标（2026-10-15，KB 05 §7.30）

`ob->query("family")["master_name"]`、`me->query("family")["family_name"]`（泥潭式为 `query("family", ob)[...]`）直接对门派映射取下标：没有门派的人（新玩家、叛师者、大多数 NPC）在 NPC 的打招呼和问话、绝招的门派判断、房间的 `valid_leave` 里报 `Value being indexed is zero`，而不是得到拒绝。6 处（5 个文件）改为 dbase 路径查询 `query("family/master_name")`：有门派时值相同，没有时得 0；原有的判断照常生效（`scripts/lpc_fix_family_index.py`）。给映射赋值的写法未动。

## 移进不存在的巫师房间（2026-10-15，KB 06 §7.251）

用完的物品、要“离开”的 NPC、掷在空中的兵器被移进巫师的工作室（`/u/llm/`、`/u/wind/`），本库没有这些房间。本库的 `move()` 用 `load_object()` 找目的地，找不到就返回 0，不报错，东西留在原处：被雇来打晕或杀人的李凌（`d/city2/npc/liling2`）办完事后没有离开，留在原地（`d/city2/npc/liling2` 本身还载入不了：`create()` 里 `carry_object()` 的物品文件缺失或编译失败，见 KB 06 §7.73，另行处理）；婚礼结束（`d/nanyang/npc/meipo` 的 `last_marry`）时月老没有离开喜堂，每办一次婚礼喜堂里就多一个月老；喜宴结束后喜来福（`d/nanyang/npc/xi-laifu`）没有退回内堂，每办一次婚礼迎宾楼就多一个喜来福。3 个文件改为移进本库的虚空房间 `VOID_OB`（`/clone/misc/void`），与原作把它们“停放”在巫师房间的用意相同（haiyang2 的维护者把月老送进 `/d/city/empty`，也是同样的做法）。

## 玉女剑法「合壁」用一次就永久改动经验和剑法（2026-10-15，KB 06 §7.253）

收尾的 `hebi()` 声明时没有参数（`void hebi() { object me, target, env; int i, j, o, p, count; ...`），call_out 传进去的人和数值全被同名的局部变量（0）挡住，开头的 `if (!me && !target) return;` 每次都返回：合壁的攻击、闪避加成和 `hebi` 标记要到重新登录才消失。更糟的是夫妻判断写成了 `target->querry("id")`（没有这个函数，得 0），没成亲的人 `marry/id` 也是 0，于是人人都被当成夫妻：自己的玉女剑法和经验乘以玉女素心功的级数/80（至少变成浮点数，160 级以上翻倍），随后给对方 `set_skill("combat_exp", ...)` 时报 `No such skill`，收尾的 call_out 也就没排上，乘过的等级和经验永远不还原。测试里用一次合壁，经验 100000 变成 200000.0、剑法 100 变成 200.0。改正：`hebi()` 按它自己再次 call_out 时传的八个参数声明，`perform` 的 call_out 去掉多余的 `h, k`，`querry` 改为 `query`，给对方的 `set_skill("combat_exp")` 改为与上一行一样的 `set("combat_exp")`。测试里加成照常生效，`hebi()` 结束时还原并清除标记，没成亲的人经验和剑法不变。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

16 个文件、20 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/d/city2/obj/killerbian`、`/obj/cloth/cloth`、`/obj/weapon/blade`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 0 个，改后 14 个（14 个原来载入不了），没有退步；其余 2 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## 物品清单把名字的第一个字吃掉（2026-10-18，KB 07 §8.1）

`inventory`、房间的物品列表（`feature/move`）和部分 `look` 把同名物品合并计数，键是 `query("unit") + short()`，只有一件时按 `key[2..]` 去掉量词。量词是一个汉字，在原来的 GBK 里占 2 字节，`[2..]` 正好去掉量词；转成 UTF-8 以后一个汉字只占一个下标，这一刀把名字的第一个字也切掉了（「把长剑」只显示「剑」，带颜色的名字切掉的是转义序列开头）。改为 `[1..]`（`scripts/lpc_fix_unit_cut.py`）：`cmds/usr/inventory.lpc`、`feature/move.lpc`。

## 去掉的预定义宏 `SAVE_EXTENSION`（2026-10-18，KB 04 §6.11）

老版 MudOS 给每个 LPC 对象预先定义了 `SAVE_EXTENSION`（`".o"`）；FluffOS 的 ChangeLog（COMPAT_BUSTER 一条）把它删了，改用 `__SAVE_EXTENSION__`。本库没有自己 `#define` 这个宏，用到它的文件一律 `Undefined variable 'SAVE_EXTENSION'`，整个对象载入不了。改成 `__SAVE_EXTENSION__`（`scripts/lpc_fix_predefined_macro.py`）：`adm/daemons/network/netmail.lpc`。`netmail` 是网络邮件守护进程（本库缺 `mailer.h` 等头文件，改后仍载入不了）。改后用 `lpcc` 逐个载入这些对象：0 个通过，1 个还有别的错误（`adm/daemons/network/netmail`：/adm/daemons/network/netmail.lpc:17: error: Cannot #include mailer.h）。


## 水潭里 `ging_cost` 是 `jing_cost` 的笔误（2026-10-18）

`shuitan` 先算 `jing_cost`，倒水时却扣 `receive_damage("jing", ging_cost)`，`ging_cost` 从没声明过：`Undefined variable 'ging_cost'`，整个物件载入不了。改成 `jing_cost`：`d/shaolin/npc/obj/shuitan.lpc`。改后用 `lpcc` 逐个载入这些对象：1 个通过。


## 全真心法 `valid_learn()` 里没声明的 `lvl`（2026-10-18）

`kungfu/skill/quanzhen-xinfa.lpc` 的 `valid_learn()` 判断 `me->query("gender") == "无性" && lvl > 49`，可是函数里只有 `nk`、`nf`、`nh`、`ns` 四个变量，没有 `lvl`：`Undefined variable 'lvl'`，这门心法的文件载入不了，学它、用它都失败。`nh` 正是全真心法的等级（`nh = query_skill("quanzhen-xinfa", 1)`），改成 `nh > 49`。改后用 `lpcc` 逐个载入这些对象：1 个通过。


## 武林盟主类 NPC 的存档里 `weapon`／`armor` 是个 mapping（2026-10-18）

盟主、`fa-e`、`shang-shan`、`tang3`/`tang2`/`xingtang` 这几个 NPC 在 `create()` 里 `restore()` 之后直接 `carry_object(query("weapon"))`。换盟主时 `do_recopy()` 把玩家整个 dbase 抄进来，玩家的 `weapon` 若是自制兵器的 mapping，存进 `data/npc/*.o` 以后下次载入就是 `new(mapping)`：`Bad argument 1 to EFUN new()`，NPC 载入失败。本库的存档里确实有这种 mapping。两行都加 `stringp()` 判断，mapping 时不拿武器（NPC 空手）：`clone/npc/fa-e.lpc`、`clone/npc/meng-zhu.lpc`、`clone/npc/shang-shan.lpc`、`d/taishan/npc/fa-e.lpc`。改后用 `lpcc` 逐个载入这些对象：4 个通过。

## 补回丢掉的基类宏（2026-10-18，KB 04 §6.13）

`inherit F_XXX;` 里的宏本库任何头文件都没有定义，报 `syntax error, unexpected L_IDENTIFIER, expecting L_STRING or '('`，整个对象载入不了；宏指向的基类文件本库其实有，别的库都把这个宏定义成同一个路径。在全局头文件 `include/globals.h` 里补上：`WQA_ROOM` → `/quest/game/wqa_room`（80 个文件）。（`scripts/lpc_restore_macros.py`）改后用 `lpcc` 逐个载入这些对象：80 个里 80 个通过。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 6 个对象设了本库没有文件的武功（4 个名字，最多的是 `yiyang`、`hunyuan-force`、`ruyi-blade`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：6 个里 6 个通过。（`scripts/lpc_guard_set_skill.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 17 处、16 个文件：`yan-fly`→`yanfly`（3 处）、`xinxiu-duzhang`→`xingxiu-duzhang`（2 处）、`tiaji-jian`→`taiji-jian`（2 处）、`kongmingquan`→`kongming-quan`（2 处）、`taiji-shenfong`→`taiji-shengong`（2 处）、`lingbo-weibu`→`lingboweibu`（2 处）、`poyu-qua`→`poyu-quan`（1 处）、`hanbing-mainzhang`→`hanbing-mianzhang`（1 处）等共 10 个名字。（`scripts/lpc_fix_skill_names.py`）

## set_name 的 id 参数传成字符串（2026-10-19，KB 06 §7.260）

`set_name("海口大碗", "bowl");` 把物品的 id 写成了字符串，本库的 `set_name(string name, string *id)` 要的是数组，驱动在编译时报 `Bad type for argument 2 of set_name ( string * vs string )`，整个物件载入不了；旧驱动不检查参数类型，字符串里照样找得到这个词，物品能用 id 称呼。改成 `({ "bowl" })`，共 2 个文件：`/d/baituo/npc/obj/bowl.lpc`、`/d/baituo/obj/bowl.lpc`。（`scripts/lpc_fix_set_name_id.py`）

## 删掉 exert_function(整数)（2026-10-19，KB 06 §7.266）

`/u/zjb/saveme.lpc` `create()` 里的 `exert_function(10);` 把整数传给了要字符串的直接调用（让 NPC 闲聊时自己运功），驱动报 `Bad type for argument 1 of exert_function ( string vs int )`，整个 NPC 载入不了。这是存档里的笔误，不知道作者想传哪个字符串，删掉这一句（只影响闲聊时的运功表现）。chidi 的同一个 NPC 早先就是这样处理的。

## 木人 NPC 的源文件被截断（2026-10-19，KB 06 §7.266）

`d/liangong/npc/muren.lpc`、`muren2.lpc`（练功房里放 100 个的陪练木人）的文件在 `set("score", 2000);` 处结束，`create()` 没有收尾，驱动报 `syntax error, unexpected end of file`，练功房 `liangong`/`liangong2` 里一个木人也出不来。补上 `setup();` 和结尾的 `}`（没有哪个同系库带着完整的这两个文件，所以只补到能载入为止，木人不带武功）。

## 区域物件的零碎修正（2026-10-19，KB 06 §7.267–§7.271）

- `/d/board/mingjiao_b.lpc` 的 `location` 从不存在的 `/d/mj/guangming-ding` 改成 `/d/mingjiao/guangming-ding`（载入明教留言板失败会让光明顶房间载入不了）
- 2 个 NPC 文件、2 处 `create()` 里的 `this_player()->carry_object(` 改成 `carry_object(`（没人在场时 `this_player()` 是 0，NPC 载入不了；有玩家在场时衣服武器落到玩家手里）

逐个物件与 HEAD 对比载入，没有退步。

## 开封擂台头文件的重复全局变量（2026-10-19，KB 04 §6.10）

`d/kaifeng/ground.h` 里的 `modes`、`mode_hints`、`families` 三张表被 `ground0.lpc` 和继承它的 `ground1/2/3.lpc`、`ground.lpc` 各包含一次，每次 `inherit` 都报 `Redeclaration of global variable`。表只放在 `ground0.lpc` 里：头文件用 `#ifndef GROUND_TABLES_INHERITED` 包住表，继承的几个程序在 `#include "ground.h"` 前 `#define GROUND_TABLES_INHERITED`（与 xiyouji 系其余库同一改法）。改后警告消失，与 HEAD 逐个对比载入，没有退步。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 玩家打造兵器模板被 NPC 带上（2026-10-19，KB 06 §7.275）

`/d/npc/m_weapon/weapon/m_club.lpc`、`/d/npc/m_weapon/weapon/m_sword.lpc`（共 2 个）的 `create()` 用 `this_player()` 读打造数据（`me->query("weapon/lv")` 等）。NPC 的 `weapon` 属性是兵器文件名（字符串），NPC 在别的 NPC 的命令环境里 `carry_object()` 这个模板时，`set_desc()` 里 `switch (w_lv)` 拿到的是那个字符串，驱动报 `Bad argument 1 to switch`，房间和 NPC 都载入不了（旧驱动里 switch 落到 default）。把 `if (me) {` 改成 `if (me && mapp(me->query("weapon"))) {`，玩家打造的流程不变。

## 玩家打造兵器模板没有打造者时（2026-10-19，KB 06 §7.275）

`/d/npc/m_weapon/weapon/m_bian.lpc`、`/d/npc/m_weapon/weapon/m_staff.lpc`、`/d/npc/m_weapon/weapon/m_whip.lpc`、`/d/quanzhen/npc/obj/m_sword.lpc`、`/d/quanzhen/obj/m_sword.lpc`（共 5 个）的 `create()` 开头 `me = this_player();` 之后无条件读 `me->query("weapon/name")` 等打造数据。房间刷新时没有人在场（`me` 为 0），或者 NPC 在别的 NPC 的命令环境里 `carry_object()` 这个模板（NPC 的 `weapon` 属性是文件名字符串），旧驱动里读出来是 0 或字符串，`switch` 照样落到 default；新驱动报 `Bad argument 1 to EFUN call_other()` / `Bad argument 1 to switch`，NPC 和它所在的房间载入不了（`--walk` 普查里一个玩家走进房间就触发）。在 `//读入数据` 之后加 `if (!me || !mapp(me->query("weapon"))) { setup(); return; }`：没有打造者就留一个没有名字的空模板，玩家打造的流程不变。

## 补回丢失的标点（2026-10-19，KB 03 §4.6）

转换时丢掉的分号、逗号、引号或文件末尾的 `}`，共 6 个文件，修前 HEAD 载入失败。别的库里同路径的完好副本只比这里少几个标点，按它补回（括号里是那个库）：`/d/city2/npc/zhengmen.lpc`（jqxz2008）、`/d/quanzhen/hudi6.lpc`（bixiecanyang）、`/kungfu/skill/guxing-sword.lpc`（xyzx3）、`/kungfu/skill/huang.lpc`（bixiecanyang）、`/quest/baituo/qlist3.lpc`（xyzx3）、`/quest/murong/qlist3.lpc`（bixiecanyang）。修后与 HEAD 逐个对比载入：这 6 个物件全部载入，没有退步（`scripts/lpc_restore_from_twin.py`、`lpc_fix_eaten_quote.py --comma`、`lpc_fix_eof_braces.py`）。

## 玩家买店用的 `feature/vendor_sale.lpc` 补回（2026-10-19，KB 03 §4.6 第四轮）

`/feature/vendor_sale.lpc`（`/kungfu/class/npc/xiaoer.lpc` 继承它）从 `pay_back` 起约 160 行的行尾丢了最后一个字符（`;` `)` `{` `}`，`else {` 只剩 `els`，`msg` 只剩 `ms`），另有一行 `if(wizardp(who) || getuid(who)==owner_id)` 被拼进了前面的 `log_file(` 调用里。文件载入失败，继承它的物件也跟着失败。别的库（ldtx、ldtxii、xhcii、syxjl、hy3）里有这个文件的完好副本，但那是另一个版本：没有作者后来加的投标公告（`string mesg;` 和 `message("channel:chat", ...)`）。所以按完好副本补回丢失的字符（`scripts/lpc_restore_from_twin.py --diff --extra`），公告两段原样保留；被拼到别处的 `if(...)` 放回完好副本里它所在的 `write("\n盈利` 之前；`message_vision("channel:chat", ...)` 多出来的第一个参数删掉（`message_vision` 的签名是 `(string, object, object)`，每次 `bid` 在扣完款之后都会报错）。补完后文件和继承它的物件都能载入，没有警告，也没有退步（HEAD 上两个都载入失败）。

## `== !"字符串"` 多出来的 `!`（2026-10-19，KB 06 §7.280）

`!"taoist"` 是整数 0，`x == !"taoist"` 就是“x 等于 0”，作者为其余所有人写的那一支永远走不到。具体是：龙女对古墓弟子的机关暗门提示永远给不出来（5 处）；孙婆婆的“你去吧”只对 class 没设置的人生效；性别检查（“你不是女的，无法领会其中至阴之理”）永远不拦人，男的照样能学玉女心法。全部改成 `!= "字符串"`（`scripts/lpc_fix_not_literal_cmp.py`）：`/kungfu/class/gumu/long.lpc`（5 处）、`/kungfu/class/gumu/sunpopo.lpc`（1 处）、`/kungfu/skill/yunu-xinfa.lpc`（1 处）。同样的行在 xkx 一系的 35 个库里都有。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。具体是：客栈小二从不拦住付了房钱又往南/往北走的客人。改动：`/d/changan/ca2.lpc`（1 处）、`/d/haojie/npc/tianshaxing.lpc`（1 处）。

## 浩劫系统 `verdict_time()`：领头玩家已经离线时 `lead->name()` 报错，戒严不解除（2026-10-20）

三十分钟后收场时 `lead`（接战书的玩家）若已退出游戏就是 0，`lead->name()` 在宣布战果的 `message()` 里报错，后面的 `LOGIN_D->set_madlock(0)` 不再执行，戒严一直保持，`quit` 指令因此对所有人关闭。改为 `(lead ? lead->name() : "各派豪杰")`。改动：`/feature/disaster.lpc`（2 处）。

## `socket` / `dumpsocket` 指令：`dump_socket_status()` 驱动里没有（2026-10-20，KB 06 §7.291）

这些巫师指令 `write(dump_socket_status());`，MudOS 的 efun 在 FluffOS 里不存在，指令编译不过。在模拟 efun 文件里补了 `dump_socket_status()`：用 `socket_status()` 排出同样的表（没有 sockets 包的构建，比如 WASM，只有表头；`scripts/lpc_add_sefun.py dump_socket_status`）。

## `tail` 指令：`tail(file)` 驱动里没有（2026-10-20，KB 06 §7.291）

`cmds/*/tail.lpc` 调用 MudOS 的 `tail()` efun，FluffOS 没有，指令编译不过。模拟 efun 文件里补了 `tail(file)`（Discworld 家族的兼容版：文件最后约 20 行，从完整的一行开始，存在返回 1；`scripts/lpc_add_sefun.py tail`）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/obj/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## 翻页器 `start_more(read_file(...))`：文件缺失时 `explode(0)`（2026-10-20，KB 06 §7.300）

东方故事系的翻页器 `void start_more(string msg) { ... explode(msg, "\n") ... }` 被这样调用：`start_more(read_file(HELP_DIR + "help/topics"))`、`start_more(read_file(NEWS))`。压缩包没带的文件使 `read_file()` 回 0，`explode(0, ...)` 在本驱动里报 `Bad argument 1 to explode()`（不带参数的 `help` 指令就是这样出错的），老驱动把 0 当空文本。在 `start_more` 开头加了 `if (!stringp(msg)) return;`（`scripts/lpc_fix_start_more.py`）。改动：`/feature/more.lpc`。

## `wabaod` 的藏宝线索按双字节算（2026-10-20，KB 06 §7.307）

天书的线索由 `adm/daemons/wabaod.lpc` 在房间描述里挖空若干个字：`desc = long[begin..begin + 60]`（按 GB 的 61 字节）、`desc[b..b + 1] = "■"`（两个字节换两个字节）。驱动的字符串是 UTF-8，区间按字符数：窗口成了 61 个字符，每次替换把两个字符换成一个，字符串越换越短，后面的偏移越界，启动时 `push_lvalue_range: invalid ind2`（随机出现，`init_xunbao` 的每次 call_out 也会）。改成按字符算：30 个字符的窗口，每处挖一个字（`scripts/lpc_fix_wabaod.py`）。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库现有的 NPC 文件里没有字面写成空 `chat_msg` 的（扫描只认 `set("chat_msg", ({ }))`）；守卫挡的是运行时才为空的列表和以后新增的 NPC。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/inherit/char/npc.lpc`（共 1 个文件）。

## `quest/dynamic_room` 的 `.c` 行：任务守护进程加载不了（2026-10-21，KB 06 §7.341）

任务守护进程（`adm/daemons/taskd.lpc`）的 `create()` 读 `/quest/dynamic_room`（琉璃庄的 19 个房间，`/d/llzhuang/lou0.c` ……），`clear_room()` 对每一行 `load_object()` 再 `room->reset()`：显式的 `.c` 按原样解析（KB 03 §4.2），档案里的房间是 `.lpc`，`load_object()` 答 0，`0->reset()` 让 `create()` 中止，守护进程没有加载（HEAD 加载失败，改后通过）。2026-10-05 的 `.c` 行扫描只认 `dynamic_location*` 和 `dynamic_quest*` 两种表，`dynamic_room` 和 `dynamic_npc_quest` 没有扫到；`scripts/lpc_dynamic_rows.py` 现在认四种，这 19 行改成 `.lpc`（本库档案里没有的行照旧不动）。

## 谷物加工厂 `goldwork2/3/4`：工作太久被赶出去时 `ob->move(..)`（2026-10-21，KB 06 §7.348）

`working()` 在连续工作次数超过 60+random(100) 时，运气低于 25 的人被送回广场：`if ((int)me->query("kar") < 25) ob->move("/d/city/guangchang");`，`ob` 声明了没赋值（同一目录的 `goldwork.lpc`、`goldwork5.lpc` 写的是 `me->move`）。抛错在 `me->set_temp("working", 0)` 和 `cot--` 之前，房间里的工人计数漏掉一个，三次之后“人手已经够了”永远不再收人。改成 `me->move(..)`，去掉 `object ob;`。改动：`/d/city/goldwork2.lpc`、`/d/city/goldwork3.lpc`、`/d/city/goldwork4.lpc`。

## 香烟 `smoke.lpc`：`do_smoking()` 读没赋值的 `me`（2026-10-21，KB 06 §7.348）

`smoke` 指令的第一句是 `jing = me->query("jing")`，`me` 声明了没赋值，每次抽烟都抛 `Bad argument 1 to call_other()`。补 `me = this_player();`（后面的 `this_player()` 调用不变）。改动：`/d/emei/user-room/melodies/smoke.lpc`。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 34 条注册（30 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/d/city/chatroom2.lpc`（`do_jump`）、`/d/city/npc/wei.lpc`（`do_sell`）、`/d/city2/qishi.lpc`（`do_pass`）、`/d/city3/npc/sister.lpc`（`do_vendor_list`）、`/d/player/yysz/hupan.lpc`（`do_han`）、`/d/quanzhen/npc/haodatong.lpc`（`do_decide`）、`/d/quanzhen/npc/mayu.lpc`（`do_decide`）、`/d/quanzhen/npc/qizhicheng.lpc`（`do_decide`）、`/d/quanzhen/npc/sunbuer.lpc`（`do_decide`）、`/d/quanzhen/npc/wangchuyi.lpc`（`do_decide`） 等共 30 个文件。最多的函数名：`do_send` 15 处、`do_decide` 7 处、`do_faint` 5 处、`do_jump` 1 处、`do_sell` 1 处。

## 对象路径里的 `..`：`new(__DIR__ "../obj/x")` 报 `Read access denied`（2026-10-22，KB 06 §7.351）

`__DIR__` 是当前文件所在目录（带结尾斜杠），`__DIR__ "../obj/x"` 就是 `/d/zhiye/npc/../obj/x`；驱动的 `legal_path()` 不接受带 `..` 的路径，`new()` / `load_object()` 直接抛 `*Read access denied.`（实测，`find_object()` 对它答 0）。走库自己的 `carry_object()` / 房间 `objects` 表的路径，库的基类会先规范化，能用；直接把路径交给 `new()` / `clone_object()` / `load_object()` / `move()` 的不行，调用到那一步才报错。改成规范化后的绝对路径（`scripts/lpc_fix_dotdot_dir.py --direct`）：`/d/wudang/npc/xiaocui.lpc`（`__DIR__ "../obj/nuerxiang"` → `"/d/wudang/obj/nuerxiang"`）。

## 缺失物品的 `new()` / `carry_object()` 调用链加了保护（2026-10-22，KB 06 §7.73 补充）

`new(路径)->move(...);` / `carry_object(宏("x"))->wear();` 这类语句，路径指向的文件在这个压缩包里没有：`new()` 返回 0，`->move()` 在 0 上报 `Bad argument 1 to EFUN call_other()`。在 `create()` 里这个对象永远加载不了，在 `reset()` 里第一个缺失物品之后的刷新每次 reset 都被跳过。1 个文件里 1 处（`new`）改成 `{ object new_ob = new(路径); if (new_ob) new_ob->move(...); }`（`scripts/lpc_guard_carry_object.py --new`：路径按这个文件自己看到的宏解析，宏名冲突、虚拟对象路径一律跳过）。 对这 1 个改动文件做加载检查（HEAD 与工作区对比）：HEAD 能加载 1 个，现在 1 个（新增可加载 0 个，回归 0 个）。

## 调用了、但这个库自己的守护进程里没有的函数（2026-10-22，KB 06 §7.354）

`MACRO->函数()` 调用的函数在这个库的守护进程里不存在：`call_other()` 对不存在的函数不报错、只返回 0，所以这些功能（时间显示、昼夜事件、名字检查、价格文字……）一直没起作用。同一血统另一个库的同名守护进程里有这些函数，原文照抄到本库守护进程末尾（`scripts/lpc_port_function.py`；调用处传的参数个数、函数体用到的函数 / 全局变量 / 宏 / 字符串键都在本库里有，已核对；守护进程在 HEAD 和工作区都能加载，每个函数用固定参数各调用一次：HEAD 返回 0，现在返回正常的值）：`/adm/daemons/chinesed.lpc` ← aoxiangtianji：`chinese_month()`（2 处调用）；`/adm/daemons/natured.lpc` ← aoxiangtianji：`room_event_fun()`（9 处调用）。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 还剩 3 个函数没有补（inquiry 2, item_desc 1）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/d/city/npc/zhuziliu.lpc`:`give_job`、`/d/city/npc/zhuziliu.lpc`:`task_ok`、`/d/yihua/lianhuachi.lpc`:`look_CAI`。

## 运行期目录 `log/nosave` 不存在，写日志的 `write_file()` 直接报错（2026-10-22，KB 03 §4.3 补充）

这个库的 13 个文件里有 19 处 `write_file("/log/nosave/...")` / `log_file("nosave/...")`（`static` 改 `nosave` 时连字符串里的日志路径一起改了，原来是 `log/static/`）：`nosave/CRASHES`、`nosave/PURGE`、`/log/nosave/KILL_PLAYER` 等。压缩包和站点包里没有这个目录，`write_file()` 在目录不存在时抛 `*Wrong permissions for opening file /log/nosave/... for append. "No such file or directory"`，调用它的函数（杀人记录、重启记录、`call` 日志……）当场中断。把 `log/nosave` 记进 `scripts/wasm_keep_dirs.txt`（站点和 pristine 树都按它建空目录）；没有把字符串改回 `static`。证明（`scripts/lpcc_eval.py`，`catch(write_file("/log/nosave/ZZTEST", ...))`，fqyy2 / hy5 / bmxkx2001 的新进程）：补目录前报上面的错误，补后写成功。

## `(: 函数名 :)` 指针指向本库没有的函数：只含这个指针的行加了注释（2026-10-22，KB 06 §7.355 补充）

`inquiry` / `item_desc` / `chat_msg*` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：用到时（`ask`、`look`、NPC 闲聊）驱动抛 `*Undefined lfun pointer called: 函数名`，这一拍心跳的后半段被跳过。这些函数没有可以补回的来源（别的库同一路径的文件里没有，或者它还要用本库没有的东西），所以 1 个文件里 1 行只含这个指针的行（`"CAI": (: look_CAI :),`）加了注释，原文保留并写明原因，这一项当作没有这个话题 / 物品 / 闲聊条目（`scripts/lpc_fix_dangling_lfun.py`；`#include` 的文件在库里缺失的对象、指针不在整行上的写法没动）。 前提（`function_exists()`）和加载检查（HEAD 与工作区对比，本库改动的 `.lpc` 文件）的结果见 KB 06 §7.355：没有一个回归。

## 写死的 `"/路径"->函数()` 指向库里没有的文件：改成现存的同名文件（2026-10-22，KB 06 §7.359）

1 处语句级的 `call_other` 字面量路径，库里没有这个文件（区域改了名 / 大小写不对 / 差一个字母 / 文件挪了地方）：`"/d/mj/obj/baihong-jian"->move()`（`/d/mingjiao/npc/yingwang.lpc`）→ `"/d/mingjiao/obj/baihong-jian"`。`call_other()` 对不存在的对象抛 `couldn't find object`，所在函数当场中断。改成库里现存、并且定义了被调用函数的文件（`scripts/lpc_fix_call_path.py`；巫师目录、备份目录、名字不同的兄弟文件都不算候选）。 其中殷天正（白眉鹰王）的 `do_answer()`：玩家念对暗语（`answer 怜我世人，忧患实多；保护教主，同抗外敌`）时把白虹剑 `move` 给玩家，区域目录改名 `mingjiao` 之后这个路径没跟着改，回答暗语只得到 `couldn't find object`，剑永远发不出来。

## 汉字按字节切片的老写法没有换成按字符：改法名 `"澄" + name[2..3]`、辈分判断 `name[0..1] == "澄"` 等 20 处（2026-10-22，KB 06 §7.360）

原档按字节算字符串区间（一个汉字 2 字节）：`name[2..3]` 是名字的第二个字，`name[0..1] == "澄"` 问名字是不是以「澄」开头。转成 UTF-8 之后，这个驱动的区间和 `strlen()` 都按字符算（`strlen("澄观")` 是 2，`"澄观"[0..1]` 是两个字），老算术原样留着、意思全变：拜入少林 / 武当 / 峨嵋等派的玩家被改成错误的法名（二字名 `张三` 变成一个字的 `澄`，更长的名字取到第三个字）；各派掌门的辈分判断（`name[0..1] == "澄"`）永远不成立。

本库 20 处（15 个文件）：拼名字的赋值 12 处、与汉字常量比较 8 处。例：`name[2..3]` → `name[1..1]`（`/kungfu/class/emei/jingxin.lpc:101`）；`name[0..1]` → `name[0..0]`（`/kungfu/class/shaolin/qing-fa.lpc:100`）；`name[0..3]` → `name[0..1]`（`/quest/imp/xquest.h:97`）。`scripts/lpc_fix_gbk_slice.py` 把下标按字符重算（社区的 UTF-8 版 `xkx100utf8` 里就是同样的写法，作对照）；没有改的：截断（`name = name[0..7]`，现在最多 8 个字，只是放宽）、ASCII 的区间（`fname[0..3] == "room"`、`ctime(time())[4..19]`）和上下文看不出是汉字的区间。证明（`scripts/lpcc_eval.py`，bixiecanyang；其余各库是同一份文本）：让澄字辈掌门 `attempt_apprentice()` 一个名叫「张三」的访客，HEAD 的法名是 `慧`，改后是 `慧三`；抽样 28 个库的 HEAD / 工作树加载对比 0 退步。工具不幂等（`[0..3]` 折半得 `[0..1]`，又是对齐区间），改过的文件记在 `scripts/gbk_slice_converted.txt`，不要重跑。

## 长度检查按字节写，旁边的提示按汉字写：24 处（2026-10-22，KB 06 §7.362）

老档的 `strlen()` 数字节（一个汉字 2 字节），转成 UTF-8 后它数字符：提示写「必须是 2 到 6 个中文字」的检查还是 `strlen(name) < 4 || strlen(name) > 12`，于是两三个字的房名、帮会名、群名、聊天室名、称号被提示自己说允许的那句话拒绝，上限却是提示的两倍；留言板的标题检查 `i < 4 || i > 24 || i % 2` 还会拒绝所有奇数个字的标题（`post 你好吗`）。本库 24 处（12 个文件）：`if ((strlen(name) < 2) || (strlen(name) > 10)) {`（`/adm/daemons/logind.lpc:787`）；`if ((strlen(name) < 2) || (strlen(name) > 12)) {`（`/cmds/bakcmds/csc.lpc:611`）。`scripts/lpc_fix_strlen_gate.py` 以提示为准：条件里每个 `strlen` 门槛都恰是提示所说数字的两倍才折半，存长度的变量（`i = strlen(arg);`）的门槛和 `|| i % 2` 奇偶项、其后循环的 `i % 2 == 0 &&` 一并处理；提示里有英文 / 字母 / 字节的不动。证明（`scripts/lpcc_eval.py`，bxsj 的留言板，求值对象继承 NPC 并重写 `edit()` 记录调用，`command("post 标题")`）：HEAD 拒绝「你好」和「你好吗」、放行 23 个字的标题；改后接受前两个、拒绝第三个；shenmo 的 `named.lpc invalid_new_name("张三")`：HEAD 回 `名字只能是2-4个中文字。`，改后回 0。抽样 24 + 15 个库的 HEAD / 工作树加载对比 0 退步。
