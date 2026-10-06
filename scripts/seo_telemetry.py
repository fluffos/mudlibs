#!/usr/bin/env python3
"""Live SEO telemetry canaries for mudlibs.fluffos.info.

Two layers of SEO health (do not merge them):

  A) Publish invariant (CI) — scripts/verify_site_publish.py fails the
     Pages build if staging/sitemap claim URLs that site/ does not ship.
     That proves the *artifact* is coherent; it does not prove Google
     can fetch or rank the live origin.

  B) Live telemetry (this script) — HTTP canaries against the published
     origin, plus an optional GSC section when credentials exist.
     Run weekly (agent timer `mudlibs-seo-telemetry`) or ad-hoc after
     SEO-affecting site changes.

Exit codes:
  0  all hard canaries green
  1  one or more hard canaries failed
  2  usage / unexpected error

Writes scripts/seo_telemetry_report.json (gitignored-friendly; safe to
commit a snapshot if you want a baseline in-repo).
"""

from __future__ import annotations

import argparse
import json
import re
import sys
import time
import urllib.error
import urllib.request
import xml.etree.ElementTree as ET
from dataclasses import asdict, dataclass, field
from datetime import date, datetime, timezone
from pathlib import Path
from typing import Any
from urllib.parse import urlparse

SITE = "https://mudlibs.fluffos.info"
UA = "mudlibs-seo-telemetry/1.0 (+https://mudlibs.fluffos.info/; museum health check)"
SITEMAP_NS = {"sm": "http://www.sitemaps.org/schemas/sitemap/0.9"}

# Hard canaries: must stay 200 with the expected shape. Keep this list
# small — a few historically significant libs + the bilingual roots.
HARD_PATHS = [
    "/",
    "/zh/",
    "/llms.txt",
    "/games.json",
    "/robots.txt",
    "/sitemap.xml",
    "/lima/",
    "/lima/info.html",
    "/lima/play.html",
    "/lima/llms.txt",
    "/lima.html",  # SEO alias → same hub, canonical must point at /lima/
    "/tmi2/",
    "/tmi2.html",
    "/ds386/",
    "/fy2005/",
]

# Soft sample: pick N sitemap <loc>s and HEAD/GET them. Failures here
# warn but do not fail the run unless --strict-sample.
DEFAULT_SAMPLE = 24

REPO_SCRIPTS = Path(__file__).resolve().parent
DEFAULT_REPORT = REPO_SCRIPTS / "seo_telemetry_report.json"


@dataclass
class Check:
    name: str
    ok: bool
    detail: str
    hard: bool = True
    meta: dict[str, Any] = field(default_factory=dict)


def fetch(
    url: str,
    *,
    timeout: float = 30.0,
    method: str = "GET",
) -> tuple[int, dict[str, str], bytes]:
    req = urllib.request.Request(
        url,
        method=method,
        headers={"User-Agent": UA, "Accept": "*/*"},
    )
    try:
        with urllib.request.urlopen(req, timeout=timeout) as resp:
            headers = {k.lower(): v for k, v in resp.headers.items()}
            body = resp.read() if method != "HEAD" else b""
            return int(resp.status), headers, body
    except urllib.error.HTTPError as e:
        body = e.read() if method != "HEAD" else b""
        headers = {k.lower(): v for k, v in (e.headers or {}).items()}
        return int(e.code), headers, body


def extract_canonical(html: str) -> str | None:
    m = re.search(
        r'rel=["\']canonical["\']\s+href=["\']([^"\']+)["\']',
        html,
        re.I,
    )
    if m:
        return m.group(1)
    m = re.search(
        r'href=["\']([^"\']+)["\']\s+rel=["\']canonical["\']',
        html,
        re.I,
    )
    return m.group(1) if m else None


def extract_hreflang(html: str) -> dict[str, str]:
    out: dict[str, str] = {}
    for m in re.finditer(
        r'rel=["\']alternate["\'][^>]*hreflang=["\']([^"\']+)["\'][^>]*href=["\']([^"\']+)["\']',
        html,
        re.I,
    ):
        out[m.group(1)] = m.group(2)
    for m in re.finditer(
        r'hreflang=["\']([^"\']+)["\'][^>]*rel=["\']alternate["\'][^>]*href=["\']([^"\']+)["\']',
        html,
        re.I,
    ):
        out[m.group(1)] = m.group(2)
    return out


