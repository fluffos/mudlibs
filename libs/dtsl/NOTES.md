# dtsl.rar → `dtsl`

- Archive: `archives/dtsl.rar` (3.4MB — "大唐双龙传"/"Twin Dragons of the
  Tang Dynasty", same "simple"/东方故事-ish lineage as lib #1
  (shzs) — `adm/obj/master.c`+`adm/obj/simul_efun.c` layout).
  **No config file shipped in this archive at all** — reused lib #1's
  `config.cfg` as a template (same lineage, same directive shapes) rather
  than reconstructing one from scratch.
- Port: **40008**.

## Status: DONE — boots clean, playable over telnet

Booted with **zero fixes needed on the first attempt** (matching lineage
to lib #1, and lib #1's proactive checks — no `load_object` in
`valid_read`/`valid_write`, `get_root_uid()` present — all held here too).

## What was fixed (all from the lpcc sweep, not the boot path)

1. Encoding: 6870 converted, 327 already UTF-8/ASCII, 377 skipped binary,
   4 lossy. `.c`→`.lpc`: 6521 files, 1037 refs auto-fixed. `static`→
   `nosave`: 87 files.
2. `F_UNIQUE` macro was referenced (`inherit F_UNIQUE;`) by ~91 clone
   item files but never `#define`d in `include/globals.h`, despite
   `feature/unique.lpc` (the file it should point to) existing —
   added `#define F_UNIQUE "/feature/unique.lpc"` alongside the other
   `F_*` macros. Fixed all ~91 files' "unexpected L_IDENTIFIER" errors
   in one shot (misleadingly, the error pointed at the NEXT line's
   `inherit F_UNIQUE`, since the undefined macro parses as a bare
   identifier where a string/path was expected).
3. 6 `clone/weapon/*.lpc` legendary-weapon files (`jin-sjian`, `shizi`,
   `feihuangshi`, `jinhua`, `sjian`, `feidao`) redundantly
   `inherit COMBINED_ITEM;` directly AND via `inherit THROWING;` (which
   already inherits `COMBINED_ITEM` itself) — a diamond that this driver's
   stricter `nomask` conflict detection rejects (`Illegal to redefine
   'nomask' function '_query'/'_delete'/'_set'/'weight'`), where an older/
   more permissive driver apparently just deduplicated it silently. Fixed
   by deleting the redundant top-level `inherit COMBINED_ITEM;` line (kept
   the one reached transitively via `THROWING`). **Gotcha while fixing**:
   these files use CRLF line endings — a `sed '/^inherit X;$/d'` silently
   no-ops on a line ending `;\r\n` because `$` doesn't absorb the `\r`;
   needed `/^inherit X;\r?$/d`.
4. `clone/weapon/sm_ding.lpc` (7th file in the same cluster) has a
   DIFFERENT, unrelated problem: `#include "/inherit/item/embed.h"`,
   which doesn't exist anywhere in this archive — genuine missing content,
   not fixed (not fabricating a header).

## Known remaining issues (documented, not fixed)

- 369 lpcc-sweep failures total (before the fixes above; not re-swept
  after — expect notably fewer on a re-run given F_UNIQUE alone likely
  accounted for close to a third of them). Not otherwise triaged past the
  categories above given time constraints.
- 3 `#include`-fragment false positives (`adm/simul_efun/{message,math,
  object}`, AGENTS.md §6b) plus one player-directory WIP file
  (`/u/fengfei/object`) under "Invalid simulated efunction override" —
  not investigated further (low priority, personal/test content).

## How to run

```
cd libs/dtsl
~/src/fluffos/build-debug/src/driver config.fluffos
python3 ../../scripts/mudclient.py 127.0.0.1 40008 --timeout 10 --send "" --send "look" --send "quit"
```

## Retroactive fix (QA re-verification pass, 2026-07-23): log_error() compile-warning spam (AGENTS.md §15af)

Found during a routine re-verification pass (full registration + post-login
`look`/`score`/`quit` test): `adm/obj/master.lpc`'s `log_error()` showed the
config's scary `default error message` ("你发现事情不大对了，但是又说不上
来。") to the connected (non-wizard) player for **every** compile-time
diagnostic funneled through `APPLY_LOG_ERROR` — including harmless "Unused
local variable" **warnings** triggered by the first lazy compile of an
ordinary room/NPC the player merely walked into (e.g. `/d/job/...`'s
`job_money.h`-included files, `/cmds/std/look.lpc`, etc). In a real
registration+play session this fired dozens of times per minute of walking
around — same bug class already documented and fixed on `wuhanzhan`/
`shenzhou` (§15af). Fixed identically: only show the default-error message
when `message` does NOT contain the substring `"warning:"` (still logs every
diagnostic to the per-file log either way; only the in-band player-visible
alarm is gated). Re-verified with a fresh registration (real name `秦北`)
followed by `look`/`score`/`quit` — zero spam, zero real `error:` lines in
`debug.log`.

## Post-hoc fix: UTF8-native is_chinese/registration (AGENTS.md §15h)

