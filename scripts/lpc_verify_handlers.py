#!/usr/bin/env python3
"""scripts/lpc_verify_handlers.py [--at PATH] SLUG PAIRS.tsv

Runtime check of the static finding of `lpc_scan_callout_targets.py` (KB 06 section 7.349): for each `file<TAB>function` line of PAIRS.tsv load the object of
`file` inside one `lpcc --batch` eval of a pristine tree of SLUG (the working-tree edits of the lib included, like `lpcc_eval.py`) and ask
`function_exists(function, ob)`.  Prints `ZZT file function MISSING|EXISTS|NOCOMPILE|LOADFAIL|CRASH|NOANSWER`; MISSING confirms the scan (the driver will answer a verb bound to
it with `Function for verb '..' not found.`), EXISTS is a miss of the static resolver, NOCOMPILE is an object that does not compile (the finding is moot until it does), LOADFAIL
an object whose create() raises even inside a verb of the eval object (a create() that needs a real player; the finding stands unproved by the runtime), CRASH is an object whose load ended the driver (the
rest of the chunk is run again without it), NOANSWER is a pair nothing answered for (the eval did not load anywhere): the static finding stands unproved for it.
The objects are loaded in chunks of 150 with `reset_eval_cost()` between them; the ones whose `create()` raised are loaded again inside a verb of the eval object (`command()` makes
`this_player()` the eval object, which answers 0 to `query()` / `query_temp()` / `query_skill()`: wdxtym's 891 armour and weapon files, whose `create()` reads the forger's
data, load only that way).  A master that refuses `/tmp` (ShadowGate's, Dead Souls') gets the eval object at the
first of `/tmp`, `/open`, `/d`, `/cmds`, `/std`, `/obj`, `/daemon`, `/clone` that answers; `--at PATH` forces one."""
import os
import re
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SCR = os.environ.get("LPC_SCRATCH") or os.path.expanduser("~/.cache/lpc-scratch")
CHUNK = 150
AT_CANDIDATES = ["/tmp/zzeval.lpc", "/open/zzeval.lpc", "/d/zzeval.lpc", "/cmds/zzeval.lpc", "/std/zzeval.lpc", "/obj/zzeval.lpc", "/daemon/zzeval.lpc", "/clone/zzeval.lpc"]
MAX_RESTARTS = 15


def lpc_str(s):
    return '"%s"' % s.replace("\\", "\\\\").replace('"', '\\"')


def source(chunk, fake=False):
    lits = ",\n        ".join("({ %s, %s })" % (lpc_str(f.rsplit(".", 1)[0]), lpc_str(h)) for f, h in chunk)
    head = 'void create() {\n' if not fake else ('mixed query(mixed a, mixed b) { return 0; }\nmixed query_temp(mixed a, mixed b) { return 0; }\nmixed query_skill(mixed a, mixed b) { return 0; }\n'
                                              'int probe(string arg) {\n')
    tail = '}\n' if not fake else ('    return 1;\n}\nvoid create() { enable_commands(); add_action("probe", "zzprobe"); command("zzprobe"); }\n')
    return (head + '    foreach (mixed *p in ({\n        ' + lits + '\n    })) {\n'
            '        object ob;\n        string e;\n        reset_eval_cost();\n'
            '        e = catch(ob = load_object(p[0]));\n'
            '        if (e || !ob) { debug_message(sprintf("ZZT %s %s %s\\n", p[0], p[1], (e && strsrch(e, "No program in object") >= 0) ? "NOCOMPILE" : "LOADFAIL")); continue; }\n'
            '        debug_message(sprintf("ZZT %s %s %s\\n", p[0], p[1], function_exists(p[1], ob) ? "EXISTS" : "MISSING"));\n'
            '    }\n' + tail)


def run(slug, chunk, at, fake=False):
    path = f"{SCR}/verify/verify_{slug}.lpc"
    os.makedirs(f"{SCR}/verify", exist_ok=True)
    open(path, "w", encoding="utf-8").write(source(chunk, fake))
    try:
        out = subprocess.run([sys.executable, f"{REPO}/scripts/lpcc_eval.py", slug, path, "--at", at], capture_output=True, text=True, timeout=3000).stdout
    except subprocess.TimeoutExpired:
        return []
    return ["ZZT %s %s %s" % m.groups() for m in re.finditer(r"ZZT (\S+) (\S+) (MISSING|EXISTS|LOADFAIL|NOCOMPILE)", out)]      # a compiler diagnostic can precede the marker on its line


def main():
    argv = sys.argv[1:]
    forced = None
    if "--at" in argv:
        i = argv.index("--at")
        forced = argv[i + 1]
        del argv[i:i + 2]
    if len(argv) < 2:
        sys.exit(__doc__)
    slug, pairs_file = argv[0], argv[1]
    pairs = []
    for ln in open(pairs_file, encoding="utf-8"):
        f = ln.rstrip("\n").split("\t")
        if len(f) >= 2:
            pairs.append((f[0], f[1]))
    good = forced
    result = {}
    for ci in range(0, len(pairs), CHUNK):
        todo = pairs[ci:ci + CHUNK]
        restarts = 0
        while todo:
            got = []
            for at in ([good] if good else AT_CANDIDATES):
                got = run(slug, todo, at)
                if got:
                    good = at
                    break
            if not got:
                break
            seen = set()
            for ln in got:
                p = ln.split(" ")
                result[(p[1], p[2])] = p[3]
                seen.add((p[1], p[2]))
            rest = [q for q in todo if (q[0].rsplit(".", 1)[0], q[1]) not in seen]
            if not rest or restarts >= MAX_RESTARTS:
                todo = rest
                break
            culprit = rest[0][0].rsplit(".", 1)[0]      # the objects load in order: the first one without an answer ended the driver (or its answer was lost in the compiler's output)
            mine = [q for q in rest if q[0].rsplit(".", 1)[0] == culprit]
            alone = run(slug, mine, good)           # on its own the answer is not lost; only an object that still gives none is a CRASH
            for ln in alone:
                p = ln.split(" ")
                result[(p[1], p[2])] = p[3]
            for q in mine:
                result.setdefault((culprit, q[1]), "CRASH")
            todo = [q for q in rest if q[0].rsplit(".", 1)[0] != culprit]
            restarts += 1
    # an object whose create() reads this_player() loads only inside a player's command: run the LOADFAIL ones again inside a verb of the eval object (command() gives
    # this_player() = the eval object, which answers 0 to query() / query_temp() / query_skill())
    again = [(f, h) for f, h in pairs if result.get((f.rsplit(".", 1)[0], h)) == "LOADFAIL"]
    for ci in range(0, len(again), CHUNK):
        todo = again[ci:ci + CHUNK]
        for at in ([good] if good else AT_CANDIDATES):
            got = run(slug, todo, at, fake=True)
            if got:
                for ln in got:
                    p = ln.split(" ")
                    if p[3] in ("MISSING", "EXISTS"):
                        result[(p[1], p[2])] = p[3]
                break
    for f, h in pairs:
        key = (f.rsplit(".", 1)[0], h)
        print(f"ZZT {key[0]} {key[1]} {result.get(key, 'NOANSWER')}")


if __name__ == "__main__":
    main()
