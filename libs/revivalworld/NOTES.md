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
