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

## AGENTS.md §7.19 fix: enable_player() reentrancy from init()

`feature/command.lpc`'s `enable_player()` (wrapper around
`enable_commands()`) was reachable from an NPC's `init()`: the shared
`inherit/char/char.lpc` `setup()` (called from every character's
`create()`) itself calls `enable_player()`, and `d/shushan/npc/zhangmen.lpc`
redundantly calls `setup()` again from inside its own `init()` (on top
of the `setup()` its `create()` already made) -- same shape as the
originally-documented mhxy `zhangmen.lpc` case. `enable_commands()` is
only safe to call from `create()`: calling it again on an object
already `living()` makes the driver re-invoke that same object's
`init()` as a side effect, which recurses back into `enable_player()`
on the same call stack until "Too deep recursion" aborts the boot on
a room's first-ever visit. Fixed with a true reentrancy flag
(`in_enable_player_now`), NOT a `living()` guard (which would break
legitimate re-enables from `revive()` in `feature/damage.lpc` and
`wakeup()`/`wakeup2()` in `cmds/std/sleep.lpc`, both confirmed to
re-invoke `enable_player()` on this lib while the object is still
`living()`). Verified via `lpcc --batch` single-file compile check
(PASS). Part of the corpus-wide §7.19 sweep (Batch E).

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.


## 深度功能测试（§10.7，2026-10-04）— undefined macro and simul_efun gaps

- `message_combatd(msg, me, you)` is called by 52 file(s) (the perform files) and defined nowhere in this archive (a simul_efun of the original server): 51 of them did not compile (`Undefined function message_combatd`). `adm/simul_efun/message.lpc` now has `varargs void message_combatd(string msg, object me, object you, mixed extra)` calling `message_vision()`, placed after `message_vision`'s definition (KB 04 §6.2). All callers compile.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 3 here-document block(s) repaired (3 with the terminator glued to the last text line, 0 with it indented), so `End of file in text block` no longer hides the room or object behind them: `d/city/sxh.lpc`, `d/dali/yuxuguanmen.lpc`, `d/dali/yuxu/yuxuguanmen.lpc`. The terminator must start its line (the lexer's own test, KB 04 §6.10); a glued one lost its newline in the GBK -> UTF-8 conversion together with a half character, which stays out.

## 深度功能测试（§10.7，2026-10-04）— paths named in another case

The archive comes from a case-insensitive host: files are stored as `BAGUA0.lpc`, `longjing.C`, `d/SHAOLIN/`, the code names them in lower
case (`__DIR__ "bagua0"`, `"tea/longjing"`, `"/d/shaolin/..."`), so the rooms, NPCs and items behind them could not be loaded (a `.C` file is
not an `.lpc` file; KB 03 §4.5). `scripts/lpc_case_paths.py --convert --apply xjcq2000`: 135 file(s) renamed to lower case (`.C` -> `.lpc`,
`.H` -> `.h`) and 0 path reference(s) in 0 file(s) rewritten to the new spelling; 0 skipped, 0 ambiguous. Load check of the 158 objects that were renamed, edited or name a renamed path (HEAD against the working tree, an object is the same under any spelling of its path): 7 PASS -> 149 PASS, 0 that loaded before fail now, 142 more load.

135 files moved (121 `.C`, 11 `.lpc`, 2 `.H`, 1 `.c`); mostly under `d/dali/wuliang` (86), `d/dali/dalieast` (28), `d/xiangyang/npc` (14), `d/city/obj` (2). A rescan with `scripts/lpc_warnings.py xjcq2000` is still due: the renamed files are compiled for the first time.

## 深度功能测试（§10.7，2026-10-05）— 任务表里的 `.c` 路径与任务守护进程的防护

`scripts/lpc_dynamic_rows.py`：`quest/dynamic_location` 里 327 行写的是原档案的 `.c` 路径。转档时文件已改名 `.lpc`，而显式后缀按原样解析，`load_object("/d/x.c")`、`new("/d/obj/quest/x.c")` 返回 0 且不报错（KB 03 §4.2，KB 06 §7.220），所以 `adm/daemons/questd.lpc` 读到的每一行都加载不出来：随机任务和任务物品从未生成，在 `create()` 里直接对结果调用 `tar->set()` 的版本还会崩溃，连带加载它的 cron 守护进程和 `give` 的任务钩子。这些行已改为 `.lpc`；另有 506 行指向的文件两种后缀都不存在（档案缺内容），保持原样。
`scripts/lpc_dynamic_quest_guard.py`：1 处 `spread_quest()` 调用（`init_dynamic_quest()` 的循环里）包进 `catch()`，缺失的任务物品或编译不过的房间只跳过那一个任务，守护进程照常加载、其余任务照常生成。
验证：`adm/daemons/questd.lpc`和 cron 守护进程在新进程里加载（HEAD 一次，工作树三次，选房是随机的）：HEAD 通过 2 个，工作树三次分别通过 2、2、2 个（共 2 个），无回退。

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `inherit/room/room.lpc`：`make_inventory()` 用 `catch()` 包住 `unew(file)`（缺档时它在 simul_efun 里对 0 调用 `query("unique")`），`else` 分支只在确有克隆时才取 `[<1]`；`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-07）— return 后面的死字符串

`d/mingjiao/npc/zhangwuji.lpc`：`return "九阳真经我知道，但是现在还不能给你说！";` 下一行又单独写了同一句字符串，永远执行不到；删去，行为不变。新进程加载通过。

## 深度功能测试（§10.7，2026-10-07）— 编译警告整理

`scripts/lpc_warnings.py xjcq2000 --fix` 加 `scripts/lpc_fix_no_effect.py --apply`，共改动 756 个 `.lpc` 和若干 `.h`。HEAD 与工作树分别加载（新进程）：718 -> 718 通过，无回退；改过的头文件的 77 个包含者 65 -> 65 通过。
记录、未改：`d/shushan/` 下 14 个 NPC（剑圣、明王、清风、醉道、龙等）的战斗招式用了 `cast_spell`——西游记系的法术函数，本库的 NPC 基类没有，于是这些文件编译不过（`Undefined variable 'cast_spell'`），蜀山一带的这些 NPC 从来没加载过；是移植区域时带进来的，要补一套法术系统超出本次范围。`inherit/char.lpc` 是没人引用的旧文件（`CHARACTER` 指的是 `/inherit/char/char`）。

启动时警告 31 -> 0；新进程登录（编码选择、新人物确认）正常。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 8 处，返回类型/原型 18 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 0 个，只在 #if 分支用的声明移进分支 0 个文件；改动 26 个文件，HEAD 与工作树各载入一次无回退（26 objects; HEAD PASS 26, tree PASS 26; regress 0; newly loading 0），这些文件的警告 26 -> 0。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查

- `kungfu/skill/liangyi-jian.bak.lpc`：`int i; level;` 去掉无用的 `level;`。载入无回退。

- 2026-10-12：`d/shenlong/npc/pang.lpc` 连写了两行 `inherit F_UNIQUE;`（同一 mixin 继承两次，变量重复声明），删去一行；HEAD 与工作树都能载入。

## 编译警告收尾（2026-10-13）

`scripts/toolkit_fix.sh` 一轮去掉 14 处多余继承：其中 7 件暗器（`clone/weapon/feidao`、`sjian`、`jin-sjian`，两处 `bqp_obj/feibiao`，归云庄石子 `shizi`，`d/hs/jinshe/obj/jinshezhui`）在 `THROWING` 之外又继承它已带的 `COMBINED_ITEM`，`Illegal to redefine 'nomask' function`，从没载入过，现在载入（同 xkxc98sj）。其余手工，能编译的文件警告清零；改动的 34 个对象在 HEAD 与工作树各载入一次：HEAD PASS 26，tree PASS 33，regress 0，新载入 7 个。

- `include/globals.h` 的 `#define BANNED_SITES "/adm/etc/banned_sites";` 多一个分号；`adm/daemons/band.lpc`、`include/net/telnet.h` 各自定义的是同一路径不带分号，去掉分号后三者一致，不再重定义。
- 巫师 squall 的备份 `u/squall/bak/wudugou.lpc`、`combatd.lpc` 先包含自己目录里的旧 `ansi.h`，再经 `weapon.h` 等包含标准 `ansi.h`，颜色宏以后者为准；直接包含 `<ansi.h>`，颜色不变。
- 三份 `hua.lpc`（`d/city/job/`、`jobsys/tianhan_job/`、`u/squall/bak/bak/`）里玩家当前任务 `mapping job` 与后面的任务表 `mapping *job` 同名，表改名 `job_list`；`d/city/npc/renwu.h` 声明了两张 `renwu4`，`hfh.lpc` 读的是后面完整的那张，前面短的改名 `renwu4_old` 保留原文；两份 `roommaker.lpc` 的 `special_props` 删去不用的前一份。
- 关将 `guanj.lpc`（四处）的 `kill_ob()` 改 `void`；`cmds/std/help1.lpc` 的 `DIR`、`jobsys/tianhan_job/feng1.lpc` 的 `QUEST`、`d/xiangyang/npc/shanzei0.lpc` 的 `MAX`、两间书库的 `STORY_DIR` 先 `#undef`；`kungfu/skill/hubo.lpc` 写明用驱动原先选的 `clean_up()`；`kungfu/skill/huashan-jian.lpc` 多余的 `;` 删去。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。8 个文件 12 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）；`x op= 浮点` 先把浮点转成整数再运算（系数小于 1 时 x 直接变 0），改为 `x = to_int(x op ...)`：`/kungfu/skill/fengyun-shou/foguang.lpc`（`damage *=`）、`/kungfu/skill/jieshou-jiushi/foguang.lpc`（`damage *=`）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。

