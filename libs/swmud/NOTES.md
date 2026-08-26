# swmud -- Star Wars Mud

Source: `git clone https://github.com/coupdeforce/swmud` (HEAD at clone
time: `cf33a51`, last pushed 2016-02-16, cloned 2026-08-26). Number 180,
slug `swmud`, port 40227. Status: **done** (clean boot, real registration
+ character creation + `look`/`score`/`who`/`inventory`/admin `update`/
`admtool`/`quit` all verified against a live driver).

## Architecture: this is not a standalone mudlib

swmud's own README says it outright: "This project only includes
additions and changes to the base mudlib. It must be installed over the
current Lima mudlib." Confirmed by inspection -- the raw clone is ~980
files with no `secure/simul_efun.lpc` combiner, no `check_config.lpc`,
no `get_root_uid()`/master security scaffolding, and macro tables
(`include/mudlib.h`, `classes.h`, `commands.h`, `daemons.h`) that
reference dozens of paths outside the archive. This project happens to
already have a full working copy of Lima itself onboarded
(`libs/lima/`, 164, `git clone https://github.com/fluffos/lima`) from
earlier this session, so the AGENTS.md \S2.1 "recognize the lineage"
playbook applies directly, just at a larger scale than usual:

1. `work/` = a full copy of `libs/lima/work/` (already fixed for this
   driver -- see `libs/lima/NOTES.md`), with every file from swmud's own
   converted tree overlaid on top. 852 files are swmud-only additions;
   233 override a same-path Lima file outright (`secure/master.lpc`,
   `secure/daemons/secure_d.lpc`, `std/body.lpc` and 14 of its `body/*`
   submodules, `std/adversary/*`, most of `cmds/verbs`/`cmds/player`,
   the `trans/cmds` "wish" shell command tree, `include/*.h`, etc).
2. Because this driver requires a **different build** for anything
   Lima-based (`NO_ADD_ACTION`/`NO_WIZARDS`/`NO_LIGHT` defined,
   `OLD_ED`/`PACKAGE_UIDS` undefined -- see `libs/lima/NOTES.md` \S
   "驱动编译选项冲突"), swmud reuses that exact driver checkout,
   `~/src/fluffos-lima/build-debug`. It will **not** boot on this
   project's shared default driver.
3. Encoding: swmud's own raw clone is 100% ASCII/UTF-8 except one Latin-1
   copyright symbol (`©`) in `help/wizard/coding/parser`, fixed with
   `iconv -f ISO-8859-1 -t UTF-8` (note: plain `-f latin-1` fails with
   "failed to start conversion processing" on this machine's `iconv` --
   use the full charset name `ISO-8859-1`). `scripts/convert_lib.sh` ran
   with `UTF-8` as the source encoding (i.e. rename + reference-fixup
   only) against a staging copy, then that staging tree was `rsync`'d
   onto the pre-populated `work/` (never run `convert_lib.sh` directly
   against `work/` here -- it deletes and recreates its target from
   scratch, which would destroy the Lima base).

Because two independently-evolved snapshots of a large, deeply
inheritance-based codebase are being combined, most of the real bugs
below are **API mismatches between vintages** -- a file on one side of
the merge calls a function/macro/class that the other side renamed,
dropped, or never had -- rather than classic single-archive conversion
bugs. Two consistent patterns run through almost everything below:

- **swmud's own `include/*.h` rewrites silently dropped macros that
  swmud's own files (or unmodified Lima files still in the merged tree)
  still reference.** Every one of `mudlib.h`, `classes.h`, `commands.h`,
  and `daemons.h` is swmud's own full replacement of Lima's original
  (confirmed: none of the 233 overridden paths above are byte-identical
  to Lima's copy), and each one is missing entries the *other* side of
  the merge needs. This is not something the conversion introduced --
  it's a pre-existing internal inconsistency in the real swmud archive,
  the same class of gap as dsI's missing `LIB_*` macros (see
  `libs/dsI/NOTES.md`) -- just spread across many headers instead of
  one.
