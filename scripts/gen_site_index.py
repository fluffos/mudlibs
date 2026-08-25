#!/usr/bin/env python3
"""Generate the GitHub Pages index for the packed mudlib site.

Inputs (all inside this repo):
  libs/<slug>/meta.json  per-lib source of truth (see AGENTS.md and
                     scripts/assemble_numbering.py's docstring for the
                     per-lib-file design rationale). The fields this
                     script reads:
                       wasm_status  playable / limited / partial /
                                    password-protected / noboot /
                                    not-mudlib / not-convertible /
                                    deprioritized / "" (not yet WASM-
                                    tested) -- mapped to the site's
                                    3-tier badge via STATUS_MAP below;
                                    entries in EXCLUDE_STATUSES (and
                                    anything with duplicate_of set, or
                                    missing libs/<slug>/config.fluffos)
                                    are left off the site entirely.
                     This script always re-runs assemble_numbering.py
                     first so scripts/lib_numbering.json (its aggregated
                     view of every meta.json) can never go stale under
                     it -- editing a lib's meta.json and re-running this
                     script is the entire update path, no separate sync
                     step to remember or forget.
  libs/<slug>/README.md  first heading = the game's Chinese name; the
                     intro paragraph directly under that heading (before
                     the first "##" subsection -- the "## 内容亮点"
                     template used since the 2026-07-25 README rewrite
                     has no standalone "简介" section anymore) = the
                     1-line description; the 「## 管理员账号 / Admin
                     account」 section = the
                     pre-seeded admin credentials (AGENTS.md §1.5: the
                     convention is fluffos / Mud@2026, but each lib's
                     README is authoritative -- a few document a variant
                     id, a passwordless login flow, or no seeded account
                     at all), shown on the card so visitors can log in
                     with wizard powers immediately.
  --commits FILE     optional lib-commits.json (slug -> {sha, date} of the
                     last commit that changed libs/<slug>, maintained by
                     scripts/update_lib_commits.py) -- rendered on each
                     card as a GitHub commit link plus a link to the
                     lib's source dir.  Omitted/missing entries just drop
                     that line from the card.

Outputs:
  scripts/lib_numbering.json  refreshed in place (see above).
  scripts/wasm_status.json  the derived slug -> status mapping, kept as a
                     build artifact for scripts/build_site.sh (which reads
                     it for the packable-slugs list) and for inspectability.
  <out>/index.html   the site index (default: site/index.html)
  <out>/robots.txt   allow-all + sitemap pointer, for search crawlers.
  <out>/sitemap.xml  the root index + every linked (non-noboot) lib's play
                     page, so search engines can discover them without
                     executing the index page's client-side search JS.
  <out>/llms.txt     a concise, hand-readable-markdown overview for LLM
                     agents/crawlers, per the llms.txt convention
                     (llmstxt.org) -- what this site is, key facts, and
                     links out (including to llms-full.txt) rather than a
                     wall of content, since an agent that wants the full
                     game list can follow that link.
  <out>/llms-full.txt  the "full" companion the llms.txt convention
                     expects: every linked lib as one markdown bullet
                     (name, slug, status, description), generated fresh
                     from the same meta.json/README data as the cards --
                     no separate list to keep in sync by hand.

Usage: python3 scripts/gen_site_index.py [--out DIR] [--commits FILE]
"""

import argparse
import html
import json
import re
import subprocess
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
REPO_URL = "https://github.com/fluffos/mudlibs"
SITE_URL = "https://mudlibs.fluffos.info"

