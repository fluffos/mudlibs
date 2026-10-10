#!/usr/bin/env python3
"""scripts/lpc_fix_unique_init.py [--apply] SLUG DIAGNOSTICS.tsv

`init() inherited from both /feature/unique.lpc and /feature/attack.lpc (via /inherit/char/npc.lpc)`: an NPC that
inherits both NPC and F_UNIQUE without an init() of its own runs only one parent's init(): either attack.lpc's
(aggression, vendettas, auto-fight) never runs, or unique.lpc's one-copy owner check never does.  This adds
  void init() { <npc scope>::init(); unique::init(); }
at the end of each reported file (the scope is the basename of the `via` program, the leaf's direct inherit).
A file that already defines init() outside comments is listed instead.  Binary-safe."""
import os
import re
import sys

args = [a for a in sys.argv[1:] if not a.startswith("--")]
apply_ = "--apply" in sys.argv
slug, tsv = args[0], args[1]
work = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "libs", slug, "work")
PAT = re.compile(r"init\(\) inherited from both (?:/feature/unique\.lpc and /feature/attack\.lpc \(via (\S+)\)|"
                 r"/feature/attack\.lpc \(via (\S+)\) and /feature/unique\.lpc)")
done = set()
n = 0
for row in open(tsv, encoding="utf-8", errors="replace"):
    f = row.rstrip("\n").split("\t")
    if len(f) < 5:
        continue
    m = PAT.match(f[4])
    if not m or f[0] in done:
        continue
    done.add(f[0])
    scope = os.path.splitext(os.path.basename(m.group(1) or m.group(2)))[0]
    p = work + f[0]
    b = open(p, "rb").read()
    code = re.sub(rb"//[^\n]*", b"", re.sub(rb"/\*.*?\*/", b"", b, flags=re.S))
    if re.search(rb"\b(void|int)\s+init\s*\(\s*\)\s*\{", code):
        print(f"READ {f[0]}: already defines init()")
        continue
    nl = b"\r\n" if b"\r\n" in b else b"\n"
    add = (nl + b"// NPC and F_UNIQUE both define init(): run both (attack.lpc's auto-fight checks, and the one-copy owner check)"
           + nl + b"void init() {" + nl + b"  " + scope.encode() + b"::init();" + nl + b"  unique::init();" + nl + b"}" + nl)
    if not b.endswith(nl):
        b += nl
    n += 1
    print(f"FIX  {f[0]}: {scope}::init(); unique::init();")
    if apply_:
        open(p, "wb").write(b + add)
print(f"{n} fixed" + ("" if apply_ else " (dry run)"))
