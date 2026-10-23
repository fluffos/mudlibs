# 红尘.rar → `hongchen`

- Archive: `红尘.rar` (from the 2026-07-29 bulk `mudlib.rar` drop). ES-II
  lineage ("change by Fan@wanxia" per `master.c`'s header), standalone
  "红尘录" (Chapters of the Red Dust) wuxia game.
- Mudlib root in archive: `hc/hc/` (two levels down; the outer `hc/`
  also has a `MUDOS.EXE`, a `架站帮助.txt` (setup help) and `小熊泥苑.txt`
  — the "小熊泥苑" hosting-site branding also seen on `bxsj`/`sjtx2`).
- Ships `config.hc` with the usual stale Windows absolute paths.
- Port: **40107**.

## Status: DONE — boots clean, full registration with a real Chinese name verified, playable

## What was fixed

1. Standard encoding + `.c`→`.lpc` rename via `convert_lib.sh`.
2. **New instance of AGENTS.md §4.3's shim-collision class**:
   `adm/obj/master.lpc` (and 4 other files sharing the same header) had
   `#ifndef __SENSIBLE_MODIFIERS__ / #define nosave static / #define
   protected static / #endif`. The blanket `static`→`nosave` sed turned
   this into `#define protected nosave` — silently aliasing `protected`
   to `nosave` even though both are real, distinct keywords on this
   driver. Deleted both now-nonsensical `#define` lines (`nosave nosave`
   / `protected nosave`) from all 5 affected files (`include/globals.h`,
   `adm/obj/master.lpc`, `adm/obj/simul_efun.lpc`, `adm/obj/
   simul_efun.ahxia.lpc`, `adm/obj/simul_efun_bak.lpc`).
3. **§8.1 class**: `adm/simul_efun/chinese.lpc`'s `is_chinese()` (GBK
   byte-range test) and `adm/daemons/logind.lpc`'s `check_legal_name()`
   (byte-oriented 2-10 bound + `i%2==0` window, message said "1 到 5 个
   中文字") — standard fix. Verified: real Chinese name 秦风六 registers
   correctly end-to-end into the game world (武庙/Wu Temple).
4. `adm/daemons/network/dns_master` and `adm/daemons/ftpd` were actively
   preloaded — commented out per the standing no-sockets-package policy.
5. Admin seeding: registered `fluffos` through the normal flow, appended
   `fluffos (admin)` to `adm/etc/wizlist`. Verified: `update /adm/obj/
   master` succeeds as `fluffos` ("重新编译 /adm/obj/master.lpc：成功！").

## Compile sweep

10014 pass / 150 fail out of ~10164 files. All core system files
(master/simul_efun/logind/chinesed/securityd) compile and run correctly;
remaining failures are individual room/NPC/item content files, not
chased further per the standing "content bugs are logged, not
exhaustively fixed" convention. `adm/daemons/restartd.lpc` has a couple
of undefined-variable errors (`CALLOUT_INTERVAL`/`RESTART_INTERVAL`) —
non-fatal at boot (preload catches the failure), not fixed.

## Full registration/gameplay verification

New character with a real Chinese name (秦风六) registers end-to-end:
gender selection, attribute roll+confirm, email, into the game world at
武庙 (Wu Temple, with 诸葛亮/Zhuge Liang and a NPC magician present).
`look` and `score` (full character sheet: attributes, HP/food/water
bars, combat exp) both work correctly. `quit` drops starting items and
prints a clean farewell message with no errors.

## WASM pass (follow-up)

Native boot above was already clean; the WASM sandbox surfaced two gaps
the native driver doesn't hit:

1. `include/restart.h` is genuinely empty (0 bytes) in both the raw
   archive and the converted source -- a pre-existing incomplete-source
   bug in the original codebase, not something the conversion lost.
   `adm/daemons/restartd.lpc`'s `SHUTDOWN`/`REBOOT`/`HALT`/
   `CALLOUT_INTERVAL`/`RESTART_INTERVAL` were all undefined as a result
   (previously masked because `restartd.lpc` fails to compile silently
   at preload and isn't load-bearing for boot). Reconstructed all six
   constants from the daemon's own usage.
2. `adm/daemons/logind.lpc`'s very first per-connection banner line used
   `socket_address(ob)` (sockets package efun, undefined on this driver)
   to extract the connecting port -- broke EVERY connection attempt
   under WASM. Switched to `query_ip_port(ob)`, already used elsewhere
   in this same codebase.

Also upgraded the admin wizlist entry from `fluffos (admin)` (seeded in
the native pass above) to `fluffos (boss)` -- this lineage's
`wiz_levels` ranks `(boss)` above `(admin)` as the actual top tier, and
`securityd.lpc`'s `trusted_read`/`trusted_write["/"]` both include
`(boss)`. Verified: `update /adm/daemons/securityd.lpc` succeeds as
`fluffos` ("重新编译 ... ：成功！").

LPC formatter run across all 10328 `.lpc`/`.h` files (10141 written).
Blind-spot check found 2 files with the classic stray-`\ n`/unquoted-
string corruption (`cmds/adm/hbless.lpc`, `d/city/diaoyuchi1.h`) and,
via a same-text-despaced-matches-old-file scan across all 112
formatter-touched files containing CJK-space-CJK sequences, 1 file with
confirmed genuine re-spacing corruption (`d/player/fyue_room.lpc`); all
3 reverted. The other 109 flagged files were pre-existing author
spacing, unchanged by the diff. Post-formatter: clean boot, zero compile
errors, registration and `(boss)` permission display both re-verified.

## Status: WASM playable

GitHub Pages packaging for this lib specifically is still deferred to a
later batch pass; the WASM boot/gameplay/admin verification above is
now complete.

## WASM 修复摘要（迁移自 meta.json 的 group_note）

ES II 血统，独立分支；来自 2026-07-29 批量 mudlib.rar 投放。原生启动在之前一轮已经验证过（详见 NOTES.md）；这次 WASM 修复解决了两个原生驱动碰不到的 WASM 专属缺口：（1）include/restart.h 在原始压缩包和转档后的源码里都真的是空文件（0 字节）——这是转档之前就存在的原始源码不完整问题，不是转档产生的 artifact——导致 adm/daemons/restartd.lpc 的 SHUTDOWN/REBOOT/HALT/CALLOUT_INTERVAL/RESTART_INTERVAL 全部未定义；已根据这个精灵自己的用法重建了全部六个常量（restartd.lpc 会被预载但不是关键精灵，所以这个问题此前一直被开机流程掩盖）。（2）adm/daemons/logind.lpc 每次连线的第一条消息用 socket_address(ob)（sockets 包 efun，这个驱动上未定义）来取得连线端口——已改用这份代码库里其它地方本来就在用的真实 efun query_ip_port(ob)。另外把管理员 wizlist 条目从之前播种的"fluffos (admin)"升级成了"fluffos (boss)"——这条血统的 wiz_levels 阶梯把 (boss) 排在 (admin) 之上作为真正的顶层，securityd.lpc 的 trusted_read/trusted_write['/'] 表里也确认了 (boss) 的存在。完整注册（id→确认→中文名字→密码→确认→天赋摇点→电子邮件→性别）→进入游戏→look→score→quit 均验证正常，管理员 id "fluffos" 显示 (boss)，格式化前 update 也成功。LPC 格式化工具对全部 10328 个档案运行；还原了 2 个确认有历史损坏的档案（cmds/adm/hbless.lpc、d/city/diaoyuchi1.h——都是经典的 \n/未加引号 CJK 字符串损坏，源自本来就不配对的引号）和 1 个确认有 CJK 重新加空格损坏的档案（d/player/fyue_room.lpc），是通过对格式化工具触碰过的全部 112 个含"CJK-空格-CJK"序列的档案做去空格后比对旧档案的扫描找到的——其余 109 个都是原作者本来就有的间距，未受影响。格式化后重新验证：启动干净，零编译错误，注册流程和 (boss) 权限显示都仍然正确。

## 深度功能测试（第二轮，2026-08-03）

此前的验证只做到浅层冒烟测试（注册→look/score/quit→(boss) 权限确
认）。本轮启动前先主动排查了本次会话已经反复确认过的几类高价值
bug 模式，提前发现并修复了一处；随后完整走通了注册、探索、丢弃道
具、退出的完整流程。

### 主动排查发现并修复：`get_resp()`/`get_name()` 里两处调试用的 `printf("%O", ob)`

`adm/daemons/logind.lpc` 里有**两处**独立的 `printf("%O\n", ob);`
（AGENTS.md §7.34 已经收录的经典模式，`esI`/`xianlvqiyuan`/`cctx`
都出现过同一类问题）——分别出现在两条平行的中文取名路径上：
`get_name()`（玩家自己手打中文名字）和 `get_resp()`（接受系统随机
建议的名字），两处都紧接在名字校验通过、`ob->set("name", ...)` 之
前，也就是每一个新玩家不管走哪条取名路径，都会在"请给自己取一个中
文名字："和"请设定您的密码："两个提示之间看到一行登录物件的内部路
径（如 `/clone/user/xxx#N`）。已把两处都删除。启动前主动 grep 未
发现 `private command_hook`、未加保护的 `MESSAGE_D->` 呼叫、或
`stat/water` 对 `stat/drink` 键名不一致——本轮没有再发现其它此前已
知模式的实例。

### 完整验证：从注册到探索

用全新账号在原生驱动上完整走通：英文 id（3-10 个英文字母）→ y 确
认 → 中文名字（无泄漏问题）→ 密码 + 确认 → 天赋摇点（0-4，0 为随
机，摇完需要 y/n 二次确认）→ 电子邮件 → 性别 → 进入"北疆小镇"——一
座维吾尔族聚居的边塞小镇，NPC"维吾尔族妇女"用带方言腔调的台词打招
呼（"小波郎子呀克西"），是这批档案里比较少见的西域边塞民族风情场
景，和常见的江南水乡/中原武侠背景形成鲜明对比。`个人档案`（score）
面板显示完整六维天赋（膂力/悟性/根骨/身法/福缘/容貌，后两项隐藏显
示为"[???]"）、食物/饮水槽全满，没有类似 `zsdsj` 那种初始化缺失的
问题。`i`（背包）显示随身携带的"布衣"和"魔法传送帖"（magic
teleport talisman，量:1 单:张，暗示一种一次性传送道具机制）。`e`
移动进入"巴依家院"（"巴依"是维吾尔语对富裕地主的称呼），院中"小
孩"和"巴依"两个 NPC 在场。`quit` 干净退出，自动丢弃了不值钱的布衣
和传送帖（"因为这样东西并不值钱，所以人们并不会注意到它的存在"），
和 `hell`/`cctx` 已经见过的同一种"退出自动清理不值钱物品"机制一
致，不是 bug。debug.log 只有驱动启动期的诊断噪音，没有来自本次实
际游玩会话的运行时错误。

### 未覆盖范围（诚实说明）

预算集中在验证调试泄漏修复和基础注册/移动/背包/退出流程，没有走
到：拜师、战斗、经济系统（钱庄存款机制看起来存在但未实测）。这些
留给下一轮，目前的验证边界如上所述。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 98 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（2026-08-13，round two，新驱动重测）

上面"第二轮"（2026-08-03）那次早于今天的驱动重建（全库
`quest_times`/`win_times` `%`-operator 修复 + Warning/warning 驱动
文本回退），不能算作针对当前驱动的覆盖——这是真正针对今天驱动的重
测。管理员账号 `fluffos`/`Mud@2026`（`(boss)` 级）此前已用真实注册
流程创建并提交，本轮复用，只做登录验证。

### 发现并修复的 PROGRAMMING bug

1. **`log_error()`（`adm/obj/master.lpc`）完全没有严重度检查（AGENTS.md
   §7.34-class，与本轮 `wdxtym`/`ffxymud`/`fy2mg`/`fys` 同一原始形
   状）**：`if (this_player(1)) efun::write("编译时段错误：" +
   message + "\n");`——不区分巫师/玩家，也不区分警告/错误。修复：加
   上 `strsrch(message, "arning:") == -1` 判断。
2. **`log_file()`（`adm/simul_efun/file.lpc`）完全没有 `assure_file()`
   保护（AGENTS.md §7.11-class 的又一确认实例）**：`adm/daemons/
   logind.lpc` 的 `get_gender()`（**新角色注册流程的最后一步**）紧
   跟着调用 `log_file("login/newid.log", ...)`——和本轮 `ffxymud`
   最初发现的那个 bug**完全同一形状**：`LOG_DIR` 下的 `login/`
   子目录若不存在，会在每一个全新角色注册完成的那一刻未捕获抛出。
   这台开发机本地 `work/log/login/` 当前确实存在（早年测试留下的
   `newid.log`），但 `work/log/` 整条路径被项目级 `.gitignore`
   排除在外，本地存在不代表新检出安全。修复：补上
   `assure_file(LOG_DIR + file);`（含前向声明）。

### Proactive checks（无需改动）

- `win_times` 修复确认存在且正确：`d/city2/npc/refereew.lpc:146`。
- 未发现 `message()` simul_efun 包装函数——不适用
  message()-missing-varargs 这一类 bug。
- 管理员账号确认真正可用：登录后权限显示 `(boss)`，
  `update /adm/simul_efun/file`（正是本轮改过的文件）确认可正常重
  新编译。

### 实测过程与一次误报排查

第一次登录时，紧接着 `password` 之后立刻发送 `update` 指令，收到了
一句没头没脑的"什麽？"而不是正常的编译结果——起初怀疑是 `log_error`/
`error_handler` 相关的又一个 bug，但检查后发现"什麽？"其实来自
`feature/alias.lpc` 的 `disable_inputs` 临时标志检查，和编译诊断无
关。进一步查 `log/debug.log`（时间戳恰好落在这次测试期间，被误认为
"有新错误"）确认真正原因：这是全新驱动进程下**首次**触发
`make_body()` 整条 `/clone/user/user` 继承链冷编译导致的
`*Too long evaluation. Execution aborted.`（AGENTS.md §7.90/§10.8 已
归档的冷启动惰性编译级联类别，注册流程本身仍然完整走完，只是紧接着
的下一条指令因为 eval cost 预算刚好在那次调用耗尽而被中止，留下
`disable_inputs` 卡在真值状态）。带着几秒钟的额外等待时间重新登录、
重新发送 `update` 指令，第二次完全干净，确认是一次性冷启动状态，非
持久性 bug，不需要修复，也不代表 `log_error()`/`log_file()` 的修复
无效。

### 已清理

- 登录测试产生的存档时间戳类微小 diff（`data/{login,user}/f/
  fluffos.o` 的 `last_on` 字段）已用 `git checkout` 撤销，不提交。
  驱动最终按精确 PID kill，`ps -p` 确认已退出。

## §7.100 修复（`ROOM` 基类的同一"多余 replace_program()"形状，全档案扫描第 6 批）

- 删除 `work/` 下 2,675 处存活的 standalone `replace_program(ROOM);` 行
  （脚本删除），另外手工修复 `clone/misc/roommaker.lpc` 建房工具代码
  生成模板里的同形状变体，共 2,676 处，与普查记录一致。
- 验证：真实 `build-debug` 驱动干净开机、端口正常监听，`debug.log` 中
  零 "cannot replace"/"cannot bind" 行。

## 深度功能测试（第四轮，2026-08-20）——拜师/战斗/经济系统补测

第二轮（2026-08-03）明确留白的三块——拜师、战斗、经济系统（含"钱庄
存款"机制）——本轮全部补测完毕，均为**干净通过**，未发现任何编译错
误或运行时崩溃。管理员账号 `fluffos`/`Mud@2026`（`(boss)` 级）复用，
另注册全新测试账号 `hctestqin`（中文名"秦风试"）做实际游玩验证，用
双 Python socket 连线（管理员 + 玩家）配合 `goto`/`summon` 把玩家搬
运到各测试地点。

### 拜师（结果：正常通过）

目标 NPC：`d/newbie/npc/hssz.lpc`（"华山使者"，`inherit F_MASTER`，
`create_family("华山派", 15, "弟子")`），房间 `/d/newbie/hsroom`。全
新角色 `bai hs`：一次通过——`attempt_apprentice()` 接受，`recruit_
apprentice()` 落实师徒关系，`score` 面板正确显示"华山派第十六代弟
子"、"你的师傅：华山使者"。机制本身工作正常（接受/拒绝两种结果都算
合理通过，本次是接受路径）。

### 战斗（结果：正常通过）

目标：`d/city2/wuchang.lpc`（练武场）里的"木人"（`d/city/npc/mu-
ren.lpc`）——一个专门设计的安全陪练木人：`accept_fight()` 会把它自
己的六维属性/技能/气血/内力全部临时替换成挑战者的镜像数值，`set(
"no_die", 1)` 使其不会真死，只会在多次陪练后进入"damaged"状态。`kill
mu` 后完整走通了多回合攻防判定（拳脚招式描述、命中/闪避/格挡三态、
双方血条状态提示逐步下降），最终测试角色不敌木人（因为是镜像战，几
乎是公平的 50/50 对局）力竭死亡——死亡记录 +1，`combat_exp` 按标准
比例扣减（100000→97500），干净复活回武庙（起始/复活点），全程零
driver 报错。确认多回合攻防结算、伤害、死亡/复活转换均正常工作。

### 经济系统 + 钱庄存款机制（结果：正常通过；确认"两层货币"是既有设
计，非 bug）

- **常规购买**：`d/village/npc/seller.lpc`（草棚里的"小贩"，
  `inherit F_VENDOR`→`/feature/dealer.lpc`）。给测试角色实物黄金/银
  子后 `buy egg` 成功购得"五香茶叶蛋"，找零银票正确发放，`i` 背包/
  身上金钱显示准确。注意：`F_VENDOR` 宏实际指向 `/feature/dealer.
  lpc`，不是同目录下看起来更像"这个"的 `/feature/vendor.lpc`（后者
  没有任何文件 `inherit` 它，是未使用的旧稿/草稿档）——价格公式是
  `value * 100 / skill`（`skill` = 讨价还价技能等级*2，无技能时钳到
  最低值 1），新手因此要付出正常标价的**100 倍**——这就是本轮测试中
  一次"钱不够"背后的真实原因（不是 bug，是刻意的杀熟/砍价玩法机
  制），换算成足够的黄金后购买立即成功。
- **钱庄存款机制**（`feature/banker.lpc`，NPC 见 `d/city/npc/qian.
  lpc`「钱眼开」，房间 `/d/city/qianzhuang`）：`deposit`/`withdraw`/
  `check` 三个指令全部实测且工作正常——`deposit all silver`（连同
  `tensilver` 银票）把玩家身上的实物货币转换成 `this_player()` 上的
  `"money"`/`"more_money"` 两个 dbase 字段（记账式余额），`check`
  正确回报"钱眼开悄悄的告诉你，你在敝庄共存有五十四两白银"；
  `withdraw 20 silver` 正确扣减记账余额（含约 1% 手续费，"三十三两
  白银又八十文钱"）并生成对应面额的实物货币放回背包。
- **关键结论（对应 NOTES 里此前标注"未实测"的那一句）**：钱庄存款
  **不是**一个可以直接用来买东西的余额——`feature/vendor.lpc`/
  `feature/dealer.lpc` 的 `can_afford()`/`pay_money()`（定义在
  `feature/finance.lpc`）只检查玩家身上**实物货币物件**
  （`gold_money`/`silver_money`/`coin_money`/...），完全不读取
  `"money"`/`"more_money"` 这两个记账字段。实测复现：把全部实物货币
  存入钱庄后（背包金钱清零，但 `check` 显示 54 两白银存款），到小贩
  处 `buy` 直接返回"你的钱不够"——即便有存款也不能买东西；必须先
  `withdraw` 把记账余额换回实物货币，才能正常购物。这和本 session 里
  `ylfyxa3`/`xyzx3` 发现的"物理货币 vs 银号记账余额"两层货币模式**完
  全一致**，是这一批 wuxia mudlib 里刻意设计的经济机制，不是 bug，
  已按要求原样记录。

### 顺带修复的一处真实 programming bug：`cmds/adm/eval.lpc` 的
`/tmp` 目录缺失（AGENTS.md §7.11 同形状）

测试经济系统途中尝试用管理员 `eval` 指令直接改玩家背包数值时触发：
`EVAL_FILE = "/tmp/tmp_eval.lpc"`（即 `work/tmp/tmp_eval.lpc`），
`work/tmp/` 目录在这份归档里从未存在过，`write_file()` 未加保护直接
抛出运行时错误（"Wrong permissions for opening file /tmp/tmp_eval.lpc
for append" + "No such file or directory"），`debug.log` 里有完整栈。
`eval` 是巫师专用调试指令，不在普通玩家可达路径上，但这确实是一处会
在 `debug.log` 留痕的真实 crash，且与 AGENTS.md §7.11 记录的"目录缺
失导致未捕获 write_file() 中止"完全同形状，顺手修了：在
`write_file()` 前加 `assure_file(EVAL_FILE);`（`adm/simul_efun/
file.lpc` 里的既有 simul_efun，`feature/save.lpc`/`cmds/adm/xcp.lpc`
等文件已经这样直接调用，不需要额外声明）。**踩坑记录**：第一次尝试
按 §7.11 条目里"含前向声明"的措辞加了一行 `void assure_file(string
file);` 前向声明，结果导致 `Undefined function called: assure_file`
——在这个驱动上，给一个 simul_efun 名字加**没有函数体**的前向声明会
让编译器把它当成"本地声明但未实现"的函数，反而挡住了向 simul_efun
的正常回退解析；去掉声明、直接裸调用 `assure_file(...)`（和
`feature/save.lpc`/`cmds/adm/xcp.lpc` 里的写法一致）后 `update` 重编
译成功，`eval 1+1` 正确返回 `Result = 2`，`debug.log` 无新错误。

### 标准 checklist 抽查结果（均已在此前批次修过，本轮仅复核未发现异
常）

- **§7.90**（eval-cost）：`config.fluffos` 里 `maximum evaluation
  cost : 5000000`，已是修复后的值，正常。
- **§7.100**（`ROOM` 多余 `replace_program()`）：全档案 `grep` 命中
  79 处 `replace_program(ROOM)` 字符串，逐一确认全部是注释掉的死代码
  （`//` 开头），零处存活调用——本轮 §7.100 修复完好无损。
- **§7.111**（`master.lpc` `standard_trace()` 的 `file_name(error
  ["object"])`）：`objectp(error["object"]) ? file_name(...) : "<none>"`
  防护仍在，正常。
- **§7.112**（NPC `init()` 里无重入保护的 `call_out` 链）：全档案命中
  的 3 个 `wgargoyle.lpc`/`bgargoyle.lpc`/`yu-zu2.lpc` 全部已带
  `death_stage_active` 临时标记防护，正常。
- **§7.113**（netdead 重连不恢复 `heart_beat`）：`LOGIN_D` 的
  `reconnect()` 调用 `user->reconnect()`，`clone/user/user.lpc::
  reconnect()` 内确认 `set_heart_beat(1)`，正常。
- **§7.114**（`private` `input_to()` 回调经 mixin 继承失效）：
  `feature/edit.lpc` 里全档案 grep `private.*input_line` 零命中，不
  适用。
- **§7.115**（`QUEST` 宏指向不存在的全局钩子档案）：该 sweep 结论是
  "只影响 `aoxiangtianji`，非系统性"，本库未见异常触发路径，跳过。
- **§7.79**（裸 2 参 `addn`/`addn_temp` 误落到 simul_efun 作用域）：
  该 sweep 明确限定在 `xfbhh`/`hhsj`/`nitan170911`/`nitan6`/`nt6`/
  `nt6nitan6win` 六个共享同一 shim 的血统家族里，本库 grep 裸 2 参
  `addn(...)`/`addn_temp(...)` 调用**零命中**，不适用此 bug 类别。

### 已清理

- 测试账号 `hctestqin`（`data/{login,user}/h/hctestqin.o`）用完即删，
  不作为存档提交。
- 管理员账号 `fluffos` 因本轮测试产生的存档噪音（`last_on`/`cwf`/
  `startroom`/`mud_age` 等字段浮动）已用 `git checkout` 撤销。
- `eval` 修复触发生成的 `work/tmp/` 目录（含 `tmp_eval.lpc`）测试完
  已删除。
- 驱动最终按精确 PID kill，`ps -p` 确认已退出，未使用 `pkill -f`。

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

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 3 here-document block(s) repaired (2 with the terminator glued to the last text line, 1 with it indented), so `End of file in text block` no longer hides the room or object behind them: `d/quanzhen/manglin1.lpc`, `d/quanzhen/manglin2.lpc`, `d/player/wzl/dongywc.lpc`. The terminator must start its line (the lexer's own test, KB 04 §6.10); a glued one lost its newline in the GBK -> UTF-8 conversion together with a half character, which stays out.

## 深度功能测试（§10.7，2026-10-04）— paths named in another case

The archive comes from a case-insensitive host: files are stored as `BAGUA0.lpc`, `longjing.C`, `d/SHAOLIN/`, the code names them in lower
case (`__DIR__ "bagua0"`, `"tea/longjing"`, `"/d/shaolin/..."`), so the rooms, NPCs and items behind them could not be loaded (a `.C` file is
not an `.lpc` file; KB 03 §4.5). `scripts/lpc_case_paths.py --convert --apply hc`: 7 file(s) renamed to lower case (`.C` -> `.lpc`,
`.H` -> `.h`) and 0 path reference(s) in 0 file(s) rewritten to the new spelling; 0 skipped, 0 ambiguous. Load check of the 14 objects that were renamed, edited or name a renamed path (HEAD against the working tree, an object is the same under any spelling of its path): 2 PASS -> 14 PASS, 0 that loaded before fail now, 12 more load.

7 files moved (7 `.lpc`); mostly under `d/player/wzl` (7). A rescan with `scripts/lpc_warnings.py hc` is still due: the renamed files are compiled for the first time.

## 深度功能测试（§10.7，2026-10-05）— room base survives a raising NPC

`scripts/lpc_resilient_room.py --apply`: `make_inventory()` of `inherit/room/room.lpc` loads each inventory object as `if (catch(ob = new(file)) || !objectp(ob)) return 0;`. `new()` of a file that is not there returns 0 (the room just lacks that NPC), but `new()` of a file whose `create()` raises (a skill file for `set_skill()` this archive never had, a `carry_object()` item that is not there, a header that never shipped) raised inside the room and the room did not load at all. The wrong-case renames of this lib (the section above) make the NPCs behind them reachable for the first time, so a room that holds one with such a content gap would have gone from "NPC missing" to "room missing"; now it loads without that NPC, as it did before. The room base compiles and loads with the change (HEAD against the working tree). KB 03 §4.5.

## 深度功能测试（§10.7，2026-10-05）— 任务表里的 `.c` 路径与任务守护进程的防护

`scripts/lpc_dynamic_rows.py`：`d/obj/quest/dynamic_quest` 里 30 行写的是原档案的 `.c` 路径。转档时文件已改名 `.lpc`，而显式后缀按原样解析，`load_object("/d/x.c")`、`new("/d/obj/quest/x.c")` 返回 0 且不报错（KB 03 §4.2，KB 06 §7.220），所以 `adm/daemons/questd.lpc` 读到的每一行都加载不出来：随机任务和任务物品从未生成，在 `create()` 里直接对结果调用 `tar->set()` 的版本还会崩溃，连带加载它的 cron 守护进程和 `give` 的任务钩子。这些行已改为 `.lpc`。
`scripts/lpc_dynamic_quest_guard.py`：2 处 `spread_quest()` 调用（`init_dynamic_quest()` 的循环里）包进 `catch()`，缺失的任务物品或编译不过的房间只跳过那一个任务，守护进程照常加载、其余任务照常生成。
验证：`adm/daemons/questd.lpc`和 cron 守护进程在新进程里加载（HEAD 一次，工作树三次，选房是随机的）：HEAD 通过 1 个，工作树三次分别通过 1、1、1 个（共 2 个），无回退；`adm/daemons/questd.lpc` 在 HEAD 与工作树都加载失败，另有原因，与本次无关。

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `inherit/room/room.lpc`：`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）；`reset()` 的 `default:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]][j])) continue;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-07）— 空的 `if (current_water == 0) {}`

