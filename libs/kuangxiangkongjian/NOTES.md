# kuangxiangkongjian — 狂想空间 (Fantasy Space)

Archive: `狂想空间.rar` (#69). Port: 40063.
Status: **done** (boots clean, full registration flow verified end-to-end
twice, real Chinese names both reaching the actual starting room).

## Lineage check (done FIRST, per task instructions) — genuinely distinct from archive #53, NOT a duplicate

This archive's own filename ("狂想空间.rar") is literally the same string
that archive #53 (`新狂想空间II.rar`, lib `libs/xinkuangxiangkongjian2/`)
turned out to self-identify as in its own `config.fs`/banner. Read
`libs/xinkuangxiangkongjian2/NOTES.md` first, then compared this archive's
raw contents directly against `libs/xinkuangxiangkongjian2/raw/fsII/`
(archive #53's already-extracted raw tree) before doing anything else, per
the task's mandatory lineage-check instruction:

- **Archive file sizes differ**: `archives/狂想空间.rar` is 3,710,123
  bytes; `archives/新狂想空间II.rar` is 5,590,619 bytes. Not byte-identical
  (unlike the genuine `狂想空间.rar` / `狂想空间 (1).rar` duplicate pair
  already in AGENTS.md's Duplicate archives table — confirmed those two
  ARE identical, this archive is the "keep" side of that pair and was the
  only one processed here).
- **Raw file counts differ substantially**: this archive extracts to 7,947
  files (root dir named `ofs/`); archive #53's raw tree has 14,440 files
  (root dir `fsII/`). Archive #53's raw tree has three extra top-level
  directories this one lacks entirely (`d/`, `nets/`, `player/`).
- **Core files differ in size AND md5, with earlier timestamps**:
  - `adm/obj/master.c`: this archive 9,274 bytes (mtime Sep 23 2002) vs
    #53's 12,615 bytes (mtime Dec 15 2002) — different md5.
  - `adm/daemons/logind.c`: this archive 18,796 bytes (mtime Dec 2 2002)
    vs #53's 32,090 bytes (mtime Dec 15 2002) — nearly half the size,
    different md5, and missing an `email`-collection step in the
    registration flow that #53's copy has (this lib's flow is
    id→confirm→name→password→confirm→gender→8 attribute points→enter
    world, no email prompt at all).
  - `adm/daemons/securityd.c`: this archive 9,956 bytes (mtime Jul 28
    2002) vs #53's 14,869 bytes (mtime Dec 15 2002) — different md5,
    and a structurally different (simpler, more permissive-by-default)
    `valid_read`/`valid_write` ACL shape (see "Confirmed NOT needed"
    below).
  - `adm/simul_efun/chinese.c`: identical size (263 bytes) but different
    md5 — this archive's copy is missing a `(string)` cast on two
    `CHINESE_D->` call results that #53's copy has; the actual
    `is_chinese()` logic (the GBK byte-range bug, see §15h below) is
    byte-for-byte identical between the two.
- **Same lineage, same collector-site distribution, same admin account,
  but an earlier/different revision**: both archives' `master.c` share the
  exact same header comment (`// for ES II mudlib / original from Lil /
  rewritten by Annihilator (11/07/94)`), confirming the same **ES II**
  mudlib base already seen across `es1_win`/`esI`/`xkx2001`/`rzrmud`/
  `beimeixiakexing2001`/`wuhanzhan`/`haiyang2`/`yanhuangwuhun`/
  `xinkuangxiangkongjian2` itself. Both archives' `小熊泥苑.txt` readme
  (the archiving/collector site, `http://dtxy.126.com`) carries the exact
  same claim — this archive's copy: "97年就开始玩狂想...我申明我的狂想源
  码不是从老jack手上偷出来的, 是自已把台湾版狂想空间big5转成gb码提供下载
  的" ("I didn't steal this from old Jack, I converted the Taiwan version
  of 狂想空间 from BIG5 to GB myself") — same collector, same claimed
  Taiwan-BIG5-to-GB conversion story as #53's own collector-site readme.
  Both archives' wizlist/config reference the same admin account **`bear`**
  (this archive's `adm/etc/wizlist`: `bear (admin)`; #53's credit line
  named `bear`/`wade` as manager). This archive ALSO carries an extra
  readme #53 doesn't have, `新改动（一定要看）.txt` ("New changes, must
  read"), dated **Dec 7 2002** by a wizard named "玩具熊" (Toy Bear),
  describing a bug-fix pass ("主要是解决了不能正常注册和进入及提升权限
  的问题" — "mainly fixed the can't-register/can't-login/can't-elevate-
  permissions issues") and providing test accounts (`bear`/`123456`
  wizard, `ronger`/`123456` player) — i.e. this archive is a **separately
  circulated bugfix snapshot of the same underlying game**, not the same
  file redistributed.
- **Conclusion**: this is a genuinely distinct codebase snapshot/fork —
  same game, same ES II base, same distribution lineage/collector site,
  same `bear` admin account, but a different (and by every file
  timestamp, earlier) development snapshot with substantially different
  file counts and file contents in every core admin file checked
  (master/logind/securityd differ in both size and md5; only the tiny
  chinese.c is near-identical, and even that has one cast-related diff).
  **Processed as its own lib, per the task's explicit instructions**,
  porting archive #53's proven fixes directly wherever the same bug shape
  was confirmed present (§15h, §15t's three include-resolution bugs, the
  `n_area.h`/`cold.h`/`basic_skill.lpc` precedents all recurred here
  almost verbatim — see below).

## What this is

Self-identifies in `config.fs` as **狂想空间** (`name : 狂想空间`, no
"新"/"II") and the live in-game banner confirms the same:
`狂想空间承蒙 mineral & elon 协助, 初次架于 1995 9 22` — "with help from
mineral & elon, first set up 1995-09-22", crediting founders "wade,
shorst, jcder". Same in-game banner text shape as #53's ("感谢...elon &
mineral" there), same founding date, confirming both archives really are
snapshots of the literal same long-running game, just at different points
in its development. Raw archive root directory is named `ofs/` (not a
recognizable acronym match to the game's own name — kept the pre-assigned
working slug `kuangxiangkongjian` since the archive's own top-level dir
name isn't a meaningful title either way, matching the project's existing
convention of using a phonetic slug of the self-identified Chinese name).

7,947 raw files, 6,323 renamed `.c`→`.lpc`. A prebuilt Windows `MudOS.exe`
binary is bundled alongside the source (ignored, per AGENTS.md — our own
driver build is used).

## Fixes applied

1. **AGENTS.md §15h, standard shape**, `adm/simul_efun/chinese.lpc`:
   `is_chinese()`'s GBK lead-byte range check (`strlen(str)>=2 &&
   str[0]>160 && str[0]<255`) rewritten to a CJK Unicode codepoint check
   (`strlen(str)>=1 && str[0]>=0x4e00 && str[0]<=0x9fff`) — byte-for-byte
   the same original bug as archive #53's copy of this exact file.
2. **AGENTS.md §15h**, `check_legal_name()` in `adm/daemons/logind.lpc`:
   byte-count bound `< 2 || > 12` → character-count bound `< 1 || > 6`
   (message text already says "必须是 1 到 6 个中文字", confirming the
   halved bound); removed the `i%2==0 &&` even-position gate in the
   per-character `is_chinese()` sliding check so every character position
   is checked under UTF-8 semantics. Identical fix shape to #53 (this
   lib's `logind.c` clearly shares a very recent common ancestor with
   #53's copy for this specific function, even though the surrounding
   file differs substantially in size/content elsewhere).
3. **AGENTS.md §15p**: `adm/etc/preload` already had
   `/adm/daemons/network/dns_master` commented out in the raw archive —
   confirmed nothing to remove here (checked proactively before first
   boot, per standing policy; documenting the check since the archive
   happened to already be clean on this one).
4. **AGENTS.md §15t, all three sub-bugs, ported directly from archive
   #53's precedent** (same driver-`inc_open()`/`legal_path()` root
   causes, confirmed by reading the actual failing files before fixing):
   - **Absolute-path angle-bracket `#include`s** (172 files, e.g.
     `std/armor/cloth.lpc`'s `#include </open/open.h>` — literally the
     same starting-clothes-item file #53 flagged as the highest-impact
     fix there). Blanket-converted every `#include <ABSOLUTE_PATH>` to
     the quoted form (`sed -E 's#include *<[[:space:]]*(/[^>]*)>#include
     "\1"#'` after a `grep -rlZ` scope check), 172 files fixed in one
     shot, plus one stray leftover `.c`-extension angle-bracket reference
     (`#include </include/basic_skill.c>`, fixed to point at the real
     `.lpc` file) that the mechanical `convert_lib.sh` pass didn't catch
     since it only fixes quoted `".c"` references, not angle-bracket ones.
   - **`..`-relative `#include`s** (94 files total: 27 `#include
     "../cold.h"` under `open/cold/*.lpc`, 28 `#include <../start.h>`
     under `open/start/{npc,room,obj}/*.lpc`, 20 `#include "../../open.h"`
     under various 2-levels-deep zone dirs, plus smaller one-off groups —
     `capital.h`×5, `badman.h`×4, `su.h`×2, `combat.h`×1, `ouch.h`×1).
     Resolved each by locating where the target header actually lives on
     disk (not by guessing at relative-path arithmetic) and converting to
     an absolute quoted path:
     - `../cold.h` → **`/open/cold.h` did not exist anywhere in the raw
       archive** (a genuine content gap, same as #53's `WQA_ROOM`/`cold.h`
       precedents) — reconstructed a minimal header defining only the two
       macros actually referenced anywhere under `open/cold/*.lpc`
       (`COLD_ROOM "/open/cold/"`, `COLD_NPC "/open/cold/npc/"` — grepped
       every `COLD_[A-Z]+` use first to confirm no `COLD_OBJ` is ever
       referenced and no `open/cold/obj/` subdirectory exists, so nothing
       beyond these two was guessed/added; the room-file layout confirms
       `COLD_ROOM` must resolve to the zone's own top dir since sibling
       rooms are referenced as e.g. `COLD_ROOM"home1"` and `home1.lpc`
       really sits directly under `open/cold/`, not a nested `room/` dir).
     - `<../start.h>` → the real `/open/start/start.h` (exists, defines
       `S_NPC`/`S_OBJ`/`S_ROOM`, genuinely used by several of the
       converted files including two personal-wizard-directory copies —
       `u/w/welcome/`, `u/f/fary/` — of start-zone content).
     - `"../../open.h"` (2-levels-deep zone dirs) → `/open/open.h` in all
       cases but one: `open/snow/room/oldsnow/room3.lpc` is nested one
       level DEEPER than its sibling `open/snow/room/*.lpc` files, so its
       literal 2-levels-up target is genuinely `/open/snow/open.h` (a
       real, smaller, snow-zone-local header that also exists) — verified
       this file doesn't actually use any macro from either header at all
       (only `ROOM`/`LONG`, unrelated to `open.h`), so the choice is
       inconsequential functionally but the path-depth-correct one was
       used anyway. One personal-sandbox copy,
       `u/m/mystery/c_box.lpc` (a near-identical draft of
       `open/snow/obj/c_box.lpc`), has a `"../../open.h"` that doesn't
       even resolve correctly BY DEPTH from its own real location
       (`u/m/mystery/`, 2-up = `u/`, no `open.h` there) — a pre-existing
       broken copy-paste from whichever zone file it was cloned from;
       pointed it at `/open/open.h` to match its sibling instead of
       preserving an already-broken relative reference.
     - `capital.h`/`badman.h` → real existing `/open/capital/capital.h` /
       `/open/badman/badman.h` (neither macro set is actually referenced
       by the misplaced/duplicate files that included them — e.g.
       `open/start/room/bad2/3/4.lpc`, three files whose own comments
       and content ("屠娇娇"/"不男不女") read as `badman`-zone NPCs
       physically misplaced under `open/start/room/`, sharing an
       unused-but-must-still-resolve include with their correctly-located
       sibling `open/badman/room/t3.lpc`).
     - `su.h` → **genuinely missing from the archive entirely** (unlike
       `cold.h`, this one is independently corroborated by a leftover
       original-operator debug log found in the raw archive itself,
       `u/b/bigcat/log`, which records `Cannot #include ../su.h` from the
       *original* pre-conversion mud's own operation — proof this exact
       gap predates our involvement, not an artifact of conversion).
       `u/o/oda/npc/boss4.lpc`'s own header comment says
       `// /open/su/npc/boss4.c by oda`, confirming an entire `/open/su/`
       zone was planned/referenced but never shipped in this archive (a
       §13-style missing-zone gap). Reconstructed a minimal `/open/su.h`
       defining only the one macro actually used anywhere
       (`SU_OBJ "/open/gblade/obj/"`, matching the real location of the
       `cup.lpc` object `u/t/tide/boy.lpc` instantiates via `new(SU_OBJ
       "cup")`) — `boss4.lpc` itself never references any `SU_` macro at
       all, so this is enough to satisfy both files without fabricating
       any of the never-shipped `/open/su/` zone's actual content.
     - `combat.h`/`ouch.h` (1 file each) → real absolute paths
       (`/u/f/fary/combat.h`, `/u/o/ouch/ouch.h`) one directory up from
       each including file's own real location — these would have
       resolved correctly even under a permissive `..`-allowing driver,
       just converted to the quoted-absolute form this driver requires.
     - 5 more `"../str.h"` references (under
       `u/s/server/map2room/*.l`) were **not** touched: these `.l` files
       are lex/flex source for a standalone C map-conversion utility
       (`/* Make: lex map.l , gcc -o map lex.yy.c */`), never renamed to
       `.lpc`, never compiled by the driver at all — correctly out of
       scope per AGENTS.md's "what counts as LPC source."
   - **`inherit` appearing after a `#include`d header's (or a bare
     global's) declaration** — found via the `lpcc_check.sh` sweep (see
     below), same shape as #53's `n_area.h` cluster almost verbatim.
