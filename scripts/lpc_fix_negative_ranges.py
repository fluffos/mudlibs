#!/usr/bin/env python3
"""scripts/lpc_fix_negative_ranges.py [--apply] SLUG...      (or --all: every vendored lib)

Count range ends from the end with `<` (KB 06 section 7.209): `x[a..-N]` -> `x[a..<N]`, `x[-N..]` -> `x[<N..]`,
`x[-K..-N]` -> `x[<K..<N]`.  In this driver a negative constant end gives "" / ({ }) and a negative start clamps to 0,
so every such range was written for the MudOS rule ("all but the last N", "the last K") and returns the wrong thing.
The driver warns only for the second element (`A negative constant as the second element of arr[x..y] ...`); this
finds both, in code only (comments, strings, here-documents and `#if 0` are blanked first; macros are code).

Left alone and listed:
* a range that is assigned to (`s[0..-1] = text`, `+=` ...): the documented prepend idiom, an lvalue;
* a bound that is a negative expression rather than a literal (`msgs[-max+1..-1]`), or a negative literal with more
  after it (`x[0..-1+n]`): needs a hand edit.
Without --apply it prints the plan (per lib and the first hits).  Edits are byte-exact (line endings kept).  Libs whose
work/ is a submodule (hosting submodule-patch / fluffos-upstream) are refused: carry the change as a catalog patch or a
PR (KB 02 section 2.3)."""
import json
import os
import re
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from lpc_src import mask  # noqa: E402

args = sys.argv[1:]
apply_ = "--apply" in args
args = [a for a in args if a != "--apply"]
if not args:
    sys.exit(__doc__)


def hosting(slug):
    try:
        return json.load(open(f"{REPO}/libs/{slug}/meta.json")).get("hosting") or "vendored"
    except OSError:
        return "vendored"


if args == ["--all"]:
    slugs = sorted(s for s in os.listdir(f"{REPO}/libs") if os.path.isdir(f"{REPO}/libs/{s}/work") and hosting(s) == "vendored")
else:
    slugs = args
NEG = re.compile(r"^-\s*(\d+)$")
ASSIGN = re.compile(r"\s*(?:[-+*/%&|^]|<<|>>)?=(?!=)")


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
        looks_neg = lo.startswith("-") or hi.startswith("-")
        if not (nlo or nhi) and not looks_neg:
            continue
        snippet = text[lo_s:hi_e + 1].replace("\n", " ")[:60]
        if ASSIGN.match(masked, close + 1):
            if nlo or nhi:
                skipped.append((lo_s, "range lvalue", snippet))
            continue
        if (lo.startswith("-") and not nlo) or (hi.startswith("-") and not nhi):
            skipped.append((lo_s, "negative expression, not a literal", snippet))
            continue
        if nlo:
            a = lo_s + masked[lo_s:lo_e].index("-")
            edits.append((a, lo_s + len(masked[lo_s:lo_e].rstrip()), "<" + nlo.group(1)))
        if nhi:
            a = hi_s + masked[hi_s:hi_e].index("-")
            edits.append((a, hi_s + len(masked[hi_s:hi_e].rstrip()), "<" + nhi.group(1)))
    out = text
    for a, b, new in sorted(edits, reverse=True):
        out = out[:a] + new + out[b:]
    return out, edits, skipped


total_files = total_edits = total_skipped = 0
for slug in slugs:
    if hosting(slug) != "vendored":
        print(f"{slug}: hosting {hosting(slug)}, not edited in place (patch or PR)")
        continue
    work = f"{REPO}/libs/{slug}/work"
    lib_edits = lib_skipped = 0
    shown = 0
    for dp, dn, fn in os.walk(work):
        rel = os.path.relpath(dp, work)
        if rel == "log" or rel.startswith("log" + os.sep) or rel.startswith("raw"):
            continue
        for f in sorted(fn):
            if not f.endswith((".lpc", ".h")):
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
