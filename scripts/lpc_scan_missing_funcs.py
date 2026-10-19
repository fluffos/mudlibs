#!/usr/bin/env python3
"""scripts/lpc_scan_missing_funcs.py --diag DIR [SLUG...] [--min N] [--skip SLUG,SLUG]

Detector, no edits (KB 06 section 7.262).  `Undefined function set_ghost` / `prepare_skill` / `NewRandom` in the compile scan of
a lib is often a function that the lib's own copy of a base file lost while the sibling libs' copy of the same file still has it
(`feature/damage.lpc` without `set_ghost`, `feature/skill.lpc` without the prepared-skill block).  For every lib and every
lower-case undefined function name that makes at least N files fail (default 3) this looks for libs that define the function in a
file whose path the failing lib also has and does not define it in, and prints one line per (lib, function, base file):

    NEED files lib function base-file donors=<libs defining it there> same-text=<of them with the commonest text> rel=<best relatedness> lines=<size>

Read the line, then `scripts/lpc_transplant_function.py --lib LIB --from DONOR --path /base-file --name function` plans the copy
(and says which identifiers the target file lacks).  The dbase API (`query`, `set`, `add` ... : a mixin without `#include <dbase.h>`, KB 05 section 7.15) is left out.
A function the lib's code calls but no sibling defines (LDMud `member`,
sefuns of a lineage the lib is not part of) shows no line.  --diag DIR is the output of scripts/lpc_warnings.py (DIR/diag-SLUG.tsv);
relatedness is the byte-identical file count of $LPC_SCRATCH/relatedness.pkl (scripts/lpc_restore_bases.py --refresh builds it).
The definition search is one `git grep` over libs/ (minutes)."""
import collections
import glob
import os
import pickle
import re
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from lpc_fix_void_return import code_mask  # noqa: E402

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SCRATCH = os.environ.get("LPC_SCRATCH") or os.path.expanduser("~/.cache/lpc-scratch")
SKIP = re.compile(r"/(u|w|wiz|wizard|wizards|open|players|backup|backups|old|bak|log|data|doc|docs|example|examples|test|tmp|attic)/|[-_.](bak|old|orphaned-driver-src)/|\.(bak|BAK|old|orig)(\.lpc)?$")
# the dbase API: an `Undefined function query` is a mixin without the F_DBASE prototypes (KB 05 section 7.15), not a lost function
DBASE_API = {"query", "set", "delete", "add", "query_temp", "set_temp", "delete_temp", "add_temp", "query_entire_dbase", "query_entire_temp_dbase"}
DEF = re.compile(r"^libs/([^/]+)/work/(.*?):(\d+):\s*(?:(?:varargs|static|nomask|private|protected|public)\s+)*(?:void|int|string|mixed|object|mapping|float|status)\s*\**\s*([A-Za-z_]\w*)\s*\(")


def extract(slug, path, line):
    try:
        b = open(f"{REPO}/libs/{slug}/work/{path}", "rb").read()
    except OSError:
        return None
    mask = code_mask(b, heredoc=True)
    code = bytes(c if m else 32 for c, m in zip(b, mask))
    starts = [0] + [m.end() for m in re.finditer(rb"\n", b)]
    if line - 1 >= len(starts):
        return None
    s = starts[line - 1]
    po = code.find(b"(", s)
    d = 0
    pc = -1
    for j in range(po, len(code)):
        if code[j:j + 1] == b"(":
            d += 1
        elif code[j:j + 1] == b")":
            d -= 1
            if d == 0:
                pc = j
                break
    if pc < 0:
        return None
    k = pc + 1
    while k < len(code) and code[k:k + 1] in b" \t\r\n":
        k += 1
    if code[k:k + 1] != b"{":
        return None
    d = 0
    for j in range(k, len(code)):
        if code[j:j + 1] == b"{":
            d += 1
        elif code[j:j + 1] == b"}":
            d -= 1
            if d == 0:
                return b[s:j + 1].decode("utf-8", "replace")
    return None


