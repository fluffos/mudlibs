"""Decode MudOS v22 bytecode and render it the way the driver's dump_prog does.

decode(prog) walks the whole program linearly. Switch tables are data, not
code: they sit between the end of the switch body and the code that follows,
so they are skipped and attached to the switch instruction.
"""
import struct
from dataclasses import dataclass, field

from . import bfile
from .ops import OP, DISPLAY, BASE

PUSH_KINDS = ('string', 'number', 'global', 'local')

FP_LOCAL, FP_EFUN, FP_SIMUL, FP_FUNCTIONAL = 2, 3, 4, 5
FP_G_VAR, FP_L_VAR, FP_ANONYMOUS = 6, 7, 8
FP_MASK, FP_NOT_BINDABLE = 0x0f, 0x40


class Efuns:
    """Efun table from drivers/<name>.json (see elfdriver.py)."""

    def __init__(self, table):
        self.by_token = {}
        self.aliases = {}
        for e in table['efuns']:
            if e['token'] & 1024:
                self.aliases.setdefault(e['token'] & 1023, []).append(e)
            else:
                self.by_token[e['token']] = e
        ones = [t for t, e in self.by_token.items() if e['min_args'] == 1 and e['max_args'] == 1]
        self.onearg_max = BASE + len(ones)
        self.arg_types = table.get('efun_arg_types', [])

    def name(self, token):
        e = self.by_token.get(token)
        return e['name'] if e else '<OTHER %d>' % token


@dataclass
class Instr:
    off: int
    op: int                    # operator opcode or efun token
    size: int
    args: tuple = ()
    target: int = None         # absolute branch target
    efun: bool = False
    nargs: int = None          # for efun/simul/call
    extra: dict = field(default_factory=dict)


def _s16(code, o):
    return struct.unpack_from('<H', code, o)[0]


def _i32(code, o):
    return struct.unpack_from('<i', code, o)[0]


