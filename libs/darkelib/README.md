# DarkeLIB

The real, original DarkeLIB circa 1999 -- the mudlib behind Daybreak Ridge, a from-scratch English-language Lima/Nightmare/TMI- lineage MudOS game. This is the actual ancestor codebase that this project's already-onboarded `rifts2` (RiftsMUD2) forked into a Rifts-tabletop-RPG reskin; DarkeLIB itself is the more original, broader base -- real fantasy-domain content, not a stripped-down starting point.

Source: `thraeq/DarkeLIB` on GitHub, a community-maintained fork 58
commits ahead of the original `jpeckham/DarkeLIB`, with real
1999-2018 development history still visible in-game (news posts from
the original staff, hardcoded admin names).

## Highlights

- A rich, hand-built race list (weretiger, high-elf, drow-elf,
  storm-giant, sword-demon, and two dozen more) and a point-buy stat
  system where you start with 325 points to spend across six
  attributes, with a table showing exactly what each point costs.
- Real fantasy domains to explore: `arm_dealers`, `camps`, `caves`,
  `damned`, `daybreak`, `diewarzau`, `drizzt`, `excelsior`,
  `illuminarae`, `khojem`, `mines`, `newbieville`, `nfd`, `nocte`,
  `shadowraith`, `soulslayer`, `warsyn`, and `zortek` -- guilds,
  shops, quests, and NPCs built up over years of real play.
- A proper score sheet with ASCII health/mental/carry bars, and a
  from-scratch `who`/alias/help system.

## Play online

WASM status: **playable**. Shared WASM driver. Admin login
(`fluffos` / `Mud@2026`) into Newbieville town square, plus `look` /
`score` ("Novice Fluffos the High-man") / `quit` ("Saving...Successful."),
verified with `scripts/wasm_client.js`. Play:
https://mudlibs.fluffos.info/darkelib/

## Admin account

- **ID**: `fluffos`
- **Password**: `Mud@2026`
- **Privilege**: full top rank (`(god)`/`(admin)`/`(superuser)`/
  `(siteadmin)`/`(assist)`/`(approval)`), granted the same way this
  lineage's own admin account works: `position "admin"` in the saved
  player file, plus group membership in `adm/db/groups.db` alongside
  the archive's original admin account, `parnell` -- a real,
  previously-played high-level character from the live 1999-era
  server, left untouched rather than reused or overwritten (its
  password is unknown and unrecoverable, so `fluffos` was seeded as a
  parallel admin account instead).

> Warning: `Mud@2026` is a public default password for local play only.
> Change it before exposing this host publicly.

## Local run

```
cd libs/darkelib
~/src/fluffos/build-debug/src/driver config.fluffos
```

Game port: **40258**.

## Getting started

Register with any alphabetic name (2-15 letters), pick a password,
choose a gender and give an email (any well-formed `user@host` string
works for local play). You'll land in the character generator: `read
list` to see the race list, `pick <race>` to choose one, then spend
your 325 stat points (`q` to keep the defaults). Answer the ANSI color
check, and you're in Newbieville's town square. Try `look`, `score`,
`inventory`, `who`, `help`, and `quit`.
