#!/usr/bin/env python3
"""Decompile, recompile with the original driver, compare.

    python3 -m mudos_b.roundtrip <raw_root> <driver.json> [--list FILE | paths...] [--keep]
raw_root is the pristine lib dir holding config.cfg, driver and world/.
"""
import argparse, json, os, sys, time
from .loader import Mudlib
from .disasm import Efuns
from .decompile import decompile
from .oracle import Oracle, canon, compare


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('raw')
    ap.add_argument('driver')
    ap.add_argument('paths', nargs='*')
    ap.add_argument('--list')
    ap.add_argument('--simul', default='adm/single/simul_efun')
    ap.add_argument('--work', default='/tmp/wlo')
    ap.add_argument('--report', default='/tmp/roundtrip.tsv')
    ap.add_argument('--srcdir', help='also write decompiled sources here')
    a = ap.parse_args()
    paths = list(a.paths)
    if a.list:
        paths += [l.rstrip('\n') for l in open(a.list, encoding='latin-1') if l.strip()]
    paths = [p.lstrip('/') for p in paths]
    bdir = os.path.join(a.raw, 'world/binaries')
    mud = Mudlib(bdir)
    efuns = Efuns(json.load(open(a.driver)))
    simuls = mud.simul_names(a.simul)
    orc = Oracle(a.raw, a.work)
    orc.reset()
    status = {}
    t0 = time.time()
    for p in paths:
        prog = mud.get(p)
        if prog is None:
            status[p] = ('nobinary', '')
            continue
        try:
            src, errs = decompile(prog, mud, efuns, simuls)
        except Exception as e:
            status[p] = ('crash', repr(e))
            continue
        data = src.encode('latin-1')
        if a.srcdir:
            fn = os.path.join(a.srcdir, p + '.c')
            os.makedirs(os.path.dirname(fn), exist_ok=True)
            open(fn, 'wb').write(data)
        if errs:
            status[p] = ('decompile', '; '.join(errs))
        orc.install(p, data)
    print('decompiled %d in %.0fs' % (len(paths), time.time() - t0), file=sys.stderr)
    todo = [p for p in paths if p not in status]
    loaded, errors, crashed = orc.run(todo + [p for p, s in status.items() if s[0] == 'decompile'])
    newmud = Mudlib(os.path.join(orc.world, 'binaries'))
    for p in todo:
        if p in crashed:
            status[p] = ('crash-driver', crashed[p])
            continue
        if p in errors or not os.path.exists(orc.new_binary(p)):
            status[p] = ('compile', errors.get(p, 'no binary written'))
            continue
        try:
            d = compare(canon(mud.get(p), mud, efuns, simuls), canon(newmud.get(p), newmud, efuns, simuls))
        except Exception as e:
            status[p] = ('compare-crash', repr(e))
            continue
        status[p] = ('ok', '') if not d else ('differs', ' | '.join(d[:3]))
    from collections import Counter
    c = Counter(s for s, _ in status.values())
    with open(a.report, 'w', encoding='utf-8') as f:
        for p in paths:
            s, m = status.get(p, ('?', ''))
            f.write('%s\t%s\t%s\n' % (p, s, m.replace('\t', ' ').replace('\n', ' ')[:500]))
    print(dict(c), file=sys.stderr)


if __name__ == '__main__':
    main()
