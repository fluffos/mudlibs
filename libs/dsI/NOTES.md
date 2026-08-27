# Dead Souls I -- porting notes

Source: `dsI.zip`, a maintained, already-FluffOS-adapted archive from
lpmuds.net (a now-defunct LPMud archive site). The live site is down;
this exact archive was recovered from the Wayback Machine
(<https://web.archive.org/web/20160306035507id_/http://lpmuds.net/files/deadsouls/dsI.zip>)
and content-verified (valid zip, intact central directory, 1673 files,
non-corrupted) before this session started. Slug `dsI`, number 178,
port 40225. The zip bundles a FluffOS 2.7-ds2.018 driver source
snapshot (`fluffos-2.7-ds2.018/`), plus `bin/`, `win32/`, `extra/`,
`v22.2b14/` build/install scaffolding -- all ignored, this project
uses its own driver. The real mudlib root is the zip's `lib/`
directory.

## 1. Duplicate check -- genuinely distinct, not a duplicate

This collection already has two Dead Souls 3.8.6-era copies, `ds386`
and `deadsouls_fluffos`. Before building out a full pipeline, checked
whether `dsI` is a third copy of the same codebase:

- **Domain count**: `dsI/lib/domains/` has only 2 domains (`default`,
  `Ylsrim`); both `ds386` and `deadsouls_fluffos` have 8 (`amigara`,
  `campus`, `cave`, `default`, `examples`, `learning`, `Praxis`,
  `town`, `Ylsrim`).
- **Top-level directory set**: `dsI/lib/` is missing `estates/`,
  `open/`, `powers/`, and `std/` entirely (present in both other
  copies) -- 967 files total vs. 4811/4813.
- **`secure/daemon/master.lpc` byte diff**: `dsI`'s copy is 711 lines;
  `ds386`/`deadsouls_fluffos`'s is ~1180-1200 lines. A real `diff`
  shows completely different structure from the first non-comment
  line on -- different include set (`<config.h>`/`<rooms.h>` vs.
  `<runtime_config.h>`/`ROOMS_H`), no `COMPAT_MODE`/`DEFAULT_PARSING`/
  `RESET_ALL` feature-flag scaffolding, no `LIB_DAEMON` inherit, a
  much smaller global-variable set (5 vars vs. 15+), no MSSP support.
- **Self-identification**: several files in this archive carry "Dead
  Souls V" or "Dead Soulsr1/r2 Object Library" header comments (vs.
  `ds386`'s explicit 3.8.6-era file headers), and lpmuds.net's own
  site description places this snapshot as closer to Nightmare IV than
  to the modern Dead Souls lineage.

All of this is consistent with `dsI` being a genuinely earlier,
distinct generation of the Dead Souls codebase, not a re-packaging of
the same one -- proceeded with the full pipeline. `duplicate_of` is
`null` in `meta.json`.

## 2. Conversion

English-language archive (not GBK-encoded) -- `scripts/convert_lib.sh`
against `raw/dsI/lib` confirmed this: 966/967 files already valid
UTF-8, 0 lossy conversions, 1 binary file skipped. 583 `.c` files
renamed to `.lpc`, 127 literal `.c"` references fixed, 26 local
angle-bracket `#include`s converted to quotes, 511 files touched by
the `static`->`nosave` sweep.

**One file needed the same by-hand treatment as `foundation2`'s
`login.real`**: `secure/lib/connect.real` is not `.c`/`.lpc` (skipped
by the mechanical sweep) but is real, live LPC source -- the one-time
first-boot admin-installation wizard (`secure/lib/connect.lpc`, \S5
below) `rename()`s it over `connect.lpc` itself once the first account
finishes registering, and it becomes the mud's real ongoing login
handler from then on. It needed **both** the `static`->`nosave` sweep
(31 sites) **and** the `TYPE array NAME`->`TYPE *NAME` dialect fix
(\S3 below, 1 site: `string array races = (string array)RACES_D->
GetRaces(1);`) applied by hand, since the mechanical sweeps both key
off file extension. Caught live: a second test account's login crashed
the connection outright with a bare "*No program in object
'/secure/lib/connect'!" once the installer had already consumed
`connect.real` and swapped it into place -- confirmed via
`log/catch`/`log/runtime`, fixed, verified with a fresh driver boot
and a full second registration.

## 3. Compile-time driver-compat fixes

### 3.1 `ref` is a reserved keyword on this driver

Same bug class as `foundation2`/`nightmare3` (§7 catalog item). Only
1 site: `secure/daemon/master.h`'s `load_access()` prototype used
`mapping ref` as an (unnamed-in-effect) parameter type/name; renamed to
`refmap` to match the actual implementation's parameter name in
`master.lpc` (which was already correctly named `resource`, not
`ref` -- only the header prototype had the reserved-word collision).

### 3.2 `LIB_UNDEAD` gated behind a garbled, always-false `#ifdef`

**The single highest-impact fix in this port.** `secure/include/
lib.h` had:

```c
#ifdef Dead SoulsLPMud
#define LIB_UNDEAD         DIR_LIB        "/undead"
#endif
```

`Dead SoulsLPMud` is not a real, definable macro name (and `Dead` is
never `#define`d anywhere in this codebase) -- the `#ifdef` always
evaluated false, silently leaving `LIB_UNDEAD` undefined. Every other
`LIB_*` macro in this header is defined unconditionally; there's no
evidence this one was ever meant to be conditional. `inherit
LIB_UNDEAD;` in `lib/body.lpc` then failed with a hard "syntax error,
unexpected L_IDENTIFIER, expecting L_STRING or '('" (the driver
left the bare, unexpanded identifier where a string was expected) --
and since `lib/body.lpc` is the base of this codebase's entire
living-creature class hierarchy (`body` -> `race` -> `living` ->
`npc`/`sentient`, plus `combat`, `leader`, `mayor`, `teller`,
`trainer`, `std/barkeep`, `std/vendor`, `obj/friend`, and every NPC in
`domains/Ylsrim/`), this one bug transitively broke ~25 files across
the codebase. Fixed by defining `LIB_UNDEAD` unconditionally, matching
every sibling macro's convention.

