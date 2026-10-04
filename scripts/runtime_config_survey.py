#!/usr/bin/env python3
"""scripts/runtime_config_survey.py [--json]

Which libs ship a `include/runtime_config.h` whose numbering is not the driver's (KB 06 section 7.89), and what do they
call?  The driver's integer settings start at 256 (`RC_BASE_CONFIG_INT = RC_LAST_CONFIG_STR + 1`); the MudOS-era
header starts them at 15, so `get_config(__MUD_PORT__)` answers a string and `get_config(__ADDR_SERVER_IP__)` /
`get_config(__SAVE_BINARIES_DIR__)` raise `Bad argument to get_config()`.  Prints, per stale lib, the integer settings
it reads, the symbols the driver's header no longer defines, and the call-site count.  The canonical header is
$FLUFFOS_SRC/src/include/runtime_config.h (default ~/src/fluffos)."""
import collections
import glob
import json
import os
import re
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
CANON = os.path.join(os.environ.get("FLUFFOS_SRC", os.path.expanduser("~/src/fluffos")), "src/include/runtime_config.h")
canon_defs = set(re.findall(r"#\s*define\s+(__\w+__)", open(CANON).read()))
res = {}
for h in sorted(glob.glob(f"{REPO}/libs/*/work/include/runtime_config.h")):
    lib = h.split("/")[-4]
    s = open(h, "rb").read().decode("latin-1")
    m = re.search(r"#\s*define\s+(?:RC_)?BASE_CONFIG_INT\s*\(([^)]*)\)", s)
    base = m.group(1).strip() if m else None
    stale = bool(base) and "255" not in base and "LAST_CONFIG" not in base
    defs = {mm.group(1): mm.group(2) for mm in re.finditer(r"#\s*define\s+(__\w+__)\s+CFG_(STR|INT)\(", s)}
    out = subprocess.run(["grep", "-rIohE", r"get_config *\( *[A-Za-z_0-9 +()]*\)", f"{REPO}/libs/{lib}/work",
                          "--include=*.lpc", "--include=*.h", "--include=*.c"], capture_output=True, text=True).stdout
    calls = collections.Counter(mm.group(1) for c in out.split("\n") for mm in [re.search(r"\(\s*(__\w+__)\s*\)", c)] if mm)
    res[lib] = dict(stale=stale, base=base,
                    ints={k: v for k, v in calls.items() if defs.get(k) == "INT"},
                    missing=sorted(k for k in calls if k not in canon_defs))
if "--json" in sys.argv:
    json.dump(res, sys.stdout, indent=1)
    sys.exit(0)
stale = [l for l, r in res.items() if r["stale"]]
print(f"{len(stale)} of {len(res)} libs ship a stale header; canonical: {', '.join(l for l, r in res.items() if not r['stale'])}")
for l in stale:
    r = res[l]
    print(f"{l:22s} base={r['base']:24s} int settings read: {sum(r['ints'].values()):3d}  not in the driver's header: {', '.join(r['missing']) or '-'}")
