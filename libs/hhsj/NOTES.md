# 洪荒世界.rar → `honghuangshijie`

- Archive: `洪荒世界(自连数据库)/nt/` (from the 2026-07-29 bulk `mudlib.rar`
  drop). **Same NT/nitan/Lonely engine lineage as `nitan170911`/`nitan6`**
  — confirmed via byte-identical `adm/kernel/master.c` and
  `feature/dbase.c` against `nitan170911`'s raw archive. A "创世/盘古"
  (Genesis/Pangu) themed reskin, ~23,700 `.c` files (smaller snapshot
  than `nitan170911`'s ~54,600).
- Ships a real `config.cfg` (unlike the other two new libs processed this
  session), but with the usual stale/wrong paths (§5.1) — rebuilt
  `config.fluffos` using `nitan170911`'s as a template (same
  `/adm/kernel/master`+`/adm/kernel/simul_efun` paths).
- Port: **40106**.

## Status: WASM playable (native boot + registration + admin all verified)

## Lineage-recognition payoff (AGENTS.md §2.1 applied literally)

Rather than rediscovering `nitan170911`'s §15/§15b/§15c/§15e fix series
from scratch, ported it wholesale:
- **Direct file copy** (raw source confirmed byte-identical to
  `nitan170911`'s pre-fix raw source, so `nitan170911`'s already-fixed
  `work/` version is correct here unmodified): `adm/kernel/
  check_config.lpc`, `adm/kernel/simul_efun.lpc` (+ its two new fragment
  files `ansi_util.lpc`/`db_compat.lpc`, easy to miss since they're
  `#include`d rather than being the file that changed hash — first boot
  attempt failed on exactly this until copied over too),
  `adm/kernel/simul_efun/{chinese,wizard}.lpc`, `feature/dbase.lpc`,
  `clone/user/baby.lpc`, `adm/daemons/examined.lpc`, `feature/alias.lpc`,
  `u/redl/cangku.lpc`.
- **Same fix pattern, different content** (raw source differs from
  `nitan170911` — real gameplay content differences, not just the bug —
  so applied the identical transformation by hand instead of copying):
  `inherit/room/room.lpc`, `clone/user/user.lpc`, `adm/daemons/
  giftd.lpc` — every `efun::set/query/delete/addn(..., ob)` call
  rewritten to `::set/query/delete/add(...)` for the self case (`ob ==
  this_object()`) or `ob->set/query/delete/addn(...)` for the
  other-object case, per the exact §15 recursion-trap writeup.
  `adm/daemons/equipmentd.lpc` got the narrower §15e guard (`if
  (objectp(ob))` around an unguarded `ob->set_color()` chain after
  `TEMPLATE_D->create_object()`, which can legitimately return 0).
- `adm/etc/preload`: same `.c`-extension leftover bug (§15c) — stripped
  with `sed -i 's/\.c$//'`. `dns_master` was already commented out.
- **New instance of the §8.1 GBK byte-range bug**, not present in
  `nitan170911`'s own fix list because it lives in a file unique to this
  snapshot: `adm/daemons/logind.lpc`'s `check_legal_name()` had
  `i<4 || i>8 || i%2` (byte-oriented, message says "2 到 4 个中文字") and
  an `i%2==0` sliding window — fixed to `i<2 || i>4` and a per-codepoint
  `is_chinese(name[i..i])` check, same as every other lib.

## Interactive verification

Boots clean (`Initializations complete.`). This lib does NOT use a
normal human-typed telnet registration flow — the archive's own name
("自连数据库" = "self-connecting database") and the client handshake
(`ver1.0,<key>` / "版本验证成功" written unconditionally on connect)
confirm it's built for a custom mobile-app client, not raw telnet. The
actual protocol (reverse-engineered by reading `logind.lpc`): send ONE
line `id,password,ciphertext,email` (comma-separated; the mudlib itself
replaces `,` with `║` internally, so plain commas from a real telnet
client work fine), then a second line `gender║img_id║中文名字`
(`║`-separated, U+2551, sent literally) for character creation.

