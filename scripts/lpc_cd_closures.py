#!/usr/bin/env python3
"""Rewrite CD-driver partial application / composition chains into FluffOS
functionals:  &operator(==)(x) @ &operator([])(, F)  ->  (: ($(x)) == (($1)[F]) :)

Terms: &operator(OP)(args), &func(args) (one empty slot = the argument),
&func() (argument appended), and a bare identifier before '@' (f(x)).
Bound arguments that are lowercase expressions (locals, macro params) are
captured with $(...); constants, CamelCase globals and literals stay as is.
Usage: python3 scripts/lpc_cd_closures.py FILE...   (prints each rewrite; binary-safe for LF files)
"""
import re, sys

IDENT = re.compile(r'[A-Za-z_]\w*')

def balanced(s, i):
    """s[i] == '(' ; return index after the matching ')'."""
    depth = 0; j = i
    instr = None
    while j < len(s):
        c = s[j]
        if instr:
            if c == '\\': j += 2; continue
            if c == instr: instr = None
        elif c in '"\'': instr = c
        elif c == '(': depth += 1
        elif c == ')':
            depth -= 1
            if depth == 0: return j + 1
        j += 1
    raise ValueError("unbalanced")

def split_args(a):
    out, depth, cur, instr = [], 0, '', None
    for c in a:
        if instr:
            cur += c
            if c == instr: instr = None
            continue
        if c in '"\'': instr = c
        if c in '([{': depth += 1
        if c in ')]}': depth -= 1
        if c == ',' and depth == 0:
            out.append(cur.strip()); cur = ''; continue
        cur += c
    out.append(cur.strip())
    return out

def cap(a):
    a = a.strip()
    if re.fullmatch(r'"(?:[^"\\]|\\.)*"|-?\d+(\.\d+)?', a): return a
    if re.fullmatch(r'[A-Z][A-Z0-9_]*(\(.*\))?', a, re.S): return a   # constant / macro
    if re.fullmatch(r'[A-Z]\w*', a): return a                          # CamelCase global
    return '$(' + a + ')'

def ws(s, i):
    while i < len(s) and s[i] in ' \t\r\n\\':
        if s[i] == '\\' and i + 1 < len(s) and s[i+1] not in '\r\n': break
        i += 1
    return i

def parse_term(s, i):
    """Parse one term at s[i]; return (term, end) or None."""
    if s[i] == '&':
        m = IDENT.match(s, i + 1)
        if not m: return None
        name = m.group(0); j = m.end()
        if j >= len(s) or s[j] != '(': return None
        k = balanced(s, j)
        g1 = s[j+1:k-1]
        if name == 'operator':
            if k >= len(s) or s[k] != '(': return None
            k2 = balanced(s, k)
            return (('op', g1.strip(), s[k+1:k2-1]), k2)
        return (('fn', name, g1), k)
    m = IDENT.match(s, i)
    if m:
        return (('id', m.group(0)), m.end())
    return None

def apply(term, x):
    kind = term[0]
    if kind == 'id':
        return f'{term[1]}({x})'
    if kind == 'fn':
        name, args = term[1], term[2]
        if not args.strip():
            return f'{name}({x})'
        parts = split_args(args)
        assert parts.count('') == 1, term
        return f'{name}(' + ', '.join(x if p == '' else cap(p) for p in parts) + ')'
    op, args = term[1], term[2]
    parts = split_args(args)
    if len(parts) == 1: parts = [parts[0], '']
    a, b = parts
    if op == '[]':
        return f'({x})[{cap(b)}]' if a == '' else f'({cap(a)})[{x}]'
    if a == '':
        return f'({x}) {op} ({cap(b)})'
    return f'({cap(a)}) {op} ({x})'

def convert(s):
    out, i, n = [], 0, 0
    while i < len(s):
        # candidate chain start: '&ident(' or 'ident <ws> @ <ws> &'
        start = None
        if s[i] == '&' and (i == 0 or s[i-1] != '&') and IDENT.match(s, i + 1) and (i + 1 >= len(s) or s[i+1] != '&'):
            start = i
        else:
            m = IDENT.match(s, i)
            if m and (i == 0 or not (s[i-1].isalnum() or s[i-1] in '_&')):
                j = ws(s, m.end())
                if j < len(s) and s[j] == '@' and s[j+1:j+2] != '@':
                    k = ws(s, j + 1)
                    if k < len(s) and s[k] == '&':
                        start = i
        if start is None:
            out.append(s[i]); i += 1; continue
        try:
            terms = []
            t, j = parse_term(s, start); terms.append(t)
            while True:
                k = ws(s, j)
                if k < len(s) and s[k] == '@' and s[k+1:k+2] != '@':
                    k = ws(s, k + 1)
                    r = parse_term(s, k)
                    if not r: break
                    terms.append(r[0]); j = r[1]
                else:
                    break
            if all(t[0] == 'id' for t in terms) or (len(terms) == 1 and terms[0][0] != 'op' and s[start] != '&'):
                out.append(s[i]); i += 1; continue
            if len(terms) == 1 and terms[0][0] == 'fn' and '' not in split_args(terms[0][2]) and terms[0][2].strip():
                out.append(s[i]); i += 1; continue   # plain &func(full args): not partial
            x = '$1'
            for t in reversed(terms):
                x = apply(t, x)
            rep = f'(: {x} :)'
            print('   ', ' '.join(s[start:j].split()), '->', rep)
            out.append(rep); i = j; n += 1
        except Exception as e:
            out.append(s[i]); i += 1
    return ''.join(out), n

for p in sys.argv[1:]:
    d = open(p, 'rb').read().decode('utf-8')
    new, n = convert(d)
    open(p, 'wb').write(new.encode('utf-8'))
    print(p, n, 'chains')
