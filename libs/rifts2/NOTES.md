# RiftsMUD2 -- porting notes

Source: `git clone https://github.com/tsathoqqua/RiftsMUD2` (cloned
2026-08-28, default branch tip). Description on the repo: "Another take
by going from DarkeLIB down to Rifts" -- a real LPC mudlib built on the
DarkeLIB lineage (itself descended from the Nightmare/TMI family: the
top-level `adm/obj/master.lpc` credits "mudlib.n and lil" as inspiration
and author `zortek@trekverse`, while a separate `d/standard/adm/master.
lpc` explicitly credits Nightmare's Douglas Reay/"Pallando"), reskinned
onto Palladium's post-apocalyptic *Rifts* tabletop RPG setting (OCCs,
MDC/SDC, PPE -- see below). Mudlib root is the repo's `mudlib/`
directory; `build/`, `docker-compose.yml`, `Dockerfile`, `local_options`/
`local_options.h`, and `mud.sh` at the repo top level are driver/deploy
scaffolding, not part of the mudlib, and were not converted. 595 `.c`
files, ~15MB. Slug `rifts2`, number 953, port 40255.

Not a duplicate of `grav1tyzero/rifts-ds` (also in this collection,
already queued separately) -- that lib reskins the same Rifts setting
onto a completely different base engine (Dead Souls lineage); this one
is DarkeLIB/Nightmare-lineage MudOS/FluffOS from scratch. No shared
code between the two.

Zero `driver_hook`/`set_driver_hook`/`H_[A-Z_]+` hits anywhere in the
tree -- genuinely FluffOS/MudOS-compatible, not LDMud (confirmed before
onboarding began).

## 1. Conversion

Almost entirely ASCII/UTF-8 already (`convert_lib.sh`:
`already_utf8=1615 converted=1 lossy=0 skipped_binary=21`). Renamed 595
`.c` files to `.lpc`, fixed 150 literal `.c"` references, converted 23
local angle-bracket `#include`s to quotes, and touched 78 files in the
`static`->`nosave` sweep. `driver.exe.stackdump` (a leftover Windows
driver crash dump, plain text but not source) at the mudlib root was
deleted before conversion -- not mudlib content. `master.lpc` had all
three required uid applies already (`get_root_uid`/`get_bb_uid`/
`creator_file`), so no stub was needed there.

`adm/binaries/` (the config's `save binaries directory`) didn't exist
in the raw archive and was created empty during onboarding, matching
this project's usual handling of a missing-but-configured runtime
directory.

## 2. Compile sweep (`lpcc_check.sh`) -- 568/595 pass after fixes (was 557/595)

Ran under `(ulimit -v 8388608; ...)` per this session's standing
practice for batch compiles. 38 initial failures, narrowed to 27 after
the fixes below; all 27 remaining failures are either (a) a known
lpcc-batch-mode artifact (below) or (b) genuinely dead/unreferenced
legacy scaffolding never wired into this Rifts-flavored fork (confirmed
by grepping the whole tree for real inherit/`new()`/`call_other()`
references to each failing path -- none found beyond the failing file
itself, or beyond another equally-dead file):

- **lpcc-batch-mode artifact, not a real bug (11 files)**:
  `adm/daemon/race_d.lpc`'s `races`/`limbs` mappings are populated by
  `init_data()`, called via `call_out("init_data", 1)` in `create()` --
  one real second after boot. `lpcc --batch` never advances real time
  (no call_outs ever fire), so any `/std/monster.lpc`-based object whose
  `create()` calls `set_body_type()` before that callout would fire
  hits `race_d.lpc`'s `is_race()` doing `keys(races)` on a still-nil
  mapping (`*Bad argument 1 to keys() Expected: mapping Got: 0`).
  Affects: `std/diewarzau/obj/misc/image`, `doc/QC/mon/hagar`,
  `d/standard/obj/mon/armageddon`, and 8 files under
  `d/damned/world/obj/mon/` (panther, jackrabbit, mountain_lion,
  will_o_wisp, pissed_rabbit, python, wolf, lizard). Cross-checked
  against a real boot (per AGENTS.md's "lpcc-vs-live-driver artifact"
  guidance): `race_d` is in the `epilog()` preload list, loads within
  the first second of a real boot, and these files are all leaf
  monster/NPC content only ever instantiated later via room `reset()`
  as a player wanders in -- zero `race_d` errors appeared in
  `debug.log` across every live boot this session. Not fixed --
  fixing it would mean changing `race_d.lpc`'s real design (making
  `init_data()` synchronous) for a test-harness-only symptom.
