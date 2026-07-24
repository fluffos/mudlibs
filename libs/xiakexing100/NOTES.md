# xiakexing100 — 侠客行一百

Archive: `侠客行100.rar`. Port: 40037. Status: **done** (boots clean and
quick, full registration flow verified end-to-end including a real
Chinese name).

## What this is

"侠客行一百", credited to "Coollizard & xkx100 2003-2004",
http://yoyo.xm.fj.cn/xkx100, up since 2001-01-14 per its own connection
banner. Same "Century-family" `adm/single/{master,simul_efun}` layout
as `shiji`/`zhonghua2`/`shujian2008`/etc. ~14,227 raw files, 12,209
after `.c`→`.lpc` rename — the largest lib processed in this session
run.

## Fixes applied

1. **AGENTS.md §15h**, standard shape: `is_chinese()`'s GBK lead-byte
   check → CJK codepoint check; `check_legal_name()`'s byte-count bound
   `< 4 || > 10` → character-count bound `< 2 || > 5`, removed the
   `i%2==0` even-byte-offset gate.
2. **Confirmed NOT needed, via source reading**: no §4 fix
   (`master.c`'s `valid_write` gates via `find_object` only,
   `valid_read` is a bare `return 1;`); no deep `named.lpc` fix
   (`named.c` exists but lacks the `PATH()`/sliding-window pattern seen
   in the nitan-family shape — a simpler, different implementation
   here).
3. **AGENTS.md §15p**: `/adm/daemons/network/dns_master` was in
   `adm/etc/preload` — removed proactively before the first boot
   attempt. Booted clean in under 20 seconds, zero compile errors, no
   hang.

## Interactive test result — full registration flow

