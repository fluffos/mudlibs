#!/usr/bin/env python3
"""Find (and fix the safe cases of) programs that inherit the same file twice.

Why: FluffOS keeps one copy of an inherited program's variables per inherit path, so a file
reached through two paths prints `Redeclaration of global variable 'X'` for every variable
and `F() inherited from both X and X` for every function (KB 04 §6.10), and the later copy
wins every function while its variables are forced `nosave` (compiler.cc define_variable) --
a silent persistence loss plus clobbered overrides (KB 06 §7.213).

  python3 scripts/lpc_diamonds.py SLUG                 # every file whose direct inherits overlap
  python3 scripts/lpc_diamonds.py SLUG --fix-redundant # preview the safe fixes
  python3 scripts/lpc_diamonds.py SLUG --fix-redundant --apply
  options: --only-lib (restrict to lib/ and secure/lib/)  --files REGEX

A pair (A, B) is *redundant* when everything B brings is already inside A's inherit closure
(B == A, or B is an ancestor of A).  The redundant `inherit B;` line is deleted when
  - it is a plain one-line `inherit EXPR;` outside any #if,
  - the file never calls `b::fn()` through B's scope name (that scope name would vanish),
  - and B is not inherited *before* A in a file that uses an unqualified `::fn()` call
    (the driver picks the first inherit that has fn, so removing B could change the target).
Everything else (partial overlaps, scope calls) is listed for a human: the right fix there
depends on which copy the object really uses (see KB 06 §7.213 for the radiance/smell cases).
Inherit paths are resolved through the lib's own #defines (LIB_ITEM -> "/lib/std/item").
"""
import itertools
import os
import re
import sys

args = sys.argv[1:]
if not args or args[0].startswith("--"):
    sys.exit(__doc__)
slug = args[0]
work = f"/home/sunyc/src/mudlib/libs/{slug}/work"
only_lib = "--only-lib" in args
fix = "--fix-redundant" in args
apply_ = "--apply" in args
files_re = None
if "--files" in args:
    files_re = re.compile(args[args.index("--files") + 1])

SKIP_TOP = ("log", "www", "doc", "realms", "estates")

defs = {}
for dp, dn, fn in os.walk(work):
    rel = os.path.relpath(dp, work)
    if rel.startswith(SKIP_TOP):
        continue
    for f in fn:
        if f.endswith(".h"):
            try:
                t = open(os.path.join(dp, f), encoding="latin-1").read()
            except OSError:
                continue
            for m in re.finditer(r"^[ \t]*#[ \t]*define[ \t]+([A-Za-z_]\w*)[ \t]+([^\n]*)$", t, re.M):
                body = re.sub(r"/\*.*?\*/|//.*", "", m.group(2)).strip()
                defs.setdefault(m.group(1), body)


def expand(expr, depth=0):
    if depth > 8:
        return None
    parts = re.findall(r'"[^"]*"|[A-Za-z_]\w*', expr)
    out = ""
    for p in parts:
        if p.startswith('"'):
            out += p[1:-1]
        elif p in defs:
            r = expand(defs[p], depth + 1)
            if r is None:
                return None
            out += r
        else:
            return None
    return out


def resolve(arg):
    arg = arg.strip()
    return arg.strip('"') if arg.startswith('"') else expand(arg)


def norm(path):
    for ext in (".lpc", ".c"):
        if path.endswith(ext):
            return path[: -len(ext)]
    return path


def file_for(path):
    p = path if path.startswith("/") else "/" + path
    for ext in (".lpc", ".c", ""):
        if os.path.isfile(work + p + ext):
            return p + ext if ext else p
    return None


INH = re.compile(r"^([ \t]*)((?:(?:private|protected|public|static|nosave|varargs)[ \t]+)*)inherit[ \t]+([^;]+);", re.M)
cache, clo_cache = {}, {}


def mask_comments(t):
    t = re.sub(r"/\*.*?\*/", lambda m: re.sub(r"[^\n]", " ", m.group(0)), t, flags=re.S)
    return re.sub(r"//[^\n]*", lambda m: " " * len(m.group(0)), t)


def conditional_flags(masked_lines):
    """per line: inside an #if/#ifdef/#ifndef block"""
    flags, depth = [], 0
    for l in masked_lines:
        s = l.strip()
        if re.match(r"#\s*if", s):
            depth += 1
            flags.append(True)
            continue
        flags.append(depth > 0)
        if re.match(r"#\s*endif", s):
            depth = max(0, depth - 1)
    return flags


def inherits_of(path):
    path = norm(path if path.startswith("/") else "/" + path)
    if path in cache:
        return cache[path]
    fp = file_for(path)
    res = []
    if fp:
        text = open(work + fp, encoding="latin-1").read()
        masked = mask_comments(text)
        for m in INH.finditer(masked):
            raw = m.group(3).strip()
            ln = masked.count("\n", 0, m.start()) + 1
            mods = m.group(2).strip()
            r = resolve(raw)
            res.append({"raw": raw, "path": norm(r) if r else None, "line": ln, "mods": mods})
    cache[path] = res
    return res


