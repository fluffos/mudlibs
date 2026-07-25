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

## 深度功能测试 / Deep functional test (2026-07-24)

First genuine hands-on playthrough (AGENTS.md §10.7) — one continuous
native session, real newbie-help-driven navigation, organic sect join
and skill learning, real (non-scripted) combat through to an actual
death/revival, an unclean-disconnect/reconnect test both promptly and
after the full 900s `NET_DEAD_TIMEOUT`, and a driver stdout capture
throughout. This pass found the single most severe bug yet in this
project's round-two sweep: **a real, non-catchable, whole-process FATAL
crash** — not just a caught runtime error — that killed the driver
outright roughly 25 minutes into an otherwise-idle session. Also fixed
five independent pre-existing compile/runtime bugs surfaced along the
way (§6.6-class typos, none related to this project's conversion
pipeline).

### Test characters (kept as evidence, both alive and saved)

- id `xjcqshen`, pw `Pass1234`, Chinese name **沈玉城** — 丐帮 (Beggars'
  Sect) 一袋弟子, apprenticed to 方裘, knows `基本手法(hand)`, currently
  at 中央广场. Saves: `work/data/login/x/xjcqshen.o`,
  `work/data/user/x/xjcqshen.o`.
- id `xjcqhuo`, pw `Huo12345`, Chinese name **霍云飞** — died once
  (killed by a 学童/schoolboy NPC while `wimpy 0`), went through the
  full 鬼门关/阎罗大殿 death-and-revival cycle, currently alive at
  中央广场 with an empty inventory (all gear/money lost on death, by
  design — confirmed intentional, see below). Saves:
  `work/data/login/x/xjcqhuo.o`, `work/data/user/x/xjcqhuo.o`.
- Admin `fluffos`/`Mud@2026` (pre-existing from an earlier pass) used
  only for `update <file>` to verify each fix recompiled cleanly.

### What was tested and confirmed working

- **Newbie help** (`doc/help/newbie`, `doc/help/intro`) read first —
  correctly describes `fight` (safe, auto-halts at ~50% qi/jing) vs
  `kill` (real, lethal) vs `hit`; sect list; `bai`/`xue` teacher flow;
  `set wimpy`; weak-NPC ladder (小孩/女孩/男孩 etc.) as the recommended
  first sparring targets.
- **Registration**: real Chinese names (沈玉城, 霍云飞) through the full
  BIG5-prompt → id → password ×2 → name → stat-roll/accept → email →
  gender flow, landing in `START_ROOM` (`/d/city/guangchang`, 中央广场)
  with real NPCs present — already known-good, re-confirmed.
- **Navigation**: read room `.lpc` source to find a working path from
  the start room to a training-grade NPC (`d/city/zahuopu`, 4 moves)
  since the docs' claimed default room (扬州武庙) and the lib's own
  designated training hall (`d/wuguan/`, actually a *Xiangyang* zone
  reachable only via `d/xiangyang/eroad1`, not the Yangzhou start zone)
  turned out to require real travel — noted, not chased further.
- **Safe sparring**: `girl`/`laoban` (老板) both refuse `fight` (their
  `attitude` is `"friendly"`, hard-coded to decline in
  `inherit/char/npc.lpc`'s `accept_fight()`); `liumang` (`attitude`
  `"peaceful"`) accepts. `fight liu` produced a full turn-by-turn combat
  log and self-halted once my `气血` dropped to 28/100 — no crash, no
  over-death, matches `help newbie`'s documented model exactly.
  `d/wuguan/npc/muren.lpc`'s dummy (the canonical stat-mirroring
  `accept_fight()` seen on other libs in this project) is real and
  present here too but sits in the Xiangyang zone, not reached live —
  **code-reviewed only, not live-verified**, flagged per §10.7 item 6.
