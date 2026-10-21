#!/usr/bin/env python3
"""scripts/lpcc_eval.py SLUG (SRCFILE | --code 'LPC statements') [--head]

Run a snippet of LPC inside a vendored lib without a wizard or a play session (KB 08 10.16): builds a pristine tree of SLUG (`scripts/pristine_tree.sh`) plus the
working-tree edits of that lib (`lpc_warnings.sync_changes`; --head leaves them out, which is how a before / after pair is made), drops the snippet in as
`/tmp/zzeval.lpc` and loads it with `lpcc --batch` (memory-capped like `lpc_listcheck.sh`).  The object's `create()` runs; `--code` wraps the statements in
`void create() { ... }`, a SRCFILE is a whole object.  Print with `debug_message(sprintf("ZZT %O\\n", x))`: the lpcc output block of the object is shown.
Examples: a daemon table restored from a save (`object q = load_object("/adm/daemons/questd"); debug_message(sprintf("ZZT %d\\n", sizeof(keys(q->getAssigner()))));`),
a shop that restores its stock (`object b = load_object("/d/city/dangpu")->findbox(); debug_message(sprintf("ZZT %d\\n", sizeof(all_inventory(b))));`).
The tree is `${LPC_SCRATCH:-~/.cache/lpc-scratch}/evaltree-SLUG`, rebuilt on every run.  Nothing in the repository is touched."""
import os
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SCR = os.environ.get("LPC_SCRATCH") or os.path.expanduser("~/.cache/lpc-scratch")


def main():
    args = [a for a in sys.argv[1:] if a != "--head"]
    head = "--head" in sys.argv[1:]
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
    os.makedirs(f"{work}/log", exist_ok=True)
    if not head:
        sys.path.insert(0, f"{REPO}/scripts")
        import lpc_warnings as lw
        lw.sync_changes(slug, f"{dest}/libs/{slug}")
    os.makedirs(f"{work}/tmp", exist_ok=True)
    open(f"{work}/tmp/zzeval.lpc", "wb").write(src)
    memkb = subprocess.run(["python3", f"{REPO}/scripts/lpcc_mem.py"], cwd=REPO, capture_output=True, text=True).stdout.strip()
    lpcc = os.environ.get("LPCC") or os.path.expanduser("~/src/fluffos/build-debug/src/lpcc")
    cmd = f"cd {dest}/libs/{slug} && ulimit -v {memkb} && echo /tmp/zzeval.lpc | timeout 600 {lpcc} --batch config.fluffos 2>&1"
    out = subprocess.run(["bash", "-c", cmd], capture_output=True, text=True, errors="replace").stdout
    i = out.find("===== /tmp/zzeval.lpc")
    print(out[i:i + 6000] if i >= 0 else out[-3000:])


if __name__ == "__main__":
    main()
