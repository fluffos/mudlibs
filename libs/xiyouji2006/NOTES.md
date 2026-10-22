# 西游记2006之 最终幻想.rar → `xiyouji2006`

- **Archive**: `archives/西游记2006之 最终幻想.rar` (archive #82). Extracted root:
  `西游记2006/` (the archive's own top-level folder), containing
  `使用说明.txt`/`重要说明.txt`/`mud游戏网.url` at that level plus the actual
  mudlib nested one level further at `西游记2006/world/`. Config:
  `world/config.cfg` (MudOS 0.9.20 format, standard `key : value` layout).
  Bundled `MudOS.exe`/`mudos.prf`/`MudOS.log` (a prebuilt Windows driver +
  its own prior run's log) sit alongside the LPC source — ignored per
  convention, our own `build-debug` driver is used throughout.
- **Self-identified name — THREE different names found, worth flagging
  explicitly**: `config.cfg`'s `name :` field reads simply `西游记2006`;
  the live ASCII banner brands it `西游记2006 之 最后的疯狂` ("Journey to
  the West 2006: The Final Madness") — **not** "最终幻想" ("Final
  Fantasy") as the archive's own filename claims; and a message-of-the-day
  notice shown to every new player reads "本游戏正式更名为《大唐西游》"
  ("This game has been officially renamed to *Great Tang's Journey to the
  West*"). All three are genuine, verified live via the interactive test
  transcript below — not a conversion artifact. Slug `xiyouji2006` kept
  per the task's port assignment, consistent with the project's
  established practice of keeping the archive-derived slug even when the
  in-game brand differs (same pattern as `xiyouji2003`/`shenmo`).
- Site: "AKAI Studio 巫师小组" (`akailee@163.com`,
  `http://akailee.myrice.com/`). The banner explicitly brands itself
  `Tomud版` ("Tomud edition") — matches the hidden client-version gate
  found in `logind.lpc` (see §15q finding below).
- Port: **40077** (per the task's explicit assignment — 40076 was
  reserved for archive #27's concurrent agent at the time this pass
  started; TODO.md's own ledger said 40076 was next-free).

## Lineage: confirmed a genuine, independently-evolved member of the mhxy/梦幻西游/shenmo family — NOT a duplicate of any already-processed sibling

Per the task's explicit instruction, all 5 already-done Journey-to-the-
West-themed siblings' NOTES.md were read first
(`libs/xyj2000f/NOTES.md` #15, `libs/mhxy/NOTES.md` #19,
`libs/mhxyqd/NOTES.md` #56, `libs/shenmo/NOTES.md` #73,
`libs/xiyouji2003/NOTES.md` #81), then this archive's `adm/obj/master.c`,
`adm/simul_efun/chinese.c`, `adm/daemons/logind.c`, `adm/daemons/securityd.c`,
`adm/daemons/named.c`, `adm/daemons/chinesed.c`, `adm/daemons/convertd.c`
were md5sum'd/diffed against the corresponding raw files of `mhxy`(#19)/
`mhxyqd`(#56)/`shenmo`(#73)/`xyj2000f`(#15)/
`xiyouji2003`(#81) **before any conversion work began**.

**Findings, by file** (raw pre-conversion bytes):

- **`adm/simul_efun/chinese.c`**: **byte-identical** (same md5,
  `c7c5c596de4edc6f8164d757de3cb3c9`) to `mhxy`(#19) AND `shenmo`(#73)'s
  copies — same `is_chinese()` GBK-byte-range shape
  (`str[0]>160&&str[0]<255`), same `chinese_number()`/`to_chinese()`
  delegating to `CHINESE_D`. This is the single strongest piece of
  evidence tying this archive to the mhxy/梦幻西游/shenmo branch
  specifically (as opposed to the `xyj2000f`/`xiyouji2003` side
  of the wider "西游记" family tree, whose `chinese.c` implementations
  are shaped differently — confirmed via the diff done for
  `xiyouji2003`'s own lineage writeup).
- **`adm/obj/master.c`**: own hash, differs from ALL compared siblings —
  but a stripped-comment structural diff against `xyj2000f`'s
  copy shows this file's ~237 lines of live logic are a genuine SUBSET of
  `xyj2000f`'s 341-line version (same `connect()`/
  `compile_object()`/`crash()`/`log_error()`/`standard_trace()` core
  shapes, same `log_file("static/CRASHES", ...)` idiom) — missing several
  later-added features (`print_vars()`/`report_error()`/the
  `error_handler()`'s wizard-vs-player trace-detail branching/`valid_read`
  delegating to `SECURITY_D`). This reads as an EARLIER/leaner snapshot of
  the same overall ES-II-derived "西游记" master.c lineage that both the
  `xyj2000f` and `mhxy` branches trace back to (matches
  `xiyouji2003`'s own observation of a "much older shared root" beneath
  the branch point) — not a byte match to either specific sibling.
- **`adm/daemons/logind.c`**: own hash; ~1168 lines (UTF-8-converted),
  same overall registration shape as `mhxy`'s copy (gb/big5 →
  `if_young` → English id ("new" to register) → Chinese name → super
  password → login password → confirm → email → gender → auto-gift →
  `enter_world`), same `check_legal_name()` byte-doubled-bound shape
  (`< 2 || > 12`, "一到六个中文字", `i%2==0 && !is_chinese(...)`) as
  `mhxy`'s PRE-fix original — but substantially different in the details
  (this copy carries its own `by canoe`-credited anti-reconnect-flood
  block, a `TMI()`/`tomud.h` client-protocol layer, and the `"2060"`
  client-version gate described below, none of which are present in
  `mhxy`'s copy). The raw archive also ships `u/canoe/` and `u/vikee/`
  wizard home directories — `vikee` is the same cracker credited in
  `xyj2000f`'s `master.c` header — suggesting this specific
  snapshot passed through (or was cross-pollinated by) people from BOTH
  sides of the wider "西游记" family tree, consistent with it being its
  own distinct fork rather than a clean descendant of only one branch.
- **`adm/daemons/securityd.c` / `named.c` / `chinesed.c` / `convertd.c`**:
  all own hashes (differ from every compared sibling) — but `convertd.c`
  carries the exact same §8h "Greek-alphabet lookup table, stray
  trailing backslash before the closing quote" defect (45 occurrences),
  the same secondary evidence of a shared distant ancestor for that one
  daemon specifically that `xiyouji2003` already found linking it to
  `mhxy`/`xyj2000f`.

**Conclusion**: this is a genuine, independently-evolved 2006-era
snapshot sharing a confirmed-byte-identical `chinese.c` with the
mhxy/梦幻西游/shenmo branch specifically, while also showing cross-
pollination evidence (the `vikee` credit, the leaner master.c) from the
wider ES-II "西游记" family that `xyj2000f`/`xiyouji2003`
belong to — **not a duplicate of any of the 5 siblings compared**. Per
the task's instruction to port proven fixes directly when related: the
§15h `is_chinese`/`check_legal_name` fix pattern and the §8h `convertd`
fix were both ported near-verbatim (this lib's own pre-fix code was
confirmed byte-identical or structurally identical to the sibling
precedent before editing); everything else was discovered fresh from
this archive's own source.

## Status: DONE — boots clean, full registration + post-login-command flow verified in THREE independent continuous connections

## Scale

11,857 raw files → 9,265 `.lpc`/`.h` files after conversion, 263MB total
— an ordinary-sized lib (comparable to `mhxy`'s 14,563 files), not a
mega-lib; the full `lpcc_check.sh` sweep was run to completion (not
skipped per §6b).

## Conversion

`scripts/convert_lib.sh libs/xiyouji2006/raw/西游记2006/world libs/xiyouji2006/work`:
GB18030→UTF-8, `.c`→`.lpc` rename (9264 files), literal `".c"` reference
fixes (0 remaining afterward), local angle-bracket `#include <x.h>` →
`"x.h"` conversion, `static`→`nosave`. One uppercase-`.C` file found and
renamed manually (`daemon/skill/xiaofeng-sword/HAMMER.C` — `find . -name
"*.C"` checked proactively per the `shenmo`-derived catalog entry; no
stray `.c"` references needed fixing for it).

**A stronger post-conversion validity check than the standard "file-
heuristic stragglers" grep was needed and is worth adding to the
catalog**: the usual `file -b "$f" | grep -qE "text|script|empty"`
straggler check caught only 1 hit (`d/qujing/start/24/12.lpc`, the
same known `file`-heuristic false-positive already documented on
`shenmo`/`mhxyqd` — confirmed valid UTF-8). But running
`iconv -f UTF-8 -t UTF-8` against **every** `.lpc`/`.h` file (not just
the ones `file` flags as non-text) found **2 more genuinely-unconverted
files** that `file` happily classified as generic 8-bit "text":
`d/sea/npc/beast1.lpc` and `d/obj/quest/shuijingqiu.lpc`. Root cause,
confirmed by inspecting the RAW pre-conversion `.c` bytes directly: both
files have genuine **pre-existing byte corruption near end-of-file** in
the original archive (not introduced by our pipeline) that makes a plain
`iconv -f GB18030 -t UTF-8` fail outright with "illegal input sequence" —
`beast1.c` has a stray 2-byte `0xff 0xba` sequence sitting immediately
after the file's final, otherwise-clean `}` (zero real content lost by
dropping it); `shuijingqiu.c` has messier ~18 bytes of corruption that
truncates mid-statement inside `do_locate()`'s final `else` branch
(`"/adm/daemons/questd"->locate_quest(this_player(),arg` then garbage,
no closing `);`/`}`). **Fixed**: `beast1.c` — truncated the raw file at
the exact byte offset immediately before the 2 stray bytes, then
converted normally (verified via `iconv -f UTF-8 -t UTF-8` on the result).
`shuijingqiu.c` — converted the salvageable portion with `iconv -c`
(lossy), then manually completed the one truncated statement using the
obvious, mechanically-implied completion pattern from an identical call
shape a few lines earlier in the SAME file
(`"/adm/daemons/questd"->locate_quest(this_player(),arg);` + `return 1;
}`) — a minimal reconstruction of pre-existing corrupted content, not
fabricated new functionality (matches the precedent set in AGENTS.md's
Encoding section for reconstructing a dropped closing-quote/tag from
context). **Recommend adding to AGENTS.md**: run the full
`iconv -f UTF-8 -t UTF-8` validity check against every `.lpc`/`.h` file
unconditionally (not gated on `file`'s classification at all) on future
libs — `file` can misclassify genuinely-corrupt/unconverted 8-bit text as
generic "text" just as readily as it misclassifies valid UTF-8.

## Fixes applied (in order found, with why)

1. **§3 counterexample — `"static/..."` log-path string-literal
   collision**: this lib uses `log_file("static/CRASHES", ...)` /
   `log_file("static/security", ...)` etc. as a pre-existing subdirectory-
   naming convention (23 files: `adm/obj/master.lpc`,
   `adm/daemons/securityd.lpc`, `adm/daemons/questd.lpc`,
   `cmds/usr/suicide.lpc`, `cmds/wiz/call.lpc`, `cmds/wiz/clone.lpc`,
   `cmds/adm/{xpass,superpass}.lpc`, `cmds/arch/{purge,purgehouse}.lpc`,
   several `u/*/lwbook.lpc`/`zaoshen.lpc` copies, etc). The blanket
   `\bstatic\b`→`nosave` sed corrupted all 23 to `"nosave/..."`. Reverted
   with a targeted `sed -i 's/"nosave\//"static\//g'` scoped to the 23
   flagged files; verified 0 `"nosave/` string-literal hits remain and all
   23 `"static/` literals restored. Checked for the §15z variant
   (`#define nosave static`/`#define protected static` shim) — none
   present, nothing to revert there.
2. **§15h, `is_chinese()` GBK byte-range bug** — `adm/simul_efun/chinese.lpc`
   (confirmed byte-identical to `mhxy`/`shenmo`'s pre-fix originals):
   `if( strlen(str)>=2 && str[0] > 160 && str[0] < 255 ) return 1;` → CJK
   Unicode codepoint range check, `str[0] >= 0x4e00 && str[0] <= 0x9fff`,
   `strlen>=1`.
3. **§15h, `check_legal_name()` in `adm/daemons/logind.lpc`**: byte-
   doubled bound `strlen(name) < 2 || > 12` (message text says "一到六个
   中文字" — 1 to 6 Chinese characters) → halved to `< 1 || > 6`; dropped
   the `i%2==0 &&` alternating-byte-position gate on the per-character
   `is_chinese(name[i..<0])` check.
4. **§8h, `adm/daemons/convertd.lpc`'s Greek-table stray-trailing-
   backslash typo** — 45 occurrences, CRLF line endings (confirmed via
   `file -b`), fixed with the established CRLF-aware pattern
   `s/\\"(,)?\r?$/"\1\r/`. **Also found and fixed the identical bug in an
   orphaned, never-loaded duplicate copy** at the bare top-level
   `daemons/convertd.lpc` (as opposed to the real, preloaded
   `adm/daemons/convertd.lpc`) — confirmed via grep that nothing
   references this bare-path copy anywhere (same "orphaned duplicate
   tree" shape as the `daemons/network/ms.lpc` vs
   `adm/daemons/network/ms.lpc` pair described below); fixed anyway since
   it was free.
5. **§14, `valid_override()` upgraded to the 3-arg form** in
   `adm/obj/master.lpc` — added the `main_file` parameter and
   `main_file==SIMUL_EFUN_OB||main_file==MASTER_OB` to the allow
   condition. Applied proactively per the catalog's "free fix" guidance;
   never observed to matter in the actual boot/test here either.
6. **§15w, `master.lpc`'s `log_error()` broadcasting every compile
   WARNING (not just real errors) to the connected player** — was
   unconditional `if(this_player(1)) efun::write("编译时段错误：" +
   message+"\n");`. Fixed by gating on the message NOT containing
   `"warning:"`. Confirmed the fix works: both full registration
   transcripts below are completely free of `编译时段错误` spam despite
   `debug.log` recording hundreds of ordinary compile warnings
   (`Unknown #pragma, ignored` — this lib's own `#pragma`s aren't
   recognized by this driver — `Unused local variable`, etc.) during the
   very same sessions' lazy compiles.
7. **§8d/§15o, `master.lpc` missing `get_include_path()`** — added the
   standard implementation (same-directory + `:DEFAULT:` fallback).
   4908 files use the local `#include <x.h>`-angle-bracket idiom
   remaining after `convert_lib.sh`'s automatic local-include-to-quote
   pass already converted a smaller subset; this master apply is
   insurance for the rest, reached only mid-connection. The full
   boot+registration+gameplay test produced **zero** `Cannot #include`
   errors on the tested path.
8. **§15p, DNS/intermud daemon preload exclusion** — removed
   `/adm/daemons/network/dns_master` from `adm/etc/preload` (25→24
   entries) per standing project policy.
9. **§15t sub-bug 1, absolute-path angle-bracket `#include`s (4 files)**
   — `#include </abs/path/to/header.h>` (angle brackets around an
   already-absolute path never resolves on this driver, even with
   `get_include_path()` present, since angle-bracket resolution only
   searches the configured include-path list, not an arbitrary absolute
   name) → converted to quoted form `#include "/abs/path/to/header.h"`
   in: `d/obj/misc/jitan.h`, `d/obj/books-nonskill/book-qujing.lpc`,
   `d/qujing/wudidong/monk1.lpc`, `u/vikee/dntg10/sky/tongmingdian.lpc`.
   **This was the exact, concretely-observed bug behind the ONE runtime
   error seen in the live interactive test** (see below):
   `book-qujing.lpc`'s `#include </d/qujing/obstacle.h>` failed to
   resolve, leaving the file permanently uncompilable
   (`*No program in object '/d/obj/books-nonskill/book-qujing'!`),
   which broke NPC `/d/city/npc/jieding`'s `create()` (tries to
   `carry_object()`/`new()` that book) — caught by the room's own
   preload/reset `catch()`-equivalent, so `look` still worked and showed
   the room correctly, just with this one error line printed first.
   Confirmed fixed: the file no longer appears in the `lpcc_check.sh`
   failure list after the fix (was previously failing with "Cannot
   #include obstacle.h").
10. **§15t sub-bug 2, one `..`-relative `#include`** —
    `d/ourhome/honglou/npc/niu.lpc`: `#include "../honglou.h"` (this
    driver disallows `..` in include paths entirely, a security boundary)
    → resolved to the real absolute quoted path,
    `#include "/d/ourhome/honglou/honglou.h"` (confirmed the target
    actually lives there).
11. **§10, missing-closing-quote typo** — `d/moon/obj/poem.lpc`: 2 string
    literals in a poem array were missing their closing `"` before the
    trailing comma (`"...留在广寒宫阙。,` / `"...黄昏却下潇潇雨。,` →
    `"...留在广寒宫阙。",` / `"...黄昏却下潇潇雨。",`), found via the lpcc
    sweep's "Illegal character" hits landing mid-Chinese-text (not a
    standalone-punctuation §9 case) — confirmed a genuine pre-existing
    authoring typo (not an encoding artifact) by checking the raw bytes
    decode identically.
12. **`log/static/` seed directory** (§15ah-shaped pattern) — the raw
    archive's `log/` directory had no `static/` subdirectory, but 23
    files (see item 1) call `log_file("static/XXX", ...)`; created
    `work/log/static/` proactively before the first boot to avoid a
    silent write failure. Confirmed no "Wrong permissions"/"No such file
    or directory" for this path anywhere in `debug.log` across all test
    sessions.
13. **`libs/xiyouji2006/log/` directory** created at the top level
    (sibling of `config.fluffos`, per §6 — `log directory` resolves
    relative to the driver's actual launch CWD, not the mudlib virtual
    root). The very first boot attempt (launched correctly from
    `libs/xiyouji2006/`) silently produced **no** `debug.log` at all until
    this directory existed — confirmed the standard non-fatal failure
    mode described in §6, not a new symptom.

## What was checked and confirmed NOT needed (verified by reading the actual source, not assumed from sibling precedent)

- **§4 (master.lpc `load_object()`-in-`valid_read`/`valid_write`
  recursion)**: `valid_write` only does
  `if (ob = find_object(SECURITY_D)) return (int)SECURITY_D->valid_write(...); return 0;`
  — no `load_object()` call, returns DENY (not recursion) if securityd
  isn't loaded yet (never observed, since securityd is first in
  preload). `valid_read` is a bare `return 1;` — doesn't even consult
  securityd. No recursion risk at all; confirmed by a completely clean
  boot with zero `Too deep recursion`/`Object cannot be loaded during
  compilation` anywhere in `debug.log` across 3 full test sessions.
- **§7 (missing `get_root_uid`/`get_bb_uid`)**: both present and correct
  in `master.lpc`.
- **§15l (`master.lpc create()` destructing `SIMUL_EFUN_OB`)**:
  `create()` is a single `write("master: loaded successfully.\n");` line
  — no `destruct()` call anywhere in it.
- **§8c/§15n (custom `securityd.lpc` ACL blocking mid-connection
  `load_object`/`include`, or a `this_player()`-override footgun)**:
  `securityd.lpc`'s `valid_read()` already has the correct shape (matches
  `mhxyqd`/`shenmo`'s confirmed-fine pattern exactly) — early-
  returns `1` for any `func` OTHER than
  `read_file`/`file_size`/`stat`/`read_bytes`/`tail`/`ed_start`, so
  `load_object`/`recompile_object`/`include` are never subjected to the
  ACL table at all. No `this_player()`-override reassignment pattern
  found either (grepped, zero hits). **Additionally**, `master.lpc`'s OWN
  `valid_read` doesn't even delegate to `securityd` (bare `return 1;`),
  so this ACL is only reachable via `valid_write` for actual data-
  modifying operations — even less exposure than the already-safe sibling
  shape. Confirmed empirically: zero `Read access denied` anywhere across
  all test sessions.
- **§15 / §15v (bare simul_efun-based `set`/`query`/`delete` dbase
  architecture bug, the nitan/NT/Lonely-family's signature issue; and a
  `LONELY_IMPROVED`-style always-on efun-family gate)**: does NOT apply
  — `feature/dbase.lpc` defines real, local `set(string prop, mixed
  data)`/`varargs query`/`delete`/`add` methods (confirmed by reading the
  file), same architecturally-correct shape as the whole
  mhxy/mhxyqd/shenmo family. No `LONELY_IMPROVED` macro exists
  anywhere in `include/*.h` either.
- **§8e (missing `tail()` efun)**: zero call sites anywhere in the lib
  (`grep -rln '\btail('` → 0 hits) — genuinely absent, nothing to fix.
- **§15ag (`__OLD_ED__`/`ed_start`/`ed_cmd`/`query_ed_mode`)**: zero
  references anywhere in the lib.
- **§15ai (a DNS-gate calling `shutdown(1)` unconditionally once
  `dns_master` is excluded from preload)**: `logind.lpc` has **zero**
  references to `DNS_MASTER` at all (confirmed via grep) — the specific
  gate found on `xiyouji2003`'s `encoding()` function doesn't exist in
  this fork's `logind.lpc`.
- **§15aj (missing mandatory gift/first-room object)**: `/d/wiz/init.lpc`
  (the "choose your gift" stat-allocation room `enter_world()` moves
  every new character to) exists in the archive and works correctly —
  confirmed present via `find` before testing, and confirmed live: both
  test characters below correctly passed through its stat-reroll/confirm
  minigame (`选择[9]则接受当前的设置` → `y` confirm) before landing in
  the real starting room.
- **§15al (`crypt(str,0)` fresh-random-hash bug)**: read
  `get_super_password`/`confirm_super_password`/`new_password`/
  `confirm_password`/`get_passwd` in full — passwords use the standard
  create-once/verify-against-stored-hash pattern (`crypt(pass,0)` only at
  initial set, ALL subsequent checks use `crypt(pass, stored_hash)` where
  `stored_hash` is a real string salt) — not the vulnerable repeated-
  fixed-challenge shape from the 指间mud-protocol precedent (there is no
  client-challenge/response handshake in this lib at all). Confirmed
  working empirically: the same super/login password pair verified
  correctly across the registration flow (set → confirm → later
  implicitly re-derivable) with no rejection.
- **§15aa (same-named `message()` wrapper calling itself before its own
  definition)**: `adm/simul_efun/message.lpc` defines
  `message_vision`/`tell_object`/`tell_room`/`shout`/`write`/`say` but has
  **no local override of `message()` itself** — every call goes straight
  to the real efun, so this bug's precondition doesn't exist here.
- **§15s (2-arg `tell_room()` passing a raw `int 0` into `message()`'s
  4th arg)**: `tell_room(mixed ob, string str, object *exclude)` passes
  `exclude` straight through even when unset/default in many call sites
  (e.g. `enter_world()`'s "XXX连线进入这个世界" broadcast) — matches the
  bug's shape, but per `shenmo`'s precedent (same driver build) this
  driver's `f_message()` tolerates a raw `0` in that argument slot
  gracefully. Not independently re-verified against the efun source this
  pass (time budget); confirmed non-issue empirically instead — zero
  heartbeat/broadcast crashes across 3 full test sessions including
  exactly this call path.
- **§15u (dormant phone-home license check)**: grepped
  `securityd.lpc`/`master.lpc` for suspicious
  `destruct`/`unlink`/`rm`/`shutdown`-gated-on-opaque-check patterns;
  none found.
- **§8f (`TYPE * name1, name2;` comma-decl bug)**: an English/Dead-Souls-
  specific authoring habit, not checked here — not applicable to this
  Chinese-wuxia-lineage lib and not surfaced by the lpcc sweep's error
  categories.

## Known, not fixed (peripheral lpcc-sweep failures, `§13`/`§8g` "breadth over depth")

Final: **9016/9265 lpcc pass (97.3%)**. The 249 failures break down into
a small number of shared root causes, all confirmed off the tested
boot/registration/gameplay path:

1. **~220 of 249 (88%) — one shared `§8g`-shaped fragment-include
   cascade**: `d/kaifeng/npc/quest.lpc` is a shared code fragment meant to
   be `#include`d (not `inherit`ed) into real NPC files via a matching
   `quest_XX.h` counterpart (e.g. `d/kaifeng/npc/yulan.lpc` does
   `inherit NPC; #include "quest_wr.h"`); its own `setup()` calls
   `::setup()` expecting an inherited base class that only resolves once
   the fragment is textually merged INSIDE a real NPC object. The ~50
   sibling `quest_XX.lpc` files (all standalone-renamed from `.c` by our
   pipeline; confirmed via grep that NONE of them is ever
   `inherit`ed/`load_object()`'d anywhere as an object in its own right)
   are not valid standalone objects and were never meant to be —
   produces "Unable to find the inherited function 'setup'" (55),
   "Undefined function query" (110, 2 per file — `quest.lpc` calls a bare
   `query()` expecting the eventual NPC host), "Type mismatch/Bad
   assignment ... id" (55+16) when `lpcc` tries to compile them directly.
   Confirmed harmless in real gameplay (only the `.h` counterparts are
   ever `#include`d into real NPCs).
2. **A distinct, narrower content gap in the SAME quest subsystem**:
   `d/kaifeng/npc/quest_wr.h` (and siblings `quest_kl.h`/`quest_gv.h`/
   `quest_fd.h`/`quest_ak.h`) do `#include <quest.h>` (angle bracket)
   expecting a same-directory `quest.h`, but only `quest.lpc` (originally
   `quest.c`) exists in `d/kaifeng/npc/` — no `quest.h` was ever shipped
   for this specific zone (confirmed: `quest.h` DOES exist in two OTHER
   zones, `d/g_quest/quest.h` and `d/obj/quest/quest.h`, just not here) —
   a genuine pre-existing content/naming inconsistency in the original
   archive. Affects `d/kaifeng/npc/old/*.lpc` (explicitly named "old" —
   superseded content) and duplicates under `u/yesi/leitai4/npc/old/`.
   Not fixed per §13 (don't fabricate missing content — duplicating
   `quest.lpc` as `quest.h` risked silently double-defining symbols
   elsewhere via double-inclusion).
3. **`daemons/network/ms.lpc`** (and its byte-identical, likewise never-
   preloaded twin `adm/daemons/network/ms.lpc`) — an incomplete/orphaned
   intermud-mail daemon missing 4 header files entirely
   (`config.h`/`mailer.h`/`daemons.h`/`uid.h`), genuinely absent from the
   archive. Not on preload, not reachable from the tested path.
4. **`soldier_skill.h`** missing for `d/penglai/_._/xueshanhufa{3,6}.lpc`
   (7 occurrences) and **`flowers.h`** missing for `lestat/hua.lpc`/
   `lestat/huaxian.lpc` (3 occurrences) — isolated peripheral zone
   content gaps.
5. Scattered single-digit "Undefined function"/"Undefined variable" hits
   (`member_group` 4, `data_netmail_file` 4, `THIS_MUD` 2,
   `SAVE_EXTENSION` 2 — the bare-macro variant of §15ac, isolated to
   peripheral files, `logind.lpc` itself correctly uses
   `__SAVE_EXTENSION__`) and a handful of syntax-error clusters in
   isolated non-critical files — not triaged individually given the
   overall pass rate and time budget.

## Registration + post-login-command test — full transcripts, run 3 times

Read `adm/daemons/logind.lpc`'s full `input_to` callback chain
(`logon`→`encoding`→`if_young`→`get_id`→`get_id1`→`get_new_id`→
`confirm_id`→`get_name`→`get_super_password`→`confirm_super_password`→
`new_password`→`confirm_password`→`get_email`→`get_gender`→
`confirm_gift`→`enter_world`) before scripting any test, per the standing
policy of never inferring a flow from prompt text alone.

**Two hidden gates found by reading the code, neither guessable from the
prompt text**:

- **§15q — a literal client-protocol-version gate disguised as the
  ordinary "your English name" prompt**: `if_young("no", ob)` (called
  directly — the actual "are you a student" y/n question is dead/
  commented-out in this build) writes `请给我...您的英文名字：（新玩家请
  键入 new 注册）` then calls `input_to((: get_id :), ob)`, but `get_id`'s
  body is `if( arg!="2060" ) { <"wrong client, disconnect"> } else
  input_to("get_id1", ob);` — the FIRST input must be the literal string
  `"2060"` (a "Tomud"/笑傲江湖-client handshake code — same literal value
  independently found on `xyzx3`, archive #48, suggesting this
  specific magic string is shared convention across several
  Tomud-branded forks, not lib-specific), silently unrelated to whatever
  real id the player types next. Only after that does `get_id1` do the
  actual id/`"new"` handling.
- **A "choose your gift" stat-allocation minigame hosted in
  `/d/wiz/init.lpc`** (reached because `confirm_gift()` unconditionally
  sets `no_gift=1` for every new character): presents a
  体格/根骨/悟性/灵性 (Physique/Bone/Wit/Spirit) stat table and prompts
  `请选择你想重新设置哪一项天赋的取值[0-3]，选择[9]则接受当前的设置：` —
  sending `9` (accept current values) then triggers a SECOND confirm
  prompt, `你确定接受当前的天赋设置吗？[y/n]`, requiring one more `y`
  before `enter_world()` actually runs. (First test attempt sent `look`/
  `score`/`quit` immediately after `9` without realizing this 2-step
  shape — they were silently consumed as invalid menu/y-n answers,
  re-prompting the same question in a loop; not a driver bug, a test-
  script oversight, corrected on the next attempt.)

**Login-password rules** (read from `check_legal_password()`, distinct
rules for the two passwords): the super/admin password needs ≥7 chars,
at least one uppercase, one lowercase, AND at least one non-letter
character, and must not contain (or be contained in) the chosen id as a
substring; the ordinary login password only needs ≥5 chars and must
differ from the super password. Email must contain both `@` and `.`.

### Run 1 — id `qinfeng`, name 秦风 (male)

```
2060 → new → qinfeng → 秦风 → Passw0rd! → Passw0rd! → mypass123 →
mypass123 → qinfeng@example.com → m → 9 → y → look → score → quit → y
```

Reached the real game world ("只见眼前霞光一闪，你已经来到了一个陌生的世界"),
landed in `/d/city/zhuque-s1` (a "朱雀" city-gate room). `look` printed the
room correctly but ALSO surfaced the one genuine runtime bug found this
pass (fixed afterward, see item 9 above):
```
执行时段错误：*No program in object '/d/obj/books-nonskill/book-qujing'!
程式：/std/char/npc.lpc 第 14 行
物件: /d/city/npc/jieding
```
non-fatal (caught by the room's own preload chain), `look`'s own room
description/NPC list still rendered fully and correctly around it.
`score` produced a complete, correct character sheet (真实姓名 秦风
(Qinfen), 体格/根骨/悟性/灵性 20/20/25/25, 年龄十四, 性别男性, etc). This
run's `quit` was not carried through to completion (test script ended
before reaching the new-account keep/discard gate).

### Run 2 — id `qinchuan`→(retried as `linfeng`), name 林风 (female)

(First attempt in this run reused `qinfeng` — already registered from Run
1 — producing an expected "already taken" rejection cascade; not a bug,
a test-script mistake, corrected with a fresh id.)

```
2060 → new → linfeng → 林风 → Passw0rd! → Passw0rd! → mypass456 →
mypass456 → linfeng@example.com → f → 9 → y → look → score → quit → y
```

Landed in `/d/city/sanmen` area, reached `南城客栈` ("South City Inn" —
the real, correctly-selected starting room) via the corridor. `look`
rendered the room, NPC list (千里眼/唐三藏/店小二/阿凯哥哥/环境判官/board),
and exit list correctly with **zero errors this time** (a different
random room this run, didn't hit the `book-qujing` NPC). `score` showed
the correct gender-specific title (`【 少 女 】` — "young lady", matching
the chosen `f` gender) and full correct stat sheet for 林风(Linfeng).
`quit` correctly triggered the new-account retention gate:
```
由于您的账号是新建的，为了减少系统开销．．．
游戏规定必需连线一小时以上才可存档！
您决定想要保留这个账号吗？[Y/N]
```
sending `y` → `您决定保留账号，并返回继续游戏！` (returned cleanly to the
game, no crash, no data loss).

### Run 3 — id `qinchuan`, name 秦川 (male) — FINAL verification, after the `book-qujing` include fix and all encoding/typo fixes

Restarted the driver fresh (picking up the §15t include-path fixes, the
2 corrected-encoding files, and the `poem.lpc`/`convertd.lpc` typo fixes)
before this run.

```
2060 → new → qinchuan → 秦川 → Passw0rd! → Passw0rd! → mypass789 →
mypass789 → qinchuan@example.com → m → 9 → y → look → score → quit → y
```

Reached 南城客栈 (the real starting room) cleanly — `look` rendered the
room/NPC list/exits with **zero errors** this time (confirms the
`book-qujing` fix, though this particular run didn't land in the
`jieding`-NPC room to directly re-exercise it — the fix's absence from
the `lpcc_check.sh` failure list is the direct confirmation). `score`
showed the correct character sheet for 秦川(Qinchuan) (体格/根骨/悟性/
灵性 20/20/25/25, 男性, 十四岁). `quit`→`y` correctly triggered and
resolved the new-account retention gate exactly as in Run 2. **Zero**
`FATAL`/`SIGSEGV`/`Read access denied`/`Cannot #include` lines anywhere
in `debug.log` across this entire session (checked via
`grep -icE "FATAL|SIGSEGV|Read access denied|Cannot #include" log/debug.log`
→ 0).

## Re-verification pass (QA sweep, later session)

Re-tested the full flow end-to-end this pass and found two real,
previously-uncaught bugs:

1. **§15s — `adm/simul_efun/message.lpc`'s `tell_room()` passed a raw,
   unset `int 0` as `message()`'s 4th ("exclude") argument.** This
   crashed during PRELOAD the first time either bridge room
   (`d/qujing/baoxiang/qiao1.lpc`/`qiao2.lpc`) called its own
   `close_bridge()` (`Bad argument 4 to EFUN message() ... Got:
   int(0)`). Fixed with the standard pattern: `exclude || ({})`.
   Re-verified: the specific error is gone from a fresh boot's
   `debug.log`.
2. **Missing `/data/topten/` directory** (§15ah-shaped): the raw archive
   never shipped this directory, but `adm/daemons/toptend.lpc`'s
   `topten_checkplayer()` -- called from `enter_world()` on **every
   single new registration** -- tries to `write_file()` 11 different
   leaderboard files there (`rich.o`, `pker.o`, `kill.o`, `exp.o`, etc),
   failing with `Wrong permissions for opening file
   /data/topten/rich.o for overwrite. "No such file or directory"` every
   time. Created `libs/xiyouji2006/work/data/topten/` (directory only,
   no seed data) proactively; re-verified with a fresh registration
   afterward -- zero `topten`-related errors.
3. **Noted, not fixed -- a recurring (not just one-off) "Too long
   evaluation" eval-abort from the ambient wandering-pilgrim NPC system**:
   `d/npc/ts.lpc`'s `tudi()`/`random_place()`/`invocation()` chain (the
   "唐僧师徒" group periodically relocating and re-spawning apprentice
   NPCs via `d/npc/qujing.lpc`'s `choose_npc()`) hits the eval-cost limit
   repeatedly -- observed **9 times in a single boot+one-registration
   session**, not just once at preload as first suspected. Each
   occurrence is caught/non-fatal (never affected registration, `look`,
   `score`, or `quit` in any test run) and appears to stem from
   `random_place()`'s 30-attempt randomized directory scan lazily
   `load_object()`-ing still-uncompiled room/NPC files each time it
   relocates the pilgrim group to a fresh, never-before-visited zone --
   a genuine, if repetitive, ambient-content performance issue rather
   than a driver-compat bug or a registration-blocking defect. Left as a
   known, documented, non-critical issue per the project's breadth-over-
   depth policy (fixing it properly would mean redesigning this NPC's
   own placement/spawn algorithm, out of scope for a QA pass).

Full registration + post-login-command flow re-verified twice after both
fixes with real Chinese names 木兰/木梅 (both female), both landing in
南城客栈, `look`/`score`/`quit` all correct, zero `topten`/`message()`-4th-arg
errors in either session (only the known, documented eval-abort noise
above, which never affected the tested flow).

**A fourth fix found during a subsequent same-session cross-check against
siblings `xiyouji`/`xiyouji2003`/`xiyouji450`**: `adm/daemons/logind.lpc`'s
Chinese-name-confirmation step (right after `// by canoe for suppwd`) had
the same stray pre-existing debug leftover `printf("%O\n", ob);` found in
all three other siblings -- dumped a raw internal object reference
straight to the connecting player on every registration. Removed;
re-verified with a fresh registration (`qfzhulan`/竹兰): no stray
object-reference text, `look`/`score`/`quit` all still correct, only the
already-documented eval-abort noise (8 occurrences this run, same known
cause, unrelated to and unaffected by this fix) in `debug.log`.

## How to run

```
cd libs/xiyouji2006
~/src/fluffos/build-debug/src/driver config.fluffos
python3 ../../scripts/mudclient.py 127.0.0.1 40077 --timeout 45 --idle 1.0 \
  --send "2060" --send "new" --send "<3-8 lowercase letters>" \
  --send "<1-6 real Chinese characters>" \
  --send "<super password: >=7 chars, upper+lower+non-letter>" \
  --send "<same super password>" \
  --send "<login password: >=5 chars, different from super password>" \
  --send "<same login password>" --send "you@example.com" --send "m" \
  --send "9" --send "y" --send "look" --send "score" --send "quit" --send "y"
```

## Driver-rebuild retest + LPC reformat + WASM pass (this session)

- **LPC formatter applied** (`tools/lpc-syntax`, all `work/*.lpc`):
  9,123 files reformatted, 137 unchanged, 5 refused (self-check
  failures on messy legacy code, expected). Confirmed the earlier
  `tell_room()` §15s fix (`adm/simul_efun/message.lpc`) and the
  `printf("%O\n", ob);` removal near the "by canoe for suppwd" comment
  in `adm/daemons/logind.lpc` both survived reformatting intact.
- **Native re-test against the freshly rebuilt driver**
  (`~/src/fluffos/build-debug/src/driver`, rebuilt from latest upstream
  master): boots clean, zero `FATAL`/`SIGSEGV`/`执行时段错误` in
  `debug.log`. Full registration verified with real Chinese name
  **秦风再来** (male, id `qretsix`), reaching the actual starting room
  (南城客栈), `look`/`score` both correct; `quit`'s new-account
  retention gate answered "y" (keep account) correctly returned to the
  game rather than disconnecting, matching this lib's documented
  behavior. `data/topten/` (created in an earlier pass) is still
  present and produced zero topten-related errors.
- **WASM build tested** (`~/src/fluffos/build-wasm/src` via
  `scripts/wasm_client.js`): boots cleanly (only expected non-fatal
  preload warnings). **Full registration + login succeeded end-to-end
  under WASM too** — real Chinese name **秦风网络** (id `qfwasev`),
  through the full `2060`/`new`/id/name/super-password/login-password/
  email/gender/gift-accept chain, landed in the real starting room
  (南城客栈), `look` rendered the actual room and NPCs, and the
  quit-retention gate (`y` = keep account) worked identically to
  native. This lib's registration/login path does not gate on
  `query_ip_number()`'s format, so it is **not** affected by the
  documented WASM IP-format limitation — a genuinely clean, complete
  WASM result.

## WASM-enablement pass (loopback-allow + admin seed)

Applied the standard WASM-first changes (AGENTS.md §1.3b/§1.3e/§1.5):

1. **Loopback always allowed through ban gates** —
   `adm/daemons/band.lpc`: added `is_local_ip(string ip)` helper (127.*,
   empty/non-string, or non-dotted-quad => local) and short-circuited
   `is_banned()`, `create_char_banned()`, `is_strict_banned()` to
   `return 0` for local IPs.
   `adm/daemons/logind.lpc` `encoding()`: the two IP-format kill gates —
   `if (!ip_name) destruct` and the "every char must be digit or dot"
   scan over `ip_number` (both destruct exactly the garbage IPs WASM
   produces) — are now skipped when
   `"/adm/daemons/band"->is_local_ip(ip_number)`.
2. **Uptime startup gate**: none in this lib (`UPTIME_CMD->report()` is
   display-only).
3. **Anti-flood throttles exempt loopback** — `logind.lpc`: (a) the
   `logon_cnt > 15` 恶意reconnect per-IP cap in `logon()`; (b) the
   `#ifdef MAX_LOGIN` per-IP multi-login cap in `get_id()` — both now
   skipped for local IPs. KEPT: the new-account 1-hour save-retention
   quit prompt (game design; wizards exempt).
4. **Admin account seeded** — id `fluffos`, display name 浮浮 (male),
   registered through the real flow (`2060` version handshake → `new` →
   id → name → 管理密码 `Adm@2026` ×2 → 登录密码 `Mud@2026` ×2 → email →
   gender → `9` → `y`). Re-login accepts EITHER password at its single
   密码 prompt ("管理密码或登陆密码") — `Mud@2026` works. Granted
   `(admin)` via `adm/etc/wizlist` (`fluffos (admin)`). Verified after
   restart: 目前权限：(admin), `update /adm/daemons/band` → 成功,
   `goto` worked. Save files: `work/data/user/f/fluffos.o` +
   `work/data/login/f/fluffos.o` (untracked, NOT gitignored —
   orchestrator must `git add`).

Retest: fresh registration (fluffos itself) reached 南城客栈 with `look`
correct; fluffos re-login `(admin)` + wizard commands OK; debug.log has
zero runtime errors.

## 深度功能测试 / Deep functional test (2026-08-06)

第一次完整游玩测试（原生驱动 `build`，ASAN/UBSAN debug 构建）。测试角
色 id `xysixtst`，中文名 小白龙。本轮 WASM 未重新验证：emsdk 工具链
下载硬编码指向 `storage.googleapis.com`，本次会话的出口代理策略性拒
绝该域名（403，已用 `curl $HTTPS_PROXY/__agentproxy/status` 确认是策
略拒绝而非临时故障），本地无法构建 WASM 驱动。

### 主动预防性修复：`maximum evaluation cost` 过低（同源 `xyj2000f`/`xiyouji450` 已确认的 AGENTS.md §7.90 实例）

在动手注册前先检查了 `config.fluffos`，发现 `maximum evaluation cost
: 400000` 与刚测试过的两份同引擎家族档案一模一样。参照那两份档案的
修复经验，本轮**在第一次注册之前就**把这个值提到了 `5000000`（本项
目 30+ 份档案验证过安全的数值），两次独立注册（跨越两个驱动进程）均
未触发任何 eval-cost 中止。

### 发现并修复：ID 重新输入分支误跳回客户端版本校验函数，导致正常玩家的第二次尝试被误判为"非法客户端"而断线（新的 AGENTS.md §8.10）

- **症状**：这份档案的连线握手要求第一次输入必须是隐藏暗号
  `2060`（`get_id()` 校验，README 已注明），通过后才进入
  `get_id1()` 真正处理"你的英文名字是什么"。手动复现：故意输入一个
  非法 ID（含数字），系统正确提示"对不起，你的英文名字只能用英文字
  母。"并要求重新输入；但紧接着输入一个合法的新用户名重试时，系统却
  回以"你的客户端非Tomud或者非笑傲江湖WWW客户端!!"并直接断开连接——
  一个完全正常、只是第一次手滑输错 ID 的玩家，会在重试时被误判为使
  用了错误的客户端而被踢出。
- **根因**：`get_id1()` 里两处重新提示"您的英文名字："之后，都调用
  `input_to("get_id", ob)`（跳回版本校验函数），而不是
  `input_to("get_id1", ob)`（跳回 ID 输入函数本身）。玩家紧接着输入
  的重试用户名，于是被当成版本暗号去和字面量 `"2060"` 比较——几乎不
  可能相等，于是触发"客户端不支持"的断线分支。第三处相同写法在
  `confirm_id()` 里，但整段被注释掉了，不会被执行，未改动。
- **修复**：把 `get_id1()` 里那两处活跃的 `input_to("get_id", ob)`
  改成 `input_to("get_id1", ob)`。
- **验证**：修复前故意复现——输错一次 ID（含数字），紧接着输入一个
  合法用户名重试，稳定复现"服务器已经和你断开连接了"的误断线；修复
  后同样的操作序列（先输错，再输入合法新用户名，再走 `new` 完整走完
  注册）正确地重新回到 ID 输入循环并顺利完成注册。`§9` 格式化自检通
  过（unchanged，未引入格式改动）。
- 这个模式（跳回版本握手函数而非 ID 输入函数）已作为 AGENTS.md 的新
  条目 §8.10 记录。同一血缘家族的另外三份档案（`mhxy`、`mhxyqd`、
  `shenmo`）用 grep 确认存在完全相同的三处写法（同样的相对行号，第三
  处同样是死代码），本轮时间预算内未去动那三份档案，留给下次碰到它
  们的人直接按 §8.10 修。

### 顺带处理：`/data/topten` 运行期目录缺失（AGENTS.md §7.44 已知模式，本地环境问题，非代码 bug）

游玩过程中 `debug.log` 出现一次 `*Wrong permissions for opening file
/data/topten/rich.o for overwrite`——`work/data/topten/` 在这份快照本
地根本不存在（`.gitignore` 已把它列为运行期生成目录）。按 §7.44 的既
定做法 `mkdir -p work/data/topten` 后未再复现，无需改代码。

### 测试内容与结果

- **注册**：隐藏客户端暗号 `2060` → 英文名（重试一次触发并验证了上述
  §8.10 bug）→ `new` → 中文名（小白龙）→ 管理密码 ×2 → 游戏登陆密码
  ×2 → 邮箱 → 性别（m）→ 天赋接受，全程顺利进入 `南城客栈`。
- **门派/技能捷径**：南城客栈驻留的"神子 阿凯哥哥"（`lestat/bai.lpc`）
  提供一次性门派技能赠礼——`ask akaigege about putuo`（普陀山）立即
  授予 12 项技能（等级 60），`skills` 命令确认发放正确，与
  `bxsj`/`bxsj1` 系的"礼物使者"捷径同类设计，非 bug。
- **战斗**：同一血缘家族共享的 `朱雀大街` 疥顶小僧（`attitude:
  peaceful`）——`set wimpy 70` 后 `fight seng` 触发真实对战（这次角
  色带着捷径获得的 60 级技能，能真正命中造成伤害），气血降到阈值以下
  时角色正确自动逃跑到相邻的十字街头，无崩溃。
- **持久化**：(a) 静默重连（net_dead 后用管理密码重新登录）——房间
  （十字街头）、装备、技能全部正确复原，"重新连线完毕"提示正确；
  (b) 真实 `quit` 触发了这份档案自己的反滥用机制——"由于您的账号是
  新建的...游戏规定必需连线一小时以上才可存档！您决定想要保留这个账
  号吗？[Y/N]"，选 Y 会取消退出、返回游戏（不是"强制存档"），本轮测
  试角色未满一小时在线时长，未继续测试选 N 之后账号真的被清除这条分
  支——如实标注为未覆盖这一具体分支，而非默认"和 fy2005 的 L2 机制
  一样所以没问题"。
- **管理员账号**：`fluffos`/`Mud@2026`（登陆密码）登录，`update
  /adm/daemons/logind` 热更新成功（含本轮的两处 §8.10 修复），确认写
  ACL 正常。
- **经济/商店**：**未覆盖**，如实标注为本轮未测。

## §10.7 补测：经济/商店 buy 与反滥用退出机制 N 分支 (2026-08-24)

补测原 2026-08-06 深度测试留下的两处"未覆盖"分支。全程原生 `build-debug`
驱动（ASAN/UBSAN），端口 40077，一次性抛弃角色 `xytstqn`（中文名"抛弃
测试"），从未涉及共享的 `fluffos` 管理员账号本体数据。

- **经济/商店 `buy`**：新注册的抛弃角色本身没有分文（`i`/`score`确认
  "没有任何存款"、身上无物），因此先用管理员账号（`fluffos`）执行
  `giveall /obj/money/silver.lpc`（在线只有这两个角色，giveall 会发给
  所有在线玩家一份——纯粹的测试便利手段，无副作用地给管理员多了一枚
  银子，测试后已用 `git checkout` 还原管理员存档，见下）。给抛弃角色
  的一两银子（100 文）到手后，在南城客栈对店小二执行
  `buy huasheng from xiaoer`（花生豆，标价二十文钱），交易成功——
  "你向店小二买下一碟花生豆"，随后 `i` 显示背包正确包含花生豆 + 一枚
  八十文钱找零（100 - 20 = 80，找零金额精确无误），店小二库存/`vendor_goods`
  逻辑（`buy.lpc`→`owner->complete_trade()`→`me->pay_money()`）验证清
  白，`debug.log` 全程无报错。结论：经济/商店 buy 路径工作正常，非
  bug。
- **反滥用退出机制 N 分支**：抛弃角色（在线时长 < 1 小时，触发条件
  `time() - birthday < 3600` 成立）执行 `quit`，看到预期的
  "游戏规定必需连线一小时以上才可存档！您决定想要保留这个账号吗？
  [Y/N]"提示后回答 `n`（对应 `cmds/usr/quit.lpc` 的 `do_yorn()`）。
  服务器正确回应"抛弃测试，欢迎您下次再来！"，角色随身物品被丢弃在
  房间地上，站点在线注册玩家数从 31 降到 30（确认账号真的从计数中消
  失）；随即用同样的 ID/密码重新连线，得到"没有这个玩家．．．"——证
  实账号确实被删除而非仅仅登出。`git status`/`find` 复核磁盘：
  `/data/user/x/xytstqn.o`、`/data/login/x/xytstqn.o` 等相关存档文件
  均未残留（`do_yorn()`里的 `rm()` 调用生效）。附带读码确认：
  `do_yorn()`末尾还调用了 `LOGIN_D->set_banned_name(me->name(1), 0)`，
  但 `/adm/daemons/logind.lpc` 里并未定义 `set_banned_name()`这个函
  数（只有一个同名的静态 `banned_name` 数组，用于注册时的违禁名单校
  验，语义完全不同）——这是一次对不存在函数的 `->` 调用，在这份驱动
  上属于安全的静默空操作（返回 0，不报错、不崩溃，`debug.log` 全程
  干净，账号照常被删除），应是历史上某次重构遗留的死代码，没有可观
  察的错误路径，不构成需要修复的编程 bug，仅作为观察记录在此。结论：
  N 分支按设计正确执行了账号删除，非 bug。
- **收尾**：测试用完 `giveall` 顺带给管理员账号加了一枚银子
  （`autoload` 从 `({})` 变成 `({"/obj/money/silver:1",})`），测试结
  束后用 `git checkout -- .../data/user/f/fluffos.o` 精确还原，管理
  员账号数据与测试前完全一致（`git diff` 确认无残留改动）。抛弃角色
  的所有存档已被机制自身删除，无需额外清理。驱动进程测试结束后已正
  常终止。

## WASM 修复摘要（迁移自 meta.json 的 group_note）

西游记2006 独立分支（改名为大唐西游）。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BBS_BOARD`、`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 36 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## §7.100 sweep (2026-08-19)

Fixed the corpus-wide `inherit ROOM; ... replace_program(ROOM);` redundant-replace bug (AGENTS.md §7.100). 235 live occurrences deleted: 234 via scripted sweep (`fix_710_room.py`), plus 1 hand-fixed roommaker-tool template (`obj/roommaker.lpc`, simple string-builder variant, same lineage as `xyj2006n`/`xyj2006zzzhx`). 6 already-commented-out instances left untouched. No real `.lpc` source found under `work/data/`. Verified via `build-debug` driver boot: clean compile, zero new "cannot replace"/"cannot bind" debug.log lines; confirmed serving via raw-socket connect showing the real login banner on port 40077.

## §7.30 uninitialized-mapping accessor sweep (2026-08-20)

Corpus-wide mechanical sweep of the `feature/skill.lpc` shared-lineage
bug (confirmed independently on `xiakexing2017`/`jqxz2015`/`haiyang2`
via round-four testing): 3 accessor(s) in this file returned a raw
never-initialized `mapping` instance variable (defaults to `int 0`,
not `([])`, until first assigned), crashing any unguarded
`keys()`/`sizeof()`/indexing caller for a fresh/untrained character.
Fixed at the accessor level (`mapp(x) ? x : ([])`) per the documented
remedy. Verified via `lpcc --batch` static compile check only (not a
live boot) as part of a large mechanical sweep; not individually
functionally re-tested live on this lib.


## AGENTS.md §7.19 fix: enable_player() reentrancy from init()

`feature/command.lpc`'s `enable_player()` (wrapper around
`enable_commands()`) was reachable from an NPC's `init()` (via the
shared `std/char.lpc` `setup()` chain), and `enable_commands()` is only
safe to call from `create()` -- calling it again on an object already
`living()` makes the driver re-invoke that same object's `init()` as a
side effect, which recursed back into `enable_player()` on the same call
stack until "Too deep recursion" aborted the boot on a room's first-ever
visit. Fixed with a true reentrancy flag (`in_enable_player_now`, set at
entry, cleared before every return), NOT a `living()`-gated guard --
`disable_player()` in the same file legitimately re-calls
`enable_commands()` while already `living()` (sleep/wakeup via
`cmds/std/sleep.lpc`, revive via `feature/damage.lpc`), which a
`living()` guard would silently break. Verified via `lpcc --batch`
single-file compile check (PASS). Part of the corpus-wide §7.19 sweep
(Batch C).

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 6 line(s) in 3 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 1 here-document block(s) repaired (1 with the terminator glued to the last text line, 0 with it indented), so `End of file in text block` no longer hides the room or object behind them: `d/moon/bedroom.lpc`. The terminator must start its line (the lexer's own test, KB 04 §6.10); a glued one lost its newline in the GBK -> UTF-8 conversion together with a half character, which stays out.

## 深度功能测试（§10.7，2026-10-05）— compile-warning and load-failure pass

`scripts/lpc_warnings.py xiyouji2006 --fix`, then the structural tools of KB 08 §10.13: 2425 distinct diagnostics -> 281 (9029 files compile, 232 do not; 276 errors in 85 files, 5 warnings). 1036 files changed. Load check of every `.lpc` (9265 objects, 700 per VM boot, HEAD against the working tree): 9021 PASS -> 9037 PASS, 0 that loaded before fail now, 16 more load (8 from the fixes below, 8 from the room base: `std/room.lpc`'s `make_inventory()` takes the `catch(ob = new(file)) || !objectp(ob)` guard of `scripts/lpc_resilient_room.py`, KB 05 §7.25). `scripts/lpc_audit_removed_locals.py HEAD`: 19 candidates, all false positives (the declaration was rebuilt without the unused names, the rest stays declared; the files compile with no diagnostic).

The fixes of `xiyouji` (the older, smaller sibling) were adopted first (`scripts/lpc_twin_port.py adopt xiyouji xiyouji2006`: spliced and reformatted twins, a raw copy), then the pass ran on this lib's own files together with the second round of the root's warning fixes (`lpc_fix_no_effect.py`, unused locals with getter initializers, see `libs/xiyouji/NOTES.md`). Fixed by hand here, each at its source:
- `d/kaifeng/ground.h` (and the four copies in `u/yesi/leitai1..4/`): the three tables are defined by every program of the `ground` -> `ground3` -> `ground2` -> `ground1` -> `ground0` chain; the derived programs `#define GROUND_TABLES_INHERITED` before the include and the header skips them (about 36 `Redeclaration of global variable` in the five directories); the unused `this_room()->query("match/...")` locals of `ground1/2/3.lpc` deleted by hand (`this_room()` loads the arena room; each of those functions calls it again).
- `d/kaifeng/npc/quest.lpc` (and the four copies): `#include "colors.h"` stood in front of the include guard, so an NPC that includes two quest fragments (`yin.lpc`: `quest_fd` and `quest_gv`) defined `color_code` twice; moved inside the guard. `reporting.lpc`: the unused `string str = ... to_chinese(points) ...`.
- `d/city/npc/yg/yaoguai.lpc` (and `d/city/npc/npc/yg/`): `int yaoguai_type = 0;` redeclared the variable of `d/dntg/yunlou/npc/yaoguai.lpc` and was never read in the leaf: deleted (22 warnings in the eleven `yg-*` children). `d/city/npc/sanhua-counter.lpc` (two copies): its saved `last_time` redeclared the `nosave` one of `feature/alias.lpc`; renamed `last_check` (no save file exists).
- `d/12gong/npc/mojie.lpc`: `check()`, called every 2-4 seconds, made a `mojie2` clone it never used (`me2->move()` is commented out): the declaration is gone. `d/qujing/yunzhan/npc/lady.lpc`: `accept_object()` made a `pig` clone on every call and dropped it. `d/dntg/lijing/lijing.lpc`: `int die() { return 1; }` and `int unconcious()` over the `void` ones of `feature/damage.lpc` are `void` now (no caller reads the value), and an unused `object target = target();` is gone.
- `for (n == 0; ...)` (`d/dntg/doushuai/bgl1.lpc`, `d/dntg/yunlou/npc/yaoguai.lpc`, `u/canoe/yaoguai.lpc`): `=`. `else if (tmp[i] == EOT) tmp[i] == EOT + ".";` in the mail daemons: `=` (corpus sweep 25480017c47).
- Typos with one reading: `d/dntg/yunlou/npc/lj.lpc` (a stray `i` before the first comment), `d/jz/npc/jiang.lpc` (`set("daoxing", 1500000) set_skill(...)`: the `;`), `d/qujing/start/24/1.lpc` (`call_out("lost", 1 who)`: the comma), `d/gao/obj/pen.lpc` and `d/obj/books-nonskill/hmeng014.lpc` (as in `xiyouji`), `d/penglai/npc/luxing.lpc` and `shouxing.lpc` (`int ref ()`: `ref` is a reserved word, renamed `do_refresh`, also in `call_out("ref", 20)`).
- `cmds/wiz/tail.lpc` calls `tail()`: defined in `adm/simul_efun/file.lpc` (KB 04 §6.2).

**What is left (85 files with a compile error, 5 warnings).** The warnings are in files that do not compile either (`adm/simul_efun/oo.lpc`, an unreferenced copy of `object.lpc`'s `destruct()` that master's `valid_override()` refuses outside simul_efun; `vikee.canoe.lpc` with a `cast` for `case`; `d/penglai/_._/10.10/score.lpc` without its semicolons). Errors: the TMI-2 network daemons (`adm/daemons/network`, `daemons/network`: `uid.h`, `config.h`, `mailer.h` never shipped), the Kaifeng `quest_*` fragments in `old/`, wizard directories (`u/yesi`, `u/vikee`), and damaged content (`d/qujing/start/24/12.lpc` is cut off in the middle of a path, `d/xueshan/obj/hufabird.lpc` has a function inside `create()`, `d/shendian/obj/niepan.lpc` and `d/moon/obj/poem.lpc` have garbled GBK, `d/dntg/sky/npc/yuhuang1.lpc` lost its quotes and semicolons).

## 深度功能测试（§10.7，2026-10-05）— 任务表里的 `.c` 路径与任务守护进程的防护

`scripts/lpc_dynamic_rows.py`：`d/obj/quest/dynamic_location`、`d/obj/quest/dynamic_quest` 里 263 行写的是原档案的 `.c` 路径。转档时文件已改名 `.lpc`，而显式后缀按原样解析，`load_object("/d/x.c")`、`new("/d/obj/quest/x.c")` 返回 0 且不报错（KB 03 §4.2，KB 06 §7.220），所以 `adm/daemons/questd.lpc`、`daemons/questd.lpc` 读到的每一行都加载不出来：随机任务和任务物品从未生成，在 `create()` 里直接对结果调用 `tar->set()` 的版本还会崩溃，连带加载它的 cron 守护进程和 `give` 的任务钩子。这些行已改为 `.lpc`；另有 4 行指向的文件两种后缀都不存在（档案缺内容），保持原样。
`scripts/lpc_dynamic_quest_guard.py`：2 处 `spread_quest()` 调用（`init_dynamic_quest()` 的循环里）包进 `catch()`，缺失的任务物品或编译不过的房间只跳过那一个任务，守护进程照常加载、其余任务照常生成；`cmds/std/look.lpc` 夜间检查的 `!present("fire", this_player())` 前加 `objectp(this_player()) &&`（房间 `reset()` 销毁物品时 `/feature/move.lpc` 的 `remove()` 会调用 `look_room()`，此时没有 this_player()，`present(…, 0)` 报 `Bad argument 2 to present()`）。
验证：`adm/daemons/questd.lpc`、`daemons/questd.lpc`和 cron 守护进程在新进程里加载（HEAD 一次，工作树三次，选房是随机的）：HEAD 通过 2 个，工作树三次分别通过 4、4、4 个（共 4 个），无回退；`adm/daemons/questd.lpc`、`daemons/cron.lpc` 原先加载失败，现在加载成功。
验证：改动过的 `adm/daemons/questd.lpc`、`cmds/std/look.lpc`、`daemons/questd.lpc` 在新进程里加载，HEAD 通过 2 个、工作树通过 3 个（共 3 个），无回退。

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `std/room.lpc`：`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 OK，工作树 单件 OK、多件 OK。

- 2026-10-10：`/obj/roommaker.lpc` 生成新文件用的 here-document 模板（`@ROOM_CODE`/`@OBJ_CODE`）里的 `inherit` 行，被 94b87c18461 的重复继承清理当成代码删掉了（`lpc_diamonds.py` 当时不识别 here-document），用它生成的房间/物品会因缺少继承而无法编译。已恢复该行；工具已修正。

## 深度功能测试（§10.7，2026-10-12）：vikee.canoe.lpc

- `d/city/npc/vikee.canoe.lpc`（及 `npc/npc/` 副本）：`cast "mace" :` 是 `case` 的笔误，整份文件从不编译；改正后可载入（这是 `vikee.lpc` 的旧副本，无人引用）。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。3 个文件 3 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。

## `->query_(` 笔误（2026-10-15，KB 06 §7.245）

调用不存在的函数 `query_`，call_other 静默返回 0，相关判断永远按 0 计算。改为 `->query(`：`buhui`。

## 空手使用兵器绝招（2026-10-15，KB 06 §7.246）

`perform` 指令允许直接点名招式（如 `perform stick.ban`），这些绝招读了 `me->query_temp("weapon")` 却从不检查，空手时 `weapon->name()` 报错（有的已先扣了内力）。在赋值后补 `if (!objectp(weapon)) return notify_fail("你必须手持兵器才能使用这一招。\n");`（`scripts/lpc_fix_perform_weapon.py`）：`yueya-chan/feicha`。

## 用兵器的绝招空手施展时报错（内联写法）（2026-10-15，KB 06 §7.246）

绝招不存兵器变量，直接写 `(me->query_temp("weapon"))->query("name")`（或在拒绝判断里写 `(weapon = me->query_temp("weapon"))->query("skill_type")`），之前又没检查兵器：空手 `perform` 时报 `Bad argument 1 to EFUN call_other()`，内力等往往已经扣掉。在第一次用到它的那条语句前补上“你必须手持兵器才能使用这一招”的拒绝（`scripts/lpc_fix_perform_weapon.py`）：`liangyi-sword/yin`。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

19 个文件、22 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`），多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/d/city/npc/npc/obj/choupao`、`/d/city/npc/obj/changqiang`、`/d/obj/cloth/cloth`）。本库 NPC 基类 `std/char/npc.lpc` 的 `carry_object()` 第一句是 `if (file->query_unique())`，对不存在的文件直接 call_other，驱动在这里报 `call_other() couldn't find object`，`new()` 来不及返回 0，所以只要 NPC 带着一件本库没有的物品就载入不了（调用处加判断对它无效）。在它前面补 `if (!objectp(load_object(file))) return 0;`（`--base`），缺的物品就跳过，NPC 照常载入；上面那些调用处同样改成带判断的块（基类以后改回去也不怕）。载入检查：改动的文件改前能载入 1 个，改后 19 个（18 个原来载入不了），没有退步；其余 1 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## 去掉的预定义宏 `SAVE_EXTENSION`（2026-10-18，KB 04 §6.11）

老版 MudOS 给每个 LPC 对象预先定义了 `SAVE_EXTENSION`（`".o"`）；FluffOS 的 ChangeLog（COMPAT_BUSTER 一条）把它删了，改用 `__SAVE_EXTENSION__`。本库没有自己 `#define` 这个宏，用到它的文件一律 `Undefined variable 'SAVE_EXTENSION'`，整个对象载入不了。改成 `__SAVE_EXTENSION__`（`scripts/lpc_fix_predefined_macro.py`）：`adm/daemons/network/netmail.lpc`、`daemons/network/netmail.lpc`。`netmail` 是网络邮件守护进程（本库缺 `mailer.h` 等头文件，改后仍载入不了）。改后用 `lpcc` 逐个载入这些对象：0 个通过，2 个还有别的错误（`adm/daemons/network/netmail`：/adm/daemons/network/netmail.lpc:17: error: Cannot #include mailer.h；`daemons/network/netmail`：/daemons/network/netmail.lpc:17: error: Cannot #include mailer.h）。

## `d/shendian/obj/niepan` 的收尾引号变成了私用字符（2026-10-18，KB 03 §4.6）

`set("long", HIR"……五种符号<U+E4D4>NOR);` 里本该是 `"` 的位置是一个私用区字符（转码时半个汉字加引号被换成了它），`Illegal character 0xee`，整个物件载入不了。换回 `"`。载入：通过。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 3 个对象设了本库没有文件的武功（5 个名字，最多的是 `chanting`、`essencemagic`、`qitian-gun`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：3 个里 3 个通过。（`scripts/lpc_guard_set_skill.py`）

## 补回本库没有的基类文件（2026-10-18，KB 04 §6.15）

下面这些基类本库没有，继承它们的对象（房间、NPC、物品）整批载入不了（`inherit XXX;` 的宏没定义，或者 `inherit "/std/…";` 的文件不在）。同系的库里有同名文件，两库有大量逐字节相同的文件（亲缘关系），所以从那边原样拷来，缺的宏补进全局头文件 `include/globals.h`：`/std/weapon/unarmed`（宏 `UNARMED`）←sjsh，2 个对象继承它，抽样 2/2 载入。每个基类补回后单独载入、再抽样载入使用它的对象，基类载不进来或者一个用户也载不进来的就撤掉（本库撤掉了它们，不再补）。（`scripts/lpc_restore_bases.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 15 处、15 个文件：`dagonforce`→`dragonforce`（4 处）、`hellfire_whip`→`hellfire-whip`（3 处）、`lahua-shou`→`lanhua-shou`（3 处）、`dragon-step`→`dragonstep`（2 处）、`yange_blade`→`yange-blade`（1 处）、`changqaun`→`changquan`（1 处）、`cuixi-zhang`→`cuixin-zhang`（1 处）。（`scripts/lpc_fix_skill_names.py`）

## 武功基类缺少 NewRandom()（2026-10-19，KB 06 §7.261）

基本武功（`boxing`、`houquan`、`westsword`、`taiji-quan` 等）用 `action[NewRandom(i, 20, level/5)]` 挑招式；`NewRandom()` 和它调用的 `sum()` 在别的库的武功基类里有，本库的 `/std/skill.lpc` 是更精简的版本，没有，于是这些武功全都报 `Undefined function NewRandom` 编译不过，有这门武功的人物只能空手。把这一对函数（115 个库共用的同一份文字）补进武功基类，受益武功 6 个：`/daemon/skill/boxing.lpc`、`/daemon/skill/houquan.lpc`、`/daemon/skill/taiji-quan.lpc`、`/daemon/skill/westsword.lpc`。（`scripts/lpc_restore_skill_helpers.py`）

## 全局头文件丢了 2 个宏（2026-10-19，KB 04 §6.16）

`/include/globals.h` 里没有定义 `NPC_D`、`LOCATION_D`，用到它们的物件（名单里 2 个）编译时报 `Undefined variable`/`Undefined function`，整个物件载入不了（编译器在第一个未定义的名字上停下，后面的错误和警告都看不到）。同系的库在各自的头文件里都有这几行：照其中和本库共有文件最多的那个库，原样补到 `/include/globals.h` 最后一个 `#define` 之后，宏体里出现的路径在本库里都存在。补完后名单里有 1 个载入，其余还差别的东西。（`scripts/lpc_restore_defines.py`）

## 找不到父类函数的 ::fn() 调用（2026-10-19，KB 06 §7.259）

`/d/city/npc/duguoyin.lpc`、`/d/city/npc/npc/duguoyin.lpc`共 2 个物件里写着 `::create();`、`::init();` 这类调用，而它们继承的基类并没有这个函数。老驱动把这种调用当成什么都不做、返回 0 的空调用，本驱动在编译时报 `Unable to find the inherited function 'init'.`，整个物件载入不了。这些物件的错误只有这一种（其他错误清掉之后才露出来的），逐个删掉这些调用（`return ::fn(...)` 改成 `return 0;`）。（`scripts/lpc_fix_dangling_super.py`）

## 出口指向不存在的房间（2026-10-19，KB 06 §7.257）

下列房间的出口写的文件不存在，而对面恰好只有一个房间的出口指回本房间，所以按对面的房间改正（笔误、大小写、路径少了一级）：

- `/d/qujing/wuji2/shandao3.lpc` 的 `west` 出口：`guankou` → `goukano`
- `/d/qujing/wuji2/shandao4.lpc` 的 `east` 出口：`guankou` → `goukano`

改后房间照常载入（与 HEAD 逐个对比，没有退步），出口现在指向存在的房间。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 旧驱动的类型宽松：缺省参数、无类型形参、数组初始化、`class` 变量（2026-10-19，KB 04 §6.19、§6.20）

原来的 MudOS 把调用少传的参数补 0、把没写类型的形参当 `mixed`、不检查变量的声明类型与初始值，也允许变量叫 `class`；这个驱动在编译时全部拒绝，整个物件载入失败。修了 1 个文件：`/daemon/class/fuqiperform/perform.lpc`（`scripts/lpc_round_files.py` 的修复轮：调用处补写 `0`、无类型形参补 `mixed`、`string X = ({...})` 补星号、void 函数的返回值，以及 `class` 变量改名 `pick_class`）。逐个文件在 HEAD 和改后载入对比：这些文件里 1 个原来载入失败、现在载入，没有退步。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。改动：`/d/liandan/baihuagu.h`（1 处）。

## `member_array('/', str)` 改为 `strsrch(str, "/")`：字符字面量的 member_array 按字节搜索（2026-10-20，KB 06 §7.283）

`member_array('/', str)` 里的 `'/'` 是整数，驱动按 UTF-8 **字节**搜索，返回字节偏移（带第三个参数时起点也是字节）；最新的 FluffOS（923cdbc0）在字符串里有非 ASCII 文字时，对每个调用点警告一次（`Warning: member_array(int, string) searches BYTES`）。而 `str[0..idx-1]` 按字符切，中文字符串会在错误的位置截断。改为 `strsrch(str, "/")`（找不到同样返回 -1，按字符计数；`scripts/lpc_fix_member_array_char.py`，JSON 编码器等少数几处手改）。改动：`/adm/daemons/vrm_server.lpc`（1 处）。

## `call_out_info()` 的每一项只有 3 个元素（2026-10-20，KB 06 §7.287）

驱动返回的是 `({ 物件, 函数, 延迟 })`，不带 call_out 的参数，旧代码读第 4 项 `info[i][3]`（`callouts` 指令、`calloutd`、`cod` 工具）一读就报 `Array index out of bounds`，指令从第一行起什么也打印不出来。改为 `(sizeof(info[i]) > 3 ? info[i][3] : 0)`（`scripts/lpc_fix_callout_info.py`）。改动：`/cmds/wiz/callouts.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 5 处）。改动：`/cmds/wiz/dns.lpc`（1 处）、`/d/shendian/babu/obj/longzhua.lpc`（4 处）。

## `callouts`：`sizeof(info[i]) == 4` 把每一行都挡掉了（2026-10-20，KB 06 §7.287）

驱动的 `call_out_info()` 每项只有 3 个元素，输出行前的守卫 `if (sizeof(info[i]) == 4)` 永远不成立，指令只打印表头。改为 `>= 3`。改动：`/cmds/wiz/callouts.lpc`（1 处）。

## `socket` / `dumpsocket` 指令：`dump_socket_status()` 驱动里没有（2026-10-20，KB 06 §7.291）

这些巫师指令 `write(dump_socket_status());`，MudOS 的 efun 在 FluffOS 里不存在，指令编译不过。在模拟 efun 文件里补了 `dump_socket_status()`：用 `socket_status()` 排出同样的表（没有 sockets 包的构建，比如 WASM，只有表头；`scripts/lpc_add_sefun.py dump_socket_status`）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/obj/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## sefun `cat()`：缺文件时 `write(0)` 报错（2026-10-20，KB 06 §7.297）

`void cat(string file) { write(read_file(file)); }`：文件不存在（压缩包没带的欢迎/公告文件，或只有运行中的 mud 才会写的日志）时 `read_file()` 回 0，`write(0)` 在本驱动里报 `Bad argument 1 to receive()`，调用者（登录对话、`cat` 指令）被中断；老驱动什么也不打印。改成 `write(read_file(file) || "");`（`scripts/lpc_fix_cat_unchecked.py`）。改动：`/adm/simul_efun/file.lpc`。

## 翻页器 `start_more(read_file(...))`：文件缺失时 `explode(0)`（2026-10-20，KB 06 §7.300）

东方故事系的翻页器 `void start_more(string msg) { ... explode(msg, "\n") ... }` 被这样调用：`start_more(read_file(HELP_DIR + "help/topics"))`、`start_more(read_file(NEWS))`。压缩包没带的文件使 `read_file()` 回 0，`explode(0, ...)` 在本驱动里报 `Bad argument 1 to explode()`（不带参数的 `help` 指令就是这样出错的），老驱动把 0 当空文本。在 `start_more` 开头加了 `if (!stringp(msg)) return;`（`scripts/lpc_fix_start_more.py`）。改动：`/feature/more.lpc`。

## 访客计数 `howmany_visitor()` 读文件不检查（2026-10-20，KB 06 §7.301）

`howmany_visitor()` 读访客计数文件（`VISITORS` / `COUNTER` / `BBSVISITOR`，只有运行中的 mud 才会写；`.gitignore` 把它排除在仓库之外），新检出的树里没有，`read_file()` 回 0，`sscanf(0, ...)` 报错。这份副本登录时不一定走到它，但调用时同样会出错。在读文件之后加了 `if (!stringp(content)) return 0;`（xkx100、xiakexing100、zzfy 早先的写法，`scripts/lpc_fix_visitor_count.py`）。改动：`/www/relative/logind.lpc`。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库现有的 NPC 文件里没有字面写成空 `chat_msg` 的（扫描只认 `set("chat_msg", ({ }))`）；守卫挡的是运行时才为空的列表和以后新增的 NPC。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/std/char/npc.lpc`（共 1 个文件）。

## 巫师命令不带参数时对 0 调用 efun（2026-10-21，KB 06 §7.336）

巫师（管理员）把命令敲成不带参数时，驱动把 0 传给字符串参数；下面的命令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`，这条指令从来没有用过。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py` 在第一处使用参数的语句前加守卫：文件自带 `int help(object me)` 的，守卫是 `if (!arg) return help(me);`（`help()` 定义在 `main()` 之后的 2 个文件补了原型 `int help(object me);`，否则编译报 `Undefined function help`）；没有 `help()` 的是 `return notify_fail("…\n");`。改动（4 个文件，括号里是接住 0 的 efun）：`/cmds/adm/admove.lpc`（`present`）、`/cmds/adm/baiban.lpc`（`sscanf`）、`/cmds/adm/dumpprog.lpc`（`new`）、`/cmds/wiz/call.lpc`（`replace_string`）。加载检查 HEAD 与工作树对照，没有退步。

## 不带参数的指令对 0 调用 efun：不在 wiz / adm 目录里的指令（2026-10-21，KB 06 §7.336）

指令敲成不带参数时，驱动把 0 传给字符串参数；下面的指令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`。它们在 `cmds/std`、`cmds/usr`、`cmds/bos`、`cmds/app` 这类目录里，上一轮的扫描只看巫师目录。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py --all-dirs` 在第一处使用参数的语句前加守卫：没有 `help()` 的是 `return notify_fail("…\n");`。改动（1 个文件，括号里是接住 0 的 efun）：`/cmds/std/actionavailable.lpc`（`sscanf`）。加载检查 HEAD 与工作树对照，没有退步。

## `cron.lpc`：`emery()` 用循环外的下标，第一次越界就让 cron 停摆（2026-10-21，KB 06 §7.345）

怪兽入侵事件 `emery()`（`/daemons/cron.lpc`）末尾 `for (m = 0; m < sizeof(user); m++) user[i]->set("kill_guaishou", 1);`：`i` 是前面随机选的地区下标，循环变量 `m` 没用上，同一个玩家被标记 `sizeof(user)` 次，在线人数不到 `i + 1` 时下标越界（`Array index out of bounds`，yueyingqiyuan 管理员扫描里的控制台行；`call /adm/daemons/cron->emery()` 一个人在线时四次里三次抛错）。`init_cron()` 在 15 分钟的整点调用 `emery()`，之后才 `call_out("init_cron", 60)` 重新排自己：抛错之后重排没有执行，玩家自动存盘（`autosave()`）、动态任务刷新（`TASK_D->init_dynamic_quest()`）和后面所有事件在这次启动里都停了。改成 `user[m]`（yueyingqiyuan 上实测：连续六次 `emery()` 都正常返回）。这个标记档案里没有任何地方读它（`go.lpc` 里的用法是注释掉的）。

## 拼错的 `call_out()` / `input_to()` 目标（KB 06 §7.349，2026-10-21）

计时器或输入提示给驱动的函数名和文件里定义的差一个字母；驱动对不存在的函数静默不理，所以对应的计时从来没有触发过。调用和配套的 `remove_call_out()` 改成已定义的拼法：`find_seal`：`disapprear` → `disappear`（法术产生的封印十分钟后从不消失）。改动：`/d/jjf/obj/find_seal.lpc`。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 19 条注册（12 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/d/changan/pinqiting.lpc`（`do_pass`、`do_resign`）、`/d/city/npc/duguoyin.lpc`（`do_vendor_list`）、`/d/city/npc/npc/duguoyin.lpc`（`do_vendor_list`）、`/d/eastway/npc/petboss.lpc`（`do_cost`、`do_list`、`do_upgrade`）、`/d/pansi/npc/qingxia.lpc`（`do_yes`）、`/d/pansi/pubu.lpc`（`do_fly`）、`/d/qujing/jisaiguo/obj/luche.lpc`（`do_get`、`do_put`）、`/d/qujing/wudidong/cave2.lpc`（`do_push`）、`/d/zhuxian/npc/guard.lpc`（`do_bian`）、`/d/zhuxian/npc/guard1.lpc`（`do_bian`） 等共 12 个文件。最多的函数名：`do_vendor_list` 2 处、`do_cost` 2 处、`do_list` 2 处、`do_upgrade` 2 处、`do_push` 2 处。

## 调用了、但这个库自己的守护进程里没有的函数（2026-10-22，KB 06 §7.354）

`MACRO->函数()` 调用的函数在这个库的守护进程里不存在：`call_other()` 对不存在的函数不报错、只返回 0，所以这些功能（时间显示、昼夜事件、名字检查、价格文字……）一直没起作用。同一血统另一个库的同名守护进程里有这些函数，原文照抄到本库守护进程末尾（`scripts/lpc_port_function.py`；调用处传的参数个数、函数体用到的函数 / 全局变量 / 宏 / 字符串键都在本库里有，已核对；守护进程在 HEAD 和工作区都能加载，每个函数用固定参数各调用一次：HEAD 返回 0，现在返回正常的值）：`/adm/daemons/chinesed.lpc` ← aoxiangtianji：`chinese_month()`（1 处调用）；`/adm/daemons/chinesed.lpc` ← bxsj：`chinese_time()`（5 处调用）。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 还剩 2 个函数没有补（inquiry 1, chat_msg_combat 1）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/d/death/npc/yanluowang.lpc`:`ask_cancel`、`/d/xueshan/obj/hufabird.lpc`:`saysth`。

## 运行期目录 `log/nosave` 不存在，写日志的 `write_file()` 直接报错（2026-10-22，KB 03 §4.3 补充）

这个库的 1 个文件里有 1 处 `write_file("/log/nosave/...")` / `log_file("nosave/...")`（`static` 改 `nosave` 时连字符串里的日志路径一起改了，原来是 `log/static/`）：`/log/nosave/ATTEMP_KILL` 等。压缩包和站点包里没有这个目录，`write_file()` 在目录不存在时抛 `*Wrong permissions for opening file /log/nosave/... for append. "No such file or directory"`，调用它的函数（杀人记录、重启记录、`call` 日志……）当场中断。把 `log/nosave` 记进 `scripts/wasm_keep_dirs.txt`（站点和 pristine 树都按它建空目录）；没有把字符串改回 `static`。证明（`scripts/lpcc_eval.py`，`catch(write_file("/log/nosave/ZZTEST", ...))`，fqyy2 / hy5 / bmxkx2001 的新进程）：补目录前报上面的错误，补后写成功。

## 读不到的留言板：`"/clone/board/x"->foo();` 在 `create()` 里报错（2026-10-22，KB 06 §7.357）

xkx 系的房间在 `setup()` 之后写 `"/clone/board/gaibang_r"->foo();` 来加载留言板（`foo()` 本来就没有定义，只为了触发加载）。这个库没有这个文件，`call_other()` 报 `*call_other() couldn't find object '/clone/board/gaibang_r'`，对象留在内存里、`load_object()` 却抛错：玩家第一次走进房间就看到错误，写在 `create()` 中间的还会切掉后半段。`scripts/lpc_fix_missing_foo.py` 把 2 条单独成行的语句（`/obj/board/xy_b`；`/d/g_quest/target/gumu.lpc`、`/d/target/gumu.lpc`）注释掉并写明原因（别的房间里同样的语句本来就是作者自己注释掉的）。证明和 45 个库的整体加载检查见 KB 06 §7.357。

## `log/` 下的日志子目录没有人建：写日志的 `write_file()` / `log_file()` 报错（2026-10-22，KB 06 §7.358）

这个库的代码往 `log/` 的 1 个子目录写日志：`log/dlog`（`daemons/moneyd.lpc`）。压缩包、`git clone` 和站点包里都没有这些目录（本地启动没有写过它们，`gen_keep_dirs.py` 没记），`write_file()` 对不存在的目录抛 `*Wrong permissions for opening file /log/dlog/money for append. "No such file or directory"`，调用它的函数在写日志那一行中断，后面的奖励、标志、步骤都没有执行。本库的 `log_file()` 是 `write_file(LOG_DIR + file, text)`，目录不存在就抛同样的错误（实测）。把 `log/dlog` 记进 `scripts/wasm_keep_dirs.txt`（`scripts/lpc_keep_log_dirs.py`；站点和 pristine 树按它建空目录）。证明（`scripts/lpcc_eval.py`，在 `/adm/daemons` 这类目录下的求值对象里写 `/log/zzdirprobe/...`，新进程）见 KB 06 §7.358 的实测表。

## `(: 函数名 :)` 指针指向本库没有的函数：只含这个指针的行加了注释（2026-10-22，KB 06 §7.355 补充）

`inquiry` / `item_desc` / `chat_msg*` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：用到时（`ask`、`look`、NPC 闲聊）驱动抛 `*Undefined lfun pointer called: 函数名`，这一拍心跳的后半段被跳过。这些函数没有可以补回的来源（别的库同一路径的文件里没有，或者它还要用本库没有的东西），所以 2 个文件里 2 行只含这个指针的行（`"cancel": (: ask_cancel :),` `(: saysth :),`）加了注释，原文保留并写明原因，这一项当作没有这个话题 / 物品 / 闲聊条目（`scripts/lpc_fix_dangling_lfun.py`；`#include` 的文件在库里缺失的对象、指针不在整行上的写法没动）。 前提（`function_exists()`）和加载检查（HEAD 与工作区对比，本库改动的 `.lpc` 文件）的结果见 KB 06 §7.355：没有一个回归。
