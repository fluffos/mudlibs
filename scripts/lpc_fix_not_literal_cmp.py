#!/usr/bin/env python3
"""scripts/lpc_fix_not_literal_cmp.py [--apply] [SLUG...]

`if (me->query("class") == !"taoist")`, `if (me->query("gender") == !"女性")`, `if (ob->query("family/family_name")==!"方寸山三星洞")`:
a `!` in front of a string literal on the right of `==`.  `!"taoist"` is the integer 0, so the test is "the value is 0" and the
branch the author wrote for everyone else never runs: Long Nü's hint about the secret door is never given, the Gumu gatekeepers send every
disciple away, `yunu-xinfa` lets men learn a skill whose refusal text says "you are not a woman", Puti's "get out, you are not of my
cave" only fires for someone with no family at all.  Every one of these means `!= "literal"`: the message under the test says so.  The
code was written that way in the xkx lineage (245 sites in 35 libs, 23 distinct lines: `kungfu/class/gumu/long.lpc`, `sunpopo.lpc`,
`kungfu/skill/yunu-xinfa.lpc`, `d/gumu/...`, `d/lingtai/npc/puti.lpc`, `open/badman/ride/deserter.lpc`) and compiles in every driver.

Only code is touched (comments, strings and character constants are masked) and only `==` followed by `!` and a string literal's opening
quote: `== !"x"`, `==!"x"`, `==! "x"` become `!= "x"`, `!="x"`, `!= "x"`.  `== !func()` (a boolean comparison somebody may have meant) and
every other shape stay.  Wizard, backup and test directories are skipped like the other mechanical fixers do; submodule work trees and the
generated trees are not read.  Binary-safe (bytes in, bytes out, the line endings stay).

Without --apply the plan is printed (`FIX<TAB>slug<TAB>/path<TAB>n`) with the totals on stderr.  Idempotent: the next run finds nothing."""
import os
import re
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from lpc_fix_void_return import code_mask  # noqa: E402

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SKIP = re.compile(r"/(u|w|wiz|wizard|wizards|open|players|backup|backups|old|bak|log|data|doc|docs|example|examples|test|tests|tmp|attic)/|[-_.](bak|old)/|\.(bak|BAK|old|orig)(\.lpc)?$")
GENERATED = {"wllz3", "longyunmeng_binary"}
PAT = re.compile(rb'(?<![=!<>])==(\s*)!(\s*)"')


def tracked(slugs):
    out = subprocess.run(["git", "ls-files", "-s", "-z", "--", "libs"], cwd=REPO, capture_output=True).stdout.split(b"\0")
    gitlinks = set()
    by = {}
    for ent in out:
        if not ent:
            continue
        meta, _, path = ent.partition(b"\t")
        try:
            p = path.decode("utf-8")
        except UnicodeDecodeError:
            continue
        parts = p.split("/")
        if len(parts) < 3 or parts[0] != "libs":
            continue
        slug = parts[1]
        if meta.split()[0] == b"160000":
            gitlinks.add(slug)
            continue
        if len(parts) > 3 and parts[2] == "work" and p.endswith((".lpc", ".h")):
            by.setdefault(slug, []).append(p)
    return {s: f for s, f in by.items() if s not in gitlinks and s not in GENERATED and (not slugs or s in slugs)}


def fix(b):
    found = list(PAT.finditer(b))
    if not found:
        return None, 0
    mask = code_mask(b)               # the byte loop only for the few files with a candidate
    edits = []
    for m in found:
        if not mask[m.start()]:
            continue
        edits.append((m.start(), m.end(), b"!=" + (m.group(1) or m.group(2)) + b'"'))
    if not edits:
        return None, 0
    out = bytearray(b)
    for s, e, rep in reversed(edits):
        out[s:e] = rep
    return bytes(out), len(edits)


def main():
    a = sys.argv[1:]
    apply_ = "--apply" in a
    slugs = {x for x in a if not x.startswith("--")}
    total = files = 0
    for slug, paths in sorted(tracked(slugs).items()):
        for p in paths:
            rel = "/" + p.split("/work/", 1)[1]
            if SKIP.search(rel):
                continue
            try:
                b = open(os.path.join(REPO, p), "rb").read()
            except OSError:
                continue
            if b"==" not in b or b"!" not in b:
                continue
            new, n = fix(b)
            if not n:
                continue
            print(f"FIX\t{slug}\t{rel}\t{n}")
            total += n
            files += 1
            if apply_:
                with open(os.path.join(REPO, p), "wb") as fh:
                    fh.write(new)
    print(f"{total} comparison(s) in {files} file(s) {'fixed' if apply_ else 'fixable'}", file=sys.stderr)


if __name__ == "__main__":
    main()
