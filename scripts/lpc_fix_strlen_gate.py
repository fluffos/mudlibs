#!/usr/bin/env python3
"""scripts/lpc_fix_strlen_gate.py [--apply] [--list] SLUG [SLUG...] | --all

`if ((strlen(name) < 4) || (strlen(name) > 12)) { write("对不起，你房屋的名字必须是 2 到 6 个中文字。\\n"); return 0; }`: the GBK-era length gate counts BYTES (a Chinese character is two), this
driver's `strlen()` counts characters (KB 07 section 8.1, KB 06 section 7.360), so a gate that was "2 to 6 characters" is "4 to 12 characters" now: a two- or three-character
name of a house (the builder `luban`, 38 libs), a gang (`nicai`, `xiang`, `huangfeihong`), a group (`gforce`), an IRC room, a title (`baoer`), a task is turned away by the
message that says it is allowed, and the upper bound is twice as wide as the text says.  The message is the oracle: the condition of an `if` whose strlen gates (`strlen(V) < G`,
`strlen(V) > G`) are each twice a bound that the message in the next three lines states (`2 到 6 个中文字`, `一到二十个中文字`, `二到八个字`, `最多 8 个中文字`, `8 个中文字以内`)
is rewritten with the halved numbers; one gate that does not match its bound leaves the whole condition alone, and a message that names English letters, bytes or digits
(`100 个英文或 50 个汉字`) is skipped.  `<=` / `>=` gates and gates on `sizeof()` are not touched.  Binary mode, the file's own line endings; a halved gate no longer equals twice
the bound, so a second run changes nothing (the ledger of lpc_fix_gbk_slice.py is for the slices, which are not idempotent).  Dry run unless `--apply`; `--list` prints every edit."""
import os
import re
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SKIP = re.compile(r"/(u|w|wiz|wizard|wizards|open|players|backup|backups|bak|old|test|tests|tmp|data|log|realms|doc|docs|example|examples|orphaned-dir)/|[-_.](bak|old)|class_bak|orphaned-dir|/海洋2002/")
CN = {"一": 1, "二": 2, "两": 2, "三": 3, "四": 4, "五": 5, "六": 6, "七": 7, "八": 8, "九": 9, "十": 10, "十一": 11, "十二": 12, "十三": 13, "十四": 14, "十五": 15, "十六": 16, "十七": 17, "十八": 18, "十九": 19, "二十": 20, "三十": 30, "四十": 40, "五十": 50}
NUM = r"(?:[0-9]+|二十|三十|四十|五十|十[一二三四五六七八九]|[一二两三四五六七八九十])"
UNIT = r"\s*个?\s*(?:汉字|中文字|中文|字符|字)"
RANGE = re.compile(r"(" + NUM + r")\s*(?:到|至|~|～|-)\s*(" + NUM + r")" + UNIT)
UPPER = re.compile(r"(?:最多|至多|不超过|不得超过|不能超过|控制在|限制在)\s*(" + NUM + r")" + UNIT + r"|(" + NUM + r")" + UNIT + r"\s*(?:以内|以下)")
LOWER = re.compile(r"(?:至少|最少|不少于)\s*(" + NUM + r")" + UNIT)
AMBIG = re.compile(r"英文|字母|字节|数字|ASCII|byte", re.I)
GATE = re.compile(r"strlen\(\s*([A-Za-z_]\w*(?:\[[^\]]*\])?)\s*\)\s*(<=|>=|<|>)\s*(\d+)")
LENVAR = re.compile(r"\b([A-Za-z_]\w*)\s*=\s*strlen\(")                     # `i = strlen(arg);` / `int i = strlen(name);`: the length kept in a variable
PARITY = re.compile(r"\s*\|\|\s*\(?\s*%s\s*%%\s*2(?:\s*==\s*1|\s*!=\s*0)?\s*\)?")
IF = re.compile(r"\bif\s*\(")
STR = re.compile(r'"((?:[^"\\\n]|\\.)*)"')


def val(x):
    return int(x) if x.isdigit() else CN.get(x)


def close_paren(t, i):
    """index of the ')' matching the '(' at t[i - 1], skipping strings; -1 if none"""
    depth, n = 1, len(t)
    while i < n:
        c = t[i]
        if c == '"':
            j = i + 1
            while j < n and t[j] != '"' and t[j] != "\n":
                j += 2 if t[j] == "\\" else 1
            i = j + 1
            continue
        if c == "(":
            depth += 1
        elif c == ")":
            depth -= 1
            if depth == 0:
                return i
        i += 1
    return -1


