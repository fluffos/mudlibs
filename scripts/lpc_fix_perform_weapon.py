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
--apply the plan is printed.

Inline shape (2026-10-15): a perform that never stores the weapon but dereferences it in place --
`(me->query_temp("weapon"))->query("name")` in its message (yunv-jian `suxin`, liangyi-sword `yin`), or the refusal test
itself `if ((weapon = me->query_temp("weapon"))->query("skill_type") != "whip")` (feiyu-bian `chanrao`).  With no
earlier test of `me->query_temp("weapon")`, the same refusal goes in before the function-level statement that holds the
first such use (never between an `if` block and its `else`: those are listed as HAND)."""
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


USE = re.compile(rb'\(?\s*(\w+\s*=\s*)?me\s*->\s*query_temp\s*\(\s*"weapon"\s*\)\s*\)?\s*->')
TESTED = re.compile(rb'(objectp\s*\(\s*(\w+\s*=\s*)?|!\s*\(?\s*(\w+\s*=\s*)?)me\s*->\s*query_temp\s*\(\s*"weapon"\s*\)'
                    rb'|me\s*->\s*query_temp\s*\(\s*"weapon"\s*\)\s*\)?\s*(&&|\?|\|\|)'
                    rb'|if\s*\(\s*\(?\s*(\w+\s*=\s*)?me\s*->\s*query_temp\s*\(\s*"weapon"\s*\)\s*\)?\s*\)'
                    rb'|\w+\s*=\s*me\s*->\s*query_temp\s*\(\s*"weapon"\s*\)\s*;')


def fix_inline(b):
    """(new bytes, 1) or (b, 0) or (b, "HAND reason")."""
    m = PF.search(b)
    if not m:
        return b, 0
    mask = code_mask(b)
    # the function body, brace-matched on code
    depth, i = 1, m.end()
    while i < len(b) and depth:
        if mask[i]:
            if b[i:i + 1] == b"{":
                depth += 1
            elif b[i:i + 1] == b"}":
                depth -= 1
        i += 1
    end = i - 1
    u = next((x for x in USE.finditer(b, m.end(), end) if mask[x.start()]), None)
    if not u:
        return b, 0
    t = next((x for x in TESTED.finditer(b, m.end(), u.start()) if mask[x.start()]), None)
    if t:
        return b, 0
    # start of the function-level statement that holds the use
    depth, paren, start = 1, 0, m.end()
    for k in range(m.end(), u.start()):
        if not mask[k]:
            continue
        c = b[k:k + 1]
        if c == b"(":
            paren += 1
        elif c == b")":
            paren -= 1
        elif c == b"{":
            depth += 1
        elif c == b"}":
            depth -= 1
            if depth == 1 and not re.match(rb"\s*else\b", b[k + 1:k + 40]):   # an if block's `}` before its else
                start = k + 1
        elif c == b";" and depth == 1 and paren == 0:
            start = k + 1
    # inside a nested block (depth > 1): `start` is still where the enclosing function-level statement begins
    j = start
    while j < u.start() and (b[j:j + 1] in b" \t\r\n" or not mask[j]):
        j += 1
    if re.match(rb"else\b", b[j:j + 5]):
        return b, "HAND the statement is an else branch"
    ls = b.rfind(b"\n", 0, j) + 1
    if b[ls:j].strip():
        return b, "HAND the statement does not start a line"
    ind = b[ls:j]
    nl = b"\r\n" if b[ls - 2:ls] == b"\r\n" else b"\n"
    ins = ind + b'if (!objectp(me->query_temp("weapon"))) return notify_fail("' + MSG + b'");' + nl
    return b[:ls] + ins + b[ls:], 1


def optional_weapon(d, b):
    """dianxue (mhxy): `type(me)` from a local header turns no weapon into "unarmed" (dif 110) and the move reads the
    weapon only under `if (dif != 110)`: bare hands are a designed case, not a crash."""
    for inc in re.findall(rb'#include\s+"([^"]+)"', b):
        h = os.path.join(d, inc.decode("utf-8", "replace"))
        if os.path.isfile(h):
            t = open(h, "rb").read()
            if b"mapping type(" in t and b'"unarmed"' in t:
                return True
    return False


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
                    if not n and optional_weapon(sd, b):
                        print(f"HAND weapon optional (an included type() helper maps no weapon to unarmed): {slug} /{d}/{sk}/{f}")
                        continue
                    if not n:
                        out, n = fix_inline(b)
                        if isinstance(n, str):
                            print(f"{n}: {slug} /{d}/{sk}/{f}")
                            continue
                    if n:
                        tot += n
                        print(f"FIX   {slug} /{d}/{sk}/{f}")
                        if apply:
                            open(p, "wb").write(out)
    print(f"{tot} perform(s)" + ("" if apply else " (plan only; --apply writes)"))


if __name__ == "__main__":
    main()
