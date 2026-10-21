# dtsl2 — 大唐双龙 (archive #49, 大唐双龙.rar)

Archive: `大唐双龙.rar`. Port: 40043. Status: **done** (boots clean, full
registration flow verified end-to-end including a real Chinese name
reaching the actual game world).

## What this is / naming discrepancy

Mudlib root was `raw/DTSL/` directly (no extra nesting). The archive's
ASCII-art connection banner, `cmds/wiz/mudinfo.lpc`'s system-info text, and
the welcome messages all say **"大唐双龙"/"DaTangShuangLong"/"Datang
ShuangLong Mudlib 1.0.0"** — that's the name actually shown to a
connecting player, and what `config.fluffos`'s `name` field was set to.

**However**, the raw config file (`config.bxcy`)'s own `name` directive
literally says **"碧血残阳 之 豪侠晚歌"** ("Bloody Sunset - Ballad of the
Bold Heroes") — which is the title of archive #71
(碧血残阳之豪侠晚歌.rar), not yet processed as of this writing. This is
almost certainly a leftover/copy-paste artifact from whatever base this
lib's config was forked from (the same class of thing seen on
xkxz2(#41), whose config had a leftover "海洋II" MUD_NAME) —
**confirmed this is NOT a duplicate of #71**: nothing else in this archive
references "碧血残阳"/"豪侠晚歌" anywhere (checked `adm/etc/welcome`,
`mudinfo.lpc`, banned-name lists, room content) — it's purely a stale
config field, coincidentally matching a different not-yet-processed
archive's title. Went with the live-banner name ("大唐双龙") for
`config.fluffos`, per instructions, and left a comment in the config
explaining the discrepancy for whoever processes #71 next.

## Lineage check against dtsl(#8) / dtslmud(#18)

Both already-processed archives share the exact title "大唐双龙传"/
"LLMUD大唐双龙". Per AGENTS.md's repeated lesson that similar titles do NOT
reliably imply shared code, checked directly (raw archive vs raw archive,
not post-fix work copies):

- `adm/simul_efun/chinese.c`: **byte-identical** (md5
  `a619b9268b2025b89020347ae80ba888`) across all three archives.
- `adm/obj/master.c`: **different** — this archive's is 302 lines with a
  simple `valid_write`/bare-`return 1` `valid_read` shape; dtsl's and
  llmud's is a shared, different 461-line master.c (identical to each
  other, md5 `3f1684c304286dca23a4a67afb6d00ab`).
- `adm/daemons/logind.c`: all three differ from each other (897/879/917
  lines) but same overall shape/flow.
- **Strongest evidence of shared content lineage**: the exact same 7-file
  `clone/weapon/*` diamond-inherit cluster (`jin-sjian`, `shizi`,
  `feihuangshi`, `jinhua`, `sjian`, `feidao` redundantly `inherit
  COMBINED_ITEM;` both directly AND via `inherit THROWING;`, plus
  `sm_ding.lpc`'s separate missing-`embed.h` issue) recurs **verbatim** in
  this archive too — see "Fixes applied" below.

**Conclusion**: this is the same underlying "大唐双龙" mudlib family/base
(shared item content, shared `chinese.c`), but a **distinct branch/fork**
from dtsl/dtslmud — different `master.c`/`logind.c`
implementations, different (smaller/simpler) security model, its own
config with the misleading stale name field. Not a duplicate archive;
processed as its own lib per instructions.

## Fixes applied

1. **AGENTS.md §15h**, standard shape (pre-confirmed from raw source
   before conversion): `adm/simul_efun/chinese.lpc`'s `is_chinese()` was
   the two-specific-byte GBK variant (`str[0]`/`str[1]` range checks) —
   rewritten to the standard single-codepoint CJK range check
   (`str[0] >= 0x4e00 && str[0] <= 0x9fff`). `adm/daemons/logind.lpc`'s
   `check_legal_name()` bound halved (`< 4 || > 10` bytes → `< 2 || > 5`
   characters) and the `i%2==0` even-byte-offset gate removed so every
   character position is checked.
2. **`F_UNIQUE` macro gap** (same as dtsl(#8)/dtslmud(#18)):
   referenced via `inherit F_UNIQUE;` by ~91 `clone/` item files but never
   `#define`d in `include/globals.h`, despite `/feature/unique.lpc`
   existing. Added `#define F_UNIQUE "/feature/unique.lpc"`. Fixed ~91
   files' "syntax error, unexpected L_IDENTIFIER" errors in one shot.
3. **`F_BACKUP` macro gap** (same shape, new instance, not previously seen
   in dtsl/llmud): `obj/fabao.lpc` and `obj/jiasha.lpc` `inherit
   F_BACKUP;` with no matching `#define`, despite `/feature/backup.lpc`
   existing. Added `#define F_BACKUP "/feature/backup.lpc"`.
4. **Same 6-file diamond-inherit bug as dtsl/llmud**: `clone/weapon/{jin-
   sjian,shizi,feihuangshi,jinhua,sjian,feidao}.lpc` redundantly `inherit
   COMBINED_ITEM;` both directly and via `inherit THROWING;` (which itself
   already inherits `COMBINED_ITEM`) — this driver's stricter `nomask`
   conflict detection rejects the diamond. Removed the redundant direct
   `inherit COMBINED_ITEM;` line in all 6 (CRLF-safe sed, per the dtsl
   gotcha). `sm_ding.lpc` (7th file in the same cluster) has the same
   unrelated, unfixed problem as in dtsl/llmud: `#include
   "/inherit/item/embed.h"` doesn't exist anywhere in this archive either
   — genuine missing content, left as-is.
5. **Confirmed NOT needed, via source reading of the raw `master.c`
   before conversion** (per task instructions): no §4 lazy-security-daemon
   recursion guard needed — `valid_write` only does a bare
   `find_object(SECURITY_D)` check (no `load_object` call at all), and
   `valid_read` is an unconditional `return 1;`. No §15l destruct-in-
   create() crash pattern — `create()` is a one-line `write()`, no
   `SIMUL_EFUN_OB`/`MASTER_OB` destruct anywhere. `get_root_uid()`/
   `get_bb_uid()` (§7) both present and correct.
6. **`adm/daemons/securityd.lpc`** has a real custom ACL (`trusted_read`/
   `exclude_read`/etc, same general shape as the §15n family) but it is
   **dead code** here — nothing calls `SECURITY_D->valid_read()` anywhere
   in the lib (`master.lpc`'s own `valid_read` never defers to it, unlike
   `valid_write` which does defer to `SECURITY_D->valid_write()`). So
   §15n's mid-connection lazy-compile lockup and §8c's `this_player()`-
   override footgun don't apply here — confirmed by reading, not by
   hitting a bug.
7. `adm/etc/preload`: `/adm/daemons/network/dns_master` was **already**
   commented out in the raw archive — verified no other network/DNS/
   intermud daemon is active in preload (grepped case-insensitively).
8. No local `<header.h>`-next-to-its-user angle-bracket includes found
   (§8d) — checked proactively, none present.

Routine conversion (`convert_lib.sh`, 8249 raw files): encoding
already_utf8=359, converted=7490, lossy=15 (mostly `data/board/*.o` and
`data/emoted*.o` save files with invalid bytes — seed/example data, not
source), skipped_binary=384; `.c`→`.lpc` rename to 6874 files; 1167
literal-`.c"`-reference fixes; 4 angle-bracket `#include <x.c>` fixes; 76
local angle-bracket `#include <x.lpc>` → `"x.lpc"` conversions
(proactive §8d insurance); 103 files `static`→`nosave`. A handful of
`.lpc`/`.h` files (`bbsd.lpc`, `d/job/haishajob/killer{1-6}.lpc`) were
flagged by the post-conversion `file`-classifier straggler check but are
confirmed-clean UTF-8 LPC source — false positives from `file`'s heuristic
on their specific content shape, not actual encoding misses.

## Boot

Booted clean on the first attempt after the fixes above — zero `error:`
lines in the debug log, all `adm/etc/preload` daemons loaded successfully,
`Accepting telnet connections on 0.0.0.0:40043` /
`Initializations complete.` reached in well under 20 seconds. Only
warnings (nosave-on-function, unused locals, no-effect expressions in
`natured.lpc`'s season-flavor-text `switch` — none fatal).

## Interactive test result — full registration flow

Read `logind.lpc`'s actual call chain before testing (not assumed from
another lib). No hidden pre-id prompts (`INFO_CMD`/`cmds/wiz/mudinfo.lpc`
is non-interactive, just prints system stats). Flow shape: banner → system
info → **English id** (3-8 lowercase letters, no "new" keyword — any
unused id works) → **y/n create-confirmation** → **Chinese name** (2-5
characters, NO separate y/n confirmation) → password (5-8 chars) →
confirm password → email → gender (m/f) → stat-point allocation (4
numbers summing to 80, each 10-30) → yes/no confirmation → enters game.

`banned_name` includes the novel's own protagonists (寇仲/Kou Zhong,
徐子陵/Xu Ziling — literally the title characters of "大唐双龙传"), plus
real political figures (江泽民, 邓小平) — avoided all of these.

Verified the **complete** registration path in one continuous
`mudclient.py` connection: id `qinfeng` → confirm `y` → **real Chinese
name `秦风`** → accepted, straight to password prompt → password
`test1234` → confirmed → email `test@test.com` → gender `m` → stats
`20 20 20 20` → confirmed `yes` → **entered the actual game world**
(大唐学院/"Datang Academy" starting room) → issued `look` successfully →
`quit`. This is the strongest possible verification (not just "reached a
prompt" — a real Chinese name was accepted and the character was fully
created and playable).

## lpcc sweep

6874 files. First pass (before `F_UNIQUE`/`F_BACKUP` fixes): 6434 pass /
440 fail (93.6%). Second pass (after both macro fixes): **6506 pass / 368
fail (94.6%)**.

Remaining failure categories, triaged by error-text histogram (not fixed
further, per AGENTS.md §6b/§13 — none of these are on the boot/
registration path, confirmed above):
- **50× `Cannot #include room.lpc`** — `d/job/timejob/job2/room*.lpc`
  (quest-job rooms) each end with `#include "room.lpc"` expecting a local
  companion file that was never shipped anywhere in this archive (checked
  the whole `d/job/` tree — no `room.lpc` exists anywhere under it). Real
  content gap (§13-shaped), not fixed.
- **21× `syntax error, unexpected L_IDENTIFIER`** (down from 107) — the
  remaining instances are two more undefined-macro cases distinct from
  F_UNIQUE/F_BACKUP: `CLUB` (9 files, e.g. `clone/weapon/club.lpc` itself,
  a 铁棍/iron-staff item) and `WEAPON_COMBO` (2 files) are referenced via
  `inherit` but have **no `#define` anywhere AND no obviously-matching
  target file** (unlike F_UNIQUE/F_BACKUP, where the target file existed
  and only the macro was missing) — `include/weapon.h` defines every
  other weapon-type macro (`STICK`, `STAFF`, `SWORD`, etc.) but never
  `CLUB`; closest analog is `STICK`/`"/std/weapon/stick"` but guessing
  that mapping would be fabricating behavior, not restoring a documented
  gap, so left unfixed. `BBS_BOARD` (3 files: `obj/board/xyj_b`,
  `query_bbs`, `menpai_bbs`) has the same shape — every other board in the
  archive uses `BULLETIN_BOARD` instead, `BBS_BOARD` itself has no
  `#define` and no matching class file anywhere.
- **8× `Cannot #include /inherit/item/embed.h`** — the pre-existing,
  unrelated `sm_ding.lpc`-family gap noted above (same as dtsl/llmud).
- **~50× `Undefined variable`** across several distinct names (`RNAME_D`
  8×, `TOPTEN_D` 7×, `JIANGJING` 5×, `BANNED_ID` 5×, `XYJ_SITES` 4×,
  `SAVE_EXTENSION` 4×, `R_JOB` 3×, etc.) and a handful of `Undefined
  function` (`clear_conditions_by_type` 9×, `unew`/`query`/`change_state`/
  `is_wanted`/`dbquery` a few each) — long-tail only-ever-called-never-
  defined globals/functions in content that isn't on the registration
  path (job-system NPCs, ranking/topten boards, banned-id lookups),
  matching the §15b "long tail, not all reachable at once" pattern from a
  different lineage. Not triaged file-by-file given time constraints.
- Remaining smaller categories (`Cannot #include uid.h`/`config.h`,
  `Bad assignment`, `Invalid argument types to '+'`, `Redeclaration of
  function 'die'`, `Invalid simulated efunction override`) are single-
  digit counts each, consistent with the usual scattered pre-existing
  typo/copy-paste tail seen across every lib in this project — not
  individually triaged.

Memory stayed healthy throughout both sweeps (free memory fluctuated
2-9GB available on this 23GB host, shared with another concurrent lpcc
run from a different session at the time — never approached the OOM-risk
threshold documented in AGENTS.md §6b).

## How to run

```
cd libs/dtsl2
~/src/fluffos/build-debug/src/driver config.fluffos
python3 ../../scripts/mudclient.py 127.0.0.1 40043 --timeout 20 --idle 1.5 \
  --send "" --send "<newid>" --send "y" --send "<中文名字>" \
  --send "<password>" --send "<password>" --send "you@example.com" \
  --send "m" --send "20 20 20 20" --send "yes" --send "look" --send "quit"
```

## Retroactive fix (QA re-verification pass, 2026-07-23): log_error() compile-warning spam (AGENTS.md §15af)

Found during a routine re-verification pass (full registration + post-login
`look`/`score`/`quit` test): `adm/obj/master.lpc`'s `log_error()` showed the
raw compiler diagnostic text to ANY connected player — no wizard check at
all — for every compile diagnostic funneled through `APPLY_LOG_ERROR`,
including harmless "Unused local variable"/"Unknown #pragma" warnings
triggered by the first lazy compile of an ordinary room/command file the
player merely walked into or typed (`/cmds/std/look.lpc`, `/adm/daemons/
examined.lpc`, `/adm/daemons/combatd.lpc`, `/cmds/std/score.lpc`, etc). In
the pre-fix test transcript this showed up as several screens of raw
compiler internals interleaved with normal game text right after
registration — exactly the same bug already found and fixed on `dtsl`(#8)
(this lib's own `chinese.c`-sharing but otherwise-distinct sibling) and
`wuhanzhan`/`shenzhou`/`dfgs2` elsewhere in this project. Fixed
identically: only show the full diagnostic to a wizard; only alarm an
ordinary player with the generic `default error message` for a genuine
compile **error** (gated on absence of `"warning:"` in the message). Also
needed `#include "/include/runtime_config.h"` added to the top of
`master.lpc` (for the `__DEFAULT_ERROR_MESSAGE__` macro) since the file had
no includes before. Re-verified with a fresh registration (real name
`秦海`) followed by `look`/`score` — zero spam, clean output, matching what
a real player should see.

Also observed (not fixed, off the critical path): one background-daemon
`*Read access denied.` runtime error appeared once during this test,
rooted in a job-system NPC (`/d/gaoli/npc/xiake`, spawned by `/adm/daemons/
jobmond.lpc`'s periodic job-posting logic) trying to `new()` a carried item
that hits an ACL denial somewhere in its own chain. This fires from the
job/quest daemon's own independent heartbeat, unrelated to the player's
registration/look/score actions being tested, and matches this project's
established "content gap in non-critical-path daemon content" pattern
(AGENTS.md §13) rather than a registration-blocking defect — not chased
further given time constraints.

## Re-verification pass (2026-07-23): driver rebuild + LPC formatter + WASM build

- **Formatter**: ran `format-corpus.mjs` over all of `work/` (6,874
  files, 6,720 written/reformatted, 30 already-clean, 124 refused with
  an error — expected on legacy code, not chased individually).
- **Native retest against rebuilt driver** (`build-debug/src/driver`,
  rebuilt from latest upstream master): clean boot, zero fatal errors in
  `debug.log`. Full registration re-verified end-to-end on the
  now-reformatted source with a fresh real Chinese name (`秦欢`, ID
  `qinhuan`, following this lib's own ID→confirm→Chinese name→password
  (5-8 chars)→email→gender→4-stat-point-allocation flow) reaching the
  actual game world (大唐学院 starting room); `look`/`score`/`quit` all
  produced correct output (full 个人档案 stat card rendered correctly,
  new-account save-eligibility prompt handled correctly by declining
  with `n`), zero real errors in `debug.log`. No regressions from the
  reformat or the fresh driver build.
- **WASM build**: preload completes with only the expected non-fatal
  `sockets`-package gap (`adm/daemons/ftpd.lpc`/`include/net/
  ftpdsupp.h`'s `socket_create`/`socket_close`/`socket_address` →
  `Undefined function`, caught non-fatally, `Initializations complete.`
  still printed). Unlike several sibling libs, this lib's login path
  does **not** gate on `query_ip_number()`'s format, so a full
  registration proceeded all the way through under WASM too: ID
  `qinlei` → Chinese name `秦雷` → password → email → gender → stat
  allocation → reached the actual game world (大唐学院 starting room),
  `look` produced correct room output, and `quit` correctly surfaced
  this lib's own new-account save-confirmation prompt. **This lib is
  confirmed fully playable under WASM**, not just "boots."

## WASM-enablement pass (2026-07 standard: loopback-allow, admin seed)

Gates patched (fail-closed: only an exact `127.0.0.1`/`localhost`/
`127.`-prefix match bypasses; a malformed/non-string address falls
through to the original regexp-scan logic unchanged):

- `adm/daemons/band.lpc` `is_banned()` (~line 39): loopback bypasses the
  ban-site regexp scan. Called from `adm/daemons/logind.lpc`'s
  `encoding()` (~line 100) with `query_ip_name(ob)` (this lineage checks
  the resolved name, not the raw dotted-quad, so the guard matches
  `"localhost"` as well as `"127.0.0.1"`/`"127."`).
- No live `uptime()` startup-grace gate found in this lineage's login
  path.
- No live per-IP anti-flood/multi-login throttle: `get_id()`'s
  `ip_cnt>8` "8 IDs per IP" cap (~line 237) is already entirely commented
  out (dead code) in the raw archive -- nothing to patch.
- `adm/daemons/sited.lpc`'s `is_valid(id, ip)` has a real dangling-
  else bug (a bare `if (ip==loopback) if (wiz_level) return 1; else
  return 0;` followed by an unconditional `return 1;`, so non-loopback
  IPs always pass and the `valid_login` whitelist mapping is
  unreachable) -- **but this function is dead code**, never called
  except from an unrelated voting command (`cmds/std/toupiao.lpc`), so
  it does not gate logins at all. Left unpatched/undocumented-further
  since it isn't on any login path; noted here so a future pass doesn't
  waste time chasing a "gate" that never fires.

Admin account: id `fluffos` / `Mud@2026` / 浮浮, registered through the
normal flow (id -> confirm y -> Chinese name 浮浮 -> password -> confirm
-> email skipped -> gender m -> stat allocation `20 20 20 20` -> confirm
yes), then granted `(admin)` via `adm/etc/wizlist` (`fluffos (admin)`
line added, `hpdxxd`'s existing entry kept) and driver restarted.
Verified: re-login shows "目前权限：(admin)", `update /d/newbie/door`
succeeded ("重新编译 /d/newbie/door.lpc：成功！"). Save files
(`data/user/f/fluffos.o`, `data/login/f/fluffos.o`) are plain untracked
paths, NOT covered by any `.gitignore` pattern (checked repo-wide and
per-lib) -- a normal `git add libs/dtsl2/` picks them up, no
force-add needed.

Retest: fresh normal registration (id `ceshiqi`, name 秦岭, female)
reached 大唐学院, look correct, quit-retention prompt handled (kept the
account then disconnected). fluffos admin login + `update` verified
above. debug.log clean across all three driver runs this pass (only the
expected boot-time config dump and SIGTERM-on-kill lines). Three driver
instances started and killed by exact PID during this pass; test
character `ceshiqi`'s save files removed afterward (`data/user/c/
ceshiqi.o`, `data/login/c/ceshiqi.o`), fluffos's kept.

## 深度功能测试 / Deep functional test (round two, AGENTS.md §10.7, 2026-07-25)

Full hands-on playthrough per the §10.7 checklist. Read `doc/help/newbie`
first (generic ES2-heritage newbie-guide text — establishes `fight` as the
lib's point-and-stop safe-sparring command, `bai`/`xue`/`skills` as the
sect-join/skill-learn verbs). Native driver
(`~/src/fluffos/build-debug/src/driver config.fluffos`, cwd
`libs/dtsl2/`), `scripts/mudclient.py`, one continuous session
per leg, real Chinese names throughout (陈慕白/id `chenmu`, 秦学才/`xuecai`,
秦一飞/`chenyi`, 秦韬/`qintao`, 秦直/`qinzhi`, 王启/`wangqi`, 郝竹/`haozhu`,
plus wizard `fluffos`/`Mud@2026` — all throwaway test accounts' save data
removed afterward except `fluffos`). Full flow verified repeatedly: id →
confirm → Chinese name → password → confirm → email → gender → 4-stat
allocation → confirm → lands in 大唐学院 (走廊) → `look`/`score`/`i` all
correct. Explored the 石龙武馆 (Stone Dragon Martial Hall) hub reachable
via `down` from the academy — walkway/正厅/北廊/账房(bank)/兵器铺(weapon
shop)/练功房 rooms, plus the hub's direct sect-gate exits (阴癸派, 净念禅院,
花间, 慈航静斋, 突厥, 东溟派, 弈剑派, 宋家堡). Withdrew bank funds
(`withdraw <n> coin`), attempted a weapon purchase (`buy <item> from
<vendor>`, correctly rejected for insufficient funds — cheapest stock item
is 80 coins, a fresh character's opening deposit is only 10), and
exercised the organic NPC-teacher skill-learning path (`bai`/`xue`/`cha`
against 石龙武馆's 武馆教头) extensively — this is where both bugs below
were found. Sect-join (`bai <family-NPC>`) confirmed correct via code
review (`d/yinkui/npc/dizi2.lpc`'s `create_family("阴癸派", 7, "弟子")`
gives a real target, matching `feature/apprentice.lpc`'s flow) and one
live negative-case check (`bai jiao` against the family-less 武馆教头
correctly refuses: "既不属於任何门派，也没有开山立派，不能拜师。") — the
positive case was NOT completed live (repeated reconnect-position
navigation errors ate the time budget; noted here rather than silently
skipped). The lib's only reachable "safe spar" for a genuine newbie is
`fight` itself (per newbie help); every NPC actually reachable from the
starting hub (教头/shifu, 弟子/dizi, 弟子/shoumen_dizi,
教头/liangongfang's jiaotou) has `accept_fight()` hardcoded to `return 0`,
and the lib's real stat-mirrored training-dummy mechanic
(`std/char/obj/mukuai.lpc`'s `pinzhuang` → `std/char/fighter.lpc`'s
`set_status()`, confirmed via code to genuinely scale down to the
attacker's own stats) is not stocked anywhere reachable from this hub —
newbies must first grind `combat_exp` up via the outside world (or the
一次性 li-guan gift, capped at 6000) before the hub's own mirrored `qiecuo`
sparring (`d/slwg/get_skill.lpc`, gated `10000 <= combat_exp < 20000`)
opens up. Documented as an observation, not fixed — plausibly intentional
newbie-zone pacing, not a defect.

### Bug 1 (fixed): `learn`/`xue` charges tuition even when the requested skill is unteachable — new class, AGENTS.md §7.33-shaped

Found live: a fresh character with money in hand, asking a teacher to
`xue <teacher> <skill they don't teach>` (e.g. shifu doesn't teach
`unarmed`), got the expected "这项技能你恐怕必须找别人学了。" rejection —
but the attempt still silently deducted 3 coins of tuition
(`recognize_apprentice()`'s side effect, `MONEY_D->player_pay()`), which
had already run and succeeded BEFORE the code ever checked whether the
requested skill exists in the teacher's roster. Same root shape as
AGENTS.md's own `zhongjidiyu` §7.33 entry ("persisting a state change
before validating that the underlying action actually succeeded"),
generalized from "writing a permanent field" to "spending real player
currency" — every one of `master_skill`/`prevent_learn`/`my_skill >=
master_skill`/skill-cap/`valid_learn`/`gin`/`potential` can independently
reject the attempt for reasons that have nothing to do with payment, and
ALL of them ran only AFTER the money was already gone.

**File actually live for ordinary players is `cmds/usr/learn.lpc`, NOT
`cmds/std/learn.lpc`** — this itself is worth recording: `adm/daemons/
cmd_d.lpc`'s `find_command()` walks a player's command path
(`PLR_PATH = ({"/cmds/std/", "/cmds/usr/"})`) via `while (i--)` starting
from `sizeof(path)`, which checks the LAST-listed directory FIRST — so
`/cmds/usr/` shadows `/cmds/std/` for any verb defined in both (this
matches several other genuinely-diverged `std`/`usr` pairs in this lib —
`ansuan`/`cemote`/`maphere`/`suicide`/`top` — so it's very likely an
intentional "usr overrides std" customization layer, not itself a bug;
just a fact worth knowing before patching ANY `cmds/std/*` file in this
lib without first checking for a same-named `cmds/usr/` shadow). My first
attempt patched only `cmds/std/learn.lpc` and had zero live effect until
this was discovered and the identical fix applied to the actually-live
`cmds/usr/learn.lpc`. `cmds/std/learn0.lpc` and `cmds/std/learn1.lpc` are
separate, genuinely-unreachable byte-identical/near-identical backup
files (no verb named `learn0`/`learn1` is ever looked up) carrying the
same original ordering bug — left untouched as dead code, matching
project convention.

**Fix** (applied identically to both `cmds/std/learn.lpc` and the
actually-live `cmds/usr/learn.lpc`): moved the `is_apprentice_of`/
`recognize_apprentice` payment gate from immediately after the
`living(ob)` check down to immediately before the final `write("你向...
请教...")` success line — i.e., after every free/no-side-effect
validation (`master_skill`, `prevent_learn`, skill-level/cap checks,
`valid_learn`, `gin`/`potential`). Verified live, before/after: a fresh
character with 10 coins, asking for an unteachable skill, now keeps all
10 coins and gets the identical rejection message; the same character
asking for a real-but-currently-fruitless skill (`sword`, which the
teacher does teach but the "lack of combat experience" content gate still
blocks progress on) is correctly charged exactly once (10 → 7).

### Bug 2 (fixed): `enable_player()` double-registers `command_hook`, silently re-running every FAILED command's side effects — exact match, AGENTS.md §7.28

Found live while investigating Bug 1: the SAME `xue jiao unarmed` attempt
(before this fix) deducted 6 coins, not 3 — i.e., `recognize_apprentice`'s
payment ran TWICE for one typed command. Root cause is byte-for-byte the
scenario already described in AGENTS.md §7.28: `adm/daemons/logind.lpc`'s
login-success flow calls `user->enable_player()` directly (~line 570),
then a few lines later calls `user->setup()`, whose own body
(`std/char.lpc`) ALSO calls `enable_player()` internally — two calls to
`feature/command.lpc`'s `enable_player()` in the same login, each doing a
bare `add_action("command_hook", "", 1)` with no idempotency guard, so two
identical `command_hook` sentences get stacked on every login. Invisible
for any command that succeeds (the driver stops at the first sentence
that returns nonzero) but every FAILING command re-ran its entire body a
second time via the second stacked sentence — confirmed live pre-fix with
a plain `look xyz` (nonexistent item) printing "你要看什么？" TWICE, and
with the `xue`-on-unteachable-skill case above silently double-charging.
`cmds/std/sleep.lpc` legitimately calls `me->enable_player()` again while
already `living()` (wake-up path), so the `living()`-gated guard §7.28
warns against is correctly avoided here too.

**Fix**: `feature/command.lpc`'s `enable_player()` now does
`remove_action("command_hook", ""); add_action("command_hook", "", 1);` —
guarantees exactly one sentence regardless of call count/order. Verified
live: `look xyz` now prints its failure message exactly once, and the
`xue`-on-unteachable-skill case (combined with the Bug 1 fix) now costs
nothing at all, as it should.

### Bug 3 (found, code-reviewed, NOT fixed — same class as AGENTS.md §7.36, live timing impractical)

`feature/clean_up.lpc` (inherited by every room via `std/room.lpc`'s
`inherit F_CLEAN_UP;`) is the exact §7.36 shape: its occupancy check for
whether a childless room may `destruct()` itself is `interactive(inv[i])`
alone, with no `userp(inv[i])` fallback — a net-dead player (real save
state, `userp()` true, `interactive()` false since the socket is gone) is
invisible to this check, so a room holding nothing but a net-dead player
looks "empty" and can be destructed out from under them by the driver's
own idle-object sweep, exactly as documented for `xiaoyuxiyou`. **Not
live-reproduced**: this lib's `config.fluffos` sets `time to clean up :
50000` (~13.9 hours of the object going unreferenced), and the driver's
own sweep only runs once per 5 real minutes even after that — reproducing
it live is outside any practical session budget, unlike `xiaoyuxiyou`'s
apparently-shorter effective window. Left unfixed pending a decision on
whether to patch proactively by code-shape match alone (this pass's time
was spent confirming the two live-reproduced bugs above and did not
budget for a speculative fix + full re-verification of a third). Grep
`interactive(inv\[i\])` in `feature/clean_up.lpc` for the exact spot; the
§7.36 fix pattern (`|| userp(inv[i])`) applies unchanged. Also worth
checking `obj/user.lpc`'s `user_dump()`'s `tell_room(environment(), ...)`
call (~line 182) for the same defense-in-depth `objectp()` guard §7.36
recommends, since this lib's net-dead handling shape (no void-park, stays
in the current room, `command("quit")` after `NET_DEAD_TIMEOUT`=900s) is
structurally similar enough that a room destructed out from under a
net-dead player would hit the same corrupted-`environment()` crash path.

### Investigated and resolved as NOT a bug: room re-displays a second time immediately after `quit`

Every `quit` (and every dropped item during the new-account "abandon
this account" flow) is followed by a second, apparently-duplicate,
full room re-render in a raw-telnet transcript. Traced this down via a
byte-exact reproduction (`fluffos`/admin quitting produces it once;
answering `n` to a fresh account's retention prompt, which drops each
carried item one at a time, produces one extra room re-render PER
dropped item, each one immediately preceded by matching `lbadd`/`lbrem`/
`lbclear` control tags). Those tags are a structured list-box protocol
this lib maintains for a custom GUI client (the `tomud`-flagged path
already visible in `logind.lpc`'s `reconnect()`); a plain-text telnet
client just sees the plain-text fallback of each protocol update, which
happens to be a full room re-render. This is cosmetic noise for
`mudclient.py`/any raw telnet client, not a functional defect — confirmed
`debug.log` stayed byte-for-byte unchanged (zero new lines) across every
occurrence. Recorded here so a future pass doesn't waste time
rediscovering it.

### Net-dead / reconnect testing

`obj/user.lpc`'s `net_dead()` does NOT void-park the player (no §7.20
shape here) — it just stops the heartbeat, clears enemies, and leaves the
body in its current room, scheduling `user_dump(DUMP_NET_DEAD)` at
`NET_DEAD_TIMEOUT` (900s) to force a `command("quit")`. `reconnect()` is a
plain re-link (`set_heart_beat(1); remove_call_out("user_dump"); ...`),
called from `logind.lpc`'s own `reconnect()`, which does NOT call
`enable_player()` again (so Bug 2 above was never actually reachable via
the reconnect path itself — only via the direct-call-plus-`setup()`
double at initial login). Exercised repeatedly and live, across many
accidental and deliberate unclean disconnects this pass (every
non-`quit` session end is an unclean/net-dead disconnect from the
server's point of view) plus one genuine ~5-real-minute wait (well inside
the 900s window): every prompt AND delayed reconnect landed the character
back in the exact room/state left behind, `look`/`score` both correct,
zero `debug.log` signal. The full 900s `user_dump` force-quit firing
itself was NOT waited out live (15 real minutes exceeds a comfortable
single-pass time budget on top of everything else this session covered)
— `user_dump`'s code was read and looks correct (single `tell_room` +
`enable_player()` + `command("quit")`, no §7.12-shaped 2-arg `tell_room`
wrapper bug present), but that specific real-time boundary is unverified
live; flagged explicitly rather than silently presented as tested.

### Not reached this pass

Combat progression to death/respawn: not attempted live — every
`accept_fight()`-enabled NPC reachable from the starting hub is either
gated behind `combat_exp` thresholds the newbie gift doesn't clear
(`qiecuo`, 10000-20000) or outright refuses `fight` (see the safe-spar
discussion above), and reaching further content requires real travel time
this pass's budget did not stretch to. Stated explicitly per §10.7 rather
than silently skipped.

## WASM 修复摘要（迁移自 meta.json 的 group_note）

dtsl/llmud 血统的相关分支。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BBS_BOARD`、`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 55 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（round four/五, AGENTS.md §10.7, 2026-08-20）：真实战斗→死亡→重生全链路验证

本轮专门补上第二轮结尾 "Not reached this pass" 里悬而未决的战斗/死亡/重生
链路。原文档担心新手礼包清不掉 `combat_exp` 门槛（10000-20000）而摸不到
`qiecuo` 陪练，且 `fight` 指令对每个可及 NPC 都 `accept_fight()` 硬编码拒绝
——但那全是 `fight`（安全切磋指令）的限制。重新读 `cmds/std/kill.lpc` 才发现
**真正的杀伤性战斗走 `kill` 指令，其 `valid_kill()`（`cmds/std/valid_kill.h`）
只限制玩家互杀（PK 冷却），对 NPC/野兽完全不设防**——`accept_kill`/
`combat_exp` 门槛根本不适用于 `kill`。用 `fluffos`(admin) 账号 `goto
/d/huashan/shanlu6` 站到一只野鸡(yeji)边上，`kill ji` 验证。

**关键发现（非 bug，纯游戏机制）**：无技能状态下双方 `get_attack()` 恒为 0
——`adm/daemons/combatd.lpc` 的 `get_attack()` 只有在学过名为 `dodge` 的技能
或 `query("dodge")` 轻功列表非空时才会用身法加成，否则 `me_attack` 死锁在
0，导致命中判定 `random(ap+vp) > vp*2/3 || vp*3 < ap` 在 `ap=vp=0` 时恒假
——连续 100+ 回合、2 分钟实时对打双方 0 命中，纯属"完全没学过技能的两个人
在互殴中谁都打不中谁"的真实力学结果，不是 bug（无编译错误/运行时错误/
driver 拒绝，符合 AGENTS.md 判定标准）。用 `arch` 级 `setskill ji dodge
300` 给野鸡技能（对应"用 admin 工具加速进战斗位置，但不绕过战斗本身"的授权
范围）后，`kill ji` 立即在几回合内通过真实伤害/破防判定（`receive_wound`
使 `eff_kee` 转负）杀死了 fluffos——`die()`→`DEATH_ROOM->start_death()`→
移动到 `/d/death/gate`（鬼门关）→ 5 秒后房间自身 `init()`/`run()` 拉入
`/d/death/gateway`（阎罗大殿，`d/death/npc/yanluo.lpc`）。

**顺带验证了 §7.112 缺口修复（`d64ace0`，2026-08-18 提交，此前未在本文档
记录）**：`yanluo.lpc`'s `init()` 现在有 `query_temp("in_death_stage")`
守卫，防止 `enable_commands()`（每次 `reconnect()` 都会广播）叠加出第二条
独立 `death_stage()` call_out 链。本轮实测（含一次断线重连穿过鬼门关房间）
只观察到唯一一条完整的五段对话链（"喂新来的"→"兵荒马乱"→"翻账册"→"阳寿未
尽"→"罢了罢了你走吧"），无重复/错乱叙事，`reincarnate()` 后正确按
`combat_exp<20000` 分支送到 `/d/slwg/zoulang1`（石龙武馆走廊，而非
REVIVE_ROOM）——修复在真实死亡流程下工作正常。

**排查过一个疑似 bug、确认为无害死代码，未改动**：`feature/damage.lpc`
`die()` 结尾 `DEATH_ROOM->start_death(this_object());`——全库搜索确认
`start_death` 从未被定义在任何文件（`/d/death/gate.lpc` 本身没有这个函数，
房间的死亡流程其实完全靠自己的 `init()`/`run()` call_out 完成，和
`start_death` 无关）。担心这是每次玩家死亡都会触发的未定义函数调用，但两次
实测死亡全程 `debug.log` 和玩家会话都**没有任何"Undefined function"报错或
异常输出**——这是 MudOS/FluffOS 系语言的标准行为：通过 `->` 调用一个目标
物件上根本不存在（未声明）的函数会静默返回 0，不会抛出可捕获的运行时错误
（区别于"声明了原型但没有函数体"的情况）。没有编译错误/运行时错误/driver
拒绝信号，按 AGENTS.md 判定标准不算 bug，是纯粹的死代码/冗余调用，未修改。

**结论**：本轮是本库第一次真正打通"真实战斗指令 → 真实伤害判定 → 真实死亡
→ 鬼魂对话 → 真实重生"全链路，全程用 `goto`/`setskill` 等合法 admin 工具
加速就位，但战斗判定、伤害结算、死亡分支、重生房间选择全部走真实游戏逻辑，
未绕过。`debug.log` 除已知的、与本次测试无关的 `/d/gaoli/npc/xiake` 背景
daemon "Read access denied"（此前几轮已记录，job 系统内容缺口，非本次死亡
链路触发）外无新增错误。测试角色为已有的 `fluffos` 管理员账号（复用而非新
建，因死亡本身不需要新角色；确认 `env/immortal` 未设置，纯合法弱身位承受
了真实死亡)。

**标准清单核对**（全部通过，本库属于"已修复完好"一类）：
- §7.90：`config.fluffos` `maximum evaluation cost : 5000000`——正确。
- §7.100：`grep -rn "replace_program(ROOM)" work/` 全部落在注释行
  （`//        replace_program(ROOM);`）或文档文件，无存活实例——延续上次
  扫描修复的结论。
- §7.111：真正被 `config.fluffos` 指向的 master 文件是 `adm/obj/master.lpc`
  （非同名的死代码 `adm/master.lpc`），其 `standard_trace()` 已有
  `objectp(error["object"]) ? file_name(...) : "(driver)"` 空值防护。
- §7.112：见上——`yanluo.lpc` 已在两天前的 corpus 扫描中修复，本轮首次做了
  真实死亡链路的现场复现验证。
- §7.113：`obj/user.lpc` `net_dead()`/`reconnect()` 形状正确
  （`set_heart_beat(0)`/`set_heart_beat(1)` 对称），延续第二轮结论。
- §7.79：本库全文搜索 `addn(`/`addn_temp(` 零命中——不适用（未使用该
  simul_efun）。

测试结束后按精确 PID kill 掉 driver；`fluffos` 存档（`data/user/f/
fluffos.o`、`data/login/f/fluffos.o`）与本轮死亡测试连带触碰的
`data/orgroom/baling.o`（帮会/门派房间状态，战斗/重生流程的正常副作用）
一并 `git add -u` 提交，均为合法游戏状态变化，非测试垃圾。

## §7.100 扫描修复（`ROOM` 基类多余 `replace_program()`）

`#define ROOM "/std/room"`：删除 687 处多余的、独立成行的
`replace_program(ROOM);`（保留 `inherit ROOM;`）；686 处由脚本
自动删除，另 1 处在 `obj/roommaker.lpc` 第 137 行——本库房间建造
工具的"克隆我所在的房间"命令用字符串拼接
`str += "\n\tsetup();\n\treplace_program(ROOM);\n}\n";` 把同一枚
多余调用烤进了每一个新克隆的房间，已同步手动修正为
`str += "\n\tsetup();\n}\n";`（该工具另一套"造一间空房间"heredoc
模板本来就是干净的）。修复后全库仅剩 82 处历史遗留的
`//`-注释掉实例，均确认无害、未改动。已用 `build-debug` 驱动干净
启动验证（0 个新增编译错误，端口 40043 正常监听，`debug.log` 无
新增 "cannot replace"/"cannot bind" 行）；未做完整 §10.7 深度
游玩测试。

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

## 深度功能测试（2026-09-04，round three，shop + 拜师）

新角度：石龙武馆兵器铺购物 + 净念禅院虚尘拜师。2026-07-25 第二轮只做了
钱不够的 `buy` 拒绝和教头负例（「既不属於任何门派…不能拜师」），正例
拜师没走完。2026-08-20 第四轮是野鸡战斗→死亡→阎罗重生，留下管理员
`fluffos` 存档 `ghost 1`（`last_damage_msg` 被野鸡杀害）。本轮端口
40043。第一输入是英文 id（没有 GB 选单）。密码 `Mud@2026`。

### 实测过程

管理员 `fluffos` / `Mud@2026`（权限 `(admin)`）。上一轮死亡留下的鬼魂
状态下，`full` 只回 kee/sen/食物饮水，**不清 ghost**。鬼魂 `living()`
为假，所以 `apprentice xu` 会先打出虚尘源码里那句抢跑的「你成为了净念
禅院的俗家弟子！」，再被 `cmds/std/recruit.lpc` 以「没有办法行拜师之
礼」拒绝，`score` 仍是普通百姓 / 还未拜师学艺。`call me->reincarnate()`
后头衔不再是鬼魂，买东西和拜师才走得通。

`goto /d/slwg/bingqipu`（石龙武馆兵器铺，铁匠 `d/slwg/npc/tiejiang.lpc`，
`F_VENDOR_SALE`）。买法是 `buy <物> from <人>`，不能光 `buy sword`。
`list` 长剑一两银子。`buy sword from tiejiang` 成功（「你向铁匠买下一把
长剑」），银子 99→98。长剑不进 autoload。

`goto /d/chanyuan/wuchang`，虚尘（`d/chanyuan/npc/xuchen.lpc`）。鬼魂那
次失败会把 `pending/apprentice` 留在身上，再 `apprentice xu` 只得到
「你想拜虚尘为师，但是对方还没有答应」，不会重跑 `attempt_apprentice`。
`apprentice cancel` 之后再拜：磕头、「恭喜您成为净念禅院的第八代弟子」。
`score` 职称「净念禅院第八代弟子」、师承虚尘。`cmds/usr/save.lpc` 在 60
秒内再 save 会假报「档案储存完毕」却不写盘；本轮用 `call me->save()`
落盘。杀驱动冷启动再登录：称谓/师傅/一两黄金/九十八两银子都在，长剑不
在。虚尘只收男性、拒已婚、PKS≥5、杀气≥100。学院老师不收徒；阴癸派
`dizi2` 有 `create_family` 但没有 `F_MASTER`/`attempt_apprentice`；朱玉
雁只收女弟子。

### 发现并修复的 PROGRAMMING bug

1. **鬼魂收徒失败后 `pending/apprentice` 不清理**（`cmds/std/recruit.lpc`）：
   `!living(ob)` 分支已经告诉双方「没有办法行拜师之礼」，却既不收徒也
   不 `delete_temp("pending/apprentice")`。玩家还阳后同一目标再
   `apprentice` 会卡在「对方还没有答应」，必须先 `apprentice cancel`。
   该分支补上 `ob->delete_temp("pending/apprentice")`。现场 `update` 后
   用 cancel + 重拜验证通过。

虚尘 `attempt_apprentice()` 在 `command("recruit")` 之前就 `tell_object`
「你成为了净念禅院的俗家弟子」——鬼魂路径下这是假成功提示。recruit
修好以后活人路径会立刻真收徒，这条抢跑提示不再误导，未改 NPC 台词。

## 深度功能测试（§10.7，2026-10-04）— paths named in another case

The archive comes from a case-insensitive host: files are stored as `BAGUA0.lpc`, `longjing.C`, `d/SHAOLIN/`, the code names them in lower
case (`__DIR__ "bagua0"`, `"tea/longjing"`, `"/d/shaolin/..."`), so the rooms, NPCs and items behind them could not be loaded (a `.C` file is
not an `.lpc` file; KB 03 §4.5). `scripts/lpc_case_paths.py --convert --apply dtsl2`: 4 file(s) renamed to lower case (`.C` -> `.lpc`,
`.H` -> `.h`) and 0 path reference(s) in 0 file(s) rewritten to the new spelling; 0 skipped, 0 ambiguous. Load check of the 7 objects that were renamed, edited or name a renamed path (HEAD against the working tree, an object is the same under any spelling of its path): 0 PASS -> 5 PASS, 0 that loaded before fail now, 5 more load.

4 files moved (4 `.C`); mostly under `d/emeishan/npc` (2), `d/hangzhou/npc` (1), `d/luoyang/npc` (1). A rescan with `scripts/lpc_warnings.py dtsl2` is still due: the renamed files are compiled for the first time.

## 深度功能测试（§10.7，2026-10-05）— room base survives a raising NPC

`scripts/lpc_resilient_room.py --apply`: `make_inventory()` of `std/room.lpc` loads each inventory object as `if (catch(ob = new(file)) || !objectp(ob)) return 0;`. `new()` of a file that is not there returns 0 (the room just lacks that NPC), but `new()` of a file whose `create()` raises (a skill file for `set_skill()` this archive never had, a `carry_object()` item that is not there, a header that never shipped) raised inside the room and the room did not load at all. The wrong-case renames of this lib (the section above) make the NPCs behind them reachable for the first time, so a room that holds one with such a content gap would have gone from "NPC missing" to "room missing"; now it loads without that NPC, as it did before. The room base compiles and loads with the change (HEAD against the working tree). KB 03 §4.5.

## 深度功能测试（§10.7，2026-10-05）— tail() simul_efun

`scripts/lpc_add_tail.py --apply`: `cmds/arch/tail.lpc`, `cmds/wiz/tail.lpc` call `tail(file)`, an efun of the MudOS this archive ran on that FluffOS does not have (`Undefined function tail`: the command did not compile). `adm/simul_efun/file.lpc` now defines `void tail(string file)`: the last 10 lines of the file, written to the player. Load check (HEAD against the working tree): 2 of the 2 tail command file(s) failed to load at HEAD, all load now, and the simul_efun file loads. KB 04 §6.2.

## 深度功能测试（§10.7，2026-10-05）— 任务表里的 `.c` 路径与任务守护进程的防护

`cmds/std/look.lpc` 夜间检查的 `!present("fire", this_player())` 前加 `objectp(this_player()) &&`（房间 `reset()` 销毁物品时 `/feature/move.lpc` 的 `remove()` 会调用 `look_room()`，此时没有 this_player()，`present(…, 0)` 报 `Bad argument 2 to present()`）。
验证：改动过的 `cmds/std/look.lpc` 在新进程里加载，HEAD 通过 1 个、工作树通过 1 个（共 1 个），无回退。

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `std/room.lpc`：`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 OK，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-07）— 正午的天气消息和刺杀任务的杀手

- `adm/daemons/natured.lpc` `event_noon()`：按月份选生病消息的 `switch` 里，三、四、六、七、九、十、十二、一这八个月写的是 `case "三": HIG + "…" + NOR; break;`——少了 `msg =`，是什么也不做的表达式。这些月份里如果后面的 `random(2)` 没中，`msg` 仍是 0，户外体弱的玩家每到正午就会触发 `tell_object(ob, 0)` 的执行错误，原作者写的季节描述也从没显示过。补上 `msg =`（与五、八、十一、二月一致）。
- `d/job/cisha/changzhen.lpc`、`fanan.lpc`、`killer.lpc`：战斗招式 `(: "apply_action", "linglong-yuquan", 2, 10 :)`——函数名写成了字符串，本驱动把它当作表达式函数指针，只得到字符串，杀手在战斗中从不出招（KB 04 §6.10）；改成同库其他 NPC 用的 `(: apply_action, ... :)`。

改动的文件在 HEAD 与工作树分别加载（新进程）通过。

## 深度功能测试（§10.7，2026-10-07）— 编译警告整理

先用 `scripts/lpc_twin_port.py adopt dtsl dtsl2` 把 dtsl 警告整理提交（a6a78f6443f）里的改动搬到 260 个修改前与它一致的文件（逐文件核对非 ASCII 文字：没有丢失或改动），剩下的再跑 `scripts/lpc_warnings.py dtsl2 --fix`，共改动 376 个 `.lpc` 和若干 `.h`。HEAD 与工作树分别加载（新进程）：342 -> 342 通过，无回退；改过的头文件的 249 个包含者 208 -> 208 通过。
手工：`adm/daemons/logind.lpc` 删去没用到的 `string ip = query_ip_number(ob);`，以及与 `include/tomud.h` 一样的 `#define TMI(x)` 重复定义（展开结果相同）。

启动时警告 26 -> 0；新进程登录（新人物确认）正常。

## 深度功能测试（§10.7，2026-10-08）— `.lpc` 后缀的定宽切片

`.c` 改名 `.lpc` 时只改了字符串没改切片宽度：`f[<2..] == ".lpc"` 拿两个字符比四个字符，永远不成立（`!=` 永远成立），按后缀筛文件、去后缀的代码因此从不运行或截成 `x.l`（KB 06 §7.238）。`scripts/lpc_lpc_suffix_slice.py --apply` 改了 1 处比较、0 处去后缀（如 `cmds/wiz/clone.lpc`）；改动的文件 HEAD 与工作树分别加载（新进程），无回退。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 0 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 3 个，只在 #if 分支用的声明移进分支 5 个文件；改动 7 个文件，HEAD 与工作树各载入一次无回退（7 objects; HEAD PASS 3, tree PASS 3; regress 0; newly loading 0），这些文件的警告 33 -> 2。

- 2026-10-12：`obj/updateroom/city/fish.lpc` 的刷新表路径是 Windows 写法 `"d\clone\room\fish/..."`（`\r` 是回车，`\c`、`\f` 被丢掉），`"npc"` 也成了 `"/dcloneoomfish/yufu"`；改为 `/d/clone/room/fish/fish_room.lpc` 与 `/d/clone/room/fish/yufu`（两个文件都在）。读这张表的 `std/room.lpc` 代码目前整段注释掉，表格处于闲置状态。
- 2026-10-14：FluffOS 970d9f09 重扫剩 3 条：`channeld.canoe.lpc` 的 `REMOTE_Q`、`logind0.lpc` 的 `TMI` 宏重定义前加 `#undef`（后定义本来就生效）；`adm/daemons/network/services/temp.lpc` 在 BLADE 已有的情况下又 `inherit F_CLEAN_UP`，删去。改动对象新进程各载入一次，无回退。

- 2026-10-14：1 个文件用了颜色宏（`HIW`、`NOR`）却没有 `#include <ansi.h>`（首个错误 `syntax error, unexpected L_STRING`）；开头补上（KB 04 §6.1、§6.3）。新进程比对 HEAD 与工作树：1 个对象，新增载入 0，回退 0。

## 负数伤害当作消耗（2026-10-15，KB 06 §7.241）

`receive_damage("neili", -52)`、`receive_damage("qi", -12)` 之类把 `add()` 的负数写进了 `receive_damage()`：本库 `feature/damage.lpc` 对负数伤害报错（或归零），练功/运功时报 `F_DAMAGE: 伤害值为负值` 或消耗失效。已改为正数伤害，内力/精力类改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py`）：`/d/clone/biwutai/biwutai`、`/d/clone/room/leitai/leitai`。

## 内力/精力当作伤害种类（2026-10-15，KB 06 §7.241 第二类）

本库 `feature/damage.lpc` 的 `receive_damage()` 不接受 `jingli`/`neili`/`force` 等种类，`me->receive_damage("jingli", 30)` 之类在练功、绝招、吸取时报 `F_DAMAGE: 伤害种类错误`。6 处改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py` 第二步）。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

24 个文件（技能、绝招、兵器、书籍、区域 NPC 等）来自侠客行体系（qi/jing/neili），而本库人物是 gin/kee/sen/force：`receive_damage("qi", ...)` 报 `伤害种类错误`，`query("neili")` 永远为 0。按 qi→kee、jing→gin（本库学习/读书指令消耗的就是它）、neili→force、max_neili→max_force、jiali→force_factor 改名（`scripts/lpc_port_es_props.py --any-file`）。


## 内力/上限当作伤害种类（补）（2026-10-15）

`victim->receive_wound("force", n, me)`（兵器吸内力）、`receive_damage("max_qi", random(100))`（走火入魔扣上限）等本库不接受的种类，9 处改为 `add(type, -N)`。

## 治疗/疗伤的属性名（2026-10-15，KB 06 §7.241）

`receive_heal()`/`receive_curing()` 也只接受本库的种类。1 个文件（多为只调用 `receive_heal`/`receive_curing` 的药物、NPC）来自侠客行体系，按 qi→kee、jing→本库学习指令消耗的池、neili→force 改名（`scripts/lpc_port_es_props.py --any-file`）。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

51 个文件、77 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/clone/misc/cloth`、`/u/smokes/junying/obj/blade`、`/d/city/obj/cloth`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 0 个，改后 22 个（22 个原来载入不了），没有退步；其余 29 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## 去掉的预定义宏 `SAVE_EXTENSION`（2026-10-18，KB 04 §6.11）

老版 MudOS 给每个 LPC 对象预先定义了 `SAVE_EXTENSION`（`".o"`）；FluffOS 的 ChangeLog（COMPAT_BUSTER 一条）把它删了，改用 `__SAVE_EXTENSION__`。本库没有自己 `#define` 这个宏，用到它的文件一律 `Undefined variable 'SAVE_EXTENSION'`，整个对象载入不了。改成 `__SAVE_EXTENSION__`（`scripts/lpc_fix_predefined_macro.py`）：`adm/daemons/network/netmail.lpc`、`d/zhiye/obj/old-zhujianlu.lpc`、`obj/token.lpc`。`token` 是帮派领袖信物；`netmail` 是网络邮件守护进程（本库缺 `mailer.h` 等头文件，改后仍载入不了）。改后用 `lpcc` 逐个载入这些对象：2 个通过，1 个还有别的错误（`adm/daemons/network/netmail`：/adm/daemons/network/netmail.lpc:17: error: Cannot #include mailer.h）。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 118 个对象设了本库没有文件的武功（137 个名字，最多的是 `pojun-quan`、`sanhua-zhi`、`taizu-quan`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：30 个里 24 个通过，其余 6 个停在别的错误上（`clone/npc/dzd_man`：*No program in object '/clone/npc/dzd_man'!；`clone/npc/tdh/fangdahong`：*No program in object '/clone/npc/tdh/fangdahong'!……）。（`scripts/lpc_guard_set_skill.py`）

## 通向不存在房间的出口，按对面房间的回头出口改正（2026-10-18，KB 06 §7.257）

房间出口 `"west": __DIR__"xxx"` 指向的文件本库没有，玩家走过去就被卡住（笔误、改过名的房间，或者没带进档案的编号房间）。对面的房间存在、并且它相反方向的出口正好指回这个房间，说明出口原本就是通向它：`/d/cahc/jinshuiqiao` 的 `north`：`wangfu` → `tongyuchi`。改动后每个出口都能解析到本库的文件（`scripts/lpc_fix_dead_exits.py`；目标在运行时本来就能载入的库——虚拟房间——不动）。

## 补回本库没有的基类文件（2026-10-18，KB 04 §6.15）

下面这些基类本库没有，继承它们的对象（房间、NPC、物品）整批载入不了（`inherit XXX;` 的宏没定义，或者 `inherit "/std/…";` 的文件不在）。同系的库里有同名文件，两库有大量逐字节相同的文件（亲缘关系），所以从那边原样拷来，缺的宏补进全局头文件 `include/globals.h`：`/inherit/weapon/club`（宏 `CLUB`）←shujian2008，9 个对象继承它，抽样 8/8 载入；`/inherit/weapon/hook`（宏 `HOOK`）←shujian2008，3 个对象继承它，抽样 3/3 载入；`/inherit/weapon/brush`（宏 `BRUSH`）←shujian2008，2 个对象继承它，抽样 2/2 载入；`/inherit/weapon/weapon_combo`（宏 `WEAPON_COMBO`）←xkxc98sj，2 个对象继承它，抽样 2/2 载入。每个基类补回后单独载入、再抽样载入使用它的对象，基类载不进来或者一个用户也载不进来的就撤掉（本库撤掉了它们，不再补）。（`scripts/lpc_restore_bases.py`）

## 调用了父类没有的函数的对象（2026-10-19，KB 06 §7.259）

`::create();`、`::init();`、`return ::buy_object(who, item);` 这类调用写的是父类里有这个函数的版本；本库的父类没有，旧驱动把它当空操作（返回 0），现在的驱动在编译时就报 `Unable to find the inherited function`，整个对象载入不了。单独成句的调用删掉，`return ::f(...)` 改成 `return 0;`（void 函数里是 `return;`），与旧驱动的行为一致。共 2 处、2 个文件：`::ob_hit()`（2 处）。只改了出错原因全是这一类的文件；还带着别的错误（多半是父类本身没了）的文件没动，等父类补回后再看。（`scripts/lpc_fix_dangling_super.py`）

## simul_efun 丢了 unew()（2026-10-19，KB 06 §7.262）

`adm/simul_efun/object.lpc` 没有 `unew()`（带“独一无二”次数限制的 `new()`：物件的 `unique` 值是允许同时存在的份数），而官府 NPC 和几件武器按 xkx 一系的写法调用 `unew(...)`，于是 `Undefined function unew`，连同它们赋值给 `object` 变量的那一行都报错，整个物件载入不了。从同系的 xkxz2 把这个函数原样补回 `object.lpc` 末尾（`scripts/lpc_transplant_function.py`），受益物件 4 个：`/clone/npc/guanfu/shi-qingshan`、`/clone/weapon/bestfalun`、`/clone/weapon/gold-falun`、`/clone/weapon/sword/jwqin`。

## 全局头文件丢了 15 个宏（2026-10-19，KB 04 §6.16）

`/include/globals.h` 里没有定义 `TOPTEN_D`、`XYJ_SITES`、`BANNED_ID`、`OBSTACLE_D`、`RICH_B`、`EXP_B`、`DAOXING_B`、`PKER_B` 等共 15 个，用到它们的物件（名单里 13 个）编译时报 `Undefined variable`/`Undefined function`，整个物件载入不了（编译器在第一个未定义的名字上停下，后面的错误和警告都看不到）。同系的库在各自的头文件里都有这几行：照其中和本库共有文件最多的那个库，原样补到 `/include/globals.h` 最后一个 `#define` 之后，宏体里出现的路径在本库里都存在。补完后名单里有 12 个载入，其余还差别的东西。（`scripts/lpc_restore_defines.py`）

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 两个斜杠开头的物件路径（2026-10-19，KB 06 §7.276）

2 个文件、2 处物件路径写成 `//…`（如 `carry_object("//clone/cloth/hic_cloth")`）：`/d/gaoli/npc/weishi.lpc`、`/d/gaoli/npc/xiake.lpc`。当年的驱动不介意（路径先被规范化）；新驱动把原样的字符串交给 master 的 `valid_read()`，securityd 按 `//clone` 查目录，NPC 的 euid 没有权限，报 `Read access denied.`，NPC 载入不了。改成一个斜杠。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。改动：`/cmds/adm/log.lpc`（1 处）。

## `member_array('/', str)` 改为 `strsrch(str, "/")`：字符字面量的 member_array 按字节搜索（2026-10-20，KB 06 §7.283）

`member_array('/', str)` 里的 `'/'` 是整数，驱动按 UTF-8 **字节**搜索，返回字节偏移（带第三个参数时起点也是字节）；最新的 FluffOS（923cdbc0）在字符串里有非 ASCII 文字时，对每个调用点警告一次（`Warning: member_array(int, string) searches BYTES`）。而 `str[0..idx-1]` 按字符切，中文字符串会在错误的位置截断。改为 `strsrch(str, "/")`（找不到同样返回 -1，按字符计数；`scripts/lpc_fix_member_array_char.py`，JSON 编码器等少数几处手改）。改动：`/adm/daemons/vrm_server.lpc`（1 处）。

## `call_out_info()` 的每一项只有 3 个元素（2026-10-20，KB 06 §7.287）

驱动返回的是 `({ 物件, 函数, 延迟 })`，不带 call_out 的参数，旧代码读第 4 项 `info[i][3]`（`callouts` 指令、`calloutd`、`cod` 工具）一读就报 `Array index out of bounds`，指令从第一行起什么也打印不出来。改为 `(sizeof(info[i]) > 3 ? info[i][3] : 0)`（`scripts/lpc_fix_callout_info.py`）。改动：`/cmds/arch/callouts.lpc`（1 处）、`/cmds/wiz/callouts.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 16 处）。改动：`/adm/daemons/competed.lpc`（1 处）、`/clone/npc/mj.lpc`（3 处）、`/cmds/std/duanzao.lpc`（8 处）、`/cmds/wiz/dns.lpc`（1 处）、`/obj/mj.lpc`（3 处）。

## `callouts`：`sizeof(info[i]) == 4` 把每一行都挡掉了（2026-10-20，KB 06 §7.287）

驱动的 `call_out_info()` 每项只有 3 个元素，输出行前的守卫 `if (sizeof(info[i]) == 4)` 永远不成立，指令只打印表头。改为 `>= 3`。改动：`/cmds/arch/callouts.lpc`（1 处）、`/cmds/wiz/callouts.lpc`（1 处）。

## `socket` / `dumpsocket` 指令：`dump_socket_status()` 驱动里没有（2026-10-20，KB 06 §7.291）

这些巫师指令 `write(dump_socket_status());`，MudOS 的 efun 在 FluffOS 里不存在，指令编译不过。在模拟 efun 文件里补了 `dump_socket_status()`：用 `socket_status()` 排出同样的表（没有 sockets 包的构建，比如 WASM，只有表头；`scripts/lpc_add_sefun.py dump_socket_status`）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/obj/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## sefun `cat()`：缺文件时 `write(0)` 报错（2026-10-20，KB 06 §7.297）

`void cat(string file) { write(read_file(file)); }`：文件不存在（压缩包没带的欢迎/公告文件，或只有运行中的 mud 才会写的日志）时 `read_file()` 回 0，`write(0)` 在本驱动里报 `Bad argument 1 to receive()`，调用者（登录对话、`cat` 指令）被中断；老驱动什么也不打印。改成 `write(read_file(file) || "");`（`scripts/lpc_fix_cat_unchecked.py`）。改动：`/adm/simul_efun/file.lpc`。

## 访客计数 `howmany_visitor()` 读文件不检查（2026-10-20，KB 06 §7.301）

`howmany_visitor()` 读访客计数文件（`VISITORS` / `COUNTER` / `BBSVISITOR`，只有运行中的 mud 才会写；`.gitignore` 把它排除在仓库之外），新检出的树里没有，`read_file()` 回 0，`sscanf(0, ...)` 报错。这份副本登录时不一定走到它，但调用时同样会出错。在读文件之后加了 `if (!stringp(content)) return 0;`（xkx100、xiakexing100、zzfy 早先的写法，`scripts/lpc_fix_visitor_count.py`）。改动：`/adm/daemons/logind.lpc`、`/adm/daemons/logind0.lpc`、`/feature/logind.lpc`。

## `get_config(__MUD_PORT__)` 经旧版 `runtime_config.h` 得到字符串（2026-10-20，KB 06 §7.302）

本库的 `include/runtime_config.h` 是老 MudOS 的编号（整数设置从 15 起，本驱动从 256 起），`get_config(__MUD_PORT__)` 读到的是另一项设置（字符串），`(int)` 又只是编译期标注，于是 `socket_bind(fd, LOCAL_PORT())` 报 `Bad argument 2 to socket_bind()`，版本守护进程 `port = get_config(__MUD_PORT__) + VERSION_PORT` 是字符串相加。头文件自己的注释写明 `get_config(__MUD_PORT__) == __PORT__`，所以代码里的这个调用（连同外面的 `(int)` / `to_int()`）改成了驱动的预定义 `__PORT__`（`scripts/lpc_fix_mud_port.py`）。改动：`/include/getconfig.h`（1 处）。

## 十大排行榜守护进程缺少 11 个数据路径宏和 6 个榜单名宏（2026-10-20，KB 04 §6.16）

`adm/daemons/toptend.lpc` 用到 `TOPTEN_RICH`、`TOPTEN_PKER`、`TOPTEN_EXP`、`TOPTEN_DAOXING`、`TOPTEN_SHEN1`、`TOPTEN_SHEN2`、`TOPTEN_neili`、`TOPTEN_PER1`、`TOPTEN_PER2`、`TOPTEN_AGE`、`TOPTEN_POTENTIAL`（数据文件路径）和 `SHEN2_B`、`neili_B`、`PER1_B`、`PER2_B`、`AGE_B`、`POTENTIAL_B`（榜单名），`include/globals.h` 只有 `TOPTEN_D` 和五个榜单名：守护进程从来编译不过，`topten` 指令报 `Undefined variable 'neili_B'`。同系的 dtxyzjb 的 `globals.h` 有完整的一组，照抄进来（路径 `/data/topten/<名>.o`）；存档里没有 `data/topten` 目录，已写入 `scripts/wasm_keep_dirs.txt`。加载检查：HEAD 0 通过 / 1 失败，工作树 1 通过。另外两个同扫描的指令没动：`quests`（`#include "/d/kaifeng/npc/colors.h"`，这个库没有 `d/kaifeng` 区域）和 `prompt`（`get_prompt()` 在 `feature/message1.lpc`，而 `F_MESSAGE` 指向的 `message.lpc` 是另一个版本，没有这个函数；dtsl、dtslmud 的 `message.lpc` 有，两种提示符设计不一致，不是一行能改对的）。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库现有的 NPC 文件里没有字面写成空 `chat_msg` 的（扫描只认 `set("chat_msg", ({ }))`）；守卫挡的是运行时才为空的列表和以后新增的 NPC。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/std/char/fighter.lpc`、`/std/char/jobnpc.lpc`、`/std/char/npc.lpc`、`/std/char/npcbak.lpc`（共 4 个文件）。

## 巫师命令不带参数时对 0 调用 efun（2026-10-21，KB 06 §7.336）

巫师（管理员）把命令敲成不带参数时，驱动把 0 传给字符串参数；下面的命令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`，这条指令从来没有用过。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py` 在第一处使用参数的语句前加守卫：文件自带 `int help(object me)` 的，守卫是 `if (!arg) return help(me);`（`help()` 定义在 `main()` 之后的 1 个文件补了原型 `int help(object me);`，否则编译报 `Undefined function help`）；没有 `help()` 的是 `return notify_fail("…\n");`。改动（3 个文件，括号里是接住 0 的 efun）：`/cmds/adm/admove.lpc`（`present`）、`/cmds/adm/baiban.lpc`（`sscanf`）、`/cmds/adm/dumpprog.lpc`（`new`）。加载检查 HEAD 与工作树对照，没有退步。

## `quests`：`/d/kaifeng/npc/colors.h` 档案里没有（2026-10-21，KB 06 §7.269）

玩家指令 `quests`（`cmds/usr/quests.lpc`，与 dtxywzxzb 的同名文件字节相同）`#include "/d/kaifeng/npc/colors.h"`（`color_code` 映射：猪八戒“红”、陈光蕊“绿”……），本库没有 `d/kaifeng`，指令编译不了（`Cannot #include`）。把 dtxywzxzb 带着的这个 351 字节的头文件原样复制到 `d/kaifeng/npc/colors.h`，指令加载通过。

## `prompt`、`examine`：别的血统的指令（2026-10-21）

管理员扫描里 `prompt`（玩家指令）和 `examine`（`cmds/arch`）编译不了：`prompt.lpc` 调用 `get_prompt()`，它在 dtsl 的 `feature/message.lpc` 里，本库的 `message.lpc` 是另一套实现（`prompt()` 按 `time` / `date` / `mud` / `hp` / `path` 这些关键字生成提示符，没有 `get_prompt()`；`message1.lpc` 里有但没有人继承它）；`examine.lpc` 调用的 `process_bar()`、`log_time()` 整个库里都没有。这两条指令是别的库的，补不上，没有动。

## 不带参数的指令对 0 调用 efun：不在 wiz / adm 目录里的指令（2026-10-21，KB 06 §7.336）

指令敲成不带参数时，驱动把 0 传给字符串参数；下面的指令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`。它们在 `cmds/std`、`cmds/usr`、`cmds/bos`、`cmds/app` 这类目录里，上一轮的扫描只看巫师目录。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py --all-dirs` 在第一处使用参数的语句前加守卫：没有 `help()` 的是 `return notify_fail("…\n");`。改动（1 个文件，括号里是接住 0 的 efun）：`/cmds/std/actionavailable.lpc`（`sscanf`）。加载检查 HEAD 与工作树对照，没有退步。
