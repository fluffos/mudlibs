#!/usr/bin/env python3
"""Decompile, recompile with a v22 driver, compare.

    python3 -m mudos_b.roundtrip <raw_root> <driver.json> [--list FILE | paths...]
raw_root is the lib dir holding config.cfg, driver and world/. By default the
shipped binaries are raw_root/world/binaries and the driver is the game's own.

A different build of the same MudOS version can stand in for a driver that
does not run on the host (033-3: a Win32 mudos.exe): give the shipped
binaries with --bdir and the stand-in driver's own table with --oracle-table.
Programs are compared by name (efuns, simul_efuns, functions, variables), so
the two builds may number their efuns differently.
"""
import argparse, json, os, sys, time
from .loader import Mudlib
from .disasm import Efuns
from .decompile import decompile
from .oracle import Oracle, SCRATCH, canon, compare


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('raw')
    ap.add_argument('driver')
    ap.add_argument('paths', nargs='*')
    ap.add_argument('--list')
    ap.add_argument('--simul', default='adm/single/simul_efun')
    ap.add_argument('--work', default=os.path.join(SCRATCH, 'mudos-oracle'))
    ap.add_argument('--report', default=os.path.join(SCRATCH, 'roundtrip.tsv'))
    ap.add_argument('--srcdir', help='also write decompiled sources here')
    ap.add_argument('--originals', help='file listing paths whose original .c is installed instead')
    ap.add_argument('--originals-root', help='where those originals live (default: raw/world)')
    ap.add_argument('--bdir', help='the shipped binaries (default: raw/world/binaries)')
    ap.add_argument('--oracle-table', help="efun table of the driver in raw (default: driver.json)")
    ap.add_argument('--preload', default='data/config/preload', help="the master's preload list, in world/")
    ap.add_argument('--port', type=int, default=47186)
    ap.add_argument('--fold', action='append', default=[],
                    help="build difference canon() ignores (transfer_local)")
    ap.add_argument('--pragma', action='append', default=[],
                    help='#pragma line put in front of every installed source (no_optimize, ...)')
    a = ap.parse_args()
    paths = list(a.paths)
    if a.list:
        paths += [l.rstrip('\n') for l in open(a.list, encoding='utf-8', errors='surrogateescape') if l.strip()]
    paths = [p.lstrip('/') for p in paths]
    bdir = a.bdir or os.path.join(a.raw, 'world/binaries')
    efuns = Efuns(json.load(open(a.driver)))
    oefuns = Efuns(json.load(open(a.oracle_table))) if a.oracle_table else efuns
    mud = Mudlib(bdir, efuns.entry_size)
    simuls = mud.simul_names(a.simul)
    orc = Oracle(a.raw, a.work, port=a.port, preload=a.preload,
                 prepend=''.join('#pragma %s\n' % p for p in a.pragma).encode())
    orc.reset()
    status = {}
    originals = set()
    if a.originals:
        originals = {l.strip().lstrip('/') for l in open(a.originals, encoding='utf-8', errors='surrogateescape')
                     if l.strip()}
    oroot = a.originals_root or os.path.join(a.raw, 'world')
    t0 = time.time()
    for p in paths:
        if p in originals:
            orc.install(p, open(os.path.join(oroot, p + '.c'), 'rb').read())
            continue
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
    newmud = Mudlib(os.path.join(orc.world, 'binaries'), oefuns.entry_size)
    try:
        newsimuls = newmud.simul_names(a.simul)
    except Exception:
        newsimuls = simuls
    for p in todo:
        if p in crashed:
            status[p] = ('crash-driver', crashed[p])
            continue
        if not os.path.exists(orc.new_binary(p)):
            status[p] = ('compile', errors.get(p, 'no binary written'))
            continue
        # a runtime error in create() still leaves a compiled binary to compare
        try:
            d = compare(canon(mud.get(p), mud, efuns, simuls, a.fold),
                        canon(newmud.get(p), newmud, oefuns, newsimuls, a.fold))
        except Exception as e:
            status[p] = ('compare-crash', repr(e))
            continue
        status[p] = ('ok', '') if not d else ('differs', ' | '.join(d[:3]))
    from collections import Counter
    c = Counter(s for s, _ in status.values())
    with open(a.report, 'w', encoding='utf-8', errors='surrogateescape') as f:
        for p in paths:
            s, m = status.get(p, ('?', ''))
            f.write('%s\t%s\t%s\n' % (p, s, m.replace('\t', ' ').replace('\n', ' ')[:500]))
    print(dict(c), file=sys.stderr)


if __name__ == '__main__':
    main()
