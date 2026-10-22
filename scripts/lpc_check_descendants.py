#!/usr/bin/env python3
"""scripts/lpc_check_descendants.py ROWS.tsv [SLUG...]

Second half of the dead-handler method (KB 06 section 7.349): the static resolver of `lpc_scan_callout_targets.py` asks whether a FILE defines a function; a base class or a
`#include`d body registers handlers that its descendants define, and that is not a bug.  For each `kind<TAB>slug<TAB>file<TAB>handler[<TAB>..]` row of `lpc_fix_dead_add_action.py`
(REMOVE / CUT / NEAR / MANUAL; or any such TSV) every descendant of FILE is collected from the whole lib (a file whose `inherit` or `#include` line, a macro expanded, names the stem of
FILE, then those files' descendants, up to eight levels) and the handler is looked up in their definitions.  Prints `ALIVE slug file handler definer` (a descendant defines it: not a bug),
`BASE slug file handler n` (descendants exist and none defines it) or `LEAF slug file handler` (nothing inherits or includes the file).  Found 133 ALIVE rows in the first 8,457
(es1's `std/adt/command.lpc` `quit` is the user's, a vendor mixin's `do_deposit` is the innkeeper's, arkadia's `unq_move` is `std/room.lpc`'s): the first resolver only looked one level down."""
import collections, os, re, sys
import os as _os
REPO = _os.path.dirname(_os.path.dirname(_os.path.abspath(__file__)))
sys.path.insert(0, _os.path.dirname(_os.path.abspath(__file__)))
import lpc_scan_callout_targets as m

rows = collections.defaultdict(list)
only = set(sys.argv[2:])
for ln in open(sys.argv[1], encoding="utf-8", errors="replace"):
    f = ln.rstrip("\n").split("\t")
    if f[0] in ("REMOVE", "CUT", "IFREMOVE", "NEAR", "MANUAL") and len(f) >= 5 and (not only or f[1] in only):
        rows[f[1]].append((f[2], f[3]))

STR = re.compile(rb'"([^"\n]*)"')
IDENT = re.compile(rb"[A-Za-z_]\w*")
for slug in sorted(rows):
    if slug in m.GITLINKS:
        continue
    L = m.Lib(slug)
    # stems mentioned by inherit lines, per mentioning file
    mention = collections.defaultdict(set)      # stem -> files that mention it in an inherit line
    for f in sorted(L.files):
        if not f.endswith((".lpc", ".c", ".h")) or m.SKIP.search(f):
            continue
        b = L.read(f)
        if b"inherit" not in b and b"include" not in b:
            continue
        sc = m.strip_comments(b)
        stems = set()

        def of_expr(txt):
            out = set()
            for q in STR.findall(txt):
                out.add(os.path.splitext(os.path.basename(q.decode("utf-8", "replace")))[0])
            for ident in IDENT.findall(txt):
                v = L.macros.get(ident.decode())
                if v:
                    for q in STR.findall(v[0]):
                        out.add(os.path.splitext(os.path.basename(q.decode("utf-8", "replace")))[0])
            return out

        for mm in m.INHERIT.finditer(sc):
            stems |= of_expr(mm.group(1))
        for mm in m.INCLUDE.finditer(sc):
            stems.add(os.path.splitext(os.path.basename(mm.group(2).decode("utf-8", "replace")))[0])
        for mm in m.INCLUDE_MACRO.finditer(sc):
            stems |= of_expr(mm.group(1))
        for st in stems:
            if st:
                mention[st].add(f)
    cache = {}
    for file, h in rows[slug]:
        stem = os.path.splitext(os.path.basename(file))[0]
        # every descendant: a file that inherits it, a file that inherits that, ...
        inh, seen_f, frontier = [], {file}, [file]
        for _ in range(8):
            nxt = []
            for g in frontier:
                gs = os.path.splitext(os.path.basename(g))[0]
                for x in mention.get(gs, ()):
                    if x not in seen_f:
                        seen_f.add(x)
                        nxt.append(x)
                        inh.append(x)
            frontier = nxt
            if not frontier:
                break
        if not inh:
            print(f"LEAF\t{slug}\t{file}\t{h}")
            continue
        definer = None
        for x in inh:
            if x not in cache:
                cache[x] = L.all_defs(x)[0]
            if h.encode() in cache[x]:
                definer = x
                break
        if definer:
            print(f"ALIVE\t{slug}\t{file}\t{h}\t{definer}")
        else:
            print(f"BASE\t{slug}\t{file}\t{h}\t{len(inh)}")
    sys.stdout.flush()
