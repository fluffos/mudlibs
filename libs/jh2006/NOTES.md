
## WASM 修复摘要（迁移自 meta.json 的 group_note）

ES2/金庸血统 mudlib（Annihilator/书剑衍生），游戏内标题为"江湖2005/江湖2006"（书剑主题）。修复的 bug：（1）adm/daemons/securityd.lpc 的 valid_read() 里经典的 §7.59 this_player() 顶替 root 身份 bug——开机时立刻就会崩溃报"*Read access denied."，出现在 logind.lpc 的 gb_big5() 第一次惰性编译 BAN_D->is_banned() 的时候，英文名字提示根本还没出现；已仿照既有模式，把 func=="load_object"/"include" 排除在 this_player() 覆盖之外来修复；（2）adm/daemons/logind.lpc 里经典的 §8.1 GBK 字节区间 is_chinese() bug 加上 check_legal_name() 字节数没减半的长度界限（4/8 字符，i%2 门槛→2/4 字符）；（3）adm/daemons/commandd.lpc 的 rehash() 里经典的 §8.3b 死指令表 sscanf——"%s.c$" 在改名成 .lpc 之后再也匹配不到任何东西，导致整个指令表变成空的；look/quit 碰巧还能用（是靠别处的 add_action 定义或者驱动内建），但包括查看状态用的指令（stscore，不是 score——这份档案不用"score"这个词）在内的其它所有指令都会落到"什么？"，直到修好为止。管理员账号（fluffos/Mud2026Pass）通过真实注册流程 + adm/etc/wizlist 播种，游戏内"您目前的权限：(admin)"显示确认生效（自动带到巫师休息室）。完整的注册→look→stscore→quit 流程在排版格式化前后各验证过一次，用的是真实中文名字——注意这份档案的注册顺序是 id→y/N 确认→密码→确认密码→中文名字→天赋数值→性别，不是其它档案更常见的 id→确认→中文名字→密码那种顺序。

## §10.7 深度功能测试（本次新增）

此前只做过注册→look→stscore→quit 的浅层验证。本次用管理员 `fluffos`
和一个全新普通角色 `tester` 实际走通了注册→look/i/stscore→武馆内移
动→沙袋练功的流程，并在源码层面逐一核对了 AGENTS.md 里已知的 bug
类别。

### 修复：d/death/gate.lpc 的 §7.68 复活软锁

`run(object ob)` 原代码 `if (!ob || !present(ob)) return;` 把"鬼魂对
象已经不存在了"和"鬼魂此刻只是暂时不在这个房间里"混为一谈，一旦判
定瞬间鬼魂碰巧不在场就永久放弃后续引导（送去 `gateway`/`mpting`/
`pusadian`），把鬼魂永久卡在鬼门关。按标准修法拆开：`!ob` 才是真正
放弃，`!present` 改为 1 秒后重试。已用管理员 `update` 指令热编译验
证无编译错误；受限于本次时间和城门 NPC（见下）没能实际找到活的怪物
触发真实死亡，未做端到端的活体复活验证——但这个修法和本项目里已经
反复验证过几十次的同一形状完全一致，可信度很高。

### 检查、确认不适用的已知 bug 类别

- §8.9 食物/饮水年龄检查错对象：本档案的 `stscore` 面板根本没有食
  物/饮水这两项资源，`logind.lpc` 里也搜不到 `ob->query("age")` 这
  种模式，不适用。
- §7.5 securd.lpc 的 file_size ACL 误拒（AGENTS.md 新增变体，上次
  在 hy2002 发现）：`adm/daemons/securityd.lpc` 的 `valid_read()`
  已经显式 `switch(func) { case "file_size": case "stat": return 1;
  }`，本来就放行，不适用。
- §7.78 CHARACTER 的 F_* 混入档缺 F_DBASE inherit：`inherit/char/
  char.lpc` 是和 shujian3/hy2002 完全相同形状的 ES2 结构（同一个
  `feature/dbase.lpc`），这两个同宗档案都已经用真实战斗测试排除过
  这个 bug（裸 set/query 实际写入了真正的 dbase），本次时间关系未
  重复验证，留给未来针对这份档案或其手足 `sjplgfjxb`/`sjplii` 的
  后续 pass。

### 一个不是 bug 的测试方法论坑：连线后不主动打印任何东西 + tmux 中文乱码

`logind.lpc` 的 `logon()` 只 `input_to("gb_big5", ob)` 注册回调，自
己不 `write()` 任何东西——欢迎横幅和"您的英文名字"提示都是在
`gb_big5()`**回调**里才打印的，也就是说这份档案要求连线后先随便送一
行（哪怕是空行）触发第一次回调，才会看到任何东西。用裸 socket 或
`tmux_mud.sh` 的 `read`（不先 `send`）会一直卡着直到驱动自己的 30
秒 `time_check()` 超时断线（"您花在连线进入手续的时间太久了"），一
度以为是驱动挂死，实际上只是没有先送空行。另外：本档案的出口键是
"方向-地点全名"这种复合字符串（如"西-小石路"，不是单独的"西"或
"west"）——用 `tmux_mud.sh` 送这类中文复合字符串偶尔会被 `tmux
send-keys -l` 弄乱（已知限制，见 memory），改用 `mudclient.py` 直连
后确认输入完全正常、移动指令本身没有问题。

### 未能完成的部分（诚实记录，非"未发现"）

新角色离开武馆的正常门槛是 `combat_exp >= 3000` 且完成馆内的拜别仪
式（`d/wuguan/menlang.lpc` 的 `valid_leave()`），本次时间关系没有练
到这个门槛；改用管理员账号 `goto` 到武馆大门外（`/d/xiangyang/
damen`）试图找一个可以安全测试战斗/死亡的目标，但该房间 `objects`
里唯一挂载的 `npc/menwei`（武馆门卫）在两次不同别名尝试下都返回"这
里没有这个人"——没有确认是编译失败还是别的原因，未深入排查。因此本
次没有做成活体的战斗/死亡/复活验证，`gate.lpc` 的修复只做到编译层
面确认，记录在案供未来 pass 补做。


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

## Deep functional test round two (2026-08-14)

Independently re-verified against current code rather than trusting the
round-one writeup above. All 3 prior fixes confirmed still present. Found
and fixed a real, 100%-reproducible §7.90-class eval-cost crash — this
one hit `enter_world()` itself and, because it left the admin character
with no environment, cascaded into a SECOND crash at `quit.lpc`'s
`message()` call, which looked like a new, unrelated bug at first.

