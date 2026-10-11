"""Decompile MudOS v22 bytecode (.b) back to LPC source.

The compiler is simple and its code shapes are fixed (icode.c, trees.c,
grammar.y), so control flow is recovered by matching those shapes rather
than by general graph structuring:

  if:        cond; br_false ELSE; then; [branch END; ELSE: else;] END:
  ?:         cond; br_false F; a; branch END; F: b; END:
  while/for: [init;] branch TEST; BODY: body; [inc;] TEST: cond; bbranch BODY
  forever:   BODY: body; [inc;] bbranch BODY
  do-while:  BODY: body; cond; bbranch BODY
  foreach:   expr; foreach ...; branch NEXT; BODY: body; NEXT: next_foreach BODY; exit_foreach
  switch:    expr; switch hdr; body; branch END; <table>; END:
  catch:     catch END; expr-or-block; end_catch; END:
  && / ||:   a; land/lor END; b; END:

Correctness is checked by recompiling the output with the original driver
and comparing the programs (see oracle.py).
"""
import struct

from . import bfile
from .disasm import decode, Efuns, FP_MASK, FP_LOCAL, FP_EFUN, FP_SIMUL, FP_FUNCTIONAL, FP_ANONYMOUS, FP_NOT_BINDABLE
from .ops import OP, BASE

TYPE_NAMES = {0: '', 1: 'mixed', 2: 'void', 3: 'void', 4: 'int', 5: 'string', 6: 'object',
              7: 'mapping', 8: 'function', 9: 'float', 10: 'buffer'}
TYPE_NOVALUE = 2


class DecompileError(Exception):
    pass


class StrayBranch(DecompileError):
    def __init__(self, target, msg):
        super().__init__(msg)
        self.target = target


# ------------------------------------------------------------------ expressions
# precedence (higher binds tighter)
P_COMMA, P_ASSIGN, P_COND, P_LOR, P_LAND, P_BOR, P_XOR, P_BAND, P_EQ, P_REL, P_SHIFT, \
    P_ADD, P_MUL, P_UNARY, P_POSTFIX, P_PRIMARY = range(16)

BINOPS = {
    'add': ('+', P_ADD), 'subtract': ('-', P_ADD), 'multiply': ('*', P_MUL), 'divide': ('/', P_MUL),
    'mod': ('%', P_MUL), 'and': ('&', P_BAND), 'or': ('|', P_BOR), 'xor': ('^', P_XOR),
    'lsh': ('<<', P_SHIFT), 'rsh': ('>>', P_SHIFT), 'eq': ('==', P_EQ), 'ne': ('!=', P_EQ),
    'lt': ('<', P_REL), 'le': ('<=', P_REL), 'gt': ('>', P_REL), 'ge': ('>=', P_REL),
}
ASSIGNOPS = {
    'assign': '=', 'void_assign': '=', 'add_eq': '+=', 'void_add_eq': '+=', 'sub_eq': '-=',
    'and_eq': '&=', 'or_eq': '|=', 'xor_eq': '^=', 'lsh_eq': '<<=', 'rsh_eq': '>>=',
    'mult_eq': '*=', 'div_eq': '/=', 'mod_eq': '%=',
}
BRANCH_COND = {  # forward conditional branch -> (negate?, comparison op or None)
    'branch_when_zero': (False, None), 'branch_when_non_zero': (True, None),
    'branch_ne': (False, 'eq'), 'branch_eq': (False, 'ne'),
    'branch_ge': (False, 'lt'), 'branch_le': (False, 'gt'),
}


class E:
    prec = P_PRIMARY
    value = True       # produces a stack value

    def src(self, prec=0):
        s = self.text()
        return '(' + s + ')' if self.prec < prec else s


class Raw(E):
    def __init__(self, s, prec=P_PRIMARY):
        self.s, self.prec = s, prec

    def text(self):
        return self.s


class Num(E):
    def __init__(self, n):
        self.n = n
        self.prec = P_PRIMARY if n >= 0 else P_UNARY

    def text(self):
        return str(self.n)


class Real(E):
    def __init__(self, f):
        self.f = f

    def text(self):
        r = repr(float(struct.unpack('<f', struct.pack('<f', self.f))[0]))
        if 'e' in r or 'inf' in r or 'nan' in r:
            r = '%.9g' % self.f
            if '.' not in r and 'e' not in r:
                r += '.0'
        return r


class Str(E):
    def __init__(self, b, ctx):
        self.b, self.ctx = b, ctx

    def text(self):
        return self.ctx.quote(self.b)


class Bin(E):
    def __init__(self, op, l, r):
        self.op, self.l, self.r = op, l, r
        self.sym, self.prec = BINOPS[op]

    def text(self):
        return '%s %s %s' % (self.l.src(self.prec), self.sym, self.r.src(self.prec + 1))


class Un(E):
    prec = P_UNARY

    def __init__(self, sym, e):
        self.sym, self.e = sym, e

    def text(self):
        inner = self.e.src(P_UNARY)
        if self.sym == '-' and inner.startswith('-'):
            inner = '(' + inner + ')'
        return self.sym + inner


class Assign(E):
    prec = P_ASSIGN

    def __init__(self, sym, lv, rv, void=False):
        self.sym, self.lv, self.rv, self.void = sym, lv, rv, void
        self.value = not void

    def text(self):
        return '%s %s %s' % (self.lv.src(P_UNARY), self.sym, self.rv.src(P_ASSIGN))


class IncDec(E):
    def __init__(self, sym, lv, post, void=False):
        self.sym, self.lv, self.post, self.void = sym, lv, post, void
        self.prec = P_POSTFIX if post else P_UNARY
        self.value = not void

    def text(self):
        return self.lv.src(P_POSTFIX) + self.sym if self.post else self.sym + self.lv.src(P_UNARY)


class Call(E):
    prec = P_POSTFIX

    def __init__(self, name, args, value=True):
        self.name, self.args, self.value = name, args, value

    def text(self):
        return '%s(%s)' % (self.name, ', '.join(a.src(P_ASSIGN) for a in self.args))


class CallOther(E):
    prec = P_POSTFIX

    def __init__(self, ob, fn, args):
        self.ob, self.fn, self.args = ob, fn, args

    def text(self):
        return '%s->%s(%s)' % (self.ob.src(P_POSTFIX), self.fn, ', '.join(a.src(P_ASSIGN) for a in self.args))


class Index(E):
    prec = P_POSTFIX

    def __init__(self, base, idx, rev=False):
        self.base, self.idx, self.rev = base, idx, rev

    def text(self):
        return '%s[%s%s]' % (self.base.src(P_POSTFIX), '<' if self.rev else '', self.idx.src(0))


class Range(E):
    prec = P_POSTFIX

    def __init__(self, base, lo, hi, lrev, hrev):
        self.base, self.lo, self.hi, self.lrev, self.hrev = base, lo, hi, lrev, hrev

    def text(self):
        lo = ('<' if self.lrev else '') + self.lo.src(0)
        hi = '' if self.hi is None else ('<' if self.hrev else '') + self.hi.src(0)
        return '%s[%s..%s]' % (self.base.src(P_POSTFIX), lo, hi)


class NewClass(E):
    prec = P_POSTFIX

    def __init__(self, k, vals, ctx):
        self.k, self.vals, self.ctx = k, vals, ctx

    def text(self):
        nm = CLASS_NAMES[self.k]
        if not self.vals:
            return 'new(class %s)' % nm
        c = self.ctx.prog.classes[self.k]
        mem = self.ctx.prog.class_members[c.index:c.index + c.size]
        return 'new(class %s, %s)' % (nm, ', '.join('%s : %s' % (self.ctx.string(m[0]).decode('latin-1'), v.src(P_ASSIGN))
                                                  for m, v in zip(mem, self.vals)))