# libs/<slug>/meta.json's wasm_status enum -> the site's 3-tier badge.
# "limited"/"password-protected" both mean "boots, but login is blocked or
# unverified" -- exactly the site's existing "受限" bucket.
STATUS_MAP = {
    "playable": "playable",
    "limited": "limited",
    "password-protected": "limited",
    "noboot": "noboot",
}
# Statuses (and "" = not yet WASM-tested) that never appear on the site:
# not-mudlib/not-convertible/deprioritized entries commonly have no
# libs/<slug>/ dir at all (see scripts/non_mudlib_meta/), and even when
# they do there is nothing confirmed playable to advertise. "partial" is
# ds386 (Dead Souls) specifically -- an English-language lib deliberately
# deprioritized per AGENTS.md §10.6 and never pushed through the WASM
# pass. It also has no libs/ds386/README.md (deliberate, since it was
# never given the standard per-lib docs pass either), which actively
# breaks the Pages build: pack_lib_for_web.sh's `sed ... README.md
# 2>/dev/null | head -1` swallows the "No such file" message, but under
# `set -euo pipefail` sed's own exit code (2, for a missing file) still
# kills the script -- the mystery "exit code 2" with no visible error in
# CI. Not a Chinese mud and not meant to be on this site anyway, so
# excluded outright rather than shipped in a "limited" state or patched
# around.
EXCLUDE_STATUSES = {"not-mudlib", "not-convertible", "deprioritized", "partial", ""}


def load_lib_numbering():
    """Refresh scripts/lib_numbering.json from every libs/<slug>/meta.json
    (see assemble_numbering.py's docstring for why that's the aggregation
    point), then load it. Doing this unconditionally on every run is what
    keeps the index from ever going stale relative to a lib's own
    meta.json -- there is no separate sync step to remember."""
    subprocess.run(
        [sys.executable, str(REPO / "scripts" / "assemble_numbering.py")],
        check=True, cwd=REPO)
    path = REPO / "scripts" / "lib_numbering.json"
    return json.loads(path.read_text(encoding="utf-8"))["libs"]


def build_status_from_meta():
    """Return the {"counts": ..., "libs": {slug: {...}}} shape the rest of
    this script expects, derived from every libs/<slug>/meta.json via
    scripts/lib_numbering.json (see module docstring)."""
    libs = {}
    for entry in load_lib_numbering():
        if entry.get("duplicate_of"):
            continue
        slug = entry["slug"]
        wasm_status = entry.get("wasm_status") or ""
        if wasm_status in EXCLUDE_STATUSES:
            continue
        if wasm_status not in STATUS_MAP:
            raise SystemExit(
                f"lib {slug}: unrecognized wasm_status {wasm_status!r} in "
                "meta.json -- add it to STATUS_MAP or EXCLUDE_STATUSES in "
                "scripts/gen_site_index.py")
        if not (REPO / "libs" / slug / "config.fluffos").is_file():
            # Declared playable/limited but nothing to actually pack --
            # skip rather than ship a dead link.
            continue
        status = STATUS_MAP[wasm_status]
        name, desc = parse_readme(slug)
        libs[slug] = {
            "name": name,
            "status": status,
            "description": desc,
            "archive": entry.get("archive", ""),
            "archive_num": entry.get("number", ""),
            "port": entry.get("port", ""),
        }
    counts = {}
    for info in libs.values():
        counts[info["status"]] = counts.get(info["status"], 0) + 1
    return {"generated_from": "libs/*/meta.json", "counts": counts, "libs": libs}


def parse_readme(slug):
    """Return (name, description) from libs/<slug>/README.md."""
    path = REPO / "libs" / slug / "README.md"
    if not path.is_file():
        return slug, ""
    text = path.read_text(encoding="utf-8")
    m = re.search(r"^#\s+(.+)$", text, re.M)
    name = m.group(1).strip() if m else slug
    desc = ""
    if m:
        # The intro paragraph sits directly under the title, before the
        # first "##" subsection (the "## 内容亮点" template used since the
        # 2026-07-25 README rewrite has no standalone "简介" section
        # anymore -- this replaces the old regex that looked for one).
        intro = text[m.end():]
        intro = re.split(r"^#", intro, maxsplit=1, flags=re.M)[0]
        for para in re.split(r"\n\s*\n", intro.strip()):
            para = re.sub(r"\s+", " ", para.replace("\n", "")).strip()
            if para:
                desc = para
                break
    return name, desc


