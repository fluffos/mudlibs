
## WASM 修复摘要（迁移自 meta.json 的 group_note）

西游记2006之最终幻想——另一个 AKAI Studio Tomud 品牌分支，是 122 号 xyj2006n 的手足档案（文件布局和 bug 模式完全相同；需要同样的自定义客户端版本握手：第一行回复必须是字面的 '2060'）。WASM 修复了和 xyj2006n 完全相同的 5 类 bug：（1）标准的 §6.6 convertd.lpc 希腊字母表反斜杠错字（45 处，真正生效的 adm/daemons/convertd.lpc 和一份死代码副本 daemons/convertd.lpc 里都有），（2）4 处绝对路径尖括号 #include 在这个驱动的 include 目录规则下永远解析不了，（3）message.lpc 的 tell_room() 把未设置的 exclude 转发进 message() 第 4 个参数（§7.12），（4）两个残留的原始 GBK 内容档案（beast1.lpc、shuijingqiu.lpc）已用 iconv 重新转换，（5）真正生效的 adm/daemons/logind.lpc 的 check_legal_name() 标准 §8.1 奇偶门槛/后缀切片写法改成了逐码点写法，另外还有 6 处 is_killing(me) 对照 is_killing(string id)（§7.50）的呼叫点，分布在 daemon/class/*.lpc 的 kungfu 技能档案里。以上全部都是靠 scripts/lib_bulk_fix.py（机械修复 1-3）和 scripts/scan_known_bugs.py（4-5，两个都是本次会话新写的工具）在第一次启动测试之前就主动抓出来的，而不是一次启动周期发现一个。httpd.lpc/ftpd.lpc/dns_master.lpc 不在真正生效的预加载列表里（休眠状态，只能通过巫师手动加载触达）——没有掏空，标记为和 xyj2006n 一致的已知潜伏风险。管理员账号播种：fluffos (admin) 加入 adm/etc/wizlist。注册流程在一次连续的 WASM 客户端会话里完整验证过：版本握手（2060）→new→英文 id→中文名字→管理员密码+确认→登录密码+确认→电子邮件→性别（m/f）→属性分配菜单（9/y）→进入游戏世界，look/score 都干净，零错误，管理员权限通过"目前权限：(admin)"确认。LPC 格式化工具对全部 9264 个档案运行（写入 9119 个，8 个转档之前就存在的未结束字符串/文本块内容错误未做格式化，137 个未改动）。没有 :: 父类呼叫拆分命中，没有 CJK 重新加空格命中；case 标签带尾随注释的盲点找到了和 xyj2006n 一样的 combatd.lpc/ftpd.lpc 命中，逐一 diff 复核确认格式化工具正确保留了后面的每一条语句。格式化后重新验证干净。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BBS_BOARD`、`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 36 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## §7.100 sweep (2026-08-19)

Fixed the corpus-wide `inherit ROOM; ... replace_program(ROOM);` redundant-replace bug (AGENTS.md §7.100). 235 live occurrences deleted: 234 via scripted sweep (`fix_710_room.py`), plus 1 hand-fixed roommaker-tool template (`obj/roommaker.lpc`, simple string-builder variant). 6 already-commented-out instances left untouched. No real `.lpc` source found under `work/data/`. Verified via `build-debug` driver boot: clean compile, zero new "cannot replace"/"cannot bind" debug.log lines; boot log appeared to stall due to stdio buffering during a large preload (per standing lesson) — confirmed healthy via a raw-socket connect showing the real login banner rendering correctly on port 40159.

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

## Deep functional test (round two, 2026-08-27)

用 `build-debug` 驱动跑了一次连续的 §10.7 深度游玩测试（Python 原始
socket 脚本），管理员账号种子为 `fluffos` / `Play2026x`（管理密码
`Mud@2026`，登录密码必须与管理密码不同——`adm/etc/wizlist` 里原本就
列着 `fluffos (admin)`，但从未真正注册过，`data/{login,user}/f/` 都
是空的）。注册流程：版本握手（首行发字面 `2060`）→ `new` → 英文 id
`fluffos` → 中文名"悟空侠" → 管理密码 → 确认 → 登录密码（必须与管理
密码不同）→ 确认 → 电子邮件 → 性别（m）→ 天赋分配菜单（`d/wiz/init.
lpc`，选 `9` 接受默认值 → `y` 确认）→ 进入游戏世界，落地南城客栈，
look/score/i/hp 全部干净，"目前权限：(admin)"确认管理员权限即时
生效。

**发现并修复 4 个真实程式 bug（3 个是既有 AGENTS.md 条目的新确诊实例，
1 个是全新 bug class，已写入 AGENTS.md §7.154）：**

1. **`adm/simul_efun/file.lpc` 的 `log_file()` 从未调用同文件里现成的
   `assure_file()`，往从未打包的 `/log/nosave/` 目录写入直接崩溃**
   （AGENTS.md §7.11，和手足档案 `xyj2006n` 的同一处发现完全一致）。
   现场复现：管理员 `call akaigege->query("name")`（一个正常的巫师
   `call` 指令，命中 `cmds/wiz/call.lpc` 的 `log_file("nosave/
   CALL_NPC", ...)`）在修复前会抛出未捕获的 `执行时段错误：*Wrong
   permissions for opening file /log/nosave/CALL_NPC for append.`。
   `cmds/usr/suicide.lpc` 的真实销号路径也走同一个 `log_file()`，意味
   着欢迎横幅明确宣传的 `suicide -f` 指令原本也会在真正删档之前就崩溃
   中止。**修复**：补上前向声明 `void assure_file(string file);`，并在
   `log_file()` 里先呼叫 `assure_file(LOG_DIR + file);` 再
   `write_file`。修复后现场复验：同一条 `call` 指令干净完成，
   `/log/nosave/CALL_NPC` 正确写入审计记录。这是全项目共用的
   simul_efun，等于同时修好了 `cmds/wiz/call.lpc`、`cmds/wiz/clone.
   lpc`、`cmds/arch/purge.lpc`、`cmds/arch/purgehouse.lpc`、`cmds/adm/
   xpass.lpc`、`cmds/adm/superpass.lpc`、`cmds/usr/suicide.lpc` 等全部
   写入 `nosave/...` 或其他从未打包子目录的呼叫点。

2. **`adm/obj/master.lpc` 的 `log_error()` 把每一条普通编译 WARNING
   （不仅仅是真正的 ERROR）原样广播给任何连线中的玩家**（AGENTS.md
   §7.103，和 `zzfy3`/`xyj2006n` 的形状一致）。现场复现：新注册角色
   打 `look`/`score`/`i` 这类首次触发懒编译的指令时会看到
   `编译时段错误：...warning: ...` 的横幅式输出。**修复**：
   `if (this_player(1)) ...` 改为 `if (this_player(1) &&
   strsrch(message, "warning:") == -1) ...`，和项目内既有修法一致。

