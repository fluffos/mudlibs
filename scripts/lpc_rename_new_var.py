#!/usr/bin/env python3
"""scripts/lpc_rename_new_var.py [--apply] [SLUG...]      (no SLUG: every vendored lib)

`new` is a reserved word in this driver (KB 04 section 6.x): a file that declares it as a variable (`object *inv, new;`, the xkx
`do_clone()` of tang / meng-zhu / xingtang, the Fengyun `ghostcurse.lpc`) does not compile at all, so the NPC or skill behind it
never existed.  In every file that declares a variable named `new`, each `new` that is not a call (`new(` / `new (`) becomes
`new_ob`.  Comments, strings and `#if 0` blocks are left alone; a file that already uses `new_ob` is listed and left.  Edits are
byte-exact.  Without --apply it prints the plan."""
import os
import re
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from lpc_src import mask  # noqa: E402

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
args = sys.argv[1:]
apply_ = "--apply" in args
slugs = [a for a in args if a != "--apply"]
DECL = re.compile(r"\b(?:object|string|int|mixed|mapping|float|function)\b[^;(){}]*?(?<![\w>.])new\s*(?:[;,=]|\[)")
USE = re.compile(r"(?<![\w$])new\b(?!\s*\()")
pathspec = [f"libs/{s}/work" for s in slugs] if slugs else ["libs/"]
files = subprocess.run(["git", "-C", REPO, "grep", "-l", "-z", "-E", r"\bnew\s*[;,=]", "--", *pathspec],
                       capture_output=True).stdout.decode("utf-8", "surrogateescape").split("\0")
total = nfiles = 0
libs = set()
for rel in files:
    if not rel.endswith((".lpc", ".h", ".c")):
        continue
    path = f"{REPO}/{rel}"
    text = open(path, "rb").read().decode("latin-1")
    mk = mask(text)
    if not DECL.search(mk):
        continue
    if re.search(r"\bnew_ob\b", mk):
        print(f"{rel}: already uses new_ob: left")
        continue
    hits = [m.start() for m in USE.finditer(mk)]
    if not hits:
        continue
    out = text
    for pos in reversed(hits):
        out = out[:pos] + "new_ob" + out[pos + 3:]
    total += len(hits)
    nfiles += 1
    libs.add(rel.split("/")[1])
    print(f"{rel}: {len(hits)} use(s) of the variable `new` -> new_ob")
    if apply_:
        open(path, "wb").write(out.encode("latin-1"))
print(f"total: {total} in {nfiles} file(s) of {len(libs)} lib(s)" + ("" if apply_ else " (plan; --apply writes)"))
