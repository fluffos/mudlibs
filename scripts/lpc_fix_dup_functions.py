#!/usr/bin/env python3
"""scripts/lpc_fix_dup_functions.py --diag DIR [SLUG...] [--apply]

A function defined twice, word for word, in one file (KB 04 section 6.6).  `int query_autoload() { return 1; }` pasted again under
the first one (the xyzx family's `clone/book/lbook5`, `pixie_book`), `greeting()` twice in the Journey-to-the-West `d/pkdao/room1`: the
driver says `Redeclaration of function 'query_autoload'.` and the object never compiles.

--diag DIR  the scan output of scripts/lpc_warnings.py (DIR/diag-SLUG.tsv).  For every file with a `Redeclaration of function` error
            all definitions of that name in the file are found (comments and strings masked, braces matched); when their texts are
            equal apart from white space, every one after the first is deleted (its lines, when nothing else is on them).  Definitions
            that differ are left (SKIP with the reason): which one is meant needs a reader.  Only definitions at file level; test
            fixtures (`/tests/`), `*_old` and `.dat_old` files, wizard and backup dirs are not touched.
Binary-safe, line endings kept.  Without --apply the plan is printed (FIX lines); idempotent."""
import collections
import glob
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from lpc_fix_void_return import code_mask  # noqa: E402

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SKIP = re.compile(r"/(u|w|wiz|wizard|wizards|open|players|backup|backups|old|bak|log|data|doc|docs|example|examples|test|tests|tmp|attic)/|[-_.](bak|old|orphaned-driver-src)/|\.(bak|BAK|old|orig)(\.lpc)?$|_old\.lpc$|\.dat_old|/test[_-][^/]*\.lpc$")
VIRTUAL = {"es1", "es1_win", "esI", "pd"}   # a virtual server compiles their `_name.lpc` templates its own way (the three copies of _bed2.lpc load fine)
MSG = re.compile(r"Redeclaration of function '([^']+)'")


def match_close(code, i, o, c):
    d = 0
    for j in range(i, len(code)):
        ch = code[j:j + 1]
        if ch == o:
            d += 1
        elif ch == c:
            d -= 1
            if d == 0:
                return j
    return -1


def definitions(b, name):
    mask = code_mask(b, heredoc=True)
    code = bytes(c if m else 32 for c, m in zip(b, mask))
    pat = re.compile(rb"(?m)^[ \t]*(?:(?:varargs|static|nomask|private|protected|public|nosave)[ \t]+)*(?:void|int|string|mixed|object|mapping|float|status|function)[ \t]*\**[ \t]*" + re.escape(name.encode()) + rb"[ \t]*\(")
    res = []
    for m in pat.finditer(code):
        po = m.end() - 1
        pc = match_close(code, po, b"(", b")")
        if pc < 0:
            continue
        k = pc + 1
        while k < len(code) and code[k:k + 1] in b" \t\r\n":
            k += 1
        if code[k:k + 1] != b"{":
            continue
        e = match_close(code, k, b"{", b"}")
        if e < 0:
            continue
        res.append((m.start(), e + 1, re.sub(rb"\s+", b" ", code[m.start():e + 1]).strip()))
    return res


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
        if only and slug not in only or slug in VIRTUAL:
            continue
        if not os.path.isdir(f"{REPO}/libs/{slug}/work") or os.path.exists(f"{REPO}/libs/{slug}/work/.git"):
            continue
        names = collections.defaultdict(set)
        for l in open(f, encoding="utf-8", errors="replace"):
            p = l.rstrip("\n").split("\t")
            if len(p) >= 5 and p[3] == "error" and not SKIP.search(p[0]):
                m = MSG.match(p[4])
                if m:
                    names[p[0]].add(m.group(1))
        for path, ns in sorted(names.items()):
            full = f"{REPO}/libs/{slug}/work{path}"
            try:
                b = open(full, "rb").read()
            except OSError:
                continue
            cuts = []
            for name in sorted(ns):
                defs = definitions(b, name)
                if len(defs) < 2:
                    nskip += 1
                    print(f"SKIP  {slug} {path} {name}(): {len(defs)} definition(s) in the file (the other comes from an include)")
                    continue
                if len({d[2] for d in defs}) != 1:
                    nskip += 1
                    print(f"SKIP  {slug} {path} {name}(): {len(defs)} definitions that differ")
                    continue
                for s, e, _ in defs[1:]:
                    ls = b.rfind(b"\n", 0, s) + 1
                    le = b.find(b"\n", e)
                    le = len(b) if le < 0 else le + 1
                    if not b[ls:s].strip() and not b[e:le].strip():
                        cuts.append((ls, le))
                    else:
                        cuts.append((s, e))
                    nfix += 1
                    print(f"FIX   {slug} {path} {name}(): delete the copy at line {b.count(chr(10).encode(), 0, s) + 1}")
            if cuts:
                nfile += 1
                if apply:
                    out, last = [], 0
                    for s, e in sorted(cuts):
                        out.append(b[last:s])
                        last = e
                    out.append(b[last:])
                    open(full, "wb").write(b"".join(out))
    print(f"{nfix} duplicate(s) in {nfile} file(s), {nskip} left" + ("" if apply else " (plan only; --apply writes)"))


if __name__ == "__main__":
    main()
