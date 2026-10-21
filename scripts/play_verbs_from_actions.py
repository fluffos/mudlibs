#!/usr/bin/env python3
"""scripts/play_verbs_from_actions.py SLUG [--min N] [--max N] > verbs.txt

The verbs of a lib whose commands are not files under cmds/<dir>/ (LPmud 3.x style: the player object and the rooms define them with
`add_action("fn", "verb")`, `add_verb`, `add_xverb`): every literal verb of an `add_action` / `add_verb` / `add_xverb` call in the lib's own sources, one per line,
for `play_sweep_lib.py SLUG --verbs-file`.  Verbs that appear in at least --min files (default 1) are listed, the --max (default 300) most common first-seen by file count.
Comments are blanked first.  Wizard homes and backup trees are left out."""
import argparse
import collections
import os
import re
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SKIPDIR = re.compile(r"(^|/)(u|wizards|players|realms|open|old|bak|backup|tmp|test|doc|log|www)/")
CALL = re.compile(r'\badd_(?:action|verb|xverb)\s*\(\s*(?:"[^"]*"|\w+|\(:[^:]*:\))\s*(?:,\s*"([^"]{1,24})")?')
VERB = re.compile(r"^[a-z][a-z'!?\-]{0,19}$")


def strip(t):
    t = re.sub(r"/\*.*?\*/", lambda m: re.sub(r"[^\n]", " ", m.group(0)), t, flags=re.S)
    return re.sub(r"//[^\n]*", "", t)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("slug")
    ap.add_argument("--min", type=int, default=1)
    ap.add_argument("--max", type=int, default=300)
    a = ap.parse_args()
    work = f"{REPO}/libs/{a.slug}/work"
    files = collections.defaultdict(set)
    for root, dirs, fs in os.walk(work):
        rel = os.path.relpath(root, work) + "/"
        if SKIPDIR.search(rel):
            dirs[:] = []
            continue
        for f in fs:
            if not f.endswith((".lpc", ".c")):
                continue
            try:
                t = strip(open(os.path.join(root, f), encoding="utf-8", errors="replace").read())
            except OSError:
                continue
            if "add_" not in t:
                continue
            for m in CALL.finditer(t):
                v = m.group(1)
                if v and VERB.match(v):
                    files[v].add(os.path.join(rel, f))
    ranked = sorted(files, key=lambda v: (-len(files[v]), v))
    out = [v for v in ranked if len(files[v]) >= a.min][:a.max]
    sys.stdout.write("\n".join(out) + ("\n" if out else ""))
    print(f"{len(out)} verbs of {len(files)}", file=sys.stderr)


if __name__ == "__main__":
    main()
