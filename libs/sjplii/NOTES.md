
## WASM 修复摘要（迁移自 meta.json 的 group_note）

sjplgfjxb 的手足档案（同一个飞白工作室《书剑飘零》ES II 代码库家族，这次用的是 adm/daemons/securityd.lpc——没有 securd/securityd 分裂，没有双档案混淆）。和 sjplgfjxb 不同，这份快照启动和注册都干净，完全不需要任何修复——sjplgfjxb 的那些 bug（report_error/CHANNEL_D、未定义的 REMOTE_DIR、损坏的 emote 存档）在这里都不存在。管理员账号播种：fluffos (admin) 加入 adm/etc/wizlist（已通过 include/globals.h 和 login.h 确认 SECURITY_D/WIZLIST 具体解析到的是 adm/daemons/securityd.lpc 和 adm/etc/wizlist——这份档案还带着好几个其它名叫 securityd.lpc/wizlist 的档案，分别在 adm/、adm/tmp/、adm/daemons/bak/ 下，都不是真正被使用的那些，符合既定的 §7.56 提醒）。已验证：完整注册（id→确认→名字→密码→确认→电子邮件→性别→出生地选择）→look/score/quit 全部干净，权限正确显示 (admin)，update 成功。LPC 格式化工具对全部 12421 个档案运行；还原了 2 个其实是纯文本 Windows dir 指令输出、被粘贴成 .lpc 扩展名的档案（不是真正的代码，格式化工具试图把它们当 LPC 重新排版导致损坏），另外还有 3 个确认有真正 CJK 重新加空格损坏的档案，都是通过"去空格后比对旧档案"扫描（覆盖 68 个格式化工具触碰过的档案）找到的；另外直接逐一比对了全部 3 个 map.lpc 档案——全部干净，只是排版调整。格式化后重新验证过，干净。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 44 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（§10.7，2026-08-08）

`README.md`/上面的 WASM 摘要曾写"sjplgfjxb 的那些 bug 在这里都不存
在"——本次逐条独立核实后需要部分更正：`chess_player.lpc` 编译错误、
`logind.lpc` 的 printf 泄漏、`/std/jboard` 的 §7.86 变体这三个 sjplgfjxb
发现的 bug，在 `sjplii` 里**同样存在**（同一个飞白工作室代码库家族，同源
程度比先前认识到的更高）；只有 `report_error()`/`CHANNEL_D` 崩溃、未定义
的 `REMOTE_DIR`、`emoted.lpc` 存档损坏这三个 sjplgfjxb 独有的 bug 真的不
在 `sjplii` 里——不过 `sjplii` 自己另外还有一个不同位置的 §7.41 类损坏存
档（见下）。都已在原生驱动上逐条改前/改后验证。

### 本次修复的 bug

1. **一处真正的编译期 `error`**（AGENTS.md §7.35 类，object-vs-string
   参数类型不匹配，裸调用触发硬编译错误）：`d/fuzhou/npc/chess_player.lpc`
   （棋摊老板"韦守儒"）第 39-40 行 `play_chess()` 里
   `printf("%s", name(this_player()));` 和
   `command("give chess to " + name(this_player()));` 把继承自
   `feature/name.lpc` 的本地方法 `varargs string name(int raw)`（取*自
   己*的名字，参数是"要不要去头衔"的整数开关）当成"取对方名字"的自由
   函数误用，传了一个 `object` 给一个只接受 `int` 的参数。驱动的静态类
   型检查在裸调用上直接拒绝：`Bad type for argument 1 of name ( int vs
   object )`，导致这个 NPC 档案全程无法编译，福州"茶馆"填充它时会级联
   `*No program in object` 报错。修复：删掉那行调试用 `printf`（§7.34
   同款，无意义调试输出），`command(...)` 改为
   `this_player()->name()`。改前：`update /d/fuzhou/npc/chess_player`
   报上述两行 `error`；改后：`成功！`（只剩 `/std/char/npc.lpc` 两行无
   关的 `Unused local variable` warning）。全档案 grep
   `name(this_player()` 及类似形状未发现第二处。
2. **两处 §7.34 类调试遗留**：`adm/daemons/logind.lpc` 的 `get_resp()`
   （第 293 行）和 `get_name()`（第 328 行）各有一行
   `printf("%O\n", ob);`，紧跟在中文名字确认之后、密码提示之前，把登
   录物件的内部路径（`/obj/login#N`）原样打印给玩家。已各删一行。改
   前后用全新注册的 `fluffos`（中文名"云中鹤"）验证：改前会在"您的中
   文名字：云中鹤"后多印一行 `/obj/login#0`；改后中文名字确认后直接
   跳到"请设定您的密码："，无路径泄漏。
3. **§7.86 类第三个变体**：`obj/board/wizard_j.lpc`（巫师"工作进度报
   告"板，`/d/wiz/jobroom`）`inherit "/std/jboard";` 之后 `create()`
   尾巴又多余调用了 `replace_program("/std/jboard");`——与已扫描修复的
   44 处 `BULLETIN_BOARD` 实例是同一致命形状，只是基类叫
   `/std/jboard.lpc`，命令动词也不是 `post` 而是 `project`/`report`
   （`do_project()`/`do_report()` 同样用
   `this_player()->edit((: lfun, ... :))` 建闭包）。已删除多余的
   `replace_program()`。改前：全档案 §7.86 扫描时只做过编译检查，未做
   过实机验证；改后：以 `fluffos` 管理员账号在 `/d/wiz/jobroom`
   执行 `project 深度测试计划` → 输入正文 → `.` 结束，`新工作计画提
   出。`，无崩溃；`update /obj/board/wizard_j` 单独重新编译也确认无报
   错（只有一条无关的 `Unused local variable 'myid'` warning）。全档
   案已确认再无第二处 board 相关的 `inherit X + replace_program(X)`
   同名组合（用 `BULLETIN_BOARD`/`BBS_BOARD`/`/std/jboard`/
   `/std/bboard` 分别 grep 过 45 个继承过任一板类的档案，逐一反查其
   `replace_program`）。
4. **一处新的 §7.41 类损坏存档**（sjplgfjxb 没有这一个，是 `sjplii`
   自己独有的）：`adm/daemons/emoted.lpc` 的 `create()` 对自己的存档
   `data/emoted.o` 做未加保护的 `restore()`，preload 时抛出未捕获异
   常（`*restore_object(): Invalid utf8 string while restoring
   emote.`，冒泡到 `master.lpc` 的 preload() catch，说明 `create()`
   没跑完，`emote` 变量停在未初始化状态）。用 Python 检查
   `data/emoted.o` 二进制内容，第 58 字节起有一段确认是遗留的 GBK 字
   节（`\xbf\xb4\xbf\xb4$n\xcd\xb7...` 等），从未在原始编码转换阶段
   被转成 UTF-8——这是货真价实的损坏存档，不是驱动或 harness 的问题。
   修复（与 sjplgfjxb 完全一致的写法）：`create()` 里把
   `if (!restore() && !mapp(emote)) emote = ([]);` 改成
   `catch(restore()); if (!mapp(emote)) emote = ([]);`。改前：驱动启
   动日志里这行异常会冒泡到 `master.lpc` 自己的 `CATCH()`（`错误讯息
   被拦截`）；改后：异常被 `emoted.lpc` 自己的 `CATCH()` 拦下（调用链
   多了一层 `emoted.lpc 的 CATCH() 第 43 行`），`create()` 正常跑完，
   `emote` 兜底成空 mapping，驱动其余启动流程无变化。

