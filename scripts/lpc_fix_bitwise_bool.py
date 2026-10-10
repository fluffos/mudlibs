#!/usr/bin/env python3
"""scripts/lpc_fix_bitwise_bool.py [--apply] SLUG [DIAGNOSTICS.tsv]

`bitwise operation on boolean values` (`if (a != "x" & a != "y")`): the result happens to equal `&&`/`||` when both
sides are comparisons, but `&` does not short-circuit and binds looser than the author meant in any longer chain
(holymission's `i < 0 & i > N` size check could never fire).  For each such warning in the lpc_warnings.py
diagnostics list (default /tmp/lpcw-SLUG/diagnostics.tsv; the column points at the end of the expression), the
reported line is fixed when it holds exactly one lone `&` or `|` outside strings and comments; anything else is
listed.  Binary-safe.  Without --apply it prints the plan."""
import os
import re
import sys

args = [a for a in sys.argv[1:] if not a.startswith("--")]
apply_ = "--apply" in sys.argv
slug = args[0]
tsv = args[1] if len(args) > 1 else f"/tmp/lpcw-{slug}/diagnostics.tsv"
work = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "libs", slug, "work")
LONE = re.compile(rb"(?<![&|])([&|])(?![&|=])")


def code_only(line):
    """blank string literals, char literals and // comments so their `&`/`|` do not count"""
    out = re.sub(rb'"(?:\\.|[^"\\])*"', lambda m: b'"' + b" " * (len(m.group(0)) - 2) + b'"', line)
    out = re.sub(rb"'(?:\\.|[^'\\])'", lambda m: b" " * len(m.group(0)), out)
    i = out.find(b"//")
    return out if i < 0 else out[:i] + b" " * (len(out) - i)


todo = {}
for row in open(tsv, encoding="utf-8", errors="replace"):
    f = row.rstrip("\n").split("\t")
    if len(f) >= 5 and f[4].startswith("bitwise operation on boolean values"):
        todo.setdefault(f[0], set()).add(int(f[1]))
fixed = listed = 0
for path, lines in sorted(todo.items()):
    p = work + path
    data = open(p, "rb").read()
    L = data.split(b"\n")
    changed = False
    for ln in sorted(lines):
        line = L[ln - 1]
        hits = list(LONE.finditer(code_only(line)))
        if len(hits) != 1:
            listed += 1
            print(f"READ {path}:{ln}: {line.strip()[:100].decode('utf-8', 'replace')}")
            continue
        i = hits[0].start()
        L[ln - 1] = line[:i] + line[i:i + 1] * 2 + line[i + 1:]
        changed = True
        fixed += 1
        print(f"FIX  {path}:{ln}: {L[ln - 1].strip()[:100].decode('utf-8', 'replace')}")
    if changed and apply_:
        open(p, "wb").write(b"\n".join(L))
print(f"{fixed} fixed, {listed} to read" + ("" if apply_ else " (dry run)"))
