#!/usr/bin/env python3
"""scripts/lpc_fix_void_return.py SLUG [--apply] [--diag TSV]

Fix the compile error "Type of returned value doesn't match function return type ( T vs void )": a function declared
`void` that returns a value; and "( T vs int )", an `int` function returning a string, object, array (`int
query_mysize() { return "tiny"; }`): it takes the type it returns, `mixed` if it also returns a non-zero int literal.  MudOS (and FluffOS with `old type behavior : 1`, which turns type checking off) compiled
it and handed the value to the caller, so an add_action handler `void do_open(string str) { ...; return 1; }` worked;
here the whole file fails to load.  Per function, from the diagnostics:

  - a driver apply whose value the driver ignores (create, init, reset, heart_beat, setup): each such `return X;`
    becomes `return;`, or `{ X; return; }` when X is a call (`return ::init();`) so its side effects stay;
  - anything else (add_action handlers, cmd_*() for the command daemon, helpers whose value a caller reads): the
    `void` in the definition, and in same-file prototypes, becomes T -- the value's type, `mixed` when the function
    returns several types.  That is what callers received before; the function's bare `return;` becomes `return 0;` (the value it gave).  A base class that declares the same function
    `void` then shows up as "Function F inherited from X does not match ... ( void vs int )"; for those, read the
    callers and run `scripts/lpc_fix_return_types.py --also F` (KB 04 section 6.10).

A function with no return type at all (`drop() {`, which this driver reads as void) gets T in front.\nListed for a hand edit: a function whose header cannot be found or has no single `void`, and one whose body holds\nanother function definition (a `}` missing above it: the `return` belongs to the nested function, and the fix is the brace).  Binary-safe (CRLF, GB bytes).
Diagnostics: $LPC_SCRATCH/lpcw-SLUG/diagnostics.tsv, $LPC_SCRATCH/rescan-1014/diag-SLUG.tsv, or --diag."""
import collections
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))


def code_mask(b):
    """1 for every byte that is code, 0 inside a string, char constant or comment.  Unlike the float fixer's mask, a
    double-quoted string may run over several lines (the driver accepts that: `"wilted<newline>flowers"`)."""
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
        if c == b'"' or (c == b"'" and (b[i + 2:i + 3] == b"'" or b[i + 1:i + 2] == b"\\")):
            j = i + 1
            while j < n and b[j:j + 1] != c and not (c == b"'" and b[j:j + 1] == b"\n"):
                j += 2 if b[j:j + 1] == b"\\" else 1
            i = j + 1
            continue
        m[i] = 1
        i += 1
    return m

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SCRATCH = os.environ.get("LPC_SCRATCH") or os.path.expanduser("~/.cache/lpc-scratch")
MSG = re.compile(r"Type of returned value doesn't match function return type \( (.+?) vs (void|int) \)")
IGNORED = {"create", "init", "reset", "heart_beat", "setup"}
NESTED = re.compile(rb"(?m)^[ \t]*(?:(?:static|nosave|private|protected|public|nomask|varargs)\s+)*"
                    rb"(?:void|int|string|object|mixed|mapping|float|status)\s+\*?\s*\w+\s*\([^;{}()]*\)\s*\{")
SIMPLE = re.compile(rb"\(?\s*(?:-?\s*[0-9.]+|[A-Za-z_]\w*|\"[^\"]*\")\s*\)?")


def depth_map(b, mask):
    """Brace depth before each byte (code only)."""
    d, out = 0, [0] * (len(b) + 1)
    for i in range(len(b)):
        out[i] = d
        if mask[i]:
            if b[i] == 0x7b:
                d += 1
            elif b[i] == 0x7d:
                d -= 1
    out[len(b)] = d
    return out


def enclosing_function(b, mask, dep, off):
    """(header_start, brace_offset) of the top-level function body holding off."""
    i = off
    while i >= 0 and not (mask[i] and b[i] == 0x7b and dep[i] == 0):
        i -= 1
    if i < 0 or dep[off] == 0:
        return None
    j = i - 1
    while j >= 0:
        if mask[j] and ((b[j] == 0x3b and dep[j] == 0) or (b[j] == 0x7d and dep[j + 1] == 0)):
            break
        if b[j] == 0x0a:
            # a preprocessor line ends the header too
            k = j + 1
            while k < i and b[k] in (0x20, 0x09):
                k += 1
            if k < i and b[k] == 0x23:
                e = b.find(b"\n", k)
                return (e + 1 if e >= 0 else k), i
        j -= 1
    return j + 1, i


