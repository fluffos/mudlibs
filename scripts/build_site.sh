#!/usr/bin/env bash
#
# build_site.sh -- assemble the full GitHub Pages site from the packed libs,
# INCREMENTALLY: only libs whose content changed since the last PUBLISHED
# state are repacked (file_packager over the full ~2.4GB of trees takes a
# while; a one-lib change must not repack all ~90).
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
# Environment:
#   LAST_PUBLISHED_SHA  (optional) commit sha of the tree the LIVE site was
#                  last successfully deployed from (CI reads it off the
#                  pages-state branch -- see .github/workflows/pages.yml).
#                  The commit and its trees must be resolvable in this
#                  clone (CI does a --filter=blob:none fetch of it; tree
#                  hashes need no blobs).  Empty/unset/unresolvable ->
#                  every lib counts as changed (full repack).
#
# Incremental model -- two mechanisms with distinct roles:
#
#   CORRECTNESS (what must be freshly packed) is anchored on the durable
#   LAST_PUBLISHED_SHA marker: a lib counts as changed iff
#   `git rev-parse $LAST_PUBLISHED_SHA:libs/<slug>` differs from
#   `git rev-parse HEAD:libs/<slug>` (or the base is unknown).  Because the
#   marker is only advanced after a deploy actually succeeds, a surviving
#   run always repacks the full cumulative set of libs touched since the
#   live site's real state -- no matter how many intermediate runs were
#   cancelled (cancel-in-progress) and left nothing behind.
#
#   SPEED (skipping the pack of an unchanged lib) additionally requires the
#   actions/cache to hold a bundle whose recorded provenance matches the
#   CURRENT inputs: cache_dir/manifest.json records
#   {driver_tag, packer, libs: {slug: tree}} for the bundles in the cache,
#   where tree = the slug's tree hash at pack time and packer = the git
#   blob sha fingerprint of pack_lib_for_web.sh (+ optional web-shell
#   override page).  A cached bundle is reused iff the lib is unchanged
#   since last publish AND the manifest says the bundle was packed from
#   exactly HEAD's tree with the current driver tag and packer.  A driver
#   release bump or packer edit invalidates every bundle (they embed
#   driver-coupled page glue).  The cache/manifest is thus a pure
#   optimization: evicted, stale, or missing just means slower (up to one
#   full repack), never wrong -- the marker alone decides what MUST be
#   repacked.  Bundles for slugs that no longer exist (or turned noboot)
#   are pruned.
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

# --- 2. resolve the durable last-published base -----------------------------
# (set by CI from the pages-state branch; may be empty on bootstrap or when
# the marker commit is not fetchable -- both degrade to a full repack)
BASE_SHA=${LAST_PUBLISHED_SHA:-}
if [ -n "$BASE_SHA" ]; then
  if git -C "$REPO" cat-file -e "$BASE_SHA^{commit}" 2>/dev/null; then
    echo "== last published commit: $BASE_SHA"
  else
    echo "warning: LAST_PUBLISHED_SHA=$BASE_SHA is not a resolvable commit" \
         "in this clone; treating every lib as changed (full repack)" >&2
    BASE_SHA=""
  fi
else
  echo "== no last-published marker: treating every lib as changed (full repack)"
fi

# --- 3. load the cache manifest (provenance of the cached bundles) ----------
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

# Cache bundles are only reusable at all when they were packed with the
# current driver release and packer script (a bump to either changes every
# bundle's content/page glue).
CACHE_OK=1
if [ "$OLD_TAG" != "$DRIVER_TAG" ] || [ "$OLD_PACKER" != "$PACKER_FP" ]; then
  CACHE_OK=0
  echo "== driver tag or packer differs from cached bundles" \
       "($OLD_TAG -> $DRIVER_TAG, packer ${OLD_PACKER:0:12} ->" \
       "${PACKER_FP:0:12}): cache unusable, full repack"
fi

# --- 4. repack libs changed since last publish (or lacking a valid bundle) --
REPACKED=0
REUSED=0
NEW_MANIFEST_LIBS=$(mktemp)
trap 'rm -f "$NEW_MANIFEST_LIBS"' EXIT
for slug in $SLUGS; do
  tree=$(git -C "$REPO" rev-parse "HEAD:libs/$slug")
  printf '%s\t%s\n' "$slug" "$tree" >> "$NEW_MANIFEST_LIBS"
  # correctness anchor: unchanged since the last successful deploy?
  base_tree=""
  if [ -n "$BASE_SHA" ]; then
    base_tree=$(git -C "$REPO" rev-parse -q --verify \
        "$BASE_SHA:libs/$slug" 2>/dev/null || true)
  fi
  if [ -n "$base_tree" ] && [ "$base_tree" = "$tree" ] \
     && [ "$CACHE_OK" = 1 ] && [ "${OLDTREE[$slug]:-}" = "$tree" ] \
     && [ -f "$CACHE_DIR/packed/$slug/mudlib.data" ] \
     && [ -f "$CACHE_DIR/packed/$slug/index.html" ]; then
    REUSED=$((REUSED + 1))
    continue
  fi
  if [ -z "$base_tree" ] || [ "$base_tree" != "$tree" ]; then
    reason="changed since last publish"
  else
    reason="no valid cached bundle"
  fi
  echo "== packing $slug (tree ${tree:0:12}: $reason)"
  rm -rf "$CACHE_DIR/packed/$slug"
  "$SELF_DIR/pack_lib_for_web.sh" "$slug" "$RELEASE_DIR" "$RELEASE_DIR" \
      "$CACHE_DIR/packed/$slug"
  REPACKED=$((REPACKED + 1))
done

# --- 5. prune bundles whose slug is gone / no longer packable ---------------
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

# --- 6. write the new manifest (records provenance of the cache contents) ---
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

# --- 7. assemble the site ----------------------------------------------------
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

# --- 8. summary --------------------------------------------------------------
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
