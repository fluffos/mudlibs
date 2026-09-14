#!/usr/bin/env python3
"""Fail the Pages build if the assembled site is missing URLs we claim
to publish.

History (2026-09-13): selective `cp` lists in build_site.sh silently
dropped artifacts that gen_site_index.py already wrote and that the
sitemap / lang-switch / landing pages linked to — first every
`/<slug>/llms.txt`, then the Chinese canonical `/zh/`. A hand-maintained
copy list will rot again the next time the generator grows an output;
this script is the backstop.

Checks (all must pass):
  1. Every file under index-staging/ exists at the same relative path in
     the assembled site/ (staging never holds play.html / .zip, so those
     site-only files are left alone).
  2. Every packable slug has play.html (written by write_play_page.sh,
     not by the generator).
  3. Every <loc> in sitemap.xml resolves to a real file under site/.
  4. The root and /zh/ lang-switch targets exist.
  5. Brand assets (favicon / og-image / icons) and catalog JSON exist.
  6. Homepage JSON-LD is the lean CollectionPage form (no giant ItemList).
  7. Sitemap entries carry <lastmod> when any lastmod is present (the
     generator always emits them once lib-commits.json has dates).

Usage: verify_site_publish.py <index-staging-dir> <site-dir>
Exit 0 on success; 1 with a missing-path report on failure.
"""

from __future__ import annotations

import json
import re
import sys
import xml.etree.ElementTree as ET
from pathlib import Path
from urllib.parse import urlparse

SITE_ORIGIN = "https://mudlibs.fluffos.info"


def main() -> int:
    if len(sys.argv) != 3:
        print(
            f"usage: {sys.argv[0]} <index-staging-dir> <site-dir>",
            file=sys.stderr,
        )
        return 2
    staging = Path(sys.argv[1]).resolve()
    site = Path(sys.argv[2]).resolve()
    if not staging.is_dir() or not site.is_dir():
        print(
            f"error: staging and site must be directories "
            f"(got {staging!s}, {site!s})",
            file=sys.stderr,
        )
        return 2

    missing: list[str] = []

    # --- 1. staging mirror -------------------------------------------------
    for src in staging.rglob("*"):
        if not src.is_file():
            continue
        rel = src.relative_to(staging)
        dst = site / rel
        if not dst.is_file():
            missing.append(f"staging→site missing: {rel.as_posix()}")

    # --- 2. play.html for every staged lib landing -------------------------
    for index in staging.glob("*/index.html"):
        slug = index.parent.name
        # skip language alias dirs
        if slug in ("zh", "en", "cn", "assets"):
            continue
        play = site / slug / "play.html"
        if not play.is_file():
            missing.append(f"play page missing: {slug}/play.html")
        alias = site / f"{slug}.html"
        if not alias.is_file():
            missing.append(f"SEO alias missing: {slug}.html")

    # --- 3. sitemap locs ---------------------------------------------------
    sitemap = site / "sitemap.xml"
    if not sitemap.is_file():
        missing.append("sitemap.xml missing from site/")
    else:
        try:
            root = ET.fromstring(sitemap.read_text(encoding="utf-8"))
        except ET.ParseError as e:
            missing.append(f"sitemap.xml parse error: {e}")
            root = None
        if root is not None:
            # ElementTree keeps the namespace URI in the tag when present.
            locs = [
                el.text.strip()
                for el in root.iter()
                if el.tag.endswith("loc") and el.text and el.text.strip()
            ]
            for loc in locs:
                path = sitemap_loc_to_path(loc)
                if path is None:
                    missing.append(f"sitemap loc outside site origin: {loc}")
                    continue
                if not site_path_exists(site, path):
                    missing.append(f"sitemap 404: {loc}  (expected {path})")

    # --- 4. lang-switch targets + brand/catalog assets ---------------------
    for required in (
        "index.html",
        "zh/index.html",
        "en/index.html",
        "cn/index.html",
        "llms.txt",
        "games.json",
        "robots.txt",
        "assets/pico.min.css",
        "favicon.ico",
        "og-image.png",
        "assets/icon.svg",
        "assets/apple-touch-icon.png",
        "assets/catalog-en.json",
        "assets/catalog-zh.json",
    ):
        if not (site / required).is_file():
            missing.append(f"required publish path missing: {required}")

    # --- 5. lean homepage JSON-LD ------------------------------------------
    index_html = site / "index.html"
    if index_html.is_file():
        text = index_html.read_text(encoding="utf-8", errors="replace")
        if '"@type":"ItemList"' in text or '"@type": "ItemList"' in text:
            missing.append(
                "index.html still embeds ItemList JSON-LD "
                "(expected lean CollectionPage only)"
            )
        if "CollectionPage" not in text:
            missing.append("index.html missing CollectionPage JSON-LD")
        if 'property="og:image"' not in text and "property='og:image'" not in text:
            missing.append("index.html missing og:image")
        if 'href="/favicon.ico"' not in text:
            missing.append("index.html missing favicon link")
        # Cards must not be SSR'd into the homepage anymore.
        if text.count('class="card ') > 2:
            missing.append(
                "index.html still server-renders catalog cards "
                "(expected client fetch of assets/catalog-*.json)"
            )

    # --- 6. sitemap lastmod consistency ------------------------------------
    sitemap = site / "sitemap.xml"
    if sitemap.is_file():
        sm = sitemap.read_text(encoding="utf-8", errors="replace")
        n_url = sm.count("<url>")
        n_last = sm.count("<lastmod>")
        # lastmod is emitted from lib-commits.json; a cold cache / local
        # gen without --commits yields zero dates — don't fail that case.
        # Once any lastmod exists, site-level URLs (/, /zh/, llms.txt,
        # games.json) must carry it too.
        if n_last and n_last < 4:
            missing.append(
                f"sitemap.xml has only {n_last} <lastmod> tags "
                f"(expected site-level URLs to carry lastmod too)"
            )

    if missing:
        print(
            "ERROR: assembled site is missing published paths "
            f"({len(missing)}):\n  - "
            + "\n  - ".join(missing),
            file=sys.stderr,
        )
        print(
            "\nThis usually means build_site.sh stopped copying something "
            "gen_site_index.py still writes (or sitemap/lang-switch still "
            "links to). Fix the assemble step; do not delete the verifier.",
            file=sys.stderr,
        )
        return 1

    n_staged = sum(1 for p in staging.rglob("*") if p.is_file())
    print(
        f"verify_site_publish: OK "
        f"({n_staged} staging files mirrored, sitemap locs resolve, "
        f"play.html + lang indexes present)"
    )
    return 0


def sitemap_loc_to_path(loc: str) -> str | None:
    """Map a sitemap <loc> URL to a site/-relative filesystem path."""
    parsed = urlparse(loc)
    if parsed.scheme and parsed.netloc:
        origin = f"{parsed.scheme}://{parsed.netloc}"
        if origin.rstrip("/") != SITE_ORIGIN.rstrip("/"):
            return None
        path = parsed.path or "/"
    else:
        path = loc
    if not path.startswith("/"):
        path = "/" + path
    if path.endswith("/"):
        return path.lstrip("/") + "index.html"
    return path.lstrip("/")


def site_path_exists(site: Path, rel: str) -> bool:
    p = site / rel
    if p.is_file():
        return True
    # GitHub Pages also serves dir/index.html for bare directories; accept
    # that form when the sitemap omitted the trailing slash.
    if not rel.endswith(".html") and not rel.endswith(".txt") and not rel.endswith(".json"):
        if (site / rel / "index.html").is_file():
            return True
    return False


if __name__ == "__main__":
    sys.exit(main())
