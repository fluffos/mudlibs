# OpenLib

A real [MudOS](https://en.wikipedia.org/wiki/LPMud#Server_software) v22.1a6-era
mudlib by Tim McIntosh, formerly called "UltraLib". Released as a single
alpha snapshot (v0.1) in late 1996 before development ceased.

Distinct from the rest of this collection in almost every way: an
English-language, from-scratch codebase built around a UNIX-flavored
security and shell model instead of the usual wuxia lineage. Login
bootstraps as the literal username `root`, players get a real UNIX-like
shell (`nmsh`) as their command interpreter, and the archive even ships
working FTP/finger/HTTP daemons alongside the game itself.

Source: `tmcintos/OpenLib` on GitHub.

## Highlights

- UNIX-style privilege/protection security model (`mkwiz`, `mkdom`,
  `chprot`, `lsprot`, ...) instead of driver uids.
- A real shell, `nmsh`, with `cd`/`pwd`/`pushd`/`popd`/aliases/history.
- Ships a working FTP daemon, finger daemon, and HTTP daemon as genuine
  listening network services alongside the mud itself.
- Deliberately minimal shipped content -- this is an incomplete v0.1
  alpha snapshot (its own GETTING_STARTED says so), not a finished game.

## Play online

https://mudlibs.fluffos.info/openlib/

## Admin account

- **ID**: `root`
- **Password**: `Mud@2026`
- **Privilege**: the archive's own bootstrap superuser account (defined
  in `security.h`) -- per its own GETTING_STARTED, the intended next
  step is to `mkwiz`/`addmem .. Admin`/`chmem adm .. Admin` a real named
  admin character from here, then `rmwiz root`.

> Warning: `Mud@2026` is a public default password for local play
> only. Change it before exposing this host publicly.

## Local run

```
cd libs/openlib
~/src/fluffos/build-debug/src/driver config.fluffos
```

Game port: **40245**.
