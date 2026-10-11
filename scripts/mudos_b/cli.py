#!/usr/bin/env python3
"""Decompile .b files.

    python3 -m mudos_b.cli <binaries_dir> <driver.json> <simul_efun> <object path>...
    (paths like d/city/kedian; output to stdout, or --out DIR for <DIR>/<path>.c)
"""
import argparse, json, os, sys
from .loader import Mudlib
from .disasm import Efuns
from .decompile import decompile


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('bdir')
    ap.add_argument('driver')
    ap.add_argument('simul')
    ap.add_argument('paths', nargs='*')
    ap.add_argument('--out')
    ap.add_argument('--list')
    a = ap.parse_args()
    mud = Mudlib(a.bdir)
    efuns = Efuns(json.load(open(a.driver)))
    simuls = mud.simul_names(a.simul)
    paths = list(a.paths)
    if a.list:
        paths += [l.strip() for l in open(a.list) if l.strip()]
    nfail = 0
    for p in paths:
        prog = mud.get(p)
        if prog is None:
            print('MISSING', p, file=sys.stderr)
            continue
        try:
            src, errs = decompile(prog, mud, efuns, simuls)
        except Exception as e:
            print('CRASH', p, repr(e), file=sys.stderr)
            nfail += 1
            continue
        if errs:
            nfail += 1
            for e in errs:
                print('FAIL', p, e, file=sys.stderr)
        data = src.encode('latin-1')
        if a.out:
            fn = os.path.join(a.out, p.lstrip('/') + '.c')
            os.makedirs(os.path.dirname(fn), exist_ok=True)
            open(fn, 'wb').write(data)
        else:
            sys.stdout.buffer.write(data)
    print('%d/%d decompiled without errors' % (len(paths) - nfail, len(paths)), file=sys.stderr)


if __name__ == '__main__':
    main()
