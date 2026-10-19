#!/usr/bin/env python3
"""scripts/lpc_fix_double_slash.py [SLUG...] [--apply]

An object path with two leading slashes (`carry_object("//clone/cloth/hic_cloth")`, `new("//obj/weapon/sword")`, `inherit "//d/azha/town/market1"`,
`move("//d/nopk/standard/void.lpc")`) reached the master's `valid_read()` un-normalised: securityd looks the directory up as `//clone`, finds no
trusted entry for the NPC's euid and answers `Read access denied.` (xajh4gkb: 30 NPCs of the sects and towns, `carry_object` in `create()`; KB 06 section 7.276).
The games ran on a driver that normalised the path first.  The fix is the one-slash path.

Only string literals that look like a path are changed: `"//` + a first segment without a dot + at least one more `/`
(`"//EXIT"`, `"//OVER"`, `"//extras"` are the markers of an editor's block comments and stay).  Binary-safe; without --apply the plan is printed
(FIX lines, one per file with the number of sites); idempotent."""
import os
import re
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
PAT = re.compile(rb'"//([A-Za-z_][A-Za-z0-9_\-]*/[A-Za-z0-9_./\-]*)"')


def main():
    args = sys.argv[1:]
    apply = "--apply" in args
    only = [a for a in args if not a.startswith("--")]
    raw = subprocess.run(["git", "-c", "core.quotepath=false", "grep", "-l", "-a", "-P", r'"//[A-Za-z_][A-Za-z0-9_\-]*/', "--", "libs/*/work/*.lpc", "libs/*/work/*.h"],
                         cwd=REPO, capture_output=True).stdout.split(b"\n")
    nfile = nsite = 0
    for r in raw:
        if not r:
            continue
        rel = r.decode("utf-8", "surrogateescape")
        slug = rel.split("/")[1]
        if (only and slug not in only) or slug in ("wllz3", "longyunmeng_binary"):
            continue
        full = os.path.join(REPO, rel)
        b = open(full, "rb").read()
        out = []
        pos = 0
        k = 0
        for m in PAT.finditer(b):
            ls = b.rfind(b"\n", 0, m.start()) + 1
            if b[ls:m.start()].lstrip().startswith(b"//"):
                continue                    # inside a comment line
            out.append(b[pos:m.start()] + b'"/' + m.group(1) + b'"')
            pos = m.end()
            k += 1
        if not k:
            continue
        nfile += 1
        nsite += k
        print(f"FIX   {slug} /{rel.split('/work/', 1)[1]}: {k} site(s)")
        if apply:
            open(full, "wb").write(b"".join(out) + b[pos:])
    print(f"{nsite} site(s) in {nfile} file(s)" + ("" if apply else " (plan only; --apply writes)"))


if __name__ == "__main__":
    main()
