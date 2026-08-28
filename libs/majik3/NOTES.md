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
