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

## 深度功能测试第二轮 / Deep functional test round two (2026-08-15, post driver-upgrade re-test)

驱动于 2026-08-12 升级后的重测。标准检查清单发现并修复两处问题：

1. **`adm/simul_efun/file.lpc`**：`log_file()` 没有 `assure_file()`
   目录预建保护；补上调用及前向声明。`cat()` 补上 `read_file() || ""`
   空值防护。（`simul_efun1/`、`simul_efun2/` 下的重复副本未被
   `adm/obj/simul_efun.lpc` `#include`，确认是死代码，未处理。）
2. **`adm/daemons/closed.lpc`（AGENTS.md §7.107，本轮在 `nt1` 发现的
   同一类 bug——独立确认的第二条血统）**：`load_all_users()` 的两处
   `restore()` 调用同样没有 `catch()` 保护，结构与 `nt1` 那份逐字节
   一致。本档案的 `data/closed.o` 目前 `closed_users` 记录很少（几乎
   为空），所以严重程度远不如 `nt1`（后者约 150 个账号），但同一漏
   洞成立——按 §7.107 记录的写法预防性修复（`catch(ok = X->restore())`
   + `err || !ok` 判定），未等真的出现损坏账号触发才修。

`cmds/wiz/update.lpc`（§7.106）与 `master.lpc::log_error()`（§7.10 的
`"arning:"` 大小写无关写法）均已是正确写法，无需改动。

`config.fluffos` 的 `maximum evaluation cost` 已经是 `2000000000`，远
超本项目安全值，无需调整。

### 现场验证

驱动干净启动，以管理员账号 `fluffos`/`Mud@2026` 登录，确认
`您的系统权限目前是：(admin)`，落地"南城客栈"（既有存档正确持久
化）。`update /adm/daemons/logind` 成功（"重新编译
/adm/daemons/logind.lpc ...成功！"），确认两处修复编译干净。两次快
速重连均正确显示 `(admin)` 权限、连线次数正确递增（第八次、第九
次），`quit` 均干净。`debug.log` 全程检查（1175 行）：无真实错误，
仅无害的宏定义匹配。

（登录流程记录一处方法论细节，非 bug：本档案开场"① 进入(Enter)
② 离开(Exit)"菜单的 `if_young()` 处理函式实际检查 `arg[0..0] ==
"1"`，纯空字串确认不会推进——尽管提示文字写着"(Enter)"，脚本化测试
时需要真的送出字元 `"1"`，而不是空白 Enter，才能进入下一步。）

### 本轮修改的文件

- `work/adm/simul_efun/file.lpc`
- `work/adm/daemons/closed.lpc`

## §7.100 sweep (2026-08-19): redundant `replace_program(ROOM);` landmine

Same corpus-wide bug as `jhfy3`'s §7.100 finding (AGENTS.md): every room
inheriting `ROOM` (`/std/room`) followed its `inherit ROOM;` with a
redundant, harmful `replace_program(ROOM);` call in `create()`, setting a
permanent "pending replace" flag that crashes the object the first time
anything later binds a closure to it. This lib had **1,957 live
occurrences** (survey-ranked #81 of 166 candidates >=100). Fixed with the
sweep's binary-mode script (`fix_710_room.py`) plus 8 hand-fixed
room-building-tool copies sharing the same bug baked into their own
code-generation templates (`obj/roommaker.lpc`, `sjsh/obj/roommaker.lpc`,
`sjsh/u/calvin/obj/roommaker.lpc`, `u/calvin/obj/roommaker.lpc`,
`u/mery/obj/roommaker.lpc` — simple `str += "...replace_program(ROOM);..."`
variant; `sjsh/u/koker/obj/teshu/roommaker.lpc`, `sjsh/u/qkl/roommaker.lpc`,
`u/koker/obj/teshu/roommaker.lpc`, `u/qkl/roommaker.lpc` — `room_code`-
prefixed 3-occurrence variant). Note: `u/calvin/obj/roommaker.lpc` and
`sjsh/u/calvin/obj/roommaker.lpc` are two SEPARATE, non-symlinked files
(the lib's `sjsh/` orphaned duplicate snapshot noted above) — both needed
the fix independently, easy to miss one if only grepping the `sjsh/`
prefix. `git diff --numstat` totals (17 insertions, 1957 deletions) match
the survey's live-occurrence count exactly. Verified via a clean
`build-debug` boot (zero "cannot replace"/"cannot bind" `debug.log` lines,
port 40067 listening) plus a live admin login (`fluffos`/`Mud@2026`) —
`look` at 南城客栈 and `quit` both worked normally. No `work/data/`
false-negative room source found for this lib (only save `.o` files and
unrelated content under `data/`). Incidental `fluffos.o` save-timestamp
drift from the spot-check reverted before committing.

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

## AGENTS.md §7.19 sweep (2026-09-01): `enable_player()` reentrancy from `init()`

Same corpus-wide bug class as `mhxy`/`wuhanzhan` (AGENTS.md §7.19): this
lib's `feature/command.lpc` `enable_player()` wrapper (around the raw
`enable_commands()` efun) is reachable from an NPC's `init()` via a
redundant `create()`-then-`init()`-calls-`setup()` (or `reset_me()`
calling `setup()`) chain -- confirmed live via a static scan of every
`init()` body in this lib: 41 NPC/item files call `setup()` directly
or via `reset_me()` from `init()`, after `create()` already called
`setup()` once (which already made the object `living()`). Calling
`enable_commands()` a second time on an already-`living()` object makes
the driver re-invoke that object's own `init()` as a side effect, which
re-enters this same chain while the original call is still on the
stack -- genuine reentrancy, crashing with "Too deep recursion" (most
likely to surface on an NPC's first-ever preload/compile).

`feature/damage.lpc`'s `revive()` and `cmds/std/sleep.lpc`'s `wakeup1()`/`wakeup2()` all call `me->enable_player()` again while the object is still `living()` (kept alive across the disabled interval by `disable_player()`'s own internal re-`enable_commands()`). This confirms a bare `if (living(this_object())) return;`
guard would be the WRONG fix (it would silently break that legitimate
re-enable) -- used the same true reentrancy-flag fix as `mhxy` instead:
a `nosave private int in_enable_player_now;` set for the duration of the
wrapper's body, guarding only genuine same-call-stack reentrancy while
leaving every legitimate re-enable (revive/wakeup/disguise) unaffected.
`feature/command.lpc`'s `enable_player()` had a single fall-through exit
(no early `return`s), so one guard-at-top + one clear-at-bottom pair was
sufficient. Verified via a single-file `lpcc --batch` compile check
(PASS) -- not individually live-boot-tested.

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.


## 深度功能测试（§10.7，2026-10-04）— undefined macro and simul_efun gaps

- `message_combatd(msg, me, you)` is called by 1017 file(s) (the perform files) and defined nowhere in this archive (a simul_efun of the original server): 1017 of them did not compile (`Undefined function message_combatd`). `adm/simul_efun/message.lpc` now has `varargs void message_combatd(string msg, object me, object you, mixed extra)` calling `message_vision()`, placed after `message_vision`'s definition (KB 04 §6.2). Callers that still do not compile: 832 (other errors, see below).
- 1965 file(s) `inherit F_SSERVER;` and no header defines it (1961 did not compile: `syntax error, unexpected L_IDENTIFIER, expecting L_STRING or '('`). `#define F_SSERVER SSERVER` in `include/globals.h` (KB 04 §6.2, `scripts/lpc_alias_macro.py`). 29 still fail. 936 files under `daemon/skill/` and 968 under `kungfu/skill/` inherit `F_SSERVER`; `SKILL_D()` is `/daemon/skill/`, so every `perform`/`exert` of those skills died at compile time. The 29 files that still fail want other things the archive lacks (`F_KUNGFU`, `NewRandom`, a `{` after `lingwu()`).

