# longyunmeng_binary — 龙云梦·炎龙封印（二进制版）（033-3）

档案：`龙云梦-炎龙封印-二进制版.rar`（19,622,891 字节）。根目录 `xyzx/`：`mudos.exe`（Win32 驱动，2006-08-02）、
`config.jh`（原配置，mudlib 目录 `D:/xyzx/ylfy/bin_version/xyzx/ylfy`，端口 2003/5555/8888/9999）和 mudlib 树 `ylfy/`。
`ylfy/说明文档.txt` 写明：「这个版本为内部使用版本。使用了专门的配套的 Os 和 LIB，运行机制采用的是纯二进制」，
OS 是「MudOS v22pre12 For Windows_Mysql_Bin」，LIB 是「夕阳再起 之 [炎龙封印] 3.5」，最后更新 2006 年 3 月 20 日，
作者「龙云梦(Wenwu)」。驱动里的版本串实际是 `v22pre11`，源码路径 `d:\xyzx\ylfy\wenwu\mudos_v22pre11_and_ mysql_for_windows_source`。
同一游戏的源码版是 033-2 `longyunmeng`（文件日期到 2011 年，是本版之后又改了几年的版本）。

## 二进制发行

- `binaries/` 下 14,395 个 MudOS `.b`（`MUDB` 魔数），全部是 2006-08-28 编译的。
- `.c` 只剩 2,013 个，都是「动态系统调用」要用的：`d/automap` 1,500（迷雾森林随机迷宫）、`kungfu/skill` 462、
  `u/wenwu` 37、`clone/money` 10 等。其中 2,006 个有对应的 `.b`；另 7 个没有（`kungfu/skill/feiyuexy.c` 等是
  加密校验用的标记文件，内容只是一串时间戳）。
- `include/` 只剩 `globals.h`、`ansi.h`，其余头文件都删掉了。
- 和 033-2 比：14,395 个程序里 13,633 个在 033-2 有同名 `.c`；762 个没有，其中 498 个靠本版自己的 `.c`
  （主要是 `d/automap`），**264 个只有 `.b`**：`d/migong` 109（其中 108 个是 `lev6`、`lev7` 两层迷宫的房间）、
  `u/snow` 70（巫师 snow 的五毒教区域 `wudujiao` 69）、`u/fyue`（华山浴血残阳任务等）25、`d/ghost`（幽灵山庄）16，
  以及一批命令、技能和 `feature/*_old` 备份。
  其中 `u/snow/wudujiao` 是巫师的工作区，没有接入游戏世界（游戏里的五毒教是 `d/wudujiao`）；幽灵山庄唯一的入口
  `d/ghost/lroad1` 通往的 `/u/guanwai/citygate` 档案里没有，只能由巫师进入。

驱动的「纯二进制」机制靠主控对象的两个自定义 apply：`valid_os_lib_version()` 和 `valid_c_or_bin_run()`
（后者对 `/d/automap/`、`/d/party/`、`/data/` 返回 5，允许从 `.c` 运行；其余返回 1）。两者都检查
`/doc/skill/mudsky`、`/doc/mudlib/efuns/ylwenwu`、`/kungfu/skill/feiyuexy.c` 等标记文件是否存在，
`adm/daemons/automap` 的心跳里任何一个返回 0 就 `shutdown(-1)`。标记文件档案里都在，FluffOS 下照常通过
（`feiyuexy.c` 的引用已随 `.lpc` 改名）。

## 驱动的 efun 表（PE 版 mudos.exe）

`mudos.exe` 是 MSVC 编译的 PE32，没有符号表。`scripts/mudos_b/pedriver.py` 按形状找 `predefs[]`：
数据段里最长的一串 32 字节 keyword_t，`word` 指向标识符串、`next` 和 `sem_value` 为 0、按名字排序，且必须
含 `call_other` 和 `this_object`。找到的位置是 `0x4d7df0`，244 个 efun。和 wllz3 的 Linux v22pre11 驱动比：
多 `db_*` 8 个（MySQL）、`generate_source`、`lpc_info`、`set_light`、`set_this_player`，少 `author_stats`、
`domain_stats`、`set_author`；共有的 efun 参数签名完全一样。

**操作码不同**：从 `init_instrs()` 里 110 次 `add_instr_name()` 调用（`push type; push 编号; push opco; push 名字;
call`）读出这个版本有 116 个运算符，比 v22pre11 标准多 3 个：`get_classstack_object`、`push_classstack_object`、
`pop_classstack_object`（114–116），所以所有 efun 编号都比 Linux 版大 3（第一个 efun 是 117）。14,395 个程序里
没有一个用到这三个运算符。`compiler_function_t` 在这个 MSVC 版本里是 16 字节（Linux 版 12 字节）。这些都写进
`scripts/mudos_b/drivers/longyunmeng_binary.json`（`operators`、`entry_size`），没有一处是猜的。

## 反编译和验证（2026-10-15）

工具 `scripts/mudos_b/`（KB 02 §3.1），全过程可以用 `rebuild.sh` 从档案重做。

