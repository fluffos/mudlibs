# chidi.rar → `chidi`

- Archive: `archives/chidi.rar` (17MB — "《江湖 I》"/"Jianghu I", generic
  wuxia-themed, MudOS lineage). Mudlib root at archive top level (no
  nesting). Config at top-level `config.cfg` (had a harmless duplicate
  `port number` line).
- Port: **40006**. Biggest lib by file count so far: 17809 raw / 16096
  `.lpc` after conversion.

## Status: DONE — boots clean, playable over telnet

Full login flow (registered-player count, high-score display, name/
password prompts) confirmed working.

## What was fixed

1. Encoding: 16994 converted, 457 already UTF-8/ASCII, 307 skipped
   binary, 51 lossy.
2. `.c` → `.lpc`: 16096 files. 911 literal `.c"` refs auto-fixed.
3. `static` → `nosave`: 74 files.
4. `master.lpc` needed NONE of the master.lpc/securityd.lpc fixes from
   libs #4/#5 (`bxsj`/`bxsj1`) — different lineage (closer to lib #1's
   "simple" style: default-allow `valid_override`, `find_object`-only
   `valid_read`/`valid_write`, no recursion risk).
5. `adm/simul_efun/file.lpc`'s `tail()` wrapper called `efun::tail()`,
   which doesn't exist in this driver (AGENTS.md §8e) — same missing-efun
   issue as lib #1, but here it's inside a file that's part of
   `simul_efun.lpc`'s composition, so it was FATAL (blocked the whole
   boot) rather than an unused dead command. Reimplemented in plain LPC
   (`do_tail_lpc`, `read_file`+`explode`+slice-last-N+`write`) — the
   caller turned out to be dead code (no callers anywhere in this lib)
   but implemented it properly anyway per AGENTS.md §8e's guidance.
6. `adm/daemons/npcd.lpc` had 4 `#include <npc/LANG.c>`-style angle-
   bracket includes referencing files renamed to `.lpc` — **generalized
   the fix into `convert_lib.sh`** (a new step handling
   `#include <....c>` uniformly, since the existing fix only handled
   quoted-string `.c"` references, not include directives).

## Known remaining issues (documented, not fixed)

- 752 lpcc-sweep failures (of 16096) — not individually triaged past a
  category scan. Largest buckets: various syntax errors (32+13+12+9+7+6 —
  likely more of the fullwidth-punctuation/missing-quote typo shapes from
  AGENTS.md §9/§10, not confirmed one-by-one), `Undefined variable
  DIABLO_D`/`SKILL_BASE_NAME`/`SKILL_EN_NAME`/`SKILL_CH_NAME` and
  `Undefined function query_competitor`/`add_light` (missing-content
  shape, AGENTS.md §13). 8 of the failures are `temp/feng<timestamp>`
  files — clearly leftover runtime/crash-dump debris from the archive's
  original live server, not real source; safe to ignore entirely.

## How to run

