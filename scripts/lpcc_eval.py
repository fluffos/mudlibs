#!/usr/bin/env python3
"""scripts/lpcc_eval.py SLUG (SRCFILE | --code 'LPC statements') [--head] [--rmdir DIR ...] [--at PATH]

Run a snippet of LPC inside a vendored lib without a wizard or a play session (KB 08 10.16): builds a pristine tree of SLUG (`scripts/pristine_tree.sh`) plus the
working-tree edits of that lib (`lpc_warnings.sync_changes`; --head leaves them out, which is how a before / after pair is made), drops the snippet in as
`/tmp/zzeval.lpc` and loads it with `lpcc --batch` (memory-capped like `lpc_listcheck.sh`).  The object's `create()` runs; `--code` wraps the statements in
`void create() { ... }`, a SRCFILE is a whole object.  Print with `debug_message(sprintf("ZZT %O\\n", x))`: the lpcc output block of the object is shown.
Examples: a daemon table restored from a save (`object q = load_object("/adm/daemons/questd"); debug_message(sprintf("ZZT %d\\n", sizeof(keys(q->getAssigner()))));`),
a shop that restores its stock (`object b = load_object("/d/city/dangpu")->findbox(); debug_message(sprintf("ZZT %d\\n", sizeof(all_inventory(b))));`).
--rmdir DIR (repeatable, a path inside the mudlib: `/verbs/spells`) removes that EMPTY directory from the staged tree before the run: the state of a plain `git clone`, which has no
empty directories (the staged tree recreates the ones `scripts/wasm_keep_dirs.txt` lists, as the site does; KB 06 7.212).
--at PATH (a path inside the mudlib, default `/tmp/zzeval.lpc`) puts the snippet there: a master that refuses to load objects from `/tmp` (Dead Souls: `valid_object()` denies `/tmp`, `/ftp`, `/log`, `/secure/save`) needs `--at /open/zzeval.lpc`.
The tree is `${LPC_SCRATCH:-~/.cache/lpc-scratch}/evaltree-SLUG`, rebuilt on every run and removed when the run ends (`KEEP_TREE=1` keeps it).  Nothing in the repository is touched."""
import os
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SCR = os.environ.get("LPC_SCRATCH") or os.path.expanduser("~/.cache/lpc-scratch")


def main():
    argv = sys.argv[1:]
    rmdirs = []
    while "--rmdir" in argv:
        i = argv.index("--rmdir")
        rmdirs.append(argv[i + 1])
        del argv[i:i + 2]
    at = "/tmp/zzeval.lpc"
    if "--at" in argv:
        i = argv.index("--at")
        at = argv[i + 1]
        del argv[i:i + 2]
    args = [a for a in argv if a != "--head"]
    head = "--head" in argv
    if len(args) < 2:
        sys.exit(__doc__)
    slug = args[0]
    if args[1] == "--code":
        if len(args) < 3:
            sys.exit(__doc__)
        src = ("void create() {\n" + args[2] + "\n}\n").encode("utf-8")
    else:
        src = open(args[1], "rb").read()
    dest = f"{SCR}/evaltree-{slug}"
    subprocess.run(["rm", "-rf", dest])
    subprocess.run([f"{REPO}/scripts/pristine_tree.sh", slug, "45993", dest], cwd=REPO, capture_output=True)
    work = f"{dest}/libs/{slug}/work"
    for ln in open(f"{dest}/libs/{slug}/config.fluffos", encoding="utf-8", errors="replace"):          # a mudlib below work/ (lima: work/lib)
        if ln.startswith("mudlib directory"):
            work = ln.split(":", 1)[1].strip()
    os.makedirs(f"{work}/log", exist_ok=True)
    if not head:
        sys.path.insert(0, f"{REPO}/scripts")
        import lpc_warnings as lw
        lw.sync_changes(slug, f"{dest}/libs/{slug}")
    for d in rmdirs:
        try:
            os.rmdir(work + "/" + d.strip("/"))
        except OSError as e:
            print(f"--rmdir {d}: {e}", file=sys.stderr)
    os.makedirs(os.path.dirname(work + at), exist_ok=True)
    open(work + at, "wb").write(src)
    memkb = subprocess.run(["python3", f"{REPO}/scripts/lpcc_mem.py"], cwd=REPO, capture_output=True, text=True).stdout.strip()
    lpcc = os.environ.get("LPCC") or os.path.expanduser("~/src/fluffos/build-debug/src/lpcc")
    cmd = f"cd {dest}/libs/{slug} && ulimit -v {memkb} && echo {at} | timeout 600 {lpcc} --batch config.fluffos 2>&1"
    out = subprocess.run(["bash", "-c", cmd], capture_output=True, text=True, errors="replace").stdout
    i = out.find("===== " + at)
    print(out[i:i + 6000] if i >= 0 else out[-3000:])
    if os.environ.get("KEEP_TREE") != "1":
        subprocess.run(["rm", "-rf", dest])      # rebuilt on every run anyway; a left-over tree per lib used up the disk's inodes (2026-10-22)


if __name__ == "__main__":
    main()
