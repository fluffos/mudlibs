# Majik 3 -- porting notes

Source: `git clone https://github.com/tleino/majik3` (commit
`3e8b11711b91ea9c8249f738d1038703c8452019`, cloned 2026-08-28). A real
MudOS v22.1b22 mudlib by Tero "namhas" Leino, the third incarnation of
his "Majik" project (1997-1998). The repo's own `README.1st` confirms
the MudOS origin, gives FluffOS build instructions directly (this repo
was apparently already tested by its author against FluffOS at some
point -- its `bin/local_options` and `majik3.conf` already carry
FluffOS-shaped runtime-config keys like `no resets`/`heartbeat interval
msec`), and candidly describes this exact backup as "alpha testing, not
playable at all, except you could grow carrots, make money and do some
exploring." Mudlib root is the repo's `lib/` directory; `bin/`, `COPYING`,
`README.1st`, and `webclient/` at the repo top level are not part of the
mudlib and were not converted. 2,140 raw files, 1,456 `.c` files. Slug
`majik3`, number 950, port 40252. `ls libs/` was checked for anything
`majik`-named before starting; nothing existed. See also
[majik4](../majik4/NOTES.md), the same author's 1999 successor project,
onboarded immediately after this one.

Zero `driver_hook`/`set_driver_hook`/`H_[A-Z_]+` hits anywhere in the
tree (confirmed via grep both before and during this pass) -- genuinely
FluffOS/MudOS-compatible, not LDMud.

## 1. Conversion

Pure English/ASCII archive, like `openlib`. `convert_lib.sh` reported
`already_utf8=1976 converted=1 lossy=129 skipped_binary=34`. All 129
"lossy" files are under `doc/` (the stock MudOS driver reference
manual pages shipped with this archive, plus a handful of
`doc/majik/*.txt` design docs) and the loss in every case is a single
dropped Latin-1 soft-hyphen byte (`0xAD`, used for hyphenation across
line-wraps in these plain-text docs) -- GB18030 (this project's default
conversion encoding) has no representation for a lone `0xAD` and drops
it. Spot-checked several of these files after conversion: the text
reads perfectly, just missing an occasional decorative hyphen at a
line-wrap point. Purely cosmetic, in non-game reference documentation
(driver efun/apply docs, not anything a player sees), left as-is. Renamed
1,456 `.c` files to `.lpc`, fixed 1,821 literal `.c"` references, and ran
the `static`->`nosave` sweep across 41 files with zero collisions.

## 2. `master.lpc`/`secure.lpc` checklist (§2.2)

- `get_root_uid()`/`get_bb_uid()` both present in `secure/master.lpc`
  (return `"root"`/`"backbone"`), matching this driver's `PACKAGE_UIDS`
  build.
- `secure/secure.lpc`'s `valid_read()`/`valid_write()` are both fully
  permissive (`return 1` for everything) -- no §4 load-during-compile
  recursion trap.
- No `get_include_path()` override needed: every local `#include` in
  this lib already uses quotes (`"path.h"`, `"../path.h"`), and the one
  shared header directory (`/include`) is reachable via the config's
  `include directories`.
- No hardcoded `MUD_PORT`/`PORTNO` outside `doc/`.
- No `dns_master`/`dns_d`/intermud preload entries; `data/config/preload`
  only lists in-mudlib daemons.
- Chinese-detection checklist is N/A (pure English content).

## 3. `config.fluffos`

Adapted directly from the archive's own `majik3.conf` (already a
MudOS v21-format config close to what this driver expects) -- swapped
`mudlib directory` to the absolute `libs/majik3/work` path and `port
number` to 40252, kept everything else including the
FluffOS-specific runtime keys the archive's own config already carried
(`no resets`, `heartbeat interval msec`, etc. -- see the file for the
full list, all copied verbatim from `majik3.conf`).

## 4. Bug found and fixed: hardcoded wizard-home-directory paths broke the archive's own advertised playable content (AGENTS.md §7.159)