class Member(E):
    prec = P_POSTFIX

    def __init__(self, base, name):
        self.base, self.name = base, name

    def text(self):
        return '%s->%s' % (self.base.src(P_POSTFIX), self.name)


class Cond(E):
    prec = P_COND

    def __init__(self, c, a, b):
        self.c, self.a, self.b = c, a, b

    def text(self):
        return '%s ? %s : %s' % (self.c.src(P_LOR), self.a.src(P_ASSIGN), self.b.src(P_COND))


class Logic(E):
    def __init__(self, sym, l, r):
        self.sym, self.l, self.r = sym, l, r
        self.prec = P_LAND if sym == '&&' else P_LOR

    def text(self):
        r = self.r.text() if isinstance(self.r, Logic) and self.r.sym == self.sym else self.r.src(self.prec + 1)
        return '%s %s %s' % (self.l.src(self.prec), self.sym, r)


class Array(E):
    def __init__(self, items):
        self.items = items

    def text(self):
        if not self.items:
            return '({ })'
        return '({ %s })' % ', '.join(i.src(P_ASSIGN) for i in self.items)


class Mapping(E):
    def __init__(self, pairs):
        self.pairs = pairs

    def text(self):
        if not self.pairs:
            return '([ ])'
        return '([ %s ])' % ', '.join('%s : %s' % (k.src(P_ASSIGN), v.src(P_ASSIGN)) for k, v in self.pairs)


class Comma(E):
    prec = P_COMMA

    def __init__(self, a, b):
        self.a, self.b = a, b

    def text(self):
        b = self.b.text() if isinstance(self.b, Comma) else self.b.src(P_ASSIGN)
        return '%s, %s' % (self.a.src(P_ASSIGN), b)


class Catch(E):
    def __init__(self, body, block=None):
        self.body, self.block = body, block

    def text(self):
        if self.block is not None:
            return 'catch ' + self.block
        return 'catch(%s)' % self.body.src(0)


class Expand(E):
    prec = P_UNARY

    def __init__(self, e):
        self.e = e

    def text(self):
        return self.e.src(P_POSTFIX) + '...'


class Novalue(E):
    """A statement-like effect sitting in expression position (void efun)."""
    value = False

    def __init__(self, e):
        self.e = e
        self.prec = e.prec

    def text(self):
        return self.e.text()


# ------------------------------------------------------------------ statements

class Stmt:
    pass


class SExpr(Stmt):
    def __init__(self, e):
        self.e = e

    def lines(self, ind):
        return [ind + self.e.src(0) + ';']


class SRaw(Stmt):
    def __init__(self, s):
        self.s = s

    def lines(self, ind):
        return [ind + self.s]


class SRet(Stmt):
    def __init__(self, e, void=False):
        self.e, self.void = e, void

    def lines(self, ind):
        if self.e is None:
            return [ind + ('return;' if self.void else 'return 0;')]
        return [ind + 'return %s;' % self.e.src(0)]


class SIf(Stmt):
    def __init__(self, cond, then, els):
        self.cond, self.then, self.els = cond, then, els

    def lines(self, ind):
        out = [ind + 'if (%s) {' % self.cond.src(0)]
        out += block_lines(self.then, ind + '    ')
        if self.els is not None:
            if len(self.els) == 1 and isinstance(self.els[0], SIf):
                sub = self.els[0].lines(ind)
                out.append(ind + '} else ' + sub[0].lstrip())
                out += sub[1:]
                return out
            out.append(ind + '} else {')
            out += block_lines(self.els, ind + '    ')
        out.append(ind + '}')
        return out


class SLoop(Stmt):
    def __init__(self, kind, cond, body, init=None, inc=None):
        self.kind, self.cond, self.body, self.init, self.inc = kind, cond, body, init, inc

    def lines(self, ind):
        b = block_lines(self.body, ind + '    ')
        c = self.cond.src(0) if self.cond is not None else ''
        if self.kind == 'do':
            return [ind + 'do {'] + b + [ind + '} while (%s);' % c]
        if self.kind == 'for':
            init = self.init.src(0) if self.init is not None else ''
            inc = self.inc.src(0) if self.inc is not None else ''
            return [ind + 'for (%s; %s; %s) {' % (init, c, inc)] + b + [ind + '}']
        return [ind + 'while (%s) {' % (c or '1')] + b + [ind + '}']


class SForeach(Stmt):
    def __init__(self, vars_, expr, body):
        self.vars, self.expr, self.body = vars_, expr, body

    def lines(self, ind):
        return [ind + 'foreach (%s in %s) {' % (', '.join(self.vars), self.expr.src(0))] + \
            block_lines(self.body, ind + '    ') + [ind + '}']


class SSwitch(Stmt):
    def __init__(self, expr, body):
        self.expr, self.body = expr, body

    def lines(self, ind):
        out = [ind + 'switch (%s) {' % self.expr.src(0)]
        for s in self.body:
            if isinstance(s, SCase):
                out += s.lines(ind)
            else:
                out += s.lines(ind + '    ')
        out.append(ind + '}')
        return out


class SCase(Stmt):
    def __init__(self, labels):
        self.labels = labels

    def lines(self, ind):
        return [ind + l for l in self.labels]


class SBlock(Stmt):
    def __init__(self, body):
        self.body = body

    def lines(self, ind):
        return [ind + '{'] + block_lines(self.body, ind + '    ') + [ind + '}']


def block_lines(stmts, ind):
    out = []
    for s in stmts:
        out += s.lines(ind)
    return out


# ------------------------------------------------------------------ context

class Context:
    """Per-program information needed to render names."""

    def __init__(self, prog, mud, efuns, simuls, encoding='gb18030', out_encoding='gb18030'):
        self.prog, self.mud, self.efuns, self.simuls = prog, mud, efuns, simuls
        self.encoding, self.out_encoding = encoding, out_encoding
        self.simul_set = set(simuls)
        self._vcache = {}

    def quote(self, b):
        b = b.split(b'\0')[0]
        out = []
        for ch in b:
            c = chr(ch)
            if ch == 0x5c:
                out.append('\\\\')
            elif ch == 0x22:
                out.append('\\"')
            elif ch == 0x0a:
                out.append('\\n')
            elif ch == 0x09:
                out.append('\\t')
            elif ch == 0x0d:
                out.append('\\r')
            elif ch == 0x1b:
                out.append('\\e')
            elif ch == 0x07:
                out.append('\\a')
            elif ch == 0x08:
                out.append('\\b')
            elif ch < 0x20 or ch == 0x7f:
                out.append('\\%03o' % ch)
            else:
                out.append(c)
        # bytes >= 0x80 travel as latin-1 code points; the writer re-encodes
        return '"' + ''.join(out) + '"'

    def string(self, idx):
        return self.prog.strings[idx].split(b'\0')[0]

    def var_name(self, idx, prog=None):
        prog = prog or self.prog
        if not prog.inherits:
            return prog.variables[idx]
        last = prog.inherits[-1]
        lp = self.mud.get(last.name)
        first = last.variable_index_offset + lp.num_variables_total
        if idx >= first:
            return prog.variables[idx - first]
        i = len(prog.inherits) - 1
        while idx < prog.inherits[i].variable_index_offset:
            i -= 1
        return self.var_name(idx - prog.inherits[i].variable_index_offset, self.mud.get(prog.inherits[i].name))

    def func_name(self, idx):
        return self.mud.function_name(self.prog, idx)

    def efun(self, tok):
        return self.efuns.by_token.get(tok)

    def efun_call_name(self, tok):
        e = self.efun(tok)
        n = e['name'] if e else '<efun %d>' % tok
        if n in self.simul_set:
            return 'efun::' + n
        return n

    def inherit_label(self, i):
        name = self.prog.inherits[i].name
        base = name.rsplit('/', 1)[-1]
        if base.endswith('.c'):
            base = base[:-2]
        return base


