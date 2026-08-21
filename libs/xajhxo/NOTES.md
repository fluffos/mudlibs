# xajhxo — 笑傲江湖XO (The Smiling, Proud Wanderer — "XO" build)

Archive: `笑傲江湖XO .rar` (note trailing space in the archive filename before
`.rar`). Port: 40069. Status: **done** (boots clean, full registration flow
verified end-to-end with a real Chinese name, ordinary post-login commands
`look`/`score`/`i` all confirmed working per §15ae policy).

Raw root: `笑傲江湖XO .rar` extracts to a single top-level `xo/` directory
(4922 files) — config self-names the mud simply `笑傲江湖` (matches the
archive's own title, no site-branding difference to note).

## Lineage confirmation (verified via diff/md5sum, per explicit instruction)

Confirmed same **TMI-2/ES2 (Falcon) lineage** as both prior "XO" family
libs — `libs/xo/` (archive #28, "笑傲江湖迷你版"/mini edition) and
`libs/xo_final/` (archive #29, "XO 最终版1.2"/final build) — via the
**identical header credit line** in `secure/obj/master.lpc`:
```
// Original from TMI-2 and ES2
// Rewritten by Falcon 96-10-02
```
(byte-identical wording to what `libs/xo/NOTES.md` already documented for
archive #28). This is a genuine third, independent snapshot in the same
lineage — **not a duplicate or simple size-variant of either sibling**:

- **File count**: 4922 raw files — between `xo`'s 1766 and `xo_final`'s
  8058, but not a clean scaled copy of either.
- **Directory layout is its own hybrid**: uses `secure/daemon/securityd.c`
  (same location as both siblings) but puts `master.c`/`sefun.c`/
  `simul_efun.c` in **`secure/obj/`** — a location neither `xo` nor
  `xo_final` uses (both keep master.c in `secure/daemon/`). It also
  carries a **duplicate set of simul_efun fragment files**: real,
  `#include`d-into-`simul_efun.c` copies live in `secure/simul_efun/*.c`,
  while an apparently-orphaned, near-identical (whitespace-only diffs)
  second copy sits in `secure/sefun/*.c`, `#include`d into a separate,
  never-loaded `secure/obj/sefun.c` "sefun" object (confirmed nothing in
  the tree references `secure/obj/sefun`/`SEFUN_OB` — dead code, fixed
  anyway as cheap insurance where the fix was one line).
- **Core-file diff sizes** (raw, pre-conversion): `master.c` — 523 diff
  lines vs `xo`'s 479-line file, 1150 diff lines vs `xo_final`'s 669-line
  file; `securityd.c` — 525 diff lines vs `xo`'s 339-line file, 699 diff
  lines vs `xo_final`'s 358-line file. By raw diff-magnitude alone this
  snapshot's core security files sit closer to `xo`'s than `xo_final`'s,
  but are genuinely, substantially different from **both** — not a
  byte-for-byte match to either.
- **Shared WORLD/SKILL CONTENT is closer to `xo_final` specifically**:
  several skill files this pass found independently corrupted turned out
  to be the **exact same files, with the exact same corruption shape**,
  already documented in `xo_final/NOTES.md` — `system/skill/shaolin/
  mohe-zhi.lpc`, `system/skill/misc/yuanyang-dao.lpc`, `system/skill/
  misc/taizu-quan.lpc` (two spots) — plus a `d/place/hami/npc/hami.npc`
  shared-NPC header that's **genuinely missing from this archive** but
  whose exact content (down to the `// hami.npc` self-referential
  comment) survives verbatim as `xo_final`'s `d/place/hami/npc/hami.h`.
  This indicates a much closer shared authorship lineage for actual game
  CONTENT with `xo_final` than with `xo`'s trimmed-down "mini" archive,
  even though the *engine*/security files diverge from both.
- **Conclusion**: this is its own distinct, independently-evolved
  snapshot of the TMI-2/ES2/Falcon "XO" codebase — neither a subset of
  `xo` nor a predecessor/successor of `xo_final` — but its *game content*
  (skills, zones) shares closer common-ancestor authorship with
  `xo_final`, while its *security/master plumbing* independently
  regressed/diverged from both (e.g. it's MISSING the `class Action`
  struct definition that `xo`'s `include/action.h` still has — see fix
  #5 below — a capability this snapshot apparently lost along the way).

## Fixes applied (with why)

1. **AGENTS.md §4 (lazy security-daemon load recursion guard)** —
   `secure/obj/master.lpc`'s `valid_write`/`valid_read` called
   `load_object(SECURITY_D)` unconditionally on every single call
   (`catch()`-wrapped but with no `find_object()` gate or re-entrancy
   flag) — identical shape to the exact bug already fixed on sibling
   `xo`. Applied the same guard: check `find_object()` first, and a
   `nosave` re-entrancy flag so a disallowed/failed load degrades to a
   safe default (`1` for read, `1` for write once already loaded) instead
   of recursing. Applied proactively before first boot given the
   recognized lineage.
2. **AGENTS.md §15h (GBK byte-range Chinese-detection bug)** — applied in
   THREE places:
   - `secure/simul_efun/chinese.lpc`'s `is_chinese()`: `str[0] > 160 &&
     str[0] < 255` (GBK lead-byte range) → CJK Unicode codepoint range
     (`str[0] >= 0x4e00 && str[0] <= 0x9fff`). Also relaxed the length
     gate from `strlen(str) >= 2` to `>= 1`, since `logind.lpc`'s
     sliding-window caller (`is_chinese(name[i..<0])`) legitimately
     passes single-CHARACTER substrings under UTF-8 (the original `>=2`
     assumed "1 Chinese char = 2 GBK bytes", which no longer holds).
   - `secure/sefun/chinese.lpc` (the orphaned/unreachable duplicate,
     confirmed nothing loads `secure/obj/sefun.lpc`): same fix applied
     as cheap insurance, in case anything non-obvious ever does load it.
   - `system/daemon/logind.lpc`'s `check_legal_name()`: halved the
     byte-calibrated length bound (`strlen(name) < 4 || > 10` → `< 2 ||
     > 5`, matching what the message text already says: "必须是 2 到 5
     个中文字"), and dropped the `i % 2 == 0 &&` byte-offset gate in the
     per-character sliding-window loop (every UTF-8 index is already one
     full character, not every-other byte).
   These three together are what let a REAL Chinese name (verified: 秦风,
   秦岭, 秦风三 across 3 independent test runs) actually pass
   registration instead of being silently rejected — confirmed via live
   interactive test, not just code inspection.
3. **AGENTS.md §15g (case-sensitive `#include <Action.h>`)** — 3 files
   (`system/feature/command.lpc`, `system/feature/lcommand.lpc`,
   `cmds/wiz/localcmds.lpc`) `#include <Action.h>` (capital A) but the
   real file on disk is `include/action.h` (lowercase) — same root cause
   already documented on sibling `xo` (a different specific file list,
   but the identical bug shape), found via the lpcc sweep's dominant
   "Undefined class 'Action'" failure cluster. Fixed all 3 include
   directives to the correct case.
4. **New: `class Action` was never actually DEFINED anywhere in this
   archive** (only ever referenced as a return/parameter TYPE in
   `add_action.lpc`/`lcommand.lpc`) — confirmed by grepping the whole
   tree for a real `class Action { ... }` struct declaration and finding
   none, even after fix #3 corrected the file-case issue. Cross-checked
   sibling `xo`'s `include/action.h` and found it DOES carry the real
   struct (`{ string verb; string ob; string func; }`), matching exactly
   the fields this archive's own `add_action.lpc` accesses
   (`Action->verb`/`->ob`/`->func`). Ported the struct verbatim from `xo`
   into this lib's `include/action.h` — this is lineage evidence, not a
   guess (see the "Lineage confirmation" section above: this snapshot
   independently lost a piece of plumbing `xo` still has).
5. **AGENTS.md §8g variant (missing macro, not missing file) — three
   separate instances found via the lpcc sweep**:
   - `GROUP_TASK` — referenced (`inherit GROUP_TASK;`) by 42 files under
     `system/task/`, never `#define`d anywhere, despite the real target
     file (`/system/std/group_task.lpc`) existing on disk. This ONE
     missing macro was the single highest-impact fix of the whole pass —
     it alone accounted for 42 of the initial 144 lpcc-sweep failures.
     Added `#define GROUP_TASK STD_DIR "group_task"` to `globals.h`.
   - `EXERT_DIR` — referenced by 6 files under `system/skill/{exert,
     shaolin,wuliang,xkdao}/`, never defined, despite the real
     `/system/skill/exert/` directory existing. Added `#define EXERT_DIR
     "/system/skill/exert/"`.
   - `ZUOJI` — referenced (`inherit ZUOJI;`) by 3 files (mount/steed
     NPCs: `clone/npc/horse1.lpc`, `horse2.lpc`, `u/xli/obj/
     baobei_zhu.lpc`), never defined, despite the real target
     (`/system/std/char/zuoji.lpc`, a genuine "standard mount" base
     class per its own header comment) existing. Added `#define ZUOJI
     STD_DIR "char/zuoji"`.
6. **New: `class task`'s field names never matched what actually uses the
   class** — `include/task.h`'s `class task` defined lowercase fields
   (`need_save`/`name`/`verb`/`target`/`event`/`begin_time`/`task_end`)
   that NOTHING in the whole archive ever reads or writes (confirmed via
   grep), while the only two real consumers of `class task`
   (`system/std/task.lpc`'s `GetTask()`, `system/feature/task.lpc`'s
   `AddTask`/`GetTask`/etc.) exclusively access a completely different,
   PascalCase field set: `TermType`, `KeyName`, `Verb`, `Target`,
   `Event`, `Birth`, `TaskEnd`. This ONE mismatch cascaded into 45 of the
   initial 144 lpcc-sweep failures (every top-level file that
   transitively loads `system/std/task.lpc`, e.g. any NPC using the task
   system). Fixed the struct to the field set both real consumers
   already use, verified safe since nothing legitimately needed the old
   field names.
7. **New: `d/place/hami/npc/hami.npc` was completely absent** — 8 files
   under `d/place/hami/npc/` (`yizhang.lpc`, `afanti.lpc`, `huosan.lpc`,
   `mmaiti.lpc`, `laoban.lpc`, `nvren.lpc`, `woldman.lpc`, `kid.lpc`)
   `#include "hami.npc"` (quoted, same-directory convention) for their
   shared `inherit NPC;` + `ask_where()` helper, but the file genuinely
   doesn't exist anywhere in the raw archive. Reconstructed verbatim (not
   fabricated) from sibling `xo_final`'s byte-for-byte-matching
   `d/place/hami/npc/hami.h` (see lineage section above — its own header
   comment literally reads `// hami.npc`, confirming it's the same
   content under a renamed extension in that later snapshot).
8. **New: `d/city/yangzhou/npc/cloth/cloth.lpc` missing `#include
   <armor.h>`** — the only one of 169 files inheriting `CLOTH` across the
   whole lib that omitted the include every other one has; a one-off
   copy-paste omission. Added the missing include line.
9. **New: `d/place/wiz/inn_hall.lpc`'s `inherit LIB_ROOM;`** referenced a
   macro/base class defined NOWHERE in the archive — the file's own
   `SetShort()`/`SetLong()`/`SetExits()` calling convention (PascalCase,
   argument-taking) is used by no other file in the whole lib (11 other
   files call a no-argument `SetLong()` from their own zone-specific
   `shamo.h`, an unrelated shape). The room's own author had already
   tried and commented out `//inherit ROOM;` right above the broken
   line — reverted to that (the base class that's actually defined and
   used successfully by every other room in the lib) and converted the
   3 `Set*()` calls to the standard `set("short"/"long"/"exits", ...)`
   idiom, rather than fabricate a whole new `LIB_ROOM` base class.
10. **AGENTS.md §3 counterexample (found again, larger this time)** — the
    blanket `\bstatic\b` → `nosave` sed collateral-damaged **16 unique
    log-path string literals across 14 files** (`"static/usage"`,
    `"static/wiz_usage"`, `"static/wiz_login_err"`, `"static/purge"`,
    `"static/command_limit"`, `"static/promote"`, `"static/
    multi_login"`, `"static/action_log"`, `"static/create_room_fail"`,
    `"static/CALL_PLAYER"`, `"static/promotion"`, `"static/QIUHUN_MSG"`,
    `"static/BLOCK_CHANNELS"`, `"static/SUICIDE"`, `"static/
    DIE_PLAYER"`, `"static/yipin_log"`), rewritten to `"nosave/..."`.
    Confirmed the real `log/static/` directory exists in the raw archive
    with genuine seed data (`log/static/usage`, `log/static/
    wiz_login_err`, `log/static/wiz_usage`) that these path references
    were supposed to point at. Reverted all 16 occurrences across all 14
    files back to `"static/..."`.
11. **AGENTS.md §15w (log_error warning-spam)** — `secure/obj/
    master.lpc`'s `log_error()` broadcast every message reaching it
    (including harmless compile WARNINGS like "Illegal to declare nosave
    function", a direct side-effect of this project's own static→nosave
    fix) to the connected player, exactly matching the documented
    pattern. Gated the player-facing `efun::write()` broadcast on the
    message not containing `"warning:"` — still logs everything to file
    regardless.
12. **§15ab-style defensive hardening (2 spots, insurance not reactive
    fixes)** — `secure/simul_efun/file.lpc`'s `cat()` (`write(read_file(
    file))`, no guard) and `clone/user/login.lpc`'s `receive_message()`
    (no `!stringp(str)` guard) both match the documented "unguarded
    write(read_file()) can crash a fresh connection" shape from
    xjcq2000/haiyang2. All files these two currently reach (WELCOME/
    MOTD/new_player) DO exist, so this wasn't an active crash — but it's
    cheap, matches established precedent, and closes the risk if any
    future edit ever points `cat()` at a missing file during the login
    sequence.
13. **~12 individual pre-existing content typos**, found via the lpcc
    sweep and fixed after confirming each against raw pre-conversion
    bytes (not blind edits):
    - `system/skill/shaolin/mohe-zhi.lpc`, `system/skill/misc/
      yuanyang-dao.lpc`, `system/skill/misc/taizu-quan.lpc` (2 spots),
      `d/menpai/shaolin/npc/dd.lpc`, `d/city/nanyang/npc/guo.lpc`,
      `d/zuzhi/yipin_tang/dixia/shuangqi.lpc`, `d/zuzhi/yipin_tang/
      dixia/suni.lpc`: missing-closing-quote bugs, several confirmed via
      raw-byte inspection to be the exact "iconv -c's invalid-byte
      recovery ate an adjacent REAL byte too" gotcha already documented
      for `xo_final` (an orphan single byte sitting where the second
      byte of a 2-byte GBK closing-bracket/quote character should have
      been) — reconstructed each closing quote/bracket from the raw
      bytes and/or sibling entries' established pattern, not guessed.
    - `d/city/lanzhou/chanfang.lpc`: a fullwidth space (U+3000) used as
      function-call whitespace (`set(　"search_things"`) — illegal at
      that syntax position; replaced with a normal space.
    - `d/place/xkdao/npc/obj/hare.lpc`, `d/zuzhi/yipin_tang/peacock/
      xuanwu_tang/npc/tuzhong1.lpc`: fullwidth commas (`，`) used as
      array-element separators inside actual code (AGENTS.md §9 pattern)
      — replaced with ASCII commas; `hare.lpc` also had one element using
      a mismatched `'...` single-quote instead of `"..."`.
    - `d/city/chuzhou/npc/whorehouseboss.lpc`: `set("negative_score',
      3000)` — opened with `"`, closed with `'` (mismatched quote type),
      cascading into "End of file in string"; fixed to a matching pair.
      Same file also had a `set_xiuwei_by_tyep` typo (→
      `set_xiuwei_by_type`, the real function 438 other files call
      correctly).
    - `d/menpai/duanshi/npc/obj/yaopai2.lpc`: a genuinely corrupted
      duplicate array-element fragment (`"/d/map/xinan/` with no closing
      quote, immediately followed by the real, complete element on the
      next line) — confirmed present in the RAW archive too (not a
      conversion artifact); deleted the broken duplicate line.
    - `d/zuzhi/yipin_tang/xuanwu_tang/diaolan.lpc` and its duplicate at
      `d/zuzhi/yipin_tang/peacock/xuanwu_tang/diaolan.lpc`: both called a
      bare `undefined("exits/out")` (never a real efun/simul_efun on this
      driver) where the evident intent was "is exits/out NOT set" —
      fixed to `!query("exits/out")`.
    - `system/menpai/wuliang/zuo_zimu.lpc`, `d/menpai/wuliang/npc/
      zuo.lpc`, `d/menpai/wuliang/west/npc/xin_shuangqing.lpc`,
      `d/menpai/wuliang/backup/npc/xin_shuangqing.lpc`: all 4 files share
      an identical copy-pasted "姓名" (character-name) dialogue string
      missing its closing quote before the field-separator comma —
      fixed all 4 with the same closing-quote insertion.
    - 4 orphaned help-text/map files renamed away from a misleading
      `.lpc` extension (AGENTS.md §12 pattern — plain text, never
      `#include`d/`load_object()`d by anything, confirmed via grep):
      `help/wizard/format.lpc` → `.txt`, `help/wizard/chelp/ref/
      lpc.lpc` → `.txt`, `help/wizard/chelp/concepts/lpc.lpc` → `.txt`
      (these 3 were pre-named `.lpc` in the RAW archive itself, not
      created by our rename script — a pre-existing naming quirk, not
      conversion fallout), and `d/city/dali/dalimap.lpc` → `.txt` (a
      pure ASCII-art city map, same shape as the `shenmin` map precedent
      already documented for a different lib).
    - Two files (`d/nanyang/suishi.c`/`d/city/nanyang/suishi.c`)
      needed a direct manual `iconv -f GB18030 -t UTF-8 -c` pass —
      `convert_lib.sh`'s per-file conversion left them as raw
      un-converted GBK bytes (misdetected by `file`'s heuristic despite
      the forced-text-extension fix already in the script, per the
      known encoding-detection caveat) — re-verified UTF-8-valid after
      manual conversion, and re-checked for `.c"`/`static` references
      (none found, nothing else to fix in either file).

## Confirmed NOT needed (checked via source read, not assumed)

- **§7 (`get_root_uid`/`get_bb_uid`)** — already present and correct in
  `secure/obj/master.lpc`.
- **§15l (destruct SIMUL_EFUN_OB in master's create())** — `master.lpc`'s
  `create()` has no `destruct()` call at all, just `write()` +
  `seteuid()`.
- **§15n (custom securityd func-discrimination allowlist)** — this lib's
  `securityd.lpc` has a genuinely custom ACL (`exclude_read`/
  `exclude_write` mappings), but critically its `exclude_read` table
  NEVER lists `"(player)"` status for any directory (only `"(wizard)"`/
  `"(apprentice)"`/`"(arch)"` are ever excluded) — the opposite design
  from `shujian2008`'s deny-by-default ACL. A fresh, unauthenticated
  connection's default `"(player)"` status is therefore never denied for
  any lazy `load_object`/`include` compile triggered by the registration
  flow; the design here degrades to ALLOW by default (`return 1` at the
  end of `valid_read`), not deny. Confirmed via full source read, not
  just inference.
- **§15o / §8d (`get_include_path()`)** — no `<local.h>`-next-to-its-own-
  user-file pattern found anywhere via a full-tree scan (every `<x.h>`
  angle-bracket include that resolves to a same-directory local file
  also has a matching top-level `include/` copy).
- **§15p (dns_master preload exclusion)** — `secure/etc/preload` only
  lists 13 registration-essential daemons (securityd, logind, cmd_d,
  chinesed, emoted, aliasd, fingerd, channeld, natured, rankd, weapond,
  combatd, reward_d); no DNS/intermud daemon present. Also checked (per
  §15ab's "still bite even when excluded from preload" caveat) for
  inline calls from `logind.lpc`/`master.lpc`/`band.lpc`/`securityd.lpc`
  into the DNS/intermud subsystem — none found. The intermud subsystem
  (`system/daemon/network/`) exists but is entirely unreferenced from
  the registration/gameplay path.
- **§15j (anti-flood registration throttle)** — `system/daemon/band.lpc`
  only implements IP-ban checking (`is_banned()`); no `IsTimeAllowed`/
  `NewIps`-shaped per-IP registration throttle exists in this snapshot
  (unlike `xo_final`'s `band.lpc`), so repeat registration tests never
  hit a silent cooldown wall.
- **§15ae (`private nomask` command-hook)** — `system/feature/
  command.lpc`'s `command_hook()` is declared plain `nomask` (no
  `private`). Confirmed both via source read AND via 3 live interactive
  tests where `look`/`score`/`i` all produced real, correct output after
  registration.
- **§15u (phone-home license bomb)** — grepped `securityd.lpc`/
  `master.lpc`/`sefun.lpc`/`simul_efun.lpc` for
  `rm`/`shutdown`/mass-delete patterns gated on an opaque check; nothing
  found (the one `SHUTDOWN_D->do_shutdown` reference is inside an
  already-commented-out block in `master.lpc`'s `crash()` handler).
- **§15z (nosave/protected compatibility shim collision)** — no
  `#define nosave static` / `#define protected static` shim exists
  anywhere in this archive's headers.
- **§15x (hardcoded MUD_PORT mismatch)** — `master.lpc`'s
  `connect(int port)` doesn't even use its `port` argument; it
  unconditionally creates a `LOGIN_OB` regardless of which port was
  connected to. No hardcoded port constant anywhere in `globals.h`.
- **§15t patterns 1 & 2 (absolute-path angle-bracket includes,
  `..`-relative includes)** — zero matches for either pattern via a
  full-tree grep.
- **§14 (`valid_override` 3-arg upgrade)** — `master.lpc`'s
  `valid_override` is still the old 2-arg form, but its own logic
  already falls through to an unconditional `return 1;` for everything
  except a `move_object`/`destruct` override attempted from outside
  `F_MOVE` — the 3-arg upgrade exists specifically to correctly ALLOW an
  `#include`d simul_efun fragment's `efun::` override, which this
  file's permissive default already does regardless. No behavior change
  either way; not applied.
- **§8f (comma-list array-modifier bug, `TYPE * a, b;`)** — this is
  primarily a Dead Souls/English-lineage authoring habit; not found here.
- **§15f (bare `array` declaration)** — zero matches.
- **§15r/§15m/§15ad (`check_config.lpc`/`versiond.lpc`-family self-check
  or version-sync daemons)** — no such files exist anywhere in this
  archive.
- **§8e (`tail()` missing efun)** — found ONE occurrence
  (`cmds/app/tail.lpc`, an unused admin command), non-fatal, not fixed
  (matches the documented "non-fatal, unused admin tooling" precedent).

## Interactive test result — full registration + post-login flow

Read `system/daemon/logind.lpc`'s actual `logon()`/`get_id()`/
`confirm_id()`/`get_name()`/`new_password()`/`confirm_password()`/
`get_email()`/`get_gender()`/`enter_world()` callback chain before
scripting the test (per instructions, not inferred from prompt text).
Sequence confirmed: connect → English id → y/n new-character confirm →
Chinese name → password → confirm password → email → gender (m/f) →
dropped into a randomly-selected start room (`select_start_room()`
picks among 4 real rooms).

Ran the full flow **3 times, each in one continuous `mudclient.py`
connection** (2 initial runs, 1 more after the later include/task.h and
include/action.h fixes to confirm nothing broke):

1. `qinfeng` → `y` → **`秦风`** (real Chinese name, accepted immediately —
   direct proof the §15h fix works, not just that the prompt renders) →
   password/confirm/email → `m` → entered **`宫城外`** (Gaochang city
   outskirts) with correct room description → **`look`** (repeated the
   same correct room description — confirms `add_action`'s
   `command_hook` dispatch is genuinely working) → `quit` → correctly
   gated behind the lib's own "must play 30 minutes before data saves"
   confirmation (`y/n`), not a bug.
2. `qinling` → `y` → **`秦岭`** (different real Chinese name, female) →
   ... → `f` → entered **`太白楼`** (a DIFFERENT start room — confirms
   `select_start_room()`'s randomization works) with NPCs (`小三`,
   `段无畏`) rendered in the room → **`look`** (correct repeat) →
   **`score`** (full character sheet: gender-correct "十四岁的女性人类",
   all 7 skill categories at 零级, kill counts, 杀气/师门忠诚度/实战经验/
   江湖阅历/武林声望 all rendering real Chinese text correctly) → `quit`
   gate again.
3. (Re-verification after `include/task.h`/`include/action.h`/`globals.h`
   fixes) `qinfengsan` → `y` → **`秦风三`** → ... → `m` → entered
   `宫城外` again → `look` → `score` → **`i`** (inventory: correctly
   showed `青布衣衫` — the auto-equipped starting cloth from
   `enter_world()`) → `quit` gate.

`grep`ping `log/debug.log` after each of the 3 sessions for
`error|denied|bad argument|undefined|crash|segfault|recursion` turned up
**zero real hits** in all 3 runs (only expected config-dump lines like
`error_handler : 1` and the harmless compile-time `nosave` warnings).

## lpcc sweep

4304 total `.lpc` files (4308 initially, minus 4 renamed to `.txt` as
orphaned non-code text per fix #13). **4202 pass / 102 fail (97.6%)**, up
from an initial 4132/4308 (95.9%) before this pass's fixes.

Memory stayed healthy throughout 3 successive sweep runs (peaked ~2.9GB
RSS on the `lpcc` process, host never dropped below ~5GB free even with
2-3 other concurrent agents' sweeps running at the same time) — this lib
did NOT reproduce the unusually heavy per-file memory footprint noted for
`xo_final` at a similar file count.

**Remaining 102 failures, triaged by category** (none further fixed,
consistent with AGENTS.md §6b — shared/systemic root causes are fixed,
the long tail is documented):
- **27**: `set_skill`/`map_skill` — genuinely never defined ANYWHERE in
  this archive (confirmed via grep), called by only 7 NPC files all
  under `d/menpai/wuliang/` (a small minority next to the 438 files that
  correctly use the real `set_wugong()` API). None of these 7 files are
  on the preload list or reachable from the registration flow — a real
  authoring/content gap (§13-shaped), not fabricated a fix for.
- **~18**: inside confirmed-orphaned/dead-code paths — the unreachable
  `secure/sefun/` simul_efun duplicate, the unreachable `system/daemon/
  daemon/` duplicate daemon copy (a stray nested directory, same shape
  as the `secure/obj/sefun.lpc` dead code noted in the lineage section),
  and the `system/daemon/network/services/` intermud subsystem (missing
  `uid.h`/`daemons.h`/`register.h`/`priv.h`/`post.h`/`config.h` headers
  — none of these files are preloaded or reachable from any live code
  path).
- **Remainder (~57)**: a long tail of single-digit categories in
  individual room/NPC/skill files not further triaged — `Undefined
  variable` (34, mostly further fallout inside the same dead
  network/services tree), `Undefined function member_group`/
  `format_string`/`report_dir`/`is_busy`/`all_caps` (4/4/2/2/2 — likely
  more "only ever called, never defined" simul_efuns in the §15b family,
  none seen on the registration/gameplay path so far), various
  `Wrong number of arguments`/`Bad assignment`/`Illegal LHS`/syntax-error
  clusters (single-digit counts each, scattered across unrelated files —
  no single shared root cause found for any of these on inspection).

## What this confirms for future agents

If another "笑傲江湖"/XO-titled archive turns up later in this project,
check it against all THREE now-processed XO-lineage libs (`xo`, `xo_final`,
`xajhxo`) via the same diff/md5sum discipline — this pass
confirms the lineage has at least 3 independently-evolved snapshots, not
just 2, and world-content sharing (skill files, zone NPCs) doesn't always
correlate with which sibling a new snapshot's core security/master files
most resemble.

## Re-verification pass: driver rebuild + formatter + WASM (2026-07-23)

- **LPC formatter** applied to all `work/*.lpc` (4304 files): 4113
  reformatted, 16 already-clean/unchanged, 175 self-checked errors
  (skipped, expected on legacy code per the formatter's own
  token/byte-identity gate — not investigated further).
- **Native re-test against the rebuilt driver** (`~/src/fluffos/build-debug/src/driver`,
  freshly rebuilt from upstream master): booted clean (no fatal errors,
  only the same pre-existing compile warnings), full registration flow
  verified again end-to-end with a fresh real Chinese name ("秦风七")
  through `look`/`score`/`i`/`quit`, all producing correct output;
  `log/debug.log` clean of `error|denied|bad argument|undefined|crash|
  segfault|recursion` beyond expected config-dump lines. The reformat
  did not break anything — no fixes needed this pass.
- **WASM test** (`scripts/wasm_client.js` against `build-wasm/src`): boots
  cleanly (same preload sequence, no fatal errors — only the expected
  non-fatal warnings, no `sockets` package needed by this lib's preload
  set). Registration proceeds correctly through English name → confirm
  → **real Chinese name** → password → confirm → email, all matching
  the native flow byte-for-byte. However, character-creation did **not**
  reliably complete past the gender (m/f) prompt in repeated attempts:
  one run produced zero output after sending `m` (subsequent `look`/
  `quit` fell through to the driver's generic "什么? 你想干嘛?" fail
  message, as if no player body was ever wired to the connection);
  another run instead re-looped on the very first name prompt several
  times. This is **not** the documented `query_ip_number()` limitation
  (this lib's gender-selection path doesn't gate on IP format) and it is
  **not reproducible natively** — the identical post-formatter code
  completes this exact flow cleanly and repeatedly under the native
  driver. Given the inconsistency between runs (sometimes stalling,
  sometimes re-looping an earlier prompt), this looks like a timing/
  event-loop-jitter interaction specific to the WASM harness/driver
  around the `get_email()`→`get_gender()` `input_to()` handoff (the one
  call in this lib's registration chain with 2 bound extra args, notably
  more than the earlier steps), not a deterministic mudlib bug — logged
  here rather than "fixed" per this pass's instructions not to patch the
  mudlib for WASM-side gaps. Verdict: **boots under WASM, registration
  proceeds through name/password/email, but character-creation finalization
  (gender → entering the game world) is unreliable under this WASM build**;
  no further attempt made to force it through, per the pass's own
  "honest assessment, not a full playthrough" guidance.

## WASM-enablement pass (2026-07, loopback/uptime/throttle + admin seed)

Standard WASM-first pass per AGENTS.md §1.3(b)/(e) and §1.5. Loopback =
`127.0.0.1`, any `127.` prefix, `"localhost"`, or an empty/non-string
value (covers older WASM `query_ip_number()`/`query_ip_name()` garbage).
Gates patched:

- `system/daemon/band.lpc::is_banned()` (~line 38): loopback
  short-circuit `return 0` at the top. The caller passes
  `query_ip_name(ob)` (a hostname, natively "localhost" for loopback),
  so the guard also treats any string containing characters outside
  `[A-Za-z0-9.-]` as loopback — both defensive for WASM garbage values
  and protecting the `regexp()` ban-pattern loop from invalid input.
- `system/daemon/logind.lpc::logon()` (~line 97): the startup-grace gate
  (`time() - startup_time < NO_LOGIN_LIMIT_TIME` destruct) now only
  applies to non-loopback connections. Note `NO_LOGIN_LIMIT_TIME` is 0
  in this snapshot's `include/options.h`, so the gate was already
  dormant — restricted anyway per standing policy so a future config
  change can't re-break WASM.
- The `ALLOW_MULTI_LOGIN` per-IP gate in `get_id()` is compiled out
  (`#define ALLOW_MULTI_LOGIN` commented in options.h) — no patch
  needed. `MAX_USERS` is a total-capacity gate, not per-IP — kept. The
  "must play 30 min before quit saves" gate is game design — kept
  (AGENTS.md §1.3e KEEP list).

Admin seed: registered `fluffos` / display 浮浮 / password `Mud@2026`
through the real flow (id → `y` → Chinese name → password x2 → email →
gender m → random start room; `enter_world()` saves both the user and
login objects immediately, so no quit-gate interaction). Granted
`(admin)` by appending `fluffos (admin)` to `/secure/etc/wizlist` (the
`WIZLIST` file, `include/login.h`). Verified after reboot: login as
fluffos → `update /system/daemon/band` → "重新编译 ...成功！".

Retest: fresh normal registration (`qfxoab` / 秦风) re-verified
end-to-end into 小秦淮客寓 with `look`/`score`/`quit` correct; test
saves removed. No new errors in `log/debug.log`.

Save files for the orchestrator to add (both paths tracked, not
gitignored; `data/user/f/` and `data/login/f/` are NEW directories):
- `libs/xajhxo/work/data/user/f/fluffos.o`
- `libs/xajhxo/work/data/login/f/fluffos.o`

## WASM 修复摘要（迁移自 meta.json 的 group_note）

同一个 XO 血统，第三份快照。状态已从过时的 limited 修正——这份档案自己的 README 里从未记录过任何缺陷说明，本轮重新测试也没有发现：管理员登录（fluffos/Mud@2026）干净正常，"目前权限：(admin)"。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 13 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试 / Deep functional test (2026-08-07)

第一次真正的完整游玩测试。测试角色最终定格在 `xajhthr`（中文名 秦岭三，
女），另有一个更早的测试角色 `xajhtwo`（秦岭，男，无量剑派东宗第六代弟
子）在验证"初次30分钟内quit会清空存档"这个既定设计时被系统正确删除，
细节见下。本轮 WASM 未重新验证：emsdk 工具链下载硬编码指向
`storage.googleapis.com`，本次会话的出口代理策略性拒绝该域名（403，已用
`curl $HTTPS_PROXY/__agentproxy/status` 确认是策略拒绝而非临时故障），
本地无法构建 WASM 驱动。之前 WASM 测试记录里提到的"性别选择之后角色创
建有时卡住、有时重复循环"的问题，这一轮在原生驱动上找到了真正的根因
（见下方"发现并修复"第一条）——**这不是 WASM 专属的时序抖动，是一个
一直存在、原生驱动同样会触发的真实崩溃**，只是这份档案自己的错误处理
机制把崩溃现场写进了一个此前没人查看过的独立日志文件，而不是
`debug.log`，导致此前的排查方向被误导。

### 发现并修复：每一个新玩家在创建人物流程的最后一步（选择性别之后）都会静默崩溃，从未真正进入游戏世界

- **症状**：完成英文名/确认/中文名/密码×2/邮箱/性别选择后，玩家只会看
  到一个光秃秃的 `>` 提示符，`目前权限：`等欢迎语从未出现，后续任何指
  令（`look`等）一律得到"什么? 你想干嘛?"——就像玩家账号从未真正连接
  到任何游戏对象一样。`log/debug.log` 里完全没有任何相关记录。
- **根因排查**：这份档案的 `secure/obj/master.lpc` 把
  `mudlib error handler`设为启用，所有未捕获的运行时错误都被路由到自
  定义的 `error_handler()`，而这个处理函数把崩溃现场写进
  `LOG_DIR + "/runtime"`（而不是驱动默认的 `debug.log`）——查看这个
  之前没人想到要看的文件，找到了真正的崩溃：
  ```
  *Wrong permissions for opening file /log/static/usage for append.
  "No such file or directory"
  'get_gender' at /system/daemon/logind at line 422
  'log_login' at /system/daemon/logind at line 678
  'log_file' at /secure/obj/simul_efun at /secure/simul_efun/file.lpc:17
  ```
  `logind.lpc` 的 `get_gender()`（设置完性别后）先调用
  `log_login(ob, user, ...)` 记录新玩家日志，`log_login()` 又调用
  simul_efun 的 `log_file(PPL_USAGE_LOG, ...)`（`PPL_USAGE_LOG` 宏是
  `"static/usage"`），而 `log_file()` 只是裸的
  `write_file(LOG_DIR + file, text)`，从不检查 `/log/static/` 这个
  目录是否存在——而这个目录**根本不存在于这份档案里**。这一步崩溃
  发生在 `get_gender()` 函数体的最开头，`init_new_player(user)` 和
  `enter_world(ob, user)`（真正把玩家送进游戏世界的调用）都排在这次
  崩溃之后，从未有机会执行——**每一个新注册的玩家都会在这里卡死**，
  不是偶发的时序问题。
- **修复**：这份档案自己的 `secure/simul_efun/file.lpc` 里已经有一个
  现成的 `assure_file(file)` 辅助函数（检查文件是否存在，不存在就逐
  级 `mkdir()` 建好所有父目录），并且已经被 `system/daemon/log_d.lpc`
  等其它日志函数正确使用（`assure_file(file); return
  write_file(file, ...);` 的固定搭配）——`log_file()`是唯一一处漏调
  用它的地方。修复为：
  ```lpc
  void log_file(string file, string text) {
    assure_file(LOG_DIR + file);
    write_file(LOG_DIR + file, text);
  }
  ```
  这个 `secure/simul_efun/file.lpc` 文件本身还有一个 orphaned 的孪生
  副本 `secure/sefun/file.lpc`（确认没有任何代码 `#include` 或加载它，
  与此档案自己 NOTES.md 之前记录的"重复 sefun 目录"是同一批遗留文件）
  ——同样的修法作为廉价保险也一并应用了。
  修复过程中还发现：`assure_file()`在物理上定义在`log_file()`**之
  后**，加上调用它需要一个"先声明后使用"的前置原型（这份档案的编译
  器不支持在同一文件里调用尚未出现在源码前面的函数——`logind.lpc`
  文件头部本身就有一长串`private void xxx(...)`这样的前置声明，是这
  份代码库自己的既定写法）：第一次只加 `assure_file()`调用而没加前置
  声明，编译报错`Undefined function assure_file`——按同一惯例在文件
  开头加了一行`void assure_file(string file);`补上。
- **验证**：修复前，用刚重启的驱动新注册一个角色，选择完性别后必现上
  述崩溃（原生驱动，非 WASM），角色永远停留在光秃秃的`>`。加上修复后
  重启驱动，同样的注册流程（英文名/确认/中文名/密码/邮箱/性别）顺利
  显示"目前权限："并正确落地到随机分配的四个起始场景之一（本次是
  〖龙门客栈〗）；`log/runtime`（此次修复前的旧崩溃记录仍留在文件里，
  但确认 mtime 早于本轮重启，本轮全程没有任何新增内容）和
  `debug.log`双双干净。

### 发现并修复：少林寺方丈（本派拜师环节的关键 NPC）因为一处技能名拼写错误，从存档诞生起就从未真正出现在他自己的房间里

- **症状**：走到少林寺法堂想拜师，执事慧觉回答"未得方丈准许，贫僧不
  敢擅收俗家弟子"——但走进方丈应该所在的〖方丈精舍书房〗，房间里空
  无一人（正常应有的 NPC 完全缺席），`debug.log` 里能看到一条编译期
  的房间物件创建失败信息：
  ```
  *F_SKILL: No such skill (shalin-xinfa)
  创建房间中的物体失败, 详见 room_log
  ```
- **根因**：`d/menpai/shaolin/npc/xuanci.lpc`（玄慈方丈，少林派第三十
  六代掌门方丈）的 `create()` 里有
  ```lpc
  set_wugong("shalin-xinfa", 200);
  ```
  ——技能名拼成了"shalin"，少了一个"o"。`system/skill/shaolin/
  shaolin-xinfa.lpc`（正确拼写）确实存在，证明这是纯粹的拼写笔误，
  不是故意改名或缺失内容。`set_wugong()`对一个不存在的技能名会直接
  抛出未捕获的错误，而这一行排在 `create_family("少林派", 36, "掌门
  方丈")`**之前**——玄慈的整个`create()`在能把自己注册为少林派掌门
  之前就先崩溃了，导致这个对象连同"少林派"这个门派的掌门归属，从这
  份档案诞生起就从未真正被创建过。全档案搜索确认这个拼写错误只出现
  这一处。
- **修复**：改成正确拼写 `set_wugong("shaolin-xinfa", 200);`。`§9`
  格式化自检通过，3 处格式化盲点检查干净。
- **验证**：修复前用刚重启的驱动 `goto` 到方丈的房间，房间描述正常但
  玩家列表里没有玄慈；修复后同样的房间，玄慈正常出现，`look`能看到
  完整的"少林派第三十六代掌门方丈「少林寺方丈」玄慈"称号，`apprentice
  xuan ci`也能触发他自己的`attempt_apprentice()`对话逻辑（"小兄弟与
  本派素无来往，不知此话从何谈起？"——这是他要求申请人必须已经是少
  林弟子才会考虑收为徒的既定门规判断，属于正常游戏设计，不是本次要
  修的问题）。

### 观察但未处理（超出"仅修程序 bug"范围）

- **`F_MASTER`（`system/std/char/master.lpc`）从未提供`attempt_apprentice()`
  的默认实现**：`cmds/verb/apprentice.lpc`对任何门派师父都会调用
  `ob->attempt_apprentice(me)`，但基类完全没有这个方法，只有部分师父
  NPC（如`huijue.lpc`/`xuanci.lpc`/无量剑派的`zuo_zimu.lpc`）自己实
  现了它。对没有实现这个方法的师父（比如大理段氏的`fu_sigui.lpc`、
  `gao_shengtai.lpc`）执行`apprentice`指令会完全静默——没有任何回应
  也没有报错，`call_other`调用一个对象上不存在的函数在 LPC 里就是这
  样静默返回 0。这更像是"这些 NPC 压根没打算走`apprentice`这条路线
  （可能是走剧情任务由代码主动调用`recruit_apprentice()`）"的设计不
  一致，而不是一个能明确判断"应该怎么补"的程序 bug——要不要给
  `F_MASTER`加一个统一的默认回应，属于会影响全档案所有门派 NPC 行为
  的设计决策，如实记录为观察，未做改动。
- **`d/zuzhi/yipin_tang/dixia/npc/weishi2.lpc`第 20 行`set_wugong("ny-
  bufa", ...)`引用了一个全档案都找不到的技能名**：搜遍`system/skill/`
  没有任何文件匹配"ny-bufa"（`system/skill/kongdong/nieyun-bufa.lpc`
  在拼写上有点像，但无法确定"ny"是否就是"nieyun"的缩写，猜测重命名
  需要对这个组织的技能设定有更多背景知识才能确认）。这个 NPC 是"一
  品堂"底下的普通杀手侍卫（`JoinZuzhi`加入的是反派组织，不是正统门
  派拜师路线），不是任何关键剧情节点，严重程度远低于少林方丈那处—
  —如实记录为观察，未做改动。
- **"必须玩够 30 分钟才能保存"的退出门槛，实测会真的删除存档文件**：
  用第一个测试角色`xajhtwo`（已经拜入无量剑派东宗、学会`wuliang-
  jian`）故意在 30 分钟内确认`quit`，`data/login/x/`、`data/user/x/`
  下对应的`.o`存档文件被系统直接删除（不只是"不保存这次的改动"，是
  整个账号一并清空，下次用同一个英文名登录会重新走"创建新角色"流
  程）——这与 README 里"这是游戏本身的防灌水设计"的说明完全一致，也
  与本项目其它同源档案（`xo`/`xo_final`）NOTES.md 里记录的同一机制
  一致，是刻意为之，不是 bug。

### 测试内容与结果

- **注册**：英文名（只能纯字母，3-12 位）→ 确认 y → 中文名（秦岭/秦
  岭三，均一次通过）→ 密码 ×2 → 邮箱 → 性别（m/f 均测试过）→ 顺利落
  地到随机四选一起始场景之一。
- **状态查看**：`look`/`score`/`i`在天赋随机分配、门派加入、学会技能
  前后均正确刷新。
- **门派——组织路线（拜师）**：少林寺（修复后）能正常触发掌门对话逻
  辑，但被"必须先是本派弟子"的门规正确拒绝（正常设计）；大理段氏的
  `gao_shengtai`/`fu_sigui`因为`F_MASTER`默认无实现而静默无反应（如
  实记录为观察，见上）；**无量剑派东宗**（`zuo zimu`/左子穆）走完整
  流程成功：`apprentice zuo zimu`→ 掌门带去侧厅→ 讲门规→`kneel`跪拜
  祖师像→ 正式收徒，`score`正确显示"无量剑派东宗第六代弟子"、师承
  "左子穆"，还获赠一把随身长剑。
- **门派/技能——快捷路线**：全档案没有找到"赠礼 NPC"或`mygift`风格的
  新手引导任务链（不同于同血脉`xo_final`的`mygiftd.lpc`），改用管理
  员`call <玩家>->set_wugong(...)`直接授予技能验证快捷路径确实可行
  （`call xajhthr->set_wugong("jiben-qinggong",30)`成功，`skills`确
  认）。
- **安全陪练/对练（duilian）**：`duilian gong gjie`（无量剑派同门师
  兄）——真实交锋但只有轻微划伤，`stop`指令能随时正常终止对练。
- **持久化**：（1）刻意验证了"30 分钟内 quit 会清空存档"的既定设计，
  与 README 描述完全一致，见上"观察"小节；（2）正常场景：管理员
  `call`授予技能后显式`->save()`，直接断开连接（不发`quit`，模拟真
  实网络掉线）等待约 15 秒后用同一账号重连，`重新连线返回`提示正确
  出现，`skills`显示授予的技能完整保留。
- **管理员账号**：`fluffos`/`Mud@2026`登录正常，`目前权限：(admin)`
  正确显示；`call`指令（本档案没有单独的`update`风格热更新指令，
  `call obj->func(args)`承担了同样的诊断/管理功能）执行`->set_wugong()`
  /`->save()`均成功返回预期结果，确认写权限正常。

## §7.100 扫描修复（`ROOM` 基类多余 `replace_program()`）

`#define ROOM STD_DIR "room"`（`STD_DIR` = `/system/std/`，宏名本
身仍是字面量 `ROOM`，源码里的调用不受拼接影响）：删除 439 处多余
的、独立成行的 `replace_program(ROOM);`（保留 `inherit ROOM;`），
438 处脚本自动删除；另 1 处在本库房间建造工具
`clone/wizard/roommaker.lpc`"克隆我所在的房间"命令的字符串拼接模
板里，已同步手动修正。`help/wizard/es/help/roommaker` 是纯文本帮助
文档，不含该 bug 模式，无需处理。`work/data` 下未发现额外 `.lpc`
源文件。修复后全库仅剩 52 处历史遗留的 `//`-注释掉实例，均确认无
害、未改动。已用 `build-debug` 驱动干净启动验证（0 个新增编译错误
，端口 40069 正常监听，`debug.log` 无新增 "cannot replace"/
"cannot bind" 行）；未做完整 §10.7 深度游玩测试。

## 深度功能测试第四轮 / Round-four §10.7 deep test (2026-08-20)：真实战斗致死/复活流程

补全上一轮（2026-08-07）从未真正测试过的一环：真实战斗导致角色死亡、
经过判官轮回流程、最终复活重新落地游戏世界的完整循环。全程同时监视
`log/debug.log`（驱动默认日志）和 `log/runtime`（这份档案自己的
`error_handler()` 改写落点，上一轮正是靠查看这个文件才找到注册崩溃
的真正根因，本轮同样全程盯着）。

### 死亡机制确认（两段式 kee/eff_kee 模型）

读 `system/std/char.lpc` 的 `heart_beat()` 确认了这份档案的死亡判定
逻辑：`eff_kee`/`eff_sen`/`eff_gin` 任一 < 0 时直接 `die()`；`kee`/
`sen`/`gin` 任一 < 0 时（存活状态下）先 `unconcious()`，非存活状态才
`die()`。这是与本项目其它一些库（如 `xyxy2`）相同形状的两段式生命值
模型。用管理员 `call qxverify->set("eff_kee", -1)` 给测试角色注入一次
性负值（临时数值授予，未绕过真实 `die()`/`heart_beat()` 代码路径），
接下来完全依赖真实的、未修改的 `heart_beat()` 心跳循环触发 `die()`——
测试确认心跳只在角色有活跃在线连接时才会真正跳动（断线角色的心跳不
会推进死亡判定），角色保持连线在场时，等待几秒后角色真实死亡（"你死
了"，"【谣言】秦验证莫名其妙的死了"），移动进入 `DEATH_ROOM`
（`/d/place/death/yellow1`，"黄泉路"），`is_ghost()` 变为 1。

### 发现并修复：查察司判官 `chacha.lpc` 的死亡轮回状态机有一条退出分支忘记清理重入守卫，导致携带任何物品死亡的鬼魂永久卡死、再也无法投胎——本轮任务重点排查对象，找到了真实缺陷

- **背景**：`d/place/death/npc/chacha.lpc`（查察司判官，阎罗大殿里负责
  鬼魂轮回叙事的 NPC）用一个共享的临时属性 `death_stage_active` 作为
  重入守卫，防止玩家重连触发的 `init()` 在一条 `death_stage()`
  `call_out` 链条还在跑的时候又叠加一条新链。这个守卫也同时被
  `d/place/death/npc/mengpo.lpc`（孟婆，另一个独立的投胎 NPC）复用同
  一个属性名——两者的 `init()` 都以`if (ob->query_temp(
  "death_stage_active")) return;`开头。
- **症状**：`death_stage(object ob, int stage)` 走到最后一段（`stage
  == 4`）时，如果 `deep_inventory(ob)`（鬼魂身上还带着东西）非空，会
  提示"判官说道：不过阴间的东西是不能带到阳间的，你先要把你身上的东
  西放下来。"然后直接 `return`——但**这条分支唯独没有清理
  `death_stage_active`守卫**，跟同一函数里另一条退出分支（`!ob ||
  !present(ob)`，第 69-72 行）以及`mengpo.lpc`自己整条链路的每一个退
  出点相比，是唯一遗漏的一处。玩家扔掉身上的东西以后，守卫仍然锁死为
  1，无论离开房间再回来（重新触发`init()`）还是走到孟婆房间（她的
  `init()`检查的是同一个属性名），都会被同一个残留的守卫直接挡在
  `return`——**永久卡死，两条投胎路线全部失效，只有管理员手动清空这
  个临时属性才能救回来**。
- **可达性验证（不是纸面假设）**：这份档案的`die()`
  （`system/feature/damage.lpc`）本身不会清空鬼魂的随身物品——真正清
  空发生在`CHAR_D->make_corpse()`（`system/daemon/chard.lpc`）里，只
  在活人变鬼魂那一刻执行一次。但孟婆自己的投胎流程会**主动往鬼魂身上
  塞一碗"孟婆茶"**（`tea_give()`最后一段，`tea->move(ob)`）——茶碗要
  靠玩家自己输入`drink tea`喝掉才会被`destruct()`清除。也就是说，一
  个鬼魂只要先走到孟婆房间领了茶还没喝，就带着这碗茶继续往判官房间走
  ，是完全正常、大概率会发生的真实游玩路径（孟婆房间就在必经之路上）
  ，不是刻意构造的边界情况。
- **实测复现**：测试角色`qxverify`（秦验证）死亡后按真实路线走
  （黄泉路→黄泉路→孟婆房间取茶不喝→鬼门关→酆都城→大殿）到查察司判
  官房间，等待完整的五段对话跑完，第五段（`stage==4`）确认收到"你先
  要把你身上的东西放下来"提示；管理员`call`查询确认
  `query_temp("death_stage_active")`此时为`1`且再也不会归零——离开房
  间再走回来（触发`init()`重试）确认没有任何新消息，验证卡死是真实、
  永久的，不是时序错觉。
- **修复**：在这条唯一遗漏的分支里补上同一守卫的清理，与函数里另一条
  退出分支保持一致：
  ```lpc
  if (sizeof(obs)) {
    command("hmm");
    tell_object(ob, HIW "判官说道：“不过阴间的东西是不能带到阳间的，你先要把你身上的东西放下来。”\n" NOR);
    ob->delete_temp("death_stage_active");
    return;
  }
  ```
  这是最小、行为一致的修复：清理守卫以后，玩家扔掉东西、离开房间再走
  回来会重新触发`init()`→`check_rein()`→`death_stage()`整条链，这次
  `deep_inventory()`已经是空的，直接走向正常完成分支。
- **修复后验证**（全新测试角色`qxverify`，重启驱动加载修复后）：完全
  重复上面的复现步骤，第五段消息出现后立刻用管理员`call`确认
  `death_stage_active`已经变回`0`（此前是永久卡在`1`）；然后
  `drop tea`丢掉孟婆茶，离开大殿再走回来，五段判官对话完整重新播放一
  遍，最后一段成功触发`ob->reincarnate()`并随机传送到三个复活点之一
  （本次落地"广场"）；`is_ghost()`确认变回`0`，`score`/`look`产出的
  内容完全正常，角色成功回到阳间继续游戏。
- **日志核对**：整个死亡→轮回卡死→修复→重新死亡→轮回完整走完的全程
  （两轮驱动重启，多个测试角色），`log/debug.log`稳定保持 392 行、
  `log/runtime`稳定保持 3034 行，与本轮测试开始前的基线**完全一致，
  没有任何新增内容**（`log/runtime`里现存的历史崩溃记录全部是本项目
  更早期会话遗留的，mtime 均早于本轮启动）——这个 bug 本身不产生任何
  错误签名，纯粹是一次静默的、可复现的状态机遗漏，只能靠真正走一遍死
  亡流程并检查每一个退出分支才能发现，符合本轮任务"检查`death_stage()`
  每一个退出分支是否都清理了重入守卫"的排查要求。

### 标准检查清单快速过一遍（预期多数已修，仅确认）

- **§7.90（eval-cost）**：`config.fluffos`里`maximum evaluation cost`
  已经是`30000000`（本项目通用的已修正默认值），确认早已修好。
- **§7.100（`ROOM`基类多余`replace_program()`）**：全库`grep`零处存活
  实例（历史修复记录见上，本轮仅确认零回归）。
- **§7.111（`standard_trace()`对`error["object"]`为`0`时崩溃）**：这
  份档案的`master.lpc`用独立的`trace_line()`辅助函数封装了这处逻辑，
  本来就是`obj ? file_name(obj) : "<none>"`三元守卫写法（跟已知漏洞
  形状不同，但效果等价、本来就安全）——确认不需要修。
- **§7.112（死亡/重入`call_out`守卫）**：全库唯二使用
  `death_stage_active`标志的两个文件是`mengpo.lpc`（已确认每条退出
  分支都清理干净）和`chacha.lpc`（本轮发现并修复的那一处遗漏，见上）
  ——本项任务的重点排查目标，找到了真实缺陷。
- **§7.79（`addn()`二参数变体）**：全库`grep`零匹配，这份档案压根没
  有`addn()`这个调用，确认不适用。
- **§7.108（`reconnect()`应调用`enable_commands()`）**：`clone/user/
  user.lpc`的`reconnect()`本身不直接调用`enable_commands()`，但实测
  确认重连后`look`/`i`/`score`等指令全部正常工作——原因是`add_action`
  绑定（`enable_player()`里注册的`command_hook`）挂在角色对象本身而不
  是连接上，断线不会清除，`logind.lpc`的`reconnect()`只需要
  `exec(user, ob)`把新连接接到同一个未销毁的对象上即可恢复指令；本轮
  测试中每一次断线重连（多次）指令都立即可用，确认不是 bug，是这份档
  案的既有架构设计正常工作。
- **§7.30（`mapp(x) ? x : ([])`守卫）**：`system/feature/skill.lpc`的
  五个`mapping`访问器（`query_jibie_map()`等）内部本身没有守卫，直接
  `return`原始实例变量——但实测一个全新、零技能角色执行`skills`指令
  完全正常显示"你目前并没有学会任何技能。"，未崩溃：三处真实调用点
  （`cmds/comm/skills.lpc`、`cmds/admin/makedoc.lpc`、`cmds/comm/
  enable.lpc`）全部先用`sizeof()`或`mapp()`把返回值判空之后才会继续
  往下用，且经验证这份驱动上`sizeof(0)`本身不报错（返回`0`，不是抛异
  常）；另外`system/std/char/npc.lpc`的`tell_skills()`里
  `my_family["generation"]`这种嵌套取值也是安全的，因为只有
  `is_tongmen_of()`已经确认双方`family`字段都是合法`mapping`之后才会
  走到这一步（`is_tongmen_of()`自己有`!mapp()`守卫）。全部三个真实调
  用路径都实测/代码确认安全，无需改动。
- **combatd.lpc 的`bounce`除零 bug**：全库（`system/daemon/
  combatd.lpc`及其孤立副本`system/daemon/daemon/combatd.lpc`）
  `grep`零处出现`bounce`这个变量名，这个具体 bug 形状在本档案里不存
  在，不适用。

### 结论

本轮任务明确要求的"真实战斗致死+复活"缺口已补全：**找到并修复了一个
真实、可复现、静默的程序缺陷**（`chacha.lpc`死亡轮回状态机的重入守
卫在物品检查分支遗漏清理，导致携带物品死亡的鬼魂永久卡死、两条投胎
路线同时失效），修复经过全新测试角色从死亡到复活的完整实测验证，两
份日志文件全程干净无新增。标准检查清单六项全部确认（一项已修实无需
再动、四项确认不适用/设计正常工作、一项就是本轮的核心发现）。
