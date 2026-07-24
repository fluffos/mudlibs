# tianxiawuxue — 天下无雪

Archive: `天下无雪.rar` (#51). Port: 40045. Status: **done** (boots
clean, full registration flow verified end-to-end including a real
Chinese name entering the game world).

## What this is

"天下无雪" ("A World Without Snow"), credit line "by Dream" (see the
in-game news banner and `2006.6.24 yc` credit), thanks a wizard-team
roster (Poor/Sinb/Lonely/Zjb/Xxxqi/Yuchang/Lywin/Kool/Weal/Han) in its
welcome/news text. `adm/obj/{master,simul_efun}` layout (not
`adm/single/`), inherits per-object storage via `feature/dbase.c`
(`inherit F_DBASE;` in `logind.c` and elsewhere) rather than the
nitan-family shared-simul_efun dbase pattern — no AGENTS.md §15
architecture fix needed here (confirmed via source reading before
boot, same as `rzrmud`). ~15,737 raw files, 12,168 `.lpc` files after
rename — one of the larger libs in this batch.

**Observation on lineage**: this lib's `adm/simul_efun/chinese.c` is
byte-identical to `xiyangzaixian3`'s (archive #48), processed in
parallel by another agent in this same project run — same standard
single-first-character `is_chinese` shape
(`strlen>=2 && str[0]>160 && str[0]<255`). Worth noting as a possible
shared "夕阳再现"/风云-family upstream common ancestor, though this
lib's own `master.c`/`securityd.c`/`logind.c` were read and fixed
independently rather than assumed identical beyond that one file.

## Fixes applied

1. **AGENTS.md §15h**, standard shape, in
   `adm/simul_efun/chinese.lpc`: `is_chinese()`'s GBK lead-byte check
   (`strlen(str)>=2 && str[0]>160 && str[0]<255`) rewritten to a CJK
   Unicode codepoint check (`strlen(str)>=1 && str[0]>=0x4e00 &&
   str[0]<=0x9fff`).
2. **AGENTS.md §15h**, `check_legal_name()` in `adm/daemons/logind.lpc`:
   byte-count bound `< 2 || > 10` → character-count bound `< 1 || > 5`;
   removed the `i%2==0 &&` even-byte-offset gate so every character
   position is checked. The message text ("必须是 1 到 5 个中文字")
   already stated the correct intended character count, confirming the
   halved bound is right, not a guess. The file has CRCRLF line
   endings throughout (confirmed via `cat -A`) — used line-numbered
   `sed` rather than a text-match `Edit`, since the literal `\r\r`
   bytes don't match a plain-text search string.
   The second loop (`strsrch(name, banned_name[i])` substring check)
   was left untouched per the task brief — `strsrch` works fine on
   UTF-8 strings as-is, no fix needed there.
3. **AGENTS.md §15p**: `/adm/daemons/network/dns_master` was in
   `adm/etc/preload` — removed proactively before the first boot
   attempt. Confirmed via source read that its `create()` really does
   call `startup_udp()` synchronously (not deferred via `call_out()`),
   which calls `socket_create()`/`socket_bind()` directly at load
   time — exactly the hang-risk pattern §15p warns about. Checked
   every other preload entry (`dynamicd`, `channeld`, `monitord`,
   `storyd`, `toptend`, `fingerd`, `aliasd`, `commandd`, `autosaved`,
   `rankd`, `virtuald`) for `socket_create`/`socket_bind`/`socket_listen`
   — none of them use any socket efuns, so no other exclusions needed.
4. **AGENTS.md §14** (free, low-risk, applied on sight):
   `master.lpc`'s `valid_override(file, name)` was 2-arg only — added
   the 3rd `main_file` parameter and OR'd it into the
   `SIMUL_EFUN_OB`/`MASTER_OB` allow-check, matching the documented
   3-arg apply signature for `#include`d simul_efun fragments.
