# 三界神话-春节.rar → `sanjieshenhua`

- Archive: `archives/三界神话-春节.rar` ("Spring Festival" snapshot of 三界
  神话 / "SanJie Myth"), nested at `sanjie/` inside the RAR. ~15.7k raw
  files, 12,871 `.lpc` files after conversion. This is a "Century/
  adm-single family"-shaped custom-securityd lib (per AGENTS.md §11) —
  bundles the ORIGINAL MudOS v22pre11 driver's own C source under
  `bin/v22pre11/` (harmless dead weight — never referenced by
  `master`/`mudlib directory`, our own driver is used instead; left in
  place rather than deleted, per AGENTS.md §3's "ignore bundled driver
  source" guidance).
- Proposed number: **060** (new, unique — see "Lineage/triage" below).
- Port: **40098** (as assigned; confirmed free).
- Status: **DONE** — boots clean, full registration verified end-to-end
  with a real Chinese name (云飞) natively AND under WASM, admin
  (`fluffos`) verified via `update` on both drivers (after a data-file
  fix — see below).

## Triage / lineage

Genuine LPC mudlib (`inherit` everywhere). Diffed core files against
sibling `sjcs` (also in this batch, shares the "三界" title
prefix) — substantially different `master.lpc`/`securityd.lpc`/
`logind.lpc` (416/747/1179 lines here vs 495/316/1718 there) — **not** a
derivative pair, same conclusion as documented in `sjcs`'s
NOTES.md. Treated as a fully independent unique game.

## State at handoff (this session)

A previous agent session had already: extracted the archive, converted
encoding/renamed `.c`→`.lpc`, written `config.fluffos` (port 40098),
applied the loopback-allow patch to `sited.lpc`/`band.lpc`, exempted
loopback from the login-count anti-flood check in `logind.lpc`, fixed the
`protected`→`nomask` `command_hook`, and appended `fluffos (admin)` to
`adm/etc/wizlist`. No `fluffos` player-save existed yet (registration not
attempted), no NOTES.md/README.md. This session completed the pipeline.

## Fixes applied this session

1. **1 corrupted file**, same exact corruption as sibling
   `sjcs`: `d/sea/npc/beast1.lpc` — 2 trailing garbage bytes
   (`\xff\xba`) right after a clean `}\n\n` ending, confirmed present in
   the raw archive itself. Truncated the 2 bytes.
2. **Wizard write-ACL default was fully deny-by-default, so a freshly
   seeded `(admin)` account could log in, show `(admin)` status, but
   could not actually write/compile anything** — a new bug class worth
   flagging for AGENTS.md. `adm/daemons/securityd.lpc`'s
   `query_security("default_trusted_write")` returns an ENTIRELY EMPTY
   mapping (its only line, `"/" : ({"(admin)"})`, is commented out in the
   source — an authoring artifact, not something the conversion touched);
   `valid_write()`'s directory-walk ACL therefore finds no `trusted_write`
   entry at any level and denies every write outside a few hardcoded
   exceptions (own `/u/<id>/`, save-file paths, `/binaries` removal).
   The lineage's own runtime mechanism for granting broader write access
   (`cmds/adm/auth.lpc`, which edits `extend_trusted_write` and persists
   it via `SECURITY_D->save()`) is itself gated to two hardcoded
   historical uids (`mudring`/`stey`) — `fluffos` cannot invoke it.
   Confirmed root cause via `update /adm/obj/master.lpc` failing with
   `读写权限不够无法更新！` despite `(admin)` status.
   **Fix** (data, not code, per AGENTS.md §1.5's "prefer editing data"):
   wrote `data/static/securityd.o` (the save file `query_save_file()`
   points at — did not exist in the archive at all) seeding
   `extend_trusted_write (["/":({"(admin)",}),])`, restoring exactly what
   the commented-out default would have granted. `securityd.lpc`'s own
   `restore()`/`::restore()` (via `inherit F_SAVE`) picks this up
   automatically on every boot. Verified: `update` now succeeds for
   `fluffos` both natively and under WASM. **This same "commented-out
   default, no seed data" shape may recur on other Century/adm-single
   family libs with dead admin write-ACLs — worth checking
   `default_trusted_write`/`default_trusted_read` for a fully-empty
   result on any future lib in this family, even if `(admin)` status
   displays correctly at login.**

## Verification (native)

Booted `cd libs/sanjieshenhua && ~/src/fluffos/build-debug/src/driver
config.fluffos` — clean boot, zero fatal errors in `log/debug.log`.

Full registration flow (fresh id `yunhang`, real Chinese name **云飞**):
English id (3-8 lowercase letters) → `new` → id again → admin/recovery
password (5+ chars) → confirm → normal password (5+ chars, must differ
from admin password) → confirm → Chinese name → email (must contain `@`
and `.`, length ≥ 9) → character type (1-6) → gender (m/f) → entered
`南城客栈`. `look`, `score` (full 个人档案 card), and `quit` all correct
(tested via reconnect after this lib's 60-second same-account
quit-retention gate elapsed — a normal game-design timer exempting
wizards, per AGENTS.md §1.3e's "keep in-game content timers" rule, not a
hosting-protection gate to bypass).

Admin: registered `fluffos` through the SAME normal "new" flow (id
`fluffos`, admin/recovery password + normal password `Mud@2026`, display
name 浮浮) — the pre-seeded `fluffos (admin)` wizlist line was picked up
immediately, "您的系统权限目前是：(admin)" shown on first login. This
lineage has a THIRD password (`WIZPWD`) for wizard-level accounts, but
`NO_CHECK_WIZPWD` is `#define`d in `logind.lpc`, so any input (including
empty) bypasses it. After the `securityd.o` seed fix above,
`update /adm/obj/master.lpc` → `重新编译 /adm/obj/master.lpc ...成功！`.
`quit` clean.

## Verification (WASM)

`node scripts/wasm_client.js ~/src/fluffos/build-wasm/src
libs/sanjieshenhua` — same full registration flow (fresh id `wasmtes`,
name 沐晨) reached the same starting room; `look`/`score`/`quit` all
correct. Admin login as `fluffos` + `update /adm/obj/master.lpc` also
succeeded under WASM (reads the same `data/static/securityd.o` seed via
the MEMFS copy of `work/`). **This lib is fully playable under WASM.**

Testing gotcha worth recording: this lineage's post-login prompt embeds a
live `HH:MM:SS` clock that updates every second, so a single mudclient/
wasm_client invocation needs a SMALL `--idle` (~0.3-0.5s) to catch the
gap between commands once in the world — but the async "首次登录天赋
分配" (first-login stat-allocation) dialog that fires right after
character creation needs a LARGER idle (~1.0-1.5s) to avoid a race where
`9`/`y` are sent before the menu has actually printed (landing as bare
invalid commands instead). Used two separate connections (registration+
gift-confirm with large idle, then a reconnect with small idle for
look/score/quit) to work around this natively; for the WASM one-shot test,
`--idle 0.5` plus one extra blank "absorber" send between gender and `9`
was enough to make both phases work in a single continuous session.

## Known remaining issues (documented, not fixed)

- `bin/v22pre11/` (the archive's bundled original driver C source) is
  inert dead weight in the tree — never loaded by our driver, left as-is
  per AGENTS.md §3.
- lpcc sweep not re-run this session (no `lpcc_fail.log` was left by the
  prior session); the real boot + full interactive registration/admin
  test is the verification gate actually used, per AGENTS.md §10.4's
  guidance for large trees.

## How to run

```
cd libs/sanjieshenhua
~/src/fluffos/build-debug/src/driver config.fluffos
python3 ../../scripts/mudclient.py 127.0.0.1 40098 --timeout 20 --idle 1.2 \
  --send "gb" --send "new" --send "yourid" \
  --send "adminpass1" --send "adminpass1" \
  --send "yourpass1" --send "yourpass1" \
  --send "你的中文名" --send "you@example.com" \
  --send "1" --send "m" --send "9" --send "y"
```
