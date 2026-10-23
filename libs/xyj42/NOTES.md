
## WASM 修复摘要（迁移自 meta.json 的 group_note）

同一批里的西游记4.2.rar 是这份档案单纯换行符不同的重复版本（文件树完全一样，每个档案的差异只是 CRLF 对 LF）——只处理了一次，这个 .rar 算作重复，不算独立条目。没有和任何既有档案匹配上 master 哈希。启动干净，不需要任何修复。完整 WASM 修复：给 band.lpc 加了本地回环放行；修复了 logind.lpc 的 make_body() 里因为多余 seteuid(getuid()) 而把 euid 重置掉的 bug；修复了 check_legal_name() 过时的 GBK 字节长度界限；给 securityd.lpc 的 get_status() 加上了防御性保护。另外还发现并修复了 adm/daemons/combatd.lpc 里一个真正的编译阻断问题：一个 switch(random(4)) 代码块里真正的 case 标签全被注释掉了，只剩下一个裸的 default:——这在这个驱动下是非法的（switch 至少要有一个真正的 case，不能只有 default），导致整个档案编译失败，破坏了每一条和战斗相关的代码路径（而且是静默失败，因为错误只在真正有东西调用 combatd 时才会第一次显现）。已把这个 switch 换成一个普通代码块，因为那些被注释掉的 case 本来就从未真正分支过。注册到进入游戏世界、look/score、以及 quit 都已干净验证，没有残留的时序抖动；注意这个血统是先问电子邮件再问性别，和某些手足血统的顺序相反——要读真实的 input_to() 呼叫链，不要假设顺序能照抄。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BBS_BOARD`、`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 24 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## §7.100 sweep (2026-08-19)

Fixed the corpus-wide `inherit ROOM; ... replace_program(ROOM);` redundant-replace bug (AGENTS.md §7.100). 239 live occurrences deleted: 238 via scripted sweep (`fix_710_room.py`), plus 1 hand-fixed roommaker-tool template (`obj/roommaker.lpc`, simple string-builder variant). 2 already-commented-out instances left untouched. No real `.lpc` source found under `work/data/`. Verified via `build-debug` driver boot: clean compile, port 40203 listening, zero new "cannot replace"/"cannot bind" debug.log lines.

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

## 深度功能测试（§10.7 round two，2026-08-27）

用 `build-debug` 驱动完整跑了一次连续的 §10.7 深度游玩测试（单次会话，
Python 原始 socket 脚本），管理员账号种子为 `fluffos` / `Mud@2026`
（`adm/etc/wizlist` 里原本就列着 `fluffos (admin)`，但此前从未真正注册过，
`data/login/f/`、`data/user/f/` 都是空的）——用标准密码注册后确认
`(admin)` 权限即时生效（`目前权限：(admin)`，score 显示【巫师】标记），
密码策略（最短 5 字元）接受这组密码。测试角色：中文名"悟空侠"，男性，
登入 id `fluffos`。

覆盖流程：注册 → look/score/i/hp → 用 `call` 指令临时提高
`combat_exp` 后向灵台方寸山（`d/lingtai/`）二代首徒广筠子拜师成功
（`bai guang`，头衔即时变为"方寸山三星洞第三代弟子"）→ `learn ... from
... with ...`（潜能耗尽时正确报"太累了"并如实扣光剩余精神，
未耗尽时正确 `improve_skill`）→ 用 `clone`+`call set_amount()`
换取货币后在南城客栈跟店小二 `buy`/`eat`/`drink`，金额、负重、
食物/饮水数值均正确更新 → 在留言板 `post`/`read`/`discard`（用内建
的 `.` 结束输入）全部正常，无崩溃 → 与"扫地小童"战斗，命中/闪避/
伤害叙述、`wimpy` 自动脱离战斗都正确触发（脱离触发原因是我自己测试
学艺把"神"值耗到 wimpy 阈值以下，不是 bug，是设计好的双阈值——气或神
低于 wimpy 百分比都会 flee）→ `quit`（`debug.log` 未见任何非 warning
的报错）→ 两次真实等待间隔后重新连线两次，角色状态（头衔、门派、
金钱、道具、attribute）都完整保留，且用第二个临时测试角色验证跨连线
`tell` 双向都能送达对方（本项因两个角色 `mud_age` 都 < 20000 秒被
`block_tell.h` 的新手反滥用机制拦下——核对原始档案字节确认这条
"注册未满约 5.5 小时禁用 tell/say/whisper/reply/emote" 的限制是
1998 年原作者写死在 `cmds/std/block_tell.h` 里的，连巫师也不例外，
不是 WASM 转换或本次测试引入的 bug，是原始设计）。

