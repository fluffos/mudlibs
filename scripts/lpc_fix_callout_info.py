#!/usr/bin/env python3
"""scripts/lpc_fix_callout_info.py [--apply] [SLUG...]

`info = call_out_info(); ... info[i][3]`: the entries this driver answers are `({ object, function, delay })`, three elements (src/packages/core/call_out.cc
`get_all_call_outs`: `allocate_empty_array(3)`, the call_out's arguments are not reported although docs/efun/system/call_out_info.md says four), so the fourth
element the MudOS wizard command `callouts` prints (`sprintf("%-30O %-20s %5d %O\\n", info[i][0], info[i][1], info[i][2], info[i][3])`) is `Array index out of
bounds` on the first line of the list: the command never printed anything.  A guard `if (sizeof(info[i]) == 4)` in front of the output line
(dtsl, hy, mhxy, sjsh, ... : 75 `callouts.lpc`) hides every row of a list of three-element entries: it becomes `>= 3`.  `V[I][3]` becomes `(sizeof(V[I]) > 3 ? V[I][3] : 0)`, which prints the argument a
driver that reports it would show and a 0 otherwise.

V is a name assigned from `call_out_info()` (also through `filter_array(call_out_info(), ...)`) in the same file, or the variable of
`foreach (X in call_out_info())`; only code is touched; `pingd.lpc` / `pingtcp.lpc` (the intermud ping daemons: the same slip inside a loop whose bound is
`sizeof(loop)`, which never runs), the Praxis `sage_room.lpc` (it re-schedules the call_outs whose argument is not `ob`: without the argument nothing can be kept) and
the TMI-2 `aclock.lpc` (`[3][0]` is an index into the argument) are left; LDMud libs and wizard directories are skipped.  Binary-safe, idempotent.  Without --apply the plan is printed
(`FIX<TAB>slug<TAB>/path<TAB>n`)."""
import os
import re
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from lpc_fix_void_return import code_mask  # noqa: E402

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
TOP = re.compile(r"^/(u|w|wiz|wizard|wizards|open|players|realms|home)/")
ANY = re.compile(r"/(backup|backups|old|bak|log|data|example|examples|test|tests|tmp|attic|last_modify)/|[-_.](bak|old)/|\.(bak|BAK|old|orig)(\.lpc)?$")
GENERATED = {"wllz3", "longyunmeng_binary"}
LDMUD = {"aoh", "morgengrauen", "nirvlp312", "simud", "sticklib", "skylib", "sluggymud", "swmud", "spacemud", "wilderness", "immaster", "amylaarmini", "mundoscuro",
         "ageofelements", "acme", "scratch", "paomud", "sagenwelt", "xxsj"}
LEFT = ("pingd.lpc", "pingtcp.lpc", "sage_room.lpc", "aclock.lpc")
ASSIGN = re.compile(rb"\b([A-Za-z_]\w*)\s*=\s*(?:filter_array\s*\(\s*)?call_out_info\s*\(")
FOREACH = re.compile(rb"foreach\s*\(\s*(?:mixed|mixed\s*\*|array)?\s*([A-Za-z_]\w*)\s+in\s+call_out_info\s*\(")


def tracked(slugs):
    out = subprocess.run(["git", "ls-files", "-s", "-z", "--", "libs"], cwd=REPO, capture_output=True).stdout.split(b"\0")
    gitlinks, by = set(), {}
    for ent in out:
        if not ent:
            continue
        meta, _, path = ent.partition(b"\t")
        try:
            p = path.decode("utf-8")
        except UnicodeDecodeError:
            continue
        parts = p.split("/")
        if len(parts) < 3 or parts[0] != "libs":
            continue
        slug = parts[1]
        if meta.split()[0] == b"160000":
            gitlinks.add(slug)
            continue
        if len(parts) > 3 and parts[2] == "work" and p.endswith((".lpc", ".h")):
            by.setdefault(slug, []).append(p)
    return {s: f for s, f in by.items() if s not in gitlinks and s not in GENERATED and s not in LDMUD and (not slugs or s in slugs)}


def fix(b):
    mask = code_mask(b)
    names = {m.group(1) for m in ASSIGN.finditer(b) if mask[m.start()]}
    each = {m.group(1) for m in FOREACH.finditer(b) if mask[m.start()]}
    if not names and not each:
        return None, 0
    edits = []
    for v in names:
        rx = re.compile(rb"(?<![\w.>])" + re.escape(v) + rb"(\[[^\[\]\n]+\])\[3\]")
        for m in rx.finditer(b):
            if not mask[m.start()]:
                continue
            pre = b[max(0, m.start() - 40):m.start()]
            if re.search(rb"sizeof\s*\(\s*$", pre) or re.search(rb">\s*3\s*\?\s*$", pre):
                continue                                  # already guarded
            idx = m.group(1)
            edits.append((m.start(), m.end(), b"(sizeof(" + v + idx + b") > 3 ? " + v + idx + b"[3] : 0)"))
    for v in each:
        rx = re.compile(rb"(?<![\w.>])" + re.escape(v) + rb"\[3\]")
        for m in rx.finditer(b):
            if not mask[m.start()]:
                continue
            pre = b[max(0, m.start() - 40):m.start()]
            if re.search(rb">\s*3\s*\?\s*$", pre):
                continue
            edits.append((m.start(), m.end(), b"(sizeof(" + v + b") > 3 ? " + v + b"[3] : 0)"))
    # `if (sizeof(info[i]) == 4)` in front of the output line: the entries have three elements here, so the guard hides every row
    for v in names:
        rx = re.compile(rb"(sizeof\s*\(\s*" + re.escape(v) + rb"\[[^\[\]\n]+\]\s*\)\s*)==(\s*)4\b")
        for m in rx.finditer(b):
            if mask[m.start()]:
                edits.append((m.start(), m.end(), m.group(1) + b">=" + m.group(2) + b"3"))
    if not edits:
        return None, 0
    edits.sort()
    keep, last = [], -1
    for s, e, r in edits:
        if s >= last:
            keep.append((s, e, r))
            last = e
    out = bytearray(b)
    for s, e, r in reversed(keep):
        out[s:e] = r
    return bytes(out), len(keep)


def main():
    a = sys.argv[1:]
    apply_ = "--apply" in a
    slugs = {x for x in a if not x.startswith("--")}
    total = files = 0
    for slug, paths in sorted(tracked(slugs).items()):
        for p in paths:
            rel = "/" + p.split("/work/", 1)[1]
            if TOP.search(rel) or ANY.search(rel) or rel.endswith(LEFT):
                continue
            try:
                b = open(os.path.join(REPO, p), "rb").read()
            except OSError:
                continue
            if b"call_out_info" not in b or b"[3]" not in b:
                continue
            new, n = fix(b)
            if not n:
                continue
            print(f"FIX\t{slug}\t{rel}\t{n}")
            total += n
            files += 1
            if apply_:
                with open(os.path.join(REPO, p), "wb") as fh:
                    fh.write(new)
    print(f"{total} access(es) in {files} file(s) {'fixed' if apply_ else 'fixable'}", file=sys.stderr)


if __name__ == "__main__":
    main()
