#!/usr/bin/env python3
"""scripts/lpc_fix_cmp_chain.py [--apply] [SLUG...]

A chain of comparisons of one value that can never differ from always-true / always-false:

  `if (arg != "wan" || arg != "丸") return notify_fail("你要吃什么？\\n");`        always true: the pill can never be eaten
  `if (dir == "south" && dir == "north") return notify_fail("...");`                 always false: the inn never stops anybody
  `if (family != "明教" || family != "武当派") && dir == "westup")`                    always true: the mountain gate shuts for everyone

An author who wanted "neither of these" wrote `!= a || != b` (the negation of `== a || == b`, De Morgan slipped), one who wanted "either of these" wrote
`== a && == b`.  Both compile everywhere and no driver warns about them.  KB 06 section 7.282.

  `!=` joined by `||` -> `&&`, only when the statement the condition guards is a `return` (a refusal `return notify_fail(...)` / `return 0;`, or a guard clause `return ::valid_leave(me, dir);`), or a block that starts with one, has a `return notify_fail(` in it or ends in `return 0;` / `return;` (`{ command("shake"); return 0; }`): then "neither of
                         these" is what the text under the test says.  A condition whose body does something instead (`if (arg != "mud" || arg != "泥") { dig(); }`) could as well
                         have meant `==` and `||`: listed, not touched.
  `==` joined by `&&` -> `||`, whatever the body: a value that equals two different literals at once cannot be what anyone meant.

The chain is wrapped in parentheses (`(a != x && a != y)`) unless it already is the whole of a parenthesized group, so the operators around it keep their grouping.  The
compared value is one left side repeated: a name, an index or a `->query("x")` chain (as in scripts/lpc_fix_literal_or.py).  Only code is touched; wizard, backup and test directories
are skipped; submodule work trees and the generated trees are not read.  Binary-safe, idempotent.

Without --apply the plan is printed (`FIX<TAB>slug<TAB>/path<TAB>n`, `LIST<TAB>slug<TAB>/path:line<TAB>text`) with the totals on stderr."""
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from lpc_fix_void_return import code_mask  # noqa: E402
import lpc_fix_literal_or as L  # noqa: E402

REPO = L.REPO
STR = L.STR
NE_OR = re.compile(rb'(?P<lhs>' + L.LHS + rb')\s*!=\s*' + STR + rb'(?:\s*\|\|\s*(?P=lhs)\s*!=\s*' + STR + rb')+')
EQ_AND = re.compile(rb'(?P<lhs>' + L.LHS + rb')\s*==\s*' + STR + rb'(?:\s*&&\s*(?P=lhs)\s*==\s*' + STR + rb')+')


def next_code(b, mask, i, step):
    """index of the next code byte that is not white space, moving by step; -1 / len when none"""
    while 0 <= i < len(b) and (not mask[i] or b[i] in b" \t\r\n"):
        i += step
    return i


def last_statement_refuses(b, mask, k, j):
    """True when the last top-level statement of the block b[k]=='{' .. b[j]=='}' is `return 0;`, `return -1;`, `return;` or `return notify_fail(...)`: the block ends the function
    with a refusal whatever it did first (`command("shake"); return 0;`)"""
    depth = 0
    start = k + 1
    last = None
    i = k
    while i <= j:
        if mask[i]:
            c = b[i]
            if c in b"([{":
                depth += 1
            elif c in b")]}":
                depth -= 1
                if depth == 1 and c == 0x7d:        # a nested block closed: the next statement starts behind it
                    start = i + 1
            elif c == 0x3b and depth == 1:          # `;` at block level ends a statement
                last = start
                start = i + 1
        i += 1
    if last is None:
        return False
    s = next_code(b, mask, last, 1)
    return bool(re.match(rb"return\s*(?:;|0\s*;|-\s*1\s*;|notify_fail\s*\()", b[s:s + 40]))


