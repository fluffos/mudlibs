#!/usr/bin/env python3
"""scripts/lpc_fix_byte_char.py [--apply] [--list] [--kinds=parity,clubpoem,channeld,strlen2] SLUG...|--all

Leftovers of the GBK-era character arithmetic after KB 06 7.360 / 7.362 (this driver's
strlen() and ranges count characters). Four shapes:

  parity     `while (i--) if (i % 2 == 0 && !is_chinese(name[i..<0]))`: the parity
             skipped every other character (a Latin letter at an odd index of "张a"
             was accepted); `name[i..<0]` / `name[i..<1]` for a single-character test
             becomes `name[i..i]`. Also the bare `is_chinese(x[i..<0])` form without
             parity (same range).

  clubpoem   `mixup()` of clubpoem / taibailou: `len = strlen(str)/2`, then `j=j+j`
             and `str[k..k+1]` swapped two-byte characters. Rewritten for character
             indices; the `strlen(first) >= 14` (seven characters) gate is halved.

  channeld   nitan-family `switch (strlen(fname)) case 4/6/8/10` league header and
             `strlen(family) == 4/6` with `family[0..1]` slices: byte lengths of
             2/3/4/5-character names. Oracle: aoxiangtianji's character cases.

  strlen2    `strlen(x) / 2` used as a character count next to a two-byte slice index
             (`random(strlen(arg)/2)*2` + `arg[i..(i+1)]`, `while (strlen(name)/2 < N)`).

Binary mode, the file's own line endings. Dry run unless `--apply`. Idempotent for
parity / channeld / strlen2; clubpoem matches the byte body only once."""
from __future__ import annotations

import os
import re
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SKIP = re.compile(
    # `/open/` is playable world in Taiwanese / dreamofseven-style libs
    r"/(u|w|wiz|wizard|wizards|players|backup|backups|bak|old|test|tests|"
    r"tmp|data|log|realms|doc|docs|example|examples|orphaned-dir)/|[-_.](bak|old)|"
    r"class_bak|orphaned-dir|/海洋2002/"
)
KINDS = ("parity", "clubpoem", "channeld", "strlen2")

# parity: optional "i % 2 == 0 &&" before is_chinese(var[range])
PARITY_ISCN = re.compile(
    r"(?:(?P<parity>(?P<idx>[A-Za-z_]\w*)\s*%\s*2\s*(?:==\s*0|!=\s*1)?\s*&&\s*)"
    r"|)"
    r"(?P<bang>!?)\s*is_chinese\s*\(\s*(?P<var>[A-Za-z_]\w*)\s*"
    r"\[\s*(?P<rng>[^\]]+?)\s*\]\s*\)"
)
# ranges that meant "one GBK character at i" and are wrong or ambiguous on characters
BAD_RANGE = re.compile(
    r"^(?P<i>[A-Za-z_]\w*)\s*\.\.\s*(?:<\s*0|<\s*1|(?P=i)\s*\+\s*1|\(\s*(?P=i)\s*\+\s*1\s*\))$"
)

