#!/usr/bin/env python3
"""scripts/lpc_name_winner.py SLUG [--apply] [--only SUBSTR ...]

Name the winner of an `F() inherited from both A and B; using the definition in W` overlap (KB 04 section 6.10).
The driver already uses W's F, so the leaf file that inherits both gets one more function that says so:

    int get() { return autoload::get(); }

which changes nothing at run time and silences the warning.  W is the later inherit (the driver's rule); the scope
name is the basename of the leaf's direct inherit that provides W (W itself, or the `via` file of the message).
The signature is copied from W's definition, so the override agrees with it in return type and argument list.

Without --apply it prints the plan.  Diagnostics come from /tmp/lpcw-SLUG/diagnostics.tsv (scripts/lpc_warnings.py).
Skipped, and listed: a leaf that is a header, a W whose definition cannot be parsed (macro, no explicit return type,
unnamed parameters), a `private`/`nomask` W, a scope name two direct inherits share, a function the leaf defines
already.  Read the plan once: the unqualified F() calls that W's own code makes now reach the leaf's function, which
calls W's F, so nothing changes; but a lib whose design needs the *other* inherit's F to win wants a hand edit
(`autoload::get()` vs `object::get()`; KB 06 section 7.213 kind 3).  The new functions go after the last top-level
`inherit` line of the leaf -- even when that line sits inside `#if`/`#ifdef`, so check the placement when the wrapper
scopes belong to another branch (spacemud `std/body.lpc` needed a hand move).  An `inherit` that comes from an
`#include`d header is not seen: the rescan then reports `Unable to find the inherited function 'f' in file 'x'` for the
leaf (xkx2001 `d/zhongnan/dajiaochang.lpc`, `d/city/nproom.lpc`); move the wrapper below the include, or delete the
leaf's redundant inherit.  Edits are byte-exact (line endings kept)."""
import collections
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from lpc_src import MODS, TYPES, mask, read, top_level_defs  # noqa: E402

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
args = sys.argv[1:]
if not args or args[0].startswith("--"):
    sys.exit(__doc__)
slug = args[0]
apply_ = "--apply" in args
only = args[args.index("--only") + 1:] if "--only" in args else []
W = f"{REPO}/libs/{slug}/work"
ROWS = f"/tmp/lpcw-{slug}/diagnostics.tsv"

MSG = re.compile(r"^(?P<fn>\w+)\(\) inherited from both (?P<a>\S+?)(?: \(via (?P<av>\S+?)\))? and (?P<b>\S+?)"
                 r"(?: \(via (?P<bv>\S+?)\))?; using the definition in (?P<w>\S+?)\.$")


def signature(wpath, fn):
    """(modifiers, return type, [(param text, param name)]) of fn's definition in the file, or (None, reason)"""
    src = read(wpath)
    if src is None:
        return None, f"cannot read {wpath}"
    m = mask(src)
    found = top_level_defs(src, fn)
    if len(found) != 1:
        return None, f"{len(found)} definitions of {fn} at top level"
    i, j, k = found[0]
    head = re.findall(r"[A-Za-z_]\w*|\*", m[max(0, i - 160):i])
    mods, rtype, stars = [], None, ""
    for tok in reversed(head):
        if tok == "*":
            stars += "*"
        elif tok in MODS:
            mods.append(tok)
        elif tok in TYPES and rtype is None:
            rtype = tok + (" " + stars if stars else "")
        else:
            break
    if rtype is None:
        return None, "no explicit return type"
    if "private" in mods or "nomask" in mods:
        return None, "private or nomask"
    params_src = src[j + 1:k]
    params = []
    if params_src.strip() and params_src.strip() != "void":
        depth = 0
        cur = ""
        for ch in params_src + ",":
            if ch in "([{":
                depth += 1
            elif ch in ")]}":
                depth -= 1
            if ch == "," and depth == 0:
                p = re.sub(r"\s+", " ", cur.strip())
                nm = re.search(r"([A-Za-z_]\w*)\s*(\.\.\.)?$", p)
                if not p or not nm or p in TYPES or re.fullmatch(r"(?:class \w+|\w+)(?: \*+)?", p) and p.split()[0] in TYPES | {"class"}:
                    return None, f"unnamed parameter {p!r}"
                params.append((p, nm.group(1), bool(nm.group(2))))
                cur = ""
            else:
                cur += ch
    return ([x for x in reversed(mods)], rtype, params), None


