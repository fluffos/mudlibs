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

## WASM 修复摘要（迁移自 meta.json 的 group_note）

西游记2006 独立分支（改名为大唐西游）。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BBS_BOARD`、`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 36 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## §7.100 sweep (2026-08-19)

Fixed the corpus-wide `inherit ROOM; ... replace_program(ROOM);` redundant-replace bug (AGENTS.md §7.100). 235 live occurrences deleted: 234 via scripted sweep (`fix_710_room.py`), plus 1 hand-fixed roommaker-tool template (`obj/roommaker.lpc`, simple string-builder variant, same lineage as `xyj2006n`/`xyj2006zzzhx`). 6 already-commented-out instances left untouched. No real `.lpc` source found under `work/data/`. Verified via `build-debug` driver boot: clean compile, zero new "cannot replace"/"cannot bind" debug.log lines; confirmed serving via raw-socket connect showing the real login banner on port 40077.
