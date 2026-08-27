# nightmare3 (git clone of `fluffos/nightmare3`)

- Source: `git clone https://github.com/fluffos/nightmare3` (not a
  traditional archive file — a maintained fork already adapted for
  FluffOS v2019, per its own README "Nightmare 3 on fluffos v2019").
  Mudlib root is the repo's `lib/` directory; the repo also bundles a
  `driver` git submodule (a FluffOS checkout) which was ignored — this
  project uses its own driver at `~/src/fluffos`.
- Port: **40208**. Slug: `nightmare3`. Number: `160`.
- Nightmare is one of the oldest, most historically influential LPMud
  mudlib families (an ancestor of the TMI-2 lineage). This lib is
  English-language content, unlike the rest of this "Chinese MUD
  Museum" collection — included deliberately for its historical
  significance.

## Status: DONE — boots clean, fully playable over telnet

Full registration flow (name → confirm → password → confirm → gender →
display name → email → real name → news → race selection room → `pick
<race>` → world entry) confirmed working end-to-end with a real test
account, followed by working `look`, `score`, and `quit` in the actual
starting room (Monument Square, Praxis domain). A seeded admin account
was also verified: creator status (`creatorp()`), full "SECURE"/"ASSIST"
group membership (`archp()`), and the `eval` wizard command all work.

## What was fixed

Since the source is already git-hosted and FluffOS-adapted (not a raw
GBK-encoded legacy archive), most of the usual AGENTS.md §4 encoding/
`.c`-rename pipeline was much lighter than a from-scratch conversion:

1. **Encoding**: none needed — every file was already clean UTF-8/ASCII
   (verified via a whole-tree Python UTF-8-decode scan). No GB18030/BIG5
   content anywhere (expected: this is English content).
2. **`.c` → `.lpc` rename**: 822 files renamed (this project's
   convention; the upstream repo itself still ships `.c`). 135 literal
   `.c"` string references auto-fixed by the same sed pass
   `convert_lib.sh` uses. Zero `#include <...c>` angle-bracket refs
   needed fixing.
3. **`static` → `nosave` (§4.3)**: only ONE file in the whole tree still
   used the bare keyword on functions (`std/door.c`'s `open()` was
   already `nosave private object …` elsewhere — the *rest* of the
   codebase had clearly already been adapted for a "sensible modifiers"
   driver upstream, just missed this one file). Fixed the 8 occurrences.
4. **Reserved-word collisions** (a variant of §4.3's `static`/`nosave`
   class, not previously cataloged for these two specific words):
   - **`ref`** is a reserved keyword on this driver (call-by-reference
     parameter modifier, `L_REF`) that Nightmare's own reference/bookmark
     subsystem (`/daemon/refs.lpc`, `/secure/daemon/master.h`) used
     as an ordinary variable/parameter name throughout. Renamed to
     `refnom`/`refmap` at the ~7 real code sites (most of the 60-odd
     textual `\bref\b` hits elsewhere were plain-English comments or
     mapping-key string literals, not identifiers — false positives).
   - **`class`** is likewise reserved (FluffOS struct/class feature,
     `L_CLASS`). `domains/Praxis/setter.lpc` (the race-picking starting
     room) already renames its local `class` variable to `Class` in the
     "current" copy — but its `standardOld/` backup sibling still used
     the reserved word. Ported the same rename.
