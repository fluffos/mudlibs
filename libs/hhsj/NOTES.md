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

## AGENTS.md §7.100 修复（2026-08-19）

同 `jhfy3` 起源发现的 `ROOM` 基类冗余 `replace_program(ROOM);` 自崩
溃地雷（详见 AGENTS.md §7.100）：本 lib 4984 个房间文件的 `create()`
末尾（紧跟 `inherit ROOM;`）都有这一行多余调用，第一次对该房间对象
绑定闭包会永久失败。同款地雷也烤进了自带建房工具
`clone/misc/roommaker.lpc` 的一处字符串拼接代码生成模板。

修复：脚本化删除所有房间文件里独立成行的 `replace_program(ROOM);`
（`d/huangshan/banshan.lpc` 有两处独立调用，均删除），加上
roommaker.lpc 里手动摘除字符串拼接片段。`git diff --stat`：4985
files changed, 1 insertion(+), 4987 deletions(-)，与预期精确吻合。

验证：`build-debug` 驱动真实冷启动，端口 40106 正常监听，
`debug.log` 全程干净。管理员 `fluffos` 账号（本 lib 特有的"自连数
据库"登录握手：单行 `id,password,x,email`，收到 `ver1.0,...`/"版本
验证成功" 后再发送）`goto` 走访 14 个刚修复的房间（`d/huanggong`/
`d/yuanyue`/`d/lingxiao`/`d/luoyang`/`d/taishan`/`d/huijiang`/
`d/newbie`/`d/item`/`d/death`/`quest/zhuzao` 等区域），均正常返回，
无 "cannot replace"/"cannot bind" 新增日志行。按精确 PID 结束驱
动；登录产生的存档增量已通过 `git add -u` 只暂存已跟踪文件规避（未
跟踪的 `.o` 存档文件本就是会话开始前已存在的未跟踪状态，未触碰）。

## AGENTS.md §7.79 修复（2026-08-19）

裸 `addn("prop", value)`（无第三参数）恒为静默无效果：simul_efun
shim（`adm/kernel/simul_efun/wizard.lpc`）里 `ob` 缺省为
`this_object()`，但这是在 simul_efun 内部求值，指向的是 simul_efun
对象自身而非真正调用者，写入垃圾去处、静默丢失。3 参及以上调用（显
式传 `ob`）从调用点求值，本就正确不受影响。方法论、脚本、以及
"定义 vs 调用"判别修法详见同源 `xfbhh` 的 NOTES.md 对应小节（同一
`fix_addn2.py`）。

本 lib 只有 `clone/user/baby.lpc` 一处本地覆盖（覆盖 `addn` 未覆盖
`addn_temp`，同 xfbhh），排除其 8 处 `addn(...)` 调用；未发现
xfbhh 那种 `clone/user/user.lpc` 命名笔误覆盖（本 lib 该处正确命名
为 `add`）。结果：907 处改写，`git diff --stat`：456 files changed,
907 insertions(+), 907 deletions(-)，加上排除的 8 处，907+8=915，与
调查阶段统计精确吻合。

验证：`build-debug` 驱动真实冷启动，端口 40106 正常监听，`debug.
log` 全程干净，无新增编译错误。全新账号（`qintest915`/角色名"秦测
九"）走完注册流程，成功进入泥潭注册室并收到欢迎序列，符合 §10.1 及
格线。按精确 PID 结束驱动。

## 深度功能测试（2026-08-20，round four）——补完死亡/复活循环 + 留言板发帖，发现并修复真实的 §7.112 缺口

本轮目标：round three 记录的两处未测项——真正的死亡/复活循环、留言板
发帖。用 `build-debug` 驱动真实起服（端口 40106），全程用
`scripts/mudclient.py` 同款的自制 Python raw-socket 脚本交互（本 lib
的登录握手是自连数据库单行 `id,password,cipher,email` + `性别║img║
中文名字`，`tmux_mud.sh` 的本地 telnet 传输问题在本项目其他 lib 上已
有先例，直接用 raw socket 规避）。

### 发现并修复：`d/death/npc/{bai,hei}.lpc` 是 §7.112 sweep 遗漏的两个实例

深挖代码确认 `DEATH_ROOM`（`include/login.h` 定义为 `/d/death/gate`）
就是这个 lib 里**所有**玩家死亡（不限于 PK/巫师）后真正落地的房间，
房间里驻扎的正是 `npc/bai.lpc`（白无常）。这条 NPC 血统跟 §7.112 已
经扫过的 `wgargoyle.lpc`/`bgargoyle.lpc`/`chacha.lpc` 系出同源（同一
`death_stage()` 五段对话 + `call_out` 递归模式），但本 lib 之前两轮
sweep（`eada77df3e0` 第一波只覆盖了 `bgargoyle.lpc`/`wgargoyle.lpc`，
`a33b1f614e5` 第二波只补了 `chacha.lpc` 和 `maze/battle1/{e,w}gate.
lpc`）都没有覆盖到 `bai.lpc`/`hei.lpc`——这两个文件在
`d/death/gate.lpc`/`d/death/gateway.lpc`（酆都城门）里被真实调用，且
是这条整个 lib 的死亡系统里**唯一**会被绝大多数普通玩家死亡触达的两
个实例，之前的 sweep 用 `wgargoyle.lpc` 文件名做种子扩散，而
`bai.lpc`/`hei.lpc`是完全不同的文件名，两波都被漏掉了。修法沿用完全
相同的既有模式：`init()` 里 `query_temp("death_stage_active")` 门控
+ `set_temp`，`death_stage()` 每个真正的退出点（不在场提前返回、五段
对话播完转投胎）都配对 `delete_temp`。改动详见
`d/death/npc/bai.lpc`/`hei.lpc` 的 diff，跟 `bgargoyle.lpc` 已验证过
的修复形状逐行对应。

### 死亡/复活循环：战斗死亡本身完整可用，但 `death_stage()` 对话没有现场触发——记录为未解之谜，不强行修复

用真实走位（`ask lao about 出村` → `choose` 选路 → `ask hua about 出
村` → `3`+`f5` 选武当派拜师 → 送到武当三清殿）代替 wizard `goto`
（round three 已确认 `is_admin()` 权限阶梯在本 lib 上不可达，
`clone`/`smash` 等强力指令全部被拒），战斗测试用 `d/wudang/tufeiwo{1,
2,3}` 土匪窝的 `土匪头`（combat_exp 20000, apply/attack 30）反复交
手。关键发现：**跳过村长赠送的 `closeeye` 属性/技能大礼（1500000点技
能经验）的角色明显脆弱得多**——带了 `closeeye` buff 的角色跟土匪打
了好几轮气血纹丝不动（跟 round three 记录的现象一致），跳过
`closeeye` 的"素体"角色反而会被土匪头打到"看来该找机会逃跑了..."，
且土匪头会主动拦截逃跑（"你逃跑失败"），最终被真实打死（两次独立复
现，`qintestd2`/`qintestd3` 两个测试角色）。

死亡流程本身完全正常：战斗判定 → 尸体生成 → 频道公告死讯 → `ghost=1`
→ 正确移动到 `【鬼门关】`（`DEATH_ROOM`）→ 房间描述、`白无常`/`黑无
常` 在场，全程 `debug.log` 保持干净，没有任何报错或崩溃迹象。

但**反复验证（含一次全程不断线、一次断线重连两种场景，累计等待超过
40 秒）都没有观察到 `death_stage()` 的五段对话文本（"喂！新来的，你
叫什么名字？"等）出现**，只看到 `chat_chance` 随机闲聊 flavor
（"白无常狠狠的敲了敲你的脑袋"之类）——这意味着 `reincarnate()`（清
除 ghost 状态、回满气/精）和自动送回 `REVIVE_ROOM` 这条便捷路径这次
没能现场验证成功。没有找到根因（`debug.log` 全程零报错排除了显式崩
溃；`init()` 的四个前置条件在静态审查下均应满足；没有可用的巫师
`call` 指令做运行时内省，`is_admin()` 权限阶梯不可达）。**好消息是：
死亡不是硬死锁**——手动 `north` 可以从 `【鬼门关】` 走到
`【酆都城门】`→`【鬼门大道】`，确认存在一整条可步行的冥界通路（呼应
round three 记录的"投胎"仪式 `d/register/yanluodian.lpc`），所以哪怕
`death_stage()` 对话没触发，玩家也不会被永久卡死，只是少了这条自动
对话+送回阳间的便利路径。这次没有强行猜测式修复——不确定是本
lib 独有的环境因素还是这条 NPC 血统本身在"move() 进入房间是否可靠触
发 init()"这件事上有更深的问题，留给下一轮如果有巫师权限或者
write()-based 现场调试手段时再深挖，不在没有确凿根因的情况下动代码。

### 死亡/复活循环，第二轮跟进：拿到了真正的巫师工具，但仍未现场复现死亡——is_admin() 之外发现了第二条独立的权限阻断根因

本轮目标是拿到真正的巫师级现场调试手段（write()/log_file() 或
`call`/`call_out_info()`），把上一轮"没有确凿根因不动代码"的死循环调
查往前推一步。结果：拿到了部分巫师权限、缩小了根因范围、发现了一个
此前未记录的独立 bug，但**这一轮仍然没能让测试角色真正走到"鬼魂站在
【鬼门关】里"这一步**，所以 `death_stage()` 本身有没有触发依旧没有
现场证据——比上一轮更清楚一点，但还是没有定论。

- **`fluffos`（boss）巫师权限重新核实**：`update`（重新编译档案）和
  `goto`（巫师瞬移）两个指令都只经过
  `SECURITY_D->valid_grant(me, "(wizard)")` 这一道关卡（`(boss)` 在
  `wiz_levels` 阶梯里天然大于 `(wizard)`），**不需要 `is_admin()`**，
  现场验证两者都能正常使用（`update /d/death/npc/bai.lpc` 成功重新编
  译；未实际使用 `goto` 但读代码确认门槛相同）。`is_admin()` 本身依
  旧不可达（`admin_flag==21` 只能靠 `set_admin()` 设置，而
  `set_admin()` 要求 `is_root(previous_object())`，全档案里没有任何
  指令会以 root euid 调用它；硬编码的 `uuuu`/`iiii` 是原始服主账号，
  不是我们能复现的身份）——这点和 round three 的结论一致，不是新发
  现。
