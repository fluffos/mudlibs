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
