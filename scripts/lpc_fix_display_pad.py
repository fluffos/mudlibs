#!/usr/bin/env python3
"""scripts/lpc_fix_display_pad.py [--apply] [--list] [--kinds=edemote,scorebar] SLUG...|--all

GBK-era display pads that treated `strlen` / string ranges as bytes (KB 06 §7.365).
This driver counts characters, so the `* 2` that converted a cell count into a
byte index doubles the slice and a half-full score bar prints full.

  edemote   `repeat_string("─", 13 - (strlen(emotion) / 2))` → drop `/ 2`
            (wizard emote detail header).

  scorebar  `bar_string[0..(val * N / max) * 2 - 1]` and the matching
            `blank_string` / `bmin_string` slices on fullwidth / CJK pad
            strings (■□　●○⊙〓—…): drop each `* 2`.
            `jings = (eff * 12 / max) * 2` + `blank_string3[0..(23 - a)]`
            (23 = 12*2-1) → drop `* 2` and rewrite 23 → 11.
            `n = strlen(full_string) / 2` with slices on full_string / blank_string
            → drop `/ 2` and the `* 2` on those slices.
            ASCII-space `none_string` / `empty_string` keep `* 2` (two spaces
            per display cell).

Binary mode, the file's own line endings. Dry run unless `--apply`. Idempotent
(a second run finds no `* 2` left on CJK pads)."""
from __future__ import annotations

import os
import re
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SKIP = re.compile(
    # `/open/` is playable world in Taiwanese / dreamofseven-style libs (not a wizard home).
    # wizard homes at the lib root only — not cmds/std/wiz/
    r"^/(u|w|wiz|wizard|wizards)/|"
    r"/(players|backup|backups|bak|old|test|tests|"
    r"tmp|data|log|realms|doc|docs|example|examples|orphaned-dir)/|[-_.](bak|old)|"
    r"class_bak|orphaned-dir|/海洋2002/"
)
KINDS = ("edemote", "scorebar")

# Wide / CJK pad characters that were two bytes in GBK (one character here).
WIDE = re.compile(
    r"[\u4e00-\u9fff\u3000-\u303f\uff00-\uffef"
    r"\u2010-\u2027\u2500-\u257f\u25a0-\u25ff\u3000"
    r"■□▬▪●◎⊙※〓━─—–‒┄┅═]"
)

EDEMOTE = re.compile(
    r"13\s*-\s*\(\s*strlen\s*\(\s*(?P<v>emotion)\s*\)\s*/\s*2\s*\)"
)

# tianxia graph: s = (val * n / max) * 2 - 1  (n already a character count)
GRAPH_IDX = re.compile(
    r"\b(?P<lhs>[sl])\s*=\s*"
    r"\(\s*(?P<body>(?:val|eff)\s*\*\s*n\s*/\s*max)\s*\)\s*\*\s*2\s*-\s*1\s*;"
)

STRDEF = re.compile(
    r"(?:^|\n)\s*(?:nosave\s+|private\s+|protected\s+|static\s+)*string\s+"
    r"(?P<v>bar_string\w*|blank_string\w*|bmin_string\w*|none_string\w*|empty_string\w*|full_string\w*)"
    r"\s*=\s*\"(?P<lit>[^\"]*)\"",
)

# jings / qis byte-scale assigns used with blank_string3
JQ = re.compile(
    r"\b(?P<lhs>jings|qis)\s*=\s*"
    r"\(\s*(?P<body>my\s*\[\s*\"eff_(?:jing|qi)\"\s*\]\s*\*\s*\d+\s*/\s*"
    r"my\s*\[\s*\"max_(?:jing|qi)\"\s*\]\s*)\)\s*\*\s*2\s*;"
)
# blank_string3[0..(23 - a)] where 23 = 2*12 - 1
BS3 = re.compile(
    r"(?P<v>blank_string3)\s*\[\s*0\s*\.\.\s*\(\s*(?P<n>23)\s*-\s*(?P<a>\w+)\s*\)\s*\]"
)

FULL_LEN = re.compile(r"strlen\s*\(\s*full_string\s*\)\s*/\s*2")

# * 2 inside a range, optionally followed by - 1
STAR2 = re.compile(r"(?P<pre>\)|\])\s*\*\s*2(?P<tail>\s*-\s*1)?")
# more general: (expr) * 2 with expr ending at )
STAR2_PAREN = re.compile(r"\)\s*\*\s*2(?P<tail>\s*-\s*1)?")


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
        if rel.endswith((".lpc", ".h")) and not SKIP.search(rel) and not re.search(
            "[\udc80-\udcff]", rel
        ):
            yield rel


def _is_wide_lit(lit: str) -> bool:
    if not lit:
        return False
    # ASCII spaces / tabs only → display-width pad, keep * 2
    if set(lit) <= set(" \t"):
        return False
    # any wide char → GBK byte * 2
    if WIDE.search(lit):
        return True
    # other non-ASCII (e.g. PUA bars) → treat as wide
    return any(ord(c) > 127 for c in lit)