def bounds(msg):
    """(lower, upper) the message states in Chinese characters, None for an unknown side; None when nothing usable"""
    if AMBIG.search(msg):
        return None
    m = RANGE.search(msg)
    if m:
        a, b = val(m.group(1)), val(m.group(2))
        return (a, b) if a and b and a <= b else None
    lo = hi = None
    m = UPPER.search(msg)
    if m:
        hi = val(m.group(1) or m.group(2))
    m = LOWER.search(msg)
    if m:
        lo = val(m.group(1))
    return (lo, hi) if (lo or hi) else None


def comment_free(t):
    """t with comments blanked (same length), strings kept"""
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


def edits(t):
    c = comment_free(t)
    out = []
    for m in IF.finditer(c):
        s = m.end()
        e = close_paren(c, s)
        if e < 0:
            continue
        cond = c[s:e]
        gates = list(GATE.finditer(cond))
        # the length kept in a variable: `i = strlen(arg);` a few lines above, gates `i < 4 || i > 24 || i % 2`
        lenvars = set(x.group(1) for x in LENVAR.finditer(c[max(0, m.start() - 600):m.start()]))
        vgates = []
        for v in lenvars:
            vgates += [(v, g) for g in re.finditer(r"(?<![\w.])" + re.escape(v) + r"\s*(<=|>=|<|>)\s*(\d+)", cond)]
        if not gates and not vgates:
            continue
        # the message: the first string with a character count in the next three lines after the condition
        k = e + 1
        window_end = k
        for _ in range(4):
            nl = c.find("\n", window_end)
            if nl < 0:
                window_end = len(c)
                break
            window_end = nl + 1
        bd = None
        for sm in STR.finditer(c[k:window_end]):
            bd = bounds(sm.group(1))
            if bd:
                break
        if not bd:
            continue
        lo, hi = bd
        new = []
        ok = True
        for g in gates:
            op, gv = g.group(2), int(g.group(3))
            if op == "<" and lo and gv == 2 * lo:
                new.append((s + g.start(3), s + g.end(3), str(lo)))
            elif op == ">" and hi and gv == 2 * hi:
                new.append((s + g.start(3), s + g.end(3), str(hi)))
            else:
                ok = False
                break
        for v, g in vgates:
            op, gv = g.group(1), int(g.group(2))
            if op == "<" and lo and gv == 2 * lo:
                new.append((s + g.start(2), s + g.end(2), str(lo)))
            elif op == ">" and hi and gv == 2 * hi:
                new.append((s + g.start(2), s + g.end(2), str(hi)))
            else:
                ok = False
                break
        if not ok or not new:
            continue
        for a, b, nv in new:
            out.append((a, b, nv, t[a:b]))
        # the parity term of a length variable (an odd byte count was half a character) goes, and so does the parity test of the loop that follows
        for v in lenvars:
            if any(True for _ in re.finditer(r"(?<![\w.])" + re.escape(v) + r"\s*(?:<|>)", cond)):
                for pm in re.finditer(PARITY.pattern % re.escape(v), cond):
                    out.append((s + pm.start(), s + pm.end(), "", t[s + pm.start():s + pm.end()]))
                tail = c[e:e + 700]
                lm = re.search(r"\b" + re.escape(v) + r"\s*%\s*2\s*==\s*0\s*&&\s*", tail)
                if lm and "is_chinese" in tail[lm.end():lm.end() + 80]:
                    out.append((e + lm.start(), e + lm.end(), "", t[e + lm.start():e + lm.end()]))
    # overlapping edits (nested ifs found twice) are dropped, the first one wins
    out.sort()
    res, last = [], -1
    for a, b, nv, old in out:
        if a < last:
            continue
        res.append((a, b, nv, old))
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
    names = [a for a in argv if not a.startswith("--")]
    if "--all" in argv:
        names = sorted(p for p in os.listdir(os.path.join(REPO, "libs")) if os.path.isdir(os.path.join(REPO, "libs", p, "work")))
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
            if b"strlen" not in raw:
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
                    line = t.split("\n")[ln - 1].strip()
                    print(f"{slug} {rel}:{ln} {old} -> {new}   {line[:110]}")
            if apply:
                nt = apply_edits(t, ed)
                if nt != t:
                    open(p, "wb").write(nt.encode("utf-8", "surrogateescape"))
        total += nedit
        print(f"{slug}: {nedit} gate(s) in {nfile} file(s)" + ("" if apply else " (plan only)"), file=sys.stderr)
    print(f"{total} gate(s)", file=sys.stderr)


if __name__ == "__main__":
    main()
