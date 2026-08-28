# es1_win.rar → `es1_win`

- Archive: `archives/es1_win.rar` (10MB — "东方故事(蓝天)"/"Eastern Story
  (Blue Sky)". **东方故事 (Dongfang Gushi / "Eastern Story") is one of
  the foundational Chinese wuxia mudlib bases** — several other archives
  in this collection reference/derive from it (`东方故事二.rar` is a
  direct sequel; lib #1's includes mention it too).
- Mudlib root: `es1/` at archive top level. Config at top-level
  `config.cfg`.
- Port: **40009**.

## Status: DONE — boots clean, playable over telnet

Full flow confirmed: banner, "东方故事现在没人." (no one online) status
line, name-length validation, name re-prompt.

## What was fixed

1. Encoding: 8238 converted, 1674 already UTF-8/ASCII, 82 skipped binary,
   17 lossy. `.c`→`.lpc`: 6933 files, 1101 refs + 2 angle-bracket
   `#include<x.c>` refs auto-fixed.
2. `master.lpc`'s `domain_file()`: `explode("/", "/")` (called by the
   DRIVER ITSELF during its own bootstrap domain-assignment, per
   `mudlib_stats.cc`) returns a **zero-length array** in this driver
   rather than `({ "", "" })`, and the existing `if(!path) return
   "NONAME";` guard doesn't catch a non-null-but-empty array — `path[0]`
   threw "Array index out of bounds", failing master's own compile.
   Added `|| !sizeof(path)` to the guard.
3. `std/object/prop.lpc` had `#include </std/object/prop_logic.lpc>`
   (angle brackets, file in the SAME directory) — the exact §8d pattern
   from lib #3, but with an important addition to that lesson: **the
   `master::get_include_path()` fix does NOT help here**, because this
   particular file gets compiled during PRELOAD, before
   `compiler_vm_context` is set (confirmed via the driver source,
   `lexer_utils.cc`'s `init_include_path()`: "No VM context: keep the
   config-file include path as-is -- there is no master object to ask").
   `get_include_path()` silently never gets consulted for preload-time
   compiles. **Fixed by changing the include to quotes instead**
   (`#include "/std/object/prop_logic.lpc"`) — quote-style local-directory
   resolution doesn't depend on any master apply/VM context at all, so
   it's the more robust fix regardless of when a file happens to compile.
   Also added the `get_include_path()` apply to this lib's master.lpc
   anyway (harmless, helps genuinely-dynamic compiles), but the REAL fix
   for this specific case was the quote change.
   **This failed to reach the login prompt with NO error output at all**
   until traced with temporary `write("DEBUG X\n")` statements inserted
   into `logind.lpc`'s `logon()` — the actual error (`_query`/`_delete`/
   `_set` undefined, cascading from the broken include, inherited all the
   way from `/std/room/room` down to `/d/std/rooms/netdead`) was being
   thrown during the very first connection's `active_users()` call, and
   the DRIVER's own `new_conn_handler` catches ANY error escaping
   `logon()` and just silently disconnects the user with zero message —
   so a real compile-cascade bug during first-connect can look exactly
   like a hung/dead server with nothing in reach except the debug.log.

## Known remaining issues (documented, not fixed)

- 1260 lpcc-sweep failures (of 6933). A meaningful chunk (`inherit ROOM;`
  failing with "unexpected L_IDENTIFIER" in `d/noden/drow/*`,
  `d/noden/hawk/*`, `std/adt/iqueue.lpc`, and others) trace to files that
  rely on the auto-included `global include file` (`globals.h`) for
  macros like `ROOM`, but `globals.h`'s own `ROOM` definition is
  commented out with a DIFFERENT (stale/wrong) value than the real one in
  `include/mudlib.h` (`"/std/room"` vs `"/std/room/room"`) — so
  uncommenting it isn't a safe fix; the affected files are missing an
  explicit `#include <mudlib.h>` instead. Zone names (`noden`, `drow`,
  `hawk`) suggest legacy/template filler content possibly never used in
  the live wuxia game, not something actively maintained — not fixed
  given the scale (dozens of files, no single-point fix) and that it's
  off the critical boot/login path.
- Not otherwise triaged past a category scan given time constraints.

## How to run

```
cd libs/es1_win
~/src/fluffos/build-debug/src/driver config.fluffos
python3 ../../scripts/mudclient.py 127.0.0.1 40009 --timeout 10 --send "" --send "look" --send "quit"
```

## Re-verification pass: driver rebuild + LPC formatter + WASM build

- **Formatter**: ran `format-corpus.mjs` over all 6933 `.lpc` files;
  6772 reformatted in place, 5 already-clean/unchanged, 156 refused
  (`errors`, expected on messy legacy code per the tool's own
  token/byte-identity self-check) — not chased down individually.
- **Native retest against rebuilt driver**: booted clean (zero fatal
  errors, "Initializations complete") against the freshly-rebuilt
  `build-debug/src/driver`. Full registration verified with a real
  Chinese name ("令狐冲"/Linghuchong, human male) all the way into the
  starting room (远风镇冒险者公会); `look`, `score`, `quit` all produced
  correct, real output (score showed the right race/gender/age line,
  quit produced the real farewell/drop-inventory text).
  **Regression found + fixed** (pre-existing since the original
  conversion commit, not caused by the reformat or driver rebuild, but
  only now caught by this pass's post-login-output check): `std/user.lpc`'s
  `setup()` unconditionally `write()`s a literal debug/garbage string
  `"aadsaaaaaaaaaaaaaaaaaaaa\n\n"` to every player on every login, right
  before the real "last logon" message. Confirmed absent from
  `raw/es1/std/user.c` under any encoding, so it was accidentally
  introduced (not original content) at some point before or during the
  initial conversion commit. Fixed by deleting the stray `write()` call;
  re-verified clean (no more garbage line) on a second full
  registration + login run, zero debug.log errors either run.
- **WASM test**: booted cleanly under `build-wasm` (the only errors are
  the expected non-fatal `Undefined function socket_create`/
  `socket_error`/`socket_bind` in `/adm/daemons/network/cmwhod.lpc`
  during `master.lpc`'s `socket_preload()` — caught by the master's own
  error handler, same as a missing daemon natively, no cascade). Logged
  into the existing test character over WASM, reached the game room, and
  `look` produced the correct room description. This lib's own IP-check
  step (`[OKIP]`) merely warns ("你没有设定任何 IP Address 检查") rather
  than gating login, so it is **not** affected by the documented
  `query_ip_number()` WASM limitation — full WASM login + play works.

## WASM-enablement pass (loopback / admin seeding)

- **Loopback ban bypass** (§1.3b): `adm/daemons/banish.lpc`
  `check_banned_site()` (~line 75) — short-circuit at top: loopback /
  empty / non-string / `localhost` / `127.` names return 0 (not banned).
  Gate is fed `query_ip_name()` (hostname), called from `logind.lpc:242`
  and `:573`. Original ban logic unchanged below.
- **Uptime gate**: none that reject/destruct. Only `uptime()` in login
  daemons (`logind.lpc:87`) grants extra user slots first 12h — content,
  kept.
- **Anti-flood throttle**: none. "试太多次" is a per-session password
  retry cap, not a per-IP throttle.
- **Admin account** (§1.5): `fluffos` / `Mud@2026`, display 浮浮. Granted
  via `/adm/etc/groups` (added `fluffos` to `(root)` and `(admin)`) plus
  connection save `data/std/connection/f/fluffos.o` (`wizard 1` triggers
  `enable_wizard()` in `std/body.lpc:199`; `domains` level `archwizard`).
  Verified `update /adm/daemons/statsd` loads OK as fluffos.
- **Fail-closed retrofit** (2026-07-24 security correction): the loopback
  check(s) above originally also treated an empty/non-string IP as
  loopback (defensive fallback for the then-broken `query_ip_number()`).
  Since the driver's IP-reporting bug is now fixed upstream (WASM
  reports a clean `127.0.0.1` like native), that fallback was removed —
  loopback is now strictly `stringp(ip) && (ip=="127.0.0.1" ||
  ip=="::1" || ip[0..3]=="127.")`; anything unparseable/empty is
  untrusted/remote and goes through the original gate logic. Retested:
  fluffos login + `look`/`quit` still clean over loopback.
- **Save files to force-add** (untracked, NOT gitignored):
  `libs/es1_win/work/data/std/connection/f/fluffos.o`,
  `libs/es1_win/work/data/std/user_ob/human/f/fluffos.o`.

## 深度功能测试 / Deep functional test (2026-07-24)

First real *playthrough* pass (AGENTS.md §10.7) — every prior pass on
this lib had only verified registration + `look`/`score`/`quit` + admin
login, never a continuous real playthrough. Native driver
(`build-debug`), one continuous session per checklist item, with
several deliberate net-dead disconnect/reconnect probes. Test
characters (both **kept**, not cleaned up, as evidence):
- `Shenqingxue` / 沈清雪 (id `shenqingxue`), password `TestPass123`,
  human female, adventurer class. Primary playthrough character: fought
  and killed a `野狗`(dog) at 远风镇西门, ended with 695 exp, 14/30 HP,
  currently sitting in `/d/adventurer/hall/adv_guild` after a clean
  `quit`. Save files: `work/data/std/connection/s/shenqingxue.o`,
  `work/data/std/user_ob/human/s/shenqingxue.o`.
- `Muyunlan` / 沐云岚 (id `muyunlan`), password `TestPassX9`, human
  male. Created specifically to reproduce the net-dead-during-
  registration bug below (see "Bugs found and fixed" #1); currently
  parked normally in `/d/adventurer/hall/adv_guild`. Save files:
  `work/data/std/connection/m/muyunlan.o`,
  `work/data/std/user_ob/human/m/muyunlan.o`.

**Correction to this file's own earlier "How to run" section**: `log
directory : /log` in `config.fluffos` resolves against the driver's
LAUNCH cwd, not the mudlib root (AGENTS.md §5.2) — with the documented
`cd libs/es1_win && driver config.fluffos` invocation, debug.log lands
at `libs/es1_win/log/debug.log`, **not**
`libs/es1_win/work/log/debug.log` (a long-stale file left over from an
earlier era/invocation convention that this pass initially — and
wrongly — kept checking for several rounds before noticing it never
changes). Use the top-level `log/` path when grepping for errors on
this lib.

### Bugs found and fixed

**1. Net-dead disconnect during the registration Q&A permanently
strands the account in the net-dead holding room on every future
login — `std/user.lpc:902` `restart_heart()`.**

- Symptom: a player who disconnects (network drop, not `quit`) at ANY
  point between `newuserd.lpc`'s `get_real_name()` (which calls
  `body->setup()`, printing the MOTD news and the "[请按 RETURN 键继续]"
  prompt) and that prompt's own `complete_setup()` callback actually
  placing them in the world — i.e. anywhere in the ordinary gap between
  finishing the registration questions and pressing RETURN to continue
  — reconnects, on every future login, directly into
  `/d/std/rooms/netdead` ("时间的缝隙", the lib's net-dead holding
  room/portal hub), permanently. Nothing else in the login flow ever
  routes them anywhere else again — `get_password()`'s "existing body
  found, not interactive" branch (`adm/daemons/logind.lpc:323-328`)
  just calls `body->restart_heart()` unconditionally. Reproduced live
  end-to-end with a fresh character (`Muyunlan`): registered through
  the "[请按 RETURN 键继续]" prompt, let the connection close without
  answering it (a realistic disconnect point — the exact same "one more
  screen before real gameplay" moment any client crash or network drop
  could hit), reconnected with the correct password, and landed
  straight in "时间的缝隙" — confirmed via the room's own
  `d/std/rooms/netdead.lpc` `set_short()` string, and via the player's
  own `.o` save file having no `"linkdead_room"` key at all (only ever
  written when `net_dead()`'s `env` is non-null). The room does have an
  undocumented escape (`enter door`), but it's a random teleport to one
  of six hardcoded coordinate rooms that ALSO immediately deducts 10%
  of the player's current HP on "landing" — actively harmful for a
  fresh, zero-inventory, zero-experience character, and undiscoverable
  without reading source.
- Root cause: `std/user.lpc`'s `net_dead()` (~line 843) always calls
  `move_player(LINKDEAD_ROOM, "SLIENCE")` as a fallback holding pen, but
  only records `set("linkdead_room", env)` `if (env)` — i.e. only if the
  player already had a real environment when they went net-dead. A
  player who disconnects during the registration Q&A/MOTD gap has
  never been placed in ANY room yet (`complete_setup()`, the function
  that actually does `move(start_room)`, hasn't run), so `env` is null,
  `linkdead_room` never gets set, and `restart_heart()`
  (`std/user.lpc:902`) — the function that's supposed to restore a
  net-dead player's pre-disconnect location — has nothing to restore
  to and just leaves them sitting in `LINKDEAD_ROOM` with no further
  recovery path. Same general shape as AGENTS.md §7.21 ("reconnecting
  mid a mandatory pre-gameplay wizard permanently strands a player" —
  `input_to()` chains don't survive `net_dead()`/reconnect, and nothing
  else re-triggers the interrupted flow), but a different lineage and a
  meaningfully different concrete manifestation: §7.21's instance
  blocks EVERY command behind a catch-all after reconnect; this one
  doesn't block anything — the player can move, talk, fight — they're
  just permanently misplaced in a hazardous portal room instead of
  their intended start room, with no error or warning ever shown.
- Fix (`std/user.lpc:921-932`, inside `restart_heart()`): when
  `linkroom` is unset, check whether the player is currently sitting in
  `LINKDEAD_ROOM` anyway (the only way that combination can happen is
  the never-placed-yet case above) and, if so, call
  `this_object()->complete_setup("")` — the exact same function the
  original "press RETURN" prompt would have called — to finish the
  interrupted placement. Before/after:
  ```lpc
  // BEFORE
    linkroom = (object)this_object()->query("linkdead_room");
    if (linkroom) {
      this_object()->move_player(linkroom, "SNEAK");
      tell_room(linkroom, ...);
    }

  // AFTER
    linkroom = (object)this_object()->query("linkdead_room");
    if (linkroom) {
      this_object()->move_player(linkroom, "SNEAK");
      tell_room(linkroom, ...);
    } else if (base_name(environment(this_object())) == LINKDEAD_ROOM) {
      this_object()->complete_setup("");
    }
  ```
- Verified: reproduced pre-fix exactly as described above (character
  `Muyunlan`, first reconnect landed in "时间的缝隙" with the debug.log
  showing no error at all — this is a genuinely silent stranding, zero
  log signal, matching the AGENTS.md §7.20 detection warning). Restarted
  the driver with the fix, re-registered `Muyunlan` fresh, stopped again
  at the same "[请按 RETURN 键继续]" prompt without answering, waited
  for the driver to notice the disconnect, reconnected with the correct
  password: now lands correctly in `/d/adventurer/hall/adv_guild` (the
  real `START` room), `目前权限：player` prints as on a normal fresh
  login, `look`/`score` both correct. Also re-verified the NORMAL
  net-dead path (disconnect/reconnect while ALREADY placed in a real
  room, both promptly and after a real 75-second wall-clock wait) is
  unaffected and continues to restore the exact pre-disconnect room —
  see "Net-dead and reconnect testing" below.
- Lineage note: `esI` (this lib's documented sibling, AGENTS.md §11)
  shares the identical `net_dead()`/`restart_heart()`/`LINKDEAD_ROOM`
  shape (same TMI/ES ancestry) and was not checked/fixed here — flagged
  for the orchestrating session to port if it does the same lineage
  sweep it's done for other bugs found this round.

**2. `#include <compress_obj.h>`'s `set_default_ob(__FILE__)` points
every affected clone at the wrong file, crashing on any property
lookup that falls through to it — already-cataloged AGENTS.md class
§7.14 ("`__FILE__` in an `#include`d fragment expands to the
FRAGMENT's path, not the includer"), previously seen on `xlqy_early`/
`longyunmeng`; this is a new (fixed) instance of the same class.**

- Symptom, reproduced live: a fresh character standing in the one shop
  in the game (`/d/noden/farwind/shop`, reachable straight from the
  start room) typing the ordinary `list` command to see what's for
  sale crashed with a real, on-screen, **uncaught-looking** runtime
  error (driver's default handler did catch it, but the trace printed
  straight to the player, not silently swallowed):
  ```
  执行时段错误：*call_other() couldn't find object '/include/compress_obj.h'.
  程式：/std/object/ob.lpc 第 127 行
  物件: /obj/bandage#40
  ```
  Every item in this lib that inherits only the lightweight
  `/std/object/ob` base (checked: `obj/bandage.lpc`, `obj/bowl.lpc`,
  `obj/torch.lpc`, `obj/map.lpc`, `obj/bag.lpc`, `obj/light_ball.lpc`,
  and ~35 more across `d/`/`u/`, one `grep -rl compress_obj` away) is
  affected, since `set_default_ob()`'s stored value is consulted
  (`std/object/prop.lpc:126-127`, `value = default_ob->query(label)`)
  on ANY property read that isn't already set directly on the specific
  clone — trivially reachable any time such an item's price/weight/etc.
  needs to be displayed, which is exactly what a shop's `list` does for
  every item it sells.
- Root cause: `include/compress_obj.h` is a bare code FRAGMENT (no
  function wrapper) meant to be pasted, via `#include`, into the very
  first line of ~40 different objects' `create()` bodies, to make each
  one register itself as its own memory-saving "default value" fallback
  target. Its `set_default_ob(__FILE__)` line assumes `__FILE__`
  resolves to whichever OUTER file it was pasted into (e.g.
  `/obj/bandage`) — but on this driver `__FILE__` tracks the PHYSICAL
  file currently being lexed, which while processing this fragment's
  own text is the fragment itself, `/include/compress_obj.h`, regardless
  of where it was `#include`d from. Every one of the ~40 affected
  objects' blueprints therefore silently self-registers as
  "`/include/compress_obj.h`" (a header, never a loadable/compilable
  LPC object) instead of their own real path — inert until the first
  property lookup that actually needs the fallback, at which point
  `call_other("/include/compress_obj.h", "query", label)` throws.
- Fix (`include/compress_obj.h:6-15`), matching AGENTS.md §7.14's
  documented remedy (there: swap in `file_name(this_object())`; here:
  `base_name(this_object())`, since `set_default_ob` wants the
  BLUEPRINT's bare path for `call_other()`, not `file_name()`'s
  clone-numbered variant):
  ```lpc
  // BEFORE
  if ( clonep(this_object()) ) {
      set_default_ob(__FILE__);
      return;
  }

  // AFTER
  if ( clonep(this_object()) ) {
      set_default_ob(base_name(this_object()));
      return;
  }
  ```
  `base_name(this_object())` is evaluated at RUNTIME inside the actual
  compiling object's own `create()`, so it always correctly resolves to
  whichever real file (e.g. `/obj/bandage`) the fragment was pasted
  into, regardless of the header's own physical path.
- Verified: reproduced the crash live pre-fix exactly as above (shop
  `list` with a `bandage` in stock). Applied the one-line header fix,
  killed and rebooted the native driver, re-ran the exact same
  `Shenqingxue` → walk to shop → `list` sequence: full item list now
  renders cleanly (油灯/绷带/魔法地图/火把 with prices), no error, no
  new debug.log line. Also exercised `buy torch`/`value torch` (correct
  "you don't have money"/"you don't have that" responses, no crash) —
  a genuine purchase wasn't completed since the character has no
  starting money and none was farmed for this pass; see "Not verified
  live" below.
- Lineage note: `esI`'s `include/compress_obj.h` is byte-identical and
  unfixed (checked, not touched) — same flag as bug #1 above, for the
  orchestrating session's lineage sweep.

### What was tested and confirmed working

Full continuous playthrough as `Shenqingxue` (real Chinese name, human
female adventurer), covering the whole §10.7 checklist:

- **`help start`** (`doc/help/c_start`) read first — this lib's own
  newbie guide, matches the classic TMI/Discworld-family help-file
  house style (`c_about`, `c_rules`, `c_help_screen`, etc., all real,
  substantial Chinese content, not filler). Correctly documents the
  guild-room `cost`/`advance`/`train`/`list`/`join` command set as the
  organic skill/attribute path (no NPC-dialogue teacher in this lineage
  — the "teacher" IS the guild room itself) and gives the real
  starting-zone layout (远风镇/冒险者公会).
- **Registration**: full flow (English login id → confirm new name →
  Chinese display name → password/confirm → gender → race → email →
  real name → MOTD/RETURN) reached the real start room,
  `/d/adventurer/hall/adv_guild`, correctly.
- **`look`/`score`/`i`**: all correct at every state change (fresh
  registration, post-training, post-combat, post-reconnect).
- **Guild skill/attribute training** (this lineage's organic path —
  no NPC teacher, the guild room's own `cost`/`advance`/`train`/`list`
  commands, per `std/guild.lpc`): `list` showed the adventurer guild's
  7 trainable skills with real costs; `cost` showed the real
  attribute/skill upgrade table; `advance str` correctly rejected for
  insufficient "usable" exp (678 total vs 389 needed from a smaller
  advance-pool) while `train unarmed` succeeded, correctly deducting
  exp and printing "你的空手搏斗技能现在提升到 1 了。" — the two-tier
  exp economy (total exp vs. per-level advance-pool) behaves as
  documented.
- **`join`**: tested at the already-joined adventurer guild — correctly
  replied "你已经是本公会的成员了！" rather than silently no-opping;
  no separate sect/faction system exists beyond the four documented
  guilds (adventurer/mage/healer/knight/monk per `help start`), each
  gated behind the same `join`-in-guild-room mechanic.
- **Exploration**: walked 远风镇冒险者公会 → 大街 → 商店/广场/微风路/
  西门, reading room `.lpc` source to resolve exits/navigation puzzles
  (notably the smithy's boxes→ladder→climb sequence, which needs a
  light source the character can't afford — see "Not verified live").
  This lib's virtual-object convention (`_smain.lpc`/`_nmain.lpc` style
  underscore-prefixed real files served under their unprefixed name via
  each zone's own `virtual/server.lpc`, a genuine TMI feature, not a
  bug) confirmed working correctly throughout.
- **Combat**: no dedicated safe-sparring dummy exists in this lib
  (`grep -r accept_fight` returns zero hits anywhere in the tree, and
  `doc/wizhelp/c_combat` is pure mechanics documentation, not a
  practice-target pointer) — used a real level-1 `野狗`(dog,
  `d/noden/farwind/monster/dog.lpc`, `set_level(1)`, low stats) at
  远风镇西门 instead, per the checklist's fallback of picking a
  deliberately weak wild target. `consider`/`kill` both worked; full
  turn-by-turn combat resolved correctly (accuracy/miss/damage/gore
  messages, `hp` mid-fight status line), character took real damage
  (26→14 of 30 HP) and the dog died correctly ("狗死了。"), leaving a
  corpse and awarding exp (605→695). No crash, no over-death, no eval
  errors.
- **Net-dead and reconnect testing** (AGENTS.md §7.20/§7.21 checklist
  item): beyond the bug #1 repro above, separately confirmed the
  NORMAL case is healthy — disconnected `Shenqingxue` uncleanly
  (socket close, no `quit`) while she was properly placed in
  `/d/adventurer/hall/adv_guild` with real HP/exp state, reconnected
  PROMPTLY: `重新连线完毕`, landed back in the exact same room with the
  exact same HP (14/30) and exp (695). Repeated with a real 75-second
  wall-clock wait before reconnecting (via a foreground timed wait, not
  a backgrounded one): identical correct result, zero new debug.log
  lines either time.
- **Quit + debug.log**: every `quit` in this pass (multiple, across
  different session states) was followed immediately by a grep of the
  CORRECT `libs/es1_win/log/debug.log` (see the correction note above)
  — all clean, no new `error:`/`Too deep recursion`/fatal lines, in
  clear contrast to the compress_obj.h crash, which WAS visibly loud on
  screen (a good reminder that "on-screen crash" and "logged crash" are
  two independent signals, not synonyms — neither implies the other on
  this lib).
- **Clean-quit relogin**: quit cleanly, reconnected fresh (full
  registration-shaped relogin path, not the net-dead reconnect path) —
  correctly restored to the guild room with all state (HP/exp/skills)
  intact, confirming `complete_setup()`'s `start_room =
  getenv("START")`-then-guild-room design intentionally always
  restarts a fresh session at the player's guild rather than their
  exact last room (distinct from, and not to be confused with, the
  net-dead reconnect path's exact-room restore).

### Addendum (2026-07-24): §7.12 `tell_room()` fix ported from sibling `esI`

`esI`'s own §10.7 pass found that `adm/simul_efun/tell_room.lpc`'s 2-arg
call shape (`exclude` defaulting to `int 0`, rejected by `message()`)
crashes `adm/daemons/weather_d.lpc`'s self-rescheduling `change_phase()`
`call_out` — no enclosing `catch()`, so the uncaught throw aborts the
function before it reaches its own tail-end reschedule, **permanently
killing the day/night phase daemon for the rest of that boot** the first
time any outdoor room is visited (`set_outside()` registers it, some
phases in `adm/etc/daytime.data` are as short as 1 second). Confirmed
via `diff` that this lib's `tell_room.lpc` is byte-identical to `esI`'s
pre-fix copy, so it carries the same bug (not independently reproduced
live on THIS lib during either pass — plausibly a session-timing/
room-visited difference). Ported the same one-line fix:
```lpc
message("tell_room", msg, room, exclude || ({}));
```
Sanity-checked only (fresh boot + existing test character
`shenqingxue` login/`look`/`quit`, clean, zero new debug.log errors) —
not a full independent §10.7 replay, since this lib was already marked
done. See `libs/esI/NOTES.md`'s own "深度功能测试" section (bug #5) for
the full live-reproduction detail (including a direct `eval`-command
proof of the crash and the fix).

### Not verified live (explicitly)

- **A completed shop purchase**: `Shenqingxue` starts with zero money
  (身无分文) and no in-session way to earn any was pursued within this
  pass's time budget; `buy`/`value` were exercised and behave correctly
  (proper rejection messages, no crash) but no item was actually
  bought. Code review of `std/seller.lpc`/`shop.lpc` suggests the buy
  path is otherwise ordinary and low-risk, but this is not the same as
  a live-verified purchase.
- **Death and respawn**: the one real fight run to completion was
  survivable (14/30 HP remaining at the end); deliberately losing a
  fight to reach the death/ghost/respawn flow was not attempted this
  pass — reason: time budget, not because it looked risky or was
  avoided for any code-quality concern.
- **An UNRESOLVED, likely-real but NOT root-caused timing anomaly**:
  on a handful of repro attempts, the FIRST movement command issued
  immediately (within 1.5-3 real seconds) after moving into a room
  being compiled for the very first time this boot (e.g. `east` from
  `/d/adventurer/hall/adv_guild` into `/d/noden/farwind/_smain.lpc`
  right after a fresh driver boot) sometimes failed silently (the
  command never appears to reach `std/user/tsh.lpc`'s `push_cmd()` at
  all — confirmed once via temporary instrumentation, then reverted)
  or produced the driver's generic default-fail message instead of
  actually moving. The SAME sequence against an already-warm room (one
  any player has visited since boot) was reliable across every attempt
  (7+), and a longer 3-second gap between commands did NOT reliably
  fix it, which argues against this being purely a `mudclient.py`
  send-pacing artifact. This has the same general "first-ever compile
  this boot only" timing-sensitivity shape as AGENTS.md §7.17/§7.19/
  §7.22, but a different concrete symptom (an apparently-dropped queued
  player command, not a crash or corrupted state) that doesn't cleanly
  match any of those three, and repeated attempts to get a clean
  instrumented trace of an actual FAILING run were unsuccessful (adding
  `write()` instrumentation itself changes the timing enough that the
  instrumented runs happened not to reproduce it). Given the real-world
  impact is narrow — only the very first player to explore a given room
  after each server restart, and only if they move unusually fast for
  the first couple of commands after arriving — this was left
  UNFIXED and is reported here rather than silently dropped, for
  whoever next has time to pin it down with a cleaner reproduction
  setup (a raw packet-capture of the two client sends plus driver-side
  socket-read logging would likely settle whether this is input
  coalescing during a slow synchronous first-compile, which was this
  pass's leading but unconfirmed hypothesis).

## Deep functional test round two (2026-08-14)

Independently re-verified against current code rather than trusting the
round-one writeup above. Confirmed all 3 prior fixes still hold (the
net-dead-during-registration `restart_heart()` fix, the
`compress_obj.h` `__FILE__`/§7.14 fix, and the ported §7.12
`tell_room()` fix), and found one new §7.90-class issue: a real preload
crash, not just a theoretical risk.

### New fix: §7.90-class eval-cost abort during boot preload — `chinese_d`'s dictionary build genuinely failed, not just at-risk

`config.fluffos` had `maximum evaluation cost : 300000`, below even this
project's common 700000 template default. Unlike some other libs this
session where a low eval-cost config was flagged as a latent risk without
a confirmed failure, THIS lib's boot log showed a real, live preload
crash:
```
Eval interrupted: object adm/daemons/chinese_d cost limit reached, limit: 300000 usec.
执行时段错误：*Too long evaluation. Execution aborted.
程式：/adm/daemons/chinese_d.lpc 第 60 行
呼叫来自：/adm/daemons/chinese_d.lpc 的 make_dictionary() 第 60 行
执行时段错误：*Can't catch eval cost too big error.
```
`chinese_d`'s `make_dictionary()` (called from its own `create()`, itself
called from `master.lpc`'s `preload()`) never finished building its
dictionary — every boot, unconditionally, not an occasional flake. Fixed
with the established §7.90 remedy: `maximum evaluation cost` → `5000000`.
Verified: fresh reboot, zero `cost limit`/`Too long evaluation`/`Can't
catch` hits anywhere in the boot log.

### Re-verified live: all 3 round-one fixes still hold

- **`compress_obj.h` §7.14 fix**: code-confirmed `set_default_ob(base_name(this_object()))`
  still present (with its explanatory comment), then live-verified by
  walking the exact original crash route as admin (远风镇冒险者公会 →
  east → east → 商店) and running `list` — full item list rendered
  cleanly (油灯/绷带/魔法地图/火把 with prices), zero new `work/log/debug.log`
  lines (checked the file's line count before and after the whole
  session: unchanged at 1035).
- **§7.12 `tell_room()` fix**: code-confirmed `exclude || ({})` still
  present in `adm/simul_efun/tell_room.lpc`.
- **Net-dead-during-registration `restart_heart()` fix**: code-confirmed
  the `else if (base_name(environment(this_object())) == LINKDEAD_ROOM)
  { ... complete_setup(""); }` branch is still present. **Not re-walked
  live this pass** (requires a fresh registration interrupted mid-MOTD,
  then a real disconnect/reconnect cycle — expensive relative to this
  pass's time budget given the fix is a small, previously-thoroughly-
  verified, self-contained conditional) — noted honestly per this lib's
  own established "not verified live" convention rather than silently
  re-claimed as freshly tested.

### Other checklist items: mostly not applicable, different lineage architecture

This lib's TMI/Discworld-family codebase doesn't share the ES2/大唐
lineage's `adm/simul_efun/file.lpc`/`cmds/wiz/update.lpc` shapes this
session's checklist was tuned around — no `update.lpc` exists at all (the
wizard reload command is `_update.lpc`, invoked as `update`, a different
implementation entirely; tested live, works correctly). `log_error()`
(`adm/obj/master.lpc:348`) never broadcasts compile diagnostics to the
connected player at all (only writes to a log file, with a fallback
`write()` only on write FAILURE) — confirmed this lineage simply doesn't
have the §7.10-class leak risk by construction, not because it's
correctly gated. `work/log/` is a real, git-tracked, already-existing
directory (not gitignored, unlike some other libs), so no
`assure_file()`-class gap applies to its own log writes either.

### A cosmetic finding, not a bug: `fluffos`'s displayed rank shows "apprentice", not an admin-sounding title

First login this pass printed `目前权限：apprentice`, which looked
concerning at a glance. Investigated rather than assumed broken: this
label comes from `DOMAIN_D->query_domain_level(player)`, a separate
"domain" title-display system, NOT from the actual ACL groups that
control real permissions. `/adm/etc/groups` still correctly lists
`fluffos` under both `(root)` and `(admin)`. Verified REAL admin access
directly rather than trusting either label: `update /adm/daemons/logind`
succeeded ("Updated and loaded."). Left the cosmetic domain-title as-is —
this project's own "don't fabricate content" principle applies to
game-facing labels too, and actual access is unaffected.

### Verification method

Booted native `build-debug` driver, admin login (`fluffos`/`Mud@2026`),
`update /adm/daemons/logind` as the real privileged-action check
(succeeded despite the cosmetic "apprentice" display). One rapid
reconnect (the connection's own `quit` is gated behind `okip` for
wizards — a genuine safety feature, not a bug — so the reconnect
exercised the silent net-dead body-reattach path instead, landing back
in the exact same room/state, which is itself valid reconnect-stability
evidence). Driver killed by exact PID after testing; incidental
`fluffos.o` save churn and a stray `.tmp` save file reverted/removed
before commit.

## §7.100 sub-threshold instance (2026-08-20)

Found during the §7.100 tail-sweep (below the original 166-lib survey's
>=100-occurrence threshold, never checked). 2 live
`replace_program(ROOM);` occurrences: `d/noden/6,8.noden.lpc`'s
`create()` (same shape/location as sibling `esI`), and this lib's own
room-building tool `u/s/sage/test/roommaker.lpc`'s heredoc
`ROOM_CODE` template — so newly-built rooms were inheriting the bug too.
Both fixed by deleting the redundant line. Verified via a clean native
driver boot (zero new `debug.log` errors, port listening, killed by
exact PID after ~8s).

## `die()` null-`killer` crash — ported from sibling `esI` (2026-08-20)

`esI`'s round-four §10.7 deep test found a real crash in
`std/user.lpc`'s `die()`: `killer` (set from `query("last_attacker")`,
falling back to `previous_object()`) can end up `int 0` whenever a
character dies from a source other than direct living-creature combat
(poison/bleeding/sickness/drowning conditions, or an admin-applied
`receive_damage()`) — two lines then call `killer->query("npc")` /
`userp(killer)` unconditionally, throwing a driver-level error on
every `heart_beat()` tick for as long as `hit_points < 1`, which means
the character never actually finishes dying (no corpse, no ghost,
stuck forever). Confirmed via `diff` that this lib's copy of the same
two lines is byte-identical/unfixed. Ported the same fix verbatim
(`killer &&` guards on both call sites, matching every other
`killer`-using line in the function which was already correctly
guarded):
```lpc
// BEFORE
if (!wizardp(this_object()) && killer->query("npc"))
if (this_object()->query_level() < 5 && userp(killer) && query("last_attacker")) {
// AFTER
if (!wizardp(this_object()) && killer && killer->query("npc"))
if (this_object()->query_level() < 5 && killer && userp(killer) && query("last_attacker")) {
```
Sanity-checked here with a fresh native driver boot + `look`/`quit`
smoke test (clean, zero new `debug.log` lines, killed by exact PID
after) — not a full independent replay of this lib's own death/respawn
flow, since `esI`'s pass already live-verified the fix's actual
behavior end-to-end twice. Flagged here for whoever next does a
round-four (or deeper) pass on this lib specifically, to do that full
live verification in its own right.

## Round-four (§10.7) deep test: net-dead-during-registration gap closed live (2026-08-21)

Closed the one remaining explicitly-flagged gap from this lib's own
NOTES.md: the `restart_heart()` net-dead-during-registration fix
(`std/user.lpc:921-932`, the `else if (base_name(environment(...)) ==
LINKDEAD_ROOM) { ... complete_setup(""); }` branch) had been
code-confirmed present across two prior passes but never re-walked live
end-to-end since the original fix/verification. Actually walked it this
pass, with a fresh, full-budget session:

- Booted native `build-debug` driver against this lib's own
  `config.fluffos` (eval cost already at the fixed `5000000`, log
  cleared first for a clean signal). Boots clean — only pre-existing
  compile warnings, no fatal errors, "Initializations complete."
- Registered a brand-new character (`caiyunshu`/蔡云舒, human female,
  id `caiyunshu`, password set but redacted here per this project's
  password-leak-prevention rule) via a raw Python socket script,
  validating each server prompt before sending the next answer (English
  login id → confirm-new-name → Chinese name → password/confirm →
  gender → race → email → real name → MOTD), and **closed the
  connection without answering** the final "`[请按 RETURN 键继续]`"
  prompt — a real, clean TCP close simulating exactly the disconnect
  point bug #1 originally described, not a `quit`.
- Confirmed the pre-placement state directly from the save file:
  `work/data/std/user_ob/human/c/caiyunshu.o` has **zero** occurrences
  of `linkdead_room` (grepped) — i.e. this reproduces the exact
  never-placed-yet precondition the fix targets, matching the original
  bug report's root-cause analysis precisely.
- Checked `log/debug.log`: zero new lines from the whole
  registration-and-drop sequence (no crash, no error trace — a silent
  drop, as expected).
- Reconnected with a fresh socket, same login id + correct password:
  landed correctly and immediately in `/d/adventurer/hall/adv_guild`
  (冒险者公会, the real `START` room) with the normal
  "重新连线完毕. 检查 IP Address 中... [OKIP]" reconnect banner — **not**
  `/d/std/rooms/netdead` ("时间的缝隙"). `look` and `quit` both produced
  correct, real output afterward. Zero new `debug.log` lines from the
  entire reconnect-and-play sequence.
- This is a genuine live pass/fail result, not a repeat of the original
  reproduction: this run used a brand-new character never touched by
  any prior pass, a fresh driver boot, and the current on-disk code —
  the fix holds. Gap closed; no code change was needed since the fix
  (present since the original 2026-07-24 pass) works correctly.
- Driver killed by exact PID (confirmed `readlink -f
  /proc/<pid>/cwd` == this lib's `work/` dir first) after testing. Only
  new artifact: `caiyunshu`'s two save files (connection + user_ob),
  kept as evidence per this lib's existing convention for prior test
  characters.

### Fast checklist pass: three newer session-wide findings, not applicable to this lib

- **combatd.lpc `bounce`/division-by-zero** (found on 4 sibling libs
  this session): `find libs/es1_win -iname "combatd.lpc"` — **no such
  file exists anywhere in this lib.** This lineage (TMI/Discworld
  family, per this lib's own already-documented "different lineage
  architecture" note above) doesn't share the ES2/大唐-family combat
  daemon shape the bug was found in. Not applicable.
- **chacha.lpc `death_stage()` reentry-guard leak** (found on 4 more
  sibling libs): `find libs/es1_win -iname "chacha.lpc"` — **no such
  file exists anywhere in this lib** either. Same lineage-mismatch
  reasoning; not applicable.
- **§7.30 mapping-accessor `mapp(x) ? x : ([])` guard**: this lib's
  actual skill-accessor equivalents, `std/living/stats.lpc` and
  `std/living/stats_npc.lpc`, both declare `mapping query_skills()`.
  Checked both directly — both already correctly guarded (a slightly
  different but equivalent shape to the documented fix pattern):
  ```lpc
  mapping query_skills() {
    if (!skills) return ([]);
    else return copy(skills);
  }
  ```
  identical in both files. No unguarded raw-variable return found.
  Confirmed clean, no fix needed.

## §7.122 sibling-sweep fix: unconditional autoload-marker reclone on net_dead (2026-08-28)

Flagged in AGENTS.md's §7.122 entry as a "near-certain candidate" — `es1`
is `es1_win`'s literal direct ancestor/near-byte-identical sibling
(shared "东方故事" lineage), and `es1` itself was already confirmed and
fixed for this exact bug on its own §10.7 round-two pass. Checked
directly rather than assumed: `work/std/user/autoload.lpc`'s
`load_autoload_obj()` was indeed byte-for-byte the same vulnerable
TMI-2-lineage code (`// autoload.c: adapted from 2.4.5 code by
Truilkan@TMI`) — unconditionally clones every entry in `auto_load[]` on
login with no presence check. Confirmed the same triggering ordering as
`es1`: `std/user.lpc`'s `remove()` (clean quit path) calls `save_me()`
*before* `destroy_autoload_obj()`, and `net_dead()` (abrupt-disconnect
path) calls `save_data()` but never calls `destroy_autoload_obj()` at
all — so an abrupt disconnect bakes every carried autoload-marker item
(bank cards, rings, disease/guild markers, etc.) into the ordinary save
data AND leaves it physically in inventory, and the next login's
`load_autoload_obj()` then clones a second copy on top with no guard,
duplicating without bound across repeated net_dead cycles.

Fixed by porting `es1`'s exact proven remedy verbatim (adapted only to
this file's own K&R brace style): `load_autoload_obj()` now snapshots
`all_inventory(this_object())` once, and skips cloning any `auto_load`
entry whose `base_name()` already matches something already carried,
appending each freshly-cloned object to that same tracking array so
duplicate entries within one `auto_load` array can't double-clone
either. Verified via a clean native driver boot (`Initializations
complete`, port 40009 listening, zero new compile errors/warnings
introduced) — not independently live-reproduced with a real net_dead
cycle on this specific lib (the fix is a verbatim port of an already
live-verified remedy from the literal ancestor codebase, not a novel
fix needing its own from-scratch reproduction).

## WASM 修复摘要（迁移自 meta.json 的 group_note）

东方故事基础版（蓝天）。
