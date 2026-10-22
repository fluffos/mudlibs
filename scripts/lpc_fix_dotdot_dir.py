#!/usr/bin/env python3
"""scripts/lpc_fix_dotdot_dir.py [--apply] [--direct] SLUG [FILE...]

`new(__DIR__ "../obj/yaochu")`, `carry_object(__DIR__"../obj/x")`, `load_object(..)`, `->move(__DIR__"../room")`: `__DIR__` is the directory of the file with a trailing slash, so
the argument is `/d/zhiye/npc/../obj/yaochu`. (`--direct`: only where the efun itself gets the path as its first argument -- `new(`, `clone_object(`, `load_object(`, `find_object(`, `unew(`, `move(` -- which every lib refuses; a `carry_object()` or a room's `objects` table passes the path through the lib's own code, which may normalize it.)  The driver refuses a path with a `..` component (`legal_path()`: "No '..' are allowed"): `new()` / `load_object()` raise
`*Read access denied.`, and the object that called it never finishes `create()`: the 6 profession NPCs of dtsl / dtsl2 / dtslmud (miner, herb picker, weaver, silk-worm
woman, ...) cannot be cloned.  A lib whose master's `valid_read()` hands back a normalized path string, or whose room / NPC base normalizes before it calls `new()` (bxsj,
dreamofseven), loads the same paths without complaint: look at the lib first (`dotdot_load` style eval: `catch(new(path))`), do not change one that works.

The fix is the normalized absolute path as one string literal: `__DIR__ "../obj/yaochu"` in `/d/zhiye/npc/x.lpc` becomes `"/d/zhiye/obj/yaochu"`.  Only a `__DIR__` that is followed
(after blanks) by a string literal that starts with `../` is touched, in code (comments and strings are masked), outside `#include` lines; a path that would leave the mudlib root is
printed and left.  Without FILE arguments every tracked `.lpc` of the lib that holds such a use is taken; wizard, backup and data directories are skipped.  Binary mode, the file's own line
endings, idempotent.  Dry run by default."""
import os
import re
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from lpc_fix_void_return import code_mask  # noqa: E402

SKIP = re.compile(r"/(u|w|wiz|wizard|wizards|backup|backups|bak|old|test|tests|tmp|data|log)/|[-_.](bak|old)")
USE = re.compile(rb'__DIR__[ \t]*"((?:\.\./)+[^"\n]*)"')


DIRECT = re.compile(rb"\b(?:new|clone_object|load_object|find_object|unew|move|move_player)\s*\(\s*$")        # the efun gets the path as its first argument: refused in every lib


def fix(b, rel, direct=False, root=None):
    """returns (new bytes, [(old, new)]) for the file at lib-relative path `rel` (`/d/zhiye/npc/x.lpc`); direct: only a `__DIR__ "../x"` that is the first argument of new() / clone_object() /
    load_object() / find_object() / unew() / move()"""
    mask = code_mask(b, heredoc=True)
    d = os.path.dirname(rel) + "/"
    out, pos, changes = [], 0, []
    for m in USE.finditer(b):
        if not mask[m.start()]:                                                         # in a comment or a string
            continue
        ls = b.rfind(b"\n", 0, m.start()) + 1
        if re.match(rb"[ \t]*#[ \t]*include", b[ls:m.start()]):                          # an include resolves `..` itself
            continue
        if direct and not DIRECT.search(b[ls:m.start()]):
            continue
        full = os.path.normpath(d + m.group(1).decode("utf-8", "replace"))
        if full.startswith("..") or not full.startswith("/"):
            print(f"LEAVES {rel}: {m.group(0).decode('utf-8', 'replace')} -> {full}")
            continue
        new = b'"' + full.encode("utf-8") + b'"'
        if root and not any(os.path.exists(root + full + ext) for ext in ("", ".lpc", ".c", ".h")):
            print(f"MISSING {rel}: {full} (the target file is not in the lib; rewritten all the same)")
        out.append(b[pos:m.start()])
        out.append(new)
        pos = m.end()
        changes.append((m.group(0).decode("utf-8", "replace"), new.decode("utf-8", "replace")))
    out.append(b[pos:])
    return b"".join(out), changes


def main():
    argv = sys.argv[1:]
    apply = "--apply" in argv
    direct = "--direct" in argv
    args = [a for a in argv if not a.startswith("--")]
    if not args:
        sys.exit(__doc__)
    slug, files = args[0], args[1:]
    root = f"libs/{slug}/work"
    if not files:
        out = subprocess.run(["git", "grep", "-l", "-E", r'__DIR__[ \t]*"\.\./', "--", root], cwd=REPO, capture_output=True, text=True).stdout.split()
        files = [f for f in out if f.endswith(".lpc") and not SKIP.search(f[len(root):])]
    total = 0
    for f in sorted(files):
        p = f if os.path.isabs(f) else os.path.join(REPO, f)
        rel = os.path.relpath(p, os.path.join(REPO, root))
        rel = "/" + rel.replace(os.sep, "/")
        b = open(p, "rb").read()
        nb, ch = fix(b, rel, direct, os.path.join(REPO, root))
        if not ch:
            continue
        total += len(ch)
        print(f"{'FIX' if apply else 'would fix'} {rel}: " + ", ".join(f"{o} -> {n}" for o, n in ch[:3]) + (f" (+{len(ch) - 3})" if len(ch) > 3 else ""))
        if apply:
            open(p, "wb").write(nb)
    print(f"{total} use(s) {'rewritten' if apply else 'to rewrite'}", file=sys.stderr)


if __name__ == "__main__":
    main()
