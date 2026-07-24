#!/usr/bin/env python3
"""Generate lib_numbering.json + rename_archives.sh + README table fragment.

Numbering scheme: each unique game/codebase gets a sequential number
(001..058). Confirmed derivatives/variants of the same codebase share the
base number with -1/-2/-3 suffixes (lineage derived from TODO.md's own
cross-reference notes). Non-LPC / non-convertible archives get a 9xx
series. Byte-identical duplicate archive files get the same number as
their kept sibling (original filename, which differs, is preserved in the
new name).
"""
import json, os, sys, unicodedata

ROOT = "/home/sunyc/src/mudlib"
OUT = "/home/sunyc/.claude/jobs/02c1e635/tmp/docs_draft"

ws = json.load(open(os.path.join(ROOT, "scripts/wasm_status.json")))["libs"]

# (number, slug, archive_filename_exact, group_note)
# archive filename None => take from wasm_status.json
# Entries whose slug is not in wasm_status carry explicit (name, status, port).
L = [
    ("001",   "shanhaizhanshen", None, ""),
    ("002",   "xingzhanyingxiong", None, ""),
    ("003",   "unknownlib20150716", None, "xiaoyu-xiyou family base"),
    ("003-1", "xiaoyuxiyou", None, "same 小雨西游 codebase, 2013 site snapshot"),
    ("004",   "bxsj", None, "ShuJian MUD family base"),
    ("004-1", "bxsj1", None, "same 书剑 codebase (书剑·经典)"),
    ("004-2", "jinyongwenzi", None, "literal same codebase as bxsj/bxsj1 (书剑2002)"),
    ("005",   "chidi", None, ""),
    ("006",   "ds386", "ds3.8.6.zip", "English Dead Souls; deprioritized/partial"),
    ("007",   "dtsl", None, "大唐双龙 family base"),
    ("007-1", "llmud_datangshuanglong", None, "same lineage as dtsl"),
    ("007-2", "datangshuanglong", None, "related fork of dtsl/llmud lineage"),
    ("008",   "es1_win", None, "东方故事 base (蓝天)"),
    ("008-1", "esI", None, "same lineage (屠龙之战)"),
    ("009",   "fengyun434", None, "风云Ⅳ base"),
    ("009-1", "fy2005", None, "风云Ⅳ 2005 build"),
    ("010",   "xiyouji", None, "西游记/xiyouji.org family ANCESTOR snapshot (1996-98)"),
    ("010-1", "fluffos_xiyou2000", None, "西游记 2000 snapshot"),
    ("010-2", "xiyouji2003", None, "西游记2003/光辉岁月 (master.c ~= fluffos_xiyou2000)"),
    ("010-3", "xiyouji450", None, "西游记450 sibling (master.c ~= mhxy)"),
    ("010-4", "xiyouji2006", None, "西游记2006 independent fork (renamed 大唐西游)"),
    ("011",   "fy2", None, "风云再起Ⅱ base"),
    ("011-1", "fengyun2qinghua", None, "byte-identical distribution of fy2"),
    ("012",   "mhxy", None, "梦幻西游 base (Qingdao)"),
    ("012-1", "menghuanxiyou2002", None, "same codebase, 14561/14563 files identical"),
    ("013",   "xiakexing2017", None, ""),
    ("014",   "nitan170911", None, "NT/nitan lineage; branded 仙剑奇侠传"),
    ("015",   "nitan6", None, "NT/nitan lineage; branded 笑傲江湖"),
    ("016",   "rzrmud", None, ""),
    ("017",   "xkx2001", None, "侠客行 XKX base"),
    ("017-1", "beimeixiakexing2001", None, "same codebase, North America 2001 build"),
    ("018",   "xlqy_new2007", None, "仙侣情缘 XLQY base (2007)"),
    ("018-1", "xlqy_early", None, "same codebase, earlier rough snapshot"),
    ("018-2", "xianlvqingyuanzheda", None, "ZJU fork of XLQY"),
    ("019",   "xo", None, "笑傲江湖 XO/TMI-2/ES2/Falcon base (mini)"),
    ("019-1", "xo_final", None, "same lineage, full 'final' build"),
    ("019-2", "xiaoaojianghu2", None, "same XO lineage, 2003 snapshot"),
    ("019-3", "xiaoaojianghu_xo", None, "same XO lineage, third snapshot"),
    ("020",   "zzfy", None, "风云III engine base (郑州风云3)"),
    ("020-1", "fengyun3xiuding", None, "same engine core (星星修订版)"),
    ("020-2", "fengyun3dianzang", None, "byte-identical core to fengyun3xiuding"),
    ("021",   "shiji", None, ""),
    ("022",   "dongfanggushi2", None, ""),
    ("023",   "zhonghua2", None, ""),
    ("024",   "shujian2008", None, "书剑天下2008 base"),
    ("024-1", "shujiantianxia", None, "code-identical, 小熊泥苑 site branding"),
    ("025",   "shujianpiaoling2", None, ""),
    ("026",   "xianlvqiyuan", None, "distinct older 2001 XLQY codebase"),
    ("027",   "xianjianchuanqi", None, ""),
    ("028",   "xiakexinzhuan2", None, ""),
    ("029",   "xiakeyingxiong3", None, ""),
    ("030",   "xiakexing100", None, ""),
    ("031",   "jinyongqunxiazhuan2008", None, "金庸群侠传 engine base (2008 加强版)"),
    ("031-1", "jinyongqunxiazhuan2008_std", None, "same codebase, lighter content"),
    ("031-2", "jinyongqunxiazhuan2008_deluxe", None, "same engine, different content build"),
    ("031-3", "jinyongqunxiazhuan2015", None, "same engine core, 2015 content"),
    ("031-4", "xiakexing3", None, "rebrand of same codebase (master.c byte-identical)"),
    ("032",   "xiyangzaixian_fengkuang", None, "夕阳再现 base (疯狂江湖)"),
    ("032-1", "xiyangzaixian_fengyun2", None, "same family (风云再起2)"),
    ("032-2", "jianghufengyun", None, "close to family common ancestor (江湖风云单机)"),
    ("033",   "xiyangzaixian3", None, "夕阳再现III/XYZX-炎龙封印 base"),
    ("033-1", "yanlongfengyin_xiaoao3", None, "heavier fork of XYZX/YLFY engine"),
    ("033-2", "longyunmeng", None, "closely-related fork of YLFY engine (源码版)"),
    ("033-3", "longyunmeng_binary", "龙云梦-炎龙封印-二进制版.rar",
     "binary-only release of the 龙云梦 fork; NOT convertible"),
    ("034",   "tianxia", None, ""),
    ("035",   "tianxiawuxue", None, ""),
    ("036",   "xinkuangxiangkongjian2", None, "狂想空间 base (later snapshot)"),
    ("036-1", "kuangxiangkongjian", None, "same game, earlier circulated snapshot"),
    ("037",   "yueyingqiyuan", None, ""),
    ("038",   "weimingkongjian", None, "own game on 夕阳再现-derived engine"),
    ("039",   "moniHuafu", None, "own game on 风云3 engine"),
    ("040",   "wuhanzhan", None, ""),
    ("041",   "nitan_ceshi", None, "泥潭三/终极魔界 base"),
    ("041-1", "nitan_san", None, "sibling snapshot of nitan_ceshi"),
    ("042",   "yuxuechongsheng", None, ""),
    ("043",   "haiyang2", None, ""),
    ("044",   "huoying", None, ""),
    ("045",   "yanhuangwuhun", None, "yh2003 codebase base (炎黄武魂Ⅱ)"),
    ("045-1", "yanhuangyingxiongshi", None, "close-cousin sibling, own content (炎黄英雄史)"),
    ("046",   "xuanjianlu", None, "own game on XKX engine"),
    ("047",   "bixiecanyang", None, "own game on 夕阳再现-derived engine"),
    ("048",   "shenzhou", None, ""),
    ("049",   "shenmo", None, ""),
    ("050",   "xiaoaojianghu_client", None, "own game on 夕阳再现-derived engine"),
    ("051",   "zitengzhan", None, ""),
    ("052",   "zhongjidiyu", None, "unrelated to the 'hell' 终极地狱 pair despite title"),
    ("053",   "zhongjidiyu_airuoyoulan", None, "'hell'/Doing-Lu engine base"),
    ("053-1", "zhongjidiyu_zhijian", None, "same core + 指间mud mobile protocol"),
    ("054",   "xixingzhanji", None, ""),
    ("055",   "chongshengdeshijie", None, "GPLv2 BIG5 life-sim, distinct lineage"),
    ("056",   "tiexuejianghu", None, ""),
    ("057",   "suiyuanxijianlu", None, ""),
    ("058",   "mohuanshiji", None, ""),
    # --- 9xx: non-LPC / not convertible / deprioritized non-Chinese ---
    ("901",   "dw_fluffos_v1", "dw_fluffos_v1.tar.gz", "Discworld (English); deprioritized"),
    ("901-1", "dw_fluffos_v2", "dw_fluffos_v2.zip", "same Discworld bundle, later version"),
    ("901-2", "dw_fluffos_v3", "dw_fluffos_v3.zip", "same Discworld bundle, later version"),
    ("902",   "tomud_vc", "TOMud_VC源代码.rar", "Windows MFC mud CLIENT, not a mudlib"),
    ("903",   "sanguowaizhuan", "三国歪传.rar", "DikuMUD/Merc C server, not LPC"),
    ("904",   "atlantis", "消失的亞特蘭提斯MUD破解版.zip", "EnvyMud/Merc C server, not LPC"),
    ("905",   "chongchujianghu", "重出江湖.rar", "closed-source C++ engine, not LPC"),
    ("905-1", "chongchujianghu_win", "重出江湖WIN完全版.rar", "same C++ engine, WIN edition"),
    ("905-2", "chongchujianghu_linux_src", "重出江湖完整源码linunx_2.71原版.rar",
     "same C++ engine, Linux source"),
    ("906",   "mofaleidemuba", "魔法类的泥巴.rar", "compiled EmberMUD binary, not LPC"),
]

