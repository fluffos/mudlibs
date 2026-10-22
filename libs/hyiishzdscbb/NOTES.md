
## WASM 修复摘要（迁移自 meta.json 的 group_note）

海洋II（Ocean II）血统，hy2000/hy2002 的手足档案（分别按路径和两者重合约 9600/10253 个档案）——上海站第三版快照。修复的 bug（全部是主动套用已知的 hy2000/hy2002 修法并确认这里同样存在）：（1）过时的 MASTER_OB/SIMUL_EFUN_OB 宏指向 /adm/single/ 死代码副本（§7.56 类）；（2）howmany_visitor()/howmany_card()/uptime.lpc 的 LASTCRASH 显示里 §7.54 类的 sscanf/write(read_file(缺失档案)) 崩溃；（3）adm/daemons/network/dns_master.lpc 的 startup_udp()/send_udp()/send_shutdown() 里 §7.52 类的 socket 掏空；（4）经典 §8.1 check_legal_name() 字节数没减半的长度界限 bug（2/10→1/5 字符）加上 i%2==0 门槛和 name[i..<0] 尾部切片（is_chinese() 本身已经是正确的）；（5）§7.63 quit.lpc 的 new('/clone/topten/magic-rice') 缺少防御性判断 if(ob=new(...))，和 hy2000 的模式完全一致。管理员引导偏离常规模式（和 hy2002 同一类 §1.5 bug）：securd.lpc 在 restore_list() 里硬编码了引导用管理员 id "titny"，但这个 id 已经是档案里一个真实存在的旧玩家账号——已在旁边追加一行 set("wiz_status/fluffos","(admin)")，用 fluffos/loginpass1 注册，游戏内"目前权限：(admin)"显示确认生效。完整的注册→look→score→quit 流程在排版格式化前后各验证过一次，用的是真实中文名字；GB 和 BIG5 两种编码都实测正常（gb_b5d.lpc 的中文字转换表里有一处无害的编译警告，两种模式下文字都能正确显示）。格式化工具发现 1 个真正损坏的档案（cmds/usr/setbak.lpc，和 hy2000/hy2002 一样的 heredoc 帮助文字损坏）——已用 git checkout 还原。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 53 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（2026-08-13，第一次真正的 §10.7 深度测试）

此前只做过 WASM 修复摘要 + §7.86 扫描修复，从未跑过真正的注册/游玩
全流程。这是第一次。Re-tested against the freshly-rebuilt
`build-debug/src/driver`（post 全库 `quest_times`/`win_times`
`%`-operator 修复 + Warning/warning 驱动文本回退）。这份档案和
`hy2000`/`hy2002` 是同一套"海洋II"血统的又一个快照（README 已记
录），管理员 `wiz_status/fluffos` 并列授权行已经从更早的一次会话
里正确修复过（`titny` 是已被占用的真实旧账号，和 `hy2002` 的
`hxsd` 同一形状），本轮只发现并修复了 log_error()/log_file() 两处。

### 发现并修复的 PROGRAMMING bug

1. **`log_error()`（`adm/obj/master.lpc`）完全没有严重度检查（AGENTS.md
   §7.34-class，与本轮 `wdxtym`/`ffxymud`/`fy2mg`/`fys`/`hc`/`hy`/
   `hy2000`/`hy2002`/`hy3`/`hy5` 同一原始形状）**：`if
   (this_player(1)) efun::write(...)`——不区分巫师/玩家，也不区分
   警告/错误。修复：加上 `strsrch(message, "arning:") == -1` 判断。
2. **`log_file()`（`adm/simul_efun/file.lpc`）完全没有 `assure_file()`
   保护（AGENTS.md §7.11-class 的又一确认实例）**：注册/登录本身只
   写 `log_file("USAGE", ...)`（无子目录，本来就存在），不受影响，
   但 `nosave/CRASHES`/`nosave/PURGE`/`nosave/tengaoshou`/
   `nosave/tenrich`/`nosave/addobj` 等管理指令路径会在首次使用时未
   捕获抛出。已补上 `assure_file(LOG_DIR + file);`（含前向声明）。

### 管理员账号：存档从未真正提交

README 记录"账号通过正常注册流程创建，已在游戏内确认'目前权限：
(admin)'显示正确"——`git log` 确认这个存档从未被提交过，本地
`work/` 目录里也不存在。已用真实注册流程（英文 id → 确认建立 →
中文名，直接设定不需要二次确认 → 密码 `loginpass1` → 确认密码 →
天赋 0 随机 → 接受 → 邮箱 → 性别）重新创建 `fluffos`/浮浮，`score`
确认"目前权限：(admin)"，`update /adm/simul_efun/file`（就是本轮改
过的文件）确认可正常重新编译，本次是真正的 live 验证。

### Proactive checks（无需改动）

- `win_times` 修复确认存在且正确：`d/city2/npc/refereew.lpc:177`。
- 未发现 `message()` simul_efun 包装函数——不适用
  message()-missing-varargs 这一类 bug。

### 实测过程

登录时有一个 GB/Big5 选码提示（选 `g`）。`adm/log/debug.log` 时间
戳全程未变化（`Jul 30`，早于本次会话），确认无新增未捕获运行期错
误。驱动最终按精确 PID kill，`ps -p` 确认已退出。