def parse_sitemap_locs(xml_bytes: bytes) -> list[tuple[str, str | None]]:
    root = ET.fromstring(xml_bytes)
    tag = root.tag.rsplit("}", 1)[-1]
    if tag == "sitemapindex":
        locs: list[tuple[str, str | None]] = []
        for sm in root.findall("sm:sitemap", SITEMAP_NS):
            loc = sm.findtext("sm:loc", default="", namespaces=SITEMAP_NS).strip()
            lastmod = sm.findtext("sm:lastmod", default=None, namespaces=SITEMAP_NS)
            if loc:
                # fetch child sitemaps
                code, _, body = fetch(loc)
                if code == 200:
                    locs.extend(parse_sitemap_locs(body))
        return locs
    out: list[tuple[str, str | None]] = []
    for url in root.findall("sm:url", SITEMAP_NS):
        loc = url.findtext("sm:loc", default="", namespaces=SITEMAP_NS).strip()
        lastmod = url.findtext("sm:lastmod", default=None, namespaces=SITEMAP_NS)
        if loc:
            out.append((loc, lastmod.strip() if lastmod else None))
    return out


def check_hard_paths() -> list[Check]:
    checks: list[Check] = []
    for path in HARD_PATHS:
        url = SITE + path
        code, headers, body = fetch(url)
        ctype = headers.get("content-type", "")
        detail = f"HTTP {code} content-type={ctype!r} bytes={len(body)}"
        ok = code == 200 and len(body) > 0
        meta: dict[str, Any] = {"url": url, "status": code}

        if ok and path.endswith(".xml"):
            try:
                locs = parse_sitemap_locs(body)
                meta["url_count"] = len(locs)
                # Expect a museum-scale sitemap (hundreds of locs).
                if len(locs) < 100:
                    ok = False
                    detail += f" sitemap_too_small={len(locs)}"
                else:
                    detail += f" sitemap_urls={len(locs)}"
                # Freshness: at least one lastmod within the last 14 days.
                today = date.today()
                fresh = 0
                for _, lm in locs:
                    if not lm:
                        continue
                    try:
                        d = date.fromisoformat(lm[:10])
                    except ValueError:
                        continue
                    if (today - d).days <= 14:
                        fresh += 1
                meta["fresh_lastmod_14d"] = fresh
                if fresh == 0:
                    ok = False
                    detail += " no_lastmod_within_14d"
            except ET.ParseError as e:
                ok = False
                detail += f" xml_parse_error={e}"

        if ok and path == "/robots.txt":
            text = body.decode("utf-8", errors="replace")
            if "Sitemap:" not in text or "sitemap.xml" not in text:
                ok = False
                detail += " robots_missing_sitemap_directive"
            if "Disallow: /" in text and "Allow: /" not in text:
                ok = False
                detail += " robots_disallows_all"

        if ok and path == "/games.json":
            try:
                data = json.loads(body)
                # Shape: {count: N, games: [...], site, repo, ...}
                if isinstance(data, list):
                    n = len(data)
                elif isinstance(data, dict):
                    games = data.get("games")
                    n = (
                        int(data["count"])
                        if isinstance(data.get("count"), int)
                        else len(games)
                        if isinstance(games, list)
                        else 0
                    )
                else:
                    n = 0
                meta["games_count"] = n
                if n < 50:
                    ok = False
                    detail += f" games_json_too_small={n}"
                else:
                    detail += f" games={n}"
            except json.JSONDecodeError as e:
                ok = False
                detail += f" json_error={e}"

        if ok and ("text/html" in ctype or path.endswith("/") or path.endswith(".html")):
            html = body.decode("utf-8", errors="replace")
            canon = extract_canonical(html)
            meta["canonical"] = canon
            if not canon:
                ok = False
                detail += " missing_canonical"
            else:
                # Alias /lima.html must canonicalize to /lima/
                if path.endswith(".html") and "/" not in path.strip("/"):
                    slug = path.strip("/").removesuffix(".html")
                    expected = f"{SITE}/{slug}/"
                    if canon.rstrip("/") != expected.rstrip("/"):
                        ok = False
                        detail += f" alias_canonical_wrong={canon}"
                detail += f" canonical={canon}"
            if path in ("/", "/zh/"):
                hl = extract_hreflang(html)
                meta["hreflang"] = hl
                for need in ("en", "zh-CN", "x-default"):
                    if need not in hl:
                        ok = False
                        detail += f" missing_hreflang_{need}"

        checks.append(Check(name=f"hard:{path}", ok=ok, detail=detail, hard=True, meta=meta))
    return checks