- **新发现：`clone`/`call`/`smash` 被拒的根因比"is_admin() 不可达"更
  深一层**——`data/securityd.o` 里确实存过
  `site_privilege(["call":"all","clone":"all", ...])`，理论上即使没
  有 `is_admin()`，这两个指令的权限判定分支（`cmds/arch/call.lpc`、
  `cmds/wiz/clone.lpc` 里 `!me->is_admin()` 之后的
  `switch(SECURITY_D->query_site_privilege(...))`，命中 `"all"` 时
  直接放行）应该能生效。但 `adm/daemons/securityd.lpc::restore()` 对
  `site_privilege` 有一个基于 `crypt()` 的完整性校验（用固定
  `SEC_SEED` 累加所有键值算出一个校验和，跟存档里 `INTERMUD_MUD_NAME`
  项存的哈希比对），**这份存档校验不过**——现场启动驱动后
  `log/nosave/security` 立刻出现十几行 `site_privilege information
  encrypted.`，`restore()` 在校验失败分支里把整个 `site_privilege`
  清空成 `([])`。于是不管 `call`/`clone` 目标是谁，`switch` 都落进
  `default` 分支，返回"你不能使用该命令。"/"你不能复制物品。"——跟
  round three 记录的拒绝提示逐字对应。这份存档来自最初的
  `mudlib.rar` 归档（`git log` 只有一次改名提交动过这个文件，早于本
  项目任何一轮调查），推测是原始正式服上曾经用 `sp` 指令合法设置过
  这个权限，但归档时的驱动/数据版本和现在重新编译的 fluffos 在
  `crypt()` 细节上不完全一致，导致校验和对不上——**没有找到能在游戏
  内合法修复它的路径**（`sp <class> <info>` 指令本身设置新值也要求
  `me->is_admin()`，跟 `clone`/`call` 卡在同一堵墙后面），判断这是这
  份归档快照的第二个真实限制（跟 `is_admin()` 不可达是两条独立但互相
  加强的死路），不是本轮该动手修的 bug——不在游戏机制之外用文件级手
  段绕过管理员权限校验。
- **`bai.lpc`/`hei.lpc` 静态复查：结构上没有发现新问题**——两份文件
  的 `init()`/`death_stage()` 早已是 `§7.112` 记录过的已修复形状
  （`death_stage_active` 在 `init()` 里设置、在 `death_stage()` 的所
  有真正退出点配对清除），`init()` 的四个前置条件（`previous_object()`
  存在、`userp()`、`is_ghost()`、非 `wizardp()`）跟标准
  `move_object()` 驱动语义（进入房间时，房间里每个 living 对象的
  `init()` 都会以 `previous_object()==` 到访者的身份被调用一次，不需
  要显式参数）吻合，没有发现类似 `zsdsj` 那种"驱动零参数调用
  `init()` 却被当成需要参数解引用"的崩溃模式。为了现场验证到底是不
  是真的触发，临时在 `bai.lpc` 的 `init()`/`death_stage()` 里加了
  `log_file("nosave/deathstage_dbg", ...)` 探针，用巫师 `update` 指
  令热编译生效——**但本轮测试角色始终没能真正走到"鬼魂站在
  【鬼门关】"这一步**（见下），探针文件全程没有任何一行输出，说明失
  败发生在更早的阶段（没能真正死亡），不能证明或证伪 `init()`/
  `death_stage()` 本身的行为。已经把这段探针代码完整移除，`git diff`
  确认 `bai.lpc` 恢复到跟上一次提交完全一致。
- **本轮没能复现真实死亡，原因是测试工具问题，不是游戏机制问题**：
  1) 用于自动化操作的裸 Python socket 脚本一开始用"读到空闲再返回"
     的策略等待每条指令的响应，但本 lib 进入游戏世界后客户端会持续
     收到一条每秒刷新一次的气血/状态提示行（形如
     `012测试辛:100/100:...`），这条心跳式提示让"读到空闲"永远等不
     到空闲，脚本卡死在 `washto` 之类的指令上——这正是已有笔记
     `feedback_recv_loop_breaks_on_live_clock_prompt.md` 记录过的同
     一个坑，本轮又踩了一次（后已改成硬性总时长上限，问题解决）；
  2) 从武当三清殿（`d/wudang/sanqingdian`）走到"土匪头"所在的
     `d/wudang/tufeiwo3` 需要精确的 20 步方向序列（先靠人工誊抄，中
     间漏抄了一步 `northdown`，导致测试角色在山路上越走越偏，最终走
     到不相关的"磨针井"/"藏经阁"，从未真正遇到"土匪头"）。已经用脚
     本从各房间文件的 `exits` 字段做 BFS 重新算出并核对了完整正确路
     径：`north, northdown, northdown, northdown, northdown, northup,
     northdown, northup, northdown, northdown, northdown, northdown,
     east, eastdown, eastdown, east, east, southup, south, east`（三
     清殿 → 广场 → 紫霄门 → 十戒 → 十八盘 → 石梁 → 太子坡 → 山路一 →
     好汉坡 → 五斗炕/... → 玉真宫 → 十戒一 → 玄岳门 → 蛇形岭三 → 剑劲
     岩 → 蛇形岭二/一 → wdroad10 → tufeiwo1 → tufeiwo2 → tufeiwo3），
     留给下一轮直接照抄使用，不用重新摸路。
- **测试账号清理**：`qintestg1`/`qintestg3`（本轮反复摸索用，均未能
  真正抵达"土匪头"或死亡）的存档已删除，未留痕迹。
- **结论**：`death_stage()` 为什么现场没触发这个谜团**依旧没有解
  开**，但排除范围比上一轮更精确了——`bai.lpc`/`hei.lpc` 的代码本身
  静态审查没有发现明显 bug；管理员权限方面确认了 `update`/`goto` 这
  类非 `is_admin()` 门槛的巫师工具是可用的，但 `call`（原本设想用来
  做运行时内省，比如 `call_out_info()`）依旧被一个独立于
  `is_admin()` 之外的 `site_privilege` 校验和损坏问题挡住，这条路线
  在这份归档快照上被双重锁死。下一轮如果要继续深挖，建议：(1) 直接
  复用上面标注的 20 步路径省下摸路时间；(2) 用带硬性总时长上限（而
  不是"读到空闲"）的收发循环写自动化脚本，避免重蹈这次的坑；(3) 如
  果这次的 `bai.lpc` 探针方案要重新启用，记得走完整条死亡流程再看探
  针文件，而不是中途放弃。

### 留言板发帖：完全正常

在 `d/wudang/sanqingdian` 的 `武当弟子留言板`（`clone/board/
wudang_b.lpc`，`inherit BULLETIN_BOARD`）用 `post <标题>` 进入多行编
辑器（`结束离开用 '.'`），输入两行英文正文，`.` 结束后立即"新贴子完
成。"，`read new` 完整读回标题/作者/时间/两行正文，逐字节正确，没有
触发 §7.114（`private input_line()`，本 lib 未受影响，已用
`feature/edit.lpc` 静态检查确认）。全程 `debug.log` 无新增报错。

### 标准检查清单快速复核（本 lib）

- **§7.90**：`config.fluffos` 的 `maximum evaluation cost` 仍是
  `5000000`，确认未回退。本轮额外发现：即使有这个提升值，`walk`
  指令在冷启动、跨多个未编译房间/NPC 做长距离寻路时仍可能撞上
  eval-cost 中断（`adm/daemons/pathd` 自身，或沿途某个 NPC）——这不
  是新 bug，是已知类别（§7.90/§10.8）在"一次性寻路要展开几十个房
  间"这种更极端场景下的又一次表现，重试后（相关档案被懒编译进内存）
  即可正常完成，验证自愈。
- **§7.100**：全档案里已经没有独立成行的 `replace_program(ROOM);`
  （之前 4985 个房间文件已清空），唯一命中的两处 (`d/wuyi/wuyigong`
  `u/redl/tmp/builderroom`，均无 `.lpc` 扩展名) diff 比对后确认是格
  式化前的旧备份文件（跟同目录的 `.lpc` 版本内容不一致），非驱动实
  际加载的对象，不是回归。
- **§7.79**：`clone/user/baby.lpc` 本地覆盖排除正确，无新增裸 2 参
  `addn`/`addn_temp` 调用（本轮源码改动只涉及 `bai.lpc`/`hei.lpc`
  的 `death_stage_active` 守卫，未引入任何 `addn` 调用）。
- **§7.111**：`adm/kernel/master/error.lpc` 第 97 行 `standard_trace()`
  仍是 `error["object"] ? file_name(error["object"]) : "0"` 的三元
  守卫写法，未回归。
- **§7.112**：见上——发现并修复 `bai.lpc`/`hei.lpc` 两处真实缺口；
  全档案 `call_out("death_stage"` 搜索确认这两处修完后本 lib 的
  `d/death/npc/`+`maze/battle1/` 全部实例都已加上守卫。
- **§7.113**：AGENTS.md 已记录本 lib 在 2026-08-19 批次里静态确认
  clean（`logind.lpc::reconnect()` 正确调用 `user->reconnect()`，
  后者正确 `set_heart_beat(1)`），本轮未重新验证。
- **§7.114**：`feature/edit.lpc` 静态检查确认 `input_line()` 不是
  `private`，且本轮留言板发帖多行输入现场验证正常，未受影响。
- **§7.115**：AGENTS.md 已记录本 lib 的 `QUEST` 宏指向的档案确实缺
  失，但全档案搜索确认没有任何 `QUEST->` 调用点（`doc/legend/xkx25`
  里的"QUEST,"字样是无关的英文教程原文），死代码，无需修复。

### 本轮清理

测试账号 `qintestd1`/`qintestd2`（早期摸索用，中途因为账号状态或位
置不理想被放弃）的存档已删除；`qintestd3`（走完完整"注册→拜师→战
斗→死亡→鬼门关"全流程、最终确认死亡循环真实可用的账号）连同武当弟
子留言板的测试帖子存档保留作为本轮验证证据，未纳入 git 提交（本 lib
未跟踪的 `.o` 存档文件本就不在版本控制范围内）。驱动按精确 PID
（`kill 636652`）结束。

## §7.30 uninitialized-mapping accessor sweep (2026-08-20)

Corpus-wide mechanical sweep of the `feature/skill.lpc` shared-lineage
bug (confirmed independently on `xiakexing2017`/`jqxz2015`/`haiyang2`
via round-four testing): 6 accessor(s) in this file returned a raw
never-initialized `mapping` instance variable (defaults to `int 0`,
not `([])`, until first assigned), crashing any unguarded
`keys()`/`sizeof()`/indexing caller for a fresh/untrained character.
Fixed at the accessor level (`mapp(x) ? x : ([])`) per the documented
remedy. Verified via `lpcc --batch` static compile check only (not a
live boot) as part of a large mechanical sweep; not individually
functionally re-tested live on this lib.

## 深度功能测试（2026-09-04，shop）

Live native pass on port **40106** (`build-debug`). 2026-08-20 already
walked 武当拜师 (`qintestd3`); this slice is shop-only. First send after
`ver1.0,<ZJKEY>` / “版本验证成功” is `id,password,x,email` (commas OK;
`jiance()` does not check the key). `fluffos` / `Mud@2026` is `(boss)`
and lands in 巫师休息室. `clone` stays `is_admin()` locked (design);
`giveall /clone/money/gold` works and yields 中级灵石 (this reskin’s
gold).

**Bug fixed**: `feature/dealer.lpc` mixin `query("vendor_goods")` in
`init_goods()` and the GUI `do_list()` (CRLF preserved) — same §15
shape as `xfbhh`/`nitan170911` (file does not `#include <dbase.h>`).
After the fix, 醉仙楼 店小二 `list` shows 烤鸡腿 at 八十块灵石碎片.
GUI `buy jitui` only prompts “你要买多少【jitui】？”; `buy 1 烤鸡腿`
paid 1 中级灵石 → 99 灵石 + 20 灵石碎片 and delivered 烤鸡腿. No
`F_DEALER` 丐帮 refuse. Also corrected Huashan
`yue-buqun`/`yue-wife`/`feng-buping` and `qingcheng/yu.lpc`
`apprentice_availavble` typo (LF).

