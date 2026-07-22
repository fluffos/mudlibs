#!/usr/bin/env bash
# Compile-check every .lpc/.c file in a mudlib's work/ dir with lpcc,
# using the debug driver build (better diagnostics/asserts).
#
# Usage: lpcc_check.sh libs/<slug>/config.fluffos libs/<slug>/work [pattern]
#
# Each file is compiled through a FRESH lpcc invocation (full VM boot: master
# + simul_efun get loaded every time, exactly like the real driver would) so
# this is accurate but not fast -- expect ~0.1-0.5s per file. Output: one
# PASS/FAIL line per file to stdout, full lpcc stderr for failures appended
# to <work>/../lpcc_fail.log.
set -uo pipefail

LPCC=~/src/fluffos/build-debug/src/lpcc
CONFIG="$1"
WORK="$2"
PATTERN="${3:-*.lpc}"

if [[ ! -x "$LPCC" ]]; then
  echo "lpcc not found/executable at $LPCC -- build it first (make -C ~/src/fluffos/build-debug lpcc)" >&2
  exit 1
fi
if [[ ! -f "$CONFIG" ]]; then
  echo "config file not found: $CONFIG" >&2
  exit 1
fi

FAILLOG="$(dirname "$WORK")/lpcc_fail.log"
: > "$FAILLOG"

pass=0
fail=0
total=0

while IFS= read -r -d '' f; do
  total=$((total + 1))
  # object path relative to mudlib root, leading slash, extension-less so
  # resolution prefers .lpc (matches what the driver itself would load).
  rel="${f#"$WORK"}"
  rel="${rel%.lpc}"
  rel="${rel%.c}"
  [[ "$rel" == /* ]] || rel="/$rel"

  out=$("$LPCC" "$CONFIG" "$rel" 2>&1)
  rc=$?
  if [[ $rc -eq 0 ]]; then
    pass=$((pass + 1))
    echo "PASS $rel"
  else
    fail=$((fail + 1))
    echo "FAIL $rel"
    {
      echo "===== $rel ====="
      echo "$out"
      echo
    } >> "$FAILLOG"
  fi
done < <(find "$WORK" -type f \( -name "*.lpc" -o -name "*.c" \) -print0)

echo "----"
echo "total=$total pass=$pass fail=$fail"
echo "failures logged to $FAILLOG"
