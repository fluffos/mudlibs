
## WASM 修复摘要（迁移自 meta.json 的 group_note）

和 138 号 zxty 一样是再现天涯，是 2008 年的修改重新发布版本——master.lpc 内容不同，没有精确哈希匹配，但标题/血统相同；完成了一次中断的转档；重新实现了 efun::tail()（§6.2）；启动干净。完整 WASM 修复：给 band.lpc 加了本地回环放行（这个血统会封禁任何不能严格解析成 4 段点分十进制的地址）；修复了 logind.lpc（create()/make_body()）里同样的因为多余 seteuid(getuid()) 而把 euid 重置掉的 bug；修复了 check_legal_name() 过时的 GBK 字节长度界限，去掉了 i%2==0 的字节配对门槛；修复了 named.lpc 的 invalid_new_name() 拒绝单字名字的问题，以及它按字节步进的近似重复名字滑动窗口（重写成按字符步进，和 nt1 的 named.lpc 是同一个 bug 同一种修法——这个血统和 NT/nitan 家族共享 named.lpc/注册房间设计，不只是和 jym 共享）；给 securityd.lpc 的 get_status() 加上了防御性保护（mapp/arrayp 检查，虽然没有实际观察到重入，但这是廉价的保险）。管理员账号通过纯文本的 /adm/etc/wizlist 档案播种（这个血统的 securityd.lpc 每次启动都会直接读取它，不涉及存档档案）。注册到进入游戏世界、look/score/quit（quit 会正确触发这个血统自己的 30 分钟防滥用确认提示，不是 bug），以及管理员身份识别（"您目前权限：(admin)"）都已干净验证。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 101 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（2026-08-13，round two，新驱动重测）

针对驱动升级（`quest_times`/`win_times` `%`-operator 修复 + Warning/warning
大小写回退兼容）做的重测，同时也是这份档案第一次真正的 §10.7 深
度游玩测试。这份档案是同一"再现天涯"血统里 `zxty`（本轮刚做完深挖）
的 2008 年重发布变体——master.lpc 内容不同（没有精确哈希匹配），
但独立核实后发现了几乎一模一样的一整套 bug 形状，说明这些问题在
分叉之前就已经存在于共同祖先里。

### 发现并修复的 PROGRAMMING bug

1. **`log_error()`（`adm/obj/master.lpc`，实际生效的 master
   file）的两条并行回显分支都没有严重度检查**：`if
   (this_player(1)) efun::write(...)` 和 `else if (this_player())
   tell_object(...)`——和 `zxty` 完全相同的双分支形状，这次一次性
   把两条分支都包进 `strsrch(message, "arning:") == -1` 判断。
2. **`log_file()`（`adm/simul_efun/file.lpc`）本身缺少
   `assure_file()` 保护**：已加上前向声明 +
   `assure_file(LOG_DIR + file);`。
3. **`cat()`（同一文件）两处 `write_file("/log/file/{cat,bugcat}",
   ...)` 同样缺少 `assure_file()` 保护，且 `read_file()` 结果没有
   类型检查**：和 `zxty` 一样确认过 `cat(MOTD)` 调用者是
   `/adm/daemons/logind`，两处 `write_file()` 都显式排除了这个调
   用者，本身不会导致"每次登录必崩"，但玩家/巫师直接用 `cat` 指令
   仍会命中。已加上 `assure_file()` 并把 `write(str1)` 改成
   `write(str1 || "")`。
4. **`feature/dbase.lpc`（真正生效的 F_DBASE）的密码写保护是
   tybxjh/wlhd/zxty 那一类已确认的 bug 形状**：`wizhood()` 纯粹读
   `wizlist` 文件，不检查密码是否已经真正存在于 `dbase` 里。已加
   上 `mapp(dbase) && dbase[prop]`。（`u/zjb/` 目录下三份死代码副
   本有相同形状，未改动，无任何引用指向它们。）
5. **§8.9 食物/饮水初始化判断的对象错了**：`adm/daemons/
   logind.lpc` 的 `enter_world()` 里 `ob->query("age") == 14`（应为
   `user`）。已改成 `user->query("age") == 14`。
6. **`get_resp()`/`get_name()`（`adm/daemons/logind.lpc`）各有一处
   调试残留 `printf("%O\n", ob)`（AGENTS.md §7.34-class）**：紧跟
   在中文名字确认之后，把连线桩物件的原始引用直接回显给正在注册
   的新玩家。已删除两处。

### Proactive checks / 观察记录

- `win_times` 的 `%`-operator 修复确认存在且正确：
  `d/city2/npc/refereew.lpc:146` 已用 `to_int(query("win_times")) %
  5`。
- **同一个 `wzd_log.lpc` 巫师算术验证码机制，行为和 `zxty` 一
  致**：`adm/daemons/wzd_log.lpc` 存在且真正被 `logind.lpc` 呼叫
  （不是死代码）。用 `scripts/mudclient.py` 连续快速重连时触发了
  这个挑战（随机数字+隐藏公式答案，答错干净断线，不崩溃）；改用一
  个独立的裸 socket 脚本单独测试时完全没有触发，直接成功登录并显
  示"您目前权限：(admin)"——和 `zxty` 观察到的间歇性触发模式完全
  一致，同属"连线时序相关，不产生真正程序错误"的既有现象，未修
  改。

