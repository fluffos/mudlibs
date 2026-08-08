
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