### 已清理

- 管理员 `fluffos` 的存档已提交（`data/{login,user}/f/fluffos.o`）。

## §7.100 修复（`ROOM` 基类的同一"多余 replace_program()"形状，全档案扫描第 6 批）

- 删除 2,623 处存活的 `replace_program(ROOM);` 相关行，与普查记录一致。
  除脚本批量删除的标准 standalone 行外，另手工修复三处不规则形状：
  `d/happy/workroom.lpc` 的行尾空注释变体（`replace_program(ROOM);
  //`）、`adm/roommaker.lpc`（本库第二套建房工具，独立于
  `clone/misc/roommaker.lpc`）里 `room_code`/`str` 两处字符串拼接
  模板变体。
- 验证：真实 `build-debug` 驱动干净开机、端口正常监听，`debug.log` 中
  零 "cannot replace"/"cannot bind" 行。

## §7.30 uninitialized-mapping accessor sweep (2026-08-20)

Corpus-wide mechanical sweep of the `feature/skill.lpc` shared-lineage
bug (confirmed independently on `xiakexing2017`/`jqxz2015`/`haiyang2`
via round-four testing): 5 accessor(s) in this file returned a raw
never-initialized `mapping` instance variable (defaults to `int 0`,
not `([])`, until first assigned), crashing any unguarded
`keys()`/`sizeof()`/indexing caller for a fresh/untrained character.
Fixed at the accessor level (`mapp(x) ? x : ([])`) per the documented
remedy. Verified via `lpcc --batch` static compile check only (not a
live boot) as part of a large mechanical sweep; not individually
functionally re-tested live on this lib.

## 深度功能测试（round three, 2026-09-01）— skill/拜师/首访 NPC 房间，结果：干净

本轮专门针对前两轮未覆盖的角度：(1) `feature/skill.lpc` 那 5 个
§7.30 accessor 修法从未 live 验证过；(2) 从未测试过拜师/门派收徒
流程；(3) 从未针对本库单独做过 §7.19（`enable_commands()`/
`enable_player()` 从 `init()` 里被重入触发的 "Too deep recursion"）
首访检查。用真实 Python socket 脚本（未用 `tmux_mud.sh`），全程用
UTF-8 编码收发（确认这个 WASM 化后的版本内部字符串是真正的 UTF-8
codepoint 阵列——`is_chinese()` 检查的是 `str[0] in
[0x4e00,0x9fff]`，不是旧版 GBK 字节区间；`Are you using BIG5` 提示
只影响输出转码，不影响输入，用 GBK 编码发送中文名字会被
`check_legal_name()` 的 `strlen()` 字节数误判超长，纯属测试脚本自
己的编码错误，不是 mudlib bug）。

用真实注册流程新建角色 `hyszdsii`/苏挽秋（男，随机天赋），全程可用：

- `skills`（一进游戏立刻测，直接命中 §7.30 修过的
  `query_skills()`）——干净返回"你目前并没有学会任何技能。"，无崩
  溃。这是该 accessor 修法第一次真正 live 验证通过。
- 用管理员账号 `fluffos`（此前已注册，见 2026-08-13 章节）`goto`
  到三个本库账号历史上从未有人到过的 NPC 房间（本次开机后的第一
  次装载）：`/d/quanzhen/wanwutang`（全真教王处一）、
  `/d/shaolin/wuqiku`（少林武器库，道尘禅师/打铁僧）、
  `/d/baituo/liangong`（白驼山练功场，李教头）——三个房间的
  `init()`/`chat_msg`/`greeting()` 首次触发均正常，`debug.log` 全程
  只新增未使用局部变量的编译期 warning，没有任何 "Too deep
  recursion"、崩溃或 §7.19 症状。
- 完整拜师流程（用 `summon` 把新角色叫到管理员所在的
  `/d/baituo/liangong`，`bai li`）：`d/baituo/npc/li.lpc`（李教头，
  白驼山派）的 `attempt_apprentice()` 没有任何门槛，直接
  `recruit_apprentice()` 成功——"恭喜您成为白驼山派的第三代弟子"，
  `score` 确认"你的师傅是：李教头"、称谓更新为"白驼山派第三代弟
  子"。`feature/apprentice.lpc` 的 `create_family`/
  `recruit_apprentice`/`assign_apprentice`/`is_apprentice_of` 全程无
  异常。收徒后 `skills` 依然干净（未自动获得任何技能，这是
  `recruit_apprentice()` 本身的设计——不赠技能，不是 bug）。
- 顺手测了平安广场留言板（`/d/pingan/pinganguangchang`，
  `pingan_b.lpc`，此前 §7.86 跨库扫描已修过 `replace_program()` 崩
  溃）：`read 1` 正常显示留言，`post`（不带参数）正常提示"留言请指
  定一个标题。"，没有重现 §7.86 症状。

**结论：本轮三个新角度（skill accessor 首次 live 验证、拜师门派流
程、多间从未装载过的 NPC 房间首访）全部干净，未发现新的 PROGRAMMING
bug。** 没有编造问题；`log/debug.log` 全程只有正常的首次装载编译期
warning（未使用局部变量），无一条 error/crash/"Too deep
recursion"。驱动按精确 PID kill。

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— 任务表里的 `.c` 路径与任务守护进程的防护

