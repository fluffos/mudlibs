#!/usr/bin/env python3
"""Apply libs/<slug>/patches/*.patch onto libs/<slug>/work.

For hosting=submodule-patch, work/ is an upstream git submodule and
catalog-only FluffOS-compat lives in patches/ (NNNN-name.patch, git
apply -p1 from work/). fluffos-upstream libs (active fluffos-org
remotes only) should have an empty patches/ — those fixes belong
on github.com/fluffos/<repo>. An archived fluffos remote is not
fluffos-upstream (lima → limalib/lima).

Usage: python3 scripts/apply_lib_patches.py <slug>
       python3 scripts/apply_lib_patches.py <slug> --work DIR
       python3 scripts/apply_lib_patches.py --all

--work DIR applies libs/<slug>/patches onto DIR instead of
libs/<slug>/work (used by make_source_zips.sh so the live
submodule stays clean).
"""
import argparse
import subprocess
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
LIBS = REPO / "libs"


def patch_files(slug: str):
    d = LIBS / slug / "patches"
    if not d.is_dir():
        return []
    return sorted(
        p for p in d.iterdir()
        if p.is_file() and p.suffix == ".patch" and not p.name.startswith(".")
    )


def apply_one(slug, work=None):
    work = Path(work) if work else (LIBS / slug / "work")
    if not work.is_dir():
        print(f"SKIP {slug}: no work/", file=sys.stderr)
        return 1
    files = patch_files(slug)
    if not files:
        print(f"OK   {slug}: no patches")
        return 0
    for patch in files:
        check = subprocess.run(
            ["git", "apply", "--check", "-p1", str(patch)],
            cwd=work, capture_output=True, text=True)
        if check.returncode != 0:
            print(f"FAIL {slug}: {patch.name}: {check.stderr.strip()}",
                  file=sys.stderr)
            return 1
        applied = subprocess.run(
            ["git", "apply", "-p1", str(patch)],
            cwd=work, capture_output=True, text=True)
        if applied.returncode != 0:
            print(f"FAIL {slug}: apply {patch.name}: {applied.stderr.strip()}",
                  file=sys.stderr)
            return 1
        print(f"OK   {slug}: {patch.name}")
    return 0


def all_slugs():
    return sorted(
        p.name for p in LIBS.iterdir()
        if p.is_dir() and (p / "patches").is_dir()
    )


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("slugs", nargs="*", help="lib slugs, or --all")
    parser.add_argument("--all", action="store_true")
    parser.add_argument("--work", help="apply patches onto this dir")
    args = parser.parse_args()
    if args.all:
        slugs = all_slugs()
    else:
        slugs = args.slugs
    if not slugs:
        parser.print_help()
        return 2
    if args.work and len(slugs) != 1:
        print("error: --work requires exactly one slug", file=sys.stderr)
        return 2
    rc = 0
    for slug in slugs:
        rc |= apply_one(slug, work=args.work)
    return rc


if __name__ == "__main__":
    sys.exit(main())