### 实测过程

管理员 `fluffos`（管理密码 `AdminMud@2026`，普通密码
`Mud@2026`，`adm/etc/wizlist` 早已播种但从未真正注册过）用完整双
密码注册流程创建，落地"铁枪庙"，`score` 显示"【天界总管】"头衔，
食物/饮水满格。随后用独立裸 socket 脚本做了真实断线重连+密码验
证：成功登录，`(admin)` 权限确认，存档数据一致。全程 `debug.log`
无运行时错误。驱动按精确 PID 结束；管理员存档已提交。

## AGENTS.md §7.100 fix (2026-08-19): redundant replace_program(ROOM) landmine

Same corpus-wide bug as the batch-1-6 sweep (`ROOM` macro
`"/inherit/room/room"` from `include/globals.h`). Deleted 2,323 live
standalone `replace_program(ROOM);` lines under `work/` via
`fix_710_room.py`, plus hand-fixed both room-building tool copies'
string-builder template (`work/clone/misc/roommaker.lpc`,
`work/u/landy/obj/roommaker.lpc`). 3 real `.lpc` files under
`work/data/` checked — none had the bug pattern. Remaining matches
after the fix are all pre-existing `//`-commented.

Verified: clean `build-debug` boot (zero new compile errors, zero
"cannot replace"/"cannot bind" in `debug.log`), live admin login
(`fluffos`/`Mud@2026`) into 铁枪庙, `look`/`score`/`quit` all worked
cleanly. Same sibling-lineage quirk as `wlhd`/`tybxjh`: `quit` deleted
`data/login/f/fluffos.o` even though it had just been used to log in
— reverted via `git checkout HEAD -- work/data` before committing,
unrelated to this fix and out of scope.

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

## 深度功能测试（2026-09-03，round three，shop + 拜师）

新角度：醉仙楼购物 + 丐帮左全拜师，并核对重连后门派是否还在。

### 实测过程

管理员 `fluffos` / 普通密码 `Mud@2026`（本次未走管理密码）。落地
`/d/city/wumiao`。`goto /d/city/zuixianlou`，店小二 `list` 价目为铜钱
尺度（烤鸡腿八十文钱）。`clone /clone/money/gold` 后 `buy jitui` 成功
（找零九十九两银子 + 二十个铜板）。`goto /d/gaibang/inhole`，
`apprentice zuo`：左全收徒，`score` 称谓「丐帮第二十代弟子」、师傅
左全。显式 `save` 成功。

`quit` 仍走 `mud_age < 1800` 的删档分支（`cmds/usr/quit.lpc` 只在
三次确认提示上豁免巫师，真正 `rm` login/user 存档时没有
`wizardp()` 判断）——和 `zxty`/`wlhd`/`tybxjh` 同一既有政策，未改。
本轮在 `quit` 之前已经 `save`，`user.o` 里的 `family` 还在；被删掉
的是 `login.o`（从 git 还原后重连）。重连 `score` 仍是丐帮第二十代
弟子 / 师傅左全，银子还在；烤鸡腿不存档（食物 `no_save`）。本轮
`wzd_log` 验证码在有残留身体时触发过一次，按显示六位里第 2–5 位
算 `(n1*n4+8)*100+n2*n3-3` 通过，公式和 2026-08-13 记录一致。

本血统 `feature/dealer.lpc` 没有丐帮「穷叫化」拒绝（和 xyzx 家族
不同），拜师前后都能买。

### 发现并修复的 PROGRAMMING bug

1. **`exert_function(10)` 类型错误，4 处**（和 `zxty` 2026-08-13 已
   修的那一组相同，这份 08 年修改版当时漏了）：
   `d/daniel/saveme.lpc`、`d/player/ltsh/npc/saveme.lpc`、
   `d/zjb/shengji.lpc`、`u/zjb/hlxy/zs.lpc`。`exert_function` 要
   string，传入 int 则编译失败。武庙 `objects` 里写了
   `"/d/daniel/saveme"`，所以每次登陆武庙都会
   `Bad type for argument 1 of exert_function (string vs int)`，NPC
   进不来房间。已按 `zxty` 同样办法删掉这行死代码。修复后武庙
   `look` 出现「清神 大魔道士--雅薇丝」。

2. **`securityd.lpc` `valid_read()` 里对 `/log/` 的拒绝会
   `log_file("file/bug_read")`，而 `log_file` 自己又要
   `valid_read(/log/...)`**——非 `zmud`/`landy` 的巫师（包括
   `fluffos` admin）每次登陆写 usage 日志、以及 `clone` 碰到
   `/log/` 时，都会 `Too deep recursion`（报在
   `sscanf(base_name(user), ...)` 那一行）并刷几十行「警告：你不能
   操作这些目录下的文件。」。加了 `in_valid_read` 重入保护：第一次
   拒绝仍写一条警告并记 log，再入直接 `return 0`。修复后登陆只剩
   两行警告（`log_file("usage")` / `log_file("USAGE")` 各一次），
   `clone /clone/money/gold` 一行警告、黄金复制成功，不再 recursion。

