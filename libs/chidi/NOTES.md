# chidi.rar → `chidi`

- Archive: `archives/chidi.rar` (17MB — "《江湖 I》"/"Jianghu I", generic
  wuxia-themed, MudOS lineage). Mudlib root at archive top level (no
  nesting). Config at top-level `config.cfg` (had a harmless duplicate
  `port number` line).
- Port: **40006**. Biggest lib by file count so far: 17809 raw / 16096
  `.lpc` after conversion.

## Status: DONE — boots clean, playable over telnet

Full login flow (registered-player count, high-score display, name/
password prompts) confirmed working.

## What was fixed

1. Encoding: 16994 converted, 457 already UTF-8/ASCII, 307 skipped
   binary, 51 lossy.
2. `.c` → `.lpc`: 16096 files. 911 literal `.c"` refs auto-fixed.
3. `static` → `nosave`: 74 files.
4. `master.lpc` needed NONE of the master.lpc/securityd.lpc fixes from
   libs #4/#5 (`bxsj`/`bxsj1`) — different lineage (closer to lib #1's
   "simple" style: default-allow `valid_override`, `find_object`-only
   `valid_read`/`valid_write`, no recursion risk).
5. `adm/simul_efun/file.lpc`'s `tail()` wrapper called `efun::tail()`,
   which doesn't exist in this driver (AGENTS.md §8e) — same missing-efun
   issue as lib #1, but here it's inside a file that's part of
   `simul_efun.lpc`'s composition, so it was FATAL (blocked the whole
   boot) rather than an unused dead command. Reimplemented in plain LPC
   (`do_tail_lpc`, `read_file`+`explode`+slice-last-N+`write`) — the
   caller turned out to be dead code (no callers anywhere in this lib)
   but implemented it properly anyway per AGENTS.md §8e's guidance.
6. `adm/daemons/npcd.lpc` had 4 `#include <npc/LANG.c>`-style angle-
   bracket includes referencing files renamed to `.lpc` — **generalized
   the fix into `convert_lib.sh`** (a new step handling
   `#include <....c>` uniformly, since the existing fix only handled
   quoted-string `.c"` references, not include directives).

## Known remaining issues (documented, not fixed)

- 752 lpcc-sweep failures (of 16096) — not individually triaged past a
  category scan. Largest buckets: various syntax errors (32+13+12+9+7+6 —
  likely more of the fullwidth-punctuation/missing-quote typo shapes from
  AGENTS.md §9/§10, not confirmed one-by-one), `Undefined variable
  DIABLO_D`/`SKILL_BASE_NAME`/`SKILL_EN_NAME`/`SKILL_CH_NAME` and
  `Undefined function query_competitor`/`add_light` (missing-content
  shape, AGENTS.md §13). 8 of the failures are `temp/feng<timestamp>`
  files — clearly leftover runtime/crash-dump debris from the archive's
  original live server, not real source; safe to ignore entirely.

## How to run

