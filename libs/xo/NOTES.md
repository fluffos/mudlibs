# xo — 笑傲江湖迷你版 (The Smiling, Proud Wanderer — Mini Edition)

Archive: `xo.zip`. Port: 40023. Status: **done** (boots clean, connects,
plays through login into "create new character?" confirmation with zero
crashes).

## What this is

A different, smaller lineage from everything else processed so far in
this batch: `secure/daemon/master.c` header says "Original from TMI-2 and
ES2, Rewritten by Falcon 96-10-02" — TMI-2 ("The Mud International 2") is
another classic MudOS-era mudlib base, distinct from the "ES II"/nitan
families seen in archives #21-#26. Uses the `secure/daemon/{master,
sefun}` path convention (not `adm/obj/` or `adm/single/`). Small lib —
1395 `.c` files, "mini edition" as the name says. No `set`/`query`/
`delete` global simul_efun defined (like `rzrmud`/`xkx2001`) — every
object provides its own via inheritance, the architecturally correct
pattern (see AGENTS.md §15).

## Fixes applied

1. **AGENTS.md §4 (lazy security-daemon load)**: `secure/daemon/
   master.lpc`'s `valid_write`/`valid_read` called `load_object(SECURITY_D)`
   unconditionally on every single call (not gated behind `find_object()`
   first), wrapped in `catch()` but with no re-entrancy guard. Added the
   full guard (nosave flag + `find_object()` check before attempting
   `load_object()`) per the established §4 fix shape, applied proactively
   before the first boot attempt given the exact matching pattern.
2. **New bug (case-sensitivity, Windows-origin archive on a
   case-sensitive Linux filesystem)**: 3 files (`system/feature/char/
   command.lpc`, `cmds/arch/ll.lpc`, `cmds/arch/localcmds.lpc`)
   `#include <Action.h>` (capital A), but the actual file on disk is
   `include/action.h` (lowercase) — silently resolves on Windows'
   case-insensitive filesystem, hard-fails here. This was responsible for
   the overwhelming majority of the initial lpcc sweep's failures (762
   "Undefined class 'Action'" + 155 "Cannot #include Action.h" out of
   1395 files, cascading from just those 3 root includes via inheritance)
   — fixing the 3 `#include` lines dropped the failure count from 209 to
   72 in one shot (85.0% → 94.8% pass). Checked the whole tree for any
   other same-shape case-only filename mismatches (`find -iname` +
   case-insensitive dedup) — none found, this was the only instance.

## Interactive test result

Boots clean, connects; welcome message + "last modified 1999.11" credit
line render correctly, empty input at the username prompt correctly
triggers a polite disconnect ("欢迎下次再来" — not a bug), `new` +
a valid English name reaches the "create new character?" (y/n)
confirmation with zero crashes. Did not create a full character or play
further (out of scope).

## lpcc sweep

1395 files, 1323 pass / 72 fail (94.8%, after the Action.h fix). Remaining
72 failures are the usual long tail (a handful of syntax typos in
individual files, a few missing daemons like `TASK_D`/`SendToUser`/
`SendToMud` referenced but not present in this "mini" trimmed-down
archive) — not triaged individually, consistent with AGENTS.md §6b/§13.

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

## 2026-07-23: driver rebuild retest + LPC formatter + WASM check

- **Formatter**: ran `tools/lpc-syntax`'s `format-corpus.mjs` over all
  1395 `.lpc` files in `work/`; 1363 written, 7 already-conformant, 25
  errors (files it refused to touch, expected/fine on legacy code).
  Spot-checked that this didn't disturb the §4/case-sensitivity fixes
  above, plus the pre-existing `#define private protected` / `#define
  nosave nosave` compatibility shim in `include/globals.h` — all intact
  post-format.
