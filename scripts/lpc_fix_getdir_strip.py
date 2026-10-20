#!/usr/bin/env python3
"""scripts/lpc_fix_getdir_strip.py [--apply] [SLUG...]

A suffix strip that kept the width of `.c` after the files were renamed `.lpc` (KB 06 section 7.238, 7.296):

  story_name = get_dir(STORY_DIR + "*.lpc");
  story_name = map_array(story_name, (: $1[0..<3] :));          "baguadao.lpc" -> "baguadao.l"

`[0..<3]` removes two characters (`.c`); `.lpc` is four, so the name keeps `.l` and everything built from it (`call_other(dir + name)`, `load_object()`, an index of the help daemon, the
object-data file of a player-made item) fails: nitan's story daemon `storyd` and the battlefield daemon, the boss daemon, `importer`, Dead Souls' `help` daemon, Discworld-like i3
service loaders, the ES event daemon `eventd`, Genesis' `wizard list` and its map linker.  `scripts/lpc_lpc_suffix_slice.py` only sees a strip next to a `== ".lpc"` test; this one follows
the `get_dir()` instead: a call whose text names `.lpc` (`"*.lpc"`, `"%s-*.lpc"`), and in the next 12 lines of code (comments skipped) a slice `[0..<3]` / `[..<3]` of `$1`, `($1)`, a name
or a name with indexes (`files[i][0][0..<3]`), which becomes `[0..<5]` / `[..<5]`.  The same for a name that was assigned a string ending in the literal `".lpc"` (`file_name = ITEM_DIR + "ring/" + id + ".lpc";`) within the 8 lines before the slice (nitan's `refsum`).  A slice of anything else (`explode(path, "/")[0..<2]`, `dir[0..strlen(dir)-2]`) is not touched.

Not read: wizard homes (top directory `/u/`, `/w/`, ...), backups, the LDMud ports (their files are `.c`), the generated trees, submodule libs.  Binary-safe, idempotent.  Without
--apply the plan is printed: `FIX<TAB>slug<TAB>/path<TAB>n` per file, `SITE<TAB>slug<TAB>/path:line<TAB>text` per slice, totals on stderr."""
import os
import re
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from lpc_fix_void_return import code_mask  # noqa: E402
import lpc_scan_cond_assign as sc  # noqa: E402

REPO = sc.REPO
GETDIR = re.compile(rb"get_dir\s*\(")
SLICE = re.compile(rb"(?P<op>\$1|\(\$1\)|[A-Za-z_]\w*(?:\s*\[[^\[\]]*\])*)\s*\[\s*(?P<lo>0)?\s*\.\.\s*<\s*3\s*\]")
WINDOW = 12
ASSIGN_LPC = re.compile(rb'([A-Za-z_]\w*)\s*=\s*[^;=]*\.lpc"\s*;')


def code_lines(b):
    """(offset, line bytes) of every line, with comments and strings blanked by the shared mask where they could hide a get_dir"""
    mask = code_mask(b)
    out, pos = [], 0
    for ln in b.split(b"\n"):
        out.append((pos, ln, mask[pos:pos + len(ln)]))
        pos += len(ln) + 1
    return out


def scan(b):
    """[(line index, start, end, replacement)] for the strips to widen"""
    lines = code_lines(b)
    hits = []
    for i, (off, ln, m) in enumerate(lines):
        if not GETDIR.search(ln) or b".lpc" not in ln:
            continue
        code_here = bytes(c for c, k in zip(ln, m) if k) if len(m) == len(ln) else ln
        if not GETDIR.search(code_here):
            continue                                    # inside a comment or a string
        for j in range(i, min(i + WINDOW + 1, len(lines))):
            offj, lnj, mj = lines[j]
            for s in SLICE.finditer(lnj):
                a = s.start("op")
                # the slice itself must be code, not text of a comment
                if len(mj) == len(lnj) and not mj[a]:
                    continue
                hits.append((j, offj + s.start(), offj + s.end(), s.group(0).replace(b"<3", b"<5").replace(b"< 3", b"<5")))
    for i, (off, ln, m) in enumerate(lines):
        ass = ASSIGN_LPC.search(ln)
        if not ass or (len(m) == len(ln) and not m[ass.start()]):
            continue
        var = ass.group(1)
        rx = re.compile(rb"(?<![\w$])(?P<op>" + re.escape(var) + rb")\s*\[\s*(?P<lo>0)?\s*\.\.\s*<\s*3\s*\]")
        for j in range(i + 1, min(i + 9, len(lines))):
            offj, lnj, mj = lines[j]
            for s in rx.finditer(lnj):
                if len(mj) == len(lnj) and not mj[s.start()]:
                    continue
                hits.append((j, offj + s.start(), offj + s.end(), s.group(0).replace(b"<3", b"<5").replace(b"< 3", b"<5")))
    seen, out = set(), []
    for h in hits:
        if h[1] not in seen:
            seen.add(h[1])
            out.append(h)
    return out


def main():
    a = sys.argv[1:]
    apply_ = "--apply" in a
    slugs = [x for x in a if not x.startswith("--")]
    sc_tracked = sc.tracked(slugs)
    n_files = n_sites = 0
    for slug, paths in sorted(sc_tracked.items()):
        if slug in sc.LDMUD or slug in sc.GENERATED:
            continue
        for full in paths:
            p = "/" + full.split("/work/", 1)[1]
            if sc.TOP.search(p) or sc.ANY.search(p):
                continue
            f = os.path.join(REPO, full)
            try:
                b = open(f, "rb").read()
            except OSError:
                continue
            if b".lpc" not in b or b"get_dir" not in b:
                continue
            hits = scan(b)
            if not hits:
                continue
            n_files += 1
            n_sites += len(hits)
            print(f"FIX\t{slug}\t{p}\t{len(hits)}")
            src_lines = b.split(b"\n")
            for j, s, e, rep in hits:
                line = b[:s].count(b"\n") + 1
                text = src_lines[line - 1].strip()[:140].decode("utf-8", "replace")
                print(f"SITE\t{slug}\t{p}:{line}\t{text}")
            if apply_:
                for j, s, e, rep in sorted(hits, key=lambda h: -h[1]):
                    b = b[:s] + rep + b[e:]
                open(f, "wb").write(b)
    print(f"{n_sites} strip(s) in {n_files} file(s)", file=sys.stderr)


if __name__ == "__main__":
    main()