- 2026-10-14：10 个文件用了颜色宏（`HIW`、`NOR`）却没有 `#include <ansi.h>`（首个错误 `syntax error, unexpected L_STRING`）；开头补上；3 个文件的函数声明为 `int`（或 `void`）却返回字符串、对象（`int query_seal() { return "…"; }`），旧驱动照样把值交给调用者；改为实际返回的类型（`scripts/lpc_fix_void_return.py`）（KB 04 §6.1、§6.3）。新编译出来的文件露出的警告一并清掉（删去未用局部变量，有返回值函数里的空 `return;` 改为 `return 0;`）。新进程比对 HEAD 与工作树：13 个对象，新增载入 11，回退 0。

- 2026-10-14（更正）：上一条把 `valid_learn()` 也改成了 `mixed`/`string`，其实那里返回值的类型是因为前面的错误（未定义的函数）才变成未知，不是真的返回字符串；恢复为 `int`。

- 2026-10-15：`kungfu/skill/guangming-blade.lpc`（光明刀法）是从五虎断门刀抄来的，`query_action()` 里仍按 `wuhu-duanmendao` 的等级挑招式：没练五虎断门刀的人出招时一招都匹配不上，`a_action` 为 0，接着赋值报错。改为按 `guangming-blade` 自己的等级。（武功运行期探针发现。）

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。9 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。


## 东方故事/西游记体系的技能文件（2026-10-15，KB 06 §7.241 第三类）

这些 `kungfu/skill` 文件来自 gin/kee/sen/force 体系，本库人物只有 jing/qi/neili：`receive_damage("kee", 30)` 报 `伤害种类错误`，`query("force")` 永远为 0，技能学不了也练不了。按 kee→qi、gin/sen→jing、force→neili、max_force→max_neili、force_factor→jiali 改了属性名（`scripts/lpc_port_es_props.py`），共 204 个文件。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

另有 22 个文件（绝招、状态、物品、NPC 等，不限于 kungfu/skill）来自 gin/kee/sen/force 体系，同样按 kee→qi、gin/sen→jing、force→neili 改名（`scripts/lpc_port_es_props.py --any-file`）。


## family 映射（补）（2026-10-15）

`mapping fam = (mapping)me->query("family");`（带类型转换的写法）同样直接取下标，7 处补上 `if (!mapp(fam)) fam = ([ ]);`。


## 内力/上限当作伤害种类（补）（2026-10-15）

`victim->receive_wound("force", n, me)`（兵器吸内力）、`receive_damage("max_qi", random(100))`（走火入魔扣上限）等本库不接受的种类，2 处改为 `add(type, -N)`。

## receive_wound 的种类表与 receive_damage 不同（2026-10-15）

本库 `receive_damage()` 接受 jingli，`receive_wound()` 只接受 jing/qi：毒（`duzun_poison`、`yao1_poison` 等）里的 `receive_wound("jingli", N)` 报 `伤害种类错误`，在倒计时之前，毒永不消退。12 个文件 15 处改为 `add("jingli", -N)`（`scripts/lpc_fix_damage_calls.py` 现在按函数分别读取种类表）。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。9 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。


## 技能按另一门武功的等级取招（2026-10-15，KB 06 §7.243）

这些技能文件是从别的武功复制改名来的，`query_action()` 仍用原武功的等级查招式表：只会本技能的人等级为 0，取不到招，每次出招都报错。改为读本技能自己的等级（`scripts/lpc_fix_action_level.py`）：`anran-zhang`、`duanjia-quan`。


## 招式表最低等级之下没有招（2026-10-15，KB 06 §7.243）

招式表的最低 "lvl" 高于 0（如全部为 100），技能等级未到之前取不到招，每次出招都报错。循环后补 `if (!a_action) a_action = action[0];`（`lpc_fix_action_level.py --fallback`）：`zhuifeng-zhang`。


## `->query_(` 笔误（2026-10-15，KB 06 §7.245）

调用不存在的函数 `query_`，call_other 静默返回 0，相关判断永远按 0 计算。改为 `->query(`：`jinshemiji`、`jsmj`。

## 妙手回春的银针检查（2026-10-15）

`miaoshouhuichun` 的 `valid_learn()` 用了未赋值的 `object ob`（`ob->query_temp("weapon")` 报错），还把兵器对象和字符串 "银针" 比较。改为 `ob = me->query_temp("weapon")`，再用 `id("yin zhen")`/`id("yinzhen")` 判断是否银针。

## 空手使用兵器绝招（2026-10-15，KB 06 §7.246）

`perform` 指令允许直接点名招式（如 `perform stick.ban`），这些绝招读了 `me->query_temp("weapon")` 却从不检查，空手时 `weapon->name()` 报错（有的已先扣了内力）。在赋值后补 `if (!objectp(weapon)) return notify_fail("你必须手持兵器才能使用这一招。\n");`（`scripts/lpc_fix_perform_weapon.py`）：`duanyun-fu/hongtianza`、`huashan-jianfa/feilong`、`murong-jianfa/kuangjian`、`shenghuo-lingfa/zhuihun`、`tianyu-qijian/kuangwu`、`wuyue-blade/jiao`、`yueya-chan/feicha`、`yuxiao-jian/yuxiao`。

## 把经验、属性、内力当技能读（2026-10-15，KB 06 §7.247）

当前内力、精这类名字有时指的是内功技能，逐处读过后手改：落英缤纷 `luoying-shenjian/lybf`：自己的注释说成功率由“精神高低”决定，两处 `query_skill("jing")` 改为 `query("jing")`。

## 碧海生潮曲空手报错（2026-10-15，KB 06 §7.246）

`iceforce/roar`（碧海生潮曲）先 `ob = me->query_temp("weapon")`，再直接拿 `base_name(ob)` 判断是不是玉箫；空手 `exert roar` 时 `base_name(0)` 报错，提示“你必须先找一只玉萧来才可以吹－－曲”根本出不来。条件前补 `!objectp(ob) ||`。

