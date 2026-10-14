#!/usr/bin/env bash
#
# pristine_tree.sh -- build a throwaway copy of one lib exactly as a fresh
# clone (or the site zip) would see it: tracked files only, no leftovers from
# earlier boots, its own mudlib directory and port, and a log/ dir (the site
# loader creates one too).  Use it for the first session of a §10.7 pass
# (docs/kb/08-formatter-testing.md): the working tree hides missing-directory
# bugs (docs/kb/06-runtime-classes-2.md §7.203).
#
# Usage: [REV=<commit>] scripts/pristine_tree.sh <slug> <port> [dest_dir]
#   dest_dir defaults to ${LPC_SCRATCH:-$HOME/.cache/lpc-scratch}/pristine-<slug>.  REV (default HEAD) builds the tree
#   from an older commit, e.g. the baseline for a before/after oracle run
#   (scripts/ds_oracle.py).  Prints the driver command; it
#   does not start anything, so the caller owns (and kills, by PID) the driver:
#     cd <dest>/libs/<slug> && setsid nohup <driver> config.fluffos > out 2>&1 &
#
# Only vendored libs (work/ tracked in this repo) are supported; submodule and
# upstream-hosted trees need their patches applied first.

set -euo pipefail

mkdir -p "${LPC_SCRATCH:-$HOME/.cache/lpc-scratch}"
if [ $# -lt 2 ]; then
  echo "usage: $0 <slug> <port> [dest_dir]" >&2
  exit 2
fi
SLUG=$1
PORT=$2
SELF_DIR=$(cd "$(dirname "$0")" && pwd)
REPO_ROOT=$(cd "$SELF_DIR/.." && pwd)
DEST=${3:-${LPC_SCRATCH:-$HOME/.cache/lpc-scratch}/pristine-$SLUG}
LIB="libs/$SLUG"

[ -f "$REPO_ROOT/$LIB/config.fluffos" ] || { echo "error: $LIB/config.fluffos not found" >&2; exit 1; }
if [ -n "$(git -C "$REPO_ROOT" ls-files -s -- "$LIB/work" | awk '$1==160000' | head -1)" ]; then
  echo "error: $LIB/work is a submodule; apply its patches/overlay by hand" >&2
  exit 1
fi
case "$DEST" in
  ${LPC_SCRATCH:-$HOME/.cache/lpc-scratch}/*|/var/tmp/*) ;;
  *) echo "error: dest_dir must be under ${LPC_SCRATCH:-$HOME/.cache/lpc-scratch} or /var/tmp (got $DEST)" >&2; exit 1 ;;
esac

# Refuse to reuse a directory that is not a previous pristine tree.
if [ -e "$DEST" ] && [ ! -f "$DEST/.pristine-tree" ]; then
  echo "error: $DEST exists and is not a pristine tree" >&2
  exit 1
fi
rm -rf -- "$DEST"
mkdir -p "$DEST"
git -C "$REPO_ROOT" archive "${REV:-HEAD}" "$LIB/work" "$LIB/config.fluffos" | tar -x -C "$DEST"
touch "$DEST/.pristine-tree"
# The site zip lays libs/<slug>/overlay/ over work/ (make_source_zips.sh); so does this tree.  oxidus keeps the
# driver headers its global.h includes there, and nothing of it compiles without them.
if git -C "$REPO_ROOT" cat-file -e "${REV:-HEAD}:$LIB/overlay" 2>/dev/null; then
  git -C "$REPO_ROOT" archive "${REV:-HEAD}" "$LIB/overlay" | tar -x -C "$DEST"
  rsync -a "$DEST/$LIB/overlay/" "$DEST/$LIB/work/"
fi

CFG="$DEST/$LIB/config.fluffos"
sed -i "s|^mudlib directory.*|mudlib directory : $DEST/$LIB/work|; s|^port number.*|port number : $PORT|" "$CFG"
mkdir -p "$DEST/$LIB/work/log"

# The site loader also recreates every dir wasm_keep_dirs.txt records for this
# slug (the zip carries none of them); do the same so this tree is what a
# visitor's browser sees, not just what a clone sees.
if [ -f "$REPO_ROOT/scripts/wasm_keep_dirs.txt" ]; then
  awk -F'\t' -v s="$SLUG" '$1==s {print $2}' "$REPO_ROOT/scripts/wasm_keep_dirs.txt" |
    while IFS= read -r d; do
      case "$d" in ..*|*/../*|/*) continue ;; esac
      mkdir -p -- "$DEST/$LIB/work/$d"
    done
fi

echo "pristine tree: $DEST/$LIB   port: $PORT"
echo "start: cd $DEST/$LIB && setsid nohup \$HOME/src/fluffos/build-debug/src/driver config.fluffos > ${LPC_SCRATCH:-$HOME/.cache/lpc-scratch}/pristine-$SLUG.out 2>&1 &"
echo "other ports in config.fluffos (ftp/http/i3) may collide with a running copy of the same lib"
