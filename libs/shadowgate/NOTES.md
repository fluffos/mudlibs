# ShadowGate -- porting notes

Source: `git clone https://github.com/openshadowgate/shadowgate` (cloned
2026-08-28). Slug `shadowgate`, number 944, port 40246. The repo root itself
is the mudlib root (`adm/obj/master.c`, `cmds/`, `d/`, `daemon/`, `std/`,
`fluffos.cfg.example`, `local_options.example` all sit at top level -- no
bundled driver source). 46,610 files, ~224MB excluding `.git`. A genuinely
distinct find: a *Nightmare Mudlib*-lineage (see `adm/obj/master.c`'s own
header: "from the Nightmare Mudlib ... created by Descartes of Borg 1993")
English-language AD&D/d20-style fantasy mudlib -- feats, invocations,
disciplines, ~50 playable races (`adm/db/races.db`), 14 classes
(barbarian/bard/cavalier/cleric/druid/fighter/mage/paladin/psion/psywarrior/
ranger/sorcerer/thief/warlock, one trainer NPC file per class under
`d/shadowgate/masters/`). The repo's own `README` states this is (or was) a
real, still-hosted MUD ("shadowgate.org", ports 8080/8443) -- unrelated to
the classic 1989 NES adventure game of the same name.

## 1. Conversion

Pure English/ASCII archive -- `convert_lib.sh` reported `already_utf8=46597
converted=2 lossy=0 skipped_binary=11`. Renamed every `.c` to `.lpc` (44,500
files), fixed 21,470 literal `.c"` references, converted 133 local
angle-bracket `#include`s to quotes, ran the `static`->`nosave` sweep across
97 files.

## 2. Required setup step (not a bug): access-control database seeding

The repo's own `README` says so directly: `adm/db/{access,groups,privs}.db`
are `.gitignore`d and ship only as `.db.example` templates. `master.lpc`'s
`load_access()`/`load_groups()`/`load_privs()` (lazily triggered by the
very first non-root file access, i.e. essentially immediately after boot)
each hard `shutdown()` the whole driver if their database file is
empty/unreadable. Copied all three `.example` files to their real names
before first boot. `groups.db`'s `(superuser): admin` line is what a
wizard-rank account actually needs (see section 5).

Also created every runtime-write directory the repo's own `.gitignore`
excludes and this project's `work/` therefore starts without: `log/` (plus
`adm/law`, `watch`, `adm/jail`, `enter`, `errors`, `emotes`, `jail`,
`personal`, `reports`, `rid`, `tshlog` subdirs referenced by `access.db`),
`adm/save/{accounts,daemons,letters,postal,users,votes}`, `daemon/save`,
`realms`, `avatar`, `inv`, `tmp`, `d/players`, `d/save/stories`, `single`
(for the configured swap file). Skipping this would trip AGENTS.md's
S7.11 class (silent `write_file()`/`save_object()` abort) across dozens of
call sites the moment any of them fired.

## 3. Compile-time / driver-compat fixes

### 3a. `std/user/refs.lpc` -- "ref" is a reserved word on this driver, and it broke the ENTIRE player body class (the severe, totally-blocking bug)

This project boots every lib against one shared prebuilt FluffOS driver
rather than rebuilding per-lib from the archive's own
`local_options.example` -- so a driver-level compile-time option this
archive's own `local_options.example` explicitly turns off
(`#undef REF_RESERVED_WORD`) can still be ON in the actual driver binary in
use, silently invalidating the archive's own assumption. Confirmed: this
project's driver hardcodes `#define REF_RESERVED_WORD`
(`src/base/internal/options_internal.h`), which makes the bare identifier
`ref` a reserved keyword (FluffOS's old MudOS-style pass-by-reference
argument marker, `void inc(int ref x)`) -- using it as an ordinary
variable/parameter name is a hard syntax error, not a warning.

