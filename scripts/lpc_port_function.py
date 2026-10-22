#!/usr/bin/env python3
"""scripts/lpc_port_function.py [--apply] [--lfun] PLAN.tsv
scripts/lpc_port_function.py [--apply] [--lfun] --daemon /adm/daemons/chinesed.lpc --func chinese_month,chinese_time --donor SLUG TARGET...

A call `CHINESE_D->chinese_month(t)` to a function the lib's own copy of that daemon does not define, where the same daemon of a sibling lineage does (KB 06 section 7.354):
`call_other()` of a function that is not there answers 0 silently, so the feature simply never works -- the ferry that freezes in winter, the finger line's clock, the time-of-day
branches of an NPC's `init()`.  The function is copied, text and all, from the donor's daemon to the end of the target's daemon.

`--lfun` is the variant for a function POINTER (`(: ask_job :)` in an `inquiry`, `(: look_leitai :)` in an `item_desc`, KB 06 section 7.355): the target file holds the prototype or nothing
at all, the same file of a sibling lineage defines the function; the path column is then the object file itself (`/d/tanggu/kongchangdi.lpc`) and the comment says that the pointer
named a function this copy lacked.  Rows whose function is still in the target inside a comment are a deliberate removal (a cheat NPC's commands): `--lfun` leaves them.

PLAN.tsv lines are `daemon<TAB>func<TAB>target slug<TAB>donor slug` (the PORT rows of the dependency analysis: every function the body calls, every global it names and every macro it
uses is already there in the target daemon, every string literal it compares or indexes with occurs in the target daemon's source, i.e. the data shape matches).  The second form
takes the daemon path, the function names and the donor on the command line and the targets as arguments.  A target that already defines the function (also found by a plain scan of the raw text: a `@@HELP ... HELP` here-doc can hide a whole region from the code mask, and a second copy is `Redefinition of function`: go.lpc of sjshv2578bb / xyj20032), whose daemon file is missing,
or whose copy of the function cannot be cut out cleanly is printed and left.  The copied text keeps the donor's header and body, gets the target file's own line endings, and a
one-line comment above it names the donor.  Binary mode, idempotent.  Dry run by default; `--apply` writes."""
import os
import re
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from lpc_fix_void_return import code_mask  # noqa: E402


def extract(b, name):
    """(start, end, text) of the definition of function `name` in bytes b, or None; a prototype does not count"""
    mask = code_mask(b, heredoc=True)
    pat = re.compile(rb"(?m)^[ \t]*((?:(?:varargs|nomask|private|protected|public|static|nosave)[ \t]+)*(?:(?:void|int|string|object|mixed|mapping|float|status|buffer|function|class[ \t]+\w+)[ \t]*\**[ \t]*)?)" + re.escape(name.encode()) + rb"[ \t\r\n]*\(")
    for m in pat.finditer(b):
        if not mask[m.start(1)]:
            continue
        i, depth = m.end(), 1
        while i < len(b) and depth:
            if mask[i]:
                depth += (b[i] == 0x28) - (b[i] == 0x29)
            i += 1
        j = i
        while j < len(b) and b[j:j + 1] in b" \t\r\n":
            j += 1
        if b[j:j + 1] != b"{":
            continue
        depth, k = 1, j + 1
        while k < len(b) and depth:
            if mask[k]:
                depth += (b[k] == 0x7B) - (b[k] == 0x7D)
            k += 1
        if depth:
            return None
        return m.start(), k, b[m.start():k]
    return None


def work(slug, path):
    return os.path.join(REPO, "libs", slug, "work", path.lstrip("/"))


def read(slug, path):
    try:
        return open(work(slug, path), "rb").read()
    except OSError:
        return None


def commented_out(tb, func):
    """the header of `func` is still in the file inside a comment: the function was removed on purpose"""
    mask = code_mask(tb, heredoc=True)
    pat = re.compile(rb"\b(?:int|string|void|mixed|object|status|varargs|static|nomask|private|protected)[ \t]+\**" + re.escape(func.encode()) + rb"[ \t\r\n]*\(")
    return any(not mask[m.start()] for m in pat.finditer(tb))