def main():
    rows = [l.rstrip("\n").split("\t") for l in open(ROWS, encoding="utf-8", errors="replace")]
    plans = collections.defaultdict(dict)       # leaf -> {fn: (qualifier, signature)}
    skipped = []
    pairs = collections.defaultdict(list)       # (leaf, fn) -> every message about it, in file order
    for f, ln, col, sev, msg in rows:
        m = MSG.match(msg)
        if not m or (only and not any(o in f for o in only)):
            continue
        if f.endswith(".h"):
            skipped.append((f, m["fn"], "diagnostic is in a header"))
            continue
        pairs[(f, m["fn"])].append(m)
    chosen = []
    for (f, fn), ms in pairs.items():
        # Three inherits that define one function give two messages (A over B, then C over A): the driver's final
        # winner is the W no other message displaces, i.e. one that is nobody's `b` under a different W.
        ws = {m["w"] for m in ms}
        alive = {w for w in ws if not any(m["b"] == w and m["w"] != w for m in ms)}
        if len(alive) != 1:
            skipped.append((f, fn, f"{len(alive)} candidate winners ({', '.join(sorted(ws))})"))
            continue
        chosen.append((f, next(m for m in ms if m["w"] in alive)))
    for f, m in chosen:
        fn, w = m["fn"], m["w"]
        if w == m["a"]:
            direct = m["av"] or m["a"]
        elif w == m["b"]:
            direct = m["bv"] or m["b"]
        else:                                   # the message names the file that provides W (the `via` one)
            direct = w
        qual = os.path.basename(direct)
        qual = qual[:-4] if qual.endswith(".lpc") else qual
        sig, why = None, "no candidate"
        for cand in dict.fromkeys([w, m["a"], m["b"]]):      # the definition may sit in an ancestor of W
            sig, why = signature(W + cand, fn)
            if sig is not None or not why.startswith("0 definitions"):
                break
        if sig is None:
            skipped.append((f, fn, why))
            continue
        plans[f][fn] = (qual, sig)
    todo = 0
    for f, fns in sorted(plans.items()):
        path = W + f
        src = read(path)
        if src is None:
            continue
        masked = mask(src)
        # a function the leaf already defines: nothing to add
        fns = {fn: v for fn, v in fns.items() if not top_level_defs(src, fn)}
        if not fns:
            continue
        inh = [mm for mm in re.finditer(r"(?m)^[ \t]*inherit\b[^;]*;[^\n]*\n?", masked)]
        if not inh:
            skipped.append((f, ",".join(fns), "no top-level inherit line found"))
            continue
        quals = [os.path.basename(re.sub(r'.*?"([^"]+)".*', r"\1", src[mm.start():mm.end()])) for mm in inh]
        crlf = "\r\n" in src
        nl = "\r\n" if crlf else "\n"
        lines = []
        for fn, (qual, (mods, rtype, params)) in sorted(fns.items()):
            plist = ", ".join(p[0] for p in params)
            alist = ", ".join(p[1] for p in params)
            head = (" ".join(mods) + " " if mods else "") + rtype + " " + fn + "(" + plist + ")"
            body = (f"{qual}::{fn}({alist});" if rtype.strip() == "void" else f"return {qual}::{fn}({alist});")
            lines.append(f"{head} {{ {body} }}")
        block = (nl + "/* Two inherits define " + ", ".join(sorted(fns)) + "(); the later one was already in effect: name it. */"
                 + nl + nl.join(lines) + nl)
        pos = inh[-1].end()
        if not src[pos - 1:pos] == "\n":
            block = nl + block
        todo += len(fns)
        print(f"{'FIX ' if apply_ else 'plan'} {f}: " + "; ".join(l for l in lines))
        if apply_:
            new = src[:pos] + block + src[pos:]
            open(path, "wb").write(new.encode("latin-1"))
    for f, fn, why in skipped:
        print(f"SKIP {f}: {fn}: {why}")
    print(f"{todo} function(s) in {len(plans)} file(s) {'written' if apply_ else 'planned'}; {len(skipped)} skipped")


main()
