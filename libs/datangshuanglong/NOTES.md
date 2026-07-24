# datangshuanglong — 大唐双龙 (archive #49, 大唐双龙.rar)

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
xiakexinzhuan2(#41), whose config had a leftover "海洋II" MUD_NAME) —
**confirmed this is NOT a duplicate of #71**: nothing else in this archive
references "碧血残阳"/"豪侠晚歌" anywhere (checked `adm/etc/welcome`,
`mudinfo.lpc`, banned-name lists, room content) — it's purely a stale
config field, coincidentally matching a different not-yet-processed
archive's title. Went with the live-banner name ("大唐双龙") for
`config.fluffos`, per instructions, and left a comment in the config
explaining the discrepancy for whoever processes #71 next.

## Lineage check against dtsl(#8) / llmud_datangshuanglong(#18)

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
from dtsl/llmud_datangshuanglong — different `master.c`/`logind.c`
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
2. **`F_UNIQUE` macro gap** (same as dtsl(#8)/llmud_datangshuanglong(#18)):
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
cd libs/datangshuanglong
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
`wuhanzhan`/`shenzhou`/`dongfanggushi2` elsewhere in this project. Fixed
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
per-lib) -- a normal `git add libs/datangshuanglong/` picks them up, no
force-add needed.

Retest: fresh normal registration (id `ceshiqi`, name 秦岭, female)
reached 大唐学院, look correct, quit-retention prompt handled (kept the
account then disconnected). fluffos admin login + `update` verified
above. debug.log clean across all three driver runs this pass (only the
expected boot-time config dump and SIGTERM-on-kill lines). Three driver
instances started and killed by exact PID during this pass; test
character `ceshiqi`'s save files removed afterward (`data/user/c/
ceshiqi.o`, `data/login/c/ceshiqi.o`), fluffos's kept.
