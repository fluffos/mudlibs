#!/usr/bin/env python3
"""scripts/lpc_save_restore_check.py [-v] [--driver-all] SLUG...|FILE...|--all

Asks the driver whether tracked save files restore.  Each text save (a `.o` whose first line is `#/...`) that
`lpc_save_encoding.parses()` rejects -- or every one, with --driver-all -- is copied into a throwaway mudlib under
$LPC_SCRATCH/rtlib (a master that allows everything, an empty simul_efun), next to an object that declares every
variable the file names as `mixed` and calls restore_object() on it under catch().  lpcc runs them in batches and the
script prints `FAIL <path>\t<error>` for each save the driver refuses (`ok <path>` too with -v).

The parser is stricter than the driver in places (22 of 795 suspects restored fine, 2026-10-15), so a repair list comes
from here, not from the parser.  A file that only looks like a save (an LPC source named `.o`, starting `#include`) is
skipped.  Repairs: `scripts/lpc_save_encoding.py --from-raw` (KB 03 section 4.4)."""
import os
import re
import shutil
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import lpcc_mem  # noqa: E402
from lpc_save_encoding import parses  # noqa: E402

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SCR = os.path.join(os.environ.get("LPC_SCRATCH") or os.path.expanduser("~/.cache/lpc-scratch"), "rtlib")
LPCC = os.environ.get("LPCC") or os.path.expanduser("~/src/fluffos/build-debug/src/lpcc")
RESERVED = set("""int string object mapping mixed float buffer void status function class struct private static nosave
public protected varargs nomask inherit if else return while for foreach switch case default break continue do in efun
new catch sscanf parse_command time_expression ref array closure symbol""".split())
MASTER = """int valid_read(string f, mixed o, string fn) { return 1; }
int valid_write(string f, mixed o, string fn) { return 1; }
int valid_override(string file, string name, string mainfile) { return 1; }
int valid_seteuid(object ob, string id) { return 1; }
void log_error(string f, string m) { debug_message("COMPILE " + f + ": " + m); }
mixed error_handler(mapping e, int caught) { debug_message("RTERR " + e["error"]); return 0; }
string get_root_uid() { return "ROOT"; }
string get_bb_uid() { return "BB"; }
string creator_file(string f) { return "ROOT"; }
string domain_file(string f) { return "ROOT"; }
string author_file(string f) { return "ROOT"; }
object connect(int port) { return 0; }
"""
BATCH = 400


def setup():
    shutil.rmtree(SCR, ignore_errors=True)
    for d in ("lib/single", "lib/log", "lib/include", "lib/zz/data"):
        os.makedirs(os.path.join(SCR, d))
    open(os.path.join(SCR, "lib/single/master.c"), "w").write(MASTER)
    open(os.path.join(SCR, "lib/single/simul_efun.c"), "w").write("// empty\n")
    open(os.path.join(SCR, "config.rt"), "w").write(
        "name : rtlib\nmud ip : 127.0.0.1\nport number : 65011\nmudlib directory : %s/lib\nlog directory : /log\n"
        "include directories : /include\nmaster file : /single/master\nsimulated efun file : /single/simul_efun\n"
        "debug log file : debug.log\ndefault fail message : What?\ndefault error message :\ntime to clean up : 1200\n"
        "time to reset : 1800\ntime to swap : 600\nmaximum evaluation cost : 30000000\nmaximum array size : 1000000\n"
        "maximum mapping size : 1000000\nmaximum string length : 20000000\nmaximum buffer size : 4000000\n"
        "maximum read file size : 20000000\nmaximum byte transfer : 20000000\n" % SCR)


def candidates(args, everything):
    pat = (["libs/*/work/*.o"] if "--all" in args else
           [a if "/" in a else "libs/%s/work/*.o" % a for a in args if not a.startswith("-")])
    files = subprocess.run(["git", "ls-files", "-z", "--"] + pat, cwd=REPO, capture_output=True).stdout.split(b"\0")
    for f in files:
        if not f:
            continue
        rel = f.decode("utf-8", "surrogateescape")
        try:
            b = open(os.path.join(REPO, rel), "rb").read()
        except OSError:
            continue
        if not b.startswith(b"#/"):
            continue
        try:
            t = b.decode("utf-8")
        except UnicodeDecodeError:
            continue   # never transcoded: lpc_save_encoding.py (without --from-raw) handles those
        if everything or not parses(t):
            yield rel, b


def run(batch):
    """batch: [(rel, bytes)] -> {rel: error or None}"""
    shutil.rmtree(os.path.join(SCR, "lib/zz"), ignore_errors=True)
    os.makedirs(os.path.join(SCR, "lib/zz/data"))
    objs = []
    for i, (rel, b) in enumerate(batch):
        open(os.path.join(SCR, "lib/zz/data/f%d.o" % i), "wb").write(b)
        names = sorted({m.decode() for m in re.findall(rb"(?m)^([A-Za-z_][A-Za-z0-9_]*) ", b)} - RESERVED)
        src = ("mixed " + ", ".join(names) + ";\n" if names else "") + (
            'void create() { mixed zz_e9; int zz_r9; zz_e9 = catch(zz_r9 = restore_object("/zz/data/f%d")); '
            'debug_message(sprintf("RT %d ret=%%O err=%%O", zz_r9, zz_e9)); }\n' % (i, i))
        open(os.path.join(SCR, "lib/zz/t%d.c" % i), "w").write(src)
        objs.append("zz/t%d" % i)
    out = subprocess.run([LPCC, "--batch", "config.rt"], cwd=SCR, input="\n".join(objs) + "\n", capture_output=True,
                         text=True, errors="replace", preexec_fn=lpcc_mem.cap, timeout=3600).stdout
    res = {rel: "no answer (lpcc died before this object)" for rel, _ in batch}
    for l in out.splitlines():
        m = re.match(r"RT (\d+) ret=\S* err=(.*)", l)
        if m:
            e = m.group(2)
            res[batch[int(m.group(1))][0]] = None if e == "0" else e.strip('"').lstrip("*").split(" while restoring")[0]
    return res


def main():
    args = sys.argv[1:]
    verbose = "-v" in args
    files = list(candidates(args, "--driver-all" in args))
    setup()
    bad = 0
    for k in range(0, len(files), BATCH):
        for rel, err in run(files[k:k + BATCH]).items():
            if err:
                bad += 1
                print("FAIL %s\t%s" % (rel, err))
            elif verbose:
                print("ok   %s" % rel)
    print("%d save(s) checked, %d refused by the driver" % (len(files), bad))


if __name__ == "__main__":
    main()
