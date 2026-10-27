#!/usr/bin/env python3
"""scripts/lpc_fix_skill_names.py [SLUG...] [--apply] [--summary]

A misspelled skill name in the call that grants or maps a skill (KB 06 section 7.258).  `set_skill("kunlun-shnfa", 100)` and
`map_skill("dodge", "shaolin-shnfa")` name a skill the lib does not have; the lib has `kunlun-shenfa` and
`shaolin-shenfa`.  Until the guard of scripts/lpc_guard_set_skill.py such an NPC died in `create()`; since then it loads, but
without the skill (a `set_skill` is skipped, a `map_skill` of a skill the NPC does not have is a no-op), so the Shaolin guards
dodge with the plain `dodge` and the monk who should teach the Yi Jin Jing teaches nothing.  scripts/lpc_fix_skill_typo.py
repairs the reading side (`query_skill`), where a Chinese name or a pinyin rule must confirm the name; this repairs the
granting side, from a reviewed table.

PAIRS maps a spelling to the skill it was meant to be.  A pair is applied in a lib only when the lib has no skill file
of the misspelled name and has one of the right name (a lib that really owns both, or neither, is left alone).  Every pair
in the table was read by a person: one letter dropped, doubled or swapped (`shnfa`, `tiaji`, `changqaun`), a hyphen added or
dropped (`yan-fly`, `kongmingquan`), `_` for `-`, or the same skill under another transliteration (`yunu`/`yunv`,
`pixie`/`bixie`); the neighbours that are a different skill (`taiji`/`taiyi`, `bihai-jianfa`/`bihai-bianfa`,
`jueqing-bian`/`jueqing-jian`) are not in it.
The name is replaced inside the string arguments of set_skill, set_wugong (the xajh/xo family's create-time call), map_skill, prepare_skill, query_skill, query_skill_mapped,
query_skill_prepared, improve_skill, add_skill, delete_skill and SKILL_D(...), in code only.  Binary-safe.  Without --apply
the plan is printed (FIX lines: lib, file, `old->new xN`); --summary prints per-lib totals.  Idempotent."""
import collections
import os
import re
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from lpc_fix_void_return import code_mask  # noqa: E402

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SKIP = re.compile(r"/(u|w|wiz|wizard|wizards|players|backup|backups|old|bak|log|data|doc|docs|example|examples|test|tmp|attic)/|[-_.](bak|old|orphaned-driver-src)/|\.(bak|BAK|old|orig)(\.lpc)?$")  # `/open/` is playable world (Taiwanese / dreamofseven-style libs), not a wizard home
SKDIR = re.compile(r"/(?:kungfu/skill|daemon/skill|skills|std/skill|adm/skill|system/skill(?:/[^/]+)*|inherit/skill|d/skills|feature/skills?)/([^/]+?)\.lpc$")
DOM = re.compile(r"/d/[^/]+/(?:skill|mjskill|skills)/([^/]+?)\.lpc$")
CALL = re.compile(rb'\b(?:set_skill|set_wugong|map_skill|prepare_skill|query_skill|query_skill_mapped|query_skill_prepared|improve_skill|add_skill|delete_skill|SKILL_D)\s*\(\s*"([A-Za-z0-9_-]+)"(?:\s*,\s*"([A-Za-z0-9_-]+)")?')

