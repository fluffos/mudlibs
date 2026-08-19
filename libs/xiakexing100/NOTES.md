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
