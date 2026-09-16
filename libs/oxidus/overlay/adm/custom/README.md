# /adm/custom — per-MUD customisation

This tree holds the **per-install overrides** that customise a fork of the
mudlib. Its layout mirrors the shipped defaults in `/adm/etc`: for a given
subsystem, the base data ships in git under `/adm/etc/...`, and the file you
drop in the matching `/adm/custom/...` slot overrides or merges on top of it.

Everything in here except this README, the `.keep` skeleton files, and the
`*.example` templates is git-ignored, so your local customisations never end
up in the repository and `git pull` never clobbers them.

## Slots

| Slot | Overrides / base | Loaded by | How it applies |
|------|------------------|-----------|----------------|
| `config.lpml` | `/adm/etc/default.lpml` | `CONFIG_D` (`/adm/daemons/config.c`) | mapping merge — your keys win |
| `first_user` | — (presence marker) | `/adm/obj/login.c`, security | exists ⇒ first superuser already minted |
| `alarms/*.txt` | template: `/adm/etc/alarms/alarm.txt.example` | `ALARM_D` (`/adm/daemons/alarm.c`) | every `*.txt` here is parsed |
| `security/groups.lpml` | `/adm/etc/security/groups_base.lpml` | master security | per-group list merge (`-name` removes) |
| `security/roles.map` | — (runtime state) | master security | direct role grants, written by `add_role`/`remove_role` |
| `security/access.local.lpml` | `/adm/etc/security/access.lpml` | master security | prepended to the base table (checked first) |
| `certs/{cert,key}.pem` | — (drop-in) | `STD_HTTP_SERVER` via `TLS_CERT`/`TLS_KEY` config; telnet TLS | your TLS cert + key |

## Adding a customisation

1. Find the base file under `/adm/etc/...` (or its `*.example` template).
2. Copy the parts you want to change into the mirrored path under
   `/adm/custom/...`.
3. Rehash the owning daemon via the `master` command or reboot.

## Running in Docker

The container image (see `/adm/dist/docker`) bakes the mudlib read-only and
keeps all runtime state in a single named volume. This whole tree is
symlinked into that volume, so your overrides persist across restarts **and**
image upgrades.

Two kinds of file live here, with two different contracts:

- **Your override data** — `config.lpml`, `security/*`, `alarms/*.txt`,
  `first_user`, etc. Written once into the volume and then **never touched by
  an upgrade**. This is your state; the image will not clobber it.
- **Image-managed scaffolding** — this `README.md`, the `.keep` files, and the
  `*.example` templates. These are baked reference files, refreshed from the
  image into the volume **on every boot** (one-directional, image → volume).
  Do not hand-edit them in the volume: an upgrade will overwrite them with the
  current versions. Copy an `*.example` to its live name and edit *that*.

The refresh only ever **adds or overwrites** the image's own scaffolding — it
never deletes. Nothing you place in this tree is removed by an upgrade, so your
overrides are safe even if a future image drops or renames a template.

## Not yet migrated

Some customisation points still read from `/adm/etc` directly and haven't
been moved into this tree yet (mssp, secrets, and the various edit-in-place
files like `logo`, `preload`, aliases and time config). They will migrate
here over time.
