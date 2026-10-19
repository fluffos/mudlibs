#!/usr/bin/env python3
"""scripts/lpc_fix_swallowed_statement.py [SLUG...] [--apply]

A statement that lost its line break sits at the end of a `//` comment, behind the indentation of the line it used to start:

    set("xyzx_sys/level", jibie);  //2016.5.22阿飞调整NPC属性    set_name("小沙弥", ({ "xiao shami", "shami" }) );   (xajh4gkb: 4 NPCs with no name)
    set_weight(4000);  //***** ADDED BY SCATTER *****                 set("wposition", "/d/baituo/obj/lingshezhang.lpc");   (20 libs)
    pay_back(...);  //归还前一个竞买者的钱               add("pnum",1);                  (5 libs: the auction's bidder counter is never incremented)

The comment ate the next statement, so the driver compiles a file that silently does less (KB 06 section 7.274, the statement-level twin of the swallowed
directive).  A line is split when the code before `//` ends with `;`, `{`, `}` or `)`, the comment text is followed by a run of 3 or more blanks
(or a tab) and a statement that ends the line (`f(...);`, `if (...) {`, `return ...;`, `} else ...`), and the swallowed part has balanced quotes and
parentheses (a half-quoted message such as dreamofseven's `add_force.lpc` stays).  The new line gets the indentation of the line it follows.
Binary-safe, line endings kept; without --apply the plan is printed (FIX lines); idempotent."""
import os
import re
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
TAIL = re.compile(rb"( {3,}|\t+)((?:[A-Za-z_]\w*[ \t]*\([^\n]*\)[ \t]*;|if[ \t]*\([^\n]*\)[ \t]*\{?|\}[ \t]*(?:else[^\n]*)?|return[^\n]*;)[ \t]*)(\r?)$")


def balanced(s):
    q = 0
    depth = 0
    i = 0
    while i < len(s):
        c = s[i:i + 1]
        if c == b'"':
            q ^= 1
        elif c == b"\\" and q:
            i += 1
        elif not q:
            if c in b"([{":
                depth += 1
            elif c in b")]}":
                depth -= 1
        i += 1
    return q == 0 and depth >= 0


def fix(b):
    """-> (new bytes, [lines])"""
    out = []
    lines = []
    for ln, line in enumerate(b.split(b"\n"), 1):
        i = line.find(b"//")
        if i < 0 or len(line) > 600:
            out.append(line)
            continue
        pre = line[:i]
        stripped = pre.strip()
        if not stripped or stripped[-1:] not in b";{})" or pre.count(b'"') % 2:
            out.append(line)
            continue
        rest = line[i + 2:]
        m = TAIL.search(rest)
        if not m:
            out.append(line)
            continue
        txt = rest[:m.start()]
        if len(txt.strip()) < 2 or not (re.search(rb"[\x80-\xff]", txt) or re.search(rb"[A-Za-z]{3,}\s+[A-Za-z]{2,}", txt) or b"*" in txt):
            out.append(line)
            continue
        code = m.group(2)
        if not balanced(code):
            out.append(line)
            continue
        ind = re.match(rb"[ \t]*", line).group(0)
        eol = b"\r" if m.group(3) else b""
        out.append(line[:i + 2] + txt.rstrip(b" \t") + eol)
        out.append(ind + code + eol)
        lines.append(ln)
    return b"\n".join(out), lines


def main():
    args = sys.argv[1:]
    apply = "--apply" in args
    only = [a for a in args if not a.startswith("--")]
    raw = subprocess.run(["git", "-c", "core.quotepath=false", "ls-files", "-z", "--", "libs/*/work/*.lpc", "libs/*/work/*.h"], cwd=REPO,
                         capture_output=True).stdout.split(b"\0")
    nfile = nline = 0
    for r in raw:
        if not r:
            continue
        rel = r.decode("utf-8", "surrogateescape")
        slug = rel.split("/")[1]
        if (only and slug not in only) or slug in ("wllz3", "longyunmeng_binary"):
            continue
        full = os.path.join(REPO, rel)
        try:
            b = open(full, "rb").read()
        except OSError:
            continue
        if b"//" not in b:
            continue
        new, lines = fix(b)
        if not lines:
            continue
        nfile += 1
        nline += len(lines)
        print(f"FIX   {slug} /{rel.split('/work/', 1)[1]}: line(s) {','.join(map(str, lines))}")
        if apply:
            open(full, "wb").write(new)
    print(f"{nline} line(s) in {nfile} file(s)" + ("" if apply else " (plan only; --apply writes)"))


if __name__ == "__main__":
    main()
