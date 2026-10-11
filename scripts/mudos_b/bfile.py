"""Parse a MudOS v22-era compiled binary (.b, magic MUDB).

Layout (binaries.c save_binary): "MUDB", u32 driver_id, u32 config_id,
u16-len include list, u16-len program name, i32 total_size, program_t blob
(pointers made relative by locate_out), then u16-length-prefixed inherit
names, strings, defined variable names, defined function names, line info,
patches.

program_t (i386, COMPRESS_FUNCTION_TABLES, 104 bytes):
  0 name  4 flags  8 ref,func_ref  12 program  16 id_number  20 line_info
 24 file_info  28 line_swap_index  32 function_table  36 function_flags
 40 function_offsets  44 function_compressed  48 classes  52 class_members
 56 strings  60 variable_table  64 variable_types  68 inherit  72 total_size
 76 heart_beat  80 argument_types  84 type_start
 88 u16 program_size, num_classes, num_functions_total,
    num_functions_defined, num_strings, num_variables_total,
    num_variables_defined, num_inherited
"""
import struct
from dataclasses import dataclass, field

# function flags (program.h)
NAME_INHERITED = 0x1
NAME_UNDEFINED = 0x2
NAME_STRICT_TYPES = 0x4
NAME_PROTOTYPE = 0x8
NAME_DEF_BY_INHERIT = 0x10
NAME_ALIAS = 0x20
NAME_TRUE_VARARGS = 0x40
NAME_HIDDEN = 0x100
NAME_STATIC = 0x200
NAME_NO_MASK = 0x400
NAME_PRIVATE = 0x800
NAME_PROTECTED = 0x1000
NAME_PUBLIC = 0x2000
NAME_VARARGS = 0x4000
NAME_NO_CODE = NAME_UNDEFINED | NAME_ALIAS | NAME_PROTOTYPE

TYPE_MOD_ARRAY = 0x20
TYPE_MOD_CLASS = 0x40

INDEX_START_NONE = 65535


@dataclass
class Function:              # compiler_function_t, one per *defined* function
    name: str
    type: int
    runtime_index: int
    address: int


@dataclass
class Inherit:
    name: str
    function_index_offset: int
    variable_index_offset: int
    type_mod: int


@dataclass
class ClassDef:
    name: int                 # string index
    type: int
    size: int
    index: int                # first member in class_members


@dataclass
class Program:
    path: str
    name: str
    includes: list
    driver_id: int
    config_id: int
    flags: int
    heart_beat: int
    code: bytes
    functions: list           # Function, defined (sorted by name, as stored)
    function_flags: list      # u16 per runtime index (num_functions_total)
    runtime: dict             # runtime index -> ('def', num_arg, num_local, f_index) | ('inh', inherit, index)
    compressed: tuple
    classes: list
    class_members: list       # (name string index, type)
    strings: list
    variables: list           # names of defined variables
    variable_types: list
    inherits: list
    argument_types: list      # None unless #pragma save_types
    type_start: list
    num_functions_total: int
    num_variables_total: int
    file_info: bytes
    patches: bytes
    raw: bytes = field(repr=False, default=b'')


ENTRY_SIZE = 12   # compiler_function_t on i386 Linux (16 on the Win32 v22pre11 build)


