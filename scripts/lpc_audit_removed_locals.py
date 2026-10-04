#!/usr/bin/env python3
"""scripts/lpc_audit_removed_locals.py BASE [PATHSPEC ...]      (BASE .. working tree, default 'libs/*/work/*')

Audit for the one edit the scan cannot check: a warning sweep that DELETED a local declaration.  For every removed
declaration line the script looks at the function it came from and prints the name when the function
still reads it and no declaration of it is left there.  Two shapes turn up:

* the name is read inside an inactive `#if`/`#ifdef` branch (`#ifdef USE_RAMDISK`, `#ifdef 0`, `#ifdef LIMB_SHIELDS`):
  the driver called the local unused, a build with the option on would not compile.  Declare it again inside the
  branch (KB 04 section 6.10);
* the file did not compile, so the compiler's "Unused local variable" came from a scope an earlier error had
  confused, and the code reads the variable (Discworld `office_code/lists.lpc`).  Put the declaration back.

Reads are looked for in code only: comments, strings, `#if 0` blocks and `<<` heredocs are blanked, `x->name`,
`x.name` and `class name` are not reads of a local.  Remaining hits are candidates: look at each one.
Example: scripts/lpc_audit_removed_locals.py 6165f9c678d~1   (every vendored lib since the 2026-10-03 warning sweep)."""
import difflib
import os
import re
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from lpc_src import mask  # noqa: E402

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
if len(sys.argv) < 2 or sys.argv[1].startswith("-"):
    sys.exit(__doc__)
base = sys.argv[1]
spec = sys.argv[2:] or ["libs/*/work/*"]
names = subprocess.run(["git", "-C", REPO, "diff", "--name-only", base, "--"] + spec,
                       capture_output=True, text=True).stdout.split("\n")
TY = r"(?:int|string|object|mixed|mapping|float|function|buffer|status|class\s+\w+)"
DECL = re.compile(r"^\s*(?:nosave\s+)?" + TY + r"\b[^;]*;\s*$")
HEREDOC = re.compile(r"@@?(\w+)[ \t]*\r?\n.*?\r?\n\1\b", re.S)


def blank_heredocs(src):
    return HEREDOC.sub(lambda m: re.sub(r"[^\n]", " ", m.group(0)), src)


def decl_names(line):
    body = re.sub(r"^\s*(?:nosave\s+)?" + TY + r"\b", "", line)
    out, depth, cur = [], 0, ""
    for ch in body:
        if ch in "([{":
            depth += 1
        elif ch in ")]}":
            depth -= 1
        if ch in ",;" and depth == 0:
            m = re.match(r"\s*\**\s*([A-Za-z_]\w*)", cur)
            if m:
                out.append(m.group(1))
            cur = ""
        else:
            cur += ch
    return out


def spans(masked):
    """[(start_line, end_line)] (0-based, inclusive) of every top-level {...} block"""
    res, depth, start, line = [], 0, None, 0
    for ch in masked:
        if ch == "\n":
            line += 1
        elif ch == "{":
            if depth == 0:
                start = line
            depth += 1
        elif ch == "}":
            depth = max(depth - 1, 0)
            if depth == 0 and start is not None:
                res.append((start, line))
                start = None
    return res


flag = checked = 0
for n in names:
    if not n or not re.search(r"\.(lpc|h|c)$", n):
        continue
    old = subprocess.run(["git", "-C", REPO, "show", f"{base}:{n}"], capture_output=True).stdout
    try:
        new = open(f"{REPO}/{n}", "rb").read()
    except OSError:
        continue
    if not old or old == new:
        continue
    o = old.decode("latin-1").replace("\r\n", "\n").split("\n")
    nw = new.decode("latin-1").replace("\r\n", "\n")
    masked = mask(blank_heredocs(nw)).split("\n")
    sp = spans("\n".join(masked))
    sm = difflib.SequenceMatcher(None, o, nw.split("\n"), autojunk=False)
    seen = set()
    for tag, i1, i2, j1, j2 in sm.get_opcodes():
        if tag not in ("delete", "replace"):
            continue
        for ln in o[i1:i2]:
            if not DECL.match(ln):
                continue
            at = max(j1 - 1, 0)
            blk = next(((a, b) for a, b in sp if a <= at <= b), None) or next(((a, b) for a, b in sp if a <= j1 <= b), None)
            if blk is None:
                continue
            text = "\n".join(masked[blk[0]:blk[1] + 1])
            text = text[text.find("{"):]
            reads = re.sub(r"->\s+", "->", re.sub(r"\bclass\s+\w+", "class", text))
            for nm in decl_names(ln):
                checked += 1
                if (nm, blk) in seen:
                    continue
                if re.search(r"(?<![\w$>.])" + re.escape(nm) + r"(?!\w)", reads) and \
                        not re.search(r"\b" + TY + r"\b[^;()]*[\s*,]" + re.escape(nm) + r"\b", text):
                    seen.add((nm, blk))
                    print(f"{n}:{blk[0] + 1}: removed `{ln.strip()}` but `{nm}` is still read in the function")
                    flag += 1
print(f"checked {checked} removed declarator(s); {flag} to look at")
sys.exit(1 if flag else 0)
