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

## WASM status update (2026-08-26, another session)

Promoted `wasm_status` from `""` to `playable`. Same by-now-routine
eager-simul_efun sockets gap as several sibling libs from this same
source: `secure/simul_efun/dump_socket_status.lpc` called
`socket_status()` unconditionally. Gutted to a safe stub (diagnostic
admin tool only, not on the boot/login path). Verified with a scripted
WASM session: login (`fluffos`/`Sky@2026Pass`), arrival in `/room/
tavern` with the correct description, and `score` producing correct
stats output -- also confirms the earlier `add_action()`/`NO_ADD_ACTION`
command-dispatcher fix carries over correctly to WASM (commands
dispatch fine here, not swallowed). `quit` wasn't recaptured distinctly
in this transcript but is already verified clean under native testing
above.

## Deep functional test (round two, 2026-08-27)

Confirmed via grep before starting that this lib had never had a full
§10.7 round-two playthrough (only the onboarding-tier verification
above). One continuous session throughout, via a raw Python socket
client (`~/src/fluffos/build-debug/src/driver config.fluffos`, port
40222), admin account `fluffos`/`Sky@2026Pass` (NOT the project's
usual `Mud@2026` -- confirmed live that this lib's login rejects that
password; the earlier WASM-status entry above already recorded the
correct one, `Sky@2026Pass`, which this pass used directly instead of
rediscovering it the hard way).

### Content-reachability note (methodology point 6)

This archive is a "distribution library" release, not a finished
game: the only room reachable from `CONFIG_START_LOCATION`
(`secure/include/config.h`) is `/room/tavern`, which has **no exits at
all** (`std/room/*` ships 14 room files total, none linked to it).
The Discworld-lineage newbie zone that exists in the tree
(`d/liaison/NEWBIE/{foyer,combat,guilds_foyer,shop,trainer,dummy,...}`)
is entirely disconnected from this graph -- confirmed by grepping
`CONFIG_START_LOCATION`'s only definition and by tracing `foyer.lpc`'s
own exits, none of which lead back to `/room/tavern`. Reaching it even
via admin `go_to` throws a live compile error (`d/liaison/NEWBIE/
dummy.lpc:29-32`: `Undefined function set_race/set_class/set_level`) --
this is the *exact* pre-existing, already-documented content gap from
this NOTES.md's own §9 (`set_race()` renamed to `set_race_ob()`
mudlib-wide, `d/liaison/NEWBIE/*` explicitly listed as one of the
affected files), not a new finding. Net effect: **guild/sect
acquisition, combat, shop/economy, and death/respawn could not be
exercised live** -- there is no reachable NPC, shop, or guild-join path
from the only connected room, and no `advance`/"join guild" command
exists either (`std/guilds/{standard,fighter,mage,cleric,thief,
artisan}.lpc` are real, working guild classes, but nothing in the
reachable graph ever offers to enroll a player into one). This is
being stated explicitly per point 6 rather than silently skipped.
What *was* fully exercised live, repeatedly, in one continuous
session: registration, `look`/`score`/`i` at every state change,
`chfn`'s full multi-step prompt chain, various soul/utility commands,
`quit`, a real-wall-clock-gap reconnect with full inventory/stat
persistence verified (see below), and the admin account separately.

### Bug 1 (fixed): dead, permission-blocked `set_name()` call on every single login -- harmless only by lucky redundancy

`secure/login.lpc`'s `begin2()` (the only code path that finishes
building a freshly-cloned player object after a successful
login/registration) called:

```
new_copy->set_name( query_name() );
```

`global/player.lpc:999`'s `protected void set_name(string str)` is the
*only* place in the whole mudlib that calls `set_living_name()` for a
player object on this driver flavor (the classic-driver equivalent,
`secure/simul_efun/add_action.lpc`'s own `set_living_name` plumbing,
is `#if !efun_defined(add_action)`-excluded here per this file's own
§4/§5 findings). Calling a `protected` function via `call_other` from
a *different* object requires `public` access on this driver
(confirmed directly against `~/src/fluffos/src/vm/internal/apply.cc`'s
`need`/`funflags` check) -- so this call was blocked outright on
**every single login, every character, every time**, confirmed via a
clean-reboot test that produced exactly one `apply() with insufficient
permission: ... function: set_name ... needs: public, has: protected`
line on driver stdout per login (never in `debug.log` -- this class of
warning is stdout-only on this driver, another reason to always
capture stdout per §10.8, not just `debug.log`).

