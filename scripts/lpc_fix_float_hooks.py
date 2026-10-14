#!/usr/bin/env python3
"""scripts/lpc_fix_float_hooks.py SLUG [--apply] [--diag TSV]
`int NAME(args) { ... return 1.75; ... }` -- an int function whose every return is a numeric literal and at least one is a
float -- flagged by `Float value truncated to int` inside it, becomes `float NAME`.  Typical: skill hooks
`power_point()`/`hard_point()` (one line, or branches on gender or a skill level).  Functions with any other return are
listed as READ.  Then the callers of each renamed function are listed: a caller that stores the value in an int and does
arithmetic gets a float at runtime (call_other results are not coerced) -- give it a float receiver and to_int() the
product (KB 04 §6.10).  Diagnostics: $LPC_SCRATCH/lpcw-SLUG/diagnostics.tsv (scripts/lpc_warnings.py) unless --diag."""
import os, re, subprocess, sys
REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SCRATCH = os.environ.get("LPC_SCRATCH") or os.path.expanduser("~/.cache/lpc-scratch")
args = [a for a in sys.argv[1:] if not a.startswith("--")]
slug = args[0]
apply = "--apply" in sys.argv
diag = sys.argv[sys.argv.index("--diag") + 1] if "--diag" in sys.argv else f"{SCRATCH}/lpcw-{slug}/diagnostics.tsv"
if "--diag" in sys.argv:
    args = [a for a in args if a != diag]
work = os.path.join(REPO, "libs", slug, "work")
sites = {}
for line in open(diag, encoding="utf-8", errors="replace"):
    r = line.rstrip("\n").split("\t")
    if len(r) >= 5 and r[3] == "warning" and r[4].startswith("Float value truncated"):
        sites.setdefault(r[0], set()).add(int(r[1]))
names, total = {}, 0
for f, lines in sorted(sites.items()):
    path = os.path.join(work, f.lstrip("/"))
    if not os.path.isfile(path):
        continue
    txt = open(path, "rb").read().decode("utf-8", "surrogateescape")
    edits = []
    for m in re.finditer(r"(?m)^int(\s+(\w+)\s*\([^()]*\)\s*\{)", txt):
        i = m.end() - 1
        depth, j = 0, i
        while j < len(txt):
            if txt[j] == "{":
                depth += 1
            elif txt[j] == "}":
                depth -= 1
                if depth == 0:
                    break
            j += 1
        l0, l1 = txt.count("\n", 0, m.start()) + 1, txt.count("\n", 0, j) + 1
        if not any(l0 <= x <= l1 for x in lines):
            continue
        rets = re.findall(r"\breturn\s+([^;]*);", txt[i:j])
        if any(re.fullmatch(r"\s*-?[0-9]*\.[0-9]+\s*", r) for r in rets) and all(re.fullmatch(r"\s*-?[0-9.]+\s*", r) for r in rets):
            edits.append(m.start())
            names[m.group(2)] = names.get(m.group(2), 0) + 1
            print(f"FIX  {f}:{l0}: int {m.group(2)}() -> float")
        else:
            print(f"READ {f}:{l0}: {m.group(2)}() returns {[r.strip() for r in rets][:4]}")
    if edits and apply:
        for e in sorted(edits, reverse=True):
            txt = txt[:e] + "float" + txt[e + 3:]
        open(path, "wb").write(txt.encode("utf-8", "surrogateescape"))
    total += len(edits)
print(f"{total} function(s) {'changed' if apply else 'to change (plan only; --apply writes)'}")
for n in names:
    out = subprocess.run(["git", "grep", "-nE", r"(->|call_other\([^;]*\")" + n + r"\b", "--", "*.lpc", "*.h"],
                         cwd=work, capture_output=True, text=True).stdout.splitlines()
    print(f"callers of {n}(): {len(out)}" + ("" if not out else " -- check each receiver (KB 04 §6.10)"))
    for x in out[:10]:
        print("   ", x[:150])