1. **反编译**：14,395 个 `.b` 全部反编译，没有一个出错。
2. **验证用的编译器**：Win32 驱动在本机跑不起来，但 wllz3（186）档案带的 Linux 版 MudOS v22pre11 能跑，
   是同一个版本号的另一个编译。`mudos_b.roundtrip --oracle-table` 让它把反编译出来的源码重新编译，再和本版的
   `.b` 做规范化比较（函数、变量、efun、simul_efun 都按名字比，所以两边 efun 编号不同不要紧）。两个编译版本
   之间有两处差别，需要说明：
   - Linux 版默认 `#pragma strict_types`，Win32 版没有（`create()` 这种不写返回类型的函数在本版 `.b` 里没有
     `NAME_STRICT_TYPES` 标志）。验证时每个文件前面加 `#pragma no_strict_types`。
   - Linux 版会把局部变量的最后一次读取编成 `transfer_local`，Win32 版从来不这样做（14,395 个程序里一次都
     没有）。两者压进栈的值一样，比较时把 `transfer_local` 当 `local`（`--fold transfer_local`）。
3. **第一轮**：10,055 个完全一致，4,318 个只差 `transfer_local`，剩下 15 个是反编译器真的错了，6 种代码形状，
   都修了（`decompile.py`）：
   - `while (1)` 里的 `continue`（跳到收尾的 `bbranch`）原来被读成 `if (...) {} else ...`，`d/city/npc/post_officer`
     这种还把语义读错了；
   - 编译器只在函数体超过两条语句时才在 `return x;` 后补 `return 0`（局部变量的初值算一条），
     `cmds/usr/score` 和 `d/city3/jiulou2/obj/food` 的原文是「初值 + return」，反编译时要合并回去；
   - `quest/guojob/guo` 和 `cmds/std/look_wiz` 有两个同名的全局变量（`#include` 了两个都声明 `names` 的文件），
     后面的引用绑定到声明在它之前的那个，所以变量声明要插在函数之间；
   - simul_efun 在场时编译的程序里，调用一个后面才定义的同名函数会编成 simul_efun 调用
     （`adm/simul_efun/message` 的 `message()`、`cmds/usr/ctell` 的 `find_player()`），原型要放到调用之后；
   - 本程序里有同名函数时，直接调 efun 要写 `efun::command(...)`（`inherit/char/char`、5 个 NPC）；
   - `adm/daemons/text2pic_d` 的 `if (...) error(...);` 后面紧跟 `v = 0;`：void efun 的值没被用。
4. **最终结果：14,395 个里 14,394 个和原 `.b` 完全一致**。剩下的 `cmds/bos/socket` 调用了 MySQL 的
   `db_status()`，Linux 版驱动没有这个 efun，编不了；它只有 `.b`，按「通过验证的反编译器还原」放进树里。
   wllz3 的反编译输出没有变化（只有它保留原文的 `adm/simul_efun/message` 换了排版）。

## 和 033-2 源码版的比对

要求是拿 033-2 的源码和反编译结果做比较。既然有能跑的 v22pre11 编译器，就直接在 MudOS 层面比：把 033-2 的
`.c` 放进本版的源码树（头文件用 033-2 的，`globals.h`/`ansi.h` 用本版自己的），编译后和本版的 `.b` 规范化比较。
这比在 FluffOS 里各自编译后比 `dump_prog` 更严格，也直接回答了「033-2 的这个文件是不是本版 `.b` 的源码」。

- 被继承的 90 个程序先全用反编译版本，其余每个程序换成 033-2 的原文：12,033 个里 **8,158 个完全一致**，
  3,745 个不一样（033-2 后来改过），130 个在本版环境里编不过（用了 033-2 后来才加的宏和守护进程）。
- 被继承的程序（`feature/`、`inherit/`）反复迭代到稳定：89 个里 44 个一致；`feature/dbase`、`move`、`skill`、
  `inherit/room/room`、`inherit/char/npc` 等核心文件 033-2 都改过。
- `adm/obj/master`、`adm/obj/simul_efun`、`adm/daemons/securityd` 用 033-2 的版本都不一致。
- 合计：033-2 也有源码的 12,125 个程序（不算本版自带 `.c` 的）里 **8,202 个（67.6%）是本版 `.b` 的源码**。

本版自带的 2,006 个 `.c`：446 个编出来和 `.b` 一致；`d/automap` 的 1,500 个房间全部比 `.b` 新
（`.c` 15:31，`.b` 15:17，同一天），是迷雾森林重新随机生成后的下一代地图，驱动对 `/d/automap/` 允许从 `.c`
运行，所以保留 `.c`；另外 60 个（`kungfu/skill` 23、`u/wenwu` 37）比 `.b` 旧，是过时的源码，用反编译版本。

## 源码树的组成

- 本版自带原文 1,946 个（`decompile/keep-original.lst`）；
- 033-2 的原文 8,202 个，外加它们 `#include` 的 64 个头文件（`decompile/borrow-033-2.lst`），每个借来的 `.c`
  第一行注明出处（`decompile/borrow-header.txt`）；本版自带的 `kungfu/skill/duanjia-jianfa` 要用的
  `include/power_control.h` 档案里也没有，同样取自 033-2（验证时它就是用这个头文件编出和 `.b` 一致的程序）；