### 观察（未改）

- `quit` 对 `mud_age < 1800` 的巫师同样删 `login.o`：确认提示有
  `!wizardp()` 豁免，真正 `rm` 没有。与先前 §7.100 记录的「quit
  删掉刚登录用的 login.o」是同一形状，当既有政策留下。
- 本轮 `feature/dealer.lpc` 无丐帮购买拒绝。
- 驱动 `log/debug.log`（`cd libs/zxty08nxgbb && driver` 打开在
  chdir 之前）是本轮 live 日志；mudlib `error_handler` 写
  `work/log/debug.log`。修复后的那次 boot 后者没有新的执行时段
  错误。

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 2 here-document block(s) repaired (2 with the terminator glued to the last text line, 0 with it indented), so `End of file in text block` no longer hides the room or object behind them: `d/quanzhen/manglin1.lpc`, `d/quanzhen/manglin2.lpc`. The terminator must start its line (the lexer's own test, KB 04 §6.10); a glued one lost its newline in the GBK -> UTF-8 conversion together with a half character, which stays out.

## 深度功能测试（§10.7，2026-10-05）— 任务表里的 `.c` 路径与任务守护进程的防护

`scripts/lpc_dynamic_rows.py`：`d/obj/quest/dynamic_location`、`d/obj/quest/dynamic_quest` 里 86 行写的是原档案的 `.c` 路径。转档时文件已改名 `.lpc`，而显式后缀按原样解析，`load_object("/d/x.c")`、`new("/d/obj/quest/x.c")` 返回 0 且不报错（KB 03 §4.2，KB 06 §7.220），所以 `adm/daemons/questd.lpc` 读到的每一行都加载不出来：随机任务和任务物品从未生成，在 `create()` 里直接对结果调用 `tar->set()` 的版本还会崩溃，连带加载它的 cron 守护进程和 `give` 的任务钩子。这些行已改为 `.lpc`；另有 1 行指向的文件两种后缀都不存在（档案缺内容），保持原样。
`scripts/lpc_dynamic_quest_guard.py`：1 处 `spread_quest()` 调用（`init_dynamic_quest()` 的循环里）包进 `catch()`，缺失的任务物品或编译不过的房间只跳过那一个任务，守护进程照常加载、其余任务照常生成。
验证：`adm/daemons/questd.lpc`和 cron 守护进程在新进程里加载（HEAD 一次，工作树三次，选房是随机的）：HEAD 通过 1 个，工作树三次分别通过 1、1、1 个（共 2 个），无回退；`adm/daemons/cron.lpc` 在 HEAD 与工作树都加载失败，另有原因，与本次无关。

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `inherit/room/room.lpc`：`make_inventory()` 用 `catch()` 包住 `new(file)`，做不出来就返回 0；`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）；`reset()` 的 `default:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]][j])) continue;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-07）— 空的 `if (current_water == 0) {}`

5 个房间的 `valid_leave()` 里有一行什么也不做的 `if (current_water == 0) {}`（编译警告 `Expression has no side effects`），删去，行为不变：`d/gaochang/room11.lpc`、`d/gaochang/room12.lpc`、`d/gaochang/room13.lpc`、`d/gaochang/room14.lpc`、`d/xingxiu/shanjiao.lpc`。

## 深度功能测试（§10.7，2026-10-07）— 编译警告整理

`scripts/lpc_warnings.py zxty08nxgbb --fix` 加 `scripts/lpc_fix_no_effect.py --apply`（`adm/daemons/wzd_log.lpc` 的 `for (i == 0; ...)` 改成 `=` 等），共改动 757 个 `.lpc` 和若干 `.h`。HEAD 与工作树分别加载（新进程）：693 -> 693 通过，无回退；改过的头文件的 86 个包含者 69 -> 69 通过。`d/feitian/npc/xunbu.lpc` 的 `(: random_move() :);` 只造函数指针不调用，属内容设计，未动。

启动时警告 29 -> 0；新进程登录（新人物确认）正常。

## 深度功能测试（§10.7，2026-10-08）— `.lpc` 后缀的定宽切片

`.c` 改名 `.lpc` 时只改了字符串没改切片宽度：`f[<2..] == ".lpc"` 拿两个字符比四个字符，永远不成立（`!=` 永远成立），按后缀筛文件、去后缀的代码因此从不运行或截成 `x.l`（KB 06 §7.238）。`scripts/lpc_lpc_suffix_slice.py --apply` 改了 2 处比较、0 处去后缀（如 `cmds/app/lp2.lpc`）；改动的文件 HEAD 与工作树分别加载（新进程），无回退。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 10 处，返回类型/原型 25 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 0 个，只在 #if 分支用的声明移进分支 1 个文件；改动 36 个文件，HEAD 与工作树各载入一次无回退（36 objects; HEAD PASS 36, tree PASS 36; regress 0; newly loading 0），这些文件的警告 36 -> 0。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查

