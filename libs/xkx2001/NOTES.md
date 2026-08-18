# xkx2001 — 侠客行 Ⅰ (Xiakexing/The Quest of Oriental Chivalry, 2001 test lib)

Archive: `xkx2001测试用老lib.zip`. Port: 40021. Status: **done** (boots
clean, connects, plays through login into "create new character?"
confirmation with zero crashes).

## What this is

"ES II mudlib" lineage (comment header in `adm/single/master.c`: "for ES
II mudlib... modified by Xiang for XKX"), same family as `rzrmud`
(archive #23, "大唐西游") — shares the exact same `master.c` function set
(`connect`/`epilog`/`preload`/`log_error`/`valid_*`/`standard_trace`/
`error_handler`) almost verbatim, both apparently descended from the
same "XKX"(侠客行)-authored base. `adm/single/master.c` +
`adm/single/simul_efun.c` layout, same as `bxsj`/`bxsj1` (archives #4/#5)
— but NOT the same lineage as those (checked: no `log_error()`/
`CHANNEL_D` reentrancy call, no lazy-load-in-valid_read pattern, 2-arg
`valid_override` but no allow-list issue hit in testing). MudOS v22b25,
"XiaKeXing Gaming Group 1996-2003".

## Fixes applied

None — booted clean with zero fixes on the first attempt (mechanical
`convert_lib.sh` pipeline only), same as `rzrmud`. Before starting,
checked this lib's `master.c` against the known bxsj-lineage bugs (§4
CHANNEL_D reentrancy, §14 valid_override 3-arg, §8c this_player()-override
footgun) since the `adm/single/` path layout matches bxsj/bxsj1 — none of
those specific bugs are present in this master.c despite the similar
directory layout, confirming layout similarity alone doesn't mean shared
bugs; the actual `master.c` *content* here is closer to rzrmud's.

## Known content gap (not fixed — see AGENTS.md §13)

lpcc sweep: 8124 files, 6884 pass / 1240 fail (84.7%). Largest cluster
(52 failures, one root cause per AGENTS.md §8g): `inherit/misc/
bboard.lpc` (and its `.bad.lpc` backup copy) calls `EDITOR_D->add(...)`/
`EDITOR_D->get_file_num(...)` — a whole daemon (`EDITOR_D`, apparently an
"anthology/featured-posts editor" service for bulletin boards) that
doesn't exist anywhere in this archive at all, not a typo or missing
`#define`. Genuine missing content (an entire daemon file), affecting
only the bulletin-board "compile into archive" feature — not fixed, out
of scope. The remaining ~1188 failures are the usual long tail (illegal-
character/encoding edge cases, syntax typos in individual files,
`#include`-only fragments failing standalone per §6b) — not triaged
individually.

## Interactive test result

Connects, ASCII banner + mudlist status table render correctly (Chinese
intact), GB/BIG5 charset prompt works, username length/alphabetic
validation works correctly (rejected both a too-long and an all-Chinese
attempt before accepting a valid one), and a valid new username reaches
the "create new character?" (y/n) confirmation prompt with zero crashes.
Did not create a full character or play further (out of scope).

## Re-verification pass (QA sweep, later session)

Earlier passes never tested past the "create new character?" confirmation
prompt / the password-setup step, so the full registration -> post-login
command flow (per the project's standing §15ae policy) had never actually
been exercised here. Re-tested end-to-end this pass and found two real,
fixed bugs, plus clarified one thing that looked exactly like a bug but
wasn't:

1. **§15s — `adm/simul_efun/message.lpc`'s `tell_room()` passed a raw,
   unset `int 0` as `message()`'s 4th ("exclude") argument** whenever
   called in its common 2-arg form. This driver's `message()` rejects that
   shape (`Bad argument 4 to EFUN message() ... Got: int(0)`), and since
   `tell_room()` fires from a room's own `create()`/`reset()`/
   `make_inventory()` chain (an NPC's arrival announcement) the very first
   time ANY room is lazily compiled, the uncaught error aborted the
   in-progress `move()` call that placed a brand-new character into their
   starting room -- leaving the character with **no environment at all**
   (`look` showed "你的四周灰蒙蒙地一片，什么也没有", `environment(me)` was
   0, every subsequent command touching `environment()` crashed). Fixed
   with the standard pattern: `exclude || ({})`. Re-verified: after the
   fix, `move()` into the starting room completes cleanly and `look`
   renders the real room every time.
2. **§15af — `master.lpc`'s `log_error()` called `wizardp(this_player(1))`
   unconditionally**, including during PRELOAD when no player is
   connected (`this_player(1)` is 0) -- `wizardp()` calls into
   `SECURITY_D` via `call_other`, which can lazily `load_object()` the
   security daemon; doing so while the driver is still mid-compile of
   some unrelated file throws `Object cannot be loaded during
   compilation.` (seen 23 times on a clean boot, all during preload, all
   non-fatal here but pure log noise plus latent-crash risk of the kind
   documented for `shenzhou`). Also fixed the same function's
   `"Warning:"` vs the driver's real lowercase `"warning:"`
   case-sensitivity bug while touching this line (the filter never
   actually matched anything before). Fixed by guarding the whole check
   behind `this_player(1) &&` first. Re-verified: a clean boot now shows
   **zero** `执行时段错误` lines at all (was 23).
3. **Missing `/log/nosave/` directory** (§15ah-shaped): `securityd.lpc`'s
   own denial-logging (`log_file("/nosave/WRITE_LOG", ...)`) and
   `message.lpc`'s read/write audit log both target this subdirectory,
   which the raw archive never shipped. Created
   `libs/xkx2001/work/log/nosave/` proactively.
4. **Not a bug -- clarified a red herring that looked exactly like a
   silent-command-dispatch bug (§15ae's symptom shape) but has a totally
   different, legitimate cause**: every brand-new (non-wizard) character
   lands on the "侠客岛" landing beach (`d/xiakedao/shatan1.lpc`), whose
   own `init()` calls `add_action("block_cmd","",1)` -- a DELIBERATE,
   hand-written onboarding gate that blocks every command except `quit`,
   `goto`, `suicide`, `follow`, `tell`, `say`, `reply`, `look` until the
   player follows the greeter NPC (auto-drags them after ~15s regardless)
   to the "侠客岛挂名处" (registration desk) and types
   `register <email>` -- which the mudlib code implements as generating
   and returning a **brand-new system password** and disconnecting the
   session (an authentic 1990s-era anti-multi-accounting mechanic, not a
   crash). `block_cmd()` returns 1 (block) with **no message at all** for
   anything outside that whitelist, so `score`/`inventory`/`help`/`who`/
   etc. silently doing nothing at this stage is completely expected
   in-game behavior, not a driver-compat regression -- confirmed by
   reconnecting with the new password afterward and finding `look`/
   `score`/`quit` all work perfectly in the real starting room. Spent
   real diagnostic effort here (temporary `efun::write_file()` tracing in
   `process_input()`/`command_hook()`/`find_command()`, all removed
   afterward) before finding `shatan1.lpc`'s `block_cmd()` -- worth
   flagging in AGENTS.md as a new variant of the "commands silently do
   nothing after registration" family (distinct from §15ae's private-
   command-hook cause and §15aj's missing-environment cause): a
   deliberate, narrow post-registration command whitelist gate with a
   silent (no-notify_fail) block response.

Full clean re-verification (fresh boot, after all fixes): registration
with real Chinese names 秦云(female)/秦伟(male), through the
follow-NPC -> auto-escort -> `register <email>` -> new-password ->
reconnect -> `look`/`score`/`quit` flow, zero `执行时段错误` in
`debug.log` across the entire session.

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

## Driver-rebuild retest + LPC reformat + WASM pass (this session)

- **LPC formatter applied** (`tools/lpc-syntax`, all `work/*.lpc`):
  8,074 files reformatted, 46 unchanged, 9 refused (self-check failures
  on messy legacy code, expected). Confirmed the §15s `tell_room()` fix
  in `adm/simul_efun/message.lpc` survived reformatting intact.
- **Native re-test against the freshly rebuilt driver**
  (`~/src/fluffos/build-debug/src/driver`, rebuilt from latest upstream
  master): boots clean, zero `FATAL`/`SIGSEGV`/`执行时段错误` in
  `debug.log`. Full registration verified end-to-end with real Chinese
  names, including this lib's distinctive onboarding mechanic: id/name/
  password/gift/email/gender -> lands on the "侠客岛" beach ->
  greeter NPC `follow`-escorts the player (auto-drags after a delay) to
  the "侠客岛挂名处" (registration desk) -> `register <email>` generates
  a brand-new system password and disconnects -> reconnect with the new
  id+password -> `look`/`score`/`quit` all correct in the real starting
  room. Verified with id `qretkxr`/real name **秦云归来** (male),
  new password `ychif` issued by `register`, reconnect succeeded and
  reached the beach's continuation room with correct character sheet.
- **WASM build tested** (`~/src/fluffos/build-wasm/src` via
  `scripts/wasm_client.js`): boots cleanly (only expected non-fatal
  preload warnings, e.g. `Macro 'ROOM' redefined` and no-`sockets`-
  package notices). **Registration succeeded end-to-end under WASM,
  including the full beach -> follow -> register-desk -> new-password
  flow** — real Chinese name **秦云网四** (id `qfwaskc`), `register`
  correctly issued a new password (`slrze`) and disconnected, exactly
  matching native behavior. **Contrary to this project's general
  expectation for this lib** (this lib's own login/ban checks —
  `BAN_D->is_banned(query_ip_name(ob))` and
  `REGBAN_D->is_banned(query_ip_name(ob))` in `logind.lpc` — use
  `query_ip_name()`, not `query_ip_number()`, and neither gated the
  registration path in this pass's testing), **this lib's own
  registration flow was NOT observed to be blocked by the documented
  `query_ip_number()`-format WASM limitation** in the portion tested.
  The one step not further exercised under WASM: reconnecting with the
  `register`-issued new password to complete the loop, since
  `wasm_client.js` boots a fresh in-memory filesystem per invocation
  and has no built-in way to reconnect to an already-disconnected
  session within one process (a harness limitation, not a mudlib or
  driver bug) — the native re-test above already fully covers that
  final step. The general `query_ip_number()` WASM limitation described
  in AGENTS.md remains real and does affect other libs in this batch
  (see `xyzxfk`/`xyzxfy2`'s NOTES.md,
  whose `BAN_D` checks use `query_ip_number()` directly) — it just
  doesn't reach this particular lib's tested registration path.

## WASM-enablement pass (loopback-allow + admin seed)

Applied the standard WASM-first changes (AGENTS.md §1.3b/§1.3e/§1.5):

1. **Loopback always allowed through ban gates** — this lineage gates on
   `query_ip_name()` (hostname), not the IP:
   - `adm/daemons/band.lpc`: added `is_local_ip(string site)` helper
     (empty/non-string, `localhost`, `127.*` => local) and
     short-circuited `is_banned()` to `return 0` for local sites.
   - `adm/daemons/regband.lpc` `is_banned()` (the registration-ban gate
     called from `logind.lpc` before new-character creation): same
     inline local short-circuit. (regband is also matched against email
     patterns; the local check only matches localhost-shaped strings so
     email matching is unaffected.)
2. **Uptime startup gate**: none in this lib.
3. **Anti-flood throttles**: none per-IP (`MAX_USERS` is a global cap —
   left intact). `SECURITY_D->valid_wiz_login()` requires a wiz_sites
   entry for every wizard — fluffos is seeded with pattern `.*` so this
   gate passes from anywhere including WASM garbage IPs; gate itself
   left intact.
4. **Admin account seeded** — id `fluffos`, display name 浮浮 (male).
   Registered through the REAL flow including this lib's quirks:
   initial password at creation, landing on the 侠客岛 beach, escort to
   侠客岛挂名处, `register fluffos@mud.local` which ASSIGNS A RANDOM
   password (was `zfbod`) and disconnects. Then granted `(admin)` by
   editing `data/securityd.o` (the lineage's ACL save data — NOT the
   `adm/etc/wizlist.h` file, which this securityd only uses as a
   fallback when the save is absent): added
   `"fluffos":"(admin)"` to `wiz_status` and `"fluffos":".*"` to
   `wiz_sites` (required by `valid_wiz_login`). After restart, logged
   in and used the game's own `passwd` command to change the random
   password to the standard `Mud@2026`. Verified: 目前权限：(admin),
   `update /adm/daemons/band` recompiled OK, wizard-view `look` shows
   file paths. (`goto` on a non-room daemon object is a no-op in this
   lib; `update` is the canonical ACL check.) Save files:
   `work/data/user/f/fluffos.o` + `work/data/login/f/fluffos.o`
   (untracked, NOT gitignored — orchestrator must `git add`), plus the
   modified `work/data/securityd.o` (already tracked).

Retest: fresh registration (fluffos itself) through beach → 挂名处 →
`register` → random password → re-login all worked natively; fluffos
re-login with `Mud@2026` + `update` verified; debug.log free of runtime
errors.

## 深度功能测试 / Deep functional test (round two)

First genuinely hands-on *playthrough* pass (all prior passes above
verified registration/admin-login/WASM boot, never actual post-登记
gameplay: skill learning, sparring, sect contact, or a real
disconnect/reconnect). Read `doc/help/newbie.dec99` and `doc/help/intro`
in full first — both correctly describe this lib's mechanics (`fight`
is the safe, non-lethal sparring form; `kill`/`hit` are real; `bai`/`xue`
for apprenticing/learning; `wimpy` for auto-flee) even though the
specific starting geography they describe (扬州客店 as the general hub)
turned out to belong to the shared "ES2 newbie doc" template, not this
lib's actual map — this archive's real starting zone is entirely the
self-contained "侠客岛" (Xiake Island) tutorial/quest zone
(`d/xiakedao/`, ~100 rooms), reached via the beach → escort → 挂名处 →
`register` flow already described above. Native driver
(`~/src/fluffos/build-debug/src/driver config.fluffos`), `scripts/
mudclient.py` throughout. Found and fixed **one serious bug** (a real
driver segfault, not just a caught LPC error — the first of that
severity found in this project's round-two pass) plus hardened the same
function against a second, non-fatal failure mode found while
re-verifying the first fix.

**Test characters left behind** (small save files, kept as playthrough
evidence, matching this project's standing convention):
- id `qinxia`, 秦霞 (female), password `gzctc` (system-issued by
  `register`, original self-chosen password was `Xia@2026` but the
  in-game `register` step always overwrites it with a random one — see
  the onboarding flow documented earlier in this file). Main
  playthrough character: completed the full 沙滩 → escort → 挂名处 →
  `register` → new-password reconnect flow; learned 基本内功 (`force`)
  to level 1 via the organic teacher-NPC path (蓝衣弟子/`dizi` at 瀑布,
  a non-sect basic-skills trainer reached via `northup` from 望海亭);
  fought a real, safe `fight dizi` sparring match to conclusion (气
  dropped visibly, match ended cleanly with "承让", no death risk,
  confirming this lib's own safe-sparring mechanism — `inherit/char/
  npc.lpc`'s `accept_fight()` — works exactly as `doc/help/newbie.dec99`
  describes); received a free 短剑 from 黄衣大汉 (`han`) via `ask han
  about 武器`; attempted `bai lingxiao` (凌逍, a real 华山 sect member
  reachable directly on the island, `create_family` confirmed) and was
  correctly declined with "要拜师，你得去拜我师父" (game design: a
  generation-14 disciple can't take his own apprentices, redirects to
  his own master) — confirms the sect-join code path is live and
  reachable from the island itself, not just via off-island travel.
  Note: the `force` skill progress above did not survive the driver
  crash described below (unsaved at the time) — re-verified the
  teacher-NPC learning mechanism works but did not re-grind it back to
  level 1 after the restart, not worth the tool-time.
- id `cetest`, 测试 (female), password `kbzeh` — a disposable second
  character used specifically to rule out a suspected registration-
  reconnect race (see Bug 2 below): repeated register → reconnect
  cycles with careful, non-overlapping connections all completed
  cleanly with no duplicate-login prompt.
- id `linxue`, 林雪 (female), password `nybhj` — used specifically to
  reproduce and re-verify Bug 1 (the crash) end to end with a real
  player, deliberately left un-followed through the full escort route
  (`d/xiakedao/npc/longx.lpc`'s `move_next()`, all 9 scripted steps:
  沙滩 zone → 小路 → 迎宾厅 → 瀑布 area → 甬道 → 大山洞) long enough
  for the guide NPC to force-drag her (`check_follow`'s count>2 branch)
  and for the fixed retry path to run repeatedly for several real
  minutes with zero crashes (see Bug 1's verification below).

### Bug 1 (NEW bug class): a mudlib logic bug (duplicate `call_out` scheduling from a missing `return`) segfaults the entire driver process, not just an LPC-level caught error

**File:line: `d/xiakedao/npc/longx.lpc`, `move_next()`, ~line 188-194.**

- **Symptom**: the driver process itself died — `Connection refused` on
  a subsequent connect attempt, no LPC-level error visible to any
  player, the crash only discoverable via `debug.log`'s C++ backtrace
  and the process actually being gone from `ps`. This happened
  spontaneously during an idle real-time wait (~2.5 minutes) while two
  test characters (an admin account and a fresh player) were sitting,
  one of them still mid-escort by this lib's own island-guide NPC
  (`d/xiakedao/npc/longx.lpc`, randomly named "龙一".."龙九" per
  instance — the exact same NPC that escorts literally every brand-new
  character from 迎宾厅 toward the island's interior after registration
  — see this file's own onboarding-flow section above). `debug.log`'s
  crash backtrace bottoms out inside the driver's own C++ `call_out()`
  implementation (`src/packages/core/call_out.cc:209`,
  `while (ob->shadowing) { ob = ob->shadowing; }`) — a null/dangling
  `object_t*` dereference consistent with `call_out()` being invoked
  for an already-freed object.
- **Root cause**: `move_next()` walks the guide NPC through a fixed
  script of movement commands (`commands[]`/`places[]`, 9 steps) via a
  self-rescheduling `call_out("move_next", 10, me, count)`. When the
  escorted player becomes separated from the guide mid-step
  (`!present(me, environment(long))` — happens routinely: some steps in
  the script are non-directional verbs like `climb tree`/`jump fall`
  that this driver's automatic leader/follow co-movement doesn't
  propagate to followers, so the two can legitimately end up in
  different rooms even with both still fully connected), the recovery
  branch explicitly re-teleports the player and reschedules
  `call_out("move_next", 10, me, count)` **with the current, unchanged
  `count`** (a retry of the same step) — but the code had **no
  `return`** after that reschedule, so execution fell straight through
  into the function's own unconditional tail, which reschedules
  `call_out("move_next", 10, me, count+1)` **a second time** on the
  same object in the same invocation. Every time this branch fires, one
  MORE duplicate/orphaned "move_next" `call_out` entry accumulates
  against the same NPC object; if the object is later `destruct()`ed
  (e.g. the ordinary "guest gave up and wandered off" cleanup path,
  lines 163-169) while one of these un-cancelled duplicates is still
  pending, the driver's own C++ call_out bookkeeping is left holding a
  scheduled callback against a now-freed object — which segfaults the
  whole process, not just the one LPC call, the next time that
  duplicate fires.
- **Why every earlier verification layer missed this**: it requires (1)
  a real player actually being escorted by this NPC (only happens
  post-registration, past every smoke test's usual stopping point), (2)
  the player becoming separated from the guide at least once (routine
  during real play, essentially never during a scripted `--send`
  sequence that never idles mid-route), and (3) enough real wall-clock
  time (multiple 10s `call_out` cycles) for the duplicate-pileup +
  destruct race to actually collide — a boot-log watch or a `look`/
  `score`/`quit` smoke test never lingers anywhere near this NPC long
  enough to hit it. Found purely by accident during this pass's
  required real-time wait for the net-dead/reconnect check below (two
  characters were left idle mid-escort while waiting) — exactly the
  kind of thing §10.7's "wait a real amount of time" step exists to
  catch.
- **Fix**: add the missing `return` so the retry-reschedule path can
  never fall through into the unconditional one:
  ```lpc
  // BEFORE:
      me->move(places[count]);
      remove_call_out("move_next");
      call_out("move_next", 10, me, count);
    }
    count = count + 1;
    remove_call_out("move_next");
    call_out("move_next", 10, me, count);
    return;
  }
  // AFTER:
      me->move(places[count]);
      remove_call_out("move_next");
      call_out("move_next", 10, me, count);
      return;   // <-- was missing; this is what let the branch fall
                //     through into the unconditional reschedule below,
                //     double-scheduling "move_next" on the same object.
    }
    count = count + 1;
    remove_call_out("move_next");
    call_out("move_next", 10, me, count);
    return;
  }
  ```
- **Verified live, twice**: (1) restarted the driver clean, waited a
  real ~2.5-3 minute idle window with two characters mid-escort by this
  exact NPC (reproducing the same conditions as the original crash) —
  the process stayed up the whole time, `ps`/`ss` confirmed it was
  still listening, `debug.log` stayed free of new fatal/segfault lines.
  (2) A second, harder stress test: deliberately walked a fresh
  character (`linxue`) into 迎宾厅 and left the connection open,
  un-followed, for the guide's full 9-step scripted route (several real
  minutes) — the `!present` recovery branch fired repeatedly (visible
  as "龙七不知从哪变了出来，拉起你的手边走边埋怨道" printing many times
  in a row near the route's end), i.e. the exact vulnerable branch ran
  dozens of times back-to-back under the fix, and the driver never
  crashed. `update /d/xiakedao/npc/longx` (as the seeded admin account)
  recompiled the fixed file with zero errors afterward.
- **Residual, lower-severity issue found while stress-testing the fix
  (not a crash, not separately fixed as a distinct bug, folded into the
  same edit below)**: at the route's very last step (`places[8]` =
  `/d/xiakedao/dadong`, a room whose only exit is `south`), the retry
  branch can loop indefinitely (every 10s, "拉起你的手边走边埋怨道..."
  repeating forever) instead of ever reaching the intended "请在这里稍候，
  岛主一会便到" completion line — the guide NPC just never finishes
  greeting that specific player, though it also never hurts anything
  (no error, no leak beyond the one harmless retry `call_out`). Not
  root-caused further given time budget; noted here rather than
  silently dropped.
- **A second, related failure mode found and fixed while
  investigating**: `move_next()`'s `command(commands[count])` call
  (the line right before the buggy branch above) can itself throw an
  uncaught driver-level error — reproduced live, twice, with the exact
  same lib-shipped message both times: `*Illegal to move or destruct an
  object (/d/xiakedao/yongdao3) defining actions from a verb
  function(north) ... which returns zero` (this driver's own safety net
  against destructing/moving an object still on a verb-function call
  stack — a pre-existing quirk of this specific room transition, not
  introduced by anything in this pass; not further root-caused). Before
  Bug 1's fix, this was moot (masked by the crash). After Bug 1's fix,
  this alone would still silently abort `move_next()` **before** it
  ever reaches the reschedule logic — leaving that guide NPC instance
  permanently stuck with no pending `call_out` at all (harmless, but a
  content regression: that NPC just stops working for that player).
  Wrapped the call in `catch()` so a failed scripted step degrades to
  the same "guest got left behind, drag them back" recovery path
  instead of derailing the whole function:
  ```lpc
  // BEFORE:  command(commands[count]);
  // AFTER:   catch(command(commands[count]));
  ```
  Re-verified: the identical "Illegal to move" line recurred a second
  time during the stress test above (same room, same step) and this
  time did **not** abort the guide's schedule — it simply fell into the
  ordinary "拉起你的手" recovery branch like any other separation,
  which is the intended degraded behavior.
- **Lineage check**: `libs/bmxkx2001/work/d/xiakedao/npc/
  longx.lpc` is a **byte-for-byte identical copy** of the pre-fix file
  (confirmed via `diff`) — same missing `return`, same vulnerable
  shape, almost certainly equally capable of segfaulting that lib's
  driver under the same real-time-wait-mid-escort conditions. Not fixed
  there (out of scope for this pass per the task instructions — flagged
  for the orchestrator/a future pass on that lib). This bug is a
  mudlib-source logic bug (missing `return`), not a driver-generic
  pattern by itself, but the *consequence* (an LPC-reachable path to a
  driver segfault via `call_out` scheduled against a soon-to-be-freed
  object) is a driver-generic risk worth watching for anywhere a
  self-rescheduling `call_out` chain has more than one reschedule call
  reachable from the same function body — see the draft AGENTS.md
  class in this task's final report.

### Bug 2 candidate investigated, NOT confirmed as a real bug (documented so the next pass doesn't re-chase it)

While repeatedly registering/re-registering the same test id in quick,
overlapping succession early in this pass (deliberately messy,
back-to-back connections, several left to time out mid character-
creation), one `register` → immediate-reconnect sequence surfaced the
"您要将另一个连线中的相同人物赶出去，取而代之吗？" (duplicate-login)
prompt where a clean netdead-reconnect was expected — looked exactly
like `regid.lpc`'s `register_char()`'s `destruct(body)` (on the very
object that is itself the current interactive session) not actually
freeing the id in time for a fast subsequent reconnect. Investigated at
length (traced `enter_world()`/`reconnect()`/`find_body()` in
`logind.lpc`, `net_dead()`/`reconnect()` in `clone/user/user.lpc` and
`clone/user/login.lpc`). **Could not reproduce it under a controlled,
single-character, non-overlapping test** (`cetest`: register → new
password → immediate reconnect, repeated cleanly multiple times, always
a clean netdead-reconnect, never the duplicate-login prompt). Current
conclusion: the one observed instance was almost certainly an artifact
of the deliberately chaotic overlapping-connections test pattern used
earlier in this pass (multiple abandoned in-flight `LOGIN_OB`
registrations for the same id) rather than a reproducible bug in the
real register/reconnect path — recorded here, not filed as a bug, so a
future pass doesn't need to re-investigate from scratch.

### Also verified working, no bugs found

- **Net-dead (unclean) disconnect + reconnect, both prompt and after a
  real wait**: reproduced constantly and incidentally throughout this
  pass (every `mudclient.py` invocation in this session that didn't end
  in an explicit `quit` is itself an unclean disconnect) — every single
  reconnect, including several after multi-minute real waits and one
  across an actual driver crash/restart (which, expectedly, reverted to
  each character's last explicitly-*saved* location rather than their
  live in-memory one — normal for any crash, not a bug), correctly
  restored the player to their real in-game location with `look`/
  `score` both correct. `clone/user/user.lpc`'s `net_dead()`/
  `reconnect()` pair (destructs only the old *login* link object,
  remembers `link_ob`/room via `nosave`/`temp` vars, `reconnect()` is
  actually wired up and called by `logind.lpc`) is a sound, already-
  defensive implementation — this lib does **not** exhibit the AGENTS.md
  §7.20 void-parking class or the §7.21 stranded-mid-wizard class:
  the pre-registration character-creation wizard runs entirely on the
  `LOGIN_OB` connection object itself (not a separate persistent player
  body), and that object's own `net_dead()` just destructs it after a
  1-second grace timer (`clone/user/login.lpc`) — an unclean disconnect
  mid-creation simply abandons that attempt cleanly, with no permanent
  stranding, confirmed by reconnecting after several such abandoned
  attempts and always landing at a fresh `您的英文名字：` prompt.
- **Clean `quit` + real wall-clock-gap reconnect**: state (location,
  stats, inventory) persisted correctly across a genuine `quit` and a
  later fresh login, for both `qinxia` and `linxue`. `debug.log` stayed
  free of `error:`/`Too deep recursion`/fatal lines after every `quit`
  performed in this pass.
- **Safe sparring (`fight`)**: confirmed working exactly as documented
  (see `qinxia`'s playthrough above).
- **Organic skill learning**: confirmed working (`xue dizi force`,
  `cha` showed the new skill).
- **Sect-join code path**: confirmed reachable and functioning as
  designed (`bai lingxiao`, correctly declined per generation rules).
- **Admin account** (`fluffos`/`Mud@2026`, seeded in an earlier pass):
  re-verified end to end this pass — login, `look`, `update
  /d/xiakedao/npc/longx` (recompiled the fix live), clean `quit`, all
  correct; `(admin)` privilege intact.

### Explicitly NOT verified live (honest gaps, not silently skipped)

- **Shop `list`/`buy` at an actual merchant**: not completed. This
  lib's real starting zone (`d/xiakedao/`, the island) is a large,
  fully self-contained ~100-room tutorial/quest area with **no shop
  anywhere inside it** (confirmed by grep — no `inherit ... SHOP` in
  any `d/xiakedao/*.lpc`); reaching a real shop requires leaving the
  island for the mainland, which (per this lib's own design) generally
  happens via a sect's own recruitment escort (e.g. following 凌逍 to
  actual 华山) rather than a direct exit — not completed within this
  pass's time budget. Did verify a related, simpler item-economy
  mechanic instead: `ask han about 武器` (黄衣大汉, an island NPC)
  hands out a free weapon, confirmed working.
- **Real (lethal) combat and death/respawn**: not attempted. Only the
  safe `fight` sparring form was exercised live; `kill`/`hit` and the
  death → 鬼门关 → 武庙 revival flow described in `doc/help/newbie.dec99`
  were not tested, given the time already spent on the crash
  investigation/fix/re-verification above.
- **Full sect enrollment** (an actual `bai` acceptance, not just the
  correctly-declined attempt at 凌逍): would require reaching one of
  the actual sect masters (岳不群/宁中则 for 华山, per `doc/help/intro`)
  off-island — not attempted within this pass's budget. The mechanism
  itself (`feature/apprentice.lpc`'s `create_family`/
  `recognize_apprentice`/`bai.lpc`) was verified structurally and via
  the one live, correctly-declined attempt.

## WASM 修复摘要（迁移自 meta.json 的 group_note）

侠客行 XKX 基础版。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 40 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## §7.112 跨库扫描修复（无常 NPC 重连触发重复轮回链）

- **`d/death/npc/{wgargoyle,wgargoyle1,bgargoyle}.lpc` 的 `init()` 无条件调度 `death_stage` call_out 链（AGENTS.md §7.112）**：这三个文件原本都没有任何去重判定——`enable_commands()` 会在同房间内向所有对象重播 `init()`，玩家哪怕只是断线重连一次，也会在原有的 `death_stage`/最终判官对话链之上再叠一条新链，导致重复的判官对白、重复扣血/转生等竞态错误。已仿照同族已修复库（`dtsl`/`dtsl2`/`dtslmud`/`jym`/`xuanjianlu`）的做法，给每个 `init()` 加上按受害者存的 `set_temp("death_stage_active", 1)`/`query_temp(...)` 门槛判定，并在 `death_stage()` 的每一个退出点（角色离场、黑无常"阳人退回"分支、链条走完转生）里 `delete_temp(...)` 清除标记。三个文件形状与 `xkm` 版本几乎一致（均无 `final_death_stage` 分支）。已用独立驱动干净编译+启动验证，未发现残留 save 数据变化。
