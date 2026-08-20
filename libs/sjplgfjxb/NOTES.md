
## WASM 修复摘要（迁移自 meta.json 的 group_note）

ES II 血统（adm/obj/master.lpc，"original from Lil, rewritten by Annihilator"），飞白工作室《书剑飘零》教学版。WASM 修复：（1）§7.60 类的 master.lpc report_error()→CHANNEL_D 编译期崩溃（这是这个模式的第三个呼叫点，在常见的 log_error()/standard_trace() 之外——report_error() 在这里是它自己独立的函式），已用 find_object(CHANNEL_D) 守卫。（2）adm/daemons/whod.lpc 用了未定义的 REMOTE_DIR 常量，破坏了它（被预载）的编译——已在 globals.h 里加上 #define REMOTE_DIR "/data/remote/"（硬盘上没有对应目录可以推断原意，但 get_dir() 对不存在的目录只会返回空数组，所以这样做是安全的，哪怕这个目录本身从未真正被创建）。（3）§7.41 类损坏的存档数据：adm/daemons/emoted.lpc 的 create() 对自己损坏的 emoted.o 做了未加保护的 restore()，预载时抛出未被捕获的异常；已包一层 catch(restore())，并显式补上 emote=([]) 兜底。深入调查后排除了一个疑似 bug：注册过程中反复出现的"你发现事情不大对了"讯息是这份 mudlib 自己的（有点吵闹但故意如此的）设计——master.lpc 的 log_error() 会把当时正好连线中的玩家告知每一次编译警告，而新角色第一次创建时其继承的各个 feature 档案（alias/damage/more/move/skill/troop）恰好都是第一次编译；临时让 error_handler 无条件显示完整细节后确认，每一条都只是无害的"Unused local variable"警告。管理员账号播种：fluffos (admin) 加入 adm/etc/wizlist（这份档案没有 sj 里那种 securd/securityd 分裂——securityd.lpc 在这里是真正、唯一的安全精灵）。已验证：完整注册（id→确认→名字→密码→确认→电子邮件→性别→出生地选择）→look/score/quit 全部干净，权限正确显示 (admin)，update 成功。LPC 格式化工具对全部 2310 个档案运行；还原了 1 个确认有损坏的档案（一种丢引号的损坏，不是常见的 CJK 重新加空格形态，但被同一个去空格比对扫描抓到），覆盖 17 个格式化工具触碰过的 CJK 间距档案；这份档案里没有 ASCII 地图档案。格式化后重新验证过，干净。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 31 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（§10.7，2026-08-08）

### 血统澄清

`README.md` 一直写"ES II 引擎家族"，但 AGENTS.md §11 的"ES II / 东方故事
mega-family"成员列表（`es1_win`/`esI`、`xkx2001`/`bmxkx2001`、
`xuanjianlu`、`syxjl` 等）里并没有 `sjplgfjxb`/`sjplii` 这一支——本次没
有专门去 diff 核心档案确认这支到底是不是同一个 §11 家族的成员，只是确认
了 `master.lpc` 文件头注释"original from Lil, rewritten by Annihilator"
与 §11 家族描述的血统吻合。留给下次同族横向比对（尤其是 `sjplii`）时顺
手做一次真正的 diff 确认，而不是只看注释文本。

### 本次修复的 bug（均已在原生驱动上逐条改前/改后验证，见下）

1. **§7.34 类调试遗留，`adm/daemons/logind.lpc` 两处**：`get_resp()`
   （第 273 行，接受随机中文名字路径）和 `get_name()`（第 308 行，自
   己输入中文名字路径）各有一行 `printf("%O\n", ob);`，紧跟在中文名
   字确认之后、密码提示之前，把登录物件的内部路径原样打印给玩家——例
   如注册时输入中文名"云中鹤"后，屏幕上会多出一行 `/obj/login#0`。
   两条路径都命中（对应"接受系统建议的随机名字"和"自己打字取名"两条
   分支），已各删一行。改前：`register→...→您的中文名字：云中鹤` 后
   紧接着输出 `/obj/login#0`，然后才是"请设定您的密码："；改后：中
   文名字确认后直接跳到"请设定您的密码："，无任何内部路径泄漏，用一
   个全新注册的 `sjplcheck`（中文名"钱塘潮"）账号验证过。
