#!/usr/bin/env python3
"""scripts/lpc_scan_daemon_calls.py [--literal] SLUG...

Calls `MACRO->func(...)` where MACRO is a `#define` that names an existing daemon file of the lib and neither that file, the headers it includes nor anything it inherits defines
`func` (KB 06 section 7.354).  `call_other()` of a function that is not there answers 0 without a word, so the feature never works: `CHINESE_D->chinese_month(t)` in a ferry
that freezes in winter, `NATURE_D->room_event_fun()` in an NPC's `init()`, `SECURITY_D->wiz_level("(arch)")` in a `reboot` whose arch-only guard then compares 0 with 0.
A file copied between lineages calls its own daemon's API and the daemon of the lib it landed in has another one.

`--literal` adds the calls whose target is a string literal path instead of a macro: `"/cmds/std/look"->look_room(me, room)`, `"/adm/daemons/emoted.lpc"->do_emote(..)` (the rows' MACRO column
holds the literal with its quotes); the file is the path with `.lpc` / `.c` resolved by the lib.  The same filters apply (a function of the object's closure, an unresolved inherit: `unsure`).

Static resolver (no boot, `lpc_scan_callout_targets.Lib`: the lib's `#define`s, `#include`s, `inherit`s): per lib every tracked `.lpc` that names one of the daemon macros is read with
comments and strings masked.  Rows, one per (lib, macro, function): `DAPI<TAB>slug<TAB>MACRO<TAB>daemon file<TAB>func<TAB>nsites<TAB>first site (file:line)<TAB>sure|unsure|private`.
`unsure`: an inherit of the daemon could not be resolved (the function may live in the part nobody can see); `private`: the function exists but only as a `private` function of an
ancestor (a call_other fails there too, KB 06 section 7.322).  Read every row before porting (scripts/lpc_daemon_call_plan.py ranks them, scripts/lpc_port_function.py copies a
function): `start_death` of `DEATH_ROOM` and the intermud daemons' network functions are shared no-ops, not bugs.  Wizard / backup directories and the gitlink libs are skipped."""
import collections
import os
import re
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import lpc_scan_callout_targets as S  # noqa: E402
from lpc_fix_void_return import code_mask  # noqa: E402

CALL = re.compile(rb"(?<![A-Za-z0-9_\"])([A-Z][A-Z0-9_]*)\s*->\s*([A-Za-z_]\w*)\s*\(")
LITCALL = re.compile(rb'"(/[A-Za-z0-9_./-]+)"[ \t]*->[ \t]*([A-Za-z_]\w*)[ \t\r\n]*\(')


def scan(slug, literal=False):
    L = S.Lib(slug)
    daemons = {}
    for name, (expr, hf) in L.macros.items():
        v = L.literal(expr, os.path.dirname(hf) + "/")
        if v and v.startswith("/"):
            f = L.real(v)
            if f and f.endswith(".lpc"):
                daemons[name] = f
    sites = collections.defaultdict(list)
    for f in sorted(L.files):
        if not f.endswith(".lpc") or S.SKIP.search(f):
            continue
        b = L.read(f)
        has_macro = any(m.encode() in b for m in daemons)
        if not has_macro and not (literal and b'"/' in b and b"->" in b):
            continue
        mask = code_mask(b, heredoc=True)
        if has_macro:
            for m in CALL.finditer(b):
                name = m.group(1).decode()
                if name in daemons and mask[m.start(1)]:
                    sites[(name, m.group(2).decode())].append((f, b.count(b"\n", 0, m.start()) + 1))
        if literal:
            for m in LITCALL.finditer(b):
                if not mask[m.start(2)]:
                    continue
                path = m.group(1).decode("utf-8", "replace")
                target = L.real(path)
                if target and target.endswith(".lpc"):
                    key = ('"' + path + '"', m.group(2).decode())
                    daemons.setdefault(key[0], target)
                    sites[key].append((f, b.count(b"\n", 0, m.start()) + 1))
    cache = {}
    for (name, fn), lst in sorted(sites.items()):
        d = daemons[name]
        if d not in cache:
            try:
                cache[d] = L.all_defs(d)
            except Exception:
                cache[d] = (set(), True, set())
        vis, unsure, hidden = cache[d]
        fb = fn.encode()
        if fb in vis:
            continue
        kind = "private" if fb in hidden else ("unsure" if unsure else "sure")
        yield f"DAPI\t{slug}\t{name}\t{d}\t{fn}\t{len(lst)}\t{lst[0][0]}:{lst[0][1]}\t{kind}"


def main():
    literal = "--literal" in sys.argv
    slugs = [a for a in sys.argv[1:] if not a.startswith("--")]
    if not slugs:
        sys.exit(__doc__)
    for slug in slugs:
        if slug in S.GITLINKS or not os.path.isdir(os.path.join(REPO, "libs", slug, "work")):
            continue
        for row in scan(slug, literal):
            print(row, flush=True)


if __name__ == "__main__":
    main()
