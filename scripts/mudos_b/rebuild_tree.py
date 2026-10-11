#!/usr/bin/env python3
"""Assemble a recovered source tree for a lib shipped as compiled binaries.

    python3 -m mudos_b.rebuild_tree <world> <decompiled_dir> <out_dir>
        [--keep-original LIST] [--exclude DIR ...]

<world> is the extracted mudlib root (with binaries/), <decompiled_dir> holds
<path>.c files written by `mudos_b.cli --out`. Every program that has a .b
gets its decompiled source, except paths in --keep-original (original
source that recompiles to the same program, so it is kept with its
comments). Everything else is copied as-is. The binaries/ cache is dropped.
"""
import argparse
import os
import shutil

HEADER = (b'// \xb1\xbe\xce\xc4\xbc\xfe\xd3\xc9\xb1\xe0\xd2\xeb\xba\xf3\xb5\xc4 .b '
          b'\xb6\xfe\xbd\xf8\xd6\xc6\xb3\xcc\xd0\xf2\xb7\xb4\xb1\xe0\xd2\xeb\xbb\xb9\xd4\xad\xa3\xac'
          b'\xd4\xad\xca\xbc\xd4\xb4\xc2\xeb\xce\xb4\xcb\xe6\xb5\xb5\xb0\xb8\xb7\xa2\xb2\xbc\xa1\xa3\n'
          b'// Decompiled from the compiled .b binary; the original source was not distributed.\n')


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('world')
    ap.add_argument('decompiled')
    ap.add_argument('out')
    ap.add_argument('--keep-original')
    ap.add_argument('--exclude', action='append', default=['binaries'])
    a = ap.parse_args()
    keep = set()
    if a.keep_original:
        keep = {l.strip().lstrip('/') for l in open(a.keep_original, encoding='latin-1') if l.strip()}
    if os.path.exists(a.out):
        shutil.rmtree(a.out)
    excl = {e.strip('/') for e in a.exclude}
    copied = 0
    for dp, dn, fn in os.walk(a.world):
        rel = os.path.relpath(dp, a.world)
        top = rel.split(os.sep)[0]
        if top in excl:
            dn[:] = []
            continue
        os.makedirs(os.path.join(a.out, rel), exist_ok=True)
        for f in fn:
            src = os.path.join(dp, f)
            if os.path.islink(src):
                continue
            shutil.copy2(src, os.path.join(a.out, rel, f))
            copied += 1
    replaced = kept = 0
    for dp, dn, fn in os.walk(a.decompiled):
        for f in fn:
            if not f.endswith('.c'):
                continue
            path = os.path.relpath(os.path.join(dp, f), a.decompiled)[:-2]
            if path in keep:
                kept += 1
                continue
            dst = os.path.join(a.out, path + '.c')
            os.makedirs(os.path.dirname(dst), exist_ok=True)
            open(dst, 'wb').write(HEADER + open(os.path.join(dp, f), 'rb').read())
            replaced += 1
    print('copied %d files, %d decompiled sources in place, %d originals kept' % (copied, replaced, kept))


if __name__ == '__main__':
    main()