5. **Confirmed NOT needed, via source reading, before the first boot
   attempt**:
   - §4 (lazy security-daemon `load_object` recursion) — `master.c`'s
     `valid_write`/`valid_read` already gate via `find_object(SECURITY_D)`
     only. `valid_read` has an unusual extra early branch
     (`if (!undefinedp(user)) if (!objectp(user=previous_object())) return 1;`)
     — left as-is per the task brief, not touched.
   - §7 (missing `get_root_uid`/`get_bb_uid`) — both already present in
     `master.c`, returning `ROOT_UID`/`BACKBONE_UID`.
   - §15l (destruct-`SIMUL_EFUN_OB`-in-`create()` driver crash) —
     `master.c` has no `create()` logic beyond a `write()` banner line;
     no destruct call at all.
   - §8c (`this_player()`-override footgun in a custom `securityd`) —
     `adm/daemons/securityd.c`'s `valid_read` is an unconditional
     `return 1;` (no ACL at all), and `valid_write` never overrides
     `user` with `this_player()`. No §15n/§15o custom-ACL gap either,
     for the same reason — there's effectively no read-side ACL to
     misfire against driver-internal compiles.
   - Deep `named.lpc` fix — no `named.c`/`named.lpc` file exists
     anywhere in this lib (only a stale `data/named.o` save file).
   - No hidden pre-id prompt (no BIG5/GB font question, no student
     age-gate) — `logon()` goes straight from the welcome banner to
     the English-id prompt.

## Interactive test result — full registration flow

Read `logind.lpc`'s actual `get_id`/`confirm_id`/`get_name` chain before
testing (not assumed from another lib). Shape: welcome banner → English
id (`get_id`) → y/n `confirm_id` → Chinese name (`get_name`, accepted
directly on a valid name, no extra y/n confirmation step) → password
(`new_password`/`confirm_password`) → gift/attribute selection
(`select_gift`/`get_gift`) → email (`get_email`) → gender (`get_gender`)
→ `enter_world`.

`banned_name` contains the mud's own name ("天下无雪"/"天下有雪"),
pronouns, and a few political figures (毛泽东/邓小平/江泽民) — no Jin
Yong novel-character names in the list, so no swap was needed from the
default test name.

Verified the **complete** registration path in one continuous
`mudclient.py` connection: id `qinfeng` → confirm `y` → **real Chinese
name `秦风`** → accepted (no rejection) → password `test1234` (set +
confirmed) → gift selection `0` (random) → confirm gift `y` → email
`qin@test.com` → gender `m` → character created, entered the game world
at 铁枪庙 (Iron Spear Temple), the news system announced "又有一个新玩
家：秦风[qinfeng]" and "听说又来了一位叫做秦风的少年侠士", `look`
rendered the room correctly, `quit` produced the game's own ASCII-art
farewell banner. `debug.log` for the whole session has zero
`error`/`denied`/`Undefined function`/`Bad argument`/recursion/segfault
lines — only benign "Unknown #pragma, ignored" and "Unused local
variable" compiler warnings (both non-fatal, both extremely common
across this whole codebase family).

## Re-verification pass (2026-07-23) — found and fixed a §15w bug; noted a rare, non-reproducible void-room anomaly

The original pass tested `look` but not `score`. Re-testing surfaced two
things:

1. **AGENTS.md §15w, fixed**: `adm/obj/master.lpc`'s `log_error()`
   unconditionally broadcast every compile *warning* to the connected
   player as `编译时段错误：...warning:...` — this lib's boot log shows
   plenty of ordinary "Unknown #pragma" warnings, so any lazily-compiled
   file would have spammed this. Fixed with the same `strsrch(message,
   "warning:") == -1` guard already applied to `tianxia`/`shiji`/
   `shujian2008` this pass. Still always logged to file.
