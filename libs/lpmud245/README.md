# LPmud 2.4.5 (lpmud245)

A pristine, pre-LDMud **LPMud 2.4.5** snapshot -- the mudlib distributed
with Lars Pensjö's own original LPMud driver line, from the era right
before the LDMud/MudOS fork. Genuinely FluffOS/MudOS-compatible: a full
`driver_hook`/`H_[A-Z_]+`/`set_driver_hook` grep across the whole
archive found zero hits (unlike, say, the Docker Hub `ldmuddev/lp245`
image, which is an LDMud-ported build of the same nominal version).
`obj/master.lpc`'s own header comment dates it precisely: "This is the
LPmud master object, used from version 3.0... designed to be used with
mudlib 2.4.6 or earlier."

This is a real, playable small world -- 286 files, hundreds of real
rooms (a village with a church, green, market road, forest, mine,
sewers, a maze, a "south" continent, wizard-only areas), NPCs
(orcs, wolves, a dragon, guards), a level/experience system, and the
classic LPMud spell/combat mechanics -- not a thin infrastructure
sketch like the already-onboarded `basis`.

## Provenance

Recovered directly from the still-live `ftp.lysator.liu.se` LPMud
archive mirror
(`https://ftp.lysator.liu.se/pub/lpmud/mudlibs/other/2.4.5.tar.gz`),
same as `basis` -- no Wayback Machine recovery was actually needed,
the file is still served as-is.

## Highlights (see `NOTES.md` for full detail)

- **A genuine, severe infinite-recursion bug, present in the original
  1990s source itself, exposed by this driver's `file_name()`
  convention**: `room/room.lpc` (the shared room base every room
  `inherit`s) caches a "number word" array (`"one"`, `"two"`, ...) on
  a shared singleton instance at `/room/room`, using
  `file_name(this_object()) == "room/room"` to detect "am I the
  singleton itself?". This driver's `file_name()` always returns a
  LEADING SLASH (`"/room/room"`); the comparison was therefore always
  false, so the singleton's own lookup called itself via
  `call_other("room/room", "query_numbers")` forever. This broke the
  long-form description of **every single room in the game** the
  first time any exit list needed to be spelled out in words ("There
  are three obvious exits: ..."), with the driver's own generic
  `default error message` masking the real "Too deep recursion" error
  from ordinary (non-wizard) players. Fixed by comparing against
  `"/room/room"`.
- **`obj/player.lpc` called `move_player()` -- the function every
  single movement in the game funnels through -- but never defined
  it**, and doesn't inherit anything that does. The genuine
  implementation exists, verbatim-compatible with player.lpc's own
  variable names, in `obj/living.lpc` (an apparent unfinished
  refactor toward a shared living-body base class that never got
  wired up to the actual player object). Copied the function in.
  Without this fix, this driver's "an undefined bare call only
  errors when actually invoked, not at compile time" behavior meant
  the whole compile sweep looked clean, and only a live walk between
  rooms revealed the break.
- Two applies this driver's `PACKAGE_UIDS` build unconditionally
  requires but this pre-uid-era archive never defined at all:
  `get_root_uid()`/`get_bb_uid()` (boot-blocking, `exit(-1)`) and
  `creator_file()` (blocks every single subsequent object load).
  Added flat single-owner stubs (AGENTS.md §7.2).
- This driver defaults to `lazy resets : 0`; this whole archive's
  `reset(arg){if(arg)return;...}` idiom (and this driver's own
  `call_create()` always marking every object "already reset" on
  load, deferring the real first reset for up to 30 minutes) meant
  every room loaded dark/uninitialized until its own random reset
  timer eventually fired. Fixed generally by adding `create() {
  reset(0); }` to all 157 files using this idiom (mechanical, not
  hand-picked) plus turning `lazy resets` on for the runtime-reset
  case (moving into an object whose reset is overdue).
- Old MudOS's classic `command(str, ob)` (run a command as a specific
  object) doesn't exist here -- `command(str)` always runs as
  `current_object`. Fixed the ~10 call sites needing to run a command
  as a DIFFERENT object (an NPC's forced "wield", a wizard's queued
  auto-typer) via a small `do_command()` wrapper defined on the
  target classes, matching this driver's `call_other()`-never-
  falls-back-to-an-efun semantics already established for the
  `move_object()`/`transfer()` dialect gap (AGENTS.md §7.158).
- `add_action("fun"); add_verb("cmd");` (a very old 2-statement
  idiom, 366 call sites) mechanically merged into the modern
  2-argument `add_action("fun", "cmd")` this driver requires.
- Reimplemented five more classic efuns this driver never had:
  `extract()`, `log_file()`, `cat()`, `creator()` (stubbed
  permissively), `previous_file()`.

## Registration flow

Type your name -> (new character) password -> confirm password ->
email address (or `none`) -> gender (`m`/`f`/`o`) -> straight into
`room/church`, the starting room.

## Local play

```
cd libs/lpmud245
~/src/fluffos/build-debug/src/driver config.fluffos
```

Port **40262**.
