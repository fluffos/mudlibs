#!/usr/bin/env python3
"""scripts/lpc_guard_carry_object.py SLUG... [--apply] [--list] [--base | --unew | --macro | --new]

An NPC that carries an item this archive never shipped (KB 06 section 7.73): `carry_object("/d/city/obj/cloth/jinpao")->wear();`
gets 0 back and `->wear()` raises `Bad argument 1 to EFUN call_other()` in create(), so the NPC never loads -- the room
that should hold it comes up without it, the quest giver or master is simply absent, a hired NPC cannot be cloned.

Each such statement whose path is a string literal (absolute, or `__DIR__ "x"`) that names no file in the lib becomes
a block `{ object carried_ob = carry_object("..."); if (carried_ob) carried_ob->wear(); }` (written on four lines, the layout the
formatter keeps): the NPC loads without the item, and
if the file comes back (or the path is a virtual object) it is carried as before.  A sibling block may reuse the name,
a nested one may not (`Illegal to redeclare local name`), so a file that already uses `carried_ob` is left alone.  Only
full statements are rewritten; comments, strings, wizard and backup dirs, gitlink libs and the generated tree of
longyunmeng_binary are skipped.  Binary-safe.  Without --apply the plan is printed (--list: one line per site).

--base fixes the other half: an NPC base whose own `carry_object(string file)` starts with `if (file->query_unique())` (the
xyj / sjsh / mhxy lineage, ~30 libs).  `file->query_unique()` is a call_other on a path string, and on this driver that RAISES
`call_other() couldn't find object` for a missing file before `new()` can return 0, so the call-site guard above cannot help
there and every NPC naming a missing item fails to load.  The fix puts `if (!objectp(load_object(file))) return 0;` before
that statement (sjshwzb and sjshwzjqb already carry a `file_size()` version of it, KB 06 section 7.99); a base that already
tests the file first is left alone.

--macro is the first shape again with a path that is not a string literal: `carry_object(ARMOR_D("cloth"))->wear();`, `carry_object(CLOTH_DIR "x")->wear();`,
`carry_object(ARMOR_DIR + "x")->wield();` (the nitan family's quest NPCs, the hubiao escort, jinshe, jiuyin).  The expression is resolved with the macro resolver of
`lpc_scan_callout_targets.py` (`Lib.literal()`: the lib's `#define`s, function-like macros with literal arguments, `__DIR__`, `+`); a path that names no file of the
lib gets the same guarded block, and an expression the resolver cannot settle is left alone.

--new is the same guard for `new(PATH)->move(TO);` / `clone_object(..)->..` / `unew(..)->..` (shadowgate's rooms spawn their monsters that way in `reset()`; 4,476 sites of one
lib name a monster the archive never shipped): `new()` of a missing file returns 0, `->move()` on it raises `Bad argument 1 to EFUN call_other()`, and in `create()` the object never
loads, in `reset()` every spawn below the first missing one is skipped on every reset.  A literal path and a macro expression are both resolved (`Lib.literal()`).

--unew fixes the third shape: the simul_efun `unew(str)` (xkx lineage, "new, but honour `unique`") that `carry_object()` calls does
`object ob = new(str); ... ob->query("unique")`.  `new()` of a missing file returns 0 and the query on it raises `Bad argument 1
to EFUN call_other()`, so again the NPC never loads.  `if (!ob) return ob;` goes before the first query (fyzfqyy already had it)."""
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from lpc_fix_void_return import code_mask  # noqa: E402

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SKIP = re.compile(r"/(u|w|wiz|wizard|wizards|open|players|backup|backups|old|bak|log|data|doc|example|examples)/|[-_.](bak|old)/")
CALL = re.compile(rb'carry_object\(\s*(__DIR__\s*)?"([^"\n]+)"\s*\)\s*->\s*(\w+)\s*\(')
VAR = b"carried_ob"


def close_paren(b, i):
    """index just past the parenthesis that closes the one opened at b[i - 1]"""
    depth, q = 1, None
    while i < len(b):
        c = b[i:i + 1]
        if q:
            if c == b"\\":
                i += 1
            elif c == q:
                q = None
        elif c in (b'"', b"'"):
            q = c
        elif c == b"(":
            depth += 1
        elif c == b")":
            depth -= 1
            if depth == 0:
                return i + 1
        i += 1
    return -1