**标准跨库 bug 形状全数系统性核对（§4.3/§4.4/§7.11/§7.30/§7.80/
§7.86/§7.100/§7.103/§7.112/§7.118/§7.121~§7.153）：均未在本档案命中
新实例。** `securityd.lpc`/`combatd.lpc` 的既有修复（见上面几节）未
回归；`log_file()` 的写入目标目录（`ALLCONT`/`USAGE`/`FILES`）此前
就已存在，未见 §7.11 形状；`set_living_name()` 只在 `enable_player()`
里调用一次（`std/char.lpc::setup()`），reconnect 复用同一个从未
destruct 的活体对象（`obj/user.lpc::reconnect()` 只是重挂
`enable_commands()`），不是"克隆新对象"模式，没有 §7.150/§7.152 的
适用空间；`std/room/hockshop.lpc`/`d/city/sm-room.lpc` 的 `do_list()`
用 `goods[name[i]]` 正确按元素索引，没有 §7.151 的整个 key 数组当索引
用的写法。

**发现并修复：6 个仍是原始 GBK 字节、从未转码的可达文本文件**（和
AGENTS.md §1 記載的 WASM 转码遗漏是同一类问题，只是这次是靠 §10.7 深
度游玩才碰到，不是靠整树 UTF-8 扫描的常规验收）：

- `doc/help/oldhelp/{weapon,guild,taoist}`——虽然没有被任何现存
  `doc/help/topics` 菜单链接到，但 `cmds/usr/help.lpc` 的话题查找是
  裸 `file_size(HELP_DIR + arg)`，只要玩家真的打 `help
  oldhelp/weapon` 这种路径就能读到，实测过（`help oldhelp/weapon`）
  之前会整页乱码。
- `d/ourhome/honglou/poem/{poem74,poem175,poem228}`——`d/ourhome/
  honglou/yard2.lpc` 的猜诗小游戏用 `random(POEMS)` 随机抽一首，这
  三首命中率不算低，玩家迟早会撞上乱码。

全部 6 个文件用 `iconv -f GB18030 -t UTF-8` 转码，转码前后逐字确认是
通顺的古文/说明文字（含裴迪《送崔九》、高适《燕歌行》《送李少府贬峡
中王少府贬长沙》三首唐诗）；文中出现的"□"字符是原文件本来就有的
（`raw/` 归档里字节一致），`yard2.lpc:217` 甚至专门用
`sscanf(poem[index], "%*s□")` 把"□"当成诗谜里特意留白的标记字符处理，
所以刻意保留，没有猜测性地替换成任何字。`doc/help.old/`
（`hints-freehero`、以及重复的 `oldhelp/{weapon,guild,taoist}`）
确认代码里完全没有引用（不是 `help_search_path`/`DEFAULT_SEARCH_PATHS`
的一部分），是打包进档案但从不会被读到的备份快照，本次不处理。
`d/obj/books-nonskill/ALL`、`d/temp/d_obj0610.tar`、`work/driver`、
`adm/tmp/swapfile.*`、`log/log`、`d/kaifeng/npc/bei.c.swp` 这些
UTF-8 解码失败的文件逐一确认是二进制/运行期产物（tar 包、vim 交换
文件、日志、driver 可执行文件残留），不是文本内容，不需要处理。

**观察但未动手改的可疑点**（不确定是不是 bug，留给以后判断）：
`feature/edit.lpc::input_line()` 提示"使用内建列编辑器用
'~e'"，但 `~e` 分支是空代码块 `{}`——不追加这一行到缓冲区，也不启动
任何编辑器，只是静默地继续等下一行输入，跟没打这个命令效果一样。
这是发留言、发信等所有走 `F_EDIT` 的地方共用的框架代码，如果这确实
是个从未补完的功能（而不是本来就该是空操作的占位符），值得以后专门
查一次；没有直接改，因为不确定"内建列编辑器"原本应该长什么样，属于
猜测性实现的范畴，超出本次程式 bug 修复的范围。

