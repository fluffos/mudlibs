#!/usr/bin/env python3
"""Pull the efun table out of a Win32 (PE) MudOS driver.

    python3 -m mudos_b.pedriver <mudos.exe> <out.json>

A PE driver built with MSVC has no symbol table, so `predefs` (keyword_t[],
the same 32-byte record elfdriver.py reads) is found by its shape: the
longest run of records in the data sections whose `word` points at an
identifier string, whose `next` and `sem_value` are 0 (they are only filled
in at run time) and whose argument counts are small. The run has to hold
`call_other` and `this_object` and be sorted by name, as edit_source writes
it; anything else is refused rather than guessed.

`efun_arg_types` follows `predefs` in the same translation unit (it does in
the unstripped ELF build too). Without a symbol its end is unknown, so only
the part the `arg_index` fields reach is written; the decompiler does not
use it.
"""
import json
import re
import struct
import sys

from .elfdriver import RECORD, record_dict

IDENT = re.compile(rb'[A-Za-z_][A-Za-z0-9_]*\Z')
# compiler_function_t in the MSVC build (name, type, runtime_index, address,
# then 6 bytes) -- 12 in the i386 Linux one; bfile.parse needs it
ENTRY_SIZE_WIN32 = 16


class PE32:
    def __init__(self, path):
        self.d = d = open(path, 'rb').read()
        if d[:2] != b'MZ':
            raise ValueError('not a PE file: %s' % path)
        pe, = struct.unpack_from('<I', d, 0x3c)
        if d[pe:pe + 4] != b'PE\0\0':
            raise ValueError('not a PE file: %s' % path)
        machine, nsec = struct.unpack_from('<HH', d, pe + 4)
        if machine != 0x14c:
            raise ValueError('not an i386 PE: machine %#x' % machine)
        optsz, = struct.unpack_from('<H', d, pe + 20)
        self.imagebase, = struct.unpack_from('<I', d, pe + 24 + 28)
        self.secs = []
        o = pe + 24 + optsz
        for _ in range(nsec):
            name = d[o:o + 8].rstrip(b'\0').decode('latin-1')
            vsize, rva, rsize, roff = struct.unpack_from('<IIII', d, o + 8)
            flags, = struct.unpack_from('<I', d, o + 36)
            self.secs.append(dict(name=name, va=self.imagebase + rva, vsize=vsize, off=roff,
                                  size=rsize, flags=flags))
            o += 40

    def off(self, va):
        for s in self.secs:
            if s['va'] <= va < s['va'] + min(s['vsize'], s['size']):
                return va - s['va'] + s['off']
        return None

    def cstr(self, va, limit=64):
        o = self.off(va)
        if o is None:
            return None
        e = self.d.find(b'\0', o, o + limit)
        return self.d[o:e] if e >= 0 else None

    def data_sections(self):
        # initialized, readable, not executable
        return [s for s in self.secs if s['flags'] & 0x40 and not s['flags'] & 0x20000000]


def plausible(pe, o):
    w, tok, sem, nxt, mn, mx, rt, a1, a2, a3, a4, ai, df = struct.unpack_from(RECORD, pe.d, o)
    if nxt or sem or not 0 < tok < 2048 or not -1 <= mn <= 32 or not -1 <= mx <= 32 or ai < 0:
        return None
    name = pe.cstr(w)
    if not name or not IDENT.match(name):
        return None
    return name


def find_predefs(pe):
    best = None
    for s in pe.data_sections():
        lo, hi = s['off'], s['off'] + s['size']
        for phase in range(0, 32, 4):
            o = lo + phase
            run = None
            while o + 32 <= hi:
                name = plausible(pe, o)
                if name is not None:
                    if run is None:
                        run = [o, []]
                    run[1].append(name)
                elif run is not None:
                    if best is None or len(run[1]) > len(best[1]):
                        best = run
                    run = None
                o += 32
            if run is not None and (best is None or len(run[1]) > len(best[1])):
                best = run
    if best is None:
        raise ValueError('no keyword_t run found')
    start, names = best
    for need in (b'call_other', b'this_object'):
        if need not in names:
            raise ValueError('longest keyword_t run lacks %s' % need.decode())
    if names != sorted(names):
        raise ValueError('keyword_t run is not sorted by name')
    return start, len(names)


