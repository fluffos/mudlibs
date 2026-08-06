# shenmo — notes

## Identity

- **Archive**: `archives/神魔20190924版本.rar` ("Gods and Demons, 2019-09-24 build"), 98MB, archive #73.
- **Self-identified name** (from `config.cfg`'s `name :` field, GBK-decoded): **西游记之神魔传说**
  ("Journey to the West: Legend of Gods and Demons") — the raw archive's root directory is
  `xyj/` (pinyin initials of *Xī Yóu Jì*, "Journey to the West"). The archive title's "神魔"
  is the tail half of the game's own full name, not a different name — no discrepancy to flag
  beyond noting the fuller self-identified form here, per the task's ask.
- **Lineage**: "ES II" / **Neolith 0.0.2** engine by **Annihilator** (same engine family as
  `es1_win`/`esI`/`xkx2001`/`rzrmud`/`bmxkx2001`/`kxkj`/
  `yueyingqiyuan`/`wuhanzhan`/`yanhuangwuhun`/`haiyang2`/`kxkj1`/`huoying` — the
  largest single family in this project). `adm/obj/master.c`'s own header comment reads
  "for ES II mudlib / original from Lil / rewritten by djx (09/09/2003) / xfan 3.10". Many
  personal wizard directories (`u/djx`, `u/fang`, `u/snowtu`, `u/cloud`, `u/tom`, `u/stey`,
  `u/xdao`, ...) are preserved in the archive, spanning credited edits from 1994 (Annihilator)
  through 2013 (per a stray `logind_20130609.c` in `u/fang/`) — this is a long-lived, actively
  developed lib, consistent with the task's expectation of "more modern/recently-maintained".
  `emoted.lpc`'s header even reads "神话世界·西游记·版本４．５０" (a DIFFERENT, older
  branding than the current config — a leftover comment from an earlier fork/version,
  harmless).
- Bundled prebuilt Windows/Cygwin driver binaries (`fluffos64/` — `driver.exe` + Cygwin DLLs,
  `MudOSxp.exe`, `mudos.dll`) exist alongside the LPC source at the mudlib root — ignored per
  convention, not part of the mudlib, our own `build-debug` driver is used throughout.
- **Orphaned nested duplicate**: a whole second, older mudlib snapshot lives at `sjsh/` (own
  `std/`, `quest/`, `obj/`, `u/` subtrees, `debug.log`, `mudos.prf`, `OBJ_DUMP`, `PROFILE` —
  2226 files, 15MB) sitting at the mudlib root alongside `adm/`, `d/`, `cmds/`, etc. Confirmed
  via `grep -rl "sjsh"` that NOTHING in the active tree references this path — it is dead
  weight from some earlier backup/test-server copy embedded in the archive, not loaded by
  anything reachable from `master.lpc`'s preload chain or normal gameplay. Left in place
  (harmless, just extra disk/file-count) rather than deleted, consistent with this project's
  general "don't delete archive content, just note it" policy.
- A handful of stray filenames throughout the tree carry double-mojibake Chinese text baked
  into the filename ITSELF (e.g. `include/globals.h(澶囦唤)`, a "(备份)"/"(backup)" suffixed
  duplicate whose parenthetical got corrupted at some point before this archive was ever
  created — re-encoding the display bytes as GB18030/BIG5 does not recover them). These are
  all orphaned backup-suffixed duplicates of already-present files (`globals.h`, `story.h`,
  `securityd.c`, room files under `sjsh/u/calvin/room/`, etc.), never referenced by path
  anywhere, so left as-is; noted here rather than chased further given the scale of the
  archive.

## Scale (why several steps below deviate from the small-lib default)