def _defs(t: str) -> dict[str, bool]:
    """varname -> True if *2 on its indices was a GBK byte conversion."""
    out = {}
    for m in STRDEF.finditer(t):
        out[m.group("v")] = _is_wide_lit(m.group("lit"))
    return out


def edits_edemote(t: str):
    out = []
    for m in EDEMOTE.finditer(t):
        out.append((m.start(), m.end(), f"13 - strlen({m.group('v')})", m.group(0)))
    return out


def _rewrite_range_body(body: str) -> str | None:
    """Drop `* 2` (and keep `- 1` when present) inside a [...] body."""
    if not re.search(r"\)\s*\*\s*2", body):
        return None
    nb, n = STAR2_PAREN.subn(lambda m: ")" + (m.group("tail") or ""), body)
    if n == 0 or nb == body:
        return None
    return nb


def edits_scorebar(t: str):
    defs = _defs(t)
    # Also treat full_string / blank_string when assigned with ■ even if names vary
    if "full_string" in t and "strlen(full_string)" in t:
        defs.setdefault("full_string", True)
        defs.setdefault("blank_string", True)
    out = []

    # strlen(full_string) / 2
    for m in FULL_LEN.finditer(t):
        out.append((m.start(), m.end(), "strlen(full_string)", m.group(0)))

    # s/l = (val|eff * n / max) * 2 - 1  next to full_string graph
    if FULL_LEN.search(t) or ("full_string" in t and "blank_string" in t):
        for m in GRAPH_IDX.finditer(t):
            out.append(
                (
                    m.start(),
                    m.end(),
                    f"{m.group('lhs')} = ({m.group('body')}) - 1;",
                    m.group(0),
                )
            )

    # jings / qis * 2 assigns
    for m in JQ.finditer(t):
        out.append(
            (
                m.start(),
                m.end(),
                f"{m.group('lhs')} = ({m.group('body')});",
                m.group(0),
            )
        )

    # blank_string3[0..(23 - a)] → 11 when jings/qis lost * 2
    if JQ.search(t) or "jings =" in t or "qis =" in t:
        for m in BS3.finditer(t):
            out.append(
                (
                    m.start(),
                    m.end(),
                    f"{m.group('v')}[0..(11 - {m.group('a')})]",
                    m.group(0),
                )
            )

    # VAR[ body with * 2 ]
    for m in re.finditer(
        r"(?P<v>bar_string\w*|blank_string\w*|bmin_string\w*|none_string\w*|empty_string\w*|full_string\w*)"
        r"\s*\[\s*(?P<body>[^\]]+)\]",
        t,
    ):
        v = m.group("v")
        # Only rewrite when the variable is known wide, or undefined but looks like
        # a bar (bar_/blank_/bmin_/full_) — never none_/empty_ without a wide def.
        wide = defs.get(v)
        if wide is False:
            continue
        if wide is None:
            if v.startswith("none_") or v.startswith("empty_"):
                continue
            # bar_/blank_/bmin_/full_ without a local def: only if file has ■ somewhere
            if not WIDE.search(t):
                continue
        body = m.group("body")
        nb = _rewrite_range_body(body)
        if nb is None:
            continue
        # preserve spacing around brackets from original
        full = m.group(0)
        # rebuild with same var + brackets style
        open_b = full.find("[")
        new = full[: open_b + 1] + nb + "]"
        if new != full:
            out.append((m.start(), m.end(), new, full))

    return _dedupe(out)


def _dedupe(edits):
    edits = sorted(edits, key=lambda x: (x[0], x[1]))
    res, last = [], -1
    for a, b, new, old in edits:
        if a < last:
            continue
        if new == old:
            continue
        res.append((a, b, new, old))
        last = b
    return res


def apply_edits(t, ed):
    out, pos = [], 0
    for a, b, new, _old in ed:
        out.append(t[pos:a])
        out.append(new)
        pos = b
    out.append(t[pos:])
    return "".join(out)


def main():
    argv = sys.argv[1:]
    apply, listing = "--apply" in argv, "--list" in argv
    kinds = set(KINDS)
    for a in argv:
        if a.startswith("--kinds="):
            kinds = set(a.split("=", 1)[1].split(","))
            bad = kinds - set(KINDS)
            if bad:
                sys.exit(f"unknown kinds: {bad}")
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
            if b"* 2" not in raw and b"*2" not in raw and b"/ 2" not in raw and b"/2" not in raw:
                continue
            if not any(
                s in raw
                for s in (
                    b"bar_string",
                    b"blank_string",
                    b"bmin_string",
                    b"full_string",
                    b"emotion",
                    b"edemote",
                    "■".encode(),
                    "□".encode(),
                )
            ):
                continue
            t = raw.decode("utf-8", "surrogateescape")
            ed = []
            if "edemote" in kinds:
                ed += edits_edemote(t)
            if "scorebar" in kinds:
                ed += edits_scorebar(t)
            ed = _dedupe(ed)
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
        total += nedit
        print(
            f"{slug}: {nedit} edit(s) in {nfile} file(s)" + ("" if apply else " (plan only)"),
            file=sys.stderr,
        )
    print(f"{total} edit(s)", file=sys.stderr)


if __name__ == "__main__":
    main()
