"""Round-trip check: recompile decompiled LPC with the original driver and
compare the new program with the original .b.

Programs are compared in a canonical form: string/function/variable
references resolved to their content and names, push groups expanded, and
branch targets turned into instruction ordinals. Two programs that compare
equal execute the same instructions on the same operands.
"""
import os
import shutil
import signal
import struct
import subprocess
import time

from . import bfile
from .disasm import decode, FP_MASK, FP_LOCAL, FP_EFUN, FP_SIMUL, FP_FUNCTIONAL, FP_ANONYMOUS
from .ops import NAME as OPN


NUMBER_OPS = {'const0': 0, 'const1': 1}


def canon_function(prog, mud, efuns, simuls, lo, hi, all_instrs):
    ins = [x for x in all_instrs if lo <= x.off < hi]
    toks = []
    offmap = {}
    fixups = []
    for x in ins:
        offmap[x.off] = len(toks)
        if x.efun:
            toks.append(('efun', efuns.name(x.op), x.nargs))
            continue
        n = OPN[x.op]
        a = x.args
        if n == 'push':
            for kind, v in a:
                if kind == 'string':
                    toks.append(('str', prog.strings[v].split(b'\0')[0]))
                elif kind == 'number':
                    toks.append(('num', v))
                elif kind == 'global':
                    toks.append(('global', var_name(prog, mud, v)))
                else:
                    toks.append(('local', v))
            continue
        if n in NUMBER_OPS:
            toks.append(('num', NUMBER_OPS[n]))
        elif n in ('byte', 'number'):
            toks.append(('num', a[0]))
        elif n == 'nbyte':
            toks.append(('num', -a[0]))
        elif n == 'real':
            toks.append(('real', a[0]))
        elif n in ('string', 'short_string'):
            toks.append(('str', prog.strings[a[0]].split(b'\0')[0]))
        elif n == 'local':
            toks.append(('local', a[0]))
        elif n in ('global', 'global_lvalue'):
            toks.append((n, var_name(prog, mud, a[0])))
        elif n == 'call_function_by_address':
            toks.append(('call', mud.function_name(prog, a[0]), x.nargs))
        elif n == 'call_inherited':
            ip = mud.get(prog.inherits[a[0]].name)
            toks.append(('call_inherited', prog.inherits[a[0]].name, mud.function_name(ip, a[1]), x.nargs))
        elif n == 'simul_efun':
            toks.append(('simul', simuls[a[0]], x.nargs))
        elif n == 'switch':
            t = x.extra['table']
            if t['kind'] == 'direct':
                cases = sorted((t['minval'] + k, ad) for k, ad in enumerate(t['addrs']) if ad)
            elif t['kind'] == 'string':
                cases = sorted(((b'' if key == 0xffffffff else prog.strings[key].split(b'\0')[0]), ad)
                               for key, ad in t['entries'])
            else:
                cases = sorted((struct.unpack('<i', struct.pack('<I', key))[0], ad) for key, ad in t['entries'])
            tok = ['switch', t['kind'] if t['kind'] != 'direct' else 'int']
            toks.append(tok)
            fixups.append((tok, 'switch', cases, a[3]))
            continue
        elif n == 'function_constructor':
            k = a[0] & FP_MASK
            if k == FP_LOCAL:
                toks.append(('funcon', a[0], mud.function_name(prog, a[1])))
            elif k == FP_EFUN:
                toks.append(('funcon', a[0], efuns.name(a[1])))
            elif k == FP_SIMUL:
                toks.append(('funcon', a[0], simuls[a[1]]))
            else:
                tok = ['funcon', a[0], a[1:-1]]
                toks.append(tok)
                fixups.append((tok, 'target', x.target, None))
            continue
        elif x.target is not None:
            tok = [n] + list(a[:-1] if n in ('loop_cond_number', 'loop_cond_local', 'while_dec') else [])
            toks.append(tok)
            fixups.append((tok, 'target', x.target, None))
            continue
        else:
            toks.append((n,) + tuple(a))
    end = len(toks)
    for tok, kind, v, d in fixups:
        if kind == 'target':
            tok.append(('L', offmap.get(v, end if v >= hi else ('?', v))))
        else:
            tok.append(tuple((key, offmap.get(ad, ('?', ad))) for key, ad in v))
            tok.append(('D', offmap.get(d, ('?', d))))
    return [tuple(t) if isinstance(t, list) else t for t in toks]


def var_name(prog, mud, idx):
    if not prog.inherits:
        return prog.variables[idx]
    last = prog.inherits[-1]
    lp = mud.get(last.name)
    first = last.variable_index_offset + lp.num_variables_total
    if idx >= first:
        return prog.variables[idx - first]
    i = len(prog.inherits) - 1
    while idx < prog.inherits[i].variable_index_offset:
        i -= 1
    return var_name(mud.get(prog.inherits[i].name), mud, idx - prog.inherits[i].variable_index_offset)


