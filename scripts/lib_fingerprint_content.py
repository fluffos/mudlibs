"""Content-scoped fingerprint: only files under kungfu/ (skills/classes)
and d/ (rooms/zones/NPCs) -- the actual GAME a player experiences, as
opposed to master.c/securityd.c/etc engine plumbing that many unrelated
games happen to share via a common decades-old ancestor.

Two archives sharing an engine core (same master.c) can be completely
different games; two archives sharing most of their kungfu/ skills and
d/ zones are the same game, near enough, regardless of what the engine
wrapper looks like. This is the signal that actually answers "is this
archive worth processing separately, or is it a repack of one I already
have."

Usage: python3 scripts/lib_fingerprint_content.py
"""
import os, hashlib, json, time
from concurrent.futures import ProcessPoolExecutor

MUDLIB_ROOT = "/home/sunyc/src/mudlib"
LIBS_DIR = os.path.join(MUDLIB_ROOT, "libs")
OUT = os.path.join(os.path.dirname(__file__), 'lib_content_fingerprints.json')

CODE_EXTS = {'.lpc', '.c', '.h'}
CONTENT_DIRS = {'kungfu', 'd'}  # top-level dirs that hold actual game content

def fingerprint_one(slug):
    libdir = os.path.join(LIBS_DIR, slug)
    base = os.path.join(libdir, 'work')
    if not os.path.isdir(base):
        base = os.path.join(libdir, 'raw')
    if not os.path.isdir(base):
        return slug, None

    # find the content dirs regardless of nesting depth under base
    # (raw/ archives can have 1-2 extra wrapper levels before the real root)
    roots = []
    for dirpath, dirnames, filenames in os.walk(base):
        for d in list(dirnames):
            if d.lower() in CONTENT_DIRS:
                roots.append(os.path.join(dirpath, d))

    if not roots:
        return slug, None

    hashes = set()
    total_files = 0
    for root in roots:
        for dirpath, dirnames, filenames in os.walk(root):
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
                hashes.add(hashlib.md5(content).hexdigest())

    return slug, {
        'file_count': total_files,
        'hashes': list(hashes),
    }

def main():
    slugs = sorted(os.listdir(LIBS_DIR))
    slugs = [s for s in slugs if os.path.isdir(os.path.join(LIBS_DIR, s))]
    print(f"fingerprinting content dirs (kungfu/, d/) for {len(slugs)} libs...", flush=True)

    results = {}
    t0 = time.time()
    with ProcessPoolExecutor(max_workers=8) as ex:
        for i, (slug, fp) in enumerate(ex.map(fingerprint_one, slugs)):
            if fp is not None and fp['file_count'] > 0:
                results[slug] = fp
            if (i + 1) % 20 == 0:
                print(f"  {i+1}/{len(slugs)} done, elapsed {time.time()-t0:.0f}s", flush=True)

    with open(OUT, 'w') as f:
        json.dump(results, f)
    print(f"DONE in {time.time()-t0:.0f}s, {len(results)} libs have kungfu/d content", flush=True)

if __name__ == '__main__':
    main()