- 反编译 4,247 个（文件开头有一行说明）。局部变量名丢失，用 `v1`、`arg1` 代替。

按这个组成在 v22pre11 编译器里再整体跑一遍：除 `d/automap` 的 1,500 个（比 `.b` 新）外，12,895 个程序里
12,894 个和原 `.b` 完全一致，剩下的就是 `cmds/bos/socket`。

## FluffOS 移植

`rebuild.sh`：反编译时用 `--fluffos --gbk`（`--gbk` 让字符串里 GBK 第二字节是 `0x5c` 的字不被转义，
否则转成 UTF-8 后会剩一个反斜杠）→ 组装源码树 → `convert_lib.sh` → 把被 §4.3 改坏的 `static/` 路径改回来 →
`scripts/lpc_drop_replace_program.py` 删掉多余的 `replace_program(X)`（6,228 个文件）→
打上 `decompile/fluffos-fixes.patch`。`OUT=<目录> REC=<目录> rebuild.sh` 可以建到别处和 `work/` 比较。
**`work/` 里的任何修改都要同步进 `fluffos-fixes.patch`，否则 `rebuild.sh` 就不能重现这棵树**：`PATCH=0 OUT=<目录>/work REC=<目录>/rec rebuild.sh`
建出打补丁之前的树，`decompile/mkpatch.sh <目录>/work work decompile/fluffos-fixes.patch` 重新生成补丁（跳过 `log/`、
`binaries/` 和玩家存档，保留管理员的两个存档；`work/` 里删掉的文件不会记进去）。

已做的修改：
- simul_efun 的 `message()`：FluffOS 的第四个参数（排除列表）不收 0，`message()`、`tell_room()`、`shout()`
  改成 `|| ({ })`，`message()` 加 `varargs`（KB 05 §7.12）。
- 中文判断（KB 07 §8.1）：`is_chinese()` 改成判断 CJK 码位；`logind` 的 `check_legal_name()` 按字符数 1–5、
  每个字都检查。
- `logind` 的 `logon()` 在 `dns_master` 没有 `query_doing_end()` 时一律踢掉连线（「『江西一站』正与主站同步中」）；
  加 `find_object()` 判断（同 033-2）。
- `adm/etc/preload`：`network/dns_master`、`network/fileserver`（4000 端口）、`ftpd`、`httpd`（8000 端口）这些
  网络服务不预载；033-2 的原作者后来也把它们注释掉了。
- 端口：原来按 2003/8888（纯文字客户端）和 5555/9999（Tomud 客户端）分协议，本项目每个库只有一个端口，
  改成 5555/9999 以外都按纯文字处理，否则所有画面都夹着 Tomud 的控制码。
- `automap`：开机时 `update_map_time` 是 0，第一次心跳（9 秒）就删掉并重写 1,500 个 `d/automap/*.lpc`；
  改成从开机算起 15 小时后才第一次重建（树里的地图本来就是完整的一代）。
- 主控对象的 `log_error()` 不再把编译警告当「编译时段错误」显示给玩家。
- **（原版的错误）放弃注册会占掉这个帐号**：simul_efun 的 `destruct()` 对 `userp()` 为真的对象都 `save()`，
  登录对象也算，于是在确认英文名之后断线，`data/login/x/<id>.o` 只存了 id 没有密码，这个 id 以后永远要求
  输入一个不存在的密码。033-2 的作者后来改成只存玩家身体；这里只跳过没有密码的登录对象。

## 移植 033-2 的修正（2026-10-15）

033-2 上线以后陆续修过的错误，本版文件里也有的都搬了过来：

- 借来的 8,202 个文件就是 033-2 修正之前的原文。`lpc_twin_port.py adopt longyunmeng longyunmeng_binary --pre dbc39b6384f`
  （KB 08 §10.13）把 033-2 此后的修正按 token 拼接进来：3,718 个文件，其中 2,868 个只是删掉多余的
  `replace_program(ROOM)`。拼接时一处被删掉的空 `if` 把里面两行注释也带走了（`adm/daemons/story/new7.lpc`），已补回。
- 033-2 上线当天的修正在 `dbc39b6384f` 里面，不会被上面带过来，单独比对：借来的文件只有 8 个和 033-2 当时的
  版本不同。搬过来的是 `d/gumu/npc/force.h`（`__FILE__` 在头文件里是头文件自己的名字，`valid_learn()` 的「先散掉别的内功」
  检查把玉女心经自己也算成别的内功：学过一级以后就再也学不上去）和两个 `bowl`（`set_name()` 的第二个参数要数组）；本版自带的
  `kungfu/skill/force.h` 同样修正。另外三个是 033-2 被 `static`→`nosave` 改坏的日志路径，本版没有这个问题。