def statement_start(b, i):
    """True when b[i] begins a statement: the previous token is ; { } ) else or a case label's :"""
    j = i - 1
    while j >= 0 and b[j:j + 1] in b" \t\r\n":
        j -= 1
    if j < 0:
        return True
    if b[j:j + 1] in b";{})":
        return True
    if b[j:j + 1] == b":" and b[j - 1:j] != b":":
        return True
    return b[max(0, j - 3):j + 1] == b"else" and not re.match(rb"[A-Za-z0-9_]", b[j - 4:j - 3] or b" ")


def eol_of(b, i):
    """the line ending in use around b[i]"""
    j = b.find(b"\n", i)
    return b"\r\n" if j > 0 and b[j - 1:j] == b"\r" else b"\n"


def block(prefix, eol, arg, call, var=None, fn=b"carry_object"):
    """the guarded statement in the layout the formatter keeps (so a lib normalized at HEAD stays normalized):
         {                                  prefix is what precedes the statement on its line, an `if (...)`, an `else`
           object carried_ob = carry_object(ARG);   or nothing; the opening brace joins it, the body is indented two
           if (carried_ob) carried_ob->CALL;        beyond the line's own indent
         }"""
    var = var or VAR
    indent = prefix[:len(prefix) - len(prefix.lstrip(b" \t"))]
    return (b"{" + eol + indent + b"  object " + var + b" = " + fn + b"(" + arg + b");" + eol +
            indent + b"  if (" + var + b") " + var + b"->" + call + b";" + eol + indent + b"}")


def missing(work, rel_file, dirflag, path):
    p = path
    if dirflag:
        p = os.path.dirname(rel_file) + "/" + p
    if not p.startswith("/"):
        return False                          # relative to the cwd at run time: cannot tell
    if p.endswith(".c"):                       # an explicit extension is resolved exactly (KB 03 4.2, KB 06 7.356): `y.c` finds no file when the archive's file is `y.lpc`
        return not os.path.isfile(work + p)
    p = re.sub(r"\.lpc$", "", p)
    return not os.path.isfile(work + p + ".lpc") and not os.path.isdir(work + p)


def fix(work, rel, b):
    if re.search(rb"\b" + VAR + rb"\b", b):
        return b, [], "uses " + VAR.decode()
    mask = code_mask(b)
    out, last, sites = [], 0, []
    for m in CALL.finditer(b):
        if not mask[m.start()] or not statement_start(b, m.start()):
            continue
        path = m.group(2).decode("utf-8", "surrogateescape")
        if not missing(work, rel, m.group(1), path):
            continue
        end = close_paren(b, m.end())
        if end < 0:
            continue
        k = end
        while k < len(b) and b[k:k + 1] in b" \t":
            k += 1
        if b[k:k + 1] != b";":
            continue                          # the result is used in an expression: leave it
        arg = b[m.start() + len(b"carry_object("):b.index(b")", m.start(2) + len(m.group(2)))]
        call = b[m.start(3):end]                                      # wear(), wield(), set_amount(10)
        out.append(b[last:m.start()])
        ls = b.rfind(b"\n", 0, m.start()) + 1
        out.append(block(b[ls:m.start()], eol_of(b, m.start()), arg.strip(), call))
        last = k + 1
        sites.append(path)
    out.append(b[last:])
    return b"".join(out), sites, ""


MACRO_EXPR = rb'(?:[A-Za-z_]\w*[ \t]*(?:\([^()\n]*\))?|"[^"\n]*")(?:[ \t]*\+?[ \t]*(?:[A-Za-z_]\w*[ \t]*(?:\([^()\n]*\))?|"[^"\n]*"))*'
CALLM = re.compile(rb"carry_object\(\s*(" + MACRO_EXPR + rb")\s*\)\s*->\s*(\w+)\s*\(")
CALLN = re.compile(rb"(?<![A-Za-z_0-9>])(carry_object|new|clone_object|unew)\(\s*(" + MACRO_EXPR + rb")\s*\)\s*->\s*(\w+)\s*\(")


