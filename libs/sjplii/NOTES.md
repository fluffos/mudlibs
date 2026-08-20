
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
