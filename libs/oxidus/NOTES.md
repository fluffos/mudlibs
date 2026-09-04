# oxidus — technical notes

Source: `gh repo clone gesslar/oxidus-mudlib` (cloned 2026-08-28/30).
Number 954, port 40256. Status: **done** — boots clean natively, full
registration-to-gameplay playthrough verified live and repeatedly.

## What this lib is

A genuinely modern, actively-developed (pushed within the last day as of
this session), from-scratch FluffOS mudlib — not a 1990s/2000s legacy
archive like nearly everything else in this corpus. Already `.lpc`
throughout, already UTF-8, ships its own `AGENTS.md`/`.claude/skills/`
(37 skill files) documenting its own coding conventions, has a real unit
test suite under `tests/` (STD_TEST framework), and targets a specific,
current FluffOS build via its own `adm/dist/rebuild` pipeline (clones
fluffos/fluffos as a submodule and builds it from source with a custom
`local_options`). Ran `scripts/convert_lib.sh` per §2.3 convention
(cheap and safe even though 0 lossy conversions were needed) — it fixed
20 literal-`.c`-reference stragglers and converted 46 local
angle-bracket includes to quotes.

8 authored content areas confirmed real (not stock/copied): a village
(Olum) with a bakery, tailor, financier, manor interior, an arcanist
NPC/spell tree, forest/cavern/maze/tunnels/wastes zones. Account-based
login (register an ACCOUNT with a password, then create/select a
CHARACTER under it) rather than the straight-into-a-name flow most
libs in this corpus use — matches the README's own description. The
first character ever created becomes the mud's owner/admin
automatically (confirmed live).

## Driver-build mismatches found and fixed (see AGENTS.md for the full writeup)

This lib assumes a considerably newer/differently-configured driver
than this corpus's shared build had, in three independent ways. All
three are documented as new AGENTS.md catalog entries since they're
real, generalizable classes other modern-lib onboardings could hit:

1. **`async`/`await` support was simply not yet built** into this
   session's shared driver — the checked-out `~/src/fluffos` was on a
   local branch (`claude/async-phase15`) 3 commits ahead of its own
   `origin/master`, and the async/await feature itself (`858d5da9`,
   merged 2026-08-27) postdated the driver binary's last build
   (2026-08-21) by 6 days. **Not a driver bug** — confirmed via a clean
   minimal repro (`async mixed foo() { ... }` failed identically in a
   throwaway single-file test, succeeded after a plain rebuild) before
   concluding anything. Fixed by rebuilding `~/src/fluffos/build-debug`
   (`cmake --build . --target driver lpcc -j8`) from the current
   checkout — a corpus-wide driver rebuild, not an oxidus-specific
   change, so every other lib in this corpus benefits/is affected by it
   too going forward.
