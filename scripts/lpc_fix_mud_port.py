#!/usr/bin/env python3
"""scripts/lpc_fix_mud_port.py [--apply] [SLUG...]

`get_config(__MUD_PORT__)` with the lib's own `include/runtime_config.h`:

  #include "runtime_config.h"
  #define LOCAL_PORT()   ((int) get_config(__MUD_PORT__))            // include/getconfig.h, the xkx / nitan / es2 login daemons and their network layer

The header is the one of an old MudOS: its numbers are not the driver's (`__MUD_PORT__` is `CFG_INT(0)` = 256 there, the lib's header starts the ints at 15), so `get_config()` answers
another setting, a string, and `(int)` on it is a compile-time no-op (KB 06 section 7.2xx, the float/int cast notes): `socket_bind(fd, LOCAL_PORT())` raises `Bad argument 2 to socket_bind()
Expected: int Got: "..."` for every connection that reaches the network layer (xkxz2, xkxc98sj, zhonghua2, zhongjidiyu), `get_config(__MUD_PORT__) + VERSION_PORT` (yxcs `versiond`) is a string
plus an int.  The header says itself what it means (`get_config(__MUD_PORT__) == __PORT__`, the comment of every runtime_config.h), and `__PORT__` is the driver's predefine for it: 15 libs already
had `#define LOCAL_PORT() __PORT__`.  This replaces `get_config(__MUD_PORT__)` (with an `(int)` or `to_int()` around it) by `__PORT__` in code; the comment lines of runtime_config.h are left alone.
Only a lib whose own runtime_config.h is the old one (`CFG_INT(x)` built on `BASE_CONFIG_INT`; the driver's header says `RC_BASE_CONFIG_INT`) is touched: with a current header
`get_config(__MUD_PORT__)` is right.  Binary-safe, idempotent.  Wizard homes, backups, the LDMud ports, the generated trees and `raw/` are not read.

Without --apply the plan is printed: `FIX<TAB>slug<TAB>/path<TAB>n`."""
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from lpc_fix_void_return import code_mask  # noqa: E402
import lpc_scan_cond_assign as sc  # noqa: E402

REPO = sc.REPO
# the wrapped forms first, the bare call last
WRAPPED = [
    re.compile(rb"\(\s*\(\s*int\s*\)\s*get_config\s*\(\s*__MUD_PORT__\s*\)\s*\)"),
    re.compile(rb"\(\s*to_int\s*\(\s*get_config\s*\(\s*__MUD_PORT__\s*\)\s*\)\s*\)"),
    re.compile(rb"\(\s*int\s*\)\s*get_config\s*\(\s*__MUD_PORT__\s*\)"),
    re.compile(rb"to_int\s*\(\s*get_config\s*\(\s*__MUD_PORT__\s*\)\s*\)"),
    re.compile(rb"get_config\s*\(\s*__MUD_PORT__\s*\)"),
]


def fix(b):
    """(new bytes, count) with every code occurrence replaced"""
    n = 0
    for rx in WRAPPED:
        mask = code_mask(b)
        out, pos = [], 0
        for m in rx.finditer(b):
            if not mask[m.start()]:
                continue
            out.append(b[pos:m.start()])
            out.append(b"__PORT__")
            pos = m.end()
            n += 1
        out.append(b[pos:])
        b = b"".join(out)
    return b, n


def stale_header(paths):
    """True when a runtime_config.h of the lib builds CFG_INT on the old BASE_CONFIG_INT"""
    for full in paths:
        if full.endswith("/runtime_config.h"):
            t = open(os.path.join(REPO, full), "rb").read()
            if b"BASE_CONFIG_INT" in t and b"RC_BASE_CONFIG_INT" not in t:
                return True
    return False


def main():
    a = sys.argv[1:]
    apply_ = "--apply" in a
    slugs = [x for x in a if not x.startswith("--")]
    total = 0
    for slug, paths in sorted(sc.tracked(slugs).items()):
        if slug in sc.LDMUD or slug in sc.GENERATED or not stale_header(paths):
            continue
        for full in paths:
            p = "/" + full.split("/work/", 1)[1]
            if sc.TOP.search(p) or sc.ANY.search(p) or p.endswith("/runtime_config.h"):
                continue
            f = os.path.join(REPO, full)
            try:
                b = open(f, "rb").read()
            except OSError:
                continue
            if b"__MUD_PORT__" not in b:
                continue
            nb, n = fix(b)
            if not n:
                continue
            total += n
            print(f"FIX\t{slug}\t{p}\t{n}")
            if apply_:
                open(f, "wb").write(nb)
    print(f"{total} site(s)", file=sys.stderr)


if __name__ == "__main__":
    main()