**Verified empirically that this had zero live effect** before
concluding it was a real, fixable bug (per this project's "verify
before fixing a pattern-matched shape" rule) -- a live collision test
(register `vexbadger` in one connection, hold it open, attempt to
register the identical name from a second connection while the first
is still connected) proved `find_player()`/`set_living_name()` *did*
work correctly despite the blocked call. Root cause: a few lines
later in the same `begin2()`, `new_copy->move_player_to_start(...)`
calls a *bare* (unqualified, same-object) `set_name(bong)` internally
on line `global/player.lpc:271` -- a same-object call satisfies the
driver's lower `private`-level permission requirement regardless of
the function's `protected` declaration, so the name gets set
correctly via this second, redundant path every time. The first call
was simply 100% dead code, its only observable effect being the
per-login stdout warning.

**Fix**: deleted the dead line (`secure/login.lpc`, `begin2()`) rather
than trying to make it work, since the real, working call already
exists two paths later and nothing between them depends on the name
being set early. Verified live: a clean reboot plus a fresh
registration now produces **zero** `apply() with insufficient
permission` lines on stdout, and naming/`find_player()`/reconnect
collision detection all still work identically to before.

This is a new instance of the general access-modifier-blocks-a-
call_other shape AGENTS.md §8.3a already tracks (that entry is
specifically about command-dispatch/callback/call_out targets; this is
a plain cross-object setter call instead, so it's being logged here
rather than folded into §8.3a's own confirmed-instances list). Also
checked §8.3a's actual named shape directly: skylib's real
command-dispatch chain (`global/player/command.lpc`'s `cmdAll()`,
`call_other(verb->file, "cmd", ...)`) requires every command file's
`cmd()` to be `public`, and a grep for `private`/`protected` `cmd()`
declarations found 7 hits -- but every one of them also defines
`query_patterns()` and is dispatched via a *bound closure*
(`(: cmd($1) :)`), not `call_other` by name; closures execute via
`call_function_pointer()`/`setup_fake_frame()` (confirmed against
`~/src/fluffos/src/vm/internal/base/function.cc`), which bypasses the
`apply()` permission gate entirely regardless of declared visibility.
Every command file that *doesn't* define `query_patterns()` (i.e.
genuinely relies on the string-based `cmd(string)` call_other path)
was also checked and all declare `cmd()` `public` already -- §8.3a's
specific command-dispatch shape is confirmed clean here.

### Bug 2 (fixed, much wider-reaching): `notify_fail()`'s own driver-flavor detection picks the wrong implementation on this build, silently discarding ~570 custom fail messages mudlib-wide

Found while checking why the newbie-help-documented bare `rows`/`cols`/
`term` commands (`global/player/events.lpc`) all printed the driver's
generic `"What?"` instead of their own documented "currently set to
N" messages. `secure/simul_efun/modified_efuns.lpc`'s own `notify_fail(
mixed stuff)` simul_efun -- the one every ordinary call site in the
mudlib actually reaches via a bare `notify_fail(...)` call -- ends
with:

```
#if efun_defined(notify_fail)
    return efun::notify_fail( stuff );
#else
    return _notify_fail( stuff );
#endif
```

The intent is clearly "if this driver build has the real native
`notify_fail()` efun, defer to it; otherwise use this mudlib's own
`_notify_fail()`/`query_notify_fail()` fail-message slot." That
assumption only holds if a real native `notify_fail()`-consuming
command path (i.e. genuine `add_action()`-based dispatch, where the
driver's own fallback machinery actually reads
`default_err_message`) is what's active. But per this NOTES.md's own
§5 finding, **almost nothing in this mudlib uses real `add_action()`**
-- everything else runs through the custom `new_parser`/`cmdAll`
dispatch chain, which never once reads the native efun's
`default_err_message` and instead reads back `_notify_fail()`'s own
`_nf` slot via `query_notify_fail()`. Since `efun_defined(notify_fail)`
is a *build-flavor* check (true on this driver, unconditionally,
regardless of which dispatcher is actually processing the current
command), the `#if` branch was picked every single time on this
build, silently writing into the native efun's inert
`default_err_message` field instead of the mudlib's own slot that its
own parser actually displays -- so the parser fell through to its own
hardcoded generic `"What?"` on every soft-fail call site instead of
showing the real message.

