#!/usr/bin/env python3
"""scripts/lpc_fix_forward_decl.py [--apply] SLUG      (reads the scan scripts/lpc_warnings.py SLUG left behind)

`Called function 'f' not compiled with type testing.` (KB 04 section 6.10): under `#pragma strict_types` a function that a
file calls *before* the textual place where it defines it has no declaration at the call, so the driver makes up an
untyped one and complains when the real definition arrives (and, when the callee is an efun name like `tell_room`, binds the
call to the efun, section 6.5).  The cure is a prototype in front of the first function of the file.  For every function the
scan names this copies the header of its definition (`varargs void single_busy(object target)`, modifiers, type, name and
parameters; `nosave`, `private`... are kept as written) and inserts `<header>;` lines in front of the first function
definition of the file, after the `inherit`/`#include` lines and the prototypes that are already there.  A function that
is defined more than once, or whose header it cannot read, is listed and left.  Without --apply it prints the plan.  Line
endings are kept."""
import collections
import os
import re
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from lpc_src import MODS, TYPES, mask, top_level_defs  # noqa: E402

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

want = collections.defaultdict(set)
for line in open(tsv, errors="replace"):
    f = line.rstrip("\n").split("\t")
    if len(f) >= 5 and f[3] == "warning":
        m = re.match(r"Called function '([A-Za-z_]\w*)' not compiled with type testing", f[4])
        if m:
            want[f[0]].add(m.group(1))

TOKEN = re.compile(r"[A-Za-z_]\w*|\*")
ALLOWED = MODS | TYPES | {"*", "class"}


def decl_start(m, name_start):
    """index of the first modifier / type token of the declaration whose name starts at name_start"""
    i = name_start
    while True:
        j = i
        while j > 0 and m[j - 1] in " \t\r\n":
            j -= 1
        k = j
        while k > 0 and (m[k - 1].isalnum() or m[k - 1] in "_*"):
            k -= 1
        tok = m[k:j]
        if tok and (tok in ALLOWED or (k > 0 and m[:k].rstrip().endswith("class"))):
            i = k
            continue
        return i


def first_function_start(m):
    """index of the declaration start of the first top-level function definition with a body"""
    depth, par, n = 0, 0, len(m)
    for i in range(n):
        c = m[i]
        if c == "(":
            par += 1
        elif c == ")":
            par -= 1
        elif c == "{" and par == 0:
            if depth == 0:
                j = i
                while j > 0 and m[j - 1] in " \t\r\n":
                    j -= 1
                if j and m[j - 1] == ")":
                    # back to the matching '(' and the name before it
                    d, k = 0, j - 1
                    while k >= 0:
                        d += (m[k] == ")") - (m[k] == "(")
                        if d == 0:
                            break
                        k -= 1
                    e = k
                    while e > 0 and m[e - 1] in " \t\r\n":
                        e -= 1
                    s = e
                    while s > 0 and (m[s - 1].isalnum() or m[s - 1] == "_"):
                        s -= 1
                    return decl_start(m, s)
            depth += 1
        elif c == "}":
            depth -= 1
    return None


total = left = 0
for path in sorted(want):
    full = work + path
    try:
        raw = open(full, "rb").read()
    except OSError:
        continue
    text = raw.decode("latin-1")
    eol = "\r\n" if "\r\n" in text else "\n"
    m = mask(text)
    protos = []
    for fn in sorted(want[path]):
        defs = top_level_defs(text, fn)
        if len(defs) != 1:
            print(f"  {path}: {fn}: {len(defs)} definitions, left")
            left += 1
            continue
        ns, op, cp = defs[0]
        st = decl_start(m, ns)
        header = re.sub(r"\s+", " ", text[st:cp + 1]).strip()
        if re.search(r"\b" + re.escape(fn) + r"\s*\(", header) is None:
            print(f"  {path}: {fn}: cannot read the header, left")
            left += 1
            continue
        # skip when a prototype with this name is already there
        if re.search(r"(?m)^[ \t]*(?:" + "|".join(sorted(MODS | TYPES)) + r")\b[^;{}()]*\b" + re.escape(fn) + r"\s*\([^;{}]*\)\s*;", m):
            print(f"  {path}: {fn}: a prototype exists already, left")
            left += 1
            continue
        protos.append(header + ";")
    if not protos:
        continue
    at = first_function_start(m)
    if at is None:
        print(f"  {path}: no function definition to put the prototypes in front of, left")
        left += len(protos)
        continue
    ls = text.rfind("\n", 0, at) + 1
    new = text[:ls] + eol.join(protos) + eol + text[ls:]
    total += len(protos)
    print(f"  {path}: {len(protos)} prototype(s): " + "; ".join(p[:60] for p in protos[:3]))
    if apply_:
        open(full, "wb").write(new.encode("latin-1"))
print(f"{total} prototype(s) {'written' if apply_ else 'planned'}; {left} left")
