# Nightmare Residuum

An [LPMud](https://en.wikipedia.org/wiki/LPMud) "inspired by the Nightmare
Mudlib" but written from scratch for modern [FluffOS](https://github.com/fluffos/fluffos)
rather than ported from a period MudOS archive. Distinct from both
`nightmare3` and `nightmare4` elsewhere in this collection -- its own
codebase, its own space-themed example domain, and a full account/character
split (your login connection and your in-game character are two separate
objects, so one account can hold several characters).

Source: `michaelprograms/nightmare-residuum` on GitHub.

## Highlights

- Real account-based registration: pick an account name, set a password,
  choose a screenreader preference, then create your first character
  (name, confirm, species).
- Account/character separation: `save/account/` holds your login and
  settings, `save/character/` holds each character's own small save file --
  multiple characters can share one account.
- The very first character ever created on a fresh copy of this lib is
  automatically granted immortal/admin rank.
- Built test-first: the mudlib ships its own in-game unit-test and code-
  coverage framework (`D_TEST`) alongside the actual game content.

## Play online

https://mudlibs.fluffos.info/residuum/

## Admin account

- **ID**: `fluffos`
- **Password**: `Mud@2026`
- **Privilege**: immortal (auto-granted to the first character ever
  created on this copy of the lib, via its own real first-connection
  bootstrap -- not a hand-edited save file).

> Warning: `Mud@2026` is a public default password for local play
> only. Change it before exposing this host publicly.

## Local run

```
cd libs/residuum
~/src/fluffos/build-debug/src/driver config.fluffos
```

Game port: **40237**.