The first `lpcc_check.sh` pass (before any fixes) showed 132/1,456
failures. A large cluster traced to `inherit`/`add_exit`/
`clone_object()` calls hardcoded to `/home/madrid/agriculture/...` --
a wizard's ("madrid") personal home directory from the original live
MUD -- instead of the shared `/world/agriculture/...` tree where the
*real*, maintained copies of these same files actually ship in this
archive. Confirmed by diffing `world/agriculture/farm_room.lpc`
(the real file, referenced correctly via `ROOM_PATH`/`ITEM_PATH` macros
elsewhere) against `world/agriculture/old/farm_room.lpc` (an older,
cruder pre-refactor snapshot that has the SAME `/home/madrid/`-style
breakage baked in even deeper -- it hardcodes THREE different wizards'
home dirs for its crop-item paths, `/home/shinael/agri/...` and
`/home/pook/farms/items/...`). The `world/agriculture/old/` tree (and
its own `guild/` subtree) is entirely orphaned -- `grep -rl
"agriculture/old"` outside that directory itself comes back empty --
so it was left as-is and not fixed.

Crucially, this bug directly broke the ONE thing this archive's own
README says actually worked at the time of the backup: growing crops.
`world/agriculture/test_farm.lpc`/`test_farm1.lpc`/`test_farm2.lpc` (the
literal strawberry/potato farming rooms) all had `inherit
"/home/madrid/agriculture/farm_room.lpc";`, a path that doesn't exist
anywhere in this archive -- so the advertised "carrots" gameplay was a
hard compile failure, not a design gap.

Fix: `sed 's#/home/madrid/agriculture/#/world/agriculture/#g'` across
every LIVE (non-`old/`) file referencing the bad prefix -- 47 files,
covering `world/agriculture/guild/path.h` (the guild sub-area's own
`ROOM_PATH`/`ITEM_PATH`/`MONSTER_PATH` macros), every `mill_farm*.lpc`
guild room, the `cure/*.lpc` potion-crafting files, and the
`test_farm*.lpc` rooms themselves. A related single-file instance,
`world/madrid_temple/rooms/altar.lpc`'s `ob->move("/home/madrid/
madrid_temple/rooms/treasure_room.lpc")`, got the same one-line fix
(`world/madrid_temple/rooms/treasure_room.lpc` is real and ships in this
archive). Verified live post-fix: logged in as the seeded admin,
`goto /world/agriculture/test_farm`, and got a correctly-rendered
"You are standing in a vast farmland for a crop of strawberry" room --
a hard compile failure before the fix.

**Not fixed (confirmed genuinely never-shipped content, not the same
bug)**: `command/mortal/finger.lpc`/`uptime.lpc`'s `#include
"/home/mordoc/include/time.lpc"` (defines `format_time()`),
`obj/skill/animal_extrusion.lpc`'s `#include "/home/yorkaturr/guilds/
witches/ingredient.h"`, `command/immortal/hearye.lpc`'s `/home/project/
areas/courthouse/path.h`, and `world/cult/rooms/wiz101.lpc`'s `inherit
"/home/madrid/obj/guild.lpc"` (ambiguous -- two different candidate
"guild.lpc" base classes exist in this tree with different inherit
chains, `inherit/guild.lpc` (MONSTER-based) vs.
`world/agriculture/guild/rooms/guild.lpc` (ROOM-based); wiz101.lpc is
itself a room, so the latter is the likelier intended target, but
low enough confidence and low enough impact -- one non-essential wizard
guild room -- that it was left alone rather than guessed at). A `find
. -iname <basename>` across the WHOLE tree comes back completely empty
for the first three -- these are a wizard's personal directory that was
simply never included in this particular backup snapshot, the same
class of gap `openlib`'s onboarding notes describe (AGENTS.md §2.3).
`command/mortal/gsay.lpc`'s `"/home/madrid/gangsta.lpc"->scramble(str)`
is the same shape and also confirmed nowhere in the archive.

## 5. Bug found and fixed: `inherit/guild.lpc` function-name collision with the inherited living/skill_system base class

`inherit/guild.lpc` (inherited by every guild room/NPC in this lib)
declares and defines its own `string query_skill_rank(int chance)`, but
also inherits `MONSTER` -> ... -> `inherit/living/skill_system.lpc`,
which independently defines a DIFFERENT `string
query_skill_rank(string skill_name)`. This driver's type-checker
resolved at least one call site inside `guild.lpc` itself (`show_train()`,
line 361) against the INHERITED string-arg signature instead of the
locally-redefined int-arg one, producing `error: Bad type for argument 1
of query_skill_rank ( string vs int )` and failing the whole file (and
every room/NPC that inherits it -- `cabin1`, `univ1`, `matthew`, etc.) to
compile. Fix: renamed guild.lpc's own local function to
`guild_skill_rank` throughout (prototype + definition + all 3 internal
call sites), eliminating the name collision entirely rather than trying
to fight the compiler's resolution order. Verified the OTHER
`query_skill_rank` call sites in the codebase (`inherit/truename.lpc`,
`inherit/player/truename.lpc`) call the string-arg (skill_system)
version and were unaffected by the rename.

## 6. Bug found and fixed: wrong `#include` relative depth in `world/welf/sutepaska.lpc`

