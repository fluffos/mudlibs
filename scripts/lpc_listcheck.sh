#!/usr/bin/env bash
# scripts/lpc_listcheck.sh SLUG LISTFILE [CHUNK]
#
# Load every object of LISTFILE (one `/path/obj.lpc` per line) at HEAD and in the working tree of a vendored lib, CHUNK
# (default 700) objects per VM boot, and print the PASS / FAIL counts of both.  Outputs: /tmp/listchunk-SLUG.{head,work}.out
# (`===== /obj.lpc =====` blocks with the driver's messages, then `PASS` / `FAIL /obj.lpc`); compare them with
# scripts/lpc_load_diff.py.  `REV=<commit> scripts/lpc_listcheck.sh ...` makes the first run use an older commit (a change that is
# already committed has no diff against HEAD).  One VM nests at most about 1000 `call_out(f, 0)` rooms before every later object prints
# `Nesting call_out(0) level limit exceeded`: hence the chunks.  Needs the debug driver (~/src/fluffos/build-debug/src/lpcc).
# A PASS at HEAD can be spurious when an earlier object of the batch left a half-built one loaded (docs/kb/08-formatter-testing.md
# section 10.13): load a surprising regression alone before believing it.
set -uo pipefail
SLUG=$1; LIST=$2; CHUNK=${3:-700}
REPO=$(cd "$(dirname "$0")/.." && pwd)
cd "$REPO"
DEST=/tmp/listchunk-$SLUG
rm -rf "$DEST"
scripts/pristine_tree.sh "$SLUG" 45993 "$DEST" > /dev/null
mkdir -p "$DEST/libs/$SLUG/work/log"
N=$(wc -l < "$LIST")
rm -f /tmp/listchunk-$SLUG.part.*
split -l "$CHUNK" -d -a 3 "$LIST" /tmp/listchunk-$SLUG.part.
run() {
  : > /tmp/listchunk-$SLUG.$1.out
  for p in /tmp/listchunk-$SLUG.part.*; do
    (cd "$DEST/libs/$SLUG" && timeout 900 "${LPCC:-$HOME/src/fluffos/build-debug/src/lpcc}" --batch config.fluffos < "$p" >> /tmp/listchunk-$SLUG.$1.out 2>&1)
  done
  echo "$1: $(grep -a -c '^PASS' /tmp/listchunk-$SLUG.$1.out) PASS, $(grep -a -c '^FAIL' /tmp/listchunk-$SLUG.$1.out) FAIL of $N"
}
run head
python3 - "$SLUG" "$DEST" << 'PY'
import sys
sys.path.insert(0, "scripts")
import lpc_warnings as lw
print("synced", lw.sync_changes(sys.argv[1], f"{sys.argv[2]}/libs/{sys.argv[1]}"), "files")
PY
run work
echo done > /tmp/listchunk-$SLUG.done