Verified end-to-end with a real Chinese name (秦风三/秦风四): new-account
creation succeeds, `SYSY"0008"`→ character-creation prompt → the new
character is dropped into 洪荒世界's starting room ("泥潭注册室"),
welcome/newbie-tip messages print correctly, `look` correctly re-displays
the room, and `quit` produces a proper ANSI-art farewell screen with no
errors. This satisfies the project's standing "real Chinese name must
reach the next stage" bar (§8.1's verification rule).

**`score` reports "还没有出生呐，察看什么？" (not yet born)** — this is
NOT a bug: `score` gates on a `"born"` dbase property that this lineage's
own bespoke genesis questline sets, not basic registration. A brand-new
character is dropped in front of an NPC "盘古" (Pangu) who requires
choosing a personality/race via `choose`/`ask` interactions and then
"投胎" (reincarnating) through further NPCs (`d/register/npc/pangu.lpc`,
`d/register/yanluodian.lpc` — Yanluodian, the Hall of the Underworld
King) before `"born"` gets set. Confirmed this is deliberate game design,
not an error path, by reading the gate condition and its setters — did
not walk the full multi-NPC ritual to completion in this pass (out of
proportion for a first bring-up; the core registration/world-entry bar
above is what this project's convention treats as sufficient, same as
`nitan170911`'s own MySQL-gated precedent).

## Resolved (WASM pass): the "什么？" on EVERY command was a real bug, not a command-search-path gap

The open item above under-diagnosed the symptom -- the "什么？" wasn't
specific to `update`/wizard commands, it happened for `look`/`score`/
literally everything, for every freshly-registered character (not just
`fluffos`). Root cause (found via `write()`-based bisection through
`get_char()` since `log_file()` output doesn't persist across separate
WASM invocations): `adm/daemons/named.lpc`'s `create()` calls a bare
`restore()` on its own ~168KB save file, which throws
`*restore_object(): Illegal mapping format while restoring dbase.`
uncaught. On THIS driver build, an uncaught error during `create()`
leaves the object permanently non-resident (`find_object()` returns 0)
rather than crashing loudly or completing with partial state -- and
critically, a later implicit `NAME_D->invalid_new_name(...)` call-string
invocation on the still-not-resident object silently does nothing at
all (no error, no output, the call just never completes) instead of
auto-compiling it the way an explicit `load_object(NAME_D)` would. Since
`get_char()` (character creation) calls `NAME_D->invalid_new_name()`
before ever calling `make_body()`, EVERY new character creation attempt
silently died at that exact point -- no crash, no error, just an
`input_to` chain that never reaches `call_out("enter_world", ...)`,
leaving the connection wedged in the driver's default command loop with
no `path` ever set, hence every subsequent command hitting the generic
`什么？` fail message forever. Fixed with the standard corrupted-shipped-
save-data guard: `catch(restore())` in `named.lpc`'s `create()` (AGENTS.md
§7.41 class). This is a genuine mudlib bug independent of WASM -- the
native pass above hit the exact same wall and, not being able to `write()`
-debug an apparently call-that-does-nothing, incorrectly attributed it to
a command-dispatch/path question instead. Verified post-fix: full
registration → `look`/`score` → `fluffos` routed to 巫师休息室 (wizard
rest room, confirming `(boss)`/`(admin)` status is recognized) →
`update /adm/daemons/named.lpc` succeeds ("重新编译 ... ：成功！").
Also upgraded the wizlist entry from `fluffos (admin)` to `fluffos
(boss)` -- this lineage's `wiz_levels` ranks `(boss)` above `(admin)` as
the actual top tier, confirmed present in `securityd.lpc`'s
`trusted_read`/`trusted_write["/"]`.

Unrelated non-blocking runtime error observed only on the `fluffos`/
wizard-room entry path (not on regular player registration): `adm/kernel/
simul_efun/message.lpc:346`, "Bad argument 4 to EFUN message() Expected:
object, array, Got: int(0)" -- doesn't block anything (room description
still prints correctly afterward), not chased further this pass.

**Correction from this session's §10.7 deep-dive (see below): this was
under-scoped.** It's not wizard-specific -- it fires from
`logind.lpc`'s `enter_world()` for EVERY new character, not just the
`fluffos` admin account. Now fixed, see below.

## 深度功能测试（§10.7，本轮）

