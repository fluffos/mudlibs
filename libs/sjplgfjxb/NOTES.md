
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

## AGENTS.md §7.19 sweep (2026-09-01): `enable_player()` reentrancy from `init()`

Same corpus-wide bug class as `mhxy`/`wuhanzhan` (AGENTS.md §7.19): this
lib's `feature/command.lpc` `enable_player()` wrapper (around the raw
`enable_commands()` efun) is reachable from an NPC's `init()` via a
redundant `create()`-then-`init()`-calls-`setup()`/`reset_me()` chain --
confirmed via a body-aware static scan of every `init()` in this lib: 15
NPC files call `setup()`/`reset_me()` from `init()` (e.g. `npc/wu43.lpc`,
`npc/wu33.lpc`, `npc/wu11.lpc`), after `create()` already made the
object `living()`. Calling `enable_commands()` a second time on an
already-`living()` object makes the driver re-invoke that object's own
`init()` as a side effect, re-entering the same chain while the
original call is still on the stack -- genuine reentrancy, crashing
with "Too deep recursion" (most likely on an NPC's first-ever
preload/compile).

`feature/damage.lpc`'s `revive()` calls `enable_player()` again while
the object is still `living()`. (`cmds/std/sleep.lpc`'s `wakeup()` has
its own `me->enable_player();` call commented out/dead in this lib, so
`revive()` alone is the confirmed legitimate re-enable path here.) This
confirms a bare `if (living(this_object())) return;` guard would be the
WRONG fix -- used the same true reentrancy-flag fix as `mhxy` instead: a
`nosave private int in_enable_player_now;` set for the duration of the
wrapper's body, guarding only genuine same-call-stack reentrancy while
leaving the legitimate revive re-enable unaffected. `enable_player()`
had a single fall-through exit (no early `return`s), so one
guard-at-top + one clear-at-bottom pair was sufficient. Verified via a
single-file `lpcc --batch` compile check (PASS) -- not individually
live-boot-tested.

## 深度功能测试（2026-09-03，第三轮）

新角度：2026-08-08 第一轮已经走完注册、战斗、留言板；死亡/复活当时
只做了代码走读。本轮补商店，并顺带实机确认红旗镖局拜师已经写入存档。

- **商店（燕云客栈店小二 / 酒馆酒保）是真 bug，已修**：
  `d/city/npc/waiter.lpc` 的 `vendor_goods` 列了
  `/d/city/obj/food/dishes/dish01`–`dish10`，`jiubao.lpc` 列了
  `dish16`–`dish20`，但这份教学版子集里整个 `d/city/obj/food/dishes/`
  目录从未随档（只有一个无关的 `apple.lpc`）。`feature/vendor.lpc` 的
  `do_vendor_list()` / `buy_object()` 对 `name[i]->name()` /
  `query("id")` 没有守卫，`list` 或 `buy` 一碰到缺失档案就
  `*call_other() couldn't find object '/d/city/obj/food/dishes/dish07'`
  （`vendor.lpc:73` / `:13`），连已经存在的
  `/obj/example/chicken_leg` 等货物也一起买不成。手足 `sjplii` 带着
  完整 `dishes/` 物件，所以那边不会踩这个洞；不要从 `sjplii` 抄菜谱
  进来——那是另一份完整档的内容，不是这份教学版丢掉的源文件。
  修复：删掉两份 NPC 里指向缺失物件的键；`feature/vendor.lpc` 的
  `list`/`buy`/`compelete_trade` 对
  `file_size(path+".lpc")`/`file_size(path+".c")` 都小于 0 的键
  `continue`，一个坏键不能再拖垮整张货表。
- **改后冷启动验证**（端口 40134，`fluffos`/`Mud@2026`，中文名云中鹤）：
  `goto /d/city/kezhan`，`list` 列出椒盐排骨 / 鱼香肉丝 / 烤鸡腿 /
  包子 / 牛皮酒袋 / 油辣猪排；`clone /obj/money/gold` 后
  `buy fried chicken leg from waiter` 成功（「你向店小二买下一根烤鸡
  腿」）。`goto /d/city/jiuguan`，酒保 `list` 列出包子 / 牛皮酒袋 /
  生烧扒翅，无崩溃。
