
## WASM 修复摘要（迁移自 meta.json 的 group_note）

逸俠之世界（Daniel's World），ES II 血统，台湾出品（BBS 140.127.179.161，联系人 leonguo@tpts4.seed.net.tw）。在任何 WASM 专属工作之前，先发现并修复了一个重大编码 bug：这份档案原本是 BIG5 编码，但最初的 convert_lib.sh 转换（硬编码 GB18030 作为源编码）用错误的码页对每一个字符串做了往返转换——结果是一段合法的 UTF-8，能解码成真实存在但毫无意义的中文字符（比如 write("\u7729\u7420\u3085") 而不是 "\u60a8\u7684\u82f1\u6587"），而不是报出 iconv 错误，所以看起来像是转换成功了，但每一条面向玩家的信息其实都是乱码。已通过用两种编码分别解码同一份原始 .c 档案，对比一处 write() 字符串字面量来确认。给 scripts/convert_lib.sh 加了一个可选的第三参数"源编码"（默认 GB18030，其它所有档案不受影响），用 BIG5 重新跑了这份档案的转换——之前所有在（GB18030 乱码版）代码树上做的源码级 WASM 修复都必须在重新用 BIG5 转换出来的代码树上重做一遍，因为 convert_lib.sh 会先删除再从 raw/ 重新生成 work/。WASM 专属修复：（1）经典的 §8.1 GBK 字节区间 is_chinese()/check_legal_name()（奇偶门槛、[i..<0] 后缀切片、字节数翻倍的 2/12 界限）改成了逐码点 0x4e00-0x9fff 检查和 name[i..i]，界限减半为 1/6。（2）§7.12 类的 tell_room() 裸 exclude 导致的 message() 崩溃，用标准的 exclude || ({}) 保护修复。（3）master.lpc 的 valid_write()（valid_read() 本来就无条件回传 1）加上了标准的 'user == this_object()' 短路判断。（4）§7.50 类的 is_killing(object) 对 is_killing(string id) 修复了 9 处呼叫点（kungfu 类的 roar/nuke 档案、几个 u/d/daniel/ 下的 NPC 档案、cmds/std/surrender.lpc）。（5）data/ 下 39 个 CRLF 换行的 .o 存档档案统一转换成 LF（restore_object() 在处理嵌套映射里的 \r 时可能会卡住）。（6）一个真正的 bug，不是 WASM 特有的：adm/daemons/securityd.lpc 的 valid_write() 对 save_object() 快速路径检查的是 'file == user->query_save_file()' 精确字符串相等，但这个驱动的 save_object() efun（vm/internal/base/object.cc）在呼叫 valid_write() 之前会先给文件名加上 __SAVE_EXTENSION__（.o）后缀——精确匹配永远失败，导致每一次玩家存档（注册、进入游戏世界、quit）都被拒绝，每次都抛出'Denied write permission in save_object()'。已改成对照 query_save_file() + __SAVE_EXTENSION__（和本次会话手足档案 yhwhpublicfi/yxjh 里本来就正确的写法一致——yxsj 的 securityd.lpc 只是漏掉了这一处）。adm/daemons/ftpd.lpc 和 adm/daemons/network/dns_master.lpc 都处于休眠状态（在 adm/etc/preload 里被注释掉，只有带保护的巫师指令呼叫者）——保持原样。已知的非阻断性问题，没有进一步深挖：adm/daemons/chinesed.lpc 和 adm/daemons/emoted.lpc 在启动时都会抛出一个被捕获、非致命的'Illegal mapping format while restoring dict/emote'（和另一份档案——yxjh 的 named.lpc——上见过的同一种无法解释的 restore_object() 失败签名一致，只是内容不同，所以很可能是驱动本身的共有怪癖，而不是某份档案特有的损坏；实际游玩中没有观察到任何功能降级）。注册/登录过程中会出现一次针对 obj/user 的 command_hook 的短暂'apply() with insufficient permission... needs: private, has: hidden'，但不会阻挡指令处理、进入游戏世界、或 quit。管理员账号播种：fluffos (admin) 加入 adm/etc/wizlist（(admin) 是这份档案的最高阶层）。注册流程在格式化前后都完整验证过（英文 id→y 确认→中文名字→密码+确认→电子邮件→性别→进入士林高中/校门区域），管理员权限已通过'目前權限﹕(admin)'确认。LPC 格式化工具对全部 949 个档案运行（写入 919 个，21 个转档之前就存在的错误，9 个未改动）。没有 :: 父类呼叫拆分命中，没有 case 标签带尾随注释的候选，没有 CJK 重新加空格/转义损坏命中。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 11 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## §7.100 sweep (2026-08-19)

