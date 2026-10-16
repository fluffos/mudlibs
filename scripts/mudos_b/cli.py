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
    ap.add_argument('--fluffos', action='store_true', help='FluffOS flavour (protected, no unused locals)')
    ap.add_argument('--gbk', action='store_true',
                    help='keep GBK characters whole in strings (a 0x5c second byte is not escaped): '
                         'for a tree that is converted to UTF-8 afterwards')
    a = ap.parse_args()
    from . import decompile as _d
    _d.TARGET['fluffos'] = a.fluffos
    _d.TARGET['gbk'] = a.gbk
    efuns = Efuns(json.load(open(a.driver)))
    mud = Mudlib(a.bdir, efuns.entry_size)
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
