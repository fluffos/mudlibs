#!/usr/bin/env python3
"""Check tracked git paths for Windows / NTFS compatibility and UTF-8 hygiene.

Flags:
  - Non-UTF-8 path bytes
  - Characters illegal on NTFS (< > : " / \\ | ? * or control chars 0x00..0x1f)
  - Path components ending with '.' or ' ' (Windows strips them silently)
  - Windows reserved device names (CON, PRN, AUX, NUL, COM1..9, LPT1..9)
  - Case-only duplicate file or directory paths
  - Case-insensitive file vs directory collisions

Exit code: 0 if clean, 1 if any violations are found.
"""

from __future__ import annotations

import argparse
from collections import defaultdict
import re
import subprocess
import sys

RESERVED_STEMS = (
    {"con", "prn", "aux", "nul"}
    | {f"com{i}" for i in range(1, 10)}
    | {f"lpt{i}" for i in range(1, 10)}
)
ILLEGAL_CHAR_RE = re.compile(r'[<>:"\\|?*\x00-\x1f]')


def check_paths(raw_paths: list[bytes]) -> dict[str, list]:
    non_utf8: list[bytes] = []
    illegal: list[str] = []
    case_files: dict[str, list[str]] = defaultdict(list)
    immediate_dirs: set[str] = set()

    for raw in raw_paths:
        if not raw:
            continue
        try:
            path = raw.decode("utf-8")
        except UnicodeDecodeError:
            non_utf8.append(raw)
            continue

        if "/" in path:
            parent = path.rsplit("/", 1)[0]
            immediate_dirs.add(parent)

        bad = False
        if ILLEGAL_CHAR_RE.search(path):
            bad = True
        else:
            for seg in path.split("/"):
                if not seg:
                    continue
                if seg.endswith((".", " ")):
                    bad = True
                    break
                if seg.split(".", 1)[0].lower() in RESERVED_STEMS:
                    bad = True
                    break
        if bad:
            illegal.append(path)

        case_files[path.lower()].append(path)

    all_dirs: set[str] = set()
    for d in immediate_dirs:
        cur = d
        while cur and cur not in all_dirs:
            all_dirs.add(cur)
            if "/" not in cur:
                break
            cur = cur.rsplit("/", 1)[0]

    case_dirs: dict[str, list[str]] = defaultdict(list)
    for d in all_dirs:
        case_dirs[d.lower()].append(d)

    case_file_dups = [sorted(v) for v in case_files.values() if len(v) > 1]
    case_dir_dups = [sorted(v) for v in case_dirs.values() if len(v) > 1]

    file_vs_dir = []
    for k, files in case_files.items():
        if k in case_dirs:
            file_vs_dir.append((sorted(files), sorted(case_dirs[k])))

    return {
        "non_utf8": sorted(non_utf8),
        "illegal": sorted(illegal),
        "case_file_dups": sorted(case_file_dups),
        "case_dir_dups": sorted(case_dir_dups),
        "file_vs_dir": sorted(file_vs_dir),
    }


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument(
        "paths",
        nargs="*",
        help="Optional git pathspecs (defaults to entire repository)",
    )
    parser.add_argument(
        "--verbose", "-v", action="store_true", help="Print every violating path"
    )
    args = parser.parse_args()

    cmd = ["git", "ls-files", "-z"]
    if args.paths:
        cmd.extend(["--", *args.paths])
    out = subprocess.check_output(cmd)
    res = check_paths(out.split(b"\x00"))

    counts = {k: len(v) for k, v in res.items()}
    total = sum(counts.values())
    print(
        f"non_utf8={counts['non_utf8']} illegal={counts['illegal']} "
        f"case_file_dups={counts['case_file_dups']} "
        f"case_dir_dups={counts['case_dir_dups']} "
        f"file_vs_dir={counts['file_vs_dir']}"
    )

    if args.verbose:
        for raw in res["non_utf8"]:
            print("NON-UTF8:", raw.decode("utf-8", "surrogateescape"))
        for p in res["illegal"]:
            print("ILLEGAL:", repr(p))
        for grp in res["case_file_dups"]:
            print("CASE-FILE:", grp)
        for grp in res["case_dir_dups"]:
            print("CASE-DIR:", grp)
        for f, d in res["file_vs_dir"]:
            print("FILE-VS-DIR:", f, d)

    return 1 if total else 0


if __name__ == "__main__":
    sys.exit(main())
