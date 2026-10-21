# xiakexing100 — 侠客行一百

Archive: `侠客行100.rar`. Port: 40037. Status: **done** (boots clean and
quick, full registration flow verified end-to-end including a real
Chinese name).

## What this is

"侠客行一百", credited to "Coollizard & xkx100 2003-2004",
http://yoyo.xm.fj.cn/xkx100, up since 2001-01-14 per its own connection
banner. Same "Century-family" `adm/single/{master,simul_efun}` layout
as `shiji`/`zhonghua2`/`shujian2008`/etc. ~14,227 raw files, 12,209
after `.c`→`.lpc` rename — the largest lib processed in this session
run.

## Fixes applied

1. **AGENTS.md §15h**, standard shape: `is_chinese()`'s GBK lead-byte
   check → CJK codepoint check; `check_legal_name()`'s byte-count bound
   `< 4 || > 10` → character-count bound `< 2 || > 5`, removed the
   `i%2==0` even-byte-offset gate.
2. **Confirmed NOT needed, via source reading**: no §4 fix
   (`master.c`'s `valid_write` gates via `find_object` only,
   `valid_read` is a bare `return 1;`); no deep `named.lpc` fix
   (`named.c` exists but lacks the `PATH()`/sliding-window pattern seen
   in the nitan-family shape — a simpler, different implementation
   here).
3. **AGENTS.md §15p**: `/adm/daemons/network/dns_master` was in
   `adm/etc/preload` — removed proactively before the first boot
   attempt. Booted clean in under 20 seconds, zero compile errors, no
   hang.

## Interactive test result — full registration flow