- 反编译出来的核心文件变量名是 `v1`、`arg1`，token 对不上，对照 033-2 的改动逐条手工移植：
  - 主控对象的 `valid_read()`/`valid_write()`：驱动编译新对象时把主控对象自己当作 user 传进来，直接放行；
  - `logind`：注册对话里两处 `printf("%O\n", ob)` 调试输出删掉；`init_new_player()` 包上 `catch`（KB 06 §7.109）；
    同一 IP 连线数的两道限制和 `band` 的封禁检查对 127.0.0.1 放行（网页版的玩家都从这个地址来，KB 01 §1.3b）；
  - `clone/user/user` 的 `reconnect()` 先 `enable_commands()`（§7.108）；`feature/command` 的 `enable_player()`
    防重入（KB 05 §7.19）；`feature/skill` 的四个 `query_*()` 在映射没有初始化时返回空映射（§7.30）；
    `feature/name` 的 `short()` 在 id 不是字符串时不出错；
  - `inherit/room/room`：`make_inventory()` 用 `catch` 包住 `clone_object()`，`reset()` 拿到 0 就跳过（KB 05 §7.25）；
  - `d/death/npc/bgargoyle`、`wgargoyle`：重新连线会再跑一次 `init()`，`death_stage` 的 call_out 链加上标记，
    每个鬼魂只有一条（KB 06 §7.112）；
  - `quest/guojob/guo`：include 进来的 `zzzjob` 和 `teamjob` 都声明了全局变量 `names`，MudOS 里是两个变量，
    FluffOS 里是同一个，守城任务会抽到 teamjob 的名单；第二个改名 `team_names`（同 033-2 的 `teamjob.lpc`）；
  - simul_efun 的 `log_file()` 先建目录（KB 05 §7.44），`cat()` 读不到文件时不出错。
- `replace_program(X)`（X 是本文件继承的对象）由 `rebuild.sh` 的一步统一删掉，6,228 个文件（借来的文件里 033-2
  也删过的在内），另加两份 `roommaker` 写出的房间模板（KB 06 §7.86、§7.100）。
- 拼接时有 396 个文件和 033-2 修正前的原文逐字节相同，`adopt` 会整个换成 033-2 现在的版本（连同 033-2 的排版）；
  这些文件改成只拼接 token 的改动，保留本版档案的排版：其中 355 个 033-2 只改了排版，41 个有实际修正。
- `lpc_fix_skill_typo.py`：`d/mr/obj/shu1` 的 `douzhuan-xignyi`（KB 06 §7.249）。

## 编译检查和其余修正（2026-10-15）

`scripts/toolkit_fix.sh` 一轮（编译警告的机械修正，再把改过的 7,114 个对象在 HEAD 和工作树各加载一次）：
未使用的局部变量 12、`varargs` 2、`init()` 的返回类型和 `feature/attack` 不一致 10（`u/snow/wudujiao` 的 NPC）、
`query_autoload()` 和继承的定义不一致 5、重复继承 `F_CLEAN_UP` 2；加载对比没有一个退步，多加载成功 86 个。
其后手工修正：
- 转码丢掉的字符：`d/heimuya/shenggu`、`tang`、`npc/tang` 的 `@LONG` 结束标记粘到了上一行
  （`lpc_fix_heredoc_terminator.py`）；`kungfu/skill/qingyi-jian` 的「大悲式」和 `kunlun-zhang` 的「天清云淡」
  两句字符串原文结尾是半个 GBK 字，转码时连同后面的引号一起没了（`.b` 里这两个字符串就是在那半个字之后结束的），
  补回引号；
- `inherit/char/npc` 的 NPC 自动出绝招：从 `kungfu/skill/<武功>/` 的目录列表取文件名后切掉两个字符（原来是
  `.c`/`.b`），本树是 `.lpc`，切出来的 `xxx.l` 不是绝招名，NPC 打斗时从来不出招；改成去掉扩展名。
  同样的切法在 `adm/daemons/baoshid`（宝石降落时随机挑一个房间物件，`load_object("xxx.l")` 永远失败，
  每次都「本次宝石发布失败」）、`cmds/bos/tomud`、`cmds/app/update`；`cmds/app/ls3`、`cmds/bos/memup` 的
  `[<2..] == ".lpc"` 比较（`lpc_lpc_suffix_slice.py`，KB 06 §7.238）；
- 中文判断（KB 07 §8.1）：`cmds/std/makelian`、`makeexp`、`makefight`（帮会建房）的名字和描述长度按 GBK
  字节数写的（「一到十个中文字」实际要求 2–20 个字符，描述「三十到一百个中文字」实际要求 60–200 个），减半；
  逐字检查不再隔一个字查一次，描述里允许中文标点（原来的检查是「双字节字符」）；`cmds/std/auction` 的物品介绍同样处理；
  不加载的 `adm/simul_efun/chinese`、`message` 也按 033-2 改了；
- `logind`：Tomud 客户端的握手串 `\031connect ...\032` 只发给 5555/9999 端口，纯文字客户端不再在提示后面看到它；
- `cmds/bos/socket2`（MudOS 的 `dump_socket_status()`）、`cmds/bos/socket`（MySQL 的 `db_status()`）用
  `efun_defined()` 判断，驱动没有这个 efun 时只显示一句说明。

