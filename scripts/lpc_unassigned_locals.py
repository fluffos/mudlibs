#!/usr/bin/env python3
"""scripts/lpc_unassigned_locals.py [--all-files] SLUG...

Finds object locals that a function dereferences but never assigns (KB 06 section 7.246, unassigned locals): a perform
that declares `object weapon;` and calls `weapon->query_amount()` without ever storing the weapon (mantian-huayu
`huayu`), a check_fight() whose `!weapon` is always true so the buff ends after one second (ranmu-daofa `fentian`), a
`weapon2->name()` for the opponent's weapon that nothing fetched (blade-of-death `suo`), a `cob->name(1)` left behind when
the line that set it was commented out (sad-strike `tuo`).

For each function body (comments and strings masked) every `object` local that appears as `NAME->` and never as
`NAME =`, `NAME +=`, `&NAME`, a foreach variable or an sscanf target is printed as `HIT <file> <function> <name>`.  A
dereference behind a guard that is always false is still printed (fanliangyi-dao `hhh` loops over an array that is
never filled): read each hit.  By default only perform and exert files (`kungfu/skill/*/`, `daemon/skill/*/`) are
scanned; --all-files scans every `.lpc` outside wizard and backup dirs."""
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from lpc_fix_void_return import code_mask  # noqa: E402

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SKIP = re.compile(r"/(u|w|wiz|wizard|wizards|open|players|backup|backups|old|bak|log|data|doc|example|examples)/|[-_.](bak|old)/")
FUNC = re.compile(rb"(?m)^[ \t]*(?:[a-z]+[ \t*]+)*([A-Za-z_]\w*)[ \t]*\(([^)]*)\)[ \t\r\n]*\{")
DECL = re.compile(rb"(?m)^[ \t]*object[ \t]+([^;(=]*?(?:,[^;(]*?)*);")


def functions(code):
    """yield (name, params, body) for each top-level function of the masked source"""
    for m in FUNC.finditer(code):
        if m.group(1) in (b"if", b"while", b"for", b"switch", b"foreach", b"catch", b"return"):
            continue
        depth, i = 1, m.end()
        while i < len(code) and depth:
            c = code[i]
            depth += (c == 0x7B) - (c == 0x7D)
            i += 1
        yield m.group(1).decode(), m.group(2), code[m.end():i - 1]


def hits(b):
    mask = code_mask(b)
    code = bytes(c if mask[i] else 32 for i, c in enumerate(b))
    for name, params, body in functions(code):
        pnames = set(re.findall(rb"([A-Za-z_]\w*)\s*(?:,|$)", params.strip()))
        for dm in DECL.finditer(body):
            for v in dm.group(1).split(b","):
                v = v.strip().lstrip(b"*").strip()
                if not re.fullmatch(rb"[A-Za-z_]\w*", v) or v in pnames:
                    continue
                if not re.search(rb"\b" + v + rb"\s*->", body):
                    continue
                if re.search(rb"\b" + v + rb"\s*(=[^=]|\+=)|&\s*" + v + rb"\b|foreach\s*\([^)]*\b" + v + rb"\b"
                             rb"|sscanf\s*\([^;]*\b" + v + rb"\b", body):
                    continue
                yield name, v.decode()


def main():
    args = sys.argv[1:]
    every = "--all-files" in args
    n = 0
    for slug in [a for a in args if not a.startswith("--")]:
        work = f"{REPO}/libs/{slug}/work"
        if not os.path.isdir(work) or os.path.exists(f"{work}/.git"):
            continue
        roots = [work] if every else [f"{work}/kungfu/skill", f"{work}/daemon/skill"]
        for root in roots:
            for dp, dn, fn in os.walk(root):
                dn.sort()
                if SKIP.search(dp[len(work):] + "/") or (not every and dp == root):
                    continue
                for f in sorted(fn):
                    if f.endswith(".lpc"):
                        p = os.path.join(dp, f)
                        for func, v in hits(open(p, "rb").read()):
                            n += 1
                            print(f"HIT {slug} {p[len(work):]} {func} {v}")
    print(f"{n} hit(s)")


if __name__ == "__main__":
    main()