# clubpoem mixup body (whitespace-flexible)
MIXUP_OLD = re.compile(
    r"(string\s+mixup\s*\(\s*string\s+(?P<arg>\w+)\s*\)\s*\{)"
    r"(?P<body>"
    r"\s*int\s+len\s*=\s*strlen\s*\(\s*(?P=arg)\s*\)\s*/\s*2\s*,\s*i\s*,\s*j\s*,\s*k\s*,\s*l\s*;"
    r"\s*string\s+ans\s*;"
    r"\s*for\s*\(\s*i\s*=\s*1\s*;\s*i\s*<=\s*random\s*\(\s*2\s*\)\s*\+\s*1\s*;\s*i\s*\+\+\s*\)\s*\{"
    r"\s*j\s*=\s*random\s*\(\s*len\s*\)\s*;"
    r"\s*k\s*=\s*random\s*\(\s*len\s*\)\s*;"
    r"\s*if\s*\(\s*j\s*==\s*k\s*\)\s*\{"
    r"\s*k\s*\+\+\s*;"
    r"\s*if\s*\(\s*k\s*>=\s*len\s*\)\s*k\s*=\s*0\s*;"
    r"\s*\}"
    r"\s*if\s*\(\s*j\s*>\s*k\s*\)\s*\{"
    r"\s*l\s*=\s*k\s*;\s*k\s*=\s*j\s*;\s*j\s*=\s*l\s*;"
    r"\s*\}"  # so j<k
    r"[^\n]*\n?"  # optional comment
    r"\s*j\s*=\s*j\s*\+\s*j\s*;\s*k\s*=\s*k\s*\+\s*k\s*;"
    r"\s*if\s*\(\s*j\s*>\s*0\s*\)\s*ans\s*=\s*(?P=arg)\s*\[\s*0\s*\.\.\s*j\s*-\s*1\s*\]\s*;"
    r"\s*else\s*ans\s*=\s*\"\"\s*;"
    r"\s*ans\s*\+=\s*(?P=arg)\s*\[\s*k\s*\.\.\s*k\s*\+\s*1\s*\]\s*\+\s*"
    r"(?P=arg)\s*\[\s*j\s*\+\s*2\s*\.\.\s*k\s*-\s*1\s*\]\s*\+\s*"
    r"(?P=arg)\s*\[\s*j\s*\.\.\s*j\s*\+\s*1\s*\]\s*;"
    r"\s*if\s*\(\s*k\s*<\s*len\s*\+\s*len\s*-\s*2\s*\)\s*ans\s*\+=\s*"
    r"(?P=arg)\s*\[\s*k\s*\+\s*2\s*\.\.\s*len\s*\+\s*len\s*-\s*1\s*\]\s*;"
    r"\s*(?P=arg)\s*=\s*ans\s*;"
    r"\s*\}"
    r"\s*return\s+(?P=arg)\s*;"
    r")",
    re.S,
)
MIXUP_NEW_BODY = """
  int len = strlen({a}), i, j, k, l;
  string ans;

  for (i = 1; i <= random(2) + 1; i++) {{
    j = random(len);
    k = random(len);
    if (j == k) {{
      k++;
      if (k >= len) k = 0;
    }}
    if (j > k) {{
      l = k; k = j; j = l;
    }}
    if (j > 0) ans = {a}[0..j - 1];
    else ans = "";
    ans += {a}[k..k] + {a}[j + 1..k - 1] + {a}[j..j];
    if (k < len - 1) ans += {a}[k + 1..len - 1];
    {a} = ans;
  }}
  return {a};
"""
GATE14 = re.compile(r"strlen\s*\(\s*(first|second)\s*\)\s*>=\s*14")

# channeld league switch
LEAGUE = re.compile(
    r"switch\s*\(\s*strlen\s*\(\s*(?P<v>fname|league_name|\w+)\s*\)\s*\)\s*\{"
    r"(?P<body>[^}]{0,1200}?)\}",
    re.S,
)
LEAGUE_OLD = re.compile(
    r"case\s+4\s*:.*?case\s+6\s*:.*?case\s+8\s*:.*?case\s+10\s*:",
    re.S,
)
FAMILY4 = re.compile(
    r"if\s*\(\s*strlen\s*\(\s*(?P<v>family)\s*\)\s*==\s*4\s*\)\s*\{"
    r"(?P<body>[^}]{0,200}?)\}",
    re.S,
)
FAMILY6 = re.compile(
    r"if\s*\(\s*strlen\s*\(\s*(?P<v>family)\s*\)\s*==\s*6\s*\)\s*\{"
    r"(?P<body>[^}]{0,200}?)\}",
    re.S,
)

