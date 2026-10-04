#!/usr/bin/env python3
"""scripts/lpc_fix_negative_ranges.py [--apply] SLUG...      (or --all: every vendored lib; or --root DIR: any tree)

Count range ends from the end with `<` (KB 06 section 7.209): `x[a..-N]` -> `x[a..<N]`, `x[-N..]` -> `x[<N..]`,
`x[-K..-N]` -> `x[<K..<N]`.  In this driver a negative constant end gives "" / ({ }) and a negative start clamps to 0,
so every such range was written for the MudOS rule ("all but the last N", "the last K") and returns the wrong thing.
The driver warns only for the second element (`A negative constant as the second element of arr[x..y] ...`); this
finds both, in code only (comments, strings, here-documents and `#if 0` are blanked first; macros are code).

Left alone and listed:
* a range that is assigned to (`s[0..-1] = text`, `+=` ...): the documented prepend idiom, an lvalue;
* a bound that is a negative expression other than a plain `-name`, `-(expr)` or `-f(args)` (`msgs[-max+1..-1]`), or a
  negative literal with more after it (`x[0..-1+n]`): needs a hand edit.  `-name` / `-(expr)` / `-f(args)` bounds are
  rewritten with the minus turned into `<` (`str[-szf..n]` -> `str[<szf..n]`).
Without --apply it prints the plan (per lib and the first hits).  Edits are byte-exact (line endings kept).  Libs whose
work/ is a gitlink (deadsouls_fluffos, fy2005, imud, lima, nightmare3, nt7, oxidus, residuum, sanguozhi, xkx100utf8) are refused: run --root on a copy of upstream (git
archive of the submodule, existing patches applied) and carry the diff as a catalog patch or a PR (KB 02 section 2.3);
--root looks at .c files too."""
import json
import os
import re
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from lpc_src import mask  # noqa: E402

args = sys.argv[1:]
apply_ = "--apply" in args
args = [a for a in args if a != "--apply"]
root = None
if "--root" in args:
    i = args.index("--root")
    root = args[i + 1]
    del args[i:i + 2]
    args = [root]
if not args:
    sys.exit(__doc__)
EXTS = (".lpc", ".h", ".c") if root else (".lpc", ".h")


def hosting(slug):
    """'submodule' when libs/SLUG/work is a gitlink in this repo (the files belong to another repo), else 'vendored':
    meta.json's hosting says 'submodule-patch' for libs whose files are tracked here as plain files"""
    out = subprocess.run(["git", "-C", REPO, "ls-files", "-s", "--", f"libs/{slug}/work"], capture_output=True, text=True).stdout
    return "submodule" if any(l.startswith("160000") for l in out.split("\n")) else "vendored"


if root:
    slugs = [root]
elif args == ["--all"]:
    slugs = sorted(s for s in os.listdir(f"{REPO}/libs") if os.path.isdir(f"{REPO}/libs/{s}/work") and hosting(s) == "vendored")
else:
    slugs = args
NEG = re.compile(r"^-\s*(\d+)$")
ASSIGN = re.compile(r"\s*(?:[-+*/%&|^]|<<|>>)?=(?!=)")


def negated_primary(x):
    """'-name', '-(expr)' or '-f(args)' as a whole (nothing after the primary): the text after the minus, else None"""
    m = re.match(r"^-\s*([A-Za-z_]\w*\s*\(|\(|[A-Za-z_]\w*$)", x)
    if not m:
        return None
    rest = x[1:].strip()
    if m.group(1).endswith("("):
        i = rest.index("(")
        depth = 0
        for k in range(i, len(rest)):
            depth += (rest[k] == "(") - (rest[k] == ")")
            if depth == 0:
                return rest if k == len(rest) - 1 else None
        return None
    return rest


