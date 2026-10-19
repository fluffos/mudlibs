#!/usr/bin/env python3
"""scripts/lpc_scan_high_bytes.py [SLUG...] [--summary]

Files whose code holds a byte >= 0x80 (KB 03 section 4.5): the driver's `Illegal character 0xNN`.  Comments, strings and `@MARKER`
here-doc text are masked (scripts/lpc_fix_void_return.code_mask(b, heredoc=True)), so what is left is a quote the GBK conversion
lost (`"skill_name" : "大悲式,`: the closing quote went with a lone lead byte), a private-use character standing in for one
(`符号<U+E4D4>NOR);`), full-width punctuation typed in code (`set("long" ，@LONG`), a line of prose that lost its quotes, or a
file that is not code at all (ASCII-art maps, encrypted job files, binary dumps named .lpc).  Prints
`HB<TAB>slug<TAB>path<TAB>line<TAB>byte column<TAB>text` for the first such byte of each file (wizard, backup, data and doc dirs,
gitlink libs and longyunmeng_binary skipped); `--summary` adds the files per kind and the paths shared by most libs.
The 2026-10-18 corpus: 1,174 files in 160 libs, 457 distinct paths; the poem (32 libs) and niepan (23) families were repaired,
most of the rest is damage every copy of the original archive carries, or not code."""
import collections
import os
import re
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from lpc_fix_void_return import code_mask  # noqa: E402

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SKIP = re.compile(r"/(u|w|wiz|wizard|wizards|open|players|backup|backups|old|bak|log|data|doc|docs|example|examples)/|[-_.](bak|old)/|\.(bak|BAK|old|orig)\.lpc$")
FW = set("，；（）：！？。、　「」『』“”‘’")


def kind(line, col):
    ch = line[col:].decode("utf-8", "ignore")[:1]
    o = ord(ch) if ch else 0
    if 0xE000 <= o <= 0xF8FF:
        return "private-use"
    if o == 0xFFFD:
        return "replacement"
    if ch in FW:
        return "full-width " + ch
    if 0x4E00 <= o <= 0x9FFF:
        return "CJK"
    return "other"


def main():
    args = sys.argv[1:]
    summary = "--summary" in args
    slugs = {a for a in args if not a.startswith("--")}
    files = subprocess.run(["git", "ls-files", "-z", "--", "libs"], cwd=REPO, capture_output=True).stdout.split(b"\0")
    kinds, paths, libs = collections.Counter(), collections.Counter(), set()
    n = 0
    for f in files:
        try:
            p = f.decode()
        except UnicodeDecodeError:
            continue
        if not p.endswith((".lpc", ".h")) or "libs/longyunmeng_binary/" in p:
            continue
        parts = p.split("/work/", 1)
        if len(parts) < 2:
            continue
        slug = p.split("/")[1]
        rel = "/" + parts[1]
        if (slugs and slug not in slugs) or SKIP.search(rel):
            continue
        try:
            b = open(os.path.join(REPO, p), "rb").read()
        except OSError:
            continue
        if not re.search(rb"[\x80-\xff]", b):
            continue
        m = code_mask(b, heredoc=True)
        hit = next((i for i, c in enumerate(b) if c >= 0x80 and m[i]), None)
        if hit is None:
            continue
        ln = b.count(b"\n", 0, hit) + 1
        start = b.rfind(b"\n", 0, hit) + 1
        end = b.find(b"\n", hit)
        line = b[start:len(b) if end < 0 else end].rstrip(b"\r")
        col = hit - start
        n += 1
        libs.add(slug)
        kinds[kind(line, col)] += 1
        paths[rel] += 1
        print(f"HB\t{slug}\t{rel}\t{ln}\t{col}\t{line.decode('utf-8', 'replace').strip()[:100]}", flush=True)
    print(f"{n} file(s) in {len(libs)} lib(s)", file=sys.stderr)
    if summary:
        print("kinds:", dict(kinds.most_common()), file=sys.stderr)
        print("most shared paths:", ", ".join(f"{r} x{c}" for r, c in paths.most_common(8)), file=sys.stderr)


if __name__ == "__main__":
    main()
