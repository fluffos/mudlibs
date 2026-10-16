#!/usr/bin/env python3
"""scripts/lpc_add_message_combatd.py [--apply] SLUG...

`Undefined function message_combatd` (KB 04 section 6.2): the kungfu/perform files of the xkx family call
`message_combatd(msg, me, target)` -- a simul_efun of the original server -- and 27 archives never shipped its definition,
so every file that calls it fails to compile (xbtxiii: 133 perform files).  Where the lib's own `message_vision()` is
defined in adm/simul_efun/message.lpc this adds, right after that definition (a same-file call before the textual
definition of the callee does not resolve on this driver, AGENTS.md 8b),

    varargs void message_combatd(string msg, object me, object you, mixed extra) { message_vision(msg, me, you); }

the alias bixiecanyang / xingzhanyingxiu / weimingkongjian carry already.  Libs that define it (under adm/simul_efun/ or
include/: a copy in a wizard dir or a daemon does not count) or have no
adm/simul_efun/message.lpc with exactly one `message_vision` definition are listed and left.  Without --apply it prints
the plan; edits are byte-exact (line endings kept).  Gitlink libs are refused."""
import os
import re
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from lpc_src import top_level_defs  # noqa: E402

args = sys.argv[1:]
apply_ = "--apply" in args
slugs = [a for a in args if a != "--apply"]
if not slugs:
    sys.exit(__doc__)


def gitlink(slug):
    out = subprocess.run(["git", "-C", REPO, "ls-files", "-s", "--", f"libs/{slug}/work"], capture_output=True, text=True).stdout
    return any(l.startswith("160000") for l in out.split("\n"))


for slug in slugs:
    if gitlink(slug):
        print(f"{slug}: work/ is a gitlink, not edited in place")
        continue
    root = f"{REPO}/libs/{slug}/work"
    target = f"{root}/adm/simul_efun/message.lpc"
    if not os.path.isfile(target):
        print(f"{slug}: no adm/simul_efun/message.lpc: left")
        continue
    # defined as a simul_efun or macro?  (a copy in a wizard dir or a daemon: tianxiawuxue's u/lonely/sec/message.lpc, hc's
    # adm/daemons/combatd.ahxia.lpc, is not one)
    out = subprocess.run(["grep", "-rlE", r"(void|int) +message_combatd *\(|define +message_combatd"]
                         + [d for d in (f"{root}/adm/simul_efun", f"{root}/include") if os.path.isdir(d)]
                         + ["--include=*.lpc", "--include=*.h"], capture_output=True, text=True).stdout.split()
    if out:
        print(f"{slug}: message_combatd is defined in {os.path.relpath(out[0], root)}: left")
        continue
    # a live call: in code (not a comment or string), and not a method call (`ob->message_combatd(`)
    from lpc_src import mask
    live = []
    for f in subprocess.run(["grep", "-rlE", r"message_combatd *\(", root, "--include=*.lpc", "--include=*.h"],
                            capture_output=True, text=True).stdout.split():
        if re.search(r"/(u|backup|bak|log)/", f[len(root):]):
            continue
        src = open(f, "rb").read().decode("latin-1")
        if re.search(r"(void|int|mixed) +message_combatd *\(", src):
            continue   # its own local function (hc's adm/daemons/combatd.ahxia.lpc)
        mk = mask(src)
        if any(mk[m.start()] == src[m.start()] and not src[:m.start()].rstrip().endswith("->")
               and not re.search(r"\b(void|int|mixed|string|varargs)\s*$", src[max(0, m.start() - 40):m.start()])
               for m in re.finditer(r"message_combatd\s*\(", src)):   # not a definition
            live.append(f)
    if not live:
        print(f"{slug}: no live call to message_combatd (commented out or method calls only): left")
        continue
    raw = open(target, "rb").read()
    text = raw.decode("latin-1")
    defs = top_level_defs(text, "message_vision")
    if len(defs) != 1:
        print(f"{slug}: {len(defs)} definitions of message_vision in message.lpc: left")
        continue
    name_start, op, cp = defs[0]
    # the closing brace of that function
    m = text  # find '{' after cp, then match
    i = text.index("{", cp)
    depth, j = 0, i
    # use the masked text for brace matching
    from lpc_src import mask
    mk = mask(text)
    while j < len(mk):
        if mk[j] == "{":
            depth += 1
        elif mk[j] == "}":
            depth -= 1
            if depth == 0:
                break
        j += 1
    eol = "\r\n" if "\r\n" in text else "\n"
    add = eol.join([
        "",
        "// message_combatd() is called by the perform files but this archive never defined it (a simul_efun of the original",
        "// server): the same as message_vision().",
        "varargs void message_combatd(string msg, object me, object you, mixed extra) {",
        "  message_vision(msg, me, you);",
        "}",
    ])
    new = text[:j + 1] + add + text[j + 1:]
    calls = subprocess.run(["grep", "-rlE", r"message_combatd *\(", root, "--include=*.lpc", "--include=*.h"],
                           capture_output=True, text=True).stdout.split()
    print(f"{slug}: + message_combatd after message_vision (line {text.count(chr(10), 0, j) + 1}); {len(calls)} file(s) call it")
    if apply_:
        open(target, "wb").write(new.encode("latin-1"))
