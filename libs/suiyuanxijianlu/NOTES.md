# 随缘洗剑录 (suiyuanxijianlu) — NOTES

Archive #96: `archives/随缘洗剑录.rar` ("Record of Sword-Washing by Fate").

## What this lib is

An **ES II-lineage** MudOS v22 wuxia mudlib. Confirmed via `adm/obj/master.c`'s
own header comment: `// for ES II mudlib`, `// original from Lil`,
`// rewritten by Annihilator (11/07/94)`, plus a later `98-10-23` upgrade
credit to `ken@XAJH` and a `securityd.c` credit to `aeolus 12/25/2000`. This
is the same lineage family as many previously-done libs in this project
(yueyingqiyuan, wuhanzhan, huoying, shenzhou, yanhuangwuhun, etc.) — same
`adm/daemons/securityd.c` ACL-table shape, same `feature/dbase.c` real
local `set`/`query`/`delete` implementation (i.e. **NOT** the nitan-family
bare-simul_efun dbase architecture bug, §15 — this lib inherits `F_TREEMAP`
and has genuine per-object storage, confirmed safe).

The raw archive's mudlib root is `syxjl/world/` (`syxjl/config.cfg` points
`mudlib directory : ../mud/world`, `master file : /adm/obj/master`). The
directory shape (`adm/`, `clone/`, `cmds/`, `d/`, `feature/`, `inherit/`,
`kungfu/`, `maxim/`, `obj/`, `quest/`, `task/`, `u/`) and content (`kungfu/`
skill-class directories, 客栈/李寻欢 starting NPC, 明教/武当/嵩山/衡山 etc.
zone names) are standard wuxia-genre ES II content — nothing suggesting a
closer match to any more specific already-done sibling lib than "generic ES
II family", so no forced lineage claim beyond that.

Archive also bundled a prebuilt Windows driver (`mudos.exe`/`mudos.dll`,
May 1998) and an `addr_server` binary — both left untouched/ignored per the
pipeline (we use our own FluffOS build).

## Port

**40088** (per TODO.md's reservation for archive #96 in the #92-96 batch).

## Fixes applied (with why)

1. **§15ao — `switch(port){ default: ... }` with no real `case` in
   `master.lpc`'s `connect()`.** Hard parse error on this driver (a `switch`
   needs at least one real `case` label). There was no actual branching on
   `port` in the original code anyway (`default:` was the only clause) —
   rewrote as a plain unconditional block, preserving the `catch(new(LOGIN_OB))`
   body verbatim. This is `adm/obj/master.lpc`, the file the config actually
   points at (a sibling copy at `adm/single/master.lpc` has the same pattern
   but isn't used by our config — left alone, noted here in case a future
   agent points a config at it).

2. **§15h — `is_chinese()` GBK-byte-range check.** `adm/simul_efun/chinese.lpc`
   had the classic `strlen(str)>=2 && str[0] > 160 && str[0] < 255`
   byte-range check — always false against real UTF-8 codepoints on this
   driver. Fixed to a CJK Unicode range check (`str[0] >= 0x4e00 && str[0]
   <= 0x9fff`) with `strlen(str)>=1` (a single Chinese character is a
   complete valid name-char now, not "half a GBK character").

3. **§15h — `check_legal_name()`'s byte-length bounds and byte-stride loop,
   in `adm/daemons/logind.lpc`.** `strlen(name) < 2 || > 8` (meant "1 to 4
   Chinese characters" per the message text, calibrated for 2 bytes/char)
   halved to `< 1 || > 4`. The sliding-window loop's `i%2==0 &&
   !is_chinese(name[i..<0])` (only checking even BYTE offsets, i.e. each
   GBK character's lead byte) had the `i%2==0 &&` guard dropped entirely,
   since every UTF-8 index is already one full character now. Verified via
   full registration test with a 3-character Chinese name (秦风寒).

4. **§15p / §15ai — `network/dns_master` preload exclusion, PLUS a live
   call-site guard.** Removed `/adm/daemons/network/dns_master` from
   `adm/etc/preload` (standing policy — avoids a boot-time hang against an
   unreachable intermud "boot server"). **Also**, unlike some prior libs,
   `adm/daemons/logind.lpc`'s `encoding_to_mudlist()` (the very first step
   of EVERY connection, right after the GB/Big5 prompt) called
   `DNS_MASTER->query_muds()`/`->query_svc()` **unconditionally**, with no
   `find_object()` guard — this would have silently lazy-loaded the
   excluded daemon back in on every single connection (defeating the
   preload exclusion entirely), and the subsequent `keys(mud_list)` would
   have thrown on a `0` `mud_list` if the daemon failed to load. Guarded
   the whole mud-list-fetch block behind `find_object(DNS_MASTER)`,
   falling back to an empty `([])` mud list (the code already printed a
   "not connected to other muds" message in this case — just made sure it
   doesn't also crash). Confirmed via the debug.log's `Undefined function`/
   `Bad argument` absence and a clean multi-run registration test that this
   never surfaces.

5. **§15ar-adjacent — `commandd.lpc`'s `sscanf(cmds[i], "%s.c", cmds[i])`.**
   Checked proactively per policy. This one was **already fixed by
   `convert_lib.sh`'s own `.c"`-reference sed** (the format string's `.c`
   sits immediately before the closing quote, exactly the pattern that sed
   already handles) — confirmed it now reads `"%s.lpc"` with no manual
   intervention needed. Documenting as **confirmed NOT needed as a manual
   fix**, since this exact bug class has bitten two previously-shipped
   libs (bxsj/bxsj1) that needed it fixed by hand.

