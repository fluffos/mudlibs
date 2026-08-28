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
  <out>/<slug>/index.html  one crawlable landing page per non-noboot lib
                     (render_lib_page): full description + rendered
                     README.md/NOTES.md as real server-rendered HTML, plus
                     a "Play Now" link to play.html (the actual WASM
                     terminal, produced separately by
                     scripts/pack_lib_for_web.sh and copied into the same
                     slug dir by build_site.sh). This is what makes a
                     game's description/restoration notes visible to
                     search crawlers and defers the multi-MB driver/data
                     download until a visitor actually clicks Play.
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
# Per-lib source ZIPs (scripts/make_source_zips.sh) live as assets on this
# GitHub Release rather than in the Pages deploy itself -- 192 libs' worth
# comes to ~2.3GB, which would roughly double the size of the already
# ~2GB WASM site if bundled in. Releases are built for large binary
# distribution and have no comparable size pressure.
RELEASE_ZIPS_URL = f"{REPO_URL}/releases/download/source-zips"

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
            # Optional per-lib English translation, hand-authored into
            # meta.json's "english_name"/"english_description" fields
            # (see [[project_curator_mandate_site_i18n_seo]] in memory --
            # this is an ongoing translation project, not expected to be
            # complete for all libs at once). render_index(lang="en")
            # falls back to the Chinese name/description when absent
            # rather than blocking the English page on 100% coverage.
            "english_name": entry.get("english_name", ""),
            "english_description": entry.get("english_description", ""),
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