def main():
    args = sys.argv[1:]
    diag = None
    minf = 3
    skip = set()
    if "--diag" in args:
        i = args.index("--diag")
        diag = args[i + 1]
        del args[i:i + 2]
    if "--min" in args:
        i = args.index("--min")
        minf = int(args[i + 1])
        del args[i:i + 2]
    if "--skip" in args:
        i = args.index("--skip")
        skip = set(args[i + 1].split(","))
        del args[i:i + 2]
    only = [a for a in args if not a.startswith("--")]
    if not diag:
        sys.exit(__doc__)
    files = collections.defaultdict(set)
    for f in glob.glob(os.path.join(diag, "diag-*.tsv")):
        slug = os.path.basename(f)[5:-4]
        if only and slug not in only or slug in skip:
            continue
        for l in open(f, encoding="utf-8", errors="replace"):
            p = l.rstrip("\n").split("\t")
            if len(p) < 5 or p[3] != "error" or SKIP.search(p[0]):
                continue
            m = re.match(r"Undefined function ([A-Za-z_]\w*)", p[4])
            if m and not m.group(1).isupper() and m.group(1) not in DBASE_API:
                files[(slug, m.group(1))].add(p[0])
    want = {n for (s, n), fl in files.items() if len(fl) >= minf}
    if not want:
        print("nothing wanted")
        return
    pat = "|".join(sorted(want))
    out = subprocess.run(["git", "grep", "-n", "-E", r"^[ \t]*((varargs|static|nomask|private|protected|public)[ \t]+)*(void|int|string|mixed|object|mapping|float|status)[ \t]*[*]*[ \t]*(" + pat + r")[ \t]*\(", "--", "libs"],
                         cwd=REPO, capture_output=True, text=True, errors="replace").stdout
    defs = collections.defaultdict(set)
    for l in out.split("\n"):
        m = DEF.match(l.strip().strip('"'))
        if m and m.group(4) in want:
            defs[m.group(4)].add((m.group(1), m.group(2), int(m.group(3))))
    rel = pickle.load(open(os.path.join(SCRATCH, "relatedness.pkl"), "rb"))[0]
    have = collections.defaultdict(set)
    for f in subprocess.run(["git", "ls-files", "-z", "--", "libs"], cwd=REPO, capture_output=True).stdout.split(b"\0"):
        try:
            p = f.decode("utf-8")
        except UnicodeDecodeError:
            continue
        parts = p.split("/", 3)
        if len(parts) == 4 and parts[2] == "work":
            have[parts[1]].add(parts[3])
    rows = []
    for (slug, name), fl in files.items():
        if len(fl) < minf:
            continue
        own = {p for (s, p, ln) in defs[name] if s == slug}
        cand = collections.defaultdict(list)
        for (s, p, ln) in defs[name]:
            if s != slug and p in have[slug] and p not in own and p.endswith((".lpc", ".h")):
                cand[p].append((s, ln))
        for p, ds in cand.items():
            texts = collections.Counter()
            for (s, ln) in ds:
                t = extract(s, p, ln)
                if t:
                    texts[re.sub(r"\s+", " ", t)] += 1
            if not texts:
                continue
            k, c = texts.most_common(1)[0]
            best = max((rel.get((slug, d), 0) for d, _ in ds), default=0)
            rows.append((len(fl), slug, name, p, len(ds), c, best, k.count("{") and len(k) // 40 + 1))
    rows.sort(key=lambda r: (-r[0], r[1]))
    for r in rows:
        print(f"NEED  {r[0]:4d} {r[1]} {r[2]} /{r[3]} donors={r[4]} same-text={r[5]} rel={r[6]} lines~{r[7]}")
    print(f"{len(rows)} (lib, function, base file) line(s)")


if __name__ == "__main__":
    main()
