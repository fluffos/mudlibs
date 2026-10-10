#!/usr/bin/env bash
#
# toolkit_import.sh -- bring your own mudlib into this repo's layout so the
# repair toolkit (TOOLKIT.md) can work on it.
#
# Usage: scripts/toolkit_import.sh <mudlib-dir> <slug> <driver-config> [encoding] [port]
#
#   <mudlib-dir>     the directory your driver's "mudlib directory" points at
#   <slug>           a short name for it (letters, digits, _), e.g. mymud
#   <driver-config>  the MudOS/FluffOS config file you boot it with today
#   [encoding]       source text encoding: GB18030 (default), BIG5, or UTF-8
#                    (files that are already valid UTF-8 are never touched)
#   [port]           telnet port for local tests (default 49900)
#
# What it does:
#   1. copies <mudlib-dir> to libs/<slug>/work through scripts/convert_lib.sh:
#      text -> UTF-8, *.c -> *.lpc (FluffOS loads both spellings), the literal
#      ".c" references that rename breaks, and static -> nosave;
#   2. writes libs/<slug>/config.fluffos from your config with the mudlib
#      directory and port pointing at the copy;
#   3. commits the result on a local branch `toolkit/<slug>`. The tools
#      compare that commit (HEAD) with your working tree, so every fix you
#      make afterwards is checked against the original.
#
# Your original directory is never modified. Nothing is pushed anywhere.
set -euo pipefail

if [ $# -lt 3 ]; then
  sed -n '3,26p' "$0" | sed 's/^# \{0,1\}//'
  exit 2
fi
SRC=$(cd "$1" && pwd)
SLUG=$2
CONF=$3
ENC=${4:-GB18030}
PORT=${5:-49900}
REPO=$(cd "$(dirname "$0")/.." && pwd)
LIB="$REPO/libs/$SLUG"

[[ "$SLUG" =~ ^[A-Za-z0-9_]+$ ]] || { echo "slug must be letters, digits or _" >&2; exit 1; }
[ -d "$SRC" ] || { echo "no such mudlib dir: $SRC" >&2; exit 1; }
[ -f "$CONF" ] || { echo "no such config file: $CONF" >&2; exit 1; }
[ -e "$LIB" ] && { echo "libs/$SLUG already exists; pick another slug or remove it first" >&2; exit 1; }
if [ -n "$(git -C "$REPO" status --porcelain --untracked-files=no -- scripts docs)" ]; then
  echo "the toolkit's own files have local edits; commit or discard them first" >&2; exit 1
fi

mkdir -p "$LIB"
"$REPO/scripts/convert_lib.sh" "$SRC" "$LIB/work" "$ENC"

# config: keep everything from the user's file, repoint the directory and the port
python3 - "$CONF" "$LIB/config.fluffos" "$LIB/work" "$PORT" <<'PY'
import re, sys
src, dst, work, port = sys.argv[1:]
text = open(src, encoding="utf-8", errors="replace").read()
def put(key, value, text):
    pat = re.compile(r"^(" + re.escape(key) + r"\s*:).*$", re.M)
    return pat.sub(lambda m: m.group(1) + " " + value, text) if pat.search(text) else text + f"\n{key} : {value}\n"
text = put("mudlib directory", work, text)
if re.search(r"^external_port_1\s*:", text, re.M):
    text = re.sub(r"^(external_port_1\s*:\s*telnet\s+)\d+", lambda m: m.group(1) + port, text, flags=re.M)
else:
    text = put("port number", port, text)
open(dst, "w", encoding="utf-8").write(text)
PY
mkdir -p "$LIB/work/log"

cd "$REPO"
git checkout -q -b "toolkit/$SLUG"
git add -- "libs/$SLUG/config.fluffos"
git add -f -- "libs/$SLUG/work"
git commit -q -m "toolkit: import $SLUG from $SRC (UTF-8, .c -> .lpc)" -- "libs/$SLUG"
echo
echo "Imported into libs/$SLUG on branch toolkit/$SLUG."
echo "Next: scripts/toolkit_fix.sh $SLUG        (see TOOLKIT.md)"
