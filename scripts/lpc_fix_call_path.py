#!/usr/bin/env python3
"""scripts/lpc_fix_call_path.py scan [SLUG...]   |   scripts/lpc_fix_call_path.py apply [--apply] PLAN.tsv

A statement `"/d/mj/obj/baihong-jian"->move(this_player());` whose literal path names no file of the lib (KB 06 section 7.359): `call_other()` of a missing object raises
`couldn't find object` and the function stops there (the Eagle King's quest reward, `yingwang` in 20 libs of the Ming Cult lineage: the area was renamed `/d/mingjiao`, the reward
was not).  `scan` prints, per literal call to a missing file, the lib's candidate that DEFINES the called function:

    ABS<TAB>slug<TAB>file:line<TAB>written path<TAB>function<TAB>CASE x | TYPO x | DIRTYPO x | MOVED x | (no fn) .. | -

CASE is the same name in other letters, TYPO the one file of the written directory one letter or one swap away (a one-digit difference is a numbered sibling, not a typo: darkelib `md_cell2`
-> `md_cell1`), DIRTYPO the same file name one letter off in its directory name, MOVED the lib's only file of that name.  A path with a macro in front (`COMMAND_DIR "std/halt"`) is a suffix,
not a path, and is skipped.  Nothing is changed by `scan`: a MOVED candidate is a fix only after a reader checks that the function is the one the caller means (a wizard's directory, a backup or
a differently named sibling is not), so the plan is a hand-made TSV `slug<TAB>file<TAB>old<TAB>new<TAB>function` (`new` must exist in the lib and define the function: `apply` checks both).
`apply` rewrites the literal `"old"` that is followed by `->` in code, in binary mode, the file's own line endings; idempotent; dry run unless `--apply`."""
import collections
import os
import re
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, REPO + "/scripts")
import lpc_scan_callout_targets as S  # noqa: E402
from lpc_fix_void_return import code_mask  # noqa: E402

LIT = re.compile(rb'"(/?[A-Za-z0-9_][A-Za-z0-9_./+-]*/[A-Za-z0-9_./+-]+)"[ \t]*->[ \t]*([A-Za-z_]\w*)[ \t\r\n]*\(')
ROOTS = ("d", "clone", "kungfu", "std", "obj", "cmds", "daemon", "adm", "inherit", "feature", "quest", "secure", "include", "domains", "lib", "world", "realms", "areas", "system")


def lev1(a, b):
    la, lb = len(a), len(b)
    if abs(la - lb) > 1 or a == b:
        return False
    if la == lb:
        d = [i for i in range(la) if a[i] != b[i]]
        if len(d) == 1:
            return not (a[d[0]].isdigit() and b[d[0]].isdigit())     # a numbered sibling (cell1 / cell2) is not a typo
        return len(d) == 2 and d[1] == d[0] + 1 and a[d[0]] == b[d[1]] and a[d[1]] == b[d[0]]
    if la > lb:
        a, b = b, a
    return any(a[:i] == b[:i] and a[i:] == b[i + 1:] for i in range(len(b)))


