#!/usr/bin/env python3
"""scripts/lpc_fix_literal_or.py [--apply] [SLUG...]

`if (arg == "yuyou" || "yu you" || "you")`, `if (str == "rune" || "on rune")`, `if (mrace == "elf"||"nymph"||"dryad")`,
`if (str != "a" && "b")`: the second and later operands are bare string literals.  A non-empty string is true, so the `||` chain is true
whatever `arg` is (every `eat X` eats the item, every `look X` finds the rune, every race is an elf) and the `&&` chain of `!=` tests is just its
first test.  Written that way by authors in every lineage (bxsj, nt6, sunshadow, ...), compiles everywhere, no warning.  What was meant is
the variable compared with each literal: `arg == "yuyou" || arg == "yu you" || arg == "you"`, `str != "a" && str != "b"`.

The left side repeated is the operand in front of the nearest `==` / `!=` of the chain: a local or global name, optionally indexed, or a
`->query("x")`-style call chain whose arguments are a string, a name or a number (`me->query("class")`, `arg`, `msgs[i]`, `ob->query_temp("x")`).  Anything
else (a call with an expression argument, an arithmetic left side) is listed, not touched.  Only code is touched (comments, strings and
character constants are masked) and only a literal that ends its operand (followed by `)`, `||`, `&&`, `{`, `;`, `,`, `?`, `:` or the end of the
line), so `x == "a" || "b" == y` stays.  Wizard, backup and test directories are skipped like the other mechanical fixers do; submodule work
trees and the generated trees are not read.  Binary-safe.  Idempotent: after the fix the chain has `V == ` in front of every literal.

Without --apply the plan is printed (`FIX<TAB>slug<TAB>/path<TAB>n` and `LIST<TAB>slug<TAB>/path:line<TAB>text`) with the totals on stderr."""
import os
import re
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from lpc_fix_void_return import code_mask  # noqa: E402

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SKIP = re.compile(r"/(u|w|wiz|wizard|wizards|open|players|backup|backups|old|bak|log|data|doc|docs|example|examples|test|tests|tmp|attic)/|[-_.](bak|old)/|\.(bak|BAK|old|orig)(\.lpc)?$")
GENERATED = {"wllz3", "longyunmeng_binary"}
STR = rb'"(?:[^"\\\n]|\\.)*"'
ARG = rb'(?:\s*(?:"[^"\n]*"|[A-Za-z_]\w*|\d+)\s*)?'
LHS = rb'(?<![\w>.\]"])[A-Za-z_]\w*(?:\[[^\]\n]*\])?(?:->[A-Za-z_]\w*\(' + ARG + rb'\))*'
# `LHS == "a"` or `LHS != "a"` followed by `|| "b"` / `&& "b"` chains of bare literals
HEAD = re.compile(rb'(?P<lhs>' + LHS + rb')(?P<ws1>\s*)(?P<op>==|!=)(?P<ws2>\s*)' + STR)
BARE = re.compile(rb'(?P<pre>\s*(?P<conj>\|\||&&)\s*)(?P<lit>' + STR + rb')(?=\s*(?:[)|&{;,?:]|$))')


def tracked(slugs):
    out = subprocess.run(["git", "ls-files", "-s", "-z", "--", "libs"], cwd=REPO, capture_output=True).stdout.split(b"\0")
    gitlinks = set()
    by = {}
    for ent in out:
        if not ent:
            continue
        meta, _, path = ent.partition(b"\t")
        try:
            p = path.decode("utf-8")
        except UnicodeDecodeError:
            continue
        parts = p.split("/")
        if len(parts) < 3 or parts[0] != "libs":
            continue
        slug = parts[1]
        if meta.split()[0] == b"160000":
            gitlinks.add(slug)
            continue
        if len(parts) > 3 and parts[2] == "work" and p.endswith((".lpc", ".h")):
            by.setdefault(slug, []).append(p)
    return {s: f for s, f in by.items() if s not in gitlinks and s not in GENERATED and (not slugs or s in slugs)}


def fix(b):
    """(new bytes or None, edits, listed lines)"""
    cand = False
    for m in HEAD.finditer(b):
        if BARE.match(b, m.end()):
            cand = True
            break
    if not cand:
        return None, 0, []
    mask = code_mask(b)               # the byte loop only for the few files with a candidate
    edits = []
    listed = []
    pos = 0
    while True:
        m = HEAD.search(b, pos)
        if not m:
            break
        if not mask[m.start("op")]:
            pos = m.end()
            continue
        op, lhs = m.group("op"), m.group("lhs")
        want = b"||" if op == b"==" else b"&&"
        cur = m.end()
        n = 0
        while True:
            c = BARE.match(b, cur)
            if not c or c.group("conj") != want or not mask[c.start("conj")]:
                break
            edits.append((c.start("lit"), lhs + b" " + op + b" "))   # insert `LHS op ` in front of the literal
            cur = c.end()
            n += 1
        if not n:
            # a chain that starts with the wrong conjunction (`x == "a" && "b"`): leave it, but say so
            c = BARE.match(b, m.end())
            if c and mask[c.start("conj")] and c.group("conj") != want:
                ln = b.count(b"\n", 0, m.start()) + 1
                listed.append((ln, b[m.start():c.end()].decode("utf-8", "replace")))
        pos = max(cur, m.end())
    if not edits:
        return None, 0, listed
    out = bytearray(b)
    for at, ins in sorted(edits, reverse=True):
        out[at:at] = ins
    return bytes(out), len(edits), listed


def main():
    a = sys.argv[1:]
    apply_ = "--apply" in a
    slugs = {x for x in a if not x.startswith("--")}
    total = files = lst = 0
    for slug, paths in sorted(tracked(slugs).items()):
        for p in paths:
            rel = "/" + p.split("/work/", 1)[1]
            if SKIP.search(rel):
                continue
            try:
                b = open(os.path.join(REPO, p), "rb").read()
            except OSError:
                continue
            if (b"||" not in b and b"&&" not in b) or (b"==" not in b and b"!=" not in b):
                continue
            new, n, listed = fix(b)
            for ln, text in listed:
                print(f"LIST\t{slug}\t{rel}:{ln}\t{text[:100]}")
                lst += 1
            if not n:
                continue
            print(f"FIX\t{slug}\t{rel}\t{n}")
            total += n
            files += 1
            if apply_:
                with open(os.path.join(REPO, p), "wb") as fh:
                    fh.write(new)
    print(f"{total} literal(s) in {files} file(s) {'fixed' if apply_ else 'fixable'}, {lst} listed", file=sys.stderr)


if __name__ == "__main__":
    main()
