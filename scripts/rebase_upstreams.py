#!/usr/bin/env python3
"""Twice-daily helper: bump behind upstream submodule pins when safe.

Invoked by an agent-armed cursor-subscriptions timer
(`mudlibs-upstream-rebase`, cron `0 4,16 * * *` UTC) — not by a
GitHub Action. See AGENTS.md §2.3 hosting modes.

Policy:
  - Refresh scripts/upstream_status.json first (check_upstream_rebase.py).
  - For each lib with status=behind whose work/ is a real git submodule:
      fetch upstream HEAD, verify every patches/*.patch still applies
      with `git apply --check`, then detach work/ at HEAD and rewrite
      meta.json upstream.commit (+ archive pin text when present).
  - Never leave patches applied in work/ (zips apply them at pack time).
  - Skip vendored trees and unknown pins. Patch-check / fetch failures
    are reported for human review (the waking agent opens/updates an
    issue titled "Upstream rebase: patch-check failures").

Usage:
  python3 scripts/rebase_upstreams.py            # check + rebase
  python3 scripts/rebase_upstreams.py --check    # status JSON only
  python3 scripts/rebase_upstreams.py --dry-run  # show what would move
  python3 scripts/rebase_upstreams.py --skip-check

Exit 0 when every behind lib was skipped-with-reason or successfully
bumped (or none were behind). Exit 1 when at least one behind lib
failed patch-check / fetch so the agent can surface it.
"""
from __future__ import annotations

import argparse
import json
import subprocess
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
LIBS = REPO / "libs"
STATUS = REPO / "scripts" / "upstream_status.json"
REPORT = REPO / "scripts" / "upstream_rebase_report.json"
CHECK = REPO / "scripts" / "check_upstream_rebase.py"


def run(cmd, cwd=None, check=True):
    return subprocess.run(
        cmd, cwd=cwd, check=check, text=True, capture_output=True)


def is_git_checkout(work: Path) -> bool:
    git = work / ".git"
    return git.is_file() or git.is_dir()


def patch_files(slug: str):
    d = LIBS / slug / "patches"
    if not d.is_dir():
        return []
    return sorted(
        p for p in d.iterdir()
        if p.is_file() and p.suffix == ".patch" and not p.name.startswith(".")
    )


def patches_apply_clean(work: Path, patches: list[Path]) -> tuple[bool, str]:
    for patch in patches:
        r = run(
            ["git", "apply", "--check", "-p1", str(patch)],
            cwd=work, check=False)
        if r.returncode != 0:
            err = (r.stderr or r.stdout or "").strip() or f"exit {r.returncode}"
            return False, f"{patch.name}: {err}"
    return True, ""


def rewrite_meta_pin(meta_path: Path, new_sha: str) -> bool:
    data = json.loads(meta_path.read_text(encoding="utf-8"))
    up = data.get("upstream") or {}
    old = (up.get("commit") or "").strip()
    if not old:
        return False
    up["commit"] = new_sha
    data["upstream"] = up
    archive = data.get("archive") or ""
    if old and old in archive:
        data["archive"] = archive.replace(old, new_sha)
    meta_path.write_text(
        json.dumps(data, ensure_ascii=False, indent=2) + "\n",
        encoding="utf-8")
    return True


