
## 深度功能测试（第二轮，2026-08-03）

之前的会话只测过注册流程，本轮做了完整的 §10.7 深度功能测试。
proactive 检查 AGENTS.md 已归档的四类常见坏味道：`feature/
command.lpc`（以及一份 `edit/` 目录下的镜像副本，核实不是生效路
径）里的"private nomask command_hook"只是历史注释保留的旧代码痕
迹（`// private nomask int command_hook(...)`），真正生效的声明
早已是干净的 `nomask int command_hook(...)`；命中了一处 `adm/
daemons/logind.lpc` 里的 printf("%O") 调试残留（新增 `yszz` 到
AGENTS.md §7.34 确认实例列表）；未命中 unguarded MESSAGE_D->、
stat/water 键名、§8.9 坏 age 判断。

**完整流程验证**：注册全新角色（沐妖神/id `yszzdive`），从"南城
客栈"起步，`hp` 确认食物/饮水/气血/精神槽均满值；向"疥顶小僧"
（这批西游记题材姊妹档案里反复出现的同一个高战力 NPC，
combat_exp 50000）发起战斗——完整交手数回合后被击昏迷致死（"你
死了"），送往"阴阳界"由"朱笔判官 崔珏"接引，明确提示"你莫乱跑，
画了生死簿，我好送你还阳"（和 `bmxkx2001` 那次发现的"鬼魂在复活
过程中被强制移动会永久卡死"是同一类设计警示，但本次静候没有被
任何其它系统打断，正常复活成功，`score` 数据完整）；`quit` 干净
退出。全程 debug.log 零报错。

**未覆盖范围**：拜师（五庄观/月宫/龙宫/普陀/方寸山/无底洞/轩辕古
墓/水帘洞/大雪山/地府共十个门派可选）、西行取经任务线、留言板因
时间原因未实测。

## 深度功能测试补测：拜师／西行取经／留言板（2026-08-24）

补测第二轮 NOTES 标记的三处未覆盖范围。

**留言板**：南城客栈留言板 `post <标题>` 进入内建编辑器，输入正文
以单独一行 `.` 结束，`留言完毕`；`look board` 正确显示新留言，作
者本人 `discard <编号>` 成功删除。round-trip 干净，无 debug.log 报
错。（测试中途一次通过 `scripts/tmux_mud.sh multi` 发送多行编辑器
正文时，`。` 结尾的中文句子在 telnet 层被截断、误触发本地
telnet 客户端的 `Ctrl-]` 转义——这是已知的 tmux/telnet 多字节透传
假警报，不是驱动或代码问题；改用一次性发送的原始 Python socket
脚本后单行/多行中文输入都稳定无误。同样的假警报又在 `ask yin
about 陈光蕊` 上重现了一次（`光` 被替换成 `�`），换用 raw socket
脚本发送同一条命令后文字完全正确，NPC 对话也正常，确认属于同一传
输假警报，不是取经任务线代码的问题。）

**拜师（选测月宫，嫦娥）**：新角色（女性，容貌 30）`goto`/`summon`
传送至嫦娥所在的"长思馆"，`apprentice change` 一次性走完全套流程
（嫦娥的 `attempt_apprentice` 检查性别+容貌门槛通过后自动
`recruit`），`score` 的"师傅"字段正确从"鬼才知道"变为"嫦娥"，并
获得师门长剑。十个门派共用同一套 `feature/apprentice.lpc` /
`cmds/std/{apprentice,recruit}.lpc` 机制，本次仅实测月宫一支，但
逻辑路径对全部门派通用。

