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
**`work/` 里的任何修改都要同步进 `fluffos-fixes.patch`，否则 `rebuild.sh` 就不能重现这棵树。**

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

`lpc_warnings.py` 全量扫描：14,402 个 `.lpc` 里 14,315 个能加载，**编译警告 0**。编不过的 7 个在原游戏里都没有
`.b`（从来没有加载过），保留原样：`doc/mudlib/efuns`（efun 名字清单，纯文本）、`doc/mudlib/efuns/shiwu`、
`kungfu/skill/feiyuexy`（纯二进制机制的标记文件，内容是一个时间戳，主控对象只检查它在不在）、
`kungfu/skill/hanbing-mianzhang2`、`huang`、`quanzhen-xinfa`、`xixi-unarmed`。

把 14,402 个对象逐个加载（工作树状态，每个驱动进程 700 个）：14,314 个成功，88 个失败，都不是移植造成的：
上面 7 个编不过的文件；`u/snow`、`u/fyue` 巫师工作区的 38 个（这两个巫师不在 `adm/etc/wizlist` 里，他们的对象
读不了 `/kungfu/skill/`，`set_skill()` 就报「No such skill」，而且这两块没有接入游戏世界）；用到档案里根本没有的
技能（`move`、`notracesnow`、`shenzhao-jing`、`kongmingquan`）的 NPC，在 `d/ghost`、`d/quanzhen_old`、
`d/migong/obj/npc1`、`clone/npc/robber`；在 `create()` 或全局变量初值里用 `this_player()` 的对象（玩家锻造的兵器
和护甲、宝石戒指、`adai-quanfa` 等六门技能的招式表），由玩家的动作触发时才能加载，批量加载时没有玩家；以及
网络守护进程和缺数据文件的 `d/miwudao/secret/npc/room`。

