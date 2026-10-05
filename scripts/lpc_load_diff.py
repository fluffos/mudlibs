#!/usr/bin/env python3
"""scripts/lpc_load_diff.py SLUG [--fold] [--show N]

The two outputs of scripts/lpc_listcheck.sh (/tmp/listchunk-SLUG.{head,work}.out) compared object by object: how many load at
HEAD and in the tree, which loaded before and fail now (REGRESS), which load now and did not (NEW).  --fold identifies an object
by its lower-cased path and ORs the results of every spelling, for a list that holds the old and the new name of a renamed file
(scripts/lpc_case_paths.py --list): without it every renamed object reads as a regression.  Read a REGRESS line with the artifact
of the HEAD column in mind (a PASS at HEAD can be spurious, see lpc_listcheck.sh)."""
import re
import sys

args = sys.argv[1:]
fold = "--fold" in args
show = 30
if "--show" in args:
    show = int(args[args.index("--show") + 1])
args = [a for a in args if not a.startswith("--") and not a.isdigit()]
if len(args) != 1:
    sys.exit(__doc__)
slug = args[0]


def load(kind):
    d = {}
    for line in open(f"/tmp/listchunk-{slug}.{kind}.out", errors="replace"):
        m = re.match(r"(PASS|FAIL)\s+(\S+)", line)
        if m:
            k = m.group(2).lower() if fold else m.group(2)
            d[k] = d.get(k, False) or m.group(1) == "PASS"
    return d


h, w = load("head"), load("work")
reg = sorted(k for k in h if h[k] and not w.get(k))
new = sorted(k for k in h if not h[k] and w.get(k))
print(f"{slug}: {len(h)} objects; HEAD PASS {sum(h.values())}, tree PASS {sum(w.values())}; regress {len(reg)}; newly loading {len(new)}")
for k in reg[:show]:
    print("  REGRESS", k)