No hidden pre-id prompts. Verified the complete registration path in
one continuous connection: id `xkxbtest` → confirm `y` → **real Chinese
name `秦风`** (avoiding "韦小宝"/Wei Xiaobao — a famous Jin Yong
character found in this lib's `banned_name` list) → accepted, proceeds
straight to "请设定您的密码：".

## lpcc sweep

12,209 files, 12,118 pass / 91 fail (99.3%). Failure tail dominated by
an `accept_hit` type-mismatch cluster (120 of the reported instances
across files, string vs object argument), plus the usual handful of
missing globals/syntax typos — not triaged individually per AGENTS.md
§6b/§13. Memory stayed comfortably healthy throughout the sweep despite
this being the largest lib in the current session run (~13GB free
consistently, lpcc RSS peaked well within normal range, no pressure
requiring an early kill).

## Re-verification pass (driver rebuild + LPC formatter + WASM build)

- **Reformatted** all 12209 `.lpc` files under `work/` with
  `tools/lpc-syntax/format-corpus.mjs`: 10795 written, 1414 already
  idempotent-clean, 0 refused. Verified the earlier §15ae fix
  (`feature/command.lpc`'s `command_hook` staying `nomask` with
  `private` still commented out) survived unchanged.
- **Native retest against the freshly-rebuilt driver**
  (`~/src/fluffos/build-debug/src/driver`, rebuilt from latest upstream
  master): clean boot, zero fatal errors in `log/debug.log`. Full
  registration flow re-verified with a fresh real Chinese name
  (`秦墨`/id `xkxbrew`, then `秦徽`/id `xkxbrev`), reaching an actual
  starting room, `look`/`score`/`quit` all producing correct output —
  also separately re-confirmed post-login command dispatch (the §15ae
  fix) via a reconnect + `look` on the saved character. No regressions
  from either the driver rebuild or the reformat.
- **WASM build test found and fixed a real, pre-existing mudlib bug**
  (`scripts/wasm_client.js` against `~/src/fluffos/build-wasm/src`):
  boot itself was clean, but every connection attempt silently stalled
  right after the login banner, never reaching the id prompt at all —
  no fatal error printed anywhere. Root-caused by reproducing the exact
  same stall **natively** (temporarily moving aside
  `work/log/MUDVISITOR`, the untracked runtime-state visitor-counter
  file `adm/daemons/logind.lpc`'s `howmany_visitor()` reads on every
  connection): `read_file(VISITORS)` returns a non-string (`0`) when the
  file doesn't exist, and the un-guarded `sscanf(content, "%s %d", ...)`
  that follows throws `Bad argument 1 to sscanf` — uncaught, this aborts
  the rest of `logon()` silently (confirmed via `debug.log`'s
  `执行时段错误：*Bad argument 1 to sscanf`), before the player ever sees
  an id prompt. This is a **genuine pre-existing mudlib bug**, not a
  WASM-specific driver gap — it just never manifested in earlier native
  testing passes because `MUDVISITOR` already existed on disk from prior
  test runs (it's untracked/gitignored runtime state, not shipped in the
  original archive's git history), whereas `scripts/wasm_client.js`'s
  in-memory filesystem deliberately never copies `log/`'s *contents*
  (only creates the empty directory, by design, to keep the harness
  fast), so a WASM run is effectively always a "genuinely fresh archive,
  first boot ever" scenario for this file — the exact condition that
  triggers the bug. **Fixed**: added a `stringp(content)` guard (return
  `0`/treat as "no visitors yet" if the file doesn't exist) to both
  `howmany_visitor()` and the identically-shaped `howmany_card()`
  (`GIFTCARD` file, same pattern, fixed proactively). Re-verified: (a)
  natively, with `MUDVISITOR` moved aside, connection now proceeds
  straight to the id prompt showing "第一位访问者" and a full
  registration completes cleanly, zero `debug.log` errors; (b) under
  WASM, full registration now also completes end-to-end (id `xkxwasmz` →
  real Chinese name `秦岫` → stat roll → gift/email/gender → landed in an
  actual starting room, `look`/`score`/`quit` all producing correct
  output). This lib has no IP-format-dependent login gate, so once this
  fix was in place it was fully playable under WASM too.

## WASM-enablement pass (loopback-allow / admin seeding)

Applied the four standard WASM-first changes (AGENTS.md §1.3b/§1.3e/§1.5).

### 1. Loopback always allowed — ban list + per-IP throttles (`adm/daemons/logind.lpc:73-124`)
`logon()` ran `BAN_D->is_banned()`, an `in_login > 10` per-IP
in-progress-login throttle, and `BAN_D->is_multi()` (per-IP character
cap) unconditionally. Added an `is_local` local computed once and
gated all three on `!is_local`.

**Written fail-closed from the start (2026-07-24)**: `is_local =
(stringp(lip) && (lip == "127.0.0.1" || strsrch(lip, "127.") == 0))` —
only a genuine loopback-shaped string is treated as local; an
unparseable/non-string ip is NOT local and still goes through the ban
list and both throttles. (An earlier partial pass on this file had used
the fail-open shape seen on this batch's other four libs — `!stringp(lip)
|| lip == "127.0.0.1" || strsrch(lip, "127.") == 0 || sscanf(lip,
"%*d.%*d.%*d.%*d") != 4`, which let ANY malformed ip bypass every gate —
but that was corrected to the fail-closed form above before this pass
was considered complete; see the sibling libs' NOTES.md entries for the
full rationale: the old WASM driver bug that produced garbage
`query_ip_number()` output is now fixed, so there is no reason left to
treat "can't parse it" as "must be loopback".)

### 2. Uptime startup gates — none present
No `uptime() < N` connection-rejection gate exists in this lib. All
`uptime()` hits are in-game content: gambling rooms (`d/*/duchang*.lpc`,
`npc/douji`, `npc/saigui`), NPC/room respawn timers, cooldowns, and
`adm/daemons/autosaved.lpc`'s once-per-boot data-file initialization
(`if (uptime() < 400) { ...write_file... }` — first-boot bootstrap of
some `/data/*` flags, not a connection gate). Nothing to bypass.

### 3. Anti-flood throttles — covered by item 1
No separate registration-throttle daemon exists; the per-IP protection
in this lib IS the `in_login`/`BAN_D->is_multi()` checks patched above,
already loopback-exempt.

### 4. Admin account seeded — `fluffos` / `Mud@2026` / 浮浮
Registered through the real flow (id `fluffos` → `y` → 浮浮 →
`test1234`/confirm → talent `1`/`20`/`20`/`20`/`y` → personality `0` →
email → `m`), landed in a random starting room. Granted `(admin)` by
appending `fluffos (admin)` to `adm/etc/wizlist` (`securityd.lpc`'s
`get_status()` reads this file into `wiz_status`). Verified: login as
fluffos shows `目前权限：(admin)`, `update /adm/daemons/logind` →
`重新编译 /adm/daemons/logind.lpc：成功！`.

**Save files for the orchestrator to force-add** (untracked, not
gitignored):
- `libs/xiakexing100/work/data/user/f/fluffos.o`
- `libs/xiakexing100/work/data/login/f/fluffos.o`

### Bonus fix: `quit`/`exit` was silently broken for EVERY player (pre-existing, not WASM-related)

While verifying the admin account's `quit`, discovered `cmds/usr/exit.lpc`'s
`savequit()` never actually let anyone quit: `int a = 1;` is reassigned
inside the `if (link_ob) {...}` branch to `a = (link_ob->save())`, and
`link_ob` (`me->query_temp("link_ob")`) is the `/clone/user/login`
connection object set by `enter_world()`/`reconnect()` on **every**
login, not just a rare possession/reconnect edge case. FluffOS's
`save_object()` efun returns the byte-size of the text written on
success (confirmed by reading `~/src/fluffos/src/vm/internal/base/object.cc`'s
`save_object_recurse()`, which accumulates and returns `textsize`), not
a 0/1 boolean — so `a` ends up as some multi-hundred-byte count, and the
final check `if (a == 1 && me->save())` was false for virtually every
quit, for every character, admin or not. The player saw all the normal
quit text ("你共停留了...欢迎下次再来！") followed immediately by a scary
"警告：档案保存失败，无法退出游戏，请马上联系巫师解决。" and was never
actually disconnected (`destruct(me)` never reached). Confirmed present
verbatim in the original raw archive (`raw/xkx100/cmds/usr/exit.c`), so
this is a decades-old author typo/driver-assumption mismatch, not
something introduced by this project's conversion or by the WASM pass.
**Fixed**: `if (a == 1 && me->save())` → `if (a && me->save())` (test
truthiness, matching the efun's actual 0=fail/nonzero=success
contract). Verified with a fresh registration and with the fluffos
admin account: `quit` now completes cleanly with no warning and no
lingering interactive body.

### Retest (2026-07-24)
Fresh boot, fresh registration (id `qinlanx`/`qintestb`, real Chinese
names 秦岚新/秦测三) through `look`/`score`/`quit` — landed in a
starting room, correct `score` output, clean quit with no warning.
`fluffos`/`Mud@2026` admin login verified: `look` then `update
/adm/daemons/logind` → `重新编译 ... 成功！`, then clean `quit` (the
bonus fix above). Zero `执行时段错误` lines in `debug.log` across the
whole session (the one hit from an unrelated missing-`log/nosave/`
directory surfaced only while probing the quit bug with the `call`
wizard command directly on a userp target — `log/` is fully
gitignored/regenerated at boot, not a real defect worth chasing
further here). Test characters removed afterward; fluffos kept.
Reverted an incidental `data/topten.o` leaderboard diff caused by the
test registrations (pre-existing tracked file, not meant to churn from
QA runs).
