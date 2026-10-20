#!/usr/bin/env python3
"""scripts/lpc_fix_cast_cmp.py [--apply] (SLUG [DIAGNOSTICS.tsv] | --all)

`Arguments to > do not have compatible types : ( string vs int ).`, one cause: a `(string)` cast in front of a number that is compared with a number
(`if((string)TP->query_level() > 12 && interactive(TP))`, `(string)this_player()->query_alignment() > -5`, `(string)inven[i]->query_stats("dex") < 10`).  In the
MudOS these libs were written for a cast was a promise to the compiler, no conversion, so the test compared two ints at run time; this driver types the
expression and stops at the comparison, and the object, with everything that inherits it, never loads.  What the author meant is `(int)`: the cast
word becomes `int`, which converts nothing here either (KB 06: a cast never converts) and says what the call returns.

The diagnostics row points into the comparison; the cast is the nearest `(string)` in front of it on the line.  The same error without a cast is a plain variable
declared `string` that holds a number (`string str, light_level; ... light_level = this_player()->test_dark(); if (light_level < 3)`, `string wimpy; ... wimpy > 100`):
it is declared `mixed` (the declaration statement's type word, as scripts/lpc_fix_bad_assign.py does: it holds what it was given, as before), when the left operand of every
comparison on the line is that one name; anything else (an array element, two names) is listed.  Rows come from DIAGNOSTICS.tsv
(default $LPC_SCRATCH/lpcw-SLUG/diagnostics.tsv or the newest scan); `--all` takes every lib's newest list.  Binary-safe, idempotent.  Load-check afterwards
(scripts/lpc_listcheck.sh).  Without --apply the plan is printed (`FIX<TAB>slug<TAB>/path<TAB>n`, `LIST<TAB>slug<TAB>/path:line<TAB>source line`)."""
import glob
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from lpc_fix_void_return import code_mask, depth_map  # noqa: E402
from lpc_fix_bad_assign import newest_diag, decl_for  # noqa: E402

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
CMPVAR = re.compile(rb"(?<![\w>.\]])([A-Za-z_]\w*)\s*(?:<=|>=|==|!=|<|>)(?!=)")
ROW = re.compile(r"(?:Arguments to (?:<=|>=|<|>) do not have compatible types : |(?:==|!=) always (?:false|true) because of incompatible types )\( string vs (int|object) \)")
OPS = rb"(?:<=|>=|==|!=|<|>)"


def fix_file(path, rows):
    b = open(path, "rb").read()
    mask = code_mask(b)
    starts = [0]
    for i, ch in enumerate(b):
        if ch == 10:
            starts.append(i + 1)
    edits = []
    listed = []
    vnames = []
    dep = depth_map(b, mask)
    for ln, col, typ in rows:
        if ln < 1 or ln > len(starts):
            continue
        pos = starts[ln - 1] + col - 1
        ls = starts[ln - 1]
        le = b.find(b"\n", ls)
        line = b[ls:le if le >= 0 else len(b)]
        rel = pos - ls
        # the row points somewhere in the comparison (its left operand, or the token behind it): the cast is the nearest `(string)` at or before that
        # point whose operand is followed by a relational operator, with no `&&`, `||` or `;` between
        m = None
        casts = []
        for c in re.finditer(rb"\(\s*string\s*\)", line):
            seg = line[c.end():].replace(b"->", b"--")
            ok = re.match(rb"[^;{}&|]*?" + OPS + rb"(?!=)\s*-?\d", seg) if typ == "int" else re.match(rb"[^;{}&|]*?" + OPS, seg)
            if ok and mask[ls + c.start()]:
                casts.append(c)             # every such cast on the line: the compiler reports one comparison per statement
                if c.start() <= rel:
                    m = c
        if not m and casts:
            m = casts[0]
        if m:
            for c in (casts if typ == "int" else [m]):
                w = ls + c.start() + c.group(0).index(b"string")
                edits.append((w, w + 6, typ.encode()))
            continue
        if not m:
            # a plain variable declared `string` that holds a number: the left operand of every comparison on the line is the same name
            names = {c.group(1) for c in CMPVAR.finditer(line) if mask[ls + c.start(1)]}
            d = None
            if len(names) == 1:
                name = next(iter(names)).decode()
                d = decl_for(b, mask, dep, name, min(pos, len(b) - 1))
            if not d:
                listed.append((ln, line.decode("utf-8", "replace").strip()[:120]))
                continue
            t0, t1, star = d
            if b[t0:t1] != b"string":
                listed.append((ln, line.decode("utf-8", "replace").strip()[:120] + "  [declared " + b[t0:t1].decode() + "]"))
                continue
            edits.append((t0, t1, b"mixed"))
            if star is not None:
                edits.append((star, star + 1, b""))
            vnames.append(name)
            continue
        w = ls + m.start() + m.group(0).index(b"string")
        edits.append((w, w + 6, b"int"))
    if not edits:
        return None, 0, [], listed
    out = bytearray(b)
    for s, e, rep in sorted(set(edits), reverse=True):
        out[s:e] = rep
    ncasts = sum(1 for s, e, rep in set(edits) if rep in (b"int", b"object"))
    return bytes(out), ncasts, sorted(set(vnames)), listed


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
            if len(f) < 5 or f[3] != "error" or not ROW.match(f[4]):
                continue
            key = (f[0], f[1], f[2])
            if key in seen:
                continue
            seen.add(key)
            by.setdefault(f[0], []).append((int(f[1]), int(f[2]), ROW.match(f[4]).group(1)))
        work = f"{REPO}/libs/{slug}/work"
        for rel, rows in sorted(by.items()):
            p = work + rel
            if not os.path.isfile(p):
                continue
            new, n, vnames, listed = fix_file(p, rows)
            for ln, text in listed:
                print(f"LIST\t{slug}\t{rel}:{ln}\t{text}")
                lst += 1
            if new is not None:
                print(f"FIX\t{slug}\t{rel}\t{n} cast(s)" + (f", mixed {','.join(vnames)}" if vnames else ""))
                total += n + len(vnames)
                if apply_:
                    with open(p, "wb") as fh:
                        fh.write(new)
    print(f"{total} cast(s) / variable(s) {'retyped' if apply_ else 'retypable'}, {lst} listed", file=sys.stderr)


if __name__ == "__main__":
    main()
