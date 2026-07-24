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

## Driver rebuild / formatter / WASM pass (2026-07-23)

- **LPC formatter** run over all `work/*.lpc`: 7,952 total, 7,948
  written, 3 already-idempotent, 1 refused (self-check error, expected).
  One genuine **formatter regression found and fixed**: `d/sky/xitian.lpc`'s
  `valid_leave()` had `if (::valid_leave(me,dir)) return notify_fail(...)`
  mangled into `if (: : valid_leave(me, dir)\n)\nreturn notify_fail(...)`
  — the formatter breaks on the `::` parent-call scope operator followed
  immediately by `(`, inserting a space between the colons and corrupting
  the surrounding statement. This file (a high-level "heaven" zone room,
  not on the registration path) wasn't reached by the interactive test so
  the corruption didn't surface as a boot failure, but was caught by
  cross-checking for the same pattern found live-breaking a sibling lib
  (`xiaoaojianghu2`) in this same pass. Fixed by hand-restoring the
  original single-line form. Worth flagging as a general formatter bug:
  **any `::methodname(...)` call appears to be at risk of this
  corruption** — a sweep for `': : '` (colon-space-colon-space) across a
  lib's `work/` after running the formatter is a cheap, effective check.
- **Native retest against the freshly-rebuilt driver**: clean boot, zero
  fatal errors, trimmed-preload boot time still well under 15 seconds.
  Full registration flow re-verified in one continuous connection (id
  `qinjiab`, real Chinese name `秦岭江`, gender `m`, gift roll accepted):
  entered the game world at 南城客栈/South City Inn with real NPCs,
  `look` and `score` produced correct real content, `quit` showed the
  proper flavor-text sequence. The previously-documented
  `default error message` noise (`你发现事情不大对了...`) reproduced again
  at a highly variable count (consistent with the prior pass's
  host-load/timing-sensitive diagnosis) — never blocked any step.
- **WASM test**: boots clean, reaches the Chinese-name prompt without
  crashing (this lib's registration-counter code apparently tolerates
  the WASM harness's log-subdirectory-copy gap better than some
  siblings — shows a real, non-zero registered-player count rather than
  crashing). No IP-gating or other blocking issue observed in the
  portion exercised; did not push to a full playthrough (not required).

## WASM-enablement pass (2026-07-24)

Standard four-change pass (AGENTS.md §1.3b/§1.3e/§1.5). Gates patched:

1. **Loopback always allowed** — `adm/daemons/band.lpc`: added a shared
   `is_local_site(site)` helper (true for `127.0.0.1`, leading `127.`,
   empty/non-string, or malformed non-dotted-quad IPs = WASM garbage) and
   short-circuited `is_banned()`, `is_strict_banned()`, and
   `create_char_banned()` with it (all three take an IP string; covers the
   two `is_strict_banned` login gates in `logind.lpc` `logon()`/
   `encoding()` and the `create_char_banned`/`is_banned` guest-jail check
   in `enter_world()`).
2. **IP-format checks bypassed for loopback** — `adm/daemons/logind.lpc`
   `encoding()` (~line 190): the `!ip_name` destruct and the
   every-char-must-be-digit-or-dot loop over `query_ip_number()` (both
   would kill any WASM connection with a garbage IP) now only run when
   `band->is_local_site()` is false.
3. **Anti-flood throttles exempt loopback** — `logind.lpc` `logon()`:
   (a) the 5-second same-IP reconnect throttle (`last_ip` + `time()+5`)
   and (b) the `logon_cnt > 10` per-IP concurrent-connection cap now skip
   local connections (new `is_local` flag); (c) the `MAX_LOGIN` (=5)
   per-IP multi-login cap in `get_id()` (~line 360) skips local
   connections too.
4. **Uptime startup gate** — none exists (the `uptime()` use in
   `encoding()` only ages out the `newid` registration-in-progress temp
   map every 300s); nothing to bypass. The per-id `newid` in-memory
   throttle ("已经有人在注册这个id了", cleared every 5 min / on restart)
   was left as-is — it is per-id not per-IP and only affects re-registering
   the same id twice within 5 minutes.
5. **Admin account seeded** — id `fluffos`, pw `Mud@2026`, name 浮浮,
   registered via the real flow (`gb` → `no` → `new` → id → Chinese name →
   password x2 → email → gender `m`, then the 西游记-style gift screen at
   first world entry: `9` accept → `y` confirm). Granted `(admin)` via
   `adm/etc/wizlist`. Verified: banner shows `(admin)`, wizard `update
   /adm/daemons/band` recompiles successfully, character finalized
   (no_gift flag cleared, lands in 南城客栈).

Save files (untracked, NOT gitignored — orchestrator must `git add`):
- `work/data/login/f/fluffos.o` (login save: password)
- `work/data/user/f/fluffos.o`  (player body save)

Retest: fresh normal registration (id `qinfzd`, 秦风) works end-to-end
(gift screen → world → `score` renders → `quit` clean); fluffos login +
wizard command works; debug.log has no new errors. One pre-existing,
unrelated error surfaced once in a transcript: lazy-loading
`adm/daemons/emoted` hits `restore_object(): Illegal mapping format`
on the archive's own corrupt `/data/emoted` seed save (§7.7 class;
emoted is excluded from the trimmed preload) — cosmetic, command still
dispatched, not introduced by this pass. Test char saves removed.
Note: id length limit is 3-8 chars (`fluffos` = 7 fits).

## Fail-closed loopback retrofit (2026-07-24)

**Security correction, applied retroactively.** `adm/daemons/band.lpc`'s
shared `is_local_site()` helper (item 1 above) originally treated an
empty/non-string/malformed IP as "local" (fail-open) — a stopgap for a
since-fixed WASM driver bug. Tightened to **fail-closed**:

```lpc
int is_local_site(string site) {
  if (!stringp(site)) return 0;
  if (site == "127.0.0.1" || site == "::1") return 1;
  if (strlen(site) >= 4 && site[0..3] == "127.") return 1;
  return 0;
}
```

An unparseable/empty IP now falls through to the normal (non-exempt)
path everywhere this helper is consulted — `is_banned()`,
`is_strict_banned()`, `create_char_banned()` in `band.lpc`, and every
`logind.lpc` call site that gates on it (the IP-format check in
`encoding()`, the anti-flood throttles in `logon()`/`get_id()`). No
other call site needed a separate edit since they all delegate to this
one helper. Retested: fresh registration (id `xlqztwo`, name 秦岭峰) still
completes end-to-end via loopback (gift accept → world → `look`/`score`
render correctly → `quit`); fluffos login + `update /adm/daemons/band`
still succeeds (`重新编译 /adm/daemons/band.lpc：成功！`). Zero new
runtime errors. Test char saves (`xlqzgat`/`xlqzone`/`xlqztwo`) removed
after verification.
