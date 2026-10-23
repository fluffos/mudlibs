#!/usr/bin/env python3
"""scripts/lpc_fix_bigcat_gsword.py [--apply] [--list] SLUG...|--all

Rewrite dead paths `/u/b/bigcat/<rest>` to `/open/gsword/<rest>` when that
`.lpc` exists (gsword area was vendored under open/ after leaving the
wizard tree). Exit lines to missing stems (`ntree`/`wtree`/`etree`) are
deleted (line-start only). Skip `//` comments. Binary mode. Dry run
unless `--apply`."""
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
# Note: /open/ is NOT skipped — that is the destination tree.

BIGCAT = re.compile(r'/u/b/bigcat/(?P<rest>[^"\']+)')
# Line-start exit to a bigcat path with no /open/gsword/ counterpart.
DROP = re.compile(
    r'(?m)^(?P<pre>[ \t]*)(?P<q>["\'])(?P<dir>[a-z]+)(?P=q)\s*:\s*(?P=q)/u/b/bigcat/(?P<rest>[^"\']+)(?P=q)\s*,?[ \t]*\r?\n'
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


def resolve(rest: str, work: str) -> str | None:
    base = rest
    for suf in (".lpc", ".c"):
        if base.endswith(suf):
            base = base[: -len(suf)]
            break
    cand = os.path.join(work, "open", "gsword", base + ".lpc")
    if os.path.isfile(cand):
        return f"/open/gsword/{base}"
    return None


def edits_for(t: str, work: str):
    out = []
    for m in BIGCAT.finditer(t):
        line_start = t.rfind("\n", 0, m.start()) + 1
        line = t[line_start : t.find("\n", m.end())]
        if line.lstrip().startswith("//"):
            continue
        new = resolve(m.group("rest"), work)
        if not new:
            continue
        old = m.group(0)
        if old == new:
            continue
        out.append((m.start(), m.end(), new, old))
    for m in DROP.finditer(t):
        if resolve(m.group("rest"), work):
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
            if b"/u/b/bigcat/" not in raw:
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
