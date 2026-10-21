#!/usr/bin/env python3
"""scripts/lpcc_bare.py SLUG FILE...: call each command file's entry function with NO argument inside one `lpcc --batch` eval of a pristine tree (no login, no wizard).

FILE is a path inside the mudlib (`cmds/creators/force.lpc`).  The entry is `main(me, 0)` or `cmd(0)` (the first function the object has); the error caught
is printed as `ZZT file fn error-first-line`.  The efun named in the error says whether the 0 reached it (`sscanf`, `lower_case`...) or an earlier use of
`me` failed first (a reason to read the file).  Output: one line per file on stdout (`/cmds/wiz/test *Bad argument 1 to present() ...`, `ok` when the bare call returned).  Pair it with `scripts/lpc_fix_bare_arg.py` (KB 06 7.336): the fixer plans the guards, this proves each candidate crashes before the edit and answers after it.
A command that reads `this_player()` before its parameter fails on `environment(0)` here (nobody is acting): read such a file by hand."""
import os
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SCR = os.environ.get("LPC_SCRATCH") or os.path.expanduser("~/.cache/lpc-scratch")


def main():
    slug, files = sys.argv[1], sys.argv[2:]
    lits = ",\n        ".join('"/' + f.rsplit(".", 1)[0].lstrip("/") + '"' for f in files)
    src = ('void create() {\n    foreach (string f in ({\n        ' + lits + '\n    })) {\n'
           '        object ob;\n        string e = catch(ob = load_object(f));\n'
           '        if (e || !ob) { debug_message(sprintf("ZZT %s LOADFAIL %s\\n", f, replace_string(e || "0", "\\n", " "))); continue; }\n'
           '        if (function_exists("main", ob)) e = catch(call_other(ob, "main", this_object(), 0));\n'
           '        else if (function_exists("cmd", ob)) e = catch(call_other(ob, "cmd", 0));\n'
           '        else { debug_message(sprintf("ZZT %s NOENTRY\\n", f)); continue; }\n'
           '        debug_message(sprintf("ZZT %s %s\\n", f, e ? replace_string(e, "\\n", " ") : "ok"));\n'
           '    }\n}\n')
    os.makedirs(f"{SCR}/bare", exist_ok=True)
    path = f"{SCR}/bare/bare_eval_{slug}.lpc"
    open(path, "w").write(src)
    out = subprocess.run([sys.executable, f"{REPO}/scripts/lpcc_eval.py", slug, path, "--at", "/open/zzeval.lpc"], capture_output=True, text=True, timeout=1500).stdout
    for ln in out.splitlines():
        if ln.startswith("ZZT "):
            print(ln[4:][:240])
        elif "FAIL" in ln and "zzeval" in ln:
            print("EVAL-FAILED", ln)


main()