5 个房间的 `valid_leave()` 里有一行什么也不做的 `if (current_water == 0) {}`（编译警告 `Expression has no side effects`），删去，行为不变：`d/gaochang/room11.lpc`、`d/gaochang/room12.lpc`、`d/gaochang/room13.lpc`、`d/gaochang/room14.lpc`、`d/xingxiu/shanjiao.lpc`。

## 深度功能测试（§10.7，2026-10-08）— 编译警告整理

`scripts/lpc_warnings.py hc --fix` 加 `scripts/lpc_fix_no_effect.py --apply`，共改动 494 个 `.lpc` 和 9 个 `.h`（多为删去未用的局部变量）。HEAD 与工作树分别加载（新进程）：465 -> 465 通过，无回退；改过的头文件的 64 个包含者 64 -> 64 通过。启动时警告 7 -> 0；新进程登录（输入名字）正常。

## 深度功能测试（§10.7，2026-10-08）— `.lpc` 后缀的定宽切片

`.c` 改名 `.lpc` 时只改了字符串没改切片宽度：`f[<2..] == ".lpc"` 拿两个字符比四个字符，永远不成立（`!=` 永远成立），按后缀筛文件、去后缀的代码因此从不运行或截成 `x.l`（KB 06 §7.238）。`scripts/lpc_lpc_suffix_slice.py --apply` 改了 1 处比较、0 处去后缀（如 `cmds/app/ls.lpc`）；改动的文件 HEAD 与工作树分别加载（新进程），无回退。

