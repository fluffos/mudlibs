# xianjianchuanqi — 仙剑狂侠2000 (Legend of Sword and Fairy — Crazy Hero 2000)

Archive: `仙剑传奇.rar`. Port: 40034. Status: **done** (boots clean and
quick, full registration flow verified end-to-end including a real
Chinese name).

## What this is

"仙剑狂侠2000", credited to 叶雨飞 (guofengcool@sina.com,
www.518518.com). Same "Century-family" `adm/single/{master,simul_efun}`
layout as `shiji`/`zhonghua2`/`shujian2008`/`shujianpiaoling2` — and its
`is_chinese()`/`check_legal_name()` match `shujian2008`'s exact shape
(the two-specific-byte GBK check, the `i<4||i>8||i%2` bound), though
`master.c`/`securityd.c` differ, so it needed its own verification
rather than blind copy. ~14,292 raw files, 12,243 after `.c`→`.lpc`
rename — the largest lib in this batch.

## Fixes applied

1. **AGENTS.md §15h**, exact `shujian2008` shape: `is_chinese()`'s
   two-specific-byte check → single-character CJK codepoint check;
   `check_legal_name(object ob, string name)`'s bound `i<4||i>8||i%2`
   (byte count + meaningless odd-byte-count rejection) → `i<2||i>4`,
   removed the `i%2==0` gate.
2. **AGENTS.md §15p (new standing policy, applied proactively)**:
   `/adm/daemons/network/dns_master` was in `adm/etc/preload` — removed
   it **before the first boot attempt** (not reactively after hitting a
   hang, unlike the investigation on `xianlvqingyuanzheda` just before
   this lib). Result: booted cleanly in well under 20 seconds, zero
   compile errors, no hang — validates the proactive-exclusion policy
   works as intended. Also checked `ftpd.lpc` (also in preload) for the
   same risk: its socket setup is deferred via `call_out(..., 2)`
   (2-second delayed, non-blocking to preload), so it was safely left
   in. `msgd` is referenced in preload but the file doesn't exist —
   harmless, `master.lpc`'s `preload()` gracefully skips missing files.
3. **New unguarded `write(read_file(...))` crash** (same bug *class* as
   `xianlvqiyuan`'s `cat()`/`BANNER` crash, found independently here):
   `cmds/usr/uptime.lpc`'s `main()` did
   `write(read_file("/log/nosave/LASTCRASH"));` completely unguarded.
   The actual file lives at `/log/static/LASTCRASH` instead — a
   hardcoded-path-vs-actual-location mismatch (not exactly a case
   mismatch this time, but the same root-cause shape). `read_file()`
   returning `0` for the wrong path crashed `write(0)` deep in
   `receive()`/`receive_message()`, killing **every single connection
   attempt** (not intermittent) with zero player-visible output. Fixed
   by guarding the `write()` call with `stringp()` rather than
   relocating the file (more robust — catches the general pattern, not
   just this one path). Also proactively hardened the shared
   `adm/simul_efun/file.lpc`'s `cat()` helper the same way, even though
   it wasn't the one that crashed this time (matches the shape found on
   `xianlvqiyuan`/`xianlvqingyuanzheda`).
4. **New conversion-tooling edge case**: the raw archive had a
   **directory** literally named `chuixue-jian.c` (kungfu/skill/), with
   the `.c` extension baked into the directory name itself, containing
   two files (`taiji-jian.c`, `liehuo-jian.c`) that are ALSO real,
   properly-named files/directories at the parent level — an orphaned
   duplicate/backup folder from the original archive's history. This
   confused `convert_lib.sh`'s blind `.c`→`.lpc` rename: it renamed the
   directory itself to `chuixue-jian.lpc` but couldn't rename the
   children inside (their `mv` targeted the pre-rename parent path,
   already gone), throwing two harmless `mv: cannot stat` warnings.
   Fixed by renaming the resulting directory to
   `chuixue-jian.orphaned-dir` so it can't be mistaken for a compilable
   object going forward — this is disposable duplicate content, not
   something any code path actually references.

## Interactive test result — full registration flow

