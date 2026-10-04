#!/usr/bin/env python3
"""scripts/lpc_fix_macro_redef.py SLUG [--apply] [--only SUBSTR ...]

Fix `Macro 'X' redefined` (KB 04 section 6.10) where a file `#define`s a name an earlier header already defined with a
different body: put `#undef X` in front of the later `#define`.  The later definition was already the one in effect, so
nothing else changes.  The diagnostic's line must hold `#define X` (it is looked for within three lines when the driver
reports a continuation line); anything else is listed.  Diagnostics come from /tmp/lpcw-SLUG/diagnostics.tsv; without
--apply it prints the plan.  Edits are byte-exact (line endings kept)."""
import collections
import os
import re
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
a = sys.argv[1:]
if not a or a[0].startswith("--"):
    sys.exit(__doc__)
slug = a[0]
apply_ = "--apply" in a
only = a[a.index("--only") + 1:] if "--only" in a else []
W = f"{REPO}/libs/{slug}/work"

rows = [l.rstrip("\n").split("\t") for l in open(f"/tmp/lpcw-{slug}/diagnostics.tsv", encoding="utf-8", errors="replace")]
want = collections.defaultdict(set)
for f, ln, col, sev, msg in rows:
    m = re.match(r"Macro '(\w+)' redefined", msg)
    if m and (not only or any(o in f for o in only)):
        want[f].add((int(ln), m.group(1)))

done = 0
for f, items in sorted(want.items()):
    path = W + f
    try:
        data = open(path, "rb").read().decode("latin-1")
    except OSError:
        print(f"SKIP {f}: unreadable")
        continue
    lines = data.split("\n")
    inserts = []
    for ln, name in sorted(items):
        pos = None
        for k in range(ln - 1, min(ln + 3, len(lines))):
            if k >= 0 and re.match(r"[ \t]*#[ \t]*define[ \t]+" + re.escape(name) + r"\b", lines[k]):
                pos = k
                break
        if pos is None:
            for k in range(max(0, ln - 4), ln - 1):
                if re.match(r"[ \t]*#[ \t]*define[ \t]+" + re.escape(name) + r"\b", lines[k]):
                    pos = k
                    break
        if pos is None:
            print(f"SKIP {f}:{ln} {name}: no `#define {name}` near the reported line")
            continue
        j = pos - 1
        while j >= 0 and not lines[j].strip():
            j -= 1
        if j >= 0 and re.match(r"[ \t]*#[ \t]*undef[ \t]+" + re.escape(name) + r"\b", lines[j]):
            continue
        indent = re.match(r"[ \t]*", lines[pos]).group(0)
        cr = "\r" if lines[pos].endswith("\r") else ""
        inserts.append((pos, f"{indent}#undef {name}{cr}"))
        done += 1
        print(f"{'FIX ' if apply_ else 'plan'} {f}:{pos + 1} #undef {name}")
    if apply_ and inserts:
        for pos, text in sorted(inserts, reverse=True):
            lines.insert(pos, text)
        open(path, "wb").write("\n".join(lines).encode("latin-1"))
print(f"{done} #undef line(s) {'written' if apply_ else 'planned'}")