**Scale**: 570 call sites reference a bare `notify_fail(` outside
`/d/`, `/w/`, and the 3 definition sites themselves -- effectively
every "fail with a helpful explanation" call site mudlib-wide.
Reproduced live before fixing: `rows`/`cols` (bare, no argument) and
`term` (**both** the bare form and `term network`, the argument form)
all printed the driver's generic `"What?"`; `busy on`/`off` (which
uses a similar `{on|off}` pattern but never calls `notify_fail()` in
its own body) worked fine, isolating the cause to `notify_fail()`
itself rather than the pattern-matching grammar.

**Fix**: made the branch selection a *runtime* check instead of a
*build-flavor* one, following the exact pattern this same file's own
`query_verb()` (a few lines below) already uses for the identical
problem (native-efun-exists vs. is-a-native-dispatch-actually-active):

```
#if efun_defined(notify_fail)
    if( efun::query_verb() )
        return efun::notify_fail( stuff );
#endif
    return _notify_fail( stuff );
```

`efun::query_verb()` only returns non-empty from genuinely
`add_action()`-dispatched code (confirmed against
`~/src/fluffos/src/packages/core/add_action.cc`'s `f_query_verb()`);
outside that context it's always empty, so this now correctly falls
through to `_notify_fail()` for the overwhelming majority of calls
while still preserving the original native-efun behavior for the
handful of genuine `add_action()` call sites that exist
(`net/obj/webster.lpc`'s 4 dictionary verbs -- not live-reachable to
verify directly, since that object is never cloned/placed anywhere in
the reachable game graph, but the logic is symmetric with the already-
verified `query_verb()` convention in the same file).

Needed a companion fix: `_notify_fail`'s forward declaration
(`secure/simul_efun/modified_efuns.lpc`, near the top of the file) was
itself only compiled in `#if !efun_defined(add_action)` (i.e. never on
this driver), so the new always-reachable call to it hard-failed the
whole simul_efun object's compile (`Undefined function _notify_fail` /
`No program in object '/secure/simul_efun/modified_efuns'!` -- a
driver-fatal boot failure, master/simul_efun object required). Moved
just that one prototype (`varargs int _notify_fail(string);`) out from
under the guard so it's always visible, regardless of which flavor's
real implementation (`add_action.lpc` vs. `fluffos_compat.lpc`) ends
up inherited.

**Verified live after both fixes, clean reboot**: `rows`/`cols` bare
now correctly print "Rows/Columns currently set to N... rows/cols
<number> to set."; `term` bare now prints the full syntax/help text
listing every terminal type; `term network` now correctly prints
"Terminal type unchanged as network."

**Bug 2b (fixed, found while verifying bug 2): `query_verb()`'s own
"is this a real native-dispatch context" check used a type-unsafe
string comparison.** `secure/simul_efun/modified_efuns.lpc`'s
`query_verb()` -- the same function bug 2's fix now depends on --
computed `verb = efun::query_verb()` and treated a non-empty result as
"real add_action context, use it as-is" via `verb != ""`. Per
`add_action.cc`'s `f_query_verb()` (`if (!last_verb) push_number(0);`),
the native efun returns the **integer** `0`, not `""`, when no native
verb is active. Since `0 != ""` is true for two different types on
this driver, the `verb != ""` check was satisfied by the *wrong*
condition and the function returned the raw integer `0` instead of
falling through to the mudlib's own `TP->query_current_verb()`.
Visible, reproducible symptom: `term`'s own syntax-error message
(`global/player/events.lpc:371`, `"Syntax: "+query_verb()+
" <term_type>\n"`) rendered as **`"Syntax: 0 <term_type>"`** instead of
`"Syntax: term <term_type>"` -- caught by re-reading the exact fixed
output of bug 2's own verification step rather than assuming success
from the mere absence of `"What?"`. Fix: normalize `verb` to `""`
whenever it isn't actually a string before the comparison
(`if( !stringp(verb) ) verb = "";`), preserving the rest of the
function's existing fallback logic unchanged. Verified live: `term`
bare now correctly prints `"Syntax: term <term_type>"`.

### Standing cross-cutting patterns checked (§7.121, §8.3a, §7.112,
§7.122, §7.123, §7.124, §7.126, §7.129, §7.130, §7.131, §7.132, §7.133,
§7.134, §7.135/§7.30)

