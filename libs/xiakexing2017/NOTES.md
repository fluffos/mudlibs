# MUD侠客行2017完整版.zip → `xiakexing2017`

- Archive: `archives/MUD侠客行2017完整版.zip` (4.7MB — "侠客行"/"Ode to
  Gallantry" [Jin Yong novel], 2017 complete edition, MudOS v21). Mudlib
  root at `xkx/` (archive top level), config at top-level `config.cfg`.
  Note: `xkx/` directory name here is coincidental — unrelated to the
  "xkx" zone-name reuse seen inside other libs' `/d/` trees.
- Port: **40017**.

## Status: DONE — boots clean, playable over telnet

Zero fixes needed — clean boot and full login flow on the first attempt.

## What was fixed

Nothing needed for boot. Routine conversion: encoding (3330 converted,
521 already UTF-8/ASCII, 59 skipped binary, 15 lossy), `.c`→`.lpc` (3266
files, 146 refs auto-fixed), 8 local angle-bracket includes converted to
quotes automatically, `static`→`nosave` (42 files).

## Known remaining issues

- 79 lpcc-sweep failures (of 3266, 97.6% pass) — not triaged given the
  small count; boot/login path unaffected.

## How to run

```
cd libs/xiakexing2017
~/src/fluffos/build-debug/src/driver config.fluffos
python3 ../../scripts/mudclient.py 127.0.0.1 40017 --timeout 10 --send "" --send "look" --send "quit"
```

## Post-hoc fix: UTF8-native is_chinese/registration (AGENTS.md §15h)

Applied in a later batch pass across the whole project: `is_chinese`/`is_chinese2`
in the shared `chinese.lpc` simul_efun fragment used GBK byte-range checks that
silently never match real Chinese text once strings are UTF-8 (this driver's
`str[i]` returns a Unicode codepoint, not a GBK byte). This broke character
registration specifically -- any real Chinese name was rejected. Fixed the
range check to test the CJK Unicode block instead, and halved the
GBK-byte-calibrated length bounds in `check_legal_name` to match. See
AGENTS.md §15h for the full writeup; confirmed via a real interactive
registration test (Chinese surname + given name reaching the next prompt).

## Re-verification pass (driver rebuild + LPC formatter + WASM build)

- **Reformatted** all 3266 `.lpc` files under `work/` with
  `tools/lpc-syntax/format-corpus.mjs`: 3238 written, 0 already
  idempotent-clean, 28 refused by the tool's own token/byte-identity
  guard (expected on messy legacy code, not chased). Verified the
  earlier §15ae fix (`feature/command.lpc`'s `command_hook` staying
  `nomask` with `private` still commented out, in both `feature/` and
  `home/` copies) survived unchanged.
- **Native retest against the freshly-rebuilt driver**
  (`~/src/fluffos/build-debug/src/driver`, rebuilt from latest upstream
  master): clean boot, zero fatal errors in `log/debug.log`. Full
  registration flow re-verified with a fresh real Chinese name
  (`秦岳`/id `xkxbnem`), reaching an actual starting room, `look`/
  `score`/`quit` all producing correct output — no regressions from
  either the driver rebuild or the reformat.
- **WASM build test** (`scripts/wasm_client.js` against
  `~/src/fluffos/build-wasm/src`): boots cleanly (only benign compile-
  warning spam, no fatal errors). Full registration completed end-to-end
  under WASM too — id `xkxwasme` → real Chinese name `秦徽` → password/
  stat-roll-accept/email/gender → landed in the game world, `look`/
  `score`/`quit` all produced correct output. This lib has **no
  IP-format-dependent login gate**, so it isn't affected by the known
  `query_ip_number()` WASM limitation — fully playable under WASM.

## WASM-enablement pass (loopback-allow / admin seeding)

This lib's `adm/daemons/band.lpc`/`logind.lpc` are byte-identical (per
§2.1 lineage check) to the `xiakexing3`/`jinyongqunxiazhuan2008` engine
files, whose WASM pass was already done and verified with the correct
fail-closed convention — ported that fix here and re-verified
independently rather than assuming it.

- `adm/daemons/band.lpc` `is_banned()`: added a loopback short-circuit
  `if (stringp(site) && (site == "127.0.0.1" || site == "::1" ||
  (strlen(site) >= 4 && site[0..3] == "127."))) return 0;` before the
  regexp ban-list scan. Written fail-closed from the start: only a real
  loopback-shaped string counts as local; a malformed/empty/non-string
  site is NOT treated as local and still goes through the regexp ban
  check. `logind.lpc:66`'s `BAN_D->is_banned(query_ip_name(ob))` gate in
  `logon()` is thereby loopback-proof.
- No `uptime()` startup-grace gate and no per-IP anti-flood/registration
  throttle exist in this lineage (only the in-memory `mad_lock` admin
  lockdown flag, default off — game/admin design, left alone).

Admin account: `fluffos` / `Mud@2026` / 浮浮, registered through the
real flow (id → y → 浮浮 → password ×2 → talent accept `y` → email →
`m`). Granted `(admin)` by appending `fluffos (admin)` to
`adm/etc/wizlist` (shipped with `rwz (admin)` already present, no
trailing newline — added one; `securityd.lpc` reads this file at
`create()`, so a driver restart was needed to pick up the new line).
Verified after restart: `目前权限：(admin)`, title `【天神】`, `update
/adm/daemons/band` → `重新编译 /adm/daemons/band.lpc：成功！`.

Save files for the orchestrator to force-add (untracked, not
gitignored):
- `libs/xiakexing2017/work/data/user/f/fluffos.o`
- `libs/xiakexing2017/work/data/login/f/fluffos.o`

Two pre-existing caught (non-fatal) `restore_object(): Illegal file
format` errors were observed in `debug.log` during this pass —
`/adm/daemons/chinesed`'s save data at boot preload, and
`/clone/board/kedian_b`'s board save data at `enter_world()` (matches
the raw-path `/clone/board/kedian_b` display already visible in the
game, instead of a proper board name — its corrupted save data is why).
Both are wrapped in `catch()` by `master.lpc`'s `preload()`/
`logind.lpc`'s own catch respectively, non-fatal, and confirmed via
`git log`/`git status` to be genuinely corrupted data already committed
as part of the original archive conversion (archive #20, "booted clean
with zero fixes") — not introduced by this session. Left as-is per the
project's established `emoted.o`/similar precedent; not a new
regression.

Retest: fresh boot, fresh registration (id `qretest`, real Chinese name
秦风十一) through `look`/`score`/`quit` — landed in 客店, correct
output, clean quit. `fluffos`/`Mud@2026` admin login verified via
`score` (confirms `(admin)`/天神) and `update`. `debug.log` had exactly
the two pre-existing corrupted-save errors above and zero NEW runtime
errors. Test character `qretest` removed afterward; fluffos kept.