`lpc_warnings.py` 全量扫描：14,402 个 `.lpc` 里 14,315 个能加载（第三次提交 `63d1b8ce684` 的树再扫是 14,351 个），
**编译警告 0**。编不过的 6 个在原游戏里都没有 `.b`（从来没有加载过），保留原样：`doc/mudlib/efuns`（efun 名字清单，
纯文本）、`doc/mudlib/efuns/shiwu`、`kungfu/skill/feiyuexy`（纯二进制机制的标记文件，内容是一个时间戳，主控对象只
检查它在不在）、`kungfu/skill/hanbing-mianzhang2`、`huang`、`xixi-unarmed`。同样没有 `.b` 的
`kungfu/skill/quanzhen-xinfa` 原来是第 7 个：「无性」的等级限制用了没有定义的 `lvl`，编译器还报了两个没用的局部变量
`i`、`ts`（这两个警告在上面的扫描里漏算了）；`lvl` 改成这门内功自己的等级 `nh`（`chidi` 档案里同一份文件的原文就是
`nh`），删掉两个变量，现在没有错误也没有警告。

把 14,402 个对象逐个加载（工作树状态，每个驱动进程 700 个）：14,314 个成功，88 个失败，都不是移植造成的：
当时编不过的 7 个文件；`u/snow`、`u/fyue` 巫师工作区的 38 个（这两个巫师不在 `adm/etc/wizlist` 里，他们的对象
读不了 `/kungfu/skill/`，`set_skill()` 就报「No such skill」，而且这两块没有接入游戏世界）；用到档案里根本没有的
技能（`move`、`notracesnow`、`shenzhao-jing`、`kongmingquan`）的 NPC，在 `d/ghost`、`d/quanzhen_old`、
`d/migong/obj/npc1`、`clone/npc/robber`；在 `create()` 或全局变量初值里用 `this_player()` 的对象（玩家锻造的兵器
和护甲、宝石戒指、`adai-quanfa` 等六门技能的招式表），由玩家的动作触发时才能加载，批量加载时没有玩家；以及
网络守护进程和缺数据文件的 `d/miwudao/secret/npc/room`。

## 深度功能测试（§10.7，2026-10-15，FluffOS 原生 + WASM）

原生驱动（`build-debug`）在由提交后的树建的干净副本上跑，纯文字 telnet 客户端：
- 注册全流程（英文名 → 中文名 林风 → 密码 → 身份标识 → 天赋 → 魔法天赋「火」→ 邮箱 → 性别），新人物随机出生在
  扬州武庙、北京客店、北疆小镇之一；`look`、`score`、`hp`、`i`、`who` 正常。
- 断线后重连（「重新连线完毕」，之后指令照常，§7.108）；把注册时间往前调一小时后 `quit` 存档，过了游戏自己的
  15 秒限流再登录，位置、死亡次数、最后杀你者、钱庄存款都在。
- `fly yz`、走路、钱庄 `qu`、醉仙楼 `list`/`buy`/`eat`、`pick gift`/`chai gift`、表情 `smile`/`hi`、`help`、`time`。
- 打架：`kill liumang` 和流氓头对打，火系魔法天赋的「火之屏障」挡伤害，技能长进，气血低时自动逃跑；
  用 `force` 让郭靖去杀收破烂的，郭靖打出降龙十八掌的「惊天一击」（NPC 出招，见上面 `inherit/char/npc` 的修正）。
- 死亡：鬼门关里白无常的五段对话只走一遍，之后还阳回到武庙；宝石降落的公告也出现了（`baoshid` 的修正）。
- 管理员 `fluffos`：`update /d/city/wumiao` 成功，`goto`、`call`、`clone`、`force` 可用。整个过程 `log/debug.log`
  里只有一条运行时错误，来自测试时用 `call` 误存成字符串的注册时间（`quit` 时减法出错），不是游戏的问题。

测出来并修正的错误：
- **（移植）第一个表情就把所有人挡在门外**：表情和频道消息要显示「名字(id@JXONE)」，`Mud_name()` 宏和
  `channeld` 里展开的同一个宏都去问 `/adm/daemons/network/dns_master` 要名字，于是第一个 `smile` 就把这个没有
  预载的守护进程加载起来；它的 `create()` 用 MudOS 的 `get_config(14)` 取端口，在 FluffOS 里这个位置是「mud ip」
  （`"0.0.0.0" + 4`，`socket_bind()` 出错），`query_doing_end()` 永远是 0，`logind` 就对此后每一个新连线说
  「『江西一站』正与主站同步中」并断开。改法：`include/net/macros.h` 的 `Mud_name()` 和 `channeld` 在守护进程
  没加载时直接用它会给的名字 `JXONE`，不再顺手把它加载起来（网页版没有 socket，它根本编译不了，原来表情和频道
  在网页版会直接出错）；`dns_master` 的端口改用 `__PORT__`，巫师手动加载它时能正常起来（`query_doing_end()`
  为 1，登录照常）。
