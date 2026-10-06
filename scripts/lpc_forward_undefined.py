#!/usr/bin/env python3
"""For `Undefined function f` errors where f is defined LATER in the same file (LDMud allowed calls
before the definition; FluffOS needs a declaration first), insert `varargs <header>;` prototypes in
front of the first function definition.  usage: scripts/lpc_forward_undefined.py SLUG [--apply] [--files REGEX]
Reads /tmp/lpcw-SLUG/diagnostics.tsv, or compiles each named file with lpcc when --compile FILE... is given."""
import os, re, sys, subprocess
REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
args = sys.argv[1:]
apply_ = "--apply" in args; args = [a for a in args if a != "--apply"]
slug = args[0]; work = f"{REPO}/libs/{slug}/work"
files = {}
if "--compile" in args:
    for f in args[args.index("--compile")+1:]:
        out = subprocess.run([os.path.expanduser("~/src/fluffos/build-debug/bin/lpcc"), "config.fluffos", f],
                             cwd=f"{REPO}/libs/{slug}", capture_output=True, text=True, errors="replace").stdout
        for m in re.finditer(r"^(\S+?):\d+:\d+: error: Undefined function (\w+)", out, re.M):
            if m.group(1) == f: files.setdefault(f, set()).add(m.group(2))
else:
    for line in open(f"/tmp/lpcw-{slug}/diagnostics.tsv", encoding="utf-8", errors="replace"):
        p = line.rstrip("\n").split("\t")
        if len(p) >= 5 and p[3] == "error":
            m = re.match(r"Undefined function (\w+)$", p[4])
            if m: files.setdefault(p[0], set()).add(m.group(1))
HEAD = r"^((?:(?:varargs|nomask|private|protected|public|static|nosave)\s+)*(?:(?:int|string|object|mapping|mixed|void|float|function|status|closure)\s*\**\s*)?)%s\s*\(([^)]*)\)\s*\{?"
total = 0
for f, names in sorted(files.items()):
    path = work + f
    if not os.path.isfile(path): continue
    raw = open(path, "rb").read(); txt = raw.decode("latin-1")
    nl = "\r\n" if "\r\n" in txt else "\n"
    protos = []
    for n in sorted(names):
        defs = list(re.finditer(HEAD % re.escape(n), txt, re.M))
        defs = [d for d in defs if not txt[d.end():d.end()+40].lstrip().startswith(";") and "{" in txt[d.start():d.end()+200].split(";")[0]]
        if len(defs) != 1: print(f"skip {f}: {n} ({len(defs)} definitions)"); continue
        mods = defs[0].group(1)
        if "varargs" not in mods: mods = "varargs " + mods
        mods = re.sub(r"\bstatic\b", "protected", mods)
        protos.append(f"{mods}{n}({defs[0].group(2).strip()});")
    if not protos: continue
    # first function definition in the file
    fd = re.search(r"^(?:(?:varargs|nomask|private|protected|public|static|nosave)\s+)*(?:(?:int|string|object|mapping|mixed|void|float|function|status)\s*\**\s*)?\w+\s*\([^;{)]*\)\s*\{?\s*$", txt, re.M)
    if not fd: print("skip", f, "no function found"); continue
    ins = "/* Called before their definitions (LDMud allowed that). */" + nl + nl.join(protos) + nl + nl
    total += len(protos)
    print(f"{f}: " + " ".join(protos))
    if apply_:
        mk = "/* Called before their definitions (LDMud allowed that). */" + nl
        if mk in txt:
            i = txt.index(mk) + len(mk)
            txt = txt[:i] + nl.join(protos) + nl + txt[i:]
        else:
            txt = txt[:fd.start()] + ins + txt[fd.start():]
        open(path, "wb").write(txt.encode("latin-1"))
print("prototypes", total)
