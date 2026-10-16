#!/usr/bin/env python3
"""scripts/lpc_drop_replace_program.py [--apply] SLUG_OR_DIR...

Deletes the redundant `replace_program(X);` lines of a lib (docs/kb/06-runtime-classes-2.md sections 7.86 and 7.100):
a room or board that does `inherit ROOM;` and ends its create() with `replace_program(ROOM);` leaves a pending program
replacement, and any closure bound to the object before it takes effect fails with `cannot bind an lfun fp to an object
with a pending replace_program()` (board `post`, rooms whose reset() filters with a closure).  The corpus sweep of 191 libs
used this rule by hand; this script is the same rule for a new lib:

  * a line that holds only `replace_program(X);` (spaces, a trailing `//` comment and CRLF allowed) is deleted
    when X is one of the file's own `inherit` arguments, macro or string, with or without `.c`/`.lpc`
    (`inherit ROOM;` + `replace_program(ROOM);`, `inherit "/inherit/room/room";` + the same string in a decompiled file);
  * a call with any other argument, or on a line with other code, is listed (LEFT) and kept;
  * commented-out calls are not touched.

Room generators that write `replace_program(ROOM);` into new files (roommaker, rmaker, playerhome builders) are a string,
not a statement: grep them and fix the template by hand.

SLUG means libs/SLUG/work; a directory is taken as is (rebuild scripts run it on the tree they build).  Without --apply it
prints the counts and the LEFT lines.  Edits are byte-exact (binary mode); only whole lines are removed."""
import os
import re
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
INHERIT = re.compile(rb'^[ \t]*inherit[ \t]+([A-Za-z_][A-Za-z0-9_]*|"[^"\n]*")[ \t]*;', re.M)
CALL = re.compile(rb'^[ \t]*replace_program[ \t]*\([ \t]*([A-Za-z_][A-Za-z0-9_]*|"[^"\n]*")[ \t]*\)[ \t]*;[ \t]*'
                  rb'(?://[^\r\n]*)?(?:\r?\n|$)', re.M)
SKIP_DIRS = {"log", "binaries", ".git"}


def norm(arg):
    for ext in (b'.c"', b'.lpc"'):
        if arg.endswith(ext):
            return arg[:-len(ext)] + b'"'
    return arg


def drop(data):
    """(new data, removed count, [kept call lines])"""
    own = {norm(m.group(1)) for m in INHERIT.finditer(data)}
    kept = []

    def sub(m):
        if norm(m.group(1)) in own:
            return b""
        kept.append(m.group(0).strip())
        return m.group(0)

    new, n = CALL.subn(sub, data)
    return new, n - len(kept), kept


def main():
    args = sys.argv[1:]
    apply = "--apply" in args
    roots = [a for a in args if a != "--apply"]
    if not roots:
        sys.exit(__doc__)
    files = calls = 0
    left = []
    for r in roots:
        root = r if os.path.isdir(r) else os.path.join(REPO, "libs", r, "work")
        if not os.path.isdir(root):
            sys.exit(f"no such lib or directory: {r}")
        for dp, dn, fn in os.walk(root):
            dn[:] = sorted(d for d in dn if d not in SKIP_DIRS)
            for f in sorted(fn):
                if not f.endswith((".lpc", ".c")):
                    continue
                p = os.path.join(dp, f)
                data = open(p, "rb").read()
                if b"replace_program" not in data:
                    continue
                new, n, kept = drop(data)
                left += [(os.path.relpath(p, root), k) for k in kept]
                if n:
                    files += 1
                    calls += n
                    if apply:
                        with open(p, "wb") as fh:
                            fh.write(new)
    for p, k in left:
        print(f"LEFT  {p}: {k.decode('utf-8', 'replace')}")
    print(f"{calls} call(s) in {files} file(s){'' if apply else ' (plan only; --apply writes)'}; {len(left)} left")


if __name__ == "__main__":
    main()