`world/welf/sutepaska.lpc` sits directly in `world/welf/` (same
directory as `world/welf/path.h`) but had `#include "../path.h"`
(one directory too far up) -- almost certainly copy-pasted from a
`world/welf/rooms/*.lpc` template, where `../path.h` correctly reaches
the same file from one level deeper. Fixed to `#include "path.h"`.

## 7. Bug found and fixed: `say()` simul_efun passed the wrong exclude-list argument, breaking EVERY `quit`

`secure/simul_efun.lpc`'s `varargs void say(string str, mixed ob)`
carefully builds a proper `object *ob2` exclude-list array from the
optional `ob` parameter (`ob2 = ({ ob, orig })` when `ob` isn't already
an array), then correctly passes `ob2` to its second `message()` call
but passes the raw, unprocessed `ob` to the FIRST:

```lpc
if (ENV(orig))
    message("say", str, ENV(orig), ob);   // bug: should be ob2
if (orig)
    message("say", str, orig, ob2);       // correct
```

`message()`'s 4th (exclude-list) argument requires an object or array.
Every caller of `say()` that omits the optional second argument gets
`ob == 0` (an int), which is exactly what `command/mortal/quit.lpc`
does: `say(THIS->query_cap_name() + " falls asleep.\n");`. Every single
player `quit` therefore threw a live, uncaught `Bad argument 4 to EFUN
message() Expected: object, array, Got: int(0)` runtime error --
visible to the player as a spurious "You have found a bug. Please
report it." printed right after the normal "Your character is now
sleeping" message, on top of the real logout message being silently
dropped for the room. Reproduced via a raw `say hello world` +
`quit` sequence (confirmed the crash fires specifically from `quit`'s
single-argument `say()` call, not the player-facing `say` command,
which passes its own explicit exclude list and works fine), fixed by
changing the first `message()` call to use `ob2` like the second one
already does, and reverified clean (`log/runtime` shows no new entries
across a full register -> race-select -> look/score/say/quit pass,
and the "found a bug" message no longer appears).

Neither this bug nor the wizard-home-path class above showed up in
`lpcc_check.sh` -- both are pure runtime logic bugs a batch-compile-only
harness can't exercise. Found only during the required live playthrough.

## 8. Confirmed genuinely unfinished content, not conversion bugs (per this project's content/design scope boundary)

