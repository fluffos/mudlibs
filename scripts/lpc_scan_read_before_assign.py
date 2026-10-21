#!/usr/bin/env python3
"""scripts/lpc_scan_read_before_assign.py [--twins] [SLUG...]

An `object` local whose FIRST mention after the declaration is a read that raises on 0 (KB 06 section 7.346): `userp(v)`, `living(v)`, `v->f()`,
`present(x, v)`, `environment(v)`, `wizardp(v)`, `destruct(v)` ...  The assignment is missing, comes later, or a line was lost from the copy:
the `if (userp(target) && target->query("age") < 18)` a coder pasted above the line that fetches `target` (ccast, ssteal, jji, pperform of the
sjsh family), `ob = this_player();` gone from the `ask_me()` of four derived libs, `fan = load_object(...)` gone from the duel stand `under.lpc`
of 16 libs.  The old driver answered 0 for `0->f()` and `userp(0)`; this one raises.

Every tracked `.lpc` / `.c` outside wizard, backup and doc directories is scanned (comments and strings masked); prints
`HIT<TAB>slug<TAB>file<TAB>function<TAB>var<TAB>line<TAB>context`.  Many hits are NOT bugs: a variable assigned later in the same loop (`genmap.lpc`
`cr`, carried to the next pass), one assigned in the other branch of an `if` / `else`, a function that returns first.  Read the function.
  --twins   after the scan, look in the other libs for the same file whose copy of the function equals ours plus ONE statement `var = expr;`
            (comments ignored): a line lost from the copy.  Prints `FIX<TAB>slug<TAB>file<TAB>function<TAB>var<TAB>twin<TAB>the statement<TAB>after: previous line`;
            the statement goes in at that place (scripts do not edit: read the twin's function first)."""
import collections
import os
import re
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from lpc_fix_void_return import code_mask  # noqa: E402

GITLINKS = {"nt7", "xkx100utf8", "fy2005", "nightmare3", "residuum", "sanguozhi", "oxidus", "deadsouls_fluffos"}
SKIP = re.compile(r"/(u|w|wiz|wizard|wizards|open|players|backup|backups|old|bak|log|data|doc|example|examples|realms|test|tmp|raw)/|[-_.](bak|old)/")
FUNC = re.compile(rb"(?m)^[ \t]*(?:[a-z]+[ \t*]+)*([A-Za-z_]\w*)[ \t]*\(([^)]*)\)[ \t\r\n]*\{")
DECL = re.compile(rb"(?m)^[ \t]*object[ \t]+([^;(=]*?(?:,[^;(]*?)*);")
RD = r"(?:userp|living|interactive|wizardp|environment|file_name|base_name|all_inventory|first_inventory|query_idle|destruct|geteuid|getuid)"
NOT_FUNC = (b"if", b"while", b"for", b"switch", b"foreach", b"catch", b"return", b"sizeof")


def functions(code):
    """(name, params, body, offset of the body start, offset of the body end)"""
    for m in FUNC.finditer(code):
        if m.group(1) in NOT_FUNC:
            continue
        depth, i = 1, m.end()
        while i < len(code) and depth:
            depth += (code[i] == 0x7B) - (code[i] == 0x7D)
            i += 1
        yield m.group(1).decode(), m.group(2), code[m.end():i - 1], m.end(), i


def masked(b):
    mask = code_mask(b)
    return bytes(c if mask[i] else 32 for i, c in enumerate(b))