def parse_admin(slug):
    """Return (admin_id, password) from the README's
    「## 管理员账号 / Admin account」 section (the authoritative per-lib
    record -- see module docstring).  Parsed at render time straight from
    the README (like nothing is hardcoded for name/description either).
    password is "" when the section documents a passwordless login flow
    (rendered as 无密码), None when an id parsed but no password line did
    (rendered as 密码见 README); (None, None) when no seeded account is
    recorded (e.g. nitan170911, whose MySQL-backed registration blocked
    seeding) -- the card then shows no admin line at all.

    Formats in the wild (all matched):
      - **ID**：`fluffos`                    /  - **id**: `fluffos`
      - 账号 id：`fluffos`　密码：`Mud@2026`
      - **密码 / Password**：`Mud@2026`（...）；**管理密码(wizpwd)**：`Wiz@2026`
        (first 密码 match wins: the login password is always listed first)
      - **密码 / password**: 无 ——           (no password step at all)
    """
    path = REPO / "libs" / slug / "README.md"
    if not path.is_file():
        return None, None
    text = path.read_text(encoding="utf-8")
    m = re.search(r"^##\s*管理员账号\s*/\s*Admin account\s*$(.*?)(?=^##|\Z)",
                  text, re.M | re.S)
    if not m:
        return None, None
    sec = m.group(1)
    mid = re.search(r"(?:\bid\b|ID|账号 id)[^`\n]*[:：][^`\n]*`([^`]+)`",
                    sec, re.I)
    if not mid:
        return None, None
    mpw = re.search(r"(?:密码|password)[^`\n]*[:：][^`\n]*`([^`]+)`",
                    sec, re.I)
    if mpw:
        return mid.group(1), mpw.group(1)
    if re.search(r"(?:密码|password)[^\n`]*[:：]\s*无", sec):
        return mid.group(1), ""  # documented "no password step"
    return mid.group(1), None


BADGE = {
    "playable": ("✅", "可玩", "browser 内可完整游玩"),
    "limited": ("⚠️", "受限", "可启动,但登录受限或未完整验证"),
    "noboot": ("❌", "不可启动", "无法在 WASM 驱动下启动"),
}


def load_numbers():
    """slug -> sort key from scripts/lib_numbering.json's "NNN" / "NNN-M"
    number scheme, e.g. "043-1" -> (43, 1). Duplicate-archive entries
    (duplicate_of set) never own a libs/ dir and are skipped; the first
    real entry per slug wins. Unnumbered slugs sort after all numbered
    ones, alphabetically, rather than disappearing or crashing."""
    path = REPO / "scripts" / "lib_numbering.json"
    numbers = {}
    if path.is_file():
        data = json.loads(path.read_text(encoding="utf-8"))
        for e in data["libs"]:
            if e.get("duplicate_of") or e["slug"] in numbers:
                continue
            m = re.match(r"^(\d+)(?:-(\d+))?$", e["number"])
            if m:
                numbers[e["slug"]] = (int(m.group(1)), int(m.group(2) or 0))
    return numbers