After the fixes above, `lpcc_check.sh` improved from 132 to 93/1,456
failures (out of the total, `world/agriculture/old/*` -- 30 files --
is orphaned dead code, and the remainder trace to one of:

- **`add_monster()`/`set_no_weight()`/`set_no_condition()` never
  implemented anywhere in the codebase** (not as a local function, not
  as a `simul_efun`, not a driver efun in this build) but called from
  ~25+ room/item files across the forest, hilltop, halfling, welf, and
  cult zones. These compile clean (an undeclared function call isn't a
  compile-time error on this driver) and only fail at runtime the
  moment the object is instantiated -- confirmed via `log/runtime`
  showing `Undefined function called: add_monster` etc. after a live
  boot, which is also why `lpcc_check.sh`'s batch harness reports these
  as a bare `Fail to load object` with NO accompanying error/warning
  text (the runtime error's text isn't captured by the compile-sweep
  harness at all -- worth remembering as a diagnostic signature: a
  `FAIL` entry with literally nothing but a benign warning above it
  means "go check `log/runtime` after a real boot," not "re-read the
  compile output harder").
- **`inherit GRIDMAP;`** in `world/creek/zone.lpc` and
  `world/halfling/zone1.lpc`, where `GRIDMAP` is never `#define`d
  anywhere -- an abandoned early prototype of the grid-based/roguelike
  engine this same author's own README says motivated *majik4*, the
  direct successor project also onboarded into this collection.
- **`inherit/living/living.lpc`, `inherit/player/login.lpc`,
  `inherit/monster.lpc`** (the un-namespaced top-level files, as
  distinct from `inherit/living.lpc` which IS the real, live base
  class): confirmed orphaned via `grep -rl` for their literal paths --
  nothing in the live tree inherits them. Superseded/abandoned
  alternates, same shape as `imud`'s disabled Intermud-3 modules
  (AGENTS.md §2.3).
- **`world/misc/rac.lpc`** (distinct from the live `world/misc/race.lpc`
  actually used by the login/guest flow): also confirmed orphaned, and
  additionally has its own unrelated syntax typo (`]"+ hair.\n"` should
  be `]+" hair.\n"` on a long string-concatenation line) -- left
  alone since nothing reaches it.
- **No `inventory`/`inv`/`i` command exists anywhere in this archive.**
  Confirmed by directory listing, not just a missing alias -- matches
  the "alpha, not playable" self-assessment.

None of these were fixed: there is no reference implementation anywhere
in this codebase to restore, and per this project's standing scope rule
(programming bugs get fixed, content/design gaps get documented), the
right call is the same one made for `openlib`'s never-shipped personal
wizard content.

## 9. Live playthrough (§10.1 bar)

Booted `~/src/fluffos/build-debug/src/driver config.fluffos` from
`libs/majik3/` -- `Accepting telnet connections on 0.0.0.0:40252` /
`Initializations complete`, zero fatal errors in `log/debug.log`.
Full registration through a raw socket client (terminal-type
negotiation -> `new` -> name/password/retype/ansi/email/realname/gender
-> race selection room -> `select thari` -> moved to Silvercreek's
Temple of Truth): a real English name ("Aventurine") registers all the
way into the game world, matching this project's usual "real name, not
just a prompt" bar (adapted for an English-only lib -- no Chinese-name
requirement here). `look` renders the room correctly (including the
ASCII minimap this lib draws inline). `score` renders a full stat sheet
(attributes, HP/SP/EP percentages, race/subrace, age, appearance).
`say` broadcasts correctly. `quit` saves and disconnects cleanly (after
the fix in §7 above). Re-logged into the same saved character
("Recovering character...") to confirm persistence. Seeded the standard
admin account (`fluffos`/`Mud2026x`, `security 100` per this archive's
own README.1st-documented granting mechanism) and verified with the
`goto` wizard command, including `goto`-ing into the now-fixed
`test_farm` farming room.

WASM packaging not attempted this pass -- `wasm_status` left empty,
matching `openlib`'s precedent for a lib onboarded outside the
site-wide WASM sweep.

## 深度功能测试 / §10.7 deep functional test (2026-08-31)

Full round-two continuous playthrough on the native driver
(`build-debug`), going well beyond the original onboarding pass's
registration+farm-fix verification above. Test character: id
`Talonquist`, name "Talonquist Q. Steele", password `Passw0r1` --
**kept** (not cleaned up) as a representative playthrough character;
male Thari human, joined "School of Elementary Agriculture" (both via
the organic teacher-NPC route and, additionally, a throwaway
admin-assigned `"Testshortcutguild"` entry left on the character as
proof the two guild-join paths don't conflict), survived one real fight
plus one admin-assisted death/revival cycle. Save files:
`work/data/user/t/talonquist.o`, `work/data/login/t/talonquist.o`.

### Two real bugs found and fixed

**1. `world/agriculture/guild/rooms/cabin1.lpc` and `univ1.lpc` inherited the WRONG "guild" base class, undefining every ROOM function the room needed (AGENTS.md §7.159's sibling gap, same lib, previously undetected)**

Both files `inherit "/inherit/guild";` -- a MONSTER-based mixin meant
for guildmaster NPCs (fixed for an unrelated name collision in §5 above)
-- while the working sibling in the SAME directory,
`world/agriculture/guild/rooms/guild.lpc`, is the correct ROOM-based
class that defines every guild-data setter these two files call
(`set_guild`, `set_guild_desc`, `set_titles`, `set_guildmaster`,
`add_avail_skill`, `add_req_skill`, `set_default_train_msg`,
`set_custom_advance_msg`) IN ADDITION to inheriting `ROOM` for
`set_area`/`set_short`/`set_long`/`add_exit`/`set_light`/`add_item`/
`add_object`. With the wrong inherit, every one of those ROOM-level
calls in `create_guild()` silently became an "Undefined function
called" no-op (confirmed live in `log/runtime`) -- the room loaded with
no description, no exits, and no light, rendering as a bare `#########
0` grid with "There are no obvious exits." This is the exact class of
bug already catalogued for this lib (a wrong-path `inherit`, same
family as the `/home/madrid/agriculture/` hardcoded-path bug in §4 and
the `query_skill_rank` collision in §5) but had never actually been hit
live before, since no earlier pass walked all the way into the guild
join rooms. Fix: `inherit "/world/agriculture/guild/rooms/guild";` in
both files (a bare relative `inherit "guild";` was tried first and
failed differently -- `Inherited file '/guild' does not exist!` --
confirming this driver resolves a non-slash-prefixed `inherit` path
against mudlib root, not the including file's own directory; no other
working example of that pattern exists anywhere in this codebase).
Verified live: both rooms now render their real descriptions/exits/NPC,
and `join`/`info`/`train`/`advance` all work correctly as the real
mortal test character (organic path) and the admin account (functional
re-check) -- `train harvesting` correctly gates on money ("But you
don't have enough money!") until funded, then trains for real
("You become a bit more adept at Harvesting."). Grepped the rest of
`world/agriculture/guild/rooms/` for the same wrong-inherit shape: only
these two files (of ~35 in that directory) have it; the parallel files
under the confirmed-orphaned `world/agriculture/old/guild/rooms/` tree
have the identical bug but were left alone per this lib's own
already-established policy of not fixing unreachable dead code (§4).

**2. A monster daemon's "pre-clone a pool of guards, dispatch one later" pattern left the other three permanently environment-less, crashing the shared `heart_beat()` every 3 seconds forever once any player fought a citizen -- new AGENTS.md §7.180**

Attacking `world/creek/monsters/citizen.lpc` (the ordinary "walking
around" filler NPC, the closest thing this lib has to a low-risk first
combat target -- there is no dedicated safe-sparring/training-dummy
mechanism anywhere in this archive, confirmed by grepping for
`accept_fight` and `spar`/`duel`/`practice_fight` patterns and finding
none) triggers its `before_battle()`/`do_shout()` ->
`world/creek/daemons/guard.lpc`'s `wake_guard()`, an intentional "guards
come running when you attack someone in the street" mechanic. `
load_guards()` clones 4 `cityguard` monsters up front without moving
any of them anywhere (a freshly cloned object has no environment until
`move()`d); `wake_guard()` then moves exactly ONE of the 4 into the
fight, leaving the other 3 sitting with `ENV() == 0` permanently (the
pool is never refilled once non-empty). Every `cityguard` has
`set_heart_beat(1)`, and the shared `inherit/base/monster.lpc`
`heart_beat()`'s "chat", "emote", and "wander" blocks all dereference
`ENV(THOB)` unconditionally (the immediately adjacent "pick"/"drop"
blocks in the same function already correctly guard with `if
(ENV(THOB))`, so this was a real inconsistency, not intentional). This
meant EVERY environment-less guard threw a real, uncaught runtime error
on EVERY heartbeat tick (3000ms in this config) for as long as the
driver ran -- confirmed live, 508 accumulating `Bad argument ... Got:
int(0)` entries in `log/runtime` from a single ordinary fight, zero
player-visible symptom. A second, related gap in `guard.lpc` itself:
after `guard->move(ENV(ob))`, the next lines unconditionally call
`ENV(guard)->query_exit_dir()` and `guard->force_us("say ...")` with no
check that the move actually succeeded, right next to an existing `if
(ENV(guard))` check for the OLD (pre-move) environment three lines
above -- an inconsistency in the same spirit. Full details and fix code
in AGENTS.md §7.180 (new entry this pass). Verified live: reproduced
the crash-loop pre-fix, applied both guards, restarted the driver, and
re-ran the identical fight+guard-dispatch+flee+40-second-idle sequence
TWICE more -- zero new `log/runtime` entries either time, while the
dispatched guard still spoke its line and fought normally when it DID
land in a valid room.

### What was tested and confirmed working

- **Registration**: a fresh English name/password/email/realname/gender
  flow, distinct from the original onboarding's "Aventurine" character,
  reached the race-selection room and then a real starting zone room
  (Silvercreek's Temple of Truth) -- re-confirms §9 above under today's
  code.
- **Movement/exploration**: real `n`/`e`/`s`/`w` moves around Silvercreek
  (Temple of Truth -> Cleric's Sanctuary -> Hall of Gifts -> Candle
  street -> the Arcane/Candle crossing), all room descriptions/exits/
  NPCs rendering correctly.
- **Skill/guild acquisition, two paths**: organic (walked/teleported
  into `cabin1`, used the guildmaster NPC's own `join`/`train`/`advance`
  commands as a real player) AND a direct admin-assigned shortcut
  (`call talonquist add_guild "..."`) -- both landed correctly in the
  `guilds` list with no conflict between the two entries.
- **Combat**: no safe-sparring mechanism exists in this lib (documented
  above, not a bug -- matches the archive's own "alpha, not playable"
  self-description); used the ordinary `citizen` filler NPC instead for
  a real but low-stakes first fight (`kill citizen`), which correctly
  produced full punch/dodge/damage narration, triggered the city-guard
  intervention mechanic, and responded correctly to `flee` (`PANIC! You
  couldn't escape!` on the first attempt under active attack, success on
  the second once the guard's own attack cycle allowed it). No client-
  visible crash or corruption at any point (the real, serious bug this
  encounter surfaced was the silent server-side log-spam in §7.180
  above, not anything visible in play).
- **Death/respawn**: verified via a fast admin-assisted method
  (`call talonquist add_hp -9999`) rather than a lengthy real fight to
  the death, given time budget -- `do_death()` correctly created a
  corpse, moved all inventory into it, teleported the character to
  `/world/misc/hell`, and `pray` there correctly revived (`hp =
  max_hp/20+1`) and teleported back near the death site. Note: the
  score screen's "You have never died" text never updated from this
  admin-assisted death, because `add_dexp(1)` (the death counter) is
  only called from the real combat-death path in
  `obj/battle/master.lpc`, not from `do_death()` itself -- confirmed by
  reading the code, not a bug, just an artifact of the expedited test
  method (a real combat kill would increment it correctly).
- **Shop/economy**: `world/creek/monsters/khirz.lpc` (an armourer,
  `inherit SHOP`) correctly reports empty stock (`list` -> "nothing in
  stock at this time" -- this shop ships with zero starting inventory by
  design, a sell-to-the-shop model, not a bug) and correctly rejects an
  illegal item type on `sell` (`sell torch` -> "A torch cannot be sold
  here", gracefully validated via `is_legal_item()`, no crash).
- **`quit`, `log/runtime` grep, reconnect after a real gap**: `quit`
  produced no new runtime-log entries; reconnected ~2 minutes later
  (real wall-clock gap, not same-session) and the "Good day-time,
  Talonquist! You wake up..." full-login-path message confirmed this
  is NOT a silent/lockout-window reconnect (this lib has no such
  window -- grepped `secure/login.lpc`/`secure/player.lpc` for
  retention/lockout logic and found none) -- guild membership, location,
  and HP all persisted correctly across the gap.
- **Long-sit boot watch**: no WASM build exists for this lib (per §9
  above), so used the native-driver equivalent -- booted, opened one
  idle connection via `mudclient.py --idle 250 --timeout 220`, sat
  through the full ~220-second window without ever logging in. Zero
  errors in the driver's own stdout/stderr during the sit; the only
  `log/runtime` growth the WHOLE session came from the two bugs above,
  both now fixed and reverified with a fresh boot.

Not reachable in the time budgeted for this pass: the `agriculture`
zone's actual farming/money-making gameplay loop beyond the compile fix
already verified in §4 (growing crops from seed to sale) -- flagged
here as unverified-live rather than silently presented as tested.
