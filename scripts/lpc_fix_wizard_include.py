#!/usr/bin/env python3
"""scripts/lpc_fix_wizard_include.py --diag DIR [SLUG...] [--apply]

`#include "/u/swordman/newbie/npc/sujia.h"` in an area file (KB 04 section 6.1).  The author wrote the object in his wizard directory,
included a header that sat next to it there, and moved the object into the area without moving the include line; the archive has no
`/u/swordman/` (or the header is not in it), so the object dies with `Cannot #include /u/swordman/newbie/npc/sujia.h` and never loads
(hc: 34 files, the `jobsys/gfjob` NPCs include `/u/poi/job/npc/npc.h`, whose copy is `jobsys/gfjob/npc/npc.h`).

--diag DIR  the scan output of scripts/lpc_warnings.py (DIR/diag-SLUG.tsv).  For every `Cannot #include /u/...` (also /w/, /wiz/, /open/,
            /players/) row of a file outside the wizard directories, the lib is searched for a file of that name outside the wizard,
            backup and test directories.  When every copy found has the same bytes the directive is rewritten to the copy nearest to
            the includer (same directory first, then the longest shared path prefix).  A name with no copy, or with copies that differ,
            is reported and left.
Binary-safe, line endings kept.  Without --apply the plan is printed (FIX / SKIP lines); idempotent."""
import glob
import hashlib
import os
import re
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
WIZ = re.compile(r"^/(u|w|wiz|wizard|wizards|open|players)/")
SKIP = re.compile(r"/(u|w|wiz|wizard|wizards|open|players|backup|backups|old|bak|log|data|doc|docs|example|examples|test|tests|tmp|attic)/|[-_.](bak|old|orphaned-driver-src)/|\.(bak|BAK|old|orig)(\.lpc)?$")
MSG = re.compile(r"Cannot #include (/(?:u|w|wiz|wizard|wizards|open|players)/\S+)$")


def index(work):
    idx = {}
    for dp, dn, fn in os.walk(work):
        rel = "/" + os.path.relpath(dp, work).replace(os.sep, "/") + "/"
        if rel == "/./":
            rel = "/"
        if SKIP.search(rel):
            dn[:] = []
            continue
        for f in fn:
            idx.setdefault(f, []).append(rel + f)
    return idx


def common(a, b):
    n = 0
    for x, y in zip(a.split("/"), b.split("/")):
        if x != y:
            break
        n += 1
    return n


def main():
    args = sys.argv[1:]
    apply = "--apply" in args
    diag = None
    if "--diag" in args:
        i = args.index("--diag")
        diag = args[i + 1]
        del args[i:i + 2]
    only = [a for a in args if not a.startswith("--")]
    if not diag:
        sys.exit(__doc__)
    nfix = nfile = nskip = 0
    for f in sorted(glob.glob(os.path.join(diag, "diag-*.tsv"))):
        slug = os.path.basename(f)[5:-4]
        if only and slug not in only:
            continue
        work = f"{REPO}/libs/{slug}/work"
        if not os.path.isdir(work) or os.path.exists(work + "/.git") or slug in ("wllz3", "longyunmeng_binary"):
            continue
        rows = {}
        for l in open(f, encoding="utf-8", errors="replace"):
            p = l.rstrip("\n").split("\t")
            if len(p) >= 5 and p[3] == "error" and not WIZ.match(p[0]) and not SKIP.search(p[0]):
                m = MSG.match(p[4])
                if m:
                    rows[(p[0], int(p[1]), m.group(1))] = 1
        if not rows:
            continue
        idx = index(work)
        byfile = {}
        for (path, line, inc) in rows:
            byfile.setdefault(path, []).append((line, inc))
        for path, items in sorted(byfile.items()):
            full = work + path
            b = open(full, "rb").read()
            lines = b.split(b"\n")
            changed = 0
            for line, inc in sorted(items):
                name = inc.rsplit("/", 1)[1]
                cands = [c for c in idx.get(name, []) if not WIZ.match(c)]
                digests = {hashlib.md5(open(work + c, "rb").read()).hexdigest() for c in cands}
                if not cands:
                    print(f"SKIP  {slug} {path}:{line}: {inc}: no copy of {name} outside the wizard directories")
                    nskip += 1
                    continue
                if len(digests) > 1:
                    print(f"SKIP  {slug} {path}:{line}: {inc}: {len(cands)} copies of {name} that differ")
                    nskip += 1
                    continue
                best = sorted(cands, key=lambda c: (-common(os.path.dirname(c), os.path.dirname(path)), len(c), c))[0]
                if line - 1 >= len(lines):
                    continue
                pat = re.compile(rb"^([ \t]*#[ \t]*include[ \t]*)([\"<])" + re.escape(inc.encode()) + rb"([\">])")
                m = pat.match(lines[line - 1])
                if not m:
                    continue
                lines[line - 1] = pat.sub(rb'\1"' + best.encode() + b'"', lines[line - 1], count=1)
                changed += 1
                nfix += 1
                print(f"FIX   {slug} {path}:{line}: {inc} -> {best}")
            if changed:
                nfile += 1
                if apply:
                    open(full, "wb").write(b"\n".join(lines))
    print(f"{nfix} include(s) in {nfile} file(s), {nskip} left" + ("" if apply else " (plan only; --apply writes)"))


if __name__ == "__main__":
    main()
