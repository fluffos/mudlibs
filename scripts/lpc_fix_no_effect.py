#!/usr/bin/env python3
"""scripts/lpc_fix_no_effect.py [--apply] SLUG      (reads the scan scripts/lpc_warnings.py SLUG left behind)

`Expression has no side effects, and the value is unused` (KB 04 section 6.10): most of them are typos a human has to read
(`res == who;` was meant `res = who;`), but two shapes have exactly one meaning, and this fixes only those, in the files
the scan flagged (the line the driver reports is the *next* token's, so the shapes are looked for in the whole file):

  `for (times; times > 0; times--)`   an init clause that is a bare variable does nothing: `for (; times > 0; times--)`
  `"\\n";` on a line of its own right after a statement that ended with `;`, `{` or `}`: a string statement left behind after
                                       the `return "...";` it was meant to continue (xkx `look_lingwei()`): deleted

Without --apply it prints the plan.  Anything else the scan flags in the file stays on the list it prints at the end."""
import os
import re
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
args = sys.argv[1:]
apply_ = "--apply" in args
args = [a for a in args if a != "--apply"]
if len(args) != 1:
    sys.exit(__doc__)
slug = args[0]
work = f"{REPO}/libs/{slug}/work"
tsv = f"/tmp/lpcw-{slug}/diagnostics.tsv"
if not os.path.isfile(tsv):
    sys.exit(f"{tsv} missing: run scripts/lpc_warnings.py {slug} first")

flagged = {}
for line in open(tsv, errors="replace"):
    f = line.rstrip("\n").split("\t")
    if len(f) >= 5 and f[3] == "warning" and f[4].startswith("Expression has no side effects"):
        flagged.setdefault(f[0], []).append(int(f[1]))

FOR = re.compile(r"(\bfor\s*\(\s*)([A-Za-z_]\w*)(\s*;)")
STR = re.compile(r'^[ \t]*"(?:[^"\\\n]|\\.)*"[ \t]*;[ \t]*$')
done = left = 0
for path in sorted(flagged):
    full = work + path
    try:
        raw = open(full, "rb").read()
    except OSError:
        continue
    text = raw.decode("latin-1")
    eol = "\r\n" if "\r\n" in text else "\n"
    lines = text.split("\n")
    n0 = done
    for k, l in enumerate(lines):
        m = FOR.search(l)
        if m:
            lines[k] = l[:m.start()] + m.group(1) + m.group(3).lstrip() + l[m.end():]
            print(f"  {path}:{k + 1}: for ({m.group(2)}; ...) -> for (; ...)")
            done += 1
    k = 1
    while k < len(lines):
        if STR.match(lines[k].rstrip("\r")):
            j = k - 1
            while j >= 0 and not lines[j].strip():
                j -= 1
            prev = lines[j].rstrip("\r").rstrip() if j >= 0 else ""
            if prev.endswith((";", "{", "}")) and not prev.lstrip().startswith("//"):
                print(f"  {path}:{k + 1}: delete the string statement {lines[k].strip()[:30]!r} after `{prev.strip()[-30:]}`")
                del lines[k]
                done += 1
                continue
        k += 1
    if done == n0:
        left += len(flagged[path])
        print(f"  {path}: {len(flagged[path])} warning(s) at line(s) {sorted(set(flagged[path]))[:4]}: not one of the two shapes, read it")
    elif apply_:
        open(full, "wb").write("\n".join(lines).encode("latin-1"))
print(f"{done} edit(s) {'written' if apply_ else 'planned'}; {left} flagged warning(s) in files with no such shape")
