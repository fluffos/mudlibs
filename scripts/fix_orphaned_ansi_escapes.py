#!/usr/bin/env python3
"""Repair ANSI escape sequences that lost their leading ESC (0x1b) byte
during this project's GB18030->UTF-8 conversion pass.

Root cause: some archives colored individual GBK-encoded glyph bytes by
wrapping each raw byte in its own escape sequence, e.g.
  ESC[0;1;35m <GBK byte> ESC[1m <GBK byte> ESC[0m
a legacy technique some GB2312/GBK-era MUD ANSI art relied on (splitting
a color change across single, otherwise-undecodable GBK bytes). The
lossy GB18030->UTF-8 fallback used on these files correctly dropped the
orphaned, undecodable GBK bytes, but also incorrectly ate the ESC byte
off the immediately-following escape sequence -- turning valid color
codes into literal garbage text like "[1m[0m" in the terminal.

Fix: find a real escape sequence "\x1b[...m" immediately followed by one
or more bracket-notation "[...]m" groups with NO \x1b prefix, and insert
the missing \x1b before each such orphaned group (applied repeatedly so
a whole run of consecutive orphaned groups all get fixed). The original
GBK art-glyph bytes themselves are unrecoverable -- they relied on
undocumented legacy terminal-specific rendering of split multi-byte
sequences with no clean UTF-8 equivalent -- but restoring the escape
codes themselves is the fixable, unambiguous part.

Usage: fix_orphaned_ansi_escapes.py [--dry-run] <file> [file ...]
"""
import re
import sys

PATTERN = re.compile(rb"(m)(\[[0-9;]*m)")
DETECT = re.compile(rb"\x1b\[[0-9;]*m(\[[0-9;]*m)+")


def fix(data: bytes) -> bytes:
    prev = None
    while prev != data:
        prev = data
        data = PATTERN.sub(lambda m: m.group(1) + b"\x1b" + m.group(2), data)
    return data


def main():
    args = sys.argv[1:]
    dry_run = "--dry-run" in args
    if dry_run:
        args.remove("--dry-run")

    for path in args:
        with open(path, "rb") as f:
            data = f.read()
        if not DETECT.search(data):
            continue
        fixed = fix(data)
        n_inserted = fixed.count(b"\x1b") - data.count(b"\x1b")
        if dry_run:
            print(f"{path}: would insert {n_inserted} missing ESC bytes")
            continue
        with open(path, "wb") as f:
            f.write(fixed)
        print(f"{path}: inserted {n_inserted} missing ESC bytes")


if __name__ == "__main__":
    main()
