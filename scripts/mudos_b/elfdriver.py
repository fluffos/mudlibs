#!/usr/bin/env python3
"""Pull the efun table out of an unstripped Linux i386 MudOS driver.

    elfdriver.py <driver> <out.json>

Reads `predefs` (keyword_t[]) and `efun_arg_types` from the symbol table.
keyword_t (v22, 32 bytes): word*, u16 token, s16 sem_value, next*,
s16 min_args, s16 max_args, s16 ret_type, u16 arg_type1..4, s16 arg_index,
s16 Default.
"""
import json, struct, sys


class Elf32:
    def __init__(self, path):
        self.d = d = open(path, 'rb').read()
        shoff, = struct.unpack_from('<I', d, 0x20)
        shentsize, shnum, shstrndx = struct.unpack_from('<HHH', d, 0x2e)
        self.secs = [struct.unpack_from('<IIIIIIIIII', d, shoff + i * shentsize) for i in range(shnum)]
        strsec = self.secs[shstrndx]
        self.byname = {self._str(s[0], strsec[4]): s for s in self.secs}
        symtab, strtab = self.byname['.symtab'], self.byname['.strtab']
        self.syms = {}
        for i in range(symtab[5] // 16):
            n, v, sz, info, oth, shn = struct.unpack_from('<IIIBBH', d, symtab[4] + i * 16)
            self.syms[self._str(n, strtab[4])] = (v, sz)

    def _str(self, o, base):
        e = self.d.index(b'\0', base + o)
        return self.d[base + o:e].decode('latin-1')

    def off(self, va):
        for s in self.secs:
            if s[1] != 8 and s[3] and s[3] <= va < s[3] + s[5]:   # skip NOBITS
                return va - s[3] + s[4]
        raise KeyError(hex(va))

    def cstr(self, va):
        o = self.off(va)
        return self.d[o:self.d.index(b'\0', o)].decode('latin-1')


def extract(path):
    e = Elf32(path)
    va, size = e.syms['predefs']
    o = e.off(va)
    efuns = []
    for k in range(size // 32):
        (w, tok, sem, nxt, mn, mx, rt, a1, a2, a3, a4, ai, df) = struct.unpack_from('<IHhIhhhHHHHhh', e.d, o + k * 32)
        efuns.append(dict(name=e.cstr(w), token=tok, min_args=mn, max_args=mx, ret_type=rt,
                          arg_types=[a1, a2, a3, a4], arg_index=ai, default=df & 0xff))
    va, size = e.syms['efun_arg_types']
    o = e.off(va)
    arg_types = list(struct.unpack_from('<%dh' % (size // 2), e.d, o))
    return dict(driver=path, efuns=efuns, efun_arg_types=arg_types)


if __name__ == '__main__':
    r = extract(sys.argv[1])
    json.dump(r, open(sys.argv[2], 'w'), indent=1)
    print(len(r['efuns']), 'efuns')
