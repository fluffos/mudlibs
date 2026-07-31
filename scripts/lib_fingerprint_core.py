import os, hashlib, json

MUDLIB_ROOT = "/home/sunyc/src/mudlib"
LIBS_DIR = os.path.join(MUDLIB_ROOT, "libs")
OUT = os.path.join(os.path.dirname(__file__), 'lib_core_fingerprints.json')

# Curated "engine signature" filenames per AGENTS.md §2.1 -- these are the
# files this project's own manual lineage-recognition process already
# relies on (master/security/chinese-detection/dbase/simul_efun). Matched
# by basename (case-insensitive), regardless of which directory they live
# in across different lineages (adm/obj/master.c vs adm/single/master.c
# vs adm/kernel/master.c etc).
CORE_BASENAMES = {
    'master.c', 'master.lpc',
    'chinese.c', 'chinese.lpc',
    'chinesed.c', 'chinesed.lpc',
    'logind.c', 'logind.lpc',
    'named.c', 'named.lpc',
    'securityd.c', 'securityd.lpc',
    'security.c', 'security.lpc',
    'dbase.c', 'dbase.lpc',
    'wizard.c', 'wizard.lpc',
    'simul_efun.c', 'simul_efun.lpc',
}

def core_fingerprint_one(slug):
    libdir = os.path.join(LIBS_DIR, slug)
    base = os.path.join(libdir, 'work')
    if not os.path.isdir(base):
        base = os.path.join(libdir, 'raw')
    if not os.path.isdir(base):
        return None

    # basename -> content hash (first match wins if dupes; rare)
    core = {}
    for dirpath, dirnames, filenames in os.walk(base):
        parts = dirpath.split(os.sep)
        if any(p in ('log', 'save', 'data', 'binaries', '.git') for p in parts):
            continue
        for fn in filenames:
            if fn.lower() not in CORE_BASENAMES:
                continue
            fpath = os.path.join(dirpath, fn)
            try:
                with open(fpath, 'rb') as f:
                    content = f.read()
            except Exception:
                continue
            h = hashlib.md5(content).hexdigest()
            key = fn.lower().rsplit('.', 1)[0]  # normalize master.c/master.lpc -> master
            # keep first occurrence per normalized key
            core.setdefault(key, h)
    return core

def main():
    slugs = sorted(os.listdir(LIBS_DIR))
    slugs = [s for s in slugs if os.path.isdir(os.path.join(LIBS_DIR, s))]
    results = {}
    for s in slugs:
        core = core_fingerprint_one(s)
        if core:
            results[s] = core
    with open(OUT, 'w') as f:
        json.dump(results, f, ensure_ascii=False, indent=2)
    print(f"{len(results)} libs have at least one core-signature file")

if __name__ == '__main__':
    main()