def parse(path, entry_size=ENTRY_SIZE, encoding='latin-1'):
    d = open(path, 'rb').read()
    if d[:4] != b'MUDB':
        raise ValueError('not a MUDB binary: %s' % path)
    driver_id, config_id = struct.unpack_from('<II', d, 4)
    o = 12

    def lstr():
        nonlocal o
        n, = struct.unpack_from('<H', d, o)
        o += 2
        s = d[o:o + n]
        o += n
        return s

    includes = [x.decode(encoding) for x in lstr().split(b'\0') if x]
    name = lstr().decode(encoding)
    total, = struct.unpack_from('<i', d, o)
    o += 4
    blob = d[o:o + total]
    o += total
    u32 = lambda off: struct.unpack_from('<I', blob, off)[0]
    i32 = lambda off: struct.unpack_from('<i', blob, off)[0]
    (program_size, num_classes, nft, nfd, num_strings, nvt, nvd, ninh) = struct.unpack_from('<8H', blob, 88)
    flags = i32(4)
    heart_beat = i32(76)
    p_prog, p_ft, p_ff, p_fo, p_fc = u32(12), u32(32), u32(36), u32(40), u32(44)
    p_cls, p_cm, p_vt, p_inh, p_at, p_ts = u32(48), u32(52), u32(64), u32(68), u32(80), u32(84)
    code = blob[p_prog:p_prog + program_size]
    ftab = []
    for i in range(nfd):
        _n, typ, ridx, addr = struct.unpack_from('<IHHH', blob, p_ft + i * entry_size)
        ftab.append([None, typ, ridx, addr])
    fflags = list(struct.unpack_from('<%dH' % nft, blob, p_ff)) if nft else []
    first_defined, first_overload, num_compressed, num_deleted = struct.unpack_from('<4H', blob, p_fc)
    n_ov = first_defined - num_compressed
    cindex = list(blob[p_fc + 8:p_fc + 8 + max(n_ov, 0)])
    classes = [ClassDef(*struct.unpack_from('<4H', blob, p_cls + i * 8)) for i in range(num_classes)]
    nmembers = sum(c.size for c in classes)
    class_members = [struct.unpack_from('<2H', blob, p_cm + i * 4) for i in range(nmembers)]
    vtypes = list(struct.unpack_from('<%dH' % nvd, blob, p_vt)) if nvd else []
    inh_raw = [struct.unpack_from('<IHHH', blob, p_inh + i * 12) for i in range(ninh)]
    argument_types = type_start = None
    if p_at:
        type_start = list(struct.unpack_from('<%dH' % nfd, blob, p_ts)) if nfd else []
        n = 0
        for ts, f in zip(type_start, ftab):
            pass
        # argument_types length: up to type_start end; derive from blob layout
        end = p_ts if p_ts > p_at else total
        argument_types = list(struct.unpack_from('<%dH' % ((end - p_at) // 2), blob, p_at))

    # trailing sections
    inh_names = [lstr().decode(encoding) for _ in range(ninh)]
    strings = [lstr() for _ in range(num_strings)]
    variables = [lstr().decode(encoding) for _ in range(nvd)]
    fnames = [lstr().decode(encoding) for _ in range(nfd)]
    file_info = lstr()
    patches = lstr()
    for f, n in zip(ftab, fnames):
        f[0] = n
    functions = [Function(*f) for f in ftab]
    inherits = [Inherit(n, r[1], r[2], r[3]) for n, r in zip(inh_names, inh_raw)]

    # runtime function table (FIND_FUNC_ENTRY)
    runtime = {}
    for i in range(nft):
        if i >= first_defined:
            off = p_fo + (i - num_deleted) * 4
        else:
            idx = i - first_overload
            if i < first_overload or idx >= n_ov or cindex[idx] == 255:
                first, last = 0, ninh - 1
                while last > first:
                    mid = (last + first + 1) // 2
                    if inherits[mid].function_index_offset > i:
                        last = mid - 1
                    else:
                        first = mid
                runtime[i] = ('inh', first, i - inherits[first].function_index_offset)
                continue
            off = p_fo + cindex[idx] * 4
        a, b, c = struct.unpack_from('<BBH', blob, off)
        if fflags[i] & NAME_INHERITED:
            runtime[i] = ('inh', struct.unpack_from('<H', blob, off)[0], c)
        else:
            runtime[i] = ('def', a, b, c)
    return Program(path=path, name=name, includes=includes, driver_id=driver_id, config_id=config_id,
                   flags=flags, heart_beat=heart_beat, code=code, functions=functions,
                   function_flags=fflags, runtime=runtime,
                   compressed=(first_defined, first_overload, num_compressed, num_deleted),
                   classes=classes, class_members=class_members, strings=strings,
                   variables=variables, variable_types=vtypes, inherits=inherits,
                   argument_types=argument_types, type_start=type_start,
                   num_functions_total=nft, num_variables_total=nvt,
                   file_info=file_info, patches=patches, raw=blob)