def rebase_one(slug: str, info: dict, dry_run: bool) -> dict:
    work = LIBS / slug / "work"
    meta_path = LIBS / slug / "meta.json"
    head = (info.get("head") or "").strip()
    pinned = (info.get("pinned") or "").strip()
    ahead = info.get("ahead_by")
    if not head:
        return {"slug": slug, "result": "skip", "detail": "no upstream HEAD"}
    if not pinned:
        return {"slug": slug, "result": "skip", "detail": "unknown pin"}
    if head == pinned:
        return {"slug": slug, "result": "skip", "detail": "already at HEAD"}
    if not work.is_dir() or not is_git_checkout(work):
        return {
            "slug": slug, "result": "skip",
            "detail": "work/ is not a git submodule checkout",
        }
    if not meta_path.is_file():
        return {"slug": slug, "result": "skip", "detail": "missing meta.json"}

    fetch = run(["git", "fetch", "--quiet", "origin"], cwd=work, check=False)
    if fetch.returncode != 0:
        return {
            "slug": slug, "result": "fail",
            "detail": f"git fetch failed: {(fetch.stderr or '').strip()}",
        }

    # Discard accidental in-place dirt (e.g. apply_lib_patches.py) so
    # checkout can move. Scheduled CI checkouts are clean; local trees
    # sometimes aren't.
    run(["git", "reset", "--hard", "HEAD"], cwd=work, check=False)
    run(["git", "clean", "-fd"], cwd=work, check=False)

    prev = run(["git", "rev-parse", "HEAD"], cwd=work).stdout.strip()
    co = run(["git", "checkout", "--detach", "--quiet", head],
             cwd=work, check=False)
    if co.returncode != 0:
        return {
            "slug": slug, "result": "fail",
            "detail": f"checkout {head[:12]}: {(co.stderr or '').strip()}",
        }

    patches = patch_files(slug)
    ok, detail = patches_apply_clean(work, patches)
    if not ok:
        run(["git", "checkout", "--detach", "--quiet", prev],
            cwd=work, check=False)
        return {
            "slug": slug, "result": "fail",
            "detail": f"patches do not apply on {head[:12]}: {detail}",
        }

    if dry_run:
        run(["git", "checkout", "--detach", "--quiet", prev],
            cwd=work, check=False)
        return {
            "slug": slug, "result": "would_bump",
            "detail": (
                f"{pinned[:12]} -> {head[:12]} (+{ahead}, "
                f"{len(patches)} patches ok)"
            ),
        }

    if not rewrite_meta_pin(meta_path, head):
        run(["git", "checkout", "--detach", "--quiet", prev],
            cwd=work, check=False)
        return {
            "slug": slug, "result": "fail",
            "detail": "meta.json upstream.commit missing; left work/ restored",
        }

    return {
        "slug": slug, "result": "bumped",
        "detail": (
            f"{pinned[:12]} -> {head[:12]} (+{ahead}, "
            f"{len(patches)} patches ok)"
        ),
    }


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--check", action="store_true",
                    help="only refresh upstream_status.json")
    ap.add_argument("--dry-run", action="store_true")
    ap.add_argument("--skip-check", action="store_true",
                    help="reuse existing upstream_status.json")
    args = ap.parse_args()

    if not args.skip_check:
        print("refreshing upstream_status.json …", flush=True)
        r = subprocess.run([sys.executable, str(CHECK)], cwd=REPO)
        if r.returncode != 0:
            print("check_upstream_rebase.py failed", file=sys.stderr)
            return 1
    if args.check:
        return 0

    if not STATUS.is_file():
        print(f"missing {STATUS}", file=sys.stderr)
        return 1

    doc = json.loads(STATUS.read_text(encoding="utf-8"))
    if doc.get("offline"):
        print(
            "upstream_status.json is offline (no GitHub token); "
            "refusing to rebase. Set GH_TOKEN/GITHUB_TOKEN.",
            file=sys.stderr,
        )
        return 2
    behind = {
        slug: info for slug, info in (doc.get("libs") or {}).items()
        if info.get("status") == "behind"
    }
    if not behind:
        print("no behind upstreams")
        REPORT.write_text(
            json.dumps({
                "checked_at": doc.get("checked_at"),
                "results": [],
                "bumped": 0, "failed": 0, "skipped": 0,
            }, ensure_ascii=False, indent=2) + "\n",
            encoding="utf-8")
        return 0

    results = []
    for slug in sorted(behind):
        print(f"rebase {slug} …", flush=True)
        results.append(rebase_one(slug, behind[slug], args.dry_run))

    bumped = [r for r in results if r["result"] in ("bumped", "would_bump")]
    failed = [r for r in results if r["result"] == "fail"]
    skipped = [r for r in results if r["result"] == "skip"]

    print("\n=== upstream rebase summary ===")
    for r in results:
        print(f"{r['result']:10} {r['slug']:22} {r['detail']}")
    print(f"bumped={len(bumped)} failed={len(failed)} skipped={len(skipped)}")

    REPORT.write_text(
        json.dumps({
            "checked_at": doc.get("checked_at"),
            "results": results,
            "bumped": len(bumped),
            "failed": len(failed),
            "skipped": len(skipped),
        }, ensure_ascii=False, indent=2) + "\n",
        encoding="utf-8")

    return 1 if failed else 0


if __name__ == "__main__":
    sys.exit(main())
