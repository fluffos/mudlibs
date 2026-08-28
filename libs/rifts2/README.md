# RiftsMUD2

A real LPC mudlib built on the DarkeLIB lineage (itself descended from
the classic Nightmare/TMI mudlib family) and reskinned onto Palladium's
post-apocalyptic *Rifts* tabletop RPG setting -- Mega-Damage/Structural
Damage Capacity (MDC/SDC), Occupational Character Classes (OCCs), and
Potential Psychic Energy (PPE) all show up on the real character sheet.
The repo's own tagline: "Another take by going from DarkeLIB down to
Rifts."

Not a duplicate of `grav1tyzero/rifts-ds` (also in this collection) --
that lib reskins the same setting onto a completely different engine
(Dead Souls lineage). This one is DarkeLIB/Nightmare-lineage MudOS/
FluffOS from scratch, with its own bespoke Rifts-setting content area
(`std/diewarzau/`, `d/diewarzau/`).

Source: `tsathoqqua/RiftsMUD2` on GitHub.

## Highlights

- Real Rifts-flavored character creation: roll attributes (IQ/ME/MA/
  PS/PP/PE/PB/Spd, with a bonus reroll on any low stat), pick a race,
  and pick an Occupational Character Class -- the underlying `RACE_D`
  daemon and per-limb damage tables are built to support many races and
  OCCs, though only Human/Coalition Grunt are populated in this
  snapshot.
- A working proficiency-based language mechanic: how well you speak a
  language affects how much of what you say comes through intact
  versus garbled nonsense -- a genuine Nightmare-mudlib-lineage design,
  not a bug.
- Bespoke Rifts-setting rooms and encounters under `std/diewarzau/`
  (a warp zone, an arena, a weapons shop, and more), built specifically
  for this fork rather than carried over as stock DarkeLIB content.

## Play online

Not yet WASM-packaged for the browser gallery -- run natively (below).

## Admin account

- **ID**: `fluffos`
- **Password**: `Mud@2026`
- **Privilege**: full top rank (`(god)`/`(admin)`/`(superuser)`/
  `(assist)`/`(arch)`), granted the same way this lineage's own admin
  account works: `position "superuser"` in the saved player file, plus
  group membership in `data/db/groups.db` alongside the archive's
  original admin account, `parnell`.

> Warning: `Mud@2026` is a public default password for local play only.
> Change it before exposing this host publicly.

## Local run

```
cd libs/rifts2
~/src/fluffos/build-debug/src/driver config.fluffos
```

Game port: **40255**.