- **（移植）物品清单吞掉第一个字**：`inventory` 和 `feature/move`（简略模式下进房间看到的物品）把同样的物品按
  「单位 + 名字」归并，只有一件时切掉 `[2..]`，在 GBK 里是一个汉字的单位，在这里是两个字符：「包子(Baozi)」
  显示成「子(Baozi)」，带颜色的名字切掉 ESC 后显示成「[1;31m幸运包」；改成 `[1..]`（KB 07 §8.1）。
- **（移植）自制兵器的 id**：`feature/item_make` 把两字一词的名字按 GBK 字节数拆（`[0..3]`、`> 4`），迷雾森林
  掉落的兵器 id 只剩「 sword」；按字符数拆以后是「毫光剑(Haoguang jian)」。
- 网页版的 FluffOS 发布版（v2026.1001.0）读配置文件一行最多 120 字节，`config.fluffos` 第一行注释 127 字节，
  网页版启动时报「Missing line: name」；注释改短（KB 08 §10.4 那一条）。
  同一个文件里 `living hash table size : 100` 不是驱动接受的值（只收 4/16/64/256/1024/4096，KB 03），启动时报
  `invalid new value`，改成 256。
- 管理员账号按 KB 01 §1.5 预置：正常注册 `fluffos`，`adm/etc/wizlist` 加 `fluffos (boss)`。本版的巫师登录还要先过
  「巫师登陆效验码」（`logind` 的 `get_wizpas()`，`login` 存档里的 `wizpasswd`，原来用 `/cmds/bos/wizpas` 设置），
  预置的效验码和密码相同。

最后在 `38b57939b1e` 的 `scripts/pristine_tree.sh` 副本上新起驱动再走一遍：注册（出生在北疆小镇）、`skills`、`smile`、`hp`、
`fly yz`、拿礼物后 `i` 显示「幸运包(Gift)」，管理员登录后 `update` 成功，两个人都做过表情以后新连线照常出现名字提示；
master 的 `error_handler` 一次也没有写 `/log/debug.log`（驱动自己的 debug.log 在这种启动方式下打不开，KB 08 §10.9）。

WASM（`scripts/wasm_client.js`，本机的 build-wasm）：注册、`look`、`score`、表情、`fly yz`、钱庄、买东西、`i`、
`help` 都正常；管理员登录（效验码 → 密码）后 `update` 成功。`wasm_status` 设为 `playable`。

## `partyinfo` 读不到 `/log/cmds/party` 就抛错（2026-10-20，KB 06 §7.326）

`cmds/std/partyinfo.lpc` 把 `read_file("/log/cmds/party")` 直接交给 `explode()`。这个文件是运行中的 mud 才会写出来的帮会日志，克隆出来的目录、站点和全新启动的树里没有，`read_file()` 答 0，于是 `Bad argument 1 to explode()`。现在读不到时按空表处理，只打印表头。同一份文件在 ylfyxa3、xajh4gkb 里已先改过（那里有实测）；这里只做了加载检查（1/1，回归 0）。`u/wenwu/partyinfo.lpc` 是巫师目录里的同名副本，没有碰。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库有 1 个 NPC 文件写成 `set("chat_msg", ({ }))`（或 `chat_msg_combat`）并带正的 `chat_chance`（例如 `/d/quanzhen_old/npc/tanchuduan.lpc`），每次心跳有 `chat_chance`% 的概率 `random(0)` 为 0、`msg[0]` 报 `Array index out of bounds`（驱动捕获，心跳继续，但每次一条运行时错误），这个 NPC 在内存里就一直发生。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/d/migong/obj/npc1.lpc`、`/inherit/char/npc.lpc`（共 2 个文件）。

## 巫师命令不带参数时对 0 调用 efun（2026-10-21，KB 06 §7.336）

巫师（管理员）把命令敲成不带参数时，驱动把 0 传给字符串参数；下面的命令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`，这条指令从来没有用过。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py` 在第一处使用参数的语句前加守卫：文件自带 `int help(object me)` 的，守卫是 `if (!arg) return help(me);`（`help()` 定义在 `main()` 之后的 1 个文件补了原型 `int help(object me);`，否则编译报 `Undefined function help`）。改动（1 个文件，括号里是接住 0 的 efun）：`/cmds/adm/dbiaoshi-md5.lpc`（`find_player`）。加载检查 HEAD 与工作树对照，没有退步。

## 睡袋：`/cmds/adm/bag` 本库没有，使用者被留在聋哑状态（2026-10-21，KB 06 §7.344）

`clone/misc/sleepbag.lpc`、`sleepbag2.lpc` 的 `do_sleep()` 在设好 `block_msg/all`、`no_get` 和房间的 `sleeping_person` 之后调用 `"/cmds/adm/bag"->main(me, "<休息中>")`。这条巫师指令只有 hc、tianxiawuxue 带着，本库没有：`call_other() couldn't find object '/cmds/adm/bag'`，玩家之后什么消息也收不到（`look` 一片空白），十秒后的 `wakeup` call_out 没有排上，房间一直 `no_fight`。城里的小贩 `xiaofan` 卖这个睡袋，没有人在扫描里买过它。`bag` 的全部内容就是 `me->disable_player(msg)`（`feature/command.lpc` 里的 `nomask void disable_player(string type)`，没有权限检查），两个文件都改成直接 `me->disable_player("<休息中>");`。chidi 上实测：`sleep` 之后十秒 "你一觉醒来，只觉精力充沛"，`look` 正常（HEAD 上玩家被留在空白屏里，`log/debug.log` 有 trace）。改动：`/clone/misc/sleepbag.lpc`、`/clone/misc/sleepbag2.lpc`。

## 香烟 `smoke.lpc`：`do_smoking()` 读没赋值的 `me`（2026-10-21，KB 06 §7.348）

`smoke` 指令的第一句是 `jing = me->query("jing")`，`me` 声明了没赋值，每次抽烟都抛 `Bad argument 1 to call_other()`。补 `me = this_player();`（后面的 `this_player()` 调用不变）。改动：`/d/emei/user-room/melodies/smoke.lpc`。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 50 条注册（50 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/clone/magicitem/jinshe1.lpc`（`use`）、`/d/city/chatroom2.lpc`（`do_jump`）、`/d/city/npc/wei.lpc`（`do_sell`）、`/d/city2/qishi.lpc`（`do_pass`）、`/d/city3/npc/sister.lpc`（`do_vendor_list`）、`/d/flypproom/npc/flypp.lpc`（`do_sell`）、`/d/miwudao/npc/enchanter.lpc`（`give_quest`）、`/d/miwudao/npc/enchanter2.lpc`（`give_quest`）、`/d/miwudao/npc/frank.lpc`（`do_vendor_list`）、`/d/miwudao/npc/graham.lpc`（`do_vendor_list`） 等共 50 个文件。最多的函数名：`do_send` 15 处、`do_vendor_list` 14 处、`do_decide` 7 处、`give_quest` 5 处、`do_sell` 3 处。

## 对象路径里的 `..`：`new(__DIR__ "../obj/x")` 报 `Read access denied`（2026-10-22，KB 06 §7.351）

`__DIR__` 是当前文件所在目录（带结尾斜杠），`__DIR__ "../obj/x"` 就是 `/d/zhiye/npc/../obj/x`；驱动的 `legal_path()` 不接受带 `..` 的路径，`new()` / `load_object()` 直接抛 `*Read access denied.`（实测，`find_object()` 对它答 0）。走库自己的 `carry_object()` / 房间 `objects` 表的路径，库的基类会先规范化，能用；直接把路径交给 `new()` / `clone_object()` / `load_object()` / `move()` 的不行，调用到那一步才报错。改成规范化后的绝对路径（`scripts/lpc_fix_dotdot_dir.py --direct`）：`/d/wudang/npc/xiaocui.lpc`（`__DIR__ "../obj/nuerxiang"` → `"/d/wudang/obj/nuerxiang"`）。

## 调用了、但这个库自己的守护进程里没有的函数（2026-10-22，KB 06 §7.354）

`MACRO->函数()` 调用的函数在这个库的守护进程里不存在：`call_other()` 对不存在的函数不报错、只返回 0，所以这些功能（时间显示、昼夜事件、名字检查、价格文字……）一直没起作用。同一血统另一个库的同名守护进程里有这些函数，原文照抄到本库守护进程末尾（`scripts/lpc_port_function.py`；调用处传的参数个数、函数体用到的函数 / 全局变量 / 宏 / 字符串键都在本库里有，已核对；守护进程在 HEAD 和工作区都能加载，每个函数用固定参数各调用一次：HEAD 返回 0，现在返回正常的值）：`/adm/daemons/natured.lpc` ← aoxiangtianji：`room_event_fun()`（2 处调用）。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 还剩 1 个函数没有补（item_desc 1）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/d/yihua/lianhuachi.lpc`:`look_CAI`。

## `(: 函数名 :)` 指针指向本库没有的函数：只含这个指针的行加了注释（2026-10-22，KB 06 §7.355 补充）

`inquiry` / `item_desc` / `chat_msg*` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：用到时（`ask`、`look`、NPC 闲聊）驱动抛 `*Undefined lfun pointer called: 函数名`，这一拍心跳的后半段被跳过。这些函数没有可以补回的来源（别的库同一路径的文件里没有，或者它还要用本库没有的东西），所以 1 个文件里 1 行只含这个指针的行（`"CAI"       :   (: look_CAI :),`）加了注释，原文保留并写明原因，这一项当作没有这个话题 / 物品 / 闲聊条目（`scripts/lpc_fix_dangling_lfun.py`；`#include` 的文件在库里缺失的对象、指针不在整行上的写法没动）。 前提（`function_exists()`）和加载检查（HEAD 与工作区对比，本库改动的 `.lpc` 文件）的结果见 KB 06 §7.355：没有一个回归。

## 汉字按字节切片的老写法没有换成按字符：改法名 `"澄" + name[2..3]`、辈分判断 `name[0..1] == "澄"` 等 18 处（2026-10-22，KB 06 §7.360）

原档按字节算字符串区间（一个汉字 2 字节）：`name[2..3]` 是名字的第二个字，`name[0..1] == "澄"` 问名字是不是以「澄」开头。转成 UTF-8 之后，这个驱动的区间和 `strlen()` 都按字符算（`strlen("澄观")` 是 2，`"澄观"[0..1]` 是两个字），老算术原样留着、意思全变：拜入少林 / 武当 / 峨嵋等派的玩家被改成错误的法名（二字名 `张三` 变成一个字的 `澄`，更长的名字取到第三个字）；各派掌门的辈分判断（`name[0..1] == "澄"`）永远不成立。

本库 18 处（13 个文件）：拼名字的赋值 10 处、与汉字常量比较 8 处。例：`name[2..3]` → `name[1..1]`（`/kungfu/class/emei/jingxin.lpc:109`）；`name[0..1]` → `name[0..0]`（`/kungfu/class/shaolin/qing-fa.lpc:109`）；`v4[2..3]` → `v4[1..1]`（`/kungfu/class/shaolin/xuan-ku.lpc:321`）。`scripts/lpc_fix_gbk_slice.py` 把下标按字符重算（社区的 UTF-8 版 `xkx100utf8` 里就是同样的写法，作对照）；没有改的：截断（`name = name[0..7]`，现在最多 8 个字，只是放宽）、ASCII 的区间（`fname[0..3] == "room"`、`ctime(time())[4..19]`）和上下文看不出是汉字的区间。证明（`scripts/lpcc_eval.py`，bixiecanyang；其余各库是同一份文本）：让澄字辈掌门 `attempt_apprentice()` 一个名叫「张三」的访客，HEAD 的法名是 `慧`，改后是 `慧三`；抽样 28 个库的 HEAD / 工作树加载对比 0 退步。工具不幂等（`[0..3]` 折半得 `[0..1]`，又是对齐区间），改过的文件记在 `scripts/gbk_slice_converted.txt`，不要重跑。

## 长度检查按字节写，旁边的提示按汉字写：2 处（2026-10-22，KB 06 §7.362）

老档的 `strlen()` 数字节（一个汉字 2 字节），转成 UTF-8 后它数字符：提示写「必须是 2 到 6 个中文字」的检查还是 `strlen(name) < 4 || strlen(name) > 12`，于是两三个字的房名、帮会名、群名、聊天室名、称号被提示自己说允许的那句话拒绝，上限却是提示的两倍；留言板的标题检查 `i < 4 || i > 24 || i % 2` 还会拒绝所有奇数个字的标题（`post 你好吗`）。本库 2 处（1 个文件）：`if (strlen(arg)<2 || strlen(arg)>30)`（`/d/player/fan_room.lpc:123`）。`scripts/lpc_fix_strlen_gate.py` 以提示为准：条件里每个 `strlen` 门槛都恰是提示所说数字的两倍才折半，存长度的变量（`i = strlen(arg);`）的门槛和 `|| i % 2` 奇偶项、其后循环的 `i % 2 == 0 &&` 一并处理；提示里有英文 / 字母 / 字节的不动。证明（`scripts/lpcc_eval.py`，bxsj 的留言板，求值对象继承 NPC 并重写 `edit()` 记录调用，`command("post 标题")`）：HEAD 拒绝「你好」和「你好吗」、放行 23 个字的标题；改后接受前两个、拒绝第三个；shenmo 的 `named.lpc invalid_new_name("张三")`：HEAD 回 `名字只能是2-4个中文字。`，改后回 0。抽样 24 + 15 个库的 HEAD / 工作树加载对比 0 退步。

## Beyond 出口仍指向 /u/beyond（2026-10-23，KB 06 §7.368）

宁波 / 苏州 / 慕容等区域已进 `/d/ningbo`、`/d/suzhou`、`/d/mr`、`/d/hz`，出口与任务物路径仍写 `/u/beyond/…`。`scripts/lpc_fix_beyond_exits.py` 在目标 `.lpc` 存在时改写（`murong`→`mr`）。本库 1 处。证明：sjplii `xikou` HEAD 西向 `/u/beyond/ningbo/aywsi`，改后 `/d/ningbo/aywsi` 可加载；bxsj `hubian1` 三向均可加载。


## 巫师区出口 faceoff / rence / niulang / yihua（2026-10-23，KB 06 §7.372）

`/u/f/faceoff/`、`/u/r/rence/`、`/u/onskyer/niulang/`、`/u/skinys/yihua/` 对应区域已在 `/open/world1/faceoff/bird/`、`/open/prayer/`、`/d/niulang/`、`/d/yihua/`。`scripts/lpc_fix_wizard_area_exits.py` 在目标存在时改写，仍缺失的出口行删除。本库 1 处。证明：dreamofseven wood5 四向可加载；xlqy_new2007 天河东西向 niulang；kxkj kitchen7 → prayer。


## hanbing `random 反引号（2026-10-27，KB 04 §6.25 Also）

`hanbing-mianzhang` / `hanbing-mianzhang2` 在 `random(` 前多了一个反引号，驱动按模板字面量读到 EOF。删掉。证明：HEAD 失败；改后加载。

## 深度功能测试（2026-10-27，§6.25 zhongling tell_object 引号错位）

`d/wanjiegu/npc/zhongling`（及同路径副本）的 `tell_object("who, 钟灵脱下一双绣花鞋。\n")` 把对象参数写进了字符串；改为 `tell_object(who, "…")`。证明：原文错位；改后加载，语料残渣 0。
