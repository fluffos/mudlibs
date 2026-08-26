# Dead Souls II -- porting notes

Source: a 4,015,339-byte ZIP archive (`ds2.zip`) from mudbytes.net, a
now-dead site. Recovered via the Wayback Machine
(<https://web.archive.org/web/20190802021627id_/http://mudbytes.net/files/download/843/>),
re-verified live (HTTP 200, `application/zip`, real ZIP magic bytes,
size matching) at the start of this session before extracting. The
zip bundles `v22.2b14/` (a MudOS driver source snapshot), `bin/`,
`win32/`, `extra/` build/install scaffolding -- all ignored, this
project uses its own driver. The real mudlib root is the zip's `lib/`
directory. Slug `dsII`, number 181, port 40228.

## 1. Duplicate check -- genuinely distinct, not a duplicate

This collection already has three Dead Souls entries: `ds386` and
`deadsouls_fluffos` (both 3.8.6-era, confirmed identical codebase
generation to each other), and `dsI` (an early Nightmare-IV-era
snapshot, ~1996-98, self-identifying as "Dead Souls V"). Before
building out a full pipeline, checked whether this "Dead Souls II"
archive is a repackaging of any of the three:

- **Self-identification, unambiguous**: `README.txt` in the raw
  archive is titled "The Dead Souls Mud Library II / Released November
  2006" and is signed "- Cratylus @ Dead Souls". `lib/doc/RELEASE_NOTES`
  has a dated version history culminating in a `---- II ----` entry
  ("Released Dead Souls II into the public domain... Removed most
  ascii art... Removed LIB_SHOP... Removed stargate system... Removed
  commands: about, boards, dsversion, quell, unquell, arch, wiz...")
  preceded by `2.1.1`, `2.1`, `2.0r29` entries -- this is a real,
  self-contained release in its own right, not a copy of anything else
  in this collection.
- **Domain count**: `dsII/lib/domains/` has 4 domains (`campus`,
  `default`, `town`, `Ylsrim`) -- more than `dsI`'s 2 (`default`,
  `Ylsrim`), fewer than `ds386`/`deadsouls_fluffos`'s 8. 1937 files
  total, vs. dsI's 967 and ds386/deadsouls_fluffos's 4811/4813.
- **`secure/daemon/master.c` comparison**: 747 lines, close in size to
  `dsI`'s 749 (both carry the identical header comment "Version: @(#)
  master.c 1.7@(#) / Last modified: 96/12/14" -- both fork from the
  same historical base) but NOT byte-identical: a real `diff` shows
  1309 changed lines out of 747 total, including added global
  variables (`rlog`, `ParserDirs`) and a rewritten `load_access()`
  body -- a real, independently-evolved snapshot, not a re-save of
  `dsI`'s copy. Neither has any of `ds386`'s `COMPAT_MODE`/
  `DEFAULT_PARSING`/`RESET_ALL`/`MSSP`/`LIB_DAEMON`-inherit
  scaffolding (both `dsI` and `dsII` have exactly 5-7 top-level global
  vars vs. `ds386`'s 15+).
- **`lib/lib/` (component library) file-set diff**: `dsI` and `dsII`
  share most of the same ~65 top-level files (`body.c`, `combat.c`,
  `command.c`, etc.) but `dsII` adds ~15 new ones not present in `dsI`
  (`battery`, `blank_pile`, `bot`, `clan`, `clay`, `clerk`, `clip`,
  `flashlight`, `manycoins`, `money`, `pistol`, `round`, `shadow`,
  `shell`, `teacher`) and drops one (`guild`) -- consistent with a
  later, independently-developed snapshot of the same lineage, not the
  same content re-packaged.

This is consistent with `dsII` being a genuinely distinct, real
middle-generation release of the Dead Souls codebase -- historically,
the actual "II" release that came between the Nightmare-IV-derived
early snapshot (`dsI`, retroactively so named by this collection) and
the later, much larger 3.8.6 generation. Proceeded with the full
pipeline. `duplicate_of` is `null` in `meta.json`.

## 2. Conversion

English-language archive (public domain, from mudbytes.net) --
`scripts/convert_lib.sh` against `raw/dsII/lib` confirmed this:
1924/1937 files already valid UTF-8, only 2 lossy conversions, 11
binary files skipped. 531 `.c` files renamed to `.lpc`, 317 literal
`.c"` references fixed, 28 local angle-bracket `#include`s converted
to quotes, 1081 files touched by the `static`->`nosave` sweep.

### 2.1 Two source files were genuinely Latin-1, not GB18030

`secure/sefun/translate.lpc` and `secure/sefun/ascii.lpc` both lost
real content under the default GB18030 decode (bytes dropped as
invalid). Inspecting the raw bytes showed why:

- `translate.c`'s `FLUBS` array is a multilingual list of curse words
  used by a "drunk talk" word-scrambler, including several Finnish
  entries with literal Latin-1 `ä` bytes (`"kyrpä"`, `"räkä"`).
- `ascii.c` is a literal byte-value-to-string lookup table (`case 128:
  ret = "\x80"; break;` ... `case 254: ret = "\xfe"; break;`, one case
  per byte value 0-255) -- inherently defined in terms of raw Latin-1
  byte identity, not any multi-byte encoding.

Re-decoded both files individually with `iconv -f ISO-8859-1 -t
UTF-8` (verified line counts match the raw originals exactly, and the
resulting UTF-8 is valid) rather than re-running the whole-lib
conversion with a different global encoding, since every other file in
the archive was correctly GB18030/ASCII.

## 3. Compile-time driver-compat fixes

### 3.1 Missing `get_root_uid()`/`get_bb_uid()`/`creator_file()` master applies

Same `PACKAGE_UIDS` requirement as `dsI`/`foundation2`/`merentha`/
`lpuni` -- this driver build calls `exit(-1)` at boot without these.
Added to `secure/daemon/master.lpc`, byte-identical implementation to
`dsI`'s fix (which itself reuses this codebase's own
`secure/sefun/security.lpc:file_privs()` classification, with the same
`sscanf(str, "%s#%d", base, ext) != 2 -> base = str` clone-suffix guard
needed to avoid passing an unmatched-`%s`'s int-0 default into
`file_privs()`'s string indexing).

### 3.2 `ref` is a reserved keyword on this driver

Same bug class as `dsI`/`foundation2`/`nightmare3`. Here it hit
**both** `secure/daemon/master.h`'s `load_access()` prototype *and* the
real implementation's parameter name in `master.lpc` itself (dsI's
copy only had the header-side collision; this codebase's `master.lpc`
uses `mapping ref` directly in the function body too, including
`ref[fl] = ...` inside). Renamed to `refmap` in both files.

### 3.3 Old-MudOS `TYPE array NAME` declaration dialect (432 sites)

Same bug class as `dsI` (370+ sites there). Wrote a small Python
tokenizer-based fixer (handles the same shapes dsI's session
documented: single names, `= default` values with balanced-paren
tracking, multi-name comma lists correctly distinguished from function
parameter lists by peeking whether the token after a comma is itself a
type keyword, `(TYPE array)` cast forms, `class TYPENAME array NAME`,
and a bare `array` used alone as a type). **Caught and fixed one real
bug in the first draft of the fixer itself before trusting it on the
whole tree**: the multi-name-list parser advanced past trailing
whitespace even when a name wasn't followed by a comma (i.e. when the
declaration ended in something other than `;`), which silently
concatenated the declared name with the next token when there was no
punctuation between them -- e.g. `foreach(string array list in ua)`
became `foreach(string *listin ua)` (`in` swallowed into the
identifier). Fixed by only consuming trailing whitespace when a comma
is actually consumed; re-ran clean afterward and spot-checked every
`foreach(string *list in ...)` site by hand.

