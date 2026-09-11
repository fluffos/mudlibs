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
  2-arg `move_object`/`nature()`/`notify_fail` returns 0 /
  `symbol_function` / `funcall` leaves literal strings alone.
- `/lib/living`, `/lib/npc`, `/lib/group_npc` are FluffOS subsets
  (originals `*_ldmud.lpc`). `/lib/treasure` keeps its source with
  `closure` → `mixed`. Room `create()` calls `reset_room()` so
  FluffOS lazy reset still stocks shops.

Live walk (native 40286, 2026-09-05, organic `fluffos` /
`Mud@2026`):

- Temple yard look; `look at pit` / `look at door` (closed) /
  `look at clock` (midday fallback); `score`; `pray` ("No sense
  praying unless you're dead.").
- East → Hall of Races (sign look). West back to the yard.
- South → virtual Market Square (S7_6). West → S6_6. West →
  Common Shop. Named shopkeeper present (Culdaff / Falo /
  Nallihan). `list` shows torches and torches of darkness at
  82 gold. `buy torch` → inventory "A torch" / "A torch of
  darkness", gold 200→118→36.
- East from physical S8_6 → Adventurers' Guild loads
  (`8a9558ad094` + `a6e16773d6a`). Sign lists cost/advance/
  list. `cost`: "You still need 1014 experience points for
  next level" (no player-visible ERROR). User graph present.
  `/lib/guild` uses `mixed guildInit`; `#'make_noise` is
  `call_out("make_noise", …)`.
- QUEST_D (`ac61209dffb`): LDMud multi-value mappings rewritten
  as mapping-of-arrays (original `questd_ldmud.lpc`). `quests`
  lists the enabled set. `qp_for_level` still returns 0
  (upstream Kieve stub), so advance is XP-only.
- Eat at Joe's LIVE (`9316443fe04` + `aa89abf6bca`): church →
  S7_6 → S6_6 south → Main Street → Dragon Street north →
  Ladywell west → Joe's. Joe stays in the restaurant (no
  city wander). After ~1s he swallows the player; stomach
  awards QUEST_EAT_AT_JOES (`M6a`). `score` shows `Quests:
  M6a`. Reconnect persists. Guild `quests` drops from 14 to
  13 (Eat at Joe's gone). Stomach has no exits (upstream).
- Well maze LIVE (`6bbecdc51dd`): S7_7 `#'read_file` map
  lambda → `map_text()`. Harry boot wrapped in catch (he
  actually spawned). Maze `exit_num` fixed to 0 so north
  advances. Church → S7_6 south → well square → down →
  north ×4 → End of maze awards QUEST_M3. `score` `Quests:
  M6a, M3`. Reconnect persist. Guild list 12 (Maze Under
  Well gone). Leather armour cloned at the end.
- Beer to Bum LIVE (`f725c02fc45`): church → S7_6 south ×3
  → S7_9 west Potato-Nosed Ogre. Bartender present. `buy
  beer` (48 gold) → inventory "Bottle of Ogre IV beer".
  East, north ×2 to well square, west ×7 to West Gate.
  Bum spawned (archive never placed him; Strategy A puts
  him at `gate_west`). `give beer to bum` awards QUEST_M2.
  `score` `Quests: M6a, M3, M2`. Gold 200→152. Reconnect
  persist. Guild `quests` 11 (Beer to Bum gone). Thin
  `/lib/drink` (original `drink_ldmud.lpc`); `/lib/pub`
  empty `reset_pub()`; nature-null pub hours; catalog
  get/give. City guards still fail to compile (private
  `gender` / `Pronoun` / `set_keep_hb`) — catch-wrapped.
- Combat LIVE (`3235caa3a99`): church → S7_6 south → well
  square (did **not** go down the well). `kill harry` —
  player hits, Harry hits back (5+3 dmg), Harry dies, 70
  XP. `score` hp 12/20 exp 70. Look: Harry gone. Reconnect
  persist hp + exp. Thin `/lib/living` attack/die/heart_beat
  (original still `living_ldmud.lpc` with HitFunc closures).
  Catalog `kill`/`hit` resolves a short fight. Stray dogs
  are a 10% street wander; S6_7 had none this boot.

This-boot live `libs/sticklib/log/debug.log` (fd, PID 1662870
BOOT_MARKER16 sticklib-combat): living + catalog player
compiled. Catch this walk: expected PEACE_D only.

Guild advance LIVE (`0cf82e040d1` + `fc60c6c304d` +
`38d9b3c591c`, native 40286, 2026-09-10): catalog
`set_level`/`set_title` persist (they were no-ops;
`query_level` always returned 1). Harry respawns on
re-enter of S7_7. Temple yard restores HP and unghosts
(login compile needed a `remove_ghost` prototype).
Organic `fluffos`: 13× `kill harry` with church rest
between fights (70 XP each; start 210 → 1120). Guild
`cost`: "enough experience to advance a level".
`advance level` fanfare; score `Fluffos the Mostly
Harmless (level 2)` exp 1120. Reconnect persist.
`qp_for_level` is still 0 (XP-only).

**Published** (`wasm_status: playable`) after WASM
§10.7 of shop / combat / guild (leftover 632,
2026-09-10).

## 4. What is not ported yet

Elevator, PEACE_D, NATURE_D. Trashcan toss (`foreach :`).
Full LDMud HitFunc / weapon closures (thin living is enough
to kill). Bulletin board extra inherit. City guards. Joe's
LDMud tell_here format tokens still print raw. Catalog
inventory persist is still save fields only.

## WASM §10.7 (2026-09-10, leftover 632)

`scripts/wasm_client.js` against `build-wasm`
(`fluffos 20260830`), organic `fluffos` / `Mud@2026`
(native leftover 629 save: level 2 Mostly Harmless,
exp 1120, gold 152, quests M6a/M3/M2):

- Temple yard look / score.
- South → S7_6 west ×2 Common Shop. `list` / `buy
  torch` (gold 152→70).
- East ×2 south → S7_7. `kill harry`: Harry dies,
  exp 1190, hp 11/20.
- East ×2 Adventurers' Guild. `cost`: "You still
  need 332 experience points for next level."
- North to the yard: "The temple yard's peace
  restores you."
- Quit / WASM reconnect: level 2, exp 1190 persist.
  Gold 200 (catalog bump when purse < 80). Inventory
  empty (catalog save fields only — same as native).

Expected compile noise (already documented, not
player-visible): PEACE_D `filter_objects`, trashcan
`foreach :`, bboard `#'`. Do not redo native harry
farm or WASM shop/combat/guild. Remaining partials:
aoh shop/combat (do not invent rooms), simud (no
`world.obj`), morgengrauen (no `/d/ebene`), acme
(no world).
