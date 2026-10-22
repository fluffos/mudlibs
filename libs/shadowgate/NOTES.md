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

Measured 2026-09-03 against the shared `~/src/fluffos/build-wasm`.
No mudlib-side compile fix was needed. Verified with
`scripts/wasm_client.js`: `fluffos` / `Mud@2026` as "Fluffos, A heavy
other elf with azure eyes and silver hair", `score` showed fighter /
swashbuckler, `quit` printed "We hope you enjoyed playing" /
"Have a nice cake!" / "Fluffos has left the game." Shop/combat/death
were not exercised this pass.

## 深度功能测试 / §10.7 deep functional test (2026-08-31)

Round-two pass, native driver (`build-debug`), continuous session. Test
character: `Fluffosc` (fighter, human/morinnen, real chargen with
`select random`/`recommended`/`done` per the section-5 pattern above),
kept as evidence -- save at `work/data/...` under the standard
per-account path (`f/fluffosc`). Admin `fluffos`/`Mud@2026` used for
setup/inspection only (`eval`, direct `move_player()`/`add_money()`
calls to skip unreachable multi-hour travel through a 44,500-file
world) -- all player-visible mechanics themselves were exercised
through the ordinary mortal command set, not bypassed.

### Two real bugs found and fixed

**1. `daemon/feat_d.lpc:1464` -- another confirmed instance of AGENTS.md
S7.118's `.c`->`.lpc` filename-slice-arithmetic class (6th+ instance
this project has hit): the feat-catalog directory scanner's own
extension check never matched, so `__ALL_FEATS` stayed permanently
empty and every player-facing feat-browsing command (`feats list`,
`feats list <category>`, `feats list categories`) silently printed
NOTHING -- no error, no text, just a bare prompt -- for every player,
always, since the very first boot. `feats allowed`/`feats add
<name>`/automatic class-feat-granting on level-up all kept working
because they resolve feats via direct file paths
(`/cmds/feats/<letter>/_<name>.lpc`) rather than through this category
index, which is exactly why this went undetected by both the compile
sweep and the onboarding smoke test -- it's a pure silent-no-output
bug with zero compile error and zero functional-looking absence (the
game just never seemed to have a browsable feat catalog at all).
`build_feat_list()`'s loop over each feat-type subfolder's files did:

```lpc
if (strsrch(files[y], ".lpc") != (strlen(files[y]) - 2)) {
    continue;
}
```

`strsrch(x, ".lpc")` on a real 4-character-extension filename returns
`strlen(x) - 4`, never `strlen(x) - 2` -- so this `continue`d on
literally every single file in every one of `/cmds/feats/{a..z}/`,
before the mechanical `.c`->`.lpc` rename this correctly checked for a
2-character `.c` extension. Fixed: `- 2` -> `- 4`. Verified live:
`sizeof(("/daemon/feat_d")->query_categories())` was `0` before the fix
and `67` after (via `eval` + `update /daemon/feat_d`); `feats list` in
a real player session went from a silently empty response to the full,
correctly-formatted two-column feat-category listing (ArcaneSpellcraft,
ArmorMastery, DamageResistance, Duelist, WeaponDamage, etc.). Grepped
the whole tree for the same `strsrch(X, ".lpc") != (strlen(X) - N)`
shape for other N -- this is the only live instance.

**2. `daemon/yuck_d.lpc`'s inventory-backup subsystem -- another
instance of the AGENTS.md S7.11 missing-runtime-directory class this
lib's own onboarding NOTES.md section 4 already found and partially
fixed, but one bucketed directory tree that pass missed: `/inv/backup_inv/<letter>/<account>/`.**
`backup_inventory()` (called from the ordinary `save_inventory()` path
on every ordinary `quit`, gated on "has been online 20+ minutes")
calls its own `assure_save_dir_exists(path)` before saving each carried
item -- but that function's fast-path branch for a 4-segment path
(`elems = explode(file,"/")`, `sizeof(elems)==4`) only ever `mkdir()`s
the immediate parent (`let_path`) and the leaf (`name_path`); `mkdir()`
on this driver is not recursive, so when the GRANDPARENT
(`/inv/backup_inv/` itself) is *also* missing -- true on every fresh
checkout, since `/inv/backup_inv` isn't among the directories this
project's own runtime-write-directory seeding created (only the
unrelated flat `/inv/<letter>/<account>/` used by the *primary* save
path was covered) -- both `mkdir()` calls silently no-op and every
subsequent `save_me()` into that still-missing path fails with `Could
not open /inv/backup_inv/<letter>/<account>/obN.o.tmp for a save`,
confirmed live on `Fluffosc`'s own first `quit` past the 20-minute
mark (visible only in the driver's own captured stdout, per this
lib's own S10.9-relevant note that `debug.log` and this driver's
stdout are NOT interchangeable -- but empirically both channels
carried this specific message here). Fixed the same way section 4's
instances were fixed: created the full `a`-`z` bucket set under
`inv/backup_inv/`. Verified the underlying mechanism directly (rather
than waiting a further 3 real hours for the per-account backup-timer
gate in `BACKUPS[name]` to re-arm): `mkdir("/inv/backup_inv/f/fluffosc")`
and a follow-up `write_file()` into it both failed with "No such file
or directory" before creating the letter buckets, and both succeeded
immediately afterward -- confirms the fix, though the natural
20-minutes-online code path was not re-observed succeeding live within
this session's time budget (flagged honestly rather than presented as
directly re-verified through the original trigger). Neither finding
above needed a new AGENTS.md catalog entry -- both are further
confirmed instances of already-catalogued classes (S7.118 and S7.11
respectively).

### What was tested and confirmed working

- **Skill/feat acquisition, organic path**: the class-trainer-NPC
  path (`d/shadowgate/masters/fighter.lpc`-family) was already
  exercised during chargen per section 5 above (deity/class-special
  selection). This pass additionally exercised the *level-up* feat
  path, this lineage's actual primary "learn a new ability" mechanic
  (a d20-style class/feat system, not a traditional "find a teacher,
  `learn <skill>`" verb) -- gained a real level via the newbie `mass`
  object's first scripted task (dig up a black gem in an
  auto-assigned meadow room, `feed` it to the mass for exp), which
  correctly triggered `ADVANCE_D->advance()` -> `add_class_feats()`,
  printing real per-feat grant/reject messages (`Adding class feat
  bravery` / `You do not meet the prerequisites for the feat medium
  armor proficiency` for a level-2 fighter, correctly gated). `advance`
  issued directly in the (non-training) town square correctly refused
  with "You are not yet experienced enough" rather than crashing.
  `feats allowed` correctly reports the class's real bonus-feat
  budget (1 general + 1 racial + 3 martial bonus feats at level 2).
  The archive's own std/trainer.lpc-based weapon-proficiency-training
  NPC system (`apply prof to <skill>`, a *second*, distinct
  skill-training path gated on fighting a specific safe trainer NPC)
  exists in the code but its one newbie-zone placement
  (`d/newbie/mon/mortius.lpc`) is only ever loaded from a room under
  `d/newbie/rooms/town/old/` -- apparently superseded, dead legacy
  content, not reachable from the live newbie zone -- not exercised
  live; flagged as unverified rather than silently presented as tested
  (this is a content/placement gap, not chased further per this
  project's "deeper content bugs logged, not necessarily fixed"
  policy).