def return_span(b, mask, semi):
    """(start, end) of `return ...;` ending at the code `;` at or after semi (on the same line)."""
    k = semi
    while k < len(b) and not (mask[k] and b[k] == 0x3b):
        if b[k] == 0x0a:
            return None
        k += 1
    j = k - 1
    depth = 0
    while j >= 0:
        if mask[j]:
            c = b[j]
            if c in b")]}":
                depth += 1
            elif c in b"([{":
                if depth == 0:
                    return None
                depth -= 1
            elif c == 0x3b and depth == 0:
                return None
            if depth == 0 and b[j:j + 6] == b"return" and (j == 0 or not (chr(b[j - 1]).isalnum() or b[j - 1] == 0x5f)) \
                    and not (chr(b[j + 6]).isalnum() or b[j + 6] == 0x5f):
                return j, k + 1
        j -= 1
    return None


def fix_file(b, rows, synlines=frozenset()):
    mask = code_mask(b)
    dep = depth_map(b, mask)
    starts = [0] + [m.end() for m in re.finditer(rb"\n", b)]
    funcs = collections.defaultdict(lambda: {"types": set(), "rets": [], "decl": set()})
    notes = []
    for row in rows:
        ln, col, t = row[:3]
        decl = row[3] if len(row) > 3 else "void"
        if ln > len(starts):
            continue
        off = starts[ln - 1] + max(col - 1, 0)
        ef = enclosing_function(b, mask, dep, min(off, len(b) - 1))
        if not ef:
            notes.append("HAND line %d: no enclosing function" % ln)
            continue
        f = funcs[ef]
        f["types"].add(t)
        f["decl"].add(decl)
        f["rets"].append(off)
    edits = []
    retype = {}
    for (hs, brace), f in funcs.items():
        header = bytes(c if mask[hs + k] else 0x20 for k, c in enumerate(b[hs:brace]))   # comments blanked
        m = re.search(rb"([A-Za-z_]\w*)\s*\([^;{}]*\)\s*$", header)
        if not m:
            notes.append("HAND %r: function header not found" % header.strip()[:60])
            continue
        name = m.group(1).decode()
        k = brace + 1
        while k < len(b) and not (mask[k] and b[k] == 0x7d and dep[k] == 1):
            k += 1
        body = bytes(c if mask[brace + 1 + x] else 0x20 for x, c in enumerate(b[brace + 1:k]))
        nested_lines = {b[:brace + 1 + x.start()].count(b"\n") + 1 + x.group(0)[:len(x.group(0)) - len(x.group(0).lstrip())].count(b"\n")
                        for x in NESTED.finditer(body)}
        if nested_lines & synlines:
            # a function definition inside the body, which the compiler read as a local declaration (`unexpected
            # '('`): a `}` is missing above, and the `return` belongs to the function that was meant to start here
            notes.append("HAND %s: a function definition inside its body (missing `}`?)" % name)
            continue
        if f["decl"] == {"int"}:
            # an `int` function returning another type (`int query_mysize() { return "tiny"; }`): the old driver
            # handed the string to the caller, so the function takes the type it returns; `mixed` when it also
            # returns a non-zero int literal or several types
            ints = [x for x in re.finditer(rb"\bint\b", header[:m.start()]) if mask[hs + x.start()]]
            if "unknown" in f["types"]:
                # the value's type is unknown because something earlier failed (a fragment compiled on its own, an
                # undefined helper): that says nothing about the function, leave it
                notes.append("HAND %s: declared int, returns a value of unknown type (an earlier error)" % name)
                continue
            if len(ints) != 1 or name in IGNORED:
                notes.append("HAND %s: declared int, returns %s" % (name, "/".join(sorted(f["types"]))))
                continue
            types = set(f["types"])
            t = types.pop() if len(types) == 1 else "mixed"
            if t == "unknown" or re.search(rb"\breturn\s*\(?\s*-?\s*[1-9][0-9]*\s*\)?\s*;", body):
                t = "mixed"
            v = ints[0]
            edits.append((hs + v.start(), hs + v.end(), t.encode()))
            retype[name] = t
            for r in re.finditer(rb"\breturn\s*;", b[brace:k]):
                if mask[brace + r.start()]:
                    edits.append((brace + r.start(), brace + r.end(), b"return 0;"))
            continue
        if f["decl"] != {"void"}:
            notes.append("HAND %s: mixed void/int declarations" % name)
            continue
        if name in IGNORED:
            for off in f["rets"]:
                sp = return_span(b, mask, off)
                if not sp:
                    notes.append("HAND %s: return statement not found" % name)
                    continue
                s, e = sp
                expr = b[s + 6:e - 1].strip()
                if not expr:
                    continue
                if SIMPLE.fullmatch(expr):
                    edits.append((s, e, b"return;"))
                else:
                    edits.append((s, e, b"{ " + expr + b"; return; }"))
            continue
        voids = [x for x in re.finditer(rb"\bvoid\b", header[:m.start()]) if mask[hs + x.start()]]
        types = f["types"]
        t = types.pop() if len(types) == 1 else "mixed"
        if t in ("unknown",):
            t = "mixed"
        if not voids and re.fullmatch(rb"\s*(?:(?:static|nosave|private|protected|public|nomask|varargs)\s+)*",
                                      header[:m.start()]):
            # no return type at all (`drop() {`): this driver takes it as void
            edits.append((hs + m.start(), hs + m.start(), t.encode() + b" "))
            retype[name] = t
            for r in re.finditer(rb"\breturn\s*;", b[brace:k]):
                if mask[brace + r.start()]:
                    edits.append((brace + r.start(), brace + r.end(), b"return 0;"))
            continue
        if len(voids) != 1:
            notes.append("HAND %s: %d `void` in the header" % (name, len(voids)))
            continue
        v = voids[0]
        edits.append((hs + v.start(), hs + v.end(), t.encode()))
        retype[name] = t
        # its bare `return;` statements would now warn (Non-void functions must return a value): they yielded 0
        for r in re.finditer(rb"\breturn\s*;", b[brace:k]):
            if mask[brace + r.start()]:
                edits.append((brace + r.start(), brace + r.end(), b"return 0;"))
    # same-file prototypes of the retyped functions
    for name, t in retype.items():
        for pm in re.finditer(rb"(?m)^([ \t]*(?:(?:static|nosave|private|protected|public|nomask|varargs)\s+)*)void(\s+\*?\s*"
                              + re.escape(name.encode()) + rb"\s*\([^;{}]*\)\s*;)", b):
            p = pm.start() + len(pm.group(1))
            if mask[p] and dep[p] == 0:
                edits.append((p, p + 4, t.encode()))
    out = b
    for s, e, new in sorted(set(edits), reverse=True):
        out = out[:s] + new + out[e:]
    return out, notes, retype


