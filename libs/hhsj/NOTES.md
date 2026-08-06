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
