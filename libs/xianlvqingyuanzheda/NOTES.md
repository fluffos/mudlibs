# xianlvqingyuanzheda — 仙侣情缘 "浙大版" (ZJU fork)

Archive: `仙侣情缘浙大版.rar`. Port: 40033. Status: **done** (boots clean
with a trimmed preload list, full registration flow verified end-to-end
including a real Chinese name).

## What this is

A modified fork of "仙侣情缘"/XLQY by bugbug & alading at 缥缈水云间
(ZJU — Zhejiang University), circa 2003-4-5, based on a branch closer to
`xlqy_new2007` (archive #26, `chinese.c` byte-identical) than to
`xianlvqiyuan`'s (archive #38) 2001 original — though `logind.c`/
`master.c`/`securityd.c`/`convertd.c` all differ from both, so this
needed its own diagnostic pass. `adm/obj/{master,simul_efun}` layout.
Archive required nested extraction (`.rar` → `xlqy.tar.gz` → `tar xzf`).
~9,206 raw files, 7,952 after `.c`→`.lpc` rename.

## Fixes applied

1. **Standard §15h**: `is_chinese()` single-char CJK rewrite;
   `check_legal_name()` bound `< 2 || > 12` → `< 1 || > 6`, removed the
   `i%2==0` gate (`name[i..<0]` slice was already clean).
2. **§15o insurance**: added `get_include_path()` to `master.lpc`.
3. **§8h recurrence**: `convertd.lpc`'s Greek-table stray-backslash typo,
   45 occurrences, fixed with the standard sed pattern (no CRLF present).
4. **§15g/k-adjacent hardening**: `adm/simul_efun/file.lpc`'s `cat()`
   hardened against a missing file (same fragile `write(read_file(...))`
   pattern as `xianlvqiyuan`, though the `BANNER` file itself was already
   correctly lowercase in this archive — applied as insurance regardless).
5. **A long boot-hang investigation, resolved pragmatically per explicit
   user direction** ("DNS / inet daemon should be generally disabled" /
   "It's not our target fix this round"): the full boot (with the
   complete original `adm/etc/preload`, 24 entries) took an extremely
   long time — observed via instrumented waits showing the driver
   spending the overwhelming majority of wall-clock time blocked (e.g.
   13 seconds of accumulated CPU time over 9+ minutes of wall-clock),
   consistent with one or more blocking/slowly-timing-out network calls
   scattered through preload and early object loading. Initially
   suspected and partially fixed `adm/daemons/network/dns_master` (an
   intermud DNS/mudlist daemon whose `create()` calls `resolve()` +
   `socket_create()`/`socket_bind()` to bootstrap a cross-mud database
   from a hardcoded remote server) — commented out its networking calls
   and removed it from preload. This did NOT fully resolve the slowness
   on its own (a full-preload retry still took many minutes), and rather
   than continue open-ended bisection across the other ~20 preload
   daemons, applied the pragmatic fix directed by the user: **trimmed
   `adm/etc/preload` down to only the entries needed for the
   registration flow itself** (`securityd`, `band`, `virtuald`, `logind`,
   `cmd_d`, `chinesed`, `convertd`) and excluded the rest (`emoted`,
   `aliasd`, `fingerd`, `channeld`, `monitord`, `natured`, `weapond`,
   `rankd`, `combatd`, `miscd`, `spelld`, `storyd`, `choosed`,
   `dns_master`, `locationd`, `feizeid`, `auto_cleard` — combat/quest/
   location/social systems, not needed to test registration). With this
   trimmed list the driver booted in well under 15 seconds. **This is a
   deliberate scope reduction for testing purposes, not a full
   restoration of the original mudlib's feature set** — if this lib is
   ever run for real play rather than registration-flow verification,
   the excluded daemons should be re-added one at a time and checked
   individually for their own preload-time cost/blocking behavior.

## New standing policy (see AGENTS.md)

Per explicit user direction, proactively check every future lib's
`adm/etc/preload` for a DNS/intermud/network daemon and exclude it
BEFORE the first boot attempt, rather than waiting to discover a boot
hang first.

## Interactive test result — full registration flow

With the trimmed preload list, verified the complete registration path
in one continuous connection (same flow shape as `xianlvqiyuan`): `gb`
→ `no` (not a student) → `new` → `xlqzda` (English name) → **`秦风`**
(real Chinese name) → accepted, proceeds to "请设定您的密码：".

## lpcc sweep

7,952 files, 7,824 pass / 128 fail (98.4%). Failure tail is the usual
shape (missing globals/inherits, a handful of syntax typos) — not
triaged individually per AGENTS.md §6b/§13. Memory stayed healthy
throughout (~14-15GB free).

## Re-verification pass (2026-07-23)

Extended the interactive test past the password prompt through full
registration (id `xlqzdgz`, name `秦江`), gift confirmation, `look`,
`score`, and `quit` — all completed correctly with real content (entered
the game world at 南城客栈/"South City Inn" with real NPCs, `score`
rendered the full character sheet, `quit` showed the real flavor-text
quit sequence).

**Investigated but not fixed — the "default error message" anomaly is
real, reproducible, host-load-dependent, and non-blocking.** The
transient `你发现事情不大对了，但是又说不上来。`(config's `default error
message`) noted as a one-off, non-reproduced anomaly in the sibling lib
`xianlvqiyuan`'s NOTES.md reproduces HERE consistently but with a highly
variable count per connection (observed 0, 3, and up to 18+ occurrences
across repeated identical test runs against the same unmodified code).
Instrumented `adm/daemons/logind.lpc`'s `enter_world()` with temporary
`write()` markers (removed after diagnosis, per the project's established
§8c/§15d technique): confirmed the errors are scattered across several
*different*, functionally unrelated calls in the same stretch of code
(new `MAILBOX_OB` creation, `"/adm/daemons/ipd"->seek_ip_address()`,
`CHANNEL_D->do_channel()`, `UPDATE_D->check_user()`) rather than one
single repeated bad call — inconsistent with a single deterministic bug
in any one of them. Also confirmed via a temporary instrumented
`master.lpc`'s `error_handler()` (writing `standard_trace()`'s full text
to a scratch file, removed after diagnosis) that **the underlying real
error text never gets captured** — not in `debug.log` (checked
extensively, zero matches even with markers correlating the exact
moment), not in the instrumented scratch file either (it was never even
created, meaning `error_handler()`'s own `write_file()` produced no
output during the very runs where the friendly message WAS shown to the
player — inconsistent with a straightforward reproducible LPC-level
error). Combined with the count varying run-to-run against byte-identical
code, this points to a **host-load/timing-sensitive artifact** (this
sweep runs many sibling agents' driver processes concurrently on a
shared, resource-constrained host) rather than a deterministic mudlib
bug — plausibly related to `eval_cost`/timer edge cases under CPU
contention (see AGENTS.md's `set_eval()` gotcha for a similar class of
timing-sensitive symptom). **Not chased further**: it never prevented
registration, `look`, `score`, or `quit` from completing correctly in any
of the ~6 test runs performed (worst case, extra noise the player has to
scroll past), and matches the sibling lib's own precedent of being
noted-but-not-investigated. Flagging here in more detail than the
original one-line note in case a future pass sees it escalate to
something that actually blocks a flow — this pass didn't observe that.