**留给未来检查同源库（xyj2006n/xyj2006zzzhx/xyj451/xyj/xyjjqzl）的
线索**：既然 `doc/help/oldhelp/` 这种"没被任何菜单链接、但 help
指令仍然裸路径可达"的残留旧帮助文件在本档案里就藏着 3 个未转码文件，
和"随机抽文本"式小游戏（诗词、灯谜等）用到的独立数据文件一样容易被
整树扫描漏掉（因为只有真正随机抽中或真的打对隐藏路径才会触发），这
两类目录建议在这几个手足库里也各自扫一遍。

清理：测试用的临时小号 `ceshiwo`（仅用于验证跨连线 `tell`）的存档
已在提交前删除；只保留种子管理员账号 `fluffos`（中文名"悟空侠"，
已加入灵台方寸山三星洞门下，测试用的技能/金钱/门派状态原样保留，
作为本次测试的存证）。


## AGENTS.md §7.19 fix: enable_player() reentrancy from init()

`feature/command.lpc`'s `enable_player()` (wrapper around
`enable_commands()`) was reachable from an NPC's `init()` (via the
shared `std/char.lpc` `setup()` chain), and `enable_commands()` is only
safe to call from `create()` -- calling it again on an object already
`living()` makes the driver re-invoke that same object's `init()` as a
side effect, which recursed back into `enable_player()` on the same call
stack until "Too deep recursion" aborted the boot on a room's first-ever
visit. Fixed with a true reentrancy flag (`in_enable_player_now`, set at
entry, cleared before every return), NOT a `living()`-gated guard --
`disable_player()` in the same file legitimately re-calls
`enable_commands()` while already `living()` (sleep/wakeup via
`cmds/std/sleep.lpc`, revive via `feature/damage.lpc`), which a
`living()` guard would silently break. Verified via `lpcc --batch`
single-file compile check (PASS). Part of the corpus-wide §7.19 sweep
(Batch C).

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— tail() simul_efun

`scripts/lpc_add_tail.py --apply`: `cmds/wiz/tail.lpc` calls `tail(file)`, an efun of the MudOS this archive ran on that FluffOS does not have (`Undefined function tail`: the command did not compile). `adm/simul_efun/file.lpc` now defines `void tail(string file)`: the last 10 lines of the file, written to the player. Load check (HEAD against the working tree): 1 of the 1 tail command file(s) failed to load at HEAD, all load now, and the simul_efun file loads. KB 04 §6.2.

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `std/room.lpc`：`make_inventory()` 用 `catch()` 包住 `new(file)`，做不出来就返回 0；`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-07）— 编译警告整理

`scripts/lpc_warnings.py xyj42 --fix` 加 `scripts/lpc_fix_no_effect.py --apply`，共改动 354 个 `.lpc` 和 6 个 `.h`（多为删去未用的局部变量）。HEAD 与工作树分别加载（新进程）：338 -> 338 通过，无回退；改过的头文件的 216 个包含者 215 -> 215 通过。

启动时警告 26 -> 0；新进程登录（新人物确认）正常。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 2 处，返回类型/原型 5 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 5 个，只在 #if 分支用的声明移进分支 1 个文件；改动 9 个文件，HEAD 与工作树各载入一次无回退（9 objects; HEAD PASS 8, tree PASS 8; regress 0; newly loading 0），这些文件的警告 30 -> 18。

## 深度功能测试（§10.7，2026-10-12）：编译警告收尾

`scripts/toolkit_fix.sh` 加手工修复，能编译的文件里的警告 63 -> 0（`lpc_warnings.py xyj42` 重扫：4766 个文件可编译；剩下 1 条警告在本来编译不过的文件里）。这次没有发现玩法上的真 bug，都是结构性的重复：

- 40 处多余的 `inherit`（`lpc_diamonds.py --fix-redundant`）：38 个 NPC/武器/房间/sserver 叶子又 `inherit F_CLEAN_UP`（基类已经带了）；`daemon/skill_wiz/sword/wind.lpc` 在一段注释诗后面又写了一遍 `inherit SKILL;`；`d/qujing/pingding/obj/weapon.lpc` 的 `inherit F_BLADE;` 连写两遍。同一份代码两条路径进来，删掉一份不改变行为。
- `d/kaifeng/ground.h`：三张常量表被 `ground0.lpc` 和一个个继承它的 `ground1/2/3.lpc`、`ground.lpc` 各包含一次；表格包进 `#ifndef GROUND_TABLES_INHERITED`，派生房间在包含前定义它（KB 04 §6.10）。
- `include/net/ftpdconf.h`：`VALID_READ`/`VALID_WRITE` 重定义 `ftpd.h` 的值，前面加 `#undef`（本来就是后一个定义生效）。

