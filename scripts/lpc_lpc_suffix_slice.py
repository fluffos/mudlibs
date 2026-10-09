#!/usr/bin/env python3
"""scripts/lpc_lpc_suffix_slice.py [--apply] [SLUG ...]

The `.c` -> `.lpc` rename changed the string in `f[<2..] == ".c"` but not the slice width (KB 03 section 4.2 item 4,
KB 06 section 7.238): `f[<2..<1] == ".lpc"` compares two characters with four and is never true (`!=` always true), so
a file filter keeps nothing or everything, and the suffix strip that follows (`f = f[0..<3]`, two characters) never
runs or cuts `x.lp`.  nitan's taskd rejected every room this way and spun forever in alloc_task().

For every comparison of a fixed-width end slice `X[<n..]` / `X[<n..<1]` (n != 4) with ".lpc", this sets n = 4, and on
the same line and the two after it rewrites the strip of the same variable `X[0..<3]` (or `<2`, `<4`) to `X[0..<5]`.
Anything else in those lines that slices X is listed for a hand look.  Without --apply it prints the plan.  No SLUG:
every vendored lib (gitlink libs are skipped: land those upstream).  Binary-safe."""
import glob
import os
import re
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
args = sys.argv[1:]
apply_ = "--apply" in args
slugs = [a for a in args if not a.startswith("-")]
os.chdir(REPO)
if not slugs:
    slugs = sorted(d for d in os.listdir("libs") if os.path.isdir(f"libs/{d}/work"))

V = rb"([A-Za-z_$][\w$]*(?:\[[^\[\]]*\])?)"       # a name, optionally one index (`$1`, `files[i]`)
CMP1 = re.compile(V + rb"\[<([0-9])\.\.(<1)?\](\s*[!=]=\s*\"\.lpc\")")
CMP2 = re.compile(rb"(\"\.lpc\"\s*[!=]=\s*)" + V + rb"\[<([0-9])\.\.(<1)?\]")


def gitlink(slug):
    out = subprocess.run(["git", "ls-files", "-s", f"libs/{slug}/work"], capture_output=True).stdout
    return out[:6] == b"160000"


sites = strips = listed = files = 0
for slug in slugs:
    if gitlink(slug):
        continue
    for path in glob.iglob(f"libs/{slug}/work/**/*", recursive=True):
        if not path.endswith((".lpc", ".h")) or not os.path.isfile(path):
            continue
        data = open(path, "rb").read()
        if b'".lpc"' not in data:
            continue
        lines = data.split(b"\n")
        changed = False
        for i, line in enumerate(lines):
            names = []

            def f1(m):
                names.append(m.group(1))
                if m.group(2) == b"4":
                    return m.group(0)
                return m.group(1) + b"[<4.." + (m.group(3) or b"") + b"]" + m.group(4)

            def f2(m):
                names.append(m.group(2))
                if m.group(3) == b"4":
                    return m.group(0)
                return m.group(1) + m.group(2) + b"[<4.." + (m.group(4) or b"") + b"]"

            new = CMP2.sub(f2, CMP1.sub(f1, line))
            if not names:
                continue
            if new != line:
                sites += 1
                lines[i] = new
                changed = True
                print(f"FIX   {path}:{i + 1}: {line.strip()[:90].decode('utf-8', 'replace')}")
            for j in range(i, min(i + 3, len(lines))):
                for nm in set(names):
                    # the strip of the same name: X[0..<3], X[..<3], X[0.. < 3] (two characters, the old ".c")
                    pat = re.compile(re.escape(nm) + rb"\[(0)?\s*\.\.\s*<\s*[234]\s*\]")
                    if pat.search(lines[j]):
                        lines[j] = pat.sub(lambda m: nm + (b"[0..<5]" if m.group(1) else b"[..<5]"), lines[j])
                        strips += 1
                        changed = True
                        print(f"STRIP {path}:{j + 1}: {lines[j].strip()[:90].decode('utf-8', 'replace')}")
                    other = re.findall(re.escape(nm) + rb"\[[^\]]*\.\.[^\]]*\]", lines[j])
                    other = [o for o in other if b"[<4.." not in o and b"..<5]" not in o and b"[<5..]" not in o]
                    if other:
                        listed += 1
                        print(f"READ  {path}:{j + 1}: {lines[j].strip()[:90].decode('utf-8', 'replace')}")
        if changed:
            files += 1
            if apply_:
                open(path, "wb").write(b"\n".join(lines))
print(f"{sites} comparison(s) in {files} file(s); {strips} strip(s) widened; {listed} line(s) to read"
      + ("" if apply_ else " (dry run)"))
