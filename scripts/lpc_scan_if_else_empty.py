#!/usr/bin/env python3
"""scripts/lpc_scan_if_else_empty.py [--libs SLUG ...] [--with-old]

Detector, no edits (KB 04 6.27): an `if (cond)` (or `else if (cond)`, `while`, `for`) line with nothing after the closing paren, directly followed by an `else` line.
The statement between them was an empty one (`;` on a line of its own, as in the intact copy `if (...)\\n      ;\\n    else\\n      x();`) and was lost, so the file is
`syntax error, unexpected L_ELSE` and the object never loads (hc `cmds/usr/quit1.lpc`; the same shape in wizard scratch files: `u/lonely/obsave.lpc`,
`u/rocky/enforce.lpc`, pd `wizards/.../j7.lpc`).  A one-line `if (x) y();  // (25%)` chain is not listed: the closing paren is found by balancing the parentheses
(strings skipped), and only a comment may follow it.  One line per site: `slug path line kind`, kind `wiz` for a wizard home (`u/`, `wizards/`, `wiz/`, `open/`)
and `code` for the rest; the summary goes to stderr.  The repair is by hand (put the `;` line back; compare with the sibling copy of the file).  Gitlink libs are skipped;
`old` / `bak` / `backup` / `attic` / `raw` directories too unless --with-old."""
import argparse
import os
import re
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
GITLINKS = {"nt7", "xkx100utf8", "fy2005", "nightmare3", "residuum", "sanguozhi", "oxidus"}
SKIPDIR = re.compile(r"(^|/)(old|bak|backup|attic|raw)(/|$)", re.I)
WIZ = re.compile(r"^(u|wizards|wiz|open)/")
IFHEAD = re.compile(rb"^\s*(?:\}\s*)?(?:else\s+)?(?:if|while|for|foreach)\s*\(")
ELSE = re.compile(rb"^\s*else\b")


def bare_if(line):
    """True when the line is `if (...)` whose closing paren ends it (a trailing comment allowed)"""
    m = IFHEAD.match(line)
    if not m:
        return False
    i = m.end() - 1
    depth = 0
    instr = None
    while i < len(line):
        c = line[i:i + 1]
        if instr:
            if c == b"\\":
                i += 1
            elif c == instr:
                instr = None
        elif c in (b'"', b"'"):
            instr = c
        elif c == b"(":
            depth += 1
        elif c == b")":
            depth -= 1
            if depth == 0:
                rest = line[i + 1:].strip()
                return rest == b"" or rest.startswith(b"//") or (rest.startswith(b"/*") and rest.endswith(b"*/"))
        i += 1
    return False


def main():
    sys.stdout.reconfigure(errors="surrogateescape")
    ap = argparse.ArgumentParser()
    ap.add_argument("--libs", nargs="*", default=[])
    ap.add_argument("--with-old", action="store_true")
    a = ap.parse_args()
    libs = a.libs or sorted(d for d in os.listdir(f"{REPO}/libs") if os.path.isdir(f"{REPO}/libs/{d}/work"))
    n = code = 0
    for slug in libs:
        if slug in GITLINKS:
            continue
        work = f"{REPO}/libs/{slug}/work"
        for root, dirs, fs in os.walk(work):
            rel = os.path.relpath(root, work)
            if not a.with_old and rel != "." and SKIPDIR.search(rel + "/"):
                dirs[:] = []
                continue
            for f in fs:
                if not f.endswith((".lpc", ".c", ".h")):
                    continue
                p = os.path.join(root, f)
                try:
                    b = open(p, "rb").read()
                except OSError:
                    continue
                if b"else" not in b:
                    continue
                prev = None
                for i, ln in enumerate(b.split(b"\n")):
                    if not ln.strip():
                        continue
                    if prev is not None and ELSE.match(ln) and bare_if(prev[1].rstrip(b"\r")):
                        r = os.path.relpath(p, work)
                        kind = "wiz" if WIZ.match(r) else "code"
                        code += kind == "code"
                        print(slug, r, prev[0] + 1, kind)
                        n += 1
                    prev = (i, ln)
    print(f"{n} site(s), {code} outside wizard homes", file=sys.stderr)


if __name__ == "__main__":
    main()