`log/debug.log` Boot Time Fri Sep 4 06:20:23 matches this run; no
`Error:` / `Wrong permissions` / eval-cost lines.

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 4 line(s) in 1 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-04）— paths named in another case

The archive comes from a case-insensitive host: files are stored as `BAGUA0.lpc`, `longjing.C`, `d/SHAOLIN/`, the code names them in lower
case (`__DIR__ "bagua0"`, `"tea/longjing"`, `"/d/shaolin/..."`), so the rooms, NPCs and items behind them could not be loaded (a `.C` file is
not an `.lpc` file; KB 03 §4.5). `scripts/lpc_case_paths.py --convert --apply hhsj`: 1 file(s) renamed to lower case (`.C` -> `.lpc`,
`.H` -> `.h`) and 0 path reference(s) in 0 file(s) rewritten to the new spelling; 0 skipped, 0 ambiguous. Load check of the 3 objects that were renamed, edited or name a renamed path (HEAD against the working tree, an object is the same under any spelling of its path): 2 PASS -> 3 PASS, 0 that loaded before fail now, 1 more load.

1 files moved (1 `.C`); mostly under `u/gigi/swing.C` (1). A rescan with `scripts/lpc_warnings.py hhsj` is still due: the renamed files are compiled for the first time.

## 深度功能测试（§10.7，2026-10-05）— room base survives a raising NPC

`scripts/lpc_resilient_room.py --apply`: `make_inventory()` of `inherit/room/room.lpc` loads each inventory object as `if (catch(ob = new(file)) || !objectp(ob)) return 0;`. `new()` of a file that is not there returns 0 (the room just lacks that NPC), but `new()` of a file whose `create()` raises (a skill file for `set_skill()` this archive never had, a `carry_object()` item that is not there, a header that never shipped) raised inside the room and the room did not load at all. The wrong-case renames of this lib (the section above) make the NPCs behind them reachable for the first time, so a room that holds one with such a content gap would have gone from "NPC missing" to "room missing"; now it loads without that NPC, as it did before. The room base compiles and loads with the change (HEAD against the working tree). KB 03 §4.5.

## 深度功能测试（§10.7，2026-10-06）— 与 zhonghua2 同源的三处编译警告

- `include/npc/indian.lpc` 与 `masia.lpc` 共用全局名 `ma_sname`/`ma_pname`；两个头文件被同一个守护进程（`npcd` 等）一起包含时，后包含的印度名表覆盖马来名表，`generate_ma_name()` 生成的是印度名字。印度表改名 `in_sname`/`in_pname`（KB 04 §6.10）。
- `cmds/std/team/bunch.lpc`、`cmds/std/team/swear.lpc`：结义失败提示被多余的 `;` 截成两句，`fail` 只剩"……可惜现在有人不在，$N"，后半句"的提议只好作罢。"丢了；接回去。
- `clone/drug/fengdong.lpc`：`if (... < 10000) max1 / 2;` 是空语句，改成 `max1 /= 2;`（经验不足一万的对手，分身技能减半）。

验证：改动的文件和包含 `npc/indian` 的守护进程在 HEAD 与工作树分别加载（`scripts/lpc_listcheck.sh`，新进程），无回退。

## 深度功能测试（§10.7，2026-10-07）— 空的 `if (current_water == 0) {}`

1 个房间的 `valid_leave()` 里有一行什么也不做的 `if (current_water == 0) {}`（编译警告 `Expression has no side effects`），删去，行为不变：`d/xingxiu/shanjiao.lpc`。

## 深度功能测试（§10.7，2026-10-07）— 村长的疗伤说明被截断

`d/newbie/npc/laocunzhang.lpc`：新手村长讲内功疗伤的那段 `msg`，`"…达到一定等级。\n\n" HIY;` 后面单独一行 `"    更多相关帮助请参阅帮助文件 help force\n\n" NOR;`——多余的 `;` 把最后一句截掉了，颜色也没有还原（`NOR` 在被丢掉的那句里）。接回去（`scripts/lpc_join_cut_strings.py`，现在也认带颜色宏的字符串）。HEAD 与工作树分别加载（新进程）通过。

## 深度功能测试（§10.7，2026-10-08）— 编译警告整理

`scripts/lpc_warnings.py hhsj --fix` 加 `scripts/lpc_fix_no_effect.py --apply`，共改动 2109 个 `.lpc` 和 50 个 `.h`（多为删去未用的局部变量）。HEAD 与工作树分别加载（新进程）：2031 -> 2031 通过，无回退；改过的头文件的 636 个包含者 614 -> 614 通过。启动时警告 14 -> 0；新进程登录（输入名字）正常。
手改：`adm/kernel/master.lpc` `direct_run_binary()` 的 `ob`、`vob` 只在 `#else`（BINARY_SUPPORT）里用到，声明挪进去；`adm/daemons/natured.lpc` 空语句 `lt[LT_MON];` 删去。护送任务杀手 `d/city/task2/shashou.lpc` 调用本库 namesd 没有的 `jap_name()`（三次加载一次失败）并把数组 id 再包一层，同 nitan6（KB 06 §7.237，`scripts/lpc_nitan_jap_name.py`）；修正后单独加载 6 次全过，探针 `new` 30 个 id 都正常。
（更正：本库没有任何 task2 以外的文件生成 `renzhi` 或发 `miling`，这个护送任务目前没接进游戏，上面的杀手修正是在休眠内容里。）

## 深度功能测试（§10.7，2026-10-08）— `.lpc` 后缀的定宽切片

`.c` 改名 `.lpc` 时只改了字符串没改切片宽度：`f[<2..] == ".lpc"` 拿两个字符比四个字符，永远不成立（`!=` 永远成立），按后缀筛文件、去后缀的代码因此从不运行或截成 `x.l`（KB 06 §7.238）。`scripts/lpc_lpc_suffix_slice.py --apply` 改了 9 处比较、0 处去后缀（如 `clone/npc/qingyun.lpc`）；改动的文件 HEAD 与工作树分别加载（新进程），无回退。
使命任务：`adm/daemons/taskd.lpc` `alloc_task()` 的 `room[<2..<1] != ".lpc"` 让每个房间都被拒，`rooms -= ({ room })` 又拿 `zone + 名字` 去减只有名字的列表，于是无限重抽，`taskd` 从来加载不起来——玩家的 `task`、`locate` 指令只显示“这里发现了臭虫”。改正切片和列表（列表空了就停）；真正走房间之后首次冷加载要 5 秒以上，`maximum evaluation cost` 提到 10000000（nt6 原本就是最大值）。新进程建人物后 `task` 列出使命物品、`locate` 可用；HEAD 两者都失败。

- 2026-10-10：`/kungfu/skill/sad-strike/tuo.lpc`、`/kungfu/skill/taiji-jian/jian.lpc`、`/kungfu/skill/wanjiandian/jian.lpc`、`/u/mud/skills/wudang/jian.lpc` 的技能判断用按位 `&` 连接两个比较（如 `tjss > 10000 & taoism > 10000`），改为逻辑 `&&`。两边都是 0/1 比较结果，行为不变，只是写法纠正。

- 2026-10-11：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 61 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 12 个，只在 #if 分支用的声明移进分支 6 个文件；改动 79 个文件，HEAD 与工作树各载入一次无回退（79 objects; HEAD PASS 79, tree PASS 79; regress 0; newly loading 0），这些文件的警告 116 -> 19。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查（批 3）

- `adm/daemons/combatd.lpc` 反击：`your_temp["guarding"];` 丢了 `= 0`（ES2 原版是 `set_temp("guarding", 0)`），一次防守姿态可无限次触发反击；补上 `= 0`。
- `clone/obj/genmap.lpc`/`traverser.lpc`：`DEBUG` 是空宏，调用处留下 `("text", n);`；改成空函数 `varargs void DEBUG(string fmt, mixed arg) {}`。
- `d/guiyun/jiuguan.lpc`（12 处）、`*/song/obj/bingfu.lpc`：`query_temp("cai_" + (i + 1, me) + "/name")` 是把 `me->query_temp(...)` 改写成 `query_temp(..., me)` 时括号放错，逗号表达式让键变成 `"cai_" + me + …`，酒馆菜单前移、兵符统军列表都读不到；改为 `query_temp("cai_" + (i + 1) + "/name", me)`。
- `d/death/qiao1.lpc`：`if (dir == "north") { /* … */ }` 只剩注释的空块，把 `if` 一起挪进注释（行为不变）。
- `d/dj/dj9.lpc`：`ob == me;` 应为 `ob = me;`，否则后面的 `if (ob == me)` 永远不成立，死因“挑战天威,最终身死道消”从不记录。
- `kungfu/skill/miaojia-jian/gan.lpc`、`zhai.lpc`：`string name() { HIY "…" NOR; }` 少了 `return`，招式名为 0；补 `return`。
- 改动的对象 HEAD 与工作区都能载入，无回退。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查（批 6）

- 补齐前几批漏掉的同码副本：`your_temp["guarding"];` 补 `= 0`（反击后清除防守姿态，含 `u/` 下的 combatd 拷贝）；`(: WEAPON_D, "query_action" :)` 改为 `(: call_other, WEAPON_D, "query_action" :)`（KB 04）；`mysql_d.lpc` 的空 `MSG` 宏改成空函数；`gigicook.lpc` 的 `arg == menu_list[0]` 改为 `=`。
- 改动文件：adm/daemons/mysql_d.lpc u/lonely/combatd.lpc u/redl/combatd.lpc 
- 改动的对象 HEAD 与工作区都能载入，无回退。

## 深度功能测试（§10.7，2026-10-12）：编译警告收尾

可编译文件的警告 **316 -> 0**（全库重扫：23246 个文件可编译）。内核与 nitan170911 逐字相同，先用 `scripts/lpc_twin_port.py adopt nitan170911 hhsj` 搬来同日 nitan170911 那一节的 104 个同码文件，再对本库自己的版本手改同样的根因。载入核对 5647 个对象（改动的、改过的头文件的包含者、`clone/`、`d/city`、`d/xiangyang`、`feature/`、`inherit/`、`adm/daemons/`、600 件玩家自制道具）：`5647 objects; HEAD PASS 5547, tree PASS 5547; regress 0; newly loading 0`。删除声明审计 0 处待看。