2. **一处真正的编译期 `error`（不只是 warning）**：
   `d/fuzhou/npc/chess_player.lpc`（棋摊老板"韦守儒"，第 39-40 行）
   `play_chess()` 里 `printf("%s", name(this_player()));` 和
   `command("give chess to " + name(this_player()));` 把继承自
   `feature/name.lpc` 的本地方法 `varargs string name(int raw)`
   （返回*自己*的名字/显示名，参数是"要不要去掉头衔"的整数开关）当
   成"取得*对方*名字"的自由函数误用，传了一个 `object` 进去。驱动的
   静态类型检查在裸调用（非 `->`）上直接拒绝，报错原文：
   `d/fuzhou/npc/chess_player.lpc:39:36: error: Bad type for argument
   1 of name ( int vs object )`（第 40 行同样报错）。这两行 `error`
   （不是 warning）导致这个 NPC 档案**全程无法编译**——福州"茶馆"
   （`d/fuzhou/tearoom2`）第一次填充这个 NPC 时，`master.lpc` 的
   `report_error()`/`log_error()` 链会级联把
   `*No program in object '/d/fuzhou/npc/chess_player'!` 连同一份
   完整的物件状态 dump 反复转发给当时在线的每一个人，刷屏严重。修
   复：`printf` 那行本身也是一处无意义的调试输出（§7.34 同款，删
   除），`command("give chess to " + name(this_player()));` 改为
   `command("give chess to " + this_player()->name());`。改前：
   `update /d/fuzhou/npc/chess_player` 报上面两行 `error`；改后：
   `重新编译 /d/fuzhou/npc/chess_player.lpc：成功！`，`debug.log`
   里此后再没有 `chess_player` 相关的 `No program in object`。
3. **§7.86 类第三个变体（新基类名字）**：`obj/board/wizard_j.lpc`
   （巫师"工作进度报告"留言板，`/d/wiz/jobroom`）`inherit
   "/std/jboard";` 之后，`create()` 尾巴又多余调用了
   `replace_program("/std/jboard");`——和已经扫描修复过的 31 处
   `BULLETIN_BOARD`/`BBS_BOARD` 实例是同一个致命形状，只是这份档案
   的留言板基类不叫 `BULLETIN_BOARD` 而是 `/std/jboard.lpc`（它自己
   的 `do_report()`/`do_describe_project()` 也是
   `this_player()->edit((: lfun, ... :))` 建闭包，同样会撞上"cannot
   bind an lfun fp to an object with a pending replace_program()"）。
   已删除多余的 `replace_program()`。改前：编译时确认过
   `wizard_j.lpc`/`wizard_bb.lpc` 与其余 31 处一样带着这个形状（当
   时只做过编译检查，没做过 `post` 的实机验证）；改后：以 `fluffos`
   管理员账号在 `/d/wiz/hall`（普通 `BULLETIN_BOARD` 板，编号已在此
   前的批量修复里处理过）`post test title` → 输入正文 → `.` 结束，
   `留言完毕。`，`look board` 正确显示
   `[ 1]  test title   云中鹤 (Sat Aug 8 05:05)`；`update
   /obj/board/wizard_j` 单独重新编译也确认无报错（只有两条与本次修
   改无关的 `Unused local variable 'myid'` warning）。**检测方法**：
   `grep -rn 'replace_program' work --include='*.lpc'`，对每个命中
   反查它前面 `inherit` 的是哪个基类，而不是只搜
   `BULLETIN_BOARD`/`BBS_BOARD` 这两个最常见的名字。

### 排查过程中确认"不是 bug"的现象