### 3.3 Missing `LIB_*` macros (3 more, same root cause as 3.2)

Three more `LIB_*` macros referenced by `inherit`/`new()` calls were
simply never defined in `secure/include/lib.h` at all (their target
`.lpc` files do exist -- this is a header-omission bug, not a missing-
content one):

- `LIB_GERM` -> `DIR_STD "/germ"` (target: `lib/std/germ.lpc`; used by
  `domains/Ylsrim/broken/{cold,flu}.lpc`, both disease-item examples).
  First guessed `DIR_LIB "/germ"` (matching most sibling macros'
  pattern), which compiled but failed at *load* time with "Inherited
  file '/lib/germ' does not exist!" (caught via `log/runtime`, not a
  compile error) -- the actual file lives under `lib/std/`, not `lib/`
  directly, so the value needed `DIR_STD` instead.
- `LIB_VIRT_LAND` -> `DIR_LIB "/virtual/virt_land"` (target: `lib/
  virtual/virt_land.lpc`; used by `lib/virtual/virt_sky.lpc`).
- `LIB_FTP_CLIENT` -> `DIR_SECURE_LIB "/net/ftp_client"` (target:
  `secure/lib/net/ftp_client.lpc`; used by `secure/lib/net/ftp.lpc`).

### 3.4 Old-MudOS `TYPE array NAME` declaration dialect (370+ sites)

FluffOS's grammar does natively support `TYPE array NAME` as a
type-modifier synonym for `TYPE *NAME` (`opt_atomic_type L_ARRAY` in
`grammar.y`, confirmed by reading the compiler source before assuming
this was a bug) -- **but not in every grammatical position.** A
function *return-type* declaration using it hits a hard parser error:

```c
string array explode_list(string list) { ... }
// error: syntax error, unexpected L_IDENTIFIER, expecting L_ASSIGN or ';' or '(' or ','
```

Rather than characterize exactly which of the many possible contexts
(top-level function return type, local-variable declaration, function
parameter, multi-name declaration list, cast expression, `class NAME
array` variant) are safe vs. broken, every instance was converted
uniformly to the `TYPE *NAME` form via a small Python script (handles
single names, names with `= initializer` default values including
nested-paren/comma expressions like `allocate(3)` or `({ 0, 0 })`, and
multi-name comma-separated declaration lists like `private string
array Classes, Religion, Deities, DeityIds;` -> `private string
*Classes, *Religion, *Deities, *DeityIds;`, fanning `*` out to every
name in the list). Also handled separately: `(TYPE array)` cast
expressions -> `(TYPE *)` (12 sites, a different regex since there's
no trailing identifier), `class TYPENAME array NAME` (2 sites, e.g.
`class MagicProtection array GetMagicProtection()` -- the base-type
detector only matched bare keywords like `string`/`int`, not `class
<Identifier>`), and one bare `array` used alone with no type prefix at
all (`private nosave array History;` in `lib/history.lpc` -> `private
nosave mixed *History;`).

**370 sites across 107 files** via the main sweep, **12 more** via the
cast-form sweep, **2 more** via the `class TYPENAME array` fix, **1
more** for the bare-`array` case, plus **1 more found only later**
in `secure/lib/connect.real` once it became live (\S2 above) -- 386
total. Every file recompiled clean afterward; spot-checked a sample
against the pre-fix/post-fix diff by hand (`lib/chapel.lpc`, `lib/
magic.lpc`, `lib/race.lpc`, `verbs/items/wield.lpc`, `daemon/help.lpc`)
to confirm the comma-list fan-out and default-value paren-tracking
worked correctly before trusting the full sweep.

### 3.5 `.c`-to-`.lpc` rename side effect: fixed-width filename-slice
arithmetic (16 sites, including the command-dispatch table itself)

Same bug class as `discworld`/`foundation2`/`skylib`/`lpuni` -- code
written to strip/check a 2-character `.c` extension via `file[0..<3]`
(drop last 2 chars) or compare `file[<2..] == ".c"` (last 2 chars)
silently breaks once every file is 2 characters longer (`.lpc`).
Checked **every** slice-comparison-against-a-literal-suffix pattern in
the tree, not just the common one, and found instances in both
directions (stripping *and* appending):

- **`daemon/command.lpc`'s `eventRehash()`** -- the command-dispatch
  table builder itself: `cmd = file[0..<3]` (built from `get_dir(path
  + "/*.lpc")` results) turned `"look.lpc"` into `"look.l"` instead of
  `"look"`, meaning **every ordinary player/creator/admin command
  would have silently stopped matching typed input** had this shipped
  unfixed -- caught by `lpcc`'s own strict compile of files depending
  on this return value being used consistently elsewhere, and by
  reasoning through the bug class from the `foundation2`/`discworld`
  precedent before it could bite at runtime. Fixed to `file[0..<5]`.
