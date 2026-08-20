
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
