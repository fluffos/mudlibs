#!/usr/bin/env python3
"""scripts/lpc_guard_carry_object.py SLUG... [--apply] [--list] [--base | --unew]

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


def block(prefix, eol, arg, call):
    """the guarded statement in the layout the formatter keeps (so a lib normalized at HEAD stays normalized):
         {                                  prefix is what precedes the statement on its line, an `if (...)`, an `else`
           object carried_ob = carry_object(ARG);   or nothing; the opening brace joins it, the body is indented two
           if (carried_ob) carried_ob->CALL;        beyond the line's own indent
         }"""
    indent = prefix[:len(prefix) - len(prefix.lstrip(b" \t"))]
    return (b"{" + eol + indent + b"  object " + VAR + b" = carry_object(" + arg + b");" + eol +
            indent + b"  if (" + VAR + b") " + VAR + b"->" + call + b";" + eol + indent + b"}")


def missing(work, rel_file, dirflag, path):
    p = path
    if dirflag:
        p = os.path.dirname(rel_file) + "/" + p
    if not p.startswith("/"):
        return False                          # relative to the cwd at run time: cannot tell
    p = re.sub(r"\.(lpc|c)$", "", p)
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
    apply, listing, base, unew = "--apply" in args, "--list" in args, "--base" in args, "--unew" in args
    tot = files = 0
    for slug in [a for a in args if not a.startswith("--")]:
        work = f"{REPO}/libs/{slug}/work"
        if slug == "longyunmeng_binary" or not os.path.isdir(work) or os.path.exists(f"{work}/.git"):
            continue
        n_lib = 0
        for dp, dn, fn in os.walk(work):
            dn.sort()
            if SKIP.search(dp[len(work):] + "/"):
                continue
            for f in sorted(fn):
                if not f.endswith(".lpc"):
                    continue
                p = os.path.join(dp, f)
                b = open(p, "rb").read()
                if not (base or unew) and b"carry_object" not in b:
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
                out, sites, why = fix(work, rel, b)
                if why and CALL.search(b):
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
