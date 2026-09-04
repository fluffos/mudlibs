# Spacemud

A space-themed mudlib built on the [LIMA Mudlib](https://limalib.dev) codebase (the same FluffOS reference framework already onboarded standalone as `libs/lima`), with as few changes to Lima itself as possible. Where Lima's own demo world is a fantasy wizard's guildhall, Spacemud drops you into a decaying space station and layers a real spaceship/exploration game on top:

> Person (classic MUD) - you walk around, pick up things, upgrade and
> explore. Buy spacecrafts! Spacecraft - you fly ships, pick up goods,
> sell goods, dock and navigate space to get to specific planets.
> Planet management - you extend your corporations on planets and
> manage the flow of goods on and off planets.

Source: [`limalib/spacemud`](https://github.com/limalib/spacemud) on
GitHub, actively maintained.

## Highlights

- A decaying space station (the `omega` domain) to wake up in and
  explore -- maintenance corridors, waiting rooms, a stargate
  terminal, and the *Yakitori* delivery guild (complete with a
  chef, cashier, and skewer snacks you can eat).
- A from-scratch **procedural universe**: `space_d` generates star
  systems and planets at first boot (types, gravity, mass, radius --
  even naming conventions borrowed from the Greek alphabet), and
  `ship_d`/`spacestation_d`/`proc_gen_d` handle spaceship navigation,
  docking, and station layout.
- Lima's own centralized natural-language command parser (`take the
  red potion from the box`, not just `take potion`), capability-based
  security system, and Unix-like wizard shell all carry over
  unchanged.
- A real crafting/salvage system -- break weapons and armour down
  into raw materials (scrap metal, cloth, plastics, and more) at any
  workbench.

## Play online

https://mudlibs.fluffos.info/spacemud/ — WASM **playable**. The site
serves the same specialized Lima-flavor WASM driver as `lima`/`swmud`
(`scripts/custom_drivers/lima_swmud/`). Admin login (`fluffos` /
`Mud12345`) through the user menu into Grand Hall, plus `look` /
`score` / `quit`, verified with `scripts/wasm_client.js` against
`~/src/fluffos-lima/build-wasm`. The shared default WASM driver cannot
boot this lib (`check_config.lpc`). See `NOTES.md`.

## Admin account

Like stock Lima, this mudlib has `AUTO_WIZ` enabled, so the **first
character created on a fresh install is automatically promoted to
admin** (Lima's own intended, documented behaviour for a
developer-facing framework -- not a bug). This repo's own save data
already has that first slot filled, matching `libs/lima`'s and
`libs/wilderness`'s own convention:

- **ID**: `fluffos`
- **Password**: `Mud12345`
- **Character**: `Fluffos` (Human)

> Warning: `Mud12345` is a public default password for local play only.
> Change it before exposing this host publicly.

## Local run

**Requires a dedicated driver build** -- the stock shared driver used
by every other lib in this collection will refuse to boot this one
(`secure/check_config.lpc`'s compile-time flag requirements conflict
with it; see `NOTES.md` and AGENTS.md §7.46). Reuses the
`~/src/fluffos-lima` worktree already built for `libs/lima`:

```
cd libs/spacemud
~/src/fluffos-lima/build-debug/src/driver config.fluffos
```

Game port: **40259**.

> Note: this mudlib preloads an Intermud-3 daemon that makes a real
> outbound connection to a public I3 router at boot (see `NOTES.md`).
> Every boot is a real network event against a third-party host, not a
> fully sandboxed local test.

## Getting started

Register with any alphabetic name, set a password (5+ characters,
confirmed twice), and answer a few account questions (gender, email,
real name, homepage, how you found the mud -- all but the last are
required, and none are shown to other players unless you prepend a
`#`). From the account menu, `c` creates your first character (pick a
gender and a race), `s` selects it, and `p` enters the game.

You'll land in the Grand Hall (Lima's own wizard meeting room, since
`AUTO_WIZ` puts the first character straight into admin territory).
Try `look`, `score`, `inventory`, `who`, and `quit` to get your
bearings, then `goto /domains/omega/room/floor1/wakeup_room` to jump
straight into the space station story -- open the metal door south and
start exploring the maintenance decks. `? for shell help` lists the
wizard shell's own commands if you want to poke around further.
