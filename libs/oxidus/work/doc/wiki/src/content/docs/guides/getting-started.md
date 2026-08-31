---
title: Getting Started
description: Clone, build, and run the Oxidus mudlib.
sidebar:
  order: 1
---

Oxidus runs on the [FluffOS](https://github.com/fluffos/fluffos) driver, which it builds from source. The whole build-and-run pipeline lives in `adm/dist/`. There are two ways to get a server running: Docker (no build toolchain required) or a from-source build.

## Quick Start with Docker

If you just want a running server with the least friction, run the published image -- no clone or compiler needed:

```bash
docker run -d --name oxidus --init \
  -p 1336:1336 \
  -v oxidus-state:/oxidus/state \
  ghcr.io/gesslar/oxidus:latest
```

- `--init` -- clean signal handling, so `docker stop` shuts the driver down promptly
- `-p 1336:1336` -- exposes the telnet port on the host
- `-v oxidus-state:/oxidus/state` -- a named volume holding all game state

See [DOCKER.md](https://github.com/gesslar/oxidus-mudlib/blob/main/DOCKER.md) for logs, lifecycle, and updates. To connect, skip to [Connect](#connect) below.

## Building from Source

### 1. Clone the repository

```bash
git clone https://github.com/gesslar/oxidus-mudlib.git
cd oxidus-mudlib
```

### 2. Install the build dependencies

The driver needs a C/C++ toolchain plus a handful of development libraries. On Debian / Ubuntu:

```bash
sudo apt-get install build-essential bison cmake git \
  libssl-dev libz-dev libpcre3-dev libsqlite3-dev libpq-dev \
  libjemalloc-dev libicu-dev default-libmysqlclient-dev
```

On other distributions, install the equivalents: a compiler, `bison`, `cmake`, `git`, and the OpenSSL, zlib, PCRE, SQLite, PostgreSQL, jemalloc, ICU, and MySQL client development headers.

### 3. Build the driver

```bash
adm/dist/rebuild
```

This initialises the bundled FluffOS submodule, compiles the driver against the current FluffOS `master`, installs the binaries into `adm/dist/bin/`, and rewrites `adm/dist/config.mud` with the absolute paths for your checkout.

### 4. Start the MUD

```bash
adm/dist/run            # run in the foreground (auto-restarts on an in-game reboot)
```

`adm/dist/run` also accepts:

- `adm/dist/run bg` -- start in the background
- `adm/dist/run stop` -- stop a running instance

## Connect

```bash
telnet localhost 1336
```

The first character to log in becomes Oxidus's owner with the highest privileges.

## Next Steps

- Read the [systems overview](/systems/overview/) to understand how the mudlib is organized.
- See [Contributing](/guides/contributing/) if you want to submit changes.
