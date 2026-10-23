# wllz3 — 武林列传Ⅲ（186）

档案：`wllz.rar`（33,366,348 字节，2026-10-11 上传到 Drive `backup-mud`）。`config.cfg` 里的名字是「武林列传Ⅲ」，
mudlib 目录 `/root/wllz/world`。文件时间 1999-10-24 到 2009-03-02，中位数 2008-09-07；`nohup.out` 记录 2009-03-02 最后一次启动。

## 二进制发行

源码被有意抹掉：14,242 个 `.c` 里有 7,589 个内容只剩一个字节 `1`（包括 `adm/single/master.c`、
`kungfu/skill` 596 个、`kungfu/class` 345 个、大部分房间）。真正的代码只留在 `binaries/` 下的 9,365 个
MudOS `.b`（`MUDB` 魔数）里：
- 被抹掉的 7,589 个里有 7,588 个有对应 `.b`；唯一缺的是 `d/shaolin/da-shou`。
- 另有 547 个 `.b` 根本没有 `.c`：542 个在 `data/founding`，4 个在 `data/room`，1 个在 `cmds/apr`。
- 6,653 个 `.c` 是完整源码，可直接读。

驱动 `driver`（2007-11-12，ELF 32 位 i386，**未 strip**）：符号表里有 `predefs`、`efun_table`、`instrs`、
`save_binary`、`locate_out`、`disassemble`，所以 efun 编号可以直接从二进制里读出来，不必猜。启动行把版本号
改成了中文字串；符号表和 `.b` 头确认是 MudOS v22pre11（与 033-3 同版本，但 033-3 是 Win32 版）。

`backup/2008-9-7` … `backup/2008-9-13` 是 7 天的玩家存档备份，每天约 3,300 个 `.o`。

## 血统

`d/`、`kungfu/`、`clone/`、`cmds/` 的路径和侠客行（xkx）家族重合 61–65%（hymud、hy5、haiyang2、yxxcii、
fqyy2、hy2002、hy、xkxyb 等），但不比其中任何一个更接近，所以单独编号，不算衍生版。

## 反编译还原（2026-10-11）

工具在 `scripts/mudos_b/`（KB 02 §3.1），全过程可以用 `libs/wllz3/rebuild.sh` 从档案重做一遍。

1. **efun 编号**：`mudos_b.elfdriver` 直接从档案自带的 `driver` 符号表（`predefs`、`efun_arg_types`）读出
   235 个 efun 的编号和参数，写进 `scripts/mudos_b/drivers/wllz3.json`，没有一处是猜的。
2. **反编译**：`mudos_b.cli` 把 9,365 个 `.b` 全部还原成 LPC（类、继承顺序、全局变量初值、函数原型、
   函数指针、switch、foreach、catch 等都按 v22pre11 的代码形状还原）。局部变量名丢失，用 `v1`、`arg1` 代替。
3. **用原驱动验证**：档案自带的 2007 年驱动能在本机跑。`mudos_b.roundtrip` 把每个反编译出来的文件放回
   原驱动重新编译，再把新生成的 `.b` 和档案里的 `.b` 做规范化比较（字符串表、函数表、变量表、跳转目标都换成
   序号后逐条比对）。最后 9,364 个里 9,363 个完全一致，剩下的 `adm/simul_efun/message` 只差一处
   `tell_room` 绑定到 simul 还是本文件（行为相同）。
4. **保留原始源码**：6,653 个完整的 `.c` 里，有 1,043 个在原驱动里编出来和档案的 `.b` 完全一样，
   这些保留原文（带注释），清单是 `decompile/keep-original.lst`。另有 187 个 `.c` 编出来和 `.b` 不一致
   或编不过，说明是过时的源码，游戏实际跑的是 `.b`，所以用反编译版本。
5. **原驱动下可玩**：还原后的 GBK 源码树放回原驱动（删掉 `binaries/`），注册、登录、look、score、quit 都正常。

