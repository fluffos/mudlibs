#!/usr/bin/env python3
"""scripts/lpc_fix_skill_typo.py SLUG... [--apply] [--dict-libs SLUG...]

A misspelled skill name in query_skill() (KB 06 section 7.249): `query_skill("beimin-shengong", 1)` for
beiming-shengong, `xiatian-gong` for xiantian-gong, `douzhuan-xignyi`, `yihua-jimu`, or the name a skill had before
the lib renamed its file (`jinwu-dao` for jinwu-daofa, `emei-jianfa` for emei-jian).  The call is always 0: a
requirement (`< 20` then refuse) never passes, so the skill or move can never be learned or used; an exclusion list
(`> 10` then refuse: the force-mixing rule) never fires; a formula loses its term.

A name is fixed only when all of these hold:
  - it is no skill file of the lib (kungfu/skill, daemon/skill) and no base skill, and nothing in the lib gives it
    out (set_skill/map_skill/prepare_skill/improve_skill: then it is a missing skill, a content gap);
  - it has typo shape against one skill of the lib: Levenshtein distance <= 2 on the names without hyphens (both
    at least 6 letters), or one name is the other plus a common suffix (-fa, -gong, -jian, -xinfa ...);
  - a Chinese name confirms it: the lines from the call to 3 lines after it contain that skill's Chinese name
    (data/e2c_dict.o or data/chinese.o of the lib, else of the --dict-libs) while not naming the skill's own id,
    or a dictionary gives the misspelled name that same Chinese name, or the difference is one no pinyin word
    comes from (`_` for `-`, a hyphen added or dropped, two adjacent letters swapped: mizongxinfa, dragon_strike,
    douzhuan-xignyi) and the name is no skill file of any lib, or the site sits in that skill's own file or perform dir
    and the names are one letter apart (hujian-daofa in hujia-daofa.lpc: its own level, misspelled) (jiuyangforce 九阳神功 is not jiuyang-force 九阳真气).
    Skill files in domain dirs (d/mj/skill) count as the lib's own names.  One confirmed site confirms the name for the whole lib.  A name whose own Chinese name (any dictionary) appears at one of its sites, or that the lib's
    own dictionary translates differently, or three dictionaries agree to name differently, is a different skill
    the lib lacks: never fixed.
Code only (comments and strings untouched except the name literal itself), wizard and backup dirs skipped.
Binary-safe.  Without --apply the plan is printed (FIX lines; SKIP lines name typo-shaped but unconfirmed names)."""
import os
import re
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from lpc_fix_void_return import code_mask  # noqa: E402

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SKIP = re.compile(r"/(u|w|open|players|backup|old|bak|log|data|doc|wiz|test)/|[-_.](bak|old)/")
CALL = re.compile(rb'query_skill\s*\(\s*"([\w-]+)"')
BASE = {"force", "dodge", "parry", "unarmed", "sword", "blade", "staff", "club", "whip", "axe", "hammer", "dagger",
        "fork", "throwing", "stick", "spear", "halberd", "hook", "cuff", "strike", "finger", "hand", "claw", "leg",
        "kick", "move", "spells", "magic", "literate", "array", "taoism", "buddhism", "mahayana", "archery", "poison",
        "medicine", "medical", "begging", "stealing", "checking", "training", "music", "qimen-wuxing", "idle",
        "iron-cloth", "perception", "necromancy", "flute", "chanting", "cursism", "lamaism", "knowledge", "trade",
        "leadership", "strategy"}
SUF = ("fa", "gong", "shu", "jue", "jing", "xinfa", "shengong", "zhang", "quan", "jian", "dao", "zhi", "shou")
KV = re.compile(r'"([\w-]+)":"([^"\\]*)"')


def lev(a, b):
    p = list(range(len(b) + 1))
    for i, ca in enumerate(a, 1):
        c = [i]
        for j, cb in enumerate(b, 1):
            c.append(min(p[j] + 1, c[j - 1] + 1, p[j - 1] + (ca != cb)))
        p = c
    return p[-1]


def mechanical(n, near):
    """Differences no pinyin word comes from: _ for -, a hyphen added or dropped, two adjacent letters swapped."""
    a, b = n.replace("_", "-"), near.replace("_", "-")
    if a == b or a.replace("-", "") == b.replace("-", ""):
        return True
    if len(a) == len(b) and len(a) >= 8:
        d = [i for i in range(len(a)) if a[i] != b[i]]
        return len(d) == 2 and d[1] == d[0] + 1 and a[d[0]] == b[d[1]] and a[d[1]] == b[d[0]]
    return False


