#!/usr/bin/env python3
"""scripts/lpc_fix_heredoc_terminator.py [--apply] SLUG...      (or --all: every vendored lib)

`End of file in text block` (KB 04 section 6.10): the driver ends a here-document `@LONG ... LONG` only at a line that
STARTS with the terminator (and is not followed by an identifier character).  Two shapes of damage in the archives leave
the block open to the end of the file, so the room never loads:

  indented   `set("long", @LONG\\ntext\\n LONG\\n);`        the terminator has a space or tab in front of it
  glued      `text of the last line.LONG\\n);`             the newline before the terminator was lost (the GBK -> UTF-8
                                                         conversion swallowed it together with a half character)

This finds every `@TERM` / `@@TERM` opener (outside comments, strings, `#if 0`) that has no terminator line and repairs
it when exactly one of the lines after it is the terminator in disguise: the whitespace is stripped from an indented
one; a glued one (`...LONG`, `...LONG);`, tabs before it allowed, the next line starting with a closing token) is split
into the text line and a `LONG` line.  Without --apply it only lists what it would do.  A block whose terminator is
nowhere (lost), or that has several candidates, is listed and left: the text after it cannot be told from the room's own
code.  Libs whose work/ is a gitlink (deadsouls_fluffos, fy2005, imud, lima, nightmare3, nt7, oxidus, residuum,
sanguozhi, xkx100utf8) are refused: run on a copy of upstream and send a PR (KB 02 section 2.3).  Line endings (LF /
CRLF) are kept.  Re-run scripts/lpc_warnings.py afterwards: a repaired block can show the next error of the file."""
import os
import re
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from lpc_src import blank_if0  # noqa: E402

args = sys.argv[1:]
apply_ = "--apply" in args
args = [a for a in args if a != "--apply"]
if not args:
    sys.exit(__doc__)


def gitlink(slug):
    out = subprocess.run(["git", "-C", REPO, "ls-files", "-s", "--", f"libs/{slug}/work"], capture_output=True, text=True).stdout
    return any(l.startswith("160000") for l in out.split("\n"))


OPEN = re.compile(r"@@?([A-Za-z_][A-Za-z0-9_]*)")


def ls_of(src, i):
    return src.rfind("\n", 0, i) + 1


def closes(src, lstart, term):
    """does the line starting at lstart end the block (the lexer's own test)?"""
    if not src.startswith(term, lstart):
        return False
    e = lstart + len(term)
    return e >= len(src) or not (src[e].isalnum() or src[e] == "_")


def unterminated(src):
    """(offset of the opener, terminator) of the first here-document that runs to the end of the file, else None; a
    block's own body is skipped, the lexer does not look inside it"""
    i, n = 0, len(src)
    while i < n:
        c, two = src[i], src[i:i + 2]
        if two == "//":
            j = src.find("\n", i)
            i = n if j < 0 else j
        elif two == "/*":
            j = src.find("*/", i + 2)
            i = n if j < 0 else j + 2
        elif c == '"':
            j = i + 1
            while j < n and src[j] != '"' and src[j] != "\n":
                j += 2 if src[j] == "\\" else 1
            i = j + 1
        elif c == "'":
            m = re.match(r"'(?:\\.|[^\\'\n])'", src[i:i + 4])
            i += len(m.group(0)) if m else 1
        elif c == "@":
            m = OPEN.match(src, i)
            if not m:
                i += 1
                continue
            term = m.group(1)
            prev = src[i - 1] if i else "\n"
            nxt = src[m.end()] if m.end() < n else "\n"
            before = src[max(0, ls_of(src, i)):i].rstrip(" \t")
            if (prev.isalnum() or prev in "._@" or nxt not in " \t\r\n),;" or len(term) < 3
                    or not (before == "" or before[-1] in "(,=+:?[{;" or before.endswith("return"))):
                i = m.end()  # an e-mail address (`me@example.com`), ASCII art (`@@@L`), not a here-document
                continue
            pos = src.find("\n", m.end())
            while pos >= 0 and not closes(src, pos + 1, term):
                pos = src.find("\n", pos + 1)
            if pos < 0:
                return i, term
            j = src.find("\n", pos + 1)
            i = n if j < 0 else j
        else:
            i += 1
    return None