- **Sect join (organic path)**: `方裘` (方裘, 丐帮八袋长老) is present in
  the START ROOM itself. `bai fang` → `apprentice.lpc` →
  `ob->attempt_apprentice(me)` → `gb_apprentice()` →
  `command("recruit " + id)` (an **NPC-issued, ORIGIN_EFUN command()
  call**, the exact shape that silently failed on `xingzhanyingxiong`
  per AGENTS.md §8.3a's addendum) worked correctly end-to-end here —
  `门派` became 丐帮, `师承` 方裘, `称号` 丐帮一袋弟子. This lib's
  `feature/command.lpc` **does** have the `private nomask command_hook`
  shape, but — matching the documented empirical caveat in §8.3a — it
  does not break dispatch on this driver/lib combination. No fix
  needed; confirmed by direct test, not assumed.
- **Skill learning (organic path)**: `xue fang hand` (format is
  `xue <teacher> <skill>`, not the plain `xue <skill>` the newbie doc's
  quick-reference implies) → "你听了方裘的指导...你的「基本手法」进步
  了！" → `cha` lists it correctly, `score` unaffected elsewhere. A
  server-side auto-save fired after learning ("您的资料已经自动保存好
  了。").
- **Shop purchase**: reached `杂货铺`'s 老板 (`d/city/npc/yang.lpc`,
  `F_DEALER`), `list` correctly priced `皮背心` at 56 两白银; `buy
  beixin` on an intentionally broke character correctly refused
  ("穷光蛋，一边呆着去！") rather than silently failing or crashing —
  confirms the dealer/buy command path itself works.
  **Not completed live**: an actual successful purchase, since neither
  test character ever had 56+ silver (starting money is minimal by
  design and this pass didn't grind for it) — the negative path is
  verified, the positive (successful-purchase) path is not.
- **Combat to death and revival, live, in full**: `set wimpy 0` (to
  defeat the flee-before-death safety net on purpose) + `kill boy`
  against `d/city/npc/boy.lpc` (学童, `combat_exp` 120, no skills) —
  produced a full round-by-round beatdown, ended in a real death
  ("你「啪」的一声倒在地上，挣扎着抽动了几下就死了。"), moved to
  `d/death/gate` → `d/death/gateway` (阎罗大殿), the 5-stage
  `death_stage()` dialogue with 阎罗王 (60s + 4×5s, matching
  `d/death/npc/yanluo.lpc`) played out correctly, then
  `reincarnate()` + move to `START_ROOM` (see next bullet) completed
  with the character alive again, inventory/money wiped — matches the
  lib's own documented death-penalty rules exactly. Zero crashes, zero
  new `debug.log`/stdout errors through the entire cycle.
- **Content note, not a bug**: revival went to `START_ROOM`
  (中央广场), not the `REVIVE_ROOM` constant (`/d/city/chmiao`,
  城隍庙, which does exist and resolve correctly — checked, not a
  §7.18-style stale path) — because `adm/daemons/logind.lpc` sets
  `enter_wuguan=1` on every freshly-registered character and
  `d/death/npc/yanluo.lpc`'s `death_stage()` explicitly routes anyone
  with that flag still set to `START_ROOM` instead. This also means
  `doc/help/newbie`'s claim that the default spawn is "扬州武庙" is
  stale documentation text (the actual constant is 中央广场) —
  cosmetic, not fixed, doesn't affect any tested flow.
- **Unclean disconnect / net-dead, prompt reconnect**: closed the
  client without `quit` several times over the course of the session
  and reconnected immediately each time — always landed back exactly
  where left off, no void-parking. Confirmed structurally: this lib's
  `clone/user/user.lpc` `net_dead()` **never moves the player to a
  void room at all** (just `remove_all_enemy()` + a
  `call_out("user_dump", NET_DEAD_TIMEOUT, ...)`), and `reconnect()`
  just clears the netdead flag and cancels that call_out — so the
  AGENTS.md §7.20 void-stranding bug class **structurally cannot occur
  on this lib**: there is no void mechanic in the disconnect path to
  begin with.
- **Unclean disconnect, reconnect after the full 900s timeout elapses**:
  waited out the real `NET_DEAD_TIMEOUT` (900s) with the character
  genuinely disconnected, confirming `user_dump(DUMP_NET_DEAD)` fires
  and routes through the same `"/cmds/usr/quit"->main()` path as a
  normal `quit` (saving `startroom` from the character's real,
  non-void location). First attempt at this reconnect is what
  triggered the FATAL crash below; a second attempt against a freshly
  rebooted driver confirmed the character's saved state (location,
  sect, skill) survived the crash intact and the timeout-triggered
  save path itself is correct.

### THE FATAL CRASH — new bug class, draft below

**`FATAL ERROR: FATAL: Object 0x561e30ffeb88 /d/xingxiu/silk6 ref count
0, but not destructed (from free_svalue).`** — this is a driver-level
consistency check, not a catchable LPC runtime error. It printed to the
driver's own stdout (never to `work/log/debug.log`, which stayed at a
constant 846 lines — its pre-existing baseline — through this entire
session, crash included) and **terminated the whole process**,
disconnecting every player. `/d/xingxiu/silk6` is an ordinary room
(星宿派 zone, "丝绸之路") that neither test character had ever visited;
the crash surfaced instead while `xjcqshen` reconnected after the net-
dead timeout, inside `feature/dbase.lpc`'s `set_temp("link_ob", ...)`,
called from `adm/daemons/logind.lpc`'s `reconnect()`. That call site is
almost certainly an innocent bystander — a `set_temp()`/mapping-touch
that happened to be the next `free_svalue()` call after the corruption
already existed, not its cause.

