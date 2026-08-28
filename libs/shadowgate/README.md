# ShadowGate

A *Nightmare Mudlib*-lineage English-language fantasy MUD (its own
`adm/obj/master.c` header reads: "from the Nightmare Mudlib ... created by
Descartes of Borg 1993"), grown into a large, actively-developed AD&D/d20
ruleset game: feats, invocations, spell disciplines, ~50 playable races,
and 14 classes (barbarian, bard, cavalier, cleric, druid, fighter, mage,
paladin, psion, psywarrior, ranger, sorcerer, thief, warlock), each with
its own trainer NPC and a 15-stage guided character-creation wizard
(class, gender, race, subrace, template, age, stat rolling,
height/weight/body/hair/eye color, language, alignment, deity, and a
class-specific "special" choice).

The repo's own `README` says this is (or was) a real, still-hosted MUD at
`shadowgate.org` -- unrelated to the classic 1989 NES adventure game of
the same name.

Source: `openshadowgate/shadowgate` on GitHub.

## Highlights

- A genuinely large, decades-grown world: 46,610 source files across
  dozens of zones (`d/shadow`, `d/dagger`, `d/laerad`, `d/underdark`,
  `d/koenig`, `d/tsarven`, and many more), a full D&D-style feat/
  discipline/invocation system, and a real per-account save architecture
  (accounts, characters, banking, quests, mail, bulletin boards).
- Porting it surfaced a genuinely severe, silent, zero-compile-error
  blocker: this project's shared driver build hardcodes FluffOS's
  `REF_RESERVED_WORD` option, making the bare identifier `ref` a
  reserved keyword -- and this archive's `std/user/refs.lpc` used `ref`
  as an ordinary parameter name in a file inherited straight into the
  player body class, breaking compilation of `std/user.lpc` (`OB_USER`)
  itself. Fixed by renaming the parameter; see `NOTES.md` for the full
  writeup, including a second, only-found-via-live-play blocker (missing
  per-account save directories silently aborting the character-creation
  wizard's `finalize` step) and the recurring Nightmare-lineage
  `set_short()`/`set_long()` closure bug also seen in this project's
  `sunshadow`/`nightmare3`/`nightmare4`/`genesis`/`finalrealms` ports.

## Admin account

- **ID**: `fluffos`
- **Password**: `Mud@2026`
- **Privilege**: promoted directly via save-data (`position "Admin"`)
  and `adm/db/groups.db` (`superuser` group membership) edits -- see
  `NOTES.md` \S6 for why no safe in-game bootstrap path exists on this
  lineage for the very first admin account.

> Warning: `Mud@2026` is a public default password for local play
> only. Change it before exposing this host publicly.

## Local run

```
cd libs/shadowgate
~/src/fluffos/build-debug/src/driver config.fluffos
```

Game port: **40246**.
