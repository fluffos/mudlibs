# Genesis -- porting notes

Source: `git clone https://github.com/genesismud/mudlib` (commit `92ce6844`,
cloned 2026-08-25). Slug `genesis`, number 166, port 40213.

## 1. What this repo actually is

Per the repo's own README: "This repo does not contain a standard domain
which will need to be implemented to use the mud." This is the **engine**
(master, login, std/ base classes, command souls, board/mail/bank/donation/
report subsystems, the wizard toolset) with **no `/d/Genesis` domain at
all** -- no rooms, no NPCs, no items, no race std files, no wizard guild
rooms, no docs directory content that the code references. Every gap
documented below as "missing domain content" traces back to this one fact,
not to anything this port broke.

## 2. Compile-sweep: CD-driver -> FluffOS dialect differences

This is a large (225 `.lpc`/`.h` files), mature CD gamedriver codebase, so
essentially every category of CD-vs-FluffOS incompatibility this project
has previously catalogued showed up here too:

- **`&operator(OP)(args)` / `@` function composition and partial
  application** -- entirely unsupported by FluffOS. Converted throughout to
  either `(: FUNCNAME, bound_args... :)` closures (bound args are evaluated
  eagerly, so they *can* capture what would otherwise be an enclosing local)
  or to small `private` helper functions when the composition needed
  reordering/renaming arguments. `secure/mbs_central.lpc`'s
  `get_board_list_cath()`/`get_board_list_dom()` macros (composition inside
  a textual macro, capturing a macro *parameter*) needed a dedicated
  `__board_match_bound()` helper. `std/launch_weapon.lpc`'s
  `&combat_ob->query_attack()` (empty parens = "freeze no arguments", i.e.
  pass the filter/map element straight through) had its implicit argument
  silently dropped by the mechanical `@`-chain converter used earlier in
  this session -- the same bug independently hit `std/living/wizstat.lpc`'s
  `stat_living()` (three `map()` calls). Both fixed by hand once found.
- **`(: expr :)` closures can't capture enclosing-function locals** -- this
  is the single most common fix in the whole port (60+ sites across
  `secure/master/fob.lpc`, `secure/mbs_central.lpc`, `secure/report_central.lpc`,
  `std/living/*.lpc`, `cmd/wiz/*.lpc`, and more): each needs a small
  `private` helper function taking the local as a **bound argument**
  (`(: FUNCNAME, local_var :)`), never a bare `(: local_var ... :)`.
- **`filter()`/`map()` on a *mapping* callback arity**: this driver calls
  the callback with **`(key, value)`** (2 args) for a mapping, per FluffOS's
  own `filter()`/`map()` semantics -- the CD driver's documented contract
  (`doc/man/efun/filter`) is **value-only** (1 arg). Several `&operator(==)`
  compositions written for the CD driver's 1-arg convention silently
  produced wrong results once mechanically converted (comparing against the
  *key*, not the value) rather than a compile error -- caught in
  `secure/mbs_central.lpc` (`__field_eq_bound_map()` added specifically for
  this) and `secure/map_central.lpc`. Not swept exhaustively across the rest
  of the codebase's other `filter(some_mapping, ...)` call sites (out of
  scope for this pass -- flagged here for a future targeted sweep if this
  lib gets deeper testing).
- **`foreach(var: expr)` colon syntax**, **old-style `TYPE name = expr`
  parameter defaults**, **`m_indexes`/`m_sizeof`/`m_delkey`/`mappingp`**
  efun renames, **`extract()`**, **`[..N]` omitted-start slices** -- all
  handled by the same mechanical sweeps this project has used on every
  large CD-derived lib so far.
