#!/usr/bin/env python3
"""scripts/lpcc_real_fails.py LPCC_OUTPUT_FILE     -> the files `lpcc --batch` could not load, without the batch artifact

`lpcc --batch config.fluffos < list` prints `===== /path =====`, the diagnostics, then PASS or FAIL per file.  Once the
batch has loaded about a thousand rooms whose create() does `call_out(f, 0)` the driver answers `Nesting call_out(0)
level limit exceeded: 1000` for every later one: 743 of es1_win's 927 FAILs were that, each loads fine alone (KB 08
section 10.4).  This prints the other FAILs, one line each: `path:line: first error`, `path [in inherited]: first error`, or
`path: RUNTIME first runtime error`, and on stderr how many were PASS, real FAIL, artifact.

  cd /tmp/lpcw-SLUG/libs/SLUG && lpcc --batch config.fluffos < list > out 2>&1     (scripts/lpc_warnings.py SLUG leaves that
  tree behind; `find work -name '*.lpc'` makes the list)
  scripts/lpcc_real_fails.py out | sort"""
import re
import sys

if len(sys.argv) != 2:
    sys.exit(__doc__)
txt = open(sys.argv[1], errors="replace").read()
blocks = re.split(r"^===== (\S+) =====\n", txt, flags=re.M)
rows = []
for i in range(1, len(blocks), 2):
    path, body = blocks[i], blocks[i + 1]
    if not re.search(r"^FAIL ", body, flags=re.M) or "Nesting call_out(0)" in body:
        continue
    m = re.search(r"^(/\S+?):(\d+)(?::\d+)?: error: (.*)$", body, flags=re.M)
    if m:
        who = "" if m.group(1) == path else f" [in {m.group(1)}]"
        rows.append(f"{path}:{m.group(2)}{who}: {m.group(3)[:100]}")
    else:
        m2 = re.search(r"^[^\n]*(?:执行时段错误|Runtime error)[:：](.*)$", body, flags=re.M)
        first = m2.group(1) if m2 else body.strip().split("\n")[0]
        rows.append(f"{path}: RUNTIME {first[:100]}")
npass = len(re.findall(r"^PASS ", txt, flags=re.M))
artifact = len(re.findall(r"^FAIL ", txt, flags=re.M)) - len(rows)
print(f"# {npass} PASS, {len(rows)} real FAIL, {artifact} call_out(0) nesting artifact", file=sys.stderr)
print("\n".join(rows))