- `d/*/npc/xunbu.lpc` 巡捕：`(: random_move() :);` 只造了一个函数指针就丢掉，巡捕从不走动；改为 `random_move();`。
- 改动的对象 HEAD 与工作区都能载入，无回退。

- 2026-10-12：`clone/npc/obj/xiang.lpc` 写着 `int remove() { save(); }`，盖掉了 `feature/move.lpc` 的 `remove(string euid)`——这些存盘箱子/柜子被销毁时不从携带者身上减负重、不清 handing（KB 06 §7.239 变体，nitan_ceshi/tianxiawuxue 同类）。改成 `varargs void remove(string euid) { save(); ::remove(euid); }`。HEAD 与工作树各载入一次，regress 0（载不进的文件在 HEAD 就载不进）。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。1 个文件 1 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。
- 2026-10-14：技能文件里 `int power_point()`/`int hard_point()` 返回 1.5、1.75 之类的浮点，经 int 返回被截断；本库没有调用者（练功走 `practice_bonus`/`learn_bonus`），改成 `float` 返回值，保留原数值。
- 2026-10-14：同一次重扫的其余 15 条：`adm/daemons/poistiond.lpc` 的 `varargs int remove() { save(); return 1; }` 取代了 F_MOVE 的 `remove()`（负重扣减从不执行），改为存盘后调用 `::remove(euid)`；`d/daniel/job/peng/peng.lpc` 的原型 `string ask_fail();` 与同目录 `dojob.lpc` 的 `int ask_fail()` 不符（原型抄自另一份 dojob），改 `int`；`beastseller` 的 `attempt_apprentice` 改 `void`（拜师指令不读返回值）；4 个文件在 NPC 基类已有的情况下又 `inherit F_CLEAN_UP`，删去；`xingchen` 写明 `clean_up()` 胜出者；`MAX` 宏重定义前加 `#undef`；`huashan-jian.lpc` 多余的 `;`、`u/huoji.lpc` 注释里残留的 `/*`。改动的 17 个对象新进程各载入一次，无回退。

- 2026-10-15：`kungfu/skill/guangming-blade.lpc`（光明刀法）是从五虎断门刀抄来的，`query_action()` 里仍按 `wuhu-duanmendao` 的等级挑招式：没练五虎断门刀的人出招时一招都匹配不上，`a_action` 为 0，接着赋值报错。改为按 `guangming-blade` 自己的等级。（武功运行期探针发现。）

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。3 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。


## 东方故事/西游记体系的技能文件（2026-10-15，KB 06 §7.241 第三类）

这些 `kungfu/skill` 文件来自 gin/kee/sen/force 体系，本库人物只有 jing/qi/neili：`receive_damage("kee", 30)` 报 `伤害种类错误`，`query("force")` 永远为 0，技能学不了也练不了。按 kee→qi、gin/sen→jing、force→neili、max_force→max_neili、force_factor→jiali 改了属性名（`scripts/lpc_port_es_props.py`），共 1 个文件。

## 治疗/疗伤的属性名（2026-10-15，KB 06 §7.241）

`receive_heal()`/`receive_curing()` 也只接受本库的种类。5 个文件（多为只调用 `receive_heal`/`receive_curing` 的药物、NPC）来自其他体系，按本库的属性名改名（`scripts/lpc_port_es_props.py --any-file`）。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。4 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。


## 技能按另一门武功的等级取招（2026-10-15，KB 06 §7.243）

这些技能文件是从别的武功复制改名来的，`query_action()` 仍用原武功的等级查招式表：只会本技能的人等级为 0，取不到招，每次出招都报错。改为读本技能自己的等级（`scripts/lpc_fix_action_level.py`）：`kuihua-dafa`、`quanzhen-jian`、`wugong-zhao`。


## `->query_(` 笔误（2026-10-15，KB 06 §7.245）

调用不存在的函数 `query_`，call_other 静默返回 0，相关判断永远按 0 计算。改为 `->query(`：`zidian-jianfa`。

## 把经验、属性、内力当技能读（2026-10-15，KB 06 §7.247）

经验、属性、内力上限不是技能，xkx/ES 的 `query_skill()` 对它们只返回 0（风云的还会去载入同名技能文件而报错）。改为 `query("...")`（`scripts/lpc_fix_pool_as_skill.py`）：`/quest/quest2/jinyong`、`/quest2/jinyong`、`/quest2/jinyong/jinyong`、`/quest2/quest2/jinyong` 生成的任务怪物照抄玩家福缘（`set("kar", who->query_skill("kar"))`，怪物福缘一直为 0）。