Verified the complete registration path in one continuous connection:
BIG5-font prompt (`n`) → id `xjcqb` → confirm `y` → password `Pass1234`
(twice) → **real Chinese name `秦风`** → accepted, proceeds into
character attribute selection (根骨/膂力/悟性/身法 stat prompt). No
novel-character-name restriction in the `banned_name` list (bans
"金庸" — the author's own name — but no specific character names).

## lpcc sweep

12,243 files, 11,695 pass / 548 fail (95.5%). Memory stayed healthy
throughout the sweep — RSS peaked around 2.1GB mid-sweep (the largest
lib in this batch by file count) but recovered normally, host stayed at
~14GB free, no pressure requiring an early kill. Failure tail is the
usual shape (missing `message_combatd`/`skillN`/combat globals, some
syntax typos) — not triaged individually per AGENTS.md §6b/§13, boot +
full interactive registration test is the verification gate.

## Re-verification pass (2026-07-23)

Extended the interactive test past the password prompt (the original
pass stopped there) through full registration, `look`/`score`/`quit`.
Found and fixed one new regression, same class as fix #3 above:

- **Missing `/log/nosave/` directory**: `adm/simul_efun/file.lpc`'s
  `log_file()` (unlike `cat()`, already hardened in fix #3) still did a
  bare `write_file()`. `cmds/usr/quit.lpc`'s `do_quit()` calls
  `log_file("nosave/EXP", ...)` for an experience-sanity-check note
  *before* `me->save(); destruct(me);` — with the directory missing, this
  threw and **aborted the rest of `do_quit()`, skipping `me->save()`
  entirely** (silent character-progress loss on every single quit, not
  just a cosmetic log failure). Fixed by wrapping `log_file()`'s
  `write_file()` in `catch()` (matching the project's established
  pattern) and creating `work/log/nosave/`. Re-verified with a fresh
  registration (id `xjcqfixd`, name `秦岳`): `quit` now completes with no
  runtime errors.
- **Noted, not fixed (pre-existing, non-blocking)**: two other runtime
  errors appear in every boot/session and are unrelated to the above —
  (a) ~21 benign `*Object cannot be loaded during compilation.` traces
  during early preload, from `master.lpc`'s `log_error()` unconditionally
  calling `CHANNEL_D->do_channel(...)` to broadcast a compile *warning*
  before `CHANNEL_D` itself has preloaded (a new variant of AGENTS.md
  §15af's family — here the trigger is an unguarded daemon call inside
  `log_error()`, not a `wizardp()` check, and the driver's own top-level
  error handling absorbs each occurrence without cascading) — purely
  cosmetic (suppresses a wizard-channel broadcast of a warning nobody is
  online to see during preload), does not block boot or any tested flow.
  (b) `*restore_object(): Illegal mapping format while restoring dbase.`
  for `/clone/board/news_b` — the archive's own `data/board/news_b.o` seed
  file contains several bulletin-board posts with literal unescaped
  newline characters embedded inside quoted string values (2001-era save
  data, not something this conversion pass introduced), which this
  driver's stricter `restore_object()` parser rejects. Degrades
  gracefully (the news board just starts empty) and does not affect
  registration, `look`, `score`, or `quit` — a pre-existing content/seed-
  data gap, not a driver-compat bug, left unfixed per the project's
  "known non-critical content gap" policy.

## Driver rebuild / formatter / WASM pass (2026-07-23)

- **LPC formatter** run over all `work/*.lpc`: 12,241 total, 12,161
  written, 54 already-idempotent, 26 refused (self-check errors,
  expected on messy legacy code, not chased).
- **Native retest against the freshly-rebuilt driver**: clean boot, zero
  compile/fatal errors. Full registration + attribute-stat + gift-gender
  flow re-verified end-to-end in one continuous connection (id
  `qinlinge`, real Chinese name `秦岭岳`, gender `m`): entered the game
  world at 中央广场/Central Plaza with real NPCs (欧阳克 among them),
  `score` rendered the full character sheet, `quit` disconnected
  cleanly. Only the same two pre-existing, previously-documented
  non-blocking noise sources recurred (early-preload
  "Object cannot be loaded during compilation" traces, and the news_b
  `restore_object()` mapping-format warning) — no new regressions from
  either the reformat or the new driver build.
- **WASM test**: boots clean (only the expected non-fatal
  `socket_create`/`socket_bind` undefined errors from `ftpd.lpc`, no
  sockets package under WASM, same shape as documented elsewhere).
  Notably, this lib's visitor-counter code degrades gracefully under the
  WASM harness's log-subdirectory-copy gap (shows "零" visits instead of
  crashing the connection, unlike a sibling lib in this same pass) —
  registration proceeds past the English-name prompt and id-confirmation
  step cleanly. Did not push a full playthrough to completion (not
  required), but no IP-gating or other blocking issue was observed in
  the portion exercised.

## WASM-enablement pass (2026-07-23)

Standard four-change pass (AGENTS.md §1.3b/§1.3e/§1.5). Gates patched:

1. **Loopback always allowed** — `adm/daemons/band.lpc` `is_banned()`
   (top of function): short-circuit `return 0` for `127.0.0.1`, a leading
   `127.` prefix, and empty/malformed IP strings (WASM garbage). All
   `BAN_D->is_banned()` callers pass `query_ip_number(ob)`, so this covers
   the login ban gate in `adm/daemons/logind.lpc` `gb_big5()` (line ~119).
2. **Anti-flood / per-IP cap** — `adm/daemons/logind.lpc` `logon()`
   (line ~96): the `login_cnt > 3` per-IP concurrent-connection cap is now
   wrapped so it only runs for real remote IPs; loopback/malformed IPs
   skip it entirely (declared a new `string ip;` local).
3. **Uptime startup gate** — none in the login path (`UPTIME_CMD->main()`
   only prints uptime, is not a gate); nothing to bypass.
4. **sited.lpc** — `is_valid()`'s login call site and the entire
   `is_multi()` function are already commented out in this lib, so neither
   is an active gate; left as-is (documented, not patched).
5. **Admin account seeded** — id `fluffos`, pw `Mud@2026`, name 浮浮,
   registered through the normal flow (BIG5 `n` → id → confirm → password
   x2 → Chinese name → gift `0`/agree → email → gender). Granted `(admin)`
   via `adm/etc/wizlist` (`fluffos (admin)`). Verified `(admin)` status +
   `update` works.

Save files (both NOT gitignored — untracked; orchestrator must `git add`):
- `work/data/login/f/fluffos.o` (login object save: holds password)
- `work/data/user/f/fluffos.o`  (player body save)

Retest: fresh registration (秦风) reaches 中央广场, `score` renders;
fluffos `(admin)` + `update` works. The only runtime errors in debug.log
are the two pre-existing content bugs (an NPC 托钵僧 `heart_beat` bad
call_other, and `/quest/poem/yard` `do_test` bad `message()` arg) —
unrelated to the login path, fire on any boot. Test chars removed.
Note: id max length is 8 chars, so `fluffos` (7) fits.

## Fail-closed loopback retrofit (2026-07-24)

**Security correction, applied retroactively.** Items 1 and 2 above
originally treated an empty/non-string/malformed IP as "local"
(fail-open) — a stopgap for a since-fixed WASM driver bug. Tightened to
**fail-closed** in both spots:
- `adm/daemons/band.lpc`'s `is_banned()`: the short-circuit is now
  `if (stringp(site) && (site == "127.0.0.1" || site == "::1" ||
  (strlen(site) >= 4 && site[0..3] == "127."))) return 0;` — an
  unparseable/empty site string no longer bypasses the ban list.
- `adm/daemons/logind.lpc`'s `logon()`: the per-IP concurrent-connection
  cap is now skipped only when `ip` is a real loopback string (same
  condition as above); a malformed/empty IP now falls through to the
  normal (non-exempt) path.

Retested: fresh registration (id `xjcqgate`, name 秦岭峰) still reaches
中央广场 via loopback with `look`/`score`/`quit` all rendering correctly;
fluffos login + `update /adm/daemons/logind` still succeeds
(`重新编译 /adm/daemons/logind.lpc ...成功！`). No new runtime errors —
`debug.log` shows only the same two pre-existing content bugs noted
above plus the benign preload `log_error()`/`news_b` traces already
documented in the "Re-verification pass" section. Test char removed.

## WASM long-sit boot-watch (2026-07-24)

A 200s passive WASM connection (AGENTS.md §10.0) surfaced ~84
`Error in mudlib error handler: *Object cannot be loaded during
compilation` cascades during preload — many more than the ~21 traces
the earlier interactive pass caught and dismissed as "purely cosmetic".
Root cause, per AGENTS.md §7.10's third bullet (the `bxsj`/`bxsj1`
shape): `adm/single/master.lpc`'s `log_error()` (line 121, called for
every compile *warning*, not just errors) and `standard_trace()` (line
214) both call `CHANNEL_D->do_channel(...)` **unguarded**. `securityd`
preloads first (before `channeld`, far down `adm/etc/preload`), so the
very first `#pragma`/nosave-function warning during `securityd`'s
compile tries to `call_other` a not-yet-loaded `CHANNEL_D` mid-compile
— forbidden — which throws, re-enters `log_error()`/`standard_trace()`
for the new error, and cascades again since `CHANNEL_D` still isn't
loaded. Every one of the 9 daemons preloaded before `channeld` (and any
`#include`d warning inside them) re-triggers it.

Fixed by guarding both call sites with `find_object(CHANNEL_D)`
(mechanical §7.10 fix, no behavior change once `CHANNEL_D` exists):

```lpc
if (find_object(CHANNEL_D))
  CHANNEL_D->do_channel(this_object(), "err", message);
```

Re-ran the 200s boot-watch: zero cascades, only the expected non-fatal
`ftpd` preload failure (missing `sockets` package under WASM, §1.3c,
caught by `master.lpc`'s own `preload()` catch — same shape as
`xiakeyingxiong3`). Native sanity retest (id `xjcqrz`/`xjcqrs`, real
Chinese name, full attribute-roll → gift → email → gender flow):
reaches 中央广场, `score` renders correctly, `quit` saves cleanly with
zero errors in the driver log. Test char saves removed.
