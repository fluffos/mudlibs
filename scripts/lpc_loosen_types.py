#!/usr/bin/env python3
"""LDMud never checked declared types, so its libs hold arrays in `string` variables, users() in an `object`,
and so on.  FluffOS reports those at compile time (`Bad assignment ( string vs mixed * )`, `Value indexed has a
bad type : "object "`) and the file does not load.  It does not check them at run time, so declaring the one
variable `mixed` keeps the behaviour and lets the file compile.

usage: lpc_loosen_types.py SLUG [--apply] FILE...      (driver paths, e.g. /obj/party.lpc)
For each such error it finds the variable on that line (the left side of the assignment, or the name in front of
the `[`), finds its declaration (a local of the enclosing function first, then a global), moves that declarator
out to its own `mixed NAME...;` line, and repeats the compile until nothing changes."""
import os, re, sys, subprocess
REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
args = sys.argv[1:]; apply_ = "--apply" in args; args = [a for a in args if a != "--apply"]
slug, files = args[0], [a for a in args[1:] if a != "--tsv"]
TSV = "--tsv" in args
LIB = f"{REPO}/libs/{slug}"; LPCC = os.path.expanduser("~/src/fluffos/build-debug/bin/lpcc")
TYPES = r"(?:int|string|object|mapping|mixed|float|status|function|closure)"
MODS = r"(?:(?:private|nosave|static|protected|public|nomask|varargs)\s+)*"
ERR = re.compile(r"^(\S+?):(\d+):(\d+): error: (Bad assignment \( .* \)\.|Value indexed has a bad type : \"(?:object|int|string|float) \"|Bad argument 1 to efun (?:explode|implode|sizeof)\(\))", re.M)
def errors(f):
    out = subprocess.run([LPCC, "config.fluffos", f], cwd=LIB, capture_output=True, text=True, errors="replace").stdout
    return [(int(m.group(2)), int(m.group(3)), m.group(4)) for m in ERR.finditer(out) if m.group(1) == f]
def target_name(line, col, kind):
    s = line[:max(col, 1) + 40]
    if kind.startswith("Bad assignment"):
        m = list(re.finditer(r"([A-Za-z_]\w*)\s*(?:\[[^\]]*\])?\s*(?:\+|-)?=(?!=)", line))
        before = [x for x in m if x.start() < col] or m
        return before[-1].group(1) if before else None
    # indexed / bad argument: the identifier in front of the nearest `[` (or the argument) around col
    m = list(re.finditer(r"([A-Za-z_]\w*)\s*\[", line))
    if m:
        best = min(m, key=lambda x: abs(x.end() - col))
        return best.group(1)
    m = re.search(r"(?:explode|implode|sizeof)\s*\(\s*([A-Za-z_]\w*)", line)
    return m.group(1) if m else None
def find_decl(lines, li, name):
    # enclosing function: nearest previous line at column 0 that looks like a function head
    start = 0
    for i in range(li, -1, -1):
        if re.match(r"^" + MODS + r"(?:" + TYPES + r"\s*\**\s*)?[A-Za-z_]\w*\s*\([^;]*$", lines[i]):
            start = i; break
    pat = re.compile(r"^(\s*)(" + MODS + TYPES + r")\b([^;(]*?)\b" + re.escape(name) + r"\b")
    for i in range(start, li + 1):
        if pat.match(lines[i]) and ";" in lines[i]: return i
    for i in range(0, len(lines)):          # global
        if re.match(r"^" + MODS + TYPES + r"\b", lines[i]) and re.search(r"\b" + re.escape(name) + r"\b", lines[i]) \
           and ";" in lines[i] and "(" not in lines[i].split(";")[0]: return i
    return None