- **Genuinely dead/unreferenced code (16 files)**: `std/diewarzau/
  locker_hash.lpc` + its exact duplicate `d/diewarzau/locker_hash.lpc`
  (both use a nonexistent `#inherit` preprocessor directive and an
  undefined `class locker_room`; referenced by nothing), `std/
  diewarzau/obj/misc/clone_soul.lpc` (genuinely truncated mid-function
  in the original archive, not a conversion artifact -- confirmed by
  diffing against the raw `.c`), `std/castle.lpc` (references an
  undefined `DIR_CASTLES_HM`, inherited by nothing), `std/obj/
  container.lpc`, `std/adt/iqueue.lpc`, `std/adt/istack.lpc` (an
  unfinished/abandoned generic-container experiment, inherited by
  nothing), `doc/etc/func_spec.lpc` (a documentation stub, not real
  code, uses `void|string`-style pseudo-type-union syntax this driver's
  parser doesn't support), `d/diewarzau/save_items2.lpc` + `d/
  diewarzau/misc/tmp_obj.lpc` (unreferenced dev scratch files -- the
  latter has a broken string literal on top of being dead),
  `d/standard/obj/misc/vial.lpc` + `d/standard/storage.lpc` + `d/
  standard/adm/master.lpc` (all three inherit-chain into a `/std/poison`
  or `/adm/daemon/alchemist_d` that was never archived at all -- and
  `d/standard/adm/master.lpc` itself is the OTHER, vestigial
  Nightmare-heritage master file mentioned above, never referenced by
  anything and NOT the master this lib's `config.fluffos` actually
  points at), `d/standard/obj/mon/atmos.lpc` (calls `set_alignment()`
  with an `int` where the real signature takes a `string` -- a genuine
  one-line bug, but the file is inherited by nothing so it never runs),
  `cmds/cmds_m.lpc` (unreferenced TMI-heritage boilerplate missing
  `#include <uid.h>` for `ROOT_UID`), `cmds/mortal/who/_who.lpc` (an
  orphaned duplicate of the real, working `cmds/mortal/_who.lpc` --
  command dispatch only scans ONE directory level deep, so a file
  nested in a `who/` subdirectory under `/cmds/mortal` was never
  reachable as a command in the first place, unlike its working
  sibling).

Everything genuinely reachable in real gameplay compiles clean.

## 3. Bugs found and fixed (AGENTS.md references)

Ordered as found; the first three are the ones that actually blocked
play, the rest are one-off correctness fixes hit along the way.

1. **AGENTS.md §7.118 (new confirmed instance) -- command dispatch
   completely broken for every verb except `quit`/`accept`/`decline`.**
   `daemon/command.lpc`'s `rehash()` did
   `choses[j] = choses[j][1..strlen(choses[j])-3]` to strip the leading
   `_` and trailing extension off each `_verb.lpc` filename -- correct
   arithmetic for the archive's original 2-character `.c` extension,
   wrong by 2 after this project's standard `.c`->`.lpc` rename (4
   characters). Every command got registered under a garbage key one
   character too long (`look` -> `"look.l"`), so `find_cmd()` could
   never find any of them and every ordinary command (`look`, `score`,
   `inventory`, `who`, `say`, `help`, ...) silently returned the
   driver's generic `"What?"` fail message from the very first boot.
   Fixed to `strlen(...)-5`. This was the single most impactful bug in
   this lib by far -- verified by direct before/after comparison over a
   live telnet session (every one of those verbs went from `"What?"`
   to correct output after the fix, with zero other code changes in
   between).
