#!/usr/bin/env python3
"""Maintain lib-commits.json -- per-lib "last commit that changed this lib".

Why this exists: the Pages workflow checks out the repo with fetch-depth: 1
(the repo carries ~4GB of history, a full clone is deliberately avoided), so
`git log -- libs/<slug>` cannot answer "when did this lib last change" -- with
one commit of history it would return HEAD's sha for every slug, which is just
whatever push triggered the run.  The true answer lives on the GitHub side, so
it is fetched from the commits API
(GET /repos/<repo>/commits?path=libs/<slug>&sha=<head>&per_page=1) and cached
in a mapping file that rides in the same persistent dir (actions/cache) as the
packed bundles.  gen_site_index.py renders it onto each index card.

Correctness model (mirrors build_site.sh's manifest.json provenance idea):
every entry records the libs/<slug> TREE HASH it was true for.  An entry is
reused iff its recorded tree equals HEAD's tree for that slug -- identical
tree means identical content, so "the last commit that actually changed it"
cannot have moved.  Everything else (missing entry, tree mismatch) is
re-queried from the API, pinned to HEAD's sha so racing newer pushes don't
bleed into this run's answer; entries for slugs gone from wasm_status.json
are pruned.  The mapping file is therefore a pure API-call saver, never an
authority: evicted, stale, or lost entirely (e.g. a cancel-in-progress run
that died before the cache save) just means re-querying the changed/missing
slugs on the next surviving run -- the same "durable anchor + disposable
cache" split the pages-state marker design established.  A full refresh is
~100 requests; the Actions GITHUB_TOKEN allows 1000/hour per repo.

API failures (rate limit, network, an unpushed local HEAD) keep the old
entry when one exists, else leave the slug absent -- the index then renders
that card without last-changed info.  This data is cosmetic, so the script
ALWAYS exits 0: it must never be able to block a deploy.

Usage: update_lib_commits.py --mapping FILE [--head SHA]
  --mapping  the lib-commits.json to read/update (created if missing)
  --head     commit sha to pin API queries to (default: HEAD of this repo)

Token: $GH_TOKEN or $GITHUB_TOKEN if set (CI), else `gh auth token` (local),
else unauthenticated (60 req/hour -- enough for incremental refreshes only).
"""

import argparse
import json
import os
import subprocess
import sys
import urllib.error
import urllib.request
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
GITHUB_REPO = os.environ.get("GITHUB_REPOSITORY", "fluffos/mudlibs")


def git(*args):
    return subprocess.run(
        ["git", "-C", str(REPO), *args],
        capture_output=True, text=True, check=False)


def get_token():
    for var in ("GH_TOKEN", "GITHUB_TOKEN"):
        if os.environ.get(var):
            return os.environ[var]
    r = subprocess.run(["gh", "auth", "token"], capture_output=True,
                       text=True, check=False)
    return r.stdout.strip() if r.returncode == 0 else ""


def query_last_commit(slug, head, token):
    """Return (sha, iso_date) of the last commit <= head touching
    libs/<slug>, or (None, reason) on any failure."""
    url = (f"https://api.github.com/repos/{GITHUB_REPO}/commits"
           f"?path=libs/{slug}&sha={head}&per_page=1")
    req = urllib.request.Request(url, headers={
        "Accept": "application/vnd.github+json",
        "User-Agent": "mudlibs-site-build",
        **({"Authorization": f"Bearer {token}"} if token else {}),
    })
    try:
        with urllib.request.urlopen(req, timeout=30) as resp:
            data = json.load(resp)
    except (urllib.error.URLError, OSError, ValueError) as e:
        return None, str(e)
    if not data:
        return None, "API returned no commits for this path"
    c = data[0]
    return c["sha"], c["commit"]["committer"]["date"]


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--mapping", required=True)
    ap.add_argument("--head", default=None)
    args = ap.parse_args()

    head = args.head
    if not head:
        head = git("rev-parse", "HEAD").stdout.strip()

    status = json.loads(
        (REPO / "scripts" / "wasm_status.json").read_text(encoding="utf-8"))
    slugs = sorted(status["libs"])

    mapping_path = Path(args.mapping)
    old = {}
    if mapping_path.is_file():
        try:
            old = json.loads(mapping_path.read_text(encoding="utf-8"))["libs"]
        except (ValueError, KeyError):
            print("warning: existing mapping unreadable; full refresh",
                  file=sys.stderr)

    token = get_token()
    new, reused, refreshed, failed = {}, 0, 0, []
    for slug in slugs:
        r = git("rev-parse", "-q", "--verify", f"HEAD:libs/{slug}")
        if r.returncode != 0:
            failed.append((slug, "no libs/<slug> tree at HEAD"))
            continue
        tree = r.stdout.strip()
        entry = old.get(slug)
        if entry and entry.get("tree") == tree:
            new[slug] = entry
            reused += 1
            continue
        sha, date_or_err = query_last_commit(slug, head, token)
        if sha:
            new[slug] = {"sha": sha, "date": date_or_err, "tree": tree}
            refreshed += 1
        else:
            failed.append((slug, date_or_err))
            if entry:  # keep the stale-but-real old value over nothing
                new[slug] = entry

    mapping_path.parent.mkdir(parents=True, exist_ok=True)
    mapping_path.write_text(
        json.dumps({"libs": new}, indent=1, sort_keys=True) + "\n",
        encoding="utf-8")

    print(f"lib-commits: {reused} reused, {refreshed} refreshed via API, "
          f"{len(failed)} failed, {len(new)} total -> {mapping_path}")
    for slug, why in failed:
        print(f"warning: {slug}: last-changed lookup failed ({why}); "
              "card will show "
              + ("the previous value" if slug in new else "no last-changed info"),
              file=sys.stderr)
    # Cosmetic data: never fail the build over it (see module docstring).
    sys.exit(0)


if __name__ == "__main__":
    main()
