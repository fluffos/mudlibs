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
                     scripts/write_play_page.sh straight into the same
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
  <out>/<slug>/llms.txt  per-lib LLM runbook (download ZIP + native
                     FluffOS run steps + admin/port + play URL).
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
OG_IMAGE_URL = f"{SITE_URL}/og-image.png"
FAVICON_ICO_URL = f"{SITE_URL}/favicon.ico"
FAVICON_SVG_URL = f"{SITE_URL}/assets/icon.svg"
# Per-lib source ZIPs (scripts/make_source_zips.sh) are hosted same-origin
# at /<slug>/<slug>.zip -- the exact same file scripts/web_shell_override/
# zip-loader.js fetches to boot the game, so there is no separate archive
# to build or keep in sync (see build_site.sh/pack_lib_zip.sh).

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
# breaks the Pages build: write_play_page.sh's `sed ... README.md
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



def display_name(slug, name):
    """Strip a trailing `(slug)` the README H1 often bakes in.

    Landing pages and cards already show the slug on its own line, so
    leaving it inside the H1 produced titles like
    `Discworld MUD lib (v2) (dw_fluffos_v2)` — and when english_name was
    then appended, a triple-stacked heading. Keep the human title only.
    """
    if not name:
        return slug
    cleaned = re.sub(
        rf'\s*[\(（]\s*{re.escape(slug)}\s*[\)）]\s*$',
        '',
        name,
        flags=re.I,
    ).strip()
    return cleaned or name


def page_title_parts(slug, info):
    """Return (primary_title, english_subtitle_or_empty) for lib pages.

    primary is the README/Chinese (or sole) name with slug paren removed;
    english_subtitle is only set when it adds information not already
    present in primary (avoids the triple-title visual bug).
    """
    primary = display_name(slug, info.get('name') or slug)
    en = (info.get('english_name') or '').strip()
    if not en:
        return primary, ''
    if en == primary or en.lower() in primary.lower() or primary.lower() in en.lower():
        return primary, ''
    return primary, en



def render_breadcrumbs(items, aria_label="Breadcrumb"):
    """Build a visible breadcrumb trail + schema.org BreadcrumbList.

    items: ordered (name, url_or_None) pairs. The last entry is the
    current page (url may be None or the canonical URL; either way it
    is rendered as plain text with aria-current="page", not a link).
    Returns (nav_html, jsonld_dict) so callers can drop the nav in the
    body and merge the dict into the page's JSON-LD @graph.
    """
    if not items:
        return "", None
    lis = []
    list_elements = []
    for i, (name, url) in enumerate(items, start=1):
        safe_name = html.escape(name)
        is_last = i == len(items)
        if is_last or not url:
            lis.append(
                f'<li class="crumb current" aria-current="page">'
                f'<span>{safe_name}</span></li>')
            entry = {
                "@type": "ListItem",
                "position": i,
                "name": name,
            }
            if url:
                entry["item"] = url
            list_elements.append(entry)
        else:
            lis.append(
                f'<li class="crumb"><a href="{html.escape(url)}">'
                f'{safe_name}</a></li>')
            list_elements.append({
                "@type": "ListItem",
                "position": i,
                "name": name,
                "item": url,
            })
    nav = (
        f'<nav class="breadcrumbs" aria-label="{html.escape(aria_label)}">'
        f'<ol>{"".join(lis)}</ol></nav>'
    )
    jsonld = {
        "@type": "BreadcrumbList",
        "itemListElement": list_elements,
    }
    return nav, jsonld


def read_port(slug, info):
    """Prefer meta.json port; fall back to config.fluffos `port number`."""
    port = str(info.get('port') or '').strip()
    if port:
        return port
    cfg = REPO / 'libs' / slug / 'config.fluffos'
    if not cfg.is_file():
        return ''
    m = re.search(r'(?im)^\s*port number\s*:\s*(\d+)\s*$',
                  cfg.read_text(encoding='utf-8', errors='replace'))
    return m.group(1) if m else ''


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
        "page_title": "LPC MUD / LPMud 博物馆 — 浏览器直接游玩",
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
        "lang_switch_label": "English", "lang_switch_href": f"{SITE_URL}/",
        "untranslated_suffix": "",
        "self_url": f"{SITE_URL}/zh/",
        "catalog_loading": "正在加载游戏目录…",
        "catalog_error": "目录加载失败，请刷新页面重试。",
        "lineage_label": "同源 · {n} 个快照",
        "upstream_label": "上游",
        "upstream_title": "本馆快照所克隆的上游仓库（不是实时镜像）",
        "upstream_behind": "落后 {n} 提交",
        "upstream_current": "已同步",
        "upstream_unknown": "未钉选提交",
        "upstream_box_title": "上游仓库",
        "upstream_pin": "本馆快照",
        "upstream_head": "上游 HEAD",
        "upstream_compare": "查看差异",
        "upstream_note": "本馆以 git submodule 跟踪该上游，本地驱动兼容补丁在 patches/。落后时需要评估是否更新子模块并重打补丁，不能直接快进。",
        "upstream_title_fluffos": "FluffOS 官方托管的上游仓库（本馆只保留说明和启动脚本）",
        "upstream_note_fluffos": "FluffOS 官方托管。本馆只保留说明和启动脚本；修复请提交到上游仓库，不要在两边各改一份。",
    },
    "en": {
        "html_lang": "en", "og_locale": "en_US",
        "page_title": "LPMud / LPC MUD Museum — Play Classic Mudlibs in Your Browser",
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
        "lang_switch_label": "中文", "lang_switch_href": f"{SITE_URL}/zh/",
        "untranslated_suffix": " (untranslated — showing original Chinese)",
        "self_url": f"{SITE_URL}/",
        "catalog_loading": "Loading catalog…",
        "catalog_error": "Could not load the catalog. Refresh to try again.",
        "lineage_label": "Same lineage · {n} snapshots",
        "upstream_label": "Upstream",
        "upstream_title": "GitHub repo this snapshot was cloned from (not a live mirror)",
        "upstream_behind": "{n} behind",
        "upstream_current": "up to date",
        "upstream_unknown": "pin unknown",
        "upstream_box_title": "Upstream",
        "upstream_pin": "This snapshot",
        "upstream_head": "Upstream HEAD",
        "upstream_compare": "Compare",
        "upstream_note": "This catalog tracks that repo as a git submodule; local driver-compat lives in patches/. A behind count means review the new commits, refresh the pin, and re-apply patches — do not fast-forward blindly.",
        "upstream_title_fluffos": "FluffOS-hosted upstream (this catalog keeps notes and build scripts only)",
        "upstream_note_fluffos": "Hosted by the FluffOS org. This catalog keeps notes and build scripts only — land fixes on the upstream repo, not in a second copy here.",
    },
}


_UPSTREAM_CACHE = None


def is_fluffos_hosted(up):
    """Active fluffos-org mudlib (AGENTS.md §2.3). Archived fluffos
    remotes are not hosting targets — trust meta hosting only."""
    return bool(up) and up.get("hosting") == "fluffos-upstream"