def find_operators(pe):
    """Opcode -> display name, from the add_instr_name(name, opco, n, type)
    calls in init_instrs(): push type; push n; push opco; push name; call."""
    d = pe.d
    text = next(s for s in pe.secs if s['flags'] & 0x20000000)

    def va_of(off):
        return text['va'] + off - text['off']

    def str_va(word):
        for s in pe.data_sections():
            k = d.find(b'\0' + word + b'\0', s['off'], s['off'] + s['size'])
            if k >= 0:
                return s['va'] + k + 1 - s['off']
        raise ValueError('no string %r' % word)

    # the call right after `push offset "branch_when_zero"` is add_instr_name
    anchor = b'\x68' + struct.pack('<I', str_va(b'branch_when_zero'))
    k = d.find(anchor, text['off'], text['off'] + text['size'])
    if k < 0 or d[k + 5] != 0xe8:
        raise ValueError('add_instr_name call not found')
    target = va_of(k + 5) + 5 + struct.unpack_from('<i', d, k + 6)[0]

    def push_before(o):
        if d[o - 2] == 0x6a:
            return struct.unpack_from('<b', d, o - 1)[0], o - 2
        if d[o - 5] == 0x68:
            return struct.unpack_from('<i', d, o - 4)[0], o - 5
        raise ValueError('add_instr_name call at %#x: unexpected argument code' % va_of(o))

    ops = {}
    for o in range(text['off'], text['off'] + text['size'] - 5):
        if d[o] != 0xe8 or va_of(o) + 5 + struct.unpack_from('<i', d, o + 1)[0] != target:
            continue
        name_va, p = push_before(o)
        _opco, p = push_before(p)
        n, p = push_before(p)
        name = pe.cstr(name_va & 0xffffffff)
        if not name or n in ops:
            raise ValueError('add_instr_name call at %#x: bad name or duplicate opcode %d' % (va_of(o), n))
        ops[n] = name.decode('latin-1')
    return ops


def operator_list(registered, base):
    """Operator names in our ops.OPERATORS spelling, opcode = index + 1.
    The standard v22 operators must sit at their usual opcodes (push and
    efun0..efunv are never registered by name); extra ones are appended
    under the name the driver registers for them."""
    from .ops import OPERATORS, DISPLAY
    names = []
    for op in range(1, base):
        shown = registered.get(op)
        if op <= len(OPERATORS):
            std = OPERATORS[op - 1]
            if shown is not None and shown != DISPLAY.get(op, std):
                raise ValueError('opcode %d is %r here, %r in v22pre11' % (op, shown, DISPLAY.get(op, std)))
            names.append(std)
        elif shown is None:
            raise ValueError('opcode %d below the first efun is not registered' % op)
        else:
            names.append(shown)
    return names


def extract(path):
    pe = PE32(path)
    start, n = find_predefs(pe)
    efuns = [record_dict(pe.d, start + k * 32, lambda va: pe.cstr(va).decode('latin-1'))
             for k in range(n)]
    # efun_arg_types: zero-terminated groups right after predefs
    o = start + n * 32
    reach = 0
    for e in efuns:
        k = e['arg_index']
        while struct.unpack_from('<h', pe.d, o + 2 * k)[0] != 0:
            k += 1
        reach = max(reach, k + 1)
    arg_types = list(struct.unpack_from('<%dh' % reach, pe.d, o))
    va = next(s['va'] + start - s['off'] for s in pe.secs if s['off'] <= start < s['off'] + s['size'])
    base = min(e['token'] for e in efuns if not e['token'] & 1024)
    registered = find_operators(pe)
    if max(registered) != base - 1:
        raise ValueError('last registered operator %d, first efun %d' % (max(registered), base))
    return dict(driver=path, format='pe32', predefs_va='%#x' % va, entry_size=ENTRY_SIZE_WIN32,
                operators=operator_list(registered, base), efuns=efuns, efun_arg_types=arg_types,
                efun_arg_types_note='prefix reached by arg_index; the PE has no symbol for its end')


if __name__ == '__main__':
    r = extract(sys.argv[1])
    json.dump(r, open(sys.argv[2], 'w'), indent=1)
    print(len(r['efuns']), 'efuns at', r['predefs_va'])
