#!/bin/bash
#
# Container entrypoint for the Oxidus image.
#
# The image starts as root so it can (1) take ownership of the (possibly
# host-bind-mounted) state for the operator's uid and (2) shuffle symlinks in
# the baked mudlib tree, then it drops privileges via gosu to run the driver
# unprivileged. Concretely:
#
#   1. Symlinks every runtime-mutable mudlib path into the persistent state mount
#      at $OXIDUS_HOME/state, so the baked image stays pristine while game state
#      (players, data, logs, certs, ...) survives container/image upgrades.
#   2. chowns the state to OXIDUS_UID:OXIDUS_GID (default 1000:1000) so a host
#      bind mount is writable by - and editable as - the operator's user.
#   3. Optionally enables TLS telnet using the FluffOS test certs.
#   4. Drops to OXIDUS_UID:OXIDUS_GID and runs the driver in a reboot loop, with
#      proper signal handling for PID 1.
#
# The set of persisted paths is derived from the mudlib .gitignore (everything
# the lib writes at runtime). Add to PERSIST_DIRS / PERSIST_FILES if the lib
# starts writing somewhere new.

set -eo pipefail

OXIDUS_HOME="${OXIDUS_HOME:-/oxidus}"
STATE="${OXIDUS_HOME}/state"
DIST="${OXIDUS_HOME}/adm/dist"
DRIVER="${DIST}/bin/driver"
CONFIG="${DIST}/config.mud"
PUID="${OXIDUS_UID:-1000}"
PGID="${OXIDUS_GID:-1000}"

cd "${OXIDUS_HOME}"

