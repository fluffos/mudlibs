# bxsj.rar → `bxsj`

- Archive: `archives/bxsj.rar` (15.4MB — "书剑天下"/"ShuJian MUD", a
  substantial, actively-maintained-looking codebase, MudOS-lineage,
  `Copyright 1997-2004 ShuJian MUD Wizard Group`).
- Mudlib root in archive: `shujian/` (config lives one level up in
  `shujian/mudos/config.txt`, alongside a bundled `mudos/driver` Windows
  binary — ignored, we use our own driver). `mudlib directory : /tx` in
  the shipped config is the ORIGINAL developer's absolute server path,
  unrelated to our layout — always override, never trust this value.
- Port: **40004**. 9936 `.lpc` files after conversion — second-biggest
  lib so far.
- Note: this lib's `name :` is also "书剑天下", the SAME name as another
  archive in this collection (`书剑天下.rar`, TODO #36) — likely a
  different snapshot/version of the same underlying mud. Not the same
  archive (not a byte-duplicate), so processed separately per the
  standard pipeline; cross-reference when that archive's turn comes.

## Status: DONE — boots clean, playable over telnet

Reached name entry, length validation, existing-ID detection, and the
password prompt — full login flow confirmed working. This lib surfaced
three genuinely new (to this project) driver-interaction bugs, all
generalizable patterns now cataloged in `AGENTS.md`.

## What was fixed

1. Encoding: 10865 converted, 737 already UTF-8/ASCII, 75 skipped binary,
   36 lossy. **Found the `convert_lib.sh` binary-detection bug here**
   (AGENTS.md, "Encoding — `file`'s text/binary guess is not reliable
   enough to gate on"): `file` misclassified several genuine GBK **source**
   files as `data` (unusual CRCRLF line endings apparently confuse its
   heuristic) and the script silently skipped converting them, leaving raw
   GBK bytes in `work/`. Fixed the shared script (forces known text
   extensions regardless of `file`'s guess) AND manually converted the
   9 affected files found here (`feature/save.lpc`, `clone/user/
   olduser{,2}.lpc`, `adm/daemons/bbsd.lpc`, `cmds/std/testsjmud{1,2}.lpc`,
   `cmds/arch/ucp.lpc`, `cmds/wiz/movedata{2,cq}.lpc`) plus re-scanned
   libs #1-3 for the same issue (clean, 0 hits — this bug's impact was
   specific to whatever tool/era produced this particular archive).
2. `.c` → `.lpc`: 9936 files. 834 literal `.c"` refs auto-fixed, 0 left over.
3. `static` → `nosave`: 199 files.
4. No §4 (`load_object` in `valid_read`) issue in this master — checked,
   `valid_write`/`valid_read` call `SECURITY_D` via `find_object` only
   (no lazy `load_object`), so no recursion risk there.
5. **New bug (AGENTS.md §8, extended)**: `master.lpc`'s `log_error()` —
   the driver's own error-reporting callback — calls
   `CHANNEL_D->do_channel(...)` unconditionally. If `CHANNEL_D` isn't
   actually loaded at the moment a PRELOADED file fails to compile (which
   is exactly when `log_error()` runs), that call needs a fresh compile,
   which is forbidden mid-compile → `Object cannot be loaded during
   compilation` → which re-enters `log_error()` → cascades. This fired
   repeatedly during boot for multiple different failing preload entries.
   Fixed with the same reentrancy-guard + `catch()` shape as AGENTS.md §4.
6. **New bug (AGENTS.md §14 cousin)**: `master.lpc`'s `valid_override()`
   was 2-arg (missing the `main_file` parameter needed for `efun::` calls
   inside `#include`d simul_efun fragments) AND defaulted to **deny**
   (`return 0`) rather than allow for anything not explicitly listed —
   stricter than lib #1's version. Added the 3rd parameter, plus an
   explicit allow-list for the simul_efun message-formatting wrappers
   (`shout`/`write`/`tell_object`/`tell_room`/`say`) that `cmds/adm/ad.lpc`
   needed via `efun::shout(...)`.
7. **New bug, the real blocker for this lib (AGENTS.md §8c) — took the
   most effort to find**: `securityd.lpc`'s `valid_read()` had
   `if (this_player()) user = this_player();` unconditionally, which
   wrongly attributed a SYSTEM-initiated lazy `load_object()` (master
   loading `BAN_D`/`band` and `UPTIME_CMD`/`cmds/usr/uptime`, neither
   preloaded, both first touched from inside a brand-new connection's own
   login sequence) to that connecting player's own unprivileged
   permissions instead of the real (root-euid) caller — an `exclude_read`
   rule protecting `/adm` from ordinary players then denied it, **which
   permanently stranded every single new connection** at the login banner
   (no compile errors anywhere — looked like a total, silent hang).
   Diagnosed via a temporary instrumented `master.lpc valid_read()`
   (logged file/user/func/result to a scratch file) rather than guessing
   from the generic `*Read access denied.` message — found the exact two
   denied `load_object` calls in minutes. Fixed: only override with
   `this_player()` when the passed-in `user` doesn't already have a
   resolvable euid/uid.

## Known remaining issues (documented, not fixed)

- 78 lpcc-sweep failures (post-fixes; was many more before). Notable
  categories left un-triaged: `Bad type for argument 1 of is_killing`
  (9 files), `Undefined function set`/`set_temp` (10 files combined),
  optional network/mail daemon cluster (`member_group`,
  `data_netmail_file` — same missing-headers shape as libs #1/#2), a
  handful of scattered `Undefined function/variable` content gaps.
- `clone/misc/tang.lpc`: one string literal built entirely from octal
  byte escapes (`"\377\371\377\376\042\377\374\005..."` — raw telnet
  protocol/control bytes, not text) that has no valid representation as a
  UTF-8 LPC string in this driver (old drivers had raw 8-bit strings).
  Would need converting to a `buffer` literal to fix properly; one
  obscure clone item, not fixed.

## How to run

```
cd libs/bxsj
~/src/fluffos/build-debug/src/driver config.fluffos
python3 ../../scripts/mudclient.py 127.0.0.1 40004 --timeout 10 --send "n" --send "testuser" --send "quit"
```

## Post-hoc fix: UTF8-native is_chinese/registration (AGENTS.md §15h)

Applied in a later batch pass across the whole project: `is_chinese`/`is_chinese2`
in the shared `chinese.lpc` simul_efun fragment used GBK byte-range checks that
silently never match real Chinese text once strings are UTF-8 (this driver's
`str[i]` returns a Unicode codepoint, not a GBK byte). This broke character
registration specifically -- any real Chinese name was rejected. Fixed the
range check to test the CJK Unicode block instead, and halved the
GBK-byte-calibrated length bounds in `check_legal_name` to match. See
AGENTS.md §15h for the full writeup; confirmed via a real interactive
registration test (Chinese surname + given name reaching the next prompt).

## Retroactive fix (found via archive #90, jinyongwenzi): this lib was completely command-dead after registration (AGENTS.md §15ae + a new commandd.lpc variant)

Archive #90 (`金庸文字版.exe`) turned out to be the literal same codebase as
this lib (byte-identical `master.c`/`securityd.c`/`chinese.c` after CRLF
normalization -- confirmed via diff, not assumed) processed much later in
the project, after §15ae (the `private nomask` command-hook bug) had
already been discovered and fixed elsewhere. That later pass found this
exact lib had TWO independent bugs compounding into the same symptom --
every single post-login command (even `look`) silently doing nothing at
all, with zero error anywhere:

1. **`feature/command.lpc`'s `command_hook()`** was `private nomask` --
   unreachable via `add_action`'s external dispatch on this driver (§15ae).
2. **`adm/daemons/commandd.lpc`'s `rehash()`** filtered `get_dir()` output
   via `sscanf(cmds[i]+"$", "%s.c$", cmds[i])` -- a live `sscanf` pattern
   invisible to both the `.c`→`.lpc` rename's quoted-string fixer and the
   bare-data-file fixer, since it's neither. After the rename this matched
   zero files forever, so `commandd`'s command-search table was never
   populated and `find_command()` always returned 0 -- a second,
   independent cause of the exact same symptom. Fixing only one of the two
   would still have left every command dead.

Both fixed here (dropped `private`; changed the sscanf pattern to
`"%s.lpc$"`), then re-verified with a full fresh registration (real name,
one of "秦风"/"秦岭"/"秦河" tested across a few runs) followed by `look`,
`score`, and `quit` all producing correct real output, and `debug.log`
confirmed clean (0 `error:` lines). This lib's ORIGINAL testing pass (see
above) never verified a post-login command -- exactly the blind spot §15ae
warns about -- so this had been silently broken since this lib was first
marked "done," undetected until the sibling codebase surfaced it. See
AGENTS.md §15ae and the new commandd.lpc sscanf-pattern addition for the
general writeup.

## Re-verification pass (2026-07-23): driver rebuild + LPC formatter + WASM build

- **Formatter**: ran `format-corpus.mjs` over all of `work/` (9,936
  files, 9,681 written/reformatted, 102 already-clean, 153 refused with
  an error — expected on legacy code, not chased individually).
- **Native retest against rebuilt driver** (`build-debug/src/driver`,
  rebuilt from latest upstream master): clean boot, zero fatal errors in
  `debug.log`. Full registration re-verified end-to-end on the
  now-reformatted source with a fresh real Chinese name (`秦叔`, ID
  `qinshu`) through the complete flow (ID → password, which must contain
  both a digit and an uppercase letter and not be "too simple"/derived
  from the ID → Chinese name → talent roll → email → gender), reaching
  the actual game world (武馆前院 starting room) with the welcome-NPC
  escort dialog (`狄云`) firing correctly; `look`/`score`/`quit` all
  produced correct output (the full 个人资料卡 stat card rendered
  correctly), zero real errors in `debug.log`. No regressions from the
  reformat or the fresh driver build.
- **WASM build**: preload completes with only the expected non-fatal
  `sockets`-package gap (`adm/daemons/network/dns_master.lpc`'s
  `socket_create`/`socket_close` → `Undefined function`, caught by
  `master.lpc`'s own error handler exactly as for a missing daemon
  natively — `Initializations complete.` still printed). Registration
  itself is blocked by the **exact** documented `query_ip_number()`
  WASM-mode limitation this project's tooling docs call out by name for
  this lib: `adm/daemons/sited.lpc`'s site-restriction check rejects
  every attempted ID with "对不起，这个英文名字不能从当前地址登录。"
  ("sorry, this name cannot log in from the current address") because
  the wasm loopback connection's `query_ip_number()` doesn't format as a
  real dotted-quad. **Not a mudlib bug** — this is the documented
  driver-side gap, not something to patch. Verdict: boots cleanly under
  WASM; registration cannot complete due to the driver's IP-check
  limitation.

## WASM-enablement pass (2026-07 standard: loopback-allow, throttle exempt, admin seed)

Gates patched (all short-circuit loopback / malformed-empty IP first, original logic intact below):

- `adm/daemons/band.lpc` `is_banned()` (~line 40): loopback/`127.`-prefix/
  non-string/malformed-IP → `return 0` (never banned).
- `adm/daemons/sited.lpc` `is_valid()` (~line 37): loopback → `return 1`
  (site always valid). `is_multi()` (~line 65): loopback → `return 0`
  (multi-login throttle exempt; moved `IP_D->ip2name` below the guard so a
  garbage IP never reaches it).
- `adm/daemons/logind.lpc` `logon()` (~line 95): per-IP concurrent-connection
  cap (`login_cnt > 3`) now only destructs a real remote dotted-quad; loopback
  and malformed/empty IPs exempt.

Notes:
- The ACTIVE login daemon is `adm/daemons/logind.lpc` (LOGIN_D, called by
  `clone/user/login.lpc`), NOT the root `/logind.lpc` (dead copy — left
  untouched). `gb_big5()` already wraps `BAN_D->is_banned` in `catch()`
  (fail-open), and the band.lpc guard now also returns 0 for loopback.
- No `uptime()` startup-grace gate rejects connections in this lineage
  (the `uptime()` calls in logind are content timers — robottest, set_temp
  "time" — kept).
- `get_id()`'s `wiz_level(arg) < wiz_lock_level` gate: `WIZ_LOCK_LEVEL` is 0
  here, so normal players pass; left as-is.

Admin account: id `fluffos` / `Mud@2026` / 浮浮, granted `(admin)` via
`adm/etc/wizlist`. Verified `update` + `goto` work. **Save files for the
orchestrator to force-add: `libs/bxsj/work/data/user/f/fluffos.o` and
`libs/bxsj/work/data/login/f/fluffos.o`** (untracked new dirs; not
gitignored).

Retest: fresh registration (id `fluffos`, name 浮浮) reached 武馆前院,
`look`/`score` correct. Pre-existing content errors unrelated to this pass
remain in debug.log (`message()` bad-arg in `user.lpc` `user_dump()`;
`call_other()` bad-arg from NPC 桃花 `carry_object`).


## Retrofit (2026-07-24): fail-closed loopback check (security correction)

The loopback-allow gate patched above originally also treated a
non-string/empty/malformed `query_ip_number()` result as loopback (a
defensive stand-in for the WASM driver bug). That driver bug is now fixed
upstream, so this was tightened to fail-closed: only an exact
`"127.0.0.1"` / `"127."`-prefix / `"::1"` match bypasses the gate; a
malformed or non-string address now falls through to the original gate
logic (treated as untrusted/remote) instead of being auto-allowed.
Re-verified fluffos login still works after tightening.

## 深度功能测试 / Deep functional test (2026-07-24)

First real *playthrough* pass on this lib (all prior passes verified only
registration + `look`/`score`/`quit` + admin login, or watched boot output).
Played as an ordinary new player through most systems, native driver
(`build-debug`), with a WASM re-verification of the one fix made. Test
character: id `qintest`, Chinese name 秦风, password `Abc12345` —
**kept** (not cleaned up) as a representative playthrough character; it
joined 武当派 (Wudang) via the newbie gift-envoy shortcut and has a
reasonably rich state (skills, family, rank-table entry) that's useful
evidence of a working system. Save files:
`work/data/user/q/qintest.o`, `work/data/login/q/qintest.o`.

### Bug found and fixed

**`cmds/usr/top.lpc` — unbounded per-hour rank-decay loop crashed on
literally every `quit` (and on `top`), file:line `cmds/usr/top.lpc:395-401`
(the live `add_rank()`) plus four sibling copies of the identical pattern
in `add_rank_beauty()` (~179), `add_rank_pk()` (~224), `add_rank_rich()`
(~271), `add_rank_worker()` (~338).**

- Symptom: every single `quit` (via `cmds/usr/quit.lpc:218`'s
  unconditional `TOP_CMD->add_rank(me)`, called for every player
  regardless of rank) and every `top`/`top beauty`/`top pk`/`top rich`/
  `top worker` invocation triggered a caught-but-real runtime crash:
  `执行时段错误：*Too long evaluation. Execution aborted.` (eval-cost
  limit, 50,000,000 usec) inside the rank-decay loop. Invisible to the
  player (the driver's error handler catches it and `quit`'s own visible
  output — "正在退出游戏……" — looks completely normal), so it was
  never caught by any prior pass that only checked `quit` "looks right"
  to the player. Classic instance of the project's own §8.3/§10.1 lesson
  generalized one level further: **a command whose visible output is
  correct can still be silently crashing server-side; grep debug.log
  after every `quit`, not just after login.**
- Root cause: each `add_rank*()` function keeps a per-entry `"time"`
  field on its saved rank-table rows and, for any currently-offline
  entry, runs `while (rank["time"] + 3600 < t) { rank["time"] += 3600;
  rank["score"] = rank["score"]*97/100; }` to decay that player's score
  by ~3%/hour since it was last touched — fine on the original always-on
  server where `t` only ever drifts forward by however long the driver
  has been up between calls. This project's restoration ships the
  archive's real shipped `/log/rank` save data verbatim (genuine
  2008-era player rankings, `"time":1219369347` etc.) and boots it fresh
  against **today's** real wall clock — a ~566,000,000-second (18 real
  year) gap per entry, i.e. ~157,000 required loop iterations for a
  single stale row, times up to 99 rows. Trivially blows the eval-cost
  limit on the very first call. This is a new, general bug class for
  this project (a decay/catch-up loop keyed off a *stored* real
  timestamp vs. the *current* real clock, safe under continuous
  original operation, pathological once an old save is booted fresh
  against a modern clock) — not previously cataloged in AGENTS.md;
  written up there now. Grepped the rest of the lib for the same shape
  (`while.*\["time"\].*< *t\b`, `while\s*(.*time()`) — these five are
  the only live occurrences (a sixth copy at `top.lpc:~556` is inside an
  already-dead `/* ... */`-commented duplicate `add_rank()`, untouched).
