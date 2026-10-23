#!/usr/bin/env python3
"""scripts/lpc_fix_drop_dead_u_exits.py [--apply] [--list] SLUG...|--all

Delete active exit-mapping lines whose destination is a known-dead wizard
path with no in-tree `.lpc` (census leftovers):

  /u/g/gold/dock
  /u/xinyue/sunrise_room
  /u/mei/workroom
  /u/mei/tianying/elou

Line-start only (`(?m)^`) so `//"east": "/u/g/gold/dock"` comments are left
alone. Only rewrites when the destination file is missing. Binary mode.
Dry run unless `--apply`."""
from __future__ import annotations

import os
import re
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SKIP = re.compile(
    r"^/(u|w|wiz|wizard|wizards)/|"
    r"/(open|players|backup|backups|bak|old|test|tests|"
    r"tmp|data|log|realms|doc|docs|example|examples|orphaned-dir)/|"
    r"[-_.](bak|old)|class_bak|orphaned-dir|/海洋2002/"
)

DEAD = (
    "/u/g/gold/dock",
    "/u/xinyue/sunrise_room",
    "/u/mei/workroom",
    "/u/mei/tianying/elou",
)
ALT = "|".join(re.escape(p) for p in DEAD)
# Line-start exit entry; optional trailing comma; eats the newline.
LINE = re.compile(
    rf'(?m)^(?P<pre>[ \t]*)(?P<q>["\'])(?P<dir>[a-z]+)(?P=q)\s*:\s*(?P=q)(?P<path>{ALT})(?P=q)\s*,?[ \t]*\r?\n'
)


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


def dest_exists(work: str, path: str) -> bool:
    base = path
    for suf in (".lpc", ".c"):
        if base.endswith(suf):
            base = base[: -len(suf)]
            break
    for ext in (".lpc", ".c"):
        if os.path.isfile(os.path.join(work, base.lstrip("/") + ext)):
            return True
    return False


DOOR = re.compile(
    r'(?m)^(?P<pre>[ \t]*)create_door\s*\(\s*(?P<q>["\'])(?P<dir>[a-z]+)(?P=q)\s*,[^;]*\);\s*\r?\n'
)


def edits_for(t: str, work: str):
    out = []
    dirs = set()
    for m in LINE.finditer(t):
        path = m.group("path")
        if dest_exists(work, path):
            continue
        # require nearby exits=
        before = t[max(0, m.start() - 500) : m.start()]
        if "exits" not in before:
            continue
        dirs.add(m.group("dir"))
        out.append((m.start(), m.end(), "", m.group(0).rstrip("\r\n")))
    # Drop create_door("dir", ...) for those directions (mei_room1: north door
    # without north exit → *Room: create_door: attempt to create a door without exit.)
    for m in DOOR.finditer(t):
        if m.group("dir") not in dirs:
            continue
        out.append((m.start(), m.end(), "", m.group(0).rstrip("\r\n")))
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
            if not any(d.encode() in raw for d in DEAD):
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
                    print(f"{slug} {rel}:{ln}: DROP {old!r}")
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
