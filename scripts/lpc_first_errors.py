#!/usr/bin/env python3
"""scripts/lpc_first_errors.py LISTFILE OUT.tsv

The first compiler errors of objects that do not load.  LISTFILE lines are `slug<TAB>/path/of/object` (no extension), for example the `NOCOMPILE` / `CRASH` objects of
`lpc_verify_handlers.py` or the failures of a `lpc_listcheck.sh` run.  Per lib one `lpcc --batch` eval (`lpcc_eval.py`) loads every listed object inside `catch()` and
records the diagnostics the driver printed for it; OUT.tsv gets `slug<TAB>object<TAB>first error || second error || third error`, one line per object (nothing after
the last tab: the object loaded).  Read the FIRST error, never the flood behind it: an unterminated string (KB 03 section 4.6, fifth round) prints one
`Illegal character 0xNN` per byte of the rest of the file, and a stray `->` (KB 04 section 6.29) makes the next error a cascade (`Illegal LHS` on a correct line).
A master that refuses `/tmp` (ShadowGate's, Dead Souls') gets the eval object at the first of `/tmp`, `/open`, `/d`, `/cmds`, `/std`, `/obj`, `/daemon`, `/clone`
that answers.  Libs run one after the other: one lpcc VM at a time."""
import collections
import os
import re
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SCR = os.environ.get("LPC_SCRATCH") or os.path.expanduser("~/.cache/lpc-scratch")
AT = ["/tmp/zzeval.lpc", "/open/zzeval.lpc", "/d/zzeval.lpc", "/cmds/zzeval.lpc", "/std/zzeval.lpc", "/obj/zzeval.lpc", "/daemon/zzeval.lpc", "/clone/zzeval.lpc"]


def main():
    if len(sys.argv) < 3:
        sys.exit(__doc__)
    per = collections.OrderedDict()
    for ln in open(sys.argv[1], encoding="utf-8"):
        f = ln.rstrip("\n").split("\t")
        if len(f) >= 2:
            per.setdefault(f[0], []).append(f[1])
    os.makedirs(f"{SCR}/verify", exist_ok=True)
    out = open(sys.argv[2], "w", encoding="utf-8")
    for slug, files in per.items():
        lits = ",\n".join('"%s"' % x.replace("\\", "\\\\").replace('"', '\\"') for x in files)
        src = ('void create() {\n  foreach (string f in ({\n' + lits + '\n  })) {\n    string e;\n    reset_eval_cost();\n    debug_message("ZZTBEGIN " + f + "\\n");\n'
               '    e = catch(load_object(f));\n    debug_message("ZZTEND " + f + (e ? " FAIL" : " OK") + "\\n");\n  }\n}\n')
        path = f"{SCR}/verify/nc_{slug}.lpc"
        open(path, "w", encoding="utf-8").write(src)
        text = ""
        for at in AT:
            try:
                text = subprocess.run([sys.executable, f"{REPO}/scripts/lpcc_eval.py", slug, path, "--at", at], capture_output=True, text=True, timeout=1500).stdout
            except subprocess.TimeoutExpired:
                text = ""
            if "ZZTBEGIN" in text:
                break
        blocks = re.split(r"ZZTBEGIN (\S+)\n", text)
        for i in range(1, len(blocks), 2):
            f, body = blocks[i], blocks[i + 1]
            body = body.split("ZZTEND")[0]
            errs = [l.strip() for l in body.splitlines() if re.search(r"error|Error", l) and "note:" not in l][:3]
            out.write(f"{slug}\t{f}\t" + " || ".join(e[:230] for e in errs) + "\n")
        out.flush()


if __name__ == "__main__":
    main()
