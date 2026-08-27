# Ninetears (ninetears)

A Spanish-language LPMud (also known as Driade / FFICMUD), run by "Alex"
("Tyrael") in the early 2000s, built on a heavily-modified FR (Final
Realms) mudlib 3.4 base with pieces of the Spanish Calandria-CLIB
derivative. Source cloned from
`git clone https://github.com/unleashed/ninetears`. Slug `ninetears`,
number 939, port 40241.

Despite the target's original framing as an "English-language" archive,
the actual in-game content -- room descriptions, commands, help text,
system messages -- is entirely in Spanish; only the upstream repo's own
`README.md` (a personal note from the author) is in English. See
`NOTES.md` for the full porting log.

A real, substantial archive: ~27,000 files / 933K lines under the mudlib
root, dozens of real wizard home directories, a large multi-domain world
(Urghak, Faeleen, Keroon, Asgard, Ishtar, Serkesh, and more), several
guild systems, and archived player save data from the mud's active years.

## Registration flow

`name` -> "Tu nombre [name] es correcto (s/n) ?" -> password -> confirm
password -> gender (h/m) -> lands in "Plano Inmaterial" (a soul-formation
antechamber room).

## Admin account

- **id**: `fluffos`
- **password**: `Mud@2026`
- **privilege**: seeded as a "god" (`/global/god` player-body class,
  `secure/rango.o`'s `dioses` mapping) plus `high_programmer` status in
  `secure/master.o`'s `positions` mapping (full file-ACL). See `NOTES.md`
  for exactly what was edited and why two separate mechanisms needed
  seeding.

Verified live: special immortal welcome banner on login, `[Dios de la
Administracion]`-style title, listed under "Inmortales" in `who`.

## Status

Boots clean, zero fatal errors. Master, simul_efun, and every core base
class (`std/object`, `std/room`, `std/living/living`, `global/player`)
compile with only harmless warnings. A brand-new character registers all
the way into the game world through the real menu-driven flow, and
`look`/`score`/`who`/`quit` all produce correct output. See `NOTES.md`
for the full compile-sweep breakdown and the encoding-detection story.

**Note**: `/secure/ftpd` is preloaded and opens a real listening socket
on a hardcoded port (4001) a couple of seconds after boot, for an
in-game FTP-style file transfer feature -- see `NOTES.md` before adding
this lib to any automated high-frequency reboot loop.

WASM status: not attempted (`wasm_status` left `""`).

## Local run

```
cd libs/ninetears
~/src/fluffos/build-debug/src/driver config.fluffos
```

Game port: **40241**.