2. **`include/driver/*.h` didn't exist** — oxidus's own build pipeline
   (`adm/dist/rebuild`) copies the driver's own `src/include/*.h`
   (`type.h`, `socket.h`, `function.h`, etc. — "headers shared between
   driver and mudlib" per their own README) into the mudlib tree at
   `include/driver/` as a build step; this repo's `libs/oxidus/work`
   never got that step run. Fixed by copying
   `~/src/fluffos/src/include/*.h` into `libs/oxidus/work/include/driver/`
   once, by hand — this is a one-time bootstrap step, not something
   that needs to happen on every boot.
3. **PACKAGE_UIDS stub applies missing** — `adm/obj/master.lpc` had no
   `get_root_uid()`/`get_bb_uid()`/`creator_file()` at all (this lib
   doesn't use the UID/euid privilege model — "Oxidus uses the FluffOS
   privs model, not PACKAGE_UIDS" per its own `AGENTS.md`), but this
   corpus's shared driver build has `PACKAGE_UIDS` compiled in, which
   `exit(-1)`s the whole driver at boot without the first two apply.
   This is the well-catalogued AGENTS.md §7.2 pattern (also just seen
   again on `majik4`, §7.160) — fixed with the standard flat "everyone
   is Root"/"BACKBONE" stub, harmless since oxidus's real security model
   (path-based ACL + role groups in `adm/obj/master/security.lpc`) never
   consults these.
4. **`OLD_ED` vs the modern `ed_start()`/`ed_cmd()`/`query_ed_mode()`
   trio** — new AGENTS.md §7.161. This corpus's shared driver has
   `OLD_ED` defined (hundreds of other libs' own wizard editors depend
   on the classic `ed()` efun), which compiles the modern efun set out
   entirely; `std/living/ed.lpc`'s `ed_edit()` had been rewritten to use
   them, breaking `std/living/body.lpc`'s ENTIRE inheritance chain
   (every player/NPC class) at compile time. Fixed by reverting
   `ed_edit()` to the classic `ed(file, write_fn, exit_fn, restricted)`
   API — simpler than the session-style version it replaced, since the
   driver owns the whole input loop once `ed()` is called (no
   `input_to()` loop needed).

## Real programming bugs fixed (beyond the driver-mismatch items above)

- **New AGENTS.md §7.162**: `ed_write()`/`ed_exit()` (the write-
  authorization/session-end callbacks passed to `ed()` as plain string
  arguments) were declared `private`, following this lib's own correct
  convention that fixed-name driver applies (`create`, `heart_beat`,
  `valid_read`, etc.) should be `private` since "the driver ignores
  visibility" for those. But `ed_write`/`ed_exit` are a DIFFERENT
  mechanism — a mudlib-chosen callback name resolved via the driver's
  generic by-name `apply()`, the same path `call_out()`/socket
  callbacks use, which explicitly does NOT bypass visibility
  (`function_exists()`'s own docs: private/protected functions are
  "treated as not defined" for any external caller). A `private`
  `ed_write()` is silently never invoked: `ed`'s `w`/`x` commands always
  print the generic "Failed command.", with nothing in any log file
  anywhere (`safe_apply()` swallows "function not found" silently).
  Isolated with a throwaway command object before touching the real
  fix: identical `ed()`+callback code worked instantly as `public`,
  failed identically as `private`. Fixed by making both `public`.
- **New AGENTS.md §8.21**: `adm/obj/login.lpc`'s `create_body()` called
  `body->restore_body()` a second, redundant time immediately after
  `BODY_D->create_body()` had already restored the body AND run
  `std_setup()` (which computes role-based command search paths —
  `/cmds/adm/`, `/cmds/dev/`, or just the standard set, depending on
  `adminp()`/`devp()`). Since `__command_paths` isn't `nosave`, the
  second restore silently reverted it to whatever was saved BEFORE the
  character's last promotion — every admin/dev who reconnects (not just
  their very first post-promotion login, since `makeadmin`/`makedev`
  add the paths directly to the live body) gets full normal gameplay
  but every `/cmds/adm/`, `/cmds/dev/`, `/cmds/file/` command —
  including the in-game `ed`/`edit` editor — silently doesn't exist,
  with the driver's generic "What?" fail message giving zero signal
  this is a permissions bug rather than a typo. Root-caused via targeted
  debug instrumentation showing `std_setup()`'s own `get_path()` result
  (6 entries, correct) diverging from `command_hook()`'s live
  `__command_paths` (3 entries, stale) moments later. Fixed by deleting
  the redundant call in `login.lpc`.
- `std/living/body.lpc`'s `std_setup()` called `adminp()`/`devp()` with
  NO argument, which defaults to `previous_object()` — at that call
  site, `previous_object()` is `std_setup()`'s OWN caller (`body_d`, or
  the driver's `create()` apply), never the body itself, so the role
  check was silently checking the wrong identity's privileges (always
  false in practice). This bug was masked by the §8.21 restore-clobber
  bug above during testing (fixing one alone wasn't enough to observe
  correct behavior; both needed fixing together to actually see role-
  based paths survive a reconnect) but is independently real and worth
  fixing on its own merits. Fixed by passing `this_object()` explicitly.
- `std/cmd/reporter.lpc`'s `set_git_hub_label()` (shared by the `bug`,
  `idea`, and `todo` commands, both the `std` and `ghost`/`dev`
  variants — 5 command files total) called `mud_config("GITHUB_REPORTER")`
  directly; `CONFIG_D->get_mud_config()` `error()`s on any unset key
  rather than returning null/0, and GITHUB_REPORTER has no default and
  ships unconfigured in a fresh self-hosted install (nothing in
  `adm/etc/default.lpml`, no example config anywhere, no mention in
  README/DOCKER.md's setup steps). Since this ran from `setup()` during
  the object's own `create()`, the uncaught `error()` took the WHOLE
  command down for every player, not just the optional GitHub-issue-
  filing half — even though `finish_report()` already has a graceful
  `git_hub_label != ""` skip-if-unconfigured path built in, meaning the
  intended "GitHub filing is optional, local-log-only reporting always
  works" behavior (explicit in three of the five commands' own help
  text) was entirely broken by this one setup-time validation. Fixed by
  wrapping the `mud_config()` call in a `catch()` and returning early
  (leaving the label unset, matching the already-correct downstream
  skip) when the config key genuinely doesn't exist, while keeping the
  strict `error()` for a config that DOES exist but names a label the
  caller passed that isn't in its `types` list (a genuine caller bug,
  should stay loud).