### New fix: §7.90-class eval-cost abort during `enter_world()` — root cause of a second, seemingly-unrelated `quit.lpc` crash

First admin login this pass never printed a room description at all —
went straight from the password prompt to a bare `>` prompt, with
`update`/`stscore` both still working (command dispatch was fine) but
`quit` crashed: `*Bad argument 3 to EFUN message()` at `cmds/usr/
quit.lpc:113` (`message("system", ..., environment(me), me)`).
`work/log/debug.log` showed the actual root cause a few lines earlier:
`Eval interrupted: object clone/user/user#2 cost limit reached, limit:
700000 usec` during `enter_world()` itself (`adm/daemons/updated.lpc`'s
`create()` → `cmds/arch/gift.lpc`'s `create()` → `restore()`) — the
abort happened before `enter_world()` ever `move()`d the character into
`巫师休息室`, leaving `environment(me)` permanently `0` for the rest of
that session, which is exactly why the LATER `quit` crashed on an
unrelated-looking line. Fixed with the established remedy:
`config.fluffos`'s `maximum evaluation cost : 700000` → `5000000`.
Verified: fresh reboot, first login landed cleanly in `巫师休息室` (the
real starting room, not silently void), and the identical `quit` that
crashed before now completes cleanly.

### New fix: `cmds/imm/update.lpc` — the same `present(environment(me))` crash class, a third path variant

This lib's wizard reload command lives at `cmds/imm/update.lpc` (not
`cmds/wiz/` or `cmds/adm/`, the two path variants already found and
fixed on other libs this session) — same vulnerable shape, same fix.
Finding this led to a corpus-wide check: 21 more libs share this exact
path, fixed separately (see the dedicated `corpus sweep:
cmds/imm/update.lpc` commit). AGENTS.md §7.106 updated to note all three
known path variants.

### New fix: `adm/simul_efun/file.lpc`'s `cat()` had no null-guard

Standard proactive hardening; `log_file()` already correctly delegates
to `LOG_D->log_file()`, which already calls `assure_file()`.

### Considered and rejected: `adm/single/master.lpc`'s `log_error()` missing `assure_file()`

Unlike `logd.lpc`'s `log_file()`, the real master file's `log_error()`
writes directly with no `assure_file()` guard. Initially added one, then
reverted: `log_error()` can fire during the simul_efun object's OWN
compile (the function explicitly guards its `file_owner()` call with
`find_object(SIMUL_EFUN_OB)` for exactly this reason), at which point
`assure_file()` — itself a simul_efun — might not be callable yet,
making the "fix" a plausible NEW crash rather than a safe hardening.
The practical risk is low anyway (`work/log/` already exists as a
tracked directory, and the player-facing broadcast is already
commented out, so no §7.10-class leak risk either) — left as-is rather
than risk an unverified speculative change.

### Re-verified: all 3 round-one fixes still hold

