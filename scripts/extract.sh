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

# Must be absolute: the *.rar/*.exe branches below `cd "$DEST"` before
# referencing $ARCHIVE, so a relative path (the normal "archives/foo.rar"
# calling convention) silently fails to open -- unrar prints "Cannot open"
# and exits 0, and this script (no `-e`) doesn't fail loudly (it exits 0
# and prints "extracted ..." with `raw/` empty either way).
ARCHIVE="$(cd "$(dirname "$ARCHIVE")" && pwd)/$(basename "$ARCHIVE")"

mkdir -p "$DEST"

lower="${ARCHIVE,,}"
case "$lower" in
  *.zip)
    unzip -o -q "$ARCHIVE" -d "$DEST" 2>&1 || unzip -o -q -O GBK "$ARCHIVE" -d "$DEST"
    # unzip exits 0 even when EVERY member was skipped for a wrong/missing
    # password (only prints "skipping: ... unable to get password" per
    # file) -- if nothing landed, the whole archive is probably password-
    # protected. Some archives in this collection embed the password
    # directly in the zip comment (shown at the top of unzip's own output,
    # garbled through this environment's locale but readable as e.g.
    # "解压密码:muds.cn" -- "extraction password: X") -- try that literal
    # known password as a fallback before giving up.
    if [[ -z "$(find "$DEST" -type f -print -quit 2>/dev/null)" ]]; then
      echo "  (no files extracted -- retrying with known archive password 'muds.cn')"
      unzip -P "muds.cn" -o -q "$ARCHIVE" -d "$DEST" 2>&1
    fi
    ;;
  *.rar)
    (cd "$DEST" && unrar x -y -o+ -p- "$ARCHIVE" >/dev/null)
    if [[ -z "$(find "$DEST" -type f -print -quit 2>/dev/null)" ]]; then
      # Passwords found in archive comments of this collection:
      # 大唐西游指间版.rar comment "密码：676036579"; zip comment "muds.cn".
      for pw in 676036579 muds.cn mud.ren; do
        echo "  (retrying rar with known archive password '$pw')"
        (cd "$DEST" && unrar x -y -o+ -p"$pw" "$ARCHIVE" >/dev/null) && break
      done
    fi
    ;;
  *.7z)
    7z x -y -o"$DEST" "$ARCHIVE" >/dev/null
    if [[ -z "$(find "$DEST" -type f -print -quit 2>/dev/null)" ]]; then
      # 武林群侠传MUDLIB.7z trailer: "解压密码： mud.ren"
      for pw in mud.ren muds.cn 676036579; do
        echo "  (retrying 7z with known archive password '$pw')"
        7z x -y -p"$pw" -o"$DEST" "$ARCHIVE" >/dev/null && break
      done
    fi
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

if [[ -z "$(find "$DEST" -type f -print -quit 2>/dev/null)" ]]; then
  echo "ERROR: nothing extracted into $DEST -- check the archive/tool output above" >&2
  exit 1
fi

echo "extracted $ARCHIVE -> $DEST"
find "$DEST" -maxdepth 2 | head -20
