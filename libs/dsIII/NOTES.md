# Dead Souls 3.0 -- porting notes

Source: a ZIP archive (`ds3.0/`, 5553 files, `WINDOWS_INSTRUCTIONS.txt` at
top level) from mudbytes.net, a now-dead site. Recovered via the Wayback
Machine
(<https://web.archive.org/web/20190802014424id_/http://mudbytes.net/files/download/2733/>),
re-verified live (HTTP 200, real ZIP magic bytes, 5553-file/`ds3.0/`
top-level-dir match) at the start of this session before extracting. The
zip bundles `fluffos-2.18-ds07/` (a driver source snapshot), `bin/`,
`win32/`, `extra/` build/install scaffolding -- all ignored, this project
uses its own driver. The real mudlib root is the zip's `lib/` directory
(`bin/mudos.cfg`'s own `master file : /secure/daemon/master` confirms
it). Slug `dsIII`, number 182, port 40229.

## 1. Duplicate check -- distinct release, but the closest sibling by far

This collection already has FOUR Dead Souls entries: `dsI` (~1996-98,
Nightmare-IV-era, 2 domains), `dsII` (2006, "Dead Souls II", 4 domains),
and `ds386`/`deadsouls_fluffos` (3.8.6, 2014-era, 9 domains, confirmed
identical codebase generation to each other). Before building out a full
pipeline, checked whether "Dead Souls 3.0" repackages any of the four:

- **Self-identification**: `doc/RELEASE_NOTES` has a dated version
  history culminating in a `---- 3.0 ----` entry ("Released
  2009-12-30... Driver: added Kalinash's fix for Solaris on 64 bit
  SPARC... Added commands: anchor, unanchor..."), preceded by
  `2.11a20`-`2.11a22` entries -- a real, self-contained, later point
  release, not a copy of `dsII` (Nov 2006) or a re-save of `ds386`
  (2014). `README.txt`'s own title text is a stale "Dead Souls 2...
  Released December 2005" banner (last touched Jan 2008) that predates
  this zip's actual `RELEASE_NOTES` contents -- a rolling-tarball
  snapshot where the README just wasn't kept in sync, not evidence this
  is actually the 2006 "II" release.
- **Domain count**: 7 domains (`campus`, `cave`, `default`, `examples`,
  `Praxis`, `town`, `Ylsrim`) -- more than `dsII`'s 4, and a STRICT
  SUBSET of `ds386`/`deadsouls_fluffos`'s 9 (missing only `amigara` and
  `learning`, both added in later 3.x point releases per their own
  `RELEASE_NOTES` entries). `dsI` has only 2. 4598 files under `lib/`
  here vs. `dsII`'s 1937, `ds386`'s 4727.
- **`secure/daemon/master.c` comparison -- the decisive evidence**: 1157
  lines here vs. `ds386`'s 1157 (identical length) and `dsII`'s 781/
  `dsI`'s 749 (a different, much smaller shape entirely). A real `diff`
  against `ds386`'s raw archive shows only **8 changed lines total** --
  all tiny game-balance/logging tweaks (a `debug_message()` string, a
  `get_stack(1)` vs `get_stack()` arg, a clean-up percentage `26` vs
  `34`, an array-size cap `500` vs `1024`, an error-counter variable) --
  vs. `dsII`'s real, substantive divergence (added globals, a rewritten
  `load_access()` body). Against `deadsouls_fluffos`'s raw copy, the
  same file differs by 223 lines -- meaning **this archive's master.lpc
  is closer to `ds386`'s than `ds386` and `deadsouls_fluffos` are to
  EACH OTHER** (189 lines apart, two nominally-same-version 3.8.6
  copies from different sources).
- **Whole-tree file-identity check**: of the 4555 relative paths shared
  between this archive and `ds386`'s raw copy, **4136 (90.8%) are
  byte-identical**; against `deadsouls_fluffos` the rate is only 63.3%
  (2874/4542). 43 files exist only here (mostly `domains/campus/adm/*`
  admin scratch tools and cached `domains/town/virtual/sky/*.c`
  coordinate-instance files); 172 exist only in `ds386` (new content
  added in later point releases, including the two newer domains).

This is a genuinely distinct release -- not a byte-identical duplicate,
since 419 of the 4555 shared files differ and 43 are unique here -- but
it sits MUCH closer to `ds386`/`deadsouls_fluffos` in the lineage than
`dsII` ever did: this is best understood as an early-2010s snapshot of
the exact same "3.x" branch that later became 3.8.6, captured about 4-5
years and several point releases earlier. `duplicate_of` is `null` in
`meta.json`, but the whole fix catalog below was ported from `ds386`'s
own NOTES.md wholesale (verified per-file via `diff` against `ds386`'s
raw archive before applying each fix) rather than rediscovered from
scratch, since nearly every driver-compat bug turned out to be
byte-identical.

## 2. Conversion

English-language archive (public domain, from mudbytes.net) --
`scripts/convert_lib.sh` against `raw/ds3.0/lib` confirmed this:
4562/4598 files already valid UTF-8 (pure ASCII), only 5 lossy
conversions, 28 binary files skipped. 2290 `.c` files renamed to
`.lpc`, 603 literal `.c"` references fixed, 31 local angle-bracket
`#include`s converted to quotes, 1429 files touched by the
`static`->`nosave` sweep.

### 2.1 One source file was genuinely MIXED-encoding, not GB18030 -- and the lossy conversion broke its string-literal syntax

`secure/sefun/translate.lpc`'s `FLUBS` array (the same multilingual
"drunk talk" curse-word list `ds386`/`dsII` both have) contains:

- Two Finnish words with literal Latin-1 bytes (`"kyrpä"`, `"räkä"`,
  0xE4 = `ä`).
- One word that was **already valid UTF-8** in the raw archive:
  `"ХУИТА"` (Cyrillic, 5 characters, `\xd0\xa5\xd0\xa3\xd0\x98\xd0\xa2\xd0\x90`).

