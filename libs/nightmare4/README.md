# Nightmare 4

The fourth major generation of the Nightmare Object Library -- one of the oldest and most historically influential LPMud mudlib families, an ancestor of the TMI-2 lineage that several other libs in this collection (including some of the Chinese-MUD codebases) ultimately trace back to. Distinct from `nightmare3` elsewhere in this collection: a later generation with its own separate example domain, its own socket/net object layer, and a class-based Race/Class/Season data-daemon design.

Source: `MudRen/nightmare4` on GitHub. Unlike the rest of this "Chinese
MUD Museum" collection, this lib's content is in English -- included
here deliberately for its historical significance to the wider LPMud
family tree.

## Highlights

- A real, full menu-driven registration flow: name, confirm, password,
  confirm password, gender, display name, email, real name.
- New characters then pick a race (`list` to see the options, `help
  RACE` for details, `pick RACE` to choose -- e.g. `pick human`) before
  landing in Ylsrim's central bazaar, the mudlib's own shipped example
  domain: a small desert town with an armoury, a weaponry, a pub, a
  church, and the surrounding Kaliid Road.
- Classic Nightmare command system: a soul-verb social/emote engine
  layered underneath the normal player command set, plus a full
  wizard/creator toolset (`update`, `clone`, `ed`, etc).

## Play online

https://mudlibs.fluffos.info/nightmare4/

## Admin account

- **ID**: `fluffos`
- **Password**: `Mud@2026`
- **Privilege**: full creator + admin (member of the `SECURE` and
  `ASSIST` groups in `secure/cfg/groups.cfg`), seeded through the
  mudlib's own real one-time installation wizard (the first connection
  to a fresh copy of this lib always creates the admin account this
  way, then replaces itself with the normal player login flow).

> Warning: `Mud@2026` is a public default password for local play
> only. Change it before exposing this host publicly.

## Status

WASM status: `playable`. A `dump_socket_status()` sefun calling
`socket_status()` unconditionally (a `netstat` creator-command
diagnostic, not on the boot/login path) was fatal to simul_efun's
compile without the `sockets` package -- guarded with `#ifdef
__PACKAGE_SOCKETS__`. Full session verified clean after the fix:
registration, race selection, `look`/`score`/`quit`. See `NOTES.md`
\S13.

## Local run

```
cd libs/nightmare4
~/src/fluffos/build-debug/src/driver config.fluffos
```

Game port: **40234**.
