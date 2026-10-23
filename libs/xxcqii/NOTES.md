
## WASM 修复摘要（迁移自 meta.json 的 group_note）

小雪初晴II（SnowMud），一款以温瑞安小说为题材的 MUD，是 117 号 xxcq（品牌名"大侠传奇之小雪初晴"）的手足档案。WASM 修复了 2 处各自独立的 §7.52 类 socket 精灵 bug：（1）adm/daemons/httpd.lpc，一个自成一体的网页服务器（JackyBoy@CuteRabbits Studio 移植），没有外部呼叫者——不仅掏空了每一个碰 socket 的函式，还按照最新的处理惯例彻底关掉了入口点：create() 不再安排 call_out("setup", 5)，也不再发出虚假的"网页服务器启动成功"提示。（2）adm/daemons/network/dns_master.lpc，一个真正的多用途 intermud 精灵（query_mud_name()/muds 映射/query_udp_port() 等被大约 28 个其它服务档案呼叫：mudlist_a/mudlist_q/gtell/gchannel/rwho/ping 等）——按照 AGENTS.md §7.52 对多用途精灵的明确例外处理，没有整个档案掏空，只掏空了两个碰 socket 的入口点（startup_udp() 现在只是回传 0，符合它自己既有的失败回传惯例，所以 create() 里的 'if (startup_udp()) init_database();' 会自然跳过依赖 socket 的数据库初始化，不需要改动其它任何代码；send_udp() 变成 no-op），另外还删掉了 send_shutdown() 里遗留的一处 socket_close() 呼叫。和 xxcq 不同，这份快照的 SECURITY_D 正确指向 /adm/daemons/securityd（不是 securd.lpc 那种硬编码播种模式），而且真的会在开机时读取 WIZLIST；adm/etc/ 目录本来就存在且带有真实数据（不像手足档案 xxcq 那样有目录缺失 bug）。管理员账号播种：fluffos (admin) 加入 adm/etc/wizlist（已有 14 个账号，分布在 (admin)/(hufa)/(immortal)/(apprentice) 各阶层）。注册流程在一次连续的 WASM 客户端会话里完整验证过：GB/BIG5 选择→英文 id→y/n 确认创建→中文名字→临时密码+确认→接受天赋赠礼（y）→性别（m/f）→在武林盟起始房间的电子邮件注册闸门（register/zhuce 指令，或直接输入指定的中文短语才能继续）→带着完整角色属性表进入游戏世界，全程没有任何意外错误。管理员权限已直接通过"目前权限：(admin)"确认，fluffos 出现在一个正在进行的任务列表里，和其它管理员并列。LPC 格式化工具对全部 3034 个档案运行（写入 2976 个，28 个报错，30 个未改动）。没有 :: 父类呼叫拆分命中，没有 CJK 重新加空格命中，没有 case 标签带尾随注释的候选。唯一一个存在的 map.lpc 档案确认内容完全相同（只是空白差异）。格式化后用同样的完整注册流程重新验证过——干净，管理员权限依然是 (admin)。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 20 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## §7.100 扫描修复（`ROOM` 基类多余 `replace_program()`）

同一形状扩展到全库通用房间基类 `#define ROOM "/inherit/room/room"`：
删除 846 处多余的、独立成行的 `replace_program(ROOM);`（保留
`inherit ROOM;`）。此外，本库自带的房间建造工具
`clone/misc/roommaker.lpc` 有两套生成模板——"造一间空房间"的
heredoc 模板本来就是干净的，但"克隆我所在的房间"命令的字符串拼接
模板（第 138 行）把同一枚多余的 `replace_program(ROOM);` 直接烤进了
每一个用它克隆出来的新房间，已同步修正（删除该拼接片段，保留
`setup();`）。已用 `build-debug` 驱动干净启动验证（0 个新增编译
错误，端口正常监听）；未做完整 §10.7 深度游玩测试。

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

## 深度功能测试（2026-08-27，round two, AGENTS.md §10.7）

一次连续的真人视角游玩会话，用真实的原始 socket 脚本（非 tmux_mud.sh）
完成：注册中文角色苏晓雪(tstsnow) → 乘马车赶到华阳 → 徒步穿越 5+
个房间抵达浣花剑庐 → `ask jia ding about 拜师` 由家丁带路入庐 →
`bai li` 拜虎组组长李子木为师，正式成为"浣花剑派第六代弟子、虎组
组员" → `learn li force` 学艺成功 → 前往少林寺"穷武房"(kfroom_5)
用木人练功桩安全对练 11 轮，最终因反复测试而阵亡成"鬼魂" → 干净
`quit` 后 grep debug.log（全程无任何 error）→ driver 完整重启后
reconnect，确认角色属性、门派归属、师父、已学技能、位置全部正确
持久化。管理员账号也按 NOTES 记录的 fluffos/Mud@2026 重新走完整注册
流程验证（此前的 WASM 阶段存档并未留存在这份 work/ 树里），确认
"目前权限：(admin)"，落地在巫师公会。