验证：改动文件、`d/kaifeng` 全部对象和包含 ftpd 头文件的对象共 157 个，HEAD 与工作树各用新进程载入：154 -> 154 通过，regress 0；删除声明审计 0 项待看。157 个对象载入无回退。

## 转码吃掉的引号（2026-10-15，KB 03）

原档在右引号前有一个孤立的 GBK 前导字节，转 UTF-8 时连引号一起丢了（如 `return name + HIM "发作身亡了;`），字符串一直延续到后面，文件编译失败：`/d/obj/books-nonskill/hmeng014`。补回引号（`scripts/lpc_fix_eaten_quote.py`）。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`baihua_zhang`→`baihua-zhang`（`/daemon/class/moon/baihua-zhang/flower`）。

## 存档读不出来：字符串里的换行、空行（2026-10-15，KB 03 §4.4）

`u/tutu/star.o`：字符串里有原样的换行（`save_object()` 存成 `\r`，`restore_object()` 逐行读，原样的换行让字符串收不了尾），或有空行（`Illegal file format`），读档的对象（留言板、NPC、玩家）从空白开始。换行改写成 `\r`、删去空行（`scripts/lpc_save_encoding.py --from-raw`），驱动核对全部能读回（`scripts/lpc_save_restore_check.py`）。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

16 个文件、19 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`），多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/d/city/npc/obj/choupao`、`/d/city/npc/obj/bingfu`、`/d/city/npc/obj/cloth`）。本库 NPC 基类 `std/char/npc.lpc` 的 `carry_object()` 第一句是 `if (file->query_unique())`，对不存在的文件直接 call_other，驱动在这里报 `call_other() couldn't find object`，`new()` 来不及返回 0，所以只要 NPC 带着一件本库没有的物品就载入不了（调用处加判断对它无效）。在它前面补 `if (!objectp(load_object(file))) return 0;`（`--base`），缺的物品就跳过，NPC 照常载入；上面那些调用处同样改成带判断的块（基类以后改回去也不怕）。载入检查：改动的文件改前能载入 1 个，改后 16 个（15 个原来载入不了），没有退步；其余 1 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## 去掉的预定义宏 `SAVE_EXTENSION`（2026-10-18，KB 04 §6.11）

老版 MudOS 给每个 LPC 对象预先定义了 `SAVE_EXTENSION`（`".o"`）；FluffOS 的 ChangeLog（COMPAT_BUSTER 一条）把它删了，改用 `__SAVE_EXTENSION__`。本库没有自己 `#define` 这个宏，用到它的文件一律 `Undefined variable 'SAVE_EXTENSION'`，整个对象载入不了。改成 `__SAVE_EXTENSION__`（`scripts/lpc_fix_predefined_macro.py`）：`adm/daemons/network/netmail.lpc`、`include/net/ftpdsupp.h`。`netmail` 是网络邮件守护进程（本库缺 `mailer.h` 等头文件，改后仍载入不了）。改后用 `lpcc` 逐个载入这些对象：0 个通过，1 个还有别的错误（`adm/daemons/network/netmail`：/adm/daemons/network/netmail.lpc:17: error: Cannot #include mailer.h）。

## `d/moon/obj/poem` 两句诗丢了收尾的引号（2026-10-18，KB 03 §4.6）

`string *poem` 数组里 `"不放玉花飞堕地，留在广寒宫阙。,` 和 `"把酒送春春不语，黄昏却下潇潇雨。,` 的收尾引号没了（转码时跟半个汉字一起丢了），下一行的开引号把字符串合上，后面的诗句成了代码：`Illegal character 0xe6`，整个物件载入不了。补回 `",`。载入：通过。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 12 个对象设了本库没有文件的武功（20 个名字，最多的是 `perception`、`celestial`、`celestrike`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：12 个里 12 个通过。（`scripts/lpc_guard_set_skill.py`）

## 补回本库没有的基类文件（2026-10-18，KB 04 §6.15）

