# Skylib (skylib)

Version 1.8 of Skylib, an English-language LPMud library boot-banner'd as the "Divided Sky Distribution Lib". It's built on the same lineage as Discworld/Nightmare -- soul-based emotes, a directory-based per-verb command dispatcher (`cmds/living`, `cmds/player`, ...), guilds, a round-time combat/action system, and Intermud-3 networking -- and per its own design "should feel familiar to Discworld types".

Source: a maintained, already-FluffOS-adapted archive
(`skylib_fluffos_v3.zip`) from lpmuds.net, a now-defunct LPMud archive
site. Recovered via the Wayback Machine
(<https://web.archive.org/web/20160306113513if_/http://lpmuds.net/files/skylib_fluffos_v3.zip>)
since the original site is down. Slug `skylib`, number 175, port
40222.

## Highlights

- A working starting world: rooms, a training dummy, guilds
  (fighter/mage/thief/cleric/artisan), shops, and full player
  registration/login.
- The single biggest bug found while porting this: this driver build
  compiles WITH native `add_action()` support, but Skylib was written
  almost entirely against a `NO_ADD_ACTION` driver flavor (confirmed
  by the archive's own bundled `local_options.skylib` build config)
  where its own soul/directory-based dispatcher is the *only* command
  path. On this driver, that meant every single typed command was
  silently swallowed and rejected twice over ("What?" printed by both
  the mudlib's own fallback and the driver's own native dispatch
  finding nothing) before ever reaching the real dispatcher. Fixed
  with a small set of driver-flavor-gated compat shims -- full
  details in `NOTES.md`.
- A second wide-reaching bug: the archive's own bundled
  `include/runtime_config.h` used a stale `get_config()` index
  numbering that doesn't match this driver's real internal layout,
  so `get_config()` calls silently returned wrong, wrongly-typed
  values. Replaced with the driver's canonical header.
- Like `imud`/`foundation2`, Skylib makes a real outbound network
  connection attempt to the historic Intermud-3 router shortly after
  every boot (`secure/handlers/intermud.lpc`, preloaded by default) --
  genuine upstream functionality, not a bug, but flagged since it's
  unusual for this project's normally fully-sandboxed corpus.

## Registration flow

`N` (new character) -> name -> confirm (y/n) -> password -> confirm
password -> gender (`male`/`female`) -> lands in the game world with
a starter dagger, torches, and some coin.

## Admin account

- **id**: `fluffos`
- **password**: `Sky@2026Pass`
- **privilege**: member of the `admin` group (`secure/save/handlers/
  domain.o`)

The mudlib starts in "creator only mode" on any fresh install (a
safety default triggered automatically the first time the saved mud
name doesn't match the configured one -- which includes the very
first boot ever), which blocks *all* new-character registration,
including the very first admin account. Bootstrapped the same way
this project has handled equivalent placeholder-admin-group archives
before (`foundation2`, `zjdywzb`, `yhwhpublicfi`): edited
`secure/save/handlers/domain.o` directly (renaming the archive's own
pre-seeded placeholder member, literally named `"default"`, to
`"fluffos"`) and reset the saved `login_mode` back to `0`
(unrestricted). See `NOTES.md` for the exact fields.

## Status

Boots clean: zero compile errors, zero runtime errors in `debug.log`
across repeated fresh-driver boots. Verified live with a real driver
session and a raw socket client: full registration of a brand-new
character, login, and `look`/`score`/`inventory`/`quit` all producing
correct, differentiated output with a clean disconnect on `quit`.

2036 of 2163 `.lpc` files pass a full `lpcc_check.sh` batch compile
sweep. The 127 that don't are, almost entirely, pre-existing content
gaps that predate this port (deliberately-broken LPC compiler-error
teaching examples under `d/learning/`, `secure/master/*` mixin files
that only compile as part of the whole `master.lpc` object, a dead/
superseded alternate room-topography system, obsolete
`std/guilds/old/*` content calling a `set_race()` function that no
longer exists anywhere in the archive, two missing headers, and one
file that ships in the *original* raw archive itself as a single
20,506-byte line with zero newlines) -- see `NOTES.md` for the full
breakdown. None of it is boot-critical or reachable from ordinary
play.

WASM status: not yet attempted (`wasm_status` left `""`).

## Local run

```
cd libs/skylib
~/src/fluffos/build-debug/src/driver config.fluffos
```

Game port: **40222**.