- **Safe-sparring combat mechanism**: `d/shadow/coliseum/room/training1.lpc`'s
  `retrieve dummy`/`return dummy` (spawns/despawns a real
  `d/shadow/coliseum/mon/dummy_weak.lpc`, HD 1/1, 100 HP, `die()`
  overridden to just narrate "cracks and splinters" rather than
  anything punitive) is this lib's designated safe newbie-combat
  target. Fought it twice, once unarmed (bare-hand combat, `kill
  dummy` -> full turn-by-turn "You hit Dummy"/"Dummy hits you
  ineffectively"/occasional real "Dummy hits you" narration, correct
  HP tracking, correct exp gain on the dummy's real death: 2,001 ->
  2,103) and once wielding a cloned short sword (`wield sword` ->
  armed combat, including a `(Critical) You hit Dummy.` crit-narration
  line) -- both fully correct, no crash, no eval-cost issue despite a
  fairly long fight. `flee` mid-combat correctly moved the character
  out of the room to an adjacent one. No real (non-training) combat
  was risked given a fresh level-2 character's fragility on a
  44,500-file world with unknown wandering-monster danger near the
  newbie zone.
- **Inventory/equipment**: `wear`/`remove` round-tripped correctly on
  both a ring (`A pure white ring` -- correct "gem begins
  illuminating"/"dims" flavor text) and a holy symbol; `wield`/(dummy
  fight above) confirmed a wielded weapon is actually used in combat
  resolution, not just cosmetic. A size-mismatched hat correctly
  refused with "That is too large for you" rather than a silent/wrong
  equip (a real design gate, not a bug).