3. **`adm/daemons/toptend.lpc` 的 `topten_save()` 往从未打包的
   `/data/topten/` 目录 `write_file(f_name, str, 1)`（第 3 参数为
   overwrite 模式），没有 `assure_file()` 防护，直接抛出未捕获错误**
   （AGENTS.md §7.11 第三次独立确诊，和 `nitan_ceshi`/`xixingzhanji`
   两个不相关血统里的同一形状一致）。这个呼叫点在 `logind.lpc::
   enter_world()` 里对每一次登入（新注册和老玩家重新登入都一样）
   都会执行，`debug.log` 里连续出现两次一模一样的 `*Wrong permissions
   for opening file /data/topten/rich.o for overwrite. "No such file
   or directory"` 崩溃记录。因为 `topten_checkplayer()` 在这个档案里
   排在 `move(startroom)` 之后才呼叫，崩溃不会让新角色卡在空气里（比
   `xixingzhanji` 那次轻），但十一个排行榜（rich/pker/kill/spells/
   exp/daoxing/force/per1/per2/age/qn）从此全部永久失效，且每次登入都
   会静默崩溃一次。**修复**：在 `write_file()` 前加
   `assure_file(f_name);`，同一处呼叫点覆盖全部十一种排行榜。修复后
   现场复验：`fluffos` 用 `get_passwd()` 真实密码登入路径重新连线，
   `debug.log` 全程零新增记录。

4. **全新 bug class，已登记为 AGENTS.md §7.154：`cmds/std/look.lpc::
   look_room()` 判断"天太黑看不清出口"的分支无条件呼叫
   `present("fire", this_player())`，但这个函数不只被 `look` 指令呼叫
   ——`feature/move.lpc::remove()`（每次 `destruct()` 都会呼叫，用来
   在被摧毁物件离开房间时刷新房间描述）和 `adm/daemons/natured.lpc::
   event_dawn()`（驱动自己的日夜循环心跳）也会呼叫它，这两个呼叫路径
   下 `this_player()` 都合法地是 `0`，而 `present()` 的第二个参数要求
   必须是 object，传 `0` 直接抛出未捕获的 `*Bad argument 2 to
   present()`。现场复现：开服头两分钟内自然发生的 `obj/corpse.lpc::
   decay()`（户外房间的尸体腐烂到"化为骨灰"阶段，`destruct()` 触发
   `remove()`→`look_room()`）在子/丑/寅/亥时辰各自崩溃了一次（同一次
   session 内连续撞到 5 具），以及驱动自己的 `natured.lpc` 日夜切换
   摧毁一个户外 NPC 时也命中同一条崩溃路径——全部发生在没有任何玩家
   指令参与的背景 `call_out()` 里，常规游玩测试如果没有恰好撞上这些
   时辰完全不会发现，只能靠 `debug.log` 抓到。**修复**：在
   `present()`/`wizardp()` 之前加 `objectp(this_player())` 短路守卫：
   ```lpc
   if (env->query("outdoors") &&
     objectp(this_player()) &&
     !present("fire", this_player()) &&
     !wizardp(this_player()) &&
     (...))
   ```
   修复后现场复验：两轮完整 quit/reconnect 周期加上后续游玩session里
   `debug.log` 再无 `present()` 崩溃记录。**手足档案 `xyj2006n` 的
   `cmds/std/look.lpc:410` 是逐字节相同的未修复版本，留给以后专门检查
   （AGENTS.md §7.154 已记录，下次测 `xyj2006n` 或任何 `xyj*`/`西游记`
   血统时先 grep 一遍 `present("fire", this_player())`）。**

**发现并修复：3 个仍是原始 GBK 字节、从未转码的可达文本文件**（与
`xyj42` 深度测试发现的同一类残留缺口——同一个诗词猜谜小游戏，同一批
唐诗数据文件）：`d/ourhome/honglou/poem/{poem74,poem175,poem228}`——
`d/ourhome/honglou/yard2.lpc` 的猜诗小游戏用 `random(POEMS)`（
`POEMS=319`）随机抽一首，这三首命中率不算低。全部用
`iconv -f GB18030 -t UTF-8` 转码，转码前后逐字确认内容完整通顺（
裴迪《送崔九》、高适《燕歌行并序》《送李少府贬峡中王少府贬长沙》三首
唐诗），并与 `raw/` 原始归档逐字节比对确认转码前内容完全一致。
`poem74` 里的"［扌从］"括号记法是原文件本来就有的合字表示法，原样
保留未动。本档案的 `doc/oldhelp/`（24 个文件）经全树扫描确认全部
已是合法 UTF-8，没有 `xyj42` 那种 `doc/help/oldhelp/` 遗漏实例。
另有 `gift.f`、`mfm1992`、`who.hxl` 三个非 UTF-8 文件，逐一确认只在
`WS_FTP.LOG`（FTP 客户端传输日志）里被提及，代码里没有任何
`load_object`/`read_file`/`clone_object` 引用，是打包进档案但从不会
被读到的孤儿文件，本次不处理；`.swp`/`.swo`（vim 交换文件）、
`MudOS.exe`/`d/shushan/back/driver`/`d/shushan/back/addr_server`（
driver 可执行文件残留）、`d/qujing/wuji2/xx.arj`（压缩包）、
`log/log`（运行期日志）逐一确认是二进制/运行期产物，不是文本内容。

**标准跨库 bug 形状全数系统性核对（§4.3/§4.4/§7.11/§7.30/§7.80/
§7.86/§7.100/§7.103/§7.112/§7.118/§7.121~§7.153，以及本次新增的
§7.154）：** §4.3（无 `log_file()` 呼叫点的字面路径参数里含
"static"）、§4.4（全树无残留非 UTF-8 字节，`.lpc` 源码零命中，见上
方文本文件小节）均未命中新实例；§7.86/§7.100 既有修复（NOTES.md
上方两节）未回归；§7.30 既有修复（`feature/skill.lpc` 3 个 accessor）
未回归；§7.129（`message.lpc` 的 `tell_room()` 已有 `exclude ||
({})` 防护，未回归）；§7.131/§7.152（`obj/user.lpc` 的
`set_living_name()`/`reconnect()` 正常工作，现场用两个连线互相
`tell` 验证过，断线前后都能送达）；§7.150（`get_passwd()` 直接对
`login` 物件自身的密码栏位做 `crypt()` 比对，没有另外 clone 一个
`LIVING` 来验证密码，不适用）；§7.153（`feature/more.lpc` 的
`morefile()`/`more()` 两套分页 `switch` 均正确处理 `"b"`/`"q"`/
default，`std/bboard.lpc::do_read()` 的 `"new"`/`"next"` 分支正确
接 `else`）；§7.148（全树无参数名为 `nosave`/`static` 的函数签名）；
§7.146（全树无孤立单斜杠误当注释的写法，几处误报核实为地图 ASCII 图
字符串字面量内容）。均未在本档案命中新实例（除上述已列出的 4 个）。

