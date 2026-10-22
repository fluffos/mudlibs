#!/usr/bin/env python3
"""scripts/lpc_fix_dead_add_action.py [--apply] [--pairs FILE [--trust]] [--libs a,b] [--hits FILE] [--twins] [SLUG...]

Takes out the `add_action("handler", "verb")` statements whose handler nobody defines (KB 06 section 7.349).  The driver answers a verb bound to a function it
cannot find with `*Function for verb 'drop' not found.` and does not try the verb's other handlers: a player who carries one Guiyuan pill (26 libs) cannot
`drop` anything, a cart in the room (`do_get`, `do_put`) takes `get` and `put` from everyone, a shopkeeper that registers `do_list` / `do_buy` for a vendor
base that has other names takes `list` and `buy`.

The finding is the static resolver's (`lpc_scan_callout_targets.py --kinds=add_action`: the file, its headers, its inherits and the objects derived from it
define no such function; the inherits all resolve).  A statement is removed only when it is safe by shape: the whole `add_action(...);` sits on its own
line(s) (a trailing comment is kept out of the way), nothing before it on the line and nothing but a comment after the `;`, and the previous code line does not
end a braceless `if (..)` / `else` / `for` / `while` header or an unfinished expression (those are printed as MANUAL).  Statements for a handler that a TWIN lib's copy of the same file defines
or that has a NEAR name in the object (a rename: `get` for `do_get`) are printed as TWIN / NEAR and left alone: read them, the handler is usually a stub that
would take the verb away from everybody.  --pairs FILE (`slug<TAB>file<TAB>handler` lines, e.g. the MISSING rows of `lpc_verify_handlers.py`) restricts the
work to confirmed pairs.  --hits FILE takes the candidates from the HIT add_action rows of a `lpc_scan_callout_targets.py` run instead of rescanning every
file; --twins also looks in the other libs for the same file (TWIN: the file itself defines the handler there, BASE: an ancestor does; slow: it loads every lib that has the file).  --trust (with --pairs) takes the pairs as proven (no resolver, no NEAR / TWIN look: for the final run over pairs that `lpc_verify_handlers.py` answered MISSING).  Binary mode, the file's own line ending, idempotent; gitlink libs are never touched.  Dry run by default."""
import collections
import difflib
import os
import re
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import lpc_scan_callout_targets as sc  # noqa: E402
from lpc_fix_void_return import code_mask  # noqa: E402


def statements(b, handler):
    """(start, end) byte spans of the `add_action("handler" ..);` statements that sit in code"""
    mask = code_mask(b, heredoc=True)
    pat = re.compile(rb'add_action\(\s*"' + re.escape(handler) + rb'"')
    for m in pat.finditer(b):
        if not mask[m.start()]:
            continue
        depth, i, n = 0, m.start() + len(b"add_action"), len(b)
        while i < n:
            c = b[i:i + 1]
            if not mask[i]:
                i += 1
                continue
            if c == b"(":
                depth += 1
            elif c == b")":
                depth -= 1
                if depth == 0:
                    break
            i += 1
        j = i + 1
        while j < n and b[j:j + 1] in b" \t":
            j += 1
        if b[j:j + 1] != b";":
            yield m.start(), None
            continue
        yield m.start(), j + 1


def prev_code(b, mask, ls):
    """(text, start) of the code line above offset ls (comments and blanks skipped), (b"", 0) when there is none"""
    p = ls
    while p > 0:
        pe = p - 1
        ps = b.rfind(b"\n", 0, pe) + 1
        sg = b"".join(bytes([c]) if mask[ps + k] else b" " for k, c in enumerate(b[ps:pe])).strip()
        p = ps
        if sg:
            return sg, ps
    return b"", 0


def if_header(b, mask, ls):
    """start of the line above `ls` when it is a complete braceless `if (...)` header whose own predecessor ends a statement or opens a block, else None"""
    prev, hs = prev_code(b, mask, ls)
    if not re.match(rb"if\s*\(", prev) or not prev.endswith(b")") or prev.count(b"(") != prev.count(b")"):
        return None
    before, _ = prev_code(b, mask, hs)
    if before and not before.startswith(b"#") and before[-1:] not in b";{}:":
        return None
    return hs


