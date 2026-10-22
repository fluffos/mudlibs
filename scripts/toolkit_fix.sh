#!/usr/bin/env bash
#
# toolkit_fix.sh -- one repair round on a lib in libs/<slug>/ (TOOLKIT.md).
#
# Usage: scripts/toolkit_fix.sh <slug> [--no-fix]
#
#   1. scan every .lpc with `lpcc --batch` and apply the mechanical warning
#      fixes (scripts/lpc_warnings.py --fix: unused locals, nosave functions,
#      bad escapes, negative range ends, varargs, bare returns);
#   2. apply the fixers that read the compiler's diagnostics list:
#      bitwise `&` in boolean tests, return types and prototypes, float truncated to int (to_int(); x op= <float>
#      zeroed x and becomes x = to_int(x op ...)), NPC + F_UNIQUE
#      init(), unused locals with an initializer, declarations used only inside
#      an inactive #if branch, `Macro 'X' redefined` (#undef in front of the later
#      #define), the `;` after a class or function body (`Extra ';'. Ignored.`);
#   3. drop inherits another inherit already contains (scripts/lpc_diamonds.py);
#   4. load every changed object twice, from HEAD and from your working tree, in
#      fresh driver processes, and report anything that loaded before and no
#      longer does;
#   5. audit every deleted declaration for a name the function still reads.
#
# With --no-fix it only scans and prints what is left.  Nothing is committed:
# read `git diff`, then commit what you keep.  Files under tests/ and
# help_topics/error_messages/ are left alone (they are broken on purpose in
# several libs).  Needs a FluffOS debug build: set LPCC=/path/to/lpcc if it is
# not at ~/src/fluffos/build-debug/src/lpcc.
set -uo pipefail

mkdir -p "${LPC_SCRATCH:-$HOME/.cache/lpc-scratch}"
SLUG=${1:?usage: toolkit_fix.sh <slug> [--no-fix]}
FIX=1; [ "${2:-}" = "--no-fix" ] && FIX=0
REPO=$(cd "$(dirname "$0")/.." && pwd)
cd "$REPO"
[ -f "libs/$SLUG/config.fluffos" ] || { echo "libs/$SLUG/config.fluffos not found (scripts/toolkit_import.sh first)" >&2; exit 1; }
OUT=$(mktemp -d ${LPC_SCRATCH:-$HOME/.cache/lpc-scratch}/toolkit-"$SLUG".XXXX)
D=${LPC_SCRATCH:-$HOME/.cache/lpc-scratch}/lpcw-$SLUG/diagnostics.tsv
SKIP=(--skip '/tests?/' --skip '/help_topics/error_messages/')
# TOOLKIT_EXTRA_SKIP='/backup/ /old/' leaves more directories out of the scan (regexes, space separated): dated backup copies of a whole lib
# (wdxtym's /backup/2023-5-31/... holds 22,795 rooms, and the scan spent its 90 minutes there) are dead code, not objects a visitor meets.
for _x in ${TOOLKIT_EXTRA_SKIP:-}; do SKIP+=(--skip "$_x"); done

echo "== 0. does the driver load your master and simul_efun?"
LPCC=${LPCC:-$HOME/src/fluffos/build-debug/src/lpcc}
[ -x "$LPCC" ] || { echo "lpcc not found at $LPCC: build FluffOS (target lpcc) and set LPCC=" >&2; exit 1; }
MASTER=$(tr -d '\r' < "libs/$SLUG/config.fluffos" | sed -n 's/^master file *: *//p' | head -1 | sed 's/[[:space:]]*$//')
mkdir -p "libs/$SLUG/work/log"
( cd "libs/$SLUG" && ulimit -v "$(python3 "$OLDPWD/scripts/lpcc_mem.py" 2>/dev/null || echo 6291456)" && echo "$MASTER" | timeout 300 "$LPCC" --batch config.fluffos > "$OUT/boot.txt" 2>&1 )
if ! grep -aq "^PASS " "$OUT/boot.txt"; then
  echo "   no: the driver stops before it can compile anything. Its last words:"
  grep -av '^\s*$' "$OUT/boot.txt" | grep -av 'Uncollected profiling\|Trace duration\|Dump trace' | tail -8 | sed 's/^/     /'
  echo "   Fix this first: TOOLKIT.md \"If the lib does not boot\" (docs/kb/05-runtime-classes-1.md §7.1-§7.3,"
  echo "   docs/kb/04-compile-classes.md for compile errors). Then run this script again."
  exit 1
