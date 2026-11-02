#!/usr/bin/env python3
"""scripts/lpc_fix_money_path.py [--apply] [--list] [--all | SLUG...]

`new("/clone/money/silver")`, `carry_object("/clone/money/" + type)`, `file_size("/clone/money/" + to + ".lpc")`: the xkx lineage keeps its coins under `/clone/money/`, the ES2 lineage under
`/obj/money/`, and a lib whose code kept the first spelling while its files (and its own `SILVER_OB "/obj/money/silver"` macro) are the second never finds a coin: the charity boxes of
tiexuejianghu / fys (`init()` raises for every newcomer: `ob = new(..); ob->set_amount(10)` on 0), the Chengdu money changers `qian` / `old-qian` / `qian1` and the bank room base
(`convert` / `deposit` answer `你想兑换哪一种钱？` for every currency), every NPC that carries cash (`carry_object("/clone/money/" + type)` in the NPC base) (KB 06 section 7.366).
A lib is taken when it has no `clone/money/silver.lpc` but has `obj/money/silver.lpc`; every `/clone/money/` of its `.lpc` / `.h` files (wizard, backup and test trees left alone) becomes
`/obj/money/`, a literal `"/clone/money/<name>"` only when `obj/money/<name>.lpc` exists (the others are listed).  Binary mode, the file's own line endings; idempotent.
Dry run unless `--apply`; `--list` prints every site."""
import os
import re
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
GITLINKS = {"nt7", "xkx100utf8", "fy2005", "nightmare3", "residuum", "sanguozhi", "oxidus", "deadsouls_fluffos"}
SKIP = re.compile(r"/(u|w|wiz|wizard|wizards|open|players|backup|backups|bak|old|test|tests|tmp|data|log|realms|doc|docs|example|examples|orphaned-dir)/|[-_.](bak|old)|class_bak|/海洋2002/")
OLD = rb"(?<![\w/])/clone/money/"             # not `/d/obj/clone/money/`: the area's own copy of the directory
NEW = b"/obj/money/"
STATIC = re.compile(rb'"/clone/money/([A-Za-z_]\w*)(?:\.lpc|\.c)?"')


def taken(slug):
    w = os.path.join(REPO, "libs", slug, "work")
    return (not os.path.exists(os.path.join(w, "clone/money/silver.lpc")) and not os.path.exists(os.path.join(w, "clone/money/silver.c"))
            and os.path.exists(os.path.join(w, "obj/money/silver.lpc")))


def tracked(slug):
    out = subprocess.run(["git", "grep", "-l", "-z", "-F", "/clone/money/", "--", f"libs/{slug}/work/*.lpc", f"libs/{slug}/work/*.h"], cwd=REPO, capture_output=True).stdout
    pre = f"libs/{slug}/work"
    for p in out.split(b"\0"):
        if p:
            s = p.decode("utf-8", "surrogateescape")
            if not SKIP.search(s[len(pre):]):
                yield s


def main():
    argv = sys.argv[1:]
    apply, listing = "--apply" in argv, "--list" in argv
    names = [a for a in argv if not a.startswith("--")]
    if "--all" in argv:
        names = sorted(p for p in os.listdir(os.path.join(REPO, "libs")) if os.path.isdir(os.path.join(REPO, "libs", p, "work")))
    if not names:
        sys.exit(__doc__)
    total = 0
    for slug in names:
        if slug in GITLINKS or not taken(slug):
            continue
        w = os.path.join(REPO, "libs", slug, "work")
        pre = f"libs/{slug}/work/"
        nfile = nsite = 0
        for rel in tracked(slug):
            p = os.path.join(REPO, rel)
            try:
                data = open(p, "rb").read()
            except OSError:
                continue
            out, last, k = [], 0, 0
            for m in re.finditer(OLD, data):
                lit = STATIC.match(data, m.start() - 1) if data[m.start() - 1:m.start()] == b'"' else None
                lineno = data.count(b"\n", 0, m.start()) + 1
                if lit and not os.path.exists(os.path.join(w, "obj/money", lit.group(1).decode() + ".lpc")):
                    print(f"KEEP {slug} {rel[len(pre):]}:{lineno} no obj/money/{lit.group(1).decode()}.lpc")
                    continue
                out.append(data[last:m.start()])
                out.append(NEW)
                last = m.end()
                k += 1
                if listing:
                    line = data.split(b"\n")[lineno - 1].decode("utf-8", "replace").strip()
                    print(f"{slug} {rel[len(pre):]}:{lineno} {line[:100]}")
            if not k:
                continue
            nfile += 1
            nsite += k
            if apply:
                out.append(data[last:])
                open(p, "wb").write(b"".join(out))
        total += nsite
        if nsite:
            print(f"{slug}: {nsite} site(s) in {nfile} file(s)" + ("" if apply else " (plan only)"), file=sys.stderr)
    print(f"{total} site(s)", file=sys.stderr)


if __name__ == "__main__":
    main()