- Fix: capped every one of the five loops at 240 iterations (10 days'
  worth of hourly decay, already enough to crush any stale entry's score
  to near zero) and unconditionally set `rank["time"] = t` afterward
  (matching what the existing `else` branch already does for online
  players), so a still-stale-after-240-iterations entry just jumps its
  clock forward rather than looping further. Preserves the original
  per-hour compounding behavior for any realistic gap; only changes
  behavior for the pathological >240-hour-offline case, where the score
  was already going to be decayed to noise anyway.
- Verified: reproduced live pre-fix (debug.log showed the exact "Too
  long evaluation" trace rooted at `add_rank()` lines 399/400, called
  from `quit.lpc`'s `do_quit()`); rebuilt nothing (LPC-only change),
  killed and rebooted the native driver, re-ran `qintest` through
  several fresh `quit`s and `top`/`top pk`/`top worker` — zero eval-cost
  errors afterward, and `top`/`top worker` now render `qintest`'s real
  entry (综合评价 3470, worker score 200) instead of silently never
  getting inserted. Re-verified under WASM (`node scripts/wasm_client.js
  ~/src/fluffos/build-wasm/src libs/bxsj`, login as `qintest` + `look` +
  `score` + `quit`): clean, no eval-cost error in the captured
  stdout/stderr.

### What was tested and confirmed working

Full continuous playthrough as `qintest` (ordinary new player), plus one
wizard-flavored digression through the game's own "newbie gift" NPC
(see below) to reach the menpai/skills systems without a long trek:

- **Registration**: real Chinese name (秦风), full flow (id → password
  with digit+uppercase validation → confirm → name → talent roll/accept
  → email → gender) — already known-good from prior passes, re-confirmed.
- **Movement/exploration**: walked the 武馆 (martial-hall) starting zone
  (`d/wuguan/`) — `武馆前院`→`东练武场`(`wuchang3`)→`东武场`(`wuchang4`,
  training dummy)→`兵器库`(armory)→`碎石路`→`门廊`, `look`, `look
  <item-id>` (`paizi`/`shakeng`/plaque banners) all render correctly;
  exits, room descriptions, day/night flavor text all correct.
- **Character info**: `score` (the 个人资料卡 stat card — attributes,
  title, master, money, kills/deaths, etc.) and `hp` (精/气/精力/内力/
  食物/饮水/潜能/经验 bars) both correct at every stage (fresh, post-gift,
  post-sect-join). `i`/inventory correct throughout, including the □
  "equipped" marker convention.
- **Combat**: `d/wuguan/wuchang4`'s 木人 (training dummy, `muren.lpc`) is
  this lib's designated safe newbie sparring target — its
  `accept_fight()` literally mirrors the attacker's own stats/skills for
  a fair, non-lethal bout. `fight muren` produced a full turn-by-turn
  combat log (attack/dodge/parry narration, qi/jing damage, fatigue
  messages) and correctly auto-halted at the ~50% resource threshold
  ("木人胜了这招，向后跃开三尺，笑道：承让！") exactly as `help newbie`
  documents `fight` (vs `hit`/`kill`) should behave. No crash, no
  over-death.
- **Skills/kungfu**: the organic first-skill path is `d/wuguan/wuchang3`'s
  武馆教头 NPC (`jiaotou.lpc`, `recognize_apprentice()`/`is_apprentice_of()`
  both hardcoded `1` — teaches ANY player without a formal `apprentice`
  first), via `cha jiaotou` (list his skills) → `xue jiaotou <skill>`
  (learn) — command dispatch and ACL confirmed working (`cha`/`xue`
  correctly require the teacher NPC to be physically present, correctly
  reject skills he doesn't teach with "这项技能你恐怕必须找别人学了"across
  the codebase). `lian <skill>` (practice) correctly refuses base
  skills not yet `enable`d as a special technique
  ("你只能练习用 enable 指定的特殊技能") — matches `help newbie`'s
  documented model (practice targets `enable`d special/menpai moves, not
  raw base skills) — not a bug. Full skill-list/enable/practice loop
  verified via the sect-join path below, which grants real special
  skills: `skills` lists 职业/杂项/基本/特殊 categories correctly;
  `enable strike taiji-quan` and `lian strike` both exercised (rejected
  post-Wudang-join with "这个技能不能当成这种用途" because the
  gift-granted 太极拳/太极剑 etc. are already the intended `strike`/`sword`
  specials and — investigated — `taiji-quan` maps to `cuff` not
  `strike`, i.e. correct rejection of a mismatched base/special pairing,
  not a bug).
- **Items/equipment**: `d/wuguan/bingqiku`'s 兵器架 (`na jian from jia`,
  one-per-character via a `marks/拿` temp flag) — correctly grants a real
  `长剑` weapon; `wield`/`unwield` both correct (wield message, weapon
  shown unmarked vs `□`-marked armor in `i`). `remove cloth`/`wear cloth`
  round-trip correct.
  **Discovered, NOT a bug — flagging per the "real design tradeoff"
  instruction**: `cmds/usr/quit.lpc:146` drops (not destroys, unless
  valueless) every carried item that doesn't implement `query_autoload()`
  or `query("unique")` when a non-wizard quits — confirmed live (a
  picked-up sword, and even the starting 布衣/布履, vanished from
  inventory after a `quit`; a *silent reconnect* — driver-level
  `net_dead()`/`find_body()` re-attach without a real quit — preserves
  everything, only an explicit `quit` sweeps). This is real, deliberate
  ES2-lineage-family original design (present in the raw archive, not
  introduced by conversion) — an anti-hoarding mechanic, not a
  persistence bug — but it means ordinary gear a player spends time
  earning is NOT expected to survive a `quit` unless flagged
  `autoload`/`unique`. The only reason default clothes don't visibly
  "disappear forever" is that `adm/daemons/logind.lpc:691`
  (`UPDATE_D->get_cloth()`) unconditionally re-grants fresh (and, once
  in a sect, sect-appropriate) clothing on every *full* login — masking
  the loss for that one item category. Left entirely as-is (§7.14 "don't
  fabricate/alter deliberate content" applies to mechanics, not just
  rooms); noting it here because it's exactly the kind of thing a player
  or a future tester could easily misdiagnose as a save/persistence bug.
