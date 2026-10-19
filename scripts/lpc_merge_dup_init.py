#!/usr/bin/env python3
"""scripts/lpc_merge_dup_init.py --diag DIR [SLUG...] [--apply]

An NPC or room that defines `init()` twice (KB 04 section 6.6, KB 06 section 7.264).  The wandering vendor `maihuanu1.lpc` of the Journey-to-the-West
family greets the player and adds `buy` in its first `init()` and, further down, `void init() { ::init(); add_action("do_vendor_list", "list"); }`;
`wuhanzhan`'s `liangdian2` adds `work` in one and a `block_cmd` catch-all in the other.  Each author wanted both: the driver says
`Redeclaration of function 'init'.` and the object never compiles (scripts/lpc_fix_dup_functions.py only removes copies that are word for word equal).

--diag DIR  the scan output of scripts/lpc_warnings.py (DIR/diag-SLUG.tsv).  For every file with a `Redeclaration of function 'init'` error whose
            file holds exactly two definitions, the second of which is nothing but `::init();` and `add_action(...);` statements (comments aside),
            those `add_action` statements move to the end of the first `init()` and the second definition is deleted.  Anything else (a body with
            logic, three definitions, a definition that comes from an include) is listed as SKIP.  Wizard, backup and test dirs are left alone.
Binary-safe, line endings kept.  Without --apply the plan is printed (FIX lines); idempotent."""
import collections
import glob
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from lpc_fix_dup_functions import SKIP, VIRTUAL, definitions, match_close  # noqa: E402
from lpc_fix_void_return import code_mask  # noqa: E402

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
MSG = re.compile(r"Redeclaration of function 'init'")


def body_span(b, start, end):
    """-> (open brace index, close brace index) of the function text b[start:end]"""
    mask = code_mask(b, heredoc=True)
    code = bytes(c if m else 32 for c, m in zip(b, mask))
    po = code.find(b"(", start)
    pc = match_close(code, po, b"(", b")")
    ob = code.find(b"{", pc)
    return ob, end - 1, code


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
    nfix = nskip = 0
    for f in sorted(glob.glob(os.path.join(diag, "diag-*.tsv"))):
        slug = os.path.basename(f)[5:-4]
        if only and slug not in only or slug in VIRTUAL:
            continue
        if not os.path.isdir(f"{REPO}/libs/{slug}/work") or os.path.exists(f"{REPO}/libs/{slug}/work/.git"):
            continue
        if slug in ("wllz3", "longyunmeng_binary"):    # generated trees (rebuild.sh + patch)
            continue
        paths = set()
        for l in open(f, encoding="utf-8", errors="replace"):
            p = l.rstrip("\n").split("\t")
            if len(p) >= 5 and p[3] == "error" and not SKIP.search(p[0]) and MSG.match(p[4]):
                paths.add(p[0])
        for path in sorted(paths):
            full = f"{REPO}/libs/{slug}/work{path}"
            try:
                b = open(full, "rb").read()
            except OSError:
                continue
            defs = definitions(b, "init")
            if len(defs) != 2:
                nskip += 1
                print(f"SKIP  {slug} {path}: {len(defs)} init() definition(s) in the file")
                continue
            (s1, e1, _), (s2, e2, _) = defs
            ob2, cb2, code2 = body_span(b, s2, e2)
            inner = code2[ob2 + 1:cb2].decode("latin-1")
            stmts = [x.strip() for x in inner.split(";") if x.strip()]
            if not stmts or not all(x == "::init()" or re.match(r"add_action\s*\(", x) for x in stmts):
                nskip += 1
                print(f"SKIP  {slug} {path}: the second init() holds more than ::init() and add_action()")
                continue
            # the add_action statements as written (comments inside them are not expected); take them from the source text
            raw = b[ob2 + 1:cb2].decode("utf-8", "replace")
            adds = [m.group(0).strip() for m in re.finditer(r"add_action\s*\((?:[^;\"']|\"(?:\\.|[^\"\\])*\"|'(?:\\.|[^'\\])*')*\)\s*;", raw)]
            if len(adds) != sum(1 for x in stmts if x.startswith("add_action")):
                nskip += 1
                print(f"SKIP  {slug} {path}: could not read the add_action statements back")
                continue
            ob1, cb1, code1 = body_span(b, s1, e1)
            if re.search(rb"\breturn\b", code1[ob1:cb1]):
                nskip += 1
                print(f"SKIP  {slug} {path}: the first init() returns early")
                continue
            nfix += 1
            l2, l1 = b.count(b"\n", 0, s2) + 1, b.count(b"\n", 0, s1) + 1
            print(f"FIX   {slug} {path}: init() at line {l2} merged into the one at line {l1} ({len(adds)} add_action)")
            if apply:
                nl = b"\r\n" if b"\r\n" in b else b"\n"
                head = b[:cb1].rstrip(b" \t\r\n")                 # the first init() up to its last statement
                ls = head.rfind(b"\n") + 1
                indent = re.match(rb"[ \t]*", head[ls:]).group(0)
                ins = b"".join(nl + indent + x.encode("utf-8") for x in adds)
                cs = b.rfind(b"\n", 0, s2) + 1                      # the second definition from the start of its line ...
                while True:                                         # ... and the blank lines above it
                    m = re.search(rb"(\r?\n)[ \t]*(\r?\n)\Z", b[:cs])
                    if not m:
                        break
                    cs = m.start(2)
                le = b.find(b"\n", e2)
                ce = len(b) if le < 0 else le + 1                   # ... to the end of the line of its closing brace
                out = b[:len(head)] + ins + b[len(head):cs] + b[ce:]
                open(full, "wb").write(out)
    print(f"{nfix} merge(s), {nskip} left" + ("" if apply else " (plan only; --apply writes)"))


if __name__ == "__main__":
    main()
