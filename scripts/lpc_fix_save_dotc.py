#!/usr/bin/env python3
"""scripts/lpc_fix_save_dotc.py [--apply] [--libs SLUG ...] [--user] [--only TEXT]

Save files (`.o`) that name code files with `.c` (KB 03 4.2 item 9).  The archives were extracted with every `.c` renamed `.lpc` and the source literals rewritten,
but the saved data still says `"/d/city/npc/wei.c"`, `"filename":"/world/area/muye/muye.c"`, `"file_name":"/sgdomain/obj/foodanddrink/mantou.c"`: an explicit
extension is resolved exactly, so `new()` / `load_object()` / `move()` of that string finds nothing (the object table of sgzmudsgz answered an error string and the
caller `->move()`d it; the NPC and room saves of the FY family, naruto's `world/area`, pd's boats name destinations that cannot load).  The fix is the data, string by
string: `"/x/y.c"` -> `"/x/y.lpc"`, only when `/x/y.lpc` exists in the lib and `/x/y.c` does not.  Only TRACKED `.o` files are touched (a runtime save is not part of the
repository), in binary mode, nothing else in the file changes (the `#/x/y.c` header line is not a quoted string and stays).  By default the player data is left alone
(`data/user`, `data/login`, `u/`, `wizards/`, backups, boards, logs, autodoc caches: shipped sample characters nobody can log in as); --user includes it.  Left alone as well: the
file-index caches (Dead Souls `secure/save/files.o` lists every file of the lib and is rebuilt by the file daemon, Discworld `secure/rcs_handler.o`) and headers that carry an
`.o` name (`include/globals.h.o`); --only TEXT restricts a run to the files whose path contains TEXT.
Dry run by default: one line per file (`slug path sites`), the per-lib summary on stderr.  The gitlink libs (nt7, xkx100utf8, fy2005, nightmare3, residuum, sanguozhi,
oxidus) are never touched."""
import argparse
import os
import re
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
GITLINKS = {"nt7", "xkx100utf8", "fy2005", "nightmare3", "residuum", "sanguozhi", "oxidus"}
PLAYER = re.compile(r"(^|/)(data/user|data/login|data1/user|data1/login|backup|bak|board|boards|u|wizards|wiz|log|autodoc|attic|old|players?|users?|login)(/|$)", re.I)
INDEX = re.compile(r"(^|/)(secure/save/files|secure/rcs_handler)\.o$|\.h\.o$|(^|/)include/[^/]+\.o$")     # file-index caches and headers that carry an .o name, not saves of objects
STR = re.compile(rb'"(/[A-Za-z0-9_./\-]+?)\.c"')


def fix(slug, data):
    work = f"{REPO}/libs/{slug}/work"
    n = 0

    def rep(m):
        nonlocal n
        base = work + m.group(1).decode("ascii")
        if os.path.exists(base + ".lpc") and not os.path.exists(base + ".c"):
            n += 1
            return b'"' + m.group(1) + b'.lpc"'
        return m.group(0)

    return STR.sub(rep, data), n


def main():
    sys.stdout.reconfigure(errors="surrogateescape")
    ap = argparse.ArgumentParser()
    ap.add_argument("--apply", action="store_true")
    ap.add_argument("--libs", nargs="*", default=[])
    ap.add_argument("--user", action="store_true")
    ap.add_argument("--only", default="", help="only the files whose path inside work/ contains this text (data/hockshop/)")
    a = ap.parse_args()
    libs = a.libs or sorted(d for d in os.listdir(f"{REPO}/libs") if os.path.isdir(f"{REPO}/libs/{d}/work"))
    per = {}
    for slug in libs:
        if slug in GITLINKS:
            continue
        out = subprocess.run(["git", "ls-files", "-z", "--", f"libs/{slug}/work"], cwd=REPO, capture_output=True).stdout
        for rel in (p.decode("utf-8", "surrogateescape") for p in out.split(b"\0") if p):
            if not rel.endswith(".o"):
                continue
            inner = rel[len(f"libs/{slug}/work/"):]
            if not a.user and PLAYER.search(inner):
                continue
            if a.only and a.only not in inner:
                continue
            if INDEX.search(inner):
                continue
            path = f"{REPO}/{rel}"
            try:
                b = open(path, "rb").read()
            except OSError:
                continue
            if b'.c"' not in b:
                continue
            new, n = fix(slug, b)
            if not n:
                continue
            files, sites = per.get(slug, (0, 0))
            per[slug] = (files + 1, sites + n)
            print(slug, inner, n)
            if a.apply:
                open(path, "wb").write(new)
    tf = sum(v[0] for v in per.values())
    ts = sum(v[1] for v in per.values())
    for slug, (f, s) in sorted(per.items(), key=lambda x: -x[1][0]):
        print(f"  {slug}: {f} file(s), {s} site(s)", file=sys.stderr)
    print(f"{tf} file(s), {ts} site(s) in {len(per)} lib(s)" + ("" if a.apply else " (dry run)"), file=sys.stderr)


if __name__ == "__main__":
    main()