# libs with no wasm_status entry: explicit metadata
EXTRA_META = {
    "ds386": {"name": "Dead Souls 3.8.6", "status": "partial",
              "port": "40007", "archive": "ds3.8.6.zip"},
    "longyunmeng_binary": {"name": "龙云梦·炎龙封印（二进制版）", "status": "not-convertible",
                           "port": "", "archive": "龙云梦-炎龙封印-二进制版.rar"},
    "dw_fluffos_v1": {"name": "Discworld MUD lib (v1)", "status": "deprioritized", "port": "", "archive": "dw_fluffos_v1.tar.gz"},
    "dw_fluffos_v2": {"name": "Discworld MUD lib (v2)", "status": "deprioritized", "port": "", "archive": "dw_fluffos_v2.zip"},
    "dw_fluffos_v3": {"name": "Discworld MUD lib (v3)", "status": "deprioritized", "port": "", "archive": "dw_fluffos_v3.zip"},
    "tomud_vc": {"name": "TOMud VC++ 客户端源码", "status": "not-mudlib", "port": "", "archive": "TOMud_VC源代码.rar"},
    "sanguowaizhuan": {"name": "三国歪传 (Diku/Merc)", "status": "not-mudlib", "port": "", "archive": "三国歪传.rar"},
    "atlantis": {"name": "消失的亞特蘭提斯 (EnvyMud)", "status": "not-mudlib", "port": "", "archive": "消失的亞特蘭提斯MUD破解版.zip"},
    "chongchujianghu": {"name": "重出江湖 (C++ engine)", "status": "not-mudlib", "port": "", "archive": "重出江湖.rar"},
    "chongchujianghu_win": {"name": "重出江湖 WIN完全版", "status": "not-mudlib", "port": "", "archive": "重出江湖WIN完全版.rar"},
    "chongchujianghu_linux_src": {"name": "重出江湖 Linux 源码 v2.71", "status": "not-mudlib", "port": "", "archive": "重出江湖完整源码linunx_2.71原版.rar"},
    "mofaleidemuba": {"name": "魔法类的泥巴 (EmberMUD)", "status": "not-mudlib", "port": "", "archive": "魔法类的泥巴.rar"},
}

