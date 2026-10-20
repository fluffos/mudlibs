#!/usr/bin/env python3
"""scripts/lpc_fix_cond_assign.py [--apply] [--while] [SLUG...]

`if (arg = "button" || arg = "按钮")`, `if (!arg || arg = "") return 0;`, `else if (check = 0 && tempB != "")`, `if (skill = 80 && ...)`: an assignment of a constant used as a
condition (scripts/lpc_scan_cond_assign.py lists them).  Its value is the constant, so the test is always true (a number other than 0, any string, even "") or always
false (0) and the variable is overwritten: the push of the hidden button works for any word, the command `return 0`s for every argument, the mahjong scorer never
awards the hand.  The driver warns about nothing.  `==` was meant: the `=` of every such term becomes `==` (in code only; a term whose right side is a call, a name or
an expression is the ordinary `if (ob = find_object(x))` idiom and is not touched).  `while (x = 0)` loops are left unless --while is given.

A chain that turns into `V == "a" && V == "b"` (one variable, different constants, joined by `&&`) can never be true: run scripts/lpc_fix_cmp_chain.py --apply on the same
libs afterwards, it makes the connective `||`.  Wizard directories, backups and examples are skipped; submodule libs are skipped.  Binary-safe, idempotent.  Without
--apply the plan is printed (`FIX<TAB>slug<TAB>/path<TAB>n`)."""
import multiprocessing
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import lpc_scan_cond_assign as sc  # noqa: E402


def work(args):
    slug, p, with_while, apply_ = args
    rel = "/" + p.split("/work/", 1)[1]
    if sc.TOP.search(rel) or sc.ANY.search(rel):
        return None
    try:
        b = open(os.path.join(sc.REPO, p), "rb").read()
    except OSError:
        return None
    if b"=" not in b:
        return None
    hits = [h for h in sc.scan(b) if h[3] == "if" or with_while]
    if not hits:
        return None
    out = bytearray(b)
    for line, term, eq, kw in sorted(hits, key=lambda h: -h[2]):
        assert out[eq:eq + 1] == b"=", (p, line, term)
        out[eq:eq + 1] = b"=="
    if apply_:
        with open(os.path.join(sc.REPO, p), "wb") as fh:
            fh.write(bytes(out))
    return slug, rel, len(hits)


def main():
    a = sys.argv[1:]
    apply_ = "--apply" in a
    with_while = "--while" in a
    slugs = {x for x in a if not x.startswith("--")}
    jobs = [(slug, p, with_while, apply_) for slug, paths in sorted(sc.tracked(slugs).items()) for p in paths]
    total = files = 0
    with multiprocessing.Pool(int(os.environ.get("JOBS", "6"))) as pool:
        for r in pool.imap(work, jobs, chunksize=64):
            if r:
                print(f"FIX\t{r[0]}\t{r[1]}\t{r[2]}")
                total += r[2]
                files += 1
    print(f"{total} term(s) in {files} file(s) {'fixed' if apply_ else 'fixable'}", file=sys.stderr)


if __name__ == "__main__":
    main()
