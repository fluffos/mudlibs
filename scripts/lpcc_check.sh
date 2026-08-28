#!/usr/bin/env bash
# Compile-check every .lpc/.c file in a mudlib's work/ dir with lpcc's
# --batch mode: ONE VM boot (master + simul_efun loaded once), then every
# file compiled in that same process -- not a fresh boot per file. This
# mirrors how a real driver boot compiles many objects with no state reset
# between them, so it's a more realistic test AND ~15-70x faster than
# spawning one lpcc process per file.
#
# Usage: lpcc_check.sh libs/<slug>/config.fluffos libs/<slug>/work [pattern]
set -uo pipefail

LPCC="${LPCC:-$HOME/src/fluffos/build-debug/src/lpcc}"
CONFIG="$1"
WORK="$2"

if [[ ! -x "$LPCC" ]]; then
  echo "lpcc not found/executable at $LPCC -- build it first (make -C ~/src/fluffos/build-debug lpcc)" >&2
  exit 1
fi
if [[ ! -f "$CONFIG" ]]; then
  echo "config file not found: $CONFIG" >&2
  exit 1
fi

FAILLOG="$(dirname "$WORK")/lpcc_fail.log"
RAWLOG="$(dirname "$WORK")/lpcc_batch_raw.log"

# Object paths relative to mudlib root, leading slash, extension-less (so
# resolution prefers .lpc -- matches what the driver itself would load).
find "$WORK" -type f \( -name "*.lpc" -o -name "*.c" \) \
  | sed -e "s#^$WORK##" -e 's/\.lpc$//' -e 's/\.c$//' -e 's#^[^/]#/&#' \
  | "$LPCC" --batch "$CONFIG" > "$RAWLOG" 2>&1

python3 - "$RAWLOG" "$FAILLOG" <<'PYEOF'
import re, sys
raw_path, fail_path = sys.argv[1], sys.argv[2]
text = open(raw_path, encoding="utf-8", errors="replace").read()
blocks = re.split(r"^===== (.+?) =====$", text, flags=re.M)[1:]
pass_n = fail_n = 0
with open(fail_path, "w", encoding="utf-8") as fail_out:
    for i in range(0, len(blocks), 2):
        name, body = blocks[i], blocks[i + 1]
        ok = re.search(r"^PASS " + re.escape(name) + r"$", body, re.M)
        if ok:
            pass_n += 1
            print(f"PASS {name}")
        else:
            fail_n += 1
            print(f"FAIL {name}")
            fail_out.write(f"===== {name} =====\n{body.strip()}\n\n")
print("----")
print(f"total={pass_n+fail_n} pass={pass_n} fail={fail_n}")
print(f"failures logged to {fail_path}")
PYEOF
