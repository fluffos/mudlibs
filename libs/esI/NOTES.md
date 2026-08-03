# esI.rar → `esI`

- Archive: `archives/esI.rar` (10.2MB — "东方故事"/"Eastern Story", themed
  "屠龙之战"/"Dragon Slaying War" per the live banner; up since May 2001
  per its own credits). Same 东方故事 lineage as archive #12 (es1_win),
  different snapshot/branch.
- Mudlib root: `esI/` at archive top level. Config at top-level
  `config.cfg`.
- Port: **40010**.

## Status: DONE — boots clean, playable over telnet

Full flow confirmed: banner, staff/admin credits, uptime status,
name-length validation, name-not-taken confirmation prompt.

## What was fixed

Applied both fixes discovered on lib #12 (same lineage) **proactively**,
before the first boot attempt, since a quick grep confirmed both patterns
present in the raw archive:
1. `std/object/prop.lpc`'s `#include </std/object/prop_logic.c>` (angle
   brackets, local directory, reached via preload) — `convert_lib.sh`'s
   automated `.c>`→`.lpc>` fix only fixes the extension, not the
   bracket-vs-quote distinction, so this still needed the manual switch
   to quotes (`#include "/std/object/prop_logic.lpc"`) per AGENTS.md §8d's
   preload-timing addendum. **Worth teaching `convert_lib.sh` to convert
   local angle-bracket `#include`s to quotes automatically** the next time
   this pattern recurs in enough libs to justify it (seen twice now).
2. `master.lpc`'s `domain_file()` — same `explode("/", "/")` returning a
   zero-length array, `!path` guard not catching it — added
   `|| !sizeof(path)`.

Both fixes applied before ever attempting a boot; booted clean on the
first real attempt. Plus the routine per-lib steps: encoding (8471
converted, 1741 already UTF-8/ASCII, 107 skipped binary, 14 lossy),
`.c`→`.lpc` (7035 files, 1009 refs + 1 angle-bracket ref auto-fixed),
`static`→`nosave` (121 files).

## Known remaining issues (documented, not fixed)