之前几轮只验证到"注册成功进入世界之树"这一步，`d/register/npc/pangu.lpc`
到"投胎"仪式之后的内容、以及上面提到的 `message()` 报错都没有深入查。这
次用真实驱动起服，走了完整流程：注册 → 生命之谷见盘古 → zz（选种族）→
xuan（选性别）→ choose（选性格）→ washto（洗点，本 lib 的分配区间是
13-30、总和 80，跟 xfbhh 的 10-200/200 不同——这是正常的数值设计差异，
不是 bug）→ 进入"世界之树"新手村，全程用了好几个不同的中文名字反复验
证，`debug.log` 全程保持空白。

### 发现并修复的 bug

**1. 与 xfbhh 完全相同血统的 §7.78：13 个 CHARACTER 组成 mixin 文件
（`action`/`apprentice`/`attack`/`attribute`/`command`/`condition`/
`damage`/`equip_liv`/`message`/`more`/`move`/`name`/`team`）里的裸
`set()`/`query()` 调用无法正确解析到本对象的 F_DBASE。** 这个 lib 跟
xfbhh 共享同一份 `dbase.c`/`name.c`（逐字节内容一致，只有排版差异），
所以这就是同一个架构缺陷的第二个实例——不是巧合，是同一血统的共同祖先
问题。修法完全一致：把这些 mixin 文件里"自己对自己"的裸调用改成
`this_object()->set(...)`/`this_object()->query(...)`（call_other），
让调用动态派发到真正组合出来的对象身上。修复前 `command.lpc` 的
`enable_player()`——每个新角色登录都会触发——会因为裸 `query("id")`
读回 0 而让 `set_living_name()` 崩溃；修复后完整走了好几次注册流程，
NPC 名字（"盘古[Pan gu]"）和玩家自己的名字在对话里都正确显示。

**2. 重新定位并修复了 README 里早就记录、但归因错误的
`efun::message()` 崩溃。** 原记录说这个 bug"只在 fluffos/巫师房间入
口路径观察到，不在普通玩家注册路径上"——这次深挖发现完全不是这样：
`adm/daemons/logind.lpc` 的 `enter_world()` 第 1664 行
`message("system", ADD2(user), users);` 这个调用只传了 3 个参数，而
`adm/kernel/simul_efun/message.lpc` 里的本地 `message()` 包装函数签
名是 `void message(mixed arg, string message, mixed target, mixed
exclude)`——不是 varargs，缺的第 4 个参数 `exclude` 会被静默补成整数
`0`，再传给 `efun::message(...)` 时这个驱动的原生 message() efun 拒
绝接受字面 `0` 作为 exclude（要求 object/array 或者干脆不传）。这意味
着**每一个新角色**在 `enter_world()` 阶段都会撞上这个报错，不只是巫
师账号——之前的记录之所以只在巫师入口观察到，大概率只是因为那一轮测
试没有用普通玩家账号复现到这一步。修法沿用 xfbhh 之前已经验证过的同
一处：`if (!exclude) exclude = ({});` 补齐再转发给 `efun::message()`。

**3. §7.68 死亡/复活软锁，5 处实例**（`d/death/npc/{bai,hei,bgargoyle,
wgargoyle,chacha}.lpc`——比 xfbhh 多一个 `chacha.lpc`）：`death_stage()`
的 `if (!ob || !present(ob)) return;` 把"角色永久离开"和"角色只是暂时
不在场"混在一起处理。按各文件自己原有的重试间隔拆分修复：bai/hei/
bgargoyle 是 5 秒，wgargoyle 是 10 秒（其 `init()` 首次用 30 秒），
chacha 是 3 秒。

### 未继续测试的部分

`score` 指令这次测试里没能稳定拿到完整角色卡输出（怀疑是任务提示消息
挤占了同一批返回，不是指令本身的问题——`debug.log` 全程没有任何报
错，`气`/`精`/`内力` 状态条数值在多个测试角色间高度一致，看起来是设计
好的数值而不是随机/错误数据）；没有触发死亡/复活流程去验证这次的 5 个
§7.68 修复是否真的生效（下一轮如果继续深挖这个 lib，建议优先找怪打死
一次角色验证）；也没有走 `d/register/yanluodian.lpc`（阎罗殿，"投胎"
仪式的一部分，`wash`/`born` 指令）——粗略读了一下代码，这个房间看起来
是死亡/转生系统的一部分，不是初始注册流程会经过的地方，留给专门测试
死亡循环的下一轮。

