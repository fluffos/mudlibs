#!/usr/bin/env python3
"""scripts/lpc_fix_wizard_area_exits.py [--apply] [--list] SLUG...|--all

Rewrite dead wizard-tree paths to in-tree areas when the destination
`.lpc` exists:

  /u/f/faceoff/<stem>     → /open/world1/faceoff/bird/<stem>
  /u/r/rence/<rest>       → /open/prayer/<rest>
  /u/onskyer/niulang/<r>  → /d/niulang/<r>
  /u/skinys/yihua/<r>     → /d/yihua/<r>

Exit lines whose destination is still missing are deleted (line-start
only). Skip `//` comments. Binary mode. Dry run unless `--apply`."""
from __future__ import annotations

import os
import re
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SKIP = re.compile(
    r"^/(u|w|wiz|wizard|wizards)/|"
    r"/(players|backup|backups|bak|old|test|tests|"
    r"tmp|data|log|realms|doc|docs|example|examples|orphaned-dir)/|"
    r"[-_.](bak|old)|class_bak|orphaned-dir|/海洋2002/"
)

# (prefix regex with named rest, dest relative under work without .lpc)
RULES = [
    (
        re.compile(r'/u/f/faceoff/(?P<rest>[^"\']+)'),
        lambda rest: f"open/world1/faceoff/bird/{_stem(rest)}",
    ),
    (
        re.compile(r'/u/r/rence/(?P<rest>[^"\']+)'),
        lambda rest: f"open/prayer/{_stem(rest)}",
    ),
    (
        re.compile(r'/u/onskyer/niulang/(?P<rest>[^"\']+)'),
        lambda rest: f"d/niulang/{_stem(rest)}",
    ),
    (
        re.compile(r'/u/skinys/yihua/(?P<rest>[^"\']+)'),
        lambda rest: f"d/yihua/{_stem(rest)}",
    ),
]

DROP = re.compile(
    r'(?m)^(?P<pre>[ \t]*)(?P<q>["\'])(?P<dir>[a-z]+)(?P=q)\s*:\s*(?P=q)'
    r'(?P<path>/u/(?:f/faceoff|r/rence|onskyer/niulang|skinys/yihua)/[^"\']+)(?P=q)\s*,?[ \t]*\r?\n'
)


def _stem(rest: str) -> str:
    base = rest
    for suf in (".lpc", ".c"):
        if base.endswith(suf):
            base = base[: -len(suf)]
            break
    return base


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


def resolve_path(path: str, work: str) -> str | None:
    for rx, dest_fn in RULES:
        m = rx.fullmatch(path)
        if not m:
            continue
        rel = dest_fn(m.group("rest"))
        if os.path.isfile(os.path.join(work, rel + ".lpc")):
            return "/" + rel
    return None


def edits_for(t: str, work: str):
    out = []
    for rx, dest_fn in RULES:
        for m in rx.finditer(t):
            line_start = t.rfind("\n", 0, m.start()) + 1
            line = t[line_start : t.find("\n", m.end())]
            if line.lstrip().startswith("//"):
                continue
            rel = dest_fn(m.group("rest"))
            if not os.path.isfile(os.path.join(work, rel + ".lpc")):
                continue
            new = "/" + rel
            old = m.group(0)
            if old == new:
                continue
            out.append((m.start(), m.end(), new, old))
    for m in DROP.finditer(t):
        if resolve_path(m.group("path"), work):
            continue
        before = t[max(0, m.start() - 500) : m.start()]
        if "exits" not in before:
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
            if not any(
                b in raw
                for b in (
                    b"/u/f/faceoff/",
                    b"/u/r/rence/",
                    b"/u/onskyer/niulang/",
                    b"/u/skinys/yihua/",
                )
            ):
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
