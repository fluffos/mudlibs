# fengyun4-3-4.rar → `fengyun434`

- Archive: `archives/fengyun4-3-4.rar` (6MB — "风云Ⅳ"/"Storm Riders 4",
  Sumxin Fengyun, `www.sumxin.com`). Mudlib root at `Fengyun/fy4/`, config
  at `Fengyun/bin/config.cfg`. Different lineage from the 东方故事/
  simple-style libs seen so far (its own `master.lpc` shape).
- Port: **40011**.

## Status: DONE — boots clean, playable over telnet

Zero fixes needed to boot — clean on the first attempt (checked
proactively for the known `load_object`/`domain_file`/angle-bracket-
include patterns beforehand; none present in this lineage). GB/BIG5
encoding-selection prompt (same legacy pattern as other libs), then full
login flow.

## What was fixed

Nothing needed for boot. Routine conversion only: encoding (8801
converted, 255 already UTF-8/ASCII, 151 skipped binary, 30 lossy),
`.c`→`.lpc` (8238 files, 465 refs auto-fixed), `static`→`nosave` (50
files, notably low ratio vs other libs of similar size — this codebase
barely uses the idiom).

## Known remaining issues

- 85 lpcc-sweep failures (of 8238) — 99% pass rate, the cleanest lib so
  far. Not triaged given the small remaining count and time budget; none
  blocked booting or the login flow.

## How to run

```
cd libs/fengyun434
~/src/fluffos/build-debug/src/driver config.fluffos
python3 ../../scripts/mudclient.py 127.0.0.1 40011 --timeout 10 --send "0" --send "" --send "quit"
```
(the `"0"` selects GB encoding at the legacy GB/BIG5 prompt)

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

## Re-verification pass: driver rebuild + LPC formatter + WASM build

- **Formatter**: `format-corpus.mjs` over all 8238 `.lpc` files; 6477
  reformatted, 4 unchanged, 1757 refused (self-check `errors`/token
  mismatches, expected on a mega-lib this size — not chased down
  individually). One explicit `TOKEN MISMATCH` reported for
  `d/for_martea/neon_playground/migong/adm/daemons/vrm_server.lpc`
  (left untouched by the formatter itself, per its own refuse-don't-guess
  policy).
- **Proactive fix applied before the first boot attempt of this pass**:
  same `adm/daemons/securityd.lpc` `resolve()`-before-`wiz_status`
  ordering bug as `fengyun3dianzang`/`fengyun3xiuding` (same 风云 engine
  family) — fixed proactively before booting. (A second, empty
  `adm/securityd.lpc` file also exists in this lib but is dead/unused —
  `SECURITY_D` in `globals.h` points at `adm/daemons/securityd`, not it —
  left alone.)
- **Native retest against rebuilt driver**: clean, zero fixes needed
  beyond the proactive one. Full registration + `look`/`score`/`quit`
  verified with a real Chinese name (杨过), zero debug.log errors.
- **WASM test**: boots and plays fully. Only non-fatal errors are the
  expected no-sockets-package ones (`ftpd.lpc` and
  `network/dns_master.lpc` both fail to compile with `Undefined function
  socket_create`/`socket_bind`/`socket_close`, `*No program in object`
  at preload — caught, non-cascading). Full registration with a real
  Chinese name (郭靖), `look`, and `quit` all completed cleanly. Not
  affected by the documented `query_ip_number()` WASM limitation.

## WASM-enablement pass (loopback / admin seeding)

- **Loopback ban bypass** (§1.3b): two gates patched.
  1. `adm/daemons/band.lpc` `is_banned()` (~line 46) — short-circuit for
     non-string / empty / `127.0.0.1` / `localhost` / `127.`-prefix.
     Called from `adm/daemons/logind.lpc:80-81`.
  2. `adm/daemons/logind.lpc` `valid_wiz_login()` (~line 528) — the
     wizard-IP whitelist gate (`/adm/etc/wizip/<id>`) destructs wizard
     logins from unlisted IPs; loopback/empty/non-string IPs now always
     pass (this gate feeds on `query_ip_number()`, garbage under WASM).
- **Uptime gate / anti-flood throttle**: none found.
- **Admin account** (§1.5): `fluffos` / `Mud@2026`, display 浮浮, status
  `(admin)` via `fluffos (admin)` appended to `/adm/etc/wizlist`. No
  `/adm/etc/wizip/fluffos` file exists (= unrestricted). Verified
  re-login + `update /adm/daemons/combatd` → 成功.
- **Retest**: fresh normal registration (秦风) works, `look`/`score` OK,
  test char saves removed; no new debug.log errors.
- **Fail-closed retrofit** (2026-07-24 security correction): the loopback
  check(s) above originally also treated an empty/non-string IP as
  loopback (defensive fallback for the then-broken `query_ip_number()`).
  Since the driver's IP-reporting bug is now fixed upstream (WASM
  reports a clean `127.0.0.1` like native), that fallback was removed —
  loopback is now strictly `stringp(ip) && (ip=="127.0.0.1" ||
  ip=="::1" || ip[0..3]=="127.")`; anything unparseable/empty is
  untrusted/remote and goes through the original gate logic. Retested:
  fluffos login + `look`/`quit` still clean over loopback.
- **Save files to force-add** (untracked, NOT gitignored):
  `libs/fengyun434/work/data/user/f/fluffos/fluffos.o`,
  `libs/fengyun434/work/data/login/f/fluffos/fluffos.o`.