- `std/object/include/object.h` had a stale duplicate/conflicting
  `void set_real_name(string str);` prototype (a second, correct
  `string set_real_name(...)` prototype already existed 4 lines later)
  and a stale `void remove();` prototype conflicting with the real
  `int remove()` implementation in `object.lpc` — both produced
  "Previous function prototype ... does not match" warnings on every
  single boot (cosmetic, no functional impact, but real dead/wrong
  declarations). Removed the two stale lines.

## lpcc-only artifact — NOT a real bug (cross-checked against a live boot)

`lpcc_check.sh`'s batch compile-sweep segfaults deterministically at
`/d/village/bakery` (confirmed reproducible: identical crash, same
file, same C++ stack trace, on two separate runs). Root cause: FluffOS's
`main_lpcc.cc` unconditionally calls `Tracer::start("trace_lpcc.json")`
at the top of `lpcc_main()` — `lpcc` ALWAYS runs with the internal
profiling Tracer active, unlike a normal `driver` boot (`mainlib.cc`
only starts it when a `--trace-log`-style flag is explicitly passed,
which nothing in this pipeline does). The crash itself is inside the
Tracer's `get_trace_id()` (a null/garbage `function_table[...].funcname`
pointer reaching `std::string`'s constructor → `strlen()` segfault) and
is reached via a nested `call_other` → simul_efun `evaluate()` →
`call_other` chain during `bakery.lpc`'s `create()` (it's the only file
in the village using `EXT_SHOP_MENU`). This looks like a real driver-
level bug in the Tracer/frame-bookkeeping code on this session's WIP
`claude/async-phase15` branch (a code comment elsewhere in the driver
already flags a concern about `FRAME_ASYNC`/`FUNC_VARARGS` bit overlap
in exactly this kind of frame-kind check) — but it is a **compile-sweep-
tool-only artifact**, not a real gameplay bug: bakery loads and plays
correctly under the real `driver` boot (confirmed live — visited the
room via a fresh player character, no crash, normal shop room). Per the
established "lpcc-vs-live-driver artifact" pattern in this project,
flagged here rather than "fixed," and NOT reported as an oxidus bug.
The rest of the corpus (482 other files, bakery excluded from that one
run) compiles 100% clean via `lpcc_check.sh`.

## Intentionally not "fixed" — real, environment-dependent, by design

