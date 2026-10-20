#!/usr/bin/env python3
"""scripts/lpc_fix_missing_args.py [--apply] (SLUG [DIAGNOSTICS.tsv] | --all) [--skip REGEX]

`Wrong number of arguments to 'F', expected: N, minimum: M, got: K` with K < M: a call that passes fewer arguments than the function
declares, and the function is not `varargs`.  The old driver filled the missing ones with 0 and compiled the call; this one refuses the
whole object.  The call gets the zeros written out (`calculate_healing()` -> `calculate_healing(0)`, `set_hd(10)` -> `set_hd(10, 0)`), which is
exactly what the old driver did at run time, so nothing changes but the compile.  `0` is accepted for every parameter type.

Positions come from the driver: the diagnostics row points at the closing `)` of the call (columns are 1-based BYTES).  A row is fixed only when the
byte there is `)`, the matching `(` is found backwards (the call may run over several lines), the identifier in front of it is F, and the argument list has
exactly K top-level arguments; anything else is listed (a stale diagnostics file, a macro that expands to the call).  Calls to a function that
really needs its argument (`targ->query_x()` on the 0 it gets) run as they always did.  Too MANY arguments (got > expected) is a different
problem and is not touched.  Binary-safe; edits go from the end of each file to its start.

Without --apply the plan is printed.  The rows come from `DIAGNOSTICS.tsv` (default $LPC_SCRATCH/lpcw-SLUG/diagnostics.tsv, or the newest
scan under $LPC_SCRATCH/tkfix/diag and fresh/out*); `--all` takes every lib's newest list.  Check afterwards with scripts/lpc_listcheck.sh
at HEAD and in the tree (a file with another error behind this one still fails: put it back or fix the next error)."""
import glob
import os
import re
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SCRATCH = os.environ.get("LPC_SCRATCH") or os.path.expanduser("~/.cache/lpc-scratch")
ROW = re.compile(r"Wrong number of arguments to '(\w+)', expected: (\d+), minimum: (\d+), got: (\d+)")
IDENT_BEFORE = re.compile(rb"([A-Za-z_][A-Za-z0-9_]*)\s*$")


def mask(b):
    """same-length copy with comments and the contents of strings and character constants blanked (newlines kept)"""
    out = bytearray(b)
    i, n = 0, len(b)
    while i < n:
        c = b[i:i + 1]
        if b[i:i + 2] == b"//":
            j = b.find(b"\n", i)
            j = n if j < 0 else j
            for k in range(i, j):
                out[k] = 0x20
            i = j
            continue
        if b[i:i + 2] == b"/*":
            j = b.find(b"*/", i + 2)
            j = n if j < 0 else j + 2
            for k in range(i, j):
                if b[k] != 10:
                    out[k] = 0x20
            i = j
            continue
        if c in (b'"', b"'"):
            j = i + 1
            while j < n and b[j:j + 1] != c and b[j:j + 1] != b"\n":
                j += 2 if b[j:j + 1] == b"\\" else 1
            for k in range(i + 1, min(j, n)):
                out[k] = 0x20
            i = j + 1
            continue
        i += 1
    return bytes(out)


def top_level_args(m, a, z):
    """number of top-level, non-empty arguments between byte a and z of the masked text"""
    depth = 0
    cnt = 0
    seen = False
    for ch in m[a:z]:
        if ch in b"([{":
            depth += 1
            seen = True
        elif ch in b")]}":
            depth -= 1
        elif ch == 0x2C and depth == 0:
            cnt += 1
            continue
        elif ch not in b" \t\r\n":
            seen = True
    return (cnt + 1) if seen else 0


def matching_open(m, pos):
    depth = 0
    k = pos
    while k >= 0:
        ch = m[k:k + 1]
        if ch == b")":
            depth += 1
        elif ch == b"(":
            depth -= 1
            if depth == 0:
                return k
        k -= 1
    return -1


def matching_close(m, pos):
    depth = 0
    k = pos
    while k < len(m):
        ch = m[k:k + 1]
        if ch == b"(":
            depth += 1
        elif ch == b")":
            depth -= 1
            if depth == 0:
                return k
        k += 1
    return -1