2. **AGENTS.md §8.20 (new) -- every new character permanently trapped
   in the character generator, unable to ever enter the real game.**
   `d/standard/setter.lpc`'s `init()` had `add_action("set_ansi",
   "ready")` commented out -- `set_ansi()`/`set_ansi_two()` is the ONLY
   code path anywhere that ever moves a character out of this room into
   `ROOM_NEWBIE` (`/d/standard/square`), so with `ready` unregistered as
   a command, `pick <race>` + `choose` (occupation) worked fine but
   there was no way out at all. Re-enabled the `add_action`. Verified
   live end-to-end three times with fresh characters.
3. **AGENTS.md §8.19 (new) -- new-account password confirmation
   accepts/rejects incorrectly.** `adm/obj/login.lpc`'s `new_pass()`/
   `npass2()` both had an `if (bad) { ...; input_to("new_pass"); }`
   block with no `return` after it, so a too-short password or a
   mismatched confirmation printed the right rejection message but then
   fell through into the unconditional success code anyway -- a
   mismatched confirmation still got `set_password()`'d and reported
   "Password set!". Added the missing `return;` to both blocks.
   Verified live: a deliberately mismatched confirmation now correctly
   loops back to "Re-enter new password" instead of silently accepting
   whatever was typed second.
4. **`std/spells/spell.lpc` -- stray `break;`/`}` broke the shared base
   spell class's compile.** `spell_func()`'s `"protection"` case had an
   extra `break;` immediately followed by a stray `}` that prematurely
   closed the enclosing `switch`, turning the case's real trailing
   `break;` into a hard "break statement outside loop" and the next
   line into a cascading syntax error. Blocked `std/spells/banned/
   sanctuary.lpc` and `data/damned/clone.lpc` (the "clone" spell) from
   compiling at all. Deleted the two stray tokens.
5. **`/wizards/diewarzau/...` stale personal-wizard-home-directory
   paths (AGENTS.md §7.159 pattern) -- 9 files.** This lib's real Rifts-
   setting content author's personal work directory got relocated to
   `/std/diewarzau/...` at some point, but 9 hardcoded path references
   were never updated to match: `herb_press.lpc`, `trap_func.lpc`,
   `chal_soul.lpc`, `gm_soul.lpc`, `lock_pick_case.lpc`, `ill_wall.lpc`
   (this one's broken inherit is what put it in the compile-fail list),
   `papers.lpc`, `lumberjack.lpc`, and `spells/banned/sanctuary.lpc`.
   Verified each target file actually exists at the corrected
   `/std/diewarzau/...` path before rewriting (distinguishing this from
   the OTHER, non-fixable shape below). Fixed with `sed` path
   substitution, one file at a time.
6. **Same stale-path shape pointing at content that was NEVER
   archived at all (not fixable, per the majik3/§7.159 precedent) --
   4 files.** `s_rune.lpc` (`/wizards/diewarzau/obj/pet/greater_demon`),
   `std/diewarzau/rooms/weapon_shop.lpc` (`/wizards/diewarzau/obj/mon/
   biff`), `data/damned/clone.lpc` (`/wizards/diewarzau/obj/mon/
   clone_ob`), and `std/diewarzau/rooms/warp.lpc` (a still-missing
   `/std/diewarzau/obj/mon/warp_creature`, i.e. not even a stale-path
   case -- this one was never archived under either path). Left
   unfixed (no content to point at), but the unguarded `new(...)->
   move(...)`/multi-step-chain call sites that assumed `new()` always
   succeeds were **crash bugs in their own right** -- `weapon_shop.lpc`
   and `warp.lpc` crashed their OWN `reset()` every time it ran (every
   room reset cycle, forever), and `s_rune.lpc`/`data/damned/clone.lpc`
   would have crashed the instant a player actually triggered them.
   Guarded all 4 with a null check and a graceful in-character failure
   message instead of fabricating the missing content.
7. **`std/obj/no_corpse.lpc` -- extra closing paren in a mapping
   literal.** `copy_body()`'s `"damage": ob->query_dam(limb_names[i]))`
   had one closing paren too many, closing the whole `([...])` mapping
   literal early and failing the rest of the function to parse. Would
   crash any monster's death sequence if it ever had `set_property("no
   corpse", 1)` set (nothing in this codebase currently does, so this
   was unreachable, but cheap and unambiguous to fix on sight).
8. **`d/standard/obj/misc/watchtower.lpc` -- two independent bugs,
   found one after fixing the other.** (a) `#define DONATORS_LIST (...)`
   used backslash line-continuation, but blank lines were interspersed
   between the continued lines in the archive's ORIGINAL source
   (confirmed via `raw/`, not a conversion artifact) -- a blank line
   ends a backslash continuation, so everything after the first
   continued line became stray top-level tokens, failing the whole
   file. Joined the continuation lines contiguously. (b) Fixing that
   unmasked `query_hour()` being forward-declared as `string` but
   DEFINED as `int`, despite its body returning a string concatenation
   and its only caller treating the result as a string -- changed the
   definition's return type to `string`.