fi
echo "   yes"

echo "== 1. scan (lpc_warnings.py; a big lib takes a while)"
if [ $FIX = 1 ]; then
  python3 -u scripts/lpc_warnings.py "$SLUG" --fix "${SKIP[@]}" | tee "$OUT/scan.txt" | grep -E 'files compile|^round'
else
  python3 -u scripts/lpc_warnings.py "$SLUG" "${SKIP[@]}" | tee "$OUT/scan.txt" | grep -E 'files compile'
  sed -n '/distinct diagnostics/,$p' "$OUT/scan.txt" | head -40
  exit 0
fi
[ -f "$D" ] || { echo "no diagnostics list at $D" >&2; exit 1; }
grep -avE '/tests?/|/help_topics/error_messages/' "$D" > "$D.f" && mv "$D.f" "$D"

echo "== 2. diagnostics-driven fixers"
echo "   inherit order: $(python3 scripts/lpc_fix_inherit_order.py "$SLUG" --apply --diag "$D" | tail -1)"
echo "   void returns: $(python3 scripts/lpc_fix_void_return.py "$SLUG" --apply --diag "$D" | tail -1)"
echo "   array types:  $(python3 scripts/lpc_fix_array_type.py "$SLUG" --apply | tail -1)"
echo "   bitwise:      $(python3 scripts/lpc_fix_bitwise_bool.py --apply "$SLUG" "$D" | tail -1)"
echo "   return types: $(python3 scripts/lpc_fix_return_types.py --apply "$SLUG" "$D" | tail -1)"
echo "   float->int:   $(python3 scripts/lpc_fix_float_trunc.py "$SLUG" --apply --diag "$D" | tail -1)"
echo "   overrides:    $(python3 scripts/lpc_fix_void_override.py "$SLUG" --mixed --apply | tail -1)"
echo "   unique init:  $(python3 scripts/lpc_fix_unique_init.py --apply "$SLUG" "$D" | tail -1)"
echo "   unused init:  $(python3 scripts/lpc_fix_unused_init.py "$SLUG" --apply 2>/dev/null | grep -c '^FIX') declaration(s)"
echo "   #if locals:   $(python3 scripts/lpc_move_decl.py "$SLUG" --apply 2>/dev/null | grep -c '^edited') file(s)"
echo "   macro redef:  $(python3 scripts/lpc_fix_macro_redef.py "$SLUG" --apply 2>/dev/null | tail -1)"
echo "   extra ';':    $(python3 scripts/lpc_fix_extra_semicolon.py "$SLUG" --apply 2>/dev/null | tail -1)"

echo "== 3. redundant inherits"
python3 scripts/lpc_diamonds.py "$SLUG" --fix-redundant --apply | tail -1

echo "== 4. load check: HEAD vs working tree"
git -c core.quotepath=false diff --name-only -- "libs/$SLUG/work" | grep '\.lpc$' \
  | sed "s#^libs/$SLUG/work##; s#\.lpc\$##" > "$OUT/changed.list"
if [ -s "$OUT/changed.list" ]; then
  scripts/lpc_listcheck.sh "$SLUG" "$OUT/changed.list" > /dev/null 2>&1
  python3 scripts/lpc_load_diff.py "$SLUG" | tail -15
else
  echo "   nothing changed"
fi

echo "== 5. deleted declarations still read (look at each)"
python3 scripts/lpc_audit_removed_locals.py HEAD "libs/$SLUG/work" | tail -15

echo "== 6. verbs bound to a function nobody defines (report only; read them, KB 06 7.349)"
python3 scripts/lpc_scan_callout_targets.py --kinds=add_action "$SLUG" 2>&1 | awk -F'\t' '$1=="HIT"{n++; if (n<=15) print "   " $4 "  " $5 "  (line " $6 ")"} END{print "   " n+0 " registration(s); the fix is scripts/lpc_fix_dead_add_action.py after scripts/lpc_verify_handlers.py and scripts/lpc_check_descendants.py"}'

echo
echo "Left for you: python3 scripts/lpc_warnings.py $SLUG --list 20   (TOOLKIT.md, \"Reading what is left\")"
echo "Scan output: $OUT/scan.txt"