- **§8.3a** (private/protected dispatch-target demoted): the two real
  findings above (bug 1, and §8.3a's own literal command-dispatch
  shape checked separately and confirmed clean, see bug 1's writeup).
- **§7.121** (float math in a declared-`int` function, no
  `to_int()`): checked `obj/money.lpc` (the currency/economy class --
  `fixup_money_weight()` already correctly calls `to_int()`,
  `query_money()` has no float math at all), `handlers/taskmaster.lpc`
  (`point_tasker()`'s `float b` is a pure intermediate used only inside
  an already-`to_int()`-wrapped `random(1000) < ...` comparison, never
  returned or assigned to an `int`-declared variable in a way that
  matters; `attempt_task()`'s `upper = calc_upper(upper, bonus)`
  assigns a genuine `float` into an `int`-declared local, but the only
  consumer is a `random(200) < (upper * ...) / margin` comparison,
  where float vs. int division doesn't change which branch is taken in
  a way that constitutes a bug -- correctly more precise, not broken).
  No `to_int()`-shaped economy/skill corruption found.
- **§7.112** (NPC `init()` unconditional `call_out` chain, no
  re-entry guard): not applicable -- no reachable NPCs at all (see the
  content-reachability note above); the framework-level heart_beat/
  `call_out` chains checked (`global/player.lpc`'s own `heart_beat()`)
  are player-side, not NPC `init()`-triggered, and already correctly
  guarded (see §7.130 below).
- **§7.122** (class-marker item duplication on reconnect): the
  specific mechanism this bug class names
  (`compute_autoload_array()`/`destroy_autoload_obj()`/
  `load_autoload_obj()`) doesn't exist anywhere in this codebase.
  Skylib's own equivalent (`global/player.lpc`'s `auto_load` field +
  `do_load_auto()`) is a different, **structurally immune** shape: a
  player's actual inventory is *never* preserved as live objects across
  a disconnect at all (confirmed live -- "Please note that your
  inventory is still being generated" / "Inventory regeneration
  complete" on every single login, new or returning) -- the save file
  stores only a *recipe* (file paths + clone properties), and
  `do_load_auto()` deletes that recipe (`set_auto_load_string(0)`)
  immediately after using it each time, so there's no "already present,
  add another" check to omit in the first place. Verified live with a
  real quit-then-reconnect-after-65-real-seconds cycle (crossing this
  lib's own `MIN_TIME_TO_SAVE` = 60s first-save threshold, see below):
  inventory came back as exactly 1 dagger + 3 torches + correct money,
  no duplicates, no loss (an initial apparent "lost a torch and all my
  money" reading turned out to be a test-script race against the
  regeneration's own 2-stage delay, not a real bug -- re-checked after
  waiting for the "regeneration complete" message and the count was
  correct; logged here as a caution for anyone re-testing this exact
  path with a script instead of a human's natural pause).
- **§7.123** (bare file-scope `IDENT = (mapping-or-array);`): zero
  hits mudlib-wide via `grep -E '^[A-Za-z_]\w* *= *(\(\[|\(\{)'`
  (excluding `/d/`, `/w/`, and `.old`/`.bak` files).
- **§7.124** (fraction-vs-percentage threshold): none found; the
  `wimpy` field (the one safety-threshold field this codebase actually
  has) is consistently an integer percentage everywhere it's read or
  written (`cmds/player`'s `wimpy` command, `score`'s display, the
  default `25` set at creation).
- **§7.126** (stale `.c` save-data reference after the `.lpc`
  rename): covered exhaustively already by this file's own §3 (28 +
  11 occurrences found and fixed at onboarding time); no further live
  instances surfaced during this pass.
- **§7.129** (`tell_room()` forwarding omitted arg as literal `0` to
  `message()`): doesn't apply here -- this codebase's `tell_room()`/
  `event()` (`secure/simul_efun/modified_efuns.lpc`) never calls the
  native `message()` efun at all; it's a fully custom
  `call_other(ob, "event_"+func, ...)`-based dispatcher to per-object
  `event_say`/`event_whisper`/etc. handlers.
- **§7.130** (unconditional `query_idle()` after already-detected
  non-interactivity): checked `global/player.lpc`'s `heart_beat()`
  directly -- already correctly guarded:
  `idle_time = ( !interactive(TO) ? time()-last_command :
  query_idle(TO) )`, i.e. `query_idle()` is only ever called when
  `interactive(TO)` is true. Clean.
- **§7.131** (`find_living()`/`find_player()` needing explicit
  `set_living_name()` this driver requires): confirmed working
  correctly end-to-end via the bug-1 investigation above (a live
  same-name-registration-collision test while the first session was
  still connected) and via the linkdead-reconnect-by-name test (§8
  above / this session's own `testquill`/`vexbadger`/`quorrelnix`
  scratch characters, all cleaned up before commit).
- **§7.132** (`map()`-over-mapping bound to the wrong arg): zero hits
  for the `map(<mapping>, ...$1...)` shape mudlib-wide.
- **§7.133** (disconnect-notification apply never defined): checked
  directly -- `global/player.lpc:1159`'s `net_dead()` **is** defined
  and does real work (statue transformation, `LOGIN_H->player_net_dead()`,
  `save_me()`); `cmds/creator/crea_tors.lpc`'s own top-of-file comment
  ("seem to like it when you call query_idle() on net dead people")
  shows this exact interaction was already known/handled by the
  original author. Clean.
- **§7.134** (array/mapping field defaulting to `0` instead of
  `({})`/`([])`): spot-checked `std/room/basic_room.lpc`'s
  `hidden_objects`/`exits`/`aliases` family (all eagerly initialized
  to `({ })` in `setup()`/`create()`, not lazily) -- clean. **Not**
  swept exhaustively corpus-wide (539 `mapping`/`mixed`-returning
  accessors mudlib-wide is a much larger undertaking than this pass's
  remaining time budget allowed); no crash of this shape surfaced
  during any live testing done this session, including the framework
  areas (score/skills/inventory/finger) exercised repeatedly.
- **§7.135/§7.30** (one sibling accessor missing a lazy-init guard):
  same scope caveat as §7.134 above -- not exhaustively swept, but the
  specific families actually exercised live (money, room
  hidden_objects/exits/aliases, skills) all use eager
  `create()`/`setup()`-time initialization rather than lazy
  first-access initialization, so this specific shape doesn't apply to
  any of them.

### Login, chfn, quit, and persistence -- all verified clean

Registered several throwaway characters across this session
(`corvishade`, `wrenthorn`, `shadowmere`, `quorrelnix`, `vexbadger`,
`testquill`, `fennglow` -- all deleted from `save/players/` before
committing; only the pre-existing seeded `fluffos` admin account and
the onboarding-time `shaydz`/`default` save files remain). Confirmed:
full registration flow (name -> confirm -> password x2 -> gender) end
to end; `look`/`score`/`i` differentiated and correct at every state
change; `chfn`'s full 6-prompt chain (real name -> location -> icq ->
birthday -> email -> homepage) completes cleanly with correct
confirmation text at each step; `quit` produces the correct "Saving
your inventory." message (once past this lib's own `MIN_TIME_TO_SAVE`
= 60-second-old threshold -- characters quit before that are correctly
*not* saved at all, by design, confirmed via `query_old_enough_to_save()`
in `global/player.lpc`, not a bug) and a clean disconnect; `debug.log`
never changed at all (byte-for-byte, timestamp-for-timestamp) across
this entire session's boots, logins, chfn flows, quits, and
reconnects -- zero runtime errors logged by anything tested. A real
wall-clock reconnect (genuine multi-minute gap, not a same-session
retry) correctly restored name, stats, gender, and inventory with no
duplication and no loss (see §7.122 above).

One pre-existing cosmetic quirk from the original onboarding NOTES
above (a single stray `"What?"` immediately after login/registration,
before the `chfn`-reminder line) was observed to recur identically on
every login throughout this session, admin and player alike -- still
confirmed harmless/non-blocking, not chased further, consistent with
the original note.

### Sanity checks before commit

`grep -h '"port"' libs/*/meta.json | grep -oE '[0-9]{5}' | sort -n |
uniq -c | awk '$1>1'` -- no output (no port collisions). All
throwaway test-character saves and driver-boot save-state churn
(`save/board_backups/`, `save/map/`, `save/handlers/crime/`,
`save/newsrc/`, `d/liaison/{error-log,runtime,catch}`, `save/
{autodoc,parcels,weather}` daemon state, `secure/save/handlers/
intermud.o`) reverted/removed before staging -- only the two `.lpc`
fixes and the admin account's own legitimately-updated save file
(`save/players/f/fluffos.o` -- new login timestamp, skill-practice
increments from this session's own admin testing) are committed.