def hits(b):
    code = masked(b)
    for name, params, body, off, _ in functions(code):
        pnames = set(re.findall(rb"([A-Za-z_]\w*)\s*(?:,|$)", params.strip()))
        for dm in DECL.finditer(body):
            if b"(" in dm.group(0):
                continue
            for v in dm.group(1).split(b","):
                v = v.strip().lstrip(b"*").strip()
                if not re.fullmatch(rb"[A-Za-z_]\w*", v) or v in pnames:
                    continue
                rest = body[dm.end():]
                m = re.search(rb"\b" + v + rb"\b", rest)
                if not m:
                    continue
                after = rest[m.end():m.end() + 6]
                before = rest[max(0, m.start() - 24):m.start()]
                if re.match(rb"\s*(=[^=]|\+=|-=)", after):
                    continue
                if re.search(rb"&\s*$", before) or re.search(rb"foreach\s*\([^)]*$", before) or re.search(rb"sscanf\s*\([^;]*$", before):
                    continue
                if re.match(rb"\s*->", after) or re.search(rb"\b" + RD.encode() + rb"\s*\(\s*$", before) or re.search(rb"present\s*\([^,;]*,\s*$", before):
                    line = b[:off + dm.end() + m.start()].count(b"\n") + 1
                    ctx = re.sub(rb"\s+", b" ", rest[max(0, m.start() - 40):m.end() + 40]).decode("latin-1").strip()[:90]
                    yield name, v.decode(), line, ctx


def norm(s):
    return re.sub(rb"\s+", b"", s)


def twins(found):
    out = subprocess.run(["git", "ls-files", "-z", "--", "libs"], cwd=REPO, capture_output=True).stdout
    byrel = collections.defaultdict(list)
    for p in out.split(b"\0"):
        m = re.match(rb"libs/([^/]+)/work(/.*)", p) if p else None
        if m:
            byrel[m.group(2).decode("utf-8", "surrogateescape")].append(m.group(1).decode())
    seen = set()
    for slug, f, func, v in found:
        if (slug, f, func, v) in seen or re.search(r"/\d+\.lpc$", f):
            continue
        seen.add((slug, f, func, v))
        mine = open(f"{REPO}/libs/{slug}/work{f}", "rb").read()
        fm = {n: (bs, be) for n, _, _, bs, be in functions(masked(mine))}
        if func not in fm:
            continue
        mynorm = norm(masked(mine)[fm[func][0]:fm[func][1] - 1])
        vb = v.encode()
        for other in byrel.get(f, []):
            if other == slug or other in GITLINKS:
                continue
            try:
                tw = open(f"{REPO}/libs/{other}/work{f}", "rb").read()
            except OSError:
                continue
            tcode = masked(tw)
            ft = {n: (bs, be) for n, _, _, bs, be in functions(tcode)}
            if func not in ft:
                continue
            bs, be = ft[func]
            body = tcode[bs:be - 1]
            for m in re.finditer(rb"(?m)^[ \t]*" + vb + rb"[ \t]*=[^=;]*;[ \t]*\r?$", body):
                cut = body[:m.start()] + body[m.end():]
                if norm(cut) == mynorm:
                    prev = body[:m.start()].rstrip().split(b"\n")[-1].strip().decode("utf-8", "replace")[:60]
                    print(f"FIX\t{slug}\t{f}\t{func}\t{v}\t{other}\t{tw[bs + m.start():bs + m.end()].strip().decode('utf-8', 'replace')}\tafter: {prev}")
                    break
            else:
                continue
            break


def main():
    args = sys.argv[1:]
    want_twins = "--twins" in args
    libs = [a for a in args if not a.startswith("--")] or sorted(d for d in os.listdir(f"{REPO}/libs") if os.path.isdir(f"{REPO}/libs/{d}/work"))
    found = []
    n = 0
    for slug in libs:
        if slug in GITLINKS:
            continue
        out = subprocess.run(["git", "ls-files", "-z", "--", f"libs/{slug}/work"], cwd=REPO, capture_output=True).stdout
        for rel in (p.decode("utf-8", "surrogateescape") for p in out.split(b"\0") if p):
            if not rel.endswith((".lpc", ".c")):
                continue
            inner = rel[len(f"libs/{slug}/work"):]
            if SKIP.search(inner):
                continue
            try:
                data = open(f"{REPO}/{rel}", "rb").read()
            except OSError:
                continue
            for func, v, line, ctx in hits(data):
                n += 1
                found.append((slug, inner, func, v))
                print(f"HIT\t{slug}\t{inner}\t{func}\t{v}\t{line}\t{ctx}")
    print(f"{n} hit(s)", file=sys.stderr)
    if want_twins:
        twins(found)


if __name__ == "__main__":
    main()