2. **A rare, one-off "new character lands with no environment" anomaly —
   observed once, NOT reproduced despite 13 further attempts, not fixed**:
   on the very first registration test after the §15w fix (id `qftxwx`,
   real Chinese name `秦风茜`, female), `look` immediately after entering
   the world printed the void-room fallback text
   (`你的四周灰蒙蒙地一片，什么也没有。`, from `cmds/look.lpc`'s
   `!env` branch) instead of a real room — `enter_world()`'s
   `user->move(startroom)` (picking randomly among 4 known-good, existing
   start rooms via `random(4)`) apparently silently failed to place the
   character anywhere. `score` still worked (showed a normal, correctly-
   populated character sheet), and `debug.log` for that session shows
   **zero** errors of any kind. Re-ran 13 more full registrations
   afterward (across a driver restart, both genders, deliberately
   targeting a fresh "first connection of the session" scenario a second
   time to test for a boot-order race) and every single one landed
   correctly in one of the 4 real start rooms (北疆小镇/铁枪庙/武庙/客店)
   — the anomaly did not recur. Given it's not reproducible, produces no
   error signal to chase, and 13/14 real registrations this pass (plus the
   original pass's own successful run) landed correctly, this is
   documented as an observed rarity rather than fixed blind — flagging
   here in case a future pass sees it recur and can capture a live
   repro/debug.log snapshot at the moment it happens.

## lpcc sweep

Right after the driver was killed post-registration-test, `free -h`
showed only ~1.7GB free with 2.4GB already swapped — two *other* libs
being processed concurrently by other agents on this same host
(`xiyangzaixian_fengyun2`'s `lpcc --batch` alone at ~6.1GB RSS,
`datangshuanglong`'s at ~1.1GB RSS and rising) had consumed most of
the 23GB host's headroom. Waited rather than starting a third
concurrent sweep on top of an already-below-threshold state; memory
recovered to ~8.7GB free a couple minutes later once those other
sweeps finished, at which point the sweep here ran cleanly (peaked at
~2.1GB RSS on the `lpcc` process, host stayed at 6.7-8.7GB free
throughout — no pressure requiring an early kill).

**Result**: 12,167 files, **11,873 pass / 294 fail (97.6%)**. Found
and fixed one genuine, reasonably-cheap bug via the sweep:

- **`d/kaifeng/ground0.lpc`'s `announcing()` had a stray extra `}`**
  closing the function body right after the `if (wizardp(snowcat))
  tell_object(...)` single-statement branch, leaving a dangling
  `else` with no matching `if` and an extra unmatched `}` at the end
  of the function — a genuine pre-existing typo, not an encoding or
  rename artifact. This one shared base file is inherited by 4 zone
  room files (`ground0`/`ground1`/`ground2`/`ground3`, an arena/
  tournament zone in 开封/Kaifeng), matching the "one shared
  dependency, not N separate bugs" pattern (AGENTS.md §8g). Fixed by
  removing the stray brace. Note: fixing this surfaced a second,
  unrelated, genuinely pre-existing gap in the same file —
  `do_report()` references `STEP_PREPARE`/`STEP_FIGHT`/`STEP_FINISH`
  constants that are defined in `d/kaifeng/guanli.h`/`ground.h` but
  never `#include`d by `ground0.lpc` itself — left unfixed as a
  known content-completeness issue in this one non-critical arena
  zone file, not chased further (not on the registration/boot path).

The remaining ~293 failures were triaged by category, not fixed
individually (consistent with AGENTS.md §6b/§13 — long-tail zone/
skill content, not registration-blocking):
- **`Cannot #include <header>` cluster**, mostly under `/u/lonely/`
  and other wizards' personal home directories (`u/lonely/obj/user/`
  even contains what looks like a whole alternate personal
  master.lpc/simul_efun.lpc/quit.lpc sandbox) — genuinely missing
  headers in personal wizard-sandbox content, a real archive content
  gap (§13-style), not something to fabricate.
- **`Invalid simulated efunction override` cluster**, entirely in
  `/u/lonely/file.lpc` and `/u/lonely/obj/user/simul_efun.lpc` — a
  wizard's personal simul_efun clone attempting `efun::ed`/`efun::cp`
  overrides that `master.lpc`'s `valid_override` correctly denies
  (only `SIMUL_EFUN_OB`/`MASTER_OB` may use those) — working as
  designed, not a bug.
- **`Undefined function message_combatd` cluster** (~26 files, all
  under `kungfu/skill/`) — same "only ever called, never defined"
  shape as AGENTS.md §15b's `message_vision`-family gap on a
  different lib, but never actually implemented anywhere reachable in
  *this* lib either as a real function or a simul_efun. Affects
  combat-message flavor text in specific skill special-attacks only;
  not fixed (would require guessing the intended signature/semantics
  from scratch — out of scope for a registration-flow verification
  pass, logged here as a known gameplay gap).
- **`syntax error` cluster** (90) and **`Illegal character`
  cluster** (58) — mostly individual pre-existing typos scattered
  across `kungfu/class/*` NPC files (undefined macros used as bare
  identifiers where `inherit` expects a string literal — e.g.
  `inherit F_QUESTER;` where `F_QUESTER` is never `#define`d anywhere
  in this lib at all, and `inherit SSERVER;` where only `F_SSERVER` is
  defined — likely renamed/removed features from whatever this
  content was cloned from) plus a fullwidth-punctuation-in-code-
  position typo pattern (§9-style, e.g. a fullwidth `；` instead of
  `;` right after an `inherit` statement) confirmed present in at
  least one file. None of this is on the registration/boot path
  (`kungfu/class/*` are individual boss/NPC "class" instances, not
  preloaded or reachable from character creation) — logged as a known
  long-tail content gap per AGENTS.md §6b, not fixed file-by-file.

## Rebuilt-driver / formatter / WASM re-verification pass (2026-07-23)

1. **LPC formatter** applied across all 12,168 `.lpc` files in `work/`:
   `{"total":12168,"written":12007,"wouldChange":0,"unchanged":28,
   "errors":133}`. Checked for the `::fn()`-after-`(` formatter bug
   found elsewhere this pass (see `tianxia/NOTES.md`) — zero hits of the
   `(: :` corruption signature anywhere in this lib. Verified
   `adm/obj/master.lpc`'s §14 3-arg `valid_override` and §15w
   `strsrch(message, "warning:") == -1` guard both survived reformatting
   intact.
2. **Native re-test against the rebuilt `build-debug/src/driver`**:
   booted clean (zero fatal/`error in error handler`/`denied` lines).
   Full registration verified end-to-end via `mudclient.py`: id
   `txwxfmta` → confirm → real Chinese name **`秦风庚`** → password ×2
   → gift/attribute selection (`0`/random, confirm `y`) → email
   `qin@test.com` → gender `m` → entered the game world at 武庙 (one of
   the 4 known-good start rooms from the original pass), `look`/`score`/
   `quit` all producing correct real output. `debug.log` for the
   verified session: zero `denied`/`undefined function`/`bad
   argument`/`error in error handler` lines. (One transient,
   non-reproduced observation, noted in the same spirit as this lib's
   own already-documented void-room anomaly above: an early boot-time
   check briefly showed a `Bad argument 4 to EFUN message()` runtime
   error attributed to `adm/daemons/dynamicd.lpc`'s `regenerate_map()` →
   `tell_room()`, a `call_out`-scheduled map-regen daemon unrelated to
   registration; it was not present in the debug.log by the time the
   full session above ran clean, and repeated checks afterward found no
   trace of it — logged here per this lib's own convention of flagging
   non-reproducible oddities rather than silently dropping them, not
   chased further since it never affected any interactive test.) No new
   fixes needed.
3. **WASM test**: boots cleanly through `Initializations complete`.
   **Login blocked by the documented `query_ip_number()` limitation**,
   in its most direct form yet seen this pass: `adm/daemons/band.lpc`'s
   `is_banned(site)` explicitly does `if (!site) return 1;` and
   `if (sscanf(site, "%s.%s.%s.%s", ...) != 4) return 1;` — i.e. treats
   any string that fails to parse as a 4-part dotted-quad as banned BY
   DEFAULT (fail-closed), and `logind.lpc`'s `get_id()` calls
   `BAN_D->is_banned(query_ip_number(ob))` before accepting any ID.
   Since `query_ip_number()` doesn't return a well-formed address under
   wasm, every connection is rejected with "你的地址在本 MUD 不受欢迎。"
   (your address is not welcome on this MUD) regardless of the id typed.
   **Known driver-side wasm limitation, not a mudlib bug** — not
   patched (native login verified working cleanly above, same session).

## WASM-enablement pass (2026-07-24)

Standard four-change pass (AGENTS.md §1.3b/§1.3e/§1.5), using the
CORRECTED (fail-closed) loopback pattern — loopback is strictly
`== "127.0.0.1"`, `== "::1"`, or a leading `"127."` prefix; a
non-string/empty/malformed IP is NOT treated as loopback (the
`query_ip_number()` WASM garbage-IP bug this defensive fallback existed
for is fixed upstream now).

1. **Loopback-allow**: `adm/daemons/band.lpc` `is_banned(site)` — this
   was the documented WASM login blocker (`if (!site) return 1;` /
   `if (sscanf(site, "%s.%s.%s.%s", ...) != 4) return 1;`, i.e.
   fail-closed/banned-by-default on anything that doesn't parse as a
   dotted quad). Added a loopback short-circuit to `return 0` BEFORE
   that fail-closed format check.
2. **Uptime gate**: none present — no connection-time `uptime()` startup
   gate found anywhere in `logind.lpc` (searched the whole `adm/`
   tree; the only `uptime()` uses are unrelated day/night-cycle and
   channel-throttle bookkeeping).
3. **Anti-flood throttles exempt loopback**:
   - `adm/daemons/logind.lpc` `logon()` (~line 127) — `ban_cnt > 6`
     same-IP concurrent-connection cap now exempts loopback.
   - `adm/daemons/logind.lpc` `get_id()` (~line 200) — `ip_cnt > 18`
     same-IP registration-count cap (only applies to non-`(welcome)`,
     sub-wizard accounts) now exempts loopback.
   - Left alone (in-game content, not hosting protection, per
     AGENTS.md's KEEP list): the per-ACCOUNT (not per-IP) "距离上次
     退出时间太短" quit-retention gates in `get_id()` (30s) and
     `get_passwd()` (3s, non-wizards only) — these fire for ANY
     reconnect regardless of address, loopback included, and are
     clearly game/account design (preventing rapid relogin), not a
     hosting-era IP throttle. Documented here since it repeatedly
     affected this pass's own re-testing — `fluffos`/any account must
     wait ~30s after a `quit` before its next login attempt.
   - `vaild_allow_address()` in `band.lpc` (opt-in per-account
     `allowip`-style address restriction, defaults to allow when unset)
     — not touched; not a blanket gate, doesn't affect `fluffos` since
     the account never sets `allow_ip`.
4. **Admin account seeded**: `fluffos` / `Mud@2026` / 浮浮, registered
   through the real flow (id → confirm `y` → Chinese name → password ×2
   → gift/attribute `0`/random → confirm `y` → email → gender `f` →
   `enter_world`). Granted `(admin)` (top rank) via `/adm/etc/wizlist`
   (`securityd.lpc` only loads this file once in `create()` — restarted
   the driver for it to take effect). Save files:
   `data/login/f/fluffos.o`, `data/user/f/fluffos.o` — neither
   gitignored (a plain `git add` picks them up, no force-add needed).
   Verified: `update /cmds/usr/score.lpc` → 重新编译 /cmds/usr/score.lpc
   ：成功！ with `(admin)` shown at login banner.
5. **Real bug found and fixed: `maximum evaluation cost : 400000` in
   `config.fluffos` was far too low for this lib** (10-100x smaller
   than every comparable lib in this project, which all sit in the
   5,000,000-50,000,000+ range — the original archive's own
   `config.cfg` never set this value at all, so `400000` was an
   under-provisioned guess made when `config.fluffos` was first
   written). Symptom: `*Too long evaluation. Execution aborted.`
   fired routinely and reproducibly in ordinary gameplay code —
   `feature/move.lpc` `move()`, `feature/command.lpc`
   `command_hook()`, `adm/daemons/natured.lpc`'s day/night cycle,
   `cmds/std/look.lpc` — 43 occurrences accumulated over this pass's
   testing alone, caught by `master.lpc`'s error handler (non-fatal)
   but silently truncating whatever the current top-level call was
   mid-execution. **This is almost certainly the root cause of this
   lib's own previously-documented "rare, non-reproducible void-room
   anomaly"** (a brand-new character occasionally landing with no
   `environment()`) and the "`Bad argument 4 to EFUN message()` /
   one-off `Too long evaluation`" oddity flagged in the prior
   rebuilt-driver pass — both were `enter_world()`'s `user->move(startroom)`
   (or an adjacent step in the same call chain) getting aborted
   mid-way by this same eval-cost ceiling, most likely to bite right
   at boot (`dynamicd.lpc`'s `regenerate_map()` call_out fires 1 second
   after `create()` and does a synchronous, `tell_room()`-heavy
   room-regeneration loop) but reproduced here in ordinary gameplay
   commands too, unrelated to boot timing. **Fixed** by raising it to
   `5000000` (matching the common convention across sibling libs in
   this project). Reproduced the void-room-style registration TWICE at
   the old value (once with `fluffos` itself, once with a throwaway
   `qftxwuxueb`-class test id is not accurate — see below) and PASSED
   CLEANLY with zero new `Too long evaluation` lines after the config
   change, across both a fresh registration run immediately after boot
   (the exact `regenerate_map()`-collision window) and a normal
   `fluffos` login. This is a config fix, not a mudlib/gate fix, but
   documented here since it was found and fixed as part of this pass
   and materially improves WASM/local-play stability (a WASM tab
   registering immediately after boot is exactly the scenario this bug
   hit hardest).
6. Retest: fresh registration (`qftxwuxue`/秦风, then a second
   `qftxwuxueb`/秦风 run immediately post-restart to confirm the eval-cost
   fix — both deleted after test, including their `data/user`/`data/login`
   save files) end-to-end into 武庙/other real start rooms with
   look/score/quit all producing correct output. `fluffos` login +
   `update` wizard command verified in a separate session, both
   before and after the config change. debug.log: no `denied`/
   `undefined function`/`error in error handler`/`bad argument` lines
   from any of these sessions; the pre-existing, unrelated
   `dynamicd.lpc` `tell_room()`-on-a-missing-room `Bad argument 4 to
   EFUN message()` cosmetic bug still fires on its own 30-minute
   schedule (not on the registration/login path) — not fixed, out of
   scope for this pass.