def scan(slug):
    L = S.Lib(slug)
    low, bybase, bydir = collections.defaultdict(list), collections.defaultdict(list), collections.defaultdict(set)
    for f in L.files:
        if f.endswith(".lpc"):
            low[f[:-4].lower()].append(f)
            bybase[os.path.basename(f)].append(f)
            d, _, n = f.rpartition("/")
            bydir[d].add(n)
    dirs = {f.rsplit("/", 1)[0] for f in L.files}
    for f in sorted(L.files):
        if not f.endswith((".lpc", ".h")) or S.SKIP.search(f):
            continue
        b = L.read(f)
        if b"->" not in b:
            continue
        mask = None
        for m in LIT.finditer(b):
            i = m.start() - 1
            while i >= 0 and b[i] in b" \t":
                i -= 1
            if i >= 0 and (b[i:i + 1].isalnum() or b[i:i + 1] in (b"_", b'"')):
                continue                                             # a macro (or another string) in front: this literal is a suffix
            if mask is None:
                mask = code_mask(b, heredoc=True)
            if not mask[m.start()] and not (m.start() > 0 and mask[m.start() - 1]):
                continue
            p, fn = m.group(1).decode("utf-8", "replace"), m.group(2).decode()
            full = os.path.normpath(p if p.startswith("/") else "/" + p)
            stem = full[:-4] if full.endswith(".lpc") else full[:-2] if full.endswith(".c") else full
            if stem + ".lpc" in L.files or full in L.files or stem in dirs:
                continue
            if not any(stem.startswith("/" + r + "/") for r in ROOTS):
                continue
            sug = []
            d, _, n = stem.rpartition("/")
            if stem.lower() in low:
                sug = ["CASE " + x for x in low[stem.lower()]]
            else:
                near = [d + "/" + x[:-4] for x in bydir.get(d, ()) if lev1(n + ".lpc", x)]
                if len(near) == 1:
                    sug = ["TYPO " + near[0] + ".lpc"]
                else:
                    cands = bybase.get(n + ".lpc", [])
                    if len(cands) == 1:
                        sug = ["MOVED " + cands[0]]
                    elif d:
                        dd = [c for c in cands if lev1(os.path.dirname(c).split("/")[-1], d.split("/")[-1]) and os.path.dirname(c).rsplit("/", 1)[0] == d.rsplit("/", 1)[0]]
                        if len(dd) == 1:
                            sug = ["DIRTYPO " + dd[0]]
            good = []
            for s in sug:
                try:
                    defs = L.all_defs(s.split(" ", 1)[1])[0]
                except Exception:
                    continue
                if fn.encode() in defs:
                    good.append(s)
            line = b.count(b"\n", 0, m.start()) + 1
            yield "ABS\t%s\t%s:%d\t%s\t%s\t%s" % (slug, f, line, p, fn, good[0] if good else ("(no fn) " + sug[0] if sug else "-"))


def apply(plan, do_apply):
    libs, n = {}, 0
    for ln in open(plan, encoding="utf-8"):
        ln = ln.rstrip("\n")
        if not ln.strip() or ln.startswith("#"):
            continue
        slug, f, old, new, fn = ln.split("\t")[:5]
        if slug not in libs:
            libs[slug] = S.Lib(slug)
        L = libs[slug]
        cand = new if new.endswith(".lpc") else new + ".lpc"
        if cand not in L.files:
            print(f"SKIP  {slug} {f}: {new} does not exist")
            continue
        if fn.encode() not in L.all_defs(cand)[0]:
            print(f"SKIP  {slug} {f}: {new} does not define {fn}()")
            continue
        p = os.path.join(REPO, "libs", slug, "work") + f
        b = open(p, "rb").read()
        mask = code_mask(b, heredoc=True)
        out, last, hit = [], 0, 0
        for m in re.finditer(rb'"' + re.escape(old.encode()) + rb'"(?=[ \t]*->)', b):
            if not mask[m.start()] and not (m.start() > 0 and mask[m.start() - 1]):
                continue
            out.append(b[last:m.start()])
            out.append(b'"' + new.encode() + b'"')
            last = m.end()
            hit += 1
        if not hit:
            continue
        out.append(b[last:])
        n += hit
        print(f"{'FIX' if do_apply else 'would fix'} {slug} {f}: {old} -> {new} ({hit})")
        if do_apply:
            open(p, "wb").write(b"".join(out))
    print(f"{n} literal(s)" + ("" if do_apply else " (plan only; --apply writes)"), file=sys.stderr)


def main():
    argv = sys.argv[1:]
    if not argv or argv[0] not in ("scan", "apply"):
        sys.exit(__doc__)
    if argv[0] == "scan":
        slugs = [a for a in argv[1:] if not a.startswith("--")] or sorted(d for d in os.listdir(REPO + "/libs") if os.path.isdir(f"{REPO}/libs/{d}/work"))
        for slug in slugs:
            if slug in S.GITLINKS:
                continue
            for row in scan(slug):
                print(row, flush=True)
    else:
        plans = [a for a in argv[1:] if not a.startswith("--")]
        if len(plans) != 1:
            sys.exit(__doc__)
        apply(plans[0], "--apply" in argv)


if __name__ == "__main__":
    main()
