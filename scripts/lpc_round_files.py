#!/usr/bin/env python3
"""scripts/lpc_round_files.py SLUG (--objects FILE | --failing TSV) [--rounds N] [--fixers NAME,NAME,...] [--dry]

Repair rounds over the objects that do not compile, without the hour a whole-lib scan takes.  Errors come in layers: fixing the first one in a file
shows the next (`Wrong number of arguments` hides `Missing type for argument` hides `Type mismatch ... when initializing`), and a whole-lib
scan per layer is too slow for a 40,000-file lib whose failing objects are a few thousand.  This compiles only those objects in one VM per round
(scripts/lpc_warnings.py's batch_compile on the scan tree scripts/pristine_tree.sh builds once), writes the diagnostics, runs the mechanical fixers
on them, syncs the edited files into the scan tree and goes round again until a round changes nothing (default at most 6).

  --objects FILE   driver paths, one per line (`/d/foo/bar.lpc`), or `slug<TAB>/d/foo/bar.lpc` rows (those of SLUG only)
  --failing TSV    every .lpc named by an error row of a diagnostics file (what lpc_warnings.py / toolkit_fix.sh leave in
                   $LPC_SCRATCH/tkfix/diag/SLUG.tsv)
  --fixers LIST    comma list, default `missing_args,untyped_params,init_array,void_return,class_ident`: scripts/lpc_fix_missing_args.py,
                   lpc_fix_untyped_params.py, lpc_fix_init_array.py, lpc_fix_void_return.py, lpc_fix_class_ident.py (each runs with --apply on the round's diagnostics)

Prints, per round, how many of the objects compile and the fixes each fixer made, and at the end the files that still fail with their first error;
the last round's diagnostics stay in $LPC_SCRATCH/lpcw-SLUG-round/diagnostics.tsv.  The repo edits are plain working-tree edits: load-check the changed files
at HEAD and in the tree (scripts/lpc_listcheck.sh, scripts/lpc_load_diff.py) before committing, as for every fixer.  --dry: compile and print, change nothing."""
import collections
import importlib.util
import os
import re
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SCRATCH = os.environ.get("LPC_SCRATCH") or os.path.expanduser("~/.cache/lpc-scratch")
spec = importlib.util.spec_from_file_location("lw", os.path.join(REPO, "scripts", "lpc_warnings.py"))
lw = importlib.util.module_from_spec(spec)
_argv, sys.argv = sys.argv, ["lpc_warnings.py"]
spec.loader.exec_module(lw)
sys.argv = _argv

FIXERS = {
    "missing_args": ["lpc_fix_missing_args.py", "--apply", "{slug}", "{tsv}"],
    "untyped_params": ["lpc_fix_untyped_params.py", "--apply", "{slug}", "{tsv}"],
    "init_array": ["lpc_fix_init_array.py", "--apply", "{slug}", "{tsv}"],
    "void_return": ["lpc_fix_void_return.py", "{slug}", "--apply", "--diag", "{tsv}"],
    "class_ident": ["lpc_fix_class_ident.py", "--apply", "--diag", "{tsv}", "{slug}"],
}


def main():
    a = sys.argv[1:]
    if not a or a[0].startswith("--"):
        sys.exit(__doc__)
    slug = a[0]
    dry = "--dry" in a
    rounds = int(a[a.index("--rounds") + 1]) if "--rounds" in a else 6
    fixers = (a[a.index("--fixers") + 1].split(",") if "--fixers" in a else ["missing_args", "untyped_params", "init_array", "void_return", "class_ident"])
    objs = []
    if "--objects" in a:
        for ln in open(a[a.index("--objects") + 1], encoding="utf-8", errors="replace"):
            f = ln.rstrip("\n").split("\t")
            if len(f) >= 2 and f[0] != slug:
                continue
            p = f[-1].strip()
            if p.startswith("/") and p.endswith(".lpc"):
                objs.append(p[:-4])
    elif "--failing" in a:
        seen = set()
        for ln in open(a[a.index("--failing") + 1], encoding="utf-8", errors="replace"):
            f = ln.rstrip("\n").split("\t")
            if len(f) >= 5 and f[3] == "error" and f[0].endswith(".lpc") and f[0] not in seen:
                seen.add(f[0])
                objs.append(f[0][:-4])
    else:
        sys.exit(__doc__)
    objs = sorted(set(objs))
    if not objs:
        sys.exit("no objects")
    dest = f"{SCRATCH}/lpcw-{slug}-round"
    lib = lw.build_tree(slug, dest)
    print(f"{slug}: {len(objs)} object(s)", flush=True)
    for rnd in range(1, rounds + 1):
        lw.sync_changes(slug, lib)
        raw = lw.batch_compile(lib, objs)
        rows, seen = [], set()
        for m in lw.DIAG.finditer(raw):
            f, ln, col, sev, msg = m.groups()
            key = (f, ln, col or "0", msg)
            if key in seen:
                continue
            seen.add(key)
            rows.append((f, int(ln), int(col or 0), sev, msg))
        npass = len(re.findall(r"^PASS ", raw, re.M))
        nfail = len(re.findall(r"^FAIL ", raw, re.M))
        tsv = os.path.join(dest, "diagnostics.tsv")
        with open(tsv, "w", encoding="utf-8") as fh:
            fh.write("\n".join("\t".join(map(str, r)) for r in rows) + "\n")
        print(f"round {rnd}: {npass} compile, {nfail} do not", flush=True)
        if dry or not nfail:
            break
        changed = 0
        for name in fixers:
            cmd = [sys.executable, os.path.join(REPO, "scripts", FIXERS[name][0])] + [x.format(slug=slug, tsv=tsv) for x in FIXERS[name][1:]]
            out = subprocess.run(cmd, capture_output=True, text=True, cwd=REPO)
            n = sum(1 for ln in out.stdout.split("\n") if ln.startswith("FIX\t"))
            if name == "void_return":
                m = re.search(r"(\d+) file\(s\) fixed", out.stdout + out.stderr)
                n = int(m.group(1)) if m else 0
            print(f"  {name}: {n} file(s)", flush=True)
            changed += n
        if not changed:
            break
    first = {}
    for r in rows:
        if r[3] == "error" and r[0] not in first:
            first[r[0]] = r
    print(f"{len(first)} file(s) with errors left; first errors:")
    c = collections.Counter(re.sub(r"\d+", "N", re.sub(r"'[^']*'", "X", r[4]))[:80] for r in first.values())
    for k, v in c.most_common(12):
        print(f"  {v:5d}  {k}")
    print(f"diagnostics: {os.path.join(dest, 'diagnostics.tsv')}")


if __name__ == "__main__":
    main()
