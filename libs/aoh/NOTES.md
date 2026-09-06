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
- `/d/silvere/rooms/west/cityinfo1` — Park Lane
- `/d/silvere/rooms/west/whealer1` — Before the house of the healer

inn buy/drink, harbourmaster bell NPC, tower interiors,
westroad5 / sell-shop buy, and healer/elder interiors
are not loaded.

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

**Not published** (`wasm_status: partial`). Do not flip to
`playable` on this harbour walk. `look at menu` and
`look at candles` are flavour — buy/drink, combat, and
tower interiors are not claimed. Next aoh slice: westroad5
/ sell-shop if expanding.

## 5. WASM

Verified 2026-09-05 via `scripts/wasm_client.js`: register/reconnect fluffos, look/score/quit.

**Not published** on mudlibs.fluffos.info (`wasm_status: partial`).
Catalog overlay Void/workshop is not a world §10.7. Flip to
`playable` only after a Strategy A port of the OSB/AOH world
and a shop/combat/guild deep-test.
