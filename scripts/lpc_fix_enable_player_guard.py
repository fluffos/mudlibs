#!/usr/bin/env python3
"""scripts/lpc_fix_enable_player_guard.py [SLUG...] [--apply]

The reentrancy guard of KB 05 section 7.19 for `enable_player()` in `feature/command.lpc`: the sect NPCs of the Journey-to-the-West family end
`init()` with `me->setup();`, `setup()` calls `enable_player()`, `enable_commands()` runs `init()` again while the first is still on the stack and the
first visit dies with `Too deep recursion` (dtxyzjb `d/tianmo/door`: the gate guard walks in after the sect elder).  The guard is a flag, not
`living()`: sleep, revive and disable flows re-enable a living object on purpose.

    nosave private int in_enable_player_now;
    nomask void enable_player() {
      if (in_enable_player_now) return;
      in_enable_player_now = 1;
      ...
      in_enable_player_now = 0;
    }

Libs whose `enable_player()` already carries the flag (or a `living()` guard) are skipped.  A function with a `return` in the middle is listed and left.
Binary-safe, line endings kept; without --apply the plan is printed (FIX / SKIP lines); idempotent."""
import os
import re
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
HDR = re.compile(rb"nomask[ \t]+void[ \t]+enable_player[ \t]*\([ \t]*\)")


def match_brace(b, start):
    """index of the `}` that closes the `{` at b[start] (strings, char literals and comments skipped), or -1"""
    depth = 0
    i = start
    n = len(b)
    while i < n:
        c = b[i:i + 1]
        two = b[i:i + 2]
        if two == b"//":
            i = b.find(b"\n", i)
            if i < 0:
                return -1
        elif two == b"/*":
            i = b.find(b"*/", i + 2)
            if i < 0:
                return -1
            i += 1
        elif c == b'"':
            i += 1
            while i < n and b[i:i + 1] != b'"':
                i += 2 if b[i:i + 1] == b"\\" else 1
        elif c == b"'":
            i += 1
            while i < n and b[i:i + 1] != b"'":
                i += 2 if b[i:i + 1] == b"\\" else 1
        elif c == b"{":
            depth += 1
        elif c == b"}":
            depth -= 1
            if depth == 0:
                return i
        i += 1
    return -1


def fix(b):
    """-> (new bytes, reason) ; new is None when nothing is to be done"""
    m = HDR.search(b)
    if not m:
        return None, "no enable_player()"
    if b"in_enable_player_now" in b:
        return None, "already guarded"
    ob = b.find(b"{", m.end())
    if ob < 0:
        return None, "no body"
    cb = match_brace(b, ob)
    if cb < 0:
        return None, "unbalanced"
    body = b[ob + 1:cb]
    if re.search(rb"if\s*\(\s*living\s*\(\s*this_object\s*\(\s*\)\s*\)\s*\)\s*return", body):
        return None, "living() guard"
    if re.search(rb"\breturn\b", body):
        return None, "a return in the middle"
    eol = b"\r\n" if b"\r\n" in b else b"\n"
    first = re.search(rb"\n([ \t]+)\S", b[ob:cb])
    ind = first.group(1) if first else b"  "
    ls = b.rfind(b"\n", 0, m.start()) + 1                  # start of the header line
    line_end = b.find(b"\n", ob)
    # the flag test goes after the leading local declarations of the body (a declaration after a statement is refused)
    DECL = re.compile(rb"^[ \t]*(?:object|int|string|mixed|mapping|float|status|buffer|function|class[ \t]+\w+)\b[^;]*;[ \t]*(?://.*)?\r?$")
    while True:
        nxt = b.find(b"\n", line_end + 1)
        if nxt < 0 or nxt > cb:
            break
        ln = b[line_end + 1:nxt]
        if DECL.match(ln) or not ln.strip() or ln.strip().startswith(b"//"):
            line_end = nxt
        else:
            break
    pro = (ind + b"if (in_enable_player_now) return;" + eol + ind + b"in_enable_player_now = 1;" + eol)
    # the closing brace goes on its own line: put the reset before it
    cls = b.rfind(b"\n", 0, cb) + 1
    epi = ind + b"in_enable_player_now = 0;" + eol
    decl = (b"// KB 05 section 7.19: enable_commands() re-runs init(); a sect NPC whose init() calls setup() re-enters here until \"Too deep recursion\"." + eol
            + b"nosave private int in_enable_player_now;" + eol + eol)
    if b[cls:cb].strip():
        return None, "closing brace shares a line"
    out = b[:ls] + decl + b[ls:line_end + 1] + pro + b[line_end + 1:cls] + epi + b[cls:]
    return out, "ok"


def main():
    args = sys.argv[1:]
    apply = "--apply" in args
    only = [a for a in args if not a.startswith("--")]
    libs = only or sorted(os.listdir(f"{REPO}/libs"))
    nfix = 0
    for slug in libs:
        work = f"{REPO}/libs/{slug}/work"
        p = f"{work}/feature/command.lpc"
        if slug in ("wllz3", "longyunmeng_binary") or os.path.exists(work + "/.git") or not os.path.exists(p):
            continue
        b = open(p, "rb").read()
        new, why = fix(b)
        if new is None:
            if only:
                print(f"SKIP  {slug}: {why}")
            continue
        print(f"FIX   {slug} /feature/command.lpc: reentrancy flag around enable_player()")
        nfix += 1
        if apply:
            open(p, "wb").write(new)
    print(f"{nfix} lib(s)" + ("" if apply else " (plan only; --apply writes)"))


if __name__ == "__main__":
    main()