当前内力、精这类名字有时指的是内功技能，逐处读过后手改：`lengquan-shengong` 的 `ob_hit()` 用 `query_skill("neili")` 比较双方内力，恒为 0 对 0，只会走“化去一部分”的分支，改为 `query("neili")`；落英缤纷 `luoying-shenjian/lybf`：自己的注释说成功率由“精神高低”决定，两处 `query_skill("jing")` 改为 `query("jing")`。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`beimin-shengong`→`beiming-shengong`（`tiangang-zhengqi`、`wangran-xinfa`、`xiantian-gong`）；`douzhuan-xignyi`→`douzhuan-xingyi`（`/d/mr/npc/obj/shu1`、`/d/mr/obj/shu1`）；`palm-sword`→`plam-sword`（`hand-blade`、`plam-sword`）；`jinwu-dao`→`jinwu-daofa`（`jinwu-daofa`）；`miaojia-jian`→`miaojia-jianfa`（`miaojia-jianfa/miehun`）；`mizongxinfa`→`mizong-xinfa`（`longxiang/fanchang`）；`yihua-jimu`→`yihua-jiemu`（`yihua-jiemu`）；`yunv-xinjing`→`yunu-xinjing`（`wangran-xinfa`）；`zhenfen-xinfa`→`zhenfeng-xinfa`（`zfwy-bu`）。

## 技能名拼错：技能文件里拼错自己的名字（2026-10-15，KB 06 §7.249）

技能自己的文件（或它的绝招目录）里，`query_skill()` 读的是差一个字母的自己的名字，永远得 0：“基本功夫要高过本技能”之类的限制从不生效，按等级取招、计算伤害的那一项一直是 0。改为本技能的名字（`scripts/lpc_fix_skill_typo.py` 的 self 判据）：`hujian-daofa`→`hujia-daofa`（`hujia-daofa`）；`jinggang-quan`→`jingang-quan`（`jingang-quan`）。

## family 映射内联取下标（2026-10-15，KB 05 §7.30）

`ob->query("family")["master_name"]`、`me->query("family")["family_name"]`（泥潭式为 `query("family", ob)[...]`）直接对门派映射取下标：没有门派的人（新玩家、叛师者、大多数 NPC）在 NPC 的打招呼和问话、绝招的门派判断、房间的 `valid_leave` 里报 `Value being indexed is zero`，而不是得到拒绝。6 处（5 个文件）改为 dbase 路径查询 `query("family/master_name")`：有门派时值相同，没有时得 0；原有的判断照常生效（`scripts/lpc_fix_family_index.py`）。给映射赋值的写法未动。


## 用兵器的绝招空手施展时报错（内联写法）（2026-10-15，KB 06 §7.246）

绝招不存兵器变量，直接写 `(me->query_temp("weapon"))->query("name")`（或在拒绝判断里写 `(weapon = me->query_temp("weapon"))->query("skill_type")`），之前又没检查兵器：空手 `perform` 时报 `Bad argument 1 to EFUN call_other()`，内力等往往已经扣掉。在第一次用到它的那条语句前补上“你必须手持兵器才能使用这一招”的拒绝（`scripts/lpc_fix_perform_weapon.py`）：`yunu-jianfa/suxin`。


## 存档读不出来：字符串里的换行、空行（2026-10-15，KB 03 §4.4）

`d/city/obj/bingqipu.o`：字符串里有原样的换行（`save_object()` 存成 `\r`，`restore_object()` 逐行读，原样的换行让字符串收不了尾），或有空行（`Illegal file format`），读档的对象（留言板、NPC、玩家）从空白开始。换行改写成 `\r`、删去空行（`scripts/lpc_save_encoding.py --from-raw`），驱动核对全部能读回（`scripts/lpc_save_restore_check.py`）。

## 移进不存在的巫师房间（2026-10-15，KB 06 §7.251）

用完的物品、要“离开”的 NPC、掷在空中的兵器被移进巫师的工作室（`/u/llm/`、`/u/wind/`），本库没有这些房间。本库的 `move()` 用 `load_object()` 找目的地，找不到就返回 0，不报错，东西留在原处：被雇来打晕或杀人的李凌（`d/city2/npc/liling2`）办完事后没有离开，留在原地；婚礼结束（`d/nanyang/npc/meipo` 的 `last_marry`）时月老没有离开喜堂，每办一次婚礼喜堂里就多一个月老；喜宴结束后喜来福（`d/nanyang/npc/xi-laifu`）没有退回内堂，每办一次婚礼迎宾楼就多一个喜来福。3 个文件改为移进本库的虚空房间 `VOID_OB`（`/clone/misc/void`），与原作把它们“停放”在巫师房间的用意相同（haiyang2 的维护者把月老送进 `/d/city/empty`，也是同样的做法）。

## 死神刀「死神锁」命中时报错（2026-10-15，KB 06 §7.246）

命中时要把对方的兵器震飞，用的 `weapon2` 却从未赋值：每次命中都在扣完内力后报错。改为当场取对方的兵器；对方空手就只有“人也彻底崩溃了”那半句。


## 弹指神通「漫天花雨」每次报错（2026-10-15，KB 06 §7.246）

绝招声明了 `object weapon;` 却从不赋值，接着就 `weapon->query_amount()` 数暗器：每次使用都报错。补上取兵器的判断，手里没有暗器时拒绝（“你手中没有暗器”）。


## 玉女剑法「合壁」用一次就永久改动经验和剑法（2026-10-15，KB 06 §7.253）

