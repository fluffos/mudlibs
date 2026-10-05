#!/usr/bin/env python3
"""scripts/lpc_dynamic_quest_guard.py [--apply] SLUG...      (no SLUG: every vendored lib)

Two latent bugs that scripts/lpc_dynamic_rows.py exposes.  With the rows of `dynamic_location` / `dynamic_quest` fixed the room-quest
daemon (`adm/daemons/questd.lpc`, `taskd.lpc`, `tasknpcd.lpc`) really runs `spread_quest()` from `create()` and from the
cron daemon for the first time since the archive was converted, and whatever was never reached before can raise:

1. `spread_quest()` calls `new(quest)` / `load_object(room)` / `room->reset()` and goes on with the result: a quest item the
   archive never shipped (xjcq2000: all 42 `/quest/shenshu/bookN`), a room that does not compile, a reset() that raises.  Its only
   callers are the `for` loops of `init_dynamic_quest()`, so the call statement there becomes `catch(spread_quest(...));`
   (a quest that cannot be spread is skipped, the daemon still loads and the other quests are spread; `give` loads questd lazily).
2. `look_room()` of `cmds/std/look.lpc` asks `present("fire", this_player())` for the night check of an outdoors room and
   `/feature/move.lpc remove()` calls `LOOK_CMD->look_room(me, ob, ...)` for every item that is destructed out of a room, so a
   room's own reset() (`destruct(inv[i])`, no this_player()) or a spread that resets a room raises
   `Bad argument 2 to present()` (xiyouji2006; xyj2006n carries the fix).  `objectp(this_player()) &&` goes in front of the
   `!present("fire", this_player())` of every look.lpc that lacks it.

Edits are byte-exact and keep the line endings; text in a comment or an `#if 0` block is left alone.  Without --apply it prints the plan.
A lib whose work/ is a gitlink is left."""
import os
import re
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from lpc_src import mask  # noqa: E402

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
args = sys.argv[1:]
apply_ = "--apply" in args
slugs = [a for a in args if a != "--apply"]
if not slugs:
    slugs = sorted(d for d in os.listdir(f"{REPO}/libs") if os.path.isdir(f"{REPO}/libs/{d}/work"))

# `spread_quest(args);` as a statement: the text before it on its line is blank, a `)` of a for/if header or an `else`
CALL = re.compile(rb"(?m)^([ \t]*(?:(?:for|if|while)[ \t]*\([^\n]*\)[ \t]*|else[ \t]+)?)spread_quest[ \t]*\(([^;\n]*)\)[ \t]*;")
FIRE = re.compile(rb'!present\("fire", this_player\(\)\)')
GUARDED = re.compile(rb"objectp\(this_player\(\)\)\s*&&\s*$")


def git(*a):
    return subprocess.run(["git", "-C", REPO] + list(a), capture_output=True).stdout


DAEMONS = ("questd.lpc", "taskd.lpc", "tasknpcd.lpc", "newquestd.lpc", "questd2.lpc", "questnew.lpc", "questsd.lpc")


def wrap_calls(raw):
    mk = mask(raw.decode("latin-1")).encode("latin-1")  # a call inside a comment or an `#if 0` block is left alone
    n = [0]

    def rep(m):
        if m.group(2).lstrip().startswith((b"string ", b"mapping ", b"int ", b"object ")):
            return m.group(0)  # a prototype, not a call
        if mk[m.start() + len(m.group(1))] == 32:
            return m.group(0)
        n[0] += 1
        return m.group(1) + b"catch(spread_quest(" + m.group(2) + b"));"
    return CALL.sub(rep, raw), n[0]


def guard_look(raw):
    mk = mask(raw.decode("latin-1")).encode("latin-1")
    n = [0]

    def rep(m):
        if mk[m.start()] == 32 or GUARDED.search(raw[max(0, m.start() - 80):m.start()]):
            return m.group(0)
        n[0] += 1
        return b"objectp(this_player()) && " + m.group(0)
    return FIRE.sub(rep, raw), n[0]


tot_calls = tot_looks = 0
for slug in slugs:
    w = f"libs/{slug}/work"
    if any(l.startswith(b"160000") for l in git("ls-files", "-s", "--", w).split(b"\n")):
        print(f"{slug}: work/ is a gitlink: left")
        continue
    files = [f for f in git("ls-files", "-z", "--", w).decode("utf-8", "surrogateescape").split("\0") if f.endswith(".lpc")]
    calls = looks = 0
    for rel in files:
        base = os.path.basename(rel)
        if base not in DAEMONS and base != "look.lpc":
            continue
        path = f"{REPO}/{rel}"
        raw = open(path, "rb").read()
        if base == "look.lpc":
            out, n = guard_look(raw)
            looks += n
        else:
            out, n = wrap_calls(raw)
            calls += n
        if out != raw and apply_:
            open(path, "wb").write(out)
    if calls or looks:
        print(f"{slug}: {calls} spread_quest() call(s) wrapped in catch, {looks} look.lpc night check(s) guarded")
    tot_calls += calls
    tot_looks += looks
print(f"total: {tot_calls} call(s), {tot_looks} look.lpc guard(s)" + ("" if apply_ else " (plan; --apply writes)"))