- **严重：F_DBASE 旁边的混入件读写 simul_efun 的共享 dbase**（详见 nitan170911 同日一节）。`include/dbase.h` 补上 F_DBASE 属性函数的原型，`feature/equip.lpc`、`itemmake.lpc`、`food`、`liquid`、`pill`、`alias`、`message`、`name`、`damage`、`dealer`、`banker`、`guarder`、`apprentice`、`unique`、`control`、`inherit/char/master.lpc` 都包含它；`npcsd.lpc`、`eval.lpc` 去掉包含。探针（新进程）：修正后 NPC `wield` 长剑 `query_temp("weapon")` 指向它、`equipped == "wielded"`，`wear` 写入 `armor`，自制道具 `query_autoload()` 返回 `"wielded"`、`is_weapon()` 为 1（修正前与 nitan170911 一样都是 0/`"kept"`）。
- 自制道具 autoload：itemmake 的 `query_autoload()`/`autoload()` 改名为 `query_itemmake_autoload()`/`itemmake_autoload()`，`item.lpc`、`combined.lpc` 先交给它；探针三种基类（STAFF/HANDS/THROWING + F_ITEMMAKE）与普通长剑、铁莲子的结果都和改前一致（itemmake 的逻辑照旧胜出）。
- `inherit/char/master.lpc` 开除弟子的逗号表达式、神木王鼎虫表、`xiang.lpc` 的 `remove()`、boss 任务 NPC 的 `WAIT_TIME`（各自的 60 生效）、幻境变量重复声明、`template/` 变量改名、`d/yixing/doc` 头文件守卫、宏 `#undef` 等，同 nitan170911。
- 本库自己的：`adm/daemons/chard1~3.lpc` 先 `#define HUMAN_RACE` 为 yao/mo 再定义为 human（后者生效），加 `#undef` 保持现状；`d/guanwai/bingdong.lpc` 的 BOOK 加 `#undef`；`combatd.lpc` 的 `def`/`armor` 挪进 `#ifdef`；`ji.lpc`、`d/u.lpc`、`d/hunduntian/npc/u.lpc` 注释里套的 `/*` 去掉；toolkit 删去 4 个重复继承 F_CLEAN_UP。

## 深度功能测试（§10.7，2026-10-12）：KB 05 §7.15 残留收尾（feature/save.lpc）

- 复查当天早些时候 dbase.h 原型一轮漏掉的混入件。`feature/action.lpc`、`condition.lpc`、`move.lpc` 在本库里**没有问题**：忙乱（`me->query_all_buff("avoid_busy")`）、中毒抗性（`this_object()->query_all_buff("avoid_poison")`）、移动时的 `this_object()->query("equipped")`、`env/brief`、`guardfor` 早就写成 `this_object()->` 或带物件参数的两参形式，没有一处裸单参 `query()`/`set()`（nitan6 的同名文件是裸调用，那里才需要 `#include <dbase.h>`），所以不加包含、不改。
- 真正漏掉的是 `feature/save.lpc`：它也被不带 F_DBASE 的守护进程继承，不能加原型；`restore_package()` 两处 `log_file("restore_package", query("id") + ...)` 是裸单参调用，读的是 simul_efun 的共享 dbase，日志里的玩家 id 恒为 `0`。改为 `this_object()->query("id")`（同 nitan6 提交 3264a2e14e1）。
- 探针（新进程，HEAD 与工作树各一次）：两个店小二，一个设 `apply/avoid_busy`=77、`apply/avoid_poison`=88，另一个读到 0，`start_busy(5)` 正常；长剑 `wield` 后移给另一个 NPC，原持有者 `weapon` 清空、`equipped` 清零——改前改后相同。带 F_DBASE+F_SAVE 的探针物件 `restore_package()` 遇到不存在的物件路径：改前日志 `0:/no/such/probefile`，改后 `probesv:/no/such/probefile`。
- 载入回退检查：继承 F_SAVE 的全部对象加 `clone/`、`d/city`、`feature/`、`inherit/`、`adm/daemons/`、`cmds/` 抽样，`2490 objects; HEAD PASS 2415, tree PASS 2415; regress 0; newly loading 0`（失败的 75 个 HEAD 同样失败），改动文件无编译警告；删除声明审计 0 处。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。20 个文件 25 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）；`x op= 浮点` 先把浮点转成整数再运算（系数小于 1 时 x 直接变 0），改为 `x = to_int(x op ...)`：`/clone/npc/walker.lpc`（`pot *=`）、`/clone/npc/walker.lpc`（`score *=`）、`/kungfu/class/generate/killed.lpc`（`exp *=`）、`/kungfu/class/generate/killed.lpc`（`pot *=`）、`/kungfu/class/generate/killed.lpc`（`weiwang *=`）、`/kungfu/class/generate/killed.lpc`（`score *=`）、`/kungfu/skill/yunv-xinfa/xiuxi2.lpc`（`xj_gain *=`）、`/kungfu/skill/yunv-xinfa/xiuxi2.lpc`（`xj_gain *=`）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。
- 2026-10-14（同一次重扫，手工部分）：
  - 36 个技能文件的 `int power_point()` 按性别、内功等级等分支返回 0.6、0.8、1.2、1.4 之类的浮点，经 `int` 返回被截断。本库没有代码调用这个函数，改成 `float` 返回值、保留原数值；`yunlong-*` 三个文件的第三个分支去掉了重扫时加的 `to_int`。
  - `inherit/room/hockshop.lpc` 当铺货物清单的售价 `value * rate / 100 * 9 / 10` 写明 `to_int()`（`rate` 是浮点）。
  - `adm/kernel/simul_efun/ntefun.lpc` 的 `y = sqrt(...)` 写明 `to_int()`。simul_efun 能载入。
  - `u/gigi/test/gigicook.lpc` 的 `arg == menu_list[0]` 改成赋值。
  - 改动的 251 个对象 HEAD 与工作树各载入一次，无回退（244 -> 244）。

- 2026-10-14：10 个文件把 `array` 单独当类型用（`array names;`），本驱动当成普通名字，报 `Illegal lvalue` 整份不编译；改为 `mixed *`，每个声明都带星号（`scripts/lpc_fix_array_type.py`）；17 个文件用了颜色宏（`HIW`、`NOR`）却没有 `#include <ansi.h>`（首个错误 `syntax error, unexpected L_STRING`）；开头补上（KB 04 §6.1、§6.3）。新编译出来的文件露出的警告一并清掉（删去未用局部变量，有返回值函数里的空 `return;` 改为 `return 0;`）。新进程比对 HEAD 与工作树：25 个对象，新增载入 21，回退 0。

## 负数伤害当作消耗（2026-10-15，KB 06 §7.241）

`receive_damage("neili", -52)`、`receive_damage("qi", -12)` 之类把 `add()` 的负数写进了 `receive_damage()`：本库 `feature/damage.lpc` 对负数伤害报错（或归零），练功/运功时报 `F_DAMAGE: 伤害值为负值` 或消耗失效。已改为正数伤害，内力/精力类改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py`）：`/kungfu/skill/pangen-cuojiefu`。

## 内力/精力当作伤害种类（2026-10-15，KB 06 §7.241 第二类）

本库 `feature/damage.lpc` 的 `receive_damage()` 不接受 `jingli`/`neili`/`force` 等种类，`me->receive_damage("jingli", 30)` 之类在练功、绝招、吸取时报 `F_DAMAGE: 伤害种类错误`。34 处改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py` 第二步）。


## 缺失的转世守护进程 `/adm/daemons/scbornd`（2026-10-15）

`SCBORN_D` 在 globals.h 中有定义，原始存档却只有 `help/scborn`，没有守护进程本身。绝招文件在每次施展时都调用 `SCBORN_D->valid_perform()`，`force.h` 的 `valid_public()` 调用 `valid_learn()`，天界入口和通天老仙调用 `check_data`/`check_data2`/`start_scborn`：全部报 `couldn't find object`。新增一个替身 `adm/daemons/scbornd.lpc`：对所有人回答“未曾转世”，转世本身仍不可进行（与存档一致），但上述调用不再报错。


## 去烦恼指 `qufannao-zhi`（2026-10-15）

该技能 `inherit F_DAMAGE`，其中 `query`/`query_temp` 的成员原型遮住了 simul_efun 的 `query(prop, ob)`，于是 `valid_learn`/`practice_skill` 报 `Undefined function called: query_temp`。改为 `me->query_temp(...)` 等直接调用。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。2 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。


## 东方故事/西游记体系的技能文件（2026-10-15，KB 06 §7.241 第三类）

这些 `kungfu/skill` 文件来自 gin/kee/sen/force 体系，本库人物只有 jing/qi/neili：`receive_damage("kee", 30)` 报 `伤害种类错误`，`query("force")` 永远为 0，技能学不了也练不了。按 kee→qi、gin/sen→jing、force→neili、max_force→max_neili、force_factor→jiali 改了属性名（`scripts/lpc_port_es_props.py`），共 5 个文件。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

另有 1 个文件（绝招、状态、物品、NPC 等，不限于 kungfu/skill）来自 gin/kee/sen/force 体系，同样按 kee→qi、gin/sen→jing、force→neili 改名（`scripts/lpc_port_es_props.py --any-file`）。


## 内力/上限当作伤害种类（补）（2026-10-15）

`victim->receive_wound("force", n, me)`（兵器吸内力）、`receive_damage("max_qi", random(100))`（走火入魔扣上限）等本库不接受的种类，1 处改为 `add(type, -N)`。

## 转码吃掉的引号（2026-10-15，KB 03）

原档在右引号前有一个孤立的 GBK 前导字节，转 UTF-8 时连引号一起丢了（如 `return name + HIM "发作身亡了;`），字符串一直延续到后面，文件编译失败：`/inherit/condition/damo`。补回引号（`scripts/lpc_fix_eaten_quote.py`）。其中 `/inherit/condition/damo.lpc` 不能编译时，所有 `damo_*`（达摩）中毒状态都载入失败。


## 摆摊状态的指令路径（2026-10-15）

`kungfu/condition/baitan.lpc` 调用 `/cmds/std/baitan.lpc`，指令实际在 `/cmds/usr/baitan.lpc`。已改正路径；本库摆摊指令用 `start_busy()`，目前没有地方施加这个状态，属于未接线的代码。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。6 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。


## 技能按另一门武功的等级取招（2026-10-15，KB 06 §7.243）

这些技能文件是从别的武功复制改名来的，`query_action()` 仍用原武功的等级查招式表：只会本技能的人等级为 0，取不到招，每次出招都报错。改为读本技能自己的等级（`scripts/lpc_fix_action_level.py`）：`canhe-zhi`、`chongling-jian`、`duoluoye-zhi`、`feifeng-bian`、`huashan-zhang`、`murong-jianfa`、`sougu-yingzhua`、`xuedao-daofa`。

## `find_player()` 只认在世界里的身体（2026-10-15，KB 07 §8.26）

