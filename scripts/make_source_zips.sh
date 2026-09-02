#!/usr/bin/env bash
#
# make_source_zips.sh -- zip each lib's trimmed source tree into a
# standalone archive. This is THE definitive trim/exclude ruleset for what
# ships in a lib's zip (see the EXCLUDES block below) -- there is no
# separate WASM-packing trim step any more: the exact same zip this script
# produces is what a visitor downloads via the site's "Download ZIP" link
# AND what scripts/web_shell_override/zip-loader.js fetches and unpacks
# into the driver's in-memory filesystem at play time (see
# scripts/pack_lib_zip.sh, AGENTS.md §1.6). Kept on purpose: .lpc/.h
# source, in-game help/doc text, data/*.o saves (including the pre-seeded
# admin account every README documents).
#
# Usage: scripts/make_source_zips.sh <out_dir> [slug ...]
#   <out_dir>  directory to write <slug>.zip into
#   [slug ...] optional: only zip these specific libs (e.g. from
#              build_site.sh's "changed since last publish, or no valid
#              cached zip" list -- see pack_lib_zip.sh).
#              Omit to zip every packable lib (the manual/full-refresh
#              case -- same "has config.fluffos" gate gen_site_index.py
#              uses, slug list from wasm_status.json).
#
# Requires: rsync, zip, python3.

set -euo pipefail

SELF_DIR=$(cd "$(dirname "$0")" && pwd)
REPO_ROOT=$(cd "$SELF_DIR/.." && pwd)

if [ $# -lt 1 ]; then
  echo "usage: $0 <out_dir> [slug ...]" >&2
  exit 2
fi
OUT_DIR=$1
shift
mkdir -p "$OUT_DIR"

if [ $# -gt 0 ]; then
  SLUGS="$*"
else
  SLUGS=$(python3 -c "
import json
d = json.load(open('$REPO_ROOT/scripts/wasm_status.json'))
print('\n'.join(sorted(d['libs'].keys())))")
fi

# The one trim/exclude ruleset for what ships in every lib's zip (see
# this file's header) -- there is no separate WASM-side ruleset any more.
EXCLUDES=(
  --exclude='/log/'
  --exclude='/www/' --exclude='/temp/' --exclude='/backup/'
  --exclude='fluffos64/'
  --exclude='*.bak' --exclude='*.b'
  --exclude='*.exe' --exclude='*.dll'
  --exclude='*.exe1' --exclude='*.exe2'
  --exclude='*.zip' --exclude='*.rar' --exclude='*.gz' --exclude='*.7z'
  --exclude='core.*' --exclude='/core'
  --exclude='*.5555' --exclude='*.6666' --exclude='*.3333' --exclude='*.8888'
)

STAGE=$(mktemp -d)
trap 'rm -rf "$STAGE"' EXIT

n=0
for slug in $SLUGS; do
  lib="$REPO_ROOT/libs/$slug"
  [ -f "$lib/config.fluffos" ] || continue

  rm -rf "$STAGE/$slug"
  mkdir -p "$STAGE/$slug"
  rsync -a "${EXCLUDES[@]}" "$lib/work/" "$STAGE/$slug/work/"
  cp "$lib/config.fluffos" "$STAGE/$slug/"
  for extra in README.md NOTES.md meta.json; do
    [ -f "$lib/$extra" ] && cp "$lib/$extra" "$STAGE/$slug/"
  done

  ( cd "$STAGE" && zip -q -r -X "$OUT_DIR/$slug.zip" "$slug" )
  rm -rf "$STAGE/$slug"
  n=$((n + 1))
done

echo "wrote $n source zips to $OUT_DIR"
du -sh "$OUT_DIR" 2>/dev/null | tail -1