### 排查过程中确认"不是 bug"的现象

- **出生地机制与 sjplgfjxb 不完全相同，取决于账号权限**：`sjplii` 的
  `enter_world()`（`adm/daemons/logind.lpc` 第 545-547 行）里有一行
  `if (wiz_level(user) > wiz_level("(apprentice)"))
  user->set("startroom", "/d/city/ciensi.lpc");`——**任何权限高于学徒
  的账号**（含刚播种的 `fluffos` 管理员）在 `enter_world()` 里会被强
  制把出生房间覆盖成长安城"大慈恩寺"，无论角色创建时选的是哪种"出生
  状况"。这不是 sjplgfjxb 那种"仅在 `load_object(startroom)` 失败时才
  退回大慈恩寺"的兜底逻辑（那段兜底逻辑在 `sjplii` 里也存在，
  第 585-592 行，两者并存、互不冲突），而是刻意为巫师账号设计的固定
  出生点。实机验证：`fluffos`（(admin) 权限，选"武力世家"）落地在
  `/d/city/ciensi`；同一次会话另外注册的非管理员一次性测试角色
  `sjplcheck`（中文名"赵日天"，同样选"武力世家"）落地在
  `/d/fuzhou/minzhai4`（`start_loc[3]`，与出生状况选择完全对应）。结
  论：普通玩家的出生地机制与 sjplgfjxb 一致（按出生状况落在山东/福州
  对应民居，长安城只是 `load_object` 失败时的兜底），但巫师账号有一
  条独立的、非 bug 的固定出生点覆盖规则，测试或验收时不要用巫师账号
  的落地房间去判断出生地机制是否正常。
- **"游客"NPC 一度像是 `kill`/`present()` 失效**：在白虎大街 `kill
  youke` 反复报"这里没有这个人。"——追查后发现单纯是这个 NPC 恰好在指
  令送达的同一瞬间被自己的 `chat_msg`/`random_move()` 带离了房间（游
  客走的方向和我确认剩余在场角色的时机凑巧撞上），不是 `id()`/
  `present()` 出问题；换一个更强、更常驻的目标（`d/fuzhou/npc/
  bing.lpc` 系或城门"小兵"）后战斗流程完全正常。
- **`std/jboard.lpc` 的 `post` 指令实际上不存在**：这份板子的动词是
  `project`（开新计画）/`report`（对已有计画提交进度）/`read`/
  `terminate`，不是 `post`——房间里同时摆着一个普通 `BULLETIN_BOARD`
  （短 id `"board"`）和这个 `jboard`（短 id 同样含 `"board"`），裸打
  `post <标题>` 会命中前者而非 jboard，一开始容易误判 jboard 修复没生
  效；确认要用 `project <标题>` 才能真正触雷 jboard 自己的
  `do_project()` 闭包路径。

### 已验证正常工作（原生驱动，`fluffos`/`Mud@2026` 管理员账号 + 一个
一次性非管理员测试角色"赵日天"/`sjplcheck`）

- 完整注册流程（英文 id → 确认 → 中文名字 → 密码 → 确认 → 邮箱 → 性
  别 → 出生状况）→ `look`/`score` → 二次连线（`get_passwd` 重新连线路
  径，非首次注册路径，显示"重新连线完毕"）全部干净；整场会话
  `debug.log` 未被写入任何新内容（仍是转换时期留下的旧文件），
  `log/log` 里除已知的 `Unused local variable` warning 外无任何错误
  或崩溃痕迹。
- 移动：长安城内多个房间（大慈恩寺→白虎大街→启夏门→曲江池等）、福
  州街区（民居→街道→十字路口）均正常，房间描述、出口、NPC 列表显示
  正确。
- 留言板：`大慈恩寺` 的普通板 `post`/`look board` 正常；`/d/wiz/
  jobroom` 的 `job board`（jboard 类）`project` 正常（见上方修复第 3
  条）。
- `maximum evaluation cost : 700000` 全程未触发 `cost limit
  reached`，不需要按 §7.90 上调。
- 战斗与死亡/复活全流程：`fluffos` 管理员角色用 `kill bing`（启夏门城
  门"小兵"，`combat_exp` 30000）触发正常攻防交换与 `wimpy` 驱动的自动
  逃跑（"看来该找机会逃跑了..."）；再用管理员 `call` 指令把自己的
  `eff_kee` 强制设成负数确认了 `die()`→`鬼门关`→`白无常` 的死亡流程本
  身能正确触发，但 `d/death/npc/wgargoyle.lpc` 的 `init()` 与
  sjplgfjxb 一样带 `wizardp(previous_object())` 早退（第 58 行），巫师
  幽灵永远不会被排定 `death_stage()`，只会看到白无常的闲聊 `chat_msg`
  ——之后用管理员 `be_ghost(0)` + 手动恢复三维属性 + `move()` 把
  `fluffos` 救回人间。**随后另注册的非管理员一次性角色"赵日天"
  （`sjplcheck`）用 `wimpy 0` 关闭自动逃跑，攻击福州街头一个明显更强
  的游走 NPC"彩衣双剑"费慎（`npc/newnpc/feishen.lpc`，
  `combat_exp` 随机 10-80 万），完整打满五阶段死亡对话（"喂！新来
  的，你叫什麽名字？"……"罢了罢了，你走吧。"），`reincarnate()` 后因
  角色 `combat_exp` 未超过一万走了 `ob->move("/d/fuzhou/duchang")` 分
  支，正确复活在福州"赌场"，`score` 确认状态完全恢复、无【鬼魂】残
  留、无任何崩溃或 `debug.log` 报错——本次是这次深度测试系列里少数几
  个真正走完完整死亡/复活循环（非管理员、真实战斗触发，非管理员强改
  属性）的例子之一。`death_stage()` 本身仍带着 AGENTS.md §7.68 已撤回
  的裸 guard 形状（`if (!ob || !present(ob)) return;`），但本次全程未
  中断触发过这个分支（复活是一次不受打扰的完整顺跑），没有新证据支持
  或反对 §7.68 的旧修补，按撤回结论不做任何改动。
- 食物/饮水初始化：`adm/daemons/logind.lpc` 的 `init_new_player()` 里
  直接、无条件地 `user->set("food", user->max_food_capacity())` /
  `set("water", ...)`，不经过任何 `age` 判断，不是 §8.9 那种"检查错误
  对象 age"的形状，两个测试角色食物/饮水均正确初始化为满值。

### 管理员账号播种

`adm/etc/wizlist` 里此前已有 `fluffos (admin)` 一行，但账号本身
（`data/{login,user}/f/fluffos/`）此前从未被真正注册/提交过——已确认
不存在。本次走标准注册流程创建（id `fluffos`，中文名"云中鹤"，密码
`Mud@2026`），登录后 `目前权限：(admin)` 立即正确显示（无需额外的
WIZ 密码之类的二级门槛，`securityd.lpc` 是这份档案里唯一、真正生效的
安全精灵），`update /d/fuzhou/npc/chess_player`、`update
/obj/board/wizard_j` 两次写权限验证都成功。测试用的一次性非管理员账
号 `sjplcheck`（中文名"赵日天"）及测试留言板存档（`大慈恩寺`板、
`wizard_j` 板各一条测试留言/计画）已在提交前删除，只保留
`fluffos` 的账号存档。

## §7.100 房间基类 replace_program() 扫尾修复（2026-08-19）

