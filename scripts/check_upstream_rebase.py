#!/usr/bin/env python3
"""Discover git-hosted upstreams and see whether a rebase/pull is needed.

A lib has an upstream when meta.json's `archive` (or optional `upstream`
object) names a GitHub repo this collection was cloned from. See
AGENTS.md §2.3: fluffos-org hosted mudlibs (`hosting: fluffos-upstream`)
keep notes and build scripts only -- LPC fixes belong on that repo
and work/ is a git submodule. Other active remotes are
`submodule-patch` (submodule + patches/). Vendored libs have no
active git upstream. This script only *reports* whether upstream has
moved past the pinned clone commit. It never rebases.

Writes scripts/upstream_status.json for gen_site_index.py (cards +
landing pages) and for the librarian loop.

Usage: python3 scripts/check_upstream_rebase.py
       python3 scripts/check_upstream_rebase.py --offline   # parse only
Token: $GH_TOKEN or $GITHUB_TOKEN, else `gh auth token`.
Always exits 0 -- a failed API call must not block a site deploy.
"""
import json
import os
import re
import subprocess
import sys
import urllib.error
import urllib.request
from datetime import datetime, timezone
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
OUT = REPO / "scripts" / "upstream_status.json"
NUMBERING = REPO / "scripts" / "lib_numbering.json"

GITHUB_RE = re.compile(
    r"(?:https://github\.com/|github\.com/|gh repo clone )"
    r"([A-Za-z0-9_.-]+)/([A-Za-z0-9_.-]+?)(?:\.git)?(?=[\s,)/]|$)",
    re.I,
)
COMMIT_RE = re.compile(r"(?:commit|HEAD)\s+([0-9a-f]{7,40})", re.I)
SKIP_REPOS = {("fluffos", "mudlibs"), ("fluffos", "fluffos")}


def get_token():
    for var in ("GH_TOKEN", "GITHUB_TOKEN"):
        if os.environ.get(var):
            return os.environ[var]
    r = subprocess.run(
        ["gh", "auth", "token"], capture_output=True, text=True, check=False)
    return r.stdout.strip() if r.returncode == 0 else ""


def github_get(path, token):
    url = f"https://api.github.com{path}"
    req = urllib.request.Request(url, headers={
        "Accept": "application/vnd.github+json",
        "User-Agent": "mudlibs-upstream-check",
        **({"Authorization": f"Bearer {token}"} if token else {}),
    })
    with urllib.request.urlopen(req, timeout=30) as resp:
        return json.loads(resp.read().decode("utf-8"))


def parse_upstreams(entry):
    """Return a list of {owner, repo, url, pinned} from meta."""
    explicit = entry.get("upstream") or {}
    archive = entry.get("archive") or ""
    found = []
    if explicit.get("url"):
        m = GITHUB_RE.search(explicit["url"])
        if m:
            owner, repo = m.group(1), m.group(2)
            found.append({
                "owner": owner,
                "repo": repo,
                "url": f"https://github.com/{owner}/{repo}",
                "pinned": (explicit.get("commit") or "").strip() or None,
                "branch": (explicit.get("branch") or "").strip() or None,
            })
    for owner, repo in GITHUB_RE.findall(archive):
        if (owner.lower(), repo.lower()) in SKIP_REPOS:
            continue
        url = f"https://github.com/{owner}/{repo}"
        if any(f["url"].lower() == url.lower() for f in found):
            continue
        found.append({
            "owner": owner,
            "repo": repo,
            "url": url,
            "pinned": None,
        })
    shas = COMMIT_RE.findall(archive)
    if found and shas and not found[0]["pinned"]:
        found[0]["pinned"] = shas[0]
    # extra SHAs map onto extra repos when counts match
    if len(shas) > 1 and len(found) > 1:
        for i, sha in enumerate(shas[1:], start=1):
            if i < len(found) and not found[i]["pinned"]:
                found[i]["pinned"] = sha
    return found


