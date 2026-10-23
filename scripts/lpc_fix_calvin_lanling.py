#!/usr/bin/env python3
"""scripts/lpc_fix_calvin_lanling.py [--apply] [--list] SLUG...|--all

Rewrite dead exits `/u/calvin/兰陵/地区/<Chinese>` to the in-tree
`/d/lanling/<file>` rooms (same area, relocated out of the wizard dir).
Also drop the dead `/u/fly/doublesword/houdian` north exit of
`/d/huanggong/dadian` (census §10.15 leftover).

Only rewrites when the destination `.lpc` exists in that lib. Binary mode.
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

CALVIN = re.compile(r'/u/calvin/兰陵/地区/(?P<name>[^"\']+)')
# Line-start only: a match that begins at the quote inside `//"north"` would
# leave the `//` and glue it onto the next exit (xlqy_early / shenmo).
DADIAN = re.compile(
    r'(?m)^(?P<pre>[ \t]*)(?P<q>["\'])north(?P=q)\s*:\s*(?P=q)/u/fly/doublesword/houdian(?P=q)\s*,?[ \t]*\r?\n'
)

# ordered rules: (regex on Chinese name, template with \1 or None for fixed stem)
RULES = [
    (re.compile(r"^兰陵大街(\d+)$"), "lldj{0}"),
    (re.compile(r"^北郊(\d+)$"), "beijiao{0}"),
    (re.compile(r"^兰陵东郊(\d+)$"), ("lldjiao{0}", "lanlingdong{0}")),
    (re.compile(r"^兰陵西郊(\d+)$"), ("llxjiao{0}", "lanlingxi{0}")),
    (re.compile(r"^石头大街(\d+)$"), "stone{0}"),
    (re.compile(r"^皇陵大道(\d+)$"), "hldd{0}"),
    (re.compile(r"^雨花石路(\d+)$"), ("yuhua{0}", "yuhualu{0}")),
    (re.compile(r"^雨花石路$"), ("yuhua", "yuhualu")),
    (re.compile(r"^小路(\d+)$"), "xiaolu{0}"),
    (re.compile(r"^陵宫大门1$"), "lgdm1"),
    (re.compile(r"^陵宫大门$"), "lgdm"),
    (re.compile(r"^兰陵城心$"), ("llcx", "center")),
    (re.compile(r"^乾宫$"), "qiangong"),
    (re.compile(r"^坤宫$"), ("kungong", "kingkungong")),
    (re.compile(r"^紫冥宫$"), "ziming"),
    (re.compile(r"^慈安庙$"), "cianmiao"),
    (re.compile(r"^装备店$"), "wshop"),
    (re.compile(r"^药铺$"), "yaopu"),
    (re.compile(r"^星月酒楼$"), "xingyuejiulou"),
]


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


def resolve(name: str, lan_dir: str) -> str | None:
    for rx, tmpl in RULES:
        m = rx.match(name)
        if not m:
            continue
        candidates = tmpl if isinstance(tmpl, tuple) else (tmpl,)
        for c in candidates:
            if m.groups():
                stem = c.format(*m.groups())
            else:
                stem = c
            if os.path.isfile(os.path.join(lan_dir, stem + ".lpc")):
                return stem
    return None


def edits_for(t: str, lan_dir: str):
    out = []
    for m in CALVIN.finditer(t):
        name = m.group("name")
        stem = resolve(name, lan_dir)
        if not stem:
            continue
        new = f"/d/lanling/{stem}"
        old = m.group(0)
        if old == new:
            continue
        out.append((m.start(), m.end(), new, old))
    for m in DADIAN.finditer(t):
        out.append((m.start(), m.end(), "", m.group(0)))
    # dedupe
    out = sorted(out, key=lambda x: (x[0], x[1]))
    res, last = [], -1
    for a, b, new, old in out:
        if a < last or new == old:
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
        lan = os.path.join(root, "d", "lanling")
        nfile = nedit = 0
        for rel in tracked(slug):
            p = root + rel
            try:
                raw = open(p, "rb").read()
            except OSError:
                continue
            if b"/u/calvin/" not in raw and b"/u/fly/doublesword" not in raw:
                continue
            t = raw.decode("utf-8", "surrogateescape")
            ed = edits_for(t, lan)
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