下面这些基类本库没有，继承它们的对象（房间、NPC、物品）整批载入不了（`inherit XXX;` 的宏没定义，或者 `inherit "/std/…";` 的文件不在）。同系的库里有同名文件，两库有大量逐字节相同的文件（亲缘关系），所以从那边原样拷来，缺的宏补进全局头文件 `include/globals.h`：`/std/weapon/unarmed`（宏 `UNARMED`）←sjsh，1 个对象继承它，抽样 1/1 载入。每个基类补回后单独载入、再抽样载入使用它的对象，基类载不进来或者一个用户也载不进来的就撤掉（本库撤掉了它们，不再补）。（`scripts/lpc_restore_bases.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 3 处、3 个文件：`yange_blade`→`yange-blade`（1 处）、`dragon-step`→`dragonstep`（1 处）、`huntian-qiong`→`huntian-qigong`（1 处）。（`scripts/lpc_fix_skill_names.py`）

## 调用了父类没有的函数的对象（2026-10-19，KB 06 §7.259）

`::create();`、`::init();`、`return ::buy_object(who, item);` 这类调用写的是父类里有这个函数的版本；本库的父类没有，旧驱动把它当空操作（返回 0），现在的驱动在编译时就报 `Unable to find the inherited function`，整个对象载入不了。单独成句的调用删掉，`return ::f(...)` 改成 `return 0;`（void 函数里是 `return;`），与旧驱动的行为一致。共 1 处、1 个文件：`::buy_object()`（1 处）。只改了出错原因全是这一类的文件；还带着别的错误（多半是父类本身没了）的文件没动，等父类补回后再看。（`scripts/lpc_fix_dangling_super.py`）

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 被注释吞掉的 inherit / include（2026-10-19，KB 06 §7.274）

`/daemon/class/moon/moonshentong/shiyue.lpc`：`inherit SSERVER;`。这些指令接在上一行 `//` 注释的末尾（档案里丢了换行），成了注释的一部分，驱动看不到：缺 `inherit` 的技能报 `Undefined function offensive_target`，缺 `#include <weapon.h>` 的兵器报语法错误。`scripts/lpc_fix_swallowed_directive.py` 把换行放回去。载入检查 1 个文件，1 个原来编译不过、现在载入，没有退步。

## `call_out_info()` 的每一项只有 3 个元素（2026-10-20，KB 06 §7.287）

驱动返回的是 `({ 物件, 函数, 延迟 })`，不带 call_out 的参数，旧代码读第 4 项 `info[i][3]`（`callouts` 指令、`calloutd`、`cod` 工具）一读就报 `Array index out of bounds`，指令从第一行起什么也打印不出来。改为 `(sizeof(info[i]) > 3 ? info[i][3] : 0)`（`scripts/lpc_fix_callout_info.py`）。改动：`/cmds/arch/callouts.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 1 处）。改动：`/cmds/wiz/dns.lpc`（1 处）。

## `callouts`：`sizeof(info[i]) == 4` 把每一行都挡掉了（2026-10-20，KB 06 §7.287）

驱动的 `call_out_info()` 每项只有 3 个元素，输出行前的守卫 `if (sizeof(info[i]) == 4)` 永远不成立，指令只打印表头。改为 `>= 3`。改动：`/cmds/arch/callouts.lpc`（1 处）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/obj/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## sefun `cat()`：缺文件时 `write(0)` 报错（2026-10-20，KB 06 §7.297）

`void cat(string file) { write(read_file(file)); }`：文件不存在（压缩包没带的欢迎/公告文件，或只有运行中的 mud 才会写的日志）时 `read_file()` 回 0，`write(0)` 在本驱动里报 `Bad argument 1 to receive()`，调用者（登录对话、`cat` 指令）被中断；老驱动什么也不打印。改成 `write(read_file(file) || "");`（`scripts/lpc_fix_cat_unchecked.py`）。改动：`/adm/simul_efun/file.lpc`。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库有 1 个 NPC 文件写成 `set("chat_msg", ({ }))`（或 `chat_msg_combat`）并带正的 `chat_chance`（例如 `/daemon/class/oldstuff/ronin/master.lpc`），每次心跳有 `chat_chance`% 的概率 `random(0)` 为 0、`msg[0]` 报 `Array index out of bounds`（驱动捕获，心跳继续，但每次一条运行时错误），这个 NPC 在内存里就一直发生。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/std/char/npc.lpc`（共 1 个文件）。

## 巫师命令不带参数时对 0 调用 efun（2026-10-21，KB 06 §7.336）