def decode_one(code, pc, efuns):
    """Decode one instruction at pc. Returns Instr (size covers operands only,
    switch tables are reported in extra['table'])."""
    start = pc
    op = code[pc]
    pc += 1
    I = lambda **kw: Instr(off=start, op=op, size=0, **kw)
    if op >= BASE:
        ins = I(efun=True, nargs=1)
    elif op == OP['push']:
        n = code[pc]
        pc += 1
        items = []
        for _ in range(n):
            j = code[pc]
            pc += 1
            items.append((PUSH_KINDS[(j & 0xc0) >> 6], j & 0x3f))
        ins = I(args=tuple(items))
    elif op in (OP['branch_ne'], OP['branch_ge'], OP['branch_le'], OP['branch_eq'], OP['branch'],
                OP['branch_when_zero'], OP['branch_when_non_zero'], OP['lor'], OP['land']):
        s = _s16(code, pc)
        ins = I(args=(s,), target=pc + s)
        pc += 2
    elif op in (OP['next_foreach'], OP['bbranch_lt'], OP['bbranch_when_zero'],
                OP['bbranch_when_non_zero'], OP['bbranch']):
        s = _s16(code, pc)
        ins = I(args=(s,), target=pc - s)
        pc += 2
    elif op == OP['foreach']:
        flags = code[pc]
        a = code[pc + 1]
        pc += 2
        b = None
        if flags & 4:
            b = code[pc]
            pc += 1
        ins = I(args=(flags, a, b))
    elif op == OP['catch']:
        s = _s16(code, pc)
        ins = I(args=(s,), target=pc + s)
        pc += 2
    elif op in (OP['aggregate'], OP['aggregate_assoc']):
        ins = I(args=(_s16(code, pc),))
        pc += 2
    elif op in (OP['member'], OP['member_lvalue'], OP['expand_varargs'], OP['new_class'],
                OP['new_empty_class'], OP['loop_incr'], OP['transfer_local'], OP['local'],
                OP['local_lvalue'], OP['void_assign_local'], OP['global'], OP['global_lvalue'],
                OP['sscanf'], OP['parse_command'], OP['byte'], OP['nbyte'], OP['short_string']):
        ins = I(args=(code[pc],))
        pc += 1
    elif op == OP['call_function_by_address']:
        ins = I(args=(_s16(code, pc),), nargs=code[pc + 2])
        pc += 3
    elif op == OP['call_inherited']:
        ins = I(args=(code[pc], _s16(code, pc + 1)), nargs=code[pc + 3])
        pc += 4
    elif op == OP['while_dec']:
        lv = code[pc]
        s = _s16(code, pc + 1)
        ins = I(args=(lv, s), target=pc - s)
        pc += 3
    elif op == OP['loop_cond_number']:
        lv = code[pc]
        n = _i32(code, pc + 1)
        s = _s16(code, pc + 5)
        ins = I(args=(lv, n, s), target=pc + 5 - s)
        pc += 7
    elif op == OP['loop_cond_local']:
        lv = code[pc]
        lv2 = struct.unpack_from('<b', code, pc + 1)[0]
        s = _s16(code, pc + 2)
        ins = I(args=(lv, lv2, s), target=pc + 2 - s)
        pc += 4
    elif op == OP['string']:
        ins = I(args=(_s16(code, pc),))
        pc += 2
    elif op == OP['simul_efun']:
        ins = I(args=(_s16(code, pc),), nargs=code[pc + 2])
        pc += 3
    elif op == OP['function_constructor']:
        kind = code[pc]
        pc += 1
        k = kind & FP_MASK
        if k in (FP_SIMUL, FP_EFUN, FP_LOCAL):
            ins = I(args=(kind, _s16(code, pc)))
            pc += 2
        elif k == FP_FUNCTIONAL:
            nargs = struct.unpack_from('<b', code, pc)[0]
            ln = _s16(code, pc + 1)
            ins = I(args=(kind, nargs, ln), target=pc + 3 + ln)
            pc += 3
        elif k == FP_ANONYMOUS:
            nargs = struct.unpack_from('<b', code, pc)[0]
            nlocals = struct.unpack_from('<b', code, pc + 1)[0]
            ln = _s16(code, pc + 2)
            ins = I(args=(kind, nargs, nlocals, ln), target=pc + 3 + ln)
            pc += 4
        elif k in (FP_G_VAR, FP_L_VAR):
            ins = I(args=(kind, code[pc]))
            pc += 1
        else:
            raise ValueError('function_constructor kind %d at %04x' % (kind, start))
    elif op == OP['number']:
        ins = I(args=(_i32(code, pc),))
        pc += 4
    elif op == OP['real']:
        ins = I(args=(struct.unpack_from('<f', code, pc)[0],))
        pc += 4
    elif op == OP['switch']:
        ttype = code[pc]
        stable, etable, deflt = struct.unpack_from('<HHH', code, pc + 1)
        pc += 7
        ins = I(args=(ttype, stable, etable, deflt))
        ins.extra['table'] = _switch_table(code, ttype, stable, etable)
    elif op == OP['efunv']:
        n = code[pc]
        tok = code[pc + 1] + efuns.onearg_max
        pc += 2
        ins = Instr(off=start, op=tok, size=0, efun=True, nargs=n, extra={'via': 'efunv'})
    elif op in (OP['efun0'], OP['efun1'], OP['efun2'], OP['efun3']):
        tok = code[pc] + efuns.onearg_max
        pc += 1
        ins = Instr(off=start, op=tok, size=0, efun=True, nargs=op - OP['efun0'],
                    extra={'via': 'efun%d' % (op - OP['efun0'])})
    else:
        ins = I()
    ins.size = pc - start
    return ins


def _switch_table(code, ttype, stable, etable):
    """Entries as (key, address). Direct tables: key = minval + i.
    String tables hold string-table indices (patch_out), 0xffffffff = 0 label."""
    out = []
    if ttype == 0xfe:
        pc = stable
        addrs = []
        while pc < etable - 4:
            addrs.append(_s16(code, pc))
            pc += 2
        minval = _i32(code, etable - 4)
        return {'kind': 'direct', 'minval': minval, 'addrs': addrs}
    kind = 'int' if ttype >> 4 == 0xf else 'string'
    pc = stable
    while pc < etable:
        key = struct.unpack_from('<I', code, pc)[0]
        addr = _s16(code, pc + 4)
        out.append((key, addr))
        pc += 6
    return {'kind': kind, 'entries': out}