Fixed the corpus-wide `inherit ROOM; ... replace_program(ROOM);` redundant-replace bug (AGENTS.md §7.100). 185 live occurrences deleted: 184 via scripted sweep (`fix_710_room.py`), plus 1 hand-fixed roommaker-tool template (`obj/roommaker.lpc`, simple string-builder variant, byte-identical sibling of `yxzsj`). 2 already-commented-out instances left untouched. No real `.lpc` source found under `work/data/`. Verified via `build-debug` driver boot: clean compile, zero new "cannot replace"/"cannot bind" debug.log lines; confirmed serving via raw-socket connect on port 40167.

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

## 深度功能测试（2026-08-27，round-two，AGENTS.md §10.7）

单一连续会话，`~/src/fluffos/build-debug/src/driver config.fluffos`
原生驱动，Python 原始 socket 脚本交互。管理员账号 `fluffos` /
`Mud@2026`（此前只在 wizlist 里播种了名字，从未真正注册过存档——本次
补做了真实注册，确认 `目前權限﹕(admin)` 生效）。测试角色：注册英文
id → y 确认 → 中文名 → 密码+确认 → email → 性别 → 进入 `/d/school/gate`
（逸俠中學校門口，`士林高中`场景，非 `help newbie` 文档描述的雪亭鎮/
天邪派等旧版地理——那份 newbie 文档看起来是这套 ES2 引擎的通用模板文字，
和这份档案实际拥有的「学校」主题内容不是同一批地图；本档案真正的门派
体系是把「逸俠中學」本身当作 family/师门，教师 NPC（吴明德、林泽贤、
何景国等）就是可拜师学艺的对象，`apprentice`/`learn` 都走这条路径）。

**发现并修复 4 个真实 programming bug，1 个已确认的 §7.126 类实例记录在案未改（低优先级，见下）：**

