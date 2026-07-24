# xianlvqiyuan — 仙侣情缘 / XLQY (2001 "知秋站" snapshot)

Archive: `仙侣奇缘新版.rar`. Port: 40032. Status: **done** (boots clean,
full registration flow verified end-to-end including a real Chinese
name).

## What this is

"仙侣情缘" ("XLQY"), a 2001.2.22-dated build per its own `readme.txt`,
credited to vikee@263.net / www.mudfan.com, "知秋站" ("Zhiqiu Station")
as its home station. `adm/obj/{master,simul_efun}` layout. Despite the
similar Chinese title, this is a genuinely **different, older codebase
snapshot** than `xlqy_new2007` (archive #26) — confirmed via `md5sum`
diff on `chinese.c`/`logind.c`/`master.c` (all different). Similar
naming across archives in this collection has now proven unreliable as
a lineage signal twice (`shujianpiaoling2` vs `shujian2008` was the
first case) — always verify via file diff, never assume from the title
alone. ~9,118 raw files, 7,237 after `.c`→`.lpc` rename (511 files hit
lossy conversion — the highest lossy count of any lib processed so far,
though only one turned out to actually break the boot/registration
path).

## Fixes applied

1. **AGENTS.md §15h**, standard shape: `is_chinese()`'s GBK lead-byte
   check → CJK codepoint check; `check_legal_name()`'s byte-count bound
   `< 2 || > 12` → character-count bound `< 1 || > 6`, removed the
   `i%2==0` gate. The `name[i..<0]` slice was already a clean
   single-character-to-end slice, no change needed there.
2. **Proactively added `get_include_path()`** to `master.lpc` (§15o/§8d
   shape) as insurance — not proven strictly necessary, booted clean
   without hitting that specific symptom.
3. **Confirmed NOT needed, via source reading rather than by hitting a
   crash**: no §4 fix (`master.c` gates via `find_object` only); no
   §15n risk (`securityd.c`'s `valid_read` has an allow-by-default-
   unless-known-data-op pattern — `if (func != "read_file" && func !=
   "file_size" && func != "stat" && func != "read_bytes" && func !=
   "tail" && func != "ed_start") return 1;` — which already covers
   `load_object`/`include` implicitly, no explicit allowlist needed);
   no `named.c` daemon exists in this lib.
4. **AGENTS.md §8h recurrence**: `adm/daemons/convertd.lpc`'s Greek-table
   stray-trailing-backslash typo (`"α\",` should be `"α",`) — 45
   occurrences this time. No CRLF present, so the plain sed pattern
   (`s/\\"(,)?$/"\1/`) applied directly; verified via re-grep that the
   count dropped to 0.
5. **New case-sensitivity bug (§15g/§15k pattern), the nastiest one
   found today**: `adm/etc/BANNER` exists uppercase on disk, but
   `include/login.h`'s `BANNER` macro references lowercase
   `/adm/etc/banner`. This was worse than a typical case mismatch:
   `adm/simul_efun/file.lpc`'s `cat(string file)` did
   `write(read_file(file))` completely unguarded — `read_file()` on the
   missing lowercase path returns `0`, and `write(0)` crashes deep in
   `receive()`/`receive_message()` ("Bad argument 1 to receive(),
   Expected: string or buffer Got: 0"), killing the connection via
   `new_conn_handler: logon() ... has failed, the user is disconnected`
   with **literally zero player-visible output** — an empty
   `mudclient.py` transcript that looked exactly like a dead server.
   Fixed two ways: (a) copied `BANNER` to the lowercase name the macro
   expects (kept the original uppercase file too), and (b) hardened
   `cat()` itself to guard against a missing/unreadable file (`if
   (stringp(content)) write(content);`), since this same fragile
   pattern could recur for any other file this codebase references by a
   hardcoded path.
6. **One transient, non-reproduced anomaly, noted but not chased**:
   during one test run, the generic `default error message` config text
   ("你发现事情不大对了，但是又说不上来。") appeared briefly right after
   the banner, with no corresponding `debug.log` entry and no impact on
   the rest of that session or later clean retests — not investigated
   further given it didn't block registration and wasn't reproducible.

## Interactive test result — full registration flow

This lib's registration shape differs from most others processed
recently: **GB/BIG5 encoding preference** → **"are you a student"
age-gate** (any non-"no" answer — including accidentally typing a
username too early — is treated as "yes" and politely ends the session,
not a bug) → **English-name prompt where `new` must be typed literally**
for new-player registration (not "any unused id directly") → English
name → **Chinese name with NO y/n confirmation step in between** → password.

Verified in one continuous connection: `gb` → `no` → `new` → `xlqyc`
(English name) → **`秦风`** (real Chinese name) → accepted, proceeds to
"请设定您的密码：". An earlier attempt in the same investigation
accidentally sent `y` as the Chinese-name input (from a stale
expectation of a confirmation step) and it was correctly **REJECTED**
("对不起，请您用「中文」取名字。") before the retry with `秦风` succeeded
— incidentally reconfirming the fix rejects non-Chinese input correctly,
not just accepting everything.

## lpcc sweep

7,237 files, 7,126 pass / 111 fail (98.5%). Failure tail includes the
usual shape (`Undefined function query`, missing `setup` inherits, some
syntax typos) plus 17 "Invalid UTF8 codepoint in string literal" errors
— likely residual corruption from the unusually high lossy-conversion
count (511 files), not triaged individually per AGENTS.md §6b/§13 since
none of them are on the boot/registration path. Memory stayed healthy
throughout (~15GB free).

## Re-verification pass (2026-07-23)

Extended the interactive test past the password prompt through full
registration (id `xlqyriz`, name `秦河`), gift confirmation, `look`,
`score`, and `quit` — all completed correctly with real content (entered
the game world at 南城客栈/"South City Inn" with real NPCs, `score`
rendered the full character sheet, `quit` showed the real flavor-text
quit sequence). Zero genuine runtime errors in `debug.log`.

Also observed (across several runs) the same `default error message`
noise (`你发现事情不大对了，但是又说不上来。`) documented in more depth in
sibling lib `xianlvqingyuanzheda`'s NOTES.md — the count varies 0 to
dozens per connection against byte-identical code, never blocks any
tested flow, and is very likely a shared engine-family artifact (same
XLQY lineage, same "d/wiz/init" gift-selection room code) rather than
something specific to this archive's own content. Not re-investigated
here given the sibling lib's more thorough diagnosis already ruled out a
single deterministic cause and pointed to host-load/timing sensitivity.

## Driver rebuild / formatter / WASM pass (2026-07-23)

- **LPC formatter** run over all `work/*.lpc`: 7,237 total. First run
  failed outright with a filesystem permission error (`EACCES` writing
  `adm/obj/simul_efun.lpc`) — 9 files under `adm/obj/` and
  `adm/simul_efun/` were mode `0444` (read-only) on disk, apparently an
  artifact of the original archive extraction, not anything deliberate
  (no NOTES.md mention from the earlier pass). `chmod u+w` on those 9
  files, then reformatted cleanly: 5,675 written, 1,556 already-
  idempotent, 6 refused (self-check errors, expected).
  Same formatter bug as the sibling `xianlvqingyuanzheda` lib (identical
  shared file, same fix): `d/sky/xitian.lpc`'s `if (::valid_leave(me,dir))
  return notify_fail(...)` got mangled into `if (: : valid_leave(me, dir)
  ...)` — hand-restored to the original single-line form. Not on the
  registration path, so didn't surface as a boot failure, but fixed
  proactively for correctness.
- **Native retest against the freshly-rebuilt driver**: clean boot, zero
  fatal errors. Full registration flow (GB prompt → `no` age-gate →
  `new` → English id → real Chinese name, no confirm step, per this
  lib's known shape) plus gift-roll, gender, and post-login commands
  re-verified in one continuous connection (id `qinrizc`, real Chinese
  name `秦河岭`): entered the game world at 南城客栈/South City Inn,
  `look`/`score` produced correct real content, `quit` showed the proper
  flavor-text sequence. The previously-documented `default error message`
  noise reproduced again at a variable count, consistent with the
  host-load/timing-sensitive diagnosis already on file — never blocked
  any step.
- **WASM test**: boots clean, reaches the Chinese-name prompt without
  crashing. No IP-gating or other blocking issue observed in the portion
  exercised; did not push to a full playthrough (not required).

## WASM-enablement pass (2026-07-24)

Standard four-change pass (AGENTS.md §1.3b/§1.3e/§1.5). Gates patched
(same family shape as `xianlvqingyuanzheda`, patched analogously):

1. **Loopback always allowed** — `adm/daemons/band.lpc`: added
   `is_local_site(site)` helper (127.0.0.1 / leading `127.` /
   empty/non-string / malformed non-dotted-quad = WASM garbage) and
   short-circuited `is_banned()`, `is_strict_banned()`,
   `create_char_banned()` with it. Covers the `is_strict_banned` gate in
   `logind.lpc` `encoding()` (~line 136) and the
   `create_char_banned`/`is_banned` guest-jail check at world entry.
2. **IP-format checks bypassed for loopback** — `adm/daemons/logind.lpc`
   `encoding()` (~line 145): the `!ip_name` destruct and the
   digit-or-dot-only loop over `query_ip_number()` now only run when
   `band->is_local_site()` is false.
3. **Anti-flood** — the `MAX_LOGIN` (=500, effectively inert but patched
   for consistency) per-IP multi-login cap in `get_id()` (~line 314) now
   skips local connections. This older snapshot has NO reconnect throttle
   or per-IP logon_cnt cap in `logon()` (unlike the zheda fork).
4. **Uptime startup gate** — none exists; nothing to bypass.
5. **Admin account seeded** — id `fluffos`, pw `Mud@2026`, name 浮浮,
   via the real flow (`gb` → `no` → `new` → id → Chinese name → password
   x2 → email → gender `m` → gift screen `9`/`y`). Granted `(admin)` via
   `adm/etc/wizlist`. Verified `update /adm/daemons/band` recompiles
   successfully; character finalized in 南城客栈.

Save files (untracked, NOT gitignored — orchestrator must `git add`):
- `work/data/login/f/fluffos.o` (login save: password)
- `work/data/user/f/fluffos.o`  (player body save)

Retest: fresh normal registration (id `qinfxy`, 秦风) works end-to-end,
`score` renders, `quit` clean; fluffos login + wizard `update` works.
debug.log: only the pre-existing, CAUGHT preload error
`restore_object(): Illegal mapping format while restoring emote`
(corrupt archive seed `/data/emoted`, §7.7 class, intercepted by the
master's own catch — present before this pass). Test char saves removed.

## Fail-closed loopback retrofit (2026-07-24)

**Security correction, applied retroactively.** Same fix as
`xianlvqingyuanzheda`'s (shared `band.lpc` lineage): `is_local_site()`
originally treated an empty/non-string/malformed IP as "local"
(fail-open) — a stopgap for a since-fixed WASM driver bug. Tightened to
fail-closed:

```lpc
int is_local_site(string site) {
  if (!stringp(site)) return 0;
  if (site == "127.0.0.1" || site == "::1") return 1;
  if (strlen(site) >= 4 && site[0..3] == "127.") return 1;
  return 0;
}
```

Every gate that consults this helper (`is_banned()`,
`is_strict_banned()`, `create_char_banned()`, and `logind.lpc`'s
IP-format/anti-flood checks that call it) now treats an unparseable IP
as remote/untrusted. Retested: fresh registration (id `xlqygate`, name
秦岭峰) still completes end-to-end via loopback (`look`/`score`/`quit`
all correct); fluffos login + `update /adm/daemons/band` still succeeds
(`重新编译 /adm/daemons/band.lpc：成功！`). Zero new runtime errors. Test
char save removed after verification.
