# QuestMud -- porting notes

Source: `git clone https://github.com/vlehtola/questmud` (cloned
2026-08-28). Slug `questmud`, number 945, port 40247. Mudlib root is the
clone's `lib/` subdirectory (`bin/`, `ftpd/`, `share/` alongside it are the
archive's own bundled driver/tools, ignored -- this project uses its own
FluffOS driver). Confirmed via `lib/secure/master.c` + `lib/secure/
simul_efun.c` before cloning; what that early check didn't catch is that
this is an **LDMud** mudlib, not MudOS-lineage like every other classic
LPMud in this collection so far -- a materially different porting job. MIT
licensed. 22,198 files in the raw clone, 12,565 `.c` files under `lib/`.

## 1. Conversion

`scripts/convert_lib.sh` on `raw/lib` -> `work`: source is English-language
and already ~99% ASCII/UTF-8 (735 lossy-conversion files out of ~21,000,
mostly Finnish wizard-name comments with accented characters -- the
original wizard team, per names throughout the archive like Ahma, Piikki,
Nalle, Rag, Siki, was Finnish), 12,565 files renamed `.c`->`.lpc`, 11,041
literal `.c"` references fixed, 6 local angle-bracket includes converted to
quotes, 231 files `static`->`nosave`.

## 2. The LDMud-vs-MudOS/FluffOS architecture gap

This is the first LDMud archive onboarded into this collection. LDMud and
MudOS/FluffOS share LPC syntax at a surface level but diverge sharply
underneath. Closure usage (`#'name`, `lambda`/`unbound_lambda`/
`bind_lambda`) turned out to be narrow in *scope* (36 files total, mostly
`secure/master.c` and a handful of scattered wizard sandbox files) but
every one of the driver-architecture-level gaps below was broad in
*impact*, since they sit in `secure/master.lpc`/`secure/simul_efun.lpc`
or otherwise get exercised by every single connection.

### 2.1 `secure/master.lpc`: `set_driver_hook()` doesn't exist

The entire original `create()`/`inaugurate_master()` chain existed to
install `set_driver_hook()`-based behavior for object creation,
uid-loading, and command dispatch -- none of which exists on FluffOS.
Replaced with a no-op stub, since FluffOS already hardcodes the equivalent
behavior directly:

- `H_CREATE_SUPER`/`H_CREATE_OB`/`H_CREATE_CLONE` -> `"create"`/`"reset"`:
  FluffOS always calls `create()` on load/clone and `reset()` on the
  normal reset cycle, unconditionally -- no hook needed.
- `H_LOAD_UIDS`/`H_CLONE_UIDS` -> `creator_file()`/`get_bb_uid()`:
  FluffOS calls `master::creator_file()` (a real apply, kept) for exactly
  this purpose, and inherits euid from the creating object otherwise.
- `H_MOVE_OBJECT0`: FluffOS's `move_object()` efun already has the
  init()-calling behavior this hook existed to install, built in natively
  (see \S2.4 for the *actual* move_object gap, which is different).
- `H_MODIFY_COMMAND(_FNAME)`/`H_NOTIFY_FAIL`/`H_INCLUDE_DIRS`: cosmetic
  (direction abbreviations, fail message, include search path) -- covered
  by `config.fluffos`'s "default fail message"/"include directories"
  instead.

### 2.2 `master::valid_read()` never had a case for `"load_object"`/`"include"` -- the single highest-impact fix in this whole port

FluffOS's `vm/internal/simulate.cc` (`load_object()`/`clone_object()`) and
`compiler/internal/lexer_utils.cc` (`#include` resolution) both route
through `master::valid_read(path, eff_user, call_fun, caller)` with
`call_fun` values `"load_object"`/`"recompile_object"`/`"include"` that
this LDMud-derived master's `valid_read()` switch had never needed a case
for (LDMud doesn't route object compilation through `valid_read()` at
all). Without a matching case, the switch falls through to its own
default (deny), so **every single object load and every single
`#include` in the entire mudlib was silently denied from the very first
boot** -- every preload line failed with a bare "Read access denied", and
every file's very first `#include <ansi.h>`/`"log.h"` failed with
"Cannot #include ...", cascading into hundreds of secondary "Undefined
variable"/syntax errors from the missing macros with no indication the
real problem was access control, not the files themselves. Fixed by
adding both cases to the existing permissive read policy (this lib's
`valid_read()` already allows `read_file`/`read_bytes`/`file_size` to
everyone):

```lpc
case "load_object":
case "recompile_object":
case "include":
case "restore_object": return 1;
```

### 2.3 `master::creator_file()`'s "no special uid" case returned a bare int -- broke loading nearly every non-wizard file

