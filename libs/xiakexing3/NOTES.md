# xiakexing3 — 侠客行三 / 金庸群侠传

Archive: `侠客行III .rar` (note: trailing space before `.rar`; TODO.md's
table originally listed this as `侠客行III 可用.zip`, which was wrong —
corrected once the real filename was discovered during extraction).
Port: 40038. Status: **done** (boots clean and quick, full registration
flow verified end-to-end including a real Chinese name).

## What this is

Config's `MUD_NAME` is "侠客行三", but the live connection banner
actually reads "金庸群侠传" ("Jin Yong's Gathering of Heroes") — yet
another instance of a lib's internal game name differing from its
config/archive name. `adm/obj/{master,simul_efun}` layout — confirmed
genuinely **unrelated** to `xiakexing100` (archive #43, `adm/single/`
layout) despite the shared "侠客行" title prefix, reinforcing the
established lesson that similar titles aren't a reliable lineage
signal. Small lib, ~3,651 raw files.

## Extraction quirk (new, see AGENTS.md's "Archive tooling" section)

Despite the `.rar` extension, this archive is actually a **plain POSIX
tar** (`unrar` correctly refused it: "not RAR archive"). Its members are
stored with **relative `../xkx3/...` paths**, which GNU `tar -xf`
unconditionally refuses to extract ("Member name contains '..'") even
with `--transform` (the safety check runs before transforms apply).
Worked around by extracting with Python's `tarfile` module directly,
stripping each member's leading `../` before calling `extract()` — see
AGENTS.md for the reusable snippet.

## Fixes applied

1. **AGENTS.md §15h**, standard shape: `is_chinese()`'s GBK lead-byte
   check → CJK codepoint check; `check_legal_name()`'s byte-count bound
   `< 2 || > 12` → character-count bound `< 1 || > 6`, removed the
   `i%2==0` even-byte-offset gate.
