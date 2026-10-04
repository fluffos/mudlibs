#!/usr/bin/env python3
"""scripts/lpc_move_decl.py SLUG [--apply]

For the unused-local diagnostics scripts/lpc_warnings.py leaves alone because the name also occurs inside an
#if/#ifdef branch of the same function (a branch this driver does not compile), move the declaration into the first
such branch instead of deleting it.  Prints the plan; with --apply edits the files (binary mode, line endings kept).
Names it cannot place are listed as "NAME NOT IN A BRANCH" / "NO DECL FOUND" for a hand edit.  Diagnostics come from
/tmp/lpcw-SLUG/diagnostics.tsv (written by lpc_warnings.py)."""
import os, re, sys, collections
REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
slug = sys.argv[1]; apply_ = "--apply" in sys.argv
work = f"{REPO}/libs/{slug}/work"
rows = [l.rstrip("\n").split("\t") for l in open(f"/tmp/lpcw-{slug}/diagnostics.tsv", encoding="utf-8", errors="replace")]
want = collections.defaultdict(set)      # file -> {(line, name)}
for p in rows:
    if len(p) >= 5 and p[3] == "warning":
        m = re.match(r"Unused local variable '(\w+)'", p[4])
        if m: want[p[0]].add((int(p[1]), m.group(1)))

def mask(t):
    t = re.sub(r"/\*.*?\*/", lambda m: re.sub(r"[^\n]", " ", m.group(0)), t, flags=re.S)
    t = re.sub(r'"(?:\\.|[^"\\\n])*"', lambda m: '"' + " " * (len(m.group(0)) - 2) + '"', t)
    return re.sub(r"//[^\n]*", lambda m: " " * len(m.group(0)), t)

DECL = re.compile(r"^(\s*)((?:(?:nosave|static|private|protected|varargs)\s+)*(?:int|string|object|mixed|mapping|float|function|status|buffer|class\s+\w+)\s*(?:\*\s*)?)((?:\*?\s*\w+\s*(?:=[^,;]*)?\s*,\s*)*\*?\s*\w+\s*(?:=[^,;]*)?)\s*;(.*)$")

plans = []
for f, items in sorted(want.items()):
    path = work + f
    try: raw = open(path, "rb").read().decode("latin-1")
    except OSError: continue
    nl = "\r\n" if "\r\n" in raw else "\n"
    lines = raw.split(nl)
    mlines = mask(raw).split(nl)
    for fnend, name in sorted(items):
        # function extent: walk back from fnend to the function's opening brace line (depth 0 start)
        end = fnend - 1
        depth = 0; start = None
        for i in range(end, -1, -1):
            depth += mlines[i].count("}") - mlines[i].count("{")
            if depth < 0 and False: pass
        # locate declaration line: nearest line above fnend containing a decl with the name, not inside #if
        decl_i = None
        for i in range(end, max(-1, end - 400), -1):
            m = DECL.match(mlines[i])
            if m and re.search(r"\b" + name + r"\b", m.group(3)):
                decl_i = i; break
        if decl_i is None:
            plans.append((f, name, "NO DECL FOUND")); continue
        # first #if line after decl and before fnend whose branch mentions the name
        cond_i = None
        stack = []
        for i in range(decl_i + 1, end + 1):
            s = mlines[i].strip()
            if re.match(r"#\s*if", s): stack.append([i, None])
            elif re.match(r"#\s*else", s) or re.match(r"#\s*elif", s):
                if stack: stack[-1][1] = i
            elif re.match(r"#\s*endif", s):
                if stack: stack.pop()
            elif re.search(r"\b" + name + r"\b", mlines[i]) and stack:
                outer = stack[0]
                cond_i = outer[1] if outer[1] is not None else outer[0]
                break
        if cond_i is None:
            plans.append((f, name, "NAME NOT IN A BRANCH")); continue
        plans.append((f, name, (decl_i + 1, cond_i + 1)))

by_file = collections.defaultdict(list)
for f, name, r in plans:
    if isinstance(r, str): print(f"{f}: {name}: {r}"); continue
    by_file[f].append((name, *r))
for f, lst in sorted(by_file.items()):
    for name, d, c in lst: print(f"{f}: {name}: decl line {d} -> into branch at line {c}")
if not apply_:
    sys.exit()
for f, lst in sorted(by_file.items()):
    path = work + f
    raw = open(path, "rb").read().decode("latin-1")
    nl = "\r\n" if "\r\n" in raw else "\n"
    lines = raw.split(nl)
    # group by declaration line; one declaration may feed several branches
    bydecl = collections.defaultdict(lambda: collections.defaultdict(list))
    for name, d, c in lst: bydecl[d][c].append(name)
    for d, branches in sorted(bydecl.items(), key=lambda kv: -kv[0]):
        m = DECL.match(lines[d - 1])
        indent, typ, vars_, rest = m.group(1), m.group(2), m.group(3), m.group(4)
        parts = [v.strip() for v in re.split(r",", vars_)]
        allmoved = {n for ns in branches.values() for n in ns}
        keep = [v for v in parts if re.sub(r"[\*\s]|=.*", "", v) not in allmoved]
        typ_clean = typ.rstrip()
        if typ_clean.endswith("*"):                       # the first declarator's star was swallowed by the type
            typ_clean = typ_clean[:-1].rstrip()
            parts[0] = "*" + parts[0].lstrip()
            keep = [v for v in parts if re.sub(r"[\*\s]|=.*", "", v) not in allmoved]
        for c in sorted(branches, reverse=True):
            moved = [v for v in parts if re.sub(r"[\*\s]|=.*", "", v) in branches[c]]
            lines.insert(c, f"{indent}{typ_clean} {', '.join(moved)};")
        if keep:
            lines[d - 1] = f"{indent}{typ_clean} {', '.join(keep)};{rest}"
        else:
            del lines[d - 1]
    open(path, "wb").write(nl.join(lines).encode("latin-1"))
    print("edited", f)
