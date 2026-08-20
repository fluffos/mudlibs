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

## Round three deep functional test (2026-08-18)

Standard 5-item checklist against a fresh `build-debug` boot, plus a
death→revive→reconnect playthrough and a board post/read test that
earlier rounds hadn't reached.

**Checklist items 1/3/4/5 — already clean, no changes needed**:
- §7.111 (`master.lpc`'s `standard_trace()`): already guards
  `file_name(error["object"])` with `objectp()` at line 242
  (`error["object"] ? file_name(...) : "<none>"`).
- §7.113 (netdead reconnect losing `heart_beat`): the real reconnect
  path IS `adm/daemons/logind.lpc`'s own `reconnect()` (line 1139),
  which calls `user->reconnect()` unconditionally (not gated on
  `silent`); `obj/user.lpc:110`'s `reconnect()` calls
  `set_heart_beat(1)` directly on the player body. Not dead code, not
  gapped — confirmed correct by inspection and live-verified below via
  an actual net-dead-then-reconnect cycle immediately after a real
  death.
- §7.90 (eval cost): `config.fluffos` already has `maximum evaluation
  cost : 10000000`, not the risky 700000 default.
- `logind.lpc`'s `enter_world()`: both `user->save()` and `ob->save()`
  present and uncommented (lines 914-915).

**§7.112 (`init()` unguarded `call_out()` chain, reconnect double-fire)
— found and fixed, but on DEAD CODE with zero live blast radius**:
`d/death/npc/wgargoyle.lpc` and `d/death/npc/bgargoyle.lpc` (白无常/
黑无常, reincarnation-desk NPCs) both had the exact vulnerable shape —
`init()` unconditionally `call_out("death_stage", 0, <target>, 0)`
with no re-entry guard, and `death_stage()` calling `ob->reincarnate()`
+ dropping inventory + moving to `REVIVE_ROOM`. However: neither NPC is
actually spawned anywhere in this lib. `d/death/gate.lpc` (the real,
live `DEATH_ROOM` = `/d/death/gate`) has its own `objects` entry for
`npc/wgargoyle` **commented out**, and a corpus-wide grep for
`wgargoyle`/`bgargoyle` outside their own two files turned up nothing
else. This lib's actual reincarnation flow is implemented directly and
*synchronously* inside `gate.lpc`'s own `init()` (no `call_out` at all
— reincarnate/drop/move all happen in one uninterruptible call chain),
so the real, live-reachable death path is not vulnerable to this bug
class. Fixed the two dead-code NPCs anyway (matches an established,
now-standard bug shape; consistent with this lib's own round-two
precedent of proactively fixing a code-shape match without live
reproduction — see round-two bug 4 above) — per-victim
`set_temp("death_stage_active", …)`/`delete_temp(...)` guard set in
`init()`, cleared at all 3 `death_stage()` exit points (early
`!ob`/`!present` return, the `!is_ghost()` redirect branch, and right
before `reincarnate()` on the success path). Both files are CRLF;
edited via binary-mode Python to avoid line-ending churn (confirmed via
`git diff --stat`: 9 lines changed each, no whole-file rewrite).