- **Native retest**: rebuilt `~/src/fluffos/build-debug/src/driver`
  booted clean (zero fatal errors in `log/debug.log` — the two
  "mudlib error handler"/`#define __DEFAULT_PRAGMAS__` lines are the
  driver's own startup config dump, not errors). Went further than the
  previous pass (which had stopped at the "create new character?"
  confirmation) into a **full end-to-end registration + play session**:
  real Chinese name 秦风丁/秦风戊, English id/confirm/Chinese
  name/password/email/gender all completed, dropped into 小秦淮客寓;
  `look` showed the correct room+NPCs, `score` produced a correct full
  character sheet, `quit` correctly enforced the "must play 30 real
  minutes before saving" gate and disconnected cleanly on confirming
  `y`. Zero real `debug.log` errors.
- **WASM**: booted cleanly (only the expected non-fatal
  `socket_create`/`socket_bind`/`socket_connect` "Undefined function"
  compile errors from `system/std/net/client.lpc`, since the `sockets`
  package isn't built into this WASM binary — matches the documented
  non-fatal WASM restriction). Registration itself proceeds correctly
  all the way through the gender prompt (m/f) — but **reproducibly**,
  across several `--idle`/`--timeout` values (1.0/2.0/3.0/6.0s), the
  transition into the live game world (`enter_world()`) never
  completes: no banner/room text appears after answering the gender
  prompt, and subsequent `look`/`quit` input gets the driver's generic
  "什么? 你想干嘛?" (unrecognized command) fallback instead of real
  output. This is **not** the documented `query_ip_number()` limitation
  (this lib never gates login on IP format). It also does **not**
  reproduce on the native rebuilt driver (full playthrough above was
  clean), and notably does **not** reproduce on `xo_final` — a very
  close sibling with near-identical `logind.lpc` registration/
  `enter_world()` code — under the exact same WASM harness (see
  `xo_final`'s own NOTES.md entry, verified working end-to-end). Root
  cause not identified (the WASM harness's debug-log-open failure at
  boot, a separate pre-existing cosmetic warning, means any real
  runtime error thrown during `enter_world()` here would be silently
  discarded rather than surfaced anywhere inspectable). **Verdict:
  flagged as a possible WASM-specific gap isolated to this lib's own
  code path, not patched** — native play is completely unaffected, and
  chasing it further didn't seem proportionate to the smoke-test scope
  of this pass. Worth a closer look in a future WASM-focused pass.

## 2026-07-23 (integrity review): WASM world-entry hang RESOLVED — was the harness, not the mudlib

Re-ran the full WASM registration flow (new → id → confirm → Chinese name
→ password ×2 → email → gender) against the same `build-wasm` binary but
with the FIXED `scripts/wasm_client.js` (the copyDir() log-directory
recursion fix landed in the final commit of the previous pass, AFTER this
lib's WASM test had been run). Result: **`enter_world()` now completes
normally under WASM** — MOTD banner, 小秦淮客寓 start room, `look`, and
the `quit` save-gate prompt all appear exactly as in the native run. No
mudlib race exists in xo's enter_world path; the earlier "reproducible
world-entry hang" was the old harness failing to recreate the lib's
nested `log/` subdirectory shape in the WASM in-memory FS (this lib's
`log/` has 6 nested subdirs — acct/catch/log/room_log/runtime/static),
so an early uncaught `write_file()`/`log_file()` during enter_world threw
ENOENT and silently aborted the flow — precisely the harness gap class
described in that commit's message. Verdict: **fully playable under
WASM**; the previous NOTES entry's "possible WASM-specific gap isolated
to this lib" flag is closed.

Also noted (pre-existing, original-author code, left as-is): `system/
daemon/logind.lpc`'s `enter_world()` contains two leftover debug
`printf("beforee exec...")` / `printf("before setup...after exec..")`
lines that print to every player at world entry — present since the raw
archive (verified in the initial conversion commit), cosmetic only.

## WASM-enablement pass (loopback-allow / gate bypass / admin seed)

Standard WASM-first pass per AGENTS.md §1.3b/e and §1.5. Gates patched:

- `system/daemon/band.lpc` `is_banned()` (~line 39) — loopback / empty /
  malformed-IP short-circuit `return 0;` at the top (inline test, no
  helper needed — only one gate function in this daemon).
- `system/daemon/logind.lpc` `CheckDupIp()` (~line 148) — multi-login
  deny list now exempts loopback/malformed-IP connections (`return 0;`
  before the multi_deny regexp loop).
- `logon()`'s `LOGIN_DELAY` startup-grace gate (~line 102) is compiled
  out (LOGIN_DELAY not defined anywhere) — left as-is, noted only.
- `uptime() < 10` in `logon()` (~line 125) is cosmetic (banner text
  choice), not a gate — left intact.

Admin account seeded: id `fluffos`, pw `Mud@2026`, name 浮浮, granted
`(admin)` via `fluffos (admin)` appended to `secure/etc/wizlist`.
Verified: real registration (ENTER/new/fluffos/y/浮浮/pw×2/email/m →
landed in 小秦淮客寓), then relogin as fluffos →
`update /system/daemon/logind` → 成功, `score` correct. Retest: fresh
normal registration (秦风, f) end-to-end with look/score correct (quit
shows the original 30-min new-account retention prompt — content timer,
kept per policy); test char save removed; zero new debug.log errors.
Save file: `work/data/user/f/fluffos.o` (NOT gitignored — normal add,
no force-add needed).


## Fail-closed retrofit for the loopback-allow gate (2026-07-24)

The loopback helper above was originally written matching the
project-wide convention at patch time (AGENTS.md §1.3b), which also
treated an empty/non-string/malformed `query_ip_number()` result as
loopback, defensively, because the WASM driver used to return garbage
there. That underlying driver bug is now fixed (fluffos commits
`e33bb5da` "fix: query_ip_number() returned uninitialized garbage under
WASM" and `007bb863` "feat: synthetic resolve() on WASM instead of
raising an LPC error", both 2026-07-23; the locally-built
`build-debug`/`build-wasm` binaries already postdate both commits), so
treating unparseable IPs as trusted is a fail-open gap with no remaining
justification. Retrofitted to fail-closed: loopback is now strictly
`ip == "127.0.0.1" || ip == "::1" || ip[0..3] == "127."` (with a
`stringp()` guard before the slice) — a malformed/empty IP now falls
through to the NORMAL gate instead of being treated as local. Retested
after tightening: fresh driver boot clean, `fluffos` loopback login and
its wizard `update` command both still work; zero new debug.log errors.
