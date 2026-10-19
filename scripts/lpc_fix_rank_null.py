#!/usr/bin/env python3
"""scripts/lpc_fix_rank_null.py [SLUG...] [--apply]

`RANK_D->query_respect(this_player())` called while an NPC is being created (an `inquiry` mapping or a `chat_msg` array built in `create()`,
1,800 files in 60+ xkx-lineage libs: the wudang disciples, yideng, the bianliang scholars ...) dies with
`Bad argument 1 to EFUN call_other()` whenever nobody is acting: the driver's own `reset()` runs with no command giver, so the room's
`make_inventory()` cannot bring the NPC back and a killed NPC never respawns (found by scripts/lpc_reach_census.py --walk, KB 06 section 7.273).
The old driver let `0->query("age")` answer 0, so `query_respect(0)` fell through to the default branch ("小兄弟"); this driver raises.

The fix is in the daemon, not in 1,800 NPC files: each of `query_respect`, `query_rude`, `query_self`, `query_self_rude`, `query_close`,
`query_self_close` of `adm/daemons/rankd.lpc` starts with

    if (!objectp(ob)) ob = this_object();

after its leading local declarations, so every `ob->query(...)` answers 0 as it did and the default branch is taken.  A function whose
leading declaration already reads the parameter, or that already has the test, is listed and left.
Binary-safe, line endings kept; without --apply the plan is printed (FIX / SKIP lines); idempotent."""
import os
import re
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
NAMES = ("query_respect", "query_rude", "query_self", "query_self_rude", "query_close", "query_self_close")
HDR = re.compile(rb"(?m)^((?:varargs[ \t]+)?(?:string|mixed))[ \t]+(" + b"|".join(n.encode() for n in NAMES) + rb")[ \t]*\([ \t]*object[ \t]+(\w+)[ \t]*\)[ \t]*(\{?)[ \t]*(\r?)$")
TYPES = rb"(?:int|string|object|mixed|mapping|float|status|buffer|function)\b[^;]*;"
DECL = re.compile(rb"^[ \t]*(?:" + TYPES + rb"[ \t]*)+(?://.*)?\r?$")            # one or more declarations on a line (`int age; string race;`)
DECL_OPEN = re.compile(rb"^[ \t]*(?:int|string|object|mixed|mapping|float|status|buffer|function)\b[^;(]*(?:,[ \t]*)?\r?$")   # a declaration that continues on the next line


def fix(b, slug):
    """-> (new bytes, [messages])"""
    msgs = []
    inserts = []
    for m in HDR.finditer(b):
        name, par = m.group(2).decode(), m.group(3).decode()
        eol = b"\r\n" if m.group(5) else b"\n"
        nl = b.find(b"\n", m.end())
        if nl < 0:
            continue
        body_from = nl + 1
        if not m.group(4):
            nxt = b.find(b"\n", body_from)
            if b[body_from:nxt].strip() != b"{":
                msgs.append(f"SKIP  {slug} {name}: the opening brace is not where expected")
                continue
            body_from = nxt + 1
        p = body_from
        while True:
            q = b.find(b"\n", p)
            if q < 0:
                break
            line = b[p:q]
            if DECL.match(line):
                if re.search(rb"\b" + par.encode() + rb"\b", line):
                    break                    # a declaration that reads the parameter: handled below
                p = q + 1
                continue
            if not line.strip():
                p = q + 1
                continue
            break
        if re.search(rb"objectp\s*\(\s*" + par.encode() + rb"\s*\)", b[p:p + 200]):
            continue
        first = b[p:b.find(b"\n", p)]
        if DECL.match(first) or DECL_OPEN.match(first):
            msgs.append(f"SKIP  {slug} {name}: a declaration reads {par} or continues on the next line")
            continue
        ind = re.match(rb"[ \t]*", first).group(0) or b"  "
        inserts.append((p, ind + f"if (!objectp({par})) {par} = this_object();".encode() + eol))
        msgs.append(f"FIX   {slug} {name}")
    out = b
    for p, g in reversed(inserts):
        out = out[:p] + g + out[p:]
    return out, msgs


def main():
    args = sys.argv[1:]
    apply = "--apply" in args
    only = [a for a in args if not a.startswith("--")]
    libs = only or sorted(os.listdir(f"{REPO}/libs"))
    nlib = nfn = 0
    for slug in libs:
        work = f"{REPO}/libs/{slug}/work"
        p = f"{work}/adm/daemons/rankd.lpc"
        if slug in ("wllz3", "longyunmeng_binary") or os.path.exists(work + "/.git") or not os.path.exists(p):
            continue
        b = open(p, "rb").read()
        new, msgs = fix(b, slug)
        for m in msgs:
            if m.startswith("SKIP") or only:
                print(m)
        nf = sum(1 for m in msgs if m.startswith("FIX"))
        if nf:
            nlib += 1
            nfn += nf
            if apply:
                open(p, "wb").write(new)
    print(f"{nfn} function(s) in {nlib} lib(s)" + ("" if apply else " (plan only; --apply writes)"))


if __name__ == "__main__":
    main()