# --- Phase 1: privileged setup (root only) -------------------------------
# Runs once per boot as root: wire persistence, own the state mount, then
# re-exec this script under gosu as the unprivileged target uid (the re-exec
# is non-root, so it skips this block and falls through to the driver loop).
if [ "$(id -u)" = "0" ]; then
  # Directories whose *contents* are runtime state. adm/custom is the
  # consolidated per-MUD override tree (config, security groups/roles/access,
  # alarms, certs, first_user, ...); persisting it as a unit means any override
  # slot added under it survives upgrades without touching this list again.
  PERSIST_DIRS=(
    data
    open
    home
    log
    tmp
    adm/etc/secret
    adm/custom
  )

  # Config is seeded, but then is editable.
  PERSIST_FILES=(
    adm/dist/config.mud
  )

  # Move a directory's pristine contents into the state mount on first boot,
  # then replace it with a symlink into the mount.
  link_dir() {
    local rel="$1"
    local src="${OXIDUS_HOME}/${rel}"
    local dst="${STATE}/${rel}"

    if [ ! -e "${dst}" ]; then
      mkdir -p "$(dirname "${dst}")"
      if [ -d "${src}" ] && [ ! -L "${src}" ]; then
        cp -a "${src}" "${dst}"   # seed from the pristine image copy (.keep files etc.)
      else
        mkdir -p "${dst}"
      fi
    fi

    rm -rf "${src}"
    mkdir -p "$(dirname "${src}")"
    ln -s "${dst}" "${src}"
  }

  # Symlink a single file into the mount. A dangling link is fine: the first
  # write the lib makes lands in the mount.
  link_file() {
    local rel="$1"
    local src="${OXIDUS_HOME}/${rel}"
    local dst="${STATE}/${rel}"

    mkdir -p "$(dirname "${dst}")"
    if [ ! -e "${dst}" ] && [ -f "${src}" ] && [ ! -L "${src}" ]; then
      cp -a "${src}" "${dst}"
    fi

    rm -f "${src}"
    mkdir -p "$(dirname "${src}")"
    ln -s "${dst}" "${src}"
  }

  echo "[entrypoint] wiring persistent state into ${STATE}"
  for d in "${PERSIST_DIRS[@]}"; do link_dir "${d}"; done
  for f in "${PERSIST_FILES[@]}"; do link_file "${f}"; done

  # Refresh image-managed scaffolding into the (now symlinked) adm/custom mount.
  # README, the .keep skeleton, and *.example templates are baked reference
  # files, not editable state - so they flow one-directionally, image -> mount,
  # on every boot, and an upgrade always lands the current versions. Live per-MUD
  # data (config.lpml, security/*, alarms/*.txt, first_user, ...) is not part of
  # the baked stash, so it is left untouched.
  #
  # Add and overwrite only, never delete. Removing a file from the image does not
  # remove it from the mount: pruning downstream would be a bidirectional sync,
  # and that is deliberately out of scope.
  if [ -d "${DIST}/custom.dist" ]; then
    cp -a "${DIST}/custom.dist/." "${OXIDUS_HOME}/adm/custom/"
    echo "[entrypoint] refreshed adm/custom scaffolding from the image"
  fi

  # Optional TLS telnet. Default off (plain telnet on 1336 only).
  if [ "${OXIDUS_TLS:-0}" = "1" ]; then
    tls_port="${OXIDUS_TLS_PORT:-1338}"
    certdir="${OXIDUS_HOME}/adm/custom/certs"   # under adm/custom, symlinked into the mount above
    if [ ! -f "${certdir}/cert.pem" ] || [ ! -f "${certdir}/key.pem" ]; then
      cp -a "${DIST}/certs.dist/cert.pem" "${certdir}/cert.pem"
      cp -a "${DIST}/certs.dist/key.pem"  "${certdir}/key.pem"
      echo "[entrypoint] installed FluffOS test certs into ${certdir}"
    fi
    if ! grep -q "external_port_2_tls" "${CONFIG}"; then
      {
        echo ""
        echo "external_port_2: telnet ${tls_port}"
        echo "external_port_2_tls: cert=adm/custom/certs/cert.pem key=adm/custom/certs/key.pem"
      } >> "${CONFIG}"
      echo "[entrypoint] enabled TLS telnet on port ${tls_port}"
    fi
  fi

  # Take ownership of the whole state mount for the target uid, so the operator
  # can read/write it on the host without sudo (and certbot/etc. can drop files
  # in). Unconditional and recursive: phase 1 runs once per container start (not
  # per in-game reboot), so re-owning the tree is cheap - and a uid-only guard on
  # the mount root would leave stale root-/old-uid-owned children (a newly seeded
  # persist path, an externally created file) unwritable by the driver.
  chown -R "${PUID}:${PGID}" "${STATE}"

  # Drop privileges and re-enter as the target uid (skips this whole block).
  # If the operator explicitly asked to run as root (OXIDUS_UID=0), stay root
  # rather than re-exec into an infinite loop.
  if [ "${PUID}" != "0" ]; then
    echo "[entrypoint] state owned by ${PUID}:${PGID}; dropping privileges"
    exec gosu "${PUID}:${PGID}" "$0" "$@"
  fi
fi

# --- Phase 2: unprivileged driver loop (we are now PUID:PGID) -------------
# Reboot loop with signal handling (mirrors adm/dist/run; exit 1 == reboot,
# exit 0 == clean shutdown, anything else == crash — both stop the container).
set +e
child=""
shutdown() {
  echo "[entrypoint] received shutdown signal, stopping driver..."
  [ -n "${child}" ] && kill -TERM "${child}" 2>/dev/null
}
trap shutdown TERM INT

cd "${DIST}"
while true; do
  echo "[entrypoint] starting driver..."
  "${DRIVER}" "${CONFIG}" &
  child=$!
  wait "${child}"
  status=$?
  echo "[entrypoint] driver exited with status ${status}"
  if [ "${status}" -eq 1 ]; then
    echo "[entrypoint] reboot requested, restarting..."
    # No delay between reboots, matching adm/dist/run's intent. This also
    # leaves no window for a stop signal to land between drivers.
  else
    break
  fi
done

exit "${status}"
