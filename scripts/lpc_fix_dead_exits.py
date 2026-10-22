#!/usr/bin/env python3
"""scripts/lpc_fix_dead_exits.py [SLUG...] [--apply] [--summary]

A room exit that leads nowhere, repaired by the room on the other side (KB 06 section 7.257).  `"east": __DIR__"zhulin2"`
where the lib has no `zhulin2` (typo, renamed file, a numbered sibling that was never shipped) strands the player: the
move fails and the rest of the map behind it is cut off.  Maps are symmetrical: if the room on the other end exists and
its opposite exit (`"west"`) points back to this room, that room is where the exit was meant to go.

For every live room (wizard, backup and example dirs aside) the exits it names as `"dir" : __DIR__"name"`,
`"dir" : "/abs/path"` or `add_exit("dir", "path")` are resolved; one whose target file is not in the lib is dead.  The
candidates are the rooms of the lib whose exit in the OPPOSITE direction (north/south, east/west, northeast/southwest,
northwest/southeast, up/down, and the one-letter forms) resolves to this room.  With exactly one candidate that is not the
room itself, the exit is repaired: `__DIR__"name"` when the candidate sits in the same directory, else its absolute path.
Several candidates, none, or a target that is a macro or an expression are left (printed as SKIP with the reason).
A candidate must lie in the room's own game area or the target's (the first two path components, an area renamed by one letter
counts), never in /clone, /obj, /adm ...; two rooms whose dead exits would be repaired to point at each other are left.  A
target that loads anyway is not dead: libs whose virtual server makes rooms from names with no file (VIRTUAL: the Eastern Stories
trio's `_name` rooms and coordinate rooms, pd's `22,30,0`) are skipped; for any other lib, load the old targets in a fresh tree
before trusting the plan.
Binary-safe: only the literal changes; the file's line endings stay.  Without --apply the plan is printed
(FIX lines: `room dir old -> new`); --summary prints per-lib totals only.  Idempotent: a repaired exit is no longer dead."""
import collections
import os
import re
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from lpc_fix_void_return import code_mask  # noqa: E402

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
GENERATED = {"wllz3", "longyunmeng_binary"}   # trees rebuilt from a decompile plus a patch: edit the patch, not work/
VIRTUAL = {"es1", "es1_win", "esI", "pd"}   # a virtual server answers for rooms that have no file: es1's `_westgate`/`8,5.east`, pd's `22,30,0`
SKIP = re.compile(r"/(u|w|wiz|wizard|wizards|open|players|backup|backups|old|bak|log|data|doc|docs|example|examples|test|tmp|attic)/|[-_.](bak|old|orphaned-driver-src)/|\.(bak|BAK|old|orig)(\.lpc)?$")
OPP = {"north": "south", "south": "north", "east": "west", "west": "east", "northeast": "southwest", "southwest": "northeast",
       "northwest": "southeast", "southeast": "northwest", "up": "down", "down": "up",
       "n": "s", "s": "n", "e": "w", "w": "e", "ne": "sw", "sw": "ne", "nw": "se", "se": "nw", "u": "d", "d": "u",
       "northup": "southdown", "southdown": "northup", "southup": "northdown", "northdown": "southup",
       "eastup": "westdown", "westdown": "eastup", "westup": "eastdown", "eastdown": "westup"}
LONG = {"n": "north", "s": "south", "e": "east", "w": "west", "ne": "northeast", "sw": "southwest", "nw": "northwest", "se": "southeast", "u": "up", "d": "down"}
DIRS = "|".join(sorted(OPP, key=len, reverse=True))
# a literal object path without the leading slash (`"north" : "d/city/kedian"`) is root-relative in this driver (KB 06 7.73 addendum): group 5, only under a directory name a lib keeps its rooms in
REL = rb"(?:d|domains|world|areas|realms|rooms|quest|maps|lib|std|u|players)/[^\"\n]+"
PAIR = re.compile(rb'"(' + DIRS.encode() + rb')"\s*:\s*(?:(__DIR__)\s*"([^"\n]+)"|"(/[^"\n]+)"|"(' + REL + rb')")\s*(?=[,)\]}])')
ADDX = re.compile(rb'add_exit\s*\(\s*"(' + DIRS.encode() + rb')"\s*,\s*(?:(__DIR__)\s*"([^"\n]+)"|"(/[^"\n]+)"|"(' + REL + rb')")')


_STARTS = {}