- **拜师已写入存档**：上一轮会话里 `goto /d/city/biaoju/kufang`、
  `bai zhuang`（庄容）成功。本轮冷启动 + 断线重连后 `score` 仍是
  「红旗镖局趟子手」「你的师父是庄容。」`save` 本身第一轮已经确认
  回「档案储存完毕。」，本轮未再踩到影子文件。
- **日志**：live `debug.log` 为 `libs/sjplgfjxb/log/debug.log`（fd
  在 chdir 进 `work/` 之前打开）。本轮无 `call_other() couldn't find
  object`、无 `error:` / `Too deep recursion`。`work/log/log` 只有
  既有的 Unused local variable 编译警告（含 `vendor.lpc` 里预先就
  在的未使用 `list` 变量，不是这次引入的）。`error_handler()` 把
  追踪写回 debug.log，没有另一份独立 runtime-error 日志。
- **结论**：两家商店 `list`/`buy` 通过；红旗镖局拜师跨冷启动仍在；
  修了缺失菜谱键 + vendor 缺档守卫。死亡/复活仍未实机触发。

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 6 line(s) in 3 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— tail() simul_efun

`scripts/lpc_add_tail.py --apply`: `cmds/arch/tail.lpc`, `cmds/wiz/tail.lpc` call `tail(file)`, an efun of the MudOS this archive ran on that FluffOS does not have (`Undefined function tail`: the command did not compile). `adm/simul_efun/file.lpc` now defines `void tail(string file)`: the last 10 lines of the file, written to the player. Load check (HEAD against the working tree): 2 of the 2 tail command file(s) failed to load at HEAD, all load now, and the simul_efun file loads. KB 04 §6.2.

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `std/room.lpc`：`make_inventory()` 用 `catch()` 包住 `new(file)`，做不出来就返回 0；`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-07）— 编译警告整理、错误处理器

`scripts/lpc_warnings.py sjplgfjxb --fix` 加 `scripts/lpc_fix_no_effect.py --apply`，共改动 224 个 `.lpc` 和 1 个 `.h`（多为删去未用的局部变量）。HEAD 与工作树分别加载（新进程）：209 -> 209 通过，无回退；改过的头文件的 29 个包含者 29 -> 29 通过。启动时警告 23 -> 0；新进程登录（新人物确认）正常。

主控对象 `adm/obj/master.lpc` 的 `report_error()` 用 `CHANNEL_D->do_channel(this_object(), ...)` 把运行错误报到频道，但主控对象没有 `query()`，`channeld` 拿不到 `channel_id`，就去取 `capitalize(me->query("id"))`，即 `capitalize(0)` 出错——没有玩家触发的错误（call_out、heart_beat、加载时）都让错误处理器自己再出错（`Error in mudlib error handler: *Bad argument 1 to capitalize()`），频道上收不到错误报告。照 `sj` 的主控对象补上 `query("channel_id")` 返回 "系统核心"。验证：加载一个出错的 NPC，修改前出现 `Error in mudlib error handler`，修改后错误处理器正常跑完。（同 `sjpl2`、`sjplii`。）

记录、未改（档案缺内容）：扬州一带 49 个 NPC 文件引用 `/d/city/obj/cloth/...`、`/d/city/obj/weapon/<类>/...`，这两个子目录档案里没有，其中 jinpao、baojian、bullboots、magua、gangqiang 等十几件在全库都找不到，这些 NPC（项三娘 boss、花钿 girla、彭飞 pengfei 等）在 `create()` 里 `carry_object(...)->wear()` 拿到 0 就加载失败。`feature/dealer.lpc` 用了未定义的 `MONEY_D`，但没有任何文件继承它（无 `F_DEALER`），是死文件。

## 编译警告收尾（2026-10-13）

`scripts/toolkit_fix.sh` 一轮：`d/city/obj/muren.lpc` 多余的 `inherit F_CLEAN_UP` 去掉，`include/net/ftpdsupp.h` 只在分支里用的 `file` 声明挪进分支。能编译的文件警告清零，regress 0。
- 2026-10-14：`data/emoted.o`（表情守护进程的存档）整个还是原档案的 GBK 编码，没有转成 UTF-8，`restore_object()` 报 `Invalid utf8 string while restoring emote`，表情守护进程启动时一个表情都没有。现按 GB18030 转码，丢掉原文件里几个被截断的半个字符。转码后 `adm/daemons/emoted` 载入不再报错（HEAD 上报错）。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

1 个文件（技能、绝招、兵器、书籍、区域 NPC 等）来自侠客行体系（qi/jing/neili），而本库人物是 gin/kee/sen/force：`receive_damage("qi", ...)` 报 `伤害种类错误`，`query("neili")` 永远为 0。按 qi→kee、jing→sen（本库学习/读书指令消耗的就是它）、neili→force、max_neili→max_force、jiali→force_factor 改名（`scripts/lpc_port_es_props.py --any-file`）。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。1 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。

## 暗器功夫身上没有对应暗器（2026-10-15）

`bolt-throw`（玉石棋子） 的 `query_action()` 先 `present("yushi qizi", me)` 取暗器，再直接调用 `qizi->query_amount()`：throwing 映射到这门功夫、手里拿的却是别的暗器（身上没有这种棋子/佛珠）时，每次出招都报 `Bad argument 1 to call_other()`。数量改为 `objectp(qizi) ? (int)qizi->query_amount() : 0`，兵器判断前补 `!objectp(weapon) ||`，没有对应暗器时退回普通招式。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`wave_step`→`wave_steps`（`bagua-steps`、`wave_steps`）；`iceclaw`→`ice_claw`（`ice_claw`）；`leaf_strike`→`leaf-strike`（`leaf-strike`）；`mizongquan`→`mizong-quan`（`mizong-quan`）；`senluo_force`→`senluo-force`（`fanliangyi-dao`）；`zongzi-force`→`tongzi-force`（`weituo_chu`）。

## 移进不存在的巫师房间（2026-10-15，KB 06 §7.251）

用完的物品、要“离开”的 NPC、掷在空中的兵器被移进巫师的工作室（`/u/baiwt/`），本库没有这些房间。本库的 `move()` 用 `call_other(dest, "???")` 载入目的地，找不到文件就报 `call_other() couldn't find object`，后面的语句都不执行：镖局任务的三个 NPC（`d/city/biaoju/npc/daoyike`、`d/city/biaoju/npc/duanxianke`、`d/city/biaoju/npc/zongjiuke`）收下镖货、发完奖励之后报错，没有离开；官府任务的五位大臣（`d/newquest/dachen1`、`d/newquest/dachen2`、`d/newquest/dachen3`、`d/newquest/dachen4`、`d/newquest/dachen5`）派完任务后报错，没有离开（`d/newquest/dachen1`、`d/newquest/dachen2`、`d/newquest/dachen3`、`d/newquest/dachen4`、`d/newquest/dachen5` 本身还载入不了：`create()` 里 `carry_object()` 的物品文件缺失或编译失败，见 KB 06 §7.73，另行处理）；彭飞（`npc/pengfei`，本库没有地方放他）召集武林大会时要先隐身离开，同样报错（`npc/pengfei` 本身还载入不了：`create()` 里 `carry_object()` 的物品文件缺失或编译失败，见 KB 06 §7.73，另行处理）。9 个文件改为移进本库的虚空房间 `VOID_OB`（`/obj/void`），与原作把它们“停放”在巫师房间的用意相同。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

