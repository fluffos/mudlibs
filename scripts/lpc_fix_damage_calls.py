#!/usr/bin/env python3
"""scripts/lpc_fix_damage_calls.py SLUG... [--apply]

`receive_damage("qi", -12)` / `receive_damage("neili", -52)` with a negative literal (KB 06 section 7.241).  The
author meant "take 12 qi" or "spend 52 neili", but receive_damage() takes a positive amount: in most ES/xkx
damage.lpc files a negative one is `error("F_DAMAGE: 伤害值为负值")`, so practising the skill (or the hit, the
miscarriage, the trap) stops with a runtime error; where damage.lpc clamps it to 0 the cost silently vanishes.

Only libs whose feature/damage.lpc rejects or clamps negative damage are touched, and only calls whose amount is a
plain negative literal, `-N - random(M)`, `-N + X`, `-( ... )` or a negated skill level (`-lvl / 6`, `-sklv`); a
variable such as `-damage` is usually negated on purpose, in the branch where it is already below zero, so it is left
alone:

    receive_damage("qi", -12)              ->  receive_damage("qi", 12)
    receive_damage("qi", -(100 + r), "x")  ->  receive_damage("qi", (100 + r), "x")
    receive_damage("neili", -52)           ->  add("neili", -52)          (a resource pool: a cost, not damage)

The same for receive_wound().

A second pass handles a resource pool passed as damage in a lib that does not take it: `receive_damage("jingli", 30)`
where damage.lpc allows only `jing`/`qi` (`F_DAMAGE: 伤害种类错误`, the nitan/xkx families' practice_skill() of
dozens of movement and weapon skills; a weapon's `victim->receive_wound("force", n, me)` drain).  Only
receive_damage()/receive_wound() statements whose type is a resource (neili, jingli, force, mana, atman, or a `max_`
pool: the 走火入魔 penalty `receive_damage("max_qi", random(100))`) missing from the lib's own `type != "..."` list
(read from its receive_damage()):

    me->receive_damage("jingli", 30);        ->  me->add("jingli", -30);
    me->receive_damage("neili", 10 + x, me); ->  me->add("neili", -(10 + x));

Code only (not strings or comments).  Binary-safe.  Without --apply the plan is printed."""
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from lpc_fix_void_return import code_mask  # noqa: E402

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SKIP = re.compile(r"/(u|w|players|backup|old|bak|log|data|doc)/")  # `/open/` is playable world (Taiwanese / dreamofseven libs)
RESOURCE = {b"neili", b"jingli", b"force", b"mana", b"atman", b"max_neili", b"max_jingli"}
CALL = re.compile(rb'receive_(damage|wound)\((\s*)"([a-z_]+)"(\s*,\s*)(-[^;]*?)(\)\s*;)')
LIT = re.compile(rb"-\s*(\d+)(\s*[-+].*)?\s*$", re.S)
NAME = re.compile(rb"-\s*((?:lvl|sklv)\b\s*(?:/\s*\d+)?)(\s*,.*)?$", re.S)   # skill levels: never below zero
PAREN = re.compile(rb"-\s*(\((?:[^()]|\((?:[^()]|\([^()]*\))*\))*\))(\s*,.*)?$", re.S)


def negative_policy(work):
    """'error' / 'clamp' when the lib's receive_damage() rejects or zeroes a negative amount, else None."""
    p = f"{work}/feature/damage.lpc"
    if not os.path.exists(p):
        return None
    d = open(p, "rb").read()
    m = re.search(rb"receive_damage\s*\([^)]*\)\s*\{(.{0,400})", d, re.S)
    if not m:
        return None
    body = m.group(1)
    if re.search(rb"damage\s*<\s*0\s*\)\s*error", body):
        return "error"
    if re.search(rb"damage\s*<\s*0\s*\)\s*damage\s*=\s*0", body):
        return "clamp"
    return None


def allowed_types(work):
    """{b"damage": types, b"wound": types}: what the lib's receive_damage() and receive_wound() accept (the
    `type != "..."` tests inside each function body), or None when neither has such a list.  The two can differ
    (xjcq2000: damage takes jingli, wound does not)."""
    p = f"{work}/feature/damage.lpc"
    if not os.path.exists(p):
        return None
    d = open(p, "rb").read()
    out = {}
    for kind in (b"damage", b"wound"):
        i = d.find(b"int receive_" + kind + b"(")
        if i < 0:
            continue
        j = d.find(b"\n}", i)
        a = set(re.findall(rb'type\s*!=\s*"(\w+)"', d[i:j if j > 0 else i + 1500]))
        if a:
            out[kind] = a
    return out or None


RES_CALL = re.compile(rb'receive_(damage|wound)\((\s*)"(neili|jingli|force|mana|atman|max_qi|max_jing|max_neili|max_jingli|max_kee|max_gin|max_sen|max_force)"(\s*),')


def split_args(b, i):
    """From just after the type's comma, the remaining arguments up to the call's `)`; returns (args, end) or None."""
    depth, start, args, k = 0, i, [], i
    while k < len(b):
        c = b[k]
        if c in b"([{":
            depth += 1
        elif c in b")]}":
            if depth == 0:
                args.append(b[start:k])
                return args, k
            depth -= 1
        elif c == 0x2c and depth == 0:
            args.append(b[start:k])
            start = k + 1
        elif c == 0x22:
            k += 1
            while k < len(b) and b[k] != 0x22:
                k += 2 if b[k] == 0x5c else 1
        elif c == 0x3b:
            return None
        k += 1
    return None


