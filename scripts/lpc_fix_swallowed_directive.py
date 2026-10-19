#!/usr/bin/env python3
"""scripts/lpc_fix_swallowed_directive.py [SLUG...] [--apply] [--list FILE]

A directive that lost its line break and sits at the end of a `//` comment line is part of the comment, so the driver never sees it:

    // 蚀月咒inherit SSERVER;                      (22 libs: shiyue.lpc has no parent, `Undefined function offensive_target`)
    // heisuo.c  黑索#include <weapon.h>             (xkx100, xiakexing100: `WHIP` is not defined, syntax error on line 2)
    // renshen-guo.c 人参#include <ansi.h>           (xajh2, xo, xo_final)
    //sadboy is 2001.4.5inherit FORCE;               (a skill with no FORCE parent)

KB 06 section 7.274.  The line break was eaten by the encoding conversion (KB 03 section 4.6: a lone lead byte swallows the byte after it) or
by the archive's editor.  The fix puts the break back before the directive.

A line is changed when, among the first 12 lines of a tracked `.lpc` / `.h` file:
  - it starts with `//`, and ends (before the end of line) with `#include <x>` / `#include "x"` / `inherit NAME;` glued to the comment text
    (the character before the directive is neither a space nor one of `/ * # ( ) ' " backquote`: `//**inherit PRIVATE_ROOM;` is the luban template
    marker, `// (by rong)inherit F_DEALER;` a deliberate comment), and
  - the same directive does not stand on a line of its own elsewhere in the file (`// by yahoo 18:35 99-3-22#include <weapon.h>` above a real
    `#include <weapon.h>` is harmless).
Binary-safe, line endings kept (CR LF files get CR LF); without --apply the plan is printed (FIX lines); idempotent.
Afterwards load the changed files at HEAD and in the tree (scripts/lpc_listcheck.sh + scripts/lpc_load_diff.py): a file that compiled before can
disagree with the directive it now sees."""
import os
import re
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
GLUED = re.compile(rb"^([ \t]*//[^\n]*?[^\s/*#()'\"`])(#[ \t]*include[ \t]*(?:<[^>\n]*>|\"[^\"\n]*\")|inherit[ \t]+[A-Z_0-9]+[ \t]*;)([ \t]*\r?)$", re.M)
HEAD_LINES = 12


def norm(d):
    return re.sub(rb"\s+", b" ", d.strip())


def fix(b):
    """-> (new bytes, [directives]) ; the bytes are unchanged when nothing is to be done"""
    out = []
    pos = 0
    done = []
    lines_end = 0
    for _ in range(HEAD_LINES):
        lines_end = b.find(b"\n", lines_end) + 1
        if lines_end == 0:
            lines_end = len(b)
            break
    head = b[:lines_end]
    for m in GLUED.finditer(head):
        d = norm(m.group(2))
        others = [norm(l) for l in b[:m.start()].split(b"\n") + b[m.end():].split(b"\n")]
        if any(o.startswith(d) for o in others):
            continue
        eol = b"\r\n" if m.group(3).endswith(b"\r") else b"\n"
        out.append(b[pos:m.start()] + m.group(1).rstrip() + eol + m.group(2) + m.group(3))
        pos = m.end()
        done.append(d.decode("utf-8", "replace"))
    if not done:
        return b, done
    return b"".join(out) + b[pos:], done


def main():
    args = sys.argv[1:]
    apply = "--apply" in args
    listfile = None
    if "--list" in args:
        i = args.index("--list")
        listfile = args[i + 1]
        del args[i:i + 2]
    only = [a for a in args if not a.startswith("--")]
    if listfile:
        paths = [l.strip() for l in open(listfile, encoding="utf-8") if l.strip()]
    else:
        raw = subprocess.run(["git", "-c", "core.quotepath=false", "ls-files", "-z", "--", "libs/*/work/*.lpc", "libs/*/work/*.h"], cwd=REPO,
                             capture_output=True).stdout.split(b"\0")
        paths = [p.decode("utf-8", "replace") for p in raw if p]
    nfile = 0
    for rel in paths:
        slug = rel.split("/")[1]
        if only and slug not in only:
            continue
        if slug in ("wllz3", "longyunmeng_binary"):
            continue
        full = os.path.join(REPO, rel)
        try:
            whole = open(full, "rb").read()
        except OSError:
            continue
        new, done = fix(whole)
        if not done:
            continue
        nfile += 1
        print(f"FIX   {slug} /{rel.split('/work/', 1)[1]}: " + ", ".join(done))
        if apply:
            open(full, "wb").write(new)
    print(f"{nfile} file(s)" + ("" if apply else " (plan only; --apply writes)"))


if __name__ == "__main__":
    main()
