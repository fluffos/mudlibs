#!/usr/bin/env bash
# Rebuild libs/wllz3/work from the archive: decompile every .b, assemble the
# recovered source tree, convert it for FluffOS. See NOTES.md.
#   libs/wllz3/rebuild.sh            (from the repo root)
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/../.." && pwd)"
LIB="$ROOT/libs/wllz3"
RAW="$LIB/raw/wllz"
[[ -d "$RAW/world/binaries" ]] || scripts/extract.sh "$ROOT/archives/186_wllz3_wllz.rar" wllz3
TMP="$(mktemp -d)"
cd "$ROOT/scripts"
# 1. sources that still compile to their own binaries are kept as-is
python3 -m mudos_b.cli "$RAW/world/binaries" mudos_b/drivers/wllz3.json adm/single/simul_efun \
    --list "$LIB/decompile/all.lst" --out "$TMP/dec" --fluffos
python3 -m mudos_b.rebuild_tree "$RAW/world" "$TMP/dec" "$LIB/raw/recovered" \
    --keep-original "$LIB/decompile/keep-original.lst" --exclude binaries --exclude backup
cd "$ROOT"
scripts/convert_lib.sh "$LIB/raw/recovered" "$LIB/work"
# 2. static->nosave also rewrote log paths inside strings (KB 03 §4.3): revert
grep -rlZ 'nosave/' "$LIB/work" --include='*.lpc' | while IFS= read -r -d '' f; do
  rel="${f#$LIB/work/}"; src="$LIB/raw/recovered/${rel%.lpc}.c"
  if [[ -f "$src" ]] && grep -q 'static/' "$src"; then sed -i 's|\([/"]\)nosave/|\1static/|g' "$f"; fi
done
mkdir -p "$LIB/work/log" "$LIB/work/binaries"
# 3. hand fixes made after the conversion (NOTES.md lists them)
patch -p1 -d "$LIB/work" < "$LIB/decompile/fluffos-fixes.patch"
rm -rf "$TMP"
echo "rebuilt $LIB/work"
