# atlantis (archive #64: 消失的亞特蘭提斯MUD破解版.zip)

## Verdict: NOT an LPC mudlib — confirmed DikuMUD/Merc-lineage compiled C server

This archive is **not compatible with the FluffOS/LPC pipeline** used
throughout this project. It is a classic **Merc 2.1/DikuMUD-derivative**
codebase ("消失的亞特蘭提斯" / "The Vanished Atlantis MUD", Traditional
Chinese, cracked/redistributed source release) — a compiled C server with
`.are`-format world files, the same fundamental architecture mismatch
already documented for archive #31 (三国歪传, see `AGENTS.md`'s non-mudlib
list). No conversion, port assignment, or driver boot was attempted, per
that established precedent — doing so would produce a meaningless result
(this driver's LPC compiler has nothing to compile here).

### Evidence

- `libs/atlantis/raw/src/` contains 24 `.c` files with the exact classic
  Merc/DikuMUD file layout: `act_auction.c`, `act_comm.c`, `act_info.c`,
  `act_move.c`, `act_obj.c`, `act_race.c`, `act_wiz.c` (+ a `.save` backup),
  `bit.c`, `build.c`, `comm.c`, `const.c`, `db.c`, `eact.c`, `fight.c`,
  `handler.c`, `hunt.c`, `ident.h`, `interp.c`, `magic.c`, `merc.h`,
  `save.c`, `script.c`, `social.c`, `special.c`, `string.c`, `update.c` —
  all canonical Merc source filenames, none of them LPC.
- `grep -r "inherit"` across the **entire** extracted tree returns **zero**
  hits — LPC's single most basic keyword (every real LPC object inherits
  something) is completely absent, exactly the same signal that confirmed
  archive #31 was not a mudlib.
- `libs/atlantis/raw/area/` holds 82 `.are` files (`midgaard.are`,
  `moria.are`, `limbo.are`, `hades.are`, `olympus.are`, ...) — Diku's
  world-data format (`#AREADATA` / `#MOBILES` / `#ROOMS` section markers,
  confirmed by inspecting `area/midgaard.are`'s raw header), plus an
  `area.lst` zone index — the same Diku convention archive #31 used, not
  an LPC object-tree layout (no `std/`, `obj/`, `d/`, `cmds/`, `adm/`
  directories anywhere).
- `area/merc.exe` (a prebuilt Windows binary) and `area/cygwin1.dll` ship
  alongside the source — a compiled-server release, not LPC source that a
  driver interprets at runtime.
- `readme.txt` (Traditional Chinese, decoded correctly with a **plain
  `iconv -f GB18030 -t UTF-8`** — no BIG5 fallback needed, see Encoding
  section below) spells out literal Windows build instructions: install
  Cygwin, patch the `Makefile`'s `c.o:` rule to add `-Dunix`, run `make`
  inside `src/`, producing an `envyb.exe` binary that gets copied into
  `area/` and launched via `play.bat` — i.e. "compile this C program and
  run the resulting executable," the standard DikuMUD/Merc build flow,
  never "point an LPC driver's `mudlib directory` at this tree."
- The binary name `envyb.exe` (referenced in `readme.txt` and matching a
  `player/` directory scaffold identical to Merc's `PC_DIR`-per-letter
  convention: `player/a` .. `player/z`, `backup_player/a` .. `z`) points at
  the "EnvyMud" Merc-derivative lineage specifically, not any LPC-family
  codebase.
- Room description text inside `.are` files (spot-checked, e.g. mob #3000
  in `midgaard.are`) is genuine Traditional Chinese narrative text, so
  this was clearly a real, played Chinese localization of a Merc engine —
  just not an LPC one, and therefore outside this project's scope (which
  targets LPC mudlibs running on the FluffOS driver, not arbitrary C MUD
  servers).

### Encoding investigation (for the one text file examined)

`readme.txt` is the only free-standing prose file in the archive worth
transcoding for a human to read (the `.c`/`.h`/`.are` files are either
non-Chinese-bearing code or raw-byte world data not touched by this
pipeline since nothing here gets compiled by our LPC driver). Despite the
archive's own filename using Traditional characters (亞特蘭提斯), a
straight `iconv -f GB18030 -t UTF-8 readme.txt` decoded cleanly and legibly
on the first try — no `BIG5` fallback was needed for this file. (The `.are`
files' embedded Chinese text appeared BIG5-shaped based on the raw byte
patterns spot-checked in `midgaard.are`'s mob #3000 entry, but since none
of this content is going through the pipeline, no full-archive encoding
conversion was performed or is needed.)

### What was NOT done, and why

Per this project's standing precedent (`AGENTS.md`'s "Non-mudlib / needs-
triage files" section, archive #31 `三国歪传.rar`): archives confirmed to
be a different server architecture entirely (here: DikuMUD/Merc, compiled
C + `.are` world files) are skipped outright, not converted. Specifically
NOT done, and correctly so:
- No `work/` conversion (`convert_lib.sh`) — there is no LPC source to
  transcode/rename/fix `.c`→`.lpc` references for; renaming these Merc
  `.c` files would be actively wrong (they're real C translation units
  compiled by `gcc`/Cygwin, not LPC objects the FluffOS driver loads).
- No `config.fluffos` written, no port assigned (the task brief pre-
  assigned port 40058, but it was never consumed — leaving it free for
  whichever next lib in the queue actually needs one; the main session
  should decide whether to reassign it forward or leave a gap, since this
  is the first "not mudlib" hit since #31 to interrupt strictly sequential
  port assignment).
- No driver boot attempt — the FluffOS/LPC driver has no ability to run a
  Merc-format world at all (different bytecode, different object model,
  different network/command-loop architecture end to end).
- No `mudclient.py` registration-flow test — there is no LPC `logind.lpc`/
  `chinese.lpc` callback chain to read or exercise; a Merc server's login
  sequence (`nanny()` in `comm.c`) is a wholly different, non-LPC
  mechanism this project's tooling doesn't target.
- No `lpcc_check.sh` sweep — there is nothing for `lpcc` to compile.

### Recommendation for TODO.md

Mark archive #64 (`消失的亞特蘭提斯MUD破解版.zip`, slug `atlantis`) as
**`not mudlib`** (not `done`), with no port assigned, using the same
convention as archive #31 (`三国歪传.rar`). Extraction was performed and
is kept at `libs/atlantis/raw/` for traceability/future reference, exactly
as archive #31's own raw extraction was presumably retained.