5. **Old-style two-argument closure literals** (`(: obj_var,
   "funcname" :)`) — a MudOS/old-FluffOS idiom for "bind a function
   pointer to a specific object+name pair" that this driver's grammar
   rejects outright when the first element is a bare local/global
   variable (`error: Can't give parameters to functional.`; passes
   when the first element is itself a call like `this_object()`, which
   is why most of the ~45 files using this idiom in shipped example
   content compiled fine once the *next* issue below was fixed).
   Rewrote the two real call sites that used a bound variable
   (`secure/include/old_weapon.h`'s `set_hit_func`/`set_wield_func`,
   and `domains/Praxis/obj/weapon/orc_slayer.lpc`) as
   `(: gob->weapon_hit($1) :)` / `(: gob->extra_wield() :)`-style
   anonymous closures (matching each function's actual call-site arity,
   confirmed by reading the `(*f)(...)` invocation sites in
   `std/weapon.lpc`). One additional occurrence in `daemon/refs.lpc`
   (`return (: gtmp1, gtmp2 :);`, a runtime string→closure deserializer
   for a wizard debugging tool) turned out to be pre-existing dead code
   even before the driver-compat problem — the guarding `if` condition
   checks the wrong pair of variables (`tmp1`/`tmp2`, never both
   simultaneously true given an earlier unconditional early-return) —
   left it as documented dead code rather than inventing a
   symbol_function()-equivalent this driver doesn't have.
6. **`Room::set_long()` narrowed to `string`, breaking functional
   longs** — `std/Object.lpc`'s base `set_long(mixed val)` already fully
   supports a function-pointer long (checks `functionp()`/`stringp()`
   and calls it lazily in `query_long()`), but `std/room.lpc` overrode
   it with `void set_long(string str)`, silently disallowing the
   feature for every Room subclass. 17 files across the shipped
   `domains/Praxis`/`domains/Examples` example content (plus
   `std/test.lpc`) pass a closure to a room's `set_long()` and failed
   to compile as a result. Widened `Room::set_long()` back to
   `mixed val` (forwarding to `container::set_long(val)`, i.e. the same
   already-supported base behavior) rather than touching 17 content
   files individually.