def check_one(item, token):
    owner, repo = item["owner"], item["repo"]
    pinned = item.get("pinned")
    out = {
        "url": item["url"],
        "repo": f"{owner}/{repo}",
        "pinned": pinned,
        "default_branch": None,
        "head": None,
        "ahead_by": None,
        "status": "unknown_pin",
        "compare_url": item["url"],
        "error": None,
    }
    if not token:
        out["status"] = "offline" if not pinned else "unknown_pin"
        out["error"] = "no GitHub token"
        return out
    try:
        info = github_get(f"/repos/{owner}/{repo}", token)
    except urllib.error.HTTPError as e:
        out["status"] = "gone" if e.code == 404 else "error"
        out["error"] = f"HTTP {e.code}"
        return out
    except (urllib.error.URLError, TimeoutError, json.JSONDecodeError) as e:
        out["status"] = "error"
        out["error"] = str(e)
        return out
    branch = item.get("branch") or info.get("default_branch") or "master"
    out["default_branch"] = branch
    try:
        head = github_get(f"/repos/{owner}/{repo}/commits/{branch}", token)
        out["head"] = head.get("sha")
    except (urllib.error.HTTPError, urllib.error.URLError, TimeoutError) as e:
        out["status"] = "error"
        out["error"] = f"head: {e}"
        return out
    if not pinned:
        out["status"] = "unknown_pin"
        if out["head"]:
            out["compare_url"] = f"{item['url']}/tree/{out['head'][:7]}"
        return out
    try:
        cmp_ = github_get(
            f"/repos/{owner}/{repo}/compare/{pinned}...{branch}", token)
    except urllib.error.HTTPError as e:
        out["status"] = "error"
        out["error"] = f"compare HTTP {e.code}"
        if out["head"]:
            out["compare_url"] = f"{item['url']}/compare/{pinned}...{branch}"
        return out
    except (urllib.error.URLError, TimeoutError, json.JSONDecodeError) as e:
        out["status"] = "error"
        out["error"] = str(e)
        return out
    ahead = cmp_.get("ahead_by")
    out["ahead_by"] = ahead
    out["compare_url"] = f"{item['url']}/compare/{pinned}...{branch}"
    if ahead == 0:
        out["status"] = "current"
    elif ahead and ahead > 0:
        out["status"] = "behind"
    else:
        out["status"] = "error"
        out["error"] = f"unexpected ahead_by={ahead!r}"
    return out


def load_entries():
    if not NUMBERING.is_file():
        subprocess.run(
            [sys.executable, str(REPO / "scripts" / "assemble_numbering.py")],
            check=False, cwd=REPO)
    data = json.loads(NUMBERING.read_text(encoding="utf-8"))
    return [e for e in data["libs"] if not e.get("duplicate_of")]


def main():
    offline = "--offline" in sys.argv
    token = "" if offline else get_token()
    entries = load_entries()
    libs = {}
    n_behind = 0
    for entry in entries:
        ups = parse_upstreams(entry)
        if not ups:
            continue
        slug = entry["slug"]
        primary = ups[0]
        checked = check_one(primary, token) if not offline else {
            "url": primary["url"],
            "repo": f"{primary['owner']}/{primary['repo']}",
            "pinned": primary.get("pinned"),
            "default_branch": None,
            "head": None,
            "ahead_by": None,
            "status": "offline" if primary.get("pinned") else "unknown_pin",
            "compare_url": primary["url"],
            "error": "offline",
        }
        extras = []
        for extra in ups[1:]:
            extras.append({
                "url": extra["url"],
                "repo": f"{extra['owner']}/{extra['repo']}",
                "pinned": extra.get("pinned"),
            })
        checked["extra_repos"] = extras
        checked["owner"] = primary["owner"]
        hosting = entry.get("hosting")
        if not hosting and primary["owner"].lower() == "fluffos":
            hosting = "fluffos-upstream"
        checked["hosting"] = hosting
        libs[slug] = checked
        if checked["status"] == "behind":
            n_behind += 1
            print(f"BEHIND  {slug:22} {checked['repo']:36} "
                  f"{checked.get('pinned') or '?'} +{checked.get('ahead_by')}",
                  flush=True)
        elif checked["status"] in ("error", "gone"):
            print(f"{checked['status'].upper():7} {slug:22} "
                  f"{checked['repo']:36} {checked.get('error')}",
                  flush=True)

    doc = {
        "checked_at": datetime.now(timezone.utc).strftime("%Y-%m-%dT%H:%M:%SZ"),
        "offline": offline or not token,
        "count": len(libs),
        "behind": n_behind,
        "libs": libs,
    }
    OUT.write_text(json.dumps(doc, ensure_ascii=False, indent=2) + "\n",
                   encoding="utf-8")
    print(f"wrote {len(libs)} upstreams ({n_behind} behind) -> {OUT}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
