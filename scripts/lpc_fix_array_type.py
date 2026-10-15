#!/usr/bin/env python3
"""scripts/lpc_fix_array_type.py SLUG [--apply]

`array` used as a type on its own (`array names;`, `array list = keys(m);`, `array f()`, `void g(array a)`): MudOS with
ARRAY_RESERVED_WORD read it as "array of mixed"; this driver has that option off, so `array` is an identifier and the
file stops with `Illegal lvalue`, `Illegal LHS` or a syntax error (KB 04 section 6.3).  Rewritten to `mixed *`:

    array a, b = ({});      ->  mixed *a, *b = ({});     (in MudOS the word belonged to the type: every declarator)
    array f(int x) {        ->  mixed *f(int x) {
    void g(array a, int n)  ->  void g(mixed *a, int n)

Only code is touched (not strings or comments), only where `array` stands in type position: at the start of a
statement after optional modifiers and followed by a name and `=`, `;`, `,` or `(`, or as a parameter type.  A variable
that is itself called `array` (`object *array;`, `array[i]`) is left alone.  `TYPE array NAME` is a different shape
(see KB 04 section 6.3).  Files under tests/ are skipped.  Binary-safe.  Without --apply only the plan is printed."""
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from lpc_fix_void_return import code_mask  # noqa: E402  (double-quoted strings may span lines)

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
MODS = rb"(?:(?:static|nosave|private|protected|public|nomask|varargs|register)\s+)*"
# statement start (after ; { } or line start), modifiers, `array`, optional *, name, then = ; , (
DECL = re.compile(rb"(?:(?<=[;{}])|(?m:^))([ \t]*" + MODS + rb")array(\s+)(\*?\s*)([A-Za-z_]\w*)(\s*)(?=[=;,(])")
PARAM = re.compile(rb"([(,]\s*)array(\s+)(\*?\s*)([A-Za-z_]\w*)(\s*)(?=[,)])")


def split_declarators(s, mask, start, end):
    """Offsets (just after each top-level comma) of the following declarators in s[start:end]."""
    out, depth = [], 0
    for i in range(start, end):
        if not mask[i]:
            continue
        c = s[i]
        if c in b"([{":
            depth += 1
        elif c in b")]}":
            depth -= 1
        elif c == 0x2c and depth == 0:
            out.append(i + 1)
    return out


def fix(b):
    mask = code_mask(b)
    edits = []
    for m in DECL.finditer(b):
        a = m.start(0) + len(m.group(1))   # the `a` of `array`
        if not mask[a]:
            continue
        name_end = m.end(4)
        rest = b[m.end(5):m.end(5) + 1]
        if rest == b"(":
            # a function returning an array: just the type
            edits.append((a, m.start(4), b"mixed *"))
            continue
        # declaration: star every declarator up to the statement's `;`
        k, depth = name_end, 0
        while k < len(b):
            if mask[k]:
                c = b[k]
                if c in b"([{":
                    depth += 1
                elif c in b")]}":
                    depth -= 1
                elif c == 0x3b and depth == 0:
                    break
            k += 1
        edits.append((a, m.start(4), b"mixed *"))
        for d in split_declarators(b, mask, name_end, k):
            w = d
            while w < k and b[w] in b" \t\r\n":
                w += 1
            if b[w:w + 1] != b"*":
                edits.append((w, w, b"*"))
    for m in PARAM.finditer(b):
        a = m.start(0) + len(m.group(1))
        if mask[a]:
            edits.append((a, m.start(4), b"mixed *"))
    out = b
    for s, e, new in sorted(set(edits), reverse=True):
        out = out[:s] + new + out[e:]
    return out, len(edits)


def main():
    args = sys.argv[1:]
    apply = "--apply" in args
    slug = [a for a in args if not a.startswith("--")][0]
    work = f"{REPO}/libs/{slug}/work"
    files = n = 0
    for dp, dn, fn in os.walk(work):
        if re.search(r"/tests?(/|$)", dp[len(work):]):
            continue
        for f in fn:
            if not f.endswith((".lpc", ".h")):
                continue
            p = os.path.join(dp, f)
            b = open(p, "rb").read()
            if b"array" not in b:
                continue
            out, k = fix(b)
            if out != b:
                files += 1
                n += k
                print(f"FIX   {p[len(work):]}  {k} edit(s)")
                if apply:
                    open(p, "wb").write(out)
    print(f"{files} file(s), {n} edit(s)" + ("" if apply else " (plan only; --apply writes)"))


if __name__ == "__main__":
    main()
