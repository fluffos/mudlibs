#!/usr/bin/env python3
"""scripts/lpc_scan_dangling.py [SLUG...] [--summary] [--kinds K,K] [--min N]

Report-only (KB 06 section 7.257).  The file paths the live code of a lib names that the lib does not have: a room exit or an
`objects` entry that points at `__DIR__"npc/xiaoer"` while the file is `xiao-er.lpc`, a `new("/clone/food/baozi")` that is
`/clone/food/baozii`, an `inherit "/std/room/class_guild"` the archive never shipped.  Each hit is `DANGLE slug kind file:line
"path" -> suggestion`:
  EXIT    a room exit value (`"north": __DIR__"room2"`, `add_exit("n", "/d/x/y")`)
  OBJ     a room `objects` entry (`__DIR__"npc/guard": 1`)
  NEW     the argument of new() / carry_object() / unew()
  INHERIT a literal `inherit "/path";`
  INC     a quoted `#include "x.h"` that resolves nowhere
and the suggestion is `CASE x` (the same name in other letters), `TYPO x` (the one file of that directory one letter, one swap
or one hyphen away) or `MOVED x` (the one file of that name in the lib), else `NONE`.  Wizard, backup and example dirs, strings
in comments and in data calls (write_file, log_file, save_object ...) are skipped.  Nothing is changed: a TYPO is a fix only after
a reader checks the NPC or room the path names; the CASE class is scripts/lpc_case_paths.py's.
--summary prints the per-lib totals; --kinds limits to some kinds; --min N shows only libs with N or more hits."""
import collections
import os
import re
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from lpc_fix_void_return import code_mask  # noqa: E402

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SKIP = re.compile(r"/(u|w|wiz|wizard|wizards|open|players|backup|backups|old|bak|log|data|doc|docs|example|examples|test|tmp|attic)/|[-_.](bak|old|orphaned-driver-src)/|\.(bak|BAK|old|orig)(\.lpc)?$")
DATACALL = re.compile(rb"(?:write_file|read_file|log_file|save_object|restore_object|file_size|mkdir|rmdir|rm|rename|cat|read_bytes|write_bytes|get_dir|cp|more|tail)\s*\(\s*$")
STR = re.compile(rb'(__DIR__\s*)?"((?:[^"\\\n]|\\.)*)"')
ROOTS = ("d", "clone", "kungfu", "std", "obj", "cmds", "daemon", "adm", "inherit", "feature", "quest", "include", "u", "domains", "lib", "secure", "world", "realms", "areas", "doc", "system", "data", "npc", "item", "weapon", "armor")
NEWCALL = re.compile(rb"(?:new|carry_object|unew|clone_object|load_object)\s*\(\s*$")
INHERIT = re.compile(rb"inherit\s*$")
EXITS = re.compile(rb"add_exit\s*\(\s*[^,()]*,\s*$")


def in_code(mask, b, pos):
    """True when the text at pos is code.  A string literal (quotes included) is masked, so a match that starts at an opening
    quote is judged by the first character before it that is not a blank: `(`, `,` or `[` of the code around it, or
    the closing `/` of a comment."""
    if mask[pos]:
        return True
    i = pos - 1
    while i >= 0 and b[i] in b" \t\r\n":
        i -= 1
    return i >= 0 and bool(mask[i]) and b[i] not in b'"'


def lev1(a, b):
    la, lb = len(a), len(b)
    if abs(la - lb) > 1 or a == b:
        return False
    if la == lb:
        d = [i for i in range(la) if a[i] != b[i]]
        return len(d) == 1 or (len(d) == 2 and d[1] == d[0] + 1 and a[d[0]] == b[d[1]] and a[d[1]] == b[d[0]])
    if la > lb:
        a, b = b, a
    return any(a[:i] == b[:i] and a[i:] == b[i + 1:] for i in range(len(b)))


def tracked():
    by = collections.defaultdict(set)
    for f in subprocess.run(["git", "ls-files", "-z", "--", "libs"], cwd=REPO, capture_output=True).stdout.split(b"\0"):
        try:
            p = f.decode("utf-8")
        except UnicodeDecodeError:
            continue
        parts = p.split("/work/", 1)
        if len(parts) == 2 and "longyunmeng_binary" not in p:
            by[p.split("/")[1]].add("/" + parts[1])
    return by