## iceforce「chillgaze」从未编译通过（2026-10-15）

`iceforce/chillgaze` 原档在第一个 `return notify_fail(...)` 后多了一个 `}`，`exert()` 就此结束，后面的语句全落在函数外，`skill`、`damage` 也没有声明，文件编译失败，这个 exert 从来用不了。照 bixiecanyang、hc、xyzx3 已修好的版本删去多余的 `}`、补上 `int skill, damage;`，其余字句不变，只是缩进进函数体。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`beimin-shengong`→`beiming-shengong`（`changle-xinfa`、`guiyuan-dafa`、`honghua-shengong`、`tiangang-zhangqi`、`wuxin-jing`、`xuedaoxinfa`）；`anran-xiaohunzhang`→`anranxiaohun-zhang`（`anranxiaohun-zhang/haichao`）；`dagou-zhenfa`→`dagouzhenfa`（`dagouzhenfa`）；`jinhse-jianfa`→`jinshe-jianfa`（`/d/hs/jinshe/skill/jinshe`）；`tanzhi_shentong`→`tanzhi-shentong`（`tanzhi-shentong/hui`）；`yan-fly`→`yanfly`（`yanfly`）；`yihua-jimu`→`yihua-jiemu`（`yihua-jiemu`）；`yinyun_ziqi`→`yinyun-ziqi`（`yinyun-ziqi/cure`）；`zhenfen-xinfa`→`zhenfeng-xinfa`（`zfwy-bu`）。

## 嵩山剑法「蓄力」没穿布衣时报错（2026-10-15）

`songshan-jian/xuli` 用 `cloth = me->query_temp("armor/cloth")` 取衣服，随后直接 `cloth->query("material")` 判断要不要显示“衣袖鼓起”的描写；身上没有布衣时（裸身或只穿铠甲）这里报错，而此时 `apply/speed` 已经扣掉、复原的 call_out 还没排上，身法就一直少了一截。两处判断前补 `objectp(cloth) &&`。

## 技能名拼错：技能文件里拼错自己的名字（2026-10-15，KB 06 §7.249）

技能自己的文件（或它的绝招目录）里，`query_skill()` 读的是差一个字母的自己的名字，永远得 0：“基本功夫要高过本技能”之类的限制从不生效，按等级取招、计算伤害的那一项一直是 0。改为本技能的名字（`scripts/lpc_fix_skill_typo.py` 的 self 判据）：`baitao-xuangong`→`bitao-xuangong`（`bitao-xuangong`）；`jiyang-shengong`→`jiuyang-shengong`（`jiuyang-shengong`）。

## 银索金铃「点穴」对空手的对手报错（2026-10-15，KB 06 §7.246）

`yinsuo-jinling/dian` 失手时三种描写之一是“真气贯注”加对手兵器的名字，对手空手时 `ob` 为 0，三次失手有一次报错。改为 `(objectp(ob) ? ob->query("name") : "全身")`（泥潭一系原本就写作“真气贯注全身”）。

## family 映射内联取下标（2026-10-15，KB 05 §7.30）

`ob->query("family")["master_name"]`、`me->query("family")["family_name"]`（泥潭式为 `query("family", ob)[...]`）直接对门派映射取下标：没有门派的人（新玩家、叛师者、大多数 NPC）在 NPC 的打招呼和问话、绝招的门派判断、房间的 `valid_leave` 里报 `Value being indexed is zero`，而不是得到拒绝。5 处（4 个文件）改为 dbase 路径查询 `query("family/master_name")`：有门派时值相同，没有时得 0；原有的判断照常生效（`scripts/lpc_fix_family_index.py`）。给映射赋值的写法未动。


## 用兵器的绝招空手施展时报错（内联写法）（2026-10-15，KB 06 §7.246）

绝招不存兵器变量，直接写 `(me->query_temp("weapon"))->query("name")`（或在拒绝判断里写 `(weapon = me->query_temp("weapon"))->query("skill_type")`），之前又没检查兵器：空手 `perform` 时报 `Bad argument 1 to EFUN call_other()`，内力等往往已经扣掉。在第一次用到它的那条语句前补上“你必须手持兵器才能使用这一招”的拒绝（`scripts/lpc_fix_perform_weapon.py`）：`liangyi-sword/yin`、`suiyuan-sword/yiqiesuiyuan`。


## 血刀刀法「祭血神刀」正神时报错（2026-10-15，KB 06 §7.241）

`xue-dao/shendao` 的伤害是 `random(shen / -1000) + shen / -3000`，越邪恶伤害越高；正神的人算出负数，`receive_damage()` 报“伤害值为负值”。补 `if (damage < 0) damage = 0;`，设计不变（正派用不出伤害），不再报错。


## 存档读不出来：字符串里的换行、空行（2026-10-15，KB 03 §4.4）

`data/board/` 44 个、`adm/daemons/` 1 个、`d/biwu/npc/` 1 个、`data/` 1 个、`data/msg/` 1 个、`doc/help/` 1 个：字符串里有原样的换行（`save_object()` 存成 `\r`，`restore_object()` 逐行读，原样的换行让字符串收不了尾），或有空行（`Illegal file format`），读档的对象（留言板、NPC、玩家）从空白开始。换行改写成 `\r`、删去空行（`scripts/lpc_save_encoding.py --from-raw`），驱动核对全部能读回（`scripts/lpc_save_restore_check.py`）。

## 玉女剑法「合壁」用一次就永久改动经验和剑法（2026-10-15，KB 06 §7.253）

收尾的 `hebi()` 声明时没有参数（`void hebi() { object me, target, env; int i, j, o, p, count; ...`），call_out 传进去的人和数值全被同名的局部变量（0）挡住，开头的 `if (!me && !target) return;` 每次都返回：合壁的攻击、闪避加成和 `hebi` 标记要到重新登录才消失。更糟的是夫妻判断写成了 `target->querry("id")`（没有这个函数，得 0），没成亲的人 `marry/id` 也是 0，于是人人都被当成夫妻：自己的玉女剑法和经验乘以玉女素心功的级数/80（至少变成浮点数，160 级以上翻倍），随后给对方 `set_skill("combat_exp", ...)` 时报 `No such skill`，收尾的 call_out 也就没排上，乘过的等级和经验永远不还原。测试里用一次合壁，经验 100000 变成 200000.0、剑法 100 变成 200.0。改正：`hebi()` 按它自己再次 call_out 时传的八个参数声明，`perform` 的 call_out 去掉多余的 `h, k`，`querry` 改为 `query`，给对方的 `set_skill("combat_exp")` 改为与上一行一样的 `set("combat_exp")`。测试里加成照常生效，`hebi()` 结束时还原并清除标记，没成亲的人经验和剑法不变（`kungfu/skill/hebi.lpc` 是放错位置的同一文件，不在绝招路径上，一并改正）。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

