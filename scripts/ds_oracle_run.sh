#!/usr/bin/env bash
# usage: scripts/ds_oracle_run.sh LABEL SLUG PORT ADMIN PW REV|WORK [extra ds_oracle.py args...]
# builds /tmp/oracle-LABEL-SLUG from REV (a commit, e.g. HEAD) or WORK (HEAD + uncommitted changes), boots it,
# runs scripts/ds_oracle.py over every lib/**.lpc (--lib), stops the driver by exact PID and leaves
# ${ORACLE_OUT:-/tmp}/oracle_SLUG_LABEL.txt; diff two of them with scripts/ds_oracle_diff.py.
# ADMIN/PW: an existing creator account (the seeded fluffos / Mud@2026 in most libs; dsI/dsII fluffos / fluffwiz123).
# `--paths FILE` adds leaf objects, one path per line.  Use ports at least 100 apart for the two runs.
set -euo pipefail
LABEL=$1; SLUG=$2; PORT=$3; ADMIN=$4; PW=$5; REV=$6; shift 6
cd "$(dirname "$0")/.."
REPO=$PWD
OUT=${ORACLE_OUT:-/tmp}
DEST=/tmp/oracle-$LABEL-$SLUG
if [ "$REV" = WORK ]; then
  scripts/pristine_tree.sh "$SLUG" "$PORT" "$DEST" > /dev/null
  python3 - "$SLUG" "$DEST" << 'PY'
import sys
import os
sys.path.insert(0, os.path.join(os.getcwd(), "scripts"))
import lpc_warnings as lw
slug, dest = sys.argv[1], sys.argv[2]
print("synced", lw.sync_changes(slug, f"{dest}/libs/{slug}"), "files")
PY
else
  REV=$REV scripts/pristine_tree.sh "$SLUG" "$PORT" "$DEST" > /dev/null
fi
cd "$DEST/libs/$SLUG"
setsid nohup ${DRIVER:-$HOME/src/fluffos/build-debug/src/driver} config.fluffos > /tmp/oracle-$LABEL-$SLUG.out 2>&1 &
PID=$!
echo $PID > /tmp/oracle-$LABEL-$SLUG.pid
trap 'kill $PID 2>/dev/null' EXIT
for i in $(seq 1 240); do nc -z localhost "$PORT" 2>/dev/null && break; kill -0 $PID 2>/dev/null || { echo "driver died"; exit 1; }; sleep 1; done
echo "driver $PID up on $PORT (cwd $(readlink /proc/$PID/cwd))"
cd "$REPO"
python3 -u scripts/ds_oracle.py "$DEST/libs/$SLUG/work" "$PORT" "$ADMIN" "$PW" "$OUT/oracle_${SLUG}_${LABEL}.txt" --lib "$@" | tail -2
kill $PID; sleep 1; kill -0 $PID 2>/dev/null && echo "WARNING: $PID still alive" || echo "driver $PID stopped"
