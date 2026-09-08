# Age of Heroes (aoh) — porting notes

Source: git clone https://github.com/seikichin/aoh (commit 6ab8f3679d560a3726ae98b671d7ded7be6fb75d, cloned 2026-09-05); repo root is the mudlib. Converted 2026-09-05. Config name `Age of Heroes`.
Slug `aoh`, number **976**, port **40285**.

**This is an LDMud → FluffOS conversion.** Discovery triage normally
drops LDMud-lineage libs; this onboard is an explicit exception in the
same family as `questmud` / `acme` (AGENTS.md §7.158).

This collection’s copy is a snapshot, not a live mirror. Do not onboard
the same upstream repo again.

## 0. Layout

Repo root **is** the mudlib. `raw/` is gitignored. Original LDMud master
preserved as `/secure/master_ldmud.lpc`.

## 1. Convert (2026-09-05)

`convert_lib.sh` with UTF-8 source encoding (already UTF-8 English /
German sources). `.c` → `.lpc` rename + literal `.c"` fixups +
`static`→`nosave` as usual.

## 2. FluffOS port (LDMud → FluffOS)

The archive is **LDMud 3.x** (`set_driver_hook`, `inaugurate_master`,
`#'` / `unbound_lambda` closures, multi-file or directory simul_efun).
FluffOS has none of those driver hooks. A mechanical dialect rewrite of
the whole tree is not attempted; the original login/command stack is
kept as source and not loaded.

`config.fluffos`: master `/catalog/master`, simul `/catalog/simul_efun`,
global include `"/catalog/auto.h"`, port **40285**,
`lazy resets : 1`.

Catalog overlay (questmud §7.158 cluster):

- `/catalog/master.lpc` — `get_root_uid`/`get_bb_uid`, `creator_file`
  always returns string `"BACKBONE"`, `valid_read` includes
  `load_object`/`recompile_object`/`include`/`restore_object`,
  `valid_override` returns 1, `error_handler` → `/log/catch`
- `/catalog/simul_efun.lpc` — thin `cat`/`log_file`/`exists`
- `/catalog/login.lpc`, `/catalog/player.lpc` — name/password →
  `/d/silvere/rooms/harbour/quay1_2` (Strategy A; Void fallback
  if load fails)
- `/catalog/void.lpc`, `/catalog/workshop.lpc` — leftover overlay rooms

## 3. Live-verified (native, port 40285)

Create `fluffos` / `Mud@2026`. Lands in The Void; `look` / `score` /
`north` (workshop) / `south` / `quit`. Reconnect after cold restart
reloads `data/f/fluffos.o`.

## 深度功能测试（§10.7, 2026-09-05）

Catalog overlay only — the LDMud 3.x world is not loaded. Organic
`fluffos` / `Mud@2026` on native 40285: Void `look` / `score`
(level 1, hp 20/20) / `inventory` / `north` workshop / `south` /
`quit` persist. Reconnect: Void `look` / `score` / `quit`. Shop,
combat, guild, death: **N/A** (needs a real LDMud driver).

Logs this boot (PID started 20:08:55, live fd
`libs/aoh/log/debug.log`): stdout + debug.log clean.
`work/log/catch` proven live with a one-shot `catchprobe`
(`CAUGHT /catalog/player.lpc *catch-path-probe`) then reverted;
play itself left no other catch lines.

## 4. What is not ported yet

Full OSB/AOH world (Silvere shop buy, remaining interiors,
tower interiors, other domains), guilds, combat, protocol stacks,
OSB kernel daemons. 2681 `#'` in 1062 files — do not attempt a
mechanical `/std` rewrite this slice. Newbie creation
`/d/login/entrance` is not loaded; catalog login uses STARTROOM.

## 6. Full dialect port (Strategy A, 2026-09-06)

Catalog Void/workshop is no longer the live start. Established
players in the archive start at `/d/silvere/rooms/harbour/quay1_2`
("The docks"; `sys/stdrooms.h` STARTROOM). Newbies go to
`/d/login/entrance` — that creation path is not loaded here.

`/std/room` and HARBOUR_BASEROOM cannot load on FluffOS (LDMud
inherit + `#'` + nightday). Strategy A keeps the authentic paths
and English harbour text as thin FluffOS rooms; originals are
`quay1_*_ldmud.lpc`.

