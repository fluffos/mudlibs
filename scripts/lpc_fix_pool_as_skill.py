#!/usr/bin/env python3
"""scripts/lpc_fix_pool_as_skill.py SLUG... [--apply]

A pool, attribute or experience read through query_skill() (KB 06 section 7.247): `me->query_skill("neili")`,
`target->query_skill("combat_exp")`, `ob->query_skill("int", 1)`.  None of these is a skill.  In the xkx/ES F_SKILL
the call returns 0 (apply/NAME plus nothing), so a gate such as `if (me->query_skill("max_neili") < 500)` refuses
forever (the perform, the apprenticeship, the book can never be used), `random(me->query_skill("combat_exp")) >
target->query_skill("combat_exp")` is `0 > 0` (FluffOS `random(0)` is 0) so the move never lands, and a formula like `dp = target->query_skill("jing") / 2` silently drops the term.  The
Fengyun F_SKILL loads `SKILL_D(name)` for a non-raw query and errors outright (`/daemon/skill/combat_exp`).

Each call whose name has only one reading becomes `query("NAME")` (the raw flag dropped): experience and standing
(combat_exp, shen, score, potential, age), the attributes, and the max_ pools (`query_skill("max_neili") < 500` is
the usual 内力修为 gate).  Skipped and listed as HAND:
  - a current pool (neili, jing, qi, jingli, kee, ...): it often stands for the internal-power skill, not the pool
    (`receive_curing("qi", 10 + me->query_skill("neili") / 5)` is the xkx heal exert's `query_skill("force") / 5`;
    the pool would heal ten times as much), so each one is read by hand;
  - a line that sets "jiali" (the stock NPC code is `set("jiali", query_skill("force") / 2)`);
  - a name the lib has a skill file for (kungfu/skill/NAME.lpc, daemon/skill/NAME.lpc);
  - a max_ pool the lib does not keep (max_neili in a max_force lib or the reverse: the name never appears in the
    file that defines receive_damage());
  - a line that also reads a non-skill this tool does not know through query_skill() (wdxtym's topten sums
    `query_skill("weiwang")`, `query_skill("gain/armor")` ...: the intent is unclear).
Code only (not strings or comments), wizard and backup dirs skipped.  Binary-safe.  Without --apply the plan is
printed."""
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from lpc_fix_void_return import code_mask  # noqa: E402

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SKIP = re.compile(r"/(u|w|players|backup|old|bak|log|data|doc)/")
POOLS = {"neili", "max_neili", "jingli", "max_jingli", "jing", "max_jing", "eff_jing", "qi", "max_qi", "eff_qi",
         "kee", "max_kee", "eff_kee", "gin", "max_gin", "eff_gin", "sen", "max_sen", "eff_sen", "mana", "max_mana",
         "atman", "max_atman"}
CURRENT = {n for n in POOLS if not n.startswith("max_")}
OTHER = {"combat_exp", "shen", "score", "potential", "age", "str", "dex", "con", "int", "kar", "per", "cor", "cps",
         "spi"}
NAMES = POOLS | OTHER
CALL = re.compile(rb'query_skill\s*\(\s*"([\w/]+)"\s*(?:,\s*1\s*)?\)')


def pools_kept(work):
    """Pool names the lib's damage code mentions (None when no such file is found: keep every name)."""
    for rel in ("feature/damage.lpc", "inherit/char/damage.lpc", "std/char/damage.lpc", "feature/damage.c"):
        p = f"{work}/{rel}"
        if os.path.exists(p):
            b = open(p, "rb").read()
            return {n for n in POOLS if b'"' + n.encode() + b'"' in b or b'"' + n.split("_")[-1].encode() + b'"' in b}
    return None


def skill_names(work):
    out = set()
    for d in ("kungfu/skill", "daemon/skill"):
        if os.path.isdir(f"{work}/{d}"):
            out.update(f[:-4] for f in os.listdir(f"{work}/{d}") if f.endswith(".lpc"))
    return out


def fix(b, skills, kept):
    """(new bytes, n fixed, hand list)."""
    ms = list(CALL.finditer(b))
    if not ms:
        return b, 0, []
    mask = code_mask(b)
    out, last, n, hand = [], 0, 0, []
    for m in ms:
        name = m.group(1).decode()
        if name not in NAMES or name in skills or not mask[m.start()]:
            continue
        ls = b.rfind(b"\n", 0, m.start()) + 1
        le = b.find(b"\n", m.end())
        line = b[ls:le if le >= 0 else len(b)]
        odd = [x.group(1).decode() for x in CALL.finditer(line)
               if x.group(1).decode() not in NAMES and x.group(1).decode() not in skills]
        lno = b.count(b"\n", 0, m.start()) + 1
        if odd:
            hand.append(f"{lno} also reads {', '.join(sorted(set(odd)))}")
            continue
        if name in CURRENT:
            hand.append(f"{lno} current pool {name}: {line.strip()[:120].decode('utf-8', 'replace')}")
            continue
        if b'"jiali"' in line:
            hand.append(f"{lno} jiali: {line.strip()[:120].decode('utf-8', 'replace')}")
            continue
        if name in POOLS and kept is not None and name not in kept:
            hand.append(f"{lno} pool {name} not kept by this lib")
            continue
        out.append(b[last:m.start()])
        out.append(b'query("' + m.group(1) + b'")')
        last = m.end()
        n += 1
    out.append(b[last:])
    return b"".join(out), n, hand


def main():
    args = sys.argv[1:]
    apply = "--apply" in args
    tot = 0
    for slug in [a for a in args if not a.startswith("--")]:
        work = f"{REPO}/libs/{slug}/work"
        if not os.path.isdir(work) or os.path.exists(f"{work}/.git"):
            continue
        skills, kept = skill_names(work), pools_kept(work)
        for dp, dn, fn in os.walk(work):
            if SKIP.search(dp[len(work):] + "/"):
                continue
            for f in fn:
                if not f.endswith((".lpc", ".h")):
                    continue
                p = os.path.join(dp, f)
                b = open(p, "rb").read()
                if b"query_skill" not in b:
                    continue
                out, n, hand = fix(b, skills, kept)
                for h in hand:
                    print(f"HAND  {slug} {p[len(work):]}:{h}")
                if n:
                    tot += n
                    print(f"FIX   {slug} {p[len(work):]}  {n}")
                    if apply:
                        open(p, "wb").write(out)
    print(f"{tot} call(s)" + ("" if apply else " (plan only; --apply writes)"))


if __name__ == "__main__":
    main()
