#!/usr/bin/env python3
"""scripts/lpc_fix_extra_semicolon.py SLUG [--apply]

Fix `warning: Extra ';'. Ignored.` (KB 04 section 6.10): the `;` the old driver let follow the closing brace of a class definition (`class ConnData { string name; ... };`,
the `*_cl.h` headers of the Nightmare / Primal Darkness family) or a function body (`void f() { ... };`).  The driver ignores it and says so on every compile.  The `;` at the
reported line and column is deleted when it is the first non-blank character after a `}` on that line, or the only thing on its line (an empty statement between two
declarations); anything else is listed.  The diagnostics come from $LPC_SCRATCH/lpcw-SLUG/diagnostics.tsv (scripts/lpc_warnings.py SLUG leaves it); without --apply the plan is printed.
Edits are byte-exact (line endings kept); the column is a 1-based byte offset."""
import collections
import os
import re
import sys

_SCRATCH = os.environ.get("LPC_SCRATCH") or os.path.expanduser("~/.cache/lpc-scratch")
REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

a = sys.argv[1:]
if not a or a[0].startswith("--"):
    sys.exit(__doc__)
slug = a[0]
apply_ = "--apply" in a
W = f"{REPO}/libs/{slug}/work"

want = collections.defaultdict(set)
for ln in open(f"{_SCRATCH}/lpcw-{slug}/diagnostics.tsv", encoding="utf-8", errors="replace"):
    f, line, col, sev, msg = ln.rstrip("\n").split("\t", 4)
    if msg.startswith("Extra ';'") and line.isdigit() and col.isdigit():
        want[f].add((int(line), int(col)))

n = skipped = 0
for f, sites in sorted(want.items()):
    path = W + f
    try:
        b = open(path, "rb").read()
    except OSError:
        continue
    lines = b.split(b"\n")
    edits = []
    for line, col in sorted(sites, reverse=True):
        if line > len(lines) or col < 1 or col > len(lines[line - 1]) or lines[line - 1][col - 1:col] != b";":
            print(f"LIST {f}:{line}:{col} (no `;` there)")
            skipped += 1
            continue
        before = lines[line - 1][:col - 1]
        if before.rstrip(b" \t\r").endswith(b"}") or not before.strip(b" \t\r"):
            edits.append((line, col))
            n += 1
            print(f"{'FIX ' if apply_ else 'plan'} {f}:{line}:{col} {lines[line - 1].strip()[:60].decode('utf-8', 'replace')}")
        else:
            print(f"LIST {f}:{line}:{col} {lines[line - 1].strip()[:60].decode('utf-8', 'replace')}")
            skipped += 1
    if apply_ and edits:
        for line, col in edits:
            lines[line - 1] = lines[line - 1][:col - 1] + lines[line - 1][col:]
        open(path, "wb").write(b"\n".join(lines))
print(f"{n} `;` {'removed' if apply_ else 'planned'}, {skipped} listed")