def plan(b, handlers):
    """edits [(start, end, kind, handler)] for one file: kind REMOVE (whole line), CUT (statement out of a line), IFREMOVE (a braceless `if` header and its dead statement) or MANUAL"""
    out = []
    mask = code_mask(b, heredoc=True)
    for h in handlers:
        for s, e in statements(b, h.encode()):
            if e is None:
                out.append((s, s, "MANUAL", h))
                continue
            ls = b.rfind(b"\n", 0, s) + 1
            le = b.find(b"\n", e)
            le = len(b) if le < 0 else le
            rest = b[e:le].strip()
            code_after = bool(rest) and not (rest.startswith(b"//") or (rest.startswith(b"/*") and rest.endswith(b"*/")))
            if b[ls:s].strip() or code_after:
                # other code shares the line: cut just the statement (and the blanks after it) when the code before it ended a statement or opened a block
                seg = bytes(c if mask[ls + k] else 32 for k, c in enumerate(b[ls:s])).strip()
                if seg and seg[-1:] not in b";{}":
                    out.append((s, e, "MANUAL", h))
                    continue
                if not seg:
                    # the statement starts the line: the previous code line decides, like a whole-line statement
                    p = ls
                    prev = b""
                    while p > 0:
                        pe = p - 1
                        ps = b.rfind(b"\n", 0, pe) + 1
                        sg = b"".join(bytes([c]) if mask[ps + k] else b" " for k, c in enumerate(b[ps:pe])).strip()
                        p = ps
                        if sg:
                            prev = sg
                            break
                    if prev and not prev.startswith(b"#") and prev[-1:] not in b";{}:":
                        out.append((s, e, "MANUAL", h))
                        continue
                e2, s2 = e, s
                while e2 < len(b) and b[e2:e2 + 1] in b" \t":
                    e2 += 1
                if seg and not rest:                       # the statement ended the line: take the blanks before it too
                    while s2 > ls and b[s2 - 1:s2] in b" \t":
                        s2 -= 1
                out.append((s2, e2, "CUT", h))
                continue
            # previous code line
            p = ls
            prev = b""
            while p > 0:
                pe = p - 1
                ps = b.rfind(b"\n", 0, pe) + 1
                seg = b"".join(bytes([c]) if mask[ps + k] else b" " for k, c in enumerate(b[ps:pe])).strip()
                p = ps
                if seg:
                    prev = seg
                    break
            # safe only after a statement end, a block brace, a case label or a preprocessor line: a line that ends in `)`, `else`, `do`, `,` or an operator is a
            # braceless header or the middle of an expression
            if prev and not prev.startswith(b"#") and prev[-1:] not in b";{}:":
                hs = if_header(b, mask, ls)
                if hs is not None:
                    out.append((hs, min(le + 1, len(b)), "IFREMOVE", h))
                else:
                    out.append((s, e, "MANUAL", h))
                continue
            out.append((ls, min(le + 1, len(b)), "REMOVE", h))
    return out


class Reader:
    """the part of sc.Lib that main() needs for a trusted pair: the file's bytes (no header / macro scan of the whole lib)"""

    def __init__(self, slug):
        self.slug = slug

    def read(self, f):
        try:
            return open(f"{REPO}/libs/{self.slug}/work{f}", "rb").read()
        except OSError:
            return b""