def shape(n, near):
    a, b = n.replace("-", "").replace("_", ""), near.replace("-", "").replace("_", "")
    if min(len(a), len(b)) >= 6 and lev(a, b) <= 2:
        return True
    if n.startswith(near + "-") or near.startswith(n + "-"):
        return False   # a family member (xx-jian / xx-jian-zong), not a spelling
    return any(x.startswith(y) and x[len(y):].lstrip("-_") in SUF for x, y in ((n, near), (near, n)))


VOTES = {}   # (id, Chinese name) -> number of libs whose dictionary says so


def chinese(slugs, vote=False):
    d = {}
    for s in slugs:
        seen = set()
        for f in ("e2c_dict.o", "chinese.o"):
            p = f"{REPO}/libs/{s}/work/data/{f}"
            if not os.path.exists(p):
                continue
            for k, v in KV.findall(open(p, "rb").read().decode("utf-8", "replace")):
                v = re.sub(r"\x1b\[[0-9;]*m", "", v).strip()
                if len(v) >= 2 and re.search(r"[\u4e00-\u9fff]", v):
                    d.setdefault(k, set()).add(v)
                    if vote and (k, v) not in seen:
                        seen.add((k, v))
                        VOTES[(k, v)] = VOTES.get((k, v), 0) + 1
    return d


_CORPUS = set()


def corpus_skills():
    """Every skill file name of every lib (kungfu/skill, daemon/skill, d/*/skill)."""
    if not _CORPUS:
        for slug in os.listdir(f"{REPO}/libs"):
            w = f"{REPO}/libs/{slug}/work"
            for d in ("kungfu/skill", "daemon/skill"):
                if os.path.isdir(f"{w}/{d}"):
                    _CORPUS.update(f[:-4] for f in os.listdir(f"{w}/{d}") if f.endswith(".lpc"))
            if os.path.isdir(f"{w}/d"):
                for area in os.listdir(f"{w}/d"):
                    sd = f"{w}/d/{area}/skill"
                    if os.path.isdir(sd):
                        _CORPUS.update(f[:-4] for f in os.listdir(sd) if f.endswith(".lpc"))
        _CORPUS.add("")
    return _CORPUS


def variants(names):
    out = set()
    for c in names:
        out.add(c)
        if len(c) >= 4 and c[-1] in "法功术诀经掌拳剑刀":
            out.add(c[:-1])
    return out


