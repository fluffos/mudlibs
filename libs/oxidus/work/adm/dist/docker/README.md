# Oxidus Docker image — technical reference

This directory holds the Docker build for Oxidus: a self-contained image of the
[Oxidus](https://oxidus.online/) mudlib plus a freshly-compiled FluffOS driver.
The build clones a **pristine** copy of the mudlib and compiles the driver from a
fresh clone of FluffOS using the canonical `adm/dist/rebuild` script — so a fresh
container is a brand-new mudlib, ready to play. The first character to log in
becomes Oxidus's owner with the highest privileges.

> **Just want to run it?** See [`DOCKER.md`](../../../DOCKER.md) at the repo root
> for the step-by-step usage guide — run the published image or build your own,
> connect, watch the logs, start/stop, upgrade, reset, and edit the lib.
>
> This document is the **technical reference**: the files in this directory, what
> persists, the configuration knobs, TLS, and how the image is assembled.

## Files in this directory

| File                    | Purpose                                                        |
| ----------------------- | -------------------------------------------------------------- |
| `Dockerfile`            | two-stage build — builder compiles the driver, slim runtime ships the tree |
| `docker-compose.yml`    | local build-and-run (`docker compose up -d --build`)           |
| `docker-entrypoint.sh`  | boot-time persistence wiring, state ownership, TLS, driver reboot loop |
| `.env.example`          | copy to `.env` for host-side compose settings (see below)      |
| `.dockerignore`         | keeps build context small                                      |

## What persists

Code is baked into the image (pristine); only runtime state lives in the
`/oxidus/state` mount (a host bind mount by default — see `DOCKER.md` — or a
named volume if you prefer). On first boot the entrypoint moves every
runtime-mutable mudlib path into that mount and symlinks it back in, so state
survives restarts **and** image upgrades:

| Path                  | Contents                                  |
| --------------------- | ----------------------------------------- |
| `data/`               | accounts, areas, db, users, storage       |
| `home/`               | player / wizard home directories          |
| `log/`                | driver + mudlib logs                       |
| `open/`, `tmp/`       | scratch / open data                       |
| `adm/etc/secret/`     | secrets                                    |
| `adm/custom/`         | per-MUD overrides: config, security (groups/roles/access), alarms, certs, first_user, mssp |
| `adm/dist/config.mud` | driver runtime config — seeded once, then editable |

The persisted set is derived from the mudlib `.gitignore` (everything the lib
writes at runtime). `adm/custom/` is persisted as a **unit**, so any per-MUD
override slot added under it survives upgrades without editing the entrypoint.
Image-managed scaffolding (`.example` templates, the `.keep` skeleton, READMEs)
is refreshed image→mount on every boot from `adm/dist/custom.dist/` — add/overwrite
only, never delete — so an upgrade always lands the current templates while your
live per-MUD data is left untouched.

## Configuration knobs

Build args (Dockerfile):

| Arg            | Default                                            | Purpose                          |
| -------------- | -------------------------------------------------- | -------------------------------- |
| `OXIDUS_REPO`  | `https://github.com/gesslar/oxidus-mudlib.git`     | mudlib repo to clone             |
| `OXIDUS_REF`   | `main`                                             | branch / tag / commit to build   |
| `OXIDUS_HOME`  | `/oxidus`                                          | install path inside the image    |

Runtime env (entrypoint, passed into the container):

| Env              | Default | Purpose                                              |
| ---------------- | ------- | ---------------------------------------------------- |
| `OXIDUS_UID`     | `1000`  | host uid that owns the state mount (chowned at boot) |
| `OXIDUS_GID`     | `1000`  | host gid that owns the state mount                   |
| `OXIDUS_TLS`     | `0`     | `1` enables TLS telnet                               |
| `OXIDUS_TLS_PORT`| `1338`  | TLS telnet port                                      |

Host-side (compose interpolation / `docker run` — resolved on the host, **not**
passed into the container):

| Var                  | Default | Purpose                                                |
| -------------------- | ------- | ------------------------------------------------------ |
| `OXIDUS_STATE_PARENT`| `$HOME` | parent dir of the `oxidus-state` state dir on the host |

Set `OXIDUS_STATE_PARENT` (and `OXIDUS_UID`/`GID`) in a `.env` file beside the
compose file (see `.env.example`) — that's the cross-platform way, since shell
export syntax differs per OS.

## TLS (optional)

Off by default. To enable TLS telnet using the FluffOS test certificates
(self-signed — fine for testing, replace for production), set `OXIDUS_TLS=1` and
publish the port:

```yaml
environment:
  OXIDUS_TLS: "1"
  OXIDUS_TLS_PORT: "1338"
ports:
  - "1336:1336"
  - "1338:1338"
```

On boot the entrypoint installs the bundled test certs into
`adm/custom/certs/` (inside the state mount) unless a `cert.pem` / `key.pem`
pair is already there, and appends the TLS port to `config.mud`. To use your own
certificates instead, drop `cert.pem` / `key.pem` into `adm/custom/certs/` in the
state mount (e.g. certbot renews there). The HTTP server reads the same pair via
the `TLS_CERT` / `TLS_KEY` config keys.

## How the image is assembled

- **Two-stage build.** The first stage clones a *pristine* copy of the mudlib
  over HTTPS and compiles the driver using the canonical
  [`adm/dist/rebuild`](../rebuild) script (which also pins the mudlib paths in
  `config.mud`). The second, slim runtime stage ships only the built tree.
- **Code baked in, state in a mount.** On first boot the entrypoint moves every
  runtime-mutable path into the `/oxidus/state` mount and symlinks it back — see
  [What persists](#what-persists).
- **Privilege drop.** The container **starts as root** to set up the state mount
  (chown a host bind mount, rewire the baked tree), then drops to
  `OXIDUS_UID:OXIDUS_GID` (default `1000`) via `gosu` and runs the driver
  unprivileged.
- **Reboot loop.** The driver runs in a reboot loop mirroring `adm/dist/run`: an
  in-game reboot (`exit 1`) restarts it automatically, while a real shutdown
  (`exit 0`) stops the container.

## Running vs. rebuilding (stable at run, fresh at build)

A built image is a frozen snapshot — a fixed driver binary with the mudlib baked
in. `docker run` / `docker start` / `docker compose up` on the same image always
behaves identically; only the state mount changes. To pick up a newer FluffOS or
newer base packages you must **rebuild**. Because Docker's layer cache reuses the
clone/compile layers, force a clean build:

```bash
docker compose build --no-cache && docker compose up -d
```

(CI builds are always fresh: each push builds at its exact commit, busting the
cache and recompiling against the latest FluffOS `master`.)

## Notes

- Per the canonical `adm/dist/rebuild`, the **driver tracks fluffos `master`**:
  rebuilding the image picks up the latest FluffOS. The mudlib itself is pinned
  to whatever `OXIDUS_REF` you build (CI builds the exact pushed commit).
- FluffOS is **not a submodule** — `rebuild` clones it fresh from
  `github.com/fluffos/fluffos` (when the `fluffos/` dir is absent) and does
  `git reset --hard origin/master` before compiling, so every rebuild rides
  master HEAD. There's no pinned SHA to advance and nothing to keep in sync.
  (fluffos updates are sporadic — a year quiet, then a flurry — so if you're ever
  unsure whether you "need to update" anything: you don't. Just rerun `rebuild`.)
- `--init` (compose: `init: true`) is recommended so signals/zombies are handled
  cleanly and `docker stop` lets the driver shut down gracefully.