76 个文件、100 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/d/city/obj/cloth/pink_cloth`、`/d/city/obj/cloth/linen`、`/d/city2/obj/jinduan`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 0 个，改后 72 个（72 个原来载入不了），没有退步；其余 4 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## 补回丢掉的基类宏（2026-10-18，KB 04 §6.13）

`inherit F_XXX;` 里的宏本库任何头文件都没有定义，报 `syntax error, unexpected L_IDENTIFIER, expecting L_STRING or '('`，整个对象载入不了；宏指向的基类文件本库其实有，别的库都把这个宏定义成同一个路径。在全局头文件 `include/globals.h` 里补上：`F_UNIQUE` → `/feature/unique`（2 个文件）。（`scripts/lpc_restore_macros.py`）改后用 `lpcc` 逐个载入这些对象：2 个里 0 个通过，其余 2 个还有别的错误（`d/obj/mace/femalemace.lpc`：syntax error, unexpected L_IDENTIFIER, expecting L_STRING or '('；`d/obj/mace/malemace.lpc`：syntax error, unexpected L_IDENTIFIER, expecting L_STRING or '('）。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 7 个对象设了本库没有文件的武功（14 个名字，最多的是 `hunyuan-yiqi`、`bibo-shengong`、`anying-fuxiang`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：7 个里 6 个通过，其余 1 个停在别的错误上（`d/npc/killer-n`：*No program in object '/d/npc/killer-n'!）。（`scripts/lpc_guard_set_skill.py`）

## 补回本库没有的基类文件（2026-10-18，KB 04 §6.15）

下面这些基类本库没有，继承它们的对象（房间、NPC、物品）整批载入不了（`inherit XXX;` 的宏没定义，或者 `inherit "/std/…";` 的文件不在）。同系的库里有同名文件，两库有大量逐字节相同的文件（亲缘关系），所以从那边原样拷来，缺的宏补进全局头文件 `include/globals.h`：`/std/weapon/mace`（宏 `MACE`）←dtsl，10 个对象继承它，抽样 10/10 载入；`/std/weapon/rake`（宏 `RAKE`）←dtsl，1 个对象继承它，抽样 1/1 载入；`/std/weapon/archery`（宏 `ARCHERY`）←dtsl，1 个对象继承它，抽样 1/1 载入。每个基类补回后单独载入、再抽样载入使用它的对象，基类载不进来或者一个用户也载不进来的就撤掉（本库撤掉了它们，不再补）。（`scripts/lpc_restore_bases.py`）

## 武功基类缺少 NewRandom()（2026-10-19，KB 06 §7.261）

基本武功（`boxing`、`houquan`、`westsword`、`taiji-quan` 等）用 `action[NewRandom(i, 20, level/5)]` 挑招式；`NewRandom()` 和它调用的 `sum()` 在别的库的武功基类里有，本库的 `/std/skill.lpc` 是更精简的版本，没有，于是这些武功全都报 `Undefined function NewRandom` 编译不过，有这门武功的人物只能空手。把这一对函数（115 个库共用的同一份文字）补进武功基类，受益武功 2 个：`/daemon/skill/hou_ken.lpc`、`/daemon/skill/weituo-chu.lpc`。（`scripts/lpc_restore_skill_helpers.py`）

## 技能基类丢了“预备武功”那一段（2026-10-19，KB 06 §7.262）

`feature/skill.lpc` 有 `skill_map`/`map_skill()`，却没有预备武功（`prepare_skill`）这一块：变量 `skill_prepare`、`prepare_skill()`、`query_skill_prepared()`、`query_skill_prepare()`。来自 xkx 系列的 NPC 在 `create()` 里调用 `prepare_skill("cuff", ...)`，于是 `Undefined function prepare_skill` 整个 NPC 载入不了。从同系的 xkx100 把这一块原样补回（声明加在 `skill_map` 后面，函数加在文件末尾），受益 NPC 1 个：`d/npc/killer-n`。（`scripts/lpc_transplant_function.py`）

## 全局头文件丢了 3 个宏（2026-10-19，KB 04 §6.16）

`/include/globals.h` 里没有定义 `RICH_B`、`PKER_B`、`EXP_B`，用到它们的物件（名单里 1 个）编译时报 `Undefined variable`/`Undefined function`，整个物件载入不了（编译器在第一个未定义的名字上停下，后面的错误和警告都看不到）。同系的库在各自的头文件里都有这几行：照其中和本库共有文件最多的那个库，原样补到 `/include/globals.h` 最后一个 `#define` 之后，宏体里出现的路径在本库里都存在。补完后名单里有 1 个载入，其余还差别的东西。（`scripts/lpc_restore_defines.py`）

