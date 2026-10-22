#!/usr/bin/env python3
"""scripts/lpc_keep_log_dirs.py [--apply] [--list] [SLUG...]

`log_file("quest/reward", msg)` / `write_file("/log/dlog/money", msg)` into a `log/` subdirectory that a fresh clone and the site's zip do not have raises
`*Wrong permissions for opening file /log/dlog/money for append. "No such file or directory"` and cuts the calling function short (KB 03 section 4.3, KB 06 section 7.358):
the sefun `log_file()` of the xkx / Eastern Story lineages is `write_file(LOG_DIR + file, text)` with no `mkdir`.  `gen_keep_dirs.py` records only the directories a
LOCAL boot happened to create; a log directory that no local boot wrote into is not in `scripts/wasm_keep_dirs.txt`, so the site (which unpacks the zip without `log/` and
recreates only the listed directories) lacks it: a periodic random event (sanjieshenhua's `ran_moneyd`), a quest reward, a job log, a gift log each die on their first write.

This tool finds those directories statically: every `log_file("a/b/x")`, `write_file(...)`, `save_object`, `fopen`, `write_bytes` whose first arguments
are string literals and `#define`d path macros (`LOG_DIR + "quest/" + id`, `"/log/dlog/money"`, `DLOG "money"`) and which lead into `log/<dir>` where `<dir>` is neither tracked in the
lib nor already listed for it.  Writers under wizard homes, backups, tests and examples do not count; a `rm()` target does not either.  `--list` prints every directory with its
first writer files; `--logfile-ok=a,b` leaves the `log_file()` rows of those libs out (a lib whose own `log_file()` makes the directory it writes into: measure it with
`lpcc_eval.py SLUG --at /adm/daemons/zzeval.lpc --code 'log_file("zzdirprobe/x", "t\n"); debug_message(sprintf("%d", file_size("/log/zzdirprobe")));'`, -2 afterwards means it does); `--apply` adds the missing directories to the lib's block of `scripts/wasm_keep_dirs.txt` (what `gen_keep_dirs.py --merge` does: existing lines are kept,
the block is sorted by path).  Without SLUG every lib with a `work/` and a `config.fluffos` is scanned (about 12 minutes).  A directory the lib's own code creates before it writes
is listed too: an empty directory costs nothing.  `--root=data` (any top directory, default `log`) runs the same scan for the directories under it: read the writer of a `data/` directory first, it is a
save the lib expects, and `missing_write_dirs.py` (first 15 directories per lib, `rm` targets included) is the noisier cousin."""
import os
import re
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(REPO / "scripts"))
import gen_keep_dirs  # noqa: E402  (tracked_dirs() knows gitlink libs, set_block() merges a block)

WRITE = re.compile(r'\b(save_object|write_file|write_bytes|fopen|log_file)\s*\(\s*((?:"[^"\n]*"|[A-Z][A-Z_0-9]*)(?:\s*\+\s*(?:"[^"\n]*"|[A-Z][A-Z_0-9]*|[a-z_]\w*(?:\([^()\n]*\))?))*)')
DEF = re.compile(r'^#\s*define\s+([A-Z][A-Z_0-9]*)\s+"([^"\n]*)"', re.M)
TOPSKIP = {"w", "u", "wiz", "wizard", "wizards", "players", "realms", "open", "home", "homes", "test", "tests", "tmp", "old", "bak", "backup", "backups",
           "attic", "doc", "docs", "example", "examples", "log", "www", "temp", "binaries", "raw", "data", "d_old"}
MIDSKIP = re.compile(r"(^|/)(old|bak|backup|backups|attic|test|tests|tmp|orphaned-dir|u|w)(/|$)|[-_.](bak|old)(/|$)")
WIZSEG = {"w", "d", "u", "players", "open", "realms", "home", "homes", "wizards"}
GOODSEG = re.compile(r"^[A-Za-z0-9_.+-]+$")


def keep_rows():
    out = {}
    if gen_keep_dirs.OUT.is_file():
        for line in gen_keep_dirs.OUT.read_text(encoding="utf-8", errors="replace").split("\n"):
            if "\t" in line:
                s, d = line.split("\t", 1)
                out.setdefault(s, set()).add(d)
    return out


