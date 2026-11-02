#!/usr/bin/env python3
"""scripts/lpc_fix_default_switch.py [--apply] [--list] SLUG [SLUG...] | --all | --file libs/SLUG/work/REL [--file ...]

`switch (x) { /* case 1: ... */ default: stmts; break; }`: a switch whose only label is `default` does not compile in this driver (`need case statements in switch/case, not
just default:`), and the object that holds it never loads.  Archives get there when somebody commented out the `case` arms and left `default` (hhsj / xfbhh's
`king4.lpc` `switch (random(1)) { default: msg = ..; }`, the hy5 / hymud `meskill/dan.lpc`, `hun.lpc`, `lian.lpc`, pd's realty and the dragons' halls, sgzmudsgz's patrol job) or when a
one-arm table was never extended (ninetears' `add_disa.lpc`).  The statement is a block that runs the default body: `switch (EXPR) { default: BODY break; }` becomes `{ BODY }`
(a trailing `break;` goes; `EXPR` stays as a statement only when it assigns, increments or calls a function other than `random` / `query*`; comments between the braces and the
`default` label stay).  A `break` anywhere else in the body (an early exit from the switch) is left for hand work and listed as MANUAL, a `switch` over a body that has `case` labels is never
touched, nor are the deliberate compiler-error demos (`two_default.lpc`, `/compiler/fail/`).  Binary mode, the file's own line endings (only text inside the statement is moved);
idempotent (the result has no switch).  Dry run unless `--apply`; `--list` prints every edit.  `--file` takes explicit paths past the wizard-directory filter
(dreamofseven's `/d/wiz/entrance` is a room players walk into, the census found it)."""
import os
import re
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SKIP = re.compile(r"/(u|w|wiz|wizard|wizards|open|players|backup|backups|bak|old|test|tests|tmp|data|log|realms|doc|docs|error_messages|fail)/|[-_.](bak|old)|two_default", re.I)
TOK = re.compile(r'"(?:[^"\\\n]|\\.)*"|\'(?:[^\'\\\n]|\\.)*\'|//[^\n]*|/\*.*?\*/|\bswitch\b|\bcase\b|\bdefault\b|\bbreak\b|\bfor\b|\bwhile\b|\bdo\b|\bforeach\b|[{}()]', re.S)
PURE = re.compile(r"\b(random|query\w*)\s*\(")


def find_all(t):
    """(start, expr_text, open_brace, close_brace, default_pos, after_colon, breaks) of every switch with `default` and no `case` at its own level"""
    toks = [(m.start(), m.end(), m.group()) for m in TOK.finditer(t) if m.group()[0] not in "\"'/"]
    out = []
    n = len(toks)
    for i in range(n):
        if toks[i][2] != "switch" or i + 1 >= n or toks[i + 1][2] != "(":
            continue
        j = i + 2
        d = 1
        while j < n and d:
            if toks[j][2] == "(":
                d += 1
            elif toks[j][2] == ")":
                d -= 1
            j += 1
        if j >= n or toks[j][2] != "{" or d:
            continue
        expr = t[toks[i + 1][1]:toks[j - 1][0]]
        ob = toks[j][0]
        d = 1
        k = j + 1
        cases = 0
        default = None
        breaks = []
        loop_depth = []                  # brace depths of enclosing loops / nested switches inside the body: a `break` there is theirs
        while k < n and d:
            tk = toks[k][2]
            if tk == "{":
                d += 1
            elif tk == "}":
                d -= 1
            elif d == 1 and tk == "case":
                cases += 1
            elif d == 1 and tk == "default":
                default = toks[k]
            elif tk == "break":
                breaks.append(toks[k][0])
            k += 1
        if d or cases or default is None:
            continue
        cb = toks[k - 1][0]
        out.append((toks[i][0], expr, ob, cb, default[0], default[1], breaks))
    return out


def inside_loop(t, ob, default_end, cb, bpos):
    """True when the `break` at bpos sits in a loop or nested switch of the default body"""
    body = t[default_end:bpos]
    # a loop / switch header seen after `default:` whose block is still open at bpos
    depth = 0
    opened = []
    for m in re.finditer(r"\b(for|while|do|foreach|switch)\b|[{}]", body):
        g = m.group()
        if g == "{":
            depth += 1
        elif g == "}":
            depth -= 1
            while opened and opened[-1] > depth:
                opened.pop()
        else:
            opened.append(depth + 1)
    return bool(opened)