- 2026-10-10：24 个 NPC 同时继承 `NPC` 和 `F_UNIQUE`、自己没有 `init()`，驱动只取其中一份（`init() inherited from both /feature/unique.lpc and /feature/attack.lpc`）：要么 `attack.lpc` 的主动攻击/仇杀检查从不执行，要么 `F_UNIQUE` 的持有者检查从不执行。每个补一个两份都调的 `init()`（`scripts/lpc_fix_unique_init.py`）；HEAD 与工作树载入结果相同，这条警告清零。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查

- `d/liwu/obj/ling3.lpc`：`if ("mark_place", base_name(...) == "llzhuang")` 开头多一个无用的逗号操作数，删掉（行为不变）。载入无回退。

## 编译警告收尾（2026-10-13）

`scripts/toolkit_fix.sh` 一轮去掉 4 处多余继承，其余手工，能编译的文件警告清零；改动的 35 个对象在 HEAD 与工作树各载入一次：HEAD PASS 34，tree PASS 34，regress 0。

- 杀怪任务的怪 `quest/shaguai/guai.ahxia.lpc`、`questguai_n.lpc` 的 `die()`（连同原型）改 `void`，`return 1;` 改 `return;`；`kungfu/new/dizangwang.lpc` 的 `attempt_apprentice()` 改 `void`——基类都是 `void`，调用方不读返回值。
- 故事守护进程 `adm/daemons/storyd.lpc` 与 `d/emei/user-room/host/home.lpc` 自己的 `STORY_DIR` 覆盖 `globals.h` 的同名宏（值不同，本文件里一直用自己的），先 `#undef`。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。2 个文件 5 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。
- 2026-10-14：1 个存档文件（留言板 1 个；`data/board/ahxia_b.o`）还是原档案的 GBK 编码，没有转成 UTF-8，`restore_object()` 报 `Invalid utf8 string` 后对象以空数据启动（表情守护进程没有表情、留言板没有帖子、玩家无法载入）。`scripts/lpc_save_encoding.py` 逐个按 GB18030 解码，结果按存档格式解析通过才写回（KB 03 §4）。
- 2026-10-14（续）：留言板存档里有 BBS 彩色字，彩色控制码夹在一个双字节字的两个字节中间（前字节、`ESC[1m`、后字节），另外有被截断的半个字，所以整份文件按任何编码都解不开，留言板一直是空的。`scripts/lpc_save_encoding.py` 先把控制码挪到字后面、丢掉孤立的前字节，再按本库的编码转成 UTF-8，结果按存档格式解析通过才写回。

- 2026-10-14：1 个文件因 `Type of returned value doesn't match function return type ( int vs void )` 整份不编译：声明为 `void`（或没写类型）的函数却返回值，旧驱动照样把值交给调用者。调用者要用返回值的（add_action 处理函数、命令、辅助函数）改为它实际返回的类型：`accept_fight()`。新进程比对 HEAD 与工作树：1 个对象，新增载入 1，回退 0（`scripts/lpc_fix_void_return.py`，KB 04 §6.3）。