## 出口指向不存在的房间（2026-10-19，KB 06 §7.257）

下列房间的出口写的文件不存在，而对面恰好只有一个房间的出口指回本房间，所以按对面的房间改正（笔误、大小写、路径少了一级）：

- `/d/city/qinglong-n3.lpc` 的 `west` 出口：`jiyuan/dating` → `jiyuan`
- `/d/city/zhongguan2.lpc` 的 `north` 出口：`zhongguan` → `zhongguan_old`

改后房间照常载入（与 HEAD 逐个对比，没有退步），出口现在指向存在的房间。

## 区域物件的零碎修正（2026-10-19，KB 06 §7.267–§7.271）

- 补上 `adm/daemons/moneyd.lpc`（取自带同一份 `feature/dealer.lpc` 的 jqxz2008）和 `include/globals.h` 的 `MONEY_D`：`feature/dealer.lpc` 之前编不过，所有继承 `F_DEALER` 的店主都载入不了

逐个物件与 HEAD 对比载入，没有退步。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 补回本库没有的基类文件，第二轮（2026-10-19，KB 04 §6.15、§6.18）

宏有定义、基类文件却不在档案里：继承它的对象载入时报 `Inherited file '…' does not exist!`，编译扫描看不到这一类（`scripts/lpc_missing_inherits.py` 能列出）。同系的库里有同一个文件，原样拷来（`scripts/lpc_restore_bases.py`）；基类和继承它的对象 include 而本库没有的头文件一起带来。每个基类补回后单独载入，再载入使用它的对象，载不进来、或一个用户也载不进来的撤掉了。

