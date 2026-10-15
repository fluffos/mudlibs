#!/usr/bin/env python3
"""scripts/lpc_fix_family_guard.py SLUG... [--apply]

`mapping fam = me->query("family");` (or `fam = (mapping)me->query("family");` to a local `mapping fam`, or the
nitan form `query("family", me)`) followed straight away by `fam["family_name"]` (KB 05 section 7.30's family
variant).  A player without a sect (a newcomer, or one who left it: 叛师 deletes "family" but keeps the skills) has no
"family" mapping, so the index raises `Value being indexed is zero` instead of the notify_fail() the check was written
for: practising or learning the skill, asking the master, entering the guarded room all stop with an error.

The fixer adds `if (!mapp(fam)) fam = ([ ]);` on the declaration's own line (line numbers stay) when the variable's
first use after it, in the same function, is an index.  A first use that tests it (`!fam`, `fam &&`, `mapp(fam)`) or
assigns it is left alone, and so is an NPC's own family (`query("family")` on itself, or on `me = this_object()`).  An empty mapping makes every comparison read as "not in that family", which is what the
author's test means.  Code only (not strings or comments).  Binary-safe.  Without --apply the plan is printed."""
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from lpc_fix_void_return import code_mask  # noqa: E402

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SKIP = re.compile(r"/(u|w|open|players|backup|old|bak|log|data|doc)/")
DECL = re.compile(rb'(?:(mapping)\s+)?([A-Za-z_]\w*)\s*=\s*(?:\(\s*mapping\s*\)\s*)?'
                  rb'(?:(?:([\w\[\]]+)\s*->\s*)?query\s*\(\s*"family"\s*\)|query\s*\(\s*"family"\s*,\s*([\w\[\]]+)\s*\))\s*;')


def fix(b):
    decls = list(DECL.finditer(b))
    if not decls:
        return b, 0
    mask = code_mask(b)
    edits = []
    for m in decls:
        if not mask[m.start()]:
            continue
        name, recv = m.group(2), m.group(3) or m.group(4)
        start = b.rfind(b"\n}", 0, m.start())
        if not m.group(1):
            # a plain assignment: only to a local declared `mapping` earlier in the same function
            if m.start() > 0 and b[m.start() - 1:m.start()] not in b" \t\n;{":
                continue
            if not re.search(rb"\bmapping\b[^;{}]*\b" + re.escape(name) + rb"\b", b[max(start, 0):m.start()]):
                continue
        if not recv or recv == b"this_object" or re.search(
                rb"\b" + re.escape(recv) + rb"\s*=\s*this_object\s*\(\s*\)", b[max(start, 0):m.start()]):
            continue   # the NPC's own family, set by create_family()
        # just recruited: recruit_apprentice() set the family a few lines up
        if recv and re.search(rb"recruit_apprentice\s*\(\s*" + re.escape(recv) + rb"\s*\)", b[max(m.start() - 400, 0):m.start()]):
            continue
        # the function ends at the next `}` in column 0
        end = b.find(b"\n}", m.end())
        end = len(b) if end < 0 else end
        use = None
        for u in re.finditer(rb"\b" + re.escape(name) + rb"\b", b[m.end():end]):
            if mask[m.end() + u.start()]:
                use = u
                break
        if not use:
            continue
        after = b[m.end() + use.end():m.end() + use.end() + 20]
        if not re.match(rb"\s*\[", after):
            continue
        edits.append((m.end(), b" if (!mapp(" + name + b")) " + name + b" = ([ ]);"))
    out = b
    for pos, ins in sorted(edits, reverse=True):
        out = out[:pos] + ins + out[pos:]
    return out, len(edits)


def main():
    args = sys.argv[1:]
    apply = "--apply" in args
    tot = 0
    for slug in [a for a in args if not a.startswith("--")]:
        work = f"{REPO}/libs/{slug}/work"
        if os.path.exists(f"{work}/.git"):
            continue
        for dp, dn, fn in os.walk(work):
            if SKIP.search(dp[len(work):] + "/"):
                continue
            for f in fn:
                if not f.endswith(".lpc"):
                    continue
                p = os.path.join(dp, f)
                b = open(p, "rb").read()
                if b'"family"' not in b:
                    continue
                out, n = fix(b)
                if n:
                    tot += n
                    print(f"FIX   {slug} {p[len(work):]}  {n}")
                    if apply:
                        open(p, "wb").write(out)
    print(f"{tot} declaration(s)" + ("" if apply else " (plan only; --apply writes)"))


if __name__ == "__main__":
    main()