**432 sites across 130 files** via the main sweep, plus 1 more found
only via `lpcc --batch` actually loading `secure/sefun/dump_socket_status.lpc`
(`foreach (array item in socket_status())` -- the exact recurring
"`dump_socket_status`-in-simul_efun" pattern flagged in `dsI`'s own
WASM notes as common across sibling libs; fixed to
`foreach (mixed *item in socket_status())`), 1 more in
`lib/std/bane.lpc`'s `int SetBane(array arr)` parameter (fixed to
`mixed *arr`), and 2 more in `secure/cmds/admins/admintool.lpc`
(`array *classes;` / `array *races;` -- a MudOS-dialect variant this
codebase happened to write with the pointer star already present;
fixed to `mixed *`), plus 3 more found only in `secure/lib/connect.real`
once it became live (see \S4 below) -- 439 total.

### 3.4 `.c`-to-`.lpc` rename side effect: fixed-width filename-slice arithmetic

Same bug class as `dsI`/`discworld`/`foundation2`/`skylib`/`lpuni`.
Checked every slice-comparison-against-a-literal-suffix pattern in the
tree:

- **`daemon/command.lpc`'s `eventRehash()`** -- the command-dispatch
  table builder itself: `cmd = file[0..<3]` turned `"look.lpc"` into
  `"look.l"` -- **the single highest-impact bug in `dsI`'s port, and
  present here byte-for-byte identically.** Fixed to `file[0..<5]`.
