#!/usr/bin/env python3
"""scripts/lpc_fix_vision_env.py SLUG... [--apply]

`message_vision(msg, environment(me), me)`: the room passed as the actor and the player as the target, the argument
order of `message("vision", msg, environment(me), me)` (KB 06 section 7.242).  message_vision() calls `name()` on its
first object; a room has none, so `replace_string(msg, "$N", 0)` errors.  Mostly in poison conditions (sanpoison,
emerald_poison, xianglu-du, laugh), which then error on every heart beat before they count down, so the victim stops
healing until the condition is cleared by hand.  `$N` in the message means the player: rewritten to
`message_vision(msg, me)`.  Code only (not strings or comments).  Binary-safe.  Without --apply the plan is printed."""
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from lpc_fix_void_return import code_mask  # noqa: E402

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SKIP = re.compile(r"/(u|w|players|backup|old|bak|log|data|doc)/")
PAT = re.compile(rb"(message_vision\s*\((?:[^;]*?)),\s*environment\s*\(\s*([a-z_]+)\s*\)\s*,\s*\2\s*\)\s*;")


def fix(b):
    ms = list(PAT.finditer(b))
    if not ms:
        return b, 0
    mask = code_mask(b)
    out, last, n = [], 0, 0
    for m in ms:
        if not mask[m.start()]:
            continue
        out.append(b[last:m.start()])
        out.append(m.group(1) + b", " + m.group(2) + b");")
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
        if os.path.exists(f"{work}/.git"):
            continue
        for dp, dn, fn in os.walk(work):
            if SKIP.search(dp[len(work):] + "/"):
                continue
            for f in fn:
                if not f.endswith(".lpc"):
                    continue
                p = os.path.join(dp, f)
                b = open(p, "rb").read()
                if b"message_vision" not in b:
                    continue
                out, n = fix(b)
                if n:
                    tot += n
                    print(f"FIX   {slug} {p[len(work):]}  {n}")
                    if apply:
                        open(p, "wb").write(out)
    print(f"{tot} call(s)" + ("" if apply else " (plan only; --apply writes)"))


if __name__ == "__main__":
    main()