5. **`master.lpc get_include_path()`** (AGENTS.md §8d/§15o): none existed;
   added the standard shape (compiling file's own directory + `:DEFAULT:`)
   as defensive insurance for any live/mid-connection compile of a
   same-directory quoted include, alongside the blanket absolute-path
   conversion above (which resolves unconditionally via `merge()`
   regardless of VM context, per §15t's documented caveat that
   `get_include_path()` alone isn't sufficient for preload-time compiles).
6. **NEW variant of the AGENTS.md §3 counterexample** (a `"static/..."`
   string-literal path corrupted by the blanket `\bstatic\b`→`nosave`
   keyword sed, same root cause as `moniHuafu`/archive #57's finding, but
   never previously documented for THIS lib's own log-directory naming):
   31 `log_file("nosave/XXX", ...)` calls across 15 files (`master.lpc`'s
   `crash()` → `"static/CRASHES"`; several `securityd.lpc` copies →
   `"static/promotion"`; `pkd.lpc`/`call.lpc`/`purge.lpc`/`purgewiz.lpc`/
   `xpass.lpc`/`summon.lpc` → `"static/pker"`/`"static/PURGE"`/
   `"static/PURGE_WIZ"`/`"static/CALL_PLAYERS"`/`"static/CALL_WIZARD"`)
   were silently rewritten to `"nosave/XXX"` by the mechanical
   `static`→`nosave` sed, since `static` is a real directory-name
   substring in these paths, not the keyword. Confirmed the corruption
   was real (not a false read) by checking the RAW pre-conversion
   `master.c` directly (`grep -a "log_file"` — needed `-a` since the raw
   GBK file's control-byte-laden lines otherwise get treated as binary by
   grep) and finding the literal `"static/CRASHES"` there, AND by
   confirming `log/static/{promotion,SUMMON,call_wizard,PURGE}` are real,
   pre-existing seed-data files still present in the raw archive under
   `log/static/` — the corrupted references would have permanently
   orphaned this real on-disk directory. Reverted all 31 occurrences
   (scoped the fix to lines containing `log_file` specifically, to avoid
   touching the two unrelated, correct `nos=="nosave"` string-comparison
   hits in `u/n/nako/npc/kawali.lpc`/`u/e/een/kawali.lpc`).
7. **NEW finding, not previously in AGENTS.md's catalog: bare `SAVE_EXTENSION`
   vs the driver's real predefined macro `__SAVE_EXTENSION__`**. 11 files
   (`obj/token.lpc` + 3 personal-directory copies, `adm/daemons/network/
   netmail.lpc`, `cmds/adm/purge.lpc`/`purgewiz.lpc` + 1 personal copy,
   `include/net/ftpdsupp.h`) reference a bare `SAVE_EXTENSION` macro that
   is never defined anywhere in this mudlib — while `adm/daemons/logind.lpc`
   (which we confirmed compiles and runs cleanly through two full
   interactive registration tests) correctly uses the double-underscored
   `__SAVE_EXTENSION__` form. Verified `__SAVE_EXTENSION__` really is a
   genuine FluffOS-driver-autogenerated preprocessor constant (`grep
   "SAVE_EXTENSION" ~/src/fluffos/build-debug/src/options.autogen.h` →
   `"__SAVE_EXTENSION__", "\".o\""`), confirming the 11 files' bare
   spelling is a real pre-existing bug (likely a naming-convention
   mismatch against whatever the original MudOS-era driver called this
   constant) rather than something our conversion introduced. Fixed with
   a word-boundary sed (`\bSAVE_EXTENSION\b` → `__SAVE_EXTENSION__`,
   safe since `\b` doesn't match between two underscores, so it never
   double-mangles the already-correct 8 files using the real name) — all
   11 confirmed fixed, zero bare occurrences remain. **Worth promoting to
   AGENTS.md's catalog** since it's mechanical, cheap to grep for, and not
   lib-specific (any lib using an unprefixed constant name where this
   driver auto-defines a double-underscored one would hit the same gap —
   `grep ~/src/fluffos/build-debug/src/options.autogen.h` for the full
   list of what this driver actually predefines is the reliable way to
   spot-check any suspiciously-bare constant name like this one).
8. **AGENTS.md §15b, exact recurrence of the `nitan_ceshi` `is_killing`
   finding**: `open/capital/npc/kingwife.lpc` (2 call sites) and
   `open/capital/npc/dog0.lpc` (1 call site) called `is_killing(who)` /
   `is_killing(ob)` directly (not `->`) with an **object** argument, where
   `feature/attack.lpc`'s `varargs int is_killing(string id)` declares a
   `string` parameter — every other call site in the lib (60+, matching
   the established pattern) correctly passes `ob->query("id")`. Fixed the
   3 call sites to `is_killing(who->query("id"))`/`is_killing(ob->query
   ("id"))`, resolving these 2 files' own compile failures plus their
   downstream cascades (`open/capital/room/king/kr3-5.lpc`/`kr4-5.lpc`,
   `u/a/anmy/room/kr3-5.lpc`, `u/t/tide/jar.lpc` — all reference/carry
   these NPCs and failed only because the NPC object itself didn't
   compile, per AGENTS.md §8g's "one shared root cause, not N bugs"
   principle, not independent bugs).
9. **AGENTS.md §15w**, `master.lpc`'s `log_error()`: gated the
   `this_player(1)`-facing live echo on the message NOT containing the
   substring `"warning:"` (still writes everything to the log file
   regardless) — this driver funnels ordinary compile *warnings* (e.g.
   the harmless "Illegal to declare nosave function" warning from our own
   §3 fix) through the same apply as genuine fatal errors, and this lib's
   original `log_error()` echoed EVERY message it received live to
   `this_player(1)` unconditionally, unlabeled as to severity.
10. **Related to §15w**: `master.lpc`'s `error_handler()` is declared
    returning `string`, with a comment "whatever we return goes to the
    debug.log" — but per `docs/apply/master/error_handler.md` this apply
    is `void` on this driver, so the returned string is silently
    discarded and the comment's assumption doesn't hold (confirmed by
    reading the driver's own apply doc, not guessed). Added a permanent
    `efun::write_file("/log/RUNTIME_ERRORS", ...)` insurance write inside
    the handler, same pattern already applied on `wuhanzhan`/archive #58.

## Confirmed NOT needed (checked by reading the actual source, not assumed)

- **§4** (`load_object`-in-`valid_read`/`valid_write` recursion):
  `master.lpc`'s `valid_write`/`valid_read` only ever call `find_object
  (SECURITY_D)` (never `load_object`), degrading to deny/allow
  respectively if not found — no lazy-load-during-compile pattern exists
  at all here, so no recursion risk regardless of `catch()` — this is
  actually a SIMPLER (safer) shape than #53's `master.lpc`, which DID
  have (and needed guarding on) a lazy `load_object(SECURITY_D)` call in
  the same applies.
- **§7** (`get_root_uid`/`get_bb_uid`): both already implemented directly
  in `master.lpc`, returning `ROOT_UID`/`BACKBONE_UID`.
- **§14** (2-arg `valid_override`): `master.lpc`'s `valid_override(file,
  name)` IS 2-arg, but its final fallthrough is an unconditional `return
  1` (only `move_object`/`destruct` outside `F_MOVE` are ever denied) —
  every `#include`d simul_efun-fragment `efun::` override is allowed by
  the same permissive default that would apply to the 3-arg case anyway;
  confirmed via a clean boot + full lpcc sweep with zero
  `valid_override`-related denials anywhere in `debug.log`/`lpcc_fail.log`.
- **§15n** (custom `securityd.lpc` blocking compile-time reads): this
  lib's `valid_read` has the SAFE shape already — its very first
  substantive check is `if (func != "read_file" && func != "file_size" &&
  func != "stat" && func != "read_bytes" && func != "tail" && func !=
  "ed_start") return 1;`, meaning `"load_object"`/`"recompile_object"`/
  `"include"` (none of which are in that exclusion list) are allowed
  UNCONDITIONALLY before the ACL tables are ever consulted — the ACL
  (`exclude_read`/`trusted_read`) only ever gates genuine DATA reads, not
  compile-time file access. Confirmed by reading the function in full;
  no fix needed (this is actually a more robust default than several
  other libs in this family that needed §15n's explicit `switch(func)`
  early-allow patched in).
- **§15s/§15aa** (`message()`/`tell_room()` wrapper passing a bare `int 0`
  exclude argument, or a same-named wrapper miscompiling to the real
  efun): `adm/simul_efun/message.lpc`'s `tell_room(ob, str)` (2-arg form)
  does pass its unset `object *exclude` varargs parameter (defaulting to
  `0`) straight through to the real `message()` efun's 4th argument, the
  same shape §15s originally found broken on `yueyingqiyuan`. But reading
  this driver's actual `f_message()` implementation
  (`~/src/fluffos/src/packages/core/efuns_main.cc`) shows the 4th-arg
  handling already gracefully degrades ANY non-object/non-array value
  (including a bare `T_NUMBER` 0) to `avoid = &the_null_array` — no
  `bad_argument()` call for that argument at all. No fix needed; verified
  empirically too, since this file's `tell_room()` fires on every room's
  ordinary broadcast throughout both full interactive test sessions with
  zero `debug.log` errors. (§15aa's self-name-shadowing risk doesn't
  apply either — this file never defines its own `message()` override at
  all, so every `message(...)` call inside it binds straight to the real
  efun as intended, no forward-declaration ordering issue possible.)
- **§15l** (`master.lpc create()` destructing/reloading `SIMUL_EFUN_OB`):
  grepped for `destruct`/`efun::destruct` targeting `SIMUL_EFUN_OB`/
  `MASTER_OB` in `master.lpc` — none present.
- **§15x** (hardcoded `MUD_PORT` mismatch): `master.lpc`'s `connect()`
  apply takes no arguments and does no port comparison at all; grepped
  `include/`/`adm/` for `MUD_PORT`/`PORTNO`-shaped constants — the only
  hit is an unrelated driver-side config-key name string inside a
  comment in `include/runtime_config.h`, not a mudlib-side dispatch gate.
  Confirmed empirically too: both interactive test connections succeeded
  on port 40063 with no rejection.
- **§8e** (`tail()` fake efun): zero `efun::tail`/bare `tail(` call sites
  anywhere in `adm/simul_efun`.
- **§15f** (bare `array` declarations): zero matches for the `array
  name;`/`array name = expr;` shape.
- **§8f** (`TYPE * a, b;` forgotten-star bug): 214 instances of the
  `TYPE *name1, name2` comma-list shape found via grep; spot-checked
  several (`string *k, list=""` in `std/room/shop.lpc`, `object
  *enemy,target` in `open/japan/npc/master.lpc`) and confirmed each is
  **intentionally** mixed (the starred variable is genuinely used as an
  array, the bare one genuinely assigned a scalar a few lines later) —
  same conclusion as archive #53's identical check on this same lineage.
  No fix applied.
- **§15u** (dormant phone-home/license-check deletion trap): grepped
  `securityd.lpc`/`master.lpc` for mass-deletion or `shutdown()` gated on
  an opaque check — nothing resembling this pattern found.
- **Encoding stragglers**: `convert_lib.sh` reported only 1 lossy file
  (`data/emoted.o`, a save-data file — same category of acceptable
  minor loss on seed/example data documented for every prior lib in this
  family). A follow-up `file`-classifier sweep for the known "misclassified
  as data" false-positive pattern (§1) found no additional stragglers.

## Known lpcc-sweep failures NOT fixed (pre-existing content bugs/gaps, not driver-compat)

Triaged the remaining 319 failures (after the fixes above took the sweep
from 91.8% to 95.0%) by grouping error messages by shape, per AGENTS.md
§6b — none of these are on the registration/boot path (confirmed clean
via two full interactive tests) and all are scattered across personal
wizard sandbox directories (`u/f/fund`, `u/b/bigcat`, `u/r/ryn`, `u/k/konn`,
`u/h/hitler`, `u/e/een`, etc. — 200+ of the 319 failures) or orphaned
utility content, not core game infrastructure:

- **~150 files, "Illegal character 0xNN" spanning many distinct shapes**
  (spot-checked ~10 to confirm variety before deciding NOT to risk a
  blanket regex fix, matching archives #53/#63's own precedent for this
  exact category): a stray backslash immediately before a fullwidth
  Chinese punctuation mark inside a string literal (e.g. `"...大餐\，不知
  道..."` — the lexer treats `\` as starting an escape sequence, then
  chokes on the following multi-byte UTF-8 character's raw bytes one at a
  time), missing `+` concatenation between ANSI-color macros and adjacent
  quoted text (same shape as #53's own "known, not fixed" category), a
  literal terminal escape sequence (`[D[D[D[2~`) accidentally typed into
  a `set_name()` call, and a handful of genuinely malformed quote/escape
  sequences in flavor text. All decorative/flavor content (item
  descriptions, skill names, NPC dialogue), never touched by registration.
- **34 files, "unexpected L_CLASS"**: source using the bare identifier
  `class` as a variable/parameter name (`string class=""`,
  `receive_message(string class, string msg)`) — `class` is a reserved
  word in this driver's grammar (used for LPC struct-style `class`
  declarations), a genuine pre-existing authoring collision, not
  something this conversion introduced. Scattered across personal wizard
  directories (`u/w/wade`, `u/a/anmy`, `bin/`), none reachable from the
  registration/boot path.
  
- **27 files, "Illegal LHS"**: source using the bare identifier `new` as a
  variable name (`new = allocate_mapping(3); new["name"] = ...`) — `new`
  is a reserved keyword (object-instantiation efun) on this driver,
  same "identifier collides with a reserved word" root cause as the
  `class` category above, just a different keyword. `open/poison/room/
  r1.lpc`/`r2.lpc` (a small, isolated quest room pair) account for a
  chunk of these; the rest are scattered personal-directory files.
- **~39 files, "Illegal to redefine 'nomask' function"** (`_set`/
  `_query`/`_delete`/`set_path`/`query_busy`/`is_busy`/`command_hook`):
  a real multiple-inheritance diamond conflict (two inherited bases both
  declaring the same `nomask` function name) in a scattered set of
  personal-wizard/orphaned NPC files (`open/capital/npc/solder_officer`,
  several `u/f/fund/*` files, `u/o/oda/npc/boss4`, `u/o/onion/npc/vendor`,
  `u/w/wade/room/casino`) — not a shared single root cause fixable in one
  shot (each file's own specific pair of conflicting inherits differs),
  and none are on the registration/boot path.
- **18 files, "Undefined variable 'SAVE_EXTENSION'"**: already fixed, see
  item 7 above — this count is the PRE-fix number, included here only for
  completeness of the "before" triage; zero remain after the fix.
- **~9 files, `adm/daemons/network/*`** (`ms`, `userid`, `pingtcp`,
  `name_server`, `mail_serv`, `netmail`, `telnetd`, `pingd`, `inetd`):
  orphaned network utility daemons, none present in `adm/etc/preload`,
  same category as AGENTS.md §12/§13's documented orphaned-content
  pattern — not fixed, never reached by any live code path.
- **~8 files, `cmds/std/*`** (`guild`, a "复件 help" backup-copy file,
  `to`, `unwieldd`, `sig`, `do`, `describe`, `song`): ordinary in-game
  admin/player commands with their own pre-existing typos/bugs, not on
  the registration path (confirmed via the clean interactive test), left
  as-is per AGENTS.md's "prioritize breadth over depth" guidance.

## Config notes

`config.fluffos` adapted from the lib's own `config.fs` (converted to
UTF-8 before any other edit, per AGENTS.md §5). Dropped `address server
ip`/`address server port` (external intermud-address-resolution service,
irrelevant here), `binary directory` (obsolete, matches #53's finding),
`swap file` and `reserved size` (both obsolete-key warnings on this
driver, same as #53). `mudlib directory` set to the absolute
`libs/kuangxiangkongjian/work` path (this driver requires it, unlike the
original MudOS-era `./`-relative convention). Created `work/adm/tmp/`,
`work/binaries/`, `work/data/` (referenced by config/save-data paths, not
guaranteed to exist as empty dirs after RAR extraction) and the sibling
`log/` directory (per AGENTS.md §6, the driver's `log directory` resolves
relative to CWD, not mudlib root — always launched via `cd
libs/kuangxiangkongjian && driver config.fluffos`).

## Registration-flow transcript (verified end-to-end, twice)

Read `adm/daemons/logind.lpc`'s full callback chain before scripting the
test: `logon → get_id → confirm_id → get_name → new_password →
confirm_password → get_gender → get_points ×7 → enter_world →
press_enter`. No hidden pre-id client-version/BIG5 gate (the very first
prompt is the real English-id prompt) and, notably, **no email-collection
step at all** (unlike archive #53's copy of this same file, which does
prompt for email — confirming again that this is an earlier/different
snapshot, not the same file). Point allocation is 8 attributes/160 points
average 20 each; only 7 are prompted individually
(`str,cps,int,cor,con,spi,per`) — the 8th (`kar`) is auto-computed as the
exact remainder the instant the `per` prompt is answered, going straight
to `enter_world()` with no further prompt (identical structure to #53's
copy of this same logic, just without the email step).

**Run 1** — `python3 scripts/mudclient.py 127.0.0.1 40063 --timeout 40
--idle 1.2`, one continuous connection, `--send` sequence: `qinfeng`
(English id) → `y` (confirm new character) → **real Chinese name "秦风"**
(2 characters) → `test1234` (password) → `test1234` (confirm) → `m`
(male) → `20`×7 (attribute points) → `` (press enter) → `look` → `quit`.

Outcome: id accepted, confirmation accepted, **"秦风" (a genuine
2-character Chinese name) accepted by the fixed `is_chinese`/
`check_legal_name`**, password/confirm/gender/all 7 attribute prompts
proceeded correctly, character creation completed, and the character was
dropped into the **real starting room** ("世界的入口" — "World Entrance"),
with the room's full Chinese description, exits, an in-game board
message, and the MOTD bulletin all rendering correctly. `look`
re-displayed the room correctly; `quit` produced the expected item-drop
message ("你丢下一件布衣。") and a clean goodbye ("欢迎下次再来！你离开
游戏。"). Zero crashes, zero permission-denied errors.

**Run 2** (fresh id/name, same driver process, confirming no anti-flood
throttle issue — grepped for `NewIps`/`IsTimeAllowed`-shaped patterns
first and found none in this lib, so no cooldown wait was needed):
`qinfengb` → `y` → **real Chinese name "秦风二"** (3 characters) →
`test5678` → `test5678` → `f` (female) → `20`×7 → `` → `look` → `quit`.
Identical clean outcome, correctly using female pronoun forms ("妳丢下
一件布衣。"/"妳离开游戏。") this time.

**`debug.log` across both sessions combined**: zero occurrences of
`error`/`denied`/`fail`/`crash`/`undefined`/`bad argument`/`recursion`/
`access` beyond the harmless boot-time compiler warnings (unused local
variables, "Unknown #pragma", two "Unknown escape sequence '\<Chinese
char>'" warnings from stray backslashes in flavor text — same non-fatal
category as the "Illegal character" sweep findings above, just below the
severity threshold that would make lpcc treat them as hard failures for
those two particular files since they occur inside the `write()`-adjacent
`feature/message.lpc`/`std/bboard.lpc`, which DO compile).

## lpcc sweep

`scripts/lpcc_check.sh libs/kuangxiangkongjian/config.fluffos
libs/kuangxiangkongjian/work`, run twice:

1. **First pass** (before the sweep-discovered fixes above, but after all
   proactive pre-boot fixes): `total=6323 pass=5804 fail=519` (91.8%).
2. **Final pass** (after fixing the 187-file inherit-ordering cluster, the
   11-file `SAVE_EXTENSION` typo, and the 3-call-site `is_killing` bug, all
   described above): **`total=6323 pass=6004 fail=319` (95.0%)**. The
   remaining 319 failures were re-triaged by error-message shape and
   confirmed to be exactly the "known, not fixed" categories documented
   above (reserved-word identifier collisions, a `nomask` multiple-
   inheritance diamond conflict, decorative-text escape/concatenation
   typos, and orphaned network-daemon/admin-command content) — zero new
   or unexplained failure categories introduced by any fix, and zero
   failures trace back to the registration/boot path (independently
   confirmed by the two clean interactive tests above).

Driver process launched via the Bash tool's own `run_in_background`
equivalent (`setsid nohup ... & disown`), confirmed dead by exact PID
before finishing (no broad `pkill` used).
