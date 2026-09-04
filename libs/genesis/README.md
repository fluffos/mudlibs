# Genesis (genesis)

The official mudlib of Genesis, one of the oldest and most influential LPMuds still running (source: <https://github.com/genesismud/mudlib>). This is the CD gamedriver-native mudlib itself, not a snapshot of the live game world -- per the repo's own README: "This repo does not contain a standard domain which will need to be implemented to use the mud." There is no `/d/Genesis` domain here: no rooms, no NPCs, no items, no race std files, no wizard guild content. What ships is the engine: master object, login/ character-creation infrastructure, the std/ base classes (living, player, room, container, weapon, armour, ...), the command souls, the board/mail/ bank/donation/report subsystems, and the full wizard toolset.

## Highlights

- A genuinely large, mature CD-driver mudlib (225 `.lpc`/`.h` files) --
  porting it required working through essentially every category of
  CD-driver-vs-FluffOS incompatibility this project has catalogued: the
  `&operator(...)`/`@` partial-application and function-composition syntax,
  closures that can't capture enclosing-function locals, `foreach(var: expr)`
  colon syntax, old-style default-argument syntax, `m_indexes`/`m_sizeof`/
  `m_delkey` mapping efun renames, reserved-keyword collisions (`class`,
  `new`, `in`, and -- less obviously -- `buffer`, a real FluffOS type
  keyword), and dozens of missing CD-driver efuns reimplemented as
  simul_efuns (`set_auth`/`query_auth`, `file_time`, `wildmatch`,
  `one_of_list`, `applyv`, `reduce`, `mkfunction`, GMCP's `val2json`, ...).
  See `NOTES.md` for the full list.
- Since no domain ships, a from-scratch `secure/login/ghost_player.lpc`
  bootstrap was needed just to make character creation possible at all --
  the real upstream character-creation wizard (race/stat selection) is lost
  along with the rest of the missing domain. See `NOTES.md`.
- The single highest-impact bug found in this port: `add_action()` with a
  bare function *value* as its first argument (`add_action(quit, "quit")`,
  used at 151 of this codebase's 158 call sites) compiles and even shows up
  in `commands()`, but the resulting sentence is **never actually matched
  against typed input** on this driver -- every command in the game,
  including the soul-command dispatch entry point itself
  (`add_action(my_commands, "", 1)`), silently did nothing until this was
  swept to the string form. See `NOTES.md`.
- A second serious, wide-reaching bug: this codebase's own `set_auth()`-based
  uid/euid simulation (written to bridge the CD driver's arbitrary
  "uid:euid" string pair onto FluffOS's simpler model) had `setuid()`/
  `seteuid()`/`export_uid()` all stomping the *other* half of that pair with
  an unresolvable `"#"` placeholder -- corrupting every object's owner uid
  the moment the standard `setuid(); seteuid(getuid());` idiom ran (used
  throughout `std/living.lpc` and elsewhere). Fixed at the source.

## Registration flow

`new` -> character name -> confirm (`y`/`n`/`q`) -> password (min. 8 chars,
2+ non-letter characters) -> confirm password -> in. No race/gender/stat
selection screen (that content is missing, see above) -- new characters
start as a plain human by default.

## Admin account

- **id**: `fluffos`
- **password**: `Mud@2026`
- **rank**: `WIZ_KEEPER` (9, this mudlib's top wizard rank)

Registered through the normal registration flow first (as a mortal), then
granted rank by adding an entry to `config/sys/local.h`'s `DEFAULT_WIZARDS`
map -- normal `new`-character registration refuses any name already present
there (by design, to stop name-squatting on a wizard's identity), so the
name has to exist as a real character first. Verified live: wizard-only
soul commands work (`update <path>` -- the canonical ACL check, since it
exercises both read and compile permissions -- successfully recompiled
`/secure/simul_efun.lpc` end-to-end).

## Status

Boots clean: zero compile errors and zero uncaught runtime errors in
`log/debug.log` across repeated fresh-driver boots. Full registration,
soul-command play (`smile`, `wave`, ...), `quit`/save, and re-login as an
existing (including wizard) character all verified end-to-end with a real
driver session and a raw socket client. Since no domain ships, a mortal's
very first login runs straight into the mudlib's own graceful "your
starting locations are corrupt" fallback and disconnects with an
explanatory message -- expected, not a bug (see `NOTES.md`); wizards are
exempt from that disconnect and can play normally in the bare bootstrap
landing room this port added specifically so login/testing wasn't blocked
entirely (`secure/login/bootstrap_room.lpc`).

A few residual gaps (documented, not blocking): a small number of files are
intentionally not standalone-compilable (`#include`-fragment files that
only compile as part of their aggregator, and two `read_file()`-as-text
room-generator templates); one non-fatal "Denied write permission" logged
during some wizard-login save/restore-privilege sequences that doesn't
block the actual save (both attempts and the resulting file are confirmed
correct); `lib/link_room.lpc` is dead code (never inherited anywhere in
this repo). See `NOTES.md` for the full list.

WASM status: **playable**. Login as `fluffos`, soul commands, and `quit`
are verified under the shared WASM driver (`NOTES.md` WASM status).
Play: https://mudlibs.fluffos.info/genesis/

## Local run

```
cd libs/genesis
~/src/fluffos/build-debug/src/driver config.fluffos
```

Game port: **40213**.
