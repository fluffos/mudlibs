# MiniMud (amylaarmini) -- porting notes

Source: `ftp.lysator.liu.se/pub/lpmud/mudlibs/Amylaar/minilib`,
recovered directly from the still-live Lysator FTP mirror. Slug
`amylaarmini`, number 962, port 40264. 19 raw files, mudlib root at
the archive's own top level (`access.allow`, `cmds/`, `etc/`,
`include/`, `log/`, `obj/`, `room/`, `secure/`). No `driver_hook`/
`set_driver_hook`/`H_[A-Z_]+` usage anywhere. Fourth and last of a
batch of four small historical libraries onboarded this session
(after `basis`, `lpmud245`, `lplib8`), and by far the thinnest --
essentially a driver-feature demo/skeleton rather than a game.

## 1. Extraction and conversion

Pure ASCII/English archive, 0 lossy conversions. `scripts/
convert_lib.sh` renamed the `.c` sources to `.lpc` and fixed literal
`.c"` references; 15 files converted (`secure/master_skeleton.c` and
the `log/`-tree leftovers from the archive's own prior use are the
non-source files). Diffed the converted `secure/master.lpc` and
`obj/object.lpc` against the raw archive bytes directly to confirm
the ONLY changes were the mechanical rename plus this project's
formatter -- nearly all of this archive's own master/simul_efun logic
needed zero hand intervention (it already defines
`get_root_uid()`/`get_bb_uid()`/`define_include_dirs()`/
`get_simul_efun()` on its own, unlike the sibling `lpmud245`/`basis`
archives this session).

## 2. Proactive on-sight checklist findings

No `status`-as-type usage, no `new`/`class` reserved-word collisions.
`config.fluffos` written fresh (port 40264, `include directories :
/include`, `global include file : <config.h>`, `lazy resets : 1`,
standard MudOS-v22 defaults matching the sibling libs this session).

## 3. Compile-time / boot-time driver-compat fixes

- **`get_dir()` flag-value convention gap (new finding for this
  session, not previously catalogued for this driver)**: the classic
  Amylaar-era driver this archive targets used flag `2` for the
  detailed `({filename, size, mtime})` array form; this driver uses
  `-1` for that form (any other nonzero value returns a plain array
  of filename strings only). `secure/simul_efun.lpc`'s `log_file()`
  called `get_dir(file_name, 2)` and then indexed `st[0] > MAX_LOG_SIZE`
  expecting `st[0]` to be the file's byte size -- on this driver
  `st[0]` was instead the filename STRING, crashing the comparison
  ("Bad argument 2 to >, Expected: string Got: 50000") the very first
  time any log file was ever written (i.e. the very first `eval`,
  `runtime_error`, or `crash` call). Fixed: flag changed to `-1`,
  index changed to `st[0][1]` (the size field of the per-file detail
  array), and the `int *st;` declaration widened to `mixed *st;`
  since the return shape is now `({string, int, int}) *` per entry,
  not a flat `int *`.
- **`set_this_object()` is not a real efun on this driver**: the same
  `log_file()` called `set_this_object(previous_object())` immediately
  before `write_file()`, presumably so the write would be attributed
  to the ORIGINAL calling object's identity rather than the simul_efun
  itself, for permission-checking purposes. This driver has no such
  efun at all. Confirmed harmless to simply drop: this archive's own
  `valid_write()`/`valid_read()` (`secure/master.lpc`) are declared
  with ZERO parameters and unconditionally `return 1;` -- a fully
  permissive single-user-testbed security model where caller identity
  never mattered to begin with. (Contrast with the much more severe
  `lplib8` finding this same session, where the equivalent security
  functions actually DID depend on caller identity and silently broke
  save/restore for every player -- not the case here.)
- **`move_object()` 2-arg vs. 1-arg** (already-catalogued AGENTS.md
  §6.2 gap): `obj/object.lpc`'s `move()` called the classic
  `move_object(this_object(), dest)`; the first argument was always
  `this_object()` in context, so rewritten to `efun::move_object(dest)`.
- **`cat()`/`log_file()` never real efuns on this driver**
  (already-catalogued AGENTS.md §6.2 gaps): both reimplemented as
  simul_efuns in `secure/simul_efun.lpc`. `cat()` here is the simple
  `write(read_file(file))` form -- no 3-argument pagination variant is
  ever called anywhere in this archive, so the fuller reimplementation
  used for `basis`/`lpmud245`/`lplib8` wasn't needed.

