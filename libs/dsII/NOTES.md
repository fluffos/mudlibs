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

## 10. Sibling sweep of the dsIII §7.121 currency-float bug — confirmed present, fixed

`AGENTS.md` §7.121 documents a currency/economy bug found in `dsIII`
(the Dead Souls 3.x lineage's shared `secure/sefun/economy.lpc`):
`query_base_rate()`, `query_player_money()`, `query_base_value()`, and
`query_value()` do real floating-point exchange-rate math internally
but are declared to return `int` with no `to_int()` on the actual
return, silently corrupting player currency into a float on every
buy/sell/exchange (a declared `int` return type is compile-time only
on this driver and never coerces a runtime float). This lib's own,
independently-evolved `secure/sefun/economy.lpc` has the identical
logic shape (same 4 functions, same missing `to_int()`s), plus the
same two sibling misses `dsIII` found: `lib/teller.lpc`'s
`eventExchange()` (`i = val / currency_rate(str2);`, with an earlier
correctly-`to_int()`-wrapped line even commented out right above it)
and `lib/props/value.lpc`'s `SetBaseCost()` (`Cost = i * rate;`).

Fixed by wrapping all four `secure/sefun/economy.lpc` returns in
`to_int()` (matching the convention already used by the file's own
`currency_mass()`/`currency_value()`), plus the two call sites, exactly
mirroring `dsIII`'s fix. Verified live: registered a fresh test
character (`Qintestdsb`), navigated from the campus starting area
(`LPC University Reception` -> corridor -> corridor3 -> foyer ->
University Square -> north path x2 -> South/main Saquivor Road) to the
First Village Bank, opened an account with Zoe and did `ask zoe to
exchange 20 silver for gold` — printed a clean `2 gold` with no
decimal, and the raw save file after `save` showed `Currency
(["silver":59,"gold":2,])` — both integers, no float. `log/debug.log`
stayed clean through the transaction.

## 11. Deep functional test (round two, per AGENTS.md §10.7)

One continuous session, `~/src/fluffos/build-debug/src/driver
config.fluffos` from `libs/dsII/`, a raw Python socket client (two
concurrent connections: a fresh non-admin character for the main
playthrough, plus the seeded admin for the safe-sparring/death test —
see §10.7's own `hy2000` precedent for why an admin-account death
sequence can be a false negative). Admin credential note: the
project-standard `fluffos`/`Mud@2026` login does NOT work on this
lib's seeded account — the working password is the one actually used
at onboarding (§6 above), `fluffwiz123`. Confirmed the account's own
password policy (`secure/lib/connect.real`'s `CreatePassword()`,
`strlen(pass) < 5`) would have accepted `Mud@2026` fine; this is
ordinary credential drift (same class as `xkm` in AGENTS.md's §7.7x
credential-drift sweep), not a bug — left the account as originally
seeded rather than resetting it.

**Registered a fresh English-named character** (`Ericlang`, human,
male) through the full flow: name → confirm → password → confirm →
gender → display name (default) → email → real name (blank) → `list`
→ `pick human`. Landed at `LPC University Reception` (`campus`
domain) with a starting t-shirt, jeans, and a Player's Handbook item.
`look`/`score`/`i` all correct after registration, after the first
`north` move (through a closed door — `open door` then `north` worked
correctly), and after `activate bot`/`next tip` (Jennybot's newbie
orientation script, plays cleanly).

**`help newbie` is broken** (pre-existing archive content gap, not a
porting bug — left unfixed): `cmds/players/newbie.lpc`'s `eventNoob()`
does `this_player()->eventPage("/doc/help/players/handbook")`, but
`doc/help/players/` is a genuinely **empty directory in the raw
archive itself** (`raw/dsII/lib/doc/help/players/`, dated Nov 2006,
confirmed via `ls` — not a conversion-sweep casualty). `eventPage()`
(`lib/pager.lpc`) correctly returns the string `"File not found."` on
a missing path, but the call site discards the return value (as does
nearly every other direct-path `eventPage()` caller across this
codebase, e.g. `realms/*/workroom.lpc`'s `/news/hints.txt` calls) —
consistent, codebase-wide convention, not a one-off typo. Net visible
effect: typing `help newbie` prints only the red
"WHAT A NEW PLAYER SHOULD KNOW" header and then silently does
nothing. The physical "Player's Handbook" item every new character
carries (`domains/default/obj/handbook.lpc`) is unaffected and works
correctly (`read index in handbook`, `read chapter N in handbook`).
Since fixing this would mean either writing the missing handbook
content (a content/design call, out of scope) or guessing at a
different intended source file, documented here rather than touched.

**Safe-sparring mechanism**: `domains/default/npc/dummy.lpc` /
`domains/campus/npc/dummy.lpc` — a `SetPacifist(1)`, 9000-HP "training
dummy" whose `eventReceiveDamage()` narrates the exact damage event
(agent/type/raw damage/limb) then immediately heals back the damage
just taken (`AddHealthPoints(damdiff+1)`), so it never dies and never
fights back. Lives in `/domains/default/room/arena` off the
Creators'-Hall-only `wiz_corr1` test-labs corridor — not reachable by
an ordinary player's normal overworld navigation (this is the
project's own admin/creator combat-testing fixture, same idea as
`bxsj`'s training dummy but gated behind wizard-only rooms here).
Tested live as admin `fluffos` (`goto /domains/default/room/arena`,
`kill dummy`): several rounds of real melee (`GetHealthClass`
proc-text varied naturally — "totally miss", "completely miss",
"swing... connect with thin air", one real hit landing "raw damage is
2... Actual damage done: 2"), the dummy's damage-report/self-heal
logic fired every single hit with zero errors in `log/errors/*` or
`log/runtime`. Confirmed clean.

**Class/skill acquisition**: only one class-join path exists in this
generation (no admin shortcut command found in
`secure/cmds/admins/admintool.lpc` or elsewhere) — the organic
`lib/leader.lpc` "ask LEADER to join" mechanism. Walked `Ericlang`
from campus reception to the town Mages' Guild (`corridor` → `west`
→ `north` → `north` → `north` → `north` → `west` → `south`) and did
`ask herkimer to join`: correctly quest-gated ("Help my brother Leo
find the Orcslayer..." — internally consistent content design, not a
bug, left alone). Spell purchase path (`lib/teacher.lpc`'s commercial
teaching, via `ask herkimer to teach buffer`) correctly reported
insufficient silver ("Buffer costs 200 silver and you only have
119") and correctly pointed at the bank for currency exchange — this
is the same `teach`/training-point/commercial-fee logic already
`§7.121`-fixed at onboarding; re-confirmed no float leakage anywhere
in this path either.

**Economy / currency-fix re-verification** (different test character
than the original §10 fix, confirms the fix generalizes): opened a
First Village Bank account (`request account from zoe`, auto-deposited
5 silver), then `ask zoe to exchange 20 silver for gold` → "You
exchange 20 silver for 2 gold" (clean integer). Raw save afterward:
`Currency (["silver":94,"gold":2,])` — both plain integers, no float,
matching the §10 fix.

**Combat + death/respawn (the subsystem sibling Dead-Souls-lineage
libs have broken before) — confirmed CLEAN.** Used `eval` on the
admin connection (`object p = find_player("ericlang");
p->eventDie(this_player());`) to force a real death with a genuine
living agent (avoiding a test-artifact false read from an
agent-less kill): "SYSTEM Fluffos has slain Ericlang", clean
`NewBody()`/corpse-drop/`ROOM_DEATH` move sequence, landed in the
single shared `/domains/default/room/death` room ("Off the mortal
coil... YOU ARE DEAD!"), inventory and carried currency correctly
transferred out (death drops your stuff — internally consistent
design, not a bug). `score` showed the expected "the ghost", "level 1
undead". Typing `regenerate` in the death room correctly called
`eventRevive()` + `eventMoveLiving(ROOM_START)`: rematerialized at
half max HP/MP/SP at `LPC University Reception`, `score` back to a
normal (non-ghost) state. Zero errors in any `log/errors/*` file or
`log/runtime` through the whole sequence — this generation's simple
"die → death room → type regenerate → revive at start" flow (no
NPC-driven `death_stage()` chain at all) has no reentrancy surface for
the §7.112-class bug to live in.

**`quit` → `debug.log` grep → reconnect after a real ~100s wall-clock
gap — confirmed clean.** `quit` produced the normal "Please come back
another time!" and a real connection close (not a silent/net-dead
retention skip — `secure/lib/connect.real`'s reconnect logic only
special-cases an actual net-dead `find_player()` hit, which a real
`quit` clears). Reconnecting after the gap required the full
name+password prompt sequence again (not a resumed session), and
landed back in the same room with the same (post-death, pre-quit)
character state: level 1, human, broke, at `LPC University
Reception`. No new entries in any per-directory `log/errors/*` file or
`log/runtime` from either the quit or the reconnect.

**Cross-cutting bug-pattern checklist (§7.121/§8.3a/§7.112/§7.122-
§7.140), checked explicitly, all confirmed clean or not applicable**:

- **§7.121** (float-returning `int` function): re-verified live above
  (already fixed at onboarding, §10) — still holds.
- **§8.3a** (`private` command-dispatch/callback/call_out-target
  function silently demoted once inherited): grepped every `private`
  function declaration in the tree (153 candidates) against every
  `add_action()`/`call_out()`/`input_to()` string-callback target
  found in the codebase (94 + 32 names respectively) — zero overlap.
  The one `private` function that IS also a `call_out()` target,
  `secure/lib/net/ftp.lpc`'s `idle_time_out()`, is safe: `ftp.lpc` is
  never inherited by anything (confirmed via a repo-wide grep for
  `inherit.*ftp`/`LIB_FTP`) and is never instantiated by any command
  or preload anywhere in the tree — genuinely dead/unreachable code,
  not a live bug. This lib's central dispatch (`lib/command.lpc`'s
  `add_action((: cmdAll :), "", 1)`) uses a bound closure, not a
  string, and `cmdAll` itself isn't `private` anyway — not exposed to
  this bug class at all.
- **§7.112** (NPC `init()` unconditional call_out chain, no
  re-entry guard): N/A — this generation's death flow (see above) has
  no NPC-driven `death_stage()`-style chain to begin with.
- **§7.122** (class-item duplication on disconnect/reconnect): no
  `compute_autoload_array()`/`destroy_autoload_obj()`-style autoload
  mechanism exists anywhere in this codebase.
- **§7.123** (bare file-scope `IDENT = (...)` killing compile): the
  full compile sweep (1401/1407 files, §6) already rules this out
  project-wide; not reintroduced.
- **§7.124** (fraction-vs-percentage threshold): no new candidate
  found; not specifically re-derivable via grep, left unconfirmed
  either way (no live symptom observed). **CORRECTION (2026-08-27,
  ds386 sibling sweep)**: this was wrong -- a direct grep of
  `lib/combat.lpc` (not run during the original pass above) found the
  identical `Wimpy = 0.20;` fraction-literal bug byte-for-byte, plus
  the same `float SetWimpy`/`float GetWimpy` mistyping, still present
  and live. Fixed: `Wimpy = 0.20;` -> `Wimpy = 20;`,
  `float SetWimpy(float wimpy)`/`float GetWimpy()` -> `int
  SetWimpy(int wimpy)`/`int GetWimpy()`. Verified live: booted, logged
  in as the seeded admin (`fluffos`/`fluffwiz123` -- see §11's own
  credential-drift note, NOT `Mud@2026`), ran `wimpy` ->
  `Percentage: 20%`, a clean integer.
- **§7.141** (MudOS-era `replace_program()` fold, sibling sweep off
  `ds386`'s round-two pass, added 2026-08-27): not checked in the
  original pass above (predates that AGENTS.md entry's own discovery
  on `dsI`). A direct check found `lib/std/room.lpc`'s `create()` has
  the identical fold (`replaceable(this_object()) && !GetNoReplace()`
  -> `inherit_list()` -> `replace_program(tmp[0])`), and the same
  file's `eventHearTalk()` builds real `filter()` closures over
  `all_inventory()` -- the exact unsafe combination. Fixed identically
  to `dsI`/`ds386`: removed the fold from `create()` entirely.
  Verified live: booted, and `say hello world` (as the logged-in admin)
  worked with zero crash at ~26 seconds post-boot -- squarely inside
  the ~5-minute window where this bug would otherwise have fired.
- **§7.126** (stale `.c` extension in `.o` save data): the §3.4 sweep
  already covered every filename-slice site at the source level; no
  live symptom seen (all door/exit loads during the playthrough
  resolved correctly).
- **§7.129** (`tell_room()` wrapper forwarding omitted `exclude` as
  literal `0`): `secure/sefun/communications.lpc`'s `tell_room()`
  dispatches through this codebase's own hand-rolled
  `eventPrint()` chain (`lib/std/room.lpc`), not the driver's native
  `message()` efun — and `eventPrint()` explicitly branches on
  `!arg3` before ever treating it as an exclude list. Confirmed clean
  by design, and live-exercised with zero errors during the death
  sequence's own `message()` calls (a different, correctly-typed call
  path).
- **§7.130** (unconditional liveness check post-non-interactive):
  no matching shape found in `net_dead()`/heartbeat code.
- **§7.131** (`find_living()`/`find_player()` needing
  `set_living_name()`): both `lib/interactive.lpc` (players) and
  `lib/npc.lpc` (NPCs) call `set_living_name()` correctly — and
  `find_player("ericlang")` was live-exercised successfully via `eval`
  during the death test above.
- **§7.132** (`map()`-over-mapping bound to the wrong argument):
  every `map(x, (: ... $1 ... :))` call site in the tree operates on
  an array-typed variable (checked the ones using the classic
  single-arg `$1` convention specifically, e.g. `lib/persist.lpc`'s
  `Saved` is `mixed *`), never a mapping. Not applicable.
- **§7.133** (disconnect-notification apply never defined): `net_dead()`
  is defined and chained correctly through
  `chat`/`interactive`/`player`/`creator`.
- **§7.134** (field defaulting to `0` instead of `({})`): no live
  symptom observed (no truncated room descriptions, no
  `member_array()`-type crashes) during the playthrough.
- **§7.135/§7.30** (accessor missing lazy-init): no live symptom
  observed.
- **§7.136** (setup step silently ungranted due to missing archive
  content): the closest match is the `help newbie` gap documented
  above, which is a help-text/doc gap, not a granted-verb/ability
  gap — players get full normal command access from character
  creation.
- **§7.139** (colour translation needs `"interactive catch tell"`):
  N/A by construction — this codebase's `write()` simul_efun
  (`secure/sefun/sefun.lpc`) routes everything through
  `message("my_action", str, this_player())`, and the driver's
  `message()` efun (`do_message()` in `vm/internal/simulate.cc`)
  always calls `receive_message()`/`eventPrint()` directly for
  interactive listeners regardless of that runtime-config flag —
  confirmed by reading the driver source, not just guessing from the
  mudlib side. `eventPrint()` (`lib/interface.lpc`) itself calls the
  `terminal_colour()` efun on the raw `%^TAG%^` markup before it ever
  reaches `receive()`/the socket. No literal `%^TAG%^` was seen
  anywhere in the whole live session (confirmed real ANSI escapes
  throughout).
- **§7.140** (compiler global-include attributed to the connected
  player): `secure/daemon/master.lpc`'s `valid_read()`/`check_access()`
  never calls `this_interactive()` at all (grepped, zero hits) — it
  resolves identity via `previous_object(-1)` (the real call stack),
  architecturally different from the `this_interactive()`-based bug
  this pattern describes. Not applicable.

**Overall: clean pass.** No new programming bugs found beyond the
one pre-existing content gap documented above (`help newbie`, left
unfixed per the content/programming scope boundary). The §7.121
currency fix re-verified live with a second, independent character.
Test characters `Ericlang`/`Testcarlin` (an aborted first registration
attempt merged into a real account mid-session — see the messy
gender-prompt retry in this session's own history) and three older
leftover test saves from the original §10 currency-fix session
(`Qintwo`/`Qintestdsb`/`Qintest`) were all deleted before commit,
leaving only the seeded `fluffos` admin account.

## Sibling-sweep check for ds386's round-two `eventRevive()` float bug (2026-08-27)

`ds386/NOTES.md`'s round-two pass found a NEW `AGENTS.md` §7.121-class
bug not covered by this lib's own earlier currency-float fix (§10
above): `eventRevive()` feeding float arithmetic (`GetMaxHealthPoints()
* PERCENT_HP`-style expressions) into `AddHealthPoints()`/
`AddMagicPoints()`'s `int` parameters. Checked this lib's own
`lib/player.lpc:eventRevive()` specifically for that shape: **not
present**. All three heal-back calls here (`AddMagicPoints`,
`AddStaminaPoints`, `AddHealthPoints`) use plain integer division
(`-(GetMaxMagicPoints()/2)` etc.) — no `PERCENT_MP`/`PERCENT_HP` float
`#define`s exist anywhere in this file. No fix needed; confirmed clean
by reading the code.
