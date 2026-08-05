#!/usr/bin/env bash
# Persistent interactive mud session via tmux, for deep-testing that needs
# to survive across many separate tool calls (registration -> play ->
# combat -> death/resurrection etc.) without losing connection state the
# way a fresh scripts/mudclient.py invocation does every time.
#
# Usage:
#   scripts/tmux_mud.sh start SESSION HOST PORT       # open telnet in a new tmux session
#   scripts/tmux_mud.sh send  SESSION "text"          # send one line (Enter appended)
#   scripts/tmux_mud.sh send  SESSION ""              # send a bare Enter
#   scripts/tmux_mud.sh read  SESSION [LINES]         # dump last LINES of the pane (default 200)
#   scripts/tmux_mud.sh sendread SESSION "text" [WAIT] [LINES]
#                                                      # send one line, sleep WAIT (default 0.8s),
#                                                      # then read back -- ONE call instead of
#                                                      # send+sleep+read three separate tool calls
#   scripts/tmux_mud.sh multi SESSION $'cmd1\ncmd2\ncmd3' [PER_WAIT] [LINES]
#                                                      # send several lines in sequence (small
#                                                      # PER_WAIT between each, default 0.5s),
#                                                      # read back once at the end -- use this to
#                                                      # drive a whole multi-step ritual (e.g. a
#                                                      # full registration flow) in a single call
#   scripts/tmux_mud.sh stop  SESSION                 # kill the session
#   scripts/tmux_mud.sh list                          # list active mud tmux sessions
#
# Sessions are tmux sessions named "mud-SESSION" so they don't collide with
# unrelated tmux usage. Prefer `sendread`/`multi` over separate send+read
# calls -- far fewer tool round-trips for the same interactive session.

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
  sendread)
    name="mud-$2"; text="${3-}"; wait="${4:-0.8}"; lines="${5:-200}"
    tmux send-keys -t "$name" -l -- "$text"
    tmux send-keys -t "$name" Enter
    sleep "$wait"
    tmux capture-pane -t "$name" -p -S "-$lines"
    ;;
  multi)
    name="mud-$2"; body="${3-}"; per_wait="${4:-0.5}"; lines="${5:-200}"
    while IFS= read -r line; do
      tmux send-keys -t "$name" -l -- "$line"
      tmux send-keys -t "$name" Enter
      sleep "$per_wait"
    done <<< "$body"
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
