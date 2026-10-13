#!/usr/bin/env python3
"""scripts/lpc_fix_double_decl.py SLUG [--apply] [--only SUBSTR ...]

Fix `Redeclaration of global variable 'X'` when it comes from one declaration statement that names X twice, bare
and then with an initializer (KB 04 section 6.10):

    string games, plera_id, plerb_id, ause,
      games = "free",
      plera_id = "no";

The driver makes two variables; code below the statement uses the second one, the initialized one.  The bare
declarator is dropped, so one variable remains and nothing changes at run time (the initializers keep their order,
so `int weight, remaining, remaining = 10, weight = remaining * 3;` still sets remaining first).

Diagnostics come from $LPC_SCRATCH/lpcw-SLUG/diagnostics.tsv (scripts/lpc_warnings.py).  Only top-level
statements (brace depth 0) are touched; a name declared bare twice, or initialized twice, or in two statements,
is listed and left for a hand edit.  Without --apply it prints the plan.
"""
import os, re, sys, collections

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SCRATCH = os.environ.get("LPC_SCRATCH") or os.path.expanduser("~/.cache/lpc-scratch")
TYPES = r"(?:(?:nosave|static|private|protected|public|nomask|varargs)\s+)*" \
        r"(?:int|string|object|mixed|mapping|float|function|status|buffer|class\s+\w+)\b"


def mask(src):
    """Blank comments and string/char literals (same length), so brackets and commas can be counted."""
    out = list(src)
    i, n = 0, len(src)
    while i < n:
        c = src[i]
        if src.startswith("//", i):
            j = src.find("\n", i)
            j = n if j < 0 else j
            for k in range(i, j):
                out[k] = " "
            i = j
        elif src.startswith("/*", i):
            j = src.find("*/", i + 2)
            j = n if j < 0 else j + 2
            for k in range(i, j):
                if out[k] != "\n":
                    out[k] = " "
            i = j
        elif c in "\"'":
            j = i + 1
            while j < n and src[j] != c:
                j += 2 if src[j] == "\\" else 1
            for k in range(i + 1, min(j, n)):
                if out[k] != "\n":
                    out[k] = " "
            i = j + 1
        else:
            i += 1
    return "".join(out)


def statements(masked):
    """(start, end) of every top-level `TYPE ...;` declaration statement (end = index of the ';')."""
    depth = 0
    i, n = 0, len(masked)
    res = []
    while i < n:
        c = masked[i]
        if c == "{":
            depth += 1
        elif c == "}":
            depth -= 1
        elif depth == 0 and (i == 0 or masked[i - 1] in "\n;}") or depth == 0 and masked[i - 1].isspace() and \
                masked[max(0, masked.rfind("\n", 0, i)):i].strip() == "":
            m = re.match(r"[ \t]*" + TYPES, masked[i:])
            if m:
                j = i
                d2 = 0
                while j < n:
                    ch = masked[j]
                    if ch in "([{":
                        d2 += 1
                    elif ch in ")]}":
                        d2 -= 1
                    elif ch == ";" and d2 == 0:
                        break
                    elif ch == "{" and d2 == 0:
                        break
                    j += 1
                if j < n and masked[j] == ";" and "(" not in masked[i:j].split("=")[0]:
                    res.append((i, j))
                    i = j
        i += 1
    return res


def split_decls(masked, a, b):
    """Split masked[a:b] (after the type) into declarator spans at depth-0 commas."""
    m = re.match(r"[ \t]*" + TYPES, masked[a:b])
    pos = a + m.end()
    parts, d, start = [], 0, pos
    for k in range(pos, b):
        ch = masked[k]
        if ch in "([{":
            d += 1
        elif ch in ")]}":
            d -= 1
        elif ch == "," and d == 0:
            parts.append((start, k))
            start = k + 1
    parts.append((start, b))
    return pos, parts


def plan_file(path, names):
    src = open(path, encoding="utf-8", errors="surrogateescape", newline="").read()
    masked = mask(src)
    edits, manual = [], []
    for a, b in statements(masked):
        pos, parts = split_decls(masked, a, b)
        info = []
        for s, e in parts:
            m = re.match(r"\s*\**\s*(\w+)\s*(=)?", masked[s:e])
            if not m:
                info = None
                break
            info.append((m.group(1), bool(m.group(2)), s, e))
        if not info:
            continue
        cnt = collections.Counter(nm for nm, _, _, _ in info)
        dup = [nm for nm, c in cnt.items() if c > 1 and nm in names]
        if not dup:
            continue
        drop = set()
        for nm in dup:
            bare = [k for k, x in enumerate(info) if x[0] == nm and not x[1]]
            init = [k for k, x in enumerate(info) if x[0] == nm and x[1]]
            if len(bare) == 1 and len(init) == 1 and bare[0] < init[0]:
                drop.add(bare[0])
            else:
                manual.append((nm, "declared %d bare / %d initialized in one statement" % (len(bare), len(init))))
        if drop:
            edits.append((a, b, pos, info, drop))
    return src, edits, manual


def apply_edits(src, edits):
    for a, b, pos, info, drop in sorted(edits, reverse=True):
        keep = [src[s:e] for k, (_, _, s, e) in enumerate(info) if k not in drop]
        # keep the first kept declarator's leading whitespace tidy
        keep[0] = " " + keep[0].lstrip(" \t") if not keep[0].startswith(("\n", "\r")) else keep[0]
        body = ",".join(keep)
        src = src[:pos] + body + src[b:]
    return src


def main():
    args = sys.argv[1:]
    if not args or args[0].startswith("-"):
        print(__doc__)
        sys.exit(2)
    slug, apply = args[0], "--apply" in args
    only = [args[k + 1] for k, x in enumerate(args) if x == "--only"]
    tsv = os.path.join(SCRATCH, "lpcw-" + slug, "diagnostics.tsv")
    work = os.path.join(REPO, "libs", slug, "work")
    rows = [l.rstrip("\n").split("\t") for l in open(tsv, encoding="utf-8", errors="replace") if l.count("\t") >= 4]
    err = {r[0] for r in rows if r[3] == "error"}
    want = collections.defaultdict(set)
    for f, ln, col, sev, msg in rows:
        m = re.match(r"Redeclaration of global variable '(\w+)'", msg)
        if sev == "warning" and m and f not in err and (not only or any(o in f for o in only)):
            want[f].add(m.group(1))
    nfix = nfile = 0
    for f in sorted(want):
        path = os.path.join(work, f.lstrip("/"))
        if not os.path.isfile(path):
            continue
        src, edits, manual = plan_file(path, want[f])
        for nm, why in manual:
            print(f"LEFT {f}: {nm}: {why}")
        if not edits:
            continue
        names = sorted(info[k][0] for _, _, _, info, drop in edits for k in drop)
        print(("FIX  " if apply else "plan ") + f + ": " + ", ".join(names))
        nfix += len(names)
        nfile += 1
        if apply:
            new = apply_edits(src, edits)
            with open(path, "w", encoding="utf-8", errors="surrogateescape", newline="") as fh:
                fh.write(new)
    print(f"{nfix} bare declarator(s) in {nfile} file(s) {'removed' if apply else 'planned'}")


if __name__ == "__main__":
    main()
