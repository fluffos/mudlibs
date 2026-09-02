#!/usr/bin/env bash
#
# build_site.sh -- assemble the full GitHub Pages site from the packed libs,
# INCREMENTALLY: only libs whose content changed since the last PUBLISHED
# state get a fresh zip (see scripts/pack_lib_zip.sh -- real rsync+zip work
# over the lib's tree; a one-lib change must not re-zip all ~250).
#
# Usage:
#   scripts/build_site.sh <release_dir> <cache_dir> <site_dir>
#
#   <release_dir>  extracted fluffos-<ver>-wasm.zip (fluffos.js/.wasm,
#                  index.html, telnet.js, vendor/) -- copied wholesale into
#                  the shared _driver/ dir on every run regardless of
#                  caching, so a driver release bump needs no per-lib cache
#                  invalidation at all (see below)
#   <cache_dir>    persistent dir (actions/cache) holding packed/<slug>/
#                  zips + manifest.json from previous runs
#   <site_dir>     output dir for the assembled site (recreated every run)
#
# Environment:
#   LAST_PUBLISHED_SHA  (optional) commit sha of the tree the LIVE site was
#                  last successfully deployed from (CI reads it off the
#                  pages-state branch -- see .github/workflows/pages.yml).
#                  The commit and its trees must be resolvable in this
#                  clone (CI does a --filter=blob:none fetch of it; tree
#                  hashes need no blobs).  Empty/unset/unresolvable ->
#                  every lib counts as changed (full re-zip).
#
# Incremental model -- two mechanisms with distinct roles:
#
#   CORRECTNESS (what must be freshly zipped) is anchored on the durable
#   LAST_PUBLISHED_SHA marker: a lib counts as changed iff
#   `git rev-parse $LAST_PUBLISHED_SHA:libs/<slug>` differs from
#   `git rev-parse HEAD:libs/<slug>` (or the base is unknown).  Because the
#   marker is only advanced after a deploy actually succeeds, a surviving
#   run always re-zips the full cumulative set of libs touched since the
#   live site's real state -- no matter how many intermediate runs were
#   cancelled (cancel-in-progress) and left nothing behind.
#
#   SPEED (skipping the zip of an unchanged lib) additionally requires the
#   actions/cache to hold a zip whose recorded provenance matches the
#   CURRENT inputs: cache_dir/manifest.json records {packer, libs: {slug:
#   tree}} for the zips in the cache, where tree = the slug's tree hash at
#   zip time and packer = the git blob sha fingerprint of
#   scripts/pack_lib_zip.sh + scripts/make_source_zips.sh (the only two
#   inputs that affect a zip's actual content -- editing either invalidates
#   every cached zip). A cached zip is reused iff the lib is unchanged since
#   last publish AND the manifest says it was zipped from exactly HEAD's
#   tree with the current packer fingerprint.  The cache/manifest is thus a
#   pure optimization: evicted, stale, or missing just means slower (up to
#   one full re-zip), never wrong -- the marker alone decides what MUST be
#   re-zipped.  Zips for slugs that no longer exist (or turned noboot) are
#   pruned.
#
#   Deliberately NOT part of this cache key: the driver release tag, or
#   anything under scripts/web_shell_override/ (the play-page template and
#   its shared client scripts).  Neither affects a zip's content at all --
#   see write_play_page.sh, run unconditionally for every packable lib on
#   every build (cheap template substitution, no rsync/zip work) -- so a
#   driver bump or a shell-page edit takes effect site-wide without
#   invalidating a single cached zip.  (This split exists because a
#   web_shell_override/index.html edit used to sit in the SAME fingerprint
#   as the zip step and forced a full ~250-lib re-zip for a pure HTML/JS
#   change -- see AGENTS.md's account of that incident.)
#
# The cache dir also carries lib-commits.json -- slug -> the last commit
# that actually changed libs/<slug> (shown on the index cards), maintained
# by scripts/update_lib_commits.py via the GitHub commits API because the
# shallow CI clone has no usable history.  Same durable-anchor/disposable-
# cache split as above: entries self-validate against the slug's current
# tree hash, so a lost or evicted cache only costs API re-queries, never
# wrong data (see that script's header for the full model).
#
# Outputs (for CI): appends "repacked=<n>", "changed=<n>" and
# "repacked_slugs=<space-separated slugs>" to $GITHUB_OUTPUT when set
# (changed = repacked + pruned, i.e. whether the cache is worth re-saving;
# a lib-commits.json refresh alone deliberately does NOT count -- re-saving
# the cache to persist a ~10KB mapping costs more than the API re-queries
# it would save. repacked_slugs is currently unconsumed by the workflow --
# there used to be a boot smoke test keyed off it, removed because it kept
# failing CI on slow-under-node-timeout boots that don't reflect the real
# browser deploy; left here in case a future, less timing-sensitive check
# wants it).