# ------------------------------------------------------------------ function decompiler

class FuncDecompiler:
    def __init__(self, ctx, instrs, nargs, nlocals, local_base=0, names=None):
        self.ctx = ctx
        self.ins = instrs
        self.at = {x.off: i for i, x in enumerate(instrs)}
        self.nargs, self.nlocals = nargs, nlocals
        self.local_base = local_base
        self.names = names or {}
        self.used_locals = set()
        # loop/switch context: list of dicts with break/continue addresses
        self.ctl = []
        self.foreach_depth = 0
        self.slot_of = {}
        self.local_types = {}
        self.void_return = False
        self.claimed = set()
        self.loop_starts = set()
        for k, y in enumerate(instrs):
            if not y.efun and OPN.get(y.op) in LOOP_CLOSERS:
                self.loop_starts.add(y.target)

    # -- names
    def lname(self, n):
        self.used_locals.add(n)
        if n in self.names:
            nm = self.names[n]
        elif n < self.nargs:
            nm = 'arg%d' % (n + 1) if self.nargs > 1 else 'arg'
        else:
            nm = 'v%d' % (n - self.nargs + 1)
        self.slot_of[nm] = n
        return nm

    # -- helpers
    def idx(self, off):
        if off not in self.at:
            raise DecompileError('no instruction at %04x' % off)
        return self.at[off]

    def end_off(self):
        last = self.ins[-1]
        return last.off + last.size

    def decode(self, lo, hi, stack=None, want_value=False):
        """Decompile instructions with offsets in [lo, hi). Returns (stmts, stack)."""
        stmts = []
        stack = list(stack or [])
        i = self.idx(lo) if lo < self.end_off() else len(self.ins)
        while i < len(self.ins) and self.ins[i].off < hi:
            x = self.ins[i]
            if x.off in self.loop_starts and x.off not in self.claimed:
                self.claimed.add(x.off)
                i = self.do_loop_body_first(i, stmts, stack)
                continue
            i = self.step(i, x, stmts, stack, hi)
        return stmts, stack

    def pop(self, stack, n=1):
        if len(stack) < n:
            raise DecompileError('stack underflow')
        if n == 0:
            return []
        out = stack[-n:]
        del stack[-n:]
        return out

    def flush(self, stmts, stack):
        """Expressions left on the stack whose values were discarded can't exist;
        but statement-effects (Novalue) may sit there: move them to stmts."""
        keep = []
        for e in stack:
            if isinstance(e, Novalue):
                stmts.append(SExpr(e.e))
            else:
                keep.append(e)
        stack[:] = keep

    def push_value(self, stack, e):
        stack.append(e)

    def opname(self, x):
        return None if x.efun else OPN[x.op]

    # -- main dispatcher; returns next instruction index
    def step(self, i, x, stmts, stack, hi):
        ctx = self.ctx
        name = self.opname(x)
        nxt = i + 1

        if x.efun:
            return self.do_efun(i, x, stmts, stack)

        if name == 'push':
            for kind, n in x.args:
                if kind == 'string':
                    stack.append(Str(ctx.string(n), ctx))
                elif kind == 'number':
                    stack.append(Num(n))
                elif kind == 'global':
                    stack.append(Raw(ctx.var_name(n)))
                else:
                    stack.append(Raw(self.lname(n)))
            return nxt
        if name in ('const0', 'const1'):
            stack.append(Num(0 if name == 'const0' else 1))
            return nxt
        if name == 'byte':
            stack.append(Num(x.args[0]))
            return nxt
        if name == 'nbyte':
            stack.append(Num(-x.args[0]))
            return nxt
        if name == 'number':
            stack.append(Num(x.args[0]))
            return nxt
        if name == 'real':
            stack.append(Real(x.args[0]))
            return nxt
        if name in ('string', 'short_string'):
            stack.append(Str(ctx.string(x.args[0]), ctx))
            return nxt
        if name in ('local', 'transfer_local'):
            stack.append(Raw(self.lname(x.args[0])))
            return nxt
        if name == 'global':
            stack.append(Raw(ctx.var_name(x.args[0])))
            return nxt
        if name == 'local_lvalue':
            stack.append(Raw(self.lname(x.args[0])))
            return nxt
        if name == 'global_lvalue':
            stack.append(Raw(ctx.var_name(x.args[0])))
            return nxt
        if name in BINOPS:
            l, r = self.pop(stack, 2)
            stack.append(Bin(name, l, r))
            return nxt
        if name == 'not':
            e, = self.pop(stack)
            stack.append(Un('!', e))
            return nxt
        if name == 'negate':
            e, = self.pop(stack)
            stack.append(Un('-', e))
            return nxt
        if name == 'compl':
            e, = self.pop(stack)
            stack.append(Un('~', e))
            return nxt
        if name in ('index', 'index_lvalue'):
            ix, b = self.pop(stack, 2)
            stack.append(Index(b, ix))
            return nxt
        if name in ('rindex', 'rindex_lvalue'):
            ix, b = self.pop(stack, 2)
            stack.append(Index(b, ix, rev=True))
            return nxt
        if name in RANGES:
            lrev, hrev, two = RANGES[name]
            if two:
                lo_, hi_, b = self.pop(stack, 3)
            else:
                lo_, b = self.pop(stack, 2)
                hi_ = None
            stack.append(Range(b, lo_, hi_, lrev, hrev))
            return nxt
        if name == 'new_empty_class':
            stack.append(NewClass(x.args[0], [], ctx))
            return nxt
        if name == 'new_class':
            c = ctx.prog.classes[x.args[0]]
            vals = self.pop(stack, c.size)
            stack.append(NewClass(x.args[0], vals, ctx))
            return nxt
        if name in ('member', 'member_lvalue'):
            b, = self.pop(stack)
            stack.append(Member(b, self.class_member_name(b, x.args[0])))
            return nxt
        if name in ASSIGNOPS:
            # stack: value, lvalue (lvalue pushed last)
            rv, lv = self.pop(stack, 2)
            if isinstance(rv, NewClass) and isinstance(lv, Raw) and lv.s in self.slot_of:
                self.local_types[self.slot_of[lv.s]] = bfile.TYPE_MOD_CLASS | rv.k
            void = name.startswith('void')
            a = Assign(ASSIGNOPS[name], lv, rv, void=void)
            if void:
                stmts.append(SExpr(a))
            else:
                stack.append(a)
            return nxt
        if name == 'void_assign_local':
            rv, = self.pop(stack)
            if isinstance(rv, NewClass):
                self.local_types[x.args[0]] = bfile.TYPE_MOD_CLASS | rv.k
            stmts.append(SExpr(Assign('=', Raw(self.lname(x.args[0])), rv, void=True)))
            return nxt
        if name == 'loop_incr':
            st_ = SExpr(IncDec('++', Raw(self.lname(x.args[0])), True, void=True))
            st_.is_incr = True
            stmts.append(st_)
            return nxt
        if name in ('inc', 'dec'):
            lv, = self.pop(stack)
            stmts.append(SExpr(IncDec('++' if name == 'inc' else '--', lv, True, void=True)))
            return nxt
        if name in ('pre_inc', 'pre_dec', 'post_inc', 'post_dec'):
            lv, = self.pop(stack)
            stack.append(IncDec('++' if 'inc' in name else '--', lv, name.startswith('post')))
            return nxt
        if name == 'pop_value':
            e, = self.pop(stack)
            stmts.append(SExpr(e))
            return nxt
        if name == 'return':
            e, = self.pop(stack)
            self.flush(stmts, stack)
            stmts.append(SRet(e))
            return nxt
        if name == 'return_zero':
            self.flush(stmts, stack)
            stmts.append(SRet(None, self.void_return))
            return nxt
        if name == 'aggregate':
            n = x.args[0]
            items = self.pop(stack, n)
            stack.append(Array(items))
            return nxt
        if name == 'aggregate_assoc':
            n = x.args[0]
            items = self.pop(stack, n)
            stack.append(Mapping([(items[k], items[k + 1]) for k in range(0, n, 2)]))
            return nxt
        if name == 'call_function_by_address':
            args = self.pop(stack, x.nargs)
            stack.append(Call(ctx.func_name(x.args[0]), args))
            return nxt
        if name == 'call_inherited':
            args = self.pop(stack, x.nargs)
            inh, fidx = x.args
            np = ctx.mud.get(ctx.prog.inherits[inh].name)
            fn = ctx.mud.function_name(np, fidx)
            if fn == '#global_init#':
                # compiler-generated init chain; drop the call and its pop
                stack.append(Novalue(Raw('')))
                if i + 1 < len(self.ins) and OPN.get(self.ins[i + 1].op) == 'pop_value' and not self.ins[i + 1].efun:
                    stack.pop()
                    return i + 2
                return nxt
            stack.append(Call('%s::%s' % (self.inherit_qual(inh, fn), fn), args))
            return nxt
        if name == 'simul_efun':
            args = self.pop(stack, x.nargs)
            stack.append(Call(ctx.simuls[x.args[0]], args))
            return nxt
        if name == 'expand_varargs':
            which = x.args[0]
            pos = len(stack) - 1 - which
            stack[pos] = Expand(stack[pos])
            return nxt
        if name == 'sscanf' or name == 'parse_command':
            return self.do_lvalue_efun(i, x, stmts, stack)
        if name in BRANCH_COND or name in ('land', 'lor'):
            return self.do_forward_cond(i, x, stmts, stack, hi)
        if name == 'branch':
            return self.do_branch(i, x, stmts, stack, hi)
        if name == 'switch':
            return self.do_switch(i, x, stmts, stack)
        if name == 'foreach':
            return self.do_foreach(i, x, stmts, stack)
        if name == 'catch':
            return self.do_catch(i, x, stmts, stack)
        if name == 'function_constructor':
            return self.do_funcon(i, x, stmts, stack)
        if name == 'exit_foreach':
            # emitted before 'return' inside foreach and after the loop; handled by callers
            return nxt
        if name in ('time_expression',):
            j = self.find_op(i + 1, 'end_time_expression')
            body, st = self.decode(self.ins[i + 1].off, self.ins[j].off)
            if st:
                raise DecompileError('time_expression with value')
            stack.append(Raw('time_expression {\n%s\n}' % '\n'.join(block_lines(body, '    '))))
            return j + 1
        if name in ('bbranch', 'bbranch_when_zero', 'bbranch_when_non_zero', 'bbranch_lt',
                    'loop_cond_local', 'loop_cond_number', 'while_dec', 'next_foreach'):
            raise DecompileError('unexpected loop end at %04x' % x.off)
        raise DecompileError('unhandled op %s at %04x' % (name, x.off))

    def class_member_name(self, base, idx):
        classes = self.ctx.prog.classes
        k = self.class_of(base)
        if k is None:
            if len(classes) == 1:
                k = 0
            else:
                raise DecompileError('member access on unknown class')
            if isinstance(base, Raw) and base.s in self.slot_of:
                self.local_types[self.slot_of[base.s]] = bfile.TYPE_MOD_CLASS | k
        c = classes[k]
        nm, _t = self.ctx.prog.class_members[c.index + idx]
        return self.ctx.string(nm).decode('latin-1')

    def class_of(self, e):
        if isinstance(e, Raw) and e.s in self.slot_of:
            t = self.local_types.get(self.slot_of[e.s])
            if t is not None and t & bfile.TYPE_MOD_CLASS and not t & bfile.TYPE_MOD_ARRAY:
                return t & 0x1f
        return None

    def inherit_qual(self, inh, fn):
        """'' when '::fn' is unambiguous, else the inherit label."""
        prog = self.ctx.prog
        hits = 0
        for k, ih in enumerate(prog.inherits):
            p = self.ctx.mud.get(ih.name)
            if p is None:
                continue
            for j in range(p.num_functions_total):
                if self.ctx.mud.function_name(p, j) == fn and not (p.function_flags[j] & bfile.NAME_NO_CODE & ~bfile.NAME_UNDEFINED):
                    hits += 1
                    break
        if hits <= 1:
            return ''
        return self.ctx.inherit_label(inh)

    def find_op(self, i, opname):
        while i < len(self.ins):
            if not self.ins[i].efun and OPN[self.ins[i].op] == opname:
                return i
            i += 1
        raise DecompileError('no %s' % opname)

    # -- efuns
    def do_efun(self, i, x, stmts, stack):
        ctx = self.ctx
        e = ctx.efun(x.op)
        if e is None:
            raise DecompileError('unknown efun %d' % x.op)
        n = x.nargs
        args = self.pop(stack, n)
        nm = e['name']
        # drop the argument the compiler filled in as a default
        df = e['default']
        if df != 0xff and n == e['min_args'] and args:
            last = args[-1]
            if df == 0xfe and isinstance(last, Call) and last.name in ('this_object', 'efun::this_object') and not last.args:
                args = args[:-1]
            elif df != 0xfe and isinstance(last, Num) and last.n == df:
                args = args[:-1]
        if nm == 'call_other' and len(args) >= 2 and isinstance(args[1], Str) and _ident(args[1].b):
            call = CallOther(args[0], args[1].b.decode('latin-1'), args[2:])
        else:
            call = Call(ctx.efun_call_name(x.op), args)
        if e['ret_type'] == TYPE_NOVALUE:
            nx = self.ins[i + 1] if i + 1 < len(self.ins) else None
            if nx is not None and not nx.efun and OPN[nx.op] == 'const0' and self.value_used_after(i + 1):
                stack.append(call)
                return i + 2
            stack.append(Novalue(call))
            self.flush(stmts, stack)
            return i + 1
        stack.append(call)
        return i + 1

    def value_used_after(self, j):
        """const0 right after a void efun: the void value was used (novalue_used)."""
        if j + 1 >= len(self.ins):
            return True
        nx = self.ins[j + 1]
        return nx.efun or OPN[nx.op] != 'pop_value'

    def do_lvalue_efun(self, i, x, stmts, stack):
        # sscanf(s, fmt, lv...) : s, fmt pushed, then each lvalue + void_assign
        n = x.args[0]
        name = OPN[x.op]
        base = 2 if name == 'sscanf' else 3
        fixed = self.pop(stack, base)
        lvs = []
        j = i + 1
        for _ in range(n):
            k = j
            while k < len(self.ins) and (self.ins[k].efun or OPN[self.ins[k].op] != 'void_assign'):
                k += 1
            if k >= len(self.ins):
                raise DecompileError('sscanf lvalues')
            sub, st = self.decode(self.ins[j].off, self.ins[k].off)
            lvs.append(self.one_value(sub, st, x))
            j = k + 1
        stack.append(Call(name, fixed + lvs))
        return j

    # -- control flow
    def do_forward_cond(self, i, x, stmts, stack, hi):
        name = OPN[x.op]
        T = x.target
        if name in ('land', 'lor'):
            l, = self.pop(stack)
            sub, st = self.decode(self.ins[i + 1].off, T)
            r = self.one_value(sub, st, x)
            stack.append(Logic('&&' if name == 'land' else '||', l, r))
            return self.idx(T) if T < self.end_off() else len(self.ins)
        negate, cmp = BRANCH_COND[name]
        if cmp:
            l, r = self.pop(stack, 2)
            cond = Bin(cmp, l, r)
        else:
            c, = self.pop(stack)
            cond = Un('!', c) if negate else c
        self.flush(stmts, stack)
        # find the end of the then-part
        ti = self.idx(T) if T < self.end_off() else len(self.ins)
        last = self.ins[ti - 1]
        els_end = None
        if (not last.efun and OPN[last.op] == 'branch' and last.target >= T and ti - 1 > i
                and not self.is_jump_out(last.target)):
            els_end = last.target
            then_hi = last.off
        else:
            then_hi = T
        then, st = self.decode(self.ins[i + 1].off, then_hi)
        if els_end is not None:
            els, st2 = self.decode(T, els_end)
            if st and st2 and len(st) == 1 and len(st2) == 1 and not then and not els:
                stack.append(Cond(cond, st[0], st2[0]))
                return self.idx(els_end) if els_end < self.end_off() else len(self.ins)
            if st or st2:
                raise DecompileError('if/else leaves values at %04x' % x.off)
            stmts.append(SIf(cond, then, els))
            return self.idx(els_end) if els_end < self.end_off() else len(self.ins)
        if st:
            raise DecompileError('if leaves values at %04x' % x.off)
        stmts.append(SIf(cond, then, None))
        return ti

    def is_jump_out(self, target):
        for c in reversed(self.ctl):
            if target in (c.get('brk'), c.get('cont')):
                return True
        return False

    def one_value(self, sub, st, x):
        if len(st) != 1:
            raise DecompileError('expected one value at %04x (stmts %d, stack %d)' % (x.off, len(sub), len(st)))
        return comma_fold(sub, st[0], x)

    def do_branch(self, i, x, stmts, stack, hi):
        T = x.target
        # break / continue
        for c in reversed(self.ctl):
            if T == c.get('brk'):
                self.flush(stmts, stack)
                stmts.append(SRaw('break;'))
                return i + 1
            if T == c.get('cont'):
                self.flush(stmts, stack)
                stmts.append(SRaw('continue;'))
                return i + 1
        if T > x.off and self.loop_end_at_safe(x.off + x.size) is not None:
            j = self.loop_end_at_safe(x.off + x.size)
            if self.ins[j].off >= T:
                return self.do_loop_test_first(i, x, stmts, stack)
        raise StrayBranch(T, 'stray branch at %04x' % x.off)

    def loop_end_at_safe(self, off):
        if off not in self.at:
            return None
        return self.loop_end_at(off)

    def loop_end_at(self, off):
        """Instruction index of a loop-closing backward branch to `off`, scanning forward."""
        for j in range(self.idx(off), len(self.ins)):
            y = self.ins[j]
            if not y.efun and OPN[y.op] in LOOP_CLOSERS and y.target == off:
                return j
        return None

    def do_loop_test_first(self, i, x, stmts, stack):
        body_lo = x.off + x.size
        T = x.target
        j = self.loop_end_at(body_lo)
        if j is None:
            raise DecompileError('no loop close for branch at %04x' % x.off)
        closer = self.ins[j]
        brk = closer.off + closer.size
        self.flush(stmts, stack)
        cname = OPN[closer.op]
        if cname == 'next_foreach':
            raise DecompileError('foreach shape mismatch')
        self.claimed.add(body_lo)
        cond = self.loop_cond(T, j)
        # the body may end with a for-increment that 'continue' jumps to:
        # pick the latest branch target inside the body whose tail up to the
        # test is a single expression statement
        cont = T
        bi, ti = self.idx(body_lo), self.idx(T) if T in self.at else len(self.ins)
        cands = sorted({y.target for y in self.ins[bi:ti]
                        if not y.efun and OPN[y.op] == 'branch' and body_lo < y.target < T}, reverse=True)
        for c in cands:
            ci = self.idx(c) if c in self.at else None
            if ci is None:
                continue
            tail = self.ins[ci:ti]
            if any(not y.efun and (y.target is not None or OPN[y.op] in ('switch', 'catch', 'function_constructor')) for y in tail):
                continue
            try:
                saved = set(self.claimed)
                incs, st2 = self.decode(c, T)
                self.claimed = saved
            except DecompileError:
                self.claimed = saved
                continue
            if not st2 and len(incs) == 1 and isinstance(incs[0], SExpr):
                cont = c
                break
        for attempt in range(8):
            saved = set(self.claimed)
            self.ctl.append({'brk': brk, 'cont': cont})
            try:
                if cont == T:
                    body, st = self.decode(body_lo, T)
                    inc = None
                else:
                    body, st = self.decode(body_lo, cont)
                    incs, st2 = self.decode(cont, T)
                    if st2 or len(incs) != 1 or not isinstance(incs[0], SExpr):
                        raise DecompileError('for increment shape at %04x' % cont)
                    inc = incs[0].e
            except StrayBranch as sb:
                self.ctl.pop()
                self.claimed = saved
                if body_lo < sb.target < T and sb.target != cont:
                    cont = sb.target
                    continue
                raise
            self.ctl.pop()
            break
        if st:
            raise DecompileError('loop body leaves values')
        if inc is None and body and getattr(body[-1], 'is_incr', False):
            inc = body[-1].e
            body = body[:-1]
        if inc is not None:
            init = None
            if stmts and isinstance(stmts[-1], SExpr) and getattr(stmts[-1].e, 'void', False):
                init = stmts.pop().e
            stmts.append(SLoop('for', cond, body, init=init, inc=inc))
        else:
            stmts.append(SLoop('while', cond, body))
        return j + 1

    def make_loop(self, stmts, body, cond, body_lo, T):
        # for-loop when the last body statement is a loop_incr or inc, and prior stmt exists
        if body and getattr(body[-1], 'is_incr', False):
            inc = body[-1].e
            init = None
            if stmts and isinstance(stmts[-1], SExpr) and getattr(stmts[-1].e, 'void', False):
                init = stmts.pop().e
            return SLoop('for', cond, body[:-1], init=init, inc=inc)
        return SLoop('while', cond, body)

    def loop_cond(self, T, j):
        closer = self.ins[j]
        cname = OPN[closer.op]
        if cname == 'loop_cond_local':
            return Bin('lt', Raw(self.lname(closer.args[0])), Raw(self.lname(closer.args[1])))
        if cname == 'loop_cond_number':
            return Bin('lt', Raw(self.lname(closer.args[0])), Num(closer.args[1]))
        if cname == 'while_dec':
            return IncDec('--', Raw(self.lname(closer.args[0])), True)
        sub, st = self.decode(T, closer.off)
        if cname == 'bbranch':
            if sub or st:
                raise DecompileError('forever loop with test code')
            return None
        if cname == 'bbranch_lt':
            if sub or len(st) != 2:
                raise DecompileError('bbranch_lt operands')
            return Bin('lt', st[0], st[1])
        if cname == 'bbranch_lt' and len(st) == 2:
            pass
        c = self.one_value(sub, st, closer)
        if cname == 'bbranch_when_zero':
            return Un('!', c)
        return c

    # do-while / forever loops: called when reaching a backward-branch target
    def do_loop_body_first(self, i, stmts, stack):
        x = self.ins[i]
        j = self.loop_end_at(x.off)
        closer = self.ins[j]
        brk = closer.off + closer.size
        cname = OPN[closer.op]
        self.flush(stmts, stack)
        if cname == 'bbranch':
            self.ctl.append({'brk': brk, 'cont': None, 'forever': True})
            body, st = self.decode(x.off, closer.off)
            self.ctl.pop()
            if st:
                raise DecompileError('forever loop leaves values')
            stmts.append(SLoop('while', None, body))
            return j + 1
        # do-while: condition is the trailing expression; continue goes to its start
        cont = None
        for attempt in range(8):
            saved = set(self.claimed)
            self.ctl.append({'brk': brk, 'cont': cont, 'do': True})
            try:
                body, st = self.decode(x.off, closer.off)
            except StrayBranch as sb:
                self.ctl.pop()
                self.claimed = saved
                if x.off < sb.target <= closer.off and sb.target != cont:
                    cont = sb.target
                    continue
                raise
            self.ctl.pop()
            break
        if cname in ('loop_cond_local', 'loop_cond_number', 'while_dec'):
            cond = self.loop_cond(closer.off, j)
            if st:
                raise DecompileError('do-while leaves values')
        elif cname == 'bbranch_lt':
            if len(st) != 2:
                raise DecompileError('do-while bbranch_lt')
            cond = Bin('lt', st[0], st[1])
        else:
            if len(st) != 1:
                raise DecompileError('do-while cond')
            cond = st[0] if cname == 'bbranch_when_non_zero' else Un('!', st[0])
        stmts.append(SLoop('do', cond, body))
        return j + 1

    def do_foreach(self, i, x, stmts, stack):
        e, = self.pop(stack)
        self.flush(stmts, stack)
        flags, a, b = x.args
        vars_ = []
        names = [(a, flags & 1)] + ([(b, flags & 2)] if flags & 4 else [])
        for n, glob in names:
            vars_.append(self.ctx.var_name(n) if glob else self.lname(n))
        br = self.ins[i + 1]
        if br.efun or OPN[br.op] != 'branch':
            raise DecompileError('foreach without branch')
        body_lo = br.off + br.size
        nf = self.idx(br.target)
        nfi = self.ins[nf]
        if OPN[nfi.op] != 'next_foreach' or nfi.target != body_lo:
            raise DecompileError('foreach next mismatch')
        ex = nf + 1
        if ex < len(self.ins) and not self.ins[ex].efun and OPN[self.ins[ex].op] == 'exit_foreach':
            brk, resume = self.ins[ex].off, ex + 1
        else:
            brk, resume = nfi.off + nfi.size, nf + 1
        self.claimed.add(body_lo)
        self.ctl.append({'brk': brk, 'cont': nfi.off, 'foreach': True})
        self.foreach_depth += 1
        body, st = self.decode(body_lo, nfi.off)
        self.foreach_depth -= 1
        self.ctl.pop()
        if st:
            raise DecompileError('foreach body leaves values')
        stmts.append(SForeach(vars_, e, body))
        return resume

    def do_switch(self, i, x, stmts, stack):
        e, = self.pop(stack)
        self.flush(stmts, stack)
        ttype, stable, etable, deflt = x.args
        t = x.extra['table']
        end = etable
        labels = {}
        if t['kind'] == 'direct':
            for k, addr in enumerate(t['addrs']):
                if addr:
                    labels.setdefault(addr, []).append('case %d:' % (t['minval'] + k))
        else:
            ents = t['entries']
            k = 0
            while k < len(ents):
                key, addr = ents[k]
                if t['kind'] == 'string':
                    lab = 'case 0:' if key == 0xffffffff else 'case %s:' % self.ctx.quote(self.ctx.string(key))
                    labels.setdefault(addr, []).append(lab)
                    k += 1
                    continue
                skey = struct.unpack('<i', struct.pack('<I', key))[0]
                if addr <= 1 and k + 1 < len(ents):
                    # range: lower entry (addr 0/1 marker) then upper entry with address
                    hkey, haddr = ents[k + 1]
                    hk = struct.unpack('<i', struct.pack('<I', hkey))[0]
                    labels.setdefault(haddr, []).append('case %d..%d:' % (skey, hk))
                    k += 2
                    continue
                labels.setdefault(addr, []).append('case %d:' % skey)
                k += 1
        body_lo = x.off + x.size
        # the body ends with a compiler 'branch END' just before the table
        last_i = self.idx(stable) - 1 if stable in self.at else None
        # find the instruction that ends right at stable
        bi = None
        for j in range(i + 1, len(self.ins)):
            y = self.ins[j]
            if y.off + y.size == stable:
                bi = j
                break
            if y.off >= stable:
                break
        if bi is None or self.ins[bi].efun or OPN[self.ins[bi].op] != 'branch':
            raise DecompileError('switch without trailing branch')
        has_default = deflt != self.ins[bi].off
        if has_default:
            labels.setdefault(deflt, []).append('default:')
        # decode body piecewise, inserting labels
        cuts = sorted(a for a in labels if body_lo <= a <= self.ins[bi].off)
        body = []
        self.ctl.append({'brk': end, 'cont': None, 'switch': True})
        pos = body_lo
        seq = cuts + [self.ins[bi].off]
        # label at the very end (case with no code) handled by placement
        for k, a in enumerate(seq):
            if a > pos:
                part, st = self.decode(pos, a)
                if st:
                    raise DecompileError('switch case leaves values')
                body += part
                pos = a
            if k < len(cuts):
                body.append(SCase(labels[a]))
        self.ctl.pop()
        stmts.append(SSwitch(e, body))
        # resume after the table
        return self.idx(end) if end < self.end_off() else len(self.ins)

    def do_catch(self, i, x, stmts, stack):
        T = x.target
        ec = self.idx(T) - 1
        y = self.ins[ec]
        if y.efun or OPN[y.op] != 'end_catch':
            raise DecompileError('catch without end_catch')
        sub, st = self.decode(self.ins[i + 1].off, y.off)
        if not sub and len(st) == 1:
            stack.append(Catch(st[0]))
        elif not st:
            stack.append(Catch(None, block='{\n' + '\n'.join(block_lines(sub, '    ')) + '\n}'))
        else:
            raise DecompileError('catch shape')
        return ec + 1

    def do_funcon(self, i, x, stmts, stack):
        kind = x.args[0]
        k = kind & FP_MASK
        ctx = self.ctx
        if k == FP_ANONYMOUS:
            nargs, nlocals, ln = x.args[1], x.args[2], x.args[3]
            lo = x.off + x.size
            hi = x.target
            sub_ins = [y for y in self.ins if lo <= y.off < hi]
            fd = FuncDecompiler(ctx, sub_ins, nargs, nargs + nlocals)
            fd.void_return = False
            fd.name_prefix = 'x'
            body, st = fd.decode(lo, hi)
            if st:
                raise DecompileError('anonymous function leaves values')
            params = ', '.join('mixed %s' % fd.lname(n) for n in range(nargs))
            decls = ['mixed %s;' % fd.lname(n) for n in range(nargs, nargs + nlocals)]
            body_lines = ['    ' + d for d in decls] + block_lines(trim_return(body, False), '    ')
            stack.append(Raw('function(%s) {\n%s\n}' % (params, '\n'.join(body_lines))))
            return self.idx(hi) if hi < self.end_off() else len(self.ins)
        bound, = self.pop(stack)
        args = []
        if isinstance(bound, Array):
            args = bound.items
        elif not (isinstance(bound, Num) and bound.n == 0):
            raise DecompileError('function constructor args')
        if k == FP_FUNCTIONAL:
            nargs, ln = x.args[1], x.args[2]
            lo = x.off + x.size
            hi = x.target
            sub_ins = [y for y in self.ins if lo <= y.off < hi]
            fd = FuncDecompiler(ctx, sub_ins, nargs, nargs, names={n: '$%d' % (n + 1) for n in range(nargs)})
            # bound args come first as $... ; the compiler numbers parameters after them
            fd.names = {}
            nb = len(args)
            for n in range(nb + nargs):
                fd.names[n] = '$%d' % (n - nb + 1) if n >= nb else '$(%s)' % args[n].src(0)
            fd.void_return = False
            fd.functional = True
            body, st = fd.decode(lo, hi)
            if not body or not isinstance(body[-1], SRet) or body[-1].e is None:
                raise DecompileError('functional body')
            expr = comma_fold(body[:-1], body[-1].e, x)
            stack.append(Raw('(: %s :)' % expr.src(0)))
            return self.idx(hi) if hi < self.end_off() else len(self.ins)
        if k == FP_LOCAL:
            nm = ctx.func_name(x.args[1])
        elif k == FP_EFUN:
            nm = ctx.efun_call_name(x.args[1])
        elif k == FP_SIMUL:
            nm = ctx.simuls[x.args[1]]
        else:
            raise DecompileError('function constructor kind %d' % kind)
        if args:
            stack.append(Raw('(: %s, %s :)' % (nm, ', '.join(a.src(P_ASSIGN) for a in args))))
        else:
            stack.append(Raw('(: %s :)' % nm))
        return i + 1


