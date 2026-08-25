# Dead Souls 3.8.6

The classic, widely-deployed "Dead Souls" LPC mudlib base (v3.8.6,
released 2014), descended from Descartes of Borg's Nightmare mudlib.
Unlike every other lib in this collection, Dead Souls isn't a themed
game in its own right — it's a generic, well-documented starter
codebase that hundreds of real-world LPMuds have been built on top of,
shipped here close to stock. A fresh boot runs its own first-time admin
installation wizard (register the admin's name/password/gender, then
the driver restarts itself), after which the world is the small stock
demo area: a campus, a scripted line editor (`ed`/`qed`), a bulletin
board, mail, an in-game creation system for builders, and a starter
"Players Handbook" new characters are pointed at on login.

## Content highlights

- The very first connection to a fresh install always runs
  `secure/lib/connect.lpc`'s bootstrap wizard, not the normal login —
  it asks for an admin username/password/display name/gender/real
  name/email, seeds that account with wizard powers, swaps in the real
  login object (`connect.real`), and then shuts the driver down; the
  next boot uses the normal registration/login flow for everyone,
  including that admin.
- Ordinary players start in the campus start room; the built-in `ed`
  line editor (used for mail, board posts, bug reports, and in-game
  file editing) is the classic archaic line-mode editor — `read chapter
  1 in handbook` is the game's own suggested first stop for players who
  haven't used one before.
- A small but real creation system (OLC-style) is available to
  wizards for building rooms/items/NPCs in-game without leaving the
  driver.

## Play online

https://mudlibs.fluffos.info/ds386/

## Admin account

- **ID**: `fluffos`
- **Password**: `Mud@2026`
- Seeded through the mudlib's own normal first-boot admin
  installation wizard (not a data-file edit) — this is the standard,
  intended way any Dead Souls install creates its first admin.

> Warning: `Mud@2026` is a published default for local play. Change it
> before exposing this to a public network.

## Run locally

```
cd libs/ds386
~/src/fluffos/build-debug/src/driver config.fluffos
```

Game port: **40205**.

Note: on a genuinely fresh `work/` (regenerated from `raw/`), the very
first connection will be the admin-install wizard described above, not
a normal login — see `NOTES.md` for the full walkthrough and what to do
if `work/secure/lib/connect.lpc` has already been swapped to the "real"
login (i.e. this repo's committed state, where the wizard has already
run once for the `fluffos` account).