- **Unconditional strip-2 via `map()`**: `lib/detect.lpc` (2 sites,
  detect-magic spell-name guessing), `daemon/verbs.lpc` (1 site,
  synonym-list extraction), `daemon/help.lpc` (3 sites: the anonymous
  index-stripper function and 2 inline `map()`s).
- **`[<2..] == ".lpc"` (always false -- comparing the last 2 characters
  against a 4-character literal) guarding a `[0..<3]` strip**:
  `lib/enter.lpc`/`lib/exits.lpc` (identical `ResolveObjectName()`
  helper duplicated in both), `lib/props/inventory.lpc`
  (`SetInventory()`), `daemon/verbs.lpc` (`eventReloadVerbs()`'s
  string-arg branch), `daemon/help.lpc` (topic normalization),
  `secure/cmds/creators/update.lpc` (`eventUpdate()`'s own `.lpc`-strip
  before `find_object()`/`load_object()`), `cmds/creators/showtree.lpc`.
- **`[<2..] != ".lpc"` (always true) guarding a `.lpc`-append (the
  inverse bug)**: `secure/cmds/creators/update.lpc` (a second, earlier
  site: `tmpfiles = map(..., function(string x) { ... x = x +
  ".lpc" ...})`), `secure/sefun/to_object.lpc`, `cmds/creators/clone.lpc`.

All fixed to the 4-character-aware form (`[0..<5]` / `[<4..]`).
Verified live: `update <path>` (both with and without an explicit
`.lpc` suffix) correctly reports `Ok`/`File not found`.

### 3.5 `secure/cmds/creators/update.lpc`: stray leading space (same bug as dsI)

`cmd()`'s argument-reconstruction loop (`default: args += " " + foo;`
for every surviving non-flag token) always left a stray leading space,
which made the downstream `explode(args, " ")` produce a spurious
leading empty-string entry -- `update <path>` with an explicit
filename argument would have produced no output at all. Fixed with
`args = trim(args)` after the loop, byte-identical fix to `dsI`'s.

### 3.6 `OLD_ED`: driver build vs. archive's new-style ed API

Same gap as `dsI`/`foundation2`/`finalrealms`: this driver build
defines `OLD_ED`, but `lib/editor.lpc` and
`secure/cmds/creators/lsed.lpc` were written against the newer
`ed_start()`/`ed_cmd()`/`query_ed_mode()` API. Fixed identically to
`dsI`:

- Added `secure/sefun/ed_compat.lpc` (byte-identical to `dsI`'s),
  approximating `query_ed_mode()` via `in_edit(this_object())`.
- Rewrote `lib/editor.lpc`'s `eventEdit()` to call the old `ed(file,
  "__ed_exit_dispatch", !creatorp())` directly, with a new
  `__ed_exit_dispatch()` callback replacing the old
  `process_input()`-based loop.
- `secure/cmds/creators/lsed.lpc`'s `LsedFile()` (scripted,
  non-interactive batch editor) has no OLD_ED equivalent at all --
  left as a graceful "not supported on this driver build" message,
  same as `dsI`.

### 3.7 Missing `#include <virtual.h>` in `lib/virtual/virt_sky.lpc`

