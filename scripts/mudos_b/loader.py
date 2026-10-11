"""Load .b programs from a binaries tree, resolving inherits by path."""
import os
from . import bfile


class Mudlib:
    def __init__(self, binaries_dir, entry_size=bfile.ENTRY_SIZE):
        self.root = binaries_dir
        self.entry_size = entry_size
        self.cache = {}

    def path_of(self, name):
        name = name.lstrip('/')
        if name.endswith('.c'):
            name = name[:-2]
        return os.path.join(self.root, name + '.b')

    def get(self, name):
        key = name.lstrip('/')
        if key.endswith('.c'):
            key = key[:-2]
        if key not in self.cache:
            p = self.path_of(key)
            self.cache[key] = bfile.parse(p, self.entry_size) if os.path.exists(p) else None
        return self.cache[key]

    def resolve(self, prog, idx):
        """Follow a runtime function index down to (program, defined Function)."""
        seen = 0
        while True:
            ent = prog.runtime[idx]
            if ent[0] == 'def':
                fn = next((f for f in prog.functions if f.runtime_index == idx), None)
                return prog, fn
            inh = prog.inherits[ent[1]]
            nprog = self.get(inh.name)
            if nprog is None:
                return None, None
            prog, idx = nprog, ent[2]
            seen += 1
            if seen > 50:
                raise RuntimeError('inherit loop')

    def function_name(self, prog, idx):
        if not (prog.function_flags[idx] & bfile.NAME_INHERITED):
            fn = next((f for f in prog.functions if f.runtime_index == idx), None)
            return fn.name if fn else '<%d>' % idx
        p, fn = self.resolve(prog, idx)
        return fn.name if fn else '<inh %d>' % idx

    def simul_names(self, simul_path):
        """simuls[] as built by get_simul_efuns: runtime order, skipping static/private/no-code."""
        prog = self.get(simul_path)
        names = []
        for i in range(prog.num_functions_total):
            if prog.function_flags[i] & (bfile.NAME_NO_CODE | bfile.NAME_STATIC | bfile.NAME_PRIVATE):
                continue
            names.append(self.function_name(prog, i))
        return names
