#!/usr/bin/env python3
"""scripts/lpc_fix_float_trunc.py SLUG [--apply] [--diag TSV]

Fix the driver's "Float value truncated to int" warning (FluffOS #1426, KB 04 section 6.10) at its source.  The driver
converts the right-hand side to the destination's type first (#1303), so the four sites the warning names do different
things:

    x *= 0.85;      x op= <float>: the 0.85 becomes 0 BEFORE the multiply -- x is zeroed (+=, -= drop the fraction of
                    the step, /= by a fraction divides by zero).  Never what the author meant: rewritten
                    x = to_int(x * 0.85);   (only when x has no side effects: no call, ++ or --)
    x = <float>;    the fraction of the final value is dropped, which is what the code means (a level from pow(), a
    int x = <float>;  scaled reward): rewritten x = to_int(<float>); -- same value, now explicit.
    return <float>; (int function) likewise return to_int(<float>);

Diagnostics come from scripts/lpc_warnings.py ($LPC_SCRATCH/lpcw-SLUG/diagnostics.tsv, or --diag).  The diagnostic's
column is the statement's closing `;`; the statement starts after the previous `;`, `{` or `}` outside strings and
comments.  A bare float literal on the right (`Wimpy = 0.20;`, `return 0.5;`) is listed, never wrapped: to_int() would keep
the 0.  A statement that is none of the three shapes above (a declaration with several declarators, a chained
assignment, a `for` header, a macro) is listed for a hand edit, never guessed.  Files are read and written in binary,
so CRLF and GB bytes survive.  Without --apply it prints the plan."""
import collections
import os
import re
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SCRATCH = os.environ.get("LPC_SCRATCH") or os.path.expanduser("~/.cache/lpc-scratch")
MSG = "Float value truncated to int"
TYPES = rb"(?:int|float|string|object|mixed|mapping|function|buffer|status)"
MODS = rb"(?:static|nosave|private|protected|public|nomask|varargs|register)"


def code_mask(b):
    """1 for every byte that is code, 0 inside a string, char constant or comment."""
    m = bytearray(len(b))
    i, n = 0, len(b)
    while i < n:
        c = b[i:i + 1]
        if b[i:i + 2] == b"//":
            j = b.find(b"\n", i)
            i = n if j < 0 else j
            continue
        if b[i:i + 2] == b"/*":
            j = b.find(b"*/", i + 2)
            i = n if j < 0 else j + 2
            continue
        if c in (b'"', b"'"):
            j = i + 1
            while j < n and b[j:j + 1] != c and b[j:j + 1] != b"\n":
                j += 2 if b[j:j + 1] == b"\\" else 1
            i = j + 1
            continue
        m[i] = 1
        i += 1
    return m


def top_level(s, mask_s):
    """Yield (index, char) of code bytes of s at paren/bracket depth 0."""
    d = 0
    for i, ch in enumerate(s):
        if not mask_s[i]:
            continue
        if ch in b"([{":
            d += 1
        elif ch in b")]}":
            d -= 1
        elif d == 0:
            yield i, ch


