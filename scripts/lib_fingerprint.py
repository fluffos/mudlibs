import os, hashlib, json, sys
from concurrent.futures import ProcessPoolExecutor
import time

MUDLIB_ROOT = "/home/sunyc/src/mudlib"
LIBS_DIR = os.path.join(MUDLIB_ROOT, "libs")
OUT = os.path.join(os.path.dirname(__file__), 'lib_fingerprints.json')

CODE_EXTS = {'.lpc', '.c', '.h'}

def fingerprint_one(slug):
    libdir = os.path.join(LIBS_DIR, slug)
    base = os.path.join(libdir, 'work')
    if not os.path.isdir(base):
        base = os.path.join(libdir, 'raw')
    if not os.path.isdir(base):
        return slug, None

    hashes = set()
    total_files = 0
    total_bytes = 0
    for dirpath, dirnames, filenames in os.walk(base):
        # skip obviously irrelevant heavy dirs
        parts = dirpath.split(os.sep)
        if any(p in ('log', 'save', 'data', 'binaries', '.git') for p in parts):
            continue
        for fn in filenames:
            ext = os.path.splitext(fn)[1].lower()
            if ext not in CODE_EXTS:
                continue
            fpath = os.path.join(dirpath, fn)
            try:
                with open(fpath, 'rb') as f:
                    content = f.read()
            except Exception:
                continue
            total_files += 1
            total_bytes += len(content)
            h = hashlib.md5(content).hexdigest()
            hashes.add(h)

    return slug, {
        'file_count': total_files,
        'total_bytes': total_bytes,
        'unique_hash_count': len(hashes),
        'hashes': list(hashes),
    }

def main():
    slugs = sorted(os.listdir(LIBS_DIR))
    slugs = [s for s in slugs if os.path.isdir(os.path.join(LIBS_DIR, s))]
    print(f"fingerprinting {len(slugs)} libs...", flush=True)

    results = {}
    t0 = time.time()
    with ProcessPoolExecutor(max_workers=8) as ex:
        for i, (slug, fp) in enumerate(ex.map(fingerprint_one, slugs)):
            if fp is not None:
                results[slug] = fp
            if (i+1) % 10 == 0:
                print(f"  {i+1}/{len(slugs)} done, elapsed {time.time()-t0:.0f}s", flush=True)
                with open(OUT, 'w') as f:
                    json.dump(results, f)

    with open(OUT, 'w') as f:
        json.dump(results, f)
    print(f"DONE in {time.time()-t0:.0f}s, {len(results)} libs fingerprinted", flush=True)

if __name__ == '__main__':
    main()
