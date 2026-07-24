# xlqy_new2007 — 新仙侣情缘之飘渺纪元 (New Immortal Companion's Fated Love: Ethereal Era)

Archive: `xlqy_new2007.rar`. Port: 40022. Status: **done** (boots clean,
connects, plays through GB/BIG5 selection and into the age-verification
gate with zero fatal errors).

## What this is

"ES II mudlib" lineage again (`adm/obj/master.c`'s header comment:
"for ES II mudlib... rewritten by Annihilator"), same family as `rzrmud`
(#23) and `xkx2001` (#25). Archive extracts to a `复件 xlqy_new/`
("copy of xlqy_new") folder — note the leading Chinese text + space in
the directory name, handled fine by `convert_lib.sh`/`cp -r` as long as
it's quoted throughout.

**Found and fixed a real bug in `extract.sh` while processing this
archive**: the `.rar` extraction branch `cd`s into the destination before
referencing the (relative) archive path, so `unrar` couldn't find it and
silently produced an empty `raw/` while the script still reported success
(no `-e`, exit 0 either way). Fixed in `scripts/extract.sh` — `ARCHIVE` is
now resolved to an absolute path up front, and the script now checks
`raw/` actually has files and fails loudly if not, for any archive type.
See AGENTS.md's "Archive tooling" section for the writeup; this could in
principle have silently affected other `.rar` archives run through the
old script, though every previously-committed lib's `work/` already
passed its own boot test, so nothing already marked `done` is suspect.

## Fixes applied

1. **`extract.sh`** (see above — a tooling fix, not lib-specific).
2. **`adm/daemons/convertd.lpc:258`**: the exact AGENTS.md §8h stray-
   trailing-backslash-before-closing-quote typo in the Greek-alphabet
   conversion table (`"Ρ\",` → `"Ρ",` — this lib's specific character was
   Rho, not Alpha like the previously-seen instances), recurring for the
   third time in this "西游记/ES"-adjacent family (`fluffos_xiyou2000`,
   `mhxy`, now here). This file has plain LF line endings (not CRLF like
   `mhxy`'s copy) — used `sed -i -E 's/\\"(,)?$/"\1/'` directly; **caught
   and had to correct a mistake**: initially reused the CRLF-safe pattern
   from AGENTS.md §8h verbatim (`s/\\"(,)?\r?$/"\1\r/`), which
   unconditionally appends `\r` in the replacement even when the original
   line had none, injecting a spurious `\r` into this LF-only file's one
   fixed line. Verified with `cat -A` before and after; stripped the
   stray `\r` back out. **Lesson for next time this recurs**: check
   whether the file actually has CRLF (`file <path>` or `cat -A` a
   sample line) BEFORE choosing which of the two sed patterns to use —
   don't default to the CRLF-safe one "just in case", since its
   replacement isn't actually conditional on the match.
   `convertd.lpc` is `#include`d into many other daemon files, so this
   one fix should improve the lpcc pass rate substantially (initial sweep
   pre-fix: 8845/9060 = 97.6%, with hundreds of the failures being
   "In file included from .../convertd.lpc" cascades — re-swept after
   the fix, see below).

## Observed but not diagnosed: one non-fatal runtime error during login

The connect-time banner sequence prints the configured `default error
message` string ("你发现事情不大对了，但是又说不上来。") once, between the
Beijing-time line (`chinesed.lpc`'s `bj_time()`) and the registered-
player-count line — i.e. some error is happening around
`logind.lpc`'s `UPTIME_CMD->report()` call, but it's evidently caught/
non-fatal (execution continues normally to the age-verification prompt
and beyond) and produced **no trace at all in `debug.log`** (same
silent-error shape as AGENTS.md §15d, though not chased down with the
same catch()-instrumentation technique here since it isn't blocking
anything). Flagging for whoever revisits this lib's `cmds/usr/uptime.lpc`
or `UPTIME_CMD->report()` next.

## Interactive test result

Boots clean, connects; ASCII-art banner + Chinese render correctly,
GB/BIG5 selection prompt works, uptime/registration-count lines print
(with the one non-fatal error noted above), reaches the age-verification
("are you a student?") gate with zero fatal errors. Did not proceed
further into character creation (out of scope for this pass).

## lpcc sweep

Initial sweep (before the convertd.lpc fix): 9060 files, 8845 pass / 215
fail (97.6%), with a large fraction of the failures being `convertd.lpc`
inclusion cascades. Re-run after the fix — see the fresh numbers in this
lib's `lpcc_fail.log` (not hand-copied here to avoid this note going
stale relative to the regenerable file itself).

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
  9060 `.lpc` files in `work/`; 9043 written, 6 already-conformant, 11
  errors (files the formatter refused to touch — expected/fine on
  messy legacy code, not chased individually).
- **Native retest**: rebuilt `~/src/fluffos/build-debug/src/driver`
  booted this lib clean (zero fatal errors in `log/debug.log`). Went
  further than the previous pass's testing (which stopped at the
  age-verification gate) into a **full end-to-end registration**: real
  Chinese name 秦淑, gb/no/new/english-id/Chinese-name/password/email/
  gender/gift-allocation (`9`+`y` confirm) all completed, landed in
  聚见亭; `look` showed the correct room, `score` produced a correct
  full character sheet, `quit` gave the correct farewell text. Zero
  `debug.log` errors this session — the previously-noted "one
  non-fatal unexplained runtime error during login" from the original
  pass did not reproduce here.
- **WASM**: booted cleanly under `build-wasm` (only expected non-fatal
  preload warnings). Full registration flow (real Chinese name 秦岚)
  completed successfully end-to-end under WASM too, reaching 聚见亭;
  `look`/`quit` worked correctly. Same cosmetic
  `query_ip_number()`-under-WASM glitch as its `xlqy_early` sibling
  (last-connected-address line shows a garbled/timestamp-like value
  instead of an IP) — non-fatal, doesn't gate login. **Verdict: fully
  playable under WASM.**

## WASM-enablement pass (loopback-allow / gate bypass / admin seed)

Standard WASM-first pass per AGENTS.md §1.3b/e and §1.5. Gates patched
(same shapes as sibling `xlqy_early`):

- `adm/daemons/band.lpc` — added `is_loopback_site(string)` helper
  (loopback / empty / malformed-IP → local) and short-circuit `return 0;`
  at the top of `is_banned()`, `create_char_banned()`,
  `is_strict_banned()`.
- `adm/daemons/logind.lpc` — added `is_loopback_conn(object)` helper and:
  - `logon()` reconnect-flood throttle (`last_ip==ip && time+10>time`,
    ~line 96) — loopback exempt.
  - `logon()` per-IP connection cap (`logon_cnt > 10`, ~line 113) —
    loopback exempt.
  - `encoding()` `!ip_name` destruct + dotted-quad char-loop validator
    (~lines 195-207) — wrapped in `if (!is_loopback_conn(ob))`; this was
    the WASM-fatal gate.
  - No `uptime()` startup-grace destruct gate; the `uptime()` at ~line
    155 is the 300s newid registration window (content) — left intact.

Admin account seeded: id `fluffos`, pw `Mud@2026`, name 浮浮, granted
`(admin)` via `fluffos (admin)` line prepended to `adm/etc/wizlist`.
Verified: real registration flow (gb/no/new/fluffos/浮浮/pw×2/email/m/
9/y → entered world), then relogin as fluffos → status `(admin)`,
`update /adm/daemons/logind` → 成功. Retest: fresh normal registration
(秦风, gender f) end-to-end with look/score/quit all correct; test char
save removed; zero new debug.log errors. Save file:
`work/data/user/f/fluffos.o` (NOT gitignored — orchestrator adds
normally, no force-add needed).


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