# byte-identical duplicate archive files -> slug they duplicate
DUPS = {
    "风云III典藏版 (1).rar": "fengyun3dianzang",
    "江湖风云 (1).rar": "jianghufengyun",
    "海洋II 2010 正式无错完整版下载 (1).rar": "haiyang2",
    "火影 (1).rar": "huoying",
    "狂想空间 (1).rar": "kuangxiangkongjian",
    "风云III修订版  (1).rar": "fengyun3xiuding",
    "夕阳再现-疯狂江湖(1).rar": "xiyangzaixian_fengkuang",
    "东方故事二 (1).rar": "dongfanggushi2",
    "金庸文字版 (1).exe": "jinyongwenzi",
    "风云II (清华仿写版） (1).ZIP": "fengyun2qinghua",
}

entries = []
num_by_slug = {}
for num, slug, arch, note in L:
    if slug in ws:
        meta = ws[slug]
        archive = arch or meta["archive"]
        name, status, port = meta["name"], meta["status"], meta.get("port", "")
    else:
        m = EXTRA_META[slug]
        archive = arch or m["archive"]
        name, status, port = m["name"], m["status"], m["port"]
    num_by_slug[slug] = num
    entries.append({
        "number": num, "slug": slug, "archive": archive,
        "name": name, "wasm_status": status, "port": port,
        "group_note": note, "duplicate_of": None,
    })

for dupfile, slug in DUPS.items():
    entries.append({
        "number": num_by_slug[slug], "slug": slug, "archive": dupfile,
        "name": "", "wasm_status": "", "port": "",
        "group_note": "byte-identical duplicate archive file",
        "duplicate_of": next(e["archive"] for e in entries if e["slug"] == slug),
    })