- 2026-10-15：`kungfu/skill/guangming-blade.lpc`（光明刀法）是从五虎断门刀抄来的，`query_action()` 里仍按 `wuhu-duanmendao` 的等级挑招式：没练五虎断门刀的人出招时一招都匹配不上，`a_action` 为 0，接着赋值报错。改为按 `guangming-blade` 自己的等级。（武功运行期探针发现。）

## 内力/精力当作伤害种类（2026-10-15，KB 06 §7.241 第二类）

本库 `feature/damage.lpc` 的 `receive_damage()` 不接受 `jingli`/`neili`/`force` 等种类，`me->receive_damage("jingli", 30)` 之类在练功、绝招、吸取时报 `F_DAMAGE: 伤害种类错误`。21 处改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py` 第二步）。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。3 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。


## 东方故事/西游记体系的技能文件（2026-10-15，KB 06 §7.241 第三类）

这些 `kungfu/skill` 文件来自 gin/kee/sen/force 体系，本库人物只有 jing/qi/neili：`receive_damage("kee", 30)` 报 `伤害种类错误`，`query("force")` 永远为 0，技能学不了也练不了。按 kee→qi、gin/sen→jing、force→neili、max_force→max_neili、force_factor→jiali 改了属性名（`scripts/lpc_port_es_props.py`），共 2 个文件。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

另有 1 个文件（绝招、状态、物品、NPC 等，不限于 kungfu/skill）来自 gin/kee/sen/force 体系，同样按 kee→qi、gin/sen→jing、force→neili 改名（`scripts/lpc_port_es_props.py --any-file`）。

## 治疗/疗伤的属性名（2026-10-15，KB 06 §7.241）

`receive_heal()`/`receive_curing()` 也只接受本库的种类。5 个文件（多为只调用 `receive_heal`/`receive_curing` 的药物、NPC）来自其他体系，按本库的属性名改名（`scripts/lpc_port_es_props.py --any-file`）。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。8 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。


## 技能按另一门武功的等级取招（2026-10-15，KB 06 §7.243）

这些技能文件是从别的武功复制改名来的，`query_action()` 仍用原武功的等级查招式表：只会本技能的人等级为 0，取不到招，每次出招都报错。改为读本技能自己的等级（`scripts/lpc_fix_action_level.py`）：`kunlun-zhang`、`taizuchangquan`、`tiezhang-zhangfa`。


## 招式表最低等级之下没有招（2026-10-15，KB 06 §7.243）

招式表的最低 "lvl" 高于 0（如全部为 100），技能等级未到之前取不到招，每次出招都报错。循环后补 `if (!a_action) a_action = action[0];`（`lpc_fix_action_level.py --fallback`）：`tiesha-shenzhang`、`tiesha-zhangfa`、`tiezhang-zhangfa`、`xiuluo-dao`。

## 空手使用兵器绝招（2026-10-15，KB 06 §7.246）

`perform` 指令允许直接点名招式（如 `perform stick.ban`），这些绝招读了 `me->query_temp("weapon")` 却从不检查，空手时 `weapon->name()` 报错（有的已先扣了内力）。在赋值后补 `if (!objectp(weapon)) return notify_fail("你必须手持兵器才能使用这一招。\n");`（`scripts/lpc_fix_perform_weapon.py`）：`dagou-bang/ban`。

## 碧海生潮曲空手报错（2026-10-15，KB 06 §7.246）

`iceforce/roar`（碧海生潮曲）先 `ob = me->query_temp("weapon")`，再直接拿 `base_name(ob)` 判断是不是玉箫；空手 `exert roar` 时 `base_name(0)` 报错，提示“你必须先找一只玉萧来才可以吹－－曲”根本出不来。条件前补 `!objectp(ob) ||`。

## 五虎断门刀出招时 random() 收到浮点数（2026-10-15）

`wuhu-duanmendao` 的 `query_action()` 写了 `a_action["damage"] = level * 1.5;`，伤害成了浮点数；战斗守护（combatd）随后对它做 `random()`，本驱动的 `random()` 只收整数，于是用这门刀法的每一招都报 `Bad argument 1 to random()`（perform 探针在 `duan` 里发现，平常出招同样如此）。改为整数 `level * 3 / 2`。全库只此一处。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`douzhuan-xignyi`→`douzhuan-xingyi`（`/d/mr/npc/obj/shu1`、`/d/mr/obj/shu1`、`/d/mr/obj/shu2`）；`beimin-shengong`→`beiming-shengong`（`tiangang-zhengqi`、`xiantian-gong`）；`huajia-daofa`→`hujia-daofa`（`hujia-daofa`、`jingzhong-bafa`）；`jinwu-dao`→`jinwu-daofa`（`jinwu-daofa`）；`mizongxinfa`→`mizong-xinfa`（`longxiang/fanchang`）；`yihua-jimu`→`yihua-jiemu`（`yihua-jiemu`）；`zhenfen-xinfa`→`zhenfeng-xinfa`（`zfwy-bu`）。

## 技能名拼错：技能文件里拼错自己的名字（2026-10-15，KB 06 §7.249）

技能自己的文件（或它的绝招目录）里，`query_skill()` 读的是差一个字母的自己的名字，永远得 0：“基本功夫要高过本技能”之类的限制从不生效，按等级取招、计算伤害的那一项一直是 0。改为本技能的名字（`scripts/lpc_fix_skill_typo.py` 的 self 判据）：`hujian-daofa`→`hujia-daofa`（`hujia-daofa`、`jingzhong-bafa`）；`shenhuo-ling`→`shenghuo-ling`（`shenghuo-ling/yan`）；`xuantie-jiafa`→`xuantie-jianfa`（`xuantie-jianfa`）；`xuanxie-jianfa`→`xuantie-jianfa`（`xuantie-jianfa`）。

## 存档读不出来：转码损坏（2026-10-15，KB 03 §4.4）

`/data/board/wudu_b.o` 在转码时坏了：原档里孤立的 GBK 前导字节被 `iconv -c` 连同后面的引号一起丢掉，`restore_object()` 报 `Illegal mapping format`，读档的对象（玩家、留言板、信件、表情）从空白开始。按 raw/ 原档重新解码（孤立字节丢掉、引号保留），驱动核对全部能读回（`scripts/lpc_save_encoding.py --from-raw`、`scripts/lpc_save_restore_check.py`）。

## family 映射内联取下标（2026-10-15，KB 05 §7.30）

`ob->query("family")["master_name"]`、`me->query("family")["family_name"]`（泥潭式为 `query("family", ob)[...]`）直接对门派映射取下标：没有门派的人（新玩家、叛师者、大多数 NPC）在 NPC 的打招呼和问话、绝招的门派判断、房间的 `valid_leave` 里报 `Value being indexed is zero`，而不是得到拒绝。6 处（5 个文件）改为 dbase 路径查询 `query("family/master_name")`：有门派时值相同，没有时得 0；原有的判断照常生效（`scripts/lpc_fix_family_index.py`）。给映射赋值的写法未动。


## 血刀刀法「祭血神刀」正神时报错（2026-10-15，KB 06 §7.241）

`xue-dao/shendao` 的伤害是 `random(shen / -1000) + shen / -3000`，越邪恶伤害越高；正神的人算出负数，`receive_damage()` 报“伤害值为负值”。补 `if (damage < 0) damage = 0;`，设计不变（正派用不出伤害），不再报错。

## 移进不存在的巫师房间（2026-10-15，KB 06 §7.251）

用完的物品、要“离开”的 NPC、掷在空中的兵器被移进巫师的工作室（`/u/llm/`），本库没有这些房间。本库的 `move()` 用 `load_object()` 找目的地，找不到就返回 0，不报错，东西留在原处：婚礼结束（`d/nanyang/npc/meipo`、`d/nanyang/npc/meipo2` 的 `last_marry`）时月老没有离开喜堂，每办一次婚礼喜堂里就多一个月老；喜宴结束后喜来福（`d/nanyang/npc/xi-laifu`）没有退回内堂，每办一次婚礼迎宾楼就多一个喜来福。3 个文件改为移进本库的虚空房间 `VOID_OB`（`/clone/misc/void`），与原作把它们“停放”在巫师房间的用意相同（haiyang2 的维护者把月老送进 `/d/city/empty`，也是同样的做法）。

## 玉女剑法「合壁」用一次就永久改动经验和剑法（2026-10-15，KB 06 §7.253）

收尾的 `hebi()` 声明时没有参数（`void hebi() { object me, target, env; int i, j, o, p, count; ...`），call_out 传进去的人和数值全被同名的局部变量（0）挡住，开头的 `if (!me && !target) return;` 每次都返回：合壁的攻击、闪避加成和 `hebi` 标记要到重新登录才消失。更糟的是夫妻判断写成了 `target->querry("id")`（没有这个函数，得 0），没成亲的人 `marry/id` 也是 0，于是人人都被当成夫妻：自己的玉女剑法和经验乘以玉女素心功的级数/80（至少变成浮点数，160 级以上翻倍），随后给对方 `set_skill("combat_exp", ...)` 时报 `No such skill`，收尾的 call_out 也就没排上，乘过的等级和经验永远不还原。测试里用一次合壁，经验 100000 变成 200000.0、剑法 100 变成 200.0。改正：`hebi()` 按它自己再次 call_out 时传的八个参数声明，`perform` 的 call_out 去掉多余的 `h, k`，`querry` 改为 `query`，给对方的 `set_skill("combat_exp")` 改为与上一行一样的 `set("combat_exp")`。测试里加成照常生效，`hebi()` 结束时还原并清除标记，没成亲的人经验和剑法不变。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

17 个文件、52 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/d/tiankong/npc/obj/cloth`、`/d/tiankong/npc/obj/sword`、`/d/tiankong/npc/obj/tongjia`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 0 个，改后 17 个（17 个原来载入不了），没有退步。

## 物品清单把名字的第一个字吃掉（2026-10-18，KB 07 §8.1）

`inventory`、房间的物品列表（`feature/move`）和部分 `look` 把同名物品合并计数，键是 `query("unit") + short()`，只有一件时按 `key[2..]` 去掉量词。量词是一个汉字，在原来的 GBK 里占 2 字节，`[2..]` 正好去掉量词；转成 UTF-8 以后一个汉字只占一个下标，这一刀把名字的第一个字也切掉了（「把长剑」只显示「剑」，带颜色的名字切掉的是转义序列开头）。改为 `[1..]`（`scripts/lpc_fix_unit_cut.py`）：`cmds/usr/ii.lpc`、`feature/move.lpc`。

## 去掉的预定义宏 `SAVE_EXTENSION`（2026-10-18，KB 04 §6.11）

老版 MudOS 给每个 LPC 对象预先定义了 `SAVE_EXTENSION`（`".o"`）；FluffOS 的 ChangeLog（COMPAT_BUSTER 一条）把它删了，改用 `__SAVE_EXTENSION__`。本库没有自己 `#define` 这个宏，用到它的文件一律 `Undefined variable 'SAVE_EXTENSION'`，整个对象载入不了。改成 `__SAVE_EXTENSION__`（`scripts/lpc_fix_predefined_macro.py`）：`adm/daemons/network/netmail.lpc`、`d/quanzhou/npc/tang3.lpc`、`d/taishan/tang3.lpc`。`tang3`/`tang`/`meng-zhu` 是武林盟主一类的 NPC，原来一个都载入不了；`netmail` 是网络邮件守护进程（本库缺 `mailer.h` 等头文件，改后仍载入不了）。改后用 `lpcc` 逐个载入这些对象：2 个通过，1 个还有别的错误（`adm/daemons/network/netmail`：/adm/daemons/network/netmail.lpc:17: error: Cannot #include mailer.h）。


## 水潭里 `ging_cost` 是 `jing_cost` 的笔误（2026-10-18）

`shuitan` 先算 `jing_cost`，倒水时却扣 `receive_damage("jing", ging_cost)`，`ging_cost` 从没声明过：`Undefined variable 'ging_cost'`，整个物件载入不了。改成 `jing_cost`：`d/shaolin/npc/obj/shuitan.lpc`。改后用 `lpcc` 逐个载入这些对象：1 个通过。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 7 个对象设了本库没有文件的武功（5 个名字，最多的是 `yiyang`、`hunyuan-force`、`ruyi-blade`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：7 个里 6 个通过，其余 1 个停在别的错误上（`jobsys/gfjob/npc/li`：*No program in object '/jobsys/gfjob/npc/li'!）。（`scripts/lpc_guard_set_skill.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 34 处、33 个文件：`shaolin-shnfa`→`shaolin-shenfa`（10 处）、`kunlun-shnfa`→`kunlun-shenfa`（10 处）、`yan-fly`→`yanfly`（3 处）、`xinxiu-duzhang`→`xingxiu-duzhang`（2 处）、`tiaji-jian`→`taiji-jian`（2 处）、`taiji-shenfong`→`taiji-shengong`（2 处）、`lingbo-weibu`→`lingboweibu`（2 处）、`kongmingquan`→`kongming-quan`（1 处）等共 10 个名字。（`scripts/lpc_fix_skill_names.py`）

## set_name 的 id 参数传成字符串（2026-10-19，KB 06 §7.260）

`set_name("海口大碗", "bowl");` 把物品的 id 写成了字符串，本库的 `set_name(string name, string *id)` 要的是数组，驱动在编译时报 `Bad type for argument 2 of set_name ( string * vs string )`，整个物件载入不了；旧驱动不检查参数类型，字符串里照样找得到这个词，物品能用 id 称呼。改成 `({ "bowl" })`，共 2 个文件：`/d/baituo/npc/obj/bowl.lpc`、`/d/baituo/obj/bowl.lpc`。（`scripts/lpc_fix_set_name_id.py`）

## 区域物件的零碎修正（2026-10-19，KB 06 §7.267–§7.271）

- `/d/newbie/npc/emsz.lpc` 的 `#include "/u/swordman/newbie/npc/sujia.h"` 改成 `/d/newbie/npc/sujia.h`（巫师目录 `/u/…` 不在档案里，头文件的唯一副本在区域里）
- `/jobsys/gfjob/npc/ada.lpc` 的 `#include "/u/poi/job/npc/npc.h"` 改成 `/jobsys/gfjob/npc/npc.h`（巫师目录 `/u/…` 不在档案里，头文件的唯一副本在区域里）
- `/jobsys/gfjob/npc/aer.lpc` 的 `#include "/u/poi/job/npc/npc.h"` 改成 `/jobsys/gfjob/npc/npc.h`（巫师目录 `/u/…` 不在档案里，头文件的唯一副本在区域里）
- `/jobsys/gfjob/npc/asan.lpc` 的 `#include "/u/poi/job/npc/npc.h"` 改成 `/jobsys/gfjob/npc/npc.h`（巫师目录 `/u/…` 不在档案里，头文件的唯一副本在区域里）
- `/jobsys/gfjob/npc/cao.lpc` 的 `#include "/u/poi/job/npc/npc.h"` 改成 `/jobsys/gfjob/npc/npc.h`（巫师目录 `/u/…` 不在档案里，头文件的唯一副本在区域里）
- `/jobsys/gfjob/npc/caokou.lpc` 的 `#include "/u/poi/job/npc/npc.h"` 改成 `/jobsys/gfjob/npc/npc.h`（巫师目录 `/u/…` 不在档案里，头文件的唯一副本在区域里）
- `/jobsys/gfjob/npc/chang.lpc` 的 `#include "/u/poi/job/npc/npc.h"` 改成 `/jobsys/gfjob/npc/npc.h`（巫师目录 `/u/…` 不在档案里，头文件的唯一副本在区域里）
- `/jobsys/gfjob/npc/dadao.lpc` 的 `#include "/u/poi/job/npc/npc.h"` 改成 `/jobsys/gfjob/npc/npc.h`（巫师目录 `/u/…` 不在档案里，头文件的唯一副本在区域里）
- `/jobsys/gfjob/npc/eba.lpc` 的 `#include "/u/poi/job/npc/npc.h"` 改成 `/jobsys/gfjob/npc/npc.h`（巫师目录 `/u/…` 不在档案里，头文件的唯一副本在区域里）
- `/jobsys/gfjob/npc/eseng.lpc` 的 `#include "/u/poi/job/npc/npc.h"` 改成 `/jobsys/gfjob/npc/npc.h`（巫师目录 `/u/…` 不在档案里，头文件的唯一副本在区域里）
- `/jobsys/gfjob/npc/gaiyiming.lpc` 的 `#include "/u/poi/job/npc/npc.h"` 改成 `/jobsys/gfjob/npc/npc.h`（巫师目录 `/u/…` 不在档案里，头文件的唯一副本在区域里）
- `/jobsys/gfjob/npc/guo.lpc` 的 `#include "/u/poi/job/npc/npc.h"` 改成 `/jobsys/gfjob/npc/npc.h`（巫师目录 `/u/…` 不在档案里，头文件的唯一副本在区域里）
- `/jobsys/gfjob/npc/hua.lpc` 的 `#include "/u/poi/job/npc/npc.h"` 改成 `/jobsys/gfjob/npc/npc.h`（巫师目录 `/u/…` 不在档案里，头文件的唯一副本在区域里）
- `/jobsys/gfjob/npc/huangxu.lpc` 的 `#include "/u/poi/job/npc/npc.h"` 改成 `/jobsys/gfjob/npc/npc.h`（巫师目录 `/u/…` 不在档案里，头文件的唯一副本在区域里）
- `/jobsys/gfjob/npc/huo.lpc` 的 `#include "/u/poi/job/npc/npc.h"` 改成 `/jobsys/gfjob/npc/npc.h`（巫师目录 `/u/…` 不在档案里，头文件的唯一副本在区域里）
- `/jobsys/gfjob/npc/li.lpc` 的 `#include "/u/poi/job/npc/npc.h"` 改成 `/jobsys/gfjob/npc/npc.h`（巫师目录 `/u/…` 不在档案里，头文件的唯一副本在区域里）
- `/jobsys/gfjob/npc/maijing.lpc` 的 `#include "/u/poi/job/npc/npc.h"` 改成 `/jobsys/gfjob/npc/npc.h`（巫师目录 `/u/…` 不在档案里，头文件的唯一副本在区域里）
- `/jobsys/gfjob/npc/meng.lpc` 的 `#include "/u/poi/job/npc/npc.h"` 改成 `/jobsys/gfjob/npc/npc.h`（巫师目录 `/u/…` 不在档案里，头文件的唯一副本在区域里）
- `/jobsys/gfjob/npc/qian.lpc` 的 `#include "/u/poi/job/npc/npc.h"` 改成 `/jobsys/gfjob/npc/npc.h`（巫师目录 `/u/…` 不在档案里，头文件的唯一副本在区域里）
- `/jobsys/gfjob/npc/quan.lpc` 的 `#include "/u/poi/job/npc/npc.h"` 改成 `/jobsys/gfjob/npc/npc.h`（巫师目录 `/u/…` 不在档案里，头文件的唯一副本在区域里）
- `/jobsys/gfjob/npc/shan.lpc` 的 `#include "/u/poi/job/npc/npc.h"` 改成 `/jobsys/gfjob/npc/npc.h`（巫师目录 `/u/…` 不在档案里，头文件的唯一副本在区域里）
- `/jobsys/gfjob/npc/shanzei.lpc` 的 `#include "/u/poi/job/npc/npc.h"` 改成 `/jobsys/gfjob/npc/npc.h`（巫师目录 `/u/…` 不在档案里，头文件的唯一副本在区域里）
- `/jobsys/gfjob/npc/songyang.lpc` 的 `#include "/u/poi/job/npc/npc.h"` 改成 `/jobsys/gfjob/npc/npc.h`（巫师目录 `/u/…` 不在档案里，头文件的唯一副本在区域里）
- `/jobsys/gfjob/npc/sun.lpc` 的 `#include "/u/poi/job/npc/npc.h"` 改成 `/jobsys/gfjob/npc/npc.h`（巫师目录 `/u/…` 不在档案里，头文件的唯一副本在区域里）
- `/jobsys/gfjob/npc/wu.lpc` 的 `#include "/u/poi/job/npc/npc.h"` 改成 `/jobsys/gfjob/npc/npc.h`（巫师目录 `/u/…` 不在档案里，头文件的唯一副本在区域里）
- `/jobsys/gfjob/npc/xian.lpc` 的 `#include "/u/poi/job/npc/npc.h"` 改成 `/jobsys/gfjob/npc/npc.h`（巫师目录 `/u/…` 不在档案里，头文件的唯一副本在区域里）
- `/jobsys/gfjob/npc/xiaoxiao.lpc` 的 `#include "/u/poi/job/npc/npc.h"` 改成 `/jobsys/gfjob/npc/npc.h`（巫师目录 `/u/…` 不在档案里，头文件的唯一副本在区域里）
- `/jobsys/gfjob/npc/xu.lpc` 的 `#include "/u/poi/job/npc/npc.h"` 改成 `/jobsys/gfjob/npc/npc.h`（巫师目录 `/u/…` 不在档案里，头文件的唯一副本在区域里）
- `/jobsys/gfjob/npc/yu.lpc` 的 `#include "/u/poi/job/npc/npc.h"` 改成 `/jobsys/gfjob/npc/npc.h`（巫师目录 `/u/…` 不在档案里，头文件的唯一副本在区域里）
- `/jobsys/gfjob/npc/yuan.lpc` 的 `#include "/u/poi/job/npc/npc.h"` 改成 `/jobsys/gfjob/npc/npc.h`（巫师目录 `/u/…` 不在档案里，头文件的唯一副本在区域里）
- `/jobsys/gfjob/npc/zhaoyishang.lpc` 的 `#include "/u/poi/job/npc/npc.h"` 改成 `/jobsys/gfjob/npc/npc.h`（巫师目录 `/u/…` 不在档案里，头文件的唯一副本在区域里）
- `/jobsys/gfjob/npc/zheng.lpc` 的 `#include "/u/poi/job/npc/npc.h"` 改成 `/jobsys/gfjob/npc/npc.h`（巫师目录 `/u/…` 不在档案里，头文件的唯一副本在区域里）
- `/jobsys/gfjob/npc/zhou.lpc` 的 `#include "/u/poi/job/npc/npc.h"` 改成 `/jobsys/gfjob/npc/npc.h`（巫师目录 `/u/…` 不在档案里，头文件的唯一副本在区域里）
- `/jobsys/gfjob/npc/zhu.lpc` 的 `#include "/u/poi/job/npc/npc.h"` 改成 `/jobsys/gfjob/npc/npc.h`（巫师目录 `/u/…` 不在档案里，头文件的唯一副本在区域里）
- 1 个 NPC 文件、1 处 `create()` 里的 `this_player()->carry_object(` 改成 `carry_object(`（没人在场时 `this_player()` 是 0，NPC 载入不了；有玩家在场时衣服武器落到玩家手里）

逐个物件与 HEAD 对比载入，没有退步。

## 一行写完的源文件还原（2026-10-19，KB 06 §7.272）

下列 1 个文件的整个源码挤在开头的一行 `//` 注释里（档案的编辑器丢了换行），驱动只编译出一个空程序，物件载入后没有名字、没有 id、拿不到手上：`/kungfu/skill/zhenyuan-force.lpc`。`scripts/lpc_uncollapse.py` 按语句、语句块、`#include` 重新分行，再过一遍格式化。还原后逐个载入没有退步，`new()` 出来的物件有名字和属性。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 玩家打造兵器模板被 NPC 带上（2026-10-19，KB 06 §7.275）

`/d/npc/m_weapon/weapon/m_club.lpc`、`/d/npc/m_weapon/weapon/m_sword.lpc`（共 2 个）的 `create()` 用 `this_player()` 读打造数据（`me->query("weapon/lv")` 等）。NPC 的 `weapon` 属性是兵器文件名（字符串），NPC 在别的 NPC 的命令环境里 `carry_object()` 这个模板时，`set_desc()` 里 `switch (w_lv)` 拿到的是那个字符串，驱动报 `Bad argument 1 to switch`，房间和 NPC 都载入不了（旧驱动里 switch 落到 default）。把 `if (me) {` 改成 `if (me && mapp(me->query("weapon"))) {`，玩家打造的流程不变。

## 玩家打造兵器模板没有打造者时（2026-10-19，KB 06 §7.275）

`/d/npc/m_weapon/weapon/m_staff.lpc`、`/d/npc/m_weapon/weapon/m_whip.lpc`（共 2 个）的 `create()` 开头 `me = this_player();` 之后无条件读 `me->query("weapon/name")` 等打造数据。房间刷新时没有人在场（`me` 为 0），或者 NPC 在别的 NPC 的命令环境里 `carry_object()` 这个模板（NPC 的 `weapon` 属性是文件名字符串），旧驱动里读出来是 0 或字符串，`switch` 照样落到 default；新驱动报 `Bad argument 1 to EFUN call_other()` / `Bad argument 1 to switch`，NPC 和它所在的房间载入不了（`--walk` 普查里一个玩家走进房间就触发）。在 `//读入数据` 之后加 `if (!me || !mapp(me->query("weapon"))) { setup(); return; }`：没有打造者就留一个没有名字的空模板，玩家打造的流程不变。

## 补回丢失的标点（2026-10-19，KB 03 §4.6）

转换时丢掉的分号、逗号、引号或文件末尾的 `}`，共 1 个文件，修前 HEAD 载入失败。别的库里同路径的完好副本只比这里少几个标点，按它补回（括号里是那个库）：`/d/quanzhen/hudi6.lpc`（bixiecanyang）。修后与 HEAD 逐个对比载入：这 1 个物件全部载入，没有退步（`scripts/lpc_restore_from_twin.py`、`lpc_fix_eaten_quote.py --comma`、`lpc_fix_eof_braces.py`）。

## 玩家买店用的 `feature/vendor_sale.lpc` 补回（2026-10-19，KB 03 §4.6 第四轮）

`/feature/vendor_sale.lpc`（`/kungfu/class/npc/xiaoer.lpc` 继承它）从 `pay_back` 起约 160 行的行尾丢了最后一个字符（`;` `)` `{` `}`，`else {` 只剩 `els`，`msg` 只剩 `ms`），另有一行 `if(wizardp(who) || getuid(who)==owner_id)` 被拼进了前面的 `log_file(` 调用里。文件载入失败，继承它的物件也跟着失败。别的库（ldtx、ldtxii、xhcii、syxjl、hy3）里有这个文件的完好副本，但那是另一个版本：没有作者后来加的投标公告（`string mesg;` 和 `message("channel:chat", ...)`）。所以按完好副本补回丢失的字符（`scripts/lpc_restore_from_twin.py --diff --extra`），公告两段原样保留；被拼到别处的 `if(...)` 放回完好副本里它所在的 `write("\n盈利` 之前；`message_vision("channel:chat", ...)` 多出来的第一个参数删掉（`message_vision` 的签名是 `(string, object, object)`，每次 `bid` 在扣完款之后都会报错）。补完后文件和继承它的物件都能载入，没有警告，也没有退步（HEAD 上两个都载入失败）。

## `== !"字符串"` 多出来的 `!`（2026-10-19，KB 06 §7.280）

`!"taoist"` 是整数 0，`x == !"taoist"` 就是“x 等于 0”，作者为其余所有人写的那一支永远走不到。具体是：龙女对古墓弟子的机关暗门提示永远给不出来（5 处）；孙婆婆的“你去吧”只对 class 没设置的人生效；性别检查（“你不是女的，无法领会其中至阴之理”）永远不拦人，男的照样能学玉女心法。全部改成 `!= "字符串"`（`scripts/lpc_fix_not_literal_cmp.py`）：`/kungfu/class/gumu/long.lpc`（5 处）、`/kungfu/class/gumu/sunpopo.lpc`（1 处）、`/kungfu/skill/yunu-xinfa.lpc`（1 处）。同样的行在 xkx 一系的 35 个库里都有。

## `x == "a" || "b"`：后面的字符串常量永远为真（2026-10-19，KB 06 §7.281）

`if (arg == "yuyou" || "yu you")` 里的 `"yu you"` 是非空字符串，永远为真，整个条件对任何 `arg` 都成立；作者要的是每个字符串都和变量比较。在每个字符串前补上变量和运算符（`scripts/lpc_fix_literal_or.py`；`forrest2.lpc` 是 `dir == "north" && "south"`，手工改成 `(dir == "north" || dir == "south") && ...`）：`/d/tiezhang/inn2.lpc`（1 处）。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。具体是：客栈小二从不拦住付了房钱又往南/往北走的客人。改动：`/d/changan/ca2.lpc`（1 处）、`/d/haojie/npc/tianshaxing.lpc`（1 处）、`/d/haojie/tianshaxing.lpc`（1 处）、`/d/player/wzl/houshan.lpc`（1 处）、`/d/player/wzl/wsroad1.lpc`（1 处）。

## `member_array('/', str)` 改为 `strsrch(str, "/")`：字符字面量的 member_array 按字节搜索（2026-10-20，KB 06 §7.283）

`member_array('/', str)` 里的 `'/'` 是整数，驱动按 UTF-8 **字节**搜索，返回字节偏移（带第三个参数时起点也是字节）；最新的 FluffOS（923cdbc0）在字符串里有非 ASCII 文字时，对每个调用点警告一次（`Warning: member_array(int, string) searches BYTES`）。而 `str[0..idx-1]` 按字符切，中文字符串会在错误的位置截断。改为 `strsrch(str, "/")`（找不到同样返回 -1，按字符计数；`scripts/lpc_fix_member_array_char.py`，JSON 编码器等少数几处手改）。改动：`/adm/daemons/vrm_server.lpc`（1 处）。

## 浩劫系统 `verdict_time()`：领头玩家已经离线时 `lead->name()` 报错，戒严不解除（2026-10-20）

三十分钟后收场时 `lead`（接战书的玩家）若已退出游戏就是 0，`lead->name()` 在宣布战果的 `message()` 里报错，后面的 `LOGIN_D->set_madlock(0)` 不再执行，戒严一直保持，`quit` 指令因此对所有人关闭。改为 `(lead ? lead->name() : "各派豪杰")`。改动：`/feature/disaster.lpc`（2 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 7 处）。改动：`/d/hangzhou/npc/meipo.lpc`（1 处）、`/d/xyju/npc/mjboy.lpc`（3 处）、`/d/xyju/npc/mjgirl.lpc`（3 处）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/obj/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## 目录读出后的后缀截取宽度（2026-10-20，KB 06 §7.296）

`.c` 改名成 `.lpc` 之后，`get_dir("*.lpc")` 读出的文件名还按两个字符截取（`$1[0..<3]`）：`baguadao.lpc` 变成 `baguadao.l`，用它拼出的路径加载不到对象（故事、战场、事件、帮助、自造物品数据、召唤列表等）。改成 `[0..<5]`（`scripts/lpc_fix_getdir_strip.py`）。改动：`/adm/daemons/storyd.lpc`（1 处）。

## 翻页器 `start_more(read_file(...))`：文件缺失时 `explode(0)`（2026-10-20，KB 06 §7.300）

东方故事系的翻页器 `void start_more(string msg) { ... explode(msg, "\n") ... }` 被这样调用：`start_more(read_file(HELP_DIR + "help/topics"))`、`start_more(read_file(NEWS))`。压缩包没带的文件使 `read_file()` 回 0，`explode(0, ...)` 在本驱动里报 `Bad argument 1 to explode()`（不带参数的 `help` 指令就是这样出错的），老驱动把 0 当空文本。在 `start_more` 开头加了 `if (!stringp(msg)) return;`（`scripts/lpc_fix_start_more.py`）。改动：`/feature/more.lpc`。

## `bipin` 指令编译不过：文件末尾的注释没有收尾（2026-10-20，KB 04 §6.25）

`cmds/skill/bipin.lpc` 第 268 行的 `/*` 把一个注释掉的旧函数 `start_huoqiang()` 一直注释到文件末尾，没有 `*/`：`End of file in a comment`，整个对象加载失败，`bipin`（比拼内力）指令不能用。在文件末尾补上 `*/`（被注释的是不用的旧代码，行为不变）。加载检查：HEAD FAIL → tree PASS。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库现有的 NPC 文件里没有字面写成空 `chat_msg` 的（扫描只认 `set("chat_msg", ({ }))`）；守卫挡的是运行时才为空的列表和以后新增的 NPC。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/inherit/char/npc.lpc`、`/inherit/char/npcb.lpc`（共 2 个文件）。

## `quit1`：`if (...)` 后面直接是 `else`，放空语句的那一行不见了（2026-10-21，KB 04 §6.27）

`cmds/usr/quit1.lpc` 是 `quit.lpc` 的副本：`if (wizardp(me) && me->query("env/invisibility"))` 和 `else link_ob->save();` 之间原来有单独一行 `;`（`quit.lpc` 里还在），副本里没有：`syntax error, unexpected L_ELSE`，后面接着 `Illegal LHS`，命令不加载。补回那一行（HEAD 0、树 1）。没有改：`cmds/usr/whotest.lpc`（`who` 的实验版：`(ppl_cnt%4==3? "\n": "")` 后面直接粘着另一段 `for`，行被拼在了一起，`who.lpc` 才是正式命令）。

## 巫师命令不带参数时对 0 调用 efun（2026-10-21，KB 06 §7.336）

巫师（管理员）把命令敲成不带参数时，驱动把 0 传给字符串参数；下面的命令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`，这条指令从来没有用过。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py` 在第一处使用参数的语句前加守卫：没有 `help()` 的是 `return notify_fail("…\n");`。改动（1 个文件，括号里是接住 0 的 efun）：`/cmds/imm/pp.lpc`（`sscanf`）。加载检查 HEAD 与工作树对照，没有退步。

## `quest/dynamic_room` 的 `.c` 行：任务守护进程加载不了（2026-10-21，KB 06 §7.341）

任务守护进程（`adm/daemons/questd100.lpc`）的 `create()` 读 `/quest/dynamic_room`（琉璃庄的 19 个房间，`/d/llzhuang/lou0.c` ……），`clear_room()` 对每一行 `load_object()` 再 `room->reset()`：显式的 `.c` 按原样解析（KB 03 §4.2），档案里的房间是 `.lpc`，`load_object()` 答 0，`0->reset()` 让 `create()` 中止，守护进程没有加载。2026-10-05 的 `.c` 行扫描只认 `dynamic_location*` 和 `dynamic_quest*` 两种表，`dynamic_room` 和 `dynamic_npc_quest` 没有扫到；`scripts/lpc_dynamic_rows.py` 现在认四种，这 19 行改成 `.lpc`（本库档案里没有的行照旧不动）；`/adm/daemons/questd100.lpc` 还读 `/quest/dynamic_location`，本库没有这个文件，`explode(0)` 仍然让它加载失败，没有动。

## `socket`：`dump_socket_status()` 在本库没有（2026-10-21，KB 06 §7.291）

管理员扫描里 `socket` 指令（`/cmds/bos/socket.lpc`）编译不了：`write(dump_socket_status());` 用的是 MudOS 有、本驱动没有的 efun。2026-10-20 的补丁只按名字找了巫师目录里的同名指令，这一条在 `cmds/bos`、`cmds/hufa`、`cmds/island`、`cmds/ser` 这类目录里；用 `scripts/lpc_add_sefun.py dump_socket_status` 在 `/adm/obj/simul_efun.lpc` 末尾补了一个由 `socket_status()` 构造表格的 simul_efun（没有 sockets 包的构建，比如 WASM，只打印表头）。指令 HEAD 编译失败，现在通过。

## `cn`：`replace_string(0)` 在 `!arg` 检查之前（2026-10-21，KB 06 §7.336）

`cn`（`cmds/imm/cn.lpc`）不带参数时报 `Bad argument 1 to EFUN replace_string() Got: int(0)`：`arg = replace_string(arg, " ", "")` 在两行之后的 `if (!arg || arg == "")` 检查之前。把用法检查提到 `replace_string` 前面。

## `findob`：不带参数（2026-10-21，KB 06 §7.336）

`ob = find_object(arg);` 在第一句：不带参数时 `Bad argument 1 to find_object() Expected: string Got: 0.`。加了 `if (!arg) return notify_fail("指令格式 : findob <物件路径>\n");`。

## `cof`：`info[count][2]` 越界（2026-10-21，KB 06 §7.347）

`call_out_info()` 之后的循环 `for (i = 0; i < count; i++) if (max_eval < info[count][2])` 下标写成 `count`（比最后一个元素大一）：每次都越界。改成 `info[i][2]`，没有延迟函数时先答一句（`info[0][2]` 也会越界）。

## 任务分配 `quest`：按顺序找目标的备用循环用了 `living[j]`（2026-10-21，KB 06 §7.347）

`/d/xingxiu/obj/quest.h`：先随机挑目标（`j = random(sizeof(living))`），挑不中再“按顺序找”：`for (i = 0; i < sizeof(living); i++) if (check(living[j], ...)) { target = living[j]; break; }`。下标写成了 `j`（上一个循环最后一次的随机下标），备用循环把同一个 NPC 检查 `sizeof(living)` 遍，世界小的时候任务就分不出去。xkx100 的原文就是这样，派生库照抄。改成 `living[i]`。

## 香烟 `smoke.lpc`：`do_smoking()` 读没赋值的 `me`（2026-10-21，KB 06 §7.348）

`smoke` 指令的第一句是 `jing = me->query("jing")`，`me` 声明了没赋值，每次抽烟都抛 `Bad argument 1 to call_other()`。补 `me = this_player();`（后面的 `this_player()` 调用不变）。改动：`/d/emei/user-room/melodies/smoke.lpc`。

## 商人基类 `do_buy()`：替别人买东西时提示读没赋值的 `ob`（2026-10-21，KB 06 §7.348）

买家 `who` 不是 `this_player()` 且身上超过 35 件东西时，提示写的是 `ob->name() + "身上已经太多东西了"`，`ob` 没赋值：改成 `who->name()`。改动：`/feature/dealer.lpc`、`/feature/dealer1.lpc`。

## 拼错的 `call_out()` / `input_to()` 目标（KB 06 §7.349，2026-10-21）

计时器或输入提示给驱动的函数名和文件里定义的差一个字母；驱动对不存在的函数静默不理，所以对应的计时从来没有触发过。调用和配套的 `remove_call_out()` 改成已定义的拼法：`announce_sb` → 文件里定义的 `annouce_sb`。改动：`/clone/misc/superman.lpc`。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 34 条注册（31 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/d/changan/qishi.lpc`（`do_pass`、`do_resign`）、`/d/city/chatroom2.lpc`（`do_jump`）、`/d/city/npc/wei.lpc`（`do_sell`）、`/d/city3/npc/sister.lpc`（`do_vendor_list`）、`/d/gumu/duanchang.lpc`（`do_no`、`do_tiao`、`do_yes`）、`/d/npc/m_weapon/weapon/m_club.lpc`（`do_rename`）、`/d/npc/m_weapon/weapon/m_staff.lpc`（`do_rename`）、`/d/npc/m_weapon/weapon/m_whip.lpc`（`do_rename`）、`/d/quanzhen/npc/haodatong.lpc`（`do_decide`）、`/d/quanzhen/npc/mayu.lpc`（`do_decide`） 等共 31 个文件。最多的函数名：`do_send` 13 处、`do_decide` 7 处、`do_rename` 3 处、`do_vendor_list` 2 处、`do_pass` 1 处。

## 对象路径里的 `..`：`new(__DIR__ "../obj/x")` 报 `Read access denied`（2026-10-22，KB 06 §7.351）

`__DIR__` 是当前文件所在目录（带结尾斜杠），`__DIR__ "../obj/x"` 就是 `/d/zhiye/npc/../obj/x`；驱动的 `legal_path()` 不接受带 `..` 的路径，`new()` / `load_object()` 直接抛 `*Read access denied.`（实测，`find_object()` 对它答 0）。走库自己的 `carry_object()` / 房间 `objects` 表的路径，库的基类会先规范化，能用；直接把路径交给 `new()` / `clone_object()` / `load_object()` / `move()` 的不行，调用到那一步才报错。改成规范化后的绝对路径（`scripts/lpc_fix_dotdot_dir.py --direct`）：`/d/wudang/npc/xiaocui.lpc`（`__DIR__ "../obj/nuerxiang"` → `"/d/wudang/obj/nuerxiang"`）。

## 缺失物品的 `new()` / `carry_object()` 调用链加了保护（2026-10-22，KB 06 §7.73 补充）

`new(路径)->move(...);` / `carry_object(宏("x"))->wear();` 这类语句，路径指向的文件在这个压缩包里没有：`new()` 返回 0，`->move()` 在 0 上报 `Bad argument 1 to EFUN call_other()`。在 `create()` 里这个对象永远加载不了，在 `reset()` 里第一个缺失物品之后的刷新每次 reset 都被跳过。1 个文件里 1 处（`new`）改成 `{ object new_ob = new(路径); if (new_ob) new_ob->move(...); }`（`scripts/lpc_guard_carry_object.py --new`：路径按这个文件自己看到的宏解析，宏名冲突、虚拟对象路径一律跳过）。 对这 1 个改动文件做加载检查（HEAD 与工作区对比）：HEAD 能加载 1 个，现在 1 个（新增可加载 0 个，回归 0 个）。

## 调用了、但这个库自己的守护进程里没有的函数（2026-10-22，KB 06 §7.354）

`MACRO->函数()` 调用的函数在这个库的守护进程里不存在：`call_other()` 对不存在的函数不报错、只返回 0，所以这些功能（时间显示、昼夜事件、名字检查、价格文字……）一直没起作用。同一血统另一个库的同名守护进程里有这些函数，原文照抄到本库守护进程末尾（`scripts/lpc_port_function.py`；调用处传的参数个数、函数体用到的函数 / 全局变量 / 宏 / 字符串键都在本库里有，已核对；守护进程在 HEAD 和工作区都能加载，每个函数用固定参数各调用一次：HEAD 返回 0，现在返回正常的值）：`/adm/daemons/chinesed.lpc` ← aoxiangtianji：`chinese_month()`（2 处调用）；`/adm/daemons/natured.lpc` ← aoxiangtianji：`room_event_fun()`（4 处调用）；`/adm/daemons/chinesed.lpc` ← fengyun434：`check_control()`（1 处调用）、`check_length()`（5 处调用）、`check_return()`（1 处调用）、`check_space()`（1 处调用）、`check_chinese()`（1 处调用）。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 还剩 2 个函数没有补（item_desc 2）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/d/city/ximenroad.lpc`:`look_gaoshi`、`/d/yihua/lianhuachi.lpc`:`look_CAI`。

## 运行期目录 `log/nosave` 不存在，写日志的 `write_file()` 直接报错（2026-10-22，KB 03 §4.3 补充）

这个库的 16 个文件里有 20 处 `write_file("/log/nosave/...")` / `log_file("nosave/...")`（`static` 改 `nosave` 时连字符串里的日志路径一起改了，原来是 `log/static/`）：`/log/nosave/KILL_PLAYER`、`nosave/CRASHES`、`/log/nosave/LASTCRASH` 等。压缩包和站点包里没有这个目录，`write_file()` 在目录不存在时抛 `*Wrong permissions for opening file /log/nosave/... for append. "No such file or directory"`，调用它的函数（杀人记录、重启记录、`call` 日志……）当场中断。把 `log/nosave` 记进 `scripts/wasm_keep_dirs.txt`（站点和 pristine 树都按它建空目录）；没有把字符串改回 `static`。证明（`scripts/lpcc_eval.py`，`catch(write_file("/log/nosave/ZZTEST", ...))`，fqyy2 / hy5 / bmxkx2001 的新进程）：补目录前报上面的错误，补后写成功。

## `log/` 下的日志子目录没有人建：写日志的 `write_file()` / `log_file()` 报错（2026-10-22，KB 06 §7.358）

这个库的代码往 `log/` 的 1 个子目录写日志：`log/doc/register`（`cmds/usr/helpbbs.lpc`）。压缩包、`git clone` 和站点包里都没有这些目录（本地启动没有写过它们，`gen_keep_dirs.py` 没记），`write_file()` 对不存在的目录抛 `*Wrong permissions for opening file /log/dlog/money for append. "No such file or directory"`，调用它的函数在写日志那一行中断，后面的奖励、标志、步骤都没有执行。本库的 `log_file()` 会自己建目录（实测，或读源码：nitan 系的 `assure_file()`），所以这里只记了直接用 `write_file()` / `save_object()` 写的目录。把 `log/doc/register` 记进 `scripts/wasm_keep_dirs.txt`（`scripts/lpc_keep_log_dirs.py`；站点和 pristine 树按它建空目录）。证明（`scripts/lpcc_eval.py`，在 `/adm/daemons` 这类目录下的求值对象里写 `/log/zzdirprobe/...`，新进程）见 KB 06 §7.358 的实测表。

## `(: 函数名 :)` 指针指向本库没有的函数：只含这个指针的行加了注释（2026-10-22，KB 06 §7.355 补充）

`inquiry` / `item_desc` / `chat_msg*` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：用到时（`ask`、`look`、NPC 闲聊）驱动抛 `*Undefined lfun pointer called: 函数名`，这一拍心跳的后半段被跳过。这些函数没有可以补回的来源（别的库同一路径的文件里没有，或者它还要用本库没有的东西），所以 2 个文件里 2 行只含这个指针的行（`"gaoshi": (: look_gaoshi :),` `"CAI": (: look_CAI :),`）加了注释，原文保留并写明原因，这一项当作没有这个话题 / 物品 / 闲聊条目（`scripts/lpc_fix_dangling_lfun.py`；`#include` 的文件在库里缺失的对象、指针不在整行上的写法没动）。 前提（`function_exists()`）和加载检查（HEAD 与工作区对比，本库改动的 `.lpc` 文件）的结果见 KB 06 §7.355：没有一个回归。

## 汉字按字节切片的老写法没有换成按字符：改法名 `"澄" + name[2..3]`、辈分判断 `name[0..1] == "澄"` 等 39 处（2026-10-22，KB 06 §7.360）

原档按字节算字符串区间（一个汉字 2 字节）：`name[2..3]` 是名字的第二个字，`name[0..1] == "澄"` 问名字是不是以「澄」开头。转成 UTF-8 之后，这个驱动的区间和 `strlen()` 都按字符算（`strlen("澄观")` 是 2，`"澄观"[0..1]` 是两个字），老算术原样留着、意思全变：拜入少林 / 武当 / 峨嵋等派的玩家被改成错误的法名（二字名 `张三` 变成一个字的 `澄`，更长的名字取到第三个字）；各派掌门的辈分判断（`name[0..1] == "澄"`）永远不成立。

本库 39 处（29 个文件）：拼名字的赋值 22 处、与汉字常量比较 17 处。例：`name[2..3]` → `name[1..1]`（`/d/shaolin/npc/damo.lpc:171`）；`name[0..1]` → `name[0..0]`（`/kungfu/class/shaolin/qing-fa.lpc:100`）；`msg[0..1] == "第"` → `msg[0..0] == "第"`（`/cmds/std/party.lpc:15`）。`scripts/lpc_fix_gbk_slice.py` 把下标按字符重算（社区的 UTF-8 版 `xkx100utf8` 里就是同样的写法，作对照）；没有改的：截断（`name = name[0..7]`，现在最多 8 个字，只是放宽）、ASCII 的区间（`fname[0..3] == "room"`、`ctime(time())[4..19]`）和上下文看不出是汉字的区间。证明（`scripts/lpcc_eval.py`，bixiecanyang；其余各库是同一份文本）：让澄字辈掌门 `attempt_apprentice()` 一个名叫「张三」的访客，HEAD 的法名是 `慧`，改后是 `慧三`；抽样 28 个库的 HEAD / 工作树加载对比 0 退步。工具不幂等（`[0..3]` 折半得 `[0..1]`，又是对齐区间），改过的文件记在 `scripts/gbk_slice_converted.txt`，不要重跑。

## 长度检查按字节写，旁边的提示按汉字写：12 处（2026-10-22，KB 06 §7.362）

老档的 `strlen()` 数字节（一个汉字 2 字节），转成 UTF-8 后它数字符：提示写「必须是 2 到 6 个中文字」的检查还是 `strlen(name) < 4 || strlen(name) > 12`，于是两三个字的房名、帮会名、群名、聊天室名、称号被提示自己说允许的那句话拒绝，上限却是提示的两倍；留言板的标题检查 `i < 4 || i > 24 || i % 2` 还会拒绝所有奇数个字的标题（`post 你好吗`）。本库 12 处（6 个文件）：`if ((strlen(name) < 2) || (strlen(name) > 10)) {`（`/adm/daemons/logind1.lpc:772`）；`if ((strlen(name) < 2) || (strlen(name) > 12)) {`（`/cmds/bakcmds/csc.lpc:611`）。`scripts/lpc_fix_strlen_gate.py` 以提示为准：条件里每个 `strlen` 门槛都恰是提示所说数字的两倍才折半，存长度的变量（`i = strlen(arg);`）的门槛和 `|| i % 2` 奇偶项、其后循环的 `i % 2 == 0 &&` 一并处理；提示里有英文 / 字母 / 字节的不动。证明（`scripts/lpcc_eval.py`，bxsj 的留言板，求值对象继承 NPC 并重写 `edit()` 记录调用，`command("post 标题")`）：HEAD 拒绝「你好」和「你好吗」、放行 23 个字的标题；改后接受前两个、拒绝第三个；shenmo 的 `named.lpc invalid_new_name("张三")`：HEAD 回 `名字只能是2-4个中文字。`，改后回 0。抽样 24 + 15 个库的 HEAD / 工作树加载对比 0 退步。

## 按字节写的汉字循环、茶馆猜诗和同盟频道标题（2026-10-23，KB 06 §7.363）

老档按字节做「一个汉字」：`while (i--) if (i % 2 == 0 && !is_chinese(name[i..<0]))` 只检查偶数下标，奇数位上的拉丁字母（`张a`）会过；茶馆猜诗 `mixup()` 用 `strlen(str)/2` 再 `j=j+j`、`str[k..k+1]` 交换两字节；泥潭系 `channeld` 的 `switch (strlen(fname)) case 4/6/8/10` 和 `strlen(family)==4/6` 按字节长度给同盟 / 门派名加空格。本驱动的 `strlen()` 和区间都按字符算。`scripts/lpc_fix_byte_char.py`：去掉奇偶项、把区间改成 `name[i..i]`，按字符重写 `mixup()` 并把 `strlen(first)>=14` 折成 7，频道标题的 case / 门派长度改成字符数（对照 aoxiangtianji）。本库 汉字循环 / `is_chinese` 区间 8 个文件；茶馆猜诗 `mixup` 1 个文件。证明（`scripts/lpcc_eval.py`）：sjplii 的 `check_legal_name` 在 HEAD 接受「张a」、改后拒绝，两边都接受「张三」；xkx100 的 `clubpoem->mixup("离离原上草")` 得到「离离原草上」（真交换汉字）；nitan_san 两字同盟名得到 `【 兄  弟 】`。关键对象加载通过。

## 血条 / 表情标题按字节算显示宽度（2026-10-23，KB 06 §7.365）

老档把汉字当两字节：`bar_string[0..(val * N / max) * 2 - 1]` 把「格数」换成字节下标，半格血条在本驱动（按字符算区间）上会整条画满；巫师表情 `edemote` 的 `repeat_string("─", 13 - (strlen(emotion) / 2))` 也会少减汉字宽度。`scripts/lpc_fix_display_pad.py`：去掉 CJK 血条 / 空白条上的 `* 2`（`jings`/`qis` 赋值和 `blank_string3[0..(23-a)]` 的 23→11 一并改），表情标题去掉 `/ 2`；ASCII 空格的 `none_string` / `empty_string` 仍保留 `* 2`（一格两个空格）。本库 2 处（1 个文件）。证明（`lpcc_eval.py` hhsj）：`tribar_graph(6,9,12)` 在 HEAD 画出整条 12 个■，改后为 6 个■+3 个□；麻将 `strlen(tempB)/2` 是两字符牌码，未改。


## Beyond 出口仍指向 /u/beyond（2026-10-23，KB 06 §7.368）

宁波 / 苏州 / 慕容等区域已进 `/d/ningbo`、`/d/suzhou`、`/d/mr`、`/d/hz`，出口与任务物路径仍写 `/u/beyond/…`。`scripts/lpc_fix_beyond_exits.py` 在目标 `.lpc` 存在时改写（`murong`→`mr`）。本库 5 处。证明：sjplii `xikou` HEAD 西向 `/u/beyond/ningbo/aywsi`，改后 `/d/ningbo/aywsi` 可加载；bxsj `hubian1` 三向均可加载。


## 死巫师出口 gold/dock、sunrise、mei（2026-10-23，KB 06 §7.370）

`/d/wanjiegu/road4` 东向 `/u/g/gold/dock`、峨眉寿星居南向 `/u/xinyue/sunrise_room`、玩家卧室通往 `/u/mei/…` 均无对应房间。`scripts/lpc_fix_drop_dead_u_exits.py` 删除这些出口行，并去掉同方向的 `create_door`（否则 `create_door` 无出口会炸）。本库 5 处。证明：zxty08nxgbb 的 road4 HEAD 有东向，改后没有；mei_room1 可加载。


## 中文名 / 验证码仍按 GBK 取「两字节一字」（2026-10-23，KB 06 §7.373）

`pname = pname[(random(sizeof(pname)) & 0xFFFE)..<1]; pname = pname[0..1];` 在按字符计下标时会取出两个汉字。`scripts/lpc_fix_pname_slice.py` 去掉掩码并把收尾改成 `[0..0]`（`pname`/`pname2`/`sec_name`/`str`/`str1`）。本库 4 处。证明：nt1 生成名长度 2–4；HEAD 常见 3–5。