唯一丢失的是 `d/shaolin/da-shou`：源码被抹成 `1`，也没有 `.b`，原游戏从未加载过它，也没有任何文件引用它，
已删除。反编译出来的文件开头有一行中英文说明。

## FluffOS 移植（2026-10-11）

`rebuild.sh` 的步骤：反编译时用 `--fluffos`（`static` 函数写成 `protected`，`static` 变量写成 `nosave`，
去掉没用到的局部变量）→ 组装源码树 → `convert_lib.sh` → 把被 §4.3 改坏的 `static/` 路径改回来 →
打上 `decompile/fluffos-fixes.patch`（下面这些手工修正）。

- `.lpc` 后缀：`eventd`、`cmds/arch/reload`、`cmds/adm/mup` 里 `[0..<3]` 切 `.c` 的地方改成 `[0..<5]`；
  `cmds/apr/ls`、`cmds/wiz/dir` 用 `lpc_lpc_suffix_slice.py` 修（KB 06 §7.238）。
- 中文判断（KB 07 §8.1）：`is_chinese()` 改成判断 Unicode 码位，`logind` 的 `check_legal_name` 和 15 个
  会给自己起名的 NPC 的长度判断按字符数减半。
- `cmds/arch/clone` 的日志路径 `/log/static/CLONE` 被 §4.3 改成了 `nosave`，改回来（`rebuild.sh` 的回退
  步骤原来只认 `"nosave/` 开头的字符串，已放宽）。
- 编译警告全部清零（`lpc_warnings.py wllz3`）：
  - `inherit/char/npc`、`clone/item/{armor,weapon,horse,wrists}` 和 1,101 个玩家锻造的兵器
    （`data/founding/`）的 `void remove()` 少了 `feature/move` 的参数；`itemd` 生成兵器的模板一起改，
    模板里拼的文件名也从 `.c` 改成 `.lpc`，否则 `raze_item()` 对不上文件名，玩家锻造的兵器销毁时永远删不掉存档。
  - `npc.lpc` 的 `move_or_destruct()` 原来调用 `remove()`，而 `feature/move` 的 `remove()` 只许
    `destruct()` simul_efun 调用，所以 NPC 所在房间被摧毁时一定报错；现在只执行 destruct override。
  - `inherit/room/{recordable,private}_room` 的 `int setup()` 改成 `void`；`d/xingxiu/npc/lingshe` 的
    `hit_ob` 参数个数；`clone/misc/bushouqi`（捕兽器）把自毁函数取名 `clean_up`，和驱动的 `clean_up(int)`
    apply 撞名，驱动每次清理都会把整数当对象传进去报错，改名为 `destroy_trap`。
  - `adm/daemons/gb_b5d` 码表里 GBK 第二字节 `0x5C` 留下的无效转义（同 hy5 的处理）；
    `u/robert/test` 的 `#pragma optimize`；其余 51 个没用到的局部变量。
  - `cmds/arch/tail`：MudOS 有 `tail()` efun，FluffOS 没有；改成读文件最后 8K。原来 `tail here` 判断的是
    还没赋值的 `file`，也改成 `fileName`。
- 仍然编不过的 9 个文件在原游戏里也没有 `.b`（从未加载）：`adm/daemons/network/` 下 intermud 的
  `inetd`、`pingd`、`pingtcp`、`telnetd`、`services/gtell`，`clone/board/news_b`，巫师 robert 的
  `robert-blades`（两份）和 `u/robert/familylist`。保留原样。
- `inherit/room/room` 的 `make_inventory()` 用 `catch` 包住 `clone_object()`，`reset()` 的 `case 1:` 拿到 0
  就跳过（KB 05 §7.25）。`d/forest/famuchang`（伐木场）列的 `npc/jiangong`、`npc/ehan` 档案里根本没有，
  原来整个房间加载失败。

