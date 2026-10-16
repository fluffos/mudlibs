#!/usr/bin/env python3
"""Compare our disassembly with the driver's dump_prog output.

    dumpcheck.py <binaries_dir> <driver.json> <simul_efun path> <dump.dis>...
"""
import json, os, re, sys
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
from mudos_b.loader import Mudlib
from mudos_b.disasm import Efuns, render_dump


def driver_section(path):
    d = open(path, 'rb').read()
    a = d.index(b';;;  *** Disassembly ***\n') + len(b';;;  *** Disassembly ***\n')
    b = d.find(b'\n;;;  *** Line Number Info ***')
    return d[a:b if b >= 0 else len(d)]


def norm_tables(text):
    """String switch tables are re-sorted by pointer on load; compare as sets."""
    lines = text.split(b'\n')
    out, buf = [], []
    for ln in lines:
        if ln.startswith(b'\t"') or (buf and ln.startswith(b'\t')):
            buf.append(ln)
            continue
        if buf:
            out += sorted(buf)
            buf = []
        out.append(ln)
    out += sorted(buf)
    return b'\n'.join(out)


def main():
    bdir, drv, simul = sys.argv[1:4]
    efuns = Efuns(json.load(open(drv)))
    mud = Mudlib(bdir, efuns.entry_size)
    simuls = mud.simul_names(simul)
    bad = 0
    for dis in sys.argv[4:]:
        name = os.path.basename(dis)[:-4].replace('%', '/')
        prog = mud.get(name)
        try:
            ours = norm_tables(render_dump(prog, mud, efuns, simuls))
        except Exception as e:
            bad += 1
            print('ERROR', name, repr(e))
            continue
        theirs = norm_tables(driver_section(dis))
        if ours.rstrip(b'\n') != theirs.rstrip(b'\n'):
            bad += 1
            print('DIFF', name)
            if len(sys.argv) == 5:
                import difflib
                for l in difflib.unified_diff(theirs.decode('latin-1').split('\n'), ours.decode('latin-1').split('\n'), 'driver', 'ours', lineterm='', n=2):
                    print(l)
    print('%d/%d identical' % (len(sys.argv) - 4 - bad, len(sys.argv) - 4))


if __name__ == '__main__':
    main()
