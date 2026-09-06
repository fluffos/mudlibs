# Age of Elements (ageofelements) — porting notes

Source: git clone https://github.com/age-of-elements/age-of-elements (commit 4e5cae45d0804f23a1cecbef577b5bcdee5a53cf, cloned 2026-09-05); repo root is the mudlib. Converted 2026-09-05. Config name `Age of Elements`.
Slug `ageofelements`, number **975**, port **40284**.

**This is an LDMud → FluffOS conversion.** Discovery triage normally
drops LDMud-lineage libs; this onboard is an explicit exception in the
same family as `questmud` / `acme` (AGENTS.md §7.158).

This collection’s copy is a snapshot, not a live mirror. Do not onboard
the same upstream repo again.

## 0. Layout

Repo root **is** the mudlib. `raw/` is gitignored. Original LDMud master
preserved as `/obj/master_ldmud.lpc`.

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
global include `"/catalog/auto.h"`, port **40284**,
`lazy resets : 1`.

Catalog overlay (questmud §7.158 cluster):

- `/catalog/master.lpc` — `get_root_uid`/`get_bb_uid`, `creator_file`
  always returns string `"BACKBONE"`, `valid_read` includes
  `load_object`/`recompile_object`/`include`/`restore_object`,
  `valid_override` returns 1, `error_handler` → `/log/catch`
- `/catalog/simul_efun.lpc` — thin `cat`/`log_file`/`exists`
- `/catalog/login.lpc`, `/catalog/player.lpc` — name/password → Void
- `/catalog/void.lpc`, `/catalog/workshop.lpc` — look/score/quit surface

## 3. Live-verified (native, port 40284)

Create `fluffos` / `Mud@2026`. Lands in The Void; `look` / `score` /
`north` (workshop) / `south` / `quit`. Reconnect after cold restart
reloads `data/f/fluffos.o`.

## 深度功能测试（§10.7, 2026-09-05）

Catalog overlay only — the LDMud 3.x world is not loaded. Organic
`fluffos` / `Mud@2026` on native 40284: Void `look` / `score`
(level 1, hp 20/20) / `inventory` / `north` workshop / `south` /
`quit` persist. Reconnect: Void `look` / `score` / `quit`. Shop,
combat, guild, death: **N/A** (needs a real LDMud driver).

Logs this boot (PID started 20:08:32, live fd
`libs/ageofelements/log/debug.log`): stdout + debug.log clean.
`work/log/catch` proven live with a one-shot `catchprobe`
(`CAUGHT /catalog/player.lpc *catch-path-probe`) then reverted;
play itself left no other catch lines.

## 6. Full dialect port (Strategy A, 2026-09-05)

Catalog Void/workshop is no longer the live world. User asked for
the real game, not a demo skeleton.

What loads now:

- `/catalog/login` still handles name/password (real `/obj/player`
  telopt/`INPUT_PROMPT`/`#'gmcp_test` is a later slice).
- `/catalog/player` inherits `/obj/living` and `enter_world()` moves
  into `/room/church`.
- `/lib/room` rewritten for FluffOS: no `#'` / `symbol_function` /
  `funcall` / LDMud `foreach (:)`. Exits and room verbs go through
  `command_driver` → `call_other`.
- Village rooms that stored closures (`church`, `well`, `wiz_hall`,
  `attic`, `elevator`, `bank`, `bankroom`, `inn`) now store function
  name strings.
- `/catalog/simul_efun` shims `member`, `m_delete`, `m_indices`,
  `widthof`, `object_name`, 2-arg `move_object`, `process_mxp`,
  `deep_copy`. `auto.h` defines `status` and `_efun_move_to`.

Live village (native 40284, 2026-09-05, organic `fluffos` /
`Mud@2026`): church look/score → south green → track → shop road
(Harry present) → shop `list`/`buy torch`/`i` → Adventurers' Guild
`cost` (1675 gold to level 2). Combat: `kill harry` → death → ghost
→ church `pray` revive. Quit persist. This-boot driver stdout +
live `log/debug.log` (fd) + `work/log/catch` clean (older catch
lines are from the compile-iterate earlier the same evening).

Still later: real `/obj/player` telopt logon, remaining `#'` in
`obj/player.lpc` / `obj/chest.lpc` / `obj/login/*`. Do not treat the
old Void/workshop §10.7 as a world pass.

Mine / south-forest / remaining village (2026-09-05, same native
40284, organic `fluffos` / `Mud@2026`):

- Hump: `get stick`, `get coins`. Yard: knife + beggar. Narrow
  alley well `down`/`up`. Bank: guard, counter closed for
  reconstruction (original text). Eastroad Inn: `look at menu`,
  `buy 1` commoner's meal (hp 10→14, gold 20→0).
- Plains west of the green → mountain pass → `/room/mine/tunnel`
  (lit entrance; `look at sign` / `look at pole` = mines closed
  for falling rock). Inner `room.h` tunnels are dark (`LIGHT` 0)
  but exits work.
- South forest: clearing west past the aggressive forest troll
  (level 9, original) → slope → deep forest → `sforst1`/`sforst2`
  old-style `add_action` rooms. Look/move work.
- Fix: FluffOS lazy `reset()` left `room.h` / `std.h` ONE/TWO/…
  EXIT rooms dark and exit-less (`dest_dir` unset → `What?`).
  `room/room.lpc` and the `std.h` macros now
  `call_other(this_object(), "reset", 0)` from `create()` (§7.158
  / §7.177 / §7.185). Catalog look falls back to `query_dest_dir()`
  and `id()`/`long(str)` so old rooms show exits and the mine sign.
- Catalog `drink_alcohol()` stub so inn beer does not throw.
  Carried items still do not persist across quit (catalog
  `save_object` only); real `/obj/player` later.

This-boot live `log/debug.log` (fd) + driver stdout + `work/log/catch`
(unchanged since 20:28; no new catch lines) clean of runtime errors.
`/obj/monster.lpc` unused-local compile warning only.

## 4. What is not ported yet

Real `/obj/player` telopt login and any file that still uses `#'`
(`obj/player.lpc`, `obj/chest.lpc`, `obj/login/*`). Inventory does
not persist across quit on the catalog body. The 2.4.5 village,
plains, mine, and south forest are what catalog login loads.

## 5. WASM

Overlay login was verified 2026-09-05 via `scripts/wasm_client.js`
(register/reconnect fluffos, look/score/quit). Same catalog login now
lands in the village church; WASM village not re-run this evening.

Listed `playable` only after the native village §10.7-shaped pass
(shop / Harry / pray / guild). Overlay-only LDMud siblings stay
`partial` and off the public site.
