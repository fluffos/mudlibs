"""Write config.fluffos for every converted lib (has work/, no
config.fluffos yet) that doesn't already have one -- ports auto-assigned
starting from the next free one in scripts/lib_numbering.json.

Usage: python3 scripts/lib_write_config.py
Output: libs/<slug>/config.fluffos for each newly-configured lib, plus
scripts/lib_write_config_results.json recording what was done (status,
port, detected master/simul_efun paths) for the next pipeline step to
consume.
"""
import os, json

MUDLIB_ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
LIBS_DIR = os.path.join(MUDLIB_ROOT, "libs")
NUMBERING = os.path.join(MUDLIB_ROOT, "scripts", "lib_numbering.json")
RESULTS_OUT = os.path.join(MUDLIB_ROOT, "scripts", "lib_write_config_results.json")

TEMPLATE = """###############################################################################
#              Customizable runtime config file for MudOS 0.9.20              #
###############################################################################
# name of this mud
name : {name}

# port number to accept users on
port number : {port}

# absolute pathname of mudlib
mudlib directory : {mudlib_dir}

# debug.log and author/domain stats are stored here
log directory : /log

# the directories which are searched by #include <...>
include directories : /include

# Directory to save binaries in.  (if BINARIES is defined)
save binaries directory : /binaries

# the file which defines the master object
master file : {master}

# The global include file is included automatically.
global include file : <globals.h>

# the file where all global simulated efuns are defined.
simulated efun file : {simul_efun}

# alternate debug.log file name (assumed to be in specified 'log directory')
debug log file : debug.log

time to clean up : 50000
time to swap : 10000
time to reset : 1200
maximum bits in a bitfield : 1200
maximum local variables : 40
maximum evaluation cost : 700000
maximum array size : 25000
maximum buffer size : 600000
maximum mapping size : 25000
inherit chain size : 60
maximum string length : 300000
maximum read file size : 300000
maximum byte transfer : 20000
hash table size : 7001
object table size : 1501
default fail message : 什麼？

maximum users : 70
evaluator stack size : 1000
compiler stack size : 200
maximum call depth : 30
living hash table size : 100
"""

def find_master_and_simul(work):
    # AGENTS.md §7.42: a content NPC/quest object can also be named
    # master.c (e.g. a "grandmaster" boss at adm/daemons/story/master.c)
    # -- prefer a candidate that actually defines `object connect(` (the
    # real master_ob's telltale apply) over the first filename match.
    master_candidates = []
    simul_rel = None
    for dirpath, dirnames, filenames in os.walk(os.path.join(work, 'adm')):
        for fn in filenames:
            base = fn.lower()
            if base in ('master.c', 'master.lpc'):
                fpath = os.path.join(dirpath, fn)
                rel = os.path.relpath(fpath, work)
                rel_slash = '/' + os.path.splitext(rel)[0].replace(os.sep, '/')
                try:
                    with open(fpath, encoding='utf-8', errors='replace') as f:
                        has_connect = 'object connect(' in f.read()
                except Exception:
                    has_connect = False
                master_candidates.append((has_connect, rel_slash))
            if base in ('simul_efun.c', 'simul_efun.lpc') and simul_rel is None:
                rel = os.path.relpath(os.path.join(dirpath, fn), work)
                simul_rel = '/' + os.path.splitext(rel)[0].replace(os.sep, '/')
    master_rel = None
    if master_candidates:
        # True (has connect) sorts after False, so this picks a connect()-
        # bearing candidate if any exist, else falls back to the first match
        master_candidates.sort(key=lambda c: c[0])
        master_rel = master_candidates[-1][1]
    return master_rel, simul_rel

def next_free_port():
    with open(NUMBERING, encoding='utf-8') as f:
        d = json.load(f)
    ports = [int(l['port']) for l in d['libs'] if l.get('port')]
    return max(ports) + 1 if ports else 40001

def main():
    port = next_free_port()
    results = {}
    slugs = sorted(
        s for s in os.listdir(LIBS_DIR)
        if os.path.isdir(os.path.join(LIBS_DIR, s, 'work'))
        and not os.path.exists(os.path.join(LIBS_DIR, s, 'config.fluffos'))
    )
    print(f"{len(slugs)} libs have work/ but no config.fluffos yet; starting at port {port}")
    for slug in slugs:
        work = os.path.join(LIBS_DIR, slug, 'work')
        master, simul = find_master_and_simul(work)
        if not master:
            results[slug] = {'status': 'no-master-found'}
            print(f"{slug}: NO MASTER FOUND")
            continue
        cfg_path = os.path.join(LIBS_DIR, slug, 'config.fluffos')
        content = TEMPLATE.format(
            name=slug,
            port=port,
            mudlib_dir=work,
            master=master,
            simul_efun=simul or '/adm/obj/simul_efun',
        )
        with open(cfg_path, 'w', encoding='utf-8') as f:
            f.write(content)
        results[slug] = {'status': 'ok', 'port': port, 'master': master, 'simul_efun': simul}
        print(f"{slug}: port={port} master={master} simul_efun={simul}")
        port += 1

    with open(RESULTS_OUT, 'w', encoding='utf-8') as f:
        json.dump(results, f, ensure_ascii=False, indent=2)
    print(f"wrote {RESULTS_OUT}")

if __name__ == '__main__':
    main()
