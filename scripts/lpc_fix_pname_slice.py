#!/usr/bin/env python3
"""scripts/lpc_fix_pname_slice.py [--apply] [--list] SLUG...|--all

NPC Chinese name generators (KB 06 §7.373): under GBK,
`pname = pname[(random(sizeof(pname)) & 0xFFFE)..<1]; pname = pname[0..1];`
picked one character (two bytes). Character indices make `[0..1]` two
characters and `& 0xFFFE` a pointless even-char gate.

Rewrite to:
  pname = pname[random(sizeof(pname))..<1];
  pname = pname[0..0];
(same for pname2). Binary mode. Dry run unless `--apply`."""
from __future__ import annotations

import os
import re
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SKIP = re.compile(  # `/open/` is playable world (Taiwanese / dreamofseven-style libs), not a wizard home
    r"^/(u|w|wiz|wizard|wizards)/|"
    r"/(players|backup|backups|bak|old|test|tests|"
    r"tmp|data|log|realms|doc|docs|example|examples|orphaned-dir)/|"
    r"[-_.](bak|old)|class_bak|orphaned-dir|/海洋2002/"
)

# pname/pname2/sec_name (NPC names) and str/str1 (ultra robot / x_pointd captcha)
VAR = r"(?:pname2?|sec_name|str1?)"
# Pick: (random(sizeof(v)) & 0xFFFE) followed by ..<1 or .. (to end)
PICK = (
    r"\[\s*\(\s*random\s*\(\s*sizeof\s*\(\s*(?P=var)\s*\)\s*\)\s*"
    r"&\s*0xFFFE\s*\)\s*\.\.(?:\s*<\s*1)?\s*\]"
)

# Two-line: masked pick + [0..1] or already [0..0]
PAIR = re.compile(
    rf"(?P<indent>[ \t]*)(?P<var>{VAR})\s*=\s*(?P=var)\s*{PICK}\s*;[ \t]*\r?\n"
    rf"(?P=indent)(?P=var)\s*=\s*(?P=var)\s*\[\s*0\s*\.\.\s*[01]\s*\]\s*;"
)

# Already lost the mask but still [0..1]
TAIL = re.compile(
    rf"(?P<indent>[ \t]*)(?P<var>{VAR})\s*=\s*(?P=var)\s*"
    rf"\[\s*random\s*\(\s*sizeof\s*\(\s*(?P=var)\s*\)\s*\)\s*\.\.(?:\s*<\s*1)?\s*\]\s*;[ \t]*\r?\n"
    rf"(?P=indent)(?P=var)\s*=\s*(?P=var)\s*\[\s*0\s*\.\.\s*1\s*\]\s*;"
)

# Lone masked pick without a following [0..N] on next line (sec_name often)
MASK_ONLY = re.compile(
    rf"(?P<indent>[ \t]*)(?P<var>{VAR})\s*=\s*(?P=var)\s*{PICK}\s*;"
)

# Lone [0..1] after a masked/random pick
LONE = re.compile(
    rf"(?P<indent>[ \t]*)(?P<var>{VAR})\s*=\s*(?P=var)\s*\[\s*0\s*\.\.\s*1\s*\]\s*;"
)


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
        if rel.endswith((".lpc", ".h")) and not SKIP.search(rel):
            yield rel


def edits_for(t: str):
    out = []
    for rx, kind in ((PAIR, "pair"), (TAIL, "tail")):
        for m in rx.finditer(t):
            var = m.group("var")
            ind = m.group("indent")
            nl = "\r\n" if "\r\n" in m.group(0) else "\n"
            new = (
                f"{ind}{var} = {var}[random(sizeof({var}))..<1];{nl}"
                f"{ind}{var} = {var}[0..0];"
            )
            out.append((m.start(), m.end(), new, kind))
    covered = set()
    for a, b, _, _ in out:
        covered.update(range(a, b))
    for m in MASK_ONLY.finditer(t):
        if any(i in covered for i in range(m.start(), m.end())):
            continue
        var = m.group("var")
        ind = m.group("indent")
        # If next non-empty line is already var = var[0..0], only strip the mask
        rest = t[m.end() :]
        m2 = re.match(
            rf"\s*{re.escape(var)}\s*=\s*{re.escape(var)}\s*\[\s*0\s*\.\.\s*[01]\s*\]\s*;",
            rest,
        )
        if m2:
            new = f"{ind}{var} = {var}[random(sizeof({var}))..<1];"
            out.append((m.start(), m.end(), new, "mask"))
        else:
            # sec_name style: pick then later [0..1] on another statement — strip mask only
            new = f"{ind}{var} = {var}[random(sizeof({var}))..<1];"
            out.append((m.start(), m.end(), new, "mask"))
        covered.update(range(m.start(), m.end()))
    for m in LONE.finditer(t):
        if any(i in covered for i in range(m.start(), m.end())):
            continue
        var = m.group("var")
        before = t[max(0, m.start() - 400) : m.start()]
        if not re.search(
            rf"{re.escape(var)}\s*=\s*{re.escape(var)}\s*\[",
            before,
        ):
            continue
        new = f"{m.group('indent')}{var} = {var}[0..0];"
        out.append((m.start(), m.end(), new, "lone"))
    out = sorted(out, key=lambda x: (x[0], x[1]))
    res, last = [], -1
    for a, b, new, kind in out:
        if a < last:
            continue
        res.append((a, b, new, kind))
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
    total = 0
    for slug in names:
        root = os.path.join(REPO, "libs", slug, "work")
        nfile = nedit = 0
        for rel in tracked(slug):
            p = root + rel
            try:
                raw = open(p, "rb").read()
            except OSError:
                continue
            if b"0xFFFE" not in raw and b"[0..1]" not in raw:
                continue
            t = raw.decode("utf-8", "surrogateescape")
            if "0xFFFE" not in t and "[0..1]" not in t:
                continue
            if not any(v in t for v in ("pname", "pname2", "sec_name", "str = str[", "str1 = str1[")):
                continue
            ed = edits_for(t)
            if not ed:
                continue
            nfile += 1
            nedit += len(ed)
            if listing:
                for a, b, new, kind in ed:
                    ln = t.count("\n", 0, a) + 1
                    print(f"{slug} {rel}:{ln}: [{kind}] -> {new!r}")
            if apply:
                nt = apply_edits(t, ed)
                if nt != t:
                    open(p, "wb").write(nt.encode("utf-8", "surrogateescape"))
        total += nedit
        print(
            f"{slug}: {nedit} edit(s) in {nfile} file(s)" + ("" if apply else " (plan only)"),
            file=sys.stderr,
        )
    print(f"{total} edit(s)", file=sys.stderr)


if __name__ == "__main__":
    main()