simul_efun 的 `filter_player()` 加上 `environment(ob)`：注册中途断线留下的、不在任何房间的身体不再被当成玩家，两个以上时 `find_player()` 不会再报 `The player(<id>) has existed in the world.`（wllz3 实测过的问题）。本库若注册流程不会留下带玩家 uid 的身体，这一改动不改变行为。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`five_poison`→`five-poison`（`/clone/medicine/poison/redyao`、`/clone/medicine/poison/shenxiandao`、`/clone/medicine/poison/whiteyao`、`/clone/medicine/poison/wuxing`、`/clone/medicine/poison/yellowyao`）；`busi-shenglong`→`busi-shenlong`（`shenlong-dafa`）；`choushui-zhang`→`chousui-zhang`（`chousui-zhang`）；`cuhixiao-jifa`→`chuixiao-jifa`（`xiaoao-jianghu`）；`hengshan-jianfa`→`hengshan-jian`（`/d/henshan/tianquan-hole`）；`jiemie-zhua`→`jimie-zhua`（`huzhua-claw`）；`lenyue-shengong`→`lengyue-shengong`（`lengyue-shengong`）；`meiren-shanzhao`→`meiren-sanzhao`（`meiren-sanzhao/fengzi`）；`qianzhu-wandu`→`qianzhu-wandushou`（`/kungfu/class/emei/zh`）；`xiawuxiang`→`xiaowuxiang`（`jidao-shaqi`）；`yaowang-mishu`→`yaowang-miaoshu`（`yaowang-miaoshu`）。

## 技能名拼错：技能文件里拼错自己的名字（2026-10-15，KB 06 §7.249）

技能自己的文件（或它的绝招目录）里，`query_skill()` 读的是差一个字母的自己的名字，永远得 0：“基本功夫要高过本技能”之类的限制从不生效，按等级取招、计算伤害的那一项一直是 0。改为本技能的名字（`scripts/lpc_fix_skill_typo.py` 的 self 判据）：`xuanyuan-arror`→`xuanyuan-arrow`（`xuanyuan-arrow`）。

## 乾天一阳「聚精」用了未定义的 MIN（2026-10-15）

`qiantian-yiyang/jujing` 从书剑（sj）移植过来，用到 `MIN(...)`；书剑的 `globals.h` 定义了这个宏，本库没有，文件编译失败。在文件里补一个局部 `#define MIN(x, y)`，现在可以载入。

## 擒龙手「擒龙打」每次都报错（2026-10-15，KB 06 §7.246）

`qinlong-shou/qin` 要求空手施展，却在出招前执行 `wn = weapon->name();`：局部变量 `weapon` 从没赋值，`wn` 也没人用，每次使用都报 `Bad argument 1 to EFUN call_other()`。删去这一行和两个没用的局部变量。


## 地图数据库 mapdb 的空档防护（2026-10-15，KB 06 §7.250）

genmap 第一次载入时 `if (!restore()) save();` 会在地图建好之前写出只有文件头的 `data/npc/map.o`；mapdb 读它成功后 `map` 为 0，所有查询都对 0 取下标（nitan170911、shenzhou 等 10 个库就带着这样的文件）。没有 map.o 时 `query_random_room_path()` 又对空数组取下标。mapdb（`/clone/obj/mapdb.lpc`）加一个 `restore()`：读档后 `map` 不是映射就重置为 `([])`；地图为空时 `query_random_room_path()` 返回 0。


## 临济庄「幽冥桩」的两处笔误（2026-10-15，KB 06 §7.245、§7.250）

`linji-zhuang/youming`：`killer->querry(...)`、`me->querry(...)` 调用的是不存在的函数，永远得 0，恶人比值只按 PK 数算，改为 `query`；`visit_room()` 先拿 `range` 作判断、后从参数里取 `range`，判断时它还是 0，效果遇到没载入的房间就停，两行取值挪到前面。


## 柔云步法「柔云纵」有时报错（2026-10-15，KB 06 §7.251）

`rouyun-steps/zong` 随机把人送到三个房间之一：精、精力已经扣了，“乘云而去了”也说了，送不过去时人留在战斗里并报错。第三个是巫师的测试房 `/u/deaner/test1`，库里没有；改为 `/d/city/guangchang`（hy、jym 等库原本就用这个）。


## 秋林拾叶「随风而舞」成功时报错（2026-10-15，KB 06 §7.252）

`qiulin-shiye/wu` 把房间的出口映射当数组：`mapping *obb = query("exits", env)`，成功时 `me->move(obb[0])`，映射里没有键 0，移动到 0 报错（没有出口的房间则是对 0 取下标）。改为 yanhuangwuhun 一系的写法：从 `values(exits)` 里随机选一个出口。


## 存档读不出来：转码损坏（2026-10-15，KB 03 §4.4）

`/temp/login/s/sina.o`、`/temp/login/t/tiyan.o`、`/temp/user/s/sina.o`、`/temp/user/t/tiyan.o` 在转码时坏了：原档里孤立的 GBK 前导字节被 `iconv -c` 连同后面的引号一起丢掉，`restore_object()` 报 `Illegal mapping format`，读档的对象（玩家、留言板、信件、表情）从空白开始。按 raw/ 原档重新解码（孤立字节丢掉、引号保留），驱动核对全部能读回（`scripts/lpc_save_encoding.py --from-raw`、`scripts/lpc_save_restore_check.py`）。

## family 映射内联取下标（2026-10-15，KB 05 §7.30）

`ob->query("family")["master_name"]`、`me->query("family")["family_name"]`（泥潭式为 `query("family", ob)[...]`）直接对门派映射取下标：没有门派的人（新玩家、叛师者、大多数 NPC）在 NPC 的打招呼和问话、绝招的门派判断、房间的 `valid_leave` 里报 `Value being indexed is zero`，而不是得到拒绝。3 处（3 个文件）改为 dbase 路径查询 `query("family/master_name")`：有门派时值相同，没有时得 0；原有的判断照常生效（`scripts/lpc_fix_family_index.py`）。给映射赋值的写法未动。


## 存档读不出来：字符串里的换行、空行（2026-10-15，KB 03 §4.4）

`help/newsd.o`：字符串里有原样的换行（`save_object()` 存成 `\r`，`restore_object()` 逐行读，原样的换行让字符串收不了尾），或有空行（`Illegal file format`），读档的对象（留言板、NPC、玩家）从空白开始。换行改写成 `\r`、删去空行（`scripts/lpc_save_encoding.py --from-raw`），驱动核对全部能读回（`scripts/lpc_save_restore_check.py`）。

## 移进不存在的巫师房间（2026-10-15，KB 06 §7.251）

用完的物品、要“离开”的 NPC、掷在空中的兵器被移进巫师的工作室（`/u/aln/`、`/u/smallfish/`），本库没有这些房间。本库的 `move()` 用 `call_other(dest, "???")` 载入目的地，找不到文件就报 `call_other() couldn't find object`，后面的语句都不执行：药（人参，`clone/drug/cb_renshen`）吃下后药效已经生效，随后报错：`call_out("destroy", 31)` 没有排上，药一直留在身上，药效过去后可以再吃；婚礼最后一步（`d/suzhou/npc/meipo` 的 `last_marry`）先把月老送走，在这里报错：新人不会被送上花轿去迎宾楼，喜宴没有了。2 个文件改为移进本库的虚空房间 `VOID_OB`（`/clone/misc/void`），与原作把它们“停放”在巫师房间的用意相同（haiyang2 的维护者把月老送进 `/d/city/empty`，也是同样的做法）。


## 拜堂时请不来月老（2026-10-15）

苏州媒婆（`d/suzhou/npc/meipo`）和红娘（`adm/npc/hongniang`）拜堂时 `new("/d/suzhou/npc/yuelao")`，本库这个 NPC 放在 `d/ruzhou/npc/yuelao.lpc`（文件头仍写着旧路径，与 nitan3 等库的 `d/suzhou/npc/yuelao.lpc` 逐字节相同）：`new()` 得 0，`moon->move(room)` 报错，婚礼停在拜堂之前。两处都改为 ruzhou 的路径。媒婆从拜堂到送入花轿的整个流程在测试里走通。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

33 个文件、43 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/d/dali/npc/obj/zipao`、`/d/tls/obj/sengxie`、`/clone/armor/baihu-qiu.lpc`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 0 个，改后 2 个（2 个原来载入不了），没有退步；其余 31 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## 补回丢掉的基类宏（2026-10-18，KB 04 §6.13）

`inherit F_XXX;` 里的宏本库任何头文件都没有定义，报 `syntax error, unexpected L_IDENTIFIER, expecting L_STRING or '('`，整个对象载入不了；宏指向的基类文件本库其实有，别的库都把这个宏定义成同一个路径。在全局头文件 `include/globals.h` 里补上：`S_RING` → `/inherit/gems/ring`（11 个文件）、`F_GEMS` → `/feature/gems`（4 个文件）。（`scripts/lpc_restore_macros.py`）改后用 `lpcc` 逐个载入这些对象：15 个里 4 个通过，其余 11 个还有别的错误（`clone/gem/ring.lpc`：Fail to load object /clone/gem/ring.；`clone/gem/ring0.lpc`：Fail to load object /clone/gem/ring0.；`clone/gem/ring1.lpc`：Fail to load object /clone/gem/ring1.……）。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 63 个对象设了本库没有文件的武功（76 个名字，最多的是 `yijin-jing`、`qingyan-zhang`、`duanjia-jianfa`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：30 个里 16 个通过，其余 14 个停在别的错误上（`d/moon/npc/makongqun`：*Inherited file '/obj/npc/npcd' does not exist!；`d/shiliang/quest/npc/wenfangda`：*No program in object '/d/shiliang/quest/npc/wenfangda'!……）。（`scripts/lpc_guard_set_skill.py`）

## 补回本库没有的基类文件（2026-10-18，KB 04 §6.15）

下面这些基类本库没有，继承它们的对象（房间、NPC、物品）整批载入不了（`inherit XXX;` 的宏没定义，或者 `inherit "/std/…";` 的文件不在）。同系的库里有同名文件，两库有大量逐字节相同的文件（亲缘关系），所以从那边原样拷来，缺的宏补进全局头文件 `include/globals.h`：`/std/sserver`（宏 `SSERVER`）←shenmo，4 个对象继承它，抽样 1/4 载入；`/feature/ridding`（宏 `F_RIDDING`）←tianxiawuxue，1 个对象继承它，抽样 1/1 载入。每个基类补回后单独载入、再抽样载入使用它的对象，基类载不进来或者一个用户也载不进来的就撤掉（本库撤掉了它们，不再补）。（`scripts/lpc_restore_bases.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 115 处、47 个文件：`yijin-jing`→`yijinjing`（34 处）、`yunu-xinjing`→`yunv-xinjing`（20 处）、`yunu-shenfa`→`yunv-shenfa`（12 处）、`shaolin-shnfa`→`shaolin-shenfa`（7 处）、`shenzhao-jing`→`shenzhaojing`（6 处）、`mizong-huoquan`→`mizong-houquan`（5 处）、`jinyin-baiguzhao`→`jiuyin-baiguzhao`（4 处）、`paiyun-zhang`→`paiyunzhang`（4 处）等共 22 个名字。（`scripts/lpc_fix_skill_names.py`）

## set_name 的 id 参数传成字符串（2026-10-19，KB 06 §7.260）

`set_name("海口大碗", "bowl");` 把物品的 id 写成了字符串，本库的 `set_name(string name, string *id)` 要的是数组，驱动在编译时报 `Bad type for argument 2 of set_name ( string * vs string )`，整个物件载入不了；旧驱动不检查参数类型，字符串里照样找得到这个词，物品能用 id 称呼。改成 `({ "bowl" })`，共 1 个文件：`/d/baituo/npc/obj/bowl.lpc`。（`scripts/lpc_fix_set_name_id.py`）