A single GB18030 pass mangled BOTH differently: the Cyrillic bytes
(already-correct UTF-8) got mis-decoded as GB18030 multi-byte sequences
into garbage CJK characters, and the Latin-1 `ä` bytes got silently
**dropped as invalid**, which ate the closing quote immediately after
`kyrp` too (`"kyrp\xe4"` -> `"kyrp"` was NOT what happened -- the actual
result was `"kyrp,"r鋕,"shawtay"`, a real syntax break: an unterminated
string swallowing the next comma, then an invalid bare identifier
`r鋕`). This is a genuine, driver-compat-relevant compile failure, not
just cosmetic mojibake -- confirmed by a first driver boot failing
simul_efun's compile entirely (`*No program in object
'/secure/sefun/sefun'!`). Fixed by hand: re-decoded the Finnish words as
Latin-1 and re-typed the Cyrillic word as literal UTF-8, leaving
everything else in the file (99% pure ASCII) untouched. Also
individually re-decoded with `iconv -f ISO-8859-1 -t UTF-8`: `doc/CREDITS`,
`doc/help/players/credits` (a `Lars Pensjö` name-with-diacritic), and
`domains/town/txt/mystery.txt` (a `¯\(°_o)/¯` ASCII-art shrug). One more
lossy file, `secure/save/functions.o`, turned out to be a stale
function-signature cache (`secure/daemon/function.lpc`'s
`RestoreObject()`/`file_exists()` guard handles a missing file
gracefully and rebuilds on demand) -- deleted rather than hand-repaired,
same precedent as `ds386`'s `functions.o`/`books.o` cache files.

## 3. Driver-compat fixes -- ported wholesale from `ds386`'s catalog, verified per-file

Every fix below was checked against `ds386`'s raw archive first (`diff`
on the specific file) to confirm the bug is byte-identical before
porting `ds386`'s exact fix; all were.

- **Missing `get_root_uid()`/`get_bb_uid()`/`creator_file()` master
  applies** (AGENTS.md section 7.2, and the `creator_file()` extension
  first cataloged on `ds386`): this driver's `PACKAGE_UIDS` build
  requires all three; missing entirely. Added byte-identical stub
  implementations (all constant `"root"`/`"backbone"`) to
  `secure/daemon/master.lpc`, same placement as `ds386`.
- **`log_error()`'s `load_object(WEB_SESSIONS_D)` re-entering the
  compiler mid-compile** (AGENTS.md section 7.60's pattern): same fix as
  `ds386` -- swapped to `find_object()`.
- **A stale `runtime_config.h` INT-slot-numbering mismatch** (AGENTS.md
  section 7.89, `ds386` is the origin case): this lib's own
  `secure/include/runtime_config.h` computed
  `BASE_CONFIG_INT = BASE_CONFIG_STR + 15` instead of the canonical
  driver's `RC_BASE_CONFIG_INT = RC_LAST_CONFIG_STR + 1` (=256) --
  every `get_config(__MAX_EVAL_COST__)`/`__MAX_BYTE_TRANSFER__`/
  `__MAX_READ_FILE_SIZE__`/`__MAX_STRING_LENGTH__` call (identical
  symbol set to `ds386`'s) would read the wrong config slot. Fixed by
  dropping in the driver's canonical header, same as `ds386`.
- **`OLD_ED` vs. this archive's split `ed_start()`/`ed_cmd()`/
  `query_ed_mode()` API**: `lib/editor.c` and
  `secure/cmds/creators/lsed.c` are BYTE-IDENTICAL to `ds386`'s raw
  copies, and `lib/interactive.c`/`lib/nmsh.c` differ from `ds386`'s by
  only one unrelated line (a `valid_event()` security check added later
  in `interactive.c`) -- so `ds386`'s exact rewrites were copied/ported
  directly rather than re-derived: `lib/editor.lpc` (full file copied
  from `ds386`'s fixed version), `secure/cmds/creators/lsed.lpc` (full
  file copied, stubs the batch-editor feature as unavailable),
  `lib/interactive.lpc`'s dead `ed_cmd(".");ed_cmd("x");ed_cmd("Q");`
  quit-path block removed (redundant under `OLD_ED`'s automatic
  `save_ed_buffer()` on destruct), `lib/nmsh.lpc`'s `query_ed_mode()`-
  gated custom ed-prompt branch collapsed to dead code (`if(0){...}`,
  unreachable since the driver prints its own ed prompt directly from C
  under `OLD_ED`).
- **`#define __DIR__ "..."` colliding with the native compiler
  predefine**: 13 files here (`domains/{town,default,Ylsrim}/virtual/
  *.lpc`) still had the old manual `#define __DIR__` idiom that
  `ds386`'s OWN copies of these same files had already dropped in a
  later point release (`ds386`'s `town`/`default`/`Ylsrim` virtuals have
  no `__DIR__` define at all -- confirms this archive predates whatever
  point release removed them, consistent with section 1's "same branch,
  earlier snapshot" finding). Removed all 13; the native `__DIR__`
  produces an identical value.
- **`secure/cmds/admins/sconv.lpc`'s `#ifndef __FLUFFOS__` guarding the
  wrong symbol** (this driver predefines bare `FLUFFOS`, not
  `__FLUFFOS__`): byte-identical raw file to `ds386`'s; same one-line
  fix (`__FLUFFOS__` -> `FLUFFOS`). Left the other ~9 files using the
  same guard untouched, matching `ds386`'s "no error, no fix" precedent
  -- all compiled and ran clean.
- **`secure/include/lib.h`'s `LIB_REMOTE` macro pointing at a
  nonexistent path** (`/lib/remote` when the real file lives at
  `secure/lib/net/remote.lpc`): same bug, same fix as `ds386`.
  `LIB_CAPTURE` (`/lib/capture`, no implementation anywhere in the
  archive) has the same pre-existing gap as `ds386` -- left unfixed,
  breaks only `domains/Ylsrim/broken/jar.lpc` (a file literally shelved
  in a `broken/` subdirectory in the original archive).
- **`SetLong`/`SetExternalDesc`/`SetInternalDesc` declared `string`-only
  when their `Get*()` counterparts already support `functionp()`/
  `arrayp()` dynamic-description values** -- 44 real call sites use the
  function-value form here (more than `ds386`'s reported failure count,
  since this archive's `cave`/`examples`/`Praxis` domains have their own
  additional users of the idiom). Widened `SetLong`/`SetExternalDesc`
  in `lib/events/look.lpc`, `SetInternalDesc`+`InternalDesc`'s declared
  type in `lib/events/look_in.lpc`, and `lib/std/room.lpc`'s `SetLong`
  wrapper, all to `mixed`/`mixed *` -- exact same fix and files as
  `ds386` (its own `lib/include/{room,interactive,door}.h` forward
  declarations were NOT widened either, matching `ds386`'s working,
  tested precedent that the header prototypes aren't enforced against
  the concrete override here).
- **`daemon/books.lpc`'s `LoadChapters()`/`lib/std/book.lpc`'s
  `eventLoadChapters()` declared `mixed *` (array) when the real payload
  is a mapping**: same bug, same 3-declaration fix as `ds386`
  (`daemon/books.lpc`, `lib/std/book.lpc` x2).
- **`domains/Praxis/supply2.lpc`'s `set_pre_exit_functions( ({...}),
  ({...}) )`** (a `#define`-aliased `SetProperty(string, mixed)` call
  given two arrays): byte-identical file to `ds386`'s (differs only in
  whitespace); every sibling room in the same directory already has the
  identical call commented out. Applied `ds386`'s exact fix (comment out
  with the same explanatory note).
