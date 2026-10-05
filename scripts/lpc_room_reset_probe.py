#!/usr/bin/env python3
"""scripts/lpc_room_reset_probe.py SLUG...      (checks scripts/lpc_resilient_room.py and scripts/lpc_room_reset_guard.py)

Does the room base of SLUG survive a room that lists an object file the archive never shipped?  The probe loads the room
base (std/room.lpc, inherit/room/room.lpc ...) as an object, gives it `objects = ([ "/zz/none/a": 1 ])` (the `case 1:` of reset())
and, in a second run, `([ "/zz/none/b": 2 ])` (the `default:` branch), calls `reset()` under `catch()` and prints OK or the error.
Two runs per lib in one pristine tree of HEAD: the committed room base first, then the working tree's copy of it.  Prints
`slug: base: HEAD case1=OK|ERR default=OK|ERR -> tree case1=... default=...`.  Needs the debug driver
(~/src/fluffos/build-debug/src/lpcc); a lib whose room base is not a loadable object prints `no probe`."""
import os
import shutil
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
CANDIDATES = ("std/room.lpc", "inherit/room/room.lpc", "inherit/room.lpc", "std/room/room.lpc", "obj/room.lpc")
LPCC = os.environ.get("LPCC", os.path.expanduser("~/src/fluffos/build-debug/src/lpcc"))
PROBE = '''void create() {
  object r;
  string e, msg;
  msg = "";
  r = load_object("%s");
  if (!objectp(r)) { debug_message("PROBE no-base"); error("\\nPROBE no-base\\n"); }
  r->set("objects", ([ "/zz/none/a": 1 ]));
  e = catch(r->reset());
  msg += "case1=" + (e ? "ERR " + replace_string(e, "\\n", " ") : "OK");
  r = new("%s");
  r->set("objects", ([ "/zz/none/b": 2 ]));
  e = catch(r->reset());
  msg += " default=" + (e ? "ERR " + replace_string(e, "\\n", " ") : "OK");
  debug_message("PROBE " + msg);  // a lib whose error handler only logs would hide the error() text
  error("\\nPROBE " + msg + "\\n");
}
'''


def run_probe(dest, slug, base):
    work = f"{dest}/libs/{slug}/work"
    os.makedirs(f"{work}/log", exist_ok=True)
    with open(f"{work}/zprobe.lpc", "w") as f:
        f.write(PROBE % (base, base))
    p = subprocess.run([LPCC, "--batch", "config.fluffos"], input="/zprobe.lpc\n", capture_output=True, encoding="utf-8", errors="replace",
                       cwd=f"{dest}/libs/{slug}", timeout=900)
    out = p.stdout + p.stderr
    for line in out.split("\n"):
        if line.startswith("PROBE "):
            return line[6:].strip()
    return "no probe"


def main():
    slugs = sys.argv[1:]
    if not slugs:
        sys.exit(__doc__)
    for slug in slugs:
        rel = next((c for c in CANDIDATES if os.path.isfile(f"{REPO}/libs/{slug}/work/{c}")), None)
        if not rel:
            print(f"{slug}: no room base")
            continue
        base = "/" + rel[:-4]
        dest = f"/tmp/rprobe-{slug}-{os.getpid()}"
        try:
            subprocess.run([f"{REPO}/scripts/pristine_tree.sh", slug, "45995", dest], capture_output=True)
            head = run_probe(dest, slug, base)
            shutil.copyfile(f"{REPO}/libs/{slug}/work/{rel}", f"{dest}/libs/{slug}/work/{rel}")
            tree = run_probe(dest, slug, base)
            print(f"{slug}: {rel}: HEAD {head} -> tree {tree}", flush=True)
        finally:
            shutil.rmtree(dest, ignore_errors=True)


main()
