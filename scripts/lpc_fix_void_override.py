#!/usr/bin/env python3
"""scripts/lpc_fix_void_override.py SLUG [--apply] [--only SUBSTR ...]

Fix `Function F inherited from 'X' does not match current function in return type ( void vs int )` (KB 04 section 6.10):
a leaf file declares `int init()` / `int reset()` / `create()` (old MudOS: no type means int) and never returns a
value, while the base class declares the hook `void`.  Only init(), reset(), create() and setup() are touched (nothing
reads their result); `clean_up()` returns a value the driver does read, and any other function may have callers.  The leaf's head becomes `void F(...)` and any `return 0;` / `return 1;`
inside the body becomes `return;`; the driver ignores a hook's return value, and a body that falls off its end returns 0
either way.  Only the (inherited void, current int) pair is handled; other pairs (`object vs int`, ...) are listed for a
hand edit, as is a body that returns a computed value (the head is then left alone).  Diagnostics come from
/tmp/lpcw-SLUG/diagnostics.tsv; without --apply it prints the plan.  Edits are byte-exact (line endings kept)."""
import collections
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from lpc_src import MODS, mask, read, top_level_defs  # noqa: E402

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
a = sys.argv[1:]
if not a or a[0].startswith("--"):
    sys.exit(__doc__)
slug = a[0]
apply_ = "--apply" in a
only = a[a.index("--only") + 1:] if "--only" in a else []
W = f"{REPO}/libs/{slug}/work"

MSG = re.compile(r"^Function (\w+) inherited from '[^']+' does not match current function in return type \( (\w+) vs (\w+) \)$")
HOOKS = {"init", "reset", "create", "setup"}     # driver applies: their return value is never read
TYPE_WORDS = ("int", "void", "status", "mixed", "string", "object", "mapping", "float", "function")

rows = [l.rstrip("\n").split("\t") for l in open(f"/tmp/lpcw-{slug}/diagnostics.tsv", encoding="utf-8", errors="replace")]
want = collections.defaultdict(set)
manual = []
for f, ln, col, sev, msg in rows:
    m = MSG.match(msg)
    if not m or (only and not any(o in f for o in only)):
        continue
    fn, inh, cur = m.groups()
    if (inh, cur) == ("void", "int") and fn in HOOKS:
        want[f].add((fn, int(ln)))
    else:
        manual.append((f, ln, fn, f"({inh} vs {cur})"))

done = 0
for f, items in sorted(want.items()):
    path = W + f
    text = read(path)
    if text is None:
        continue
    m_ = mask(text)
    edits = []
    for fn, ln in sorted(items):
        defs = top_level_defs(text, fn)
        cand = [d for d in defs if text.count("\n", 0, d[0]) + 1 == ln] or (defs if len(defs) == 1 else [])
        if not cand:
            manual.append((f, ln, fn, "definition not found at top level" if not defs else "several definitions"))
            continue
        i, j, k = cand[0]
        e = k + 1
        while m_[e] in " \t\r\n":
            e += 1
        depth, p = 0, e
        while p < len(m_):
            depth += (m_[p] == "{") - (m_[p] == "}")
            if depth == 0:
                break
            p += 1
        body = m_[e:p + 1]
        rets = list(re.finditer(r"\breturn\b[ \t]*([^;]*);", body))
        valued = [mm for mm in rets if mm.group(1).strip()]
        if any(not re.fullmatch(r"-?\d+|\(\s*-?\d+\s*\)|TRUE|FALSE", mm.group(1).strip()) for mm in valued):
            manual.append((f, ln, fn, "returns a computed value"))
            continue
        lo = max(0, i - 80)
        pre = [(mm.group(0), lo + mm.start()) for mm in re.finditer(r"[A-Za-z_]\w*", m_[lo:i])]
        k2 = len(pre) - 1
        while k2 >= 0 and pre[k2][0] in MODS:
            k2 -= 1
        typed = k2 >= 0 and pre[k2][0] in TYPE_WORDS and "\n\n" not in m_[pre[k2][1]:i]
        if typed and pre[k2][0] != "int":
            manual.append((f, ln, fn, f"declared {pre[k2][0]}"))
            continue
        for mm in valued:
            edits.append((e + mm.start(), e + mm.end(), "return;"))
        edits.append((pre[k2][1], pre[k2][1] + 3, "void") if typed else (i, i, "void "))
        done += 1
        print(f"{'FIX ' if apply_ else 'plan'} {f}:{ln} {fn}: -> void ({len(valued)} flag return(s) dropped)")
    if apply_ and edits:
        out = text
        for s0, e0, rep in sorted(edits, reverse=True):
            out = out[:s0] + rep + out[e0:]
        open(path, "wb").write(out.encode("latin-1"))
for f, ln, fn, why in manual:
    print(f"MANUAL {f}:{ln} {fn}: {why}")
print(f"{done} function(s) {'fixed' if apply_ else 'planned'}; {len(manual)} left for a hand edit")
