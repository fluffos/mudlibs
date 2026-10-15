#!/usr/bin/env python3
"""scripts/lpc_port_es_props.py SLUG... [--any-file] [--apply]

A skill file copied from an Eastern-Stories / xyj lib (`kee`, `gin`, `sen`, `force`, `max_force`) into an xkx-lineage
lib whose characters carry `qi`, `jing`, `neili`, `max_neili` (KB 06 section 7.241, third class).  Its practice_skill()
calls `me->receive_damage("kee", 30)`, which the lib's damage.lpc rejects (`F_DAMAGE: 伤害种类错误`), and its tests
read properties nobody has (`query("force") < 3` is always true, so practice and learning refuse forever).

Only top-level kungfu/skill/*.lpc files whose practice_skill() passes such a type to receive_damage()/receive_wound()
are touched, only in libs whose receive_damage() *errors* on an unknown type and accepts `qi` and `jing`.  In those
files the first string argument of the dbase and damage calls (query, add, set, receive_damage, receive_wound,
receive_heal, receive_curing, and their `me->` forms) is renamed:

    kee -> qi        max_kee -> max_qi        eff_kee -> eff_qi
    gin -> jing      max_gin -> max_jing      eff_gin -> eff_jing
    sen -> jing      max_sen -> max_jing      eff_sen -> eff_jing     (xkx folded 精 and 神 into jing)
    force -> neili   max_force -> max_neili   force_factor -> jiali

The reverse direction, an xkx file inside an ES/xyj lib that errors on `qi`/`jing` and has `kee`, maps `qi` -> `kee`,
`jing` -> the pool the lib's own study/learn/practice commands charge (`sen` in the xyj family, `gin` in ES and
dtsl), `neili` -> `force`, `jiali` -> `force_factor` (and the `max_`/`eff_` forms); `jingli` has no ES
counterpart and is left.  `--any-file` widens the scope from kungfu/skill practice_skill() to every file of the lib
(wizard, backup and data dirs aside) that passes a foreign type to receive_damage()/receive_wound(): performs,
conditions, NPC specials, items; a two-level directory that no file outside it names (an unwired copy such as
xbtxiii's daemon/gongfu) is skipped.

A lib whose characters carry `jingli` where xkx has `jing` (the xxcq family: receive_damage() takes jingli, qi,
douzhi, shenzhi) gets the forward table with every `jing` target, and xkx's own `jing`, renamed to `jingli`.

`query_skill("force")` and other skill names are not touched, nor anything in strings that are not that first
argument.  Binary-safe.  Without --apply the plan is printed."""
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from lpc_fix_void_return import code_mask  # noqa: E402

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
MAP = {b"kee": b"qi", b"max_kee": b"max_qi", b"eff_kee": b"eff_qi",
       b"gin": b"jing", b"max_gin": b"max_jing", b"eff_gin": b"eff_jing",
       b"sen": b"jing", b"max_sen": b"max_jing", b"eff_sen": b"eff_jing",
       b"force": b"neili", b"max_force": b"max_neili", b"force_factor": b"jiali"}
RMAP = {b"qi": b"kee", b"max_qi": b"max_kee", b"eff_qi": b"eff_kee",
        b"jing": b"gin", b"max_jing": b"max_gin", b"eff_jing": b"eff_gin",
        b"neili": b"force", b"max_neili": b"max_force", b"jiali": b"force_factor"}
ES_TYPES = {b"kee", b"gin", b"sen"}
XKX_TYPES = {b"qi", b"jing"}
SKIP = re.compile(r"/(u|w|open|players|backup|old|bak|log|data|doc)/")


def call_re(m):
    return re.compile(rb'\b(query|add|set|receive_damage|receive_wound|receive_heal|receive_curing)\(\s*"(' +
                      b"|".join(sorted(m, key=len, reverse=True)) + rb')"')


CALL = call_re(MAP)
RCALL = call_re(RMAP)
JLCALL = call_re({**MAP, b"jing": b"", b"max_jing": b"", b"eff_jing": b""})
PRACTICE = re.compile(rb"int\s+practice_skill\s*\([^)]*\)\s*\{(.*?)\n\}", re.S)


def lib_dir(work):
    """'fwd' when receive_damage() errors on an unknown type and takes qi/jing (not kee); 'rev' for kee (not qi)."""
    p = f"{work}/feature/damage.lpc"
    if not os.path.exists(p):
        return False
    d = open(p, "rb").read()
    i = d.find(b"int receive_damage(")
    if i < 0:
        return False
    body = d[i:i + 1500]
    allowed = set(re.findall(rb'type\s*!=\s*"(\w+)"', body))
    if re.search(rb'type\s*!=\s*"\w+"[^;{]*\)\s*\n?\s*error', body) is None:
        return None
    if XKX_TYPES <= allowed and not allowed & ES_TYPES:
        return "fwd"
    if {b"qi", b"jingli"} <= allowed and b"jing" not in allowed and not allowed & ES_TYPES:
        return "jl"   # the xxcq family: xkx's jing is called jingli
    if b"kee" in allowed and not allowed & XKX_TYPES:
        return "rev"
    return None


