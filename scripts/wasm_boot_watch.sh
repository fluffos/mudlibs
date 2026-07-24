#!/usr/bin/env bash
# Boot one lib under the WASM driver and just sit connected for a while,
# capturing the FULL raw print()/printErr() transcript to a log file --
# no scripted --send commands beyond an initial newline to open the
# connection. The point is to let the driver's own game-time heartbeats
# and call_outs run long enough for LAZILY-LOADED daemons to actually
# fire and reveal load/compile failures that a quick boot+quit smoke
# test never triggers (a daemon that's only touched by a periodic
# heartbeat, a scheduled event, or an on-demand call_other from some
# other subsystem won't show up in a 20-second registration test).
#
# Usage:
#   scripts/wasm_boot_watch.sh <slug> [duration_sec]
#
# duration_sec defaults to 200 (>3 minutes). The underlying wasm_client.js
# --idle is set higher than --timeout so it never exits early on idle
# silence -- it always runs the full duration regardless of activity.
#
# Output: full transcript to /tmp (path printed at the end), plus a grep
# summary of common failure signatures printed to stdout. This is a
# STARTING POINT, not a verdict -- read the full transcript before
# concluding a lib has a real problem; known noisy-but-harmless lines
# (obsolete config warnings, the mudlib's own caught-and-logged content
# bugs) show up here too. See AGENTS.md \xc2\xa77 for known crash classes.

set -uo pipefail

slug="${1:?usage: $0 <slug> [duration_sec]}"
duration="${2:-200}"
idle=$((duration + 60))

repo_root=$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)
lib_dir="$repo_root/libs/$slug"
wasm_dir="$HOME/src/fluffos/build-wasm/src"
node_bin="$HOME/.local/opt/node/bin/node"

if [ ! -d "$lib_dir" ]; then
  echo "error: $lib_dir does not exist" >&2
  exit 1
fi
if [ ! -x "$node_bin" ]; then
  node_bin=$(command -v node || true)
fi
if [ -z "$node_bin" ]; then
  echo "error: no node binary found (checked ~/.local/opt/node/bin/node and PATH)" >&2
  exit 1
fi

out="/tmp/wasm_boot_watch_${slug}_$$.log"
echo "booting $slug under wasm for ${duration}s (transcript: $out)" >&2

"$node_bin" "$repo_root/scripts/wasm_client.js" "$wasm_dir" "$lib_dir" \
  --send "" --idle "$idle" --timeout "$duration" > "$out" 2>&1
rc=$?

echo "== exit code: $rc =="
echo "== possible failure signatures (grep first-pass, verify by reading $out) =="
grep -nE 'error|Error|ERROR|错误|FATAL|Fatal|fail to load|failed to load|cannot be loaded|Undefined function|Bad argument|Bad type|core dump|Segmentation' "$out" \
  | grep -vE 'obsolete line in config file|mudlib error handler|PRAGMA_ERROR_CONTEXT|error_handler\(\)|__MUDLIB_ERROR_HANDLER__' \
  | head -60
echo "== transcript saved at: $out =="
exit $rc
