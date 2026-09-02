#!/usr/bin/env bash
#
# pack_lib_zip.sh -- produce the ONE trimmed source zip a lib needs for both
# the site's "Download ZIP" link and play-time loading (see
# scripts/web_shell_override/zip-loader.js) -- a thin wrapper around
# scripts/make_source_zips.sh that also copies README.md/NOTES.md alongside
# it, for play.html's Info tab.
#
# Usage: scripts/pack_lib_zip.sh <slug> <out_dir>
#
# Deliberately separate from write_play_page.sh: this is the expensive-ish
# half (real rsync+zip work over the lib's tree) that build_site.sh caches,
# keyed on the lib's own tree hash -- unlike the play page (cheap template
# substitution), it must NOT be invalidated by a scripts/web_shell_override/
# edit, or every lib's zip gets needlessly rebuilt on every shell-page tweak
# (see AGENTS.md's account of the incident this split fixes).

set -euo pipefail

SELF_DIR=$(cd "$(dirname "$0")" && pwd)
REPO_ROOT=$(cd "$SELF_DIR/.." && pwd)

if [ $# -ne 2 ]; then
  echo "usage: $0 <slug> <out_dir>" >&2
  exit 2
fi
SLUG=$1
OUT=$2
LIB="$REPO_ROOT/libs/$SLUG"

[ -f "$LIB/config.fluffos" ] || { echo "error: $LIB/config.fluffos not found" >&2; exit 1; }
[ -d "$LIB/work" ] || { echo "error: $LIB/work not found" >&2; exit 1; }

mkdir -p "$OUT"
"$SELF_DIR/make_source_zips.sh" "$OUT" "$SLUG" >/dev/null
[ -f "$OUT/$SLUG.zip" ] || { echo "error: make_source_zips.sh did not produce $OUT/$SLUG.zip" >&2; exit 1; }

# For play.html's own Info tab (see renderMarkdown()/showInfo() in
# scripts/web_shell_override/index.html) -- fetched by plain filename
# relative to the lib's own page. Copy whichever exist; the Info tab
# degrades to "(no README/NOTES.md shipped for this lib)" if neither does.
[ -f "$LIB/README.md" ] && cp "$LIB/README.md" "$OUT/README.md"
[ -f "$LIB/NOTES.md" ] && cp "$LIB/NOTES.md" "$OUT/NOTES.md"

echo "zipped $SLUG -> $OUT/$SLUG.zip"