- **Shop/economy**: the Offestry clothing shop (`Adresa, the Offestry
  seamstress`) -- `list` (paginated inventory with AC/MaxDEX
  columns), `buy hat` (id-based match, not full-name match -- matches
  this shop's own `help shop` documentation), correct multi-denomination
  coin change (1 gold spent on a 4-silver item correctly returned 1
  silver + 1 electrum change), `i` (shop-context "evaluate your
  inventory" listing with sell values), and `sell hat` (correct payout)
  all worked correctly end-to-end with real player-held gold (granted
  via admin `add_money()` since a level-1/2 newbie starts with none --
  flagged here as an admin-assisted setup step, not a live-earned-gold
  path, since no gold-earning activity was reached in this session's
  time budget).
- **`quit`, stdout/debug.log grep, reconnect after a real gap**: two
  full `quit`/reconnect cycles run (the second after the ~25+ minutes
  of wall-clock time this whole pass took, comfortably a "real gap").
  Both quits produced the correct "we hope you enjoyed playing..."
  banner and clean disconnect; reconnecting with the same
  name+password both times correctly restored the saved character
  (level, exp, room location -- including the coliseum training room
  the character was in, not reset to a default start room) rather
  than re-running chargen. One pre-existing, already-documented-above
  (section 5) cosmetic issue recurred identically on both restores:
  `Error: File //d/magic/symbols/holy_symbol not found` during
  inventory reload -- confirmed still non-blocking, not a regression,
  not re-investigated further.
- **Long-sit boot watch** (no WASM build exists for this lib, per
  `meta.json`'s empty `wasm_status` -- used the native-driver
  equivalent per this task's instructions): a raw `mudclient.py`
  connection held open at the login-name prompt for a full 220
  seconds (`--idle 220 --timeout 220`) produced only the expected
  server-side "Login timed out." disconnect, no crash, no unexpected
  output. Grepped the driver's own captured stdout across the entire
  ~34-minute test session (not just this one idle window) for error
  signatures -- the only non-cosmetic hits were the two bugs fixed
  above (both since resolved) and the already-known-benign
  `Unable to open log file: "log/debug.log"`/monsters-database-missing
  lines (the latter already correctly self-guarded in the archive's
  own `daemon/monster_d.lpc`, confirmed by reading the code -- a
  graceful "start empty" fallback, not a crash). Driver RSS stayed a
  healthy ~2.2GB after the full session (registration, meadow-quest,
  shop, two dummy fights, two reconnects); process never needed
  intervention.
- **Death/respawn**: NOT reached live this pass -- flagged honestly as
  unverified rather than guessed at. No safe admin-assisted death path
  exists for an interactive player on this lineage (`slay` explicitly
  refuses interactive targets: "you still have to kill players by
  hand"), and no `die()`-equivalent entry point for players was found
  in `std/living.lpc`/`std/battle.lpc` within this session's time
  budget (this AD&D-style engine's real death/wound resolution lives
  somewhere deeper in the class/combat files not yet located). Forcing
  a genuine death by fighting something dangerous enough was judged
  too risky for a fresh level-2 test character given the size and
  unfamiliarity of this 44,500-file world's newbie-adjacent zones.
  The newbie `mass` object's own multi-stage task chain (graveyard
  item retrieval, then a keep/rescue quest) was also not completed --
  each is a genuine multi-room fetch-quest requiring real exploration
  time beyond this pass's budget; the mechanism up through task 1
  (dig/feed) was confirmed working, tasks 2+ unverified.

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 1 line(s) in 1 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-04）— `<../x.h>` includes resolve: 3 more files load

3 files in old areas (`d/dragon/old/sewer/fall1.lpc`, `d/dagger/derro/old/mon/elemental.lpc`,
`d/islands/common/eldebaro/eldebaro/ob/runestone.lpc`) include a header named relative to themselves in angle brackets; the
driver refuses `..` in a `<...>` name. `adm/obj/master.lpc` now answers `include_file()` with `"./" + path` (KB 04 §6.1) and all
three load. The lib's warnings pass has not been done (unused locals in the master, redeclared `ac`/`size` in
`derro/old/mon/elemental.lpc`).

## 深度功能测试（§10.7，2026-10-05）— 主控 author_file()/domain_file()

驱动的 mudlib_stats 包在主控载入时各调用一次 `author_file(<主控文件>)` 和 `domain_file("/")`，要求返回字符串。本库这两个 apply 只为 domains / realms 目录下的文件返回名字，其余返回 0，所以每次启动都打印 `author_file() in the master file does not work, using root_uid as fallback` 和 `domain_file() in the master file does not work, using bb_ui as fallback` 两行，网页版每位访客的终端里都看得到。`adm/obj/master.lpc` 改成与 fluffos 组织维护的 Dead Souls 上游（`deadsouls_fluffos`）相同的写法：其余文件的域返回 `"BACKBONE"`，作者返回 `"NONAME"`。域等于 backbone 域时驱动让对象沿用创建者的域，与返回 0 时相同；作者统计（`author_stats()`）多出一行 `NONAME`，汇总 realms 目录以外的对象（KB 06 §7.222）。用 `lpcc config.fluffos /nonexistent.lpc` 前后对比，主控载入段只少了这两行。

## 2026-10-06 — `protected private`

`adm/daemon/services.lpc` 的 `build_mudlist()` 声明为 `protected private`（早期把 `static` 换成 `protected` 时留下的两个访问修饰），FluffOS 报 `Multiple access modifiers`；改为 `private`。该文件仍因缺少 `NETWORK_D`（本驱动没有网络包下的互联服务）无法编译。

## Deep test (§10.7, 2026-10-07) — messages cut by a stray `;`

`std/class/crypt_stalker.lpc` and `shadowdancer.lpc` prerequisite text: a stray `;` ended the string early, so "10 Ranks spent in Survival skill", "Undead Favored Enemy" and "10 Ranks spent in Athletics Skill" were never shown. Joined.

Changed files loaded at HEAD and in the tree in fresh processes: no regression.

## 深度功能测试（§10.7，2026-10-10）— 编译警告整理

`scripts/lpc_warnings.py shadowgate --fix` 加 `scripts/lpc_fix_no_effect.py --apply`，共改动 3256 个 `.lpc` 和 3 个 `.h`（多为删去未用的局部变量）。HEAD 与工作树分别加载（新进程）：3002 -> 3002 通过，无回退；改过的头文件的 76 个包含者 63 -> 63 通过。启动时警告 39 -> 0；新进程登录（输入名字）正常。
整库对比的 2 个“回退”已逐个核对：`/d/atoyatl/tecqumin/jungleh/rooms/tun_entry` 单独载入通过（批处理伪影，`/d/deku/keep/monster/prisoner` 则反向翻转）；`/d/azha/mon/impguard` 在 HEAD 也随机失败——随机三选一的装备里 `/d/tsarven/equip/ghalberd.lpc`、`gshield.lpc` 从不存在，`new()` 出错中断 `create()`，且三个 `case` 没有 `break`。`impguard.lpc`、`s-impguard.lpc` 改用现有的 `/d/tsarven/equip/ihalberd.lpc` 与 `/d/azha/equip/ishield.lpc` 并补上 `break`，此后连续 6 次载入都通过。`adm/include/conf.h`、`config.h` 重复定义的 6 个宏照 sunshadow 的做法在 `#define` 前加 `#undef`，启动警告 39 -> 0。审计标出的 3 个未载入文件均为误报（`east_limit(path)` 是函数调用；`qcs` 仍在声明中）。登录（英文提示）手工核对，HEAD 与工作树回应相同。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查

逐条阅读 72 条 `Expression has no side effects` / `Value of conditional expression is unused`（能编译的文件中），另在全库 grep 同形代码，72 条全部处理（无遗留），另补改 4 处未在清单内的同形代码。共改动 66 个 `.lpc`。

- **`==` 当 `=`**：`daemon/quests_low/mid/high` 的 `__Removal`；`d/azha/daemon/overseer` 的 `resetMons`（为 0 时 `0 + ({ add })` 出错）；10 个任务 NPC 的 `step3`（ghostking、ghostshaman、imp、kreeyan、musond、nerussa、sirith、malturkurk、grakulan、ulfgar；`step3` 从未被读取，无可见变化）；`rooms/spell.lpc` 的 `prof = FULL_EFFECT`（无熟练度时效果为 0 而非满效）；`tabaxi/obj/cauldron` 的 `desc += ", "`（可装填物列表原先没有逗号分隔）；`oasis` 的初始葡萄/兰花数；`pest`、`stalker` 的 `FLAG`；两把 `mining_pick` 开工时 `count = 1`（中途放下镐后再挖会从中段接着数）；`undead/tomb/chamber` 的 `found`。清单外：`std/battle.lpc` 及其测试副本 `d/deku/hhouse/inherits/test/battle.lpc` 的 `reset_scrambles()` 写成 `iteration == sizeof(combatants)`，循环一次也不跑，战斗结束后 scrambling 状态从未复位；`d/antioch/valley/obj/nymph_dress_in.lpc` 的 `yy == random(10)+1`，高魅力的裙装描述从不出现。
- **运算结果丢弃**：`_sweepingblow` 的 `num - 1` → `num = -1`（照 `_whirl`/`_spinning_kick` 的 `hit = -1`：被闪避的一击不再算作“落空”而让施放者失衡）；`silvanus/cube`（两份）`myExp /= 2`（迷你任务经验减半，代码本意）；`maze_builder2/3`、`sign` 的 `room_number`；`ram3` 的饮料计数 `uses -= 1`/`uses2 -= 1`，茶壶误用威士忌的 `uses`，改为一直无人使用的 `uses3`（之前三种饮料可无限倒）；`d/deku/monster/bheur` 的 `list - ...` 四行改 `-=`（老巫婆瞬移时排除禁入房间、当前房间和 fire_tunnel）；`std/vendor` 的 `enchant = enchant ? enchant : 1`（在 if 内，行为不变）。仅删除：`_tax` 的 `MyTime;`、`_heal` 的 `sdamage;`、`spell_research` 的 `keyword_index[words[j]];`、`demon_footman` 的游离属性数组、`axlhaina`/`ogre2` 的 `obj == ("corpse")`（`obj` 已由上一行赋值）、三份 `lightstone` 的 `isLit;` 改为 `isLit = 0;`（初始未点亮，行为不变）。
- **逗号表达式**：`d/laerad/lgnolls` 的 4 个豺狼人（含清单外的 `gnollhunter`，该文件另有语法错误仍无法载入）与 `worg_tooth` 的 `do_damage("torso",(2,20)+20)` 只取逗号右值（固定 40/40/8/17 点），改为 `roll_dice(…)`；`archer` 的 `for(i=0;level, i<level;i++)`；`river.lpc`（`rooms/` 与 `base_files/` 两份）的 `direction += (ob, PORT)` 对映射加整数会出错，按房间其余代码的标量用法改为 `direction = PORT; progress = 5;`（`enter()` 无人调用）；`obsidian_orb1`（两份）的 `target = (str, …)` 补回 `present(`，并改为在房间里找目标（原先只能喂自己背包里的东西，`str` 为 0 时会出错）；`_freeze` 游离的 `( {caster, target} )` 放回 `tell_room` 的排除参数（另修同处 `tell_object(...)+"\n"` 的括号）；`underdark/inherit/spiderarches`、`ud_ruins/cliff/shrine1` 的 `(("passage","passages"))` 只剩最后一个 id，改为数组。
- **丢失 `return`/赋值目标**：`guilds/virtual/field_server` 的 `query_listen()` 补 `return`（战场听觉描述从不显示）；`std/races/orc` 的 `default: return 0;`；`rumours_d` 的三个来源后缀改为 `fb += …`（“They've been gossipping about you” 原先没有下文）；`persnoop` 的 `default: words[i];` 改为 `break`。
- **空 if / `if (x);`**：`daemon/search_d` 的 `is_item_locked()` 写成 `if (locked > 0); return 1;`，对任何已登记物品都答“已锁定”，改为按标志返回；`std/tobj` 的 `do_trap()` 同形，去掉分号；`adm/daemon/ipc`、`daemon/multi_d`、`daemon/unique_d` 只含注释的 if 并入注释。

另外顺手修正 overseer `add_timed_monster()` 里从未赋值的 `ob`（无调用者）。未运行格式化器，以保持差异最小。HEAD 与工作树新进程分别载入改动的 66 个对象：63 -> 63 通过，无回退；未通过的 3 个（`_freeze`、`gnollhunter`、测试用 `battle`）在 HEAD 同样无法载入。改后这些文件的“无副作用”警告 74 -> 0。66 个对象载入无回退。

- 2026-10-11 补记：`d/deku/weapons/winters_chill.lpc`（冬寒法杖）`query_charges()` 声明为 void 却 `return charges;`，`failure()` 为 void 却 `return 1;`；sunshadow 下整份不编译，`d/deku/monster/bheur.lpc` 一半几率 clone 它而载入失败。改为 `int query_charges()`、`return;`（调用方不取返回值）。

## 深度功能测试（§10.7，2026-10-12）：编译警告收尾

能编译的文件中的警告从 34447 条（5517 个文件）降到约 200 条（2 个文件：`d/atoyatl/tecqumin/obj/table.lpc` 与 `d/laerad/dojo/obj/shield.lpc`，各达到驱动的 100 条上限，见文末“遗留”）。几乎全部来自少数几个根源，按根源修，而不是逐个叶子文件修：

- **`adm/include/priest.h` 里写着 `inherit SPELL;`**，而 158 个牧师法术又自己 `inherit SPELL;`，于是每个法术里有两份 spell.lpc（每个法术约 26 条重复声明、4106 条 `inherited from both`）。`::create()` 走第一份，其余函数走第二份，两份变量各管各的。头文件不再继承，叶子保留自己的 `inherit SPELL;`；原来靠头文件继承的 18 个法术补上这一行。`_mass_cause_*_wounds`（继承 `_mass_harm`）和 `godsfavor`（继承 OBJECT）也包含 priest.h：此前 `::create()` 走的是头文件那份 spell 的 create，`_mass_harm` 和 OBJECT 的 create 从未执行；现在走对了。
- **`std/living/body.lpc` 的 `ac`、`size` 与 Object 链里 `decay.lpc` 的 `ac`、`move.lpc` 的 `size` 同名**（各约 4100 条，每个生物和玩家都报）。body 的两个都是 nosave，改名 `body_ac`/`body_size`（全库没有别的文件直接读写这两个变量）。
- **`std/room.lpc` 的 `flag`**（只在 reset() 清零）与 15 个区域房间基类各自的 `int flag` 同名（约 1060 条）。改名 `room_flag`；真正依赖它被 reset 清零的 5 个房间（`d/dagger/derro` 的 c21/c35 及其 old 副本、tonerra 的 m4）跟着改名。`std/townsman.lpc`、`std/caravan.lpc` 的 `path`、caravan 的 `speed` 与 monster.lpc 的同名变量是两回事，改名为 nosave 的 `event_path`/`caravan_path`/`caravan_speed`。
- **重复继承**：`lpc_diamonds.py --fix-redundant` 删掉 82 行多余的 `inherit`；另有 12 处要人工判断（先列出的基类先被 `::create()` 选中，§7.240），删掉后改由子类的 create 执行：`hutentry`、`hid38`、`cave12`、`lk1`、`unshield`、新手路 road39-41 等；`mine2/rooms/secret1` 的 `room::create()` 改为 `mine::create()`；`foothills14` 的 `ROOMS"foothills.lpc"` 与 `FOOTHILLSINH` 是同一个文件。
- **两个完整类的拼合**：`concourse`、`pass_parent`、`forest/road1` 三个房间基类从 ROOM 改为 VAULT（VAULT 就是带门的 ROOM），其叶子 `concourse5`/`pass1`/`mainroad6` 去掉自己多加的 VAULT；`Torm/city/c146`（地牢 + 牢房类）只继承 jail_cell 并抄入 cellar 的房间文字；`newtharis/rooms/north5`、`yuki/rooms/barn`、`silesse/clearing`、两个 `shadow.dock` 同样只留功能类（rquestroom、hitching_post、pier、sea/dock，河码头留 dock4 并抄入 river_dock 的四个成员）；`bpeak/rooms/criver` 去掉 bcave1（它的 init() 顶掉了 pier 的钓鱼命令）；`std/obj/ring` 去掉 artifact（只有它用）；`d/magic/etc/d_robe` 改为 PARMOUR（带口袋的护甲本来就是这个类）。
- **真错误**：
  - `d/shadow/room/troll/mon/` 的 7 种巨魔把 TYPE、LONG、POWER、遗言、问候语写成重新声明的全局变量，troll.lpc 的 `set_em_up()` 读的是自己那份空值——每只巨魔都叫“Troll ”、没有描述。改为在 create() 里赋值后再 `::create()`。
  - `std/user/tsh.lpc`：history 与 pushd 栈都定义 `alloc()`/`enqueue()`，后继承的栈胜出，history 自己调用的 `enqueue(cmd)` 把每条命令塞进 pushd 栈，命令历史从不记录。tsh 显式定义两者转给 `history::`（failsafe 副本同改）。
  - `d/darkwood/room/road10` 多继承了 DAEMON：它的 `clean_up()` 无条件 destruct，房间会连人带物被清掉。删去。
  - 法术叶子重复声明 spell.lpc 的 `caster`/`place`/`target`/`clevel`/`cname`/`arg`（182 个声明子删去）：叶子读到的是自己那份，从未赋值时就是 0。`duration` 在 spell.lpc 里是“有持续时间”的标志，与叶子自己的时长含义不同，23 个文件改名 `spell_time` 而不是合并。
  - `adm/daemon/astronomy_d`、`include/crafting.h`、`common_destinations.h`、`class_spells.h`、`spell_domains_spells.h`、`_rumors`、`_elemental_aura`/`_elemental_body_i`：先 `mapping X;` 再在文件顶层写 `X = ([...]);`——老式 LPC 的隐式声明，等于第二个同名变量。合并为一条带初值的声明。
  - `std/tobj.lpc` 把 `unique_item`/`unique_lease` 声明了两遍；`faris`、`grolin`、`sandling` 同一个变量在文件里声明两次（sandling 第二次还声明成 int）。
  - `_kiss_of_beshaba` 的 switch 里多了一对花括号和一句 `return 1;`，整份不能编译；修正后能编译（载入仍失败，与 HEAD 相同，`set_spell_level(3)` 未查）。
- **字符串函数指针 `(: "name" :)`**（58 处）：本库的 `search`/`items`/`read` 处理器原本就是“求值得到函数名再 call_other”（大量 `(: TO, "fn" :)` 写法依赖这一点）。`std/room/senses.lpc`、`items.lpc` 和 `Object.lpc` 的 read 改为：FP_FUNCTIONAL 指针照旧，真正的函数指针直接以参数求值；`Object::set()` 只为旧式指针登记 `function_X` 属性。各处改成 `(: name :)` 并补前置声明。`set("aggressive", ...)` 在 monster 里只认整数和字符串，bushtiger 的指针从未生效，改为字符串并让 `attack_function()` 在没有参数时取 `this_player()`；`daemon/help` 的 `more` 结束回调是字符串指针，菜单“按回车继续”从不出现，改为 `(: endmore, category :)`；`drow/rooms/city22` 的 `search_it` 全库都不存在，删去这条 search；`_mmap` 的 `allocate(n, (: "." :))` 改为直接给字符串；`puzzle_daemon` 的裂缝描述改为 `(: call_other, room, "crack_description" :)`。
- **未知转义**：`daemon/pictures/pictures.h` 的 ASCII 图里反斜杠是画的一部分，改为 `\\`；`cardpics2.h` 的 `\/` 本意是 `/`（真正的反斜杠已写成 `\\`），删去反斜杠；另有 `signet_ring.h`、`items.h`、`story.lpc` 各一处。
- 其余：33 处宏重定义加 `#undef`；`/*` 嵌在注释里的 6 个文件；多余的 `;`；几个未用局部变量；`std/room.lpc` 定义 `initiate()` 调用 exits 与 senses 两份；`std/adt/cstack.lpc` 的 `size` 改名 `cq_size`；`finger_d`/`ava_finger_d` 的工作变量改名，不再顶替用户躯体的私有变量；`psi_comp_bag` 不再重复包含 `spellcomponents.h`；几十个叶子与基类同名、含义不同的变量改名（行为不变）。

遗留：`d/atoyatl/tecqumin/obj/table.lpc` 是会走路的桌子，既是 MONSTER 又是容器（bag_logic），两个完整类都要用，需要重新设计，未动。`d/laerad/dojo/obj/shield.lpc`（盾牌兼剑鞘）去掉 mshield 后因缺 `set_armor_prof`/`set_block_chance` 载入失败，已还原。`d/magic/obj/rebirther`（复生选择物件）`#include <user.h>`，于是它同时是 OBJECT 和一具玩家躯体；它的 `do_rebirth()`/`do_death()` 从 user.lpc 抄来，`save_player(...)`、`query_currencies()`、`add_money()` 等都作用在它自己身上（金钱转移对象为空，`save_player` 存的是这具空躯体）。去掉 user.h 后这些调用无定义、载入失败（本库主控把编译错误只写进日志，扫描看不到，HEAD 对比载入才发现），已还原，留待按原意改成作用于 `reborn`。

验证：改动的 474 个文件加包含改动头文件的文件，共 2666 个对象在 HEAD 与工作树的新进程中分别载入：2665 个对象载入无回退（唯一的回退即上面还原的 shield）。`lpc_audit_removed_locals.py` 列出的 83 条全部是巨魔叶子里改成赋值的声明。

- 补记（同日，移植到 sunshadow 时发现，两库同改）：`d/guilds/order/` 下 84 个守卫/兵士定义 `object *query_party(){return parties;}`，覆盖了 living.lpc 返回队伍名字符串的 `query_party()`，任何按队伍名比较这些 NPC 的代码拿到的是数组；改名 `query_guard_party()`（全库无调用者）。`std/plate.lpc` 的 `wearit()` 声明为 void：body.lpc 在穿戴函数答 0 时拒绝穿上，void 函数答 0，所有用基类 `wearit` 的板甲都穿不上；改为 `int` 并返回 1（原意见注释：拥有者检查已取消）。载入对比：98 个对象无回退。
- 补记：`d/common/mons/questor.lpc` 的 `thank()` 把列表存进 `string thanklist`，改为 `string *`（sunshadow 的严格类型下整份不能编译）。

- 2026-10-14: FluffOS 970d9f09 warns `Float value truncated to int` (#1426). 14 sites in 11 files: assignments, initializers and returns now spell the truncation `to_int(...)` (same value); `x op= <float>` converted the float before the operation (zeroing `x` for a factor below 1) and is now `x = to_int(x op ...)`: `/d/atoyatl/tecqumin/tabaxi/obj/catapult.lpc`（`hp *=`）, `/d/atoyatl/tecqumin/tabaxi/obj/catapult.lpc`（`hp *=`）, `/d/atoyatl/tecqumin/tabaxi/obj/catapult.lpc`（`hp *=`）, `/daemon/combat_d.lpc`（`defend *=`）, `/daemon/world_events_d.lpc`（`exp +=`）, `/daemon/world_events_d.lpc`（`exp -=`）. Changed objects loaded before and after in fresh drivers, no regressions (`scripts/lpc_fix_float_trunc.py`, KB 04 §6.10).
- 2026-10-14 (same rescan, by hand): `d/atoyatl/tecqumin/test/guardcham.lpc` drops its own `int entered` (the base `zig_int_base.lpc` has one and never reads it), as in sunshadow. The three files with whole-class diamonds stay as noted above: `d/magic/obj/rebirther.lpc`, `d/laerad/dojo/obj/shield.lpc` and `d/atoyatl/tecqumin/obj/table.lpc`. Naming winners for their overlapping functions would not remove the variable redeclarations.

- 2026-10-14: 52 files did not compile with `Illegal to inherit after defining global variables`: FluffOS takes every `inherit` before the first global, MudOS did not care. `scripts/lpc_fix_inherit_order.py` moved the globals (and `#include`s of headers that declare globals) written above the `inherit` to just below the last one (KB 04 §6.3). The toolkit round then cleared the warnings the newly loading files showed (0 nosave functions, 0 bare returns, 25 unused locals). HEAD vs tree in fresh drivers: 52 objects, 47 newly loading, 0 regressions.

- 2026-10-14: 9 monsters called `set_new_exp("boss", 70)` with the arguments swapped (the signature is `set_new_exp(int level, string perc)`): the level fell back to `query_level()` and the percentile to `"normal"`, so bosses gave normal experience. Now `set_new_exp(70, "boss")`; the two eldebaro `npc_creator.lpc` passed the level as a string (`"35"`), now `35`. (This config runs with `old type behavior : 1`, which is why the compiler never flagged them.)

## Exits to rooms that do not exist, repaired from the room on the other side (2026-10-18, KB 06 7.257)

A room exit named a file the lib does not have, so the player was stuck (a typo, a renamed room, a numbered room the archive lacks). The room at the other end exists and its opposite exit points back, so that is where the exit was meant to go: `/d/attaya/crafters/desert/des201` `southeast`: `/d/attaya/crafters/desert/des222.lpc` -> `/d/attaya/crafters/desert/des223`; `/d/attaya/crafters/desert/des268` `northeast`: `/d/attaya/crafters/desert/des291` -> `/d/attaya/crafters/desert/des246`; `/d/khalian/stresa/cicatrice/room115` `northeast`: `/d/khalian/stresa/cicatrice/room/108` -> `/d/khalian/stresa/cicatrice/room116`; `/d/khalian/stresa/cicatrice/room134` `west`: `/d/khalian/stresa/cicatraice/room133` -> `/d/khalian/stresa/cicatrice/room133`; `/d/khalian/stresa/cicatrice/room85` `south`: `/d/khalian/stresa/cicatrirce/room100` -> `/d/khalian/stresa/cicatrice/room100`; `/d/khalian/stresa/cicatrice/room92` `west`: `/d/khalian/stresa/cicatraice/room91` -> `/d/khalian/stresa/cicatrice/room91`; `/d/tharis/Tharis/market5` `south`: `/d/tharis/palace/mountain/m32` -> `/d/tharis/Tharis/market8`. Every repaired exit now resolves to a file of the lib (`scripts/lpc_fix_dead_exits.py`; libs whose virtual rooms load anyway are left alone).

## Objects that call an inherited function no parent has (2026-10-19, KB 06 7.259)

`::create();`, `::init();` and `return ::buy_object(who, item);` were written against a parent that has the function; this lib's parents do not, the old driver took the call for a no-op returning 0, and the current driver stops at compile time with `Unable to find the inherited function`, so the object never loads. A call written as a statement is deleted, `return ::f(...)` becomes `return 0;` (`return;` in a void function), which is what the old driver did. 4 calls in 2 files: `::reset()` (1), `::cure_light()` (1), `::cure_serious()` (1), `::cure_critical()` (1). Only files whose every error was this one were edited; a file that also has another error (usually a parent that is itself missing) is left until the parent is restored. (`scripts/lpc_fix_dangling_super.py`)

## Macros the global header lost (2026-10-19, KB 04 6.16)

`/adm/include/std.h` did not define `MOON_DESC`; the objects that use them (1 on the list) stopped at `Undefined variable`/`Undefined function`, and since the compiler stops at the first undefined name the errors and warnings behind it stayed hidden. The sibling libs of the same lineage carry these lines in their headers: the copy of the sibling with the most files in common was added after the last `#define` of `/adm/include/std.h`; every path in a macro body exists in this lib. the listed objects have other errors as well and still do not load. (`scripts/lpc_restore_defines.py`)

## Object paths with two leading slashes (2026-10-19, KB 06 §7.276)

5 file(s), 5 site(s) wrote an object path as `//…` (like `carry_object("//clone/cloth/hic_cloth")`): `/d/azha/town/market2.lpc`, `/d/azha/town/market3.lpc`, `/d/azha/town/market4.lpc`, `/d/azha/town/market5.lpc`, `/d/azha/town/market6.lpc`. The driver these games ran on did not mind (the path was normalised first); this one hands the string to the master's `valid_read()` as written, securityd looks up `//clone`, the NPC's euid has no entry and the answer is `Read access denied.`: the NPC does not load. One slash now.

## The rebirther object: a second copy of the player class and a player it never touched (2026-10-19, KB 06 7.278)

- `d/magic/obj/rebirther.lpc` (the object the rebirth spell puts in a dying player, `std/user.lpc` and `adm/failsafe/user_failsafe.lpc` clone it) `#include`d `<user.h>`, which in this lib is the player's list of `inherit`s, and then `inherit OBJECT;`: two copies of `/std/Object`, more than 100 warnings from that one line (the scan's cap of 100 hid the rest), and an `id()` whose `::id(str)` ran in the copy `create()` never set up (`Value being indexed is zero` from `Object.lpc:919` when `present()` looked at it with an avatar acting).
- The death and rebirth code had been pasted from `user.c` and called `save_player()`, `query_currencies()`, `query_money()` and `add_money()` on the rebirther itself (the living chain supplied them): `save_player(name)` returns when the name is not the object's own, and the money loop moved nothing. Those calls now go to `reborn` (the dying player), `corpse->add_id("corpse of " + ...)` names the player instead of "rebirther999", `set_invis()` is the `set_hidden` / `set_magic_hidden` toggle the living version ran for a non-avatar, and `query_invis()` still answers 1.
- Checked with a fake player that logs the calls it receives, at HEAD and in the tree: HEAD crashes in both `do_rebirth()` and `do_death()` with the `Value being indexed is zero` above and the fake never sees a call; the tree runs both to the end (`save_player("fakeplayer")`, `add_money("gold", -7)`, `add_money("silver", -3)`). The object loads with no warning (HEAD: 100+).
- Left as is: `d/laerad/dojo/obj/shield.lpc` (a shield that is both `sheath_inherit`, a copy of the armour class on top of `/std/bag`, and `mshield`, the real `/std/armour`; `set_block_chance` / `set_armor_prof` exist only in the second) and `d/atoyatl/tecqumin/obj/table.lpc` (`MONSTER` plus `/std/bag_logic`, which inherits `CONTAINER`): each really is two class stacks; removing either side removes functions the object calls.

## Old-driver type slack: missing arguments, untyped parameters, array initializers, `class` variables (2026-10-19, KB 04 6.19, 6.20)

MudOS filled the missing arguments of a call with 0, took an untyped parameter as `mixed`, never compared a declared type with its initializer and let a variable be named `class`; this driver refuses all of it at compile time and the whole object fails. 24 file(s) fixed: `/cmds/skills/bak/_boost.lpc`, `/cmds/skills/bak/_cure.lpc`, `/cmds/skills/bak/_detect.lpc`, `/cmds/skills/bak/_feed.lpc`, `/cmds/skills/bak/_heal.lpc`, `/cmds/skills/bak/_lore.lpc`, `/cmds/skills/bak/_mend.lpc`, `/cmds/skills/bak/_offer.lpc` ... (24 in all) (the repair rounds of `scripts/lpc_round_files.py`: zeros written out at the call, `mixed` for untyped parameters, `string X = ({...})` given its star, void functions returning values, and `class` variables renamed `pick_class`). Loaded at HEAD and in the tree, per file: 24 of them failed before and load now, none regressed.

## Runtime bugs the sunshadow type-slack work found here too (2026-10-19)

`config.fluffos` here sets `old type behavior : 1`, so none of the type slack that stopped 500+ sunshadow files (KB 04 6.19) shows in this lib; KB 04 says not to switch the option on elsewhere, and the sunshadow fixes are what a shadowgate without it would need (`scripts/lpc_twin_port.py classify sunshadow shadowgate --pre 3bfad968f7b`: 49 files carry the same code, 151 differ, 32 are absent here). The same sources hold four bugs that run wrong with or without type checking; fixed here as in sunshadow:
- `d/deku/inherits/foresttraili.lpc` (238 forest rooms): `ob = "/d/magic/obj/treant"; ob->set_hp(...); ob->move(TO)` set up and moved the blueprint, so there was one treant for the whole forest; now `new("/d/magic/obj/treant")`.
- `d/islands/dinosaur/jungle.lpc` / `lakefront.lpc` (114 rooms): `(mapping)TO->query_traps() == ({})` compares a mapping with an array and is always false, so the reset never set the room items and no jungle trap was ever laid; now `!sizeof(TO->query_traps())` and `sizeof(TO->query_traps())` for the three `!= ({})` guards.
- `d/laerad/obj/wand_para.lpc`: `!TP->query_name() == "hansoth"` is `(!name) == "hansoth"`, always false, so the wield requirement its own comment describes (everyone but Hansoth) never applied; now `TP->query_name() != "hansoth"`: the wand has to be wielded.
- `d/antioch/valley/rooms/v6.lpc`: line 1 read `#include <std.h>\` with a stray backslash, which joins it to the next line, so `#include "../valley.h"` was swallowed and `inherit VALLEY;` was an undefined macro (the room never compiled; its siblings `v1`..`v5` have no backslash). Removed.
- Left as is, the third whole-class diamond: `d/mine2/rooms/mine22.lpc` (compiles since `d/mine2/mine.lpc` lost its `class` variable) inherits `mine.lpc` (`/std/room`) and `/std/pier.lpc` (`/std/vault`): two room classes, two copies of every room variable, 101 warnings at the compiler's cap, like `d/laerad/dojo/obj/shield.lpc` and `d/atoyatl/tecqumin/obj/table.lpc`. A probe shows what it costs on `shield.lpc`: after `set_ac(1)` and `set_block_chance(25)` its `query_ac()` and `query_block_chance()` return 0, and dropping the `mshield` chain makes `set_armor_prof()` undefined (the bag-armour class has no such setter), so which class wins is the author's decision (KB 06 7.279).

## `x == "a" || "b"`：后面的字符串常量永远为真（2026-10-19，KB 06 §7.281）

`if (arg == "yuyou" || "yu you")` 里的 `"yu you"` 是非空字符串，永远为真，整个条件对任何 `arg` 都成立；作者要的是每个字符串都和变量比较。具体是：`whisper` 的语言参数永远被改成 wizish。在每个字符串前补上变量和运算符（`scripts/lpc_fix_literal_or.py`；`forrest2.lpc` 是 `dir == "north" && "south"`，手工改成 `(dir == "north" || dir == "south") && ...`）：`/cmds/mortal/_whisper.lpc`（1 处）、`/d/dagger/phederia/rooms/v1.lpc`（2 处）、`/d/dagger/phederia/rooms/v15.lpc`（2 处）、`/d/darkwood/yntala/mon/centaur.lpc`（5 处）、`/d/darkwood/yntala/mon/centaurcl.lpc`（4 处）、`/d/darkwood/yntala/mon/centaurg.lpc`（3 处）、`/d/deku/hhouse/study.lpc`（1 处）、`/d/islands/giant/hill/rooms/r13.lpc`（1 处）、`/d/shadow/city/room/moffice.lpc`（1 处）、`/d/shadow/room/githyanki/27,17.desert.lpc`（1 处）、`/d/shadow/room/githyanki/rooms/0_0.lpc`（1 处）、`/d/shadow/virtual/desert/27,17.desert.lpc`（1 处）。

## `x != "a" || x != "b"` and `x == "a" && x == "b"`: comparison chains of one value that can never differ (2026-10-20, KB 06 7.282)

`if (arg != "wan" || arg != "pill") return notify_fail(...)` is true whatever `arg` is, `dir == "south" && dir == "north"` is never true: the guard under the test never opens, or never closes. The author meant "neither of these" (`&&`) or "either of these" (`||`). `!=` chains joined by `||` became `&&` (only where the statement under the test is a `return`, a refusal or a guard clause), `==` chains joined by `&&` became `||` (`scripts/lpc_fix_cmp_chain.py`). Changed: `/d/antioch/ruins/rooms/graveyard.lpc` (2), `/d/islands/dreams/rooms/fire.lpc` (1). Left as written (the body under the test does something else, `==` and `||` may have been meant): `/cmds/mortal/_abandon.lpc` (1), `/d/darkwood/forest/village/priv1.lpc` (1), `/d/darkwood/forest/village/priv2.lpc` (1), `/d/darkwood/forest/village/priv3.lpc` (1), `/d/darkwood/forest/village/priv4.lpc` (1), `/d/darkwood/forest/village/priv5.lpc` (1), `/d/darkwood/forest/village/priv6.lpc` (1), `/d/darkwood/forest/village/priv7.lpc` (1), `/d/darkwood/forest/village/room1.lpc` (1), `/d/darkwood/forest/village/room2.lpc` (1), `/d/darkwood/forest/village/room3.lpc` (1), `/d/darkwood/forest/village/room4.lpc` (1), `/d/darkwood/forest/village/room5.lpc` (1), `/d/darkwood/forest/village/room6.lpc` (1), `/d/darkwood/forest/village/room7.lpc` (1), `/d/darkwood/forest/village/well1.lpc` (1), `/d/darkwood/forest/village/well2.lpc` (1), `/d/player_houses/aunuit/gates.lpc` (1), `/std/weapon.lpc` (1).

## `query_guild`, `trunk.lpc` (2026-10-20, KB 04 6.21, 6.22)

The 45 Fist troopers (`d/guilds/fist/oldfist/troopers/*.lpc`): `string *query_guild() { return "Iron Fist"; }` is `string query_guild()` (the callers take the string; the `*` was a copy of the player's line), the same edit as in sunshadow; with `old type behavior : 1` set here the declaration never mattered to the compile, and each `create()` still dies on a wizard-directory item the archive lacks (`new("/realms/bane/closed/bracers5")`). `d/tharis/obj/trunk.lpc`: `base_name(inven[i] == "/d/tharis/obj/treething")` is `base_name(inven[i]) == "/d/tharis/obj/treething"` (the misplaced parenthesis handed the result of a comparison to `base_name()`, so the check for the tree thing never worked). Loaded at HEAD and in the tree, per file: nothing regressed.

## Comparison chains: hand fix (2026-10-20, KB 06 7.282)

`d/player_houses/aunuit/gates.lpc`: `race != "drow" || race != "elf" || enemy` called the dragons for every visitor who had not the owner's authority; it is `(race != "drow" && race != "elf") || enemy`.

## `member_array('/', str)` became `strsrch(str, "/")`: the character-literal member_array is a byte search (2026-10-20, KB 06 7.283)

`'/'` in `member_array('/', str)` is an int, so the driver searches the UTF-8 **bytes** and answers a byte offset (a third argument is a byte offset too). FluffOS 923cdbc0 warns once per call site (`Warning: member_array(int, string) searches BYTES`) when the string holds non-ASCII text before the match, and `str[0..idx-1]` counts characters, so a non-ASCII string was cut in the wrong place. Now `strsrch(str, "/")` (-1 when absent, a character index; `scripts/lpc_fix_member_array_char.py`, the JSON encoders and a few other sites by hand). Changed: `/daemon/json.lpc` (11).

## `if (x = CONST)`: a comparison written as an assignment (2026-10-20, KB 06 7.290)

`if (arg = "button" || arg = "pill")`, `if (!arg || arg = "") return 0;`, `else if (check = 0 && tempB != "")`: `=` was typed for `==`, so the condition is the constant: the branch is always taken for a non-zero number or any string (even "") and never for 0, and the variable is overwritten; the driver does not warn. Every such `=` became `==` (`scripts/lpc_fix_cond_assign.py`, 59 terms); the chains the `==` then exposed (`x == "a" && x == "b"`, `x == "a" || "b"`) were completed (`/d/avatars/avatars/helm/astral_shield.lpc`, `/d/avatars/helm/astral_shield.lpc`). Changed: `/cmds/bard/_lore.lpc` (1), `/cmds/spells/a/_animate_object.lpc` (1), `/d/atoyatl/tecqumin/city/rooms/balcony.lpc` (1), `/d/atoyatl/tecqumin/rooms/spell.lpc` (1), `/d/avatars/avatars/helm/astral_shield.lpc` (1), `/d/avatars/avatars/nienne/feycharm.lpc` (4), `/d/avatars/avatars/nienne/mieamulet.lpc` (8), `/d/avatars/helm/astral_shield.lpc` (1), `/d/avatars/nienne/feycharm.lpc` (4), `/d/avatars/nienne/mieamulet.lpc` (8), `/d/common/obj/clothing/magerobe.lpc` (2), `/d/dagger/exchange/horse/storage/horse_master.lpc` (1) and 18 more (30 files).

## A login password over 255 bytes: `crypt()` raises (2026-10-20, KB 06 7.294)

The driver's `crypt()` raises (`Error in crypt(), check your salt`) for a key over 255 bytes, where the old driver hashed any length. A password of 256 bytes or more typed at the login prompt threw an error in the password check and left the connection at a bare `> ` prompt, so the login never completed (the old-password test of `password` the same); found by the sweep shape of 300 `x`. `/adm/obj/simul_efun.lpc` now defines a simulated efun `crypt(key, salt)` of the same name: only an over-long key is cut (to 255 characters, then character by character until `sizeof(to_buffer(key)) <= 255`: the limit is in bytes, a CJK character takes three) before it is handed to `efun::crypt()`; every ordinary password hashes as before and the saved hashes are untouched (`scripts/lpc_add_sefun.py crypt`).

## `darkrobe` keeps a name in an `object` variable (2026-10-20, KB 06 7.305)

`d/attaya/senund/obj/darkrobe.lpc` declares `object OWNER;` but stores the player's name (a string) in it and compares against it: `error: != always true because of incompatible types ( string vs object )`, the robe (and the NPC that carries it) never loaded. The declaration is `string OWNER;` now.

## 药水文件的属性变量叫 `in`（2026-10-20，KB 04 §6.26）

`d/darkwood/tabor/obj/potions/weaken.lpc` 和 `d/shadow/obj/potion/weaken.lpc` 的 `int st,in,wi,de,co,ch;`（力量、智力、感知……的缩写，`in` 是智力）：保留字，`syntax error, unexpected L_IN`，药水加载不了。`scripts/lpc_fix_in_ident.py` 改名为 `in_var`（各 4 处）。加载检查 2/2，HEAD FAIL → tree PASS。

## 移植 sunshadow 的命令、法术、守护进程修复（2026-10-21，KB 04 §6.21，KB 06 §7.329–7.330）

sunshadow 第十七批改的 75 个文件里 74 个对象在 shadowgate 也有同名文件（`lpc_twin_port.py classify`）：13 个逐 token 相同，用 `adopt --apply` 整体采用（`listener`、`_addnwp`、`_alterobj`、`_acheck`、`_callout`、`_blindfold`、`_bury`、`_passwd`、`_skin`、`_rgrep2`、`dlevel`、`treesave_d`、`iqueue`）；60 个有各自的代码，其中仍然加载失败的用补丁逐个移植（`pacct`、`_druids`、`_spell_list`、`letter`、`templefunds_d`、`rn`、`is_druid`、`m_armour`、`m_monster`、`m_room`、`m_weapon`）。shadowgate 自己的归档损伤另有三处：`adm/obj/pacct.lpc` 的 `save_file_name()` 少一个 `}`、`save_pacct()` 的 `actually_save_pacct(name)` 少 `;`；`std/news/rn.lpc` 的 `sprintf("%d-%d", GetLeft(...),num;` 少一个 `)`（都对照 sunshadow 的同一段）；`rn.exit()` 里三个没用的局部变量去掉（warning）。

`daemon/letter`：`for` 循环里的 `if(file_size(DIR_LETTERS+"/"+i) == -2)` 没有花括号，只管下一行 `y += ...`，后面的 `__LettersDir += get_dir(...)` 总会执行；`/secure/save/letters/N/` 不存在时 `get_dir()` 答 0，`+= 0` 抛 `Bad argument 2 to (void)+=`，整个邮件守护进程加载失败（sunshadow 的检查树里有这些目录所以没暴露；两个库一起补了花括号，目录都在时行为不变）。

验证：74 个对象 HEAD 加载 58 个、树 71 个，regress 0，新加载 13 个，没有 warning（`make/m_monster` 的三条是归档损坏，见下）；实机（`play-shadowgate-xq`，机器人）`blindfold`、`bury`、`skin`、`passwd`、`gossip`、`mail`、`news`、`actions`、`buff` 都有正常回答，控制台没有错误。仍然失败的三个：`make/m_monster`（第 741–890 行在归档里损坏，sunshadow 同样）、`adm/simul_efun/sum_array` 和 `std/user/retinue`（shadowgate 没有这两个文件）。

## `map`（不带参数）无限自我强制，`skin <活物>` 调用没有函数体的 `do_live()`（2026-10-21，KB 06 §7.333）

`cmds/mortal/_map.lpc`：`if (!stringp(str)) { TP->force_me("map"); return 1; }`：不带参数的 `map` 强迫玩家再敲一次不带参数的 `map`，一直到 `Too deep recursion`，玩家收到 "contact a dev"（实测）。下面 `switch` 的 `default:` 分支对不认识的参数调用 `help()`，所以不带参数也走 `help()`（`<map view>` 等用法说明）。`cmds/mortal/_skin.lpc`：`skin <活物>` 走 `return do_live(corpse);`，`do_live()` 只有一条原型，归档里没有函数体，调用会出错；活物和其他剥不了皮的东西一样回答 `You can't skin that.`，原型删掉。sunshadow 和 shadowgate 同一处，实测：`map` 打出用法，`map list` 正常，控制台没有错误。

## 战斗探针的孪生问题：Stormbringer 的 `object owned` 和 Freloc 的匕首（2026-10-21，KB 06 §7.305 / §7.269）

sunshadow 的战斗探针找到五个怪物里的 `(string)TO->query_current_attacker() != targ` 在那边编译不了（基类有类型）；shadowgate 的基类没有声明类型，副本能编译，没有动。两处同样的失误这里也有：`d/dagger/marsh/tower/obj/storm.lpc`（与 sunshadow 的字节相同）把 `object owned;` 用来存 `TPQN`：改 `string owned;`；`d/common/assassins/freloc.lpc` 在 `create()` 里两次克隆 `/realms/grazzt/assassins/dagger.lpc`，这个巫师目录档案里没有，`0->move()` 让 NPC 加载就中止（六个文件里唯一失败的一个）：克隆和两条 `wield` 放在 `file_size(...) > 0` 后面。改动：`/d/dagger/marsh/tower/obj/storm.lpc`、`/d/common/assassins/freloc.lpc`。

## 兽人小队、树屋平台和扑克荷官：三个拼错的局部变量（KB 06 §7.348，KB 06 §7.350，2026-10-21）

`orog.lpc` 的 `swing_in()` 问的是没赋值的 `critter`（循环变量是 `critters[i]`）；`t_house_base.lpc` 的 `fly_platform()` 问 `rooms->query_spiked()`，对象是 `room`；扑克荷官 `deal()` 对离开的玩家播报 `absentee->QCN`，应是 `player`（同一个文件里 `sizeof(hand !=2)` 还让它根本编译不了，见下）。改动：`/d/atoyatl/tecqumin/mons/orog.lpc`、`/d/atoyatl/tecqumin/treehouse/rooms/t_house_base.lpc`、`/d/shadow/mon/dealer.lpc`。

## 魔怪 `fiend.lpc`：`a != b != c` 的比较链编译不了（KB 06 §7.282，2026-10-21）

心跳里的 `if (base_name(att[i]) != base_name(TO) != base_name("klauth"))` 先比出一个 int 再和字符串比，类型检查报 `!= always true because of incompatible types ( int vs string )`，这个怪物整个加载不了；改成两个比较用 `&&` 连接。改动：`/d/islands/common/mon/fiend.lpc`。

## `sizeof(x == n)`：括号里放了比较（KB 06 §7.350，2026-10-21）

`sizeof(tmp != 2)`、`sizeof(casualties ==1)`、`sizeof(file_list == 0)` 先算比较再取 0 / 1 的 `sizeof`（本驱动里 `sizeof(1)` 是 0），守卫或提示的分支永远不执行；扑克荷官的 `hand` 是 `string *`，类型检查直接报错，荷官根本加载不了。改成 `sizeof(x) == n`。改动：`/d/atoyatl/tecqumin/tabaxi/obj/catapult.lpc`、`/d/atoyatl/vis_climb_d.lpc`、`/d/shadow/mon/dealer.lpc`、`/d/token_hunt/token_vendor.lpc`。

## 账号登录和 IPC 监视：两个拼错的调用目标（KB 06 §7.349，2026-10-21）

`pacct_login.lpc` 的 `input_to("get__pacct_password", ..)`（双下划线）名字对不上 `get_pacct_password`，输入的密码被吞掉；`ipc.lpc` 的 `call_out("ip_monitor_self", ..)` 对应的函数是 `ipc_monitor_self`。改动：`/adm/daemon/ipc.lpc`、`/adm/obj/pacct_login.lpc`。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 82 条注册（53 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/cmds/guild/philosopher/_cmd.lpc`（`relsoul`）、`/d/antioch/antioch2/d_animal.lpc`（`get_off`）、`/d/antioch/greaterantioch/mon/zathon.lpc`（`ask_em`）、`/d/antioch/wiz_hall/wizard_rm1.lpc`（`peruse_titles`）、`/d/atoyatl/tecqumin/base_files/ropebridge_base.lpc`（`jump_off`）、`/d/atoyatl/tecqumin/city/rooms/balcony.lpc`（`address_city`）、`/d/atoyatl/tecqumin/jungle/rooms/ropebridge_base.lpc`（`jump_off`）、`/d/atoyatl/tecqumin/rooms/t_house_middle.lpc`（`climb`、`fly_platform`、`shoot_rope`、`throw_rope`）、`/d/atoyatl/tecqumin/rooms/treetop_base.lpc`（`swing`）、`/d/atoyatl/tecqumin/rooms/zigzenith.lpc`（`release`） 等共 53 个文件。最多的函数名：`no_kill` 16 处、`dive_func` 5 处、`ask_em` 3 处、`throw_rope` 3 处、`jump_off` 2 处。没有动（读过）：`/d/antioch/greaterantioch/obj/healring.lpc` 的 `use_ring`（对象本身编译不过，登记留着，等对象能加载再处理）、`/d/atoyatl/tecqumin/obj/jung_maze.lpc` 的 `place`（对象本身编译不过，登记留着，等对象能加载再处理）、`/d/atoyatl/tecqumin/obj/tec_maze.lpc` 的 `clear_maze`（对象本身编译不过，登记留着，等对象能加载再处理）、`/d/atoyatl/tecqumin/obj/tec_maze.lpc` 的 `place`（对象本身编译不过，登记留着，等对象能加载再处理）、`/d/atoyatl/tecqumin/rooms/ropebridge_base.lpc` 的 `jump_off`（对象本身编译不过，登记留着，等对象能加载再处理）、`/d/mine2/sandy/room/boat.lpc` 的 `buy`（对象本身编译不过，登记留着，等对象能加载再处理）。