## LPC formatter (WASM pass)

Ran across all 24177 `.lpc`/`.h` files (24082 written). Blind-spot check
found 5 files with confirmed CJK re-spacing corruption (`d/yixing/doc/
set_bang.h`, `help/family.h`, `help/intro.h`, `help/map.h`, `u/lonely/
skybook/lianchengjue.lpc`) via a same-text-despaced-matches-old-file scan
across all 287 formatter-touched files containing CJK-space-CJK
sequences; all 5 reverted. Also directly diff-reviewed all 6 `map.lpc`
ASCII-art zone-map files in this lib (`d/shaolin`, `d/emei`, `d/city`,
`d/guanwai`, `d/gaochang`, `quest/skybook/xsfh`) since box-drawing art
doesn't match the CJK-space regex -- all 6 clean (only cosmetic
brace/spacing reformatting, string-literal content byte-identical).
Post-formatter re-verified: clean boot, zero compile errors, registration
and admin `update` both still working.

## Not yet done (out of scope for this pass)

- Full `lpcc_check.sh` compile sweep — skipped deliberately, same
  reasoning as `nitan170911` (mega-lib, single-VM sweep risks OOM without
  finding new bug classes beyond what the boot+interactive test already
  found).
- WASM export / GitHub Pages packaging — deferred to a later batch pass.

## WASM 修复摘要（迁移自 meta.json 的 group_note）

NT/nitan/Lonely 血统，nitan170911 的手足档案（master.c/dbase.c 逐字节相同）——之前一轮原生启动测试里已经移植了 nitan170911 完整的 §15 dbase 架构修复系列。这次 WASM 修复找到了之前那轮"update 指令返回默认失败讯息"这个未解决遗留问题的真正根源：adm/daemons/named.lpc 的 create() 对自己损坏的约 168KB 存档档案（Illegal mapping format）做了未加保护的 restore()，抛出的异常没有被捕获——这个驱动上，一个未被捕获的 create() 异常会让这个物件永久无法驻留，之后任何隐式的 NAME_D->invalid_new_name(...) 字符串呼叫在这个还没加载的物件上什么都不会做（没有报错，没有重试），而不是自动编译它。由于 get_char()（角色创建）在真正走到 make_body()/enter_world() 之前就会呼叫这个函式，每一次新角色创建都会在这里静默死掉——没有崩溃，没有可见错误——连线卡住，从未设置任何指令处理路径，导致之后每一条指令（不只是巫师指令）永远撞上通用的"什么？"失败讯息。这影响的是所有玩家，不只是管理员账号；之前那轮原生测试的诊断（认为是巫师专属动词的指令搜索路径缺口）并不完整，这是可以理解的，因为基于 write() 的调试没法区分"呼叫静默空跑"和"动词没找到"。已用标准的 §7.41 损坏存档数据防护修复：named.lpc 的 create() 里包一层 catch(restore())。是通过在 get_char() 里用 write() 做二分定位找到的（log_file() 在不同的 WASM 调用之间不会持久化，所以只能在真实的交互式 input_to 环境里用 write()）。另外把 wizlist 条目从 fluffos (admin) 升级成了 fluffos (boss)——这条血统的 wiz_levels 阶梯把 (boss) 排在 (admin) 之上作为真正的顶层，securityd.lpc 的 trusted_read/trusted_write['/'] 里也确认了这一点。已验证：完整注册→look/score→fluffos 被正确带到巫师休息室，确认 (boss) 身份被识别→update 成功。LPC 格式化工具对全部 24177 个档案运行；还原了 5 个通过"去空格后比对旧档案"扫描（覆盖全部 287 个格式化工具触碰过的档案）确认有 CJK 重新加空格损坏的档案；另外直接逐一比对了全部 6 个 map.lpc ASCII 地图档案（方块字符画不会命中 CJK 正则）——全部 6 个干净，只是排版调整。格式化后重新验证过，干净。


## 更正（2026-08-05）：§7.68 复活软锁"修复"已撤销