def load_upstreams():
    """slug -> upstream status from scripts/upstream_status.json
    (written by scripts/check_upstream_rebase.py). Missing file is
    fine -- cards then omit the upstream line."""
    global _UPSTREAM_CACHE
    if _UPSTREAM_CACHE is not None:
        return _UPSTREAM_CACHE
    path = REPO / "scripts" / "upstream_status.json"
    if not path.is_file():
        _UPSTREAM_CACHE = {}
        return _UPSTREAM_CACHE
    try:
        _UPSTREAM_CACHE = json.loads(
            path.read_text(encoding="utf-8")).get("libs", {})
    except (OSError, json.JSONDecodeError):
        _UPSTREAM_CACHE = {}
    return _UPSTREAM_CACHE


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
        "    style=\"color:var(--pico-primary)\">FluffOS</a> 驱动上。整个驱动通过 WebAssembly\n"
        "    在你的浏览器里运行 —— 点击任意一款游戏,即可像当年 telnet 泥潭一样注册、\n"
        "    登录、行走江湖。无需安装,无需服务器。每张卡片还标注了预置的管理员账号\n"
        "    (🔑)——用它登录即可获得巫师权限,自由探索游戏世界与代码。"
    ),
    "en": (
        "    A free, browser-playable <b>LPMud / LPC MUD museum</b>: {n_total} restored\n"
        "    classic mudlibs from the 1990s onward — mostly Chinese-language\n"
        "    wuxia/xianxia titles, plus landmark English mudlibs like Dead Souls and\n"
        '    Discworld — running on the\n'
        '    <a href="https://github.com/fluffos/fluffos" style="color:var(--pico-primary)">FluffOS</a>\n'
        "    LPMud driver compiled to WebAssembly. Click any game to register, log in,\n"
        "    and explore exactly as players did over telnet decades ago. No install, no\n"
        "    server. Every card lists a pre-seeded admin account (🔑) for immediate\n"
        "    wizard-level access to the game world and its source. Chinese UI at\n"
        "    <a href=\"/zh/\" style=\"color:var(--pico-primary)\">/zh/</a>."
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

# Light-mode values for the same variable set both templates' dark
# :root block defines -- kept as one shared Python constant so light
# mode is only ever specified once even though it's needed in TWO CSS
# selectors per page (see THEME_STYLE_BLOCK): an explicit
# :root[data-theme="light"] override (the visitor clicked the toggle)
# and an @media(prefers-color-scheme:light) block gated on
# :not([data-theme="dark"]) (the visitor's OS prefers light and they
# haven't overridden it). Dark stays the default/fallback either way,
# matching this site's established identity when neither condition
# applies. Colors were chosen to keep the same primary-blue hue and
# the same ok/warn/bad semantics as the dark palette, re-tuned for
# AA contrast against a white background rather than a literal
# invert.
LIGHT_VARS = """
    --pico-background-color: #fff;
    --pico-color: #1f2430;
    --pico-h1-color: #1f2430;
    --pico-h2-color: #1f2430;
    --pico-muted-color: #5b6472;
    --pico-muted-border-color: #e2e5ec;
    --pico-primary: #3b5bc9;
    --pico-primary-background: #3b5bc9;
    --pico-primary-hover: #2f49a3;
    --pico-primary-hover-background: #2f49a3;
    --pico-primary-underline: rgba(59, 91, 201, .5);
    --pico-primary-inverse: #fff;
    --pico-card-background-color: #f5f6fa;
    --pico-card-border-color: #e2e5ec;
    --pico-code-background-color: #f5f6fa;
    --pico-code-color: #1f2430;
    --pico-blockquote-border-color: #e2e5ec;
    --ok: #2f7d32; --warn: #a15c00; --bad: #b3273f;
    --fg: #1f2430;
"""

# Shared CSS emitted verbatim into both templates' <style> blocks --
# the toggle button + badge-link chip styling, plus the light-mode
# selector pair described above. Kept as one constant so the two
# templates can't drift out of sync on this shared chrome.
THEME_STYLE_BLOCK = f"""
  :root[data-theme="light"] {{{LIGHT_VARS}}}
  @media (prefers-color-scheme: light) {{
    :root:not([data-theme="dark"]) {{{LIGHT_VARS}}}
  }}
  .topbar {{ display: flex; align-items: center; justify-content: space-between;
            gap: 10px; flex-wrap: wrap; }}
  .topbar p {{ margin: 0; font-size: 13px; }}
  .engage {{ display: flex; align-items: center; gap: 8px; flex-wrap: wrap; line-height: 1; }}
  /* Hand-built chrome below (badge/toggle chips) deliberately uses the
     plain --fg var, NOT --pico-color: Pico's own CSS locally redefines
     --pico-color on <button>/<a> elements to its own component colors
     (button text -> its own inverse-of-primary white, link text ->
     its own primary blue) with a selector that wins regardless of our
     :root remap's specificity, since a rule that matches the element
     directly always beats one only inherited from an ancestor. --fg is
     a name Pico's CSS has no rule for, so it can't be shadowed the
     same way -- this is what made these chips render as invisible
     white-on-near-white text in light mode before this was caught. */
  /* Badge chips + theme toggle share ONE chip recipe. Pico's own
     `button` / `[type=button]` rules inject a large form-control
     padding and `margin-bottom: var(--pico-spacing)`, which made the
     🌓 toggle sit a few pixels above the ⭐/Sponsor pills (same flex
     row, different outer box). Reset those and size every chip with
     the same inline-flex / height / padding so they share a baseline. */
  .badge-link,
  button.theme-toggle {{
    display: inline-flex; align-items: center; justify-content: center;
    gap: 5px; box-sizing: border-box; height: 32px; margin: 0;
    font: 600 12.5px/1 var(--pico-font-family);
    color: var(--fg); background: var(--pico-card-background-color);
    border: 1px solid var(--pico-card-border-color); border-radius: 999px;
    padding: 0 12px; text-decoration: none;
    transition: border-color .12s, color .12s;
  }}
  .badge-link:hover,
  button.theme-toggle:hover {{
    border-color: var(--pico-primary); color: var(--pico-primary);
  }}
  button.theme-toggle {{
    width: 32px; padding: 0; font-size: 15px; cursor: pointer;
    /* Kill Pico's primary-button fill that would otherwise paint this
       chip blue behind the emoji (same specificity race as --fg).
       `button.theme-toggle` beats Pico's `[type=button]` so we don't
       need !important. */
    background-color: var(--pico-card-background-color);
  }}

"""

# Sets data-theme from a saved visitor choice as early as possible (a
# synchronous <head> script, before first paint) so returning visitors
# never see a flash of the wrong theme. The toggle button's onclick
# calls window.__toggleTheme directly -- no click-handler wiring/build
# step needed for a plain multi-page static site like this one.
THEME_SCRIPT = """<script>
(function(){
  var KEY = 'mudlibs-theme';
  try {
    var saved = localStorage.getItem(KEY);
    if (saved) document.documentElement.setAttribute('data-theme', saved);
  } catch (e) {}
  window.__toggleTheme = function () {
    var root = document.documentElement;
    var cur = root.getAttribute('data-theme');
    if (!cur) {
      cur = (window.matchMedia && window.matchMedia('(prefers-color-scheme: light)').matches)
          ? 'light' : 'dark';
    }
    var next = cur === 'dark' ? 'light' : 'dark';
    root.setAttribute('data-theme', next);
    try { localStorage.setItem(KEY, next); } catch (e) {}
  };
})();
</script>"""


def get_github_stars():
    """Best-effort GitHub star count for the engagement badge, fetched
    once at build time (not client-side -- no runtime API dependency,
    works the same whether or not a visitor's browser can reach the
    GitHub API). Returns None on any failure (rate limit, no `gh` auth
    in this environment, network hiccup) so callers can render the
    badge without a number rather than fail the whole build over a
    cosmetic stat."""
    try:
        result = subprocess.run(
            ["gh", "api", "repos/fluffos/mudlibs", "--jq", ".stargazers_count"],
            capture_output=True, text=True, timeout=15)
        if result.returncode == 0 and result.stdout.strip().isdigit():
            return int(result.stdout.strip())
    except Exception:
        pass
    return None


def render_engage_badges(lang, stars):
    """GitHub + Open Collective sponsor badges, shown on every page for
    discoverability. Plain self-styled links, not shields.io/Open
    Collective's own hosted badge images -- this project already
    chose to vendor its CSS framework locally rather than load it from
    a CDN specifically because this site's largely mainland-Chinese
    audience can find CDN hosts slow or blocked (see the Pico CSS
    vendoring comment in main()); an actual badge IMAGE from a
    different external host would reintroduce exactly that risk for a
    purely decorative element. The star count itself is still real,
    just fetched at build time (get_github_stars) instead of rendered
    client-side."""
    star_label = f"⭐ {stars}" if stars is not None else "⭐ GitHub"
    sponsor_label = "💚 赞助 · Sponsor" if lang == "zh" else "💚 Sponsor"
    toggle_label = "🌓" if lang == "zh" else "🌓"
    toggle_title = "切换深色/浅色主题" if lang == "zh" else "Toggle dark/light theme"
    return (
        '<div class="engage">'
        f'<a class="badge-link" href="{REPO_URL}" title="GitHub">{star_label}</a>'
        f'<a class="badge-link" href="https://opencollective.com/fluffos-579">{sponsor_label}</a>'
        f'<button type="button" class="theme-toggle" onclick="__toggleTheme()" '
        f'title="{toggle_title}" aria-label="{toggle_title}">{toggle_label}</button>'
        '</div>'
    )


def brand_head_tags(*, twitter_card="summary_large_image"):
    """Shared favicon + Open Graph image tags for every generated page."""
    return (
        f'<link rel="icon" href="/favicon.ico" sizes="any">\n'
        f'<link rel="icon" href="/assets/icon.svg" type="image/svg+xml">\n'
        f'<link rel="apple-touch-icon" href="/assets/apple-touch-icon.png">\n'
        f'<meta property="og:image" content="{OG_IMAGE_URL}">\n'
        f'<meta property="og:image:width" content="1200">\n'
        f'<meta property="og:image:height" content="630">\n'
        f'<meta property="og:image:alt" content="LPC MUD Museum">\n'
        f'<meta name="twitter:card" content="{twitter_card}">\n'
        f'<meta name="twitter:image" content="{OG_IMAGE_URL}">'
    )


def write_brand_assets(out_dir: Path):
    """Emit favicon.ico, SVG icon, apple-touch, and default og-image.png."""
    from PIL import Image, ImageDraw, ImageFont

    assets = out_dir / "assets"
    assets.mkdir(parents=True, exist_ok=True)
    bg = (11, 14, 20, 255)
    fg = (213, 219, 229, 255)
    accent = (122, 162, 247, 255)

    def mark(size: int, radius_frac=0.18) -> Image.Image:
        im = Image.new("RGBA", (size, size), bg)
        d = ImageDraw.Draw(im)
        pad = max(1, size // 12)
        r = int(size * radius_frac)
        d.rounded_rectangle(
            [pad, pad, size - pad - 1, size - pad - 1],
            radius=r, outline=accent, width=max(2, size // 16))
        y1, y2 = size * 0.38, size * 0.55
        x0, x1 = size * 0.28, size * 0.72
        lw = max(2, size // 14)
        d.line([(x0, y1), (x1, y1)], fill=fg, width=lw)
        d.line([(x0, y2), (x0 + (x1 - x0) * 0.55, y2)], fill=accent, width=lw)
        return im

    icon_512 = mark(512)
    icon_512.save(assets / "apple-touch-icon.png", format="PNG")
    icon_512.save(out_dir / "favicon.ico", format="ICO",
                  sizes=[(16, 16), (32, 32), (48, 48)])
    (assets / "icon.svg").write_text(
        """<svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 64 64">
  <rect width="64" height="64" rx="12" fill="#0b0e14"/>
  <rect x="6" y="6" width="52" height="52" rx="10" fill="none"
        stroke="#7aa2f7" stroke-width="3"/>
  <line x1="18" y1="26" x2="46" y2="26" stroke="#d5dbe5" stroke-width="4"
        stroke-linecap="round"/>
  <line x1="18" y1="36" x2="36" y2="36" stroke="#7aa2f7" stroke-width="4"
        stroke-linecap="round"/>
</svg>
""",
        encoding="utf-8",
    )
    og = Image.new("RGB", (1200, 630), (11, 14, 20))
    d = ImageDraw.Draw(og)
    d.rectangle([40, 40, 1160, 590], outline=(35, 42, 56), width=2)
    d.rectangle([40, 40, 48, 590], fill=(122, 162, 247))
    try:
        font_lg = ImageFont.truetype(
            "/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf", 72)
        font_sm = ImageFont.truetype(
            "/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf", 32)
    except OSError:
        font_lg = ImageFont.load_default()
        font_sm = font_lg
    d.text((80, 200), "LPC MUD Museum", fill=(213, 219, 229), font=font_lg)
    d.text((80, 300), "Play classic LPMud / LPC mudlibs in your browser",
           fill=(107, 116, 132), font=font_sm)
    d.text((80, 500), "mudlibs.fluffos.info", fill=(122, 162, 247), font=font_sm)
    og.save(out_dir / "og-image.png", format="PNG", optimize=True)


def build_jsonld(status, lang, ui, numbers, canonical_url=None):
    """Lean homepage JSON-LD: WebSite + CollectionPage.

    Individual VideoGame entities live on per-lib landing pages (and in
    games.json). Embedding a full ItemList of every title here used to
    add ~300KB of duplicate structured data to every language index."""
    n_linked = sum(
        1 for info in status["libs"].values() if info["status"] != "noboot")
    canon = canonical_url or ui["self_url"]
    doc = {
        "@context": "https://schema.org",
        "@graph": [
            {
                "@type": "WebSite",
                "name": ui["site_name"],
                "url": canon,
                "inLanguage": ui["html_lang"],
                "isAccessibleForFree": True,
                "image": OG_IMAGE_URL,
            },
            {
                "@type": "CollectionPage",
                "name": ui["h1"],
                "url": canon,
                "isPartOf": {"@type": "WebSite", "url": SITE_URL + "/"},
                "numberOfItems": n_linked,
                "about": {
                    "@type": "Thing",
                    "name": "LPMud / LPC mudlib museum",
                },
            },
        ],
    }
    return json.dumps(doc, ensure_ascii=False).replace("</", "<\/")



def _is_cjk_name(name):
    """True if a lib's native `name` contains CJK script -- used to boost
    English-original libs to the top of the /en/ page (an English visitor
    shouldn't have to scroll past ~190 Chinese-titled cards first). The zh
    page's own order is untouched; this only ever affects lang="en"."""
    return any("一" <= ch <= "鿿" for ch in name)


def _lineage_clusters(entries, numbers, lang):
    """Group catalog siblings that share a base number (NNN / NNN-M).

    `entries` is already sorted by catalog number so members of one
    lineage are consecutive. Clusters of size 1 stay unwrapped; clusters
    of 2+ become a visible lineage group on the index.

    On the English page, clusters whose members are all CJK-named sort
    after clusters that include an English-original title -- same
    English-first boost as before, without splitting a lineage across
    that boundary."""
    clusters = []
    current = []
    current_base = None
    for slug, info in entries:
        base = numbers.get(slug, (9999, 0))[0]
        if current and base != current_base:
            clusters.append((current_base, current))
            current = []
        current.append((slug, info))
        current_base = base
    if current:
        clusters.append((current_base, current))
    if lang == "en":
        clusters.sort(key=lambda c: (
            all(_is_cjk_name(info["name"]) for _, info in c[1]),
            c[0],
        ))
    return clusters


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


def build_meta_bits(slug, info, ui, commits, linked, *, index_card=False):
    """The admin-credential / updated-commit / source / download-zip line
    shared by both the index card (render_index) and the per-lib landing
    page (render_lib_page). Returns (meta_bits_html_list, admin_id) --
    callers that also need admin_id for their own search corpus (only
    render_index does) get it back rather than re-parsing the README.

    index_card=True uses site-root-relative ZIP hrefs (`/<slug>/<slug>.zip`)
    because index pages live at `/` and `/zh/`, where a bare `{slug}.zip`
    would resolve to the wrong path."""
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
        zip_href = (f"/{html.escape(slug)}/{html.escape(slug)}.zip"
                    if index_card else f"{html.escape(slug)}.zip")
        meta_bits.append(
            f'<a href="{zip_href}" '
            f'title="{ui["download_title"]}">{ui["download_label"]}</a>')
    up = load_upstreams().get(slug)
    if up and up.get("url") and up.get("repo"):
        st = up.get("status") or ""
        extra = ""
        if st == "behind" and up.get("ahead_by"):
            extra = (
                f' <span class="upstream-behind">'
                f'{html.escape(ui["upstream_behind"].format(n=up["ahead_by"]))}'
                f'</span>')
        href = up.get("compare_url") or up["url"]
        title_key = ("upstream_title_fluffos" if is_fluffos_hosted(up)
                     else "upstream_title")
        meta_bits.append(
            f'<a class="upstream" href="{html.escape(href)}" '
            f'title="{html.escape(ui[title_key])}" '
            f'rel="noopener">{ui["upstream_label"]} '
            f'{html.escape(up["repo"])}</a>{extra}')
    return meta_bits, admin_id


def render_upstream_box(slug, ui):
    """Visible upstream block for the per-lib landing page."""
    up = load_upstreams().get(slug)
    if not up or not up.get("url") or not up.get("repo"):
        return ""
    pin = html.escape((up.get("pinned") or "")[:12] or "—")
    head = html.escape((up.get("head") or "")[:12] or "—")
    st = up.get("status") or ""
    if st == "behind" and up.get("ahead_by"):
        status_html = (
            f'<span class="upstream-behind">'
            f'{html.escape(ui["upstream_behind"].format(n=up["ahead_by"]))}'
            f'</span>')
    elif st == "current":
        status_html = (
            f'<span class="upstream-current">'
            f'{html.escape(ui["upstream_current"])}</span>')
    elif st == "unknown_pin":
        status_html = html.escape(ui["upstream_unknown"])
    else:
        status_html = html.escape(st or "")
    extras = ""
    for extra in up.get("extra_repos") or []:
        extras += (
            f'<li><a href="{html.escape(extra.get("url") or "")}" '
            f'rel="noopener">{html.escape(extra.get("repo") or "")}</a></li>')
    extra_html = f'<ul class="upstream-extras">{extras}</ul>' if extras else ""
    compare = up.get("compare_url") or up["url"]
    note_key = ("upstream_note_fluffos" if is_fluffos_hosted(up)
                else "upstream_note")
    return (
        f'<aside class="upstream-box">\n'
        f'  <h2>{html.escape(ui["upstream_box_title"])}</h2>\n'
        f'  <p><a href="{html.escape(up["url"])}" rel="noopener">'
        f'{html.escape(up["repo"])}</a> · {status_html}</p>\n'
        f'  <p>{html.escape(ui["upstream_pin"])} <code>{pin}</code>'
        f' · {html.escape(ui["upstream_head"])} <code>{head}</code>'
        f' · <a href="{html.escape(compare)}" rel="noopener">'
        f'{html.escape(ui["upstream_compare"])}</a></p>\n'
        f'  <p class="upstream-note">{html.escape(ui[note_key])}</p>\n'
        f'  {extra_html}\n'
        f'</aside>'
    )


def render_lib_page(slug, info, commits, stars=None, page="landing"):
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
    write_play_page.sh."""
    st = info["status"]
    icon, label, _ = BADGE[st]
    ui_zh = UI["zh"]
    meta_bits, _ = build_meta_bits(slug, info, ui_zh, commits, True)
    meta_html = '<p class="meta">' + "\n    ".join(meta_bits) + '</p>'
    upstream_html = render_upstream_box(slug, ui_zh)

    primary_title, en_subtitle = page_title_parts(slug, info)
    name_en = (info.get("english_name") or en_subtitle or "").strip()
    # English-default SEO: when we have an English name, put it in the
    # <h1>/<title> and demote the Chinese/README name to .aka. English
    # queries like "lpmud" / game-name searches otherwise only saw a
    # zh-CN document whose H1 never mentioned the English title.
    if name_en and name_en != primary_title:
        h1_title = name_en
        aka_html = f'<p class="aka">{html.escape(primary_title)}</p>'
    else:
        h1_title = primary_title
        aka_html = (
            f'<p class="aka">{html.escape(en_subtitle)}</p>'
            if en_subtitle and en_subtitle != primary_title else ''
        )
    title_bits = html.escape(h1_title)

    desc = info["description"]
    desc_en = info.get("english_description") or ""

    # For a genuinely English-original archive, README's own intro
    # paragraph (desc) and meta.json's hand-authored english_description
    # (desc_en) are both already English -- independently worded, but
    # the same content -- so showing them stacked under an "English"
    # heading reads as the page repeating itself. Detect "desc is
    # already English" via common English stopwords (robust enough to
    # tell it apart from Chinese, and from this collection's one
    # ASCII-only non-English case, Polish, which has none of these
    # words): only show both blocks when they're genuinely two
    # different languages serving two different readers.
    _en_stopwords = (" the ", " and ", " of ", " is ", " with ",
                      " to ", " a ", " in ", " this ")
    desc_already_english = sum(
        1 for w in _en_stopwords if w in f" {desc.lower()} ") >= 3
    same_language_dup = bool(desc and desc_en and desc != desc_en
                              and desc_already_english)
    if same_language_dup:
        # Prefer the more thoroughly-researched field (usually
        # english_description, curated by this project's later
        # description-quality sweep) as the single description shown.
        primary_desc = desc_en if len(desc_en) >= len(desc) else desc
        desc_html = f'<p class="desc">{html.escape(primary_desc)}</p>'
    else:
        primary_desc = desc
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
        # Drop the leading paragraph too, if it's the exact text already
        # shown as the page's own description block above (parse_readme
        # extracts `desc` from precisely this paragraph, so it usually
        # is) -- otherwise every page repeats its own opening sentence
        # a second time the moment a reader scrolls to the README
        # section.
        if text and primary_desc:
            parts = re.split(r"\n\s*\n", text, maxsplit=1)
            first_para_norm = re.sub(
                r"\s+", " ", parts[0].replace("\n", "")).strip()
            if first_para_norm == primary_desc.strip():
                text = parts[1].strip() if len(parts) > 1 else ""
        if text:
            doc_sections.append(
                f'<section class="doc"><h2>README</h2>{render_markdown_html(text)}</section>')
    notes_path = REPO / "libs" / slug / "NOTES.md"
    if notes_path.is_file():
        text = notes_path.read_text(encoding="utf-8").strip()
        if text:
            # NOTES.md is a developer-facing porting/bug-fix log, not
            # game content -- on a typical lib it runs to tens of
            # thousands of words and was measured at 80-90% of this
            # page's total weight, burying the actual description a
            # visitor came to read under a wall of compiler-error
            # minutiae before they ever reach "Play Now". Collapse it
            # behind a native <details> disclosure (still real DOM --
            # fully crawlable/indexable and screen-reader-navigable,
            # no JS involved) so the page reads cleanly by default
            # while the material stays one click away for anyone who
            # wants it.
            doc_sections.append(
                '<details class="doc notes"><summary><h2>NOTES · 移植与修复记录</h2></summary>'
                f'{render_markdown_html(text)}</details>')
    docs_html = "\n".join(doc_sections)

    # page="landing" -> /<slug>/ (hub). page="info" -> /<slug>/info.html,
    # a stable static URL for the same description/README content so
    # Google can treat "info" the way /play.html is the stable play URL.
    if page not in ("landing", "info"):
        raise ValueError(f"unknown lib page kind: {page!r}")
    landing_url = f"{SITE_URL}/{slug}/"
    info_url = f"{SITE_URL}/{slug}/info.html"
    play_url = f"{SITE_URL}/{slug}/play.html"
    canonical_url = info_url if page == "info" else landing_url
    # Prefer English description for the global meta (English is the
    # site default); fall back to Chinese. Prefix with LPMud keywords so
    # game pages can rank for the same queries as the index.
    _desc_for_meta = (desc_en or primary_desc or info["name"]).strip()
    if not _desc_for_meta.lower().startswith(("lpmud", "lpc mud", "mudlib")):
        _desc_for_meta = f"LPMud mudlib — {_desc_for_meta}"
    meta_desc_attr = html.escape(_desc_for_meta[:300])

    zip_url = f"{SITE_URL}/{slug}/{slug}.zip"
    # VideoGame entity always points at the landing hub; info.html is a
    # WebPage/alias for the same description, not a second game entity.
    jsonld_doc = {
        "@context": "https://schema.org",
        "@type": "VideoGame",
        "name": info.get("english_name") or primary_title,
        "alternateName": primary_title if info.get("english_name") else None,
        "description": primary_desc or desc_en,
        "url": landing_url,
        "genre": ["MUD", "Text Adventure", "RPG"],
        "gamePlatform": ["Web browser (WebAssembly)", "FluffOS (native)"],
        "playMode": "MultiPlayer",
        "inLanguage": ["zh-CN", "en"],
        "isAccessibleForFree": True,
        "downloadUrl": zip_url,
        "installUrl": play_url,
        "sameAs": [f"{REPO_URL}/tree/main/libs/{slug}"],
        "offers": {
            "@type": "Offer",
            "price": "0",
            "priceCurrency": "USD",
            "availability": "https://schema.org/InStock",
            "url": zip_url,
        },
    }
    jsonld_doc = {k: v for k, v in jsonld_doc.items() if v is not None}

    # Visible trail + BreadcrumbList JSON-LD. Landing: Home → Name.
    # Info: Home → Name → Info (Name links back to the hub).
    crumb_label = info.get("english_name") or primary_title
    if page == "info":
        crumb_items = [
            ("Home", f"{SITE_URL}/"),
            (crumb_label, landing_url),
            ("Info", None),
        ]
        page_title_suffix = "Info — LPMud Museum"
    else:
        crumb_items = [
            ("Home", f"{SITE_URL}/"),
            (crumb_label, None),
        ]
        page_title_suffix = "LPMud Museum"
    crumb_html, crumb_ld = render_breadcrumbs(crumb_items)
    if crumb_ld:
        # Promote the single VideoGame node into an @graph so the
        # BreadcrumbList rides alongside without a second <script> tag.
        game_node = {k: v for k, v in jsonld_doc.items() if k != "@context"}
        jsonld_doc = {
            "@context": "https://schema.org",
            "@graph": [game_node, crumb_ld],
        }
    jsonld = json.dumps(jsonld_doc, ensure_ascii=False).replace("</", "<\\/")

    site_name = html.escape(ui_zh["site_name"])
    return f"""<!doctype html>
<html lang="en">
<head>
<meta charset="utf-8">
<meta name="viewport" content="width=device-width, initial-scale=1">
<title>{title_bits} — {page_title_suffix}</title>
<meta name="description" content="{meta_desc_attr}">
<meta name="keywords" content="LPMud, LPC MUD, mudlib, FluffOS, play MUD online, WebAssembly, text MUD">
<meta name="robots" content="index, follow">
<link rel="canonical" href="{canonical_url}">
<link rel="alternate" hreflang="en" href="{canonical_url}">
<link rel="alternate" hreflang="x-default" href="{canonical_url}">
<meta property="og:type" content="website">
<meta property="og:site_name" content="{site_name}">
<meta property="og:title" content="{title_bits}">
<meta property="og:description" content="{meta_desc_attr}">
<meta property="og:url" content="{canonical_url}">
<meta name="twitter:card" content="summary">
<meta name="twitter:title" content="{title_bits}">
<meta name="twitter:description" content="{meta_desc_attr}">
{brand_head_tags()}
<script type="application/ld+json">{jsonld}</script>
{THEME_SCRIPT}
<link rel="stylesheet" href="/assets/pico.min.css">
<style>
  /* Remap this site's own long-standing dark palette onto Pico's
     theming variables, rather than keeping two parallel color systems
     -- every Pico-styled element (links, headings, code, hr, details)
     picks this up for free. Vendored locally; see main()'s comment for
     why this isn't a CDN include. */
  :root {{
    --pico-font-family: -apple-system, "PingFang SC", "Microsoft YaHei",
          "Noto Sans CJK SC", var(--pico-font-family-sans-serif);
    --pico-background-color: #0b0e14;
    --pico-color: #d5dbe5;
    --pico-h1-color: #d5dbe5;
    --pico-h2-color: #d5dbe5;
    --pico-muted-color: #6b7484;
    --pico-muted-border-color: #232a38;
    --pico-primary: #7aa2f7;
    --pico-primary-background: #7aa2f7;
    --pico-primary-hover: #9ab8f9;
    --pico-primary-hover-background: #9ab8f9;
    --pico-primary-underline: rgba(122, 162, 247, .5);
    --pico-primary-inverse: #0b0e14;
    --pico-card-background-color: #11151f;
    --pico-card-border-color: #232a38;
    --pico-code-background-color: #11151f;
    --pico-code-color: #d5dbe5;
    --pico-blockquote-border-color: #232a38;
    --ok: #9ece6a; --warn: #e0af68; --bad: #f7768e;
    --fg: #d5dbe5;
  }}
  body > header, body > main, body > footer {{ max-width: 760px; }}
  body > header {{ padding-bottom: 0; }}
  .breadcrumbs {{ font-size: 13px; margin: 0 0 4px; }}
  .breadcrumbs ol {{
    list-style: none; display: flex; flex-wrap: wrap; align-items: center;
    gap: 0; padding: 0; margin: 0; color: var(--pico-muted-color);
  }}
  .breadcrumbs li {{ display: inline-flex; align-items: center; }}
  .breadcrumbs li:not(:last-child)::after {{
    content: "/"; margin: 0 8px; opacity: .55; speak: never;
  }}
  .breadcrumbs a {{ color: var(--pico-muted-color); text-decoration: none; }}
  .breadcrumbs a:hover {{ color: var(--pico-primary); }}
  .breadcrumbs .current span {{ color: var(--fg); font-weight: 600; }}
  .head {{ display: flex; align-items: center; gap: 12px; flex-wrap: wrap;
           margin: 18px 0 0; }}
  h1 {{ font-size: 30px; margin: 0; font-weight: 700; letter-spacing: -.01em; }}
  .badge {{ font-size: 13px; font-weight: 600; white-space: nowrap;
           padding: 3px 10px; border-radius: 999px; border: 1px solid currentColor; }}
  .badge.playable {{ color: var(--ok); }}
  .badge.limited {{ color: var(--warn); }}
  .badge.noboot {{ color: var(--bad); }}
  .slug {{ margin: 6px 0 14px; color: var(--pico-muted-color); font-size: 12px;
          font-family: var(--pico-font-family-monospace); }}
  .aka {{ margin: 4px 0 0; font-size: 15px; color: var(--pico-muted-color); }}
  .run-links {{ margin: -8px 0 22px; font-size: 13px; color: var(--pico-muted-color); }}
  .run-links a {{ margin: 0 2px; }}
  .meta {{ margin: 0 0 24px; font-size: 13px; color: var(--pico-muted-color);
          line-height: 1.9; display: flex; flex-wrap: wrap; gap: 4px 16px; }}
  .meta .admin {{ font-family: var(--pico-font-family-monospace); }}
  .upstream-behind {{ color: var(--warn); font-weight: 600; }}
  .upstream-current {{ color: var(--ok); }}
  .upstream-box {{
    margin: 0 0 24px; padding: 12px 14px; border-radius: 10px;
    border: 1px solid var(--pico-muted-border-color);
    background: var(--pico-card-background-color); font-size: 14px;
  }}
  .upstream-box h2 {{ font-size: 15px; margin: 0 0 8px; }}
  .upstream-box p {{ margin: 0 0 6px; }}
  .upstream-note {{ color: var(--pico-muted-color); font-size: 13px; }}
  .play-cta {{ margin: 0 0 28px; }}
  .play-btn {{
    display: inline-block; background: var(--pico-primary); color: #0b0e14;
    font-weight: 700; text-decoration: none; padding: 13px 30px;
    border-radius: 8px; font-size: 16px;
    box-shadow: 0 4px 20px -6px rgba(122, 162, 247, .55);
    transition: transform .12s ease, box-shadow .12s ease, opacity .12s ease;
  }}
  .play-btn:hover {{
    opacity: .92; transform: translateY(-1px);
    box-shadow: 0 6px 24px -6px rgba(122, 162, 247, .7);
  }}
  .play-btn:active {{ transform: translateY(0); }}
  .desc {{
    font-size: 16.5px; line-height: 1.75;
    margin: 0 0 30px; padding: 2px 0 2px 16px;
    border-left: 3px solid var(--pico-primary);
  }}
  section.doc h2:first-child {{ margin-top: 8px; }}
  details.notes {{
    border: 1px solid var(--pico-muted-border-color); border-radius: 10px;
    padding: 4px 18px; margin: 30px 0 0; background: var(--pico-card-background-color);
  }}
  details.notes[open] {{ padding-bottom: 18px; }}
  details.notes summary {{
    cursor: pointer; list-style: none; padding: 14px 0;
    display: flex; align-items: center; gap: 10px; user-select: none;
  }}
  details.notes summary::-webkit-details-marker {{ display: none; }}
  details.notes summary h2 {{
    margin: 0; border-bottom: none; padding-bottom: 0;
    font-size: 16px; color: var(--pico-muted-color); flex: 1;
  }}
  details.notes summary::after {{
    content: "▸"; color: var(--pico-muted-color); font-size: 13px;
    transition: transform .15s ease; flex-shrink: 0;
  }}
  details.notes[open] summary::after {{ transform: rotate(90deg); }}
  details.notes summary:hover h2, details.notes summary:hover::after {{ color: var(--pico-primary); }}
  details.notes > *:not(summary) {{ margin-top: 4px; }}
  body > footer {{ margin-top: 44px; font-size: 12px; color: var(--pico-muted-color); }}
{THEME_STYLE_BLOCK}
</style>
</head>
<body>
<header>
  <div class="topbar">
    {crumb_html}
    {render_engage_badges("zh", stars)}
  </div>
  <div class="head">
    <h1>{title_bits}</h1>
    <span class="badge {st}">{icon} {html.escape(label)}</span>
  </div>
  {aka_html}
  <p class="slug">{html.escape(slug)}</p>
  {meta_html}
  {upstream_html}
</header>
<main>
  <p class="play-cta"><a role="button" class="play-btn" href="play.html">▶ 开始游玩 · Play Now</a></p>
  <p class="run-links"><a href="info.html" title="Static info page (description, README, NOTES)">info.html · 介绍</a>
    · <a href="play.html" title="Play in browser via WebAssembly">play.html · 游玩</a>
    · <a href="llms.txt" title="LLM-oriented download &amp; native-run instructions">llms.txt · 下载与本地运行</a>
    · <a href="{SITE_URL}/{slug}/{slug}.zip">ZIP</a>
    · <a href="{REPO_URL}/tree/main/libs/{slug}">GitHub</a></p>
  {desc_html}
  {docs_html}
</main>
<footer>
{FOOTER['zh']}
</footer>
</body>
</html>
"""



def build_catalog(status, commits, lang, ui, numbers):
    """Lean per-language catalog payload for the homepage grid.

    Cards used to be server-rendered into index.html (~900KB HTML). They
    now live in /assets/catalog-{lang}.json and are painted client-side;
    per-lib landing pages, games.json, and the sitemap remain the
    crawler-facing discovery surface.
    """
    libs = status["libs"]
    entries = sorted(
        libs.items(),
        key=lambda kv: (numbers.get(kv[0], (9999, 0)), kv[0]))
    clusters = _lineage_clusters(entries, numbers, lang)
    out_clusters = []
    noscript_links = []
    for base, members in clusters:
        cards = []
        for slug, info in members:
            st = info["status"]
            icon = BADGE[st][0]
            label = ui["badge"][st]
            if lang == "en":
                name_src = info.get("english_name") or display_name(slug, info["name"])
                desc_src = info.get("english_description") or info["description"]
                desc_suffix = (
                    "" if info.get("english_description")
                    else ui["untranslated_suffix"])
            else:
                name_src = display_name(slug, info["name"])
                desc_src = info["description"]
                desc_suffix = ""
            linked = st != "noboot"
            meta_bits, admin_id = build_meta_bits(
                slug, info, ui, commits, linked, index_card=True)
            search_bits = [
                slug, info["name"], info["description"],
                info.get("english_name", ""), info.get("english_description", ""),
                info.get("archive", ""), info.get("archive_num", ""),
                admin_id or "",
                (load_upstreams().get(slug) or {}).get("repo") or "",
            ]
            cards.append({
                "slug": slug,
                "status": st,
                "name": name_src,
                "desc": desc_src + desc_suffix,
                "badge": label,
                "icon": icon,
                "linked": linked,
                "search": " ".join(b for b in search_bits if b).lower(),
                "meta": "\n    ".join(meta_bits),
            })
            if linked:
                noscript_links.append((slug, name_src))
        if lang == "en":
            canon_name = members[0][1].get("english_name") or members[0][1]["name"]
        else:
            canon_name = members[0][1]["name"]
        num_label = f"{base:03d}" if base < 9999 else "?"
        out_clusters.append({
            "num": num_label,
            "name": canon_name,
            "count_label": ui["lineage_label"].format(n=len(members)),
            "cards": cards,
        })
    return {"lang": lang, "clusters": out_clusters, "noscript": noscript_links}


def render_catalog_json(status, commits, lang):
    ui = UI[lang]
    numbers = load_numbers()
    payload = build_catalog(status, commits, lang, ui, numbers)
    wire = {"lang": payload["lang"], "clusters": payload["clusters"]}
    return json.dumps(wire, ensure_ascii=False, separators=(",", ":")) + "\n"


def render_index(status, commits, lang="zh", canonical_url=None, stars=None):
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
    catalog = build_catalog(status, commits, lang, ui, numbers)

    n_total = len(libs)
    n_play = counts.get("playable", 0)
    n_lim = counts.get("limited", 0)
    n_no = counts.get("noboot", 0)

    page_title = ui["page_title"]
    if lang == "en":
        meta_desc = (
            f"Play {n_play}+ classic LPMud / LPC mudlibs in your browser — "
            f"a free FluffOS WebAssembly museum of {n_total} restored games "
            f"from the 1990s onward (Chinese wuxia/xianxia plus English "
            f"mudlibs like Dead Souls and Discworld). No install, no server. "
            "Pre-seeded admin/wizard accounts on every card.")
    else:
        meta_desc = (
            f"收藏了 {n_total} 个上世纪九十年代至今的 LPC MUD(泥潭)游戏库,"
            f"以中文游戏为主,也收录了 Dead Souls、Discworld 等经典英文 mudlib,"
            f"其中 {n_play} 款可在浏览器内通过 WebAssembly 完整游玩,无需安装、"
            "无需服务器。每款游戏都标注了预置管理员账号,登录即有巫师权限。"
            "A browser-playable archive of restored classic LPC MUD "
            "(mudlib) games, running on the FluffOS driver via WebAssembly.")
    meta_desc_attr = html.escape(meta_desc)

    jsonld = build_jsonld(status, lang, ui, numbers, canonical_url=canonical_url)

    if lang == "zh":
        index_crumb_html, index_crumb_ld = render_breadcrumbs([
            ("Home", f"{SITE_URL}/"),
            ("中文", None),
        ])
        if index_crumb_ld:
            import json as _json
            try:
                graph = _json.loads(jsonld)
            except Exception:
                graph = {"@context": "https://schema.org", "@graph": []}
            if "@graph" in graph:
                graph["@graph"].append(index_crumb_ld)
            else:
                node = {k: v for k, v in graph.items() if k != "@context"}
                graph = {"@context": graph.get("@context", "https://schema.org"),
                         "@graph": [node, index_crumb_ld]}
            jsonld = _json.dumps(graph, ensure_ascii=False).replace("</", "<\/")
    else:
        index_crumb_html = ""

    catalog_url = f"/assets/catalog-{lang}.json"
    brand = brand_head_tags()
    loading = html.escape(ui["catalog_loading"])
    err_js = json.dumps(ui["catalog_error"], ensure_ascii=False)
    noscript_items = "\n".join(
        f'  <li><a href="/{html.escape(slug)}/">{html.escape(name)}</a></li>'
        for slug, name in catalog["noscript"]
    )

    css = """
  /* Same palette remap as the per-lib landing page (render_lib_page) --
     kept in sync by hand since these are two independent inline
     <style> blocks, not a shared stylesheet. */
  :root {{
    --pico-font-family: -apple-system, "PingFang SC", "Microsoft YaHei",
          "Noto Sans CJK SC", var(--pico-font-family-sans-serif);
    --pico-background-color: #0b0e14;
    --pico-color: #d5dbe5;
    --pico-h1-color: #d5dbe5;
    --pico-muted-color: #6b7484;
    --pico-muted-border-color: #232a38;
    --pico-primary: #7aa2f7;
    --pico-primary-background: #7aa2f7;
    --pico-primary-hover: #9ab8f9;
    --pico-primary-hover-background: #9ab8f9;
    --pico-primary-underline: rgba(122, 162, 247, .5);
    --pico-primary-inverse: #0b0e14;
    --pico-card-background-color: #11151f;
    --pico-card-border-color: #232a38;
    --ok: #9ece6a; --warn: #e0af68; --bad: #f7768e;
    --fg: #d5dbe5;
  }}
  body > header, body > main, body > footer {{ max-width: 1100px; }}
  body > header {{ padding-bottom: 0; }}
  h1 {{ font-size: 28px; margin: 8px 0 4px; font-weight: 700; letter-spacing: -.01em; }}
  .intro {{ color: var(--pico-muted-color); margin: 0 0 6px; }}
  .stats {{ color: var(--pico-muted-color); font-size: 13px; margin-bottom: 8px; }}
  .stats b {{ color: var(--pico-color); }}
  .controls {{
    display: flex; flex-wrap: wrap; gap: 8px; margin: 0 0 18px;
    position: sticky; top: 0; background: var(--pico-background-color);
    padding: 12px 0; z-index: 5; border-bottom: 1px solid var(--pico-muted-border-color);
  }}
  /* #q and .fbtn use --fg, not --pico-color -- see THEME_STYLE_BLOCK's
     comment on .badge-link: Pico's own CSS shadows --pico-color locally
     on <button>/form elements with its own component colors, which a
     plain :root remap can't override (a rule matching the element
     directly always wins over one only inherited from :root). */
  #q {{
    flex: 1 1 220px; background: var(--pico-card-background-color);
    border: 1px solid var(--pico-muted-border-color); border-radius: 8px;
    color: var(--fg); font: inherit; padding: 9px 14px;
    outline: none; margin: 0; transition: border-color .12s;
  }}
  #q:focus {{ border-color: var(--pico-primary); box-shadow: none; }}
  .fbtn {{
    background: var(--pico-card-background-color); border: 1px solid var(--pico-muted-border-color);
    color: var(--fg); border-radius: 8px; padding: 9px 16px;
    font: inherit; font-size: 13px; font-weight: 600; cursor: pointer;
    white-space: nowrap; margin: 0; transition: border-color .12s, color .12s;
  }}
  .fbtn.active {{ border-color: var(--pico-primary); color: var(--pico-primary); }}
  .grid {{
    display: grid; gap: 14px;
    grid-template-columns: repeat(auto-fill, minmax(300px, 1fr));
  }}
  .lineage {{
    grid-column: 1 / -1;
    border: 1px solid var(--pico-muted-border-color);
    border-radius: 12px;
    padding: 12px 14px 14px;
    background: color-mix(in srgb, var(--pico-card-background-color) 70%, transparent);
  }}
  .lineage-head {{
    display: flex; flex-wrap: wrap; align-items: baseline; gap: 8px 12px;
    margin: 0 0 12px;
  }}
  .lineage-num {{
    font-family: var(--pico-font-family-monospace); font-size: 13px;
    font-weight: 600; color: var(--pico-primary);
  }}
  .lineage-name {{ font-size: 14px; font-weight: 600; color: var(--pico-color); }}
  .lineage-count {{ font-size: 12px; color: var(--pico-muted-color); }}
  .lineage-grid {{
    display: grid; gap: 14px;
    grid-template-columns: repeat(auto-fill, minmax(300px, 1fr));
  }}
  .card {{
    position: relative; display: block; background: var(--pico-card-background-color);
    border: 1px solid var(--pico-muted-border-color); border-radius: 10px;
    padding: 16px 18px; color: inherit;
    transition: border-color .15s, transform .15s, box-shadow .15s;
  }}
  .card.linked:hover {{
    border-color: var(--pico-primary); transform: translateY(-2px);
    box-shadow: 0 8px 24px -10px rgba(0, 0, 0, .5);
  }}
  .card .play {{ color: inherit; text-decoration: none; }}
  /* stretch the title link over the whole card (see render_index) */
  .card.linked .play::after {{ content: ""; position: absolute; inset: 0; }}
  .card.noboot {{ opacity: .55; }}
  .card-head {{ display: flex; align-items: baseline; gap: 8px;
               justify-content: space-between; }}
  .card h2 {{ font-size: 16px; margin: 0; font-weight: 600; }}
  .badge {{
    font-size: 11.5px; font-weight: 600; white-space: nowrap;
    padding: 2px 9px; border-radius: 999px; border: 1px solid currentColor;
  }}
  .badge.playable {{ color: var(--ok); }}
  .badge.limited {{ color: var(--warn); }}
  .badge.noboot {{ color: var(--bad); }}
  .slug {{ margin: 4px 0 8px; color: var(--pico-muted-color); font-size: 12px;
          font-family: var(--pico-font-family-monospace); }}
  .desc {{
    margin: 0; font-size: 13px; line-height: 1.55; color: var(--pico-color);
    display: -webkit-box; -webkit-line-clamp: 4; -webkit-box-orient: vertical;
    overflow: hidden;
  }}
  .meta {{
    margin: 10px 0 0; font-size: 12px; color: var(--pico-muted-color);
    display: flex; flex-wrap: wrap; gap: 2px 12px;
  }}
  .meta .admin {{ font-family: var(--pico-font-family-monospace); }}
  /* meta links must stay clickable above the stretched .play overlay */
  .meta a {{ position: relative; z-index: 2; }}
  .upstream-behind {{ position: relative; z-index: 1; color: var(--warn); font-weight: 600; }}
  body > footer {{ margin-top: 36px; color: var(--pico-muted-color); font-size: 12px; }}
  .catalog-status {
    grid-column: 1 / -1; color: var(--pico-muted-color); font-size: 14px;
    margin: 8px 0; padding: 0;
  }
{THEME_STYLE_BLOCK}
"""

    return f"""<!doctype html>
<html lang="{ui['html_lang']}">
<head>
<meta charset="utf-8">
<meta name="viewport" content="width=device-width, initial-scale=1">
<title>{html.escape(page_title)}</title>
<meta name="description" content="{meta_desc_attr}">
<meta name="robots" content="index, follow">
<link rel="canonical" href="{canonical_url}">
<link rel="alternate" hreflang="en" href="{UI['en']['self_url']}">
<link rel="alternate" hreflang="zh-CN" href="{UI['zh']['self_url']}">
<link rel="alternate" hreflang="x-default" href="{UI['en']['self_url']}">
<link rel="alternate" type="text/plain" title="llms.txt" href="{SITE_URL}/llms.txt">
<link rel="alternate" type="application/json" title="games.json" href="{SITE_URL}/games.json">
<link rel="preload" href="{catalog_url}" as="fetch" crossorigin>
{brand}
<meta property="og:type" content="website">
<meta property="og:site_name" content="{html.escape(ui['site_name'])}">
<meta property="og:title" content="{html.escape(page_title)}">
<meta property="og:description" content="{meta_desc_attr}">
<meta property="og:url" content="{canonical_url}">
<meta property="og:locale" content="{ui['og_locale']}">
<meta name="twitter:title" content="{html.escape(page_title)}">
<meta name="twitter:description" content="{meta_desc_attr}">
<script type="application/ld+json">{jsonld}</script>
{THEME_SCRIPT}
<link rel="stylesheet" href="/assets/pico.min.css">
<style>
{css}
</style>
</head>
<body>
<header>
  <div class="topbar">
    <div>
      {index_crumb_html}
      <p class="lang-switch"><a href="{ui['lang_switch_href']}">{html.escape(ui['lang_switch_label'])}</a></p>
    </div>
    {render_engage_badges(lang, stars)}
  </div>
  <h1>{html.escape(ui['h1'])}</h1>
  <p class="intro">
{INTRO[lang].format(n_total=n_total)}
  </p>
  <p class="stats">
{STATS[lang].format(n_play=n_play, n_lim=n_lim, n_no=n_no)}
  </p>
</header>
<main>
  <div class="controls">
    <input id="q" type="search" placeholder="{html.escape(ui['search_placeholder'])}"
           autocomplete="off">
    <button class="fbtn active" data-f="all">{html.escape(ui['filter_all'])} {n_total}</button>
    <button class="fbtn" data-f="playable">{html.escape(ui['filter_playable'])} {n_play}</button>
    <button class="fbtn" data-f="limited">{html.escape(ui['filter_limited'])} {n_lim}</button>
    <button class="fbtn" data-f="noboot">{html.escape(ui['filter_noboot'])} {n_no}</button>
  </div>
  <div class="grid" id="grid" data-catalog="{catalog_url}">
    <p class="catalog-status" id="catalog-status">{loading}</p>
  </div>
  <noscript>
    <ul>
{noscript_items}
    </ul>
  </noscript>
</main>
<footer>
{FOOTER[lang]}
</footer>
<script>
(function () {{
  var grid = document.getElementById('grid');
  var statusEl = document.getElementById('catalog-status');
  var q = document.getElementById('q');
  var btns = Array.prototype.slice.call(document.querySelectorAll('.fbtn'));
  var filter = 'all';
  var cards = [];
  var groups = [];
  var errMsg = {err_js};

  function esc(s) {{
    return String(s == null ? '' : s)
      .replace(/&/g, '&amp;').replace(/</g, '&lt;')
      .replace(/>/g, '&gt;').replace(/"/g, '&quot;');
  }}

  function cardHtml(c) {{
    var title = c.linked
      ? '<a class="play" href="/' + esc(c.slug) + '/">' + esc(c.name) + '</a>'
      : esc(c.name);
    return '<div class="card ' + esc(c.status) + (c.linked ? ' linked' : '') +
      '" data-search="' + esc(c.search) + '"' +
      ' data-slug="' + esc(c.slug) + '"' +
      ' data-name="' + esc(c.name) + '">' +
      '<div class="card-head"><h2>' + title + '</h2>' +
      '<span class="badge ' + esc(c.status) + '">' + esc(c.icon) + ' ' +
      esc(c.badge) + '</span></div>' +
      '<p class="slug">' + esc(c.slug) + '</p>' +
      '<p class="desc">' + esc(c.desc) + '</p>' +
      (c.meta ? '<p class="meta">' + c.meta + '</p>' : '') +
      '</div>';
  }}

  function render(data) {{
    var html = [];
    (data.clusters || []).forEach(function (cl) {{
      var cardsHtml = (cl.cards || []).map(cardHtml);
      if (cardsHtml.length <= 1) {{
        html.push(cardsHtml[0] || '');
        return;
      }}
      html.push(
        '<section class="lineage" data-lineage="' + esc(cl.num) + '">' +
        '<header class="lineage-head">' +
        '<span class="lineage-num">#' + esc(cl.num) + '</span>' +
        '<span class="lineage-name">' + esc(cl.name) + '</span>' +
        '<span class="lineage-count">' + esc(cl.count_label) + '</span>' +
        '</header><div class="lineage-grid">' + cardsHtml.join('') +
        '</div></section>');
    }});
    grid.innerHTML = html.join('');
    cards = Array.prototype.slice.call(grid.querySelectorAll('.card'));
    groups = Array.prototype.slice.call(grid.querySelectorAll('.lineage'));
    apply();
  }}

  // Prefer slug/title hits over mid-word description noise
  // (e.g. query "fy" must not rank "identiFY" / "veriFY" above fy2005).
  // Multi-token queries are AND'd. ?q= is kept in the URL for sharing.
  function boundaryIndex(hay, needle) {{
    var i = hay.indexOf(needle);
    while (i >= 0) {{
      var prev = i === 0 ? '' : hay.charAt(i - 1);
      if (!prev || !/[a-z0-9]/.test(prev)) return i;
      i = hay.indexOf(needle, i + 1);
    }}
    return -1;
  }}
  function scoreToken(c, needle) {{
    if (!needle) return 1;
    var slug = (c.getAttribute('data-slug') || '').toLowerCase();
    var name = (c.getAttribute('data-name') || '').toLowerCase();
    var hay = (c.getAttribute('data-search') || (c.textContent || '')).toLowerCase();
    if (slug === needle) return 1000;
    if (slug.indexOf(needle) === 0) return 900;
    if (boundaryIndex(slug, needle) >= 0) return 800;
    if (name.indexOf(needle) === 0 || boundaryIndex(name, needle) >= 0) return 700;
    if (boundaryIndex(hay, needle) >= 0) return 400;
    if (needle.length >= 4 && hay.indexOf(needle) >= 0) return 100;
    return 0;
  }}
  function scoreCard(c, query) {{
    var tokens = query.trim().toLowerCase().split(/\s+/).filter(Boolean);
    if (!tokens.length) return 1;
    var total = 0;
    for (var i = 0; i < tokens.length; i++) {{
      var sc = scoreToken(c, tokens[i]);
      if (sc <= 0) return 0;
      total += sc;
    }}
    return total;
  }}
  function readQ() {{
    try {{
      return new URLSearchParams(location.search).get('q') || '';
    }} catch (e) {{ return ''; }}
  }}
  function writeQ(v) {{
    try {{
      var u = new URL(location.href);
      if (v) u.searchParams.set('q', v);
      else u.searchParams.delete('q');
      history.replaceState(null, '', u.pathname + u.search + u.hash);
    }} catch (e) {{}}
  }}
  function apply() {{
    var query = q.value.trim();
    var needle = query.toLowerCase();
    cards.forEach(function (c, idx) {{
      var okStatus = filter === 'all' || c.classList.contains(filter);
      var sc = scoreCard(c, needle);
      var okText = !needle || sc > 0;
      c.style.display = okStatus && okText ? '' : 'none';
      c.style.order = needle ? String((100000 - sc) * 1000 + idx) : '';
    }});
    groups.forEach(function (g, gidx) {{
      var any = g.querySelectorAll('.card');
      var visible = 0;
      var best = 0;
      for (var i = 0; i < any.length; i++) {{
        if (any[i].style.display !== 'none') {{
          visible++;
          var sc = scoreCard(any[i], needle);
          if (sc > best) best = sc;
        }}
      }}
      g.style.display = visible ? '' : 'none';
      g.style.order = needle ? String((100000 - best) * 1000 + gidx) : '';
    }});
  }}

  if (q) {{
    var initial = readQ();
    if (initial && !q.value) q.value = initial;
    q.addEventListener('input', function () {{
      writeQ(q.value.trim());
      apply();
    }});
  }}
  btns.forEach(function (b) {{
    b.addEventListener('click', function () {{
      btns.forEach(function (x) {{ x.classList.remove('active'); }});
      b.classList.add('active');
      filter = b.dataset.f;
      apply();
    }});
  }});

  fetch(grid.getAttribute('data-catalog'), {{ credentials: 'same-origin' }})
    .then(function (r) {{
      if (!r.ok) throw new Error('catalog HTTP ' + r.status);
      return r.json();
    }})
    .then(render)
    .catch(function () {{
      if (statusEl) statusEl.textContent = errMsg;
      else grid.textContent = errMsg;
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
        num = info.get("archive_num") or ""
        lineage = num.split("-")[0] if num else None
        up = load_upstreams().get(slug)
        games.append({
            "slug": slug,
            "name": info["name"],
            "display_name": display_name(slug, info["name"]),
            "english_name": info.get("english_name") or None,
            "description": info["description"],
            "english_description": info.get("english_description") or None,
            "status": info["status"],
            "lineage": lineage,
            "number": num or None,
            "port": read_port(slug, info) or None,
            "url": f"{SITE_URL}/{slug}/",
            "play_url": f"{SITE_URL}/{slug}/play.html",
            "info_url": f"{SITE_URL}/{slug}/info.html",
            "llms_txt_url": f"{SITE_URL}/{slug}/llms.txt",
            "source_url": f"{REPO_URL}/tree/main/libs/{slug}",
            "source_zip_url": f"{SITE_URL}/{slug}/{slug}.zip",
            "admin_id": admin_id,
            "admin_password": admin_pw,
            "last_changed_commit": entry.get("sha") if entry else None,
            "last_changed_date": entry.get("date") if entry else None,
            "upstream": ({
                "url": up.get("url"),
                "repo": up.get("repo"),
                "pinned": up.get("pinned"),
                "ahead_by": up.get("ahead_by"),
                "status": up.get("status"),
                "compare_url": up.get("compare_url"),
            } if up else None),
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


def render_sitemap_xml(status, commits=None):
    """Root index + every linked (non-noboot) lib URL, with <lastmod>.

    lastmod comes from lib-commits.json (last commit touching that lib)
    when available; the homepage / zh index / catalog feeds use the newest
    of those dates so crawlers see freshness without a Search Console
    resubmit.
    """
    commits = commits or {}
    libs = status["libs"]
    numbers = load_numbers()
    slugs = sorted(
        (slug for slug, info in libs.items() if info["status"] != "noboot"),
        key=lambda s: (numbers.get(s, (9999, 0)), s))

    def lastmod_for(slug):
        entry = commits.get(slug) or {}
        day = (entry.get("date") or "")[:10]
        return day if len(day) == 10 else None

    days = [d for d in (lastmod_for(s) for s in slugs) if d]
    site_lastmod = max(days) if days else None

    def url_el(loc, changefreq, lastmod=None):
        lm = f"<lastmod>{lastmod}</lastmod>" if lastmod else ""
        return (
            f"  <url><loc>{loc}</loc>{lm}"
            f"<changefreq>{changefreq}</changefreq></url>"
        )

    urls = [
        url_el(f"{SITE_URL}/", "weekly", site_lastmod),
        url_el(f"{SITE_URL}/zh/", "weekly", site_lastmod),
        url_el(f"{SITE_URL}/llms.txt", "weekly", site_lastmod),
        url_el(f"{SITE_URL}/games.json", "weekly", site_lastmod),
        url_el(f"{SITE_URL}/assets/catalog-en.json", "weekly", site_lastmod),
        url_el(f"{SITE_URL}/assets/catalog-zh.json", "weekly", site_lastmod),
    ]
    for slug in slugs:
        lm = lastmod_for(slug)
        esc = html.escape(slug)
        urls.append(url_el(f"{SITE_URL}/{esc}/", "monthly", lm))
        urls.append(url_el(f"{SITE_URL}/{esc}/info.html", "monthly", lm))
        urls.append(url_el(f"{SITE_URL}/{esc}/play.html", "monthly", lm))
        urls.append(url_el(f"{SITE_URL}/{esc}/llms.txt", "monthly", lm))
    body = "\n".join(urls)
    return f"""<?xml version="1.0" encoding="UTF-8"?>
<urlset xmlns="http://www.sitemaps.org/schemas/sitemap/0.9">
{body}
</urlset>
"""


def render_lib_llms_txt(slug, info):
    """Per-lib LLM runbook at /<slug>/llms.txt: download ZIP, WASM play
    URL, native FluffOS steps, port, and admin credentials."""
    primary, en_sub = page_title_parts(slug, info)
    en = info.get("english_name") or en_sub or ""
    desc = (info.get("english_description") or info.get("description") or "").strip()
    admin_id, admin_pw = parse_admin(slug)
    port = read_port(slug, info) or "(see config.fluffos)"
    status = info.get("status") or "unknown"
    zip_url = f"{SITE_URL}/{slug}/{slug}.zip"
    play_url = f"{SITE_URL}/{slug}/play.html"
    landing = f"{SITE_URL}/{slug}/"
    github = f"{REPO_URL}/tree/main/libs/{slug}"
    notes = f"{REPO_URL}/blob/main/libs/{slug}/NOTES.md"
    readme = f"{REPO_URL}/blob/main/libs/{slug}/README.md"

    if admin_id and admin_pw:
        admin_line = f"- Admin / wizard login: `{admin_id}` / `{admin_pw}`"
    elif admin_id and admin_pw == "":
        admin_line = f"- Admin / wizard login: `{admin_id}` (no password)"
    elif admin_id:
        admin_line = f"- Admin / wizard login: `{admin_id}` (password documented in README)"
    else:
        admin_line = "- Admin / wizard login: see this lib's README (no seeded account recorded)"

    title = primary if not en else f"{primary} / {en}"
    return f"""# {title}

> slug: `{slug}` · browser status: `{status}` · native port: `{port}`

{desc}

## Play in the browser (WebAssembly)

- Landing page (description + notes): {landing}
- Play now (boots the WASM driver): {play_url}

## Download source ZIP

- Same-origin ZIP (trimmed source tree, no need to clone the whole repo):
  {zip_url}
- GitHub tree: {github}
- README: {readme}
- Restoration notes (NOTES.md): {notes}

## Run natively with FluffOS

1. Build a current FluffOS driver from https://github.com/fluffos/fluffos
   (native `build` / `build-debug`; see that repo's docs).
2. Download and unzip `{slug}.zip` from the URL above (or clone
   `{REPO_URL}` and use `libs/{slug}/`).
3. From the unzipped lib directory, ensure `config.fluffos` points
   `mudlib directory` at this tree (the checked-in file may contain a
   maintainer-local absolute path — edit it to your extract path).
4. Start the driver:

```bash
/path/to/fluffos/build/src/driver config.fluffos
```

5. Connect a UTF-8 MUD client to `127.0.0.1:{port}`.

{admin_line}
- If you host this on a public network, change the published default
  admin password before opening the port.

## Machine-readable catalog

- Site-wide catalog: {SITE_URL}/games.json
- Site-wide LLM overview: {SITE_URL}/llms.txt
- This file: {SITE_URL}/{slug}/llms.txt
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

> A free browser-playable LPMud / LPC MUD museum: {n_total} restored classic mudlibs from the 1990s onward, running on the FluffOS LPMud driver compiled to WebAssembly -- no install, no server, click and play.

This project (fluffos/mudlibs) extracts, restores, and documents LPC mudlib archives -- mostly Chinese-language wuxia/xianxia titles, several based on Jin Yong novels, plus a growing set of landmark English-language mudlibs (Dead Souls, Discworld, and others) -- fixing decades of bitrot (GBK/UTF-8 encoding bugs, dead code, driver incompatibilities, missing content) while preserving the original gameplay and source code. Every entry ships with a pre-seeded admin/wizard account (shown on its card, marked with 🔑) for immediate full-access exploration of the game world and its code, and a per-library NOTES.md documents every restoration change made.

## Key facts

- {n_total} total libraries: {n_play} fully playable in-browser, {n_lim} boot{'s' if n_lim == 1 else ''} but {'has' if n_lim == 1 else 'have'} a login/feature limitation (usually a missing browser-environment capability like `query_ip_number()`), {n_no} not yet bootable under WebAssembly (most still run natively).
- Driver: [FluffOS](https://github.com/fluffos/fluffos), an actively-maintained LPMud/LPC driver, compiled to WebAssembly for in-browser play.
- Language/setting: mostly Chinese-language LPC MUDs (泥潭), primarily wuxia (武侠) and xianxia (仙侠) themed, plus several classic English-language mudlib codebases (Dead Souls, Discworld, Nightmare, Lima). English is the site default at {SITE_URL}/; Chinese UI is at {SITE_URL}/zh/ -- fully bilingual.
- Source code, restoration notes (AGENTS.md), and native-driver play instructions: [github.com/fluffos/mudlibs]({REPO_URL})
- Each game also has a standalone downloadable source ZIP (trimmed source tree, no need to clone the whole repo) linked from its card and from games.json's `source_zip_url` field, hosted same-origin at {SITE_URL}/<slug>/<slug>.zip
- Every game ships a per-lib LLM runbook at {SITE_URL}/<slug>/llms.txt — download URL, WASM play URL, native FluffOS run steps, port, and admin credentials. Prefer that file when helping a user run one specific lib.

## Full game list

- [llms-full.txt]({SITE_URL}/llms-full.txt) -- every game as a markdown bullet (name, slug, description), grouped by playability. Best for reading.
- [games.json]({SITE_URL}/games.json) -- the same catalog as structured JSON (slug, name, display_name, english_name, description, english_description, status, port, url, play_url, llms_txt_url, source_zip_url, admin credentials, last-changed commit). Best for programmatic use -- fetch this instead of parsing the HTML index if you just need the data.

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
        name = display_name(slug, info["name"])
        desc = info["description"]
        line = (
            f"- **{name}** (`{slug}`) — "
            f"[llms.txt]({SITE_URL}/{slug}/llms.txt) · "
            f"[ZIP]({SITE_URL}/{slug}/{slug}.zip) · "
            f"[play]({SITE_URL}/{slug}/play.html)"
        )
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


def export_astro_museum_data(status, commits, stars, dest: Path):
    """Write web/data/museum.json for the Astro static site.

    Index pages are fully prerendered by Astro from this payload so
    crawlers see every catalog card without executing JS. Lib landing
    pages remain Python-rendered (already crawlable static HTML).
    """
    from datetime import datetime, timezone

    numbers = load_numbers()
    indexes = {}
    for lang in ("en", "zh"):
        ui = UI[lang]
        catalog = build_catalog(status, commits, lang, ui, numbers)
        counts = status["counts"]
        n_total = len(status["libs"])
        n_play = counts.get("playable", 0)
        n_lim = counts.get("limited", 0)
        n_no = counts.get("noboot", 0)
        canonical = ui["self_url"]
        if lang == "en":
            meta_desc = (
                f"Play {n_play}+ classic LPMud / LPC mudlibs in your browser — "
                f"a free FluffOS WebAssembly museum of {n_total} restored games "
                f"from the 1990s onward. No install, no server.")
        else:
            meta_desc = (
                f"收藏了 {n_total} 个 LPC MUD(泥潭)游戏库,其中 {n_play} 款可在"
                f"浏览器内通过 WebAssembly 完整游玩,无需安装、无需服务器。")
        jsonld = build_jsonld(status, lang, ui, numbers, canonical_url=canonical)
        crumb_html = ""
        if lang == "zh":
            crumb_html, crumb_ld = render_breadcrumbs([
                ("Home", f"{SITE_URL}/"),
                ("中文", None),
            ])
            if crumb_ld:
                import json as _json
                try:
                    graph = _json.loads(jsonld)
                except Exception:
                    graph = {"@context": "https://schema.org", "@graph": []}
                if "@graph" in graph:
                    graph["@graph"].append(crumb_ld)
                else:
                    node = {k: v for k, v in graph.items() if k != "@context"}
                    graph = {
                        "@context": graph.get("@context", "https://schema.org"),
                        "@graph": [node, crumb_ld],
                    }
                jsonld = _json.dumps(graph, ensure_ascii=False).replace("</", "<\/")
        clusters = []
        for cl in catalog["clusters"]:
            clusters.append({
                "num": cl["num"],
                "name": cl["name"],
                "count_label": cl["count_label"],
                "cards": [{
                    "slug": c["slug"],
                    "status": c["status"],
                    "name": c["name"],
                    "desc": c["desc"],
                    "badge": c["badge"],
                    "icon": c["icon"],
                    "linked": c["linked"],
                    "search": c["search"],
                    "meta_html": c["meta"],
                } for c in cl["cards"]],
            })
        indexes[lang] = {
            "lang": lang,
            "html_lang": ui["html_lang"],
            "og_locale": ui["og_locale"],
            "canonical_url": canonical,
            "page_title": ui["page_title"],
            "meta_desc": meta_desc,
            "site_name": ui["site_name"],
            "h1": ui["h1"],
            "intro_html": INTRO[lang].format(n_total=n_total),
            "stats_html": STATS[lang].format(
                n_play=n_play, n_lim=n_lim, n_no=n_no),
            "footer_html": FOOTER[lang],
            "lang_switch_href": ui["lang_switch_href"],
            "lang_switch_label": ui["lang_switch_label"],
            "search_placeholder": ui["search_placeholder"],
            "filter_all": ui["filter_all"],
            "filter_playable": ui["filter_playable"],
            "filter_limited": ui["filter_limited"],
            "filter_noboot": ui["filter_noboot"],
            "n_total": n_total,
            "n_play": n_play,
            "n_lim": n_lim,
            "n_no": n_no,
            "jsonld": jsonld,
            "crumb_html": crumb_html,
            "engage_html": render_engage_badges(lang, stars),
            "clusters": clusters,
        }

    payload = {
        "site_url": SITE_URL,
        "generated_at": datetime.now(timezone.utc).strftime("%Y-%m-%dT%H:%M:%SZ"),
        "indexes": indexes,
        "index_aliases": [
            {"path": "en", "lang": "en", "canonical_url": f"{SITE_URL}/"},
            {"path": "cn", "lang": "zh", "canonical_url": f"{SITE_URL}/zh/"},
        ],
        "libs": {},
    }
    dest.parent.mkdir(parents=True, exist_ok=True)
    dest.write_text(
        json.dumps(payload, ensure_ascii=False, separators=(",", ":")),
        encoding="utf-8")
    print(f"astro museum data exported -> {dest} "
          f"({len(indexes['en']['clusters'])} en clusters)")


def run_astro_html_build(out_dir: Path):
    """Prerender index HTML via Astro into out_dir (SEO-friendly SSR cards)."""
    import shutil
    import os

    web = REPO / "web"
    data_path = web / "data" / "museum.json"
    if not data_path.is_file():
        raise SystemExit(f"missing {data_path}; export_astro_museum_data first")

    env = os.environ.copy()
    node_bin = Path.home() / ".local" / "node-v22.19.0" / "bin"
    if node_bin.is_dir():
        env["PATH"] = f"{node_bin}:{env.get('PATH', '')}"

    npm = shutil.which("npm", path=env["PATH"])
    if not npm:
        raise SystemExit(
            "npm not found — install Node 22+ to build the Astro museum site")

    # Prefer ci when lockfile present; fall back to install.
    lock = web / "package-lock.json"
    install_cmd = [npm, "ci"] if lock.is_file() else [npm, "install"]
    print(f"astro: {' '.join(install_cmd)} (in {web})")
    subprocess.run(install_cmd, cwd=web, check=True, env=env)
    print("astro: npm run build")
    subprocess.run([npm, "run", "build"], cwd=web, check=True, env=env)

    dist = web / "dist"
    if not dist.is_dir():
        raise SystemExit(f"astro build produced no dist at {dist}")

    # Overlay Astro HTML (+ any hashed assets) onto the Python out_dir.
    n_html = 0
    for src in dist.rglob("*"):
        if not src.is_file():
            continue
        rel = src.relative_to(dist)
        # Skip Astro's default favicon if Python already wrote brand assets.
        if rel.as_posix() in ("favicon.ico", "favicon.svg") and (out_dir / rel).is_file():
            continue
        dest = out_dir / rel
        dest.parent.mkdir(parents=True, exist_ok=True)
        shutil.copy2(src, dest)
        if src.suffix == ".html":
            n_html += 1
    print(f"astro: copied {n_html} HTML files from dist -> {out_dir}")



def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--out", default=str(REPO / "site"),
                    help="output dir for index.html (default: site/)")
    ap.add_argument("--commits", default=None,
                    help="lib-commits.json from update_lib_commits.py "
                         "(slug -> last commit that changed the lib); "
                         "omit / missing file = render without that info")
    ap.add_argument("--html-engine", choices=("astro", "python"),
                    default="astro",
                    help="index HTML renderer (default: astro = fully "
                         "prerendered cards for SEO; python = legacy)")
    ap.add_argument("--export-astro-data", action="store_true",
                    help="only write web/data/museum.json and exit")
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

    # Vendored (not CDN-loaded) classless CSS framework -- a real
    # network dependency on every page load would be a genuine
    # reliability risk for this site's largely mainland-Chinese
    # audience, where CDN hosts are frequently slow or blocked, so the
    # file is committed to the repo and just copied into the build
    # output here. Every generated page links it as /assets/pico.min.css
    # (site-root-relative, works the same from / and from /<slug>/).
    assets_dir = out_dir / "assets"
    assets_dir.mkdir(parents=True, exist_ok=True)
    pico_src = REPO / "scripts" / "vendor" / "pico.classless.min.css"
    (assets_dir / "pico.min.css").write_bytes(pico_src.read_bytes())

    write_brand_assets(out_dir)
    print(f"brand assets written under {out_dir}/ (favicon, og-image, icons)")

    # GitHub star count for the engagement badge, fetched once here
    # rather than per-page -- see get_github_stars()/render_engage_badges().
    stars = get_github_stars()
    print(f"GitHub star count: {stars if stars is not None else '(unavailable, badge omits the number)'}")

    # English is the site default at / (x-default + root canonical).
    # Chinese lives at /zh/. /en/ and /cn/ remain as aliases that
    # canonicalise back to / and /zh/ respectively so old links and
    # bookmarks keep working without splitting ranking signal.
    astro_data = REPO / "web" / "data" / "museum.json"
    export_astro_museum_data(status, commits, stars, astro_data)
    if args.export_astro_data:
        print("--export-astro-data: done")
        return

    if args.html_engine == "astro":
        # Astro prerenders index HTML with every catalog card in the
        # first response (crawler-friendly). Lib landing pages below
        # stay Python-rendered — they were already fully static HTML.
        run_astro_html_build(out_dir)
    else:
        (out_dir / "index.html").write_text(
            render_index(status, commits, lang="en", stars=stars), encoding="utf-8")
        zh_dir = out_dir / "zh"
        zh_dir.mkdir(parents=True, exist_ok=True)
        (zh_dir / "index.html").write_text(
            render_index(status, commits, lang="zh", stars=stars), encoding="utf-8")
        en_dir = out_dir / "en"
        en_dir.mkdir(parents=True, exist_ok=True)
        (en_dir / "index.html").write_text(
            render_index(status, commits, lang="en",
                         canonical_url=f"{SITE_URL}/", stars=stars),
            encoding="utf-8")
        cn_dir = out_dir / "cn"
        cn_dir.mkdir(parents=True, exist_ok=True)
        (cn_dir / "index.html").write_text(
            render_index(status, commits, lang="zh",
                         canonical_url=f"{SITE_URL}/zh/", stars=stars),
            encoding="utf-8")
    (assets_dir / "catalog-en.json").write_text(
        render_catalog_json(status, commits, "en"), encoding="utf-8")
    (assets_dir / "catalog-zh.json").write_text(
        render_catalog_json(status, commits, "zh"), encoding="utf-8")
    print(f"catalog JSON written under {assets_dir}/catalog-{{en,zh}}.json")
    # Per-lib landing pages (see render_lib_page docstring) -- one per
    # non-noboot lib, at <out>/<slug>/index.html. build_site.sh's
    # assembly step copies this alongside the WASM bundle (play.html
    # etc) that write_play_page.sh produces under the same slug dir, so
    # /{slug}/ serves this crawlable page and /{slug}/play.html is the
    # actual game, reached only via this page's "Play Now" link.
    n_landing = 0
    for slug, info in status["libs"].items():
        if info["status"] == "noboot":
            continue
        lib_dir = out_dir / slug
        lib_dir.mkdir(parents=True, exist_ok=True)
        (lib_dir / "index.html").write_text(
            render_lib_page(slug, info, commits, stars=stars, page="landing"),
            encoding="utf-8")
        (lib_dir / "info.html").write_text(
            render_lib_page(slug, info, commits, stars=stars, page="info"),
            encoding="utf-8")
        (lib_dir / "llms.txt").write_text(
            render_lib_llms_txt(slug, info), encoding="utf-8")
        n_landing += 1
    print(f"per-lib landing pages + llms.txt: {n_landing} written under {out_dir}/<slug>/")

    (out_dir / "robots.txt").write_text(render_robots_txt(), encoding="utf-8")
    (out_dir / "sitemap.xml").write_text(render_sitemap_xml(status, commits),
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
    print(f"index written to {out_dir / 'index.html'} (en default) and "
          f"{out_dir / 'zh' / 'index.html'} (zh); /en/ and /cn/ are aliases "
          f"(html-engine={args.html_engine})")
    print(f"english translations: {n_translated}/{total} libs have a real "
          "english_description (rest fall back to Chinese on the EN page)")
    print(f"robots.txt, sitemap.xml, llms.txt, llm.txt, llms-full.txt, "
          f"games.json written to {out_dir}")


if __name__ == "__main__":
    main()