Root-cause chain (established from the driver's own stdout, which
happened to be captured to a file — **this would have left literally
zero evidence otherwise**):

1. This lib's ambient world simulation is NOT idle even with nobody
   giving commands: roaming NPCs (`赵爵爷`, `捕头`, others) have
   `heart_beat()` → `chat()` → `random_move()` chains that walk them
   through real exits via `cmds/std/go.lpc`, exactly like a player
   would. Given enough real wall-clock time (here: ~25 minutes), this
   ambient wandering forces lazy compilation of rooms/NPCs across
   **the entire map**, including zones neither test character ever
   went near (星宿, 明教, 逍遥, 武当, 大理, 红花, 黑木崖, 全真...).
2. That mass-compile surfaced several genuinely broken pre-existing
   files (see fixes below) — `unew()`/`make_inventory()` failures,
   `restore_object()` illegal-format errors on old board-post save
   data (same already-documented shape as the `news_b` finding above,
   now also hit for `wiz_b`/`towiz_b`/`yuelaoting` boards) — all
   individually caught and harmless on their own.
3. Somewhere in that sustained churn of compiling/cloning/destructing
   objects across nearly the whole lib, a room's (`/d/xingxiu/silk6`)
   reference count was corrupted to 0 without the object actually being
   destructed. The corruption is silent until the NEXT unrelated
   `free_svalue()` call happens to touch it, at which point the
   driver's own internal consistency check aborts the whole process.

**This is exactly the shape AGENTS.md's testing methodology was built
to catch and exactly the shape ordinary testing never will**: it needs
(a) real wall-clock idle time, not just a quick smoke test, (b) a
process that was NOT restarted in between (so ambient churn can
accumulate), and (c) driver stdout capture, since `debug.log` shows
absolutely nothing. Two of this project's fixes below (broken NPC
compiles that were part of the churn) are plausible **contributing**
factors — a failed `unew()` on a target that never received a working
program is exactly the shape of "reference grabbed to something that
gets partially torn down" — but this was **not proven as the exact
root cause** within this pass's time budget; a from-scratch reproduction
attempt (fresh boot, long idle soak, no other player activity, watch
for the same FATAL) was not run again given the ~25-minute-per-attempt
cost. Flagged honestly as **not fully root-caused**, not silently
presented as fixed.

**Recovery verified**: killed the dead process (confirmed via PID +
`readlink -f /proc/<pid>/cwd`, not by pattern), rebooted fresh — both
test characters' saved data (location, sect, skill, and — for
`xjcqhuo` — the post-death empty inventory) survived the crash intact
and reconnected normally. The on-disk save format was not corrupted by
the crash; only the live process died.

### Bugs found and fixed (all pre-existing, unrelated to this
project's conversion pipeline — §6.6-class typos/copy-paste bugs)

