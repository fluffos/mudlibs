#!/usr/bin/env python3
"""scripts/lpc_fix_inherit_order.py SLUG [--apply] [--diag TSV]

Fix "Illegal to inherit after defining global variables" (KB 04 section 6.3).  FluffOS takes every `inherit` before the
first global variable; the MudOS builds these libs ran on did not care, so a file that reads

    #include <m_spells.h>      // declares mapping ABJURATION = ([ ... ]);
    int found;
    inherit ROOM;

never loads here.  The offenders -- top-level variable declarations, and `#include` lines of headers that declare a
global (followed through nested includes), that sit before the last top-level `inherit` -- are moved, whole lines and in
their order, to just after the line holding that last `inherit`.  Moving them down keeps every macro they use defined
before them, and the inherited program's variables come first as the driver wants.

Only files the diagnostics (scripts/lpc_warnings.py, $LPC_SCRATCH/lpcw-SLUG/diagnostics.tsv or --diag; or
$LPC_SCRATCH/rescan-1014/diag-SLUG.tsv) list with this error are touched.  Listed for a hand edit, never guessed: an
offender or the last inherit inside `#if`/`#ifdef`, an offender sharing a line with other code, a file where none is
found.  Binary read/write keeps CRLF and GB bytes.  Without --apply only the plan is printed."""
import collections
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from lpc_fix_float_trunc import code_mask  # noqa: E402

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SCRATCH = os.environ.get("LPC_SCRATCH") or os.path.expanduser("~/.cache/lpc-scratch")
MSG = "Illegal to inherit after defining global variables"
DECL_HEAD = re.compile(rb"(?:(?:static|nosave|private|protected|public|nomask|varargs|register)\s+)*"
                       rb"(?:int|float|string|object|mixed|mapping|function|buffer|status|class\s+\w+)\b")


def pp_lines(b, mask):
    """Byte ranges (start, end) of preprocessor lines (with backslash continuations)."""
    out, i, n = [], 0, len(b)
    while i < n:
        j = b.find(b"\n", i)
        j = n if j < 0 else j + 1
        k = i
        while k < j and b[k:k + 1] in (b" ", b"\t"):
            k += 1
        if k < j and b[k:k + 1] == b"#" and mask[k]:
            e = j
            while e < n and (b[e - 2:e] == b"\\\n" or b[e - 3:e] == b"\\\r\n"):
                f = b.find(b"\n", e)
                e = n if f < 0 else f + 1
            out.append((i, e))
            j = e
        i = j
    return out


def statements(b, mask, pp):
    """Top-level statements: (start, end, text) where end is past the `;` or the closing `}` of a function body."""
    code = bytearray(mask)
    for s, e in pp:
        for x in range(s, e):
            code[x] = 0
    out, i, n = [], 0, len(b)
    while i < n:
        if not code[i] or b[i:i + 1] in b" \t\r\n":
            i += 1
            continue
        start, depth, j, body = i, 0, i, False
        while j < n:
            if code[j]:
                c = b[j:j + 1]
                if c in b"([":
                    depth += 1
                elif c == b"{":
                    if depth == 0 and b[j - 1:j] != b"(":
                        body = True
                    depth += 1
                elif c in b")]}":
                    depth -= 1
                    if c == b"}" and depth == 0 and body:
                        j += 1
                        break
                elif c == b";" and depth == 0:
                    j += 1
                    break
            j += 1
        out.append((start, j, b[start:j], body))
        i = j
    return out


def is_decl(text, body):
    if body or not DECL_HEAD.match(text):
        return False
    m = code_mask(text)
    depth = 0
    for i, c in enumerate(text):
        if not m[i]:
            continue
        if c == ord("=") and depth == 0:
            return True
        if c == ord("(") and depth == 0:
            return False   # a prototype
        if c in b"([":
            depth += 1
        elif c in b")]":
            depth -= 1
    return True


def header_declares(path, incdirs, seen):
    if path in seen or not os.path.isfile(path):
        return False
    seen.add(path)
    b = open(path, "rb").read()
    mask = code_mask(b)
    pp = pp_lines(b, mask)
    if any(is_decl(t, body) for _, _, t, body in statements(b, mask, pp)):
        return True
    for s, e in pp:
        m = re.match(rb"\s*#\s*include\s*([<\"])([^>\"]+)[>\"]", b[s:e])
        if m:
            p = resolve(m.group(2).decode("utf-8", "replace"), m.group(1) == b'"', os.path.dirname(path), incdirs)
            if p and header_declares(p, incdirs, seen):
                return True
    return False


