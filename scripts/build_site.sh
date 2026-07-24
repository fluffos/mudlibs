#!/usr/bin/env bash
#
# build_site.sh -- assemble the full GitHub Pages site from the packed libs,
# INCREMENTALLY: only libs whose content changed since the last run are
# repacked (file_packager over the full ~2.4GB of trees takes a while; a
# one-lib change must not repack all ~90).
#
# Usage:
#   scripts/build_site.sh <release_dir> <driver_tag> <cache_dir> <site_dir>
#
#   <release_dir>  extracted fluffos-<ver>-wasm.zip (fluffos.js/.wasm,
#                  index.html, telnet.js, vendor/)
#   <driver_tag>   the release tag those files came from (cache key part)
#   <cache_dir>    persistent dir (actions/cache) holding packed/<slug>/
#                  bundles + manifest.json from previous runs
#   <site_dir>     output dir for the assembled site (recreated every run)
#
# Incremental model:
#   cache_dir/manifest.json records {driver_tag, packer, libs: {slug: tree}}
#   where tree = `git rev-parse HEAD:libs/<slug>` (works in a fetch-depth:1
#   shallow clone) and packer = the git blob sha of pack_lib_for_web.sh.
#   A lib is repacked iff its tree hash changed, its bundle is missing, or
#   the driver tag / packer changed (bundles embed driver-coupled page glue,
#   so a driver bump repacks everything).  Bundles for slugs that no longer
#   exist (or turned noboot) are pruned.  A cache miss just means one slow
#   full repack, never a failure.
#
# Outputs (for CI): appends "repacked=<n>" and "changed=<n>" to
# $GITHUB_OUTPUT when set (changed = repacked + pruned, i.e. whether the
# cache is worth re-saving).

set -euo pipefail

SELF_DIR=$(cd "$(dirname "$0")" && pwd)
REPO=$(cd "$SELF_DIR/.." && pwd)