`scripts/lpc_dynamic_rows.py`：`quest/dynamic_location` 里 833 行写的是原档案的 `.c` 路径。转档时文件已改名 `.lpc`，而显式后缀按原样解析，`load_object("/d/x.c")`、`new("/d/obj/quest/x.c")` 返回 0 且不报错（KB 03 §4.2，KB 06 §7.220），所以 `adm/daemons/questd.lpc`、`cmds/std/questd.lpc` 读到的每一行都加载不出来：随机任务和任务物品从未生成，在 `create()` 里直接对结果调用 `tar->set()` 的版本还会崩溃，连带加载它的 cron 守护进程和 `give` 的任务钩子。这些行已改为 `.lpc`。
`scripts/lpc_dynamic_quest_guard.py`：2 处 `spread_quest()` 调用（`init_dynamic_quest()` 的循环里）包进 `catch()`，缺失的任务物品或编译不过的房间只跳过那一个任务，守护进程照常加载、其余任务照常生成；`cmds/std/look.lpc` 夜间检查的 `!present("fire", this_player())` 前加 `objectp(this_player()) &&`（房间 `reset()` 销毁物品时 `/feature/move.lpc` 的 `remove()` 会调用 `look_room()`，此时没有 this_player()，`present(…, 0)` 报 `Bad argument 2 to present()`）。
验证：`adm/daemons/questd.lpc`、`cmds/std/questd.lpc`和 cron 守护进程在新进程里加载（HEAD 一次，工作树三次，选房是随机的）：HEAD 通过 3 个，工作树三次分别通过 3、3、3 个（共 3 个），无回退。
验证：改动过的 `adm/daemons/questd.lpc`、`cmds/std/look.lpc`、`cmds/std/questd.lpc` 在新进程里加载，HEAD 通过 3 个、工作树通过 3 个（共 3 个），无回退。

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `inherit/room/room.lpc`：`make_inventory()` 用 `catch()` 包住 `new(file)`，做不出来就返回 0；`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-06）— 白驼山掌门欧阳锋编译不过

`d/baituo/ouyangfeng.lpc` 有两处笔误，整个 NPC 从未编译成功：`greeting()` 里 `write("你是谁？我要杀了你！哈￣哈￣哈￣") break;` 缺分号，`inquiry_map()` 里 `object me = this - player();`（应为 `this_player()`）。白驼山派的掌门因此不存在，拜师、问路（`inquiry_map`）都无从谈起。两处改正后，新进程里 HEAD 加载失败、工作树加载成功。同一文件在 14 个 xkx 系的库里一字不差。

## 深度功能测试（§10.7，2026-10-07）— 空的 `if (current_water == 0) {}`

3 个房间的 `valid_leave()` 里有一行什么也不做的 `if (current_water == 0) {}`（编译警告 `Expression has no side effects`），删去，行为不变：`d/xingxiu/nanjiang2.lpc`、`d/xingxiu/nanjiang3.lpc`、`d/xingxiu/shanjiao.lpc`。

## 深度功能测试（§10.7，2026-10-07）— 编译警告整理；组队/跟随从来没起作用

`scripts/lpc_warnings.py hyiishzdscbb --fix` 加 `scripts/lpc_fix_no_effect.py --apply`（`d/tiezhang` 三个房间删去 `return` 后面的 `"\n";`，`kungfu/skill/xuanyuan-arrow.lpc` 删去什么也不做的 `(: throw_weapon :);`），共改动 686 个 `.lpc` 和若干 `.h`。HEAD 与工作树分别加载（新进程）：648 -> 648 通过，无回退。
**`feature/team.lpc` 是 `cmds/std/team.lpc` 指令的一份拷贝**（`int main(object me, string arg)`），不是组队特性——归档里就是这样。人物（`inherit/char/char.lpc` 的 `inherit F_TEAM;`）因此没有 `set_leader()`、`query_leader()`、`query_team()`、`follow_me()` 等函数：`follow`、`team`、`come`、`stay` 这些指令对玩家 `->set_leader()` 什么也不做，跟随和组队从来没起作用；直接调用 `set_leader()` 的 NPC（`d/binghuodao/npc/wuji.lpc`、神龙教的 `kungfu/class/shenlong/*` 等 8 个）根本编译不过。换成 hy 的 `feature/team.lpc`（hy 的 `inherit/char/char.lpc` 与本库一字不差）。改过的头文件和人物基类的 168 个包含者 160 -> 167 通过，新能加载的就是这些 NPC；启动时的 `clean_up() inherited from both`（那份指令拷贝 `inherit F_CLEAN_UP` 带进来的）也没了。

启动时警告 77 -> 0；新进程登录正常。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 11 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 0 个，只在 #if 分支用的声明移进分支 0 个文件；改动 5 个文件，HEAD 与工作树各载入一次无回退（5 objects; HEAD PASS 5, tree PASS 5; regress 0; newly loading 0），这些文件的警告 11 -> 0。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查（批 3）

- `kungfu/skill/liangyi-jian.bak.lpc`：`int i; level;` 去掉无用的 `level;`。
- 改动的对象 HEAD 与工作区都能载入，无回退。

## 深度功能测试（§10.7，2026-10-12）：编译警告收尾

能编译的文件里的警告 11 -> 0（`lpc_warnings.py hyiishzdscbb` 重扫：8519 个文件可编译，剩下的诊断都在本来就编译不过的文件里）。与 hy2000 同码：hy2000 当天的修复（提交 d38039ba8e2）改的 11 个文件在这里都是 token 级孪生，用 `lpc_twin_port.py adopt` 搬过来；本库自己的扫描对这 8 个文件同样报了 `clean_up()` 双重继承，删掉的 inherit 在本库基类里确实重复。

- 8 个多余的 `inherit F_CLEAN_UP;`（`NPC`/`BLADE` 基类已带）：`services/temp.lpc`、`d/npc/tie-ren.lpc`、`d/quanzhou{,.old}/npc/tang{,3}.lpc`、两个 `mu-ren.lpc`。
- `adm/roommaker.lpc` 重复声明的 `special_props` 删掉前一份死声明；两个 `library.lpc` 重定义 `STORY_DIR` 前加 `#undef`。

本轮没有发现玩法层面的真问题。

验证：11 个改动对象 HEAD 与工作树各用新进程载入：7 -> 7 通过（tang 四个两边都因 lpcc 下读 `/data/npc/meng-zhu.o` 被拒而失败），regress 0；删除声明审计 0 项待看。11 个对象载入无回退。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。5 个文件 5 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）；`x op= 浮点` 先把浮点转成整数再运算（系数小于 1 时 x 直接变 0），改为 `x = to_int(x op ...)`：`/kungfu/skill/fengyun-shou/foguang.lpc`（`damage *=`）、`/kungfu/skill/taiji-quan/zhenup.lpc`（`damage *=`）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。

## 内力/精力当作伤害种类（2026-10-15，KB 06 §7.241 第二类）

本库 `feature/damage.lpc` 的 `receive_damage()` 不接受 `jingli`/`neili`/`force` 等种类，`me->receive_damage("jingli", 30)` 之类在练功、绝招、吸取时报 `F_DAMAGE: 伤害种类错误`。12 处改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py` 第二步）。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。4 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。


## 东方故事/西游记体系的技能文件（2026-10-15，KB 06 §7.241 第三类）

这些 `kungfu/skill` 文件来自 gin/kee/sen/force 体系，本库人物只有 jing/qi/neili：`receive_damage("kee", 30)` 报 `伤害种类错误`，`query("force")` 永远为 0，技能学不了也练不了。按 kee→qi、gin/sen→jing、force→neili、max_force→max_neili、force_factor→jiali 改了属性名（`scripts/lpc_port_es_props.py`），共 6 个文件。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

另有 3 个文件（绝招、状态、物品、NPC 等，不限于 kungfu/skill）来自 gin/kee/sen/force 体系，同样按 kee→qi、gin/sen→jing、force→neili 改名（`scripts/lpc_port_es_props.py --any-file`）。


## family 映射（补）（2026-10-15）

`mapping fam = (mapping)me->query("family");`（带类型转换的写法）同样直接取下标，2 处补上 `if (!mapp(fam)) fam = ([ ]);`。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。8 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。

## 飞雪的兵器销毁（2026-10-15，绝招探测）

`liangyi-jian/feixue.lpc` 末尾的 `else destruct(obj);` 在前一分支已销毁兵器时对 0 调用，改为 `else if (objectp(obj))`。

## 空手使用兵器绝招（2026-10-15，KB 06 §7.246）

`perform` 指令允许直接点名招式（如 `perform stick.ban`），这些绝招读了 `me->query_temp("weapon")` 却从不检查，空手时 `weapon->name()` 报错（有的已先扣了内力）。在赋值后补 `if (!objectp(weapon)) return notify_fail("你必须手持兵器才能使用这一招。\n");`（`scripts/lpc_fix_perform_weapon.py`）：`dagou-bang/ban`、`murong-jianfa/kuangjian`、`tianyu-qijian/kuangwu`、`wuyue-blade/jiao`。

## 妙手回春的银针检查（2026-10-15）

`miaoshouhuichun` 的 `valid_learn()` 用了未赋值的 `object ob`，`ob->query_temp("weapon")` 每次都报错，谁也学不了；还把兵器对象和字符串 "银针" 比较。照 chidi 的修法改为 `ob = me->query_temp("weapon")`，再用 `id("yin zhen")`/`id("yinzhen")` 判断是否银针。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`douzhuan-xignyi`→`douzhuan-xingyi`（`/d/mr/obj/shu1`）；`jinwu-dao`→`jinwu-daofa`（`jinwu-daofa`）；`yinyun_ziqi`→`yinyun-ziqi`（`yinyun-ziqi/cure`）。

## 技能名拼错：技能文件里拼错自己的名字（2026-10-15，KB 06 §7.249）

技能自己的文件（或它的绝招目录）里，`query_skill()` 读的是差一个字母的自己的名字，永远得 0：“基本功夫要高过本技能”之类的限制从不生效，按等级取招、计算伤害的那一项一直是 0。改为本技能的名字（`scripts/lpc_fix_skill_typo.py` 的 self 判据）：`chanyun-tui`→`chuanyun-tui`（`chuanyun-tui/shuangjue`）。

## family 映射内联取下标（2026-10-15，KB 05 §7.30）

`ob->query("family")["master_name"]`、`me->query("family")["family_name"]`（泥潭式为 `query("family", ob)[...]`）直接对门派映射取下标：没有门派的人（新玩家、叛师者、大多数 NPC）在 NPC 的打招呼和问话、绝招的门派判断、房间的 `valid_leave` 里报 `Value being indexed is zero`，而不是得到拒绝。5 处（4 个文件）改为 dbase 路径查询 `query("family/master_name")`：有门派时值相同，没有时得 0；原有的判断照常生效（`scripts/lpc_fix_family_index.py`）。给映射赋值的写法未动。


## 用兵器的绝招空手施展时报错（内联写法）（2026-10-15，KB 06 §7.246）

绝招不存兵器变量，直接写 `(me->query_temp("weapon"))->query("name")`（或在拒绝判断里写 `(weapon = me->query_temp("weapon"))->query("skill_type")`），之前又没检查兵器：空手 `perform` 时报 `Bad argument 1 to EFUN call_other()`，内力等往往已经扣掉。在第一次用到它的那条语句前补上“你必须手持兵器才能使用这一招”的拒绝（`scripts/lpc_fix_perform_weapon.py`）：`yunv-jian/suxin`。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

3 个文件、4 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/d/city/obj/tudao`、`/d/guanwai/obj/cwbdao`、`/quest/weiguo/jinbing/obj/japancloth`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 0 个，改后 3 个（3 个原来载入不了），没有退步。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 8 个对象设了本库没有文件的武功（3 个名字，最多的是 `shenlong-quanfa`、`xingxiu-duzhang`、`meiren-sanshi`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：8 个里 8 个通过。（`scripts/lpc_guard_set_skill.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 34 处、32 个文件：`kunlun-shnfa`→`kunlun-shenfa`（12 处）、`shaolin-shnfa`→`shaolin-shenfa`（10 处）、`lingbo-weibu`→`lingboweibu`（3 处）、`yunu-xinfa`→`yunv-xinfa`（3 处）、`tiaji-jian`→`taiji-jian`（2 处）、`yan-fly`→`yanfly`（2 处）、`shenhuo-shengong`→`shenghuo-shengong`（1 处）、`taiji-shenfong`→`taiji-shengong`（1 处）。（`scripts/lpc_fix_skill_names.py`）

## 全局头文件丢了 1 个宏（2026-10-19，KB 04 §6.16）

`/include/globals.h` 里没有定义 `MAILDIR`，用到它们的物件（名单里 1 个）编译时报 `Undefined variable`/`Undefined function`，整个物件载入不了（编译器在第一个未定义的名字上停下，后面的错误和警告都看不到）。同系的库在各自的头文件里都有这几行：照其中和本库共有文件最多的那个库，原样补到 `/include/globals.h` 最后一个 `#define` 之后，宏体里出现的路径在本库里都存在。名单里的物件除了这几个宏之外还有别的错误，暂时仍载入不了。（`scripts/lpc_restore_defines.py`）

## bite.lpc 被截断（2026-10-19，KB 06 §7.266）

`d/city/bite.lpc` 在 `set("no_clean_up", 0);` 处结束，缺 `setup(); }`，驱动报 `syntax error, unexpected end of file`。补上 `setup();` 和结尾的 `}`（同系的 hy5 等带着完整的文件）。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 载入不了的零碎文件（2026-10-19，KB 03 §4.7、KB 04 §6.10）

- `d/hangzhou/npc/tangzi.lpc`：整个文件只是 UTF-16 的空格（`\x00 \x00 …`，作者把这个物件清空了），驱动报 `Illegal embedded NUL byte (0x00) in source`；旧驱动编出一个空程序。改成一个换行，行为和原来一样（空程序），不从 xkx100 抄回同名 NPC。

逐个载入与 HEAD 对比，没有退步。

## 玩家打造兵器模板被 NPC 带上（2026-10-19，KB 06 §7.275）

`/d/npc/m_weapon/weapon/m_sword.lpc`（共 1 个）的 `create()` 用 `this_player()` 读打造数据（`me->query("weapon/lv")` 等）。NPC 的 `weapon` 属性是兵器文件名（字符串），NPC 在别的 NPC 的命令环境里 `carry_object()` 这个模板时，`set_desc()` 里 `switch (w_lv)` 拿到的是那个字符串，驱动报 `Bad argument 1 to switch`，房间和 NPC 都载入不了（旧驱动里 switch 落到 default）。把 `if (me) {` 改成 `if (me && mapp(me->query("weapon"))) {`，玩家打造的流程不变。

## 玩家打造兵器模板没有打造者时（2026-10-19，KB 06 §7.275）

`/d/npc/m_weapon/weapon/m_blade.lpc`、`/d/npc/m_weapon/weapon/m_club.lpc`、`/d/npc/m_weapon/weapon/m_hammer.lpc`、`/d/npc/m_weapon/weapon/m_staff.lpc`、`/d/npc/m_weapon/weapon/m_whip.lpc`（共 5 个）的 `create()` 开头 `me = this_player();` 之后无条件读 `me->query("weapon/name")` 等打造数据。房间刷新时没有人在场（`me` 为 0），或者 NPC 在别的 NPC 的命令环境里 `carry_object()` 这个模板（NPC 的 `weapon` 属性是文件名字符串），旧驱动里读出来是 0 或字符串，`switch` 照样落到 default；新驱动报 `Bad argument 1 to EFUN call_other()` / `Bad argument 1 to switch`，NPC 和它所在的房间载入不了（`--walk` 普查里一个玩家走进房间就触发）。在 `//读入数据` 之后加 `if (!me || !mapp(me->query("weapon"))) { setup(); return; }`：没有打造者就留一个没有名字的空模板，玩家打造的流程不变。

## 补回丢失的标点（2026-10-19，KB 03 §4.6）

转换时丢掉的分号、逗号、引号或文件末尾的 `}`，共 3 个文件，修前 HEAD 载入失败。别的库里同路径的完好副本只比这里少几个标点，按它补回（括号里是那个库）：`/d/baituo/npc/obj/bowl.lpc`（cctx）、`/d/baituo/obj/bowl.lpc`（cctx）、`/d/city2/npc/zhengmen.lpc`（jqxz2008）。修后与 HEAD 逐个对比载入：这 3 个物件全部载入，没有退步（`scripts/lpc_restore_from_twin.py`、`lpc_fix_eaten_quote.py --comma`、`lpc_fix_eof_braces.py`）。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。改动：`/d/mingjiao/shanmen.lpc`（1 处）。

## `call_out_info()` 的每一项只有 3 个元素（2026-10-20，KB 06 §7.287）

驱动返回的是 `({ 物件, 函数, 延迟 })`，不带 call_out 的参数，旧代码读第 4 项 `info[i][3]`（`callouts` 指令、`calloutd`、`cod` 工具）一读就报 `Array index out of bounds`，指令从第一行起什么也打印不出来。改为 `(sizeof(info[i]) > 3 ? info[i][3] : 0)`（`scripts/lpc_fix_callout_info.py`）。改动：`/cmds/arch/callouts.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 14 处）。改动：`/adm/daemons/combatd.lpc`（1 处）、`/d/city4/puke-room.lpc`（4 处）、`/d/hangzhou/npc/meipo.lpc`（1 处）、`/kungfu/class/emei/tobebonze.h`（1 处）、`/kungfu/skill/qiankun-danuoyi.lpc`（7 处）。

## `callouts`：`sizeof(info[i]) == 4` 把每一行都挡掉了（2026-10-20，KB 06 §7.287）

驱动的 `call_out_info()` 每项只有 3 个元素，输出行前的守卫 `if (sizeof(info[i]) == 4)` 永远不成立，指令只打印表头。改为 `>= 3`。改动：`/cmds/arch/callouts.lpc`（1 处）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/obj/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## sefun `cat()`：缺文件时 `write(0)` 报错（2026-10-20，KB 06 §7.297）

`void cat(string file) { write(read_file(file)); }`：文件不存在（压缩包没带的欢迎/公告文件，或只有运行中的 mud 才会写的日志）时 `read_file()` 回 0，`write(0)` 在本驱动里报 `Bad argument 1 to receive()`，调用者（登录对话、`cat` 指令）被中断；老驱动什么也不打印。改成 `write(read_file(file) || "");`（`scripts/lpc_fix_cat_unchecked.py`）。改动：`/adm/simul_efun/file.lpc`。

## 翻页器 `start_more(read_file(...))`：文件缺失时 `explode(0)`（2026-10-20，KB 06 §7.300）

东方故事系的翻页器 `void start_more(string msg) { ... explode(msg, "\n") ... }` 被这样调用：`start_more(read_file(HELP_DIR + "help/topics"))`、`start_more(read_file(NEWS))`。压缩包没带的文件使 `read_file()` 回 0，`explode(0, ...)` 在本驱动里报 `Bad argument 1 to explode()`（不带参数的 `help` 指令就是这样出错的），老驱动把 0 当空文本。在 `start_more` 开头加了 `if (!stringp(msg)) return;`（`scripts/lpc_fix_start_more.py`）。改动：`/feature/more.lpc`。

## `setbak` 指令编译不过：文件末尾粘了半截 `help()`（2026-10-20，KB 06 §7.264）

`cmds/usr/setbak.lpc` 在完整的 `help()` 之后又重复了帮助文字的结尾（`取消变数设定请用 unset 指令。……TEXT ); return 1; }`，没有函数头）：`Illegal character 0xe5`。在第一个完整函数结尾处截断（去掉 8 行）。加载检查：HEAD FAIL → tree PASS。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库现有的 NPC 文件里没有字面写成空 `chat_msg` 的（扫描只认 `set("chat_msg", ({ }))`）；守卫挡的是运行时才为空的列表和以后新增的 NPC。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/inherit/char/npc.lpc`（共 1 个文件）。

## 存档里的 `.c` 文件名改成 `.lpc`（2026-10-21，KB 03 §4.2 第 9 项）

存档里写着 `"/d/city/npc/wei.c"` 这样的文件名；extract 时源文件已经全部改成 `.lpc`，而驱动对带扩展名的路径只认字面，`new()` / `load_object()` / `move()` 都找不到它，调用方多半把失败当成「没有这个东西」悄悄跳过。本库 10 个存档共 10 处按 `scripts/lpc_fix_save_dotc.py` 改成 `.lpc`（只改 `.lpc` 存在而 `.c` 不存在的字符串；玩家存档、备份、留言板、巫师目录和文件索引缓存不动）。改动：`/p/residence/cash971888263.o`（1 处）、`/p/residence/cash971888503.o`（1 处）、`/p/residence/cash971888605.o`（1 处）、`/p/residence/chao972181288.o`（1 处）（等共 10 个存档）。

## 巫师命令不带参数时对 0 调用 efun（2026-10-21，KB 06 §7.336）

巫师（管理员）把命令敲成不带参数时，驱动把 0 传给字符串参数；下面的命令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`，这条指令从来没有用过。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py` 在第一处使用参数的语句前加守卫：文件自带 `int help(object me)` 的，守卫是 `if (!arg) return help(me);`（`help()` 定义在 `main()` 之后的 1 个文件补了原型 `int help(object me);`，否则编译报 `Undefined function help`）。改动（1 个文件，括号里是接住 0 的 efun）：`/cmds/wiz/test.lpc`（`present`）。加载检查 HEAD 与工作树对照，没有退步。

## `home`：模板 `/clone/misc/wizroom.lpc` 档案里没有（2026-10-21，KB 06 §7.310）

管理员扫描里 `home` 报 `Bad argument 1 to EFUN replace_string() Got: int(0)`（`cmds/imm/home.lpc` 第 30 行）：巫师还没有工作室时，`home` 从 `/clone/misc/wizroom.lpc` 读模板，把 `NAME` 换成名字写进 `/u/<id>/workroom.lpc`；本库没有这个模板，`read_file()` 答 0，第一次敲 `home` 的巫师就是系统错误。`wizroom.lpc` 是这一系的公用文件（hy3、chidi、wmkj、yxcs 等 28 个库都带，内容相同，只差换行符：“没有建造工作室的巫师的临时住处”，出口 `north` 通 `/d/wizard/wizard_room`，本库有这个房间），从 hy3 原样复制过来，加载检查通过。

## `refresh`（`retask`）：动词函数不返回 1，搬动或销毁带动作的物件时报错（2026-10-21，KB 06 §7.339）

管理员扫描里 `refresh` 在重新分布使命之后报 `Illegal to move or destruct an object (/questobj/...) defining actions from a verb function(refresh) in object(/obj/user#...) which returns zero.`：`main()` 以第二条 `message()` 结尾、没有 `return`，答 0，而 `TASK_D->init_dynamic_quest(1)` 销毁了给玩家定义过动作（`init()` 里的 `add_action`）的使命物件：驱动只在动词答非 0 时才允许这样搬动或销毁，否则它接着遍历的动作表会悬空；答 0 还会让解析器在指令做完之后再补一句“什么？”。`main()` 末尾加 `return 1;`（同系已经返回 1 的 11 个同名文件没有动）。

## `blockade` / `recover`：`data/keep` 不存在，解封之后世界仍然锁着（2026-10-21，KB 06 §7.340）

管理员扫描里 `blockade` 报 `Error copying file from /data/user/f/fluffos.o to /data/keep/fluffos, Error: No such file or directory`，随后的 `recover` 在第一个 `cp()` 上死于 `*/data/keep/fluffos: lstat failed`，来不及执行最后的 `LOGIN_D->set_madlock(0)`：封锁解不开。`data/keep/` 是运行时目录，git 克隆里没有空目录。`blockade` 在第一次写之前 `if (file_size("/data/keep") != -2) mkdir("/data/keep");`（`mkdir()` 失败答 0，不抛错），`recover` 对没有保存档的玩家 `if (file_size(src) < 0) continue;`，其余照常恢复、照常解锁（`scripts/lpc_fix_keep_dir.py`，hy5 上实测：没有保存档时 `recover` 答“时空解封完毕”，`blockade` 建出 `data/keep` 并保存，`recover` 取回并删除）。改动（2 个文件）：`/cmds/arch/blockade.lpc`、`/cmds/arch/recover.lpc`。

## 瓦耳拉齐 `ask_back`：送回去的是没赋值的 `ob`（2026-10-21，KB 06 §7.348）

带着地图问“回去”时 `ob->move(__DIR__ "entrance")`：`ob` 没赋值，路径也错成了 `/d/gaochang/npc/entrance`。xkx100 的原文是 `me->move("/d/gaochang/entrance");`，照改，去掉 `object ob;`。改动：`/d/gaochang/npc/wuaer.lpc`。

## 妙手回春 `valid_learn()`：先读 `ob->query_temp("weapon")` 再给 `ob` 赋值（2026-10-21，KB 06 §7.348）

学这门暗器技能时 `valid_learn()` 第一个武器检查读的是没赋值的 `ob`，`xue` / `learn` 在这里抛错；后面 `ob = me->query_temp("weapon")` 的检查才是对的。有两种写法：`if (!ob->query_temp("weapon"))` 改成 `me->query_temp("weapon")`；`if ((string)ob->query_temp("weapon") != "银针")`（拿一个对象和字符串比较，永远不等，补上 `ob` 之后这门技能也学不成）改成后一种写法里的 `!objectp(ob = me->query_temp("weapon")) || !(ob->id("yin zhen") || ob->id("yinzhen"))`。改动：`/d/hxsd/pingan/shenzhen/skills/miaoshouhuichun.lpc`、`/d/pingan/pingan/shenzhen/skills/miaoshouhuichun.lpc`、`/d/pingan/shenzhen/skills/miaoshouhuichun.lpc`。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 17 条注册（7 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/d/city/leitai.lpc`（`do_quit`）、`/d/city4/qishi.lpc`（`do_pass`、`do_resign`）、`/d/hxsd/pingan/npc/sighmoon.lpc`（`do_vendor_list`）、`/d/mr/shuichi.lpc`（`do_strike`）、`/d/pingan/npc/sighmoon.lpc`（`do_vendor_list`）、`/d/pingan/pingan/npc/sighmoon.lpc`（`do_vendor_list`）、`/inherit/misc/fboard.lpc`（`do_list`）。最多的函数名：`do_quit` 9 处、`do_vendor_list` 3 处、`do_strike` 2 处、`do_pass` 1 处、`do_resign` 1 处。