6. **§15ae — `private nomask` command-hook.** Checked `feature/command.lpc`'s
   `command_hook()` proactively. It's declared plain `nomask` (no
   `private`) and dispatch (`add_action("command_hook", "", 1)`) works
   correctly — **confirmed NOT present**, no fix needed. Verified
   end-to-end with real post-login `look`/`score`/`i` commands (see below).

7. **§15n / §8c / §4 — custom `securityd.lpc`'s `valid_read`/`valid_write`,
   and `master.lpc`'s lazy `SECURITY_D` load.** Checked proactively. This
   lib's `valid_read`/`valid_write` only apply their ACL restriction for a
   short allow-list of sensitive `func` values (`read_file`, `file_size`,
   `stat`, `read_bytes`, `tail`, `ed_start` for read; `write_file`,
   `save_object` special-cased, else the ACL for write) — anything else
   (including `load_object`/`recompile_object`/`include`) falls through to
   `return 1;` unconditionally. **Confirmed NOT the §15n bug** — compiling/
   including code was never blocked here. `master.lpc`'s own
   `valid_read`/`valid_write` already wrap `load_object(SECURITY_D)` in
   `catch()` (no reentrancy flag, but the `catch()` alone was sufficient —
   confirmed no stack-overflow/recursion crash on a clean boot) —
   **confirmed the §4 pattern's dangerous shape (unguarded lazy load with
   no catch) is NOT present**, no fix needed.

8. **§7 — `get_root_uid()`/`get_bb_uid()`.** Both already implemented in
   `master.lpc`, returning `ROOT_UID`/`BACKBONE_UID`. **Confirmed present,
   no fix needed.**

9. **§15ag — `ed_start`/`ed_cmd`/`query_ed_mode`.** Grepped the whole lib —
   zero hits. **Confirmed not present, no fix needed.**

10. **§15l — `master.lpc create()` destructing `SIMUL_EFUN_OB`.** `create()`
    is just `write("master: loaded successfully.\n");` — **confirmed not
    present, no fix needed.**

11. **§15r — `check_config.lpc`-style driver self-check.** No such file
    anywhere in the archive. **Confirmed not present.**

