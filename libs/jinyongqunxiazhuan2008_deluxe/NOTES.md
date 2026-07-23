# jinyongqunxiazhuan2008_deluxe — 金庸群侠传 (Jin Yong Heroes Gathering, deluxe)

Archive: `archives/金庸群侠传2008超豪华版.rar` ("Jin Yong Heroes Gathering 2008,
super deluxe edition"). Extracted mudlib root: `raw/jy/` (a single top-level
`jy/` directory inside the archive, same layout as archive #91). Port:
**40085**. Status: **done** (boots clean, full registration flow verified
3 times with real Chinese names, post-login `look`/`score`/`quit` verified
working each time).

## What this is / lineage (confirmed via md5sum BEFORE doing anything else)

`config.cfg`'s `name` field (GB18030-decoded: `bd f0 d3 b9 c8 ba cf c0 b4
ab` -> `金庸群侠传`) matches the archive title exactly.

**Confirmed byte-identical core engine to `jinyongqunxiazhuan2008` (archive
#91, `libs/jinyongqunxiazhuan2008/`)**, checked via `md5sum` on the raw
archives before any conversion, per the task brief's lineage-check
instruction:

| file | md5 vs #91 | md5 vs xiakexing3(#44) |
|---|---|---|
| `adm/obj/master.c` | **identical** | identical (matches #91's own prior finding) |
| `adm/single/master.c` | **identical** | identical |
| `adm/daemons/logind.c` | **identical** | identical |
| `adm/daemons/securityd.c` | **identical** | differs (matches #91's prior finding that only securityd/config differ vs xiakexing3) |
| `adm/simul_efun/chinese.c` | **identical** | identical |
| `adm/daemons/chinesed.c` | **identical** | identical |

So this archive is confirmed to be **the same underlying engine core as
#91**, exactly as the task brief predicted (title-family: xiakexing3(#44),
#91, #92, #93, #94 all share the 金庸群侠传/侠客行 lineage). Per the task's
explicit instruction, all of #91's proven fixes to these byte-identical
files were **ported directly** rather than rediscovered from scratch (see
below) — verified line-by-line via `diff` against #91's already-fixed
`work/` copies before applying each one, not assumed.

**However, this is NOT a duplicate/near-duplicate of #91's overall content**
— it's a genuinely different content snapshot on the same engine (the
same relationship as "different game version, same server software").
`diff -rq` of the two raw archives shows: file count differs (3773 raw
files in #91 vs 3811 here), and dozens of zone/NPC/room files differ
byte-for-byte between the two (`combatd.c` has different combat-formula
tuning, `chard.c`/`updated.c`/several `d/` zone files differ, several
files exist only in one archive or the other e.g. `clone/board/
mingjiao_b.c` only here, `d/mingjiao/guangmingding.c` only in #91, etc).
This matches the established `shujian2008`/`shujiantianxia` and
`zhongjidiyu`-family precedent: same engine, different content build.

**Cross-check note for later archives (per task brief)**: archive #92
(`金庸群侠传2008版.rar`, being processed concurrently by a sibling agent
into `libs/jinyongqunxiazhuan2008_std/` at the time of this writing) and
archive #94 (`金庸群侠传2015版.rar`, not yet started) were NOT
cross-checked against this lib (concurrent/not-yet-processed, per the task
brief's own caveat) — whoever processes or reviews #94 next should
`md5sum` its `adm/obj/master.c`/`adm/daemons/logind.c`/`adm/simul_efun/
chinese.c`/`adm/daemons/chinesed.c` against both #91's and this lib's raw
copies; given the pattern held for #91 vs xiakexing3 vs this lib, there's
a real chance #94 is yet another same-engine snapshot.

Small-to-medium lib: 3,811 raw files, 3,171 `.lpc`/`.c` files sweepable by
`lpcc_check.sh`.

## Fixes applied (with why) — ported from #91 after confirming applicability

For every fix below, the underlying file was diffed against #91's
pre-fix/post-fix state first; only fixes confirmed applicable (identical
buggy pattern actually present in this archive's copy) were applied. Nothing
was applied blindly on lineage-assumption alone.

1. **AGENTS.md §15h** (is_chinese / check_legal_name — GBK byte-range
   checks silently wrong under UTF-8 strings). Confirmed via `diff` that
   `adm/simul_efun/chinese.lpc` and `adm/daemons/logind.lpc` were BYTE-FOR-
   BYTE identical to #91's own pre-fix originals (not just "similar") —
   ported #91's exact fix verbatim:
   - `chinese.lpc`'s `is_chinese()`: GBK lead-byte range (`str[0] > 160 &&
     str[0] < 255`, `strlen>=2`) → CJK Unified Ideographs codepoint range
     (`str[0] >= 0x4e00 && str[0] <= 0x9fff`, `strlen>=1`).
   - `logind.lpc`'s `check_legal_name()`: byte-count bound `strlen(name) <
     2 || > 12` → character-count bound `< 1 || > 6`; dropped the
     `i%2==0 &&` even-byte-offset gate.
   - **Verified working**: real Chinese names "秦风", "秦风二", "秦风三"
     all accepted on the first try across 3 separate registration runs.

2. **AGENTS.md §15ae** (`private nomask` command-hook breaks every
   post-login command silently): `feature/command.lpc`'s `command_hook`
   was `private nomask` (same as #91); `home/command.lpc`'s copy was
   already correct (`nomask` only, no `private`) — same split as #91.
   Dropped `private` from the `feature/` copy. **Verified**: `look` and
   `score` both work correctly post-login in all 3 test runs.

3. **AGENTS.md §15t (variant 1 + variant 3, combined)**: `combatd.lpc`
   DIFFERS from #91's copy in its combat-formula numbers (this is the
   deluxe edition's own balance tuning), but the include/inherit-ordering
   bug was present in BOTH: `#include </quest/quest.h>` (absolute path
   inside angle brackets, never resolved by this driver's `inc_open()`)
   placed AFTER `inherit F_DBASE;` in source order but the file-scope
   global `quest_name` it defines textually preceded the inherit once
   included — a fatal "Illegal to inherit after defining global
   variables". Fixed identically to #91: moved `inherit F_DBASE;` above
   all `#include`s, and changed `#include </quest/quest.h>` to the quoted
   absolute form `#include "/quest/quest.h"`. **Verified**: `score` (which
   needs `combatd`) works cleanly post-fix; before the fix this would have
   thrown `*No program in object '/adm/daemons/combatd'!` exactly as it
   did in #91.

4. **The same `capitalize()`-on-`0` robustness bug in `feature/name.lpc`**:
   byte-identical to #91's pre-fix `short(int raw)` fallback (`capitalize
   (query("id"))` with no guard). Applied the identical `stringp(id)`
   guard fix. Not independently re-triggered via a live crash this time
   (the tea-house board `/clone/board/kedian_b` in this archive also has
   no `"short"` set, same as #91, so this WOULD have crashed `look` there
   without the fix — pre-emptively fixed before first boot per the task's
   explicit "apply proactively before first boot" instruction, then
   confirmed `look` works cleanly with the fix in place).

5. **`d/city/npc/guidao.lpc`'s `is_killing(who)` direct-call type
   mismatch**: byte-identical bug to #91 (`is_killing(who)` instead of
   `is_killing(who->query("id"))`). Fixed identically.

6. **The "tang"-family NPC template's `new` used as a bare variable name**:
   present identically in the same 7 files as #91 (`d/quanzhou/npc/{tang,
   tang1,tang2,tang3}.lpc`, `d/taishan/{tang2,tang3,xingtang}.lpc`).
   Renamed the local variable `new` → `newob` throughout (declaration +
   both usages) in all 7 files, exactly as in #91 — the actual `new(...)`
   efun calls are untouched.

7. **AGENTS.md §15ac (bare `SAVE_EXTENSION` instead of
   `__SAVE_EXTENSION__`)**: found in the SAME 6 files as #91 —
   `include/net/ftpdsupp.h`, `adm/daemons/network/netmail.lpc`,
   `cmds/arch/purge.lpc`, `d/quanzhou/npc/tang.lpc`, `d/quanzhou/npc/
   tang3.lpc`, `d/taishan/tang3.lpc`. Fixed identically. **Left alone**
   (same as #91): `clone/npc/meng-zhu.lpc` and `u/jackyboy/TOKEN.C`, which
   both `#define SAVE_EXTENSION ".o"` locally.

8. **`kungfu/class/mingjiao/mingjiao.h`'s string-literal-adjacent-to-
   macro-expansion syntax error** (`== HIG "明教" NOR` with no `+`
   operators): present identically. Fixed to `HIG + "明教" + NOR`. **A
   genuine divergence from #91 found here**: this archive's raw copy of
   `kungfu/class/mingjiao/mingjiao.h` ALREADY had `#include <ansi.h>` at
   the top (confirmed via the raw, pre-conversion `.c` file, not just the
   converted copy) — #91's raw copy was missing it and needed it added.
   So only the syntax-error half of #91's two-part fix applied here; the
   `<ansi.h>`-add half was already unnecessary. Also found and fixed the
   SAME syntax bug in a SECOND, separate `d/mingjiao/npc/mingjiao.h` file
   (different file, same bug, not mentioned in #91's notes — possibly #91
   didn't have this second copy hit by its lpcc sweep, or this is new
   deluxe-only content; either way it's the identical fix).

9. **`d/mingjiao/npc/changjinpeng.lpc`'s wrong absolute `#include` path**
   (`#include "/kungfu/class/mingjiao/tanzhu.h"` — doesn't exist; real
   file is `d/mingjiao/npc/tanzhu.h`): present identically, fixed
   identically (`#include "tanzhu.h"`).

10. **`d/mingjiao/npc/{fenggongying,baiguishou}.lpc`'s
    `#include __DIR__"tanzhu.h"`**: present identically in both files,
    fixed identically to plain quoted `#include "tanzhu.h"`.

11. **`d/baituo/ouyangfeng.lpc`, the same two independent pre-existing
    typos as #91**: (a) missing semicolon after `write("...")` inside a
    `switch` `case 0:` block; (b) `object me=this-player();` (subtraction
    typo for `this_player()`) in the LIVE `inquiry_map()` function. Fixed
    both. **Note**: this file also has a second, commented-out (`/* ...
    */`) copy of `inquiry_map()` containing the SAME `this-player()` typo
    at line 95 — left untouched since it's dead code inside a comment
    block, confirmed by reading the full comment span before deciding.

12. **`d/shaolin/obj/shuitan.lpc`: `ging_cost` typo for the declared
    variable `jing_cost`**: present identically at the same call site
    (`me->receive_damage("jing", ging_cost)`). Fixed identically. **Note**:
    this archive ALSO has a second, different `shuitan.lpc` at
    `d/shaolin/shuitan.lpc` (not present in #91) — checked it separately
    and confirmed it does NOT have this typo (already uses `jing_cost`
    correctly throughout) — left untouched, no fix needed there.

13. **`d/mingjiao/jmqshenmu.lpc` genuinely truncated in the raw archive
    itself**: confirmed via `diff` that this archive's raw `.c` file is
    byte-identical to #91's raw `.c` file (both 26 lines, ending mid-
    `void init() {` with no closing braces) — the exact same pre-existing
    truncation, not a conversion artifact, not something specific to this
    archive. Closed with an empty body exactly as in #91.

## New fixes found in THIS archive (not part of #91's list — genuinely new
content/bugs specific to the deluxe edition's differing files)

14. **`d/baituo/obj/bowl.lpc` and `d/baituo/npc/obj/bowl.lpc` (2 files,
    both named `bowl.lpc` in different directories, same content bug):
    `set_name("海口大碗", "bowl")`** — second argument to `set_name()`
    must be an array of id strings (every sibling file in the same
    archive, e.g. `d/baituo/npc/xiaoqing.lpc`, correctly uses
    `({ "id1", "id2" })`), but these two pass a bare string, which this
    driver's static type checker rejects (`Bad type for argument 2 of
    set_name (string * vs string)`) — the whole file failed to compile.
    Fixed to `set_name("海口大碗", ({ "bowl" }) )` in both files. Neither
    file exists in #91's archive (deluxe-only content).

15. **`d/city2/npc/zhengmen.lpc` genuinely truncated in the raw archive
    itself, in a DIFFERENT way than jmqshenmu.lpc** (missing closing
    braces mid-function rather than mid-statement): confirmed via `diff`
    that this archive's raw `.c` is byte-identical to #91's raw copy of
    the SAME file (both 77 lines, `valid_leave()`'s nested `if(dir==
    "north"){ ... } else { ... }` block and the function itself are never
    closed) — **this exact same truncation also exists, unfixed, in #91's
    shipped `work/` copy** (confirmed via `diff` against #91's raw and
    work directories — #91's own conversion never caught this one; it's
    not in #91's NOTES.md's fix list at all). Fixed here by adding the 3
    missing closing braces (traced brace depth line-by-line with a small
    Python script to get the count right — first attempt under-added by
    one brace, caught by a second `lpcc` compile and corrected). This
    file is in a side zone (`d/city2`, the imperial-palace-gate NPC/room),
    not on the tested registration/`look`/`score` path, so it wasn't a
    registration blocker either way — found via the `lpcc_check.sh` sweep,
    not a live-boot crash. **Cross-check flag**: since #91 has this exact
    same latent bug still unfixed in its shipped `work/` copy, this is
    worth a follow-up patch to `libs/jinyongqunxiazhuan2008/work/d/city2/
    npc/zhengmen.lpc` too, though that's out of scope for this archive's
    own task.
    - After the brace fix, the file compiles but its `create()` still hits
      a runtime `*Bad argument 1 to EFUN call_other() ... Got: int(0)`
      while trying to populate its `"objects"` mapping
      (`/d/city/npc/wujiang`, `/d/city/npc/bing` — both files genuinely
      exist on disk) — same shape/category as the `m_weapon`/`luguanji.lpc`
      "call_other on 0" cases below (§6b-style isolated-compile artifact,
      not chased further); the syntax fix alone is the meaningful
      improvement (file went from "doesn't compile at all" to "compiles,
      loads, one populate-step artifact identical to an established
      benign category").

## Confirmed NOT needed (byte-identical core files inherited the "not
needed" verdict from #91's own reading of the same file; independently
re-verified via `diff` that the file text is unchanged, not just assumed)

- **§4** (master's lazy security-daemon recursion): `master.lpc` identical
  to #91's already-fixed/confirmed-clean copy (`diff` against #91's
  `work/adm/obj/master.lpc` = empty). Same for §7, §8c, §15l, §15n/§15o,
  §15u, §15r, §15x, §15ao — all live in `master.lpc`/`securityd.lpc`,
  both confirmed byte-identical to #91's clean copies.
- **§15p** (DNS/intermud daemon in preload): `adm/etc/preload` has the
  same 11-entry list as #91, no `network/dns_master` — confirmed by direct
  read, not inferred from lineage.
- **§15al** (`crypt(str, 0)` footgun): `logind.lpc` identical to #91's
  already-confirmed-clean copy.
- **§8e** (`tail()` not a real efun): same single harmless hit as #91, in
  the same unused admin command `cmds/wiz/tail.lpc`.
- **§15/§15b** (simul_efun-based dbase architecture bug): confirmed this
  lib uses the same `inherit F_DBASE` architecture as #91/xiakexing3/
  rzrmud, no global `set`/`query`/`delete` simul_efuns.
- **Duplicate `inherit F_UNIQUE;` (§91's item 7)**: checked
  `d/mingjiao/npc/{yinwushou,yinwulu,yinwufu}.lpc` directly — only ONE
  `inherit F_UNIQUE;` in each file here, NOT duplicated in this archive
  (a genuine divergence from #91, where it was duplicated) — no fix
  needed.
- **A LOOKALIKE duplicate-inherit false positive, checked and confirmed
  harmless**: `clone/misc/{roommaker,objmaker}.lpc` each contain
  `inherit ITEM;`/`inherit ROOM;` 2-3 times when grepped, but on reading
  the actual file these are inside a `@OBJ_CODE ... OBJ_CODE` /
  `@ROOM_CODE ... ROOM_CODE` heredoc STRING LITERAL (a wizard tool that
  writes template `.lpc` files to disk for new objects/rooms) — not real
  compilation-unit inherits at all. Same false-positive shape as #91 (not
  flagged there either).
- **§15z** (`#define nosave static` shim): none found.
- **Uppercase `.C` files**: same 4 as #91, all `u/jackyboy/{TOKEN,
  WIZ_CLOA,CLOTH1,GLASS}.C`, already UTF-8, simply renamed to `.lpc`.

## Content gaps confirmed as real archive gaps, not bugs (AGENTS.md §13)

- `d/mingjiao/yuan/*` (9 named "yuan" NPCs — 郑七灭/王八衰/赵敏/周五输/
  吴六破/孙三毁/钱二败/赵一伤/李四摧) reference two genuinely-missing
  kungfu skill files (`xuanyuan-arrow`, `liangyi-jian`), same as #91.
- `d/mingjiao/npc/monkey.lpc` references an undefined race (`走兽`,
  "beast"), same as #91. **New in this archive**: `d/mingjiao/gudi3.lpc`/
  `d/mingjiao/gudi4.lpc` (rooms, not in #91's list) ALSO fail loading
  their room-embedded monkey NPC (`bigmonkey`) for the same undefined-race
  reason (`走兽`/`走畜`) — same root cause, different call sites.
- `d/wudang/taoyuan/{tyroad4,5,6,7}.lpc`: same confirmed ORPHANED
  early-draft duplicates of the working top-level `d/wudang/tyroad{4,5,
  6,7}.lpc` files as #91 (broken `#include`, no NPC spawns, unreferenced
  anywhere in the tree).
- `u/liujun/quest/{leftkiller,rightkiller}.lpc` reference missing skills
  (`six-chaos-sword`, `stormdance`) — wizard scratch quest content, same
  category as #91's finding (only `leftkiller` was in #91's archive;
  `rightkiller` is new here, same shape).
- `u/editer/tie-luohan.lpc`: broken/unfinished wizard scratch draft
  (garbled variable name `snamei`), same as #91.
- `adm/daemons/network/*` (11 files: `ping_q`, `mudlist_a`, `ms`,
  `userid`, `pingtcp`, `name_server`, `mail_serv`, `netmail`, `telnetd`,
  `pingd`, `inetd`): confirmed not in `adm/etc/preload` and not referenced
  by anything outside this subdirectory — dead intermud subsystem, same
  category as #91 (11 here vs #91's ~16 — this deluxe build simply ships
  fewer of these dead files). `adm/daemons/network/services/mudlist_a.lpc`
  independently has the SAME reserved-word bug as the tang-family
  (`mapping new, old;`) but it's unreachable dead code — not fixed, same
  judgement call as leaving `tail()` alone.
- `home/simul_efun.lpc`: same pure sweep artifact as #91 (stray backup
  copy in a `/home` sandbox, not the configured simul_efun).
- `clone/board/*` corrupted save data: **11 board `.o` files** fail
  `restore_object()` with either "Illegal file format" or "Invalid utf8
  string while restoring dbase" (`wudang_b`, `xingxiu_b`, `tiandihui_b`,
  `towiz_b`, `kedian_b`, `bonze_b`, `huashan_b`, `gaibang_b`, `gaibang_r`,
  `wiz_b`, `taohua_b`) — same class of pre-existing corrupted seed data as
  #91's finding (also exactly 11 boards); each board's `setup()` already
  wraps the failure gracefully, confirmed non-fatal via the live `look`
  test at `kedian_b` (which just starts empty, exactly as in #91).
- `adm/daemons/chinesed.lpc`'s `data/e2c_dict.o` restore also fails
  identically to #91 (same "Illegal file format" pre-existing corrupted
  seed data, caught non-fatally by `master.lpc`'s `preload()` wrapper).
- `d/npc/m_weapon/weapon/{m_club,m_blade,m_whip,m_sword,m_staff}.lpc`:
  same `this_player()`-is-null-during-isolated-compile §6b artifact as
  #91 (5 files, identical shape).
- **New content-gap findings, not in #91's archive**:
  - `d/city2/obj/luguanji.lpc`'s `carry_object(__DIR__"obj/diaopi")->
    wield()` fails with the same "call_other on 0" shape even though
    `diaopi.lpc` itself compiles cleanly standalone (confirmed via a
    direct isolated `lpcc` run) — same §6b isolated-compile-context
    artifact class as the `m_weapon` files, just via `carry_object()`
    instead of a direct `this_player()` call.
  - `d/city2/lilishi.lpc` references `/d/city/obj/tudao`, which genuinely
    does not exist anywhere in this archive — a real missing-content gap
    (§13), not an isolated-compile artifact.
  - `d/xingxiu/npc/btshan.lpc` references `d/xingxiu/npc/ke.lpc`, which
    doesn't exist (§13 content gap); its sibling `snake.lpc` DOES exist.
  - `d/shaolin/cangku.lpc` references `d/shaolin/obj/{jitui,jiudai}.lpc`,
    neither of which exists (§13 content gap).
  - `d/shaolin/obj/{houdian,bailongdong}.lpc` reference NPCs via
    `__DIR__"npc/..."` (i.e. `d/shaolin/obj/npc/...`), but the actual NPC
    files live one level up at `d/shaolin/npc/{seng-bing3,xiang-ke}.lpc`
    — a genuine relative-path mismatch (the NPCs exist, just not where
    these two rooms look for them). Left as a documented content/path
    bug rather than fixed, since the "right" fix (change `__DIR__` to
    `__DIR__+".."` or similar) needs a judgement call about original
    intent and this is a single side-zone, not on the registration path.
  - `d/wudang/fuzhen5.lpc` references `/u/fcxy/songqing.lpc`, which
    doesn't exist (§13 content gap; there's even a commented-out
    alternate reference in the same line via `CLASS_D("wudang")`,
    suggesting the original author knew this NPC's location was in flux).
  - `d/mingjiao/npc/yinsusu.lpc`, `d/taohua/npc/shoumu.lpc`,
    `d/xingxiu/npc/btshan.lpc` (room-self, separately from its `ke.lpc`
    NPC-population issue above) each hit a "call_other on 0" during their
    own `create()` — not individually root-caused further (side-zone
    NPCs, not on the registration/`look`/`score` path); documented as the
    same general content-gap/§6b-adjacent category.
  - `d/taohua/taohua_b.lpc` (a bulletin board) tries to `move()` itself
    into `/tmp/jungu/dating`, which doesn't exist — a genuine missing
    room/zone reference (§13).
  - `d/huashan/map.lpc`: NOT real LPC code at all — it's a plain-text
    ASCII map (confirmed via `file`: "Unicode text... with CRLF, LF line
    terminators", and its content is garbled box-drawing/tile characters,
    not a program) that happens to carry a `.c`→`.lpc` extension from the
    original archive; confirmed via grep that nothing in the tree ever
    references `d/huashan/map` as an object path — dead/inert data file,
    not a bug, not fixed.
  - `doc/build/devil.lpc`, `doc/efuns/shiwu.lpc`: unreferenced anywhere
    (grepped), genuinely-broken example/tutorial scripts under `doc/`
    (missing semicolons, a bare `do_close` where a string `"do_close"`
    was clearly intended for `call_out`) — never loaded in real gameplay,
    left as-is per the same judgement as other wizard-scratch content.
  - `cmds/usr/to.lpc` / `cmds/wiz/to.lpc` (2 files, identical bug): a
    real driver-compat compile error, NOT a content gap — `me->edit( (:
    this_object(), ({ "do_to", me, arg }) :) )` fails with "Illegal to
    use local variable in functional" (this driver forbids capturing a
    local variable inside an unbound `(: ... :)` closure literal the way
    old-style MudOS code here does it). Other `->edit()` call sites in
    this same lib (`bboard.lpc`, `mailbox.lpc`) pass a plain function-name
    symbol and `this_player()`/parameter-only args and compile fine, so
    this is specific to `to.lpc`'s particular `this_object(), array`
    calling convention. This is a real, understood bug — but it's a
    non-critical wizard/player utility command (composes a multi-line
    message via the line editor), not on the registration/`look`/`score`
    path, and fixing it correctly would require restructuring the
    closure (e.g. to a bound lambda) rather than a one-line patch, so per
    AGENTS.md's "prioritize breadth over depth" policy it's documented
    here as a known, real, unfixed compile bug rather than patched.

## Interactive test result — full registration + post-login flow

Driver booted clean (`setsid nohup ... & disown`, PID 922298, launched
from `libs/jinyongqunxiazhuan2008_deluxe/` so `log/debug.log` resolves
correctly per AGENTS.md §6). Zero fatal errors in `log/debug.log` across
the whole session — only the 2 expected non-fatal caught corrupted-
save-data errors (`chinesed`'s `e2c_dict.o`, `kedian_b`'s board data,
both documented above) and ordinary compile *warnings* ("Unused local
variable", "Illegal to declare nosave function").

Ran the full registration flow **3 separate times** in 3 separate
continuous `mudclient.py` connections, with 3 different real Chinese
names, confirming the fix is robust and not a one-off:

1. `qinfengjy` (English id) → `y` (confirm new character) → **"秦风"**
   → password → confirm → accept gift stats (`y`) → email → gender
   (`m`) → enters game world at 客店 → `look` → `score` → `quit`. All
   steps succeeded; `look` re-rendered the room cleanly; `score` showed
   the full character sheet (title 平民, age/gender/birthdate, 膂力/悟性/
   根骨/身法 stats, 精/气 bars, 食物/饮水 bars, kill count, 潜能/实战经验);
   `quit` saved and discononected cleanly with the "丢下一件布衣" message
   (unequipped default item on quit, expected).
2. `qinfengjyer` → **"秦风二"** → same full flow, same success.
3. `qinfengsan` → **"秦风三"** → same full flow, same success (this was
   the FINAL post-all-fixes confirmation run, done after the bowl.lpc/
   zhengmen.lpc lpcc-sweep fixes, to make sure nothing in the late round
   of fixes destabilized the core path).

Sample transcript (run 1, abbreviated to the state-changing prompts):
```
您的英文名字：使用 qinfengjy 这个名字将会创造一个新的人物，您确定吗(y/n)？
请输入您的高姓大名，...
您的中文名字：（accepted 秦风 first try — before §15h fix this would loop-reject forever）
请设定您的密码：
请再输入一次您的密码，以确认您没记错：
...膂力[23]， 悟性[19]， 根骨[19]， 身法[19]
您接受这一组天赋吗？
您的电子邮件地址：
您要扮演男性(m)的角色或女性(f)的角色？

目前权限：(player)
[1;36m客店[2;37;0m -
    这是一家价钱低廉的客栈，生意非常兴隆。...
    这里明显的出口是 west 和 up。
  /clone/board/kedian_b [ 没有任何留言 ]
  店小二(Xiao er)
你上次连线是从0 on Wed Dec 31 16:00:00 1969

> 店小二用脖子上的毛巾抹了抹手，说道：这位小兄弟，请进请进。
[1;36m客店[2;37;0m - (look re-rendered cleanly)
> [1m【 平  民 】[2;37;0m普通百姓 秦风(Qinfengjy)
 你是一位十四岁的男性人类，...
 膂力：[ 23]  悟性：[ 19]  根骨：[ 19]  身法：[ 19]
 <精> ■■■■...  <气> ■■■■...
 战斗攻击力 1 (+0)    战斗防御力 1 (+1)
 食物：□□□...  饮水：□□□...
 你到目前为止总共杀了 0 个人，其中有 0 个是其他玩家。
 神： 0  潜能： 99 (1%)  实战经验： 0
> 你丢下一件布衣。
因为这样东西并不值钱，所以人们并不会注意到它的存在。
当你下次连线进来时，会从这里开始。
欢迎下次再来！
```

Note (same test-script gotcha as #91): the English id must be fresh
letters-only each retry — a digit anywhere in the id (e.g. `qinfengjy2`)
gets rejected by the English-name-must-be-letters check and, since
`mudclient.py` sends its whole `--send` list regardless of prompt state,
the rejection loop consumes all the scripted follow-up sends as more id
attempts. Not a bug, just something to remember when re-testing.

## lpcc sweep

Ran 3 times across the fix-iteration cycle via `scripts/lpcc_check.sh`:

- **First sweep** (after all core-engine + content fixes ported from #91,
  before discovering the deluxe-specific bowl.lpc/zhengmen.lpc bugs):
  3104/3171 pass (97.9%).
- **After fixing bowl.lpc (x2) and a first zhengmen.lpc brace attempt**:
  3106/3171 (97.95%) — zhengmen.lpc still failed (one brace short, caught
  by a Python brace-depth trace and fixed on the second attempt).
- **Final**: 3106/3171 pass (**97.95%**), same numeric pass count as the
  second sweep since zhengmen.lpc's remaining failure mode changed from a
  hard syntax error to a benign runtime "call_other on 0" content-gap
  artifact (documented above) rather than newly passing outright.

Remaining 65 failures were triaged by category (AGENTS.md §6b), all
confirmed via direct source reading (not guessed): 11 corrupted
pre-existing board saves, 11 dead network/intermud daemon files (not
preloaded, not referenced), ~13 genuinely missing zone/skill/race/NPC
content (`mingjiao/yuan` x9, `monkey`/`gudi3`/`gudi4` undefined-race,
`wudang/taoyuan` x4 orphaned drafts, `lilishi`→`tudao`, `btshan`→`ke`,
`cangku`→`jitui`/`jiudai`, `fuzhen5`→`songqing`, `taohua_b`→missing
`/tmp/jungu/dating`), 3 wizard-scratch quest/tool files (`u/liujun/
quest/{left,right}killer`, `u/editer/tie-luohan`), 1 dead-code-only
reserved-word bug (`network/services/mudlist_a.lpc`, unreachable), 1
sweep artifact (`home/simul_efun.lpc`), 1 known-unfixed-efun hit
(`cmds/wiz/tail.lpc`, §8e), 2 non-content-gap real driver-compat bugs
left unfixed as non-critical (`cmds/usr/to.lpc`/`cmds/wiz/to.lpc`'s
closure-capture error), 2 non-LPC/dead data files (`d/huashan/map.lpc`,
plus the 2 `doc/` example scripts), 6 §6b isolated-compile-context
artifacts (5 `m_weapon` files + `luguanji.lpc`'s `carry_object()->
wield()`), a path-mismatch pair (`houdian`/`bailongdong` → their own
`npc/` subdir that doesn't exist), and `zhengmen.lpc`'s now-syntax-clean
but still content-gap-flavored remainder. None of these affect
registration, `look`, or `score` — all confirmed via direct source
reading, not guessed.

Memory stayed healthy throughout all 3 sweeps (`free -h` showed ~11-19GB
available before/after each run, well clear of pressure; no other
`lpcc`/driver sweeps were running concurrently at sweep time).

## Process notes

- Driver launched via `setsid nohup ~/src/fluffos/build-debug/src/driver
  config.fluffos > boot_stdout.log 2>&1 & disown` from within
  `libs/jinyongqunxiazhuan2008_deluxe/` (required for `log/debug.log` to
  resolve correctly, per AGENTS.md §6). Booted once, kept running through
  all 3 registration tests and both post-fix lpcc sweeps (the later
  bowl.lpc/zhengmen.lpc fixes only affect side-zones never visited by the
  live driver session, so no reboot was needed to validate them — the
  `lpcc_check.sh` sweep independently re-reads files from disk each run).
  Killed by its own exact PID (922298) at the end — verified gone via
  `ps -p` and `ss -tlnp` no longer showing port 40085 — never used a
  broad `pkill` pattern (per the explicit standing warning about other
  agents' concurrent drivers sharing the same command line).
- Scratch files (`boot_stdout.log`, `lpcc_batch_raw.log`) removed from
  the lib's top-level directory before finishing, per instructions; kept
  `lpcc_fail.log` (matches #91's own convention of keeping this one file).
- Port 40085 chosen per the task brief's explicit instruction (40084
  reserved for the concurrent archive #92 agent; TODO.md's own "next
  free port" counter said 40084 at the time this task started, so 40085
  is the next port after that reservation).
