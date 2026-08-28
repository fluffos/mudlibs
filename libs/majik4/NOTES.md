# Majik 4 -- porting notes

Source: `git clone https://github.com/tleino/majik4` (commit
`b24efafe0b53c5b3433f421751e29442cee1262b`, cloned 2026-08-28). A real
MudOS v21/v22-era mudlib by Tero "namhas" Leino, the fourth incarnation
of his "Majik" project and the direct successor to
[majik3](../majik3/NOTES.md) (onboarded immediately before this one,
same session). The repo's own `README.1st` confirms the MudOS origin,
candidly says development stopped when the base engine was "almost,
still not even beta" (the designers hadn't finished building content
before the team moved on to the 3D `majik3d` successor), and gives
build instructions that name a **custom native driver package**
(`bin/majik_mapgen.c`/`bin/majik_mapgen_spec.c`) the mudlib depends on
-- see §3 below, the most consequential single finding in this pass.
Mudlib root is the repo's `lib/` directory; `bin/`, `COPYING`, `doc/`,
`README.1st`, `TODO`, and `template/` at the repo top level are not part
of the mudlib and were not converted. 271 raw files, 232 `.c` files.
Slug `majik4`, number 951, port 40253.

Zero `driver_hook`/`set_driver_hook`/`H_[A-Z_]+` hits anywhere in the
tree -- genuinely FluffOS/MudOS-compatible, not LDMud.

## 0. Architecture is very different from majik3