- **`secure/sefun/sockets.lpc`'s `foreach (array item in finalsocks)`**
  -- the same `dump_socket_status`-in-simul_efun `array`-dialect pattern
  flagged as recurring across sibling libs. Fixed to
  `foreach (mixed *item in finalsocks)`.

## 4. `TYPE array NAME` dialect -- 166 files via an automated fixer, plus 7 hand-caught shapes the fixer's regexes didn't cover

Wrote a quote/comment-masking Python regex fixer (handles single-name
declarators with/without default values, multi-name comma lists, bare
`array NAME`/`array *NAME`, and `(TYPE array)` cast forms) and ran it
across the whole `work/` tree: **166 files changed** on the first pass
(`secure/cmds/admins/admintool.lpc`'s `array *classes;`/`array
*races;`, `secure/sefun/sockets.lpc`, `secure/sefun/sefun.h`, and 163
more). Then a full driver boot + a standalone re-grep surfaced 7 more
shapes the regex set didn't anticipate, each fixed individually and
verified there was exactly one instance:

- **`lib/body.lpc:1810`**: `class MagicProtection array
  GetMagicProtection(){ ... }` -- a `class TYPENAME array` FUNCTION
  RETURN TYPE, not a variable declaration. The generic fixer's "bare
  `array NAME`" rule actually MIS-FIRED here (matched the space before
  `array` regardless of the preceding `marriage`/`MagicProtection`
  token, since its negative lookbehind only checks the single character
  immediately before `array`) and produced the WRONG result
  (`class MagicProtection mixed *GetMagicProtection()` -- inserting a
  spurious `mixed`). Caught and corrected to `class MagicProtection
  *GetMagicProtection(){ ... }` by hand; grepped the whole tree for the
  same `class \w+ mixed \*` mis-fire pattern and confirmed no other
  instances.
- **`secure/daemon/finger.lpc:23`**: `private class marriage array
  Marriages;` -- same `class TYPENAME array` shape, in a variable
  declaration this time; hit the SAME fixer mis-fire
  (`private class marriage mixed *Marriages;`). Corrected to
  `private class marriage *Marriages;`.
- **`lib/guard.lpc:6`**: `private nosave array PendingGuard = ({});` --
  a bare `array NAME = default` (no element type, WITH an initializer);
  the fixer's bare-array rule only matched a terminator of `;`/`,`/`)`
  immediately after the name, not `=`. Fixed to
  `private nosave mixed *PendingGuard = ({});`.
- **`lib/std/story.lpc:20,65`**: `array GetTaleKeys();` /
  `array GetTaleKeys(){ return keys( Tales ); }` -- bare `array` as a
  FUNCTION RETURN TYPE (prototype and implementation). Fixed both to
  `mixed *GetTaleKeys()`.
- **`secure/sefun/sockets.lpc:14`**: `foreach (array item in
  finalsocks)` -- covered in section 3 above, same root pattern as
  `ds386`'s recurring `dump_socket_status`-class foreach.
- **`secure/cmds/players/history.lpc:32`**: `string *arr, tmp =
  ({});` -- the ORIGINAL (pre-conversion) source was `string array arr,
  tmp = ({});`, a multi-name declarator list WITH a default value on
  the second name. The fixer's multi-name rule required no `=` in the
  matched span, so it never touched this line at all, and it slipped
  through to a real compile failure (`Type mismatch ( string vs mixed *
  ) when initializing tmp`) since a bare `string *arr, tmp` only stars
  the FIRST name -- `tmp` stayed scalar `string` while assigned an
  array. Fixed to `string *arr, *tmp = ({});` (both starred, matching
  the old dialect's "applies to every name in the list" semantics, same
  as `ds386`'s NOTES.md documents for its own `admintool.lpc` finds).

All 7 fixes verified individually: a clean re-grep for each pattern
class found zero remaining instances, and a full driver boot + full
`lpcc_check.sh` batch sweep both came back clean of these specific
error signatures afterward.

## 5. Live verification

Booted clean (`Accepting telnet connections on 0.0.0.0:40229.`,
`Initializations complete.`, zero fatal errors, zero uncaught compile
errors in `log/debug.log`).

**Confirmed THREE independent real outbound network side effects at
boot -- more than any prior Dead Souls-lineage lib in this collection,
and the third one is NEW to this archive specifically:**

1. **IMC2** (`secure/daemon/imc2.lpc`, preloaded, `DISABLE_IMC2`/
   `DISABLE_INTERMUD` both `0` in `secure/include/config.h`): makes a
   real `socket_connect()` a couple seconds after boot. Confirmed live
   (`ss -tnp` showed `ESTABLISHED ... 204.209.44.3:8080`).
2. **Intermud-3** (`daemon/intermud.lpc`, preloaded): a second real
   connection attempt, confirmed live (`ss -tnp` showed
   `SYN-SENT ... 74.207.247.83:5000`).
3. **NEW: an automatic release-notes HTTP fetch on every single boot,
   with zero player interaction required.** `secure/daemon/autoexec.lpc`
   is ITSELF preloaded, and its `create()` schedules `eventRun()` via
   `call_out(..., 1)` -- one second after preload completes, with a
   `hasrun` guard so it only fires once per boot. `eventRun()`
   unconditionally does
   `catch( load_object("/secure/cmds/creators/dsversion")->cmd());`,
   and `dsversion.lpc`'s `cmd()` immediately opens a real socket to
   `dead-souls.net` (`97.107.133.86:80`) and fetches `/RELEASE_NOTES`,
   overwriting `doc/RELEASE_NOTES_HTTP` with the live response.
   **Confirmed live and reproducible on a bare idle boot with NO login
   at all**: `doc/RELEASE_NOTES_HTTP`'s mtime changed within ~14 seconds
   of driver start with zero connections made, and its content is a
   REAL, CURRENT response from a still-live server -- the fetched
   response includes release notes up through "3.9, Released
   2020-04-08", meaning **dead-souls.net itself is not dead** (unlike
   mudbytes.net, this project's actual archive source). A SEPARATE
   creator command, `secure/cmds/creators/rss.lpc`, has the same
   eager-`create()`-time network behavior (registers RSS feeds from
   `lpmuds.net`/`feedburner.com` via `call_out((: Setup :), 2)`) but is
   NOT itself preloaded -- it only fires if something actually loads the
   file, which an `lpcc --batch` compile sweep does (merely compiling
   `secure/cmds/creators/rss.lpc` as one of thousands of files in the
   sweep triggers its `create()` and, 2 seconds later, its own real
   HTTP/RSS fetches) -- confirmed by `doc/RELEASE_NOTES_HTTP` and
   `tmp/imc2.log` both getting freshly rewritten after this session's
   `lpcc_check.sh` runs, with no driver boot in between.
   **This means BOTH a live boot of this lib AND a bare `lpcc --batch`
   compile sweep of this lib can make real, uncontrolled outbound
   network connections to third-party servers** -- extend the existing
   "don't sweep into high-frequency automated re-boot loops" caveat
   (already standard for `dsI`/`dsII`/`imud`/`foundation2`-class libs)
   to cover automated/batch COMPILE sweeps of this lib too, not just
   driver boots. `doc/RELEASE_NOTES_HTTP` and `tmp/imc2.log` were reset
   to their originally-shipped/pristine state before every commit in
   this session; a future re-test will regenerate fresh copies again on
   its own next boot/sweep, which is expected and not a bug.

Tested with a raw Python socket client (`scripts/mudclient.py`), all
required flows in one continuous session:

1. **First-boot admin installation wizard** (`secure/lib/connect.lpc`):
   username `fluffos` -> password/confirm `Mud@2026` -> default display
   name -> gender `male` -> blank real name -> `fluffos@example.com` --
   completed successfully; the mud self-shut-down as designed
   (`connect.real`'s `shutdown()` + `destruct(master())`, matching
   `dsII`/`ds386`'s installer behavior -- a driver restart is required
   before the new admin can log in). `secure/cfg/groups.cfg` and
   `secure/include/config.h` correctly ended up with `fluffos` in place
   of the `ADMIN`/`DEBUG_NAME` placeholder tokens -- **unlike `dsII`,
   this archive's shipped `groups.cfg`/`config.h` already had the
   correct placeholder tokens (not a hardcoded original-author name), so
   no hand-fix was needed here.**
2. **Reboot + admin login**: `fluffos`/`Mud@2026` -> arrived in
   `/realms/fluffos/workroom` with wizard robe+hat, general/creator/
   admin news tiers all paged correctly, `who`-equivalent (`people`,
   auto-sourced via `.profile`) showed the admin present, `score`
   produced a correct full character sheet ("You are First Admin
   Fluffos (neutral)... a level 1 Human Explorer..."), `update` (no
   argument, current-room form) reported `Ok` (warnings-only compile,
   no errors), `quit` disconnected cleanly with correct
   inventory-removal messages.
3. **Ordinary new-player registration** (tested with `Qinbing`, an
   ASCII name -- **this archive enforces a strict `A-Z a-z ' -`
   name-charset check with an explicit rejection message, so a real
   Chinese name is out of scope here by design, same adapted bar as
   `ds386`'s own testing**): name -> confirm (y) -> age-gate (y,
   "Are you 13 years of age or older?") -> password -> confirm -> gender
   -> [display-name step skipped, `CUSTOM_FORMAT` is off by default] ->
   email (validated, a blank/malformed first attempt is correctly
   rejected and re-prompted) -> [real-name step skipped, `REAL_NAME` is
   off] -> race selection (`list`/`help RACE`/`pick RACE` -- 8 races:
   dwarf, elf, half-elf, half-orc, halfling, human, orc, poleepkwa) ->
   news pages -> landed in "The start room" (the `default` domain's
   entry point) with a correct ASCII-art room map and an HP/MP/SP status
   bar. Re-logged in as the same character on a second connection:
   `Reconnected.` (confirms the reconnect path is a distinct, working
   code path from fresh registration, not just registration succeeding
   once), `score` produced correct output, `quit` clean.
