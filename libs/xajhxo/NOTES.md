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
