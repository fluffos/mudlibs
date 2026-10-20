#!/usr/bin/env python3
"""scripts/lpc_fix_class_ident.py [--apply] (SLUG... | --all)

`class` is a reserved word here (FluffOS structs), so a variable, parameter or global named `class` (`int bait, class;`, `string class = me->query("class");`,
`void create(class)`) is `syntax error, unexpected L_CLASS` and the object never loads; every NPC / room / skill that inherits it goes with it.  The word was
a free identifier in the MudOS this code was written for (a character's class is the commonest thing to name).

For every file whose diagnostics hold a `L_CLASS` syntax error (the newest scan of each lib, as scripts/lpc_fix_missing_args.py finds it), the identifier is
renamed in the file's code to `pick_class` (`my_class`, `class_name`, `cls_id` when the name is taken) with scripts/lpc_rename_ident.py: comments, strings,
character constants and preprocessor lines are left alone, and so is every `ob->class`, `::class` and `class(`.  A file that uses `class` as the
keyword (`class foo { ... }`, `class foo x;`) is listed, not touched.  Binary-safe.  Without --apply the plan is printed (`slug<TAB>/path<TAB>new name<TAB>uses`).
Load-check the files afterwards (scripts/lpc_listcheck.sh at HEAD and in the tree): a file can fail on the next error behind it.
130 files in 19 libs on 2026-10-19 (questmud 31, shadowgate 24, sunshadow 22, kxkj1 15, mortremains 9 ...), KB 04 section 6.20."""
import glob
import os
import re
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SCRATCH = os.environ.get("LPC_SCRATCH") or os.path.expanduser("~/.cache/lpc-scratch")
KEYWORD_USE = re.compile(r"(?<![\w>:])class\s+[A-Za-z_]\w*\s*(\{|[A-Za-z_]\w*\s*[;=,)])")
NAMES = ("pick_class", "my_class", "class_name", "cls_id")
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
    slugs = [x for x in a if not x.startswith("--")]
    if "--all" in a:
        slugs = sorted(os.path.basename(os.path.dirname(p)) for p in glob.glob(f"{REPO}/libs/*/work"))
    if not slugs:
        sys.exit(__doc__)
    total = 0
    for slug in slugs:
        if slug in LDMUD:
            continue
        d = newest_diag(slug)
        if not d:
            continue
        files = []
        seen = set()
        for row in open(d, encoding="utf-8", errors="replace"):
            f = row.rstrip("\n").split("\t")
            if len(f) >= 5 and f[3] == "error" and "L_CLASS" in f[4] and f[0].endswith(".lpc") and f[0] not in seen:
                seen.add(f[0])
                files.append(f[0])
        for rel in files:
            p = f"{REPO}/libs/{slug}/work{rel}"
            try:
                b = open(p, "rb").read().decode("latin-1")
            except OSError:
                continue
            if KEYWORD_USE.search(code_text(b)):
                print(f"LIST\t{slug}\t{rel}\tuses `class` as a keyword")
                continue
            for new in NAMES:
                out = subprocess.run([sys.executable, os.path.join(REPO, "scripts", "lpc_rename_ident.py"), slug, "class", new, rel] + (["--apply"] if apply_ else []),
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