53 个文件、79 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/u/jpei/thd/obj/biyuxiao.lpc`、`/clone/weapon/blade/blade`、`/d/obj/weapon/sword/changjian`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 0 个，改后 0 个（0 个原来载入不了），没有退步；其余 53 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## NPC 带着不存在的物品：simul_efun `unew()` 报错（2026-10-18，KB 06 §7.73）

`adm/simul_efun/object.lpc` 的 `unew(str)`（带 `unique` 判断的 `new()`）先 `ob = new(str)`，紧接着就读 `ob->query("unique")`。物品文件不存在时 `new()` 返回 0，读 0 的属性报 `Bad argument 1 to EFUN call_other()`，从 `carry_object()` 一路带出去：`create()` 里带着缺失物品的 NPC 载入不了（jh2006 的苗疆何铁手一类，该有 NPC 的房间少了人）。读属性之前补 `if (!ob) return ob;`（`int i = ob->query("unique"), j, k;` 拆成声明和赋值两句），缺的物品跳过，NPC 照常载入（`scripts/lpc_guard_carry_object.py --unew`）。载入检查：改动的文件改前能载入 1 个，改后 38 个，没有退步。

## 补回丢掉的基类宏（2026-10-18，KB 04 §6.13）

`inherit F_XXX;` 里的宏本库任何头文件都没有定义，报 `syntax error, unexpected L_IDENTIFIER, expecting L_STRING or '('`，整个对象载入不了；宏指向的基类文件本库其实有，别的库都把这个宏定义成同一个路径。在全局头文件 `include/globals.h` 里补上：`SSERVER` → `/inherit/sserver`（14 个文件）、`SPEAR` → `/inherit/weapon/spear`（2 个文件）、`NPC_SAVE` → `/inherit/char/npcsave`（1 个文件）。（`scripts/lpc_restore_macros.py`）改后用 `lpcc` 逐个载入这些对象：17 个里 17 个通过。

## `kungfu/skill/qingyi-jian` 第一式的 `skill_name` 丢了收尾引号（2026-10-18，KB 03 §4.6）

`"skill_name" : "大悲式,` 的收尾引号没了（转码时跟半个汉字一起丢了），字符串连到下一行，`damage_type` 成了代码：`Illegal character 0xe5`，整个武功载入不了。补回 `",`（同系的 bixiecanyang、syxjl 等库里有完好的同名文件）。载入：通过。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 11 个对象设了本库没有文件的武功（10 个名字，最多的是 `canglang-goufa`、`brush`、`yingou-bifa`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：11 个里 10 个通过，其余 1 个停在别的错误上（`kungfu/class/xiake/master`：*No program in object '/kungfu/class/xiake/master'!）。（`scripts/lpc_guard_set_skill.py`）

## 通向不存在房间的出口，按对面房间的回头出口改正（2026-10-18，KB 06 §7.257）

房间出口 `"west": __DIR__"xxx"` 指向的文件本库没有，玩家走过去就被卡住（笔误、改过名的房间，或者没带进档案的编号房间）。对面的房间存在、并且它相反方向的出口正好指回这个房间，说明出口原本就是通向它：`/d/dali/houyuan` 的 `south`：`zoulang1` → `zoulang`。改动后每个出口都能解析到本库的文件（`scripts/lpc_fix_dead_exits.py`；目标在运行时本来就能载入的库——虚拟房间——不动）。

## 补回本库没有的基类文件（2026-10-18，KB 04 §6.15）

下面这些基类本库没有，继承它们的对象（房间、NPC、物品）整批载入不了（`inherit XXX;` 的宏没定义，或者 `inherit "/std/…";` 的文件不在）。同系的库里有同名文件，两库有大量逐字节相同的文件（亲缘关系），所以从那边原样拷来，缺的宏补进全局头文件 `include/globals.h`：`/inherit/weapon/ring`（宏 `RING`）←fqyy2，9 个对象继承它，抽样 9/9 载入。每个基类补回后单独载入、再抽样载入使用它的对象，基类载不进来或者一个用户也载不进来的就撤掉（本库撤掉了它们，不再补）。（`scripts/lpc_restore_bases.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 76 处、75 个文件：`shaolin-shnfa`→`shaolin-shenfa`（29 处）、`kunlun-shnfa`→`kunlun-shenfa`（29 处）、`huashen-shenfa`→`huashan-shenfa`（6 处）、`lognxiang-gong`→`longxiang-gong`（4 处）、`tiaji-jian`→`taiji-jian`（2 处）、`xinxiu-duzhang`→`xingxiu-duzhang`（1 处）、`duan-yirangzhi`→`duan-yiyangzhi`（1 处）、`weiituo-gun`→`weituo-gun`（1 处）等共 11 个名字。（`scripts/lpc_fix_skill_names.py`）

## 调用了父类没有的函数的对象（2026-10-19，KB 06 §7.259）

`::create();`、`::init();`、`return ::buy_object(who, item);` 这类调用写的是父类里有这个函数的版本；本库的父类没有，旧驱动把它当空操作（返回 0），现在的驱动在编译时就报 `Unable to find the inherited function`，整个对象载入不了。单独成句的调用删掉，`return ::f(...)` 改成 `return 0;`（void 函数里是 `return;`），与旧驱动的行为一致。共 1 处、1 个文件：`::setup()`（1 处）。只改了出错原因全是这一类的文件；还带着别的错误（多半是父类本身没了）的文件没动，等父类补回后再看。（`scripts/lpc_fix_dangling_super.py`）

## set_name 的 id 参数传成字符串（2026-10-19，KB 06 §7.260）

`set_name("海口大碗", "bowl");` 把物品的 id 写成了字符串，本库的 `set_name(string name, string *id)` 要的是数组，驱动在编译时报 `Bad type for argument 2 of set_name ( string * vs string )`，整个物件载入不了；旧驱动不检查参数类型，字符串里照样找得到这个词，物品能用 id 称呼。改成 `({ "bowl" })`，共 2 个文件：`/d/baituo/npc/obj/bowl.lpc`、`/d/baituo/obj/bowl.lpc`。（`scripts/lpc_fix_set_name_id.py`）

## 武功文件里混进了分页器的文字（2026-10-19，KB 06 §7.263）

`kungfu/skill/boxing.lpc` 第一行是 `> more boxing.c  // houquan.c 猴拳`，`kungfu/skill/westsword.lpc` 两个数组元素中间有一行 `已 经 显 示 26 % (ENTER 继 续 下 一 页 ， q 离 开 ， b 前 一 页)`：这两个文件是从 `more` 分页器里复制出来的，命令行和分页提示留在了文本里，驱动报 `unexpected L_ORDER`、`Illegal character 0xe5`。前后的代码是完整的（与 chidi、yxjh 的同名文件逐记号对照，除了数值调整之外一致），删掉这两行就能载入。

## 全局头文件丢了 7 个宏（2026-10-19，KB 04 §6.16）

`/include/globals.h` 里没有定义 `LANGUAGE_D`、`MUDLIB_ENCODING`、`REMOTE_Q`、`INTERMUD_NAME`、`MAILDIR`、`BASE64_D`、`COMPETE_D`，用到它们的物件（名单里 9 个）编译时报 `Undefined variable`/`Undefined function`，整个物件载入不了（编译器在第一个未定义的名字上停下，后面的错误和警告都看不到）。同系的库在各自的头文件里都有这几行：照其中和本库共有文件最多的那个库，原样补到 `/include/globals.h` 最后一个 `#define` 之后，宏体里出现的路径在本库里都存在。补完后名单里有 6 个载入，其余还差别的东西。（`scripts/lpc_restore_defines.py`）

## 区域物件的零碎修正（2026-10-19，KB 06 §7.267–§7.271）

- `/kungfu/skill/chousui-zhang/sandu_test.lpc` 的 `#include "/u/maco/poison_list.h"` 改成 `/kungfu/skill/chousui-zhang/poison_list.h`（巫师目录 `/u/…` 不在档案里，头文件的唯一副本在区域里）

逐个物件与 HEAD 对比载入，没有退步。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 补回丢失的标点（2026-10-19，KB 03 §4.6）

