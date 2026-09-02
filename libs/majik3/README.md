# Majik 3

A real [MudOS](https://en.wikipedia.org/wiki/LPMud#Server_software) v22.1b22-era mudlib from 1997-1998 -- the third incarnation of hobbyist author Tero "namhas" Leino's Majik project, a text-based online RPG. This snapshot is taken from a backup made just before a planned conversion to a grid-based ("roguelike") engine -- the author's own README calls it alpha testing, "not playable at all, except you could grow carrots, make money and do some exploring." That candid self-assessment holds up: character creation and basic exploring and farming all work, while several other areas (monster-stocked rooms, a couple of guild rooms, an abandoned early grid-map prototype) rely on game mechanics that were still mid-development when this backup was made.

Distinct from the rest of this collection in the same way `openlib` is:
an English-language, from-scratch codebase, not a Chinese-wuxia
derivative.

Source: `tleino/majik3` on GitHub.

## Highlights

- Real character creation: pick a name and password, then choose from a
  full roster of playable races (human tribes, half-elven, elven,
  dwarven, and "mystic"/"dark" races), each with its own starting city.
- A working farming minigame -- plant and harvest real crops (potatoes,
  carrots, strawberries, tobacco, and more) in the Agriculture zone.
- `guest1`/`guest2`/`guest3` let you visit instantly without registering.
- See also [majik4](../majik4/README.md), the same author's 1999
  successor project (also in this collection) -- an early 2D
  "roguelike" grid-map engine, the direction majik3's own README says
  this project was headed when development on it stopped.

## Play online

Not yet WASM-packaged for the browser gallery -- run natively (below).

## Admin account

- **ID**: `fluffos`
- **Password**: `Mud2026x`
- **Privilege**: `security 100` (this lib's own top rank), granted the
  same way the archive's own README.1st documents: register normally,
  then append `security 100` to the resulting
  `data/player/f/fluffos.o` save file (a `home/fluffos/` working
  directory was also created, matching the same doc's instructions).

> Warning: `Mud2026x` is a public default password for local play only.
> Change it before exposing this host publicly.

## Local run

```
cd libs/majik3
~/src/fluffos/build-debug/src/driver config.fluffos
```

Game port: **40252**.