- `/inherit/weapon/bow`（宏 `BOW`）←sjplii：1/1 个继承它的对象载入
- `/inherit/weapon/weapon`（宏 `M_WEAPON`）←sjplii：5/5 个继承它的对象载入
- 玩家打造兵器的模板（5 个文件）这回有了基类，照 KB 06 §7.275 加上没有打造者时的保护（`scripts/lpc_fix_forge_template.py`）。

逐个与 HEAD 对比载入，没有退步。

## `call_out_info()` 的每一项只有 3 个元素（2026-10-20，KB 06 §7.287）

驱动返回的是 `({ 物件, 函数, 延迟 })`，不带 call_out 的参数，旧代码读第 4 项 `info[i][3]`（`callouts` 指令、`calloutd`、`cod` 工具）一读就报 `Array index out of bounds`，指令从第一行起什么也打印不出来。改为 `(sizeof(info[i]) > 3 ? info[i][3] : 0)`（`scripts/lpc_fix_callout_info.py`）。改动：`/cmds/arch/callouts.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 5 处）。改动：`/d/city/puke-room.lpc`（4 处）、`/d/fuzhou/npc/mei_po.lpc`（1 处）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/obj/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## sefun `cat()`：缺文件时 `write(0)` 报错（2026-10-20，KB 06 §7.297）

`void cat(string file) { write(read_file(file)); }`：文件不存在（压缩包没带的欢迎/公告文件，或只有运行中的 mud 才会写的日志）时 `read_file()` 回 0，`write(0)` 在本驱动里报 `Bad argument 1 to receive()`，调用者（登录对话、`cat` 指令）被中断；老驱动什么也不打印。改成 `write(read_file(file) || "");`（`scripts/lpc_fix_cat_unchecked.py`）。改动：`/adm/simul_efun/file.lpc`。

## 翻页器 `start_more(read_file(...))`：文件缺失时 `explode(0)`（2026-10-20，KB 06 §7.300）

东方故事系的翻页器 `void start_more(string msg) { ... explode(msg, "\n") ... }` 被这样调用：`start_more(read_file(HELP_DIR + "help/topics"))`、`start_more(read_file(NEWS))`。压缩包没带的文件使 `read_file()` 回 0，`explode(0, ...)` 在本驱动里报 `Bad argument 1 to explode()`（不带参数的 `help` 指令就是这样出错的），老驱动把 0 当空文本。在 `start_more` 开头加了 `if (!stringp(msg)) return;`（`scripts/lpc_fix_start_more.py`）。改动：`/feature/more.lpc`。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库现有的 NPC 文件里没有字面写成空 `chat_msg` 的（扫描只认 `set("chat_msg", ({ }))`）；守卫挡的是运行时才为空的列表和以后新增的 NPC。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/cmds/std/char/npc.lpc`、`/feature/newvendor.lpc`、`/std/char/new_npc.lpc`、`/std/char/newvendor.lpc`、`/std/char/npc.lpc`、`/std/char/vendor.lpc`（共 6 个文件）。