Applied in a later batch pass across the whole project: `is_chinese`/`is_chinese2`
in the shared `chinese.lpc` simul_efun fragment used GBK byte-range checks that
silently never match real Chinese text once strings are UTF-8 (this driver's
`str[i]` returns a Unicode codepoint, not a GBK byte). This broke character
registration specifically -- any real Chinese name was rejected. Fixed the
range check to test the CJK Unicode block instead, and halved the
GBK-byte-calibrated length bounds in `check_legal_name` to match. See
AGENTS.md §15h for the full writeup; confirmed via a real interactive
registration test (Chinese surname + given name reaching the next prompt).

## Re-verification pass (2026-07-23): driver rebuild + LPC formatter + WASM build

- **Formatter**: ran `format-corpus.mjs` over all of `work/` (6,521
  files, 6,369 written/reformatted, 29 already-clean, 123 refused with
  an error — expected on legacy code, not chased individually).
- **Native retest against rebuilt driver** (`build-debug/src/driver`,
  rebuilt from latest upstream master): clean boot, zero fatal errors in
  `debug.log`. Full registration re-verified end-to-end on the
  now-reformatted source with a fresh real Chinese name (`秦诺`, ID
  `qinnuo`, following the same ID→confirm→Chinese name→password (5-8
  chars)→email→gender→4-stat-point-allocation flow as sibling
  `dtsl2`) reaching the actual game world (大唐学院 starting
  room); `look`/`score` both produced correct output (full 人物档案
  stat card rendered correctly), `quit` exited cleanly. One background
  `*Read access denied.` runtime error appeared during this run, same
  pre-existing job-daemon content gap already documented in
  `dtsl2`'s NOTES (`adm/daemons/jobmond.lpc`'s periodic
  job-posting logic trying to move an NPC into a room via a chain that
  hits an ACL denial) — fires from that daemon's own independent
  heartbeat, unrelated to the registration/look/score/quit path under
  test, not a regression. No regressions from the reformat or the fresh
  driver build.
- **WASM build**: preload completes with only the expected non-fatal
  `sockets`-package gap (`adm/daemons/ftpd.lpc`/`include/net/
  ftpdsupp.h` and `adm/daemons/network/dns_master.lpc`'s
  `socket_create`/`socket_bind`/`socket_close`/`socket_address` →
  `Undefined function`, caught non-fatally, `Initializations complete.`
  still printed). Like `dtsl2`, this lib's login path does
  **not** gate on `query_ip_number()`'s format, so a full registration
  proceeded all the way through under WASM too: ID `qinao` → Chinese
  name `秦傲` → password → email → gender → stat allocation → reached
  the actual game world (大唐学院), `look` produced correct room
  output, `quit` exited cleanly. **This lib is confirmed fully playable
  under WASM**, not just "boots."

## WASM-enablement pass (2026-07 standard: loopback-allow, admin seed)

Same "大唐双龙" simple-lineage shape as sibling `dtsl2`
(byte-identical `adm/daemons/band.lpc`/`sited.lpc`) -- checked directly
rather than assumed:

- `adm/daemons/band.lpc` `is_banned()` (~line 39): loopback bypasses the
  ban-site regexp scan. Fail-closed: only an exact `127.0.0.1`/
  `localhost`/`127.`-prefix match bypasses; a malformed address falls
  through to the original scan. Called from `adm/daemons/logind.lpc`'s
  `logon()` (~line 97) with `query_ip_name(ob)`.
- No live `uptime()` startup-grace gate.
- No live per-IP throttle: `get_id()`'s `ip_cnt>8` cap (~line 222) is
  entirely commented-out dead code in the raw archive, same as
  `dtsl2` -- nothing to patch.
- `adm/daemons/sited.lpc`'s `is_valid(id, ip)` has the same dangling-
  else bug as `dtsl2` (loopback+non-wizard is rejected,
  every non-loopback IP unconditionally passes, the `valid_login`
  whitelist is unreachable) -- but it's dead code here too, only called
  from the unrelated `cmds/std/toupiao.lpc` voting command, so it does
  not gate logins. Left unpatched/undocumented-further for the same
  reason as `dtsl2`.

Admin account: id `fluffos` / `Mud@2026` / 浮浮, registered through the
normal flow (id -> confirm y -> Chinese name 浮浮 -> password x2 ->
email skipped -> gender m -> stat allocation `20 20 20 20` -> confirm
yes), granted `(admin)` via `adm/etc/wizlist` (`fluffos (admin)` line
added, existing `fengfei`/`kouzhong`/`ttj`/`zhujiepo` entries kept)
before registration, so wizard status was active immediately
("作为巫师，你可以迅速离线" shown on the very first `quit`). Verified
on a SEPARATE re-login: password accepted, `update /d/newbie/door`
succeeded ("重新编译 /d/newbie/door.lpc：成功！") -- unlike sibling
`dfgs2`, this lineage's restore path has no permission bug,
re-login just works. Save files (`data/user/f/fluffos.o`,
`data/login/f/fluffos.o`) are plain untracked paths, not covered by any
`.gitignore` pattern -- a normal `git add libs/dtsl/` picks them up, no
force-add needed.

