#!/usr/bin/env python3
"""scripts/lpc_fix_prototype_types.py [--apply] SLUG      (reads the scan scripts/lpc_warnings.py SLUG left behind)

`Previous function prototype for check_out does not match current function in return type ( void vs int )` (KB 04
section 6.10): the file declares `void check_out(...);` near the top and defines `int check_out(...) { ... }`.  The
definition is the code that runs (it returns what it returns), so the prototype is brought to the definition's type:
the first type of the pair is the prototype's, the second the definition's.  This finds the prototype in the masked
code (comments, strings, here-documents and `#if 0` blanked), the last one before the reported definition line, and
replaces its return-type word(s).  Modifiers (`varargs`, `nomask`, `protected`, `nosave` ...) stay.  Without --apply it only
prints the plan; a prototype it cannot find, or a type that is not a plain `[modifiers] type [*] name(...);`, is listed
and left.  Reads /tmp/lpcw-SLUG/diagnostics.tsv (path, line, column, severity, message).  Re-run the scan afterwards:
a caller that used the old type shows up there."""
import os
import re
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from lpc_src import mask  # noqa: E402

args = sys.argv[1:]
apply_ = "--apply" in args
args = [a for a in args if a != "--apply"]
if len(args) != 1:
    sys.exit(__doc__)
slug = args[0]
work = f"{REPO}/libs/{slug}/work"
tsv = f"/tmp/lpcw-{slug}/diagnostics.tsv"
if not os.path.isfile(tsv):
    sys.exit(f"{tsv} missing: run scripts/lpc_warnings.py {slug} first")

MSG = re.compile(r"Previous function prototype for (\w+) does not match current function in return type \( (.+?) vs (.+?) \)")
todo = {}
for line in open(tsv, errors="replace"):
    f = line.rstrip("\n").split("\t")
    if len(f) < 5 or f[3] != "warning":
        continue
    m = MSG.match(f[4])
    if m:
        todo.setdefault(f[0], []).append((int(f[1]), m.group(1), m.group(2).strip(), m.group(3).strip()))


def type_regex(t):
    """regex for a return type spelled any way: `mixed *` -> mixed[ \\t]*\\*"""
    base = t.replace("*", "").strip()
    stars = t.count("*")
    return r"\b" + re.escape(base) + r"\b" + (r"[ \t]*\*[ \t]*" * stars if stars else r"(?![ \t]*\*)")


def balanced_end(m, i):
    """offset just after the `)` matching the `(` at masked[i]"""
    depth = 0
    for k in range(i, len(m)):
        if m[k] == "(":
            depth += 1
        elif m[k] == ")":
            depth -= 1
            if depth == 0:
                return k + 1
    return -1


planned = skipped = 0
for path in sorted(todo):
    full = work + path
    try:
        raw = open(full, "rb").read()
    except OSError:
        continue
    text = raw.decode("latin-1")
    masked = mask(text)
    starts = [0]
    for i, ch in enumerate(text):
        if ch == "\n":
            starts.append(i + 1)
    edits = []
    for ln, fname, ptype, ctype in todo[path]:
        limit = starts[ln - 1] if 0 < ln <= len(starts) else len(text)
        pat = re.compile(r"(?m)^([ \t]*(?:(?:varargs|nomask|private|protected|public|static|nosave)[ \t]+)*)(%s)([ \t]*)%s[ \t]*\(" % (type_regex(ptype), re.escape(fname)))
        best = None
        for m in pat.finditer(masked, 0, limit):
            op = m.end() - 1
            end = balanced_end(masked, op)
            if end > 0 and re.match(r"\s*;", masked[end:end + 40] or ""):
                best = m
        if not best:
            print(f"  skip {path}:{ln}: no prototype `{ptype} {fname}(...);` found")
            skipped += 1
            continue
        edits.append((best.start(2), best.end(2), ctype, fname, ln, ptype))
    done = set()
    for a, b, new, fname, ln, ptype in sorted(edits, reverse=True):
        if (a, b) in done:
            continue
        done.add((a, b))
        text = text[:a] + new + text[b:]
        planned += 1
        print(f"  {path}:{ln}: prototype of {fname}: {ptype} -> {new}")
    if apply_ and edits:
        open(full, "wb").write(text.encode("latin-1"))
print(f"{planned} prototype(s) {'fixed' if apply_ else 'to fix'}, {skipped} skipped")