`inherit LIB_VIRT_LAND;` with `LIB_VIRT_LAND` genuinely defined (in
`secure/include/virtual.h`) but never `#include`d by this one file --
the other 3 files in the tree that reference `LIB_VIRT_LAND`/
`LIB_VIRT_MAP` all correctly `#include <virtual.h>`. This is a one-off
omission, not a systemic `lib.h` gap like `dsI`'s `LIB_UNDEAD`/
`LIB_GERM` (every other `LIB_*` macro this codebase references --
checked exhaustively against every header in the tree -- is defined
somewhere and reachable). Fixed by adding the missing `#include`.

### 3.8 `#define __DIR__ "..."` collides with this driver's native builtin

4 files (`domains/town/virtual/{forest,server}.lpc`,
`domains/Ylsrim/virtual/{desert,server}.lpc`) manually
`#define __DIR__` to a hardcoded string matching their own directory
-- a common old-MudOS idiom predating driver-native `__DIR__` support.
This driver's compiler now predefines `__DIR__` natively (directory of
the current file, with trailing slash -- confirmed by reading
`lexer_rules_pp.cc`: exactly the same value these files were
hardcoding), and rejects any attempt to `#define` it ("Illegal to
redefine a predefined value."). Removed the four redundant
`#define`s; the native builtin produces an identical value.

### 3.9 Two broken `#include`s (unrelated one-off path bugs)

- **`domains/{campus,Ylsrim}/adm/cache.lpc`**: `#include <room.h>` --
  but `lib/include/room.h` (a pure forward-declaration header for
  `LIB_ROOM`'s methods) lives outside the configured include path
  (`/secure/include:/include`) and outside these files' own directory,
  so it can never resolve on this driver ("Cannot #include room.h").
  Both files already `inherit LIB_ROOM;`, which provides real,
  already-known signatures for everything the header would have
  forward-declared -- the broken include was simply redundant. Removed
  it (kept the working `#include <rooms.h>` for the `ROOM_START`
  constant these files also need and were separately missing).
- **`obj/area_room.lpc`**: `#include "../../customdefs.h"` -- this file
  is a copy-source *template* that `secure/modules/room.lpc`'s
  room-building tool `cp()`'s to a user-chosen destination (unlike its
  sibling `realms/template/area/room/sample_room.lpc`, whose identical
  `"../../customdefs.h"` is correct relative to *that* file's own fixed
  location). From `/obj/`, the relative path never resolves. Since this
  file's body never actually references any of `customdefs.h`'s `MY_*`
  macros (unlike `sample_room.lpc`, which genuinely needs them),
  dropped the include entirely rather than trying to repoint a path
  that has no single correct destination-independent answer.

### 3.10 `SetLong`/`SetExternalDesc`/`SetInternalDesc` declared too narrowly (severe -- 11+18 sites)

`lib/events/look.lpc`'s `GetExternalDesc()` and
`lib/events/look_in.lpc`'s `GetInternalDesc()` both already support
function-valued and array-valued "long description" callbacks (see
their `functionp()`/`arrayp()` branches -- day/night-variant and
dynamic-description objects are a real, widely-used feature of this
codebase: 17 real objects across `obj/` and `domains/*` call
`SetLong((: SomeFunction :))`). But the *setter* side --
`SetLong(string str)`, `SetExternalDesc(string desc)`,
`SetInternalDesc(string str)`, plus forward declarations in
`lib/include/room.h` and `lib/include/interactive.h` -- were all
declared `string`-only. This driver's stricter argument type-checking
rejected every one of those 17 real call sites (18 total compile
failures counting one indirect path), the single most numerous
compile-failure category after \S3.11 below. Widened all of them to
`mixed`/`mixed *` to match what the getter side already supported --
not a new feature, just correcting a too-narrow declared type that
happened to never matter on a looser-checking driver.

### 3.11 `lib/comp/seal.lpc`'s `eventOpen()` called `eventPick()` with the wrong argument (severe -- ~195 files, the single highest-impact fix in this port)

`eventPick()` is declared `varargs mixed eventPick(object who, string
id, object tool)` (`lib/events/lock.lpc`) -- the 2nd positional
argument is always the lock id (a string), with `tool` 3rd and
optional; every other real caller in the codebase (e.g.
`verbs/items/pick.lpc`) follows this correctly. But
`lib/comp/seal.lpc`'s `eventOpen(object who, object tool)` called
`eventPick(who, tool)` -- passing `tool` (an object) positionally as
`id` (a string), a genuine original-archive bug. This driver's
argument type-checking caught it as "Bad type for argument 2 of
eventPick ( string vs object )" -- and since `lib/comp/seal.lpc` (the
LIB_CLOSE+LIB_LOCK "seal" composite) is inherited transitively by
`lib/std/storage.lpc` and therefore by essentially every closeable,
lockable container/door/chest in the mudlib, this single bug broke
**195 of the 232 total compile failures** found in the first full
sweep. Fixed by passing an explicit unset `id` (`0`) and moving `tool`
to its real 3rd position: `eventPick(who, 0, tool)`.