def body_kind(b, mask, m_end):
    """'return' when the statement guarded by the condition that contains the chain at m_end starts with `return` (directly or in its block), 'other' otherwise, None when
    the chain is not inside an if / while condition"""
    # climb out of the parentheses that enclose the chain until one belongs to `if` / `while`
    depth = 0
    i = m_end
    close = None
    while i < len(b):
        if mask[i]:
            c = b[i]
            if c in b"([{":
                depth += 1
            elif c in b")]}":
                if depth == 0:
                    if c != 0x29:                       # `)`
                        return None
                    # this `)` closes some paren group: find its `(` and see what precedes it
                    close = i
                    j, d = i - 1, 0
                    while j >= 0:
                        if mask[j]:
                            if b[j] in b")]}":
                                d += 1
                            elif b[j] in b"([{":
                                if d == 0:
                                    break
                                d -= 1
                        j -= 1
                    if j < 0 or b[j] != 0x28:
                        return None
                    k = next_code(b, mask, j - 1, -1)
                    word = re.search(rb"[A-Za-z_]\w*$", b[max(0, k - 12):k + 1])
                    if word and word.group(0) in (b"if", b"while"):
                        break
                    # a sub-expression group: keep climbing from just after this `)`
                    depth = 0
                    i += 1
                    continue
                depth -= 1
            elif c in b";" and depth == 0:
                return None
        i += 1
    if close is None or i >= len(b):
        return None
    k = next_code(b, mask, close + 1, 1)
    if k >= len(b):
        return None
    refusal = re.compile(rb"return\b")         # a guard clause: the test selects the exit, whatever it returns
    if b[k:k + 1] == b"{":
        # a block: a refusal when a `return notify_fail(` is in it (the block may do some work first: `inv = all_inventory(me); for (...) ... return notify_fail(...)`)
        d, j = 0, k
        while j < len(b):
            if mask[j]:
                if b[j] == 0x7b:
                    d += 1
                elif b[j] == 0x7d:
                    d -= 1
                    if d == 0:
                        break
            j += 1
        text = bytes(c if mask[k + x] else 0x20 for x, c in enumerate(b[k:j]))
        return "return" if re.search(rb"\breturn\s*notify_fail\s*\(", text) or refusal.match(b, next_code(b, mask, k + 1, 1)) or last_statement_refuses(b, mask, k, j) else "other"
    return "return" if refusal.match(b, k) else "other"


def connectives(b, mask, start, end, op):
    return [i for i in range(start, end - 1) if mask[i] and b[i:i + 2] == op]


def fix(b):
    found = []
    for name, pat in (("ne_or", NE_OR), ("eq_and", EQ_AND)):
        for m in pat.finditer(b):
            found.append((name, m))
    if not found:
        return None, 0, []
    mask = code_mask(b)
    edits = []
    listed = []
    for name, m in sorted(found, key=lambda x: x[1].start()):
        if not mask[m.start()]:
            continue
        s, e = m.start(), m.end()
        pre = next_code(b, mask, s - 1, -1)
        post = next_code(b, mask, e, 1)
        whole_group = pre >= 0 and b[pre:pre + 1] == b"(" and post < len(b) and b[post:post + 1] == b")"
        if whole_group:
            k = next_code(b, mask, pre - 1, -1)
            if k >= 0 and b[k:k + 1] == b"!":
                listed.append((b.count(b"\n", 0, s) + 1, "negated group"))
                continue
        if name == "ne_or":
            kind = body_kind(b, mask, e)
            if kind != "return":
                listed.append((b.count(b"\n", 0, s) + 1, re.sub(rb"\s+", b" ", b[s:e]).decode("utf-8", "replace")[:90] + ("  [body: %s]" % (kind or "not in an if"))))
                continue
            old, new = b"||", b"&&"
        else:
            old, new = b"&&", b"||"
        for i in connectives(b, mask, s, e, old):
            edits.append((i, i + 2, new))
        if not whole_group:
            edits.append((s, s, b"("))
            edits.append((e, e, b")"))
    if not edits:
        return None, 0, listed
    out = bytearray(b)
    # insertions at one offset: `)` of an earlier chain and `(` of a later one never share an offset; apply from the end
    for s, e, rep in sorted(edits, key=lambda x: (x[0], x[1]), reverse=True):
        out[s:e] = rep
    n = sum(1 for x in edits if x[2] in (b"&&", b"||"))
    return bytes(out), n, listed


def main():
    a = sys.argv[1:]
    apply_ = "--apply" in a
    slugs = {x for x in a if not x.startswith("--")}
    total = files = lst = 0
    for slug, paths in sorted(L.tracked(slugs).items()):
        for p in paths:
            rel = "/" + p.split("/work/", 1)[1]
            if L.SKIP.search(rel):
                continue
            try:
                b = open(os.path.join(REPO, p), "rb").read()
            except OSError:
                continue
            if (b"||" not in b and b"&&" not in b) or (b"==" not in b and b"!=" not in b):
                continue
            new, n, listed = fix(b)
            for ln, text in listed:
                print(f"LIST\t{slug}\t{rel}:{ln}\t{text}")
                lst += 1
            if not n:
                continue
            print(f"FIX\t{slug}\t{rel}\t{n}")
            total += n
            files += 1
            if apply_:
                with open(os.path.join(REPO, p), "wb") as fh:
                    fh.write(new)
    print(f"{total} connective(s) in {files} file(s) {'fixed' if apply_ else 'fixable'}, {lst} listed", file=sys.stderr)


if __name__ == "__main__":
    main()
