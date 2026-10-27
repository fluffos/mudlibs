#!/usr/bin/env python3
"""scripts/lpc_fix_tail_slice.py [--apply] [--list] SLUG...|--all

From-end ranges left over from the GBK era (KB 06 §7.360 only halved numeric
`[a..b]`). On the archives a Chinese character is two bytes, so `name[<2..<1]`
is the last character and `name[<4..<1]` the last two; this driver counts
characters.

Only clear Chinese contexts are rewritten (ASCII zero-pads, ctime years,
plural `-es`/`-sh`, `.lpc` extensions are left alone):

  name[<2..<1]  ->  name[<1..<1]
    when compared to a non-ASCII literal, or `member_array`/`member` of a
    nearby list of single Chinese characters, or the RHS of `+` / `+=` next
    to Chinese text (`"明" + name[<2..<1]`, `name += oldname[<2..<1]`).

  name[<4..<1]  ->  name[<2..<1]
    only in those same Chinese name-building / can_name contexts (never when
    compared to `.lpc`).

Also the Shujian `gcreate` length gate (help text is the oracle:
`二至六个汉字`, `3到8个英文字母`):

  (strlen(gname2)%2)==1 || strlen(gname2)<4 || strlen(gname2)>12 || strlen(gid)<4 || strlen(gid)>8
    ->  strlen(gname2)<2 || strlen(gname2)>6 || strlen(gid)<3 || strlen(gid)>8

Binary mode. Dry run unless `--apply`. **Not chain-idempotent** (`<4`→`<2>`
would then match `<2>`): rewritten files are listed in
`scripts/tail_slice_converted.txt` and skipped later."""
from __future__ import annotations

import os
import re
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
LEDGER = os.path.join(REPO, "scripts", "tail_slice_converted.txt")
SKIP = re.compile(
    # `/open/` is playable world (Taiwanese / dreamofseven-style libs), not a wizard home
    r"/(u|w|wiz|wizard|wizards|players|backup|backups|bak|old|test|tests|"
    r"tmp|data|log|realms|doc|docs|example|examples|orphaned-dir)/|[-_.](bak|old)|"
    r"class_bak|orphaned-dir|/海洋2002/"
)

SLICE = re.compile(r"\[\s*<\s*(?P<n>[24])\s*\.\.\s*<\s*1\s*\]")
GCREATE = re.compile(
    r"\(\s*strlen\s*\(\s*(?P<g>gname2|gname)\s*\)\s*%\s*2\s*\)\s*==\s*1\s*"
    r"\|\|\s*strlen\s*\(\s*(?P=g)\s*\)\s*<\s*4\s*"
    r"\|\|\s*strlen\s*\(\s*(?P=g)\s*\)\s*>\s*12\s*"
    r"\|\|\s*strlen\s*\(\s*(?P<id>gid|id)\s*\)\s*<\s*4\s*"
    r"\|\|\s*strlen\s*\(\s*(?P=id)\s*\)\s*>\s*8"
)
# CJK ideographs + CJK punctuation (。、「」…) — not ASCII
CN = re.compile(r"[\u4e00-\u9fff\u3000-\u303f\uff00-\uffef]")
STR_LIT = re.compile(r'"((?:[^"\\]|\\.)*)"')


def comment_free(t):
    out, i, n = [], 0, len(t)
    while i < n:
        c = t[i]
        if c == '"':
            j = i + 1
            while j < n and t[j] != '"' and t[j] != "\n":
                j += 2 if t[j] == "\\" else 1
            out.append(t[i : j + 1])
            i = j + 1
        elif c == "/" and t[i + 1 : i + 2] == "/":
            j = t.find("\n", i)
            j = n if j < 0 else j
            out.append(" " * (j - i))
            i = j
        elif c == "/" and t[i + 1 : i + 2] == "*":
            j = t.find("*/", i + 2)
            j = n if j < 0 else j + 2
            out.append("".join("\n" if ch == "\n" else " " for ch in t[i:j]))
            i = j
        else:
            out.append(c)
            i += 1
    return "".join(out)


def has_cn_literal(s):
    return bool(CN.search(s))