def trim_return(body, void):
    return body


def comma_fold(stmts, value, x=None):
    """(a, b, value): leading expression statements were compiled as popped values."""
    if not stmts:
        return value
    for st in stmts:
        if not isinstance(st, SExpr):
            raise DecompileError('statement inside expression at %04x' % (x.off if x else -1))
    out = value
    for st in reversed(stmts):
        out = Comma(st.e, out)
    return out


def _ident(b):
    s = b.decode('latin-1')
    return s.isidentifier() and s.isascii()


OPN = {}
RANGES = {
    'nn_range': (False, False, True), 'rn_range': (True, False, True), 'rr_range': (True, True, True),
    'nr_range': (False, True, True), 'ne_range': (False, False, False), 're_range': (True, False, False),
    'nn_range_lvalue': (False, False, True), 'rn_range_lvalue': (True, False, True),
    'rr_range_lvalue': (True, True, True), 'nr_range_lvalue': (False, True, True),
}
LOOP_CLOSERS = {'bbranch', 'bbranch_when_zero', 'bbranch_when_non_zero', 'bbranch_lt',
                'loop_cond_local', 'loop_cond_number', 'while_dec', 'next_foreach'}
from .ops import NAME as _NAME
OPN.update(_NAME)


# ------------------------------------------------------------------ program level