- `/d/silvere/rooms/harbour/quay1_2` — The docks (login)
- `/d/silvere/rooms/harbour/quay1_3` — The quay at Silvere (west)
- `/d/silvere/rooms/harbour/quay1_1` — A street (east; lobster traps)
- `/d/silvere/rooms/harbour/street3` — harbour crossing (southeast)
- `/d/silvere/rooms/harbour/street2` — paved road up the hill
- `/d/silvere/rooms/harbour/street1` — sun clock
- `/d/silvere/rooms/harbour/entrance` — City Gate
- `/d/silvere/rooms/harbour/harbour_inn` — The Seaman's Rest
- `/d/silvere/rooms/harbour/harbourmaster` — office (up harbourmaster2 loaded)
- `/d/silvere/rooms/harbour/harbourmaster2` — upstairs loft (telescope look-at; look through not wired)
- `/d/silvere/rooms/harbour/shipyard` — north of the lobster-trap street
- `/d/silvere/rooms/harbour/quay2_1` — southern quay (barrels)
- `/d/silvere/rooms/harbour/quay2_2` — southern landing
- `/d/silvere/rooms/harbour/quay2_3` — path to the southern tower
- `/d/silvere/rooms/harbour/stower_enter` — Before a high tower (south)
- `/d/silvere/rooms/harbour/ntower_enter` — Before a high tower (north)
- `/d/silvere/rooms/west/harbourgate` — city side of the harbour wall
- `/d/silvere/rooms/west/westroad1` — The Westway
- `/d/silvere/rooms/west/westroad2` — Westway shop fronts
- `/d/silvere/rooms/west/westroad3` — Westway chandler front
- `/d/silvere/rooms/west/chandler` — Molly's Chandler (look only)
- `/d/silvere/rooms/west/westroad4` — Westway flowerbed
- `/d/silvere/rooms/west/westshop1` — south alley (SHOPPE THATT WAY)
- `/d/silvere/rooms/west/westshop2` — lane to the sell-only shop
- `/d/silvere/rooms/west/westshop` — A little shop (look only)
- `/d/silvere/rooms/west/westroad5` — Westway toward the post office
- `/d/silvere/rooms/west/westroad6` — fishmonger-front Westway
- `/d/silvere/rooms/west/westroad7` — tailor-front Westway / Elrimand Road
- `/d/silvere/rooms/west/westroad8` — wine-shop-front Westway
- `/d/silvere/rooms/west/westroad9` — Guild Street fork
- `/d/silvere/rooms/west/westroad10` — flower-shop-front Westway
- `/d/silvere/rooms/west/westroad11` — palace-square approach Westway
- `/d/silvere/rooms/center/westenter` — Central place, west end
- `/d/silvere/rooms/center/outside1` — West Palace Avenue
- `/d/silvere/rooms/center/outside2` — Avenue of the Palace (look only)
- `/d/silvere/rooms/center/outside3` — The palace avenue (look only)
- `/d/silvere/rooms/center/outside4` — The palace avenue, salium beds
- `/d/silvere/rooms/center/outside5` — The palace avenue, east corner
- `/d/silvere/rooms/center/outside6` — Road at the palace (look only)
- `/d/silvere/rooms/center/outside7` — Road at the palace, further east (look only)
- `/d/silvere/rooms/center/outside8` — Road at the palace, further east (look only)
- `/d/silvere/rooms/center/outside9` — Avenue of the Palace, entrance fork (look only; east mainsouth1 loaded)
- `/d/silvere/rooms/center/palplace1` — The palace square, west side (look only)
- `/d/silvere/rooms/center/palplace4` — The place before the palace (look only)
- `/d/silvere/rooms/center/palplace5` — At the entrance into the palace (look only; north palenter loaded)
- `/d/silvere/rooms/palace/palenter` — A hall in the palace (archive stub; east paleast1 / west palwest1 loaded; enter throneroom not wired)
- `/d/silvere/rooms/palace/paleast1` — east-wing hall stub (seems to glance / you.The walls / podestal; east pal*2+ not wired)
- `/d/silvere/rooms/palace/palwest1` — west-wing hall stub (seems to glance / podestal; west pal*2+ not wired)
- `/d/silvere/rooms/center/palplace2` — The palace square fountain (look only)
- `/d/silvere/rooms/center/mainsouth1` — Avenue of the Palace, Sarykan statue (look only; west outside9 loaded)
- `/d/silvere/rooms/south/mainroad1` — On a road at Silvere (archive stub)
- `/d/silvere/rooms/center/palplace3` — The place before the palace, east wing (look only)
- `/d/silvere/rooms/center/palplace6` — The place before the palace, east-wing walls (look only)
- `/d/silvere/rooms/center/outside10` — Road at the palace, south of east wing (look only)
- `/d/silvere/rooms/center/outside11` — Avenue the palace (look only; archive short typo)
- `/d/silvere/rooms/center/outside12` — Road at the palace, east of Avenue the palace (look only)
- `/d/silvere/rooms/center/outside13` — Road at the palace, east of outside12 (look only)
- `/d/silvere/rooms/center/outside14` — The palace avenue, Lady flowers (look only)
- `/d/silvere/rooms/center/outside15` — The palace avenue, Arabellas (look only)
- `/d/silvere/rooms/center/outside16` — The palace avenue, venus poppys (look only)
- `/d/silvere/rooms/center/outside17` — Avenue of the Palace, Tali statue (look only; east eastroad1 loaded)
- `/d/silvere/rooms/center/eastroad1` — Mainroad leading east (archive stub)
- `/d/silvere/rooms/center/eastroad2` — Mainroad leading east (archive stub)
- `/d/silvere/rooms/east/mainroad1` — On a road at Silvere (foggy; Joan and Mistral house mentioned, not loaded)
- `/d/silvere/rooms/center/outside18` — The palace avenue, Morning Stars (look only)
- `/d/silvere/rooms/center/outside19` — The palace avenue, pomegranate grove (look only)
- `/d/silvere/rooms/center/outside20` — The palace avenue, turns west (look only)
- `/d/silvere/rooms/center/outside21` — Avenue at the palace, rear wall (look only)
- `/d/silvere/rooms/center/outside22` — Avenue at the palace, doves (look only)
- `/d/silvere/rooms/center/outside23` — Avenue of the Palace, angelica/sorrel (look only)
- `/d/silvere/rooms/center/outside24` — Avenue of the Palace, sage/mint (look only)
- `/d/silvere/rooms/center/outside25` — Avenue of the Palace, Kyrie statue (look only; north northroad loaded)
- `/d/silvere/rooms/center/northroad` — On a road at Silvere (foggy stub; north unwired)
- `/d/silvere/rooms/center/outside26` — Avenue of the Palace, bay/lavender (look only)
- `/d/silvere/rooms/center/outside27` — Avenue at the palace, ginger/parsley (look only)
- `/d/silvere/rooms/center/outside28` — Avenue at the palace, fig grove (look only; south garden2 loaded)
- `/d/silvere/rooms/center/outside29` — Avenue at the palace, fig grove west (look only; south garden1 loaded)
- `/d/silvere/rooms/center/outside30` — The palace avenue, west corner (look only; southeast garden1 loaded)
- `/d/silvere/rooms/center/outside31` — The palace avenue, west wing south (look only; east garden1 loaded)
- `/d/silvere/rooms/center/garden1` — Palace Fig Garden (look only)
- `/d/silvere/rooms/center/garden2` — Palace Fig Garden, east (look only)
- `/d/silvere/rooms/center/garden3` — Palace pomegranate Garden (look only; east garden4 loaded)
- `/d/silvere/rooms/center/garden4` — Palace pomegranate Garden, east (look only)
- `/d/silvere/rooms/south/mainroad2` — On a road at Silvere (foggy south-gate stub; south mainroad3 loaded)
- `/d/silvere/rooms/south/mainroad3` — On a road at Silvere (foggy stub)
- `/d/silvere/rooms/south/mainroad4` — On a road at Silvere (foggy stub)
- `/d/silvere/rooms/south/mainroad5` — On a road at Silvere (foggy stub)
- `/d/silvere/rooms/south/mainroad6` — On a road at Silvere (foggy stub; south mainroad7 loaded)
- `/d/silvere/rooms/south/mainroad7` — On a road at Silvere (foggy stub)
- `/d/silvere/rooms/south/mainroad8` — On a road at Silvere (foggy stub)
- `/d/silvere/rooms/south/mainroad9` — On a road at Silvere (foggy stub; south mainroad10 loaded)
- `/d/silvere/rooms/south/mainroad10` — On a road at Silvere (foggy stub plus west citypark mention; west parkroad1 loaded)
- `/d/silvere/rooms/south/parkroad1` — On a road at Silvere (foggy citypark stub)
- `/d/silvere/rooms/south/parkroad2` — On a road at Silvere (foggy citypark stub)
- `/d/silvere/rooms/south/parkroad3` — On a road at Silvere (foggy citypark stub; west parkroad4 loaded)
- `/d/silvere/rooms/south/parkroad4` — On a road at Silvere (foggy citypark stub)
- `/d/silvere/rooms/south/parkroad5` — On a road at Silvere (foggy citypark stub; west parkroad6 loaded)
- `/d/silvere/rooms/south/parkroad6` — On a road at Silvere (foggy wall+trees stub)
- `/d/silvere/rooms/south/parkenter` — On a road at Silvere (foggy park-entrance stub; west park interiors not loaded)
- `/d/silvere/rooms/south/mainroad11` — On a road at Silvere (citygates south; south southgate loaded)
- `/d/silvere/rooms/south/southgate` — southern gates (This are; ivy look-at; climb not wired)
- `/d/silvere/rooms/south/wilderness1` — road south of the gates (layout stub)
- `/d/silvere/rooms/south/wilderness2` — road toward the river (layout stub)
- `/d/silvere/rooms/south/wilderness3` — road with windmill mention (west fields not wired)
- `/d/silvere/rooms/south/rivershore1` — On a road south (layouted stub; south bridge not wired)
- `/d/silvere/rooms/center/outside32` — palace avenue (archive short; jasmine; look only)
- `/d/silvere/rooms/west/flowershop` — Jehane's Flowers (look only)
- `/d/silvere/rooms/west/libraryroad1` — Guild Street / library road (east adventurerguild loaded)
- `/d/silvere/rooms/west/adventurerguild` — The Adventurers Guild (archive stub; leave guild not wired)
- `/d/silvere/rooms/west/libraryroad2` — library road west (stub look-ats; west libraryenter loaded)
- `/d/silvere/rooms/west/libraryenter` — The Adventurers Guild / library entrance stub
- `/d/silvere/rooms/west/wineshop` — Chez Brigan (look only)
- `/d/silvere/rooms/west/bakery` — Eldranna's Bake Shoppe (look only)
- `/d/silvere/rooms/west/tailor` — Couture Celimarith (look only)
- `/d/silvere/rooms/west/councilroad1` — Elrimand Road (bakery look-at; north councilroad2 loaded)
- `/d/silvere/rooms/west/councilroad2` — Elrimand Road (houses / coat of arms look-ats)
- `/d/silvere/rooms/west/councilroad3` — Elrimand Road, Elrimand statue (look only)
- `/d/silvere/rooms/west/councilroad4` — Elrimand Road, outside the council hall (look only; enter hall not wired)
- `/d/silvere/rooms/west/councilenter` — Council Hall Entrance (archive stub)
- `/d/silvere/rooms/west/fishmonger` — Feridwyn's Seafood (look only)
- `/d/silvere/rooms/west/wpostroad1` — lane to the post office
- `/d/silvere/rooms/west/wpostroad2` — Counting House arch
- `/d/silvere/rooms/west/wpostoffice` — post office (look only)
- `/d/silvere/rooms/west/wbank` — Counting House foyer (look only)
- `/d/silvere/rooms/west/cityinfo1` — Park Lane (east cityinfo loaded; south citypark1 loaded)
- `/d/silvere/rooms/west/cityinfo` — Elder office (look only; leave/sit/elder NPC not wired)
- `/d/silvere/rooms/west/citypark1` — Park Lane (uneaven cobbles; south citypark2 loaded)
- `/d/silvere/rooms/west/citypark2` — Park Lane (thebare bricks; south cityenter loaded)
- `/d/silvere/rooms/west/cityenter` — Citypark entrance (look only; south SIL_PARK parkenter loaded; enter park verb not wired)
- `/d/silvere/rooms/newbiepark/parkenter` — Citypark entrance (sign / it's wooden surface; leave/search not wired)
- `/d/silvere/rooms/newbiepark/forest_enter` — Before a small forest (archive stub; east forest_room1 not wired)
- `/d/silvere/rooms/west/whealer1` — Before the house of the healer (north whealer loaded)
- `/d/silvere/rooms/west/whealer` — The house of the healer (look only; drink / treat not wired)
- `/d/silvere/rooms/west/templeroad1` — Templeroad (Xalandre approach)
- `/d/silvere/rooms/west/templeroad2` — Templeroad (archive stub)
- `/d/silvere/rooms/west/templeroad3` — Templeroad, outside the temple (look only; enter temple not wired)
- `/d/silvere/rooms/west/cparch` — Caves of Parch entrance (blocked stub)
- `/d/silvere/rooms/west/wsmithroad1` — small road toward the weaponsmith (stub)
- `/d/silvere/rooms/west/wsmithroad2` — small road before the weaponsmith (stub; shop not loaded)

inn buy/drink, harbourmaster bell NPC, tower interiors,
palace hall look-ats (`palenter`) plus east/west wing
stubs (`paleast1` / `palwest1`) are loaded
(`enter throneroom` / pal*2+ not wired),
harbourmaster loft telescope look-ats are loaded
(`look through` not wired),
further south-town
(`/d/silvere/rooms/south/southgate` look-ats are
loaded; `climb ivy` not wired; west fields and the
south bridge stay unwired),
north of northroad is unwired (no `prevent_void`
message), statue
touch/helmet, `enter hall`,
mail / bank deposit,
shop buy, and healer treat/drink are not loaded
(healer-house look-ats are loaded).
The council hall, library entrance, and adventurers
guild stubs are loaded (look only). The City Elder
office look-ats are loaded (`leave office` / `sit`
/ elder NPC not wired). Park Lane continues south
through citypark1–2 to the cityenter gate and
SIL_PARK `parkenter` / `forest_enter` look-ats
(`leave park` / `search` / forest combat not wired).

`/catalog/login` still handles name/password. `/catalog/player`
`enter_world()` moves onto the docks (fallback Void if load fails).

Live walk (native 40285, 2026-09-06, organic `fluffos` /
`Mud@2026`):

- Lands on The docks. `look at nets` / `gulls` / `pails`.
- West → The quay at Silvere (`look at sails`). East back.
  East → A street (`look at traps`). West back to the docks.
- `score` level 1, hp 20/20. Quit persist. Reconnect lands on
  the docks again.

This-boot live `libs/aoh/log/debug.log` (fd 3, PID 1750409
BOOT_MARKER1 aoh-docks): start rooms compiled, no new lines
after the marker. Catch this walk: empty after the marker
(older `*catch-path-probe` line is from 2026-09-05).

Harbour expansion (native 40285, 2026-09-06, same `fluffos` /
`Mud@2026`, do not redo the docks look-ats):

- East → lobster-trap street. Southeast → harbour crossing
  (`look at road`). East ×2 past the sun clock (`look at clock`)
  to City Gate (`look at ivy`).
- South → The Seaman's Rest (`look at sailors` / `menu`).
  North back. North → Office of the Harbourmaster
  (`look at desk` / `bell`). South back.
- `score` persist. Reconnect still lands on the docks.

This-boot live `libs/aoh/log/debug.log` (fd 3, PID 1778974
BOOT_MARKER2 aoh-inn-hm): no new lines after the marker.
Catch this walk: empty after the marker.

Harbour expansion 2 (native 40285, 2026-09-06, same `fluffos` /
`Mud@2026`, do not redo docks or inn/office look-ats):

- East → lobster-trap street. North → The shipyard of Silvere
  (`look at frames` / `tar` / `workers`). South back.
- Southeast → crossing. Southwest → southern quay
  (`look at barrels` / `crates`). West → landing
  (`look at people`). East, northeast back.
- East ×3 to City Gate. East → City gates (`look at gate` /
  `portcullis`). West back.
- `score` persist. Reconnect still lands on the docks.

This-boot live `libs/aoh/log/debug.log` (fd 3, PID 1806541
BOOT_MARKER3 aoh-quay2-yard): no new lines after the marker.
Catch this walk: empty after the marker.

Harbour expansion 3 (native 40285, 2026-09-06, same `fluffos` /
`Mud@2026`, do not redo docks, inn/office, shipyard, or
quay2/city-gate look-ats):

- West from the landing → path to the southern tower
  (`look at bushes` / `trees`). West → Before a high tower
  (`look at tower` / `chain`). East back.
- East through City Gate → The Westway (`look at flagstones` /
  `shops`). East → shop-front Westway (`look at signs`).
- South → Park Lane (`look at sign`). North, north → healer
  street (`look at herbs`).
- `score` persist. Reconnect still lands on the docks.

This-boot live `libs/aoh/log/debug.log` (fd 3, PID 1836787
BOOT_MARKER4 aoh-westway): no new lines after the marker.
Catch this walk: empty after the marker.

Harbour expansion 4 (native 40285, 2026-09-06, same `fluffos` /
`Mud@2026`, do not redo docks, inn/office, shipyard,
southern-tower, or Westway look-ats):

- West ×2 from the docks → northern tower exterior
  (`look at tower` / `chain`). East back.
- East through City Gate and The Westway → chandler-front
  Westway (`look at sign` / `shop`).
- `score` persist. Reconnect still lands on the docks.

This-boot live `libs/aoh/log/debug.log` (fd 3, PID 1863039
BOOT_MARKER5 aoh-ntower-wr3): no new lines after the marker.
Catch this walk: empty after the marker.

Harbour expansion 5 (native 40285, 2026-09-06, same `fluffos` /
`Mud@2026`, do not redo docks, inn/office, towers, or
Westway look-ats):

- North from the chandler front → Molly's Chandler
  (`look at candles` / `sign`). South back.
- East → Westway flowerbed (`look at flowerbed` / `fence`).
  South → pigeon alley (`look at sign` / `pigeons`).
- `score` persist. Reconnect still lands on the docks.

This-boot live `libs/aoh/log/debug.log` (fd 3, PID 1892062
BOOT_MARKER6 aoh-wr4-chandler): no new lines after the marker.
Catch this walk: empty after the marker.

Harbour expansion 6 (native 40285, 2026-09-06, same `fluffos` /
`Mud@2026`, do not redo docks, inn/office, towers,
Westway, or chandler/flowerbed/alley look-ats):

- East of the flowerbed → Westway toward the post office
  (`look at decorations` / `houses`).
- South of the pigeon alley → sell-shop lane (`look at shop`)
  → A little shop (`look at shopkeeper` / `trashcan`).
- `score` persist. Reconnect still lands on the docks.

This-boot live `libs/aoh/log/debug.log` (fd 3, PID 1920162
BOOT_MARKER7 aoh-wr5-sellshop): no new lines after the marker.
Catch this walk: empty after the marker.

Harbour expansion 7 (native 40285, 2026-09-06, same `fluffos` /
`Mud@2026`, do not redo docks, inn/office, towers,
Westway, chandler/flowerbed/alley, or westroad5/sell-shop
look-ats):

- East of westroad5 → fishmonger-front Westway
  (`look at sign` / `nets`). West back.
- North → post-office lane. North → Counting House
  street (`look at plaque` / `arch`). West → post office
  (`look at cabins`). Mail is not implemented.
- `score` persist. Reconnect still lands on the docks.

This-boot live `libs/aoh/log/debug.log` (fd 3, PID 1950215
BOOT_MARKER8 aoh-wr6-post): no new lines after the marker.
Catch this walk: empty after the marker.

Harbour expansion 8 (native 40285, 2026-09-06, same `fluffos` /
`Mud@2026`, do not redo docks, inn/office, towers,
Westway, chandler/flowerbed/alley, westroad5/sell-shop,
or westroad6/post-office look-ats):

- North of westroad6 → a fishmonger's
  (`look at tiles` / `vats` / `sign` FERIDWYN'S SEAFOOD).
  South back.
- East → tailor-front Westway / Elrimand Road
  (`look at sign` Couture Celimarith / `flagstones`).
  West back.
- East of the Counting House street → The bank of Silvere
  (`look at sign` / `panelling`). Deposit is not implemented.
- `score` persist. Reconnect still lands on the docks.

This-boot live `libs/aoh/log/debug.log` (fd 3, PID 1977309
BOOT_MARKER9 aoh-wr7-fish-bank): no new lines after the marker.
Catch this walk: empty after the marker.

Harbour expansion 9 (native 40285, 2026-09-06, same `fluffos` /
`Mud@2026`, do not redo docks, inn/office, towers,
Westway, chandler/flowerbed/alley, westroad5/sell-shop,
westroad6/post-office, or westroad7/fishmonger/bank
look-ats):

- South of westroad7 → a tailor shop
  (`look at cloth` / `dummy` / `sign`). North back.
- North → Elrimand Road
  (`look at sign` Eldranna's Bake Shoppe / `bakery`).
  South back.
- East → wine-shop-front Westway
  (`look at sign` wine glass / `vines`).
- `score` persist. Reconnect still lands on the docks.

This-boot live `libs/aoh/log/debug.log` (fd 3, PID 2014609
BOOT_MARKER10 aoh-wr8-tailor-elrimand): no new lines after
the marker. Catch this walk: empty after the marker.

Harbour expansion 10 (native 40285, 2026-09-06, same
`fluffos` / `Mud@2026`, do not redo docks, inn/office,
towers, Westway, chandler/flowerbed/alley,
westroad5/sell-shop, westroad6/post-office,
westroad7/fishmonger/bank, or westroad8/tailor/Elrimand
look-ats):

- North of westroad8 → a wine merchant's shop
  (`look at racks` / `sign` CHEZ BRIGAN). South back.
- East → Guild Street fork
  (`look at street` / `palace`). West back.
- West of Elrimand Road → Eldranna's Bake Shoppe
  (`look at shelves` / `chalkboard`). Buy is not
  implemented.
- `score` persist. Reconnect still lands on the docks.

This-boot live `libs/aoh/log/debug.log` (fd 3, PID 2033649
BOOT_MARKER11 aoh-wr9-wine-bakery): no new lines after
the marker. Catch this walk: empty after the marker.

Harbour expansion 11 (native 40285, 2026-09-06, same
`fluffos` / `Mud@2026`, do not redo docks, inn/office,
towers, Westway, chandler/flowerbed/alley,
westroad5/sell-shop, westroad6/post-office,
westroad7/fishmonger/bank, westroad8/tailor/Elrimand,
or westroad9/wineshop/bakery look-ats):

- East of westroad9 → flower-shop-front Westway
  (`look at sign` iron rose / `roses` / `palace` marble).
  West back.
- South → Library road (`look at guild` / `library`).
  West → library road west (`look at library`). Guild
  and library interiors are archive stubs.
- `score` persist. Reconnect still lands on the docks.

This-boot live `libs/aoh/log/debug.log` (fd 3, PID 2061268
BOOT_MARKER12 aoh-wr10-guildstreet): no new lines after
the marker. Catch this walk: empty after the marker.

Harbour expansion 12 (native 40285, 2026-09-06, same
`fluffos` / `Mud@2026`, do not redo docks, inn/office,
towers, Westway, chandler/flowerbed/alley,
westroad5/sell-shop, westroad6/post-office,
westroad7/fishmonger/bank, westroad8/tailor/Elrimand,
westroad9/wineshop/bakery, or westroad10/Guild Street
look-ats):

- South of westroad10 → a flower shop
  (`look at flowers` / `sign` JEHANE'S FLOWERS /
  `vases`). Archive long keeps the typo “myriard”.
  Buy is not implemented. North back.
- East → palace-square approach Westway
  (`look at palace` white marble/gardens / `square` /
  `murals`). East palace square (`westenter`) is
  still the LDMud original — not loaded.
- `score` persist. Reconnect still lands on the docks.

This-boot live `libs/aoh/log/debug.log` (fd 3, PID 2090614
BOOT_MARKER13 aoh-wr11-flowershop): no new lines after
the marker. Catch this walk: empty after the marker.

Harbour expansion 13 (native 40285, 2026-09-06, same
`fluffos` / `Mud@2026`, do not redo docks, inn/office,
towers, Westway, chandler/flowerbed/alley,
westroad5/sell-shop, westroad6/post-office,
westroad7/fishmonger/bank, westroad8/tailor/Elrimand,
westroad9/wineshop/bakery, westroad10/Guild Street,
or westroad11/Jehane flower-shop look-ats):

- East of westroad11 → Central place, west end
  (`look at palace` brownstone wall / `trees` lime /
  `statue` too far). Archive detail keeps the typo
  “gaurds”. East West Palace Avenue (`outside1`) is
  still the LDMud original — not loaded.
- `score` persist. Reconnect still lands on the docks.

This-boot live `libs/aoh/log/debug.log` (fd 3, PID 2120738
BOOT_MARKER14 aoh-westenter): no new lines after
the marker. Catch this walk: empty after the marker.

Harbour expansion 14 (native 40285, 2026-09-06, same
`fluffos` / `Mud@2026`, do not redo docks, inn/office,
towers, Westway, chandler/flowerbed/alley,
westroad5/sell-shop, westroad6/post-office,
westroad7/fishmonger/bank, westroad8/tailor/Elrimand,
westroad9/wineshop/bakery, westroad10/Guild Street,
westroad11/Jehane flower-shop, or westenter
palace-square west-end look-ats):

- East of westenter → West Palace Avenue
  (`look at stone` brownstones / `gulls` / `avenue`
  statue “gaurds”). Archive long keeps “roads leads”.
  East Avenue of the Palace (`outside2`) is still
  the LDMud original — not loaded.
- `score` persist. Reconnect still lands on the docks.

This-boot live `libs/aoh/log/debug.log` (fd 3, PID 2152533
BOOT_MARKER15 aoh-outside1): no new lines after
the marker. Catch this walk: empty after the marker.

Harbour expansion 15 (native 40285, 2026-09-06, same
`fluffos` / `Mud@2026`, do not redo docks, inn/office,
towers, Westway, chandler/flowerbed/alley,
westroad5/sell-shop, westroad6/post-office,
westroad7/fishmonger/bank, westroad8/tailor/Elrimand,
westroad9/wineshop/bakery, westroad10/Guild Street,
westroad11/Jehane flower-shop, westenter
palace-square west-end, or outside1 West Palace
Avenue look-ats):

- East of outside1 → Avenue of the Palace
  (`look at statue` helmeted Rilana / `roses` Myrads /
  `inscription` Gaurdian). Touch/helmet is not
  implemented. South `outside3` / north `outside32`
  are still the LDMud originals — not loaded.
- `score` persist. Reconnect still lands on the docks.

This-boot live `libs/aoh/log/debug.log` (fd 3, PID 2185452
BOOT_MARKER16 aoh-outside2): no new lines after
the marker. Catch this walk: empty after the marker.

Harbour expansion 16 (native 40285, 2026-09-06, same
`fluffos` / `Mud@2026`, do not redo docks, inn/office,
towers, Westway, chandler/flowerbed/alley,
westroad5/sell-shop, westroad6/post-office,
westroad7/fishmonger/bank, westroad8/tailor/Elrimand,
westroad9/wineshop/bakery, westroad10/Guild Street,
westroad11/Jehane flower-shop, westenter
palace-square west-end, outside1 West Palace Avenue,
or outside2 Avenue of the Palace look-ats):

- South of outside2 → The palace avenue
  (`look at cinnamon` cassia / `flowers` gentleman's
  buttons / `trees` lime). Archive long keeps
  “forage though”. South `outside4` is still the
  LDMud original — not loaded.
- `score` persist. Reconnect still lands on the docks.

This-boot live `libs/aoh/log/debug.log` (fd 3, PID 2206456
BOOT_MARKER17 aoh-outside3): no new lines after
the marker. Catch this walk: empty after the marker.

Harbour expansion 17 (native 40285, 2026-09-06, same
`fluffos` / `Mud@2026`, do not redo docks, inn/office,
towers, Westway, chandler/flowerbed/alley,
westroad5/sell-shop, westroad6/post-office,
westroad7/fishmonger/bank, westroad8/tailor/Elrimand,
westroad9/wineshop/bakery, westroad10/Guild Street,
westroad11/Jehane flower-shop, westenter
palace-square west-end, outside1 West Palace Avenue,
outside2 Avenue of the Palace, or outside3
cinnamon/gentleman's-buttons look-ats):

- South of outside3 → The palace avenue
  (`look at saliums` pink / `stone` brownstones /
  `jays`). Archive long keeps “gentley” and
  “forage though”. South `outside5` is still the
  LDMud original — not loaded.
- `score` persist. Reconnect still lands on the docks.

This-boot live `libs/aoh/log/debug.log` (fd 3, PID 2235109
BOOT_MARKER18 aoh-outside4): no new lines after
the marker. Catch this walk: empty after the marker.

Harbour expansion 18 (native 40285, 2026-09-06, same
`fluffos` / `Mud@2026`, do not redo docks, inn/office,
towers, Westway, chandler/flowerbed/alley,
westroad5/sell-shop, westroad6/post-office,
westroad7/fishmonger/bank, westroad8/tailor/Elrimand,
westroad9/wineshop/bakery, westroad10/Guild Street,
westroad11/Jehane flower-shop, westenter
palace-square west-end, outside1 West Palace Avenue,
outside2 Avenue of the Palace, outside3
cinnamon/gentleman's-buttons, or outside4
salium-bed look-ats):

- South of outside4 → The palace avenue
  (`look at flowers` purple bonnie bells / `cinnamon` /
  `avenue` curves north and east). Archive long keeps
  “thier”. East `outside6` — see Harbour expansion 19.
- `score` persist. Reconnect still lands on the docks.

This-boot live `libs/aoh/log/debug.log` (fd 3, PID 2264366
BOOT_MARKER19 aoh-outside5): no new lines after
the marker. Catch this walk: empty after the marker.

Harbour expansion 19 (native 40285, 2026-09-06, same
`fluffos` / `Mud@2026`, do not redo docks, inn/office,
towers, Westway, chandler/flowerbed/alley,
westroad5/sell-shop, westroad6/post-office,
westroad7/fishmonger/bank, westroad8/tailor/Elrimand,
westroad9/wineshop/bakery, westroad10/Guild Street,
westroad11/Jehane flower-shop, westenter
palace-square west-end, outside1 West Palace Avenue,
outside2 Avenue of the Palace, outside3
cinnamon/gentleman's-buttons, outside4
salium-bed, or outside5 east-corner bonnie-bell
look-ats):

- East of outside5 → Road at the palace
  (`look at roses` pink and creamy white / `palace`
  front wall / `avenue` northern approach / `stone`
  “The stones brownstones” / `doves`). East
  `outside7` — see Harbour expansion 20.
- `score` persist. Reconnect still lands on the docks.

This-boot live `libs/aoh/log/debug.log` (fd 3, PID 2294047
BOOT_MARKER20 aoh-outside6): this-run boot banner only
(driver truncates the log on open); no `error:` after
Initializations complete. Catch this walk: empty after
the marker.

Harbour expansion 20 (native 40285, 2026-09-06, same
`fluffos` / `Mud@2026`, do not redo docks, inn/office,
towers, Westway, chandler/flowerbed/alley,
westroad5/sell-shop, westroad6/post-office,
westroad7/fishmonger/bank, westroad8/tailor/Elrimand,
westroad9/wineshop/bakery, westroad10/Guild Street,
westroad11/Jehane flower-shop, westenter
palace-square west-end, outside1 West Palace Avenue,
outside2 Avenue of the Palace, outside3
cinnamon/gentleman's-buttons, outside4
salium-bed, outside5 east-corner bonnie-bell,
or outside6 rose/palace look-ats):

- East of outside6 → Road at the palace
  (`look at gulls` / `shrubs` pink and creamy white /
  `wall` front palace / `path` northern approach).
  Same Joan front-wall rose stretch as outside6.
  East `outside8` — see Harbour expansion 21.
- `score` persist. Reconnect still lands on the docks.

This-boot live `libs/aoh/log/debug.log` (fd 3, PID 2322674
BOOT_MARKER21 aoh-outside7): no new lines after the
marker. Catch this walk: empty after the marker.

Harbour expansion 21 (native 40285, 2026-09-06, same
`fluffos` / `Mud@2026`, do not redo docks, inn/office,
towers, Westway, chandler/flowerbed/alley,
westroad5/sell-shop, westroad6/post-office,
westroad7/fishmonger/bank, westroad8/tailor/Elrimand,
westroad9/wineshop/bakery, westroad10/Guild Street,
westroad11/Jehane flower-shop, westenter
palace-square west-end, outside1 West Palace Avenue,
outside2 Avenue of the Palace, outside3
cinnamon/gentleman's-buttons, outside4
salium-bed, outside5 east-corner bonnie-bell,
outside6 rose/palace, or outside7
gulls/shrubs/wall look-ats):

- East of outside7 → Road at the palace
  (`look at brownstones` “The stones brownstones” /
  `seagulls` / `rose` pink and creamy white / `road`
  northern approach). Same Joan front-wall rose
  stretch as outside6/outside7. East `outside9` —
  see Harbour expansion 22.
- `score` persist. Reconnect still lands on the docks.

This-boot live `libs/aoh/log/debug.log` (fd 3, PID 2351704
BOOT_MARKER22 aoh-outside8): no new lines after the
marker. Catch this walk: empty after the marker.

Harbour expansion 22 (native 40285, 2026-09-06, same
`fluffos` / `Mud@2026`, do not redo docks, inn/office,
towers, Westway, chandler/flowerbed/alley,
westroad5/sell-shop, westroad6/post-office,
westroad7/fishmonger/bank, westroad8/tailor/Elrimand,
westroad9/wineshop/bakery, westroad10/Guild Street,
westroad11/Jehane flower-shop, westenter
palace-square west-end, outside1 West Palace Avenue,
outside2 Avenue of the Palace (statue), outside3
cinnamon/gentleman's-buttons, outside4
salium-bed, outside5 east-corner bonnie-bell,
outside6 rose/palace, outside7
gulls/shrubs/wall, or outside8
brownstones/seagulls/rose look-ats):

- East of outside8 → Avenue of the Palace
  (long “A broad road leads north to palace
  entrance”; `look at avenue` northern approach /
  `mourning doves` / `palace wall` / `stones`
  “The stones brownstones”). North `palplace1` —
  see Harbour expansion 23. East `mainsouth1` is
  still the LDMud original — not loaded.
- `score` persist. Reconnect still lands on the docks.

This-boot live `libs/aoh/log/debug.log` (fd 3, PID 2389673
BOOT_MARKER23 aoh-outside9): no new lines after the
marker. Catch this walk: empty after the marker.

Harbour expansion 23 (native 40285, 2026-09-06, same
`fluffos` / `Mud@2026`, do not redo docks, inn/office,
towers, Westway, chandler/flowerbed/alley,
westroad5/sell-shop, westroad6/post-office,
westroad7/fishmonger/bank, westroad8/tailor/Elrimand,
westroad9/wineshop/bakery, westroad10/Guild Street,
westroad11/Jehane flower-shop, westenter
palace-square west-end, outside1–outside8, or
outside9 Avenue-of-the-Palace entrance-fork look-ats):

- North of outside9 → The palace square
  (long exotic flowers / gravel / crushed seashells;
  `look at flowers` / `saliums` pink / `lanterns`
  cast-iron alabaster / `roses`). North `palplace4`
  (The place before the palace) and east `palplace2`
  are still the LDMud originals — not loaded.
- `score` persist. Reconnect still lands on the docks.

This-boot live `libs/aoh/log/debug.log` (fd 3, PID 2412237
BOOT_MARKER24 aoh-palplace1): no new lines after the
marker. Catch this walk: empty after the marker.

Harbour expansion 24 (native 40285, 2026-09-06, same
`fluffos` / `Mud@2026`, do not redo docks, inn/office,
towers, Westway, chandler/flowerbed/alley,
westroad5/sell-shop, westroad6/post-office,
westroad7/fishmonger/bank, westroad8/tailor/Elrimand,
westroad9/wineshop/bakery, westroad10/Guild Street,
westroad11/Jehane flower-shop, westenter
palace-square west-end, outside1–outside9, or
palplace1 palace-square west-side look-ats):

- North of palplace1 → The place before the palace
  (long latticed windows / basement / artfully aranged
  flowers / cascades of roses / white marble bench;
  `look at bench` / `marble bench` / `lanterns`
  cast-iron alabaster / `roses` / `flowers` pink
  saliums / `palace` brown stone). East `palplace5`
  (At the entrance into the palace) is still the
  LDMud original — not loaded.
- `score` persist. Reconnect still lands on the docks.

This-boot live `libs/aoh/log/debug.log` (fd 3, PID 2443689
BOOT_MARKER25 aoh-palplace4): no new lines after the
marker. Catch this walk: empty after the marker.

Harbour expansion 25 (native 40285, 2026-09-06, same
`fluffos` / `Mud@2026`, do not redo docks, inn/office,
towers, Westway, chandler/flowerbed/alley,
westroad5/sell-shop, westroad6/post-office,
westroad7/fishmonger/bank, westroad8/tailor/Elrimand,
westroad9/wineshop/bakery, westroad10/Guild Street,
westroad11/Jehane flower-shop, westenter
palace-square west-end, outside1–outside9,
palplace1 palace-square west-side, or palplace4
place-before-the-palace look-ats):

- East of palplace4 → At the entrance into the palace
  (long brownstone entry way / hieroglyphics / citygates;
  `look at hieroglyphics` founding of Silvere /
  `palace` brown stone / `roses` / `flowers` pink
  saliums). North `enter palace` / `palenter`, south
  `palplace2` (fountain square), and east `palplace6`
  are still the LDMud originals — not loaded.
- `score` persist. Reconnect still lands on the docks.

This-boot live `libs/aoh/log/debug.log` (fd 3, PID 2472361
BOOT_MARKER26 aoh-palplace5): no new lines after the
marker. Catch this walk: empty after the marker.

Harbour expansion 26 (native 40285, 2026-09-06, same
`fluffos` / `Mud@2026`, do not redo docks, inn/office,
towers, Westway, chandler/flowerbed/alley,
westroad5/sell-shop, westroad6/post-office,
westroad7/fishmonger/bank, westroad8/tailor/Elrimand,
westroad9/wineshop/bakery, westroad10/Guild Street,
westroad11/Jehane flower-shop, westenter
palace-square west-end, outside1–outside9,
palplace1 palace-square west-side, palplace4
place-before-the-palace, or palplace5
palace-entrance look-ats):

- South of palplace5 → The palace square (fountain)
  (long exotic flowers / geometric designs / carved
  fountain / basin; `look at fountain` pearly white
  stone / 4 carved griffins / `griffins` / `griffons`
  eagles' heads / `pearly carved white stone` /
  `pearly white stone basin` / `paving stones`
  sunburst / `flowers` Lu'meyn gardens). `drink water`
  is not wired. South `mainsouth1` and east `palplace3`
  are still the LDMud originals — not loaded.
- `score` persist. Reconnect still lands on the docks.

This-boot live `libs/aoh/log/debug.log` (fd 3, PID 2500061
BOOT_MARKER27 aoh-palplace2): no new lines after the
marker. Catch this walk: empty after the marker.

Harbour expansion 27 (native 40285, 2026-09-07, same
`fluffos` / `Mud@2026`, do not redo docks, inn/office,
towers, Westway, chandler/flowerbed/alley,
westroad5/sell-shop, westroad6/post-office,
westroad7/fishmonger/bank, westroad8/tailor/Elrimand,
westroad9/wineshop/bakery, westroad10/Guild Street,
westroad11/Jehane flower-shop, westenter
palace-square west-end, outside1–outside9,
palplace1 palace-square west-side, palplace4
place-before-the-palace, palplace5 palace-entrance,
or palplace2 fountain look-ats):

- South of palplace2 → Avenue of the Palace
  (long north to palace entrance / south to harbour /
  huge white marble statue / pink and white roses;
  `look at statue` winged Sarykan / black boots /
  eels and star fish / whirlpool cloak /
  `inscription` / `base` The Gaurdian Sarykan /
  `roses` / `avenue` quietly gaurds). `touch statue`
  is not wired. South `mainroad1`, east `outside10`,
  and west `outside9` exits are not loaded this slice.
- `score` persist. Reconnect still lands on the docks.

This-boot live `libs/aoh/log/debug.log` (fd 3, PID 2529898
BOOT_MARKER28 aoh-mainsouth1): no new lines after the
marker. Catch this walk: empty after the marker.

Harbour expansion 28 (native 40285, 2026-09-07, same
`fluffos` / `Mud@2026`, do not redo docks, inn/office,
towers, Westway, chandler/flowerbed/alley,
westroad5–westroad11, westenter, outside1–outside9,
palplace1–palplace5, palplace2 fountain, or
mainsouth1 Sarykan look-ats):

- South of mainsouth1 → On a road at Silvere
  (long palace north / city gates south / buildings
  somewhat foggy, archive typo “seems”; archive stub —
  `look at buildings` / `road` / `palace` / `gates`
  nothing special). South `mainroad2` is still the
  LDMud original — not loaded.
- `score` persist. Reconnect still lands on the docks.

This-boot live `libs/aoh/log/debug.log` (fd 3, PID 2558804
BOOT_MARKER29 aoh-mainroad1): no new lines after the
marker. Catch this walk: empty after the marker.

Harbour expansion 29 (native 40285, 2026-09-07, same
`fluffos` / `Mud@2026`, do not redo docks, inn/office,
towers, Westway, chandler/flowerbed/alley,
westroad5–westroad11, westenter, outside1–outside9,
palplace1–palplace5, palplace2 fountain,
mainsouth1 Sarykan, or south/mainroad1 foggy-road
look-ats):

- East of palplace2 → The place before the palace
  (long eastern side / exotic flowers / gravel and
  crushed seashells / palace windows; `look at lanterns`
  alabaster / `palace` brown stone / `roses` pink and
  creamy white / `flowers` / `saliums` / `gulls` /
  `doves`; `look at gravel` / `seashells` / `windows`
  nothing special). North `palplace6` and south
  `outside10` are still the LDMud originals — not
  loaded (`You cannot go that way.`).
- `score` persist. Reconnect still lands on the docks.

This-boot live `libs/aoh/log/debug.log` (fd 3, PID 2588690
BOOT_MARKER30 aoh-palplace3): no new lines after the
marker. Catch this walk: empty after the marker.

Harbour expansion 30 (native 40285, 2026-09-07, same
`fluffos` / `Mud@2026`, do not redo docks, inn/office,
towers, Westway, chandler/flowerbed/alley,
westroad5–westroad11, westenter, outside1–outside9,
palplace1–palplace5, palplace2 fountain,
mainsouth1 Sarykan, south/mainroad1 foggy-road, or
palplace3 east-wing look-ats):

- North of palplace3 → The place before the palace
  (long latticed windows / basement / archive typo
  “enrance” / artfully arranged flowers / cascades of
  roses; `look at lanterns` alabaster / `palace` brown
  stone / `roses` pink and creamy white / `flowers` /
  `saliums` / `bench` / `white marble bench` / `gulls`
  / `doves`; `look at windows` / `basement` /
  `latticed windows` nothing special). West back to
  palplace5 works. South `outside10` is still the
  LDMud original — not loaded.
- `score` persist. Reconnect still lands on the docks.

This-boot live `libs/aoh/log/debug.log` (fd 3, PID 2618069
BOOT_MARKER31 aoh-palplace6): no new lines after the
marker. Catch this walk: empty after the marker.

Harbour expansion 31 (native 40285, 2026-09-07, same
`fluffos` / `Mud@2026`, do not redo docks, inn/office,
towers, Westway, chandler/flowerbed/alley,
westroad5–westroad11, westenter, outside1–outside9,
palplace1–palplace6, palplace2 fountain,
mainsouth1 Sarykan, south/mainroad1 foggy-road, or
palplace3 east-wing look-ats):

- South of palplace3 → Road at the palace
  (long tree-lined avenue / north to palace entrance /
  pink and white shrub roses; `look at avenue` /
  `road` northern approach / `stones` / `brownstones`
  archive “The stones brownstones” / `palace` brown
  stone / `roses` / `gulls` / `doves`). East
  `outside11` is still the LDMud original — not
  loaded (`You cannot go that way.`). West back to
  mainsouth1 works.
- `score` persist. Reconnect still lands on the docks.

This-boot live `libs/aoh/log/debug.log` (fd 3, PID 2646658
BOOT_MARKER32 aoh-outside10): no new lines after the
marker. Catch this walk: empty after the marker.

Harbour expansion 32 (native 40285, 2026-09-07, same
`fluffos` / `Mud@2026`, do not redo docks, inn/office,
towers, Westway, chandler/flowerbed/alley,
westroad5–westroad11, westenter, outside1–outside10,
palplace1–palplace6, palplace2 fountain,
mainsouth1 Sarykan, south/mainroad1 foggy-road, or
palplace3 east-wing look-ats):

- East of outside10 → Avenue the palace
  (archive short typo missing “of”; long tree-lined
  avenue / pink and white shrub roses; `look at avenue`
  / `road` “To the west the graceful avenue” /
  `stones` / `brownstones` archive “The stones
  brownstones” / `palace` brown stone / `roses` /
  `gulls` / `doves`). East `outside12` is still the
  LDMud original — not loaded (`You cannot go that
  way.`). West back to outside10 works.
- `score` persist. Reconnect still lands on the docks.

This-boot live `libs/aoh/log/debug.log` (fd 3, PID 2675159
BOOT_MARKER33 aoh-outside11): no new lines after the
marker. Catch this walk: empty after the marker.

Harbour expansion 33 (native 40285, 2026-09-07, same
`fluffos` / `Mud@2026`, do not redo docks, inn/office,
towers, Westway, chandler/flowerbed/alley,
westroad5–westroad11, westenter, outside1–outside11,
palplace1–palplace6, palplace2 fountain,
mainsouth1 Sarykan, south/mainroad1 foggy-road, or
palplace3 east-wing look-ats):

- East of outside11 → Road at the palace
  (long tree-lined avenue / pink and white shrub roses;
  `look at avenue` / `road` “To the west the graceful
  avenue” / `stones` / `brownstones` archive “The
  stones brownstones” / `palace` brown stone / `roses`
  / `gulls` / `doves`). East `outside13` is still the
  LDMud original — not loaded (`You cannot go that
  way.`). West back to Avenue the palace works.
- `score` persist. Reconnect still lands on the docks.

This-boot live `libs/aoh/log/debug.log` (fd 3, PID 2703475
BOOT_MARKER34 aoh-outside12): no new lines after the
marker. Catch this walk: empty after the marker.

Harbour expansion 34 (native 40285, 2026-09-07, same
`fluffos` / `Mud@2026`, do not redo docks, inn/office,
towers, Westway, chandler/flowerbed/alley,
westroad5–westroad11, westenter, outside1–outside12,
palplace1–palplace6, palplace2 fountain,
mainsouth1 Sarykan, south/mainroad1 foggy-road, or
palplace3 east-wing look-ats):

- East of outside12 → Road at the palace
  (long tree-lined avenue / pink and white shrub roses;
  `look at avenue` / `road` “To the west the graceful
  avenue” / `stones` / `brownstones` archive “The
  stones brownstones” / `palace` brown stone / `roses`
  / `gulls` / `doves`). East `outside14` is still the
  LDMud original — not loaded (`You cannot go that
  way.`). West back to outside12 works.
- `score` persist. Reconnect still lands on the docks.

This-boot live `libs/aoh/log/debug.log` (fd 3, PID 2733196
BOOT_MARKER35 aoh-outside13): no new lines after the
marker. Catch this walk: empty after the marker.

Harbour expansion 35 (native 40285, 2026-09-07, same
`fluffos` / `Mud@2026`, do not redo docks, inn/office,
towers, Westway, chandler/flowerbed/alley,
westroad5–westroad11, westenter, outside1–outside13,
palplace1–palplace6, palplace2 fountain,
mainsouth1 Sarykan, south/mainroad1 foggy-road, or
palplace3 east-wing look-ats):

- East of outside13 → The palace avenue
  (turns west and north; Lady flowers archive “thier”;
  `look at lady flowers` / `cinnamon` “the the
  brownstone” / `trees`).
- North → The palace avenue (Arabellas / archive
  “gentley”; `look at arabellas` / `flowers`).
- North → The palace avenue (purple venus poppys;
  archive “poppys”).
- North → Avenue of the Palace (Tali statue / firery
  cloak and swords / `look at inscription` “The
  Gaurdian Tali” fire; `look at base` marble;
  `look at roses` red shrub). `touch statue` not
  wired (`What?`). East `eastroad1` still LDMud
  (`You cannot go that way.`).
- North → The palace avenue (Morning Stars).
- North → The palace avenue (pomegranate grove;
  `look at grove` archive “pomegranatetrees”;
  `look at pomegranates` “You can't see them from
  here.”). North `outside20` and west `garden4`
  still LDMud. South back to Morning Stars works.
- `score` persist. Reconnect still lands on the docks.

This-boot live `libs/aoh/log/debug.log` (fd 3, PID 2752534
BOOT_MARKER36 aoh-outside14-19): no new lines after the
marker. Catch this walk: empty after the marker.

Harbour expansion 36 (native 40285, 2026-09-07, same
`fluffos` / `Mud@2026`, do not redo docks, inn/office,
towers, Westway, westenter, outside1–outside19,
palplace1–palplace6, mainsouth1 Sarykan,
south/mainroad1, or Tali statue look-ats):

- North of outside19 → The palace avenue
  (turns west and south; `look at grove` archive
  “grove os sweet”; `look at pomegranates` “You
  can't see them from here.”). Southwest `garden4`
  still LDMud.
- West → Avenue at the palace (rear palace wall;
  `look at brownstones` archive “The stones
  brownstones” / `grove` / `palace`). South
  `garden4` still LDMud.
- West → Avenue at the palace (`look at doves`
  archive “trees..” / `grove`). South `garden3`
  still LDMud.
- West → Avenue of the Palace (`look at angelica`
  / `sorrel` / `astra liliums`). West `outside24`
  still LDMud. East back to the dove stretch works.
- `score` persist. Reconnect still lands on the docks.

This-boot live `libs/aoh/log/debug.log` (fd 3, PID 2757269
BOOT_MARKER37 aoh-outside20-23): no new lines after the
marker. Catch this walk: empty after the marker.

Harbour expansion 37 (native 40285, 2026-09-07, same
`fluffos` / `Mud@2026`, do not redo docks, inn/office,
towers, Westway, westenter, outside1–outside23,
palplace1–palplace6, mainsouth1 Sarykan,
south/mainroad1, Tali statue, or grove look-ats):

- West of outside23 → Avenue of the Palace
  (`look at sage` / `mint` / orange `star liliums`).
- West → Avenue of the Palace (Kyrie statue / ice
  swords / snowy whirlwind cloak; `look at
  inscription` “The Gaurdian Kyrie” wind; `look at
  roses`). `touch statue` not wired (`What?`).
  North `northroad` still LDMud.
- West → Avenue of the Palace (`look at bay`
  archive “lavendar” / `lavender` / orange `astra
  liliums`).
- West → Avenue at the palace (`look at ginger` /
  `parsley` / yellow `star liliums`). West
  `outside28` still LDMud. East back to bay/lavender
  works.
- `score` persist. Reconnect still lands on the docks.

This-boot live `libs/aoh/log/debug.log` (fd 3, PID 2789264
BOOT_MARKER38 aoh-outside24-27): no new lines after the
marker. Catch this walk: empty after the marker.

Harbour expansion 38 (native 40285, 2026-09-07, same
`fluffos` / `Mud@2026`, do not redo docks, inn/office,
towers, Westway, westenter, outside1–outside27,
palplace1–palplace6, mainsouth1 Sarykan,
south/mainroad1, Tali/Kyrie statues, or herb-bed
look-ats):

- West of outside27 → Avenue at the palace
  (fig grove / `look at hedge` archive “perferred”
  / `figs` “You can't see them from here.” /
  `doves` archive “trees..”). South `garden2`
  still LDMud.
- West → Avenue at the palace (fig grove / hedge
  “perferred”). South `garden1` still LDMud.
- West → The palace avenue (turns south; fig grove
  southeast). Southeast `garden1` still LDMud.
- South → The palace avenue (fig grove east).
  East `garden1` still LDMud.
- South → palace avenue (archive short omits
  “The”; `look at jasmine` / `cinnamon` “the the
  brownstone”). South closes the loop onto
  already-live Avenue of the Palace (outside2 /
  Rilana statue; no new look-ats).
- `score` persist. Reconnect still lands on the docks.

This-boot live `libs/aoh/log/debug.log` (fd 3, PID 2820105
BOOT_MARKER39 aoh-outside28-32): no new lines after the
marker. Catch this walk: empty after the marker.

Harbour expansion 39 (native 40285, 2026-09-07, same
`fluffos` / `Mud@2026`, do not redo docks, inn/office,
towers, Westway, westenter, outside1–outside32,
palplace1–palplace6, mainsouth1 Sarykan,
south/mainroad1, Tali/Kyrie statues, or palace-avenue
look-ats):

- East of Tali / outside17 → Mainroad leading east
  (palace west / eastern district east; archive stub,
  no AddDetail; `look at road` “You see nothing
  special.”).
- East → Mainroad leading east (same stub long).
- East → On a road at Silvere (foggy buildings archive
  “seems to be”; house of Joan and Mistral south).
  `look at buildings` “You see nothing special.”
  South `mistralhouse/garden1` not wired (`You cannot
  go that way.`). East citygate unfinished (`You
  cannot go that way.`). West×3 returns to Tali.
- `score` persist. Reconnect still lands on the docks.

This-boot live `libs/aoh/log/debug.log` (fd 3, PID 2825393
BOOT_MARKER40 aoh-eastroad): no new lines after the
marker. Catch this walk: empty after the marker.

Harbour expansion 40 (native 40285, 2026-09-07, same
`fluffos` / `Mud@2026`, do not redo docks, inn/office,
towers, Westway, westenter, outside1–outside32,
palplace1–palplace6, mainsouth1 Sarykan,
south/mainroad1, Tali/Kyrie statues, eastroad stubs,
or palace-avenue look-ats):

- East of outside31 → Palace Fig Garden (`look at
  grove` weather.Perhaps / `ripe figs` / `hedge`
  archive “perferred” / `tree` “figs..” / `figs`
  “the the ripe”). `pick fig` not wired (`What?`).
- East → Palace Fig Garden (archive “big leave”;
  `look at grass` “romp?”). `romp` not wired
  (`What?`). West back, north to outside29 works.
- South of outside22 → Palace pomegranate Garden
  (archive “withing”; `look at pond` “lavendar”
  / `lavendar lily` / `pomegranates` “the the ripe”
  / `fish`). `drink` not wired (`What?`). East
  `garden4` still LDMud (`You cannot go that way.`).
- `score` persist. Reconnect still lands on the docks.

This-boot live `libs/aoh/log/debug.log` (fd 3, PID 2850585
BOOT_MARKER41 aoh-gardens): no new lines after the
marker. Catch this walk: empty after the marker.

Harbour expansion 41 (native 40285, 2026-09-07, same
`fluffos` / `Mud@2026`, do not redo docks, inn/office,
towers, Westway, westenter, outside1–outside32,
palplace1–palplace6, mainsouth1 Sarykan,
south/mainroad1, Tali/Kyrie statues, eastroad stubs,
garden1–3 look-ats, or palace-avenue look-ats):

- East of garden3 → Palace pomegranate Garden
  (`look at grove` / `ripe pomegranates` / `hedge`
  archive “perferred” / `tree` “pomegranates..”).
  `pick` not wired (`What?`). East to outside19 works.
- South of mainroad1 → On a road at Silvere (foggy
  buildings archive “seems to be”; citygate south /
  palace north). `look at buildings` “You see nothing
  special.” South `mainroad3` still LDMud (`You cannot
  go that way.`).
- `score` persist. Reconnect still lands on the docks.

This-boot live `libs/aoh/log/debug.log` (fd 3, PID 2878703
BOOT_MARKER42 aoh-garden4-mainroad2): no new lines after
the marker. Catch this walk: empty after the marker.

<!-- librarian-expansion:42 -->

Harbour expansion 42 (native 40285, 2026-09-07, same
`fluffos` / `Mud@2026`, do not redo docks, inn/office,
towers, Westway, westenter, outside1–outside32,
palplace1–palplace6, mainsouth1 Sarykan,
south/mainroad1–2, Tali/Kyrie statues, eastroad stubs,
garden1–4 look-ats, or palace-avenue look-ats):

- South of mainroad2 → On a road at Silvere (foggy
  buildings archive “seems to be”; citygate south /
  palace north; `look at buildings` “You see nothing
  special.”).
- South ×3 through the same stub long to mainroad6
  (north-only). South `mainroad7` still LDMud (`You
  cannot go that way.`).
- `score` persist. Reconnect still lands on the docks.

This-boot live `libs/aoh/log/debug.log` (fd 3, PID 2905859
BOOT_MARKER43 aoh-mainroad3-6): no new lines after the
marker. Catch this walk: empty after the marker.

**Not published** (`wasm_status: partial`). Do not flip to
`playable` on this harbour walk. `look at menu`,
`look at candles`, `look at cabins`, `look at tiles`,
and tailor/bakery/wine/flower `sign`s are flavour —
buy/drink, mail, deposit, combat, `enter palace`,
`touch statue`, and tower interiors are not claimed.

<!-- librarian-expansion:43 -->

Harbour expansion 43 (native 40285, 2026-09-07, same
`fluffos` / `Mud@2026`, do not redo docks, inn/office,
towers, Westway, westenter, outside1–outside32,
palplace1–palplace6, mainsouth1 Sarykan,
south/mainroad1–6, Tali/Kyrie statues, eastroad stubs,
garden1–4 look-ats, or palace-avenue look-ats):

- South of mainroad6 → On a road at Silvere (foggy
  buildings archive “seems to be”; citygate south /
  palace north; `look at buildings` “You see nothing
  special.”).
- South ×2 through the same stub long to mainroad9
  (north-only). South `mainroad10` still LDMud (`You
  cannot go that way.`).
- `score` persist. Reconnect still lands on the docks.

This-boot live `libs/aoh/log/debug.log` (fd 3, PID 2909848
BOOT_MARKER44 aoh-mainroad7-9): no new lines after the
marker. Catch this walk: empty after the marker.

**Not published** (`wasm_status: partial`). Do not flip to
`playable` on this harbour walk. `look at menu`,
`look at candles`, `look at cabins`, `look at tiles`,
and tailor/bakery/wine/flower `sign`s are flavour —
buy/drink, mail, deposit, combat, `enter palace`,
`touch statue`, and tower interiors are not claimed.

<!-- librarian-expansion:44 -->

Harbour expansion 44 (native 40285, 2026-09-07, same
`fluffos` / `Mud@2026`, do not redo docks, inn/office,
towers, Westway, westenter, outside1–outside32,
palplace1–palplace6, mainsouth1 Sarykan,
south/mainroad1–9, Tali/Kyrie statues, eastroad stubs,
garden1–4 look-ats, or palace-avenue look-ats):

- South of mainroad9 → On a road at Silvere (foggy
  buildings archive “seems to be”; west citypark
  mention; `look at buildings` / `citypark` “You see
  nothing special.”). West `parkroad1` still LDMud
  (`You cannot go that way.`).
- South → On a road at Silvere (citygates south /
  palace and citypark crossing north; north-only).
  South `southgate` still LDMud (`You cannot go that
  way.`).
- `score` persist. Reconnect still lands on the docks.

This-boot live `libs/aoh/log/debug.log` (fd 3, PID 2934733
BOOT_MARKER45 aoh-mainroad10-11): no new lines after the
marker. Catch this walk: empty after the marker.

**Not published** (`wasm_status: partial`). Do not flip to
`playable` on this harbour walk. `look at menu`,
`look at candles`, `look at cabins`, `look at tiles`,
and tailor/bakery/wine/flower `sign`s are flavour —
buy/drink, mail, deposit, combat, `enter palace`,
`touch statue`, and tower interiors are not claimed.

<!-- librarian-expansion:45 -->

Harbour expansion 45 (native 40285, 2026-09-07, same
`fluffos` / `Mud@2026`, do not redo docks, inn/office,
towers, Westway, westenter, outside1–outside32,
palplace1–palplace6, mainsouth1 Sarykan,
south/mainroad1–11, Tali/Kyrie statues, eastroad stubs,
garden1–4 look-ats, or palace-avenue look-ats):

- West of mainroad10 → On a road at Silvere (foggy
  buildings archive “didn't decide yet”; trailing
  space; `look at buildings` “You see nothing
  special.”).
- West ×2 through the same stub long to parkroad3
  (east-only). West `parkroad4` still LDMud (`You
  cannot go that way.`).
- `score` persist. Reconnect still lands on the docks.

This-boot live `libs/aoh/log/debug.log` (fd 3, PID 2963392
BOOT_MARKER46 aoh-parkroad1-3): no new lines after the
marker. Catch this walk: empty after the marker.

**Not published** (`wasm_status: partial`). Do not flip to
`playable` on this harbour walk. `look at menu`,
`look at candles`, `look at cabins`, `look at tiles`,
and tailor/bakery/wine/flower `sign`s are flavour —
buy/drink, mail, deposit, combat, `enter palace`,
`touch statue`, and tower interiors are not claimed.

<!-- librarian-expansion:46 -->

Harbour expansion 46 (native 40285, 2026-09-07, same
`fluffos` / `Mud@2026`, do not redo docks, inn/office,
towers, Westway, westenter, outside1–outside32,
palplace1–palplace6, mainsouth1 Sarykan,
south/mainroad1–11, parkroad1–3, Tali/Kyrie statues,
eastroad stubs, garden1–4 look-ats, or palace-avenue
look-ats):

- West of parkroad3 → On a road at Silvere (foggy
  buildings archive “didn't decide yet”; trailing
  space; `look at buildings` “You see nothing
  special.”).
- West → same stub long to parkroad5 (east-only).
  West `parkroad6` still LDMud (`You cannot go that
  way.`).
- `score` persist. Reconnect still lands on the docks.

This-boot live `libs/aoh/log/debug.log` (fd 3, PID 2992129
BOOT_MARKER47 aoh-parkroad4-5): no new lines after the
marker. Catch this walk: empty after the marker.

**Not published** (`wasm_status: partial`). Do not flip to
`playable` on this harbour walk. `look at menu`,
`look at candles`, `look at cabins`, `look at tiles`,
and tailor/bakery/wine/flower `sign`s are flavour —
buy/drink, mail, deposit, combat, `enter palace`,
`touch statue`, and tower interiors are not claimed.

<!-- librarian-expansion:47 -->

Harbour expansion 47 (native 40285, 2026-09-07, same
`fluffos` / `Mud@2026`, do not redo docks, inn/office,
towers, Westway, westenter, outside1–outside32,
palplace1–palplace6, mainsouth1 Sarykan,
south/mainroad1–11, parkroad1–5, Tali/Kyrie statues,
eastroad stubs, garden1–4 look-ats, or palace-avenue
look-ats):

- West of parkroad5 → On a road at Silvere (wall+trees;
  archive “looks somewhat” / “as someone didn't decide
  yet”; trailing space; `look at buildings` / `wall` /
  `trees` “You see nothing special.”).
- West → On a road at Silvere (citypark to the west
  into the city; archive “hasn't decided yet”;
  east-only). West park interiors still LDMud (`You
  cannot go that way.`).
- `score` persist. Reconnect still lands on the docks.

This-boot live `libs/aoh/log/debug.log` (fd 3, PID 3019962
BOOT_MARKER48 aoh-parkroad6-parkenter): no new lines after
the marker. Catch this walk: empty after the marker.

**Not published** (`wasm_status: partial`). Do not flip to
`playable` on this harbour walk. `look at menu`,
`look at candles`, `look at cabins`, `look at tiles`,
and tailor/bakery/wine/flower `sign`s are flavour —
buy/drink, mail, deposit, combat, `enter palace`,
`touch statue`, and tower interiors are not claimed.
Next aoh slice: north `northroad` (south of Kyrie /
outside25; foggy stub; `prevent_void` north; look-ats
only). Do not load `southgate` interiors or park
interiors this next leftover unless that is the assigned
batch.

<!-- librarian-expansion:48 -->

Harbour expansion 48 (native 40285, 2026-09-07, same
`fluffos` / `Mud@2026`, do not redo docks, inn/office,
towers, Westway, westenter, outside1–outside32,
palplace1–palplace6, mainsouth1 Sarykan look-ats,
south/mainroad1–11, parkroad1–6, parkenter,
Tali/Kyrie statues, eastroad stubs, garden1–4
look-ats, or palace-avenue look-ats):

- North of outside25 (Kyrie) → On a road at Silvere
  (broad road backside of the palace; archive “seems
  to be”; south-only; `look at buildings` “You see
  nothing special.”). North still unwired (`You
  cannot go that way.`; no LDMud `prevent_void`
  message).
- West of mainsouth1 → already-live outside9
  (Avenue of the Palace; exits west, north and east).
  East back to mainsouth1 works.
- `score` persist. Reconnect still lands on the docks.

This-boot live `libs/aoh/log/debug.log` (fd 3, PID 3050915
BOOT_MARKER49 aoh-northroad-mainsouth1-west): no new
lines after the marker. Catch this walk: empty after
the marker.

**Not published** (`wasm_status: partial`). Do not flip to
`playable` on this harbour walk. `look at menu`,
`look at candles`, `look at cabins`, `look at tiles`,
and tailor/bakery/wine/flower `sign`s are flavour —
buy/drink, mail, deposit, combat, `enter palace`,
`touch statue`, and tower interiors are not claimed.
Next aoh slice: further council road (`councilroad2+`
east of already-live Elrimand / `councilroad1`) if
those are look-at stubs with no shop/combat. Do not
load `southgate` interiors, park interiors (`SIL_PARK`),
`palenter`, or mistralhouse this next leftover unless
that is the assigned batch.

<!-- librarian-expansion:49 -->

Harbour expansion 49 (native 40285, 2026-09-07, same
`fluffos` / `Mud@2026`, do not redo docks, inn/office,
towers, Westway, westenter, outside1–outside32,
palplace1–palplace6, mainsouth1 Sarykan look-ats,
south/mainroad1–11, parkroad1–6, parkenter,
Tali/Kyrie statues, eastroad stubs, garden1–4,
northroad, mainsouth1↔outside9, bakery look-ats,
or palace-avenue look-ats):

- North of councilroad1 → Elrimand Road (`look at
  houses` / `guards` / `flagstones` / `coat of
  arms`).
- East → Elrimand Road. A statue is standing here
  (`look at statue` archive “semingly”; `look at
  cloak` archive “statue4s”; `look at sign` “You
  may read it.”; `look at inscription` “Elrimand,
  founder of Silvere.”; `look at hedge`).
- East → Elrimand Road, just outside the council
  hall (`look at tree` / summer `branches` /
  heart-shaped `leaves` / `trunk` / `doors` /
  `marble`). `enter hall` not wired (`What?`).
- East → Council Hall Entrance (archive stub
  “nothing here nothing can be seen”; `look at
  clocktower` “You see nothing special.”). West
  back works.
- `score` persist. Reconnect still lands on the docks.

This-boot live `libs/aoh/log/debug.log` (fd 3, PID 3077782
BOOT_MARKER50 aoh-councilroad2-enter): no new lines
after the marker. Catch this walk: empty after the
marker.

**Not published** (`wasm_status: partial`). Do not flip to
`playable` on this harbour walk. `look at menu`,
`look at candles`, `look at cabins`, `look at tiles`,
and tailor/bakery/wine/flower `sign`s are flavour —
buy/drink, mail, deposit, combat, `enter palace`,
`enter hall`, `touch statue`, and tower interiors
are not claimed.
Next aoh slice: templeroad look-ats
(`/d/silvere/rooms/west/templeroad1+` north of
already-live westroad2) if those are look-at rooms
with no shop/combat. Do not load `southgate`
interiors, park interiors (`SIL_PARK`), `palenter`,
or mistralhouse this next leftover unless that is
the assigned batch.

<!-- librarian-expansion:50 -->

Harbour expansion 50 (native 40285, 2026-09-07, same
`fluffos` / `Mud@2026`, do not redo docks, inn/office,
towers, Westway look-ats, westenter, outside1–32,
palplace1–6, mainsouth1 Sarykan, south/mainroad1–11,
parkroad1–6, parkenter, Tali/Kyrie, eastroad stubs,
garden1–4, northroad, mainsouth1↔outside9,
councilroad2–4 + councilenter, or bakery look-ats):

- North of westroad2 → Templeroad (`look at path`
  worn smooth; Xalandre sea-goddess long).
- North → Templeroad (leads in from the south;
  `look at road` “You see nothing special.”).
- East → Templeroad at the temple (`look at temple`
  / `grass` / `palms` / `ocean` / `wall`). `enter
  temple` not wired (`What?`). East still refuses
  (`You cannot go that way.`; no `xal_temple` /
  pray).
- West of already-live westshop2 → Caves of Parch
  (blocked entrance stub; `look at caves` “You see
  nothing special.”). East back works.
- `score` persist. Reconnect still lands on the docks.

This-boot live `libs/aoh/log/debug.log` (fd 3, PID 3105174
BOOT_MARKER51 aoh-templeroad-cparch): no new lines
after the marker. Catch this walk: empty after the
marker.

**Not published** (`wasm_status: partial`). Do not flip to
`playable` on this harbour walk. `look at menu`,
`look at candles`, `look at cabins`, `look at tiles`,
and tailor/bakery/wine/flower `sign`s are flavour —
buy/drink, mail, deposit, combat, `enter palace`,
`enter hall`, `enter temple`, `touch statue`, and
tower interiors are not claimed.
Next aoh slice: libraryenter stub (west of
already-live `libraryroad2`) if it is a look-at
archive stub. If that is only one room, continue
with `wsmithroad1+` look-ats (do not load the
weaponsmith shop). Do not load `southgate`
interiors, park interiors (`SIL_PARK`), `palenter`,
`xal_temple`, or mistralhouse this next leftover
unless that is the assigned batch.

<!-- librarian-expansion:51 -->

Harbour expansion 51 (native 40285, 2026-09-07, same
`fluffos` / `Mud@2026`, do not redo docks, inn/office,
towers, Westway look-ats, westenter, outside1–32,
palplace1–6, mainsouth1 Sarykan, south/mainroad1–11,
parkroad1–6, parkenter, Tali/Kyrie, eastroad stubs,
garden1–4, northroad, mainsouth1↔outside9,
councilroad2–4 + councilenter, templeroad1–3 +
cparch, bakery, or flower-shop look-ats):

- West of libraryroad2 → The Adventurers Guild
  (archive short on a library-entrance long; `look
  at library` “You see nothing special.”). `leave
  library` not wired (`What?`). East back works.
- East of already-live westshop1 → small road
  (shop mentioned; `look at shop` “You see nothing
  special.”).
- East → small road before a shop (archive “Then
  entrance”). `enter shop` not wired (`What?`).
  South still refuses (`You cannot go that way.`;
  no weaponsmith).
- `score` persist. Reconnect still lands on the docks.

This-boot live `libs/aoh/log/debug.log` (fd 3, PID 3133101
BOOT_MARKER52 aoh-libraryenter-wsmith): no new lines
after the marker. Catch this walk: empty after the
marker.

**Not published** (`wasm_status: partial`). Do not flip to
`playable` on this harbour walk. `look at menu`,
`look at candles`, `look at cabins`, `look at tiles`,
and tailor/bakery/wine/flower `sign`s are flavour —
buy/drink, mail, deposit, combat, `enter palace`,
`enter hall`, `enter temple`, `enter shop`,
`touch statue`, and tower interiors are not claimed.
Next aoh slice: Park Lane south of already-live
`cityinfo1` (`citypark1+` look-ats; do not load
`SIL_PARK` / `cityenter` enter-park). Or the
stonecutter workshop look-ats. Do not load
`southgate` interiors, park interiors (`SIL_PARK`),
`palenter`, `xal_temple`, weaponsmith, or
mistralhouse this next leftover unless that is
the assigned batch.

<!-- librarian-expansion:52 -->

Harbour expansion 52 (native 40285, 2026-09-07, same
`fluffos` / `Mud@2026`, do not redo docks, inn/office,
towers, Westway look-ats, westenter, outside1–32,
palplace1–6, mainsouth1 Sarykan, south/mainroad1–11,
parkroad1–6, parkenter, Tali/Kyrie, eastroad stubs,
garden1–4, northroad, mainsouth1↔outside9,
councilroad2–4 + councilenter, templeroad1–3 +
cparch, libraryenter, wsmithroad1–2, bakery, or
flower-shop look-ats):

- East of already-live libraryroad1 → The Adventurers
  Guild (archive stub; `look at guild` “You see
  nothing special.”). `leave guild` not wired
  (`What?`). North refuses. West back works.
- East of already-live cityinfo1 → Elder office
  (archive `Ciraran` in the long). Desk / oak /
  papers / quills / window / curtains / floral
  design / rosebush / chairs / rug / painting /
  harbour-is-a-picture / blue door look-ats.
  `sit`, `leave office`, `enter office` not wired
  (`What?`). `look at elder` “You see nothing
  special.” (NPC not loaded). West back works.
- `score` persist. Reconnect still lands on the docks.

This-boot live `libs/aoh/log/debug.log` (fd 3, PID 3162172
BOOT_MARKER53 aoh-adventurerguild-cityinfo): no new lines
after the marker. Catch this walk: empty after the
marker.

**Not published** (`wasm_status: partial`). Do not flip to
`playable` on this harbour walk. `look at menu`,
`look at candles`, `look at cabins`, `look at tiles`,
and tailor/bakery/wine/flower `sign`s are flavour —
buy/drink, mail, deposit, combat, `enter palace`,
`enter hall`, `enter temple`, `enter shop`,
`touch statue`, and tower interiors are not claimed.
Next aoh slice: `cityenter` look-at stub south of
already-live `citypark2` (do not wire `enter park`
/ `SIL_PARK`). The stonecutter workshop is an
archive orphan (south to westroad3, but westroad3
has no inbound). Do not load `southgate` interiors,
park interiors (`SIL_PARK`), `palenter`,
`xal_temple`, weaponsmith, or mistralhouse this
next leftover unless that is the assigned batch.

<!-- librarian-expansion:53 -->

Harbour expansion 53 (native 40285, 2026-09-07, same
`fluffos` / `Mud@2026`, do not redo docks, inn/office,
towers, Westway look-ats, westenter, outside1–32,
palplace1–6, mainsouth1 Sarykan, south/mainroad1–11,
parkroad1–6, parkenter, Tali/Kyrie, eastroad stubs,
garden1–4, northroad, mainsouth1↔outside9,
councilroad2–4 + councilenter, templeroad1–3 +
cparch, libraryenter, wsmithroad1–2, adventurerguild,
cityinfo office, bakery, or flower-shop look-ats):

- South of already-live cityinfo1 → Park Lane
  (day-default inlined; archive `uneaven` cobbles;
  refuse/weeds/fissures/children/women/westway).
- South → Park Lane (archive `thebare` bricks;
  peeling paint / cracked stones). `south` refuses
  (`You cannot go that way.`; no cityenter).
  `enter park` not wired (`What?`). North back works.
- `score` persist. Reconnect still lands on the docks.

This-boot live `libs/aoh/log/debug.log` (fd 3, PID 3189577
BOOT_MARKER54 aoh-citypark1-2): no new lines after the
marker. Catch this walk: empty after the marker.

**Not published** (`wasm_status: partial`). Do not flip to
`playable` on this harbour walk. `look at menu`,
`look at candles`, `look at cabins`, `look at tiles`,
and tailor/bakery/wine/flower `sign`s are flavour —
buy/drink, mail, deposit, combat, `enter palace`,
`enter hall`, `enter temple`, `enter shop`,
`enter park`, `touch statue`, and tower interiors
are not claimed.
Next aoh slice: `southgate` look-ats south of
already-live `mainroad11` (do not implement ivy
climb / weapons). Do not load `SIL_PARK`
interiors, `palenter`, `xal_temple`, weaponsmith,
or mistralhouse this next leftover unless that is
the assigned batch. Stonecutter remains an archive
orphan.

<!-- librarian-expansion:54 -->

Harbour expansion 54 (native 40285, 2026-09-07, same
`fluffos` / `Mud@2026`, do not redo docks, inn/office,
towers, Westway look-ats, westenter, outside1–32,
palplace1–6, mainsouth1 Sarykan, south/mainroad1–11,
parkroad1–6, parkenter, Tali/Kyrie, eastroad stubs,
garden1–4, northroad, mainsouth1↔outside9,
councilroad2–4 + councilenter, templeroad1–3 +
cparch, libraryenter, wsmithroad1–2, adventurerguild,
cityinfo office, citypark1–2, bakery, or
flower-shop look-ats):

- South of already-live citypark2 → Citypark
  entrance (sandstone gate / reliefs / rusty
  hinges / neglected houses / cloth-covered
  windows). Archive `which quite surprising` on
  birds. `south` refuses (`You cannot go that
  way.`; no SIL_PARK). `enter park` / `leave city`
  not wired (`What?`). North back works.
- `score` persist. Reconnect still lands on the docks.

This-boot live `libs/aoh/log/debug.log` (fd 3, PID 3217409
BOOT_MARKER55 aoh-cityenter): no new lines after the
marker. Catch this walk: empty after the marker.

**Not published** (`wasm_status: partial`). Do not flip to
`playable` on this harbour walk. `look at menu`,
`look at candles`, `look at cabins`, `look at tiles`,
and tailor/bakery/wine/flower `sign`s are flavour —
buy/drink, mail, deposit, combat, `enter palace`,
`enter hall`, `enter temple`, `enter shop`,
`enter park`, `touch statue`, and tower interiors
are not claimed.
Next aoh slice: `palenter` look-ats (do not wire
`enter palace` / throneroom). Do not load
`SIL_PARK` interiors, `xal_temple`, weaponsmith,
or mistralhouse this next leftover unless that is
the assigned batch. West fields / south bridge are
not in the snapshot. Stonecutter remains an archive
orphan.

<!-- librarian-expansion:55 -->

Harbour expansion 55 (native 40285, 2026-09-07, same
`fluffos` / `Mud@2026`, do not redo docks, inn/office,
towers, Westway look-ats, westenter, outside1–32,
palplace1–6, mainsouth1 Sarykan, south/mainroad1–11,
parkroad1–6, parkenter, Tali/Kyrie, eastroad stubs,
garden1–4, northroad, mainsouth1↔outside9,
councilroad2–4 + councilenter, templeroad1–3 +
cparch, libraryenter, wsmithroad1–2, adventurerguild,
cityinfo office, citypark1–2, cityenter, bakery, or
flower-shop look-ats):

- South of already-live mainroad11 → southern gates
  (archive `This are`; ivy / city wall / citywall
  look-ats). `climb ivy` / `climb wall` not wired
  (`What?`).
- South → road toward the river (layout stub).
- South → road before the bridge (layout stub).
- South → road with windmill mention. `west` refuses
  (unfinished fields). `look at windmill` nothing
  special.
- South → On a road south (archive `*No details yet,
  room only layouted.`). `south` refuses (no bridge
  / forest). North back works.
- `score` persist. Reconnect still lands on the docks.

This-boot live `libs/aoh/log/debug.log` (fd 3, PID 3245111
BOOT_MARKER56 aoh-southgate-wilderness): no new lines
after the marker. Catch this walk: empty after the
marker.

**Not published** (`wasm_status: partial`). Do not flip to
`playable` on this harbour walk. `look at menu`,
`look at candles`, `look at cabins`, `look at tiles`,
and tailor/bakery/wine/flower `sign`s are flavour —
buy/drink, mail, deposit, combat, `enter palace`,
`enter hall`, `enter temple`, `enter shop`,
`enter park`, `climb ivy`, `touch statue`, and
tower interiors are not claimed.
Next aoh slice: `paleast1` + `palwest1` hall stubs
east/west of already-live `palenter` (look-ats
only; do not load throneroom or pal*2+). Do not
load `SIL_PARK` interiors, `xal_temple`,
weaponsmith, or mistralhouse this next leftover
unless that is the assigned batch. West fields /
south bridge are not in the snapshot. Stonecutter
remains an archive orphan.

<!-- librarian-expansion:56 -->

Harbour expansion 56 (native 40285, 2026-09-07, same
`fluffos` / `Mud@2026`, do not redo docks, inn/office,
towers, Westway look-ats, westenter, outside1–32,
palplace1–6, mainsouth1 Sarykan, south/mainroad1–11,
parkroad1–6, parkenter, Tali/Kyrie, eastroad stubs,
garden1–4, northroad, mainsouth1↔outside9,
councilroad2–4 + councilenter, templeroad1–3 +
cparch, libraryenter, wsmithroad1–2, adventurerguild,
cityinfo office, citypark1–2, cityenter, southgate
chain, bakery, or flower-shop look-ats):

- North of already-live palplace5 → A hall in the
  palace (archive stub; no AddDetail). `look at hall`
  / `doors` / `archways` / `throneroom` / `wings`
  nothing special. `enter throneroom` / `leave palace`
  not wired (`What?`). `north` / `east` / `west`
  refuse (`You cannot go that way.`). South back
  works.
- North of already-live whealer1 → The house of the
  healer (`cannisters` / `linaments` / `contruction`
  / missing space before `crush`). `look at herbs` /
  `roots` / `labels` / `table` / `pestle` / `mortar` /
  `shelves` / `trivet` / `hearth` / `soup` / `sign`
  (100/300/500 copper day-default). `drink soup` /
  `taste brew` / `leave healer` not wired (`What?`).
  `north` refuses. South back works.
- `score` persist. Reconnect still lands on the docks.

This-boot live `libs/aoh/log/debug.log` (fd 3, PID 3276642
BOOT_MARKER57 aoh-palenter-whealer): no new lines after
the marker. Catch this walk: empty after the marker.

**Not published** (`wasm_status: partial`). Do not flip to
`playable` on this harbour walk. `look at menu`,
`look at candles`, `look at cabins`, `look at tiles`,
and tailor/bakery/wine/flower `sign`s are flavour —
buy/drink, mail, deposit, combat, `enter palace`,
`enter hall`, `enter temple`, `enter shop`,
`enter park`, `climb ivy`, `touch statue`,
`drink soup`, and tower interiors are not claimed.
Next aoh slice: `SIL_PARK` `parkenter` look-ats
south of already-live `cityenter` (or west of
south/`parkenter`; look-ats only, no snake pit).
Do not load `xal_temple`, weaponsmith, mistralhouse,
throneroom, or pal*2+ this next leftover unless
that is the assigned batch. West fields / south
bridge are not in the snapshot. Stonecutter remains
an archive orphan.

<!-- librarian-expansion:57 -->

Harbour expansion 57 (native 40285, 2026-09-07, same
`fluffos` / `Mud@2026`, do not redo docks, inn/office
look-ats, towers, Westway look-ats, westenter,
outside1–32, palplace1–6, mainsouth1 Sarykan,
south/mainroad1–11, parkroad1–6, parkenter, Tali/Kyrie,
eastroad stubs, garden1–4, northroad,
mainsouth1↔outside9, councilroad2–4 + councilenter,
templeroad1–3 + cparch, libraryenter, wsmithroad1–2,
adventurerguild, cityinfo office, citypark1–2,
cityenter, southgate chain, palenter hall stub,
whealer house, bakery, or flower-shop look-ats):

- East of already-live palenter → east-wing hall
  (archive `seems to glance` / `you.The walls` /
  `podestal`). `look at guards` / `tapestries` /
  `podestal` nothing special. `east` refuses
  (no pal*2+). West back works.
- West of already-live palenter → west-wing hall
  (archive `seems to glance` / `podestal`).
  `look at guards` / `podestal` nothing special.
  `west` refuses (no pal*2+). East back works.
  `north` / `enter throneroom` still refuse.
- Up from already-live harbourmaster office →
  upstairs loft. `look at telescope` / `spy glass` /
  `tube` / `brass telescope` static brass-tube
  description. `look through telescope` nothing
  special. `north` refuses. Down back works.
- `score` persist. Reconnect still lands on the docks.

This-boot live `libs/aoh/log/debug.log` (fd 3, PID 3303416
BOOT_MARKER58 aoh-paleast-palwest-loft): no new lines
after the marker. Catch this walk: empty after the
marker.

**Not published** (`wasm_status: partial`). Do not flip to
`playable` on this harbour walk. `look at menu`,
`look at candles`, `look at cabins`, `look at tiles`,
and tailor/bakery/wine/flower `sign`s are flavour —
buy/drink, mail, deposit, combat, `enter palace`,
`enter hall`, `enter temple`, `enter shop`,
`enter park`, `climb ivy`, `touch statue`,
`drink soup`, `look through` telescope, and tower
interiors are not claimed.
Next aoh slice: `SIL_PARK` `southentrance` look-ats
west of already-live south/`parkenter` (look-ats
only; no snake pit / forest_room1 combat). Do not
load `xal_temple`, weaponsmith, mistralhouse,
throneroom, or pal*2+ this next leftover unless
that is the assigned batch. West fields / south
bridge are not in the snapshot. Stonecutter remains
an archive orphan.

<!-- librarian-expansion:58 -->

Harbour expansion 58 (native 40285, 2026-09-07, same
`fluffos` / `Mud@2026`, do not redo docks, inn/office
look-ats, towers, Westway look-ats, westenter,
outside1–32, palplace1–6, mainsouth1 Sarykan,
south/mainroad1–11, parkroad1–6, south/parkenter,
Tali/Kyrie, eastroad stubs, garden1–4, northroad,
mainsouth1↔outside9, councilroad2–4 + councilenter,
templeroad1–3 + cparch, libraryenter, wsmithroad1–2,
adventurerguild, cityinfo office, citypark1–2,
cityenter look-ats, southgate chain, palenter,
paleast1, palwest1, whealer, harbourmaster loft,
bakery, or flower-shop look-ats):

- South of already-live cityenter → Citypark
  entrance (forestal border; archive `it's wooden
  surface`). `look at sign` / `important sign` /
  `words` / `text` show the wimpy/kill-rabbit
  inscription. `leave park` / `enter city` /
  `search ground` / `enter park` not wired
  (`What?`).
- East → Before a small forest (archive stub).
  `look at forest` / `path` / `trees` / `wall`
  nothing special. `enter forest` / `enter park`
  not wired (`What?`). `east` refuses (no
  forest_room1 / snake pit). West and north back
  work.
- `score` persist. Reconnect still lands on the docks.

This-boot live `libs/aoh/log/debug.log` (fd 3, PID 3331600
BOOT_MARKER59 aoh-silpark-parkenter): no new lines after
the marker. Catch this walk: empty after the marker.

**Not published** (`wasm_status: partial`). Do not flip to
`playable` on this harbour walk. `look at menu`,
`look at candles`, `look at cabins`, `look at tiles`,
and tailor/bakery/wine/flower `sign`s are flavour —
buy/drink, mail, deposit, combat, `enter palace`,
`enter hall`, `enter temple`, `enter shop`,
`enter park`, `climb ivy`, `touch statue`,
`drink soup`, `look through` telescope, and tower
interiors are not claimed.
Next aoh slice: `SIL_PARK` `southentrance` look-ats
west of already-live south/`parkenter` (look-ats
only; no snake pit / forest_room1 combat). Do not
load `xal_temple`, weaponsmith, mistralhouse,
throneroom, or pal*2+ this next leftover unless
that is the assigned batch. West fields / south
bridge are not in the snapshot. Stonecutter remains
an archive orphan.

## 5. WASM

Verified 2026-09-05 via `scripts/wasm_client.js`: register/reconnect fluffos, look/score/quit.

**Not published** on mudlibs.fluffos.info (`wasm_status: partial`).
Catalog overlay Void/workshop is not a world §10.7. Flip to
`playable` only after a Strategy A port of the OSB/AOH world
and a shop/combat/guild deep-test.