## count_* 系列简单函数被条件编译挡掉（2026-10-19，KB 05 §7.15）

`adm/kernel/simul_efun/ntefun.lpc` 里的 `count_add/sub/mul/div/lt/gt/le/ge/eq` 整组被 `#ifdef __PACKAGE_ARITH_OPERATOR__` 包着，而且调用的是原版驱动才有的大数 efun `efun::count()`；这里两样都没有，整组函数编译不进 simul_efun，凡是调用它们的对象（`adm/daemons/gambled`、擂台鼓 `adm/npc/obj/drum3/4`、`adm/daemons/enterprised`、`quest/skybook/flagwar/flagd`）都报 `Undefined function count_lt` 载入不了。与 nitan6、nitan170911 的做法一致：去掉条件，包装函数改调 `db_compat.lpc` 里本地的 `count()`。同一批里 `quest/skybook/flagwar/flagd.lpc` 还照 nitan6 把 `ANSI_D->remove_ansi(...)`（本库没有 ANSI_D）改成 `remove_ansi(...)`，把 `reward_money *= 0.9` 改成 `to_int(reward_money * (0.9))`。

## 全局头文件丢了 4 个宏（2026-10-19，KB 04 §6.16）

`/include/globals.h` 里没有定义 `BOOK_D(x)`、`CENTER_OB`、`EXIT_SIZE`、`EXIT(n)`，用到它们的物件（名单里 4 个）编译时报 `Undefined variable`/`Undefined function`，整个物件载入不了（编译器在第一个未定义的名字上停下，后面的错误和警告都看不到）。同系的库在各自的头文件里都有这几行：照其中和本库共有文件最多的那个库，原样补到 `/include/globals.h` 最后一个 `#define` 之后，宏体里出现的路径在本库里都存在。补完后名单里有 1 个载入，其余还差别的东西。（`scripts/lpc_restore_defines.py`）

## kedian4 的 mapping ob（2026-10-19，KB 06 §7.266）

`d/city/kedian4.lpc`（客店，每隔两小时给老玩家发烟的 `give_cigarette()`）把循环变量 `ob` 声明成了 `mapping`，而 `foreach (ob in obs)` 里拿它当物件传给 `query("online_time", ob)`，驱动报 `Bad type for argument 2 of query ( object vs mapping )`，整个房间载入不了。改成 `object ob;`。

## die_reason 的参数个数（2026-10-19，KB 04 §6.10）

`/kungfu/condition/damo_luanqi.lpc`、`/kungfu/condition/damo_shangshen.lpc`、`/kungfu/condition/damo_zheyuan.lpc` 里的 `string die_reason()` 覆盖了基类的 `die_reason(string name)`，驱动报 `Number of arguments to 'die_reason' disagrees with previous definition`。补上 `varargs`，调用处不用改；改后与 HEAD 逐个物件对比载入，没有退步。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 两个斜杠开头的物件路径（2026-10-19，KB 06 §7.276）

1 个文件、1 处物件路径写成 `//…`（如 `carry_object("//clone/cloth/hic_cloth")`）：`/d/gaoli/npc/xiake.lpc`。当年的驱动不介意（路径先被规范化）；新驱动把原样的字符串交给 master 的 `valid_read()`，securityd 按 `//clone` 查目录，NPC 的 euid 没有权限，报 `Read access denied.`，NPC 载入不了。改成一个斜杠。

## 缺失的 unew()（2026-10-19，KB 06 §7.262）

本库的 NPC 和兵器在 `create()` 里调用 xkx 一系的模拟函数 `unew(file)`（`new()`，但遵守物件的 `unique` 上限），`/adm/kernel/simul_efun/object.lpc` 里没有，调用者全部报 `Undefined function unew`（以及接收结果那一行的 `Bad assignment ( object vs unknown )`），载入不了。补上和 dtsl、pkuxkx、sjpl2 等库一样的 `unew()`（文件不存在时返回 0，不会让调用者死在 `carry_object()` 里）。

## 丢失的 ARMOR_D(x)、BINGQI_D(x)（2026-10-19，KB 04 §6.16）

`include/globals.h` 没有 `ARMOR_D(x)`（`("/clone/armor/" + x)`）和 `BINGQI_D(x)`（`("/clone/weapon/" + x)`），用它们的 NPC 报 `Undefined function ARMOR_D` / `BINGQI_D`，载入不了。照同一系 19 个库里相同的定义补上（`scripts/lpc_restore_defines.py`）。

## 被注释吞掉的语句（2026-10-19，KB 06 §7.274）

- `/d/baituo/obj/lingshezhang.lpc`：`set("wposition", "/d/baituo/obj/lingshezhang.lpc")` 被 `//***** ADDED BY SCATTER *****` 注释吞掉

`scripts/lpc_fix_swallowed_statement.py` 把换行放回去。逐个载入与 HEAD 对比，没有退步。

## 标准整理轮（2026-10-19，`scripts/toolkit_fix.sh`）

本库在新驱动下重扫，机械修复：12 个未使用的局部变量，1 个文件的数组类型。修后与 HEAD 逐个物件对比载入，没有退步。

## d/ailao/yuanjiang 的 59 个房间（2026-10-19，KB 04 §6.18）

`d/ailao/yuanjiang/` 下 59 个房间开头是 `inherit __DIR__ "normal.lpc";`，也就是 `d/ailao/yuanjiang/normal.lpc`，档案里没有这个文件（有的是上一级的 `d/ailao/normal.lpc`，是这个区域的房间基类，`ailao.lpc` 继承的就是它）。编译扫描看不到这一类（`inherit` 的文件载入时才读），房间载入时报 `Inherited file '/d/ailao/yuanjiang/normal.lpc' does not exist!`。改成 `inherit "/d/ailao/normal";`，62 个对象（这 59 个房间加上目录里本来能载入的 3 个）全部载入，逐个与 HEAD 对比没有退步；`chuan71` 到 `chuan79` 能编译之后才露出的未用局部变量 `usr` 一并删掉。

## 手工收尾（2026-10-19，KB 04 §6.10）

- `maze/yanmen/npc/horse.lpc`：`inherit NPC; inherit F_RIDDING;`，NPC 一路带来 `feature/equip_liv.lpc` 的 `unequip(object ob, int ref status)`，`feature/ridding.lpc` 也有 `unequip()`（`unequip() inherited from both …`），驱动用了后继承的 ridding 那个；写出 `int unequip() { return ridding::unequip(); }`，行为不变（`scripts/lpc_name_winner.py`）。

逐个与 HEAD 对比载入，没有退步。

## 帮派文件里丢掉的引号（2026-10-19，KB 03 §4.6）

- `d/yixing/doc/set_bang.h` 第 82、84 行：两句帮主的话，最后半个字连同结尾的引号一起丢了（`…景仰之情<乱码>);`），下一行的开头引号把它闭合，后面的汉字被当成代码（`Illegal character 0xe8`），宜兴帮主 `d/yixing/npc/bangzhu.lpc` 从来载入不了。字串照 nt7 里完好的拷贝补回（`犹如滔滔江水连绵不绝。`、`帮主的敬仰犹如黄河泛滥一发不可收拾。`），引号补上。
- 同一文件第 45 行 `level = ceil( pow( … ) ) * 4 / 5;` 把浮点数存进 int，补 `to_int()`。

载入 `d/yixing/npc/` 的 bangzhu、biaotou、bangzhu2、cl_bei：HEAD 通过 3 个，现在通过 4 个（`bangzhu.lpc` 现在载入），没有退步。

## `x == "a" || "b"`：后面的字符串常量永远为真（2026-10-19，KB 06 §7.281）

`if (arg == "yuyou" || "yu you")` 里的 `"yu you"` 是非空字符串，永远为真，整个条件对任何 `arg` 都成立；作者要的是每个字符串都和变量比较。具体是：吃任何东西（`eat` 后面不管写什么）都会吃掉紫草；`valid_combo()` 对任何组合都返回真。在每个字符串前补上变量和运算符（`scripts/lpc_fix_literal_or.py`；`forrest2.lpc` 是 `dir == "north" && "south"`，手工改成 `(dir == "north" || dir == "south") && ...`）：`/clone/medicine/zicao.lpc`（1 处）、`/kungfu/skill/meinv-quan.lpc`（1 处）。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。具体是：`cross pubu`（穿瀑布）永远回答“你要往哪儿穿？”，瀑布后面的密室进不去。改动：`/adm/daemons/ward.lpc`（1 处）、`/d/baihuagu/yangfeng.h`（1 处）、`/d/gumu/liangong1.lpc`（1 处）、`/d/tiezhang/hhyuan-3.lpc`（1 处）、`/kungfu/skill/daoyu/jiu.lpc`（1 处）。另有 `/d/city/npc/majiang.lpc`（2 处） 的条件下面做的是别的事（`==` 和 `||` 也可能是本意），保持原样。

## `member_array('/', str)` 改为 `strsrch(str, "/")`：字符字面量的 member_array 按字节搜索（2026-10-20，KB 06 §7.283）