**New real bug found and fixed — §7.11 pattern (missing `/log/nosave/`
directory, unguarded `log_file()`), reproduced LIVE via the wizard
`call` command**: `adm/simul_efun/file.lpc`'s `log_file(string file,
string text)` (line 39) was a bare `write_file(LOG_DIR + file, text)`
with no `assure_file()` guard, even though a correct, unused
`assure_file()` helper already exists 300+ lines below in the same
file (identical to the 6-instance pattern already catalogued in
AGENTS.md §7.11). `log/nosave/` does not exist in this lib's `work/`
tree (confirmed: 84 *other* libs in this project have it, chidi
doesn't). Reproduced live: logged in as the seeded admin (`fluffos`)
and ran `call qiuyan->die()` on an online test character —
`cmds/adm/call.lpc`'s own audit-log call
(`log_file("nosave/CALL_PLAYER", ...)`) threw an uncaught
`*Wrong permissions for opening file /log/nosave/CALL_PLAYER for
append. "No such file or directory"`, printed as a raw error trace to
the admin's screen (via `master.lpc`'s `error_handler()`, working
correctly per §7.111) and aborting the `call` command **before**
`call_other(obj, args)` ever ran — so `me->die()` never actually fired.
This is not confined to `call.lpc`: the same unguarded `log_file()` is
shared by ~24 other `nosave/...`-prefixed call sites across the tree,
including `adm/obj/master.lpc`'s own crash logger
(`nosave/CRASHES`), `cmds/usr/passwd.lpc`'s password-change audit log,
`cmds/std/suicide.lpc`, `cmds/adm/{purge,setskill}.lpc`,
`cmds/wiz/kickout.lpc`, and `adm/daemons/securityd.lpc`'s promotion
log — all of these would throw the same uncaught error and abort
whatever command triggered them. (`feature/skill.lpc`'s
`nosave/set_skill` logger is whitelist-gated to skip all the normal
`xue`/`learn`/newbie-gift/combat-daemon paths, so it wouldn't have
fired during either round's normal playthrough testing — consistent
with neither round noticing it organically.) Fix: added
`assure_file(LOG_DIR + file);` immediately before the `write_file()`
call in `log_file()`, plus a one-line forward declaration
(`void assure_file(string file);`) — confirmed required live: the
first attempt without the forward declaration hard-aborted the whole
boot (`Undefined function assure_file` → `No program in object
'/adm/obj/simul_efun'!`, matching AGENTS.md §7.11's documented
forward-reference gotcha exactly). Both edits are CRLF; applied via
binary-mode Python (2-line and 1-line diffs respectively, verified via
`git diff --stat`).

**Verified live after the fix, fresh driver restart**: re-ran
`call qiuyan->die()` — full death sequence played out correctly
(combat-style death message, 〖江湖传闻〗 broadcast, gate.lpc's
white-无常 reincarnation dialogue, item drop, move to `REVIVE_ROOM`
i.e. 武庙/Wu Miao); `score` afterward showed 你共死亡 incremented to 1,
`i` (inventory) showed empty (starting cloth correctly dropped);
`log/nosave/CALL_PLAYER` now exists and contains the expected audit
line. Immediately chained into a real net-dead-then-reconnect test
(abrupt socket close, 3-second wait, fresh reconnect with the same
credentials): "重新连线完毕", landed back in 武庙 correctly, no
stranding, no error — confirms §7.113 still holds after a real death
+ reconnect sequence, not just an ordinary one. `work/log/debug.log`
did not exist at all after this entire pass (only created on a real
runtime error) — zero errors end to end.

**Board post/read tested for the first time this lib** (earlier rounds
never reached it): `d/board/towiz_b.lpc` (巫师反馈意见板), whose
`create()`/`setup()` moves itself into `/d/wizard/guest_room`
(reachable via `northwest` from the 武庙/wumiao start room) — confirmed
this project's "board file force-loaded via a bogus `call_other(...,
"???")` in the room's `create()`" idiom is just triggering the board's
own `setup()`→`move(location)` chain, not dead code. This specific
board's `do_post()` is wizard-gated (`if (!wizardp(this_player()))
return 0;`), so tested as admin: `post <title>` → FluffOS line editor
→ body text → `.` to save → "新贴子完成。" → `read 3` showed the new
post with correct title/author/body. (Board already had 2 pre-existing
posts carried over from the original archive's live save data,
including one from a real historical player titled "投胎的时候被踢出
来，没法投胎" — unrelated to this session's testing, left untouched.)
Reverted the test post's save-file churn (`data/board/towiz_b.o`)
before committing, along with the seeded admin account's routine
login-timestamp churn (`data/login/f/fluffos.o`, `data/user/f/fluffos.o`)
and the fresh test character's untracked save files
(`qiuyan`, id/password `qiuyan`/`LoginPw456`, created and then removed
— not kept as a seeded account).

Driver restarted 3 times total this pass (initial boot, post-§7.11-fix
attempt that hard-aborted on the forward-reference gotcha, final
working build); final process killed by exact PID, cross-checked via
`readlink /proc/<pid>/cwd` before killing, confirmed dead via `ps -p`.

**Flag for other libs**: the `adm/simul_efun/file.lpc` unguarded
`log_file()`/present-but-unused-`assure_file()` shape is now confirmed
independently on at least 7 lineages project-wide (6 already catalogued
in AGENTS.md §7.11 plus this one) — worth checking on sight in any
future round-three pass, not just when a symptom already points at it.

## AGENTS.md §7.100 修复（2026-08-19，批次三）

`ROOM` 基类冗余 `replace_program(ROOM);` 自崩溃地雷（详见 AGENTS.md
§7.100）：4030 处命中。本 lib 有三份独立的建房工具拷贝
（`clone/misc/roommaker.lpc`、`obj/roommaker.lpc`、`obj/rmmaker.lpc`），
三份的代码生成模板里都烤了同一个地雷，一并修复。

`git diff --stat`：4028 files changed, 3 insertions(+), 4030 deletions(-)，
与预期精确吻合。

验证：`build-debug` 驱动真实冷启动，端口 40006 正常监听。既有管理
员账号 `fluffos`/`Mud@2026` 登录，头衔显示【西天如来】，武庙→北大
街→中央广场多房间走访无误，`quit` 干净退出，全程无新增 "cannot
replace"/"cannot bind" 日志行（游戏本身既有的"首次编译警告显示给
管理员"调试功能产生了大量屏显编译警告，与本次修复无关，属预先存
在的行为）。

## Round-four deep functional test (2026-08-20): both round-three "not verified live" gaps closed, one new real bug found and fixed

Targeted follow-up on this lib's own two explicitly-flagged gaps from the
round-three pass (shop purchase with real cash, and combat leading to a
real death/respawn cycle), plus a fast standard-checklist sanity pass.

### Checklist re-confirmation (all already clean, no changes needed)

- §7.90: `config.fluffos` `maximum evaluation cost : 10000000` — confirmed.
- §7.100: corpus-wide grep for live, non-commented `replace_program(ROOM);`
  in `.lpc` files returns zero hits (all remaining raw-text matches are in
  `.bak`/`.vns`/doc files, or are commented out) — confirmed still fully
  swept from the 2026-08-19 batch-three pass.
- §7.111: `adm/obj/master.lpc`'s `standard_trace()` still correctly guards
  `file_name(error["object"])` with `objectp()` — confirmed.
- §7.112: `death_stage()` reentrancy — `d/death/npc/wgargoyle.lpc`/
  `bgargoyle.lpc` (fixed round three) still correct. Found one more
  instance not previously checked, `d/shaolin/npc/yu-zu2.lpc` (狱卒,
  少林 death-themed NPC) — its `init()`/`death_stage()` pair already has
  the correct guard shape (`set_temp`/`delete_temp("death_stage_active")`
  cleared at all 3 exit points: early return, escalation continuation,
  and the terminal move), so no fix needed. Also confirmed dead code (no
  room anywhere spawns `npc/yu-zu2`), consistent with the other two
  gargoyle files' dead-code status.
- §7.79: zero bare 2-arg `addn(`/`addn_temp(` calls corpus-wide.
- §7.108: `clone/user/user.lpc` (the real `USER_OB`, confirmed via
  `include/globals.h`) already has `enable_commands()` in `reconnect()`
  from the 2026-08-16 sweep commit. (A different, unrelated file,
  `obj/user.lpc`, looks similar but is dead legacy code not used as
  `USER_OB` — not to be confused with the real one.)

### Gap 1 (shop purchase with real cash) — RESOLVED, no bug, purchase completed live

This lib has a genuine two-tier currency system exactly like the sibling
libs referenced in the task brief: bank deposit (`money`/`more_money`
player fields) vs. physical coin objects (`coin_money`/`silver_money`/
`gold_money`, `/clone/money/*`). `feature/finance.lpc`'s `can_afford()`/
`pay_money()` (used by both `feature/vendor.lpc` and `feature/dealer.lpc`,
the two shop-NPC mixins) check ONLY physical coin objects present on the
player — bank deposit is never consulted. This is a legitimate design
split, not a bug, and it's exactly what round-three's `linshuang` got
stuck on.

**Found the sanctioned withdrawal command**: `feature/banker.lpc`'s
`do_withdraw()` (`withdraw <amount> <currency>`, e.g. `withdraw 200
coin`), registered on real live bank-teller NPCs (`d/city/npc/qian.lpc`,
钱眼开/"Money Eyes Open", 扬州钱庄) — reachable from the start-area map
(`d/city/qianzhuang.lpc`, west of `beidajie1`, itself one hop from
`wumiao`). Confirmed live: fresh character (`ceshiqi`, no admin
shortcuts used for this part) walked `wumiao`→`beidajie2`→`beidajie1`→
`qianzhuang`, `withdraw 200 coin` correctly cloned 200 physical coins
into inventory and deducted 200 from the bank-deposit balance (verified
via `check`). Then walked to `d/city/zahuopu.lpc` (杂货铺/general store,
`d/city/npc/yang.lpc` vendor, `dongdajie1`→south), `buy caoxie` (草鞋,
listed price 100) correctly deducted 100 coin from inventory and added
the item — confirmed via `i` (inventory) before/after. **Real cash
purchase completed end-to-end through unmodified game logic, no bug
found or fixed.**

### Gap 2 (combat → unconsciousness/death → respawn) — RESOLVED, real death reproduced, plus a genuine new bug found and fixed en route

**New bug found and fixed (§7.25 instance, `feature/skill.lpc` +
`inherit/room/room.lpc`)**: reaching a genuinely dangerous NPC required
teleporting a test character (admin `call ceshiqi->move(...)`, per the
task's sanctioned use of admin assistance for positioning) into
`/d/migong/lev15/dong4` (眠龙洞尽头, the endgame 12-level maze's final
boss lair — 7 aggressive dragon NPCs including `d/migong/lev15/npc/boss.lpc`
"千年火龙王"). The move threw an uncaught runtime error and **failed
outright** — the whole room's first-ever `reset()`/`make_inventory()`
chain aborted partway through, because `d/migong/lev15/npc/lev1.lpc`
("蓝龙") and its ~9 siblings across `d/migong/lev13`, `lev14`, `lev15`
(38 files total, confirmed via corpus grep) call
`set_skill("dragon", ...)`/`map_skill("unarmed","dragon")`/
`prepare_skill("unarmed","dragon")` — but this archive never shipped a
`/kungfu/skill/dragon.lpc` file (a genuine content gap, confirmed via
`find`; only compound names like `king-of-dragon`/`longxiang` exist).
`feature/skill.lpc`'s `set_skill()`/`map_skill()`/`prepare_skill()`/
`can_improve_skill()`/`improve_skill()` all `error()`ed on the missing
file, which — since `inherit/room/room.lpc`'s `make_inventory()` calls
`new(file)` completely unguarded — aborted the ENTIRE room population
cascade (every other dragon still left to spawn) and, via the call
chain `move()`→room `create()`→`setup()`→`reset()`→`make_inventory()`,
also aborted the calling `move()` itself. This is exactly AGENTS.md
§7.25's bug class (confirmed via `debug.log`'s full call-stack trace),
with the missing-skill trigger mechanism specifically matching a
precedent already fixed on a sibling lib (`fyzfqyy`, commit
`59145635381`). **Fix, ported from that precedent**: `feature/skill.lpc`'s
five `error("F_SKILL: No such skill...")` call sites now log to
`/log/nosave/missing_skill` and return/skip gracefully instead of
throwing (content gap logged, not fabricated); `inherit/room/room.lpc`'s
`make_inventory()` now wraps `new(file)` in `catch()` and returns `0` on
either failure mode, and both `reset()` call sites now guard the result
with `objectp()` before calling `is_character()`/`return_home()` on it.
**Verified live**: fresh driver restart, re-ran the same `move()` into
`dong4` — succeeded cleanly (`= 1`), all 7 dragons spawned correctly,
`/log/nosave/missing_skill` correctly recorded 14 skipped `dragon`/
`magic-old` skill grants across the room's full population, zero
`debug.log` errors. This is a real, previously-unencountered live bug
(this exact room was never visited in any prior testing pass on this
lib) with genuine blast radius (blocks entry to 3 whole maze levels'
worth of rooms on their first-ever load, for any real player who
eventually reaches them through normal maze progression, not just for
this admin-assisted test).

**Real combat → real death → real respawn, fully reproduced live**:
this lib's fresh-character combat balance turned out to be extremely
defense-favored — even 7 simultaneous endgame-tier dragons (skill
700-800, combat_exp up to 2×10⁹ on some) landed **zero** hits across
~150+ attack attempts against an untrained fresh character over several
minutes of real combat. Traced the actual cause by reading
`adm/daemons/combatd.lpc`'s `skill_power()`: the `apply/attack`/
`apply/attack1` temp fields (the obvious lever) only ever gate which of
two code branches fires (`level < 1`) — the branch that's actually
**returned** as usable attack/defense power is computed from
`str`/`dex`/`combat_exp`/a separate `dj` (`query_level()`, this lib's
distinct level-up-room-driven rank stat, unrelated to `combat_exp`) —
and both our fresh characters and the maze dragons had `dj = 0` (dragons
never went through the level-up room either), so hit chance reduced to
a `str`-vs-`dex` contest where our fresh characters' base stats
happened to dominate essentially every roll. This is a real oddity in
the formula (`apply/attack`'s magnitude is silently discarded once
`level >= 1`) but produces no error/crash — per this project's scope
rule, a combat-balance quirk with no error signature is not something to
"fix", so it was left alone and treated purely as a testing obstacle to
route around with legitimate admin assistance (exactly as the task
brief anticipated: "use admin ... stat or skill grants to get INTO
position").
Used admin `set()`/`set_temp()` on a `str` (the field that DOES feed the
formula, unlike `apply/attack`) — first on the endgame boss (partial
effect: it landed a very high hit that put the character into a genuine
`unconscious` state — the first of the two flagged states — with the
correct `hunmi=1`/disable/"你的眼前一黑" flow, confirmed live), then
more decisively via a fresh admin-summoned `/d/city/npc/liumang.lpc`
clone (a normal low-tier NPC template) with `str` set very high and a
real `kill liu` issued from the test character's own live session (not
an admin-forced action) in a normal fightable room
(`/d/city/beidajie2`, outdoor street — the maze boss room and the
`wumiao` start room are both `no_fight`-gated, confirmed by hitting
"这里不准战斗"/"大胆！在神像面前也敢胡来" and having to relocate).
**Result, fully through real unmodified combat/death mechanics**: the
`kill` command's own combat loop (real turn-by-turn attack/damage
resolution, `receive_wound()` reducing `qi`/`jing` for real) produced a
genuine lethal blow ("造成 92880 点瘀伤" → "你受伤过重...随时都可能
断气" → "扑在地上挣扎了几下，腿一伸，口中喷出几口鲜血，死了！"),
followed by the real 〖江湖传闻〗 public death broadcast, `feature/damage.lpc`'s
real `die()` (item drop — inventory confirmed empty afterward — ghost
flow, `DEATH_ROOM`), and landing safely at `REVIVE_ROOM` (武庙/Wu Miao,
matching round-three's finding) with **零** new `debug.log` errors and
no soft-lock (the exact bug class round-three flagged as a precedent
risk on `xajh2` did NOT recur here). `score` confirmed 你共死亡
incremented correctly (2, from an earlier near-death unconscious episode
plus this real kill). Immediately re-verified a genuine net-dead
reconnect after this real death (abrupt socket close + fresh reconnect)
landed back in 武庙 correctly with no stranding — §7.113/round-three's
reconnect-after-death finding re-confirmed under a DIFFERENT death
trigger (real combat, not the admin `->die()` shortcut round three used).

**Confirmed a real `kill`-command PvP-only gate, not an NPC-combat
gate** (matching the task brief's stated precedent from `dtsl2`/`mhxy`/
`xajh2`): `cmds/std/kill.lpc`'s `combat_exp < 500`-vs-`>10000` block is
wrapped in `if (userp(obj) ...)` — confirmed by reading the source, not
just by the successful NPC kill above.

**Process hygiene**: driver restarted 3 times (initial boot for the
checklist/gap-1 pass, post-`§7.25`-fix restart, final clean-boot
re-verification), each restart's PID cross-checked via
`readlink -f /proc/<pid>/cwd` before touching it and killed by exact PID.
The summoned `liumang` clone (temporarily `str`-buffed for the death
test) briefly went aggressive with its buffed stats before being
`dest`royed — it landed a few hits on the seeded admin account
(`fluffos`) too, including two real admin deaths; harmless (same
respawn mechanics, no permanent state loss) and cleaned up immediately
(`dest liu` once back in the same room). Driver RSS grew to ~4.7GB
during the multi-dragon/high-stat-NPC combat stress (chinese-number
string formatting and heartbeat combat resolution across 7
simultaneously-fighting high-stat NPCs is not cheap) but never
approached a real OOM risk (18GB free throughout) and returned to the
normal ~21MB baseline on the final clean restart. All throwaway test
character saves (`ceshiliu` — abandoned mid-registration after an
unrelated unclean-disconnect artifact left it looping through
re-registration, never completed; `ceshiqi`; `ceshiba`) removed before
committing, along with routine admin (`fluffos`)/`linshuang`
login-timestamp churn — none kept as seeded accounts, consistent with
round-three's `qiuyan` precedent.

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
