#!/usr/bin/env python3
"""scripts/lpc_apply_edits.py [--apply] EDITS.json SLUG...

The same hand edit in the same file of every lib of a family.  A family of siblings carries the same defects (a header that
declares a global the base already has, an unused local, a truncated string), and after the root is fixed by hand each sibling
needs the identical change: this applies a list of exact-text edits to every named lib and says, per edit, whether it applied,
was already there (`unless`), or did not match (a sibling whose copy differs is left for a human).

EDITS.json is a list of objects:
  {"file": "d/kaifeng/ground1.lpc",           path under libs/SLUG/work
   "old":  "  int step = this_room()->query(\\"match/step\\");\\n  object who",   exact text (LF; a CRLF file is matched with CRLF)
   "new":  "  object who",
   "count": 1,                                 optional, how many places (default 1)
   "unless": "text"}                           optional: when the file already contains this text the edit is `already there`
  or, in place of "old", {"regex": "(string \\\\*families = \\\\(\\\\{.*?\\\\}\\\\);)", "new": "#ifndef X\\n\\\\1\\n#endif"}: a Python
  regular expression (DOTALL; `\\r?\\n` for a line break that may be CRLF) and its replacement (\\1 is group 1; "\\n" in the
  replacement becomes CRLF in a CRLF file)

Edits are exact byte strings in UTF-8; the file keeps its line endings.  Without --apply it prints the plan."""
import json
import os
import re
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
args = sys.argv[1:]
apply_ = "--apply" in args
args = [a for a in args if a != "--apply"]
if len(args) < 2:
    sys.exit(__doc__)
edits = json.load(open(args[0], encoding="utf-8"))
slugs = args[1:]

total = {"applied": 0, "already": 0, "missing": 0, "nomatch": 0}
for slug in slugs:
    for e in edits:
        path = f"{REPO}/libs/{slug}/work/{e['file']}"
        if not os.path.isfile(path):
            print(f"{slug}: {e['file']}: no such file")
            total["missing"] += 1
            continue
        b = open(path, "rb").read()
        crlf = b"\r\n" in b
        want = e.get("count", 1)
        if e.get("unless") and e["unless"].encode("utf-8") in b:
            print(f"{slug}: {e['file']}: already there")
            total["already"] += 1
            continue
        if "regex" in e:
            text = b.decode("utf-8")
            pat = re.compile(e["regex"], re.S)
            repl = e["new"].replace("\n", "\r\n") if crlf else e["new"]
            n = len(pat.findall(text))
            if n == want:
                print(f"{slug}: {e['file']}: {'edited' if apply_ else 'would edit'} ({n} place{'s' if n != 1 else ''})")
                total["applied"] += 1
                if apply_:
                    open(path, "wb").write(pat.sub(lambda m: m.expand(repl), text).encode("utf-8"))
            else:
                print(f"{slug}: {e['file']}: {n} match(es), wanted {want}: left")
                total["nomatch"] += 1
            continue
        old, new = e["old"], e["new"]
        if crlf:
            old, new = old.replace("\n", "\r\n"), new.replace("\n", "\r\n")
        old_b, new_b = old.encode("utf-8"), new.encode("utf-8")
        n = b.count(old_b)
        if n == want:
            print(f"{slug}: {e['file']}: {'edited' if apply_ else 'would edit'} ({n} place{'s' if n != 1 else ''})")
            total["applied"] += 1
            if apply_:
                open(path, "wb").write(b.replace(old_b, new_b))
        else:
            print(f"{slug}: {e['file']}: {n} match(es), wanted {want}: left")
            total["nomatch"] += 1
print(total)