def decode(prog, efuns, start=0, end=None):
    """Linear decode of [start, end), skipping switch tables."""
    code = prog.code
    end = len(code) if end is None else end
    out = []
    skip = {}
    pc = start
    while pc < end:
        if pc in skip:
            pc = skip.pop(pc)
            continue
        ins = decode_one(code, pc, efuns)
        if ins.op == OP['switch'] and not ins.efun:
            _, stable, etable, _ = ins.args
            skip[stable] = etable
        out.append(ins)
        pc += ins.size
    return out


# ---------------------------------------------------------------- dump format

def _dstr(b):
    """disassem_string: first 29 bytes, \\n escaped."""
    s = b.split(b'\0')[0][:29]
    return s.replace(b'\n', b'\\n')


def render_dump(prog, mud, efuns, simuls):
    """Reproduce the ';;;  *** Disassembly ***' section of dump_prog (bytes)."""
    code = prog.code
    out = []
    w = out.append
    nfd = len(prog.functions)
    end = len(code)
    offsets = []
    for i, f in enumerate(prog.functions):
        if prog.function_flags[f.runtime_index] & (bfile.NAME_INHERITED | bfile.NAME_NO_CODE):
            offsets.append((end + 1, i))
        else:
            offsets.append((f.address, i))
    offsets.sort(key=lambda x: x[0])
    nxt = 0

    def fname(idx):
        return mud.function_name(prog, idx).encode('latin-1')

    def vname(p, idx):
        if not p.inherits:
            return p.variables[idx]
        last = p.inherits[-1]
        lp = mud.get(last.name)
        first = last.variable_index_offset + lp.num_variables_total
        if idx >= first:
            return p.variables[idx - first]
        i = len(p.inherits) - 1
        while idx < p.inherits[i].variable_index_offset:
            i -= 1
        return vname(mud.get(p.inherits[i].name), idx - p.inherits[i].variable_index_offset)

    _pending = []
    for ins in decode(prog, efuns):
        while nxt is not None and nxt < nfd and ins.off >= offsets[nxt][0]:
            w(b'\n;; Function %s\n' % prog.functions[offsets[nxt][1]].name.encode('latin-1'))
            nxt += 1
        w(b'%04x: ' % ins.off)
        op = ins.op
        if ins.efun:
            buff = b''
            via = ins.extra.get('via', '')
            if via == 'efunv':
                buff = b'%d' % ins.nargs
            w(b'%s %s\n' % (efuns.name(op).encode('latin-1'), buff))
            continue
        name = DISPLAY.get(op, '<OTHER %d>' % op).encode('latin-1')
        a = ins.args
        if op == OP['push']:
            w(b'push ' + b', '.join(b'%s %d' % (k.encode(), n) for k, n in a) + b'\n')
            continue
        if op in (OP['branch_ne'], OP['branch_ge'], OP['branch_le'], OP['branch_eq'], OP['branch'],
                  OP['branch_when_zero'], OP['branch_when_non_zero'], OP['lor'], OP['land'],
                  OP['next_foreach'], OP['bbranch_lt'], OP['bbranch_when_zero'],
                  OP['bbranch_when_non_zero'], OP['bbranch']):
            buff = b'%04x (%04x)' % (a[0], ins.target & 0xffff)
        elif op == OP['foreach']:
            flags, x, y = a
            buff = b'(%s) %s %d' % (b'mapping' if flags & 4 else b'array', b'global' if flags & 1 else b'local', x)
            if flags & 4:
                buff += b', %s %d' % (b'global' if flags & 2 else b'local', y)
        elif op == OP['catch']:
            buff = b'%04x' % a[0]
        elif op in (OP['aggregate'], OP['aggregate_assoc'], OP['member'], OP['member_lvalue'],
                    OP['sscanf'], OP['parse_command'], OP['byte']):
            buff = b'%d' % a[0]
        elif op == OP['nbyte']:
            buff = b'-%d' % a[0]
        elif op == OP['expand_varargs']:
            buff = b'%d from top of stack' % a[0] if a[0] else b'top of stack'
        elif op in (OP['new_class'], OP['new_empty_class']):
            buff = _raw(prog.strings[prog.classes[a[0]].name])
        elif op == OP['call_function_by_address']:
            if a[0] < prog.num_functions_total:
                buff = b'%-12s %5d' % (fname(a[0]), a[0])
            else:
                buff = b'<out of range %d>' % a[0]
        elif op == OP['call_inherited']:
            inh = prog.inherits[a[0]]
            np = mud.get(inh.name)
            if a[1] < np.num_functions_total:
                buff = b'%30s::%-12s %5d' % (np.name.encode('latin-1'),
                                             mud.function_name(np, a[1]).encode('latin-1'), a[1])
            else:
                buff = b'<out of range in %30s - %d>' % (np.name.encode('latin-1'), a[1])
        elif op in (OP['global'], OP['global_lvalue']):
            if a[0] < prog.num_variables_total:
                buff = vname(prog, a[0]).encode('latin-1')
            else:
                buff = b'<out of range %d>' % a[0]
        elif op in (OP['loop_incr'], OP['transfer_local'], OP['local'], OP['local_lvalue'],
                    OP['void_assign_local']):
            buff = b'LV%d' % a[0]
        elif op == OP['while_dec']:
            buff = b'LV%d--, branch %04x (%04x)' % (a[0], a[1], ins.target & 0xffff)
        elif op == OP['loop_cond_number']:
            buff = b'LV%d < %d bbranch_when_non_zero %04x (%04x)' % (a[0], a[1], a[2], ins.target & 0xffff)
        elif op == OP['loop_cond_local']:
            buff = b'LV%d < LV%d bbranch_when_non_zero %04x (%04x)' % (a[0], a[1], a[2], ins.target & 0xffff)
        elif op in (OP['string'], OP['short_string']):
            if a[0] < len(prog.strings):
                buff = b'"' + _dstr(prog.strings[a[0]]) + b'"'
            else:
                buff = b'<out of range %d>' % a[0]
        elif op == OP['simul_efun']:
            buff = b'"%s" %d' % (simuls[a[0]].encode('latin-1'), ins.nargs)
        elif op == OP['function_constructor']:
            k = a[0] & FP_MASK
            if k == FP_SIMUL:
                buff = b'<simul_efun> "%s"' % simuls[a[1]].encode('latin-1')
            elif k == FP_EFUN:
                buff = b'<efun> %s' % efuns.name(a[1]).encode('latin-1')
            elif k == FP_LOCAL:
                buff = b'<local_fun> %s' % fname(a[1]) if a[1] < prog.num_functions_total else \
                    b'<local_fun> <out of range %d>' % a[1]
            elif k == FP_FUNCTIONAL:
                buff = b'<functional, %d args>\nCode:' % a[1]
            elif k == FP_ANONYMOUS:
                buff = b'<anonymous function, %d args, %d locals, ends at %04x>\nCode:' % (a[1], a[2], ins.target)
            else:
                buff = b''
        elif op == OP['number']:
            buff = b'%d' % a[0]
        elif op == OP['real']:
            buff = b'%f' % a[0]
        elif op == OP['switch']:
            ttype, stable, etable, deflt = a
            w(b'switch\n      type: %02x table: %04x-%04x deflt: %04x\n' % (ttype, stable, etable, deflt))
            _pending.append((stable, ins))
            while _pending and _next_off(ins) >= _pending[-1][0]:
                _emit_table(w, prog, *_pending.pop())
            continue
        else:
            buff = b''
        w(b'%s %s\n' % (name, buff))
        # switch tables are printed when the body ends
        while _pending and _next_off(ins) >= _pending[-1][0]:
            _emit_table(w, prog, *_pending.pop())
    while _pending:
        _emit_table(w, prog, *_pending.pop())
    return b''.join(out)



def _next_off(ins):
    return ins.off + ins.size


def _raw(b):
    return b.split(b'\0')[0]


def _emit_table(w, prog, stable, ins):
    w(b'      switch table (for %04x)\n' % ins.off)
    t = ins.extra['table']
    if t['kind'] == 'direct':
        for i, addr in enumerate(t['addrs']):
            w(b'\t%2d: %04x\n' % (i, addr))
        w(b'\tminval = %d\n' % t['minval'])
    else:
        for key, addr in t['entries']:
            if t['kind'] == 'int':
                w(b'\t%-4d\t%04x\n' % (struct.unpack('<i', struct.pack('<I', key))[0], addr))
            elif key == 0xffffffff:
                w(b'\t%-4d\t%04x\n' % (0, addr))
            else:
                w(b'\t"%s"\t%04x\n' % (_dstr(prog.strings[key]), addr))