if [ $# -ne 4 ]; then
  echo "usage: $0 <release_dir> <driver_tag> <cache_dir> <site_dir>" >&2
  exit 2
fi
RELEASE_DIR=$(cd "$1" && pwd)
DRIVER_TAG=$2
CACHE_DIR=$3
SITE_DIR=$4

for f in fluffos.js fluffos.wasm index.html telnet.js; do
  [ -f "$RELEASE_DIR/$f" ] || { echo "error: $RELEASE_DIR/$f missing" >&2; exit 1; }
done
[ -d "$RELEASE_DIR/vendor" ] || { echo "error: $RELEASE_DIR/vendor missing" >&2; exit 1; }

mkdir -p "$CACHE_DIR/packed"
MANIFEST="$CACHE_DIR/manifest.json"

# --- 1. derive per-lib WASM status (also writes scripts/wasm_status.json) ---
python3 "$SELF_DIR/gen_site_index.py" --out "$CACHE_DIR/index-staging"

# Packable slugs: everything except noboot (a noboot lib gets no link on the
# index, so shipping its ~MBs of data would be pure waste).
SLUGS=$(python3 -c "
import json
d = json.load(open('$REPO/scripts/wasm_status.json'))
print('\n'.join(sorted(s for s, i in d['libs'].items()
                       if i['status'] != 'noboot')))")

# blob sha of the WORKING copy (equals the committed blob sha when clean,
# and correctly invalidates the cache on local/CI edits before commit).
# The optional web-shell override page is an input of the packed bundles
# too (pack_lib_for_web.sh uses it as the page template when present), so
# it is part of the fingerprint: adding/editing/removing it repacks all.
PACKER_FP=$(git -C "$REPO" hash-object scripts/pack_lib_for_web.sh)
if [ -f "$SELF_DIR/web_shell_override/index.html" ]; then
  PACKER_FP="$PACKER_FP+$(git -C "$REPO" hash-object scripts/web_shell_override/index.html)"
fi

# --- 2. load the previous manifest ------------------------------------------
declare -A OLDTREE
OLD_TAG=""
OLD_PACKER=""
if [ -f "$MANIFEST" ]; then
  while IFS=$'\t' read -r k v; do
    case "$k" in
      driver_tag) OLD_TAG=$v ;;
      packer) OLD_PACKER=$v ;;
      lib) OLDTREE[${v%% *}]=${v#* } ;;
    esac
  done < <(python3 -c "
import json
try:
    m = json.load(open('$MANIFEST'))
except Exception:
    m = {}
print('driver_tag\t' + m.get('driver_tag', ''))
print('packer\t' + m.get('packer', ''))
for s, t in m.get('libs', {}).items():
    print('lib\t%s %s' % (s, t))")
fi

FULL_REPACK=0
if [ "$OLD_TAG" != "$DRIVER_TAG" ] || [ "$OLD_PACKER" != "$PACKER_FP" ]; then
  FULL_REPACK=1
  echo "== driver tag or packer changed ($OLD_TAG -> $DRIVER_TAG," \
       "packer ${OLD_PACKER:0:12} -> ${PACKER_FP:0:12}): full repack"
fi

# --- 3. repack changed/missing libs -----------------------------------------
REPACKED=0
REUSED=0
NEW_MANIFEST_LIBS=$(mktemp)
trap 'rm -f "$NEW_MANIFEST_LIBS"' EXIT
for slug in $SLUGS; do
  tree=$(git -C "$REPO" rev-parse "HEAD:libs/$slug")
  printf '%s\t%s\n' "$slug" "$tree" >> "$NEW_MANIFEST_LIBS"
  if [ "$FULL_REPACK" = 0 ] && [ "${OLDTREE[$slug]:-}" = "$tree" ] \
     && [ -f "$CACHE_DIR/packed/$slug/mudlib.data" ] \
     && [ -f "$CACHE_DIR/packed/$slug/index.html" ]; then
    REUSED=$((REUSED + 1))
    continue
  fi
  echo "== packing $slug (tree ${tree:0:12})"
  rm -rf "$CACHE_DIR/packed/$slug"
  "$SELF_DIR/pack_lib_for_web.sh" "$slug" "$RELEASE_DIR" "$RELEASE_DIR" \
      "$CACHE_DIR/packed/$slug"
  REPACKED=$((REPACKED + 1))
done

# --- 4. prune bundles whose slug is gone / no longer packable ---------------
PRUNED=0
for d in "$CACHE_DIR"/packed/*/; do
  [ -d "$d" ] || continue
  s=$(basename "$d")
  if ! cut -f1 "$NEW_MANIFEST_LIBS" | grep -qx "$s"; then
    echo "== pruning stale bundle $s"
    rm -rf "$d"
    PRUNED=$((PRUNED + 1))
  fi
done

# --- 5. write the new manifest ----------------------------------------------
# (the libs list is passed as a file argument -- `python3 -` already consumes
# stdin for the script itself, so it cannot double as the data channel)
python3 - "$MANIFEST" "$DRIVER_TAG" "$PACKER_FP" "$NEW_MANIFEST_LIBS" <<'PYEOF'
import json, sys
libs = {}
for line in open(sys.argv[4]):
    slug, tree = line.rstrip('\n').split('\t')
    libs[slug] = tree
out = {'driver_tag': sys.argv[2], 'packer': sys.argv[3], 'libs': libs}
json.dump(out, open(sys.argv[1], 'w'), indent=1, sort_keys=True)
PYEOF

# --- 6. assemble the site ----------------------------------------------------
rm -rf "$SITE_DIR"
mkdir -p "$SITE_DIR/_driver"
cp "$RELEASE_DIR/fluffos.js" "$RELEASE_DIR/fluffos.wasm" \
   "$RELEASE_DIR/telnet.js" "$SITE_DIR/_driver/"
cp -r "$RELEASE_DIR/vendor" "$SITE_DIR/_driver/"
for slug in $SLUGS; do
  # hardlink when possible (same fs), fall back to a copy
  cp -al "$CACHE_DIR/packed/$slug" "$SITE_DIR/$slug" 2>/dev/null \
    || cp -a "$CACHE_DIR/packed/$slug" "$SITE_DIR/$slug"
done
cp "$CACHE_DIR/index-staging/index.html" "$SITE_DIR/index.html"
touch "$SITE_DIR/.nojekyll"

# --- 7. summary --------------------------------------------------------------
echo
echo "== per-lib packed sizes =="
du -sm "$SITE_DIR"/*/ | sort -n
echo "== totals =="
du -sh "$SITE_DIR"
echo "reused=$REUSED repacked=$REPACKED pruned=$PRUNED"
if [ -n "${GITHUB_OUTPUT:-}" ]; then
  {
    echo "repacked=$REPACKED"
    echo "changed=$((REPACKED + PRUNED))"
  } >> "$GITHUB_OUTPUT"
fi