发现并修复了 6 类程序性 bug（按 AGENTS.md 标准清单逐项排查后确认）：

1. **注册流程 debug 遗留 `printf("%O\n", ob)` 泄漏内部对象引用**
   （`adm/daemons/logind.lpc`/`logind1.lpc`/`logind2.lpc` 的
   `get_name()`，仅 `logind.lpc` 是 `LOGIN_D` 实际生效的档案，另两份
   是历史快照但一并修正保持一致）：每一个新注册玩家在设定中文名字
   之后，正式提示"请设定您的临时密码"之前，都会先看到一行裸露的
   `/clone/user/login#N` 内部对象路径。已删除该行调试语句。

2. **`inherit/skill/skill.lpc` 基类 `valid_learn()` 声明 0 参数，
   但全库 93/94 个技能档案（含 `kungfu/skill/force.lpc`）都用 1 参数
   `valid_learn(object me)` 覆写**：`force.lpc` 是唯一残留 0 参数版本
   的档案。这个不一致触发驱动的"Number of arguments... disagrees
   with previous definition"编译警告，且该警告会直接印在**触发首次
   编译的那个玩家自己的屏幕上**（`learn <师父> <功夫>` 第一次真正
   延迟编译某个技能档案时）。已将基类和 `force.lpc` 都统一成 1 参数
   形式；driver 重启后确认警告消失。

3. **AGENTS.md §7.11**：`adm/simul_efun/file.lpc` 的 `log_file()`
   没有调用同档案里现成的 `assure_file()`，本库从未随档发过
   `log/nosave/` 目录。已加上 `assure_file(LOG_DIR + file);`（连同
   一个前向声明，因为 `assure_file()` 定义在 `log_file()` 之后）。
   详见 AGENTS.md §7.11 新增条目。

4. **AGENTS.md §7.112 新实例**：`d/shaolin/kfroom_5.lpc`/`kfroom_6.lpc`
   （少林"穷武房"11 轮木人机关阵，每轮实发 `combat_exp`/`potential`）
   的 `init()` 完全没有防重入保护；`kfroom_1`~`4` 虽然有一次性入场
   旗标但没有"本轮正在进行中"的防护。已用真实的断线-重连复现实验
   （非清洁 `quit`，模拟真实掉线）确认修复前会在重连时叠加第二条
   完整的机关阵调用链（重复触发"机关开动了"横幅），修复后不再重复。
   6 个档案均已修正并用 `update` 热编译验证。详见 AGENTS.md §7.112
   新增段落。

5. **`feature/dealer.lpc` 的 `do_list()` 用整个键数组当映射下标**
   （`j = tmp[goods];` 应为 `j = tmp[goods[i]];`），导致**全库所有
   商人的 `list` 指令永远把实际持有的商品数量显示成 0**（在华阳
   打铁铺·刘铁匠现场确认："0件布衣" → 修复后 "1件布衣"，实际持有
   数量全程未变）。这是一处全新的、AGENTS.md 尚未收录的 bug 形状，
   已作为 §7.151 新增条目登记。

6. **AGENTS.md §7.86 新实例**：`d/kunming/dangpu.lpc`（当铺房间）和
   `d/kunming/obj/dpm.lpc`（当铺柜台）都是 `inherit SR_DANGPU;` 之后
   又多余调用一次 `replace_program(SR_DANGPU);`——本库先前的
   `ROOM`/`BULLETIN_BOARD` 专项扫描没有覆盖这个宏，属于漏网实例。
   已删除两处多余调用；`dangpu.lpc`（真正会被载入的房间）经
   `update` 验证编译干净。`dpm.lpc` 经全库搜索确认是**从未被任何地方
   引用的死代码**，且本身还带一个与这次修复无关的既存编译错误
   （`set_name()` 未定义，因为 `SR_DANGPU` 的祖先链里没有提供这个
   函数的物品/角色基类）——因为不可达且需要猜测原作者想再继承哪个
   基类，此项按"存疑不动"处理，只作为观察记录，未修复。

7. **AGENTS.md §7.152（新增条目）**：`clone/user/user.lpc` 的
   `reconnect()` 会正确恢复 `heart_beat`、清除 `netdead` 旗标，但
   **从未重新调用 `set_living_name()`**（不同于建号时 `enable_player()`
   会做的事）。用两个 socket 的隔离复现实验确认：任何玩家只要有过
   一次掉线重连（哪怕只隔 1.5 秒），在该次连线剩余时间内，
   `find_player()`/`find_living()` 驱动的所有功能都会找不到这个人——
   已现场验证 `tell <名字> ...`（真实玩家指令）和管理员 `call
   <名字>->...`（调试工具）两者都会报错"没有这个人"/"找不到指定的
   物件"，即使该角色明显在线、可以正常收发指令。已在 `reconnect()`
   开头补上与 `enable_player()` 相同的 `set_living_name()` 调用；
   干净重启后重新做同样的断线-重连复现实验，`tell` 恢复正常。**排查
   过程中的一个误报**：清洁 `quit` 后立刻（10 秒内）重新登录同一个
   ID 会被本库自己的防灌水机制拒绝（`get_passwd()` 里"你距上次退出
   仅 N tick"的检查，`adm/daemons/logind.lpc` 明确写出的既有设计），
   一开始误以为是另一个 bug，等够 10 秒以上再测就确认这是正常行为。

