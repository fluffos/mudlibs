#!/usr/bin/env python3
"""scripts/lpc_fix_action_level.py SLUG... [--all-files] [--fallback] [--apply]

A skill file copied from another skill and renamed, whose query_action() still walks the move table by the
*original's* level (KB 06 section 7.243): `level = me->query_skill("tiesha-shenzhang", 1);` in tiesha-zhangfa.lpc,
`quanzhen-jianfa` in quanzhen-jian.lpc, `sougu` in sougu-yingzhua.lpc.  A player who has only this skill has level 0
there, no move matches (`level > action[i - 1]["lvl"]`), and `a_action["dodge"] = ...` indexes 0 on every attack
(`Illegal type of index` / `Value being indexed is zero`); one who has both gets the other skill's moves.

In the query_action() of each kungfu/skill / daemon/skill file, the assignment `VAR = me->query_skill("OTHER", 1)`
becomes the file's own skill name when VAR drives the table (the body has `action[i - 1]["lvl"]` or `NewRandom(`)
and no level assignment reads the own name already.  By default only skills the lib uses are touched (the name
appears in some other file outside wizard and backup dirs: an NPC's set_skill, a master's teach list, a book);
`--all-files` takes every hit.

`--fallback` instead fixes the walk's other gap: `for (i = sizeof(action); i > 0; i--) if (level > action[i -
1]["lvl"]) { a_action = ...; break; }` assigns nothing when the player's level is at or below the lowest "lvl" of the
table (hc's tiesha/tiezhang tables start at 100, xiongba-tianxia at 250), and the next `a_action["dodge"] = ...`
indexes 0 on every attack until the skill passes that level.  It inserts `if (!a_action) a_action = action[0];` after
the loop (braced `if` body only; other shapes are listed) when the table's lowest "lvl" is above 0 and no such
fallback is there.  Code only.  Binary-safe.  Without --apply the plan is printed."""
import os
import re
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from lpc_fix_void_return import code_mask  # noqa: E402

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
QA = re.compile(rb"mapping\s+query_action\s*\([^)]*\)\s*\{")
LV = re.compile(rb'(\w+)(\s*=\s*(?:\(\s*int\s*\)\s*)?(?:\(\s*)?me\s*->\s*query_skill\s*\(\s*")([\w-]+)("\s*,\s*1\s*\))')
TABLE = re.compile(rb'action\s*\[\s*i\s*-\s*1\s*\]\s*\[\s*"lvl"\s*\]|NewRandom')
SKIP = ("/u/", "/w/", "/backup/", "/old/", "/bak/")
WALK = re.compile(rb'if\s*\(\s*\w+\s*>\s*action\s*\[\s*i\s*-\s*1\s*\]\s*\[\s*"lvl"\s*\]\s*\)\s*(\{)?\s*(\w+)\s*=\s*action\s*\[')


