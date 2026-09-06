# MorgenGrauen (morgengrauen) — porting notes

Source: git clone https://github.com/MorgenGrauen/mg-mudlib (commit a178b88a9cac64480a9475f72a96cd4c183e64c7, cloned 2026-09-05); repo root is the mudlib. Converted 2026-09-05. Config name `MorgenGrauen`.
Slug `morgengrauen`, number **974**, port **40283**.

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
global include `"/catalog/auto.h"`, port **40283**,
`lazy resets : 1`.

Catalog overlay (questmud §7.158 cluster):

- `/catalog/master.lpc` — `get_root_uid`/`get_bb_uid`, `creator_file`
  always returns string `"BACKBONE"`, `valid_read` includes
  `load_object`/`recompile_object`/`include`/`restore_object`,
  `valid_override` returns 1, `error_handler` → `/log/catch`
- `/catalog/simul_efun.lpc` — thin `cat`/`log_file`/`exists`
- `/catalog/login.lpc`, `/catalog/player.lpc` — name/password →
  `/gilden/abenteurer` (Strategy A; Void fallback if load fails)
- `/catalog/void.lpc`, `/catalog/workshop.lpc` — leftover overlay rooms

## 3. Live-verified (native, port 40283)

Create `fluffos` / `Mud@2026`. Lands in The Void; `look` / `score` /
`north` (workshop) / `south` / `quit`. Reconnect after cold restart
reloads `data/f/fluffos.o`.

## 深度功能测试（§10.7, 2026-09-05）

Catalog overlay only — the German LDMud 3.x world is not loaded.
Organic `fluffos` / `Mud@2026` on native 40283: Void `look` / `score`
(level 1, hp 20/20) / `inventory` / `north` workshop / `south` /
`quit` persist. Reconnect: Void `look` / `score` / `quit`. Shop,
combat, guild, death: **N/A** (needs a real LDMud driver).

Logs this boot (PID started 20:08:07, live fd
`libs/morgengrauen/log/debug.log`): stdout + debug.log clean.
`work/log/catch` proven live with a one-shot `catchprobe`
(`CAUGHT /catalog/player.lpc *catch-path-probe`) then reverted;
play itself left no other catch lines.

## 4. What is not ported yet

Full LDMud world (`/d/ebene` Port Vain and other domains live in
git submodules that are not in this snapshot), guild commands
(`liste` / `kosten` / `lerne`), shop, combat, protocol stacks,
OSB/MG kernel daemons. 840 `#'` in 180 files — do not attempt a
mechanical `/std` rewrite this slice. `/room/church` is a leftover
English 2.4.5 church, not the live German spawn.

## 6. Full dialect port (Strategy A, 2026-09-06)

Catalog Void/workshop is no longer the live start. Established
players in the archive start at `/gilden/abenteurer` ("Die
beruehmte Abenteurergilde"; `std/player/base.lpc` P_START_HOME).
Newbies go to `/room/welcome/<name>` then a tutorial hut — that
path is not loaded here.

`/std/room` cannot load on FluffOS (LDMud inherit + `#'`).
Strategy A keeps the authentic path and German text as thin
FluffOS rooms; original guild object is
`/gilden/abenteurer_ldmud.lpc`.

- `/gilden/abenteurer` — guild hall (login)
- `/d/ebene/room/PortVain/po_haf1` — Hafenstrasse (north). Domain
  files.ebene is not in the snapshot; text reconstructed from the
  guild's own Hafenstrasse / Port Vain details so the exit walks.
- `/p/verein/room/buero` — Foerderverein office (up)

`/catalog/login` still handles name/password. `/catalog/player`
`enter_world()` moves into the guild (fallback Void if load fails).

Live walk (native 40283, 2026-09-06, organic `fluffos` /
`Mud@2026`):

- Lands in Die beruehmte Abenteurergilde. `look at tuer` /
  `dielen` / `uhr`.
- North → Hafenstrasse von Port Vain. South back. Up → Buero
  des Foerdervereins. Down back.
- `score` level 1, hp 20/20. Quit persist. Reconnect lands in
  the guild again.

This-boot live `libs/morgengrauen/log/debug.log` (fd 3, PID
1724270 BOOT_MARKER1 mg-abenteurer): start rooms compiled, no
new lines after the marker. Catch this walk: empty after the
marker (older `*catch-path-probe` line is from 2026-09-05).

**Not published** (`wasm_status: partial`). Do not flip to
`playable` on this guild-hall walk. Shop / combat / `liste` /
`lerne` are not claimed. Next MG slice needs domain files that
are not in the snapshot, or start aoh.

## 5. WASM

Verified 2026-09-05 via `scripts/wasm_client.js`: register/reconnect fluffos, look/score/quit.

**Not published** on mudlibs.fluffos.info (`wasm_status: partial`).
Catalog overlay Void/workshop is not a world §10.7. Flip to
`playable` only after a Strategy A port of the MorgenGrauen world
and a shop/combat/guild deep-test.