- **`kill shao nian`/`look shao nian` 一度像是 `present()`/`id()` 失
  效**：`d/fuzhou/eroad2` 街上的"江湖少年"NPC（`obj/npc/shaonian.
  lpc`）打 `kill shaonian`（不带空格）反复报"这里没有这个人。"，甚
  至连打 `kill 江湖少年`（中文全名）也一样失败，一度怀疑是
  `feature/name.lpc` 的 `id()`（`this_player()->visible(this_
  object())` 那个早退分支）或 `present()` 出了问题。临时在 `id()`
  里加了一行 `write_file()` 追踪（`str`/`this_object()`/
  `this_player()`/`my_id`/`visible()` 返回值），重启驱动复现后发
  现：这个 NPC 的 `set_name("江湖少年", ({ "shao nian" }));`——真正
  的 id 是带空格的两个词"shao nian"，不是"shaonian"一个词（对照同一
  份档案里 `kill.lpc` 自己也大量使用"body guard"/"taoist guard"这类
  带空格的多词 id，是这份 mudlib 一贯的命名习惯）。改用
  `kill shao nian`（带空格）复测，命中了正确的对象，但 NPC 恰好在同
  一时刻被自己的 `chat_msg` 触发的 `random_move()` 带离房间（这个
  NPC 的 `chat_chance` 是 15，且没有战斗中禁止走动的锁定），指令送达
  时人已经走了——不是玩家/驱动的 bug，是"打错 id + 目标恰好在闲聊时
  随机走动"两个巧合叠加。`work/feature/name.lpc` 的 `id()`/`visible
  ()` 本身逻辑正确，已移除追踪代码，不做任何修改。
- **README 原文"新角色从长安城的'大慈恩寺'起步"不准确**：
  `adm/daemons/logind.lpc` 的 `enter_world()` 实际按角色创建时选的
  "出生状况"（0-3）从 `start_loc` 数组（山东泰安两间、福州两间民
  居）里选出生地，`START_ROOM`（`/d/city/ciensi` 大慈恩寺）只在
  `!catch(load_object(startroom))` 判定失败（出生地房间加载失败）时
  才作为兜底使用——本次用 4 种出生状况分别注册验证，全部落在对应的
  `start_loc` 房间（例如"武力世家"落在 `/d/fuzhou/minzhai4`，"商贾之
  家"的女性角色落在 `/d/shandong/ta/minzhai2`），从未见过兜底路径被
  触发。已改写 `README.md` 的"内容亮点"第一条为准确描述，长安城本身
  仍然存在且以真实唐代地标为骨架（城门/大慈恩寺等），只是不是新手的
  默认出生点。

### 已验证正常工作（原生驱动，`fluffos`/`Mud@2026` 管理员账号 + 两个
一次性测试角色"赵日天"/"钱塘潮"）

- 完整注册流程（英文 id → 确认 → 中文名字 → 密码 → 确认 → 邮箱 → 性
  别 → 出生状况）→ `look`/`score` → `quit` → 二次连线（`get_passwd`
  路径，非首次注册路径）全部干净；`quit` 后 `debug.log` 只有无关的
  `Unused local variable` warning，没有 §7.16 类 `quit` 崩溃。
- 性别分支验证：男性"武力世家"（力量偏高）与女性"商贾之家"（初始
  `combat_exp` 被 `enter_world()` 直接设成 100，其余出生状况的男性
  角色是 10）两条分支的 `score` 都正常，食物/饮水均正确初始化为满值
  （无 §8.9 类 wrong-object 食物/饮水 bug）。
- 战斗：`kill fatman`（大胖子，福州东路的一个友善摊贩型 NPC）触发的
  一整套攻防交换、"半昏迷"提示、`unconcious()`→`disable_player()` 全
  面封锁指令→`call_out("revive", ...)` 自动苏醒的循环，在持续数分钟
  的连续搏斗（含用管理员 `call me->set("kee",1)` 等指令人为压低生命
  值做压力测试）下没有触发任何崩溃或 `debug.log` 报错；`wimpy` 环境
  变量驱动的自动逃跑（`env/wimpy`）也正常触发过一次。
- 留言板：见上面"已修复"第 3 条，`post`/`look board` 均正常。
- `maximum evaluation cost : 700000`（本项目最常见的默认值）在本次
  移动、注册、战斗全过程中一次也没有触发 `cost limit reached`——不
  需要按 §7.90 上调。

### 死亡/复活流程：仅代码走读，未能在预算内实机触发（诚实标注为未验
证）

`std/char.lpc` 的 `heart_beat()` 只有当 `eff_kee`/`eff_sen`/`eff_gin`
（而不是 `kee`/`sen`/`gin`）跌破 0，或 `kee`/`sen`/`gin` 跌破
`-10*dur` 时才会调用真正的 `die()`；否则只会反复调用
`unconcious()`（见上一节验证过的"半昏迷→自动苏醒"循环）。本次尝试过
两种方式让测试角色真正死亡：

1. 管理员账号 `fluffos` 用 `call` 指令把自己的 `kee`/`gin`/`sen` 直
   接设成 1、并把 `env/wimpy` 设成 0（关闭自动逃跑）后继续和大胖子
   互殴——结果只反复触发 `unconcious()`（因为 `eff_kee` 等派生字段
   没有同步跌破 0），且 `disable_commands()` 在昏迷期间连 `call` 指
   令本身都被封锁，没能在昏迷的间隙里补一刀把 `eff_kee` 也设成负
   数。
2. 另注册的一次性非管理员角色"赵日天"（普通玩家权限）没有 `call`
   指令的路径权限（不在 `PLR_PATH` 搜索范围内），且附近能找到的两个
   可攻击目标（大胖子 combat_exp 5、"卧龙岗强盗" `d/fuzhou/npc/
   gangster.lpc` 未被任何房间引用、是死内容）双方战力都太弱，几分钟
   的持续搏斗里角色和大胖子交替进入又走出"半昏迷"状态，始终没有真
   正累积到 `eff_kee<0` 的门槛。

在预算内没有进一步升级测试（例如去几个路程较远、combat_exp 高得多的
真正杀气 NPC，如 `d/city/npc/bing.lpc`，combat_exp 30000，在长安城城
门一带）。改为**代码走读**死亡序列：`feature/damage.lpc::die()` 把
`userp()` 角色的 `gin`/`kee`/`sen` 都设成 1、`ghost=1`、存档后
`move(DEATH_ROOM)`（`/d/death/gate`，鬼门关），`DEATH_ROOM->start_
death()` 之后由 `d/death/npc/wgargoyle.lpc`（白无常）的 `init()` 排
定 `call_out("death_stage", 5, ...)`，五阶段对话后 `reincarnate()` +
`move()` 到复活地点。**两点值得记录、供下次（尤其是 `sjplii`）复用**：

- `wgargoyle.lpc` 的 `init()` 有 `if (!previous_object() ||
  !userp(previous_object()) || wizardp(previous_object())) return;`
  ——完全跳过 `wizardp()` 为真的对象，即标准种子管理员账号
  `fluffos` 即使真的死了，也**永远不会**被这个 NPC 驱动的复活序列
  接管（这正是 AGENTS.md §10.7 检查清单第 6a 条描述的陷阱）。下次要
  验证死亡/复活全流程，必须用一个非管理员的一次性测试角色，且要给
  它准备足够强的对手（或用 `call` 直接把 `eff_kee`/`eff_sen`/
  `eff_gin` 都设成负数，绕开缓慢的自然搏斗）。
- `death_stage()` 本身带着 AGENTS.md §7.68 已撤回的裸 guard 形状
  （`if (!ob || !present(ob)) return;`，五阶段对话之间没有重试）。
  按 §7.68 的撤回结论，**没有**在代码层面套用那个"改成重试"的旧补
  丁——没有实机确认过"(1) 鬼魂在这个房间里是否真的被禁止自行移动"
  和"(2) 是否存在某个外部系统会强制把鬼魂带离房间"这两个前提，任何
  一个不成立，"5 秒对话中途被打断就永远卡住"就更可能是"鬼魂自己走
  丢，靠重新进入房间的 `init()` 重新触发"这种有意设计，而不是 bug。
  留给下次真正实机跑通死亡序列时再确认。

### 管理员账号播种

`adm/etc/wizlist` 里此前已经有 `fluffos (admin)` 一行，但账号本身
（`data/{login,user}/f/fluffos/`）在这次会话之前从未被真正注册/提
交过。本次走标准注册流程创建（id `fluffos`，密码 `Mud@2026`），登
录后 `目前权限：(admin)` 正确显示，`update /d/fuzhou/npc/chess_
player`、`update /obj/board/wizard_j` 两次写权限验证都成功（§1.5
第 3 步的标准检查）。

## §7.100 sweep (2026-08-19)

Fixed the corpus-wide `inherit ROOM; ... replace_program(ROOM);` redundant-replace bug (AGENTS.md §7.100). 228 live occurrences deleted: 227 via scripted sweep (`fix_710_room.py`), plus 1 hand-fixed roommaker-tool template (`obj/roommaker.lpc`, simple string-builder variant). 23 already-commented-out instances left untouched. No real `.lpc` source found under `work/data/`. Verified via `build-debug` driver boot: clean compile, zero new "cannot replace"/"cannot bind" debug.log lines; confirmed serving via raw-socket connect on port 40134.

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