def string_starts(b):
    """positions of the opening quote of every double-quoted string literal that sits in code (not in a comment, a character constant or a here-doc)"""
    key = (id(b), len(b))
    r = _STARTS.get(key)
    if r is not None:
        return r
    r = set()
    i, n = 0, len(b)
    while i < n:
        c = b[i:i + 1]
        if c == b"@":
            h = re.compile(rb"@@?([A-Za-z_]\w*)[ \t]*\r?\n").match(b, i)
            if h:
                end = re.compile(rb"(?m)^" + re.escape(h.group(1)) + rb"(?![A-Za-z0-9_])").search(b, h.end())
                i = end.end() if end else n
                continue
        if b[i:i + 2] == b"//":
            j = b.find(b"\n", i)
            i = n if j < 0 else j
            continue
        if b[i:i + 2] == b"/*":
            j = b.find(b"*/", i + 2)
            i = n if j < 0 else j + 2
            continue
        if c == b"'" and (b[i + 2:i + 3] == b"'" or b[i + 1:i + 2] == b"\\"):
            j = i + 1
            while j < n and b[j:j + 1] != c and b[j:j + 1] != b"\n":
                j += 2 if b[j:j + 1] == b"\\" else 1
            i = j + 1
            continue
        if c == b'"':
            r.add(i)
            j = i + 1
            while j < n and b[j:j + 1] != c:
                j += 2 if b[j:j + 1] == b"\\" else 1
            i = j + 1
            continue
        i += 1
    if len(_STARTS) > 64:
        _STARTS.clear()
    _STARTS[key] = r
    return r


def in_code(mask, b, pos):
    """True when the text at pos is code.  A match that starts at an opening quote is code exactly when that quote opens a string literal
    of the code (the old test looked at the character before it, which is the `/` of a `/* sizeof() == 4 */` comment after `([` and so
    dropped the first exit of every room written that way)."""
    if mask[pos]:
        return True
    return b[pos:pos + 1] == b'"' and pos in string_starts(b)


def area(path):
    return "/".join(path.split("/")[:3])


def plausible(y, r, tgt, dirs):
    """the repair stays in the room's own area or the target's: not a link to another game area that was never shipped, and
    never a /clone or /obj object that happens to carry an exit"""
    if y.startswith(("/clone/", "/obj/", "/include/", "/adm/", "/cmds/", "/std/", "/inherit/")):
        return False
    ay, ar, at = area(y), area(r), area(tgt)
    if ay == ar:
        return at in dirs or at == ar
    if ay == at or lev1(ay.rsplit("/", 1)[-1], at.rsplit("/", 1)[-1]) and ay.rsplit("/", 1)[0] == at.rsplit("/", 1)[0]:
        return True
    return False


def lev1(a, b):
    la, lb = len(a), len(b)
    if abs(la - lb) > 1 or a == b:
        return False
    if la == lb:
        d = [i for i in range(la) if a[i] != b[i]]
        return len(d) == 1 or (len(d) == 2 and d[1] == d[0] + 1 and a[d[0]] == b[d[1]] and a[d[1]] == b[d[0]])
    if la > lb:
        a, b = b, a
    return any(a[:i] == b[:i] and a[i:] == b[i + 1:] for i in range(len(b)))


def tracked():
    by = collections.defaultdict(set)
    for f in subprocess.run(["git", "ls-files", "-z", "--", "libs"], cwd=REPO, capture_output=True).stdout.split(b"\0"):
        try:
            p = f.decode("utf-8")
        except UnicodeDecodeError:
            continue
        parts = p.split("/work/", 1)
        if len(parts) == 2 and "longyunmeng_binary" not in p and p.endswith(".lpc"):
            by[p.split("/")[1]].add("/" + parts[1])
    return by


def stem(path):
    return path[:-4] if path.endswith(".lpc") else path[:-2] if path.endswith(".c") else path


def parse_exits(slug, rel):
    """-> [(dir, resolved stem, start, end, kind, text)] for the literal exits of one room file"""
    try:
        b = open(f"{REPO}/libs/{slug}/work{rel}", "rb").read()
    except OSError:
        return [], b""
    if b"exit" not in b:
        return [], b
    mask = code_mask(b, heredoc=True)
    fdir = rel.rsplit("/", 1)[0]
    out = []
    for rx in (PAIR, ADDX):
        for m in rx.finditer(b):
            if not in_code(mask, b, m.start()):
                continue
            d = LONG.get(m.group(1).decode(), m.group(1).decode())
            if m.group(2):    # __DIR__"name"
                name = m.group(3).decode("utf-8", "replace")
                full = os.path.normpath(fdir + "/" + (name[1:] if name.startswith("/") else name))
                s, e = m.start(2), m.end(3) + 1   # from __DIR__ to the closing quote
                out.append((d, stem(full), s, e, "dir", name))
            elif m.group(4):
                path = m.group(4).decode("utf-8", "replace")
                s, e = m.start(4) - 1, m.end(4) + 1
                out.append((d, stem(os.path.normpath(path)), s, e, "abs", path))
            else:             # root-relative literal: the fix writes the absolute path
                path = m.group(5).decode("utf-8", "replace")
                s, e = m.start(5) - 1, m.end(5) + 1
                out.append((d, stem(os.path.normpath("/" + path)), s, e, "abs", path))
    return out, b


