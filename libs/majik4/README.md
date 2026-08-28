# Majik 4

A real [MudOS](https://en.wikipedia.org/wiki/LPMud#Server_software)
v21/v22-era mudlib from 1998-1999 -- the fourth incarnation of hobbyist
author Tero "namhas" Leino's Majik project, and the direct successor to
[majik3](../majik3/README.md) (also in this collection). Development
stopped when the base engine was, in the author's own words, "almost,
still not even beta" -- the world builders hadn't finished building
content by the time the team moved on to a 3D successor project.

Architecturally very different from majik3: a grid-based, "roguelike"
2D gameworld with a real graphical client (not plain telnet) driving it
over a custom structured wire protocol.

Source: `tleino/majik4` on GitHub.

## Highlights

- A real 2D grid map you walk around on, not room-to-room text
  navigation.
- Real hand-built content: Hilltop Village (an inn, a bank, a general
  store, a village square) and the Bral Gaur dwarven area (with its own
  invented conlang, used for in-game names and vocabulary).
- The original graphical client protocol is fully text-framed and
  scriptable (see NOTES.md) -- you don't need the original client
  binaries to interact with this server.
- See also [majik3](../majik3/README.md), the same author's 1997-1998
  predecessor project.

## A note on playability

This archive's own procedural terrain generator (used to fill in
"wilderness" between the hand-built areas) was written as a native
MudOS C driver extension for performance, never built into this
project's FluffOS driver. Onboarding added a minimal compatibility stub
so every character can still enter the game world -- but wilderness
tiles beyond the hand-built areas render as flat, undetailed terrain
rather than the original's smoothly blended landscape. The named areas
themselves (Hilltop Village, Bral Gaur) are unaffected and play as
originally built.

## Play online

Not yet WASM-packaged for the browser gallery -- run natively (below),
and note this lib needs a protocol-aware client (a plain telnet client
will not work for interactive play -- see NOTES.md for the wire format).

## Admin account

- **ID**: `fluffos`
- **Password**: `Mud2026x`
- **Privilege**: `security 100` (this lib's own top rank), granted the
  same way the archive's own README.1st documents: register normally,
  then append `security 100` to the resulting
  `data/player/f/fluffos.o` save file.

> Warning: `Mud2026x` is a public default password for local play only.
> Change it before exposing this host publicly.

## Local run

```
cd libs/majik4
~/src/fluffos/build-debug/src/driver config.fluffos
```

Game port: **40253**.
