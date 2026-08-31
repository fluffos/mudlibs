# syntax=docker/dockerfile:1
#
# Oxidus mudlib + FluffOS driver, containerised.
#
# Reuses the canonical Oxidus build/run methodology in adm/dist:
#   * adm/dist/rebuild  -> clones FluffOS fresh, compiles the driver, and
#                          rewrites config.mud with absolute paths.
#   * adm/dist/run      -> reboot loop (mirrored by docker-entrypoint.sh so it
#                          behaves correctly as PID 1).
#
# Stage 1 clones a pristine copy of the mudlib over public HTTPS and builds the
# driver. Stage 2 ships only the built tree on a slim runtime base.

############################
# Stage 1: build
############################
FROM debian:bookworm-slim AS builder

# Where the mudlib lives inside the image. The rebuild script bakes this exact
# path into config.mud, so the runtime stage MUST use the same value.
ARG OXIDUS_HOME=/oxidus
# Repo + ref to clone. CI passes the exact commit SHA for a reproducible lib;
# fluffos itself still tracks master (per the canonical rebuild script).
ARG OXIDUS_REPO=https://github.com/gesslar/oxidus-mudlib.git
ARG OXIDUS_REF=main

ENV DEBIAN_FRONTEND=noninteractive

# Build toolchain + FluffOS build deps (see /mud/fluffos_deps_ubuntu).
# Note: FluffOS's cmake always runs find_package(MySQL) and requires mysql.h
# even though rebuild sets PACKAGE_DB_MYSQL=0, so the client headers must be
# present (matches mysql-devel on the canonical Fedora build host).
RUN apt-get update && apt-get install -y --no-install-recommends \
      build-essential \
      bison \
      cmake \
      git \
      ca-certificates \
      libssl-dev \
      libz-dev \
      libpcre3-dev \
      libsqlite3-dev \
      libpq-dev \
      libjemalloc-dev \
      libicu-dev \
      default-libmysqlclient-dev \
      pkg-config \
      libffi-dev \
 && rm -rf /var/lib/apt/lists/*

# Pristine clone of the mudlib.
RUN git clone "${OXIDUS_REPO}" "${OXIDUS_HOME}" \
 && git -C "${OXIDUS_HOME}" checkout "${OXIDUS_REF}"

# Build the driver via the canonical script. It clones FluffOS fresh (tracking
# master), compiles, installs binaries into adm/dist/bin, copies the driver
# headers into include/driver, and rewrites config.mud's mudlib/log paths.
#
# MARCH_NATIVE=OFF is critical: FluffOS defaults -march=native ON, which would
# tune the binary to the *build* host's CPU (e.g. a CI runner with AVX-512) and
# SIGILL on any older CPU at runtime. OFF targets a portable x86-64 baseline.
WORKDIR ${OXIDUS_HOME}/adm/dist
RUN OXIDUS_CMAKE_EXTRA="-DMARCH_NATIVE=OFF" ./rebuild

# Slim the tree for the runtime stage: keep the FluffOS test certs (used for the
# optional TLS opt-in) but drop the fluffos source/build tree and git metadata.
# Also stash the baked adm/custom scaffolding (README, .keep skeleton, *.example
# templates) into custom.dist. The whole baked tree is scaffolding - live
# per-MUD data is git-ignored and never in the image - so the entrypoint can
# refresh it into the volume one-directionally on every boot.
RUN set -eux; cd "${OXIDUS_HOME}"; \
    mkdir -p adm/dist/certs.dist; \
    cp adm/dist/fluffos/testsuite/etc/cert.pem adm/dist/certs.dist/; \
    cp adm/dist/fluffos/testsuite/etc/key.pem  adm/dist/certs.dist/; \
    cp -a adm/custom adm/dist/custom.dist; \
    rm -rf adm/dist/fluffos .git

############################
# Stage 2: runtime
############################
FROM debian:bookworm-slim AS runtime

ARG OXIDUS_HOME=/oxidus
ENV OXIDUS_HOME=${OXIDUS_HOME}
ENV DEBIAN_FRONTEND=noninteractive

# Shared libraries the dynamically-linked driver needs at runtime, plus bash
# (run/entrypoint) and procps (pgrep, used by adm/dist/run's stop helper).
# neovim/nano/ripgrep are included so you can `docker exec` in and edit/search
# the lib directly (handy for tinkering — note such edits are wiped on the next
# image update; see README "Editing the lib").
RUN apt-get update && apt-get install -y --no-install-recommends \
      bash \
      procps \
      ca-certificates \
      libssl3 \
      zlib1g \
      libpcre3 \
      libsqlite3-0 \
      libpq5 \
      libjemalloc2 \
      libicu72 \
      libstdc++6 \
      libbz2-1.0 \
      libmariadb3 \
      neovim \
      nano \
      ripgrep \
      gosu \
 && rm -rf /var/lib/apt/lists/* \
 && useradd -r -m -d /home/oxidus -s /bin/bash oxidus

COPY --from=builder ${OXIDUS_HOME} ${OXIDUS_HOME}
COPY docker-entrypoint.sh /usr/local/bin/docker-entrypoint.sh

# state/ is the single persistence root; the entrypoint symlinks all mutable
# mudlib paths into it. The image starts as root (no USER line) so the
# entrypoint can chown a host bind mount to the operator's uid and rewire the
# baked tree, then it drops to OXIDUS_UID:OXIDUS_GID via gosu to run the driver
# unprivileged. The build-time chown seeds sane ownership for the baked tree and
# any anonymous-volume fallback.
RUN chmod +x /usr/local/bin/docker-entrypoint.sh \
 && mkdir -p ${OXIDUS_HOME}/state \
 && chown -R oxidus:oxidus ${OXIDUS_HOME}

WORKDIR ${OXIDUS_HOME}

# Plain telnet on 1336; TLS telnet on 1338 is opt-in via OXIDUS_TLS=1 (see
# docker-entrypoint.sh). EXPOSE is metadata only — you still map the port with
# -p/ports; listing 1338 keeps the image self-describing and lets `docker run -P`
# publish it.
EXPOSE 1336
EXPOSE 1338
VOLUME ${OXIDUS_HOME}/state

ENTRYPOINT ["/usr/local/bin/docker-entrypoint.sh"]