- §9 格式化只用在改过的 30 个原始源码文件上（去掉空白后内容不变）；反编译出来的文件本来就是统一的
  4 空格格式，不再改成 2 空格，免得同一棵树里两种缩进。

## 深度功能测试（2026-10-11，FluffOS 原生 + WASM）

原生驱动（`build-debug`），UTF-8 客户端：
- 注册全流程（英文名 → 中文名 → 密码须含大小写和符号 → 确认 → 邮箱 → OICQ → 性别）、重新连线、
  `quit` 后重新登录、`levelup` 分配属性后存档读档都正常；30 秒内重复连线会被游戏自己的限流挡住，属设计。
- 走路、商店 `list`/`buy 包子 from xiao fan`、`eat`、`chat`、`wllz` 频道、`emote`、和小偷战斗（自动逃跑）、
  `call ->die()` 死亡 → 鬼门关 → `revive`（要说两次）→ 地藏殿 → 判官送回阳间，整套都通。
- 拜师（武当谷虚道长，要求 `guarded`≥1）、`learn guxu with force 3` 学到技能；一次学太多会「太累」，
  是体力公式，不是错误。
- 用临时探针在一个驱动里 `load_object()` 了 `d/`、`clone/`、`kungfu/` 下全部 7,597 个文件：除了上面
  已知的死文件（`news_b`、`robert-blades`、没被引用的 `towiz_b` 指向不存在的 `/d/wizard/guest_room`）
  和已修的伐木场，没有加载错误。

测试中发现并修好的错误：
1. **（严重）放弃注册留下的空身体让该帐号无法登录**（KB 07 §8.26）。`logind` 在填邮箱那一步就
   `make_body()`，之后断线身体就留在世上（没有环境）。玩家下线后 `find_player()` 改为在
   `children("/clone/user/user")` 里找，同 id 有两个以上就 `error("The player(...) has existed in the
   world.")`，`get_passwd()` 中途被打断，登录对象没有命令，所有输入都回「什么？」，直到重启。
   修法：`filter_player()` 只算有环境的身体（`adm/single/simul_efun` 和没用到的 `adm/simul_efun/user`）。
2. `feature/command` 的 `command_hook`（`add_action` 目标）、`feature/action` 的 `eval_function`
   （`start_busy` 的 call_out 目标）、`inherit/item/combined` 的 `destruct_me` 是 `private`，FluffOS 不让驱动
   调用继承来的 private 函数（`apply() with insufficient permission ... has: hidden`）：NPC 的命令和所有
   用函数做的忙碌动作都失效。改成 `protected`（KB 07 §8.3）。
3. `tell_room()` 两参数调用把省略的 exclude 当 0 传给 `message()`（尸体腐烂时报错），`message_system`、
   `other_message` 也显式传 0（KB 05 §7.12）。
4. `cmds/arch/clone` 写 `/log/nosave/CLONE`（见上）。

WASM（`scripts/wasm_client.js`）：注册、look、emote、chat、`wllz` 频道、score、走路、inventory 都正常。
没有 sockets，`dns_master` 编不过：`master` 的 `preload()` 在没有 `__PACKAGE_SOCKETS__` 时跳过
`/adm/daemons/network/`；`channeld` 的 `remove_addresses()`（每个 emote 都会调用）和 `wllz` 频道转发
intermud 之前先 `find_object(dns_master)`，否则 WASM 里每个 emote 和 `wllz` 频道都会报错（KB 01 §1.3c）。
提示符每秒刷新时钟，`wasm_client.js` 要用小于 1 秒的 `--idle`。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`shenghuo-lingfa`→`shenghuo-ling`（`shenghuo-shengong/tougu`、`shenghuo-shengong/yinfeng`）；`mizongxinfa`→`mizong-xinfa`（`longxiang/fanchang`）。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库目前没有对象设了缺失的武功；三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。（`scripts/lpc_guard_set_skill.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 7 处、6 个文件：`tiaji-jian`→`taiji-jian`（2 处）、`lingbo-weibu`→`lingboweibu`（2 处）、`henshan-jian`→`hengshan-jian`（1 处）、`henshan-sword`→`hengshan-sword`（1 处）、`taiji-shenfong`→`taiji-shengong`（1 处）。（`scripts/lpc_fix_skill_names.py`）

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库现有的 NPC 文件里没有字面写成空 `chat_msg` 的（扫描只认 `set("chat_msg", ({ }))`）；守卫挡的是运行时才为空的列表和以后新增的 NPC。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/inherit/char/npc.lpc`（共 1 个文件）。