1. **`chinesed.lpc` 字典存档格式损坏，`learn`/`skills` 等核心指令必崩
   （新发现的 bug 形状，会话中新增 AGENTS.md 条目）**：`data/chinese.o`
   （`to_chinese()` simul_efun 依赖的技能名中译字典）在原始 1995 年
   BIG5 存档里，凡是遇到第二字节恰好是 `0x5C`（ASCII 反斜线）的中文字
   （如「功」=`0xA5 0x5C`、「许」=`0xB3 0x5C`），当年经典驱动的
   字节级 `save_object()` 会把这个 `0x5C` 当成需要转义的字符，写成
   `0x5C 0x5C`（如 raw 档案里「玄子神功」结尾是 `...功\\"`）——这在
   字节层面能被同样字节级的 `restore_object()` 正确还原。但本项目
   `convert_lib.sh` 的 BIG5→UTF-8 转换是纯字节流转码，不理解这层转义
   语义，把 `0x5C 0x5C` 逐字节转成了两个字面反斜线字符，其中一个紧贴
   着字符串的收尾引号——对最后一个词条「玄子神功」而言，`功\"` 被
   LPC 编译器解析成「转义引号」而不是「收尾引号」，导致整个映射字面量
   永远读不到真正的收尾 `])`，`restore_object()` 抛出
   `*Illegal mapping format while restoring dict.`（此前 NOTES 曾把
   这条启动期警告当成"已知非阻断性问题，实际游玩未观察到功能降级"，
   这个结论是错的——`restore()` 失败时 `dict` 变量被清成裸 `0` 而不是
   `([])`，任何真正调用到 `chinese()`（`str.chinese("...")`索引）的
   地方都会崩溃：实测 `learn <技能> from <人>` 和 `skills` 两个核心
   指令 100% 复现
   `執行時段錯誤﹕*Value being indexed is zero.`（`chinesed.lpc:83`，
   来自 `cmds/std/learn.lpc`/`cmds/usr/skills.lpc` 对 `to_chinese()`
   的调用）。**修复**：写了一次性转换脚本，正确还原原始转义语义——
   按字节扫描找到引号定界的字符串字面量，字节级反转义（`\\`→单字节
   `\`），把还原出的原始字节流按 BIG5 解码，再按 LPC 语法重新转义输出
   为 UTF-8——而不是简单地对整份文件做一次天真的 BIG5→UTF-8 直接转码。
   已验证：修复后 `learn unarmed from teacher` 正确显示"撲擊格鬥之技"
   并成功涨点，`skills` 正确列出已学技能，无崩溃；`chinesed.lpc` 的
   启动期 `Illegal mapping format` 警告也随之消失。**同样的「BIG5
   第二字节=0x5C 导致转换后多出一个反斜线」现象在若干真实 `.lpc`
   源码字符串字面量里也存在**（如 `cmds/usr/quit.lpc`、
   `adm/daemons/combatd.lpc`、`std/char/master.lpc` 等，全档案粗略
   统计约 54 个文件、129+ 处「功\」/「许\」之类的残留），但这些都出现
   在字符串中段而不是收尾引号前，只产生一条无害的
   `warning: Unknown escape sequence` 编译警告，尚未观察到会造成编译
   失败或崩溃的位置——评估为内容质量瑕疵（显示文字里可能多一个游离的
   反斜线字符）而非阻断性 bug，本轮未做全量修复，值得未来专门开一次
   转换补丁扫描（新增 AGENTS.md §4.4 记录这个模式，供其他 BIG5
   血统档案参考）。
2. **`log_error()` 把编译 WARNING 当成 ERROR 广播给玩家（AGENTS.md
   §7.103 已知模式的新确认实例）**：`adm/obj/master.lpc` 的
   `log_error()` 对 `this_player(1)` 无条件 `efun::write()` 每一条编译
   诊断，包括纯警告（`Unused local variable`、`Unknown escape
   sequence` 等）。实测：一次全新注册+登录流程里，仅仅是首次懒编译
   `/std/char.lpc` 及其继承链，就在管理员屏幕上刷出十几条
   `編譯時段錯誤﹕...warning: ...` 噪音。**修复**：按 §7.103 文档化的
   remedy 加上 `strsrch(message, "warning:") == -1` 门槛，真错误仍然
   照常显示，纯警告不再回显给玩家（依然写入 log）。已验证：同样的
   注册流程修复后干净无噪音。
3. **`cmds/wiz/call.lpc`（以及 `master.lpc`/`purge.lpc`/
   `securityd.lpc`）对玩家对象发起 `call` 时崩溃 —— `static`→`nosave`
   转换 sed 误伤了字符串字面量（AGENTS.md §4.3 已知碰撞类型的新确认
   实例）**：管理员对另一在线玩家执行
   `call <玩家>->query(...)` 时 100% 复现
   `執行時段錯誤﹕*Wrong permissions for opening file
   /log/nosave/CALL_PLAYER for append. "No such file or directory"`。
   核对 raw 档案发现：`cmds/wiz/call.lpc`、`adm/obj/master.lpc`（崩溃
   日志 `CRASHES`）、`cmds/arch/purge.lpc`（`PURGE`）、
   `adm/daemons/securityd.lpc`（`promotion`）这 4 个文件的 `log_file`
   调用原本都是 `"static/XXX"`，本项目的全局 `static`→`nosave`
   保留字替换 sed 把这些**字符串字面量**也误改成了 `"nosave/XXX"`——
   而 `work/log/static/` 目录下恰好还留着从 raw 档案转换过来的、
   真实的 2000 年历史数据（`CALL_PLAYER`、`CRASHES`、`promotion` 三个
   文件都有真实的巫师升级记录/崩溃记录/管理员通话记录），`nosave/`
   目录则从未被创建过，导致这四处 `log_file()` 调用全部会在实际触发时
   崩溃，并让这些历史档案在功能上被架空。**修复**：把这 4 个文件的
   5 处 `log_file("nosave/...")` 全部改回 `"static/..."`，恢复到原始
   raw 档案的字面量，重新指向真实存在的历史日志。另外给共享的
   `adm/simul_efun/file.lpc` 的 `log_file()` simul_efun 本体加了
   `assure_file(LOG_DIR + file)`（沿用 `feature/save.lpc` 里
   `save()` 已经用到的同一个 helper）作为额外的防御性修复——以后即使
   再出现引用了从未创建过目录的 `log_file()` 调用，也不会再崩溃，
   而是自动建目录。已验证：管理员对在线测试角色 `call
   ceshier->query("id")` 修复前 100% 崩溃，修复后正常返回结果，且
   写入的正是 `work/log/static/CALL_PLAYER`（历史数据依旧完整，新记
   录追加在后面）。
4. **`obj/board/wizard_j.lpc`：`inherit "/std/jboard"` + 多余
   `replace_program("/std/jboard")`（AGENTS.md §7.86/§7.100 已知模式
   的新确认实例，本次跨库扫描当年用宏名 `BULLETIN_BOARD`/`ROOM`
   匹配，漏掉了这处用字面量路径 `"/std/jboard"` 的写法）**：这是巫师
   专用的「工作进度报告板」（`/d/wiz/jobroom`），`project`/`report`
   两个指令都会对 `this_player()` 发起
   `this_player()->edit((: done_describe_project/done_report, ... :))`
   这种自绑定 lfun 闭包，命中和 §7.86 完全一致的
   `*cannot bind an lfun fp to an object with a pending
   replace_program()` 崩溃。**修复**：删掉多余的
   `replace_program("/std/jboard");`，保留 `inherit`。已验证：修复前
   `project <标题>` 会话中未触发（该指令本身在崩溃修好之前从未真正
   测试过），修复后 `project 测试标题` 正常打开行编辑器、"新工作計畫
   提出"确认成功；顺带在同一个文件里发现并修复了下面第 5 条一个独立
   的逻辑 bug。
5. **`std/jboard.lpc` 的 `do_read()`：`read new`/`read next` 永远失败
   （独立发现的新 bug，随第 4 条一起在同一文件修复）**：`"new"`/`"next"`
   分支算出 `num` 后没有 `return`，也没有用 `else if` 接上后面
   `if (!sscanf(arg, "%d", num)) return notify_fail(...)`
   这一段——于是又用同一个非数字的 `arg`（`"new"`）重新
   `sscanf` 了一次，必然失败，把已经算好的 `num` 覆盖掉，永远落到
   "你要讀第幾個計畫的簡報﹖" 这条错误提示，从未真正显示新报告。
   对照同一血统的 `std/bboard.lpc`（普通留言板）的等价逻辑，确认那边
   是正确的 `if / else if / else if` 三段链——`jboard.lpc` 是从
   `bboard.lpc` 改造时漏掉了这个 `else`。**修复**：把
   `}\n  if (!sscanf(...))` 改成 `} else if (!sscanf(...))`。已验证：
   修复前 `read new` 返回错误提示；修复后正确显示新发的工作计划内容。

**已确认但未修复的低优先级实例（§7.126 类，存档数据里的陈旧 `.c`
扩展名）**：9 个巫师账号（`test`/`pill`/`chara`/`daniel`/`testa`/
`mous`/`testb`/`fva`/`eeman`，均为原始档案自带的历史巫师，非本次
播种账号）的存档里都有一个 `cwf`（"current working file"，供
`clone`/`update` 免参数时使用的"上次编辑文件"书签）字段，值仍然是
`convert_lib.sh` 转换前的 `xxx.c` 路径，`.c`→`.lpc` 改名后这个书签
指向的文件已不存在，`clone`/`update` 空参数调用会静默失败（不是
崩溃，只是"找不到档案"）。范围窄（只影响这几个多年不上线的历史
巫师本人的编辑便利，不影响任何玩家可见内容），且部分书签还同时带着
独立的大小写路径问题（如 `/d/pili/glass/...` vs 实际的
`/d/Pili/glass/...`），修起来需要额外核对每条路径，本轮未处理，
留档记录。

**回归测试覆盖**：注册全流程（英文 id→确认→中文名→密码×2→email→
性别→进世界，管理员与普通角色各测一遍）；师门加入
`apprentice`/`learn`/`skills`/`score` 全链路（此前因 bug 1 完全无法
测试，修复后确认可用）；`fight`（安全切磋机制，不会真的杀死，确认
`unconscious()`→`disable_player()`→`call_out("revive",...)` 30~129
秒后自动恢复的机制存在且被正确触发）；`list`/`buy`（福利社商店，
余额不足的拒绝路径正常，无崩溃；未实际获得充足游戏币走通"购买成功"
分支，因为这是纯粹的经济数值问题不在本轮抓 bug 范围内）；两轮
"网络异常断线（不发 quit，直接断 socket）→ 重新连线" 循环——两次都
正确显示"重新連線完畢"，`ulist` 确认全程只有一个 `ceshier` 对象
（`/obj/user#202`），断线重连后管理员 `tell ceshier ...`
依然能找到人（`find_living`/`set_living_name` 注册在 `obj/user.lpc`
的 `reconnect()` 里没有被清除，不是 AGENTS.md §7.152 那种"重连后
再也找不到人"的形状，此档案在这点上是干净的）；`quit`
后核对 `log/debug.log` 干净无异常；管理员账号自举机制核对（此档案
没有"自动提升第一个注册者为管理员"的机制——`fluffos` 完全靠预先写入
`adm/etc/wizlist` 生效，属于 AGENTS.md §7.149 场景之外的干净设计）。
所有测试用临时角色（`ceshiyixia`/`ceshier`/`ceshisan`）已在提交前
删除存档，只保留播种的 `fluffos` 管理员账号（干净状态，无战斗损伤、
无测试道具）。
