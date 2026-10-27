#!/usr/bin/env python3
"""scripts/lpc_fix_beyond_exits.py [--apply] [--list] SLUG...|--all

Rewrite dead exits `/u/beyond/<area>/<stem>` to in-tree `/d/<area>/<stem>`
when that room exists. Special-case: `murong` → `/d/mr/` (慕容 island was
filed under `mr` after leaving the wizard tree).

Only rewrites when the destination `.lpc` exists. Line-start-agnostic string
replace (paths appear in exits and in NPC load_object). Binary mode.
Dry run unless `--apply`."""
from __future__ import annotations

import os
import re
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SKIP = re.compile(  # `/open/` is playable world, not skipped
    
    r"^/(u|w|wiz|wizard|wizards)/|"
    r"/(players|backup|backups|bak|old|test|tests|"
    r"tmp|data|log|realms|doc|docs|example|examples|orphaned-dir)/|"
    r"[-_.](bak|old)|class_bak|orphaned-dir|/海洋2002/"
)

# /u/beyond/<area>/<rest> — rest may include subdirs; we only rewrite when
# the full relative path under /d/<mapped_area>/ exists as .lpc
BEYOND = re.compile(r'/u/beyond/(?P<area>[^/"\']+)/(?P<rest>[^"\']+)')

AREA_MAP = {
    "murong": "mr",
}


def tracked(slug):
    out = subprocess.run(
        ["git", "ls-files", "-z", "--", f"libs/{slug}/work"],
        cwd=REPO,
        capture_output=True,
    ).stdout
    pre = f"libs/{slug}/work"
    for p in out.split(b"\0"):
        if not p:
            continue
        s = p.decode("utf-8", "surrogateescape")
        rel = s[len(pre) :]
        if rel.endswith((".lpc", ".h")) and not SKIP.search(rel):
            yield rel


def resolve(area: str, rest: str, work: str) -> str | None:
    dest_area = AREA_MAP.get(area, area)
    # strip trailing .c/.lpc from rest for lookup
    base = rest
    for suf in (".lpc", ".c"):
        if base.endswith(suf):
            base = base[: -len(suf)]
            break
    cand = os.path.join(work, "d", dest_area, base + ".lpc")
    if os.path.isfile(cand):
        return f"/d/{dest_area}/{base}"
    return None


def edits_for(t: str, work: str):
    out = []
    for m in BEYOND.finditer(t):
        # skip commented lines
        line_start = t.rfind("\n", 0, m.start()) + 1
        line = t[line_start : t.find("\n", m.end())]
        if line.lstrip().startswith("//"):
            continue
        new = resolve(m.group("area"), m.group("rest"), work)
        if not new:
            continue
        old = m.group(0)
        if old == new:
            continue
        # keep original suffix if present (.c/.lpc) — dest is bare path
        out.append((m.start(), m.end(), new, old))
    out = sorted(out, key=lambda x: (x[0], x[1]))
    res, last = [], -1
    for a, b, new, old in out:
        if a < last:
            continue
        res.append((a, b, new, old))
        last = b
    return res


def apply_edits(t, ed):
    out, pos = [], 0
    for a, b, new, _ in ed:
        out.append(t[pos:a])
        out.append(new)
        pos = b
    out.append(t[pos:])
    return "".join(out)


def main():
    argv = sys.argv[1:]
    apply, listing = "--apply" in argv, "--list" in argv
    names = [a for a in argv if not a.startswith("--")]
    if "--all" in argv:
        names = sorted(
            p
            for p in os.listdir(os.path.join(REPO, "libs"))
            if os.path.isdir(os.path.join(REPO, "libs", p, "work"))
        )
    if not names:
        sys.exit(__doc__)
    total = 0
    for slug in names:
        root = os.path.join(REPO, "libs", slug, "work")
        nfile = nedit = 0
        for rel in tracked(slug):
            p = root + rel
            try:
                raw = open(p, "rb").read()
            except OSError:
                continue
            if b"/u/beyond/" not in raw:
                continue
            t = raw.decode("utf-8", "surrogateescape")
            ed = edits_for(t, root)
            if not ed:
                continue
            nfile += 1
            nedit += len(ed)
            if listing:
                for a, b, new, old in ed:
                    ln = t.count("\n", 0, a) + 1
                    print(f"{slug} {rel}:{ln}: {old!r} -> {new!r}")
            if apply:
                nt = apply_edits(t, ed)
                if nt != t:
                    open(p, "wb").write(nt.encode("utf-8", "surrogateescape"))
        total += nedit
        print(
            f"{slug}: {nedit} edit(s) in {nfile} file(s)" + ("" if apply else " (plan only)"),
            file=sys.stderr,
        )
    print(f"{total} edit(s)", file=sys.stderr)


if __name__ == "__main__":
    main()