转换时丢掉的分号、逗号、引号或文件末尾的 `}`，共 4 个文件，修前 HEAD 载入失败。别的库里同路径的完好副本只比这里少几个标点，按它补回（括号里是那个库）：`/kungfu/skill/huang.lpc`（bixiecanyang）、`/kungfu/skill/jueqing-chenfa.lpc`（syxjl）。一行文字在逗号前丢了结尾的引号（下一行是同一个表的下一项），补上：`/kungfu/skill/jueqing-chenfa.lpc`。文件末尾少了 `}`（最后一个或两个字节丢了），补上：`/u/benteng/shizhe1.lpc`（2 个）。修后与 HEAD 逐个对比载入：这 4 个物件全部载入，没有退步（`scripts/lpc_restore_from_twin.py`、`lpc_fix_eaten_quote.py --comma`、`lpc_fix_eof_braces.py`）。

## 旧驱动的类型宽松：缺省参数、无类型形参、数组初始化、`class` 变量（2026-10-19，KB 04 §6.19、§6.20）

原来的 MudOS 把调用少传的参数补 0、把没写类型的形参当 `mixed`、不检查变量的声明类型与初始值，也允许变量叫 `class`；这个驱动在编译时全部拒绝，整个物件载入失败。修了 1 个文件：`/clone/npc/luohantang-shouzuo.lpc`（`scripts/lpc_round_files.py` 的修复轮：调用处补写 `0`、无类型形参补 `mixed`、`string X = ({...})` 补星号、void 函数的返回值，以及 `class` 变量改名 `pick_class`）。逐个文件在 HEAD 和改后载入对比：这些文件里 1 个原来载入失败、现在载入，没有退步。

## `== !"字符串"` 多出来的 `!`（2026-10-19，KB 06 §7.280）

`!"taoist"` 是整数 0，`x == !"taoist"` 就是“x 等于 0”，作者为其余所有人写的那一支永远走不到。具体是：性别检查（“你不是女的，无法领会其中至阴之理”）永远不拦人，男的照样能学玉女心法。全部改成 `!= "字符串"`（`scripts/lpc_fix_not_literal_cmp.py`）：`/kungfu/skill/yunu-xinfa.lpc`（1 处）。同样的行在 xkx 一系的 35 个库里都有。

## `x == "a" || "b"`：后面的字符串常量永远为真（2026-10-19，KB 06 §7.281）

`if (arg == "yuyou" || "yu you")` 里的 `"yu you"` 是非空字符串，永远为真，整个条件对任何 `arg` 都成立；作者要的是每个字符串都和变量比较。具体是：`valid_enable()` 对任何 usage 都返回真。在每个字符串前补上变量和运算符（`scripts/lpc_fix_literal_or.py`；`forrest2.lpc` 是 `dir == "north" && "south"`，手工改成 `(dir == "north" || dir == "south") && ...`）：`/kungfu/skill/tianyu-bufa.lpc`（1 处）。

## 比较链的人工修正（2026-10-20，KB 06 §7.282）

`d/mingjiao/bhd/xbkai.lpc`：爬岩石的判断 `arg != "yanshi" || arg != "岩石"` 永远为真，爬什么词都爬上岩石；本意是参数是 yanshi 或“岩石”，改成 `==` 和 `||`。

## `call_out_info()` 的每一项只有 3 个元素（2026-10-20，KB 06 §7.287）

驱动返回的是 `({ 物件, 函数, 延迟 })`，不带 call_out 的参数，旧代码读第 4 项 `info[i][3]`（`callouts` 指令、`calloutd`、`cod` 工具）一读就报 `Array index out of bounds`，指令从第一行起什么也打印不出来。改为 `(sizeof(info[i]) > 3 ? info[i][3] : 0)`（`scripts/lpc_fix_callout_info.py`）。改动：`/feature/disaster.lpc`（1 处）。

## 任务 NPC 的 `random_move()`：目的地房间没载入时 `find_object(dest)->query(...)` 对 0 调用（2026-10-20）

任务/豪杰 NPC 随机走动前先问目的地房间是否 `no_fight`，`find_object(dest)` 在房间还没载入时返回 0，`0->query()` 报 `Bad argument 1 to call_other()`，NPC 每次心跳报一次错、永远走不出第一个房间。改为 `(find_object(dest) || load_object(dest))->query("no_fight")`。改动：`/feature/disaster.lpc`（1 处）。

## 浩劫系统 `verdict_time()`：领头玩家已经离线时 `lead->name()` 报错，戒严不解除（2026-10-20）

三十分钟后收场时 `lead`（接战书的玩家）若已退出游戏就是 0，`lead->name()` 在宣布战果的 `message()` 里报错，后面的 `LOGIN_D->set_madlock(0)` 不再执行，戒严一直保持，`quit` 指令因此对所有人关闭。改为 `(lead ? lead->name() : "各派豪杰")`。改动：`/feature/disaster.lpc`（3 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 20 处）。改动：`/adm/daemons/topd.lpc`（6 处）、`/cmds/skill/quanjia.lpc`（1 处）、`/cmds/std/help1.lpc`（1 处）、`/d/mingjiao/npc/zhangwuji.lpc`（1 处）、`/kungfu/class/emei/fengling.lpc`（1 处）、`/kungfu/skill/meinu-quanfa.lpc`（1 处）、`/kungfu/skill/meinv-quanfa.lpc`（1 处）、`/kungfu/skill/qiankun-danuoyi.lpc`（7 处）、`/quest/guojob/teamjob.lpc`（1 处）。

## `socket` / `dumpsocket` 指令：`dump_socket_status()` 驱动里没有（2026-10-20，KB 06 §7.291）

这些巫师指令 `write(dump_socket_status());`，MudOS 的 efun 在 FluffOS 里不存在，指令编译不过。在模拟 efun 文件里补了 `dump_socket_status()`：用 `socket_status()` 排出同样的表（没有 sockets 包的构建，比如 WASM，只有表头；`scripts/lpc_add_sefun.py dump_socket_status`）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/single/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## 翻页器 `start_more(read_file(...))`：文件缺失时 `explode(0)`（2026-10-20，KB 06 §7.300）