- `adm/daemons/discord/chatter.lpc` (explicitly labeled "Chatter Discord
  Bot Example" in its own file header) fails to load with `error("Bot
  not setup")` — it needs a real Discord bot token via `DISCORD_BOT`
  config, which nothing in this sandboxed environment can provide. It
  is not preloaded and not reachable from normal gameplay; this is
  example/reference code for admins who want to wire up a real bot, not
  a broken feature. Matches this corpus's existing precedent for
  `imud`'s real Intermud-3 network dependency (§2.3).

## Playthrough verification

Full session via `scripts/tmux_mud.sh`, native driver
(`~/src/fluffos/build-debug/src/driver config.fluffos`, cwd
`libs/oxidus`), port 40256:

- Registered a new account (`elarion`/password, with confirmation) →
  became the mud's first character/owner automatically → landed in the
  admin-only "Developer Workroom" starting room (not the normal player
  start) → `look`/`score` both correct.
- Registered a second, independent account (`wisteria`) → normal
  character creation (lowercase-only name validation confirmed) →
  landed in the real starting room, "Village Square of Olum" → `look`/
  `score`/`inventory` all correct → walked west twice into the village
  content (tavern, a "gathering place for newcomers" room) → confirmed
  real, distinct room descriptions, not placeholders.
- Reconnect/restore path verified independently for both accounts
  (quit, disconnect, reconnect, select existing character — correct
  each time).
- Promoted `wisteria` to developer rank (`makedev`, run as the admin
  account) to test wizard-only commands on a non-admin identity; used
  `dest`/reconnect cycles (destroying and recreating the live body
  object) to confirm each fix against a genuinely freshly-compiled
  character rather than a stale in-memory clone predating a given fix —
  this was essential for finding and confirming both the §8.21 restore-
  clobber bug and the §7.162 private-callback bug, neither of which
  would have been distinguishable from "already fixed, just testing a
  stale object" without it.
- Full `ed` (in-game line editor) session verified end-to-end as a
  freshly-promoted developer: `ed <file>` on a nonexistent file → `a`
  (append) → typed a line → `.` (end input) → `x` (write and quit) →
  "Exit from ed." with no error, and the file's actual on-disk content
  confirmed correct afterward (`home/w/wisteria/final.txt`). Also
  confirmed the permission gate itself works correctly: a `write:
  "self"` path rule (`/home/*/*/**`) let a developer write their own
  home directory but correctly denied a write to mudlib root
  (`/tmp_final_verify.txt` → "Permission denied.", not a crash).
- `quit` clean both times (proper goodbye message, connection closed).

## Minor unfixed observation (not root-caused, doesn't block anything)

An empty directory named after the character (e.g. `wisteria`, `elarion`)
appeared at the mudlib ROOT (not under `/home/<letter>/<name>/`, the
correct home-directory location) after the first admin bootstrap login
and again after a `makedev` promotion. Harmless (empty, never referenced
by anything observed during the playthrough) and not chased down to a
specific line — `cwd` defaults to `/doc` (`std/living/player.lpc`), not
a bare name, so the stray `mkdir` isn't there; likely somewhere in
`login.lpc`'s admin/dev promotion path or `body_d`. Deleted both before
committing (test-session cruft, not shipped content). Worth a closer
look in a future pass if it turns out to recur for every ordinary
character too, rather than just the admin/dev promotion paths tested
here.

## WASM

Not yet WASM-packaged for the browser gallery (§1.4 pass) — this
session's scope was native onboarding + bring-up per the standard
pipeline; WASM triage left for a follow-up pass, matching the same
"native-boot verified, WASM pending" status other very recently
onboarded libs in this corpus (e.g. `rifts2`) currently carry.

## WASM measurement (2026-09-03)

`meta.json` was already `playable` from the 2026-08-31 deploy-unblock;
the README still said "not yet packaged." Cold-boot under the shared
`~/src/fluffos/build-wasm` reached the account prompt, but every
room failed to compile: `std/room/room.lpc` `gmcp_room_info()` calls
`hash("md4", ...)` (a PACKAGE_CRYPTO efun the WASM build does not
have). Added `adm/simul_efun/hash.lpc` (compiled only when
`__PACKAGE_CRYPTO__` is absent; native keeps the real efun) and
included it from `adm/obj/simul_efun.lpc`. After that,
`scripts/wasm_client.js` created account `wasmxid` / character
`wasmox` / `Mud@2026` and landed in Village Square of Olum (five
exits), `look` reprinted the square, `score` showed "You are Wasmox,
a level 1 human." HP 100, `quit` printed "Y'all come back, now,
y'hear?" Shop/combat/death were not exercised this pass. The MEMFS
copy does not write the throwaway account back to the host.

## §10.7 deep functional test (2026-08-31)

Round-two deep-functional-test pass, going beyond the onboarding
playthrough into actual game systems: combat, skills/spells, equipment,
shop economy, consumables, death/respawn, and a real quit+reconnect gap.
Native driver (`~/src/fluffos/build-debug/src/driver config.fluffos`,
rebuilt since onboarding — confirmed still the correct build, async/await
and `ed()` fixes both still in effect), port 40256, via
`scripts/tmux_mud.sh`. Three accounts used: `thornwick`/`elmswood`
(first-ever character on this driver boot, auto-admin, used for `makedev`
promotion and `eval`-assisted mob spawning), `briarwyn`/`willowmere`
(second character, used only to verify the stray-directory fix), and
`cinderfall`/`moonshade` (main playthrough character, promoted to
developer for `gimme`/`healup`).

### Upstream movement check (informational, not acted on)

Per the task brief, checked whether `gesslar/oxidus-mudlib` has moved
since this project's clone (2026-08-28/30). It has, substantially:
`gh api repos/gesslar/oxidus-mudlib/commits?since=2026-08-28T00:00:00Z`
returns 21 commits between 2026-08-29 16:01 and 2026-08-31 14:02 (today,
a few hours before this test pass — `gh repo view` confirms `pushedAt:
2026-08-31T17:44:59Z`). Notable commit subjects suggest the areas most
likely to have diverged from this snapshot are exactly the two this
project's onboarding had the most friction with: the login/account
system (`login object updated`, `promise-driven login handshake`) and
the async/promise infrastructure (`gmcp_await`, `promises header file`,
`request_deadline never fulfils; type it that way`, `LPCDoc unwraps
promises; document the payload`). This is informational only per the
task brief — not re-synced, not investigated further, and none of the
bugs found in this pass were re-checked against the newer upstream code.
A future re-onboarding pass should expect the login/async areas in
particular to have changed shape.

### Bug found and fixed

**`adm/obj/login.lpc:449` — `new_character()`'s home-directory setup
call passed the bare character name to `assure_dir()` instead of a real
path, creating a spurious empty directory named after the character at
the mudlib ROOT on every single character creation (not just
admin/dev promotions) — this closes the "Minor unfixed observation" left
open in this lib's own onboarding NOTES.**

- The function's own doc comment says it "Validates length, format, and
  uniqueness, then creates the character, body, and home directory" — but
  the actual call was `assure_dir(str);` where `str` is the bare
  lowercase character name (e.g. `"elmswood"`). `assure_dir()`
  (`adm/simul_efun/file.lpc`) builds a directory tree by
  `explode(path, "/")` and `mkdir()`-ing each successive segment; a
  bare name with no slashes just does one `mkdir("elmswood")` relative
  to the mudlib root, not the character's real home directory.
  `home_path(name)` (the correct helper, already used two lines further
  down inside `first_admin_login()` for exactly this purpose) returns
  `"/home/<first-letter>/<name>/"`.
- Confirmed the stray directory is genuinely harmless-looking but
  100% reproducible for EVERY new character, not just the first-ever
  admin bootstrap as the onboarding note speculated: created a third,
  ordinary (non-admin, non-dev) character `moonshade` on a fresh driver
  boot before applying the fix and got `work/moonshade/` (empty) at the
  mudlib root exactly as before.
- The real home directory (`/home/<letter>/<name>/`) is otherwise never
  created for any character except the very first (`first_admin_login()`
  only runs once, gated by the `FIRST_USER` marker file) — so every
  ordinary player's home directory silently doesn't exist until
  something else happens to create it (e.g. `ed`'s own write-permission
  path, which per onboarding's own testing DID succeed writing to a
  non-admin's home dir — the file-write efun apparently tolerates a
  missing intermediate directory here, or creates it, so this was
  latent rather than an active second bug).
- **Fix**: `assure_dir(str)` → `assure_dir(home_path(str))`. Verified
  live end-to-end: reverted the stray-directory symptom by creating a
  fresh character (`briarwyn`/`willowmere`) BEFORE restarting the driver
  and confirmed the bug still reproduced (objects don't recompile from a
  live edit — driver restart required, per AGENTS.md §10.3), then
  restarted the driver, applied the fix, created a THIRD fresh character
  (`cinderfall`/`moonshade`) and confirmed: no stray directory at
  mudlib root, and `/home/m/moonshade/` now exists with the correct
  `.keep` sibling structure. A final full long-sit idle boot watch
  (~220s, native `mudclient.py`, nobody logging in) also confirmed no
  new stray directories appear from boot alone.

### Confirmed working, no bugs found

- **Shop economy, both architectures** (`currency-and-shops` skill):
  the bakery's `EXT_SHOP_MENU` (`list`/`buy muffin`/`eat muffin`, correct
  price and change-in-copper math, item cloned fresh and consumed) and
  the tailor's `EXT_SHOP` (`list`/`buy tunic`/`wear tunic`/`remove
  tunic`/`sell tunic`, correct `sell_factor` payout and exact-coin
  change on both legs of the transaction). `wealth` command, `gimme`
  dev command, and `adjust_wealth()`'s currency-denomination math all
  verified correct across several buy/sell round-trips.
- **Equipment** (`equipment` skill): `wear`/`remove` on a clothing item
  worked correctly end-to-end including the shop round-trip above.
- **Consumables** (`consumables` skill): `eat muffin` correctly depleted
  the single-use food item and removed it from inventory with the
  documented "You have eaten the last of the muffin." message.
- **Skills** (`skills-and-advancement` skill): `use_skill()`'s
  auto-creation-on-first-use fired correctly — punching for the first
  time printed "You have gained a new skill: combat.melee.unarmed.",
  taking a hit for the first time printed the matching
  `combat.defence.dodge` message, and casting a spell for the first time
  printed `arcane.discipline.lightning`. The `skills` command
  (`cmds/std/skills.lpc`) correctly prints nothing for a skill-less
  character (its own recursive walk over an empty `query_skills()`
  mapping legitimately produces an empty string) — this is expected
  behaviour given `initialize_missing_skills()` (the function that would
  pre-seed the config's default skill tree) is dead code, never called
  from anywhere; not a bug, since the use-based auto-creation path is
  the one actually exercised by every real gameplay action.
- **Combat** (`combat-system` skill): fought a level-1 `field mouse`
  (admin-spawned into the village's `field` virtual zone via
  `add_inventory("mob/field_mouse")` — the correct virtual-object path
  form; see gotcha below) with the `punch` ability end-to-end across a
  full multi-round fight — hit/miss rolls, cooldown gating ("You must
  wait before you can use that again."), mutual damage, and HP loss all
  behaved correctly and consistently with the formulas in the skill doc.
- **Death and revival**: died for real (HP reached 0 from the field
  mouse's counter-attacks) — `"You have perished."` fired, a
  `the rotting body of moonshade` corpse appeared, wealth converted to
  loose coin objects in the room (not inside the corpse — a small
  presentation detail, not chased down further), and the player
  auto-revived 1 second later at 1 HP/1 SP/1 MP via `ghost.lpc`'s
  `call_out("revive", 1)` — a deliberately forgiving, near-instant
  revival design, not a bug. The revived player's own
  `move_cost()`-gated movement correctly refused a distance-2 exit
  ("That location is too far away to travel to right now.") until MP
  regenerated — also correct, not a bug (confirmed by reading
  `std/room/room.lpc`'s `move_cost()`).
- **Arcanist spell tree** (`skills-and-advancement` + `combat-system`
  skills): found Madame Brille in the manor's salon (see navigation
  gotcha below), `learn arcane` correctly granted
  `/cmds/spell/arcanist/` path access, `shield` (self-buff, costs SP)
  and `shock <target>` (offensive lightning bolt, costs MP, trains
  `arcane.discipline.lightning`) both worked correctly — the shield's
  damage-absorption message ("Your inertial shielding absorbs some of
  the damage.") correctly appeared on subsequent hits taken.
- **Reconnect with a real gap**: quit from the `moonshade` character,
  waited (a ~4-minute gap covering the long-sit boot-watch pass below,
  which required a driver restart in between), reconnected with
  `character@account` form — full state correctly restored (room,
  HP/SP/MP, wealth all exactly as left).
- **Long-sit idle boot watch** (~220s, native `mudclient.py --idle
  220 --timeout 220`, no login attempted): clean, only the same cosmetic
  compile warnings already documented as pre-existing/harmless; the
  connection was closed by the login object's own legitimate 60-second
  login timeout, not by anything unexpected.

### Not a bug: two same-`id` doors in the manor's Foyer

`d/village/manor/foyer.lpc` has two `add_door()` calls both using
`id: "foyer door"` (one north-facing to the porch, one east-facing to
the salon) with no distinguishing adjective. A bare `open door` (or
`open foyer door`) in that room correctly reports "There are multiple
doors with that name." — looked like a content bug at first (the room's
only two exits both blocked), but `std/room/door.lpc:add_door()` already
auto-appends a direction-specific alias (`door.name = "<direction>
door"`) to each door's `id` array specifically to handle this case:
`open north door` / `open east door` disambiguate correctly and are the
intended way to interact with a room that has multiple same-named doors.
Confirmed live. Not fixed, because it isn't broken.

