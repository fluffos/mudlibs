#!/usr/bin/env python3
"""scripts/lpc_fix_perform_weapon.py SLUG... [--apply]

A perform (kungfu/skill/<skill>/<move>.lpc, daemon/skill/...) that reads `weapon = me->query_temp("weapon");` and then
calls `weapon->name()` / `weapon->query("skill_type")` without ever testing it (KB 06 section 7.246).  The perform
command lets a player name the move explicitly (`perform stick.ban`) with nothing in hand, and the move then stops
with `Bad argument 1 to call_other()`, often after it has already taken its neili.  After the assignment statement
the fixer adds

    if (!objectp(weapon)) return notify_fail("你必须手持兵器才能使用这一招。\\n");

when no earlier line of the function tests the weapon (`objectp(...query_temp("weapon"))`, `!me->query_temp(
"weapon")`, `!weapon`, `weapon &&`, `weapon ?`) before its first `weapon->`.  Code only.  Binary-safe.  Without
--apply the plan is printed."""
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from lpc_fix_void_return import code_mask  # noqa: E402

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
PF = re.compile(rb"int\s+perform\s*\(\s*object\s+me\s*,\s*object\s+target\s*\)\s*\{")
MSG = "你必须手持兵器才能使用这一招。\\n".encode()


def fix(b):
    m = PF.search(b)
    if not m:
        return b, 0
    end = b.find(b"\n}", m.end())
    end = len(b) if end < 0 else end
    body = b[m.end():end]
    a = re.search(rb'([ \t]*)(\w+)\s*=\s*me\s*->\s*query_temp\s*\(\s*"weapon"\s*\)\s*;[ \t]*\r?\n', body)
    if not a:
        return b, 0
    mask = code_mask(b)
    if not mask[m.end() + a.start(2)]:
        return b, 0
    v = a.group(2)
    after = body[a.end():]
    first = re.search(re.escape(v) + rb"\s*->", after)
    if not first:
        return b, 0
    pre = after[:first.start()]
    if re.search(rb"(!\s*|objectp\s*\(\s*|\(\s*)" + re.escape(v) + rb"\b", pre) or \
            re.search(re.escape(v) + rb"\s*(&&|\?|\|\|)", pre):
        return b, 0
    head = body[:a.end() + first.start()]
    if re.search(rb'(objectp\s*\(\s*(\w+\s*=\s*)?|!\s*)me\s*->\s*query_temp\s*\(\s*"weapon"\s*\)', head):
        return b, 0
    if re.search(rb"objectp\s*\(\s*\w+\s*=\s*me\s*->\s*query_temp", head):
        return b, 0
    nl = b"\r\n" if body[a.end() - 2:a.end()] == b"\r\n" else b"\n"
    ins = a.group(1) + b"if (!objectp(" + v + b")) return notify_fail(\"" + MSG + b"\");" + nl
    pos = m.end() + a.end()
    return b[:pos] + ins + b[pos:], 1


def main():
    args = sys.argv[1:]
    apply = "--apply" in args
    tot = 0
    for slug in [a for a in args if not a.startswith("--")]:
        work = f"{REPO}/libs/{slug}/work"
        if os.path.exists(f"{work}/.git"):
            continue
        for d in ("kungfu/skill", "daemon/skill"):
            D = f"{work}/{d}"
            if not os.path.isdir(D):
                continue
            for sk in sorted(os.listdir(D)):
                sd = f"{D}/{sk}"
                if not os.path.isdir(sd):
                    continue
                for f in sorted(os.listdir(sd)):
                    p = f"{sd}/{f}"
                    if not f.endswith(".lpc") or not os.path.isfile(p):
                        continue
                    b = open(p, "rb").read()
                    if b"query_temp" not in b:
                        continue
                    out, n = fix(b)
                    if n:
                        tot += n
                        print(f"FIX   {slug} /{d}/{sk}/{f}")
                        if apply:
                            open(p, "wb").write(out)
    print(f"{tot} perform(s)" + ("" if apply else " (plan only; --apply writes)"))


if __name__ == "__main__":
    main()