`member_array('/', str)` 里的 `'/'` 是整数，驱动按 UTF-8 **字节**搜索，返回字节偏移（带第三个参数时起点也是字节）；最新的 FluffOS（923cdbc0）在字符串里有非 ASCII 文字时，对每个调用点警告一次（`Warning: member_array(int, string) searches BYTES`）。而 `str[0..idx-1]` 按字符切，中文字符串会在错误的位置截断。改为 `strsrch(str, "/")`（找不到同样返回 -1，按字符计数；`scripts/lpc_fix_member_array_char.py`，JSON 编码器等少数几处手改）。改动：`/adm/daemons/vrm_server.lpc`（1 处）、`/cmds/arch/sameip.lpc`（1 处）、`/cmds/usr/mazemap.lpc`（1 处）、`/inherit/room/mine_field.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 31 处）。改动：`/adm/daemons/combatd.lpc`（5 处）、`/adm/daemons/competed.lpc`（2 处）、`/adm/daemons/intermud2_d.lpc`（2 处）、`/adm/daemons/xinruid.lpc`（2 处）、`/clone/game/mj.lpc`（3 处）、`/clone/game/mjlady3.lpc`（3 处）、`/clone/huoniao.lpc`（2 处）、`/cmds/wiz/roomlong.lpc`（1 处）、`/d/city/npc/matong.lpc`（3 处）、`/d/hangzhou/npc/meipo.lpc`（1 处）、`/d/jiaxing/npc/yang.lpc`（1 处）、`/d/yaowang/huichun/npc/zhanggui.lpc`（1 处） 等 16 个文件。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/kernel/simul_efun/object.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## 目录读出后的后缀截取宽度（2026-10-20，KB 06 §7.296）

`.c` 改名成 `.lpc` 之后，`get_dir("*.lpc")` 读出的文件名还按两个字符截取（`$1[0..<3]`）：`baguadao.lpc` 变成 `baguadao.l`，用它拼出的路径加载不到对象（故事、战场、事件、帮助、自造物品数据、召唤列表等）。改成 `[0..<5]`（`scripts/lpc_fix_getdir_strip.py`）。改动：`/adm/daemons/battlefieldd.lpc`（1 处）、`/adm/daemons/storyd.lpc`（1 处）、`/adm/kernel/importer.lpc`（1 处）、`/cmds/adm/refsum.lpc`（5 处）。

## `get_config(__MUD_PORT__)` 经旧版 `runtime_config.h` 得到字符串（2026-10-20，KB 06 §7.302）

本库的 `include/runtime_config.h` 是老 MudOS 的编号（整数设置从 15 起，本驱动从 256 起），`get_config(__MUD_PORT__)` 读到的是另一项设置（字符串），`(int)` 又只是编译期标注，于是 `socket_bind(fd, LOCAL_PORT())` 报 `Bad argument 2 to socket_bind()`，版本守护进程 `port = get_config(__MUD_PORT__) + VERSION_PORT` 是字符串相加。头文件自己的注释写明 `get_config(__MUD_PORT__) == __PORT__`，所以代码里的这个调用（连同外面的 `(int)` / `to_int()`）改成了驱动的预定义 `__PORT__`（`scripts/lpc_fix_mud_port.py`）。改动：`/cmds/arch/config.lpc`（1 处）、`/include/getconfig.h`（1 处）。

## `d/luoyang/obj/xiang.lpc`：`chuangli` 先 `explode(read_file("/log/PARTY"))`（2026-10-20，KB 06 §7.326）

关帝像的 `chuangli`（`kaibang`）指令在检查年龄和经验之前就读 `/log/PARTY`，那是运行中的 mud 记录已创立帮派的文件，全新的树里没有，`explode(0)` 报 `Bad argument 1 to explode()`：任何人敲 `chuangli 什么` 都是系统错误，而不是“你还嫩着呢”。改成 `file = read_file("/log/PARTY") || "";`（空串的 `explode` 是空数组）。xkx100utf8 和 nt7 是 gitlink 库（fluffos-org 上游），同一行在那里没有改。加载检查各 1/1。

## `mroom`（帮会房间生成）读不到 `dir_pre`（2026-10-21，KB 04 §6.16）

`cmds/bunch/mroom.lpc` 的 `valid_room_position()` 和建房流程用 `dir_pre` 当帮会目录前缀，库里没有任何头文件或变量声明它（`include/bunch.h` 只剩 `room_desc_l`、`max_exits`、`r_dir`、`vdirs`，整个语料里也没有 `dir_pre` 的定义），整个命令编译失败：`Undefined variable 'dir_pre'`。`adm/daemons/bunchd.lpc` 里 `BUNCH_HOME "/data/bunch/"`（`BUNCH_HOME + id + "/center.lpc"`，模板目录 `/d/room/bunch/` 复制到那里）和 `valid_room_position()` 的路径算术（前缀 `explode()` 三段、房间路径五段，差 2，返回第四段即帮会 id）对得上，所以在 `mroom.lpc` 里加 `#define dir_pre "/data/bunch/"`。nt6、nitan170911、nitan6、hhsj、xfbhh 的 `mroom.lpc` 逐字节相同，同一处改法；加载检查 HEAD 0、树 1。没有改：nt7（gitlink）同一文件；tianxia 的 `cmds/bangzhu/mroom.lpc` 用的是 `BANGHUI_DIR`，但那里的 `banghui_d` 自己就有类型错误和未声明的变量加载不了。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库有 2 个 NPC 文件写成空 `chat_msg`（例如 `/d/city/npc/lulixian.lpc`、`/maze/sand_dragon/npc/sand_dragon.lpc`），它们走的基类 `chat()` 本来已经检查了列表大小（或碰巧不出错），不受影响；下面这些文件各自带着一份没有检查的 `chat()`（NPC 里的副本、旧版基类），一并加上守卫。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/u/lonely/skybook/skybooknpc.lpc`、`/u/lonely/skybook14/skybooknpc.lpc`（共 2 个文件）。

## `blockade` / `recover`：`data/keep` 不存在，解封之后世界仍然锁着（2026-10-21，KB 06 §7.340）

管理员扫描里 `blockade` 报 `Error copying file from /data/user/f/fluffos.o to /data/keep/fluffos, Error: No such file or directory`，随后的 `recover` 在第一个 `cp()` 上死于 `*/data/keep/fluffos: lstat failed`，来不及执行最后的 `LOGIN_D->set_madlock(0)`：封锁解不开。`data/keep/` 是运行时目录，git 克隆里没有空目录。`blockade` 在第一次写之前 `if (file_size("/data/keep") != -2) mkdir("/data/keep");`（`mkdir()` 失败答 0，不抛错），`recover` 对没有保存档的玩家 `if (file_size(src) < 0) continue;`，其余照常恢复、照常解锁（`scripts/lpc_fix_keep_dir.py`，hy5 上实测：没有保存档时 `recover` 答“时空解封完毕”，`blockade` 建出 `data/keep` 并保存，`recover` 取回并删除）。改动（1 个文件）：`/cmds/arch/recovermud.lpc`。

## 不带参数的指令对 0 调用 efun：不在 wiz / adm 目录里的指令（2026-10-21，KB 06 §7.336）

指令敲成不带参数时，驱动把 0 传给字符串参数；下面的指令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`。它们在 `cmds/std`、`cmds/usr`、`cmds/bos`、`cmds/app` 这类目录里，上一轮的扫描只看巫师目录。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py --all-dirs` 在第一处使用参数的语句前加守卫：文件自带 `int help(object me)` 的，守卫是 `if (!arg) return help(me);`（`help()` 定义在 `main()` 之后的 1 个文件补了原型 `int help(object me);`，否则编译报 `Undefined function help`）；没有 `help()` 的是 `return notify_fail("…\n");`。改动（1 个文件，括号里是接住 0 的 efun）：`/cmds/std/look1.lpc`（`present`）。加载检查 HEAD 与工作树对照，没有退步。

## 任务分配 `quest`：按顺序找目标的备用循环用了 `living[j]`（2026-10-21，KB 06 §7.347）

`/feature/quest.lpc`：先随机挑目标（`j = random(sizeof(living))`），挑不中再“按顺序找”：`for (i = 0; i < sizeof(living); i++) if (check(living[j], ...)) { target = living[j]; break; }`。下标写成了 `j`（上一个循环最后一次的随机下标），备用循环把同一个 NPC 检查 `sizeof(living)` 遍，世界小的时候任务就分不出去。xkx100 的原文就是这样，派生库照抄。改成 `living[i]`。

## 华山密室 `stage3()`：重新登录那段被注释掉，`obj` 没赋值（2026-10-21，KB 06 §7.348）

练成之后 `obj = LOGIN_D->make_body(link_ob); ... exec(link_ob, me); destruct(me); ...` 整段在注释里，下面的 `obj->move(place); obj->write_prompt(); set(.., obj); obj->save();` 还在：属性已经加完，抛错发生在“恢复气血、存盘”之前。xkx100 系的库里这段是启用的；这里补 `obj = me;`，下面几句直接作用在玩家本人身上。改动：`/d/huashan/mishi.lpc`。

## hhsj 金灵巨兽 `die()`：广播里的 `ob->query("name")`（2026-10-21，KB 06 §7.348）

杀死金灵巨兽的人是 `enemy`，广播 “大道之音.<名字>干掉了金灵巨兽” 读的却是后面才赋值的 `ob`：每次被击杀都在 `::die()` 之前抛错。改成 `query("name", enemy)`。改动：`/d/hunduntian/npc/u.lpc`、`/d/u.lpc`。

## 追杀任务 `killer1.lpc`：奖励循环里的 `me` 从没赋值（2026-10-21，KB 06 §7.348）

黑衣人 `die()` 对每个在场的追杀者发经验和潜能，循环里写的是 `me->add("combat_exp", exp)`（nitan 系是 `addn("combat_exp", exp, me)`），`me` 要到循环之后才被 `find_player(owner)` 赋值：xkx100 系抛 `Bad argument 1 to call_other()`，nitan 系把奖励悄悄记到 0 上，追杀者什么也拿不到。循环里先 `me = obs[i];`。改动：`/clone/quest/killer1.lpc`。

## 拼错的 `call_out()` / `input_to()` 目标（KB 06 §7.349，2026-10-21）

计时器或输入提示给驱动的函数名和文件里定义的差一个字母；驱动对不存在的函数静默不理，所以对应的计时从来没有触发过。调用和配套的 `remove_call_out()` 改成已定义的拼法：`ruanweijia` / `yuxiao`：`return_to_zhang` → `return_to_huang`（携带者在战斗时的重试从不发生，宝物一直留在玩家手里）；张无忌：`destrory` → `destroy`。改动：`/clone/lonely/ruanweijia.lpc`、`/clone/lonely/yuxiao.lpc`、`/kungfu/class/mingjiao/zhangwuji.lpc`。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 42 条注册（30 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/adm/npc/beichou.lpc`（`do_join`）、`/adm/npc/ganjiang.lpc`（`do_merge`）、`/adm/npc/jierishizhe.lpc`（`do_vendor_list`）、`/adm/npc/referee.lpc`（`do_halt`）、`/clone/3.lpc`（`do_name`）、`/clone/dan.lpc`（`do_name`）、`/clone/dan0.lpc`（`do_name`）、`/clone/dan2.lpc`（`do_name`）、`/clone/dan6.lpc`（`do_name`）、`/clone/medicine/nostrum/gaoyao.lpc`（`do_eat`） 等共 30 个文件。最多的函数名：`do_name` 6 处、`do_bcheck` 3 处、`do_bcun` 3 处、`do_bqu` 3 处、`do_tiao` 3 处。没有动（读过）：`/d/lingyunku/npc/niefeng.lpc` 的 `do_show`（对象本身编译不过，登记留着，等对象能加载再处理）、`/quest/skybook/jiuyin/zhou.lpc` 的 `do_answer`（对象本身编译不过，登记留着，等对象能加载再处理）、`/quest/skybook/jiuyin/zhou.lpc` 的 `do_learn`（对象本身编译不过，登记留着，等对象能加载再处理）、`/quest/skybook/tlbb/murong-fu.lpc` 的 `do_lingwu`（对象本身编译不过，登记留着，等对象能加载再处理）。

## 基类的 `add_action` 登记：处理函数只在后代里定义，基类自己被加载时报错（2026-10-21，KB 06 §7.349）

房间、NPC、公告板这类基类，`init()` 里登记的 `add_action("函数", "动词")` 的函数只由继承它的后代定义；基类对象自己被直接加载（房间可以走进去、NPC 可以克隆）时，访客输入这个动词，驱动报 `*Function for verb 'x' not found.`（第一轮扫描把这些当成“有后代定义，是活的”放过了，`scripts/lpc_verify_handlers.py` 在基类对象上跑 `function_exists()` 才看出来）。登记前加 `if (function_exists("函数", this_object(), 1))`（第三个参数 1：默认 `function_exists()` 把 `protected` / `private` 函数当作没有定义），后代照常登记。共 1 处、1 个文件（`scripts/lpc_fix_dead_add_action.py --guard`）：`/d/yixing/npc/bangzhu.lpc`（`do_xue`）。

## 缺失物品的 `new()` / `carry_object()` 调用链加了保护（2026-10-22，KB 06 §7.73 补充）

`new(路径)->move(...);` / `carry_object(宏("x"))->wear();` 这类语句，路径指向的文件在这个压缩包里没有：`new()` 返回 0，`->move()` 在 0 上报 `Bad argument 1 to EFUN call_other()`。在 `create()` 里这个对象永远加载不了，在 `reset()` 里第一个缺失物品之后的刷新每次 reset 都被跳过。11 个文件里 13 处（`new`）改成 `{ object new_ob = new(路径); if (new_ob) new_ob->move(...); }`（`scripts/lpc_guard_carry_object.py --new`：路径按这个文件自己看到的宏解析，宏名冲突、虚拟对象路径一律跳过）。 对这 11 个改动文件做加载检查（HEAD 与工作区对比）：HEAD 能加载 10 个，现在 10 个（新增可加载 0 个，回归 0 个）。

## 调用了、但这个库自己的守护进程里没有的函数（2026-10-22，KB 06 §7.354）

`MACRO->函数()` 调用的函数在这个库的守护进程里不存在：`call_other()` 对不存在的函数不报错、只返回 0，所以这些功能（时间显示、昼夜事件、名字检查、价格文字……）一直没起作用。同一血统另一个库的同名守护进程里有这些函数，原文照抄到本库守护进程末尾（`scripts/lpc_port_function.py`；调用处传的参数个数、函数体用到的函数 / 全局变量 / 宏 / 字符串键都在本库里有，已核对；守护进程在 HEAD 和工作区都能加载，每个函数用固定参数各调用一次：HEAD 返回 0，现在返回正常的值）：`/adm/daemons/natured.lpc` ← aoxiangtianji：`outdoor_room_event()`（2 处调用）。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 还剩 8 个函数没有补（other 4, inquiry 4）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/adm/daemons/intermud2_d.lpc`:`receive_support_answer`、`/adm/daemons/npcsd.lpc`:`exert_function`、`/adm/daemons/npcsd.lpc`:`perform_action`、`/d/yixing/npc/bangzhu.lpc`:`ask_skills`、`/inherit/banghui/smith.lpc`:`is_money`、`/quest/skybook/jiuyin/zhou.lpc`:`questions`、`/quest/skybook/kuihua/linzhennan.lpc`:`test_dart`、`/quest/skybook/tlbb/liao-huo.lpc`:`ask_for_join`。

