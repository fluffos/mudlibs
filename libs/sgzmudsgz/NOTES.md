# sgzmudsgz（三国志MUD）-- 当前 FluffOS 移植笔记

档案 `archives/145_sgzmudsgz_三国志MUDsgz.tar.gz`。嵌套树里只有
`sgz/lib` 是完整可玩 mudlib（`sgz_old` / `sgzmud` 不用）。2026-08-05
曾按「必须跟 32 位 Linux 2.0 捆绑 ELF」清出馆外；用户 2026-09-11
要求改到**当前 FluffOS**。这不是空骨架，不要造 void。

编号 **145**，端口 **40196**。手足 `sanguozhi`（162）是已经改过共享
FluffOS 的后来快照，**不能**拿 162 顶替 145。

## 驱动

不再需要 `#define ARRAY_RESERVED_WORD` / `~/src/fluffos-wilderness`。
Lima `array` 类型已改成 `mixed *` / `string *`（leftover 656），
`check_config.lpc` 的 `create()` 已掏空，`master.lpc` 补了 UID
applies。`set_this_player()` 按 sanguozhi 全部 no-op（默认驱动只在
`NO_ADD_ACTION` 分支暴露这个 efun）。

走共享默认驱动：

```
cd libs/sgzmudsgz
~/src/fluffos/build-debug/src/driver config.fluffos
```

站点 WASM 也走共享 `~/src/fluffos/build-wasm/src`，不再进
`scripts/custom_drivers/wilderness/`。`wilderness` 自己仍要那份二进制。

`config.fluffos`：`mudlib directory` 指 `work/`，`log directory : /log`
相对启动 CWD（必须 `cd libs/sgzmudsgz` 再跑 driver），
`inherit chain size : 300`，`global include file : <global.h>`。

## 转码

GB18030→UTF-8（排除 `*.tbz2` / `*.zip` / `*.exe` / `WWW.bak`）：
already_utf8=2214 converted=5461 lossy=74 skipped_binary=78，约 3546
个 `.lpc`。登录中文是干净的。

## 当前 FluffOS 上编不过 / 连不上的修法

无类型 `array` 再下标，现代驱动把元素当成 `unknown`：

- `daemons/imud/mudlist.lpc`：`array inf` → `mixed *`（否则
  `IMUD_D->query_mudlist()` 在 `real_logon()` 里直接把连线踢掉）
- `std/body.lpc` `channel_rcv_soul`、`help_d` / `soul_d` / `news_d` /
  `doc_d` / `country_d` / `area_d` / `ev_merchant/appear`：同样改成
  `mixed *`（或注释掉 `compose_message("", …)` 那行，第一参必须是
  object）
- `std/object/description.lpc`：`set_in_room_desc(mixed)`，留言板
  `(: do_desc :)` 才能编过（手足 sanguozhi §7.200）

`.c`→`.lpc` 后缀长度：`cmd_d` / `spell_d` / `quest_d` /
`troop_type_d` / `cmds/player/cmd` 的 `[0..<3]` 改 `[0..<5]`，
否则 `quit`/`help` 对不上。

`global.h` 补 `ADDR_SERVER_IP` / `ADMIN_EMAIL`（`login.lpc` 和
`secure_d` 要用）。`is_chinese()` / `valid_chinese_id()` 改 Unicode
`0x4e00–0x9fff`（§8.1）。`simul_efun/string.lpc` 的 `create()` 去掉
`nosave`，跳过 `chr(0)`。`master.lpc` `parser_error_message` 的
`array descs` → `mixed * descs`。`check_config.lpc` 的 `create()`
去掉 `nosave`。

`doc_d.lpc` 后半段 `get_dir` 类型仍编不过（preload `catch`，不挡登录）。

机械去掉 `array` 关键字时，Lima `string array a, b` 里的标量 `b`
曾被误加成 `string *`。`char_obj` 因此编不过，登录会被送去极乐世界。
已按 sanguozhi 把混写声明改回（`char_obj` / `check` / `country_d` 等）。

## 实测（本机默认 FluffOS，端口 40196）

`fluffos` / `Play2026x` / 云游。Admin 域已有历史成员，
号是凡人，进档案 `START` `/a/huayin/vhall` **草庐**：水镜先生、
大砍刀、草庐留言板。`look` / `west`（小村中心）/ `score`（云游 /
fluffos / 汉末 / 白身）/ `quit` 都通。