CLASS_NAMES = []   # set per program by ProgramDecompiler (class index -> name)


def type_str(t, name='', fn=False):
    base = t & 0x1f
    arr = t & bfile.TYPE_MOD_ARRAY
    if t & bfile.TYPE_MOD_CLASS:
        tn = 'class ' + CLASS_NAMES[base] if base < len(CLASS_NAMES) else 'mixed'
    else:
        tn = TYPE_NAMES.get(base, 'mixed')
    if not tn:
        return name
    return '%s %s%s' % (tn, '*' if arr else '', name)


def modifiers(flags):
    out = []
    if flags & bfile.NAME_PRIVATE:
        out.append('private')
    if flags & bfile.NAME_PROTECTED:
        out.append('protected')
    if flags & bfile.NAME_PUBLIC:
        out.append('public')
    if flags & bfile.NAME_NO_MASK:
        out.append('nomask')
    if flags & bfile.NAME_STATIC:
        out.append('static')
    if flags & bfile.NAME_VARARGS:
        out.append('varargs')
    return out


def function_ranges(prog):
    """(Function, start, end) for every function with code, in address order."""
    with_code = []
    for f in prog.functions:
        fl = prog.function_flags[f.runtime_index]
        if fl & (bfile.NAME_INHERITED | bfile.NAME_NO_CODE):
            continue
        with_code.append(f)
    with_code.sort(key=lambda f: f.address)
    out = []
    for k, f in enumerate(with_code):
        end = with_code[k + 1].address if k + 1 < len(with_code) else len(prog.code)
        out.append((f, f.address, end))
    return out