## 运行期目录 `log/nosave` 不存在，写日志的 `write_file()` 直接报错（2026-10-22，KB 03 §4.3 补充）

这个库的 142 个文件里有 238 处 `write_file("/log/nosave/...")` / `log_file("nosave/...")`（`static` 改 `nosave` 时连字符串里的日志路径一起改了，原来是 `log/static/`）：`nosave/using`、`nosave/dongtian`、`nosave/security` 等。压缩包和站点包里没有这个目录，`write_file()` 在目录不存在时抛 `*Wrong permissions for opening file /log/nosave/... for append. "No such file or directory"`，调用它的函数（杀人记录、重启记录、`call` 日志……）当场中断。把 `log/nosave/guilei` 记进 `scripts/wasm_keep_dirs.txt`（站点和 pristine 树都按它建空目录）；没有把字符串改回 `static`。证明（`scripts/lpcc_eval.py`，`catch(write_file("/log/nosave/ZZTEST", ...))`，fqyy2 / hy5 / bmxkx2001 的新进程）：补目录前报上面的错误，补后写成功。

## `log/` 下的日志子目录没有人建：写日志的 `write_file()` / `log_file()` 报错（2026-10-22，KB 06 §7.358）

这个库的代码往 `log/` 的 3 个子目录写日志：`log/job`（`kungfu/class/quanzhen/beidou.h`）、`log/money`（`d/suzhou/npc/meipo.lpc`）、`log/test`（`d/baituo/npc/shenu.lpc`）。压缩包、`git clone` 和站点包里都没有这些目录（本地启动没有写过它们，`gen_keep_dirs.py` 没记），`write_file()` 对不存在的目录抛 `*Wrong permissions for opening file /log/dlog/money for append. "No such file or directory"`，调用它的函数在写日志那一行中断，后面的奖励、标志、步骤都没有执行。本库的 `log_file()` 会自己建目录（实测，或读源码：nitan 系的 `assure_file()`），所以这里只记了直接用 `write_file()` / `save_object()` 写的目录。把 `log/job`、`log/money`、`log/test` 记进 `scripts/wasm_keep_dirs.txt`（`scripts/lpc_keep_log_dirs.py`；站点和 pristine 树按它建空目录）。证明（`scripts/lpcc_eval.py`，在 `/adm/daemons` 这类目录下的求值对象里写 `/log/zzdirprobe/...`，新进程）见 KB 06 §7.358 的实测表。

## `(: 函数名 :)` 指针指向本库没有的函数：只含这个指针的行加了注释（2026-10-22，KB 06 §7.355 补充）

`inquiry` / `item_desc` / `chat_msg*` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：用到时（`ask`、`look`、NPC 闲聊）驱动抛 `*Undefined lfun pointer called: 函数名`，这一拍心跳的后半段被跳过。这些函数没有可以补回的来源（别的库同一路径的文件里没有，或者它还要用本库没有的东西），所以 1 个文件里 2 行只含这个指针的行（`"武功": (: ask_skills :),` `"skills": (: ask_skills :),`）加了注释，原文保留并写明原因，这一项当作没有这个话题 / 物品 / 闲聊条目（`scripts/lpc_fix_dangling_lfun.py`；`#include` 的文件在库里缺失的对象、指针不在整行上的写法没动）。 前提（`function_exists()`）和加载检查（HEAD 与工作区对比，本库改动的 `.lpc` 文件）的结果见 KB 06 §7.355：没有一个回归。

## 汉字按字节切片的老写法没有换成按字符：改法名 `"澄" + name[2..3]`、辈分判断 `name[0..1] == "澄"` 等 36 处（2026-10-22，KB 06 §7.360）

原档按字节算字符串区间（一个汉字 2 字节）：`name[2..3]` 是名字的第二个字，`name[0..1] == "澄"` 问名字是不是以「澄」开头。转成 UTF-8 之后，这个驱动的区间和 `strlen()` 都按字符算（`strlen("澄观")` 是 2，`"澄观"[0..1]` 是两个字），老算术原样留着、意思全变：拜入少林 / 武当 / 峨嵋等派的玩家被改成错误的法名（二字名 `张三` 变成一个字的 `澄`，更长的名字取到第三个字）；各派掌门的辈分判断（`name[0..1] == "澄"`）永远不成立；NPC 的称呼和提示里取到两个字而不是一个字。

本库 36 处（26 个文件）：拼名字的赋值 22 处、与汉字常量比较 13 处、`to_chinese()[..]` 1 处。例：`name[2..3]` → `name[1..1]`（`/kungfu/class/emei/fengling.lpc:136`）；`name[0..1]` → `name[0..0]`（`/kungfu/class/emei/tobebonze.h:39`）；`name[4..5]` → `name[2..2]`（`/kungfu/class/quanzhen/chu.h:69`）。`scripts/lpc_fix_gbk_slice.py` 把下标按字符重算（社区的 UTF-8 版 `xkx100utf8` 里就是同样的写法，作对照）；没有改的：截断（`name = name[0..7]`，现在最多 8 个字，只是放宽）、ASCII 的区间（`fname[0..3] == "room"`、`ctime(time())[4..19]`）和上下文看不出是汉字的区间。证明（`scripts/lpcc_eval.py`，bixiecanyang；其余各库是同一份文本）：让澄字辈掌门 `attempt_apprentice()` 一个名叫「张三」的访客，HEAD 的法名是 `慧`，改后是 `慧三`；抽样 28 个库的 HEAD / 工作树加载对比 0 退步。工具不幂等（`[0..3]` 折半得 `[0..1]`，又是对齐区间），改过的文件记在 `scripts/gbk_slice_converted.txt`，不要重跑。

## 全局头文件里的宏，`carry_object` 守卫以前看不见：41 处（2026-10-22，KB 06 §7.361）

`config.fluffos` 的 `global include file` 会被驱动塞进每个对象，文件里没有写 `#include` 也能用 `ARMOR_D("shoes")` / `BINGQI_D("langya-bang")` 这类宏；`lpc_guard_carry_object.py` 的宏表只读文件自己写出来的 `#include`，认不出它们，第 46 批 `--macro` 把这些行整个跳过了——NPC 在 `create()` 里 `carry_object(ARMOR_D("shoes"))->wear()`，文件不存在，`new()` 答 0，`->wear()` 抛 `Bad argument 1 to EFUN call_other()`，NPC 加载不了。宏表现在加上全局头文件；本库 41 处改成守卫块（缺文件就不穿，文件回来照旧穿）。证明（HEAD / 工作树加载对比，只含改过的 `.lpc`）：HEAD 加载失败的对象里有 13 个现在能加载，0 退步（quest11 的镖师、金蛇、九阴、葵花、天龙八部各路 NPC 等）。其余仍失败的文件失败在别的原因（`Unable to find the inherited function`、`Undefined variable 'RNAME_D'`），不属于这一类。

## 长度检查按字节写，旁边的提示按汉字写：14 处（2026-10-22，KB 06 §7.362）

老档的 `strlen()` 数字节（一个汉字 2 字节），转成 UTF-8 后它数字符：提示写「必须是 2 到 6 个中文字」的检查还是 `strlen(name) < 4 || strlen(name) > 12`，于是两三个字的房名、帮会名、群名、聊天室名、称号被提示自己说允许的那句话拒绝，上限却是提示的两倍；留言板的标题检查 `i < 4 || i > 24 || i % 2` 还会拒绝所有奇数个字的标题（`post 你好吗`）。本库 14 处（7 个文件）：`if ((strlen(name) < 4) || (strlen(name) > 12)) {`（`/adm/npc/luban.lpc:1770`）；`if ((strlen(name) < 2) || (strlen(name) > 10)) {`（`/d/city/npc/petseller.lpc:184`）。`scripts/lpc_fix_strlen_gate.py` 以提示为准：条件里每个 `strlen` 门槛都恰是提示所说数字的两倍才折半，存长度的变量（`i = strlen(arg);`）的门槛和 `|| i % 2` 奇偶项、其后循环的 `i % 2 == 0 &&` 一并处理；提示里有英文 / 字母 / 字节的不动。证明（`scripts/lpcc_eval.py`，bxsj 的留言板，求值对象继承 NPC 并重写 `edit()` 记录调用，`command("post 标题")`）：HEAD 拒绝「你好」和「你好吗」、放行 23 个字的标题；改后接受前两个、拒绝第三个；shenmo 的 `named.lpc invalid_new_name("张三")`：HEAD 回 `名字只能是2-4个中文字。`，改后回 0。抽样 24 + 15 个库的 HEAD / 工作树加载对比 0 退步。
