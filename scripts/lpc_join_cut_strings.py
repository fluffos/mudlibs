#!/usr/bin/env python3
"""scripts/lpc_join_cut_strings.py [--apply] [--skip SLUG ...] [SLUG ...]

A message cut in half by a stray `;` (KB 04 section 6.10):

    fail = "虽然大家都同意"
      "了，可惜现在有人不在，$N";
    "的提议只好作罢。\\n";            <- a string statement on its own: never shown

The driver reports `Expression has no side effects` at the line after the orphan, but only in a file that compiles, and a
warning scan reads it as noise.  This finds a string literal with text in it standing alone as a statement right after
(blank lines allowed) a statement that ends with a string literal, walks back to where that statement starts, and when
the statement is an assignment (`x = "..."`, `x += "..."`) drops the `;` that cut it so the orphan joins it.  A chain of
several orphans joins one after another.  When the statement is a `return` (an orphan after a `return` can be dead
text, or a copy of what is returned) or anything else (an LDMud `([ k: v1; v2 ])` mapping), it is only listed.

Without --apply it prints the plan.  No SLUG: every vendored lib.  Binary-safe (CRLF kept)."""
import glob
import os
import re
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
args = sys.argv[1:]
apply_ = "--apply" in args
skip = set()
slugs = []
k = 0
while k < len(args):
    a = args[k]
    if a == "--apply":
        pass
    elif a == "--skip":
        k += 1
        skip.add(args[k])
    elif a.startswith("-"):
        sys.exit(__doc__)
    else:
        slugs.append(a)
    k += 1
os.chdir(REPO)
if not slugs:
    slugs = sorted(d for d in os.listdir("libs") if os.path.isdir(f"libs/{d}/work"))

STR = re.compile(rb'^[ \t]*"((?:[^"\\\n]|\\.)*)"[ \t]*;[ \t]*\r?$')
CONT = re.compile(rb'^[ \t]*"')            # a continuation line of a multi-line concatenation


def gitlink(slug):
    out = subprocess.run(["git", "ls-files", "-s", f"libs/{slug}/work"], capture_output=True).stdout
    return out[:6] == b"160000"


def has_text(lit):
    return re.sub(rb"\\n|\\r|\s", b"", lit) != b""


def statement_head(lines, j):
    """The first line of the statement that ends at line j (walk back over string continuation lines)."""
    while j > 0 and CONT.match(lines[j]):
        p = lines[j - 1].rstrip(b"\r").rstrip()
        if p.endswith((b";", b"{", b"}")) or not p:
            break
        j -= 1
    return lines[j]


total = joined = listed = 0
for slug in slugs:
    if slug in skip or gitlink(slug):
        continue
    for path in glob.iglob(f"libs/{slug}/work/**/*.lpc", recursive=True):
        try:
            data = open(path, "rb").read()
        except OSError:
            continue
        if b'";' not in data:
            continue
        lines = data.split(b"\n")
        changed = False
        for i, line in enumerate(lines):
            m = STR.match(line)
            if not m or not has_text(m.group(1)):
                continue
            j = i - 1
            while j >= 0 and not lines[j].strip():
                j -= 1
            if j < 0:
                continue
            prev = lines[j].rstrip(b"\r").rstrip()
            if not prev.endswith(b'";') or b"//" in prev or prev.lstrip().startswith(b"/*"):
                continue
            total += 1
            head = statement_head(lines, j).strip()
            loc = f"{path}:{i + 1}"
            if re.search(rb"\breturn\b", head) or not re.search(rb"(\+=|[^=!<>]=[^=])", head):
                listed += 1
                print(f"READ {loc}: {head[:50].decode('utf-8', 'replace')} ... {line.strip()[:40].decode('utf-8', 'replace')}")
                continue
            joined += 1
            print(f"JOIN {loc}: {line.strip()[:60].decode('utf-8', 'replace')}")
            cr = b"\r" if lines[j].endswith(b"\r") else b""
            lines[j] = prev[:-1] + cr          # drop the `;` after the closing quote
            changed = True
        if changed and apply_:
            open(path, "wb").write(b"\n".join(lines))
print(f"{total} orphan string statement(s): {joined} joined, {listed} to read" + ("" if apply_ else " (dry run)"))