**留言板测试**：南城客栈留言板 `post <标题>` → 内建编辑器输入正文，
`.` 结束 → `read <编号>` 显示完整内容（作者/标题/时间/正文/IP 全部
正确）→ `discard <编号>` 删除成功，`read` 后确认"没有任何留言"。全程
无崩溃，未见 §7.86/§7.151 形状（这个留言板的 `do_read`/`do_discard`
用的是普通编号 `notes[num]`，不是 do_list 式的整个 key 数组索引）。

**商店测试**：南城客栈店小二 `list` 正确显示带价格的完整商品清单，
`buy huasheng from xiao er`（身无分文的新角色）正确返回"你的钱不够"
而非静默无操作或崩溃。

**拜师/学艺测试**：灵台方寸山三星洞二代首徒广筠子（`bai guang`，用
`call me->set("combat_exp", 40000)` 越过其 30000 点道行+经验门槛
后）拜师成功，头衔即时变为"方寸山三星洞第三代弟子"；`learn force
from guang` 正确 `improve_skill`。首饰赠功 NPC 阿凯哥哥（南城客栈）
`ask akaigege about fangcun` 一次性赠予十三种基础技能，`yudian/
skills` 门闩正确防止二次领取（"你不是已经要过功夫了吗？"）。

**安全切磋测试**：`std/char/npc.lpc::accept_fight()` 的默认（非
`friendly`）态度 NPC 会接受 `fight` 指令且不致命（`help fight`：
"点到为止...不会真的受伤"）；找到灵台方寸山讲经堂的小道士（
`attitude: peaceful`，命中 default 分支）实测 `fight xiao dao` —
命中、闪避描述正常，交手片刻后手动中断测试（未打到分出胜负，出于
时间预算考虑），未见异常。`d/city/obj/muren.lpc`/`d/obj/misc/
muren.lpc`（镜像对手属性的木人训练假人，和 xyj2006n/xyj42 血统里的
标准安全陪练机制同款代码）在全树没有任何房间引用它，是死代码，未
处理（不是本次程式 bug 修复范围内的问题——不确定是否曾经被某个已删除
的房间引用过，留作观察）。

**quit/reconnect 测试**：两轮完整 quit → 真实等待间隔（各 65 秒）→
重新连线周期，管理员账号（头衔"方寸山三星洞第三代弟子"、师承、
技能、战斗力）状态完整保留；期间用第二个临时测试角色 `ceshiwyz`
验证跨连线 `tell` 双向送达（连线时），断线后对 `<断线中>` 的角色
`tell` 正确返回"没有这个人"（`cmds/std/tell.lpc` 自带的 `find_player`
只扫描 `users()` 里真正 interactive 的连线，这是这份实现本来的设计，
不是 §7.131/§7.152 的 bug 形状）；房间列表全程只显示一份角色实例，
未见 §7.150 式的残留重复物件。`quit` 前后 `debug.log` 除本次记录并
已修复的 4 个 bug 之外全程零新增记录。

清理：测试用的临时小号 `ceshiwyz` 存档已在提交前删除；只保留种子
管理员账号 `fluffos`（中文名"悟空侠"，已加入灵台方寸山三星洞门下，
测试用的技能/门派状态原样保留，作为本次测试的存证）。已核对
`grep -h '"port"' libs/*/meta.json | grep -oE '[0-9]{5}' | sort -n |
uniq -c | awk '$1>1'` 提交前不产生任何输出。驱动均以精确 PID 关闭。


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