def canon(prog, mud, efuns, simuls):
    from .decompile import function_ranges
    all_instrs = decode(prog, efuns)
    funcs = {}
    for f, lo, hi in function_ranges(prog):
        ent = prog.runtime[f.runtime_index]
        funcs[f.name] = dict(type=f.type, flags=prog.function_flags[f.runtime_index],
                             nargs=ent[1], nlocals=ent[2],
                             code=canon_function(prog, mud, efuns, simuls, lo, hi, all_instrs))
    table = []
    for i in range(prog.num_functions_total):
        table.append((mud.function_name(prog, i), prog.function_flags[i]))
    return dict(inherits=[i.name for i in prog.inherits],
                variables=list(zip(prog.variables, prog.variable_types)),
                table=table, funcs=funcs, heart_beat=prog.heart_beat)


def compare(a, b):
    """List of human-readable differences (empty when equivalent)."""
    d = []
    for k in ('inherits', 'variables', 'heart_beat'):
        if a[k] != b[k]:
            d.append('%s: %r != %r' % (k, a[k], b[k]))
    if a['table'] != b['table']:
        d.append('function table differs')
    for name in sorted(set(a['funcs']) | set(b['funcs'])):
        fa, fb = a['funcs'].get(name), b['funcs'].get(name)
        if fa is None or fb is None:
            d.append('function %s only in %s' % (name, 'original' if fb is None else 'recompiled'))
            continue
        for k in ('type', 'flags', 'nargs', 'nlocals'):
            if fa[k] != fb[k]:
                d.append('%s.%s: %r != %r' % (name, k, fa[k], fb[k]))
        if fa['code'] != fb['code']:
            ca, cb = fa['code'], fb['code']
            k = next((k for k in range(min(len(ca), len(cb))) if ca[k] != cb[k]), min(len(ca), len(cb)))
            d.append('%s: code differs at token %d: %r != %r' % (
                name, k, ca[k] if k < len(ca) else None, cb[k] if k < len(cb) else None))
    return d


# ------------------------------------------------------------------ driver runs

RUNNER = r'''// decompiler oracle: load objects listed in /log/oracle/jobs
int pos, part;
void run_batch();
void create() { pos = 1; part = 0; call_out("run_batch", 1); }
void run_batch()
{
    string chunk, *lines, path, err;
    object ob, pre;
    int n;
    // read_file() loads the whole file first and the driver caps that at
    // 200000 bytes, so the job list is split into jobs.0, jobs.1, ...
    chunk = read_file("/log/oracle/jobs." + part, pos, 50);
    if ((!chunk || !strlen(chunk)) && file_size("/log/oracle/jobs." + (part + 1)) > 0) {
        part++;
        pos = 1;
        chunk = read_file("/log/oracle/jobs." + part, pos, 50);
    }
    lines = chunk ? explode(chunk, "\n") : ({});
    pos += 50;
    for (n = 0; n < sizeof(lines); n++) {
        if (strlen(lines[n]) < 6 || lines[n][0..4] != "load ") continue;
        path = lines[n][5..];
        write_file("/log/oracle/CURRENT", path + "\n", 1);
        pre = find_object(path);
        if (pre) catch(destruct(pre));
        err = catch(ob = load_object(path));
        if (err || !ob) { write_file("/log/oracle/ERRORS", path + "\t" + replace_string(err || "noobj", "\n", " ") + "\n"); continue; }
        write_file("/log/oracle/LOADED", path + "\n");
        if (!interactive(ob)) catch(destruct(ob));
    }
    if (sizeof(lines)) { call_out("run_batch", 0); return; }
    write_file("/log/oracle/DONE", "ok\n", 1);
    shutdown(0);
}
'''


