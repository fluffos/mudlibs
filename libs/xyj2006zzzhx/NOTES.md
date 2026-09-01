
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