- **`securityd.lpc`'s `valid_read()` `this_player()` override
  exemption**: code-confirmed `func != "load_object" && func !=
  "include"` still present. Live-confirmed indirectly — the driver
  booted and the very first lazy compile (`gb_big5()`'s `BAN_D->
  is_banned()` call) didn't crash, which is exactly what this fix
  prevents.
- **`is_chinese()`/`check_legal_name()` byte-length fix**: code-
  confirmed `strlen(name)` bounds check uses the corrected `i < 2 || i
  > 4` codepoint range (not the old byte-doubled 4/8 range).
- **`commandd.lpc`'s `rehash()` dead `.c$` pattern fix**: code-confirmed
  `sscanf(cmds[i] + "$", "%s.lpc$", cmds[i])` present. Live-confirmed:
  `stscore` (which would show "什么？" if the command table were still
  empty) rendered the full stat card correctly, on both the pre-fix and
  post-fix eval-cost sessions alike.

### Verification method

Booted native `build-debug` driver, admin login (`fluffos`/
`Mud2026Pass`) — this lib's login flow requires sending a blank line
first to trigger the banner (`logon()` only registers an `input_to`
callback, doesn't `write()` anything itself — a documented test-
methodology note from round one, still holds). `update /cmds/imm/
update` and `stscore` as privileged-action/command-table checks. Two
full rapid reconnects post-fix, both clean. Driver killed by exact PID
after each reboot (three total: initial boot where the crash was found,
one aborted reconnect during the config edit, clean reboot for
verification); incidental `fluffos.o` save-timestamp churn reverted
before commit.

### Files modified this pass

- `config.fluffos` — §7.90 fix (`maximum evaluation cost` 700000 →
  5000000).
- `work/cmds/imm/update.lpc` — `environment(me)` null-check (§7.106
  path variant).
- `work/adm/simul_efun/file.lpc` — `cat()` null-guard.

## §7.100 sub-threshold instance (2026-08-20)

Found during the §7.100 tail-sweep (below the original 166-lib survey's
>=100-occurrence threshold, never checked). Same lineage/shape as
`bxsj`/`sjecl`/`sjtx2`/`shujian2008`/`shujian3` (shared
`data/group/groom/*.lpc` cluster), but a different room set: 15 live
`replace_program(ROOM);` occurrences (`data/group/groom/*.lpc`,
`d/city/dayuan.lpc`, `d/mr/hc2.lpc`/`hc3.lpc`/`hc4.lpc`,
`d/kunlun/lang2.lpc`). No roommaker.lpc factory-bug variant. Verified
via a clean native driver boot (zero new `debug.log` errors, port
listening, killed by exact PID after ~8s).

## Round four (2026-08-20): `menwei` mystery solved, first-ever live combat/death/resurrection, §7.78 confirmed, §7.112 found and fixed

Prior rounds never got past the `combat_exp >= 3000` starting-hall gate and
were blocked by an unexplained "这里没有这个人" (no such person here) when
trying to interact with the one NPC (`npc/menwei`) at the hall's outer gate
room (`/d/xiangyang/damen`). Root-caused and resolved this pass, then used
the fixed NPC's room to reach a real live death/resurrection cycle for the
first time in this lib's testing history.

### Root cause of the `menwei` mystery: a real compile error, not a wrong alias

`d/wuguan/npc/menwei.lpc:463` had a stray full-width Chinese period (`。`)
placed OUTSIDE a string literal, right before an orphaned `\n`:
```lpc
// BEFORE (byte-for-byte, confirmed via python3 repr()):
message_vision( sprintf(HIW "武馆门卫交给$N一块武馆令牌"。\n" NOR), me);
```
The lexer chokes on the individual UTF-8 bytes of the stray `。`
(`Illegal character 0xe3`/`0x80`/`0x82`), then chokes again on the bare
`\n` outside a string, cascading into a second, unrelated-looking error at
line 467 (`$var illegal outside of function pointer`) from the resulting
string/quote misalignment. **This is a genuine compile error that has
blocked `menwei.lpc` from compiling at all, apparently since this file was
last touched** — confirmed live: a fresh `goto /d/xiangyang/damen` on an
unpatched driver throws `*No program in object '/d/wuguan/npc/menwei'!`
uncaught from inside `d/xiangyang/damen.lpc`'s own `create()` (which
`new()`s every entry in its `objects` mapping during `setup()`), which
means **the entire `/d/xiangyang/damen` room fails to load, not just the
NPC** — and this room is a normal, ungated city street any player can walk
through on the way into or out of the wuguan district, not an
admin-test-only path. Fixed by moving the closing quote to the correct
position:
```lpc
// AFTER:
message_vision( sprintf(HIW "武馆门卫交给$N一块武馆令牌。\n" NOR), me);
```
Live-verified: `update /d/wuguan/npc/menwei` recompiles clean, and a fresh
`goto` (after also `update`-ing the room object, since the room's earlier
crashed instance stayed resident in a half-initialized state until forced
to reload — a red herring worth remembering: after a compile-error fix,
force-reload the ROOM too, not just the fixed file, or a stale broken
instance can persist and make the fix look like it didn't work) loads
`武馆门卫(Men wei)` into the room correctly, responds to `look`/`ask`, and
a completely fresh driver boot from scratch compiles this file with zero
errors and the NPC is present and interactive on the very first visit.

### First-ever live combat → death → resurrection cycle

Registered a fresh throwaway character (`testnine`, 测武生), used the
admin `summon` command to bring it (bypassing the hall's exit gate, which
only applies to normal `valid_leave()` walking) to `/d/xiangyang/eroad1`
(`/d/xiangyang/damen` itself has `no_fight` set, so combat had to happen
one room over) alongside a wandering beggar-sect NPC
(`kungfu/class/gaibang/qigai.lpc`, `combat_exp` ~43000+ vs. the fresh
character's 0). `kill qigai` produced a fully real combat sequence
(genuine attack/dodge/damage exchange, not an admin-forced kill) ending in
death, correct routing through `d/death/gate.lpc` → `d/death/gateway.lpc`
(阎罗大殿) or `mpting.lpc` (孟婆亭, random 50/50 per `gate.lpc`'s `run()`),
and — after the `death_stage()` chain completed — full resurrection back
into `START_ROOM` (武馆前院, since the test character never left the hall
proper), HP/qi/jing fully restored, `is_ghost()` cleared, and the game
auto-saved cleanly. **Zero debug.log errors or crashes anywhere in this
cycle**, confirmed by diffing `log/debug.log` against a pre-test baseline.
This is the first time this specific end-to-end path has been verified
live on this lib across all four testing rounds.

### New bug found and fixed: §7.112-class `init()`/`call_out()` duplication in `d/death/npc/death.h`

While chasing the death cycle, found that `mengpo.lpc`, `yanluo.lpc`, and
`pusa.lpc` all `#include "d/death/npc/death.h"`, a shared header defining
`init()`/`death_stage()` for exactly the reincarnation-desk NPC shape
AGENTS.md §7.112 describes — an unconditional `call_out("death_stage", 90,
me, 0)` in `init()` with no re-entry guard, in a lib whose
`clone/user/user.lpc::reconnect()` unconditionally calls
`enable_commands()` (confirmed: `adm/daemons/logind.lpc`'s driver-invoked
`reconnect()` calls `user->reconnect()` unconditionally on both netdead-
reconnect branches). Every one of the earlier §7.112 corpus sweeps missed
this lib — it was never on either wave's batch list. **This is a real,
live, wide-reaching bug**: any player who is a ghost in 阎罗大殿/孟婆亭/
菩萨殿 and reconnects even once (a routine event, not an edge case) gets a
second, independent `death_stage()` `call_out` chain stacked on the first,
which can double-apply the death penalty or race-misroute the
reincarnation.

Fixed with the project's established minimal fix shape — a
`death_stage_active` per-victim temp-flag guard set in `init()` and
cleared at every exit point of `death_stage()` — deliberately NOT
importing the extra `special_poison`/`special_die`/`no_fight` divergences
found in sibling libs' (`bxsj`, `shujian3`) later-evolved copies of this
same file, since those are unrelated feature additions this lib's own
code never references. Live-verified with the project's established
`callouts death_stage` technique: put `testnine` into `阎罗大殿` as a
ghost, confirmed exactly one `death_stage` call_out pending via
`callouts death_stage` (as admin), forced an explicit reconnect
("重新连线完毕"), and re-checked — still exactly one call_out, confirming
the guard works. Let the chain run to completion and confirmed full,
clean resurrection.

`d/death/npc/wgargoyle.lpc`/`bgargoyle.lpc` in this lib are plain
decorative gargoyle NPCs with NO `death.h` include and no `call_out` at
all — not vulnerable, don't need the same fix. Not corpus-swept this pass
(single-lib fix only, since it was found via this lib's own testing, not
a dedicated sweep) — worth checking sibling libs sharing this exact
`data/group/groom` lineage (`bxsj`, `sjecl`, `sjtx2`, `shujian2008`,
`shujian3`) for whether their divergent `death.h` copies already carry
this guard (spot-checked `bxsj` and `shujian3` while looking for a
reference fix shape — both already have it) or need it independently
checked against their own `enable_commands()`-on-reconnect behavior.

### §7.78 F_DBASE: confirmed live via real bare `set`/`query`/`delete`

Used the admin wizard `call` command (`call me->set("test_dbase_marker",
424242)` / `call me->query(...)` / `call me->delete(...)`) directly on the
admin's own `char.lpc`-derived player object — genuinely bare calls, not
wrapped through any other function. Value round-tripped correctly across
an explicit `save`, full disconnect, and reconnect (new object instance,
confirmed via a different `#N` clone id in the `%O` dump before and
after), and `delete()` correctly zeroed it back out on a second
disconnect/reconnect cycle. **F_DBASE is confirmed genuinely working on
this lib**, not just inherited-by-assumption from a sibling lib as round
one left it. Test marker was deleted before the final save; no residue in
`git diff` on `data/user/f/fluffos.o`.

### Sect apprenticeship: works correctly

`bai tan` (against a non-sect NPC, 冯坦, the wuguan instructor) correctly
rejected with "既不属於任何门派，也没有开山立派，不能拜师" (matches
`cmds/skill/apprentice.lpc`'s `family` mapping check — not a bug, reasoned
rejection). `bai yue` at 华山正气堂 against 岳不群 (`d/huashan/npc/
yuebuqun.lpc`, which does `create_family("华山派", 13, "掌门")`) succeeded
cleanly: "岳不群决定收你为弟子" + kowtow message + "恭喜您成为华山派的
第十四代弟子". No crash, no error. Mechanism confirmed sound.

### Standing checklist sanity pass — all confirmed, no regressions

- **§7.90** (eval-cost 700000→5000000): code-confirmed still present in
  `config.fluffos`; also indirectly reconfirmed by a completely clean
  admin login/enter_world() this round (no repeat of the original crash).
- **§7.100** (sub-threshold `replace_program(ROOM)` fix, 15 occurrences):
  not re-diffed this pass, no reason to suspect regression (mechanical
  content fix, not touched by anything this round did).
- **§7.111** (`standard_trace()` `file_name(error["object"])` crash):
  **not applicable to this lib** — `adm/single/master.lpc`'s
  `standard_trace()` uses `%O` (driver's own safe object formatter) on
  `error["object"]` directly, never calls `file_name()` on it at all. A
  different, already-safe shape, not the vulnerable one.
- **§7.112**: see above — found unswept, fixed this round.
- **§7.113** (netdead reconnect losing `heart_beat`): not on the original
  62-lib checked list; spot-verified this round via the same call-graph
  method — `adm/daemons/logind.lpc::reconnect()` calls `user->
  reconnect()` unconditionally, and `clone/user/user.lpc::reconnect()`
  unconditionally does `enable_commands()` and (per user.lpc's own
  `heart_beat` handling elsewhere) resumes ticking correctly. No live
  disconnected-then-heal test was run this pass (no time), but the
  static shape matches every other confirmed-clean lib in this sweep,
  not `shzs`'s broken one.
- **§7.114** (private `input_line()` in an inherited `F_EDIT` mixin):
  **not applicable** — `feature/edit.lpc` has no `private` modifier
  anywhere and re-arms via a bound closure (`input_to((: input_line :),
  ...)`), not a string-name re-dispatch, sidestepping the whole bug
  shape. Live-verified anyway with a real multi-line board post
  (`post 测试标题` + 2 content lines + `.`) at `巫师休息室`'s board —
  every line was accepted correctly, not just the first, and posting
  completed ("留言完毕"). Test post was NOT left on the board (see
  cleanup note below).
- **§7.115** (missing `QUEST` file target): jh2006 is one of the "13 of
  80 missing-target" libs from the completed corpus survey in AGENTS.md,
  but has zero live `QUEST->` call sites — confirmed dead/unused, no
  action needed (already covered by that completed sweep, not
  re-verified from scratch this round).
- **§7.79** (bare 2-arg `addn`/`addn_temp`): **confirmed inapplicable** —
  `grep` found zero uses of `addn(` or `addn_temp(` anywhere in this
  lib's tree. The vulnerable simul_efun shim isn't even relevant here
  since nothing calls it.

### Observation, not fixed (out of strict scope per this round's directive): possible §8.1-shape title-length check

`clone/board/wuguan_b.lpc` inherits `inherit/misc/bboard.lpc`'s
`do_post()`, which checks `i = strlen(arg); if (i < 4 || i > 24 || i % 2)`
— on this driver `strlen()` counts real characters (not GBK byte pairs),
so this rejects any title with an ODD number of Chinese characters (e.g.
5-character titles), only accepting even counts. This has the same
byte-halving-not-adjusted shape as the already-fixed §8.1
`check_legal_name()` bug elsewhere in this lib, but it's a title-length
validation quirk, not a crash or data-corruption — players can always
pick a title with an even character count, so this doesn't block board
posting (verified: a 4-character title posted successfully end-to-end).
Left untouched per this round's explicit scope guidance (no crash/error/
stuck-state, so treated as a possible latent quirk to flag, not a bug to
fix without further confirmation this is unintended).

### Test methodology / cleanup

Native `build-debug` driver, two full boots (one to find/fix the
`menwei`/`death.h` bugs, one clean reboot from scratch to verify neither
regressed and to run the full combat/death/dbase/sect test sequence from
a known-clean state). Admin `fluffos`/`Mud2026Pass` used for `goto`/
`summon`/`call`/`callouts`/`update`; a throwaway character `testnine`
(测武生) used for all player-facing testing. Cleaned up before commit:
removed `testnine`'s save files (`data/user/t/testnine.o`,
`data/login/t/testnine.o`), reverted the test board post on
`data/board/wuguan_b.o` and an incidental resave of the unrelated,
real-player-content `data/board/post_b.o` (both via `git checkout --`,
confirmed no real player data was altered), and confirmed the admin's own
resaved `data/user/f/fluffos.o` has no test-marker residue. Driver killed
by exact PID after each boot (723700, then 726243) — never pattern-match
`pkill`.

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

## AGENTS.md §7.19 fix: enable_player() reentrancy from init()

`feature/command.lpc`'s `enable_player()` (wrapper around
`enable_commands()`) was reachable from an NPC's `init()`: the shared
`inherit/char/char.lpc` `setup()` (called from every character's
`create()`) itself calls `enable_player()`, and `d/gb/npc/xixia-wushi.lpc`
redundantly calls `setup()` again from inside its own `init()` (on top
of the `setup()` its `create()` already made) -- same shape as the
originally-documented mhxy `zhangmen.lpc` case. `enable_commands()` is
only safe to call from `create()`: calling it again on an object
already `living()` makes the driver re-invoke that same object's
`init()` as a side effect, which recurses back into `enable_player()`
on the same call stack until "Too deep recursion" aborts the boot on
a room's first-ever visit. Fixed with a true reentrancy flag
(`in_enable_player_now`), NOT a `living()` guard (which would break
legitimate re-enables from `revive()` in `feature/damage.lpc` and
`wakeup()`/`wakeup2()` in `cmds/std/sleep.lpc`, both confirmed to
re-invoke `enable_player()` on this lib while the object is still
`living()`). Verified via `lpcc --batch` single-file compile check
(PASS). Part of the corpus-wide §7.19 sweep (Batch E).

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 1 line(s) in 1 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 2 here-document block(s) repaired (2 with the terminator glued to the last text line, 0 with it indented), so `End of file in text block` no longer hides the room or object behind them: `d/tiezhang/taijie-2.lpc`, `d/dali/yuxu/yuxuguanmen.lpc`. The terminator must start its line (the lexer's own test, KB 04 §6.10); a glued one lost its newline in the GBK -> UTF-8 conversion together with a half character, which stays out.

## 深度功能测试（§10.7，2026-10-05）— 任务表里的 `.c` 路径与任务守护进程的防护

`scripts/lpc_dynamic_rows.py`：`quest/dynamic_location` 里 2443 行写的是原档案的 `.c` 路径。转档时文件已改名 `.lpc`，而显式后缀按原样解析，`load_object("/d/x.c")`、`new("/d/obj/quest/x.c")` 返回 0 且不报错（KB 03 §4.2，KB 06 §7.220），所以 `adm/daemons/questd.lpc` 读到的每一行都加载不出来：随机任务和任务物品从未生成，在 `create()` 里直接对结果调用 `tar->set()` 的版本还会崩溃，连带加载它的 cron 守护进程和 `give` 的任务钩子。这些行已改为 `.lpc`；另有 14 行指向的文件两种后缀都不存在（档案缺内容），保持原样。
`scripts/lpc_dynamic_quest_guard.py`：1 处 `spread_quest()` 调用（`init_dynamic_quest()` 的循环里）包进 `catch()`，缺失的任务物品或编译不过的房间只跳过那一个任务，守护进程照常加载、其余任务照常生成。
验证：`adm/daemons/questd.lpc`和 cron 守护进程在新进程里加载（HEAD 一次，工作树三次，选房是随机的）：HEAD 通过 2 个，工作树三次分别通过 2、2、2 个（共 2 个），无回退。

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `inherit/room/room.lpc`：`make_inventory()` 用 `catch()` 包住 `unew(file)`（缺档时它在 simul_efun 里对 0 调用 `query("unique")`），`else` 分支只在确有克隆时才取 `[<1]`。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-08）— 编译警告整理

`scripts/lpc_warnings.py jh2006 --fix` 加 `scripts/lpc_fix_no_effect.py --apply`，共改动 99 个 `.lpc`（多为删去未用的局部变量）。HEAD 与工作树分别加载（新进程）：93 -> 93 通过，无回退。启动时警告 9 -> 0；新进程登录（输入名字）正常。
手改 `adm/daemons/logind.lpc`：`get_id()` 里从未用到的 `ip` 删去。

## 深度功能测试（§10.7，2026-10-08）— `.lpc` 后缀的定宽切片

`.c` 改名 `.lpc` 时只改了字符串没改切片宽度：`f[<2..] == ".lpc"` 拿两个字符比四个字符，永远不成立（`!=` 永远成立），按后缀筛文件、去后缀的代码因此从不运行或截成 `x.l`（KB 06 §7.238）。`scripts/lpc_lpc_suffix_slice.py --apply` 改了 1 处比较、0 处去后缀（如 `cmds/skill/verify.lpc`）；改动的文件 HEAD 与工作树分别加载（新进程），无回退。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 3 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 1 个，只在 #if 分支用的声明移进分支 0 个文件；改动 4 个文件，HEAD 与工作树各载入一次无回退（4 objects; HEAD PASS 4, tree PASS 4; regress 0; newly loading 0），这些文件的警告 4 -> 0。

## 深度功能测试（§10.7，2026-10-11）：全库严格 UTF-8 检查

- `u/cht/workroom.lpc` 是含 NUL 的二进制文件（原档损坏），保留原样。

## 编译警告收尾（2026-10-13）

`scripts/toolkit_fix.sh` 一轮去掉 1 处多余继承，其余手工清零；改动的 5 个对象在 HEAD 与工作树各载入一次，regress 0。

- 天书任务 `quest/shenshu/npc/man.lpc`、毒虫 `d/xingxiu/obj/duchong.lpc` 的 `kill_ob()` 改 `void`，与 `feature/attack.lpc` 一致（`return ::kill_ob(victim);` 改成先调用再结束）。
- `cmds/usr/news.lpc` 里只有被注释掉的数据库代码用的 `mysql`、`rows` 删去；`d/city/mine_room.lpc` 自己的 `CLR`（清屏）覆盖 `ansi.h` 的空定义，先 `#undef` 再定义，行为不变。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。7 个文件 7 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）；`x op= 浮点` 先把浮点转成整数再运算（系数小于 1 时 x 直接变 0），改为 `x = to_int(x op ...)`：`/d/mr/npc/murong-fu.lpc`（`bouns *=`）、`/kungfu/skill/force/qi.lpc`（`q *=`）、`/kungfu/skill/force/recover.lpc`（`q *=`）、`/kungfu/skill/jieshou-jiushi/foguang.lpc`（`damage *=`）、`/kungfu/skill/taiji-quan/luanhuan.lpc`（`p *=`）、`/kungfu/skill/taiji-quan/zhen.lpc`（`damage *=`）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。

## 负数伤害当作消耗（2026-10-15，KB 06 §7.241）

`receive_damage("neili", -52)`、`receive_damage("qi", -12)` 之类把 `add()` 的负数写进了 `receive_damage()`：本库 `feature/damage.lpc` 对负数伤害报错（或归零），练功/运功时报 `F_DAMAGE: 伤害值为负值` 或消耗失效。已改为正数伤害，内力/精力类改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py`）：`/kungfu/skill/huntian-qigong/powerup`、`/kungfu/skill/lanhua-shou`。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。9 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。

## family 映射（补）（2026-10-15）

`mapping fam = (mapping)me->query("family");`（带类型转换的写法）同样直接取下标，1 处补上 `if (!mapp(fam)) fam = ([ ]);`。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。3 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。

## 把经验、属性、内力当技能读（2026-10-15，KB 06 §7.247）

当前内力、精这类名字有时指的是内功技能，逐处读过后手改：`longxiang-boruo` 的 `ob_hit()` 用 `query_skill("neili")` 比较双方内力，恒为 0 对 0，只会走“化去一部分”的分支，改为 `query("neili")`。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`xixing-dafa`→`xixin-dafa`（`qiantian-yiyang`、`tianlong-shengong`）；`jinshe-zhang`→`jinshe-zhangfa`（`jinshe-jianfa/kuangwu`）。

## 技能名拼错：技能文件里拼错自己的名字（2026-10-15，KB 06 §7.249）

技能自己的文件（或它的绝招目录）里，`query_skill()` 读的是差一个字母的自己的名字，永远得 0：“基本功夫要高过本技能”之类的限制从不生效，按等级取招、计算伤害的那一项一直是 0。改为本技能的名字（`scripts/lpc_fix_skill_typo.py` 的 self 判据）：`songyang-zhou`→`songyang-shou`（`songyang-shou`）。

## 燃木刀法「焚天」的效果一秒就消失（2026-10-15，KB 06 §7.246）

每秒检查的 `check_fight()` 声明了 `object weapon;` 却从不赋值，条件里的 `!weapon` 永远为真，效果在第一次检查时就被撤掉。把这一项改为 `!objectp(weapon = me->query_temp("weapon"))`，先存兵器再判断刀的种类。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

3 个文件、5 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/d/foshan/obj/shaobing`、`/d/miaojiang/npc/obj/shoe`、`/d/miaojiang/npc/obj/red_silk`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 1 个，改后 1 个（0 个原来载入不了），没有退步；其余 2 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## NPC 带着不存在的物品：simul_efun `unew()` 报错（2026-10-18，KB 06 §7.73）

`adm/simul_efun/object.lpc` 的 `unew(str)`（带 `unique` 判断的 `new()`）先 `ob = new(str)`，紧接着就读 `ob->query("unique")`。物品文件不存在时 `new()` 返回 0，读 0 的属性报 `Bad argument 1 to EFUN call_other()`，从 `carry_object()` 一路带出去：`create()` 里带着缺失物品的 NPC 载入不了（jh2006 的苗疆何铁手一类，该有 NPC 的房间少了人）。读属性之前补 `if (!ob) return ob;`（`int i = ob->query("unique"), j, k;` 拆成声明和赋值两句），缺的物品跳过，NPC 照常载入（`scripts/lpc_guard_carry_object.py --unew`）。载入检查：改动的文件改前能载入 2 个，改后 4 个，没有退步。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库目前没有对象设了缺失的武功；三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。（`scripts/lpc_guard_set_skill.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 26 处、26 个文件：`shaolin-shnfa`→`shaolin-shenfa`（12 处）、`kunlun-shnfa`→`kunlun-shenfa`（8 处）、`banrou-zhang`→`banruo-zhang`（2 处）、`yijinjing`→`yijin-jing`（1 处）、`qinmang-jian`→`qingmang-jian`（1 处）、`huashen-shenfa`→`huashan-shenfa`（1 处）、`weiituo-gun`→`weituo-gun`（1 处）。（`scripts/lpc_fix_skill_names.py`）

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## `x == "a" || "b"`：后面的字符串常量永远为真（2026-10-19，KB 06 §7.281）

`if (arg == "yuyou" || "yu you")` 里的 `"yu you"` 是非空字符串，永远为真，整个条件对任何 `arg` 都成立；作者要的是每个字符串都和变量比较。具体是：吃任何东西都会吃掉鱼油。在每个字符串前补上变量和运算符（`scripts/lpc_fix_literal_or.py`；`forrest2.lpc` 是 `dir == "north" && "south"`，手工改成 `(dir == "north" || dir == "south") && ...`）：`/clone/food/yuyou.lpc`（4 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 15 处）。改动：`/cmds/leitai/bwdh/ctrl.lpc`（3 处）、`/d/city/npc/obj/budai.lpc`（1 处）、`/d/city/obj/budai.lpc`（1 处）、`/d/hmy/shufang.lpc`（1 处）、`/d/sld/npc/stt.lpc`（1 处）、`/d/sld/sanpo7.lpc`（1 处）、`/kungfu/skill/qiankun-danuoyi.lpc`（7 处）。

## `socket` / `dumpsocket` 指令：`dump_socket_status()` 驱动里没有（2026-10-20，KB 06 §7.291）

这些巫师指令 `write(dump_socket_status());`，MudOS 的 efun 在 FluffOS 里不存在，指令编译不过。在模拟 efun 文件里补了 `dump_socket_status()`：用 `socket_status()` 排出同样的表（没有 sockets 包的构建，比如 WASM，只有表头；`scripts/lpc_add_sefun.py dump_socket_status`）。

## `mcheck`：`query_ip_rport()` 驱动里没有（2026-10-20，KB 06 §7.291）

指令要显示连线的远端端口，MudOS 时代的 `query_ip_rport()` 在 FluffOS 里不存在（`query_ip_port()` 给的是本地端口），指令编译不过。文件里加了一个返回 `"?"` 的占位函数（dtsl 的同名指令早就这么做）。改动：`/cmds/wiz/mcheck.lpc`。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/single/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## `exp` 指令编译不过：丢了两个颜色宏（2026-10-20，KB 04 §6.25）

`cmds/usr/exp.lpc` 里 `if (lvl > mylvl && lvl <= mylvl + S) str +=;` 两处缺右值：`syntax error, unexpected ';'`。书剑系的同名文件（shujian2008、shujian3、sjtx2、sjecl、bxsj）是 `str += HIY;` 和 `str += NOR;`（当前等级段高亮），照它补。加载检查：HEAD FAIL → tree PASS。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库现有的 NPC 文件里没有字面写成空 `chat_msg` 的（扫描只认 `set("chat_msg", ({ }))`）；守卫挡的是运行时才为空的列表和以后新增的 NPC。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/inherit/char/npc.lpc`（共 1 个文件）。

## `ad`：`efun::shout()` 通不过 `valid_override`（2026-10-21，KB 06 §7.311）

管理员扫描里 `ad`（`cmds/adm/ad.lpc`）编译失败：`23:9: error: Invalid simulated efunction override`，指令里的 `efun::shout(...)` 不在 master 允许的目录里。本库的 sefun `shout(str)` 就是 `message("shout", str, users(), this_player())`，与 efun 的行为相同，改成直接调用 `shout(`。同系的 bxsj、bxsj1、shujian3、jinyongwenzi 的 master 放行，没有动。

## 昆仑派 `banshuxian`、`hetaichong`、血刀门 `laozu` 的 `ask_me()`：`ob` 从来没赋值（2026-10-21，KB 06 §7.346）

`/kungfu/class/kunlun/banshuxian.lpc`、`/kungfu/class/kunlun/hetaichong.lpc`：`object ob;` 之后直接 `ob->query("gender")` / `ob->query_skill(..)`，根上的 xkx100 在声明后有一句 `ob = this_player();`，这个派生库把它丢了，`ask <师傅> about <秘籍>` 一律抛 `call_other() ... Got: int(0)`。补上这句。

## 苗疆山谷 `shangu1`：第二条蛇写成了 `jinshe = new(..yinshe)`（2026-10-21，KB 06 §7.346）

烧灵芝兰（`do_shao`）引出两条蛇：`jinshe = new(__DIR__ "npc/jinshe"); jinshe = new(__DIR__ "npc/yinshe");`，第二句把第一条覆盖了，`yinshe` 一直是 0，后面的 `yinshe->move(...)` 抛错。第二句改成 `yinshe = new(...)`（sje、jym 的同一份文件是对的）。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 15 条注册（12 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/d/city/pinqiting.lpc`（`do_pass`、`do_resign`）、`/d/dali/wuliang/anbian.lpc`（`do_tiao`）、`/d/dali/wuliang/muwu1.lpc`（`do_tiao`）、`/d/dali/wuliang/shanlin-6.lpc`（`do_tiao`）、`/d/huanghe/npc/mafu.lpc`（`do_rideyz`）、`/d/huashan/jinshe/obj/haigu.lpc`（`do_move`）、`/d/huashan/npc/yaba.lpc`（`do_follow`、`do_kill`）、`/d/miaojiang/slu9.lpc`（`do_zuan`）、`/d/mr/obj/chahua3.lpc`（`do_chu`）、`/d/mr/shuichi.lpc`（`do_strike`） 等共 12 个文件。最多的函数名：`do_tiao` 3 处、`do_strike` 2 处、`do_pass` 1 处、`do_resign` 1 处、`do_rideyz` 1 处。

## 对象路径里的 `..`：`new(__DIR__ "../obj/x")` 报 `Read access denied`（2026-10-22，KB 06 §7.351）

`__DIR__` 是当前文件所在目录（带结尾斜杠），`__DIR__ "../obj/x"` 就是 `/d/zhiye/npc/../obj/x`；驱动的 `legal_path()` 不接受带 `..` 的路径，`new()` / `load_object()` 直接抛 `*Read access denied.`（实测，`find_object()` 对它答 0）。走库自己的 `carry_object()` / 房间 `objects` 表的路径，库的基类会先规范化，能用；直接把路径交给 `new()` / `clone_object()` / `load_object()` / `move()` 的不行，调用到那一步才报错。改成规范化后的绝对路径（`scripts/lpc_fix_dotdot_dir.py --direct`）：`/d/wudang/npc/xiaocui.lpc`（`__DIR__ "../obj/nuerxiang"` → `"/d/wudang/obj/nuerxiang"`）。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 还剩 2 个函数没有补（inquiry 2）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/d/shaolin/npc/xuan-du.lpc`:`ask_me`、`/kungfu/class/gumu/sun.lpc`:`ask_job`。

## `(: 函数名 :)` 指针指向本库没有的函数：只含这个指针的行加了注释（2026-10-22，KB 06 §7.355 补充）

`inquiry` / `item_desc` / `chat_msg*` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：用到时（`ask`、`look`、NPC 闲聊）驱动抛 `*Undefined lfun pointer called: 函数名`，这一拍心跳的后半段被跳过。这些函数没有可以补回的来源（别的库同一路径的文件里没有，或者它还要用本库没有的东西），所以 2 个文件里 3 行只含这个指针的行（`"佛事": (: ask_me :),` `"水陆大会": (: ask_me :)` `"玉蜂": (: ask_job :),`）加了注释，原文保留并写明原因，这一项当作没有这个话题 / 物品 / 闲聊条目（`scripts/lpc_fix_dangling_lfun.py`；`#include` 的文件在库里缺失的对象、指针不在整行上的写法没动）。 前提（`function_exists()`）和加载检查（HEAD 与工作区对比，本库改动的 `.lpc` 文件）的结果见 KB 06 §7.355：没有一个回归。

## 汉字按字节切片的老写法没有换成按字符：改法名 `"澄" + name[2..3]`、辈分判断 `name[0..1] == "澄"` 等 55 处（2026-10-22，KB 06 §7.360）

原档按字节算字符串区间（一个汉字 2 字节）：`name[2..3]` 是名字的第二个字，`name[0..1] == "澄"` 问名字是不是以「澄」开头。转成 UTF-8 之后，这个驱动的区间和 `strlen()` 都按字符算（`strlen("澄观")` 是 2，`"澄观"[0..1]` 是两个字），老算术原样留着、意思全变：拜入少林 / 武当 / 峨嵋等派的玩家被改成错误的法名（二字名 `张三` 变成一个字的 `澄`，更长的名字取到第三个字）；各派掌门的辈分判断（`name[0..1] == "澄"`）永远不成立；改名官 `zhuce` 的长度检查按字节算，合法的名字一个也过不了；NPC 的称呼和提示里取到两个字而不是一个字。

本库 55 处（29 个文件）：拼名字的赋值 21 处、与汉字常量比较 22 处、改名官的长度检查 7 处、对切片赋值 3 处、两个名字切片互比 1 处、`query("name")[..]` 1 处。例：`name[2..3]` → `name[1..1]`（`/d/shaolin/npc/fangsheng.lpc:150`）；`old_name[2..3]` → `old_name[1..1]`（`/d/shaolin/npc/rong.lpc:66`）；`old_name[0..3]` → `old_name[0..1]`（`/d/thd/npc/yaoshi.lpc:349`）。`scripts/lpc_fix_gbk_slice.py` 把下标按字符重算（社区的 UTF-8 版 `xkx100utf8` 里就是同样的写法，作对照）；没有改的：截断（`name = name[0..7]`，现在最多 8 个字，只是放宽）、ASCII 的区间（`fname[0..3] == "room"`、`ctime(time())[4..19]`）和上下文看不出是汉字的区间。证明（`scripts/lpcc_eval.py`，bixiecanyang；其余各库是同一份文本）：让澄字辈掌门 `attempt_apprentice()` 一个名叫「张三」的访客，HEAD 的法名是 `慧`，改后是 `慧三`；抽样 28 个库的 HEAD / 工作树加载对比 0 退步。工具不幂等（`[0..3]` 折半得 `[0..1]`，又是对齐区间），改过的文件记在 `scripts/gbk_slice_converted.txt`，不要重跑。

## 长度检查按字节写，旁边的提示按汉字写：20 处（2026-10-22，KB 06 §7.362）

老档的 `strlen()` 数字节（一个汉字 2 字节），转成 UTF-8 后它数字符：提示写「必须是 2 到 6 个中文字」的检查还是 `strlen(name) < 4 || strlen(name) > 12`，于是两三个字的房名、帮会名、群名、聊天室名、称号被提示自己说允许的那句话拒绝，上限却是提示的两倍；留言板的标题检查 `i < 4 || i > 24 || i % 2` 还会拒绝所有奇数个字的标题（`post 你好吗`）。本库 20 处（5 个文件）：`if (i < 4 || i > 8 || i % 2) {`（`/adm/logind.lpc:766`）；`if (i % 2 == 0 && !is_chinese(name[i..<1])) {`（`/adm/logind.lpc:772`）。`scripts/lpc_fix_strlen_gate.py` 以提示为准：条件里每个 `strlen` 门槛都恰是提示所说数字的两倍才折半，存长度的变量（`i = strlen(arg);`）的门槛和 `|| i % 2` 奇偶项、其后循环的 `i % 2 == 0 &&` 一并处理；提示里有英文 / 字母 / 字节的不动。证明（`scripts/lpcc_eval.py`，bxsj 的留言板，求值对象继承 NPC 并重写 `edit()` 记录调用，`command("post 标题")`）：HEAD 拒绝「你好」和「你好吗」、放行 23 个字的标题；改后接受前两个、拒绝第三个；shenmo 的 `named.lpc invalid_new_name("张三")`：HEAD 回 `名字只能是2-4个中文字。`，改后回 0。抽样 24 + 15 个库的 HEAD / 工作树加载对比 0 退步。

## 按字节写的汉字循环、茶馆猜诗和同盟频道标题（2026-10-23，KB 06 §7.363）

老档按字节做「一个汉字」：`while (i--) if (i % 2 == 0 && !is_chinese(name[i..<0]))` 只检查偶数下标，奇数位上的拉丁字母（`张a`）会过；茶馆猜诗 `mixup()` 用 `strlen(str)/2` 再 `j=j+j`、`str[k..k+1]` 交换两字节；泥潭系 `channeld` 的 `switch (strlen(fname)) case 4/6/8/10` 和 `strlen(family)==4/6` 按字节长度给同盟 / 门派名加空格。本驱动的 `strlen()` 和区间都按字符算。`scripts/lpc_fix_byte_char.py`：去掉奇偶项、把区间改成 `name[i..i]`，按字符重写 `mixup()` 并把 `strlen(first)>=14` 折成 7，频道标题的 case / 门派长度改成字符数（对照 aoxiangtianji）。本库 汉字循环 / `is_chinese` 区间 6 个文件。证明（`scripts/lpcc_eval.py`）：sjplii 的 `check_legal_name` 在 HEAD 接受「张a」、改后拒绝，两边都接受「张三」；xkx100 的 `clubpoem->mixup("离离原上草")` 得到「离离原草上」（真交换汉字）；nitan_san 两字同盟名得到 `【 兄  弟 】`。关键对象加载通过。

## 从末尾按字节取汉字、书剑开帮长度（2026-10-23，KB 06 §7.364）

§7.360 只折了数字下标的 `[a..b]`，从末尾取的 `[<2..<1]`（GBK 下一个汉字）和 `[<4..<1]`（两个字）还留着：开帮 `gcreate` 的帮助写「二至六个汉字 / 3到8个英文字母」，检查却是 `(strlen%2)==1 || <4 || >12`，末字对 `({ "帮","会",… })` 用 `gname2[<2..<1]` 永远对不上；少林 / 峨嵋法名 `"明" + name[<2..<1]`、死讯 `killer[<2..<1] != "。"`、兵器改名的 `can_name` 同样坏掉。`scripts/lpc_fix_tail_slice.py` 只改汉字语境（对照非 ASCII 字面量、`can_name` / `valid_group_name`、拼名字），ASCII 补零 / ctime / 复数词尾 / `.lpc` 不动；`[<2..<1]`→`[<1..<1]`，`[<4..<1]`→`[<2..<1]`，开帮门槛按帮助改写。本库 从末尾切片 5 个文件。证明（`scripts/lpcc_eval.py` bxsj）：HEAD 上 `斧头帮[<2..<1]` 对不上「帮」；改后 `[<1..<1]` 对上；长度放行 `斧头帮`/`fut`；`"明"+"张三"[<1..<1]` 得「明三」。

## 血条 / 表情标题按字节算显示宽度（2026-10-23，KB 06 §7.365）

老档把汉字当两字节：`bar_string[0..(val * N / max) * 2 - 1]` 把「格数」换成字节下标，半格血条在本驱动（按字符算区间）上会整条画满；巫师表情 `edemote` 的 `repeat_string("─", 13 - (strlen(emotion) / 2))` 也会少减汉字宽度。`scripts/lpc_fix_display_pad.py`：去掉 CJK 血条 / 空白条上的 `* 2`（`jings`/`qis` 赋值和 `blank_string3[0..(23-a)]` 的 23→11 一并改），表情标题去掉 `/ 2`；ASCII 空格的 `none_string` / `empty_string` 仍保留 `* 2`（一格两个空格）。本库 2 处（1 个文件）。证明（`lpcc_eval.py` hhsj）：`tribar_graph(6,9,12)` 在 HEAD 画出整条 12 个■，改后为 6 个■+3 个□；麻将 `strlen(tempB)/2` 是两字符牌码，未改。


## Beyond 出口仍指向 /u/beyond（2026-10-23，KB 06 §7.368）

宁波 / 苏州 / 慕容等区域已进 `/d/ningbo`、`/d/suzhou`、`/d/mr`、`/d/hz`，出口与任务物路径仍写 `/u/beyond/…`。`scripts/lpc_fix_beyond_exits.py` 在目标 `.lpc` 存在时改写（`murong`→`mr`）。本库 2 处。证明：sjplii `xikou` HEAD 西向 `/u/beyond/ningbo/aywsi`，改后 `/d/ningbo/aywsi` 可加载；bxsj `hubian1` 三向均可加载。

## 丐帮长老 gb_nz 无法加载（2026-10-27，KB 04 §6.25 Also）

`d/gb/npc/gb_nz.lpc`：`mixed wherei=({` 少了内层 `({`（手足 xkxz2 / xkxc98sj 的 `d/gaibang/npc/gb_nz` 有），`query_temp("promotion_target)` 缺收尾引号，`accept_object` 在注释掉的备用奖励块前多了一个 `}`。补内层数组、补引号、去掉多余 `}`，并删掉未用的 `fam`。`/u/hunthu/` 路径未动（内容）。证明：HEAD 加载失败；改后加载成功。

## 深度功能测试（2026-10-27，§6.25 set_name 缺开头引号）

`lx_cloth` / `jugeng` 的 `set_name(` 缺开头引号（已有收尾 `"`）；补上。