不要用捆绑的 `etc/driver` 32 位 ELF。不要用
`~/src/fluffos-wilderness`。

## WASM（2026-09-11 leftover 656）

共享默认 `~/src/fluffos/build-wasm/src`：`fluffos` / `Play2026x`
进草庐，`look` / `score`（云游）/ `quit` 通过。`socket.lpc` 在 WASM
下没有 socket efun（I3/HTTP），不挡登录。`doc_d` 仍编不过，preload
`catch`。

## 深度功能测试（§10.7，2026-09-13）

本轮在共享 mudlib 上另开驱动端口 **41196**（PID 4010321，本会话
拉起；**未动** 既有 40196/PID 2421649）。账号 **sgzptac** /
`Play26aa` / 测辛。

### 发现并修复

1. **`HZK2ASC_D` 在 UTF-8 库上整题崩成 `====== BUG ======`。**
   HZK16/24 点阵按 GBK 索引；转码后 `hzk2asc16/24` 失败。
   `work/daemons/hzk2asc_d.lpc`：转换失败时回退明文 `s`。
2. **厨娘砍柴交工的机器人题依赖 HZK，UTF-8 下不可答。**
   `work/sgdomain/robot/queitem.lpc`：改为明文分类题，并在
   四选一串里加 `、` 分隔。`zi.lpc`：字号题同样去掉 HZK 包装。
3. **挖地（digsoil）对象仍挂在旧 `wiz/emperor/huayin` 虚图，未接进
   已转码的 `a/huayin/*`。** 新手「ask money」也指去 digsoil——
   本轮不造房，记为已知缺口；经济切片改走砍柴。

### 游玩证据

- 登录 → 草庐 → `west`/`south`/`east`/`east`/`south` 到厨房；
  `ask chu niang about job` 领砍柴刀。
- 村西树林 `chop woods with kanchai dao`：累了会「你太累了，休息
  一会儿吧。」，歇够再砍；`i` 收到 **二十根柴火**。
- `ask chu niang about pay` → 可读机器人题 → 答对 → **十两银子**
  （答错会只给纸钱；本轮答对拿到银子）。
- 小店 `list` / `buy skin` / `buy mantou` / `eat mantou` 成交。
- `quit` 后重连：仍在草庐，身上银子/帖子等仍在。

### 日志

- 本轮 `work/log/catch` mtime 仍是 2026-09-11（无新 catch）。
- `work/log/runtime` / `log` / `logins` mtime 对应该驱动开机与本轮
  登录（2026-09-13）。`debug.log`/`execute` 按 §10.9 启动 CWD 约定，
  不把空 debug 当成干净。

Do not invent digsoil rooms. Empty numbering rows (mhxy2002/fy4/jy/
hylib/dtxy) stay confirmed duplicates.

## 深度功能测试（§10.7，2026-10-04）— 连续两次未捕获的错误会让会话哑掉

`secure/user/inputsys.lpc` 只在输入处理函数正常返回后才用 `modal_recapture()` 重新挂上 `input_to()`。处理函数里一次
未捕获的错误会跳过它，下一行输入走 `process_input()` 兜底；兜底里再出一次错，驱动（`comm.cc` 的 `process_input`）就对这条
连接永远停用 `process_input()`，之后每一行都落到普通命令解析器，只回「What?」，只有重连才能恢复。原树复现：往
`cmds/player` 放一条 `main()` 里 `int *a; a[0] = 1;` 的命令，连敲两次，再 `look`。玩家把同一条出错的命令敲两遍就会碰上。

`dispatch_modal_input()` 现在把处理函数调用和 `!` 转义都包进 `catch()`，其后照旧 `modal_recapture()`（上游 Lima 的做法）；
`error_handler()` 仍会给玩家打印错误和「Trace written to」（日志改记 `/log/catch`）。实测：连续四次出错后 `look`、`i`、
`!look` 都正常。KB 06 §7.217。

