#!/usr/bin/env python3
"""scripts/lpc_fix_family_index.py SLUG... [--apply]

The family mapping indexed inline (KB 05 section 7.30, inline shape): `ob->query("family")["family_name"]`,
`me->query("family")["master_name"]`, nitan's `query("family", ob)["master_id"]`.  A character without a sect -- every
new player, a 叛师 student, most NPCs -- has no "family" mapping, so the index raises `Value being indexed is zero`:
the NPC greeting or inquiry, the perform's sect check (xkm huashan-jianfa `san`), the room's valid_leave stops there
instead of refusing.

Each such read becomes the dbase path query `query("family/KEY")` (`query("family/KEY", ob)`), which gives the same
value when the mapping exists and 0 when it does not; a guard that already tested the mapping keeps working.  Left
alone: an assignment into the mapping (`query("family")["title"] = ...`, a path query is not an lvalue), comments and
strings, wizard and backup dirs, and a lib whose F_DBASE does not split `/` paths (none of the 105 libs on 2026-10-15).
Binary-safe.  Without --apply the plan is printed."""
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from lpc_fix_void_return import code_mask  # noqa: E402

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SKIP = re.compile(r"/(u|w|open|players|backup|old|bak|log|data|doc)/|[-_.](bak|old)/")
READ = re.compile(rb'query\(\s*"family"\s*(,\s*([A-Za-z_][A-Za-z0-9_]*(?:\(\))?)\s*)?\)\s*\[\s*"([a-z_]+)"\s*\]')
LVALUE = re.compile(rb"\s*(=[^=]|\+=|-=|\*=|/=|\+\+|--)")


def path_query(work):
    for rel in ("feature/dbase.lpc", "inherit/dbase.lpc", "std/dbase.lpc"):
        p = f"{work}/{rel}"
        if os.path.exists(p):
            b = open(p, "rb").read()
            return bool(re.search(rb'explode\(prop, *"/"\)|_query\(|strsrch\(prop, *.\/.\)', b))
    return False


def fix(b):
    mask = code_mask(b)
    out, last, n = [], 0, 0
    for m in READ.finditer(b):
        if not mask[m.start()] or LVALUE.match(b, m.end()):
            continue
        key, ob = m.group(3), m.group(2)
        out.append(b[last:m.start()])
        out.append(b'query("family/' + key + b'"' + (b", " + ob if ob else b"") + b")")
        last = m.end()
        n += 1
    out.append(b[last:])
    return b"".join(out), n


def main():
    args = sys.argv[1:]
    apply = "--apply" in args
    tot = 0
    for slug in [a for a in args if not a.startswith("--")]:
        work = f"{REPO}/libs/{slug}/work"
        if not os.path.isdir(work) or os.path.exists(f"{work}/.git"):
            continue
        if not path_query(work):
            print(f"LEFT  {slug}: its F_DBASE does not split / paths")
            continue
        for dp, dn, fn in os.walk(work):
            if SKIP.search(dp[len(work):] + "/"):
                continue
            for f in fn:
                if not f.endswith((".lpc", ".h")):
                    continue
                p = os.path.join(dp, f)
                b = open(p, "rb").read()
                if b'"family"' not in b:
                    continue
                out, n = fix(b)
                if n:
                    tot += n
                    print(f"FIX   {slug} {p[len(work):]}  {n}")
                    if apply:
                        open(p, "wb").write(out)
    print(f"{tot} read(s)" + ("" if apply else " (plan only; --apply writes)"))


if __name__ == "__main__":
    main()