`std/user/refs.lpc` (`set_ref(string ref, ...)`/`get_ref(string ref)`)
hit this on both its functions. This file is directly `inherit`ed by
`/adm/include/user.h`, which is itself `#include`d by `std/user.lpc` --
**the actual player body class (`OB_USER`)**. The syntax error in the
inherited file failed the whole `/std/user` compile
(`Fail to load object /std/user`), which would have broken `new(OB_USER)`
in `adm/obj/login.lpc::logon()` for every single connection, falling
through to the failsafe body (`/adm/failsafe/user_failsafe`) at best, or
killing every connection outright if that also failed to compile --
functionally identical in severity to the `ed_start()`/`query_ed_mode()`
class of blocker documented for `finalrealms`. Fixed by renaming the
parameter `ref` -> `refname` in `std/user/refs.lpc`.

The same identifier was used the same way in three more places, all fixed
identically (renamed to `refname`/`idx`, functionally identical, all
`ref`-commands only -- wizard reference-variable tooling, not part of the
core boot chain but sharing the bug): `adm/daemon/refs_d.lpc` (the
`this_player()->set_ref(...)`/`get_ref(...)` call-other shim, plus a local
`string ref;` inside `resolv_ref()`), `adm/failsafe/refs_failsafe.lpc` (a
dead, unreferenced standby copy of `refs.lpc` -- fixed anyway for
consistency), and `cmds/system/_clog.lpc`'s `pop_coder(int ref)`. Grepped
the whole tree for the declaration shape
`(string|object|int|mixed|float|mapping)\s*\*?\s*ref\b\s*[,;=)]` after the
fix and confirmed no more live instances; a handful of remaining `ref`
substrings are all inside string literals/comments (`cmds/system/_ref.lpc`'s
own help text, etc.), not real identifiers.

**Not previously catalogued in AGENTS.md -- added as a new general bug
class** since REF_RESERVED_WORD is a driver-build-wide setting that could
affect any future archive using "ref" as a variable name (a very natural,
common short name), and this is exactly the kind of "reads clean, archive's
own config says it's off, but the driver actually in use says otherwise"
trap the project has been bitten by before with other build-time options
(OLD_ED, etc.).

### 3b. `std/Object.lpc`/`std/room.lpc` `set_short()`/`set_long()` -- closures passed but never evaluated