收尾的 `hebi()` 声明时没有参数（`void hebi() { object me, target, env; int i, j, o, p, count; ...`），call_out 传进去的人和数值全被同名的局部变量（0）挡住，开头的 `if (!me && !target) return;` 每次都返回：合壁的攻击、闪避加成和 `hebi` 标记要到重新登录才消失。更糟的是夫妻判断写成了 `target->querry("id")`（没有这个函数，得 0），没成亲的人 `marry/id` 也是 0，于是人人都被当成夫妻：自己的玉女剑法和经验乘以玉女素心功的级数/80（至少变成浮点数，160 级以上翻倍），随后给对方 `set_skill("combat_exp", ...)` 时报 `No such skill`，收尾的 call_out 也就没排上，乘过的等级和经验永远不还原。测试里用一次合壁，经验 100000 变成 200000.0、剑法 100 变成 200.0。改正：`hebi()` 按它自己再次 call_out 时传的八个参数声明，`perform` 的 call_out 去掉多余的 `h, k`，`querry` 改为 `query`，给对方的 `set_skill("combat_exp")` 改为与上一行一样的 `set("combat_exp")`。测试里加成照常生效，`hebi()` 结束时还原并清除标记，没成亲的人经验和剑法不变。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

6 个文件、10 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/jyquest/sword`、`/jyquest/armor`、`/obj/cloth/cloth`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 3 个，改后 6 个（3 个原来载入不了），没有退步。

## 物品清单把名字的第一个字吃掉（2026-10-18，KB 07 §8.1）

`inventory`、房间的物品列表（`feature/move`）和部分 `look` 把同名物品合并计数，键是 `query("unit") + short()`，只有一件时按 `key[2..]` 去掉量词。量词是一个汉字，在原来的 GBK 里占 2 字节，`[2..]` 正好去掉量词；转成 UTF-8 以后一个汉字只占一个下标，这一刀把名字的第一个字也切掉了（「把长剑」只显示「剑」，带颜色的名字切掉的是转义序列开头）。改为 `[1..]`（`scripts/lpc_fix_unit_cut.py`）：`cmds/std/sssinventory.lpc`、`feature/move.lpc`。

## 去掉的预定义宏 `SAVE_EXTENSION`（2026-10-18，KB 04 §6.11）

老版 MudOS 给每个 LPC 对象预先定义了 `SAVE_EXTENSION`（`".o"`）；FluffOS 的 ChangeLog（COMPAT_BUSTER 一条）把它删了，改用 `__SAVE_EXTENSION__`。本库没有自己 `#define` 这个宏，用到它的文件一律 `Undefined variable 'SAVE_EXTENSION'`，整个对象载入不了。改成 `__SAVE_EXTENSION__`（`scripts/lpc_fix_predefined_macro.py`）：`d/quanzhou/npc/tang3.lpc`、`d/taishan/tang3.lpc`。`tang3`/`tang`/`meng-zhu` 是武林盟主一类的 NPC，原来一个都载入不了。改后用 `lpcc` 逐个载入这些对象：2 个通过。


## 水潭里 `ging_cost` 是 `jing_cost` 的笔误（2026-10-18）

`shuitan` 先算 `jing_cost`，倒水时却扣 `receive_damage("jing", ging_cost)`，`ging_cost` 从没声明过：`Undefined variable 'ging_cost'`，整个物件载入不了。改成 `jing_cost`：`d/shaolin/npc/obj/shuitan.lpc`。改后用 `lpcc` 逐个载入这些对象：1 个通过。


## 武林盟主类 NPC 的存档里 `weapon`／`armor` 是个 mapping（2026-10-18）

盟主、`fa-e`、`shang-shan`、`tang3`/`tang2`/`xingtang` 这几个 NPC 在 `create()` 里 `restore()` 之后直接 `carry_object(query("weapon"))`。换盟主时 `do_recopy()` 把玩家整个 dbase 抄进来，玩家的 `weapon` 若是自制兵器的 mapping，存进 `data/npc/*.o` 以后下次载入就是 `new(mapping)`：`Bad argument 1 to EFUN new()`，NPC 载入失败。本库的存档里确实有这种 mapping。两行都加 `stringp()` 判断，mapping 时不拿武器（NPC 空手）：`clone/npc/fa-e.lpc`、`clone/npc/meng-zhu.lpc`、`clone/npc/shang-shan.lpc`、`d/quanzhou/npc/tang3.lpc`、`d/taishan/tang2.lpc`、`d/taishan/tang3.lpc`、`d/taishan/xingtang.lpc`。改后用 `lpcc` 逐个载入这些对象：7 个通过。

## 补回丢掉的基类宏（2026-10-18，KB 04 §6.13）

