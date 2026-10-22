#!/usr/bin/env bash
# scripts/play_stop.sh SLUG...   stop the play-SLUG unit(s) scripts/play_boot.sh started (exact unit, never a pkill), remove their staged trees (KEEP_TREE=1 keeps them) and say what is left
for s in "$@"; do
  systemctl --user stop "play-$s" 2>/dev/null && echo "stopped play-$s" || echo "play-$s was not running"
  systemctl --user reset-failed "play-$s" 2>/dev/null || true
  # the staged tree (scripts/play_boot.sh rebuilds it on every boot) is removed with the unit; KEEP_TREE=1 keeps it.  307 left-over trees helped to use up the disk's inodes on 2026-10-22.
  [ "${KEEP_TREE:-0}" = 1 ] || rm -rf "${LPC_SCRATCH:-$HOME/.cache/lpc-scratch}/play-$s"
done
systemctl --user list-units 'play-*' --no-legend 2>/dev/null | cut -c1-100
