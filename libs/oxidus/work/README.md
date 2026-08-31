# Oxidus

> **If you're looking to run it in a Docker container, please see
> [DOCKER.md](DOCKER.md)** — one command, no build toolchain required.

## Setting up and documentation

Information on setting up and further documentation of the systems and
functions of Oxidus can be found on the [Oxidus documentation site](https://oxidus.online/).

## Installing and running

Oxidus runs on the [FluffOS](https://github.com/fluffos/fluffos) driver, which
it builds from source. The whole build-and-run pipeline lives in `adm/dist/`.

### 1. Clone the repository

```bash
git clone https://github.com/gesslar/oxidus-mudlib.git
cd oxidus-mudlib
```

### 2. Install the build dependencies

The driver needs a C/C++ toolchain plus a handful of development libraries. On
Debian / Ubuntu:

```bash
sudo apt-get install build-essential bison cmake git \
  libssl-dev libz-dev libpcre3-dev libsqlite3-dev libpq-dev \
  libjemalloc-dev libicu-dev default-libmysqlclient-dev
```

On other distributions, install the equivalents: a compiler, `bison`, `cmake`,
`git`, and the OpenSSL, zlib, PCRE, SQLite, PostgreSQL, jemalloc, ICU, and MySQL
client development headers.

### 3. Build the driver

```bash
adm/dist/rebuild
```

This initialises the bundled FluffOS submodule, compiles the driver against the
current FluffOS `master`, installs the binaries into `adm/dist/bin/`, and
rewrites `adm/dist/config.mud` with the absolute paths for your checkout.

### 4. Start the MUD

```bash
adm/dist/run            # run in the foreground (auto-restarts on an in-game reboot)
```

`adm/dist/run` also accepts:

- `adm/dist/run bg` — start in the background
- `adm/dist/run stop` — stop a running instance

### 5. Connect

```bash
telnet localhost 1336
```

The first character to log in becomes Oxidus's owner with the highest
privileges.

## AI Assistant Guidelines

Be aware of skills documented in .claude/skills