**发现并修复一个真实的 programming bug**（非平衡性/内容问题）：
`cmds/std/apprentice.lpc` 里"对方已经用 recruit 表态愿意收我为徒"
分支（`ob->query_temp("pending/recruit") == me` 时），判断是否为
"背叛师门投入新门派"时直接比较
`me->query("family/family_name") != ob->query("family/family_name")`，
没有先判断 `me`（申请人）本来就有没有 `family`——对于第一次拜师、
从未加入过任何门派的角色，`me->query("family/family_name")` 恒为
0，永远不等于新师父的门派名，导致每一次「正常首次拜师」都被误判
成「背叛师门投入别人门下」，弹出错误的台词且把 `score` 清零。姊
妹指令 `cmds/std/recruit.lpc` 里对称的分支（`me->recruit_apprentice`
一侧）正确地先用 `(ob->query("family")) && (...)` 守卫，
`apprentice.lpc` 漏掉了同样的守卫，help 文本本身也写明"你已经有
了师父，又背叛师门投入别人门下"才会触发这个惩罚——代码与文档意
图不符。加了同样的 `me->query("family") &&` 守卫修复。

**修复前后均现场复现验证**：造出两名全新无门派角色，让已拜入月宫
的 `yszzcy` 先用 `recruit <目标>` 主动收徒（模拟玩家师父主动招募
从未拜师的新人这一常见场景），目标再用 `apprentice yszzcy` 确
认——修复前，回应是错误的"你决定投入云裳仙门下！！"（背叛台词）；
`update /cmds/std/apprentice` 热更新代码后，同样操作对第二个全新
角色正确显示"你决定拜云裳仙为师。"（正常拜师台词）。两次全程
debug.log 零报错，确认是纯逻辑 bug，不是编译/崩溃类问题，但确有
实际错误行为（错误台词+错误清零 score）。