东方故事系的翻页器 `void start_more(string msg) { ... explode(msg, "\n") ... }` 被这样调用：`start_more(read_file(HELP_DIR + "help/topics"))`、`start_more(read_file(NEWS))`。压缩包没带的文件使 `read_file()` 回 0，`explode(0, ...)` 在本驱动里报 `Bad argument 1 to explode()`（不带参数的 `help` 指令就是这样出错的），老驱动把 0 当空文本。在 `start_more` 开头加了 `if (!stringp(msg)) return;`（`scripts/lpc_fix_start_more.py`）。改动：`/kungfu/skill/more.lpc`。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库现有的 NPC 文件里没有字面写成空 `chat_msg` 的（扫描只认 `set("chat_msg", ({ }))`）；守卫挡的是运行时才为空的列表和以后新增的 NPC。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/inherit/char/npc.lpc`（共 1 个文件）。

## 存档里的 `.c` 文件名改成 `.lpc`（2026-10-21，KB 03 §4.2 第 9 项）

存档里写着 `"/d/city/npc/wei.c"` 这样的文件名；extract 时源文件已经全部改成 `.lpc`，而驱动对带扩展名的路径只认字面，`new()` / `load_object()` / `move()` 都找不到它，调用方多半把失败当成「没有这个东西」悄悄跳过。本库 10 个存档共 10 处按 `scripts/lpc_fix_save_dotc.py` 改成 `.lpc`（只改 `.lpc` 存在而 `.c` 不存在的字符串；玩家存档、备份、留言板、巫师目录和文件索引缓存不动）。改动：`/p/residence/cash971888263.o`（1 处）、`/p/residence/cash971888503.o`（1 处）、`/p/residence/cash971888605.o`（1 处）、`/p/residence/chao972181288.o`（1 处）（等共 10 个存档）。

## 不带参数的指令对 0 调用 efun：不在 wiz / adm 目录里的指令（2026-10-21，KB 06 §7.336）

指令敲成不带参数时，驱动把 0 传给字符串参数；下面的指令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`。它们在 `cmds/std`、`cmds/usr`、`cmds/bos`、`cmds/app` 这类目录里，上一轮的扫描只看巫师目录。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py --all-dirs` 在第一处使用参数的语句前加守卫：文件自带 `int help(object me)` 的，守卫是 `if (!arg) return help(me);`（`help()` 定义在 `main()` 之后的 1 个文件补了原型 `int help(object me);`，否则编译报 `Undefined function help`）；没有 `help()` 的是 `return notify_fail("…\n");`。改动（1 个文件，括号里是接住 0 的 efun）：`/cmds/std/fill.lpc`（`present`）。加载检查 HEAD 与工作树对照，没有退步。

## 任务分配 `quest`：按顺序找目标的备用循环用了 `living[j]`（2026-10-21，KB 06 §7.347）

`/adm/daemons/taskd.lpc`、`/feature/quest.lpc`：先随机挑目标（`j = random(sizeof(living))`），挑不中再“按顺序找”：`for (i = 0; i < sizeof(living); i++) if (check(living[j], ...)) { target = living[j]; break; }`。下标写成了 `j`（上一个循环最后一次的随机下标），备用循环把同一个 NPC 检查 `sizeof(living)` 遍，世界小的时候任务就分不出去。xkx100 的原文就是这样，派生库照抄。改成 `living[i]`。

## 苗疆山谷 `shangu1`：第二条蛇写成了 `jinshe = new(..yinshe)`（2026-10-21，KB 06 §7.346）

烧灵芝兰（`do_shao`）引出两条蛇：`jinshe = new(__DIR__ "npc/jinshe"); jinshe = new(__DIR__ "npc/yinshe");`，第二句把第一条覆盖了，`yinshe` 一直是 0，后面的 `yinshe->move(...)` 抛错。第二句改成 `yinshe = new(...)`（sje、jym 的同一份文件是对的）。

## xjcq2000：渡世济人、昆仑和雪山的 `ask_me()` 读没赋值的 `ob`（2026-10-21，KB 06 §7.348）

这几份是 batch 38 / 39 修过的同一批文件的另一份拷贝（当时的扫描被 `@LONG` 里的引号弄乱，漏看了这个库）：`persuade` 的 `ob->query("no_fight")` 改成 `environment(me)->query("no_fight")`；`ask_me()` / `ask_me_1()` 开头补 `ob = this_player();`。改动：`/cmds/std/persuade.lpc`、`/kungfu/class/kunlun/banshuxian.lpc`、`/kungfu/class/kunlun/hetaichong.lpc`、`/kungfu/class/xueshan/laozu.lpc`。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 65 条注册（56 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/d/city/leitai12.lpc`（`do_action`）、`/d/city/npc/obj/letter.lpc`（`do_call`）、`/d/city/pinqiting.lpc`（`do_pass`、`do_resign`）、`/d/city3/npc/bboss.lpc`（`do_vendor_list`）、`/d/city3/npc/blackman.lpc`（`do_vendor_list`）、`/d/city3/npc/chengboss.lpc`（`do_vendor_list`）、`/d/city3/npc/fan1.lpc`（`do_vendor_list`）、`/d/city3/npc/fan2.lpc`（`do_vendor_list`）、`/d/city3/npc/fan3.lpc`（`do_vendor_list`）、`/d/city3/npc/liuzi.lpc`（`do_loan`、`do_pawn`、`do_redeem`、`do_vendor_list`） 等共 56 个文件。最多的函数名：`do_send` 15 处、`do_vendor_list` 12 处、`do_tiao` 7 处、`do_strike` 3 处、`do_loan` 2 处。没有动（读过）：`/d/shushan/npc/zhangmen.lpc` 的 `do_bandage`（对象本身编译不过，登记留着，等对象能加载再处理）。

## 基类的 `add_action` 登记：处理函数只在后代里定义，基类自己被加载时报错（2026-10-21，KB 06 §7.349）

房间、NPC、公告板这类基类，`init()` 里登记的 `add_action("函数", "动词")` 的函数只由继承它的后代定义；基类对象自己被直接加载（房间可以走进去、NPC 可以克隆）时，访客输入这个动词，驱动报 `*Function for verb 'x' not found.`（第一轮扫描把这些当成“有后代定义，是活的”放过了，`scripts/lpc_verify_handlers.py` 在基类对象上跑 `function_exists()` 才看出来）。登记前加 `if (function_exists("函数", this_object(), 1))`（第三个参数 1：默认 `function_exists()` 把 `protected` / `private` 函数当作没有定义），后代照常登记。共 1 处、1 个文件（`scripts/lpc_fix_dead_add_action.py --guard`）：`/d/ghost/npc/master.lpc`（`give_quest`）。

## 对象路径里的 `..`：`new(__DIR__ "../obj/x")` 报 `Read access denied`（2026-10-22，KB 06 §7.351）

`__DIR__` 是当前文件所在目录（带结尾斜杠），`__DIR__ "../obj/x"` 就是 `/d/zhiye/npc/../obj/x`；驱动的 `legal_path()` 不接受带 `..` 的路径，`new()` / `load_object()` 直接抛 `*Read access denied.`（实测，`find_object()` 对它答 0）。走库自己的 `carry_object()` / 房间 `objects` 表的路径，库的基类会先规范化，能用；直接把路径交给 `new()` / `clone_object()` / `load_object()` / `move()` 的不行，调用到那一步才报错。改成规范化后的绝对路径（`scripts/lpc_fix_dotdot_dir.py --direct`）：`/d/dali/npc/zhang.lpc`（`__DIR__ "../obj/hammer"` → `"/d/dali/obj/hammer"`）, `/d/wudang/npc/xiaocui.lpc`（`__DIR__ "../obj/nuerxiang"` → `"/d/wudang/obj/nuerxiang"`）。

## 商人的 `list` 命令：登记的是另一个血统的函数名（2026-10-22，KB 06 §7.349）

第 42 批把 `add_action("do_vendor_list", "list");` 当成死登记删掉了（这些文件里没有 `do_vendor_list`，输入 `list` 只会得到 `*Function for verb 'list' not found.`），但它们的商人基类里同一个工作的函数叫 `do_list`，`list` 动词就此没了：`/d/city3/npc/blackman.lpc`, `/d/city3/npc/fan1.lpc`, `/d/city3/npc/fan2.lpc`, `/d/city3/npc/fan3.lpc`, `/d/city3/npc/liuzi.lpc`, `/d/city3/npc/whiteman.lpc`。按真正存在的函数名放回 `add_action("do_list", "list");`；用库的管理员账号克隆 NPC 再输入 `list` 实测（`/d/city3/npc/blackman.lpc`：`你可以向黑衣青年购买下列物品： 名称 数量 价格 二百粒黑云子(Black yun-piece) 二十盒 二十八两白银 `），每个文件都列出商品或问要看哪一类。同一批里放回去后仍答 `什麼？`、没有商品或者列表时报错（货品文件缺失）的商人没有动。

## 缺失物品的 `new()` / `carry_object()` 调用链加了保护（2026-10-22，KB 06 §7.73 补充）

`new(路径)->move(...);` / `carry_object(宏("x"))->wear();` 这类语句，路径指向的文件在这个压缩包里没有：`new()` 返回 0，`->move()` 在 0 上报 `Bad argument 1 to EFUN call_other()`。在 `create()` 里这个对象永远加载不了，在 `reset()` 里第一个缺失物品之后的刷新每次 reset 都被跳过。7 个文件里 7 处（`new`）改成 `{ object new_ob = new(路径); if (new_ob) new_ob->move(...); }`（`scripts/lpc_guard_carry_object.py --new`：路径按这个文件自己看到的宏解析，宏名冲突、虚拟对象路径一律跳过）。 对这 7 个改动文件做加载检查（HEAD 与工作区对比）：HEAD 能加载 7 个，现在 7 个（新增可加载 0 个，回归 0 个）。