No hidden pre-id prompts. Verified the complete registration path in
one continuous connection: id `xkxbtest` → confirm `y` → **real Chinese
name `秦风`** (avoiding "韦小宝"/Wei Xiaobao — a famous Jin Yong
character found in this lib's `banned_name` list) → accepted, proceeds
straight to "请设定您的密码：".

## lpcc sweep

12,209 files, 12,118 pass / 91 fail (99.3%). Failure tail dominated by
an `accept_hit` type-mismatch cluster (120 of the reported instances
across files, string vs object argument), plus the usual handful of
missing globals/syntax typos — not triaged individually per AGENTS.md
§6b/§13. Memory stayed comfortably healthy throughout the sweep despite
this being the largest lib in the current session run (~13GB free
consistently, lpcc RSS peaked well within normal range, no pressure
requiring an early kill).

## Re-verification pass (driver rebuild + LPC formatter + WASM build)

- **Reformatted** all 12209 `.lpc` files under `work/` with
  `tools/lpc-syntax/format-corpus.mjs`: 10795 written, 1414 already
  idempotent-clean, 0 refused. Verified the earlier §15ae fix
  (`feature/command.lpc`'s `command_hook` staying `nomask` with
  `private` still commented out) survived unchanged.
- **Native retest against the freshly-rebuilt driver**
  (`~/src/fluffos/build-debug/src/driver`, rebuilt from latest upstream
  master): clean boot, zero fatal errors in `log/debug.log`. Full
  registration flow re-verified with a fresh real Chinese name
  (`秦墨`/id `xkxbrew`, then `秦徽`/id `xkxbrev`), reaching an actual
  starting room, `look`/`score`/`quit` all producing correct output —
  also separately re-confirmed post-login command dispatch (the §15ae
  fix) via a reconnect + `look` on the saved character. No regressions
  from either the driver rebuild or the reformat.
- **WASM build test found and fixed a real, pre-existing mudlib bug**
  (`scripts/wasm_client.js` against `~/src/fluffos/build-wasm/src`):
  boot itself was clean, but every connection attempt silently stalled
  right after the login banner, never reaching the id prompt at all —
  no fatal error printed anywhere. Root-caused by reproducing the exact
  same stall **natively** (temporarily moving aside
  `work/log/MUDVISITOR`, the untracked runtime-state visitor-counter
  file `adm/daemons/logind.lpc`'s `howmany_visitor()` reads on every
  connection): `read_file(VISITORS)` returns a non-string (`0`) when the
  file doesn't exist, and the un-guarded `sscanf(content, "%s %d", ...)`
  that follows throws `Bad argument 1 to sscanf` — uncaught, this aborts
  the rest of `logon()` silently (confirmed via `debug.log`'s
  `执行时段错误：*Bad argument 1 to sscanf`), before the player ever sees
  an id prompt. This is a **genuine pre-existing mudlib bug**, not a
  WASM-specific driver gap — it just never manifested in earlier native
  testing passes because `MUDVISITOR` already existed on disk from prior
  test runs (it's untracked/gitignored runtime state, not shipped in the
  original archive's git history), whereas `scripts/wasm_client.js`'s
  in-memory filesystem deliberately never copies `log/`'s *contents*
  (only creates the empty directory, by design, to keep the harness
  fast), so a WASM run is effectively always a "genuinely fresh archive,
  first boot ever" scenario for this file — the exact condition that
  triggers the bug. **Fixed**: added a `stringp(content)` guard (return
  `0`/treat as "no visitors yet" if the file doesn't exist) to both
  `howmany_visitor()` and the identically-shaped `howmany_card()`
  (`GIFTCARD` file, same pattern, fixed proactively). Re-verified: (a)
  natively, with `MUDVISITOR` moved aside, connection now proceeds
  straight to the id prompt showing "第一位访问者" and a full
  registration completes cleanly, zero `debug.log` errors; (b) under
  WASM, full registration now also completes end-to-end (id `xkxwasmz` →
  real Chinese name `秦岫` → stat roll → gift/email/gender → landed in an
  actual starting room, `look`/`score`/`quit` all producing correct
  output). This lib has no IP-format-dependent login gate, so once this
  fix was in place it was fully playable under WASM too.

## WASM-enablement pass (loopback-allow / admin seeding)

Applied the four standard WASM-first changes (AGENTS.md §1.3b/§1.3e/§1.5).

### 1. Loopback always allowed — ban list + per-IP throttles (`adm/daemons/logind.lpc:73-124`)
`logon()` ran `BAN_D->is_banned()`, an `in_login > 10` per-IP
in-progress-login throttle, and `BAN_D->is_multi()` (per-IP character
cap) unconditionally. Added an `is_local` local computed once and
gated all three on `!is_local`.

**Written fail-closed from the start (2026-07-24)**: `is_local =
(stringp(lip) && (lip == "127.0.0.1" || strsrch(lip, "127.") == 0))` —
only a genuine loopback-shaped string is treated as local; an
unparseable/non-string ip is NOT local and still goes through the ban
list and both throttles. (An earlier partial pass on this file had used
the fail-open shape seen on this batch's other four libs — `!stringp(lip)
|| lip == "127.0.0.1" || strsrch(lip, "127.") == 0 || sscanf(lip,
"%*d.%*d.%*d.%*d") != 4`, which let ANY malformed ip bypass every gate —
but that was corrected to the fail-closed form above before this pass
was considered complete; see the sibling libs' NOTES.md entries for the
full rationale: the old WASM driver bug that produced garbage
`query_ip_number()` output is now fixed, so there is no reason left to
treat "can't parse it" as "must be loopback".)

### 2. Uptime startup gates — none present
No `uptime() < N` connection-rejection gate exists in this lib. All
`uptime()` hits are in-game content: gambling rooms (`d/*/duchang*.lpc`,
`npc/douji`, `npc/saigui`), NPC/room respawn timers, cooldowns, and
`adm/daemons/autosaved.lpc`'s once-per-boot data-file initialization
(`if (uptime() < 400) { ...write_file... }` — first-boot bootstrap of
some `/data/*` flags, not a connection gate). Nothing to bypass.

### 3. Anti-flood throttles — covered by item 1
No separate registration-throttle daemon exists; the per-IP protection
in this lib IS the `in_login`/`BAN_D->is_multi()` checks patched above,
already loopback-exempt.

### 4. Admin account seeded — `fluffos` / `Mud@2026` / 浮浮
Registered through the real flow (id `fluffos` → `y` → 浮浮 →
`test1234`/confirm → talent `1`/`20`/`20`/`20`/`y` → personality `0` →
email → `m`), landed in a random starting room. Granted `(admin)` by
appending `fluffos (admin)` to `adm/etc/wizlist` (`securityd.lpc`'s
`get_status()` reads this file into `wiz_status`). Verified: login as
fluffos shows `目前权限：(admin)`, `update /adm/daemons/logind` →
`重新编译 /adm/daemons/logind.lpc：成功！`.

**Save files for the orchestrator to force-add** (untracked, not
gitignored):
- `libs/xiakexing100/work/data/user/f/fluffos.o`
- `libs/xiakexing100/work/data/login/f/fluffos.o`

### Bonus fix: `quit`/`exit` was silently broken for EVERY player (pre-existing, not WASM-related)

While verifying the admin account's `quit`, discovered `cmds/usr/exit.lpc`'s
`savequit()` never actually let anyone quit: `int a = 1;` is reassigned
inside the `if (link_ob) {...}` branch to `a = (link_ob->save())`, and
`link_ob` (`me->query_temp("link_ob")`) is the `/clone/user/login`
connection object set by `enter_world()`/`reconnect()` on **every**
login, not just a rare possession/reconnect edge case. FluffOS's
`save_object()` efun returns the byte-size of the text written on
success (confirmed by reading `~/src/fluffos/src/vm/internal/base/object.cc`'s
`save_object_recurse()`, which accumulates and returns `textsize`), not
a 0/1 boolean — so `a` ends up as some multi-hundred-byte count, and the
final check `if (a == 1 && me->save())` was false for virtually every
quit, for every character, admin or not. The player saw all the normal
quit text ("你共停留了...欢迎下次再来！") followed immediately by a scary
"警告：档案保存失败，无法退出游戏，请马上联系巫师解决。" and was never
actually disconnected (`destruct(me)` never reached). Confirmed present
verbatim in the original raw archive (`raw/xkx100/cmds/usr/exit.c`), so
this is a decades-old author typo/driver-assumption mismatch, not
something introduced by this project's conversion or by the WASM pass.
**Fixed**: `if (a == 1 && me->save())` → `if (a && me->save())` (test
truthiness, matching the efun's actual 0=fail/nonzero=success
contract). Verified with a fresh registration and with the fluffos
admin account: `quit` now completes cleanly with no warning and no
lingering interactive body.

### Retest (2026-07-24)
Fresh boot, fresh registration (id `qinlanx`/`qintestb`, real Chinese
names 秦岚新/秦测三) through `look`/`score`/`quit` — landed in a
starting room, correct `score` output, clean quit with no warning.
`fluffos`/`Mud@2026` admin login verified: `look` then `update
/adm/daemons/logind` → `重新编译 ... 成功！`, then clean `quit` (the
bonus fix above). Zero `执行时段错误` lines in `debug.log` across the
whole session (the one hit from an unrelated missing-`log/nosave/`
directory surfaced only while probing the quit bug with the `call`
wizard command directly on a userp target — `log/` is fully
gitignored/regenerated at boot, not a real defect worth chasing
further here). Test characters removed afterward; fluffos kept.
Reverted an incidental `data/topten.o` leaderboard diff caused by the
test registrations (pre-existing tracked file, not meant to churn from
QA runs).

## 深度功能测试 / Deep functional test (AGENTS.md §10.7, 2026-07-24)

One continuous native session (`~/src/fluffos/build-debug/src/driver`,
port 40037), following the §10.7 checklist end to end: read `help
intro`/`help newbie`/`help newbie-basic`/`help newbie-shaolin1` first,
registered a real Chinese name (`qftester` / 秦风, password `test1234`,
born 嘉兴/group `3`, talents 20/20/20/20, personality `0`), landed at
`/d/jiaxing/yanyu` ("烟雨楼"), `look`/`score`/`i`/`hp` all correct.
Explored on foot toward 牛家村 reading room `.lpc` source
(`d/jiaxing/*.lpc`) to navigate since exit lists intermittently hide
under the lib's night-time darkness gate. Used the wizard `spgo`/
`summon` commands (via the seeded `fluffos` admin) purely to fast-travel
the SAME test character to distant content (少林寺 练武场/广场) rather
than trekking the whole map by foot — the actual sect-join, skill-learn,
combat, and shop interactions below were all performed by the ordinary
player character, not the admin.

**Safe sparring**: the newbie guide's suggested targets (a village
`小孩`/`女孩`) both declined `fight` — traced this to their `attitude`
being genuinely `"friendly"` in their own `create()` (`/d/village/npc/
kid.lpc`, `/d/village/npc/girl.lpc`), which `inherit/char/npc.lpc`'s
`accept_fight()` is coded to always decline (`case "friendly": ...
return 0;`) — working as designed, not a bug (a different, unrelated
`/d/jiaxing/npc/boy.lpc`/`/d/village/npc/boy.lpc` with `attitude:
"peaceful"` momentarily looked like a mismatch until the actual live
object path was confirmed via `call obj->query(...)` — red herring, not
reused). Used the lib's own documented, code-confirmed-safe wooden-dummy
mechanic instead (`d/shaolin/obj/mu-ren.lpc`, `accept_fight()` checks
`me->query("damaged")`/a `random(fight_times)>=10` break-chance, exactly
the §10.7-item-3 shape): `fight mu` at `/d/shaolin/wuchang1` exchanged
several rounds of blows with correct combat text, `halt` ended it
cleanly, `hp`/`i` afterward correct, zero `debug.log` errors.

**Skill/sect join**: followed `help newbie-shaolin1`'s documented path —
`apprentice biqiu` (清为比丘 at `/d/shaolin/guangchang1w`) immediately
accepted as a 俗家弟子/少林派第四十一代弟子 (no manual `ask ... about
出家`/`kneel` needed for this particular monk); `score` showed 师父/称谓
updated correctly; `skills biqiu` listed the master's own skill roster;
`xue biqiu dodge 1` (organic NPC-teacher path) advanced 基本躲闪 from
unlearned to `1/0`, `cha` confirmed it. Both the sect-join and
skill-learn steps worked correctly, no separate admin-command shortcut
was tested (none is needed/expected in this lib — `apprentice` IS the
join mechanism).

**`quit` → debug.log → reconnect (§10.7 items 5, 8, 9)**: clean `quit`
produced no warning (confirms the pre-existing `savequit()` fix from the
"Bonus fix" section above still holds) and left zero new `debug.log`
lines. Net-dead (dropped the connection without `quit`) and reconnected
PROMPTLY (a few seconds later): worked correctly, position/state intact.
**Net-dead and NOT reconnecting until the real timeout elapsed found a
new, live-reproduced bug — see below.** Separately, clean `quit`
followed by a genuine ~75-real-second wall-clock gap, then a FULL fresh
login (not a net-dead reconnect) via `qftester`/`test1234`: correctly
restored sect membership, skill, and all `score` fields from the
on-disk save file (`data/user/q/qftester.o` — `family` mapping,
`skills`/`learned` mappings, `dbase.qi`/`jing` etc. all intact).

**Shop purchase (§10.7 item 6)**: character had no starting funds
("你没有存款"), so used the admin account to `clone /clone/money/coin`,
`call coin->set_amount(500)`, `spgive qftester coin` (funding only —
the purchase itself was performed by the ordinary player character).
`list` at 烟雨楼's 店小二 showed the menu correctly; `buy jitui` (30
文) succeeded, correctly made change into higher denominations (500
铜钱 → 1 烤鸡腿 + 4 两白银 + 70 文铜钱); `eat jitui` consumed it. No
errors.

**Not verified live**: progression to a real death/respawn cycle — the
session budget went to the net-dead bug investigation below instead;
code review only (`d/city/ghost*.lpc`/鬼门关 revival flow referenced by
`help newbie-basic`'s〖死亡〗section was read but not exercised). A
sect promotion (拜达摩/升辈) is a multi-hour undertaking per the
newbie guide's own admission and was not attempted.

### Bug found and fixed: `tell_room()` 2-arg wrapper crashes the net-dead force-quit handler — matches AGENTS.md §7.12 exactly (severity-escalated instance)

`adm/simul_efun/message.lpc`'s `tell_room()` wrapper:

```lpc
varargs void tell_room(mixed ob, string str, object *exclude) {
  if (ob) message("tell_room", str, ob, exclude);   // BEFORE
}
```

Every 2-argument call site leaves `exclude` as LPC's default `int 0`
(not an empty array), and the real `message()` efun's 4th argument
rejects a bare `0`. `clone/user/user.lpc`'s `user_dump()` — the
`NET_DEAD_TIMEOUT`-driven (900s / 15 real minutes, `include/user.h`)
force-quit handler that runs when a net-dead player never reconnects —
calls `tell_room(environment(), ..., "\n")` with only 2 args at its very
first line (the DUMP_NET_DEAD case). This is byte-for-byte the same
lib/function/case/timeout shape AGENTS.md §7.12 documents as
"severity-escalated" from `dtsl`'s deep functional test: the crash
aborts `user_dump()` at that exact statement, so the two lines after it
(`"/cmds/usr/exit"->savequit(this_object())`) never run — **silently
disabling the entire net-dead force-quit safety net**: a player who
net-deads and never manually reconnects would stay alive in server
memory forever (never actually saved-and-removed via this path) until a
driver restart.

**Live-reproduced** (not just pattern-matched): temporarily lowered
`NET_DEAD_TIMEOUT` from 900 to 12 (`include/user.h`), ran the wizard
`update /clone/user/user` command to recompile it, connected as
`qftester`, dropped the connection without `quit`, waited past the
shortened timeout:

```
执行时段错误：*Bad argument 4 to EFUN message()
Expected: object, array,  Got: int(0).
程式：/adm/single/simul_efun.lpc 第 77 行
呼叫来自：/clone/user/user.lpc 的 user_dump() 第 75 行，物件： /clone/user/user#105 ("秦风")
呼叫来自：/adm/single/simul_efun.lpc 的 tell_room() 第 77 行
```

**Fixed** (the standard AGENTS.md §7.12 wrapper fix, protects every
2-arg call site in the lib at once, not just this one):

```lpc
varargs void tell_room(mixed ob, string str, object *exclude) {
  if (ob) message("tell_room", str, ob, exclude || ({}));   // AFTER
}
```

Re-verified with the same shortened-timeout methodology: no crash,
`debug.log` clean, and `who` afterward showed only the admin online —
`qftester` was correctly force-quit-and-saved this time (confirms the
two previously-dead lines, including `savequit()`, now execute).
Restored `NET_DEAD_TIMEOUT` to 900 and did a full clean driver restart
before finishing (the test-only timeout value was never left in place).

**Note for the project**: two other confirmed "Century/`adm-single`"
lineage siblings (AGENTS.md §11) — `shiji` and `xjcq2000` — still
carry the exact same unfixed 2-arg `tell_room()` wrapper in their own
`adm/simul_efun/message.lpc` (checked via grep during this pass, not
fixed — out of scope for this task, which is `xiakexing100`-only).
`shujian2008`, `xkxz2`, and `zhonghua2` (same family) already
carry the fix from earlier passes. Worth a follow-up pass on `shiji`/
`xjcq2000` specifically for this bug given `xjcq2000` is
also the lib AGENTS.md §10.8 documents hitting an unrelated driver-fatal
crash ~25 minutes into its own net-dead soak — the two are different
bugs but both live in the same net-dead code path family.

### Observation, not fixed (design ambiguity, see §10.7's scope note): two independent day/night clocks can visibly contradict each other

`cmds/std/look.lpc`'s exit-listing darkness gate
(`天色太黑了，你看不清明显的出路`) keys off `NATURE_D->game_time()`,
which derives an in-game shichen (時辰) hour from a heavily-compressed
calendar clock (`adm/daemons/natured.lpc`: `#define TIME_TICK
((time()%(60*24*3600))*365)` — 60 mud-years pass every 60 real days,
i.e. roughly 6 mud-hours per real minute, confirmed live: the session's
in-game date advanced across several 时辰 within a couple of real
minutes). The SEPARATE sun-position flavor line
(`NATURE_D->outdoor_room_description()`) keys off `current_day_phase`,
a `nosave` variable advanced by its own independent real-time
`call_out("update_day_phase", ...)` cycle. These two clocks are not
synchronized and were observed live disagreeing outright in the same
room printout — "一轮火红的夕阳正徘徊在西方的地平线上"（sunset flavor
text) immediately followed by "天色太黑了，你看不清明显的出路"
(darkness gate, only fires for 亥/子/丑/寅时) moments apart, and at one
point "太阳正高挂在西方的天空中"（afternoon flavor text) paired with the
SAME darkness message. Purely cosmetic/exit-listing (movement in a
known direction still works even when the list is hidden — confirmed by
navigating through several "dark" rooms via directions read from
source), and both clocks' formulas are pure LPC business logic with no
encoding/efun/grammar involvement, so this is very plausibly authentic
original-game behavior rather than anything this project's conversion
introduced. Documented per §10.7's scope note rather than "fixed" by
guessing which clock should govern the gate.

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 70 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（2026-08-13，round two，新驱动重测）

针对驱动升级（`quest_times`/`win_times` `%`-operator 修复 + Warning/warning
大小写回退兼容）做的重测。

### 发现并修复的 PROGRAMMING bug

1. **`log_file()`（`adm/simul_efun/file.lpc`）完全没有
   `assure_file()` 保护（AGENTS.md §7.11-class）**：已加上前向声明
   + `assure_file(LOG_DIR + file);`。

### Proactive checks（无需改动）

- 实际生效的 master file 是 `adm/single/master.lpc`（`config.fluffos`
  指定），其 `log_error()` 已经在更早一轮修复过（`strsrch(message,
  "arning:") == -1` 判断）。仓库里还有一份未使用的
  `adm/obj/master.lpc`（没有任何档案 `#include`/引用它，也不是
  `config.fluffos` 指定的 master file），其中的 `log_error()` 仍是
  未修复的旧形状——确认它是死代码后未改动。
- `win_times` 的 `%`-operator 修复确认存在且正确：
  `d/city/npc/jinyong.lpc:197`、`d/beijing/npc/refereew.lpc:177`、
  `d/city/npc/gulong.lpc:246` 均已用 `to_int(query("win_times")) %
  5`。
- `feature/dbase.lpc` 未发现 tybxjh/wlhd 那种密码写保护，不适用。

### 实测过程

管理员 `fluffos`/`Mud@2026`（此前 WASM 阶段已注册并提交存档）用真
实密码重新连线，落地在此前保存的地点（车马店），`score` 正常显示
天赋/属性，`quit` 前的游戏内状态与存档一致。全程 `debug.log` 只有
正常的编译期提示（`Unknown #pragma` 等价的 `In file included
from` 追踪行、未使用局部变量），无运行时错误。驱动按精确 PID 结
束；测试期间产生的存档时间戳增量已 `git checkout --` 还原，未提
交无关变化。

## AGENTS.md §7.100 修复（2026-08-19，批次三）

`ROOM` 基类冗余 `replace_program(ROOM);` 自崩溃地雷（详见 AGENTS.md
§7.100）：4430 处命中，其中 `d/huangshan/banshan.lpc` 是本项目已见
过多次的"同一个 `create()` 里两处独立冗余调用"形状（`setup()` 前
后各一次），两处均删除。自带建房工具 `clone/misc/roommaker.lpc` 的
字符串拼接模板同样修复。

`git diff --stat`：4428 files changed, 1 insertion(+), 4430 deletions(-)，
与预期精确吻合。

验证：`build-debug` 驱动真实冷启动，端口 40037 正常监听。既有管理
员账号 `fluffos`（登录密码为 `Mud@2026`，与原始注册记录的
`test1234` 不同，二者都在 NOTES 中留档过）登录，`目前权限：(admin)`
确认，车马店→南大街→车马店多房间走访无误，`quit` 干净退出，全程
无新增 "cannot replace"/"cannot bind" 日志行。

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

`scripts/lpc_fix_negative_ranges.py`: 4 line(s) in 1 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators (opener line, case)

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 2 more block(s) repaired: 2 where the text sits on the opener's line (`@LONG   text...LONG`, the newlines were lost): `open/task1/huodu.lpc`, `d/city/task1/huodu.lpc`.

## 深度功能测试（§10.7，2026-10-05）— 任务表里的 `.c` 路径与任务守护进程的防护

`scripts/lpc_dynamic_rows.py`：`quest/dynamic_location` 里 4141 行写的是原档案的 `.c` 路径。转档时文件已改名 `.lpc`，而显式后缀按原样解析，`load_object("/d/x.c")`、`new("/d/obj/quest/x.c")` 返回 0 且不报错（KB 03 §4.2，KB 06 §7.220），所以 `adm/daemons/questd.lpc` 读到的每一行都加载不出来：随机任务和任务物品从未生成，在 `create()` 里直接对结果调用 `tar->set()` 的版本还会崩溃，连带加载它的 cron 守护进程和 `give` 的任务钩子。这些行已改为 `.lpc`。
`scripts/lpc_dynamic_quest_guard.py`：1 处 `spread_quest()` 调用（`init_dynamic_quest()` 的循环里）包进 `catch()`，缺失的任务物品或编译不过的房间只跳过那一个任务，守护进程照常加载、其余任务照常生成；`cmds/std/look.lpc` 夜间检查的 `!present("fire", this_player())` 前加 `objectp(this_player()) &&`（房间 `reset()` 销毁物品时 `/feature/move.lpc` 的 `remove()` 会调用 `look_room()`，此时没有 this_player()，`present(…, 0)` 报 `Bad argument 2 to present()`）。
验证：`adm/daemons/questd.lpc`和 cron 守护进程在新进程里加载（HEAD 一次，工作树三次，选房是随机的）：HEAD 通过 2 个，工作树三次分别通过 2、2、2 个（共 2 个），无回退。
验证：改动过的 `adm/daemons/questd.lpc`、`cmds/std/look.lpc` 在新进程里加载，HEAD 通过 2 个、工作树通过 2 个（共 2 个），无回退。

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `inherit/room/room.lpc`：`make_inventory()` 用 `catch()` 包住 `new(file)`，做不出来就返回 0；`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-06）— 编译警告整理

`scripts/lpc_warnings.py xiakexing100 --fix`：无用局部变量 1847 个、`varargs` 7 处、转义 34 处、`nosave` 函数 30 个改 `protected`，共改动 879 个 `.lpc`。这些文件在 HEAD 与工作树分别加载（新进程）：867 -> 867 通过，无回退；`scripts/lpc_audit_removed_locals.py HEAD` 的 16 条候选都是声明被重建（仍在用的名字保留）或同名的 efun 调用（`time()`）。启动时警告 505 -> 0；新进程启动后登录界面（侠客行时间与农历日期、名字校验、新人物确认）正常。

## 深度功能测试（§10.7，2026-10-07）— 空的 `if (current_water == 0) {}`

3 个房间的 `valid_leave()` 里有一行什么也不做的 `if (current_water == 0) {}`（编译警告 `Expression has no side effects`），删去，行为不变：`d/xingxiu/nanjiang2.lpc`、`d/xingxiu/nanjiang3.lpc`、`d/xingxiu/shanjiao.lpc`。

## 深度功能测试（§10.7，2026-10-08）— `.lpc` 后缀的定宽切片

`.c` 改名 `.lpc` 时只改了字符串没改切片宽度：`f[<2..] == ".lpc"` 拿两个字符比四个字符，永远不成立（`!=` 永远成立），按后缀筛文件、去后缀的代码因此从不运行或截成 `x.l`（KB 06 §7.238）。`scripts/lpc_lpc_suffix_slice.py --apply` 改了 5 处比较、2 处去后缀（如 `clone/npc/qingyun.lpc`）；改动的文件 HEAD 与工作树分别加载（新进程），无回退。

- 2026-10-10：`/d/wudujiao/mishi.lpc` 的技能判断用按位 `&` 连接两个比较（如 `tjss > 10000 & taoism > 10000`），改为逻辑 `&&`。两边都是 0/1 比较结果，行为不变，只是写法纠正。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 12 处，返回类型/原型 34 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 0 个，只在 #if 分支用的声明移进分支 0 个文件；改动 36 个文件，HEAD 与工作树各载入一次无回退（36 objects; HEAD PASS 36, tree PASS 36; regress 0; newly loading 0），这些文件的警告 47 -> 0。

## 深度功能测试（§10.7，2026-10-11）：钱塘潮颜色

- `adm/daemons/event/qiantang.lpc`：`"…十分壮观。\n"; NOR;` 分号把 `NOR` 隔成独立语句，颜色不复位；改为 `"…" NOR;`。载入无回退。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查（批 3）

- `daemon/skill/*-archery.lpc` `practice_skill()`：`(: throw_weapon :);` 只造函数指针不调用（练习本就不该射箭），删去。
- 改动的对象 HEAD 与工作区都能载入，无回退。

## 深度功能测试（§10.7，2026-10-11）：dns_master 空 if

- `adm/daemons/network/dns_master.lpc` `query_services()`：`if (! (mud_svc[mud]["tell"/"finger"] & SVC_KNOWN)) {` 里只有 `#if PREF_X & SVC_TCP … #endif`，选项关闭时 if 体为空（“无副作用”警告）；把 `#if`/`#endif` 挪到 if 外面（KB 04 §6.10，2026-10-07 那次扫描漏掉了 `! (` 带空格、大括号另起一行的写法）。载入无回退。

## 深度功能测试（§10.7，2026-10-11）：dns_master 空 if

- `adm/daemons/network/dns_master.lpc` `query_services()`：`if (! (mud_svc[mud]["finger"/"tell"] & SVC_KNOWN))` 块里只有 `#if PREF_X & SVC_TCP … #endif`，选项关闭时 if 为空（“无副作用”警告报在下一句）；把 `#if`/`#endif` 挪到 if 外面（KB 04，2026-10-07 那次扫描漏了 `! (` 加括号换行这种写法）。载入无回退。

## 深度功能测试（§10.7，2026-10-11）：铁掌山房间描述

- `d/tiezhang/pingtai.lpc`、`wmfeng.lpc`、`wztang.lpc`：完整描述后孤立的 `"\n";` 删去（无可见变化）。载入无回退。

## 深度功能测试（§10.7，2026-10-12）：黑木崖老者

- `d/heimuya/npc/laozhe.lpc` `init()`：残留调试行 `sprintf("%s \n", what);`，`what` 是对象，本驱动 `sprintf` 的 `%s` 遇对象报错，进房间时 `init()` 每次中断、招呼从不执行；删去（与 fys 同）。

## 编译警告收尾（2026-10-12）

`scripts/toolkit_fix.sh` 一轮加手工收尾，能编译的文件警告清零。改动的 34 个对象 HEAD 与工作树各载入一次：HEAD PASS 32，tree PASS 33，regress 0，新载入 1（`laozhe`）。

- 冗余继承 15 处（`lpc_diamonds.py`：`open/task1/*`、`open/xiangyang/npc/*` 的 NPC 又直接继承一遍基类已有的 mixin；`shenzhao-jing`、`taixuan-gong`、`douzhuan-xingyi/xingyi`）。`d/city/pai9room.lpc` 在 `inherit ROOM` 前多写了 `inherit F_CLEAN_UP`，删去（§7.240）。
- `clean_up()` 两条路进来（`F_SSERVER` 与 NPC/SKILL/ROOM 基类都继承 `F_CLEAN_UP`）：`d/death/god1`、`d/yixing/npc/bangzhong`、`kungfu/skill/{bixie-jian,love-sword,taiji-jian}` 用 `lpc_name_winner.py` 写出驱动本来就选的那一个。
- `d/heimuya/npc/laozhe.lpc`：`command("give yancao to", me)` 给单参数 efun 传了两个参数，是编译错误，这个老者从来载不进来；同族其它库都已注释掉这一行和白克隆一个 `yancao` 的那行，这里照删。
- `open/xiangyang/task/guo.lpc` 同时 include `zzzjob.lpc` 和 `teamjob.lpc`，两者各声明一份逐字相同的 `names` 表；两处都加 `#ifndef XIANGYANG_TASK_NAMES` 防重。
- `d/yixing/doc/info_{store,biao,guest}.h` 经 `bangzhu_duty.h`/`guanjia.h` 被同一文件 include 两次，加 include guard。
- 宏重定义：`shuyuan2/3` 的 `STORY_DIR`（`globals.h` 里是故事守护的目录）、`clxiaoting`/`bangling` 的 `BANGZHU`、`biaotou` 的 `BIAOHUO`（`changle.h` 已定义），本地 `#define` 前加 `#undef`。`d/city/daxiaoroom.lpc` 注释块里的嵌套 `/*`。
- 未改：`d/yixing/npc/bangzhu.lpc` HEAD 就编不过（`doc/set_bang.h:83` 语法错误），与本轮无关。

- 2026-10-12：`open/xiangyang/task/teamjob.lpc` 的组队任务用 `names[0][random(40)]` 选地点，而这张表只有 34 个地名，`random()` 落到表外时数组越界报错、任务中断。改成 `random(sizeof(names[0]))`（shenmo `u/stey/newjob/teamjob.lpc` 同类）。HEAD 与工作树各载入一次，regress 0。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。9 个文件 12 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）；`x op= 浮点` 先把浮点转成整数再运算（系数小于 1 时 x 直接变 0），改为 `x = to_int(x op ...)`：`/kungfu/skill/bahuang-gong/powerup.lpc`（`skill *=`）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。
- 2026-10-14（同一次重扫，手工部分）：
  - 36 个技能文件的 `int power_point()` 返回 1.1–1.5 的浮点（含按内功等级分支的写法），经 `int` 返回一律被截成 1，改为 `float`。
  - `adm/daemons/combatd.lpc` 用到这个值：
    - 防守时读进 `float dpower`，限定在 1–1.5，乘到防御等级上，这里原本就是浮点写法。
    - 进攻时原写 `damage *= (int)SKILL_D(...)->power_point(me)`。`(int)` 对浮点只是编译期标注，不做转换，`damage` 会在运行时变成浮点。现改为 `damage = to_int(damage * ...)`。
  - **玩家可见**：带威力系数的武功和轻功按原设计的 1.1–1.5 倍计算伤害和防御。原先在本驱动下系数一直被截成 1。
  - `d/city/daxiaoroom.lpc` 去掉注释里嵌套的 `/*`；`mudlib/testsuite/tmp_eval_file.lpc` 补 `return`。

- 2026-10-14：1 个文件因 `Illegal to inherit after defining global variables` 整份不编译：FluffOS 要求所有 `inherit` 写在第一个全局变量之前，MudOS 不管。`scripts/lpc_fix_inherit_order.py` 把写在 `inherit` 之前的全局变量（以及声明全局变量的头文件的 `#include`）挪到最后一个 `inherit` 之后（KB 04 §6.3）。

## 内力/精力当作伤害种类（2026-10-15，KB 06 §7.241 第二类）

本库 `feature/damage.lpc` 的 `receive_damage()` 不接受 `jingli`/`neili`/`force` 等种类，`me->receive_damage("jingli", 30)` 之类在练功、绝招、吸取时报 `F_DAMAGE: 伤害种类错误`。5 处改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py` 第二步）。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。2 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

另有 1 个文件（绝招、状态、物品、NPC 等，不限于 kungfu/skill）来自 gin/kee/sen/force 体系，同样按 kee→qi、gin/sen→jing、force→neili 改名（`scripts/lpc_port_es_props.py --any-file`）。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。18 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。


## 技能按另一门武功的等级取招（2026-10-15，KB 06 §7.243）

这些技能文件是从别的武功复制改名来的，`query_action()` 仍用原武功的等级查招式表：只会本技能的人等级为 0，取不到招，每次出招都报错。改为读本技能自己的等级（`scripts/lpc_fix_action_level.py`）：`boruo-strike`、`cibei-blade`、`huashan-jianfa`、`huashan-zhangfa`。

## 空手使用兵器绝招（2026-10-15，KB 06 §7.246）

`perform` 指令允许直接点名招式（如 `perform stick.ban`），这些绝招读了 `me->query_temp("weapon")` 却从不检查，空手时 `weapon->name()` 报错（有的已先扣了内力）。在赋值后补 `if (!objectp(weapon)) return notify_fail("你必须手持兵器才能使用这一招。\n");`（`scripts/lpc_fix_perform_weapon.py`）：`taiji-jian/raozhi`。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`five_poison`→`five-poison`（`/clone/medicine/poison/redyao`、`/clone/medicine/poison/shenxiandao`、`/clone/medicine/poison/whiteyao`、`/clone/medicine/poison/wuxing`、`/clone/medicine/poison/yellowyao`）；`jinwu-dao`→`jinwu-daofa`（`jinwu-daofa`）。

## family 映射内联取下标（2026-10-15，KB 05 §7.30）

`ob->query("family")["master_name"]`、`me->query("family")["family_name"]`（泥潭式为 `query("family", ob)[...]`）直接对门派映射取下标：没有门派的人（新玩家、叛师者、大多数 NPC）在 NPC 的打招呼和问话、绝招的门派判断、房间的 `valid_leave` 里报 `Value being indexed is zero`，而不是得到拒绝。3 处（3 个文件）改为 dbase 路径查询 `query("family/master_name")`：有门派时值相同，没有时得 0；原有的判断照常生效（`scripts/lpc_fix_family_index.py`）。给映射赋值的写法未动。


## 达摩剑「达摩三绝剑」、反两仪刀「华岳三神峰」每次报错（2026-10-15，KB 06 §7.246）

两个绝招都声明了 `object weapon, ob;` 却从不给 `ob` 赋值：结尾 `if (!ob->is_fighting(me))` 在内力扣完后报错，`sanshen` 的三刀甚至都砍向 `ob`（0）。改为 `target`，并先判断 `objectp(target)`（循环里可能取不到对手）。

## 去掉的预定义宏 `SAVE_EXTENSION`（2026-10-18，KB 04 §6.11）

老版 MudOS 给每个 LPC 对象预先定义了 `SAVE_EXTENSION`（`".o"`）；FluffOS 的 ChangeLog（COMPAT_BUSTER 一条）把它删了，改用 `__SAVE_EXTENSION__`。本库没有自己 `#define` 这个宏，用到它的文件一律 `Undefined variable 'SAVE_EXTENSION'`，整个对象载入不了。改成 `__SAVE_EXTENSION__`（`scripts/lpc_fix_predefined_macro.py`）：`d/jiaxing/npc/tang.lpc`、`d/jiaxing/npc/tang3.lpc`、`d/quanzhou/npc/tang.lpc`、`d/quanzhou/npc/tang3.lpc`、`include/net/ftpdsupp.h`。`tang3`/`tang`/`meng-zhu` 是武林盟主一类的 NPC，原来一个都载入不了。改后用 `lpcc` 逐个载入这些对象：4 个通过。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库目前没有对象设了缺失的武功；三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。（`scripts/lpc_guard_set_skill.py`）

## 宠物商人 `d/city/npc/oldman` 的变量叫 `class`（2026-10-18，KB 04 §6.14）

`string *class = ({ ... })` 的 `class` 在 FluffOS 里是保留字（结构体），`syntax error, unexpected L_CLASS`，老头载入不了。变量改叫 `pet_class`（7 处）。载入：通过。

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 26 处、18 个文件：`shaolin-shnfa`→`shaolin-shenfa`（5 处）、`pixie-jian`→`bixie-jian`（4 处）、`choushui-zhang`→`chousui-zhang`（4 处）、`pixie-sword`→`bixie-sword`（3 处）、`tiaji-jian`→`taiji-jian`（2 处）、`lingbo-weibu`→`lingboweibu`（2 处）、`shenxingbaibian`→`shenxing-baibian`（1 处）、`jingding-zhang`→`jinding-zhang`（1 处）等共 12 个名字。（`scripts/lpc_fix_skill_names.py`）

## set_name 的 id 参数传成字符串（2026-10-19，KB 06 §7.260）

`set_name("海口大碗", "bowl");` 把物品的 id 写成了字符串，本库的 `set_name(string name, string *id)` 要的是数组，驱动在编译时报 `Bad type for argument 2 of set_name ( string * vs string )`，整个物件载入不了；旧驱动不检查参数类型，字符串里照样找得到这个词，物品能用 id 称呼。改成 `({ "bowl" })`，共 2 个文件：`/d/baituo/npc/obj/bowl.lpc`、`/d/baituo/obj/bowl.lpc`。（`scripts/lpc_fix_set_name_id.py`）

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 被注释吞掉的 inherit / include（2026-10-19，KB 06 §7.274）

`/d/shaolin/npc/obj/heisuo.lpc`：`#include <weapon.h>`；`/d/shaolin/obj/heisuo.lpc`：`#include <weapon.h>`。这些指令接在上一行 `//` 注释的末尾（档案里丢了换行），成了注释的一部分，驱动看不到：缺 `inherit` 的技能报 `Undefined function offensive_target`，缺 `#include <weapon.h>` 的兵器报语法错误。`scripts/lpc_fix_swallowed_directive.py` 把换行放回去。载入检查 2 个文件，2 个原来编译不过、现在载入，没有退步。

## 标准整理轮（2026-10-19，`scripts/toolkit_fix.sh`）

本库在新驱动下重扫，机械修复：2 个未使用的局部变量。修后与 HEAD 逐个物件对比载入，没有退步。

## 载入不了的零碎文件（2026-10-19，KB 03 §4.7、KB 04 §6.10）

- `d/shenlong/jushi.lpc`、`sea.lpc`、`sea2.lpc` 里 `me->name() + "\241\243\n"` 的 `\241\243`（GBK 的「。」写成八进制转义，旧驱动把这两个字节原样发给 GBK 客户端）改成「。」；新驱动报 `Invalid UTF8 codepoint in string literal`，三个房间（共 4 处）载入不了。

逐个载入与 HEAD 对比，没有退步。

## 标准整理轮，第二轮（2026-10-19，`scripts/toolkit_fix.sh`）

本库在新驱动下重扫，机械修复：1 个未使用的局部变量。修后与 HEAD 逐个物件对比载入，没有退步。

## 手工收尾（2026-10-19，KB 04 §6.10）

- `d/city/npc/oldman.lpc`：宠物店老人的 `int *weight = ({ … })`（宠物重量表）和 NPC 基类 `feature/move.lpc` 的 `nosave int weight`（物件自己的重量）同名（`Redeclaration of global variable 'weight'`），驱动给了它第二个变量；改名 `pet_weight`（`nosave`，3 处，`scripts/lpc_rename_ident.py`），行为不变。

逐个与 HEAD 对比载入，没有退步。

## 帮派文件里丢掉的引号（2026-10-19，KB 03 §4.6）

- `d/yixing/doc/set_bang.h` 第 82、84 行：两句帮主的话，最后半个字连同结尾的引号一起丢了（`…景仰之情<乱码>);`），下一行的开头引号把它闭合，后面的汉字被当成代码（`Illegal character 0xe8`），宜兴帮主 `d/yixing/npc/bangzhu.lpc` 从来载入不了。字串照 nt7 里完好的拷贝补回（`犹如滔滔江水连绵不绝。`、`帮主的敬仰犹如黄河泛滥一发不可收拾。`），引号补上。
- 同一文件第 45 行 `level = ceil( pow( … ) ) * 4 / 5;` 把浮点数存进 int，补 `to_int()`。
- `d/yixing/doc/info_store.h`、`info_biao.h`、`info_guest.h` 没有重复包含的保护（本库其他拷贝有）：`bangzhu.lpc` 自己 include 一遍，`bangzhu_duty.h` → `guanjia.h` 又 include 一遍，四张表被声明两次；加上 `#ifndef __YIXING_INFO_*_H__`。`bangzhu.lpc` 同时继承 `NPC` 和 `F_SSERVER`，两条路都带来 `clean_up()`（`clean_up() inherited from both …`），写出 `int clean_up() { return sserver::clean_up(); }`，行为不变。

载入 `d/yixing/npc/` 的 bangzhu、biaotou、bangzhu2、cl_bei：HEAD 通过 3 个，现在通过 4 个（`bangzhu.lpc` 现在载入），没有退步。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。改动：`/d/baihuagu/yangfeng.h`（1 处）、`/d/gumu/liangong1.lpc`（1 处）、`/d/mingjiao/shanmen.lpc`（1 处）。另有 `/d/city/npc/majiang.lpc`（2 处） 的条件下面做的是别的事（`==` 和 `||` 也可能是本意），保持原样。

## 深度功能测试（§10.7，2026-10-20）：实机指令扫描后同步 xkx100 的发现（KB 08 §10.16）

xkx100 的实机指令扫描（见 `libs/xkx100/NOTES.md`）里和本库代码相同的几处，同样修复：`cmds/usr/boss.lpc`（`/open/shit.txt` 不存在，`write(0)`）、`cmds/usr/news.lpc` 和 `inherit/misc/bboard.lpc`（公告板房间 `/u/qingyun/workroom` 不存在）、`cmds/wiz/clone.lpc`（`if (msg = "none")`）、`cmds/wiz/cip.lpc`（无参数）、`cmds/wiz/w_lian.lpc`（`__DIR__ "enable"` 指向不存在的 `/cmds/wiz/enable`）、`clone/quest/*` 与 `clone/haojie/shashou.lpc` 的 `random_move()`（`find_object(dest)->query("no_fight")`，目的地没载入时对 0 调用）、`adm/daemons/disaster.lpc`（`lead->name()`，领头玩家离线时报错、戒严不解除）、`cmds/wiz/callouts.lpc`（`call_out_info()` 只有 3 项）。`exit.lpc` 的 `a == 1` 和 `npcd.lpc` 的 `string dest` 本库 7 月就是对的。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 16 处）。改动：`/d/changan/npc/majiang.lpc`（3 处）、`/d/changan/npc/matong.lpc`（3 处）、`/d/changan/puke-room.lpc`（4 处）、`/d/city/npc/matong.lpc`（3 处）、`/d/city/shufengguan.lpc`（1 处）、`/d/hangzhou/npc/meipo.lpc`（1 处）、`/quest/weixiaobao.lpc`（1 处）。

## `callouts`：`sizeof(info[i]) == 4` 把每一行都挡掉了（2026-10-20，KB 06 §7.287）

驱动的 `call_out_info()` 每项只有 3 个元素，输出行前的守卫 `if (sizeof(info[i]) == 4)` 永远不成立，指令只打印表头。改为 `>= 3`。改动：`/cmds/adm/callouts.lpc`（1 处）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/single/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## sefun `cat()`：缺文件时 `write(0)` 报错（2026-10-20，KB 06 §7.297）

`void cat(string file) { write(read_file(file)); }`：文件不存在（压缩包没带的欢迎/公告文件，或只有运行中的 mud 才会写的日志）时 `read_file()` 回 0，`write(0)` 在本驱动里报 `Bad argument 1 to receive()`，调用者（登录对话、`cat` 指令）被中断；老驱动什么也不打印。改成 `write(read_file(file) || "");`（`scripts/lpc_fix_cat_unchecked.py`）。改动：`/adm/simul_efun/file.lpc`。

## 翻页器 `start_more(read_file(...))`：文件缺失时 `explode(0)`（2026-10-20，KB 06 §7.300）

东方故事系的翻页器 `void start_more(string msg) { ... explode(msg, "\n") ... }` 被这样调用：`start_more(read_file(HELP_DIR + "help/topics"))`、`start_more(read_file(NEWS))`。压缩包没带的文件使 `read_file()` 回 0，`explode(0, ...)` 在本驱动里报 `Bad argument 1 to explode()`（不带参数的 `help` 指令就是这样出错的），老驱动把 0 当空文本。在 `start_more` 开头加了 `if (!stringp(msg)) return;`（`scripts/lpc_fix_start_more.py`）。改动：`/feature/more.lpc`。

## `get_config(__MUD_PORT__)` 经旧版 `runtime_config.h` 得到字符串（2026-10-20，KB 06 §7.302）

本库的 `include/runtime_config.h` 是老 MudOS 的编号（整数设置从 15 起，本驱动从 256 起），`get_config(__MUD_PORT__)` 读到的是另一项设置（字符串），`(int)` 又只是编译期标注，于是 `socket_bind(fd, LOCAL_PORT())` 报 `Bad argument 2 to socket_bind()`，版本守护进程 `port = get_config(__MUD_PORT__) + VERSION_PORT` 是字符串相加。头文件自己的注释写明 `get_config(__MUD_PORT__) == __PORT__`，所以代码里的这个调用（连同外面的 `(int)` / `to_int()`）改成了驱动的预定义 `__PORT__`（`scripts/lpc_fix_mud_port.py`）。改动：`/include/getconfig.h`（1 处）。

## `d/luoyang/obj/xiang.lpc`：`chuangli` 先 `explode(read_file("/log/PARTY"))`（2026-10-20，KB 06 §7.326）

关帝像的 `chuangli`（`kaibang`）指令在检查年龄和经验之前就读 `/log/PARTY`，那是运行中的 mud 记录已创立帮派的文件，全新的树里没有，`explode(0)` 报 `Bad argument 1 to explode()`：任何人敲 `chuangli 什么` 都是系统错误，而不是“你还嫩着呢”。改成 `file = read_file("/log/PARTY") || "";`（空串的 `explode` 是空数组）。xkx100utf8 和 nt7 是 gitlink 库（fluffos-org 上游），同一行在那里没有改。加载检查各 1/1。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库有 1 个 NPC 文件写成 `set("chat_msg", ({ }))`（或 `chat_msg_combat`）并带正的 `chat_chance`（例如 `/d/city/npc/lulixian.lpc`），每次心跳有 `chat_chance`% 的概率 `random(0)` 为 0、`msg[0]` 报 `Array index out of bounds`（驱动捕获，心跳继续，但每次一条运行时错误），这个 NPC 在内存里就一直发生。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/inherit/char/npc.lpc`（共 1 个文件）。

## 巫师命令不带参数时对 0 调用 efun（2026-10-21，KB 06 §7.336）

巫师（管理员）把命令敲成不带参数时，驱动把 0 传给字符串参数；下面的命令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`，这条指令从来没有用过。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py` 在第一处使用参数的语句前加守卫：没有 `help()` 的是 `return notify_fail("…\n");`。改动（1 个文件，括号里是接住 0 的 efun）：`/cmds/wiz/inittask.lpc`（`sscanf`）。加载检查 HEAD 与工作树对照，没有退步。