**结算与清理**：测试角色（tstsnow、以及排查过程中另建的 freshzz）
的存档和相关一次性 daemon 运行时状态（`emaild.o`、`data/SaveRoom/`）
已在提交前删除，只保留播种的 fluffos 管理员存档。`grep -h '"port"'`
端口唯一性检查、LPC 格式化工具（16 个改动档案，0 written/0 errors，
说明本次改动本身已符合格式规范）均已过。

**留给后续测试 `xxcqii2`（同属小雪初晴系列，很可能共享同一份引擎
代码）的排查清单**：以上 7 类里第 3～5、7 项（`log_file()`/
`assure_file()`、`kfroom_*` 防重入、`dealer.lpc` 的 `do_list()` 下标、
`reconnect()` 缺 `set_living_name()`）都基于共享 mixin/feature 档案，
如果 `xxcqii2` 复用了同一份代码，大概率会有同样的问题，建议优先
核对这几个档案。

## Shop (2026-09-04)

2026-08-27 already did 浣花 `bai li` (on tstsnow, later deleted) and
fixed dealer `list` at 华阳打铁铺 (`0件布衣` → `1件布衣`). That pass
never paid for a catalog item. This pass: native port **40131**, first
send **`g`**, admin `fluffos`/`Mud@2026` (云天明, 【天神】). `goto
/d/bianliang/sanhelou`, `list` still `1件布衣` + 烤鸡腿 八十文.
Cloned 一两白银, `buy jitui` → 买下烤鸡腿, leftover 二十文铜板.
拜师 not re-run.