def chinese_context(c, start, end, n):
    """True if this from-end slice is a GBK-era one-or-two Chinese character cut."""
    after = c[end : end + 80]
    before = c[max(0, start - 100) : start]
    window = c[max(0, start - 200) : min(len(c), end + 200)]

    # never touch extension / save-suffix / ctime / zero-pad / explode line tails
    if re.search(r"FILE_EXTENSION|SAVE_EXTENSION|LPC_EXTENSION|__SAVE_EXTENSION__", window):
        return False
    if re.search(r"\bctime\b", before) or re.search(r'\("0"\s*\+|"0"\s*\+', before):
        return False
    if "explode" in before and "\\n" in window:
        return False
    # == / != ".lpc" or other ASCII extension
    m = re.match(r'\s*(==|!=)\s*"((?:[^"\\]|\\.)*)"', after)
    if m and all(ord(ch) < 128 for ch in m.group(2)):
        return False
    m = re.search(r'"((?:[^"\\]|\\.)*)"\s*(==|!=)\s*[A-Za-z_]\w*\s*$', before)
    if m and all(ord(ch) < 128 for ch in m.group(1)):
        return False  # "sh" == s[<2..<1], "es" == ...
    # switch (x[<2..<1]) { case "th": / case ".lpc":
    if re.search(r"switch\s*\(", before):
        if re.search(r'case\s*"((?:[^"\\]|\\.)*)"', after):
            return False

    # 1) compared to a Chinese literal: != "。"
    m = re.match(r'\s*(==|!=)\s*"((?:[^"\\]|\\.)*)"', after)
    if m and has_cn_literal(m.group(2)):
        return True
    m = re.search(r'"((?:[^"\\]|\\.)*)"\s*(==|!=)\s*[A-Za-z_]\w*\s*$', before)
    if m and has_cn_literal(m.group(1)):
        return True

    # 2) member_array(x[<2..<1], end_name) where end_name / can_name holds Chinese
    if re.search(r"member_array\s*\(|\bmember\s*\(", before) or "member_array" in after[:40]:
        # look for a nearby ({ "帮", "会" ...}) or can_name keys
        if has_cn_literal(window) and ("can_name" in window or "end_name" in window or re.search(r'\(\{\s*"' + CN.pattern, window)):
            return True
        # member_array(name[<2..<1], keys(can_name[type]))
        if "can_name" in window or "keys(" in window:
            return True

    # 3) Chinese name build: "明" + name[<2..<1] / new_name = ... + name[<4..<1]
    if re.search(
        r'"[^"]*(?:[\u4e00-\u9fff\u3000-\u303f\uff00-\uffef])[^"]*"\s*\+\s*[A-Za-z_]\w*\s*$',
        before,
    ):
        return True
    if re.search(r"(new_name|name2?)\s*\+=\s*[A-Za-z_]\w*\s*$", before) and (
        "oldname" in before + after or has_cn_literal(window)
    ):
        return True
    # new_name = prename[...] + name[<4..<1]
    if re.search(r"(new_name|name)\s*=\s*.*\+\s*[A-Za-z_]\w*\s*$", before) and has_cn_literal(
        window
    ):
        return True

    # 4) can_name[type][name[<4..<1]] index
    if "can_name" in window and n in (2, 4):
        return True

    # 5) gcreate last-char vs valid_group_name (Chinese list)
    if "valid_group_name" in window or "invalid_group_name" in window:
        return True

    return False


def edits(t):
    c = comment_free(t)
    out = []
    for m in SLICE.finditer(c):
        n = int(m.group("n"))
        if not chinese_context(c, m.start(), m.end(), n):
            continue
        if n == 2:
            out.append((m.start(), m.end(), "[<1..<1]", t[m.start() : m.end()]))
        else:
            out.append((m.start(), m.end(), "[<2..<1]", t[m.start() : m.end()]))
    for m in GCREATE.finditer(c):
        g, i = m.group("g"), m.group("id")
        new = f"strlen({g}) < 2 || strlen({g}) > 6 || strlen({i}) < 3 || strlen({i}) > 8"
        out.append((m.start(), m.end(), new, t[m.start() : m.end()]))
    out.sort()
    res, last = [], -1
    for a, b, new, old in out:
        if a < last or new == old:
            continue
        res.append((a, b, new, old))
        last = b
    return res


def apply_edits(t, ed):
    out, pos = [], 0
    for a, b, new, _ in ed:
        out.append(t[pos:a])
        out.append(new)
        pos = b
    out.append(t[pos:])
    return "".join(out)


def tracked(slug):
    out = subprocess.run(
        ["git", "ls-files", "-z", "--", f"libs/{slug}/work"],
        cwd=REPO,
        capture_output=True,
    ).stdout
    pre = f"libs/{slug}/work"
    for p in out.split(b"\0"):
        if not p:
            continue
        s = p.decode("utf-8", "surrogateescape")
        rel = s[len(pre) :]
        if rel.endswith((".lpc", ".h")) and not SKIP.search(rel) and not re.search("[\udc80-\udcff]", rel):
            yield rel


def load_ledger():
    if not os.path.isfile(LEDGER):
        return set()
    return {ln.strip() for ln in open(LEDGER, encoding="utf-8") if ln.strip() and not ln.startswith("#")}


def append_ledger(paths):
    if not paths:
        return
    with open(LEDGER, "a", encoding="utf-8") as f:
        for p in sorted(paths):
            f.write(p + "\n")


def main():
    argv = sys.argv[1:]
    apply, listing = "--apply" in argv, "--list" in argv
    names = [a for a in argv if not a.startswith("--")]
    if "--all" in argv:
        names = sorted(
            p
            for p in os.listdir(os.path.join(REPO, "libs"))
            if os.path.isdir(os.path.join(REPO, "libs", p, "work"))
        )
    if not names:
        sys.exit(__doc__)
    done = load_ledger()
    total = 0
    newly = []
    for slug in names:
        root = os.path.join(REPO, "libs", slug, "work")
        nfile = nedit = 0
        for rel in tracked(slug):
            key = f"libs/{slug}/work{rel}"
            if key in done:
                continue
            p = root + rel
            try:
                raw = open(p, "rb").read()
            except OSError:
                continue
            if b"[<" not in raw and b"gname2" not in raw:
                continue
            t = raw.decode("utf-8", "surrogateescape")
            ed = edits(t)
            if not ed:
                continue
            nfile += 1
            nedit += len(ed)
            if listing:
                for a, b, new, old in ed:
                    ln = t.count("\n", 0, a) + 1
                    print(f"{slug} {rel}:{ln}: {old!r} -> {new!r}")
            if apply:
                nt = apply_edits(t, ed)
                if nt != t:
                    open(p, "wb").write(nt.encode("utf-8", "surrogateescape"))
                    newly.append(key)
        total += nedit
        print(
            f"{slug}: {nedit} edit(s) in {nfile} file(s)" + ("" if apply else " (plan only)"),
            file=sys.stderr,
        )
    if apply:
        append_ledger(newly)
    print(f"{total} edit(s)", file=sys.stderr)


if __name__ == "__main__":
    main()