### Flagged, not fixed: benign first-boot-only messaging race during the very first character's world-entry

Every fresh driver boot's first-ever `new_character()` call (which is
also always the auto-admin bootstrap path) logs 2-3 caught,
non-fatal `*Object cannot be loaded during compilation.` errors from
`std/ext/messaging.lpc:172` (`receive(message)`), reached via
`enter_world()` → `move_living()` → `force_me("look")`'s own
`command_hook()` chain. Confirmed genuinely reproducible, not a
one-off: it happened identically for `elarion` (the original onboarding
session's first character, 2026-08-30 19:51, per `log/runtime`) and
again for `elmswood` (this pass's first character, 2026-08-31 12:24) —
but did NOT recur for any subsequently-created character on either
driver boot (`wisteria`, `briarwyn`/`willowmere`, `cinderfall`/
`moonshade`), confirming it's specific to the very-first-ever compile of
the full player class hierarchy on a cold boot, not a general messaging
bug. `enter_world()` already wraps the relevant calls in `catch()`, so
nothing crashes, and the player-visible outcome was correct both times
(the new admin lands in the Developer Workroom with a correct room
description). Root cause not fully chased down (plausibly a
`COLOUR_D`/`LINES_D` daemon still finishing its own first-ever lazy
compile at the exact moment `receive()` tries to use it) — flagged here
per this round's "document honestly rather than guess" instruction
rather than risking a speculative fix to first-boot compile ordering.

### Flagged, not fixed: `defence`/`defense` skill-path spelling split (zero live impact)

Every live combat/spell code path (`std/living/combat.lpc`,
`std/living/damage.lpc`, `cmds/ability/punch.lpc`, weapon procs, all
five arcanist spell files) consistently uses the Canadian-English
spelling `"combat.defence.dodge"` / `"combat.defence.evade"` — correct
per this project's own mandated Canadian-English house style
(`AGENTS.md`'s own example list literally includes "defence"). Live
gameplay in this pass confirmed this spelling is what actually gets
trained and queried ("You have gained a new skill:
combat.defence.dodge."). However, `adm/etc/default.lpml`'s configured
default skill tree, and this lib's own `.claude/skills/` documentation
(`combat-system` and `skills-and-advancement` SKILL.md), both use the
American spelling `"combat.defense.dodge"` / `"combat.defense.evade"`
instead. This is a real spelling inconsistency, but has **zero live
functional impact** today: `initialize_missing_skills()` (the function
that would seed the config's `"defense"`-named default tree onto new
characters) is dead code, never called from anywhere in the codebase,
so nothing ever tries to reconcile the two trees — every skill node in
practice is created lazily by `use_skill()`'s own auto-creation using
whichever spelling the calling code happens to use, and combat code is
internally self-consistent. Not fixed: which side is "canonical" here
is genuinely ambiguous (more call sites use "defence", but the config
schema and generated docs use "defense"), and there is no live bug to
reproduce/verify a fix against — flagged for whoever eventually
resolves it (`initialize_missing_skills()` dead code, or the doc
spelling, or both) rather than guessed at.

### Gotchas hit while testing (useful for future passes on this lib)

- **Virtual mob paths are NOT filesystem paths.** Spawning a monster for
  testing requires the routed virtual form
  `add_inventory("mob/<name>")` (no leading slash, `"mob/"` prefix),
  which `master()->compile_object()` routes through
  `adm/daemons/modules/virtual/mob.lpc` to `/d/mobs/<name>.lpml`.
  Calling `add_inventory("/d/mobs/<name>")` directly (a real absolute
  path, since only the `.lpml` data file exists there, no `.lpc`) fails
  with `"Something went wrong."` broadcast to the room and logs `*Too
  deep recursion.` to `log/VIRTUAL` — an artifact of feeding the wrong
  path form, not a mudlib bug (self-inflicted during this pass, verified
  the correct form works cleanly on the next attempt).
- **`this_body()`/`this_player()` inside the `eval` dev command's
  scratch object is unreliable for chained calls.** `eval`
  compiles the given statements into a fresh, unrelated
  `/tmp/eval_<name>.lpc` object and runs them with the caller's privs,
  but `this_body()` (`efun::this_player()`) inside that context returned
  `0` when chained (`this_body()->environment()`). Use `find_player(name)`
  to get a reliable reference to a live player object from inside
  `eval`, and the bare `environment(ob)` efun (not `ob->environment()`,
  which calls a same-named method that doesn't exist) to get their
  room.
- The village's own two north/south "A Path Through the Village" rooms
  (`village_path1`/`village_path2`, reached from the square's `north`
  and `west` exits respectively) share the same room title and a very
  similar opening sentence structure but lead to different content
  (bakery vs. tavern) — easy to misnavigate by title alone; check the
  room's own listed exits, not just the heading, when route-planning
  through the village by hand.