上面提到的"鬼魂离开/不在场时被永久放弃复活流程"曾被当作 AGENTS.md
§7.68 记录的一类 bug 修复（把单次判定改成每 5 秒重试）。经用户指出并
重新审视：这更可能是**有意的游戏设计**，不是 bug——大多数这类档案里
鬼魂根本无法自行移动，所以"不在场"要么从未真正发生，要么是"离开去
在阴间游荡，想回来时再走回这个房间、流程会通过 init() 重新从头开始"
这种有意为之的宽松机制，而不是需要强制追上玩家的错误。强行重试还可能
引入新问题：如果鬼魂之后又走回这个房间，旧的重试和 init() 重新触发的
新一轮流程可能同时运行，导致对话重叠错乱。已把这处改动撤销，恢复成
原始的 `if (!ob || !present(ob)) return;` 单次判定写法（`bmxkx2001`
除外——那份档案里这确实是一个真实存在、经过实际复现验证的 bug：鬼魂
本身完全无法移动，是另一个不相关的 NPC 强行把鬼魂拖走导致的）。详见
AGENTS.md §7.68 顶部的撤销说明。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 83 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（2026-08-12，round two，新驱动重测）

用新编译的 `~/src/fluffos/build-debug/src/driver`（origin/master 最新拉取，
含本项目自己提交并合入的 #1343/#1344 两个 PR）重新验证。

### `to_int()` 任务计数器修复

`adm/daemons/combatd.lpc`/`cmds/std/whisper.lpc` 里全部 `quest_count = ...
% 500` 已经是 `to_int(query(...)) % 500` 的修复后形状（本会话早前的语料库
扫描已覆盖），无需改动。

### 新发现并修复：`log_error()` 大小写不匹配导致警告过滤形同虚设

`adm/kernel/master/error.lpc` 的 `log_error()`（AGENTS.md §7.103 已有先例，
这是同一 bug class 在 kernel 架构、不是 single-file master 架构下的第 N
个独立实例）：`error_type = strsrch(message, "Warning") == -1 ? "错误" :
"警告"` 只匹配大写 `Warning`，而真实编译器输出的是小写 `warning:`——这个
大小写不匹配意味着 `error_type` 恒为"错误"，但**更关键的是**：这段代码
从来没有真正拿 `error_type`（或任何等价判断）去**门控**是否要
`tell_object()` 转发给玩家——不管是不是纯 warning，一律无条件转发。新注
册流程期间反复触发（每个第一次被懒编译的档案都会命中），修复：改成不区
分大小写匹配 `"warning:"`，只在真正的 error 时才 `tell_object()` 转发给
玩家（`debug` 频道广播给巫师和 `write_file()` 落盘均保持不变，未受影
响）。**现场验证**：修复前后各跑一次干净的全新账号注册流程对比，修复后
的欢迎序列（news/msg/wenxuan 提示）不再夹带任何"编译时段错误：...
warning:"文本。

### 之前记录的"什么？"排查：证实是 tmux_mud.sh 的已知 CJK 传输问题，不是驱动回归

本轮一开始用 `tmux_mud.sh` 送中文名字（"秦风六"、"凌霄"）反复触发
`check_legal_name()` 拒绝（"对不起，请您用「中文」取名字。"），一度怀疑
是本会话审查并合入的 PR #1344（O(1) ASCII 字符串快速路径）引入的字符串
处理回归——认真排查过：用 `lpcshell` 直接、脱离网络层测试
`is_chinese()`、`name[i..i]` 单字符切片、以及和真实代码路径完全一致的
`explode(arg, "║")`，三项在纯 LPC 字面量输入下全部返回正确结果。结论：
驱动本身的字符串处理完全正常，问题在 `tmux_mud.sh` 本地 telnet 客户端对
中文的传输损坏（AGENTS.md §10.2 已有先例，和 `zhonghua2`/`ntii`/`nte`
本轮记录的现象一致）。改用 `scripts/mudclient.py`（原始 socket）后同样
的中文名字注册流程一次成功。

### 冷启动级联编译撑爆 `maximum evaluation cost`（AGENTS.md §7.90/§10.8 已有先例）

