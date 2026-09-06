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

Still later: real `/obj/player` logon, remaining `#'` in
`obj/player.lpc` / `obj/chest.lpc` / `obj/login/*`, mine/south
forest live §10.7. Do not treat the old Void/workshop §10.7 as a
world pass.

## 4. What is not ported yet

Real `/obj/player` telopt login, mine/south-forest depth, and any
file that still uses `#'` (`obj/player.lpc`, `obj/chest.lpc`,
`obj/login/*`). The 2.4.5 village itself (church → green → shop /
Harry / Adventurers' Guild) is what catalog login loads.

## 5. WASM

Verified 2026-09-05 via `scripts/wasm_client.js`: register/reconnect fluffos, look/score/quit.