Unlike majik3's room-based text-MUD model, majik4 is a real 2D grid
("roguelike") world with a dedicated graphical client
(`tleino/majik4-client`, `tleino/majik4-client-drac`) communicating over
a custom but plain-text-framed protocol (`include/mcp.h`): every line
is `<command-code>:<datalen>:<data>\n`, and even login itself goes
through this framing (`CMD_LOGIN_NAME`=18, `CMD_LOGIN_PASS`=20, etc. --
`secure/login.lpc`/`secure/player.lpc`'s `process_input()`). This is
genuinely scriptable over a plain TCP socket once the frame format is
understood -- NOT a WASM-terminal-only limitation the way `zjdyzj`'s
protocol handshake is -- confirmed via a raw Python client that logs
in, sends `race human` (`command/mortal/race.lpc`'s special-cased
dispatch, bypassing the normal command queue), and receives back the
character-sheet/map/object frames and a real room description. See §5
for the full verified playthrough and §4 for one non-obvious mechanic
(commands are NOT processed synchronously) that will trip up any future
scripted test against this lib.

## 1. Conversion

Almost entirely English/ASCII, like majik3 and openlib.
`convert_lib.sh` reported `already_utf8=267 converted=0 lossy=4
skipped_binary=0`. All 4 lossy files are `world/bral_gaur/{gwel-nouns,
gwel-verbs,gwel-adjectives,voc-gwelmarun}` -- vocabulary lists for
"Gwel," an invented dwarven conlang used in the Bral Gaur area's names
and lore. Trial-decoded a raw sample with `latin-1` per AGENTS.md §4.1's
guidance (GB18030 dropped the bytes outright rather than mis-decoding
them, since these aren't Chinese-locale bytes at all): confirmed
genuine **Finnish** text (`maaperä` = "soil/ground", `maaperä
(hiekkainen)` = "soil (sandy)") -- unsurprising, the author is Finnish.
Re-decoded these 4 files individually with `latin-1` -> UTF-8 instead of
the corpus default, overwriting the mis-converted copies in `work/`.
Renamed 232 `.c` files to `.lpc`, fixed 69 literal `.c"` references, and
converted 1 local angle-bracket `#include` to quotes. `static`->`nosave`
sweep found zero hits (this codebase already used `nosave`
consistently).

## 2. `master.lpc` checklist (§2.2) -- unlike majik3, no uid applies at all

`secure/master.lpc` had **no** `get_root_uid()`, `get_bb_uid()`, or
`creator_file()` at all (majik3's sibling lib has these on a separate
`secure/secure.lpc`; this archive apparently never got the equivalent
file). With this driver's `PACKAGE_UIDS` build:

- Missing `get_root_uid()` is a hard `exit(-1)` at boot (confirmed via
  `~/src/fluffos/src/vm/internal/master.cc`'s `APPLY_GET_ROOT_UID`
  handling).
- Missing `creator_file()` doesn't crash the boot but throws `No
  function creator_file() defined!` on every single object load,
  visible immediately in `lpcc_check.sh`'s batch output (which cascaded
  further into a SECOND error, `Wrong permissions for opening file
  /log/runtime.log`, since `error_handler()`'s own attempt to log the
  first error also failed -- see §2b).

Fixed with the same flat "everyone is Root" stub already established
for `openlib`/`nightmare3`/`nightmare4`/`residuum`/`majik3` (this
session):

```lpc
string get_root_uid () { return "root"; }
string get_bb_uid () { return "backbone"; }
string creator_file (string file) { return get_root_uid(); }
```

`valid_read()`/`valid_write()` were deliberately left undefined --
checked `~/src/fluffos/src/packages/core/file.cc`'s
`check_valid_path()`: an ABSENT master apply here is treated as
"allow, path unchanged" (only an explicit numeric `0` return denies),
unlike `get_root_uid()` which is unconditionally required. This
mudlib's own access model never touches `getuid()`/`seteuid()`/
`valid_read`/`valid_write` anywhere (corpus-wide grep: zero hits), so
no further ACL work was needed.

### 2b. Archive shipped with no `lib/log/` (or `lib/binaries/`) directory

Unlike majik3's raw archive (which had an empty but present `lib/log/`),
this one had neither -- almost certainly because git doesn't track
empty directories and this particular working copy's `log/` happened to
be empty when it was committed. Every `write_file("/log/...")`/
`log_file(...)` call in `secure/simul_efun.lpc`/`secure/player.lpc`
(including one at the very top of `process_input()` -- i.e. EVERY
single line of client input, not just error paths) throws `Wrong
permissions for opening file ... "No such file or directory"` without
it. Fixed with `mkdir -p work/log work/binaries` before the first boot,
per this project's standing convention for missing-runtime-directory
crashes (AGENTS.md, generic "missing directory swallows errors"
pattern). Both directories are `.gitignore`d corpus-wide
(`libs/*/work/log/`) same as every other lib's -- re-create them again
if this lib is ever rebuilt from `raw/` via `convert_lib.sh` on a fresh
checkout.

## 3. The real blocker: `generate_map()` is a native MudOS C driver package this project's FluffOS build doesn't have (AGENTS.md §7.160)

`secure/player.lpc`'s per-session `setup()` unconditionally routes every
new (or otherwise location-less) character's `start` variable to
`/world/worldmap` as the fallback. `world/worldmap.lpc`'s own
`build_map()` calls `generate_map(options, 100, 100)` -- a function
that does not exist ANYWHERE in this codebase as LPC. Per this
archive's own `README.1st` build instructions (`cp
/majik/server/bin/majik_mapgen.c packages/`) and
`bin/majik_mapgen_spec.c`'s own efun-prototype declaration (`string
*generate_map(string, int, int);`), this was a **native MudOS C driver
package**, written in C specifically for performance (the author's own
`doc/mapgen.txt` walks through the CPU cost of real-time bicubic
terrain-blending interpolation in pure LPC and concludes it's
infeasible at the player counts they wanted). This project's FluffOS
build does not compile in that package and has no equivalent.

Without it, `world/worldmap.lpc` fails to compile at all, and via a
live playthrough: character creation and race selection complete fine,
but the very next `CMD_START` (the client's post-race handshake) throws
`No program in object '/world/worldmap'!` at `secure/player.lpc:393` --
**no character could ever be positioned into the game world at all**,
mortal or admin, the single most severe possible finding for this lib.

Unlike `majik3`'s `add_monster()`/`set_no_weight()` class of gaps
(genuinely unfinished content with no reference implementation anywhere
to restore -- left alone, see that lib's NOTES.md/AGENTS.md §7.159),
this one has a clear reference implementation, just not one this
environment can build (a native C extension is out of scope for a
mudlib onboarding pass -- see also `feedback_fluffos_pr_workflow`-style
driver-level work, a different kind of task entirely). Since the
absence isn't a case of "the author never finished this" but "this
project's driver doesn't build the required native extension," a
**minimal, explicitly-labeled compatibility stub** was justified --
different from leaving `majik3`'s content gaps alone. Added as a
`secure/simul_efun.lpc` simul_efun:

```lpc
varargs string *
generate_map (string options, int w, int h)
{
   // parses the packed "options" string (see world/worldmap.lpc's own
   // builder) just far enough to pick ONE terrain character (highest
   // total corner probability) and fills the whole w*h grid with it.
   ...
}
```

This does **NOT** reimplement the real blended/randomized terrain
algorithm -- that stays out of scope as genuine game-design/content
work, and doing it "for real" would mean writing an entirely new
terrain generator from the design doc, not fixing a bug. It exists
purely so the game is enterable and playable at all. **Real,
documented, permanent consequence**: wilderness tiles beyond the
hand-built named areas (Hilltop Village, Bral Gaur) render as flat,
single-terrain-character grids instead of the original's smoothly
blended landscape. The hand-built areas themselves are unaffected --
confirmed live, walking around Hilltop Village renders its real,
hand-authored room descriptions and NPCs exactly as designed (see §5).

## 4. Severe bug found and fixed: EVERY character got full admin on EVERY login

`secure/player.lpc`'s `setup()` (run once per session, after race
selection) contained an unconditional:

```lpc
security = 100;
```

`include/security.h` defines `SEC6 100` ("greater god" -- the maximum
admin rank in this lib's own rank scheme). This line ran for every
single character, new or returning, mortal or not, on every login --
meaning literally every player who has ever connected to this exact
codebase became a full admin the moment they finished character
creation. This directly contradicts the archive's own `README.1st`,
which documents a deliberate, manual, out-of-band admin-promotion
process (register as an ordinary mortal, log out, hand-edit the save
file to add `security 100`) as the intended mechanism -- a debug/
testing leftover almost certainly never meant to ship, consistent with
the project's own "almost, still not even beta" self-description of
this exact snapshot.

Verified live: a brand-new `mortaltest` character's save file has NO
`security` line at all (int fields default to `0` when never assigned
and not restored) BEFORE the fix would have existed; after the fix, a
fresh `mortaltest` registration correctly stays unset/`0` (mortal)
rather than getting a saved `security 100` line. Fix: only initialize
`security` to `SEC_MORTAL` (0) if it is still its zero default, never
overwriting an already-legitimately-granted higher rank on subsequent
logins:

```lpc
if (!security)
    security = SEC_MORTAL;
```

This is the highest-severity single finding across both `majik3` and
`majik4` this session -- a universal privilege-escalation bug, not a
crash or a missing-content gap -- and is recorded as its own catalog
item, AGENTS.md §7.160.

## 5. Other bugs found and fixed

- **`command/mortal/throw.lpc`**: `if(ob->query_range() & RANG_THROWN))`
  -- one extra closing paren, a hard compile syntax error. Fixed to
  `if(ob->query_range() & RANG_THROWN)`.
- **`world/bral_gaur/genwords.lpc`**: `#define NUM_LETTERS NUM_VOCALS +
  NUM_CONS` referenced an undefined `NUM_VOCALS`, when the very
  preceding line defines `NUM_VOWELS` -- almost certainly the Finnish
  author's own native-language false friend ("vokaali" = vowel; compare
  the real Finnish content in this same lib's `world/bral_gaur/`
  vocabulary files, §1). Fixed to reference `NUM_VOWELS`.

## 6. Confirmed genuinely orphaned/dead code, not fixed

`inherit/elemental.lpc` (undefined `SPELL_EXTRA`) and
`inherit/truename.lpc` (undefined `TRUENAME_D`) are both confirmed
un-inherited anywhere in the live tree (`grep -rl` for their literal
paths comes back empty) -- same shape as `majik3`'s
`inherit/living/living.lpc` orphan pair, an abandoned earlier draft
superseded elsewhere. `doc/example/platemail.lpc`/`helm.lpc` (undefined
`DT_IMPACT`/`DT_STAB`/`DT_CUT` -- simply missing `#include <weapon.h>`)
are dead tutorial content, same class as majik3's own `doc/examples/`
and `openlib`'s doc tree; nothing outside `doc/example/` references
either file. None of these four affect anything reachable in actual
play.

## 7. An observed-but-not-fully-diagnosed runtime error, flagged for a future pass

One `log/runtime.log` entry surfaced during testing that wasn't traced
to a specific root cause: `Bad argument 1 to EFUN call_other() Expected:
object, string, array, Got: int(0). -- /inherit/living.lpc:1042
OBJ(0)` (the `else if(THOB->query_somatic_meaning(verb))` line inside
`force_us()`, §0's command dispatcher). It appeared once across two
back-to-back test sessions run in close succession against the same
driver instance (an admin-seeding run immediately followed by a
mortal-character verification run) and did not visibly interrupt either
session -- both characters entered the game world and rendered correctly
afterward. Plausible candidate: `THOB` (`this_object()`) resolving to a
just-destructed/invalid reference if two connections' `heart_beat()`-
driven command draining (§4 below) overlapped in a way this quick
back-to-back test setup could trigger but a normal single-session
playthrough wouldn't. Not reproduced in isolation with the time
available this pass; noted here rather than chased further, per this
project's standard practice of recording an observed-but-unconfirmed
runtime finding rather than either ignoring it or over-claiming a fix.

## 8. Live playthrough (§10.1 bar, adapted for this lib's real-time/grid design)

Booted `~/src/fluffos/build-debug/src/driver config.fluffos` from
`libs/majik4/` -- `Accepting telnet connections on 0.0.0.0:40253` /
`Initializations complete`, zero fatal errors. Full flow verified with a
raw Python socket client speaking the `<code>:<len>:<data>\n` frame
protocol (see `include/mcp.h` for the code table):

1. `CMD_START` (`1:2:-1` -- the `-1` sentinel deliberately skips this
   lib's own client-version enforcement, `player.lpc`'s own documented
   escape hatch for exactly this kind of non-client testing).
2. `CMD_LOGIN_NAME`/`CMD_LOGIN_PASS` register a new character
   ("brannoc"/"Passw0rd") -- confirmed via `New character.` echoed back.
3. A second `CMD_START` triggers the race-selection dialog (`CMD_DIALOG`
   frame: `Select which race? race human;elf;orc;troll;dwarf;`).
4. `CMD_COMMAND` with `race human` (dispatched specially, bypassing the
   normal command queue -- `secure/player.lpc`'s `process_input()`)
   completes character creation: stat rolls, starting skills
   ("You feel like you just improved your punch/dodge/kick"), and (post
   §3's fix) successful placement into the real hand-built **Hilltop
   Village** -- a proper room description ("You are standing in the
   middle of the Hilltop Village central square...") plus visible NPCs
   (banker, innkeeper, grocer, several torches, a bulletin board) sent
   as real `CMD_ADD_OBJECT`/`CMD_INFO_OBJECT` frames, followed by an
   automatic step into the village inn.
5. `i` (inventory, one of the three commands `process_input()`
   dispatches immediately without the heart_beat queue -- §4) correctly
   reports "You are carrying: 8 gold coins".
6. `quit` triggers this lib's own real confirmation flow -- a warning
   about being killable while disconnected, then `Are you sure (y/N)?`
   -- and `quit y` completes it cleanly: `CMD_SOUND` (logoff sfx),
   `CMD_QUIT` with reason text `Normal exit.`, then the server closes
   the connection. No crash, no error.
7. Re-logged in as the same saved character ("brannoc") to confirm
   persistence (race and location restored correctly).
8. Seeded the standard admin account (`fluffos`/`Mud2026x`, `security
   100` per this archive's own README.1st-documented mechanism,
   confirmed unaffected by the §4 fix since the fix only skips
   re-initializing an ALREADY-set security value).

### Important test-writing gotcha: commands are NOT processed synchronously

`secure/player.lpc`'s `heart_beat()` drains at most ONE queued command
per tick, gated by an accumulating `speed_count` (incremented by a flat
`MAX_SPEED`/`include/living.h` per tick) needing to exceed the
character's own `query_speed()`. With the two exactly equal at a fresh
character's default speed, this is a **minimum of two heartbeat
intervals** (`heartbeat interval msec : 3000` in this config -> 6+
seconds) per command, and back-to-back commands compound linearly. A
naive scripted test sending commands 2-4 seconds apart will see stale
or entirely absent responses that look exactly like a hang or a
silently-dropped command but are neither -- confirmed by simply waiting
longer: a `quit`/`quit y` round-trip that looked stuck at a 15-second
total test budget completed correctly, prompt and all, once the same
test was given ~20 seconds. `i`/`blook`/`vlook` are the three
exceptions, force-executed immediately without the queue -- but `blook`/
`vlook` themselves both require an explicit `<x> <y>` grid-coordinate
argument (a client-side "look at this specific tile" feature, not a
bare "look around" command the way `look` works in a normal text MUD --
this lib simply doesn't have a room-level "look" command at all, since
the room is always visually rendered by the client).

WASM packaging not attempted this pass -- `wasm_status` left empty,
matching `majik3`/`openlib`'s precedent for a lib onboarded outside the
site-wide WASM sweep (and this lib's custom client protocol would need
its own WASM-side client shim regardless, a separate follow-up task).
