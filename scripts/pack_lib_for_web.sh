#!/usr/bin/env bash
#
# pack_lib_for_web.sh -- pack ONE converted mudlib from libs/<slug>/ into a
# playable static browser bundle for the GitHub Pages site.
#
# Usage:
#   scripts/pack_lib_for_web.sh <slug> <driver_dir> <shell_dir> <out_dir>
#
#   <slug>        directory name under libs/ (must contain config.fluffos + work/)
#   <driver_dir>  dir containing fluffos.js + fluffos.wasm (extracted release zip
#                 or a build-wasm/src tree) -- only validated here; the driver is
#                 NOT copied per lib (one shared copy lives at the site root, see
#                 the dedupe note below)
#   <shell_dir>   dir containing the web terminal index.html (in the release zip
#                 this is the same dir as the driver).  When
#                 scripts/web_shell_override/index.html exists it is used as
#                 the page template INSTEAD of <shell_dir>/index.html -- a
#                 newer upstream page (src/www/wasm/index.html, e.g. the
#                 Game/Logs tab shell) deployed ahead of the next fluffos
#                 release.  The override must keep the patch anchors below.
#   <out_dir>     output dir for this lib's bundle (created)
#
# Output bundle (per lib):
#   mudlib.data / mudlib.js   the trimmed lib tree, packed by emscripten's
#                             file_packager for the in-memory FS
#   fluffos-boot.js           mount point + config for the web terminal page
#   index.html                the web terminal, patched so that fluffos.js /
#                             fluffos.wasm / telnet.js / vendor/* load from
#                             ../_driver/ (ONE shared copy at the site root
#                             instead of ~3.5MB duplicated into every lib dir)
#
# The lib's work/ tree is staged with trimming (logs, backups, bundled native
# drivers, archives, bytecode) -- see EXCLUDES below.  log/ directory SHAPE is
# preserved via 0-byte .keep files because many libs' log_file()/write_file()
# calls throw (and silently abort the caller) on a missing directory, even a
# nested one (same behavior as scripts/wasm_client.js's mkdirsOnly()).
#
# config.fluffos's `mudlib directory :` line (an absolute host path in this
# repo's convention) is rewritten to the in-image path /mudlib/work, exactly
# like scripts/wasm_client.js does before boot.
#
# Requires: rsync, python3, emscripten's file_packager (emsdk on PATH).

set -euo pipefail

SELF_DIR=$(cd "$(dirname "$0")" && pwd)
REPO_ROOT=$(cd "$SELF_DIR/.." && pwd)

