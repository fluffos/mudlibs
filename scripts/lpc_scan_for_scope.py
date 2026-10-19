#!/usr/bin/env python3
"""scripts/lpc_scan_for_scope.py [SLUG...]

A variable declared in a `for` header and read after the loop (KB 04 section 6.12).  FluffOS scopes `for (int i = 0; ...)` to the
loop, so the pawn-shop idiom

    for (int i = 0; i < sizeof(inv); i++)
      if (inv[i]->id(arg) && !(index--)) break;
    if (i == sizeof(inv)) return notify_fail(...);

is `Undefined variable 'i'` on the line after the loop and the whole object (a room, an NPC) never loads.  Prints `HIT path line var`
for each header variable that the rest of its function still names, unless an outer declaration, a later declaration or a later
`for` header with the same name explains the use.  Report only.  Known false positives: LDMud lambda quotes (`'i`), and a loop
body split by `#if / #else` (the other branch names the variable inside the loop).  The fix is `int i;` at the head of the
function and `for (i = 0; ...)`.  Wizard and backup dirs, gitlink libs and longyunmeng_binary are skipped; with no SLUG every lib."""
import bisect
import os
import re
import subprocess
import sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from lpc_fix_void_return import code_mask  # noqa: E402

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SKIP = re.compile(r"/(u|w|wiz|wizard|wizards|open|players|backup|backups|old|bak|log|data|doc|example|examples)/|[-_.](bak|old)/")
FOR = re.compile(rb"\bfor\s*\(\s*(?:int|string|object|mixed|float|mapping|object\s*\*|int\s*\*|string\s*\*)\s+\*?(\w+)\s*=")
TYPES = rb"(?:int|string|object|mixed|float|mapping|status|buffer|function|class\s+\w+)"
def match_close(code, i, o, c):
    d = 0
    while i < len(code):
        ch = code[i]
        if ch == o: d += 1
        elif ch == c:
            d -= 1
            if d == 0: return i
        i += 1
    return -1
def stmt_end(code, i):
    n = len(code)
    while i < n and code[i] in b" \t\r\n": i += 1
    if i >= n: return n
    if code[i] == 0x7B:
        j = match_close(code, i, 0x7B, 0x7D); return j + 1 if j > 0 else n
    m = re.match(rb"(if|for|while|foreach|switch)\b", code[i:i+10])
    if m:
        k = code.find(b"(", i)
        k2 = match_close(code, k, 0x28, 0x29)
        e = stmt_end(code, k2 + 1)
        if m.group(1) == b"if":
            m2 = re.compile(rb"\s*else\b").match(code, e)
            if m2: e = stmt_end(code, e + m2.end())
        return e
    j = code.find(b";", i)
    return j + 1 if j >= 0 else n
def top_blocks(code):
    res = []; depth = 0; start = 0
    for m in re.finditer(rb"[{}]", code):
        if m.group() == b"{":
            if depth == 0: start = m.start()
            depth += 1
        else:
            depth -= 1
            if depth == 0: res.append((start, m.start()))
            elif depth < 0: depth = 0
    return res
def func_bounds(blocks, starts, pos):
    k = bisect.bisect_right(starts, pos) - 1
    if k < 0: return 0, -1
    s, e = blocks[k]
    return (s, e) if s <= pos <= e else (0, -1)

def main():
    slugs = set(a for a in sys.argv[1:] if not a.startswith("--"))
    files = subprocess.run(["git", "ls-files", "-z", "--", "libs"], cwd=REPO, capture_output=True).stdout.split(b"\0")
    hits = 0
    for f in files:
        try:
            p = f.decode()
        except UnicodeDecodeError:
            continue
        if not p.endswith((".lpc", ".h")) or "libs/longyunmeng_binary/" in p:
            continue
        parts = p.split("/work/", 1)
        if len(parts) < 2 or SKIP.search("/" + parts[1]) or (slugs and p.split("/")[1] not in slugs):
            continue
        try:
            b = open(os.path.join(REPO, p), "rb").read()
        except OSError:
            continue
        if not re.search(rb"\bfor\s*\(\s*(?:int|string|object|mixed|float|mapping)\s+\*?\w+\s*=", b):
            continue
        mask = code_mask(b, heredoc=True)
        code = bytes(c if mask[i] else 32 for i, c in enumerate(b))
        blocks = top_blocks(code)
        starts = [x[0] for x in blocks]
        for m in FOR.finditer(code):
            name = m.group(1)
            fs, fe = func_bounds(blocks, starts, m.start())
            if fe < 0:
                continue
            hdr_close = match_close(code, code.find(b"(", m.start()), 0x28, 0x29)
            e = stmt_end(code, hdr_close + 1)
            rest = bytearray(code[e:fe])
            for m2 in FOR.finditer(code, e, fe):
                if m2.group(1) != name:
                    continue
                hc = match_close(code, code.find(b"(", m2.start()), 0x28, 0x29)
                e2 = stmt_end(code, hc + 1)
                for q in range(m2.start() - e, min(e2, fe) - e):
                    rest[q] = 32
            rest = bytes(rest)
            first = re.search(rb"(?<![A-Za-z0-9_'])" + name + rb"\b", rest)
            if not first:
                continue
            if re.search(rb"(?m)^[ \t]*#[ \t]*(else|elif)\b", rest[:first.start()]):
                continue
            decl = TYPES + rb"[ \t*]+(?:[^;(){}]*,\s*)?\*?" + name + rb"\b"
            if re.search(decl, code[fs:m.start()]):
                continue
            d = re.search(decl, rest)
            if d and d.start() <= first.start():
                continue
            print(f"HIT {p} {b.count(chr(10).encode(), 0, m.start()) + 1} {name.decode()}")
            hits += 1
    print(hits, "hit(s)")


if __name__ == "__main__":
    main()
