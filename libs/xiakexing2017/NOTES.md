# MUD侠客行2017完整版.zip → `xiakexing2017`

- Archive: `archives/MUD侠客行2017完整版.zip` (4.7MB — "侠客行"/"Ode to
  Gallantry" [Jin Yong novel], 2017 complete edition, MudOS v21). Mudlib
  root at `xkx/` (archive top level), config at top-level `config.cfg`.
  Note: `xkx/` directory name here is coincidental — unrelated to the
  "xkx" zone-name reuse seen inside other libs' `/d/` trees.
- Port: **40017**.

## Status: DONE — boots clean, playable over telnet

Zero fixes needed — clean boot and full login flow on the first attempt.

## What was fixed

Nothing needed for boot. Routine conversion: encoding (3330 converted,
521 already UTF-8/ASCII, 59 skipped binary, 15 lossy), `.c`→`.lpc` (3266
files, 146 refs auto-fixed), 8 local angle-bracket includes converted to
quotes automatically, `static`→`nosave` (42 files).

## Known remaining issues

- 79 lpcc-sweep failures (of 3266, 97.6% pass) — not triaged given the
  small count; boot/login path unaffected.

## How to run

```
cd libs/xiakexing2017
~/src/fluffos/build-debug/src/driver config.fluffos
python3 ../../scripts/mudclient.py 127.0.0.1 40017 --timeout 10 --send "" --send "look" --send "quit"
```

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

## Re-verification pass (driver rebuild + LPC formatter + WASM build)

- **Reformatted** all 3266 `.lpc` files under `work/` with
  `tools/lpc-syntax/format-corpus.mjs`: 3238 written, 0 already
  idempotent-clean, 28 refused by the tool's own token/byte-identity
  guard (expected on messy legacy code, not chased). Verified the
  earlier §15ae fix (`feature/command.lpc`'s `command_hook` staying
  `nomask` with `private` still commented out, in both `feature/` and
  `home/` copies) survived unchanged.
- **Native retest against the freshly-rebuilt driver**
  (`~/src/fluffos/build-debug/src/driver`, rebuilt from latest upstream
  master): clean boot, zero fatal errors in `log/debug.log`. Full
  registration flow re-verified with a fresh real Chinese name
  (`秦岳`/id `xkxbnem`), reaching an actual starting room, `look`/
  `score`/`quit` all producing correct output — no regressions from
  either the driver rebuild or the reformat.
- **WASM build test** (`scripts/wasm_client.js` against
  `~/src/fluffos/build-wasm/src`): boots cleanly (only benign compile-
  warning spam, no fatal errors). Full registration completed end-to-end
  under WASM too — id `xkxwasme` → real Chinese name `秦徽` → password/
  stat-roll-accept/email/gender → landed in the game world, `look`/
  `score`/`quit` all produced correct output. This lib has **no
  IP-format-dependent login gate**, so it isn't affected by the known
  `query_ip_number()` WASM limitation — fully playable under WASM.

## WASM-enablement pass (loopback-allow / admin seeding)

This lib's `adm/daemons/band.lpc`/`logind.lpc` are byte-identical (per
§2.1 lineage check) to the `xiakexing3`/`jqxz2008` engine
files, whose WASM pass was already done and verified with the correct
fail-closed convention — ported that fix here and re-verified
independently rather than assuming it.

- `adm/daemons/band.lpc` `is_banned()`: added a loopback short-circuit
  `if (stringp(site) && (site == "127.0.0.1" || site == "::1" ||
  (strlen(site) >= 4 && site[0..3] == "127."))) return 0;` before the
  regexp ban-list scan. Written fail-closed from the start: only a real
  loopback-shaped string counts as local; a malformed/empty/non-string
  site is NOT treated as local and still goes through the regexp ban
  check. `logind.lpc:66`'s `BAN_D->is_banned(query_ip_name(ob))` gate in
  `logon()` is thereby loopback-proof.
- No `uptime()` startup-grace gate and no per-IP anti-flood/registration
  throttle exist in this lineage (only the in-memory `mad_lock` admin
  lockdown flag, default off — game/admin design, left alone).