def fix_file(path, rows):
    """rows: [(line, col, name, minimum, got)]; returns (new bytes or None, fixed, listed)"""
    b = open(path, "rb").read()
    m = mask(b)
    starts = [0]
    for i, ch in enumerate(b):
        if ch == 10:
            starts.append(i + 1)
    edits = []
    listed = []
    for ln, col, name, minimum, got in rows:
        if ln < 1 or ln > len(starts):
            listed.append((ln, name, "line out of range"))
            continue
        pos = starts[ln - 1] + col - 1
        k = -1
        if pos < len(b) and b[pos:pos + 1] == b")" and m[pos:pos + 1] == b")":
            k = matching_open(m, pos)
        if k < 0:
            # the driver points elsewhere for a call that is an argument of another call: take the one call to F on that line with K arguments
            line_end = starts[ln] - 1 if ln < len(starts) else len(b)
            cands = []
            for mt in re.finditer(rb"\b" + name.encode() + rb"\s*\(", m[starts[ln - 1]:line_end]):
                o = starts[ln - 1] + mt.end() - 1
                close = matching_close(m, o)
                if close >= 0 and top_level_args(m, o + 1, close) == got:
                    cands.append((o, close))
            if len(cands) != 1:
                listed.append((ln, name, "no `)` at the reported position" if not cands else "several calls on the line"))
                continue
            k, pos = cands[0]
        before = IDENT_BEFORE.search(m[max(0, k - 80):k])
        if not before or before.group(1).decode() != name:
            listed.append((ln, name, "the call in front of `(` is not " + name))
            continue
        have = top_level_args(m, k + 1, pos)
        if have != got:
            listed.append((ln, name, f"the call has {have} argument(s), the compiler counted {got}"))
            continue
        miss = minimum - got
        # insert right after the last argument (or right after `(`), not in front of trailing white space
        e = pos
        while e > k + 1 and m[e - 1:e] in (b" ", b"\t", b"\r", b"\n"):
            e -= 1
        text = (b", " if got else b"") + b", ".join([b"0"] * miss)
        edits.append((e, text))
    if not edits:
        return None, 0, listed
    out = bytearray(b)
    for e, text in sorted(set(edits), reverse=True):
        out[e:e] = text
    return bytes(out), len(set(edits)), listed


def newest_diag(slug):
    best = None
    for pat in (f"{SCRATCH}/lpcw-{slug}/diagnostics.tsv", f"{SCRATCH}/tkfix/diag/{slug}.tsv", f"{SCRATCH}/fresh/out*/diag-{slug}.tsv"):
        for p in glob.glob(pat):
            if best is None or os.path.getmtime(p) > os.path.getmtime(best):
                best = p
    return best


def main():
    a = sys.argv[1:]
    apply_ = "--apply" in a
    skip = a[a.index("--skip") + 1] if "--skip" in a else None
    args = [x for i, x in enumerate(a) if not x.startswith("--") and (i == 0 or a[i - 1] != "--skip")]
    if "--all" in a:
        slugs = sorted(os.path.basename(os.path.dirname(p)) for p in glob.glob(f"{REPO}/libs/*/work"))
        tsv = None
    elif args:
        slugs = [args[0]]
        tsv = args[1] if len(args) > 1 else None
    else:
        sys.exit(__doc__)
    total = 0
    lst = 0
    for slug in slugs:
        t = tsv or newest_diag(slug)
        if not t:
            continue
        by = {}
        seen = set()
        for row in open(t, encoding="utf-8", errors="replace"):
            f = row.rstrip("\n").split("\t")
            if len(f) < 5 or f[3] != "error":
                continue
            mm = ROW.match(f[4])
            if not mm or int(mm.group(4)) >= int(mm.group(3)):
                continue
            if skip and re.search(skip, f[0]):
                continue
            key = (f[0], f[1], f[2])
            if key in seen:
                continue
            seen.add(key)
            by.setdefault(f[0], []).append((int(f[1]), int(f[2]), mm.group(1), int(mm.group(3)), int(mm.group(4))))
        work = f"{REPO}/libs/{slug}/work"
        for rel, rows in sorted(by.items()):
            p = work + rel
            if not os.path.isfile(p):
                continue
            new, n, listed = fix_file(p, rows)
            for ln, name, why in listed:
                print(f"LIST\t{slug}\t{rel}:{ln}\t{name}\t{why}")
                lst += 1
            if new is not None:
                print(f"FIX\t{slug}\t{rel}\t{n}")
                total += n
                if apply_:
                    with open(p, "wb") as fh:
                        fh.write(new)
    print(f"{total} call(s) {'fixed' if apply_ else 'fixable'}, {lst} listed", file=sys.stderr)


if __name__ == "__main__":
    main()