`ROOM` 宏（`/std/room`）在本档案 2,290 处房间文件的 `create()` 里
紧跟 `inherit ROOM;` 之后又多余调用了一次 `replace_program(ROOM);`
——和姊妹档案 `sjpl2`（同一份 `书剑飘零` 血统，房间生成工具家族逐字
节相同）完全一样的 AGENTS.md §7.100 休眠 bug。用 `fix_710_room.py`
扫过 `work/`，删除 2,280 处标准形状；另有 9 处不规则形状手工修复，
和 `sjpl2` 的处理逐一对应：`obj/roommaker.lpc` 字符串拼接变体、
4 份房间生成工具副本 + 2 份内嵌同一段代码的 NPC 档案
（`u/lark/xiaoyao/npc/{rich,tumu}.lpc`、`u/jakey/npc/rich.lpc`）里
"仅当房间没有 item_desc 时才拼接" 的条件变体（`u/losey/roommaker.lpc`
`u/set/obj/roommaker.lpc`、`u/gdjk/roomm.lpc`、
`u/gdjk/hongnong/maker.lpc`），以及 `u/lark/yangmingzhai/ss.lpc`
一处真实房间文件（`replace_program` 紧跟在已注释掉的
`/* setup() */` 后面同一行）。`u/lark/luoyang/dongmen.lpc` 剩下 1
处留着未修：整份文件从 `inherit ROOM`（无分号）起就缺失几乎全部语
句分号，确认是转档之前就已经损坏、与本次改动无关，和 `sjpl2` 同一
份损坏文件的表现一致。`git diff --stat` 显示 2284 个文件净删 2289
行，与 `sjpl2` 完全对称吻合；另有 150 处转档之前已注释掉的 `//` 行
原样保留。`work/data/` 下没有真实 `.lpc` 源码命中。

驱动干净启动（零新增编译错误、端口正常监听、`debug.log` 无任何
"cannot replace"/"cannot bind"行），巫师账号
`fluffos`/`Mud@2026` 确认"目前权限：(admin)"后 `look`/`goto` 走读
了 `y/city/baozipu.lpc`（曾经命中过这个 bug 的房间）正常，`quit`
干净退出。走读时另外撞见 `y/city/baihu-n1.lpc` 一处转档之前就存在
的 `NPC_DIR "people/man"` 宏拼接语法错误（`git diff` 确认本次改动
只碰了 `replace_program` 那一行），与本次 sweep 无关，不在修复范
围内。登录存档的增量已用 `git checkout HEAD --` 撤销，未落入提交。

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

## AGENTS.md §7.19 sweep (2026-09-01): `enable_player()` reentrancy from `init()`