## 深度功能测试（§10.7，2026-10-05）— here-document terminators

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 6 here-document block(s) repaired (2 with the terminator glued to the last text line, 4 with it indented), so `End of file in text block` no longer hides the room or object behind them: `d/sh-jing/lishui.lpc`, `d/sh-jing/zhaoyao1.lpc`, `u/shulele/bangpai/zongtan.lpc`, `u/tom/wuxiaroom.lpc`, `u/weilai/bangpai/zongtan.lpc`, `u/fly/spyjob/corpseroom.lpc`. The terminator must start its line (the lexer's own test, KB 04 §6.10); a glued one lost its newline in the GBK -> UTF-8 conversion together with a half character, which stays out.

## 深度功能测试（§10.7，2026-10-05）— tail() simul_efun

`scripts/lpc_add_tail.py --apply`: `cmds/wiz/tail.lpc` calls `tail(file)`, an efun of the MudOS this archive ran on that FluffOS does not have (`Undefined function tail`: the command did not compile). `adm/simul_efun/file.lpc` now defines `void tail(string file)`: the last 10 lines of the file, written to the player. Load check (HEAD against the working tree): 1 of the 1 tail command file(s) failed to load at HEAD, all load now, and the simul_efun file loads. KB 04 §6.2.

## 深度功能测试（§10.7，2026-10-05）— 任务表里的 `.c` 路径与任务守护进程的防护

`scripts/lpc_dynamic_rows.py`：`quest/dynamic_location` 里 1735 行写的是原档案的 `.c` 路径。转档时文件已改名 `.lpc`，而显式后缀按原样解析，`load_object("/d/x.c")`、`new("/d/obj/quest/x.c")` 返回 0 且不报错（KB 03 §4.2，KB 06 §7.220），所以 `adm/daemons/questd.lpc` 读到的每一行都加载不出来：随机任务和任务物品从未生成，在 `create()` 里直接对结果调用 `tar->set()` 的版本还会崩溃，连带加载它的 cron 守护进程和 `give` 的任务钩子。这些行已改为 `.lpc`；另有 80 行指向的文件两种后缀都不存在（档案缺内容），保持原样。
`scripts/lpc_dynamic_quest_guard.py`：3 处 `spread_quest()` 调用（`init_dynamic_quest()` 的循环里）包进 `catch()`，缺失的任务物品或编译不过的房间只跳过那一个任务，守护进程照常加载、其余任务照常生成。
验证：`adm/daemons/questd.lpc`和 cron 守护进程在新进程里加载（HEAD 一次，工作树三次，选房是随机的）：HEAD 通过 2 个，工作树三次分别通过 2、2、2 个（共 2 个），无回退。

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `std/room.lpc`：`make_inventory()` 用 `catch()` 包住 `new(file)`，做不出来就返回 0；`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-06）— 编译警告整理

`scripts/lpc_warnings.py shenmo --fix`（第一轮；本库 33000 多个 `.lpc`，扫描很慢，只提交第一轮）：无用局部变量、`nosave` 函数、`varargs`、转义等，共改动 5287 个 `.lpc`。HEAD 与工作树分别加载（新进程）：4760 -> 4762 通过，无回退；`scripts/lpc_audit_removed_locals.py HEAD` 的 61 条候选都是声明被重建（有 `#if` 的只有 `d/city/piggy*.lpc`，与被删的名字无关）。启动时警告 214 -> 0。

## 深度功能测试（§10.7，2026-10-06）— 与 zhonghua2 同源的三处编译警告

- `clone/drug/fengdong.lpc`：`if (... < 10000) max1 / 2;` 是空语句，改成 `max1 /= 2;`（经验不足一万的对手，分身技能减半）。

验证：改动的文件和包含 `npc/indian` 的守护进程在 HEAD 与工作树分别加载（`scripts/lpc_listcheck.sh`，新进程），无回退。

## 深度功能测试（§10.7，2026-10-08）— `.lpc` 后缀的定宽切片

`.c` 改名 `.lpc` 时只改了字符串没改切片宽度：`f[<2..] == ".lpc"` 拿两个字符比四个字符，永远不成立（`!=` 永远成立），按后缀筛文件、去后缀的代码因此从不运行或截成 `x.l`（KB 06 §7.238）。`scripts/lpc_lpc_suffix_slice.py --apply` 改了 1 处比较、1 处去后缀（如 `cmds/eld/mem.lpc`）；改动的文件 HEAD 与工作树分别加载（新进程），无回退。

- 2026-10-10：7 个 NPC 同时继承 `NPC` 和 `F_UNIQUE`、自己没有 `init()`，驱动只取其中一份（`init() inherited from both /feature/unique.lpc and /feature/attack.lpc`）：要么 `attack.lpc` 的主动攻击/仇杀检查从不执行，要么 `F_UNIQUE` 的持有者检查从不执行。每个补一个两份都调的 `init()`（`scripts/lpc_fix_unique_init.py`）；HEAD 与工作树载入结果相同，这条警告清零。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查（批 3）

- `daemon/skill/*-archery.lpc` `practice_skill()`：`(: throw_weapon :);` 只造函数指针不调用（练习本就不该射箭），删去。
- 改动的对象 HEAD 与工作区都能载入，无回退。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查（批 5）

- `daemon/skill_wiz/archery/xuanyuan-archery.lpc` `practice_skill()`：`(: throw_weapon :);` 只造函数指针不调用，删去。
- 改动的对象 HEAD 与工作区都能载入，无回退。

## 深度功能测试（§10.7，2026-10-11）：dns_master 空 if

- `adm/daemons/network/dns_master.lpc` `query_services()`：`if (! (mud_svc[mud]["tell"/"finger"] & SVC_KNOWN)) {` 里只有 `#if PREF_X & SVC_TCP … #endif`，选项关闭时 if 体为空（“无副作用”警告）；把 `#if`/`#endif` 挪到 if 外面（KB 04 §6.10，2026-10-07 那次扫描漏掉了 `! (` 带空格、大括号另起一行的写法）。载入无回退。

## 深度功能测试（§10.7，2026-10-11）：dns_master 空 if

- `adm/daemons/network/dns_master.lpc` `query_services()`：`if (! (mud_svc[mud]["finger"/"tell"] & SVC_KNOWN))` 块里只有 `#if PREF_X & SVC_TCP … #endif`，选项关闭时 if 为空（“无副作用”警告报在下一句）；把 `#if`/`#endif` 挪到 if 外面（KB 04，2026-10-07 那次扫描漏了 `! (` 加括号换行这种写法）。载入无回退。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查

- `d/shenjian/npc/obj/jewelsword.lpc` `hit_ob()`：命中描述少了 `return`，明珠剑的特效文字从不出现；补 `return`。
- `d/game/biao/fan.lpc`：`else "恩，你已顺利完成任务。";` 少了 `return`，完成镖局任务后回话为空；补上。
- `d/skyjob/npc/yaomo.lpc`、`tower_door.lpc`、`u/xdao/yaoguai.lpc`：`for (i == 0; …)` 改为 `i = 0`（局部变量本为 0，行为不变）。
- `d/xkx/wudu/shanlu1.lpc`、`xiao3.lpc` 描述后孤立的 `"\n";`，`wudoumi-shengong/perform/gui.lpc` 两份多余的 `NOR;`，删去；`u/stey/cron.lpc` 只剩注释的 `if (tang) { }` 挪进注释。
- `u/angell/npc/shen.lpc`（含 `sjsh/` 副本）：三行 `(: call_other, __FILE__, "…_name_skill", who :);` 只造函数指针不调用，而被指向的是 `input_to` 式回调（参数是 string），无法确定作者原意，改成注释，行为不变。
- 13 个对象载入无回退。

## 深度功能测试（§10.7，2026-10-11）：全库严格 UTF-8 检查

- `u/shulele/yangxu-yan.lpc` 原档在一句字符串中间截断（GBK，未转码），无法恢复，保留原样。

## 深度功能测试（§10.7，2026-10-12）：编译警告收尾（补）

- `d/quest/dajiu/`、`d/xingji/dajiu/` 的 `baohunpc*.lpc`（8 个）：原型 `voidset_skills(...)`、`voidset_hp_status(...)` 少了空格，被当成返回类型缺省、名为 `voidset_skills` 的另一个函数；改为 `void set_skills(...)`。批量载入时 `create()` 读 `this_player()` 为 0 而失败（任务中由玩家触发生成，不是代码问题）。

## 编译警告收尾（2026-10-12，第一轮）

`scripts/toolkit_fix.sh` 一轮：钩子函数（`reset`/`init`/`heart_beat`/`create` 等）在 `void` 基类上写成 `int` 的 271 个改为 `void`（`return 1;` 改 `return;`），覆盖函数 6 个，冗余继承 13 处，未用局部变量等机械类。改动的 305 个对象 HEAD 与工作树各载入一次：HEAD PASS 291，tree PASS 296，regress 0，新载入 5：`u/koker/obj/axe`、`blade` 与 `sjsh/u/koker/obj/` 两份拷贝、`u/snowtu/give`——它们在基类之外又直接继承一遍带 `nomask` 的 dbase，驱动报 `Illegal to redefine 'nomask' function '_query'`，从前载不进来。

- `d/snowtu/obj/birthday.lpc` 生日蛋糕的字符画：旧版转义修复器把 `\\` 的后一半当成未知转义 `\/` 删，每轮删一个、连删 8 轮把这一行删坏；按原文把每个反斜杠写成 `\\`，照原样显示。修复器已改（只认前面有偶数个反斜杠的转义，`\/`、`\_` 加倍而不删；KB 04 转义一行）。
- 剩下的（约 300 个非钩子函数的返回类型、46 条重复声明、30 个宏重定义等）留待第二轮。

## 编译警告收尾（第二轮，2026-10-12）

按 2026-10-12 扫描结果（可编译文件中 174 条警告）逐条在源头修，不加 pragma。改动 115 个文件；改动的文件、引用改动头文件的文件及受影响子类共 198 个对象，HEAD 与工作树各载入一次：HEAD PASS 191，tree PASS 191，regress 0；这些对象在 HEAD 共 197 条警告，工作树 0 条。7 个 FAIL 两边相同，都是 `create()` 运行期错误（`d/wizz/stey/*guai.lpc` 的 `setname()` 对 0 调用、`u/weilai/tianjie/biyao/zhang.lpc` 用了不存在的技能 `qysword`、`repoo/npc/npc.lpc` 的名字守护进程不存在、`d/kaifeng/npc/quest.lpc` 本是 include 片段），不在这一轮范围内。

**发现的真 bug：**
- `u/snowtu/bing.lpc` 巡逻官兵的 `kill_ob()` 结尾 `return kill_ob(me);` 调用自身，没有出口：每层还随机放招（克隆 luocheng 打人），直到递归过深报错。改为放招后调一次 `::kill_ob(me)`，返回 `void`。
- `u/weilai/xyb.lpc` 幸运包状态：`sprintf("…%d…%d…", …)` 的两个 `%d` 分别收到字符串（`"读书"` 等）和 `?:` 里的 `"无限"`，运行时 sprintf 报错；改成 `%s`，剩余分钟用 `sprintf("%d", …)`。
- `d/obj/cloth/jiasha.lpc` 锦镧袈裟同时继承 `CLOTH` 与 `F_UNIQUE`，两边都有 `init()`，驱动只用 unique 的那份，袈裟不能 `tear`；补一个两份都调的 `init()`（与第一轮 7 个 NPC 同法）。
- `u/stey/newjob/teamjob.lpc`（含 `sjsh/` 副本）`names[0][random(40)]` 而表只有 12 项，大半时候数组越界；改为 `random(sizeof(...))`。同时把这张表改名 `team_names`（与 `zzzjob.lpc` 的 `names` 同在 `guo.lpc` 里 include，重复声明；数据相同，xkx 家族同名修法）。

**重复声明（46 条）：**
- `d/kaifeng/ground.h` 的三张表被 `ground0.lpc` 与继承它的 `ground1/2/3.lpc`、`ground.lpc` 各 include 一遍：沿用 xiyouji 的 `GROUND_TABLES_INHERITED` 做法。`d/kaifeng/npc/colors.h` 经 `quest.lpc` 被 `quest_fd`/`quest_gv` 等各带进一次：加 include 保护。
- `feature/alias.lpc` 统计命令频率的 `nosave int last_time` 与 `d/city/npc/sanhua-counter.lpc`（存档 NPC，`last_time` 要存盘）、`d/pingan/**/shenyi.lpc` 自己的 `last_time` 同名：改基类这份为 `last_cmd_time`，叶子与存档键不变。
- 叶子与基类各有一份、各读各的：`cmds/std/go*.lpc`、`u/djx/cmds/go.lpc`（两份）的方向表 `default_dirs`（`DIR_D` 里那份没有函数读）改名 `go_dirs`；`d/wizz/fangz/wizman*.lpc`、`u/shulele/npc/wizman2.lpc`、`zqd2.lpc` 的技能名单 `skills`（盖住 F_SKILL 的 `mapping skills`）改名 `skill_list`；`u/xdao/yaoguai.lpc` 自己的放招计数 `tick`（与 `std/char.lpc` 的心跳计数分开）改名 `perform_tick`。
- 叶子重复了基类变量却从不读：`d/city/npc/yg/yaoguai.lpc` 的 `yaoguai_type`、`d/snowtu/team/npc/evl2.lpc` 的 `atk`，删去叶子那份。
- 同一文件声明两次：`roommaker.lpc`（4 份）保留后一份（`do_saveroom` 用的就是它），`u/weilai/liwu/jrsj.lpc` 两张节日表（后一份覆盖前一份）合成一张按年份的表。

**其余：**
- 返回类型：`heart_beat` 20、`die` 5、`unconcious` 2、`fight_ob` 4、`kill_ob` 10（`return ::kill_ob()`、`return 5` 改为无返回值；调用处都不读返回值）用 `scripts/lpc_fix_return_types.py --also …` 改 `void`；`reset` 原型 3 个改 `void`，`d/sds4/npc/hufa.lpc` 多余的 `int kill_ob(object);` 原型删去。`reward_ob`：`d/emei/huanbochi/r.lpc` 读它的返回值（非零 = NPC 战败后不退走），所以基类 `npc.lpc` 改为 `int reward_ob() { return 0; }`，`moshi.lpc` 跟着改 `int`、返回 0，15 个叶子不动。
- `long()`：5 个神龙/狗 NPC 留着没有函数体的 `int long();` 原型，删去，用继承的 `string long()`。`u/shulele/npc/sz.lpc` 原型 `string ask_wuxue()` 改为与定义一致的 `int`。
- 宏重定义 30：`toptend.lpc`（两份）、`u/pkl/quest/*`、`repoo/npc/npc.lpc` 有意覆盖 `globals.h` 的宏，在各自 `#define` 前加 `#undef`。
- 顶层多余的 `;` 21（`inherit ROOM; ;`、函数后 `};`），`clone/box/gbox*.lpc` 注释里嵌套的 `/*`，`d/kaifeng/npc/reporting.lpc` 未用的 `str`（输出语句早已注释掉，声明一并移进注释），`vikee/network/dns_master.lpc`（两份）`#if` 关掉后剩下的空 `if {}`（照 `adm/daemons/network/dns_master.lpc` 把 `#if` 挪到 `if` 外）。
- 两条路径带进同一个 `/feature/clean_up.lpc` 的 `clean_up()`：三个 `tang.lpc` 根本没用 `SSERVER` 的函数，去掉这个继承；`daemon/skill/hubo.lpc`、`test-whip.lpc` 用 `lpc_name_winner.py` 写出驱动本来就选的那份。
- `scripts/lpc_audit_removed_locals.py HEAD` 0 项。格式化器只重排了 `jrsj.lpc`、`xyb.lpc` 两个文件。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。18 个文件 25 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）；`x op= 浮点` 先把浮点转成整数再运算（系数小于 1 时 x 直接变 0），改为 `x = to_int(x op ...)`：`/daemon/skill/fengyun-shou/foguang.lpc`（`damage *=`）、`/kungfu/skill/fengyun-shou/foguang.lpc`（`damage *=`）、`/kungfu/skill/taiji-quan/zhenup.lpc`（`damage *=`）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。
- 2026-10-14：技能文件里 72 处 `int power_point()`/`int hard_point()` 返回 1.3、1.75 之类的浮点，经 int 返回被截断；本库没有调用者，改成 `float` 返回值，保留原数值（`float_hooks.py`，KB 04 §6.10）。

- 2026-10-14：6 个文件因 `Type of returned value doesn't match function return type ( int vs void )` 整份不编译：声明为 `void`（或没写类型）的函数却返回值，旧驱动照样把值交给调用者。调用者要用返回值的（add_action 处理函数、命令、辅助函数）改为它实际返回的类型：`check_fight()`、`checking()`。驱动忽略返回值的 apply（`init`、`reset`、`heart_beat`、`create`）里改成空 `return;`（`return ::init();` 改为 `{ ::init(); return; }`，调用照旧）。新进程比对 HEAD 与工作树：10 个对象，新增载入 8，回退 0（`scripts/lpc_fix_void_return.py`，KB 04 §6.3）。

- 2026-10-14：`std/skill.lpc` 补上 `sum()` 与 `NewRandom()`：所有 `kungfu/skill`、`daemon/skill` 武功的 `query_action()` 都用 `NewRandom()` 按等级挑招式，本 lib 却从没定义，566 个武功文件整份不编译；补上后 560 个新载入（HEAD 与工作树新进程比对，回退 0）。`feature/skill.lpc` 补上 xkx 的 `prepare_skill()`/`query_skill_prepared()`/`query_skill_prepare()`（新增存档变量 `skill_prepare`，旧存档读出为空）：`/kungfu/class`、`/daemon/class` 的门派师父、`copyskill` 与 `zhentian-quan` 调用它们；308 个对象中 97 个新载入，其余卡在缺失的物品文件（`/clone/weapon/changjian`、`/clone/misc/cloth` 等 27 个，内容缺失）。擂台 `d/leitai/leitai.lpc` 补上 `fullup()` 漏掉的 `}` 并删去从未生效的重复 `do_quit()`。`kungfu/skill/poison.lpc` 的 `skill_improved()` 照基类回到 `void`。

- 2026-10-14：2 个文件因 `Illegal to inherit after defining global variables` 整份不编译：FluffOS 要求所有 `inherit` 写在第一个全局变量之前，MudOS 不管。`scripts/lpc_fix_inherit_order.py` 把写在 `inherit` 之前的全局变量（以及声明全局变量的头文件的 `#include`）挪到最后一个 `inherit` 之后（KB 04 §6.3）。

- 2026-10-14（toolkit 一轮，补上 NewRandom/prepare_skill 之后）：全 lib 重扫，31,559 个文件能编译，新载入的武功、师父文件里露出的 8 个未用局部变量删去；改动对象新进程比对无回退。`d/maze` 的 baihuazhen、dayan-ta 等迷宫房间仍不编译（调用的迷宫守护进程本 lib 没有），留着。

- 2026-10-14：`kungfu/skill/`、`daemon/skill/liu-unarmed.lpc` 的 `query_action()` 里取等级与 `for` 循环两行被注释掉，剩下 `if (level > action[i - 1]["lvl"])`，i 为 0，每次出招都报 `Array index must be positive or zero`；恢复这两行（与其他武功相同的写法）。逐个武功调用 query_action/valid_learn/practice_skill 的运行期探针发现。
- 2026-10-14：`daemon/skill/saoye-leg.lpc` 的 `valid_learn()` 直接取 `me->query("门派/shaolin")["saoye-leg"]`，没有少林记录的人学这门腿法时报 `Value being indexed is zero`；加 `mapp()` 判断。

## 内力/精力当作伤害种类（2026-10-15，KB 06 §7.241 第二类）

本库 `feature/damage.lpc` 的 `receive_damage()` 不接受 `jingli`/`neili`/`force` 等种类，`me->receive_damage("jingli", 30)` 之类在练功、绝招、吸取时报 `F_DAMAGE: 伤害种类错误`。59 处改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py` 第二步）。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。1 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。

## 内力/上限当作伤害种类（补）（2026-10-15）

`victim->receive_wound("force", n, me)`（兵器吸内力）、`receive_damage("max_qi", random(100))`（走火入魔扣上限）等本库不接受的种类，6 处改为 `add(type, -N)`。

## `message_vision(msg, environment(me), me)`（2026-10-15，KB 06 §7.242）

把房间当成了动作者：`message_vision()` 取房间的 `name()` 得 0，`replace_string(msg, "$N", 0)` 报错。在状态（中毒）里，这个错误发生在 `apply_condition(name, duration - 1)` 之前，状态永不结束，心跳里后面的恢复也每次被跳过。改为 `message_vision(msg, me)`：`/d/sfighter/jiejie3`、`/daemon/class/bonze/lunhui-zhang/fire`、`/daemon/class/npc/lunhui-zhang/fire`。


## 转码吃掉的引号（2026-10-15，KB 03）

原档在右引号前有一个孤立的 GBK 前导字节，转 UTF-8 时连引号一起丢了（如 `return name + HIM "发作身亡了;`），字符串一直延续到后面，文件编译失败：`/d/sansheng/shijie5`、`/d/wusheng/shijie5`。补回引号（`scripts/lpc_fix_eaten_quote.py`）。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。18 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。


## `->query_(` 笔误（2026-10-15，KB 06 §7.245）

调用不存在的函数 `query_`，call_other 静默返回 0，相关判断永远按 0 计算。改为 `->query(`：`buhui`、`buhui`。

## 妙手回春的银针检查（2026-10-15）

`miaoshouhuichun` 的 `valid_learn()` 用了未赋值的 `object ob`（`ob->query_temp("weapon")` 报错），还把兵器对象和字符串 "银针" 比较。改为 `ob = me->query_temp("weapon")`，再用 `id("yin zhen")`/`id("yinzhen")` 判断是否银针。

## 空手使用兵器绝招（2026-10-15，KB 06 §7.246）

`perform` 指令允许直接点名招式（如 `perform stick.ban`），这些绝招读了 `me->query_temp("weapon")` 却从不检查，空手时 `weapon->name()` 报错（有的已先扣了内力）。在赋值后补 `if (!objectp(weapon)) return notify_fail("你必须手持兵器才能使用这一招。\n");`（`scripts/lpc_fix_perform_weapon.py`）：`babao-gun/fo`、`tmjian/jianshen`、`wuyue-blade/jiao`、`yueya-chan/feicha`、`tmjian/jianshen`、`wuyue-blade/jiao`。

## 把经验、属性、内力当技能读（2026-10-15，KB 06 §7.247）

经验、属性、内力上限不是技能，xkx/ES 的 `query_skill()` 对它们只返回 0（风云的还会去载入同名技能文件而报错）。改为 `query("...")`（`scripts/lpc_fix_pool_as_skill.py`）：屠龙刀法 `/daemon/skill/yitian-tulong/tulong`、`/kungfu/skill/yitian-tulong/tulong`（比较经验时目标一侧读成 0）。

## 妙手回春的银针检查（2026-10-15）

`miaoshouhuichun` 的 `valid_learn()` 用了未赋值的 `object ob`，`ob->query_temp("weapon")` 每次都报错，谁也学不了；还把兵器对象和字符串 "银针" 比较。照 chidi 的修法改为 `ob = me->query_temp("weapon")`，再用 `id("yin zhen")`/`id("yinzhen")` 判断是否银针。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`hujia-dao`→`hujia-daofa`（`daojian-guizhen`、`daojian-guizhen`）；`lenyue-shengong`→`lengyue-shengong`（`lengyue-shengong`、`lengyue-shengong`）；`yinyun_ziqi`→`yinyun-ziqi`（`yinyun-ziqi/cure`、`yinyun-ziqi/cure`）；`bashishentong`→`bashi-shentong`（`lingjianjue`）；`buddhsim`→`buddhism`（`qianye-shou`）；`jinwu-dao`→`jinwu-daofa`（`jinwu-daofa`）。

## 嵩山剑法「蓄力」没穿布衣时报错（2026-10-15）

`songshan-jian/xuli` 用 `cloth = me->query_temp("armor/cloth")` 取衣服，随后直接 `cloth->query("material")` 判断要不要显示“衣袖鼓起”的描写；身上没有布衣时（裸身或只穿铠甲）这里报错，而此时 `apply/speed` 已经扣掉、复原的 call_out 还没排上，身法就一直少了一截。两处判断前补 `objectp(cloth) &&`。

## 技能名拼错：技能文件里拼错自己的名字（2026-10-15，KB 06 §7.249）

技能自己的文件（或它的绝招目录）里，`query_skill()` 读的是差一个字母的自己的名字，永远得 0：“基本功夫要高过本技能”之类的限制从不生效，按等级取招、计算伤害的那一项一直是 0。改为本技能的名字（`scripts/lpc_fix_skill_typo.py` 的 self 判据）：`chanyun-tui`→`chuanyun-tui`（`chuanyun-tui/shuangjue`、`chuanyun-tui/shuangjue`）；`xiyu-tiezhang`→`xiyu-tiezheng`（`xiyu-tiezheng`、`xiyu-tiezheng`）；`lianuuan-zhang`→`lianhuan-zhang`（`lianhuan-zhang`）。

## 柔云步法「柔云纵」有时报错（2026-10-15，KB 06 §7.251）

`rouyun-steps/zong` 随机把人送到三个房间之一：精、精力已经扣了，“乘云而去了”也说了，送不过去时人留在战斗里并报错。本库没有 `/d/city/wumiao`、`/d/city/kedian`、`/d/city/guangchang`，每次都报错；改用本库的城隍庙 `/d/city/chenghuang`、南城客栈 `/d/city/kezhan`、十字街头 `/d/city/center`。


## 银索金铃「点穴」对空手的对手报错（2026-10-15，KB 06 §7.246）

`yinsuo-jinling/dian` 失手时三种描写之一是“真气贯注”加对手兵器的名字，对手空手时 `ob` 为 0，三次失手有一次报错。改为 `(objectp(ob) ? ob->query("name") : "全身")`（泥潭一系原本就写作“真气贯注全身”）。


## 存档读不出来：转码损坏（2026-10-15，KB 03 §4.4）

`/u/snowtu/data/user/g/guang.oo.o` 在转码时坏了：原档里孤立的 GBK 前导字节被 `iconv -c` 连同后面的引号一起丢掉，`restore_object()` 报 `Illegal mapping format`，读档的对象（玩家、留言板、信件、表情）从空白开始。按 raw/ 原档重新解码（孤立字节丢掉、引号保留），驱动核对全部能读回（`scripts/lpc_save_encoding.py --from-raw`、`scripts/lpc_save_restore_check.py`）。

## 用兵器的绝招空手施展时报错（内联写法）（2026-10-15，KB 06 §7.246）

绝招不存兵器变量，直接写 `(me->query_temp("weapon"))->query("name")`（或在拒绝判断里写 `(weapon = me->query_temp("weapon"))->query("skill_type")`），之前又没检查兵器：空手 `perform` 时报 `Bad argument 1 to EFUN call_other()`，内力等往往已经扣掉。在第一次用到它的那条语句前补上“你必须手持兵器才能使用这一招”的拒绝（`scripts/lpc_fix_perform_weapon.py`）：`liangyi-sword/yin`。


## 存档读不出来：字符串里的换行、空行（2026-10-15，KB 03 §4.4）

`u/snowtu/data/fabao/l/llg-3.o`、`u/snowtu/data/fabao/s/sungirl-3.o`、`u/snowtu/data/zhangmen.o/zhangmen_master_zhaoyang.o`：字符串里有原样的换行（`save_object()` 存成 `\r`，`restore_object()` 逐行读，原样的换行让字符串收不了尾），或有空行（`Illegal file format`），读档的对象（留言板、NPC、玩家）从空白开始。换行改写成 `\r`、删去空行（`scripts/lpc_save_encoding.py --from-raw`），驱动核对全部能读回（`scripts/lpc_save_restore_check.py`）。

## 移进不存在的巫师房间（2026-10-15，KB 06 §7.251）

用完的物品、要“离开”的 NPC、掷在空中的兵器被移进巫师的工作室（`/u/aln/`、`/u/wind/`），本库没有这些房间。本库的 `move()` 用 `load_object()` 找目的地，找不到就返回 0，不报错，东西留在原处：药（人参、熊胆、狐狸皮、虎骨，`clone/drug/cb_renshen`、`clone/drug/hugu`、`clone/drug/hulipi`、`clone/drug/xiongdan`）吃下后没有移走，31 秒后才销毁，这期间还能交给别人再吃一次；被雇来打晕或杀人的李凌（`sjsh/u/stey/u/cnd/liling`）办完事后没有离开，留在原地。5 个文件改为移进本库的虚空房间 `VOID_OB`（`/obj/void`），与原作把它们“停放”在巫师房间的用意相同。

## 燃木刀法「焚天」的效果一秒就消失（2026-10-15，KB 06 §7.246）

每秒检查的 `check_fight()` 声明了 `object weapon;` 却从不赋值，条件里的 `!weapon` 永远为真，效果在第一次检查时就被撤掉。把这一项改为 `!objectp(weapon = me->query_temp("weapon"))`，先存兵器再判断刀的种类（本库 `SKILL_D` 指向 `daemon/skill/`，生效的是那一份；`kungfu/skill/` 里的旧副本一并改正）。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

448 个文件、638 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`），多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/clone/weapon/changjian`、`/clone/misc/cloth`、`/clone/cloth/cloth`）。本库 NPC 基类 `sjsh/std/char/npc.lpc`、`std/char/npc.lpc` 的 `carry_object()` 第一句是 `if (file->query_unique())`，对不存在的文件直接 call_other，驱动在这里报 `call_other() couldn't find object`，`new()` 来不及返回 0，所以只要 NPC 带着一件本库没有的物品就载入不了（调用处加判断对它无效）。在它前面补 `if (!objectp(load_object(file))) return 0;`（`--base`），缺的物品就跳过，NPC 照常载入；上面那些调用处同样改成带判断的块（基类以后改回去也不怕）。载入检查：改动的文件改前能载入 2 个，改后 412 个（410 个原来载入不了），没有退步；其余 39 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## 清风的倭寇奖励：整数除以浮点数（2026-10-18，KB 04 §6.10 `Float value truncated to int`）

`d/sunrise/npc/qingfeng` 的 `give_reward()` 按经验逐级缩减奖励：`mainexp /= 0.8`、`/= 0.9`、`/= 1.1`、`/= 1.2`、`/= 1.5`，`mainexp` 是 int，驱动先把右边的浮点数截成整数再运算：经验超过 15 亿时 `/= 0.9` 变成 `/= 0`（除以零，奖励发不出来），其余的 `/= 1.1`、`1.2`、`1.5` 都变成 `/= 1`，该缩减的奖励一点没缩减。改为 `mainexp = to_int(mainexp / 0.8)`（其余同），按原意先除后取整。

## 去掉的预定义宏 `SAVE_EXTENSION`（2026-10-18，KB 04 §6.11）

老版 MudOS 给每个 LPC 对象预先定义了 `SAVE_EXTENSION`（`".o"`）；FluffOS 的 ChangeLog（COMPAT_BUSTER 一条）把它删了，改用 `__SAVE_EXTENSION__`。本库没有自己 `#define` 这个宏，用到它的文件一律 `Undefined variable 'SAVE_EXTENSION'`，整个对象载入不了。改成 `__SAVE_EXTENSION__`（`scripts/lpc_fix_predefined_macro.py`）：`adm/daemons/network/netmail.lpc`、`clone/token.lpc`。`token` 是帮派领袖信物；`netmail` 是网络邮件守护进程（本库缺 `mailer.h` 等头文件，改后仍载入不了）。改后用 `lpcc` 逐个载入这些对象：1 个通过，1 个还有别的错误（`adm/daemons/network/netmail`：/adm/daemons/network/netmail.lpc:17: error: Cannot #include mailer.h）。

## 补回丢掉的基类宏（2026-10-18，KB 04 §6.13）

`inherit F_XXX;` 里的宏本库任何头文件都没有定义，报 `syntax error, unexpected L_IDENTIFIER, expecting L_STRING or '('`，整个对象载入不了；宏指向的基类文件本库其实有，别的库都把这个宏定义成同一个路径。在全局头文件 `include/globals.h` 里补上：`PILL` → `/std/medicine/pill`（9 个文件）。（`scripts/lpc_restore_macros.py`）改后用 `lpcc` 逐个载入这些对象：9 个里 9 个通过。

## `d/moon/obj/poem` 两句诗丢了收尾的引号（2026-10-18，KB 03 §4.6）

`string *poem` 数组里 `"不放玉花飞堕地，留在广寒宫阙。,` 和 `"把酒送春春不语，黄昏却下潇潇雨。,` 的收尾引号没了（转码时跟半个汉字一起丢了），下一行的开引号把字符串合上，后面的诗句成了代码：`Illegal character 0xe6`，整个物件载入不了。补回 `",`。载入：通过。

## `d/shendian/obj/niepan` 的收尾引号变成了私用字符（2026-10-18，KB 03 §4.6）

`set("long", HIR"……五种符号<U+E4D4>NOR);` 里本该是 `"` 的位置是一个私用区字符（转码时半个汉字加引号被换成了它），`Illegal character 0xee`，整个物件载入不了。换回 `"`。载入：通过。

## `kungfu/skill/qingyi-jian` 第一式的 `skill_name` 丢了收尾引号（2026-10-18，KB 03 §4.6）

`"skill_name" : "大悲式,` 的收尾引号没了（转码时跟半个汉字一起丢了），字符串连到下一行，`damage_type` 成了代码：`Illegal character 0xe5`，整个武功载入不了。补回 `",`（同系的 bixiecanyang、syxjl 等库里有完好的同名文件）。载入：通过。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 45 个对象设了本库没有文件的武功（94 个名字，最多的是 `xukong-steps`、`jiuxi-fuqi`、`huitian-fanri`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：30 个里 13 个通过，其余 17 个停在别的错误上（`d/baihuagu/npc/baicaoxian`：*No program in object '/d/baihuagu/npc/baicaoxian'!；`d/binghuo/tulong/npc/liuyun`：*No program in object '/d/binghuo/tulong/npc/liuyun'!……）。（`scripts/lpc_guard_set_skill.py`）

## 通向不存在房间的出口，按对面房间的回头出口改正（2026-10-18，KB 06 §7.257）

房间出口 `"west": __DIR__"xxx"` 指向的文件本库没有，玩家走过去就被卡住（笔误、改过名的房间，或者没带进档案的编号房间）。对面的房间存在、并且它相反方向的出口正好指回这个房间，说明出口原本就是通向它：`/d/sds5/evl/fenggu` 的 `westdown`：`er` → `dieryu`。改动后每个出口都能解析到本库的文件（`scripts/lpc_fix_dead_exits.py`；目标在运行时本来就能载入的库——虚拟房间——不动）。

## 补回本库没有的基类文件（2026-10-18，KB 04 §6.15）

下面这些基类本库没有，继承它们的对象（房间、NPC、物品）整批载入不了（`inherit XXX;` 的宏没定义，或者 `inherit "/std/…";` 的文件不在）。同系的库里有同名文件，两库有大量逐字节相同的文件（亲缘关系），所以从那边原样拷来，缺的宏补进全局头文件 `include/globals.h`：`/feature/dealer`（宏 `F_DEALER`）←sjshv150，21 个对象继承它，抽样 7/8 载入；`/inherit/char/worm`（宏 `WORM`）←wxddym，15 个对象继承它，抽样 8/8 载入；`/inherit/weapon/ring`（宏 `RING`）←hy5，9 个对象继承它，抽样 8/8 载入；`/feature/banker`（宏 `F_BANKER`）←yueyingqiyuan，4 个对象继承它，抽样 4/4 载入；`/inherit/room/river`（宏 `RIVER`）←xiakexing100，2 个对象继承它，抽样 2/2 载入；`/feature/coagent`（宏 `F_COAGENT`）←wdxtym，2 个对象继承它，抽样 2/2 载入；`/inherit/char/snake`（宏 `SNAKE`）←wdxtym，2 个对象继承它，抽样 2/2 载入。每个基类补回后单独载入、再抽样载入使用它的对象，基类载不进来或者一个用户也载不进来的就撤掉（本库撤掉了它们，不再补）。（`scripts/lpc_restore_bases.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 80 处、59 个文件：`bixie-sword`→`pixie-sword`（32 处）、`cibeidao`→`cibei-dao`（8 处）、`lahua-shou`→`lanhua-shou`（7 处）、`dagonforce`→`dragonforce`（5 处）、`yunu-xinfa`→`yunv-xinfa`（4 处）、`hellfire_whip`→`hellfire-whip`（3 处）、`changqaun`→`changquan`（3 处）、`yan-fly`→`yanfly`（3 处）等共 19 个名字。（`scripts/lpc_fix_skill_names.py`）

## 全局头文件丢了 6 个宏（2026-10-19，KB 04 §6.16）

`/include/globals.h` 里没有定义 `GOLD_OB`、`WEAPON_OB`、`MUSIC_D`、`ZJBR`、`MAILDIR`、`LOCATION_D`，用到它们的物件（名单里 9 个）编译时报 `Undefined variable`/`Undefined function`，整个物件载入不了（编译器在第一个未定义的名字上停下，后面的错误和警告都看不到）。同系的库在各自的头文件里都有这几行：照其中和本库共有文件最多的那个库，原样补到 `/include/globals.h` 最后一个 `#define` 之后，宏体里出现的路径在本库里都存在。补完后名单里有 5 个载入，其余还差别的东西。（`scripts/lpc_restore_defines.py`）

## 同一个 init() 写了两遍、内容不同（2026-10-19，KB 06 §7.265）

`d/xuyi/npc/maihuanu1`、`d/youxia/npc/maihuanu1` 里 `init()` 定义了两次（一个加 `buy`/`work` 之类的指令，另一个再加 `list`/`block_cmd`），驱动报 `Redeclaration of function 'init'`，整个物件载入不了。两处作者本来都要：把第二个 `init()` 里的 `add_action(...)` 并到第一个 `init()` 末尾，删掉第二个。（`scripts/lpc_merge_dup_init.py`）

## 找不到父类函数的 ::fn() 调用（2026-10-19，KB 06 §7.259）

`/d/kaifeng/npc/quest.lpc`、`/d/yhg/npc/die.lpc`共 2 个物件里写着 `::create();`、`::init();` 这类调用，而它们继承的基类并没有这个函数。老驱动把这种调用当成什么都不做、返回 0 的空调用，本驱动在编译时报 `Unable to find the inherited function 'init'.`，整个物件载入不了。这些物件的错误只有这一种（其他错误清掉之后才露出来的），逐个删掉这些调用（`return ::fn(...)` 改成 `return 0;`）。（`scripts/lpc_fix_dangling_super.py`）

## 出口指向不存在的房间（2026-10-19，KB 06 §7.257）

下列房间的出口写的文件不存在，而对面恰好只有一个房间的出口指回本房间，所以按对面的房间改正（笔误、大小写、路径少了一级）：

- `/d/qujing/wuji2/shandao3.lpc` 的 `west` 出口：`guankou` → `goukano`
- `/d/qujing/wuji2/shandao4.lpc` 的 `east` 出口：`guankou` → `goukano`

改后房间照常载入（与 HEAD 逐个对比，没有退步），出口现在指向存在的房间。

## 一行写完的源文件还原（2026-10-19，KB 06 §7.272）

下列 1 个文件的整个源码挤在开头的一行 `//` 注释里（档案的编辑器丢了换行），驱动只编译出一个空程序，物件载入后没有名字、没有 id、拿不到手上：`/d/jishouhang/jishou.lpc`。`scripts/lpc_uncollapse.py` 按语句、语句块、`#include` 重新分行，再过一遍格式化。还原后逐个载入没有退步，`new()` 出来的物件有名字和属性。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 被注释吞掉的 inherit / include（2026-10-19，KB 06 §7.274）

`/feature/team.lpc`：`#include <command.h>`。这些指令接在上一行 `//` 注释的末尾（档案里丢了换行），成了注释的一部分，驱动看不到：缺 `inherit` 的技能报 `Undefined function offensive_target`，缺 `#include <weapon.h>` 的兵器报语法错误。`scripts/lpc_fix_swallowed_directive.py` 把换行放回去。载入检查 1 个文件，0 个原来编译不过、现在载入，没有退步。

## 载入不了的零碎文件（2026-10-19，KB 03 §4.7、KB 04 §6.10）

- `daemon/skill/dugu-jiujian.lpc` 两句出招描述里的乱码（`「\0唤Ｂ渚叛恪梗…飨?n的$l`、`$n\0?l`）按 cctx 等库里完整的同一个技能还原成 `「一剑落九雁」，削向$n的$l` 和 `$n的$l`；原来驱动报 `Illegal embedded NUL byte` / `Invalid UTF8 codepoint`，技能载入不了。

逐个载入与 HEAD 对比，没有退步。

## 两个斜杠开头的物件路径（2026-10-19，KB 06 §7.276）

1 个文件、1 处物件路径写成 `//…`（如 `carry_object("//clone/cloth/hic_cloth")`）：`/d/youxia/npc/li.lpc`。当年的驱动不介意（路径先被规范化）；新驱动把原样的字符串交给 master 的 `valid_read()`，securityd 按 `//clone` 查目录，NPC 的 euid 没有权限，报 `Read access denied.`，NPC 载入不了。改成一个斜杠。

## 缺失的 unew()（2026-10-19，KB 06 §7.262）

本库的 NPC 和兵器在 `create()` 里调用 xkx 一系的模拟函数 `unew(file)`（`new()`，但遵守物件的 `unique` 上限），`/adm/obj/simul_efun.lpc` 里没有，调用者全部报 `Undefined function unew`（以及接收结果那一行的 `Bad assignment ( object vs unknown )`），载入不了。补上和 dtsl、pkuxkx、sjpl2 等库一样的 `unew()`（文件不存在时返回 0，不会让调用者死在 `carry_object()` 里）。

## 标准整理轮（2026-10-19，`scripts/toolkit_fix.sh`）

本库在新驱动下重扫，机械修复：7 个未使用的局部变量。修后与 HEAD 逐个物件对比载入，没有退步。

## 手工收尾（2026-10-19，KB 04 §6.10）

- `daemon/skill/liangyi-jian.bak.lpc`、`kungfu/skill/liangyi-jian.bak.lpc`：`query_skill_name()` 开头 `int i; level;` 里的 `level;` 是个没有效果的表达式（`Expression has no side effects, and the value is unused`），删掉。

逐个与 HEAD 对比载入，没有退步。

## 补回缺失的基类 `YUEQI`（2026-10-19，KB 04 §6.15，`scripts/lpc_restore_bases.py --retry`）

`inherit YUEQI;` 的基类文件 `/std/item/yueqi.lpc` 本库没有，宏也没有定义。从 sjshwzjqb 取来文件，并在 `include/globals.h` 补上 `#define YUEQI`；`/d/obj/misc/yaoqin.lpc` 因此载入。同一轮里重试的其余几个基类（这个库的 JOBNPC / SUPER_NPC / QUEST_OB / F_GUARDER 等）载入时仍缺别的东西，已经撤回，没有留下文件或宏。

## 补回丢失的标点（2026-10-19，KB 03 §4.6）

转换时丢掉的分号、逗号、引号或文件末尾的 `}`，共 26 个文件，修前 HEAD 载入失败。别的库里同路径的完好副本只比这里少几个标点，按它补回（括号里是那个库）：`/d/jz/npc/jiang.lpc`（dtxyzjb）、`/daemon/skill/beiming-shengong.lpc`（fy2mg）、`/daemon/skill/huashan-shenfa.lpc`（fy2mg）、`/daemon/skill/huashan-zhangfa.lpc`（fy2mg）、`/daemon/skill/qiankundanuoyi.lpc`（fy2mg）、`/daemon/skill/xiaowuxiang.lpc`（fy2mg）、`/daemon/skill/yunlong-shenfa.lpc`（fy2mg）、`/daemon/skill/yunlong-zhua.lpc`（fy2mg）。一行文字在逗号前丢了结尾的引号（下一行是同一个表的下一项），补上：`/daemon/skill/awenzhang-unarmed.lpc`、`/daemon/skill/emperor-unarmed.lpc`、`/daemon/skill/kunlun-zhang.lpc`、`/daemon/skill/qingyi-jian.lpc`、`/kungfu/skill/awenzhang-unarmed.lpc`、`/kungfu/skill/emperor-unarmed.lpc`、`/kungfu/skill/kunlun-zhang.lpc`。文件末尾少了 `}`（最后一个或两个字节丢了），补上：`/d/jjg/npc/erzhuan.lpc`（2 个）、`/d/jjg/npc/jjg/npc/erzhuan.lpc`（2 个）、`/daemon/skill/fanliangyi-dao.lpc`、`/daemon/skill/lingboweibu.lpc`、`/daemon/skill/taizuchangquan.lpc`、`/daemon/skill/unused/snowshade-force.lpc`、`/sjsh/u/stey/obj/putao.lpc`、`/sjsh/u/stey/obj/tao.lpc`、`/u/shulele/npc/nanren.lpc`、`/u/stey/obj/putao.lpc`、`/u/stey/obj/tao.lpc`。修后与 HEAD 逐个对比载入：这 26 个物件全部载入，没有退步（`scripts/lpc_restore_from_twin.py`、`lpc_fix_eaten_quote.py --comma`、`lpc_fix_eof_braces.py`）。

## 补回标点后新载入的物件里的未使用局部变量（2026-10-19，KB 04 §6.10）

之前载入失败、补回丢失的标点后才载入的物件里还有未使用的局部变量警告，共 4 个文件：`/d/jjg/npc/erzhuan.lpc`、`/d/jjg/npc/jjg/npc/erzhuan.lpc`、`/daemon/skill/kunlun-zhang.lpc`、`/kungfu/skill/kunlun-zhang.lpc`。删掉没有用到的声明；用 `scripts/lpc_listcheck.sh` 对比 HEAD 和改后，物件仍然载入，没有警告。

## 旧驱动的类型宽松：缺省参数、无类型形参、数组初始化、`class` 变量（2026-10-19，KB 04 §6.19、§6.20）

原来的 MudOS 把调用少传的参数补 0、把没写类型的形参当 `mixed`、不检查变量的声明类型与初始值，也允许变量叫 `class`；这个驱动在编译时全部拒绝，整个物件载入失败。修了 1 个文件：`/daemon/class/fuqiperform/perform.lpc`（`scripts/lpc_round_files.py` 的修复轮：调用处补写 `0`、无类型形参补 `mixed`、`string X = ({...})` 补星号、void 函数的返回值，以及 `class` 变量改名 `pick_class`）。逐个文件在 HEAD 和改后载入对比：这些文件里 1 个原来载入失败、现在载入，没有退步。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。改动：`/d/calvin/lanling/yuhuayuan.lpc`（1 处）、`/d/mingjiao/shanmen.lpc`（1 处）、`/daemon/class/mojie/liejiuquan/ball.lpc`（1 处）。另有 `/d/newborn/three/npc/juanlian.lpc`（1 处） 的条件下面做的是别的事（`==` 和 `||` 也可能是本意），保持原样。

## 比较链的人工修正（2026-10-20，KB 06 §7.282）

`d/newborn/three/npc/juanlian.lpc`：`accept_object()` 的检查 `id != 白琉璃 || ... || id != 紫琉璃 || !me->query(...) || id != "nver hong"` 永远为真，琉璃碎片一块也收不下，任务做不完。改成“不是这四块之一，或还没接任务”才拒绝；末尾的 `nver hong` 是多出来的第五项（函数里没有它的分支），去掉。

## `member_array('/', str)` 改为 `strsrch(str, "/")`：字符字面量的 member_array 按字节搜索（2026-10-20，KB 06 §7.283）

`member_array('/', str)` 里的 `'/'` 是整数，驱动按 UTF-8 **字节**搜索，返回字节偏移（带第三个参数时起点也是字节）；最新的 FluffOS（923cdbc0）在字符串里有非 ASCII 文字时，对每个调用点警告一次（`Warning: member_array(int, string) searches BYTES`）。而 `str[0..idx-1]` 按字符切，中文字符串会在错误的位置截断。改为 `strsrch(str, "/")`（找不到同样返回 -1，按字符计数；`scripts/lpc_fix_member_array_char.py`，JSON 编码器等少数几处手改）。改动：`/adm/daemons/vrm_server.lpc`（1 处）、`/quest/renzhi/vrm_server.lpc`（1 处）、`/quest/renzhi/vrm_server1.lpc`（1 处）。

## `call_out_info()` 的每一项只有 3 个元素（2026-10-20，KB 06 §7.287）

驱动返回的是 `({ 物件, 函数, 延迟 })`，不带 call_out 的参数，旧代码读第 4 项 `info[i][3]`（`callouts` 指令、`calloutd`、`cod` 工具）一读就报 `Array index out of bounds`，指令从第一行起什么也打印不出来。改为 `(sizeof(info[i]) > 3 ? info[i][3] : 0)`（`scripts/lpc_fix_callout_info.py`）。改动：`/cmds/arch/callouts.lpc`（1 处）、`/cmds/wiz/callouts.lpc`（1 处）。

## 浩劫系统 `verdict_time()`：领头玩家已经离线时 `lead->name()` 报错，戒严不解除（2026-10-20）

三十分钟后收场时 `lead`（接战书的玩家）若已退出游戏就是 0，`lead->name()` 在宣布战果的 `message()` 里报错，后面的 `LOGIN_D->set_madlock(0)` 不再执行，戒严一直保持，`quit` 指令因此对所有人关闭。改为 `(lead ? lead->name() : "各派豪杰")`。改动：`/feature/disaster.lpc`（2 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 38 处）。改动：`/clone/drug/liushen.lpc`（1 处）、`/cmds/wiz/callouts.lpc`（1 处）、`/cmds/wiz/dns.lpc`（1 处）、`/d/city/jiyuan2.lpc`（1 处）、`/d/city/mjlady3.lpc`（3 处）、`/d/city/npc/mjlady.lpc`（3 处）、`/d/longzhu/weapon/npc long.lpc`（1 处）、`/d/sfighter/npc/mjlady.lpc`（3 处）、`/daemon/class/jjg/hentian-jian/hentian.lpc`（1 处）、`/daemon/class/jjg/kuihua-baodian/onlyu.lpc`（1 处）、`/daemon/class/mojie/evilfight/dragonshoot.lpc`（3 处）、`/daemon/class/mojie/evilsword/16slash.lpc`（1 处） 等 22 个文件。

## `callouts`：`sizeof(info[i]) == 4` 把每一行都挡掉了（2026-10-20，KB 06 §7.287）

驱动的 `call_out_info()` 每项只有 3 个元素，输出行前的守卫 `if (sizeof(info[i]) == 4)` 永远不成立，指令只打印表头。改为 `>= 3`。改动：`/cmds/arch/callouts.lpc`（1 处）、`/cmds/wiz/callouts.lpc`（1 处）。

## `socket` / `dumpsocket` 指令：`dump_socket_status()` 驱动里没有（2026-10-20，KB 06 §7.291）

这些巫师指令 `write(dump_socket_status());`，MudOS 的 efun 在 FluffOS 里不存在，指令编译不过。在模拟 efun 文件里补了 `dump_socket_status()`：用 `socket_status()` 排出同样的表（没有 sockets 包的构建，比如 WASM，只有表头；`scripts/lpc_add_sefun.py dump_socket_status`）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/obj/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## `get_config(__MUD_PORT__)` 经旧版 `runtime_config.h` 得到字符串（2026-10-20，KB 06 §7.302）

本库的 `include/runtime_config.h` 是老 MudOS 的编号（整数设置从 15 起，本驱动从 256 起），`get_config(__MUD_PORT__)` 读到的是另一项设置（字符串），`(int)` 又只是编译期标注，于是 `socket_bind(fd, LOCAL_PORT())` 报 `Bad argument 2 to socket_bind()`，版本守护进程 `port = get_config(__MUD_PORT__) + VERSION_PORT` 是字符串相加。头文件自己的注释写明 `get_config(__MUD_PORT__) == __PORT__`，所以代码里的这个调用（连同外面的 `(int)` / `to_int()`）改成了驱动的预定义 `__PORT__`（`scripts/lpc_fix_mud_port.py`）。改动：`/include/getconfig.h`（1 处）。

## `closed` 守护的心跳每秒调一次不存在的 `versiond`（2026-10-20，KB 01 §1.3(c)）

`closed.lpc` 的 `heart_beat()` 以 `if (! VERSION_D->is_version_ok()) return;` 开头，本库没有 `/adm/daemons/versiond`：有人在闭关时，控制台每秒一条 `call_other() couldn't find object '/adm/daemons/versiond'`，闭关的后续处理（`load_all_users()`）也永远走不到。改成 `if (find_object(VERSION_D) && !VERSION_D->is_version_ok())`（KB 01 的写法：没有版本守护就当版本正常）。shenmo 里 `cmds/usr/closed.lpc` 还有一份守护代码的副本（敲 `closed` 就把它加载成指令对象，它的心跳每秒一条错误：扫描里一个动词 41 行），同样改了。实测：敲 `closed`、`look`、`score`、`hp` 之后单元输出里没有 `versiond`。加载检查 OK。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库现有的 NPC 文件里没有字面写成空 `chat_msg` 的（扫描只认 `set("chat_msg", ({ }))`）；守卫挡的是运行时才为空的列表和以后新增的 NPC。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/sjsh/std/char/npc.lpc`、`/std/char/npc.lpc`、`/u/xdao/npc.lpc`（共 3 个文件）。

## 存档里的 `.c` 文件名改成 `.lpc`（2026-10-21，KB 03 §4.2 第 9 项）

存档里写着 `"/d/city/npc/wei.c"` 这样的文件名；extract 时源文件已经全部改成 `.lpc`，而驱动对带扩展名的路径只认字面，`new()` / `load_object()` / `move()` 都找不到它，调用方多半把失败当成「没有这个东西」悄悄跳过。本库 12 个存档共 21 处按 `scripts/lpc_fix_save_dotc.py` 改成 `.lpc`（只改 `.lpc` 存在而 `.c` 不存在的字符串；玩家存档、备份、留言板、巫师目录和文件索引缓存不动）。改动：`/d/dntg/yunlou/npc/guai.o`（2 处）、`/d/newguai/npc/yaoguai.o`（1 处）、`/d/newguai/npc/yaoguai050606.o`（1 处）、`/d/newguai/npc/yaoguai1.o`（1 处）（等共 12 个存档）。

## 巫师命令不带参数时对 0 调用 efun（2026-10-21，KB 06 §7.336）

巫师（管理员）把命令敲成不带参数时，驱动把 0 传给字符串参数；下面的命令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`，这条指令从来没有用过。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py` 在第一处使用参数的语句前加守卫：文件自带 `int help(object me)` 的，守卫是 `if (!arg) return help(me);`（`help()` 定义在 `main()` 之后的 1 个文件补了原型 `int help(object me);`，否则编译报 `Undefined function help`）。改动（1 个文件，括号里是接住 0 的 efun）：`/cmds/adm/dumpprog.lpc`（`new`）。加载检查 HEAD 与工作树对照，没有退步。

## `update` 不带参数：`valid_read(0)` 先于 `cwf` 缺省（2026-10-21，KB 06 §7.342）

管理员扫描里 `update` 不带参数报 `Bad argument 1 to sscanf() Expected: string Got: 0.`（`/adm/daemons/securityd.lpc` 的 `valid_read()`，第一句 `sscanf(file, "/c/%*s")`）：`main(me, file)` 先 `SECURITY_D->valid_read(file, me, "read")`，之后才 `if (!file) file = me->query("cwf")`。把“缺省取 `cwf`、仍为空就拒绝”这两句移到权限检查前面（是移动，不是复制）。改动：`/cmds/wiz/update.lpc`。
