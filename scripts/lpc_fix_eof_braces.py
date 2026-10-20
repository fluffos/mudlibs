#!/usr/bin/env python3
"""scripts/lpc_fix_eof_braces.py (SLUG... | --list FILE) [--apply]

A file that stops one or two `}` short of the end: `syntax error, unexpected end of file`, and the object (or every object that
inherits it) never loads.  The last byte or two of an archive file went missing in the conversion (`}` and the line break after it), or
the author's editor cut the file; 160 files in the corpus miss one brace and 32 miss two (KB 03 4.6).

A file is repaired when, with comments, strings and `@TEXT` blocks masked, its braces are open by one or two at the end of the file,
its parentheses and brackets balance, and the last thing in it is a finished statement or block (`;` or `}`): the closing braces are
appended, one per line, with the file's own line ending.  A file whose last code character is anything else (an operator, a comma, an
open call) lost more than a brace and is left alone; so is a file whose braces are open by more than two or closed too often.  The
repair makes the file compile when the damage really was at the end; whether a `}` that belonged earlier now closes the wrong block
is what the load check afterwards shows (scripts/lpc_listcheck.sh, scripts/lpc_load_diff.py): a file that still fails goes back as it was.

Without --apply the plan is printed: `slug<TAB>/path<TAB>braces appended`.  The files come from scanning the libs named, or from `--list FILE`
(`slug<TAB>/path` per line, e.g. the first-error rows `unexpected end of file` of a scan's diagnostics).  Wizard, backup, data and
`old`/`bak` paths are skipped like the scanner does unless the file is named in a list."""
import os
import re
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from lpc_fix_void_return import code_mask  # noqa: E402
from lpc_scan_high_bytes import SKIP  # noqa: E402

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
GENERATED = {"longyunmeng_binary", "wllz3"}


def plan(b):
    """number of closing braces to append, or 0"""
    m = code_mask(b, heredoc=True)
    depth = {b"{": 0, b"(": 0, b"[": 0}
    close = {0x7D: 0x7B, 0x29: 0x28, 0x5D: 0x5B}
    d = {0x7B: 0, 0x28: 0, 0x5B: 0}
    last = None
    for i, c in enumerate(b):
        if not m[i]:
            continue
        if c in d:
            d[c] += 1
        elif c in close:
            d[close[c]] -= 1
            if d[close[c]] < 0:
                return 0
        if c not in b" \t\r\n\f\v":
            last = c
    if d[0x28] or d[0x5B] or d[0x7B] not in (1, 2):
        return 0
    if last not in (0x3B, 0x7D):
        return 0
    return d[0x7B]


def fix(b, n):
    nl = b"\r\n" if b.count(b"\r\n") * 2 > b.count(b"\n") else b"\n"
    out = bytearray(b)
    if not out.endswith(b"\n"):
        out += nl
    for _ in range(n):
        out += b"}" + nl
    return bytes(out)


def main():
    args = sys.argv[1:]
    apply = "--apply" in args
    lst = args[args.index("--list") + 1] if "--list" in args else None
    slugs = [a for a in args if not a.startswith("--") and a != lst]
    cand = []
    if lst:
        seen = set()
        for ln in open(lst, encoding="utf-8", errors="replace"):
            f = ln.rstrip("\n").split("\t")
            if len(f) >= 2 and f[1].startswith("/") and (f[0], f[1]) not in seen and f[0] not in GENERATED:
                seen.add((f[0], f[1]))
                if not slugs or f[0] in slugs:
                    cand.append((f[0], f[1], f"libs/{f[0]}/work{f[1]}"))
    else:
        if not slugs:
            sys.exit(__doc__)
        for slug in slugs:
            files = subprocess.run(["git", "ls-files", "-z", "--", f"libs/{slug}/work"], cwd=REPO, capture_output=True).stdout.split(b"\0")
            for f in files:
                try:
                    p = f.decode()
                except UnicodeDecodeError:
                    continue
                rel = "/" + p.split("/work/", 1)[1] if "/work/" in p else ""
                if p.endswith((".lpc", ".h")) and slug not in GENERATED and rel and not SKIP.search(rel):
                    cand.append((slug, rel, p))
    n = 0
    for slug, rel, p in cand:
        try:
            b = open(os.path.join(REPO, p), "rb").read()
        except OSError:
            continue
        k = plan(b)
        if not k:
            continue
        n += 1
        print(f"{slug}\t{rel}\t{k}")
        if apply:
            with open(os.path.join(REPO, p), "wb") as fh:
                fh.write(fix(b, k))
    print(f"{n} file(s) {'repaired' if apply else 'repairable'}", file=sys.stderr)


if __name__ == "__main__":
    main()
