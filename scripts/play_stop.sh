#!/usr/bin/env bash
# scripts/play_stop.sh SLUG...   stop the play-SLUG unit(s) scripts/play_boot.sh started (exact unit, never a pkill) and say what is left
for s in "$@"; do
  systemctl --user stop "play-$s" 2>/dev/null && echo "stopped play-$s" || echo "play-$s was not running"
  systemctl --user reset-failed "play-$s" 2>/dev/null || true
done
systemctl --user list-units 'play-*' --no-legend 2>/dev/null | cut -c1-100
