#!/usr/bin/env python3
"""Regenerate scripts/wasm_keep_dirs.txt: per-lib directories that exist in
the LOCAL working tree but contain no git-tracked files, so a CI checkout
(which only materializes tracked files) would lack them entirely.

Why this matters for the web packs: many libs' log_file()/write_file()/
save_object() calls throw -- and silently abort the caller -- when a target
directory is missing at ANY depth (see AGENTS.md's missing-directory-
swallows-errors pattern).  Locally these dirs exist (created by real boots:
work/log/..., data/topten/, ...) but they are gitignored, so
scripts/pack_lib_for_web.sh recreates their SHAPE in the packed image from
this file (0-byte .keep placeholders; emscripten's file_packager only
materializes directories that contain files).

Run this from a machine where the libs have actually been booted (i.e. the
runtime dir shapes exist on disk) whenever a lib gains new runtime dirs,
and commit the result.

Usage: python3 scripts/gen_keep_dirs.py
"""

import subprocess
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
OUT = REPO / "scripts" / "wasm_keep_dirs.txt"

# dirs the packer trims anyway -- no point recording shape beneath them
# (top-level, relative to work/)
TRIMMED_TOP = {"www", "temp", "backup"}


def tracked_dirs(slug):
    """All dirs (relative to work/) that contain at least one tracked file."""
    out = subprocess.run(
        ["git", "-C", str(REPO), "ls-files", "-z", f"libs/{slug}/work/"],
        check=True, capture_output=True).stdout.decode('utf-8', 'surrogateescape')
    dirs = set()
    prefix = f"libs/{slug}/work/"
    for f in out.split("\0"):
        if not f.startswith(prefix):
            continue
        rel = Path(f[len(prefix):]).parent
        while rel != Path("."):
            dirs.add(rel.as_posix())
            rel = rel.parent
    return dirs


def main():
    lines = []
    libs_dir = REPO / "libs"
    for lib in sorted(libs_dir.iterdir()):
        work = lib / "work"
        if not work.is_dir() or not (lib / "config.fluffos").is_file():
            continue
        slug = lib.name
        have_tracked = tracked_dirs(slug)
        for d in sorted(work.rglob("*")):
            if not d.is_dir():
                continue
            rel = d.relative_to(work).as_posix()
            parts = rel.split("/")
            if parts[0] in TRIMMED_TOP or "fluffos64" in parts:
                continue
            if rel not in have_tracked:
                lines.append(f"{slug}\t{rel}")
    OUT.write_text("\n".join(lines) + "\n", encoding="utf-8",
                   errors="surrogateescape")
    print(f"{OUT}: {len(lines)} untracked dirs recorded")


if __name__ == "__main__":
    main()
