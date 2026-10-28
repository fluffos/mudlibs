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

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 4 line(s) in 1 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 2 here-document block(s) repaired (2 with the terminator glued to the last text line, 0 with it indented), so `End of file in text block` no longer hides the room or object behind them: `d/heimuya/shenggu.lpc`, `d/heimuya/tang.lpc`. The terminator must start its line (the lexer's own test, KB 04 §6.10); a glued one lost its newline in the GBK -> UTF-8 conversion together with a half character, which stays out.

## 深度功能测试（§10.7，2026-10-04）— paths named in another case

The archive comes from a case-insensitive host: files are stored as `BAGUA0.lpc`, `longjing.C`, `d/SHAOLIN/`, the code names them in lower
case (`__DIR__ "bagua0"`, `"tea/longjing"`, `"/d/shaolin/..."`), so the rooms, NPCs and items behind them could not be loaded (a `.C` file is
not an `.lpc` file; KB 03 §4.5). `scripts/lpc_case_paths.py --convert --apply chidi`: 18 file(s) renamed to lower case (`.C` -> `.lpc`,
`.H` -> `.h`) and 26 path reference(s) in 1 file(s) rewritten to the new spelling; 0 skipped, 0 ambiguous. Load check of the 19 objects that were renamed, edited or name a renamed path (HEAD against the working tree, an object is the same under any spelling of its path): 1 PASS -> 19 PASS, 0 that loaded before fail now, 18 more load.

18 files moved (18 `.lpc`); mostly under `u/luoyun/zhuanshi` (18). A rescan with `scripts/lpc_warnings.py chidi` is still due: the renamed files are compiled for the first time.

## 深度功能测试（§10.7，2026-10-05）— 任务表里的 `.c` 路径与任务守护进程的防护

`scripts/lpc_dynamic_rows.py`：`d/obj/quest/dynamic_location`、`d/obj/quest/dynamic_quest` 里 86 行写的是原档案的 `.c` 路径。转档时文件已改名 `.lpc`，而显式后缀按原样解析，`load_object("/d/x.c")`、`new("/d/obj/quest/x.c")` 返回 0 且不报错（KB 03 §4.2，KB 06 §7.220），所以 `adm/daemons/questd.lpc` 读到的每一行都加载不出来：随机任务和任务物品从未生成，在 `create()` 里直接对结果调用 `tar->set()` 的版本还会崩溃，连带加载它的 cron 守护进程和 `give` 的任务钩子。这些行已改为 `.lpc`；另有 1 行指向的文件两种后缀都不存在（档案缺内容），保持原样。
`scripts/lpc_dynamic_quest_guard.py`：2 处 `spread_quest()` 调用（`init_dynamic_quest()` 的循环里）包进 `catch()`，缺失的任务物品或编译不过的房间只跳过那一个任务，守护进程照常加载、其余任务照常生成。
验证：`adm/daemons/questd.lpc`和 cron 守护进程在新进程里加载（HEAD 一次，工作树三次，选房是随机的）：HEAD 通过 2 个，工作树三次分别通过 2、2、2 个（共 2 个），无回退。

## 深度功能测试（§10.7，2026-10-06）— 与 zhonghua2 同源的三处编译警告

- `include/npc/indian.lpc` 与 `masia.lpc` 共用全局名 `ma_sname`/`ma_pname`；两个头文件被同一个守护进程（`npcd` 等）一起包含时，后包含的印度名表覆盖马来名表，`generate_ma_name()` 生成的是印度名字。印度表改名 `in_sname`/`in_pname`（KB 04 §6.10）。

验证：改动的文件和包含 `npc/indian` 的守护进程在 HEAD 与工作树分别加载（`scripts/lpc_listcheck.sh`，新进程），无回退。

## 深度功能测试（§10.7，2026-10-07）— 空的 `if (current_water == 0) {}`

5 个房间的 `valid_leave()` 里有一行什么也不做的 `if (current_water == 0) {}`（编译警告 `Expression has no side effects`），删去，行为不变：`d/gaochang/room11.lpc`、`d/gaochang/room12.lpc`、`d/gaochang/room13.lpc`、`d/gaochang/room14.lpc`、`d/xingxiu/shanjiao.lpc`。

## 深度功能测试（§10.7，2026-10-07）— 被 `;` 截断的消息

`kungfu/skill/yizhi-chan/yizhi.lpc` 第二式的 `msg += "…护住身前。";` 后面单独一行"只听「嗤」的一声，掌影顿消，$p已经变得脸色惨白。"、`d/banghui/include/bunchnew.lpc` 结义失败提示"的提议只好作罢。"——多余的 `;` 把消息截成两句，后半句从来没显示过；接回去。

验证：改动的文件在 HEAD 与工作树分别加载（新进程），无回退。

## 深度功能测试（§10.7，2026-10-07）— 编译警告整理

`scripts/lpc_warnings.py chidi --fix` 加 `scripts/lpc_fix_no_effect.py --apply`：共改动 1296 个 `.lpc` 和若干 `.h`。HEAD 与工作树分别加载（新进程）：1235 -> 1235 通过；`d/chaoting/npc/japanese` 新能加载，`obj/npc/marchial` 一次失败——这个 NPC 加载时有随机成分，同一个新进程里连载三次，工作树也是时成时败，改动只是删了两行 `#pragma save_binary`，不是回退。改过的头文件的 56 个包含者 51 -> 51 通过。
手工：`feature/dbase.lpc` `set()` 里只剩注释的 `if (data > 500000000) { }` 去掉，注释留着；`adm/daemons/autobootd.lpc` 只在 `#ifdef REBOOT_TIME` 用的局部变量，声明挪进同样的条件里。
未动：`inherit/misc/bbsboard1.lpc` 的 `note["msg"] = (text, 1);` 是逗号表达式，帖子内容会存成 1——但这个留言板基类没有任何对象继承；`d/feitian/npc/xunbu.lpc` 的 `(: random_move() :);` 只造函数指针不调用，巡捕要不要走开是内容设计；`clone/misc/card.lpc` 本身有语法错误，HEAD 起就编译不过。

启动时警告 85 -> 0；新进程登录正常。

## 深度功能测试（§10.7，2026-10-08）— `.lpc` 后缀的定宽切片

`.c` 改名 `.lpc` 时只改了字符串没改切片宽度：`f[<2..] == ".lpc"` 拿两个字符比四个字符，永远不成立（`!=` 永远成立），按后缀筛文件、去后缀的代码因此从不运行或截成 `x.l`（KB 06 §7.238）。`scripts/lpc_lpc_suffix_slice.py --apply` 改了 1 处比较、1 处去后缀（如 `cmds/bos/mem.lpc`）；改动的文件 HEAD 与工作树分别加载（新进程），无回退。

- 2026-10-10：8 个 NPC 同时继承 `NPC` 和 `F_UNIQUE`、自己没有 `init()`，驱动只取其中一份（`init() inherited from both /feature/unique.lpc and /feature/attack.lpc`）：要么 `attack.lpc` 的主动攻击/仇杀检查从不执行，要么 `F_UNIQUE` 的持有者检查从不执行。每个补一个两份都调的 `init()`（`scripts/lpc_fix_unique_init.py`）；HEAD 与工作树载入结果相同，这条警告清零。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查

- `d/feitian/npc/xunbu.lpc` 巡捕：`(: random_move() :);` 只造函数指针不调用，巡捕从不走动；改为 `random_move();`（同码的另 9 个库一并修）。
- `inherit/misc/bbsboard1.lpc`：`note["msg"] = (text, 1);` 等四处是逗号表达式，存进去的帖子内容是数字 1（原档就如此，丢了一个函数名）；照 `bbsboard.lpc` 改为存 `text`。目前没有对象继承它。
- `clone/obj/genmap.lpc`：`DEBUG` 是空宏，留下 `("text", n);` 语句；改成空函数（与 yxcs 同法）。载入无回退。

## 深度功能测试（§10.7，2026-10-12）：编译警告收尾

`scripts/toolkit_fix.sh` 加手工修复，能编译的文件里的警告 78 → 0（15727 个文件可编译，数量不变）。剩下的 7 条都在本来就编译不过的 `clone/misc/card.lpc` 里（`add(...)` 少分号、`obj3 += 100` 把对象当整数加，不是一处小改能修好的，没动）。

**机械修复（工具）：** 27 个 `int init()` 只回传标志 → `void`（含 `clone/shoufei/long/armor.h`）；21 个 `string query_autoload()` 覆盖 item/whip 的 `int` 版本 → `mixed`（`feature/autoload.lpc` 把返回值原样当 autoload 参数用，返回值不变）；11 处 `a != x & a != y` → `&&`（五毒教毒囊、`dongxue.lpc`，结果不变只是恢复短路）；`clear_title`/`give_gift`/`mapit` 原型与定义对齐；2 处多余 inherit；`board.lpc` 只在 `#ifdef BACKUP_B` 里用的 `transfer` 移进分支。

**手工修复：**
- `quest/haojie/npc/wuzhe.lpc`：`do_join()` 覆盖 `bhnpc.lpc` 的 `int do_join(object)`，原型和定义都改成 `varargs mixed`（行为不变）。工具这里出过错：原型和定义两条诊断落到同一个定义上，同一处替换做了两次，写出 `varargs mixeddo_join()`（成了另一个函数，询问 join 会改走 bhnpc 的版本）；已手工改正，`scripts/lpc_fix_void_override.py` 现在每处编辑只做一次。
- `quest/quest_kill/dugu.lpc`：`ask_kill` 有 `int` 和 `string` 两个原型，删掉与定义不符的 `string` 那个。
- `d/city2/shenzhen/npc/shenyi.lpc`：发银针的计时 `last_time` 跟 `feature/alias.lpc` 的 `nosave last_time` 同名，改名 `last_zhen_time`（本来就是两个变量，行为不变）。
- `quest/tulong/npc/dragon.lpc`：全局 `object killer = this_player()` 跟 `feature/attack.lpc` 的 `object *killer` 同名，改名 `summoner`（只在 create() 里读属性用）。
- `d/register/npc/dizangwang.lpc`：`attempt_apprentice()` 改 `void`（`cmds/skill/apprentice.lpc` 不读返回值）。
- `clone/ship/harbor.h` 的 `wildharbors` 包进 `#ifndef HARBOR_NO_WILDHARBORS`，在 `find_exits()` 里 include 它的 `genmap.lpc` 先 `#define`（它用不到这张表）。
- `d/emei/user-room/host/home.lpc` 的 `STORY_DIR` 前加 `#undef`；`huashan-jian.lpc` 删掉一个多余的 `;`。

另：本库 `config.fluffos` 是 CRLF，`toolkit_fix.sh` 第 0 步读出的 master 路径带 `\r`，lpcc 一直报 master 载入失败；脚本已改为去掉 `\r`。

915 个对象载入无回退（HEAD 914 通过，现在 914 通过）；`lpc_audit_removed_locals.py` 0 条需复查。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。10 个文件 13 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）；`x op= 浮点` 先把浮点转成整数再运算（系数小于 1 时 x 直接变 0），改为 `x = to_int(x op ...)`：`/kungfu/skill/taiji-quan/zhenup.lpc`（`damage *=`）、`/quest/quest_kill/quest_npc111.lpc`（`reward_exp +=`）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。
- 2026-10-14：9 个技能文件 `int power_point() { return 1.75; }`、2 个 `int hard_point() { return 2.5; }`，浮点值经 int 返回被截成 1、2。本库没有调用者（只有书本的 `"power_point"` 属性同名），改成 `float` 返回值，数值照原意保留。

- 2026-10-15：`kungfu/skill/guangming-blade.lpc`（光明刀法）是从五虎断门刀抄来的，`query_action()` 里仍按 `wuhu-duanmendao` 的等级挑招式：没练五虎断门刀的人出招时一招都匹配不上，`a_action` 为 0，接着赋值报错。改为按 `guangming-blade` 自己的等级。（武功运行期探针发现。）

## 内力/精力当作伤害种类（2026-10-15，KB 06 §7.241 第二类）

本库 `feature/damage.lpc` 的 `receive_damage()` 不接受 `jingli`/`neili`/`force` 等种类，`me->receive_damage("jingli", 30)` 之类在练功、绝招、吸取时报 `F_DAMAGE: 伤害种类错误`。45 处改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py` 第二步）。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。3 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。


## 东方故事/西游记体系的技能文件（2026-10-15，KB 06 §7.241 第三类）

这些 `kungfu/skill` 文件来自 gin/kee/sen/force 体系，本库人物只有 jing/qi/neili：`receive_damage("kee", 30)` 报 `伤害种类错误`，`query("force")` 永远为 0，技能学不了也练不了。按 kee→qi、gin/sen→jing、force→neili、max_force→max_neili、force_factor→jiali 改了属性名（`scripts/lpc_port_es_props.py`），共 9 个文件。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

另有 20 个文件（绝招、状态、物品、NPC 等，不限于 kungfu/skill）来自 gin/kee/sen/force 体系，同样按 kee→qi、gin/sen→jing、force→neili 改名（`scripts/lpc_port_es_props.py --any-file`）。


## family 映射（补）（2026-10-15）

`mapping fam = (mapping)me->query("family");`（带类型转换的写法）同样直接取下标，1 处补上 `if (!mapp(fam)) fam = ([ ]);`。

## 治疗/疗伤的属性名（2026-10-15，KB 06 §7.241）

`receive_heal()`/`receive_curing()` 也只接受本库的种类。5 个文件（多为只调用 `receive_heal`/`receive_curing` 的药物、NPC）来自其他体系，按本库的属性名改名（`scripts/lpc_port_es_props.py --any-file`）。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。3 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。


## 技能按另一门武功的等级取招（2026-10-15，KB 06 §7.243）

这些技能文件是从别的武功复制改名来的，`query_action()` 仍用原武功的等级查招式表：只会本技能的人等级为 0，取不到招，每次出招都报错。改为读本技能自己的等级（`scripts/lpc_fix_action_level.py`）：`quanzhen-jian`。

补（同日）：`kuangfeng-jian` 读的是 `kuangfeng-jianfa` 的等级（华山风不平教的就是 `kuangfeng-jian`）。它真正的 `query_action()` 上方还有一份注释掉的旧定义，第一遍扫描读到的是注释那份，所以漏掉了；脚本现在只认代码里的定义。

## 妙手回春的银针检查（2026-10-15）

`miaoshouhuichun` 的 `valid_learn()` 用了未赋值的 `object ob`（`ob->query_temp("weapon")` 报错），还把兵器对象和字符串 "银针" 比较。改为 `ob = me->query_temp("weapon")`，再用 `id("yin zhen")`/`id("yinzhen")` 判断是否银针。

## 空手使用兵器绝招（2026-10-15，KB 06 §7.246）

`perform` 指令允许直接点名招式（如 `perform stick.ban`），这些绝招读了 `me->query_temp("weapon")` 却从不检查，空手时 `weapon->name()` 报错（有的已先扣了内力）。在赋值后补 `if (!objectp(weapon)) return notify_fail("你必须手持兵器才能使用这一招。\n");`（`scripts/lpc_fix_perform_weapon.py`）：`bahuang-qiangfa/throw`、`bingpo-blade/ningxie`、`liangyi-dao/sanshen`、`murong-jianfa/kuangjian`。

## 把经验、属性、内力当技能读（2026-10-15，KB 06 §7.247）

经验、属性、内力上限不是技能，xkx/ES 的 `query_skill()` 对它们只返回 0（风云的还会去载入同名技能文件而报错）。改为 `query("...")`（`scripts/lpc_fix_pool_as_skill.py`）：`/quest/wudang/song` 生成的任务怪物照抄玩家福缘（`set("kar", who->query_skill("kar"))`，怪物福缘一直为 0）。

当前内力、精这类名字有时指的是内功技能，逐处读过后手改：`gouyee/heal`、`yuxuan-guizhen/heal` 的疗伤量写成 `query_skill("neili") / 5`，本库其余疗伤 exert 都是 `query_skill("force") / 5`，照此改为内功等级（若读内力，疗伤量会大十倍）；落英缤纷 `luoying-shenjian/lybf`：自己的注释说成功率由“精神高低”决定，两处 `query_skill("jing")` 改为 `query("jing")`。

## 碧海生潮曲空手报错（2026-10-15，KB 06 §7.246）

`iceforce/roar`（碧海生潮曲）先 `ob = me->query_temp("weapon")`，再直接拿 `base_name(ob)` 判断是不是玉箫；空手 `exert roar` 时 `base_name(0)` 报错，提示“你必须先找一只玉萧来才可以吹－－曲”根本出不来。条件前补 `!objectp(ob) ||`。

## iceforce「chillgaze」从未编译通过（2026-10-15）

`iceforce/chillgaze` 原档在第一个 `return notify_fail(...)` 后多了一个 `}`，`exert()` 就此结束，后面的语句全落在函数外，`skill`、`damage` 也没有声明，文件编译失败，这个 exert 从来用不了。照 bixiecanyang、hc、xyzx3 已修好的版本删去多余的 `}`、补上 `int skill, damage;`，其余字句不变，只是缩进进函数体。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`beimin-shengong`→`beiming-shengong`（`guiyuan-dafa`、`honghua-shengong`、`tiangang-zhengqi`、`wangran-xinfa`、`xiantian-gong`）；`douzhuan-xignyi`→`douzhuan-xingyi`（`/d/mr/npc/obj/shu1`、`/d/mr/obj/shu1`）；`hujia-dao`→`hujia-daofa`（`hujia-dao/cangdao`、`hujia-dao/xuehai`）；`meinu-quan`→`meinu-quanfa`（`meinu-quanfa/luowang`）；`mizongxinfa`→`mizong-xinfa`（`longxiang/fanchang`）；`yihua-jimu`→`yihua-jiemu`（`yihua-jiemu`）；`yunv-xinjing`→`yunu-xinjing`（`wangran-xinfa`）；`zhenfen-xinfa`→`zhenfeng-xinfa`（`zfwy-bu`）。

## 技能名拼错：技能文件里拼错自己的名字（2026-10-15，KB 06 §7.249）

技能自己的文件（或它的绝招目录）里，`query_skill()` 读的是差一个字母的自己的名字，永远得 0：“基本功夫要高过本技能”之类的限制从不生效，按等级取招、计算伤害的那一项一直是 0。改为本技能的名字（`scripts/lpc_fix_skill_typo.py` 的 self 判据）：`baitao-xuangong`→`bitao-xuangong`（`bitao-xuangong`）；`bobo-shengong`→`bibo-shengong`（`bibo-shengong/powerup`）；`jinggang-quan`→`jingang-quan`（`jingang-quan`）；`jiujin-shengong`→`jiuyin-shengong`（`jiuyin-shengong/perform/zhang`）；`tiaodao-blade`→`tiandao-blade`（`tiandao-blade`）。

## 地图数据库 mapdb 读到只有文件头的 map.o（2026-10-15，KB 06 §7.250）

本库的 `data/npc/map.o` 只有一行文件头：genmap 第一次载入时 `if (!restore()) save();`，地图还没建就存了档，值为 0 的变量不写进去。mapdb 的 `restore()` 读它成功，`map` 却成了 0，`query_room_info()`、`query_room_exits()`、`query_map()` 都对 0 取下标或把 0 交出去：本库暂无调用者，问题潜伏。mapdb（`/clone/npc/mapdb.lpc`）加一个 `restore()`：读档后 `map` 不是映射就重置为 `([])`；地图为空时 `query_random_room_path()` 返回 0。地图本身仍需巫师用 genmap 生成。

## family 映射内联取下标（2026-10-15，KB 05 §7.30）

`ob->query("family")["master_name"]`、`me->query("family")["family_name"]`（泥潭式为 `query("family", ob)[...]`）直接对门派映射取下标：没有门派的人（新玩家、叛师者、大多数 NPC）在 NPC 的打招呼和问话、绝招的门派判断、房间的 `valid_leave` 里报 `Value being indexed is zero`，而不是得到拒绝。8 处（6 个文件）改为 dbase 路径查询 `query("family/master_name")`：有门派时值相同，没有时得 0；原有的判断照常生效（`scripts/lpc_fix_family_index.py`）。给映射赋值的写法未动。


## 用兵器的绝招空手施展时报错（内联写法）（2026-10-15，KB 06 §7.246）

绝招不存兵器变量，直接写 `(me->query_temp("weapon"))->query("name")`（或在拒绝判断里写 `(weapon = me->query_temp("weapon"))->query("skill_type")`），之前又没检查兵器：空手 `perform` 时报 `Bad argument 1 to EFUN call_other()`，内力等往往已经扣掉。在第一次用到它的那条语句前补上“你必须手持兵器才能使用这一招”的拒绝（`scripts/lpc_fix_perform_weapon.py`）：`yunu-jianfa/suxin`。

## 移进不存在的巫师房间（2026-10-15，KB 06 §7.251）

用完的物品、要“离开”的 NPC、掷在空中的兵器被移进巫师的工作室（`/u/llm/`、`/u/lonely/`、`/u/wind/`），本库没有这些房间。本库的 `move()` 用 `load_object()` 找目的地，找不到就返回 0，不报错，东西留在原处：被雇来打晕或杀人的李凌（`d/city2/npc/liling2`）办完事后没有离开，留在原地（`d/city2/npc/liling2` 本身还载入不了：`create()` 里 `carry_object()` 的物品文件缺失或编译失败，见 KB 06 §7.73，另行处理）；婚礼结束（`d/nanyang/npc/meipo` 的 `last_marry`）时月老没有离开喜堂，每办一次婚礼喜堂里就多一个月老；喜宴结束后喜来福（`d/nanyang/npc/xi-laifu`）没有退回内堂，每办一次婚礼迎宾楼就多一个喜来福。3 个文件改为移进本库的虚空房间 `VOID_OB`（`/clone/misc/void`），与原作把它们“停放”在巫师房间的用意相同（haiyang2 的维护者把月老送进 `/d/city/empty`，也是同样的做法）。

## 玉女剑法「合壁」用一次就永久改动经验和剑法（2026-10-15，KB 06 §7.253）

收尾的 `hebi()` 声明时没有参数（`void hebi() { object me, target, env; int i, j, o, p, count; ...`），call_out 传进去的人和数值全被同名的局部变量（0）挡住，开头的 `if (!me && !target) return;` 每次都返回：合壁的攻击、闪避加成和 `hebi` 标记要到重新登录才消失。更糟的是夫妻判断写成了 `target->querry("id")`（没有这个函数，得 0），没成亲的人 `marry/id` 也是 0，于是人人都被当成夫妻：自己的玉女剑法和经验乘以玉女素心功的级数/80（至少变成浮点数，160 级以上翻倍），随后给对方 `set_skill("combat_exp", ...)` 时报 `No such skill`，收尾的 call_out 也就没排上，乘过的等级和经验永远不还原。测试里用一次合壁，经验 100000 变成 200000.0、剑法 100 变成 200.0。改正：`hebi()` 按它自己再次 call_out 时传的八个参数声明，`perform` 的 call_out 去掉多余的 `h, k`，`querry` 改为 `query`，给对方的 `set_skill("combat_exp")` 改为与上一行一样的 `set("combat_exp")`。测试里加成照常生效，`hebi()` 结束时还原并清除标记，没成亲的人经验和剑法不变。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

31 个文件、47 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/d/japan/npc/obj/armor`、`/d/japan/npc/obj/sword`、`/d/huanhua/npc/obj/jinpao`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 0 个，改后 20 个（20 个原来载入不了），没有退步；其余 12 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## 物品清单把名字的第一个字吃掉（2026-10-18，KB 07 §8.1）

`inventory`、房间的物品列表（`feature/move`）和部分 `look` 把同名物品合并计数，键是 `query("unit") + short()`，只有一件时按 `key[2..]` 去掉量词。量词是一个汉字，在原来的 GBK 里占 2 字节，`[2..]` 正好去掉量词；转成 UTF-8 以后一个汉字只占一个下标，这一刀把名字的第一个字也切掉了（「把长剑」只显示「剑」，带颜色的名字切掉的是转义序列开头）。改为 `[1..]`（`scripts/lpc_fix_unit_cut.py`）：`cmds/usr/inventory.lpc`、`feature/move.lpc`、`quest/quest_jun/look.lpc`。

## 水潭里 `ging_cost` 是 `jing_cost` 的笔误（2026-10-18）

`shuitan` 先算 `jing_cost`，倒水时却扣 `receive_damage("jing", ging_cost)`，`ging_cost` 从没声明过：`Undefined variable 'ging_cost'`，整个物件载入不了。改成 `jing_cost`：`d/shaolin/npc/obj/shuitan.lpc`。改后用 `lpcc` 逐个载入这些对象：1 个通过。


## 武林盟主类 NPC 的存档里 `weapon`／`armor` 是个 mapping（2026-10-18）

盟主、`fa-e`、`shang-shan`、`tang3`/`tang2`/`xingtang` 这几个 NPC 在 `create()` 里 `restore()` 之后直接 `carry_object(query("weapon"))`。换盟主时 `do_recopy()` 把玩家整个 dbase 抄进来，玩家的 `weapon` 若是自制兵器的 mapping，存进 `data/npc/*.o` 以后下次载入就是 `new(mapping)`：`Bad argument 1 to EFUN new()`，NPC 载入失败。本库的存档里确实有这种 mapping。两行都加 `stringp()` 判断，mapping 时不拿武器（NPC 空手）：`clone/npc/fa-e.lpc`、`clone/npc/meng-zhu.lpc`、`clone/npc/shang-shan.lpc`。改后用 `lpcc` 逐个载入这些对象：3 个通过。

## 补回丢掉的基类宏（2026-10-18，KB 04 §6.13）

`inherit F_XXX;` 里的宏本库任何头文件都没有定义，报 `syntax error, unexpected L_IDENTIFIER, expecting L_STRING or '('`，整个对象载入不了；宏指向的基类文件本库其实有，别的库都把这个宏定义成同一个路径。在全局头文件 `include/globals.h` 里补上：`SSERVER` → `/inherit/sserver`（3 个文件）、`NPC_TRAINEE` → `/inherit/char/trainee`（1 个文件）。（`scripts/lpc_restore_macros.py`）改后用 `lpcc` 逐个载入这些对象：4 个里 3 个通过，其余 1 个还有别的错误（`d/xingxiu/npc/lingshe.lpc`：Undefined function set_color）。

## `kungfu/skill/qingyi-jian` 第一式的 `skill_name` 丢了收尾引号（2026-10-18，KB 03 §4.6）

`"skill_name" : "大悲式,` 的收尾引号没了（转码时跟半个汉字一起丢了），字符串连到下一行，`damage_type` 成了代码：`Illegal character 0xe5`，整个武功载入不了。补回 `",`（同系的 bixiecanyang、syxjl 等库里有完好的同名文件）。载入：通过。

## 补回本库没有的基类文件（2026-10-18，KB 04 §6.15）

下面这些基类本库没有，继承它们的对象（房间、NPC、物品）整批载入不了（`inherit XXX;` 的宏没定义，或者 `inherit "/std/…";` 的文件不在）。同系的库里有同名文件，两库有大量逐字节相同的文件（亲缘关系），所以从那边原样拷来，缺的宏补进全局头文件 `include/globals.h`：`/inherit/weapon/ring`（宏 `RING`）←xyzxyl201412，10 个对象继承它，抽样 10/10 载入；`/inherit/weapon/rake`（宏 `RAKE`）←wxddym，4 个对象继承它，抽样 4/4 载入；`/std/weapon/archery`（宏 `ARCHERY`）←shenmo，2 个对象继承它，抽样 2/2 载入；`/d/xueshan/obj/anqi-jian`←shenmo，2 个对象继承它，抽样 2/2 载入；`/inherit/room/city1`←fqyy2，1 个对象继承它，抽样 1/1 载入。每个基类补回后单独载入、再抽样载入使用它的对象，基类载不进来或者一个用户也载不进来的就撤掉（本库撤掉了它们，不再补）。（`scripts/lpc_restore_bases.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 55 处、30 个文件：`yunv-xinfa`→`yunu-xinfa`（18 处）、`yunv-shenfa`→`yunu-shenfa`（14 处）、`yujiashu`→`yujianshu`（4 处）、`yan-fly`→`yanfly`（3 处）、`xinxiu-duzhang`→`xingxiu-duzhang`（2 处）、`tiaji-jian`→`taiji-jian`（2 处）、`kongmingquan`→`kongming-quan`（2 处）、`taiji-shenfong`→`taiji-shengong`（2 处）等共 16 个名字。（`scripts/lpc_fix_skill_names.py`）

## 调用了父类没有的函数的对象（2026-10-19，KB 06 §7.259）

`::create();`、`::init();`、`return ::buy_object(who, item);` 这类调用写的是父类里有这个函数的版本；本库的父类没有，旧驱动把它当空操作（返回 0），现在的驱动在编译时就报 `Unable to find the inherited function`，整个对象载入不了。单独成句的调用删掉，`return ::f(...)` 改成 `return 0;`（void 函数里是 `return;`），与旧驱动的行为一致。共 2 处、2 个文件：`::scan()`（2 处）。只改了出错原因全是这一类的文件；还带着别的错误（多半是父类本身没了）的文件没动，等父类补回后再看。（`scripts/lpc_fix_dangling_super.py`）

## set_name 的 id 参数传成字符串（2026-10-19，KB 06 §7.260）

`set_name("海口大碗", "bowl");` 把物品的 id 写成了字符串，本库的 `set_name(string name, string *id)` 要的是数组，驱动在编译时报 `Bad type for argument 2 of set_name ( string * vs string )`，整个物件载入不了；旧驱动不检查参数类型，字符串里照样找得到这个词，物品能用 id 称呼。改成 `({ "bowl" })`，共 2 个文件：`/d/baituo/npc/obj/bowl.lpc`、`/d/baituo/obj/bowl.lpc`。（`scripts/lpc_fix_set_name_id.py`）

## feature/damage.lpc 丢了 set_ghost()（2026-10-19，KB 06 §7.262）

`feature/damage.lpc` 里有 `int ghost` 和 `is_ghost()`，没有 `set_ghost(int i)`；木人、狼等 NPC 在 `create()` 里调用它，整个 NPC 报 `Undefined function set_ghost` 载入不了。从 xkx100 补回这一行函数，受益 NPC 1 个：`d/feitian/npc/wolf`。（`scripts/lpc_transplant_function.py`）

## add_light() 空函数（2026-10-19，KB 06 §7.262）

`d/temple/` 和 `d/chaoting/fuya/` 的房间调用 `add_light(this_object(), 1)`，这个房间照明效果在整个存档里从来没有实现过，所以这些房间 `Undefined function add_light` 载入不了。照 yxcs 的做法在 `adm/simul_efun/object.lpc` 里放一个空函数 `void add_light(object room, int level) {}`（效果本来就没有）。

## 全局头文件丢了 2 个宏（2026-10-19，KB 04 §6.16）

`/include/globals.h` 里没有定义 `UNARMED_ATTACK`、`REMOTE_ATTACK`，用到它们的物件（名单里 2 个）编译时报 `Undefined variable`/`Undefined function`，整个物件载入不了（编译器在第一个未定义的名字上停下，后面的错误和警告都看不到）。同系的库在各自的头文件里都有这几行：照其中和本库共有文件最多的那个库，原样补到 `/include/globals.h` 最后一个 `#define` 之后，宏体里出现的路径在本库里都存在。补完后名单里有 2 个载入，其余还差别的东西。（`scripts/lpc_restore_defines.py`）

## 和包含文件同目录的头文件，改成引号形式（2026-10-19，KB 04 §6.17）

1 个文件用尖括号写 `#include <hedi.h>` 这类头文件（`12gong.h` 等），头文件其实就放在它们自己的目录里。老驱动对尖括号名字也会先找包含文件所在目录，本驱动只找 include 路径，所以报 `Cannot #include ...`，整个物件载入不了。改成 `#include "hedi.h"`（引号形式相对包含文件解析，预加载、`lpcc` 和运行时编译都一样）。（`scripts/lpc_fix_local_include.py`）

## 出口指向不存在的房间（2026-10-19，KB 06 §7.257）

下列房间的出口写的文件不存在，而对面恰好只有一个房间的出口指回本房间，所以按对面的房间改正（笔误、大小写、路径少了一级）：

- `/d/green/entrance.lpc` 的 `north` 出口：`outdoor` → `eight0`

改后房间照常载入（与 HEAD 逐个对比，没有退步），出口现在指向存在的房间。

## 区域物件的零碎修正（2026-10-19，KB 06 §7.267–§7.271）

- `/d/board/mingjiao_b.lpc` 的 `location` 从不存在的 `/d/mj/guangming-ding` 改成 `/d/mingjiao/guangming-ding`（载入明教留言板失败会让光明顶房间载入不了）
- 5 个 NPC 文件、5 处 `create()` 里的 `this_player()->carry_object(` 改成 `carry_object(`（没人在场时 `this_player()` 是 0，NPC 载入不了；有玩家在场时衣服武器落到玩家手里）

逐个物件与 HEAD 对比载入，没有退步。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 补回丢失的标点（2026-10-19，KB 03 §4.6）

转换时丢掉的分号、逗号、引号或文件末尾的 `}`，共 2 个文件，修前 HEAD 载入失败。文件末尾少了 `}`（最后一个或两个字节丢了），补上：`/d/legato/obj/skeleton.lpc`（2 个）、`/quest/baobiao/yuanwai.lpc`。修后与 HEAD 逐个对比载入：这 2 个物件全部载入，没有退步（`scripts/lpc_restore_from_twin.py`、`lpc_fix_eaten_quote.py --comma`、`lpc_fix_eof_braces.py`）。

## `== !"字符串"` 多出来的 `!`（2026-10-19，KB 06 §7.280）

`!"taoist"` 是整数 0，`x == !"taoist"` 就是“x 等于 0”，作者为其余所有人写的那一支永远走不到。具体是：龙女对古墓弟子的机关暗门提示永远给不出来（5 处）；孙婆婆的“你去吧”只对 class 没设置的人生效；性别检查（“你不是女的，无法领会其中至阴之理”）永远不拦人，男的照样能学玉女心法。全部改成 `!= "字符串"`（`scripts/lpc_fix_not_literal_cmp.py`）：`/kungfu/class/gumu/long.lpc`（5 处）、`/kungfu/class/gumu/sunpopo.lpc`（1 处）、`/kungfu/skill/yunu-xinfa.lpc`（1 处）。同样的行在 xkx 一系的 35 个库里都有。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。具体是：客栈小二从不拦住付了房钱又往南/往北走的客人；百日十龙丸怎么 `eat` 都只得到“你要吃什么？”。改动：`/d/changan/ca2.lpc`（1 处）、`/d/longmen/xuehepai/obj/bairiwan.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 10 处）；其后 `x == "a" && x == "b"` / `x == "a" || "b"` 这类被 `==` 暴露出来的链也随之改成 `||` 或补全变量（`/d/hainan/npc/xianhe.lpc`、`/d/hainan/npc/xiaohe.lpc`、`/d/shushan/shanjian.lpc`）。改动：`/d/hainan/npc/xianhe.lpc`（3 处）、`/d/hainan/npc/xiaohe.lpc`（3 处）、`/d/shushan/shanjian.lpc`（2 处）、`/quest/guojob/guo.lpc`（2 处）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/obj/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## 翻页器 `start_more(read_file(...))`：文件缺失时 `explode(0)`（2026-10-20，KB 06 §7.300）

东方故事系的翻页器 `void start_more(string msg) { ... explode(msg, "\n") ... }` 被这样调用：`start_more(read_file(HELP_DIR + "help/topics"))`、`start_more(read_file(NEWS))`。压缩包没带的文件使 `read_file()` 回 0，`explode(0, ...)` 在本驱动里报 `Bad argument 1 to explode()`（不带参数的 `help` 指令就是这样出错的），老驱动把 0 当空文本。在 `start_more` 开头加了 `if (!stringp(msg)) return;`（`scripts/lpc_fix_start_more.py`）。改动：`/feature/more.lpc`。

## `get_config(__MUD_PORT__)` 经旧版 `runtime_config.h` 得到字符串（2026-10-20，KB 06 §7.302）

本库的 `include/runtime_config.h` 是老 MudOS 的编号（整数设置从 15 起，本驱动从 256 起），`get_config(__MUD_PORT__)` 读到的是另一项设置（字符串），`(int)` 又只是编译期标注，于是 `socket_bind(fd, LOCAL_PORT())` 报 `Bad argument 2 to socket_bind()`，版本守护进程 `port = get_config(__MUD_PORT__) + VERSION_PORT` 是字符串相加。头文件自己的注释写明 `get_config(__MUD_PORT__) == __PORT__`，所以代码里的这个调用（连同外面的 `(int)` / `to_int()`）改成了驱动的预定义 `__PORT__`（`scripts/lpc_fix_mud_port.py`）。改动：`/adm/daemons/versiond.lpc`（1 处）、`/include/getconfig.h`（1 处）。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库现有的 NPC 文件里没有字面写成空 `chat_msg` 的（扫描只认 `set("chat_msg", ({ }))`）；守卫挡的是运行时才为空的列表和以后新增的 NPC。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/d/migong/obj/npc1.lpc`、`/inherit/char/npc.lpc`（共 2 个文件）。

## 存档里的 `.c` 文件名改成 `.lpc`（2026-10-21，KB 03 §4.2 第 9 项）

存档里写着 `"/d/city/npc/wei.c"` 这样的文件名；extract 时源文件已经全部改成 `.lpc`，而驱动对带扩展名的路径只认字面，`new()` / `load_object()` / `move()` 都找不到它，调用方多半把失败当成「没有这个东西」悄悄跳过。本库 1 个存档共 1 处按 `scripts/lpc_fix_save_dotc.py` 改成 `.lpc`（只改 `.lpc` 存在而 `.c` 不存在的字符串；玩家存档、备份、留言板、巫师目录和文件索引缓存不动）。改动：`/d/green/k.o`（1 处）（共 1 个存档）。

## `socket`：`dump_socket_status()` 在本库没有（2026-10-21，KB 06 §7.291）

管理员扫描里 `socket` 指令（`/cmds/bos/socket.lpc`）编译不了：`write(dump_socket_status());` 用的是 MudOS 有、本驱动没有的 efun。2026-10-20 的补丁只按名字找了巫师目录里的同名指令，这一条在 `cmds/bos`、`cmds/hufa`、`cmds/island`、`cmds/ser` 这类目录里；用 `scripts/lpc_add_sefun.py dump_socket_status` 在 `/adm/obj/simul_efun.lpc` 末尾补了一个由 `socket_status()` 构造表格的 simul_efun（没有 sockets 包的构建，比如 WASM，只打印表头）。指令 HEAD 编译失败，现在通过。

## 睡袋：`/cmds/adm/bag` 本库没有，使用者被留在聋哑状态（2026-10-21，KB 06 §7.344）

`clone/misc/sleepbag.lpc`、`sleepbag2.lpc` 的 `do_sleep()` 在设好 `block_msg/all`、`no_get` 和房间的 `sleeping_person` 之后调用 `"/cmds/adm/bag"->main(me, "<休息中>")`。这条巫师指令只有 hc、tianxiawuxue 带着，本库没有：`call_other() couldn't find object '/cmds/adm/bag'`，玩家之后什么消息也收不到（`look` 一片空白），十秒后的 `wakeup` call_out 没有排上，房间一直 `no_fight`。城里的小贩 `xiaofan` 卖这个睡袋，没有人在扫描里买过它。`bag` 的全部内容就是 `me->disable_player(msg)`（`feature/command.lpc` 里的 `nomask void disable_player(string type)`，没有权限检查），两个文件都改成直接 `me->disable_player("<休息中>");`。chidi 上实测：`sleep` 之后十秒 "你一觉醒来，只觉精力充沛"，`look` 正常（HEAD 上玩家被留在空白屏里，`log/debug.log` 有 trace）。改动：`/clone/misc/sleepbag.lpc`、`/clone/misc/sleepbag2.lpc`。

## `feature/damage.lpc`：巫师口渴时调用 `/cmds/imm/full`（2026-10-21，KB 06 §7.344）

饥饿那一行用 `"/cmds/adm/full"->main(me)`，口渴那一行写成 `"/cmds/imm/full"`（本库只有 `cmds/adm/full` 和 `cmds/imm_bck/full`）：一个醒着的巫师水喝完时，心跳里抛 `couldn't find object`。改成 `/cmds/adm/full`。

## `mapp`：全局变量不能写 `varargs`（2026-10-21，KB 04 §6.28）

`varargs mixed m;` 和 `varargs string *rfile;` 是 `mapp` 指令的两个全局变量，本驱动只允许函数用 `varargs`（`Illegal to declare varargs variable.`），指令编译不了。去掉两处 `varargs`。

## 香烟 `smoke.lpc`：`do_smoking()` 读没赋值的 `me`（2026-10-21，KB 06 §7.348）

`smoke` 指令的第一句是 `jing = me->query("jing")`，`me` 声明了没赋值，每次抽烟都抛 `Bad argument 1 to call_other()`。补 `me = this_player();`（后面的 `this_player()` 调用不变）。改动：`/d/emei/user-room/melodies/smoke.lpc`。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 70 条注册（58 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/clone/wx/hecheng/item/boots.lpc`（`do_rename`）、`/clone/wx/hecheng/item/finger.lpc`（`do_rename`）、`/clone/wx/hecheng/item/hands.lpc`（`do_rename`）、`/clone/wx/hecheng/item/head.lpc`（`do_rename`）、`/clone/wx/hecheng/item/neck.lpc`（`do_rename`）、`/clone/wx/hecheng/item/pifeng.lpc`（`do_rename`）、`/clone/wx/hecheng/item/waist.lpc`（`do_rename`）、`/d/banghui/npc/nicai.lpc`（`create_banghui`、`delate_banghui`）、`/d/city/21_room.lpc`（`do_climb`、`do_jump`）、`/d/city/chatroom2.lpc`（`do_jump`） 等共 58 个文件。最多的函数名：`do_send` 15 处、`do_rename` 7 处、`do_jump` 7 处、`do_decide` 7 处、`do_climb` 6 处。

## 对象路径里的 `..`：`new(__DIR__ "../obj/x")` 报 `Read access denied`（2026-10-22，KB 06 §7.351）

`__DIR__` 是当前文件所在目录（带结尾斜杠），`__DIR__ "../obj/x"` 就是 `/d/zhiye/npc/../obj/x`；驱动的 `legal_path()` 不接受带 `..` 的路径，`new()` / `load_object()` 直接抛 `*Read access denied.`（实测，`find_object()` 对它答 0）。走库自己的 `carry_object()` / 房间 `objects` 表的路径，库的基类会先规范化，能用；直接把路径交给 `new()` / `clone_object()` / `load_object()` / `move()` 的不行，调用到那一步才报错。改成规范化后的绝对路径（`scripts/lpc_fix_dotdot_dir.py --direct`）：`/d/wudang/npc/xiaocui.lpc`（`__DIR__ "../obj/nuerxiang"` → `"/d/wudang/obj/nuerxiang"`）。

## 缺失物品的 `new()` / `carry_object()` 调用链加了保护（2026-10-22，KB 06 §7.73 补充）

`new(路径)->move(...);` / `carry_object(宏("x"))->wear();` 这类语句，路径指向的文件在这个压缩包里没有：`new()` 返回 0，`->move()` 在 0 上报 `Bad argument 1 to EFUN call_other()`。在 `create()` 里这个对象永远加载不了，在 `reset()` 里第一个缺失物品之后的刷新每次 reset 都被跳过。2 个文件里 4 处（`new`）改成 `{ object new_ob = new(路径); if (new_ob) new_ob->move(...); }`（`scripts/lpc_guard_carry_object.py --new`：路径按这个文件自己看到的宏解析，宏名冲突、虚拟对象路径一律跳过）。 对这 2 个改动文件做加载检查（HEAD 与工作区对比）：HEAD 能加载 2 个，现在 2 个（新增可加载 0 个，回归 0 个）。

## 调用了、但这个库自己的守护进程里没有的函数（2026-10-22，KB 06 §7.354）

`MACRO->函数()` 调用的函数在这个库的守护进程里不存在：`call_other()` 对不存在的函数不报错、只返回 0，所以这些功能（时间显示、昼夜事件、名字检查、价格文字……）一直没起作用。同一血统另一个库的同名守护进程里有这些函数，原文照抄到本库守护进程末尾（`scripts/lpc_port_function.py`；调用处传的参数个数、函数体用到的函数 / 全局变量 / 宏 / 字符串键都在本库里有，已核对；守护进程在 HEAD 和工作区都能加载，每个函数用固定参数各调用一次：HEAD 返回 0，现在返回正常的值）：`/adm/daemons/natured.lpc` ← aoxiangtianji：`room_event_fun()`（11 处调用）；`/adm/daemons/chinesed.lpc` ← fengyun434：`check_control()`（1 处调用）、`check_length()`（5 处调用）、`check_return()`（1 处调用）、`check_space()`（1 处调用）、`check_chinese()`（1 处调用）。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 还剩 17 个函数没有补（inquiry 9, item_desc 6, chat_msg 1, other 1）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/d/chaoting/bingying/npc/zhiqin_bing.lpc`:`back_home`、`/d/city/npc/hua_girl.lpc`:`ask_me`、`/d/feitian/npc/shiren.lpc`:`away`、`/d/goathill/npc/obj/dead_leech.lpc`:`eat_tonic`、`/d/npc/guojing.lpc`:`ask_job`、`/d/npc/guojing.lpc`:`ask_gonglao`、`/d/npc/guojing.lpc`:`ask_fangqi`、`/d/npc/guojing.lpc`:`ask_jianxi`、`/d/wuguan/lianhuachi.lpc`:`look_CAI`、`/d/wuguan/lianhuachi1.lpc`:`look_CAI` 等另外 7 个。

## 不带前导斜杠的物品路径：缺失物品的 `new()` / `carry_object()` 调用链加了保护（2026-10-22，KB 06 §7.73 补充）

`carry_object("d/city/obj/jiasha")->wear();` 这类路径不带前导斜杠的写法在这个驱动里按根目录解析（`new("d/city/obj/changjian")` 能加载 `/d/city/obj/changjian`），所以和带斜杠的一样：文件不在压缩包里时 `new()` 返回 0，`->wear()` 在 0 上报 `Bad argument 1 to EFUN call_other()`，整个 NPC 加载不了。此前的保护工具把这种写法当作「相对当前目录，没法判断」跳过了。2 个文件里 4 处（`obj/weapon/sixhammer`、`obj/weapon/stick`）改成带保护的块（`scripts/lpc_guard_carry_object.py`）。 对这 2 个改动文件做加载检查（HEAD 与工作区对比）：HEAD 能加载 1 个，现在 2 个（新增可加载 1 个，回归 0 个）。

## `#include` 路径里的一个笔误让黄蓉整个加载不了（2026-10-22，KB 04 §6.1 补充）

`/quest/huang/huang.lpc`（黄蓉）第 4 行 `#include "/quset/huang/huangjobhy.lpc"`：`quset` 是 `quest` 的笔误，文件在 `/quest/huang/huangjobhy.lpc`。`Cannot #include` 之后，定义在那个文件里的 `ask_job` / `ask_gonglao` / `ask_fangqi`（`inquiry` 里的三个函数）全部成了未定义变量，NPC 编译不过。改成 `quest`。证明（`scripts/lpcc_eval.py`，HEAD 与工作区各一个新进程）：HEAD 的 `load_object("/quest/huang/huang")` 编译失败（`Cannot #include /quset/huang/huangjobhy.lpc`、`Undefined variable 'ask_job'` ...），工作区加载成功（黄蓉）。全库 11 处找不到的 `#include`（一次性静态扫描，找同名文件）里只有这一处是笔误；`/d/npc/guojing.lpc` 的 `#include "zzzjob.lpc"` / `"teamjob.lpc"` 找不到，是因为这两个文件在 `/quest/guojob/`（`/quest/guojob/guo.lpc` 是后来的郭靖，房间里对旧版 `/d/npc/guojing` 的引用都被作者注释掉了），没动。

## `log/` 下的日志子目录没有人建：写日志的 `write_file()` / `log_file()` 报错（2026-10-22，KB 06 §7.358）

这个库的代码往 `log/` 的 1 个子目录写日志：`log/doc/register`（`cmds/usr/helpbbs.lpc`）。压缩包、`git clone` 和站点包里都没有这些目录（本地启动没有写过它们，`gen_keep_dirs.py` 没记），`write_file()` 对不存在的目录抛 `*Wrong permissions for opening file /log/dlog/money for append. "No such file or directory"`，调用它的函数在写日志那一行中断，后面的奖励、标志、步骤都没有执行。本库的 `log_file()` 会自己建目录（实测，或读源码：nitan 系的 `assure_file()`），所以这里只记了直接用 `write_file()` / `save_object()` 写的目录。把 `log/doc/register` 记进 `scripts/wasm_keep_dirs.txt`（`scripts/lpc_keep_log_dirs.py`；站点和 pristine 树按它建空目录）。证明（`scripts/lpcc_eval.py`，在 `/adm/daemons` 这类目录下的求值对象里写 `/log/zzdirprobe/...`，新进程）见 KB 06 §7.358 的实测表。

## `(: 函数名 :)` 指针指向本库没有的函数：只含这个指针的行加了注释（2026-10-22，KB 06 §7.355 补充）

`inquiry` / `item_desc` / `chat_msg*` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：用到时（`ask`、`look`、NPC 闲聊）驱动抛 `*Undefined lfun pointer called: 函数名`，这一拍心跳的后半段被跳过。这些函数没有可以补回的来源（别的库同一路径的文件里没有，或者它还要用本库没有的东西），所以 9 个文件里 9 行只含这个指针的行（`"回去": (: back_home :),` `"song": (: ask_me :),` `(: away :),`）加了注释，原文保留并写明原因，这一项当作没有这个话题 / 物品 / 闲聊条目（`scripts/lpc_fix_dangling_lfun.py`；`#include` 的文件在库里缺失的对象、指针不在整行上的写法没动）。 前提（`function_exists()`）和加载检查（HEAD 与工作区对比，本库改动的 `.lpc` 文件）的结果见 KB 06 §7.355：没有一个回归。

## 写死的 `"/路径"->函数()` 指向库里没有的文件：改成现存的同名文件（2026-10-22，KB 06 §7.359）

2 处语句级的 `call_other` 字面量路径，库里没有这个文件（区域改了名 / 大小写不对 / 差一个字母 / 文件挪了地方）：`"/cmds/skill/skills"->skill_level()`（`/quest/quest_jun/look.lpc`）→ `"/cmds/usr/skills"`；`"/d/mj/obj/baihong-jian"->move()`（`/d/mingjiao/npc/yingwang.lpc`）→ `"/d/mingjiao/obj/baihong-jian"`。`call_other()` 对不存在的对象抛 `couldn't find object`，所在函数当场中断。改成库里现存、并且定义了被调用函数的文件（`scripts/lpc_fix_call_path.py`；巫师目录、备份目录、名字不同的兄弟文件都不算候选）。 其中殷天正（白眉鹰王）的 `do_answer()`：玩家念对暗语（`answer 怜我世人，忧患实多；保护教主，同抗外敌`）时把白虹剑 `move` 给玩家，区域目录改名 `mingjiao` 之后这个路径没跟着改，回答暗语只得到 `couldn't find object`，剑永远发不出来。 证明（`scripts/cmd_probe`，新进程）：HEAD `answer ...` 打印 `*call_other() couldn't find object '/d/mj/obj/baihong-jian'`（`yingwang.lpc` 第 92 行），物品栏里没有剑。

## 汉字按字节切片的老写法没有换成按字符：改法名 `"澄" + name[2..3]`、辈分判断 `name[0..1] == "澄"` 等 20 处（2026-10-22，KB 06 §7.360）

原档按字节算字符串区间（一个汉字 2 字节）：`name[2..3]` 是名字的第二个字，`name[0..1] == "澄"` 问名字是不是以「澄」开头。转成 UTF-8 之后，这个驱动的区间和 `strlen()` 都按字符算（`strlen("澄观")` 是 2，`"澄观"[0..1]` 是两个字），老算术原样留着、意思全变：拜入少林 / 武当 / 峨嵋等派的玩家被改成错误的法名（二字名 `张三` 变成一个字的 `澄`，更长的名字取到第三个字）；各派掌门的辈分判断（`name[0..1] == "澄"`）永远不成立。

本库 20 处（15 个文件）：拼名字的赋值 12 处、与汉字常量比较 8 处。例：`name[2..3]` → `name[1..1]`（`/d/emei/npc/miejue.lpc:99`）；`name[0..1]` → `name[0..0]`（`/kungfu/class/shaolin/qing-fa.lpc:100`）；`name[0..1] == "慧"` → `name[0..0] == "慧"`（`/kungfu/class/shaolin/cheng.h:108`）。`scripts/lpc_fix_gbk_slice.py` 把下标按字符重算（社区的 UTF-8 版 `xkx100utf8` 里就是同样的写法，作对照）；没有改的：截断（`name = name[0..7]`，现在最多 8 个字，只是放宽）、ASCII 的区间（`fname[0..3] == "room"`、`ctime(time())[4..19]`）和上下文看不出是汉字的区间。证明（`scripts/lpcc_eval.py`，bixiecanyang；其余各库是同一份文本）：让澄字辈掌门 `attempt_apprentice()` 一个名叫「张三」的访客，HEAD 的法名是 `慧`，改后是 `慧三`；抽样 28 个库的 HEAD / 工作树加载对比 0 退步。工具不幂等（`[0..3]` 折半得 `[0..1]`，又是对齐区间），改过的文件记在 `scripts/gbk_slice_converted.txt`，不要重跑。

## 长度检查按字节写，旁边的提示按汉字写：12 处（2026-10-22，KB 06 §7.362）

老档的 `strlen()` 数字节（一个汉字 2 字节），转成 UTF-8 后它数字符：提示写「必须是 2 到 6 个中文字」的检查还是 `strlen(name) < 4 || strlen(name) > 12`，于是两三个字的房名、帮会名、群名、聊天室名、称号被提示自己说允许的那句话拒绝，上限却是提示的两倍；留言板的标题检查 `i < 4 || i > 24 || i % 2` 还会拒绝所有奇数个字的标题（`post 你好吗`）。本库 12 处（6 个文件）：`if ((strlen(name) < 2) || (strlen(name) > 12)) {`（`/cmds/adm/meskills.lpc:590`）；`if ((strlen(name) < 2) || (strlen(name) > 40)) {`（`/cmds/usr/buildbh.lpc:205`）。`scripts/lpc_fix_strlen_gate.py` 以提示为准：条件里每个 `strlen` 门槛都恰是提示所说数字的两倍才折半，存长度的变量（`i = strlen(arg);`）的门槛和 `|| i % 2` 奇偶项、其后循环的 `i % 2 == 0 &&` 一并处理；提示里有英文 / 字母 / 字节的不动。证明（`scripts/lpcc_eval.py`，bxsj 的留言板，求值对象继承 NPC 并重写 `edit()` 记录调用，`command("post 标题")`）：HEAD 拒绝「你好」和「你好吗」、放行 23 个字的标题；改后接受前两个、拒绝第三个；shenmo 的 `named.lpc invalid_new_name("张三")`：HEAD 回 `名字只能是2-4个中文字。`，改后回 0。抽样 24 + 15 个库的 HEAD / 工作树加载对比 0 退步。

## 按字节写的汉字循环、茶馆猜诗和同盟频道标题（2026-10-23，KB 06 §7.363）

老档按字节做「一个汉字」：`while (i--) if (i % 2 == 0 && !is_chinese(name[i..<0]))` 只检查偶数下标，奇数位上的拉丁字母（`张a`）会过；茶馆猜诗 `mixup()` 用 `strlen(str)/2` 再 `j=j+j`、`str[k..k+1]` 交换两字节；泥潭系 `channeld` 的 `switch (strlen(fname)) case 4/6/8/10` 和 `strlen(family)==4/6` 按字节长度给同盟 / 门派名加空格。本驱动的 `strlen()` 和区间都按字符算。`scripts/lpc_fix_byte_char.py`：去掉奇偶项、把区间改成 `name[i..i]`，按字符重写 `mixup()` 并把 `strlen(first)>=14` 折成 7，频道标题的 case / 门派长度改成字符数（对照 aoxiangtianji）。本库 汉字循环 / `is_chinese` 区间 11 个文件。证明（`scripts/lpcc_eval.py`）：sjplii 的 `check_legal_name` 在 HEAD 接受「张a」、改后拒绝，两边都接受「张三」；xkx100 的 `clubpoem->mixup("离离原上草")` 得到「离离原草上」（真交换汉字）；nitan_san 两字同盟名得到 `【 兄  弟 】`。关键对象加载通过。

## 血条 / 表情标题按字节算显示宽度（2026-10-23，KB 06 §7.365）

老档把汉字当两字节：`bar_string[0..(val * N / max) * 2 - 1]` 把「格数」换成字节下标，半格血条在本驱动（按字符算区间）上会整条画满；巫师表情 `edemote` 的 `repeat_string("─", 13 - (strlen(emotion) / 2))` 也会少减汉字宽度。`scripts/lpc_fix_display_pad.py`：去掉 CJK 血条 / 空白条上的 `* 2`（`jings`/`qis` 赋值和 `blank_string3[0..(23-a)]` 的 23→11 一并改），表情标题去掉 `/ 2`；ASCII 空格的 `none_string` / `empty_string` 仍保留 `* 2`（一格两个空格）。本库 2 处（1 个文件）。证明（`lpcc_eval.py` hhsj）：`tribar_graph(6,9,12)` 在 HEAD 画出整条 12 个■，改后为 6 个■+3 个□；麻将 `strlen(tempB)/2` 是两字符牌码，未改。


## Beyond 出口仍指向 /u/beyond（2026-10-23，KB 06 §7.368）

宁波 / 苏州 / 慕容等区域已进 `/d/ningbo`、`/d/suzhou`、`/d/mr`、`/d/hz`，出口与任务物路径仍写 `/u/beyond/…`。`scripts/lpc_fix_beyond_exits.py` 在目标 `.lpc` 存在时改写（`murong`→`mr`）。本库 1 处。证明：sjplii `xikou` HEAD 西向 `/u/beyond/ningbo/aywsi`，改后 `/d/ningbo/aywsi` 可加载；bxsj `hubian1` 三向均可加载。


## 死巫师出口 gold/dock、sunrise、mei（2026-10-23，KB 06 §7.370）

`/d/wanjiegu/road4` 东向 `/u/g/gold/dock`、峨眉寿星居南向 `/u/xinyue/sunrise_room`、玩家卧室通往 `/u/mei/…` 均无对应房间。`scripts/lpc_fix_drop_dead_u_exits.py` 删除这些出口行，并去掉同方向的 `create_door`（否则 `create_door` 无出口会炸）。本库 1 处。证明：zxty08nxgbb 的 road4 HEAD 有东向，改后没有；mei_room1 可加载。


## 中文名 / 验证码仍按 GBK 取「两字节一字」（2026-10-23，KB 06 §7.373）

`pname = pname[(random(sizeof(pname)) & 0xFFFE)..<1]; pname = pname[0..1];` 在按字符计下标时会取出两个汉字。`scripts/lpc_fix_pname_slice.py` 去掉掩码并把收尾改成 `[0..0]`（`pname`/`pname2`/`sec_name`/`str`/`str1`）。本库 4 处。证明：nt1 生成名长度 2–4；HEAD 常见 3–5。

## example/book 注释折行无法加载（2026-10-27，KB 04 §6.25 Also）

`obj/example/book.lpc` 的 `// name of the skill` 等注释被折行，下一行 `the skill` 成了裸标识符，驱动报 `unexpected L_IDENTIFIER`。用手足 sjsh 完好副本覆盖。证明：HEAD 加载失败；改后加载成功。

## hanbing `random 反引号（2026-10-27，KB 04 §6.25 Also）

`hanbing-mianzhang` / `hanbing-mianzhang2` 在 `random(` 前多了一个反引号，驱动按模板字面量读到 EOF。删掉。证明：HEAD 失败；改后加载。

## 深度功能测试（2026-10-27，§6.25 d/city/sj 去引号残渣）

`d/city/sj` 仍有去引号的 `message_vision`（上次只修了带引号的 `add_action` 副本）；按 jhfy 替换。
