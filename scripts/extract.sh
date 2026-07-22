#!/usr/bin/env bash
# Extract one archive into libs/<slug>/raw/, auto-detecting the archive type.
# Usage: extract.sh archives/<name> <slug>
set -uo pipefail

ARCHIVE="$1"
SLUG="$2"
ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
DEST="$ROOT/libs/$SLUG/raw"

if [[ ! -f "$ARCHIVE" ]]; then
  echo "no such archive: $ARCHIVE" >&2
  exit 1
fi

mkdir -p "$DEST"

lower="${ARCHIVE,,}"
case "$lower" in
  *.zip)
    unzip -o -q "$ARCHIVE" -d "$DEST" 2>&1 || unzip -o -q -O GBK "$ARCHIVE" -d "$DEST"
    ;;
  *.rar)
    (cd "$DEST" && unrar x -y -o+ "$ARCHIVE" >/dev/null)
    ;;
  *.7z)
    7z x -y -o"$DEST" "$ARCHIVE" >/dev/null
    ;;
  *.tar.gz|*.tgz)
    tar xzf "$ARCHIVE" -C "$DEST"
    ;;
  *.gz)
    # could be a bare gzip of a tar (not .tar.gz-named) -- try tar first
    if tar tzf "$ARCHIVE" >/dev/null 2>&1; then
      tar xzf "$ARCHIVE" -C "$DEST"
    else
      gunzip -c "$ARCHIVE" > "$DEST/$(basename "${ARCHIVE%.gz}")"
    fi
    ;;
  *.exe)
    # self-extracting RAR/7z SFX
    7z x -y -o"$DEST" "$ARCHIVE" >/dev/null 2>&1 || (cd "$DEST" && unrar x -y "$ARCHIVE" >/dev/null)
    ;;
  *)
    echo "unknown archive type: $ARCHIVE" >&2
    exit 1
    ;;
esac

echo "extracted $ARCHIVE -> $DEST"
find "$DEST" -maxdepth 2 | head -20