`scripts/lpc_fix_negative_ranges.py`: 6 line(s) in 3 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 1 here-document block(s) repaired (1 with the terminator glued to the last text line, 0 with it indented), so `End of file in text block` no longer hides the room or object behind them: `d/moon/bedroom.lpc`. The terminator must start its line (the lexer's own test, KB 04 §6.10); a glued one lost its newline in the GBK -> UTF-8 conversion together with a half character, which stays out.

## 深度功能测试（§10.7，2026-10-05）— 编译警告与加载失败整理

与 `xiyouji2006` 同日同批修复（本库与它的 `d/`、`adm/`、`std/` 是同一份代码：改动的 1036 个文件中 984 个与 `xiyouji2006` 工作树逐字节相同，其余 52 个含本库自有代码，由同一套工具处理）：`scripts/lpc_warnings.py xyj2006zzzhx --fix` 与 KB 08 §10.13 的结构化工具，855 行增、1967 行删。逐条记录见 `libs/xiyouji2006/NOTES.md` 同日一节（`d/kaifeng/ground.h`、`quest.lpc`、`yaoguai.lpc`、`mojie.lpc` 等手工修复，`for (n == 0; ...)`、邮件守护进程 `tmp[i] == EOT + "."`、`int ref ()`（`ref` 是保留字，改 `do_refresh`，连同 `call_out("ref", 20)`）、`cmds/wiz/tail.lpc` 用的 `tail()` 在 `adm/simul_efun/file.lpc`）。

验证：全部 `.lpc`（9264 个对象，每次 VM 启动 700 个，HEAD 对工作树）9020 PASS -> 9036 PASS，由通变不通 0 个，新增可加载 16 个（8 个来自上述修复，8 个来自房间基类：`std/room.lpc` 的 `make_inventory()` 加了 `catch(ob = new(file)) || !objectp(ob)`，`scripts/lpc_resilient_room.py`，KB 05 §7.25）。`scripts/lpc_audit_removed_locals.py HEAD`：19 条候选全是误报（声明被重建，仍在用的名字仍在；这些文件无诊断）。`scripts/lpc_warnings.py xyj2006zzzhx` 剩 292 条诊断：87 个文件 287 条错误、5 条警告，都在本来就不能编译的文件里（与 `xyj2006n` 相同；本库另有 3 条未用局部变量，`d/dntg/yunlou/npc/lj.lpc` 的 `ghost`、`d/penglai/npc/luxing.lpc` 与 `shouxing.lpc` 的 `obj`，已手工删除，这三个文件现与 `xyj2006n` 的相同）。

**剩余（不虚构内容）**：TMI-2 网络守护进程（`adm/daemons/network`、`daemons/network`：`uid.h`、`config.h`、`mailer.h` 档案里没有）；`d/kaifeng` 的 `old/quest_*` 片段；巫师目录（`u/yesi`、`u/vikee`）；损坏内容：`d/qujing/start/24/12.lpc` 在路径中间截断，`d/xueshan/obj/hufabird.lpc` 的函数写在 `create()` 里，`d/shendian/obj/niepan.lpc`、`d/moon/obj/poem.lpc`、`d/obj/quest/shuijingqiu.lpc` 有乱码字节（`Illegal character`），`d/dntg/sky/npc/yuhuang1.lpc` 丢了引号和分号。警告 5 条：`adm/simul_efun/oo.lpc`（`object.lpc` 里 `destruct()` 的无引用副本，simul_efun 之外被 `valid_override()` 拒绝）、`vikee.canoe.lpc`（`case` 写成 `cast`）、`d/penglai/_._/10.10/score.lpc` 与 `u/vikee/10.10/score.lpc`（缺分号）。

## 深度功能测试（§10.7，2026-10-05）— 任务表里的 `.c` 路径与任务守护进程的防护

`scripts/lpc_dynamic_rows.py`：`d/obj/quest/dynamic_location`、`d/obj/quest/dynamic_quest` 里 263 行写的是原档案的 `.c` 路径。转档时文件已改名 `.lpc`，而显式后缀按原样解析，`load_object("/d/x.c")`、`new("/d/obj/quest/x.c")` 返回 0 且不报错（KB 03 §4.2，KB 06 §7.220），所以 `adm/daemons/questd.lpc`、`daemons/questd.lpc` 读到的每一行都加载不出来：随机任务和任务物品从未生成，在 `create()` 里直接对结果调用 `tar->set()` 的版本还会崩溃，连带加载它的 cron 守护进程和 `give` 的任务钩子。这些行已改为 `.lpc`；另有 4 行指向的文件两种后缀都不存在（档案缺内容），保持原样。
`scripts/lpc_dynamic_quest_guard.py`：2 处 `spread_quest()` 调用（`init_dynamic_quest()` 的循环里）包进 `catch()`，缺失的任务物品或编译不过的房间只跳过那一个任务，守护进程照常加载、其余任务照常生成。
验证：`adm/daemons/questd.lpc`、`daemons/questd.lpc`和 cron 守护进程在新进程里加载（HEAD 一次，工作树三次，选房是随机的）：HEAD 通过 2 个，工作树三次分别通过 4、4、4 个（共 4 个），无回退；`adm/daemons/questd.lpc`、`daemons/cron.lpc` 原先加载失败，现在加载成功。

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `std/room.lpc`：`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 OK，工作树 单件 OK、多件 OK。

- 2026-10-10：`/obj/roommaker.lpc` 生成新文件用的 here-document 模板（`@ROOM_CODE`/`@OBJ_CODE`）里的 `inherit` 行，被 94b87c18461 的重复继承清理当成代码删掉了（`lpc_diamonds.py` 当时不识别 here-document），用它生成的房间/物品会因缺少继承而无法编译。已恢复该行；工具已修正。

## 深度功能测试（§10.7，2026-10-12）：vikee.canoe.lpc

- `d/city/npc/vikee.canoe.lpc`（及 `npc/npc/` 副本）：`cast "mace" :` 是 `case` 的笔误，整份文件从不编译；改正后可载入（这是 `vikee.lpc` 的旧副本，无人引用）。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。3 个文件 3 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。

## `->query_(` 笔误（2026-10-15，KB 06 §7.245）

调用不存在的函数 `query_`，call_other 静默返回 0，相关判断永远按 0 计算。改为 `->query(`：`buhui`。

## 空手使用兵器绝招（2026-10-15，KB 06 §7.246）

`perform` 指令允许直接点名招式（如 `perform stick.ban`），这些绝招读了 `me->query_temp("weapon")` 却从不检查，空手时 `weapon->name()` 报错（有的已先扣了内力）。在赋值后补 `if (!objectp(weapon)) return notify_fail("你必须手持兵器才能使用这一招。\n");`（`scripts/lpc_fix_perform_weapon.py`）：`yueya-chan/feicha`。

## 用兵器的绝招空手施展时报错（内联写法）（2026-10-15，KB 06 §7.246）

绝招不存兵器变量，直接写 `(me->query_temp("weapon"))->query("name")`（或在拒绝判断里写 `(weapon = me->query_temp("weapon"))->query("skill_type")`），之前又没检查兵器：空手 `perform` 时报 `Bad argument 1 to EFUN call_other()`，内力等往往已经扣掉。在第一次用到它的那条语句前补上“你必须手持兵器才能使用这一招”的拒绝（`scripts/lpc_fix_perform_weapon.py`）：`liangyi-sword/yin`。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

19 个文件、22 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`），多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/d/city/npc/npc/obj/choupao`、`/d/city/npc/obj/changqiang`、`/d/obj/cloth/cloth`）。本库 NPC 基类 `std/char/npc.lpc` 的 `carry_object()` 第一句是 `if (file->query_unique())`，对不存在的文件直接 call_other，驱动在这里报 `call_other() couldn't find object`，`new()` 来不及返回 0，所以只要 NPC 带着一件本库没有的物品就载入不了（调用处加判断对它无效）。在它前面补 `if (!objectp(load_object(file))) return 0;`（`--base`），缺的物品就跳过，NPC 照常载入；上面那些调用处同样改成带判断的块（基类以后改回去也不怕）。载入检查：改动的文件改前能载入 1 个，改后 19 个（18 个原来载入不了），没有退步；其余 1 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## 去掉的预定义宏 `SAVE_EXTENSION`（2026-10-18，KB 04 §6.11）

老版 MudOS 给每个 LPC 对象预先定义了 `SAVE_EXTENSION`（`".o"`）；FluffOS 的 ChangeLog（COMPAT_BUSTER 一条）把它删了，改用 `__SAVE_EXTENSION__`。本库没有自己 `#define` 这个宏，用到它的文件一律 `Undefined variable 'SAVE_EXTENSION'`，整个对象载入不了。改成 `__SAVE_EXTENSION__`（`scripts/lpc_fix_predefined_macro.py`）：`adm/daemons/network/netmail.lpc`、`daemons/network/netmail.lpc`。`netmail` 是网络邮件守护进程（本库缺 `mailer.h` 等头文件，改后仍载入不了）。改后用 `lpcc` 逐个载入这些对象：0 个通过，2 个还有别的错误（`adm/daemons/network/netmail`：/adm/daemons/network/netmail.lpc:17: error: Cannot #include mailer.h；`daemons/network/netmail`：/daemons/network/netmail.lpc:17: error: Cannot #include mailer.h）。

## `d/moon/obj/poem` 两句诗丢了收尾的引号（2026-10-18，KB 03 §4.6）

`string *poem` 数组里 `"不放玉花飞堕地，留在广寒宫阙。,` 和 `"把酒送春春不语，黄昏却下潇潇雨。,` 的收尾引号没了（转码时跟半个汉字一起丢了），下一行的开引号把字符串合上，后面的诗句成了代码：`Illegal character 0xe6`，整个物件载入不了。补回 `",`。载入：通过。

## `d/shendian/obj/niepan` 的收尾引号变成了私用字符（2026-10-18，KB 03 §4.6）

`set("long", HIR"……五种符号<U+E4D4>NOR);` 里本该是 `"` 的位置是一个私用区字符（转码时半个汉字加引号被换成了它），`Illegal character 0xee`，整个物件载入不了。换回 `"`。载入：通过。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 3 个对象设了本库没有文件的武功（5 个名字，最多的是 `chanting`、`essencemagic`、`qitian-gun`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：3 个里 3 个通过。（`scripts/lpc_guard_set_skill.py`）

## 补回本库没有的基类文件（2026-10-18，KB 04 §6.15）

下面这些基类本库没有，继承它们的对象（房间、NPC、物品）整批载入不了（`inherit XXX;` 的宏没定义，或者 `inherit "/std/…";` 的文件不在）。同系的库里有同名文件，两库有大量逐字节相同的文件（亲缘关系），所以从那边原样拷来，缺的宏补进全局头文件 `include/globals.h`：`/std/weapon/unarmed`（宏 `UNARMED`）←sjsh，2 个对象继承它，抽样 2/2 载入。每个基类补回后单独载入、再抽样载入使用它的对象，基类载不进来或者一个用户也载不进来的就撤掉（本库撤掉了它们，不再补）。（`scripts/lpc_restore_bases.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 15 处、15 个文件：`dagonforce`→`dragonforce`（4 处）、`hellfire_whip`→`hellfire-whip`（3 处）、`lahua-shou`→`lanhua-shou`（3 处）、`dragon-step`→`dragonstep`（2 处）、`yange_blade`→`yange-blade`（1 处）、`changqaun`→`changquan`（1 处）、`cuixi-zhang`→`cuixin-zhang`（1 处）。（`scripts/lpc_fix_skill_names.py`）

## 调用了父类没有的函数的对象（2026-10-19，KB 06 §7.259）

`::create();`、`::init();`、`return ::buy_object(who, item);` 这类调用写的是父类里有这个函数的版本；本库的父类没有，旧驱动把它当空操作（返回 0），现在的驱动在编译时就报 `Unable to find the inherited function`，整个对象载入不了。单独成句的调用删掉，`return ::f(...)` 改成 `return 0;`（void 函数里是 `return;`），与旧驱动的行为一致。共 2 处、2 个文件：`::buy_object()`（2 处）。只改了出错原因全是这一类的文件；还带着别的错误（多半是父类本身没了）的文件没动，等父类补回后再看。（`scripts/lpc_fix_dangling_super.py`）

## 武功基类缺少 NewRandom()（2026-10-19，KB 06 §7.261）

基本武功（`boxing`、`houquan`、`westsword`、`taiji-quan` 等）用 `action[NewRandom(i, 20, level/5)]` 挑招式；`NewRandom()` 和它调用的 `sum()` 在别的库的武功基类里有，本库的 `/std/skill.lpc` 是更精简的版本，没有，于是这些武功全都报 `Undefined function NewRandom` 编译不过，有这门武功的人物只能空手。把这一对函数（115 个库共用的同一份文字）补进武功基类，受益武功 6 个：`/daemon/skill/boxing.lpc`、`/daemon/skill/houquan.lpc`、`/daemon/skill/taiji-quan.lpc`、`/daemon/skill/westsword.lpc`。（`scripts/lpc_restore_skill_helpers.py`）

## 全局头文件丢了 2 个宏（2026-10-19，KB 04 §6.16）

`/include/globals.h` 里没有定义 `NPC_D`、`LOCATION_D`，用到它们的物件（名单里 2 个）编译时报 `Undefined variable`/`Undefined function`，整个物件载入不了（编译器在第一个未定义的名字上停下，后面的错误和警告都看不到）。同系的库在各自的头文件里都有这几行：照其中和本库共有文件最多的那个库，原样补到 `/include/globals.h` 最后一个 `#define` 之后，宏体里出现的路径在本库里都存在。补完后名单里有 1 个载入，其余还差别的东西。（`scripts/lpc_restore_defines.py`）

## 出口指向不存在的房间（2026-10-19，KB 06 §7.257）

下列房间的出口写的文件不存在，而对面恰好只有一个房间的出口指回本房间，所以按对面的房间改正（笔误、大小写、路径少了一级）：

- `/d/qujing/wuji2/shandao3.lpc` 的 `west` 出口：`guankou` → `goukano`
- `/d/qujing/wuji2/shandao4.lpc` 的 `east` 出口：`guankou` → `goukano`

改后房间照常载入（与 HEAD 逐个对比，没有退步），出口现在指向存在的房间。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 旧驱动的类型宽松：缺省参数、无类型形参、数组初始化、`class` 变量（2026-10-19，KB 04 §6.19、§6.20）

原来的 MudOS 把调用少传的参数补 0、把没写类型的形参当 `mixed`、不检查变量的声明类型与初始值，也允许变量叫 `class`；这个驱动在编译时全部拒绝，整个物件载入失败。修了 1 个文件：`/daemon/class/fuqiperform/perform.lpc`（`scripts/lpc_round_files.py` 的修复轮：调用处补写 `0`、无类型形参补 `mixed`、`string X = ({...})` 补星号、void 函数的返回值，以及 `class` 变量改名 `pick_class`）。逐个文件在 HEAD 和改后载入对比：这些文件里 1 个原来载入失败、现在载入，没有退步。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。改动：`/d/liandan/baihuagu.h`（1 处）。

## `member_array('/', str)` 改为 `strsrch(str, "/")`：字符字面量的 member_array 按字节搜索（2026-10-20，KB 06 §7.283）

`member_array('/', str)` 里的 `'/'` 是整数，驱动按 UTF-8 **字节**搜索，返回字节偏移（带第三个参数时起点也是字节）；最新的 FluffOS（923cdbc0）在字符串里有非 ASCII 文字时，对每个调用点警告一次（`Warning: member_array(int, string) searches BYTES`）。而 `str[0..idx-1]` 按字符切，中文字符串会在错误的位置截断。改为 `strsrch(str, "/")`（找不到同样返回 -1，按字符计数；`scripts/lpc_fix_member_array_char.py`，JSON 编码器等少数几处手改）。改动：`/adm/daemons/vrm_server.lpc`（1 处）。

## `call_out_info()` 的每一项只有 3 个元素（2026-10-20，KB 06 §7.287）

驱动返回的是 `({ 物件, 函数, 延迟 })`，不带 call_out 的参数，旧代码读第 4 项 `info[i][3]`（`callouts` 指令、`calloutd`、`cod` 工具）一读就报 `Array index out of bounds`，指令从第一行起什么也打印不出来。改为 `(sizeof(info[i]) > 3 ? info[i][3] : 0)`（`scripts/lpc_fix_callout_info.py`）。改动：`/cmds/wiz/callouts.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 5 处）。改动：`/cmds/wiz/dns.lpc`（1 处）、`/d/shendian/babu/obj/longzhua.lpc`（4 处）。

## `callouts`：`sizeof(info[i]) == 4` 把每一行都挡掉了（2026-10-20，KB 06 §7.287）

驱动的 `call_out_info()` 每项只有 3 个元素，输出行前的守卫 `if (sizeof(info[i]) == 4)` 永远不成立，指令只打印表头。改为 `>= 3`。改动：`/cmds/wiz/callouts.lpc`（1 处）。

## `socket` / `dumpsocket` 指令：`dump_socket_status()` 驱动里没有（2026-10-20，KB 06 §7.291）

这些巫师指令 `write(dump_socket_status());`，MudOS 的 efun 在 FluffOS 里不存在，指令编译不过。在模拟 efun 文件里补了 `dump_socket_status()`：用 `socket_status()` 排出同样的表（没有 sockets 包的构建，比如 WASM，只有表头；`scripts/lpc_add_sefun.py dump_socket_status`）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/obj/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## sefun `cat()`：缺文件时 `write(0)` 报错（2026-10-20，KB 06 §7.297）

`void cat(string file) { write(read_file(file)); }`：文件不存在（压缩包没带的欢迎/公告文件，或只有运行中的 mud 才会写的日志）时 `read_file()` 回 0，`write(0)` 在本驱动里报 `Bad argument 1 to receive()`，调用者（登录对话、`cat` 指令）被中断；老驱动什么也不打印。改成 `write(read_file(file) || "");`（`scripts/lpc_fix_cat_unchecked.py`）。改动：`/adm/simul_efun/file.lpc`。

## 登录计数文件 `UserNumber` 缺失（2026-10-20，KB 06 §7.298）

`logind.lpc` 的 `do_counter()` 读 `/adm/daemons/UserNumber`（访客计数，运行中的 mud 才会写）；`.gitignore` 把它排除在仓库之外，所以新检出的树里没有，`read_file()` 回 0，`sscanf(0, ...)` 报错。登录时的 `logon()` 调用了它，每个连接都以 `Bad argument 1 to sscanf` 被断开，没有人登录得进来。加了 `if (stringp(file))` 的守卫（与 dtxywzxzb、rzrmud、xiyouji2006、zitengzhan 早先的做法相同）。

## 翻页器 `start_more(read_file(...))`：文件缺失时 `explode(0)`（2026-10-20，KB 06 §7.300）

东方故事系的翻页器 `void start_more(string msg) { ... explode(msg, "\n") ... }` 被这样调用：`start_more(read_file(HELP_DIR + "help/topics"))`、`start_more(read_file(NEWS))`。压缩包没带的文件使 `read_file()` 回 0，`explode(0, ...)` 在本驱动里报 `Bad argument 1 to explode()`（不带参数的 `help` 指令就是这样出错的），老驱动把 0 当空文本。在 `start_more` 开头加了 `if (!stringp(msg)) return;`（`scripts/lpc_fix_start_more.py`）。改动：`/feature/more.lpc`。

## 访客计数 `howmany_visitor()` 读文件不检查（2026-10-20，KB 06 §7.301）

`howmany_visitor()` 读访客计数文件（`VISITORS` / `COUNTER` / `BBSVISITOR`，只有运行中的 mud 才会写；`.gitignore` 把它排除在仓库之外），新检出的树里没有，`read_file()` 回 0，`sscanf(0, ...)` 报错。这份副本登录时不一定走到它，但调用时同样会出错。在读文件之后加了 `if (!stringp(content)) return 0;`（xkx100、xiakexing100、zzfy 早先的写法，`scripts/lpc_fix_visitor_count.py`）。改动：`/www/relative/logind.lpc`。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库现有的 NPC 文件里没有字面写成空 `chat_msg` 的（扫描只认 `set("chat_msg", ({ }))`）；守卫挡的是运行时才为空的列表和以后新增的 NPC。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/std/char/npc.lpc`（共 1 个文件）。

## 巫师命令不带参数时对 0 调用 efun（2026-10-21，KB 06 §7.336）

巫师（管理员）把命令敲成不带参数时，驱动把 0 传给字符串参数；下面的命令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`，这条指令从来没有用过。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py` 在第一处使用参数的语句前加守卫：文件自带 `int help(object me)` 的，守卫是 `if (!arg) return help(me);`（`help()` 定义在 `main()` 之后的 2 个文件补了原型 `int help(object me);`，否则编译报 `Undefined function help`）；没有 `help()` 的是 `return notify_fail("…\n");`。改动（4 个文件，括号里是接住 0 的 efun）：`/cmds/adm/admove.lpc`（`present`）、`/cmds/adm/baiban.lpc`（`sscanf`）、`/cmds/adm/dumpprog.lpc`（`new`）、`/cmds/wiz/call.lpc`（`replace_string`）。加载检查 HEAD 与工作树对照，没有退步。

## 不带参数的指令对 0 调用 efun：不在 wiz / adm 目录里的指令（2026-10-21，KB 06 §7.336）

指令敲成不带参数时，驱动把 0 传给字符串参数；下面的指令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`。它们在 `cmds/std`、`cmds/usr`、`cmds/bos`、`cmds/app` 这类目录里，上一轮的扫描只看巫师目录。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py --all-dirs` 在第一处使用参数的语句前加守卫：没有 `help()` 的是 `return notify_fail("…\n");`。改动（1 个文件，括号里是接住 0 的 efun）：`/cmds/std/actionavailable.lpc`（`sscanf`）。加载检查 HEAD 与工作树对照，没有退步。

## `cron.lpc`：`emery()` 用循环外的下标，第一次越界就让 cron 停摆（2026-10-21，KB 06 §7.345）

怪兽入侵事件 `emery()`（`/daemons/cron.lpc`）末尾 `for (m = 0; m < sizeof(user); m++) user[i]->set("kill_guaishou", 1);`：`i` 是前面随机选的地区下标，循环变量 `m` 没用上，同一个玩家被标记 `sizeof(user)` 次，在线人数不到 `i + 1` 时下标越界（`Array index out of bounds`，yueyingqiyuan 管理员扫描里的控制台行；`call /adm/daemons/cron->emery()` 一个人在线时四次里三次抛错）。`init_cron()` 在 15 分钟的整点调用 `emery()`，之后才 `call_out("init_cron", 60)` 重新排自己：抛错之后重排没有执行，玩家自动存盘（`autosave()`）、动态任务刷新（`TASK_D->init_dynamic_quest()`）和后面所有事件在这次启动里都停了。改成 `user[m]`（yueyingqiyuan 上实测：连续六次 `emery()` 都正常返回）。这个标记档案里没有任何地方读它（`go.lpc` 里的用法是注释掉的）。

## 拼错的 `call_out()` / `input_to()` 目标（KB 06 §7.349，2026-10-21）

计时器或输入提示给驱动的函数名和文件里定义的差一个字母；驱动对不存在的函数静默不理，所以对应的计时从来没有触发过。调用和配套的 `remove_call_out()` 改成已定义的拼法：`find_seal`：`disapprear` → `disappear`（法术产生的封印十分钟后从不消失）。改动：`/d/jjf/obj/find_seal.lpc`。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 19 条注册（12 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/d/changan/pinqiting.lpc`（`do_pass`、`do_resign`）、`/d/city/npc/duguoyin.lpc`（`do_vendor_list`）、`/d/city/npc/npc/duguoyin.lpc`（`do_vendor_list`）、`/d/eastway/npc/petboss.lpc`（`do_cost`、`do_list`、`do_upgrade`）、`/d/pansi/npc/qingxia.lpc`（`do_yes`）、`/d/pansi/pubu.lpc`（`do_fly`）、`/d/qujing/jisaiguo/obj/luche.lpc`（`do_get`、`do_put`）、`/d/qujing/wudidong/cave2.lpc`（`do_push`）、`/d/zhuxian/npc/guard.lpc`（`do_bian`）、`/d/zhuxian/npc/guard1.lpc`（`do_bian`） 等共 12 个文件。最多的函数名：`do_vendor_list` 2 处、`do_cost` 2 处、`do_list` 2 处、`do_upgrade` 2 处、`do_push` 2 处。

## 调用了、但这个库自己的守护进程里没有的函数（2026-10-22，KB 06 §7.354）

`MACRO->函数()` 调用的函数在这个库的守护进程里不存在：`call_other()` 对不存在的函数不报错、只返回 0，所以这些功能（时间显示、昼夜事件、名字检查、价格文字……）一直没起作用。同一血统另一个库的同名守护进程里有这些函数，原文照抄到本库守护进程末尾（`scripts/lpc_port_function.py`；调用处传的参数个数、函数体用到的函数 / 全局变量 / 宏 / 字符串键都在本库里有，已核对；守护进程在 HEAD 和工作区都能加载，每个函数用固定参数各调用一次：HEAD 返回 0，现在返回正常的值）：`/adm/daemons/chinesed.lpc` ← aoxiangtianji：`chinese_month()`（1 处调用）；`/adm/daemons/chinesed.lpc` ← bxsj：`chinese_time()`（5 处调用）。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 还剩 2 个函数没有补（inquiry 1, chat_msg_combat 1）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/d/death/npc/yanluowang.lpc`:`ask_cancel`、`/d/xueshan/obj/hufabird.lpc`:`saysth`。

## 读不到的留言板：`"/clone/board/x"->foo();` 在 `create()` 里报错（2026-10-22，KB 06 §7.357）

xkx 系的房间在 `setup()` 之后写 `"/clone/board/gaibang_r"->foo();` 来加载留言板（`foo()` 本来就没有定义，只为了触发加载）。这个库没有这个文件，`call_other()` 报 `*call_other() couldn't find object '/clone/board/gaibang_r'`，对象留在内存里、`load_object()` 却抛错：玩家第一次走进房间就看到错误，写在 `create()` 中间的还会切掉后半段。`scripts/lpc_fix_missing_foo.py` 把 2 条单独成行的语句（`/obj/board/xy_b`；`/d/g_quest/target/gumu.lpc`、`/d/target/gumu.lpc`）注释掉并写明原因（别的房间里同样的语句本来就是作者自己注释掉的）。证明和 45 个库的整体加载检查见 KB 06 §7.357。

## `log/` 下的日志子目录没有人建：写日志的 `write_file()` / `log_file()` 报错（2026-10-22，KB 06 §7.358）

这个库的代码往 `log/` 的 1 个子目录写日志：`log/dlog`（`daemons/moneyd.lpc`）。压缩包、`git clone` 和站点包里都没有这些目录（本地启动没有写过它们，`gen_keep_dirs.py` 没记），`write_file()` 对不存在的目录抛 `*Wrong permissions for opening file /log/dlog/money for append. "No such file or directory"`，调用它的函数在写日志那一行中断，后面的奖励、标志、步骤都没有执行。本库的 `log_file()` 会自己建目录（实测，或读源码：nitan 系的 `assure_file()`），所以这里只记了直接用 `write_file()` / `save_object()` 写的目录。把 `log/dlog` 记进 `scripts/wasm_keep_dirs.txt`（`scripts/lpc_keep_log_dirs.py`；站点和 pristine 树按它建空目录）。证明（`scripts/lpcc_eval.py`，在 `/adm/daemons` 这类目录下的求值对象里写 `/log/zzdirprobe/...`，新进程）见 KB 06 §7.358 的实测表。

## `(: 函数名 :)` 指针指向本库没有的函数：只含这个指针的行加了注释（2026-10-22，KB 06 §7.355 补充）

`inquiry` / `item_desc` / `chat_msg*` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：用到时（`ask`、`look`、NPC 闲聊）驱动抛 `*Undefined lfun pointer called: 函数名`，这一拍心跳的后半段被跳过。这些函数没有可以补回的来源（别的库同一路径的文件里没有，或者它还要用本库没有的东西），所以 2 个文件里 2 行只含这个指针的行（`"cancel": (: ask_cancel :),` `(: saysth :),`）加了注释，原文保留并写明原因，这一项当作没有这个话题 / 物品 / 闲聊条目（`scripts/lpc_fix_dangling_lfun.py`；`#include` 的文件在库里缺失的对象、指针不在整行上的写法没动）。 前提（`function_exists()`）和加载检查（HEAD 与工作区对比，本库改动的 `.lpc` 文件）的结果见 KB 06 §7.355：没有一个回归。

## 汉字按字节切片的老写法没有换成按字符：改法名 `"澄" + name[2..3]`、辈分判断 `name[0..1] == "澄"` 等 3 处（2026-10-22，KB 06 §7.360）

原档按字节算字符串区间（一个汉字 2 字节）：`name[2..3]` 是名字的第二个字，`name[0..1] == "澄"` 问名字是不是以「澄」开头。转成 UTF-8 之后，这个驱动的区间和 `strlen()` 都按字符算（`strlen("澄观")` 是 2，`"澄观"[0..1]` 是两个字），老算术原样留着、意思全变：拜入少林 / 武当 / 峨嵋等派的玩家被改成错误的法名（二字名 `张三` 变成一个字的 `澄`，更长的名字取到第三个字）。

本库 3 处（2 个文件）：拼名字的赋值 3 处。例：`name[0..1]` → `name[0..0]`（`/d/nanhai/npc/master.lpc:104`）。`scripts/lpc_fix_gbk_slice.py` 把下标按字符重算（社区的 UTF-8 版 `xkx100utf8` 里就是同样的写法，作对照）；没有改的：截断（`name = name[0..7]`，现在最多 8 个字，只是放宽）、ASCII 的区间（`fname[0..3] == "room"`、`ctime(time())[4..19]`）和上下文看不出是汉字的区间。证明（`scripts/lpcc_eval.py`，bixiecanyang；其余各库是同一份文本）：让澄字辈掌门 `attempt_apprentice()` 一个名叫「张三」的访客，HEAD 的法名是 `慧`，改后是 `慧三`；抽样 28 个库的 HEAD / 工作树加载对比 0 退步。工具不幂等（`[0..3]` 折半得 `[0..1]`，又是对齐区间），改过的文件记在 `scripts/gbk_slice_converted.txt`，不要重跑。

## 长度检查按字节写，旁边的提示按汉字写：16 处（2026-10-22，KB 06 §7.362）

老档的 `strlen()` 数字节（一个汉字 2 字节），转成 UTF-8 后它数字符：提示写「必须是 2 到 6 个中文字」的检查还是 `strlen(name) < 4 || strlen(name) > 12`，于是两三个字的房名、帮会名、群名、聊天室名、称号被提示自己说允许的那句话拒绝，上限却是提示的两倍；留言板的标题检查 `i < 4 || i > 24 || i % 2` 还会拒绝所有奇数个字的标题（`post 你好吗`）。本库 16 处（8 个文件）：`if ((strlen(name) < 2) || (strlen(name) > 12)) {`（`/adm/daemons/logind.canoe.lpc:956`）；`if ((strlen(name) < 4) || (strlen(name) > 16)) {`（`/d/city/npc/huangfeihong.lpc:49`）。`scripts/lpc_fix_strlen_gate.py` 以提示为准：条件里每个 `strlen` 门槛都恰是提示所说数字的两倍才折半，存长度的变量（`i = strlen(arg);`）的门槛和 `|| i % 2` 奇偶项、其后循环的 `i % 2 == 0 &&` 一并处理；提示里有英文 / 字母 / 字节的不动。证明（`scripts/lpcc_eval.py`，bxsj 的留言板，求值对象继承 NPC 并重写 `edit()` 记录调用，`command("post 标题")`）：HEAD 拒绝「你好」和「你好吗」、放行 23 个字的标题；改后接受前两个、拒绝第三个；shenmo 的 `named.lpc invalid_new_name("张三")`：HEAD 回 `名字只能是2-4个中文字。`，改后回 0。抽样 24 + 15 个库的 HEAD / 工作树加载对比 0 退步。

## 按字节写的汉字循环、茶馆猜诗和同盟频道标题（2026-10-23，KB 06 §7.363）

老档按字节做「一个汉字」：`while (i--) if (i % 2 == 0 && !is_chinese(name[i..<0]))` 只检查偶数下标，奇数位上的拉丁字母（`张a`）会过；茶馆猜诗 `mixup()` 用 `strlen(str)/2` 再 `j=j+j`、`str[k..k+1]` 交换两字节；泥潭系 `channeld` 的 `switch (strlen(fname)) case 4/6/8/10` 和 `strlen(family)==4/6` 按字节长度给同盟 / 门派名加空格。本驱动的 `strlen()` 和区间都按字符算。`scripts/lpc_fix_byte_char.py`：去掉奇偶项、把区间改成 `name[i..i]`，按字符重写 `mixup()` 并把 `strlen(first)>=14` 折成 7，频道标题的 case / 门派长度改成字符数（对照 aoxiangtianji）。本库 汉字循环 / `is_chinese` 区间 28 个文件；茶馆猜诗 `mixup` 1 个文件。证明（`scripts/lpcc_eval.py`）：sjplii 的 `check_legal_name` 在 HEAD 接受「张a」、改后拒绝，两边都接受「张三」；xkx100 的 `clubpoem->mixup("离离原上草")` 得到「离离原草上」（真交换汉字）；nitan_san 两字同盟名得到 `【 兄  弟 】`。关键对象加载通过。

## 血条 / 表情标题按字节算显示宽度（2026-10-23，KB 06 §7.365）

老档把汉字当两字节：`bar_string[0..(val * N / max) * 2 - 1]` 把「格数」换成字节下标，半格血条在本驱动（按字符算区间）上会整条画满；巫师表情 `edemote` 的 `repeat_string("─", 13 - (strlen(emotion) / 2))` 也会少减汉字宽度。`scripts/lpc_fix_display_pad.py`：去掉 CJK 血条 / 空白条上的 `* 2`（`jings`/`qis` 赋值和 `blank_string3[0..(23-a)]` 的 23→11 一并改），表情标题去掉 `/ 2`；ASCII 空格的 `none_string` / `empty_string` 仍保留 `* 2`（一格两个空格）。本库 2 处（1 个文件）。证明（`lpcc_eval.py` hhsj）：`tribar_graph(6,9,12)` 在 HEAD 画出整条 12 个■，改后为 6 个■+3 个□；麻将 `strlen(tempB)/2` 是两字符牌码，未改。


## 黑风山 pusa1 用未声明的 ob 且函数外残留 call_out（2026-10-27，KB 06 §7.348 Also）

`d/qujing/heifeng/npc/pusa1.lpc` 的 `announce_success(object who)` 写成 `if (!ob->query("obstacle/hf"))`（`Undefined variable 'ob'`），同目录 `pusa.lpc` 是 `who->query("obstacle/hf") == "done"`；`who->save(); }` 之后还残留 `call_out("die"...); return; }`，落在函数外（`unexpected L_STRING`），对象无程序。改成与 `pusa` 相同的门，并删掉残留语句。证明：HEAD 加载失败；改后加载成功。


## 雪山 obj/hufabird set_level 缺 }（2026-10-27，KB 04 §6.28 Also）

`d/xueshan/obj/hufabird.lpc` 的 `set_level` 在 `setup();` 后少了一个 `}`，后面的 `int heal_up()` / `leave` / `invocation` / `die` 都嵌进了 `set_level`（`unexpected '('`），对象无程序；同目录 `npc/hufabird.lpc` 正常关闭。顺带：`messege_vision`→`message_vision`，`return : die()`→`return ::die()`，以及无 `saysth` 的 `(: saysth :)` 按 7.355 注释掉。证明：HEAD 加载失败；改后加载成功。


## 洗衣盆 is_container 映射缺值编不过（2026-10-27，KB 04 §6.28 Also）

`d/gao/obj/pen.lpc`（或 `d/qujing/gao/obj/pen`）的 `is_container()` 写成 `set("objects", ([ "/u/bula/gao/obj/kaoji" ]));`：映射只有键没有值（`unexpected ']'`），对象无程序。同族 hy5 / xyj2000 已把该函数注释掉。改成标准的 `return 1;`。证明：HEAD 加载失败；改后加载成功。
