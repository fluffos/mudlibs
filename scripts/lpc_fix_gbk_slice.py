#!/usr/bin/env python3
"""scripts/lpc_fix_gbk_slice.py [--apply] [--list] [--rules A,B,C,E] SLUG [SLUG...]

String ranges of the GBK era count BYTES: `name[2..3]` was the second Chinese character of a name, `name[0..1] == "澄"` asked whether the name starts with the
character 澄 (a Chinese character is two bytes).  This driver's strings are UTF-8 and a range counts CHARACTERS (`strlen("澄观")` is 2, `"澄观"[0..1]` is
both characters, `"澄观"[0..0]` is the first), so the archive's text still says "two characters" where it meant "one" and every such line silently misbehaves (KB 07 section 8.1
lists the idiom, KB 06 section 7.360 the sweep): a new Shaolin disciple of the 112 libs with the xkx `kungfu/class/shaolin/*.h` masters is renamed `"澄" + name[2..3]`, which is
"澄" alone for a two-character name (the third character otherwise), and the generation test `name[0..1] == "澄"` of the same masters is never true.  `xkx100utf8`, the
community's own UTF-8 port, carries the converted text (`"澄" + name[1..1]`, `name[0..0] == "澄"`): it is the oracle the rules below reproduce.

Rules (an even-aligned slice `[a..b]`, a even and b odd, becomes `[a/2..(b-1)/2]`; only code is touched, comments and strings are skipped):
  A  `X[a..b] == "LIT"` / `!= "LIT"` (and `"LIT" == X[a..b]`) with a literal of N non-ASCII characters and b - a + 1 == 2N: certain, the slice can never equal the literal.  a == 0 is
     rewritten to `[0..N-1]`; a > 0 only for a name variable (`new_name[2..3] == "志"`) or when `--rules` names `A+` (the characters in front of it must all be Chinese).
  B  a name assembled from slices: `new_name = "澄" + name[2..3];`, `new_name = prename[random(sizeof(prename))] + name[0..1];`, `new_name = name[0..01] + "志" + name[4..5];`,
     `name = old_name[0..1] + name[0..1];`: the statements whose left side is `new_name` / `newname` / `nun_name` / `v5` (any right side with an aligned slice of a name
     variable) or `name` (a right side with a Chinese literal, `prename` or two slices); every aligned slice of `name` / `old_name` / `newname` / `new_name` / `v4` in them.
  C  `new_name[0..1] = "玄";` (a slice on the left side that a literal of N characters replaces): `[0..N-1]`.
  E  `name[0..1] != arg[0..1]`: the same aligned range on both sides of a comparison between name variables and `arg`.
Left alone and printed with `--list` as LEFT: a slice of an ASCII id (`name[0..0]` of a path shard, `fname[0..3] == "room"`), a time string (`ctime(time())[4..19]`), and every
aligned slice no rule names (`name = name[0..7]` is a truncation to eight characters now, longer than before and harmless).  Binary mode (UTF-8 with surrogateescape), the file's own line
endings.  NOT idempotent: halving `[0..3]` gives `[0..1]`, which is again an aligned slice, so a second run would halve the converted text again; the tool keeps a ledger of the files it has
rewritten (`scripts/gbk_slice_converted.txt`, commit it with the edits) and skips them.  Dry run unless `--apply`.  Without SLUG nothing runs; `--all` takes every lib with a work tree."""
import os
import re
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SKIP = re.compile(  # `/open/` is playable world in Taiwanese / dreamofseven-style libs
    r"/(u|w|wiz|wizard|wizards|players|backup|backups|bak|old|test|tests|tmp|data|log|realms|doc|docs|example|examples|orphaned-dir)/|[-_.](bak|old)|class_bak|orphaned-dir|/海洋2002/")