def main():
    args = sys.argv[1:]
    apply = "--apply" in args
    summary = "--summary" in args
    only = [a for a in args if not a.startswith("--")]
    by = tracked()
    tot = tot_skip = nfiles = 0
    for slug in sorted(only or by):
        if slug not in by or slug in GENERATED or slug in VIRTUAL or os.path.exists(f"{REPO}/libs/{slug}/work/.git"):
            continue
        files = by[slug]
        stems = {stem(f) for f in files}
        rooms = {}      # stem -> exits
        raw = {}
        for rel in files:
            if SKIP.search(rel):
                continue
            ex, b = parse_exits(slug, rel)
            if ex:
                rooms[stem(rel)] = ex
                raw[stem(rel)] = (rel, b)
        stems_dirs = {area(x) for x in stems}       # the game areas (first two path components) the lib has
        incoming = collections.defaultdict(list)     # (target stem, dir) -> [rooms that have an exit `dir` to the target]
        for r, ex in rooms.items():
            for d, tgt, s, e, kind, text in ex:
                incoming[(tgt, d)].append(r)
        fixes = collections.defaultdict(list)
        for r, ex in rooms.items():
            for d, tgt, s, e, kind, text in ex:
                if tgt in stems:
                    continue
                cands = sorted({y for y in incoming.get((r, OPP[d]), []) if y != r and y in stems and plausible(y, r, tgt, stems_dirs)})
                if len(cands) != 1:
                    tot_skip += 1
                    if not summary and len(cands) > 1:
                        print(f"SKIP  {slug} {r} {d} {text}: {len(cands)} rooms point back ({', '.join(cands[:3])})")
                    continue
                y = cands[0]
                same = y.rsplit("/", 1)[0] == r.rsplit("/", 1)[0]
                new = '__DIR__"' + y.rsplit("/", 1)[1] + '"' if (kind == "dir" and same) else '"' + y + '"'
                fixes[r].append((s, e, new, d, text))
                tot += 1
        chosen = {}
        for r, fl in fixes.items():
            for s_, e_, new_, d_, text_ in fl:
                chosen[(r, d_)] = new_
        def dest(r_, d_, new_):
            return None
        cyc = set()
        for (r, d), new_ in chosen.items():
            m_ = re.match(r'(?:__DIR__)?"([^"]+)"', new_)
            if not m_:
                continue
            y = m_.group(1) if m_.group(1).startswith("/") else r.rsplit("/", 1)[0] + "/" + m_.group(1)
            if chosen.get((y, d)) is not None:
                z = re.match(r'(?:__DIR__)?"([^"]+)"', chosen[(y, d)])
                zz = z.group(1) if z.group(1).startswith("/") else y.rsplit("/", 1)[0] + "/" + z.group(1)
                if zz == r:
                    cyc.add((r, d))
        if cyc:
            fixes = {r: [f for f in fl if (r, f[3]) not in cyc] for r, fl in fixes.items()}
            fixes = {r: fl for r, fl in fixes.items() if fl}
            tot -= len(cyc)
        for r, fl in sorted(fixes.items()):
            rel, b = raw[r]
            nfiles += 1
            if not summary:
                for s, e, new, d, text in fl:
                    print(f"FIX   {slug} {rel} {d}: {text} -> {new}")
            if apply:
                out, last = [], 0
                for s, e, new, d, text in sorted(fl):
                    out.append(b[last:s])
                    out.append(new.encode("utf-8"))
                    last = e
                out.append(b[last:])
                open(f"{REPO}/libs/{slug}/work{rel}", "wb").write(b"".join(out))
        if fixes:
            print(f"LIB   {slug}: {sum(len(v) for v in fixes.values())} dead exit(s) in {len(fixes)} room(s) repaired by the room on the other side")
    print(f"{tot} exit(s) in {nfiles} file(s); {tot_skip} dead exit(s) left (none or several rooms point back)" + ("" if apply else " (plan only; --apply writes)"))


if __name__ == "__main__":
    main()
