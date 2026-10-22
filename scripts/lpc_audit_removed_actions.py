#!/usr/bin/env python3
"""scripts/lpc_audit_removed_actions.py [BASE] [--libs=a,b] [--files=LISTFILE] [--allow-rename]

Audit of an `lpc_fix_dead_add_action.py --apply` run (KB 06 section 7.349): for every tracked .lpc / .c file that differs from BASE (default HEAD) the
diff may consist of nothing but removed `add_action(...)` statements: a deleted line is a whole `add_action("fn", "verb");` statement (a trailing comment allowed),
a changed line is the old line minus one such statement and its blanks, a renamed registration (`--allow-rename`) changes only the function name inside the
first string (--allow-rename).  A statement may span several lines (`add_action("fn", ({ "a", "b",` ... `}));`), end in a `//` or `/* */` comment, or stand under the header of a
braceless `if (..)` / `else` that the sweep took out with it (an `IFREMOVE` row): a deleted or replaced block is accepted when it is nothing but such statements (and at most a header
in front of the last one) once they are cut out, or when its remainder equals the new block without white space (`add_action(..); add_action(..);` on one line, the closing brace
below it).  --files takes the paths (one per line, `libs/SLUG/work/...`) the sweep touched, so that an unrelated edit in the same working tree is
not audited.  Prints `BAD path line text` for any other hunk and a count line; exit status 1 when anything is bad."""
import difflib
import os
import re
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
STMT = re.compile(rb'add_action\(\s*(?:"[A-Za-z_]\w*"|\(:[^)]*:\))\s*,\s*(?:"[^"\n]*"|\(\{[^}]*\}\)|[A-Za-z_]\w*)\s*\)\s*;')
WHOLE = re.compile(rb'^[ \t]*add_action\(.*\)\s*;[ \t]*(?://.*|/\*.*\*/)?[ \t]*\r?$')
REG = re.compile(rb'add_action\(\s*"([A-Za-z_]\w*)"')
ARGS = rb"(?:[^()]|\((?:[^()]|\((?:[^()]|\([^()]*\))*\))*\))*"
STMT_ML = re.compile(rb"add_action\(" + ARGS + rb"\)\s*;[ \t]*(?://[^\r\n]*|/\*[^\r\n]*?\*/)?", re.S)
HEADER = re.compile(rb"\s*(?:\bif\s*\(" + ARGS + rb"\)|\belse)\s*", re.S)


def squeeze(b):
    return re.sub(rb"\s+", b"", b)


def block_ok(old_lines, new_lines):
    """the old block is nothing but add_action statements (and a braceless header before them) once they are cut out of it, or equals the new block without white space"""
    ot, nt = b"\n".join(old_lines), b"\n".join(new_lines)
    n = len(STMT_ML.findall(ot))
    if not n:
        return 0
    rest = STMT_ML.sub(b"", ot)
    if squeeze(rest) == squeeze(nt):
        return n
    if not squeeze(nt) and HEADER.fullmatch(rest):
        return n
    return 0


def main():
    argv = [a for a in sys.argv[1:] if not a.startswith("--")]
    base = argv[0] if argv else "HEAD"
    only = None
    listed = None
    for a in sys.argv[1:]:
        if a.startswith("--libs="):
            only = set(a[7:].split(","))
        if a.startswith("--files="):
            listed = set(x.strip().encode() for x in open(a[8:], encoding="utf-8") if x.strip())
    names = subprocess.run(["git", "diff", "--name-only", "-z", base, "--", "libs"], cwd=REPO, capture_output=True).stdout.split(b"\0")
    bad = n_files = n_del = n_cut = n_ren = 0
    for p in names:
        if not p or not p.endswith((b".lpc", b".c")) or (listed is not None and p not in listed):
            continue
        m = re.match(rb"libs/([^/]+)/work/", p)
        if not m or (only and m.group(1).decode() not in only):
            continue
        path = p.decode("utf-8", "surrogateescape")
        old = subprocess.run(["git", "show", f"{base}:{path}"], cwd=REPO, capture_output=True).stdout
        try:
            new = open(f"{REPO}/{path}", "rb").read()
        except OSError:
            continue
        if old == new:
            continue
        n_files += 1
        a, b = old.split(b"\n"), new.split(b"\n")
        sm = difflib.SequenceMatcher(None, a, b, autojunk=False)
        for tag, i1, i2, j1, j2 in sm.get_opcodes():
            if tag == "equal":
                continue
            ok = block_ok(a[i1:i2], b[j1:j2]) if tag in ("delete", "replace") else 0
            if ok:
                n_del += ok
                continue
            if tag == "delete":
                for k in range(i1, i2):
                    if WHOLE.match(a[k]):
                        n_del += 1
                    else:
                        bad += 1
                        print(f"BAD {path} {k + 1} deleted: {a[k][:100]!r}")
            elif tag == "replace" and (i2 - i1) == (j2 - j1):
                for k in range(i2 - i1):
                    ol, nl = a[i1 + k], b[j1 + k]
                    cut = STMT.sub(b"", ol, count=1)
                    if re.sub(rb"\s+", b"", cut) == re.sub(rb"\s+", b"", nl):
                        n_cut += 1
                    else:
                        r1, r2 = REG.search(ol), REG.search(nl)
                        if r1 and r2 and ol.replace(r1.group(1), r2.group(1), 1) == nl and "--allow-rename" in sys.argv:
                            n_ren += 1
                        else:
                            bad += 1
                            print(f"BAD {path} {i1 + k + 1} changed: {ol[:90]!r} -> {nl[:90]!r}")
            elif tag == "replace":
                # a cut line may also have emptied the line (whole line gone, neighbours unchanged): treat unequal blocks as bad unless every old line is a whole statement
                if all(WHOLE.match(x) for x in a[i1:i2]) and not b[j1:j2]:
                    n_del += i2 - i1
                else:
                    bad += 1
                    print(f"BAD {path} {i1 + 1} block {tag}: {a[i1:i2][:2]!r} -> {b[j1:j2][:2]!r}")
            else:
                bad += 1
                print(f"BAD {path} {j1 + 1} {tag}: {b[j1:j2][:2]!r}")
    print(f"{n_files} file(s): {n_del} deleted statement line(s), {n_cut} cut statement(s), {n_ren} renamed registration(s), {bad} bad")
    sys.exit(1 if bad else 0)


if __name__ == "__main__":
    main()
