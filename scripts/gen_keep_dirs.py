#!/usr/bin/env python3
"""Regenerate scripts/wasm_keep_dirs.txt: per-lib directories that exist in
the LOCAL working tree but contain no git-tracked files, so a CI checkout
(which only materializes tracked files) would lack them entirely.

Why this matters for the web packs: many libs' log_file()/write_file()/
save_object() calls throw -- and silently abort the caller -- when a target
directory is missing at ANY depth (see AGENTS.md's missing-directory-
swallows-errors pattern).  Locally these dirs exist (created by real boots:
work/log/..., data/topten/, ...) but they are gitignored, so
scripts/web_shell_override/zip-loader.js recreates them at play time from
this file (baked into each lib's fluffos-boot.js by write_play_page.sh) --
a zip archive has no notion of an empty directory to preload.

The zip never contains log/ (make_source_zips.sh trims it), so a log/
subdirectory that a lib writes into can ONLY reach the site through this
file.  A lib missing its log subdirs on the site can look healthy to a
local WASM check and still die for every visitor (Foundation I: the
new-character prompt logs to /log/secure and aborts).

Run this from a machine where the libs have actually been booted (i.e. the
runtime dir shapes exist on disk) whenever a lib gains new runtime dirs,
and commit the result.

Usage:
  python3 scripts/gen_keep_dirs.py                  # every lib, REPLACE all lines
  python3 scripts/gen_keep_dirs.py SLUG [SLUG ...]  # rescan only these libs,
                                                    # replace only their lines
  python3 scripts/gen_keep_dirs.py --merge [SLUG ...]
      # same scan, but only ADD dirs: existing lines are never dropped.
      # Prefer this: a full replace forgets every dir the local tree no
      # longer has (cleaned trees, libs checked out elsewhere), and the site
      # then loses them.  A full scan takes ~15 minutes; naming slugs takes
      # seconds.

A lib whose work/ is a submodule (gitlink) has its tracked dirs read from
the submodule's own index, otherwise every dir would look untracked.
"""

import subprocess
import sys
from pathlib import Path, PurePosixPath

REPO = Path(__file__).resolve().parent.parent
OUT = REPO / "scripts" / "wasm_keep_dirs.txt"

# dirs the packer trims anyway -- no point recording shape beneath them
# (top-level, relative to work/)
TRIMMED_TOP = {"www", "temp", "backup"}


def is_gitlink(slug):
    out = subprocess.run(
        ["git", "-C", str(REPO), "ls-files", "-s", "--", f"libs/{slug}/work"],
        check=True, capture_output=True).stdout.decode('utf-8', 'surrogateescape')
    return any(line.split(None, 1)[0] == "160000" for line in out.splitlines())


def tracked_dirs(slug):
    """All dirs (relative to work/) that contain at least one tracked file."""
    if is_gitlink(slug):
        # paths are already relative to work/ when asked in the submodule
        out = subprocess.run(
            ["git", "-C", str(REPO / "libs" / slug / "work"), "ls-files", "-z"],
            check=True, capture_output=True).stdout.decode('utf-8', 'surrogateescape')
        prefix = ""
    else:
        out = subprocess.run(
            ["git", "-C", str(REPO), "ls-files", "-z", f"libs/{slug}/work/"],
            check=True, capture_output=True).stdout.decode('utf-8', 'surrogateescape')
        prefix = f"libs/{slug}/work/"
    dirs = set()
    for f in out.split("\0"):
        if not f.startswith(prefix) or not f:
            continue
        rel = Path(f[len(prefix):]).parent
        while rel != Path("."):
            dirs.add(rel.as_posix())
            rel = rel.parent
    return dirs


def scan(slug):
    """Dirs under libs/<slug>/work/ with no tracked file, in Path sort order."""
    work = REPO / "libs" / slug / "work"
    have_tracked = tracked_dirs(slug)
    found = []
    for d in sorted(work.rglob("*")):
        if not d.is_dir():
            continue
        rel = d.relative_to(work).as_posix()
        parts = rel.split("/")
        if parts[0] in TRIMMED_TOP or "fluffos64" in parts:
            continue
        if rel not in have_tracked:
            found.append(rel)
    return found


def read_lines():
    """The file's lines in their on-disk order (blocks are not strictly slug-
    sorted: onboarding commits appended their own blocks, so order is kept)."""
    if not OUT.is_file():
        return []
    text = OUT.read_text(encoding="utf-8", errors="surrogateescape")
    return [line for line in text.split("\n") if line]


def set_block(lines, slug, rels, merge):
    """Replace (or, with merge, extend) slug's lines in place; a lib with no
    block yet is appended at the end.  Everything else stays byte-identical."""
    prefix = slug + "\t"
    idx = [i for i, line in enumerate(lines) if line.startswith(prefix)]
    old = [lines[i][len(prefix):] for i in idx]
    if merge:
        union = set(old) | set(rels)
        rels = sorted(union, key=lambda r: PurePosixPath(r).parts)
        if rels == old:
            return lines
    new = [prefix + r for r in rels]
    if not idx:
        return lines + new
    first = idx[0]
    rest = [line for i, line in enumerate(lines) if i not in set(idx)]
    return rest[:first] + new + rest[first:]


def scannable(slug):
    lib = REPO / "libs" / slug
    return (lib / "work").is_dir() and (lib / "config.fluffos").is_file()


def main(argv):
    merge = "--merge" in argv
    named = [a for a in argv if not a.startswith("--")]
    bad = [a for a in argv if a.startswith("--") and a != "--merge"]
    if bad:
        sys.exit(f"unknown option(s): {' '.join(bad)}")
    libs_dir = REPO / "libs"
    if named:
        for s in named:
            if not scannable(s):
                sys.exit(f"{s}: no libs/{s}/work or config.fluffos")
        targets = named
    else:
        targets = [lib.name for lib in sorted(libs_dir.iterdir()) if scannable(lib.name)]

    lines = read_lines()
    before = len(lines)
    if not named and not merge:
        lines = []            # full replace also drops libs that no longer exist
    for slug in targets:
        lines = set_block(lines, slug, scan(slug), merge)

    OUT.write_text("\n".join(lines) + "\n", encoding="utf-8",
                   errors="surrogateescape")
    print(f"{OUT}: {len(lines)} untracked dirs recorded "
          f"({before} before; {len(targets)} lib(s) scanned"
          f"{', merge' if merge else ''})")


if __name__ == "__main__":
    main(sys.argv[1:])