def plain_definition(tb, func):
    """a definition of `func` by a plain regex over the raw text (no mask): the mask can lose a whole region behind a `@@HELP ... HELP` here-doc, and a second copy is `Redefinition of function`"""
    pat = re.compile(rb"(?m)^[ \t]*(?:(?:varargs|nomask|private|protected|public|static|nosave)[ \t]+)*(?:(?:void|int|string|object|mixed|mapping|float|status|buffer|function)[ \t]*\**[ \t]*)?" + re.escape(func.encode()) + rb"[ \t\r\n]*\([^;{}]*\)[ \t\r\n]*\{")
    mask = code_mask(tb, heredoc=True)
    # a plain hit counts unless it sits in a comment (the mask is off there AND the line starts with a comment marker)
    for m in pat.finditer(tb):
        line_start = tb.rfind(b"\n", 0, m.start()) + 1
        if not mask[m.start()] and re.match(rb"[ \t]*(//|/\*|\*)", tb[line_start:m.end()]):
            continue
        return True
    return False


def port(daemon, func, target, donor, apply, lfun=False):
    db = read(donor, daemon)
    tb = read(target, daemon)
    if db is None:
        return f"SKIP {target} {daemon} {func}: the donor {donor} has no {daemon}"
    if tb is None:
        return f"SKIP {target} {daemon} {func}: the target has no {daemon}"
    got = extract(db, func)
    if got is None:
        return f"SKIP {target} {daemon} {func}: no definition of it in the donor {donor}"
    if extract(tb, func) is not None:
        return f"HAVE {target} {daemon} {func}"
    if plain_definition(tb, func):
        return f"SKIP {target} {daemon} {func}: the target already defines it (found by a plain scan; a here-doc kept the code mask from seeing it)"
    if lfun and commented_out(tb, func):
        return f"SKIP {target} {daemon} {func}: the target holds it inside a comment (removed on purpose)"
    nl = b"\r\n" if tb.count(b"\r\n") * 2 > tb.count(b"\n") else b"\n"
    text = got[2].replace(b"\r\n", b"\n").replace(b"\n", nl)
    body = tb.rstrip(b"\r\n")
    if lfun:
        note = b"// " + func.encode() + b": restored from the same file of " + donor.encode() + b"; a function pointer (: " + func.encode() + b" :) named it and this copy had the prototype only (KB 06 7.355)"
    else:
        note = b"// " + func.encode() + b": the same function of the daemon of the lib's other lineage (" + donor.encode() + b"), the callers got 0 without it (KB 06 7.354)"
    add = (nl + nl + note + nl + text + nl)
    if apply:
        open(work(target, daemon), "wb").write(body + add)
    return f"{'PORT' if apply else 'would port'} {target} {daemon} {func} <- {donor}"


def main():
    argv = sys.argv[1:]
    apply = "--apply" in argv
    lfun = "--lfun" in argv
    args = [a for a in argv if a not in ("--apply", "--lfun")]
    jobs = []
    if "--daemon" in args:
        def opt(name):
            return args[args.index(name) + 1]
        daemon, funcs, donor = opt("--daemon"), opt("--func").split(","), opt("--donor")
        skip = {args.index("--daemon") + 1, args.index("--func") + 1, args.index("--donor") + 1, args.index("--daemon"), args.index("--func"), args.index("--donor")}
        targets = [a for i, a in enumerate(args) if i not in skip]
        for t in targets:
            for f in funcs:
                jobs.append((daemon, f, t, donor))
    elif args:
        for ln in open(args[0], encoding="utf-8"):
            f = ln.rstrip("\n").split("\t")
            if len(f) >= 4 and f[0].startswith("/"):
                jobs.append((f[0], f[1], f[2], f[3]))
    else:
        sys.exit(__doc__)
    n = 0
    for daemon, func, target, donor in jobs:
        msg = port(daemon, func, target, donor, apply, lfun)
        if not msg.startswith("HAVE"):
            print(msg)
        n += msg.startswith(("PORT", "would port"))
    print(f"{n} function(s) {'ported' if apply else 'to port'} in {len({j[2] for j in jobs})} lib(s)", file=sys.stderr)


if __name__ == "__main__":
    main()
