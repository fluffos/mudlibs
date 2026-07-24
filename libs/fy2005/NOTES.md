# fy2005.rar → `fy2005`

- Archive: `archives/fy2005.rar` (48MB — "风云Ⅳ" 2005 build, same lineage
  as archive #14 (fengyun434), a later/bigger snapshot). Mudlib root at
  `fy2005/fy4/`, config at `fy2005/bin/config.fy4`.
- Port: **40013**.

## Status: DONE — boots clean; has an intentional 5-minute startup grace period

Booted with zero fixes needed (same clean lineage as fengyun434/fy2).
**This build enforces a 5-minute wait before login is allowed**
("风云系统正在初始化，请在五分钟后再登陆。" — "Fengyun system is
initializing, please log in again in 5 minutes.") — an intentional
startup-grace mechanic (same shape as `unknownlib20150716`'s 30-second
wait, just longer here), not a bug. Not waited out to confirm the actual
post-wait login flow given the time cost, but the boot itself is clean
(no compile errors, no crashes) and the pre-wait prompt flow (name
validation) works correctly.

## What was fixed

Nothing needed for boot. Routine conversion: encoding (12801 converted,
384 already UTF-8/ASCII, 43 skipped binary, 75 lossy), `.c`→`.lpc` (9764
files, 1328 refs auto-fixed), 11 local angle-bracket includes converted
to quotes automatically, `static`→`nosave` (44 files).

## Known remaining issues (documented, not fixed)

- Several `call_other() couldn't find object '/d/ZONE/room.c'` errors at
  boot — traced to plain-text DATA files (`quest/dynamic_location`,
  `adm/etc/scenery_phase` — bare one-path-per-line lists, no LPC string
  quoting) that still hold literal `.c` object-path references.
  `convert_lib.sh`'s `.c"` reference fix only scans `.lpc`/`.h` source
  (quoted-string context); it doesn't touch extensionless data files with
  bare (unquoted) paths, and blanket-fixing "any `path.c` text anywhere"
  risks false positives in genuine documentation/help text. Left as-is —
  affects some quest/scenery room resolution, not the boot/login path.
- lpcc sweep: 9696/9764 pass (99.3%) — not fully triaged past confirming
  a clean boot given time constraints.

## How to run

```
cd libs/fy2005
~/src/fluffos/build-debug/src/driver config.fluffos
# wait 5 minutes after boot before the login name prompt will proceed
python3 ../../scripts/mudclient.py 127.0.0.1 40013 --timeout 10 --send "" --send "look" --send "quit"
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

## Re-verification pass: driver rebuild + LPC formatter + WASM build

- **Formatter**: `format-corpus.mjs` over all 9764 `.lpc` files; 9739
  reformatted, 2 unchanged, 23 refused (self-check `errors`, expected).
- **Proactive fixes applied before the first boot attempt of this pass**
  (found via this same lib's `adm/daemons/securityd.lpc`, before even
  connecting): the same `resolve()`-before-`wiz_status` WASM-crashing
  ordering bug as `fengyun3dianzang`/`fengyun3xiuding`/`fengyun434` (same
  风云 engine family) -- reordered + wrapped in `catch()`. **Also found a
  second, more serious latent bug in the same `create()`**: an
  AGENTS.md-§15u-style "phone-home license expiration" self-destruct --
  `if (local[5]*10000+... > C_YEAR*10000+...) shutdown(0);` would kill
  the entire driver process once the wall clock passes
  `C_YEAR`/`C_MON`/`C_MDAY` (hardcoded to year **2109** here, so not
  reachable on any realistic host clock today -- but disabled/commented
  out as insurance per standing policy rather than left armed, same
  treatment as `moniHuafu`'s/`fengyun3dianzang`'s equivalent).
- **Native re-test against rebuilt driver**: clean boot, zero fixes
  needed beyond the two proactive ones above. The documented 5-minute
  startup grace period (`uptime() < 300`) still behaves exactly as
  described -- confirmed by actually waiting it out this time (prior
  passes noted the mechanic but didn't wait through it). **Full
  registration flow completed end-to-end for the first time, including
  the ASCII-art digit CAPTCHA** (`/feature/nada.lpc`'s `my_number()`):
  wrote a one-off scripted client (`/tmp`, not committed) that decodes
  the CAPTCHA programmatically -- copied the exact 10 digit glyphs from
  `c_num` in `nada.lpc` (10 rows × 15 chars each) and pattern-matches
  each of the up-to-8 digit columns in the two rendered row-groups
  against them (exact match, not fuzzy OCR, since the glyph table itself
  came straight from the source) -- rather than reading the ASCII art
  visually turn-by-turn. Verified end-to-end with real Chinese names
  (唐游/悟空/取经取) reaching the actual starting room (风云台),
  `look`/`score` producing correct output, and the double-`quit`
  anti-abuse confirmation (documented in README) working as described.
  Zero debug.log errors across all runs.
- **WASM test — full CAPTCHA-solving playthrough completed, not just a
  boot check**: this lib combines two real obstacles for WASM testing
  that don't affect the other 8 libs in this batch: (a) the same 90s
  per-connection `LOGIN_TIMEOUT` (`obj/login.lpc`) that exists natively
  too, and (b) the 5-minute `uptime()` grace period, which under the
  WASM harness's real-time-driven tick clock genuinely takes 5 real
  minutes of process lifetime to elapse. **Pitfall found**: an initial
  attempt kept one `fluffos_connect()`-created connection open through
  the whole 5-minute wait (sending periodic keepalive blanks) and got
  kicked by the 90s `LOGIN_TIMEOUT` long before the grace period ended
  (its own local timer, started at connect time, independent of
  `uptime()`) -- reproduced the "您花在连线进入手续的时间太久了" kick
  message. Fixed by ticking the driver with **no connection open at
  all** for the first 310 real seconds (`uptime()` advances regardless
  of connections), then calling `fluffos_connect()` fresh only after
  that -- giving the fresh connection its own full 90s window with the
  grace period already satisfied. With that fix, the full registration
  flow (encoding → id → CAPTCHA, decoded via the same exact-glyph-match
  approach as the native test → Chinese name 取经取 → password → email →
  gender → race) completed cleanly under WASM, reaching 风云台, with
  `look`/`score`/`quit`(×2) all producing correct output identical in
  shape to the native run. Only non-fatal errors are the expected
  no-sockets-package ones (`network/dns_master.lpc`'s
  `socket_create`/`socket_bind`, `*No program in object` at preload).
  This is the only lib in this batch where a full WASM CAPTCHA-gated
  registration was actually driven to completion, not just verified to
  boot. Not affected by the documented `query_ip_number()` WASM
  limitation.

## WASM-enablement pass (loopback / admin seeding)

Gates patched (all in `work/`):

- `adm/daemons/band.lpc` `is_banned()` (~line 58): loopback / empty /
  non-string / `localhost` / `127.`-prefix short-circuit (return 0).
  Called from `adm/daemons/logind.lpc:104-105`.
- `adm/daemons/logind.lpc` `logon()` (~line 217): the **5-minute
  `uptime() < 300` startup gate now applies only to non-loopback
  connections** (previously destructed every early local/WASM connect;
  the WASM harness needed a 310s pre-wait — no longer). Original gate
  kept verbatim for remote connections.
- `adm/daemons/logind.lpc` `logon()` (~line 153): the NETBAR per-IP
  multi-login cap block is skipped entirely for loopback/empty/
  non-string IPs (browser tabs are all loopback).
- `adm/daemons/logind.lpc` `valid_wiz_login()` (~line 665): the wizard
  IP-whitelist gate (`/adm/etc/wizip/<id>`) always passes loopback/
  empty/non-string IPs.
- KEPT: `LOGIN_TIMEOUT` idle kick, quit-twice confirmation, wiz_lock
  maintenance gate — game design, not hosting protection.

Admin account (§1.5): `fluffos` / `Mud@2026`, display 浮浮, status
`(admin)` via `fluffos (admin)` appended to `/adm/etc/wizlist`.
Registered through the REAL flow including the ASCII CAPTCHA (solved by
exact glyph match against `feature/nada.lpc`'s `c_num` table — note the
glyphs are Chinese numerals 零一二...九, indexes 0-9, plus an unused 十).
As a wizlisted account it spawns in /d/wiz/hall. Verified re-login +
`update /adm/daemons/combatd` → 成功.

Retest: fresh normal registration (秦风) through encoding + CAPTCHA into
风云台 with working `look`/`score` — confirms the uptime-gate bypass
(connected seconds after boot, previously impossible) and that normal
players are unaffected. Test char saves removed; no new debug.log errors.

- **Fail-closed retrofit** (2026-07-24 security correction): the loopback
  check(s) above originally also treated an empty/non-string IP as
  loopback (defensive fallback for the then-broken `query_ip_number()`).
  Since the driver's IP-reporting bug is now fixed upstream (WASM
  reports a clean `127.0.0.1` like native), that fallback was removed —
  loopback is now strictly `stringp(ip) && (ip=="127.0.0.1" ||
  ip=="::1" || ip[0..3]=="127.")`; anything unparseable/empty is
  untrusted/remote and goes through the original gate logic. Retested:
  fluffos login + `look`/`quit` still clean over loopback.

**Save files to force-add** (untracked, NOT gitignored):
`libs/fy2005/work/data/user/f/fluffos/fluffos.o`,
`libs/fy2005/work/data/login/f/fluffos/fluffos.o`.
