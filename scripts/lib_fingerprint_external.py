"""Merge the 7 standalone fluffos-org mudlib repos (siblings of this repo,
checked out at ~/src/<name>, not under libs/) into the same fingerprint
files lib_fingerprint.py / lib_fingerprint_core.py / lib_fingerprint_content.py
already produced, under an `ext_`-prefixed slug. Run those three first,
then this, then lib_similarity_cluster.py picks up the merged data
automatically -- no separate cluster step needed.

Usage: python3 scripts/lib_fingerprint_external.py
"""
import os, hashlib, json

# The 7 standalone fluffos-org mudlib repos processed earlier this session,
# living outside ~/src/mudlib/libs/ entirely -- include them in the
# similarity index too, since they're part of the same restoration effort.
EXTERNAL_ROOTS = {
    'ext_nightmare3': '/home/sunyc/src/nightmare3/lib',
    'ext_xkx100': '/home/sunyc/src/xkx100',
    'ext_nt7': '/home/sunyc/src/nt7',
    'ext_sanguozhi': '/home/sunyc/src/sanguozhi',
    'ext_deadsouls': '/home/sunyc/src/dead-souls/lib',
    'ext_imud': '/home/sunyc/src/imud',
    'ext_lima': '/home/sunyc/src/lima/lib',
}

CODE_EXTS = {'.lpc', '.c', '.h'}
CORE_BASENAMES = {
    'master.c', 'master.lpc', 'chinese.c', 'chinese.lpc', 'chinesed.c', 'chinesed.lpc',
    'logind.c', 'logind.lpc', 'named.c', 'named.lpc', 'securityd.c', 'securityd.lpc',
    'security.c', 'security.lpc', 'dbase.c', 'dbase.lpc', 'wizard.c', 'wizard.lpc',
    'simul_efun.c', 'simul_efun.lpc',
}
CONTENT_DIRS = {'kungfu', 'd'}

SCRIPTS_DIR = os.path.dirname(__file__)

def full_fingerprint(root):
    hashes = set()
    total = 0
    for dirpath, dirnames, filenames in os.walk(root):
        parts = dirpath.split(os.sep)
        if any(p in ('log', 'save', 'data', 'binaries', '.git', 'build') for p in parts):
            continue
        for fn in filenames:
            if os.path.splitext(fn)[1].lower() not in CODE_EXTS:
                continue
            fpath = os.path.join(dirpath, fn)
            try:
                with open(fpath, 'rb') as f:
                    content = f.read()
            except Exception:
                continue
            total += 1
            hashes.add(hashlib.md5(content).hexdigest())
    return total, hashes

def core_fingerprint(root):
    core = {}
    for dirpath, dirnames, filenames in os.walk(root):
        parts = dirpath.split(os.sep)
        if any(p in ('log', 'save', 'data', 'binaries', '.git', 'build') for p in parts):
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
            key = fn.lower().rsplit('.', 1)[0]
            core.setdefault(key, h)
    return core

def content_fingerprint(root):
    roots = []
    for dirpath, dirnames, filenames in os.walk(root):
        for d in list(dirnames):
            if d.lower() in CONTENT_DIRS:
                roots.append(os.path.join(dirpath, d))
    hashes = set()
    total = 0
    for r in roots:
        for dirpath, dirnames, filenames in os.walk(r):
            parts = dirpath.split(os.sep)
            if any(p in ('log', 'save', 'data', 'binaries', '.git') for p in parts):
                continue
            for fn in filenames:
                if os.path.splitext(fn)[1].lower() not in CODE_EXTS:
                    continue
                fpath = os.path.join(dirpath, fn)
                try:
                    with open(fpath, 'rb') as f:
                        content = f.read()
                except Exception:
                    continue
                total += 1
                hashes.add(hashlib.md5(content).hexdigest())
    return total, hashes

def main():
    with open(os.path.join(SCRIPTS_DIR, 'lib_fingerprints.json')) as f:
        fp = json.load(f)
    with open(os.path.join(SCRIPTS_DIR, 'lib_core_fingerprints.json')) as f:
        core = json.load(f)
    with open(os.path.join(SCRIPTS_DIR, 'lib_content_fingerprints.json')) as f:
        content = json.load(f)

    for slug, root in EXTERNAL_ROOTS.items():
        if not os.path.isdir(root):
            print(f"SKIP {slug}: {root} not found")
            continue
        total, hashes = full_fingerprint(root)
        fp[slug] = {'file_count': total, 'total_bytes': 0, 'unique_hash_count': len(hashes), 'hashes': list(hashes)}

        c = core_fingerprint(root)
        if c:
            core[slug] = c

        ctotal, chashes = content_fingerprint(root)
        if ctotal:
            content[slug] = {'file_count': ctotal, 'hashes': list(chashes)}

        print(f"{slug}: {total} files, {len(c)} core files, {ctotal} kungfu/d files")

    with open(os.path.join(SCRIPTS_DIR, 'lib_fingerprints.json'), 'w') as f:
        json.dump(fp, f)
    with open(os.path.join(SCRIPTS_DIR, 'lib_core_fingerprints.json'), 'w') as f:
        json.dump(core, f, ensure_ascii=False, indent=2)
    with open(os.path.join(SCRIPTS_DIR, 'lib_content_fingerprints.json'), 'w') as f:
        json.dump(content, f)

if __name__ == '__main__':
    main()
