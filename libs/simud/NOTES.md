# SIMud (simud) — porting notes

Source: git clone https://github.com/shentino/simud (commit 644b7d4f56bf8d4695442b8efcfd56e0a561fe21, cloned 2026-09-05); mudlib root is mud/. Converted 2026-09-05. Config name `SIMud`.
Slug `simud`, number **978**, port **40287**.

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
global include `"/catalog/auto.h"`, port **40287**,
`lazy resets : 1`.

Catalog overlay (questmud §7.158 cluster):

- `/catalog/master.lpc` — `get_root_uid`/`get_bb_uid`, `creator_file`
  always returns string `"BACKBONE"`, `valid_read` includes
  `load_object`/`recompile_object`/`include`/`restore_object`,
  `valid_override` returns 1, `error_handler` → `/log/catch`
- `/catalog/simul_efun.lpc` — thin `cat`/`log_file`/`exists`
- `/catalog/login.lpc`, `/catalog/player.lpc` — name/password → Void
- `/catalog/void.lpc`, `/catalog/workshop.lpc` — look/score/quit surface

## 3. Live-verified (native, port 40287)

Create `fluffos` / `Mud@2026`. Lands in The Void; `look` / `score` /
`north` (workshop) / `south` / `quit`. Reconnect after cold restart
reloads `data/f/fluffos.o`.

## 深度功能测试（§10.7, 2026-09-05）

Catalog overlay only — rooms/races/magic/economy under the mud/ tree
are not loaded. Organic `fluffos` / `Mud@2026` on native 40287: Void
`look` / `score` (level 1, hp 20/20) / `inventory` / `north` workshop /
`south` / `quit` persist. Reconnect: Void `look` / `score` / `quit`.
Shop, combat, guild, death: **N/A** (needs a real LDMud driver).

Logs this boot (PID started 20:09:43, live fd
`libs/simud/log/debug.log`): stdout + debug.log clean.
`work/log/catch` proven live with a one-shot `catchprobe`
(`CAUGHT /catalog/player.lpc *catch-path-probe`) then reverted;
play itself left no other catch lines.

## 6. Full dialect port (Strategy A, 2026-09-06)

Catalog Void/workshop is no longer the live start. User asked for
the real SIMud spawn, not a demo skeleton.

The archive spawn is `;ch;oldtown;temple;temple2` ("Temple of All
Gods"). SIMud's world is a saved object tree (`/world/world.obj`);
that dump is **not** in the git snapshot. Strategy A reconstructs
the spawn path as FluffOS rooms under `/world/start/`:

- `/world/start/temple2` — inner shrine (login)
- `/world/start/temple` — public hall
- `/world/start/oldtown` — street outside

`/catalog/login` still handles name/password. `/catalog/player`
`enter_world()` moves into `temple2` (fallback Void if load fails).

Live walk (native 40287, 2026-09-06, organic `fluffos` /
`Mud@2026`):

- Lands in Temple of All Gods. `look at altar`.
- North → temple hall. North → Oldtown street (further streets
  closed). South ×2 back to the shrine.
- `score` level 1, hp 20/20. Quit persist. Reconnect lands in
  the shrine again.

This-boot live `libs/simud/log/debug.log` (fd, PID 1693124
BOOT_MARKER1 simud-temple): start rooms compiled. Catch this
walk: empty after the marker.

**Not published** (`wasm_status: partial`). Flip to `playable`
only after a shop/combat/guild deep-test. The rest of Oldtown
cannot be loaded from archive files — it lived in world.obj.

## 4. What is not ported yet

Full LDMud world object tree (no `world.obj` in the snapshot),
guilds, protocol stacks, OSB/MG kernel daemons, shop, combat.
Original `/world/room` uses LDMud closures (`(: $1->… :)`).
Next simud slice: more Oldtown if we can reconstruct it, or
start morgengrauen Strategy A.