PAIRS = {
    # shnfa for shenfa, tiaji for taiji and other letters dropped, doubled, swapped or mistyped
    "shaolin-shnfa": "shaolin-shenfa", "kunlun-shnfa": "kunlun-shenfa", "tiaji-jian": "taiji-jian", "dagonforce": "dragonforce",
    "lahua-shou": "lanhua-shou", "taiji-shenfong": "taiji-shengong", "changquana": "changquan", "changqaun": "changquan",
    "chanquan": "changquan", "chang-quan": "changquan", "xinxiu-duzhang": "xingxiu-duzhang", "dabei-trike": "dabei-strike",
    "xiake-trike": "xiake-strike", "poyu-qua": "poyu-quan", "cuixi-zhang": "cuixin-zhang", "zhoangnan-zhi": "zhongnan-zhi",
    "huashen-shenfa": "huashan-shenfa", "banrou-zhang": "banruo-zhang", "xiuluao-dao": "xiuluo-dao", "jinggang-zhi": "jingang-zhi",
    "jinggang-quan": "jingang-quan", "douzhuan-xingy": "douzhuan-xingyi", "douzhuan-xiongyi": "douzhuan-xingyi",
    "canhhe-zhi": "canhe-zhi", "pudu-chang": "pudu-zhang", "jinwu-goufan": "jinwu-goufa", "weiituo-gun": "weituo-gun",
    "lognxiang-gong": "longxiang-gong", "fumotaff": "fumostaff", "huashan-jinfa": "huashan-jianfa", "jiahua-neigong": "jiaohua-neigong",
    "yujiashu": "yujianshu", "sanying-zhua": "sanyin-zhua", "qinmang-jian": "qingmang-jian", "mizong-huoquan": "mizong-houquan",
    "lingyi-sword": "liangyi-sword", "jingding-zhang": "jinding-zhang", "hanbing-mainzhang": "hanbing-mianzhang",
    "huagu-mainzhang": "huagu-mianzhang", "choushui-zhang": "chousui-zhang", "chuosui-zhang": "chousui-zhang",
    "jinyin-baiguzhao": "jiuyin-baiguzhao", "zhnetian-quan": "zhentian-quan", "tang-balde": "tang-blade", "xuanhu-balde": "xuanhu-blade",
    "stuff": "staff", "piaoxu-zhang": "piaoxue-zhang", "huntian-qiong": "huntian-qigong", "draginstrike": "dragonstrike",
    "yinsuo-jingling": "yinsuo-jinling", "mihou-froce": "mihou-force", "meimv-quanfa": "meinv-quanfa", "meimu-quanfa": "meinv-quanfa",
    "meimv-quan": "meinv-quan", "duan-yirangzhi": "duan-yiyangzhi", "chaos-steos": "chaos-steps", "baguanzhen": "baguazhen",
    "shujian-yidong": "shunjian-yidong", "qianye-sho": "qianye-shou", "fengxiao-sxinfa": "fengxiao-xinfa",
    "fanlingyi-dao": "fanliangyi-dao", "shenghuo-shenggong": "shenghuo-shengong", "shenhuo-shengong": "shenghuo-shengong",
    "qinashou": "qinnashou", "ningxie-force": "ningxue-force", "juming-leg": "jueming-leg", "houqaun": "houquan",
    "bolomiduo": "boluomiduo", "taosim": "taoism", "sheding-diaoshou": "shexing-diaoshou", "raoshirouhong": "raozhirouhong",
    "qiankun-danuoy": "qiankun-danuoyi", "posion": "poison", "mantianhuyu": "mantianhuayu", "lunhun-zhang": "lunhui-zhang",
    "literare": "literate", "juemen-gung": "juemen-gun", "jlongzhua-gong": "longzhua-gong", "henshan-sword": "hengshan-sword",
    "henshan-jian": "hengshan-jian", 
    
    "bahuangh-gong": "bahuang-gong", 
    "jinshe-chui": "jinshe-zhui", "tiangang-zhangqi": "tiangang-zhengqi", "tianzhan-zhang": "tianshan-zhang", "lingji-zhuang": "linji-zhuang",
    "beimin-shengong": "beiming-shengong", "kongming--steps": "kongming-steps",
    "qishang--quan": "qishang-quan", "jiuyin--zhengong": "jiuyin-zhengong", 
    # hyphen added or dropped, `_` for `-`
    "yan-fly": "yanfly", "kongmingquan": "kongming-quan", "dragon-step": "dragonstep", "yingzhaogong": "yingzhao-gong",
    "yange_blade": "yange-blade", "qiulinshiye": "qiulin-shiye", "taiji-force": "taijiforce", "dashouyin": "dashou-yin",
    "shenzhao-jing": "shenzhaojing", "qingping-sword": "qingpingsword", "shenkongxing": "shenkong-xing", "iceforce": "ice_force",
    "lingboweibu": "lingbo-weibu", "lingbo-weibu": "lingboweibu", "hellfire_whip": "hellfire-whip", "lotus-force": "lotusforce",
    "paiyun-zhang": "paiyunzhang", "liumai-shenjian": "liumaishenjian", "cibeidao": "cibei-dao", "qiankundanuoyi": "qiankun-danuoyi",
    "qiankun-danuoyi": "qiankundanuoyi", "cloud-staff": "cloudstaff", "yiyangzhi": "yiyang-zhi", "qingshenfa": "qingshen-fa",
    "qingfengsword": "qingfeng-sword", "moyunshou": "moyun-shou", "fumozhang": "fumo-zhang", "zhengqijue": "zhengqi-jue",
    "shenxingbaibian": "shenxing-baibian", "sanyang_shengong": "sanyang-shengong", "molianspells": "molian-spells",
    "huxing-step": "huxing-steps", "huashan_shenfa": "huashan-shenfa", "heilianforce": "heilian-force", "hama-gong": "hamagong",
    "eyesword": "eye-sword", "cuixinzhang": "cuixin-zhang", "zhaixing-gong": "zhaixinggong", "snow-step": "snowstep",
    "sevensteps": "seven-steps", "moshen-bu": "moshenbu", "huntian_qigong": "huntian-qigong", "heart_dodge": "heartdodge",
    "dangmo_axe": "dangmo-axe", "lingjian-steps": "lingjian-step", "yijin-jing": "yijinjing", "yijinjing": "yijin-jing",
    # the same skill under another transliteration
    "yunu-xinjing": "yunv-xinjing", "yunv-xinjing": "yunu-xinjing", "yunu-shenfa": "yunv-shenfa", "yunv-shenfa": "yunu-shenfa",
    "yunu-xinfa": "yunv-xinfa", "yunv-xinfa": "yunu-xinfa", "meinu-quan": "meinv-quan", "bixie-sword": "pixie-sword",
    "pixie-sword": "bixie-sword", "pixie-jian": "bixie-jian", "moshen-jianda": "moshen-jianfa", "guiyuan-tuanfa": "guiyuan-tunafa",
    "jienanzhi": "jienan-zhi", "jinggang": "jingang", "wl-shenfa": "wuliang-shenfa",
}
assert all(k != v for k, v in PAIRS.items())


