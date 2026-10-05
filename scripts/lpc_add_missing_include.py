#!/usr/bin/env python3
"""scripts/lpc_add_missing_include.py [--apply] [--skip REGEX ...] SLUG      (reads the scan scripts/lpc_warnings.py SLUG left behind)

A file that names a macro and never includes the header that defines it dies with one of two errors:
  `inherit MONSTER;`           -> syntax error, unexpected L_IDENTIFIER, expecting L_STRING or '('
  `file + SAVE_EXTENSION`      -> Undefined variable 'SAVE_EXTENSION'
(an `#include <mudlib.h>` the archive lost, or one the author never wrote because an older driver pulled it in).
For every such error whose offending name is an ALL-CAPS identifier defined by exactly one header of the lib's include
directories (or, when several define it, by `mudlib.h`), this adds `#include <header>` after the file's leading
#include lines (at the top when it has none), keeping the file's line endings.  Without --apply it only prints the plan; --skip leaves the paths it matches alone
(a file the scan lists for an earlier edit of yours, a dead directory).
Not touched, listed instead: a name that no header defines, a name several headers define (none of them mudlib.h), a
file that already includes the header (something else is wrong), a name used only after the file's first `inherit`
being undefined for another reason.  Re-run the scan afterwards: a header can bring macros that clash with the file's own.

Reads /tmp/lpcw-SLUG/diagnostics.tsv (path, line, col, severity, message) and the lib's config.fluffos include path."""
import os
import re
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
args = sys.argv[1:]
apply_ = "--apply" in args
args = [a for a in args if a != "--apply"]
skips = []
while "--skip" in args:
    i = args.index("--skip")
    skips.append(re.compile(args[i + 1]))
    del args[i:i + 2]
if len(args) != 1:
    sys.exit(__doc__)
slug = args[0]
work = f"{REPO}/libs/{slug}/work"
tsv = f"/tmp/lpcw-{slug}/diagnostics.tsv"
if not os.path.isfile(tsv):
    sys.exit(f"{tsv} missing: run scripts/lpc_warnings.py {slug} first")

# include directories of the lib
inc_dirs = []
for line in open(f"{REPO}/libs/{slug}/config.fluffos", errors="replace"):
    m = re.match(r"include directories\s*:\s*(.*)", line)
    if m:
        inc_dirs = [d.strip().strip("/") for d in m.group(1).split(":") if d.strip()]
if not inc_dirs:
    sys.exit("no include directories in config.fluffos")

DEFINE = re.compile(rb"^[ \t]*#[ \t]*define[ \t]+([A-Z][A-Z0-9_]*)\b", re.M)
defs = {}  # NAME -> [header spelled for #include <...>]
for d in inc_dirs:
    root = os.path.join(work, d)
    for dp, dn, fn in os.walk(root):
        for f in fn:
            if not f.endswith(".h"):
                continue
            p = os.path.join(dp, f)
            rel = os.path.relpath(p, root)
            try:
                b = open(p, "rb").read()
            except OSError:
                continue
            for m in DEFINE.finditer(re.sub(rb"/\*.*?\*/", b"", b, flags=re.S)):
                defs.setdefault(m.group(1).decode(), set()).add(rel)

todo = {}  # path -> {name}
for line in open(tsv, errors="replace"):
    f = line.rstrip("\n").split("\t")
    if len(f) < 5 or f[3] != "error":
        continue
    path, ln, col, msg = f[0], int(f[1]), int(f[2]), f[4]
    name = None
    m = re.match(r"Undefined variable '([A-Z][A-Z0-9_]*)'", msg)
    if m:
        name = m.group(1)
    elif msg.startswith("syntax error, unexpected L_IDENTIFIER, expecting L_STRING or '('"):
        try:
            src = open(work + path, "rb").read().decode("latin-1").split("\n")[ln - 1]
        except OSError:
            continue
        m = re.match(r"\s*inherit\s+([A-Z][A-Z0-9_]*)\s*;", src)
        if m:
            name = m.group(1)
    if name:
        todo.setdefault(path, set()).add(name)

planned = skipped = 0
for path in sorted(todo):
    if any(s.search(path) for s in skips):
        continue
    full = work + path
    try:
        b = open(full, "rb").read()
    except OSError:
        continue
    text = b.decode("latin-1")
    add = []
    for name in sorted(todo[path]):
        hs = defs.get(name, set())
        if not hs:
            print(f"  skip {path}: {name} is defined by no header")
            skipped += 1
            continue
        if len(hs) > 1:
            if "mudlib.h" in hs:
                hs = {"mudlib.h"}
            else:
                print(f"  skip {path}: {name} is defined by {sorted(hs)}")
                skipped += 1
                continue
        h = next(iter(hs))
        if re.search(r"#[ \t]*include[ \t]*<%s>" % re.escape(h), text) or h in add:
            if h not in add:
                print(f"  skip {path}: already includes <{h}>")
                skipped += 1
            continue
        add.append(h)
    if not add:
        continue
    eol = "\r\n" if "\r\n" in text else "\n"
    lines = text.split("\n")
    # insert after the last #include of the leading block (first 60 lines), else at the top
    last = -1
    for i, l in enumerate(lines[:60]):
        if re.match(r"\s*#[ \t]*include\b", l):
            last = i
    new = [f"#include <{h}>" + ("\r" if eol == "\r\n" else "") for h in add]
    lines[last + 1:last + 1] = new
    planned += 1
    print(f"  {path}: + {', '.join('<' + h + '>' for h in add)} (after line {last + 1})")
    if apply_:
        open(full, "wb").write("\n".join(lines).encode("latin-1"))
print(f"{planned} file(s) {'patched' if apply_ else 'to patch'}, {skipped} skipped")
