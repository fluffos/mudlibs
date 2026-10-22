#!/usr/bin/env python3
"""scripts/lpc_scan_cond_assign.py [--all] [--list] [SLUG...]

Detector, no edits: `if (x = 1)`, `if (arg = "")`, `else if (n = 0)`, `while (i = 0)`, `if (a == 1 && b = 2)`: a plain assignment of a constant (a number or a string) used
as a condition (or as one operand of `&&` / `||` in it).  The value of such an assignment is the constant, so the branch is always taken (a non-zero number or any
string, even "") or never (0), and the variable is overwritten either way.  `==` was meant.  The driver does not warn about it, so no compile scan lists it.
`if (ob = find_object(x))`, `while (sscanf(...))` and every right side that is a call, a name or an expression are the ordinary idiom and are not listed.

Prints `slug<TAB>/path<TAB>line<TAB>the term<TAB>context` per hit and a count per lib on stderr.  Wizard directories (/u/, /w/, ...), backups and examples are left out unless --all."""
import os
import re
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from lpc_fix_void_return import code_mask  # noqa: E402

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
TOP = re.compile(r"^/(u|w|wiz|wizard|wizards|open|players|realms|home)/")
ANY = re.compile(r"/(backup|backups|old|bak|log|data|example|examples|test|tests|tmp|attic|last_modify)/|[-_.](bak|old)/|\.(bak|BAK|old|orig)(\.lpc)?$")
LDMUD = {"aoh", "morgengrauen", "nirvlp312", "simud", "sticklib", "skylib", "sluggymud", "swmud", "spacemud", "wilderness", "immaster", "amylaarmini", "mundoscuro",
         "ageofelements", "acme", "scratch", "paomud", "sagenwelt", "xxsj"}      # LDMud ports: not run on this driver, so a change there cannot be checked; left out unless --all
GENERATED = {"wllz3", "longyunmeng_binary"}
COND = re.compile(rb"\b(?:if|while)\s*\(")
TERM = re.compile(rb'^\(*\s*([A-Za-z_]\w*(?:\s*\[[^\[\]=]*\])?)\s*=(?!=)\s*("(?:[^"\\\n]|\\.)*"|-?\d+(?:\.\d+)?|0x[0-9a-fA-F]+)\s*\)*$')


def tracked(slugs):
    out = subprocess.run(["git", "ls-files", "-s", "-z", "--", "libs"], cwd=REPO, capture_output=True).stdout.split(b"\0")
    gitlinks, by = set(), {}
    for ent in out:
        if not ent:
            continue
        meta, _, path = ent.partition(b"\t")
        try:
            p = path.decode("utf-8")
        except UnicodeDecodeError:
            continue
        parts = p.split("/")
        if len(parts) < 3 or parts[0] != "libs":
            continue
        slug = parts[1]
        if meta.split()[0] == b"160000":
            gitlinks.add(slug)
            continue
        if len(parts) > 3 and parts[2] == "work" and p.endswith((".lpc", ".h")):
            by.setdefault(slug, []).append(p)
    return {s: f for s, f in by.items() if s not in gitlinks and s not in GENERATED and (s not in LDMUD or slugs and s in slugs) and (not slugs or s in slugs)}


def cond_span(b, mask, open_at):
    """index just past the `)` that closes the `(` at open_at (code only), or -1"""
    depth = 0
    for i in range(open_at, len(b)):
        if not mask[i]:
            continue
        c = b[i]
        if c == 0x28:
            depth += 1
        elif c == 0x29:
            depth -= 1
            if depth == 0:
                return i + 1
    return -1


def split_terms(cond):
    """split the text of a condition on top-level && and ||: [(offset in cond, term bytes)]"""
    terms, depth, cur, i, start = [], 0, bytearray(), 0, 0
    instr = False
    while i < len(cond):
        c = cond[i]
        if instr:
            cur.append(c)
            if c == 0x5c and i + 1 < len(cond):
                cur.append(cond[i + 1])
                i += 2
                continue
            if c == 0x22:
                instr = False
            i += 1
            continue
        if c == 0x22:
            instr = True
        elif c in b"([{":
            depth += 1
        elif c in b")]}":
            depth -= 1
        if depth == 0 and cond[i:i + 2] in (b"&&", b"||"):
            terms.append((start, bytes(cur)))
            cur = bytearray()
            i += 2
            start = i
            continue
        cur.append(c)
        i += 1
    terms.append((start, bytes(cur)))
    return terms


def scan(b):
    """[(line, term text, absolute offset of the `=`, keyword)] for every constant assignment used as a condition"""
    mask = code_mask(b, heredoc=True)
    hits = []
    for m in COND.finditer(b):
        if not mask[m.start()]:
            continue
        open_at = m.end() - 1
        end = cond_span(b, mask, open_at)
        if end < 0:
            continue
        cond = b[open_at + 1:end - 1]
        for off, t in split_terms(cond):
            tm = TERM.match(t.strip())
            if tm:
                lead = len(t) - len(t.lstrip())
                # the `=` is the first bare `=` after the left-hand side
                lhs_end = lead + tm.end(1)
                eq = t.index(b"=", lhs_end)
                hits.append((b.count(b"\n", 0, m.start()) + 1, t.strip().decode("utf-8", "replace"), open_at + 1 + off + eq, m.group(0)[:-1].strip().decode()))
    return hits


def main():
    a = sys.argv[1:]
    every = "--all" in a
    slugs = {x for x in a if not x.startswith("--")}
    per = {}
    for slug, paths in sorted(tracked(slugs).items()):
        for p in paths:
            rel = "/" + p.split("/work/", 1)[1]
            if not every and (TOP.search(rel) or ANY.search(rel)):
                continue
            try:
                b = open(os.path.join(REPO, p), "rb").read()
            except OSError:
                continue
            if b"=" not in b:
                continue
            for line, term, _, kw in scan(b):
                print(f"{slug}\t{rel}\t{line}\t{kw}\t{term[:80]}")
                per[slug] = per.get(slug, 0) + 1
    print(f"{sum(per.values())} hit(s) in {len(per)} lib(s)", file=sys.stderr)


if __name__ == "__main__":
    main()