def local_macros(lib, rel, seen=None, depth=0):
    """the macros the file REL sees: its own `#define`s and those of the headers it includes (relative `"x.h"`, the lib's include directories, absolute), as
    (object-like {name: [(expr, header)]}, function-like {name: [(params, body)]}).  The resolver's global table keeps the FIRST definition of a name in the whole lib, and an area
    header such as `#define MON "/d/shadow/room/muuldaan/mon/"` exists once per area: reading the global table resolved `MON"guard1"` against another area's directory and
    called a monster that exists missing (the guard went in for nothing).  A name defined differently along the closure is ambiguous and left to the caller to skip."""
    import lpc_scan_callout_targets as resolver
    seen = seen if seen is not None else set()
    objs, funcs = {}, {}
    if rel in seen or depth > 6:
        return objs, funcs
    seen.add(rel)
    b = resolver.strip_comments(lib.read(rel))
    fdir = os.path.dirname(rel) + "/"
    for m in resolver.INCLUDE.finditer(b):
        name = m.group(2).decode("utf-8", "replace")
        if name.startswith("/"):
            cands = [os.path.normpath(name)]
        else:
            cands = [os.path.normpath(fdir + name)] if m.group(1) == b'"' else []
            cands += [os.path.normpath(d + "/" + name) for d in lib.incdirs] + [os.path.normpath("/" + name)]
        for c in cands:
            if c in lib.files:
                o2, f2 = local_macros(lib, c, seen, depth + 1)
                for k, v in o2.items():
                    objs.setdefault(k, []).extend(v)
                for k, v in f2.items():
                    funcs.setdefault(k, []).extend(v)
                break
    for m in resolver.DEFINE.finditer(b):
        objs.setdefault(m.group(1).decode(), []).append((m.group(2), rel))
    for m in resolver.FDEFINE.finditer(b):
        funcs.setdefault(m.group(1).decode(), []).append(([a.strip().decode() for a in m.group(2).split(b",") if a.strip()], m.group(3).strip()))
    return objs, funcs


def macro_tables(lib, rel):
    """({name: (expr, header)}, {name: (params, body)}) the file sees, a name that is defined two different ways along the include closure left out"""
    objs, funcs = local_macros(lib, rel)
    table, ftable = {}, {}
    for k, v in objs.items():
        if len({e for e, _ in v}) == 1:
            table[k] = (v[-1][0], v[-1][1])
    for k, v in funcs.items():
        if len({(tuple(p), body) for p, body in v}) == 1:
            ftable[k] = v[-1]
    return table, ftable


def resolve_here(lib, rel, expr, tables=None):
    """lib.literal(expr) against the macros the file sees, None when a macro is unknown there or defined in two different ways"""
    table, ftable = tables or macro_tables(lib, rel)
    save = (lib.macros, lib.fmacros)
    lib.macros, lib.fmacros = table, ftable
    try:
        return lib.literal(expr, os.path.dirname(rel) + "/")
    finally:
        lib.macros, lib.fmacros = save


def lib_macro_names(lib):
    """every name `#define`d in a header of the lib (object-like or function-like): a local variable called like a macro is expanded or breaks the line (the Shujian family's
    globals.h has `#define new_ob(str) new(resolve_path(__DIR__, str))`: `new_ob->move(me)` died with `unexpected L_ORDER`)"""
    if getattr(lib, "_macro_names", None) is None:
        names = set()
        for f in lib.files:
            if f.endswith(".h"):
                names |= set(re.findall(rb"(?m)^[ \t]*#[ \t]*define[ \t]+([A-Za-z_]\w*)", lib.read(f)))
        lib._macro_names = names
    return lib._macro_names


def fresh(b, base, taken=()):
    """base, base2, base3 ... the first name that is not a macro of the lib and does not occur in the file"""
    var, n = base, 1
    while re.search(rb"\b" + var + rb"\b", b) or var in taken:
        n += 1
        var = base + str(n).encode()
    return var