def ranges(masked):
    """yield (lo_start, lo_end, hi_start, hi_end, close) for every `[lo..hi]` subscript (offsets into masked)"""
    stack = []
    n = len(masked)
    i = 0
    while i < n:
        c = masked[i]
        if c == "[":
            stack.append([i, None])
        elif c == "]":
            if stack:
                op, dots = stack.pop()
                if dots is not None:
                    yield op + 1, dots, dots + 2, i, i
        elif c == "." and masked.startswith("..", i) and not masked.startswith("...", i) and (i == 0 or masked[i - 1] != "."):
            if stack and stack[-1][1] is None:
                stack[-1][1] = i
            i += 1
        i += 1


def process(text):
    """-> (new text, rewrites [(offset, old, new)], skipped [(offset, why, snippet)])"""
    masked = mask(text)
    edits, skipped = [], []
    for lo_s, lo_e, hi_s, hi_e, close in ranges(masked):
        lo, hi = masked[lo_s:lo_e].strip(), masked[hi_s:hi_e].strip()
        nlo, nhi = NEG.match(lo), NEG.match(hi)
        looks_neg = (lo.startswith("-") and not lo.startswith("--")) or (hi.startswith("-") and not hi.startswith("--"))
        if not (nlo or nhi) and not looks_neg:
            continue
        snippet = text[lo_s:hi_e + 1].replace("\n", " ")[:60]
        if ASSIGN.match(masked, close + 1):
            if nlo or nhi:
                skipped.append((lo_s, "range lvalue", snippet))
            continue
        plo = None if nlo or lo.startswith("--") else negated_primary(lo) if lo.startswith("-") else None
        phi = None if nhi or hi.startswith("--") else negated_primary(hi) if hi.startswith("-") else None
        if (lo.startswith("-") and not lo.startswith("--") and not nlo and plo is None) or \
           (hi.startswith("-") and not hi.startswith("--") and not nhi and phi is None):
            skipped.append((lo_s, "negative expression, not a literal or a negated name/call", snippet))
            continue
        for part, s0, e0, lit, prim in ((lo, lo_s, lo_e, nlo, plo), (hi, hi_s, hi_e, nhi, phi)):
            if lit or prim is not None:
                a = s0 + masked[s0:e0].index("-")
                edits.append((a, a + 1 if prim is not None else s0 + len(masked[s0:e0].rstrip()), "<" if prim is not None else "<" + lit.group(1)))
    out = text
    for a, b, new in sorted(edits, reverse=True):
        out = out[:a] + new + out[b:]
    return out, edits, skipped


total_files = total_edits = total_skipped = 0
for slug in slugs:
    if not root and hosting(slug) != "vendored":
        print(f"{slug}: hosting {hosting(slug)}, not edited in place (patch or PR)")
        continue
    work = root if root else f"{REPO}/libs/{slug}/work"
    lib_edits = lib_skipped = 0
    shown = 0
    for dp, dn, fn in os.walk(work):
        rel = os.path.relpath(dp, work)
        if rel == "log" or rel.startswith("log" + os.sep) or rel.startswith("raw"):
            continue
        for f in sorted(fn):
            if not f.endswith(EXTS):
                continue
            p = os.path.join(dp, f)
            try:
                text = open(p, "rb").read().decode("latin-1")
            except OSError:
                continue
            if ".." not in text:
                continue
            new, edits, skipped = process(text)
            for off, why, snip in skipped:
                ln = text.count("\n", 0, off) + 1
                print(f"  SKIP {slug}/{os.path.relpath(p, work)}:{ln}: {why}: {snip}")
                lib_skipped += 1
            if not edits:
                continue
            total_files += 1
            lib_edits += len(edits)
            if apply_:
                open(p, "wb").write(new.encode("latin-1"))
            elif shown < 2:
                a, b, repl = edits[0]
                ln = text.count("\n", 0, a) + 1
                print(f"  {slug}/{os.path.relpath(p, work)}:{ln}: {text.split(chr(10))[ln - 1].strip()[:90]}")
                shown += 1
    total_edits += lib_edits
    total_skipped += lib_skipped
    if lib_edits or lib_skipped:
        print(f"{slug}: {lib_edits} bound(s) {'rewritten' if apply_ else 'to rewrite'}, {lib_skipped} left for a hand edit")
print(f"{total_edits} bound(s) in {total_files} file(s), {total_skipped} left for a hand edit")
