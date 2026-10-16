#!/usr/bin/env bash
# Rebuild libs/longyunmeng_binary/work from the archives: decompile every .b,
# assemble the recovered source tree, convert it for FluffOS. See NOTES.md.
#   libs/longyunmeng_binary/rebuild.sh            (from the repo root)
#   OUT=<dir> REC=<dir> libs/longyunmeng_binary/rebuild.sh   builds elsewhere (to compare with work/)
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/../.." && pwd)"
LIB="$ROOT/libs/longyunmeng_binary"
RAW="$LIB/raw/xyzx/ylfy"
SRC2="$ROOT/libs/longyunmeng/raw/ylfy"     # 033-2, the source edition of the same game
OUT="${OUT:-$LIB/work}"
REC="${REC:-$LIB/raw/recovered}"
[[ -d "$RAW/binaries" ]] || scripts/extract.sh "$ROOT/archives/033-3_longyunmeng_binary_龙云梦-炎龙封印-二进制版.rar" longyunmeng_binary
[[ -d "$SRC2/adm" ]] || scripts/extract.sh "$ROOT/archives/033-2_longyunmeng_龙云梦-炎龙封印源码版.rar" longyunmeng
SCRATCH="${LPC_SCRATCH:-$HOME/.cache/lpc-scratch}"
mkdir -p "$SCRATCH"
TMP="$(mktemp -d -p "$SCRATCH")"
cd "$ROOT/scripts"
# 1. decompile; sources that compile to their own binaries replace the
#    decompiled text: this edition's own .c (keep-original.lst) and 033-2's
#    (borrow-033-2.lst, plus the headers they include)
python3 -m mudos_b.cli "$RAW/binaries" mudos_b/drivers/longyunmeng_binary.json adm/obj/simul_efun \
    --list "$LIB/decompile/all.lst" --out "$TMP/dec" --fluffos --gbk
python3 -m mudos_b.rebuild_tree "$RAW" "$TMP/dec" "$REC" \
    --keep-original "$LIB/decompile/keep-original.lst" \
    --borrow "$SRC2" "$LIB/decompile/borrow-033-2.lst" \
    --borrow-header "$(cat "$LIB/decompile/borrow-header.txt")" \
    --exclude binaries
cd "$ROOT"
scripts/convert_lib.sh "$REC" "$OUT"
# 2. static->nosave also rewrote log paths inside strings (KB 03 §4.3): revert
grep -rlZ 'nosave/' "$OUT" --include='*.lpc' | while IFS= read -r -d '' f; do
  rel="${f#$OUT/}"; src="$REC/${rel%.lpc}.c"
  if [[ -f "$src" ]] && grep -q 'static/' "$src"; then sed -i 's|\([/"]\)nosave/|\1static/|g' "$f"; fi
done
# 3. `replace_program(X);` after `inherit X;` (KB 06 §7.86, §7.100)
python3 "$ROOT/scripts/lpc_drop_replace_program.py" --apply "$OUT" > /dev/null
mkdir -p "$OUT/log" "$OUT/binaries"
# 4. hand fixes and the fixes ported from 033-2 (NOTES.md lists them)
patch -p1 -d "$OUT" < "$LIB/decompile/fluffos-fixes.patch"
rm -rf "$TMP"
echo "rebuilt $OUT"