def prefix_of(arg, defs, is_log_file):
    """the literal prefix of the path argument: string literals and macro names up to the first variable"""
    toks = re.split(r"\s*\+\s*", arg)
    parts = []
    for t in toks:
        if t.startswith('"'):
            parts.append(t.strip('"'))
        elif re.fullmatch(r"[A-Z][A-Z_0-9]*", t) and t in defs:
            parts.append(defs[t])
        else:
            break
    p = "".join(parts)
    if is_log_file:
        p = "log/" + p.lstrip("/")
    return p.lstrip("/")


def scan(slug, tracked, kept, root="log", skip_log_file=False):
    work = REPO / "libs" / slug / "work"
    files, defs = [], {}
    for dp, dn, fn in os.walk(work):
        rel = Path(dp).relative_to(work).as_posix()
        top = rel.split("/")[0]
        if top in TOPSKIP and rel != ".":
            dn[:] = []
            continue
        if rel != "." and MIDSKIP.search(rel):
            dn[:] = []
            continue
        for f in fn:
            if f.endswith((".lpc", ".h", ".c")):
                files.append(Path(dp) / f)
    texts = {}
    for f in files:
        try:
            t = f.read_text(encoding="utf-8", errors="replace")
        except OSError:
            continue
        texts[f] = t
        if f.suffix == ".h":
            for m in DEF.finditer(t):
                defs.setdefault(m.group(1), m.group(2))
    found = {}
    for f, t in texts.items():
        rel = f.relative_to(work).as_posix()
        for m in WRITE.finditer(t):
            fn, arg = m.group(1), m.group(2)
            if skip_log_file and fn == "log_file":
                continue
            p = prefix_of(arg, defs, fn == "log_file")
            if "%" in p or "/" not in p:
                continue
            d = p.rsplit("/", 1)[0]
            segs = d.split("/")
            if segs[0] != root or len(segs) < 2 or not all(GOODSEG.match(s) for s in segs):
                continue
            if segs[1] in WIZSEG:
                continue                      # `log/w/ceres`, `log/d/admin/log`: one wizard's or one domain's own path, not a lib directory
            found.setdefault(d, set()).add(f"{fn}@{rel}")
    return {d: sorted(v) for d, v in found.items() if d not in tracked and d not in kept}


def main():
    argv = sys.argv[1:]
    apply, listing = "--apply" in argv, "--list" in argv
    root, logfile_ok = "log", set()
    for a in argv:
        if a.startswith("--root="):
            root = a.split("=", 1)[1]
        if a.startswith("--logfile-ok="):
            logfile_ok = set(a.split("=", 1)[1].split(","))
    names = [a for a in argv if not a.startswith("--")]
    if not names:
        names = [p.name for p in sorted((REPO / "libs").iterdir()) if (p / "work").is_dir() and (p / "config.fluffos").is_file()]
    keep = keep_rows()
    lines = gen_keep_dirs.read_lines()
    nlib = ndir = 0
    for slug in names:
        tracked = gen_keep_dirs.tracked_dirs(slug)
        kept = keep.get(slug, set())
        # a directory below one that is listed already exists once the parent does not matter: ensureDir() is mkdir -p
        rows = scan(slug, tracked, kept, root, slug in logfile_ok)
        # drop a row whose child is also a row: the child's mkdir -p creates it
        leaves = {d: v for d, v in rows.items() if not any(o != d and o.startswith(d + "/") for o in rows)}
        if not leaves:
            continue
        nlib += 1
        ndir += len(leaves)
        print(f"{slug}: {len(leaves)} director{'y' if len(leaves) == 1 else 'ies'}: " + ", ".join(sorted(leaves)))
        if listing:
            for d, v in sorted(leaves.items()):
                print(f"    {d}   <- {v[0]}" + (f" (+{len(v) - 1})" if len(v) > 1 else ""))
        if apply:
            lines = gen_keep_dirs.set_block(lines, slug, sorted(leaves), True)
    print(f"{ndir} director(ies) in {nlib} lib(s)" + ("" if apply else " (plan only; --apply writes scripts/wasm_keep_dirs.txt)"), file=sys.stderr)
    if apply:
        gen_keep_dirs.OUT.write_text("\n".join(lines) + "\n", encoding="utf-8", errors="surrogateescape")


if __name__ == "__main__":
    main()
