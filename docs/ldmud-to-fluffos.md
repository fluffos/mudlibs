# Porting an LDMud mudlib to FluffOS (mudlibs.fluffos.info)

This collection targets [FluffOS](https://github.com/fluffos/fluffos).
Most archives are MudOS-lineage; **LDMud** is a different driver family.
Discovery triage usually drops LDMud unless someone explicitly wants a
port (see `AGENTS.md` §7.158 and the `questmud` / `acme` /
`morgengrauen` / `ageofelements` / `aoh` / `sticklib` / `simud` onboards).

Every onboarded LDMud lib must say clearly in `README.md`, `NOTES.md`,
and `meta.json` that it is an **LDMud → FluffOS conversion**.

## Choose a strategy

| Strategy | When | Examples |
|---|---|---|
| **A. Full dialect port** | Older LDMud / Amylaar-era lib; closures rare; you intend playable world content | `questmud` |
| **B. Catalog overlay** | Modern LDMud 3.x (`set_driver_hook`, `#'` / `unbound_lambda`, `virtual inherit`, MessageLib, XML cmds) — mechanical rewrite of the whole tree is not realistic | `acme`, `morgengrauen`, `ageofelements`, `aoh`, `sticklib`, `simud`, `sticklib`, `simud` |

Both strategies still run the normal extract → `convert_lib.sh` →
`config.fluffos` → numbering/`meta.json` pipeline from `AGENTS.md` §2.

## Shared mechanical steps

1. Clone or extract into `libs/<slug>/raw/` (gitignored).
2. Run `scripts/convert_lib.sh libs/<slug>/raw libs/<slug>/work UTF-8`
   (English/German sources are usually already UTF-8; Chinese LDMud is rare).
3. Assign the next free number/port; write `meta.json`, `README.md`,
   `NOTES.md`, `config.fluffos`.
4. Mark lineage in copy: title or first paragraph must include
   **“LDMud → FluffOS conversion”**.
5. Assemble: `python3 scripts/assemble_numbering.py` then
   `python3 scripts/gen_readme_table.py`.
6. Verify native `look` / `score` / `quit`, reconnect after quit, and
   WASM via `scripts/wasm_client.js` before calling it playable.

## Architecture checklist (do this before trusting a clean compile)

LDMud and FluffOS share LPC surface syntax but diverge in master /
security / builtin semantics. A clean compile is not enough. Audit
these **before** deep play (full writeup: `AGENTS.md` §7.158,
`libs/questmud/NOTES.md`):

1. **`master::valid_read()`** — add cases for `"load_object"`,
   `"recompile_object"`, `"include"` (and usually `"restore_object"`).
   LDMud does not route compilation through `valid_read()`; without
   these cases FluffOS silently denies every object load / `#include`.
2. **`master::creator_file()`** — always return a **uid string** (e.g.
   `"BACKBONE"`). Never return bare `0`/`1` (LDMud’s “no special uid”
   sentinel); FluffOS destructs the object after compile if it gets a
   non-string.
3. **`master::valid_override()`** — return 1 (or a real policy). Required
   for any `efun::…` call outside `simul_efun.lpc`.
4. **`creator()` / backbone guards** — after (2), truthy-uid “wizard
   clone” guards may self-destruct every login; exempt backbone/system
   uids.
5. **`reset()` timing** — FluffOS `reset` is lazy/scheduled, not
   synchronous after `create()` like LDMud. Daemons that assume
   `reset()`-filled maps need `create() { reset(0); }` or direct
   initializers (see also §7.177).
6. **`move_object`** — FluffOS efun is **1-arg** (moves `this_object()`).
   Rewriting `move_object(A,B)` → `A->move_object(B)` **silently no-ops**
   when `A` is not `this_object()` (no `call_other`→efun fallback). Prefer
   a real `move_object(dest)` method on livings, or `efun::move_object`
   only from the moving object.
7. **Missing LDMud efuns** — shim in `simul_efun` as needed (`cat`,
   `tail`, `object_name`, `member`, `m_delete`, …). See `questmud`.
8. **Live-verify silently-failing paths** — fresh character’s first move
   into the world, and save/restore across a cold driver restart.

## Strategy B — catalog overlay (modern LDMud 3.x)

Use when the archive master is built on `set_driver_hook()`,
`inaugurate_master()`, closures, and/or a multi-file simul_efun tree.
FluffOS has no `set_driver_hook` / `unbound_lambda` / `#'` closures.

Pattern used by `acme` and the 974–978 onboards:

1. After `convert_lib.sh`, rename the LDMud master (and simul entry if a
   single file) to `*_ldmud.lpc` so it is preserved but not loaded.
2. Add a FluffOS-only tree under `/catalog/`:
   - `master.lpc` — permissive §7.158 apply set; `connect()` clones
     `/catalog/login`
   - `simul_efun.lpc` — thin helpers (`cat`, `log_file`, `exists`)
   - `auto.h` — global include for the overlay only
   - `login.lpc` / `player.lpc` — name/password, `look`/`score`/`quit`,
     save under `/data/<letter>/<name>.o`
   - `void.lpc` / `workshop.lpc` — two linked rooms so movement is
     exercised
3. Point `config.fluffos` at:
   - `master file : /catalog/master`
   - `simulated efun file : /catalog/simul_efun`
   - `global include file : "/catalog/auto.h"`
4. Keep the full LDMud source tree in `work/` for archaeology; document
   in NOTES that the world/guild/protocol stacks are **not** loaded.
5. Helper that wrote the 974–976 overlays:
   `scratchpad/write_ldmud_catalog.py` (edit and re-run for the next
   similar lib, or copy `/catalog` from an existing overlay).

## Strategy A — fuller port (questmud-style)

1. Start from the §7.158 master fixes above on the real master, not a
   stub.
2. Sweep LDMud-only syntax (`#'`, `lambda`, multi-value mappings
   `map[key, n]`, `foreach` variants FluffOS rejects, etc.).
3. Add simul_efun shims for missing efuns.
4. Fix `move_object` properly (living method), not only the silent
   `A->move_object(B)` rewrite.
5. Boot, register, and deep-test (§10.7) — catalog overlay is not enough
   if you claim the real world is playable.

## Registration / site

- `libs/<slug>/meta.json` with `wasm_status`, `port`, English description
  that mentions LDMud → FluffOS.
- `scripts/assemble_numbering.py` + `gen_readme_table.py`.
- Site pack happens in CI / `scripts/build_site.sh` from `meta.json`.

## Do not

- Treat “compiled clean” or “passed `lpcc_check`” as proof the port is
  done for a new LDMud lineage.
- Onboard a second copy of the same upstream without checking
  `scratchpad/librarian-next.txt` / existing NOTES.
- Load LDMud `set_driver_hook` masters on FluffOS and expect them to
  boot.
