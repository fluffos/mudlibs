#!/usr/bin/env python3
"""scripts/lpc_scan_includes.py [SLUG...]

An `#include` of a file the lib does not have (KB 04 section 6.1): the object / header that includes it does not compile (`Cannot #include /quset/huang/huangjobhy.lpc`), or, when
the missing file held functions (a quest's `ask_job`), compiles into `Undefined variable 'ask_job'` errors.  Detector, no edits.  For every `#include "x"` / `<x>` of a tracked `.lpc` / `.h` / `.c`
(wizard and backup directories aside) that the include rules do not resolve (relative to the includer, the lib's include directories, the root) it prints

    INC<TAB>slug<TAB>includer<TAB>name<TAB>-><TAB>candidate | N cands | none

where the candidate is the lib's only file with that base name.  9,555 rows in 243 libs on 2026-10-22 (chidi: 11): nearly all of them are area headers the archive never shipped (`/d/abarrach/path.h`
in ninetears: 1,724 includers) or includes that a master `include_file()` hook answers (esI / es1_win `../hole.h`), so read a candidate before repairing; a candidate whose directory differs from the
written one by a letter is a typo (chidi `/quset/huang/` -> `/quest/huang/`: the only one).  The compile scan (`lpc_load_census.py`) says which of them actually break an object."""
import os, re, sys, collections
REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, REPO + "/scripts")
import lpc_scan_callout_targets as S
slugs=[a for a in sys.argv[1:] if not a.startswith("--")] or sorted(d for d in os.listdir(REPO+"/libs") if os.path.isdir(f"{REPO}/libs/{d}/work"))
INC=re.compile(rb'(?m)^[ \t]*#[ \t]*include[ \t]+(["<])([^">\r\n]+)[">]')
tot=0
for slug in slugs:
    if slug in S.GITLINKS: continue
    L=S.Lib(slug)
    bybase=collections.defaultdict(list)
    for f in L.files: bybase[os.path.basename(f)].append(f)
    for f in sorted(L.files):
        if not f.endswith((".lpc",".h",".c")) or S.SKIP.search(f): continue
        b=L.read(f)
        if b"#" not in b: continue
        for m in INC.finditer(S.strip_comments(b)):
            name=m.group(2).decode("utf-8","replace")
            fdir=os.path.dirname(f)+"/"
            if name.startswith("/"): cands=[os.path.normpath(name)]
            else:
                cands=[os.path.normpath(fdir+name)] if m.group(1)==b'"' else []
                cands+=[os.path.normpath(d+"/"+name) for d in L.incdirs]+[os.path.normpath("/"+name)]
            if any(c in L.files for c in cands): continue
            alt=bybase.get(os.path.basename(name),[])
            tot+=1
            print("INC",slug,f,name,"->",alt[0] if len(alt)==1 else ("%d cands"%len(alt) if alt else "none"),sep="\t",flush=True)
print("total",tot,file=sys.stderr)