class ProgramDecompiler:
    def __init__(self, ctx):
        self.ctx = ctx
        self.prog = ctx.prog
        self.instrs = decode(self.prog, ctx.efuns)
        self.errors = []

    def instrs_in(self, lo, hi):
        return [x for x in self.instrs if lo <= x.off < hi]

    def func_header(self, f, nargs, proto, flags=None):
        prog = self.prog
        fl = prog.function_flags[f.runtime_index] if flags is None else flags
        mods = modifiers(fl)
        ret = type_str(f.type, f.name)
        args = []
        for n in range(nargs):
            an = '' if proto else (' arg%d' % (n + 1) if nargs > 1 else ' arg')
            if n == nargs - 1 and fl & bfile.NAME_TRUE_VARARGS:
                args.append('mixed *%s...' % an.strip())
            else:
                args.append('mixed' + an)
        return '%s(%s)' % (' '.join(mods + [ret]), ', '.join(args))

    def global_inits(self):
        prog = self.prog
        gi = next((f for f in prog.functions if f.name == '#global_init#'), None)
        if gi is None:
            return {}
        rng = next(((s, e) for f, s, e in function_ranges(prog) if f is gi), None)
        if rng is None:
            return {}
        fd = FuncDecompiler(self.ctx, self.instrs_in(*rng), 0, 0)
        body, st = fd.decode(*rng)
        inits = {}
        for s in body:
            if isinstance(s, SExpr) and isinstance(s.e, Assign) and isinstance(s.e.lv, Raw):
                inits[s.e.lv.s] = s.e.rv
            elif isinstance(s, SExpr) and isinstance(s.e, Raw) and s.e.s == '':
                continue
            elif isinstance(s, SRet):
                continue
            else:
                raise DecompileError('unexpected statement in #global_init#')
        return inits

    def run(self):
        prog, ctx = self.prog, self.ctx
        out = []
        CLASS_NAMES[:] = [ctx.string(c.name).decode('latin-1') for c in prog.classes]
        inherited_classes = set()
        for ih in prog.inherits:
            ip = ctx.mud.get(ih.name)
            if ip:
                inherited_classes |= {ip.strings[c.name].split(b'\0')[0] for c in ip.classes}
        for c in prog.classes:
            if ctx.string(c.name) in inherited_classes:
                continue
            mem = prog.class_members[c.index:c.index + c.size]
            out.append('class %s { %s }' % (CLASS_NAMES[prog.classes.index(c)],
                                            ' '.join('%s;' % type_str(t, ctx.string(nm).decode('latin-1')) for nm, t in mem)))
        if prog.classes:
            out.append('')
        # function table order: inherit statements and prototypes interleaved
        # exactly as their runtime indices fall (a header may declare
        # prototypes before the first inherit)
        events = []
        for k, ih in enumerate(prog.inherits):
            events.append((ih.function_index_offset, 0, k, 'inherit'))
        blocks = []
        for ih in prog.inherits:
            ip = ctx.mud.get(ih.name)
            n = ip.num_functions_total if ip else 0
            # the parent's #global_init# is not copied into children
            if ip and any(f.name == '#global_init#' for f in ip.functions):
                n -= 1
            blocks.append((ih.function_index_offset, ih.function_index_offset + n))
        for i in range(prog.num_functions_total):
            if any(a <= i < b for a, b in blocks):
                continue
            fl = prog.function_flags[i]
            f = next((f for f in prog.functions if f.runtime_index == i), None)
            if f is not None:
                if f.name == '#global_init#':
                    continue
                ent = prog.runtime[i]
                events.append((i, 1, (f, ent[1] if ent[0] == 'def' else 0, fl), 'proto'))
                continue
            # a prototype (usually from a header) later satisfied by an inherit
            tp, tf = ctx.mud.resolve(prog, i)
            if tf is None:
                raise DecompileError('unresolvable function %d' % i)
            tent = tp.runtime[tf.runtime_index]
            events.append((i, 1, (tf, tent[1] if tent[0] == 'def' else 0, fl), 'proto'))
        events.sort(key=lambda e: (e[0], e[1]))
        for pos, _, item, kind in events:
            if kind == 'inherit':
                ih = prog.inherits[item]
                n = ih.name[:-2] if ih.name.endswith('.c') else ih.name
                out.append('inherit "/%s";' % n)
            else:
                f, nargs, fl = item
                out.append(self.func_header(f, nargs, True, flags=fl) + ';')
        if events:
            out.append('')
        inits = self.global_inits()
        for name, t in zip(prog.variables, prog.variable_types):
            mods = modifiers(t & ~0x1f & ~bfile.TYPE_MOD_ARRAY & ~bfile.TYPE_MOD_CLASS & 0xff00)
            decl = ' '.join(mods + [type_str(t & 0xff, name)])
            if name in inits:
                decl += ' = ' + inits[name].src(P_ASSIGN)
            out.append(decl + ';')
        if prog.variables:
            out.append('')
        for f, lo, hi in function_ranges(prog):
            if f.name == '#global_init#':
                continue
            ent = prog.runtime[f.runtime_index]
            nargs, nloc = ent[1], ent[2]
            try:
                out += self.function(f, lo, hi, nargs, nloc)
            except DecompileError as e:
                self.errors.append('%s: %s' % (f.name, e))
                out.append('// DECOMPILE FAILED: %s: %s' % (f.name, e))
            out.append('')
        lines = []
        for l in '\n'.join(out).split('\n'):
            lines += wrap_line(l)
        return '\n'.join(lines).rstrip('\n') + '\n'

    def function(self, f, lo, hi, nargs, nloc):
        fd = FuncDecompiler(self.ctx, self.instrs_in(lo, hi), nargs, nargs + nloc)
        fd.void_return = (f.type & 0x1f) == 3
        body, st = fd.decode(lo, hi)
        if st:
            raise DecompileError('function leaves values on stack')
        if body and isinstance(body[-1], SRet) and body[-1].e is None:
            body = body[:-1]
        lines = [self.func_header(f, nargs, False) + ' {']
        for n in range(nargs, nargs + nloc):
            t = fd.local_types.get(n)
            lines.append('    %s;' % (type_str(t, fd.lname(n)) if t else 'mixed ' + fd.lname(n)))
        lines += block_lines(body, '    ')
        lines.append('}')
        return lines