1. **`d/city/npc/kongkong.lpc`** — `inherit __DIR__ "gaibang_npc.lpc"`
   but no `d/city/npc/gaibang_npc.lpc` file existed (three OTHER
   directories have their own differing copies of this file:
   `d/gaibang/npc/`, `d/gaibang/npc/obj/`, `jobsys/gb_job1/` — none
   shared). `d/city/npc/kongkong.lpc` is itself a byte-identical
   duplicate of `d/gaibang/npc/kongkong.lpc`, so the fix was to copy
   its matching sibling, `d/gaibang/npc/gaibang_npc.lpc`, alongside it
   at `d/city/npc/gaibang_npc.lpc` (new file — `git add` needed).
   Spawned live by `d/city/dongdajie2.lpc` (a room actually walked
   through this session) — every `reset()` there previously threw
   `*Inherited file '/d/city/npc/gaibang_npc' does not exist!`,
   silently leaving that room's NPC population incomplete every time.
   Verified via admin `update /d/city/npc/kongkong` +
   `update /d/city/dongdajie2` — both recompile clean now.
2. **`d/city/npc/xiaosong.lpc:57`** — `is_killing(who)` passed an
   `object` where `is_killing(string id)` (defined in
   `feature/attack.lpc`) requires a string, throwing `*Bad type for
   argument 1 of is_killing` — a genuine **hard compile error**, so
   this file has likely never successfully compiled since whatever
   commit introduced the bug (every spawn attempt threw `*No program
   in object`). Fixed: `is_killing(who->query("id"))`. Verified via
   admin `update` — compiles clean.
3. **Four instances of `this_player()->carry_object(...)->wear()`
   inside `create()`** — `this_player()` is undefined at compile/
   `create()`-time (no player context yet), so this evaluates to `0`,
   throwing `*Bad argument 1 to EFUN call_other() ... Got: int(0)` on
   every single spawn — a hard runtime failure on `create()`, not a
   cosmetic warning. Every other NPC file in this lib correctly calls
   the bare (self-targeted) `carry_object(...)->wear()` instead. Found
   by grepping the whole lib for the pattern after fixing the first
   instance (per §10.7 item 7 — checking siblings for the same
   pattern), all four fixed identically:
   - `quest/poem/npc/daxueshi.lpc:18` (spawned by `quest/poem/yard.lpc`
     — the room I actually walked `xjcqhuo` through this session,
     confirming this one live).
   - `u/deng/npc/daxueshi.lpc:18` (a personal-workspace duplicate of
     the above, spawned by `u/deng/yard.lpc`).
   - `d/honghua/npc/yuyutong.lpc:53`, `d/honghua/npc/xutianhong.lpc:52`
     (both spawned by `d/honghua/goldroom.lpc`/`goldroom2.lpc`) — found
     by pattern match, verified via admin `update` (compiles), **not
     live-walked to, per §10.7 item 7's "flagged as unverified live"
     allowance**.
4. **`d/honghua/npc/xutianhong.lpc:63`** — `ob - query("family/
   master_id")` (missing `>` — parsed as subtraction of an object,
   not a method call), throwing a **hard compile error** (`*Bad
   argument number 1 to '-': "object "`) independent of fix #3 above;
   this file has also likely never compiled successfully. Fixed:
   `ob->query("family/master_id")`. Verified via admin `update`.

None of the four `restore_object()` illegal-format board-save errors
surfaced during the mass-compile churn (`wiz_b`, `towiz_b`,
`yuelaoting`) were fixed — same root cause and same "degrades
gracefully, known non-critical content gap" disposition already
established for `news_b` above (old save data with unescaped literal
newlines/quotes inside post text, predating this conversion pass).

### Explicitly not verified live (honest accounting, §10.7 item 6)

- `d/wuguan/npc/muren.lpc`'s stat-mirroring training dummy — code-
  reviewed, matches the canonical safe-sparring shape from other libs
  in this project, but sits in a zone (Xiangyang, via
  `d/wuguan/guanmen.lpc` ← `d/xiangyang/eroad1`) not reached this pass.
- A successful (funded) shop purchase — the buy-command path and its
  insufficient-funds rejection are confirmed live; an actual completed
  transaction was not, since grinding up 56+ silver was out of scope
  for this pass.
- The exact LPC-level root cause of the `/d/xingxiu/silk6` refcount
  corruption — the crash itself, its trigger conditions, and plausible
  contributing factors are all confirmed live; the precise object-
  lifecycle bug that corrupted the refcount was not isolated to a
  specific file:line within this pass's budget.
- `d/honghua/npc/yuyutong.lpc`/`xutianhong.lpc` post-fix — confirmed to
  recompile cleanly via admin `update`, not walked to live in-game.