刚重启的驱动上，连续几次全新账号注册各自在 `enter_world()` 链路上不同的
文件（`clone/user/user.lpc` 的 `calc_sec_id()`、`adm/kernel/
simul_efun.lpc` 的 `append_color()`、`adm/daemons/band.lpc` 的
`load_welcome()`）触发"Too long evaluation. Execution aborted."——每次都
是当时还没被懒编译过的不同档案，符合已知的"冷启动一次性懒编译级联撑爆
`maximum evaluation cost`（700000，未改动）"既有类别，不是新的独立 bug，
也不是驱动升级引入的回归（同一会话里 `ntii`/`nte` 用同一份升级后驱动测
试时记录了完全相同的现象）。**验证自愈**：驱动"热身"几次注册尝试后（多
数常用档案已被编译进内存），后续全新账号（`qinfengba`）一次性干净走完
注册→"泥潭注册室"→欢迎序列，全程零报错。

### 完整游玩测试范围

沿用 round one 已经验证过的"注册成功进入洪荒世界，欢迎序列正确显示"作为
及格线（`score`/`born` 相关的盘古投胎仪式在 round one 已确认是深山之外
的独立系统，本轮同样未走）。战斗/死亡循环仍未触达——受限于本轮时间预
算，留给下一次专门测试。

### 本轮结论

驱动升级后 hhsj 整体状态良好：任务计数器 `to_int()` 修复确认已生效；新
发现并修复一个真实的 `log_error()` 严重度门控缺失 bug（§7.103 家族第 N
例）；此前记录疑似"什么？"的诡异现象证实只是本地 telnet 传输问题，不是
驱动或代码的 bug；冷启动 eval-cost 级联属已知类别且验证自愈。测试账号
（`fluffos`/`fluffosb`/`qinfengwu`/`qinfengliu`/`qinfengqi`/`qinfengba`）
存档留在 `data/` 下作为佐证，未清理（同批次未跟踪文件，不纳入本次提
交）。

## 深度功能测试（2026-08-17，round three）——补完战斗测试，发现并修复一个比先前记录更严重的 §7.90 变体：角色创建本身会被撞垮

本轮目标是补完 round one/two 一直搁置的战斗/死亡/复活循环，过程中先撞
上一个比 round two 记录过的"冷启动 eval-cost 级联，自愈"更严重的同类
问题，实际上会让角色创建本身失败。

- **发现：`get_char()` 里 `make_body()` 的冷编译被 eval-cost 中断，
  未捕获，导致新角色永久卡在无指令状态**（比 round two 记录的"自愈"
  现象更严重的同一类根因）：用全新英文 id 走完 `get_user()` 那一步
  （`id,password,cipher,email` 单行格式）后，输入 `性别║img║中文名字`
  （`get_char()` 期望的格式）时，`make_body(ob)` 第一次冷编译整条
  `/inherit/char/char.lpc` 继承链，在 `700000` 的默认 eval-cost 限额
  下被 `Eval interrupted: object adm/kernel/master cost limit reached`
  反复打断（`debug.log` 里连续十几条），而 `get_char()` 对这整个流程
  没有任何 `catch()` 保护。中断发生在 `input_to("get_char", ob)` 重新
  注册之前，于是连线对象 `ob` 掉回默认指令处理，之后任何输入
  （包括空行、`look`、`score`）一律得到通用的"什么？"——账号数据从未
  真正写入（`registered:0`），角色永久无法建立，且没有任何提示告诉玩
  家出了什么问题。这不是 round two 记录的"某些请求恰好赶上冷编译，重
  试几次就好"那种温和表现，而是**第一次创建角色就可能被直接打断且无法
  恢复**，比 round two 保守估计的影响面更大。round two 当时只观察到
  "自愈"（后续注册变干净），没有意识到那正是"冷编译期间被打断的角色
  从此报废"的另一面。
- **修复**：沿用本项目 §7.90 已确立的标准手法，`config.fluffos` 的
  `maximum evaluation cost` 从 `700000`（此项目最常见的模板默认值）
  提升到 `5000000`（此项目内 30+ 档案已经在用的同一个值）。**现场验
  证**：重启一个全新驱动进程，同一账号（`qintestc3`）的角色创建流程
  （`get_char()` 那一步）一次性干净完成，`debug.log` 里再没有任何
  `cost limit reached` 记录，随后完整走完"盘古投胎"仪式
  （`zz`/`xuan`/`choose`/`washto`）进入"古村"/"世界之树"，`score` 正
  确显示所有选择（种族人类、性别男性、性格光明磊落、四维 20/20/20/20）。
