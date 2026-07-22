#!/usr/bin/env bash
# Convert an extracted mudlib (libs/<slug>/raw/<mudlib-root>) into a working
# copy (libs/<slug>/work) with: GB18030->UTF-8 on every text file, .c->.lpc
# rename, literal ".c" reference fixes (.lpc + .h), and static->nosave.
#
# Usage: convert_lib.sh <raw-mudlib-root-dir> <work-dir>
#   e.g. convert_lib.sh libs/foo/raw/simple libs/foo/work
#
# This handles the MECHANICAL fixes from AGENTS.md's compatibility catalog.
# It does NOT handle lib-specific logic bugs (e.g. the master.lpc
# valid_read/valid_write recursion guard, §4) -- those need a human/agent
# read of the actual code. Re-run lpcc_check.sh and a real boot after this.
set -uo pipefail

RAW="$1"
WORK="$2"

if [[ ! -d "$RAW" ]]; then
  echo "no such raw dir: $RAW" >&2
  exit 1
fi

echo "== copying $RAW -> $WORK"
rm -rf "$WORK"
cp -r "$RAW" "$WORK"

echo "== encoding: GB18030 -> UTF-8 for every text file"
find "$WORK" -type f > /tmp/convert_lib_filelist.$$.txt
total=$(wc -l < /tmp/convert_lib_filelist.$$.txt)
n=0; already_utf8=0; converted=0; lossy=0; skipped_binary=0
while IFS= read -r f; do
  n=$((n + 1))
  if [[ $((n % 200)) -eq 0 ]]; then echo "  progress $n/$total"; fi

  # `file`'s text/binary heuristic is NOT reliable enough to gate LPC
  # source on alone -- a GBK file with an unusual byte pattern (seen: CRCRLF
  # line endings) gets misclassified as "data" and silently skipped, left
  # as raw GBK forever (a real bug found processing lib #4; re-scan any
  # already-converted lib if you're fixing this after the fact). Known
  # source/text extensions are ALWAYS treated as text regardless of what
  # `file` thinks; only fall back to the `file`-based guess for extension-
  # less files and unknown extensions, where we have no prior.
  # (.o deliberately excluded: LPC save-data .o files are text, but a
  # genuine compiled/bytecode-dump .o also uses that extension in some of
  # these archives -- keep the `file`-based guess for that one.)
  case "$f" in
    *.c|*.lpc|*.h|*.txt|*.log|*.cfg|*.conf|*.map) ;;
    *)
      ftype=$(file -b "$f")
      case "$ftype" in
        *text*|*script*) ;;
        *) skipped_binary=$((skipped_binary + 1)); continue ;;
      esac
      ;;
  esac

  if timeout 2 iconv -f UTF-8 -t UTF-8 "$f" >/dev/null 2>&1; then
    already_utf8=$((already_utf8 + 1))
    continue
  fi
  if timeout 2 iconv -f GB18030 -t UTF-8 "$f" > "$f.utf8tmp" 2>/dev/null; then
    mv "$f.utf8tmp" "$f"
    converted=$((converted + 1))
  else
    rm -f "$f.utf8tmp"
    if timeout 2 iconv -f GB18030 -t UTF-8 -c "$f" > "$f.utf8tmp" 2>/dev/null; then
      mv "$f.utf8tmp" "$f"
      lossy=$((lossy + 1))
      echo "  LOSSY conversion (invalid bytes dropped): $f"
    else
      rm -f "$f.utf8tmp"
      echo "  FAILED to convert (left as-is, check encoding manually): $f"
    fi
  fi
done < /tmp/convert_lib_filelist.$$.txt
rm -f /tmp/convert_lib_filelist.$$.txt
echo "  encoding: already_utf8=$already_utf8 converted=$converted lossy=$lossy skipped_binary=$skipped_binary"

echo "== renaming .c -> .lpc"
find "$WORK" -name "*.c" | while read -r f; do mv "$f" "${f%.c}.lpc"; done
renamed=$(find "$WORK" -name "*.lpc" | wc -l)
echo "  now $renamed .lpc files"

echo "== fixing literal .c\" references (.lpc + .h)"
before=$(grep -rn '\.c"' "$WORK" --include="*.lpc" --include="*.h" 2>/dev/null | wc -l)
grep -rlZ '\.c"' "$WORK" --include="*.lpc" --include="*.h" 2>/dev/null | xargs -0 -r sed -i 's/\.c"/\.lpc"/g'
after=$(grep -rn '\.c"' "$WORK" --include="*.lpc" --include="*.h" 2>/dev/null | wc -l)
echo "  fixed $((before - after)) refs, $after remain (inspect manually -- see AGENTS.md §2)"

echo "== static -> nosave (.lpc + .h)"
# NUL-delimited throughout -- a plain newline-delimited pipe into xargs
# word-splits any filename containing a space (seen: "char - 副本.lpc",
# a backup-copy file with a literal space in its Chinese-annotated name).
statics_count=$(grep -rlZ '\bstatic\b' "$WORK" --include="*.lpc" --include="*.h" 2>/dev/null | tee /tmp/convert_lib_statics.$$.txt | tr -cd '\0' | wc -c)
if [[ -s /tmp/convert_lib_statics.$$.txt ]]; then
  xargs -0 -r sed -i -E 's/\bstatic\b/nosave/g' < /tmp/convert_lib_statics.$$.txt
fi
rm -f /tmp/convert_lib_statics.$$.txt
echo "  files touched: $statics_count"

echo "== done. Next: review AGENTS.md §2/§3 leftovers, check master.lpc for the §4"
echo "   load_object-during-compile recursion pattern, then boot."