## 存档里的 `.c` 文件名改成 `.lpc`（2026-10-21，KB 03 §4.2 第 9 项）

存档里写着 `"/d/city/npc/wei.c"` 这样的文件名；extract 时源文件已经全部改成 `.lpc`，而驱动对带扩展名的路径只认字面，`new()` / `load_object()` / `move()` 都找不到它，调用方多半把失败当成「没有这个东西」悄悄跳过。本库 11 个存档共 40 处按 `scripts/lpc_fix_save_dotc.py` 改成 `.lpc`（只改 `.lpc` 存在而 `.c` 不存在的字符串；玩家存档、备份、留言板、巫师目录和文件索引缓存不动）。改动：`/data/npc/luban.o`（16 处）、`/data/room/d/room/road_1e.sav.o`（1 处）、`/data/room/d/room/road_1w.sav.o`（2 处）、`/data/room/d/room/road_2e.sav.o`（1 处）（等共 11 个存档）。

## 巫师命令不带参数时对 0 调用 efun（2026-10-21，KB 06 §7.336）

巫师（管理员）把命令敲成不带参数时，驱动把 0 传给字符串参数；下面的命令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`，这条指令从来没有用过。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py` 在第一处使用参数的语句前加守卫：文件自带 `int help(object me)` 的，守卫是 `if (!arg) return help(me);`（`help()` 定义在 `main()` 之后的 1 个文件补了原型 `int help(object me);`，否则编译报 `Undefined function help`）。改动（2 个文件，括号里是接住 0 的 efun）：`/cmds/adm/denpc.lpc`（`sscanf`）、`/cmds/wiz/test.lpc`（`present`）。加载检查 HEAD 与工作树对照，没有退步。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 3 条注册（2 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/d/city4/qishi.lpc`（`do_pass`、`do_resign`）、`/d/quanzhen/obj/lip.lpc`（`do_quyao`）。最多的函数名：`do_pass` 1 处、`do_resign` 1 处、`do_quyao` 1 处。

## 汉字按字节切片的老写法没有换成按字符：改法名 `"澄" + name[2..3]`、辈分判断 `name[0..1] == "澄"` 等 83 处（2026-10-22，KB 06 §7.360）

原档按字节算字符串区间（一个汉字 2 字节）：`name[2..3]` 是名字的第二个字，`name[0..1] == "澄"` 问名字是不是以「澄」开头。转成 UTF-8 之后，这个驱动的区间和 `strlen()` 都按字符算（`strlen("澄观")` 是 2，`"澄观"[0..1]` 是两个字），老算术原样留着、意思全变：拜入少林 / 武当 / 峨嵋等派的玩家被改成错误的法名（二字名 `张三` 变成一个字的 `澄`，更长的名字取到第三个字）；各派掌门的辈分判断（`name[0..1] == "澄"`）永远不成立。

本库 83 处（45 个文件）：拼名字的赋值 41 处、与汉字常量比较 42 处。例：`v4[2..3]` → `v4[1..1]`（`/adm/npc/da-mo.lpc:114`）；`name[0..1]` → `name[0..0]`（`/kungfu/class/emei/tobebonze.h:33`）；`name[2..3]` → `name[1..1]`（`/kungfu/class/shaolin/cheng.h:129`）。`scripts/lpc_fix_gbk_slice.py` 把下标按字符重算（社区的 UTF-8 版 `xkx100utf8` 里就是同样的写法，作对照）；没有改的：截断（`name = name[0..7]`，现在最多 8 个字，只是放宽）、ASCII 的区间（`fname[0..3] == "room"`、`ctime(time())[4..19]`）和上下文看不出是汉字的区间。证明（`scripts/lpcc_eval.py`，bixiecanyang；其余各库是同一份文本）：让澄字辈掌门 `attempt_apprentice()` 一个名叫「张三」的访客，HEAD 的法名是 `慧`，改后是 `慧三`；抽样 28 个库的 HEAD / 工作树加载对比 0 退步。工具不幂等（`[0..3]` 折半得 `[0..1]`，又是对齐区间），改过的文件记在 `scripts/gbk_slice_converted.txt`，不要重跑。

## 长度检查按字节写，旁边的提示按汉字写：8 处（2026-10-22，KB 06 §7.362）

老档的 `strlen()` 数字节（一个汉字 2 字节），转成 UTF-8 后它数字符：提示写「必须是 2 到 6 个中文字」的检查还是 `strlen(name) < 4 || strlen(name) > 12`，于是两三个字的房名、帮会名、群名、聊天室名、称号被提示自己说允许的那句话拒绝，上限却是提示的两倍；留言板的标题检查 `i < 4 || i > 24 || i % 2` 还会拒绝所有奇数个字的标题（`post 你好吗`）。本库 8 处（2 个文件）：`if( (strlen(faction) < 4) || (strlen(faction) > 8))`（`/cmds/std/factions.lpc:85`）；`if(i < 4 || i > 10)`（`/cmds/skill/sponsor.lpc:42`）。`scripts/lpc_fix_strlen_gate.py` 以提示为准：条件里每个 `strlen` 门槛都恰是提示所说数字的两倍才折半，存长度的变量（`i = strlen(arg);`）的门槛和 `|| i % 2` 奇偶项、其后循环的 `i % 2 == 0 &&` 一并处理；提示里有英文 / 字母 / 字节的不动。证明（`scripts/lpcc_eval.py`，bxsj 的留言板，求值对象继承 NPC 并重写 `edit()` 记录调用，`command("post 标题")`）：HEAD 拒绝「你好」和「你好吗」、放行 23 个字的标题；改后接受前两个、拒绝第三个；shenmo 的 `named.lpc invalid_new_name("张三")`：HEAD 回 `名字只能是2-4个中文字。`，改后回 0。抽样 24 + 15 个库的 HEAD / 工作树加载对比 0 退步。

## 按字节写的汉字循环、茶馆猜诗和同盟频道标题（2026-10-23，KB 06 §7.363）

老档按字节做「一个汉字」：`while (i--) if (i % 2 == 0 && !is_chinese(name[i..<0]))` 只检查偶数下标，奇数位上的拉丁字母（`张a`）会过；茶馆猜诗 `mixup()` 用 `strlen(str)/2` 再 `j=j+j`、`str[k..k+1]` 交换两字节；泥潭系 `channeld` 的 `switch (strlen(fname)) case 4/6/8/10` 和 `strlen(family)==4/6` 按字节长度给同盟 / 门派名加空格。本驱动的 `strlen()` 和区间都按字符算。`scripts/lpc_fix_byte_char.py`：去掉奇偶项、把区间改成 `name[i..i]`，按字符重写 `mixup()` 并把 `strlen(first)>=14` 折成 7，频道标题的 case / 门派长度改成字符数（对照 aoxiangtianji）。本库 汉字循环 / `is_chinese` 区间 2 个文件。证明（`scripts/lpcc_eval.py`）：sjplii 的 `check_legal_name` 在 HEAD 接受「张a」、改后拒绝，两边都接受「张三」；xkx100 的 `clubpoem->mixup("离离原上草")` 得到「离离原草上」（真交换汉字）；nitan_san 两字同盟名得到 `【 兄  弟 】`。关键对象加载通过。
