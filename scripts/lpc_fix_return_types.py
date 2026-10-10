#!/usr/bin/env python3
"""scripts/lpc_fix_return_types.py [--apply] SLUG [DIAGNOSTICS.tsv]

Two return-type warnings from the lpc_warnings.py diagnostics list (default /tmp/lpcw-SLUG/diagnostics.tsv):

  Function F inherited from 'X' does not match current function in return type ( void vs int )
      for the driver applies whose value the driver ignores (create, init, reset): the leaf's `int F(` becomes
      `void F(`, and `return 0;` / `return 1;` / `return;` in its body become `return;`.  A body returning anything
      else (`return notify_fail(...)`, a variable) is listed.
  Previous function prototype for F does not match current function in return type ( A vs B )
      the prototype is wrong about its own file's definition: the prototype takes the definition's type.

Everything else (a leaf that really returns a value where the base says void) is listed.  Binary-safe."""
import importlib.util
import os
import re
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
spec = importlib.util.spec_from_file_location("lw", os.path.join(REPO, "scripts", "lpc_warnings.py"))
lw = importlib.util.module_from_spec(spec)
argv, sys.argv = sys.argv, ["lpc_warnings.py"]
spec.loader.exec_module(lw)
sys.argv = argv

args = [a for a in sys.argv[1:] if not a.startswith("--")]
apply_ = "--apply" in sys.argv
slug = args[0]
tsv = args[1] if len(args) > 1 else f"/tmp/lpcw-{slug}/diagnostics.tsv"
work = os.path.join(REPO, "libs", slug, "work")
APPLIES = {"create", "init", "reset"}
INH = re.compile(r"Function (\w+) inherited from '([^']+)' does not match current function in return type \( void vs int \)")
PRO = re.compile(r"Previous function prototype for (\w+) does not match current function in return type \( (.+?) vs (.+?) \)")

jobs = {}
for row in open(tsv, encoding="utf-8", errors="replace"):
    f = row.rstrip("\n").split("\t")
    if len(f) < 5:
        continue
    m = INH.match(f[4]) or PRO.match(f[4])
    if m:
        jobs.setdefault(f[0], []).append((int(f[1]), m))
fixed = listed = 0
for path, items in sorted(jobs.items()):
    p = work + path
    src = open(p, "rb").read().decode("latin-1")
    masked = lw.mask(src)
    edits = []
    for ln, m in items:
        name = m.group(1)
        if m.re is INH:
            if name not in APPLIES:
                listed += 1
                print(f"READ {path}:{ln}: {name}() returns int where {m.group(2)} says void")
                continue
            h = re.search(r"(?m)^([ \t]*(?:(?:public|protected|private|nomask|varargs|static)[ \t]+)*)int([ \t]+\**[ \t]*"
                          + name + r"[ \t]*\()", masked)
            if not h:
                listed += 1
                print(f"READ {path}:{ln}: no `int {name}(` header found")
                continue
            ob = masked.find("{", h.end())
            semi = masked.find(";", h.end())
            if ob < 0 or (0 <= semi < ob):
                listed += 1
                print(f"READ {path}:{ln}: `{name}` header without a body")
                continue
            cb = lw.find_open  # noqa (keep the import used)
            depth, i = 0, ob
            while i < len(masked):
                if masked[i] == "{":
                    depth += 1
                elif masked[i] == "}":
                    depth -= 1
                    if depth == 0:
                        break
                i += 1
            body = masked[ob:i]
            rets = list(re.finditer(r"\breturn\b([^;]*);", body))
            if any(r.group(1).strip() not in ("", "0", "1") for r in rets):
                listed += 1
                print(f"READ {path}:{ln}: {name}() returns a value: "
                      + "; ".join(src[ob + r.start():ob + r.end()].strip() for r in rets
                                  if r.group(1).strip() not in ("", "0", "1"))[:90])
                continue
            edits.append((h.start(1) + len(h.group(1)), h.start(1) + len(h.group(1)) + 3, "void"))
            for r in rets:
                if r.group(1).strip():
                    edits.append((ob + r.start(), ob + r.end(), "return;"))
            fixed += 1
            print(f"FIX  {path}:{ln}: int {name}() -> void{' (' + str(len(rets)) + ' return)' if rets else ''}")
        else:
            proto_t, def_t = m.group(2).strip(), m.group(3).strip()
            protos = list(re.finditer(r"(?m)^([ \t]*(?:(?:public|protected|private|nomask|varargs|static)[ \t]+)*)("
                                      + re.escape(proto_t).replace(r"\ ", r"\s*") + r")([ \t]+\**[ \t]*" + name
                                      + r"[ \t]*\([^;{)]*\)[ \t]*;)", masked))
            if len(protos) != 1 or not re.fullmatch(r"[\w ]+\**|[\w]+ \*", def_t):
                listed += 1
                print(f"READ {path}:{ln}: prototype of {name}() says {proto_t}, definition {def_t} "
                      f"({len(protos)} prototype line(s) matched)")
                continue
            q = protos[0]
            edits.append((q.start(2), q.end(2), def_t))
            fixed += 1
            print(f"FIX  {path}:{ln}: prototype {proto_t} {name}() -> {def_t}")
    if edits and apply_:
        for a, b, rep in sorted(edits, reverse=True):
            src = src[:a] + rep + src[b:]
        open(p, "wb").write(src.encode("latin-1"))
print(f"{fixed} fixed, {listed} to read" + ("" if apply_ else " (dry run)"))
