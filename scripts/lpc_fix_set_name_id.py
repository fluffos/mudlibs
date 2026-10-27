#!/usr/bin/env python3
"""scripts/lpc_fix_set_name_id.py --diag DIR [SLUG...] [--apply]

`set_name("海口大碗", "bowl");` where the lib's `set_name(string name, string *id)` takes the ids as an array (KB 06 section
7.260).  The driver says `Bad type for argument 2 of set_name ( string * vs string )` and the object never loads: the Baituo
bowl `d/baituo/npc/obj/bowl` is this one line in 46 libs of the Eastern Story family; pkuxkx's gem blades and swords pass
`blade_id[type - 1]`.  The old driver did not check the argument; `member_array(str, "bowl")` still found the word, so the
object answered to its id.

--diag DIR  the scan output of scripts/lpc_warnings.py (DIR/diag-SLUG.tsv).  The `Bad type for argument 2 of set_name ( string * vs
            string )` rows name the call; the second argument becomes `({ ... })` when it is a plain string literal (letters, digits,
            blanks, `_ . ' -`) or an indexed name (`blade_id[type - 1]`).  Anything else (`set_name("short", @LONG ... LONG)`, where the
            author took set_name for set) is listed and left.
Comments, strings and here-docs are masked; the file's own line endings are kept; wizard, backup and example dirs are skipped (`/open/` is playable world, not skipped).
Without --apply the plan is printed (FIX lines).  Idempotent: the array form is no longer reported."""
import collections
import glob
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from lpc_fix_void_return import code_mask  # noqa: E402

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SKIP = re.compile(r"/(u|w|wiz|wizard|wizards|players|backup|backups|old|bak|log|data|doc|docs|example|examples|test|tmp|attic)/|[-_.](bak|old|orphaned-driver-src)/|\.(bak|BAK|old|orig)(\.lpc)?$")
MSG = "Bad type for argument 2 of set_name ( string * vs string )"
LIT = re.compile(rb'"[A-Za-z0-9_ .\'-]*"')
IDX = re.compile(rb"[A-Za-z_]\w*\[[^\[\]]*\]")


def match_close(code, i):
    depth = 0
    for j in range(i, len(code)):
        c = code[j:j + 1]
        if c == b"(":
            depth += 1
        elif c == b")":
            depth -= 1
            if depth == 0:
                return j
    return -1


def top_commas(code, lo, hi):
    out, depth = [], 0
    for j in range(lo, hi):
        c = code[j:j + 1]
        if c in b"([{":
            depth += 1
        elif c in b")]}":
            depth -= 1
        elif c == b"," and depth == 0:
            out.append(j)
    return out


def plan(b, lines):
    mask = code_mask(b, heredoc=True)
    code = bytes(c if m else 32 for c, m in zip(b, mask))
    starts = [0] + [m.end() for m in re.finditer(rb"\n", b)]

    def line_of(pos):
        lo, hi = 0, len(starts)
        while lo + 1 < hi:
            mid = (lo + hi) // 2
            if starts[mid] <= pos:
                lo = mid
            else:
                hi = mid
        return lo + 1

    calls = []
    for m in re.finditer(rb"(?<![A-Za-z0-9_>.])set_name[ \t]*\(", code):
        o = m.end() - 1
        c = match_close(code, o)
        if c > 0:
            calls.append((m.start(), o, c))
    edits, skips, done = [], [], set()
    for ln in sorted(set(lines)):
        hit = [t for t in calls if line_of(t[1]) <= ln <= line_of(t[2])]
        if len(hit) != 1:
            skips.append((ln, "%d set_name calls cover the line" % len(hit)))
            continue
        s, o, c = hit[0]
        if (s, c) in done:
            continue
        done.add((s, c))
        commas = top_commas(code, o + 1, c)
        if len(commas) != 1:
            skips.append((ln, "%d arguments" % (len(commas) + 1)))
            continue
        a_lo, a_hi = commas[0] + 1, c
        arg = b[a_lo:a_hi]
        core = arg.strip()
        if not (LIT.fullmatch(core) or IDX.fullmatch(core)):
            skips.append((ln, "second argument is not a plain id: %s" % core[:40].decode("utf-8", "replace")))
            continue
        lead = arg[:len(arg) - len(arg.lstrip())]
        trail = arg[len(arg.rstrip()):]
        edits.append((a_lo, a_hi, lead + b"({ " + core + b" })" + trail, ln, core.decode("utf-8", "replace")))
    return edits, skips


def main():
    args = sys.argv[1:]
    apply = "--apply" in args
    diag = None
    if "--diag" in args:
        i = args.index("--diag")
        diag = args[i + 1]
        del args[i:i + 2]
    only = [a for a in args if not a.startswith("--")]
    if not diag:
        sys.exit(__doc__)
    nedit = nfile = nskip = 0
    libs = set()
    for f in sorted(glob.glob(os.path.join(diag, "diag-*.tsv"))):
        slug = os.path.basename(f)[5:-4]
        if only and slug not in only:
            continue
        if not os.path.isdir(f"{REPO}/libs/{slug}/work") or os.path.exists(f"{REPO}/libs/{slug}/work/.git") or slug == "longyunmeng_binary":
            continue
        rows = collections.defaultdict(list)
        for l in open(f, encoding="utf-8", errors="replace"):
            p = l.rstrip("\n").split("\t")
            if len(p) >= 5 and p[3] == "error" and p[4].startswith(MSG) and not SKIP.search(p[0]):
                rows[p[0]].append(int(p[1]))
        for path, lines in sorted(rows.items()):
            full = f"{REPO}/libs/{slug}/work{path}"
            try:
                b = open(full, "rb").read()
            except OSError:
                continue
            edits, skips = plan(b, lines)
            for ln, why in skips:
                nskip += 1
                print(f"SKIP  {slug} {path}:{ln}: {why}")
            if not edits:
                continue
            nfile += 1
            nedit += len(edits)
            libs.add(slug)
            for s, e, rep, ln, core in edits:
                print(f"FIX   {slug} {path}:{ln} set_name(..., {core}) -> ({{ {core} }})")
            if apply:
                out, last = [], 0
                for s, e, rep, ln, core in sorted(edits):
                    out.append(b[last:s])
                    out.append(rep)
                    last = e
                out.append(b[last:])
                open(full, "wb").write(b"".join(out))
    print(f"{nedit} call(s) in {nfile} file(s) of {len(libs)} lib(s), {nskip} left" + ("" if apply else " (plan only; --apply writes)"))


if __name__ == "__main__":
    main()