Retest: fresh normal registration (id `ceshijiu`, name 秦鹏, female)
reached 大唐学院, look correct, clean quit. debug.log clean across both
driver runs this pass (only expected boot-time config dump and
SIGTERM-on-kill lines -- the visible "编译时段错误" warning spam during
fluffos's OWN session is expected/correct: this lib's `log_error()` fix
(see above, 2026-07-23 pass) shows full diagnostics to wizards and only
gates the generic scary message for non-wizards, and fluffos is a
wizard). Two driver instances started/killed by exact PID; test
character `ceshijiu`'s saves removed afterward (`data/user/c/
ceshijiu.o`, `data/login/c/ceshijiu.o`), `fluffos`'s kept. Note: this
lib's `data/user/`+`data/login/` trees already contained other untracked
leftover test saves (e.g. `q/` shard, from this lib's own earlier
`qinnuo`/`qinao` verification passes documented above) predating this
session -- left untouched as out of this pass's scope.

## 深度功能测试 / Deep functional test (2026-07-24, round two)

First real *playthrough* pass on this lib (all prior passes verified only
registration + `look`/`score`/`quit` + admin login, or watched boot
output). Read `doc/help/newbie` in full first -- it named the
`fight`-vs-`kill` distinction, the `bai`/`skills`(`cha`)/`xue` teaching
loop, and `dazuo`/`tuna` cultivation up front, matching the methodology's
prediction that it's the fastest way to learn the intended path. Played
as an ordinary new player through registration, exploration of the
`d/slwg` (石龙武馆) newbie hall, the lib's own room-scoped `qiecuo` safe-
sparring command, the organic paid-teacher `xue` path (both a failing and
a successful attempt), the `bai`/`apprentice` sect-join mechanism, a real
`sleep`/wake cultivation cycle, a real `quit`, a real prompt net-dead
reconnect, and a real **15-minute** (`NET_DEAD_TIMEOUT`) unclean-
disconnect wait to force the force-quit path, all on the native driver
(`build-debug`). Found and fixed **two** bugs, both new classes for this
project's catalog: a command-dispatch duplication bug (Bug 2, found
first) and, from the mandatory real 15-minute wait, a **critical**
`tell_room()` type-error bug (Bug 1) that disables the net-dead force-
quit safety net entirely and was observed to crash the whole native
driver process outright -- see Bug 1 below for the full story; it is by
a wide margin the more important finding of this pass.

**Test character** (kept, not cleaned up, as representative playthrough
evidence): id `qintian`, Chinese name 秦天 (male), password `Qt12345`.
State: received the newbie 礼官 gift (combat_exp 6000, +1 to all four
attributes), sparred a 弟子 via `qiecuo` at 石龙武馆's 练武场, withdrew
and spent savings on a (gated-out, already-capped) `xue jiao force`
lesson, survived a full `quit`→save→relogin round trip with all of the
above state intact, and was the character used to reproduce and then
re-verify the bug below across a prompt net-dead reconnect, a `sleep`/
wake cycle, and the full 15-minute net-dead force-quit path. Saves:
`work/data/user/q/qintian.o`, `work/data/login/q/qintian.o` (state as of
the pre-Bug-1-investigation clean `quit`, since the later crash meant no
further save occurred for this id). Secondary throwaway characters
created to isolate Bug 2 (`ceyanzc`/测验者, `shuimian`/沉睡) and to
reproduce/verify Bug 1 (`ceyanzc` again, plus `wangce`/网测 and
`zongjian`/总检, and `goumai`/购买者 for the shop-purchase check, all
password `Ab12345`) were left in place rather than risk clobbering
evidence mid-investigation -- their saves are harmless, ordinary
fresh-registration state.

### Bug 1 (CRITICAL, NEW bug class): a 2-argument `tell_room()` call inside `user_dump()`'s net-dead force-quit path crashes with an uncaught runtime error, permanently disabling the 15-minute net-dead force-quit safety net -- and, worse, appears to be the trigger for an actual DRIVER-LEVEL CRASH (full outage) observed live

**File:line of the fix: `adm/simul_efun/message.lpc`'s `tell_room()`
(line 47-54). Directly reached from `obj/user.lpc`'s `user_dump()`
(line 182-183), the `NET_DEAD_TIMEOUT`-driven `call_out` handler that
force-quits a player who never reconnects.**

- **How this was found**: found by doing exactly what AGENTS.md §10.7 /
  the task brief ask for and no faster verification layer would ever
  reach -- net-deading a real character (closing the socket without
  `quit`) and waiting a genuine **15 real minutes**
  (`NET_DEAD_TIMEOUT` = 900s, `include/user.h:10`) for the driver's own
  `call_out("user_dump", NET_DEAD_TIMEOUT, DUMP_NET_DEAD)` to fire, then
  checking `debug.log` and reconnecting -- rather than assuming a prompt
  reconnect test (which this session also did, repeatedly, and which
  never touches this code path at all) was sufficient.
- **Symptom**: `debug.log` showed, for BOTH characters that happened to
  be net-dead past the 15-minute mark at the same real time (`qintian`
  and `ceyanzc`):
  ```
  执行时段错误：*Bad argument 4 to EFUN message()
  Expected: object, array,  Got: int(0).
  程序：/adm/obj/simul_efun.lpc 第 49 行
  呼叫来自：/obj/user.lpc 的 user_dump() 第 182 行 ...
  调用参数：tell_room("秦天断线超过 15 分钟，自动退出这个世界。\n", NULL)
  ```
  A few driver ticks later, reconnecting as either character crashed
  the **entire native driver process** with a fatal C-level abort (not
  an LPC-catchable error) -- `md: debugmalloc: attempted to free
  non-malloc'd pointer ...` inside `dealloc_object()`/`free_svalue()`,
  triggered while indexing a mapping whose value was a destructed
  object reference (`assign_svalue()`'s destructed-object auto-null
  path at `interpret.cc:3792`), captured in the driver's own crash
  backtrace (printed to the driver's redirected stdout at the time --
  not preserved as a repo artifact, this is a description of what was
  observed live, not a file left behind). This took the whole MUD down
  for every connected player, not just the two net-dead characters --
  categorically the most severe finding of this pass, and of this
  project's round-two testing effort to date.
