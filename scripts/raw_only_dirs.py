#!/usr/bin/env python3
"""Directories the original archive ships (usually empty, so git and the converted
work/ tree never kept them) that the lib's own code names as a directory.

A fresh clone or the site's zip has no empty directories, so a lib that does
`get_dir(DIR_X "/*.lpc")` on a directory the archive shipped empty gets 0 back, and
`array + 0` aborts.  Dead Souls II's `help` command died exactly this way
(secure/cmds/common, verbs/spells, verbs/undead -- docs/kb/06-runtime-classes-2.md
§7.212).  scripts/gen_keep_dirs.py cannot see these: it only records directories that
exist in the LOCAL work/ tree, and these were never there.  This script reads the
pristine extraction (libs/<slug>/raw/, gitignored; regenerate with scripts/extract.sh)
instead.

A raw directory is reported when
  - it is absent from work/ (or has no tracked file and is not in wasm_keep_dirs.txt),
  - and some path the code names (a "/dir/..." string literal, or a #define that
    expands to one, with a trailing "/", "/*", "/*.c" or "/*.lpc" stripped) is exactly
    that directory.
Paths that merely lie beneath it (a room file under d/fozhou) do not count: the
directory is only worth keeping if something lists or writes it as a directory.

Usage:
  python3 scripts/raw_only_dirs.py SLUG [SLUG ...]          # report
  python3 scripts/raw_only_dirs.py --apply SLUG [SLUG ...]  # append to scripts/wasm_keep_dirs.txt
  python3 scripts/raw_only_dirs.py --all                    # report every lib that has raw/
The raw root (the directory in raw/ that corresponds to work/) is guessed by the overlap
of top-level directory names; it is printed so a wrong guess is visible.
"""
import os
import re
import subprocess
import sys
from pathlib import Path, PurePosixPath

REPO = Path(__file__).resolve().parent.parent
KEEP = REPO / "scripts" / "wasm_keep_dirs.txt"
NOISE_PARTS = {".git", "CVS", ".svn", "backup", "backtemp", "binaries", "www", "temp"}
SRC_EXT = (".lpc", ".c", ".h")


def is_gitlink(slug):
    out = subprocess.run(["git", "-C", str(REPO), "ls-files", "-s", "--", f"libs/{slug}/work"],
                         capture_output=True).stdout.decode("utf-8", "surrogateescape")
    return any(line.split(None, 1)[0] == "160000" for line in out.splitlines() if line.strip())


def tracked_dirs(slug):
    """dirs (relative to work/) holding at least one tracked file; a submodule's tracked
    files are read from the submodule's own index."""
    if is_gitlink(slug):
        out = subprocess.run(["git", "-C", str(REPO / "libs" / slug / "work"), "ls-files", "-z"],
                             capture_output=True).stdout.decode("utf-8", "surrogateescape")
        pre = ""
    else:
        out = subprocess.run(["git", "-C", str(REPO), "ls-files", "-z", f"libs/{slug}/work/"],
                             capture_output=True).stdout.decode("utf-8", "surrogateescape")
        pre = f"libs/{slug}/work/"
    dirs = set()
    for f in out.split("\0"):
        if not f or not f.startswith(pre):
            continue
        rel = PurePosixPath(f[len(pre):]).parent
        while str(rel) != ".":
            dirs.add(rel.as_posix())
            rel = rel.parent
    return dirs


def keep_dirs(slug):
    out = set()
    if KEEP.is_file():
        for line in KEEP.read_text(encoding="utf-8", errors="replace").split("\n"):
            if line.startswith(slug + "\t"):
                out.add(line.split("\t", 1)[1])
    return out


def all_dirs(root):
    out = set()
    for dp, dn, fn in os.walk(root):
        rel = os.path.relpath(dp, root)
        out.add("" if rel == "." else rel.replace(os.sep, "/"))
    return out


def guess_raw_root(raw, work):
    wtop = {d for d in os.listdir(work) if os.path.isdir(os.path.join(work, d))}
    best = (0, None)
    for dp, dn, fn in os.walk(raw):
        depth = os.path.relpath(dp, raw).count(os.sep)
        if depth > 4:
            dn[:] = []
            continue
        ov = len(set(dn) & wtop)
        if ov > best[0]:
            best = (ov, dp)
    return best[1] if best[0] >= 2 else None


# ---- what paths does the code name as directories
LIT = re.compile(r'"(/?[A-Za-z0-9_.\-/*]+)"')
DEFINE = re.compile(r"^[ \t]*#[ \t]*define[ \t]+([A-Za-z_]\w*)[ \t]+([^\n]*)$", re.M)
TAIL = re.compile(r"/(\*\.lpc|\*\.c|\*\.h|\*)$")


