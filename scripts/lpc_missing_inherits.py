#!/usr/bin/env python3
"""scripts/lpc_missing_inherits.py [SLUG...] [--min N] [--json FILE]

The objects that cannot load because a file they inherit is not in the lib -- the case the compile scan (scripts/lpc_warnings.py) does not
see: `lpcc --batch` compiles `inherit MACRO;` fine when the macro is defined, and the load fails only when the inherited file is read
(`Inherited file '/inherit/item/tessera' does not exist!`).  Static, no driver:

  macro    `inherit TESSERA;` where a header of the lib defines `#define TESSERA "/inherit/item/tessera"` and that file is not in the lib
  literal  `inherit "/std/room/class_guild";` / `inherit __DIR__ "base";` with the file missing
  undef    `inherit IDENT;` with an all-caps IDENT no header defines (scripts/lpc_restore_macros.py / lpc_restore_bases.py)

A file counts once per missing target.  Wizard, backup and test directories are left out (the same SKIP pattern as lpc_restore_macros.py).
Per lib it prints the objects affected and the biggest missing targets; --min N hides targets with fewer users; --json writes
{slug: {target: [files]}}.  Whether a donor exists is scripts/lpc_restore_bases.py's plan."""
import collections
import json
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import lpc_restore_macros as R  # noqa: E402
from lpc_restore_bases import own_defs  # noqa: E402

LIT = re.compile(rb'(?m)^[ \t]*inherit[ \t]+(__DIR__[ \t]*)?"([^"\n]+)"[ \t]*;')
MAC = re.compile(rb"(?m)^[ \t]*inherit[ \t]+([A-Z][A-Z0-9_]*)[ \t]*;")


def norm(p):
    p = p.strip()
    if p.endswith(".c"):
        p = p[:-2]
    elif p.endswith(".lpc"):
        p = p[:-4]
    return os.path.normpath("/" + p.lstrip("/"))


def scan(slug, files, fileset):
    defs = own_defs(slug, files)
    alldefs = R.lib_scan(slug, fileset)[0]
    objs = {norm(f) for f in files if f.endswith((".lpc", ".c"))}     # a lib that kept its `.c` names (the upstream-hosted English ones) counts too
    miss = collections.defaultdict(list)      # (kind, target) -> files
    for rel in files:
        if not rel.endswith(".lpc") or R.SKIP.search(rel) or re.search(r"/(tests?|doc|docs|help)/", rel):
            continue
        try:
            b = open(f"{R.REPO}/libs/{slug}/work{rel}", "rb").read()
        except OSError:
            continue
        if b"inherit" not in b:
            continue
        for m in LIT.finditer(b):
            t = m.group(2).decode("utf-8", "replace")
            if m.group(1):
                t = os.path.dirname(rel) + "/" + t
            elif not t.startswith("/"):
                continue                       # relative to nothing we can resolve here
            if norm(t) not in objs:
                miss[("literal", norm(t))].append(rel)
        for m in MAC.finditer(b):
            name = m.group(1).decode()
            if name in defs:
                if norm(defs[name]) not in objs:
                    miss[("macro", f"{name} {norm(defs[name])}")].append(rel)
            elif m.group(1) not in alldefs:
                miss[("undef", name)].append(rel)
    return miss


def main():
    args = sys.argv[1:]
    mn = 1
    out = None
    if "--min" in args:
        i = args.index("--min")
        mn = int(args[i + 1])
        del args[i:i + 2]
    if "--json" in args:
        i = args.index("--json")
        out = args[i + 1]
        del args[i:i + 2]
    only = [a for a in args if not a.startswith("--")]
    by = R.tracked()
    res = {}
    tot = 0
    for slug in sorted(only or by):
        if slug not in by or os.path.exists(f"{R.REPO}/libs/{slug}/work/.git"):
            continue
        miss = scan(slug, by[slug], set(by[slug]))
        files = {f for fs in miss.values() for f in fs}
        if not files:
            continue
        tot += len(files)
        res[slug] = {f"{k[0]}:{k[1]}": v for k, v in miss.items()}
        top = sorted(miss.items(), key=lambda kv: -len(kv[1]))
        print(f"{slug}: {len(files)} object(s) with a missing base, {len(miss)} target(s)")
        for (kind, tgt), fs in top[:8]:
            if len(fs) >= mn:
                print(f"    {len(fs):4d} {kind:7s} {tgt}   e.g. {fs[0]}")
    print(f"{tot} object(s) in {len(res)} lib(s)")
    if out:
        json.dump(res, open(out, "w"), ensure_ascii=False)


if __name__ == "__main__":
    main()
