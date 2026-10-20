#!/usr/bin/env python3
"""scripts/lpc_fix_untyped_params.py [--apply] (SLUG [DIAGNOSTICS.tsv] | --all)

`Missing type for argument`: a parameter written without a type (`int cant_be_dominated(targ)`, `varargs void set_spell(int mylevel, myclevel)`,
`void f(victim, limb, damage)`).  The old driver took an untyped parameter as `mixed`; this one stops at the first one and the whole object fails.
Each untyped parameter gets `mixed ` in front of its name, which is what it was.

The diagnostics row points at the parameter's name (columns are 1-based BYTES).  Fixed only when the identifier there is preceded by `(` or `,` and
followed by `,` or `)`.  One typo shape is repaired instead of typed: `object room, object, victim, int dam` (a comma where the space belongs):
`TYPE, name` -> `TYPE name` when the word in front of the comma is a bare type word, since typing `victim` would leave a nameless `object` parameter
and shift every later one.  Anything else is listed.  Binary-safe; edits go from the end of each file to its start.

Without --apply the plan is printed.  Rows come from DIAGNOSTICS.tsv (default $LPC_SCRATCH/lpcw-SLUG/diagnostics.tsv, or the newest scan under
$LPC_SCRATCH/tkfix/diag and fresh/out*); `--all` takes every lib's newest list.  Load-check afterwards (scripts/lpc_listcheck.sh at HEAD and in the tree)."""
import glob
import os
import re
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SCRATCH = os.environ.get("LPC_SCRATCH") or os.path.expanduser("~/.cache/lpc-scratch")
TYPEWORD = re.compile(rb"(?:^|[\s(,*])(?:int|string|object|mapping|mixed|float|function|status|buffer|void|class\s+\w+)\s*\**\s*$")


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
    edits = []          # (start, end, replacement)
    listed = []
    for ln, col in rows:
        if ln < 1 or ln > len(starts):
            listed.append((ln, "line out of range"))
            continue
        pos = starts[ln - 1] + col - 1
        m = re.compile(rb"[A-Za-z_][A-Za-z0-9_]*").match(b, pos)
        if not m or (pos > 0 and (b[pos - 1:pos].isalnum() or b[pos - 1:pos] == b"_")):
            listed.append((ln, "no identifier at the reported position"))
            continue
        i = pos - 1
        while i >= 0 and b[i:i + 1] in b" \t\r\n":
            i -= 1
        j = m.end()
        while j < len(b) and b[j:j + 1] in b" \t\r\n":
            j += 1
        if b[i:i + 1] not in (b"(", b",") or b[j:j + 1] not in (b",", b")", b";"):
            listed.append((ln, "not a parameter list entry"))
            continue
        if b[i:i + 1] == b",":
            # `object room, object, victim`: the word in front of the comma is a bare type word
            lo = max(0, i - 60)
            seg = b[lo:i]
            tm = TYPEWORD.search(seg)
            if tm and re.search(rb"[,(]\s*(?:int|string|object|mapping|mixed|float|function|status|buffer)\s*\**\s*$", seg):
                edits.append((i, pos, b" "))              # drop the comma: `object, victim` -> `object victim`
                continue
        edits.append((pos, pos, b"mixed "))
    if not edits:
        return None, 0, listed
    out = bytearray(b)
    for s, e, rep in sorted(set(edits), reverse=True):
        out[s:e] = rep
    return bytes(out), len(set(edits)), listed


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
            if len(f) < 5 or f[3] != "error" or not f[4].startswith("Missing type for argument"):
                continue
            key = (f[0], f[1], f[2])
            if key in seen:
                continue
            seen.add(key)
            by.setdefault(f[0], []).append((int(f[1]), int(f[2])))
        work = f"{REPO}/libs/{slug}/work"
        for rel, rows in sorted(by.items()):
            p = work + rel
            if not os.path.isfile(p):
                continue
            new, n, listed = fix_file(p, rows)
            for ln, why in listed:
                print(f"LIST\t{slug}\t{rel}:{ln}\t{why}")
                lst += 1
            if new is not None:
                print(f"FIX\t{slug}\t{rel}\t{n}")
                total += n
                if apply_:
                    with open(p, "wb") as fh:
                        fh.write(new)
    print(f"{total} parameter(s) {'fixed' if apply_ else 'fixable'}, {lst} listed", file=sys.stderr)


if __name__ == "__main__":
    main()