def edits(t):
    res, manual = [], []
    for start, expr, ob, cb, dpos, dend, breaks in find_all(t):
        m = re.match(r"\s*:", t[dend:])
        if not m:
            continue
        after = dend + m.end()
        body = t[after:cb]
        # the colon after `default` may be followed by comments; a trailing `break;` is removed
        stripped = re.sub(r"//[^\n]*|/\*.*?\*/", lambda x: " " * len(x.group()), body, flags=re.S)
        tm = re.search(r"\bbreak\s*;(\s*)$", stripped)
        real = [b for b in breaks if b >= after and not inside_loop(t, ob, after, cb, b)]
        trailing = tm is not None
        if len(real) > (1 if trailing else 0) or (real and not trailing):
            manual.append((start, "a break inside the default body"))
            continue
        keep = ""
        if re.search(r"(?<![=!<>])=(?!=)|\+\+|--", expr):
            keep = expr.strip() + ";"
        else:
            for cm in re.finditer(r"([A-Za-z_]\w*)\s*\(", expr):
                if not PURE.match(expr[cm.start():]):
                    keep = expr.strip() + ";"
                    break
        pre = t[ob + 1:dpos]                      # between the brace and `default`: the commented-out arms stay here
        dbody = t[after:cb]
        if trailing:
            core, tail = dbody[:tm.start()], dbody[tm.start(1):]
        else:
            core, tail = dbody, ""
        if not core.strip():
            core = ""
            pre = pre.rstrip(" \t")
            tail = re.sub(r"^[ \t]*\r?\n", "", tail) if pre.endswith("\n") else tail
        elif re.match(r"[ \t]*\r?\n", core):
            pre = pre.rstrip(" \t")
            core = re.sub(r"^[ \t]*\r?\n", "", core)
        else:
            core = core.lstrip(" \t")
        if trailing:
            core = core.rstrip(" \t")
            if core.endswith("\n"):                # the `break;` sat on a line of its own: no blank line in its place
                tail = re.sub(r"^\r?\n", "", tail)
        else:
            tail = ""
        if keep:                                  # the switch expression runs on a line of its own, at the indentation of the old `default`
            nl = "\r\n" if "\r\n" in t[ob:cb] else "\n"
            ind = re.search(r"[ \t]*$", pre).group(0)
            keep = nl + ind + keep.strip() + ("" if re.match(r"[ \t]*\r?\n", pre) else nl + ind)
            new = "{" + keep + pre + core + tail
        else:
            new = "{" + pre + core + tail
        res.append((start, cb + 1, new + "}", t[start:cb + 1]))
    return res, manual


def tracked(slug):
    out = subprocess.run(["git", "grep", "-l", "-z", "--all-match", "-E", "-e", r"\bswitch[[:space:]]*\(", "-e", r"\bdefault[[:space:]]*:", "--", f"libs/{slug}/work/*.lpc", f"libs/{slug}/work/*.h"],
                         cwd=REPO, capture_output=True).stdout
    for p in out.split(b"\0"):
        if p:
            s = p.decode("utf-8", "surrogateescape")
            if not SKIP.search(s[s.index("/work/"):]):
                yield s


def main():
    argv = sys.argv[1:]
    apply, listing = "--apply" in argv, "--list" in argv
    files = [argv[i + 1] for i, a in enumerate(argv) if a == "--file" and i + 1 < len(argv)]
    names = [a for a in argv if not a.startswith("--") and a not in files]
    if files:
        names = sorted({f.split("/")[1] for f in files})
    if "--all" in argv:
        names = sorted(p for p in os.listdir(os.path.join(REPO, "libs")) if os.path.isdir(os.path.join(REPO, "libs", p, "work")))
    if not names:
        sys.exit(__doc__)
    total = nman = 0
    for slug in names:
        nfile = nedit = 0
        for rel in ([f for f in files if f.split("/")[1] == slug] if files else tracked(slug)):
            p = os.path.join(REPO, rel)
            try:
                raw = open(p, "rb").read()
            except OSError:
                continue
            t = raw.decode("utf-8", "surrogateescape")
            ed, manual = edits(t)
            for pos, why in manual:
                nman += 1
                print(f"MANUAL {slug} {rel}:{t.count(chr(10), 0, pos) + 1} {why}")
            if not ed:
                continue
            nfile += 1
            nedit += len(ed)
            if listing:
                for a, b, new, old in ed:
                    o1, n1 = re.sub(r"\s+", " ", old)[:90], re.sub(r"\s+", " ", new)[:90]
                    print(f"{slug} {rel}:{t.count(chr(10), 0, a) + 1} {o1}  ->  {n1}")
            if apply:
                out, pos = [], 0
                for a, b, new, old in ed:
                    out.append(t[pos:a])
                    out.append(new)
                    pos = b
                out.append(t[pos:])
                open(p, "wb").write("".join(out).encode("utf-8", "surrogateescape"))
        total += nedit
        if nedit:
            print(f"{slug}: {nedit} switch(es) in {nfile} file(s)" + ("" if apply else " (plan only)"), file=sys.stderr)
    print(f"{total} switch(es), {nman} manual", file=sys.stderr)


if __name__ == "__main__":
    main()