set -euo pipefail

SELF_DIR=$(cd "$(dirname "$0")" && pwd)
REPO=$(cd "$SELF_DIR/.." && pwd)

if [ $# -ne 3 ]; then
  echo "usage: $0 <release_dir> <cache_dir> <site_dir>" >&2
  exit 2
fi
RELEASE_DIR=$(cd "$1" && pwd)
CACHE_DIR=$2
SITE_DIR=$3

for f in fluffos.js fluffos.wasm index.html telnet.js; do
  [ -f "$RELEASE_DIR/$f" ] || { echo "error: $RELEASE_DIR/$f missing" >&2; exit 1; }
done
[ -d "$RELEASE_DIR/vendor" ] || { echo "error: $RELEASE_DIR/vendor missing" >&2; exit 1; }

mkdir -p "$CACHE_DIR/packed"
MANIFEST="$CACHE_DIR/manifest.json"

# --- 1. derive per-lib WASM status (also writes scripts/wasm_status.json) ---
# (this early run exists for the status JSON, which the slug list below
# needs; the index it renders is provisional -- step 7 re-renders it with
# the freshly updated per-lib last-changed mapping)
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
# Only the two scripts that actually determine a zip's contents -- NOT the
# web-shell page/scripts, see the header comment above.
PACKER_FP="$(git -C "$REPO" hash-object scripts/pack_lib_zip.sh)+$(git -C "$REPO" hash-object scripts/make_source_zips.sh)"

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

# --- 3. load the cache manifest (provenance of the cached zips) ------------
declare -A OLDTREE
OLD_PACKER=""
if [ -f "$MANIFEST" ]; then
  while IFS=$'\t' read -r k v; do
    case "$k" in
      packer) OLD_PACKER=$v ;;
      lib) OLDTREE[${v%% *}]=${v#* } ;;
    esac
  done < <(python3 -c "
import json
try:
    m = json.load(open('$MANIFEST'))
except Exception:
    m = {}
print('packer\t' + m.get('packer', ''))
for s, t in m.get('libs', {}).items():
    print('lib\t%s %s' % (s, t))")
fi

# Cached zips are only reusable at all when they were built with the
# current packer fingerprint (an edit to either script changes every zip's
# actual content).
CACHE_OK=1
if [ "$OLD_PACKER" != "$PACKER_FP" ]; then
  CACHE_OK=0
  echo "== packer differs from cached zips (${OLD_PACKER:0:12} ->" \
       "${PACKER_FP:0:12}): cache unusable, full re-zip"
fi

# --- 4. re-zip libs changed since last publish (or lacking a valid cached zip)
REPACKED=0
REPACKED_SLUGS=""
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
     && [ -f "$CACHE_DIR/packed/$slug/$slug.zip" ]; then
    REUSED=$((REUSED + 1))
    continue
  fi
  if [ -z "$base_tree" ] || [ "$base_tree" != "$tree" ]; then
    reason="changed since last publish"
  else
    reason="no valid cached zip"
  fi
  echo "== zipping $slug (tree ${tree:0:12}: $reason)"
  rm -rf "$CACHE_DIR/packed/$slug"
  "$SELF_DIR/pack_lib_zip.sh" "$slug" "$CACHE_DIR/packed/$slug"
  REPACKED=$((REPACKED + 1))
  REPACKED_SLUGS="$REPACKED_SLUGS$slug "
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
python3 - "$MANIFEST" "$PACKER_FP" "$NEW_MANIFEST_LIBS" <<'PYEOF'
import json, sys
libs = {}
for line in open(sys.argv[3]):
    slug, tree = line.rstrip('\n').split('\t')
    libs[slug] = tree
out = {'packer': sys.argv[2], 'libs': libs}
json.dump(out, open(sys.argv[1], 'w'), indent=1, sort_keys=True)
PYEOF

# --- 7. per-lib "last changed" mapping + final index render -----------------
# Refresh lib-commits.json (slug -> last commit that changed libs/<slug>,
# via the GitHub commits API pinned to HEAD -- see update_lib_commits.py's
# header for why the shallow clone forces this and why a lost cache is
# harmless), then re-render the index with that info on the cards.  The
# update never fails the build: last-changed info is cosmetic, and a card
# without it beats a blocked deploy.
python3 "$SELF_DIR/update_lib_commits.py" \
    --mapping "$CACHE_DIR/lib-commits.json" \
    --head "$(git -C "$REPO" rev-parse HEAD)"
python3 "$SELF_DIR/gen_site_index.py" --out "$CACHE_DIR/index-staging" \
    --commits "$CACHE_DIR/lib-commits.json"

# --- 8. assemble the site ----------------------------------------------------
rm -rf "$SITE_DIR"
mkdir -p "$SITE_DIR/_driver"
cp "$RELEASE_DIR/fluffos.js" "$RELEASE_DIR/fluffos.wasm" \
   "$RELEASE_DIR/telnet.js" "$SITE_DIR/_driver/"
cp -r "$RELEASE_DIR/vendor" "$SITE_DIR/_driver/"
# Shared client scripts every play.html references as ../_driver/*.js --
# one copy for the whole site rather than duplicated into every lib dir
# (they're byte-identical across libs; only fluffos-boot.js is per-lib).
# See scripts/web_shell_override/zip-loader.js's header for the mechanism.
cp "$SELF_DIR/web_shell_override"/{persist,save-export,zip-loader,zip-worker,tab-lock,sync-hook}.js \
   "$SITE_DIR/_driver/"
for slug in $SLUGS; do
  # hardlink when possible (same fs), fall back to a copy. This brings in
  # the cached zip (+README/NOTES.md) from pack_lib_zip.sh.
  cp -al "$CACHE_DIR/packed/$slug" "$SITE_DIR/$slug" 2>/dev/null \
    || cp -a "$CACHE_DIR/packed/$slug" "$SITE_DIR/$slug"
  # play.html + fluffos-boot.js: written fresh for EVERY packable lib on
  # EVERY run, deliberately uncached -- see this file's header and
  # write_play_page.sh's own header for why.
  "$SELF_DIR/write_play_page.sh" "$slug" "$RELEASE_DIR" "$RELEASE_DIR" "$SITE_DIR/$slug"
  # Server-rendered landing page (full description + README/NOTES.md,
  # "Play Now" link to play.html) -- see gen_site_index.py's
  # render_lib_page. This, not the WASM page, is what /{slug}/ serves;
  # it's what makes the game's description/notes crawlable and defers
  # the actual driver/data download until the visitor clicks Play.
  cp "$CACHE_DIR/index-staging/$slug/index.html" "$SITE_DIR/$slug/index.html"
done
for f in index.html robots.txt sitemap.xml llms.txt llm.txt llms-full.txt games.json; do
  cp "$CACHE_DIR/index-staging/$f" "$SITE_DIR/$f"
done
# Vendored (not CDN) classless CSS framework every page links as
# /assets/pico.min.css -- see gen_site_index.py's main() for why it's
# self-hosted rather than loaded from a CDN.
cp -r "$CACHE_DIR/index-staging/assets" "$SITE_DIR/assets"
mkdir -p "$SITE_DIR/en" "$SITE_DIR/cn"
cp "$CACHE_DIR/index-staging/en/index.html" "$SITE_DIR/en/index.html"
cp "$CACHE_DIR/index-staging/cn/index.html" "$SITE_DIR/cn/index.html"
touch "$SITE_DIR/.nojekyll"

# --- 9. summary --------------------------------------------------------------
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
    echo "repacked_slugs=${REPACKED_SLUGS% }"
  } >> "$GITHUB_OUTPUT"
fi
