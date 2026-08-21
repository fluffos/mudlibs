# xjcq2000 — 仙剑狂侠2000 (Legend of Sword and Fairy — Crazy Hero 2000)

Archive: `仙剑传奇.rar`. Port: 40034. Status: **done** (boots clean and
quick, full registration flow verified end-to-end including a real
Chinese name).

## What this is

"仙剑狂侠2000", credited to 叶雨飞 (guofengcool@sina.com,
www.518518.com). Same "Century-family" `adm/single/{master,simul_efun}`
layout as `shiji`/`zhonghua2`/`shujian2008`/`sjpl2` — and its
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
   hang, unlike the investigation on `xlqyzdb` just before
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
   `xianlvqiyuan`/`xlqyzdb`).
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
`xkyx3b`). Native sanity retest (id `xjcqrz`/`xjcqrs`, real
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
  call**, the exact shape that silently failed on `xzyx`
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

## WASM 修复摘要（迁移自 meta.json 的 group_note）

状态已从过时的 limited 修正——这份档案自己的 README 里从未记录过任何缺陷说明，本轮重新测试也没有发现：管理员登录干净正常："Are you using BIG5 font [Y|N]?"（回答 n）→id+密码→"您目前的权限是：(admin)"。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 100 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（2026-08-13，round two，新驱动重测）

针对驱动升级（`quest_times`/`win_times` `%`-operator 修复 + Warning/warning
大小写回退兼容）做的重测。

### 发现并修复：`data/board/news_b.o` 存档数据本身已损坏，每次登录都
### 触发一次被顶层捕获的运行时错误

登录后固定 1 秒的 `call_out("check_news", ...)` 会加载新闻留言板
`/clone/board/news_b`，其 `setup()` 无保护地调用 `restore()` →
`restore_object()`，而这份存档本身括号不配对（`[`/`]`：371 对
339，`(`/`)`：707 对 706）——`raw/` 原始压缩包里的同一份存档就已经
是这个字节形状（`md5sum` 内容不同是编码转换导致的正常膨胀，但括号
计数在转档前后完全一致），确认是转档之前就存在的损坏数据，不是本
项目引入的回归。因为 `check_news()` 是通过 `call_out` 异步触发（不
在注册/登录的主执行路径上），崩溃只会让这一次 `call_out` 的执行栈
被顶层错误处理器捕获并写进 `debug.log`（`执行时段错误：
*restore_object(): Illegal mapping format while restoring dbase.`），
不会打断登录本身——但每一次任何人登录都会在 `debug.log` 里重复留
下这条噪音，且新闻板永远不可用。`restore_object()` 对不存在的文件
只会静默返回 0，不会抛出，所以删除这个无法再被正确解析的损坏文件
是安全的：`git rm work/data/board/news_b.o`。删除前后各做一次完整
的 `fluffos`/`Mud@2026` 管理员登录验证：删除前能在 `debug.log` 里
稳定复现这条错误，删除后同样的登录流程干净无此错误，`score` 显示
"【天神】"头衔正常，功能无回归（本来就不可读的新闻板，删除后
`setup()` 的 `restore()` 只是拿到"文件不存在"，走默认空白留言板路
径）。

### Proactive checks（无需改动）

- 实际生效的 master file 是 `adm/single/master.lpc`，其
  `log_error()` 里对玩家的 `efun::write()` 调用整行被注释掉，编译
  诊断只写日志文件不回显给任何人，不适用 §7.34-class；仓库里还有一
  份未被任何档案引用的死代码 `adm/obj/master.lpc`（旧形状，未改
  动）。
- `log_file()`（`adm/simul_efun/file.lpc`）已经用 `catch()` 包裹
  `write_file()`，功能上等价于 `assure_file()` 保护，确认仍然生
  效。
- `win_times` 的 `%`-operator 修复确认存在且正确：
  `d/city2/npc/refereew.lpc:177` 已用 `to_int(query("win_times")) %
  5`；`d/hs/npc/refereew.lpc` 里没有用到 `%`，不适用。
- `feature/dbase.lpc` 未发现 tybxjh/wlhd 那种密码写保护，不适用。

### 实测过程

管理员 `fluffos`/`Mud@2026` 用真实密码重新连线（含"Are you using
BIG5 font"→n 这一步），落地在此前保存的地点，`score`
显示"【天神】"头衔和正确属性数值。驱动按精确 PID 结束；测试期间产
生的存档时间戳增量已 `git checkout --` 还原，只提交
`news_b.o` 的删除。

## §7.100 修复（`ROOM` 基类的同一"多余 replace_program()"形状，全档案扫描第 6 批）

- 删除 2,451 处存活的 `replace_program(ROOM);` 相关行，与普查记录一致。
  本库有四套建房/建群组工具副本命中同形状：`clone/misc/
  roommaker.lpc`、`u/deng/roommaker.lpc`（各含 3 处 `room_code`/`str`
  拼接变体）、`adm/daemons/groupd.lpc`、`cmds/debug/roommaker.lpc`。
- 验证：真实 `build-debug` 驱动干净开机、端口正常监听，`debug.log` 中
  零 "cannot replace"/"cannot bind" 行。

### ```§7.112``` residual-gap closure (2026-08-20)

Corpus re-scan (`grep -rl 'call_out("death_stage"' ... | filter for missing guard`) found unguarded `init()`-scheduled `death_stage()` call_out chain(s) in `d/death/npc/yanluo.lpc` that the original two-wave sweep (see AGENTS.md §7.112) missed -- same reconnect-triggered duplicate-chain bug, different filename/lineage. Added the standard `query_temp("death_stage_active")`/`set_temp`/`delete_temp` re-entry guard, adapted per file's own exit points. Compile-verified via `lpcc --batch`.

## §7.30 uninitialized-mapping accessor sweep (2026-08-20)

Corpus-wide mechanical sweep of the `feature/skill.lpc` shared-lineage
bug (confirmed independently on `xiakexing2017`/`jqxz2015`/`haiyang2`
via round-four testing): 4 accessor(s) in this file returned a raw
never-initialized `mapping` instance variable (defaults to `int 0`,
not `([])`, until first assigned), crashing any unguarded
`keys()`/`sizeof()`/indexing caller for a fresh/untrained character.
Fixed at the accessor level (`mapp(x) ? x : ([])`) per the documented
remedy. Verified via `lpcc --batch` static compile check only (not a
live boot) as part of a large mechanical sweep; not individually
functionally re-tested live on this lib.

## Round-four (§10.7) follow-up — closing the three explicitly-flagged gaps (2026-08-20)

Native `build-debug` driver, fresh boot, `debug.log` wiped before boot
and stayed **completely absent (zero errors) through the entire pass**
— no compile/runtime errors from anything below. All three items from
the "Explicitly not verified live" list closed:

1. **Successful (funded) shop purchase — now verified, no bug.**
   Logged in as admin `fluffos`, `goto /d/city/zahuopu`, `clone
   /clone/money/silver 60` (auto-merges into a single "六十两白银"
   stack per `COMBINED_ITEM`'s move()-time same-`base_name` merge),
   `list` confirmed `皮背心` at 56两, `buy beixin` succeeded
   ("你从杂货铺老板那里买下了最后一件皮背心。"), item appeared in
   `i`. **First measurement looked like a bug** (money appeared to go
   *up*, 60→64两, instead of down by 56) — root-caused via `call`
   introspection (`call laoban->query_goods_value(...)` confirmed the
   correct 5600-copper price; `call silver->query_amount()` confirmed
   a single, non-duplicated money object) to a **test-methodology
   artifact, not a real bug**: two separate `clone .../silver 60`
   calls were issued across two different reconnects of the same
   persistent admin character without checking inventory in between,
   and `COMBINED_ITEM.move()`'s auto-merge silently combined them into
   120 silver (12,000 copper) before the buy — 12,000 − 5,600 = 6,400
   = "六十四两", exactly matching the observed number. A clean
   second purchase on the same character, with a known starting
   balance (6,400 copper) and no interleaved reconnect, deducted
   *exactly* 5,600 copper (6,400 → 800, "八两") as expected. Price
   deduction and item receipt both confirmed correct; **no code
   change needed**. (Admin's test-acquired silver/beixin items were
   left in inventory as evidence, consistent with other test-character
   saves in this NOTES file; the resulting `data/*/f/fluffos.o` /
   `u/deng/log` save-churn from this session was reverted via `git
   checkout --` since no other file changed, per this project's
   save-churn-avoidance convention.)
2. **`d/wuguan/npc/muren.lpc` training dummy — now verified live,
   clean.** `goto /d/wuguan/wuchang4` (one of the rooms that places
   `npc/muren` per its `objects` mapping) reached the dummy directly.
   `fight muren` produced a full multi-round turn-by-turn combat log
   (`accept_fight()`'s stat-mirroring worked — evenly matched, neither
   side landed early hits), self-halted via the safety net exactly
   like the `liumang`/`girl` sparring already verified in the original
   deep-functional pass ("看来该找机会逃跑了..." → auto-retreated to
   the adjacent room). No crash, no `debug.log` output at all.
3. **`d/honghua/npc/yuyutong.lpc`/`xutianhong.lpc` post-fix — now
   verified live.** `xutianhong.lpc` **is** reachable through normal
   navigation (`goto /d/honghua/goldroom2`, which lists
   `/d/honghua/npc/xutianhong` in its `objects` mapping) — `look xu`
   showed it spawned correctly, wearing "布衣(Cloth)" (confirms the
   fixed self-targeted `carry_object("/d/honghua/cloth")->wear()` in
   `create()` ran without error). **Correction to this file's own
   earlier claim**: re-checked while here — `yuyutong.lpc` is **not
   actually referenced by any room's `objects` mapping anywhere in
   this lib** (`goldroom.lpc` only has a *commented-out* line for a
   *different*, wizard-sandbox `xutianhong` copy at
   `/u/ybl/honghua/npc/xutianhong`; a corpus-wide
   `grep -rln 'npc/yuyutong'` outside the NPC file itself found
   nothing) — it is orphaned/unreachable through ordinary play, not
   merely "not reached this pass". Since the actual fixed code path
   (the `create()`-time `carry_object(...)->wear()` call) fires
   identically on `new()` regardless of how the object is
   instantiated, live-verified it directly via admin
   `clone /d/honghua/npc/yuyutong` in `goldroom2`: spawned cleanly,
   `look yu` showed it correctly wearing "布衣(Cloth)" too, no crash,
   no `debug.log` output. Fix confirmed to hold under live
   instantiation; the orphaned-reachability finding is a documentation
   correction, not a new bug (nothing crashes from an unreferenced
   file existing on disk).

### Standard checklist confirmation pass (fast, per §10.7 routine)

- **§7.90** (eval-cost): `config.fluffos` already has `maximum
  evaluation cost : 5000000` (not the low default) — confirmed
  already fixed.
- **§7.100**/**§7.86** (ROOM/board redundant `replace_program()`):
  already swept per this file's own earlier entries; boot stayed
  clean this pass too.
- **§7.111** (`standard_trace()` unconditional `file_name()` on a
  possibly-`0` `error["object"]`): not applicable to this lib's
  shape — `adm/single/master.lpc`'s `standard_trace()` formats
  `error["object"]` via `%O` in `sprintf`, never calls `file_name()`
  on it directly, so the crash shape can't occur here.
- **§7.108** (duplicate-login kick-reconnect leaves character command-
  dead): this lib does have the `exec(old_link` shape
  (`adm/daemons/logind.lpc:323`), but `clone/user/user.lpc`'s
  `reconnect()` already starts with `enable_commands();` — already
  fixed.
- **§7.112** (`death_stage()` reentrancy): already closed per this
  file's own 2026-08-20 entry above; `find ... -iname chacha.lpc`
  under this lib returns nothing, so the specific shared-file shape
  from the 4-lib session finding doesn't apply here.
- **§7.79** (bare `addn()`/`addn_temp()` 2-arg): this lib is not one
  of the 6 confirmed-affected libs in the corpus-wide sweep — not
  applicable.
- **§7.30** (uninitialized-mapping accessor guard): already applied
  per this file's own entry directly above, confirmed present in
  `feature/skill.lpc` (`mapp(skills) ? skills : ([])` etc.).
- **combatd.lpc `bounce`-division pattern**: `grep -n bounce
  adm/daemons/combatd.lpc` returns nothing — this lib's combat daemon
  doesn't have the `bounce`-loop shape at all, not applicable.

No new bugs found or fixed this pass — all three previously-flagged
gaps closed as **verified clean** (one initially-alarming false
alarm, fully root-caused to a test-methodology artifact rather than a
real defect). The `/d/xingxiu/silk6` refcount-corruption root cause
remains not further chased, per the task's stated lower-priority/
budget guidance — still documented as-is above, nothing new to add.