def decompile(prog, mud, efuns, simuls):
    ctx = Context(prog, mud, efuns, simuls)
    pd = ProgramDecompiler(ctx)
    src = pd.run()
    return src, pd.errors


# ------------------------------------------------------------------ line wrapping
# The v22 lexer rejects physical lines of 1024 bytes or more and string
# literals much over that, so long lines are broken at spaces outside
# strings and long literals are split into adjacent literals.

WRAP = 760
STR_CHUNK = 600


def _units(body):
    """Split a literal body (latin-1 str with escapes) into indivisible units."""
    out = []
    i = 0
    n = len(body)
    while i < n:
        c = body[i]
        if c == '\\':
            if i + 1 < n and body[i + 1] in '01234567':
                j = i + 1
                while j < n and j < i + 4 and body[j] in '01234567':
                    j += 1
                out.append(body[i:j])
                i = j
            else:
                out.append(body[i:i + 2])
                i += 2
        elif ord(c) >= 0x81 and i + 1 < n:
            if i + 3 < n and 0x30 <= ord(body[i + 1]) <= 0x39:
                out.append(body[i:i + 4])
                i += 4
            else:
                out.append(body[i:i + 2])
                i += 2
        else:
            out.append(c)
            i += 1
    return out


def _tokens(line):
    """(kind, text): 'str' literals, 'sp' spaces outside strings, 'x' anything else."""
    toks = []
    i = 0
    n = len(line)
    while i < n:
        c = line[i]
        if c == '"':
            j = i + 1
            while j < n and line[j] != '"':
                j += 2 if line[j] == '\\' else 1
            toks.append(('str', line[i:j + 1]))
            i = j + 1
        elif c == "'":
            j = i + 1
            while j < n and line[j] != "'":
                j += 2 if line[j] == '\\' else 1
            toks.append(('x', line[i:j + 1]))
            i = j + 1
        elif c == ' ':
            j = i
            while j < n and line[j] == ' ':
                j += 1
            toks.append(('sp', line[i:j]))
            i = j
        else:
            j = i
            while j < n and line[j] not in '" \'':
                j += 1
            toks.append(('x', line[i:j]))
            i = j
    return toks


def wrap_line(line):
    if len(line) <= WRAP:
        return [line]
    ind = line[:len(line) - len(line.lstrip(' '))]
    cont = ind + '        '
    toks = []
    for k, t in _tokens(line.lstrip(' ')):
        if k == 'str' and len(t) > STR_CHUNK:
            units = _units(t[1:-1])
            chunk = ''
            first = True
            for u in units:
                if len(chunk) + len(u) > STR_CHUNK:
                    if not first:
                        toks.append(('sp', ' '))
                    toks.append(('str', '"' + chunk + '"'))
                    first = False
                    chunk = ''
                chunk += u
            if not first:
                toks.append(('sp', ' '))
            toks.append(('str', '"' + chunk + '"'))
        else:
            toks.append((k, t))
    out = []
    cur = ind
    for k, t in toks:
        if k == 'sp':
            if len(cur) > WRAP - 40:
                out.append(cur.rstrip(' '))
                cur = cont
            elif cur.strip():
                cur += t
            continue
        if len(cur) + len(t) > WRAP and cur.strip():
            out.append(cur.rstrip(' '))
            cur = cont
        cur += t
    if cur.strip():
        out.append(cur.rstrip(' '))
    return out