- **Reserved-keyword collisions**: `class` (used as a parameter name in
  `std/armour.lpc`, `std/weapon.lpc` x2, `std/unarmed_enhancer.lpc` x2 --
  renamed to `ac`/`hitval`/`penval`), `new` (already a known-recurring
  issue, one more instance in `std/living/combat.lpc`'s `add_attack_delay()`
  -- renamed to `new_delay`), `in` (`secure/application_player.lpc`'s
  `write_info()` had a local literally named `in`, holding the connecting
  IP's hostname -- renamed to `ipname`; "in" is reserved for `foreach`'s
  `var in expr` syntax). And a less obvious one: **`buffer` is a real
  FluffOS type keyword** (`packages/core`'s binary buffer type) that isn't
  reserved on the CD driver -- `secure/player_tool.lpc` declared three
  locals named `buffer` (renamed to `filedata`), which produced a
  genuinely confusing "unexpected L_BASIC_TYPE" error several statements
  away from the actual problem line (bisected with `lpcc` by truncating the
  file until the error disappeared).
- **Illegal diamond inherit**: `std/bow.lpc` explicitly `inherit`s both
  `/std/launch_weapon` and `/lib/keep`, but `/std/launch_weapon` already
  transitively inherits `/lib/keep` via `/std/weapon` -- the CD driver
  tolerated the redundant re-inherit (present in the original upstream
  source, not something this port introduced), this driver rejects it
  ("Illegal to redefine 'nomask' function"). Removed the redundant explicit
  inherit.
- **Missing efuns implemented as simul_efuns** (`secure/simul_efun.lpc`,
  each documented with a `FluffOS PORT NOTE`): `set_auth`/`query_auth`
  (the whole uid/euid model -- CD driver's arbitrary "uid:euid" string pair
  per object vs. FluffOS's simpler native model, see \S4), `file_time`
  (via `get_dir(path, -1)`'s undocumented single-file stat mode),
  `wildmatch` (translated to `regexp()`), `one_of_list`, `applyv`,
  `call_otherv`, `reduce`, `mkfunction`, `rnd`, `gettimeofday`, `tail`,
  `debug`, `m_delete`, `process_value`/`process_string` (VBFC), and GMCP's
  `val2json`/`write_socket_gmcp` (this driver's `send_gmcp(string)` takes
  a single pre-formatted `"Package.Sub {json}"` string with no JSON
  encoding of its own -- `val2json()` is a small from-scratch encoder
  covering the subset of JSON this codebase's own `catch_gmcp()` call
  sites actually produce: strings, ints, floats, 0-as-null, arrays,
  string-keyed mappings).
- **Documented CD-driver "graceful degradation on wrong argument type"
  contracts that FluffOS's real efuns don't replicate** -- this recurred
  enough to be its own category, not isolated incidents:
  - `doc/man/efun/m_indexes`: "if an integer is given instead of a mapping,
    0 is returned" -- FluffOS's `keys()` hard-errors instead. Fixed in the
    `m_indices()` simul_efun (hit for real: `secure/master/player.lpc`'s
    `query_seconds()` calls `m_indices(m_seconds[first])`, legitimately `0`
    for anyone with no seconds on file, checked on **every single login**).
  - `doc/man/efun/member_array`: "if an integer is given instead of an
    array, -1 is returned" -- FluffOS's real `member_array()` efun
    hard-errors. Shadowed with a simul_efun of the same name (bypassing to
    the real efun via `efun::member_array()` for the normal case). Hit for
    real: `std/player/cmd_sec.lpc`'s `check_valid_startloc()` calls
    `IN_ARRAY(env, SECURITY->query_list_def_start())` where that function
    doesn't even exist (a **separate**, genuine pre-existing bug -- the
    real functions are `FPATH_FILENAME`'s `query_def_start_locations()`/
    `query_temp_start_locations()`, not `SECURITY`'s `query_list_def_start`/
    `query_list_temp_start`, which exist nowhere in this codebase) -- every
    mortal's very first `quit` hit this.
  - `doc/man/efun/filter`: mapping-filter value-only-callback semantics,
    see above.
- **Two self-inflicted mechanical-sweep bugs**, both from this session's own
  earlier conversion scripts (documented for the record, already fixed):
  a for-loop-init-clause corruption and a string-literal-embedded-comma
  corruption, each caught via a comment/string-aware paren-balance
  comparison script run repeatedly against every `raw/*.c` vs `work/*.lpc`
  pair (0 mismatches at every checkpoint from this point in the session
  onward).

## 3. `add_action()` bare function-value bug (the headline bug)

`add_action(FUNCTION_VALUE, "verb")` -- e.g. `add_action(quit, "quit")`,
using the bare function name as a value, the standard idiom throughout this
codebase -- **compiles cleanly, and the resulting sentence shows up in
`commands()`**, but is **never actually matched against typed player
input** on this driver. Confirmed via `lpcc`/live-driver testing: switching
a handful of calls to the **string form** (`add_action("quit", "quit")`)
made them work immediately, with no other change.

This wasn't a narrow issue: **151 of 158** `add_action()` call sites in the
whole codebase used the bare-value form, including
`std/living/cmdhooks.lpc`'s `add_action(my_commands, "", 1)` -- the
catch-all verb (`""`) that is the **entry point into the entire
soul-command dispatch system**. With that one call broken, no soul command
(the emote soul, wizard souls, everything) worked for anyone, wizard or
mortal -- while it *looked* like a soul-loading problem (the "Yikes, baaad
soul: /d/Genesis/cmd/misc" message, from the genuinely-missing `NPC_SOULS`
second entry, printed on every keystroke) the actual root cause was
upstream of the soul system entirely.

Fixed with a tree-wide mechanical sweep (145 more sites, on top of 7
manually fixed earlier while chasing the initial symptom) converting
`add_action(IDENT, ...)` -> `add_action("IDENT", ...)`. One site was
**not** converted: `std/room/exits.lpc`'s `ugly_update_action(object
player, string cmd, function fun) { add_action(fun, cmd); }` takes a
genuine runtime `function` **parameter**, not a compile-time-known name --
there's no way to recover a string name from an arbitrary function value on
this driver (`function_name()`/`function_object()` don't exist here
either, a previously-documented gap) -- left as-is, already flagged by an
existing comment in that file as a pre-existing "de-dup regression" from an
earlier, unrelated fix.

## 4. `set_auth`-based uid/euid model: `"#"` placeholder bug

`secure/simul_efun.lpc` implements `set_auth()`/`query_auth()` (and the
`getuid`/`geteuid`/`seteuid`/`setuid`/`export_uid` efuns built on top of
them) as a from-scratch simul_efun shim, because the CD driver's uid model
is an arbitrary, freely-settable **`"uid:euid"` string pair per object**
(via `set_auth(ob, "uid:euid")`), which doesn't map onto FluffOS's simpler
native single-string-uid/single-string-euid model at all.

`setuid()`, `seteuid()`, and `export_uid()` all used a literal `"#"` string
as a placeholder for "the other half of the pair, don't care right now" --
e.g. `setuid()` did `set_auth(previous_object(), CREATOR + ":#")` (uid set
correctly, euid set to the placeholder). The bug: **`getuid()`/`geteuid()`
never actually resolved `"#"` back to anything** (they only special-case
the string `"0"` as "unset"). So the very next call in this codebase's own
standard idiom, `setuid(); seteuid(getuid(this_object()));`, would read
back the *other* field's real value correctly, then **immediately
overwrite it with `"#"`** when setting the field it was updating --
`seteuid(str)` did `set_auth(ob, "#:" + str)`, permanently stomping the
uid field it should have left alone.

Net effect: **every single object that went through this standard idiom**
(used throughout `std/living.lpc`'s `create_container()`, and elsewhere)
ended up with a uid of the literal string `"#"` after its very first
`seteuid()` call -- silently breaking any *later* `getuid()`-based
permission check on that object. This is exactly why the new-player
bootstrap (\S5) failed with "Denied write permission in save_object()" on
its first save attempt: `export_uid()`, called from `secure/master.lpc`'s
`save_player()` wrapper, read the corrupted `"#"` uid and propagated it
into the object being saved.

Fixed at the source: `export_uid()`, `seteuid()`, and `setuid()` in
`secure/simul_efun.lpc` now always **preserve** the field they aren't
updating (read it first, write it back unchanged), and `setuid()`'s euid
default is `"0"` (which `geteuid()` *does* resolve, to unset/none) instead
of `"#"`. One direct call site outside the simul_efun file had the exact
same bug and needed the same fix: `secure/master/fob.lpc`'s
`reset_wiz_uid()` (called from `std/player.lpc`'s `reset_userids()`,
i.e. **every wizard login**) did `set_auth(wiz, name + ":#")` directly.

Every other `set_auth(this_object(), "#:root")`-style call throughout
`secure/master.lpc` (15+ occurrences) is **not** the same bug -- those are
the master object's own well-understood, intentional self-referential
placeholder (master's own uid is never actually checked anywhere in this
codebase, only its euid), left untouched.

**Residual, non-blocking**: one "Denied write permission in
save_object()" is still logged during some wizard-login
save/quit euid-transition sequences (traced to
`std/player/cmd_sec.lpc`'s `save_me()`, which explicitly does
`seteuid(0)` immediately before calling `SECURITY->save_player()` as
part of a "drop privileges, let master re-grant them" pattern) -- but
the actual save consistently succeeds regardless (the resulting
playerfile is correct both times it was checked, and the user-visible
"Saving <name>." + clean disconnect always appears). Not fully root-caused
given the time budget for this pass; flagged for anyone doing deeper
testing on this lib later.

## 5. Missing character-creation bootstrap (`secure/login/ghost_player.lpc`)

`config/sys/local.h`'s `LOGIN_NEW_PLAYER`/`LOGIN_TEST_PLAYER` macros point
at `/d/Genesis/login/ghost_player` -- unlike most of this repo's other
missing-domain-content gaps (narrative/world content with a graceful
fallback already built into the surrounding code, left undefined/empty and
documented, see \S6), this file **never existed anywhere in the upstream
repo at all**, and it's genuinely load-bearing *infrastructure*:
`secure/login.lpc` clones it and calls `open_player()`/`enter_new_player()`
on it to create every single new character, and `secure/master.lpc`'s
`load_player()`/`save_player()` gate **every player save/load** on
`LOGIN_NEW_PLAYER->legal_player()`. Without some real implementation here,
character creation -- and therefore save/load entirely -- was impossible.

Added a minimal, functional bootstrap implementation at
`secure/login/ghost_player.lpc` (inheriting `/std/player`, config updated
to point at it) rather than a recreation of whatever richer race/stat-
selection wizard the original surely had (that content is lost along with
the rest of the missing domain). It:

- Sets a default race (`RACES[0]`, i.e. `"human"` -- `std/player.lpc`'s own
  `setup_player()` already has a "mortals should have one of the base races
  by default" comment, but its `reset_race_name()` call is a no-op
  self-reassignment, not a real default, since no race std file ever set
  `race_name` in the first place).
- **Explicitly saves the player object before calling `enter_game()`** --
  `std/player.lpc`'s `setup_player()` silently returns early (skipping
  `cmd_sec_reset()`, which registers `quit`/`save`/`password`, and every
  later setup step) unless `SECURITY->load_player()` succeeds, which
  requires `restore_object()` to find an *existing* playerfile. The real
  (missing) character-creation wizard presumably did its own explicit save
  once race/stat selection was done; this bootstrap does the same.
- Implements `legal_player()` permissively (any real, loaded `/std/player`-
  derived object) and `reincarnate_me()` as a documented no-op (the real
  reincarnation flow -- guild/race-specific rebirth rules -- is lost domain
  content; `death_sec.lpc`'s own ghost/second-life handling already keeps
  the player object alive and playable without it).

A related, previously-dead piece of functionality got wired up in the same
pass: `std/living/cmdhooks.lpc`'s `load_wiz_souls()` (loads a wizard's
rank-appropriate command souls, e.g. `update`, into `wiz_souls`) was never
called from **anywhere** in this codebase -- genuinely disconnected
functionality as shipped, not something this port broke, presumably
originally wired into the same missing character-creation/promotion flow.
The soul *files* themselves (`cmd/wiz/apprentice.lpc`, `cmd/wiz/wizard.lpc`,
etc.) are all present and compile cleanly in this repo, so this was a
"reconnect existing working code" fix, not content invention: called from
`std/player.lpc`'s `setup_player()`, in the existing `if
(query_wiz_level())` branch.

## 6. Missing domain-content symbols (compile-blocking, left content-neutral)

A large number of symbols are referenced throughout `std/`, `cmd/`, and
`secure/` but were never actually `#define`d anywhere in this repo -- they
are normally domain content. Left undefined, each is a hard "Undefined
variable/function" **compile** error (not just a missing-content gap), so a
real definition was needed just to get the mudlib to compile at all.
Defined in `secure/auto.h` (this project's chosen "global include file")
or the relevant local file, each with a `FluffOS PORT NOTE` explaining the
choice:

- **`RACES`** -- derived directly from the six race std files
  `secure/preload_list` already names (itself missing, like the rest of the
  domain), rather than invented: `({ "human", "dwarf", "elf", "goblin",
  "hobbit", "gnome" })`.
- **`RACES_SHORT`, `RACESOUND`, `RACEATTR`, `SPREAD_PROC`, `HEIGHTDESC`,
  `WIDTHDESC`, `RACEMAP`, `RACESTATMOD`** -- cosmetic/gameplay per-race
  content (abbreviations, sound tables, height/width attribute numbers and
  description text, a name-lookup map, stat modifiers) with no way to
  derive real values structurally. Defined as empty mappings/arrays: every
  reader either already has its own "no entry for this race" fallback
  (`RACES_SHORT`'s only reader in `cmd/wiz/apprentice/people.lpc` falls
  back to a 3-char substring; `RACEATTR`/`SPREAD_PROC`/`HEIGHTDESC`/
  `WIDTHDESC` are only ever reached, during actual player creation, through
  `set_height_desc()`/`set_width_desc()`'s own `member_array(...) < 0`
  guard, which fires safely on an empty array) or is a wizard-only,
  interactive-only display command not on the boot-critical path
  (`RACESTATMOD`, `finger`'s stat approximation; `RACEMAP`, a "newlook"
  guild command) -- left as a documented, deferred runtime gap for those
  specific commands rather than invented content.
- **`RACESTART`** (per-race starting room path) -- the one exception to
  "leave empty": `std/player.lpc`'s own login fallback chain already
  gracefully handles "no valid room" for a *mortal* by disconnecting with
  an explanatory message, but that disconnect happens **before the very
  first save ever runs** (\S5's circular-dependency problem again) -- so
  with `RACESTART` empty, *no character could ever complete registration
  at all*, wizard or mortal. Every race is mapped to the bare bootstrap
  landing room this port added (`secure/login/bootstrap_room.lpc`, see
  \S7) instead -- infrastructure to unblock login/testing, not invented
  world content.
- **`DEFAULT_WIZARDS`/`DEFAULT_DOMAINS`** -- these two **do** ship as real
  content in this repo (found, not invented): `config/sys/local.h` already
  had `postmaster`/`wiz`/`mrpr`/`lars`/`tintin`/`mercade`/`marvin` as
  pre-configured default wizards. Every entry, however, was only 5 elements
  (`{rank, level, chlevel, dom, chdom}`) while `secure/master/fob.lpc`'s own
  `FOB_WIZ_*` field constants define 8 (through `FOB_WIZ_STUDENTS`, index
  7) -- `query_restrict()` indexes `FOB_WIZ_RESTRICT` (5) with no per-field
  bounds check, so a short entry hard-errors ("Array index out of bounds")
  the moment *any* of these wizards (not just the admin account added for
  this port, see the README) hits a restrict/mentor/students check --
  happened for real on the very first `update` command tried as `fluffos`.
  Padded every entry to the full 8-element shape with each field's neutral
  default (0 restrictions, no mentor, no students) -- structural completion
  of a shape the codebase's own constants already document, not new
  content.
- Various file paths and small structural constants for admin/maintenance
  tools whose real backing files/configuration were never shipped:
  `secure/donation.h`-equivalent constants (`DONATION_SAVE`/`DONATION_LOG`/
  four `DONATION_LIMIT_*` USD tier thresholds -- the real historical dollar
  figures are lost, defined as a shared large sentinel so the tier logic
  never fires on an arbitrary invented amount, consistent with this repo
  having no live payment processing anyway; `DONATION_BROOCH`/
  `DONOR_BROOCH_ID`/`DONATION_OFFICE`), `secure/gog_accounts.lpc`'s missing
  `/d/Genesis/sys/deposit.h` (bank/gem-transfer file paths, mapping-key
  constants, and fee/transit-time numbers -- the latter given inert
  defaults: long delays, 0% fee), and `secure/bit_change.h`'s entirely
  admin-authored per-run configuration (the tool's own docstring says as
  much: "you must alter the bit_change.h header file accordingly ... run
  with a root or archwizard euid" -- a one-shot maintenance utility, never
  invoked during normal play, given safe no-op defaults matching that
  documented expectation).

## 7. `ARMAGEDDON` stale path + bootstrap landing room

Unlike the missing-content symbols in \S6, `ARMAGEDDON` (the
world-shutdown-orchestrator singleton, used pervasively -- checked
unconditionally on **every single login attempt** by `secure/login.lpc`)
is **not** missing content: its real implementation ships in this repo at
`secure/armageddon.lpc`, exactly like `SECURITY`/`DOCMAKER`/`MAP_CENTRAL`/
etc. (all defined in `sys/files.h` pointing at their real `/secure/...`
locations) -- but the `ARMAGEDDON` macro itself, in `config/sys/local.h`,
was still pointing at the original domain path `/d/Genesis/obj/armageddon`,
never updated to match. This turned every login into a hard, uncaught
`call_other() couldn't find object` crash. Fixed by pointing the macro at
`/secure/armageddon` instead.

Separately, `secure/login/bootstrap_room.lpc` was added: a deliberately
bare, purely-functional landing room (`std/room` base, no exits, no
decoration -- explicitly documented in its own header as infrastructure,
not game content) used as `WIZ_ROOM` and every `RACESTART` entry (\S6).
Without *any* real room anywhere in this repo, character registration
could never complete at all (see \S5/\S6's circular-dependency discussion)
-- this unblocks login/testing while making zero claim to represent
anything in an actual game world.

A handful of `OWN_STATUE` (`/d/Genesis/obj/statue`, another missing-content
path, used for a "linkdead players become a statue" feature) call sites
that skipped the `objectp(find_object(...))` guard most other call sites in
this codebase already use were fixed the same way (`secure/login.lpc`,
`std/player.lpc` x4, `secure/armageddon.lpc`) -- this crashed a wizard's
very first `quit`/password-check flow uncaught.

## 8. `std/container.lpc`'s `add_subloc()` foreach-on-int crash

`add_subloc(string sloc, mixed resp, mixed ids)` -- `ids` is `varargs`;
every 2-arg call site (the overwhelming majority, including
`std/living/inventory.lpc`'s `wear_reset()`/`wield_reset()`/`hold_reset()`,
called **unconditionally during every single living's creation**, players
and NPCs alike) leaves it at its default `mixed` value, `0`. The subsequent
`foreach (string aid in ids)` hard-errors on this driver ("Bad argument 2
to foreach: Expected array Got: 0") -- the CD driver evidently tolerated a
0-iteration loop over a non-array. This crashed **every single living
object's `create()`**, silently truncating it partway through (before
`enable_commands()`/`cmdhooks_reset()` ever ran) -- the underlying cause of
"no commands work" being observable well before the \S3 `add_action()` bug
was even found. Fixed with a `pointerp(ids)` guard defaulting to `({ })`.

## 9. Miscellaneous fixes

- **`secure/master/player.lpc`'s `purge_predeath()`**: `get_dir()` returns
  `0` (not `({})`) for a nonexistent directory on this driver, unlike the
  CD driver -- null-guarded (a login-letter bucket directory not existing
  yet is normal for a fresh install).
- **`std/player/savevars_sec.lpc`'s `query_auto_load()`/
  `query_recover_list()`**: unguarded, unlike their sibling
  `query_pending_auto_load()`/`query_pending_recover()` -- for a brand new
  character the backing variable is never initialized (stays the int `0`),
  and `std/player.lpc`'s `load_auto_files()`/the recover-file loader do
  `query_X() + query_pending_X()`, which this driver's `+` hard-errors on
  ("Bad type argument to +. Had int and array") for `int + array`, unlike
  the CD driver.
- **`std/act/launch_weapon.lpc`'s confirmation check**: upstream itself has
  misplaced parens, `lower_case(args != Target->query_real_name())` --
  calling `lower_case()` on a *boolean*, not on `args`. The CD driver's
  `lower_case()` evidently tolerated the wrong argument type silently; this
  driver's doesn't, surfacing what the surrounding comment already says was
  the intent (`lower_case(args) != Target->query_real_name()`). A
  pre-existing upstream bug this port's stricter driver simply exposed,
  fixed to match the documented intent rather than left broken.
- **`/data/` directory tree entirely missing** -- this repo ships no
  `/data/` at all, needed for player saves, board/mail/bank state, etc.
  Created the full expected structure (`data/players/<a-z>/`,
  `data/gog_accounts/<a-z>/`, `data/pinfo/<a-z>/`, plus flat
  `data/{banished,deleted,mail,mbs_save,messages,sanctions,saved}/`, each
  with a `.gitkeep`) after tracing several `save_object()`/`write_file()`
  failures back to the missing parent directories.
- **`/syslog/log/` runtime log directories** -- also entirely missing,
  hardcoded by paths throughout the codebase; created with `.gitkeep`
  placeholders (carried over from earlier in this session, before the
  boot/play-testing phase documented above).

## 10. Fragment/non-standalone files (false positives in a naive `lpcc`
sweep)

~45 files fail a flat, one-file-at-a-time `lpcc --batch` sweep but are
**not** bugs -- they are intentionally not standalone compilation units:

- `std/living/*.lpc`, `std/player/*.lpc`, `std/room/*.lpc`,
  `secure/master/*.lpc`, `cmd/wiz/apprentice/*.lpc`,
  `cmd/wiz/wizard/*.lpc` (42 files) are `#include`d as text fragments into
  their aggregator (`std/living.lpc`, `std/player.lpc`, `secure/master.lpc`,
  etc.) -- they compile fine as part of that file (confirmed via full
  driver boot with zero compile errors) but lack the standalone context
  (inherits, sibling fragment functions) a flat per-file sweep assumes.
- `lib/link_room.lpc` is a genuine mixin (`inherit`-style, providing
  `query_exit`/`query_short`/etc. it expects the inheriting room to
  already have) that is **never actually inherited anywhere in this
  repo** -- confirmed via a repo-wide grep. Dead code as shipped, not a
  bug; left as-is rather than inventing a fake inherit to silence the
  sweep.
- `lib/std_area/{preamble,postamble}.lpc` are read as raw **text** via
  `read_file()` by `lib/area_handler.lpc`'s auto-generated-room-file
  builder, never compiled as LPC objects at all.

A handful of additional files (`std/corpse`, `std/workroom`, `std/herb`,
`std/board`, `doc/workroom`, `secure/armageddon`, `secure/mbs_central`)
show as `lpcc` failures purely from a `create()`-time runtime crash inside
`lpcc`'s isolated single-object test harness (e.g. a `restore_object()`
permission error in a context with no real filesystem/euid setup) with
**zero actual compile errors** -- a previously-documented "lpcc-vs-live-
driver artifact" pattern for this project; the real driver boot (which
exercises the actual preload chain in the actual runtime environment)
shows these compiling and loading cleanly.

## WASM status (2026-08-25, another session)

Promoted `wasm_status` from `""` to `playable`. `pack_lib_for_web.sh`
initially failed outright (not a driver/compile issue): `doc/examples`
and `doc/man/Genesis` were dangling symlinks pointing at
`../d/Genesis/doc/...` -- the very game-world domain this archive never
shipped (see above) -- and emscripten's `file_packager` errors out
trying to `stat()` a broken symlink's target. Removed both (pure
documentation symlinks, irrelevant to boot/play) rather than fixing
their targets, since the domain they point at doesn't exist in this
repo at all. Once packed, the driver booted clean under WASM with no
further fixes needed. Verified with a real scripted WASM session:
login as `fluffos`/`Mud@2026`, the documented start-location fallback
firing correctly (no `/d/Genesis` domain to land in), a soul command
(`smile`) dispatching correctly (confirming the `add_action()` bare-
function-value fix carries over to the WASM build), and a clean `quit`
("Saving Fluffos. Goodbye. Until next time."). One caught-and-logged
(non-fatal) error during quit -- `call_other() couldn't find object
'/d/Web/stats/webstats'` inside a `catch()` -- is the same class of
graceful missing-domain-content fallback as the start-location one,
not a new bug.
