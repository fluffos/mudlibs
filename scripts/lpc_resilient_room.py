#!/usr/bin/env python3
"""scripts/lpc_resilient_room.py [--apply] SLUG...

A room whose inventory object raises in create() must not take the room down with it.  The xkx / Fengyun / ES II room base
(`std/room.lpc`, `inherit/room/room.lpc`) fills a room in `make_inventory(string file[, int j])` with

    ob = new(file);                 (then `if (!objectp(ob)) return 0;` or straight on to `ob->move(this_object())`)

and `new()` of a file that is not there returns 0 on this driver, but `new()` of a file whose `create()` raises (a missing
skill file for `set_skill()`, a weapon `carry_object()` cannot find, an include that never shipped) raises in the room.  Once
the wrong-case paths of a lib are fixed (scripts/lpc_case_paths.py) the NPCs behind them exist for the first time, and every
room that holds one with a content gap stopped loading (sjshwzjqb, sjcs): worse than the missing NPC it had before.
The unique-object form of the sje / shujian / sjsh family (`ob = unew(file); if (ob) {...} else ob = filter_array(children(file),
(: clonep :))[<1];`) gets `if (catch(ob = unew(file))) ob = 0;` and an `else` that indexes only a non-empty array.

This replaces the one `ob = new(file);` of make_inventory by

    if (catch(ob = new(file)) || !objectp(ob)) return 0;

(with a comment saying why).  A room base without that exact statement, or with a `catch` already, is listed and left.  Without
--apply it prints the plan; edits are byte-exact and keep the line endings."""
import os
import re
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from lpc_src import mask, top_level_defs  # noqa: E402

args = sys.argv[1:]
apply_ = "--apply" in args
slugs = [a for a in args if a != "--apply"]
if not slugs:
    sys.exit(__doc__)

CANDIDATES = ("std/room.lpc", "inherit/room/room.lpc", "inherit/room.lpc", "std/room/room.lpc", "obj/room.lpc")
UNEW = re.compile(r"(?m)^([ \t]*)ob[ \t]*=[ \t]*unew[ \t]*\([ \t]*file[ \t]*\)[ \t]*;[ \t]*(\r?)$")
UNEW_ELSE = re.compile(r"(\}?[ \t]*)else[ \t]+ob[ \t]*=[ \t]*filter_array[ \t]*\([ \t]*children[ \t]*\([ \t]*file[ \t]*\)[ \t]*,[ \t]*"
                       r"\(:[ \t]*clonep[ \t]*:\)[ \t]*\)[ \t]*\[[ \t]*<[ \t]*1[ \t]*\][ \t]*;")
DECL = re.compile(r"(?m)^([ \t]*)object[ \t]+ob[ \t]*;")
STMT = re.compile(r"(?m)^([ \t]*)ob[ \t]*=[ \t]*new[ \t]*\([ \t]*file[ \t]*\)[ \t]*;[ \t]*(\r?)$")


def git(*a):
    return subprocess.run(["git", "-C", REPO] + list(a), capture_output=True, text=True).stdout


for slug in slugs:
    w = f"libs/{slug}/work"
    if any(l.startswith("160000") for l in git("ls-files", "-s", "--", w).split("\n")):
        print(f"{slug}: work/ is a gitlink: left")
        continue
    seen = False
    for rel in CANDIDATES:
        path = f"{REPO}/{w}/{rel}"
        if not os.path.isfile(path):
            continue
        raw = open(path, "rb").read()
        text = raw.decode("latin-1")
        defs = top_level_defs(text, "make_inventory")
        if len(defs) != 1:
            continue
        seen = True
        ns, op, cp = defs[0]
        i = text.index("{", cp)
        mk = mask(text)
        depth, j = 0, i
        while j < len(mk):
            depth += (mk[j] == "{") - (mk[j] == "}")
            if depth == 0:
                break
            j += 1
        body = text[i:j + 1]
        if "catch" in mask(body):
            print(f"{slug}: {rel} make_inventory has a catch already: left")
            continue
        ms = list(STMT.finditer(body))
        mu, me = UNEW.search(body), UNEW_ELSE.search(body)
        if len(ms) != 1 and mu and me and len(UNEW.findall(body)) == 1 and DECL.search(body):
            # the unique-object form (sje / shujian / sjsh): `ob = unew(file);` raises in the simul_efun for a file that is not
            # there (`new()` is 0, then `ob->query("unique")`), and the `else` takes `[<1]` of an empty array
            eol = "\r\n" if "\r\n" in text else "\n"
            ind = mu.group(1)
            nb = body[:mu.start()] + (f"{ind}// a missing or broken object file must not take the room down with it{eol}"
                                      f"{ind}if (catch(ob = unew(file))) ob = 0;" + mu.group(2)) + body[mu.end():]
            me = UNEW_ELSE.search(nb)
            nb = nb[:me.start()] + me.group(1) + "else if (sizeof(obs = filter_array(children(file), (: clonep :)))) ob = obs[<1];" + nb[me.end():]
            d = DECL.search(nb)
            nb = nb[:d.start()] + d.group(1) + "object ob, *obs;" + nb[d.end():]
            out = text[:i] + nb + text[j + 1:]
            print(f"{slug}: {rel}: make_inventory made resilient (unew form)")
            if apply_:
                open(path, "wb").write(out.encode("latin-1"))
            break
        if len(ms) != 1:
            print(f"{slug}: {rel} make_inventory has {len(ms)} `ob = new(file);` statements: left")
            continue
        m = ms[0]
        eol = "\r\n" if "\r\n" in text else "\n"
        ind = m.group(1)
        new_stmt = (f"{ind}// an object whose create() raises (a missing skill file, a header that never shipped) must not take the room{eol}"
                    f"{ind}// down with it{eol}"
                    f"{ind}if (catch(ob = new(file)) || !objectp(ob)) return 0;" + m.group(2))
        newbody = body[:m.start()] + new_stmt + body[m.end():]
        out = text[:i] + newbody + text[j + 1:]
        print(f"{slug}: {rel}: make_inventory made resilient")
        if apply_:
            open(path, "wb").write(out.encode("latin-1"))
        break
    if not seen:
        print(f"{slug}: no make_inventory in {', '.join(CANDIDATES)}: left")