Same corpus-wide bug class as `mhxy`/`wuhanzhan` (AGENTS.md §7.19): this
lib's `feature/command.lpc` `enable_player()` wrapper (around the raw
`enable_commands()` efun) is reachable from an NPC's `init()` via a
redundant `create()`-then-`init()`-calls-`setup()` (or `reset_me()`
calling `setup()`) chain -- confirmed live via a static scan of every
`init()` body in this lib: 45 NPC/item files call `setup()` directly
or via `reset_me()` from `init()`, after `create()` already called
`setup()` once (which already made the object `living()`). Calling
`enable_commands()` a second time on an already-`living()` object makes
the driver re-invoke that object's own `init()` as a side effect, which
re-enters this same chain while the original call is still on the
stack -- genuine reentrancy, crashing with "Too deep recursion" (most
likely to surface on an NPC's first-ever preload/compile).

same as `sjpl2` (shared lineage): `feature/damage.lpc`'s `revive()` calls `this_object()->enable_player()` while the object is still `living()`. This confirms a bare `if (living(this_object())) return;`
guard would be the WRONG fix (it would silently break that legitimate
re-enable) -- used the same true reentrancy-flag fix as `mhxy` instead:
a `nosave private int in_enable_player_now;` set for the duration of the
wrapper's body, guarding only genuine same-call-stack reentrancy while
leaving every legitimate re-enable (revive/wakeup/disguise) unaffected.
`feature/command.lpc`'s `enable_player()` had a single fall-through exit
(no early `return`s), so one guard-at-top + one clear-at-bottom pair was
sufficient. Verified via a single-file `lpcc --batch` compile check
(PASS) -- not individually live-boot-tested.

## 深度功能测试（2026-09-03，第三轮）

新角度：2026-08-08 第一轮已经走完注册、战斗、完整死亡/复活和留言板。
本轮补商店，并尝试红旗镖局拜师。手足 `sjplgfjxb` 同一轮刚修过缺失
`dishes/` 键把整张货表拖垮的 bug；这份完整档带着
`d/city/obj/food/dishes/dish*.lpc`，预期不会踩那个洞。

- **商店（通过，菜谱是齐的）**：管理员落地在鬼门关（上一轮死亡测试把
  `fluffos` 的 startroom 留在 `/d/death/gate`，不是新 bug）。
  `goto /d/city/kezhan`，`list` 列出烤鸡腿 / 包子 / 牛皮酒袋 / 油辣猪
  排，以及十道真正的 `dishes/` 菜（油炝大虾、红烧素鹅、京酱肉丝等）。
  `clone /obj/money/gold` 后 `buy fried chicken leg from waiter` 成功
  （「你向店小二买下一根烤鸡腿」），找零七十文 + 九十九两银子。
  `feature/vendor.lpc` 没有缺档崩溃。不需要把 `sjplgfjxb` 的
  `file_size` 守卫搬过来——这边货物档案都在。
- **拜师（续完，不是 `input_to` / `command()` 的 bug）**：上一小段
  停在「你想要拜庄容为师。」、`score` 仍是普通百姓。本段冷启动复
  核：庄容 `living()` 为真（`apprentice` 的弄醒检查能过）、
  `query_path()` 是 `({ "/cmds/std/" })`、`find_command("recruit")`
  能解析到 `/cmds/std/recruit`、`command_hook` 也挂在 NPC 的
  sentence 上。巫师 `call zhuang->command("say …")` 返回 0 是假阴
  性——`call` 走 `call_other`，找不到 LPC 函数 `command`，碰不到
  efun；`call -Root zhuang->force_me("say 探测命令")` 成功（「庄容
  说道：探测命令」）。`force_me("recruit fluffos")` 在 pending 已
  经设好时仍返回 0，且没有任何「禁止玩家收徒」提示。
  根因是测试号还是**鬼魂**：`call me->is_ghost()` = 1（2026-08-08
  死亡测试留下的 `ghost` 标志；`enter_world()` 见鬼魂就强送
  `/d/death/gate`，所以看起来像 startroom 被留在鬼门关）。
  `feature/name.lpc` 的 `id()` 先问 `this_player()->visible()`，
  `std/char.lpc` 的 `visible()` 对非鬼魂观察者隐藏鬼魂，于是庄容的
  `present("fluffos")` 找不到人，`recruit.lpc` 走 `notify_fail`
  （失败句写在 NPC 身上，玩家看不见）。`input_to` 确认步本身没问
  题：`be_ghost(0)` 之后原样 `apprentice zhuang` → 再输入 `zhuang`
  →「庄容决定收你为弟子」「恭喜您成为红旗镖局的第四代弟子」。
  `score` 为「红旗镖局趟子手」「你的师父是庄容」。`save` 后同进程
  重连、以及杀掉驱动冷启动再登，都还在；冷启动落地大慈恩寺（巫师
  `wiz_level > apprentice` 的 startroom 覆盖），不再进鬼门关。
  未改 `apprentice.lpc`（中途试过拿掉 `input_to` / `call_out` 推迟，
  都已还原）。
- **`save`**：拜师后 `save` 回「档案储存完毕。」
- **日志**：live `debug.log` 为 `libs/sjplii/log/debug.log`。本轮无
  `error:` / `Too deep recursion` / `couldn't find object`。
  `work/log/log` 只有编译警告。
- **结论**：燕云客栈 `list`/`buy` 通过（完整菜谱）。红旗镖局拜师在
  清掉鬼魂标志后通过，并跨冷启动保持。不是编程 bug。未改代码。

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 10 line(s) in 4 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.


## 深度功能测试（§10.7，2026-10-04）— undefined macro and simul_efun gaps

- 4 file(s) `inherit F_SSERVER;` and no header defines it (2 did not compile: `syntax error, unexpected L_IDENTIFIER, expecting L_STRING or '('`). `#define F_SSERVER "/feature/sserver.lpc"` in `include/globals.h` (KB 04 §6.2, `scripts/lpc_alias_macro.py`). 0 still fail.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 2 here-document block(s) repaired (1 with the terminator glued to the last text line, 1 with it indented), so `End of file in text block` no longer hides the room or object behind them: `d/wuhan/wroad2.lpc`, `u/lark/yangmingzhai/ss.lpc`. The terminator must start its line (the lexer's own test, KB 04 §6.10); a glued one lost its newline in the GBK -> UTF-8 conversion together with a half character, which stays out.

## 深度功能测试（§10.7，2026-10-05）— tail() simul_efun

`scripts/lpc_add_tail.py --apply`: `cmds/arch/tail.lpc`, `cmds/wiz/tail.lpc` call `tail(file)`, an efun of the MudOS this archive ran on that FluffOS does not have (`Undefined function tail`: the command did not compile). `adm/simul_efun/file.lpc` now defines `void tail(string file)`: the last 10 lines of the file, written to the player. Load check (HEAD against the working tree): 2 of the 2 tail command file(s) failed to load at HEAD, all load now, and the simul_efun file loads. KB 04 §6.2.

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `std/room.lpc`：`make_inventory()` 用 `catch()` 包住 `new(file)`，做不出来就返回 0；`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-07）— 错误处理器自身出错

主控对象 `adm/obj/master.lpc` 的 `report_error()` 用 `CHANNEL_D->do_channel(this_object(), ...)` 把运行错误报到频道，但主控对象没有 `query()`，`channeld` 拿不到 `channel_id`，就去取 `capitalize(me->query("id"))`，即 `capitalize(0)` 出错——没有玩家触发的错误（call_out、heart_beat、加载时）都让错误处理器自己再出错（`Error in mudlib error handler: *Bad argument 1 to capitalize()`），频道上收不到错误报告。照 `sj` 的主控对象补上 `query("channel_id")` 返回 "系统核心"。验证：加载一个出错的 NPC，修改前出现 `Error in mudlib error handler`，修改后错误处理器正常跑完。

## 深度功能测试（§10.7，2026-10-07）— 编译警告整理

`scripts/lpc_warnings.py sjplii --fix` 加 `scripts/lpc_fix_no_effect.py --apply`，共改动 1221 个 `.lpc` 和 4 个 `.h`（多为删去未用的局部变量）。HEAD 与工作树分别加载（新进程）：1167 -> 1167 通过，无回退；改过的头文件的 148 个包含者 145 -> 145 通过。启动时警告 20 -> 0；新进程登录（新人物确认）正常。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 4 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 0 个，只在 #if 分支用的声明移进分支 1 个文件；改动 4 个文件，HEAD 与工作树各载入一次无回退（4 objects; HEAD PASS 4, tree PASS 4; regress 0; newly loading 0），这些文件的警告 4 -> 0。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查

- `u/kyd/npc/luqingdu.lpc`：已给过任务物品时的回话少了 `return`，玩家得不到任何答复；补上。`u/gdjk/hongnong/npc/chigu.lpc` 末尾空的 `else if (exp <= 102000) { }`、`u/xiyu/shanjiao.lpc` 空的 `if (current_water == 0) {}` 删去（行为不变）。
- 改动的对象载入无回退。

## 编译警告收尾（2026-10-13）

`scripts/lpc_twin_port.py adopt sjpl2 sjplii` 搬来 sjpl2 同日整理（4c889b95867）的 10 个文件（`d/chengdu/npc/cheng.lpc` 等的多余继承、两把剑的 `query_autoload`），能编译的文件警告清零；改动的 10 个对象在 HEAD 与工作树各载入一次：HEAD PASS 7，tree PASS 9，regress 0。

- `d/yangzhou/npc/mouse.lpc` 的闲逛 `(: "random_move" :)` 只返回字符串，老鼠从不走动；改成 `(: random_move :)`。
- `u/losey/gogoha.lpc`（巫师 losey 的居所）内层 `/* sizeof() == 2 */` 提前结束了外层注释、结尾又写成 `* /`，房间从没编译成功；内层改 `//`、结尾改 `*/` 后载入。
- 未改：`d/wuhan/npc/npc.lpc`、`cmds/adm/locate.lpc`、`u/lark/luoyang/room1.lpc` 是几个文件首尾相接贴成的一个文件，编译失败，按原样保存（见 sjpl2 NOTES）。
- 2026-10-14：`data/emoted.o`（表情守护进程的存档）整个还是原档案的 GBK 编码，没有转成 UTF-8，`restore_object()` 报 `Invalid utf8 string while restoring emote`，表情守护进程启动时一个表情都没有。现按 GB18030 转码，丢掉原文件里几个被截断的半个字符。转码后 `adm/daemons/emoted` 载入不再报错（HEAD 上报错）。

## 内力/精力当作伤害种类（2026-10-15，KB 06 §7.241 第二类）

本库 `feature/damage.lpc` 的 `receive_damage()` 不接受 `jingli`/`neili`/`force` 等种类，`me->receive_damage("jingli", 30)` 之类在练功、绝招、吸取时报 `F_DAMAGE: 伤害种类错误`。4 处改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py` 第二步）。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

4 个文件（技能、绝招、兵器、书籍、区域 NPC 等）来自侠客行体系（qi/jing/neili），而本库人物是 gin/kee/sen/force：`receive_damage("qi", ...)` 报 `伤害种类错误`，`query("neili")` 永远为 0。按 qi→kee、jing→sen（本库学习/读书指令消耗的就是它）、neili→force、max_neili→max_force、jiali→force_factor 改名（`scripts/lpc_port_es_props.py --any-file`）。

## 治疗/疗伤的属性名（2026-10-15，KB 06 §7.241）

`receive_heal()`/`receive_curing()` 也只接受本库的种类。6 个文件（多为只调用 `receive_heal`/`receive_curing` 的药物、NPC）来自侠客行体系，按 qi→kee、jing→本库学习指令消耗的池、neili→force 改名（`scripts/lpc_port_es_props.py --any-file`）。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。1 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。

## 暗器功夫身上没有对应暗器（2026-10-15）

`bolt-throw`（玉石棋子）和 `fozhu-throw`（玄木佛珠） 的 `query_action()` 先 `present("yushi qizi", me)` 取暗器，再直接调用 `qizi->query_amount()`：throwing 映射到这门功夫、手里拿的却是别的暗器（身上没有这种棋子/佛珠）时，每次出招都报 `Bad argument 1 to call_other()`。数量改为 `objectp(qizi) ? (int)qizi->query_amount() : 0`，兵器判断前补 `!objectp(weapon) ||`，没有对应暗器时退回普通招式。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`iceclaw`→`ice_claw`（`ice_claw`）；`leaf_strike`→`leaf-strike`（`leaf-strike`）；`mizongquan`→`mizong-quan`（`mizong-quan`）；`senluo_force`→`senluo-force`（`fanliangyi-dao`）；`zongzi-force`→`tongzi-force`（`weituo_chu`）。

## 技能名拼错：技能文件里拼错自己的名字（2026-10-15，KB 06 §7.249）

技能自己的文件（或它的绝招目录）里，`query_skill()` 读的是差一个字母的自己的名字，永远得 0：“基本功夫要高过本技能”之类的限制从不生效，按等级取招、计算伤害的那一项一直是 0。改为本技能的名字（`scripts/lpc_fix_skill_typo.py` 的 self 判据）：`wave_step`→`wave_steps`（`bagua-steps`）。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

95 个文件、122 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/clone/misc/cloth`、`/d/city2/obj/jinduan`、`/obj/armor/tiejia`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 0 个，改后 58 个（58 个原来载入不了），没有退步；其余 37 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## 补回丢掉的基类宏（2026-10-18，KB 04 §6.13）

`inherit F_XXX;` 里的宏本库任何头文件都没有定义，报 `syntax error, unexpected L_IDENTIFIER, expecting L_STRING or '('`，整个对象载入不了；宏指向的基类文件本库其实有，别的库都把这个宏定义成同一个路径。在全局头文件 `include/globals.h` 里补上：`F_DEALER` → `/feature/dealer`（28 个文件）、`F_UNIQUE` → `/feature/unique`（19 个文件）。（`scripts/lpc_restore_macros.py`）改后用 `lpcc` 逐个载入这些对象：47 个里 10 个通过，其余 37 个还有别的错误（`d/chengdu/boss.lpc`：Undefined variable 'MONEY_D'；`d/chengdu/cdjiulou2.lpc`：Undefined variable 'MONEY_D'；`d/chengdu/jiulou2.lpc`：Undefined variable 'MONEY_D'……）。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 36 个对象设了本库没有文件的武功（44 个名字，最多的是 `cuff`、`wenjia-quan`、`shaolin-shenfa`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：30 个里 20 个通过，其余 10 个停在别的错误上（`d/npc/killer-n`：*No program in object '/d/npc/killer-n'!；`d/wuhan/npc/npc`：*No program in object '/d/wuhan/npc/npc'!……）。（`scripts/lpc_guard_set_skill.py`）

## 通向不存在房间的出口，按对面房间的回头出口改正（2026-10-18，KB 06 §7.257）

房间出口 `"west": __DIR__"xxx"` 指向的文件本库没有，玩家走过去就被卡住（笔误、改过名的房间，或者没带进档案的编号房间）。对面的房间存在、并且它相反方向的出口正好指回这个房间，说明出口原本就是通向它：`/d/chengdu/dao` 的 `south`：`dadao1` → `dadao2`。改动后每个出口都能解析到本库的文件（`scripts/lpc_fix_dead_exits.py`；目标在运行时本来就能载入的库——虚拟房间——不动）。

## 补回本库没有的基类文件（2026-10-18，KB 04 §6.15）

下面这些基类本库没有，继承它们的对象（房间、NPC、物品）整批载入不了（`inherit XXX;` 的宏没定义，或者 `inherit "/std/…";` 的文件不在）。同系的库里有同名文件，两库有大量逐字节相同的文件（亲缘关系），所以从那边原样拷来，缺的宏补进全局头文件 `include/globals.h`：`/std/weapon/mace`（宏 `MACE`）←dtslmud，21 个对象继承它，抽样 8/8 载入；`/std/weapon/rake`（宏 `RAKE`）←dtslmud，5 个对象继承它，抽样 5/5 载入；`/std/weapon/archery`（宏 `ARCHERY`）←dtslmud，2 个对象继承它，抽样 2/2 载入；`/inherit/weapon/bow`（宏 `BOW`）←fys，2 个对象继承它，抽样 2/2 载入。每个基类补回后单独载入、再抽样载入使用它的对象，基类载不进来或者一个用户也载不进来的就撤掉（本库撤掉了它们，不再补）。（`scripts/lpc_restore_bases.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 14 处、7 个文件：`iceforce`→`ice_force`（14 处）。（`scripts/lpc_fix_skill_names.py`）

## 武功基类缺少 NewRandom()（2026-10-19，KB 06 §7.261）

基本武功（`boxing`、`houquan`、`westsword`、`taiji-quan` 等）用 `action[NewRandom(i, 20, level/5)]` 挑招式；`NewRandom()` 和它调用的 `sum()` 在别的库的武功基类里有，本库的 `/std/skill.lpc` 是更精简的版本，没有，于是这些武功全都报 `Undefined function NewRandom` 编译不过，有这门武功的人物只能空手。把这一对函数（115 个库共用的同一份文字）补进武功基类，受益武功 2 个：`/d/chengdu/skill/jinshe-jianfa.lpc`、`/daemon/skill/hou_ken.lpc`。（`scripts/lpc_restore_skill_helpers.py`）

## 技能基类丢了“预备武功”那一段（2026-10-19，KB 06 §7.262）

`feature/skill.lpc` 有 `skill_map`/`map_skill()`，却没有预备武功（`prepare_skill`）这一块：变量 `skill_prepare`、`prepare_skill()`、`query_skill_prepared()`、`query_skill_prepare()`。来自 xkx 系列的 NPC 在 `create()` 里调用 `prepare_skill("cuff", ...)`，于是 `Undefined function prepare_skill` 整个 NPC 载入不了。从同系的 xkx100 把这一块原样补回（声明加在 `skill_map` 后面，函数加在文件末尾），受益 NPC 12 个：`d/jiaxing/npc/limochou`、`d/npc/killer-n`、`d/xiangyang/npc/dingpopo`、`d/xiangyang/npc/pingpopo`。（`scripts/lpc_transplant_function.py`）

## feature/damage.lpc 丢了 set_ghost()（2026-10-19，KB 06 §7.262）

`feature/damage.lpc` 里有 `int ghost` 和 `is_ghost()`，没有 `set_ghost(int i)`；木人、狼等 NPC 在 `create()` 里调用它，整个 NPC 报 `Undefined function set_ghost` 载入不了。从 xkx100 补回这一行函数，受益 NPC 1 个：`d/xiangyang/npc/muren`。（`scripts/lpc_transplant_function.py`）

## simul_efun 丢了 unew()（2026-10-19，KB 06 §7.262）

`adm/simul_efun/object.lpc` 没有 `unew()`（带“独一无二”次数限制的 `new()`），`d/jiaxing/npc/limochou` 按 xkx 一系的写法调用它，`Undefined function unew`。从同系的 xkxz2 把这个函数原样补回 `object.lpc` 末尾（`scripts/lpc_transplant_function.py`）。这个物件还差宏 `BINGQI_D`（本库的头文件没有定义），所以仍载入不了，属于未定义宏一类，另案处理。

## 全局头文件丢了 3 个宏（2026-10-19，KB 04 §6.16）

`/include/globals.h` 里没有定义 `RICH_B`、`PKER_B`、`EXP_B`，用到它们的物件（名单里 1 个）编译时报 `Undefined variable`/`Undefined function`，整个物件载入不了（编译器在第一个未定义的名字上停下，后面的错误和警告都看不到）。同系的库在各自的头文件里都有这几行：照其中和本库共有文件最多的那个库，原样补到 `/include/globals.h` 最后一个 `#define` 之后，宏体里出现的路径在本库里都存在。补完后名单里有 1 个载入，其余还差别的东西。（`scripts/lpc_restore_defines.py`）

## 找不到父类函数的 ::fn() 调用（2026-10-19，KB 06 §7.259）

`/d/city/obj/book/kugu-2.lpc`、`/d/city/obj/book/kugu-3.lpc`、`/d/city/obj/fabao/kunxian-suo.lpc`共 3 个物件里写着 `::create();`、`::init();` 这类调用，而它们继承的基类并没有这个函数。老驱动把这种调用当成什么都不做、返回 0 的空调用，本驱动在编译时报 `Unable to find the inherited function 'init'.`，整个物件载入不了。这些物件的错误只有这一种（其他错误清掉之后才露出来的），逐个删掉这些调用（`return ::fn(...)` 改成 `return 0;`）。（`scripts/lpc_fix_dangling_super.py`）

## 出口指向不存在的房间（2026-10-19，KB 06 §7.257）

下列房间的出口写的文件不存在，而对面恰好只有一个房间的出口指回本房间，所以按对面的房间改正（笔误、大小写、路径少了一级）：

- `/d/latemoon/in_room/flower1.lpc` 的 `north` 出口：`corridor7` → `backroom`

改后房间照常载入（与 HEAD 逐个对比，没有退步），出口现在指向存在的房间。

## 区域物件的零碎修正（2026-10-19，KB 06 §7.267–§7.271）

- 补上 `adm/daemons/moneyd.lpc`（取自带同一份 `feature/dealer.lpc` 的 jqxz2008）和 `include/globals.h` 的 `MONEY_D`：`feature/dealer.lpc` 之前编不过，所有继承 `F_DEALER` 的店主都载入不了

逐个物件与 HEAD 对比载入，没有退步。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 钱庄老板和客店留言板（2026-10-19，KB 06 §7.262）

`d/hangzhou/npc/qzlaoban`、`d/suzhou/npc/laoban2`（钱庄老板）`inherit F_BANKER`（`/feature/banker`），档案里没有这个文件，NPC 载入不了；取 xkx100 的 `feature/banker.lpc`（`MONEY_D` 已在上一批补上）。`d/hangzhou/tianxianglou` 和 `d/suzhou/kedian` 开头的 `"/clone/board/kedian_b"->foo();` 指向一块档案里没有的留言板（整个 `clone/board/` 都不在），房间载入不了；这两行删掉（`u/kunlun` 下巫师目录里的留言板调用不动）。

## 补回本库没有的基类文件，第二轮（2026-10-19，KB 04 §6.15、§6.18）

宏有定义、基类文件却不在档案里：继承它的对象载入时报 `Inherited file '…' does not exist!`，编译扫描看不到这一类（`scripts/lpc_missing_inherits.py` 能列出）。同系的库里有同一个文件，原样拷来（`scripts/lpc_restore_bases.py`）；基类和继承它的对象 include 而本库没有的头文件一起带来。每个基类补回后单独载入，再载入使用它的对象，载不进来、或一个用户也载不进来的撤掉了。

- `/std/char/kzznpc`（宏 `KZZNPC`）←fys：15/15 个继承它的对象载入，同时带来头文件 `/include/kzznpc.h`、`/include/die.h`
- `/inherit/weapon/weapon`（宏 `M_WEAPON`）←xjcq2000：5/5 个继承它的对象载入
- 玩家打造兵器的模板（7 个文件）这回有了基类，照 KB 06 §7.275 加上没有打造者时的保护（`scripts/lpc_fix_forge_template.py`）。

逐个与 HEAD 对比载入，没有退步。

## 标准整理轮，第二轮（2026-10-19，`scripts/toolkit_fix.sh`）

本库在新驱动下重扫，机械修复：8 个未使用的局部变量，2 个文件的 void 函数返回值，1 处 inherit 顺序。修后与 HEAD 逐个物件对比载入，没有退步。

## 补回丢失的标点（2026-10-19，KB 03 §4.6）

转换时丢掉的分号、逗号、引号或文件末尾的 `}`，共 2 个文件，修前 HEAD 载入失败。文件末尾少了 `}`（最后一个或两个字节丢了），补上：`/u/kyd/npc/obj/caidao.lpc`、`/u/kyd/obj/caidao.lpc`。修后与 HEAD 逐个对比载入：这 2 个物件全部载入，没有退步（`scripts/lpc_restore_from_twin.py`、`lpc_fix_eaten_quote.py --comma`、`lpc_fix_eof_braces.py`）。

## 旧驱动的类型宽松：缺省参数、无类型形参、数组初始化、`class` 变量（2026-10-19，KB 04 §6.19、§6.20）

原来的 MudOS 把调用少传的参数补 0、把没写类型的形参当 `mixed`、不检查变量的声明类型与初始值，也允许变量叫 `class`；这个驱动在编译时全部拒绝，整个物件载入失败。修了 1 个文件：`/u/jakey/obj/origin.lpc`（`scripts/lpc_round_files.py` 的修复轮：调用处补写 `0`、无类型形参补 `mixed`、`string X = ({...})` 补星号、void 函数的返回值，以及 `class` 变量改名 `pick_class`）。逐个文件在 HEAD 和改后载入对比：这些文件里 1 个原来载入失败、现在载入，没有退步。

## `call_out_info()` 的每一项只有 3 个元素（2026-10-20，KB 06 §7.287）

驱动返回的是 `({ 物件, 函数, 延迟 })`，不带 call_out 的参数，旧代码读第 4 项 `info[i][3]`（`callouts` 指令、`calloutd`、`cod` 工具）一读就报 `Array index out of bounds`，指令从第一行起什么也打印不出来。改为 `(sizeof(info[i]) > 3 ? info[i][3] : 0)`（`scripts/lpc_fix_callout_info.py`）。改动：`/cmds/arch/callouts.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 2 处）。改动：`/d/fuzhou/npc/mei_po.lpc`（1 处）、`/d/wuhan/npc/obj/letter.lpc`（1 处）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/obj/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## sefun `cat()`：缺文件时 `write(0)` 报错（2026-10-20，KB 06 §7.297）

`void cat(string file) { write(read_file(file)); }`：文件不存在（压缩包没带的欢迎/公告文件，或只有运行中的 mud 才会写的日志）时 `read_file()` 回 0，`write(0)` 在本驱动里报 `Bad argument 1 to receive()`，调用者（登录对话、`cat` 指令）被中断；老驱动什么也不打印。改成 `write(read_file(file) || "");`（`scripts/lpc_fix_cat_unchecked.py`）。改动：`/adm/simul_efun/file.lpc`。

## 翻页器 `start_more(read_file(...))`：文件缺失时 `explode(0)`（2026-10-20，KB 06 §7.300）

东方故事系的翻页器 `void start_more(string msg) { ... explode(msg, "\n") ... }` 被这样调用：`start_more(read_file(HELP_DIR + "help/topics"))`、`start_more(read_file(NEWS))`。压缩包没带的文件使 `read_file()` 回 0，`explode(0, ...)` 在本驱动里报 `Bad argument 1 to explode()`（不带参数的 `help` 指令就是这样出错的），老驱动把 0 当空文本。在 `start_more` 开头加了 `if (!stringp(msg)) return;`（`scripts/lpc_fix_start_more.py`）。改动：`/feature/more.lpc`。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库现有的 NPC 文件里没有字面写成空 `chat_msg` 的（扫描只认 `set("chat_msg", ({ }))`）；守卫挡的是运行时才为空的列表和以后新增的 NPC。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/cmds/std/char/npc.lpc`、`/feature/newvendor.lpc`、`/std/char/new_npc.lpc`、`/std/char/newvendor.lpc`、`/std/char/npc.lpc`、`/std/char/vendor.lpc`（等共 7 个文件）。

## 巫师命令不带参数时对 0 调用 efun（2026-10-21，KB 06 §7.336）

巫师（管理员）把命令敲成不带参数时，驱动把 0 传给字符串参数；下面的命令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`，这条指令从来没有用过。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py` 在第一处使用参数的语句前加守卫：没有 `help()` 的是 `return notify_fail("…\n");`。改动（2 个文件，括号里是接住 0 的 efun）：`/cmds/adm/cmaterial.lpc`（`sscanf`）、`/cmds/adm/cpall.lpc`（`read_file`）。加载检查 HEAD 与工作树对照，没有退步。

## 帮会税 `/cmds/adm/ctom.lpc`：档案里没有帮会地盘模块（2026-10-21，KB 06 §7.344）

`/d/chengdu/npc/qiuwa.lpc`、`/d/chengdu/npc/wenlaoban.lpc` 在收钱的 `accept_object()` / 兑换函数里调用 `"/cmds/adm/ctom.lpc"->save_money(..)`（把一半钱记给占着地盘的帮会）。本库没有 `ctom`，也没有 `/clone/misc/area`、`lingpai` 这套帮会地盘模块，玩家付住店钱或兑换时在 `return 1` 之前抛错（客栈老板那一支连 `rent_paid` 都有时来不及设）。调用前加 `file_size("/cmds/adm/ctom.lpc") > 0` 的判断（KB 06 §7.308 的写法），模块以后补上就自然生效。

## 拼错的 `call_out()` / `input_to()` 目标（KB 06 §7.349，2026-10-21）

计时器或输入提示给驱动的函数名和文件里定义的差一个字母；驱动对不存在的函数静默不理，所以对应的计时从来没有触发过。调用和配套的 `remove_call_out()` 改成已定义的拼法：`find_seal`：`disapprear` → `disappear`（法术产生的封印十分钟后从不消失）。改动：`/daemon/class/taoist/scratmancy/obj/find_seal.lpc`。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 24 条注册（11 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/d/city/famous.lpc`（`do_bian`、`do_upadm`、`do_upboot`、`do_uplock`）、`/d/city/piggy.lpc`（`do_bian`）、`/d/city/qiyuan.lpc`（`do_pass`、`do_resign`）、`/d/suzhou/liang3.lpc`（`do_jump`、`lingwu`）、`/d/village/npc/seller.lpc`（`do_buy`）、`/d/wuhan/hankou/npc/xiaoboss.lpc`（`do_buy`）、`/std/qitem.lpc`（`do_sing`）、`/std/qitem1.lpc`（`do_cures`、`do_defend`、`do_lookfor`、`do_sing`等）、`/y/city/famous.lpc`（`do_bian`、`do_upadm`、`do_upboot`、`do_uplock`）、`/y/city/piggy.lpc`（`do_bian`） 等共 11 个文件。最多的函数名：`do_bian` 4 处、`do_upadm` 2 处、`do_upboot` 2 处、`do_uplock` 2 处、`do_pass` 2 处。

## 缺失物品的 `new()` / `carry_object()` 调用链加了保护（2026-10-22，KB 06 §7.73 补充）

`new(路径)->move(...);` / `carry_object(宏("x"))->wear();` 这类语句，路径指向的文件在这个压缩包里没有：`new()` 返回 0，`->move()` 在 0 上报 `Bad argument 1 to EFUN call_other()`。在 `create()` 里这个对象永远加载不了，在 `reset()` 里第一个缺失物品之后的刷新每次 reset 都被跳过。1 个文件里 1 处（`new`）改成 `{ object new_ob = new(路径); if (new_ob) new_ob->move(...); }`（`scripts/lpc_guard_carry_object.py --new`：路径按这个文件自己看到的宏解析，宏名冲突、虚拟对象路径一律跳过）。 对这 1 个改动文件做加载检查（HEAD 与工作区对比）：HEAD 能加载 1 个，现在 1 个（新增可加载 0 个，回归 0 个）。

## 调用了、但这个库自己的守护进程里没有的函数（2026-10-22，KB 06 §7.354）

`MACRO->函数()` 调用的函数在这个库的守护进程里不存在：`call_other()` 对不存在的函数不报错、只返回 0，所以这些功能（时间显示、昼夜事件、名字检查、价格文字……）一直没起作用。同一血统另一个库的同名守护进程里有这些函数，原文照抄到本库守护进程末尾（`scripts/lpc_port_function.py`；调用处传的参数个数、函数体用到的函数 / 全局变量 / 宏 / 字符串键都在本库里有，已核对；守护进程在 HEAD 和工作区都能加载，每个函数用固定参数各调用一次：HEAD 返回 0，现在返回正常的值）：`/adm/daemons/chinesed.lpc` ← fengyun434：`check_control()`（1 处调用）、`check_length()`（5 处调用）、`check_return()`（1 处调用）、`check_space()`（1 处调用）、`check_chinese()`（1 处调用）。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 还剩 3 个函数没有补（inquiry 3）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/d/yangzhou/npc/woman1.lpc`:`about_he`、`/y/city/npc/heyunfeng.lpc`:`about_he`、`/y/city/npc/heyunfeng.lpc`:`about_yang`。 另有 1 处函数体被作者整段注释掉（指针没跟着删），是有意关掉的，没动。

## 运行期目录 `log/nosave` 不存在，写日志的 `write_file()` 直接报错（2026-10-22，KB 03 §4.3 补充）

这个库的 21 个文件里有 24 处 `write_file("/log/nosave/...")` / `log_file("nosave/...")`（`static` 改 `nosave` 时连字符串里的日志路径一起改了，原来是 `log/static/`）：`nosave/promotion`、`nosave/CALL_PLAYER`、`nosave/CRASHES` 等。压缩包和站点包里没有这个目录，`write_file()` 在目录不存在时抛 `*Wrong permissions for opening file /log/nosave/... for append. "No such file or directory"`，调用它的函数（杀人记录、重启记录、`call` 日志……）当场中断。把 `log/nosave` 记进 `scripts/wasm_keep_dirs.txt`（站点和 pristine 树都按它建空目录）；没有把字符串改回 `static`。证明（`scripts/lpcc_eval.py`，`catch(write_file("/log/nosave/ZZTEST", ...))`，fqyy2 / hy5 / bmxkx2001 的新进程）：补目录前报上面的错误，补后写成功。

## 不带前导斜杠的物品路径：缺失物品的 `new()` / `carry_object()` 调用链加了保护（2026-10-22，KB 06 §7.73 补充）

`carry_object("d/city/obj/jiasha")->wear();` 这类路径不带前导斜杠的写法在这个驱动里按根目录解析（`new("d/city/obj/changjian")` 能加载 `/d/city/obj/changjian`），所以和带斜杠的一样：文件不在压缩包里时 `new()` 返回 0，`->wear()` 在 0 上报 `Bad argument 1 to EFUN call_other()`，整个 NPC 加载不了。此前的保护工具把这种写法当作「相对当前目录，没法判断」跳过了。1 个文件里 1 处（`clone/misc/cloth`）改成带保护的块（`scripts/lpc_guard_carry_object.py`）。 对这 1 个改动文件做加载检查（HEAD 与工作区对比）：HEAD 能加载 0 个，现在 1 个（新增可加载 1 个，回归 0 个）。

## `(: 函数名 :)` 指针指向本库没有的函数：只含这个指针的行加了注释（2026-10-22，KB 06 §7.355 补充）

`inquiry` / `item_desc` / `chat_msg*` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：用到时（`ask`、`look`、NPC 闲聊）驱动抛 `*Undefined lfun pointer called: 函数名`，这一拍心跳的后半段被跳过。这些函数没有可以补回的来源（别的库同一路径的文件里没有，或者它还要用本库没有的东西），所以 3 个文件里 4 行只含这个指针的行（`(: movemove :),` `"help": (: about_he :),` `"谷兰香": (: about_he :),`）加了注释，原文保留并写明原因，这一项当作没有这个话题 / 物品 / 闲聊条目（`scripts/lpc_fix_dangling_lfun.py`；`#include` 的文件在库里缺失的对象、指针不在整行上的写法没动）。 前提（`function_exists()`）和加载检查（HEAD 与工作区对比，本库改动的 `.lpc` 文件）的结果见 KB 06 §7.355：没有一个回归。

## 长度检查按字节写，旁边的提示按汉字写：18 处（2026-10-22，KB 06 §7.362）

老档的 `strlen()` 数字节（一个汉字 2 字节），转成 UTF-8 后它数字符：提示写「必须是 2 到 6 个中文字」的检查还是 `strlen(name) < 4 || strlen(name) > 12`，于是两三个字的房名、帮会名、群名、聊天室名、称号被提示自己说允许的那句话拒绝，上限却是提示的两倍；留言板的标题检查 `i < 4 || i > 24 || i % 2` 还会拒绝所有奇数个字的标题（`post 你好吗`）。本库 18 处（9 个文件）：`if ((strlen(name) < 2) || (strlen(name) > 12)) {`（`/adm/daemons/logind.lpc:658`）；`if ((strlen(name) < 2) || (strlen(name) > 40)) {`（`/d/city/npc/caifeng.lpc:135`）。`scripts/lpc_fix_strlen_gate.py` 以提示为准：条件里每个 `strlen` 门槛都恰是提示所说数字的两倍才折半，存长度的变量（`i = strlen(arg);`）的门槛和 `|| i % 2` 奇偶项、其后循环的 `i % 2 == 0 &&` 一并处理；提示里有英文 / 字母 / 字节的不动。证明（`scripts/lpcc_eval.py`，bxsj 的留言板，求值对象继承 NPC 并重写 `edit()` 记录调用，`command("post 标题")`）：HEAD 拒绝「你好」和「你好吗」、放行 23 个字的标题；改后接受前两个、拒绝第三个；shenmo 的 `named.lpc invalid_new_name("张三")`：HEAD 回 `名字只能是2-4个中文字。`，改后回 0。抽样 24 + 15 个库的 HEAD / 工作树加载对比 0 退步。

## 按字节写的汉字循环、茶馆猜诗和同盟频道标题（2026-10-23，KB 06 §7.363）

老档按字节做「一个汉字」：`while (i--) if (i % 2 == 0 && !is_chinese(name[i..<0]))` 只检查偶数下标，奇数位上的拉丁字母（`张a`）会过；茶馆猜诗 `mixup()` 用 `strlen(str)/2` 再 `j=j+j`、`str[k..k+1]` 交换两字节；泥潭系 `channeld` 的 `switch (strlen(fname)) case 4/6/8/10` 和 `strlen(family)==4/6` 按字节长度给同盟 / 门派名加空格。本驱动的 `strlen()` 和区间都按字符算。`scripts/lpc_fix_byte_char.py`：去掉奇偶项、把区间改成 `name[i..i]`，按字符重写 `mixup()` 并把 `strlen(first)>=14` 折成 7，频道标题的 case / 门派长度改成字符数（对照 aoxiangtianji）。本库 汉字循环 / `is_chinese` 区间 11 个文件；茶馆猜诗 `mixup` 1 个文件。证明（`scripts/lpcc_eval.py`）：sjplii 的 `check_legal_name` 在 HEAD 接受「张a」、改后拒绝，两边都接受「张三」；xkx100 的 `clubpoem->mixup("离离原上草")` 得到「离离原草上」（真交换汉字）；nitan_san 两字同盟名得到 `【 兄  弟 】`。关键对象加载通过。

## 血条 / 表情标题按字节算显示宽度（2026-10-23，KB 06 §7.365）

老档把汉字当两字节：`bar_string[0..(val * N / max) * 2 - 1]` 把「格数」换成字节下标，半格血条在本驱动（按字符算区间）上会整条画满；巫师表情 `edemote` 的 `repeat_string("─", 13 - (strlen(emotion) / 2))` 也会少减汉字宽度。`scripts/lpc_fix_display_pad.py`：去掉 CJK 血条 / 空白条上的 `* 2`（`jings`/`qis` 赋值和 `blank_string3[0..(23-a)]` 的 23→11 一并改），表情标题去掉 `/ 2`；ASCII 空格的 `none_string` / `empty_string` 仍保留 `* 2`（一格两个空格）。本库 4 处（2 个文件）。证明（`lpcc_eval.py` hhsj）：`tribar_graph(6,9,12)` 在 HEAD 画出整条 12 个■，改后为 6 个■+3 个□；麻将 `strlen(tempB)/2` 是两字符牌码，未改。


## Beyond 出口仍指向 /u/beyond（2026-10-23，KB 06 §7.368）

宁波 / 苏州 / 慕容等区域已进 `/d/ningbo`、`/d/suzhou`、`/d/mr`、`/d/hz`，出口与任务物路径仍写 `/u/beyond/…`。`scripts/lpc_fix_beyond_exits.py` 在目标 `.lpc` 存在时改写（`murong`→`mr`）。本库 7 处。证明：sjplii `xikou` HEAD 西向 `/u/beyond/ningbo/aywsi`，改后 `/d/ningbo/aywsi` 可加载；bxsj `hubian1` 三向均可加载。

## wei #me->move 无法加载（2026-10-27，KB 04 §6.25 Also）

踢人分支写成了 shell 风格的 `#me->move("/d/city/...")`，驱动报 `Unknown preprocessor directive: #me`，对象无法编译。改回 `me->move(...)`。本库改动：`d/chengdu/npc/wei.lpc`。证明：HEAD 加载失败；改后加载成功。

## wife inquiry ask_me 前置声明（2026-10-27，KB 04 §6.25 Also）

`d/chengdu/npc/wife.lpc` 在 `create()` 里写 `"参茶": (: ask_me :)`，但 `int ask_me` 定义在后面，驱动报 `Undefined variable 'ask_me'`。在 inherit 后补 `int ask_me(object me);`。证明：HEAD 加载失败；改后加载成功。

## 铁罗汉 tie-luohan 下标丢失无法加载（2026-10-27，KB 06 §7.348 Also）

`d/chengdu/obj/tie-luohan.lpc`：`snamei` / `skill_statussname` / `hp_statusstr` 等下标括号丢失，缺 `sname = keys(...)`，`me` 未赋值，另有多余的 `return notify_fail` 使技能复制不可达。按手足技能复制形重写 `accept_fight` / `renewing`（保留 FY 的 kee/gin/force）。证明：改前加载失败；改后加载成功。

## fabao EXAMPLE（city/obj）缺 ) 与 !（2026-10-27，KB 04 §6.25 Also）

`d/city/obj/fabao/EXAMPLE.lpc` 与 `d/obj/fabao/EXAMPLE` 同病：`if (objectp(victim = present(target, environment()))`。改为 `if (!objectp(victim = present(target, environment(me))))`。证明：HEAD 加载失败；改后加载成功。
