# xiyangzaixian_fengkuang — 夕阳再现 (Sunset Reappears — "疯狂江湖" build)

Archive: `夕阳再现-疯狂江湖.rar` (byte-identical duplicate: `夕阳再现-疯狂
江湖(1).rar`, already listed in AGENTS.md's Duplicate archives table —
only this one processed). Port: 40040. Status: **done** (boots clean,
full registration flow verified end-to-end including a real Chinese
name).

## What this is

"夕阳再现" ("Sunset Reappears"), `adm/obj/{master,simul_efun}` layout,
~17,768 raw files — one of the larger libs processed in this session.

## Fixes applied

1. **AGENTS.md §15h**, standard shape: `is_chinese()`'s GBK lead-byte
   check → CJK codepoint check; `check_legal_name()`'s byte-count bound
   `< 2 || > 10` → character-count bound `< 1 || > 5`, removed the
   `i%2==0` even-byte-offset gate.
2. **Confirmed NOT needed, via source reading**: no §4 fix
   (`master.c`'s `valid_write` gates via `find_object` only); no
   `named.c` daemon exists in this lib.
3. **Confirmed no DNS/intermud daemon to exclude** — unlike most recent
   libs, `adm/etc/preload` has NO `dns_master` entry at all (nothing to
   apply AGENTS.md §15p to here). `httpd` is in preload, confirmed safe
   — its socket setup is deferred via `call_out("setup", 5)`, non-
   blocking to preload.

## Interactive test result — full registration flow

No hidden pre-id prompts. Verified the complete registration path in
one continuous connection: id `xyzfktest` → confirm `y` → **real
Chinese name `秦风`** → accepted, proceeds straight to "请设定您的密码：".
This lib's registration prompt warns against Jin Yong novel character
names, but the actual `banned_name` array only contains pronouns and
generic words ("风云", "流氓", political figures) — no specific
character name needed to be avoided this time.

## Re-verification pass (QA sweep, later session)

Earlier pass's "full registration flow verified end-to-end" only actually
tested through to the password-setup prompt, not an ordinary post-login
command (per the project's standing §15ae policy of always testing at
least one post-login command like `look`/`score`). Re-tested the whole
flow end-to-end this pass:

- Confirmed `feature/command.lpc`'s `command_hook()` is `protected nomask`
  (not `private`) -- §15ae does not apply here.
- **Found and fixed a real bug**: `adm/obj/master.lpc`'s `log_error()`
  showed EVERY compile-time diagnostic to the connected player
  unconditionally (§15w), including harmless WARNINGS (`Unknown #pragma,
  ignored`, `Unused local variable`) from the first-ever lazy compile of
  a never-preloaded room/NPC file -- confirmed live: a fresh registration
  showed ~6 spurious `编译时段错误：... warning: ...` lines interleaved
  with the real welcome banner and room description. Fixed by gating the
  player-facing broadcast on the message NOT containing `"warning:"`
  (still logs everything to disk regardless, matching the established
  fix pattern used across this project). Re-verified with a fresh
  registration (`qinshu`/秦树, female) after restarting the driver: **zero**
  spurious messages, `look`/`score`/`quit` all correct (correct
  female-specific title "芊芊民女", landed in a real starting room
  "铁枪庙").
- Full registration + post-login-command flow now confirmed working with
  real Chinese names 秦天(male, landed in 北疆小镇)/秦树(female, landed in
  铁枪庙), `look`/`score`/`quit` all producing correct output, zero
  `执行时段错误` in `debug.log` after the fix.

## lpcc sweep

14,105 files, 13,798 pass / 307 fail (97.8%). Largest single cluster (53
failures) is a missing `GROUP_D` global — not triaged individually per
AGENTS.md §6b/§13. Memory stayed healthy throughout (~10-11GB free
during this sweep specifically), even while running concurrently
alongside several sibling libs' conversions/sweeps in the same session
as part of a push to parallelize more archives at once.

## Driver-rebuild retest + LPC reformat + WASM pass (this session)

- **LPC formatter applied** (`tools/lpc-syntax`, all `work/*.lpc`):
  14,003 files reformatted, 37 unchanged, 65 refused (self-check
  failures on messy legacy code, expected/harmless per the tool's own
  docs). Spot-checked that the fix sites below survived reformatting
  byte-for-byte in logic (only whitespace/style changed).
- **New bug found and fixed during this pass's native re-verification**
  (not caught by any earlier pass): `adm/daemons/logind.lpc`'s
  `get_resp()`/`get_name()` had the same stray, pre-existing debug
  leftover `printf("%O\n", ob);` seen in the `xiyouji`-family siblings
  (2 occurrences here) — dumped a raw internal object reference (e.g.
  `/clone/user/login#1`) straight to the connecting player right after
  their Chinese name is accepted, on every registration. Found live
  during a fresh registration test against the rebuilt driver; removed
  both occurrences; re-verified with a fresh registration (`qfzaid`/
  秦风终, male) — no stray object-reference text anywhere in the
  transcript, `look`/`score`/`quit` all still correct.
- **Native re-test against the freshly rebuilt driver**
  (`~/src/fluffos/build-debug/src/driver`, rebuilt from latest upstream
  master): boots clean, zero `FATAL`/`SIGSEGV`/`执行时段错误` in
  `debug.log`. Full registration verified with real Chinese name
  **秦风终** (male), reaching the actual starting room (北疆小镇),
  `look`/`score`/`quit` all producing correct output.
- **WASM build tested** (`~/src/fluffos/build-wasm/src` via
  `scripts/wasm_client.js`): boots cleanly (only the expected
  non-fatal `httpd.lpc` `socket_create`/`socket_bind` "Undefined
  function" preload errors, since the `sockets` package isn't built
  into this WASM image — same class of harmless preload gap as any
  missing daemon natively). **Login is blocked by the documented
  `query_ip_number()` WASM limitation**: `adm/daemons/logind.lpc`'s
  `logon()` calls `BAN_D->is_banned(query_ip_number(ob))` before any
  other prompt; under WASM this receives a malformed IP string (not a
  real dotted-quad), and the connecting player sees "你的地址在本 MUD
  不受欢迎" (address not welcome) immediately on connect, before ever
  reaching the id/name prompts. This is a driver-side WASM gap, **not**
  a mudlib bug — not patched, per AGENTS.md's standing guidance. Native
  play on `127.0.0.1` is completely unaffected.

## WASM-enablement pass (loopback-allow + admin seed)

Applied the four standard WASM-first changes (AGENTS.md §1.3b/§1.3e/§1.5):

1. **Loopback always allowed through ban/site gates**
   - `adm/daemons/band.lpc`: added reusable `is_local_ip(string ip)`
     helper (returns 1 for `127.*`, empty/non-string, or any string that
     fails `sscanf("%*d.%*d.%*d.%*d")` — i.e. WASM garbage IPs).
   - `adm/daemons/band.lpc` `is_banned()` (was ~L106): short-circuits
     `return 0` when `is_local_ip(site)` — this was the WASM login
     blocker (`is_banned()` returned 1 for a malformed IP, rejecting
     every WASM connection with "地址不受欢迎").
   - `adm/daemons/band.lpc` `vaild_allow_address()` (was ~L353):
     short-circuits `return 1` for local IPs (bypasses per-player
     allow-ip restriction).
2. **Uptime startup gate**: none in this build (the sibling
   `xiyangzaixian_fengyun2` has `uptime()<30`; this "疯狂江湖" build does
   not).
3. **Anti-flood throttles exempt loopback** — `adm/daemons/logind.lpc`:
   `logon()` `ban_cnt > 6` gate and `get_id()` `ip_cnt > 6` gate both now
   `&& !BAN_D->is_local_ip(...)`. In-game quit/kickout 600s retention
   timers left intact (game design, AGENTS.md §1.3e).
4. **Admin account seeded** — id `fluffos`, registered through the real
   flow (浮浮, male), granted `(admin)` by adding `fluffos (admin)` to
   `adm/etc/wizlist` (read by `securityd.lpc::create()`). Verified after
   restart: `update /adm/daemons/band` recompiled OK, `goto` worked,
   score shows 「您目前权限：(admin)」. Save file:
   `work/data/user/f/fluffos.o` (untracked, NOT gitignored — orchestrator
   must `git add` it).

Retest: fresh registration (the fluffos registration itself) reached the
world as a `(player)`; fluffos re-login has `(admin)` and wizard commands
work; `log/debug.log` clean (0 runtime errors).