7. **`status` is not a real type on this driver** (an old MudOS
   `int`-alias keyword). Fixed 2 variable declarations
   (`std/monster.lpc`'s `heart_beat_on` flag) and 3 function
   return-type declarations (`cmds/creator/_wcheck.lpc`,
   `_roomcheck.lpc`, `_acheck.lpc` — all three wizard-diagnostic
   commands returning a plain boolean `int`) by replacing `status` with
   `int`.
8. **Two content typos, mechanically confirmed against a correctly-
   spelled sibling instance in the same file**: `std/armour.lpc` had
   `armour_ private ["wear"/"unwear"/"lit"]` (3 sites) where every other
   line in the same file correctly says `armour_static[...]` — looks
   like a stray editor "whole-word" find/replace of `static` once broke
   this specific identifier (treating `_` as a word boundary, unlike
   real regex `\b`). `std/obj/RoomCreator.lpc` had `proteceted void
   primary_prompt();` (should be `protected`).
9. **`inherit` after global variable declarations (§6.1)**: 4 files
   (`std/obj/ears_orb.lpc` and `domains/Praxis/obj/misc/{stone,
   stone_pile,gallows}.lpc`) declared `object`/`void` globals and
   function prototypes textually before their `inherit OBJECT;` line.
   Reordered (inherit first) in all 4.
10. **`domains/Praxis/attic/class_change.lpc`**: the entire file's first
    line was mechanically corrupted — `inherit`, two `#define`s, and the
    start of `create()` all squashed onto one physical line with no
    newlines (`#define` must start its own line for this driver's
    preprocessor), plus a stray `, x)` argument on an otherwise-standard
    `seteuid(getuid(this_object()));` idiom (confirmed against several
    identical call sites elsewhere in the codebase). Restored the
    obvious line breaks and dropped the spurious argument — purely
    mechanical, no new content invented. (This file — in an "attic",
    i.e. this mudlib's own graveyard for deprecated rooms — still fails
    to *load* at runtime because it references a since-deleted
    `/obj/mon/wizard`; left as a documented, non-reachable content gap,
    see below.)
11. **`domains/Praxis/standardOld/*` lineage-porting (§2.1 pattern,
    applied within a single lib rather than across sibling libs)**:
    `domains/Praxis/standardOld/` is a full early-snapshot backup copy
    of most of the main `domains/Praxis/` room tree, evidently kept
    around by the original Nightmare maintainers and never deleted. In
    several cases the "current" file had already been fixed by the
    original authors for issues the `standardOld/` backup still has:
    - `set_pre_exit_functions(...)` (an apparently-never-implemented
      API — no such function exists anywhere in the codebase) is
      commented out in the 6 current `hall*.lpc`/`supply2.lpc` files but
      still active, uncommented, in their `standardOld/` counterparts.
      Commented out the same way.
    - `standardOld/setter.lpc` still used the reserved word `class`
      (see item 4) where the current `setter.lpc` already renamed it to
      `Class`.
12. **`secure/cmds/ambassador/_ss.lpc`** inherited a stale path,
    `/adm/daemon/refs_d` (this codebase's `/adm` directory doesn't
    exist at all — an artifact of Nightmare's `/adm` → root-level
    reorganization at some point in its history). The sibling
    `secure/cmds/creator/_call.lpc` already inherits the correct
    current path, `/daemon/refs`. Fixed to match.
13. **`daemon/command.lpc`'s command-dispatch directory scanner — the
    single highest-impact fix, found via live playtesting, not the
    compile sweep.** `rehash()` lists every `_*.lpc` file under each
    command directory and strips the verb name out of the filename with
    fixed-offset string slicing: `choses[j][1..strlen(choses[j])-3]`.
    That offset is exactly right for the *original* `.c` extension
    (`_look.c` → slice `[1..4]` = `look`) but silently wrong after this
    project's standard `.c`→`.lpc` rename (`_look.lpc` → the same
    `[1..(len-3)]` slice yields `look.l`, not `look`) — `.lpc` is two
    characters longer than `.c` and nothing else in the conversion
    pipeline touches string-length arithmetic like this. The practical
    effect: **every command in `/cmds/mortal`, `/cmds/creator`, and
    every other directory scanned this way was silently unregistered.**
    `look`, `score`, `inventory`, and virtually every other normal
    player command fell through to the SOUL_D emote-verb fallback and
    then to the driver's bare "What?" — the game *booted* clean and
    *registration* worked end-to-end, but was otherwise almost entirely
    unplayable. Fixed the slice offset from `-3` to `-5`. Confirmed:
    `cmds/adm/_commands.lpc` (a *different*, unrelated admin utility
    that does the same kind of filename parsing) had *already* been
    adapted to use `sscanf(files[j],"%s.lpc",commandname)` instead of
    hardcoded-length slicing — strong evidence this is specifically a
    gap the upstream FluffOS-adaptation effort missed in one file, not
    an intentional design choice. Swept the whole tree for the same
    `get_dir(...+"_*.lpc")` + fixed-offset-slice idiom; this was the
    only occurrence.