def referenced_dirs(work, pres):
    """The two-level directories of PRES (e.g. `/daemon/gongfu/`) that some .lpc/.h file outside them names, with or
    without the leading slash; one pass over the lib."""
    found = {p for p in pres if p.count("/") < 3}
    todo = {p: p[1:].encode() for p in pres if p not in found}
    for dp, dn, fn in os.walk(work):
        if not todo:
            break
        rel = dp[len(work):] + "/"
        for f in fn:
            if not f.endswith((".lpc", ".h")) or not todo:
                continue
            b = open(os.path.join(dp, f), "rb").read()
            for p, key in list(todo.items()):
                if not rel.startswith(p) and key in b:
                    found.add(p)
                    del todo[p]
    return found


def needs_port(b, direction="fwd", any_file=False):
    foreign = {"fwd": rb"kee|gin|sen", "rev": rb"qi|jing", "jl": rb"kee|gin|sen|jing"}[direction]
    pat = rb'receive_(?:damage|wound)\(\s*"(' + foreign + rb')"'
    if any_file:
        mask = None
        for m in re.finditer(pat, b):
            mask = mask or code_mask(b)
            if mask[m.start()]:
                return True
        return False
    m = PRACTICE.search(b)
    return m is not None and re.search(pat, m.group(1)) is not None


def jing_target(work):
    """The ES pool that stands for xkx `jing` in this lib: the one its own study/learn/practice commands charge
    (xyj: sen, ES/dtsl: gin); failing that, the more used of query("gin") / query("sen")."""
    c = {b"gin": 0, b"sen": 0}
    for d in ("cmds/skill", "cmds/std", "cmds/usr"):
        for f in ("study.lpc", "learn.lpc", "practice.lpc", "du.lpc"):
            p = f"{work}/{d}/{f}"
            if os.path.exists(p):
                for t in re.findall(rb'receive_damage\(\s*"(gin|sen)"', open(p, "rb").read()):
                    c[t] += 1
    if c[b"gin"] != c[b"sen"]:
        return max(c, key=c.get)
    for dp, dn, fn in os.walk(f"{work}/kungfu" if os.path.isdir(f"{work}/kungfu") else f"{work}/daemon"):
        for f in fn:
            if f.endswith(".lpc"):
                b = open(os.path.join(dp, f), "rb").read()
                c[b"gin"] += b.count(b'query("gin")')
                c[b"sen"] += b.count(b'query("sen")')
    return b"sen" if c[b"sen"] > c[b"gin"] else b"gin"


def port(b, direction="fwd", jing=b"gin"):
    mask = code_mask(b)
    if direction == "fwd":
        table, call = MAP, CALL
    elif direction == "jl":
        table = {**MAP, **{k: v.replace(b"jing", b"jingli") for k, v in MAP.items() if v.endswith(b"jing")},
                 b"jing": b"jingli", b"max_jing": b"max_jingli", b"eff_jing": b"eff_jingli"}
        call = JLCALL
    else:
        table = {**RMAP, b"jing": jing, b"max_jing": b"max_" + jing, b"eff_jing": b"eff_" + jing}
        call = RCALL
    out, last, n = [], 0, 0
    for m in call.finditer(b):
        if not mask[m.start()]:
            continue
        # the receiver is either nothing (this object) or `x->`; `query_skill(` does not match `\bquery\(`
        s, e = m.start(2), m.end(2)
        out.append(b[last:s])
        out.append(table[m.group(2)])
        last = e
        n += 1
    out.append(b[last:])
    return b"".join(out), n


def main():
    args = sys.argv[1:]
    apply = "--apply" in args
    any_file = "--any-file" in args
    tot = files = 0
    for slug in [a for a in args if not a.startswith("--")]:
        work = f"{REPO}/libs/{slug}/work"
        direction = None if os.path.exists(f"{work}/.git") else lib_dir(work)
        if not direction:
            continue
        if any_file:
            paths = [os.path.join(dp, f) for dp, dn, fn in os.walk(work) if not SKIP.search(dp[len(work):] + "/")
                     for f in fn if f.endswith(".lpc")]
        else:
            d = f"{work}/kungfu/skill"
            paths = [f"{d}/{f}" for f in os.listdir(d) if f.endswith(".lpc")] if os.path.isdir(d) else []
        todo = []
        for p in sorted(paths):
            b = open(p, "rb").read()
            if b"receive_" in b and needs_port(b, direction, any_file):
                todo.append((p, b))
        if any_file and todo:
            # skip a two-level directory no file outside it names (xbtxiii's daemon/gongfu, an unwired skill copy)
            pre = {p: "/".join(p[len(work):].split("/")[:3]) + "/" for p, b in todo}
            live = referenced_dirs(work, set(pre.values()))
            todo = [(p, b) for p, b in todo if pre[p] in live]
        jing = jing_target(work) if direction == "rev" and todo else b"gin"
        for p, b in todo:
            out, n = port(b, direction, jing)
            if n:
                files += 1
                tot += n
                print(f"PORT  {slug} ({direction}{' jing->' + jing.decode() if direction == 'rev' else ''}) "
                      f"{p[len(work):]}  {n}")
                if apply:
                    open(p, "wb").write(out)
    print(f"{files} file(s), {tot} key(s)" + ("" if apply else " (plan only; --apply writes)"))


if __name__ == "__main__":
    main()