2. **Confirmed NOT needed**: no §4 fix (`master.c`'s `valid_write` gates
   via `find_object` only, `valid_read` is a bare `return 1;`); no
   `named.lpc` (doesn't exist in this lib).
3. **AGENTS.md §15p**: `/adm/daemons/network/dns_master` was in
   `adm/etc/preload` — removed proactively before the first boot
   attempt. Booted clean in under 10 seconds, zero compile errors, no
   hang.

## Interactive test result — full registration flow

No hidden pre-id prompts. Verified the complete registration path in
one continuous connection: id `xkxctest` → confirm `y` → **real Chinese
name `秦风`** → accepted, proceeds straight to "请设定您的密码：". This
lib's registration prompt text warns against using Jin Yong novel
character names, but the actual `banned_name` array only contains
pronouns + "时空" (no specific character names), so no specific name
needed to be avoided this time.

## lpcc sweep

2,981 files, 2,887 pass / 94 fail (96.8%). Failure tail is the usual
shape (missing globals, a handful of syntax typos) — not triaged
individually per AGENTS.md §6b/§13. Memory stayed healthy throughout
(~13GB free).

## Retroactive fix (found via archive #91, jinyongqunxiazhuan2008): this lib was completely command-dead after registration (AGENTS.md §15ae)

Archive #91 (`金庸群侠传2008加强版.rar`) turned out to have a master.c
byte-identical (in both `adm/single/` and `adm/obj/` locations) to this
lib's raw archive -- confirmed via md5sum, not assumed -- explaining
this lib's previously-unexplained "config says 侠客行三 but live banner
says 金庸群侠传" oddity: this is a rebrand of the same underlying
codebase. That later processing pass (after §15ae, the `private
nomask` command-hook bug, had been discovered) flagged this lib for a
check, since its own original testing above never verified a
post-login command -- exactly the blind spot §15ae warns about.

Checked and confirmed: `feature/command.lpc`'s `command_hook()` was
`private nomask` (the `home/command.lpc` copy was already correct,
`nomask` without `private`). `commandd.lpc`'s `sscanf` pattern was
ALREADY `"%s.lpc"` (not the `".c"` variant found on `bxsj`/`bxsj1`/
`jinyongwenzi` — so §15ar's second bug does not apply here, only
§15ae's). Fixed by dropping `private`; re-verified with a fresh full
registration (id → confirm → real Chinese name "秦岳"/"秦淮" → password
→ stat-gift accept → email → gender) reaching an actual starting room
(客店), with `look`/`score`/`quit` all now producing correct real
output, `debug.log` clean (0 `error:` lines — the "编译时段错误"
warning-spam visible to the player during testing is the separate,
still-unfixed §15w bug, cosmetic and unrelated to command dispatch).

## Re-verification pass (driver rebuild + LPC formatter + WASM build)

- **Reformatted** all 2981 `.lpc` files under `work/` with
  `tools/lpc-syntax/format-corpus.mjs`: 2948 written, 13 already
  idempotent-clean, 20 refused by the tool's own token/byte-identity
  guard (expected on messy legacy code, not chased). Verified the §15ae
  fix above (`feature/command.lpc`'s `command_hook` staying `nomask`
  with `private` dropped) survived the reformat unchanged.
- **Native retest against the freshly-rebuilt driver**
  (`~/src/fluffos/build-debug/src/driver`, rebuilt from latest upstream
  master): clean boot, zero fatal errors in `log/debug.log`. Full
  registration flow re-verified with a fresh real Chinese name
  (`秦墨`/id `xkxcnex`), reaching the actual starting room (`客店`),
  `look`/`score`/`quit` all producing correct output — confirms the
  §15ae fix continues to hold under both the rebuilt driver and the
  reformatted source. No regressions.
- **WASM build test** (`scripts/wasm_client.js` against
  `~/src/fluffos/build-wasm/src`): boots cleanly (only benign compile-
  warning spam, no fatal errors). Full registration completed end-to-end
  under WASM too — id `xkxcwas` → real Chinese name `秦岭` → password/
  stat-roll-accept/email/gender → landed in the same `客店` starting
  room, `look`/`score`/`quit` all produced correct output (post-login
  command dispatch, i.e. the §15ae fix, also confirmed working under
  WASM). This lib has **no IP-format-dependent login gate**, so it isn't
  affected by the known `query_ip_number()` WASM limitation — fully
  playable under WASM.

## WASM-enablement pass (loopback-allow / admin seeding)

This lib is byte-identical (per §2.1 lineage check) to the
`jinyongqunxiazhuan2008` engine/daemon files, whose WASM pass was
already done and verified with the correct fail-closed convention —
ported that fix here and re-verified independently rather than
assuming it (§2.1's "ported fixes still need per-lib verification").

- `adm/daemons/band.lpc` `is_banned()`: added a loopback short-circuit
  `if (stringp(site) && (site == "127.0.0.1" || site == "::1" ||
  (strlen(site) >= 4 && site[0..3] == "127."))) return 0;` before the
  regexp ban-list scan. Written fail-closed from the start: only a real
  loopback-shaped string counts as local; a malformed/empty/non-string
  site is NOT treated as local and still goes through the regexp ban
  check. `logind.lpc`'s `BAN_D->is_banned(query_ip_name(ob))` gate in
  `logon()` is thereby loopback-proof.
- No `uptime()` startup-grace gate and no per-IP anti-flood/registration
  throttle exist in this lineage (checked the full `logind.lpc`
  input_to chain; the only other connection-adjacent gate is the
  in-memory `mad_lock` admin lockdown flag, default off — game/admin
  design, left alone).

Admin account: `fluffos` / `Mud@2026` / 浮浮, registered through the
real flow (id → y → 浮浮 → password ×2 → talent accept `y` → email →
`m`). Granted `(admin)` by appending `fluffos (admin)` to
`adm/etc/wizlist` (shipped with `sbaa (admin)` already present;
`securityd.lpc` reads this file at `create()`, so a driver restart was
needed to pick up the new line). Verified after restart: `目前权限：
(admin)`, title `【天神】`, `update /adm/daemons/band` →
`重新编译 /adm/daemons/band.lpc：成功！`.

Save files for the orchestrator to force-add (untracked, not
gitignored):
- `libs/xiakexing3/work/data/user/f/fluffos.o`
- `libs/xiakexing3/work/data/login/f/fluffos.o`

Retest: fresh boot, fresh registration (id `qretest`, real Chinese name
秦风十) through `look`/`score`/`quit` — landed in 客店, correct output,
clean quit. `fluffos`/`Mud@2026` admin login verified twice (once via
`update`, once via `score` to confirm `(admin)`/天神 status directly).
Zero `执行时段错误` lines in `debug.log` across the whole session. Test
character `qretest` removed afterward; fluffos kept.