# strlen2: random(strlen(X)/2)*2 with a following two-byte slice on X
RAND2 = re.compile(
    r"(?P<a>random\s*\(\s*strlen\s*\(\s*(?P<v>[A-Za-z_]\w*(?:\[[^\]]*\])?)\s*\)\s*/\s*2\s*\))"
    r"(?P<b>\s*\*\s*2)"
)
WHILE2 = re.compile(r"while\s*\(\s*strlen\s*\(\s*(?P<v>[A-Za-z_]\w*)\s*\)\s*/\s*2\s*(?P<op><|<=|>|>=)\s*")
LEN_ASSIGN2 = re.compile(
    r"\b(?P<lhs>len)\s*=\s*strlen\s*\(\s*(?P<v>[A-Za-z_]\w*)\s*\)\s*/\s*2\b"
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
        if rel.endswith((".lpc", ".h")) and not SKIP.search(rel) and not re.search("[\udc80-\udcff]", rel):
            yield rel


def edits_parity(t):
    out = []
    for m in PARITY_ISCN.finditer(t):
        rng = m.group("rng").strip()
        rm = BAD_RANGE.match(rng)
        if not rm and not m.group("parity"):
            continue
        if m.group("parity") and m.group("idx") != rm.group("i") if rm else (m.group("idx") != m.group("var") if m.group("parity") else False):
            # parity index should match the slice index variable
            if m.group("parity"):
                idx = m.group("idx")
                if not re.match(r"^" + re.escape(idx) + r"(\s*\.\.|\s*$)", rng) and idx not in rng.split("..")[0]:
                    if not BAD_RANGE.match(rng):
                        continue
        pieces = []
        # drop parity
        if m.group("parity"):
            pieces.append((m.start("parity"), m.end("parity"), ""))
        # fix range to i..i
        if rm:
            i = rm.group("i")
            # replace only the range inside the brackets
            abs_rng_start = m.start("rng")
            # keep original spacing minimal: i..i
            pieces.append((abs_rng_start, m.end("rng"), f"{i}..{i}"))
        elif m.group("parity"):
            # parity alone with an already-good range (i..i): still drop parity
            pass
        else:
            continue
        out.extend(pieces)
    return _dedupe(out, t)


def edits_clubpoem(t):
    out = []
    for m in MIXUP_OLD.finditer(t):
        a = m.group("arg")
        old_body = m.group("body")
        nl = "\r\n" if "\r\n" in old_body else "\n"
        # indent = whitespace before the first non-empty line of the old body
        ind = "  "
        for line in old_body.splitlines():
            if line.strip():
                ind = re.match(r"[ \t]*", line).group(0)
                break
        raw_lines = MIXUP_NEW_BODY.format(a=a).strip("\n").split("\n")
        # MIXUP_NEW_BODY is written with 2-space base indent; shift to ind
        rebuilt_lines = []
        for ln in raw_lines:
            if not ln.strip():
                rebuilt_lines.append("")
                continue
            # strip the template's two-space base
            core = ln[2:] if ln.startswith("  ") else ln.lstrip()
            rebuilt_lines.append(ind + core)
        rebuilt = nl + nl.join(rebuilt_lines) + nl
        out.append((m.start("body"), m.end("body"), rebuilt))
    for m in GATE14.finditer(t):
        out.append((m.start(), m.end(), f"strlen({m.group(1)}) >= 7"))
    return _dedupe(out, t)


def _rewrite_league_body(body, v):
    """Rewrite case 4/6/8/10 block to case 2/3/4/5; keep colour / quote style of case 4 line."""
    if not LEAGUE_OLD.search(body):
        return None
    # require the byte slices
    if f"{v}[0..1]" not in body and f"{v}[0..1]" not in body.replace(" ", ""):
        if not re.search(re.escape(v) + r"\s*\[\s*0\s*\.\.\s*1\s*\]", body):
            return None
    # pull templates from each case
    def case_rhs(n):
        m = re.search(rf"case\s+{n}\s*:\s*([^=\n]+)=([^;]+);", body)
        return m.group(1).strip(), m.group(2).strip() if m else (None, None)

    # Build new body from old case-4 / case-6 templates when possible
    # Default plain form matching nitan_san
    plain = {
        2: f'"【 " + {v}[0..0] + "  " + {v}[1..1] + " 】"',
        3: f'"【 " + {v} + " 】"',
        4: f'"【" + {v} + "】"',
        5: f'"【" + {v}[0..3] + "】"',
    }
    # If case 4 used a coloured form, keep colours around the new split
    lhs4, rhs4 = case_rhs(4)
    if rhs4 and "HI" in rhs4:
        # coloured oracle style from aoxiangtianji is lib-specific; keep structure:
        # replace fname[0..1] / [2..3] with [0..0]/[1..1] and lengths
        pass
    new_cases = []
    for n_old, n_new, tmpl in (
        (4, 2, plain[2]),
        (6, 3, plain[3]),
        (8, 4, plain[4]),
        (10, 5, plain[5]),
    ):
        lhs, rhs = case_rhs(n_old)
        if not rhs:
            return None
        # map byte slices in the RHS to character slices
        nr = rhs
        nr = re.sub(rf"{re.escape(v)}\s*\[\s*0\s*\.\.\s*1\s*\]", f"{v}[0..0]", nr)
        nr = re.sub(rf"{re.escape(v)}\s*\[\s*2\s*\.\.\s*3\s*\]", f"{v}[1..1]", nr)
        nr = re.sub(rf"{re.escape(v)}\s*\[\s*4\s*\.\.\s*5\s*\]", f"{v}[2..2]", nr)
        nr = re.sub(rf"{re.escape(v)}\s*\[\s*0\s*\.\.\s*7\s*\]", f"{v}[0..3]", nr)
        # if RHS is just wrapping fname with no slices (cases 6/8), keep as-is
        if n_old == 10 and f"{v}[0..3]" not in nr and v in nr:
            # truncated form required
            if not re.search(rf"{re.escape(v)}\s*\[", nr):
                nr = re.sub(rf"\b{re.escape(v)}\b", f"{v}[0..3]", nr, count=1)
        new_cases.append((n_new, lhs or v, nr))
    # detect indent
    ind_m = re.search(r"\n([ \t]*)case\s+4", body)
    ind = ind_m.group(1) if ind_m else "          "
    parts = ["\n"]
    for n, lhs, rhs in new_cases:
        parts.append(f"{ind}case {n}:\n")
        parts.append(f"{ind}  {lhs} = {rhs};\n")
        parts.append(f"{ind}  break;\n\n")
    parts.append(ind[:-2] if len(ind) >= 2 else ind)
    return "".join(parts)


def edits_channeld(t):
    out = []
    for m in LEAGUE.finditer(t):
        v = m.group("v")
        new_body = _rewrite_league_body(m.group("body"), v)
        if new_body is None:
            continue
        out.append((m.start("body"), m.end("body"), new_body))
    for m in FAMILY4.finditer(t):
        body = m.group("body")
        v = m.group("v")
        if not re.search(rf"{re.escape(v)}\s*\[\s*0\s*\.\.\s*1\s*\]", body):
            continue
        nb = body
        nb = re.sub(rf"{re.escape(v)}\s*\[\s*0\s*\.\.\s*1\s*\]", f"{v}[0..0]", nb)
        nb = re.sub(rf"{re.escape(v)}\s*\[\s*2\s*\.\.\s*3\s*\]", f"{v}[1..1]", nb)
        # replace == 4 in the condition
        out.append((m.start(), m.end(), f"if (strlen({v}) == 2) {{{nb}}}"))
    for m in FAMILY6.finditer(t):
        body = m.group("body")
        v = m.group("v")
        if not re.search(rf"{re.escape(v)}\s*\[\s*0\s*\.\.\s*1\s*\]", body):
            continue
        nb = body
        nb = re.sub(rf"{re.escape(v)}\s*\[\s*0\s*\.\.\s*1\s*\]", f"{v}[0..0]", nb)
        nb = re.sub(rf"{re.escape(v)}\s*\[\s*2\s*\.\.\s*3\s*\]", f"{v}[1..1]", nb)
        nb = re.sub(rf"{re.escape(v)}\s*\[\s*4\s*\.\.\s*5\s*\]", f"{v}[2..2]", nb)
        out.append((m.start(), m.end(), f"if (strlen({v}) == 3) {{{nb}}}"))
    return _dedupe(out, t)


def edits_strlen2(t):
    out = []
    for m in RAND2.finditer(t):
        # only when nearby code indexes with a two-byte window
        window = t[m.end() : m.end() + 200]
        v = m.group("v")
        if not re.search(
            rf"{re.escape(v.split('[')[0])}\s*\[\s*\w+\s*\.\.\s*\(?\s*\w+\s*\+\s*1",
            window,
        ) and not re.search(r"\[\s*i\s*\.\.\s*\(?\s*i\s*\+\s*1", window):
            # mirror task: file = random(...)*2; msg uses msg_arr[rank][file..file+1]
            if "file" not in m.group(0) and not re.search(r"\[\s*file\s*\.\.", window):
                continue
        out.append((m.start("a"), m.end("b"), f"random(strlen({v}))"))
    for m in WHILE2.finditer(t):
        out.append((m.start(), m.end(), f"while (strlen({m.group('v')}) {m.group('op')} "))
    return _dedupe(out, t)


def _dedupe(edits, t):
    edits = sorted(edits, key=lambda x: (x[0], x[1]))
    res, last = [], -1
    for a, b, new in edits:
        if a < last or a == b and new == t[a:b]:
            continue
        if t[a:b] == new:
            continue
        res.append((a, b, new, t[a:b]))
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


def _merge(ed, t):
    # ed items are (a,b,new,old)
    ed = sorted(ed, key=lambda x: (x[0], x[1]))
    res, last = [], -1
    for a, b, new, old in ed:
        if a < last:
            continue
        if new == old:
            continue
        res.append((a, b, new, old))
        last = b
    return res


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
            if not any(
                s in raw
                for s in (b"is_chinese", b"mixup", b"strlen", b"channeld", b"fname", b"family")
            ):
                # still need strlen for clubpoem gates
                if b"strlen" not in raw and b"is_chinese" not in raw:
                    continue
            t = raw.decode("utf-8", "surrogateescape")
            ed = []
            if "parity" in kinds:
                ed += edits_parity(t)
            if "clubpoem" in kinds and ("mixup" in t or "strlen(first)" in t or "strlen(second)" in t):
                ed += edits_clubpoem(t)
            if "channeld" in kinds and ("fname" in t or "family" in t):
                ed += edits_channeld(t)
            if "strlen2" in kinds and (b"/ 2" in raw or b"/2" in raw):
                ed += edits_strlen2(t)
            ed = _merge(ed, t)
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
