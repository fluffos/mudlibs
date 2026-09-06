# StickLib (sticklib) — porting notes

Source: git clone https://github.com/StickMUD/StickLib (commit a0750273104c49d7d506d92f232b221b64577853, cloned 2026-09-05); repo root is the mudlib. Converted 2026-09-05. Config name `StickLib`.
Slug `sticklib`, number **977**, port **40286**.

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
global include `"/catalog/auto.h"`, port **40286**,
`lazy resets : 1`.

Catalog overlay (questmud §7.158 cluster):

- `/catalog/master.lpc` — `get_root_uid`/`get_bb_uid`, `creator_file`
  always returns string `"BACKBONE"`, `valid_read` includes
  `load_object`/`recompile_object`/`include`/`restore_object`,
  `valid_override` returns 1, `error_handler` → `/log/catch`
- `/catalog/simul_efun.lpc` — thin `cat`/`log_file`/`exists`
- `/catalog/login.lpc`, `/catalog/player.lpc` — name/password → Void
- `/catalog/void.lpc`, `/catalog/workshop.lpc` — look/score/quit surface

## 3. Live-verified (native, port 40286)

Create `fluffos` / `Mud@2026`. Lands in The Void; `look` / `score` /
`north` (workshop) / `south` / `quit`. Reconnect after cold restart
reloads `data/f/fluffos.o`.

## 深度功能测试（§10.7, 2026-09-05）

Catalog overlay only — the StickMUD LDMud 3.x world is not loaded.
Organic `fluffos` / `Mud@2026` on native 40286: Void `look` / `score`
(level 1, hp 20/20) / `inventory` / `north` workshop / `south` /
`quit` persist. Reconnect: Void `look` / `score` / `quit`. Shop,
combat, guild, death: **N/A** (needs a real LDMud driver).

Logs this boot (PID started 20:09:19, live fd
`libs/sticklib/log/debug.log`): stdout + debug.log clean.
`work/log/catch` proven live with a one-shot `catchprobe`
(`CAUGHT /catalog/player.lpc *catch-path-probe`) then reverted;
play itself left no other catch lines.

## 6. Full dialect port (Strategy A, 2026-09-05)

Catalog Void/workshop is no longer the live world. User asked for
the real StickMUD, not a demo skeleton.

What loads now:

- `/catalog/login` still handles name/password. `/catalog/player`
  `enter_world()` moves into `/room/church` (Temple yard, Newbie
  York).
- `/lib/room` rewritten as a FluffOS Stick-API subset: 1-arg
  `set(NO_PK)`, `add_exit`/`add_item`/`add_permanent`,
  `command_driver` → `call_other`. Original LDMud room (closures,
  3-arg implode, PEACE_D/PARTY_D) is `/lib/room_ldmud.lpc`.
- `/catalog/master` `compile_object` delegates to
  `/areas/tristeza/virtual/server` so `S7_6` etc. clone
  `tristeza_room` (FluffOS renames the clone to the virtual path).
- Church `#'query_door_desc` / clock closures → function-name
  strings. Elevator `call_other` uses an explicit path (FluffOS
  parsed `(int)AREA+"rooms/elevator"->fn` as `'rooms/elevator'`).
- `mud_name.h` no longer redefines FluffOS's predefined `MUD_NAME`.
  Simul shims: `member`/`m_delete`/`m_indices`/3-arg `implode`/
  2-arg `move_object`/`nature()`/`notify_fail` returns 0.

Live walk (native 40286, 2026-09-05, organic `fluffos` /
`Mud@2026`):

- Temple yard look; `look at pit` / `look at door` (closed) /
  `look at clock` (midday fallback); `score`; `pray` ("No sense
  praying unless you're dead.").
- East → Hall of Races (sign look). West back to the yard.
- South → virtual Market Square (S7_6). West → S6_6. West →
  Common Shop. `read writing` shows buy/sell/list/value. `list`
  is "Shop doesn't seem to be open" (shopkeeper is `/lib/npc` →
  `/lib/living` `closure HitFunc`, does not compile).
- Adventurers' Guild (east from physical S8_6) does not load:
  `/lib/guild` `closure guildInit` plus `#'make_noise` in
  `adv_guild.lpc`.

This-boot live `libs/sticklib/log/debug.log` (fd) + driver
stdout clean of uncaught play errors after the elevator-path
fix. `work/log/catch` this boot: expected CAUGHT on
`/lib/treasure` (saint/finger), `/lib/living` (shopkeeper /
street NPCs), `/bin/daemons/peaced`, `/bin/daemons/nature_d`,
elevator. Older catch lines above those are from the compile
iterate earlier the same evening.

**Not published** (`wasm_status: partial`). Flip to `playable`
only after shop buy + combat + guild actually work.

## 4. What is not ported yet

`/lib/living`, `/lib/npc`, `/lib/guild`, `/lib/treasure` still
use the `closure` type. Elevator, PEACE_D, NATURE_D, and
`#'make_noise` in the Adventurers' Guild. Catalog body: inventory
does not persist usefully; gold on the saved `fluffos` account
is 0 from the old Void overlay. Next slice: living/npc so the
shopkeeper clones and `list`/`buy` work, then guild + combat.