- **swmud rewrote several core object-model files (`std/modules/
  m_damage_source.lpc`'s weapon-damage API, `std/adversary/*`'s whole
  combat/limb system, item base classes) with a different API than
  Lima's originals, orphaning Lima's own demo content that still calls
  the old API.** `domains/` (Lima's stock example rooms/monsters/spells:
  Grand Hall wizard start, `V_Plains`, the caves/labyrinth/beach demo
  areas, `fireball`/`magic_arrow`, `troll`/`orc`/`goblin`/`dragon`/`wolf`)
  and a handful of generic `std/*.lpc` files (`sword`, `torch`, `armour`,
  `meat`, `paper`, `water`, `light_object`, `lantern`, `combat_spell`,
  `moving_monster`/`wandering_monster`/`following_monster`/
  `aggressive_monster`, `loot_chest`, `fluid`) are **not** part of
  swmud's real Star Wars game world (that lives in the top-level `d/`
  tree and `domains/std/{ammo,weapon,crafting,monster,spells,rooms,...}`
  content that *swmud itself* authored) -- they're leftover Lima
  teaching/demo content that happens to still be present in the merged
  tree, was never touched by swmud's own commits, and is not wired into
  swmud's actual gameplay. 77 of the 129 remaining `lpcc_check.sh`
  failures are exactly this category. Confirmed non-canonical by cross-
  referencing: none of these files are byte-different from `libs/lima/
  work`'s copy, and nothing in swmud's real content (`d/`, the SW-named
  `domains/std/*` subtrees) inherits or references them. Left unfixed,
  same as this project's standing policy for pre-existing content/
  design gaps (see e.g. `libs/lima/NOTES.md`'s own `WWW/cgi/*`/`contrib/
  marriage/*` entries, or `libs/dsI/NOTES.md`'s "declare war" gap).

## Real bugs fixed (driver-compat / programming, not content)

### 1. Dropped macro definitions (the single biggest bug class)

Systematic sweeps (grep every `inherit BARE_MACRO;`, `new(MACRO...)`, and
`MACRO->call()` site against every `#define` in `include/*.h`) found and
fixed:

- **`include/daemons.h`**: 9 missing daemon-path macros for daemon files
  that do exist (`CRAFTING_D`, `DOMAIN_D`, `EMOJI_D`, `LOOT_D`,
  `MEMCHECK_D`, `PARTY_D`, `RST_D`, `STATE_D`, `TASK_D`) plus `XTERM256_D`
  (used by `std/modules/m_colours.lpc`/`m_frame.lpc`/`m_triggers.lpc` for
  ANSI color support).
- **`include/mudlib.h`**: ~40 missing object-path macros across several
  waves of discovery -- `M_FRAME` (dropped despite 7 `cmds/player/*`
  files still inheriting it, and the module file itself still present
  unmodified from Lima); the whole `M_COLOURS`/`M_CRAFTING`/`M_DICE`/
  `M_HEALING`/`M_LOCKPICK`/`M_POWER`/`M_REACT`/`M_READY`/`M_SALVAGEABLE`/
  `M_SPECIAL_WEAPON`/`M_STATEFUL`/`M_TRAINER`/`M_WIDGETS` module family
  (all present as real files, all in Lima's original table, all missing
  from swmud's); the whole "high-level inheritable" family (`ARMOUR`,
  `AMMUNITION`, `BANDAGE`, `BATTERY`, `BEHAVIOUR_TREE`, `BOARD_OB`,
  `CRAFTING_STATION`, `DRINK`, `ELEVATOR`, `JUNK`, `MATERIAL`,
  `MATERIAL_SPAWNER`, `RANGED_WEAPON`, `SLOWHEAL`, `TAMING_COLLAR`,
  `TRANSIENT`, `ART_OBJECT`, `GEM`, `PELT`); `HEAVEN`; menu/shell
  plumbing (`PARTY_MENU`, `PLAYER_SHELL` -- an exact duplicate of
  swmud's own renamed `PLYR_SHELL`, still needed by unmodified
  `secure/user/shell.lpc`, `TASKTOOL`, `USER_MENU`, `CONFIG_EDITOR`,
  `CMD_OB_TASKTOOL`, and the whole `CMD_OB_{EMOJI,FRAMES,METRIC,MODE,
  SIMPLIFY,WIDTH}` family used by `obj/mudlib/plmenu.lpc`); and three
  application-specific paths inferred from their sole call sites rather
  than a Lima precedent (`CRAFTING_ITEMS` = `/domains/std/crafting/`,
  `IMUD_CHANNELT_DUMMY` = `/obj/mudlib/ichannelt`, `MAKER` =
  `/contrib/roommaker/buildmenu`, `SNOOP_DUMMY` = `/obj/secure/
  snoop_dummy`).
- **`include/classes.h`**: `CLASS_EFFECT` and `CLASS_WEAR_INFO` (both
  target files -- `std/classes/effect.lpc`, `std/classes/wear_info.lpc`
  -- present and unmodified; swmud's own `std/living/effects.lpc` and
  `std/adversary/armour/limbs.lpc`/`cmds/player/equip.lpc` still
  `inherit` them by macro name).
- **`include/commands.h`**: `TRANS_ADMINCMD_DIR`/`CMD_DIR_ADMIN`
  (target dir `/trans/admincmds` present and populated -- without this,
  `trans/obj/wish.lpc`'s `ADMIN_CMD_DIRS` macro expansion produced a
  syntax error that cascaded into wrecking parsing for the rest of the
  file, breaking the wizard "wish" shell object entirely).
- **`include/config.h`**: `METRIC`/`KG_TO_LBS`/`LBS_TO_KG` (needed by
  the restored `weight_to_string()`, see \S2 below, and by swmud's own
  `std/modules/m_companion.lpc`).

All confirmed by checking the target file actually exists in the merged
tree before adding the macro back -- none of these paths were invented.

### 2. Dropped simul_efun functions

swmud's own `secure/simul_efun/{misc,objcalls,path,string}.lpc` (4 of
the 4 simul_efun source files it ships) replaced Lima's originals
wholesale, but are an older/leaner snapshot missing several utility
functions that both Lima-base files *and swmud's own files* still call:
`lima_version()`/`identify()` (misc.lpc; called by `secure/
error_handler.lpc` and the `version` command), `file_domain()` (path.lpc;
called by `daemons/domain_d.lpc`), and `punctuate()`/`tidy_list()`/
`time_to_string()`/`weight_to_string()`/`filepath_ellipsis()` (string.lpc;
called by 14+ files including `cmds/wiz/calls.lpc` and swmud's own
`std/modules/m_companion.lpc`). Ported the exact implementations forward
from `libs/lima/work/secure/simul_efun/*.lpc` (unmodified copy-paste,
credited in-file) rather than reinventing them.

Also found the **exact same already-known bug** Lima itself had and
fixed upstream: `secure/simul_efun/string.lpc`'s `create()` builds an
"every byte value" lookup table via `chr(i)` for `i` in `[0,256)`; this
driver's `sprintf("%c", 0)` (used by the `chr()` simul_efun override
itself) errors on a `\0`/out-of-range codepoint. Lima's own current
`string.lpc` already fixed this (`for (i = 1; i < 255; i++)`); swmud's
copy had reverted to the original `[0, 256)` range. Applied the exact
same fix Lima uses, verbatim, rather than re-deriving a different one.

### 3. `TYPE array NAME` / bare `array` dialect (§7's recurring bug class 7)

980 sites across swmud's own files used two flavors of the classic old-
MudOS array-declaration dialect this driver doesn't accept: `TYPE array
NAME` (405 hand-written + machine-verified sites, e.g. `string array
names;`) and **bare `array` as a shorthand for `mixed *`** (a second,
narrower dialect specific to this archive -- ~200 more sites, e.g.
`array args...`, `array handle_ob(...)`, `class command_info array
module_commands()`). A two-pass scripted sweep converted both to modern
`TYPE *name` / `mixed *name` syntax. Two sweep-tooling bugs surfaced and
were caught by re-running `lpcc_check.sh` and fixing forward rather than
trusting the first pass:

- The bare-`array` regex needed a trailing word-boundary; without it,
  `arrayp(` and `array_sum(` (two real identifiers that happen to start
  with the substring `array`) got mangled into `mixed *p(` and
  `mixed *_sum(`. Fixed by reverting those ~80 specific corruptions with
  a targeted second pass, then adding the missing `\b`.
  `secure/simul_efun/json.lpc`'s own header comments (a "v1.0.2: define
  array keyword for LDMud... v1.0.4: Removed array keyword" changelog)
  independently confirm swmud is a snapshot from *before* upstream Lima
  cleaned up exactly this same LDMud-style `array` shorthand -- this
  wasn't a guess, it's the archive's own documented history.
- Class-typed arrays (`class event_info array queue`, `class
  command_info array module_commands()`) got the wrong substitution
  (`class event_info mixed * queue` -- two type keywords in a row); the
  correct transform for a `class X array` prefix is `class X *`, not
  `class X mixed *`. Fixed with a second targeted pass matching the
  `class IDENT mixed \*` pattern this produced.
- One residual case (`std/object/visible.lpc`'s `void remove_id(string
  array ...);`, a *typed* varargs ellipsis) needed the `TYPE *...` form,
  not the bare-array sweep's `mixed *...` -- fixed by hand (only one
  instance existed).

### 4. `inherit chain size` too small once merged (masqueraded as infinite recursion)

`/std/body.lpc` failed every load attempt with `*Inherit chain too deep:
> N` for every `N` up to 200 tried -- looked like true runaway recursion,
but the real cause (found by bisecting) was a **missing file**:
`std/body.lpc` has `inherit __DIR__ "body/help";`, and `std/body/
help.lpc` does not exist anywhere in this archive or in Lima's base.
Compiling a missing inherit target routes through `master.lpc`'s
`compile_object()` virtual-object fallback, which (per its own doc
comment) walks up the path looking for a parent `.lpc` to call
`virtual_create()` on -- for `/std/body/help` that parent is `/std/
body.lpc` itself, so resolving the missing inherit re-entered compiling
`/std/body.lpc`, which needed to resolve the same missing inherit again,
forever. Removed the dead `inherit __DIR__ "body/help";` line (content
genuinely absent, not invented) and also `inherit __DIR__
"body/wiz_position";` on the same line block -- confirmed *not* just
missing but actively dead: `std/body/wizfuncs.lpc`'s own header says
"230319, Tsath: Merged wiz_positions into this file," and it already
defines `query_wiz_position()`/`set_wiz_position()`. `inherit chain
size` was still bumped from Lima's `30` to `60` (this project's common
ceiling, used by 137 other libs) as normal headroom for the now-much-
larger combined class hierarchy -- it just wasn't the real bug.

One related, still-orphaned file: `std/modules/m_exit_obj.lpc` (from
Lima's base, unreferenced anywhere in the merged tree -- `grep` confirms
nothing inherits `M_EXIT_OBJ`) calls a 3-argument `eval_dest()`, but
swmud's own replacement `std/modules/m_exit.lpc` defines a completely
different 1-argument `eval_dest()` (also `private`, matching the
AGENTS.md \S7.48 cross-file-private pattern -- loosened to `protected`
on general principle, though no live caller actually needs it). Left
`m_exit_obj.lpc` as a known `lpcc_check.sh` failure: it's genuinely dead
code with an incompatible signature from a different API vintage, not
something to guess a 3-argument implementation for.

### 5. First-ever player registration crash (real, 100%-reproducible)

The single most severe bug found: **every fresh install of this archive
crashes on the very first character ever created.** `secure/user/
sw_body.lpc`'s `sw_body_handle_new_logon()` auto-promotes the first-ever
registrant to admin (a direct port of Lima's own bootstrap convention)
*before* calling `create_body()`. Inside `std/body.lpc`'s `create()` ->
`adversary::create()` -> `mudlib_setup()` -> `refresh_stats()` ->
`std/adversary/health/limbs.lpc`'s `set_max_health()`, the racial-stat
rollout calls `check_wizard_set()` (an anti-cheat guard meant to stop a
*different*, low-ranked wizard from remotely tampering with another
player's stats). That guard's `thing != link` check is unconditionally
true at this exact point in the call chain, for *every* new character
of *any* account, because `link` is only ever assigned later, inside
`enter_game()`/`init_cmd_hook()` -- which hasn't run yet during the
body's own constructor. For an ordinary (non-wizard) new account this is
harmless (`wizardp(thing)` is falsy, so the guard short-circuits), but
for the bootstrap-admin account -- unavoidable on a fresh install, and
also would hit any wizard creating a new character if this mudlib ever
supported more than one character per account -- `wizardp(thing)` is
truthy and the guard fires: `*Invalid attempt by <name> to set 's max
health to <n>.` This took real trace-level debugging to isolate (naive
`write()`/`printf()` debug statements silently vanished at exactly this
point in the call stack, because `this_player()` context is ambiguous
mid-construction; switching to `write_file()`-based logging and reading
`/log/runtime`'s actual stack trace was what nailed the true call
chain -- see git history of this fix for the full reasoning if this
class of bug recurs elsewhere). Fixed with a one-line, minimal guard:
only apply the anti-cheat check once `link` is actually established
(`if (link && ...)` instead of just `if (...)`), preserving the real
anti-cheat behavior for its intended post-login use case.

### 6. Division by zero in the Character Creation attribute screen

`std/modules/m_bodystats.lpc`'s `query_for()` (the "Force" stat, with a
Star-Wars-specific environmental bonus term) divides by `cur_for`
unconditionally -- but `cur_for` is legitimately `0` for every freshly
rolled, not-yet-allocated character, which is exactly the state the
attribute-point-buy screen displays. Crashed the Character Creation
"Attributes" screen for every single new character on every single
render until the player had already put at least one point into Force.
Fixed with a guard returning `cur_for` unmodified (0) rather than
dividing by it, on the reasoning that a character with 0 force
sensitivity shouldn't receive an environmental force bonus anyway.

### 7. `team_alignment` used but never declared

`obj/mudlib/createmenu.lpc`'s Character Creation "Team" step
(imperial/rebel/neutral) calls `this_body()->set_team_alignment(n)`, and
`secure/daemons/{user_d,finger_d}.lpc`'s `who`/finger display code reads
`"team_alignment"` back as a plain global variable via this driver's
`fetch_variable()` reflection mechanism -- but no `team_alignment`
variable, nor `set_team_alignment()`/`query_team_alignment()` functions,
exist anywhere in the archive. The setter calls were pure no-ops
(call_other to an undefined function silently returns 0), and every
`who`/finger lookup on *any* character crashed outright (`*Variable
named 'team_alignment' does not exist or is not visible!`) since the
variable genuinely doesn't exist to reflect. Added the missing
`int team_alignment;` variable plus matching accessors to `std/
body.lpc`, mirroring how `race_name` already works as a plain reflected
variable on the race classes. (The broader `legal_body_query` list in
`user_d.lpc` also names 8 jedi-sponsorship fields -- `jedi_sponsor`,
`sponsored_by`, etc -- that are similarly never declared anywhere; left
alone since they're outside the everyday `who` query set that actually
gets exercised, per `secure/daemons/finger_d.lpc`'s own shorter
12-field list, so they're not a live crash. Flagged here in case a
future jedi-sponsor-specific command surfaces the same gap.)

### 8. `race_name` missing from 4 leftover Lima races -> crashed `who`

`std/race/{human,elf,orc,documentation}.lpc` are unmodified Lima base
files (byte-identical, confirmed via `diff`) that hardcode `query_race()`
to return a literal string instead of exposing a `race_name` variable
the way every one of swmud's *own* races does (`human_corellian`,
`wookiee`, `defel`, etc. all declare `string race_name = "...";`).
`who`/finger's variable-reflection lookup on `race_name` crashed for any
character of one of these 4 races the same way \S7 did for
`team_alignment`. Since these 4 races are also non-canonical for a Star
Wars game (a generic "human"/"elf"/"orc" alongside swmud's own 13 real
races, one of which -- `human_corellian` et al -- already covers
"human" properly) and were the same 4 files needing the `stat_roll_mods`
class-inherit fix below, moved them to `std/race/unused/` (an existing,
already-used-for-this-purpose directory -- `human_dathomirian.lpc` was
already there) alongside `troll.lpc` (\S9). `race_d.lpc`'s own
`get_dir(DIR_RACES + "/*.lpc")` glob is non-recursive, so this cleanly
removes them from the selectable race list without deleting any content.

### 9. Missing `inherit CLASS_STATMODS;` broke 5 races' stat-roll class

`std/race/{human,elf,orc,troll,documentation}.lpc` (all unmodified Lima
files) declare a local `class stat_roll_mods query_roll_mods()` function
using a `class` type defined in `std/classes/statmods.lpc`, but never
`inherit CLASS_STATMODS;` to bring that class definition into scope --
a real, `lpcc_check.sh`-confirmed compile failure (`Undefined class
'stat_roll_mods'`) for all 5. Added the missing inherit to all 5. 4 of
the 5 (everything except `troll.lpc`) now compile clean and were kept
loadable (before being moved to `unused/` per \S8 above, for the
separate `race_name` reason). `troll.lpc` has a second, deeper
incompatibility (below) and stays broken.

### 10. `troll.lpc` (leftover Lima demo race) broke 3 *real* swmud races

`std/race/troll.lpc` additionally calls `set_to_hit_bonus()`/
`set_weapon_class()` -- functions that existed in Lima's old combat
system but don't exist anywhere in swmud's rewritten `std/adversary/*`
combat model (\S"Architecture" above). This alone would just mean troll
fails to load and gets skipped -- except `daemons/race_d.lpc`'s
`create()` loop does `if (!load_object(tmp)) { continue; }`, and on this
driver a **failed compile inside `load_object()` throws an error that
propagates past that `if`/`continue` guard instead of returning falsy**,
aborting the entire `foreach` early. Since `get_dir()` returns races in
filename order and `troll.lpc` sorts right before `twilek.lpc`,
`verpine.lpc`, and `wookiee.lpc`, this silently dropped 3 of swmud's own
*real, working, Star-Wars-canonical* races from the selectable list
every single boot -- not a cosmetic listing bug, an actual "3 valid
races become permanently unselectable" bug, caused entirely by one
broken leftover demo file sorting adjacent to them. Fixed by moving
`troll.lpc` to `std/race/unused/` (same mechanism as \S8) rather than
trying to guess a `set_weapon_class()`/`set_to_hit_bonus()`
implementation for content that was never part of this game to begin
with. Verified live: the race list now shows all 13 real races,
including wookiee/twi'lek/verpine, and each is independently selectable.

### 11. `WIZARD_START` pointed at broken Lima demo content

`include/config.h`'s `WIZARD_START` (upstream value: `"/domains/std/
Wizroom"`, Lima's stock "Grand Hall" demo room) fails at runtime: its
`set_objects()` places a virtual `"map"` object at `/domains/std/
map.lpc`, which calls `set_untouched_desc()` -- again, a function that
doesn't exist anywhere in swmud's rewritten object API (same pattern as
\S10). This crashed `move_to_start()` for the wizard-fallback path
specifically -- i.e. exactly the path this project's own admin-account
verification convention exercises. Repointed `WIZARD_START` at
`/d/common/void` (a real, working room this archive does ship) instead
of inventing replacement demo content. This is a deployment
substitution, not a "fix" of swmud's own design, since \S12 below means
the *real* wizard starting room was never included in the archive
either way; ordinary (non-wizard) players already fall through `move_
to_start()`'s own built-in fallback chain to this same Void room for
that reason, so wizards now land in the same well-defined place.

### 12. The real starting area doesn't exist in this archive at all

`include/config.h`'s `START`/`NEW_PLAYER_START` point at `/d/coru/main`
("Coruscant", the intended real starting location) -- but neither that
file nor even a `d/coru/` directory exist anywhere in the raw clone or
its git history. This is confirmed **not** a conversion artifact: the
`d/` tree (swmud's real, non-Lima game-content root) has real, working
subtrees for items/weapons/armor/monster templates (`d/arm`, `d/buffs`,
`d/com`, `d/const`, `d/mon`, `d/obj`, `d/weap`) but **no room/area
content anywhere** -- confirming the actual playable map was never
committed to this git repository at all (plausibly built live on the
original production server and never checked in, a common split for
"engine code" vs "game content" in MUD codebases). This is a genuine,
severe, pre-existing content gap -- not something fixable within this
project's "fix programming bugs, don't invent content" mandate.
Fortunately `std/body/start.lpc`'s `move_to_start()` already has a
sensible built-in fallback chain (configured start -> `WIZARD_START`/
`START` -> `VOID_ROOM`) ending at a real, well-written room
(`/d/common/void.lpc`, "Void... This is where players and objects are
moved to when something goes wrong. If you end up here, please let a
wizard know."), so every new character still lands somewhere coherent
and playable rather than crashing -- this was the intended behavior of
swmud's own error-handling design, not a workaround this port invented.

### 13. `secure/user/sw_body.lpc`'s new-character shell path clamp broke wizard commands

Every brand-new character's shell (`incarnate()`, in the `if (is_new)`
block) unconditionally overwrote its shell's `"path"` variable to
`({"/cmds/player", "/cmds/guild"})`. `secure/user/shell.lpc`'s
`start_shell()` already correctly picks `WIZ_SHELL` (the Lima "wish"
shell, `/trans/obj/wish`, whose own `create()` smartly defaults `path`
to `WIZ_CMD_DIRS`/`ADMIN_CMD_DIRS` for a wizard account) vs
`PLAYER_SHELL` based on `wizardp()` -- but the very next thing
`incarnate()` did was stomp that smart default back down to the plain
player command set, for every new character regardless of wizard
status. Combined with \S5's bootstrap-admin-before-`create_body()`
ordering, this permanently locked the very first player on a fresh
install (guaranteed to be a wizard) out of every wizard/admin command
(`update`, `admtool`, ...) forever, since this mudlib is single-
character-per-account (no way to "recreate" the character with a wider
path later). Fixed by only clamping the path when `!wizardp(query_
userid())`, letting a wizard's shell keep whatever `WIZ_SHELL`'s own
constructor already set up. Verified live: `update /std/race/wookiee`
and `admtool` (through its wizard-gated `priv 1` submenu) both work
correctly for the bootstrap-admin account after this fix.

### 14. `NO_NEW_PLAYERS` -- deployment change, not a bug fix

`include/config.h` ships with `#define NO_NEW_PLAYERS` (an intentional
upstream "closed beta" gate -- new registrations are rejected outright
except via a pre-approved guest slot). Since this project's whole point
is letting site visitors register and actually play, `#undef`'d it.
Documented in-file as a deliberate deployment substitution, matching
this project's established convention for this exact situation.

### 15. Missing `<lpscript.h>` header (removed, not invented)

swmud's own `include/mudlib.h` replaced Lima's `#include
"custom_mudlib.h"` (an empty upstream placeholder) with `#include
<lpscript.h>` -- a header that doesn't exist anywhere in this archive
*or* in Lima's base, breaking compilation of every single file (it's
pulled in via the global include chain). The only 3 references to
LPscript anywhere in the merged tree (`daemons.h`'s `LPSCRIPT_D` path
macro, `secure/master.lpc`'s `compile_object()` handling a hypothetical
`*.scr` file extension, and this include line) need zero symbols from
the missing header -- there are no `.scr` files anywhere in the archive
either, so the code path is dead in practice. Removed the `#include`
line rather than fabricating a header for a feature this archive never
actually ships content for.

## Known, deliberately unfixed gaps (content/design, not bugs)

- **\S"Architecture" above**: ~77 of 129 remaining `lpcc_check.sh`
  failures are orphaned Lima demo content (`domains/`'s stock rooms/
  monsters/spells, plus `std/sword.lpc` and siblings) that predates this
  port and isn't part of swmud's real game world. Not fixed, matching
  this project's standing "don't invent content" policy.
- **`std/modules/m_exit_obj.lpc`** (\S4): dead code, incompatible
  `eval_dest()` signature from a different API vintage, nothing
  references it. Not fixed.
- **`std/race/troll.lpc`** (\S10, now in `std/race/unused/`): incompatible
  old-Lima combat API calls (`set_to_hit_bonus`/`set_weapon_class`).
  Not fixed -- not a real Star Wars race to begin with.
- **`obj/mudlib/nicknamemenu.lpc`**: one real, fixed bug (missing
  `inherit CLASS_ALIAS;` for its `class alias` usage -- applied), but
  the file has additional pre-existing gaps beyond that (`(:
  new_template :)`/`(: rcv_new_alias_name :)` reference functions that
  don't exist anywhere in the file or its inherits) that look like a
  genuinely incomplete/abandoned feature in the original archive, not a
  conversion artifact. Left as a known `lpcc_check.sh` failure --
  nickname aliasing is a peripheral QoL feature, not exercised by this
  port's core verification path.
- **`obj/usermenu/usermenu.lpc`**: an alternate, apparently-unused
  character-creation menu system (nothing in the active registration
  flow references `USER_MENU`) with a hardcoded `DIR_RACES "/human"`
  default that now dangles after \S8 moved `human.lpc` to `unused/`.
  Not fixed -- this file isn't reachable from swmud's actual
  registration flow (`secure/user/sw_body.lpc` has its own, completely
  separate, active implementation), so this is latent, not live.
- **`obj/mudlib/newsreader.lpc`**: uses an undefined `SAVE_OB` macro/
  variable pervasively (27 sites). Confirmed via `diff` to be byte-
  identical to Lima's own copy of this file, and Lima's own headers
  *also* don't define `SAVE_OB` -- this is a pre-existing upstream Lima
  bug, not something swmud or this port introduced, and newsreader isn't
  part of the preload chain or core verification path. Not fixed (out
  of scope: this port is responsible for swmud's own changes, not
  auditing all of Lima's dependencies for latent bugs beyond what swmud
  itself needs to work).
- **`daemons/imud/finger.lpc`**, **`contrib/marriage/finger_d.lpc`**,
  **`WWW/cgi/who.lpc`**: reference `class finger` members (`visname`,
  `level`, `nickname`) that don't exist in `std/classes/finger.lpc`'s
  actual field list. Intermud finger-protocol and a `contrib/`-flagged
  optional marriage extension respectively -- neither is preloaded or
  part of core gameplay. Not fixed (same category as Lima's own
  documented `contrib/marriage` `spouse`-member gap, see `libs/lima/
  NOTES.md`).
- **`secure/daemons/ftp_d.lpc`**: "Illegal to use local variable in
  functional" -- the exact same pre-existing Lima-base driver-dialect
  gap already documented (and left unfixed) in `libs/lima/NOTES.md`;
  `ftp_d` isn't in this archive's preload list either.
## ⚠️ Real outbound network connection at boot (Intermud-3)

Unlike almost every other lib in this corpus (all sandboxed, no outbound
connections -- see AGENTS.md \S1.3c/\S7.6), **`daemons/imud_d.lpc`
preloads at boot and makes a genuine outbound socket connection to the
public Intermud-3 router network.** `imud_d.lpc`'s `create()` has a
protective check that refuses to load if `ADMIN_EMAIL` is still Lima's
placeholder `"billg@microsoft.com"` -- exactly the guard that made
`libs/lima/`'s own `imud_d` refuse to load (see `libs/lima/NOTES.md`).
swmud's `include/config.h` sets `ADMIN_EMAIL` to a real-looking value
(`"starwarsmud@gmail.com"`), so that guard does **not** trigger here:
`create()` proceeds to call `trigger_reconnect("router")`
unconditionally at every boot, same as `libs/imud/`'s intentional demo
behavior (see `libs/imud/NOTES.md`). This means **this lib should not be
swept into high-frequency automated re-boot loops** (round-two/round-
three-style re-test cron, `lpcc_check.sh`-adjacent live-boot sweeps) the
way the rest of this project's sandboxed corpus safely can be -- each
boot is a real network event against a real third party.

## Admin account

Bootstrapped through the mudlib's own real first-boot logic (not a
save-file hand-edit): registered `fluffos`/`Mud@2026` as the very first
account on a completely clean `data/{links,players,pshells,wshells}`
tree, which `sw_body_handle_new_logon()` auto-promotes to admin/wizard
per Lima's own convention (see \S5 above for the crash this triggered
and its fix). Completed full Character Creation (Corellian, right-
handed, Rebel alignment) and verified: `who` shows `[Apprentice] Fluffos
the Bantha Fodder (Corellian)` with Role `Admin Wizard`; `update
/std/race/wookiee` succeeds (`Updated and loaded.`); `admtool` opens and
its wizard-gated `priv 1` -> `administration` submenu (showing `[admin]`-
tagged options) is reachable. A second, ordinary (non-wizard) test
account (`testplayer`, Wookiee, Imperial) was also registered end-to-end
to confirm the bootstrap-specific fixes above don't regress the normal
player path.

## Verification record

`scripts/mudclient.py`-equivalent raw Python socket sessions through the
real `~/src/fluffos-lima/build-debug/src/driver`, multiple independent
boots across the debugging process above: full registration (username,
"is this correct?" confirmation, password+confirm, gender, email, real
name, homepage) -> race selection (verified against `corellian` and
`wookiee`, both non-human and human-ethnicity races) -> point-buy
attribute allocation -> dominant hand -> team alignment -> lands in Void
with a starting body -> `look` (room description + exits correct) ->
`score` (race/gender/guild/XP/HP/credits all correct) -> `who` (roster
line with role tag, race, location) -> `inventory` -> admin `update`/
`admtool` (bootstrap-admin account only) -> `quit` (clean disconnect
back to the User Menu, `debug.log` free of new errors). No crashes,
zero silent failures, across all of the above after the fixes in this
document.