- **Extension-stripping via `map()`**: `daemon/help.lpc` (4 sites:
  `LoadIndices()`'s anonymous stripper function plus 2 inline
  `map()`s, `GetHelpByIndex()`'s topic-normalization check),
  `daemon/verbs.lpc` (2 sites: `eventReloadVerbs()`'s string-arg
  branch and its verb-name extraction from a bare filename),
  `lib/detect.lpc` (2 sites, both in the "detect magic" skill's
  spell-name guessing, see \S4 below for a related runtime crash
  fixed in the same code), `lib/enter.lpc`/`lib/exits.lpc`
  (`ResolveObjectName()`, identical helper duplicated in both files),
  `lib/props/inventory.lpc` (`SetInventory()`), `secure/cmds/
  creators/update.lpc` (`cmd()`'s own `.lpc`-suffix strip), `cmds/
  creators/showtree.lpc`.
- **Extension-*appending* (the inverse bug)**: `x[<2..] != ".lpc"`
  (last-2-chars compared against a 4-char literal, always true) meant
  `.lpc` got appended even when a user already typed it, producing
  `foo.lpc.lpc` -- `secure/cmds/creators/update.lpc` (a second,
  different site from the one above), `secure/cmds/creators/
  create.lpc`, `secure/sefun/to_object.lpc`, `cmds/creators/
  clone.lpc`.

All fixed to the 4-character-aware form (`[0..<5]` / `[<4..]`).
Verified live: `update <path>` (both with and without an explicit
`.lpc` suffix) correctly reports `Ok`/`File not found` rather than
silently matching nothing.

### 3.6 `runtime_config.h`: bundled copy is stale but harmless here

The bundled `secure/include/runtime_config.h` has drifted from this
driver's actual `get_config()` index numbering in several slots
(confirmed by diffing against `~/src/fluffos/src/include/
runtime_config.h`: index 1 is `__ADDR_SERVER_IP__` here vs. a retired
slot on the real driver, index 9 is `__MAX_LOCAL_VARIABLES__` here vs.
retired, etc.) -- the skylib-class bug from the catalog. **Checked and
confirmed harmless for this archive specifically**: the only
`get_config()` calls anywhere in the tree (`secure/lib/net/{ftp,
server}.lpc`, `secure/lib/file.lpc`) use exactly `__MAX_BYTE_TRANSFER__`
(index 16) and `__MAX_READ_FILE_SIZE__` (index 17), and those two
specific macro names/values are identical between the bundled header
and the real driver's -- the drifted slots are simply never read. Not
touched, to avoid an unnecessary risk of introducing a *new* mismatch.

### 3.7 `OLD_ED`: driver build vs. archive's new-style ed API

This project's driver build defines `OLD_ED` (`#define OLD_ED` in
`src/local_options`), which compiles out `ed_start()`/`ed_cmd()`/
`query_ed_mode()` (`core.spec`'s `#else` branch) and leaves only the
older single-efun `ed(fname, exitfn, restricted)` form -- but this
archive's `lib/editor.lpc` and `secure/cmds/creators/lsed.lpc` were
written against the newer API (same gap as `foundation2`/
`finalrealms`, opposite direction from what the AGENTS.md catalog item
literally describes, which assumes the archive itself predates the
new API -- here the archive is *newer* than this driver's build
config).

- **`query_ed_mode()`**: added a `secure/sefun/ed_compat.lpc` simul_efun
  shim (byte-identical fix to `foundation2`'s), approximating it via
  `in_edit(this_object())` (available under `OLD_ED`): returns 0 while
  editing, -1 otherwise -- lossless for every real caller in this
  codebase, which only ever branches on `-1` vs. not.
- **`lib/editor.lpc`**: rewrote to the same pattern as `foundation2`'s
  fixed version -- `eventEdit()` now calls the old `ed(file,
  "__ed_exit_dispatch", !creatorp())` directly (the driver's own comm
  layer routes raw input straight to its C-level editor while a
  session is active, so this object no longer drives the edit loop
  itself), with a new `__ed_exit_dispatch()` callback replacing the
  old `process_input()`-based loop. One convenience lost: the original
  used `ed_cmd("$a")` right after starting to drop mortals/empty-file
  edits straight into insert mode; there's no LPC-level way to feed a
  just-started real `ed()` session a synthetic command, so editing now
  always starts at ed's normal command prompt.
- **`secure/cmds/creators/lsed.lpc`** (a scripted, non-interactive
  batch editor -- "run this list of ed commands against a file"): has
  **no OLD_ED equivalent at all**. Unlike a single interactive `ed()`
  session (fire-and-forget with an exit callback) or `query_ed_mode()`
  (approximable via `in_edit()`), there is no LPC-level way to feed a
  running OLD_ED session commands one at a time and read back its
  output, which is this tool's entire design. Left as a graceful
  "not supported on this driver build" message rather than left
  uncompilable -- a creator-only scripting convenience, not part of
  this project's core player/creator verification path.

## 4. Runtime (non-compile-time) bugs found and fixed

### 4.1 `daemon/help.lpc`'s `LoadIndices()` crashed on every single boot

Not caught by `lpcc_check.sh` (the file compiles and loads fine
standalone) -- only surfaced because `lpcc --batch` also *executes*
each object's `create()`, and because this file is transitively
reachable during a real boot (it's not itself preloaded, but gets
loaded on first `help` use, and this project's batch check loads
every file regardless). `LoadIndices()`'s "commands" index builder
chains several `get_dir(DIR_X + "/*.lpc")` calls with `+`:

```c
tmp = get_dir(...) + get_dir(...) + ... + get_dir(DIR_SPELL_VERBS + "/*.lpc") + ...;
```

`verbs/spells/` and `verbs/undead/` (`DIR_SPELL_VERBS`/
`DIR_UNDEAD_VERBS`) don't exist in this archive (the spell *objects*
themselves live in `/spells/` and do exist -- only their player-facing
"cast"-style verb wrappers were never shipped) -- `get_dir()` on a
missing directory returns `-1` (an `int`), and `array + int` is a hard
runtime error ("Bad type argument to +. Had array and int"), confirmed
via `log/runtime`. Guarded both sites with `pointerp(get_dir(...)) ?
get_dir(...) : ({})`. The identical pattern in `lib/detect.lpc`'s
"detect magic" skill (2 sites, `map(get_dir(DIR_SPELL_VERBS + ...))`,
plus a `spells[random(sizeof(spells))]` that would also break on an
empty result) was fixed the same way, falling back to a graceful "you
do not detect any magic" message.

### 4.2 `secure/lib/connect.lpc`/`connect.real`: see \S2 above

The by-hand `static`->`nosave` + array-dialect fix on the file that
only becomes live after the first successful admin registration.

## 5. Admin account seeding

Created live through the mud's own first-boot installation wizard
(`secure/lib/connect.lpc`, before it self-replaces with `connect.real`
-- see \S2), not a save-file hand-edit: `id fluffos`, password
`fluffwiz123`, male, default display name, email
`fluffos@example.com`, real name blank, race `human`.

One recovery needed: an earlier test run of the installer completed
successfully once, but a subsequent connection then hit the
`connect.real` static/array bug (\S2/\S3.4) and crashed before I could
verify it -- in the process of restarting to retry, I deleted the
already-correctly-created admin save file
(`secure/save/creators/f/fluffos.o`) along with its intended test
state, not realizing the installation had actually already fully
succeeded. The *second* registration (after the real fix) went through
this codebase's **normal** new-player flow instead of the one-time
installer (which only ever fires for the very first account), landing
the save file under `secure/save/players/` rather than `secure/save/
creators/`. `secure/cfg/groups.cfg` already had `fluffos` correctly
listed under `(SECURE)`/`(ASSIST)` from the first, successful
installer run (a config-file edit, not a save file, so it survived).
Manually moved the save file to `secure/save/creators/f/fluffos.o`
(exactly matching what `secure/lib/connect.lpc`'s own `InputEmail()`
does: `mkdir(DIR_CRES + "/" + Name[0..0]); rename(DIR_PLAYERS + ...,
DIR_CRES + ...)`) and recreated `realms/fluffos/workroom.lpc` (copied
from the shipped `realms/workroom.lpc` template, matching the
installer's `cp()` step) to match the state a clean single successful
run would have produced. `secure/daemon/master.lpc`'s `player_object()`
picks the `DIR_CRES` path automatically based on `file_size()` at
login time, so this is functionally identical to going through the
installer -- verified live afterward (see \S6/README.md "Admin
account").

Also found and fixed in the process: `secure/cmds/creators/
update.lpc`'s argument-reconstruction loop (`args += " " + foo` for
every surviving non-flag token) always left a stray leading space on
the rebuilt `args`, which made the file-list `explode(args, " ")`
downstream produce a spurious leading empty-string entry --
`update <path>` with an explicit filename argument produced **no
output at all** (confirmed live, before the fix). `update` with no
argument (update-current-environment) was unaffected, since it never
re-explodes `args`. Fixed with `args = trim(args)` after the
reconstruction loop. Verified live: `update /cmds/players/inventory`
now correctly prints `/cmds/players/inventory: Ok`. (Separately,
`update /secure/cmds/creators/update` -- updating the very command
object currently executing the update -- still produces no visible
"Ok" text, but this is the file destructing/reloading itself
mid-execution losing its own continuation before the final print, a
general LPC self-update gotcha rather than a bug specific to this
port; every other target file works correctly.)

## 6. Known pre-existing gaps (not fixed -- content/archive corruption,
   not driver-compat)

Per this project's standing rule against inventing missing game
content/design, the following 9 files still fail `lpcc_check.sh`
(576/585 pass) -- all non-preloaded, none block boot or the
player/creator verification path:

- **`daemon/combat.lpc`** and **`secure/sefun/values.lpc`**: both
  genuinely truncated mid-file in the *original raw archive itself*
  (confirmed by reading the raw `.c` source before any conversion
  touched it -- `daemon/combat.c` cuts off mid-string-literal inside
  an array literal at line 54 of 110, `secure/sefun/values.c` is only
  14 lines and cuts off mid-`switch`). `values.lpc` is additionally
  orphaned -- never `#include`d into `secure/sefun/sefun.lpc`'s
  simul_efun bundle, so it isn't even reachable at runtime.
- **`daemon/services/ucache.lpc`**: a genuine fragment file (like its
  7 siblings in `daemon/services/`), meant to be textually spliced
  into `daemon/services.lpc` via `#include` -- the `#include` line
  itself was missing from the original archive despite `create()`/
  `GetServices()` already assuming it was present (`#ifdef
  SERVICE_UCACHE call_out(... eventCompactUcache ...)`), meaning
  `eventCompactUcache()` etc. were referenced but never actually
  defined in the compiled program -- a real (if latent -- nothing
  calls it until the first `call_out` 3600s after boot) runtime
  "undefined function" bug. **Fixed** by adding the missing
  `#include` (matching its 7 siblings); the file's own *standalone*
  `lpcc` failure is now the expected, harmless kind (it depends on the
  parent's `inherit`/`#include <daemons.h>` provided via the splice,
  same as how its siblings work) -- added a defensive `#include
  <daemons.h>` to it directly too, matching `channel.lpc`'s
  precedent, but `eventSave()` still needs the parent's `inherit
  LIB_DAEMON` and can't be made to compile fully standalone without
  restructuring the fragment pattern itself.
- **`daemon/tmp/A_WEARON.lpc`**: one of 33 files in `daemon/tmp/` that
  are clearly wizard scratch/debug leftovers (each is a 2-line
  "`#include <X_types.h>`; `int f() { return SOME_CONSTANT; }`"
  snippet, evidently saved by some interactive eval/dump tool) rather
  than real mudlib source. This one typos `A_WEARON` for the real
  `A_WEAPON` constant (`include/armour_types.h`) -- left as-is rather
  than guessing at and "fixing" what is essentially found evidence of
  a long-ago wizard's typo, not real content.
- **`daemon/war.lpc`**: `class war`/`class team` (defined in `include/
  war.h`, which this file never `#include`d) **fixed**, along with a
  typo in the header itself (`class team agressor;` -> `aggressor;`,
  to match every real usage). But `eventDeclareWar()` still references
  an undefined `WAR_INTERVAL` constant (no value specified anywhere in
  the archive), an `obs` local used without declaration, and an
  `enemy` object variable that's read (`enemy->GetKeyName()`) but
  never assigned anywhere in the function (only `War->enemy`, the
  *class field*, is ever set) -- this looks like an abandoned/
  never-finished "declare war" feature in the original archive. Not
  in `secure/cfg/preload.cfg`, so it never blocks boot. Left
  undone rather than inventing the missing design.
- **`domains/Ylsrim/broken/jar.lpc`**: `inherit LIB_CAPTURE;`, but
  `lib/capture.lpc` (the target file) doesn't exist anywhere in this
  archive at all -- a real missing-content gap (a whole "capture a
  creature in a container" component library, used by exactly this
  one lightning-bug-jar example object), not a missing macro like
  \S3.3's cases. Its 2 sibling "broken" disease-item examples
  (`cold.lpc`/`flu.lpc`) only needed the `LIB_GERM` macro fix and now
  compile clean.
- **`secure/daemon/bugs.lpc`**: a bug-tracking daemon requiring
  `PACKAGE_DB` (which this driver build does have) against a specific,
  long-defunct external MySQL server hostname
  (`nightmare.imaginary.com`) hardcoded in `Connect()`. Has real,
  fixable typos in its first half (an `Undefined function Connect`
  forward-reference issue, a `tmp`/`reolution`/`bug_id` set of
  copy-paste typos matching this archive's general typo pattern) but
  its `GetBugs()` function is **also genuinely truncated** in the
  original raw archive (unbalanced braces, references an undeclared
  `ret`, trails off mid-statement) -- since the file can't compile
  clean regardless of the first-half fixes, and it depends on an
  external service that no longer exists either way, left entirely
  undone rather than partially patching a file that still won't
  compile.
- **`secure/daemon/remote.lpc`**: literally headed "from the
  Foundation II LPC Library" in its own file comment -- a file copied
  in from a *different* codebase generation whose `eventWrite(int fd,
  ...)` raw-file-descriptor socket API doesn't match this archive's
  own `LIB_SERVER` (`secure/lib/net/server.lpc`, whose `eventWrite`
  takes `(object owner, mixed val, int close)` instead). Adapting
  `remote.lpc`'s whole raw-fd-keyed connection/event model to the
  object-based API it's actually inheriting here would mean
  redesigning several functions, not a mechanical compat fix -- and
  it's already commented out of `secure/cfg/preload.cfg` in the
  shipped archive (a creator-only Remote Creator Protocol daemon).
  Left undone.
- **`cmds/creators/mraces.lpc`**: `#include <preset_npc_races.h>`,
  which doesn't exist anywhere in this archive (genuinely missing
  content, not a rename/path issue -- searched the whole tree).
  A creator-only "list preset NPC races" debug tool; left undone.

## 7. Skipped/no-fix bug-class checks that turned up nothing

- **`add_action()` bare-function-value vs. `NO_ADD_ACTION`**: this
  driver supports native `add_action()` and this codebase uses it
  normally (10 files, both string-name and closure-value forms) --
  not the `skylib`-class bug.
- **Missing `creator_file()`/`get_root_uid()`/`get_bb_uid()`**: also
  missing here (same `PACKAGE_UIDS` requirement as `foundation2`/
  `merentha`/`lpuni`), fixed the same way -- reusing this codebase's
  own `secure/sefun/security.lpc:file_privs()` privs-category
  classification (`ASSIST`/`CMDS`/`GENERAL`/`MUDLIBPRIV`/`SECURE`/
  domain-name) rather than inventing a new uid scheme, with the same
  `sscanf(str, "%s#%d", base, ext) != 2 -> base = str` clone-suffix
  guard `foundation2` needed for the same reason (an unmatched `%s`
  target defaults to int `0`, not `""`, which would otherwise crash
  `file_privs()`'s string-indexing on every non-cloned preload path).
- **`explode()` on `SANE_EXPLODE_STRING` edge cases**: no
  `tmi2`-class `explode('/', '/')`-shaped call sites found in this
  archive.
- **Bundled `runtime_config.h` stale indexing**: present but harmless
  here, see \S3.6.

## 8. WASM pass

**Update (2026-08-26, another session)**: promoted `wasm_status` from
`""` to `playable`. Booted clean on the first try, zero fixes needed --
unlike most sibling libs from the recurring `dump_socket_status`-in-
simul_efun pattern, this codebase apparently doesn't have that file (or
never inherits it eagerly). Verified with a scripted WASM session:
login (`fluffos`/`fluffwiz123`), the multi-page general/creator/admin
news pager, and arrival in `/domains/default/room/start` with the
correct room description. `look`/`score`/`quit` weren't recaptured
distinctly in this transcript (absorbed by the news pager, same as the
native testing initially hit -- see \S7) but are already verified clean
under native testing above.

## 9. Sibling sweep of the dsIII §7.121 currency-float bug — NOT APPLICABLE, this lib doesn't have the affected functions

`AGENTS.md` §7.121 documents a currency/economy bug in `dsIII` (the
Dead Souls 3.x lineage's shared `secure/sefun/economy.lpc`):
`query_base_rate()`/`query_player_money()`/`query_base_value()`/
`query_value()` do real floating-point exchange-rate math but are
declared `int` with no `to_int()` on the return, flagged for a sibling
sweep across `ds386`/`dsI`/`dsII`/`dshakkard`/`deadsouls_fluffos`.

This lib's `secure/sefun/economy.lpc` is a much smaller, earlier
Nightmare-IV-era file — it only defines `currency_rate()`,
`currency_inflation()`, `currency_mass()`, `currency_value()`, and
`mud_currencies()` (all already correctly `to_int()`-wrapped where they
return `int`). The four suspect functions (`query_base_rate()`,
`query_player_money()`, `query_base_value()`, `query_value()`) don't
exist anywhere in this archive (`grep -rn` across the whole tree found
zero matches), and `lib/teller.lpc`'s `eventExchange()` computes its
own exchange amount inline (`val = amount / currency_rate(str1); ... i
= to_int(val * currency_rate(str2));`) with the `to_int()` already
correctly present — no gap. `lib/props/value.lpc` has no `SetBaseCost()`
or any currency-rate math at all. **Checked, confirmed not applicable**
— this lib's economy code predates the buggy function shapes entirely,
so no fix was needed or made.

## 10. Deep functional test (round two, §10.7)

Full continuous playthrough via a raw Python socket script against
`~/src/fluffos/build-debug/src/driver`, admin account `fluffos`/
`fluffwiz123` (per §5 above). This lib had never had a round-two pass
before this session. Two real programming bugs found and fixed live;
everything else checked came back clean.

### 10.1 `lib/std/room.lpc`'s single-inherit `replace_program()` "fold"
optimization crashes ANY speech (`say`/`ask`/`tell`) in a just-loaded
room for its first ~5 minutes, driver-wide, on every simple room

`create()` ended with:

```c
if( replaceable(this_object()) && !GetNoReplace() ) {
    string *tmp= inherit_list(this_object());
    if( sizeof(tmp) == 1 ) {
        replace_program(tmp[0]);
    }
}
```

— a classic MudOS-era memory optimization: a room that only does
`inherit LIB_ROOM;` and adds nothing but its own `create()` gets its
compiled program folded into the single shared base-class program once
`create()` finishes, since nothing else in it is ever called again.
This still works correctly on this driver in the end state, but the
*timing* doesn't: `replace_program()`'s effect is deferred to this
driver's periodic `remove_destructed_objects()`/`replace_programs()`
sweep, which only runs **every 5 minutes** from boot
(`backend_register_tick_events()` in `~/src/fluffos/src/backend.cc`),
not after every command the way an original-era MudOS did. Any object
with a pending replace sits in a "cannot bind a functional to an
object with a pending replace_program()" state
(`vm/internal/base/function.cc`'s `make_functional_funp()`) until that
sweep fires — and `lib/std/room.lpc`'s own `eventHearTalk()`
(`TALK_LOCAL` case) builds a `filter()` closure
(`(: (int)$1->is_living() && $1 != $(who) :)`) on the room object
itself. Since `/domains/default/room/start` (the very first room every
new player lands in) is exactly this shape (bare `inherit LIB_ROOM;`),
**every single `say`/`ask`/`tell` heard in that room during its first
~5 minutes after being loaded (i.e. essentially every fresh boot)
hard-crashes** with that error, caught only as a generic "A runtime
error occurred, use 'bug -r' to report it" for the speaker. Confirmed
live: a fresh `ask <anyone> to <anything>` in the start room within
~1 minute of boot reliably crashed (`log/runtime`), and the identical
command 5+ minutes after boot worked cleanly. **Fixed** by dropping the
`replace_program()` call from `lib/std/room.lpc`'s `create()` entirely
— it is purely a memory micro-optimization with no functional
consequence once it lands, so removing it just means ordinary rooms
keep their own (tiny, already-compiled) program instead of being
folded into the shared one; `SetNoReplace()`/`GetNoReplace()` are left
in place as harmless now-unused API. Verified live: `say`/`ask`
immediately after a fresh boot (well inside the old 5-minute window)
now work cleanly with zero `log/runtime` entries. This is a new bug
shape — not a match for any existing AGENTS.md `§7.*` entry — added as
a new entry (see AGENTS.md for the number) since `replace_program()`'s
"fold a single-inherit object into its parent program" idiom is a
generic MudOS/Nightmare/Dead-Souls-era pattern likely to recur in
sibling libs that never got a §10.7 pass yet.

### 10.2 `lib/combat.lpc`: `Wimpy` auto-flee threshold initialized as a
0.0-1.0 fraction into a declared-`int` field — an exact instance of
AGENTS.md §7.124 (previously found on `nightmare4`, a close sibling of
this very lib's own "closer to Nightmare IV" lineage)

`private int Wimpy;` was initialized in `create()` with `Wimpy = 0.20;`
— a fraction, not the 0-100 percentage that `percent()`,
`cmds/players/wimpy.lpc` (`wimpy on` sets `23`, caps user input at
`30`), and the runtime check itself (`Wimpy < percent(hp, max)` in
`eventReceiveDamage()`) all consistently expect. This driver silently
truncates a float assigned to a declared-`int` variable at the point
of assignment (confirmed directly via `eval int x; x = 0.20; return
x;` → `0`), so `Wimpy` was actually `0` for every character from
`create()` onward — and `eventReceiveDamage()`'s very first line,
`if( !Wimpy ) return x;`, meant the entire auto-flee-at-low-health
safety net was **silently dead for every character, from the very
first one ever created, with zero compile error and zero crash** —
exactly AGENTS.md §7.124's shape, byte-for-byte the same buggy literal
(`Wimpy = 0.20;`) as the already-documented `nightmare4` instance.
`SetWimpy(float wimpy)`/`float GetWimpy()` carried the same secondary
mismatch `nightmare4` had too: declared to return `float` instead of
`int` (matching the field's own real type and its only real callers),
which meant a nonzero value round-tripped through a real float on
return, corrupting the player-facing `wimpy` command's own percentage
display (`"Percentage: 20.000000%"` instead of `"20%"`, confirmed live
pre-fix). **Fix**, identical in shape to `nightmare4`'s: `Wimpy = 0.20;`
→ `Wimpy = 20;`, and `float SetWimpy(float wimpy)`/`float GetWimpy()` →
`int SetWimpy(int wimpy)`/`int GetWimpy()`. Verified live end-to-end,
not just the default value: a fresh character's bare `wimpy` command
now reports `"Percentage: 20%"` (was `"Percentage: 20.000000%"`
pre-fix, the exact `nightmare4`-shaped display corruption), and a
direct test — spawn a cloned `traveller` NPC, cut the test character's
HP to 58/390 (~15%, below the 20% threshold) via `eval`, then
`attack traveller` — now correctly triggers the auto-flee: the
character was moved out of the room entirely (fled from
`/domains/default/room/start` to `/domains/Ylsrim/room/bazaar` via
`eventWimpy()`'s "go out" → fallback-to-any-valid-exit logic) after
taking one more hit, surviving at 49/390 hp instead of continuing to
fight to death. Pre-fix, this exact sequence would never have fled at
all (`Wimpy` being `0` short-circuits the check unconditionally).
Extended AGENTS.md §7.124's "confirmed instances" note rather than
adding a new entry, since this is the identical bug shape on a lineage
sibling of the lib §7.124 was originally found on.

### 10.3 Full playthrough coverage (all confirmed clean except the two
bugs above)

- **Registration + race selection**: registered `Testwind`
  (English name, human, male fighter) through the full
  `secure/lib/connect.lpc` flow (name → confirm → password → confirm
  → gender → display name → email → real name → race `list`/`pick`).
  Clean throughout.
- **Newbie help**: `news/newbie` is an empty placeholder file (no
  actual newbie-help content shipped in this archive) — the intended
  test path had to be reconstructed from room descriptions and NPC
  `long` text instead (this is what led to `domains/Ylsrim`'s fighter
  hall / Roshd Burlyneck NPC as the class-join path).
- **Movement**: full navigation `start` → `bazaar` → `kaliid4` →
  `kaliid5` → `fighter_hall`, and `bazaar` → `s_bazaar`. Directions
  only work as `go <word>` or the single-letter aliases
  (`n`/`s`/`e`/`w`/`u`/`d`/`ne`/`nw`/`se`/`sw`, from
  `lib/nmsh.lpc`'s `Aliases` mapping) — a bare full word like `north`
  is NOT itself a command (no `add_action("north", ...)` anywhere;
  only `go.lpc`'s `SetRules("STR", "into STR")` and the single-letter
  aliases exist). Confirmed this is the actual shipped design (not a
  bug) by reading `lib/nmsh.lpc` directly — flagging here only because
  an early test round mis-typed bare directions and initially looked
  like a broken movement system before the aliasing scheme was found.
- **Class join**: `domains/Ylsrim/npc/fighter.lpc` (Roshd Burlyneck,
  `LIB_LEADER`) via `ask roshd to join fighters` — works correctly
  (`ask X about Y` is NOT supported by this codebase's `ask` verb,
  since it has no `"about"`-stripping rule in `SetRules()`; the
  NPC's own description text literally says `ask him to "join
  fighters"`, i.e. the `LIV to STR` rule, which is the one that
  actually calls `eventAsk()` — `LIV STR` alone just speaks the
  sentence audibly with no NPC response). `score`/title correctly
  updated `Newbie Wanderer` → `Newbie Fighter`, `Human Commoner` →
  `Human Fighter`. `ask roshd to describe fighters` silently produces
  no visible output beyond the player's own echoed line — traced to
  `lib/leader.lpc`'s `eventPreview()` paging
  `DIR_CLASS_HELP "/" + GetClass()` (`/doc/help/classes/fighter`),
  which doesn't exist anywhere in this archive (`doc/` only ships
  `CHANGES`/`README`, no `help/` subtree at all) — genuine missing
  content, not a code bug (`eventPage()` on a missing file returns
  `"File not found."` as a string that `eventPreview()` never prints).
  Left as-is per this project's standing rule against inventing
  content.
- **No safe-sparring mechanism exists in this lib** (grepped for
  `spar`/`practice`/`dummy`-as-training-target — `lib/std/dummy.lpc`
  is an unrelated hidden-scenery-item base class, not a combat
  target). Used the domain's own placed wandering `traveller` NPC
  (level 5, `domains/Ylsrim/room/s_bazaar`) as the weakest reachable
  live opponent instead — `domains/Ylsrim/npc/balrog.lpc` (level 8,
  the domain's other low-level NPC) turns out to be dead/orphaned
  content: grepped the whole tree and it is never placed by any room
  or `SetInventory()` anywhere, only referenced by its own file and by
  `secure/cfg/races/balrog` (a playable-race entry, not a placement).
- **Combat**: `attack <target>` engages normally, exchanges
  proper damage messages, correct `hp`/`mp`/`sp` status-bar updates,
  skill-improvement messages ("You are a bit more adept with your
  melee attack/defense"), and resolves cleanly (traveller wandered off
  mid-fight per its own `SetWander(25)`, ending combat with no
  crash — `GetInCombat()` correctly returned to `0` afterward).
- **Death/resurrection**: this lib's death model is a **two-stage
  "become a ghost, then regenerate" system**, not permanent one-shot
  death. `body::eventDie()` toggles `GetUndead()` as a side effect
  (`SetUndead(!GetUndead())`); a mortal's first death flips it to `1`
  and routes through `player::eventDie()`'s `else` branch (message,
  `NewBody()`, half-heal, move to `ROOM_DEATH`
  `/domains/default/room/death`) — confirmed live via `eval
  ...->eventDie()`: correct "Consciousness passes from you..." message,
  landed in "Off the mortal coil", `score` correctly showed "the
  ghost"/"level 1 undead Human Fighter". The death room's `regenerate`
  command correctly calls `eventRevive()` + moves back to
  `ROOM_START`, confirmed live: `score` afterward correctly showed
  the character alive again ("the unaccomplished", no longer
  "undead"). **This subsystem is NOT silently broken here** (unlike
  the sibling `es1` finding flagged in this session's task brief) —
  full death→ghost→regenerate cycle verified live end to end.
  - A **second** `eventDie()` while already undead flips the flag back
    to `0` (mortal) and takes the `if(!GetUndead())` branch, which
    calls `eventDestroyUndead(agent)` — initially suspected as an
    undefined-function crash (same shape as the wxddym/shenmo `addn()`
    class of bug from this session's earlier sweeps), but on closer
    reading `lib/player.lpc:116` DOES define it, just as a permanently
    **empty stub** (`nosave void eventDestroyUndead(object agent) {
    }`). Confirmed live: a second forced death produces no crash and
    no visible effect at all beyond the title reverting from "the
    ghost" to "the unaccomplished" — this looks like an intentional
    "permanent death" hook that was simply never implemented in this
    archive. Left as an **observed content/design gap, not fixed**
    (deciding what permanent death should actually do is exactly the
    kind of content/design judgment call this project's scope
    excludes) — documented here rather than guessed at.
  - The death room's alternate `wander` command (an admitted secondary
    path alongside `regenerate`) moves to
    `/domains/campus/room/admissns`, a room from a `campus` domain
    this archive never shipped (only `default`/`Ylsrim` exist here) —
    `eventMoveLiving()` handles the missing destination gracefully
    (`eventMove()`'s own `find_object`/`catch(call_other(...))` fallback
    returns `0` cleanly), so this is a soft no-op ("You remain where
    you are") rather than a crash. Missing content, not a fix-worthy
    bug.
- **`get`/`drop`**: work correctly (verified with a cloned
  `/domains/Ylsrim/etc/pole`).
- **Shop/economy**: `buy ITEM from VENDOR` / `sell ITEM to VENDOR`
  verbs exist and route correctly to `lib/std/vendor.lpc`'s
  `eventSell()`/`eventShowItem()`, but a live end-to-end transaction
  was **not reachable this session**: the shops (`max`/armourer,
  `shiela`/weapon vendor) are day/night-gated
  (`domains/Ylsrim/room/armoury.lpc`'s `CheckOpen()` destructs the
  vendor NPC entirely at night) and this session's test window landed
  during in-game night both times it reached the armoury — confirmed
  this is the shop's own intentional day/night design (not a bug) by
  reading `CheckOpen()` directly. Separately, `armoury_storage.lpc`/
  `weaponry_storage.lpc` (the `SetStorageRoom()` targets `eventSell()`
  reads stock from) ship with **no preset `SetInventory()`** at all —
  so even during the day, `buy` would report "I have nothing like
  that to sell" until a player first sells something there, or an
  admin stocks it by hand. This looks like the intended
  "vendors buy your loot, no premade retail stock" design for this
  minimal example domain, not a missing-content bug, but is flagged
  here as **not fully verified live** (economy testing performed;
  the buy/sell code paths were read and are structurally sound, but
  a real day-side purchase was never actually completed).
- **`quit` + `debug.log`/`log/runtime` grep + reconnect after a real
  wall-clock gap**: `quit` prints the normal "Please come back another
  time!" every time; `debug.log` stayed empty and `log/runtime`'s line
  count did not change across every quit/reconnect cycle in this
  session (checked after each one, not just once). Reconnected after
  a real ~60+ second gap (not simulated) mid-session: `score`/`i`/
  `look` all correctly reflected the exact pre-quit state (title,
  class, room, inventory).
- **Standing cross-cutting bug-pattern sweep** (§7.121 float-in-int,
  §8.3a `private`+`add_action`/`call_out` demotion, §7.112 unguarded
  `init()` call_out chains, §7.122 autoload duplication, §7.123 bare
  file-scope assignment, §7.126 stale-`.c` door data, §7.129
  `tell_room()`/`message()` literal-`0` exclude, §7.130 unconditional
  `query_idle()`, §7.131 `find_living()`/`find_player()` registration,
  §7.132 `map()`-over-mapping argument binding, §7.133 undefined
  disconnect apply, §7.134 uninitialized array field, §7.135/§7.30
  missing lazy-init guard): grepped for every one of these shapes
  explicitly. All came back clean/not-applicable in this codebase
  except §7.124 (already covered in §10.2 above) — see the commit's
  companion AGENTS.md edit for the one-line summary of what was
  checked for each. Notably, this codebase's collections are
  overwhelmingly eagerly initialized in `create()` (`Quests = ({});`,
  `Exits = ([]);`, `DummyItems = ({});`, etc.) rather than relying on
  a lazy-init-on-first-access idiom, so the whole §7.30/§7.135 family
  of bugs doesn't really have the right shape to occur here in the
  first place. `find_living()`/`set_living_name()` (§7.131) is
  correctly wired (`lib/npc.lpc`/`lib/interactive.lpc` both call
  `set_living_name()`), confirmed live via `eval find_player(...)`
  working correctly throughout every test above.

### 10.4 Test character cleanup

All throwaway test-character saves (`Testwind`, `Wimpycheck`,
`Wimpye2e` — the last one never actually completed registration) were
deleted before committing, per this project's standing convention —
only the seeded `fluffos` admin account (`secure/save/creators/f/
fluffos.o`) remains under `secure/save/`.

### 10.5 Sibling-sweep check for ds386's round-two `eventRevive()` float bug (2026-08-27)

`ds386/NOTES.md`'s round-two pass found a NEW `AGENTS.md` §7.121-class
bug not covered by this lib's own §10.2/§7.124 Wimpy fix: `eventRevive()`
feeding float arithmetic (`GetMaxHealthPoints() * PERCENT_HP`-style
expressions) into `AddHealthPoints()`/`AddMagicPoints()`'s `int`
parameters. Checked this lib's own `lib/player.lpc:eventRevive()`
specifically for that shape: **not present**. This codebase's
`eventRevive()` only calls `eventCompleteHeal(GetMaxHealthPoints())`
(a full heal, no arithmetic) for HP and `AddMagicPoints(-(GetMaxMagicPoints()/2))`
for MP — plain integer division, no `PERCENT_MP`/`PERCENT_HP` float
`#define`s exist anywhere in this file. No fix needed; confirmed clean
by reading the code (no live re-test required for a no-op finding).
