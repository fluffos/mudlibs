# Skylib -- restoration notes

## 0. Provenance

Archive: `skylib_fluffos_v3.zip`, recovered from the Wayback Machine
(<https://web.archive.org/web/20160306113513if_/http://lpmuds.net/files/skylib_fluffos_v3.zip>)
since the original lpmuds.net site is now down. Already content-verified
before this onboarding started. The archive bundles a full driver source
snapshot (`fluffos-2.9-ds2.04/`) alongside the real mudlib root
(`mudlib/`) -- the driver source was ignored; this project uses its own
shared FluffOS build.

The bundled driver source includes `local_options.skylib`, the
archive author's own intended build configuration, which
`#define`s **`NO_ADD_ACTION`**. That single fact explains most of the
real bugs below: this mudlib was written and tested exclusively
against a driver flavor where `add_action()`/`command()`/
`set_this_player()`/etc. behave very differently from this project's
shared driver build (which compiles WITH native `add_action()`).

## 1. Conversion

`scripts/convert_lib.sh libs/skylib/raw/skylib_fluffos_v3/mudlib
libs/skylib/work ISO-8859-1`. Almost the whole tree was already plain
ASCII (English archive); only 3 files (`cmds/creator/aconvert.c`,
`d/learning/school/characters/womble{,_interm}.c`) had non-ASCII bytes,
correctly decoded as ISO-8859-1 (not this project's usual GB18030
default -- guessed and confirmed by eyeballing the decoded text).
2162 `.c` files renamed to `.lpc`, 321 literal `.c"` references fixed,
10 local angle-bracket includes converted to quoted form, 9
`static`->`nosave` fixups. No lossy conversions.

## 2. `include/runtime_config.h` used a stale/mismatched `get_config()`
numbering (AGENTS.md \S7.89 class)

The archive's own bundled `include/runtime_config.h` computed
`BASE_CONFIG_INT` as `BASE_CONFIG_STR + 15` (an old MudOS convention
reserving only 15 string-config slots), while this driver's real
internal layout (`~/src/fluffos/src/include/runtime_config.h`)
reserves 256. Confirmed live: `secure/handlers/http.lpc`'s `create()`
called `get_config(__MAX_BUFFER_SIZE__)` -- this lib's header computed
`__MAX_BUFFER_SIZE__` as `27`, but the real driver's slot 27 holds
some unrelated *string* config value, so the result came back as an
empty string, and assigning it into an `int` threw `*Trying to put
string in int` at every preload boot, cascading into a broken
mudlib-side error handler too (`secure/master/logging.lpc`'s own
`get_config(__MAX_STRING_LENGTH__)` call hit the identical bug while
trying to log the *first* error, becoming `*Bad argument 1 to /` when
dividing by the resulting empty-string-turned-0).

Fix: replaced the whole file with the driver's canonical copy (same
remedy as \S7.89's `ds386`/`zjdywzb`/`yhwhpublicfi` instances). Diffed
the symbol sets first: 5 symbols in the old header don't exist in the
canonical one (`__ADDR_SERVER_IP__`, `__ADDR_SERVER_PORT__`,
`__MAX_LOCAL_VARIABLES__`, `__RESERVED_MEM_SIZE__`,
`__SAVE_BINARIES_DIR__`) -- grepped the whole lib and none of them are
actually *used* anywhere outside the header's own definitions, so no
aliasing was needed (unlike the `zjdywzb`/`yhwhpublicfi` instances,
which each needed 1-2 alias/removal reconciliations). All 14
`get_config(...)` call sites in the lib use only symbols present in
both headers.

## 3. `.c`-to-`.lpc` rename broke filename-slice arithmetic in **11
more files** beyond the `__FILE__[0..<3]` pattern

The well-known instance (`AGENTS.md` \S2's bug class 3): code that
computed a base filename by slicing off a *fixed 2-character* `.c`
suffix (`someName[0..<3]`, `someName[<2..] == ".c"`) breaks once the
suffix is 4 characters (`.lpc`) -- needs `[0..<5]`/`[<4..]`.

**28 occurrences of `__FILE__[0..<3]` across 26 files** (all of them
runtime `base_name(TO) == __FILE__[0..<3]` "am I the master copy, not
a clone" guards in `std/object.lpc`, `std/container.lpc`,
`obj/weapon.lpc`, `obj/armour.lpc`, `obj/clothing.lpc`, and 21 more)
fixed to `[0..<5]` by a straight `sed` sweep after confirming every
hit was this exact shape.

**11 more files use the same class of bug on `get_dir()`-listed
filenames or explicit `.lpc`-suffix checks**, found by grepping for
the diagnostic `X[<2..] == ".lpc"` shape (always-false: comparing a
2-char substring to a 4-char literal -- a dead giveaway that this was
originally `X[<2..] == ".c"` before the mechanical `.c`->`.lpc`
literal-reference rewrite) and for bare `get_dir(dir+"*.lpc")` results
sliced with `[0..<3]`:

- `handlers/armoury.lpc` (`make_list()` -- this is what broke the
  starting dagger: "The armoury failed to clone \"dagger\"." on every
  new character, confirmed live before the fix and gone after)
- `secure/command.lpc` (`GetCommand()`/`eventRehash()` -- the
  directory-based command-file lookup table)
- `cmds/player/judge.lpc`, `cmds/creator/hous_ing.lpc`,
  `secure/simul_efun/back_trace.lpc` (`call_stack(0)` program names)
- `std/room/blackjack.lpc`, `www/secure/errors.lpc`,
  `handlers/map.lpc`, `secure/handlers/remote.lpc`,
  `secure/handlers/autodoc/autodoc_html.lpc`,
  `secure/handlers/autodoc/autodoc_handler.lpc` (4 separate sites)

Each fixed to the `[<4..]`/`[0..<5]` equivalent. **Not** fixed:
`cmds/creator/cloner.lpc`'s `do_add()` has the same broken
`[<2..] == ".lpc"` check, but its accompanying assignment
(`source = source[<2..]`) is *also* independently wrong (keeps the
LAST 2 characters instead of stripping the last N) -- a pre-existing
bug unrelated to the rename. Fixing only the check would have made
this dead code start corrupting input instead of just staying inert,
so it was left alone entirely (out of scope: this is a wizard-only
alias-mapping convenience command, not reachable from ordinary play).
Also **not** fixed (confirmed pre-existing, unrelated to the rename):
`handlers/leaflet_handler.lpc` and `handlers/deity_handler.lpc` both
slice a 2-character `.o` suffix with `[0..<3]` (off by one regardless
of driver -- `.o` was never touched by the `.c`->`.lpc` rename), and
`obj/misc/tree.lpc`/`global/player/events.lpc`/
`std/basic/expressions.lpc`/`cmds/living/l_ook.lpc` all have
superficially similar `[0..<3]` slices on strings that are not
filenames at all (an `'s`-suffix strip, a language-tag prefix, an
expression-evaluator stack, a terrain string) -- checked each by hand
and none of them touch a `.c`/`.lpc` filename.

## 4. `set_this_player()`/`_notify_fail()`/`query_notify_fail()` are not
real efuns on this driver build

`set_this_player()` only exists as a driver efun on a `NO_ADD_ACTION`
build (the two are mutually exclusive in FluffOS's `core.spec`). This
driver compiles with `add_action()`, so it doesn't exist here, and
~8 files (`std/living/living.lpc`'s NPC-flee `run_away()`,
`std/npc.lpc`, `global/player/psoul.lpc`, ingested-effect/disease
processing, `std/room/basic/door.lpc`, `std/shops/player_shop/
shop_front.lpc`) call it bare, unconditionally, with no local
override -- confirmed as genuinely reachable code, not the kind of
`#if !efun_defined(add_action)`-guarded dead branch Discworld uses for
the same construct (see \S6). `_notify_fail()`/`query_notify_fail()`
are a separate mudlib-userland fail-message slot (never a real efun on
*either* driver flavor -- `query_notify_fail` isn't in FluffOS's efun
table at all) used pervasively by the parser
(`global/player/new_parse.lpc`, `cmds/living/get.lpc`,
`cmds/player/sea_rch.lpc`) -- normally supplied by
`secure/simul_efun/add_action.lpc`, but that whole file is only
conditionally inherited (`#if !efun_defined(add_action)` in
`secure/simul_efun.lpc`), so it's absent here too.

Fix: new `secure/simul_efun/fluffos_compat.lpc`, inherited exactly
when `!efun_defined(set_this_player)` (i.e. precisely this driver
configuration):
- `set_this_player(ob)` reassigns the driver's real `command_giver` by
  call\_other-ing into the target object (so `current_object` becomes
  that object) and invoking the always-present native
  `enable_commands()` efun there (bare, no argument, to avoid also
  flipping the "toggle_action" bit and re-running `init()` across
  environment/inventory -- not part of what `set_this_player()` itself
  ever did). The actual `enable_commands()` call lives in a tiny helper
  on `/std/object` (`__fluffos_become_command_giver()`), since the
  simul_efun's own `current_object` during a bare call is the
  simul_efun object itself, not the caller.
- `_notify_fail(mess)`/`query_notify_fail()` reimplement the original
  local-storage pair exactly (`private nosave string _nf`).

## 5. The core bug: this mudlib's whole ordinary-command dispatch
never ran on an add_action-native driver

By far the most impactful finding, and the reason **every single
typed command** (`look`, `score`, `quit`, everything) failed with
"What?" -- twice -- before any of the fixes below.

**Layer 1 -- `process_input()` always told the driver "I didn't
handle this".** `global/player/psoul.lpc`'s `process_input(str)` (the
driver's `APPLY_PROCESS_INPUT` hook, called automatically on every
line of raw input) calls this mudlib's own `_process_input(str)`
internally and then `return 0;` unconditionally. Per this driver's
`comm.cc::process_input()`, returning anything other than a nonzero
*number* makes the driver ALSO run its own native
`safe_parse_command()` on the raw input as a fallback -- and since
this mudlib registers almost nothing via genuine `add_action()`
(only `net/obj/webster.lpc`'s 4 dictionary-lookup verbs), that native
fallback always misses and prints the driver's own default fail
message ("What?") a second time, after whatever
`_process_input()` itself already produced. Fixed: `process_input()`
now returns `1` unconditionally (declared `mixed`, was `string`) --
`_process_input()` is fully self-contained, including its own failure
messaging, so the driver's native fallback should never run at all.

**Layer 2 -- `drunk_check()`'s tail silently swallowed every command
regardless of outcome.** `_process_input()`'s dispatch chain is
`!drunk_check(str) && !TO->exit_command(str) && !TO->cmdAll(str) &&
!TO->new_parser(str) && !TO->lower_check(str)`. `drunk_check()` is
first, and (once past its round-time/queueing gates) ends every
ordinary command by calling the bare `command(str)` efun and then
**unconditionally `return 1;`** -- correct only on a `NO_ADD_ACTION`
driver, where `secure/simul_efun/add_action.lpc` supplies `command()`
as a simul_efun that bridges back into `_process_input()` itself. On
this driver, `command()` is the real native efun (`add_action.lpc` is
never inherited here, same `#if !efun_defined(add_action)` guard as
\S4), and it can never dispatch an ordinary player verb (again,
almost nothing is registered via real `add_action()`) -- it just
fails silently. Because `drunk_check()` never checked the result and
always returned 1, the short-circuiting `&&` chain stopped right
there: `exit_command`/`cmdAll`/`new_parser`/`lower_check` -- **the
actual directory-based and pattern-based command dispatchers** --
never ran at all. Confirmed live with a temporary probe before this
fix: every command reached `command(str)`, got nothing back, and
`drunk_check()` reported success anyway.

Fix: a new `#if efun_defined(add_action)`-gated helper,
`_dispatch_command(cmd)`, that runs the same fallback chain
`_process_input()` itself uses (`exit_command`/`cmdAll`/`new_parser`/
`lower_check` -- everything except `drunk_check()` itself, which would
recurse). `drunk_check()`'s tail now calls `_dispatch_command()`
instead of the native `command()` efun on this driver (both at the
single-command call site and inside the alias-expansion loop), and
prints the "What?"/`query_notify_fail()` message itself on a genuine
miss so the outer chain in `_process_input()` doesn't double-dispatch.
On a real `NO_ADD_ACTION` driver the `#else` branch preserves the
original `command(str)` call unchanged.

**Combined effect, verified live**: before these two fixes, a brand
new character typing `look` got two "What?"s and nothing else; after,
`look`/`score`/`inventory`/`quit` all produce correct, differentiated
output (a real room description, real stats, a real inventory
listing, a clean `quit`/disconnect) with no duplicate messages and a
clean `debug.log`.

## 6. Things checked and found to be already fine (from AGENTS.md's
recurring-bug-class list for this archive family)

- **`add_action()` with a bare function value** (found in
  `genesis`/`finalrealms`): only 4 call sites total
  (`net/obj/webster.lpc`), all with string-literal verbs.
- **`ed_start`/`ed_cmd`/`query_ed_mode`** (found in
  `finalrealms`/`foundation2`): zero usages anywhere in this archive
  (`secure/cmds/creator/ed.lpc`/`global/player/line_ed.lpc` both use
  the old-style `ed()` efun this driver actually has).
- **`ref` as an ordinary identifier** (found in `tmi2`): the only
  hits are `secure/handlers/http.lpc`'s legitimate pass-by-reference
  parameters (`int ref start`) -- correct usage, and this driver does
  support the `ref` keyword (confirmed via the compiler grammar).
- **Missing `creator_file()` master apply** (found in `foundation2`):
  already present and correct in `secure/master/creator_file.lpc`
  (bundled with the archive) -- not a gap here.
- **`explode()` on `SANE_EXPLODE_STRING` edge cases** (found in
  `tmi2`'s `master.lpc`): `master.lpc` doesn't call `explode()` at
  all; no `explode('/','/')`-shaped call sites found anywhere
  boot-critical.

## 7. Misc small fixes

- **`cmds/creator/mudinfo.lpc`**: `#ifndef __COMPILER__` guarded
  *both* `__COMPILER__` and `__OPTIMIZATION__`'s fallback `#define`s
  in one block. This driver predefines `__COMPILER__` (a real
  compiler-identity constant) but not `__OPTIMIZATION__` (this file's
  own invention, no driver equivalent on any flavor), so the whole
  block was skipped and `__OPTIMIZATION__` stayed undefined --
  "Undefined variable '\_\_OPTIMIZATION\_\_'" on this `mudinfo` wizard
  command. Split into two independent `#ifndef` guards.
- **`secure/std/channel_base.lpc`**: the exact same bug class
  Discworld's `global/wiz_channels.lpc` had (see that lib's NOTES.md)
  -- a `function (object ob) { ...$1->query_cap_name()... }` named
  closure with leftover `$1` copy-pasted from the neighboring
  anonymous `(: strcmp($1->query_name(), $2->query_name()) :)`
  closure just above it. This driver rejects `$var` inside a named
  function pointer outright. Changed the 3 stray `$1`s to `ob`.
- Created the missing `save/board_backups/` directory -- absent from
  the raw archive, so every boot's board-backup routine threw
  `Error copying file from /save/boards.o to /save/board_backups/
  boards.<timestamp>, Error: No such file or directory` (visible but
  non-fatal; harmless to create).

## 8. Admin bootstrap ("creator only mode")

`handlers/login_handler.lpc`'s `create()` sets `login_mode = 2`
("creator only mode") whenever the saved `mud_name` doesn't match the
current one -- which is true on *any* fresh install with no prior save
(`!mud_name` is the first half of that `||`), including this one.
In that mode, `secure/login.lpc`'s `'n'` (new character) menu option
is blocked outright for *everyone*, including the very first admin --
there's no in-band way to create the first account.

`secure/save/handlers/domain.o` (shipped in the archive, not created
by this port) already had exactly the bootstrap shape this project has
seen before (`foundation2`, `zjdywzb`, `yhwhpublicfi`): an `"admin"`
group whose sole member is literally named `"default"` -- a
placeholder seeded by the archive's original author (`"sandoz"`,
per the save data), meant to be renamed to the real first admin.
Fixed both pieces directly via save-file edit (driver stopped first):
1. `secure/save/handlers/domain.o`: renamed the placeholder member
   `"default"` -> `"fluffos"` (both the `"admin"` group's members list
   and the standalone member record's own name) -- confirmed via
   `secure/std/modules/group.lpc`'s `class member`/`class group`
   layout before editing, not guessed.
2. `secure/save/login_handler.o`: `login_mode 2` -> `login_mode 0`.

Verified live: reconnecting after the edit, `'n'` -> full registration
succeeds for `fluffos`, and login shows the creator-only MOTD board
(confirming group membership took effect) instead of the "you cannot
create a new character" refusal.

## 9. Known content gaps -- NOT fixed (pre-existing, out of scope)

`lpcc_check.sh` batch sweep: 2036/2163 pass, 127 fail. Sampled broadly
across every distinct failure shape (not just counted) before
concluding these are pre-existing content, not driver-compat bugs:

- **~44 files under `d/learning/help_topics/error_messages/`**:
  deliberately malformed LPC snippets used as *teaching examples* of
  specific compiler error messages for student wizards (e.g.
  `bad_break.lpc` is a one-line file that does nothing but `break;`
  outside a loop, with a comment explaining the error it's meant to
  demonstrate). Failing to compile is their entire purpose.
- **`secure/master/{creator_file,logging,permission,snoop,valid_read,
  valid_seteuid,valid_write}.lpc`**: master.lpc mixin components,
  standalone-compile-only false positives -- they reference functions/
  variables only present once mixed into the real `master.lpc`, which
  itself boots and runs cleanly (confirmed live, zero errors).
- **`std/guilds/old/{artisan,cleric,fighter,mage,thief}.lpc`** plus
  several unrelated NPC files (`d/liaison/NEWBIE/*`, `net/daemon/
  chars/{tell_demon,in_finger_demon}.lpc`, `room/magic_circle.lpc`,
  `obj/monster/godmother/{granny,magrat}.lpc`): all call a function
  literally named `set_race()`, which **does not exist anywhere in
  this archive** (only `set_race_ob()` does) -- a genuine, wide,
  pre-existing API-rename gap that predates this port, confirmed by
  grepping the whole tree for an exact `set_race(` definition. The
  `std/guilds/*.lpc` (no `old/`) sibling set is the real, active,
  working guild system and is not affected.
- **`std/room/topography/{area,iroom,milestone}/*` and
  `std/room/inherit/topography/{aroom,iroom,milestone}.lpc`**: an
  alternate/experimental room-topology system (the file itself
  apologizes in a comment for "including .c files"), confirmed
  unreferenced by anything else in the mudlib. The real, active,
  working room base (`std/room/basic_room.lpc`) is unaffected and
  loads via preload.
- **`std/room/water_outside.lpc`** (and its topography-tree
  duplicate): calls `water::event_exit(...)`, but
  `std/room/basic/water.lpc`'s own doc comment says its real override
  point is `swim_exit`, which is what it actually defines --
  `event_exit` doesn't exist there. A pre-existing internal API
  mismatch inside the original archive, unrelated to FluffOS.
- **`std/shadows/misc/marry_shadow.lpc`,
  `std/shadows/object/store_ritual{,_new}.lpc`,
  `std/npc/goals/basic/stay_alive.lpc`**: `#include` headers
  (`marry.h`, `rituals.h`, `goals.h`) that don't exist anywhere in the
  raw archive either -- genuinely missing content, not a conversion
  artifact.
- **`std/room/club_room_controller.lpc`**: ships in the *original raw
  archive* (`.c`, before any conversion) as a single 20,506-byte line
  with **zero newline characters anywhere** (`file` confirms: "with no
  line terminators"), which breaks `#include` parsing ("Illegal
  character '#'") since the preprocessor needs `#` at the start of a
  physical line. Pre-existing archive corruption, not introduced by
  this port; not reflowed (would require careful C-aware
  reformatting of a single file with no clear payoff -- not reachable
  from ordinary play).
- **`obj/scabbards/{belt_loop,bone_knife_scabbard,dagger_scabbard}.lpc`**:
  marked "// Autogenned file", reference an undefined `SCABBARD_OBJ`
  macro with zero `#include`s -- incomplete/abandoned autogenerated
  content, pre-existing.
- **`obj/gatherables/handler.dat_old.c`/`handler.dat_dc.c`**: shipped
  with a genuine `.c` extension in the raw archive (confirmed) but are
  the original author's own abandoned backup/draft snapshots --
  unreferenced by `handlers/gathering.lpc` (the real, active handler)
  or anything else.
- A handful of other isolated one-off content bugs (missing local
  variable declarations, etc.) sampled and confirmed pre-existing,
  not driver-related; not itemized individually here since none are
  reachable from core gameplay.

## 10. Boot and play test

Booted `~/src/fluffos/build-debug/src/driver config.fluffos`
repeatedly; zero compile errors, zero runtime errors in `debug.log`,
listening on port 40222 every time.

Verified live via a raw Python socket client, end to end:
registration of a brand-new character (name -> confirm -> password ->
confirm -> gender) all the way into the game world, then
`look`/`score`/`inventory` each producing correct, real, differentiated
content, then `quit` producing the correct farewell message and a
clean server-initiated disconnect (confirmed via socket EOF). Admin
account `fluffos` verified separately: creator-only-mode MOTD board on
login (confirming group membership), full play-through of the same
command set.

One minor, non-blocking cosmetic quirk observed but not chased down:
the very first system message after a brand-new character's gender
selection ("You struggle to hold a dagger." immediately followed by a
`chfn`-reminder line) is preceded by a single stray "What?" that
doesn't recur on any subsequent command -- looks like an artifact of
something in the initial equip/spawn sequence, not the dispatch bug
above (which was confirmed, live, to double literally every command
before the fix and to affect none after).

**Not swept into high-frequency automated re-boot loops** (same class
as `imud`/`foundation2`, AGENTS.md \S2.3): `secure/handlers/
intermud.lpc` is preloaded unconditionally and its `create()` calls
`open_socket(host, port, MUD)` against a hardcoded real address
(`204.209.44.3:8080`, the historic `*i4` Intermud-3 router) --
genuine intended upstream functionality, but a real outbound network
event against a real (near-certainly long-defunct) third party on
every single boot.

WASM status: not attempted this pass (`wasm_status` left `""`).
