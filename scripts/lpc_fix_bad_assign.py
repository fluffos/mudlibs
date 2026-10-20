#!/usr/bin/env python3
"""scripts/lpc_fix_bad_assign.py [--apply] (SLUG [DIAGNOSTICS.tsv] | --all)

`Bad assignment ( int vs string ).`: a variable declared with one type and assigned a value of another (`int value; ... value = "   " + value;`,
`string halves; halves = ({ ... });`, `object who; who = "gandalf";`, `string *names; names = "bob";`).  MudOS never compared the two, the variable
simply held what it was given, and every later use treats it that way; this driver stops at the first assignment and the object, and everything
that inherits it, never loads.  The variable is declared `mixed`, which is what it was: the type word of its declaration statement
(`int a, b, value;` -> `mixed a, b, value;`; for `string *names, other;` only `names` loses its star: `mixed names, other;` is wrong for nobody, `mixed *`
would keep the array type) and nothing else changes.  A function parameter is retyped the same way (`void f(string value)`).

The diagnostics row points at the end of the assignment (the `;`, `)` or `,` behind its right side); the target is the identifier in front of the nearest
`=` / `+=` ... whose right side ends there.  Fixed only when the target is a plain name (not `a[i]`, `ob->x`) whose declaration is found in the enclosing
function (its parameters and locals) or at file level, as a statement without parentheses in it (`int a = foo(1), value;` is listed).  Binary-safe;
idempotent.  `Bad assignment ( X vs Y )` rows only: `Bad type for argument`, `Type of returned value` (scripts/lpc_fix_void_return.py) and `Type mismatch` stay.

Without --apply the plan is printed (`FIX<TAB>slug<TAB>/path<TAB>names` and `LIST<TAB>slug<TAB>/path:line<TAB>why`).  Rows come from DIAGNOSTICS.tsv (default
$LPC_SCRATCH/lpcw-SLUG/diagnostics.tsv or the newest scan); `--all` takes every lib's newest list.  Load-check afterwards (scripts/lpc_listcheck.sh)."""
import glob
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from lpc_fix_void_return import code_mask, depth_map, enclosing_function  # noqa: E402

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SCRATCH = os.environ.get("LPC_SCRATCH") or os.path.expanduser("~/.cache/lpc-scratch")
ROW = re.compile(r"Bad assignment \( .+? vs .+? \)")
TYPES = r"(?:int|string|object|mapping|float|function|status|buffer)"
ASSIGN = re.compile(rb"(?<![=!<>])(?:\+|-|\*|/|%|\||&|\^|<<|>>)?=(?!=)")


def newest_diag(slug):
    best = None
    for pat in (f"{SCRATCH}/lpcw-{slug}/diagnostics.tsv", f"{SCRATCH}/lpcw-{slug}-round/diagnostics.tsv", f"{SCRATCH}/tkfix/diag/{slug}.tsv", f"{SCRATCH}/fresh/out*/diag-{slug}.tsv"):
        for p in glob.glob(pat):
            if best is None or os.path.getmtime(p) > os.path.getmtime(best):
                best = p
    return best


def target(b, mask, pos, line_start):
    """(name, name_offset) of the plain identifier assigned by the nearest assignment on the line whose right side ends at pos"""
    seg_start = line_start
    cands = [m for m in ASSIGN.finditer(b, seg_start, pos) if mask[m.start()]]
    for m in reversed(cands):
        rhs = b[m.end():pos]
        depth = 0
        ok = True
        for i, ch in enumerate(rhs):
            if not mask[m.end() + i]:
                continue
            if ch in b"([{":
                depth += 1
            elif ch in b")]}":
                depth -= 1
                if depth < 0:
                    ok = False
                    break
            elif ch in b",;" and depth == 0:
                ok = False
                break
        if not ok or depth:
            continue
        k = m.start() - 1
        while k >= seg_start and b[k:k + 1] in b" \t":
            k -= 1
        e = k + 1
        while k >= seg_start and (b[k:k + 1].isalnum() or b[k:k + 1] == b"_"):
            k -= 1
        name = b[k + 1:e]
        if not name or name[0:1].isdigit():
            return None, "target is not a plain name"
        j = k
        while j >= seg_start and b[j:j + 1] in b" \t":
            j -= 1
        if b[max(j - 1, 0):j + 1] == b"->" or b[j:j + 1] in b".]":
            return None, "target is a member or element"
        return name.decode(), k + 1
    return None, "no assignment ends there"


