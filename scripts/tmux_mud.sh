#!/usr/bin/env bash
# Persistent interactive mud session via tmux, for deep-testing that needs
# to survive across many separate tool calls (registration -> play ->
# combat -> death/resurrection etc.) without losing connection state the
# way a fresh scripts/mudclient.py invocation does every time.
#
# Usage:
#   scripts/tmux_mud.sh start SESSION HOST PORT   # open telnet in a new tmux session
#   scripts/tmux_mud.sh send  SESSION "text"      # send one line (Enter appended)
#   scripts/tmux_mud.sh send  SESSION ""          # send a bare Enter
#   scripts/tmux_mud.sh read  SESSION [LINES]     # dump last LINES of the pane (default 200)
#   scripts/tmux_mud.sh stop  SESSION             # kill the session
#   scripts/tmux_mud.sh list                      # list active mud tmux sessions
#
# Sessions are tmux sessions named "mud-SESSION" so they don't collide with
# unrelated tmux usage. `read` is non-blocking -- it just snapshots the
# pane; caller is responsible for waiting/polling (e.g. `sleep 1` between
# send and read) since there's no clean way to detect "done producing
# output" for a telnet stream in general.

set -euo pipefail

cmd="${1:-}"
case "$cmd" in
  start)
    name="mud-$2"; host="$3"; port="$4"
    tmux kill-session -t "$name" 2>/dev/null || true
    tmux new-session -d -s "$name" -x 220 -y 500
    tmux send-keys -t "$name" "telnet $host $port" Enter
    ;;
  send)
    name="mud-$2"; text="${3-}"
    tmux send-keys -t "$name" -l -- "$text"
    tmux send-keys -t "$name" Enter
    ;;
  read)
    name="mud-$2"; lines="${3:-200}"
    tmux capture-pane -t "$name" -p -S "-$lines"
    ;;
  stop)
    name="mud-$2"
    tmux kill-session -t "$name" 2>/dev/null || true
    ;;
  list)
    tmux list-sessions 2>/dev/null | grep '^mud-' || echo "(no active mud sessions)"
    ;;
  *)
    echo "usage: $0 {start|send|read|stop|list} ..." >&2
    exit 1
    ;;
esac