4. **`update <path>` on the 4 lpcc-flagged "eval-cost" failures**
   (section 6 below) confirmed 3 of the 4 are batch-sweep artifacts, not
   real bugs -- see that section for the one (`domains/cave/room/
   common1`) that is a genuine, but pre-existing and non-blocking,
   content-side performance bug.

2282 of 2291 `.lpc` files pass a full `lpcc_check.sh` batch compile
sweep (99.6%); the 9 that don't are broken down in section 6.

## 6. Known pre-existing gaps and sweep artifacts (not fixed -- content/archive design or tooling artifacts, not driver-compat)

- **`/obj/stargate`**: `#include this is here on purpose to prevent this
  from loading` -- a deliberate author anti-load trap, same class as
  `ds386`'s identical file.
- **`/obj/area_room`** and **`/open/prog`**: builder-tool scaffolding
  templates never meant to compile standalone in place (`area_room.lpc`
  is copied elsewhere by the room-building tool before its relative
  `#include` resolves; `open/prog.lpc` is written by
  `daemon/defines.lpc` at runtime with a `$S` placeholder later
  substituted) -- same non-bug class as `ds386`'s identical files.
- **`/domains/campus/chamber/elevator`** and **`/realms/template/area/
  room/sample_room`**: fail with ONLY a "Redeclaration of global
  variable" warning and no further error text -- confirmed harmless by
  an identically-warned sibling passing clean in the same sweep
  (`domains/campus/chamber/tree.lpc` for the first, any of dozens of
  `LIB_ROOM`-inheriting rooms for the second) -- the same
  isolated-single-file-compile artifact class `ds386`'s NOTES.md
  documents (AGENTS.md section 10.4).