巫师（管理员）把命令敲成不带参数时，驱动把 0 传给字符串参数；下面的命令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`，这条指令从来没有用过。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py` 在第一处使用参数的语句前加守卫：文件自带 `int help(object me)` 的，守卫是 `if (!arg) return help(me);`（`help()` 定义在 `main()` 之后的 1 个文件补了原型 `int help(object me);`，否则编译报 `Undefined function help`）。改动（1 个文件，括号里是接住 0 的 efun）：`/cmds/wiz/test.lpc`（`present`）。加载检查 HEAD 与工作树对照，没有退步。

## `cast1`：宏 `SYNTAX` 带着分号（2026-10-21，KB 04 §6.28）

`#define SYNTAX "指令格式：cast <法术> [<参数>| on <目标>]\n";` 的 `;` 属于宏展开，`notify_fail(SYNTAX);` 变成 `notify_fail("..." ;);`，整个指令编译不了（`unexpected ';'`）。去掉宏里的分号，并删掉没用到的局部变量 `dest`（编译警告）。

## `pk`、`rget`、`tianfu`（2026-10-21，KB 06 §7.336、KB 04 §6.28）

`pk`、`rget`（巫师指令）不带参数时 `Bad argument 1 to sscanf() Expected: string Got: 0.`（管理员扫描的控制台行）：在 `if (sscanf(arg, ...) == 2);` 前面加了 `if (!arg) return help(me);`（并补上 `int help(object me);` 原型）。`tianfu` 编译不了：原型 `string display_attr(int gift, int value);` 和定义 `varargs string display_attr(string gift, int value, int effective)` 对不上，原型改成和定义一致（兄弟库的原型本来就对）。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 8 条注册（5 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/d/changan/pinqiting.lpc`（`do_pass`、`do_resign`）、`/d/city/npc/duguoyin.lpc`（`do_vendor_list`）、`/d/lingtai/npc/kancai.lpc`（`do_vendor_list`）、`/d/qujing/jisaiguo/obj/luche.lpc`（`do_get`、`do_put`）、`/d/qujing/wudidong/cave2.lpc`（`do_push`）。最多的函数名：`do_vendor_list` 2 处、`do_push` 2 处、`do_pass` 1 处、`do_resign` 1 处、`do_get` 1 处。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 另有 1 处函数体被作者整段注释掉（指针没跟着删），是有意关掉的，没动。

## 运行期目录 `log/nosave` 不存在，写日志的 `write_file()` 直接报错（2026-10-22，KB 03 §4.3 补充）

这个库的 6 个文件里有 10 处 `write_file("/log/nosave/...")` / `log_file("nosave/...")`（`static` 改 `nosave` 时连字符串里的日志路径一起改了，原来是 `log/static/`）：`nosave/CRASHES`、`nosave/CALL_PLAYER`、`nosave/PURGE` 等。压缩包和站点包里没有这个目录，`write_file()` 在目录不存在时抛 `*Wrong permissions for opening file /log/nosave/... for append. "No such file or directory"`，调用它的函数（杀人记录、重启记录、`call` 日志……）当场中断。把 `log/nosave` 记进 `scripts/wasm_keep_dirs.txt`（站点和 pristine 树都按它建空目录）；没有把字符串改回 `static`。证明（`scripts/lpcc_eval.py`，`catch(write_file("/log/nosave/ZZTEST", ...))`，fqyy2 / hy5 / bmxkx2001 的新进程）：补目录前报上面的错误，补后写成功。

## `(: 函数名 :)` 指针指向本库没有的函数：只含这个指针的行加了注释（2026-10-22，KB 06 §7.355 补充）

`inquiry` / `item_desc` / `chat_msg*` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：用到时（`ask`、`look`、NPC 闲聊）驱动抛 `*Undefined lfun pointer called: 函数名`，这一拍心跳的后半段被跳过。这些函数没有可以补回的来源（别的库同一路径的文件里没有，或者它还要用本库没有的东西），所以 1 个文件里 2 行只含这个指针的行（`"剃度": (: ask_for_join :),` `"出家": (: ask_for_join :),`）加了注释，原文保留并写明原因，这一项当作没有这个话题 / 物品 / 闲聊条目（`scripts/lpc_fix_dangling_lfun.py`；`#include` 的文件在库里缺失的对象、指针不在整行上的写法没动）。 前提（`function_exists()`）和加载检查（HEAD 与工作区对比，本库改动的 `.lpc` 文件）的结果见 KB 06 §7.355：没有一个回归。

