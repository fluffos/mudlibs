#!/usr/bin/env bash
#
# make_source_zips.sh -- zip each lib's trimmed source tree into a
# standalone downloadable archive, so a visitor can grab ONE game's
# source without cloning the whole (~4GB, full archive history) repo.
#
# Reuses the exact same trim/exclude rules pack_lib_for_web.sh uses to
# stage a lib for WASM packing (see that script's EXCLUDES block) --
# what's playable in-browser is the same tree you get in the zip, just
# without the WASM/JS wrapping. Kept on purpose: .lpc/.h source, in-game
# help/doc text, data/*.o saves (including the pre-seeded admin account
# every README documents) -- see pack_lib_for_web.sh's own comment for
# why those stay.
#
# Usage: scripts/make_source_zips.sh <out_dir> [slug ...]
#   <out_dir>  directory to write <slug>.zip into
#   [slug ...] optional: only zip these specific libs (e.g. from CI's
#              "which libs changed since last publish" list -- see
#              .github/workflows/pages.yml's release-zips step, which
#              reuses build_site.sh's repacked_slugs output so this
#              script doesn't need its own separate change-detection).
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

# Same exclusion set as pack_lib_for_web.sh's EXCLUDES (kept in sync by
# hand -- both scripts trim the same lib tree for two different outputs).
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