- **副作用发现：`fluffos` 管理员账号本身就是这个 bug 的受害者**——检
  查 `data/login/f/fluffos.o` 发现这份档案里的 `fluffos` 账号早就存在
  一份"只有登录层存档、没有角色层存档"的半成品记录（`registered:0`），
  推测是此前某一轮标准的 admin 播种流程走到 `get_char()` 冷编译时被同
  一个 bug 打断，之后从未被发现或补完（因为 `fluffos` 从未真正需要
  重新登录去验证）。用已修复的驱动重新走一次 `fluffos` 的角色创建
  （复用已经保存的登录层密码 `Mud@2026`，直接进入巫师休息室，跳过盘古
  仪式），`wizlist` 确认 `(boss)` 权限正确识别——修复了这个此前被
  忽略的半成品账号。
- **新发现、未修复：`is_admin()` 与 wizlist 权限阶梯是两套独立的授权
  机制，标准的 admin 播种流程只覆盖了后者**——`clone`/`summon`/
  `smash` 等强力指令额外用 `me->is_admin()`（`clone/user/user.lpc`）
  把关，这个函式只有 `admin_flag==21`（只能通过 `set_admin()` 设置，
  而 `set_admin()` 要求 `is_root(previous_object())`，需要真正的
  root-euid 调用者）或者硬编码的两个原始服主 UID（`uuuu`/`iiii`）才
  会返回真。全档案搜索确认 `set_admin()` 从未被任何指令实际调用
  过——这条路径在这份快照里完全无法通过正常游戏流程到达。也就是说本
  项目"播种 fluffos 进 wizlist 即可获得完整巫师权限"的标准约定，在这
  份档案上并不完整：`fluffos` 拥有 `(boss)` 这个 wiz_level 阶梯里的
  最高等级，但 `is_admin()` 恒为假，`clone`/`summon`/`smash` 全部被拒
  （"你不能复制物品。"等）。判断这不是需要修复的 bug（`uuuu`/`iiii`
  是原始正式服主的账号，硬编码进代码里更像是刻意的、独立于 wizlist 之
  外的第二重保护，不像是疏漏），而是这份档案的一个真实限制，记录下来
  避免以后重新踩坑、重新排查。
- **战斗验证**：`is_admin()` 受限导致没法用 `clone` 变出强力 NPC 或用
  `smash` 直接测试死亡，转而用真实走位找到新手村外"乱石岗/竹林"一带
  的"野兔"（`clone/quarry/tu`，原本是采集资源用的，但支持 `kill`）反
  复交手验证：伤害数字、命中部位描述、气血百分比、胜负判定全部正常，
  完整拿下一场战斗（"只听野兔嚎了几声，倒在地上扑腾了几下，死了。"）。
  但角色躲避率明显碾压这些弱资源怪，30 回合连续开战气血纹丝不动
  （100/100），无法用它们触发真正的死亡。
- **未覆盖、留给下一轮**：真正的死亡/复活循环、留言板发帖——本轮探索
  确认新手村范围内（世界之树、青石小路、后村小路、乱石岗、乱坟岗、竹
  林）没有任何威胁性 NPC，是有意设计的安全教学区；真正的危险区域在新
  手村之外的主世界（`d/guanwai`、`d/kaifeng` 等已确认存在
  `attitude: aggressive` 的 NPC），但从新手村步行过去的具体路径本轮未
  探明，且 `is_admin()` 限制排除了用巫师工具走捷径的可能。下一轮如果
  继续测试，建议：(1) 先探明新手村到主世界的具体出口/传送点；(2) 或者
  升级测试角色到一定等级后村庄本身可能会开放更多区域；(3) 死亡机制本
  身的代码（`inherit/char/`、`d/register/yanluodian.lpc`）值得直接读
  代码先确认死亡触发条件和复活流程的实现，不必完全依赖实战复现。
