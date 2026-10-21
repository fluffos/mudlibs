#!/usr/bin/env python3
"""scripts/lpc_fix_in_ident.py [--apply] [--diag TSV] (SLUG... | --all)

`in` is a reserved word here (`foreach (x in list)`), so a variable, parameter or global named `in` (`int i, in, n;` for "inside quotes", `int st,in,wi,de,co,ch;` for
intelligence, `int copy_file(string in, string out)`) is `syntax error, unexpected L_IN, expecting L_DEFINED_NAME or L_IDENTIFIER or '*'` and the object never loads; whatever
inherits it goes with it.  The word was a free identifier in the MudOS this code was written for.  Same shape as scripts/lpc_fix_class_ident.py (KB 04 6.20).

For every file whose diagnostics hold an `unexpected L_IN` syntax error (the newest scan of each lib), the identifier is renamed in the file's code to `in_var` (`in_val`,
`in_id`, `inp` when the name is taken) with scripts/lpc_rename_ident.py: comments, strings, character constants and preprocessor lines are left alone, and so is every
`ob->in` and `::in`.  Files under a dead-copy directory (`old`, `bak`, `backup`, `*.old`, ...) are skipped unless --with-old.  A file that uses `in` as the keyword (`foreach (string s in arr)`) is listed, not touched.  Binary-safe.  Without --apply the plan is printed
(`slug<TAB>/path<TAB>new name<TAB>uses`).  Load-check the files afterwards (scripts/lpc_listcheck.sh at HEAD and in the tree): a file can fail on the next error behind it.
269 files in 51 libs in the 2026-10-18 scan (ninetears 128 in a `cleric.old` directory, shadowgate 15, questmud 14, yxcs 6, kxkj1 2 -- the `do` command ...), KB 04 section 6.26."""
import glob
import os
import re
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SCRATCH = os.environ.get("LPC_SCRATCH") or os.path.expanduser("~/.cache/lpc-scratch")
KEYWORD_USE = re.compile(r"\bforeach\s*\([^)]*[A-Za-z_\]\)]\s+in\s")
NAMES = ("in_var", "in_val", "in_id", "inp")
OLD_DIR = re.compile(r"(^|/)([^/]*\.)?(old|bak|backup|attic|oldcomandos|antiguo)[^/]*(/|$)", re.I)   # a directory of dead copies: left alone unless --with-old
LDMUD = {"simud", "aoh", "sticklib", "morgengrauen", "nirvlp312", "mundoscuro", "amylaarmini", "wilderness"}


def newest_diag(slug):
    best = None
    for pat in (f"{SCRATCH}/lpcw-{slug}/diagnostics.tsv", f"{SCRATCH}/tkfix/diag/{slug}.tsv", f"{SCRATCH}/fresh/out*/diag-{slug}.tsv"):
        for p in glob.glob(pat):
            if best is None or os.path.getmtime(p) > os.path.getmtime(best):
                best = p
    return best


def code_text(b):
    s = re.sub(r'"(\\.|[^"\\\n])*"', '""', b)
    s = re.sub(r"//[^\n]*", "", s)
    return re.sub(r"/\*.*?\*/", "", s, flags=re.S)


def main():
    a = sys.argv[1:]
    apply_ = "--apply" in a
    with_old = "--with-old" in a
    diag = a[a.index("--diag") + 1] if "--diag" in a else None
    slugs = [x for i, x in enumerate(a) if not x.startswith("--") and (i == 0 or a[i - 1] != "--diag")]
    if "--all" in a:
        slugs = sorted(os.path.basename(os.path.dirname(p)) for p in glob.glob(f"{REPO}/libs/*/work"))
    if not slugs:
        sys.exit(__doc__)
    total = 0
    for slug in slugs:
        if slug in LDMUD:
            continue
        d = diag or newest_diag(slug)
        if not d:
            continue
        files = []
        seen = set()
        for row in open(d, encoding="utf-8", errors="replace"):
            f = row.rstrip("\n").split("\t")
            if len(f) >= 5 and f[3] == "error" and re.search(r"unexpected L_IN\b", f[4]) and f[0].endswith(".lpc") and f[0] not in seen:
                seen.add(f[0])
                files.append(f[0])
        for rel in files:
            if not with_old and OLD_DIR.search(rel):
                continue
            p = f"{REPO}/libs/{slug}/work{rel}"
            try:
                b = open(p, "rb").read().decode("latin-1")
            except OSError:
                continue
            if KEYWORD_USE.search(code_text(b)):
                print(f"LIST\t{slug}\t{rel}\tuses `in` as the foreach keyword")
                continue
            for new in NAMES:
                out = subprocess.run([sys.executable, os.path.join(REPO, "scripts", "lpc_rename_ident.py"), slug, "in", new, rel] + (["--apply"] if apply_ else []),
                                     capture_output=True, text=True, cwd=REPO).stdout
                if "already uses" in out:
                    continue
                m = re.search(r"(\d+) use\(s\) in", out)
                n = int(m.group(1)) if m else 0
                print(f"{slug}\t{rel}\t{new}\t{n}")
                total += n
                break
            else:
                print(f"LIST\t{slug}\t{rel}\tno free name")
    print(f"{total} use(s) {'renamed' if apply_ else 'to rename'}", file=sys.stderr)


if __name__ == "__main__":
    main()
