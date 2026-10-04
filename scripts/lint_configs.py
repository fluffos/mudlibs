#!/usr/bin/env python3
"""scripts/lint_configs.py [SLUG ...] [--lpcc PATH]

Print every message the driver gives while it reads a lib's `config.fluffos` (obsolete keys, values it resets to the
default, a second `external_port_1` for a port the `port number` line already defines).  Each one is a fix
(docs/kb/03-encoding-config.md section 5.1); a clean config prints nothing.

The driver only parses the file and stops: the copy of the config points `mudlib directory` at an empty scratch
directory, so no lib is booted (a boot in place rewrites tracked save files and drops stray files into work/).
Without SLUG every libs/*/config.fluffos is checked; an argument that is a file is linted as it is.  Exit status 1 when anything was printed."""
import glob
import os
import re
import subprocess
import sys
import tempfile

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
args = sys.argv[1:]
lpcc = os.path.expanduser("~/src/fluffos/build-debug/src/lpcc")
if "--lpcc" in args:
    i = args.index("--lpcc")
    lpcc = args[i + 1]
    del args[i:i + 2]
slugs = args or sorted(os.path.basename(os.path.dirname(p)) for p in glob.glob(f"{REPO}/libs/*/config.fluffos"))
scratch = tempfile.mkdtemp(prefix="lintcfg-")
os.makedirs(f"{scratch}/mud/log", exist_ok=True)
bad = 0
for slug in slugs:
    src = open(slug if os.path.isfile(slug) else f"{REPO}/libs/{slug}/config.fluffos", "rb").read()
    slug = os.path.basename(slug) if os.path.isfile(slug) else slug
    cfg = re.sub(rb"(?m)^(mudlib directory)\s*:.*$", b"\\1 : " + f"{scratch}/mud".encode(), src)
    path = f"{scratch}/{slug}.fluffos"
    open(path, "wb").write(cfg)
    try:
        out = subprocess.run([lpcc, path, "/nonexistent.lpc"], cwd=scratch, capture_output=True, timeout=30).stdout
    except subprocess.TimeoutExpired:
        print(f"{slug}\tlpcc timed out")
        bad += 1
        continue
    lines = out.decode("utf-8", "replace").splitlines()
    msgs = []
    for l in lines:
        if l.startswith("Execution root"):
            break
        if l.startswith(("Processing config", "New Debug log", "Unable to open log")) or not l.strip():
            continue
        msgs.append(l.strip())
    for m in msgs:
        print(f"{slug}\t{m}")
        bad += 1
sys.exit(1 if bad else 0)