Recurring Nightmare-lineage bug already catalogued in AGENTS.md
(`nightmare3`, `nightmare4`, `sunshadow`, `demonangel`, `realms`, `genesis`,
`finalrealms` all hit variants of this). 789 call sites across this
archive pass a two-argument bound closure (`set_short((:TO,"long_desc":))`,
etc. -- `TO` expands to `this_object()`, a call, so this grammar shape
compiles fine on this driver per the `nightmare3` precedent) to
`set_short()`/`set_long()`, expecting the description to be computed lazily
each time it's displayed. But `std/Object.lpc`'s `set_short(string str)`/
`set_long(string str)` only ever `set()` the raw value, and
`query_short()`/`query_long()`/`query_obvious_short()` only checked a
*separate* `function_short`/`function_long` string-property mechanism
(resolved via `call_other(TO, name)`) before falling back to
`ob_data["short"]`/`ob_data["long"]` **verbatim, with no `functionp()`
check at all** -- a stored closure would flow straight into a
`string`-declared return and then into ordinary string concatenation the
first time anything displayed it (a `look`, an NPC's own short, etc.),
throwing a runtime type error. The archive's own dead/unused legacy base
class `std/tobj.lpc` (confirmed: 0 live inherits anywhere in this tree)
already implements the correct pattern
(`functionp(ob_data["short"]) ? (*ob_data["short"])() : ob_data["short"]`)
-- ported that exact idiom into the live `std/Object.lpc`. Widened
`set_short()`/`set_long()` to `mixed` (both here and in `std/room.lpc`'s
forwarding overrides, and `std/riding_animal.lpc`'s `set_short()` override
for consistency, though no live mount content currently passes it a
closure). `std/room.lpc`'s own `query_long()`/`query_short()` already
correctly handle a separate day/night-description closure mechanism and
fall through to `container::query_long()`/`query_short()` for the plain
case, so fixing the base class alone covers rooms too.

### 3c. `daemon/command.lpc` -- the AGENTS.md S7.118 `.c`->`.lpc` filename-slice bug, another confirmed instance

Already catalogued (S7.118): archives that build a command-dispatch table
by slicing a fixed number of characters off a directory-listing filename
to strip the extension break once this project's mechanical `.c`->`.lpc`
rename lengthens every extension by two characters. `rehash()`'s
`choses[j] = choses[j][1..strlen(choses[j])-3]` (strip 1 leading `_` + 2
for the archive's original `.c`) silently kept two garbage characters --
`_look.lpc` became `look.l` instead of `look` -- corrupting **every single
ordinary command name** (`look`, `score`, `say`, ...) in `__Cmds`, the
table `find_cmd()` looks up on every command a player types. Total,
silent, zero-compile-error blocker: this is the shared-ancestor file for
`sunshadow`'s own confirmed instance of the same bug (both are Nightmare
Mudlib IV `daemon/command.c` descendants) -- see AGENTS.md S7.118 for the
general writeup and four other independent confirmed instances the same
week. Fixed the same way: `-3` -> `-5` (strip 1 leading `_` + 4 for
`.lpc`).

Checked for the S7.118 "second instance" shapes elsewhere in this archive
(a `strsrch(...) != strlen-2`-style extension-comparison, or a
`file_size(x+".c")`-style literal-extension existence check) and a broader
sweep of every `[..strlen(x)-N]`/`[N..strlen(x)-N]` slice for N in 2-5:
none of the other ~15 hits were extension-related (they trim trailing
punctuation/separators from unrelated strings, or -- `daemon/quests_{low,
mid,high}.lpc`/`cmds/mortal/_advance.lpc` -- walk a path backwards one
character at a time in a `while` loop until hitting `/`, which is already
extension-agnostic). `daemon/magic_d.lpc`'s own spell-directory scanner
and `cmds/adm/_commands.lpc`'s header generator both already use
`replace_string(x, ".lpc", "", 1)`/`sscanf(x, "%s.lpc", ...)` --
dynamically matched against the literal `.lpc` string rather than a
hardcoded length, so both were either already fine or self-healed by the
mechanical `.c"` -> `.lpc"` literal-reference fixup in `convert_lib.sh`
(confirmed: `magic_d.lpc`'s `replace_string` calls used a bare `".c"`
string argument, which that fixup's sed pass rewrites the same as any
other `.c"` reference).

### 3d. `d/shadowgate/masters/{masters,class_stuff}.lpc` -- wrong `<dieties.h>` resolved (AGENTS.md S6.1)

The class-specialization "masters" trainer NPCs (one file per class) both
`#include <dieties.h>`. Angle brackets only search the configured include
path (`/adm/include:/include`), never the including file's own directory,
so this resolved to a small, unrelated global `/include/dieties.h` (34
lines, no `KNIGHTALIGN`/`RANGERALIGN`/`DRUIDS`) instead of the real, much
larger deity-alignment table one directory up at
`/d/shadowgate/dieties.h` (102 lines, has all three) -- `Undefined
variable 'KNIGHTALIGN'`/etc., breaking every class trainer's
diety-selection step (`pick_diety()`). Not fixable via
`master::get_include_path()` (commented out in this archive, and even
enabled it only special-cases same-directory headers, not a parent
directory) and `..` in include paths is disallowed outright, so fixed with
an absolute quoted include: `#include "/d/shadowgate/dieties.h"`. (A
near-identical, byte-mostly-duplicate `d/shadowgate/dieities.h` -- note
the extra `i`, an old typo'd fork -- also exists and also defines these
constants, but lacks a couple of newer additions the real file has; used
`dieties.h`, the one `masters.lpc`'s own comments and content expect.)
Left the other 12 files that also `#include <dieties.h>` (including
`std/user.lpc` itself) alone -- none of them reference the
`KNIGHTALIGN`/`RANGERALIGN`/`DRUIDS` constants, so the generic global
header is functionally correct for their purposes and switching them
risked pulling in the local file's slightly different data (a
`"Undead/War"` vs `"Undeath/War"` spelling difference, etc.) with no
benefit.

### 3e. Compile-sweep tail (deep zone/content files)

`scripts/lpcc_check.sh` against the full ~44,500-file tree is memory-heavy
on a lib this size (a known project hazard, AGENTS.md S10.4: "batch mode
never unloads"). A first, uncapped run was stopped by the coordinator at
27,041/44,500 files (2,364 fails) when RSS hit ~15.5GB with host-wide free
memory down to 5.4GB -- the exact incident class AGENTS.md documents for
`nt1`/`sunshadow`. Triaging that partial run's failures (before fixing
anything) found the two real driver-compat bugs in SS3a/3c above; after
fixing them, every one of this project's own core boot-chain files was
individually spot-checked clean in isolation:  `adm/obj/master`,
`adm/obj/simul_efun`, `adm/obj/login`, `adm/obj/user_account`, `std/user`
(the player body, previously the one core-chain FAIL), `std/Object`,
`std/container`, `std/room`, `std/living`, `std/battle`, `std/move`, and
the real starting room `/d/shadow/room/forest/road30` (from `ROOM_START`,
`adm/include/rooms.h`) -- all PASS. A re-run wrapped in `ulimit -v
8388608` (8GB) plus an active RSS-polling safety watcher (kill past 9GB)
self-terminated cleanly (exit 0, no watcher intervention needed) after
12,276/44,500 files: `total=12276 pass=10569 fail=1707`. None of the
1,707 failures in this capped run touch any core boot-chain file (grepped
for all the paths above -- zero hits), confirming the two fixes above are
the load-bearing ones. The remaining tail is deep zone/monster/room/item
content scattered across `d/*` -- dominated by `error: syntax error`
(1,526 -- individual scattered content typos) and `error: Cannot
#include ...` (63 -- mostly `/realms/<wizard-name>/...` personal-workroom
headers that don't exist in this repo snapshot since `/realms` is
`.gitignore`d player/wizard data, AGENTS.md S7.14 "missing zone content is
an archive gap, not a bug"). Genuinely a huge, decades-developed live game
world; per this project's standing policy (AGENTS.md S2, "deeper content
bugs ... logged in NOTES.md, not necessarily fixed") not exhaustively
chased file-by-file, and not worth another multi-GB sweep attempt to
cover the untested remainder given the core chain is already confirmed
clean by direct inspection. One dead/unused file confirmed along the way:
`std/newuser.lpc` (0 live inherits/references anywhere in the tree) calls
`more::create()`, which does not exist (`/std/user/more.lpc` defines no
`create()`) -- a genuine pre-existing bug in the original archive, but
inert since nothing loads this file.

## 4. A second severe blocker found only through live play: missing per-account save-data directories abort `setter_object.lpc::_finalize()` mid-way, silently trapping every new character in chargen forever

Not visible from any static grep or compile sweep -- only surfaced by
actually playing a full registration through to world entry. The 15-stage
chargen wizard (`d/shadowgate/setter_object.lpc`, matching the
`sunshadow`-lineage description of the same file: class, gender, race,
subrace, template, age, stat rolling, height/weight/body/hair/eye,
language, alignment, deity, class special) completes and accepts
`<finalize>` with zero error message, but the player never actually left
the "soul void" creation room -- `<finalize>` silently re-displayed the
void room's "veteran player" text instead of the expected "Entering the
world of ShadowGate!" banner and a real room. Root cause: `_finalize()`
calls `"/daemon/description_d"->new_description_profile(ETO)`, which
`save_object()`s to a **per-first-letter-of-username bucket directory**,
`/daemon/save/saved_descriptions/<letter>/`, that (like every other
per-account save path in this archive) is `.gitignore`d upstream and does
not exist in a fresh checkout. `save_object()` into a missing parent
directory aborts the whole calling function on this driver (not a
soft `0` return) -- so `_finalize()` died right after printing "Converting
relationships..." (from the call just before) and before reaching
`tell_object(ETO, "Entering the world...")`/`move_player()`. The
character was stuck being asked to `<press button>`/`<review>` forever,
indistinguishable from a hang to anyone not reading the LPC. Two sibling
per-account paths hit the identical class the moment normal gameplay
(not just chargen) exercised them: `/log/tshlog/player/<name>` (every
`tshlog`-based command logging) and `/d/save/quests/<timestamp>.lpc`
(the quest daemons). Fixed by creating the full `a`-`z` bucket set under
`daemon/save/saved_descriptions/`, plus `log/tshlog/player/`,
`d/save/quests/`, and `adm/save/user_accounts/` (a second, differently-
named accounts directory used only by `adm/obj/user_account.lpc`'s
`ACCOUNTS_DIR`, distinct from `bank.h`'s `/adm/save/accounts/`).
**General lesson for any future letter/hash-bucketed per-account save
path in a from-scratch English archive**: grep `SAVE_EXTENSION`-style
directory constants and any `<var>[0..0] + "/"`/`folder = ...[0]`-shaped
bucket-directory construction proactively, not just the flat directories
`access.db`/`.gitignore` name explicitly -- this bug class specifically
escapes both the compile sweep (no compile error at all) AND a
registration test that stops at "did a room description print" rather
than confirming the SPECIFIC "Entering the world" banner text.

Also confirmed, empirically: this project's build-debug driver was
intermittently `SIGKILL`ed (confirmed via `gdb -batch`, not a caught
LPC-level error, no debug.log signature, no host-memory-exhaustion
signature either -- `free -h` and RSS polling both stayed healthy)
during the FIRST `std/user.lpc` compile of a fresh boot, before the
`setter_object.lpc`/`dieties.h` fix above landed. It has not recurred in
any of the many (10+) boot/registration/finalize/quit cycles run after
that fix, including the final formatter-verification pass, which is
consistent with (though not conclusively proven to be) the AGENTS.md
S10.4 "repeated-failed-compile-attempt memory/resource churn" mechanism:
every `press button` attempt with `setter_object.lpc` still broken
retried the same failing `new()` immediately, and on a lib this size
(44,500 files) that retry loop's cost may have been enough to trip an
external resource guard on this shared multi-tenant host even though no
single measurement ever caught it above a few hundred MB RSS. Recorded
here rather than left unexplained in case a future session sees the same
symptom on this or another mega-lib.

## 5. Boot and play verification

Native driver (`~/src/fluffos/build-debug/src/driver config.fluffos`,
run from `libs/shadowgate/` per AGENTS.md S5.2), zero fatal boot errors
after the fixes above -- only the usual `-Wunused-variable`-style
warnings and two benign preload notes (`author_file()`/`domain_file()`
fallback; `ipc.lpc`'s own local-only status-socket preload at boot+5s on
port 8181, harmless, not a network call to any third party). Full
end-to-end verification with a raw socket client (`scripts/mudclient.py`)
after all fixes:

- **Fresh registration, real name, full flow**: connect -> name
  (`fluffos`) -> confirm -> password (>=6 chars) -> confirm -> ANSI color
  test -> drops into the "soul void" chargen room -> `press button` ->
  the full 15-stage `setter_object.lpc` wizard (class **fighter**,
  gender, race **moon elf**, subrace, template, age, stat rolling via
  `recommended`+`done`, height/weight/body/hair/eye, language,
  alignment, deity, class special) -> `finalize` -> "Entering the world
  of ShadowGate!" -> real world room (`/d/newbie/ooc/hub_room2`, the OOC
  tutorial hub, `ROOM_START`'s effective destination for a first-time
  character via `getenv("start")`/`primary_start`).
- **`look`**: correct room name/description/exits, confirmed on both the
  chargen void room (day/veteran-vs-new text branch working, exercising
  the S3b closure fix directly -- `set_long((:TO,"my_long":))`) and the
  post-finalize hub room.
- **`score`**: full, correctly-populated character sheet -- race,
  gender, alignment, class, level, exp, deity, fighter style, HP/AC/
  carrying/hunger/thirst/stamina/intoxication meters, play time.
- **`quit`**: clean save (`adm/save/users/f/fluffos.o` written) and
  disconnect banner; re-login with the same name+password afterward
  correctly restores the saved character into its last room
  (`/d/newbie/ooc/hub_room2`) rather than re-running chargen.
- Repeated the full cycle 3+ times (different random race/class/deity
  rolls each time, including a second full account `fluffosb`) with
  consistent success once the S3a/S3d/S4 fixes were in place.

Minor, non-blocking observation from live play: `diety()` in
`d/shadowgate/masters.lpc` prints two `Error: File //d/magic/symbols/
holy_symbol not found` / `File //d/shadowgate/setter_object not found`
lines while restoring a saved character's inventory (a literal
double-slash in whatever wrote those two auto-load entries originally,
most likely from this same session's own test churn while `_finalize()`
was still broken and briefly created/lost the setter_object item mid-
inventory-load) -- cosmetic, does not block login or play; left
unfixed as content/save-data noise, not a code bug, and did not recur on
freshly-created accounts.

## 6. Admin account

- **id**: `fluffos`
- **password**: `Mud@2026`
- Registered through the normal registration flow above (real driver,
  real prompts), then promoted directly via save-data + ACL-database
  edits (no safe in-game bootstrap path exists for the very first admin
  on this lineage -- `_wizmaker`/`_xmote` both require the *caller* to
  already be a privileged/arch account, and `enable_wizard()` -- the
  actual FluffOS efun this codebase's `setup()` calls, gated on
  `query_position() == "creator" || "Admin"` -- has no ACL of its own
  besides "must be interactive"):
  1. `adm/save/users/f/fluffos.o`: `position "newbie"` -> `position
     "Admin"` (also bumped `level 1` -> `level 250`, matching this
     lineage's own `_wizmaker.lpc` builder-level constant, though
     `archp()` itself doesn't check level).
  2. `adm/db/groups.db`: `(superuser): admin` -> `(superuser): admin
     fluffos` (this driver's `wizardp()` maps to a plain `O_IS_WIZARD`
     flag set by `enable_wizard()`, gated on `position`; `archp()`
     additionally requires euid/account-name group membership in
     `assist` or `superuser` -- `fluffos`'s own account name is its own
     euid on this driver, so adding the literal string `fluffos` to the
     `superuser` line is what `archp()`/`check_access()` actually
     consult).
  3. Restarted the driver (both edits are read once at
     boot/first-lazy-load and cached in memory).
- Verified: logged in as `fluffos`, `update /std/user` returned
  `/std/user: updated and loaded.` -- the canonical read+compile ACL
  check per AGENTS.md S1.5 (`update /adm/obj/simul_efun` itself
  correctly refuses with `couldn't destruct`, a driver-level protection
  on the simul_efun object regardless of privilege, not an ACL denial --
  don't mistake that one for a failed grant).

## 7. WASM status

Not attempted this pass (native-driver bring-up only, per this task's
scope) -- `wasm_status` left empty in `meta.json`.
