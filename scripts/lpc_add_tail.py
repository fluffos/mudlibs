#!/usr/bin/env python3
"""scripts/lpc_add_tail.py [--apply] SLUG...

`Undefined function tail` (KB 04 section 6.2): `tail()` was an efun of the MudOS the xkx / Fengyun / ES II archives ran on and
FluffOS has no such efun, so the wizard command `cmds/*/tail.lpc` (`tail(file);`) fails to compile in about 60 libs.  Where a lib
has such a command that does not define `tail` itself and defines `tail` nowhere under adm/ (nor as a macro), this appends

    void tail(string file)       the last 10 lines of the file, written to this_player()

to `adm/simul_efun/file.lpc` (every one of those libs has it; its directory is loaded as a whole), after a comment that says why.
It prints the libs it leaves (no command, already defined, no file.lpc, gitlink).  Without --apply it prints the plan; edits are
byte-exact and keep the line endings of the file."""
import os
import re
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
args = sys.argv[1:]
apply_ = "--apply" in args
slugs = [a for a in args if a != "--apply"]
if not slugs:
    sys.exit(__doc__)

FUNC = """
// tail() was an efun of the MudOS this archive ran on and is not one here: the last 10 lines of a file, as `cmds/*/tail.lpc` expects.
void tail(string file) {
  string content, *lines;
  int start;

  content = read_file(file);
  if (!stringp(content))
    return;
  lines = explode(content, "\\n");
  start = sizeof(lines) - 10;
  if (start < 0)
    start = 0;
  write(implode(lines[start..], "\\n") + "\\n");
}
"""


def git(*a):
    return subprocess.run(["git", "-C", REPO] + list(a), capture_output=True, text=True).stdout


for slug in slugs:
    w = f"libs/{slug}/work"
    if any(l.startswith("160000") for l in git("ls-files", "-s", "--", w).split("\n")):
        print(f"{slug}: work/ is a gitlink: left")
        continue
    cmds = [p for p in git("grep", "-l", "-E", r"^[ \t]*tail[ \t]*\(", "--", f"{w}/cmds/*/tail.lpc").split("\n") if p]
    # a command that defines its own tail() (bxsj `int tail(string fname)`) compiles as it is
    own = set(git("grep", "-l", "-E", r"^(varargs[ \t]+)?(void|int|string|mixed|object)[ \t]+tail[ \t]*\(", "--", f"{w}/cmds/*/tail.lpc").split("\n"))
    cmds = [c for c in cmds if c not in own]
    if not cmds:
        print(f"{slug}: no tail command calls tail(): left")
        continue
    if git("grep", "-l", "-E", r"^(varargs[ \t]+)?(void|int|string|mixed|object)[ \t]+tail[ \t]*\(", "--", f"{w}/adm").strip() or \
            git("grep", "-l", "-E", r"define[ \t]+tail\b", "--", w).strip():
        print(f"{slug}: tail() is defined already: left")
        continue
    host = f"{REPO}/{w}/adm/simul_efun/file.lpc"
    if not os.path.isfile(host):
        print(f"{slug}: no adm/simul_efun/file.lpc: left")
        continue
    b = open(host, "rb").read()
    eol = b"\r\n" if b"\r\n" in b else b"\n"
    add = FUNC.replace("\n", eol.decode()).encode("utf-8")
    new = b + (b"" if b.endswith(b"\n") else eol) + add
    print(f"{slug}: + tail() in adm/simul_efun/file.lpc ({len(cmds)} command file(s))")
    if apply_:
        open(host, "wb").write(new)