def main():
    argv = sys.argv[1:]
    apply = "--apply" in argv
    want_twins = "--twins" in argv
    trust = "--trust" in argv
    pairs = None
    only_libs = None
    hits_file = None
    rest = []
    i = 0
    while i < len(argv):
        a = argv[i]
        if a == "--pairs":
            pairs = collections.defaultdict(set)
            for ln in open(argv[i + 1], encoding="utf-8"):
                f = ln.rstrip("\n").split("\t")
                if len(f) >= 3:
                    pairs[(f[0], f[1])].add(f[2])
            i += 2
            continue
        if a == "--libs":
            only_libs = argv[i + 1].split(",")
            i += 2
            continue
        if a == "--hits":
            hits_file = argv[i + 1]
            i += 2
            continue
        if not a.startswith("--"):
            rest.append(a)
        i += 1
    libs = only_libs or rest or sorted(d for d in os.listdir(f"{REPO}/libs") if os.path.isdir(f"{REPO}/libs/{d}/work"))
    out = subprocess.run(["git", "ls-files", "-z", "--", "libs"], cwd=REPO, capture_output=True).stdout
    byrel = collections.defaultdict(list)
    for p in out.split(b"\0"):
        mm = re.match(rb"libs/([^/]+)/work(/.*)", p) if p else None
        if mm and mm.group(2).endswith((b".lpc", b".c")):
            byrel[mm.group(2).decode("utf-8", "surrogateescape")].append(mm.group(1).decode())
    cache = {}

    def lib(s):
        if s not in cache:
            cache[s] = sc.Lib(s)
        return cache[s]

    n_rm = n_manual = n_twin = n_near = n_files = 0

    def candidates():
        if trust and pairs is not None:
            for (slug, f), hs in sorted(pairs.items()):
                if slug in sc.GITLINKS or (only_libs and slug not in only_libs):
                    continue
                yield slug, f, Reader(slug), set(), False, [h.encode() for h in sorted(hs)]
            return
        if hits_file:
            groups = collections.OrderedDict()
            for ln in open(hits_file, encoding="utf-8", errors="replace"):
                r = ln.rstrip("\n").split("\t")
                if r[0] == "HIT" and len(r) >= 6 and r[1] == "add_action" and (not only_libs or r[2] in only_libs):
                    groups.setdefault((r[2], r[3]), []).append(r[4].encode())
            for (slug, f), ts in groups.items():
                if slug in sc.GITLINKS:
                    continue
                L = lib(slug)
                defs, unsure, hidden = L.all_defs(f)
                yield slug, f, L, defs, unsure, [t for t in dict.fromkeys(ts)]
            return
        for slug in libs:
            if slug in sc.GITLINKS:
                continue
            L = lib(slug)
            for f in sorted(L.files):
                if not f.endswith((".lpc", ".c")) or sc.SKIP.search(f):
                    continue
                b = L.read(f)
                if b"add_action" not in b:
                    continue
                text = sc.strip_comments(b)
                names = collections.OrderedDict()
                for m in sc.KINDS["add_action"].finditer(text):
                    names.setdefault(m.group(1), 1)
                if not names:
                    continue
                defs, unsure, hidden = L.all_defs(f)
                yield slug, f, L, defs, unsure, list(names)

    for slug, f, L, defs, unsure, names in candidates():
        if True:
            b = L.read(f)
            missing = []
            for t in names:
                if not trust and (t in defs or L.derived_defines(f, t) or unsure):
                    continue
                if pairs is not None and t.decode() not in pairs.get((slug, f), set()):
                    continue
                missing.append(t)
            if not missing:
                continue
            todo = []
            for t in missing:
                twin = None
                base_note = ""
                for other in (byrel.get(f, []) if want_twins else []):
                    if other == slug or other in sc.GITLINKS:
                        continue
                    o = lib(other)
                    d = o.definer(f, t) or o.derived_defines(f, t)
                    if d:
                        twin = f"{other}:{d}" if d == f else None
                        if not twin:
                            base_note = f"{other}:{d}"
                        break
                td = t.decode()
                if trust:
                    todo.append(td)
                    continue
                pool = [d.decode("utf-8", "replace") for d in defs]
                near = difflib.get_close_matches(td, pool, n=2, cutoff=0.75)
                near += [d for d in pool if d != td and d not in near and (d == "do_" + td or td == "do_" + d or d.endswith("_" + td) or td.endswith("_" + d)) and len(min(d, td, key=len)) >= 3]
                if twin:
                    n_twin += 1
                    print(f"TWIN\t{slug}\t{f}\t{t.decode()}\t{twin}")
                elif near:
                    n_near += 1
                    print(f"NEAR\t{slug}\t{f}\t{t.decode()}\t{','.join(near)}")
                else:
                    if base_note:
                        print(f"BASE\t{slug}\t{f}\t{t.decode()}\t{base_note}")
                    todo.append(t.decode())
            if not todo:
                continue
            edits = plan(b, todo)
            if not edits:
                continue
            for s, e, kind, h in edits:
                line = b[:s].count(b"\n") + 1
                if kind == "MANUAL":
                    n_manual += 1
                    print(f"MANUAL\t{slug}\t{f}\t{h}\t{line}")
                else:
                    n_rm += 1
                    print(f"{kind}\t{slug}\t{f}\t{h}\t{line}")
            if apply:
                data = b
                for s, e, kind, h in sorted(edits, reverse=True):
                    if kind in ("REMOVE", "CUT", "IFREMOVE"):
                        data = data[:s] + data[e:]
                    if kind == "CUT":
                        ls2 = data.rfind(b"\n", 0, s) + 1
                        le2 = data.find(b"\n", s)
                        le2 = len(data) if le2 < 0 else le2
                        if not data[ls2:le2].strip():          # the line held nothing but dead statements
                            data = data[:ls2] + data[min(le2 + 1, len(data)):]
                if data != b:
                    open(f"{REPO}/libs/{slug}/work{f}", "wb").write(data)
                    n_files += 1
    print(f"{n_rm} statement(s) removed{'' if apply else ' (dry run)'} in {n_files} file(s); {n_manual} manual, {n_twin} twin, {n_near} near", file=sys.stderr)


if __name__ == "__main__":
    main()