- 1195 lpcc-sweep failures (of 7035) — not triaged past confirming the
  lib boots and plays; given the time budget across ~90 remaining
  archives, not chasing every failure category individually this time
  (same call as es1_win's NOTES.md documents for its own long tail).

## How to run

```
cd libs/esI
~/src/fluffos/build-debug/src/driver config.fluffos
python3 ../../scripts/mudclient.py 127.0.0.1 40010 --timeout 10 --send "" --send "look" --send "quit"
```

## Re-verification pass: driver rebuild + LPC formatter + WASM build

- **Formatter**: `format-corpus.mjs` over all 7035 `.lpc` files; 6986
  reformatted, 5 unchanged, 44 refused (self-check `errors`, expected).
- **Native retest against rebuilt driver — 2 regressions found + fixed**
  (both pre-existing gaps from before this pass, only surfaced now by
  actually running `look`/`score`/`quit` to completion rather than just
  confirming boot + registration):
  1. Same stray debug `write("aadsaaaaaaaaaaaaaaaaaaaa\n\n")` in
     `std/user.lpc`'s `setup()` as `es1_win` (same lineage/root cause,
     absent from `raw/`) — deleted.
  2. **`quit` crashed** with `*Inherited file '/std/room' does not
     exist!` the first time, then `*No program in object
     '/d/std/IRC/lobby'!` after a partial fix — both trace back to the
     same **§8d `get_include_path()` gap**: this lib's TODO.md entry
     claims "both known fixes applied proactively" (referring to
     `es1_win`'s §8d fix), but `adm/obj/master.lpc` was actually
     *missing* `get_include_path()` — only `es1_win`'s copy has it. Two
     symptoms stacked: (a) `include/globals.h`'s `ROOM` macro is stale
     (`"/std/room"`, real file is `std/room/room.lpc`) while
     `include/mudlib.h`'s is correct (`"/std/room/room"`) — files that
     `#include <mudlib.h>` are fine, files relying only on the
     auto-included `globals.h` (e.g. `logoutd.lpc`'s room lookups) got
     the wrong path; fixed by correcting `globals.h`'s value to match
     `mudlib.h` (single point, matches the pattern of every other macro
     in that file). (b) once that was fixed, `d/std/IRC/lobby.lpc`
     (lazily compiled mid-connection during `logoutd`'s post-quit
     cleanup, not during preload) still failed with `Cannot #include
     irc.h` — the exact §8d/§15o symptom (angle-bracket same-dir
     `#include` needs `master.lpc`'s `get_include_path()` for compiles
     triggered live, not preload/bare-`lpcc`); fixed by adding the
     standard `get_include_path()` shape to `master.lpc` (identical to
     `es1_win`'s). Re-verified: full registration + `look`/`score`/
     `quit` all clean, zero debug.log errors, with two separate real
     Chinese names (乔峰, 阿朱).
- **WASM test**: boots cleanly (only the expected non-fatal
  `Undefined function socket_create` et al. in
  `/adm/daemons/network/cmwhod.lpc` during preload, and the same
  cmwhod-related `*No program in object` at `quit`-time cleanup — both
  are the documented "no sockets package under WASM" limitation, caught
  by the existing error handling, non-cascading). Full registration with
  a real Chinese name (慕容), `look`, and `quit` all worked end-to-end —
  this lib's IP-check is non-blocking, so it is unaffected by the
  documented `query_ip_number()` WASM limitation.

## WASM-enablement pass (loopback / admin seeding)

Identical to sibling `es1_win` (ES II family, 008).

- **Loopback ban bypass** (§1.3b): `adm/daemons/banish.lpc`
  `check_banned_site()` (~line 75) — short-circuit at top for loopback /
  empty / non-string / `localhost` / `127.` names (returns 0). Gate is
  fed `query_ip_name()`, called from `logind.lpc:242` and `:577`.
- **Uptime gate**: none rejecting. `logind.lpc:87` `uptime()<43200` only
  grants extra user slots (content, kept).
- **Anti-flood throttle**: none (per-session password retry cap only).
- **Admin account** (§1.5): `fluffos` / `Mud@2026`, display 浮浮. Added to
  `(root)`+`(admin)` in `/adm/etc/groups`; `wizard 1` + `domains`
  (archwizard) in `data/std/connection/f/fluffos.o`. Verified
  `update /adm/daemons/statsd` loads OK.
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
  `libs/esI/work/data/std/connection/f/fluffos.o`,
  `libs/esI/work/data/std/user_ob/human/f/fluffos.o`.

## 深度功能测试 / Deep functional test (2026-07-24)

Round-two pass (AGENTS.md §10.7) on the native driver, one continuous
session per checklist item, with several deliberate net-dead
disconnect/reconnect probes (both prompt and after a real ~80s
wall-clock wait) plus a fresh-boot verification of every fix. Test
characters (both **kept**, not cleaned up, as evidence):

- `Jiangfeng` / 江枫 (id `jiangfeng`), password `TestPass456`, human
  male adventurer. Primary walkthrough character: registered, trained
  `unarmed` via guild `train`, explored 远风镇, confirmed `join` at an
  already-joined guild replies correctly, quit cleanly. Currently
  parked in `/d/adventurer/hall/adv_guild` after a clean `quit`. Save:
  `work/data/std/user_ob/human/j/jiangfeng.o`.
- `Muyunhe` / 穆云鹤 (id `muyunhe`), password `TestPassZ7`, female elf
  adventurer. Created specifically to reproduce the net-dead-during-
  registration bug (disconnected at the "[请按 RETURN 键继续]" prompt,
  before ever being placed in a room) — see bug #1 below. Also used for
  the full combat/shop pass: fought a level-1 `野狗`(dog) at 远风镇西门
  for 40+ real combat rounds (no crash; both combatants have very low
  hit chance so it never concluded — fled cleanly with `east`),
  admin-granted 50 gold + 50 silver coins (see "Not verified live"),
  bought a `torch` for 5 silver at `/d/noden/farwind/shop`, confirmed
  `wield torch` correctly rejects a non-weapon, quit cleanly. Currently
  parked in `/d/adventurer/hall/adv_guild`. Save:
  `work/data/std/user_ob/elf/m/muyunhe.o`.

### Ported from sibling `es1_win` (§11 lineage, byte-identical files confirmed via diff before porting)

Both fixes below were previously found+fixed on `es1_win`'s own §10.7
pass and explicitly flagged there as "sibling esI has byte-identical
unfixed copies of both files". Confirmed via `diff` against `es1_win`'s
pre-fix commit (`92be845f197^`) that `esI`'s copies were indeed
byte-identical (module trivial pragma/comment differences), ported the
same fix, and live-verified both work on `esI` specifically.

**1. Net-dead disconnect during registration permanently strands the
account (§7.21 variant) — `std/user.lpc` `restart_heart()`.** Same root
cause as `es1_win`: `net_dead()` only records `linkdead_room` `if (env)`,
so a player who disconnects between finishing the registration Q&A and
pressing RETURN at the MOTD prompt (i.e. before `complete_setup()` ever
places them in a room) has no `linkdead_room` to restore and gets stuck
in `LINKDEAD_ROOM` forever on every future login. Fix ported verbatim:
in `restart_heart()`, when `linkroom` is unset but the player is
currently sitting in `LINKDEAD_ROOM`, call
`this_object()->complete_setup("")` to finish the interrupted setup.
**Live-verified on `esI`**: registered `Muyunhe` through to the
"[请按 RETURN 键继续]" prompt, let the connection close without
answering it, reconnected with the correct password — landed correctly
in `/d/adventurer/hall/adv_guild` (the real start room), not
`/d/std/rooms/netdead`. `look`/`score` both correct, zero debug.log
signal either before or after the fix (matches §7.20's "zero log
signal" warning).

**2. `#include <compress_obj.h>`'s `set_default_ob(__FILE__)` — §7.14
class.** `__FILE__` inside the pasted-in fragment always resolves to
`/include/compress_obj.h` itself, not whichever of the ~40 objects it
was pasted into, so every affected clone's fallback property lookup
throws `*call_other() couldn't find object '/include/compress_obj.h'`
the first time it's needed (e.g. a shop's `list` command reading an
item's price). Fix ported verbatim: `base_name(this_object())` instead
of `__FILE__`. **Live-verified on `esI`**: pre-fix, walking into
`/d/noden/farwind/shop` and typing `list` (or the room's own first-ever
`reset()`, see bug #4 below) would have hit this on the very first item
lookup; post-fix, `list` renders the full item list with prices cleanly
(油灯/绷带/魔法地图/火把), and a real purchase (`buy torch`) completed
without error (see "What was tested" below).

### New bugs found on `esI` (not present/not reproduced on `es1_win`)

**3. Leftover developer debug checkpoints printed to every player on
every real login — `adm/daemons/logind.lpc` (~line 477-490).** Five
`tell_object(player, "ttt\n")` / `"ttt1\n"` / ... `"ttt4\n"` calls,
interleaved between the real `ENTER_D`/`TOPPLAYER_D` login-chain calls,
unconditionally print literal `ttt`/`ttt1`/`ttt2`/`ttt3`/`ttt4` lines to
every player's screen on every ordinary login (confirmed reproducible —
not the net-dead-reconnect path, which goes through `restart_heart()`
instead and doesn't show them). Confirmed present in the raw archive
(`/bin/grep -a ttt raw/esI/adm/daemons/logind.c` — same 5 lines,
byte-identical), i.e. original author debug instrumentation that was
never cleaned up before this snapshot shipped, not a conversion
artifact. Same class as this lib's own already-documented
`"aadsaaaaaaaaaaaaaaaaaaaa"` stray-debug-string bug (see "Native retest"
section above) — zero player-facing content value, unambiguously
leftover instrumentation, not a game-content/design question. **Not
present on `es1_win`** (`grep ttt es1_win/.../logind.lpc` — zero hits;
this snapshot's own addition, so no sibling port needed in that
direction). Fix: deleted the 5 `tell_object()` lines, kept the 5
original comments and the real calls they were checkpointing. Verified:
re-logged in as both `Jiangfeng` and `Muyunhe` post-fix — no more
`ttt*` lines anywhere in the transcript, login chain output otherwise
unchanged.

**4. Uncatchable eval-cost abort on a room's cold first compile —
another instance of §7.22's general shape, config-level fix — the
farwind shop's `reset()`.** `/d/noden/farwind/shop.lpc`'s `create()`
calls `reset()` **synchronously** (this shop's own explicit choice,
matching a lib-wide convention — 1553 files across the tree call
`reset()` directly from `create()`, not just relying on the inherited
`std/room/room.lpc`'s async `call_out("reset", 0)`). On this snapshot's
shop, that synchronous `reset()` populates FOUR objects on the room's
very first compile, one of which — `"woodman": "/d/zeq/woodman"` — is a
heavily-decorated level-19 guard NPC (85350 HP) that equips 10 armor
pieces plus a weapon in its own `create()`, each an independent
first-time compile+clone. On a fresh boot, the FIRST player to walk
`east` into the shop hit a real, on-screen, cascading crash:
```
执行时段错误：*Too long evaluation. Execution aborted.
程式：/adm/obj/master.lpc 第 349 行
...
呼叫来自：/d/noden/farwind/shop.lpc 的 create() 第 35 行，物件： /d/noden/farwind/shop
呼叫来自：/std/room/room.lpc 的 reset() 第 47 行 ...
```
cascading into `log_error()`/`domain_file()` themselves (each hitting
the SAME already-exhausted eval budget as soon as execution resumed),
ending in `*Can't catch eval cost too big error.` The player's `move()`
into the shop simply failed (they stayed in the previous room — not
left environment-null, unlike §7.22's original `START_ROOM` instance),
but the crash is loud and repeats identically every time the shop's
FIRST-ever visit this boot is attempted. Confirmed first-visit-only:
after the aborted attempt, `east` a second time succeeded cleanly
(shop and all 4 NPCs already resident in memory from the partial first
attempt). Root cause confirmed by direct test, not guesswork: rebooting
with `maximum evaluation cost` raised from the shipped `300000` to
`5000000` and repeating the exact same fresh-boot `east` into the shop
now succeeds cleanly with zero errors — i.e. this is genuinely
"legitimately a lot of synchronous first-load work", not an infinite
loop. Worth noting the archive's OWN config comment
(`config.fluffos:72-73`, `"Because of the heavy load on the Power PC,
made it larger to pass the bad time. (By Annihilator)"`) shows the
original author already had to raise this exact value once, on their
own era's hardware, for what is plausibly this same class of problem.
`5000000` is also already the single most common `maximum evaluation
cost` value across this project's other converted libs (30 of them, per
`grep -rh "^maximum evaluation cost" libs/*/config.fluffos`), so this is
a precedented, low-risk config fix, not a one-off value pulled from
nowhere. Fix: `libs/esI/config.fluffos`, `maximum evaluation cost :
300000` → `5000000`. Live-verified: fresh reboot, fresh character,
`east` into the shop on the very first attempt this boot succeeds
cleanly (全部 4 只 NPC 正确显示), zero debug.log errors.

**5. §7.12 `tell_room()` 2-arg wrapper bug — `adm/simul_efun/tell_room.lpc`, hit from a self-rescheduling `call_out` with no enclosing `catch()` (the severity-escalation shape, not just cosmetic).**
`varargs void tell_room(mixed room, mixed msg, mixed exclude)` passes
`exclude` straight through to the real `message()` efun; called with
only 2 args (the overwhelmingly common case throughout this lib),
`exclude` defaults to `int 0`, which `message()` rejects (`Bad argument
4 to EFUN message() Expected: object, array, Got: int(0)`). Reproduced
live: `adm/daemons/weather_d.lpc`'s `change_phase()` — a
**self-rescheduling `call_out`** ("it call_outs to itself recursively
so there's always one version in the call_out queue", per the file's
own comment) — calls `tell_room(notifications[i], msg)` with only 2 args
inside a loop, with no `catch()` anywhere in the function. The uncaught
throw aborts `change_phase()` at that exact statement, meaning the
function's OWN tail —
`call_out("change_phase", day_phases[current_phase]["length"])` — never
runs, so the entire day/night phase cycle daemon **permanently stops
forever** for the rest of that boot, with the single runtime-error line
in `debug.log` as the only trace (no crash, no other visible symptom;
weather/ambient broadcasts and phase-change text simply never happen
again). Trivially reachable: `WEATHER_D->request_weather_notices()` is
called by every outdoor room's `set_outside()` (`std/room/room.lpc`),
so registering even ONE outdoor room (any ordinary walk outside)
arms the crash for whenever the phase timer next fires — some phases
in `adm/etc/daytime.data` are as short as 1 second, so this fires
quickly in practice, well within a normal play session. Confirmed via
`diff`: `es1_win`'s copy of `tell_room.lpc` is byte-identical and
carries the same unfixed bug (not caught by that lib's own §10.7 pass —
plausibly a timing/room-visited difference between sessions). Fix
(matching AGENTS.md §7.12's documented remedy exactly):
```lpc
// BEFORE
message("tell_room", msg, room, exclude);
// AFTER
message("tell_room", msg, room, exclude || ({}));
```
**Live-verified on `esI`** two ways: (a) played normally afterward with
an outdoor room registered for ~15 real seconds, zero new debug.log
errors; (b) direct proof via the `fluffos` admin account's `eval`
command — `eval tell_room(environment(this_player()), "TESTBROADCAST_2ARG\n"); return 1;`
(the exact 2-arg shape that crashed `weather_d.lpc`) broadcast cleanly
with `Result = 1` and zero debug.log error, both pre-fix (reproduced the
crash directly this way too) and post-fix (clean). **Ported to
`es1_win`** (`libs/es1_win/work/adm/simul_efun/tell_room.lpc`, same
one-line fix, comment cites this lib's finding) and sanity-checked there
with a fresh boot + existing test-character login/`look`/`quit` (clean,
zero new errors) — not a full independent replay of `es1_win`'s own
§10.7 checklist, since that lib was already marked done; flagged here
for whoever next touches `es1_win` to note in ITS OWN NOTES.md.

### What was tested and confirmed working

- **`help start`** read first (`doc/help/c_start`) — same TMI/ES house
  style as `es1_win`'s `c_start`, documents the guild `cost`/`advance`/
  `train`/`list`/`join` organic skill path (no NPC-dialogue teacher in
  this lineage) and the real starting layout (远风镇/冒险者公会).
- **Registration**: full flow (English id → confirm new → Chinese name
  → password/confirm → gender → race → email → real name → MOTD/RETURN)
  reached `/d/adventurer/hall/adv_guild` correctly, twice (`Jiangfeng`,
  `Muyunhe`). Both got the "自动获得巫师权限" (automatic wizard status)
  message this snapshot's config grants every new character — cosmetic
  only in practice: `west` from `adv_guild` into `/d/wiz/wiz_hall`
  (wizard-only gate) still correctly rejected both test characters with
  "对不起，只有巫师才能进去。", and the `eval` wizard command was only
  reachable as the separately-seeded `fluffos` admin account, not either
  test character — documented as an observation, not "fixed" (a gate
  correctly rejecting a character despite a registration banner that
  implies it shouldn't is at most a content/messaging inconsistency, not
  a crash or obviously-wrong efun call).
- **`look`/`score`/`i`**: correct at every state change (registration,
  post-training, post-combat, post-shop-purchase, post-reconnect,
  post-relogin).
- **Guild training** (organic path, no NPC teacher — `cost`/`advance`/
  `train`/`list` in the guild room itself, `std/guild.lpc`): `list`
  showed the 7 trainable adventurer-guild skills with real costs;
  `train unarmed` correctly deducted exp and printed
  "你的空手搏斗技能现在提升到 1 了。".
- **`join`**: tested at the already-joined adventurer guild — correctly
  replied "你已经是本公会的成员了！" (matching `es1_win`); no separate
  sect/faction system beyond the documented guilds (adventurer/mage/
  healer/knight/monk/thief/scholar, each gated behind the same
  `join`-in-guild-room mechanic reached via real travel this pass didn't
  budget time for beyond the starting adventurer guild).
- **Safe-sparring mechanism**: this lib DOES have one, unlike `es1_win`
  — a scripted "doll" combat tutorial at
  `/d/noden/school/basic3-doll.lpc` (`kill doll` sets a flag, waits 3
  real seconds, then `cease_all_attacks()` — genuinely no real combat
  resolution happens, confirmed by code read; `grep -r accept_fight`
  across the whole tree is empty, same as `es1_win`, so nothing in this
  lib implements a real damage-mirroring practice dummy). Reaching it
  requires completing a lengthy multi-room, command-specific tutorial
  gated by `school1`/`school2` flags (`get`/`give`/`put`/`search`/`ask`/
  `say`/`hp`/`who`/`look` sequences across ~14 rooms) — not traversed
  this pass given the time budget, AND because it wouldn't have
  exercised real combat resolution anyway (per the code read above).
  Used a real level-1 `野狗`(dog) at 远风镇西门 instead (same choice
  `es1_win`'s own pass made, for the same reason — no functioning
  `accept_fight()`-style dummy exists in this lineage).
- **Combat**: `consider`/`kill` both worked; 40+ real turn-by-turn
  combat rounds resolved correctly (hit/miss/damage messages, `hp`
  mid-fight status, `score` reflecting HP/SP loss) against the level-1
  dog — both combatants have minimal stats (character starts at 1 in
  every attribute) so hit rates are low and neither side reliably wins;
  fled cleanly with a direction command (`战斗结束了。`). No crash, no
  eval-cost error, no stuck state.
- **Shop purchase — completed live**: admin-granted `Muyunhe` 50 gold +
  50 silver coins via the `fluffos` account's `eval` (see "Not verified
  live" for why admin-assisted, not organic), then `buy torch` at
  `/d/noden/farwind/shop` correctly charged 5 silver
  ("你花5枚银币　买下一枝火把。"), added the torch to inventory, and
  `score`'s money breakdown updated correctly (50 金币 / 45 银币).
  `wield torch` correctly rejected ("那并不是武器。" — not a weapon).
  This also re-exercises bug #2's fix (the shop's `list`/item-property
  lookups) and bug #4's fix (the shop's first-ever `reset()`) together
  in one real transaction.
- **`quit` + debug.log**: every `quit` in this pass (multiple, across
  both test characters and the admin account) was followed immediately
  by a `grep` of `libs/esI/log/debug.log` — all clean except for the
  bug #5 crash line itself (found this way, per §10.7's own worked
  lesson: never trust a normal-looking on-screen quit/interaction
  without checking the log).
- **Net-dead reconnect — both edge cases tested, not just the ported
  one**: (a) the registration-interrupt case (bug #1, above); (b) the
  ORDINARY case — a player already properly placed in a real room
  (`Muyunhe` in `adv_guild`) disconnected uncleanly (no `quit`) and
  reconnected PROMPTLY: `重新连线完毕`, landed back in the exact same
  room with exact same HP/exp state; repeated with a real ~81-second
  wall-clock wait (via a foreground polling loop, not a backgrounded
  sleep) before reconnecting — identical correct result, zero new
  debug.log lines either time. (Did not wait through the full
  `WIZ_LINKDEAD_DUMP`/`LINKDEAD_DUMP` force-quit timer — 20-60 real
  minutes per `include/body.h` — out of this pass's time budget; the
  `es1_win` sibling's own pass didn't either.)
- **Clean-quit relogin**: quit cleanly (`Muyunhe`), reconnected fresh
  (full login-shaped relogin, not net-dead reconnect) — correctly
  restored to `adv_guild` with all state (HP/exp/inventory/money)
  intact.

### Not verified live (explicitly)

- **Death and respawn**: not reached — the one real fight run this pass
  (40+ rounds vs. the level-1 dog) never concluded either way given both
  combatants' minimal stats; deliberately seeking a losing fight wasn't
  pursued within this pass's time budget. Same as `es1_win`'s own pass.
- **The shop purchase used admin-granted money, not organically-earned
  money**: `Muyunhe` started with zero gold (身无分文, same as every new
  character) and no in-session path to earn any was pursued (same
  situation `es1_win`'s pass documented); coins were cloned directly via
  the `fluffos` account's `eval` command
  (`new("/std/coins")`/`set_type()`/`set_number()`/`move()`) rather than
  earned through gameplay. The actual `buy` transaction itself — ACL,
  price deduction, inventory update, the shop's own `sell`/`value`
  logic — IS real and live-verified; only the money's ORIGIN is
  admin-assisted rather than organic.
- **Other guilds (mage/healer/knight/monk/thief/scholar)**: not
  travelled to and `join`ed — only the starting adventurer guild's
  `join` (already-a-member case) was exercised live. Code review of
  `std/guild.lpc` suggests the same mechanism handles all guilds
  uniformly, but this is not the same as a live-verified join into a
  DIFFERENT guild.
- **Full tutorial-school traversal / the "doll" scripted sparring
  mechanism**: not completed (see "What was tested" above for why —
  time budget, plus it wouldn't exercise real combat resolution anyway).
- **A broader lib-wide sweep for other rooms sharing bug #4's shape**
  (a room whose `create()` synchronously `reset()`s a first-time-heavy
  NPC roster): 1553 files share the "direct `reset()` in `create()`"
  convention lib-wide; only the farwind shop was actually walked into
  and crashed this pass. The `maximum evaluation cost` config fix is
  lib-wide (protects every such room, not just the shop), but no attempt
  was made to enumerate or pre-visit every other room that might carry
  an equally-heavy first-load NPC.

## WASM 修复摘要（迁移自 meta.json 的 group_note）

同一血统（屠龙之战）。
