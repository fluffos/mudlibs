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
- WASM mode was not evaluated for this pass — this lib was onboarded
  natively only. Left `wasm_status` unset for a future WASM triage pass
  per AGENTS.md §1.4.

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
