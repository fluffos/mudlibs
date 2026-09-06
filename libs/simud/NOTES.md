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

## 4. What is not ported

Full LDMud world, guilds, protocol stacks, and OSB/MG kernel daemons.
Those remain in the tree for archaeology; booting them needs a real
LDMud driver.