def render_index(status, commits):
    libs = status["libs"]
    counts = status["counts"]
    numbers = load_numbers()
    entries = sorted(
        libs.items(),
        key=lambda kv: (numbers.get(kv[0], (9999, 0)), kv[0]))

    # Cards contain inner links (commit / source / play), so they cannot be
    # <a> elements themselves (nested anchors are invalid HTML and browsers
    # split them apart).  Instead every card is a <div>; on linked cards the
    # title <a class="play"> is stretched over the whole card via ::after,
    # and the meta links sit above it with a higher z-index.
    cards = []
    for slug, info in entries:
        st = info["status"]
        icon, label, _ = BADGE[st]
        name = html.escape(info["name"])
        desc = html.escape(info["description"])
        linked = st != "noboot"
        title_html = (f'<a class="play" href="{slug}/">{name}</a>' if linked
                      else name)

        meta_bits = []
        admin_id, admin_pw = parse_admin(slug)
        if admin_id:
            if admin_pw:
                cred = f"{admin_id} / {admin_pw}"
            elif admin_pw == "":
                cred = f"{admin_id}(无密码)"
            else:
                cred = f"{admin_id}(密码见 README)"
            meta_bits.append(
                '<span class="admin" title="内置管理员账号——用它登录即有'
                f'巫师权限">🔑 {html.escape(cred)}</span>')
        entry = commits.get(slug)
        if entry:
            short = html.escape(entry["sha"][:7])
            day = html.escape(entry.get("date", "")[:10])
            meta_bits.append(
                f'<span>更新 <a href="{REPO_URL}/commit/'
                f'{html.escape(entry["sha"])}" title="该游戏库最近一次改动的'
                f'提交">{short}</a> {day}</span>')
        meta_bits.append(
            f'<a href="{REPO_URL}/tree/main/libs/{html.escape(slug)}" '
            'title="该游戏库的源代码目录">源码</a>')
        meta_html = ('<p class="meta">' + "\n    ".join(meta_bits) + '</p>')

        # Search should cover every field a visitor might type, not just the
        # visible slug/name/description text -- including fields that never
        # render on the card at all (original archive filename, admin id).
        # Building this as an explicit corpus (rather than relying on
        # card.textContent) means search stays correct even if the visible
        # markup changes later.
        search_bits = [
            slug, info["name"], info["description"],
            info.get("archive", ""), info.get("archive_num", ""),
            admin_id or "",
        ]
        search_corpus = html.escape(" ".join(b for b in search_bits if b).lower())

        cards.append(f"""<div class="card {st}{' linked' if linked else ''}" data-search="{search_corpus}">
  <div class="card-head">
    <h2>{title_html}</h2>
    <span class="badge {st}">{icon} {label}</span>
  </div>
  <p class="slug">{html.escape(slug)}</p>
  <p class="desc">{desc}</p>
  {meta_html}
</div>""")

    n_total = len(libs)
    n_play = counts.get("playable", 0)
    n_lim = counts.get("limited", 0)
    n_no = counts.get("noboot", 0)
    cards_html = "\n".join(cards)

    page_title = "中文 MUD 博物馆 — 浏览器直接游玩"
    meta_desc = (
        f"收藏了 {n_total} 个上世纪九十年代至今的中文 LPC MUD(泥潭)游戏库,"
        f"其中 {n_play} 款可在浏览器内通过 WebAssembly 完整游玩,无需安装、"
        "无需服务器。每款游戏都标注了预置管理员账号,登录即有巫师权限。"
        "A browser-playable archive of restored classic Chinese LPC MUD "
        "(mudlib) games, running on the FluffOS driver via WebAssembly.")
    meta_desc_attr = html.escape(meta_desc)

    return f"""<!doctype html>
<html lang="zh-CN">
<head>
<meta charset="utf-8">
<meta name="viewport" content="width=device-width, initial-scale=1">
<title>{html.escape(page_title)}</title>
<meta name="description" content="{meta_desc_attr}">
<link rel="canonical" href="{SITE_URL}/">
<link rel="alternate" type="text/plain" title="llms.txt" href="{SITE_URL}/llms.txt">
<meta property="og:type" content="website">
<meta property="og:site_name" content="中文 MUD 博物馆">
<meta property="og:title" content="{html.escape(page_title)}">
<meta property="og:description" content="{meta_desc_attr}">
<meta property="og:url" content="{SITE_URL}/">
<meta property="og:locale" content="zh_CN">
<meta name="twitter:card" content="summary">
<meta name="twitter:title" content="{html.escape(page_title)}">
<meta name="twitter:description" content="{meta_desc_attr}">
<style>
  :root {{
    --bg: #0b0e14; --fg: #d5dbe5; --dim: #6b7484; --accent: #7aa2f7;
    --panel: #11151f; --border: #232a38;
    --ok: #9ece6a; --warn: #e0af68; --bad: #f7768e;
  }}
  * {{ box-sizing: border-box; }}
  body {{
    margin: 0; background: var(--bg); color: var(--fg);
    font: 15px/1.6 -apple-system, "PingFang SC", "Microsoft YaHei",
          "Noto Sans CJK SC", sans-serif;
  }}
  .wrap {{ max-width: 1100px; margin: 0 auto; padding: 24px 16px 64px; }}
  h1 {{ font-size: 26px; margin: 8px 0 4px; color: var(--accent); }}
  .intro {{ color: var(--dim); margin: 0 0 6px; }}
  .stats {{ color: var(--dim); font-size: 13px; margin-bottom: 18px; }}
  .stats b {{ color: var(--fg); }}
  .controls {{
    display: flex; flex-wrap: wrap; gap: 8px; margin-bottom: 18px;
    position: sticky; top: 0; background: var(--bg); padding: 10px 0;
    z-index: 5; border-bottom: 1px solid var(--border);
  }}
  #q {{
    flex: 1 1 220px; background: var(--panel); border: 1px solid var(--border);
    border-radius: 8px; color: var(--fg); font: inherit; padding: 8px 12px;
    outline: none;
  }}
  #q:focus {{ border-color: var(--accent); }}
  .fbtn {{
    background: var(--panel); border: 1px solid var(--border); color: var(--fg);
    border-radius: 8px; padding: 8px 14px; font: inherit; font-size: 13px;
    cursor: pointer; white-space: nowrap;
  }}
  .fbtn.active {{ border-color: var(--accent); color: var(--accent); }}
  .grid {{
    display: grid; gap: 12px;
    grid-template-columns: repeat(auto-fill, minmax(300px, 1fr));
  }}
  .card {{
    position: relative; display: block; background: var(--panel);
    border: 1px solid var(--border); border-radius: 10px; padding: 14px 16px;
    color: inherit; transition: border-color .15s;
  }}
  .card.linked:hover {{ border-color: var(--accent); }}
  .card .play {{ color: inherit; text-decoration: none; }}
  /* stretch the title link over the whole card (see render_index) */
  .card.linked .play::after {{ content: ""; position: absolute; inset: 0; }}
  .card.noboot {{ opacity: .55; }}
  .card-head {{ display: flex; align-items: baseline; gap: 8px;
               justify-content: space-between; }}
  .card h2 {{ font-size: 16px; margin: 0; }}
  .badge {{ font-size: 12px; white-space: nowrap; }}
  .badge.playable {{ color: var(--ok); }}
  .badge.limited {{ color: var(--warn); }}
  .badge.noboot {{ color: var(--bad); }}
  .slug {{ margin: 2px 0 6px; color: var(--dim); font-size: 12px;
          font-family: Consolas, Menlo, monospace; }}
  .desc {{
    margin: 0; font-size: 13px; color: var(--fg);
    display: -webkit-box; -webkit-line-clamp: 2; -webkit-box-orient: vertical;
    overflow: hidden;
  }}
  .meta {{
    margin: 8px 0 0; font-size: 12px; color: var(--dim);
    display: flex; flex-wrap: wrap; gap: 2px 12px;
  }}
  .meta .admin {{ font-family: Consolas, Menlo, monospace; }}
  /* meta links must stay clickable above the stretched .play overlay */
  .meta a {{
    color: var(--accent); text-decoration: none;
    position: relative; z-index: 1;
  }}
  .meta a:hover {{ text-decoration: underline; }}
  footer {{ margin-top: 32px; color: var(--dim); font-size: 12px; }}
  footer a {{ color: var(--accent); }}
</style>
</head>
<body>
<div class="wrap">
  <h1>中文 MUD 博物馆</h1>
  <p class="intro">
    这里收藏了 {n_total} 个上世纪九十年代至今的中文 LPC MUD(泥潭)游戏库,
    均已修复并运行在 <a href="https://github.com/fluffos/fluffos"
    style="color:var(--accent)">FluffOS</a> 驱动上。整个驱动通过 WebAssembly
    在你的浏览器里运行 —— 点击任意一款游戏,即可像当年 telnet 泥潭一样注册、
    登录、行走江湖。无需安装,无需服务器。每张卡片还标注了预置的管理员账号
    (🔑)——用它登录即可获得巫师权限,自由探索游戏世界与代码。
  </p>
  <p class="stats">
    <b>{n_play}</b> 款可完整游玩(✅) ·
    <b>{n_lim}</b> 款可启动但登录受限(⚠️,多为依赖 query_ip_number()
    等浏览器环境缺失能力) · <b>{n_no}</b> 款暂无法启动(❌)
  </p>
  <div class="controls">
    <input id="q" type="search" placeholder="搜索游戏名 / 简介 / slug / 原始文件名 ……"
           autocomplete="off">
    <button class="fbtn active" data-f="all">全部 {n_total}</button>
    <button class="fbtn" data-f="playable">✅ 可玩 {n_play}</button>
    <button class="fbtn" data-f="limited">⚠️ 受限 {n_lim}</button>
    <button class="fbtn" data-f="noboot">❌ 不可启动 {n_no}</button>
  </div>
  <div class="grid" id="grid">
{cards_html}
  </div>
  <footer>
    源代码与修复记录:<a href="https://github.com/fluffos/mudlibs">fluffos/mudlibs</a>
    · 驱动:<a href="https://github.com/fluffos/fluffos">FluffOS</a> (WebAssembly)
    · 游戏内容版权归原作者所有,仅作历史保存用途。
  </footer>
</div>
<script>
(function () {{
  var q = document.getElementById('q');
  var cards = Array.prototype.slice.call(
      document.querySelectorAll('#grid .card'));
  var btns = Array.prototype.slice.call(document.querySelectorAll('.fbtn'));
  var filter = 'all';
  function apply() {{
    var needle = q.value.trim().toLowerCase();
    cards.forEach(function (c) {{
      var okStatus = filter === 'all' || c.classList.contains(filter);
      var hay = c.dataset.search || c.textContent.toLowerCase();
      var okText = !needle || hay.indexOf(needle) >= 0;
      c.style.display = okStatus && okText ? '' : 'none';
    }});
  }}
  q.addEventListener('input', apply);
  btns.forEach(function (b) {{
    b.addEventListener('click', function () {{
      btns.forEach(function (x) {{ x.classList.remove('active'); }});
      b.classList.add('active');
      filter = b.dataset.f;
      apply();
    }});
  }});
}})();
</script>
</body>
</html>
"""


