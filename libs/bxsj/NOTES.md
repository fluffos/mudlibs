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
