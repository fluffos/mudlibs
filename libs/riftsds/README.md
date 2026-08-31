# Rifts DS

A Dead Souls mudlib (the same well-known generic LPC starter codebase
as `ds386`/`dsI`/`dsII`/`dsIII` elsewhere in this collection, here on
version 3.9) reskinned onto Palladium's post-apocalyptic *Rifts*
tabletop RPG setting: characters track a P.P.E. (Potential Psychic
Energy) resource alongside the usual HP/SP, and the race list includes
a custom `greathorneddragon` option alongside the stock Dead Souls
choices (dwarf, elf, human, half-elf, half-orc, halfling, orc,
poleepkwa).

Not to be confused with `rifts2` (`RiftsMUD2`) elsewhere in this
collection -- that's a completely different, unrelated codebase
(DarkeLIB/Nightmare lineage) that happens to use the same Rifts
setting.

## Important: the "Omega Station" content does not currently work

This lib ships a large, detailed `domains/omega` area (a multi-floor
sci-fi space station, "Omega Station," with named NPCs, a shop, and an
elevator connecting nine levels) plus supporting `domains/common`
sci-fi item/ship content. **Neither compiles or loads.** Both depend on
a whole second set of base object classes (a `LIVING`/`CONTAINER`/
`ARMOUR`/`ELEVATOR`/vendor-and-container "mixin" framework) that the
original repository never actually included -- not a conversion
mistake on this project's part, and not something a quick patch can
fix (see `NOTES.md` and `AGENTS.md` §7.164 for the full technical
writeup). The same problem affects a bundled stock-Dead-Souls-3.9
"builder school" tutorial area (`domains/std`) that ships with this
version of the engine. All of this content is left in place, exactly
as it arrived, in case a future pass wants to build out the missing
framework -- but as of this onboarding, none of it is reachable or
playable.

## What actually works

- The real, functioning Dead Souls 3.9 base: a start room, `enter
  town` into a small village (a general store, a bank with a teller,
  guild halls), the classic `ed`/`qed` line editor, mail, bulletin
  boards, and an in-game creation system for builders.
- A set of thin (intentionally minimal, matching this project's usual
  treatment of stock-base Dead-Souls-lineage content) continent-themed
  stub domains: Africa, Americas, Atlantis, Australia, Australia
  Outback, China, Europe, Japan, Mexico, Russia, South America.
- The standard Dead Souls demo areas: a small campus, `Praxis`, and
  `Ylsrim`.
- This lib's own Rifts flavor layered on top of all of the above: the
  P.P.E. stat, the extra `greathorneddragon` race, and Rifts-flavored
  currency/vendor dialogue in town.

## Play online

https://mudlibs.fluffos.info/riftsds/

## Admin account

- **ID**: `fluffos`
- **Password**: `Mud@2026`
- This repository arrived as a live, previously-played snapshot (three
  real wizard accounts already existed: `gravity`, `thurtea`, `shrub`)
  rather than a fresh install, so the usual first-boot admin wizard
  did not apply. `fluffos` was added to every group in `secure/cfg/
  groups.cfg` alongside the existing accounts, registered normally as
  a player, then promoted to creator status the same way the mudlib's
  own `encre` admin command does it (moving the save file from the
  players directory to the creators directory) -- see `NOTES.md` for
  the exact steps if this ever needs re-seeding.

> Warning: `Mud@2026` is a published default for local play. Change it
> before exposing this to a public network.

## Run locally

```
cd libs/riftsds
~/src/fluffos/build-debug/src/driver config.fluffos
```

Game port: **40257**.
