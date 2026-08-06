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