## 汉字按字节切片的老写法没有换成按字符：改法名 `"澄" + name[2..3]`、辈分判断 `name[0..1] == "澄"` 等 3 处（2026-10-22，KB 06 §7.360）

原档按字节算字符串区间（一个汉字 2 字节）：`name[2..3]` 是名字的第二个字，`name[0..1] == "澄"` 问名字是不是以「澄」开头。转成 UTF-8 之后，这个驱动的区间和 `strlen()` 都按字符算（`strlen("澄观")` 是 2，`"澄观"[0..1]` 是两个字），老算术原样留着、意思全变：拜入少林 / 武当 / 峨嵋等派的玩家被改成错误的法名（二字名 `张三` 变成一个字的 `澄`，更长的名字取到第三个字）。

本库 3 处（2 个文件）：拼名字的赋值 3 处。例：`name[0..1]` → `name[0..0]`（`/d/nanhai/npc/master.lpc:102`）。`scripts/lpc_fix_gbk_slice.py` 把下标按字符重算（社区的 UTF-8 版 `xkx100utf8` 里就是同样的写法，作对照）；没有改的：截断（`name = name[0..7]`，现在最多 8 个字，只是放宽）、ASCII 的区间（`fname[0..3] == "room"`、`ctime(time())[4..19]`）和上下文看不出是汉字的区间。证明（`scripts/lpcc_eval.py`，bixiecanyang；其余各库是同一份文本）：让澄字辈掌门 `attempt_apprentice()` 一个名叫「张三」的访客，HEAD 的法名是 `慧`，改后是 `慧三`；抽样 28 个库的 HEAD / 工作树加载对比 0 退步。工具不幂等（`[0..3]` 折半得 `[0..1]`，又是对齐区间），改过的文件记在 `scripts/gbk_slice_converted.txt`，不要重跑。

## 按字节写的汉字循环、茶馆猜诗和同盟频道标题（2026-10-23，KB 06 §7.363）

老档按字节做「一个汉字」：`while (i--) if (i % 2 == 0 && !is_chinese(name[i..<0]))` 只检查偶数下标，奇数位上的拉丁字母（`张a`）会过；茶馆猜诗 `mixup()` 用 `strlen(str)/2` 再 `j=j+j`、`str[k..k+1]` 交换两字节；泥潭系 `channeld` 的 `switch (strlen(fname)) case 4/6/8/10` 和 `strlen(family)==4/6` 按字节长度给同盟 / 门派名加空格。本驱动的 `strlen()` 和区间都按字符算。`scripts/lpc_fix_byte_char.py`：去掉奇偶项、把区间改成 `name[i..i]`，按字符重写 `mixup()` 并把 `strlen(first)>=14` 折成 7，频道标题的 case / 门派长度改成字符数（对照 aoxiangtianji）。本库 汉字循环 / `is_chinese` 区间 2 个文件；茶馆猜诗 `mixup` 1 个文件。证明（`scripts/lpcc_eval.py`）：sjplii 的 `check_legal_name` 在 HEAD 接受「张a」、改后拒绝，两边都接受「张三」；xkx100 的 `clubpoem->mixup("离离原上草")` 得到「离离原草上」（真交换汉字）；nitan_san 两字同盟名得到 `【 兄  弟 】`。关键对象加载通过。

## 血条 / 表情标题按字节算显示宽度（2026-10-23，KB 06 §7.365）

老档把汉字当两字节：`bar_string[0..(val * N / max) * 2 - 1]` 把「格数」换成字节下标，半格血条在本驱动（按字符算区间）上会整条画满；巫师表情 `edemote` 的 `repeat_string("─", 13 - (strlen(emotion) / 2))` 也会少减汉字宽度。`scripts/lpc_fix_display_pad.py`：去掉 CJK 血条 / 空白条上的 `* 2`（`jings`/`qis` 赋值和 `blank_string3[0..(23-a)]` 的 23→11 一并改），表情标题去掉 `/ 2`；ASCII 空格的 `none_string` / `empty_string` 仍保留 `* 2`（一格两个空格）。本库 4 处（2 个文件）。证明（`lpcc_eval.py` hhsj）：`tribar_graph(6,9,12)` 在 HEAD 画出整条 12 个■，改后为 6 个■+3 个□；麻将 `strlen(tempB)/2` 是两字符牌码，未改。