## 巫师命令不带参数时对 0 调用 efun（2026-10-21，KB 06 §7.336）

巫师（管理员）把命令敲成不带参数时，驱动把 0 传给字符串参数；下面的命令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`，这条指令从来没有用过。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py` 在第一处使用参数的语句前加守卫：文件自带 `int help(object me)` 的，守卫是 `if (!arg) return help(me);`（`help()` 定义在 `main()` 之后的 1 个文件补了原型 `int help(object me);`，否则编译报 `Undefined function help`）。改动（1 个文件，括号里是接住 0 的 efun）：`/cmds/wiz/test_attack.lpc`（`present`）。加载检查 HEAD 与工作树对照，没有退步。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 12 条注册（4 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/d/city/famous.lpc`（`do_bian`、`do_upadm`、`do_upboot`、`do_uplock`）、`/d/city/piggy.lpc`（`do_bian`）、`/d/city/qiyuan.lpc`（`do_pass`、`do_resign`）、`/std/qitem.lpc`（`do_cures`、`do_defend`、`do_lookfor`、`do_sing`等）。最多的函数名：`do_bian` 2 处、`do_upadm` 1 处、`do_upboot` 1 处、`do_uplock` 1 处、`do_pass` 1 处。

## 调用了、但这个库自己的守护进程里没有的函数（2026-10-22，KB 06 §7.354）

`MACRO->函数()` 调用的函数在这个库的守护进程里不存在：`call_other()` 对不存在的函数不报错、只返回 0，所以这些功能（时间显示、昼夜事件、名字检查、价格文字……）一直没起作用。同一血统另一个库的同名守护进程里有这些函数，原文照抄到本库守护进程末尾（`scripts/lpc_port_function.py`；调用处传的参数个数、函数体用到的函数 / 全局变量 / 宏 / 字符串键都在本库里有，已核对；守护进程在 HEAD 和工作区都能加载，每个函数用固定参数各调用一次：HEAD 返回 0，现在返回正常的值）：`/adm/daemons/chinesed.lpc` ← fengyun434：`check_control()`（1 处调用）、`check_length()`（5 处调用）、`check_return()`（1 处调用）、`check_space()`（1 处调用）、`check_chinese()`（1 处调用）。

## 运行期目录 `log/nosave` 不存在，写日志的 `write_file()` 直接报错（2026-10-22，KB 03 §4.3 补充）

这个库的 10 个文件里有 13 处 `write_file("/log/nosave/...")` / `log_file("nosave/...")`（`static` 改 `nosave` 时连字符串里的日志路径一起改了，原来是 `log/static/`）：`nosave/CALL_PLAYER`、`nosave/promotion`、`nosave/CRASHES` 等。压缩包和站点包里没有这个目录，`write_file()` 在目录不存在时抛 `*Wrong permissions for opening file /log/nosave/... for append. "No such file or directory"`，调用它的函数（杀人记录、重启记录、`call` 日志……）当场中断。把 `log/nosave` 记进 `scripts/wasm_keep_dirs.txt`（站点和 pristine 树都按它建空目录）；没有把字符串改回 `static`。证明（`scripts/lpcc_eval.py`，`catch(write_file("/log/nosave/ZZTEST", ...))`，fqyy2 / hy5 / bmxkx2001 的新进程）：补目录前报上面的错误，补后写成功。

## 长度检查按字节写，旁边的提示按汉字写：6 处（2026-10-22，KB 06 §7.362）

老档的 `strlen()` 数字节（一个汉字 2 字节），转成 UTF-8 后它数字符：提示写「必须是 2 到 6 个中文字」的检查还是 `strlen(name) < 4 || strlen(name) > 12`，于是两三个字的房名、帮会名、群名、聊天室名、称号被提示自己说允许的那句话拒绝，上限却是提示的两倍；留言板的标题检查 `i < 4 || i > 24 || i % 2` 还会拒绝所有奇数个字的标题（`post 你好吗`）。本库 6 处（3 个文件）：`if ((strlen(name) < 2) || (strlen(name) > 12)) {`（`/adm/daemons/logind.lpc:623`）；`if ((strlen(name) < 2) || (strlen(name) > 40)) {`（`/d/city/npc/caifeng.lpc:135`）。`scripts/lpc_fix_strlen_gate.py` 以提示为准：条件里每个 `strlen` 门槛都恰是提示所说数字的两倍才折半，存长度的变量（`i = strlen(arg);`）的门槛和 `|| i % 2` 奇偶项、其后循环的 `i % 2 == 0 &&` 一并处理；提示里有英文 / 字母 / 字节的不动。证明（`scripts/lpcc_eval.py`，bxsj 的留言板，求值对象继承 NPC 并重写 `edit()` 记录调用，`command("post 标题")`）：HEAD 拒绝「你好」和「你好吗」、放行 23 个字的标题；改后接受前两个、拒绝第三个；shenmo 的 `named.lpc invalid_new_name("张三")`：HEAD 回 `名字只能是2-4个中文字。`，改后回 0。抽样 24 + 15 个库的 HEAD / 工作树加载对比 0 退步。

## 按字节写的汉字循环、茶馆猜诗和同盟频道标题（2026-10-23，KB 06 §7.363）

老档按字节做「一个汉字」：`while (i--) if (i % 2 == 0 && !is_chinese(name[i..<0]))` 只检查偶数下标，奇数位上的拉丁字母（`张a`）会过；茶馆猜诗 `mixup()` 用 `strlen(str)/2` 再 `j=j+j`、`str[k..k+1]` 交换两字节；泥潭系 `channeld` 的 `switch (strlen(fname)) case 4/6/8/10` 和 `strlen(family)==4/6` 按字节长度给同盟 / 门派名加空格。本驱动的 `strlen()` 和区间都按字符算。`scripts/lpc_fix_byte_char.py`：去掉奇偶项、把区间改成 `name[i..i]`，按字符重写 `mixup()` 并把 `strlen(first)>=14` 折成 7，频道标题的 case / 门派长度改成字符数（对照 aoxiangtianji）。本库 汉字循环 / `is_chinese` 区间 5 个文件；茶馆猜诗 `mixup` 1 个文件。证明（`scripts/lpcc_eval.py`）：sjplii 的 `check_legal_name` 在 HEAD 接受「张a」、改后拒绝，两边都接受「张三」；xkx100 的 `clubpoem->mixup("离离原上草")` 得到「离离原草上」（真交换汉字）；nitan_san 两字同盟名得到 `【 兄  弟 】`。关键对象加载通过。

## 血条 / 表情标题按字节算显示宽度（2026-10-23，KB 06 §7.365）

老档把汉字当两字节：`bar_string[0..(val * N / max) * 2 - 1]` 把「格数」换成字节下标，半格血条在本驱动（按字符算区间）上会整条画满；巫师表情 `edemote` 的 `repeat_string("─", 13 - (strlen(emotion) / 2))` 也会少减汉字宽度。`scripts/lpc_fix_display_pad.py`：去掉 CJK 血条 / 空白条上的 `* 2`（`jings`/`qis` 赋值和 `blank_string3[0..(23-a)]` 的 23→11 一并改），表情标题去掉 `/ 2`；ASCII 空格的 `none_string` / `empty_string` 仍保留 `* 2`（一格两个空格）。本库 2 处（1 个文件）。证明（`lpcc_eval.py` hhsj）：`tribar_graph(6,9,12)` 在 HEAD 画出整条 12 个■，改后为 6 个■+3 个□；麻将 `strlen(tempB)/2` 是两字符牌码，未改。


## 深度功能测试（2026-10-27，§6.25 tell_object/tell_room 字符串目标）

bingbu：`tell_object("ob")`→`tell_room(ob)`；`tell_room("where")`→`tell_room(where)`。