## 深度功能测试（§10.7，2026-10-05）— here-document terminators

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 1 here-document block(s) repaired (0 with the terminator glued to the last text line, 1 with it indented), so `End of file in text block` no longer hides the room or object behind them: `wiz/lei/room/startroom.lpc`. The terminator must start its line (the lexer's own test, KB 04 §6.10); a glued one lost its newline in the GBK -> UTF-8 conversion together with a half character, which stays out.

## 2026-10-05 — `T array a, b` 转换遗漏

四个 `nation_menu.lpc`（`cmds/area`、`wiz/edc`、`wiz/xiaobai/menu`、`wiz/mimi`）的 `string * keys, dis;` 由原文 `string array keys, dis;` 转换而来，`dis` 丢了 `*`（MudOS 的 `array` 属于类型，两个名字都是数组）。补回 `*`；运行时驱动不检查局部变量类型，所以以前也能用（KB 03）。

## 深度功能测试（§10.7，2026-10-06）— 编译警告整理

`scripts/lpc_warnings.py sgzmudsgz --fix`：无用局部变量 216 个、`varargs` 8 处、裸 `return` 3 处、`nosave` 函数 136 个改 `protected`（8 个去掉），共改动 136 个 `.lpc`。HEAD 与工作树分别加载（新进程）：134 -> 134 通过，无回退；`scripts/lpc_audit_removed_locals.py HEAD` 检查 291 个删除的声明，0 条需看。
手工：
- `cmds/verbs/throw.lpc` 把 `inherit VERB_OB;` 写了两遍（第二遍在 `//ok` 之后），12 个函数报"从两处继承"；删去重复的那一行。
- `secure/user/inputsys.lpc` 的 `object save_this_user = this_user();` 只被一行注释掉的 `set_this_player` 读，删去。
- `scripts/lpc_diamonds.py --fix-redundant`：`domains/std/scarf.lpc`、`wiz/yue/obj/door/lockable_door.lpc` 去掉已被其他父类带进来的重复 `inherit`。`std/armor.lpc` 用 `object::remove()` 依赖 `inherit OBJ` 的作用域名，保留；`wiz/yue/obj/door/lock_door.lpc` 是巫师目录里的菱形继承，启动不加载，未动。

启动时警告 139 -> 0；新进程登录（标题画面、`new` 注册、英文名确认）正常。

## 深度功能测试（§10.7，2026-10-08）— `.lpc` 后缀的定宽切片

`.c` 改名 `.lpc` 时只改了字符串没改切片宽度：`f[<2..] == ".lpc"` 拿两个字符比四个字符，永远不成立（`!=` 永远成立），按后缀筛文件、去后缀的代码因此从不运行或截成 `x.l`（KB 06 §7.238）。`scripts/lpc_lpc_suffix_slice.py --apply` 改了 8 处比较、2 处去后缀（如 `daemons/doc_d.lpc`）；改动的文件 HEAD 与工作树分别加载（新进程），无回退。

## 深度功能测试（§10.7，2026-10-08）— 编译警告整理

`scripts/lpc_warnings.py sgzmudsgz --fix` 加 `scripts/lpc_fix_no_effect.py --apply`，共改动 311 个 `.lpc`（多为删去未用的局部变量）。HEAD 与工作树分别加载（新进程）：306 -> 306 通过，无回退。启动时警告 0 -> 0；新进程登录（输入名字）正常。
（这一轮用分块扫描重跑：上一轮单次 `lpcc --batch` 中途死掉，只扫到 3546 个文件里的 1452 个。）
记录、未改：分块扫描时 `daemons/warai_d/warai_d.lpc`、`wiz/edc/code/troop_d.lpc`、`wiz/edc/code/warai_d.lpc` 让 lpcc 进程死掉（`Too deep recursion`）。它们是放在子目录里的旧副本，`inherit __DIR__ + "warai_d/attack"` 指向不存在的 `.../warai_d/warai_d/attack`，master 的 `compile_object()` 又按“上一级同名文件”去找 `warai_d.lpc` 的 `virtual_create()`，于是加载自己、无限递归。真正在用的是 `/daemons/warai_d.lpc`、`/daemons/troop_d.lpc`（`include/daemons.h`），这几个副本没人加载。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 0 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 20 个，只在 #if 分支用的声明移进分支 0 个文件；改动 13 个文件，HEAD 与工作树各载入一次无回退（13 objects; HEAD PASS 13, tree PASS 13; regress 0; newly loading 0），这些文件的警告 20 -> 1。

- 2026-10-10（续）：第二轮编译警告整理（`lpc_fix_unused_init.py`）删掉了只在不启用的 `#if` 分支里用到的局部变量声明（如 `include/net/ftpdsupp.h` 中 `#ifdef GUEST_WIZARD_FTP` 分支的 `file`），启用该选项时会编译失败；声明已放回所用的分支里，工具已改为跳过这种情况（交给 `lpc_move_decl.py`）。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查

- `daemons/messages_d.lpc`（及 `wiz/mimi/update/` 副本）`get_detail_messages()`：缺子类时 `({"少一条信息…"});` 少了 `return`，返回 0；补 `return`。
- `sgdomain/obj/cloth/cloth.lpc`、`weapon/dandao.lpc`：`if(one_name);` 多了分号，“所有者”行无论有无主人都显示；去掉分号。
- `wiz/ljty/modules/l_lockable.lpc`：门坏了时的提示 `"它己经坏了…";` 丢了 `write(`，补上。`WWW/cgi/news_groups.lpc` 孤立的 `mud_name();` 删去。
- 5 个能载入的对象载入无回退。

## 编译警告收尾（2026-10-12）

`scripts/toolkit_fix.sh` 一轮加手工收尾，能编译的文件警告清零。改动的对象加全部继承 `FURNITURE`/`M_MOUNTABLE` 的家具 HEAD 与工作树各载入一次：58 个，HEAD PASS 58，tree PASS 58，regress 0。

- `std/modules/m_mountable.lpc` 的 `mount_it_already()` 是 `private`，私有函数不能被重载：`sit()`/`mount()`/`get_on()` 永远调基类自己那份（只把人挪进去），18 张床、沙发自己写的 `int mount_it_already()`（“脱下衣服躺在床上”等）从来没跑过。基类改 `protected void`，各家具的同名函数改 `void`（`return 1;` 改 `return;`），现在躺床走家具自己的描写。
- `cmds/player/enable.lpc`（及 `wiz/mimi/update/enable.lpc`）：`main()` 写成 `int` 并用 `return notify_fail("...")` 报错，可是 Lima 的 `cmd.lpc` 的 `call_main()` 不看 `main()` 的返回值，notify_fail 的提示从来不会显示；`main()` 改 `void`，出错处改成 `write(...); return;`，玩家现在能看到“你不会这种技能”等提示。
- `cmds/player/info.lpc` 及两份拷贝同时继承 `CMD` 和 `VERB_OB`，两者都有 `create()`，原来只跑 `VERB_OB` 的那个，`CMD` 的 `set_privilege(1)` 被跳过；加 `create() { cmd::create(); verb_ob::create(); }`。
- 两条路进来的同名函数：`sgdomain/event/ev_war.lpc` 的 `train_collect()`（`train.lpc` 与 `train_beg.lpc` 两份逐 token 相同）、`domains/std/shopkeeper.lpc`、`sgdomain/base/room/enter.lpc`、`room.lpc`、`wiz/listen/cmd/call.lpc` 用 `lpc_name_winner.py` 写明驱动本来就选的那个；`wiz/yue/obj/door/lock_door.lpc` 在 `SECRET_DOOR`（已含 `M_LOCKABLE`）前多继承了 `M_LOCKABLE`，删去（§7.240）。
- 叶子变量与基类同名而各管各的：`sgdomain/job/xuzijiang/xianren.lpc` 的 `busy`/`long` 改 `talk_busy`/`dir_list`，`sgdomain/job/fishing/net.lpc` 的 `size` 改 `net_size`，`wiz/lcm/baguaroom.lpc` 自己的出口表改 `bagua_exits`；`wiz/nono/*.lpc` 四个房间没用的 `private mapping exits;` 删去。
- `CHINESE_DA`（9 个 NPC）、`wiz/emperor/baby/sanguo.h` 的 `TROOP`/`SALERATE` 前加 `#undef`；`daemons/union_d/cases.lpc` 的 `?:` 类型；`obj/hintmenu.lpc` 没用的 `MENU m`；`wiz/chun/room/dream.lpc` 多余的 `;`。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。46 个文件 109 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）；`x op= 浮点` 先把浮点转成整数再运算（系数小于 1 时 x 直接变 0），改为 `x = to_int(x op ...)`：`/daemons/troop_d/troop_attack.lpc`（`ret *=`）、`/daemons/warai_d/array_attack.lpc`（`p_kill *=`）、`/sgdomain/modules/m_bank.lpc`（`p_bank +=`）、`/wiz/edc/code/array_attack.lpc`（`p_kill *=`）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。
- 2026-10-14（同一次重扫，手工部分）：`sgdomain/jimou/hunluan.lpc`（计策「混乱」）的倍率 `x=1.8`、`z=1.5` 声明成 `int`，被截成 1。施计方的计策值本应乘 1.8，实际只乘 1。现改为 `float x, z;`，`kill = to_int(kill*x - kill1*y)`。**玩家可见**：混乱计策按原设计更容易成功。改动的 46 个对象 HEAD 与工作树各载入一次，无回退。

- 2026-10-14：1 个文件因 `Type of returned value doesn't match function return type ( int vs void )` 整份不编译：声明为 `void`（或没写类型）的函数却返回值，旧驱动照样把值交给调用者。调用者要用返回值的（add_action 处理函数、命令、辅助函数）改为它实际返回的类型：`file_pos()`。新进程比对 HEAD 与工作树：1 个对象，新增载入 0，回退 0（`scripts/lpc_fix_void_return.py`，KB 04 §6.3）。

## 旧驱动的类型宽松：缺省参数、无类型形参、数组初始化、`class` 变量（2026-10-19，KB 04 §6.19、§6.20）

原来的 MudOS 把调用少传的参数补 0、把没写类型的形参当 `mixed`、不检查变量的声明类型与初始值，也允许变量叫 `class`；这个驱动在编译时全部拒绝，整个物件载入失败。修了 2 个文件：`/secure/modules/m_file.lpc`、`/wiz/flee/law/ev_judge.lpc`（`scripts/lpc_round_files.py` 的修复轮：调用处补写 `0`、无类型形参补 `mixed`、`string X = ({...})` 补星号、void 函数的返回值，以及 `class` 变量改名 `pick_class`）。逐个文件在 HEAD 和改后载入对比：这些文件里 0 个原来载入失败、现在载入，没有退步。

## `member_array('/', str)` 改为 `strsrch(str, "/")`：字符字面量的 member_array 按字节搜索（2026-10-20，KB 06 §7.283）

`member_array('/', str)` 里的 `'/'` 是整数，驱动按 UTF-8 **字节**搜索，返回字节偏移（带第三个参数时起点也是字节）；最新的 FluffOS（923cdbc0）在字符串里有非 ASCII 文字时，对每个调用点警告一次（`Warning: member_array(int, string) searches BYTES`）。而 `str[0..idx-1]` 按字符切，中文字符串会在错误的位置截断。改为 `strsrch(str, "/")`（找不到同样返回 -1，按字符计数；`scripts/lpc_fix_member_array_char.py`，JSON 编码器等少数几处手改）。改动：`/daemons/channel_d.lpc`（2 处）、`/daemons/guild_d.lpc`（1 处）、`/daemons/help_d.lpc`（1 处）、`/daemons/news_d.lpc`（2 处）、`/daemons/sghelp_d.lpc`（1 处）、`/daemons/soul_d.lpc`（2 处）、`/obj/helpsys.lpc`（1 处）、`/secure/daemons/cmd_d.lpc`（2 处）、`/secure/daemons/secure_d.lpc`（5 处）、`/sgdomain/modules/war_grid.lpc`（1 处）、`/std/grid_server.lpc`（1 处）、`/std/modules/m_ansi.lpc`（1 处）、`/std/modules/m_glob.lpc`（1 处）、`/std/modules/m_set.lpc`（1 处）、`/std/room/parsedsc.lpc`（2 处）、`/trans/obj/admtool/security.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 11 处）。改动：`/cmds/verbs/money.lpc`（1 处）、`/sgdomain/troops/bowman.lpc`（2 处）、`/sgdomain/troops/cavalry.lpc`（2 处）、`/sgdomain/troops/commando.lpc`（2 处）、`/sgdomain/troops/footman.lpc`（2 处）、`/sgdomain/troops/infantry.lpc`（2 处）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/secure/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。
