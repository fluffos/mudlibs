#!/usr/bin/env python3
"""scripts/lpc_fix_init_array.py [--apply] (SLUG [DIAGNOSTICS.tsv] | --all)

`Type mismatch ( string vs mixed * ) when initializing NAME`: a variable declared with a plain type and initialized with an array literal,
`string COLORS = ({ "%^RED%^", ... });` or the second declarator of `string me, mySpells = ({ ... });`.  MudOS (and every driver without
type checking) let the variable hold the array, and every use in the file treats it as one (`COLORS[random(sizeof(COLORS))]`); this driver
stops at the declaration and the object, and everything that inherits it, never loads.  The declarator gets its star: `string *COLORS`,
`string me, *mySpells`.  (In this grammar the star belongs to one declarator: `string *a, b` makes only `a` an array, KB 04 section 6.10.)

The diagnostics row points at the end of the initializer (the closing `)`); the declarator is the nearest `NAME = ({` before it.  Only an
array-literal initializer (`({`) is touched, and only when the name has no star yet.  Anything else is listed.  Binary-safe.

Without --apply the plan is printed.  Rows come from DIAGNOSTICS.tsv (default $LPC_SCRATCH/lpcw-SLUG/diagnostics.tsv, or the newest scan under
$LPC_SCRATCH/tkfix/diag and fresh/out*); `--all` takes every lib's newest list.  Load-check afterwards (scripts/lpc_listcheck.sh at HEAD and in the tree)."""
import glob
import os
import re
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SCRATCH = os.environ.get("LPC_SCRATCH") or os.path.expanduser("~/.cache/lpc-scratch")
ROW = re.compile(r"Type mismatch \( (?:string|object|int|float|mapping|mixed|function|status) vs mixed \* \) when initializing (\w+)")


def newest_diag(slug):
    best = None
    for pat in (f"{SCRATCH}/lpcw-{slug}/diagnostics.tsv", f"{SCRATCH}/tkfix/diag/{slug}.tsv", f"{SCRATCH}/fresh/out*/diag-{slug}.tsv"):
        for p in glob.glob(pat):
            if best is None or os.path.getmtime(p) > os.path.getmtime(best):
                best = p
    return best


def fix_file(path, rows):
    b = open(path, "rb").read()
    starts = [0]
    for i, ch in enumerate(b):
        if ch == 10:
            starts.append(i + 1)
    edits = set()
    listed = []
    for ln, col, name in rows:
        if ln < 1 or ln > len(starts):
            listed.append((ln, name, "line out of range"))
            continue
        pos = starts[ln - 1] + col - 1
        lo = max(0, pos - 4000)
        seg = b[lo:pos + 1]
        cands = list(re.finditer(rb"(?<![\w*])(\*?\s*)(" + name.encode() + rb")\s*=\s*\(\{", seg))
        if not cands:
            listed.append((ln, name, "no `NAME = ({` before the reported position"))
            continue
        mt = cands[-1]
        if mt.group(1).strip() == b"*":
            listed.append((ln, name, "already has a star"))
            continue
        # the declarator must follow a type word or a comma, not an assignment statement
        before = seg[:mt.start(2)].rstrip()
        if not (before.endswith(b",") or re.search(rb"(?:int|string|object|mapping|mixed|float|function|status|buffer)\s*$", before)):
            listed.append((ln, name, "not a declarator"))
            continue
        edits.add(lo + mt.start(2))
    if not edits:
        return None, 0, listed
    out = bytearray(b)
    for e in sorted(edits, reverse=True):
        out[e:e] = b"*"
    return bytes(out), len(edits), listed


def main():
    a = sys.argv[1:]
    apply_ = "--apply" in a
    args = [x for x in a if not x.startswith("--")]
    if "--all" in a:
        slugs = sorted(os.path.basename(os.path.dirname(p)) for p in glob.glob(f"{REPO}/libs/*/work"))
        tsv = None
    elif args:
        slugs = [args[0]]
        tsv = args[1] if len(args) > 1 else None
    else:
        sys.exit(__doc__)
    total = lst = 0
    for slug in slugs:
        t = tsv or newest_diag(slug)
        if not t:
            continue
        by = {}
        seen = set()
        for row in open(t, encoding="utf-8", errors="replace"):
            f = row.rstrip("\n").split("\t")
            if len(f) < 5 or f[3] != "error":
                continue
            mm = ROW.match(f[4])
            if not mm:
                continue
            key = (f[0], f[1], f[2])
            if key in seen:
                continue
            seen.add(key)
            by.setdefault(f[0], []).append((int(f[1]), int(f[2]), mm.group(1)))
        work = f"{REPO}/libs/{slug}/work"
        for rel, rows in sorted(by.items()):
            p = work + rel
            if not os.path.isfile(p):
                continue
            new, n, listed = fix_file(p, rows)
            for ln, name, why in listed:
                print(f"LIST\t{slug}\t{rel}:{ln}\t{name}\t{why}")
                lst += 1
            if new is not None:
                print(f"FIX\t{slug}\t{rel}\t{n}")
                total += n
                if apply_:
                    with open(p, "wb") as fh:
                        fh.write(new)
    print(f"{total} declarator(s) {'fixed' if apply_ else 'fixable'}, {lst} listed", file=sys.stderr)


if __name__ == "__main__":
    main()