def loosen(line, name):
    m = re.match(r"^(\s*)(" + MODS + r")(" + TYPES + r")\b(.*?);(.*)$", line, re.S)
    if not m: return None
    ind, mods, typ, decls, rest = m.groups()
    if typ == "mixed": return None
    parts = [p.strip() for p in decls.split(",")]
    if any("(" in p for p in parts): return None
    hit = [p for p in parts if re.fullmatch(r"\**\s*" + re.escape(name) + r"\b.*", p)]
    if len(hit) != 1: return None
    keep = [p for p in parts if p is not hit[0]]
    moved = re.sub(r"^\**\s*", "", hit[0])
    new = ""
    if keep: new = f"{ind}{mods}{typ} {', '.join(keep)};{rest}"
    newline = f"{ind}{mods}mixed {moved};"
    return (new + "\n" + newline) if keep else (newline + rest)
def loosen_many(line, names):
    m = re.match(r"^(\s*)(" + MODS + r")(" + TYPES + r")\b(.*?);(.*)$", line, re.S)
    if not m: return None
    ind, mods, typ, decls, rest = m.groups()
    parts = [p.strip() for p in decls.split(",")]
    if any("(" in p for p in parts): return None
    def nm(p):
        x = re.match(r"^\**\s*([A-Za-z_]\w*)", p); return x.group(1) if x else None
    hit = [p for p in parts if nm(p) in names]
    if not hit: return None
    keep = [p for p in parts if p not in hit]
    out = []
    if keep: out.append(f"{ind}{mods}{typ} {', '.join(keep)};{rest}")
    moved = [re.sub(r"^\**\s*", "", p) for p in hit]
    out.append(f"{ind}{mods}mixed {', '.join(moved)};" + ("" if keep else rest))
    return out
total = 0
if TSV:
    rows = {}
    ERRK = re.compile(r"^(Bad assignment \( .* \)\.|Value indexed has a bad type : \"(?:object|int|string|float) \"|Bad argument 1 to efun (?:explode|implode|sizeof)\(\))$")
    for line in open(f"/tmp/lpcw-{slug}/diagnostics.tsv", encoding="utf-8", errors="replace"):
        p = line.rstrip("\n").split("\t")
        if len(p) >= 5 and p[3] == "error" and ERRK.match(p[4]):
            rows.setdefault(p[0], []).append((int(p[1]), int(p[2] or 0), p[4]))
    nfiles = 0
    for f, errs in sorted(rows.items()):
        path = LIB + "/work" + f
        if not os.path.isfile(path): continue
        raw = open(path, "rb").read().decode("latin-1"); nl = "\r\n" if "\r\n" in raw else "\n"
        lines = raw.split(nl); bydecl = {}
        for ln, col, kind in errs:
            if ln - 1 >= len(lines): continue
            name = target_name(lines[ln - 1], col, kind)
            if not name: continue
            di = find_decl(lines, ln - 1, name)
            if di is None: continue
            bydecl.setdefault(di, set()).add(name)
        changed = False
        for di in sorted(bydecl, reverse=True):
            new = loosen_many(lines[di], bydecl[di])
            if new is None: continue
            lines[di:di + 1] = new; changed = True; total += len(bydecl[di])
        if changed:
            nfiles += 1
            if apply_: open(path, "wb").write(nl.join(lines).encode("latin-1"))
    print("files", nfiles)
    files = []
for f in files:
    path = LIB + "/work" + f
    for rnd in range(30):
        errs = errors(f)
        if not errs: break
        raw = open(path, "rb").read().decode("latin-1"); nl = "\r\n" if "\r\n" in raw else "\n"
        lines = raw.split(nl); changed = False; done = set()
        for ln, col, kind in sorted(errs, reverse=True):
            name = target_name(lines[ln - 1], col, kind)
            if not name or name in done: continue
            di = find_decl(lines, ln - 1, name)
            if di is None: print(f"  {f}:{ln} {name}: declaration not found"); done.add(name); continue
            new = loosen(lines[di], name)
            if new is None: print(f"  {f}:{di+1} {name}: cannot split `{lines[di].strip()}`"); done.add(name); continue
            print(f"{f}:{di+1}: {name} -> mixed   ({kind[:40]})"); total += 1
            lines[di:di + 1] = new.split("\n"); changed = True; done.add(name)
            break   # line numbers shift: recompile
        if not changed or not apply_: break
        open(path, "wb").write(nl.join(lines).encode("latin-1"))
print("loosened", total)