def repair(lines, op_line, term):
    """(line index, kind, replacement lines) or a string saying why not"""
    ind = re.compile(r"[ \t]+%s(?![A-Za-z0-9_])" % re.escape(term))
    glue = re.compile(r"^(.*?\S)[ \t]*%s((?:[ \t]*[);,]+)?[ \t]*)$" % re.escape(term))
    cand = []
    ol = lines[op_line].rstrip("\r")
    m0 = re.match(r"^(.*@@?%s)[ \t]*(\S.*?\S|\S)[ \t]*%s((?:[ \t]*[);,]+)?[ \t]*)$" % (re.escape(term), re.escape(term)), ol)
    if m0 and not ind.match(ol):
        nxt0 = next((x.strip() for x in lines[op_line + 1:op_line + 6] if x.strip()), "")
        if m0.group(3).strip() or re.match(r"[)\];,}]", nxt0):
            return (op_line, "opener-glued", [m0.group(1), m0.group(2), term + (m0.group(3).rstrip() if m0.group(3).strip() else "")])
    ci = re.compile(r"(%s)(?![A-Za-z0-9_])" % re.escape(term), re.I)
    for k in range(op_line + 1, len(lines)):
        l = lines[k].rstrip("\r")
        mci = ci.match(l)
        if mci and mci.group(1) != term and not cand:
            # `@long ... LONG`: the driver compares the terminator case-sensitively; spell the opener like the terminator
            return (op_line, "case-mismatch", [re.sub(r"(@@?)%s" % re.escape(term), lambda m: m.group(1) + mci.group(1), lines[op_line].rstrip("\r"), count=1)])
        if ind.match(l):
            cand.append((k, "indented", [l.lstrip(" \t")]))
            continue
        m = glue.match(l)
        if m and m.group(1).strip():
            tail = m.group(2).strip()
            nxt = next((x.strip() for x in lines[k + 1:k + 6] if x.strip()), "")
            if tail or re.match(r"[)\];,}]", nxt):
                cand.append((k, "glued", [m.group(1).rstrip(" \t"), term + (m.group(2).rstrip() if tail else "")]))
    if len(cand) == 1:
        return cand[0]
    return "no line holds the terminator" if not cand else f"{len(cand)} candidate lines ({cand[0][0] + 1}, {cand[1][0] + 1}...)"


slugs = sorted(s for s in os.listdir(f"{REPO}/libs") if os.path.isdir(f"{REPO}/libs/{s}/work")) if args == ["--all"] else args
tot_fixed = tot_left = 0
for slug in slugs:
    if gitlink(slug):
        print(f"{slug}: work/ is a gitlink, not edited in place")
        continue
    root = f"{REPO}/libs/{slug}/work"
    fixed = left = 0
    for dp, dn, fn in os.walk(root):
        for f in sorted(fn):
            if not f.endswith((".lpc", ".h", ".c")):
                continue
            p = os.path.join(dp, f)
            try:
                raw = open(p, "rb").read()
            except OSError:
                continue
            if b"@" not in raw or b"\x00" in raw:
                continue
            text = raw.decode("latin-1")
            rel = os.path.relpath(p, root)
            changed = False
            for _ in range(20):
                u = unterminated(blank_if0(text))
                if not u:
                    break
                at, term = u
                lines = text.split("\n")
                op_line = text.count("\n", 0, at)
                r = repair(lines, op_line, term)
                if isinstance(r, str):
                    print(f"  {slug}/{rel}:{op_line + 1}: @{term} never closed -- {r}: left")
                    left += 1
                    break
                k, kind, new = r
                eol = "\r" if lines[k].endswith("\r") else ""
                lines[k:k + 1] = [x + eol for x in new]
                text = "\n".join(lines)
                changed = True
                fixed += 1
                print(f"  {slug}/{rel}:{k + 1}: @{term} {kind} terminator {'repaired' if apply_ else 'to repair'}")
            if changed and apply_:
                open(p, "wb").write(text.encode("latin-1"))
    if fixed or left:
        print(f"{slug}: {fixed} block(s) {'repaired' if apply_ else 'to repair'}, {left} left")
    tot_fixed += fixed
    tot_left += left
print(f"{tot_fixed} block(s) {'repaired' if apply_ else 'to repair'}, {tot_left} left")
