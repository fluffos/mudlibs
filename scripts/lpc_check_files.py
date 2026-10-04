#!/usr/bin/env python3
"""Compile a few objects of a lib the way scripts/lpc_warnings.py does, in seconds.

usage: scripts/lpc_check_files.py SLUG OBJ... [--all]
  OBJ    /domains/town/obj/seawater (no .lpc); list every file you edited or want to re-check
  --all  also print the diagnostics lpcc reports for other files (the boot-time block, inherited warnings)

Needs the scan tree of a previous `scripts/lpc_warnings.py SLUG` run (/tmp/lpcw-SLUG). The working tree's changes
(git diff against HEAD plus new files) are copied into it first, so the check sees your edits without rebuilding
the tree or scanning the whole lib (5-15 minutes). Prints `file:line:col severity message` and PASS/FAIL per object;
a FAIL with no diagnostic is a load-time run-time error (create() raising), not a compile problem.
"""
import importlib.util
import os
import subprocess
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
spec = importlib.util.spec_from_file_location("lw", os.path.join(HERE, "lpc_warnings.py"))
lw = importlib.util.module_from_spec(spec)
spec.loader.exec_module(lw)


def main():
    if len(sys.argv) < 3:
        sys.exit(__doc__)
    slug = sys.argv[1]
    objs = [a for a in sys.argv[2:] if not a.startswith("--")]
    lib = f"/tmp/lpcw-{slug}/libs/{slug}"
    if not os.path.isdir(lib):
        sys.exit(f"no scan tree {lib}: run scripts/lpc_warnings.py {slug} first")
    lw.sync_changes(slug, lib)
    raw = subprocess.run([lw.LPCC, "--batch", "config.fluffos"], cwd=lib, input="\n".join(objs) + "\n",
                         capture_output=True, text=True, errors="replace").stdout
    seen = set()
    for m in lw.DIAG.finditer(raw):
        f, ln, col, sev, msg = m.groups()
        key = (f, ln, msg)
        if key in seen:
            continue
        seen.add(key)
        if "--all" not in sys.argv and not any(f == o + ".lpc" or f == o for o in objs):
            continue
        print(f"{f}:{ln}:{col} {sev} {msg[:230]}")
    print("\n".join(l for l in raw.splitlines() if l.startswith(("PASS ", "FAIL "))))


if __name__ == "__main__":
    main()
