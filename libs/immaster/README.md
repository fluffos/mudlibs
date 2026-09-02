# immaster (菜鸟飞天传)

A small, real Chinese-language LPC learning project built on top of MudCore (<https://github.com/oiuv/mudcore>), a modern FluffOS-native engine framework. immaster's own README calls it plainly: "Ongoing building of the mudlib, as a learning project." It supplies only the content layer -- a short tutorial map -- while MudCore supplies the engine underneath (accounts, login/registration, save/restore, movement, command dispatch, wizard tools, and a set of daemons).

Source: `git clone https://github.com/flyinrookie/immaster` (commit
`43382dc`, July 2020), plus MudCore pinned at the exact commit
(`88d5d3a`) immaster's own git submodule record points to. Slug
`immaster`, number 940, port 40242.

## Highlights

- A real account system: English login ID + password + a 2-10 character
  Chinese character name + gender, all live-verified, including
  save/restore surviving a genuine driver restart.
- A short, polished ~12-room outdoor/indoor tutorial map (courtyard,
  backyard, forest, stream, waterfall, cave, tomb, cliff, treehouse,
  trails) with a real map image under `doc/map/`. No NPCs, items, or
  combat in this specific archive -- a genuinely thin, in-progress
  learning project by design, not a conversion gap (MudCore's own
  combat/NPC primitives compile fine, immaster's map just doesn't use
  them yet). See `NOTES.md` §5.
- Registering with the reserved login ID `teamug` (MudCore's built-in
  admin-account convention) grants wizard commands automatically -- no
  separate seeding step needed.
- **Critical fix applied during conversion**: MudCore's central command
  dispatcher (`find_command()`, used by every player and wizard command)
  and its object preloader both gated on a hardcoded `file_size(x +
  ".c")` check, which this project's `.c`->`.lpc` rename would have
  silently broken -- every single command would have failed with zero
  compile errors. Auto-fixed by `convert_lib.sh`'s literal-extension
  sed pass and confirmed live. Full details in `NOTES.md` §1.
- No outbound network anywhere in the merged engine+content tree
  (verified by grep for socket/Intermud efuns) -- fully offline like the
  rest of this collection.

## Status

Boots clean against `~/src/fluffos/build-debug/src/driver`: all ten
MudCore daemons preload in order, `Initializations complete.` every time.
127 of 128 files pass a full `lpcc_check.sh` sweep; the one failure is a
pre-existing orphaned/dead file in the original archive (never inherited
or referenced anywhere, and missing a data file it depends on) -- not a
conversion regression. Full detail in `NOTES.md` §2.

Verified live with raw socket sessions: full registration flow, login
with restore, `look`, movement between rooms, `say`, `help`, the
archive's own `test` command, and a clean `quit` -- plus save/restore
confirmed across an actual driver restart.

WASM status: not yet attempted (`wasm_status` left `""`).

## Local run

```
cd libs/immaster
~/src/fluffos/build-debug/src/driver config.fluffos
```

Game port: **40242**.
