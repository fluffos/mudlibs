#!/usr/bin/env bash
# mkpatch.sh BASE WORK OUT: writes OUT, the unified diff of every file WORK changes or adds against BASE
# (new directories are walked).  Regenerates decompile/fluffos-fixes.patch after an edit in work/:
#   S=~/.cache/lpc-scratch/lym-base
#   PATCH=0 OUT=$S/work REC=$S/rec libs/longyunmeng_binary/rebuild.sh
#   libs/longyunmeng_binary/decompile/mkpatch.sh $S/work libs/longyunmeng_binary/work \
#       libs/longyunmeng_binary/decompile/fluffos-fixes.patch
# Skipped: log/, binaries/, trace_lpcc.json and the player saves under data/login and data/user, except the
# admin seed (data/login/f/fluffos.o, data/user/f/fluffos.o).  A file deleted in WORK is not recorded.
set -uo pipefail
BASE=$1; WORK=$2; OUT=$3
BASE=$(cd "$BASE" && pwd); WORK=$(cd "$WORK" && pwd)
TMPOUT=$(mktemp -p "${LPC_SCRATCH:-$HOME/.cache/lpc-scratch}")
keep() {
  case "$1" in data/login/f/fluffos.o|data/user/f/fluffos.o) return 0;; log|log/*|binaries/*|trace_lpcc.json|data/login/*|data/user/*) return 1;; esac
  return 0
}
emit() {
  local rel=$1
  keep "$rel" || return 0
  local src="$BASE/$rel"; [ -e "$src" ] || src=/dev/null
  diff -u --label "a/$rel" --label "b/$rel" "$src" "$WORK/$rel" >> "$TMPOUT"
}
cd "$WORK"
diff -rq "$BASE" "$WORK" 2>/dev/null | while IFS= read -r line; do
  case "$line" in
    "Files $BASE/"*) rel=${line#"Files $BASE/"}; rel=${rel%% and *};;
    "Only in $WORK: "*|"Only in $WORK/"*) d=${line#"Only in $WORK"}; d=${d#/}; d=${d%%: *}; f=${line##*: }; rel=${d:+$d/}$f;;
    *) continue;;
  esac
  if [ -d "$WORK/$rel" ]; then
    (cd "$WORK" && find "$rel" -type f | sort) | while IFS= read -r r; do emit "$r"; done
  else
    emit "$rel"
  fi
done
mv "$TMPOUT" "$OUT"
echo "patch: $(grep -c '^+++ ' "$OUT") files"