FluffOS's uid system (`packages/uids/uids.cc`'s `set_uid()`) hard-requires
`creator_file()` to always return a real uid **string**; any other return
type -- including the bare `1`/`0` LDMud used as its "no special
creator, ordinary system object" sentinel -- fatally destructs the object
being loaded with `"Illegal object to load: return value of
master::creator_file() was not a string"`, *even though the object had
compiled cleanly moments earlier*. This hit essentially every
non-`wizards/`-owned file the instant it got past its own compile errors
(confirmed live on `obj/timer`, `obj/wizlist`, `room/house_shop_d`,
`daemons/mastery_d`, and would have hit every other ordinary content file
in the mudlib). Fixed by returning `get_bb_uid()` (the existing
`"Backbone"` sentinel) everywhere the original returned a bare int or fell
off the end of the function with no return at all.

### 2.4 `move_object()` is 1-arg on this driver -- a corpus-wide dialect fix that only partially works

FluffOS's `move_object()` efun takes one argument and moves
`this_object()` only (`void move_object(object | string)`); the archive's
LDMud/older-MudOS convention is 2-arg (`move_object(item, dest)`, moving
an arbitrary object). This project's established mechanical fix for this
dialect gap is `move_object(A, B)` -> `A->move_object(B)`, applied
corpus-wide here too (9,873 sites/182 files via a paren-aware script, not
a flat regex, so nested-call arguments were handled correctly).