- **53,363 raw files, 683MB** (`raw/xyj/`). After conversion: **33,196 `.lpc`+`.h` files, 740MB**
  (`work/`) — this is comfortably in "mega-lib" territory (bigger than `nitan6`'s 23,100 files,
  though smaller than `nitan170911`'s 54,600). `find`/`grep`/`iconv` passes over the whole tree
  each took real wall-clock minutes; the full GBK→UTF-8 encoding pass alone took ~35 minutes.
- **Deliberately skipped the `scripts/convert_lib.sh`-internal "local `#include <x>` → quoted"
  pass and the `lpcc_check.sh` full sweep, both per AGENTS.md §6b's mega-lib guidance** — see
  the two dedicated notes below for why each is safe to skip here specifically (not just "too
  slow to bother").

## Encoding

- Base encoding is GBK/GB18030, converted via the standard `convert_lib.sh` pass (already_utf8:
  3898, converted: 48470, **lossy: 734** — a large lossy count for this project, proportional
  to the archive's size), `skipped_binary: 256`.
- **§15y (mixed GBK+BIG5) confirmed, same as `huoying`** — this lib shares the exact same
  Neolith-engine "Annihilator (09/07/2000)" config-file boilerplate header as `huoying`, and it
  is BIG5-encoded (not GBK) in both places: the `Neolith 0.0.2 組態檔` / `作者：Annihilator`
  header comment, AND the `default fail message` / `default error message` values. Confirmed
  by direct byte-level decode test (GBK decode of the author-credit line throws an invalid-byte
  error; BIG5 decodes it cleanly to legible Chinese). Fixed by hand when building
  `config.fluffos` (see below) — the rest of `config.cfg`/the whole `work/` tree is ordinary
  GBK and converts cleanly through the normal pipeline.
- `data/emoted.o` (the emote-definitions save file) hit `convert_lib.sh`'s `iconv -c`
  lossy-conversion fallback (invalid bytes dropped) — this is the **exact same file/symptom**
  AGENTS.md's own Encoding section already documents from the very first pilot lib
  (`shzs`: "seen: `emoted.o`, position 25324"). Confirmed this manifests here as a
  genuine, harmless runtime symptom (see "Known, not fixed" below), not a new bug.

## Fixes applied (with why)

1. **§15h, `is_chinese()` GBK byte-range bug** — `adm/simul_efun/chinese.lpc`:
   `if( strlen(str)>=2 && str[0] > 160 && str[0] < 255 ) return 1;` (a GBK lead-byte range
   check, comparing a full UTF-8 codepoint against 160-255 — always false for real Chinese
   text under this driver) → fixed to
   `if( strlen(str)>=1 && str[0] >= 0x4e00 && str[0] <= 0x9fff ) return 1;` (CJK Unified
   Ideographs codepoint range, `strlen>=1` since one UTF-8 index is already one full
   character). Confirmed this is the function actually used by registration (traced
   `check_legal_name` → `is_chinese`, both in the live `logind.lpc`/`adm/simul_efun/chinese.lpc`
   chain).
2. **§15h, `named.lpc`'s `PATH()` sharding macro** — `adm/daemons/named.lpc`:
   `#define PATH(name) (name[0..1] + "/" + name)` ("first GBK character" under the old
   byte-indexed convention, now grabbing the first TWO UTF-8 characters) → fixed to
   `name[0..0]` (first character only).
3. **§15h, `check_legal_name()` in `adm/daemons/logind.lpc`** — two sub-fixes in the same
   function:
   - `strlen(name) < 2 || strlen(name) > 12` (message text explicitly says "一到六个中文字"
     — 1 to 6 Chinese characters — the byte-doubled bound of 2-12 was calibrated for the old
     2-bytes-per-character GBK convention) → halved to `strlen(name) < 1 || strlen(name) > 6`.
   - `if( i%2==0 && !is_chinese(name[i..<0]) )` (the `i%2==0` gate existed to land on every
     OTHER byte position — the lead byte of each 2-byte GBK character; under UTF-8 every index
     is already one full character) → dropped the `i%2==0 &&` entirely, so every character
     position is checked, matching §15h's item 3 pattern exactly.
4. **§8d/§15o, missing `master::get_include_path()`** — found **1706 files** throughout the
   content tree (`d/`, `obj/`, `cmds/`, `kungfu/`, `daemon/`, `quest/`, `u/`) using
   `#include <flavor.h>`-style angle brackets for a same-directory "flavor" header (e.g.
   `d/kaifeng/ground.c` `#include <ground.h>`, `d/kaifeng/npc/bing.c` `#include <greeting.h>`)
   — identical shape to the `es1_win`/`esI` lineage's documented §8d bug. **Crucially confirmed
   zero of these 1706 hits are inside `adm/daemons/`, `adm/obj/`, or `adm/simul_efun/`**
   (`grep -c '^\./adm/daemons\|^\./adm/obj\|^\./adm/simul_efun'` on the hit list returned 0) —
   meaning none of the preload-critical bootstrap chain is affected by the §15o "no VM
   context at preload time" timing gotcha; the get_include_path() master apply alone is
   sufficient for every one of these 1706 files since they're all reached lazily,
   mid-connection, well after master/simul_efun/logind are loaded. Added the standard:
   ```lpc
   string *get_include_path(string file)
   {
       string *parts = explode(file, "/");
       if (sizeof(parts) <= 1)
           return ({ "/", ":DEFAULT:" });
       return ({ "/" + implode(parts[0..<2], "/"), ":DEFAULT:" });
   }
   ```
   to `adm/obj/master.lpc`. **This is the reason the physical "convert local `<x.h>` includes
   to quoted form" pass inside `convert_lib.sh` was deliberately killed partway through** (see
   "Deviations from the standard pipeline" below) — the master-apply fix is a complete,
   driver-level substitute for the file-by-file quote conversion for every one of these 1706
   cases, confirmed by the interactive test successfully reaching and lazily-compiling several
   of the exact affected files (`d/city/kezhan.lpc`, `d/city/npc/xiaoer.lpc`,
   `d/city/npc/liwu7.lpc`, all originally using `<ansi.h>`/local headers) with no `Cannot
   #include` errors anywhere in `debug.log`.
5. **§3, `static` → `nosave`** — 299 files touched by the blanket word-boundary sed (function
   declarations only; no bare `array`/other §15f-family issues found in this lib).
   **§3 counterexample confirmed and reverted**: this lib uses `"static/CRASHES"`,
   `"static/security"`, `"static/PURGE"`, etc. as a `log_file()` subdirectory-naming
   convention (same idiom as `moniHuafu`/`yanhuangwuhun`) — real, pre-existing seed data
   exists on disk at `log/static/{CRASHES,security,PURGE,gift,promote,...}`. The blanket sed
   corrupted **82 files'** string literals to `"nosave/..."`; reverted all 82 with a targeted
   `sed -i -E 's/"nosave\//"static\//g'` scoped to only the files flagged by
   `grep -l '"nosave/'`. Verified zero `"nosave/` string-literal hits remain and all 82
   `"static/` literals are restored. **Also checked, not present**: no
   `#define nosave static`/`#define protected static` compatibility shim anywhere in
   `include/*.h` (the §15z collision case) — confirmed via direct grep, nothing to revert
   there.
6. **New pattern, not previously seen in this project: uppercase `.C` extension rename** —
   **363 files** throughout the content tree (`obj/npc/LUOHAN1.C`, `d/newjob/longzhu/obj/*.C`,
   `d/quest/newequip/**/*.C`, `daemon/class/**/*.C`, etc.) use an **uppercase** `.C` extension
   instead of the usual lowercase `.c` — genuine LPC source (spot-checked several: real
   `inherit ITEM;`/`set_name()`/`create()` object bodies, not driver C source or data).
   `convert_lib.sh`'s rename step only globs lowercase `*.c` (case-sensitive on this Linux
   host), so these 363 files were untouched by the normal rename pass and would have stayed
   permanently unloadable (any code path expecting to find `foo.c`/`foo.lpc` at that path
   would fail) — worked fine on the original author's Windows/case-insensitive dev filesystem,
   the same root cause class as §15g/§15k, just applied to whole compilable objects rather
   than `#include`s or plain data reads. **Fixed with an additional
   `find . -name "*.C" -print0 | xargs -0 ... mv ... .lpc` pass** after the normal
   `convert_lib.sh` run, alongside the same literal-`.c"`-reference re-check (found and fixed
   6 more stray refs this exposed). **Worth adding to AGENTS.md's catalog** — grep any new
   lib for `find . -name "*.C"` early, since a case-sensitive-only rename glob is an easy
   thing to miss when every other lib in this project so far has used lowercase `.c`
   uniformly.
7. **§15w, `log_error()` broadcasting ordinary compile warnings as scary player-facing
   messages** — confirmed via a live before/after test (see "Registration + post-login test"
   below): `adm/obj/master.lpc`'s `log_error()` did
   `if(this_player(1)) efun::write("编译时段错误：" + message+"\n");` unconditionally, and
   this driver funnels every soft compile *warning* (`Illegal to declare nosave function`,
   `Unknown #pragma, ignored` — this lib's `#pragma optimize`/`#pragma save_binary` directives
   aren't recognized by this driver — `Unused local variable`, `Number of arguments to 'X'
   disagrees with previous definition`) through the identical apply as genuine fatal errors.
   Because a brand-new character's first `look`/`score`/etc. is very often the FIRST time in
   a driver session that a given room/NPC/command file gets lazily compiled, a fresh
   registrant saw a wall of `编译时段错误：...warning: ...` lines that look exactly like
   real crashes, immediately after finishing registration and again on the very first `look`.
   **Fix**: gated the broadcast on the message NOT containing `"warning:"`
   (`if(this_player(1) && strsrch(message, "warning:") == -1) efun::write(...)`) — still
   writes every message (including warnings) to the log file via the unconditional
   `efun::write_file(home + "log", message);` line right below, just stops broadcasting
   harmless warnings to the connected player. **Verified fixed**: re-booted the driver after
   this edit and re-ran a full fresh registration (new id `qfengliu`/name `秦风六`) — zero
   `编译时段错误` lines appeared anywhere in the transcript despite `look`/`score`/`quit`
   being the very first compile of `cmds/std/look.lpc`/`cmds/std/score.lpc`/
   `cmds/usr/quit.lpc` in that driver session (confirmed via `debug.log`: 334 `warning:`
   lines still logged to file, correctly suppressed from the player).

## Confirmed NOT needed (and how confirmed — read the actual source, not guessed)

- **§4 (`load_object()`-during-compile recursion in `valid_read`/`valid_write`)**: read
  `master.lpc`'s `valid_read`/`valid_write` in full — both are the simple
  `if (ob = find_object(SECURITY_D)) return (int)ob->valid_X(...); return 0/1;` shape with
  **no `load_object()` call at all**. No recursion risk; confirmed by a clean boot with no
  `Too deep recursion`/`Object cannot be loaded during compilation` anywhere in `debug.log`.
- **§7 (missing `get_root_uid`/`get_bb_uid`)**: both present verbatim in `master.lpc`
  (`return ROOT_UID;` / `return BACKBONE_UID;`) — driver boots without the `set_master()`
  `exit(-1)` this fix normally prevents.
- **§15l (`create()` destructing `SIMUL_EFUN_OB`)**: `master.lpc create()` is a single
  `write("master: loaded successfully.\n");` line — no `destruct()` call anywhere in it.
- **§15n (custom `securityd` blocking mid-connection `load_object`/`include`)**:
  `adm/daemons/securityd.lpc`'s `valid_read` already has the correct shape — it early-returns
  `1` for any `func` OTHER than `read_file`/`file_size`/`stat`/`read_bytes`/`tail`/`ed_start`,
  meaning `load_object`/`recompile_object`/`include`/`restore_object` (handled by a separate
  earlier branch) are already effectively allowlisted. No fix needed; confirmed by a completely
  clean registration flow with zero `Read access denied` anywhere in `debug.log`.
- **§8c (`this_player()`-override footgun in `securityd`)**: no such override pattern exists —
  `valid_read`/`valid_write` derive `euid`/`status` directly from the passed-in `user`
  parameter (`geteuid(user)`), never re-assigning `user = this_player()`.
- **§15p (DNS/intermud daemon in preload)**: `adm/etc/preload` (the file actually read by
  `master.lpc epilog()`, confirmed via `CONFIG_DIR + "preload"` = `/adm/etc/preload` exactly)
  has **no** `dns_master` entry — 27 daemons listed, none network/DNS-related. A stray, unused
  `adm/etc/preload.mud` backup file DOES list `/adm/daemons/network/dns_master`, but it is
  never read by anything (same "leftover backup preload copy" pattern documented on
  `wmkj`) — confirmed via `epilog()`'s exact literal string. No inline
  `dns_master`/`DNS_MASTER` calls anywhere outside the `network/` subsystem's own internal
  files either (checked the §15ab variant proactively). Boot completed in well under 5 seconds.
- **§14 (2-arg `valid_override`)**: `master.lpc`'s `valid_override(string file, string name)`
  is the old 2-arg form, but read its full body — the restricted-override list is only
  `({"shutdown","localtime","ctime","exec","snoop","destruct"})`, and the only
  `efun::`-prefixed call inside an `#include`d simul_efun fragment (`write()` in
  `adm/simul_efun/message.lpc`, via `efun::write(str)`) is not on that list at all — it falls
  through to the final unconditional `return 1;` regardless of the 2-arg/3-arg distinction.
  Confirmed this never actually matters for this lib by reading the full function; not applied
  (a deliberate, checked "skip", not an oversight — differs from several other libs in this
  project where the 3-arg upgrade was applied proactively "for free").
- **§15s (`tell_room` 2-arg `message()` bad-4th-arg crash)**: read
  `adm/simul_efun/message.c`'s `tell_room(mixed ob, string str, object *exclude)` →
  `message("tell_room", str, ob, exclude)`, where `exclude` can be an unset/default `0`. Then
  read this driver's own `f_message()` implementation
  (`~/src/fluffos/src/packages/core/efuns_main.cc`) directly: the 4th argument's `switch`
  only special-cases `T_OBJECT`/`T_ARRAY`, and its `default:` case (covering a bare `int 0`)
  silently sets `avoid = &the_null_array;` with **no `bad_argument()` call at all** for that
  argument position (`bad_argument()` is only ever invoked for the 3rd argument, `use`, in
  this function). Confirmed this driver's exact build tolerates a raw `0` in `message()`'s
  4th slot gracefully — the §15s bug (found on `yueyingqiyuan`) evidently does not reproduce
  here; not fixed since reading the actual efun source shows there is nothing to fix.
- **§15t (absolute-path angle-bracket / `..`-relative / inherit-after-globals)**: grepped for
  all three specific shapes; zero hits for any of them.
- **§15u (dormant "phone-home" destructive license check)**: grepped `securityd.lpc`/
  `master.lpc` for suspicious `rm`/`unlink`/`shutdown`-gated-on-opaque-check functions; none
  found.
- **§15v (`LONELY_IMPROVED`-gated `efun::` family / bignum `count()`)**: this is NOT the
  NT/nitan/Lonely lineage — `feature/dbase.lpc` already implements real, local
  `set`/`query`/`delete` (confirmed early, alongside the §15 "bare simul_efun dbase" check
  below), and no `LONELY_IMPROVED` macro exists anywhere in `include/*.h`.
- **§15 (bare simul_efun-based `set`/`query`/`delete` dbase architecture bug, the
  nitan/NT/Lonely-family's signature issue)**: does NOT apply — `feature/dbase.lpc` already
  defines real local `set(string prop, mixed data)`/`query`/`delete` methods (inherited
  directly, not routed through a bare simul_efun call). Confirmed additionally via
  §15b's usual "never defined, only called" simul_efun family check: `addn`/`addn_temp`/
  `remove_ansi`/`noansi_strlen`/`B2G`/`db_affected`/`clr_ansi`/`chinese_number`(*)/
  `changed_match_path`/`query_bandwide`/`query_shadowed` all show **zero call sites** in
  this lib except `chinese_number`, which IS properly defined (`CHINESE_D->chinese_number(i)`,
  delegating to `adm/daemons/chinesed.lpc`'s real implementation) — confirms this lib's
  lineage never had the nitan-family architecture at all, consistent with it being ES
  II/Neolith rather than NT/nitan/Lonely.
- **§15aa (same-named `message()` wrapper ordering bug)**: `adm/simul_efun/message.c` defines
  `tell_room`/`tell_object`/`shout`/`write`/`say` but has **no local override of `message()`
  itself** — every call is directly to the real efun, so the "wrapper calls itself before its
  own definition" footgun (found on `yanhuangwuhun`) cannot occur here; there is no wrapper.
- **§15ae (`private nomask` command-hook silently breaking every post-login command) —
  the standing policy this pass was explicitly told to check hardest**: `feature/command.c`
  line 35 has a **commented-out** `// private nomask int command_hook(string arg)`
  immediately followed by the ACTIVE line 36, `nomask int command_hook(string arg)` — **no
  `private`**. This lib's own maintainers apparently already hit and fixed this exact bug at
  some point in its (long, multi-author) history, independent of this project. Confirmed via
  `grep -rn "private nomask"` across the whole tree — **zero occurrences anywhere**. Also
  empirically confirmed twice over via the interactive test: `look`/`score`/`quit` all fired
  correctly after registration in every successful run.
- **§8e (`tail()` missing efun)**, **§8h (`convertd.lpc` Greek-table backslash typo)**,
  **§15c (bare `.c` refs in `adm/etc/preload`)**, **§15f (bare `array` type)**: all grepped for
  specifically; zero hits for each.
- **§8f (`TYPE * a, b;` forgotten-star array bug, Dead Souls' signature issue)**: grep found
  621 files matching the broad "starred type followed by a bare comma-separated identifier"
  shape, but spot-checked ~20 samples across different subsystems (`kungfu/class/*`,
  `std/weapon/weapon.lpc`, `feature/equip.lpc`, `feature/condition.lpc`, ...) and every one
  uses CORRECT, INTENTIONAL C-style single-declarator scoping (e.g.
  `object *inv, obj, weapon, me = this_player();` — only `inv` is genuinely meant to be an
  array; `obj`/`weapon`/`me` are deliberately scalar, confirmed by their subsequent
  single-object assignments). This lineage's authors understood the driver's actual scoping
  rule correctly (unlike Dead Souls' English/Nightmare-lineage authors) — **not** applying
  a blanket fix here; this is a different codebase culture, not a bug.

## Known, not fixed (pre-existing content issue, documented per AGENTS.md's own precedent)

- **`data/emoted.o` corrupted seed data**: `convert_lib.sh` flagged this file as a lossy
  conversion (invalid bytes dropped). At boot, `adm/daemons/emoted.lpc`'s `create()` calls
  `restore()` unguarded, which throws `*restore_object(): Illegal mapping format while
  restoring emote.` — the exact same file/symptom pair AGENTS.md's own Encoding section
  documents from the very first pilot lib (`shzs`). The emote-definitions daemon's
  `emote` mapping simply stays unset (no further gate depends on it — checked, unlike the
  `zhonghua2`/§15m case, this does NOT masquerade as any kind of maintenance/sync block; the
  driver's own `catch(call_other(file, "??"))` around each `preload()` call absorbs the error
  and moves on). Practical effect: the `emote`/social-emote command's built-in emote table is
  empty for this session; everything else (registration, movement, combat scaffolding, boards,
  NPCs) is unaffected. Not fixed, matching the project's stated policy of accepting minor loss
  on save/seed data.

## Deviations from the standard pipeline (and why, given the file count)

- **Killed `convert_lib.sh`'s "convert local `#include <x>` to quoted form" step partway
  through** (after the encoding/rename/literal-`.c"`-reference passes had already completed
  cleanly) once it became clear this per-file grep+sed pass (with no progress logging) was
  going to take a very long time across 30k+ files with heavy fork overhead, most of it
  spent on `#include <globals.h>` (present in nearly every file) which never has a local
  match. **This was a deliberate, informed substitution, not a shortcut**: confirmed first
  that (a) none of the 1706 files needing the fix live in the preload-critical
  `adm/daemons`/`adm/obj`/`adm/simul_efun` directories (§8d fix #4 above), and (b) the
  `master::get_include_path()` apply added instead is the textbook, fully equivalent fix for
  every one of those 1706 cases per AGENTS.md §8d/§15o — then verified empirically that
  several of the exact affected files compiled and loaded correctly during the interactive
  test with zero `Cannot #include` errors anywhere in `debug.log`. The (never-run)
  `static → nosave` sed step from the same killed process was re-run separately by hand
  afterward (see fix #5 above) so nothing was actually skipped, only the physical
  quote-conversion pass was substituted for its driver-level equivalent.
- **Skipped the full `scripts/lpcc_check.sh` sweep entirely**, per AGENTS.md §6b's mega-lib
  guidance — 33,196 `.lpc`/`.h` files is larger than `nitan6`'s 23,100 (already treated as
  mega-lib scale and skipped), and the host had several OTHER agents' concurrent
  `lpcc --batch` processes running at the time (each holding 1-2GB RSS), making an unbounded,
  unloading-none `lpcc --batch` run on a lib this size a real risk to host memory as
  documented. Relied on the boot + interactive-test pipeline instead — per the same section,
  "the test that actually caught every real bug found on nitan170911/nitan6...is a perfectly
  sufficient signal on its own for a lib this size." Individually spot-checked the
  bootstrap-critical chain with single-file `lpcc` runs before the first full boot
  (`/adm/obj/master`, `/adm/daemons/named`, `/adm/daemons/logind`, `/adm/daemons/securityd`,
  `/adm/simul_efun/chinese`, `/d/city/kezhan` — all exit 0, no errors) as a cheaper
  pre-boot sanity gate.

## Boot

- `~/src/fluffos/build-debug/src/driver config.fluffos`, launched from `libs/shenmo/` via
  `setsid nohup ... & disown` (per AGENTS.md §6's reliability note). Boots in a few seconds.
  `debug.log` is completely clean apart from the one documented `emoted.o` restore error above
  — no `Read access denied`, no `Undefined function`, no `Bad argument`, no segfault, no
  `Cannot #include`, no recursion.
- Config adapted from the archive's own `config.cfg` (`iconv`'d BEFORE any edit, per AGENTS.md
  §5, with the two BIG5-encoded lines hand-decoded separately as described above): port
  `40067`, `mudlib directory` set to the absolute `work/` path, dropped-then-warned-about
  obsolete keys (`reserved size`, `binary directory`, `swap file` — driver prints
  "obsolete line in config file" warnings for these, harmless, matches the pattern already
  seen on every other lib in this project using the same MudOS-0.9.20-era config shape).

## Registration + post-login test (the critical, most-important verification)

Ran the FULL flow in single continuous `mudclient.py` connections, reading the actual
`logind.lpc` `input_to` callback chain first (encoding → if_young → get_id → get_new_id →
confirm_id[auto] → get_name → new_ad_password → confirm_ad_password → new_password →
confirm_password → get_email → get_webpage → get_icq → make_body[auto] → get_zhongzu →
get_gender → confirm_gift[auto] → enter_world) rather than guessing the shape from prompt text
— confirmed the `encoding()` prompt itself is actually SKIPPED (its whole function still
exists, but `logon()`'s `#ifdef GB_AND_BIG5` branch is false in this build since
`GB_AND_BIG5` is commented out in `mudlib.h`, so it calls `encoding("gb",ob)` directly instead
of ever prompting the player) — the first REAL prompt a connecting player sees is the
"进入(Enter)/离开(Exit)" youth-protection gate, not an encoding choice. Also discovered by
running the test that the gift/talent-allocation menu (`0-3` to re-roll a stat, `9` to accept)
requires an explicit `y` **confirmation** after `9` ("你确定接受当前的天赋设置吗？[y/n]") —
not documented anywhere in the prompt text itself, found only by watching an early attempt's
`look`/`quit` sends get silently swallowed as (invalid) answers to this confirmation.

**Final clean run** (after the §15w fix, fresh id `qfengliu` / real Chinese name `秦风六`,
one continuous connection):
```
1                    -> youth-gate "进入" (enter)
new                  -> trigger new-player registration
qfengliu             -> English id (accepted, unique, 3-8 lowercase letters)
秦风六                -> Chinese name (ACCEPTED — confirms the is_chinese/check_legal_name fixes)
admin12345           -> admin password
admin12345           -> confirm admin password
player12345          -> regular password
player12345          -> confirm regular password
test@test.com        -> email
(blank)              -> webpage (optional)
(blank)               -> ICQ (optional)
1                    -> race: 人类 (human)
m                    -> gender: 男性 (male)
9                    -> accept current gift/talent allocation
y                    -> confirm gift acceptance
look                 -> REAL room description of 南城客栈 (South-city Inn, the actual
                         configured START_ROOM), full exits list, board, 3 NPCs listed
score                -> REAL character sheet, correctly showing "秦风六(Qfengliu)",
                         correct age/gender/stats/etc.
quit                 -> clean quit message, connection closed normally
```
Zero `编译时段错误`/error/crash lines anywhere in this final transcript, and `debug.log` for
this session shows only the one pre-known `emoted.o` restore warning plus 334 ordinary
compile `warning:` lines (correctly suppressed from the player by the §15w fix, still logged
to file). Re-ran this exact sequence twice (ids `qfengs`/`秦风五` and `qfengliu`/`秦风六`) with
identical success both times, confirming this is reproducible and not a one-off.

## lpcc status

Full sweep skipped (mega-lib, see above). Individual `lpcc` runs against the bootstrap-critical
chain (`master`, `named`, `logind`, `securityd`, `chinese`, and the actual start room
`d/city/kezhan`) all passed clean (exit 0, no compile errors) before the first full driver
boot.

## Rebuilt-driver / formatter / WASM re-verification pass (2026-07-23)

1. **LPC formatter** applied across all 33,199 `.lpc` files in `work/`
   (~703MB): `{"total":33199,"written":32148,"wouldChange":0,
   "unchanged":625,"errors":426}` — took a few minutes given the file
   count, run in the background per this lib's own established
   mega-lib-scale conventions. Checked for the `::fn()`-after-`(`
   formatter bug found on `tianxia`/`shujian2008`/`sjtx2`/
   `syxjl` this same pass (see `tianxia/NOTES.md` for the full
   writeup) — **zero hits** of the `(: :` corruption signature anywhere
   in this lib's 33k+ reformatted files. Spot-verified the three
   critical fixes survived reformatting intact: `feature/command.lpc`'s
   `command_hook` still plain `nomask` (with the original commented-out
   `private` line preserved as a comment), `adm/obj/master.lpc`'s §15w
   `strsrch(message, "warning:") == -1` guard, and its §8d/§15o
   `get_include_path()` apply.
2. **Native re-test against the rebuilt `build-debug/src/driver`**:
   booted clean in a few seconds despite the 33k-file scale (zero fatal
   errors, only the one already-documented `emoted.o` restore warning
   plus ordinary compile warnings). Full registration verified
   end-to-end via `mudclient.py`, following the exact flow already
   documented above (youth-gate → `new` → id → Chinese name → admin
   password ×2 → regular password ×2 → email → optional
   webpage/ICQ → race → gender → gift accept/confirm → world): id
   `smfmtb`, real Chinese name **`秦风壬`**, reached 南城客栈 (the
   documented start room), `look` showed the correct room, `score`
   showed a correctly-populated character sheet, `quit` produced the
   game's own farewell text. `debug.log`: zero `error in error
   handler`/`denied`/`undefined function`/`bad argument` lines beyond
   the one pre-known `emoted.o` restore message. No new fixes needed —
   confirms the reformatted 33k-file tree is still fully sound against
   the rebuilt driver.
3. **WASM test**: per this pass's own scope note for mega-libs, expected
   this might be slow/memory-heavy enough to just document a
   timeout/hang rather than force it through — **it was not**: the
   whole `scripts/wasm_client.js` run (copying `work/`'s ~700MB into
   MEMFS, compiling the preload chain, and driving a full registration)
   completed in under a minute, peak host memory usage stayed modest
   (~4.2GB used, ~18GB available throughout, no swap pressure beyond the
   pre-existing baseline from other concurrent agents' sessions on this
   host). **Full registration completed successfully under wasm**, same
   flow as the native test above (id `smwasma`, real Chinese name
   `秦风癸`), reaching 南城客栈 with `look` producing the correct room
   and `quit` producing the correct farewell — a genuinely full,
   working wasm playthrough for a 33k-file mega-lib. Two caught,
   non-blocking runtime errors observed along the way, both logged but
   neither interrupting registration:
   - The already-documented `emoted.o` restore-format error (same as
     native, unrelated to wasm).
   - **A new, minor `query_ip_number()`-adjacent finding**:
     `adm/daemons/ipd.lpc`'s `seek_ip_address(ip)` does
     `user_ip = explode(ip, ".")` then unconditionally indexes
     `user_ip[1]` for some branches — since `query_ip_number()` doesn't
     return a real dotted-quad under wasm, `explode()` yields a
     single-element array and indexing `user_ip[1]` throws `Array index
     out of bounds`. Called from `logind.lpc`'s `confirm_gift()` →
     `enter_world()` path (an ISP-routing/regional lookup, not an actual
     login gate), so — unlike `shujian2008`/`tianxiawuxue`'s
     hard-rejecting `is_banned()`/`is_valid()` checks — this one is
     purely cosmetic/non-blocking here: the driver's own error handler
     catches it and registration proceeds straight through to the game
     world regardless. **Not patched** — same "known
     `query_ip_number()` wasm limitation, not a mudlib bug" reasoning,
     just a different, non-blocking manifestation of it than seen on
     other libs this pass. **Assessment: shenmo is fully playable under
     wasm**, the best possible outcome for a mega-lib, and the
     mega-lib-scale wasm risk flagged in this pass's own brief did not
     materialize.

## WASM-enablement pass (2026-07-24)

Standard four-change pass (AGENTS.md §1.3b/§1.3e/§1.5), applied with
targeted edits only (mega-lib — no sweeps):

1. **Loopback-allow** (empty/non-string/`127.*` IP treated as loopback):
   - `adm/daemons/logind.lpc` `logon()` (~line 179) — the
     `is_strict_banned()` gate, the `!ip_name` kick AND the per-character
     IP-format kick (`kicked out, Non_number` — this one
     destructed every WASM connection, since WASM's garbage IP contains
     non-digit chars) are all now skipped for loopback/malformed IPs.
   - `adm/daemons/logind.lpc` `enter_world()` (~line 1086) — the
     `create_char_banned()`/`is_banned()` move-to-guest-room gate
     skipped for loopback.
   - `adm/daemons/band.lpc` — `is_banned()`, `create_char_banned()`,
     `is_strict_banned()` all short-circuit to 0 for
     loopback/localhost/malformed sites.
   - `adm/daemons/ipd.lpc` `seek_ip_address()` — returns "本地" for
     loopback/malformed IPs instead of crashing on `user_ip[1]`
     (previously documented-only WASM finding, now fixed).
2. **Uptime gate**: none (uptime() in logind is only bookkeeping for the
   newid-temp cleanup). **Anti-flood**: no per-IP throttle; the
   `newid/<id>` temp guard is per-ID double-registration protection
   (cleared every 300s / on restart), left alone as game logic.
3. **Admin seeded**: `fluffos` / `Mud@2026` / 浮浮 → `(admin)` appended
   to `/adm/etc/wizlist` (3rd wizlist column = login-site restriction,
   left empty = unrestricted). Registration also required the lib's
   separate "管理密码" (recovery): `Admin@2026`. Save files:
   `work/data/login/f/fluffos.o`, `work/data/user/f/fluffos.o` (data/
   not gitignored). Verified: `update /cmds/usr/bjtime` → 重新编译
   成功.
4. Retest: fresh registration (smqfb/秦风, deleted after test) into
   南城客栈 with look/score/quit OK. debug.log: only the pre-existing
   `restore_object(): Illegal mapping format while restoring emote`
   (known emoted.o data quirk, documented in earlier passes). Removed
   one runtime-churn file the boot created (`u/snowtu/data/user/s/
   sajia.dzxy`). Registration flow gotcha (for future scripting): after
   email there are TWO skippable prompts (homepage AND ICQ/QQ) — a
   single empty send desyncs the race prompt.

### Retrofit: fail-closed loopback check (2026-07-24)

The loopback-allow gates above were originally written per the (now
superseded) defensive instruction to also treat an empty/non-string/
malformed `query_ip_number()` result as loopback, since older WASM
driver builds returned garbage. That driver bug is now fixed upstream
(`query_ip_number()`/`resolve()` return real values under WASM too), so
the "malformed IP = trust it" fallback was a fail-open bypass with no
remaining justification. Tightened every gate listed above to the
strict pattern: loopback is ONLY `ip == "127.0.0.1"`, `ip == "::1"`, or
a leading `"127."` prefix — a non-string/empty/malformed IP is now
treated as untrusted/remote and subject to the gate normally, not
silently allowed through. Retested: fluffos login (127.0.0.1, real
value under the current driver) still passes every gate; debug.log
stayed clean of `denied`/`undefined function`/`error in error handler`.

## 深度功能测试 / Deep functional test (2026-07-25, AGENTS.md §10.7)

One continuous native-driver session (plus deliberate reconnect/soak
sessions afterward), following §10.7's checklist. Read
`doc/help/newbie` first (「南城客栈」start room, food/water/气/内力/法力
basics, 拜师/学艺 flow, `wimpy` safety note, weak starter-NPC list, "if
you can't win, `quit`" advice — note the help text's own body text
repeatedly says "仙侣情缘" instead of "神魔传说", a leftover from
whichever earlier game this help file was copied from; cosmetic/content,
not touched).

### Test characters

- `shenmuce`/沈墨策 — first registration attempt, used to confirm the
  §7.34 fix (below) before any other testing.
- `qfshenmo`/秦风八, `qftestc`/秦风测测, `qftwaaa`/秦测五五,
  `qftwbbb`/秦测六六 — throwaway characters used while chasing the
  "dizzy" message (see Observations below).
- **`qfengda`/秦风大 — the main test character.** Registered → accepted
  gift → entered 南城客栈 → walked 南城客栈→朱雀大街→十字街头→青龙大街
  (×2)→将军府→练武场 (`west`,`north`,`east`,`east`,`south`,`south`) →
  `answer 拜师` past 秦安's gate guard → `apprentice qin` (joined
  将军府, 秦富 as master, unconditional recruit — no gating at all in
  `d/jjf/npc/qinfu.lpc`'s `attempt_apprentice`) → `learn force from qin`
  (succeeded, 潜能 99→98, "你的「内功心法」进步了") → `da sandbags`
  (correctly rejected: "你的道行不够高，不能从打沙袋中学到新知", since
  `combat_exp` was still 0) → `wimpy 50` → `kill xiao tong` (real combat
  against the newbie-doc-recommended weak NPC, `d/jjf/npc/xiaotong.lpc`,
  combat_exp 4000) → clean `quit`. Net-dead/reconnect and soak testing
  (below) also used this character.

### Safe-sparring mechanism (found, not live-reachable within budget)

`d/city/obj/muren.lpc` ("木人", a training dummy) has exactly the
documented shape (`accept_fight()` copies the attacker's own
skills/stats onto itself before the fight, so a spar against it can
never be a mismatch) — but grepping the whole live tree found **no
room's `"objects"` mapping references this specific file**; it is dead
content (see also `d/obj/misc/muren.lpc`, also unreferenced). Sibling
copies exist and ARE placed (`d/pingan/new/npc/muren.lpc`,
`d/shaolin/muren-xiang.lpc`, `d/mingjiao`, `d/shushan`, `d/laoshaolin`),
but all are multiple zones away from the start area and out of this
pass's time budget to path to and verify live. Used 将军府's own
in-game-documented alternative instead: `练武场`'s `sandbags` object
(`d/jjf/front_yard.lpc`'s `do_da()`) is a genuinely safe (no death risk,
only `kee` cost) skill-training mechanic gated on sect membership and a
`combat_exp` threshold — exercised live above, correctly rejected for a
too-fresh character. **Not claiming the muren mechanism itself was
verified live** — flagging this honestly per §10.7 item 6 rather than
presenting it as tested.

### Bugs found and fixed

**1. §7.34 (leftover developer debug output) — `adm/daemons/logind.lpc`
`get_name()`.** Live-reproduced on the very first registration attempt:
between the Chinese-name prompt and the admin-password prompt, the raw
transcript showed `您的中文名字：/obj/login#150` — the login object's
driver-assigned path printed instead of moving straight to the next
prompt, byte-identical in shape to the `xianlvqiyuan`/`esI` instances
already cataloged in §7.34. Root cause: a bare `printf("%O\n", ob);` at
line 775, right before `ob->set("name", arg);`, with no explanatory
comment — a debug checkpoint the original author never removed.
**Fix**: deleted the line. Re-verified: re-ran the exact same
registration flow (id `qfshenmo` and others below) — the raw byte
sequence now goes straight from the Chinese-name prompt to the
admin-password block with nothing in between.

**2. NEW class — `file_owner()`'s fixed-depth `sscanf` misattributes
any `/u/<wizard>/<subdir>/...` file, crashing `log_error()`'s log write
on any compile warning under a nested wizard directory (matches
AGENTS.md §7.26 exactly, independently found here).**
`adm/simul_efun/object.lpc`'s `file_owner()` did
`sscanf(file, "/u/%s/%s/%s", dir, name, rest) == 3; return name;` —
returning the SECOND segment (a subdirectory name) instead of the
wizard's own uid for any file nested more than one level under `/u/`.
Live-reproduced: walking a fresh character `north` from 朱雀大街 into
`十字街头` (`/d/city/center.lpc`) for the first time this boot lazily
compiled `/u/xdao/ljs/npc/ljstudi.lpc` (the 两界山土地 NPC placed
there), which has an ordinary "Unused local variable" warning;
`log_error()` then tried `file_owner()` → got back `"ljs"` (the
subdirectory, not `xdao`) → `user_path("ljs")` → a directory that
doesn't exist → `[执行时段错误]: *Wrong permissions for opening file
/u/ljs/log for append. "No such file or directory"`, caught by the
driver but landing squarely inside `center.lpc`'s own
`create()`→`setup()`→`reset()`→`make_inventory()` chain (the same
first-visit-only shape as §7.17/§7.25). Confirmed a SECOND, byte-
identical, dead (unreferenced-by-`adm/obj/simul_efun.lpc`) copy exists
at `adm/simul_efun/oo.lpc` — left untouched per the project's
leave-dead-code-alone convention, since it is not part of the compiled
simul_efun and fixing it would be pure churn.
**Fix**: capture only the first segment after `/u/`
(`sscanf(file, "/u/%s/%s", name, rest) == 2`), matching `domain_file()`'s
own first-segment-only discipline immediately below it in the same file.
**Re-verified live**: restarted the driver, walked the same
`west`,`north` route into `center.lpc` on a fresh boot (forcing the same
first-ever lazy compile of `ljstudi.lpc`) — zero `Wrong permissions`/
`执行时段错误` lines in `debug.log` this time, room populated normally.

**3. §7.12 (2-arg `tell_room()` wrapper bug), severity-escalation shape
— confirmed live, including the follow-on driver segfault.**
`adm/simul_efun/message.lpc`'s `tell_room(mixed ob, string str, object
*exclude)` called `message("tell_room", str, ob, exclude)` — with
`exclude` an unset (`int 0`) local for any of this lib's 2000+ 2-arg
call sites. **Contrary to this same lib's own earlier NOTES entry
("§15s"), which checked ONLY the C++ `f_message()` *body*'s `switch` on
the 4th argument (whose `default:` branch does silently tolerate a bare
`0` with no `bad_argument()` call) — the ACTUAL live crash comes from a
layer that check missed entirely: this driver's efun **prototype**
(`src/packages/core/core.spec`: `void message(mixed, mixed, string |
string* | object | object*, void | object | object*);`) declares the
4th parameter as `void | object | object*` — NOT `int`/`mixed` — and the
driver's own prototype-based argument type-checker rejects a literal
`int 0` at the call boundary, before the C++ body's tolerant `switch` is
ever reached.** (Correcting that earlier conclusion here rather than
silently overwriting it, since it's a genuinely instructive miss — the
efun's declared *prototype* and its C++ *implementation* can disagree,
and checking only the implementation body isn't sufficient.)

Live-reproduced via `obj/user.lpc`'s `user_dump()` — the
`NET_DEAD_TIMEOUT`-driven (600s / 10 real minutes) force-quit handler,
same function class as `dtsl`'s original find:
1. Deliberately net-deaded `qfengda` (disconnected without `quit`), then
   did ONE blocking `sleep 660` (past the 600s timeout) before
   reconnecting.
2. `debug.log` showed exactly the predicted crash:
   `[执行时段错误]: *Bad argument 4 to EFUN message() Expected: object,
   array,  Got: int(0).` with a backtrace rooted at
   `user_dump() /obj/user.lpc 181行` → `tell_room()` — i.e. the very
   `tell_room(environment(), name + "断线超过...分钟，自动退出这个世界。\n")`
   call in `user_dump()`'s `DUMP_NET_DEAD` case. Per §7.12's own
   documented mechanism, this uncaught crash (no enclosing `catch()`,
   fired from a bare `call_out`) aborted the REST of that `switch` case
   — the very next line, `QUIT_CMD->main(this_object(), "", 1);`, never
   ran, so the net-dead force-quit safety net was silently disabled,
   exactly as on `dtsl`.
3. **The follow-on driver crash also reproduced**: the very next
   reconnect attempt against that half-handled net-dead object hit
   `CONNECT_FAILED: [Errno 111] Connection refused` — the driver process
   itself had died. Captured stdout showed a genuine C-level
   `Segmentation fault (Address not mapped to object [0x65])` inside
   `apply_low()`, dereferencing a corrupted `ob->shadowed` pointer, with
   `command_hook()`→`f__call_other()` on the stack — the exact
   double-free/dangling-object shape §7.12's `dtsl` writeup and §10.8's
   catalog already describe.

**Fix**: `exclude || ({})` at the `message()` call site inside the
`tell_room()` wrapper — the same one-line, project-standard fix used on
every other lib carrying this bug class. **Re-verified live end-to-end,
twice**:
- A normal register→move→`quit` session afterward showed zero `Bad
  argument`/`执行时段错误` lines.
- **Repeated the exact net-dead + 660s-wait scenario against the fixed
  driver.** This time `debug.log` stayed completely clean through the
  whole wait (no `Bad argument 4` line at all — confirms the LPC-level
  crash is genuinely fixed) and the driver process was still alive and
  listening immediately after the timeout fired. **However, roughly 20–
  30 real seconds later — with no player command in flight, no
  reconnect attempted yet — the driver process died again**, this time
  from a *different* segfault: captured stdout shows the crash
  originating from a bare `call_out` firing (not a player command),
  descending through TWO nested `f__call_other()` frames before the same
  `apply_low()` → `ob->shadowed` dereference. This is the AGENTS.md
  §10.8 driver-level memory-corruption class (five prior independent
  occurrences already cataloged there, across five unrelated libs/
  lineages) — **not mudlib-fixable**, and explicitly out of scope for an
  LPC-level fix per that section's own conclusion. Recorded here as a
  **sixth independent occurrence**, and the first one observed
  triggering from the *successful* (post-fix) net-dead force-quit path
  itself rather than from an aborted/crashing one — i.e. fixing the
  LPC-level §7.12 bug above removed one trigger for the segfault class
  but did not eliminate the class itself. Flagging per §10.8's own
  standing recommendation: this warrants a dedicated driver-level
  investigation (ASan/valgrind against a long net-dead soak) in the
  `~/src/fluffos` checkout itself, not further per-lib mudlib changes.

### Net-dead / reconnect / soak testing (§10.7 items 8–9)

- **Prompt reconnect** (net-dead without `quit`, reconnect ~35s later,
  well inside the 600s window): worked correctly — `qfengda` was
  restored in the exact room it had been in (朱雀大街), full `score`
  state intact, no `reconnect()`-vs-`net_dead()`-mismatch shape from
  §7.20 observed (this lib's `obj/user.lpc reconnect()` directly clears
  the net-dead call_outs and re-links in place — it never parks the
  player in a separate void room to begin with, so the §7.20 failure
  mode doesn't apply to this lib's architecture).
- **Long-wait unclean-disconnect reconnect** (past the full 600s
  `NET_DEAD_TIMEOUT`): see bug #3 above — this path is exactly what
  surfaced both the §7.12 crash and its §10.8 driver-segfault follow-on.
  After the fix, the force-quit itself completes correctly (confirmed:
  the character's `startroom`/location was NOT corrupted to a void or
  otherwise stale — a fresh login afterward landed back in 南城客栈,
  the correctly-saved last position).
- **Clean quit, real wait (~90s), reconnect**: worked correctly — state
  (南城客栈, full `score` sheet) restored exactly as left.

### Shop purchase / combat (§10.7 item 6/10)

- `buy jiudai from xiao er` at 南城客栈 (per `doc/help/newbie`'s own
  example) correctly rejected with "你的钱不够" — new characters start
  with zero money, matching the newbie doc's own "没有钱怎么办？...向
  老玩家讨" advice. The rejection path itself works correctly; a real
  purchase was not reachable within this pass's time budget (would
  require earning money first) — stated explicitly, not silently
  presented as tested.
- `kill xiao tong` (real, un-mirrored combat against the newbie-doc-
  recommended weak NPC) initiated correctly (aggro messages, opponent
  engaged) with `wimpy 50` set beforehand as the newbie doc recommends.
  Did not observe the fight through to a kill/death, since the
  connection ended (deliberately, to set up the net-dead test) while
  the fight was still in its opening exchanges — **death/respawn was
  NOT reached or verified this pass**, stated explicitly per §10.7 item 6.

### Observations (documented, not fixed — genuinely unresolved)

- **An unexplained, low-frequency "dizzy" flavor message** —
  `你一陣頭昏，似乎發生了什麼事，但是又無跡可循...` (note: this exact
  string is in TRADITIONAL characters, inconsistent with the rest of
  this Simplified-Chinese lib) — appeared a handful of times across this
  pass's sessions, always immediately after a directional movement
  command (`west` twice, `north` once). Investigated extensively:
  the literal string does not exist anywhere in `work/` (checked every
  extension, including the dead `sjsh/` tree, via both direct grep and a
  byte-level Python scan of the raw transcript to rule out an ANSI/
  decoding artifact — the bytes are genuine, well-formed UTF-8). It does
  NOT reliably block movement: one occurrence (kezhan→center) was
  immediately followed by successful arrival in the new room; two other
  occurrences (both attempts to leave 南城客栈 via `west`) were followed
  by the character remaining in the original room. Re-ran the exact same
  registration + `west` sequence on 5 additional fresh characters
  (`qftestc`, `qftwaaa`, `qftwbbb`, and two more) with generous
  `--idle`; it did not reproduce on any of them — movement was clean
  every time. No corresponding line appears in `debug.log` for any
  occurrence. Checked and ruled out: `valid_move()`'s own busy/
  encumbrance/`no_move` gates (none of their fixed message text matches
  and `busy` is `nosave`, so it can't survive a driver restart the way
  one occurrence did); `EMOTE_D->do_emote()` and `CHANNEL_D->do_channel()`
  (both return 0 for an unrecognized verb, no such fallback text in
  either file); `adm/daemons/natured.lpc`'s weather/day-phase broadcast
  (broadcasts the actual phase text to every user, not this message).
  Per AGENTS.md's own scope note ("when genuinely unsure... document
  honestly... leave the code untouched — don't guess"), this is recorded
  as unresolved rather than guessed at. If it recurs on a future pass,
  worth grepping specifically for dynamically-CONCATENATED string pieces
  (not a single literal), since an exhaustive literal-text search across
  the whole tree came up empty.
- `doc/help/newbie` repeatedly refers to the game as "仙侣情缘" instead
  of its actual name ("西游记-神魔传说") — cosmetic help-text content
  left over from wherever this file was originally copied from; not
  touched (content, not a programming bug).
- Pre-existing, unrelated to this pass: `d/obj/books-nonskill/
  book-qujing.lpc` fails to compile (`Cannot #include
  /d/qujing/obstacle.h`, `Undefined variable 'obstacles'`) every time
  it's lazily reached — a genuine missing-header archive gap (the header
  file simply isn't present anywhere in the archive), not a conversion
  or driver-compat bug. Left alone per the mega-lib partial-sweep policy
  already documented earlier in this file.

### Files modified this pass

- `work/adm/daemons/logind.lpc` — deleted the stray `printf("%O\n",
  ob)` debug leftover in `get_name()` (§7.34).
- `work/adm/simul_efun/object.lpc` — fixed `file_owner()`'s fixed-depth
  `sscanf` to capture only the first `/u/` segment (matches §7.26).
- `work/adm/simul_efun/message.lpc` — `tell_room()`'s `message()` call
  now passes `exclude || ({})` instead of a bare possibly-`0` value
  (matches §7.12).

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BBS_BOARD`、`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 181 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。