## 调用了、但这个库自己的守护进程里没有的函数（2026-10-22，KB 06 §7.354）

`MACRO->函数()` 调用的函数在这个库的守护进程里不存在：`call_other()` 对不存在的函数不报错、只返回 0，所以这些功能（时间显示、昼夜事件、名字检查、价格文字……）一直没起作用。同一血统另一个库的同名守护进程里有这些函数，原文照抄到本库守护进程末尾（`scripts/lpc_port_function.py`；调用处传的参数个数、函数体用到的函数 / 全局变量 / 宏 / 字符串键都在本库里有，已核对；守护进程在 HEAD 和工作区都能加载，每个函数用固定参数各调用一次：HEAD 返回 0，现在返回正常的值）：`/adm/daemons/chinesed.lpc` ← aoxiangtianji：`chinese_month()`（4 处调用）；`/adm/daemons/chinesed.lpc` ← fengyun434：`check_control()`（1 处调用）、`check_length()`（5 处调用）、`check_return()`（1 处调用）、`check_space()`（1 处调用）、`check_chinese()`（1 处调用）。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 还剩 18 个函数没有补（chat_msg_combat 12, inquiry 4, other 1, item_desc 1）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/cmds/std/help1.lpc`:`confirm_l_choice`、`/d/city/ximenroad.lpc`:`look_gaoshi`、`/d/shushan/npc/dragon2.lpc`:`cast_spell`、`/d/shushan/npc/dragon3.lpc`:`cast_spell`、`/d/shushan/npc/dragon6.lpc`:`cast_spell`、`/d/shushan/npc/dragon7.lpc`:`cast_spell`、`/d/shushan/npc/guard.lpc`:`cast_spell`、`/d/shushan/npc/guiwang.lpc`:`cast_spell`、`/d/shushan/npc/jiansheng.lpc`:`cast_spell`、`/d/shushan/npc/mingwang.lpc`:`cast_spell` 等另外 8 个。 另有 1 处函数体被作者整段注释掉（指针没跟着删），是有意关掉的，没动。

## 不带前导斜杠的物品路径：缺失物品的 `new()` / `carry_object()` 调用链加了保护（2026-10-22，KB 06 §7.73 补充）

`carry_object("d/city/obj/jiasha")->wear();` 这类路径不带前导斜杠的写法在这个驱动里按根目录解析（`new("d/city/obj/changjian")` 能加载 `/d/city/obj/changjian`），所以和带斜杠的一样：文件不在压缩包里时 `new()` 返回 0，`->wear()` 在 0 上报 `Bad argument 1 to EFUN call_other()`，整个 NPC 加载不了。此前的保护工具把这种写法当作「相对当前目录，没法判断」跳过了。5 个文件里 5 处（`clone/weapon/sword/sword`、`d/obj/cloth/daopao`、`u/deng/job/gb/obj/gaoji-wenshu`）改成带保护的块（`scripts/lpc_guard_carry_object.py`）。 对这 8 个改动文件做加载检查（HEAD 与工作区对比）：HEAD 能加载 3 个，现在 5 个（新增可加载 2 个，回归 0 个）。

## 任务副本城的出口指向库里没有的 `/d/xiangyang/...`，改到副本里同名的房间（2026-10-22，KB 06 §7.257 补充）

`/quest/skills2/wakuang/` 下三个房间的出口 `kuangshan` west `/d/xiangyang/caodi6`、`shanhang` north `d/xiangyang/dangpu`（不带前导斜杠）、`zhujia` west `/d/xiangyang/tiejiangpu`：这个库没有这些襄阳房间，任务副本里的 `/quest/skills2/wakuang/xy/caodi6`、`xy/dangpu`、`xy/tiejiangpu` 存在并且各有回到原房间的出口（地图对称），改到副本房间。`scripts/lpc_fix_dead_exits.py` 现在也读不带斜杠的路径，它们的反向出口因此被看见。证明（`scripts/lpcc_eval.py`，新进程）：HEAD 三个出口的目标 `load_object()` 都返回 0，工作区都能加载。

## `log/` 下的日志子目录没有人建：写日志的 `write_file()` / `log_file()` 报错（2026-10-22，KB 06 §7.358）

这个库的代码往 `log/` 的 2 个子目录写日志：`log/html`（`d/city/tohtml.lpc`）、`log/log/job`（`jobsys/gb_job1/fangqiu2.lpc`）。压缩包、`git clone` 和站点包里都没有这些目录（本地启动没有写过它们，`gen_keep_dirs.py` 没记），`write_file()` 对不存在的目录抛 `*Wrong permissions for opening file /log/dlog/money for append. "No such file or directory"`，调用它的函数在写日志那一行中断，后面的奖励、标志、步骤都没有执行。测试对象里本库的 `log_file()` 什么也没写（探针对象没有写权限，`log_file()` 自己也不建目录），所以真实调用者会得到什么没有测出来。把 `log/html`、`log/log/job` 记进 `scripts/wasm_keep_dirs.txt`（`scripts/lpc_keep_log_dirs.py`；站点和 pristine 树按它建空目录）。证明（`scripts/lpcc_eval.py`，在 `/adm/daemons` 这类目录下的求值对象里写 `/log/zzdirprobe/...`，新进程）见 KB 06 §7.358 的实测表。

## `(: 函数名 :)` 指针指向本库没有的函数：只含这个指针的行加了注释（2026-10-22，KB 06 §7.355 补充）

`inquiry` / `item_desc` / `chat_msg*` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：用到时（`ask`、`look`、NPC 闲聊）驱动抛 `*Undefined lfun pointer called: 函数名`，这一拍心跳的后半段被跳过。这些函数没有可以补回的来源（别的库同一路径的文件里没有，或者它还要用本库没有的东西），所以 15 个文件里 22 行只含这个指针的行（`"gaoshi": (: look_gaoshi :),` `(: cast_spell, "breathe" :),` `(: cast_spell, "freeze" :),`）加了注释，原文保留并写明原因，这一项当作没有这个话题 / 物品 / 闲聊条目（`scripts/lpc_fix_dangling_lfun.py`；`#include` 的文件在库里缺失的对象、指针不在整行上的写法没动）。 前提（`function_exists()`）和加载检查（HEAD 与工作区对比，本库改动的 `.lpc` 文件）的结果见 KB 06 §7.355：没有一个回归。

## 汉字按字节切片的老写法没有换成按字符：改法名 `"澄" + name[2..3]`、辈分判断 `name[0..1] == "澄"` 等 59 处（2026-10-22，KB 06 §7.360）

原档按字节算字符串区间（一个汉字 2 字节）：`name[2..3]` 是名字的第二个字，`name[0..1] == "澄"` 问名字是不是以「澄」开头。转成 UTF-8 之后，这个驱动的区间和 `strlen()` 都按字符算（`strlen("澄观")` 是 2，`"澄观"[0..1]` 是两个字），老算术原样留着、意思全变：拜入少林 / 武当 / 峨嵋等派的玩家被改成错误的法名（二字名 `张三` 变成一个字的 `澄`，更长的名字取到第三个字）；各派掌门的辈分判断（`name[0..1] == "澄"`）永远不成立。

