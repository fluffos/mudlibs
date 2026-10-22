#!/usr/bin/env python3
"""scripts/lpc_fix_dotc_path.py [--apply] [--list] SLUG [FILE...]

A string literal `"/d/shaolin/obj/qimeigun.c"` in code (`carry_object("/x/y.c")->wield()`, `new("/x/y.c")`, `inherit "/x/y.c"`, `"down" : "/x/y.c"` in an exits mapping, a vendor
`"/x/y.c" : 10`, `#define MYFILE "/x/y.c"`) while the lib's file is `/x/y.lpc` (KB 06 section 7.356).  The archive's `.c` files were renamed `.lpc` and an explicit extension is resolved
EXACTLY (KB 03 section 4.2): `new("/x/y.c")` finds no file, answers 0, and `0->move()` / `carry_object(..)->wield()` raises `Bad argument 1 to EFUN call_other() Got int(0)`: the
NPC of sjshwzb / sjshwzjqb's Shaolin monks (`sengbing`, `gunseng`) never finishes `create()`, mohuanshiji's treasurer cannot hand out 17 items, jym's escort cart names 6 NPCs it can
not clone, 12 exits of sjshv2578bb lead nowhere.

The fix is the literal with `.lpc`: only a literal in code (comments, other strings and here-docs are skipped) whose `.c` file does NOT exist and whose `.lpc` file does is rewritten;
a literal whose target exists in neither spelling is printed as MISSING and left (a content gap, not this defect), one whose `.c` file exists is a lib that keeps `.c` files and is
left.  Wizard / backup / data directories and `*.orphaned-dir` are skipped.  Without FILE arguments every tracked `.lpc` / `.h` of the lib that holds such a literal is taken.
Binary mode, the file's own line endings, idempotent (a rewritten literal has no `.c` left).  Dry run by default; `--apply` writes; `--list` prints every literal."""
import os
import re
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SKIP = re.compile(r"/(u|w|wiz|wizard|wizards|open|players|backup|backups|bak|old|test|tests|tmp|data|log|realms)/|[-_.](bak|old)|orphaned-dir|class_bak")
PATH = re.compile(rb"^/[A-Za-z0-9_/.+\- ]+\.c$")
HEREDOC = re.compile(rb"@@?([A-Za-z_][A-Za-z_0-9]*)[ \t]*\r?\n")


def literals(b):
    """(start, end) of every string literal that sits in code: comments, character literals and `@LONG ... LONG` here-docs are skipped"""
    i, n, out = 0, len(b), []
    while i < n:
        c = b[i]
        if c == 0x2F and b[i + 1:i + 2] == b"/":
            j = b.find(b"\n", i)
            i = n if j < 0 else j
        elif c == 0x2F and b[i + 1:i + 2] == b"*":
            j = b.find(b"*/", i + 2)
            i = n if j < 0 else j + 2
        elif c == 0x22:
            j = i + 1
            while j < n and b[j] != 0x22:
                if b[j] == 0x5C:
                    j += 1
                if b[j:j + 1] == b"\n":
                    break
                j += 1
            out.append((i, j + 1))
            i = j + 1
        elif c == 0x27:
            j = i + 1
            while j < n and b[j] != 0x27:
                if b[j] == 0x5C:
                    j += 1
                if b[j:j + 1] == b"\n":
                    break
                j += 1
            i = j + 1
        elif c == 0x40:
            m = HEREDOC.match(b, i)
            if m:
                k = b.find(b"\n" + m.group(1), m.end())
                i = n if k < 0 else k + 1 + len(m.group(1))
            else:
                i += 1
        else:
            i += 1
    return out


def fix(b, root):
    """returns (new bytes, [(old, new)], [missing paths])"""
    out, pos, changes, missing = [], 0, [], []
    for s, e in literals(b):
        inner = b[s + 1:e - 1]
        if not PATH.match(inner):
            continue
        p = inner.decode("utf-8", "replace")
        if os.path.isfile(root + p):
            continue
        if os.path.isfile(root + p[:-2] + ".lpc"):
            out.append(b[pos:s])
            out.append(b'"' + inner[:-2] + b'.lpc"')
            pos = e
            changes.append((p, p[:-2] + ".lpc"))
        elif not os.path.isdir(root + p[:-2]) and not os.path.isfile(root + p[:-2]):
            missing.append(p)
    out.append(b[pos:])
    return b"".join(out), changes, missing


def main():
    argv = sys.argv[1:]
    apply, listing = "--apply" in argv, "--list" in argv
    args = [a for a in argv if not a.startswith("--")]
    if not args:
        sys.exit(__doc__)
    slug, files = args[0], args[1:]
    root = os.path.join(REPO, "libs", slug, "work")
    if not files:
        out = subprocess.run(["git", "grep", "-l", "-E", r'"/[A-Za-z0-9_/.+-]+\.c"', "--", f"libs/{slug}/work"], cwd=REPO, capture_output=True).stdout.split(b"\n")
        files = []
        for f in out:
            try:
                s = f.decode("utf-8")
            except UnicodeDecodeError:
                continue
            if s.endswith((".lpc", ".h")) and not SKIP.search(s[len(f"libs/{slug}/work"):]):
                files.append(s)
    nfile = nlit = nmiss = 0
    for f in sorted(files):
        p = f if os.path.isabs(f) else os.path.join(REPO, f)
        b = open(p, "rb").read()
        nb, ch, miss = fix(b, root)
        rel = p[len(root):] if p.startswith(root) else f
        for m in miss:
            print(f"MISSING {rel}: {m} (the file exists in neither spelling: a content gap, left)")
            nmiss += 1
        if not ch:
            continue
        nfile += 1
        nlit += len(ch)
        print(f"{'FIX' if apply else 'would fix'} {rel}: {len(ch)} literal(s)")
        if listing:
            for old, new in ch:
                print(f"    {old} -> {new}")
        if apply:
            open(p, "wb").write(nb)
    print(f"{slug}: {nlit} literal(s) in {nfile} file(s), {nmiss} missing" + ("" if apply else " (plan only; --apply writes)"), file=sys.stderr)


if __name__ == "__main__":
    main()