## 4. `secure/lib/connect.real`: the same by-hand treatment `dsI` needed

Same situation as `dsI`'s `connect.real`/`foundation2`'s
`login.real`: `secure/lib/connect.real` is the mudlib's real,
**ongoing** login/registration object -- `secure/lib/connect.lpc` (the
one-time first-boot admin-installer) `cp()`'s the just-consumed
installer into `connect.first` and swaps `connect.real` into
`connect.lpc`'s place once the first account finishes registering.
Because it's shipped without a `.c` extension, the mechanical
conversion sweep skips it entirely. Needed, by hand:

- The `static`->`nosave` sweep (32 sites).
- The `TYPE array NAME` dialect fix (3 sites, all `(string array)`
  cast-form calls to `RACES_D->GetRaces(1)` inside the installer's own
  race-selection `cmdList()`/`cmdHelp()` commands -- this archive's
  admin installer, unlike `dsI`'s otherwise-similar flow, genuinely
  does include a race-selection step for the very first account too).

No slice-arithmetic or literal `.c"` issues in this file. Verified
live end-to-end (see \S6).

## 5. `secure/cfg/groups.cfg` / `secure/include/config.h`: broken placeholder scrubbing (pre-existing archive bug, present on any driver)

`secure/lib/connect.real`'s `InputEmail()` (the installer's final
step) tries to promote the newly-created admin into the `SECURE`/
`ASSIST`/`ELDER`/`TEST`/`INTERMUD` groups and the debug-name config by
doing a literal text substitution: `replace_string(read_file(CFG_GROUPS),
"ADMIN", Name)` and `replace_string(read_file(".../config.h"),
"DEBUG_NAME", Name)`. But the archive as shipped by mudbytes.net
already has the *original author's own name* hardcoded in both
places (`secure/cfg/groups.cfg`: `(SECURE) cratylus` etc.;
`secure/include/config.h`: `#define DEBUGGER "cratylus"`) rather than
the `ADMIN`/`DEBUG_NAME` placeholder tokens the installer code is
actually searching for -- so both `replace_string()` calls are
silent no-ops on this exact shipped copy, on any driver. Confirmed
live: after running the installer as `fluffos`, the admin's save file
correctly landed under `secure/save/creators/f/fluffos.o` and
`ADMIN_EMAIL` (a *separate*, working mechanism via
`admintool.lpc`'s `eventChangeEmail()`) correctly updated -- but
`groups.cfg` and `DEBUGGER` still said `cratylus`, meaning the new
admin would have had **no real group membership at all** despite
going through the installer successfully.

Fixed by hand-editing both files to replace `cratylus` with `fluffos`,
completing what the installer's own code already intended to do.
Verified live afterward: `who` shows `Arch: First Admin Fluffos`, and
`update` (both with no argument and none needed for a re-test) reports
`Ok`.

## 6. Live verification

Booted clean (`Accepting telnet connections on 0.0.0.0:40228.`), with
a confirmed real outbound Intermud-3 connection (`ss -tnp` showed an
ESTABLISHED connection to `149.152.218.102:23` a few seconds after
boot -- **do not sweep this lib into high-frequency automated re-boot
loops**, same caveat as `dsI`/`imud`/`foundation2`).

Tested with a raw Python socket client, both required flows:

1. **First-boot admin installation wizard**: `fluffos` /
   `fluffwiz123` / male / default display name / blank real name /
   `fluffos@example.com` -- completed successfully, the mud
   self-shut-down as designed (`connect.real`'s own `shutdown()` +
   `destruct(master())` -- this codebase's installer, unlike `dsI`'s,
   requires a full driver restart before the new admin can actually
   log in and play). Restarted the driver, logged in as `fluffos`:
   arrived in `/realms/fluffos/workroom` with wizard robe+hat, all
   three news tiers (general/creator/admin) paged correctly, `who`
   showed `Arch: First Admin Fluffos`, `update` (current-room form)
   reported `Ok`, `look`/`score`/`quit` all produced correct output.
2. **Ordinary new-player registration** (a second character,
   `Qintwo`): full flow -- name, confirm, password, confirm password,
   gender, display name (default), email, real name (blank), `list`
   (see races: halfling/elf/orc/half-orc/human/half-elf/dwarf),
   `pick human` -- landed in `LPC University Reception` (the `campus`
   domain's starting area), with a live NPC greeting
   ("Jennybot ... I'm Jenny, the LPC University automated guide bot").
   `look`/`score`/`quit` all produced correct output (`score`:
   "You are Qintwo the unaccomplished (neutral). You are a level 1
   Human Explorer...").

1401 of 1407 `.lpc` files pass a full `lpcc_check.sh` batch compile
sweep (99.6%); the 6 that don't are all non-preloaded, pre-existing
content gaps (see \S7).

## 7. Known pre-existing gaps (not fixed -- content/archive design, not driver-compat)

- **`domains/Ylsrim/room/tower.lpc`**: `SetInventory()` references
  `/domains/Ylsrim/obj/stargate`, which doesn't exist anywhere in this
  archive -- consistent with `lib/doc/RELEASE_NOTES`' own "II" entry
  explicitly stating "Removed stargate system." A leftover reference
  to deliberately-removed content, not a porting bug.
- **`domains/campus/room/conf2.lpc`**: `SetInventory()` references
  `/domains/campus/obj/podium`, which was never shipped anywhere in
  this archive (searched the whole raw tree). A genuine missing-content
  gap, not a rename/path issue.
- **`domains/Ylsrim/broken/jar.lpc`**: `inherit LIB_CAPTURE;`, but
  `lib/capture.lpc` (the target) doesn't exist -- the same gap `dsI`
  documented for its own copy of this exact example object (a
  "capture a creature in a container" component library never shipped
  in either generation).
- **`secure/daemon/remote.lpc`**: same "from the Foundation II LPC
  Library" foreign-codebase file `dsI` found -- its
  `eventWrite(int fd, ...)` raw-file-descriptor API doesn't match this
  archive's own `LIB_SERVER` (`object owner, mixed val, int close`)
  signature. Already commented out of `secure/cfg/preload.cfg` in the
  shipped archive. Left undone, same as `dsI`.
- **`secure/tmp/cratylus_CMD_EVAL_TMP_FILE.lpc`**: a wizard's
  interactive-`eval`-command scratch file, calling an undefined
  `reverse_stringy()` (evidently a typo/experiment by the original
  author, Cratylus, mid-development) -- the same class of found
  evidence of debug scratch as `dsI`'s `daemon/tmp/A_WEARON.lpc`. Left
  as-is.
- **`secure/cmds/admins/opcprof.lpc`**: calls the `opcprof()` efun,
  which doesn't exist at all in this driver build (0 matches in driver
  source -- an old MudOS opcode-profiling efun this build never
  compiled in). A creator-only admin diagnostic, not on the core
  player/creator verification path. Left undone.

## 8. Skipped/no-fix bug-class checks that turned up nothing

- **`add_action()` bare-function-value vs. `NO_ADD_ACTION`**: this
  driver supports native `add_action()` and this codebase uses it
  normally (both string-name and closure-value forms, e.g.
  `lib/bboard.lpc`'s string form and `lib/command.lpc`'s closure form)
  -- not the `skylib`-class bug.
- **`explode()` on `SANE_EXPLODE_STRING` edge cases**: no
  `tmi2`-class call sites found.
- **Bundled `runtime_config.h` stale indexing**: not present as a
  distinct bundled file issue here (this codebase reads
  `secure/include/config.h`, a real config header, not a
  driver-`runtime_config.h`-mirroring one).
- **Hardcoded ports / `efun::` overrides**: none found.

## 9. WASM pass

Not yet attempted this session (`wasm_status` left `""`).