`inherit F_XXX;` 里的宏本库任何头文件都没有定义，报 `syntax error, unexpected L_IDENTIFIER, expecting L_STRING or '('`，整个对象载入不了；宏指向的基类文件本库其实有，别的库都把这个宏定义成同一个路径。在全局头文件 `include/globals.h` 里补上：`BUILD_ROOM` → `/inherit/room/buildroom`（20 个文件）、`STICK` → `/inherit/weapon/stick`（3 个文件）、`F_GUARDER` → `/feature/guarder`（3 个文件）。（`scripts/lpc_restore_macros.py`）改后用 `lpcc` 逐个载入这些对象：26 个里 23 个通过，其余 3 个还有别的错误（`clone/unique/kusang-bang.lpc`：Unable to find the inherited function 'create'.；`clone/unique/yuzhu-zhang.lpc`：Unable to find the inherited function 'create'.；`d/room/roomnpc/laopu.lpc`：Unable to find the inherited function 'accept_hit'.）。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 3 个对象设了本库没有文件的武功（5 个名字，最多的是 `hunyuan-force`、`ruyi-blade`、`taxue-steps`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：3 个里 2 个通过，其余 1 个停在别的错误上（`d/room/roomnpc/laopu`：*No program in object '/d/room/roomnpc/laopu'!）。（`scripts/lpc_guard_set_skill.py`）

## 补回本库没有的基类文件（2026-10-18，KB 04 §6.15）

下面这些基类本库没有，继承它们的对象（房间、NPC、物品）整批载入不了（`inherit XXX;` 的宏没定义，或者 `inherit "/std/…";` 的文件不在）。同系的库里有同名文件，两库有大量逐字节相同的文件（亲缘关系），所以从那边原样拷来，缺的宏补进全局头文件：`/clone/fam/gift/gift`←wxddym，2 个对象继承它，抽样 2/2 载入。每个基类补回后单独载入、再抽样载入使用它的对象，基类载不进来或者一个用户也载不进来的就撤掉（本库撤掉了它们，不再补）。（`scripts/lpc_restore_bases.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 19 处、16 个文件：`yan-fly`→`yanfly`（3 处）、`yijin-jing`→`yijinjing`（3 处）、`xinxiu-duzhang`→`xingxiu-duzhang`（2 处）、`tiaji-jian`→`taiji-jian`（2 处）、`kongmingquan`→`kongming-quan`（2 处）、`taiji-shenfong`→`taiji-shengong`（2 处）、`lingbo-weibu`→`lingboweibu`（2 处）、`poyu-qua`→`poyu-quan`（1 处）等共 10 个名字。（`scripts/lpc_fix_skill_names.py`）

## 调用了父类没有的函数的对象（2026-10-19，KB 06 §7.259）

`::create();`、`::init();`、`return ::buy_object(who, item);` 这类调用写的是父类里有这个函数的版本；本库的父类没有，旧驱动把它当空操作（返回 0），现在的驱动在编译时就报 `Unable to find the inherited function`，整个对象载入不了。单独成句的调用删掉，`return ::f(...)` 改成 `return 0;`（void 函数里是 `return;`），与旧驱动的行为一致。共 20 处、19 个文件：`::create()`（17 处）、`::do_discard()`（1 处）、`::accept_hit()`（1 处）、`::accept_kill()`（1 处）。只改了出错原因全是这一类的文件；还带着别的错误（多半是父类本身没了）的文件没动，等父类补回后再看。（`scripts/lpc_fix_dangling_super.py`）

## set_name 的 id 参数传成字符串（2026-10-19，KB 06 §7.260）

`set_name("海口大碗", "bowl");` 把物品的 id 写成了字符串，本库的 `set_name(string name, string *id)` 要的是数组，驱动在编译时报 `Bad type for argument 2 of set_name ( string * vs string )`，整个物件载入不了；旧驱动不检查参数类型，字符串里照样找得到这个词，物品能用 id 称呼。改成 `({ "bowl" })`，共 2 个文件：`/d/baituo/npc/obj/bowl.lpc`、`/d/baituo/obj/bowl.lpc`。（`scripts/lpc_fix_set_name_id.py`）

## feature/damage.lpc 丢了 set_ghost()（2026-10-19，KB 06 §7.262）

`feature/damage.lpc` 里有 `int ghost` 和 `is_ghost()`，没有 `set_ghost(int i)`；木人、狼等 NPC 在 `create()` 里调用它，整个 NPC 报 `Undefined function set_ghost` 载入不了。从 xkx100 补回这一行函数，受益 NPC 1 个：`d/feitian/npc/wolf`。（`scripts/lpc_transplant_function.py`）

## 全局头文件丢了 2 个宏（2026-10-19，KB 04 §6.16）

`/include/globals.h` 里没有定义 `F_SILENTDEST`、`LOOK_CMD`，用到它们的物件（名单里 2 个）编译时报 `Undefined variable`/`Undefined function`，整个物件载入不了（编译器在第一个未定义的名字上停下，后面的错误和警告都看不到）。同系的库在各自的头文件里都有这几行：照其中和本库共有文件最多的那个库，原样补到 `/include/globals.h` 最后一个 `#define` 之后，宏体里出现的路径在本库里都存在。补完后名单里有 2 个载入，其余还差别的东西。（`scripts/lpc_restore_defines.py`）

## 区域物件的零碎修正（2026-10-19，KB 06 §7.267–§7.271）

- 1 个 NPC 文件、1 处 `create()` 里的 `this_player()->carry_object(` 改成 `carry_object(`（没人在场时 `this_player()` 是 0，NPC 载入不了；有玩家在场时衣服武器落到玩家手里）

逐个物件与 HEAD 对比载入，没有退步。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 玩家打造兵器模板被 NPC 带上（2026-10-19，KB 06 §7.275）

