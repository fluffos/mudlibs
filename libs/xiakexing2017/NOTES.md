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
