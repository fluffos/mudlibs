#!/usr/bin/env python3
"""scripts/lpc_fix_warning_rows.py ROWFILE...

The mechanical warning fixers of scripts/lpc_warnings.py, driven by warning rows instead of a whole-lib scan.  A repair that makes objects load
(a restored file, a fixed core class) brings their warnings with it; collecting those with `scripts/lpc_listcheck.sh` takes minutes for the changed objects,
a `lpc_warnings.py SLUG --fix` rescan of a 40,000-file lib takes over an hour.

ROWFILE lines are `SLUG /driver/path.lpc:LINE:COL: warning: MESSAGE` (what the listcheck check runners collect from listchunk-SLUG.work.out:
`grep -a -E ':[0-9]+(:[0-9]+)?: warning' ... | sed "s/^/$slug /"`).  Per lib, in the order lpc_warnings.py uses: `Illegal to declare nosave function` -> `protected`
(public when a call_other-style use exists), negative range ends, unknown escape sequences, `varargs` for disagreeing argument counts, bare returns in
non-void functions, and, last because it deletes lines, unused locals.  Rows of any other kind are ignored (read them: the scan lists them under their
KB 04 section 6.10 class).  The row positions must still match the files, so run this before any other edit of them.  Prints one line per lib."""
import collections
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
argv, sys.argv = sys.argv, ["lpc_warnings.py"]
import lpc_warnings as W  # noqa: E402
sys.argv = argv


def main():
    if len(sys.argv) < 2:
        sys.exit(__doc__)
    rows = collections.defaultdict(set)
    for p in sys.argv[1:]:
        for ln in open(p, encoding="utf-8", errors="replace"):
            m = re.match(r"^(\S+) (/\S+?):(\d+):(\d+): warning: (.*)$", ln.rstrip("\n"))
            if m:
                rows[m.group(1)].add((m.group(2), int(m.group(3)), int(m.group(4)), "warning", m.group(5)))
    for slug in sorted(rows):
        work = f"{REPO}/libs/{slug}/work"
        r = sorted(rows[slug])
        public = set(W.external_callers(work, W.nosave_function_names(work, r)))
        np_, nd_, m1 = W.fix_nosave_functions(work, r, public)
        nr_, m2 = W.fix_range_ends(work, r)
        ne_, m3 = W.fix_escapes(work, r)
        na_, m5 = W.fix_arg_counts(work, r)
        nb_, m6 = W.fix_bare_returns(work, r)
        nu_, m4 = W.fix_unused_locals(work, r)
        print(f"{slug}: rows {len(r)} nosave {np_}+{nd_} ranges {nr_} escapes {ne_} varargs {na_} bare {nb_} unused {nu_} left {len(m1 + m2 + m3 + m4 + m5 + m6)}")


if __name__ == "__main__":
    main()