`/d/npc/m_weapon/weapon/m_club.lpc`、`/d/npc/m_weapon/weapon/m_sword.lpc`、`/d/npc/m_weapon/weapon/m_sword3.lpc`（共 3 个）的 `create()` 用 `this_player()` 读打造数据（`me->query("weapon/lv")` 等）。NPC 的 `weapon` 属性是兵器文件名（字符串），NPC 在别的 NPC 的命令环境里 `carry_object()` 这个模板时，`set_desc()` 里 `switch (w_lv)` 拿到的是那个字符串，驱动报 `Bad argument 1 to switch`，房间和 NPC 都载入不了（旧驱动里 switch 落到 default）。把 `if (me) {` 改成 `if (me && mapp(me->query("weapon"))) {`，玩家打造的流程不变。

## 玩家打造兵器模板没有打造者时（2026-10-19，KB 06 §7.275）

`/d/npc/m_weapon/weapon/m_staff.lpc`、`/d/npc/m_weapon/weapon/m_whip.lpc`、`/d/quanzhen/npc/obj/m_sword.lpc`（共 3 个）的 `create()` 开头 `me = this_player();` 之后无条件读 `me->query("weapon/name")` 等打造数据。房间刷新时没有人在场（`me` 为 0），或者 NPC 在别的 NPC 的命令环境里 `carry_object()` 这个模板（NPC 的 `weapon` 属性是文件名字符串），旧驱动里读出来是 0 或字符串，`switch` 照样落到 default；新驱动报 `Bad argument 1 to EFUN call_other()` / `Bad argument 1 to switch`，NPC 和它所在的房间载入不了（`--walk` 普查里一个玩家走进房间就触发）。在 `//读入数据` 之后加 `if (!me || !mapp(me->query("weapon"))) { setup(); return; }`：没有打造者就留一个没有名字的空模板，玩家打造的流程不变。

## 被注释吞掉的语句（2026-10-19，KB 06 §7.274）

- `/d/zjb/paimai.lpc`：拍卖房的 `add("pnum",1)`（竞买者计数）被 `//归还前一个竞买者的钱` 注释吞掉，计数从不增加

`scripts/lpc_fix_swallowed_statement.py` 把换行放回去。逐个载入与 HEAD 对比，没有退步。

## 标准整理轮（2026-10-19，`scripts/toolkit_fix.sh`）

本库在新驱动下重扫，机械修复：2 处重复的 inherit。修后与 HEAD 逐个物件对比载入，没有退步。

## 手工收尾（2026-10-19，KB 04 §6.10）

- `clone/npc/magic-beast.h`：开头的 `mapping skill_map; mapping skill_prepare;` 是从 NPC 基类抄来的，头文件里的代码一次也没读过（只调用基类的 `query_skill_map()`），删掉（`Redeclaration of global variable`）。
- `d/quanzhou/npc/tang3.lpc`、`d/taishan/tang3.lpc` 的 `clean_up() inherited from both …` 只在整库扫描里出现：物件单独载入时不出现，它的四个 inherit 之间也没有第二条通往 `clean_up` 的路径；`clean_up::clean_up()` 编译不过，所以没有动，整库重扫后再看（`lpc_name_winner.py` 现在会跳过这种没有直接 inherit 的情形）。

逐个与 HEAD 对比载入，没有退步。

## 补回丢失的标点（2026-10-19，KB 03 §4.6）

转换时丢掉的分号、逗号、引号或文件末尾的 `}`，共 5 个文件，修前 HEAD 载入失败。别的库里同路径的完好副本只比这里少几个标点，按它补回（括号里是那个库）：`/d/city2/npc/zhengmen.lpc`（jqxz2008）、`/d/quanzhen/hudi6.lpc`（bixiecanyang）、`/kungfu/skill/guxing-sword.lpc`（xyzx3）、`/quest/murong/qlist3.lpc`（bixiecanyang）。文件末尾少了 `}`（最后一个或两个字节丢了），补上：`/u/zjb/adm/combatd2.lpc`。修后与 HEAD 逐个对比载入：这 5 个物件全部载入，没有退步（`scripts/lpc_restore_from_twin.py`、`lpc_fix_eaten_quote.py --comma`、`lpc_fix_eof_braces.py`）。

## `== !"字符串"` 多出来的 `!`（2026-10-19，KB 06 §7.280）

`!"taoist"` 是整数 0，`x == !"taoist"` 就是“x 等于 0”，作者为其余所有人写的那一支永远走不到。具体是：龙女对古墓弟子的机关暗门提示永远给不出来（5 处）；孙婆婆的“你去吧”只对 class 没设置的人生效；性别检查（“你不是女的，无法领会其中至阴之理”）永远不拦人，男的照样能学玉女心法。全部改成 `!= "字符串"`（`scripts/lpc_fix_not_literal_cmp.py`）：`/kungfu/class/gumu/long.lpc`（5 处）、`/kungfu/class/gumu/sunpopo.lpc`（1 处）、`/kungfu/skill/yunu-xinfa.lpc`（1 处）。同样的行在 xkx 一系的 35 个库里都有。