if [ $# -ne 4 ]; then
  echo "usage: $0 <slug> <driver_dir> <shell_dir> <out_dir>" >&2
  exit 2
fi

SLUG=$1
DRIVER_DIR=$(cd "$2" && pwd)
SHELL_DIR=$(cd "$3" && pwd)
OUT=$4

LIB="$REPO_ROOT/libs/$SLUG"
[ -f "$LIB/config.fluffos" ] || { echo "error: $LIB/config.fluffos not found" >&2; exit 1; }
[ -d "$LIB/work" ] || { echo "error: $LIB/work not found" >&2; exit 1; }
[ -f "$DRIVER_DIR/fluffos.js" ] && [ -f "$DRIVER_DIR/fluffos.wasm" ] || {
  echo "error: driver not found in $DRIVER_DIR (need fluffos.js + fluffos.wasm)" >&2; exit 1; }
[ -f "$SHELL_DIR/index.html" ] || { echo "error: $SHELL_DIR/index.html not found" >&2; exit 1; }

# Page template: prefer the local override (an upstream src/www/wasm page
# newer than the release zip's) when it exists; the path patching below
# requires the same anchors either way and fails loudly if they are gone.
SHELL_PAGE="$SHELL_DIR/index.html"
if [ -f "$SELF_DIR/web_shell_override/index.html" ]; then
  SHELL_PAGE="$SELF_DIR/web_shell_override/index.html"
  echo "using web shell override: $SHELL_PAGE"
fi

# --- locate emscripten's file_packager (same logic as pack-mudlib.sh) --------
FILE_PACKAGER=""
if command -v file_packager >/dev/null; then
  FILE_PACKAGER="file_packager"
else
  EMCC_PATH=$(command -v emcc || true)
  for c in "${EMCC_PATH:+$(dirname "$EMCC_PATH")/tools/file_packager.py}" \
           /usr/share/emscripten/tools/file_packager.py; do
    if [ -n "$c" ] && [ -f "$c" ]; then FILE_PACKAGER="python3 $c"; break; fi
  done
fi
[ -n "$FILE_PACKAGER" ] || { echo "error: emscripten file_packager not found (emsdk on PATH?)" >&2; exit 1; }

STAGE=$(mktemp -d "${TMPDIR:-/tmp}/packlib.$SLUG.XXXXXX")
# Some libs ship read-only dirs/files (rsync -a preserves the modes); make
# the staging tree writable again before removing it, and never let cleanup
# failures change the script's exit status.
trap 'chmod -R u+w "$STAGE" >/dev/null 2>&1 || true; rm -rf "$STAGE" 2>/dev/null || true' EXIT

# --- 1. stage the trimmed work/ tree ----------------------------------------
# Trimming policy (user-requested; when in doubt KEEP the file):
#   - the TOP-LEVEL log/ tree entirely (shape preserved below).  Only the
#     top level: nested dirs that happen to be named "log" hold tracked
#     in-game content in several libs (e.g. xlqy_new2007's doc/help/log/
#     help texts, xiakexing100's adm/log seed data) and must ship.
#   - www/, temp/, backup/ TOP-LEVEL dirs only
#   - bundled old native drivers: fluffos64/ anywhere; work/driver/ only when
#     it contains no LPC source (checked below)
#   - *.bak backups, *.b compiled MudOS bytecode, win32 binaries, archives,
#     core dumps, numbered-backup junk (*.5555 etc.)
# Kept on purpose: .lpc/.h source, in-game help/doc text, data/*.o saves
# (boards/storage read at runtime), banned_name, banner files.
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

# Top-level native driver binaries shipped under generic names (no extension
# for the patterns above to catch): exclude any top-level regular file whose
# magic bytes say ELF (several libs bundle an old built `driver`).
while IFS= read -r f; do
  magic=$(head -c4 "$f" | od -An -tx1 | tr -d ' \n')
  if [ "$magic" = "7f454c46" ]; then
    EXCLUDES+=(--exclude="/$(basename "$f")")
  fi
done < <(find "$LIB/work" -maxdepth 1 -type f -size +64k)

# work/driver/: some archives bundle an old native driver source/binary tree
# there, but at least one lib uses driver/ for LPC content -- exclude only if
# it contains no LPC source at all.
DRIVER_SUBDIR_EXCLUDED=0
if [ -d "$LIB/work/driver" ]; then
  if [ -z "$(find "$LIB/work/driver" \( -name '*.lpc' -o -name '*.c' -o -name '*.h' \) -print -quit)" ]; then
    EXCLUDES+=(--exclude='/driver/')
    DRIVER_SUBDIR_EXCLUDED=1
  fi
fi

mkdir -p "$STAGE/mudlib"
rsync -a "${EXCLUDES[@]}" "$LIB/work/" "$STAGE/mudlib/work/"

# Preserve directory SHAPE (0-byte .keep placeholders; file_packager only
# materializes directories that contain files) for:
#   a) the trimmed top-level log/ tree, from the local disk when present;
#   b) every dir recorded in scripts/wasm_keep_dirs.txt for this slug --
#      dirs that exist on a booted local tree but hold no git-tracked files,
#      so a CI checkout lacks them entirely (log/, data/topten/, ...).
# Many libs' log_file()/write_file()/save_object() calls throw -- silently
# aborting the caller -- on a missing directory at any depth (AGENTS.md's
# missing-directory-swallows-errors pattern), so the shape must exist.
keep_dir() {
  local rel=$1
  mkdir -p "$STAGE/mudlib/work/$rel"
  # tolerate an already-staged read-only dir: it exists, which is all that
  # matters (the .keep is only needed for dirs that would otherwise be empty)
  : > "$STAGE/mudlib/work/$rel/.keep" 2>/dev/null || true
}
if [ -d "$LIB/work/log" ]; then
  while IFS= read -r d; do
    keep_dir "${d#"$LIB/work/"}"
  done < <(find "$LIB/work/log" -type d)
fi
KEEP_LIST="$SELF_DIR/wasm_keep_dirs.txt"
if [ -f "$KEEP_LIST" ]; then
  while IFS=$'\t' read -r s rel; do
    [ "$s" = "$SLUG" ] || continue
    case "$rel" in
      www|www/*|temp|temp/*|backup|backup/*) continue ;;
      driver|driver/*)
        if [ "$DRIVER_SUBDIR_EXCLUDED" = 1 ]; then continue; fi ;;
    esac
    keep_dir "$rel"
  done < "$KEEP_LIST"
else
  echo "warning: $KEEP_LIST missing -- packed image may lack runtime dirs" >&2
fi
mkdir -p "$STAGE/mudlib/work/log"   # the config's `log directory : /log`
[ -e "$STAGE/mudlib/work/log/.keep" ] || : > "$STAGE/mudlib/work/log/.keep"

# --- 2. rewrite config.fluffos's mudlib directory to the in-image path ------
python3 - "$LIB/config.fluffos" "$STAGE/mudlib/config.fluffos" <<'PYEOF'
import re, sys
src, dst = sys.argv[1], sys.argv[2]
text = open(src, encoding='utf-8', errors='surrogateescape').read()
new, n = re.subn(r'^(\s*mudlib directory\s*:\s*).*$', r'\g<1>/mudlib/work',
                 text, flags=re.M)
if n != 1:
    sys.exit('error: expected exactly one "mudlib directory :" line, found %d' % n)
open(dst, 'w', encoding='utf-8', errors='surrogateescape').write(new)
PYEOF

# --- 3. pack with file_packager ---------------------------------------------
mkdir -p "$OUT"
(cd "$STAGE" && $FILE_PACKAGER "$OUT/mudlib.data" \
    --preload "mudlib@/mudlib" \
    --js-output="$OUT/mudlib.js" >/dev/null)

# --- 4. boot config ----------------------------------------------------------
cat > "$OUT/fluffos-boot.js" <<EOF
// Generated by scripts/pack_lib_for_web.sh -- consumed by index.html.
window.FLUFFOS_BOOT = {
  mount: "/mudlib",
  config: "config.fluffos",
};
EOF

# --- 5. per-lib page: patched copy of the web terminal -----------------------
# Path patches (MUST all apply -- fail loudly if the upstream page changed):
#   vendor/, telnet.js, fluffos.js -> ../_driver/...
#   locateFile: .wasm from ../_driver/, everything else (mudlib.data) local.
# Cosmetic patches (title/h1 -> game name) are best-effort.
GAME_NAME=$(sed -n 's/^# *//p' "$LIB/README.md" 2>/dev/null | head -1)
[ -n "$GAME_NAME" ] || GAME_NAME=$SLUG
export SLUG GAME_NAME
python3 - "$SHELL_PAGE" "$OUT/index.html" <<'PYEOF'
import os, sys
src, dst = sys.argv[1], sys.argv[2]
html = open(src, encoding='utf-8').read()
slug = os.environ['SLUG']
name = os.environ['GAME_NAME']

required = [
    ('href="vendor/xterm.css"', 'href="../_driver/vendor/xterm.css"'),
    ('<script src="vendor/xterm.js"></script>',
     '<script src="../_driver/vendor/xterm.js"></script>'),
    ('<script src="vendor/addon-fit.js"></script>',
     '<script src="../_driver/vendor/addon-fit.js"></script>'),
    ('<script src="telnet.js"></script>',
     '<script src="../_driver/telnet.js"></script>'),
    ('<script src="fluffos.js"></script>',
     '<script src="../_driver/fluffos.js"></script>'),
    ('locateFile: (f) => f,',
     "locateFile: (f) => f.endsWith('.wasm') ? '../_driver/' + f : f,"),
]
for old, new in required:
    if html.count(old) != 1:
        sys.exit('error: pattern not found exactly once in %s: %r\n'
                 '(the release web terminal page changed; update '
                 'scripts/pack_lib_for_web.sh)' % (src, old))
    html = html.replace(old, new)

cosmetic = [
    ('<title>FluffOS — WebAssembly driver</title>',
     '<title>%s — FluffOS WASM</title>' % name),
    ('<h1>FluffOS / WebAssembly</h1>',
     '<h1><a href="../" style="color:inherit;text-decoration:none" '
     'title="返回游戏列表">«</a> %s</h1>' % name),
]
for old, new in cosmetic:
    if html.count(old) == 1:
        html = html.replace(old, new)
    else:
        print('warning: cosmetic pattern not found, skipped: %r' % old,
              file=sys.stderr)

open(dst, 'w', encoding='utf-8').write(html)
PYEOF

SIZE=$(du -sh "$OUT" | cut -f1)
echo "packed $SLUG -> $OUT ($SIZE)"