# ---- verify every archive file exists exactly, and full coverage ----
have = set(os.listdir(os.path.join(ROOT, "archives")))
want = [e["archive"] for e in entries]
missing = [a for a in want if a not in have]
extra = sorted(have - set(want))
if missing:
    print("MISSING (name mismatch, fix table):", missing); sys.exit(1)
if extra:
    print("UNCOVERED archive files:", extra); sys.exit(1)
assert len(want) == len(set(want)) == 113, len(want)

uniq = sorted({e["number"].split("-")[0] for e in entries if not e["number"].startswith("9")})
groups = {}
for e in entries:
    if e["duplicate_of"]:
        continue
    groups.setdefault(e["number"].split("-")[0], []).append(e["number"])
n_groups = sum(1 for k, v in groups.items() if len(v) > 1 and not k.startswith("9"))
print(f"unique games: {len(uniq)}; derivative groups (>=2 members, LPC): {n_groups}; "
      f"total numbered rows: {len(entries)}")

# ---- lib_numbering.json ----
out = {
    "scheme": ("NNN = one unique game/codebase; NNN-M = confirmed derivative/variant "
               "of the same codebase (lineage per TODO.md cross-reference notes, "
               "now recorded in AGENTS.md's lineage section). 9xx = non-LPC / "
               "not-convertible / deprioritized-English archives. Byte-identical "
               "duplicate archive files share their sibling's number "
               "(duplicate_of set)."),
    "unique_games": len(uniq),
    "libs": entries,
}
with open(os.path.join(OUT, "lib_numbering.json"), "w") as f:
    json.dump(out, f, ensure_ascii=False, indent=2)

# ---- rename_archives.sh ----
def quoted(s):
    return "'" + s.replace("'", "'\\''") + "'"

lines = [
    "#!/usr/bin/env bash",
    "# Rename raw archive files in archives/ to NNN[-M]_<slug>_<original-name>",
    "# so the numbering <-> lib <-> original archive reference stays close.",
    "# The FULL original filename (including its extension and any odd",
    "# spacing) is preserved verbatim after the prefix -- reversible by",
    "# stripping everything up to and including the second underscore-",
    "# delimited field (i.e. 'NNN[-M]_<slug>_').",
    "# Generated by gen_numbering.py from lib_numbering.json. DO NOT hand-edit",
    "# the pair list; regenerate instead.",
    "#",
    "# Dry-run by default. Pass --apply to actually rename.",
    "set -euo pipefail",
    'cd "$(dirname "$0")/archives" 2>/dev/null || cd archives',
    'APPLY=0; [ "${1:-}" = "--apply" ] && APPLY=1',
    "rename_one() {",
    '  local src="$1" dst="$2"',
    '  if [ ! -e "$src" ]; then',
    '    if [ -e "$dst" ]; then echo "already renamed: $dst"; return 0; fi',
    '    echo "MISSING: $src" >&2; return 1',
    "  fi",
    '  if [ "$APPLY" = 1 ]; then mv -n -- "$src" "$dst"; echo "renamed: $dst";',
    '  else echo "would rename: $src -> $dst"; fi',
    "}",
    "",
]
for e in sorted(entries, key=lambda e: (e["number"], e["archive"])):
    src = e["archive"]
    dst = f'{e["number"]}_{e["slug"]}_{src}'
    lines.append(f"rename_one {quoted(src)} {quoted(dst)}")
with open(os.path.join(OUT, "rename_archives.sh"), "w") as f:
    f.write("\n".join(lines) + "\n")
os.chmod(os.path.join(OUT, "rename_archives.sh"), 0o755)

# ---- README markdown table fragment ----
STATUS_MD = {"playable": "WASM playable", "limited": "WASM limited",
             "noboot": "WASM no-boot", "partial": "partial (native only)",
             "not-convertible": "not convertible", "deprioritized": "deprioritized",
             "not-mudlib": "not a mudlib"}
rows = ["| # | Slug | Game | Original archive | Port | WASM |",
        "|---|---|---|---|---|---|"]
for e in entries:
    if e["duplicate_of"]:
        continue
    rows.append("| {} | `{}` | {} | `{}` | {} | {} |".format(
        e["number"], e["slug"], e["name"].replace("|", "\\|"),
        e["archive"], e["port"] or "—", STATUS_MD.get(e["wasm_status"], e["wasm_status"])))
with open(os.path.join(OUT, "numbering_table.md"), "w") as f:
    f.write("\n".join(rows) + "\n")
print("wrote lib_numbering.json, rename_archives.sh, numbering_table.md")