Admin account: `fluffos` / `Mud@2026` / 浮浮, registered through the
real flow (id → y → 浮浮 → password ×2 → talent accept `y` → email →
`m`). Granted `(admin)` by appending `fluffos (admin)` to
`adm/etc/wizlist` (shipped with `rwz (admin)` already present, no
trailing newline — added one; `securityd.lpc` reads this file at
`create()`, so a driver restart was needed to pick up the new line).
Verified after restart: `目前权限：(admin)`, title `【天神】`, `update
/adm/daemons/band` → `重新编译 /adm/daemons/band.lpc：成功！`.

Save files for the orchestrator to force-add (untracked, not
gitignored):
- `libs/xiakexing2017/work/data/user/f/fluffos.o`
- `libs/xiakexing2017/work/data/login/f/fluffos.o`

Two pre-existing caught (non-fatal) `restore_object(): Illegal file
format` errors were observed in `debug.log` during this pass —
`/adm/daemons/chinesed`'s save data at boot preload, and
`/clone/board/kedian_b`'s board save data at `enter_world()` (matches
the raw-path `/clone/board/kedian_b` display already visible in the
game, instead of a proper board name — its corrupted save data is why).
Both are wrapped in `catch()` by `master.lpc`'s `preload()`/
`logind.lpc`'s own catch respectively, non-fatal, and confirmed via
`git log`/`git status` to be genuinely corrupted data already committed
as part of the original archive conversion (archive #20, "booted clean
with zero fixes") — not introduced by this session. Left as-is per the
project's established `emoted.o`/similar precedent; not a new
regression.

Retest: fresh boot, fresh registration (id `qretest`, real Chinese name
秦风十一) through `look`/`score`/`quit` — landed in 客店, correct
output, clean quit. `fluffos`/`Mud@2026` admin login verified via
`score` (confirms `(admin)`/天神) and `update`. `debug.log` had exactly
the two pre-existing corrupted-save errors above and zero NEW runtime
errors. Test character `qretest` removed afterward; fluffos kept.

## 深度功能测试 / Deep functional test (2026-07-24, round two)

First real *playthrough* pass on this lib (all prior passes verified only
registration + `look`/`score`/`quit`, or watched boot output). Read
`doc/help/newbie` and `doc/help/intro` in full first — this is the
"东方故事２" (ES II) -derived 金庸-themed game: `newbie` names the
`fight` (safe, to-half-health sparring) vs `kill` (real) distinction up
front, the `bai`/`xue` teacher-apprentice loop, the 扬州 (Yangzhou)
starting-city layout with turn-by-turn routes to every sect, and dozens
of shortcuts. Played one continuous native-driver (`build-debug`)
session as an ordinary new player: registration with a real Chinese
name, exploring Yangzhou (客店→北大街→中央广场→东大街→东门, then the
deterministic `ml1`–`ml7` "青竹林" maze into `d/city/pomiao` and the
`丐帮` hideout `gbandao`), the organic `bai`/`apprentice` sect-join path
against four different 丐帮 teacher NPCs (all correctly rejected per
their own, met-or-not stat/alignment gates — not a bug, see below), the
`fight` safe-sparring command against a 流氓 (real multi-round combat
output, no crash), a `list`/`buy` shop-purchase attempt (correctly
rejected for insufficient funds), a real clean `quit`→relogin round
trip (state preserved), a real **prompt** net-dead reconnect (uncleanly
closing the socket, reconnecting ~25s later — resumed in the exact same
room, confirming this lib's `net_dead()` never void-parks the player at
all, see "§7.20 checked" below), and — critically — a real **full-
duration (600s = `NET_DEAD_TIMEOUT`) unclean-disconnect wait**, which
crashed the native driver process outright. Found and fixed **four**
separate bugs: one already-cataloged class (§7.12, promoted to
CRITICAL severity by this pass — the driver crash above), one recurrence
of an existing class applied at a more general choke point (§7.25-
shaped), and one genuinely new class (drafted below) that hit in three
independent files.

**Primary test character** (kept, state left as evidence): id
`qinfengxia`, Chinese name 沈秋白 (male), password `Xia@2026`. Rolled
stats 膂力19/悟性26/根骨21/身法14 (all four teacher-rejection messages
below are a direct, verifiable consequence of this exact roll, not a
bug). State: explored Yangzhou + the 丐帮 hideout, sparred a 流氓 via
`fight` (both survived, health text on both sides — matches the "点到
为止" safe-sparring description in `help combat`/`help intro`), no
sect/skill acquired live (see honesty note below), survived a clean
`quit`→relogin, a prompt net-dead reconnect, and — after the fix below
— a real full-duration net-dead force-quit + fresh-login verification.
Currently sitting at 客店 (start room) after a final clean `quit`.
Saves: `work/data/user/q/qinfengxia.o`, `work/data/login/q/qinfengxia.o`.

**Secondary throwaway character**: id `goumaice`, Chinese name 顾买测
(female), password `Gm@2026`. Used to exercise the shop `list`/`buy`
flow (correctly rejected, no money) and — deliberately left net-dead at
the same real moment as `qinfengxia` — as the second of the two
simultaneously-net-dead characters needed to reproduce the §7.12 driver
crash (see Bug 1). Saves: `work/data/user/g/goumaice.o`,
`work/data/login/g/goumaice.o`.

**§7.20 (void-parking) explicitly checked and does NOT apply to this
lib**: read `clone/user/user.lpc`'s `net_dead()`/`reconnect()` in full —
this lineage never moves a disconnected player to a `VOID_OB`/holding
room at all; the player object simply stays in its current room with a
`netdead` temp flag while `call_out("user_dump", NET_DEAD_TIMEOUT,
DUMP_NET_DEAD)` waits, and `reconnect()` (confirmed actually invoked,
`adm/daemons/logind.lpc:481`) just clears the flag in place. No location
to lose, no restore path needed. Confirmed live with both a prompt
(~25s) and a full 600s-plus net-dead reconnect: character stayed in the
same room both times.

### Bug 1 (CRITICAL — already-cataloged class, AGENTS.md §7.12, severity re-confirmed): the shared `tell_room()` simul_efun wrapper forwards an unset `exclude` varargs as a raw `int 0`, crashing `message()` — reached from the `NET_DEAD_TIMEOUT` force-quit path, and reproduced as an actual **native driver process crash**

**File:line: `adm/simul_efun/message.lpc:36-38`.**

This is the identical bug AGENTS.md §7.12 already documents (first found
on `yueyingqiyuan`, severity-escalated on `dtsl`'s own §10.7 pass) —
citing the existing class, not redrafting it. Filed here because this
lib turns out to carry a **byte-identical** copy of the vulnerable
`adm/simul_efun/message.lpc` (not currently listed as a sibling of
`dtsl`/`yueyingqiyuan` in AGENTS.md §11's lineage map — worth a lineage
note) and because this pass independently reproduced §7.12's full
"severity escalation" scenario live, including the driver crash, on a
*third* lib:

- **How this was found**: exactly per AGENTS.md §10.7 checklist item 8 —
  net-deading a real character (closing the socket without `quit`) and
  waiting the genuine, full `NET_DEAD_TIMEOUT` (600s = `include/
  user.h:10`) for `obj/user.lpc`-equivalent's (`clone/user/user.lpc`)
  `call_out("user_dump", NET_DEAD_TIMEOUT, DUMP_NET_DEAD)` to fire, then
  reconnecting — rather than stopping at a prompt-reconnect test (also
  done this pass, and which never touches this code path).
- **Root cause**: `clone/user/user.lpc`'s `user_dump()` `DUMP_NET_DEAD`
  case calls `tell_room(environment(), <message>)` — a completely
  ordinary 2-argument call, one of many such call sites across the lib.
  `adm/simul_efun/message.lpc`'s `tell_room(mixed ob, string str, object
  *exclude)` is `varargs`; when the caller omits the 3rd argument,
  `exclude` is a real, typed `int 0`, not "absent" — and the wrapper
  unconditionally forwards it as `message()`'s 4th positional argument
  (`message("tell_room", str, ob, exclude)`), which only accepts
  `void|object|object*`. This throws `*Bad argument 4 to EFUN message()`
  from inside a `call_out`-driven function with no enclosing `catch()`,
  aborting the rest of `user_dump()` at that exact statement —
  `command("quit")` right after it never runs, so **the entire net-dead
  force-quit safety net was silently disabled** for any player who
  net-deads and never manually reconnects.
- **Then it got worse, exactly like `dtsl`'s report**: reproducing this
  live with **two** characters (`qinfengxia` and `goumaice`) both net-
  dead past the timeout at nearly the same real moment, followed by a
  third connection attempt, crashed the **entire native driver process**
  — captured in the driver's own redirected stdout:
  ```
  md: debugmalloc: attempted to free non-malloc'd pointer ...
  #3 MDfree ... #4 debugfree ... #5 dealloc_object ... #6 int_free_svalue
  #7 assign_svalue ... #8 assign_value_to_lvalue ... #9 eval_instruction (F_ASSIGN)
  ... #12 f__call_other ... #17 call_function_interactive (processing the
  reconnect command) ... Aborted (Signal sent by tkill())
  ```
  Confirmed via `ps`/`ss` that the driver was genuinely gone (not just
  the connection dropping) and via the stdout backtrace, not inferred.
  The exact C-level mechanism (a destructed-object reference whose
  refcount reached 0 without a proper `free_object`) wasn't rigorously
  proven with ASan/valgrind (out of scope), matching AGENTS.md §7.12's
  own caveat, but the correlation is strong: the crash did not recur
  after the fix, reproducing an equivalent two-character scenario.
- **Fix** (identical to AGENTS.md §7.12's prescribed fix):
  ```lpc
  // BEFORE:
  varargs void tell_room(mixed ob, string str, object *exclude) {
    if (ob) message("tell_room", str, ob, exclude);
  }
  // AFTER:
  varargs void tell_room(mixed ob, string str, object *exclude) {
    if (ob) message("tell_room", str, ob, exclude || ({}));
  }
  ```
- **Verified**: to avoid a second genuine 10+ minute wait, re-verified
  with the exact methodology AGENTS.md §7.12/`dtsl` used —
  `include/user.h`'s `NET_DEAD_TIMEOUT` temporarily changed from `600`
  to `15` for testing only (LPC logic exercised is byte-for-byte
  identical, only real wall-clock time differs), confirmed restored to
  `600` immediately after (`git diff` on that file is empty). With the
  fix applied: net-deaded `qinfengxia` and `goumaice` simultaneously
  again, waited a real 25+ seconds past the (shortened) timeout, checked
  `debug.log` (zero `Bad argument`/any error), then reconnected as
  `qinfengxia` — landed in a genuinely fresh login (confirmed by the
  "上次连线" timestamp updating, i.e. `enter_world()` actually ran, not
  a stale netdead resume) at 客店, `look`/`quit` both correct, and the
  **driver process stayed alive and stable throughout** (`ps` RSS
  tracked normally, no crash). Final full sanity pass afterward (fresh
  boot, full `NET_DEAD_TIMEOUT` restored to 600, register→explore→
  quit) also clean.

**Lineage note for AGENTS.md §11**: `xiakexing2017`'s
`adm/simul_efun/message.lpc` carries this exact vulnerable `tell_room()`
shape, matching `dtsl`'s. Currently listed as "Standalone/distinct" in
§11 — worth flagging as sharing at least this one shared-infrastructure
file with the broader ES II family (§11's "ES II / 东方故事 mega-family"
already carries the §7.12 warning), even though this project's own
`newbie`/`intro` docs describe it as "东方故事２" (ES II) -derived
already, so this is consistent, not a surprise.

### Bug 2 (new bug class, draft below): mapping-typed properties/accessors default to a raw `int 0` when never set, and several call sites index into them without checking — "value being indexed is zero" / "bad argument 1 to keys()"

Two independent instances, one in shared engine code (reachable from
nearly every room in the game) and one in specific zone content — same
underlying shape, draft text below covers both.

**Instance A — `feature/skill.lpc`'s `query_skills()`/`query_learned()`/
`query_skill_map()`/`query_skill_prepare()` (lines 13-14, 103-109)**:
each is declared `mapping query_X() { return X; }` where the module
variable `X` (`skills`/`learned`/`skill_map`/`skill_prepare`) is declared
`mapping X;` but never initialized — LPC's default value for an unset
`mapping` global is `int 0`, not `([])`. Every setter in the same file
(`set_skill()`, `map_skill()`, etc.) correctly guards with `if
(!mapp(skills)) skills = (...)`, but the four query accessors return the
raw variable unconditionally. Reached live: `d/npc/xiaofeng.lpc`'s
`check_skills()` (fired via a 2-second `call_out` from `init()`, i.e. on
ordinary room entry) does `skl = ob->query_skills(); sname =
sort_array(keys(skl), ...)` — for our fresh test character (0 skills
learned, completely ordinary, expected state for a brand-new player),
`query_skills()` returned raw `0`, and `keys(0)` crashed:
```
执行时段错误：*Bad argument 1 to keys()
Expected: mapping Got: 0.
程式：/d/npc/xiaofeng.lpc 第 99 行
```
84 call sites across 42 files call `->query_skills()`/`->query_learned()`
— most already defensively re-guard with their own `if (!mapp(...))`
before use (e.g. `cmds/std/check.lpc`, `cmds/skill/skills.lpc`, which is
exactly why this didn't surface everywhere), but at least this one did
not.

**Instance B — a mapping-typed per-object `query()` property indexed
directly, same shape, different mechanism**: `query("party")` (an
object's faction-membership record, unset for anyone not in that
faction) and `query("family")` (sect-membership record, unset for anyone
sect-less) both legitimately return `0` for the common case of "hasn't
joined". Three files indexed one of these directly with no guard:
`d/mingjiao/npc/mingjiao.h:6` and its byte-identical duplicate
`kungfu/class/mingjiao/mingjiao.h:6` (`ob->query("party")["party_name"]`
in a shared `greeting()` used by ~20+ 明教 NPC files, fired via a 1-
second post-`init()` `call_out` — i.e. crashes for any non-明教 player
standing near ANY of them, confirmed live for `d/mingjiao/npc/
changyuchun.lpc`'s 常遇春, who sits in the starting city's central
square that every fresh login passes through), and `d/xiaoyao/obj/
bojuan.lpc:43` (`me->query("family")["family_name"]`, a readable skill
scroll — crashes for any non-逍遥派 player who tries `read`/`study`/`du`
on it, which is the obvious, intended first thing to try). All three
crash with the same signature:
```
执行时段错误：*Value being indexed is zero.
```
This shape is NOT universal in this lib — most other `query("family")[`/
`query("party")[` call sites (checked: `kungfu/class/mingjiao/
zhangwuji.lpc`, `d/xiaoyao/xiaodao1.lpc`, `shishi4.lpc`, `npc/qingyun.lpc`,
`npc/xuemuh.lpc`, `fangjian2.lpc`) already correctly guard with `!ob-
>query("family") ||`/`ob->query("party") &&` — confirming this is an
easy-to-miss oversight recurring independently, not evidence the whole
convention is broken, and that the correct local idiom was already
established and just not applied consistently.

**Detection**: grep `->query_skills(\|->query_learned(\|->query_skill_map(
\|->query_skill_prepare(` (or a lib's own equivalent mapping-returning
accessor) for definitions that `return <bare variable>;` without a
`mapp()` guard, matching the setter functions' own established
discipline in the same file. Separately grep `->query("<mapping-shaped-
property>")\[` (family/party/couple/skill-map-shaped properties) for
direct indexing with no adjacent `mapp()`/truthiness check — cross-check
against sibling call sites in the SAME file/directory first, since (as
here) the correct guarded idiom is very often already established
nearby and the unguarded instance is the outlier, not the norm.

**Fix**: at the accessor/property level, not every call site — same
"shared choke point" principle as §7.25/§7.26. For an engine accessor
like Instance A: `mapping query_skills() { return mapp(skills) ? skills
: ([]); }` (applied to all four accessors in `feature/skill.lpc`). For a
one-off unguarded index like Instance B: capture the property into a
local first and guard it (`party = ob->query("party"); if (mapp(party)
&& party["party_name"] == ...)`), matching the idiom already used
correctly elsewhere in the same codebase.

**Verified**: restarted the driver after each fix; re-walked
`qinfengxia` past 萧峰/xiaofeng (北大街) and 常遇春/changyuchun (中央
广场) — both previously-crashing `check_skills()`/`greeting()` calls
fired cleanly with zero `debug.log` errors afterward, confirmed across
two independent fresh-boot sessions. `bojuan.lpc`'s fix was verified by
code-inspection parity with the other five already-correct sibling call
sites in the same directory (not re-walked live to the 逍遥派 zone
specifically — a multi-minute maze/gate trek for a one-line, pattern-
identical fix already proven safe by the two live-verified sibling
instances; noted honestly rather than silently claimed as live-tested).

### Bug 3 (recurrence of AGENTS.md §7.25, fixed at a more general choke point): `cmds/std/go.lpc`'s destination-room force-load silently swallows the player's move command on that room's first-ever visit when the room's own tail-of-`create()` companion-object load throws

**File:line: `cmds/std/go.lpc:70-73`** (plus two smaller sibling
instances at `d/wizard/guest_room.lpc:24` and `d/wizard/wizard_room.lpc:
21`, same shape, fixed the same way).

Matches AGENTS.md §7.25's "closely related shape" almost exactly
("rooms that force-load a companion object ... via `call_other('<path>',
'???')` in their own `create()`") — citing the existing class. The
difference from a textbook §7.25 instance: the vulnerable
`call_other(dest, "???")` isn't inside each room's own `create()`, it's
in the single SHARED movement command (`go.lpc`) that force-compiles
*any* destination room on its first-ever visit — so this fix was applied
at that one shared choke point instead of repeating `catch()` across
this lib's 17 separate rooms that end their own `create()` with an
identical `"/clone/board/xxx_b"->foo();` companion-board force-load
(confirmed all 17 have the load as the LAST statement of `create()`,
i.e. after `exits`/`objects`/`setup()` are already set — spot-checked
5 of the 17 directly, matching the one instance actually reproduced
live).

- **How this was found**: exploring Yangzhou's `ml1`-`ml7` "青竹林"
  maze toward the 丐帮 (Beggars' Sect) hideout, per `doc/help/newbie`'s
  own documented route. The maze's final room (`ml7`) exits north into
  `d/city/pomiao` — a room visited for the first time this boot.
  `pomiao.lpc`'s `create()` ends with `"/clone/board/gaibang_b"->foo();`
  to force-load its message board; that board's SAVED DATA is corrupted
  (pre-existing, same class as the already-documented `kedian_b`
  corruption above — confirmed via `git log`/`git blame` on
  `work/data/board/gaibang_b.o`, unchanged since the original archive
  conversion commit, raw GBK/BIG5-era bytes, not something this session
  introduced), so `restore_object()` throws `*restore_object(): Invalid
  utf8 string while restoring dbase.` — caught by the driver's own
  top-level handler (not an LPC `catch()`, since `feature/save.lpc`'s
  `restore()` has none), which aborts the ENTIRE calling chain back up
  to wherever a `catch()` (or the top of the call) actually exists. That
  chain is `command_hook() → cmds/std/go.lpc main() → call_other(dest,
  "???")` — i.e. `go.lpc`'s own `main()` function, mid-execution, with
  no enclosing `catch()` anywhere in between. Net effect: `main()` aborts
  right at the force-load line, and the code immediately after it — the
  retry `find_object(dest)` check and the actual `me->move(obj)` call —
  never runs. The room itself finishes compiling correctly (the throwing
  line is its very last statement), but the player's move command that
  triggered the compile is silently swallowed: they stay exactly where
  they were, `look` shows the same room again, no error, no hint
  anything happened. Confirmed reproducible-then-fixed: before the fix,
  a scripted `n` (or whichever direction led into `pomiao` first) from
  inside the maze left the character still in "青竹林" with the caught
  error visible only in `debug.log`; after the fix, the identical move
  landed the character in 土地庙 (`pomiao`) immediately, board-load
  error still present in `debug.log` (harmless, pre-existing, unrelated
  to the fix) but the room transition now completes.
- **Fix**: wrap the force-load in `catch()`:
  ```lpc
  // BEFORE:
  if (!(obj = find_object(dest)))
    call_other(dest, "???");
  // AFTER:
  if (!(obj = find_object(dest)))
    catch(call_other(dest, "???"));
  ```
  Safe specifically because every instance checked (17/17 by grep, 5/17
  spot-checked directly) puts the risky companion-object load as the
  LAST statement of the destination room's `create()` — so even when the
  `catch()` swallows a throw, the room object is already fully populated
  (`exits`/`objects`/`setup()` all ran) by the time `go.lpc`'s retry
  `find_object(dest)` check runs immediately after, and the move
  proceeds normally into a correctly-initialized room. Also applied the
  same `catch()` to the two structurally-identical but currently-
  unexercised direct `call_other(".../board", "???")` force-loads in
  `d/wizard/guest_room.lpc` and `d/wizard/wizard_room.lpc` (their own
  `create()`, not reached via `go.lpc` — the same §7.25 shape, proactive
  fix by code-shape match, not yet live-triggered since their board data
  isn't known to be corrupted).
- **Verified**: reproduced live pre-fix (character stuck in 青竹林,
  caught error in `debug.log`, no transition) and post-fix (same exact
  scripted route now lands in 土地庙, board-load error still logged as
  expected/harmless, room transition succeeds) across two separate
  fresh-boot sessions with the deterministic `ml1`→`ml2`→`ml3`→`ml4`→
  `ml5`→`ml6`→`ml7`→`pomiao` route derived by reading each maze room's
  `exits` mapping directly (the maze is NOT actually random despite the
  "你仿佛迷失了方向" flavor text — every room has fixed, asymmetric
  exits, several of which loop back to themselves; `doc/help/newbie`'s
  own `丐帮：#3 e;n;e;n;w;n;e;w;n;...` route matches this exactly). The
  `guest_room.lpc`/`wizard_room.lpc` siblings were fixed but not live-
  reproduced (no known corrupted board data for `towiz_b`/`wiz_b`
  currently) — noted honestly, not claimed as live-verified.

### Honesty notes — not verified live, explicitly

- **Sect membership / `xue` skill learning were NOT completed live.**
  `bai`/`apprentice` was correctly exercised against four different 丐帮
  teacher NPCs reachable via the documented route (`鲁有脚`/`彭有敬` at
  `pomiao`, plus the two rejects noted in the newbie-help zone) — each
  rejected `qinfengxia` for a real, code-verified reason specific to
  that NPC (`int>=25`, unconditional non-recruiter, etc.), all correctly
  matching this character's actual random stat roll (str19/int26/
  con21/dex14). This is normal game-content behavior, not a bug — see
  `attempt_apprentice()` bodies in `kungfu/class/gaibang/*.lpc`. The one
  unconditional-accept teacher found in the whole lib (`kongkong.lpc`,
  空空儿) sits inside `d/city/lichunyuan` (丽春院/brothel), gated behind
  an explicit, code-confirmed age check (`d/city/nandajie2.lpc:33`,
  `age < 18`) that a fresh 14-year-old character cannot pass without
  real in-game aging — a genuine content gate, not a bug, and not worth
  spending further session time defeating for its own sake. Reaching a
  free/no-prerequisite teacher and completing a real `xue` was not
  achieved live within this pass's time budget.
- **Death/respawn was not reached live.** `fight` (the safe-sparring
  path) was exercised and confirmed non-lethal by design (`help
  combat`/`help intro`: stops at ~half health, matches
  `cmds/std/fight.lpc`'s own help text); reaching real death would
  require either a deliberately lost `kill` fight or self-`suicide`,
  neither attempted given the time budget already spent on the §7.12
  full-duration net-dead reproduction above (the highest-value finding
  of this pass).
- **A successful shop purchase was not completed live** — `list` and a
  `buy` attempt were both exercised (`goumaice` at `d/city/yaopu`,
  correctly rejected with "穷光蛋，一边呆着去！" for insufficient funds,
  the expected/correct behavior for a brand-new character with no
  income yet) but earning money first (per `doc/help/newbie`'s own
  suggested 谷物加工厂/服装厂 wage-work path) was not attempted given the
  time budget.

### Files modified this pass

- `work/adm/simul_efun/message.lpc` — Bug 1 fix (§7.12).
- `work/feature/skill.lpc` — Bug 2 Instance A fix (4 accessors).
- `work/d/mingjiao/npc/mingjiao.h`, `work/kungfu/class/mingjiao/
  mingjiao.h` — Bug 2 Instance B fix (duplicate copies).
- `work/d/xiaoyao/obj/bojuan.lpc` — Bug 2 Instance B fix.
- `work/cmds/std/go.lpc` — Bug 3 fix (primary).
- `work/d/wizard/guest_room.lpc`, `work/d/wizard/wizard_room.lpc` — Bug 3
  fix (proactive siblings).
- `work/include/user.h` — touched only transiently for the accelerated
  §7.12 re-verification (`NET_DEAD_TIMEOUT` 600→15→600); confirmed
  byte-identical to the pre-pass version (`git diff` empty) before
  finishing.

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 19 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。