def resolve(name, local, here, incdirs):
    work = incdirs[0]
    cands = []
    if name.startswith("/"):
        cands.append(work + name)
    else:
        if local:
            cands.append(os.path.join(here, name))
        cands += [work + d + "/" + name for d in incdirs[1:]]
        if not local:
            cands.append(os.path.join(here, name))
    for c in cands:
        if os.path.isfile(c):
            return os.path.normpath(c)
    return None


def if_depth(pp_ranges, b, off):
    d = 0
    for s, e in pp_ranges:
        if s >= off:
            break
        t = b[s:e].lstrip()
        if re.match(rb"#\s*if", t):
            d += 1
        elif re.match(rb"#\s*endif", t):
            d -= 1
    return d


def line_range(b, s, e):
    ls = b.rfind(b"\n", 0, s) + 1
    le = b.find(b"\n", max(s, e - 1))
    le = len(b) if le < 0 else le + 1
    return ls, le


def fix(b, incdirs, here):
    mask = code_mask(b)
    pp = pp_lines(b, mask)
    st = statements(b, mask, pp)
    inh = [x for x in st if re.match(rb"inherit\b", x[2])]
    if not inh:
        return "no top-level inherit"
    last = inh[-1]
    # the inherits must form one group: a file pasted in twice has a second `inherit` block after function bodies,
    # and moving the globals below it only trades the error for redeclarations
    if any(body for s_, e_, t_, body in st if s_ < last[0] and s_ > inh[0][0]):
        return "a function body between the inherits (a file pasted twice?)"
    if if_depth(pp, b, last[0]):
        return "last inherit inside #if"
    offs = [(s, e) for s, e, t, body in st if e <= last[0] and is_decl(t, body)]
    for s, e in pp:
        if e > last[0]:
            break
        m = re.match(rb"\s*#\s*include\s*([<\"])([^>\"]+)[>\"]", b[s:e])
        if not m:
            continue
        p = resolve(m.group(2).decode("utf-8", "replace"), m.group(1) == b'"', here, incdirs)
        if p and header_declares(p, incdirs, set()):
            offs.append((s, e))
    if not offs:
        return "no offender found before the last inherit"
    stmt_spans = [(s, e) for s, e, _, _ in st]
    ranges = set()
    for s, e in offs:
        if if_depth(pp, b, s):
            return "an offender inside #if"
        ls, le = line_range(b, s, e)
        # the line(s) must hold nothing but offenders, whitespace and comments
        for ss, se in stmt_spans + pp:
            if ss < le and se > ls and (ss, se) not in offs and any(mask[x] and b[x:x + 1] not in b" \t\r\n"
                                                                    for x in range(max(ss, ls), min(se, le))):
                return "an offender shares a line with other code: %r" % b[ls:le][:60]
        ranges.add((ls, le))
    ranges = sorted(ranges)
    _, ins = line_range(b, last[0], last[1])
    moved = b"".join(b[s:e] for s, e in ranges)
    if not moved.endswith(b"\n"):
        moved += b"\r\n" if b"\r\n" in b else b"\n"
    out = b[:ins] + moved + b[ins:]
    for s, e in reversed(ranges):
        out = out[:s] + out[e:]
    return out, ranges


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
    incdirs = [work]
    cfg = open(f"{REPO}/libs/{slug}/config.fluffos", encoding="utf-8", errors="replace").read()
    m = re.search(r"^include directories\s*:\s*(.+)$", cfg, re.M)
    if m:
        incdirs += [d.strip() for d in m.group(1).split(":") if d.strip()]
    files = sorted({r.split("\t")[0] for r in open(diag, encoding="utf-8", errors="replace")
                    if r.count("\t") >= 4 and r.split("\t")[3] == "error" and r.split("\t")[4].startswith(MSG)})
    done = hand = 0
    for f in files:
        p = work + f
        if not os.path.isfile(p):
            continue
        b = open(p, "rb").read()
        res = fix(b, incdirs, os.path.dirname(p))
        if isinstance(res, str):
            print(f"HAND  {f}  {res}")
            hand += 1
            continue
        out, ranges = res
        print(f"FIX   {f}  moved {len(ranges)} line range(s) below the last inherit")
        done += 1
        if apply:
            open(p, "wb").write(out)
    print(f"{done} fixed, {hand} for a hand edit" + ("" if apply else " (plan only; --apply writes)"))


if __name__ == "__main__":
    main()
