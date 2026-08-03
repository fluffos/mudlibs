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
byte-identical to `xyzx3`'s (archive #48), processed in
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
(`xyzxfy2`'s `lpcc --batch` alone at ~6.1GB RSS,
`dtsl2`'s at ~1.1GB RSS and rising) had consumed most of
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

## 深度功能测试 / Deep functional test (2026-07-24, round two)

First real *playthrough* pass on this lib per AGENTS.md §10.7. Read
`doc/help/newbie{,1,2,3,4}` and `doc/help/combat` in full first — note
that this content is recycled from a DIFFERENT, unrelated upstream game
(it repeatedly names itself "晚霞"/"红尘", uses "hc" as its own
abbreviation, and describes a Yangzhou-centric map with a `gc` central
square and sects/mechanics that don't match this installation at all)
and does not reflect this lib's actual starting rooms or geography —
harmless (nothing crashes because of it) but a documentation-quality
observation, not fixed, out of scope. `README.md`'s own description
(four random start rooms, sect/拜师/江湖历练) is accurate and was used
instead. Native driver (`build-debug`), one continuous character
(`shenmubai`/沈慕白) across many `scripts/mudclient.py` sessions, each
session's own close (no `quit`) itself exercising an unclean/net-dead
disconnect.

**Task directive: check for the `tianxia`-sibling `changed_match_path`
bug first.** This lib does **NOT** share it. `tianxia`'s bug was a
never-defined `changed_match_path(mapping, string)` simul_efun restored
as a bare passthrough to the real `match_path()` efun. `tianxiawuxue`
has no such function anywhere (confirmed via `grep -rn
changed_match_path` — zero hits) and uses a completely different,
architecturally-correct storage mechanism: `feature/dbase.lpc` (`inherit
F_TREEMAP;`, not a simul_efun-based property store) delegates
multi-segment `"a/b"`-style property paths to `feature/treemap.lpc`'s
own `_query()`/`_set()`/`_delete()` — genuine hand-written recursive
nested-mapping descent (`explode(prop, "/")`, walk one segment per
level), never touching the real `match_path()` efun at all (confirmed
`grep -rn '\bmatch_path\b'` outside `doc/` has zero hits in `work/`).
Traced `feature/command.lpc`'s bare-directional-movement fast path
(`environment()->query("exits/" + verb)`) by hand against
`treemap.lpc`'s `_query()` and confirmed it correctly returns the
nested `exits["west"]` value. **Live-verified this explicitly, per the
task's own instruction to test BOTH forms**: registered 沈慕白, and
both bare `west`/`east`/`north`/`south`/`northwest`/`out` etc. AND `go
<direction>` correctly moved the character through 20+ distinct rooms
across several zones (长安/北京城2/华山派练武场/丐帮地下暗道) with no
asymmetry between the two forms. No fix needed here — noted for the
record since the task specifically asked.

**Test character** (kept, not cleaned up, as playthrough evidence): id
`shenmubai`, Chinese name **沈慕白** (male), password `TxTest2026#`.
Random gift roll: 膂力23/悟性20/根骨22/身法15. Final state: at a
`valid_startroom` (location re-randomizes on every fresh login — see
bug/observation below, so "current" location is not meaningful state);
no sect/skill acquired (see below); inventory `Cloth`/`Trans site`
(魔法传送帖); credits/deaths reset to 0 after an unavoidable mid-session
driver restart (§10.5-consistent — only `save`/`quit` persist state, an
in-memory-only death from before a restart does not survive it, which
is expected, not a bug). Saves: `work/data/user/s/shenmubai.o`,
`work/data/login/s/shenmubai.o`.

### Bug found and fixed (NEW class): safe-sparring training dummies (`mu-ren`/`muren`, 9 files) never set `can_speak`, so `fight`/`hit` route every spar attempt through the REAL lethal `kill_ob()` path instead of the dummy's own carefully-written safe `accept_fight()` — live-reproduced player death on the very first hit

**Files: `d/city/npc/mu-ren.lpc`, `d/shaolin/npc/mu-ren.lpc`,
`d/shaolin/obj/mu-ren.lpc`, `d/shaolin/npc/obj/mu-ren.lpc`,
`d/quanzhen/npc/muren.lpc`, `d/mingjiao/obj/mu-ren.lpc`,
`d/mingjiao/npc/obj/mu-ren.lpc`, `d/shushan/obj/muren.lpc`,
`d/working/obj/mu-ren.lpc`.**

- **How this was found**: per AGENTS.md §10.7 item 3 and this task's
  explicit instruction, went looking for the lib's own safe-sparring
  mechanism before risking a real fight. Found `d/shaolin/npc/mu-ren`
  (a training-dummy NPC placed in `d/city2/wuchang.lpc`'s 练武场,
  reached via `trans tam` + 6 hops) with an elaborate, obviously
  intentional `accept_fight(object ob)` override: it copies the
  attacker's own skills/skill-maps/stats onto itself
  (`ob->query_entire_dbase()` → `me->set(...)` for str/int/con/dex/
  qi/jing/neili/jiali), sets `"no_die": 1` on itself, and tracks
  `fight_times`/`last_fighter` so it "breaks" after repeated use rather
  than ever dying — unambiguously a purpose-built, always-safe practice
  partner, matching `help combat`'s own promise that `fight`/`hit`
  never cause real death ("不会真的受伤"). Used `fight mu ren` against a
  **fresh, unequipped, level-0 character** expecting a guaranteed-safe
  bout — and the training dummy killed the character outright on its
  second real exchange (`你口中喷出几口鲜血，倒在地上,死了！`, death
  counter went from 0 to 2 across two separate spar attempts before a
  later driver restart reset the unsaved counter back to 0).
- **Root cause**: `cmds/std/fight.lpc`'s `main()` only calls
  `obj->accept_fight(me)` inside an `if (obj->query("can_speak")) {
  ... }` branch; the `else` branch (taken whenever `can_speak` is
  unset/falsy) skips `accept_fight()` entirely and instead runs
  `me->fight_ob(obj); obj->kill_ob(me);` — REAL, lethal combat, the
  exact same call `kill.lpc` would make. `cmds/std/hit.lpc` has the
  identical shape. None of the 9 `mu-ren`/`muren` dummy files ever
  `set("can_speak", 1)` (confirmed: `can_speak` appears nowhere in any
  of them before this fix), so `query("can_speak")` returns
  `0`/undefined for all of them, and EVERY `fight`/`hit` against a
  training dummy — lib-wide, in every zone that has one — silently took
  the lethal branch instead of the safety-net branch its own code was
  clearly written for. Confirmed `accept_fight()` is called from
  NOWHERE else in the entire codebase (`grep -rn 'accept_fight('
  work/cmds work/feature work/inherit`, only hit: `fight.lpc`'s one
  call site plus the base definition in `inherit/char/npc.lpc`) — so
  `fight` really is the sole intended entry point, and this
  `no_die`-flagged, stat-mirroring dummy's `accept_fight()` was
  provably 100% dead code before this fix, for every single instance
  in the archive.
- **Why this isn't the "a safe spar that isn't perfectly safe" design
  choice AGENTS.md §10.7's scope note warns against fixing**: that
  caution is about `help combat`'s own documented risk when the skill
  gap between two REAL opponents is too large (an intentional balance
  mechanic). This is categorically different — a single-purpose,
  `no_die`-flagged practice-dummy NPC whose entire elaborate
  stat-mirroring safety mechanism is architecturally unreachable via
  the only command that could ever invoke it, contradicting both its
  own code's obvious purpose and the command's own player-facing help
  text. Confirmed byte-identical in the pristine raw archive
  (`raw/mud/world/kungfu/…` n/a — dummy files are under `d/`, checked
  `raw/mud/world/d/city/npc/mu-ren.c` etc.; the `can_speak`-less shape
  matches `work/` exactly) — an original-game bug, not introduced by
  conversion, but squarely "making its own already-intended logic
  actually work" per the scope note's own test, not a balance judgment
  call.
- **Fix**: added `set("can_speak", 1);` right after `set_name(...)` in
  all 9 files (the dummy's own `long` description already says "如同
  真人一般" — "as lifelike as a real person" — so this is consistent
  with its own flavor text, not an invented property). This is a
  narrow, local, zero-blast-radius fix: it does NOT touch the shared
  `fight.lpc`/`hit.lpc` command files (which route hundreds of other,
  genuinely-hostile silent NPCs system-wide and were deliberately left
  alone, since auditing whether ALL of those should also gain a
  safe-negotiation path is a design question outside this task's
  scope), and does not affect any other NPC in the lib.
- **Verified live, before/after**: before the fix, `fight mu ren`
  (matchable id is the two-word `"mu ren"`, not `"muren"`) against the
  `d/city2/wuchang` dummy killed the fresh test character on the second
  exchange. After the fix (recompiled via the `fluffos` admin's `update
  /d/shaolin/npc/mu-ren` etc., all 9 files individually confirmed
  "重新编译 ... ：成功！", then a full driver restart to be certain), the
  identical `fight mu ren` sequence against the same dummy correctly
  ran several rounds of real-looking combat log text, then the dummy
  **conceded** (`木人胜了这招，向后跃开三尺，笑道：承让！`) — matching
  the sibling `tianxia` lib's own documented safe-spar-concedes shape
  — the character survived with `<气>` (stamina) depleted but no
  injury, gained `+1 实战经验`/`+1 潜能`, and `你共死亡` stayed at `0`.
  `debug.log` showed zero new lines from either the pre-fix death or
  the post-fix safe spar.
- **This is a NEW bug class for AGENTS.md's catalog** — see draft
  below (not added to AGENTS.md directly per this task's instructions).

### Bug found and fixed: `kungfu/class/gaibang/hong.lpc`'s `attempt_apprentice()` wraps two rejection conditions in `mapp()`, which is always false for a boolean/int comparison result, permanently bypassing both intended sect-entry gates

**File:line: `kungfu/class/gaibang/hong.lpc:75` and `:79`.**

- **How this was found**: while looking for an accessible sect to
  exercise the organic `apprentice` path with `shenmubai`'s randomly
  rolled (and comparatively weak) stats, read every `attempt_apprentice()`
  override in `kungfu/class/*/*.lpc` looking for one without a
  hard-to-satisfy stat gate. 洪七公 (`hong.lpc`, 丐帮/Beggars' Sect's
  17th leader) has:
  ```lpc
  if (mapp(ob->query("shen") < 100000)) {
    command("say " + RANK_D->query_respect(ob) + "的侠义不够啊，怎么能成为我老叫花的徒弟呢");
    return;
  }
  if (mapp(ob->query_skill("huntian-qigong") < 600)) {
    command("say " + RANK_D->query_respect(ob) + "的本派内功不够啊，怎么能成为我老叫花的徒弟呢");
    return;
  }
  ```
  `ob->query("shen") < 100000` and `ob->query_skill(...) < 600` are
  both relational-comparison expressions that evaluate to plain `int`
  `0`/`1` — `mapp()` is the driver's mapping-type predicate and returns
  `0` (false) for ANY non-mapping argument, including these ints. So
  `mapp(<anything> < <anything>)` is unconditionally `0`, the `if`
  body (the rejection) can NEVER execute, and both gates are dead code:
  every character, regardless of actual `shen`/skill level, sails past
  these two checks. This sits directly between a correctly-formed
  guard two lines above it (`if ((int)ob->query_str() < 30 || (int)
  ob->query_con() < 25) { ...; return; }`, no `mapp()`) and another
  correctly-formed guard four lines below it (`if (mapp(ob->query
  ("family")) && ...)`, where `mapp()` is used CORRECTLY because
  `ob->query("family")` really is expected to be a mapping) — the
  `mapp()` wrapper on the two broken lines is an obvious copy/paste
  artifact from the third guard's *correct* usage of `mapp()`, applied
  to the wrong kind of expression on the two lines above it.
- **Confirmed present byte-identical in the pristine raw archive**
  (`raw/mud/world/kungfu/class/gaibang/hong.c` lines 78/82) — an
  original-game bug, not introduced by conversion.
- **Fix**: removed the erroneous `mapp()` wrapper, restoring plain
  boolean guards matching the surrounding code's own established
  pattern:
  ```lpc
  // BEFORE:
  if (mapp(ob->query("shen") < 100000)) { ...; return; }
  if (mapp(ob->query_skill("huntian-qigong") < 600)) { ...; return; }
  // AFTER:
  if (ob->query("shen") < 100000) { ...; return; }
  if (ob->query_skill("huntian-qigong") < 600) { ...; return; }
  ```
- **NOT fully live-verified end-to-end** — recompiled cleanly via the
  `fluffos` admin's `update /kungfu/class/gaibang/hong` (confirmed
  "重新编译 ... ：成功！", no compile errors), but reaching 洪七公 himself
  (`d/city/gbxiaowu.lpc`, "林间小屋") turned out to be gated behind a
  SEPARATE, legitimate design mechanism: the only mapped entrance
  (`d/city/gbandao.lpc`, "暗道") has its own `valid_leave()` override
  that blocks any non-丐帮 character from proceeding further via an NPC
  (简长老) that physically attacks and repels outsiders — i.e., you
  must already be in the sect to reach the sect leader who recruits
  you, an unrelated chicken-and-egg gate this task's time budget didn't
  allow fully tracing (possibly a different, unmapped entrance exists;
  not investigated further). The `mapp()` logic error itself is
  unambiguous from static reading and the clean recompile confirms no
  syntax regression, but the actual in-game consequence (does a
  low-`shen` character now get recruited, live) is explicitly
  **unverified**, flagged honestly rather than claimed.

### Observation (NOT fixed — genuinely ambiguous, documented per the task's own instruction rather than guessed): fresh characters' spawn location is re-randomized on literally EVERY future login, not just the first, because `enter_world()`'s success branch never persists `"startroom"`

**File: `adm/daemons/logind.lpc`, `enter_world()`, contrast the success
branch (~line 690) against the fallback branch (~line 693-695).**

```lpc
if (file_size(startroom + ".lpc") > 0 && !catch(load_object(startroom)))
  user->move(startroom);          // <-- no user->set("startroom", ...) here
else {
  user->move(start_room[i]);
  startroom = start_room[i];
  user->set("startroom", start_room[i]);   // <-- only the fallback persists it
}
```

- **How this was found**: registered `shenmubai`, landed at 客店
  (`/d/city2/kedian`). Later, after an unavoidable driver restart mid-
  session (destroying the live in-memory object, forcing a real
  `restore()` + `enter_world()` fresh-login path rather than a
  `reconnect()`), the SAME character landed at a completely different
  room (北疆小镇, one of the other 3 `start_room[]` entries) despite
  never having died or explicitly relocated. Traced this to
  `enter_world()`: `startroom = user->query("startroom")` is read on
  every login, but the only two places that ever WRITE it are (a) this
  function's own fallback branch (only reached if the previous
  `startroom` failed to load — not the normal case), and (b)
  `cmds/usr/save.lpc`'s `save` command, and ONLY when the player is
  standing in a room with `set("valid_startroom", 1)` at the moment
  they type `save`. Confirmed no other write site exists
  (`grep -rn 'set("startroom"' work/` → exactly these two). The
  periodic `adm/daemons/autosaved.lpc` daemon (runs every ~600s on
  every connected player) calls the bare `->save()` method, NOT the
  `save` command's logic, so it does not set `startroom` either. Net
  effect: unless a player deliberately types `save` while standing in
  one of the four starter rooms, EVERY subsequent full login (not just
  the first) re-rolls a fresh random start room from
  `start_room[random(4)]`.
- **Why this is genuinely ambiguous, not a clear-cut bug**: (1)
  Confirmed byte-identical in the pristine raw archive
  (`raw/mud/world/adm/daemons/logind.c` lines 704-717) — an original,
  never-since-fixed shape, not introduced by this project's conversion.
  (2) The `save` command's own player-facing text —
  "当你下次连线进来时，会从这里开始" ("next time you connect, you'll
  start from here") — explicitly frames binding a spawn point as an
  opt-in player action, which reads as consistent with "random until
  you bind" being the intended default, not an oversight. (3) However,
  the sibling lib `tianxia`'s equivalent `enter_world()` (`libs/tianxia
  /work/adm/daemons/logind.lpc` ~line 1049) DOES call `user->set
  ("startroom", startroom)` in BOTH branches, making a first-time-random
  spawn point sticky from then on automatically — a meaningfully
  different (and arguably more standard) design for the same lineage
  family, which raises real doubt about whether the missing call here
  was actually intentional or itself an unnoticed upstream bug that
  `tianxia` simply doesn't share.
- Per AGENTS.md §10.7's explicit scope note (which uses almost this
  exact shape — "a 'safe' spar that isn't perfectly safe" — as a
  worked example of a design choice NOT to fix) and the task's own
  "when genuinely unsure, document, don't guess" instruction: left
  UNTOUCHED. Documented here for a human maintainer's judgment call,
  not silently ignored.

### Sixth independent occurrence of the known driver-fatal crash class (AGENTS.md §10.8) — corroborating, not a new mudlib bug

During this pass's net-dead soak window (character disconnected
uncleanly, driver left running idle ~12 minutes with no player
commands), the driver process itself aborted:
```
md: debugmalloc: attempted to free non-malloc'd pointer <addr>
Aborted (Signal sent by tkill() <pid> 1000)
```
with a full C++ backtrace through `reclaim_objects()` →
`gc_mapping()` → `check_svalue()` → `free_svalue()` →
`dealloc_object()` → `debugfree()` → `MDfree()`'s own internal
consistency check aborting — i.e., triggered by the driver's own
periodic ~5-minute `remove_destructed_objects()`/`reclaim_objects()`
GC sweep, the exact same trigger path §10.8 already documents for
`shenzhou`. This is corroborating evidence for the existing §10.8
entry (now six independent occurrences across six unrelated
libs/lineages), not a new finding — flagged here per §10.8's own
"treat 'the process was still alive at the end' as worth checking"
guidance, not silently omitted. One small refinement to the existing
note: unlike every prior occurrence (which left `debug.log`
completely untouched), THIS occurrence's `debugmalloc` warning line
**was** captured in `debug.log` (one line, no further detail) —
apparently that specific abort path routes through `debug_message()`
before `abort()`, unlike the plain ref-count-consistency-check crashes
in the other five occurrences. Not mudlib-fixable; not root-caused
further here, consistent with the existing entry's own conclusion.

### What was tested and confirmed working

- **Registration**: real Chinese name (沈慕白) through the full gift-
  selection/email/gender flow into a real random `valid_startroom`
  (varied across sessions: 客店, 武庙, 北疆小镇 all observed — see the
  `startroom` observation above for why).
- **Movement/exploration**: both bare directional commands AND `go
  <direction>` (see the `changed_match_path`-check section above),
  20+ rooms across 长安/北京城2 (王府井/地安门/天安门/太庙-adjacent
  streets)/华山派/丐帮暗道/一片"青竹林" random-move maze zone (a
  legitimate lost-in-the-woods mechanic, not a bug — eventually exits
  via any repeated direction).
- **Long-distance travel**: `trans <code>` (`Trans site`/魔法传送帖,
  a starting-inventory item) correctly teleported the character to
  `hs`/华山, `gc`/扬州广场, `tam`/天安门 instantly, each with the
  correct "身影突然出现在一阵烟雾之中" flavor text and a real 10-`jing`
  cost — confirmed reaching the intended LIVE zone each time (not a
  stale/backup path, no §7.18-shaped bug here).
- **Safe sparring**: `fight mu ren` against the `d/city2/wuchang`
  training dummy — see the bug writeup above (confirmed genuinely
  unsafe before the fix, confirmed genuinely safe, auto-concede,
  reward-granting after it).
- **Sect join (organic NPC path), mechanism confirmed working even
  though not completed**: `apprentice yue`/`apprentice buqun`
  against 岳不群 (华山派 sect head, reached via `trans hs`) correctly
  triggered his `attempt_apprentice()` dialogue and correctly rejected
  the character on legitimate content grounds (`shen<10000`,
  `dex<25` — both real, intentional stat gates, confirmed via source
  reading, not a bug); same against 令狐冲's lower-but-still-unmet
  `int<25` gate (read only, not reached live — see travel notes in the
  earlier "Interactive test result" section of this lib's own history
  for why 舍身崖 wasn't attempted this pass, prioritizing the more
  reachable target instead). The `apprentice`/`command()`-self-call
  chain itself (message_vision, `set_temp("pending/apprentice", ...)`)
  ran correctly with no crash or error in every attempt — the
  MECHANISM works; this character's own randomly-rolled stats simply
  never qualified for either master tried, which is content, not a
  bug, per AGENTS.md §10.7's scope note.
- **`learn`**: read `cmds/skill/learn.lpc` in full (requires
  `is_apprentice_of()` or `recognize_apprentice()`, neither ever true
  for `shenmubai` given the above) — mechanism understood but NOT
  exercised live, since no sect join ever succeeded this pass.
  Honestly unverified, not claimed as tested.
- **Clean `quit`**: correct ASCII-art farewell banner
  (`/adm/etc/welcome1`) + `me->save(); destruct(me);`, zero new
  `debug.log` lines immediately after, confirmed multiple times across
  the session.
- **Unclean (net-dead) disconnect + PROMPT reconnect** (within the
  600s `NET_DEAD_TIMEOUT`, `include/user.h`): every `mudclient.py`
  session in this pass that didn't end in `quit` (i.e., almost all of
  them) was itself a real unclean disconnect; reconnecting shortly
  after consistently printed `重新连线完毕。` and resumed the exact
  same live object/room, confirmed repeatedly (e.g. mid-navigation
  rooms with no other way to be standing in them).
- **Admin account** (`fluffos`/`Mud@2026`): confirmed working,
  `(admin)` status, `update <path>` successfully hot-recompiled all 10
  edited files with "成功！" and no errors — used deliberately as a
  `find_body()`+`move()` teleport shortcut via `eval` (per AGENTS.md
  §10.3's instrumentation guidance) after this lib's dynamically-
  changing/maze-like room graph made hand-navigated pathing to a
  specific distant NPC unreliable; `work/tmp/` had to be created first
  (missing directory, `eval`'s scratch-file write otherwise fails —
  a minor pre-existing admin-tooling gap, not fixed, out of scope,
  removed again before finishing).

### What was NOT verified live, and why

- **Full 600-second `NET_DEAD_TIMEOUT` force-quit reconnect path**:
  attempted via a real wall-clock wait, but the driver process itself
  crashed during that same idle window from the independent, known
  §10.8 driver-fatal class documented above (a sixth corroborating
  occurrence, itself a legitimate finding), before the timeout could
  fire and be observed. Given the time already spent this pass, this
  check was not re-attempted after restarting the driver. Explicitly
  unverified — not claimed as tested. (The PROMPT-reconnect path,
  the mechanically-adjacent code, was verified repeatedly, above.)
- **State persistence across a clean `quit` + real wait + reconnect**:
  a clean `quit` was run and confirmed error-free, but the driver
  crashed (same §10.8 event) before a deliberate post-quit wait +
  reconnect could be re-run in this final pass. Money/inventory/skill
  state WAS repeatedly confirmed correctly round-tripping across the
  many earlier prompt-reconnects earlier in the session (strong
  circumstantial evidence the same save/restore path is sound), but
  this specific checklist item was not independently re-verified after
  the crash. Explicitly flagged, not silently assumed.
- **`hong.lpc`'s fix, live end-to-end** (recruitment actually
  succeeding with a low-`shen` character) — blocked by a separate,
  legitimate access-gate mechanism reaching 洪七公 himself; see the bug
  writeup above.
- **A real shop purchase (`buy`/`list`)**: identified a reachable
  vendor (`d/city2/npc/xiaofan.lpc`, `list`/`buy` via `inherit
  F_VENDOR`, `feature/dealer.lpc`) very close to the starting `客店`
  zone and read its full `do_list()`/`do_buy()` implementation, but
  ran out of session time (driver crash, then the coordinator's
  explicit time-box) before actually executing a live purchase.
  Explicitly unverified, not claimed as tested.
- **Real combat to death / respawn**: not attempted (per the task's
  own guidance to use the safe-sparring mechanism first, which
  consumed most of this pass's combat-testing time investigating and
  then fixing the mu-ren bug above). Death/reincarnation code was not
  read this pass.
- **WASM interactive playthrough**: this pass was native-driver only,
  per the task's own instructions.
