#!/usr/bin/env python3
"""scripts/lpc_fix_no_effect.py [--apply] SLUG      (reads the scan scripts/lpc_warnings.py SLUG left behind)

`Expression has no side effects, and the value is unused` (KB 04 section 6.10): most of them are typos a human has to read
(`res == who;` was meant `res = who;`), but five shapes have exactly one meaning, and this fixes only those, in the files
the scan flagged (the line the driver reports is the *next* token's, so the shapes are looked for in the whole file):

  `for (times; times > 0; times--)`   an init clause that is a bare variable does nothing: `for (; times > 0; times--)`
  `"\\n";` on a line of its own right after a statement that ended with `;`, `{` or `}`: a string statement left behind after
                                       the `return "...";` it was meant to continue (xkx `look_lingwei()`): deleted
  `if (!(mud_svc[mud]["tell"] & SVC_KNOWN)) {` whose whole body is `#if PREF_TELL & SVC_TCP ... #endif` (the TMI-2
                                       `dns_master.lpc` query_services()): with the option off the `if` is empty and its test an
                                       expression with no effect; the `#if` / `#endif` pair moves outside the braces (same code)
  `for (n == 0; n < 4; n++)`           a comparison where the assignment was meant (the loop variable starts from whatever it
                                       held): `for (n = 0; ...)`
  `(: name :);`                        a function-pointer literal as a statement on its own line (xyj `practice_skill()`: the
                                       `throw_weapon` of the combat actions, never called from there): deleted

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
FOR_EQ = re.compile(r"(\bfor\s*\(\s*[A-Za-z_]\w*\s*)==(\s*-?\w+\s*;)")
STR = re.compile(r'^[ \t]*"(?:[^"\\\n]|\\.)*"[ \t]*;[ \t]*$')
FPTR = re.compile(r"^[ \t]*\(:[ \t]*[A-Za-z_]\w*[ \t]*:\)[ \t]*;[ \t]*$")
PREF_IF = re.compile(r"^#[ \t]*if[ \t]+PREF_\w+[ \t]*&[ \t]*SVC_\w+[ \t]*(//.*)?\r?$")
IF_KNOWN = re.compile(r"^[ \t]*if[ \t]*\(.*SVC_KNOWN.*\)[ \t]*\{?[ \t]*$")


def fix_pref_if(lines, path):
    """`if (... SVC_KNOWN) {` + `#if PREF_X & SVC_Y` ... `#endif` (no #elif / #else) + `}`: the `#if` pair goes outside"""
    n = 0
    k = 0
    while k < len(lines):
        if not PREF_IF.match(lines[k]):
            k += 1
            continue
        depth, e = 0, None
        for j in range(k, len(lines)):
            t = lines[j].lstrip()
            if t.startswith("#"):
                d = t[1:].lstrip()
                if d.startswith(("if", "ifdef", "ifndef")):
                    depth += 1
                elif d.startswith(("elif", "else")) and depth == 1:
                    break
                elif d.startswith("endif"):
                    depth -= 1
                    if depth == 0:
                        e = j
                        break
        if e is None:
            k += 1
            continue
        h = k - 1
        while h >= 0 and not lines[h].strip():
            h -= 1
        if h >= 0 and lines[h].strip() == "{":
            h -= 1
        c = e + 1
        while c < len(lines) and not lines[c].strip():
            c += 1
        if h < 0 or c >= len(lines) or lines[c].strip() != "}" or not IF_KNOWN.match(lines[h].rstrip("\r")) \
                or not any("{" in l for l in lines[h:k]):
            k += 1
            continue
        new = [lines[k]] + lines[h:k] + lines[k + 1:e] + lines[e + 1:c + 1] + [lines[e]]
        print(f"  {path}:{k + 1}: `{lines[k].strip()}` moved outside `{lines[h].strip()[:50]}`")
        lines[h:c + 1] = new
        n += 1
        k = c + 1
    return n


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
        m = FOR_EQ.search(l)
        if m:
            lines[k] = l[:m.start()] + m.group(1) + "=" + m.group(2) + l[m.end():]
            print(f"  {path}:{k + 1}: `{m.group(0).strip()}` -> `=`")
            done += 1
            continue
        m = FOR.search(l)
        if m:
            lines[k] = l[:m.start()] + m.group(1) + m.group(3).lstrip() + l[m.end():]
            print(f"  {path}:{k + 1}: for ({m.group(2)}; ...) -> for (; ...)")
            done += 1
    done += fix_pref_if(lines, path)
    k = 0
    while k < len(lines):
        if FPTR.match(lines[k].rstrip("\r")):
            print(f"  {path}:{k + 1}: delete the function-pointer statement {lines[k].strip()}")
            del lines[k]
            done += 1
            continue
        k += 1
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
        print(f"  {path}: {len(flagged[path])} warning(s) at line(s) {sorted(set(flagged[path]))[:4]}: not one of the five shapes, read it")
    elif apply_:
        open(full, "wb").write("\n".join(lines).encode("latin-1"))
print(f"{done} edit(s) {'written' if apply_ else 'planned'}; {left} flagged warning(s) in files with no such shape")
