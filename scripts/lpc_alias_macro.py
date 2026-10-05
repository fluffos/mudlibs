#!/usr/bin/env python3
"""scripts/lpc_alias_macro.py [--apply] SLUG NAME TARGET

A macro that files use and no header defines (KB 04 section 6.2): the xkx perform files `inherit F_SSERVER;`, the Xiyou
libs that took them over define the same file as `SSERVER`, so 1932 of shenmo's skill files, `xianlvqiyuan`'s and 22 other
libs' imported ones stop at `syntax error, unexpected L_IDENTIFIER, expecting L_STRING or '('`.  This adds one line

    #define NAME TARGET            (TARGET = another macro of the lib, or a quoted path)

right after the line that defines TARGET (a macro) in the lib's include directories, or at the end of the global include
file when TARGET is a path.  It refuses when NAME is already defined somewhere under the lib's include directories or
when the lib has no file that uses NAME, and when TARGET is a macro defined on several lines it takes the first line of the
global include file (config.fluffos `global include file`).  Without --apply it prints the plan.  Line endings are kept."""
import os
import re
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
args = sys.argv[1:]
apply_ = "--apply" in args
args = [a for a in args if a != "--apply"]
if len(args) != 3:
    sys.exit(__doc__)
slug, name, target = args
root = f"{REPO}/libs/{slug}/work"
cfg = open(f"{REPO}/libs/{slug}/config.fluffos", errors="replace").read()
m = re.search(r"include directories\s*:\s*(.*)", cfg)
inc_dirs = [d.strip().strip("/") for d in m.group(1).split(":") if d.strip()] if m else ["include"]
g = re.search(r"global include file\s*:\s*[<\"]([^>\"\s]+)", cfg)
glob = g.group(1) if g else None

headers = []
for d in inc_dirs:
    for dp, dn, fn in os.walk(os.path.join(root, d)):
        for f in sorted(fn):
            if f.endswith(".h"):
                headers.append(os.path.join(dp, f))
DEF = lambda n: re.compile(rb"^[ \t]*#[ \t]*define[ \t]+" + re.escape(n.encode()) + rb"\b", re.M)
for h in headers:
    if DEF(name).search(open(h, "rb").read()):
        sys.exit(f"{slug}: {name} is already defined in {os.path.relpath(h, root)}")
if target.startswith('"'):
    cands = [h for h in headers if glob and h.endswith("/" + glob)] or headers[:1]
    host, after = (cands[0] if cands else None), None
else:
    hits = []
    for h in headers:
        b = open(h, "rb").read()
        mm = DEF(target).search(b)
        if mm:
            hits.append((h, mm))
    if not hits:
        sys.exit(f"{slug}: {target} is defined in no header of {inc_dirs}")
    hits.sort(key=lambda x: (not (glob and x[0].endswith("/" + glob)), x[0]))
    host, mm = hits[0]
    after = mm
if host is None:
    sys.exit(f"{slug}: no header to put the line in")
b = open(host, "rb").read()
eol = b"\r\n" if b"\r\n" in b else b"\n"
line = b"#define " + name.encode() + b" " + target.encode()
spelling = re.match(rb"[ \t]*#[ \t]*define([ \t]+)", (b[after.start():after.end() + 40] if after else b"#define "))
if after is not None:
    e = b.find(b"\n", after.end())
    e = len(b) if e < 0 else e + 1
    new = b[:e] + line + eol + b[e:] if b[:e].endswith(b"\n") else b[:e] + eol + line + eol
else:
    new = b + (b"" if b.endswith(b"\n") else eol) + line + eol
users = os.popen(f"grep -rlw {name} {root} --include='*.lpc' --include='*.h' 2>/dev/null | wc -l").read().strip()
print(f"{slug}: + `{line.decode()}` in {os.path.relpath(host, root)}; {users} file(s) name {name}")
if apply_:
    open(host, "wb").write(new)