NV = r"(?:name|old_name|newname|new_name|v4)"
IDX = r"\[\s*(\d+)\s*\.\.\s*(\d+)\s*\]"
NONASCII = re.compile(r"^[^\x00-\x7f]+$")
LEDGER = os.path.join(REPO, "scripts", "gbk_slice_converted.txt")     # `slug<TAB>/path` of every file this tool has rewritten: NOT idempotent (see the docstring), a listed file is never touched again
NAMEHEADS = {"new_name", "newname", "name", "old_name"}      # a name variable holds Chinese text from its first character: `new_name[2..3] == "志"` is the second character
SLICE_RAW = re.compile(rb"\[\s*\d+\s*\.\.\s*\d+\s*\]")


def code_only(t):
    """t with comment text blanked (same length); string literals are walked so a `//` inside one is not a comment"""
    out, i, n = [], 0, len(t)
    while i < n:
        c = t[i]
        if c == '"':
            j = i + 1
            while j < n and t[j] != '"' and t[j] != "\n":
                j += 2 if t[j] == "\\" else 1
            out.append(t[i:j + 1])
            i = j + 1
        elif c == "/" and t[i + 1:i + 2] == "/":
            j = t.find("\n", i)
            j = n if j < 0 else j
            out.append(" " * (j - i))
            i = j
        elif c == "/" and t[i + 1:i + 2] == "*":
            j = t.find("*/", i + 2)
            j = n if j < 0 else j + 2
            out.append("".join("\n" if ch == "\n" else " " for ch in t[i:j]))
            i = j
        else:
            out.append(c)
            i += 1
    return "".join(out)


def num(s):
    return int(s, 10)


def half(a, b):
    return a // 2, (b - 1) // 2


def aligned(a, b):
    return a % 2 == 0 and b % 2 == 1 and b > a


def rewrite(m, g1, g2, a, b):
    """text of match m with the two index groups replaced by a, b (the spacing around the numbers is kept)"""
    s = m.group(0)
    s0 = m.start(0)
    out = s[:m.start(g1) - s0] + str(a) + s[m.end(g1) - s0:m.start(g2) - s0] + str(b) + s[m.end(g2) - s0:]
    return out


