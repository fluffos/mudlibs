#!/usr/bin/env python3
"""scripts/lpc_fix_tp_carry.py [SLUG...] [--apply]

`this_player()->carry_object("/d/city/obj/cloth")->wear();` inside an NPC's `create()` (KB 06 section 7.268).  The author meant the NPC (`carry_object(...)`);
`this_player()` is whoever caused the clone.  With nobody acting (a preload, the room's reset from the driver, a loader) it is 0 and the call dies
with `Bad argument 1 to EFUN call_other()`, so the NPC never loads; with a visitor walking into the room the visitor gets the cloth and the sword
and the NPC stays naked.  (syxjl 48 sites, ldtx 40, ldtxii 40, hy3 28, and a few in 27 more libs.)

Rewrites `this_player()->carry_object(` to `carry_object(` inside functions named `create` only (a `do_combine()` that hands the player an item is
a different thing and is left).  Wizard, backup and test directories, wllz3 and longyunmeng_binary (generated trees) are not touched.
Binary-safe, line endings kept.  Without --apply the plan is printed (FIX lines); idempotent."""
import os
import re
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
HDR = re.compile(rb"^(?:(?:varargs|static|nomask|private|protected|public|nosave)\s+)*(?:void|int|string|object|mixed|mapping|float|status)\b[\s*]*(\w+)\s*\(")
SKIP = re.compile(r"/work/(u|w|wiz|wizard|wizards|open|players|backup|backups|old|bak|test|tests)/|/(bak|old|backup|test)/|[-_.](bak|old)\.lpc$")
NEEDLE = b"this_player()->carry_object("


def main():
    args = sys.argv[1:]
    apply = "--apply" in args
    only = [a for a in args if not a.startswith("--")]
    libs = only or sorted(os.listdir(f"{REPO}/libs"))
    nfix = nfile = 0
    for slug in libs:
        work = f"{REPO}/libs/{slug}/work"
        if slug in ("wllz3", "longyunmeng_binary") or not os.path.isdir(work) or os.path.exists(work + "/.git"):
            continue
        out = subprocess.run(["git", "-C", REPO, "grep", "-l", "-F", "this_player()->carry_object(", "--", f"libs/{slug}/work/*.lpc"],
                             capture_output=True, text=True).stdout.split("\n")
        for rel in sorted(x for x in out if x):
            if SKIP.search("/" + rel):
                continue
            full = f"{REPO}/{rel}"
            b = open(full, "rb").read()
            lines = b.split(b"\n")
            cur = None
            changed = 0
            for i, line in enumerate(lines):
                m = HDR.match(line)
                if m:
                    cur = m.group(1)
                if cur == b"create" and NEEDLE in line:
                    lines[i] = line.replace(NEEDLE, b"carry_object(")
                    changed += 1
            if changed:
                nfix += changed
                nfile += 1
                print(f"FIX   {slug} {rel[len('libs/' + slug + '/work'):]}: {changed} site(s)")
                if apply:
                    open(full, "wb").write(b"\n".join(lines))
    print(f"{nfix} site(s) in {nfile} file(s)" + ("" if apply else " (plan only; --apply writes)"))


if __name__ == "__main__":
    main()
