# revivalworld (重生的世界) -- porting notes

Source: `git clone https://github.com/MudRen/RevivalWorld` (commit
`71dcacb26b9db4a0813543761e2c610a2d4c04df`, cloned 2026-08-26). Confirmed
via `gh repo list MudRen` and a quick `ls libs/` scan not to be a
duplicate of anything already in this collection -- it is a genuinely
different codebase/lineage from every other lib here: Traditional
Chinese (BIG5), English-named source (`RWlib`) and content, built
against MudOS v22.2b14 (a bundled `MudOS-v22.2b14-RW-Build-Win32.zip`
Windows build is ignored, per convention -- only the LPC source was
converted and run through this project's own FluffOS build), and an
economic-simulation theme (land/cities/government, farming ->
manufacturing -> knowledge-era production chains, an in-game stock
market) rather than the wuxia-combat theme most of this collection's
libs share. Slug `revivalworld`, number 936, port 40238.

Raw archive: 1,498 files (~13MB), 813 `.lpc` files after conversion.
Top-level layout: `city cmds combat data doc include log obj quest
std system wiz www zone` -- the mudlib root is the repo root itself.

## Pipeline

1. Cloned into `libs/revivalworld/raw/RevivalWorld/` (git-hosted
   source, `.git` stripped before copying in).
2. `scripts/convert_lib.sh libs/revivalworld/raw/RevivalWorld
   libs/revivalworld/work BIG5` -- confirmed BIG5 (not the corpus
   default GB18030) by decoding `system/kernel/master.c` both ways and
   eyeballing the header comment ("主宰物件" only came out readable
   under BIG5). `already_utf8=124 converted=1310 lossy=1
   skipped_binary=37`; renamed 813 files to `.lpc`; fixed 347 literal
   `.c"` references; `static`->`nosave` touched 12 files (checked for
   both AGENTS.md 4.3 collision classes -- neither present).
3. Filename-level mojibake (separate from file *content*, which
   `convert_lib.sh` already handles): a full tree walk for non-UTF8
   *names* found two classes, both fixed by hand:
   - Four weather-data files under `system/daemons/etc/` had their
     BIG5-encoded season names (春/夏/秋/冬季) still raw in the
     filename (decoding attempts as BIG5/GBK on the exact bytes gave
     nonsense -- resolved by reading each file's own first line
     instead, which named its season correctly) -- renamed to
     `weather_春季` etc.
   - `doc/help/` and `doc/rwlib/` each had one real file plus a spurious
     `PaxHeader/` sibling directory -- artifacts of the original
     archive being packed from a GNU-tar extended-header tarball with
     non-ASCII member names, committed to git as literal mangled bytes.
     Decoded the real filenames from the PaxHeader entries' own stored
     `path=` metadata (BIG5-encoded, itself double-mangled through an
     intermediate Latin-1 hop) -- `doc/help/注音` ("Zhuyin/Bopomofo
     table", matching its content) and `doc/rwlib/目錄結構`
     ("directory structure"). The two `PaxHeader/` directories
     themselves are pure tar metadata, never real mudlib content --
     deleted.

## Fixes applied (driver-incompatibility bugs)

### The big one: creator.lpc's own #define-header generator was silently wiping itself

`system/kernel/creator.lpc` (on the preload list, so this runs on every
real boot) generates `include/{feature,inherit,daemon,condition}.h` --
every `#define WHATEVER_D "/system/daemons/whatever_d.lpc"`-style macro
this entire codebase uses, including the ones `simul_efun.lpc` itself
needs just to *compile* -- by scanning the source tree and stripping
each file's directory prefix and `.lpc` extension to build the macro
name. Its own `.c`->`.lpc`-rename-era extension checks/strips were
never widened past the old 2-character `.c` shape:
- `f[<2..<1] != ".lpc"` -- `<2..<1>` is the **last 2 characters** of the
  string, so this compared a 2-char slice against a 4-char literal and
  was *never once true*. Every file got skipped, every single time,
  from every one of the 4 generator functions.
- `f[strsrch(f,"/",-1)+2..<3]` -- stripped only the last 2 characters,
  leaving a stray `.l` even on files that *did* pass the check.

Net effect, confirmed by root-causing via temporary `write_file()`
instrumentation (this driver doesn't run any given object's `create()`
during a bare single-file `lpcc` compile-check *unless* that object is
actually loaded as part of the boot/preload/dependency chain, which
made this take real digging to isolate): every boot silently
**overwrote all four header files down to just their comment stub**
(confirmed against the archive's real shipped versions, which have full
content -- 85 lines in `daemon.h`, not 14). Once one of the earlier
compile attempts in this session hit that regenerate-to-empty path, it
took down essentially everything downstream: `simul_efun.lpc` itself
failed to compile (`Undefined variable 'CITY_D'`/`'MAP_D'`/etc.), which
cascaded into the "Master object 發生無限錯誤迴圈" (master hit its own
infinite-error-loop guard) message repeating for literally every single
file in a full `lpcc_check.sh` batch sweep (805/823 failures on the
first attempt, all the identical shared root cause per AGENTS.md 6.4).
Fixed by widening every one of the 4 generators' checks to `<4..<1>`
and strips to `<5>` (`system/kernel/creator.lpc`), matching the general
`.lpc`-vs-`.c` extension-width class already documented in AGENTS.md
4.2 point 4 -- just previously undocumented as also hitting a *check*
condition, not only strip widths.

The identical bug shape recurred independently in two more places, each
found by re-running the batch sweep and tracing the new failure back:
- **`system/daemons/command_d.lpc`'s own command-dispatch table** --
  `verb[<2..<1] != ".lpc"` / `verb[0..<3]` (2 sites, the wizard-command
  and sub-command registration loops). Since the check never matched,
  **zero player commands ever registered, at all** -- this is the exact
  "command-dispatch table slicing filenames with hardcoded
  2-char-extension arithmetic" bug class flagged as a known
  Chinese-wuxia-family pattern; confirmed here in an entirely
  English-lineage codebase too. Fixed the same way (`<4..<1>`/`<5>`).
- **`system/daemons/system_d.lpc`'s preload-list filter** --
  `distributed_system_preload()` reads `system/kernel/etc/preload`
  (also fixed separately, see below) and applies `file[<2..<1] ==
  ".lpc"` when expanding a directory entry, `path[<2..<1] != ".lpc"`
  when validating a bare-file entry -- meaning the `/system/daemons/`
  wildcard directory entry expanded to **nothing**, and the 3
  individually-listed bare-file entries (`city_d`, `area_d`,
  `creator` -- the comment literally says "CITY_D 必須先行載入", city_d
  must load first) all got silently removed from the preload list by
  this same check. Fixed the same way.
- **`std/inherit/feature/room/_remove_room.lpc`** and
  **`system/daemons/building_d.lpc`** had one more instance each of the
  same `[<2..<1]`-vs-`".lpc"` check (not the strip); fixed identically.
- `system/kernel/etc/preload`'s own bare-text entries still had literal
  `.c` extensions (`/system/daemons/city_d.c` etc.) -- a plain-text
  data file, so `convert_lib.sh`'s quoted-string-literal fixer never
  touches it (AGENTS.md 4.2 point 2's exact "bare paths in plain-text
  data files" shape). Fixed by hand (3 lines).
- Six more genuine extension-strip-only sites (check already correct
  width, only the strip needed widening) found by grepping every
  `[0..<3]` near a `get_dir()`/room-file-load call and confirming
  context: `system/daemons/zone_d.lpc` (6 sites), `city_d_main.lpc` (3),
  `estate_d.lpc` (7), `building_d.lpc`, `skill_d.lpc`,
  `cmds/std/wiz/whereis.lpc` (2), `system/kernel/simul_efun/object.lpc`.
  (Several *other* `[0..<3]`/`[<2..<1]` sites in the same files were
  individually checked and left alone -- they strip/check a genuinely
  2-character suffix like `.o`/`__SAVE_EXTENSION__`/`"()"`, unrelated
  to the `.c`->`.lpc` rename.)

### The database/set/query/delete architecture (F_DBASE-equivalent)

This lib's original custom MudOS build provided `set()`/`query()`/
`delete()`/`set_temp()`/`query_temp()`/`delete_temp()`/`addn()`/
`addn_temp()` as real driver efuns (see the bundled
`doc/driver/modify/source_files/packages/database.c` for the actual C
source) operating via C-level reflection on the *calling* object's own
`database`/`temp_database` mapping variable, walking a `"/"`-separated
path up to 20 levels deep. None of that exists on stock FluffOS.
Restored as:
- Real local methods on `std/inherit/feature/object/_database.lpc`
  (inherited by standard_object/standard_room/standard_npc/
  interactive/bulletin_board/standard_maproom -- virtually everything),
  so a bare call from most objects resolves locally via ordinary LPC
  function binding, matching the original semantics including the
  3-arg trailing-`ob` redirect (now a plain `ob->query(...)` call to
  the same local implementation on that other object) and the
  `query()`-only `shadow_ob` indirection `_database.lpc`'s own
  `set_shadow_ob()` already implements.
- **A driver-specific gotcha found here, not (yet) documented
  elsewhere in AGENTS.md**: a bare call from a file that does *not*
  itself `inherit DATABASE;`, but ends up composed into an object that
  does via a *different*, sibling `inherit` (e.g. `_reset_room.lpc`'s
  own `delete("temp_objects")` -- `_reset_room.lpc` has no inherits of
  its own; `standard_room.lpc` inherits both it and `DATABASE`
  separately), does **not** resolve to the sibling's method on this
  driver -- it falls through to the simul_efun fallback with
  `this_object()` bound to the simul_efun object itself, not the real
  room. (First caught live: every room's `reset_objects()` -- called
  from nearly every `reset()` -- throwing "object has no dbase" the
  first time any room with `temp_objects` reset.) Fixed at the
  simul_efun-fallback level in `rw_compat.lpc` by re-dispatching
  through `previous_object()` (the object whose code actually made the
  bare call) via a real `->` call, which *does* use full dynamic
  dispatch against that object's complete composite method table;
  guarded with `function_exists()` so a genuinely dbase-less object
  still degrades exactly like the original efun did (`query()`/
  `query_temp()` -> 0, the rest -> `error()`).
- `system/object/login_ob.lpc` declares its own **standalone**
  `nosave mapping database;` without inheriting the DATABASE feature at
  all (predates it, matching the old C reflection convention that
  worked on *any* object with a variable literally named `database`,
  not just ones inheriting a specific base class) -- restored real
  local `set()`/`query()` (with the same "/"-path nesting; this file's
  own `query("encode/gb")` call needed it) directly on that file. Every
  connection crashed inside `login_ob::create()`'s
  `set("callout", ...)` before this fix, caught by
  `master.lpc::connect()`'s `catch()`, so literally **every** connection
  just showed "登錄程式正在修改中，請稍後再試" (login program under
  maintenance) forever -- no banner, no prompt, nothing.

### ansi/arith_operator/chinese custom-package restoration

Also custom driver efuns from the same bundled C source
(`doc/driver/modify/source_files/packages/{ansi,arith_operator,
chinese}.c`), restored as simul_efuns in the new
`system/kernel/simul_efun/rw_compat.lpc` (included first in
`simul_efun.lpc`'s file list, since this driver resolves a same-file
bare call against whatever's already been compiled earlier in the same
translation unit -- AGENTS.md 6.5):
- `ansi()`/`remove_ansi()`/`noansi_strlen()`/`kill_repeat_ansi()`/
  `ansi_part()` -- ported faithfully in *behavior*, but rewritten to
  collect string pieces into an array and `implode()` once rather than
  `ret += ...` one character/escape at a time. This mattered for real:
  `system/daemons/html_d.lpc` (on the preload list) renders the whole
  world/city/area map as one heavily-ANSI-colored HTML blob (every one
  of ~1700 world-map cells can carry a color code) and calls
  `remove_ansi()` on the ~60KB result -- a naive character-by-character
  rebuild is quadratic and, combined with this environment's unusually
  slow per-character string-indexing throughput (confirmed by
  benchmark: a bare `s[i]` scan over 60,000 plain ASCII characters with
  no work per iteration took ~10 real seconds on this driver build),
  blew straight through the stock 30-second eval-cost wall-clock
  budget. Even after switching to array-collection (only appending at
  actual escape-sequence boundaries, not every character), the
  unavoidable single full-string scan still costs real seconds on this
  build, so `config.fluffos`'s `maximum evaluation cost` was also
  raised (30,000,000 -> 900,000,000 usec) as a genuine one-time-per-boot
  accommodation, not a code bug -- a release-mode driver build would
  very likely never need this headroom for the same task.
- `count(a, op, b)` (arith_operator's big-number decimal-string
  arithmetic, written for 32-bit MudOS) -- reimplemented with plain
  native 64-bit `int` arithmetic rather than porting the original
  by-hand decimal-digit algorithm; this driver's real int range is
  already far beyond anything this lib's actual money/quantity values
  ever reach.
- `cwrap()` (word-wrap) -- ported from BIG5 lead-byte-pair width
  detection to Unicode-codepoint width detection (CJK codepoints count
  as width 2, everything else width 1), since this driver's strings are
  UTF-8/codepoint-indexed, not raw BIG5 bytes.
- `B2G()`/`G2B()`/`bg5cc()` (raw-byte BIG5<->GBK re-encoding and a BIG5
  backslash-second-byte workaround) -- restored as no-op passthroughs.
  These only ever made sense against raw single/double-byte BIG5/GBK
  byte streams; there is no byte-level encoding left to convert once
  the whole lib (and driver) works exclusively in UTF-8. Every call
  site is gated behind an opt-in "encode/gb" player preference
  (default off) or the Intermud-2 daemon (see below), so this doesn't
  affect normal registration/gameplay.
- `remove_fringe_blanks()` -> `trim()` (real efun); `set_this_player()`
  -> no-op (this driver only compiles that efun in under
  `NO_ADD_ACTION`, which this build doesn't use; confirmed by reading
  `_command_usr.lpc`, the shared base every "cmd" funnels through, that
  this codebase's own dispatch is built around `this_object()`, never
  `this_player()`, so the only real gap is the rare NPC/labor/
  mahjong-AI call site forcing a non-interactive object to act as the
  current actor for one command); `remove_input_to()` -> no-op (its one
  call site is a login timeout about to disconnect the object anyway).

### Master applies / PACKAGE_UIDS

`system/kernel/master.lpc` had no uid concept anywhere (this lib
predates PACKAGE_UIDS) but this driver's build has it on and hard-fails
without `get_root_uid()`/`get_bb_uid()`; also `creator_file()` -- called
unconditionally for **every single object load** -- was missing too,
and its absence produces a uniquely catastrophic symptom: not a boot
failure, but every subsequent compile attempt in a batch sweep hitting
master's own "Master object 發生無限錯誤迴圈" guard (335,000+ duplicate
trace lines on the very first `lpcc_check.sh` run). All three added as
simple single-uid-world stubs.

### Hardcoded 3-port login architecture

`include/login.h` hardcoded `PPL_PORT 5000` / `WIZ_PORT 5001` /
`CLIENT_PORT 5002` -- the original server ran 3 separate driver
instances, one per port, and `login_ob.lpc::logon()` dispatches purely
on `query_ip_port()`, `return`ing 0 (no login daemon at all -- the
connection just sits open with no banner, ever) for any port that
doesn't match one of the three. Since this project's convention (like
every other lib here) runs a single port for everything, with admin
status granted per-account rather than per-connection-port, changed
`PPL_PORT` to this lib's real port (40238) so the one real port routes
through the normal player login flow. **Known limitation**: this makes
`WIZ_PORT`'s dedicated flow (`wiz_login_d.lpc`) permanently unreachable
-- an existing wizard-level account connecting through the single real
port gets an informational reminder ("您必須由連接埠 5001 上線才能擁有
巫師權限") but is not blocked from playing; `SECURE_D`'s file-permission
ACL is account-based (a `wizards` mapping keyed by id), independent of
connection port, so real admin file-access permissions are unaffected
-- only the separate "enter through the dedicated wizard welcome flow"
experience is unreachable now. **If this lib's assigned port ever
changes** (e.g. a collision with a concurrently-onboarded lib caught
after the fact), `include/login.h`'s `PPL_PORT` must be updated to
match, alongside `config.fluffos`.

### Missing runtime directories (AGENTS.md 7.11)

`mkdir -p`'d after being caught live during registration testing (none
of these ship in a fresh git checkout):
- `data/bug/` -- `system/daemons/bug_d.lpc::create()` does
  `sort_array(get_dir(DATA_PATH), ...)` unconditionally; crashed this
  preloaded daemon's own load on every boot.
- `area/` -- `area_d_main.lpc::restore_all_data()`'s `get_dir(AREA_ROOT)`;
  same shape, also preloaded.
- `log/{channel,command,command/etc,daemon,wizhall}/` -- discovered one
  at a time via live registration testing; `log/daemon/` specifically
  crashed `password_d.lpc::set_password()`'s own success-logging call
  (`log_file("/log/daemon/password", ...)`) on every single new-account
  registration, right after the password was already saved.
- `www/map/` -- `city_d_main.lpc`/`area_d_main.lpc` write per-city/area
  ANSI map-graph files here (`write_file("/www/map/citymap_...")`); the
  personal-wizard path `u/c/cookys/map/` referenced by an unrelated,
  unreachable dead file was *not* created (see Confirmed-dead below --
  `u/` doesn't exist anywhere in this archive).

### Assorted one-liners

- **`log_error()` warning-vs-error case mismatch** (the recurring
  §7.10-class bug in this collection): `master/error.lpc`'s
  `log_error()` checked capitalized `"Warning"` only; this driver emits
  lowercase `"warning: ..."`. Fixed to check both.
- **`(int)` cast on an already-int `foreach` variable**, a false trail:
  `ppl_login_d.lpc`'s new-ID character-class check used
  `foreach(string a in arg) if((int) a<'a' ...)` -- looked exactly like
  the classic "(int) cast is compile-time-only" bug (AGENTS.md's own
  standing reference note), but turned out to be the *opposite*: this
  driver's `foreach` over a string actually yields the loop variable as
  a real `int` codepoint regardless of its declared type, so the
  original `(int)` cast was a harmless no-op and an initial "fix"
  attempt (indexing `a[0]` on the assumption `a` was a string) broke it
  instead ("Cannot index value of type 'int'", caught live testing
  registration). Corrected by declaring the loop variable `int`
  outright and dropping the redundant cast. Lesson reinforced: verify
  a `(int)`-cast diagnosis against the actual runtime type before
  "fixing" it, not just the visual pattern match.
- **A stale, format-incompatible save file (`emote_d.lpc`'s saved
  custom emotions) silently took down every single player command,
  site-wide, from the very first boot.** `command_d.lpc::create()`
  calls `reset_commands()`, whose *very first* step (before the actual
  `cmds/` directory scan even begins) is
  `foreach(verb, fp in EMOTE_D->query_emotions_fpointer())`. That lazily
  loads `emote_d.lpc`, whose own `create()` does an unguarded
  `restore_object(DATA)` against this archive's shipped `emotion.o` --
  which this driver rejects outright (`restore_object(): Illegal
  mapping format while restoring emotions`) as a hard **throw**, not a
  graceful `0` return. Since nothing in the whole call chain (from
  `command_d`'s own `create()` all the way down) ever wraps this in a
  `catch()`, the throw aborted `reset_commands()` **before it ever
  reached the loop that loads `cmds/std/*`** -- so `std_commands` never
  got any player-level verbs registered at all, and every single
  command (`look`, `score`, `quit`, everything) failed with `沒有「X」
  這個指令` from the moment the driver finished booting, for every
  player, forever. Root-caused only after live registration testing
  reached actual world entry and *still* couldn't run `look` --
  compiling `command_d.lpc`/`emote_d.lpc` individually showed no
  errors, since the failure only manifests through this specific
  lazy-load call chain during a real boot. Fixed by wrapping
  `restore_object(DATA)` in `catch()` in `emote_d.lpc::create()` (a
  save-format mismatch now degrades to "no saved custom emotions"
  instead of taking the command system down with it), guarding
  `query_emotions_fpointer()`'s own `keys(emotions)` against `emotions`
  being unset, and skipping the `COMMAND_D->do_reset()` call on the
  failure path (calling it after `destruct(this_object())` re-entered
  right back into this same lazy-load chain on a fresh reload).
- **Smaller, separate issue found along the way**:
  `find_command_object("snoop")` returning 0 was spamming every single
  line of output to every player, independent of the bug above:
  `catch_tell()` (`_message_usr.lpc`) and `process_input()`
  (`_input_usr.lpc`) both call `COMMAND_D->find_command_object("snoop")
  ->notify_snooper_...(...)` unconditionally inside a `catch()`.
  `find_command_object()`'s own `function_owner(std_commands[ADMIN]
  [verb])` hard-errors (rather than returning 0) when the verb isn't
  registered, and even after guarding that, a bare `0->method()` call
  *also* hard-errors on this driver (`Bad argument 1 to EFUN
  call_other()`) rather than silently no-oping -- so the `catch()`
  around it was still catching a real error and logging/broadcasting
  it, on every message, to every player, the entire time. Root-caused
  via the "catch" log filling with dozens of identical entries during a
  single test registration. Fixed at both call sites with an explicit
  `objectp()`-style guard before the `->` call. (Not fully root-caused
  *why* `"snoop"` itself never registers in `std_commands[ADMIN]` --
  `cmds/std/wiz/snoop.lpc` compiles cleanly standalone and has the same
  shape as working wizard commands; left as a narrower follow-up since
  the snoop/wiz-monitoring feature itself is out of scope for this pass
  and the guard fully neutralizes the symptom.)
- `system/daemons/money_d.lpc`: `#define DEFAULT_PRICE_INDEX 1.` (a
  bare trailing decimal point, the "MACRO.0 float-promotion trick" bug
  class, AGENTS.md 6.3) -- this driver's lexer wants a digit after the
  dot; fixed to `1.0`.
- `combat/handler/unarm.lpc:37: #include <combat.h>` -- one ref param
  syntax fix aside (below), `combat.h` doesn't exist anywhere in this
  archive and `unarm.lpc` has zero references from anywhere else in the
  codebase either; confirmed dead, not fixed (see below).
- `obj/etc/mj/mj.lpc::show_all()`: `string arr` should have been
  `string *arr` (passed by `ref` into `otile_display(string ref *arr,
  ...)`, which every *other* call site in the same file already
  declares correctly) -- `arr[0] += ...` on a plain string tried to
  assign a string into an int (a character codepoint), "Bad assignment
  (int vs string)".
- **Old-MudOS ref-parameter syntax** (`TYPE &param`/`array ref param`)
  needed reshaping for this driver's grammar in a handful of spots:
  `system/kernel/simul_efun/file.lpc`'s `f_rmtree`/`f_cptree`
  (`array &res` -> `mixed &*res`) and `array.lpc`/`terrain_d.lpc` (2
  sites)/`obj/etc/mj/mj.lpc` (`array ref x` -> `mixed ref *x` -- this
  driver accepts the `ref` keyword form fine, just needs the pointer
  `*` to come *after* `ref`, not before).
- **Old-MudOS array-declaration dialects** (AGENTS.md 6.3, both
  distinct classes): bare `array x` with no element type (~340
  occurrences across ~160 files, safe to bulk-fix at this scale per the
  same section's own guidance -- fixed via a scripted two-pass sweep:
  multi-declarator statements got a `*` on each name, everything else
  got `mixed *`) and the two-word `TYPE array NAME` dialect (2 sites:
  `cmds/std/ppl/localtime.lpc`'s `string array DAYLIGHT_SAVINGS` and a
  doc-comment-only occurrence in `valid_socket.lpc`, real code already
  correct there). One first-pass sweep bug caught and fixed before it
  shipped: an unescaped regex corrupted 191 real calls to the
  **`arrayp()`** efun (`\barray\b` matched the `array` substring inside
  `arrayp` too) into `mixed *p(` -- caught by diffing against a fresh
  from-scratch conversion before committing, not left in.
- A single-quote-quote character literal (`case ''':` in
  `_input_usr.lpc`, meant to match a literal `'` for the `'say`
  shorthand) -- the exact "Multi-char character literals" class in
  AGENTS.md 6.3; fixed to `case '\'':`.

## Confirmed dead / not fixed (genuinely unreachable, per standing policy)

- `combat/handler/unarm.lpc` -- needs a nonexistent `combat.h`; zero
  references anywhere else in the archive.
- `std/module/object/{furniture/{chest,stool,chair},vehicle/car,
  tools/{rod,ring}}.lpc` (6 files) -- all `inherit OBJECT_ACTION_MOD;`
  (`tools/ring.lpc` also `inherit EQUIP;`), neither macro is ever
  defined anywhere and no file in the archive provides the obvious
  target content either (unlike, e.g., zhyx's `SKI_ZHEN` gap, where the
  target file already existed and only the macro was missing) --
  genuinely absent content, not fabricated. Zero references to any of
  these 6 files from anywhere else in the codebase either.
- `u/c/cookys/map/` (a personal wizard's map-export path,
  `write_file()`'d from somewhere under `obj/etc/mj/` presumably tied
  to that wizard's own tools) -- `u/` doesn't exist anywhere in this
  archive at all.
- `system/kernel/master/object.lpc` -- only ever `#include`d as a
  fragment by `master.lpc` (needs `VOID_OB` from `<object.h>`, which
  `master.lpc` includes before the fragment); shows as a batch-sweep
  "FAIL" only because the sweep tool attempts every `.lpc` file
  standalone, including files that were never meant to be independently
  loadable objects.
- `doc/driver/**/*.lpc` (renamed from `.c` by the blanket sweep, ~20
  files) -- the bundled reference C source for this lib's original
  custom driver patches, never real LPC, never `#include`d/inherited by
  anything; expected-permanent batch-sweep failures (`Cannot #include
  spec.h` etc.), same as every other lib's bundled driver-source docs.

## Boot / registration verification

- `~/src/fluffos/build-debug/src/lpcc`, single-file, confirmed clean on
  the core base classes before ever running a full batch sweep (per
  this project's RAM-safety discipline): `system/kernel/{master,
  simul_efun}`, and 6 of `std/inherit/standard/*.lpc` covering
  object/room/npc/interactive/bulletin_board/maproom.
- Full `lpcc_check.sh` batch sweep (823 objects, including `doc/`):
  RSS peaked around 250MB across every run this session (well under
  the 10GB safety threshold; monitored every ~20s throughout), each
  full run completing in 1-5 minutes depending on machine load.
  **783/814 non-`doc` PASS** on the final sweep (96.2%); every one of
  the remaining 31 failures (20 in `doc/`, 11 real) is accounted for
  above as either fixed-and-reconfirmed or confirmed-dead content.
  Three earlier full-sweep runs this session hit 805, 534, then 141
  failures respectively as the creator.lpc header-generator fix and its
  knock-on `command_d.lpc`/`system_d.lpc` siblings landed -- illustrating
  AGENTS.md 6.4's "one shared root cause, not N bugs" at real scale.
- Real `build-debug` driver boot on port 40238: clean boot, preload
  completes in ~2-3 minutes wall-clock on this environment (dominated
  by `html_d.lpc`'s map-render, see above -- **do not mistake a live
  driver sitting quietly during this window for a hang**; RSS settles
  around 120MB once preload finishes).
- Full registration flow verified via raw socket scripts
  (`scripts/mudclient.py`), many independent runs with real
  English-lineage ids (`qinling`, `qinhuai`, `qinshui`, `qinzhen`,
  `qincheng`, `qinyue`, `qinbo`, `qinrui`, plus the seeded `fluffos`
  admin account) through id -> display name -> password (typed
  twice) -> optional email -> gender (M/F) -> character creation ->
  actual world entry into the start room ("巫師神殿"/Wizard Temple),
  each producing a real save file under `data/user/<letter>/<id>`
  (throwaway test ids' save data deleted before finishing; `fluffos`
  and the two pre-existing `clode`/`msr` seed accounts kept). The
  `qincheng` run (before the `emote_d.lpc`/command-registration fix)
  couldn't run any command at all; the `qinyue` run (after that fix,
  before the `find_command_object("snoop")` guard) surfaced the
  `call_other()`-on-int-0 spam described above; the final `qinrui` and
  `fluffos` runs, after both fixes, cleanly ran `look` (showing the
  real start-room description and exits) with zero entries in
  `log/run` (uncaught errors) and only the pre-existing, harmless
  `restore_object(): Illegal mapping format while restoring emotions`
  warning (now caught gracefully instead of aborting command
  registration) in `log/catch`.
- Admin account seeded two ways, both confirmed live: edited the
  *persisted* save file directly (`system/kernel/data/secure.o`, a
  plain-text `mapping wizards` save -- the in-source `secure_d.lpc`
  default list only takes effect on a truly fresh boot with no save
  file present, per that file's own comment) to add
  `"fluffos":"admin"` alongside the two pre-existing seed entries
  (`clode`, `msr`); then registered a real `fluffos`/`Mud@2026`
  character through the normal flow above. The login broadcast on
  connection read `登入：Fluffos(Fluffos)由<Admin/127.0.0.1/.../-/->
  連線進入`, confirming the account's `(admin)`-equivalent status is
  live and recognized. Login through the single real port still routes
  through `PPL_LOGIN_D` (see the hardcoded-port section above), so this
  account's file-permission admin status (`SECURE_D`, account-based) is
  real and confirmed, but the separate dedicated-wizard-port login
  experience/room is not reachable through it.
- Outbound network check (task step 6): `system/daemons/intermud2_d.lpc`
  is preloaded (via the `/system/daemons/` wildcard) and opens a real
  UDP `DATAGRAM` socket (`socket_create`+`socket_bind`) plus a DNS
  `resolve()` call, sending real Intermud-2-style startup/mudlist-
  request packets to whatever hosts are in its saved `mudlist` --
  the same class of live network side effect already documented for
  `zhyx`'s `dns_master.lpc`. Its `read_callback()` was declared with a
  `string` parameter but this driver delivers DATAGRAM payloads as a
  `buffer`; widened to `mixed` with a `bufferp()`+`string_decode()`
  guard, matching that precedent exactly. **Flagging per standing
  convention: do not sweep this lib into high-frequency automated
  reboot loops** -- each boot is a real network event.

## Not run this session

- **LPC formatter (§9)**: not run against the handful of hand-edited
  files above (small, targeted edits, manually checked against
  surrounding style) -- consistent with this session's time budget
  given the unusual depth of driver-compat work this lib needed.
- **Full deep §10.7-style playthrough / WASM pass**: out of scope for
  this onboarding session per the task brief (native boot +ized
  registration verification only). The live Intermud-2 UDP traffic is
  an extra reason to be deliberate about how often this lib gets
  rebooted in any future automated long-sit/WASM-enablement pass.
- The `find_command_object("snoop")`-never-registers root cause itself
  (see above) -- the symptom is fully neutralized, but *why* `snoop`
  specifically fails to land in `std_commands[ADMIN]` while
  structurally-identical wizard commands do was not tracked down
  further; worth a future look if snoop/wizard-monitoring functionality
  is ever needed.

## 深度功能測試（round two, 2026-08-27）

Full AGENTS.md §10.7 pass: newbie-help read, one continuous live session
(raw Python socket scripts against `~/src/fluffos/build-debug/src/driver`
on port 40238, native, not WASM), registration through a fresh
non-wizard character (`qinfeng`/`TestPass123`, deleted before
committing -- see cleanup note below), movement into the coordinate map,
`quit`/`debug.log` grep/wall-clock gap/relogin, and a systematic grep
sweep for all six standing cross-cutting patterns (§7.121/§8.3a/§7.122/
§7.123/§7.124/§7.126). Two real bugs found and fixed; the economy/
stock-market systems specifically (the task's stated priority for this
lib) turned out to be unreachable live for a reason that is itself
documented below, not a bug.

### Bug 1 (new AGENTS.md §7.11 bullet): missing `city/fallencity1/0/room/` directory crashed `restore_all_data()` on every boot, which cascaded into a permanent 5-minute cron crash loop

`system/daemons/city_d_main.lpc::restore_all_data()` (called from
`city_d.lpc::create()`, on the preload list) does `foreach(roomfile in
get_dir(CITY_NUM_ROOM(city,num)))` to load each city section's built
"module rooms". `city/fallencity1/0/room/` doesn't exist in the shipped
archive (a fresh/never-built-on section has zero rooms, and git can't
track an empty directory), so `get_dir()` returned `0` and the `foreach`
threw `Bad argument 2 to foreach Expected: array Got: 0` at
`city_d_main.lpc:2794`, confirmed live via `log/system/preload`
(`載入 /system/daemons/city_d.lpc 時發生錯誤`). Two compounding
symptoms, both confirmed via `log/catch`:
1. `system_d.lpc`'s `distributed_preload()` catches the `load_object()`
   failure, logs it, and just drops `city_d` from the preload list
   (no retry) -- but a LATER pass over the same list (the
   `/system/daemons/` wildcard entry, which legitimately re-lists
   `city_d.lpc` alongside its own earlier "must load first" explicit
   listing, per `system/kernel/etc/preload`'s own comment) found the
   already-partially-created `city_d` object via `find_object()` and
   treated that as success -- masking the failure from a casual glance
   at the preload log (the SECOND `載入` line for `city_d.lpc` has no
   error after it, even though the object never finished initializing).
2. The crash happened BEFORE `restore_all_data()`'s own tail call to
   `assign_cities_num()`, which is the ONLY place that populates
   `sort_save_list` (a mapping used by `time_distributed_save()`, a
   `*/5 * * * * *` cron job, "每五分鐘城市資料分散儲存"). With
   `sort_save_list` left at its default `0` (not even an empty
   mapping), every single firing of that cron thereafter threw `Value
   being indexed is zero.` on `sort_save_list[++number]` at
   `city_d_main.lpc:369` -- confirmed live in `log/catch`, a fresh entry
   every 5 minutes, forever, for the rest of the boot's uptime.

**Fix**: `mkdir -p city/fallencity1/0/room/` plus a `.gitkeep`
placeholder (git can't track an empty directory, so without a
placeholder file this fix wouldn't survive a fresh `git clone` --
re-checked and found the SAME gap on three other directories already
`mkdir -p`'d during this lib's original onboarding session,
`data/bug/`, `area/`, `www/map/`: all three exist in the current local
working tree but were never actually committed as tracked content, so a
fresh checkout would hit the identical missing-directory crashes this
session already fixed once. Added `.gitkeep` to all four.) Verified
live: a full reboot after the fix showed a clean `log/system/preload`
entry for `city_d.lpc` (no error line) and `log/catch` stayed
completely empty through a full registration → movement → `quit` →
relogin session (previously it reliably grew a new entry every 5
minutes from the cron alone). See AGENTS.md §7.11's new bullet for the
general "get_dir() on a missing directory returns 0, not an empty
array, and a crash mid-init-function can leave a LATER global
permanently unset" pattern.

### Bug 2 (new AGENTS.md §7.128): `process_input()` returning the input string (instead of a nonzero int) made the driver's own "unknown command" fallback fire after EVERY player command, forever

Confirmed live on a completely clean, crash-free session: `look`,
`score`, `i`, `help`, and `command wizard` all produced their correct
real output, immediately followed by a spurious extra line reading
`什么？` ("what?") on its own. Root-caused via `config.fluffos`'s
`default fail message : 什么？` directive (a `grep` for the literal text
across the whole `work/` tree found it nowhere in any `.lpc` file, only
in this project's own generated driver config -- the first clue this
was a driver-level mechanism, not a stray mudlib string) plus
`~/src/fluffos/src/comm.cc`'s `process_input()` C function, which
inspects the LPC-level `process_input()` apply's return value to decide
whether to ALSO run the driver's OWN native `add_action()`-based command
parser on the input: a returned `string` re-parses that exact string
through the (empty, in this lib's case) native action table; a returned
`0`/falsy number falls through to parsing the ORIGINAL raw input
instead; only a genuine non-zero `int` skips the native parser
entirely. `revivalworld` builds a complete custom dispatch of its own
(`std/inherit/feature/living/usr/_input_usr.lpc` → `_command_usr.lpc`'s
`evaluate_command()`, invoked via `evaluate()` on a captured function
pointer) and never once calls the real `add_action()` efun anywhere in
the whole codebase (confirmed: the codebase defines its OWN, differently
-signatured, same-named `add_action(object, mapping)` LOCAL method in
`_action_usr.lpc`/`_action_npc.lpc` that shadows the efun everywhere --
every "add_action(...)" call site in the tree is calling this local
method, not the driver's). But `_input_usr.lpc::process_input()`, after
fully handling the command itself via `process_command()`, ended every
one of its 6 return statements with `return input;` -- the single worst
choice, since it explicitly asks the driver to re-parse the very string
it just finished handling against a command table with zero real verbs
on it, guaranteeing the driver's own fallback fires. **Fix**: changed
all 6 `return input;` inside `process_input()` to `return 1;` (verified
via `comm.cc` that this is the ONLY return shape that fully skips
`safe_parse_command()` -- a bare `return 0;` does NOT work, since `0` is
still a valid `T_NUMBER` svalue and the driver's own check is
specifically `ret->type != T_NUMBER || !ret->u.number`). Verified: `lpcc
--batch` PASS on the edited file, then a full live session (register →
`south`/`look`/`score`/`i`/`skill`/`quest`/`help` → `quit` → wait →
relogin → `look`) showed the trailing message gone from literally every
reply, `log/catch`/`log/run` stayed empty throughout. See AGENTS.md
§7.128 for the general pattern (any mudlib with its own full command
dispatch that shadows/never-calls the real `add_action()` needs
`process_input()` to return a genuine non-zero int on every
already-handled path).

### Economy/stock-market systems: confirmed unreachable live in this specific save snapshot, and why -- not a bug

This lib's shipped world has exactly one city, `fallencity1`, and its
raw persisted save data (`city/fallencity1/info`) has `"fallen":1` and
`"name":"廢棄都市"` (literally "Abandoned City") baked in directly --
this is the ACTUAL captured state of the original live server at
archival time (zero citizens, zero government, zero assets), not a
runtime bug introduced by conversion or by the missing-directory fix
above. `cmds/std/ppl/occupy.lpc`'s "found a new city on the ruins of a
fallen one" flow is the ONLY way to un-fall a city, and it costs
`OCCUPY_MONEY` = $RW 100,000,000 (`system/daemons/city_d_main.lpc`),
completely unreachable for a brand-new character who starts with
literally zero currency and no citizenship (citizenship itself, and the
starting-money/land-deed grant that comes with it, requires physically
registering at a functioning CityHall -- which doesn't exist in a fallen
city). This blocks the ENTIRE land/production-chain/stock-market loop
from a fresh player with no external funding, through any normal
in-game path, in this exact save snapshot.

I also confirmed, while investigating whether the seeded `fluffos`
admin account could be used to bootstrap around this (e.g. via the
wizard-only `givememoney` command), that **wizard-level commands are
completely unavailable to ANY account connecting through this lib's
single consolidated port, including the seeded admin account** -- a
materially bigger consequence than this file's existing "Known
limitation" note above (written during onboarding) currently states.
Root cause, traced end-to-end: `system/daemons/virtual_d.lpc`'s
`compile_object()` hook decides `WIZ_OB` vs `PPL_OB` for a restoring
player body via `SECURE_D->is_wizard(id) &&
(call_stack(1)[3]==load_object(WIZ_LOGIN_D) ||
call_stack(1)[3]==load_object(LOGIN_D))` -- but a RETURNING player
logging in through the ordinary port takes `ppl_login_d.lpc`'s OLD_PLAYER
branch, which calls the shared `load_user()` simul_efun directly; the
immediate caller frame at that point is `ppl_login_d` itself, which is
neither `WIZ_LOGIN_D` nor plain `LOGIN_D`, so the condition is never
true and `PPL_OB` is always chosen regardless of `SECURE_D` admin
status. Confirmed live and directly (not just by inference): `fluffos`'s
own save file header reads `#/system/object/ppl_ob.lpc`, and both
`givememoney $RW 100000000` and `command wizard`/an arbitrary
wizard-only verb came back `沒有「X」這個指令` (command not found) --
`wizardp(this_object())` never becomes true for this account through
this port, because `enable_wizard()` only ever gets called from
`_command_wiz.lpc`'s `enable_interactive()`, which only a `WIZ_OB`
inherits. `SECURE_D`'s file-permission ACL (used for e.g. `SECURE_D`
checks gating file edits) is genuinely unaffected, since that's a
separate, account-keyed mapping -- but essentially every in-game wizard
COMMAND (`givememoney`, and by the same mechanism every other
`cmds/std/wiz/*.lpc`/`cmds/std/adm/*.lpc` file) is unusable through the
single real port. This is a direct, if more severe than previously
described, consequence of this lib's ALREADY-DECIDED onboarding-time
port-consolidation tradeoff (`include/login.h`'s hardcoded 3-port
architecture collapsed onto one port) -- not a new/separate bug, and not
something this pass changed, since re-opening that architecture
decision is out of scope for a deep-test pass. Flagging for whoever
next needs in-game wizard-command access on this lib: the reliable
workaround this session used successfully is direct persisted-save-file
edits (as onboarding already did for `secure_d.lpc`'s `wizards`
mapping), not `givememoney`/other in-game wizard commands.

Given the above, the economic loop was exercised as far as is reachable
by an ordinary new character with the shipped starting resources:
registration, `score`/`i` (both empty/zero as expected for a brand-new
character with no city), movement into the `fallencity1` coordinate map
(confirmed working -- landed at `(50,50)`, "荒地"/wasteland, saw the
"廢棄都市"/"第一都市" map labels), `skill` (correctly reports "你目前沒
有學習任何技能"), `quest` (correctly reports "你尚未完成任何任務"),
`help topics` (pager works, `<数字>`/`B`/`Q` navigation not separately
exercised beyond confirming the pager itself renders and advances).
Land purchase, `build`, production chains (`grow`/`collect`/`order`),
enterprise/business ownership, and the stock market (`std/module/room/
stock.lpc`'s `list`/`buy`/`sell`) were NOT reachable live and are
UNVERIFIED beyond the source-level review already on record above (the
onboarding session's port/database/simul_efun restoration work, all of
which the stock-market code correctly builds on -- `count()`'s
string-arithmetic money handling, `to_int()`-wrapped share-price-to-cost
conversions, etc. -- but none of that was exercised through an actual
live `buy`/`sell` transaction this session). If this lib's world state
ever needs the economy live-tested end-to-end, the practical path is a
direct persisted-save-file edit granting a test character enough $RW to
`occupy city`, or restoring from an earlier, non-fallen snapshot of the
same city if one exists upstream.

### Six standing cross-cutting patterns (§7.121/§8.3a/§7.122/§7.123/§7.124/§7.126): checked, no live instances found

- **§7.121 (float-into-declared-int, especially economic functions)**:
  swept every economy-adjacent file (`money_d.lpc`, `exchange_d.lpc`,
  `estate_d.lpc`, `enterprise_d.lpc`, `city_d_main.lpc`, `tax_d.lpc`,
  `stock.lpc`, `bank.lpc`) plus a scripted whole-tree scan for
  `int`-declared functions returning an expression built from a
  `float`-typed local/param or a bare decimal literal with no
  `to_int()`/`(int)` wrap. This lib is unusually well-defended against
  this exact class BY DESIGN: all real player currency is stored and
  moved as `string` decimal values via the ported `count(a,op,b)`
  arbitrary-precision-arithmetic simul_efun (`rw_compat.lpc`), which
  itself does `to_int()` on both operands before computing -- and
  `big_number_check()` (the gate every `spend_money()`/`earn_money()`
  call funnels through) explicitly REJECTS a float value outright
  (returns 0) rather than silently accepting and corrupting it. One
  borderline, but genuinely dead, instance found: `exchange_d.lpc`'s
  `int compare(unit1,money1,op,unit2,money2)` returns
  `count(count(money1,"*",ex1), op, count(money2,"*",ex2))`, and
  `count()` returns a STRING (not an int) whenever `op` is one of
  `+`/`-`/`*`/`/`/`%` rather than a comparison operator -- a real
  declared-int-vs-actual-string mismatch if ever called with an
  arithmetic `op` -- but `compare()` has ZERO callers anywhere in the
  codebase (confirmed via `grep -rn 'EXCHANGE_D->compare\|->compare('`
  across the whole tree); every real currency-exchange call site
  (`bank.lpc`'s teller, `estate_d.lpc`'s cross-city asset totals) uses
  the sibling `convert()` function instead, which is correctly declared
  `string`. Left untouched per this project's confirmed-dead-code
  policy (documenting, not fixing, code with zero live callers).
- **§8.3a (`private` command-dispatch demotion)**: does not apply to
  this codebase's architecture. Every `cmds/**/*.lpc` file declares its
  own handler as `private void command(...)`/`private void
  do_command(...)`, but dispatch never goes through the driver's native
  `add_action()` at all -- see Bug 2 above for the full mechanism
  (`_command.lpc`'s `query_fp()` returns a function-pointer LITERAL
  created inside the object's own code, `(: do_command($1,$2) :)`,
  invoked later via `evaluate()`, not a driver-level `add_action`
  external dispatch that would be subject to the `private`→
  `DECL_HIDDEN` demotion this pattern normally catches). Confirmed live
  by the fact every single player command actually worked throughout
  this whole test session.
- **§7.122 (autoload/class-item duplication on reconnect)**: no
  `auto_load`/`compute_autoload_array`/`destroy_autoload_obj`/
  `load_autoload_obj` mechanism (or any equivalent "regenerate this item
  on next login separately from normal inventory restore" pattern)
  exists anywhere in this codebase (`grep` for all four TMI-2-lineage
  symbol names returned nothing) -- this is an RWlib-original codebase,
  not TMI-2-descended, and doesn't have this class of mechanism at all.
- **§7.123 (bare file-scope `IDENT = (...)` statement)**: a scripted
  brace-depth-aware scan of every `.lpc` file for a bare
  `IDENT = (...)`-shaped statement outside any function found zero real
  instances (the only matches were inside `doc/v22doc/`'s bundled C
  reference documentation, not real LPC).
- **§7.124 (percentage-threshold 0.0-1.0-vs-0-100 literal mismatch)**:
  no `wimpy`/auto-flee safety mechanism exists in this codebase at all
  (matches the task brief's own expectation that this economic-sim lib
  may lack a traditional combat safety net) -- `combat/handler/
  unarm.lpc` is confirmed dead (needs a nonexistent `combat.h`, zero
  references, per the onboarding session's own finding above), and a
  `fight` command exists for PvP but isn't gated by any percentage
  threshold of this shape. A targeted grep for `= 0\.[0-9]+;` assigned
  to an `int`-declared field found zero matches anywhere in `work/`.
- **§7.126 (stale pre-`.lpc` `.c` extension in a coordinate-AREA's saved
  door/exit data)**: this lib's map/movement system is NOT the
  macro-placeholder-resolved-at-runtime AREA-class engine this pattern
  targets (no `__DIR__`-in-save-data / custom `file_path()` door
  resolver anywhere -- the `__DIR__` occurrences found by an initial
  grep are all this driver's own compile-time `__DIR__` builtin macro
  used in ordinary `inherit __DIR__"foo.lpc";` statements, unrelated).
  Two harmless, pre-existing, non-gameplay-affecting stale-`.c`
  references WERE found in two of the three pre-existing seed accounts'
  own save data (`data/user/c/clode/data.o`'s `last_title_screen`
  property, `data/user/m/msr/data.o`'s `current_work/file` wizard-editor
  bookmark) -- traced both to confirm neither is ever passed to
  `load_object()` (one is a plain string-equality comparison used only
  to decide whether to reprint a map legend once; the other is a
  wizard's "resume last edited file" convenience whose target file
  doesn't even exist under either extension). Left untouched: this is
  pre-existing player(-equivalent) save data, not source, and the
  observed effect is purely cosmetic (one extra legend printout /
  editor "no such file" on next use), not a functional break -- fixing
  it would mean reaching into already-kept seed-account data for no
  live-observable benefit.

### Persistence verified

A full `quit` (clean exit via the `quit` command, not a timeout/
disconnect) correctly showed this lib's own quit flavor text ("你本次共
連線了十三秒" + a poem + "你離開遊戲了") and a subsequent relogin
restored the exact same map coordinate (`(50,50)`, confirmed both via
the live `look` output and directly via the raw save file's
`quit_place` field, `({49,49,0,"fallencity1",0,0,...})` from an earlier
net-dead-timeout disconnect in the same test run -- confirming both the
clean-quit AND the abrupt-disconnect save paths persist location
correctly). `log/catch` and `log/run` stayed empty across the entire
session, both before and after the two fixes above (i.e. the
process_input fix didn't need the missing-directory fix to be verified,
and vice versa -- independently confirmed).

### Cleanup and verification before commit

Test character `qinfeng` (created for this session) was fully removed
before committing: `data/user/q/qinfeng/` deleted, and its residual
entries in `system/kernel/data/password.o`/`password.o_backup` (the
crypt hash) and `data/daemon/money.o` (an empty `moneydata["qinfeng"]`
entry, created merely by existing as a registered citizen-less
character, never funded) removed by hand, restoring those two files
byte-for-byte to their pre-session state. Only the three original seed
accounts (`clode`, `msr`) plus the seeded `fluffos`/`Mud@2026` admin
account remain. `lpcc --batch` re-confirmed the single edited file
(`_input_usr.lpc`) compiles clean. The
`grep -h '"port"' libs/*/meta.json | ...` duplicate-port sanity check
(per task instructions) printed nothing before committing.

## wasm_status 审计（2026-09-01）：修复两处 sockets 包缺失崩溃，验证为 playable

`meta.json` 的 `wasm_status` 此前一直留空（NOTES.md 已注明"WASM 通道
未构建"，此前只做过原生驱动验证）。本次批量审计（见
[[project_wasm_status_audit]]）补上这一步。

首次用 `scripts/wasm_client.js` 起跑，driver 直接拒绝启动：

```
/system/kernel/simul_efun/socket.lpc:20:46: error: Undefined function socket_status
No error handler for error: *No program in object '/system/kernel/simul_efun'!
The simul_efun (/system/kernel/simul_efun) and master (/system/kernel/master) objects must be loadable.
```

与本收藏此前已修复的 `dsII`/`dsIII`/`lima`/`nightmare4` 同一类
bug（AGENTS.md §1.3(c)）：`dump_socket_status()` 无条件调用只有
编译了 `sockets` 包的驱动才有的 `socket_status()`，WASM 构建默认不带
这个包，导致这不是运行时缺失而是**编译期**报错，进而拖垮整个
simul_efun 编译。修复（`#ifdef __PACKAGE_SOCKETS__` 包一层，没有
这个包时退化成空字符串，与既有修复手法一致）。

修复后再跑，登入对象本身编译失败，每个连线在 `Can not accept
connection ... due to error in connect()` 后被直接拒绝：
`std/inherit/feature/living/usr/_ident_usr.lpc` 的 `get_ident()`
（被 `system/object/login_ob.lpc` 每次连线都无条件调用一次）整个
函数体依赖 `socket_address()`/`socket_create()`/`socket_connect()`/
`socket_error()`/`socket_write()`/`socket_close()`——这是 AGENTS.md
§1.3(c) 目录里"ident/auth 端口 113 查询"那一类的具体实例（此前只在
`huoying` 见过）。修复：整个函数体和其余几个只服务于这个功能的
回调函数一起包进 `#ifdef __PACKAGE_SOCKETS__`，没有这个包时
`get_ident()` 直接返回 0（表示身份识别不可用，原有调用方已经会
正确处理这个返回值）。

`cmds/std/adm/wscheck.lpc`、`cmds/std/guest/ident.lpc`/`userid.lpc`
（客人可用的手动 ident 查询指令）、`system/daemons/{dict_d,ftp_d,
http_client_d,im_d,intermud2_d,mud_d,realnews_d,smtp_d,socket_d,
socket_ob,translate_d,whois_d}.lpc` 等文件也用到 socket 相关 efun，
但都不在开机/登入这条关键路径上——它们是懒加载的指令文件或预载
精灵，编译失败只表现为开机预载列表里的一行"Failed"（预载完成后
驱动照常打印"啟動完畢，重新連線中..."），不影响真实登入，保持
原样不动，与本项目对同类"外围精灵编译失败"一贯的处理方式一致。

**开机行为提醒**：这个 lib 的预载会在跑完整个精灵列表后**主动
断开当前连线并提示"啟動完畢，重新連線中..."**，需要在测试脚本上
加 `--reconnect-on-disconnect`（`wasm_client.js` 现有参数）才能让
客户端跟着重连，否则会被误判为登入失败。已确认这不是 bug，是与
README 里记载的"开机预载持续 2-3 分钟"配套的既有设计。

两处修复后跑通一次完整会话：`new` 创角 → 英文 ID/名称/密码/信箱/
性别全部走完 → "歡迎 WasmTest(Wasmtest) 進入重生的世界。" → 落地
巫師神殿 → 5 秒后自动进入游戏 → 城市公告栏/新手提示正常显示 →
`quit` 干净退出（"你離開遊戲了。"），全程无未捕获错误。`wasm_status`
设为 `playable`。