def plan_one(b, mask, off):
    """off = index of the statement's `;`.  Returns (start, end, new_text) or a reason string."""
    if b[off:off + 1] != b";":
        # some sites point into the expression: the statement still ends at the next code `;`
        k = off
        while k < len(b) and not (mask[k] and b[k:k + 1] in (b";", b"{", b"}")):
            k += 1
        if b[k:k + 1] != b";":
            return "no ';' after the column"
        off = k
    j = off - 1
    while j >= 0 and not (mask[j] and b[j:j + 1] in (b";", b"{", b"}")):
        j -= 1
    start = j + 1
    stmt = b[start:off]
    ms = mask[start:off]
    lead = 0   # skip whitespace and comments (non-code bytes) in front of the statement
    while lead < len(stmt) and (not ms[lead] or stmt[lead:lead + 1] in (b" ", b"\t", b"\r", b"\n")):
        lead += 1
    body, mb = stmt[lead:], ms[lead:]
    body = body.rstrip()
    mb = mb[:len(body)]
    if not body:
        return "empty statement"
    if b"\n#" in body:
        return "preprocessor directive inside the statement"
    # `else x = ...;`, `if (c) x = ...;`, `} else if (c) x op= ...;`: skip the prefix to the statement itself
    while True:
        m = re.match(rb"(?:case\b[^:;]*|default\s*):(?!:)\s*", body)   # `case 26..35: exp -= exp / 7.32;`
        if m:
            lead += m.end(); body = body[m.end():]; mb = mb[m.end():]
            continue
        m = re.match(rb"else\b\s*", body)
        if m:
            lead += m.end(); body = body[m.end():]; mb = mb[m.end():]
            continue
        m = re.match(rb"(?:if|while)\s*\(", body)
        if not m:
            break
        d, k = 0, m.end() - 1
        while k < len(body):
            if mb[k] and body[k:k + 1] == b"(":
                d += 1
            elif mb[k] and body[k:k + 1] == b")":
                d -= 1
                if d == 0:
                    break
            k += 1
        if d:
            return "unbalanced condition"
        k += 1
        while k < len(body) and body[k:k + 1] in (b" ", b"\t", b"\r", b"\n"):
            k += 1
        lead += k; body = body[k:]; mb = mb[k:]
    if re.match(rb"(?:for|switch|do|case|default)\b", body):
        return "control statement"
    m = re.match(rb"return\b\s*", body)
    if m:
        e = body[m.end():]
        if not e:
            return "bare return"
        if re.fullmatch(rb"\(?\s*-?\s*[0-9]*\.[0-9]*(?:[eE][-+]?[0-9]+)?\s*\)?", e):
            return "an int function returns a float literal: decide the return type by hand"
        return start + lead + m.end(), start + lead + len(body), b"to_int(" + e + b")"
    ops = []
    toks = list(top_level(body, mb))
    for k, (i, ch) in enumerate(toks):
        if ch == ord("="):
            prev = body[i - 1:i]
            nxt = body[i + 1:i + 2]
            if nxt == b"=" or prev in (b"=", b"!", b"<", b">"):
                continue
            if prev in (b"*", b"/", b"+", b"-", b"%") and mb[i - 1]:
                ops.append((i - 1, prev.decode()))
            else:
                ops.append((i, "="))
        elif ch == ord(","):
            return "comma at the top level (several declarators?)"
    if len(ops) != 1:
        return "%d assignment operators" % len(ops)
    i, op = ops[0]
    lhs = body[:i].rstrip()
    rhs = body[i + (1 if op == "=" else 2):].strip()
    if not rhs:
        return "no right-hand side"
    rs = start + lead + i + (1 if op == "=" else 2)
    while b[rs:rs + 1] in (b" ", b"\t"):
        rs += 1
    re_ = start + lead + len(body)
    if op == "=" and re.fullmatch(rb"\(?\s*-?\s*[0-9]*\.[0-9]*(?:[eE][-+]?[0-9]+)?\s*\)?", rhs):
        # `Wimpy = 0.20;` into an int: to_int() would write the bug down (the value is 0); the variable or the
        # constant is wrong -- read the uses (Dead Souls combat.lpc: a percentage, so 20)
        return "a float literal stored into an int: decide the type or the value by hand"
    if op == "=":
        return rs, re_, b"to_int(" + rhs + b")"
    # x op= e  ->  x = to_int(x op e); the variable alone, possibly indexed by a side-effect-free subscript
    decl = re.match(rb"(?:" + MODS + rb"\s+)*" + TYPES + rb"\b", lhs)
    if decl:
        return "op= in a declaration"
    if b"(" in lhs or b"++" in lhs or b"--" in lhs:
        return "left-hand side may have side effects: " + lhs.decode("utf-8", "replace")
    ls = start + lead
    return ls, re_, lhs + b" = to_int(" + lhs + b" " + op.encode() + b" (" + rhs + b"))"


def main():
    args = sys.argv[1:]
    apply = "--apply" in args
    diag = None
    if "--diag" in args:
        diag = args[args.index("--diag") + 1]
    slug = [a for a in args if not a.startswith("--") and a != diag][0]
    diag = diag or f"{SCRATCH}/lpcw-{slug}/diagnostics.tsv"
    work = f"{REPO}/libs/{slug}/work"
    sites = collections.defaultdict(set)
    errfiles = set()
    for line in open(diag, encoding="utf-8", errors="replace"):
        r = line.rstrip("\n").split("\t")
        if len(r) < 5:
            continue
        if r[3] == "error":
            errfiles.add(r[0])
        elif r[3] == "warning" and r[4].startswith(MSG):
            sites[r[0]].add((int(r[1]), int(r[2] or 0)))
    fixed = hand = 0
    for f in sorted(sites):
        p = work + f
        if f in errfiles or not os.path.isfile(p):
            continue
        b = open(p, "rb").read()
        mask = code_mask(b)
        starts = [0] + [m.end() for m in re.finditer(rb"\n", b)]
        edits = []
        for ln, col in sorted(sites[f]):
            if ln > len(starts):
                print(f"HAND  {f}:{ln}  line past end of file")
                hand += 1
                continue
            off = starts[ln - 1] + col - 1
            res = plan_one(b, mask, off)
            if isinstance(res, str):
                print(f"HAND  {f}:{ln}  {res}")
                hand += 1
                continue
            edits.append(res)
        for s, e, new in sorted(set(edits), reverse=True):
            old = b[s:e]
            print(f"FIX   {f}  {old.decode('utf-8', 'replace').strip()[:90]}  ->  {new.decode('utf-8', 'replace').strip()[:110]}")
            b = b[:s] + new + b[e:]
            fixed += 1
        if apply and edits:
            open(p, "wb").write(b)
    print(f"{fixed} fixed, {hand} for a hand edit" + ("" if apply else " (plan only; --apply writes)"))


if __name__ == "__main__":
    main()
