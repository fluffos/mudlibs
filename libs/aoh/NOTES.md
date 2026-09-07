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
- `/d/silvere/rooms/harbour/harbourmaster` — office
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
- `/d/silvere/rooms/center/outside9` — Avenue of the Palace, entrance fork (look only)
- `/d/silvere/rooms/center/palplace1` — The palace square, west side (look only)
- `/d/silvere/rooms/center/palplace4` — The place before the palace (look only)
- `/d/silvere/rooms/center/palplace5` — At the entrance into the palace (look only)
- `/d/silvere/rooms/center/palplace2` — The palace square fountain (look only)
- `/d/silvere/rooms/center/mainsouth1` — Avenue of the Palace, Sarykan statue (look only)
- `/d/silvere/rooms/south/mainroad1` — On a road at Silvere (archive stub)
- `/d/silvere/rooms/center/palplace3` — The place before the palace, east wing (look only)
- `/d/silvere/rooms/center/palplace6` — The place before the palace, east-wing walls (look only)
- `/d/silvere/rooms/west/flowershop` — Jehane's Flowers (look only)
- `/d/silvere/rooms/west/libraryroad1` — Guild Street / library road
- `/d/silvere/rooms/west/libraryroad2` — library road west (stub look-ats)
- `/d/silvere/rooms/west/wineshop` — Chez Brigan (look only)
- `/d/silvere/rooms/west/bakery` — Eldranna's Bake Shoppe (look only)
- `/d/silvere/rooms/west/tailor` — Couture Celimarith (look only)
- `/d/silvere/rooms/west/councilroad1` — Elrimand Road (bakery look-at)
- `/d/silvere/rooms/west/fishmonger` — Feridwyn's Seafood (look only)
- `/d/silvere/rooms/west/wpostroad1` — lane to the post office
- `/d/silvere/rooms/west/wpostroad2` — Counting House arch
- `/d/silvere/rooms/west/wpostoffice` — post office (look only)
- `/d/silvere/rooms/west/wbank` — Counting House foyer (look only)
- `/d/silvere/rooms/west/cityinfo1` — Park Lane
- `/d/silvere/rooms/west/whealer1` — Before the house of the healer

inn buy/drink, harbourmaster bell NPC, tower interiors,
palace enter (`palenter` / `enter palace` not wired),
outside10, further south-town
(`/d/silvere/rooms/south/mainroad2` is still the LDMud
SILBASEROOM original), statue touch/helmet, further
council road / mail / bank deposit / Caves of Parch,
shop buy, and healer/elder interiors are not loaded.
The council hall, library, and adventurers guild
interiors are archive stubs (no details).

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

**Not published** (`wasm_status: partial`). Do not flip to
`playable` on this harbour walk. `look at menu`,
`look at candles`, `look at cabins`, `look at tiles`,
and tailor/bakery/wine/flower `sign`s are flavour —
buy/drink, mail, deposit, combat, `enter palace`,
`touch statue`, and tower interiors are not claimed.
Next aoh slice: Road at the palace south of the
east wing (`/d/silvere/rooms/center/outside10`) if
expanding.

## 5. WASM

Verified 2026-09-05 via `scripts/wasm_client.js`: register/reconnect fluffos, look/score/quit.

**Not published** on mudlibs.fluffos.info (`wasm_status: partial`).
Catalog overlay Void/workshop is not a world §10.7. Flip to
`playable` only after a Strategy A port of the OSB/AOH world
and a shop/combat/guild deep-test.