本库 59 处（43 个文件）：拼名字的赋值 42 处、与汉字常量比较 15 处、对切片赋值 2 处。例：`arg[0..3]` → `arg[0..1]`（`/d/city/npc/zhao.lpc:100`）；`name[0..1]` → `name[0..0]`（`/d/city/npc/zhao.lpc:105`）；`arg[0..1]` → `arg[0..0]`（`/d/city/npc/zhao.lpc:105`）。`scripts/lpc_fix_gbk_slice.py` 把下标按字符重算（社区的 UTF-8 版 `xkx100utf8` 里就是同样的写法，作对照）；没有改的：截断（`name = name[0..7]`，现在最多 8 个字，只是放宽）、ASCII 的区间（`fname[0..3] == "room"`、`ctime(time())[4..19]`）和上下文看不出是汉字的区间。证明（`scripts/lpcc_eval.py`，bixiecanyang；其余各库是同一份文本）：让澄字辈掌门 `attempt_apprentice()` 一个名叫「张三」的访客，HEAD 的法名是 `慧`，改后是 `慧三`；抽样 28 个库的 HEAD / 工作树加载对比 0 退步。工具不幂等（`[0..3]` 折半得 `[0..1]`，又是对齐区间），改过的文件记在 `scripts/gbk_slice_converted.txt`，不要重跑。

## 全局头文件里的宏，`carry_object` 守卫以前看不见：4 处（2026-10-22，KB 06 §7.361）

`config.fluffos` 的 `global include file` 会被驱动塞进每个对象，文件里没有写 `#include` 也能用 `ARMOR_D("shoes")` / `BINGQI_D("langya-bang")` 这类宏；`lpc_guard_carry_object.py` 的宏表只读文件自己写出来的 `#include`，认不出它们，第 46 批 `--macro` 把这些行整个跳过了——NPC 在 `create()` 里 `carry_object(ARMOR_D("shoes"))->wear()`，文件不存在，`new()` 答 0，`->wear()` 抛 `Bad argument 1 to EFUN call_other()`，NPC 加载不了。宏表现在加上全局头文件；本库 4 处改成守卫块（缺文件就不穿，文件回来照旧穿）。证明（HEAD / 工作树加载对比，只含改过的 `.lpc`）：HEAD 加载失败的对象里有 2 个现在能加载，0 退步（`/d/city/npc/shi` 的 `langya-bang`、`shusheng` 的 `jinduan`）。其余仍失败的文件失败在别的原因（`Unable to find the inherited function`、`Undefined variable 'RNAME_D'`），不属于这一类。

## 长度检查按字节写，旁边的提示按汉字写：18 处（2026-10-22，KB 06 §7.362）

老档的 `strlen()` 数字节（一个汉字 2 字节），转成 UTF-8 后它数字符：提示写「必须是 2 到 6 个中文字」的检查还是 `strlen(name) < 4 || strlen(name) > 12`，于是两三个字的房名、帮会名、群名、聊天室名、称号被提示自己说允许的那句话拒绝，上限却是提示的两倍；留言板的标题检查 `i < 4 || i > 24 || i % 2` 还会拒绝所有奇数个字的标题（`post 你好吗`）。本库 18 处（6 个文件）：`if ((strlen(name) < 4) || (strlen(name) > 16)) {`（`/cmds/group/gbuild.lpc:84`）；`if ((strlen(name) < 2) || (strlen(name) > 40)) {`（`/d/city3/npc/smith.lpc:177`）。`scripts/lpc_fix_strlen_gate.py` 以提示为准：条件里每个 `strlen` 门槛都恰是提示所说数字的两倍才折半，存长度的变量（`i = strlen(arg);`）的门槛和 `|| i % 2` 奇偶项、其后循环的 `i % 2 == 0 &&` 一并处理；提示里有英文 / 字母 / 字节的不动。证明（`scripts/lpcc_eval.py`，bxsj 的留言板，求值对象继承 NPC 并重写 `edit()` 记录调用，`command("post 标题")`）：HEAD 拒绝「你好」和「你好吗」、放行 23 个字的标题；改后接受前两个、拒绝第三个；shenmo 的 `named.lpc invalid_new_name("张三")`：HEAD 回 `名字只能是2-4个中文字。`，改后回 0。抽样 24 + 15 个库的 HEAD / 工作树加载对比 0 退步。

## 按字节写的汉字循环、茶馆猜诗和同盟频道标题（2026-10-23，KB 06 §7.363）

老档按字节做「一个汉字」：`while (i--) if (i % 2 == 0 && !is_chinese(name[i..<0]))` 只检查偶数下标，奇数位上的拉丁字母（`张a`）会过；茶馆猜诗 `mixup()` 用 `strlen(str)/2` 再 `j=j+j`、`str[k..k+1]` 交换两字节；泥潭系 `channeld` 的 `switch (strlen(fname)) case 4/6/8/10` 和 `strlen(family)==4/6` 按字节长度给同盟 / 门派名加空格。本驱动的 `strlen()` 和区间都按字符算。`scripts/lpc_fix_byte_char.py`：去掉奇偶项、把区间改成 `name[i..i]`，按字符重写 `mixup()` 并把 `strlen(first)>=14` 折成 7，频道标题的 case / 门派长度改成字符数（对照 aoxiangtianji）。本库 汉字循环 / `is_chinese` 区间 9 个文件。证明（`scripts/lpcc_eval.py`）：sjplii 的 `check_legal_name` 在 HEAD 接受「张a」、改后拒绝，两边都接受「张三」；xkx100 的 `clubpoem->mixup("离离原上草")` 得到「离离原草上」（真交换汉字）；nitan_san 两字同盟名得到 `【 兄  弟 】`。关键对象加载通过。

## 从末尾按字节取汉字、书剑开帮长度（2026-10-23，KB 06 §7.364）

§7.360 只折了数字下标的 `[a..b]`，从末尾取的 `[<2..<1]`（GBK 下一个汉字）和 `[<4..<1]`（两个字）还留着：开帮 `gcreate` 的帮助写「二至六个汉字 / 3到8个英文字母」，检查却是 `(strlen%2)==1 || <4 || >12`，末字对 `({ "帮","会",… })` 用 `gname2[<2..<1]` 永远对不上；少林 / 峨嵋法名 `"明" + name[<2..<1]`、死讯 `killer[<2..<1] != "。"`、兵器改名的 `can_name` 同样坏掉。`scripts/lpc_fix_tail_slice.py` 只改汉字语境（对照非 ASCII 字面量、`can_name` / `valid_group_name`、拼名字），ASCII 补零 / ctime / 复数词尾 / `.lpc` 不动；`[<2..<1]`→`[<1..<1]`，`[<4..<1]`→`[<2..<1]`，开帮门槛按帮助改写。本库 从末尾切片 1 个文件。证明（`scripts/lpcc_eval.py` bxsj）：HEAD 上 `斧头帮[<2..<1]` 对不上「帮」；改后 `[<1..<1]` 对上；长度放行 `斧头帮`/`fut`；`"明"+"张三"[<1..<1]` 得「明三」。

## example/book 注释折行无法加载（2026-10-27，KB 04 §6.25 Also）

`obj/example/book.lpc` 的 `// name of the skill` 等注释被折行，下一行 `the skill` 成了裸标识符，驱动报 `unexpected L_IDENTIFIER`。用手足 sjsh 完好副本覆盖。证明：HEAD 加载失败；改后加载成功。

## hanbing `random 反引号（2026-10-27，KB 04 §6.25 Also）

`hanbing-mianzhang` / `hanbing-mianzhang2` 在 `random(` 前多了一个反引号，驱动按模板字面量读到 EOF。删掉。证明：HEAD 失败；改后加载。

## 深度功能测试（2026-10-27，§6.25 ZHAOSHI 截断玩家技能）

玩家自创武功在 `// ZHAOSHI : 0` 处截断（EOF），无法加载。按同系完整 `moming-blade` 补一招 + valid_*/query_*/practice（2）：`kungfu/skill/fuhu-unarmed.lpc`, `kungfu/skill/fulong-unarmed.lpc`。

## 深度功能测试（2026-10-27，§6.25 one-arg message_vision）

`message_vision("…")` 补第二参（`me` / `TP` / `this_player()`）。