- **Root cause (confirmed for the LPC-level crash; the C-level
  double-free is very likely, but not rigorously proven, to be a
  downstream consequence of the same bug)**: `adm/simul_efun/
  message.lpc`'s `tell_room()` is declared `varargs void tell_room(mixed
  ob, string str, object *exclude)`. The real driver efun it wraps,
  `message()`, types its 4th parameter `void | object | object *` --
  explicitly allowing the argument to be OMITTED (`void`), but NOT
  allowing a bare integer. When a caller invokes `tell_room(room, msg)`
  with only 2 arguments (an extremely common pattern -- grep found 80+
  such call sites across this lib), the unset `object *exclude`
  `varargs` parameter is a real, typed `int` `0`, not "absent" --  and
  `tell_room()` unconditionally forwards it as `message()`'s 4th
  positional argument regardless of whether the caller supplied it.
  Passing an explicit `int 0` where the signature demands
  `void|object|object*` is a genuine type violation that aborts with
  `*Bad argument 4 to EFUN message()`. This is a **shared root cause,
  not one bad call site** (AGENTS.md §6.4's framing) -- it's latent at
  EVERY 2-argument `tell_room()` call site in the entire lib, most of
  which this pass's ~40 minutes of active, varied gameplay apparently
  never happened to exercise live (no other occurrence appeared in
  `debug.log` all session) -- `user_dump()`'s `DUMP_NET_DEAD` case was
  simply the first one this pass's testing actually triggered, purely
  because it's gated behind a real 15-minute wait that no previous
  verification pass in this project's history had ever performed. Once
  triggered from a `call_out`-driven function with no enclosing
  `catch()` (unlike a player-typed command, where the driver's own
  top-level handler catches the error and the visible damage is just an
  ugly line in `debug.log`), the error **aborts the rest of
  `user_dump()` at that exact statement** -- the next two lines,
  `this_object()->enable_player(); command("quit");`, never execute.
  Net effect: **the entire 15-minute net-dead force-quit mechanism was
  completely disabled** -- any player who net-deads and never manually
  reconnects stays alive in server memory, marked `netdead`, forever
  (until server restart), never saved via this path. The subsequent
  driver-level double-free crash was reproduced exactly once, in the
  specific circumstance of TWO different characters both hitting this
  aborted, half-completed `user_dump()` at nearly the same real moment,
  followed immediately by a third connection (a reconnect attempt);
  root-causing the EXACT C-level memory-corruption mechanism would need
  driver-level tooling (ASan/valgrind) out of scope for an LPC-focused
  pass, but the correlation is strong: after applying the fix below and
  reproducing an equivalent scenario (see Verified), the crash did not
  recur.
- **Fix**: only forward `exclude` to the underlying `message()` call
  when the caller actually supplied one:
  ```lpc
  // BEFORE:
  message("tell_room", str, ob, exclude);
  // AFTER:
  if (exclude) message("tell_room", str, ob, exclude);
  else message("tell_room", str, ob);
  ```
  This is the single, root-cause fix point for the whole shared-root-
  cause bug -- it doesn't require touching any of the 80+ individual
  call sites, since the type violation only ever happens inside
  `tell_room()`'s own forwarding call.
- **Verified**: reproduced live at the real, full 15-minute duration
  (native driver, `qintian`+`ceyanzc`, genuine ~16-minute wall-clock
  wait via a foreground-blocking wait, not simulated) -- confirmed the
  exact error above in `debug.log`, then confirmed the driver crash on
  the next reconnect attempt (driver process gone, `ss`/`ps` show
  nothing listening on port 40008, crash backtrace captured in the
  redirected stdout log). Applied the fix, then re-verified with an
  **accelerated but otherwise identical** repro (temporarily changed
  `include/user.h`'s `NET_DEAD_TIMEOUT` from `900` to `20` for testing
  purposes only, restored to `900` immediately afterward and confirmed
  restored -- the LPC logic exercised is byte-for-byte identical
  regardless of the constant's value, only real wall-clock time differs):
  fresh character `wangce`/网测, net-deaded deliberately, waited a real
  25+ seconds, reconnected -- `debug.log` showed NO `Bad argument`
  error this time, `quit.lpc` was lazily compiled (confirming
  `command("quit")` now actually runs), and the following reconnect
  landed in a genuinely fresh login flow (confirming `do_quit()`'s
  `save()`+`destruct()` completed) rather than a stale `netdead`
  reconnect, and the driver process stayed alive and stable throughout
  (`ps`-checked). Also re-ran the full register→explore→`xue`(fail)→
  `quit` smoke test with a
  THIRD fresh character (`zongjian`/总检) after this fix, confirming no
  regression to ordinary gameplay (single-dispatch from Bug 2's fix
  still holds; `quit`/relogin round trip clean). `debug.log` clean
  across every post-fix iteration.
- **Lineage scope**: checked directly -- `dtsl2` and
  `dtslmud` share this exact `adm/simul_efun/message.lpc`
  `tell_room()` implementation and the identical `obj/user.lpc`
  `user_dump()` call site (confirmed via direct file inspection, not
  assumed), so this is **lineage-wide** and, given `tell_room()` is
  such a basic, widely-used primitive, plausibly present in unrelated
  lineages too wherever a `varargs`-optional trailing parameter gets
  blindly forwarded to a stricter-typed efun -- worth a proactive grep
  (`varargs.*mixed|object \*\w+\)\s*\{` in any lib's own `tell_room`/
  `tell_room`-alike wrapper, checked against whether the wrapped efun's
  own signature tolerates `void` for that slot) on any future deep pass
  that reaches a 15-minute wait. Porting the fix to the siblings is out
  of scope for this task (left for the orchestrating session).

### Bug 2 (NEW bug class): every `enable_player()` call beyond the first silently stacks a duplicate command-dispatch sentence, so any FAILING command runs its side effects more than once

**File:line of the fix: `feature/command.lpc`'s `enable_player()`
(~line 79-105). Root cause is distributed across several call sites,
none of which look buggy in isolation: `adm/daemons/logind.lpc`'s
`enter_world()` (~line 554, a direct `user->enable_player()` call,
immediately followed a few lines later by `user->setup()`, which itself
calls `enable_player()` again via `std/char.lpc:50`) and
`cmds/std/sleep.lpc`'s `wakeup()` (lines 43/61/67, three unconditional
calls in a row on every single sleep-and-wake cycle).**

- **Symptom, found first**: a single, ordinary `xue jiao force` command
  (asking 石龙武馆's 教头 to teach a base skill, while too poor to pay
  the 3-coin tuition) printed the tuition-required message **twice**:
  ```
  你现在的学费是每次三文铜板，请备好零钱。
  你现在的学费是每次三文铜板，请备好零钱。
  武馆教头说道：您太客气了，这怎么敢当？
  ```
  Nothing in `debug.log` — no error, no warning, zero log signal, the
  single hardest-to-notice shape in this catalog (matches the framing of
  §7.20's "zero signal in debug.log" but via a completely different
  mechanism). A player would have to be looking closely at the *exact*
  wording of a rejection message to ever notice; a resource-costing
  success path (a rejection with a side effect already applied before
  the failure return, exactly `learn.lpc`'s shape here) would silently
  cost twice what it should, with no error to grep for afterward.
- **Root cause**: `feature/command.lpc`'s `enable_player()` calls
  `enable_commands()` then unconditionally `add_action("command_hook",
  "", 1)` -- a self-registered wildcard sentence that dispatches every
  typed command by hand-rolled `find_command()`+`call_other()` (this
  lineage doesn't use the driver's real per-verb `add_action`). Nothing
  guards against calling this function more than once per session, and
  in ordinary (non-buggy-looking) code it *is* called more than once:
  `enter_world()` calls it directly, then calls `setup()`, which calls
  it again — the FIRST of those two calls happens *before* `exec(user,
  ob)` has linked the fresh body to the actual connection, so its
  `add_action()` silently fails at the driver level (a self-registered
  sentence requires `command_giver == this_object()`, which isn't true
  yet) — it's the SECOND call, from `setup()`, that actually succeeds
  and registers the one sentence a fresh login ever needed. Separately,
  `cmds/std/sleep.lpc`'s `wakeup()` — the sleep/rest cultivation
  mechanic's `call_out`-driven wake handler, an extremely common,
  frequently-repeated action, not a rare edge case — calls
  `enable_player()` three times per wake with no reason given for the
  repetition (dead/commented-out code nearby suggests this accreted over
  edits rather than being deliberate). Each of these EXTRA calls
  `add_action()`s ANOTHER wildcard "command_hook" sentence onto the same
  living object; `add_action()` has no built-in deduplication. The
  FluffOS add_action dispatch loop tries every matching sentence in
  registration order until one returns nonzero — for a command whose
  handler SUCCEEDS on the first try (the overwhelming majority of
  ordinary play), the extra stacked sentences are simply never reached
  and the bug is entirely invisible. Only a FAILING command (wrong
  target, insufficient funds/skill, an NPC that refuses -- extremely
  common, not an edge case) re-runs from scratch on the next stacked
  sentence, including any side effect the handler already produced
  before its failure return. Confirmed directly (not just inferred) via
  `write()`-based instrumentation in both `command_hook()` and
  `learn.lpc`'s `main()`: a single typed `xue jiao force` line produced
  **two** full `command_hook()`/`main()` invocations, both with
  identical arguments, in the same driver tick. The multiplier compounds
  with play time: a character that has slept N times has accumulated
  roughly `2 + N` stacked sentences (2 from the login-time double-call,
  +1 net per sleep, since `wakeup()`'s three calls only net one *extra*
  stack beyond what was already there), so a long-lived character's
  every failing command could eventually silently re-run many times
  over, not just twice -- this is an accumulating leak, not a fixed 2x.
- **A false lead worth recording**: the first fix attempt gated the
  `enable_commands()`+`add_action()` pair behind `if
  (!living(this_object()))`, mirroring AGENTS.md §7.19's documented
  pattern. This reliably fixed the original bug (verified: the double
  "学费" message became single) but introduced a **regression** that
  only showed up on the very next `sleep`/wake cycle: `look`/`score`/
  every other command started failing outright (`什么?`) after waking
  up, for BOTH the original test character and a freshly-registered
  control character (ruling out corrupted prior state as the cause).
  Root cause of the regression: `disable_player()` (used by both the
  sleep mechanic and the stun/faint mechanic in `feature/damage.lpc`)
  calls `disable_commands()` immediately followed by a bare
  `enable_commands()` as its OWN last two lines -- so by the time
  `wakeup()`'s calls run, `living()` is ALREADY true again (restored by
  `disable_player()` itself), even though the actual `add_action()`
  call that would re-establish a *working* sentence never happened yet.
  Gating on `living()` therefore skipped the one call that mattered,
  leaving the character "living" but with zero dispatchable commands.
  This is a useful general lesson beyond this one lib: `living()`
  reflects only the driver's `O_ENABLE_COMMANDS` flag, not whether any
  particular `add_action()` sentence is actually attached -- it is NOT
  a safe proxy for "has add_action already run" on any lib whose own
  disable/enable helper toggles that flag independently of the
  sentence-registering wrapper.
- **Fix**: call `remove_action("command_hook", "")` immediately before
  every `add_action("command_hook", "", 1)` call inside `enable_player()`
  itself (not at any of the several call sites). This keeps *exactly*
  one sentence registered no matter how many times the wrapper is
  (redundantly) called, in whatever order or `command_giver` context
  those calls happen to run in, without depending on `living()` or any
  other state flag as a stand-in for "is the sentence already there" --
  sidestepping the regression above entirely, since it doesn't matter
  whether a given call's `add_action()` would have succeeded or
  silently no-op'd; a stale sentence is removed first either way, and
  the freshest `add_action()` call that actually has a valid
  `command_giver` context is the one that sticks.
- **Verified**: reproduced live pre-fix (`write_file`/`write`
  instrumentation showed `learn.lpc`'s `main()` and
  `command.lpc`'s `command_hook()` each firing twice for one typed
  `xue jiao force`); rebuilt nothing (LPC-only change); killed and
  rebooted the native driver between each iteration (objects don't
  recompile from disk changes on a live process, per AGENTS.md §10.3);
  re-tested with THREE separate characters after the final fix:
  - `qintian`, immediately after a fresh login: a single failing `xue
    jiao force` now prints the tuition message exactly once.
  - `ceyanzc`/测验者, fresh registration → `xue jiao force` (fails,
    single message) → withdrew savings → `xue jiao force` again
    (succeeds, tuition charged exactly once, correctly then gated by
    the *separate*, correct "已经无法再进步" skill-cap check, not a
    regression) → full `sleep`/25s-real-wait/wake cycle → `look`/
    `score`/`xue jiao force` all immediately functional afterward
    (the regression's exact repro scenario), single dispatch confirmed
    throughout.
  - `shuimian`/沉睡, an independent control character, used specifically
    to catch the `living()`-guard regression (which it did) and then to
    confirm the `remove_action()` fix resolved it (which it did).
  `debug.log` clean (no `error:`/`Too deep recursion`/`Undefined
  function`) across every iteration of this investigation.
- **Lineage scope**: checked directly, not assumed -- byte-identical
  unguarded `enable_player()` in `feature/command.lpc`, byte-identical
  double-call from `enter_world()`, and byte-identical triple-call from
  `sleep.lpc`'s `wakeup()` are present in BOTH documented siblings,
  `dtsl2` and `dtslmud` — this is a
  **lineage-wide** bug, not specific to this archive, though porting the
  fix to the siblings is out of scope for this pass (left for the
  orchestrating session per the task brief).

### What was tested and confirmed working

- **Registration**: real Chinese name (秦天), full id→confirm→name→
  password(5-8 chars)→confirm→email(skip)→gender→4-stat-point
  allocation flow, landing in 大唐学院 (`/d/newbie/door`), `look`/
  `score`/`i` all correct at every stage.
- **Newbie zone navigation**: walked `d/slwg` (石龙武馆, reached via
  大唐学院's `down` exit) end-to-end by reading room `.lpc` source for
  exits (the ASCII `map.txt` file in that directory matches the actual
  `set("exits", ...)` wiring) -- 走廊→正厅→北廊→练武场/练功房/西廊
  (花园/休息室)/东廊(账房). Room descriptions, day/night flavor text,
  and multi-line exit listings all render correctly throughout.
- **Newbie gift**: `ask li about 大唐双龙` on 石龙武馆's 礼官 (`d/clone/
  npc/liguan.lpc`) correctly grants a one-time combat_exp/attribute
  boost with the documented flavor text.
- **Safe sparring**: this lineage's actual safe-sparring mechanism is
  NOT the generic `fight`/`accept_fight()` hook documented as the
  default pattern in AGENTS.md §10.7 point 3 -- both the 练武场
  (`d/slwg/wuchang1.lpc` etc, `d/slwg/get_skill1.lpc`) and 练功房
  (`d/slwg/liangongfang{1,2,3}.lpc`, `d/slwg/get_skill.lpc`) rooms are
  `no_fight`-flagged and their NPCs (`npc/dizi.lpc`, `npc/jiaotou.lpc`)
  hardcode `accept_fight() { return 0; }` -- `fight`/`kill` are
  deliberately unusable there. Instead each room registers its own
  local `qiecuo <弟子|教头>` verb (`add_action("do_action", "qiecuo")`
  in the room's own `init()`) that calls `target->fight_ob(ob)`
  directly, gated by a `combat_exp` band (`<10000` → spar the 弟子 at
  练武场; `10000-20000` → spar the 教头 at 练功房; `>=20000` → told to
  go adventure instead). Confirmed live: `qiecuo di` (id `di zi`/`di`/
  `zi` — note the space-separated multi-word id, `qiecuo dizi` as one
  word does not match) at 练武场 started a real, non-lethal bout with
  full combat narration.
- **Organic skill-teaching path**: `cha`/`skills` lists a teacher's
  known skills; `xue <teacher> <skill>` (aliased from `xue`→`learn` via
  `adm/daemons/aliasd.lpc`) correctly gates on `recognize_apprentice()`
  (3-coin tuition per lesson for 石龙武馆's 教头, `is_apprentice_of()`
  hardcoded `1` so it teaches any player without requiring a formal
  apprenticeship first -- the same "teaches anyone" shape documented on
  other libs' `jiaotou`-style NPCs) and separately on a skill-level cap
  (`my_skill >= max_pot - 100` → "缺乏实战经验" rejection, not a bug --
  matches the documented base-skill-vs-special-technique growth model).
  `withdraw <amount> coin` at 石龙武馆's 账房 (`d/slwg/npc/
  zhangfang_xiansheng.lpc`, `F_BANKOWNER`) correctly moves money from
  `deposit` to carried cash.
- **Sect-join mechanism (`bai`/`apprentice`)**: `cmds/std/apprentice.lpc`
  correctly routes an NPC target through `ob->attempt_apprentice(me)`,
  each real recruiter NPC implementing its own gate (gender/marriage/
  PK-count/skill-level/rank checks) before either rejecting with in-
  character dialogue or calling `command("recruit " + id)` to complete
  the bond. Live-tested against 净念禅院's door greeter 和尚
  (`d/chanyuan/npc/heshang.lpc`), which does NOT itself implement
  `attempt_apprentice` (it's a flavor NPC, not a real recruiter) --
  confirmed this is a harmless no-op, not a crash: `ob->attempt_apprentice(me)`
  is a `call_other()` to an undefined function, which is standard-LPC
  silent-0, not a runtime error (verified no error appeared in
  `debug.log`). Code-reviewed (not live-tested, see below) the lib's
  own `doc/help/cy_baishi` walkthrough and the real newbie-entry
  recruiter it names (虚尘/`npc/xuchen.lpc`, gated only on gender/
  marriage/PK/`bellicosity`, all satisfiable by a fresh character) --
  logic is sound and self-consistent with the help text.
- **Cultivation/rest**: `sleep` (in a `sleep_room`-flagged room, e.g.
  石龙武馆's 休息室) and its `call_out`-driven `wakeup()` correctly
  restore `kee`/`gin`/`force`/`sen` over a real ~25s wait (delay scales
  with `con`); this is also the mechanic whose `enable_player()` triple-
  call exposed the bug above.
- **Persistence across `quit`**: `quit` (non-wizard, 8s delayed
  `do_quit`) correctly shows "现在准备离开游戏..." and, after the real
  8+s delay, saves and destructs the body -- confirmed by a subsequent
  reconnect landing in a genuinely fresh login flow (not a same-session
  reconnect), with `combat_exp`/attribute-boost/carried-money state all
  correctly restored from the save file. Matches this project's
  documented (`bxsj` et al.) "non-autoload items get dropped on quit"
  design -- confirmed live (starting 布衣/皮靴 replaced by
  `logind.lpc`'s `get_cloth()` on the next full login, masking the
  drop) -- not a bug, deliberate anti-hoarding mechanic already
  cataloged elsewhere in this project.
- **Net-dead disconnect and reconnect**: this lineage's `obj/user.lpc`
  does **not** use a `VOID_OB`-style holding room at all (§7.20/§7.21's
  precondition doesn't apply here) -- `net_dead()` simply leaves the
  body in its current room and stops the heartbeat; a prompt reconnect
  (`adm/daemons/logind.lpc`'s `get_passwd()` detects
  `query_temp("netdead")` and routes straight to its own `reconnect()`,
  which calls `obj/user.lpc`'s `reconnect()` apply) correctly restores
  the heartbeat and clears the netdead flag with the player never having
  moved — confirmed live across more than a dozen prompt reconnects
  during this session, zero location loss. **Also tested the full real
  15-minute `NET_DEAD_TIMEOUT` unclean-disconnect wait** (not just a
  prompt reconnect), which is precisely the test that found **Bug 1**
  above (a crash, previously undiscovered because no prior verification
  pass had ever performed this specific real-time wait) -- see Bug 1's
  writeup for the full story: net-deaded `qintian`/`ceyanzc`
  deliberately, waited a genuine 15+ real minutes, and found the
  net-dead force-quit path itself crashing (and, downstream, the whole
  native driver process crashing). Fixed and re-verified with an
  accelerated-but-equivalent repro (below); after the fix, a net-dead
  wait past the timeout correctly force-quits and saves the character,
  confirmed by the next connection landing in a genuinely fresh login
  rather than a stale `netdead` reconnect.

### Not verified live (explicitly flagged, not silently skipped)

- **A full live sect-join round trip.** The organic recruiter chain for
  净念禅院 (this pass's chosen sect) turned out to require walking a
  ~14-hop maze-like path from the sect gate to reach 虚尘, the actual
  newbie-accessible recruiter named by `doc/help/cy_baishi` (every
  senior monk actually reachable in 1-2 hops from the gate --
  了空/`liaokong.lpc`, 不痴/不嗔/不惧/不贪/不渡-equivalents --
  requires skills/rank a fresh character cannot have, and one
  newbie-shaped recruiter, `npc/budu.lpc`, turned out to be orphaned
  content not placed in any room's `objects` mapping at all). Time
  budget did not stretch to walking that path and completing a live
  `recruit`; the mechanism was instead verified by full code review
  (`cmds/std/apprentice.lpc` + `d/chanyuan/npc/xuchen.lpc`'s
  `attempt_apprentice()`) plus one live test against a non-recruiter
  gate NPC (above), confirming the failure/no-op path is clean.
- **Real combat death and respawn.** Combat was only exercised via the
  lib's own non-lethal `qiecuo` sparring mechanism (by design, per
  AGENTS.md §10.7 point 3 -- use the safe path before risking a real
  fight). Deliberately losing a real `kill` fight to reach death/
  reincarnation was not attempted this pass; reason: doing so safely
  needs either a significantly outmatched opponent or considerable
  travel/grinding, and the time budget went to the bug investigation
  above instead. `feature/damage.lpc`'s `die()`/`reincarnate()` and
  `DEATH_ROOM` routing were read (not exercised) and appear structurally
  sound (no unguarded `enable_player()` reachable from `die()` itself),
  but this is a code-review-only claim, not a live-tested one.
- **A successful (funds-permitting) shop purchase.** `buy <item> from
  <vendor>` (`cmds/std/buy.lpc`) was live-tested against 石龙武馆's
  `d/slwg/npc/tiejiang.lpc` (铁匠, `F_VENDOR_SALE`) with an
  insufficient-funds character (`buy sword from tiejiang` → `你身上带
  的钱不够啊!`, correctly single-dispatched, another confirmatory data
  point for the fix above on a third independent command) -- the
  cheapest `vendor_goods` entry there (`sword`/`blade`/`dagger`/etc, all
  `value: 100`) exceeds what a brand-new character can withdraw from
  savings (starting `deposit` is only 10), so a live SUCCESSFUL purchase
  was not reached this pass; not pursued further given the time already
  spent on the bug investigation above.

## WASM 修复摘要（迁移自 meta.json 的 group_note）

此前被错误标记为某个不存在于本项目任何档案的原始压缩包文件名（dtsl.rar）的 duplicate_of——那份"兄弟"上传显然从未被真正转档过，所以这份 7z 重新打包版是这款游戏唯一存活、完全独立的副本。duplicate_of 已清除。