def render_robots_txt():
    return f"""User-agent: *
Allow: /

Sitemap: {SITE_URL}/sitemap.xml
"""


def render_sitemap_xml(status):
    """Root index + every linked (non-noboot) lib's play page. noboot
    entries have no page of their own (see render_index's `linked`
    check) so they're excluded here too."""
    libs = status["libs"]
    numbers = load_numbers()
    slugs = sorted(
        (slug for slug, info in libs.items() if info["status"] != "noboot"),
        key=lambda s: (numbers.get(s, (9999, 0)), s))
    urls = [f"  <url><loc>{SITE_URL}/</loc><changefreq>weekly</changefreq></url>"]
    for slug in slugs:
        urls.append(
            f"  <url><loc>{SITE_URL}/{html.escape(slug)}/</loc>"
            "<changefreq>monthly</changefreq></url>")
    body = "\n".join(urls)
    return f"""<?xml version="1.0" encoding="UTF-8"?>
<urlset xmlns="http://www.sitemaps.org/schemas/sitemap/0.9">
{body}
</urlset>
"""


def render_llms_txt(status):
    """Concise llms.txt (llmstxt.org convention): what this is, key
    facts, and links out -- including to llms-full.txt for the
    exhaustive per-game list, rather than inlining all of it here."""
    counts = status["counts"]
    n_total = len(status["libs"])
    n_play = counts.get("playable", 0)
    n_lim = counts.get("limited", 0)
    n_no = counts.get("noboot", 0)
    return f"""# 中文 MUD 博物馆 (Chinese MUD Museum)

> A browser-playable archive of {n_total} restored classic Chinese LPC MUD (mudlib) games from the 1990s onward, running on the FluffOS driver compiled to WebAssembly -- no install, no server, click and play.

This project (fluffos/mudlibs) extracts, restores, and documents Chinese-language LPC mudlib archives -- mostly wuxia/xianxia titles, several based on Jin Yong novels -- fixing decades of bitrot (GBK/UTF-8 encoding bugs, dead code, driver incompatibilities, missing content) while preserving the original gameplay and source code. Every entry ships with a pre-seeded admin/wizard account (shown on its card, marked with 🔑) for immediate full-access exploration of the game world and its code, and a per-library NOTES.md documents every restoration change made.

## Key facts

- {n_total} total libraries: {n_play} fully playable in-browser, {n_lim} boot{'s' if n_lim == 1 else ''} but {'has' if n_lim == 1 else 'have'} a login/feature limitation (usually a missing browser-environment capability like `query_ip_number()`), {n_no} not yet bootable under WebAssembly (most still run natively).
- Driver: [FluffOS](https://github.com/fluffos/fluffos), an actively-maintained LPMud/LPC driver, compiled to WebAssembly for in-browser play.
- Language/setting: all games are Chinese-language LPC MUDs (泥潭), primarily wuxia (武侠) and xianxia (仙侠) themed.
- Source code, restoration notes (AGENTS.md), and native-driver play instructions: [github.com/fluffos/mudlibs]({REPO_URL})

## Full game list

See [llms-full.txt]({SITE_URL}/llms-full.txt) for every game: name, slug, status, and a one-line description.

## Docs

- [Project README]({REPO_URL}/blob/main/README.md)
- [FluffOS driver](https://github.com/fluffos/fluffos)
"""