def tracked():
    by = collections.defaultdict(list)
    for f in subprocess.run(["git", "ls-files", "-z", "--", "libs"], cwd=REPO, capture_output=True).stdout.split(b"\0"):
        try:
            p = f.decode("utf-8")
        except UnicodeDecodeError:
            continue
        parts = p.split("/work/", 1)
        if len(parts) == 2 and "longyunmeng_binary" not in p and p.endswith((".lpc", ".h")):
            by[p.split("/")[1]].append("/" + parts[1])
    return by


def in_code(mask, b, pos):
    if mask[pos]:
        return True
    i = pos - 1
    while i >= 0 and b[i] in b" \t\r\n":
        i -= 1
    return i >= 0 and bool(mask[i]) and b[i] not in b'"'


def main():
    args = sys.argv[1:]
    apply = "--apply" in args
    summary = "--summary" in args
    only = [a for a in args if not a.startswith("--")]
    by = tracked()
    tot = nfiles = 0
    per = collections.Counter()
    for slug in sorted(only or by):
        if slug not in by or os.path.exists(f"{REPO}/libs/{slug}/work/.git"):
            continue
        names = set()
        for rel in by[slug]:
            m = SKDIR.match(rel) or DOM.match(rel)
            if m:
                names.add(m.group(1))
        if len(names) < 20:
            continue
        use = {k: v for k, v in PAIRS.items() if k not in names and v in names}
        if not use:
            continue
        for rel in by[slug]:
            if not rel.endswith(".lpc") or SKIP.search(rel):
                continue
            full = f"{REPO}/libs/{slug}/work{rel}"
            try:
                b = open(full, "rb").read()
            except OSError:
                continue
            if b'"' not in b or not any(k.encode() in b for k in use):
                continue
            mask = None
            edits = []
            for m in CALL.finditer(b):
                if mask is None:
                    mask = code_mask(b, heredoc=True)
                if not in_code(mask, b, m.start()):
                    continue
                for g in (1, 2):
                    if m.group(g) is None:
                        continue
                    n = m.group(g).decode()
                    if n in use:
                        edits.append((m.start(g), m.end(g), use[n].encode(), n))
            if not edits:
                continue
            nfiles += 1
            tot += len(edits)
            per[slug] += len(edits)
            if not summary:
                c = collections.Counter(f"{n}->{use[n]}" for *_, n in edits)
                print(f"FIX   {slug} {rel}  " + ", ".join(f"{k} x{v}" for k, v in sorted(c.items())))
            if apply:
                out, last = [], 0
                for s, e, new, _n in sorted(edits):
                    out.append(b[last:s])
                    out.append(new)
                    last = e
                out.append(b[last:])
                open(full, "wb").write(b"".join(out))
    for slug, n in sorted(per.items()):
        print(f"LIB   {slug}: {n} name(s)")
    print(f"{tot} name(s) in {nfiles} file(s) of {len(per)} lib(s)" + ("" if apply else " (plan only; --apply writes)"))


if __name__ == "__main__":
    main()
