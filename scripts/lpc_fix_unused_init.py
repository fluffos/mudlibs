#!/usr/bin/env python3
"""scripts/lpc_fix_unused_init.py SLUG [--apply] [--only SUBSTR ...]

Handle the `Unused local variable` diagnostics that scripts/lpc_warnings.py --fix refuses because the declaration
has an initializer.  A pure initializer deletes the declaration: a literal (`({})`, `([])`, a number, a string) or an
expression built only from variables, operators and the side-effect-free calls in PURE_CALLS (`environment()`,
`this_player()`, `sort_array(...)`, ...).  Any other initializer stays as an expression statement, because the
call may have an effect.  The declaration must be a
single-declarator line whose enclosing block closes at the line the driver reports, so a same-named local in another
function is never touched; anything else is listed as SKIP for a hand edit (multi-declarator lines, locals only used
in an inactive #if branch: scripts/lpc_move_decl.py).  Diagnostics come from /tmp/lpcw-SLUG/diagnostics.tsv, which
lpc_warnings.py writes; without --apply this only prints the plan.  --only restricts it to paths containing a SUBSTR."""
import os, re, sys, collections
REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
slug = sys.argv[1]
apply = "--apply" in sys.argv
only = []
if "--only" in sys.argv:
    only = sys.argv[sys.argv.index("--only") + 1:]
W = f"{REPO}/libs/{slug}/work"
rows = [l.rstrip("\n").split("\t") for l in open(f"/tmp/lpcw-{slug}/diagnostics.tsv", encoding="utf-8", errors="replace")]
TYPE = r"(?:int|string|object|mixed|mapping|float|function|status|buffer|class\s+\w+)"
want = collections.defaultdict(set)
for f, ln, col, sev, msg in rows:
    m = re.match(r"Unused local variable '(\w+)'", msg)
    if m and (not only or any(o in f for o in only)):
        want[f].add((int(ln), m.group(1)))
def strip_code(text):
    """blank out strings, char literals and comments (keeps newlines)"""
    out, i, n = [], 0, len(text)
    while i < n:
        c, two = text[i], text[i:i+2]
        if two == "//":
            j = text.find("\n", i); j = n if j < 0 else j
            out.append(" " * (j - i)); i = j
        elif two == "/*":
            j = text.find("*/", i + 2); j = n if j < 0 else j + 2
            out.append(re.sub(r"[^\n]", " ", text[i:j])); i = j
        elif c == '"' or c == "'":
            q = c; j = i + 1
            while j < n and text[j] != q and text[j] != "\n":
                j += 2 if text[j] == "\\" else 1
            j = min(j + 1, n)
            out.append(re.sub(r"[^\n]", " ", text[i:j])); i = j
        else:
            out.append(c); i += 1
    return "".join(out)

def block_end(clean_lines, k):
    """0-based line index where the block that contains line k closes (None if unbalanced)"""
    depth = 0
    for j in range(k, len(clean_lines)):
        l = clean_lines[j]
        if l.lstrip().startswith("#"):
            continue
        for ch in l:
            if ch == "{": depth += 1
            elif ch == "}":
                depth -= 1
                if depth < 0:
                    return j
    return None

PURE = re.compile(r'^(\(\{\s*\}\)|\(\[\s*\]\)|-?\d+|"[^"]*"|0)$')
PURE_CALLS = set("""environment this_object this_player previous_object all_inventory deep_inventory sizeof time file_name
base_name format_page sort_array capitalize lower_case upper_case member_array keys values copy identify sprintf implode
explode query_ip_name objectp stringp intp mapp arrayp living interactive to_int to_float""".split())

def is_pure(init):
    """literal, or variables/operators/PURE_CALLS only: no assignment, ++/--, ->, closures, other calls"""
    s = init.strip()
    if PURE.match(s):
        return True
    t = re.sub(r'"(?:\\.|[^"\\])*"', '""', s)
    t = re.sub(r"'(?:\\.|[^'\\])+'", "0", t)
    t = t.replace("==", " ").replace("!=", " ").replace("<=", " ").replace(">=", " ")
    if "=" in t or re.search(r"\+\+|--|->|::|\(:|\$|\bcatch\b|\bnew\b", t):
        return False
    return all(m in PURE_CALLS for m in re.findall(r"\b([A-Za-z_]\w*)\s*\(", t))
for f, items in sorted(want.items()):
    path = W + f
    data = open(path, "rb").read().decode("latin-1")
    lines = data.split("\n")
    edits = []
    clean = strip_code(data).split("\n")
    for ln, name in sorted(items, reverse=True):
        decl = re.compile(r'^(\s*)(?:(?:varargs|nosave|static|private|protected)\s+)*' + TYPE + r'\s*\**\s*' + re.escape(name) + r'\s*(?:=\s*(.+?))?\s*;\s*(?://.*)?\r?$')
        found = None
        for k in range(min(ln - 1, len(lines) - 1), max(ln - 400, -1), -1):
            m = decl.match(lines[k])
            if m and block_end(clean, k) == ln - 1:
                found = (k, m); break
        if not found:
            print(f"SKIP {f}:{ln} {name}: no single-declarator line whose block closes at the diagnostic"); continue
        k, m = found
        indent, init = m.group(1), m.group(2)
        cr = "\r" if lines[k].endswith("\r") else ""
        if init is None or is_pure(init):
            edits.append((k, None)); how = "delete"
        else:
            edits.append((k, indent + init.strip() + ";" + cr)); how = "call kept"
        print(f"{'FIX ' if apply else 'plan'} {f}:{k+1} {name}: {how}: {lines[k].strip()[:90]}")
    if apply:
        for k, new in sorted(edits, reverse=True):
            if new is None:
                del lines[k]
            else:
                lines[k] = new
        open(path, "wb").write("\n".join(lines).encode("latin-1"))