def decl_for(b, mask, dep, name, off):
    """the declaration statement of `name` that governs the assignment at off: (type_start, type_end, star_offset or None) or None"""
    n = re.escape(name.encode())
    ef = enclosing_function(b, mask, dep, off)
    spans = []
    if ef:
        spans.append((ef[0], off, False))            # header (parameters) and the body up to the assignment
    spans.append((0, off, True))                     # file level, before the assignment
    typew = re.compile(rb"\b(?:" + TYPES.encode() + rb"|mixed)\b")
    for lo, hi, filelevel in spans:
        best = None
        for mo in re.finditer(rb"(?<![\w>.])" + n + rb"\b", b[lo:hi]):
            at = lo + mo.start()
            if not mask[at]:
                continue
            base = max(lo, at - 800)
            prefix = b[base:at]
            tws = [t for t in typew.finditer(prefix) if mask[base + t.start()]]
            if not tws:
                continue
            tw = tws[-1]
            mid = prefix[tw.end():]
            if re.search(rb"[^\w\s,*=\"\-.]", mid):
                continue                             # parentheses, braces or `;` in between: not one declaration
            stripped = mid.rstrip()
            if stripped and not stripped.endswith((b",", b"*")):
                continue                             # the name is not at the start of a declarator
            if filelevel and dep[base + tw.start()] != 0:
                continue                             # file level: braces depth 0 only
            star = base + tw.end() + stripped.rfind(b"*") if stripped.endswith(b"*") else None
            best = (base + tw.start(), base + tw.end(), star)
        if best is not None:
            return best
    return None


def fix_file(path, rows):
    b = open(path, "rb").read()
    mask = code_mask(b)
    dep = depth_map(b, mask)
    starts = [0]
    for i, ch in enumerate(b):
        if ch == 10:
            starts.append(i + 1)
    edits = {}
    names = []
    listed = []
    for ln, col in rows:
        if ln < 1 or ln > len(starts):
            listed.append((ln, "line out of range"))
            continue
        pos = starts[ln - 1] + col - 1
        # the position is the end of the right side; a statement may begin on an earlier line, but a plain assignment sits on one
        name, why = target(b, mask, min(pos, len(b)), starts[ln - 1])
        if name is None:
            listed.append((ln, why))
            continue
        d = decl_for(b, mask, dep, name, min(pos, len(b) - 1))
        if not d:
            listed.append((ln, f"declaration of {name} not found"))
            continue
        t0, t1, star = d
        edits[(t0, t1)] = b"mixed"
        if star is not None:
            edits[(star, star + 1)] = b""              # `string *x` -> `mixed x`
        names.append(name)
    if not edits:
        return None, [], listed
    out = bytearray(b)
    for (s, e), rep in sorted(edits.items(), reverse=True):
        out[s:e] = rep
    return bytes(out), sorted(set(names)), listed


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
            by.setdefault(f[0], []).append((int(f[1]), int(f[2])))
        work = f"{REPO}/libs/{slug}/work"
        for rel, rows in sorted(by.items()):
            p = work + rel
            if not os.path.isfile(p):
                continue
            new, names, listed = fix_file(p, rows)
            for ln, why in listed:
                print(f"LIST\t{slug}\t{rel}:{ln}\t{why}")
                lst += 1
            if new is not None:
                print(f"FIX\t{slug}\t{rel}\t{','.join(names)}")
                total += len(names)
                if apply_:
                    with open(p, "wb") as fh:
                        fh.write(new)
    print(f"{total} variable(s) {'retyped' if apply_ else 'retypable'}, {lst} listed", file=sys.stderr)


if __name__ == "__main__":
    main()
