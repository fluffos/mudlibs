#!/usr/bin/env python3
"""scripts/lpc_fix_missing_foo.py [--apply] [--list] SLUG [FILE...]

`"/clone/board/gaibang_r"->foo();` as a statement of its own: the xkx idiom that loads a board (any call forces the load, `foo()` is not even defined) at the end of a room's `create()`.  When
the lib has no such file (the Eastern Story lineages that never shipped their boards: fy2mg, njhhdxdes2hx, zzfy, xbtxiii, tianxiawuxue ... 53 libs, KB 06 section 7.357) the call raises
`*call_other() couldn't find object '/clone/board/gaibang_r'` inside `create()`: the room object stays loaded but `load_object()` raises for the player's first move into it, and a call in
the middle of a `create()` cuts the rest of it.  The fix comments the statement out and says why (`// "/x"->foo();  // no such file in this lib (KB 06 7.357)`), so a lib that later gains the
board shows what to put back.

Only a statement that fills a whole line (a trailing `//` comment is kept), the function `foo`, an absolute literal path with no `virtual` in it, whose file exists in neither `.lpc` nor `.c` spelling nor as a directory, in
`.lpc` / `.h` files outside wizard / backup / data directories.  Binary mode, the file's own line endings, idempotent.  Dry run by default; `--apply` writes; `--list` prints the lines."""
import os
import re
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SKIP = re.compile(r"/(u|w|wiz|wizard|wizards|players|backup|backups|bak|old|test|tests|tmp|data|log|realms|doc|docs|example|examples)/|[-_.](bak|old)/")
LINE = re.compile(rb'(?m)^([ \t]*)("(/[A-Za-z0-9_/.+-]+)"[ \t]*->[ \t]*foo[ \t]*\([ \t]*\)[ \t]*;)([ \t]*(?://[^\r\n]*)?)(\r?)$')


def fix(b, root):
    out, pos, changes = [], 0, []
    for m in LINE.finditer(b):
        path = m.group(3).decode("utf-8", "replace")
        if "virtual" in path:
            continue
        base = re.sub(r"\.(lpc|c)$", "", root + path)
        if os.path.isfile(base + ".lpc") or os.path.isfile(root + path) or os.path.isdir(base) or os.path.isfile(base + ".c"):
            continue
        out.append(b[pos:m.start()])
        out.append(m.group(1) + b"// " + m.group(2) + m.group(4).rstrip() + b"  // no such file in this lib: the call raised (KB 06 7.357)" + m.group(5))
        pos = m.end()
        changes.append(path)
    out.append(b[pos:])
    return b"".join(out), changes


def main():
    argv = sys.argv[1:]
    apply, listing = "--apply" in argv, "--list" in argv
    args = [a for a in argv if not a.startswith("--")]
    if not args:
        sys.exit(__doc__)
    slug, files = args[0], args[1:]
    root = os.path.join(REPO, "libs", slug, "work")
    if not files:
        out = subprocess.run(["git", "grep", "-l", "-E", r'^[[:space:]]*"/[A-Za-z0-9_/.+-]+"[[:space:]]*->[[:space:]]*foo[[:space:]]*\(', "--", f"libs/{slug}/work"], cwd=REPO, capture_output=True).stdout.split(b"\n")
        files = []
        for f in out:
            try:
                s = f.decode("utf-8")
            except UnicodeDecodeError:
                continue
            if s.endswith((".lpc", ".h")) and not SKIP.search(s[len(f"libs/{slug}/work"):] + "/"):
                files.append(s)
    nfile = nstmt = 0
    for f in sorted(files):
        p = f if os.path.isabs(f) else os.path.join(REPO, f)
        b = open(p, "rb").read()
        nb, ch = fix(b, root)
        if not ch:
            continue
        rel = p[len(root):] if p.startswith(root) else f
        nfile += 1
        nstmt += len(ch)
        print(f"{'FIX' if apply else 'would fix'} {rel}: {len(ch)} statement(s)")
        if listing:
            for c in ch:
                print(f"    {c}")
        if apply:
            open(p, "wb").write(nb)
    print(f"{slug}: {nstmt} statement(s) in {nfile} file(s)" + ("" if apply else " (plan only; --apply writes)"), file=sys.stderr)


if __name__ == "__main__":
    main()
