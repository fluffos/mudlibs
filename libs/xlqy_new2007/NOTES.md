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