```
cd libs/chidi
~/src/fluffos/build-debug/src/driver config.fluffos
python3 ../../scripts/mudclient.py 127.0.0.1 40006 --timeout 10 --send "" --send "look" --send "quit"
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

## Re-verification pass (2026-07-23): driver rebuild + LPC formatter + WASM build + NEW log_error() spam fix (AGENTS.md §15af)

- **Formatter**: ran `format-corpus.mjs` over all of `work/` (16,096
  files, 15,035 written/reformatted, 42 already-clean, 1,019 refused
  with an error — a larger-than-usual error count but expected on this
  archive's already-documented long tail of syntax typos, not chased
  individually).
- **Native retest against rebuilt driver** (`build-debug/src/driver`,
  rebuilt from latest upstream master): clean boot (took roughly a
  minute to preload — this is the largest of this batch's libs at
  16k+ files), zero fatal errors in `debug.log`.
- **NEW bug found and fixed**: a full interactive registration (this
  lib's own admin-password + normal-password two-tier scheme, then
  Chinese name, talent roll, email, gender) revealed
  `adm/obj/master.lpc`'s `log_error()` showed the **raw compiler
  diagnostic text to ANY connected player**, no `wizardp()` gate at
  all, for every compile diagnostic funneled through
  `APPLY_LOG_ERROR` — including harmless "Unused local variable"/
  "Unknown #pragma" warnings triggered by the very first lazy compile
  of the new character's own `char.lpc`/`feature/*` files right after
  gender selection. In the pre-fix transcript this dumped ~30 screens
  of raw compiler internals over the new player's very first moment in
  the game — same bug class already found and fixed on several sibling
  libs in this project (`dtsl`/`datangshuanglong`/`dongfanggushi2`/
  `bixiecanyang`/`wuhanzhan`/`shenzhou`, AGENTS.md §15af), not
  previously caught here because this lib's original testing pass
  (like several others) never exercised a full registration through to
  gender selection. Fixed identically: only show the full diagnostic to
  a wizard; only alarm an ordinary player with the generic
  `__DEFAULT_ERROR_MESSAGE__` for a genuine compile **error** (gated on
  absence of the substring `"warning:"`) — `#include <runtime_config.h>`
  was already present in `master.lpc`, no additional include needed.
- Re-verified with a fresh full registration (real name `秦深`, ID
  `qinshen`) all the way through to the actual game world (世外桃源
  starting room, NPC dialogue firing correctly), then `look`/`score`/
  `quit` all producing correct output with **zero** compiler-warning
  spam and zero real errors in `debug.log`.
- **WASM build**: preload completes with only the expected non-fatal
  `sockets`-package gap (`adm/daemons/ftpd.lpc`'s
  `socket_create`/`socket_bind`/`socket_close` → `Undefined function`,
  cascading into a few dependent compile errors on the same file but
  caught non-fatally — `Initializations complete.` still printed).
  Registration is blocked by the documented `query_ip_number()`
  WASM-mode limitation: `adm/daemons/logind.lpc`'s `logon()` calls
  `BAN_D->is_banned(query_ip_number(ob))` and rejects every connection
  with "你的地址在本 MUD 不受欢迎...". **Not a mudlib bug** — the
  documented driver-side gap, not something to patch. Verdict: boots
  cleanly under WASM (log_error fix confirmed present in this build
  copy too, via the in-memory `work/` snapshot); registration cannot
  complete due to the driver's IP-check limitation.

## WASM-enablement pass (2026-07 standard: loopback-allow, throttle exempt, admin seed)

Gates patched:

- `adm/daemons/band.lpc` `is_banned()` (~line 106): loopback / `127.`
  prefix / empty / non-string / non-dotted-quad IP → return 0. This was
  the documented WASM login blocker (logind's `logon()` calls it with
  `query_ip_number()`); now bypassed per §1.3b.
- `adm/daemons/logind.lpc` `logon()` (~line 138): `ip_cnt > 40` per-IP
  connection cap now applies only to non-loopback addresses.
- No `uptime()` startup-grace gate in this lib's logon.

Admin account: id `fluffos`, password `Mud@2026`, wizpwd `Wiz@2026`
(chidi shares the 碧血残阳-style dual-password registration), name 浮浮,
granted `(boss)` (this lineage's top rank) via `adm/etc/wizlist`.
Verified `update /d/register/entry` → 成功 on re-login; wizard room-path
view active. **Save files for the orchestrator to force-add:
`libs/chidi/work/data/user/f/fluffos.o` and
`libs/chidi/work/data/login/f/fluffos.o`** (untracked dirs).

Retest: fresh normal registration (id `ceshisi`, name 秦风, female)
end-to-end into 世外桃源, look/score/quit correct, 0 new errors in
debug.log; test char saves removed.


## Retrofit (2026-07-24): fail-closed loopback check (security correction)

The loopback-allow gate patched above originally also treated a
non-string/empty/malformed `query_ip_number()` result as loopback (a
defensive stand-in for the WASM driver bug). That driver bug is now fixed
upstream, so this was tightened to fail-closed: only an exact
`"127.0.0.1"` / `"127."`-prefix / `"::1"` match bypasses the gate; a
malformed or non-string address now falls through to the original gate
logic (treated as untrusted/remote) instead of being auto-allowed.
Re-verified fluffos login still works after tightening.
