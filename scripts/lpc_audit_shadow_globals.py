#!/usr/bin/env python3
"""scripts/lpc_audit_shadow_globals.py [REV-RANGE ...]

Lists initialized local declarations that a commit deleted while the file still declares a global of the same name
(`int maxpages = 20;` inside a function, next to the file-level `int maxpages;`).  Such a local is reported unused by
the driver and dropped by `lpc_warnings.py --fix` (which now lists it instead), but the author nearly always meant to
set the global: the type in front made it a new local, so the global keeps 0.  Default range: the compile-warnings
commits since 2026-10-02.  Prints FILE:LINE  removed text  -- one line per hit, for a hand look."""
import importlib.util
import os
import re
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
os.chdir(REPO)
spec = importlib.util.spec_from_file_location("lw", "scripts/lpc_warnings.py")
lw = importlib.util.module_from_spec(spec)
argv, sys.argv = sys.argv, ["lpc_warnings.py"]
spec.loader.exec_module(lw)
sys.argv = argv

if len(sys.argv) > 1:
    commits = []
    for r in sys.argv[1:]:
        commits += subprocess.run(["git", "rev-list", r], capture_output=True, text=True).stdout.split()
else:
    commits = subprocess.run(["git", "log", "--since=2026-10-02", "--format=%H", "--grep=compile warnings",
                              "--grep=compile-warnings", "--grep=warnings pass", "--grep=every compile warning"],
                             capture_output=True, text=True).stdout.split()

DECL = re.compile(r"^\s*(?:(?:nosave|static)\s+)?" + lw.TYPES + r"\b(.*);")
seen = set()
for c in commits:
    diff = subprocess.run(["git", "show", "-U0", "--format=", c, "--", "*.lpc", "*.h"],
                          capture_output=True).stdout.decode("latin-1")
    path = None
    added = {}
    cur = None
    for line in diff.split("\n"):
        if line.startswith("+++ b/"):
            cur = line[6:]
        elif cur and line.startswith("+") and not line.startswith("+++"):
            added.setdefault(cur, []).append(line[1:])
    for line in diff.split("\n"):
        if line.startswith("+++ "):
            path = line[6:] if line.startswith("+++ b/") else None
            globs = None
            continue
        if not path or not line.startswith("-") or line.startswith("---"):
            continue
        m = DECL.match(line[1:])
        if not m or "=" not in m.group(1):
            continue
        names = set()
        for part in m.group(1).split(","):
            dm = re.match(r"\s*\**\s*([A-Za-z_]\w*)\s*=", part)
            if dm:
                names.add(dm.group(1))
        if not names:
            continue
        if globs is None:
            try:
                src = subprocess.run(["git", "show", f"{c}:{path}"], capture_output=True).stdout.decode("latin-1")
            except Exception:
                src = ""
            globs = lw.file_globals(lw.mask(src))
        # a removed file-level global itself also matches DECL: only count it when the name survives as a global
        hit = {n for n in names & globs
               # a declarator list rewritten (another name dropped) keeps this one on a `+` line
               if not any(re.search(r"(?<![\w>])" + re.escape(n) + r"\s*=(?!=)", a) for a in added.get(path, ()))}
        if hit and (path, line) not in seen:
            seen.add((path, line))
            print(f"{c[:11]} {path}  {line[1:].strip()[:100]}  [{', '.join(sorted(hit))}]")
