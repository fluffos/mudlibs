# fy2.rar → `fy2`

- Archive: `archives/fy2.rar` (2.8MB — "风云再起Ⅱ"/"Storm Rises Again
  II", 河海大学计算机及信息工程学院/Hohai University). Mudlib root at
  `fy/fy/`, config in the same directory (`config.FY2`). Same `fy4`-style
  master.lpc lineage as fengyun434/fy2005 (default-allow `valid_override`,
  no `load_object` in `valid_read`/`valid_write`).
- Port: **40014**.

## Status: DONE — boots clean, playable over telnet

Zero fixes needed to boot — clean on the first attempt. Full login flow
confirmed (name-length validation, re-prompt).

## What was fixed

Nothing needed for boot. Routine conversion: `.c`→`.lpc` refs auto-fixed,
9 local angle-bracket includes converted to quotes automatically,
`static`→`nosave` (39 files).

## Known remaining issues

- 73 lpcc-sweep failures (of 2839, 97.4% pass) — not triaged given the
  small count; boot/login path unaffected.

## How to run

```
cd libs/fy2
~/src/fluffos/build-debug/src/driver config.fluffos
python3 ../../scripts/mudclient.py 127.0.0.1 40014 --timeout 10 --send "" --send "look" --send "quit"
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

- **Formatter**: `format-corpus.mjs` over all 2839 `.lpc` files; 2837
  reformatted, 2 unchanged, **0 errors**.
- **Proactive fix applied before the first boot attempt of this pass**:
  this lib is confirmed byte-identical to `fengyun2qinghua` (same
  distribution, per that lib's own NOTES.md cross-check), which this
  pass found has a `cmds/usr/quit.lpc` bug: `message("system", ...,
  environment(me), me)` assumes `environment(me)` is always non-zero,
  and a mistimed `quit` (racing the post-registration RETURN prompt)
  can crash it, leaving the connection stuck repeating the same crash
  on every subsequent `quit`. Applied the identical `if
  (environment(me))` guard here proactively before booting, rather than
  waiting to rediscover it independently.
- **Native retest against rebuilt driver**: clean, zero fixes needed
  beyond the proactive one. Full registration + `look`/`score`/`quit`
  verified with a real Chinese name (王语嫣, female), zero debug.log
  errors.
- **WASM test**: boots and plays fully. No errors of any kind (not even
  the usual non-fatal sockets-package warnings — this lib doesn't
  preload a network daemon, same as `fengyun2qinghua`). Full
  registration with a real Chinese name (段誉), `look`, and `quit` all
  completed cleanly. Not affected by the documented `query_ip_number()`
  WASM limitation.

## WASM-enablement pass (loopback / admin seeding)

- **Loopback ban bypass** (§1.3b): `adm/daemons/band.lpc` `is_banned()`
  (~line 47) — short-circuit at top: non-string / empty / `127.0.0.1` /
  `localhost` / `127.`-prefix sites return 0. Called from
  `adm/daemons/logind.lpc:72-73` with both `query_ip_name()` and
  `query_ip_number()`; original regexp ban logic unchanged below.
- **Uptime gate**: none (no `uptime()` connection gate in logind).
- **Anti-flood throttle**: none found.
- **Admin account** (§1.5): `fluffos` / `Mud@2026`, display 浮浮, status
  `(admin)` via a `fluffos (admin)` line appended to `/adm/etc/wizlist`
  (read by `adm/daemons/securityd.lpc` create()). Registered through the
  real flow; verified re-login + `update /adm/daemons/combatd` →
  "重新编译 ... 成功". Retest: fresh normal registration (秦风) into the
  world with working `look`/`score` (test char saves removed).
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
  `libs/fy2/work/data/user/f/fluffos/fluffos.o`,
  `libs/fy2/work/data/login/f/fluffos/fluffos.o`.
