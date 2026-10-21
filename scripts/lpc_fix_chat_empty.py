#!/usr/bin/env python3
"""scripts/lpc_fix_chat_empty.py [--apply] [--libs SLUG ...] [--with-old]

The NPC chat dispatcher indexes an empty message list (KB 06 7.334).  Every xkx-lineage NPC base has

    if (arrayp(msg = query(is_fighting() ? "chat_msg_combat" : "chat_msg"))) {
      if (random(100) < chance) {
        rnd = random(sizeof(msg));
        if (stringp(msg[rnd])) ...

and 697 NPC files in 41 libs say `set("chat_msg", ({ }))` next to a positive `chat_chance`: with an empty array `random(0)` is 0 and `msg[0]` raises
`Array index out of bounds` on that percentage of the NPC's heart beats, for as long as the NPC is loaded (xkx100 `lulixian`, the fy family's `d/qianfo` NPCs,
the kxkj family's guards).  Fix: `sizeof(msg) &&` in front of the dice test, the form xuanjianlu, qhxajh and kxkj1's `new_npc` already carry:

    if (sizeof(msg) && random(100) < chance) {

Forms taken: `if (random(N) < chance) {` and `if( random(N) < chance ) {` whose next statement (blank lines allowed) is `rnd = random(sizeof(msg));`, and the
early-return form `if (random(N) > chance) return 0;` followed by that statement (dfgs2, shzs, zzhj: `if (!sizeof(msg) || random(N) > chance) return 0;`).  A site whose
enclosing condition (the 240 bytes before it) already tests `sizeof(msg)` is left alone.  Binary mode, the file's own line ending; backup / old directories (`old`, `bak`, `backup`) are skipped unless --with-old; the gitlink
libs (nt7, xkx100utf8, fy2005, nightmare3, residuum, sanguozhi, oxidus) are never touched.  Dry run by default: one line per file, the summary on stderr."""
import argparse
import os
import re
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
GITLINKS = {"nt7", "xkx100utf8", "fy2005", "nightmare3", "residuum", "sanguozhi", "oxidus"}
SKIPDIR = re.compile(r"(^|/)(old|bak|backup|attic|antiguo|oldcomandos|raw)(/|$)", re.I)
PAT = re.compile(r"(?P<head>if\s*\(\s*)(?P<test>random\(\s*\d+\s*\)\s*<\s*chance)(?P<tail>\s*\)\s*\{[ \t]*\r?\n\s*rnd\s*=\s*random\(\s*sizeof\(\s*msg\s*\)\s*\);)")
PAT2 = re.compile(r"(?P<head>if\s*\(\s*)(?P<test>random\(\s*\d+\s*\)\s*>\s*chance)(?P<tail>\s*\)\s*return\s+0;[ \t]*\r?\n\s*rnd\s*=\s*random\(\s*sizeof\(\s*msg\s*\)\s*\);)")


def fix(text):
    n = 0

    def guarded(m):
        return "sizeof(msg)" in text[max(0, m.start() - 240):m.start()]       # the enclosing `if (arrayp(msg = ...) && sizeof(msg))`

    def rep(m):
        nonlocal n
        if guarded(m):
            return m.group(0)
        n += 1
        return f"{m.group('head')}sizeof(msg) && {m.group('test')}{m.group('tail')}"

    def rep2(m):
        nonlocal n
        if guarded(m):
            return m.group(0)
        n += 1
        return f"{m.group('head')}!sizeof(msg) || {m.group('test')}{m.group('tail')}"

    return PAT2.sub(rep2, PAT.sub(rep, text)), n


def main():
    sys.stdout.reconfigure(errors="surrogateescape")
    ap = argparse.ArgumentParser()
    ap.add_argument("--apply", action="store_true")
    ap.add_argument("--libs", nargs="*", default=[])
    ap.add_argument("--with-old", action="store_true")
    a = ap.parse_args()
    libs = a.libs or sorted(d for d in os.listdir(f"{REPO}/libs") if os.path.isdir(f"{REPO}/libs/{d}/work"))
    files = total = 0
    per = {}
    for slug in libs:
        if slug in GITLINKS:
            continue
        work = f"{REPO}/libs/{slug}/work"
        for root, dirs, fs in os.walk(work):
            rel = os.path.relpath(root, work)
            if not a.with_old and rel != "." and SKIP_RE(rel):
                dirs[:] = []
                continue
            for f in fs:
                if not f.endswith((".lpc", ".c")):
                    continue
                p = os.path.join(root, f)
                try:
                    b = open(p, "rb").read()
                except OSError:
                    continue
                if b"rnd" not in b or b"sizeof" not in b:
                    continue
                t = b.decode("utf-8", errors="surrogateescape")
                new, n = fix(t)
                if not n:
                    continue
                files += 1
                total += n
                per[slug] = per.get(slug, 0) + 1
                print(f"{slug}\t{os.path.relpath(p, work)}\t{n}")
                if a.apply:
                    open(p, "wb").write(new.encode("utf-8", errors="surrogateescape"))
    print(f"{files} file(s), {total} site(s) in {len(per)} lib(s)" + ("" if a.apply else " (dry run)"), file=sys.stderr)


def SKIP_RE(rel):
    return bool(SKIPDIR.search(rel + "/"))


if __name__ == "__main__":
    main()