**This fix is only reliable when `A` is already `this_object()` at the
call site.** `call_other()` never falls back to an efun of the same name
when the target object has no matching LPC function of its own -- it
just returns `0` silently, no error, no exception. Confirmed live: a
brand-new character's own `myself->move_object("/obj/race_selection")`
(inside `obj/player.lpc`'s own registration flow, where `myself ==
this_object()`) *appeared* to work -- no exception, normal control flow
continued, the write()s after it printed fine -- but
`environment(myself)` was still `0` immediately afterward. A bare
`move_object(dest)` call from the same code worked correctly. This was
diagnosed by literally inlining a debug_message() with a `catch()` around
the call and comparing `find_object()`/`environment()` before and after.

**Fixed for the by-far-most-common case**: `obj/living.lpc` (inherited by
every player and monster via `living.h`) now defines a real
`move_object(dest)` method:

```lpc
mixed move_object(mixed dest) {
    return efun::move_object(dest);
}
```

This makes `X->move_object(dest)` a real, correctly-resolving function
call for any living (player, monster, NPC) target -- covering the
overwhelming majority of `->move_object(` call sites in this specific
mudlib (players/monsters moving themselves or being moved by daemons).
`efun::move_object` (not a bare recursive call) is required specifically
*because* the new function shares the efun's own name; using `efun::`
here needed its own separate fix, see \S2.5.

**Not fixed**: any `->move_object(` call site whose *target* is not a
living (money, weapons, corpses, and other clonable items that don't
inherit `obj/living.lpc`) still silently no-ops. This is a real,
confirmed-live, corpus-wide gap that a full future pass should audit --
grep the whole corpus for `->move_object(` and, for each target class
that isn't already living-derived, either add the same real
`move_object(dest)` wrapper to that class's own base file, or rewrite the
call site to run from inside the target's own execution context. Left
as documented, unfixed scope for this session given the size of the
corpus (12,565 files) and that the verified registration/play path above
doesn't depend on any of the remaining cases.

### 2.5 `efun::name(...)` outside `secure/simul_efun.lpc` requires `master::valid_override()`

The compiler's `efun::` override syntax (`compiler/internal/
grammar_rules_exprs.cc`'s `rule_efun_override()`) gates every use through
`master::valid_override(calling_file, identifier, main_file)`; with no
`valid_override()` defined at all, this silently *denies* every use once
`master_ob` is set (a `NULL` master apply return -> `master_approved()`
returns 0), which happens the moment `secure/master.lpc` itself finishes
loading. `secure/simul_efun.lpc`'s own many `efun::` calls (`efun::
map_delete`, `efun::file_name`, `efun::command`, etc., used throughout
this file's compat shims) never hit this because `simul_efun.lpc` loads
and compiles *before* `master_ob` is set (the "no master yet" bootstrap
allow case in `master_approved()`) -- but any `efun::` call anywhere else
in the mudlib, compiled lazily later during actual play, hit "Invalid
simulated efunction override" and failed to compile. First surfaced by
`obj/living.lpc`'s new `move_object()` wrapper (\S2.4) needing
`efun::move_object`. Fixed with a permissive `valid_override()`:

```lpc
int valid_override(string calling_file, string identifier, string caller) {
  return 1;
}
```

### 2.6 Wide/multi-value mappings -- no FluffOS equivalent at all

LDMud mappings can hold multiple values per key
(`(["key": v0; v1; v2])`, accessed via `map[key, N]` column indexing).
FluffOS mappings are always single-value. Every instance found this
session was converted to a single array value instead
(`(["key": ({v0, v1, v2})])`, read back as `map[key][N]`):

- `obj/player.lpc`'s `ability_train` (3 columns: current exp, exp
  target, training-destination guild).
- `room/banish_d.lpc`'s `names`/`sites` ban-tracking mappings (4/3
  columns).
- `daemons/guildrank_d.lpc`'s `leaders` (2 columns: score, leader name).
- `daemons/emote_d.lpc`/`daemons/emote_data.lpc`'s `e_map` (9 columns
  per emote verb -- ~190 individual emote entries converted via a
  quote-aware script, plus 2 entries that had wrapped onto a second
  physical line and needed hand-fixing after the automated pass).
- `cmds/std/_mail.lpc`'s `mail` (5 columns: sender, timestamp, subject,
  body, unread-flag).
- `guilds/guilds/guild_init.lpc`'s `guilds` (5 columns: display name,
  room path, description path, exp threshold, flag) and `multiguilds`
  (2 columns: two base guild names).

`daemons/leader_d.lpc`'s `leaders` mapping turned out to be a **false
positive** for this pattern: it's genuinely single-valued
(`leaders[race] = name`), but was *read* with `leaders[race, 0]`
LDMud-style column-0 indexing anyway (valid LDMud syntax for a
width-1 mapping, equivalent to plain `leaders[race]`) -- fixed by
dropping the `, 0` rather than wrapping the write side in an array.
Worth checking for this exact false-positive shape (write side is
single-value, read side still uses `[key, 0]`) before assuming every
`map[key, N]` site needs the full array-value conversion.

### 2.7 FluffOS's `reset()` is scheduled/lazy, not synchronous-on-load

LDMud calls `reset()` synchronously right after `create()` for every new
object (this mudlib's original `master.c` explicitly documented this:
"1. reset() will be called first... 4. The game will enter multiuser
mode"). FluffOS's `reset()` only fires on the normal reset-timer cycle
(`"time to reset"`, default here 3600s) unless `"lazy resets"` is
enabled in `config.fluffos`, in which case it fires on the object's
*first* `apply_low()`/`move_object()` touch instead -- **but even with
`lazy resets : 1` set, several daemons still had their `reset()`-
populated state read before `reset()` had run**, crashing with `*Value
being indexed is zero` on a raw-LPC-default (`int 0`) mapping. Confirmed
live, repeatedly, as the actual blocker for the very first character's
own registration flow (each fix below was found by tracing one specific
crash during a real registration playthrough, not by static analysis):

- `secure/simul_efun.lpc`'s `living_name_m`/`name_living_m` (the
  `find_living()`/`find_player()` name-index mappings) -- these were
  never going to get initialized via `reset()` at all, since they were
  originally populated by `start_simul_efun()`, itself only ever called
  from `master::get_simul_efun()` -- an LDMud-only master apply not in
  FluffOS's applies table, so never invoked. Fixed by initializing both
  directly at declaration (`mapping living_name_m = ([]), name_living_m
  = ([]);`) instead of relying on a function nothing calls.
- `daemons/guildrank_d.lpc`'s `leaders` -- fixed with a real
  `create() { reset(0); }` plus, belt-and-suspenders, initializing
  `leaders` with the same real 10-guild starting value directly at
  declaration (the first live repro showed `create()`->`reset()` alone
  still weren't enough the very first time this exact daemon was
  touched -- not fully root-caused given time constraints; the direct
  initializer is what actually fixed it).
- `daemons/multiguild_d.lpc`, `daemons/race_stats.lpc`,
  `world/special/traits.lpc`, `guilds/guilds/guild_init.lpc` -- all
  fixed with a straightforward `create() { reset(0); }`.
- `daemons/xp_rate_d.lpc` -- deliberately *not* given the `create()`->
  `reset()` treatment: its `reset()` chains into `process_tune()`->
  `add_race_xp()`->`race_stats.lpc`'s `query_race_stat()`, which itself
  assumes a real connected player context (`this_player()->
  query_guest()`, unguarded) that doesn't exist yet during a synchronous
  boot-time `create()`. Forcing the full chain surfaced a *new* crash
  (`this_player()` was `0`) instead of fixing the original one. Fixed
  `race_stats.lpc`'s missing null-guard as a genuine, narrow pre-existing
  bug (`this_player() && this_player()->query_guest()`) since that
  daemon-context call shape is legitimate, but left `xp_rate_d.lpc`
  itself with just direct mapping initializers rather than a forced
  `reset()`, to avoid trading one lazy-reset bug for a different
  "assumed player context" bug.

**This class is confirmed real and repeatable but almost certainly not
exhaustively found** -- every instance above was discovered by literally
playing through registration and reacting to each new crash, not by a
systematic corpus grep. A future pass should grep for every `mapping`/
`array` global that a file's own `reset()` populates and cross-check
whether anything in that same file (or callable from elsewhere) reads it
before `reset()` could plausibly have run.

### 2.8 Missing LDMud-only efuns, added as `secure/simul_efun.lpc` shims

- **`cat(file, start, num)`** -- prints a chunk of a file's lines,
  returns line count printed or 0 on failure. Genuinely load-bearing:
  582 call sites including the very first login banner
  (`obj/player.lpc` printing `/WELCOME`) and the "more"-style pager
  (`even_more()`/`cat_file()`). Implemented via `read_file()` +
  `explode()`/slicing.
- **`tail(file)`** -- print the last ~10 lines of a file. Already a
  cataloged pattern in this project's own AGENTS.md \S6.2 for a
  different lib; reimplemented the same way here.
- **`to_string(mixed)`** -- int/float->string conversion, 64 call
  sites. This driver's `+` operator already coerces int/float onto a
  string (confirmed elsewhere in this same mudlib), so
  `return "" + x;` is a safe, simple implementation.
- **`strstr(haystack, needle, start)`** -- this driver's `strsrch()` has
  the identical `(string, string|int, int start)` contract and -1-on-
  not-found return, so a direct passthrough alias was sufficient
  (24 call sites).
- **`unshadow()`** (bare, "remove every shadow layer on
  `this_object()`") -- used by this mudlib's real spell/status-effect
  system (haste, shield, heal_resist, stat_boost all `shadow()` the
  target for the effect's duration). Implemented by walking the shadow
  chain (`shadow(this_object(), 0)`) and `destruct()`-ing each layer,
  matching how `secure/master.lpc`'s own `prepare_destruct()` already
  tears down a shadow chain on this driver.
- **`object_name(object)`** -- this driver's real efun is the older
  MudOS name `file_name()` instead; `object_name()` doesn't exist here
  at all (confirmed: zero hits anywhere in this whole project's
  corpus/AGENTS.md before this lib, unlike every dialect gap already
  cataloged from the MudOS-lineage libs). The mudlib's own pre-existing
  `file_name()` simul_efun had it backwards (aliased `file_name` ->
  `object_name`, assuming `object_name` was the real one) -- flipped to
  alias `object_name` -> `efun::file_name` instead, so the handful of
  LDMud-native `object_name()` call sites (`secure/master.lpc`, `secure/
  simul_efun.lpc`'s own `geteuid()`, one wizard test file) work without
  breaking every other file's `file_name()` calls.
- **`creator()`/`domain()`** -- see \S2.9, a related but distinct bug
  from simply "missing efun".
- **`set_modify_command(ob)`** -- registers the (nonexistent, \S2.1)
  `H_MODIFY_COMMAND_FNAME` hook; stubbed as a no-op (cosmetic, direction
  abbreviations only).
- **`member(what, elem)`** -- LDMud's overloaded array-index-or-mapping-
  presence builtin (~70 call sites), reimplemented via `mapp()` +
  `efun::member_array()`. `member_array()` itself needed its own fix:
  the mudlib's existing `member_array(elem, arr) { return
  member(arr,elem); }` wrapper called the (missing) `member()` builtin
  with reversed argument order; replaced with a direct
  `efun::member_array(elem, arr)` passthrough (FluffOS already has a
  real `member_array` efun with the exact contract wanted).
- **`m_delete(mapping, key)`** -- on LDMud a real, non-mutating built-in
  efun (returns a *new* mapping with the key removed); this mudlib's own
  compat version of it shipped **commented out** in `secure/
  simul_efun.lpc` (since on LDMud it was never needed -- the driver
  already had a real `m_delete`). This driver has no `m_delete` efun at
  all, only `map_delete()` (void/in-place, the classic MudOS/LDMud
  `map_delete()` dialect split already cataloged in this project's
  AGENTS.md) -- re-enabled the mudlib's own commented-out shim, fixed to
  copy via mapping `+` (no `copy_mapping()` on this driver either) before
  calling `efun::map_delete()` on the copy. 35 files across the mudlib
  call `m_delete()`, including `obj/player.lpc` and several daemons.
- **`m_indices`/`m_values`** -> `keys`/`values`: already a cataloged
  MudOS/LDMud dialect gap in this project's AGENTS.md; swept
  corpus-wide (229 files/709 sites).

### 2.9 `creator()`/`domain()`: the *other* self-destructing-registration bug

Once \S2.3's `creator_file()` fix was in place, `obj/player.lpc`'s own
`reset()` had a second, independent bug that also self-destructed every
newly-registered character: `if (creator(this_object())) { ...
destruct(this_object()); }` is a "reject this if it looks like a
wizard's own ad-hoc clone of player.lpc, not a normal system-created
character" guard, and the mudlib's own `creator()` simul_efun was a bare
`getuid()` passthrough. Under real euid tracking every object always has
*some* uid (never LDMud's original int-0/1 "no special uid" sentinel,
per \S2.3), so `creator()` became truthy for literally every object,
including perfectly ordinary `clone_object("obj/player")` calls from
`master::connect()`. Fixed by filtering out the backbone/system uid
specifically:

```lpc
string creator(object ob) {
    string uid = (string)getuid(ob);
    return (uid && uid != (string)MASTER->get_bb_uid()) ? uid : 0;
}
```

## 3. Ordinary compile-time bugs (same class as every other lib in this
   collection, just discovered via an LDMud lens)

Once the architectural gaps above were fixed, the remaining errors were
the same familiar patterns already cataloged in this project's top-level
AGENTS.md, just numerous because this is a 12,565-file archive:

- **Untyped functions/parameters** (old-LPC implicit `int`/`mixed`,
  strict "unknown" on this driver): swept mechanically across the whole
  corpus with two scripts -- one adding an explicit `mixed` return type
  to every bare `name(args) {` definition (63,952 sites/many files), one
  adding `mixed` to every untyped parameter in the same definitions
  (15,171 sites). Both are strictly additive (they only add type
  information the compiler was missing; `mixed` is compatible with
  everything, so neither changes runtime behavior).
- **Declared-scalar-but-actually-array** (`object ob;` then
  `ob = all_inventory(...)`; `string s;` then `s = ({...})`; etc.): the
  single most common individual bug hit while chasing the registration
  path live -- dozens of instances across `obj/living.lpc`,
  `obj/player.lpc`, `room/room.lpc` (`property`, shared by every room in
  the mudlib via inheritance -- a single one-line fix here likely
  resolved a large fraction of the wider compile-sweep tail),
  `daemons/race_stats.lpc`, `daemons/guildrank_d.lpc`,
  `guilds/guilds/guild.lpc`, `obj/new_money.lpc`, `obj/timer.lpc`, and
  more. No corpus-wide mechanical fix attempted (each needs a human read
  of how the variable is actually used to know whether it's genuinely
  array-typed or the assignment itself is the real bug).
- **Same-file forward references** (this driver compiles one pass per
  file; a function called before its own textual definition needs a
  forward declaration first) -- extremely widespread, expected for a
  file this size (`obj/player.lpc` alone needed ~60 forward
  declarations). Fixed with a purpose-built script (parses out
  brace-depth-0 function definitions including multi-line signatures,
  finds bare calls preceding their own definition line, emits `mixed
  name();` prototypes) rather than by hand.
- **Base-class calls a function only the derived class defines**
  (`obj/living.lpc` calling `add_hunger()`/`add_thirst()`/
  `check_condis()`/`query_real_name()`/`add_hunter_list()`/
  `query_hunter_list()`/`wiz_commands()`/`wiz_commands2()`, all of which
  only exist in `obj/player.lpc`; `guilds/guilds/guild.lpc` calling
  `guild_name()`/`guild_max_level()`/`skill_list()`, which only exist in
  each individual derived guild room) -- this driver compiles each file
  standalone, so a base class genuinely cannot see a subclass-only
  symbol at compile time even though it works fine at runtime once a
  real subclass instance is what's actually calling it. Forward-declared
  each; documented as narrow, real, pre-existing gaps in the original
  mudlib's own class design (a bare `obj/monster.lpc` instance reaching
  `add_hunger()` would still hit a genuine runtime "Undefined function")
  rather than invented around.
- **Arg-count mismatches** (a function declared with N required params,
  called elsewhere with fewer) -- this driver treats these as hard
  compile errors unless the function is `varargs`; ~15 individual
  functions across `obj/player.lpc`, `obj/living.lpc`,
  `daemons/guildrank_d.lpc`, `daemons/race_stats.lpc`, `room/room.lpc`,
  `room/bank_d.lpc` made `varargs` to match their real, pre-existing
  call-site shapes (never invented a new default value beyond what the
  function body's own logic already treated a missing arg as, e.g.
  falsy/zero).
- **`status` as a legacy type keyword** (an old LPmud alias for `int`):
  swept corpus-wide (504 files/1,097 sites), same pattern as every other
  MudOS/LDMud-lineage lib in this project's AGENTS.md \S4.3.
- **A single genuine copy-paste bug**, unrelated to porting:
  `daemons/guildrank_d.lpc`'s `query_rank()` had `guild[i]` (indexing a
  scalar string parameter, giving a stray character code) where every
  sibling call in the same branch used plain `guild` -- a leftover from
  copy-pasting the function's own later array-loop version. Fixed to
  match the surrounding code.

## 4. Compile-sweep results

`scripts/lpcc_check.sh`: **12,565 files, 5,829 pass, 6,736 fail.** Of the
failures, 6,021 (89%) are inside individual wizards' own personal
`wizards/<name>/` sandboxes -- each wizard kept a full private copy of
core files like `player.lpc`/`living.lpc`/`guildrank_d.lpc` to
experiment on, confirmed via grep to never be referenced from the live
game (only the canonical `obj/player.lpc`, `obj/living.lpc`, etc. are
actually loaded) -- the same "wizard-sandbox clutter" shape this
project's AGENTS.md already documents for several other libs, just at a
larger absolute scale given this archive's size. Of the remaining 715
failures outside `wizards/`, the largest identifiable groups are
`doc/examples/*` (114 files, tutorial/template content, several
genuinely incomplete even in the original archive per their own
comments) and the `stronghold/` player-housing subsystem (5 files). None
of the 6,736 failures block the registration/play path verified live
this session (see `README.md`). The fix patterns in \S2/\S3 above would
likely close a large fraction of this tail if picked up as a future
sweep -- the declared-scalar-but-actually-array pattern and the
forward-reference script in particular are corpus-wide, mechanical, and
already proven safe on the files fixed this session.

## 5. Known limitations / deliberately left for future work

- \S2.4's `move_object()` gap is only fixed for living-derived targets.
- \S2.7's lazy-reset class is confirmed real but not exhaustively
  audited -- only the specific daemons that blocked the verified
  registration path were fixed.
- The 6,736-file compile-sweep tail (\S4) was triaged by category, not
  fixed file-by-file.
- WASM pass not attempted this session.

## §10.7 deep functional test (2026-08-31, round two)

Full continuous playthrough against `~/src/fluffos/build-debug/src/
driver config.fluffos` (the shared driver, no dedicated worktree
needed), several fresh throwaway registrations, following AGENTS.md's
own note that \S2.7's lazy-reset class was "confirmed real but not
exhaustively audited." It wasn't -- this pass found the single most
severe, most far-reaching bug in this whole port, well beyond what
\S2/\S7.158 already catalogued. Full technical writeup: **new AGENTS.md
\S7.192**. Summary here.

### SEVERE finding: `room/room.lpc` and `obj/monster.lpc` were both still missing the \S2.7 lazy-reset `create()` bridge -- this made essentially the ENTIRE explorable game world unreachable

Registering a fresh character (`Bragoth`, human Fighter) through the
full chargen flow and joining the Fighter guild landed in a room with
**no description at all and "No obvious exits."** -- a hard, silent,
total dead end immediately after character creation, for every single
new player, every time. Root-caused via `vm/internal/base/object.cc`'s
`call_create()`: it arms `next_reset` to an hour in the future BEFORE
`create()` even runs, so `try_reset()`'s lazy-resets check is already
false the instant any object finishes loading -- meaning `reset()`
(which is what actually populates `short_desc`/`long_desc`/exits via
`add_exit()`, per `room/room.lpc`'s own header comment) never fires
until a full hour after that specific room's first load, REGARDLESS of
`lazy resets : 1`. `room/room.lpc` (inherited by 5,368+ files
corpus-wide) and `obj/monster.lpc` (the base class for every NPC/
monster clone in the game) both had no `create()` of their own. Fixed
both with the same pattern AGENTS.md \S7.177 already established for
"universal base class, subclasses each override `reset()`" (a bare
`reset(0)` can silently no-op on this driver -- route through
`call_other()` instead):

```lpc
void create() {
    call_other(this_object(), "reset", 0);
}
```

### The reset() gap cascaded into a whole chain of previously-unreachable, independent compile/type bugs -- fixed one link at a time via live reproduction, not static analysis

Once `reset()` actually started running for the first time ever on
this driver, every bug hiding inside it (permanently dead code before
the fix) became a real, live, uncaught crash that aborts the calling
room's `reset()` PARTWAY THROUGH -- silently skipping whatever comes
textually after the crash point, including the room's own
`add_exit()`/description setup that always follows its initial
"populate my furniture/NPCs" `clone_object()` calls. Traced and fixed
via repeated live reproduction (join guild -> crash -> read trace ->
fix -> reboot -> repeat), not a static sweep:

- **`obj/monster.lpc`**: a dozen+ same-file forward-reference bugs
  (functions called before their own definition -- `random_move`,
  `short`, `query_invisible`, `test_match`, `check_al_aggr`,
  `pick_any_obj`, `follow`, `random_resists`, `set_skills`,
  `heart_beat`, `set_skill_chance`, `query_race`, `set_short`,
  `query_hunter_list`, `set_random_pick`, `random_combat_tactic`,
  `set_resists`, `query_resists`, `set_skill`, `set_spell_chance`,
  `query_animal` -- all forward-declared, same mechanical pattern as
  \S3's original sweep, just not caught for this specific file);
  `move_away()` called but never defined anywhere in the mudlib
  (forward-declared only, left as a genuine pre-existing gap per \S3's
  own precedent); several arg-count mismatches needing `varargs`
  (`query_limb`, `check_al_aggr`, `query_hunter_list`, `set_skill`,
  `random_resists`, `set_skills` -- each verified falsy-safe against
  its own body before adding `varargs`); declared-scalar-but-actually-
  array globals (`skill_chance`, `use_skill`, `spell_words`,
  `talk_func`/`talk_match`/`talk_type` -- the last three literally
  commented "Vector of ..." in the original source) and locals
  (`second_life()`'s `members`, `set_antiobjects()`'s `ob`); a missing
  `[i]` index in `set_skill_chance()`'s own array-copy loop (copying
  the whole old array into one slot instead of one element, same shape
  as `room/room.lpc`'s own already-correct `add_exit()` copy loop);
  plus its own missing `create()` (above).
- **`obj/living.lpc`**: `death(mixed force)` needed `varargs` --
  `obj/monster.lpc` calls it with 0 args in two places, and `force` is
  already used with a falsy-safe `!force` check in the body.
- **`obj/monster_data.lpc`**: `get_hp()`'s local `cost` declared `int`
  but assigned `allocate(21)` and indexed throughout -- `int *cost`.
- **`obj/base_object.lpc`**: `size` declared `string` alongside the
  file's other string fields, but every real call site
  (`set_size(2)`/`set_size(30)`/`set_size(5)`) and this file's own
  `get_size(int)` (0-100 numeric size code) treat it as `int` -- fixed
  the declaration, plus a same-file forward-reference on `get_size()`
  itself.
- **`wizards/siki/base_drink.lpc`** -- **a file this project's usual
  "wizards/ = personal sandbox, never referenced from the live game"
  assumption does NOT hold for**: `/world/objects/fountain.lpc` (the
  real, shipped fountain at the game's own Central Square) inherits it
  directly. A forward-reference (`get_drinks_left`) and a genuinely
  undefined `query_name()` (forward-declared only, per \S3's "base
  class calls a subclass-only function" precedent -- the one live
  caller, the fountain, always sets `liquid_type` and never reaches
  that branch) were both blocking Central Square's own `reset()`.
- **`cmds/std/_environment.lpc`**: a forward-reference (`return_color`)
  plus a false-positive instance of \S2.6's wide-mapping pattern -- `l`
  is a genuinely single-valued mapping but read with LDMud-style
  `l[key, 0]` column indexing in three places, fixed by dropping the
  `, 0` (same remedy \S2.6 already documented for `daemons/
  leader_d.lpc`'s identical false-positive shape).
- **`secure/master.lpc`**: `valid_read()` had no case for call_fun
  `"stat"` -- this driver's `get_dir()`/`stat()` efuns BOTH route
  through `valid_read(path, eff_user, "stat", caller)`
  (`packages/core/file.cc`), a different call_fun value than the
  `"get_dir"` case this master's switch already had (dead code on this
  driver -- never actually passed). Silently denied `get_dir()`
  return an int `0` instead of an array, which fell all the way
  through the race-selection room's own `sizeof(str)` guard with zero
  error -- "Available races:" printed as a genuinely empty list on
  every single registration. Fixed by adding `"stat"` to the existing
  permissive read policy alongside `read_file`/`read_bytes`/
  `file_size`.
- **267-file corpus sweep**: `string chat_str;` declared as a scalar
  but always assigned `allocate(N)` and indexed via
  `chat_str[0..N] = ...; load_chat(N, chat_str);` -- a copy-pasted NPC
  idle-chat idiom used across the ENTIRE archive (guild masters, city
  guards, wizard-realm NPCs, wild monsters). A quote-aware Python sweep
  found 294 candidate files, confirmed array usage (`chat_str[` or
  `chat_str = allocate(`) in 267 of them before fixing (27 correctly
  skipped as genuine single-string scalars, e.g. `world/misc/chat.lpc`).

### Verified live, end to end, after all of the above

Full continuous session, fresh registration each time a fix needed a
reboot: name -> password -> race selection (`Available races:` now
lists all 22 real races, not empty) -> special traits -> guild
selection (`select fighter`) -> **the Fighter guild room now shows its
real description AND all 5 exits** -> `east` onto Gold street (a real
citizen and city guard NPC both visible and correctly described, no
crash) -> `south` into **Central Square** (the game's own central hub
-- also showing its real description, all 4 exits, and a patrolling
guard NPC) -> `north` back. `quit` produced a clean disconnect with
`log/debug.log` never created (no uncaught errors) both before and
after every fix in this chain. A ~220s idle long-sit boot watch (real
driver stdout capture, not `debug.log` alone) produced zero new error
lines beyond the already-catalogued, unrelated 66-line compile-sweep
tail from \S4/\S5.

### What was NOT reached, flagged honestly rather than silently skipped

- **Combat**: `kill citizen` on an ordinary street NPC produced no
  visible combat exchange at all (no damage either direction over
  several heartbeat ticks) -- most likely this specific NPC/room is
  intentionally non-hostile "flavor" content (the newbie help text
  explicitly directs new players to dedicated zones instead: "City
  slums: 2s,2e,2s,1e", "Ant mines: 16s,11e,3s,6e,2n" from Central
  Square), not a bug; not chased further given the travel distance and
  time budget. No dedicated safe-sparring dummy/mechanism exists in
  this archive (grepped for the `accept_fight` pattern this project's
  own AGENTS.md documents as the thing to look for -- zero hits
  anywhere outside `wizards/`).
- **Skill training past the automatic background-advancement phase,
  and admin-shortcut guild assignment**: not reached -- the organic
  `select <guild>` path (verified above) is the only guild-join
  mechanism found in the explorable game; no separate admin/newbie-
  gift shortcut exists to cross-check against.
- **Shop/economy**: not reached, time-budgeted out in favor of the
  severe crash-chain fix above.
- **Death/respawn**: not reached; `help newbie`'s own "Death and
  logging in to the game" section describes a ghost/resurrection flow
  (ask a cleric-guild player, or accept a costly ress from an NPC
  called Khaland) that was read but not live-triggered.
- **Restore/reconnect path**: attempted, but **this lib's own
  `save_me()` deliberately no-ops** (`if (level < 2 && age < 3600 ||
  guest) return 1;` in `obj/player.lpc`) for any character below
  internal level 2 and under 1 hour old -- a design choice from the
  original 1996-2000-era archive (not something this session's fixes
  touched or should touch per scope discipline), most likely intended
  to avoid persisting throwaway newbie registrations. The "Saving
  <name>." message prints unconditionally regardless of whether
  `save_me()` actually persisted anything, which is genuinely
  misleading but was left alone as an in-scope-adjacent messaging
  quirk of an intentional gate, not fixed. Practical effect for
  testing: **a normal single-session `§10.7` playthrough cannot
  exercise the restore path for this lib** (every test character
  quits well under both thresholds) -- a future pass would need either
  a wizard-seeded high-level test account or a genuine 1-hour real-time
  session to verify reconnect/restore.
- **Minor, unresolved cosmetic observation**: a room's `look` output
  occasionally printed a stray bare `0` on its own line (once directly,
  once as `two times 0` via `daemons/string_stack_d.lpc`'s item-
  stacking formatter), implying some item's `short()` resolves to the
  literal string `"0"` rather than a real description in at least one
  placed object. Did not block navigation or any other functionality;
  not root-caused given time constraints -- flagged for a future pass
  rather than guessed at.

### Files modified this pass

`room/room.lpc`, `obj/monster.lpc`, `obj/living.lpc`,
`obj/monster_data.lpc`, `obj/base_object.lpc`,
`wizards/siki/base_drink.lpc`, `cmds/std/_environment.lpc`,
`secure/master.lpc`, plus 267 files (guild masters, city NPCs, and
wizard-realm monsters/NPCs archive-wide) for the `chat_str` array-type
sweep -- see AGENTS.md §7.192 for the full technical writeup.

## WASM measurement (2026-09-03)

`meta.json` was already `playable` from the 2026-08-31 deploy-unblock;
the README still said "not attempted." Cold-boot under the shared
`~/src/fluffos/build-wasm` succeeded with no new mudlib-side compile
fix. `work/` is ~378MB and copies into MEMFS without OOM. Verified
with `scripts/wasm_client.js` (`--timeout 300 --idle 0.4`): `c` →
`wasmqm` → password → `select human` → `continue` → `continue` →
`select fighter`. Landed in the Fighter guild of Duranghom with the
real room description, five exits, and Anrax the guildmaster visible.
`look` reprinted that room; `score` showed "Wasmqm. You are a level 1
Human" / "Primary guild: Fighters" / HP 86(141); `quit` printed
"Saving Wasmqm." The already-catalogued \S4 compile-sweep tail
(LDMud leftover `#'` closures, `No program in object` on
`/guilds/obj/skillfun`, `/cmds/std/_drop`, etc.) still prints at
preload and on `quit`'s drop-all path; none of it blocked the login
or play session. Shop/combat/death were not exercised this pass
(same gaps as the native §10.7 writeup). The MEMFS copy does not
write player saves back to the host, so `wasmqm` left no work-tree
debris.