# Per-language UI chrome. Card content (name/description) is a separate
# concern handled in render_index via info["english_name"]/
# info["english_description"], which fall back to the Chinese text when
# a lib's translation isn't written yet -- this dict is only the fixed
# strings around the cards (search, filters, footer, etc.), which ARE
# all translated up front since there's no per-lib data dependency.
UI = {
    "zh": {
        "html_lang": "zh-CN", "og_locale": "zh_CN",
        "page_title": "LPC MUD 博物馆 — 浏览器直接游玩",
        "site_name": "LPC MUD 博物馆", "h1": "LPC MUD 博物馆",
        "search_placeholder": "搜索游戏名 / 简介 / slug / 原始文件名 ……",
        "filter_all": "全部", "filter_playable": "✅ 可玩",
        "filter_limited": "⚠️ 受限", "filter_noboot": "❌ 不可启动",
        "badge": {"playable": "可玩", "limited": "受限", "noboot": "不可启动"},
        "admin_title": "内置管理员账号——用它登录即有巫师权限",
        "admin_nopw": "无密码", "admin_pw_readme": "密码见 README",
        "updated_label": "更新", "commit_title": "该游戏库最近一次改动的提交",
        "source_label": "源码", "source_title": "该游戏库的源代码目录",
        "download_label": "下载 ZIP", "download_title": "下载这个游戏库的独立源码压缩包（无需克隆整个仓库）",
        "footer_source": "源代码与修复记录", "footer_driver": "驱动",
        "footer_copyright": "游戏内容版权归原作者所有,仅作历史保存用途。",
        "lang_switch_label": "English", "lang_switch_href": f"{SITE_URL}/en/",
        "untranslated_suffix": "",
        "self_url": f"{SITE_URL}/",
    },
    "en": {
        "html_lang": "en", "og_locale": "en_US",
        "page_title": "LPC MUD Museum — Play Instantly in Your Browser",
        "site_name": "LPC MUD Museum", "h1": "LPC MUD Museum",
        "search_placeholder": "Search by name / description / slug / archive filename…",
        "filter_all": "All", "filter_playable": "✅ Playable",
        "filter_limited": "⚠️ Limited", "filter_noboot": "❌ Won't boot",
        "badge": {"playable": "Playable", "limited": "Limited",
                  "noboot": "Won't boot"},
        "admin_title": "Pre-seeded admin account — log in with it for full "
                        "wizard privileges",
        "admin_nopw": "no password", "admin_pw_readme": "password in README",
        "updated_label": "Updated",
        "commit_title": "Most recent commit that changed this library",
        "source_label": "Source", "source_title": "Source directory for this library",
        "download_label": "Download ZIP", "download_title": "Download a standalone source archive for this library (no need to clone the whole repo)",
        "footer_source": "Source & restoration notes", "footer_driver": "Driver",
        "footer_copyright": "Game content copyright belongs to the original "
                             "authors; preserved here for historical purposes only.",
        "lang_switch_label": "中文", "lang_switch_href": f"{SITE_URL}/",
        "untranslated_suffix": " (untranslated — showing original Chinese)",
        "self_url": f"{SITE_URL}/en/",
    },
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


# Longer prose blocks that don't fit the flat UI dict (they interpolate
# per-page counts, and read more naturally as full paragraphs than as
# reassembled fragments). {n_total}/{n_play}/{n_lim}/{n_no} are filled in
# by render_index via str.format.
INTRO = {
    "zh": (
        "    这里收藏了 {n_total} 个上世纪九十年代至今的 LPC MUD(泥潭)游戏库,\n"
        "    以中文武侠/仙侠题材为主,也收录了 Dead Souls、Discworld 等几款\n"
        '    经典英文 mudlib。均已修复并运行在 <a href="https://github.com/fluffos/fluffos"\n'
        "    style=\"color:var(--accent)\">FluffOS</a> 驱动上。整个驱动通过 WebAssembly\n"
        "    在你的浏览器里运行 —— 点击任意一款游戏,即可像当年 telnet 泥潭一样注册、\n"
        "    登录、行走江湖。无需安装,无需服务器。每张卡片还标注了预置的管理员账号\n"
        "    (🔑)——用它登录即可获得巫师权限,自由探索游戏世界与代码。"
    ),
    "en": (
        "    This is an archive of {n_total} classic LPC MUD (mudlib) games dating\n"
        "    back to the 1990s — mostly Chinese-language wuxia/xianxia titles, plus a\n"
        "    handful of landmark English-language mudlibs like Dead Souls and\n"
        '    Discworld — restored and running on the\n'
        '    <a href="https://github.com/fluffos/fluffos" style="color:var(--accent)">FluffOS</a>\n'
        "    driver. The whole driver runs in your browser via WebAssembly — click any\n"
        "    game and register, log in, and explore the world exactly as players did\n"
        "    over telnet decades ago. No install, no server. Every card lists a\n"
        "    pre-seeded admin account (🔑) for immediate wizard-level access to the\n"
        "    game world and its source."
    ),
}
STATS = {
    "zh": (
        "    <b>{n_play}</b> 款可完整游玩(✅) ·\n"
        "    <b>{n_lim}</b> 款可启动但登录受限(⚠️,多为依赖 query_ip_number()\n"
        "    等浏览器环境缺失能力) · <b>{n_no}</b> 款暂无法启动(❌)"
    ),
    "en": (
        "    <b>{n_play}</b> fully playable (✅) ·\n"
        "    <b>{n_lim}</b> boot but have a login/feature limitation (⚠️, usually a\n"
        "    missing browser-environment capability like query_ip_number()) ·\n"
        "    <b>{n_no}</b> not yet bootable in-browser (❌)"
    ),
}
FOOTER = {
    "zh": (
        '    源代码与修复记录:<a href="https://github.com/fluffos/mudlibs">fluffos/mudlibs</a>\n'
        '    · 驱动:<a href="https://github.com/fluffos/fluffos">FluffOS</a> (WebAssembly)\n'
        "    · 游戏内容版权归原作者所有,仅作历史保存用途。"
    ),
    "en": (
        '    Source & restoration notes: <a href="https://github.com/fluffos/mudlibs">fluffos/mudlibs</a>\n'
        '    · Driver: <a href="https://github.com/fluffos/fluffos">FluffOS</a> (WebAssembly)\n'
        "    · Game content copyright belongs to the original authors; preserved here for historical purposes only."
    ),
}


def build_jsonld(status, lang, ui, numbers, canonical_url=None):
    """schema.org structured data: a WebSite wrapping an ItemList of
    every linked (non-noboot) game as a VideoGame entry. This is the
    machine-readable twin of the human-facing cards -- search engines
    and LLM agents that parse JSON-LD get clean, unambiguous entity
    data (name/description/URL/genre) without needing to parse the
    card markup or run the page's search JS. Kept lean (no images/
    ratings/etc that don't exist) rather than padded out with
    schema.org fields this project has no real data for."""
    libs = status["libs"]
    entries = sorted(
        ((slug, info) for slug, info in libs.items() if info["status"] != "noboot"),
        key=lambda kv: (numbers.get(kv[0], (9999, 0)), kv[0]))
    items = []
    for i, (slug, info) in enumerate(entries, start=1):
        if lang == "en":
            name = info.get("english_name") or info["name"]
            desc = info.get("english_description") or info["description"]
        else:
            name = info["name"]
            desc = info["description"]
        items.append({
            "@type": "ListItem",
            "position": i,
            "item": {
                "@type": "VideoGame",
                "name": name,
                "description": desc,
                "url": f"{SITE_URL}/{slug}/",
                "genre": ["MUD", "Text Adventure", "RPG"],
                "gamePlatform": "Web browser (WebAssembly)",
                "playMode": "MultiPlayer",
                "inLanguage": "zh-CN",
                "isAccessibleForFree": True,
            },
        })
    doc = {
        "@context": "https://schema.org",
        "@graph": [
            {
                "@type": "WebSite",
                "name": ui["site_name"],
                "url": canonical_url or ui["self_url"],
                "description": (info["description"] if False else None),
                "inLanguage": ui["html_lang"],
                "isAccessibleForFree": True,
            },
            {
                "@type": "ItemList",
                "name": ui["h1"],
                "numberOfItems": len(items),
                "itemListElement": items,
            },
        ],
    }
    # drop the placeholder None (kept the key above only for readability
    # while writing this; schema.org tolerates a missing description)
    doc["@graph"][0].pop("description", None)
    return json.dumps(doc, ensure_ascii=False).replace("</", "<\\/")


def _is_cjk_name(name):
    """True if a lib's native `name` contains CJK script -- used to boost
    English-original libs to the top of the /en/ page (an English visitor
    shouldn't have to scroll past ~190 Chinese-titled cards first). The zh
    page's own order is untouched; this only ever affects lang="en"."""
    return any("一" <= ch <= "鿿" for ch in name)


def _escape_md_html(s):
    return s.replace("&", "&amp;").replace("<", "&lt;").replace(">", "&gt;")


def _render_inline_md(s):
    s = re.sub(r"`([^`]+)`", r"<code>\1</code>", s)
    s = re.sub(r"\*\*([^*]+)\*\*", r"<strong>\1</strong>", s)
    s = re.sub(r"\[([^\]]+)\]\(([^)]+)\)",
                r'<a href="\2" target="_blank" rel="noopener">\1</a>', s)
    return s


def render_markdown_html(md):
    """Python port of renderMarkdown()/renderInline() in
    scripts/web_shell_override/index.html -- same regexes, same
    escape-first order, so a lib's README.md/NOTES.md render identically
    whether fetched client-side into the play page's Info tab or
    server-side rendered here into the crawlable landing page (see
    render_lib_page). Keep the two in sync if either changes."""
    lines = _escape_md_html(md).split("\n")
    out = []
    i = 0
    n = len(lines)
    list_open = False

    def close_list():
        nonlocal list_open
        if list_open:
            out.append("</ul>")
            list_open = False

    while i < n:
        line = lines[i]
        if re.match(r"^```", line):
            close_list()
            buf = []
            i += 1
            while i < n and not re.match(r"^```", lines[i]):
                buf.append(lines[i])
                i += 1
            out.append("<pre><code>" + "\n".join(buf) + "</code></pre>")
            i += 1
            continue
        heading = re.match(r"^(#{1,3})\s+(.*)$", line)
        if heading:
            close_list()
            level = len(heading.group(1))
            out.append(f"<h{level}>{_render_inline_md(heading.group(2))}</h{level}>")
            i += 1
            continue
        if re.match(r"^---+\s*$", line):
            close_list()
            out.append("<hr>")
            i += 1
            continue
        quote = re.match(r"^&gt;\s?(.*)$", line)
        if quote:
            close_list()
            out.append(f"<blockquote>{_render_inline_md(quote.group(1))}</blockquote>")
            i += 1
            continue
        item = re.match(r"^[-*]\s+(.*)$", line)
        if item:
            if not list_open:
                out.append("<ul>")
                list_open = True
            buf = [item.group(1)]
            i += 1
            while (i < n and re.match(r"^\s+\S", lines[i])
                   and not re.match(
                       r"^\s*[-*]\s|^\s*(#{1,3})\s|^\s*```|^\s*&gt;\s?|^\s*---+\s*$",
                       lines[i])):
                buf.append(lines[i].strip())
                i += 1
            out.append(f"<li>{_render_inline_md(' '.join(buf))}</li>")
            continue
        if line.strip() == "":
            close_list()
            i += 1
            continue
        close_list()
        buf = [line]
        i += 1
        while (i < n and lines[i].strip() != ""
               and not re.match(r"^(#{1,3})\s|^```|^[-*]\s|^&gt;\s?|^---+\s*$", lines[i])):
            buf.append(lines[i])
            i += 1
        out.append(f"<p>{_render_inline_md(chr(10).join(buf))}</p>")
    close_list()
    return "".join(out)


def build_meta_bits(slug, info, ui, commits, linked):
    """The admin-credential / updated-commit / source / download-zip line
    shared by both the index card (render_index) and the per-lib landing
    page (render_lib_page). Returns (meta_bits_html_list, admin_id) --
    callers that also need admin_id for their own search corpus (only
    render_index does) get it back rather than re-parsing the README."""
    meta_bits = []
    admin_id, admin_pw = parse_admin(slug)
    if admin_id:
        if admin_pw:
            cred = f"{admin_id} / {admin_pw}"
        elif admin_pw == "":
            cred = f"{admin_id}({ui['admin_nopw']})"
        else:
            cred = f"{admin_id}({ui['admin_pw_readme']})"
        meta_bits.append(
            f'<span class="admin" title="{ui["admin_title"]}">'
            f'🔑 {html.escape(cred)}</span>')
    entry = commits.get(slug)
    if entry:
        short = html.escape(entry["sha"][:7])
        day = html.escape(entry.get("date", "")[:10])
        meta_bits.append(
            f'<span>{ui["updated_label"]} <a href="{REPO_URL}/commit/'
            f'{html.escape(entry["sha"])}" title="{ui["commit_title"]}"'
            f'>{short}</a> {day}</span>')
    meta_bits.append(
        f'<a href="{REPO_URL}/tree/main/libs/{html.escape(slug)}" '
        f'title="{ui["source_title"]}">{ui["source_label"]}</a>')
    if linked:
        meta_bits.append(
            f'<a href="{RELEASE_ZIPS_URL}/{html.escape(slug)}.zip" '
            f'title="{ui["download_title"]}">{ui["download_label"]}</a>')
    return meta_bits, admin_id


def render_lib_page(slug, info, commits):
    """Full, server-side-rendered, crawlable landing page for one lib,
    served at /{slug}/ (see build_site.sh's assembly step). This is what
    fixes the site's core SEO problem: /{slug}/ used to serve straight
    to the WASM play page, which unconditionally boots the driver on
    load (createFluffOS(Module).then(...) in
    scripts/web_shell_override/index.html) -- fine for a visitor who
    already wants to play, useless to a crawler and unfriendly to a
    visitor who just wants to read about the game first. This page is
    plain HTML (full description + rendered README/NOTES.md, real text
    in the first response, no JS/driver download required) with a
    single "Play Now" link to the WASM page, relocated to play.html by
    pack_lib_for_web.sh."""
    st = info["status"]
    icon, label, _ = BADGE[st]
    ui_zh = UI["zh"]
    meta_bits, _ = build_meta_bits(slug, info, ui_zh, commits, True)
    meta_html = '<p class="meta">' + "\n    ".join(meta_bits) + '</p>'

    name = html.escape(info["name"])
    name_en = info.get("english_name") or ""
    title_bits = name
    if name_en and name_en != info["name"]:
        title_bits += f" ({html.escape(name_en)})"

    desc = info["description"]
    desc_en = info.get("english_description") or ""
    desc_html = f'<p class="desc">{html.escape(desc)}</p>' if desc else ""
    if desc_en and desc_en != desc:
        desc_html += f'<h2>English</h2>\n  <p class="desc">{html.escape(desc_en)}</p>'

    doc_sections = []
    readme_path = REPO / "libs" / slug / "README.md"
    if readme_path.is_file():
        text = readme_path.read_text(encoding="utf-8").strip()
        # Drop the leading "# Name" heading -- this page already has its
        # own <h1> with the game name, so keeping README's own would
        # just double it.
        text = re.sub(r"^#[^\n]*\n?", "", text, count=1).strip()
        if text:
            doc_sections.append(
                f'<section class="doc"><h2>README</h2>{render_markdown_html(text)}</section>')
    notes_path = REPO / "libs" / slug / "NOTES.md"
    if notes_path.is_file():
        text = notes_path.read_text(encoding="utf-8").strip()
        if text:
            doc_sections.append(
                '<section class="doc"><h2>NOTES · 移植与修复记录</h2>'
                f'{render_markdown_html(text)}</section>')
    docs_html = "\n".join(doc_sections)

    canonical_url = f"{SITE_URL}/{slug}/"
    meta_desc_attr = html.escape((desc or desc_en or info["name"])[:300])

    jsonld_doc = {
        "@context": "https://schema.org",
        "@type": "VideoGame",
        "name": info.get("english_name") or info["name"],
        "alternateName": info["name"] if info.get("english_name") else None,
        "description": desc_en or desc,
        "url": canonical_url,
        "genre": ["MUD", "Text Adventure", "RPG"],
        "gamePlatform": "Web browser (WebAssembly)",
        "playMode": "MultiPlayer",
        "inLanguage": "zh-CN",
        "isAccessibleForFree": True,
    }
    jsonld_doc = {k: v for k, v in jsonld_doc.items() if v is not None}
    jsonld = json.dumps(jsonld_doc, ensure_ascii=False).replace("</", "<\\/")

    site_name = html.escape(ui_zh["site_name"])
    return f"""<!doctype html>
<html lang="zh-CN">
<head>
<meta charset="utf-8">
<meta name="viewport" content="width=device-width, initial-scale=1">
<title>{title_bits} — {site_name}</title>
<meta name="description" content="{meta_desc_attr}">
<meta name="robots" content="index, follow">
<link rel="canonical" href="{canonical_url}">
<meta property="og:type" content="website">
<meta property="og:site_name" content="{site_name}">
<meta property="og:title" content="{title_bits}">
<meta property="og:description" content="{meta_desc_attr}">
<meta property="og:url" content="{canonical_url}">
<meta name="twitter:card" content="summary">
<meta name="twitter:title" content="{title_bits}">
<meta name="twitter:description" content="{meta_desc_attr}">
<script type="application/ld+json">{jsonld}</script>
<style>
  :root {{
    --bg: #0b0e14; --fg: #d5dbe5; --dim: #6b7484; --accent: #7aa2f7;
    --panel: #11151f; --border: #232a38;
    --ok: #9ece6a; --warn: #e0af68; --bad: #f7768e;
  }}
  * {{ box-sizing: border-box; }}
  body {{
    margin: 0; background: var(--bg); color: var(--fg);
    font: 15px/1.7 -apple-system, "PingFang SC", "Microsoft YaHei",
          "Noto Sans CJK SC", sans-serif;
  }}
  .wrap {{ max-width: 800px; margin: 0 auto; padding: 24px 16px 64px; }}
  .back a {{ color: var(--accent); text-decoration: none; font-size: 13px; }}
  .back a:hover {{ text-decoration: underline; }}
  .head {{ display: flex; align-items: baseline; gap: 10px; flex-wrap: wrap;
           margin-top: 14px; }}
  h1 {{ font-size: 26px; margin: 0; color: var(--accent); }}
  .badge {{ font-size: 13px; white-space: nowrap; }}
  .badge.playable {{ color: var(--ok); }}
  .badge.limited {{ color: var(--warn); }}
  .badge.noboot {{ color: var(--bad); }}
  .slug {{ margin: 4px 0 10px; color: var(--dim); font-size: 12px;
          font-family: Consolas, Menlo, monospace; }}
  .meta {{ margin: 0 0 18px; font-size: 13px; color: var(--dim);
          display: flex; flex-wrap: wrap; gap: 4px 14px; }}
  .meta .admin {{ font-family: Consolas, Menlo, monospace; }}
  .meta a {{ color: var(--accent); text-decoration: none; }}
  .meta a:hover {{ text-decoration: underline; }}
  .play-cta {{ margin: 0 0 22px; }}
  .play-btn {{
    display: inline-block; background: var(--accent); color: #0b0e14;
    font-weight: 600; text-decoration: none; padding: 12px 26px;
    border-radius: 8px; font-size: 16px;
  }}
  .play-btn:hover {{ opacity: .9; }}
  .desc {{ font-size: 15px; line-height: 1.7; }}
  h2 {{ font-size: 19px; margin: 28px 0 10px; color: var(--fg);
       border-bottom: 1px solid var(--border); padding-bottom: 6px; }}
  section.doc h2:first-child {{ margin-top: 8px; }}
  .doc p {{ margin: 0 0 12px; }}
  .doc ul {{ margin: 0 0 12px; padding-left: 22px; }}
  .doc li {{ margin: 4px 0; }}
  .doc pre {{ background: var(--panel); border: 1px solid var(--border);
             border-radius: 6px; padding: 10px 12px; overflow-x: auto; }}
  .doc code {{ font-family: Consolas, Menlo, monospace; font-size: 13px; }}
  .doc blockquote {{ margin: 0 0 12px; padding: 4px 14px; color: var(--dim);
                     border-left: 3px solid var(--border); }}
  .doc hr {{ border: none; border-top: 1px solid var(--border); margin: 20px 0; }}
  .doc a {{ color: var(--accent); }}
  footer {{ margin-top: 40px; color: var(--dim); font-size: 12px; }}
  footer a {{ color: var(--accent); }}
</style>
</head>
<body>
<div class="wrap">
  <p class="back"><a href="/">← {site_name} / LPC MUD Museum</a></p>
  <div class="head">
    <h1>{title_bits}</h1>
    <span class="badge {st}">{icon} {html.escape(label)}</span>
  </div>
  <p class="slug">{html.escape(slug)}</p>
  {meta_html}
  <p class="play-cta"><a class="play-btn" href="play.html">▶ 开始游玩 · Play Now</a></p>
  {desc_html}
  {docs_html}
  <footer>
{FOOTER['zh']}
  </footer>
</div>
</body>
</html>
"""


def render_index(status, commits, lang="zh", canonical_url=None):
    ui = UI[lang]
    libs = status["libs"]
    counts = status["counts"]
    numbers = load_numbers()
    # canonical_url lets a caller render this same page's content at a
    # second URL (e.g. /cn/ mirroring /) without it competing with the
    # real canonical URL for search ranking -- rel=canonical/og:url point
    # back at canonical_url while hreflang still references the real zh/en
    # canonical pair, so crawlers consolidate signal onto one URL per lang.
    canonical_url = canonical_url or ui["self_url"]
    if lang == "en":
        # English-original libs (native name has no CJK) first, each group
        # keeping the existing catalog-number order within itself.
        entries = sorted(
            libs.items(),
            key=lambda kv: (
                _is_cjk_name(kv[1]["name"]),
                numbers.get(kv[0], (9999, 0)),
                kv[0],
            ))
    else:
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
        icon = BADGE[st][0]
        label = ui["badge"][st]
        if lang == "en":
            name_src = info.get("english_name") or info["name"]
            desc_src = info.get("english_description") or info["description"]
            desc_suffix = "" if info.get("english_description") else ui["untranslated_suffix"]
        else:
            name_src = info["name"]
            desc_src = info["description"]
            desc_suffix = ""
        name = html.escape(name_src)
        desc = html.escape(desc_src) + html.escape(desc_suffix)
        linked = st != "noboot"
        # Absolute (site-root-relative) path -- the en page is served from
        # /en/, so a plain "{slug}/" relative href would resolve to
        # /en/{slug}/ (404) instead of the real play page at /{slug}/.
        title_html = (f'<a class="play" href="/{slug}/">{name}</a>' if linked
                      else name)

        meta_bits, admin_id = build_meta_bits(slug, info, ui, commits, linked)
        meta_html = ('<p class="meta">' + "\n    ".join(meta_bits) + '</p>')

        # Search should cover every field a visitor might type, not just the
        # visible slug/name/description text -- including fields that never
        # render on the card at all (original archive filename, admin id,
        # and -- on the English page -- both the Chinese AND English name/
        # description, so a visitor typing either language finds the card).
        search_bits = [
            slug, info["name"], info["description"],
            info.get("english_name", ""), info.get("english_description", ""),
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

    page_title = ui["page_title"]
    if lang == "en":
        meta_desc = (
            f"A browser-playable archive of {n_total} restored classic "
            f"LPC MUD (mudlib) games from the 1990s onward -- mostly "
            f"Chinese-language, plus landmark English mudlibs like Dead "
            f"Souls and Discworld -- {n_play} of them fully playable via "
            "WebAssembly -- no install, no server. Every game lists a "
            "pre-seeded admin account for instant wizard access.")
    else:
        meta_desc = (
            f"收藏了 {n_total} 个上世纪九十年代至今的 LPC MUD(泥潭)游戏库,"
            f"以中文游戏为主,也收录了 Dead Souls、Discworld 等经典英文 mudlib,"
            f"其中 {n_play} 款可在浏览器内通过 WebAssembly 完整游玩,无需安装、"
            "无需服务器。每款游戏都标注了预置管理员账号,登录即有巫师权限。"
            "A browser-playable archive of restored classic LPC MUD "
            "(mudlib) games, running on the FluffOS driver via WebAssembly.")
    meta_desc_attr = html.escape(meta_desc)

    other = "en" if lang == "zh" else "zh"
    jsonld = build_jsonld(status, lang, ui, numbers, canonical_url=canonical_url)

    return f"""<!doctype html>
<html lang="{ui['html_lang']}">
<head>
<meta charset="utf-8">
<meta name="viewport" content="width=device-width, initial-scale=1">
<title>{html.escape(page_title)}</title>
<meta name="description" content="{meta_desc_attr}">
<meta name="robots" content="index, follow">
<link rel="canonical" href="{canonical_url}">
<link rel="alternate" hreflang="zh-CN" href="{UI['zh']['self_url']}">
<link rel="alternate" hreflang="en" href="{UI['en']['self_url']}">
<link rel="alternate" hreflang="x-default" href="{UI['zh']['self_url']}">
<link rel="alternate" type="text/plain" title="llms.txt" href="{SITE_URL}/llms.txt">
<link rel="alternate" type="application/json" title="games.json" href="{SITE_URL}/games.json">
<meta property="og:type" content="website">
<meta property="og:site_name" content="{html.escape(ui['site_name'])}">
<meta property="og:title" content="{html.escape(page_title)}">
<meta property="og:description" content="{meta_desc_attr}">
<meta property="og:url" content="{canonical_url}">
<meta property="og:locale" content="{ui['og_locale']}">
<meta name="twitter:card" content="summary">
<meta name="twitter:title" content="{html.escape(page_title)}">
<meta name="twitter:description" content="{meta_desc_attr}">
<script type="application/ld+json">{jsonld}</script>
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
  .lang-switch {{
    position: absolute; top: 24px; right: 16px; font-size: 13px;
  }}
  .lang-switch a {{ color: var(--accent); text-decoration: none; }}
  .lang-switch a:hover {{ text-decoration: underline; }}
  .wrap {{ position: relative; }}
</style>
</head>
<body>
<div class="wrap">
  <p class="lang-switch"><a href="{ui['lang_switch_href']}">{html.escape(ui['lang_switch_label'])}</a></p>
  <h1>{html.escape(ui['h1'])}</h1>
  <p class="intro">
{INTRO[lang].format(n_total=n_total)}
  </p>
  <p class="stats">
{STATS[lang].format(n_play=n_play, n_lim=n_lim, n_no=n_no)}
  </p>
  <div class="controls">
    <input id="q" type="search" placeholder="{html.escape(ui['search_placeholder'])}"
           autocomplete="off">
    <button class="fbtn active" data-f="all">{html.escape(ui['filter_all'])} {n_total}</button>
    <button class="fbtn" data-f="playable">{html.escape(ui['filter_playable'])} {n_play}</button>
    <button class="fbtn" data-f="limited">{html.escape(ui['filter_limited'])} {n_lim}</button>
    <button class="fbtn" data-f="noboot">{html.escape(ui['filter_noboot'])} {n_no}</button>
  </div>
  <div class="grid" id="grid">
{cards_html}
  </div>
  <footer>
{FOOTER[lang]}
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


def render_games_json(status, commits):
    """The structured-data twin of llms-full.txt: every linked
    (non-noboot) game as a clean JSON object, one fetch away from the
    whole catalog -- no HTML parsing, no JS execution required. This is
    the same data the cards/llms-full.txt render from, just in the
    shape an LLM agent or script would actually want to consume."""
    libs = status["libs"]
    numbers = load_numbers()
    entries = sorted(
        ((slug, info) for slug, info in libs.items() if info["status"] != "noboot"),
        key=lambda kv: (numbers.get(kv[0], (9999, 0)), kv[0]))
    games = []
    for slug, info in entries:
        admin_id, admin_pw = parse_admin(slug)
        entry = commits.get(slug)
        games.append({
            "slug": slug,
            "name": info["name"],
            "english_name": info.get("english_name") or None,
            "description": info["description"],
            "english_description": info.get("english_description") or None,
            "status": info["status"],
            "url": f"{SITE_URL}/{slug}/",
            "source_url": f"{REPO_URL}/tree/main/libs/{slug}",
            "source_zip_url": f"{RELEASE_ZIPS_URL}/{slug}.zip",
            "admin_id": admin_id,
            "admin_password": admin_pw,
            "last_changed_commit": entry.get("sha") if entry else None,
            "last_changed_date": entry.get("date") if entry else None,
        })
    doc = {
        "generated_from": "libs/*/meta.json + libs/*/README.md",
        "site": SITE_URL,
        "repo": REPO_URL,
        "count": len(games),
        "games": games,
    }
    return json.dumps(doc, ensure_ascii=False, indent=2) + "\n"


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
    urls = [
        f"  <url><loc>{SITE_URL}/</loc><changefreq>weekly</changefreq></url>",
        f"  <url><loc>{SITE_URL}/en/</loc><changefreq>weekly</changefreq></url>",
    ]
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
    return f"""# LPC MUD 博物馆 (LPC MUD Museum)

> A browser-playable archive of {n_total} restored classic LPC MUD (mudlib) games from the 1990s onward, running on the FluffOS driver compiled to WebAssembly -- no install, no server, click and play.

This project (fluffos/mudlibs) extracts, restores, and documents LPC mudlib archives -- mostly Chinese-language wuxia/xianxia titles, several based on Jin Yong novels, plus a growing set of landmark English-language mudlibs (Dead Souls, Discworld, and others) -- fixing decades of bitrot (GBK/UTF-8 encoding bugs, dead code, driver incompatibilities, missing content) while preserving the original gameplay and source code. Every entry ships with a pre-seeded admin/wizard account (shown on its card, marked with 🔑) for immediate full-access exploration of the game world and its code, and a per-library NOTES.md documents every restoration change made.

## Key facts

- {n_total} total libraries: {n_play} fully playable in-browser, {n_lim} boot{'s' if n_lim == 1 else ''} but {'has' if n_lim == 1 else 'have'} a login/feature limitation (usually a missing browser-environment capability like `query_ip_number()`), {n_no} not yet bootable under WebAssembly (most still run natively).
- Driver: [FluffOS](https://github.com/fluffos/fluffos), an actively-maintained LPMud/LPC driver, compiled to WebAssembly for in-browser play.
- Language/setting: mostly Chinese-language LPC MUDs (泥潭), primarily wuxia (武侠) and xianxia (仙侠) themed, plus several classic English-language mudlib codebases (Dead Souls, Discworld, Nightmare, Lima). Every game card and description exists in both Chinese ({SITE_URL}/) and English ({SITE_URL}/en/) -- this is a fully bilingual site.
- Source code, restoration notes (AGENTS.md), and native-driver play instructions: [github.com/fluffos/mudlibs]({REPO_URL})
- Each game also has a standalone downloadable source ZIP (trimmed source tree, no need to clone the whole repo) linked from its card and from games.json's `source_zip_url` field, hosted as GitHub Release assets at {RELEASE_ZIPS_URL}/<slug>.zip

## Full game list

- [llms-full.txt]({SITE_URL}/llms-full.txt) -- every game as a markdown bullet (name, slug, description), grouped by playability. Best for reading.
- [games.json]({SITE_URL}/games.json) -- the same catalog as structured JSON (slug, name, english_name, description, english_description, status, url, admin credentials, last-changed commit). Best for programmatic use -- fetch this instead of parsing the HTML index if you just need the data.

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
    return f"""# LPC MUD 博物馆 — full game list

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
    (out_dir / "index.html").write_text(render_index(status, commits, lang="zh"),
                                        encoding="utf-8")
    en_dir = out_dir / "en"
    en_dir.mkdir(parents=True, exist_ok=True)
    (en_dir / "index.html").write_text(render_index(status, commits, lang="en"),
                                        encoding="utf-8")
    # /cn/ mirrors / (an explicit Chinese-language path, requested
    # alongside /en/) -- same content, but its canonical/og:url/JSON-LD
    # point back at the real / so search engines consolidate ranking
    # signal onto one URL instead of treating /cn/ as duplicate content.
    cn_dir = out_dir / "cn"
    cn_dir.mkdir(parents=True, exist_ok=True)
    (cn_dir / "index.html").write_text(
        render_index(status, commits, lang="zh",
                     canonical_url=f"{SITE_URL}/"),
        encoding="utf-8")
    # Per-lib landing pages (see render_lib_page docstring) -- one per
    # non-noboot lib, at <out>/<slug>/index.html. build_site.sh's
    # assembly step copies this alongside the WASM bundle (play.html
    # etc) that pack_lib_for_web.sh produces under the same slug dir, so
    # /{slug}/ serves this crawlable page and /{slug}/play.html is the
    # actual game, reached only via this page's "Play Now" link.
    n_landing = 0
    for slug, info in status["libs"].items():
        if info["status"] == "noboot":
            continue
        lib_dir = out_dir / slug
        lib_dir.mkdir(parents=True, exist_ok=True)
        (lib_dir / "index.html").write_text(
            render_lib_page(slug, info, commits), encoding="utf-8")
        n_landing += 1
    print(f"per-lib landing pages: {n_landing} written under {out_dir}/<slug>/index.html")

    (out_dir / "robots.txt").write_text(render_robots_txt(), encoding="utf-8")
    (out_dir / "sitemap.xml").write_text(render_sitemap_xml(status),
                                          encoding="utf-8")
    llms_txt = render_llms_txt(status)
    (out_dir / "llms.txt").write_text(llms_txt, encoding="utf-8")
    # "llm.txt" (singular) as an alias -- the established convention
    # (llmstxt.org) is "llms.txt", but some tooling/crawlers check the
    # singular form; serving both costs nothing and only helps discovery.
    (out_dir / "llm.txt").write_text(llms_txt, encoding="utf-8")
    (out_dir / "llms-full.txt").write_text(render_llms_full_txt(status),
                                            encoding="utf-8")
    (out_dir / "games.json").write_text(render_games_json(status, commits),
                                         encoding="utf-8")

    n_translated = sum(1 for info in status["libs"].values()
                        if info.get("english_description"))
    total = len(status["libs"])
    print(f"derived from meta.json: {total} libs -> {status['counts']}")
    print(f"index written to {out_dir / 'index.html'} (zh) and {en_dir / 'index.html'} (en)")
    print(f"english translations: {n_translated}/{total} libs have a real "
          "english_description (rest fall back to Chinese on the EN page)")
    print(f"robots.txt, sitemap.xml, llms.txt, llm.txt, llms-full.txt, "
          f"games.json written to {out_dir}")


if __name__ == "__main__":
    main()