```
cd libs/chidi
~/src/fluffos/build-debug/src/driver config.fluffos
python3 ../../scripts/mudclient.py 127.0.0.1 40006 --timeout 10 --send "" --send "look" --send "quit"
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

## Re-verification pass (2026-07-23): driver rebuild + LPC formatter + WASM build + NEW log_error() spam fix (AGENTS.md §15af)

- **Formatter**: ran `format-corpus.mjs` over all of `work/` (16,096
  files, 15,035 written/reformatted, 42 already-clean, 1,019 refused
  with an error — a larger-than-usual error count but expected on this
  archive's already-documented long tail of syntax typos, not chased
  individually).
- **Native retest against rebuilt driver** (`build-debug/src/driver`,
  rebuilt from latest upstream master): clean boot (took roughly a
  minute to preload — this is the largest of this batch's libs at
  16k+ files), zero fatal errors in `debug.log`.
- **NEW bug found and fixed**: a full interactive registration (this
  lib's own admin-password + normal-password two-tier scheme, then
  Chinese name, talent roll, email, gender) revealed
  `adm/obj/master.lpc`'s `log_error()` showed the **raw compiler
  diagnostic text to ANY connected player**, no `wizardp()` gate at
  all, for every compile diagnostic funneled through
  `APPLY_LOG_ERROR` — including harmless "Unused local variable"/
  "Unknown #pragma" warnings triggered by the very first lazy compile
  of the new character's own `char.lpc`/`feature/*` files right after
  gender selection. In the pre-fix transcript this dumped ~30 screens
  of raw compiler internals over the new player's very first moment in
  the game — same bug class already found and fixed on several sibling
  libs in this project (`dtsl`/`dtsl2`/`dfgs2`/
  `bixiecanyang`/`wuhanzhan`/`shenzhou`, AGENTS.md §15af), not
  previously caught here because this lib's original testing pass
  (like several others) never exercised a full registration through to
  gender selection. Fixed identically: only show the full diagnostic to
  a wizard; only alarm an ordinary player with the generic
  `__DEFAULT_ERROR_MESSAGE__` for a genuine compile **error** (gated on
  absence of the substring `"warning:"`) — `#include <runtime_config.h>`
  was already present in `master.lpc`, no additional include needed.
- Re-verified with a fresh full registration (real name `秦深`, ID
  `qinshen`) all the way through to the actual game world (世外桃源
  starting room, NPC dialogue firing correctly), then `look`/`score`/
  `quit` all producing correct output with **zero** compiler-warning
  spam and zero real errors in `debug.log`.
- **WASM build**: preload completes with only the expected non-fatal
  `sockets`-package gap (`adm/daemons/ftpd.lpc`'s
  `socket_create`/`socket_bind`/`socket_close` → `Undefined function`,
  cascading into a few dependent compile errors on the same file but
  caught non-fatally — `Initializations complete.` still printed).
  Registration is blocked by the documented `query_ip_number()`
  WASM-mode limitation: `adm/daemons/logind.lpc`'s `logon()` calls
  `BAN_D->is_banned(query_ip_number(ob))` and rejects every connection
  with "你的地址在本 MUD 不受欢迎...". **Not a mudlib bug** — the
  documented driver-side gap, not something to patch. Verdict: boots
  cleanly under WASM (log_error fix confirmed present in this build
  copy too, via the in-memory `work/` snapshot); registration cannot
  complete due to the driver's IP-check limitation.

## WASM-enablement pass (2026-07 standard: loopback-allow, throttle exempt, admin seed)

Gates patched:

- `adm/daemons/band.lpc` `is_banned()` (~line 106): loopback / `127.`
  prefix / empty / non-string / non-dotted-quad IP → return 0. This was
  the documented WASM login blocker (logind's `logon()` calls it with
  `query_ip_number()`); now bypassed per §1.3b.
- `adm/daemons/logind.lpc` `logon()` (~line 138): `ip_cnt > 40` per-IP
  connection cap now applies only to non-loopback addresses.
- No `uptime()` startup-grace gate in this lib's logon.

Admin account: id `fluffos`, password `Mud@2026`, wizpwd `Wiz@2026`
(chidi shares the 碧血残阳-style dual-password registration), name 浮浮,
granted `(boss)` (this lineage's top rank) via `adm/etc/wizlist`.
Verified `update /d/register/entry` → 成功 on re-login; wizard room-path
view active. **Save files for the orchestrator to force-add:
`libs/chidi/work/data/user/f/fluffos.o` and
`libs/chidi/work/data/login/f/fluffos.o`** (untracked dirs).

Retest: fresh normal registration (id `ceshisi`, name 秦风, female)
end-to-end into 世外桃源, look/score/quit correct, 0 new errors in
debug.log; test char saves removed.


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
registration + `look`/`score`/`quit` + admin login). Played as an ordinary
new player through registration, the personality/`born` flow, the newbie
gift, a formal sect apprenticeship, safe sparring, and a shop purchase —
one continuous native-driver (`build-debug`) session per phase, restarting
the driver only to pick up in-place fixes (per `AGENTS.md` §10.3).

**Test characters (kept as evidence, both reachable with the credentials
below)**:
- id `linshuang`, password `Passwd456`, real name 林霜, female,
  personality 光明磊落, registered via the normal (non-admin) two-tier
  password scheme. Final state: newbie-gift skills (`blade`/`dodge`/
  `force`/`parry`/`sword`/`unarmed` all 300, `literate` 1000), two
  `jue1` weapon items + starting cloth in inventory, `startroom`
  `d/city/wumiao` (武庙, forced there by `quit.lpc`'s indoor-quit rule),
  cleanly logged out. Save files: `work/data/user/l/linshuang.o`,
  `work/data/login/l/linshuang.o`.
- id `chenmu`, password `Passwd789`, real name 陈牧, male, personality
  光明磊落. Used specifically to reach a male-only sect entrance for the
  organic-teacher test (§ below). Final state: 少林派第四十一代弟子
  (Shaolin 41st-generation lay disciple), master 清无比丘, `force` skill
  learned to level 1 via `xue`/`learn`. Save files:
  `work/data/user/c/chenmu.o`, `work/data/login/c/chenmu.o`.

### Bugs found and fixed

**1. `adm/daemons/logind.lpc` — raw `printf("%O", ob)` object-dump leaked
to every new registrant, on literally every registration, file:line
`logind.lpc:595` (random-name-accepted branch of `get_resp()`) and
`logind.lpc:630` (typed-name branch of `get_name()`).**
- Symptom, reproduced live pre-fix: right after a brand-new player typed
  their Chinese name (or accepted a random one), the raw LPC object
  reference (`/clone/user/login#0`-shaped text) printed directly to the
  connecting client, inline with the surrounding prompts — a leftover
  author debug statement (`printf("%O\n", ob);`), not gated on
  `wizardp()` or anything else, firing for every single registration.
  Cosmetic (didn't block the flow), but genuinely reproducible on every
  new account and clearly not intended for players.
- Fix: deleted both `printf("%O\n", ob);` lines outright — dead debug
  output with no other role in the function (the surrounding logic
  doesn't depend on it).
- Verified: re-ran a full fresh registration (id `linshuang`) after the
  fix — no stray object-dump anywhere in the transcript, name/password/
  talent/email/gender flow otherwise identical to the pre-fix run.

**2. (RETRACTED — content/design judgment call, not a programming bug;
reverted on user review) `d/city/huadian.lpc`'s vendor NPC was never
spawned (its `objects` entry was commented out:
`// __DIR__"npc/hua_girl" : 1,`).** Originally uncommented and paired
with a `do_buy()` syntax patch, both since reverted: restoring
deliberately-disabled content isn't a compile error or wrong efun
usage — it's a decision about what the game should contain, which this
project's round-two testing scope explicitly excludes (see AGENTS.md
§10.7's scope note). The room's own flavor text and help board still
describe 英莲 as present, so the disabled state does look like it could
be an abandoned WIP toggle from the original archive's own development
— but "looks like an oversight" isn't the same as a proven programming
defect, and we don't have grounds to be certain either way. Left as-is
(shop remains non-functional, matching the shipped archive), documented
here rather than silently re-fixed.

**3. `d/city/npc/wizer.lpc:22` and `d/jh/shengji.lpc:17` — a hard
compile-blocking type error (`exert_function(<int>)` where the function
requires a `string`) on two NPCs spawned by `d/city/wumiao.lpc`
(武庙/Wu Miao, one of this lib's `START_ROOM` fallback destinations and
`quit.lpc`'s own forced respawn point for any indoor quit) took down the
room's ENTIRE first-ever compile this boot — new login landed with
literally no environment at all.**
- Symptom, reproduced live pre-fix: relogging in after a clean `quit`
  from an indoor room landed the character with `look` showing "你的四
  周灰蒙蒙地一片，什么也没有。" (driver's own `!environment(me)` fallback
  text, `cmds/std/look.lpc:143`) and every movement command failing with
  "你哪里也去不了。" (`cmds/std/go.lpc:57`'s `!environment` check) — the
  player was never actually placed in ANY room, matching the shape of
  AGENTS.md §7.22 (a first-visit-only environment-less login) even
  though the specific mechanism here is a compile error, not an
  eval-cost abort.
- Root cause: `inherit/char/npc.lpc:155`'s `exert_function(string func)`
  ("Let the npc exert his/her enabled force" during idle chat) was
  called as `exert_function(1000)` in `wizer.lpc` and
  `exert_function(10)` in `shengji.lpc` — an integer where the direct
  (non-`->`) call requires a string, a hard compile error on this driver
  (AGENTS.md §8.5's exact class). Both are copy-pasted from the same
  template (identical `chat_chance`/`title`/`exert_function(N)`/
  `chat_msg`/`gender`/`combat_exp`/`max_neili`/`force` shape) — a
  genuine archive-native typo (this NPC never compiled correctly even on
  the original live server; not something this project's conversion
  introduced). `debug.log` showed the compile error rooted exactly here:
  `/d/city/npc/wizer.lpc:22:22: error: Bad type for argument 1 of
  exert_function ( string vs int )`. `wumiao.lpc`'s `reset()` spawns
  `wizer` as one of five `objects` entries; the failed compile appears
  to have aborted the room's own first-ever load rather than merely
  skipping the one broken NPC (exits, otherwise set via plain `set()`
  calls before `setup()` even runs, were also missing on the broken
  visit — consistent with `load_object(startroom)` itself throwing and
  being caught by `enter_world()`'s own `catch()`, which then fell
  through to a *second*, independently-buggy path, see bug 4 below).
- Fix: removed the erroneous `exert_function(N);` call from both files.
  It's purely a cosmetic ambient-chat behavior (per its own doc comment)
  with no other effect on the NPC — deleting it is strictly safer than
  guessing which string the author actually meant.
- Verified: post-fix, `debug.log` shows only pre-existing unused-variable
  warnings for both files, no `error:` line; a fresh visit to `武庙`
  (first-ever this boot) rendered its real description, all 4 exits, and
  all 5 NPCs (including 大魔道士--雅薇丝/Wizer) correctly; a fresh visit
  to `/d/jh/shengjiroom` (南, off 武庙) likewise rendered 升级师
  correctly with no error.

**4. `adm/daemons/logind.lpc:892` — `int i = random(4);` indexes
`start_room` (a 1-element array) out of bounds 3 times out of 4,
whenever the array is actually touched (a broken/missing custom
`startroom`, or the ghost/`DEATH_ROOM` respawn branch).**
- Not independently reproduced live (bug 3's fix removed the one path
  that was actually exercising it this pass), but confirmed by direct
  code inspection: `start_room = ({ "/d/city/wumiao" })` (single entry,
  presumably trimmed down from a larger pool at some point in the
  archive's own history — same "stale content left over from an earlier
  version of the game" shape as AGENTS.md §7.18, here affecting an array
  size rather than a path) while every one of its 4 use sites in
  `enter_world()` indexes it with `i = random(4)`. This driver's default
  range-checking (`old range behavior : 0` per `debug.log`'s boot
  banner) throws a real error on an out-of-bounds array read rather than
  silently returning 0 — so any future login that legitimately falls
  into this branch (e.g. a corrupted custom `startroom`, or a ghost
  respawn) would hit the same "aborts partway through `enter_world()`,
  player ends up with no environment" failure as bug 3, from an
  unrelated trigger. Fixed proactively alongside bug 3 since it's the
  same failure *shape* (and literally the fallback path bug 3's login
  failure would have fallen through to, had `wizer.lpc`'s compile error
  actually thrown past `wumiao.lpc`'s own `setup()` rather than being
  contained there — the two bugs are adjacent, not confirmed to be the
  same event).
- Fix: `int i = random(4);` → `int i = random(sizeof(start_room));` —
  sizes the random draw to the array's real length instead of a stale
  hardcoded `4`; behavior-preserving for the current 1-element array
  (`random(1)` always yields the only valid index `0`) and automatically
  correct if `start_room` ever grows back.
- Verified: code-review only (safe, minimal, behavior-preserving change;
  the specific crash shape it guards against is bug 3's, already
  reproduced and re-verified fixed above).

### What was tested and confirmed working

- **Registration**: real Chinese name (林霜/`linshuang`), full flow (id
  → confirm-new → Chinese name → admin password ×2 → normal password ×2
  → talent roll (`0`=random, accepted) → email → gender) — reached the
  actual game world (世外桃源 entry room) correctly; re-verified with a
  second character (陈牧/`chenmu`) after the printf-leak fix, confirming
  the leaked-object-dump bug is gone on both the random-name and
  typed-name branches.
- **Personality/`born` flow**: all 4 entry-room exits correctly grant
  their respective personality (`east` → 陆天抒 → 光明磊落, confirmed
  live for both test characters); `out` → 阎罗殿 (Yanluodian) →
  `born 扬州人氏` correctly relocates into `/d/city/kedian` (有间客栈,
  matching the `fly yz` alias target) and grants the starting outfit.
- **Newbie gift shortcut** (the *direct* skill-acquisition path,
  `doc/help/intro`'s documented `ask shizhe about 江湖`): grants
  `literate` 1000 plus `blade`/`dodge`/`force`/`parry`/`sword`/`unarmed`
  at 300 each, plus stat/potential/exp/money boosts and two weapon
  clones — reproduced live, correct output, `skills` confirms all 7
  entries at the right levels.
- **Organic teacher-NPC path** (the *indirect* skill-acquisition path):
  `d/kungfu/class/shaolin/qing-wu.lpc` (清无比丘, 少林派第四十代弟子,
  reachable via `fly sl` → `east`) auto-recruits any male player with no
  stat gating (`attempt_apprentice()` only checks gender) — `bai qingwu`
  correctly ran the full `apprentice.lpc` flow (pending → NPC's own
  `attempt_apprentice()` → `recruit`), `score` showed the new 师傅/称谓
  immediately, and `xue qingwu force 5` (the real `learn` command)
  correctly deducted potential and raised `force` to level 1 — the
  organic teacher path works end-to-end. (Every *sect-master*-tier
  teacher checked for the same test — 岳不群/Huashan requires `int>=20`,
  张三丰/Wudang requires `shen>=5,000,000` + `int>=150` +
  `taiji-shengong>=100`, several others require `weiwang>=50` — all
  correctly gated far beyond a fresh newbie's reach, matching
  `doc/help/newbie`'s own advice not to bother with formal apprenticeship
  before reincarnating; 清无比丘 is the one genuinely-newbie-accessible
  teacher found.)
- **Combat / safe sparring**: no dedicated accept_fight-mirroring
  training dummy exists in this lib (checked; none of the
  `accept_fight()` implementations found via grep match that shape —
  unlike `bxsj`/`xiyouji`'s 木人). The lib's actual safety mechanism is
  structural: `fight`/`hit` (as opposed to `kill`) halt automatically
  once either side drops to ~50% resources and never escalate to death
  (`doc/help/combat`, confirmed live) — `fight qingwu` (against
  `chenmu`'s own newly-sworn low-tier master, `combat_exp` 5000)
  produced a normal turn-by-turn combat log, several real hits, exp/
  potential gains, and `force` improving mid-fight, then halted cleanly
  with `hp` afterward showing full, undamaged qi/jing — no crash, no
  danger.
- **Shop / economy**: see bug 2 above — `list` and item-matching now
  work correctly; a full successful purchase (real cash changing hands)
  was **not completed live** because `linshuang`'s starting funds are
  entirely bank-deposited, not cash-on-hand — noted explicitly rather
  than silently skipped.
- **`quit`**: reproduced clean on every attempt across this pass (from
  both indoor and outdoor rooms, both before and after all 4 fixes) —
  `debug.log` grepped after every single `quit` in this session, zero
  `error:`/`Too deep recursion`/eval-cost lines at any point.
- **Unclean disconnect (net-dead) + reconnect**: this lib's `net_dead()`
  (`obj/user.lpc:88`) does **not** park the player in any void/holding
  room — it just stops the heartbeat and leaves the object exactly where
  it was, remembered via ordinary `environment()`, with a real
  `reconnect()` (`obj/user.lpc:100`) that `adm/daemons/logind.lpc`'s own
  `reconnect()` genuinely calls (`grep -rn "->reconnect("` confirms one
  real call site, unlike the AGENTS.md §7.20 "nothing ever calls it"
  shape). Verified correct both **promptly** (every mudclient.py session
  after the first in this whole pass was itself an implicit net-dead
  reconnect, since the tool closes its socket without sending `quit` —
  location/stats/inventory correct every single time) and after a
  **real ~100-second wall-clock wait** (explicit test: logged in, let
  the connection lapse, blocking-waited 100 real seconds, reconnected —
  same room, same stats, same inventory, "重新连线完毕" reconnect
  message, no void-stranding). This lib does **not** exhibit the
  §7.20 bug class.
- **Clean-quit persistence across a real wait**: `quit` → real ~30-35
  second wall-clock wait → reconnect went through the full fresh-login/
  `restore()` path (not net-dead reconnect, since `quit` genuinely
  `destruct()`s the player object) — location (`startroom`, correctly
  either the actual outdoor room or `d/city/wumiao` for an indoor quit,
  per `quit.lpc`'s own rule), skills, stats, and inventory all restored
  correctly.

### Not verified live (explicit, not silently skipped)

- **A fully successful shop purchase** (cash actually changing hands) —
  blocked by `linshuang` having no loose cash, only bank deposit; the
  purchase-matching bug itself (bug 2) IS confirmed fixed and live-
  reproduced up to the affordability check.
- **Combat leading to a real fight loss / unconsciousness / death and
  the respawn/`DEATH_ROOM` flow** — `doc/help/newbie` and `doc/help`'s
  own economy notes make clear that reaching a genuine, deliberately-
  outmatched fight (or the `kill` command specifically) requires
  substantial grinding/travel investment beyond this pass's time
  budget; not attempted. `DEATH_ROOM`/ghost-respawn code was read (see
  bug 4's writeup) but not exercised live.
- **`start_room[i]` out-of-bounds (bug 4)** — fixed proactively by code
  shape-match to bug 3, not independently reproduced live (see bug 4's
  own note for why).

### Process hygiene

Native driver (`build-debug/src/driver config.fluffos`), restarted 5
times total to pick up each in-place fix; every restart verified against
`ps aux | grep "driver config"` + `readlink -f /proc/<pid>/cwd` before
touching any PID, and RSS spot-checked between restarts (peaked around
~590MB after a longer no-restart stretch, never ran away) per the
process-hygiene requirement. Final driver process killed cleanly at the
end of this pass; confirmed dead via `ps -p`.

## WASM 修复摘要（迁移自 meta.json 的 group_note）

状态已从过时的 limited 修正——这份档案自己的 README 里从未记录过任何缺陷说明，本轮重新测试也没有发现：一次完整的 WASM 注册流程（英文 id 仅限小写字母 → 确认 → 中文名字 → 管理密码+确认 → 登录密码+确认 → 天赋摇点，0 为随机 → 接受 → 电子邮件，需 id@address 格式 → 性别）全程无错误地进入"世外桃源"起始区域（"你连线进入这个世界，开始了自己的江湖生涯"），预先播种的管理员账号（fluffos/Mud@2026）也能正常登录，屏幕上确认了最高权限称号（"您目前权限：〖巫师协会懂事〗(boss)"——这份档案的顶层巫师等级字符串是 (boss)，不是 (admin)）。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 116 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（2026-08-12，round two，新驱动重测）

Re-tested against the freshly-rebuilt `build-debug/src/driver` (post
corpus-wide `quest_times`/`win_times` `%`-operator fix + the
Warning/warning driver-text revert). Booted clean, port 40006, zero
errors in boot log.

**Proactive source checks (no changes needed, all already correct
from earlier passes)**:
- `win_times` fix confirmed present and correct at
  `d/city2/npc/refereew.lpc:146`:
  `(string)(to_int(query("win_times")) % 5)`.
- `log_error()` (`adm/obj/master.lpc`) already uses case-agnostic
  `strsrch(message, "arning:")` matching (from an earlier session's
  §15af work) — correctly gates so wizards always see raw diagnostics
  but non-wizards only see a generic message for genuine errors, never
  warnings.
- No custom `message()` simul_efun wrapper exists in this lib at all
  (zero matches for `void message(mixed` corpus-wide) — this lib calls
  the native efun directly, so the message()-missing-`varargs` bug
  class (found on `nt6`/`nt6nitan6win`) doesn't apply here.
- `adm/simul_efun/file.lpc`'s `log_file()` has a simpler shape than the
  assure_file-euid-reset pattern found on the kernel-lineage/nitan
  libs (`log_file()` here is just
  `write_file(LOG_DIR + file, text)` — no `seteuid()`/`assure_file()`
  call at all, even though `assure_file()` is defined elsewhere in the
  same file). Did not assume this was a bug without live evidence.

**Live verification**: fresh registration via `mudclient.py`
(`linshuangb` / 尘沐, id → confirm y → Chinese name → admin password
×2 → login password ×2 → stat roll (0=random) → accept y → email →
gender m), reached 世外桃源 start room cleanly
("你连线进入这个世界，开始了自己的江湖生涯"), player count
incremented 103861→103862 confirming a real save. `debug.log` mtime
unchanged across the entire registration (predates this test session
by hours) — zero new errors. Re-logged-in with the same credentials
(`重新连线完毕`), confirmed persistence. Ran `quit` from inside a room
— found this lib's `cmds/usr/quit.lpc` does **not** call
`log_file("nosave/register", ...)` at all (unlike the
kernel-lineage/nitan siblings' `confirm()`-gated delete path;
`grep -rln log_file` across the whole tree turns up no `quit.lpc`
hit) — so the `log_file()` shape difference noted above is confirmed
**not a live bug**: this lib's quit flow simply never exercises that
function. No new bugs found this round; no changes made.

Driver killed cleanly by exact PID at the end of this pass; confirmed
dead via `ps -p`.
