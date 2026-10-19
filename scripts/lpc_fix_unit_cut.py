#!/usr/bin/env python3
"""scripts/lpc_fix_unit_cut.py SLUG... [--apply]

A `unit + short()` key cut with `[2..]` (KB 07 section 8.1).  `inventory`, the brief-mode item list of `feature/move` and some `look`
copies count items in a mapping keyed by `query("unit") + short()` and print the key for a single item without its unit:

    my[str[i]] == 1 ? str[i][2..] : str[i]

The unit is one hanzi, which was two bytes in the GBK original, so `[2..]` removed exactly the unit.  After the UTF-8 conversion
a hanzi is one index: the same cut also removes the first character of the name (「把长剑」 prints as 「剑」), or the ESC of a
coloured name.  `[1..]` is the faithful translation.  The shape is matched on code only (comments and strings are masked), the
file must build the keys with `query("unit")`, multi-line ternaries are handled.  Wizard and backup dirs, gitlink libs and the
generated tree of longyunmeng_binary (fixed in its patch) are skipped.  Binary-safe.  Without --apply the plan is printed."""
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from lpc_fix_void_return import code_mask  # noqa: E402

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SKIP = re.compile(r"/(u|w|wiz|wizard|wizards|open|players|backup|backups|old|bak|log|data|doc|example|examples)/|[-_.](bak|old)/")
CUT = re.compile(rb"(\b\w+\[\s*(\w+)\s*\[\s*(\w+)\s*\]\s*\]\s*==\s*1\s*\?\s*)\2\s*\[\s*\3\s*\]\s*\[\s*2\s*\.\.\s*\]"
                 rb"(\s*:\s*\2\s*\[\s*\3\s*\])")


def fix(b):
    if b'"unit"' not in b:
        return b, 0
    mask = code_mask(b)
    out, last, n = [], 0, 0
    for m in CUT.finditer(b):
        if not mask[m.start()] or not mask[m.end() - 1]:
            continue
        cut = b[m.end(1):m.start(4)]                      # `str[i][2..]`
        out.append(b[last:m.end(1)])
        out.append(re.sub(rb"\[\s*2\s*\.\.\s*\]", b"[1..]", cut))
        last = m.start(4)
        n += 1
    out.append(b[last:])
    return b"".join(out), n


def main():
    args = sys.argv[1:]
    apply = "--apply" in args
    tot = files = 0
    for slug in [a for a in args if not a.startswith("--")]:
        work = f"{REPO}/libs/{slug}/work"
        if slug == "longyunmeng_binary" or not os.path.isdir(work) or os.path.exists(f"{work}/.git"):
            continue
        n_lib = 0
        for dp, dn, fn in os.walk(work):
            dn.sort()
            if SKIP.search(dp[len(work):] + "/"):
                continue
            for f in sorted(fn):
                if not f.endswith((".lpc", ".h")):
                    continue
                p = os.path.join(dp, f)
                b = open(p, "rb").read()
                if b"[2" not in b:
                    continue
                out, n = fix(b)
                if n:
                    n_lib += n
                    files += 1
                    print(f"FIX   {slug} {p[len(work):]}  {n}")
                    if apply:
                        open(p, "wb").write(out)
        tot += n_lib
    print(f"{tot} cut(s) in {files} file(s)" + ("" if apply else " (plan only; --apply writes)"))


if __name__ == "__main__":
    main()
