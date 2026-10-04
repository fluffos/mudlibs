#!/usr/bin/env python3
"""scripts/lpc_rename_ident.py SLUG OLD NEW FILE... [--apply]

Rename one identifier in the code of the given files (paths as the driver prints them: `/d/mines/objects/mon/mob_eq2.lpc`,
or relative to libs/SLUG/work).  Comments, string and character literals and preprocessor lines are left alone, and so is
every use that is a function name or a member of another object (`ob->OLD`, `::OLD`, `OLD(`).  Use it for the private-name
collisions of KB 04 section 6.10 (`Redeclaration of global variable 'x'` where two inherited programs, or a leaf and its base,
each declare their own): rename the variable in the file that declares it, and every use follows.

Without --apply it prints the number of hits per file.  Refuses a file that already uses NEW as an identifier.  Edits are
byte-exact (line endings kept)."""
import os
import re
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
a = sys.argv[1:]
if len(a) < 4 or a[0].startswith("--"):
    sys.exit(__doc__)
slug, old, new = a[0], a[1], a[2]
apply_ = "--apply" in a
files = [x for x in a[3:] if not x.startswith("--")]
W = f"{REPO}/libs/{slug}/work"


def mask(src):
    """same-length copy with comments, string/char literal contents and preprocessor lines blanked"""
    out, i, n = list(src), 0, len(src)
    bol = True
    while i < n:
        c, two = src[i], src[i:i + 2]
        if bol and c in " \t":
            i += 1
            continue
        if bol and c == "#":
            j = i
            while j < n and src[j] != "\n":
                if src[j] == "\\" and src[j + 1:j + 2] == "\n":
                    j += 1
                j += 1
            for k in range(i, j):
                if src[k] != "\n":
                    out[k] = " "
            i = j
            continue
        bol = False
        if c == "\n":
            bol = True
            i += 1
        elif two == "//":
            while i < n and src[i] != "\n":
                out[i] = " "
                i += 1
        elif two == "/*":
            j = src.find("*/", i + 2)
            j = n if j < 0 else j + 2
            for k in range(i, j):
                if src[k] != "\n":
                    out[k] = " "
            i = j
        elif c in "\"'":
            j = i + 1
            while j < n and src[j] != c and src[j] != "\n":
                j += 2 if src[j] == "\\" else 1
            for k in range(i + 1, min(j, n)):
                out[k] = " "
            i = j + 1
        else:
            i += 1
    return "".join(out)


total = 0
for f in files:
    path = f if os.path.isabs(f) and os.path.exists(f) else W + (f if f.startswith("/") else "/" + f)
    raw = open(path, "rb").read().decode("latin-1")
    m = mask(raw)
    if re.search(r"(?<![\w])" + re.escape(new) + r"(?![\w])", m):
        print(f"SKIP {f}: already uses {new}")
        continue
    hits = []
    for mm in re.finditer(r"(?<![\w])" + re.escape(old) + r"(?![\w])", m):
        before = m[max(0, mm.start() - 2):mm.start()]
        after = m[mm.end():mm.end() + 40].lstrip(" \t")
        if before.endswith("->") or before.endswith("::") or before.endswith(".") or after.startswith("("):
            continue
        hits.append(mm.start())
    total += len(hits)
    print(f"{'FIX ' if apply_ else 'plan'} {f}: {len(hits)} use(s)")
    if apply_ and hits:
        out = raw
        for pos in sorted(hits, reverse=True):
            out = out[:pos] + new + out[pos + len(old):]
        open(path, "wb").write(out.encode("latin-1"))
print(f"{total} use(s) in {len(files)} file(s)")
