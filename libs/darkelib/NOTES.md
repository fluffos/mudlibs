# DarkeLIB -- onboarding notes

Source: `gh repo clone thraeq/DarkeLIB` (cloned 2026-08-30, default
branch tip, commit `d6226ca`). Description: "DarkeLIB circa 1999, used
for daybreak ridge." A community-maintained fork of the original
`jpeckham/DarkeLIB`, 58 commits ahead -- a real historical English-
language LPC mudlib, distinct from and more developed than the base
repo. Mudlib root is the repo's `mudlib/` directory; `Dockerfile`,
`docker-compose.yml`, `local_options.fluffos`, `local_options.v22.2b14`,
`mud.sh`, and `README.md` at the repo top level are deploy/build
scaffolding, not part of the mudlib, and were not converted. 9,815
files, ~63MB, 6957 `.lpc` files after conversion.

**Lineage**: `rifts2` (already onboarded, #953) is itself derived from
this exact codebase ("Another take by going from DarkeLIB down to
Rifts" per its own repo description) -- DarkeLIB is the more original/
base engine, not a duplicate. Both share `adm/obj/master.lpc`'s
`socket_preload()`/`epilog()` structure nearly verbatim (including the
"Parnell 2018" FluffOS-porting comments), the same `adm/db/groups.db`
Nightmare-mudlib group-security layout, and the same live outbound-UDP
`/daemon/network.lpc` intermud service (see below). Several bugs found
here were already catalogued from `rifts2`'s own onboarding pass
(§7.118's dispatch-table bug, §8.19's password-confirmation bug) and
confirmed as independent instances rather than re-discoveries, since
this lineage's shared code carries the same defects into every
downstream fork.

Zero `driver_hook`/`set_driver_hook`/`H_[A-Z_]+` hits anywhere in the
tree -- genuinely FluffOS/MudOS-compatible, not LDMud (confirmed before
onboarding began, per the assignment).

## 1. Conversion

`convert_lib.sh` on `mudlib/` -> `work/`: renamed all `.c` files to
`.lpc`, fixed literal `.c"` references, converted 29 local angle-
bracket `#include`s to quotes, and swept `static`->`nosave` (6 files
touched at the mechanical-sweep level; individual files with `status`-
as-`int` and other driver-compat issues needed separate hand fixes,
see §3 below). Since this is a from-scratch English archive there was
no GBK/GB18030 encoding work to do -- verified via a whole-tree Python
UTF-8-decode scan: the only non-UTF-8 files anywhere are 123 genuine
binaries (`www/`'s embedded website assets -- JPEGs/GIFs, and an
entire bundled, unrelated `wwwcount2.3` C hit-counter program with its
own compiled `.o` files, a `mkstrip` ELF binary, and even leftover
`ftpd.core`/`MudOS_swapfile.*` crash-dump/swapfile artifacts from the
original 1999-2018 server). None of that is mudlib content; left as-is
(matches the corpus convention of not touching real binaries, and the
crash dumps/swapfiles are small, ~2.5MB total, harmless historical
artifacts).

`www/wwwcount2.3/` (a bundled, unrelated C web-hit-counter program,
NOT LPC) got swept into the `.c`->`.lpc` rename along with everything
else and will never compile as LPC (`#include <stdio.h>` etc.) -- this
is expected and matches AGENTS.md's precedent for bundled non-mudlib
content accidentally caught by a blanket rename (`imud`'s dead
Intermud-3 modules). `daemon/www/rolecall.lpc`, by contrast, IS real
mudlib content (a "generate an HTML rolecall of online players" daemon)
despite living under a `www`-named path -- don't confuse the two.

A straggler-file check (`file(1)`'s text/binary heuristic false-
positive on some GBK-era-CRLF-shaped ASCII files) flagged ~30 files as
"data"; all were spot-checked and are genuine plain ASCII/UTF-8 LPC
source, just tripping the same known `file(1)` unreliability
documented in AGENTS.md §4.1 for an unrelated reason (odd control
characters, e.g. a stray `\x05` in one file's comment header).

`log directory : /log` resolves against the driver's launch CWD (§5.2)
-- created `libs/darkelib/log/` (sibling of `work/`, matching the
project convention) since the archive didn't ship one at the
project's expected location. `adm/binaries` (the config's `save
binaries directory`) also didn't exist in the raw archive and was
created empty.

## 2. Compile sweep (`lpcc_check.sh`)

Ran under `(ulimit -v 8388608; ...)` given the file count (~6957 .lpc
files, comparable to the largest libs in this corpus). Iterated
several times as fixes landed:

| pass | pass/fail | note |
|---|---|---|
| 1 (pre-fix) | 5594 / 1363 | baseline |
| 2 (after §7.165 message() fix + monk.h/misery-def.h path fixes) | 6464 / 493 | +870 files from ONE fix |
| 3 (after glitch/swamp zone + mentorp.lpc + dealer.lpc fixes) | 6527 / 430 | |
| 4 (after status-type + doctors_note + world_server fixes) | 6557 / 400 | |
| final (after LPC formatter's idempotency check surfaced 2 more pre-existing unterminated strings) | 6562 / 395 | |

94%+ pass rate. Remaining failures, triaged by category (per §10.4 --
cross-checked against a live boot before accepting any as real):

- **A whole `d/excelsior/tinker2/` content subtree (~15 files) is
  systematically corrupted**: every literal `w` character anywhere in
  these files -- keywords (`while`->`dhile`), identifiers
  (`shadow`->`shadod`, `new`->`ned`, `who`->`dho`, `write`->`drite`,
  `lower_case`->`loder_case`), AND user-facing string text
  (`weapons`->`deapons`, `wooden`->`dooden`, `sword`->`sdord`,
  `with`->`dith`) -- got replaced with `d`. Confirmed via direct raw-
  archive byte comparison (`grep -c "w" <file>` returns exactly 0 on
  every affected file) -- this predates conversion entirely and is
  baked into the archive's own git history. This would never have
  compiled on ANY driver, ever; it's a completely dead, unreferenced
  "tinker2" (second attempt at a tinker guild?) content area -- zero
  inbound references from anywhere else in the tree, confirmed via
  grep. Left undocumented-but-broken rather than guessing at repairs
  across dozens of corrupted identifiers/strings; the working
  `d/damned/guilds/tinker/` (no "2") is the real, live tinker guild.
- **`std/obj/container.lpc`** -- the exact same dead file `rifts2`
  already found and documented from this same DarkeLIB ancestry: an
  unfinished generic-container experiment with no `inherit` statement
  at all, calling `::save()`/`::restore()` on nothing, referenced by
  nothing anywhere in the tree. Left unfixed (matches precedent).
- **`std/{diewarzau/}locker_hash.lpc`** (2 copies) -- uses a
  nonexistent `#inherit` directive and an undefined `class
  locker_room`; referenced by nothing. Same shape `rifts2` already
  catalogued from this lineage.
- **`/wizards/misery/sefun.lpc`** -- genuinely never archived (no
  equivalent exists anywhere in the tree, unlike the `def.h` case
  below where the same personal-path convention pointed at content
  that DOES exist elsewhere). Blocks `d/mines/objects/etc/shead.lpc`
  and a `booths_room.lpc` from compiling; left unfixed, not fabricated.
- **`d/excelsior/mon/dealer.lpc`'s `who_wins()` function is genuinely
  truncated mid-implementation in the original 1999 archive** (a
  video-poker-style minigame's hand-ranking logic) -- confirmed via
  direct raw-archive line-count/tail comparison: the raw `.c` file
  ends mid-`if`-block, never closing its braces, at EXACTLY the same
  line as the converted copy. This is the same class of pre-existing
  truncation `rifts2` found in `clone_soul.lpc`. Three OTHER real bugs
  in the same file (`void`-declared functions doing `return 1`, a
  `score`/`scores` variable-name typo, `scanff`/`sscanf`) were fixed
  anyway since they're cheap, unambiguous, and don't depend on the
  truncated function -- but the file as a whole still can't compile
  until/unless the truncated function is either completed (would be
  inventing content) or stubbed out.
- **Non-LPC content** (`www/wwwcount2.3/`, ~170 of the remaining
  failures via `Cannot #include stdio.h/time.h/math.h/sys/types.h/
  sys/stat.h`) -- a real bundled C program, not LPC, not a bug.
- **A handful of genuinely-dead backup/duplicate files**
  (`std/user.c2.lpc`, `std/user.realold.lpc`, `std/user.new.lpc`,
  `std/living-retry.lpc`, `std/living_OLD_BAK.lpc`) -- zero inbound
  references anywhere, confirmed via grep; old editor-history copies
  of `std/user.lpc`/`std/living.lpc`, the files actually inherited by
  the live player body.

## 3. Bugs found and fixed

Ordered roughly by impact.

1. **AGENTS.md §7.165 (NEW) -- `adm/simul_efun/overrides.lpc`'s
   `message()` compatibility shim crashed the OVERWHELMING MAJORITY of
   ordinary 3-argument `message()` calls across the entire codebase.**
   The shim's own comment explains its intent correctly ("Allows
   message to be supplied with 0 as a third arg, in which case it does
   nothing"), but its guard only covered the 3rd argument (`to`);
   since the function is `varargs`, any ordinary 3-arg caller (by far
   the most common shape in this codebase -- `message("my_action",
   "You wear the robe.", this_player());`) got the 4th (`exclude`)
   argument defaulted to plain `int 0`, which the shim then forwarded
   POSITIONALLY to `efun::message()` regardless. This driver's real
   `message()` efun declares its 4th parameter `void | object |
   object *` -- omitting the argument is fine, an explicit literal `0`
   is not, so every such call threw `*Bad argument 4 to EFUN message()
   Expected: object, array, Got: int(0)` the instant `to` was truthy
   (i.e., almost always in real play). Found via a room's `reset()`
   spawning an NPC that gets force-equipped starting armor
   (`std/armour.lpc`'s `wear()`), which crashed the moment an
   unrelated stale-include fix let that room compile far enough to
   actually execute. Fixed by only forwarding `exclude` when actually
   supplied. **This single fix turned a 1363-failure `lpcc_check.sh`
   sweep into 493 failures in one pass** -- overwhelmingly the
   dominant bug in this lib, silently aborting nearly every in-game
   action that prints a message with no explicit exclude list.
2. **AGENTS.md §7.118 (confirmed instance) -- `daemon/command.lpc`'s
   `rehash()` had the identical bug already found in `rifts2`**:
   `choses[j] = choses[j][1..strlen(choses[j])-3]` was correct only
   for the archive's original 2-character `.c` extension; after this
   project's `.c`->`.lpc` rename (4 characters), every command
   filename got sliced into a garbage key one character too long
   (`_look.lpc` -> `"look.l"` instead of `"look"`), so `find_cmd()`
   could never match anything registered through this table. Since
   this lib's `quit`/`accept`/`decline` are the only verbs registered
   by direct `add_action()`, every other command (`look`, `score`,
   `who`, `say`, `help`, ...) would have silently returned `"What?"`
   from the very first boot. Fixed identically to `rifts2`: widened
   the slice to `-5`.
3. **`adm/obj/login.lpc` message-class typo silently swallowed the
   new-password rejection/mismatch feedback.** `new_pass()`/`npass2()`
   used message type `"login"` instead of `"logon"` (every OTHER
   message() call in this file uses `"logon"`) -- and the login
   object's own `receive_message(string cl, string msg)` callback
   explicitly gates on `if(cl != "logon") return;`, so a too-short
   password or a mismatched confirmation's rejection text was silently
   dropped: the player saw nothing at all and had to guess why the
   prompt just repeated. Confirmed pre-existing via raw-archive diff.
   Fixed both call sites to `"logon"`.
4. **AGENTS.md §8.19 (confirmed instance) -- the same `new_pass()`/
   `npass2()` functions also had the missing-`return` bug already
   catalogued from `rifts2`**: the `if (strlen(tmp)<5) { ...; input_to
   ("new_pass"); }` and `if (pass != tmp) { ...; input_to("new_pass");
   }` rejection blocks both fell through into the success code below
   them with no `return`, so a too-short password or a mismatched
   confirmation would still get accepted on top of printing the
   rejection message. Added the missing `return;` to both (this is
   now visible thanks to fix #3 above finally letting the rejection
   messages display at all). Verified live: both a too-short password
   and a mismatched confirmation now correctly loop back to
   "Re-enter new password" instead of silently succeeding.
5. **AGENTS.md §6.8 (NEW) -- `status` as a declared type, a real
   MudOS-era `int` alias this driver's lexer doesn't recognize at
   all.** 10 files declared function return types or variables as
   `status` (meaning "an int used as a boolean flag"); this driver has
   no such keyword, hard `syntax error`ing at every declaration site
   and cascading into "Undefined variable"/"Illegal lvalue" everywhere
   the identifier is then used. Affected: `d/khojem/room.lpc`'s custom
   room-mixin `id()` override, `d/excelsior/locker.lpc` +
   `d/daybreak/obj/ntfbox.lpc` + two `guilds/cleric{,_new}/safe.lpc`
   guild-bank items' `query_is_locker()`/`query_is_safe()` checks, two
   `world_server.lpc` virtual-zone generators' `brook`/`query_brook()`
   plus a mid-function `status flag;` local. Fixed by mechanically
   replacing `status` with `int` (behavior-preserving -- that's
   literally what the word meant on the original driver).
6. **AGENTS.md §7.159-class stale personal-wizard-home-directory
   paths -- three independent instances, ~59 files total:**
   - 10 monster/NPC files under `d/arm_dealers/nalon/mon/` referenced
     `#include "/wizards/shanus/defs/monk.h"`, a path that no longer
     exists; the real file lives at `/d/arm_dealers/nalon/monk.h`
     (byte-identical to a second copy at `/adm/include/monk.h`).
     Fixing this ALSO fixed a batch-mode-only false-positive symptom:
     ~27 room files in the same zone (`rooms/room1`-`room20`, etc.)
     that correctly included the real path already showed "Undefined
     variable MONKOBJ" in the batch sweep -- purely because `lpcc
     --batch`'s single-VM run had already poisoned that macro name via
     the earlier broken include on an alphabetically-earlier file;
     confirmed via a standalone single-file `lpcc` re-run of one
     affected room, which passed clean immediately after the real fix,
     with no room-level code change needed at all.
   - `d/zortek/obj/chat.lpc` + `d/zortek/obj/combat.lpc` +
     `d/mines/objects/etc/shead.lpc` + a `booths_room.lpc` referenced
     `#include "/wizards/misery/def.h"`; the real file is
     `/adm/include/def.h` (confirmed identical content -- the macros
     it defines, `FN`/`PO`/`TP`/etc., are exactly what the including
     files actually use). Fixed the def.h path in all 4; the latter
     two still fail to compile due to the separate, genuinely-missing
     `/wizards/misery/sefun.lpc` (§2 above).
   - An entire `d/zortek/secure/glitch/` "swamp"+"caverns" mini-zone
     (48 files: room resets spawning `chief`/`f_troll`/`y_troll`/
     `g_croc`/`g_mosquito`/`shambler`/`ranger`/`hermit` monsters and a
     `staff` item) referenced `/wizards/glitch/swamp/...`, missing the
     `zortek/secure/` segment of the real current path
     (`/wizards/zortek/secure/glitch/swamp/...`) -- and a further
     sub-case, `items/staff` vs the real `obj/staff` (a directory
     rename). Every one of these was an unguarded `new(...)->move(...)`
     chain, so EVERY affected room's `reset()` would have crashed on
     every single reset cycle, forever, the moment the include-path
     fix above let them compile far enough to run. Fixed all 48 with a
     verified-target-exists path rewrite (confirmed every referenced
     monster/item file actually exists at the corrected path before
     rewriting, per the established `rifts2`-precedent distinction
     between a fixable stale path and genuinely-missing content).
7. **`adm/simul_efun/simul_efun.lpc` was missing the `#include` for
   its own, complete, correct `mentorp.lpc` simul_efun** -- used by
   real, reachable commands (`cmds/mentor/_sponsor.lpc`,
   `cmds/adm/_sponsor.lpc`, and 4 `d/excelsior/cmds/` wizard commands).
   Unlike `arenap.lpc`/`arena_ownerp.lpc` right next to it in the same
   file (confirmed, via raw-archive diff, to be DELIBERATELY commented
   out already in the original archive -- left untouched, that reads
   as an intentional feature freeze on a Medievia-style arena system
   hardcoded to two specific staff usernames, not a bug), `mentorp.lpc`
   had no such marker; it was simply never wired in. Added the
   `#include`.
8. **Several one-off pre-existing typos/type-mismatches**, all
   confirmed via raw-archive diff before fixing (none introduced by
   conversion):
   - `std/obj/deed.lpc` -- a mismatched-quote-style `#include` (`"..."`
     opened, `'` closed) and an unescaped nested `"` inside a string
     literal, both breaking the whole file's compile.
   - `d/khojem/guilds/arch-mage/new/meeting.lpc` and
     `d/zortek/secure/glitch/caverns/rooms/c1.lpc` -- missing closing
     quotes / a missing comma+quote in an `add_exit()` call.
   - `d/zortek/secure/glitch/swamp/mons/hermit.lpc` -- a doubled
     trailing quote (`weakling!""`) that opened a second, unterminated
     string swallowing the rest of the function (including the
     `new("/wizards/.../staff")` call three lines later, corrupting
     that path into "Undefined variable" garbage).
   - `d/excelsior/obj/doctors_note.lpc` (a real, reachable item --
     `d/excelsior/mon/orderly.lpc` clones it) -- a stray `#undef \`
     line-continuation directly above `inherit "std/Object";` made the
     preprocessor swallow the inherit statement as part of the (empty,
     nonsensical) `#undef`'s argument list. Removed the stray
     `#undef \`.
   - `d/khojem/room.lpc` -- called `exits::initiate()` but
     `std/room/exits.lpc`'s real function is `initiate_exits()`
     (confirmed via its sibling `senses::initiate()`, which DOES match
     `std/room/senses.lpc`'s real function name). Currently dead code
     (zero inbound references), fixed anyway since it was already
     being touched and the correction is free.
   - `d/warsyn/monastery/armour/field-plate.lpc` and
     `d/damned/guilds/seer/items/captain-plate.lpc` -- both called
     `set_ac(40, ({ "crushing", "cutting", ... }))`, but
     `std/armour.lpc`'s real `set_ac(int, string)` takes a single
     string (or no 2nd arg to apply to every damage type); an array
     falls through to that exact "apply to all" fallback at runtime on
     the archive's original loosely-typed driver, so dropping the
     array to `set_ac(40)` preserves behavior exactly while satisfying
     this driver's static type check.
   - Two `world_server.lpc` virtual-zone generators (`d/zortek/secure/
     canute/` and `d/khojem/stuff/`) had the identical `set_ac()`-class
     mistake in `set_smell(({ "evergreen", "evergreens" }), "...")` --
     `set_smell(string, mixed)` also takes one string, no array
     fallback exists here, so expanded into two separate calls (one
     per item name) to preserve the original "both nouns share this
     smell" intent.
   - `d/excelsior/mon/dealer.lpc` -- three `void`-declared poker-game
     command functions (`pot()`, `call_bet()`, `check()`) that
     actually `return 1`/`return 0` (the standard `add_action` command-
     handled-it convention); a `score`/`scores` variable-name typo
     (the real array was declared `scores`, allocated correctly, but
     indexed as bare `score` at 2 call sites); a `scanff`/`sscanf`
     typo; and an `int *scores` declaration used as a 2D `mixed *`
     array (each `scores[i]` holds its own sub-array) -- widened to
     `mixed *scores`. (The file still can't fully compile due to the
     genuine truncation documented in §2.)
   - `std/spells/shadows/demon_shadow.lpc` -- missing closing quote on
     `query_property("demon))` (found via the required LPC-formatter
     idempotency self-check, §4 below, not the lpcc sweep).
   - `d/khojem/guilds/arch-mage/new/arch-mage_join.lpc` and
     `d/khojem/guilds/paladin/new/p_treas.lpc` -- both had an
     unterminated string spanning a newline in a room-description
     literal (also found via the formatter's idempotency check).

## 4. LPC formatter (§9)

Ran `format-corpus.mjs` on the whole `work/` tree (6957 files; needed a
local Node binary since none was on `PATH` --
`~/.vscode-server/bin/*/node`, v16.13.2, worked fine). 6933 written, 13
unchanged, 11 refusals on the first pass -- 8 were `road6.lpc` (4
unique files, `d/`+`wizards/` copies each) failing the formatter's own
idempotency self-check (a `#define` macro with backslash-continued
multi-line string array content that re-tokenizes unstably on a second
pass) -- left in original archive formatting per the tool's designed
fail-safe (confirmed the file still compiles and plays correctly
either way, this is a formatter limitation, not a mudlib bug). The
other 3 were genuine pre-existing unterminated-string bugs (§3, last
3 items above) -- fixed by hand, then re-ran the formatter, which
picked them up cleanly on the next pass with zero errors. Ran all
three required blind-spot checks after formatting: `::`-split grep
(0 hits), `\ n`-mangled-escape grep (0 hits), and a second full re-run
confirming idempotency (0 written / 6946 unchanged on the second
pass, same 11 pre-existing refusals). Re-booted and replayed the full
registration-to-gameplay flow after formatting (§5) -- identical,
correct behavior to the pre-format playthrough.

## 5. Live playthrough (native driver)

Booted `~/src/fluffos/build-debug/src/driver config.fluffos` from
`libs/darkelib/` repeatedly across the fix cycle; zero fatal errors,
clean `debug.log` on every boot (only routine compile warnings --
`nosave`-on-function soft warnings from the `static`->`nosave` sweep,
unused-local-variable notices -- no runtime errors). Full registration-
to-gameplay loop scripted over raw Python sockets (no telnet client
needed) and run to completion multiple times with different fresh
characters, exercising both branches of every either/or prompt:

register (real English name, e.g. "Thandor"/"Osric"/"Isolde") ->
confirm name (y) -> new password (tested BOTH a too-short password,
correctly rejected with a visible message after fix #3, and a
mismatched confirmation, also correctly rejected after fix #4) ->
gender (male AND female tested) -> email (any `user@host` string) ->
real name (optional, tested blank) -> a real, in-character 1999-era
Darkemud news feed (paginated via the built-in `--More--` pager) ->
`read list` (the full 30-something-race list) -> `pick <race>` (tested
`high-man` and `high-elf`) -> stat assignment (`q` to keep the rolled
defaults, `yes` to confirm) -> the ANSI color check (tested BOTH `y`
and `n` -- both correctly move the character into
`/d/newbieville/rooms/townsquare`) -> lands in Newbieville's town
square with a real room description and 5 exits.

From there: `look` (correct room description + exits), `score` (a
real character sheet -- ASCII Health/Mental/Carry bars, Level/Race/
Age/DevPts/State/Thirst/Hunger/Mind/handedness, a WEALTH panel), 
`inventory` (correctly empty-handed), `who` (a real ASCII-art server
banner, paginated), `help` (real topic help text), and `quit` (clean
save + disconnect, "Reality suspended. See you another time! -*> Items
Saved: 0. Saving...Successful."). Verified a full reconnect-and-relogin
with a previously-registered, previously-quit character (`Osric`) --
correct password prompt, correct restored character state (race,
handedness, stats all persisted), `look`/`score` both correct, and a
second clean `quit`/save.

Registered the standard `fluffos`/`Mud@2026` admin account (AGENTS.md
§1.5) through this same normal flow, then granted admin the data-file
way per this lineage's own mechanism: `position "player"` ->
`position "admin"` in the saved `.o` file (matching the game's own
`if(member_array(query_position(), MORTAL_POSITIONS) == -1)
enable_wizard();` logic in `std/user.lpc`'s `setup()`), plus adding
`fluffos` alongside `parnell` to the `(god)`/`(admin)`/`(superuser)`/
`(siteadmin)`/`(assist)`/`(approval)` lines of `adm/db/groups.db`
(mirroring `rifts2`'s own admin-seeding for this same lineage; the
`(superuser)`/`(assist)` groups specifically are what `archp()`
actually checks for top wizard-command-directory access, which
`parnell`'s own real historical group memberships don't happen to
include in THIS repo's `groups.db` snapshot -- seeded broader than
`parnell`'s literal current memberships to guarantee full admin
access for testing). This is the §1.5 "pre-existing archived player"
bug class: `adm/save/users/p/parnell.o` is a REAL, previously-played
high-level 1999-era character (593591 max exp, a real crypt-hashed
password with no known plaintext) -- not a fresh/empty bootstrap slot
-- so `fluffos` was seeded as a parallel admin account rather than
attempting to claim or reset `parnell`'s own identity. Verified: logged
in as `fluffos`, ran `update /cmds/adm/_chkdev` (succeeded, "updated
and loaded" -- this exercises both read and compile ACL, and
incidentally re-verified fix #8's `adj_skill`/`adj_spell` int-return
fixes live), confirming full wizard write access works correctly.

## 6. Minor observed non-bugs / content notes (not fixed)

- **`/daemon/network.lpc` opens real outbound UDP sockets to a
  hardcoded remote IP:port 5 seconds after every boot**, via
  `socket_preload()` in `epilog()`'s eager preload chain
  (`/daemon/network`, `/daemon/services`) -- the same genuine,
  intentional DarkeLIB-era rwho/intermud-style network service
  `rifts2` already documented from this exact lineage (that lib
  inherited this file essentially unchanged). Per AGENTS.md §2.3's
  `imud` precedent and `rifts2`'s own note: this means **this lib
  should NOT be swept into high-frequency automated re-boot loops**
  (§10.0-style long-sit scans, round-two/round-three re-test cron) the
  way most other libs safely can be, since every boot is a real
  outbound network event (UDP, fire-and-forget) against a real, almost
  certainly long-dead third-party host.
- **`adm/obj/master.lpc`'s `connect()` has a `destruct(this_object())`
  in its error-handling path** (triggered only if `OB_LOGIN` itself
  fails to compile -- a state this onboarding never reproduced, since
  the login object compiles and works correctly throughout). The
  original author's own comment flags this as suspicious ("this is
  odd, are we destructing master.c ???"). Left as-is: it's an
  extremely rare, already-broken-state-only code path, not something
  that affects normal play, and "fixing" a defensive error handler
  that's never actually exercised risks masking a real problem if
  `OB_LOGIN` genuinely does fail to compile in some future edit.
- **`log_error()`'s wizard-facing broadcast** (`adm/obj/master.lpc`,
  commented "Tweaked this function to show the wizard the errors just
  so it wouldn't be so annoying - Geldron 030696") shows every compile
  warning/error to a CONNECTED WIZARD when a file they're near
  triggers a lazy recompile (confirmed live -- reconnecting as
  `fluffos` after any code edit shows a stream of `nosave`-function/
  unused-variable warnings). This is intentional, existing, wizard-
  only dev-convenience behavior (not the corpus's usual §7.10
  all-players-see-warnings bug class), left unchanged.
- **Only `human`-equivalent racial content actually reachable via
  `high-man`** -- the race list shows ~30 real options
  (weretiger/pech/high-elf/wraith/gerudan/etc.) but no literal
  "human"; `high-man` is this game's own naming for the closest
  equivalent. Not a bug, just this game's own established naming
  convention (confirmed via `RACE_D`'s race list, a real, intentional
  design choice consistent with the game's fantasy setting).

## 7. §10.7 deep functional test (round two, 2026-08-31)

Full continuous native-driver session (`~/src/fluffos/build-debug/src/driver
config.fluffos`, port 40258) beyond the registration-flow smoke test
already covered by onboarding (§5 above): a fresh mortal character
(`Deeptestor`, `TestPass123`) plus the seeded `fluffos` admin, driven
via `scripts/tmux_mud.sh` in parallel sessions.

**ACL cross-check (per this session's specific instruction, since
`rifts2` -- this lib's own direct fork -- already turned up AGENTS.md
§8.24's "`groups.db` group never lists the daemon UID it's meant to
include" pattern from the exact same `access.db`+`groups.db`+
`creator_file()` ACL architecture, and §8.24's own "how to apply
generally" section explicitly names DarkeLIB as a suspect lineage):**
carefully traced `adm/obj/master.lpc`'s `check_access()` end to end.
This lib's `(mudlib)` group in `adm/db/groups.db` is indeed just
`noone` (no `Mudlibrary` entry) -- superficially the identical shape.
But unlike `rifts2`'s damage daemon (which only had the group-
membership path available), `check_access()` here has a SECOND,
earlier-checked path: `access[file][euid]` is tested directly (as a
literal string key) before ever falling through to the
`groups[grps[j]]` membership loop. Every real persistent daemon that
needs `/daemon/save` write access (`castle_d`, `clan_d`,
`council_vote`, `letter`, `events_d`, `email_d`, `reinc_d`, `pk_d`,
`multi_d`, `network`, `remotepost`, `player_d`, `mine_d`, `voting`)
deliberately `seteuid()`s itself to a purpose-specific UID
(`UID_DAEMONSAVE` = `"DaemonSave"`, `UID_POSTALSAVE`, `UID_VOTESAVE`,
`UID_USERSAVE`, `UID_SOCKET`, ...) that is *itself* one of the literal
permission-class names already written directly into the matching
`access.db` line (e.g. `(/daemon/save): (all)[r] (mudlib)[rw]
(DaemonSave)[rw] (superuser)[rw]`) -- so the direct-euid-match branch
succeeds immediately and `groups.db` never needs an entry for
`DaemonSave`/`PostalSave`/etc. at all. Confirmed live: `daemon/save/`
files (`economy.o`, `events.o`, `player_list.o`, ...) all had fresh
mtimes after a normal boot and playthrough, with zero `permission
denied` lines anywhere in `debug.log`. **Verdict: §8.24's pattern does
NOT reproduce here** -- this lib's `check_access()` is written
differently from `rifts2`'s inherited copy in exactly the way that
avoids the bug (the two libs share the surrounding file structure and
comments but not this function's actual logic). No `groups.db`/
`access.db` change made.

**Full playthrough**: `look`/`score`/`inventory` after every state
change; joined the Fighter guild via the organic route (walked an
admin-`trans`-assisted path to `/d/damned/guilds/join_rooms/
fighter_join` and typed `join` -- succeeded, guild mods applied
correctly: HP 38->64, Mental 6->25, plus a starting gold/silver grant)
and trained a skill there (`train melee`, correctly deducted
development points and reported the new percentage and next cost). No
admin/direct guild-join shortcut command exists anywhere in this
codebase (grepped `cmds/` for a `set_class`/`set_member_status`-driving
wizard command -- none found) -- documented honestly as "only one path
exists," not silently skipped.

No dedicated safe-sparring mechanism exists in this codebase either (no
`accept_fight()`/stat-mirroring dummy anywhere, confirmed via grep) --
the nearest guild-side NPC (`t_guard.lpc`, guarding the treasury
door) is a fully-armed, very high-stat door guard, not a sparring
partner. Used the deliberately weak, stationary
`d/excelsior/newbie/mon/halfling.lpc` (`set_skill("dodge",0)`,
`set_skill("parry",0)`, level 1) instead, per the checklist's
"weak wild NPC" fallback. Real combat produced real bidirectional
damage (confirmed `get_damage()`'s unarmed-strike branch is fully
implemented and exercised, NOT the "weapons never populated, 0 damage
always" content gap `rifts2` separately documented as a genuine
unfinished-content issue in ITS OWN reskinned combat data -- that gap
does not reproduce in this, the ancestor lib, whose base
`std/living/combat.lpc` is fully functional) -- limbs got crippled and
severed, the character died cleanly (`death_stage`-equivalent flow:
"You die" -> "you rise above your corpse" -> immediate reincarnation
with full health, gold/inventory dropped to the corpse), and
`debug.log` stayed completely clean through the entire death sequence
(only ordinary first-load compile warnings from lazily-loaded
`damage_d.lpc`/`pk_d.lpc`/`_unequip.lpc`, no errors).

`quit` -> `debug.log` grep (clean, zero error/denied/undefined-function
lines) -> a real ~3-minute wall-clock gap -> reconnect with the same
account/password restored the exact same character state (guild,
trained skill, dev points, zeroed gold/silver from the death above) in
the room set by `quit`'s own "Setting start location" mechanic (Akkad
Church, a resurrection-shrine room, not the death location) --
confirmed both the save and the restore paths work correctly.

**Shop/economy: attempted, blocked by a real (non-bug) in-game
condition, honestly flagged unverified rather than skipped silently.**
The Fighter guild shop (`fighter_shop.lpc`) enforces real business
hours (`set_close_function(..., "16:00:00")` /
`set_open_function(..., "7:00:00")`) and the in-game clock
(`EVENTS_D->query_time_of_day()`) was genuinely "night" for this
entire session -- confirmed via `eval` as a real, moving day/night
+ moon-phase cycle (`ASTRONOMY_D->query_moon_light()` returned a
real, non-stuck value), not a broken/frozen clock. This also fully
explains an initially-suspicious observation (`look` showing "It is
dark." in the outdoor Newbieville town square, whose own `.lpc`
explicitly sets `set_property("light", 3)`) -- `total_light()`'s
`"night"` branch legitimately subtracts more than that base light
level when the moon is dim, which is exactly what a 1999-era
MudOS day/night/moon-phase darkness system is supposed to do. Neither
of these is a bug; both are documented here so a future session
doesn't waste time re-investigating them. Did not budget enough
remaining session time to wait out to daytime and complete a real
purchase -- flagged unverified-live, not tested.

**Long-sit idle boot watch**: `python3 scripts/mudclient.py 127.0.0.1
40258 --timeout 225 --idle 300` (no WASM build exists yet for this lib,
so this is the native-driver equivalent of §10.0's watch, sitting on an
open, otherwise-idle connection at the login prompt for ~185
wall-clock seconds, run synchronously in the foreground) -- ended in
the login object's own normal inactivity-timeout disconnect
("Login timed out."), zero new `debug.log` errors, driver RSS a steady
~340MB the whole time. No lazily-loaded daemon failures surfaced.

**No new programming bug found** in this pass beyond what onboarding
(§3 above) already fixed -- despite the ACL deep-dive, the combat
system, guild-join, skill training, death/respawn, and quit/reconnect
all independently exercised live and found clean. Documenting a clean
result explicitly, per this project's standing rule against silently
treating "found nothing" the same as "didn't look."

## 8. WASM status

Measured 2026-09-03 against the shared `~/src/fluffos/build-wasm`.
No mudlib-side compile fix was needed (`dump_socket_status` lives
only in a creator `_netstat` command). Verified with
`scripts/wasm_client.js`: `fluffos` / `Mud@2026` into Newbieville
town square (`/d/newbieville/rooms/townsquare`, five exits including
castle), `score` showed "Novice Fluffos the High-man" Health 31,
`quit` printed "Saving...Successful." Shop/combat/death were not
exercised this pass.

## 9. AGENTS.md §7.19 (room/prop variant) -- kobold pond reentrancy crash, fixed

Corpus-wide `enable_commands()`/`init()` reentrancy sweep (AGENTS.md
§7.19) flagged `d/camps/kobold/rooms/pond.lpc:26` as a structurally
distinct instance: not the ES2/Xiyouji player-wrapper architecture the
main sweep fixed (66 libs), but a scenery prop cloned into a real room
(`d/camps/kobold/rooms/camp07.lpc`, `new(PATH+"pond")->move(this_object())`
in `create()`) whose own `init()` unconditionally called
`enable_commands()`.

**Live-confirmed real and severe, not a false alarm.** The driver's
`enable_commands()` (`packages/core/add_action.cc`) re-invokes `init()`
on environment/sibling/inventory objects whenever `enable_commands
call init` (default ON, `__RC_ENABLE_COMMANDS_CALL_INIT__`) is set --
regardless of the `setup_actions` argument passed. Because the pond is
sitting in camp07's own inventory, every living object (an
already-`enable_commands()`'d player) entering camp07 makes the
driver's own command-registration cascade call the pond's `init()`
again while the ORIGINAL call is still on the stack; that nested call
hits `enable_commands()` again and re-enters the same cascade,
recursing until the control-stack depth limit aborts it.

Reproduced live pre-fix: `goto /d/camps/kobold/rooms/camp07` as the
`fluffos` admin threw `Too deep recursion.` immediately (the player
was NOT moved, `debug.log` blamed `/std/room.lpc:54` -- the closing
brace of camp07's inherited `::init()`, the frame that finally
exceeded the depth limit inside the reentrant cascade). This is not
first-visit-only self-healing: the pond permanently gets its
`O_ENABLE_COMMANDS` flag set on the very first (aborted) attempt, and
every subsequent player entering camp07 re-triggers the same crash via
the driver's per-object command-registration loop -- i.e. camp07 was
permanently unusable, not just broken on its first-ever visit.

**Fix**: guarded the call with `if (!living(this_object())) enable_commands();`
(see the in-code comment for the full reasoning). Unlike the
player-wrapper §7.19 case, a plain `living()` guard is safe here --
the driver sets `O_ENABLE_COMMANDS` as literally the first statement
inside `enable_commands()`, before any recursive init() cascade runs,
so `living()` already reflects the truth for a reentrant call; and
this prop has no legitimate re-enable-while-living use case the way a
player's revive/wakeup/disguise-removal flows do (no `catch_tell()`,
no `command()` use, and `add_action()` doesn't require
`enable_commands()` to function at all -- the call appears to be
inert copy-paste, per the file's own header comment "Code ripped from
Khojem's vats and stream").

Re-verified live post-fix with a full driver restart: fresh login (the
`fluffos` account's saved start location is camp07 from the pre-fix
test) drops straight into camp07 with no crash, `look`/`fill` both
work normally, `debug.log` shows zero "Too deep recursion" occurrences
across the whole post-fix session. Compile-clean (single-file
recompile via driver restart, no new warnings/errors on this file).

## 10. §10.7 deep functional test (round two, second pass, 2026-09-01) -- disconnect-during-character-creation soft-lock, fixed

New angle from this pass's assignment: adversarial/malformed input and
disconnecting mid-action, plus a corpus-wide re-check of the
`enable_commands()`/`init()` reentrancy shape (§9 above) for other
instances. The reentrancy re-check was **clean**: every other
`enable_commands()` call site in this codebase
(`d/zortek/spells/channel_ward.lpc`'s in `create()` before any
`move_object()`, `std/monster.lpc`'s in `__INIT()` -- itself only ever
called from `create()`, never `init()` -- and the various `std/user*.lpc`
player-wrapper variants' own self-enabling in `init()`) is either on a
living object enabling its own commands (the normal, safe shape) or runs
before the object has an environment to cascade into. No second instance
of the dangerous "scenery prop cloned into a room's own inventory,
unconditional `enable_commands()` in `init()`" shape found anywhere else
in the corpus.

**Severe bug found and fixed via the disconnect-mid-action angle:
disconnecting during character creation's stat-assignment step
permanently soft-locks the account, unrecoverable without a wizard.**

`d/standard/setter.lpc`'s `pick()` (the `pick <race>` command) moves the
player into `/d/standard/waiting_room` (line 182, before this fix) and
then calls `do_rolls()` (line 183), which prints the stat-assignment
intro and registers `input_to("press_enter", ...)`. That kicks off a
multi-step `input_to()` chain (`press_enter` -> `assign_point`/
`pick_stat` -> `yes_or_no`) that only ends when the player types "yes" to
confirm their stat spread, at which point `yes_or_no()` finally sets
`who->set_property("dev points", dev_tot)` and moves them onward via
`set_ansi()`/`set_ansi_two()` to `ROOM_NEWBIE`.

**Root cause**: a pending `input_to()` callback does not survive a
reconnect. `adm/obj/login.lpc`'s `is_copy()` reattaches a returning
connection to the same in-memory player object via a plain
`exec(ob, this_object())` (confirmed live: this is the *only* code path
taken once the prior connection is no longer `interactive()`, which is
the ordinary case for a real link death or a client just closing) --
this does not preserve whatever `input_to()` chain was pending on `ob`.
Since `/d/standard/waiting_room.lpc` (before this fix) had **zero exits
and no `add_action` commands of its own** -- the `pick`/`read` commands
live on the setter room the player already left -- a player who
disconnects anywhere between `pick()` and the final "yes" confirmation
comes back to a completely dead room: ordinary commands like `look`/
`score` still work (global commands, not tied to the room), but there is
no way to move, no way to resume the stat-assignment prompt, and no way
to ever finish creation. `"dev points"` stays unset/left at whatever
value it had before (0 for a genuinely new character), so `score` shows
`DevPts: 0`, `Race:` whatever was picked, `Master: None`, forever.

**Live-reproduced** (native driver, port 40258): registered
`Novaquest`/`Testfixer` fresh, paged through the MOTD, `pick dwarf` /
`pick wood-elf`, then deliberately let the TCP connection close right at
the `"Press [enter] to continue:"` prompt (mid `do_rolls()`) instead of
answering it. Reconnecting with the same name/password showed
`"Password: Reconnected."` immediately followed by the room's bare
`"This is the waiting room, you are in the creation process. \n\nThere
are no obvious exits."` with no way to progress -- confirmed `pick
<race>`, `out`, `exits`, and every direction all fail (`"What?"` /
`"You cannot go that way."`) in this state, only `look`/`score`/`help`
(global commands) respond. Also confirmed this is **not** a driver-restart
artifact: within one continuous driver session the stuck state persists
across as many reconnects as tried; only a full driver restart discards
it (because it reloads from the last periodic `save_player()` snapshot,
which in this lib runs on a `call_out("save_player", 2, ...)` scheduled
at every login/`std/user.lpc:491` -- 2 real seconds after the *previous*
successful login, so it generally lags behind live progress and isn't a
substitute for testing within one boot).

**Fix**: `d/standard/waiting_room.lpc` gained an `init()` that detects
"reconnected with character creation still incomplete" and re-invokes
`ROOM_SETTER->do_rolls()` (`ROOM_SETTER` = `/d/standard/setter`, from
`adm/include/rooms.h`) to restart the stat-assignment step from scratch
(safe, since no partial point allocation is ever saved to the player
object until the final "yes" -- there is nothing partial to lose).
`d/standard/setter.lpc`'s `pick()` gained a matching pair of `set()`
calls on a new player property, `"__creation_complete"` (reset to 0
right before `pick()`'s own `move()`+`do_rolls()`, set to 1 only at the
very end of `yes_or_no()` alongside `"in creation"` going back to 0) --
this is the completion marker the room's `init()` checks, **not**
`"dev points"`, because a *reincarnating* character
(`daemon/reinc_d.lpc` moves players back through this exact same
`ROOM_SETTER`/`pick()`/`waiting_room` flow to re-roll) already has a
real, nonzero `"dev points"` left over from their previous life -- that
property alone can't tell "never finished this `pick()`" apart from
"finished a *previous* life's `pick()`" for a reincarnating player who
disconnects mid-reroll, which would have silently left that case
unfixed.

**A second, more severe bug was found and fixed while verifying the
first fix live**: the very first (pre-guard) version of the
`waiting_room.lpc` `init()` above checked only `"in creation"` and
`!"dev points"`, with no guard against re-entering `do_rolls()` while
`pick()`'s own call to it was still on the stack. `move_object()`
synchronously calls the destination room's `init()` as part of the same
driver mechanism documented in §9 above
(`packages/core/add_action.cc`'s `setup_new_commands()`, called directly
by `move_object()` for any object with `O_ENABLE_COMMANDS` set, not just
the `enable_commands()`-cascade path) -- so `pick()`'s own
`who->move("/d/standard/waiting_room")` on line 182 immediately,
synchronously, called the room's new `init()`, which (before the
`"__setup_in_progress"` guard existed) matched the exact same "in
creation, no dev points yet" condition on **every single normal, never-
disconnected character creation** and called `do_rolls()` a second,
reentrant time -- registering a duplicate `input_to()` on the same
player object while `pick()`'s own subsequent `do_rolls()` call was
about to do the same thing. **Live-confirmed severe**: this crashed the
*entire driver process* on the very next command after `pick <race>`
(reproduced twice, both a "brand-new-character-plus-`pick`" session
against a freshly-booted, otherwise idle driver) --
```
#0 mudlib_stats.cc:178, in add_moves: if (st->domain) {
#1 add_action.cc:479, in user_parser: add_moves(&s->ob->stats, 1);
Segmentation fault (Address not mapped to object [0xd0])
```
-- consistent with a stale/dangling `sentence->ob` (null `s->ob`, and
`offsetof(object_t, stats)` on this build is exactly `0xd0` = 208,
matching the faulting address) left in the action/sentence list by the
duplicate `input_to()`/`add_action` registration. Fixed by adding the
`"__setup_in_progress"` property (set by `pick()` immediately before its
own `move()`+`do_rolls()`, cleared immediately after) as a third
condition on the room's `init()` -- this is the only thing that reliably
distinguishes `pick()`'s own single correct call (guard is true) from a
genuine later reconnect (guard is always false, since it's cleared
synchronously before `pick()` ever returns control to the input loop).

**Re-verified live, full regression pass, after the reentrancy fix**:
three fresh characters (`Brintor` the Dwarf, `Calidor` the Gnome,
`Whistrel` the Sprite) each completed the ENTIRE normal creation flow
end-to-end with no crash and no reconnect involved (confirms the
reentrancy fix didn't just move the bug -- ordinary, uninterrupted
creation is unaffected). Two more characters were deliberately
disconnected mid-flow at two different `input_to()` stages (`Calidor` at
the `"Press [enter] to continue:"` prompt right after `pick`, `Whistrel`
at the final `"(yes or no):"` confirmation prompt) and reconnected within
the same driver boot: both correctly saw `"Your character creation was
interrupted -- restarting stat assignment."` and were walked back through
a fresh stat-assignment sequence to a normal completion (`DevPts: 44`,
moved to Newbieville town square, `score`/`look`/`i` all functioning
normally afterward), with **zero further crashes and zero new
`debug.log` errors** (`work/log/debug.log` and the live
`/log/debug.log`, per the §10.9 dead-log caveat -- checked the live one)
across the whole multi-character regression session. A subsequent normal
reconnect on an already-*completed* character does not re-trigger the
recovery message (confirmed on `Brintor`), since `"__creation_complete"`
is correctly left at 1.

Files touched: `d/standard/waiting_room.lpc` (new `init()`),
`d/standard/setter.lpc` (`pick()` and `yes_or_no()`, both in the file's
existing functions, no new functions added).