def render_llms_full_txt(status):
    """The llms.txt convention's "full" companion: every linked lib as
    one markdown bullet, grouped by status. Generated fresh from the
    same meta.json/README data as the HTML cards -- no separate list to
    keep in sync by hand."""
    libs = status["libs"]
    numbers = load_numbers()

    def bullet(slug, info):
        name = info["name"]
        desc = info["description"]
        line = f"- **{name}** (`{slug}`)"
        if desc:
            line += f" — {desc}"
        return line

    sections = []
    for status_key, heading in (
        ("playable", "## Fully playable (✅)"),
        ("limited", "## Boots, login/feature limited (⚠️)"),
        ("noboot", "## Not yet bootable in-browser (❌, native-only)"),
    ):
        entries = sorted(
            ((slug, info) for slug, info in libs.items()
             if info["status"] == status_key),
            key=lambda kv: (numbers.get(kv[0], (9999, 0)), kv[0]))
        if not entries:
            continue
        lines = [heading, ""]
        lines.extend(bullet(slug, info) for slug, info in entries)
        sections.append("\n".join(lines))

    body = "\n\n".join(sections)
    return f"""# 中文 MUD 博物馆 — full game list

Companion to [llms.txt]({SITE_URL}/llms.txt). Every library in this archive, grouped by browser-playability. `noboot` entries link to nothing on the site itself (they're native-driver-only for now) but their source and restoration notes are still in the repo at `{REPO_URL}/tree/main/libs/<slug>`.

{body}
"""


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--out", default=str(REPO / "site"),
                    help="output dir for index.html (default: site/)")
    ap.add_argument("--commits", default=None,
                    help="lib-commits.json from update_lib_commits.py "
                         "(slug -> last commit that changed the lib); "
                         "omit / missing file = render without that info")
    args = ap.parse_args()

    commits = {}
    if args.commits and Path(args.commits).is_file():
        commits = json.loads(
            Path(args.commits).read_text(encoding="utf-8")).get("libs", {})

    # Status is derived fresh from every libs/<slug>/meta.json on every
    # run (see build_status_from_meta / module docstring) -- there is no
    # separate cache file to keep in sync by hand. wasm_status.json is
    # still written, as a build artifact for build_site.sh's slug list
    # and for inspectability, but it is output-only now: nothing reads
    # it back to derive status.
    status = build_status_from_meta()
    status_path = REPO / "scripts" / "wasm_status.json"
    status_path.write_text(
        json.dumps(status, ensure_ascii=False, indent=2, sort_keys=True) + "\n",
        encoding="utf-8")

    out_dir = Path(args.out)
    out_dir.mkdir(parents=True, exist_ok=True)
    (out_dir / "index.html").write_text(render_index(status, commits),
                                        encoding="utf-8")
    (out_dir / "robots.txt").write_text(render_robots_txt(), encoding="utf-8")
    (out_dir / "sitemap.xml").write_text(render_sitemap_xml(status),
                                          encoding="utf-8")
    (out_dir / "llms.txt").write_text(render_llms_txt(status), encoding="utf-8")
    (out_dir / "llms-full.txt").write_text(render_llms_full_txt(status),
                                            encoding="utf-8")

    total = len(status["libs"])
    print(f"derived from meta.json: {total} libs -> {status['counts']}")
    print(f"index written to {out_dir / 'index.html'}")
    print(f"robots.txt, sitemap.xml, llms.txt, llms-full.txt written to {out_dir}")


if __name__ == "__main__":
    main()
