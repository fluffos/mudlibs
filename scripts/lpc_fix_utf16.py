#!/usr/bin/env python3
"""scripts/lpc_fix_utf16.py [SLUG...] [--apply]

A `.lpc` / `.h` file stored as UTF-16 (a NUL byte between all characters) stops the driver at the first NUL:
`Illegal embedded NUL byte (0x00) in source`.  Two shapes in the corpus (KB 03 section 4.7):

  blank   the file is nothing but UTF-16 spaces (`\\x00 \\x00 ...`, 713 characters in the Hangzhou escort NPC `d/hangzhou/npc/tangzi.lpc` of the
          hy family and xkxyb, the same for xkxyb's guanjia, jiading, wolfdog): the author blanked the object and the old driver compiled an
          empty program.  The file becomes a single line break (an empty program again), which compiles.
  text    real UTF-16 source that decodes cleanly: saved as UTF-8, line endings as found (none survives in the corpus: fy2mg's wizard copy of
          `/system/feature/attack.c` is big-endian ASCII that changes byte alignment at its first Chinese comment, and is left).

The byte order comes from the BOM, else from where the NUL bytes sit in the first 64 bytes (even offsets = big endian).  A file that does not decode cleanly (a binary
that kept its `.lpc` name, a blank prefix with a few shifted bytes of code behind it, a switch of byte alignment) is listed and left.
Binary-safe; without --apply the plan is printed (FIX / SKIP lines); idempotent."""
import os
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def convert(b):
    """-> (new bytes, kind) or (None, reason)"""
    if len(b) < 4 or len(b) % 2:
        return None, "odd length"
    nul = b.count(b"\0")
    if nul * 10 < len(b) * 4:
        return None, "not UTF-16"
    if b.startswith(b"\xff\xfe"):
        enc, body = "utf-16-le", b[2:]
    elif b.startswith(b"\xfe\xff"):
        enc, body = "utf-16-be", b[2:]
    else:
        head = b[:64]       # the alignment at the start decides; a file that changes alignment later fails the noise check below
        even = sum(1 for i in range(0, len(head), 2) if head[i] == 0)
        odd = sum(1 for i in range(1, len(head), 2) if head[i] == 0)
        enc, body = ("utf-16-be", b) if even >= odd else ("utf-16-le", b)
    try:
        s = body.decode(enc)
    except UnicodeDecodeError:
        return None, "does not decode as " + enc
    if "\0" in s:
        return None, "NUL after decoding (binary)"
    if not s.strip():
        return b"\n", "blank"
    solid = [c for c in s if not c.isspace()]
    control = sum(1 for c in s if c < " " and c not in "\r\n\t")
    odd = sum(1 for c in s if c >= "\x80" and not (0x3000 <= ord(c) <= 0x303F or 0x4E00 <= ord(c) <= 0x9FFF or 0xFF00 <= ord(c) <= 0xFFEF))
    if sum(1 for c in solid if c < "\x80") * 5 < len(solid) * 2 or (odd + control) * 200 > len(s):
        return None, "decodes to noise (binary, a shifted fragment, or text that changes byte alignment half way)"
    return s.encode("utf-8"), "text"


def main():
    args = sys.argv[1:]
    apply = "--apply" in args
    only = [a for a in args if not a.startswith("--")]
    raw = subprocess.run(["git", "-c", "core.quotepath=false", "ls-files", "-z", "--", "libs/*/work/*.lpc", "libs/*/work/*.h"], cwd=REPO,
                         capture_output=True).stdout.split(b"\0")
    nfix = 0
    for r in raw:
        if not r:
            continue
        rel = r.decode("utf-8", "surrogateescape")
        slug = rel.split("/")[1]
        if only and slug not in only:
            continue
        if slug in ("wllz3", "longyunmeng_binary"):
            continue
        full = os.path.join(REPO, rel)
        try:
            b = open(full, "rb").read()
        except OSError:
            continue
        if not b or b.count(b"\0") * 10 < len(b) * 4:
            continue
        new, kind = convert(b)
        where = f"{slug} /{rel.split('/work/', 1)[1]}"
        if new is None:
            print(f"SKIP  {where}: {kind}")
            continue
        nfix += 1
        print(f"FIX   {where}: {kind}")
        if apply:
            open(full, "wb").write(new)
    print(f"{nfix} file(s)" + ("" if apply else " (plan only; --apply writes)"))


if __name__ == "__main__":
    main()