def fix_chain(lib, work, rel, b, new_mode=False):
    """like fix() for a statement `carry_object(EXPR)->fn(...)` where EXPR is a macro expression (the plain literal is fix()'s); new_mode (`--new`) takes every chain: `carry_object(MACRO..)`,
    `new(EXPR)->fn(...)`, `clone_object(..)`, `unew(..)`, a plain string too.  EXPR must resolve, with the macros THE FILE sees, to a path no file of the lib answers.  A file that already
    has guard blocks gets a fresh variable name (`carried_ob2`, `new_ob2`, ...): the blocks are siblings, never nested"""
    if not new_mode:
        pats = [(CALLM, False)]
    else:
        pats = [(CALLN, True)]
    mask = None
    tables = None
    out, last, sites = [], 0, []
    taken = lib_macro_names(lib)
    names = {b"carry_object": fresh(b, VAR, taken), b"new": fresh(b, b"new_ob", taken), b"clone_object": fresh(b, b"new_ob", taken), b"unew": fresh(b, b"new_ob", taken)}
    for pat, is_new in pats:
        for m in pat.finditer(b):
            fn, expr, name_i = (m.group(1), m.group(2), 3) if is_new else (b"carry_object", m.group(1), 2)
            if fn == b"carry_object" and re.fullmatch(rb'\s*"[^"\n]*"\s*', expr):
                continue                             # a plain literal: fix() reads those
            if mask is None:
                mask = code_mask(b, heredoc=True)
            if not mask[m.start()] or not statement_start(b, m.start()):
                continue
            if tables is None:
                tables = macro_tables(lib, rel)
            v = resolve_here(lib, rel, expr, tables)
            if v is None or not v.startswith("/"):
                continue
            p = re.sub(r"\.(lpc|c)$", "", v)
            if os.path.isfile(work + p + ".lpc") or os.path.isdir(work + p):
                continue
            if re.search(r"/virtual/|\.[A-Za-z]+$", p):
                continue                             # a virtual object (`/d/damned/virtual/great-axe_6.weapon`): the lib's virtual server makes it, no file is the normal case
            end = close_paren(b, m.end())
            if end < 0:
                continue
            k = end
            while k < len(b) and b[k:k + 1] in b" \t":
                k += 1
            if b[k:k + 1] != b";":
                continue                             # the result is used in an expression: leave it
            call = b[m.start(name_i):end]
            out.append((m.start(), b[last:m.start()] if False else None, end, k, expr.strip(), call, fn, v))
    # the matches are collected first (one pass of one regex), then written from the start so the pieces stay in order
    out.sort(key=lambda t: t[0])
    pieces, last = [], 0
    for start, _, end, k, expr, call, fn, v in out:
        if start < last:
            continue
        ls = b.rfind(b"\n", 0, start) + 1
        pieces.append(b[last:start])
        pieces.append(block(b[ls:start], eol_of(b, start), expr, call, names[fn], fn))
        last = k + 1
        sites.append(v)
    pieces.append(b[last:])
    return b"".join(pieces), sites, ""


BASE = re.compile(rb"(?m)^[ \t]*(?:varargs[ \t]+)?object[ \t]+carry_object[ \t]*\([ \t]*string[ \t]+(\w+)[ \t]*\)[ \t\r\n]*\{")


def fix_base(b):
    """(new bytes, changed, reason): a carry_object(string f) whose f->query_unique() runs before f is known to exist"""
    mask = code_mask(b)
    m = BASE.search(b)
    if not m or not mask[m.start()]:
        return b, 0, "no carry_object definition"
    name = m.group(1)
    depth, i = 1, m.end()
    while i < len(b) and depth:
        if mask[i]:
            depth += (b[i] == 0x7B) - (b[i] == 0x7D)
        i += 1
    uq = None
    for x in re.finditer(rb"\b" + name + rb"\s*->\s*query_unique\s*\(", b[m.end():i]):
        if mask[m.end() + x.start()]:
            uq = m.end() + x.start()
            break
    if uq is None:
        return b, 0, "no query_unique() in it"
    before = b[m.end():uq]
    if re.search(rb"load_object\s*\(\s*" + name + rb"\s*\)|file_size\s*\(\s*" + name + rb"\b|find_object\s*\(\s*" + name + rb"\b", before):
        return b, 0, "already tests the file"
    ls = b.rfind(b"\n", 0, uq) + 1
    line = b[ls:b.index(b"\n", ls) + 1]
    indent = re.match(rb"[ \t]*", line).group(0)
    if not re.match(rb"if\b", line[len(indent):]):
        return b, 0, "HAND: the first query_unique() is not at the start of an if line"
    eol = b"\r\n" if line.endswith(b"\r\n") else b"\n"
    guard = indent + b"if (!objectp(load_object(" + name + b"))) return 0;   // a missing file: " + name + b"->query_unique() raises" + eol
    return b[:ls] + guard + b[ls:], 1, ""


UNEW = re.compile(rb"(?m)^[ \t]*object[ \t]+unew[ \t]*\([^)]*\)[ \t\r\n]*\{")
UNEW_Q = re.compile(rb'(?m)^(?P<ind>[ \t]*)(?P<decl>int[ \t]+)?i[ \t]*=[ \t]*ob->query\("unique"\)(?P<rest>[^;]*);')