def plan(slug, ext):
    work = f"{REPO}/libs/{slug}/work"
    skills = set()
    for d in ("kungfu/skill", "daemon/skill"):
        if os.path.isdir(f"{work}/{d}"):
            skills.update(f[:-4] for f in os.listdir(f"{work}/{d}") if f.endswith(".lpc"))
    if not skills:
        return {}, {}, {}, []
    files, unknown, local = {}, set(), set()
    for dp, dn, fn in os.walk(work):
        if SKIP.search(dp[len(work):] + "/"):
            continue
        if "skill" in os.path.basename(dp):   # a domain skill dir (d/mj/skill, d/kunlun/mjskill, skills): its names are skills
            local.update(f[:-4] for f in fn if f.endswith(".lpc"))
        for f in fn:
            if f.endswith((".lpc", ".h")) and not re.search(r"副本|复件| - |copy", f, re.I):   # backup copies ("x - 副本.lpc")
                p = os.path.join(dp, f)
                b = open(p, "rb").read()
                if b"query_skill" in b or b"_skill" in b:
                    files[p] = b
                    unknown.update(m.group(1).decode() for m in CALL.finditer(b))
    unknown -= skills | BASE | local
    cand = {}
    for n in unknown:
        near = [s for s in skills if shape(n, s)]
        if len(near) == 1:
            cand[n] = near[0]
    if not cand:
        return {}, {}, {}, []
    own = chinese([slug])
    cn = lambda x: own.get(x) or ext.get(x) or set()
    cn_all = lambda x: own.get(x, set()) | ext.get(x, set())
    given, conf, other = set(), {}, set()
    for p, b in files.items():
        t = b.decode("utf-8", "replace")
        for n, near in cand.items():
            if n not in t:
                continue
            if re.search(r'(?:set_skill|map_skill|prepare_skill|improve_skill)\s*\([^;]*"' + re.escape(n) + '"', t):
                given.add(n)
            names = variants(cn(near))
            theirs = variants(cn_all(n)) - variants(cn_all(near))   # the misspelled id's own Chinese names, if any
            L = t.split("\n")
            for i, l in enumerate(L):
                if '"' + n + '"' in l and "query_skill" in l:
                    win = "\n".join(L[i:i + 4])
                    if any(x in win for x in theirs):
                        other.add(n)   # the site names the other skill (圣火心法 next to 圣火令法)
                    elif names and '"' + near + '"' not in win and any(x in win for x in names):
                        conf.setdefault(n, set()).add("ctx")
            if cn(n) & cn(near):
                conf.setdefault(n, set()).add("dict")
            if mechanical(n, near) and n not in corpus_skills():   # a skill file of some lib is a real name
                conf.setdefault(n, set()).add("mech")
            own_skill = re.search(r"/(?:kungfu|daemon)/skill/([^/]+?)(?:\.lpc$|/)", p)
            if own_skill and own_skill.group(1) == near and \
                    lev(n.replace("-", "").replace("_", ""), near.replace("-", "").replace("_", "")) == 1:
                conf.setdefault(n, set()).add("self")   # one letter off its own name, in its own file (hujian-daofa)
    # a site that also names the misspelled id's own Chinese name means a real, different skill the lib lacks
    # (syxjl shenghuo-lingfa: "你对圣火心法的领悟不够，无法学圣火令法" gates on shenghuo-xinfa, not on itself);
    # so does a dictionary of this very lib that names it differently (jiuyang-force 九阳真气 vs jiuyangforce)
    other |= {n for n in cand if own.get(n) and not (variants(own[n]) & variants(cn(cand[n])))}
    # and three or more dictionaries agreeing on a different name (tonsillitis 反五行摄气诀 vs tonsillit 摄气诀)
    other |= {n for n in cand if any(c >= 3 and not (variants({v}) & variants(cn_all(cand[n])))
                                     for (k, v), c in VOTES.items() if k == n)}
    fix = {n: near for n, near in cand.items() if n in conf and n not in given and n not in other}
    skip = {n: near for n, near in cand.items() if n not in conf and n not in given and n not in other}
    diff = {n: cand[n] for n in other if n not in given}
    return fix, skip, diff, list(files.items())


def apply_file(b, fix):
    mask = code_mask(b)
    out, last, n = [], 0, 0
    for m in CALL.finditer(b):
        name = m.group(1).decode()
        if name in fix and mask[m.start()]:
            out.append(b[last:m.start(1)])
            out.append(fix[name].encode())
            last = m.end(1)
            n += 1
    out.append(b[last:])
    return b"".join(out), n


def main():
    args = sys.argv[1:]
    apply = "--apply" in args
    dict_libs = []
    if "--dict-libs" in args:
        k = args.index("--dict-libs")
        dict_libs = [a for a in args[k + 1:] if not a.startswith("--")]
        args = args[:k]
    ext = chinese(dict_libs, vote=True) if dict_libs else {}   # once: VOTES counts each lib one time
    tot = 0
    for slug in [a for a in args if not a.startswith("--")]:
        work = f"{REPO}/libs/{slug}/work"
        if not os.path.isdir(work) or os.path.exists(f"{work}/.git"):
            continue
        if not subprocess.run(["git", "-C", REPO, "ls-files", "--", f"libs/{slug}/work/"], capture_output=True,
                              text=True).stdout.strip():
            continue   # an untracked tree is someone's work in progress (a decompile being rebuilt)
        fix, skip, diff, files = plan(slug, ext)
        for n, near in sorted(skip.items()):
            print(f"SKIP  {slug} {n} -> {near}  (no Chinese name confirms it)")
        for n, near in sorted(diff.items()):
            print(f"OTHER {slug} {n} -> {near}  (named as a different skill: left)")
        if not fix:
            continue
        for p, b in files:
            out, n = apply_file(b, fix)
            if n:
                tot += n
                print(f"FIX   {slug} {p[len(work):]}  {n}  " + ", ".join(sorted({f'{k}->{v}' for k, v in fix.items() if k.encode() in b})))
                if apply:
                    open(p, "wb").write(out)
    print(f"{tot} call(s)" + ("" if apply else " (plan only; --apply writes)"))


if __name__ == "__main__":
    main()