def simple(e):
    """A literal, a name or a call chain: `-e` needs no parentheses."""
    e = e.strip()
    if re.fullmatch(rb"\d+", e):
        return True
    depth = 0
    e = re.sub(rb'"(?:[^"\\]|\\.)*"', b'""', e)
    for i, c in enumerate(e):
        if c in b"([":
            depth += 1
        elif c in b")]":
            depth -= 1
        elif depth == 0 and (c in b"+*/%?:<>=&|!" or c == 0x2d and e[i:i + 2] != b"->"):
            if c == 0x3e and e[i - 1:i] == b"-":
                continue
            return False
    return True


def fix_types(b, allowed):
    hits = [m for m in RES_CALL.finditer(b)
            if m.group(1) in allowed and m.group(3) not in allowed[m.group(1)]]
    if not hits:
        return b, 0, []
    mask = code_mask(b)
    out, last, n, hand = [], 0, 0, []
    for m in hits:
        if not mask[m.start()]:
            continue
        ls = b.rfind(b"\n", 0, m.start()) + 1
        prefix = b[ls:m.start()]
        if re.search(rb"(=|\breturn\b|\(|&&|\|\||\?|:)\s*[\w\[\]\->\"]*$", prefix.replace(b"->", b"")):
            hand.append(b[:m.start()].count(b"\n") + 1)   # the value is used: only a statement is rewritten
            continue
        r = split_args(b, m.end())
        if not r or not re.match(rb"\s*;", b[r[1] + 1:]) or not r[0][0].strip():
            hand.append(b[:m.start()].count(b"\n") + 1)
            continue
        args, end = r
        amt = args[0].strip()
        if amt.startswith(b"-"):
            new_amt = amt   # already the add() amount (section 7.241's first class)
        else:
            new_amt = b"-" + amt if simple(amt) else b"-(" + amt + b")"
        out.append(b[last:m.start()])
        out.append(b"add(" + m.group(2) + b'"' + m.group(3) + b'"' + m.group(4) + b", " + new_amt + b")")
        last = end + 1
        n += 1
    out.append(b[last:])
    return b"".join(out), n, hand


def one_term(rest):
    """rest is `+ X` or `- X` with no further top-level + or -: its sign can be flipped."""
    depth = 0
    for i, c in enumerate(rest):
        if c in b"([":
            depth += 1
        elif c in b")]":
            depth -= 1
        elif c in b"+-" and depth == 0 and rest[:i].strip() and rest[i:i + 2] != b"->":
            return False
        elif c == 0x2c and depth == 0:
            return False
    return True


def rewrite(m):
    kind, sp, typ, comma, arg, close = m.groups()
    call = b"receive_" + kind + b"(" + sp + b'"' + typ + b'"' + comma
    lm, pm = LIT.match(arg), PAREN.match(arg)
    if typ in RESOURCE:
        if kind == b"damage" and (lm and (not lm.group(2) or one_term(lm.group(2))) or pm and not pm.group(2)):
            return b"add(" + sp + b'"' + typ + b'"' + comma + arg + close
        return None
    if lm:
        rest = lm.group(2) or b""
        if rest and not one_term(rest):
            return None
        rest = re.sub(rb"^(\s*)([-+])", lambda r: r.group(1) + (b"+" if r.group(2) == b"-" else b"-"), rest)
        return call + lm.group(1) + rest + close
    nm = NAME.match(arg)
    if nm:
        return call + nm.group(1) + (nm.group(2) or b"") + close
    if pm:
        return call + pm.group(1) + (pm.group(2) or b"") + close
    return None


def fix(b):
    calls = list(CALL.finditer(b))
    if not calls:
        return b, 0, []
    mask = code_mask(b)
    out, last, n, hand = [], 0, 0, []
    for m in calls:
        if not mask[m.start()]:
            continue
        new = rewrite(m)
        if new is None:
            hand.append(b[:m.start()].count(b"\n") + 1)
            continue
        # `obj->receive_damage(` stays a call on obj: only the name and arguments change
        out.append(b[last:m.start()])
        out.append(new)
        last = m.end()
        n += 1
    out.append(b[last:])
    return b"".join(out), n, hand


def main():
    args = sys.argv[1:]
    apply = "--apply" in args
    slugs = [a for a in args if not a.startswith("--")]
    tot = 0
    for slug in slugs:
        work = f"{REPO}/libs/{slug}/work"
        pol = negative_policy(work)
        allowed = allowed_types(work)
        if not pol and not allowed:
            continue
        for dp, dn, fn in os.walk(work):
            if SKIP.search(dp[len(work):] + "/"):
                continue
            for f in fn:
                if not f.endswith(".lpc"):
                    continue
                p = os.path.join(dp, f)
                b = open(p, "rb").read()
                if b"receive_" not in b:
                    continue
                out, n, hand = fix(b) if pol else (b, 0, [])
                if allowed:
                    out, n2, hand2 = fix_types(out, allowed)
                    n += n2
                    hand += hand2
                for ln in hand:
                    print(f"HAND  {slug} {p[len(work):]}:{ln}")
                if n:
                    tot += n
                    print(f"FIX   {slug} ({pol}) {p[len(work):]}  {n}")
                    if apply:
                        open(p, "wb").write(out)
    print(f"{tot} call(s)" + ("" if apply else " (plan only; --apply writes)"))


if __name__ == "__main__":
    main()
