# Nightmare 3

One of the oldest and most historically influential LPMud mudlib
families — an ancestor of the TMI-2 lineage that many later mudlibs
(including several Chinese-MUD codebases elsewhere in this collection)
ultimately trace back to. This is the `fluffos/nightmare3` fork,
already updated for modern FluffOS. Unlike the rest of this "Chinese
MUD Museum" collection, this lib's content is in English — included
here deliberately for its historical significance to the wider LPMud
family tree.

## Highlights

- New characters land in a small "genesis void" room and pick a race
  (`read list` to see the options, `pick <race>` to choose — e.g.
  `pick human`) before rolling stats and being dropped into Praxis's
  Monument Square, the game's central starting town.
- Praxis is the mudlib's own shipped example/tutorial domain — a full
  small town (shops, a bank, guild halls, a graveyard, mountain caves,
  an orc valley) meant as both a playable starting area and a worked
  example for anyone building their own domain on this codebase.
- Classic Nightmare command system: a soul-verb social/emote engine
  (`daemon/soul.lpc`) layered underneath the normal player command set.

## Play online

https://mudlibs.fluffos.info/nightmare3/

## Admin account

- **ID**: `fluffos`
- **Password**: `Mud2026Wiz`
- **Privilege**: full creator + admin (`position` = `immortal`,
  member of the `SECURE` and `ASSIST` groups in
  `secure/cfg/groups.cfg` — equivalent to what this codebase's own
  in-game `_sponsor` wizard command grants).

> Warning: `Mud2026Wiz` is a public default password for local play
> only. Change it before exposing this host publicly.

## Local run

```
cd libs/nightmare3
~/src/fluffos/build-debug/src/driver config.fluffos
```

Game port: **40208**.
