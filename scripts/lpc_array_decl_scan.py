#!/usr/bin/env python3
"""Find `T array a, b` declarations in raw/ whose work/ counterpart became `T * a, b`
(only the first declarator starred).  In MudOS `array` belongs to the type, so every
declarator was an array; `*` belongs to one declarator (KB 04 §6.x)."""
import os, re, sys
DECL = re.compile(r"^([ \t]*(?:(?:private|nosave|static|public|protected|nomask)\s+)*)(\w+)\s+array\s+([^;(){}]*?);", re.M)
def strip_comments(s):
    return re.sub(r"//[^\n]*", "", s)
root = "libs"
slugs = sys.argv[1:] or sorted(os.listdir(root))
total = 0
for slug in slugs:
    raw = os.path.join(root, slug, "raw"); work = os.path.join(root, slug, "work")
    if not (os.path.isdir(raw) and os.path.isdir(work)): continue
    # index work files by relative path without extension (raw layout may have a top dir)
    wfiles = {}
    for dp, dn, fn in os.walk(work):
        for f in fn:
            if f.endswith((".lpc", ".h")):
                rel = os.path.relpath(os.path.join(dp, f), work)
                wfiles[os.path.splitext(rel)[0] if f.endswith(".lpc") else rel] = os.path.join(dp, f)
    for dp, dn, fn in os.walk(raw):
        for f in fn:
            if not f.endswith((".c", ".h")): continue
            rp = os.path.join(dp, f)
            try: txt = strip_comments(open(rp, "rb").read().decode("latin1"))
            except OSError: continue
            for m in DECL.finditer(txt):
                decls = [d.strip() for d in m.group(3).split(",")]
                names = [re.match(r"\w+", d).group(0) for d in decls if re.match(r"\w+", d)]
                if len(names) < 2: continue
                rel = os.path.relpath(rp, raw)
                key = os.path.splitext(rel)[0] if f.endswith(".c") else rel
                # raw may have one or two extra leading dirs
                cands = [k for k in wfiles if key.endswith(k) and (key == k or key[-len(k)-1] == "/")]
                if not cands: continue
                wp = wfiles[max(cands, key=len)]
                w = open(wp, "rb").read().decode("latin1")
                for n in names[1:]:
                    # declared in work as a plain (unstarred) later declarator of a starred line?
                    pat = re.compile(r"^[ \t]*(?:(?:private|nosave|static|public|protected|nomask)\s+)*" + re.escape(m.group(2)) +
                                     r"\s*\*\s*\w+[^;\n]*,\s*" + re.escape(n) + r"\b(?!\s*\()", re.M)
                    for wm in pat.finditer(w):
                        line = w[:wm.start()].count("\n") + 1
                        seg = wm.group(0)
                        # make sure n itself is not starred
                        if re.search(r"\*\s*" + re.escape(n) + r"\b", seg): continue
                        total += 1
                        print(f"{wp}:{line}: {n}  <- raw {rp}: {m.group(0).strip()[:80]}")
print("total", total, file=sys.stderr)
