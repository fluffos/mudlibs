#!/usr/bin/env python3
"""scripts/lpc_fix_wabaod.py [--apply] [SLUG...]

The treasure-hunt daemon of the Eastern Story / xkx lineage, `adm/daemons/wabaod.lpc`, makes the clue of the skybook (天书) by blanking characters of a room description:

  begin = random((strlen(long) - 60) / 2) * 2;
  desc = long[begin..begin + 60];                          // 61 bytes: 30 GB characters
  begin = (sep * i + random(sep)) * 2;
  desc[begin..begin + 1] = "■";                            // one 2-byte character becomes another

It counts in bytes, two to a character.  The driver's strings are UTF-8 and a range counts characters: the window is 61 characters, and every `desc[b..b+1] = "■"` replaces TWO characters
by ONE, so the string shrinks while the offsets keep growing and a later replacement runs past the end: `push_lvalue_range: invalid ind2` in `insert_blank()` -> `init_xunbao()` -> `create()`
(wdxtym at boot, the rest at random, and again at every `init_xunbao` call_out).  Becomes the same puzzle in characters: a 30-character window, one character blanked per slot
(`begin = random(strlen(long) - 29)`, `long[begin..begin + 29]`, `begin = sep * i + random(sep)`, `desc[begin..begin] = "■"`, and the 30-character minimum in `get_long()`)
(KB 06 section 7.301).  A copy that already worked around it (hy3 collects the offsets and replaces from the highest, wxddym multiplies by 0) is not the shape and is listed, not changed.
Binary-safe, idempotent.

Without --apply the plan is printed: `FIX<TAB>slug<TAB>/path`, other copies `LIST<TAB>slug<TAB>/path`."""
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import lpc_scan_cond_assign as sc  # noqa: E402

REPO = sc.REPO
BLANK = "■".encode("utf-8")
EDITS = [
    (re.compile(rb"random\(\(strlen\(long\) - 60\) / 2\) \* 2"), b"random(strlen(long) - 29)"),
    (re.compile(rb"long\[begin\.\.begin \+ 60\]"), b"long[begin..begin + 29]"),
    (re.compile(rb"\(sep \* i \+ random\(sep\)\) \* 2;"), b"sep * i + random(sep);"),
    (re.compile(rb"\(30 - left \+ random\(left\)\) \* 2;"), b"30 - left + random(left);"),
    (re.compile(rb'desc\[begin\.\.begin \+ 1\] = "' + BLANK + rb'"'), b'desc[begin..begin] = "' + BLANK + b'"'),
    (re.compile(rb"strlen\(long\) < 60"), b"strlen(long) < 30"),
]


def main():
    a = sys.argv[1:]
    apply_ = "--apply" in a
    slugs = [x for x in a if not x.startswith("--")]
    n = 0
    for slug, paths in sorted(sc.tracked(slugs).items()):
        if slug in sc.LDMUD or slug in sc.GENERATED:
            continue
        for full in paths:
            p = "/" + full.split("/work/", 1)[1]
            if not p.endswith("/wabaod.lpc") or sc.TOP.search(p) or sc.ANY.search(p):
                continue
            f = os.path.join(REPO, full)
            b = open(f, "rb").read()
            if b"insert_blank" not in b:
                continue
            if all(not rx.search(b) for rx, _ in EDITS[:2]):
                continue                                # already in characters
            if not all(rx.search(b) for rx, _ in EDITS):
                print(f"LIST\t{slug}\t{p}")
                continue
            n += 1
            print(f"FIX\t{slug}\t{p}")
            if apply_:
                for rx, rep in EDITS:
                    b = rx.sub(lambda m, rep=rep: rep, b)
                open(f, "wb").write(b)
    print(f"{n} file(s)", file=sys.stderr)


if __name__ == "__main__":
    main()
