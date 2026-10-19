#!/usr/bin/env python3
"""scripts/lpc_scan_missing_skills.py [SLUG...] [--summary] [--files DIR] [--donors]

Report-only (KB 06 section 7.256).  For every lib with a skill system (twenty or more skill files in kungfu/skill, daemon/skill,
skills, std/skill, adm/skill, system/skill or a domain's skill dir) the objects that `set_skill("name", n)` with a name the lib has
no skill file for: `MISS slug name files first-file`.  `set_skill()` raised on such a name until scripts/lpc_guard_set_skill.py
made it skip the skill, so each of these objects is one the lib never loaded.

--summary   only the per-lib totals
--files DIR write DIR/SLUG.list, one object per line (no .lpc), for scripts/lpc_listcheck.sh or the catch() loader
--donors    name, for each missing skill, the lib with the most skill names in common that carries a file of it
            (`DONOR slug name donor overlap`): the candidates for restoring the skill itself"""
import collections
import os
import re
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from lpc_fix_void_return import code_mask  # noqa: E402

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SKIP = re.compile(r"/(u|w|wiz|wizard|wizards|open|players|backup|backups|old|bak|log|data|doc|docs|example|examples)/|[-_.](bak|old)/")
SKDIR = re.compile(r"/(?:kungfu/skill|daemon/skill|skills|std/skill|adm/skill|system/skill|inherit/skill|d/skills|feature/skills?)/([^/]+?)\.lpc$")
DOM = re.compile(r"/d/[^/]+/(?:skill|mjskill|skills)/([^/]+?)\.lpc$")
SETS = re.compile(rb'\bset_skill\s*\(\s*"([A-Za-z0-9_-]+)"')


def tracked():
    by = collections.defaultdict(list)
    for f in subprocess.run(["git", "ls-files", "-z", "--", "libs"], cwd=REPO, capture_output=True).stdout.split(b"\0"):
        try:
            p = f.decode("utf-8")
        except UnicodeDecodeError:
            continue
        parts = p.split("/work/", 1)
        if len(parts) == 2 and p.endswith((".lpc", ".h")) and "longyunmeng_binary" not in p:
            by[p.split("/")[1]].append("/" + parts[1])
    return by


def main():
    args = sys.argv[1:]
    summary = "--summary" in args
    donors = "--donors" in args
    outdir = None
    if "--files" in args:
        i = args.index("--files")
        outdir = args[i + 1]
        del args[i:i + 2]
    only = [a for a in args if not a.startswith("--")]
    by = tracked()
    have = {}
    for slug, files in by.items():
        ns = set()
        for rel in files:
            m = SKDIR.match(rel) or DOM.match(rel)
            if m:
                ns.add(m.group(1))
        if len(ns) >= 20:
            have[slug] = ns
    tot_pairs = tot_files = 0
    for slug in sorted(only or have):
        if slug not in have:
            continue
        names = have[slug]
        miss = collections.defaultdict(list)
        objs = set()
        for rel in by[slug]:
            if not rel.endswith(".lpc") or SKIP.search(rel):
                continue
            try:
                b = open(f"{REPO}/libs/{slug}/work{rel}", "rb").read()
            except OSError:
                continue
            if b"set_skill" not in b:
                continue
            mask = None
            for m in SETS.finditer(b):
                n = m.group(1).decode()
                if n in names:
                    continue
                if mask is None:
                    mask = code_mask(b, heredoc=True)
                if not mask[m.start()]:
                    continue
                if rel not in miss[n]:
                    miss[n].append(rel)
                objs.add(rel)
        if not miss:
            continue
        tot_pairs += len(miss)
        tot_files += len(objs)
        print(f"LIB   {slug}: {len(objs)} object(s), {len(miss)} missing skill name(s)")
        if outdir:
            os.makedirs(outdir, exist_ok=True)
            open(f"{outdir}/{slug}.list", "w", encoding="utf-8").write("\n".join(sorted(o[1:-4] for o in objs)) + "\n")
        if summary:
            continue
        for n, rels in sorted(miss.items(), key=lambda kv: -len(kv[1])):
            print(f"MISS  {slug} {n} {len(rels)} {rels[0]}")
            if donors:
                best = None
                for d, ns in have.items():
                    if d != slug and n in ns:
                        ov = len(names & ns) / max(1, len(names))
                        if best is None or ov > best[0]:
                            best = (ov, d)
                if best:
                    print(f"DONOR {slug} {n} {best[1]} {best[0]:.2f}")
    print(f"{tot_pairs} (lib, skill) pair(s), {tot_files} object(s)")


if __name__ == "__main__":
    main()