def add_fallback(b):
    """(new bytes, 1) with the fallback after the table walk, (b, 0) when not needed, (b, -1) for a hand edit."""
    if b"query_action" not in b:
        return b, 0
    m = find_qa(b)
    if not m:
        return b, 0
    end = b.find(b"\n}", m.end())
    end = len(b) if end < 0 else end
    w = WALK.search(b, m.end(), end)
    if not w:
        return b, 0
    var = w.group(2)
    if re.search(rb"if\s*\(\s*!\s*(?:mapp\s*\(\s*)?" + re.escape(var) + rb"\b", b[m.end():end]):
        return b, 0
    i = b.find(b"mapping *action")
    i = b.find(b"mapping*action") if i < 0 else i
    mask0 = code_mask(b)
    lv = [int(x.group(1)) for x in re.finditer(rb'"lvl"\s*:\s*(\d+)', b[i:b.find(b"});", i)])
          if mask0[i + x.start() - 1]] if i >= 0 else []   # commented-out moves do not count (the key is a string: test the byte before it)
    if not lv or min(lv) == 0:
        return b, 0
    if not w.group(1):
        return b, -1
    mask = code_mask(b)
    k, depth = w.start(1) + 1, 1
    while k < end and depth:
        if mask[k]:
            if b[k:k + 1] == b"{":
                depth += 1
            elif b[k:k + 1] == b"}":
                depth -= 1
        k += 1
    if depth:
        return b, -1
    eol = b.find(b"\n", k)
    eol = end if eol < 0 else eol
    ls = b.rfind(b"\n", 0, w.start()) + 1
    fs = b.rfind(b"\n", 0, b.rfind(b"for", m.end(), w.start())) + 1   # indent of the `for`
    indent = re.match(rb"[ \t]*", b[fs:]).group(0)
    nl = b"\r\n" if b[eol - 1:eol] == b"\r" else b"\n"
    pos = eol - 1 if nl == b"\r\n" else eol
    ins = nl + indent + b"if (!" + var + b") " + var + b" = action[0];   // below the lowest \"lvl\" of the table"
    return b[:pos] + ins + b[pos:], 1


def used(work, name, own):
    out = subprocess.run(["grep", "-rlF", "--include=*.lpc", f'"{name}"', work], capture_output=True, text=True).stdout
    for p in out.split("\n"):
        if not p or p == own or f"/skill/{name}/" in p or any(x in p[len(work):] for x in SKIP):
            continue
        return True
    return False


def find_qa(b, mask=None):
    """The query_action() definition that is code (an older copy may sit in a comment above it)."""
    mask = mask or code_mask(b)
    for m in QA.finditer(b):
        if mask[m.start()]:
            return m
    return None


def fix(b, name):
    if b"query_action" not in b:
        return b, 0
    m = find_qa(b)
    if not m:
        return b, 0
    end = b.find(b"\n}", m.end())
    end = len(b) if end < 0 else end
    body = b[m.end():end]
    if not TABLE.search(body):
        return b, 0
    lvs = list(LV.finditer(body))
    if not lvs or any(x.group(3) == name for x in lvs):
        return b, 0
    mask = code_mask(b)
    out, last, n = [], 0, 0
    for x in lvs:
        if not mask[m.end() + x.start(1)]:   # the assignment itself is code (the name is a string)
            continue
        s = m.end() + x.start(3)
        out.append(b[last:s])
        out.append(name)
        last = m.end() + x.end(3)
        n += 1
    out.append(b[last:])
    return b"".join(out), n


def main():
    args = sys.argv[1:]
    apply = "--apply" in args
    every = "--all-files" in args
    fallback = "--fallback" in args
    tot = 0
    for slug in [a for a in args if not a.startswith("--")]:
        work = f"{REPO}/libs/{slug}/work"
        if os.path.exists(f"{work}/.git"):
            continue
        for d in ("kungfu/skill", "daemon/skill"):
            D = f"{work}/{d}"
            if not os.path.isdir(D):
                continue
            for f in sorted(os.listdir(D)):
                if not f.endswith(".lpc") or f.endswith(".bak.lpc"):
                    continue
                name = os.fsencode(f[:-4])
                p = f"{D}/{f}"
                b = open(p, "rb").read()
                if fallback:
                    out, n = add_fallback(b)
                    if n < 0:
                        print(f"HAND  {slug} /{d}/{f}")
                    elif n:
                        tot += n
                        print(f"FIX   {slug} /{d}/{f}  fallback")
                        if apply:
                            open(p, "wb").write(out)
                    continue
                out, n = fix(b, name)
                if not n:
                    continue
                if not every and not used(work, f[:-4], p):
                    continue
                tot += n
                print(f"FIX   {slug} /{d}/{f}  {n}")
                if apply:
                    open(p, "wb").write(out)
    print(f"{tot} assignment(s)" + ("" if apply else " (plan only; --apply writes)"))


if __name__ == "__main__":
    main()