14. **Missing runtime directories** — several `log_file()`/file-access
    target directories referenced by working code simply don't exist in
    the git repo (git doesn't track empty directories, and only a
    couple of the needed ones shipped with a `.gitignore` placeholder).
    Symptom: a raw driver error ("Wrong permissions for opening file …
    for append", "No such file or directory") leaking straight to the
    player's screen instead of the intended clean behavior — e.g. every
    *failed* login password attempt tried to log to
    `/log/watch/logon` and crashed instead. Created: `log/watch`,
    `log/adm`, `log/open` (the fallback log path for any unprivileged
    object — hit by ordinary NPC `death_func()`/stats logging, found
    via the seeded admin's `eval` catching the real error text),
    `log/harass`, `log/personal`, `log/reports`, `secure/tmp` (needed
    for the wizard `eval` command's scratch file — every admin account
    without a real "home directory" hits this), `tmp` (mudlib-root, used
    by the editor/bug-report/board systems), `secure/save/letters`,
    `secure/save/votes`, `secure/save/boards`, `secure/save/daemons`,
    `daemon/save/accounts`. This class of bug is easy to miss purely
    from a compile sweep or even a clean boot — it only surfaces when a
    specific code path actually runs (a failed login, an NPC death, a
    wizard command) — worth flagging for future git-hosted-source
    onboardings in this project generally.

## Known remaining issues (documented, not fixed)

- **14 of 822 files** (1.7%) still fail the `lpcc_check.sh` batch
  compile sweep, all deep in the shipped `domains/Praxis` example
  content and none of them preloaded or reachable from the normal game
  world:
  - 12 are in `domains/Praxis/standardOld/` — the early-snapshot backup
    copy described above. Not all of its divergences from the "current"
    tree were chased down (only the two known-fixed-upstream patterns
    in item 11 were ported); the rest (`roots`, `rogue_hall`, `sheriff`,
    `crypt`, `app_room`, `storage`, `pit`, `supply2`, `fighter_hall`,
    `monk_hall`, `square`, `spider_pit`) have their own independent,
    untriaged compile errors. Since `standardOld/` is dead weight (not
    inherited or referenced by anything else, not preloaded, and
    superseded by the "current" copy of the same rooms), this was not
    worth further chasing.
  - `domains/Praxis/cemetary/mon/ghosta.lpc` and
    `domains/Praxis/attic/class_change.lpc` both compile clean but fail
    to *load* — both throw at runtime from `create()`, most likely
    (confirmed for `class_change`) a reference to game content that no
    longer exists in this snapshot (`/obj/mon/wizard`, deleted at some
    point in Nightmare's own history but never cleaned out of this one
    attic room). Left as-is per this project's scope discipline —
    fabricating replacement monster content would be a content/design
    change, not a driver-compat fix.
- The seeded admin account (`fluffos`) was granted creator+SECURE/ASSIST
  privilege by hand-editing its save file's `position` field and adding
  it to `secure/cfg/groups.cfg` (mirroring exactly what the in-game
  `_sponsor` wizard command does) rather than via any in-game "first
  admin" bootstrap flow — Nightmare doesn't ship one out of the box
  (the pre-existing `secure/save/users/d/descartes.o` in the upstream
  repo is presumably the original author's seed account, but its
  password is unknown/unusable here).
- **WASM status update (2026-08-25, another session)**: promoted to
  `playable`. Unlike several sibling libs onboarded the same day
  (`ds386`, `discworld`), this codebase's simul_efun/master chain has
  no unconditional `socket_status()`/`compress_file()`-style calls, so
  it booted clean under WASM with zero fixes needed — the only
  sockets-related error is `daemon/intermud.lpc`'s own deliberate
  `#error` guard (refuses to load without the sockets package, working
  as designed, not a bug). Verified with a real scripted WASM session:
  login (`fluffos`/`Mud2026Wiz`), `look` and `score` both producing
  correct output matching the native-tested room/character-sheet text.
  `quit` wasn't distinctly captured in the WASM transcript (no visible
  disconnect text before the client's idle window elapsed) but is
  already verified clean under native testing above and untouched by
  anything WASM-specific.

## How to run

```
cd libs/nightmare3
~/src/fluffos/build-debug/src/driver config.fluffos
```

Game port: **40208** (telnet). New-player registration flow: name →
"Do you really wish `<name>` to be your name? (y/n)" → password (≥5
chars) → confirm password → gender (`male`/`female`) → display name
(blank = default) → email (`user@host` form, required) → real name
(optional, blank OK) → two news screens (blank/return to continue) →
lands in a race-selection limbo room; `read list` shows valid races,
`pick <race>` (e.g. `pick human`) finishes character creation and
drops the new player into Praxis's Monument Square starting room.

## Deep functional test, round two (2026-08-27, AGENTS.md §10.7)

One continuous session against `~/src/fluffos/build-debug/src/driver`, a
raw Python socket bridge (a small FIFO-fed persistent-connection script,
not `tmux_mud.sh`), plus a separate admin (`fluffos`/`Mud2026Wiz`)
connection for `eval`-based root-causing. This lib had never had a
round-two pass despite `nightmare4` and `residuum` (same family) both
already being done — per the task brief, checked `nightmare4`'s own
round-two write-up for the exact bug shapes to look for here first.
Registered a real character (`Brandmoor`, human) through the full
name→password→gender→email→race-pick flow described above, then walked
`look`/`score`/`i` after every state change: after registration, after
the first move (`go south`), after joining the fighter class (`become
fighter` at `fighter_join`), after real combat, after death/respawn,
and after a real quit+reconnect (30s real wall-clock gap).

**Four real bugs found and fixed**, all silent — zero compile error,
zero crash, invisible to `lpcc_check.sh` and to a clean boot:

1. **`domains/Praxis/setter.lpc`'s `pick()`** called `this_player()->
   new_body()` *before* `do_rolls()` ever populated the character's real
   `stats` mapping. `new_body()` derives every starting current value
   (`set_hp()`, `set_sp()`, `set_mp()`) from `query_stats()`, which is
   still all-zero at that point (`stats = ([])` from `init_stats()`, no
   roll yet) — while `do_rolls()`'s own `set_stats()` side effect
   *does* separately fix up the MAX fields (`max_hp`/`max_sp`/`magic
   max points`) for each real rolled stat. The result: every fresh
   character's current `sp` got `set_sp(0)` (dexterity was 0 at that
   instant), and the very first `add_sp(-1)` call (fired unconditionally
   by ordinary movement in `std/user.lpc`'s `move_player()`) hit
   `add_sp()`'s own "was this ever initialized?" guard
   (`if(!player_data["general"]["sp"]) set_sp(x)`) — since a legitimately
   zero `sp` reads as falsy, this branch treats the delta `-1` as an
   absolute new value and sets `sp` directly to **-1**, not `max_sp - 1`.
   Reproduced live pre-fix: `Thornwick` (human) showed `25 (160) health
   points, -1 (56) stamina points` after nothing but registering and
   taking a single step — every fresh character starts materially
   broken (both a nonsensical negative "current" stat display and a
   starting HP baseline computed from zero-constitution instead of the
   real rolled value). **Fix**: moved the `new_body()` call to run right
   before the final `move_player(ROOM_START)`, i.e. after `do_rolls()`
   has populated real stats — behavior-preserving (nothing between the
   two calls in `pick()` reads `stats`/hp/sp/mp). Verified live:
   `Brandmoor` (registered post-fix) showed a sane `73 (170) health
   points, 10 (77) stamina points` immediately after character creation,
   and correctly negative `sp` values later during real combat (a
   legitimate fatigue mechanic, `add_sp()`'s own documented floor is
   -200 — confirmed this is intentional design, not something to
   "fix" further, by reading every `add_sp()` call site).

2. **`std/vendor.lpc`'s entire buy/sell/cost/value/show feedback** was
   completely silent — written up as new AGENTS.md **§7.143**. Every one
   of the 28 `this_object()->force_me("speak "+...)` call sites (the
   shopkeeper's own spoken responses — "Buy what?", "you are too poor
   for that!", "I will take N electrum for it.", etc.) produced zero
   output, even though the underlying `cost`/`buy`/`sell`/`value`/`show`
   commands themselves dispatched and worked correctly (money/item
   state changed, `list` printed fine). Root cause: `std/living.lpc`'s
   self-registered `add_action("cmd_hook", "", 1)` (every living's own
   catch-all command dispatcher) only actually attaches when this
   driver's `add_action()` requirement `ob == command_giver` holds at
   registration time — true for an interactive player (registering
   during their own live login), never true for an NPC/vendor `new()`d
   from an ordinary room `reset()` (no live command_giver in scope at
   all). See §7.143 for the full root-cause writeup (including how this
   was distinguished live from a `private`-modifier issue, and why
   `wimpy`'s own `force_me()`-based auto-flee is unaffected — it runs
   from `heart_beat()` on the PLAYER's own already-correctly-registered
   body, a materially different driver code path). **Fix**: added a
   `__Speak(string str)` helper using this codebase's own proven-working
   `tell_room()`-based NPC dialogue idiom (the same shape
   `std/monster.lpc`-descended NPCs like the beggar already use for
   `say_line()`), and replaced every `force_me("speak ...")` call site
   with it (also fixing a pre-existing, now-moot typo: `__Show`'s own
   "no argument" message was missing the `"speak "` prefix even before
   this bug). Verified live: `cost vial` → `"Horace: Brandmoor, I will
   take 1 electrum for it."`; `buy vial` while broke → `"Horace:
   Brandmoor, you are too poor for that!"`; bare `buy` → `"Horace: Buy
   what?"` — all previously silent, all now correct. **Not fixed, only
   flagged** (§7.143's own writeup): `std/living/combat.lpc`'s
   `execute_attack()` (`this_object()->force_me(this_spell)`, a
   spellcasting creature's own random-spell trigger) and
   `std/realtor.lpc`/`std/monster.lpc`'s multi-lingual
   `force_me("speak in ...")` share the identical shape and are equally
   suspect, but no spellcasting monster was actually engaged live this
   session to confirm the symptom before touching that code.

3. **`std/user/autosave.lpc`'s `setup()`** unconditionally `new()`s a
   fresh copy of every `query_auto_load()`-flagged item on every login,
   with no check for whether a matching item is already present — a
   confirmed fourth instance of the already-documented **§7.122** "class
   object auto-reload duplicates a carried marker item" bug class,
   this time in the genuine Nightmare codebase rather than a TMI-2
   descendant (distinct function names, `pre_save()`/`__AutoLoad`
   instead of `compute_autoload_array()`/`auto_load`, but the identical
   save-before-strip ordering: `quit()`/`net_dead()` both reach
   `save_player()` → `pre_save()` — which snapshots carried auto-load
   items into `__AutoLoad` while leaving them physically in inventory,
   so `save_object()` bakes them in redundantly — *before* `quit()`'s
   later `remove()` → `autosave::remove()` ever strips them back out,
   and `net_dead()` never calls that stripping step at all). Real,
   currently-playable content is affected: `std/guild.lpc`'s
   guild-membership marker (used by all three of this lib's real
   guilds — druids/philosophers/witches, per `doc/help/user/guilds`),
   `std/obj/wed_ring.lpc`, `domains/Praxis/obj/misc/handcuffs.lpc`,
   `std/germ.lpc` (disease markers). See §7.122's own updated entry for
   the full write-up. **Fix**: identical idempotency-guard pattern to
   the three prior instances — `setup()` now snapshots
   `all_inventory(this_object())` into a `base_name()`-mapped list once
   before its reload loop, skipping any `__AutoLoad` entry whose file
   already matches something already carried. Verified live via direct
   `eval` (clone a `/std/obj/wed_ring` onto the admin test account,
   `pre_save()` then `setup()` three times in a row) — held steady at
   exactly 1 ring throughout, confirming the guard works; the
   underlying unconditional-clone shape was independently confirmed by
   reading the pre-fix code (no `member_array`/presence check existed
   at all). Flagged for a follow-up sibling check: `nightmare4`/
   `residuum` (this lib's own direct siblings) and the Dead-Souls-3.x
   lineage (built on old Nightmare-IV code) next.

4. **Missing runtime directory `daemon/save/votes/`** — `daemon/
   voting.lpc`'s `create()` does `restore_object(VOTE_SAVE)` (`"/daemon/
   save/votes/daemon"`) unconditionally; the directory didn't exist at
   all (a *different* path from `secure/save/votes/`, which this lib's
   own onboarding-time NOTES.md item 14 already created — this is a
   second, previously-missed instance of the exact same "missing
   runtime directory" class documented there). Since `VOTING_D` is
   lazily loaded on first reference, and `domains/Praxis/{fighter,
   cleric,mage,rogue,kataan,monk}_hall.lpc` **all six** class halls'
   shared `receive_objects()` call `VOTING_D->is_time_to_vote()`
   unconditionally on every object moved into them, the very first
   attempt by anyone to walk into ANY class hall crashed with
   `*restore_object: read permission denied: /daemon/save/votes/
   daemon.o.` uncaught inside `create()` — aborting the whole `move()`
   and leaving the player stuck outside with "You remain where you
   are." **Every single class hall in the game — the core "learn
   skills/train/advance" location for every one of the 5 playable
   classes plus the kataan variant — was completely unreachable** until
   this was fixed. **Fix**: created the missing directory (`mkdir -p
   daemon/save/votes`). Verified live: `go up` from `fighter_join` now
   reaches "Welcome to the inner sanctum of the Hall of Fighters!"
   cleanly. **Known remaining cosmetic wrinkle, not fixed**: since
   `daemon/save/votes/daemon.o` itself only gets created once a real
   election is ever held (`save_object()` is never called from
   `create()`, only from the actual voting functions), the *very first*
   `VOTING_D` touch after any fresh boot still prints the same raw
   `*restore_object: read permission denied` line to whichever player's
   login happens to trigger it (harmless — caught, non-blocking, and
   does not recur for the rest of that boot) — a `try`/`catch` around
   that one `restore_object()` call in `create()` would be the fully
   clean fix, but wasn't made since the actual functional blocker (six
   unreachable class halls) is already resolved and this residual is
   cosmetic-only. **Also worth flagging generally**: neither this
   directory nor any of the ones created at onboarding time (item 14 —
   `secure/save/votes`, `log/watch`, `secure/tmp`, etc.) are tracked in
   git at all (`git ls-files` returns nothing for any of them, confirmed
   for several) — git cannot track an empty directory, and none of them
   ever had a placeholder file committed. This means a truly fresh
   `git clone` of this repo would silently lose ALL of onboarding's
   item-14 directory fixes and reintroduce those exact crashes, not
   just this session's `daemon/save/votes` — worth a dedicated pass
   (add a tracked placeholder file to each) if this lib is ever
   re-cloned/re-deployed from git rather than tested in-place.

**All standing cross-cutting bug patterns checked explicitly, systematic
grep sweep against every §-numbered pattern from AGENTS.md's own
standing list**: §7.118 (the filename-slice class) was already this
lib's dominant onboarding-time bug (item 13 above) and was re-verified
clean by the fact that every ordinary command (`look`/`score`/`i`/
`go`/`become`/`kill`/`pray`/`wimpy`/`quit`) worked correctly all session;
§8.3a (`private nomask command_hook`) checked and confirmed NOT the
shape present here — `cmd_hook` dispatch works correctly for real
players (exhaustively proven live while chasing the §7.143 bug above);
§7.112 (unconditional `init()` call_out chain, no re-entry guard) —
`std/monster.lpc`'s `create()`/`init()` schedule no `call_out()` at all,
not applicable; §7.121 (float arithmetic in a declared-`int`
function/param) — no matches on a targeted `= 0\.[0-9]` grep against
`int`-declared fields; §7.124 (Wimpy fraction-vs-percentage) — checked
`std/living/combat.lpc`'s own `wimpy` mechanism directly (this lineage
generation implements it completely differently from `nightmare4`'s
buggy version: a plain `int wimpy` field, `set_wimpy(23)` on `wimpy on`,
a clean `(hp*100)/max_hp < wimpy` percentage comparison) — confirmed
clean, no fraction-literal bug present; §7.122 — found and fixed, see
finding 3 above; §7.123 (bare file-scope mapping/array assignment) — one
grep hit (`secure/cmds/mortal/_tell.lpc`'s `__Morse = ([...])`),
hand-verified as a local variable inside `morse()`, not file scope, same
false-positive shape already documented for `nightmare4`; §7.126 (stale
`.c` extension surviving in `.o` save data) — corpus-wide grep for
`\.c"` inside `.o` files found zero hits; §7.129 (a `tell_room()`
wrapper forwarding an omitted arg as `0`) — no custom `tell_room()`
wrapper exists at all, every caller uses the driver efun directly, not
applicable; §7.130 (`query_idle()` called after non-interactive already
detected) — `std/user.lpc`'s `heart_beat()` already returns immediately
on `!interactive(this_object())` before its own `query_idle()` call
later in the same function, confirmed correctly guarded; §7.131
(`find_living()`/`find_player()` needing `set_living_name()`) — called
correctly in both `std/user.lpc` and `std/monster.lpc`; §7.132 (`map()`
over a mapping bound to the wrong arg) — every `map()` call in the
codebase operates on an array (`users()`, `keys(...)`), never a bare
mapping, not applicable; §7.133 (`net_dead()` never defined) — defined
correctly in `std/user.lpc`; §7.134 (uninitialized `room_descs`-style
accumulator crashing `member_array(0, X)`) — zero `member_array(0,`
call sites anywhere; §7.135/§7.30 (a lazy-init accessor missing its
sibling's guard) — this lib's starting-location machinery is
architecturally different (no `def_locations`/`temp_locations`-style
mechanism at all) and the `quit` path was independently verified live
(clean, no crash, correct save/restore) so no live instance of this
shape was found; §7.136 (a required setup step silently never granted)
— `become fighter` correctly re-granted the full class skill table live
(verified via `skills` before/after); §7.141 (MudOS-era `replace_program`
timing crash) — zero `replace_program()` calls anywhere in this
codebase, not applicable.

**Combat/economy/death coverage**: engaged `domains/Praxis/obj/mon/
beggar.lpc` (level 4, the same weak non-aggressive NPC nightmare4's own
round-two pass used) for a live fight — turned out to be a genuinely
hard, nearly-unwinnable matchup for a fresh level-1 character (every
attack landed "ineffectively", HP dropped steadily from 73 to death with
no real damage dealt back) rather than the "safe sparring" it appeared
to be; this is a content/difficulty-balance observation, not something
fixed, per this project's scope discipline (no error signature, just an
unfavorable but internally-consistent combat roll). The resulting death
→ `pray` at the Praxis monastery → full revival cycle was exercised for
real and confirmed clean (correct HP/SP/MP reset, empty inventory
preserved, no duplicate corpses or repeat death loop). Shop economy
(`cost`/`buy`/`value` at Horace's supply shop) tested live and is where
finding 2 above was found and fixed. A genuine `quit` → `debug.log`/
`log/catch` grep (clean, no new uncaught errors beyond the
already-documented, non-blocking `daemon/voting` cosmetic message and a
pre-existing, gracefully-caught beggar-wandering-into-a-nonexistent-room
content gap, `/domains/Under/entry`, left untouched as out-of-scope
content) → a real 30-second wall-clock gap → reconnect cycle confirmed
full state persistence (hp/sp/mp, class title, skill table all matched
exactly pre-quit, landing back at the fighter's `setenv("start", ...)`
location rather than the exact last room — expected, intentional
class-hall-restart design, not a bug).

Sanity-checked the port-uniqueness invariant
(`grep -h '"port"' libs/*/meta.json | grep -oE '[0-9]{5}' | sort -n |
uniq -c | awk '$1>1'`) printed nothing before committing. Test character
`Brandmoor` and the admin's own throwaway test items were cleaned up
before committing, keeping only the pre-existing seeded `fluffos` admin
account.
