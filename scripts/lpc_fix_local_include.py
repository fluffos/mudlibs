#!/usr/bin/env python3
"""scripts/lpc_fix_local_include.py --diag DIR [SLUG...] [--apply]

`#include <hedi.h>` where hedi.h sits in the directory of the including file (KB 04 section 6.1).  The old driver searched the includer's own
directory for an angle-bracket name; this one searches only the include path, so the object dies with `Cannot #include hedi.h` (hy5: 24 files,
hy 17, wxddym 11 ...).  A master `get_include_path()` that prepends the includer's directory fixes it only for compiles triggered at run time:
a preload or `lpcc --batch` compile never asks the master, so the scan cannot tell whether it worked.  The quoted form works everywhere, so this
rewrites the directive: `#include <hedi.h>` -> `#include "hedi.h"`.

--diag DIR  the scan output of scripts/lpc_warnings.py (DIR/diag-SLUG.tsv).  For every `Cannot #include NAME` row where NAME is a plain file name
            (no directory part) that exists next to the including file, the directive on the reported line is rewritten.  A name that is also in
            the lib's own include directory is left (the scan would not have failed on it).  Wizard, backup and test dirs are not touched.
Binary-safe, line endings kept.  Without --apply the plan is printed (FIX lines); idempotent."""
import glob
import os
import re
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SKIP = re.compile(r"/(u|w|wiz|wizard|wizards|players|backup|backups|old|bak|log|data|doc|docs|example|examples|test|tests|tmp|attic)/|[-_.](bak|old|orphaned-driver-src)/|\.(bak|BAK|old|orig)(\.lpc)?$|_old\.lpc$")
MSG = re.compile(r"Cannot #include ([^/\\<>\"]+\.(?:h|lpc|c|inc))$")


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
    nfix = nfile = 0
    for f in sorted(glob.glob(os.path.join(diag, "diag-*.tsv"))):
        slug = os.path.basename(f)[5:-4]
        if only and slug not in only:
            continue
        work = f"{REPO}/libs/{slug}/work"
        if not os.path.isdir(work) or os.path.exists(work + "/.git"):
            continue
        if slug in ("wllz3", "longyunmeng_binary"):    # generated trees (rebuild.sh + patch)
            continue
        rows = {}
        for l in open(f, encoding="utf-8", errors="replace"):
            p = l.rstrip("\n").split("\t")
            if len(p) >= 5 and p[3] == "error" and not SKIP.search(p[0]):
                m = MSG.match(p[4])
                if m and os.path.exists(os.path.join(work + os.path.dirname(p[0]), m.group(1))):
                    rows[(p[0], int(p[1]), m.group(1))] = 1
        byfile = {}
        for (path, line, name) in rows:
            byfile.setdefault(path, []).append((line, name))
        for path, items in sorted(byfile.items()):
            full = work + path
            b = open(full, "rb").read()
            lines = b.split(b"\n")
            changed = 0
            for line, name in sorted(items):
                if line - 1 >= len(lines):
                    continue
                pat = re.compile(rb"^([ \t]*#[ \t]*include[ \t]*)<" + re.escape(name.encode()) + rb">")
                if pat.match(lines[line - 1]):
                    lines[line - 1] = pat.sub(rb'\1"' + name.encode().replace(b"\\", b"\\\\") + b'"', lines[line - 1])
                    changed += 1
                    nfix += 1
                    print(f"FIX   {slug} {path}:{line}: <{name}> -> \"{name}\"")
            if changed:
                nfile += 1
                if apply:
                    open(full, "wb").write(b"\n".join(lines))
    print(f"{nfix} include(s) in {nfile} file(s)" + ("" if apply else " (plan only; --apply writes)"))


if __name__ == "__main__":
    main()
