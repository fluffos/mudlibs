#!/usr/bin/env bash
# scripts/lpc_boot_survey.sh [SLUG...]
#
# Boot each lib once on a pristine tree (HEAD, scripts/pristine_tree.sh) with the debug driver's batch mode and no objects,
# and count what the driver prints while the master, the simul_efun file and the preload list compile: the screen the first
# visitor of a fresh boot sees.  One line per lib on stdout and in ${LPC_SCRATCH:-$HOME/.cache/lpc-scratch}/boot_survey.tsv:
#   slug <TAB> warnings <TAB> errors <TAB> first warning or error
# Without arguments every vendored lib with a config.fluffos is booted (a submodule's work/ is skipped, so is `realms`, which
# needs MySQL); SURVEY_SKIP="slug slug" skips more.  A lib that does not boot at all (no master) shows `-` for both counts.
# The tree is deleted after each boot.  Run it from a clean commit: it surveys HEAD, not the working tree.
set -uo pipefail
SCR=${LPC_SCRATCH:-$HOME/.cache/lpc-scratch}
mkdir -p "$SCR"
REPO=$(cd "$(dirname "$0")/.." && pwd)
cd "$REPO"
LPCC=${LPCC:-$HOME/src/fluffos/build-debug/src/lpcc}
MEMKB=$(python3 scripts/lpcc_mem.py)
OUT=$SCR/boot_survey.tsv
: > "$OUT"
if [ $# -gt 0 ]; then slugs=("$@"); else slugs=($(for d in libs/*/; do basename "$d"; done)); fi
for s in "${slugs[@]}"; do
  [ -f "libs/$s/config.fluffos" ] || continue
  [ -n "$(git ls-files -s -- "libs/$s/work" | awk '$1==160000' | head -1)" ] && continue
  case " realms ${SURVEY_SKIP:-} " in *" $s "*) continue ;; esac
  dest=$SCR/bootsurvey-$s
  if ! scripts/pristine_tree.sh "$s" 45997 "$dest" > /dev/null 2>&1; then
    printf '%s\t-\t-\tno pristine tree\n' "$s" | tee -a "$OUT"
    continue
  fi
  r=$(cd "$dest/libs/$s" && ulimit -v "$MEMKB" && timeout 600 "$LPCC" --batch config.fluffos < /dev/null 2>&1)
  w=$(printf '%s\n' "$r" | grep -a -c ': warning:')
  e=$(printf '%s\n' "$r" | grep -a -c ': error:')
  first=$(printf '%s\n' "$r" | grep -a -m1 -E ': (warning|error):' | cut -c1-160)
  if ! printf '%s\n' "$r" | grep -a -q 'Loading master file'; then w=-; e=-; first="did not boot: $(printf '%s\n' "$r" | tail -n 1 | cut -c1-120)"; fi
  printf '%s\t%s\t%s\t%s\n' "$s" "$w" "$e" "$first" | tee -a "$OUT"
  case "$dest" in "$SCR"/bootsurvey-*) rm -rf -- "$dest" ;; esac
done
echo "boot survey done" >&2