class Oracle:
    def __init__(self, raw_root, work='/tmp/wlo', port=47186, mem_kb=3000000):
        """raw_root: the pristine extracted lib (contains config.cfg, driver, world/)."""
        self.raw = raw_root
        self.work = work
        self.port = port
        self.mem_kb = mem_kb

    @property
    def world(self):
        return os.path.join(self.work, 'world')

    def reset(self):
        if os.path.exists(self.work):
            shutil.rmtree(self.work)
        shutil.copytree(self.raw, self.work, symlinks=True)
        os.chmod(os.path.join(self.work, 'driver'), 0o755)
        cfg = os.path.join(self.work, 'config.cfg')
        d = open(cfg, 'rb').read()
        import re
        d = re.sub(rb'mudlib directory : [^\r\n]*', b'mudlib directory : ' + self.world.encode(), d)
        d = re.sub(rb'binary directory : [^\r\n]*', b'binary directory : ' + self.world.encode() + b'/binaries', d)
        d = re.sub(rb'port number : \d+', b'port number : %d' % self.port, d)
        k = [0]

        def rep(m):
            k[0] += 1
            return b'telnet %d' % (self.port - 6 + k[0])
        d = re.sub(rb'telnet \d+', rep, d)
        open(cfg, 'wb').write(d)
        open(os.path.join(self.world, 'adm/daemons/zzoracle.c'), 'w').write(RUNNER)
        pre = os.path.join(self.world, 'data/config/preload')
        p = open(pre, 'rb').read().rstrip(b'\r\n') + b'\n/adm/daemons/zzoracle\n'
        open(pre, 'wb').write(p)
        os.makedirs(os.path.join(self.world, 'log/oracle'), exist_ok=True)

    def install(self, path, source_bytes):
        """Put decompiled source in place of path.c and drop its binary."""
        path = path.lstrip('/')
        fn = os.path.join(self.world, path + '.c')
        os.makedirs(os.path.dirname(fn), exist_ok=True)
        open(fn, 'wb').write(source_bytes)
        b = os.path.join(self.world, 'binaries', path + '.b')
        if os.path.exists(b):
            os.remove(b)

    def run(self, paths, timeout=3600, max_restarts=500):
        """Load each path; returns (loaded, errors, crashed). Restarts the driver after a crash."""
        od = os.path.join(self.world, 'log/oracle')
        for f in ('DONE', 'ERRORS', 'LOADED', 'CURRENT'):
            if os.path.exists(os.path.join(od, f)):
                os.remove(os.path.join(od, f))
        remaining = ['/' + p.lstrip('/') for p in paths]
        crashed = {}
        restarts = 0
        while remaining and restarts <= max_restarts:
            self._run_once(remaining, timeout)
            if os.path.exists(os.path.join(od, 'DONE')):
                break
            cur_f = os.path.join(od, 'CURRENT')
            cur = open(cur_f, 'rb').read().decode('latin-1').strip() if os.path.exists(cur_f) else None
            if cur in remaining:
                k = remaining.index(cur)
                crashed[cur.lstrip('/')] = self._crash_reason()
                remaining = remaining[k + 1:]
            else:
                crashed['<boot>'] = self._crash_reason()
                break
            restarts += 1
        errors = {}
        ef = os.path.join(od, 'ERRORS')
        if os.path.exists(ef):
            for line in open(ef, 'rb'):
                p, _, e = line.rstrip(b'\n').partition(b'\t')
                errors[p.decode('latin-1').lstrip('/')] = e.decode('gb18030', 'replace')
        loaded = set()
        lf = os.path.join(od, 'LOADED')
        if os.path.exists(lf):
            loaded = {l.decode('latin-1').strip().lstrip('/') for l in open(lf, 'rb')}
        return loaded, errors, crashed

    def _crash_reason(self):
        try:
            d = open(os.path.join(self.work, 'boot.log'), 'rb').read()[-3000:].decode('gb18030', 'replace')
        except OSError:
            return ''
        k = d.rfind('FATAL')
        return d[k:k + 120].replace('\n', ' ') if k >= 0 else d[-200:].replace('\n', ' ')

    def _run_once(self, paths, timeout):
        od = os.path.join(self.world, 'log/oracle')
        import glob
        for old in glob.glob(os.path.join(od, 'jobs.*')):
            os.remove(old)
        for k in range(0, max(len(paths), 1), 4000):
            open(os.path.join(od, 'jobs.%d' % (k // 4000)), 'w', encoding='latin-1').write(
                ''.join('load %s\n' % p for p in paths[k:k + 4000]))
        zb = os.path.join(self.world, 'binaries/adm/daemons/zzoracle.b')
        if os.path.exists(zb):
            os.remove(zb)
        log = open(os.path.join(self.work, 'boot.log'), 'wb')
        import resource
        lim = self.mem_kb * 1024
        proc = subprocess.Popen(['../driver', '../config.cfg'], cwd=self.world, stdout=log, stderr=log,
                                preexec_fn=lambda: resource.setrlimit(resource.RLIMIT_AS, (lim, lim)))
        t0 = time.time()
        while proc.poll() is None and time.time() - t0 < timeout:
            if os.path.exists(os.path.join(od, 'DONE')):
                break
            time.sleep(0.5)
        time.sleep(0.5)
        if proc.poll() is None:
            proc.send_signal(signal.SIGTERM)
            try:
                proc.wait(10)
            except subprocess.TimeoutExpired:
                proc.kill()
                proc.wait()

    def new_binary(self, path):
        return os.path.join(self.world, 'binaries', path.lstrip('/') + '.b')