**Bug ported.** `inherit/room/room.lpc` `make_inventory()` lacked the
`objectp` guard after `new()` (same sibling shape as `xxcq` /
`xxcqii2`). Added `if (!objectp(ob)) return 0;` plus the two `reset()`
`objectp` checks. CRLF preserved.

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 3 here-document block(s) repaired (3 with the terminator glued to the last text line, 0 with it indented), so `End of file in text block` no longer hides the room or object behind them: `d/tangmen/nzlangn1.lpc`, `d/longmen/xuehepai/chenei.lpc`, `d/huanhua/wuroad2.lpc`. The terminator must start its line (the lexer's own test, KB 04 §6.10); a glued one lost its newline in the GBK -> UTF-8 conversion together with a half character, which stays out.

## 深度功能测试（§10.7，2026-10-04）— paths named in another case

The archive comes from a case-insensitive host: files are stored as `BAGUA0.lpc`, `longjing.C`, `d/SHAOLIN/`, the code names them in lower
case (`__DIR__ "bagua0"`, `"tea/longjing"`, `"/d/shaolin/..."`), so the rooms, NPCs and items behind them could not be loaded (a `.C` file is
not an `.lpc` file; KB 03 §4.5). `scripts/lpc_case_paths.py --convert --apply xxcqii`: 1 file(s) renamed to lower case (`.C` -> `.lpc`,
`.H` -> `.h`) and 1 path reference(s) in 1 file(s) rewritten to the new spelling; 0 skipped, 0 ambiguous. Load check of the 1 objects that were renamed, edited or name a renamed path (HEAD against the working tree, an object is the same under any spelling of its path): 1 PASS -> 1 PASS, 0 that loaded before fail now, 0 more load.

1 files moved (1 `.HTM`); mostly under `www/html/WARNING.HTM` (1). A rescan with `scripts/lpc_warnings.py xxcqii` is still due: the renamed files are compiled for the first time.

## 深度功能测试（§10.7，2026-10-05）— room base survives a raising NPC

`scripts/lpc_resilient_room.py --apply`: `make_inventory()` of `inherit/room/room.lpc` loads each inventory object as `if (catch(ob = new(file)) || !objectp(ob)) return 0;`. `new()` of a file that is not there returns 0 (the room just lacks that NPC), but `new()` of a file whose `create()` raises (a skill file for `set_skill()` this archive never had, a `carry_object()` item that is not there, a header that never shipped) raised inside the room and the room did not load at all. The wrong-case renames of this lib (the section above) make the NPCs behind them reachable for the first time, so a room that holds one with such a content gap would have gone from "NPC missing" to "room missing"; now it loads without that NPC, as it did before. The room base compiles and loads with the change (HEAD against the working tree). KB 03 §4.5.

## 深度功能测试（§10.7，2026-10-08）— 编译警告整理

`scripts/lpc_warnings.py xxcqii --fix` 加 `scripts/lpc_fix_no_effect.py --apply`，共改动 105 个 `.lpc` 和 1 个 `.h`（多为删去未用的局部变量）。HEAD 与工作树分别加载（新进程）：94 -> 94 通过，无回退；改过的头文件的 1 个包含者 0 -> 0 通过。启动时警告 3 -> 0；新进程登录（输入名字）正常。

- 2026-10-10：与 xxcq 相同的两处编译错误：`kungfu/skill/wenjia-daofa/wryd.lpc`（「温柔一刀」）的 `if` 括号放错、`d/wenjia/obj/xiangshi.lpc` 的 `me->die;` 少括号，以及 `d/wenjia/` 下两份 `xiangshi_poison.lpc` 草稿少的右括号，从未能编译；已改正，改动文件 HEAD 0 个、工作树全部载入。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 0 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 1 个，只在 #if 分支用的声明移进分支 0 个文件；改动 1 个文件，HEAD 与工作树各载入一次无回退（1 objects; HEAD PASS 0, tree PASS 1; regress 0; newly loading 1），这些文件的警告 2 -> 1。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。23 个文件 23 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。
- 2026-10-14：同一次重扫的其余 14 条：`inherit/private_room.lpc`、`recordable_room.lpc` 的 `setup()` 写成 `int`（基类 `void`，钩子返回值无人读），改 `void`；6 个宏重定义前加 `#undef`；`temp.lpc` 多余的 `inherit F_CLEAN_UP` 删去；一处跨文件同名函数写明胜出者。改动的 50 个对象新进程各载入一次，无回退。

## 内力/精力当作伤害种类（2026-10-15，KB 06 §7.241 第二类）

本库 `feature/damage.lpc` 的 `receive_damage()` 不接受 `jingli`/`neili`/`force` 等种类，`me->receive_damage("jingli", 30)` 之类在练功、绝招、吸取时报 `F_DAMAGE: 伤害种类错误`。1 处改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py` 第二步）。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

27 个文件来自侠客行体系：本库把 jing 改叫 jingli（`receive_damage()` 只接受 jingli/qi/douzhi/shenzhi），`receive_damage("jing", ...)` 报 `伤害种类错误`。按 jing→jingli、kee→qi、force→neili 改名；其中本库自己的 `cmds/skill/learn.lpc`：玩家教玩家时扣教者的 `jing` 报错，学不动时 `query("jing")` 永远为 0（`scripts/lpc_port_es_props.py --any-file`）。

## 治疗/疗伤的属性名（2026-10-15，KB 06 §7.241）

`receive_heal()`/`receive_curing()` 也只接受本库的种类。1 个文件（多为只调用 `receive_heal`/`receive_curing` 的药物、NPC）来自其他体系，按本库的属性名改名（`scripts/lpc_port_es_props.py --any-file`）。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。17 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。


## 技能按另一门武功的等级取招（2026-10-15，KB 06 §7.243）

这些技能文件是从别的武功复制改名来的，`query_action()` 仍用原武功的等级查招式表：只会本技能的人等级为 0，取不到招，每次出招都报错。改为读本技能自己的等级（`scripts/lpc_fix_action_level.py`）：`bupangguan`。


## 招式表最低等级之下没有招（2026-10-15，KB 06 §7.243）

招式表的最低 "lvl" 高于 0（如全部为 100），技能等级未到之前取不到招，每次出招都报错。循环后补 `if (!a_action) a_action = action[0];`（`lpc_fix_action_level.py --fallback`）：`wenjia-daofa`、`zhuifeng-zhang`。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`yiqi-guanriyue`→`yiqiguan-riyue`（`yiqi-guanriyue/heal`）。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

18 个文件、18 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/d/wenjia/obj/chouduan`、`/clone/weapon/blade`、`/d/wenjia/obj/grnduanda`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 0 个，改后 14 个（14 个原来载入不了），没有退步；其余 4 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## 文良玉 NPC 重复继承（2026-10-18，KB 06 §7.240）

`d/wenjia/wenjia/wenjia/npc/wenliangyu.lpc` 先 `inherit NPC;` 又 `inherit F_DEALER;`，而 `F_DEALER`（`/feature/dealer`）本身已经继承 `NPC`：`Illegal to redefine 'nomask' function 'command_hook'`（还有 `disable_player`、`enable_player`、`is_busy`、`query_busy`），整个 NPC 载入不了。去掉多余的 `inherit NPC;`，买东西（`do_buy`）和 `give_task` 都在，`init()` 能正常跑。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 16 个对象设了本库没有文件的武功（5 个名字，最多的是 `yanling-shenfa`、`shenyuan-gong`、`canhe-zhi`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：16 个里 15 个通过，其余 1 个停在别的错误上（`d/murong/npc/job-dizi`：*Bad argument 1 to EFUN call_other()）。（`scripts/lpc_guard_set_skill.py`）

## 标准整理轮（2026-10-19，`scripts/toolkit_fix.sh`）

本库在新驱动下重扫，机械修复：1 个未使用的局部变量。修后与 HEAD 逐个物件对比载入，没有退步。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 被注释吞掉的 inherit / include（2026-10-19，KB 06 §7.274）

`/adm/daemons/securd.lpc`：`#include <login.h>`。这些指令接在上一行 `//` 注释的末尾（档案里丢了换行），成了注释的一部分，驱动看不到：缺 `inherit` 的技能报 `Undefined function offensive_target`，缺 `#include <weapon.h>` 的兵器报语法错误。`scripts/lpc_fix_swallowed_directive.py` 把换行放回去。载入检查 1 个文件，0 个原来编译不过、现在载入，没有退步。

## 手工收尾（2026-10-19，KB 04 §6.10）

- `d/murong/npc/skill.h`：`mapping *skills=({ … })` 是慕容复能传授的武功表，和 NPC 基类 `feature/skill.lpc` 的 `mapping skills`（本人的武功等级）同名；驱动让后声明的盖掉先声明的（`define_variable`），`murong-fu.lpc` 的 `ask_learn()` 读到的一直是这张表，后声明的这份还被强制成 `nosave`。把表改名 `skill_table` 并明写 `nosave`，`ask_learn()` 里 `mapping skills = skill_table[random(sizeof(skill_table))];` 一行跟着改（初始化表达式里的名字指全局表，局部的 `skills` 在初始化之后才进入作用域：`rule_new_local_def_with_init`）。
- `d/murong/npc/dizi.h`：开头 `mapping skills; mapping learned;` 是从基类抄来的，`job-dizi.lpc` 一次也没用到，删掉（`Redeclaration of global variable 'skills'`、`'learned'`）。

逐个与 HEAD 对比载入，没有退步。

## `x == "a" || "b"`：后面的字符串常量永远为真（2026-10-19，KB 06 §7.281）

`if (arg == "yuyou" || "yu you")` 里的 `"yu you"` 是非空字符串，永远为真，整个条件对任何 `arg` 都成立；作者要的是每个字符串都和变量比较。具体是：驿站把任何输入都当成合法的去处；`valid_enable()` 对任何 usage 都返回真。在每个字符串前补上变量和运算符（`scripts/lpc_fix_literal_or.py`；`forrest2.lpc` 是 `dir == "north" && "south"`，手工改成 `(dir == "north" || dir == "south") && ...`）：`/inherit/room/yizhan.lpc`（7 处）、`/kungfu/skill/tianyu-bufa.lpc`（1 处）。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。具体是：百日十龙丸怎么 `eat` 都只得到“你要吃什么？”。改动：`/d/longmen/xuehepai/obj/bairiwan.lpc`（1 处）、`/d/wenjia/square.lpc`（2 处）。另有 `/d/murong/npc/laoda.lpc`（1 处） 的条件下面做的是别的事（`==` 和 `||` 也可能是本意），保持原样。

## `member_array('/', str)` 改为 `strsrch(str, "/")`：字符字面量的 member_array 按字节搜索（2026-10-20，KB 06 §7.283）

`member_array('/', str)` 里的 `'/'` 是整数，驱动按 UTF-8 **字节**搜索，返回字节偏移（带第三个参数时起点也是字节）；最新的 FluffOS（923cdbc0）在字符串里有非 ASCII 文字时，对每个调用点警告一次（`Warning: member_array(int, string) searches BYTES`）。而 `str[0..idx-1]` 按字符切，中文字符串会在错误的位置截断。改为 `strsrch(str, "/")`（找不到同样返回 -1，按字符计数；`scripts/lpc_fix_member_array_char.py`，JSON 编码器等少数几处手改）。改动：`/adm/daemons/vrm_server.lpc`（1 处）、`/cmds/adm/sameip.lpc`（1 处）。

## `boss` 指令：`/open/shit.txt` 不在存档里，`write(0)` 报错（2026-10-20，KB 06 §7.285）

`boss 1` 先清屏、屏蔽所有消息，再 `msg = read_file("/open/shit.txt"); write(msg);`。`/open/` 是巫师目录，存档里没有这个文件，`read_file()` 返回 0，`write(0)` 报 `Bad argument 1 to receive()`，玩家的屏幕还被屏蔽着。改为 `if (stringp(msg)) write(msg);`（`cmds/usr/boss.lpc`）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 7 处）。改动：`/d/huanhua/npc/obj/saozhou.lpc`（1 处）、`/d/murong/hhyuan.lpc`（1 处）、`/d/yaowang/lufeng.lpc`（1 处）、`/d/yaowang/npc/lufeng.lpc`（1 处）、`/d/yaowang/npc/zhanggui.lpc`（1 处）、`/feature/skill.lpc`（2 处）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/obj/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## 简易 `cat()` 把 simul_efun 对象的 euid 改成了玩家：存档时 `Too deep recursion`（2026-10-20，KB 06 §7.313）

`adm/simul_efun/file.lpc` 的 `cat()` 是 `seteuid(geteuid(this_player())); write(read_file(file));`，它在 simul_efun 对象里执行：玩家敲过一次 `help` 之后，这个对象的 euid 就一直是那个玩家的。它自己的 `log_file()` → `assure_file()` → `file_size(LOG_DIR + file)` 于是按玩家权限过 `valid_read()`，被拒绝，`securityd` 再用 `log_file()` 记一笔拒绝，又走回 `file_size()`……直到调用深度耗尽。第二次连线（角色已保存）时第一次被拒的是 `restore_object` 读 `/data/login/s/<id>.o`，之后控制台出现两条 `Too deep recursion.`（`securityd.lpc:173` 和 `:247`），`log/read_fail.log` 写满同一行，角色不再被保存。现在 `cat()` 先记下 simul_efun 自己的 euid，用调用者的权限读文件（`catch()` 里读），读完再还原，`read_file()` 返回 0 时不 `write()`。实测：第一次连线跑 `help`，立刻第二次连线，无递归、无 `read_fail.log`。xxcq 的 `securityd` 没有走到同一条路，同一份 `cat()` 一并改了（潜在的）。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库现有的 NPC 文件里没有字面写成空 `chat_msg` 的（扫描只认 `set("chat_msg", ({ }))`）；守卫挡的是运行时才为空的列表和以后新增的 NPC。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/inherit/char/npc.lpc`（共 1 个文件）。

## `nodjoin`：没有参数时 `present(0, ...)`（2026-10-21，KB 06 §7.336）

`cmds/skill/nodjoin.lpc`（`recruit.c` 的副本）第一句就是 `ob = present(arg, environment(me));`，裸命令 `nodjoin` 时 `arg` 是 0，`present(0, ...)` 在这个驱动里报 `Bad argument 1 to present()`，而且排在 `userp(me)` 的拒绝之前（玩家本来就用不了这个命令）。先拒绝玩家，再 `if (!arg || !objectp(ob = present(arg, environment(me)))) return notify_fail("指令格式 : recruit|shou [cancel]|<对象>\n");`（帮助里的那一行）。xxcq、xxcqii、xxcqii2 三份同样的改法。

## `blockade` / `recover`：`data/keep` 不存在，解封之后世界仍然锁着（2026-10-21，KB 06 §7.340）

管理员扫描里 `blockade` 报 `Error copying file from /data/user/f/fluffos.o to /data/keep/fluffos, Error: No such file or directory`，随后的 `recover` 在第一个 `cp()` 上死于 `*/data/keep/fluffos: lstat failed`，来不及执行最后的 `LOGIN_D->set_madlock(0)`：封锁解不开。`data/keep/` 是运行时目录，git 克隆里没有空目录。`blockade` 在第一次写之前 `if (file_size("/data/keep") != -2) mkdir("/data/keep");`（`mkdir()` 失败答 0，不抛错），`recover` 对没有保存档的玩家 `if (file_size(src) < 0) continue;`，其余照常恢复、照常解锁（`scripts/lpc_fix_keep_dir.py`，hy5 上实测：没有保存档时 `recover` 答“时空解封完毕”，`blockade` 建出 `data/keep` 并保存，`recover` 取回并删除）。改动（2 个文件）：`/cmds/adm/blockade.lpc`、`/cmds/adm/recover.lpc`。

## `xupdate`：`file[sizeof(file)] != '/'` 永远为真（2026-10-21，KB 06 §7.343）

管理员扫描里 `xupdate`（xyj2000）从根目录 `/` 开始递归时报 `Bad argument 2 to foreach Expected: array Got: 0.`：`UpdateDir()` 用 `file[sizeof(file)] != '/'` 判断路径是否已经以 `/` 结尾，下标等于长度读到的是 0，条件永远成立，`/` 变成 `//`，`get_dir("//")` 答 0。改成 `file[<1] != '/'`。同一个写法在 `xrm`、`rm`、`rmdir1`、`rmhir` 里有 55 处，没有动：对普通路径新旧写法的行为相同，唯一改变的是 `xrm /`，旧写法让它死在第一个 `get_dir("//")`，改了它就能递归删光整个游戏目录。

## `socket`：`dump_socket_status()` 在本库没有（2026-10-21，KB 06 §7.291）

管理员扫描里 `socket` 指令（`/cmds/hufa/socket.lpc`）编译不了：`write(dump_socket_status());` 用的是 MudOS 有、本驱动没有的 efun。2026-10-20 的补丁只按名字找了巫师目录里的同名指令，这一条在 `cmds/bos`、`cmds/hufa`、`cmds/island`、`cmds/ser` 这类目录里；用 `scripts/lpc_add_sefun.py dump_socket_status` 在 `/adm/obj/simul_efun.lpc` 末尾补了一个由 `socket_status()` 构造表格的 simul_efun（没有 sockets 包的构建，比如 WASM，只打印表头）。指令 HEAD 编译失败，现在通过。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 30 条注册（26 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/clone/wizmisc/zhihuan.lpc`（`test`）、`/d/bianliang/npc/tiejiang.lpc`（`do_buy`、`do_list`）、`/d/huafu/obj/gaoliang.lpc`（`do_bann`）、`/d/moto.lpc`（`do_list`）、`/d/murong/npc/murong-fu.lpc`（`do_jiaoliang`）、`/d/quanli/npc/dujue.lpc`（`do_join`）、`/d/quanli/npc/futianyi.lpc`（`do_join`）、`/d/quanli/npc/guan.lpc`（`do_join`）、`/d/quanli/npc/kang.lpc`（`do_join`）、`/d/quanli/npc/kong.lpc`（`do_join`） 等共 26 个文件。最多的函数名：`do_join` 19 处、`do_list` 2 处、`test` 1 处、`do_buy` 1 处、`do_bann` 1 处。没有动（读过）：`/d/quanli/npc/hua.lpc` 的 `do_join`（对象本身编译不过，登记留着，等对象能加载再处理）。

## 缺失物品的 `new()` / `carry_object()` 调用链加了保护（2026-10-22，KB 06 §7.73 补充）

`new(路径)->move(...);` / `carry_object(宏("x"))->wear();` 这类语句，路径指向的文件在这个压缩包里没有：`new()` 返回 0，`->move()` 在 0 上报 `Bad argument 1 to EFUN call_other()`。在 `create()` 里这个对象永远加载不了，在 `reset()` 里第一个缺失物品之后的刷新每次 reset 都被跳过。1 个文件里 1 处（`new`）改成 `{ object new_ob = new(路径); if (new_ob) new_ob->move(...); }`（`scripts/lpc_guard_carry_object.py --new`：路径按这个文件自己看到的宏解析，宏名冲突、虚拟对象路径一律跳过）。 对这 1 个改动文件做加载检查（HEAD 与工作区对比）：HEAD 能加载 1 个，现在 1 个（新增可加载 0 个，回归 0 个）。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 还剩 1 个函数没有补（item_desc 1）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/d/murong/hole.lpc`:`look_out`。 另有 1 处函数体被作者整段注释掉（指针没跟着删），是有意关掉的，没动。

## 读不到的留言板：`"/clone/board/x"->foo();` 在 `create()` 里报错（2026-10-22，KB 06 §7.357）

xkx 系的房间在 `setup()` 之后写 `"/clone/board/gaibang_r"->foo();` 来加载留言板（`foo()` 本来就没有定义，只为了触发加载）。这个库没有这个文件，`call_other()` 报 `*call_other() couldn't find object '/clone/board/gaibang_r'`，对象留在内存里、`load_object()` 却抛错：玩家第一次走进房间就看到错误，写在 `create()` 中间的还会切掉后半段。`scripts/lpc_fix_missing_foo.py` 把 1 条单独成行的语句（`/clone/board/wenjia_b`；`/d/wenjia/wenjia/wenjia/square.lpc`）注释掉并写明原因（别的房间里同样的语句本来就是作者自己注释掉的）。证明和 45 个库的整体加载检查见 KB 06 §7.357。

## `(: 函数名 :)` 指针指向本库没有的函数：只含这个指针的行加了注释（2026-10-22，KB 06 §7.355 补充）

`inquiry` / `item_desc` / `chat_msg*` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：用到时（`ask`、`look`、NPC 闲聊）驱动抛 `*Undefined lfun pointer called: 函数名`，这一拍心跳的后半段被跳过。这些函数没有可以补回的来源（别的库同一路径的文件里没有，或者它还要用本库没有的东西），所以 2 个文件里 3 行只含这个指针的行（`"window": (: look_out :),` `"震天鼓": (: ask_me :),` `"gu": (: ask_me :),`）加了注释，原文保留并写明原因，这一项当作没有这个话题 / 物品 / 闲聊条目（`scripts/lpc_fix_dangling_lfun.py`；`#include` 的文件在库里缺失的对象、指针不在整行上的写法没动）。 前提（`function_exists()`）和加载检查（HEAD 与工作区对比，本库改动的 `.lpc` 文件）的结果见 KB 06 §7.355：没有一个回归。

## 汉字按字节切片的老写法没有换成按字符：改法名 `"澄" + name[2..3]`、辈分判断 `name[0..1] == "澄"` 等 28 处（2026-10-22，KB 06 §7.360）

原档按字节算字符串区间（一个汉字 2 字节）：`name[2..3]` 是名字的第二个字，`name[0..1] == "澄"` 问名字是不是以「澄」开头。转成 UTF-8 之后，这个驱动的区间和 `strlen()` 都按字符算（`strlen("澄观")` 是 2，`"澄观"[0..1]` 是两个字），老算术原样留着、意思全变：拜入少林 / 武当 / 峨嵋等派的玩家被改成错误的法名（二字名 `张三` 变成一个字的 `澄`，更长的名字取到第三个字）；各派掌门的辈分判断（`name[0..1] == "澄"`）永远不成立。

本库 28 处（20 个文件）：拼名字的赋值 19 处、与汉字常量比较 9 处。例：`name[2..3]` → `name[1..1]`（`/kungfu/class/shaolin/baocan.lpc:156`）；`name[0..1]` → `name[0..0]`（`/kungfu/class/shaolin/tong.h:68`）；`s1[0..1] == "。"` → `s1[0..0] == "。"`（`/adm/npc/luban.lpc:2007`）。`scripts/lpc_fix_gbk_slice.py` 把下标按字符重算（社区的 UTF-8 版 `xkx100utf8` 里就是同样的写法，作对照）；没有改的：截断（`name = name[0..7]`，现在最多 8 个字，只是放宽）、ASCII 的区间（`fname[0..3] == "room"`、`ctime(time())[4..19]`）和上下文看不出是汉字的区间。证明（`scripts/lpcc_eval.py`，bixiecanyang；其余各库是同一份文本）：让澄字辈掌门 `attempt_apprentice()` 一个名叫「张三」的访客，HEAD 的法名是 `慧`，改后是 `慧三`；抽样 28 个库的 HEAD / 工作树加载对比 0 退步。工具不幂等（`[0..3]` 折半得 `[0..1]`，又是对齐区间），改过的文件记在 `scripts/gbk_slice_converted.txt`，不要重跑。

## 长度检查按字节写，旁边的提示按汉字写：8 处（2026-10-22，KB 06 §7.362）

老档的 `strlen()` 数字节（一个汉字 2 字节），转成 UTF-8 后它数字符：提示写「必须是 2 到 6 个中文字」的检查还是 `strlen(name) < 4 || strlen(name) > 12`，于是两三个字的房名、帮会名、群名、聊天室名、称号被提示自己说允许的那句话拒绝，上限却是提示的两倍；留言板的标题检查 `i < 4 || i > 24 || i % 2` 还会拒绝所有奇数个字的标题（`post 你好吗`）。本库 8 处（4 个文件）：`if ((strlen(name) < 2) || (strlen(name) > 8)) {`（`/adm/daemons/logind.lpc:620`）；`if ((strlen(name) < 2) || (strlen(name) > 12)) {`（`/adm/daemons/logind1.lpc:605`）。`scripts/lpc_fix_strlen_gate.py` 以提示为准：条件里每个 `strlen` 门槛都恰是提示所说数字的两倍才折半，存长度的变量（`i = strlen(arg);`）的门槛和 `|| i % 2` 奇偶项、其后循环的 `i % 2 == 0 &&` 一并处理；提示里有英文 / 字母 / 字节的不动。证明（`scripts/lpcc_eval.py`，bxsj 的留言板，求值对象继承 NPC 并重写 `edit()` 记录调用，`command("post 标题")`）：HEAD 拒绝「你好」和「你好吗」、放行 23 个字的标题；改后接受前两个、拒绝第三个；shenmo 的 `named.lpc invalid_new_name("张三")`：HEAD 回 `名字只能是2-4个中文字。`，改后回 0。抽样 24 + 15 个库的 HEAD / 工作树加载对比 0 退步。

## 按字节写的汉字循环、茶馆猜诗和同盟频道标题（2026-10-23，KB 06 §7.363）

老档按字节做「一个汉字」：`while (i--) if (i % 2 == 0 && !is_chinese(name[i..<0]))` 只检查偶数下标，奇数位上的拉丁字母（`张a`）会过；茶馆猜诗 `mixup()` 用 `strlen(str)/2` 再 `j=j+j`、`str[k..k+1]` 交换两字节；泥潭系 `channeld` 的 `switch (strlen(fname)) case 4/6/8/10` 和 `strlen(family)==4/6` 按字节长度给同盟 / 门派名加空格。本驱动的 `strlen()` 和区间都按字符算。`scripts/lpc_fix_byte_char.py`：去掉奇偶项、把区间改成 `name[i..i]`，按字符重写 `mixup()` 并把 `strlen(first)>=14` 折成 7，频道标题的 case / 门派长度改成字符数（对照 aoxiangtianji）。本库 汉字循环 / `is_chinese` 区间 4 个文件。证明（`scripts/lpcc_eval.py`）：sjplii 的 `check_legal_name` 在 HEAD 接受「张a」、改后拒绝，两边都接受「张三」；xkx100 的 `clubpoem->mixup("离离原上草")` 得到「离离原草上」（真交换汉字）；nitan_san 两字同盟名得到 `【 兄  弟 】`。关键对象加载通过。

## 血条 / 表情标题按字节算显示宽度（2026-10-23，KB 06 §7.365）

老档把汉字当两字节：`bar_string[0..(val * N / max) * 2 - 1]` 把「格数」换成字节下标，半格血条在本驱动（按字符算区间）上会整条画满；巫师表情 `edemote` 的 `repeat_string("─", 13 - (strlen(emotion) / 2))` 也会少减汉字宽度。`scripts/lpc_fix_display_pad.py`：去掉 CJK 血条 / 空白条上的 `* 2`（`jings`/`qis` 赋值和 `blank_string3[0..(23-a)]` 的 23→11 一并改），表情标题去掉 `/ 2`；ASCII 空格的 `none_string` / `empty_string` 仍保留 `* 2`（一格两个空格）。本库 4 处（2 个文件）。证明（`lpcc_eval.py` hhsj）：`tribar_graph(6,9,12)` 在 HEAD 画出整条 12 个■，改后为 6 个■+3 个□；麻将 `strlen(tempB)/2` 是两字符牌码，未改。