def closure(path):
    path = norm(path)
    if path in clo_cache:
        return clo_cache[path]
    clo_cache[path] = set()
    s = set()
    for i in inherits_of(path):
        if i["path"]:
            s.add(i["path"])
            s |= closure(i["path"])
    clo_cache[path] = s
    return s


def all_files():
    out = []
    for dp, dn, fn in os.walk(work):
        rel = os.path.relpath(dp, work)
        if rel.startswith(SKIP_TOP):
            continue
        if only_lib and not rel.startswith(("lib", "secure/lib")):
            continue
        for f in fn:
            if f.endswith((".lpc", ".c")):
                p = "/" + os.path.relpath(os.path.join(dp, f), work)
                if files_re is None or files_re.search(p):
                    out.append(p)
    return sorted(out)


def pairs(path):
    inh = [i for i in inherits_of(path) if i["path"]]
    for a, b in itertools.combinations(inh, 2):
        ca, cb = closure(a["path"]) | {a["path"]}, closure(b["path"]) | {b["path"]}
        sh = ca & cb
        if sh:
            yield a, b, sh, ca <= cb, cb <= ca


def report(files):
    n = 0
    for f in files:
        ps = list(pairs(f))
        if not ps:
            continue
        n += 1
        print(f"\n{f}")
        for a, b, sh, a_in_b, b_in_a in ps:
            tag = "A in B" if a_in_b else ("B in A" if b_in_a else "partial")
            print(f"  L{a['line']} {a['raw']} ({a['path']})  x  L{b['line']} {b['raw']} ({b['path']})  [{tag}]  shared: {', '.join(sorted(sh))}")
    print(f"\n{n} files have overlapping direct inherits")


def scope_names(prog):
    return {os.path.basename(prog)}


def plan_fixes(files):
    """-> {file: [(line, raw, reason_ok or None, note)]}"""
    plans = {}
    for f in files:
        fp = file_for(f)
        text = open(work + fp, encoding="latin-1").read()
        masked = mask_comments(text)
        mlines = masked.split("\n")
        cond = conditional_flags(mlines)
        has_unq = re.search(r"(?<![\w:])::\s*\w+\s*\(", masked) is not None
        dropped = set()
        out = []
        for a, b, sh, a_in_b, b_in_a in pairs(f):
            if a_in_b and b_in_a:
                victim, cover = b, a          # identical closure: drop the later one
            elif b_in_a:
                victim, cover = b, a
            elif a_in_b:
                victim, cover = a, b
            else:
                continue
            if victim["line"] in dropped:
                continue
            why = None
            if victim["mods"]:
                why = f"inherit has modifiers ({victim['mods']})"
            elif cond[victim["line"] - 1]:
                why = "inside #if"
            else:
                for sc in scope_names(victim["path"]):
                    if re.search(r"(?<![\w:])" + re.escape(sc) + r"\s*::", masked):
                        why = f"file calls {sc}::fn() through the scope name"
                        break
                if why is None and has_unq and victim["line"] < cover["line"]:
                    why = "unqualified ::fn() call and the redundant inherit comes first"
            line_txt = text.split("\n")[victim["line"] - 1]
            if why is None and not re.fullmatch(r"[ \t]*inherit[ \t]+[^;]+;[ \t]*(//[^\n]*|/\*.*\*/)?[ \t]*\r?", line_txt):
                why = "inherit line has other text on it"
            out.append((victim["line"], victim["raw"], cover["raw"], cover["line"], why))
            if why is None:
                dropped.add(victim["line"])
        if out:
            plans[f] = out
    return plans


def apply_plan(f, entries):
    fp = work + file_for(f)
    with open(fp, "rb") as fh:
        text = fh.read().decode("latin-1")
    lines = text.split("\n")
    for ln in sorted({e[0] for e in entries if e[4] is None}, reverse=True):
        del lines[ln - 1]
    with open(fp, "wb") as fh:
        fh.write("\n".join(lines).encode("latin-1"))


def main():
    files = all_files()
    if not fix:
        report(files)
        return
    plans = plan_fixes(files)
    ok = man = 0
    for f, entries in sorted(plans.items()):
        for ln, raw, cover, cl, why in entries:
            if why is None:
                ok += 1
                print(f"{'FIX ' if apply_ else 'fix '} {f}:{ln}: drop `inherit {raw};` (already inside `inherit {cover};` at line {cl})")
            else:
                man += 1
                print(f"MANUAL {f}:{ln}: `inherit {raw};` is redundant with `{cover}` (line {cl}) but: {why}")
        if apply_:
            apply_plan(f, entries)
    print(f"\n{ok} redundant inherit(s) {'removed' if apply_ else 'removable'}, {man} need a human")


main()