**西行取经任务线**：`doc/help/newqujing` 里有完整的攻略文档，全线
共 36 "关"（`obstacle/number`），score 里"任务行动篇"栏正确显示
"你尚未踏上西行大道"（`obstacle/number == 0`）。实测了第一关"江
州／金山寺"的头两步：`goto /d/jz/fzroom` 找法明长老 `ask faming
about 血书` 正确给出反应并交出信物；`goto /d/jz/in` 找殷温娇 `ask
yin about 陈光蕊` 正确触发她的伤心台词。两步均无崩溃、无
debug.log 报错。后续关卡（双叉岭杀虎、`nianjing` 念经、流沙河跳
水等）因深度游玩成本高（帮助文档标注全线需要上千年道行/极高战力
才能推进到后期关卡）未继续深入，但已验证任务线的入口和早期节点
是可达、可交互、无编程错误的。

测试用角色（`yszzcy`/`yszztsb`/`yszztsc`）及其存档已清理；南城客
栈留言板测试留言已通过 `discard` 删除。

## WASM 修复摘要（迁移自 meta.json 的 group_note）

WASM 修复：修好了 §8.1 GBK 字节区间 is_chinese()/check_legal_name() bug（这个驱动下 str[i] 是一个码点，不是一个 GBK 字节——真实的中文名字会被静默拒绝）；给 band.lpc 的 is_banned()/create_char_banned() 打上了本地回环放行补丁；通过 adm/etc/wizlist 把 fluffos/Mud@2026 播种为 (admin)。在 WASM 下用一个真实的中文名字（秦风）完整验证了注册+look/score/quit，管理员账号的 update 指令也验证可用。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BBS_BOARD`、`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 38 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## §7.100 sweep (2026-08-19)

Fixed the corpus-wide `inherit ROOM; ... replace_program(ROOM);` redundant-replace bug (AGENTS.md §7.100). 305 live occurrences deleted: 303 via scripted sweep (`fix_710_room.py`), plus 2 hand-fixed roommaker-tool templates (`clone/misc/roommaker.lpc`, `obj/roommaker.lpc` — both simple string-builder variant). 7 already-commented-out instances left untouched. No real `.lpc` source found under `work/data/`. Verified via `build-debug` driver boot: clean compile, port 40192 listening, zero new "cannot replace"/"cannot bind" debug.log lines. Pre-existing untracked test-account debris (`data/{login,user}/y/yszzdive.o`) confirmed left untouched by `git status` review before staging.

### ```§7.112``` residual-gap closure (2026-08-20)

Corpus re-scan (`grep -rl 'call_out("death_stage"' ... | filter for missing guard`) found unguarded `init()`-scheduled `death_stage()` call_out chain(s) in `d/death/npc/wgargoyle.lpc` that the original two-wave sweep (see AGENTS.md §7.112) missed -- same reconnect-triggered duplicate-chain bug, different filename/lineage. Added the standard `query_temp("death_stage_active")`/`set_temp`/`delete_temp` re-entry guard, adapted per file's own exit points. Compile-verified via `lpcc --batch`.

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

## AGENTS.md §7.19 sweep (2026-09-01): `enable_player()` reentrancy from `init()`

Same corpus-wide bug class as `mhxy`/`wuhanzhan` (AGENTS.md §7.19): this
lib's `feature/command.lpc` `enable_player()` wrapper (around the raw
`enable_commands()` efun) is reachable from an NPC's `init()` via a
redundant `create()`-then-`init()`-calls-`setup()` (or `reset_me()`
calling `setup()`) chain -- confirmed live via a static scan of every
`init()` body in this lib: 48 NPC/item files call `setup()` directly
or via `reset_me()` from `init()`, after `create()` already called
`setup()` once (which already made the object `living()`). Calling
`enable_commands()` a second time on an already-`living()` object makes
the driver re-invoke that object's own `init()` as a side effect, which
re-enters this same chain while the original call is still on the
stack -- genuine reentrancy, crashing with "Too deep recursion" (most
likely to surface on an NPC's first-ever preload/compile).

`feature/damage.lpc`'s `revive()` and `cmds/std/sleep.lpc`'s `wakeup1()`/`wakeup2()` call `enable_player()` again while the object is still `living()`. This confirms a bare `if (living(this_object())) return;`
guard would be the WRONG fix (it would silently break that legitimate
re-enable) -- used the same true reentrancy-flag fix as `mhxy` instead:
a `nosave private int in_enable_player_now;` set for the duration of the
wrapper's body, guarding only genuine same-call-stack reentrancy while
leaving every legitimate re-enable (revive/wakeup/disguise) unaffected.
`feature/command.lpc`'s `enable_player()` had a single fall-through exit
(no early `return`s), so one guard-at-top + one clear-at-bottom pair was
sufficient. Verified via a single-file `lpcc --batch` compile check
(PASS) -- not individually live-boot-tested.

## 深度功能测试（2026-09-04，shop）

Live native pass on port **40192**. 2026-08-24 already did 月宫嫦娥拜师;
this slice is shop-only. First send is **`gb`** (banner “Select GB or
BIG5 (gb/big5)”), then id `fluffos` / `Mud@2026` (`(admin)`, lands in
巫师会议厅). `clone /obj/money/gold` works.

南城客栈 店小二 (`u/city/npc/xiaoer.lpc`, `F_VENDOR_SALE`) `list`
already showed 炸鸡腿 80文 (`vendor_sale.lpc` `#include <dbase.h>`).
Bare `buy jitui` did **not**: `cmds/std/buy.lpc` auto-picks
`is_vendor()` in the room, but `F_VENDOR_SALE` never defined it (only
`feature/vendor.lpc` did). Help text requires `buy <item> from
<someone>`; without `is_vendor()` the short form always printed the
usage line. Added `int is_vendor() { return 1; }` (CRLF preserved).
After reboot, `buy jitui` purchased 炸鸡腿 and changed 1 黄金 into 99
两银子 + 20 文. No 丐帮 refuse (this vendor has none).

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 2 here-document block(s) repaired (2 with the terminator glued to the last text line, 0 with it indented), so `End of file in text block` no longer hides the room or object behind them: `d/moon/bedroom.lpc`, `u/cici/cici/yi.lpc`. The terminator must start its line (the lexer's own test, KB 04 §6.10); a glued one lost its newline in the GBK -> UTF-8 conversion together with a half character, which stays out.

## 深度功能测试（§10.7，2026-10-05）— tail() simul_efun

`scripts/lpc_add_tail.py --apply`: `cmds/wiz/tail.lpc` calls `tail(file)`, an efun of the MudOS this archive ran on that FluffOS does not have (`Undefined function tail`: the command did not compile). `adm/simul_efun/file.lpc` now defines `void tail(string file)`: the last 10 lines of the file, written to the player. Load check (HEAD against the working tree): 1 of the 1 tail command file(s) failed to load at HEAD, all load now, and the simul_efun file loads. KB 04 §6.2.

## 深度功能测试（§10.7，2026-10-05）— 任务表里的 `.c` 路径与任务守护进程的防护

`scripts/lpc_dynamic_rows.py`：`d/obj/quest/dynamic_location`、`d/obj/quest/dynamic_quest` 里 250 行写的是原档案的 `.c` 路径。转档时文件已改名 `.lpc`，而显式后缀按原样解析，`load_object("/d/x.c")`、`new("/d/obj/quest/x.c")` 返回 0 且不报错（KB 03 §4.2，KB 06 §7.220），所以 `adm/daemons/questd.lpc` 读到的每一行都加载不出来：随机任务和任务物品从未生成，在 `create()` 里直接对结果调用 `tar->set()` 的版本还会崩溃，连带加载它的 cron 守护进程和 `give` 的任务钩子。这些行已改为 `.lpc`；另有 1 行指向的文件两种后缀都不存在（档案缺内容），保持原样。
`scripts/lpc_dynamic_quest_guard.py`：1 处 `spread_quest()` 调用（`init_dynamic_quest()` 的循环里）包进 `catch()`，缺失的任务物品或编译不过的房间只跳过那一个任务，守护进程照常加载、其余任务照常生成。
验证：`adm/daemons/questd.lpc`和 cron 守护进程在新进程里加载（HEAD 一次，工作树三次，选房是随机的）：HEAD 通过 2 个，工作树三次分别通过 2、2、2 个（共 2 个），无回退。

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `std/room.lpc`：`make_inventory()` 用 `catch()` 包住 `new(file)`，做不出来就返回 0；`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK；全库 7364 个对象 HEAD 对工作树的加载检查：7271 -> 7276，新增 5 个可加载，无回退。

## 深度功能测试（§10.7，2026-10-07）— 兵器的 `actions` 函数指针

`set("actions", (: WEAPON_D, "query_action" :));`：旧 MudOS 把 `(: 字符串, "函数" :)` 当作 call_other 函数指针，本驱动把它当作表达式函数指针，求值只得到字符串 `"query_action"`。没有对应兵器技能时 `feature/attack.lpc` 直接用兵器的 `actions`，`COMBAT_D` 拿到的不是 mapping，`reset_action()` 后仍不是，记一条 bad action 就不出招——拿着这些兵器打不出攻击。改成别的兵器早已用的 `(: call_other, WEAPON_D, "query_action" :)`（KB 04 §6.10）：`std/weapon/club.lpc`、`d/obj/inherit/weapon/throwing.lpc`、`d/obj/inherit/weapon/fork.lpc`、`d/obj/inherit/weapon/whip.lpc`、`d/obj/inherit/weapon/sword.lpc`、`d/obj/inherit/weapon/axe.lpc`、等共 10 个。改动的文件在 HEAD 与工作树分别加载（新进程），无回退。

## 深度功能测试（§10.7，2026-10-07）— 编译警告整理

`scripts/lpc_warnings.py yszz --fix` 加 `scripts/lpc_fix_no_effect.py --apply`（四份 `xuanyuan-archery`/`xuanyuan-arrow` 删去什么也不做的 `(: throw_weapon :);`）：共改动 677 个 `.lpc` 和若干 `.h`。兵器基类的 `(: WEAPON_D, "query_action" :)` 已在同日的兵器函数指针一节修过。HEAD 与工作树分别加载（新进程）：651 -> 651 通过，无回退；改过的头文件的 272 个包含者 271 -> 271 通过。
手工：`adm/daemons/logind.lpc` `get_id()` 里只在 `#ifdef MAX_LOGIN` 分支用的七个局部变量（同 IP 多重登录的计数），声明挪进同样的条件里。

启动时警告 93 -> 0；新进程登录正常（新人物用 `new`）。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 18 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 6 个，只在 #if 分支用的声明移进分支 2 个文件；改动 23 个文件，HEAD 与工作树各载入一次无回退（23 objects; HEAD PASS 23, tree PASS 23; regress 0; newly loading 0），这些文件的警告 52 -> 18。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查

- **安全**：`obj/login.lpc`（及 `edit/obj/login.lpc`）`set()`：`if (prop == "freeze_time"); return ::set(prop, data);` 多了分号，return 无条件执行，下面的 `geteuid(previous_object()) != ROOT_UID` 检查永远到不了——任何对象都能改玩家连接对象的任意属性（密码、权限等）。去掉分号。全库只有本库两份是这个写法。
- `u/fly/npc/greeting.h` 转码时漏了，仍是 GBK：字符串里的 GBK 尾字节打乱了词法，警告报在 `xuerengui.lpc` 第 66 行。按 GB18030 转成 UTF-8（全库 .lpc/.h 严格 UTF-8 检查另行进行）。
- 改动的对象载入无回退，`xuerengui` 新增可载入。

## 编译警告收尾（2026-10-13）

`scripts/toolkit_fix.sh` 一轮去掉 13 处多余继承，其余照同族改法手工，能编译的文件警告清零；改动的 36 个对象在 HEAD 与工作树各载入一次：HEAD PASS 34，tree PASS 34，regress 0。

- 袈裟 `d/obj/cloth/jiasha.lpc` 与宝甲 `obj/baojia.lpc` 都是 `CLOTH` + `F_UNIQUE`，各只跑一边的 `init()`（袈裟的撕袈裟 `tear` 从没加上，宝甲的唯一物品检查从不运行）；两者都补 `init() { cloth::init(); unique::init(); }`。
- `d/kaifeng/ground.h` 表格守卫（同 xyj2000）；`include/net/ftpdconf.h` 的 `VALID_READ`、`VALID_WRITE` 与 `feature/quest.lpc` 的 `QUEST_D` 先 `#undef`；巫师 fly 的 `u/fly/job/npc/skill.h` 的武功表 `skills` 与 `F_SKILL` 同名，改名 `job_skills`（`killer.lpc` 一处），`u/fly/other/xyj2000_job/npc/yg/yaoguai.lpc` 没人读的 `yaoguai_type` 删去。
- 玉兔两份（`d/moon/npc/yutu.lpc`、`edit/d/moon/npc/yutu.lpc`）的 `kill_ob()`、劫匪两份 `jiefei.lpc` 的 `unconcious()` 改 `void`；`d/death/god1.lpc`、`d/obj/weapon/sword/di.lpc`、`d/qujing/jilei/obj/fzy.lpc`、`daemon/skill/test-whip.lpc` 写明用驱动原先选的 `clean_up()`；四处多余的 `;` 删去。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。1 个文件 1 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）；`x op= 浮点` 先把浮点转成整数再运算（系数小于 1 时 x 直接变 0），改为 `x = to_int(x op ...)`：`/u/fly/skill/zhen.lpc`（`damage *=`）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。
- 2026-10-14：技能文件 `int power_point()`/`hard_point()`/`effective_level()` 返回 1.2~2.5 之类的浮点，经 int 返回被截断；本库没有（有效的）调用者，改成 `float`，保留原数值。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。1 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

11 个文件（技能、绝招、兵器、书籍、区域 NPC 等）来自侠客行体系（qi/jing/neili），而本库人物是 gin/kee/sen/force：`receive_damage("qi", ...)` 报 `伤害种类错误`，`query("neili")` 永远为 0。按 qi→kee、jing→sen（本库学习/读书指令消耗的就是它）、neili→force、max_neili→max_force、jiali→force_factor 改名（`scripts/lpc_port_es_props.py --any-file`）。

## 治疗/疗伤的属性名（2026-10-15，KB 06 §7.241）

`receive_heal()`/`receive_curing()` 也只接受本库的种类。4 个文件（多为只调用 `receive_heal`/`receive_curing` 的药物、NPC）来自侠客行体系，按 qi→kee、jing→本库学习指令消耗的池、neili→force 改名（`scripts/lpc_port_es_props.py --any-file`）。


## 转码吃掉的引号（2026-10-15，KB 03）

原档在右引号前有一个孤立的 GBK 前导字节，转 UTF-8 时连引号一起丢了（如 `return name + HIM "发作身亡了;`），字符串一直延续到后面，文件编译失败：`/d/obj/books-nonskill/hmeng014`。补回引号（`scripts/lpc_fix_eaten_quote.py`）。

## 技能按另一门武功的等级取招（2026-10-15，KB 06 §7.243）

这些技能文件是从别的武功复制改名来的，`query_action()` 仍用原武功的等级查招式表：只会本技能的人等级为 0，取不到招，每次出招都报错。改为读本技能自己的等级（`scripts/lpc_fix_action_level.py`）：`qianye-shou`。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`jinwu-dao`→`jinwu-daofa`（`jinwu-daofa`）；`yan-fly`→`yanfly`（`yanfly`）；`yijin-jing`→`yijinjing`（`/d/kaifeng/taishan/shijin`）。

## family 映射内联取下标（2026-10-15，KB 05 §7.30）

`ob->query("family")["master_name"]`、`me->query("family")["family_name"]`（泥潭式为 `query("family", ob)[...]`）直接对门派映射取下标：没有门派的人（新玩家、叛师者、大多数 NPC）在 NPC 的打招呼和问话、绝招的门派判断、房间的 `valid_leave` 里报 `Value being indexed is zero`，而不是得到拒绝。1 处（1 个文件）改为 dbase 路径查询 `query("family/master_name")`：有门派时值相同，没有时得 0；原有的判断照常生效（`scripts/lpc_fix_family_index.py`）。给映射赋值的写法未动。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

2 个文件、4 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`），多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/obj/obj/golden_armor`、`/obj/obj/golden_sword`、`/obj/obj/steel_armor`）。本库 NPC 基类 `std/char/npc.lpc` 的 `carry_object()` 第一句是 `if (file->query_unique())`，对不存在的文件直接 call_other，驱动在这里报 `call_other() couldn't find object`，`new()` 来不及返回 0，所以只要 NPC 带着一件本库没有的物品就载入不了（调用处加判断对它无效）。在它前面补 `if (!objectp(load_object(file))) return 0;`（`--base`），缺的物品就跳过，NPC 照常载入；上面那些调用处同样改成带判断的块（基类以后改回去也不怕）。载入检查：改动的文件改前能载入 1 个，改后 3 个（2 个原来载入不了），没有退步。

## 去掉的预定义宏 `SAVE_EXTENSION`（2026-10-18，KB 04 §6.11）

老版 MudOS 给每个 LPC 对象预先定义了 `SAVE_EXTENSION`（`".o"`）；FluffOS 的 ChangeLog（COMPAT_BUSTER 一条）把它删了，改用 `__SAVE_EXTENSION__`。本库没有自己 `#define` 这个宏，用到它的文件一律 `Undefined variable 'SAVE_EXTENSION'`，整个对象载入不了。改成 `__SAVE_EXTENSION__`（`scripts/lpc_fix_predefined_macro.py`）：`adm/daemons/network/netmail.lpc`、`include/net/ftpdsupp.h`。`netmail` 是网络邮件守护进程（本库缺 `mailer.h` 等头文件，改后仍载入不了）。改后用 `lpcc` 逐个载入这些对象：0 个通过，1 个还有别的错误（`adm/daemons/network/netmail`：Undefined function data_netmail_file）。

## `d/moon/obj/poem` 两句诗丢了收尾的引号（2026-10-18，KB 03 §4.6）

`string *poem` 数组里 `"不放玉花飞堕地，留在广寒宫阙。,` 和 `"把酒送春春不语，黄昏却下潇潇雨。,` 的收尾引号没了（转码时跟半个汉字一起丢了），下一行的开引号把字符串合上，后面的诗句成了代码：`Illegal character 0xe6`，整个物件载入不了。补回 `",`。载入：通过。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 4 个对象设了本库没有文件的武功（6 个名字，最多的是 `qiankun-danuoyi`、`essencemagic`、`bibo-shengong`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：4 个里 4 个通过。（`scripts/lpc_guard_set_skill.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 22 处、21 个文件：`dagonforce`→`dragonforce`（8 处）、`mihou-froce`→`mihou-force`（4 处）、`yange_blade`→`yange-blade`（3 处）、`houqaun`→`houquan`（2 处）、`hellfire_whip`→`hellfire-whip`（2 处）、`dragon-step`→`dragonstep`（2 处）、`cuixi-zhang`→`cuixin-zhang`（1 处）。（`scripts/lpc_fix_skill_names.py`）

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 被注释吞掉的 inherit / include（2026-10-19，KB 06 §7.274）

`/daemon/class/moon/moonshentong/shiyue.lpc`：`inherit SSERVER;`。这些指令接在上一行 `//` 注释的末尾（档案里丢了换行），成了注释的一部分，驱动看不到：缺 `inherit` 的技能报 `Undefined function offensive_target`，缺 `#include <weapon.h>` 的兵器报语法错误。`scripts/lpc_fix_swallowed_directive.py` 把换行放回去。载入检查 1 个文件，1 个原来编译不过、现在载入，没有退步。

## 玩家打造兵器模板没有打造者时（2026-10-19，KB 06 §7.275）

`/d/obj/m_weapon/weapon/m_blade.lpc`、`/d/obj/m_weapon/weapon/m_club.lpc`、`/d/obj/m_weapon/weapon/m_hammer.lpc`、`/d/obj/m_weapon/weapon/m_staff.lpc`、`/d/obj/m_weapon/weapon/m_sword.lpc`、`/d/obj/m_weapon/weapon/m_whip.lpc`（共 6 个）的 `create()` 开头 `me = this_player();` 之后无条件读 `me->query("weapon/name")` 等打造数据。房间刷新时没有人在场（`me` 为 0），或者 NPC 在别的 NPC 的命令环境里 `carry_object()` 这个模板（NPC 的 `weapon` 属性是文件名字符串），旧驱动里读出来是 0 或字符串，`switch` 照样落到 default；新驱动报 `Bad argument 1 to EFUN call_other()` / `Bad argument 1 to switch`，NPC 和它所在的房间载入不了（`--walk` 普查里一个玩家走进房间就触发）。在 `//读入数据` 之后加 `if (!me || !mapp(me->query("weapon"))) { setup(); return; }`：没有打造者就留一个没有名字的空模板，玩家打造的流程不变。

## 补回丢失的标点（2026-10-19，KB 03 §4.6）

转换时丢掉的分号、逗号、引号或文件末尾的 `}`，共 4 个文件，修前 HEAD 载入失败。别的库里同路径的完好副本只比这里少几个标点，按它补回（括号里是那个库）：`/d/obj/book/baguatu.lpc`（fys）、`/daemon/skill/taizuchangquan.lpc`（fy2mg）。文件末尾少了 `}`（最后一个或两个字节丢了），补上：`/d/ourhome/room1.lpc`、`/daemon/skill/unused/snowshade-force.lpc`。修后与 HEAD 逐个对比载入：这 4 个物件全部载入，没有退步（`scripts/lpc_restore_from_twin.py`、`lpc_fix_eaten_quote.py --comma`、`lpc_fix_eof_braces.py`）。

## `set_name` 的 id 参数（2026-10-19，KB 06 §7.260）

`/d/qujing/wudidong/obj/baowu2.lpc`、`baowu3.lpc`、`baowu5.lpc`、`baowu6.lpc` 里 `set_name("墨台", ("mo tai"))`：括号里是字符串不是数组，`set_name` 要的是 id 数组，物件载入失败。改成 `({ "mo tai" })`，HEAD 上载入失败的 4 个物件全部载入，没有警告。

## `call_out_info()` 的每一项只有 3 个元素（2026-10-20，KB 06 §7.287）

驱动返回的是 `({ 物件, 函数, 延迟 })`，不带 call_out 的参数，旧代码读第 4 项 `info[i][3]`（`callouts` 指令、`calloutd`、`cod` 工具）一读就报 `Array index out of bounds`，指令从第一行起什么也打印不出来。改为 `(sizeof(info[i]) > 3 ? info[i][3] : 0)`（`scripts/lpc_fix_callout_info.py`）。改动：`/cmds/adm/callouts.lpc`（1 处）、`/cmds/arch/callouts.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 2 处）；其后 `x == "a" && x == "b"` / `x == "a" || "b"` 这类被 `==` 暴露出来的链也随之改成 `||` 或补全变量（`/d/wiz/menu.lpc`、`/d/wiz/menu_conf.lpc`、`/d/wiz/menu_ser.lpc`）。改动：`/clone/medicine/liushen.lpc`（1 处）、`/cmds/wiz/dns.lpc`（1 处）。

## `callouts`：`sizeof(info[i]) == 4` 把每一行都挡掉了（2026-10-20，KB 06 §7.287）

驱动的 `call_out_info()` 每项只有 3 个元素，输出行前的守卫 `if (sizeof(info[i]) == 4)` 永远不成立，指令只打印表头。改为 `>= 3`。改动：`/cmds/adm/callouts.lpc`（1 处）、`/cmds/arch/callouts.lpc`（1 处）。

## `socket` / `dumpsocket` 指令：`dump_socket_status()` 驱动里没有（2026-10-20，KB 06 §7.291）

这些巫师指令 `write(dump_socket_status());`，MudOS 的 efun 在 FluffOS 里不存在，指令编译不过。在模拟 efun 文件里补了 `dump_socket_status()`：用 `socket_status()` 排出同样的表（没有 sockets 包的构建，比如 WASM，只有表头；`scripts/lpc_add_sefun.py dump_socket_status`）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/obj/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## sefun `cat()`：缺文件时 `write(0)` 报错（2026-10-20，KB 06 §7.297）

`void cat(string file) { write(read_file(file)); }`：文件不存在（压缩包没带的欢迎/公告文件，或只有运行中的 mud 才会写的日志）时 `read_file()` 回 0，`write(0)` 在本驱动里报 `Bad argument 1 to receive()`，调用者（登录对话、`cat` 指令）被中断；老驱动什么也不打印。改成 `write(read_file(file) || "");`（`scripts/lpc_fix_cat_unchecked.py`）。改动：`/adm/simul_efun/file.lpc`。

## 访客计数 `howmany_visitor()` 读文件不检查（2026-10-20，KB 06 §7.301）

`howmany_visitor()` 读访客计数文件（`VISITORS` / `COUNTER` / `BBSVISITOR`，只有运行中的 mud 才会写；`.gitignore` 把它排除在仓库之外），新检出的树里没有，`read_file()` 回 0，`sscanf(0, ...)` 报错。这份副本登录时不一定走到它，但调用时同样会出错。在读文件之后加了 `if (!stringp(content)) return 0;`（xkx100、xiakexing100、zzfy 早先的写法，`scripts/lpc_fix_visitor_count.py`）。改动：`/adm/daemons/logind.lpc`、`/edit/adm/daemons/logind.lpc`。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库现有的 NPC 文件里没有字面写成空 `chat_msg` 的（扫描只认 `set("chat_msg", ({ }))`）；守卫挡的是运行时才为空的列表和以后新增的 NPC。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/d/obj/inherit/char/npc.lpc`、`/std/char/npc.lpc`（共 2 个文件）。
