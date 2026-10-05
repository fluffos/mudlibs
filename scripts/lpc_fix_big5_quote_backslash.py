#!/usr/bin/env python3
"""scripts/lpc_fix_big5_quote_backslash.py [--apply] SLUG...      (or --all: every vendored lib)

KB 03 section 4.4: a BIG5 character whose second byte is 0x5C (`功` A5 5C, `許`, `豹` C0 5C, `餐` C0 5C ...) was written by
the authors with one extra backslash after it, because the old driver read `5C 5C` as one backslash and so completed the
character.  The UTF-8 conversion keeps that extra `\\`.  Mid-string it is only the warning `Unknown escape sequence`
(scripts/lpc_warnings.py --fix deletes it before a multi-byte character).  Right before a closing quote it escapes the
quote, the string runs on, and the whole file fails to compile:

    "force":  "内功\\",          set_name("豹\\", ({ "leopard" }))          if (temp == "功\\") ...

Found by the corpus scan of 2026-10-04 (39 sites, 10 libs: `cmds/std/enable.lpc` of yxsj, yxzsj, kxkj1, dfgs2 -- the
`enable` command never loaded --, NPC `set_name` lines, a skill book).
This deletes the backslash when (a) the character before it encodes to two bytes in cp950 with 0x5C as the second one,
(b) a `"` follows, and (c) the next thing after that quote ends an expression (`,` `)` `;` `}` `]` `+` or the line's end),
so a deliberately escaped quote inside a longer string is left alone.  Without --apply it only lists the files.
Libs whose work/ is a gitlink (deadsouls_fluffos, fy2005, imud, lima, nightmare3, nt7, oxidus, residuum, sanguozhi,
xkx100utf8) are refused: run on a copy of upstream and send a PR (KB 02 section 2.3).  Not handled: `功\\\\"` (two
backslashes; yxsj `bullets.lpc` -- read those by hand)."""
import os
import re
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
args = sys.argv[1:]
apply_ = "--apply" in args
args = [a for a in args if a != "--apply"]
if not args:
    sys.exit(__doc__)


def gitlink(slug):
    out = subprocess.run(["git", "-C", REPO, "ls-files", "-s", "--", f"libs/{slug}/work"], capture_output=True, text=True).stdout
    return any(l.startswith("160000") for l in out.split("\n"))


slugs = sorted(s for s in os.listdir(f"{REPO}/libs") if os.path.isdir(f"{REPO}/libs/{s}/work")) if args == ["--all"] else args
RE = re.compile(r'([\u0080-\uffff])\\(?=")')
AFTER = re.compile(r'"[ \t]*(?:[,);}\]+]|\r?$)', re.M)
cache = {}


def trail_5c(ch):
    r = cache.get(ch)
    if r is None:
        try:
            e = ch.encode("cp950")
            r = len(e) == 2 and e[1] == 0x5C
        except UnicodeEncodeError:
            r = False
        cache[ch] = r
    return r


total = 0
for slug in slugs:
    if gitlink(slug):
        print(f"{slug}: work/ is a gitlink, not edited in place")
        continue
    root = f"{REPO}/libs/{slug}/work"
    files = sites = 0
    for dp, dn, fn in os.walk(root):
        for f in sorted(fn):
            if not f.endswith((".lpc", ".h", ".c")):
                continue
            p = os.path.join(dp, f)
            try:
                raw = open(p, "rb").read()
                text = raw.decode("utf-8")
            except (OSError, UnicodeDecodeError):
                continue
            if "\\" not in text:
                continue
            out, last, hits = [], 0, 0
            for m in RE.finditer(text):
                if trail_5c(m.group(1)) and AFTER.match(text, m.end()):
                    out.append(text[last:m.end() - 1])
                    last = m.end()
                    hits += 1
            if hits:
                files += 1
                sites += hits
                if apply_:
                    out.append(text[last:])
                    open(p, "wb").write("".join(out).encode("utf-8"))
                else:
                    print(f"  {slug}/{os.path.relpath(p, root)}: {hits}")
    total += sites
    if sites:
        print(f"{slug}: {sites} site(s) in {files} file(s) {'fixed' if apply_ else 'to fix'}")
print(f"{total} site(s)")