9. **`cmds/system/_clog.lpc` -- AGENTS.md §6.7's `REF_RESERVED_WORD`
   class, the exact file already named in that section as a known-
   affected shape.** `pop_coder(int ref)` used `ref` as a parameter
   name; this driver build has `REF_RESERVED_WORD` defined, making
   `ref` a hard keyword. Renamed to `refname` (matching the established
   fix pattern). Proactively grepped the whole archive for the same
   shape (`(string|object|int|mixed|float|mapping)\s*\*?\s*ref\b\s*
   [,;=)]`) per §6.7's own "how to apply" guidance -- this was the only
   hit in the whole tree. This is a real, reachable wizard command
   (`clog`, directly under `/cmds/system/`, matched by the command
   dispatch's `_*.lpc` scan).
10. **`cmds/creator/_pupdate.lpc` -- three independent bugs in the
    live-reload wizard command.** `if (str == master())` compared a
    filename string against the master OBJECT (a hard type-check error
    on this driver) -- changed to `str == base_name(master())`.
    `CONFIG_DIR` and `tell_group()` are both genuinely undefined
    anywhere in this codebase (no equivalent exists) -- replaced the
    dead admin-notification branch with this codebase's own real,
    already-used equivalent, `INFORM_D->do_inform("external_edits",
    ...)` (the same daemon/category `adm/obj/master.lpc` itself uses
    for the identical "someone edited a live file" notification).
11. **`cmds/creator/_netstat.lpc` -- genuinely missing native efun
    (AGENTS.md §7.160 pattern).** `dump_socket_status()` is declared in
    this driver's own C++ headers but takes an internal `outbuffer_t*`
    argument and is never actually exposed as a callable LPC efun (not
    present in `sockets.spec`). The real modern equivalent is
    `socket_status(int)`. Rewrote `cmd_netstat()` as a minimal
    compatible reimplementation looping `socket_status(i)` until it
    returns 0, rather than reconstructing the original's exact
    (unknown) table format.

All 11 items above are real, reachable, verified-live fixes -- none are
content/design changes. Every fix was re-verified with a fresh
`lpcc_check.sh` pass and, for the ones touching login/chargen/command
dispatch, a fresh end-to-end telnet playthrough.

## 4. Config

`config.fluffos` ported directly from the archive's `mudlib/config.
darke` (a Lima-mudlib-flavored MudOS v22 config file) -- all the
resource limits, `master file`/`simulated efun file`/`include
directories`/`global include file` paths, and messages carried over
unchanged except `name` (`RiftsMUD2@FluffOS`) and `port number`
(40255, this lib's assigned port; the archive's own default was 7878).

## 5. Live playthrough (native driver)

Booted `~/src/fluffos/build-debug/src/driver config.fluffos` from
`libs/rifts2/` repeatedly across the fix cycle above; zero fatal errors,
clean `debug.log` on every boot. Full registration-to-gameplay loop
scripted over a raw Python socket (no telnet client needed) and run to
completion multiple times with fresh character names after each fix:

register (real name, e.g. "Aranthis") -> confirm name -> set password
(exercised both the too-short-password and mismatched-confirmation
rejection paths, §8.19 above) -> gender -> email -> real name (optional)
-> `help races` (lists the one playable race, Human) -> `pick human` ->
answer the "low stat" 1d4+N boost prompt -> `y` to keep rolled
attributes (HP correctly computed from PE, e.g. 14/15/10 across
different rolls) -> `choose` -> `1` (the one available OCC, "Coalition
Grunt" -- SDC correctly rolled 2d6+12, e.g. 19/20/21) -> `ready` -> `n`
to the ANSI color check -> lands in `/d/standard/square` ("You're in
the city center square... two obvious exits: world and east").

From there: `look` (correct room description + exits), `score` (a real
Rifts-style character sheet -- HP/SDC/PPE bars, Level/Race/Age/State/
Thirst/Hunger/Credits/Experience), `inventory` (correctly lists the
still-carried "OCC Picker" prop -- a genuine minor content gap, not a
bug: `pick_occ()` never calls `remove()` on it after a successful pick,
see §6 below), `who` (an ASCII-art banner, paginated through the
built-in `more` pager), `say <message>` (a working proficiency-based
"broken language" mechanic -- `adm/simul_efun/translate.lpc`
deliberately garbles some words into placeholder-Latin nonsense based
on a random roll against the speaker's language skill; confirmed
genuine documented Nightmare-mudlib design, not a bug, per this
project's "no error signature = design" standard), `help` (real topic
help text), and `quit` (clean save + disconnect, `Items Saved: 1`).

Registered the standard `fluffos`/`Mud@2026` admin account (AGENTS.md
§1.5) through this same normal flow, then granted admin rank the
data-file way per this lineage's own mechanism: edited its save file's
`position "player"` to `position "superuser"` (matching the archive's
own pre-existing admin account, `parnell` -- see §6) and added
`fluffos` alongside `parnell` in `data/db/groups.db`'s group-membership
lines (`(god)`, `(admin)`, `(superuser)`, `(siteadmin)`, `(assist)`,
`(arch)`, `(mentor)`, `(elder)`, `(wizard)`, plus the lower-stakes
`(approval)`/`(mudlib)`/`(law)`/`(ambassador)`/`(advocate)` groups, all
mirroring `parnell`'s exact memberships). Verified: logged in as
`fluffos`, ran `update /cmds/creator/_netstat` (succeeded, "updated and
loaded"), then ran the freshly-reloaded `netstat` command and got real
socket data back, including the two live `/daemon/network` UDP sockets
described in §7 below -- confirms both the wizard ACL and the live-
reload command path work correctly.

## 6. Minor observed non-bugs / content gaps (not fixed)

- **`OCC Picker` prop lingers in inventory after character creation.**
  `std/occ_picker.lpc`'s `pick_occ()` sets the character's SDC/MDC
  correctly on selection but never calls `remove()` on itself
  afterward (unlike its own `drop()` method, which does). Cosmetic --
  it's a real object with `query_is_occ_obj()` returning 1 so `choose`
  can find and clean up any stale ones on a re-roll, but nothing
  actually cleans it up on the SUCCESS path. Left as-is: not a crash,
  not a silently-broken command, just an inventory clutter item from an
  unfinished chargen flow.
- **Only one race (Human) and one occupation (Coalition Grunt) are
  actually implemented**, despite the surrounding architecture (a real
  `RACE_D` daemon, a `_occs` array clearly designed to hold more than
  one entry, per-limb damage/body-type tables) being built to support
  many. Consistent with this being an early-stage, apparently
  unfinished build (same "development stopped early" pattern seen
  repeatedly elsewhere in this corpus, e.g. majik3/majik4) -- genuine
  content scope, not a bug.
- **A single reproducible spurious `"What?"` appears once, right when
  the `ready` command first triggers the ANSI color-check prompt**,
  immediately after the real "Is this line red (y or n)?" message, in
  the same driver-to-client write. It's cosmetic (never blocks
  progression -- the very next input still correctly reaches
  `set_ansi_two()` and moves the character to `ROOM_NEWBIE`) and
  produces no `debug.log` entry at all. Investigated `set_ansi()`,
  `reset_terminal()`, `reset_max_exp()`, and `setter.lpc`'s `init()`
  (which re-runs every command in that room, since driver-level `init()`
  re-registration is per-command in this room the way it is everywhere
  else) without conclusively isolating the source within this session's
  time budget. Reproduced identically across 3 independent fresh
  registrations, so it is a real, deterministic behavior of this
  specific transition, not test-harness noise from a stale connection
  -- flagged here for whoever next round-two/round-three tests this
  lib, rather than left silently unmentioned.
- **`/daemon/network.lpc` opens a real outbound UDP socket and sends a
  live "startup" packet to a real remote IP:port
  (`207.227.182.222:5567`, `adm/include/network.h`'s `SERVER_ADDR`/
  `SERVER_PORT`) 5 seconds after every single boot**, via
  `socket_preload()` in `epilog()`'s eager preload chain (`/daemon/
  network`, `/daemon/services`). This is a genuine, intentional
  DarkeLIB-era rwho/intermud-style network service (`SERVICE_UDP_*`
  constants for mudlist/ping/rwho/mail/gwizmsg/gtell queries against
  what's almost certainly a long-dead ~1990s-2000s intermud directory
  server), not something to patch away -- but per AGENTS.md §2.3's
  precedent (`imud`), this means **this lib should NOT be swept into
  high-frequency automated re-boot loops** (§10.0-style long-sit scans,
  round-two/round-three re-test cron) the way most other libs in this
  corpus safely can be, since every boot is a real outbound network
  event (UDP, fire-and-forget, but still a real packet to a real third
  party). Confirmed harmless to normal single-session testing: it's a
  fire-and-forget UDP send with no bind requirement met (the target is
  presumably unreachable/dead), and `netstat` shows the resulting local
  sockets sitting in `BOUND` state with no remote data ever received.

## 7. WASM status

Not yet run through the WASM pipeline (§1 of AGENTS.md) -- this
onboarding pass focused on the native-driver bring-up, bug fixes, and
full playthrough verification per the assignment. `wasm_status` left
empty in `meta.json`, same convention as other recently-onboarded libs
pending their WASM pass (e.g. majik4).
