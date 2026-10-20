#!/usr/bin/env bash
# scripts/play_boot.sh SLUG PORT [DRIVER]
#
# Boot one vendored lib for a play test (KB 08 10.7, 10.16): a pristine copy of the tracked files (scripts/pristine_tree.sh: its own config and port, the site's
# keep dirs) and the real driver as a transient systemd user unit `play-SLUG` with a 3 GB memory cap, its stdout and stderr in
# ${LPC_SCRATCH:-$HOME/.cache/lpc-scratch}/play-SLUG.out.  DRIVER defaults to ~/src/fluffos/build-debug/src/driver (a lib with its own driver build, lima or
# wilderness, passes that one).  Waits until the port answers.  Stop it with `scripts/play_stop.sh SLUG`: the unit is the exact process group, never a pkill.
set -euo pipefail
[ $# -ge 2 ] || { echo "usage: $0 SLUG PORT [DRIVER]" >&2; exit 2; }
SLUG=$1; PORT=$2; DRIVER=${3:-$HOME/src/fluffos/build-debug/src/driver}
SCR=${LPC_SCRATCH:-$HOME/.cache/lpc-scratch}
TAG=${PLAY_TAG:+-$PLAY_TAG}     # PLAY_TAG=old: a second instance (own unit, tree and output) for an A/B run with another driver
DEST=$SCR/play-$SLUG$TAG
cd "$(dirname "$0")/.."
systemctl --user stop "play-$SLUG$TAG" 2>/dev/null || true
systemctl --user reset-failed "play-$SLUG$TAG" 2>/dev/null || true
rm -rf "$DEST"
scripts/pristine_tree.sh "$SLUG" "$PORT" "$DEST" > /dev/null
# the pristine tree is HEAD: bring in the working-tree edits of this lib too (a fix being tested), unless PLAY_SYNC=0
if [ "${PLAY_SYNC:-1}" != 0 ]; then
  python3 - "$SLUG" "$DEST" << 'PY'
import sys
sys.path.insert(0, "scripts")
import lpc_warnings as lw
print("synced", lw.sync_changes(sys.argv[1], f"{sys.argv[2]}/libs/{sys.argv[1]}"), "working-tree file(s)")
PY
fi
OUT=$SCR/play-$SLUG$TAG.out
: > "$OUT"
systemd-run --user --quiet --unit="play-$SLUG$TAG" -p MemoryMax=3G -p MemorySwapMax=0 \
  -p "StandardOutput=file:$OUT" -p "StandardError=file:$OUT" -p "WorkingDirectory=$DEST/libs/$SLUG" "$DRIVER" config.fluffos
for _ in $(seq 1 180); do
  if (exec 3<>"/dev/tcp/127.0.0.1/$PORT") 2>/dev/null; then echo "unit play-$SLUG$TAG listening on port $PORT; output $OUT; tree $DEST"; exit 0; fi
  sleep 1
done
echo "play-$SLUG$TAG did not open port $PORT in 180 s; see $OUT" >&2
exit 1