- **NPCs/social**: `ask <npc> about name/rumors/here` (the three
  standard questions every non-animal/non-mute NPC answers per
  `help newbie`) all produced correct, in-character dialogue on 宋远桥
  (Song Yuanqiao, Wudang's hall master). `say`/`emote` both correct.
  `chat`/`rumor` channels both correct (rumor correctly anonymizes the
  speaker to "某人"; chat shows the real name) — matches `help newbie`'s
  documented distinction. `tell <self>` correctly rejected
  ("告诉自己？").
- **Quests**: the newbie escort/tutorial chain (`d/wuguan/npc/diyun.lpc`
  and its near-duplicate `dizi7.lpc`/冯坦, both driving the SAME
  `wgtask`/`wgmeet`/`wgquestion` player temp-var state machine) gates
  `d/wuguan/dayuan.lpc`'s southward exits ("你先回答了冯坦的问题再离开也
  不迟啊！") until answered — confirmed both the accept path
  (`answer y` → move-command tutorial → directs to 孙均) and the decline
  path (`answer n` → skips straight to the "find work" branch) work.
  **Note**: `wgtask`/`wgmeet`/etc. are `nosave` *temp* vars, so a
  low-`combat_exp` character gets re-approached and re-gated on every
  FULL login (not on a silent reconnect) — mildly repetitive UX but
  consistent/correct, not a bug (temp state resetting on reconnect is
  expected LPC behavior, and the gate is always answerable).
- **Menpai/sect**: two independent paths confirmed —
  1. *Organic*: `bai <master>`/`apprentice <master>` on a real
     family-affiliated NPC (宋远桥) — first call ran the full accept
     flow ("你想要拜宋远桥为师。...你跪了下来...恭喜您成为武当派的第三
     代弟子。"), second call correctly recognized the existing
     relationship ("你恭恭敬敬地向宋远桥磕头请安"). `cha song` correctly
     lists his 14 skills incl. `□`-marked (enabled) special techniques.
  2. *Newbie-gift shortcut*: `d/wuguan/npc/shizhe.lpc` (「书剑天下礼物
     使者」, present in the starting room) — `ask shizhe about newbie`
     (wipes skills, grants a large stat/VIP boost) →
     `ask shizhe about 拜师` → `ask shizhe about <门派名>` — instantly
     joins any of 15 sects with a full max-level special-skill kit and
     teleports to that sect's hall. This is clearly an intentional
     in-game "catch-up"/GM-flavored newbie reward (explicit "为鼓励
     newbie特此奖励" message), not a bug — used here deliberately as a
     fast path to reach and verify the skills/family systems without a
     long trek, then cross-checked against the organic `bai` path above
     to confirm both converge on the same, correctly-recognized
     `family`/`is_apprentice_of` state.
- **Persistence**: confirmed at both layers this lib has —
  (a) *silent reconnect* (driver `net_dead()` leaves the body object
  alive in the world; next login's `find_body()` + `!interactive()`
  re-attaches it with zero data loss, no re-`look`) — exact room,
  inventory, HP all preserved;
  (b) *full quit+relogin* (real `save()`/`restore()`) — stats, skills,
  family/sect membership, and title all round-tripped correctly across
  multiple cycles (only the item-drop-on-quit mechanic above affects
  inventory, and that's original design, not a persistence defect).
- **Economy/shops**: reviewed at the code level (`inherit/room/shop.lpc`,
  `clone/shop/yangzhou_shop.lpc` — a player-consignment auction house
  requiring player-crafted "imbued" goods, not a fixed-price vendor;
  `feature/vendor.lpc`/`F_VENDOR`-based fixed-goods peddlers like
  `clone/npc/huolang.lpc` and `d/xiangyang/npc/niulaoban.lpc`'s 杂货铺
  general store, `buy`/`list`/`sell` all implemented with correct
  money checks) — **not live-verified end-to-end** (no successful
  purchase completed). The nearest confirmed fixed-price vendor
  (`d/xiangyang`'s 杂货铺) is a genuine trek from the starting `d/wuguan`
  zone, and the sect-join shortcut relocated the test character to a
  third, even more distant zone (Wudang mountain); chasing a full
  buy/sell round-trip across that distance was deprioritized given the
  time budget once the code review turned up no red flags. Free-goods
  interactions (武馆's own `d/wuguan/chufang.lpc` kitchen, `get`/`eat`
  free tea/rice) were identified as reachable but likewise not live-run.
  **Flagged as a real gap in this pass, not a "confirmed working"
  claim** — a future pass on this lib (or the next tester following this
  checklist) should prioritize a live shop transaction early, before
  wandering into an unrelated zone.
- **Death/respawn**: **not conclusively live-tested**, noted honestly
  rather than guessed. `feature/damage.lpc:210`'s `die()` was reviewed
  (looks structurally sound — listener hooks, wizard-immortal guard,
  arena-specific branch, falls through to `reincarnate()`) but not
  triggered. The `muren` spar's built-in 50%-resource auto-halt (see
  Combat above) confirms the *combat-safety* half of this works. Two
  live paths were identified but not pursued: `kill muren` (removes the
  auto-halt; since `muren` mirrors the attacker's exact stats it's
  close to a fair coin-flip fight, so *could* produce a real, controlled
  player death) and `suicide -f` (a real, sanctioned `die()` trigger
  requiring either a bladed weapon in hand or force-skill ≥500 — the
  test character had neither at the point this was considered, having
  already dropped its sword per the quit-drop mechanic above). Skipped
  because the character was, by that point, deliberately overpowered by
  the newbie-gift shortcut (combat_exp 1,000,000, skills ~201) relative
  to any easily-reachable NPC, making genuine self-endangerment
  impractical without a further trek to find a dangerous opponent, and
  the time budget was better spent chasing the `top.lpc` crash (a
  confirmed, live, every-single-quit bug) to a real fix. Left as a
  concrete to-do for whoever plays this lib next.

### Methodology notes (for the broader pass this seeds)

- **The `top.lpc` bug is the single most important finding of this
  pass, methodologically**: it was invisible to every previous
  verification because "the visible output of `quit` looked correct."
  **New standing checklist item**: after every `quit` in a deep pass
  (not just after login/registration), re-grep debug.log for fresh
  error/crash lines before moving on — a caught server-side error can
  ride along behind a perfectly normal-looking client-visible message.
- **Restored archives carry real historical timestamps as data, and
  this driver's `time()` is the real wall clock** — any lib that ships
  saved data with a `"time"`/`"date"`/epoch-like field consumed by a
  *loop* (not a one-shot comparison) is a candidate for this same class
  of bug. A one-shot `if (time() - x > N)` is safe; a `while` (or
  recursive) catch-up keyed off the same gap is not. Worth a
  `grep -rn 'while.*time()\|while.*\["time"\]'` pass on any newly-picked-up
  lib with old shipped rank/leaderboard/decay data.
- **Wandering NPCs make room-content assumptions stale mid-script.**
  Several `chat_msg`-driven NPCs here (`jiaotou`, `huolang`, `zhanggui`)
  include `(: random_move :)` — a scripted multi-step test that assumes
  "NPC X is still in room Y" three commands later can silently fail for
  reasons unrelated to the system under test. Prefer a `look` right
  before any NPC-dependent command in a scripted session, or accept the
  occasional need to re-plan a step live.
- **A single continuous connection is much more valuable than several
  short ones** for this class of lib: this lineage's login flow has (a)
  a 30-second real-time anti-flap lock keyed off `last_on` (set on BOTH
  clean quit and raw disconnect) that rejects a same-ID reconnect
  attempted too soon, and (b) a "silent reconnect" path that reuses the
  live in-memory body (no fresh `look`, no `get_cloth()` re-grant,
  exact position preserved) whenever the previous session ended without
  a real `quit`. Both are correct, deliberate behavior (§1.3e-style
  quit-retention timer, kept per AGENTS.md policy) but they mean a
  test harness that reconnects between every few commands will
  intermittently (a) get locked out for 30 real seconds, and (b)
  silently skip the full-login code path (banner, `get_cloth()`,
  quest-greeting re-fire) that a "fresh login" test actually wants to
  exercise. Plan a script's full command sequence in ONE session where
  possible; only split across reconnects when specifically testing the
  reconnect/persistence path itself, and expect to need real wall-clock
  waiting (not a instant retry) between separate connection attempts —
  standalone `sleep` is blocked in this harness; use a backgrounded
  `sleep N && echo ready` (`run_in_background: true`) and continue other
  (non-connection) work in the meantime rather than idling a live
  connection at the login prompt (idling at the BIG5-font prompt itself
  trips a *separate*, unrelated 30-second `login.lpc` `time_out()` — see
  `clone/user/login.lpc:19-39` — so "just wait inside the open
  connection" doesn't work either).
- **A "safe newbie combat area" is worth identifying by name early.**
  This lib's is a training-dummy NPC (`muren.lpc`) whose `accept_fight()`
  deliberately mirrors the attacker's own stats — a reusable pattern
  worth grepping for (`accept_fight` + a stat-copy loop from
  `ob->query_skills()`) on any wuxia lib before assuming combat testing
  requires finding a "safe" wild NPC by trial and error.
- **A lib's own `help newbie`/`help intro` file (when present) is the
  single highest-value source for planning a systematic test path** —
  it directly named the exact commands (`fight` vs `hit`/`kill`,
  `apprentice`/`bai`, `learn`/`xue`, `practice`/`lian`, `enable`/`jifa`,
  `ask ... about ...`, `chat`/`rumor`) and explained WHY each system
  behaves the way it does, turning what would otherwise be a slow
  trial-and-error command-guessing exercise into a directed one. Read it
  in full before starting the playthrough, not just when something looks
  wrong.
- **A deep-test checklist for this class of lib (menpai/kungfu/wuxia),
  distilled from what actually mattered here**, roughly in the order
  that paid off fastest:
  1. Read the lib's own newbie help file (if any) FIRST — it's usually a
     complete command reference for exactly this checklist.
  2. One continuous session: register → `look`/`score`/`i` at each major
     state change (not just once) → explore the starting zone's `exits`
     by reading room `.lpc` files rather than guessing, to plan an
     efficient route instead of bumbling into dead ends live.
  3. Identify and use the lib's own "safe sparring" mechanism if one
     exists (grep `accept_fight` for stat-mirroring or an explicit
     newbie-dummy flag) before hunting for a "weak enough" wild NPC.
  4. Learn ONE skill via the organic teacher-NPC path AND verify the
     sect-join (`apprentice`/`bai`) path separately — they can be
     inconsistent or one can be gated behind the other; both are cheap
     to test once located.
  5. `quit`, grep debug.log, THEN reconnect (real wall-clock gap) and
     confirm state — do not skip the debug.log grep even though the
     player-visible `quit` message looked fine.
  6. Shop/economy and death/respawn are the two systems most likely to
     require genuine travel/setup investment (money, a dangerous
     opponent) — budget time for them explicitly, or explicitly flag
     them as unverified rather than silently skipping past them.

## WASM 修复摘要（迁移自 meta.json 的 group_note）

书剑 MUD 家族的基础版本。状态已从过时的 limited 修正——这份档案自己的 NOTES.md 记录了一次完整的原生驱动深度功能测试（2026-07-24），以普通新玩家身份走完了注册、移动、人物信息、战斗（木人安全对练机制）、门派/技能系统，并在过程中发现并修复了一个真实 bug（cmds/usr/top.lpc 的 add_rank() 系列函数：一个不设上限的按小时衰减排名循环，一旦这份 2008 年代的存档数据配上现代系统时钟运行，每一次 quit/top 指令都会撑爆求值成本上限——已限制在 240 次迭代以内）。只有商店/经济系统和死亡/复活没有被实测覆盖到（是测试覆盖缺口，不是已知损坏）。这份档案自己的 README 没有记录任何缺陷，本轮也没有发现新的。本轮在当前 WASM 驱动构建下重新验证了预先播种的管理员账号登录（fluffos/Mud@2026，look/score/quit 全部正常，"您目前的权限是：(admin)"）——由于 NOTES.md 里 2026-07-24 的深度测试已经完整覆盖过注册流程，本轮没有重跑注册；同一代码家族的手足档案 bxsj1 本轮则重新完整验证过一次注册流程，结果一致。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 1 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## Deep functional test round two (2026-08-14)

Independently re-verified every §10.7 checklist item against current code
rather than trusting the 2026-07-24 writeup above. One proactive hardening
fix applied; the one real bug found in round one (`top.lpc`'s rank-decay
crash) was re-confirmed still fixed via a genuine live regression test on
the same character that originally triggered it, not just by grepping the
diff.

### Fix: `adm/simul_efun/file.lpc`'s `cat()` had no null-guard on `read_file()`

Standard proactive hardening for this session's checklist (§7.11-adjacent):
`cat()` called `write(read_file(file))` unguarded — `read_file()` returns
`0` for a missing/unreadable file, and `write(0)` is a latent throw risk.
```lpc
// BEFORE:
void cat(string file) {
  write(read_file(file));
}
// AFTER:
void cat(string file) {
  write(read_file(file) || "");
}
```
`log_file()` in the same file was already correctly hardened — it delegates
to `LOG_D->log_file()` (`adm/daemons/logd.lpc`), which unconditionally calls
`assure_file(file)` before every write regardless of the optional `db` flag
(the `if (db)` only guards the preceding `dbquery()` call — misleading
indentation, correct semantics, verified by reading the actual statement
boundaries rather than trusting the visual layout). No callers in this lib
pass a truthy `db` flag, so the MySQL `dbquery()` branch is dead code, not
exercised, not a live risk.

Checked and ruled out as not applicable to this lib: no `log_error()`
severity-gate case-mismatch (none found in `adm/single/master.lpc`), no
`dbase.lpc` password-write-guard shape (this lib's admin seeding doesn't use
that pattern), no `%`-operator-on-corrupted-float shape beyond the
already-corpus-fixed `quest_times`/`win_times` class (the only unguarded `%`
hits found were unrelated weight-formatting arithmetic in
`d/city/weapon/weapon*.lpc`, not attribute counters), no §8.9 food/water
wrong-object read, no `printf` debug leaks in `logind.lpc`.

### Re-verified live: `top.lpc` rank-decay crash (round one's fix) still holds

Logged in as `qintest` (the same character whose `quit` originally
reproduced the crash on 2026-07-24) rather than trusting the diff was still
applied. `top` correctly rendered the real ranking entry (综合评价 3470),
and `quit` — the exact original crash trigger, since `cmds/usr/quit.lpc`
unconditionally calls `TOP_CMD->add_rank(me)` — completed with zero new
`work/log/debug.log` lines (checked the file's line count before and after:
unchanged). The original crash was invisible in the player-facing output
even when it was happening, so a clean-looking `quit` message alone isn't
sufficient evidence; the debug.log line-count check is what actually
confirms it.

### Verification method

Booted native `build-debug` driver, admin login (`fluffos`/`Mud@2026`) with
`update /adm/daemons/logind` as the real privileged-action check (succeeded
— "重新编译 ... 成功！"; `adm/simul_efun/file.lpc` itself is `#include`'d into
`adm/single/simul_efun.lpc`, a container object, so it can't be `update`'d
directly — same limitation documented elsewhere this campaign). Two rapid
consecutive admin reconnects, both clean, both landing a full fresh login
(上次连线 timestamp updated each time). One login attempt as `qintest` timed
out mid-password-entry on the login procedure's overall timer
(`clone/user/login.lpc`'s `time_check()`/`time_out()`) when sent via too
many separate tool calls; resolved by sending the whole
id+password sequence as a single batched `tmux_mud.sh multi` call with a
slightly longer per-line wait — not a mudlib bug, a test-harness pacing
issue (this lib's overall login-procedure timeout is comparatively tight).
Noted a stale `FATAL ERROR: SIGTERM: Process terminated` line at the tail of
`work/log/debug.log` predating this session's own boot — the driver
(confirmed via `readlink /proc/<pid>/cwd`) stayed alive and responsive
throughout testing, so this is leftover content from an earlier, unrelated
process instance sharing the same log path, not a live crash; not
investigated further since it didn't correlate with any actual failure
during this pass. Driver killed by exact PID after testing; incidental
`fluffos.o`/`qintest.o` save-timestamp churn reverted before commit.

### Files modified this pass

- `work/adm/simul_efun/file.lpc` — `cat()` null-guard on `read_file()`.

## Round three deep functional test (2026-08-18)

Went deeper than rounds one/two per the standing checklist: real combat
death/reincarnation (not just code review), board post/read, shop dispatch,
and a persistent-guild command smoke test — plus a project-wide sweep for
three newly-catalogued bug patterns (AGENTS.md §7.111/§7.112, and the
§8 logind.lpc `enter_world()` missing-save shape).

### Bug found and fixed: §7.112 unguarded reincarnation-chain `init()` (2 live instances + 1 hardening)

Grepped every `init()` containing a `call_out(` corpus-wide (2,278 files have
`init()`, 543 also schedule a `call_out`; narrowed to 81 candidates lacking
any existing `remove_call_out`/`query_temp` guard, then to the ones whose
scheduled function recursively re-schedules itself — a genuine multi-stage
chain, not a one-shot timer). Two real hits, both in the death/reincarnation
zone (`/d/death/`), exactly matching the reference shape from
`haiyang2`/`jym`'s `wgargoyle.lpc`:

1. **`work/d/death/npc/death.h`** (included by `mengpo.lpc`/孟婆,
   `yanluo.lpc`/阎罗, `pusa.lpc`/菩萨 — the three reincarnation-guide NPCs a
   dead player's ghost meets) — `init()` unconditionally scheduled a 5-stage
   `death_stage()` message/teleport chain (first stage 20-40s out, then 5s
   between stages) with no guard. Since the driver re-broadcasts `init()` to
   every NPC in a room whenever a living object's commands are enabled
   (including on a player reconnect), a player who disconnects and
   reconnects while standing in front of one of these NPCs — very plausible
   given the 20-60s window — would stack a second parallel chain: doubled
   dialogue, and a second `reincarnate()`/move at the end.
2. **`work/d/shaolin/npc/yu-zu2.lpc`** (狱卒, a Shaolin-jail guard) — same
   unguarded shape, its own private 5-stage `death_stage()` chain (60s
   between stages) ending in `ob->move("/d/shaolin/woshi1")`. Grep found no
   room anywhere in the corpus that currently places this NPC (a sibling
   `yu-zu.lpc`, no "2", is the one actually used in `d/shaolin/jianyu1.lpc`,
   and it already has its own correctly-guarded `remove_call_out`+`call_out`
   pattern) — `yu-zu2.lpc` looks like dead/orphaned code today, but fixed it
   anyway since the shape is real and harmless to guard.

Fix (matching the documented reference shape): a `death_stage_active`
per-player `set_temp()`/`query_temp()` guard around the `call_out()`
scheduling call in `init()`, cleared at every exit point of
`death_stage()` (the ghost-already-resurrected early return, the
target-left-the-room early return, and the final completion branch).

**Proactive hardening in the same zone**: `work/d/death/gate.lpc` (地门/鬼门关
— `DEATH_ROOM`, the very first room a dying player lands in) had the
identical unguarded shape one level up — its own `init()` unconditionally
scheduled a `call_out("run", 1, me)` that randomly routes the ghost into
`gateway`/`mpting` (yanluo/mengpo). Narrower window (1s) and more benign
outcome (a duplicated flavor-text line, and a possible unwanted second
random reroute) than the death.h chain, but same class of bug and directly
in the path being live-tested here, so hardened it with the same
`gate_run_active` guard shape for consistency.

**Live-verified end-to-end, twice**:
- As admin (`fluffos`), became a ghost (`ghost`), then `goto`'d into
  `/d/death/mpting` (mengpo) **twice in immediate succession** (bounce out
  to `/d/wuguan/dayuan` and back) to force two `init()` calls within the
  vulnerable 40-second window. Only **one** copy of the 5-stage message
  chain played (confirmed by watching for the "孟婆说道：哦！又来了个新的"
  opening line — appeared exactly once, not twice), and the chain completed
  correctly (moved back to `/d/wuguan/dayuan` matching `enter_wuguan`).
  `debug.log` stayed completely empty throughout.
- **A real, non-simulated combat death**: as admin, `smash qintest` (a
  wizard command that calls the target's real `die()`) while qintest was
  actively logged in. Watched the full pipeline fire for real: corpse
  created, `qintest` became a ghost, `save()`d, moved to `DEATH_ROOM`
  (`gate.lpc`, our new guard), routed into the reincarnation NPC's room,
  ran the full 5-stage `death.h` chain once, and correctly returned
  `qintest` to `REVIVE_ROOM` (`/d/city/chmiao`). Verified via a later
  `score` on `qintest`: `死亡：一次` (death count 1), `上次遇害：被闪电劈死
  了` (matches `smash.lpc`'s flavor text), `combat_exp` reduced by exactly
  10,000 (the death penalty), skills all reduced accordingly — the whole
  death→reincarnation→revival cycle executed correctly with zero
  `debug.log` errors. This closes the "**death/respawn not conclusively
  live-tested**" gap flagged as a to-do in round one's notes.

**Not a match — checked and ruled out**: `work/adm/single/master.lpc`'s
`standard_trace()` (§7.111) formats `error["object"]` with `%O` (safe,
never throws on a non-object), not an unguarded `file_name(error["object"])`
— this lib's error handler doesn't have the §7.111 shape at all.
`adm/daemons/logind.lpc`'s `enter_world()` (the §8 logind save-guard check)
already unconditionally calls both `user->save()` and `ob->save()` right
after `setup()` completes — not commented out, not missing.

### Live-verified: economy/shop (closes another round-one gap, partially)

Round one flagged shop transactions as reviewed-but-never-actually-run.
This pass: `goto`'d directly to `/d/xiangyang/zahuopu` (牛老板's general
store) as admin, ran `list` (correct item/price/stock table), then
`buy deng long` — item-id resolution worked correctly (`vendor.lpc`'s
`is_vendor_good()`/`do_buy()` dispatch fired without error), and since
admin had no money, `MONEY_D->player_pay()`'s real insufficient-funds path
executed and returned the correct in-character rejection ("穷光蛋，一边呆
着去！"). Confirms the shop's full command-dispatch and payment-check code
path executes cleanly end-to-end; a **successful** purchase (money actually
changing hands) is still not verified — no in-game money-granting wizard
command exists in this lib (checked `cmds/wiz/*`, `cmds/adm/*`; no
`clone`/`cash`/`give` tool), and legitimately earning coin would require a
genuine trek/job. Left as a to-do, same as round one.

### Live-verified: board post/read (new coverage)

As admin on the 巫师留言簿 (`/d/wizard/wizard_room`'s wizard board):
`post <title>` (title must be given inline, then drops into the real
`ed`-style multiline editor via `me->edit(...)`) → wrote a body line → `.`
to end — got "留言完毕" (posting complete), board count went from 124 to
125, and `read 125` played back the exact posted title/body/author/timestamp
correctly. Confirms `bboard.lpc`'s post/read path (including the
`§7.86`-fixed `inherit`/`replace_program` shape from the earlier corpus
sweep) is still fully live-functional, not just "loads without crashing."

### Smoke-tested: persistent-guild commands (`cmds/group/*`, new coverage)

Distinct from the menpai/sect system (`bai`/`apprentice`, tested in round
one) — this lib also has a separate persistent-faction system
(`gcreate`/`glist`/`gmove`/`grant`/`gforce`/`abdicate`/`destory`, dispatched
by filename via `commandd.lpc`, not `add_action`). `glist` rendered a
correctly-formatted (empty) faction leaderboard without error. `gcreate`
with a syntactically-valid Chinese faction name (`测试帮`, ends in a legal
suffix character) correctly rejected with "抱歉，当前只允许贵宾玩家才能创
建帮派" (VIP-only gate) — read `gcreate.lpc`: this is a genuine, deliberate
VIP paywall, not a bug, so left alone per scope discipline. Confirms the
command-dispatch and argument-validation paths for this whole subsystem are
alive; full faction creation remains unverified (would need a VIP account).

### Methodology notes

- **A wizard `ghost`/`goto` combo (or, better, a real `smash`-triggered
  death) is a fast, repeatable way to reach and re-trigger reincarnation-NPC
  `init()` chains for regression-testing §7.112-class guards** without
  waiting on genuine risky combat — `goto` into the NPC's room fires
  `init()` on every occupant exactly like a room-entry would, so re-entering
  twice in a row is a faithful stand-in for the reconnect-mid-chain
  scenario, and is much faster to script than arranging two real
  concurrent socket connections.
- **`smash <target>` is a real, unguarded wizard-level kill command**
  (calls `ob->die()` directly, bypassing combat) — useful for deterministic
  death/respawn testing on any character regardless of level, without
  needing to find a "fair fight." Requires the target to be `present()` in
  the admin's own room first (`goto` there).
- **This lib has no in-game way to grant money to a test account outside
  earning it legitimately** — checked `cmds/wiz/*` and `cmds/adm/*`
  thoroughly; no `clone`/`cash`/`give`-style tool exists. A future full
  shop-purchase test needs either a real trek+job/quest income, or a
  save-file edit while the driver is stopped.

### Flag for cross-lib awareness (not fixed elsewhere, per instructions)

The §7.112 pattern (unguarded reincarnation/staged `call_out()` chain in a
room or NPC's `init()`) was found here in the death-zone specifically. Any
other lib in this corpus with its own `/d/death/`-style
reincarnation-guide NPCs (or any other multi-stage `init()`-scheduled
process) is worth the same grep sweep
(`call_out(` inside `init()`, minus files that already `remove_call_out`
or check a `temp` flag first) — this is the third or so independent lineage
this exact shape has now been found in per today's (2026-08-18) session
notes.

### Files modified this pass

- `work/d/death/npc/death.h` — `death_stage_active` re-entrancy guard
  (§7.112).
- `work/d/shaolin/npc/yu-zu2.lpc` — same guard, likely-dead code but fixed
  for consistency (§7.112).
- `work/d/death/gate.lpc` — `gate_run_active` guard, proactive hardening of
  the same class one room upstream.

## §7.100 sub-threshold instance (2026-08-20)

Found during the §7.100 tail-sweep (below the original 166-lib survey's
>=100-occurrence threshold, never checked). 24 live
`replace_program(ROOM);` occurrences across 24 files (`d/wanshou/*.lpc`,
`data/group/groom/*.lpc`, `d/cangzhou/dangpu.lpc`) — same fatal
redundant-replace-after-inherit shape as the rest of the §7.100 family.
This lib's room-building tools (`clone/misc/roommaker.lpc`,
`cmds/debug/roommaker.lpc`) never had the bug baked into their
templates, so no factory-side fix needed. One pre-existing
already-`//`-commented instance (`d/xueshan/jlshan.lpc`) left untouched.
Fixed by deleting the redundant lines (binary-mode script, 24/24 matched
`git diff --stat`). Verified via a clean native driver boot (zero new
`debug.log` errors, port listening, killed by exact PID after ~8s).

### ```§7.112``` residual-gap closure (2026-08-20)

Corpus re-scan (`grep -rl 'call_out("death_stage"' ... | filter for missing guard`) found unguarded `init()`-scheduled `death_stage()` call_out chain(s) in `d/death/npc/death2.h` that the original two-wave sweep (see AGENTS.md §7.112) missed -- same reconnect-triggered duplicate-chain bug, different filename/lineage. Added the standard `query_temp("death_stage_active")`/`set_temp`/`delete_temp` re-entry guard, adapted per file's own exit points. Compile-verified via `lpcc --batch`.

Note: the touched header here (`death2.h`) turned out to be dead/unreferenced code in this lib -- the live NPCs (`yanluo.lpc`/`mengpo.lpc`/`pusa.lpc`) actually `#include` a sibling `death.h`, which was already guarded from an earlier fix. This edit is a harmless no-op; no live vulnerability existed in this lib for this file.

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

## AGENTS.md §7.19 sweep (2026-09-01): `enable_player()` reentrancy from `init()`

Same corpus-wide bug class as `mhxy`/`wuhanzhan` (AGENTS.md §7.19): this
lib's `feature/command.lpc` `enable_player()` wrapper (around the raw
`enable_commands()` efun) is reachable from an NPC's `init()` via a
redundant `create()`-then-`init()`-calls-`setup()`/`reset_me()` chain --
confirmed via a body-aware static scan of every `init()` in this lib: 5
NPC files call `setup()`/`reset_me()` from `init()` (e.g.
`data/group/npc/hufa.lpc`, `d/gb/npc/xixia-wushi.lpc`,
`d/gb/npc/xiaox-wushi.lpc`), after `create()` already made the object
`living()`. Calling `enable_commands()` a second time on an
already-`living()` object makes the driver re-invoke that object's own
`init()` as a side effect, re-entering the same chain while the
original call is still on the stack -- genuine reentrancy, crashing
with "Too deep recursion" (most likely on an NPC's first-ever
preload/compile).

`feature/damage.lpc`'s `revive()` and `cmds/std/sleep.lpc`'s `wakeup()`
both call `enable_player()` again while the object is still `living()`.
This confirms a bare `if (living(this_object())) return;` guard would
be the WRONG fix -- used the same true reentrancy-flag fix as `mhxy`
instead: a `nosave private int in_enable_player_now;` set for the
duration of the wrapper's body, guarding only genuine same-call-stack
reentrancy while leaving every legitimate re-enable (revive/wakeup)
unaffected. `enable_player()` had a single fall-through exit (no early
`return`s), so one guard-at-top + one clear-at-bottom pair was
sufficient. Verified via a single-file `lpcc --batch` compile check
(PASS) -- not individually live-boot-tested.

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `inherit/room/room.lpc`：`make_inventory()` 用 `catch()` 包住 `unew(file)`（缺档时它在 simul_efun 里对 0 调用 `query("unique")`），`else` 分支只在确有克隆时才取 `[<1]`。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-07）— 编译警告整理

`scripts/lpc_warnings.py bxsj --fix` 加 `scripts/lpc_fix_no_effect.py --apply`，共改动 515 个 `.lpc` 和 11 个 `.h`（多为删去未用的局部变量）。HEAD 与工作树分别加载（新进程）：505 -> 505 通过，无回退；改过的头文件的 12 个包含者 11 -> 11 通过。启动时警告 17 -> 0；新进程登录（编码选择、新人物确认）正常。

## 深度功能测试（§10.7，2026-10-08）— `.lpc` 后缀的定宽切片

`.c` 改名 `.lpc` 时只改了字符串没改切片宽度：`f[<2..] == ".lpc"` 拿两个字符比四个字符，永远不成立（`!=` 永远成立），按后缀筛文件、去后缀的代码因此从不运行或截成 `x.l`（KB 06 §7.238）。`scripts/lpc_lpc_suffix_slice.py --apply` 改了 10 处比较、0 处去后缀（如 `d/xueshan/zanpugc.lpc`）；改动的文件 HEAD 与工作树分别加载（新进程），无回退。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 19 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 1 个，只在 #if 分支用的声明移进分支 0 个文件；改动 18 个文件，HEAD 与工作树各载入一次无回退（18 objects; HEAD PASS 18, tree PASS 18; regress 0; newly loading 0），这些文件的警告 20 -> 0。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查

- `clone/obj/traverser.lpc`：`DEBUG` 是空宏，每次调用留下 `("text", n);` 语句；改成空函数 `varargs void DEBUG(string fmt, mixed arg) {}`。载入无回退。

## 深度功能测试（§10.7，2026-10-11）：全库严格 UTF-8 检查

- `d/city/weapon/weapon-2.lpc`、`weapon-4.lpc` 是含 NUL 的二进制垃圾（原档损坏），保留原样。

## 深度功能测试（§10.7，2026-10-12）：编译警告收尾（一）

- `kungfu/skill/*zhen*.lpc` 等 11 个阵法技能：`query_action()` 返回招式描述字符串，基类 `inherit/skill/skill.lpc` 声明 `mapping`；子类改为 `mixed`（调用方拿到的值不变，类型检查不再报警）。工具：`lpc_fix_void_override.py --mixed`（新增）。
- `inherit/misc/equip.lpc`：`void ob_hit()` 改为 `mixed ob_hit()`。`combatd` 把护甲 `ob_hit()` 的返回值当消息字符串或伤害修正读，软猬甲等子类返回 int；基类是 void 才报警。函数体不变，落尾返回 0。
- `d/xingxiu/obj/duchong.lpc` `kill_ob()` 改为 void（无人读返回值）；`d/gumu/npc/mmnz.h` 原型 `int kill_ob` 改为与定义一致的 `void`。
- 5 处多余的 inherit（`kuihua-shengong.lpc` 的 `SKILL` 已由 `FORCE` 带入等，`lpc_diamonds.py`）。
- 77 个对象（含包含/继承改动文件的）载入无回退。剩余多为 `Redeclaration of global variable`（`skills_pfm.h`、`r_name.h`、`huanjing2003` 等），按 KB 04 逐个核对后另行处理。

## 深度功能测试（§10.7，2026-10-12）：编译警告收尾（二）

全库编译警告 89 -> 0（`scripts/lpc_warnings.py bxsj`），逐条按 KB 04 §6.10 核对后修：

- `adm/daemons/huanjing2003/` 的 4 个国度 NPC、4 个宝物和 `room_readygo_hj.lpc`：一条声明里同名变量写了两遍（`string me_guodu, ask_arg, …, me_guodu = "…", …`），驱动给后一份初始化、前一份是空的。删去前面不带初值的那串名字，只留带初值的一份（代码原本读的就是后一份，`ask_arg = baowu_name` 也读到初值）。
- 16 个继承 `FIGHTER` 的门派弟子/护卫 NPC（`d/city/npc/laopu.lpc`、`d/huashan/npc/cs_npc.lpc` 等）：自己的 `string *str_menpai`（各自的门派列表）与 `inherit/char/fighter.lpc` 的同名变量冲突。两份各管各的（`setparty()` 读基类的，NPC 自己的 `create()` 读自己的），叶子一侧改名 `npc_menpai`，行为不变。
- `d/city/npc/r_name.h`（经 `d/city/npc/skills_pfm.h` 包含进上述 NPC）的六张姓名表与 `include/r_name.h`（`fighter.lpc` 包含）同名但内容不同；按“两份头文件同名不同内容”处理，改名 `c_f_name` 等，叶子里的 `random_name()` 照旧读自己那份。
- `d/city/npc/mengdie_npc{,1,2}.lpc`：已继承 `FIGHTER` 又 `#include <skills_pfm.h>`，变量和函数再来一份；删去多余的 include（函数体相同，继承来的那份照常可用）。
- `kungfu/skill/dzxy.lpc`：`string *attack_action` 与 `inherit/skill/skill.lpc` 的同名变量本意相同（`skills.h` 读它），删去叶子声明，改在 `create()` 里赋值（先调 `::create()`）。
- `d/taishan/npc/runner.lpc`：泰山叛徒的逃跑路线 `path` 与 `feature/command.lpc` 的命令搜索路径 `path` 撞名，叶子改名 `route`。
- `d/village/npc/obj/robber.lpc`、`robber_n.lpc`：`NAME_D` 重定义，前面加 `#undef NAME_D`（生效的仍是本文件的定义）。
- `cmds/usr/mygift.lpc`、`mygift2.lpc`：`?:` 两支 int/string，去掉无效的 `(int)`。
- `clone/npc/tdh/man1.h`、`d/shaolin/npc/h.lpc`：块注释里的 `/*` 去掉（注释范围不变）。

改动的 37 个文件及包含改动头文件的对象共 40 个，HEAD 与工作树各载入一次（新进程）：40 个对象载入无回退（regress 0）；`lpc_audit_removed_locals.py` 0 处待查。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。12 个文件 21 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）；`x op= 浮点` 先把浮点转成整数再运算（系数小于 1 时 x 直接变 0），改为 `x = to_int(x op ...)`：`/d/mr/npc/murong-fu.lpc`（`bouns *=`）、`/kungfu/skill/force/qi.lpc`（`q *=`）、`/kungfu/skill/force/recover.lpc`（`q *=`）、`/kungfu/skill/taiji-quan/luanhuan.lpc`（`p *=`）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。

- 2026-10-14：1 个文件用了颜色宏（`HIW`、`NOR`）却没有 `#include <ansi.h>`（首个错误 `syntax error, unexpected L_STRING`）；开头补上（KB 04 §6.1、§6.3）。新进程比对 HEAD 与工作树：1 个对象，新增载入 1，回退 0。

## 负数伤害当作消耗（2026-10-15，KB 06 §7.241）

`receive_damage("neili", -52)`、`receive_damage("qi", -12)` 之类把 `add()` 的负数写进了 `receive_damage()`：本库 `feature/damage.lpc` 对负数伤害报错（或归零），练功/运功时报 `F_DAMAGE: 伤害值为负值` 或消耗失效。已改为正数伤害，内力/精力类改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py`）：`/kungfu/skill/fanchang`、`/kungfu/skill/hujia-daofa`、`/kungfu/skill/huntian-qigong/huntian`、`/kungfu/skill/lanhua-shou`、`/kungfu/skill/longxiang-boruo/fanchang`、`/kungfu/skill/yiyang-zhi`。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。11 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。

## family 映射（补）（2026-10-15）

`mapping fam = (mapping)me->query("family");`（带类型转换的写法）同样直接取下标，2 处补上 `if (!mapp(fam)) fam = ([ ]);`。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。3 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。


## 技能按另一门武功的等级取招（2026-10-15，KB 06 §7.243）

这些技能文件是从别的武功复制改名来的，`query_action()` 仍用原武功的等级查招式表：只会本技能的人等级为 0，取不到招，每次出招都报错。改为读本技能自己的等级（`scripts/lpc_fix_action_level.py`）：`kuihua-shengong`。

## 把经验、属性、内力当技能读（2026-10-15，KB 06 §7.247）

当前内力、精这类名字有时指的是内功技能，逐处读过后手改：`lengquan-shengong` 的 `ob_hit()` 用 `query_skill("neili")` 比较双方内力，恒为 0 对 0，只会走“化去一部分”的分支，改为 `query("neili")`。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`jinshe-zhang`→`jinshe-zhangfa`（`jinshe-jianfa/kuangwu`、`kuangwu`）；`qimen_baguazhen`→`qimen-baguazhen`（`suibo-zhuliu/wuzhuan`）；`xixing-dafa`→`xixin-dafa`（`tianlong-shengong`）。

## 技能名拼错：技能文件里拼错自己的名字（2026-10-15，KB 06 §7.249）

技能自己的文件（或它的绝招目录）里，`query_skill()` 读的是差一个字母的自己的名字，永远得 0：“基本功夫要高过本技能”之类的限制从不生效，按等级取招、计算伤害的那一项一直是 0。改为本技能的名字（`scripts/lpc_fix_skill_typo.py` 的 self 判据）：`xuantia-wuji`→`xuantian-wuji`（`xuantian-wuji/wuji`）。

## 地图数据库 mapdb 读到只有文件头的 map.o（2026-10-15，KB 06 §7.250）

本库的 `data/npc/map.o` 只有一行文件头：genmap 第一次载入时 `if (!restore()) save();`，地图还没建就存了档，值为 0 的变量不写进去。mapdb 的 `restore()` 读它成功，`map` 却成了 0，`query_room_info()`、`query_room_exits()`、`query_map()` 都对 0 取下标或把 0 交出去：任务系统 `job_area.h` 的 `get_arearoom()` 在 `keys(room)` 报错。mapdb（`/clone/obj/mapdb.lpc`）加一个 `restore()`：读档后 `map` 不是映射就重置为 `([])`；地图为空时 `query_random_room_path()` 返回 0。地图本身仍需巫师用 genmap 生成。


## npc_setup 的浮点截断警告（2026-10-15，KB 04 §6.10）

`/clone/obj/npc_setup.lpc`：`level = pow(10 * exp, 0.333334);` 把浮点数隐式截成整数，编译时警告；改为 `to_int(...)`，结果不变。

## 燃木刀法「焚天」的效果一秒就消失（2026-10-15，KB 06 §7.246）

每秒检查的 `check_fight()` 声明了 `object weapon;` 却从不赋值，条件里的 `!weapon` 永远为真，效果在第一次检查时就被撤掉。把这一项改为 `!objectp(weapon = me->query_temp("weapon"))`，先存兵器再判断刀的种类。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

3 个文件、3 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/clone/cloth/cloth`、`/d/city/obj/blade`、`/u/lius/wudang/obj/cloth`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 0 个，改后 0 个（0 个原来载入不了），没有退步；其余 3 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## NPC 带着不存在的物品：simul_efun `unew()` 报错（2026-10-18，KB 06 §7.73）

`adm/simul_efun/object.lpc` 的 `unew(str)`（带 `unique` 判断的 `new()`）先 `ob = new(str)`，紧接着就读 `ob->query("unique")`。物品文件不存在时 `new()` 返回 0，读 0 的属性报 `Bad argument 1 to EFUN call_other()`，从 `carry_object()` 一路带出去：`create()` 里带着缺失物品的 NPC 载入不了（jh2006 的苗疆何铁手一类，该有 NPC 的房间少了人）。读属性之前补 `if (!ob) return ob;`（`int i = ob->query("unique"), j, k;` 拆成声明和赋值两句），缺的物品跳过，NPC 照常载入（`scripts/lpc_guard_carry_object.py --unew`）。载入检查：改动的文件改前能载入 1 个，改后 3 个，没有退步。

## `clone/spec/putao` 的 `long` 里引号错位（2026-10-18，KB 03 §4.6）

`set("long","这是一串由达摩传入中土HIG"神奇葡萄"NOR"，……")`：开引号落在 `HIG` 后面而不是前面，字符串在 `HIG` 处就闭合了，后面的 `神奇葡萄` 成了代码（`Illegal character 0xe7`），整个物件载入不了。把引号挪到 `HIG` 前面（`中土"HIG"神奇葡萄"NOR"，`，与同系其他库的同名文件一致）。载入：通过。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 2 个对象设了本库没有文件的武功（22 个名字，最多的是 `kick`、`liangyi-dao`、`pishi-poyu`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：2 个里 1 个通过，其余 1 个停在别的错误上（`clone/obj/npc_setup`：*No program in object '/clone/obj/npc_setup'!）。（`scripts/lpc_guard_set_skill.py`）

## 通向不存在房间的出口，按对面房间的回头出口改正（2026-10-18，KB 06 §7.257）

房间出口 `"west": __DIR__"xxx"` 指向的文件本库没有，玩家走过去就被卡住（笔误、改过名的房间，或者没带进档案的编号房间）。对面的房间存在、并且它相反方向的出口正好指回这个房间，说明出口原本就是通向它：`/d/fuzhou/nanmen` 的 `south`：`birdge` → `bridge`；`/d/shaolin/nanyang` 的 `south`：`yidao2` → `hanshui2`。改动后每个出口都能解析到本库的文件（`scripts/lpc_fix_dead_exits.py`；目标在运行时本来就能载入的库——虚拟房间——不动）。

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 35 处、35 个文件：`shaolin-shnfa`→`shaolin-shenfa`（14 处）、`kunlun-shnfa`→`kunlun-shenfa`（11 处）、`yijinjing`→`yijin-jing`（2 处）、`guiyuan-tuanfa`→`guiyuan-tunafa`（2 处）、`banrou-zhang`→`banruo-zhang`（2 处）、`qinmang-jian`→`qingmang-jian`（1 处）、`huashen-shenfa`→`huashan-shenfa`（1 处）、`weiituo-gun`→`weituo-gun`（1 处）等共 9 个名字。（`scripts/lpc_fix_skill_names.py`）

## 全局头文件丢了 1 个宏（2026-10-19，KB 04 §6.16）

`/include/globals.h` 里没有定义 `SHOP_DIR`，用到它们的物件（名单里 1 个）编译时报 `Undefined variable`/`Undefined function`，整个物件载入不了（编译器在第一个未定义的名字上停下，后面的错误和警告都看不到）。同系的库在各自的头文件里都有这几行：照其中和本库共有文件最多的那个库，原样补到 `/include/globals.h` 最后一个 `#define` 之后，宏体里出现的路径在本库里都存在。名单里的物件除了这几个宏之外还有别的错误，暂时仍载入不了。（`scripts/lpc_restore_defines.py`）

## 区域物件的零碎修正（2026-10-19，KB 06 §7.267–§7.271）

- `/d/shaolin/npc/xuan-du.lpc` 的 `#include "/u/hunthu/npc/xuan-du.h"` 改成 `/kungfu/class/shaolin/xuan-du.h`（巫师目录 `/u/…` 不在档案里，头文件的唯一副本在区域里）

逐个物件与 HEAD 对比载入，没有退步。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 补回本库没有的基类文件，第二轮（2026-10-19，KB 04 §6.15、§6.18）

宏有定义、基类文件却不在档案里：继承它的对象载入时报 `Inherited file '…' does not exist!`，编译扫描看不到这一类（`scripts/lpc_missing_inherits.py` 能列出）。同系的库里有同一个文件，原样拷来（`scripts/lpc_restore_bases.py`）；基类和继承它的对象 include 而本库没有的头文件一起带来。每个基类补回后单独载入，再载入使用它的对象，载不进来、或一个用户也载不进来的撤掉了。

- `/inherit/weapon/weapon_combo`←sje：2/2 个继承它的对象载入

逐个与 HEAD 对比载入，没有退步。

## `x == "a" || "b"`：后面的字符串常量永远为真（2026-10-19，KB 06 §7.281）

`if (arg == "yuyou" || "yu you")` 里的 `"yu you"` 是非空字符串，永远为真，整个条件对任何 `arg` 都成立；作者要的是每个字符串都和变量比较。具体是：吃任何东西都会吃掉鱼油。在每个字符串前补上变量和运算符（`scripts/lpc_fix_literal_or.py`；`forrest2.lpc` 是 `dir == "north" && "south"`，手工改成 `(dir == "north" || dir == "south") && ...`）：`/clone/food/yuyou.lpc`（4 处）。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。改动：`/kungfu/skill/anran-zhang/jishi.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 16 处）。改动：`/clone/npc/mj.lpc`（3 处）、`/cmds/group/glist_new.lpc`（2 处）、`/d/city/npc/budai.lpc`（1 处）、`/d/city/obj/budai.lpc`（1 处）、`/d/sld/npc/stt.lpc`（1 处）、`/d/sld/sanpo7.lpc`（1 处）、`/kungfu/skill/qiankun-danuoyi.lpc`（7 处）。

## `socket` / `dumpsocket` 指令：`dump_socket_status()` 驱动里没有（2026-10-20，KB 06 §7.291）

这些巫师指令 `write(dump_socket_status());`，MudOS 的 efun 在 FluffOS 里不存在，指令编译不过。在模拟 efun 文件里补了 `dump_socket_status()`：用 `socket_status()` 排出同样的表（没有 sockets 包的构建，比如 WASM，只有表头；`scripts/lpc_add_sefun.py dump_socket_status`）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/single/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。
