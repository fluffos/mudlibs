#!/usr/bin/env python3
"""scripts/lpc_scan_loop_index.py [SLUG...]

A `for (v = ..; ..; v++)` loop whose body indexes an array with ANOTHER plain variable w (`user[i]` inside a `for (m ...)`) and never mentions v: the loop
variable is dead and every pass touches the same element, or runs off the array (KB 06 sections 7.345 and 7.347).  Found in the cron daemon of 16 libs
(`for (m = 0; m < sizeof(user); m++) user[i]->set("kill_guaishou", 1);`, `i` being the random district of the same event: the first pass with fewer users
than `i + 1` raises and the cron's `call_out("init_cron", 60)` after it never runs: no autosave, no quest refresh for the rest of the boot), in the
`feature/quest.lpc` of 13 libs (`for (i ..) if (check(living[j] ..)) target = living[j];`: the ordered fallback never looks past one NPC) and in
es1's pawnshop (`for (j = i; ..; j++) set(DIGITS[i], query(DIGITS[i+1]))`: the remembered-item list is not shifted).

Only single-purpose loops are reported: a body without `random`, `break`, `return`, `continue`, `call_out`, `input_to`, `time` and at most three
statements; a loop nested in a loop over w is skipped (`for (i ..) for (j ..) give(item[i])` is how a stack of N is handed out).  Prints
`HIT<TAB>slug<TAB>file<TAB>line<TAB>v<TAB>w<TAB>start of the body`; read each: a retry loop that indexes one fixed element is legitimate."""
import os
import re
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from lpc_fix_void_return import code_mask  # noqa: E402

GITLINKS = {"nt7", "xkx100utf8", "fy2005", "nightmare3", "residuum", "sanguozhi", "oxidus", "deadsouls_fluffos"}
SKIP = re.compile(r"/(u|w|wiz|wizard|wizards|open|players|backup|backups|old|bak|log|data|doc|example|examples|realms|test|tmp|raw|edit)/|[-_.](bak|old)/")
FOR = re.compile(rb"\bfor\s*\(\s*(\w+)\s*=\s*[^;()]*;[^;]*;\s*([^)]*)\)")


def body_after(code, pos):
    """(body bytes, its start) of the statement or block that follows a for header"""
    i, n = pos, len(code)
    while i < n and code[i] in b" \t\r\n":
        i += 1
    if i >= n:
        return b"", i
    if code[i:i + 1] == b"{":
        depth, j = 0, i
        while j < n:
            c = code[j:j + 1]
            if c == b"{":
                depth += 1
            elif c == b"}":
                depth -= 1
                if depth == 0:
                    return code[i:j + 1], i
            j += 1
        return code[i:], i
    depth, j = 0, i
    while j < n:
        c = code[j:j + 1]
        if c in b"([":
            depth += 1
        elif c in b")]":
            depth -= 1
        elif c == b";" and depth == 0:
            return code[i:j + 1], i
        j += 1
    return code[i:], i


def hits(b):
    mask = code_mask(b, heredoc=True)
    code = bytes(c if mask[i] else 32 for i, c in enumerate(b))
    fors = [(m, *body_after(code, m.end())) for m in FOR.finditer(code)]
    for m, body, bstart in fors:
        v, step = m.group(1), m.group(2)
        if not body or not re.search(rb"\b" + v + rb"\s*(\+\+|--|\+=|-=)|(\+\+|--)\s*" + v + rb"\b|\b" + v + rb"\s*=\s*" + v, step):
            continue
        idx = set(re.findall(rb"\[\s*([A-Za-z_]\w*)\s*\]", body))
        idx.discard(v)
        if not idx or re.search(rb"\b" + v + rb"\b", body):
            continue
        if re.search(rb"\b(random|break|return|continue|call_out|input_to|time)\b", body) or body.count(b";") > 3:
            continue
        for w in idx:
            if len(w) > 2:
                continue
            if re.search(rb"\b" + w + rb"\s*(=[^=]|\+\+|--|\+=|-=)|(\+\+|--)\s*" + w + rb"\b|for\s*\(\s*" + w + rb"\b|\(\s*&\s*" + w, body):
                continue
            if any(m2 is not m and m2.group(1) == w and b2 and bs2 <= m.start() < bs2 + len(b2) for m2, b2, bs2 in fors):
                continue
            yield b[:m.start()].count(b"\n") + 1, v.decode(), w.decode(), re.sub(rb"\s+", b" ", body)[:90].decode("latin-1")


def main():
    libs = sys.argv[1:] or sorted(d for d in os.listdir(f"{REPO}/libs") if os.path.isdir(f"{REPO}/libs/{d}/work"))
    n = 0
    for slug in libs:
        if slug in GITLINKS:
            continue
        out = subprocess.run(["git", "ls-files", "-z", "--", f"libs/{slug}/work"], cwd=REPO, capture_output=True).stdout
        for rel in (p.decode("utf-8", "surrogateescape") for p in out.split(b"\0") if p):
            if not rel.endswith((".lpc", ".c", ".h")):
                continue
            inner = rel[len(f"libs/{slug}/work"):]
            if SKIP.search(inner):
                continue
            try:
                data = open(f"{REPO}/{rel}", "rb").read()
            except OSError:
                continue
            for line, v, w, st in hits(data):
                n += 1
                print(f"HIT\t{slug}\t{inner}\t{line}\t{v}\t{w}\t{st}")
    print(f"{n} hit(s)", file=sys.stderr)


if __name__ == "__main__":
    main()
