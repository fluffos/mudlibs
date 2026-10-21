#!/usr/bin/env python3
"""scripts/lpc_fix_keep_dir.py [--apply] [--libs a,b]

The xkx family's `blockade` / `recover` pair (118 files in 61 libs: `cmds/arch/blockade.lpc`, `recover.lpc`, `recovermud.lpc`, `recover1.lpc`, `recover_sp.lpc`) keeps every
logged-in player's save in `data/keep/<id>` while the world is locked and copies it back afterwards.  `data/keep/` is runtime output: a git clone has no empty directory
(only wuhanzhan's keep list has it), so `blockade` calls `cp(src, "data/keep/<id>")` into a directory that does not exist, and `recover` then dies in its first
`cp()` of a kept file that is not there (`*/data/keep/fluffos: lstat failed`) BEFORE its `LOGIN_D->set_madlock(0)`: the world stays locked.  Two lines:

    blockade   `if (file_size("/data/keep") != -2) mkdir("/data/keep");`   before the first `dst = "data/keep/" + playerid;`   (mkdir answers 0, it does not raise)
    recover*   `if (file_size(src) < 0) continue;`                          after `src = "data/keep/" + playerid;`   (a player who has no kept save is skipped, the rest is restored and the lock released)

Wizard copies (`u/`, `old/`, `bak/`), the gitlink libs and binary files are not touched.  Dry run unless `--apply`; binary mode, the file's own line ending, idempotent."""
import os
import re
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
GITLINKS = {"nt7", "xkx100utf8", "fy2005", "nightmare3", "residuum", "sanguozhi", "oxidus", "deadsouls_fluffos"}
SKIPDIR = re.compile(r"(^|/)(old|bak|backup|attic|raw|u|wizards|w|realms|binaries)(/|$)")
DST = re.compile(rb'(?m)^([ \t]*)dst[ \t]*=[ \t]*"data/keep/"[ \t]*\+[ \t]*playerid[ \t]*;[ \t]*\r?$')
SRC = re.compile(rb'(?m)^([ \t]*)src[ \t]*=[ \t]*"data/keep/"[ \t]*\+[ \t]*playerid[ \t]*;[ \t]*\r?$')


def plan(base, data):
    nl = b"\r\n" if data.count(b"\r\n") * 2 > data.count(b"\n") else b"\n"
    if base.startswith("blockade"):
        if b'mkdir("/data/keep")' in data:
            return None
        m = DST.search(data)
        if not m:
            return None
        return m.start(), m.group(1) + b'if (file_size("/data/keep") != -2) mkdir("/data/keep");' + nl
    if base.startswith("recover"):
        if b"file_size(src)" in data:
            return None
        m = SRC.search(data)
        if not m:
            return None
        end = data.index(b"\n", m.end() - 1) + 1 if b"\n" in data[m.end() - 1:] else len(data)
        return end, m.group(1) + b"if (file_size(src) < 0) continue;" + nl
    return None


def main():
    apply = "--apply" in sys.argv
    libs = None
    for i, a in enumerate(sys.argv):
        if a == "--libs" and i + 1 < len(sys.argv):
            libs = sys.argv[i + 1].split(",")
    out = subprocess.run(["git", "grep", "-l", "-I", "data/keep/", "--", "libs/*/work/cmds/*"], cwd=REPO, capture_output=True, text=True).stdout.split("\n")
    n = 0
    per = {}
    for rel in sorted(x for x in out if x.endswith((".lpc", ".c"))):
        slug = rel.split("/")[1]
        inner = rel[len(f"libs/{slug}/work/"):]
        if slug in GITLINKS or (libs and slug not in libs) or SKIPDIR.search(inner):
            continue
        path = f"{REPO}/{rel}"
        data = open(path, "rb").read()
        p = plan(os.path.basename(rel), data)
        if not p:
            continue
        pos, ins = p
        n += 1
        per[slug] = per.get(slug, 0) + 1
        print(f"{slug}\t{inner}\t{data[:pos].count(bytes([10])) + 1}\t{ins.strip().decode('utf-8', 'replace')}")
        if apply:
            open(path, "wb").write(data[:pos] + ins + data[pos:])
    print(f"{n} file(s) in {len(per)} lib(s)" + ("" if apply else " (dry run)"), file=sys.stderr)


if __name__ == "__main__":
    main()