def main():
    args = sys.argv[1:]
    apply = "--apply" in args
    diag = args[args.index("--diag") + 1] if "--diag" in args else None
    slug = [a for a in args if not a.startswith("--") and a != diag][0]
    if not diag:
        diag = f"{SCRATCH}/lpcw-{slug}/diagnostics.tsv"
        if not os.path.isfile(diag):
            diag = f"{SCRATCH}/rescan-1014/diag-{slug}.tsv"
    work = f"{REPO}/libs/{slug}/work"
    rows = collections.defaultdict(set)
    syn = collections.defaultdict(set)
    for r in open(diag, encoding="utf-8", errors="replace"):
        r = r.rstrip("\n").split("\t")
        if len(r) < 5 or r[3] != "error":
            continue
        if r[4].startswith("syntax error, unexpected '('"):
            syn[r[0]].add(int(r[1]))
        m = MSG.match(r[4])
        if m:
            rows[r[0]].add((int(r[1]), int(r[2] or 0), m.group(1), m.group(2)))
    done = hand = 0
    for f in sorted(rows):
        p = work + f
        if not os.path.isfile(p):
            continue
        b = open(p, "rb").read()
        out, notes, retype = fix_file(b, sorted(rows[f]), frozenset(syn[f]))
        for n in notes:
            print(f"{n.split(' ')[0]}  {f}  {n.split(' ', 1)[1]}")
            hand += 1
        if out != b:
            done += 1
            print(f"FIX   {f}  " + (", ".join(f"{k}->{v}" for k, v in sorted(retype.items())) or "returns in applies"))
            if apply:
                open(p, "wb").write(out)
    print(f"{done} file(s) fixed, {hand} for a hand edit" + ("" if apply else " (plan only; --apply writes)"))


if __name__ == "__main__":
    main()