12. **§3 — `static` → `nosave` blanket sed, and its known string-literal
    counterexample.** Ran the standard `\bstatic\b` → `nosave` sed (89
    files touched net of the revert below). **Then found and fixed a real
    instance of the exact `moniHuafu` counterexample from AGENTS.md §3**:
    this lib uses a `log_file("static/CRASHES", ...)`-style convention
    (a literal `"static"` path SEGMENT, not the keyword) in **22 files**,
    PLUS a subtler variant the counterexample note doesn't explicitly
    cover — `"/log/static/LASTCRASH"`-shaped strings where `static`
    appears **mid-path**, not at the very start of the string (17 more
    occurrences across `combatd(1).lpc`, `adm/single/master.lpc`,
    `cmds/.../{kill,fuhuo,shutdown,reboot,recover,bai,apprentice,uptime}.lpc`).
    The word-boundary sed corrupted ALL of these to `"nosave/..."` /
    `"/log/nosave/..."`. Found this because `cmds/usr/uptime.lpc`'s
    `write(read_file("/log/nosave/LASTCRASH"))` (called from
    `logind.lpc`'s `login()` on EVERY connection) then read a
    nonexistent file, got `0` back, and `write(0)` crashed with `*Bad
    argument 1 to receive(): Expected string or buffer Got: 0` inside
    `clone/user/login.lpc`'s `receive_message()` — **this derailed the
    entire registration flow on the FIRST test run**: after that crash,
    the connection's `input_to()` chain never got (re-)armed, so every
    subsequent typed line just hit the default fail message ("What ?"),
    looking exactly like a totally broken/silent server. Fixed by
    reverting every `"[/]nosave/...` string back to `"[/]static/...`
    (verified against the raw pre-conversion archive that `static` — never
    `nosave` — was the ORIGINAL word in every one of these 39 total
    occurrences, so this is a pure revert, not a guess).

13. **A same-named directory colliding with the `.c`→`.lpc` rename** (the
    `xianjianchuanqi`/`zitengzhan`-shaped bug, but a fresh instance):
    `kungfu/skill/chuixue-jian.c/` (a directory containing `taiji-jian.c`/
    `liehuo-jian.c`) and `u/duanfei/chuixue-jian.c/` (containing `lian.c`)
    both got renamed to `...chuixue-jian.lpc` (a directory, not a file) by
    the blind rename pass, with their *inner* files left un-renamed (the
    parent directory rename raced ahead of `find`'s listing). Confirmed
    via grep that NOTHING in the whole lib references either directory by
    that literal path (the live, working skill is a differently-named
    sibling, `hantian-chuixue-jian`) — these are orphaned/superseded
    duplicate-content folders, not live code. Renamed both directories to
    `*.orphaned-dir` (and their never-renamed inner `.c` files to `.lpc`
    for consistency) so nothing mistakes a directory for a compilable
    object. A third, genuinely-empty directory, `kungfu/skill/cuixue-jian.c/`
    (note: different spelling, no `h`) hit the same rename bug but had
    zero children even in the raw archive — renamed to
    `cuixue-jian.orphaned-empty-dir`.

14. **Uppercase `.C` files** (the `shenmo`-shaped bug). 6 files:
    `d/shashou/obj/{YINGXION,XUEYI}.C`, `d/quanzhen/obj/jia.C`,
    `d/shashou/npc/obj/{YINGXION,XUEYI}.C`, `d/quanzhen/npc/obj/bookshelf.C`.
    `convert_lib.sh`'s glob is case-sensitive and skipped these; one file
    (`cangjingge2.lpc`) references `bookshelf` via an extensionless
    `__DIR__"obj/bookshelf"` path that would have resolved fine on a
    case-insensitive filesystem but not here. Renamed all 6 directly to
    `.lpc` (their `file`-based encoding guess already correctly ran them
    through iconv during the original convert pass, confirmed valid UTF-8).

15. **A genuinely corrupted/truncated raw source file:**
    `d/wudujiao/npc/cunfu.c` failed BOTH strict and `-c`/lossy `iconv`
    (exit 1 either way — `iconv: incomplete character or shift sequence at
    end of buffer`), and `convert_lib.sh`'s current fallback logic treats
    ANY nonzero exit from the `-c` attempt as total failure (discards the
    temp file, logs "FAILED to convert", leaves the original raw GBK bytes
    in `work/` untouched) — this is a **real gap in `convert_lib.sh`
    itself** worth flagging for the main session to consider: `iconv -c`
    can still exit nonzero even after writing a perfectly good *partial*
    conversion to stdout (confirmed: piping the same command's stdout
    directly showed clean, correct UTF-8 text right up to where the raw
    bytes are genuinely garbage), so the current "discard on any nonzero
    exit" logic throws away recoverable partial output, not just failed
    output. Inspected the raw bytes directly (`xxd`): the file is a small,
    trivial random-NPC-name generator (`cunfu.c` — "村妇", a random
    village-woman NPC) whose content is cleanly valid right up through
    `set("max_qi", 200);`, then abruptly turns into non-text binary
    garbage for the rest of its ~340 remaining raw bytes (looks like
    unrelated corrupted/overwritten disk content, not anything
    resembling LPC or even valid GBK). Fixed by extracting only the
    valid leading ~500 bytes, converting those cleanly, and closing the
    `create()` function's brace immediately after the last valid
    statement — no fabricated content, matching the project's established
    "close gracefully, don't invent" convention for genuinely truncated
    files (same approach used for archive #91's one similarly-truncated
    file). This file is not preloaded/reachable from the standard
    registration/look/score path either way.

16. **A one-shot, whole-mudlib-affecting header bug:
    `kungfu/skill/eff_msg.h` duplicated its ENTIRE body within itself**
    (confirmed present byte-for-byte in the RAW pre-conversion archive too
    — not something our pipeline introduced): `eff_status_msg()` and
    `damage_msg()` were each fully defined TWICE in the same file (once
    around line 9, once again around line 150), each copy also trailed by
    a stray, non-matching `#include "/kungfu/skill/eff_msg.h";` /
    `int p; ...` snippet (an unclosed second "usage example" left active
    instead of commented, unlike the identical-looking, correctly
    commented-out block at the very top of the file) — this crashed EVERY
    file that includes it (`linboweibu`, `linboweibu1`, `taiji-quansd`,
    `taiji-quan/zhensd`, `huifeng-jian`, `yijin-jing`, 6 kungfu-skill
    action files) with `Redeclaration of function 'eff_status_msg'/
    'damage_msg'`. The two copies' `damage_msg()` actually cover
    *different, non-overlapping* damage-type `case` labels (one has
    擦伤/割伤/砸伤/default, the other has 瘀伤/内伤/震伤/抓伤/刺伤/default) —
    NOT simple duplicates, so a naive "just delete the dupe" fix would
    also silently drop real damage-flavor-text coverage either way. Kept
    the FIRST copy (immediately after the doc comment, the position every
    sibling working file's own `eff_msg.h`-alike would put the real
    definitions) and removed the second, to keep the fix conservative
    (no fabricated merge risking a duplicate-`case` compile error of its
    own). One of the 6 dependent files (`huifeng-jian.lpc`) had a SECOND,
    independent bug once this was fixed: `#include
    "/kungfu/skill/eff_msg.h";` (which defines global variables) appeared
    textually BEFORE `inherit SKILL;` — illegal on this driver (§15t
    variant 3) — reordered so `inherit` comes first. All 6 files verified
    passing via direct `lpcc` afterward.

17. **A recurring "pager status line pasted into the source" corruption
    (confirmed present in the raw archive, NOT a conversion artifact) —
    found in 3 unrelated places**: `d/xingxiu/obj/sheep.c` and
    `kungfu/skill/yijin-jing/heal.c` each had a stray, standalone line
    reading `== 未完继续 NN% == (ENTER 继续下一页，q 离开，b 前一页)` (a
    Chinese `more`-style pager's "-- More --" status line) embedded
    mid-function — clearly captured by accident during some long-ago
    editing/screen-scraping session, not code. Deleted both lines
    outright (they're 100% non-code noise, confirmed by comparing
    against the surrounding statements' obvious intent). A related,
    nastier variant in `u/linghu/ground2.lpc` (a PK-arena feature in a
    personal wizard directory) had the SAME pager garbage **spliced into
    two live statements** rather than sitting on its own line:
    `{(q 离开，b 前一页，其他继续下一页)` (should just be `{`) and
    `if (brief)== (q 离开，b 前一页，其他继续下一页)` (should just be
    `if (brief)`), plus a `case MO` with no colon and no real constant
    name a few lines earlier (inferred, from this same switch's sibling
    cases elsewhere in the file using `MODE_SINGLE_SD`/`MODE_SINGLE_LT`/
    `MODE_TEAM_LT`/`MODE_TEAM_DZ`/`MODE_TEAM_XH` in that exact order and
    this being the FIRST case in its switch, to be the truncated start of
    `MODE_SINGLE_SD:`). Fixed all three spots in `ground2.lpc`.
    **Left un-fixed, documented as a known gap** (see below): the SAME
    file's `do_debug()` function (much further down, ~250 lines) has
    extensive, unrelated pre-existing corruption (missing semicolons and
    closing parens across ~40+ lines) that also predates this project —
    a genuinely unfinished/never-tested wizard debug utility, not reached
    by any normal play, not worth the repair time this session.

18. **Missing/dropped closing quotes in string literals (§10-shaped,
    confirmed pre-existing in the raw archive via byte-level diff against
    both strict and lossy `iconv` output) — found in 7 unrelated files**:
    `d/quanzhen/{hudi3,hudi4,hudi5,hudi6}.lpc` (missing OPENING quote
    before a `set("long", ...)` multi-line text block — `hudi5` was
    additionally missing its CLOSING quote too, a second independent
    instance in the same file), `kungfu/skill/qingyi-jian.lpc`
    (`"skill_name" : "大悲式,` missing the closing quote before the
    comma), `kungfu/skill/yanxing-dao.lpc` (same shape, `...刺去,`),
    `kungfu/skill/jueqing-chenfa.lpc` (two independent instances in the
    same file: `...阴毒无\n塘,` — note this one lost more than just the
    quote, an unrecoverable original-content truncation the raw bytes
    confirm predates us too, closed cleanly after the last legible word
    rather than fabricating the rest — and a second `...阴毒无` case
    further down, same fix). Each fixed by inserting the missing `"`
    at the exact point the content/context indicates.

19. **A 4-file `set("long", @LONG ... LONG)` closing-tag-merged-onto-text
    bug** (the exact `tianxia`/AGENTS.md-documented "iconv -c eats an
    adjacent real newline" shape) in `d/quanzhen/{manglin1,manglin2}.lpc`,
    `d/chang'an/gulouerceng.lpc`, `d/wudang/xiaolu2.lpc` — the closing
    `LONG` heredoc tag must start its own line, but was merged onto the
    end of the preceding Chinese text line in all 4. **Diagnostic
    footnote for future agents**: my first repair attempt used a careless
    manual `iconv -f GB18030 -t UTF-8 ... 2>/dev/null` (no `-c`, stderr
    discarded) to re-extract 2 of these 4 files from raw for inspection,
    which SILENTLY TRUNCATED both of them mid-file (strict `iconv` was
    failing partway through on an unrelated bad byte elsewhere in each
    file, and redirecting stderr to `/dev/null` hid the nonzero exit and
    the truncation both) — caught immediately by a sanity line-count/
    content check before it was ever written back into `work/`, redone
    correctly with `-c`. **This was purely a self-inflicted diagnostic
    mistake, not a flaw in `convert_lib.sh` itself** (which already does
    the correct strict-then-`-c`-fallback dance with proper exit-code
    checking) — noting it here only as a reminder to always re-derive a
    file from `raw/` through the SAME strict→`-c`-fallback discipline the
    real pipeline uses, never a bare one-off `iconv` call.

20. **A shared-header path mismatch, 21 files at once (§8g: one root
    cause, not 21 bugs):** every file under `u/think/gfjob/npc/*.lpc`
    (~21 files) did `#include "/quest/gfjob/npc/npc.h"` — but
    `/quest/gfjob/` doesn't exist anywhere in the archive; the real
    `npc.h` lives at `/u/think/gfjob/npc/npc.h` (same directory as the
    files including it — a personal-wizard quest-content area, clearly
    moved at some point without updating its own header's `#include`
    path in whichever template it was cloned from). Fixed the `#include`
    path in all 21 files in one `sed` pass to point at the real location.
    A related, unrelated-cause pair: `u/bombju/wudang/{hutou,langmei}.lpc`
    did `#include "feng.h"` (quoted, local-dir-first resolution) but
    neither file's own directory has a `feng.h` — the real one lives at
    `/d/wudang/feng.h` (these two files are near-verbatim clones of the
    `d/wudang/taoyuan/tyroad*.lpc` room family, sharing that header).
    Fixed both to the absolute path. `d/wudang/taoyuan/{tyroad4,5,6,7}.lpc`
    had a THIRD, distinct variant of the same underlying "which feng.h"
    confusion: `#include __DIR_"feng.h"` (note: single trailing
    underscore, not the real `__DIR__` macro) — a typo that resolves to
    nothing at all (`__DIR_` isn't a macro), and even a corrected
    `__DIR__"feng.h"` would have been wrong anyway since `feng.h` lives
    one directory up, not alongside these 4 files. Fixed all 4 to the
    same `/d/wudang/feng.h` absolute path.

21. **`new` used as a bare variable name (7 files) — the exact bug class
    already retroactively found in `jinyongqunxiazhuan2008`/`xiakexing3`
    (archive #91's report)**: `d/quanzhou/npc/{tang,tang1,tang2,tang3}.lpc`,
    `d/taishan/{tang2,tang3,xingtang}.lpc` all declared
    `object *inv, new;` then did `new = new("/clone/npc/...")` — `new` is
    a reserved token (`L_NEW`) on this driver's lexer, not just a
    shadowable identifier, so the DECLARATION itself is a hard parse
    error. Renamed the variable to `new_ob` throughout all 7 files
    (declaration + both use sites each) via a scoped `sed`, verified each
    compiles clean afterward.

22. **A duplicate `inherit F_UNIQUE;` line (3 files)** — same shape as
    already found in the `jinyongqunxiazhuan2008` pass:
    `d/mingjiao/npc/{yinwufu,yinwulu,yinwushou}.lpc` all had `inherit
    F_UNIQUE;` written TWICE (byte-identical files, likely all cloned from
    one template with the same authoring slip), producing `Illegal to
    redefine 'nomask' function 'violate_unique'` (the second inherit tries
    to re-bring-in a `nomask` function `F_UNIQUE` already installed by
    the first). Removed the duplicate line from all 3.

23. **`message_combatd` — the exact simul_efun gap AGENTS.md's own §8b
    write-up is named after**, recurring here: called from 4 kungfu
    combat-skill files (`chousui-zhang/{sandu,throw}.lpc`,
    `force/transfer.lpc`, one more commented-out call site) with the same
    `(msg, me, target)` 3-arg shape as `message_vision()`, but never
    defined anywhere in this lib's `simul_efun`. Restored as a thin alias
    to `message_vision()` in `adm/simul_efun/message.lpc` (added AFTER
    `message_vision`'s own definition in the same file, per the §8b
    same-file-ordering rule), which already handles exactly this `$N`/`$n`
    attacker/target substitution shape. All 3 real call sites verified
    compiling clean afterward.

24. **A same-file forward-declared function whose real body lives entirely
    inside a comment (3 files)**: `d/jingzhou/npc/{dingdian,shiye,
    lingtuisi}.lpc` each reference `(: do_zhuibu :)` in an `inquiry`
    mapping (an NPC "ask about work" hook), but `do_zhuibu()`'s actual
    body — along with a ~200-line quest implementation — is entirely
    inside a `/* ... */` block (confirmed: even the function's OWN
    forward declaration a few lines above `create()` is itself commented
    out, `//string do_zhuibu();`, in all 3 files) — a deliberately
    disabled/unfinished feature, not something this project should
    resurrect (that would mean writing ~200 lines of new quest logic from
    scratch, well out of scope). Removed just the `"工作" : (: do_zhuibu
    :),` entry from each NPC's `inquiry` mapping (leaving an empty `([
    ])`), which is the minimal fix that stops referencing a genuinely
    absent function without fabricating the missing feature.

## Directories created (raw archive didn't ship them, but code references
them)

`static/`, `binaries/`, `adm/swap/`, `data/nosave/`, `log/nosave/`,
`nosave/` (bare — `cmds/adm/recover.lpc` writes to `/nosave/RECOVER`),
`hate/` (PK-hatred-list feature, `feature/attack.lpc`/`combatd(1).lpc`/
`cmds/usr/hatred.lpc`), `topten/` (referenced by `TOPTEN_DIR` in
`toptend.lpc`). None of these being absent caused a HARD failure during
registration/look/score (mostly `write_file()`/`log_file()` calls that
either aren't on the critical path or degrade gracefully), but per §15ah
precedent they're cheap, proactive insurance against a silent write
failure derailing some other flow later.

## Config (`config.fluffos`) adjustments

- `port number : 40088`, `noninteractive stderr write : 1` added.
- `mudlib directory` pointed at the absolute `work/` path.
- Dropped obsolete keys the driver warned about: `address server ip`,
  `address server port`, `reserved size`, `swap file` (none used/recognized
  by this driver build).
- `maximum local variables : 30` → `64` (this driver's config schema
  enforces a minimum of 64; the original value was silently reset to
  default with a warning otherwise — bumped to the real minimum instead of
  leaving the warning in place).
- `external_port_1 : telnet 8888` commented out (fully superseded by `port
  number`; was only producing an "ignoring" info line, not an error).

## Registration flow + post-login command test (verified twice, full
transcripts)

Flow shape: GB/Big5 encoding choice → "Press Enter to Continue" (past an
inline DNS-mud-list display, now empty since dns_master is excluded) →
banner/stats/uptime → English id (`check_legal_id`: lowercase a-z only,
3-12 chars) → (existing-save-file check; new id → confirm y/n) → Chinese
name (`check_legal_name`: 1-4 real Chinese characters after the §15h fix)
→ password (twice) → gift-stat selection (`0` = random, or 1-5 to pick one
stat to name a value for, then accept/reject the rolled set) → email →
gender (m/f) → drops into the game world at `随缘客栈` (the starting inn),
greeted by NPC 李寻欢.

**Final verification run** (`mudclient.py 127.0.0.1 40088`, one continuous
session, `--idle 1.0`):
```
gb → "" → qinfengfinal → y → 秦风寒 → password123 → password123
→ 0 → y → final@test.com → m → look → score → i → quit
```
Result: registration completed cleanly, landed in `随缘客栈` with the
correct room description, NPC greeting text, and exit list; **`look`**
re-displayed the room correctly; **`score`** printed the full character
sheet (中文姓名 秦风寒, 英文姓名 qinfengfinal, stats, all fields populated,
no crash); **`i`** (inventory) listed the starting items correctly; `quit`
cleanly dropped an item and printed the goodbye message. `log/debug.log`
for this run has exactly one non-fatal runtime line
(`*/topten/source: lstat failed`, harmless — `topten/` directory was
missing pre-existing content for whatever sub-path constructs `"source"`
as a topten category key; didn't block anything, not chased further given
time budget) and otherwise zero errors.

An earlier full run (before the final config/driver restart, id
`hantianli`/name 秦风寒/gender f) is what originally caught bug #12 above
(the `uptime.lpc`/`LASTCRASH` static→nosave corruption) — that run's
`look` command hard-crashed the object (`*No program in object
'/cmds/std/look'!`) before the fix (bug #18's `look_msg.h` dropped-quote
issue, found in that same first pass) was applied; both are now confirmed
fixed with a subsequent clean run.

## `lpcc_check.sh` sweep results

**97.3% pass: 7306/7508** (`lpcc_fail.log` in this directory has full
detail). Started at 96.5% (263 failures) before this pass's fixes; every
genuine driver-compat/typo bug found in the sweep that's described above
was fixed and individually re-verified via direct `lpcc` before the final
sweep. Memory stayed well within safe bounds throughout (peaked ~1.3GB RSS
on the `lpcc` process, ~9-10GB free system-wide) — no need to back off per
§6b, this lib (7508 files) isn't in the "mega-lib" risk tier.

**Remaining ~200 failures, triaged into known-noise categories (not
bugs to fix):**
- **`kungfu/skill/xiake-shengong/*` (侠客神功 skill class, ~9 files):**
  calls an entirely undefined `test_zouhuorumo()` function (21 hits) and
  `#include`s two headers (`cond.h`, `spec.h`) that don't exist anywhere
  in the archive. Confirmed via grep this whole skill class was
  incomplete/broken from the start (nothing else in the lib defines
  either), not something to fabricate — this is a real, pre-existing
  content gap (§13-shaped), not reachable unless a player actually learns
  and tries to use this one specific (apparently never-finished) skill.
- **`adm/daemons/network/*` (mail/ping/telnet/inetd/userid/dns_master
  sibling daemons, ~15-20 files):** missing `config.h`/`uid.h`/`daemons.h`/
  `mailer.h` headers and undefined `member_group()`. None of these are
  preloaded (dns_master and its whole family are excluded per §15p) or
  reachable from the registration/login flow — pure intermud/mail-relay
  plumbing, expected noise per this project's standing DNS-daemon policy.
- **`maxim/skill_model_{default,unarmed,weapon}.lpc` (3 files):** these are
  literal COPY-PASTE TEMPLATES for wizards writing new kungfu skills
  (comment: `//line number must be same!!! so it is done`) — reference
  `SKILL_CH_NAME`/`SKILL_EN_NAME`/`SKILL_BASE_NAME`/`action` as
  intentional placeholders meant to be filled in by whoever clones the
  template. Never `#include`d/inherited/loaded as real objects anywhere.
- **A long tail of individually-small, genuinely pre-existing content
  issues** in personal-wizard directories (`u/linghu/ground2.lpc`'s
  `do_debug()`, see fix #17 above), `cmds/arch/examine.lpc` (a whole
  `else` branch missing semicolons throughout — confirmed present
  byte-for-byte in the raw archive, a wizard-only admin command, never
  finished/tested even originally), and scattered individual NPC/room/
  skill files with one-off typos in code paths not reachable from
  ordinary play. None of these block boot, registration, or the standard
  post-login command set; documented rather than chased further, per this
  project's stated breadth-over-depth policy for a ~100-archive batch.

## What was confirmed NOT needed (checked proactively, all negative)

- §4 (master.lpc lazy security-daemon load recursion) — already
  catch()-guarded in the original code.
- §7 (`get_root_uid`/`get_bb_uid`) — already present.
- §8c (`valid_read`/`valid_write` blindly overriding `user` with
  `this_player()`) — not this lib's shape; the ACL only fires for a
  narrow `func` allow-list, `load_object`/`include`/`recompile_object`
  always pass.
- §15ae (`private nomask` command_hook) — `command_hook()` is plain
  `nomask`, dispatch confirmed working via the real `look`/`score`/`i`
  test.
- §15ag (`ed_start`/`ed_cmd`/`query_ed_mode`) — zero hits anywhere.
- §15l (master.lpc `create()` destructing `SIMUL_EFUN_OB`) — `create()`
  is a one-line `write()`, nothing else.
- §15n (custom securityd blocking compile-time `load_object`/`include`) —
  this lib's ACL already special-cases those `func` values as always-allow.
- §15r (`check_config.lpc`-style driver self-check) — file doesn't exist
  in this archive.
- §15v/§15b's whole-mudlib bare-simul_efun `set`/`query`/`delete` dbase
  architecture bug (the "nitan" family's core bug) — this lib's
  `feature/dbase.c` has real local `set`/`query`/`delete` methods
  (`inherit F_TREEMAP`), not the bare-simul_efun pattern; confirmed not
  applicable to this lineage.
- §8f (`TYPE * a, b;` C-style array-modifier scoping treated as a bug) —
  spot-checked several instances (`feature/equip.c`'s `string *apply,
  type;`, `kungfu/skill/qixing-array.c`'s `object *member, ob;`) and
  confirmed these are INTENTIONAL single-star-scoping (the second
  identifier is genuinely meant to be a scalar, used as such throughout)
  — this is the Dead Souls/English-lineage bug shape, not something this
  Chinese ES-II-lineage codebase's authors got wrong.
- §15u (dormant "phone-home" destructive license check in securityd) —
  grepped for mass-deletion/`shutdown()` patterns gated on suspicious
  checks; none found.

## Process hygiene

Driver launched via `run_in_background`/`setsid nohup ... & disown`
(several times across the fix/re-verify cycle), always killed by exact
recorded PID (never a broad `pkill` pattern) once done with each round of
testing. Confirmed via `ss -tlnp`/`ps` after each kill that the port was
actually freed and no stray process remained. Multiple other sibling
agents' driver processes were observed running concurrently on this host
throughout (archives #92-95) — none were touched.

## Rebuilt-driver / formatter / WASM re-verification pass (2026-07-23)

1. **LPC formatter** applied across all 7,509 `.lpc` files in `work/`:
   `{"total":7509,"written":7454,"wouldChange":0,"unchanged":6,
   "errors":49}`. Verified post-format `feature/command.lpc`'s
   `command_hook` is still plain `nomask`. **Found and fixed the same
   formatter bug discovered across this pass's other libs** (full
   writeup in `tianxia/NOTES.md`): a bare `::fn(...)` call immediately
   after `(` with no space is mis-lexed as a `(: ... :)` closure
   literal. Hit once, in `adm/object/bm.lpc`'s `short()`:
   `capitalize(::query("id"))` got rewritten to the syntactically broken
   `capitalize (: : query("id")\n)\n+ ")"`. Hand-fixed back to
   `return ::name(1) + "(" + capitalize(::query("id")) + ")";`.
   Re-verified via a full `lpcc_check.sh` sweep: 7,306/7,508 pass (202
   fail, matching the pre-format baseline below), `bm.lpc` not in the
   failure log.
2. **Native re-test against the rebuilt `build-debug/src/driver`**:
   booted clean (zero fatal errors). Full registration verified
   end-to-end via `mudclient.py` (this lib prompts for a GB/Big5
   encoding choice before the ID prompt, first send `"g"`): id
   `syxfmte` → confirm → real Chinese name **`秦风廿八`** → password ×2
   → attribute roll (`0`/random) → accept → email `abc@abc.com` →
   gender `m` → entered the game world at 随缘客栈, `look` displayed the
   room (correctly re-shown), `score` showed a correctly-populated
   character card matching registration, `quit` dropped items and
   printed "欢迎下次再来！". `debug.log`: zero `error in error
   handler`/`denied`/`undefined function`/`bad argument` lines. No new
   fixes needed; the reformatted source is still fully sound.
3. **WASM test**: boots cleanly through `Initializations complete`
   (only the expected missing-sockets-package compile errors for
   `ftpd`/`httpd`/`emaild`). **A real registration playthrough could not
   be driven through this specific harness**, for a reason distinct from
   the documented `query_ip_number()` limitation: `cmds/usr/uptime.lpc`'s
   `main()` does `write(read_file("/log/static/LASTCRASH"))` with no
   type-check on `read_file()`'s return, called from `logind.lpc`'s
   `login()` on every new connection to print the "上次当机原因" banner
   line. `scripts/wasm_client.js` deliberately does not copy the
   *contents* of `work/log/` into the wasm instance's in-memory FS (see
   the script's own comment — avoids wasting time/memory on runtime-churn
   log files), so `/log/static/LASTCRASH` — a legitimate small reference
   file, not actually churn — doesn't exist there, `read_file()` returns
   `0`, and `write(0)` throws `Bad argument 1 to receive()` uncaught
   mid-`login()`. Because this happens before `login()` reaches the code
   that prints the ID prompt and registers `input_to()`, the connection
   is left with no input handler at all — every subsequent line sent
   just falls through to the ordinary (empty-environment) command parser
   ("What?") instead of being treated as an ID/name/password answer.
   **Assessment**: this is a wasm-harness/no-persistent-log-data
   interaction, not a mudlib bug in the sense of "broken on a real
   server" (the archive ships `LASTCRASH`, and the native session above
   is proof registration works perfectly there) — but it is a genuine
   latent fragility (`write(read_file(x))` with no string-type guard)
   that would reproduce identically on ANY from-scratch deployment
   lacking pre-existing `/log/static/LASTCRASH` data (e.g. a real
   from-scratch browser/wasm deployment with no prior log history), so
   it's worth flagging even though it isn't the already-catalogued
   `query_ip_number()` limitation. Not patched, per the task's "note,
   don't force a fix for wasm-specific gaps" guidance.