def main():
    args = sys.argv[1:]
    summary = "--summary" in args
    kinds = None
    minn = 0
    if "--kinds" in args:
        i = args.index("--kinds")
        kinds = set(args[i + 1].split(","))
        del args[i:i + 2]
    if "--min" in args:
        i = args.index("--min")
        minn = int(args[i + 1])
        del args[i:i + 2]
    only = [a for a in args if not a.startswith("--")]
    by = tracked()
    tot = collections.Counter()
    for slug in sorted(only or by):
        if slug not in by or os.path.exists(f"{REPO}/libs/{slug}/work/.git"):
            continue
        files = by[slug]
        lpc = {f[:-4] for f in files if f.endswith(".lpc")} | {f[:-2] for f in files if f.endswith(".c")}
        low = collections.defaultdict(list)
        for f in lpc:
            low[f.lower()].append(f)
        dirs = collections.defaultdict(set)
        base = collections.defaultdict(list)
        for f in lpc:
            d, _, n = f.rpartition("/")
            dirs[d].add(n)
            base[n].append(f)
        alldirs = {f.rsplit("/", 1)[0] for f in files}
        hits = []
        for rel in sorted(files):
            if not rel.endswith(".lpc") or SKIP.search(rel):
                continue
            try:
                b = open(f"{REPO}/libs/{slug}/work{rel}", "rb").read()
            except OSError:
                continue
            if b'"' not in b:
                continue
            mask = None
            fdir = rel.rsplit("/", 1)[0]
            for m in STR.finditer(b):
                s = m.group(2)
                rel_dir = bool(m.group(1))
                if not s or len(s) > 120 or b"\n" in s:
                    continue
                path = s.decode("utf-8", "replace")
                if rel_dir:
                    if path.startswith("/"):
                        path = path[1:]
                    full = fdir + "/" + path
                elif path.startswith("/") and path.split("/")[1:2] and path.split("/")[1] in ROOTS and re.fullmatch(r"/[A-Za-z0-9_./+-]+", path):
                    full = path
                else:
                    continue
                if mask is None:
                    mask = code_mask(b, heredoc=True)
                if not in_code(mask, b, m.start()):
                    continue
                before = b[max(0, m.start() - 60):m.start()].rstrip()
                if DATACALL.search(before):
                    continue
                if re.search(rb"\.(o|h|txt|dat|log|bak|sav|c|lpc|map|cfg|dir)$", s) and not rel_dir:
                    # `.c` / `.lpc` names are still files to check; the others are data
                    if not re.search(rb"\.(c|lpc)$", s):
                        continue
                full = os.path.normpath(full)
                stem = full[:-4] if full.endswith(".lpc") else full[:-2] if full.endswith(".c") else full
                if stem in lpc or full in files or full in alldirs or full + "/" in {d + "/" for d in alldirs}:
                    continue
                # which kind of reference
                if INHERIT.search(before):
                    kind = "INHERIT"
                elif NEWCALL.search(before):
                    kind = "NEW"
                elif EXITS.search(before) or re.search(rb"[\"'\w]\s*:\s*$", before) and (b"exits" in b[max(0, m.start() - 600):m.start()]):
                    kind = "EXIT"
                elif re.search(rb"\s*:\s*\d+\s*[,)]", b[m.end():m.end() + 16]) or re.match(rb"\s*:\s*[\d(]", b[m.end():m.end() + 8]):
                    kind = "OBJ"
                else:
                    continue
                if kinds and kind not in kinds:
                    continue
                # suggestion
                sug = "NONE"
                d, _, n = stem.rpartition("/")
                if stem.lower() in low and stem not in lpc:
                    sug = "CASE " + low[stem.lower()][0]
                else:
                    near = [x for x in dirs.get(d, ()) if lev1(n, x)]
                    if len(near) == 1:
                        sug = "TYPO " + d + "/" + near[0]
                    elif len(base.get(n, ())) == 1:
                        sug = "MOVED " + base[n][0]
                line = b.count(b"\n", 0, m.start()) + 1
                hits.append((kind, rel, line, path, sug))
        if len(hits) < max(minn, 1):
            continue
        c = collections.Counter(h[0] + "/" + h[4].split(" ")[0] for h in hits)
        tot.update(c)
        print(f"LIB   {slug}: {len(hits)} dangling  " + " ".join(f"{k}={v}" for k, v in sorted(c.items())))
        if not summary:
            for kind, rel, line, path, sug in hits:
                print(f"DANGLE {slug} {kind} {rel}:{line} \"{path}\" -> {sug}")
    print("TOTAL " + " ".join(f"{k}={v}" for k, v in sorted(tot.items())))


if __name__ == "__main__":
    main()