def check_sitemap_sample(n: int, *, strict: bool) -> list[Check]:
    code, _, body = fetch(f"{SITE}/sitemap.xml")
    if code != 200:
        return [
            Check(
                name="sample:sitemap_fetch",
                ok=False,
                detail=f"HTTP {code}",
                hard=True,
            )
        ]
    locs = [loc for loc, _ in parse_sitemap_locs(body)]
    # Prefer a spread: roots + mid + tail of the list.
    if not locs:
        return [Check(name="sample:empty", ok=False, detail="no locs", hard=True)]
    step = max(1, len(locs) // n)
    picked = locs[::step][:n]
    checks: list[Check] = []
    fails = 0
    for loc in picked:
        c, hdrs, b = fetch(loc)
        ok = c == 200 and len(b) > 0
        if not ok:
            fails += 1
        checks.append(
            Check(
                name=f"sample:{urlparse(loc).path}",
                ok=ok,
                detail=f"HTTP {c} bytes={len(b)} ctype={hdrs.get('content-type', '')!r}",
                hard=strict,
                meta={"url": loc, "status": c},
            )
        )
    # Aggregate: soft unless --strict-sample; still hard-fail if >25% dead.
    ratio = fails / max(1, len(picked))
    checks.insert(
        0,
        Check(
            name="sample:summary",
            ok=ratio <= 0.25,
            detail=f"sampled={len(picked)} failed={fails} fail_ratio={ratio:.2f}",
            hard=True,
            meta={"sampled": len(picked), "failed": fails, "sitemap_total": len(locs)},
        ),
    )
    return checks


def gsc_section_stub() -> dict[str, Any]:
    """Placeholder consumed by the weekly agent prompt via GSC MCP.

    This script stays dependency-free. The agent fills `gsc` in the
    report after calling gscServer tools (list_properties,
    get_performance_overview, batch_url_inspection, check_indexing_issues).
    """
    creds = Path.home() / ".config" / "gsc"
    has_secrets = (creds / "client_secrets.json").is_file()
    has_token = (creds / "credentials.json").is_file() or (
        creds / "token.json"
    ).is_file()
    return {
        "status": "skipped_no_oauth" if not has_token else "ready_for_agent_mcp",
        "has_client_secrets": has_secrets,
        "has_oauth_token": has_token,
        "property_hint": "https://mudlibs.fluffos.info/",
        "canary_urls": [
            f"{SITE}/",
            f"{SITE}/zh/",
            f"{SITE}/lima/",
            f"{SITE}/tmi2/",
            f"{SITE}/sitemap.xml",
        ],
        "weekly_checks": [
            "get_performance_overview: clicks/impressions/ctr/position last 28d",
            "compare_search_periods: this 28d vs prior 28d (alert on >30% click drop)",
            "batch_url_inspection: canary_urls indexing state",
            "check_indexing_issues: canary_urls",
            "list_sitemaps_enhanced: sitemap submitted + last downloaded",
        ],
    }


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--sample", type=int, default=DEFAULT_SAMPLE)
    ap.add_argument(
        "--strict-sample",
        action="store_true",
        help="Treat every sitemap sample miss as a hard failure",
    )
    ap.add_argument("--report", type=Path, default=DEFAULT_REPORT)
    ap.add_argument("--quiet", action="store_true")
    args = ap.parse_args()

    started = time.time()
    checks: list[Check] = []
    checks.extend(check_hard_paths())
    checks.extend(check_sitemap_sample(args.sample, strict=args.strict_sample))

    hard_fail = [c for c in checks if c.hard and not c.ok]
    soft_fail = [c for c in checks if not c.hard and not c.ok]

    report = {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "site": SITE,
        "duration_s": round(time.time() - started, 2),
        "ok": not hard_fail,
        "hard_failures": len(hard_fail),
        "soft_failures": len(soft_fail),
        "checks": [asdict(c) for c in checks],
        "gsc": gsc_section_stub(),
    }
    args.report.write_text(json.dumps(report, indent=2, sort_keys=True) + "\n")

    if not args.quiet:
        for c in checks:
            mark = "OK " if c.ok else ("FAIL" if c.hard else "WARN")
            print(f"{mark}  {c.name}: {c.detail}")
        print(
            f"\nreport -> {args.report}  "
            f"hard_fail={len(hard_fail)} soft_fail={len(soft_fail)} "
            f"duration={report['duration_s']}s"
        )
        if report["gsc"]["status"] == "skipped_no_oauth":
            print(
                "GSC: no OAuth token at ~/.config/gsc/ — complete "
                "gscServer.reauthenticate once, then the weekly agent "
                "prompt fills the ranking/indexing half."
            )

    return 1 if hard_fail else 0


if __name__ == "__main__":
    try:
        sys.exit(main())
    except KeyboardInterrupt:
        sys.exit(130)
    except Exception as e:  # noqa: BLE001 — top-level CLI guard
        print(f"error: {e}", file=sys.stderr)
        sys.exit(2)