def edits(t, rules):
    """-> list of (start, end, new text, rule, old text) for the code of t"""
    c = code_only(t)
    out = []
    taken = []

    def free(s, e):
        return not any(s < te and ts < e for ts, te in taken)

    def add(s, e, new, rule):
        if free(s, e):
            taken.append((s, e))
            out.append((s, e, new, rule, t[s:e]))

    if "A" in rules or "A+" in rules:
        for m in re.finditer(r'(?P<head>[A-Za-z_][A-Za-z_0-9]*|\)|\])' + IDX + r'(?P<op>\s*(?:==|!=)\s*)"(?P<lit>[^"\n]+)"', c):
            a, b = num(m.group(2)), num(m.group(3))
            lit = t[m.start("lit"):m.end("lit")]
            if not NONASCII.match(lit) or not aligned(a, b) or b - a + 1 != 2 * len(lit):
                continue
            if a == 0 or "A+" in rules or m.group("head") in NAMEHEADS:
                add(m.start(), m.end(), rewrite(m, 2, 3, a // 2, a // 2 + len(lit) - 1), "A" if a == 0 else "A+")
        for m in re.finditer(r'"(?P<lit>[^"\n]+)"(?P<op>\s*(?:==|!=)\s*)(?P<head>[A-Za-z_][A-Za-z_0-9]*|\)|\])' + IDX, c):
            a, b = num(m.group(4)), num(m.group(5))
            lit = t[m.start("lit"):m.end("lit")]
            if not NONASCII.match(lit) or not aligned(a, b) or b - a + 1 != 2 * len(lit):
                continue
            if a == 0 or "A+" in rules or m.group("head") in NAMEHEADS:
                add(m.start(), m.end(), rewrite(m, 4, 5, a // 2, a // 2 + len(lit) - 1), "A" if a == 0 else "A+")
    if "C" in rules:
        for m in re.finditer(r'(?P<head>\bnew_name|\bnewname|\bname)' + IDX + r'(?P<op>\s*=\s*)"(?P<lit>[^"\n]+)"\s*;', c):
            a, b = num(m.group(2)), num(m.group(3))
            lit = t[m.start("lit"):m.end("lit")]
            if NONASCII.match(lit) and aligned(a, b) and b - a + 1 == 2 * len(lit) and a == 0:
                add(m.start(), m.end(), rewrite(m, 2, 3, 0, len(lit) - 1), "C")
    if "B" in rules:
        for m in re.finditer(r'\b(?P<lhs>new_name|newname|nun_name|v5|name)\s*=(?!=)(?P<rhs>[^;]*);', c):
            rhs_s = m.start("rhs")
            rhs = c[rhs_s:m.end("rhs")]
            sl = [s for s in re.finditer(r'\b(?:name|old_name|newname|new_name|v4|arg)' + IDX, rhs) if aligned(num(s.group(1)), num(s.group(2)))]
            if not sl:
                continue
            if m.group("lhs") == "name":
                lit = re.search(r'"[^"\n]*[\u4e00-\u9fff][^"\n]*"', rhs)
                if not (lit or "prename" in rhs or len(sl) >= 2):
                    continue
            for s in sl:
                a, b = num(s.group(1)), num(s.group(2))
                na, nb = half(a, b)
                s_abs = rhs_s + s.start()
                add(s_abs, rhs_s + s.end(), rewrite(s, 1, 2, na, nb), "B")
    if "F" in rules and "辈分不对，重来" in t:
        # the rename registrar (Zhao Chengzhi `zhuce`, `change_name.h`): its gates count bytes too, so no valid name was ever accepted
        for pat, new in (
            (r'strlen\(arg\)\s*!=\s*6\s*\|\|\s*arg\[\s*4\s*\.\.\s*5\s*\]\s*!=\s*"([风子])"', 'strlen(arg) != 3 || arg[2..2] != "\\1"'),
            (r'strlen\(arg\)\s*!=\s*4\b', 'strlen(arg) != 2'),
            (r'strlen\(arg\)\s*<\s*6\b', 'strlen(arg) < 3'),
            (r'strlen\(arg\)\s*>\s*6\b', 'strlen(arg) > 3'),
            (r'\bi\s*<\s*4\s*\|\|\s*i\s*>\s*8\s*\|\|\s*i\s*%\s*2\b', 'i < 2 || i > 4'),
            (r'\bi\s*%\s*2\s*==\s*0\s*&&\s*(?=!is_chinese)', ''),
        ):
            for m in re.finditer(pat, c):
                add(m.start(), m.end(), m.expand(new), "F")
    if "F" in rules and "最多四个字" in t:
        # xkx2001's `shiye` (Tan Youji, `change <name>`): four characters were `strlen(name) > 8` bytes
        for m in re.finditer(r'strlen\(name\)\s*>\s*8\b', c):
            add(m.start(), m.end(), "strlen(name) > 4", "F")
    if "G" in rules:
        for m in re.finditer(r'\bto_chinese\s*\([^()\n]*\)\s*' + IDX, c):
            a, b = num(m.group(1)), num(m.group(2))
            if aligned(a, b):
                na, nb = half(a, b)
                add(m.start(), m.end(), rewrite(m, 1, 2, na, nb), "G")
    if "H" in rules:
        for m in re.finditer(r'(?:->\s*query\(\s*"(?:name|c_name)"\s*\)|->\s*name\(\s*\d*\s*\)|COLOR_D->uncolor\(\s*\w+->query\(\s*"name"\s*\)\s*\)|\(string\)\s*\w+->query\(\s*"c_name"\s*\)\))\s*' + IDX, c):
            a, b = num(m.group(1)), num(m.group(2))
            if aligned(a, b):
                na, nb = half(a, b)
                add(m.start(), m.end(), rewrite(m, 1, 2, na, nb), "H")
    if "E" in rules:
        for m in re.finditer(r'\b(?P<x>' + NV + r'|arg)' + IDX + r'(?P<op>\s*(?:==|!=)\s*)(?P<y>' + NV + r'|arg)' + IDX, c):
            a, b, a2, b2 = num(m.group(2)), num(m.group(3)), num(m.group(6)), num(m.group(7))
            if (a, b) == (a2, b2) and aligned(a, b):
                na, nb = half(a, b)
                s = m.group(0)
                s0 = m.start(0)
                new = s[:m.start(2) - s0] + str(na) + s[m.end(2) - s0:m.start(3) - s0] + str(nb) + s[m.end(3) - s0:m.start(6) - s0] + str(na) + s[m.end(6) - s0:m.start(7) - s0] + str(nb) + s[m.end(7) - s0:]
                add(m.start(), m.end(), new, "E")
    return sorted(out)


def apply_edits(t, ed):
    out, pos = [], 0
    for s, e, new, _rule, _old in ed:
        out.append(t[pos:s])
        out.append(new)
        pos = e
    out.append(t[pos:])
    return "".join(out)


def tracked(slug):
    out = subprocess.run(["git", "ls-files", "-z", "--", f"libs/{slug}/work"], cwd=REPO, capture_output=True).stdout
    pre = f"libs/{slug}/work"
    for p in out.split(b"\0"):
        if not p:
            continue
        s = p.decode("utf-8", "surrogateescape")
        rel = s[len(pre):]
        if rel.endswith((".lpc", ".h")) and not SKIP.search(rel) and not re.search("[\udc80-\udcff]", rel):
            yield rel


def main():
    argv = sys.argv[1:]
    apply, listing = "--apply" in argv, "--list" in argv
    rules = {"A", "B", "C", "E", "F", "G", "H"}
    for a in argv:
        if a.startswith("--rules="):
            rules = set(a.split("=", 1)[1].split(","))
    names = [a for a in argv if not a.startswith("--")]
    if "--all" in argv:
        names = sorted(p for p in os.listdir(os.path.join(REPO, "libs")) if os.path.isdir(os.path.join(REPO, "libs", p, "work")))
    if not names:
        sys.exit(__doc__)
    tot = {}
    done = set()
    if os.path.isfile(LEDGER):
        done = set(l for l in open(LEDGER, encoding="utf-8", errors="surrogateescape").read().split("\n") if l)
    newly = set()
    for slug in names:
        root = os.path.join(REPO, "libs", slug, "work")
        nfile = nedit = 0
        for rel in tracked(slug):
            p = root + rel
            if f"{slug}\t{rel}" in done:
                continue
            try:
                raw = open(p, "rb").read()
            except OSError:
                continue
            if not SLICE_RAW.search(raw):
                continue
            t = raw.decode("utf-8", "surrogateescape")
            ed = edits(t, rules)
            if not ed:
                continue
            nfile += 1
            nedit += len(ed)
            for r in ed:
                tot[r[3]] = tot.get(r[3], 0) + 1
            if listing:
                for s, e, new, rule, old in ed:
                    ln = t.count("\n", 0, s) + 1
                    print(f"{slug} {rel}:{ln} {rule}: {old}  ->  {new}")
            if apply:
                nt = apply_edits(t, ed)
                if nt != t:
                    open(p, "wb").write(nt.encode("utf-8", "surrogateescape"))
                    newly.add(f"{slug}\t{rel}")
        if apply and newly:
            # per lib, so an interrupted run never leaves a rewritten file out of the ledger
            open(LEDGER, "w", encoding="utf-8", errors="surrogateescape").write("\n".join(sorted(done | newly)) + "\n")
        print(f"{slug}: {nedit} edit(s) in {nfile} file(s)" + ("" if apply else " (plan only)"), file=sys.stderr)
    print("by rule: " + ", ".join(f"{k} {v}" for k, v in sorted(tot.items())), file=sys.stderr)
    if apply and newly:
        print(f"ledger: {len(newly)} file(s) added, {len(done | newly)} in all", file=sys.stderr)


if __name__ == "__main__":
    main()