`scripts/lpcc_check.sh` batch compile: 14/15 PASS. The one failure,
`secure/master_skeleton.lpc`, is a documentation/reference file, not
real mudlib code -- confirmed via its own header comment ("skeleton"),
duplicate function declarations with mismatched arity (e.g. two
different `reset()` signatures, one marked `// !native` and one
`// native`), and zero load-time references anywhere else in the
archive (never `inherit`ed, never `clone_object()`d, never
`call_other()`'d). Same known-acceptable-false-positive class as
`lpmud245`'s `def_castle.lpc` template file (see that lib's NOTES.md).

## 4. Live-boot / functional verification

Booted clean, zero debug.log errors, verified via full live
playthrough (native driver + a separate WASM boot check via
`scripts/wasm_client.js`):

- Registration: type any name, no password prompt at all, straight
  into `/room/start` ("The startroom" / "You are in the startroom of
  Minimud.").
- `look`, `say <text>`, `who` (lists connected names by their
  capitalized login name) -- all confirmed working, both natively and
  under WASM.
- `ls` -- lists the mudlib's own top-level directory tree (this
  archive has no per-player working directory concept).
- `eval <expr>` -- confirmed working for both a bare-`return`
  expression (no visible output, since the archive's own
  implementation never `write()`s the return value -- expected
  behavior, not a bug) and an explicit `write(...)` expression.
- `rehash` -- confirmed working ("Ok").
- `update <path>` -- confirmed working for a non-resident path
  ("No such object" for `/cmds/who`, since transient command objects
  aren't kept loaded). Tested against the player's own current room
  (`/room/start`) as the classic "update the room you're standing in"
  wizard footgun; this update implementation does nothing to guard
  against it (no content/player relocation before `destruct()`). An
  initial test run's ambiguous outcome (driver appeared to vanish with
  zero debug.log trace) was root-caused via a clean relaunch-and-retest
  to be this session's recurring concurrent-`holymission`-driver
  collision artifact (see AGENTS.md's stall-recovery notes), NOT a
  genuine amylaarmini crash -- a full clean relaunch afterward
  confirmed the driver stays alive and error-free across repeated
  boots and command sequences. Even if updating one's own occupied
  room DID crash a from-scratch implementation, that would be the
  well-known, expected classic-MudOS wizard footgun (content/design),
  not a driver-compat bug in scope for this project to fix.
- `quit` -- not implemented at all in this archive (falls through to
  the default fail message, `What?`); confirmed under WASM. Not a bug,
  simply an unimplemented command in this minimal 19-file skeleton.

## 5. A confirmed-dead, not-a-bug oddity worth recording

`secure/master.lpc` defines its own `process_input(string str)`
(which shells out every line of input to a throwaway `/etc/fil.lpc`
run as raw LPC, discarding normal command parsing entirely) and a
second, redundant `logon()` right below `get_simul_efun()`. Grepping
FluffOS's own driver source (`packages/core/interactive.cc`) confirms
`process_input()` is only ever invoked on the INTERACTIVE object
itself, never on the master object -- this is a classic-driver
global-input-filter convention that simply doesn't exist on this
driver. Confirmed neither `obj/player/player.lpc` nor `obj/living.lpc`
defines its own `process_input()`, so this vestigial master-level
function is entirely inert: every live test of ordinary commands
(`look`/`say`/`who`/etc.) went through normal `add_action()` dispatch
exactly as expected, with zero interference from the dead code. Left
as-is (matches the project's "content/design, not a bug" scope
boundary for inert legacy code with no behavioral effect either way).

## 6. Formatting

`find libs/amylaarmini/work -name '*.lpc' | node .../format-corpus.mjs`:
16 files reformatted (the `log/tmpfile.lpc` runtime artifact generated
by `eval` during testing was deleted before the final commit, along
with the other `log/{compile,compile.err,runtime.err}` scratch files
`eval`/the compiler wrote during testing -- none of these are source).
0 errors. All three documented formatter blind spots checked and
clean: no `::`-split hits, no case-label-comment-merge diffs to
review (file is new/untracked, nothing to diff against), no CJK
respacing hits (moot -- pure-English archive). Re-ran the full
`lpcc_check.sh` compile sweep (still 14/15, same single expected
`master_skeleton.lpc` failure) and a fresh native + WASM boot after
formatting -- both clean, all commands re-verified working.