def strip_comments(t):
    t = re.sub(r"/\*.*?\*/", "", t, flags=re.S)
    return re.sub(r"//[^\n]*", "", t)


def collect_refs(work):
    defs = {}
    lits = set()
    for dp, dn, fn in os.walk(work):
        rel = os.path.relpath(dp, work)
        if rel == "log" or rel.startswith("log" + os.sep):
            continue
        for f in fn:
            if not f.endswith(SRC_EXT):
                continue
            try:
                t = open(os.path.join(dp, f), encoding="latin-1").read()
            except OSError:
                continue
            t = strip_comments(t)
            if f.endswith(".h"):
                for m in DEFINE.finditer(t):
                    defs.setdefault(m.group(1), m.group(2).strip())
            for m in LIT.finditer(t):
                lits.add(m.group(1))

    def expand(expr, depth=0):
        if depth > 8:
            return None
        parts = re.findall(r'"[^"]*"|[A-Za-z_]\w*', expr)
        if not parts:
            return None
        out = ""
        for p in parts:
            if p.startswith('"'):
                out += p[1:-1]
            elif p in defs:
                r = expand(defs[p], depth + 1)
                if r is None:
                    return None
                out += r
            else:
                return None
        return out

    vals = set(lits)
    for name, body in defs.items():
        v = expand(body)
        if v:
            vals.add(v)
    refs = set()
    for v in vals:
        if "/" not in v:
            continue
        v = TAIL.sub("", v)
        v = v.strip("/")
        if v:
            refs.add(v)
    return refs


def analyse(slug):
    lib = REPO / "libs" / slug
    raw, work = lib / "raw", lib / "work"
    if not raw.is_dir() or not work.is_dir():
        return None
    root = guess_raw_root(str(raw), str(work))
    if not root:
        return {"root": None}
    rdirs = all_dirs(root)
    have = tracked_dirs(slug) | keep_dirs(slug)
    refs = collect_refs(str(work))
    out = []
    for d in sorted(rdirs, key=lambda r: PurePosixPath(r).parts):
        if not d or d in have:
            continue
        if any(p in NOISE_PARTS or p.startswith(".") for p in d.split("/")):
            continue
        if "\udcf0" in d or any(ord(c) > 0xD7FF for c in d):   # undecodable names
            continue
        if d in refs:
            out.append(d)
    return {"root": os.path.relpath(root, raw), "dirs": out, "total": len(rdirs)}


def main(argv):
    apply_ = "--apply" in argv
    every = "--all" in argv
    named = [a for a in argv if not a.startswith("--")]
    bad = [a for a in argv if a.startswith("--") and a not in ("--apply", "--all")]
    if bad:
        sys.exit(f"unknown option(s): {' '.join(bad)}")
    slugs = sorted(p.name for p in (REPO / "libs").iterdir() if (p / "raw").is_dir()) if every else named
    if not slugs:
        sys.exit(__doc__)
    lines = KEEP.read_text(encoding="utf-8", errors="surrogateescape").split("\n") if KEEP.is_file() else []
    lines = [l for l in lines if l]
    added = 0
    for slug in slugs:
        r = analyse(slug)
        if r is None:
            print(f"{slug}: no raw/ or work/")
            continue
        if not r.get("root"):
            print(f"{slug}: raw root not found")
            continue
        if not r["dirs"]:
            if not every:
                print(f"{slug}: root {r['root']}: nothing to add")
            continue
        print(f"{slug}: root {r['root']}: {len(r['dirs'])} directory(ies) the code names but git/work lack")
        for d in r["dirs"]:
            print(f"    {d}")
        if apply_:
            prefix = slug + "\t"
            idx = [i for i, l in enumerate(lines) if l.startswith(prefix)]
            old = {lines[i][len(prefix):] for i in idx}
            merged = sorted(old | set(r["dirs"]), key=lambda x: PurePosixPath(x).parts)
            new = [prefix + x for x in merged]
            if idx:
                first = idx[0]
                rest = [l for i, l in enumerate(lines) if i not in set(idx)]
                lines = rest[:first] + new + rest[first:]
            else:
                lines = lines + new
            added += len(merged) - len(old)
    if apply_:
        KEEP.write_text("\n".join(lines) + "\n", encoding="utf-8", errors="surrogateescape")
        print(f"wasm_keep_dirs.txt: {added} line(s) added")


if __name__ == "__main__":
    main(sys.argv[1:])