- **`/domains/town/room/shop2`** and **`/realms/template/area/room/
  sample_room`** (again): fail with "Eval interrupted... cost limit
  reached" in the BATCH sweep, but **PASS when compiled standalone** via
  a single-file `lpcc --batch` run outside the shared-budget batch
  session -- confirmed a `feedback_lpcc_sweep_eval_cost_artifact`-class
  false positive (the whole `lpcc_check.sh` sweep shares one continuous
  eval-cost counter across thousands of files; a room whose `create()`
  clones a large `SetInventory()` list can tip over the limit purely
  because of what ran immediately before it in the batch, not because
  the file itself is slow). Also verified `shop2` live via admin
  `update` -- no error.
- **`/domains/cave/room/common1`**: fails BOTH in the batch sweep AND
  standalone -- a genuine, pre-existing performance bug, but confirmed
  present byte-identically in `daemon/races.c` in `ds386`'s own raw
  archive too (not something this port introduced). Root cause:
  `common1.lpc`'s `create()` -> `SetInventory()` clones an
  `orc_female1` NPC -> `SetRace("orc")` -> `NewBody()` ->
  `daemon/races.lpc:534`'s `SetCharacterLimbs()`, which hits "Too long
  evaluation" (5,000,000 usec) even though the actual per-race data is
  tiny (13 `HAND`/`LIMB` lines total for "orc"). `AddRace()`'s
  `LIMB`-parsing branch (`daemon/races.lpc:365-366`) has an actual
  duplicate-append typo -- `res["Limbs"] = ({ res["Limbs"]..., limb });`
  immediately followed by `res["Limbs"] += ({limb});`, appending each
  limb twice -- present identically in `ds386`'s raw copy, i.e. a real
  original-archive bug, not conversion fallout. Whether that duplicate-
  append is the actual root cause of the 5-second hang (vs. some other
  expensive step in the NPC/race/body creation chain) was not fully
  isolated; per this project's "programming bugs only, and even then
  verify before applying" discipline, and because `domains/cave/` is
  NOT preloaded and NOT on the core registration/login/play path this
  pass verified, this was left as a documented, non-blocking gap rather
  than speculatively patched. A future deep-play pass into the `cave`
  domain specifically should budget time to actually isolate and fix
  this (or confirm it's cosmetic/rare enough to leave).
- **`/domains/Ylsrim/broken/jar`**: `LIB_CAPTURE` has no implementation
  anywhere in the archive -- same pre-existing gap as `ds386`
  (the file is literally shelved in a `broken/` subdirectory in the
  original archive).
- **`/secure/cmds/admins/opcprof`**: calls the `opcprof()` efun, which
  doesn't exist in this driver build at all -- same as `ds386`, a
  creator-only diagnostic tool, not on any core path.

## 7. WASM pass

Measured 2026-09-03 against the shared `~/src/fluffos/build-wasm`.
`secure/sefun/sockets.lpc` was already stubbed (the `ds386` sibling
treatment this section originally predicted). No further mudlib-side
compile fix was needed. Verified with `scripts/wasm_client.js`:
`fluffos` / `Mud@2026` into Fluffos' workroom, `score` showed
"First Admin Fluffos", clean `quit`. IMC2/I3/HTTP version-check still
try outbound connects at boot — do not loop-reboot. Shop/combat/death
were not exercised this pass.

## 深度功能测试 / Deep functional test (round two, AGENTS.md §10.7)

First real *playthrough* pass on this lib (prior sessions only verified
registration + `look`/`score`/`quit` + the admin install wizard, per
section 5 above). Played a full, continuous session as an ordinary new
player on the native driver (`build-debug`), using a second admin
connection only for a controlled death test at the end. This is also
the first lib in the Dead Souls lineage (`dsI`/`dsII`/`ds386`/
`dshakkard`/`deadsouls_fluffos`) to get a §10.7 pass -- none of the
siblings have a "深度功能测试" heading in their own `NOTES.md` yet, so
the bug found below (and its fix pattern) should be checked against
all of them, not just this archive.

**Newbie path**: `read chapter 1 in handbook` (repeated through
"chapter N" for the whole book) is this lib's own onboarding doc.
Chapter 4 spells out the intended early game explicitly: level up on
weak monsters in "the newbie mansion" (reached from the village, past
a newbie-only gate guard and a locked mansion door -- the real way in
for a level-1 character is external: grab the ladder from the
gardener's shack west of the mansion, drop it under the mansion's
open second-floor window, and `climb ladder`/`enter window`), sell
loot to a shopkeeper (this archive's actual town vendors are James at
the Healers' Guild and Lars at the pub -- the handbook's own "Otik"
example is stock Dead Souls boilerplate text, not hand-tailored to
this archive's actual NPC names, a content detail, not a bug), bank
with Zoe, and eventually join a class (fighter/mage/cleric/thief) via
a guild NPC once a gating quest (Orcslayer) is done.

Test character: id `Qintestds`, ASCII name (per this archive's own
strict `A-Z a-z ' -` name-charset validation, same as `ds386`'s and
this archive's own admin-install testing in section 5 -- a Chinese
name is out of scope here by design), password `Abc12345`, human
Explorer -- **kept** (not cleaned up) as a representative playthrough
character, currently a ghost-then-regenerated corpse sitting in "The
start room" at half HP/MP/SP after the controlled death test below.
Save file: `work/secure/save/players/q/qintestds.o`.

### Bug found and fixed

**Silver/gold/every other in-game currency silently turns into a
float the first time it passes through ANY currency-exchange
calculation, corrupting the player's `Currency` mapping permanently --
`secure/sefun/economy.lpc`'s `query_base_value()`/`query_value()`/
`query_base_rate()`/`query_player_money()`, plus one sibling miss in
`lib/teller.lpc`'s `eventExchange()` and one in `lib/props/value.lpc`'s
`SetBaseCost()`.**

- Symptom: reproduced live buying a 2-silver bottle of water from Lars
  (the pub keeper) with `buy water from lars`. The very next attempt to
  learn a spell from Herkimer (`ask herkimer to teach light`) printed:
  `"Light costs 100 silver and you only have 88.000000."` -- a raw
  float leaking into player-facing text instead of a clean integer
  silver count. Confirmed at the data level too: after a `save`, the
  raw player file literally contains `Currency
  (["silver":88.000000,...])` -- not a display bug, the stored balance
  itself is now a float and stays that way forever (every future
  addition/subtraction against an already-float mapping value stays a
  float in this dialect, since a declared `int` type is compile-time
  only and never coerces an assignment -- see this project's own
  `reference_lpc_int_cast_is_compile_time_only` precedent and the
  `quest_times_percent_operator` corpus sweep for the identical class
  of bug in other libs).
- Root cause, traced end to end: `lib/std/barkeep.lpc`'s
  `eventSell()` (invoked by every `buy X from <barkeep NPC>`) does
  `x = query_value(ob->GetBaseCost(), query_base_currency(),
  GetLocalCurrency()); ... who->AddCurrency(GetLocalCurrency(), -x);`.
  `query_value()` and its helper `query_base_value()`
  (`secure/sefun/economy.lpc:59-70` before the fix) are both declared
  to return `int`, but their bodies do real floating-point exchange-rate
  math (`amount * rate`, `baseval / rate`, where `rate` always comes
  from `ECONOMY_D->__Query(type,"rate")`, a value the economy daemon
  stores and returns as a genuine `float`) and return that float
  **without ever calling `to_int()`** -- unlike their own two sibling
  functions in the exact same file, `currency_mass()` and
  `currency_value()`, which already correctly wrap their return in
  `to_int()`. Once a float slips into `x`, `AddCurrency(string type,
  int amount)` stores it straight into the `Currency` mapping
  (`lib/currency.lpc`'s `Currency[type] += amount`), permanently
  changing that currency's runtime type for the rest of the character's
  life. The bank's currency-exchange command
  (`lib/teller.lpc:227-229`, `ask zoe to exchange N x for y`) has the
  identical gap on its own separate line -- `i = val / currency_rate(str2);`
  -- missing a `to_int()` that the very next line in the same function
  (`charge = to_int(i / (100 / GetExchangeFee()));`) already has, so it
  independently reintroduces the same corruption even with
  `economy.lpc` fixed. `lib/props/value.lpc`'s `SetBaseCost(string
  currency, int amount)` two-argument form (used pervasively for
  pricing items, e.g. `SetBaseCost("silver", 10)` in dozens of files)
  has the same gap at its own point of origin: `Cost = i * rate;` with
  no `to_int()`, contaminating an item's *listed* price before it ever
  reaches a vendor transaction.
- Fix: added `to_int()` around the return value of `query_base_rate()`,
  `query_player_money()` (also switched its internal accumulator `x`
  from a lying `int` to an honest `float` that only gets truncated at
  the very end, for clarity), `query_base_value()`, and `query_value()`
  in `secure/sefun/economy.lpc`; wrapped `lib/teller.lpc`'s
  `i = val / currency_rate(str2);` in `to_int()`; wrapped
  `lib/props/value.lpc`'s `Cost = i * rate;` in `to_int()`. Every fix
  matches the `to_int()`-wrapping convention already established by
  sibling functions in the very same files -- this is closing an
  inconsistency the original code already knew the pattern for, not
  inventing a new one.
- Verified: rebuilt nothing (LPC-only change), ran the `lpc-syntax`
  formatter on all three touched files (all three §9 blind-spot checks
  came back clean), rebooted the native driver, reconnected as
  `Qintestds`. The character's pre-existing `silver` balance is still
  shown as `63.000000` in the raw save file after the fix -- **expected
  and left as-is**: the fix stops NEW corruption, it cannot retroactively
  un-float a value already written to a save file (that would need a
  one-time data migration, out of scope for a programming-bug fix).
  Proved the fix actually works by exercising a brand-new currency the
  character had never held: opened a bank account with Zoe and did
  `ask zoe to exchange 20 silver for gold` (the exact previously-broken
  `eventExchange()` path) -- after a `save`, the raw player file shows
  `"gold":2` with **no decimal point**, next to the still-float legacy
  `"silver":63.000000` in the very same mapping literal, proving the
  fix closes the corruption at its source. `log/debug.log` stayed clean
  (no compile/runtime errors) through the whole sequence.
- **Sibling libs to check**: `ds386`, `dsI`, `dsII`, `dshakkard`, and
  `deadsouls_fluffos` share this same Dead Souls Object Library
  codebase and, per this archive's own section 1 lineage analysis, are
  very likely to have byte-identical or near-identical copies of
  `secure/sefun/economy.lpc`, `lib/teller.lpc`, and
  `lib/props/value.lpc` -- worth a quick `diff` check and the same
  three-line fix on all of them the next time any gets a §10.7 pass or
  economy-focused re-test.

### What was tested and confirmed working

- **Registration**: full flow (name -> confirm -> age gate -> password
  + confirm -> gender -> email, validated -- a blank/malformed first
  attempt correctly re-prompts -- -> race pick, `list`/`pick human`) --
  landed in "The start room" with the starting Player's Handbook,
  t-shirt, and jeans, `score` and `i` both correct immediately after.
- **Movement/exploration**: the default domain's start room only has a
  `down` exit into the `campus` domain (LPC University, a separate
  builder-tutorial zone) -- this is `SetNoModify(1)`-locked, deliberate
  content structure, not a bug. Walked from there through campus,
  across "University Square", north along a connecting path into the
  actual `town` domain (village intersection, Saquivor Road, the
  mansion), and confirmed door/`open door` mechanics, a `climb
  ladder`/`enter window` alternate-entry puzzle (the mansion's front
  door is locked and needs a key; the intended level-1 route is
  external, via a ladder retrieved from the gardener's shack), and a
  newbie-only gate-guard bypass (`PreExit()` in
  `domains/town/room/gate.lpc`, correctly let a level-1 character
  "sneak past" with a flavor message).
- **Combat**: no player-reachable safe-sparring dummy exists in this
  archive (`domains/default/npc/dummy.lpc` sits in a creator-only
  `arena` room gated by `CanReceive()`; `domains/campus/npc/dummy.lpc`
  is never placed in any room at all -- both are inert example content,
  not a bug, just not wired up for ordinary players). Fell back to the
  handbook's own recommended weak target: rats in the mansion kitchen
  (`domains/town/room/mansion_room7.lpc`, `SetLevel(1)`,
  `SetMaxHealthPoints(10)`). A full `kill rat` fight ran cleanly for
  several dozen exchanges (both sides mostly missing at level 1,
  unarmed -- slow but correct, matches the handbook's own explanation
  of skill-based to-hit), correctly updated `melee attack`/`melee
  defense` skill percentages in `stat` from use, and `ignore all` +
  moving away correctly disengaged without further loss once clear of
  the room.
- **Skill/class acquisition, two paths**: asked Herkimer (the Mages'
  Guild guildmaster) directly `to join` -- correctly refused pending
  the Orcslayer quest (`"First you must prove yourself worthy..."`,
  `herkimer.lpc`'s `JoinGuild()`). Asked him `to teach light` (the
  organic, no-guild-required spell-purchase path) -- correctly gated on
  affordability, which is exactly the interaction that surfaced the
  currency bug above.
- **Shop/economy**: bought a claritin pill (10 silver) from James at
  the Healers' Guild and a bottle of water (2 silver) from Lars at the
  pub -- both transactions correctly moved the item and deducted
  silver, `i`/inventory updated immediately. Opened a bank account with
  Zoe (`ask zoe for account`, 5-silver minimum deposit) and successfully
  exchanged currency (`ask zoe to exchange 20 silver for gold`) -- see
  the bug section above for what this surfaced and how it was verified
  fixed.
- **Death/respawn**: no reachable-in-budget wild monster could kill a
  420-HP level-1 character in reasonable real time (the rat fight above
  shows just how low the to-hit rates are at level 1), so this was
  triggered directly and deliberately via the seeded admin account
  (`fluffos`/`Mud@2026`) on a second connection: `eval object ob =
  find_player("qintestds"); return ob->eventDie("test smash");` against
  the **non-admin** test character (never the admin's own body, which
  would hit `lib/creator.lpc`'s wizard-exempt `eventDie()` override
  instead and prove nothing). Confirmed the full cycle live: death
  message + ASCII "YOU ARE DEAD!" art, `score` correctly showed
  `Qintestds the ghost`, `undead` race, and reduced max MP while dead;
  `regenerate` correctly rematerialized the character at roughly half
  HP/MP/SP, applied the expected XP penalty (50 -> 38, `score`'s
  "more experience points to advance" figure moved from 450 to 462
  accordingly), and dropped the character back at the same default
  "start room" respawn point. `log/debug.log` stayed clean through the
  whole death/regenerate sequence.
- **`quit` / debug.log / reconnect after a real gap**: `quit` produced
  the correct "Please come back another time!" message and clean
  worn-item-removal text; `log/debug.log` showed zero errors immediately
  after (this project's own §7.16/§10.7 lesson: a clean-looking `quit`
  message does not by itself prove nothing broke server-side -- checked
  anyway, and it really was clean here). Waited a genuine 90-second
  wall-clock gap, reconnected with the same login/password, and landed
  back exactly where the character had quit (First Village Bank, same
  worn items re-equipped), with `score` correctly reflecting realistic
  additional food/drink decay over the elapsed real time.

### Minor observation, not fixed (cosmetic, not a programming bug)

`domains/town/room/mansion_uhall1.lpc` (and likely other rooms using
the same `window`-as-exit idiom) defines `"window"` as BOTH a raw
`SetExits()` key and a `SetEnters()` entry. The room's own
`GenerateObviousExits()`-generated text lists `"window"` as if it were
a plain bare-word direction right alongside `down`/`west`/`east`/`south`
(`"Obvious exits: down, west, east, window, south, enter window"`), but
typing bare `window` actually fails (`"There is no go window here."`)
-- only `enter window` (or, per `verbs/rooms/go.lpc`'s own help text,
presumably `go window`) actually works. Root cause: `lib/nmsh.lpc`'s
bare-word-to-`"go "`-command pre-aliasing only covers the fixed
classic-cardinal-direction set (n/s/e/w/ne/nw/se/sw/u/d/out), never
arbitrary custom exit names, while `lib/std/room.lpc`'s
`GenerateObviousExits()` blindly `implode()`s every raw exit key into
the display text regardless of whether it's bare-word-usable. This
looks like it would affect every room in the whole Dead Souls lineage
that names a custom exit outside the cardinal set (not something
introduced by this archive), and it's misleading-but-harmless UI text,
not a crash or wrong efun call -- documented here per the project's own
scope discipline (`ERR_THERE_IS_NO` is a normal, non-fatal parser
rejection, not a bug signature) rather than "fixed" by guessing at what
the room author actually intended.

## Sibling sweep of ds386's round-two `eventRevive()`/room.lpc/combat.lpc/beggar.lpc bugs (2026-08-27)

`ds386`'s own round-two deep-functional-test pass (this NOTES.md's own
sibling file) found and fixed four bugs and flagged all of them for a
sweep across the whole Dead Souls 3.x lineage: (1) `SEVERE`
`eventRevive()` feeding float arithmetic into `AddHealthPoints()`/
`AddMagicPoints()`'s `int` parameters (AGENTS.md §7.121 class), (2) the
MudOS-era `replace_program()` fold in `lib/std/room.lpc`'s `create()`
(AGENTS.md §7.141), (3) the `Wimpy` fraction-vs-percentage bug in
`lib/combat.lpc` (AGENTS.md §7.124 class), and (4) a minor `GiveMap()`
reentrancy gap in `domains/town/npc/beggar.lpc`. Checked all four here:

- **Bug #1 (`eventRevive()` float corruption): NOT PRESENT, confirmed
  clean.** `lib/player.lpc`'s `eventRevive()` heals back HP/MP/SP via
  plain integer division (`AddMagicPoints(-(GetMaxMagicPoints()/2))`,
  `AddStaminaPoints(-(GetMaxStaminaPoints()/2))`,
  `AddHealthPoints(-(GetMaxHealthPoints()/2))`) -- this codebase never
  adopted the `PERCENT_MP`/`PERCENT_HP` float-`#define` percentage
  scheme `ds386`/`dshakkard`/`deadsouls_fluffos` use here, so there is
  no float expression feeding the `int` parameters at all. No fix
  needed.
- **Bug #2 (`replace_program()` fold in `lib/std/room.lpc`): PRESENT,
  fixed identically to `ds386`/`dsI`.** Removed the
  `replaceable(this_object()) && !GetNoReplace()` → `inherit_list()` →
  `replace_program(tmp[0])` fold from `create()` entirely (pure memory
  micro-optimization, no functional effect once applied since this
  driver defers `replace_program()`'s effect to a periodic backend
  sweep, which crashes any closure built on a freshly-loaded room, e.g.
  `eventHearTalk()`'s `TALK_AREA` filter, for roughly its first 5
  minutes). `SetNoReplace()`/`GetNoReplace()` left in place as harmless
  now-unused API.
- **Bug #3 (`Wimpy` fraction-vs-percentage): PRESENT, fixed identically
  to `ds386`.** `lib/combat.lpc:65` had `Wimpy = 0.20;` (declared
  `private int Wimpy`, so the float literal silently truncated) instead
  of `Wimpy = 20;`, plus `SetWimpy`/`GetWimpy` mistyped `float` instead
  of `int`. Fixed both. **Verified live**: booted
  (`~/src/fluffos/build-debug/src/driver config.fluffos` from
  `libs/dsIII/`), logged in as the existing admin account
  (`fluffos`/`Mud@2026`), ran `wimpy` -> `Percentage: 20%`, a clean
  integer.
- **Bug #4 (`GiveMap()` reentrancy in `domains/town/npc/beggar.lpc`):
  PRESENT, fixed identically to `ds386`.** Added the same
  `!present("town map",ob)` delivery-time re-check inside `GiveMap()`
  that already existed at schedule-time in `init()`.

**Verified live end-to-end**: fresh boot compiled clean (zero new
errors in `log/debug.log`, only the same pre-existing benign warning
classes already catalogued), `say hello world` worked immediately with
no crash, and `wimpy` showed the fixed `20%`. Killed the test driver by
exact PID when done.

Source pattern for all four checks: `ds386/NOTES.md`'s "Deep
functional test (round two, 2026-08-27)" section.

## Sibling sweep: `become <class>` SetClass -> ChangeClass fix (2026-09-01)

Ported the fix from `riftsds` (AGENTS.md §7.195/§7.196; commit
`11216f003b1`) -- see `ds386/NOTES.md`'s identical write-up (same
session, same batch) for the full bug mechanism. Summary: the stock
Dead Souls "Praxis" demo guild-join rooms called `SetClass()` directly
instead of `ChangeClass()`, so the multi-class privilege gate
(`high_mortalp()`, which excludes creators too) always silently
rejected a fresh explorer's first class despite a success message
printing.

**Confirmed present here**, byte-identical to `ds386`/`riftsds`'s
pre-fix files: all six `domains/Praxis/*_join.lpc` files called
`SetClass()`; `secure/include/compat.h` was missing the same three
`query_name`/`query_cap_name`/`query_gender` mappings.

**Fix applied**: six `SetClass()` -> `ChangeClass()` edits, three
`compat.h` accessor lines added -- identical to `ds386`.

**Live-verified** with the seeded `fluffos` admin (`Class` reset to
`"explorer"` via `eval` between attempts, to force the exact
creator-excluded-from-`high_mortalp()` scenario the bug hits):
`become fighter`/`become cleric`/`become mage` all now print the real
success text and `score` confirms the genuine class change ("You are
a level 1 Human Fighter"/"Cleric"/"Mage"). `become monk`/`kataan`/
`rogue` do not work, but this is the identical pre-existing,
shared-lineage missing-class-data gap documented in `ds386/NOTES.md`
(`secure/cfg/classes/` here also only ships `explorer`/`fighter`/
`mage`/`cleric`/`thief` -- confirmed, same as `riftsds` and `ds386`),
not a regression or a miss in this fix.

Committed only the six join-file fixes and the three `compat.h`
mappings; incidental save-file churn from this session's boot (seeded
`fluffos` admin's `Class` field, player list, mudinfo, snoop, preload
saves, RELEASE_NOTES_HTTP refetch) was left uncommitted. Killed the
test driver by exact PID when done.
