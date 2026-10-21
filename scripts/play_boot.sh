#!/usr/bin/env bash
# scripts/play_boot.sh SLUG PORT [DRIVER]
#
# Boot one vendored lib for a play test (KB 08 10.7, 10.16): a pristine copy of the tracked files (scripts/pristine_tree.sh: its own config and port, the site's
# keep dirs) and the real driver as a transient systemd user unit `play-SLUG` with a 3 GB memory cap, its stdout and stderr in
# ${LPC_SCRATCH:-$HOME/.cache/lpc-scratch}/play-SLUG.out.  DRIVER defaults to ~/src/fluffos/build-debug/src/driver (a lib with its own driver build, lima or
# wilderness, passes that one, or sets PLAY_DRIVER for the sweep / combat / walk / soak scripts).  Waits until the port answers.  Stop it with `scripts/play_stop.sh SLUG`: the unit is the exact process group, never a pkill.
set -euo pipefail
[ $# -ge 2 ] || { echo "usage: $0 SLUG PORT [DRIVER]" >&2; exit 2; }
SLUG=$1; PORT=$2; DRIVER=${3:-${PLAY_DRIVER:-$HOME/src/fluffos/build-debug/src/driver}}     # PLAY_DRIVER: the lib's own build for a probe script that cannot pass a third argument (lima: ~/src/fluffos-lima/build-debug/src/driver)
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
  # a lib whose config names its port some other way (shadowgate: `external_port_1`) listens elsewhere: the driver says where
  REAL=$(sed -n 's/^Accepting telnet connections on [0-9.]*:\([0-9][0-9]*\).*/\1/p' "$OUT" 2>/dev/null | head -1)
  for P in "$PORT" ${REAL:+"$REAL"}; do
    if (exec 3<>"/dev/tcp/127.0.0.1/$P") 2>/dev/null; then
      # the port answers before the driver is done with its own start-up work (nt1's `closed` daemon restores 139 users at the first heart beat: every line a visitor
      # types is answered 10-30 s late until then; a loader that runs on the first connection is the lib's own business): wait until the driver's CPU has been quiet
      # for two samples two seconds apart, at most PLAY_QUIET_WAIT (default 45) seconds: nt1's driver is never quiet and the 3 GB cap kills it 2m15s after the boot, so a long wait would only connect to a corpse
      PID=$(systemctl --user show -p MainPID --value "play-$SLUG$TAG" 2>/dev/null || echo 0)
      if [ "${PID:-0}" -gt 0 ] 2>/dev/null; then
        quiet=0; prev=-1; waited=0
        while [ "$waited" -lt "${PLAY_QUIET_WAIT:-45}" ] && [ -r "/proc/$PID/stat" ]; do
          cur=$(awk '{print $14+$15}' "/proc/$PID/stat" 2>/dev/null || echo -1)
          if [ "$prev" -ge 0 ] && [ "$cur" -ge 0 ] && [ $((cur - prev)) -lt 30 ]; then quiet=$((quiet + 1)); else quiet=0; fi
          [ "$quiet" -ge 2 ] && break
          prev=$cur; sleep 2; waited=$((waited + 2))
        done
      fi
      echo "unit play-$SLUG$TAG listening on port $P; output $OUT; tree $DEST"; exit 0
    fi
  done
  sleep 1
done
echo "play-$SLUG$TAG did not open port $PORT in 180 s; see $OUT" >&2
exit 1