## 对象路径里的 `..`：`new(__DIR__ "../obj/x")` 报 `Read access denied`（2026-10-22，KB 06 §7.351）

`__DIR__` 是当前文件所在目录（带结尾斜杠），`__DIR__ "../obj/x"` 就是 `/d/zhiye/npc/../obj/x`；驱动的 `legal_path()` 不接受带 `..` 的路径，`new()` / `load_object()` 直接抛 `*Read access denied.`（实测，`find_object()` 对它答 0）。走库自己的 `carry_object()` / 房间 `objects` 表的路径，库的基类会先规范化，能用；直接把路径交给 `new()` / `clone_object()` / `load_object()` / `move()` 的不行，调用到那一步才报错。改成规范化后的绝对路径（`scripts/lpc_fix_dotdot_dir.py --direct`）：`/d/wudang/npc/xiaocui.lpc`（`__DIR__ "../obj/nuerxiang"` → `"/d/wudang/obj/nuerxiang"`）。

## 调用了、但这个库自己的守护进程里没有的函数（2026-10-22，KB 06 §7.354）

`MACRO->函数()` 调用的函数在这个库的守护进程里不存在：`call_other()` 对不存在的函数不报错、只返回 0，所以这些功能（时间显示、昼夜事件、名字检查、价格文字……）一直没起作用。同一血统另一个库的同名守护进程里有这些函数，原文照抄到本库守护进程末尾（`scripts/lpc_port_function.py`；调用处传的参数个数、函数体用到的函数 / 全局变量 / 宏 / 字符串键都在本库里有，已核对；守护进程在 HEAD 和工作区都能加载，每个函数用固定参数各调用一次：HEAD 返回 0，现在返回正常的值）：`/adm/daemons/chinesed.lpc` ← aoxiangtianji：`chinese_month()`（4 处调用）；`/adm/daemons/chinesed.lpc` ← fengyun434：`check_control()`（1 处调用）、`check_length()`（5 处调用）、`check_return()`（1 处调用）、`check_space()`（1 处调用）、`check_chinese()`（1 处调用）。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 还剩 4 个函数没有补（item_desc 3, other 1）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/cmds/imm/help2.lpc`:`confirm_l_choice`、`/d/city/ximenroad.lpc`:`look_gaoshi`、`/d/gaochang/zoulang2.lpc`:`look_writing`、`/d/gaochang/zoulang_1.lpc`:`look_writing`。 另有 1 处函数体被作者整段注释掉（指针没跟着删），是有意关掉的，没动。

## 读不到的留言板：`"/clone/board/x"->foo();` 在 `create()` 里报错（2026-10-22，KB 06 §7.357）

xkx 系的房间在 `setup()` 之后写 `"/clone/board/gaibang_r"->foo();` 来加载留言板（`foo()` 本来就没有定义，只为了触发加载）。这个库没有这个文件，`call_other()` 报 `*call_other() couldn't find object '/clone/board/gaibang_r'`，对象留在内存里、`load_object()` 却抛错：玩家第一次走进房间就看到错误，写在 `create()` 中间的还会切掉后半段。`scripts/lpc_fix_missing_foo.py` 把 1 条单独成行的语句（`/clone/board/jail_b`；`/d/city2/jail.lpc`）注释掉并写明原因（别的房间里同样的语句本来就是作者自己注释掉的）。证明和 45 个库的整体加载检查见 KB 06 §7.357。

## `(: 函数名 :)` 指针指向本库没有的函数：只含这个指针的行加了注释（2026-10-22，KB 06 §7.355 补充）

`inquiry` / `item_desc` / `chat_msg*` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：用到时（`ask`、`look`、NPC 闲聊）驱动抛 `*Undefined lfun pointer called: 函数名`，这一拍心跳的后半段被跳过。这些函数没有可以补回的来源（别的库同一路径的文件里没有，或者它还要用本库没有的东西），所以 4 个文件里 4 行只含这个指针的行（`"gaoshi": (: look_gaoshi :),` `"高昌迷宫": (: ask_gaochang :),` `"writing": (: look_writing :),`）加了注释，原文保留并写明原因，这一项当作没有这个话题 / 物品 / 闲聊条目（`scripts/lpc_fix_dangling_lfun.py`；`#include` 的文件在库里缺失的对象、指针不在整行上的写法没动）。 前提（`function_exists()`）和加载检查（HEAD 与工作区对比，本库改动的 `.lpc` 文件）的结果见 KB 06 §7.355：没有一个回归。