def fix_unew(b):
    """(new bytes, changed, reason): unew() that queries `ob` before knowing new() found a file"""
    mask = code_mask(b)
    m = UNEW.search(b)
    if not m or not mask[m.start()]:
        return b, 0, "no unew definition"
    depth, i = 1, m.end()
    while i < len(b) and depth:
        if mask[i]:
            depth += (b[i] == 0x7B) - (b[i] == 0x7D)
        i += 1
    q = None
    for x in UNEW_Q.finditer(b, m.end(), i):
        if mask[x.start()]:
            q = x
            break
    if q is None:
        return b, 0, "no ob->query(\"unique\") in it"
    if re.search(rb"if\s*\(\s*!\s*ob\s*\)\s*return|objectp\s*\(\s*ob\s*\)", b[m.end():q.start()]):
        return b, 0, "already guarded"
    eol = b"\r\n" if b[q.start():q.end() + 2].endswith(b"\r\n") or b"\r\n" in b[q.start():q.end() + 40] else b"\n"
    ind = q.group("ind")
    guard = (ind + b"// new() of a missing file returns 0; the query below would raise call_other() Bad argument 1 and kill" + eol +
             ind + b"// the caller (carry_object() in an NPC's create())" + eol +
             ind + b"if (!ob) return ob;" + eol + eol)
    if q.group("decl"):
        # `int i = ob->query("unique"), j, k;`  ->  `int i, j, k;` here, the assignment after the guard
        rest = q.group("rest").strip()           # `, j, k`
        decl = ind + b"int i" + (rest if rest.startswith(b",") else b"") + b";"
        stmt_at = b.find(b"\n", q.end()) + 1
        # the first statement after the declarations is `if (!i) return ob;`: put the guard and the assignment before it
        nxt = re.compile(rb"(?m)^[ \t]*if[ \t]*\([ \t]*![ \t]*i[ \t]*\)").search(b, q.end(), i)
        if not nxt:
            return b, 0, "HAND: no `if (!i)` after the declarations"
        out = (b[:q.start()] + decl + b[q.end():nxt.start()] + guard + ind + b'i = ob->query("unique");' + eol + b[nxt.start():])
        return out, 1, ""
    return b[:q.start()] + guard + b[q.start():], 1, ""


def main():
    args = sys.argv[1:]
    apply, listing, base, unew, macro, newm = "--apply" in args, "--list" in args, "--base" in args, "--unew" in args, "--macro" in args, "--new" in args
    macro = macro or newm
    tot = files = 0
    for slug in [a for a in args if not a.startswith("--")]:
        work = f"{REPO}/libs/{slug}/work"
        if slug == "longyunmeng_binary" or not os.path.isdir(work) or os.path.exists(f"{work}/.git"):
            continue
        n_lib = 0
        lib = None
        if macro:
            import lpc_scan_callout_targets as resolver            # noqa: E402  (the macro resolver: Lib.literal())
            lib = resolver.Lib(slug)
        for dp, dn, fn in os.walk(work):
            dn.sort()
            if SKIP.search(dp[len(work):] + "/"):
                continue
            for f in sorted(fn):
                if not f.endswith(".lpc"):
                    continue
                p = os.path.join(dp, f)
                b = open(p, "rb").read()
                if not (base or unew) and b"carry_object" not in b and not newm:
                    continue
                if newm and b"->" not in b:
                    continue
                rel = p[len(work):]
                if base or unew:
                    if (b"query_unique" if base else b"unew") not in b:
                        continue
                    out, changed, why = (fix_base if base else fix_unew)(b)
                    if changed:
                        n_lib += 1
                        files += 1
                        print(f"FIX   {slug} {rel}")
                        if apply:
                            open(p, "wb").write(out)
                    elif listing and why.startswith("HAND"):
                        print(f"HAND  {slug} {rel}  ({why})")
                    continue
                if macro:
                    out, sites, why = fix_chain(lib, work, rel, b, newm)
                else:
                    out, sites, why = fix(work, rel, b)
                if not macro and why and CALL.search(b):
                    if listing:
                        print(f"LEFT  {slug} {rel}  ({why})")
                    continue
                if sites:
                    n_lib += len(sites)
                    files += 1
                    if listing:
                        for s in sites:
                            print(f"FIX   {slug} {rel}  {s}")
                    if apply:
                        open(p, "wb").write(out)
        if n_lib:
            tot += n_lib
            print(f"{slug}: {n_lib} site(s)")
    print(f"{tot} site(s) in {files} file(s)" + ("" if apply else " (plan only; --apply writes)"))


if __name__ == "__main__":
    main()
