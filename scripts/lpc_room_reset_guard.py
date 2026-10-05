#!/usr/bin/env python3
"""scripts/lpc_room_reset_guard.py [--apply] SLUG...      (scripts/lpc_resilient_room.py is the other half)

The room base of the xkx / Fengyun / ES II / Journey-to-the-West family fills a room in `reset()`:

    case 1:
      if (!ob[list[i]]) ob[list[i]] = make_inventory(list[i]);
      if (environment(ob[list[i]]) != this_object() && ob[list[i]]->is_character()) { ... }

`make_inventory()` returns 0 for an object file that is not there or whose create() raises (KB 05 section 7.25: new() of a
missing file is 0, and lpc_resilient_room.py makes the helper itself survive the other case).  On this driver
`environment(0)` and `0->is_character()` raise, so the first room that lists an NPC the archive never shipped is
`Bad argument 1 to environment()` out of create() -> setup() -> reset(): the room does not load, and neither does the area behind
it (xyj2006n: 52 rooms, `/d/changan/playerhomes/h_croc`, `/d/dntg/sky/npc/dongtian`).  A room base that already skips the 0
(`if (objectp(...) && ...)`, `if (!(ob[list[i]])) continue;`, es2, fy2, tianlongbabu, zjdyzj ...) is left; so is one whose
statement is followed by an `else` (a 0 skips the `else if`, and an inserted statement would steal the `else`) or has a shape
this tool does not know (listed: hy5, hymud, yszz and the bases without a `case 1:` are read by hand).  For the
rest the tool inserts, behind that statement of `case 1:`

    if (!objectp(ob[list[i]])) break;

(leaves the switch only: the entry stays 0, the next reset() tries again, the other entries are filled).  Only `reset()` of
the first CANDIDATES file that defines both it and make_inventory() is looked at.  Edits are byte-exact and keep the
line endings.  Without --apply it prints the plan."""
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
CASE1 = re.compile(r"case[ \t\r\n]+1[ \t\r\n]*:")
MAKE = re.compile(r"(?m)^([ \t]*)if[ \t]*\([ \t]*![ \t]*ob\[list\[i\]\][ \t]*\)[ \t]*ob\[list\[i\]\][ \t]*=[ \t]*"
                  r"make_inventory[ \t]*\([ \t]*list\[i\][^;\n]*\)[ \t]*;[ \t]*(\r?)\n")


MAKE_BRACE = re.compile(r"(?m)^[ \t]*if[ \t]*\([ \t]*![ \t]*ob\[list\[i\]\][ \t]*\)(?:[ \t\r]*\n[ \t]*)?[ \t]*\{[ \t\r]*\n"
                        r"([ \t]*)ob\[list\[i\]\][ \t]*=[ \t]*make_inventory[ \t]*\([ \t]*list\[i\][^;\n]*\)[ \t]*;[ \t]*(\r?)\n")
DEF_LABEL = re.compile(r"default[ \t\r\n]*:")
DEF_MAKE = re.compile(r"(?m)^([ \t]*)(?:if[ \t]*\([^\n;]*\)[ \t]*)?ob\[list\[i\]\]\[j\][ \t]*=[ \t]*make_inventory[ \t]*\([^;\n]*\)[ \t]*;[ \t]*(\r?)\n")
GUARDED_CASE = re.compile(r"objectp ?\( ?ob\[list\[i\]\]|ob\[list\[i\]\] ?(&&|\|\|)|! ?\(? ?ob\[list\[i\]\] ?\)? ?\) ?(continue|break)")


def git(*a):
    return subprocess.run(["git", "-C", REPO] + list(a), capture_output=True, text=True).stdout


def guard_default(text, slug, rel):
    """`default:` of the same switch: `ob[list[i]][j] = make_inventory(...);` followed by a call on the entry instead of `continue;`
    (cctx / jhfy / xajh family: `if (ob[list[i]][j]->is_character() && ...)`) gets `if (!objectp(ob[list[i]][j])) continue;`"""
    mk = mask(text)
    span = func_body(text, mk, "reset")
    if not span:
        return text, 0
    i, j = span
    body, mbody = text[i:j + 1], mk[i:j + 1]
    d = DEF_LABEL.search(mbody)
    if not d:
        return text, 0
    n = 0
    for m in reversed(list(DEF_MAKE.finditer(body, d.end()))):
        nxt = re.sub(r"\s+", " ", mbody[m.end():]).strip()
        if nxt.startswith("continue") or nxt.startswith("if (!objectp(ob[list[i]][j])) continue"):
            continue
        after = re.sub(r"\s+", " ", mbody[m.end():m.end() + 400])
        deref = re.search(r"ob\[list\[i\]\]\[j\] ?->|environment ?\( ?ob\[list\[i\]\]\[j\]", after)
        if not deref:
            continue
        cond = after[max(0, after.rfind("if", 0, deref.start())):deref.start()]
        if re.search(r"objectp ?\( ?ob\[list\[i\]\]\[j\] ?\)|ob\[list\[i\]\]\[j\] ?&&", cond):
            continue  # the call is already behind `ob[list[i]][j] &&` / objectp() (wmkj)
        ind, cr = m.group(1), m.group(2)
        body = body[:m.end()] + f"{ind}if (!objectp(ob[list[i]][j])) continue;{cr}\n" + body[m.end():]
        n += 1
    if n:
        print(f"{slug}: {rel}: reset() `default:` skips an entry make_inventory() could not make")
    return text[:i] + body + text[j + 1:], n


def func_body(text, mk, name):
    defs = top_level_defs(text, name)
    if len(defs) != 1:
        return None
    ns, op, cp = defs[0]
    i = text.index("{", cp)
    depth, j = 0, i
    while j < len(mk):
        depth += (mk[j] == "{") - (mk[j] == "}")
        if depth == 0:
            break
        j += 1
    return i, j


for slug in slugs:
    w = f"libs/{slug}/work"
    if any(l.startswith("160000") for l in git("ls-files", "-s", "--", w).split("\n")):
        print(f"{slug}: work/ is a gitlink: left")
        continue
    done = False
    for rel in CANDIDATES:
        path = f"{REPO}/{w}/{rel}"
        if not os.path.isfile(path):
            continue
        text = open(path, "rb").read().decode("latin-1")
        mk = mask(text)
        if len(top_level_defs(text, "make_inventory")) != 1:
            continue
        span = func_body(text, mk, "reset")
        if not span:
            print(f"{slug}: {rel}: no single reset(): left")
            done = True
            break
        i, j = span
        body, mbody = text[i:j + 1], mk[i:j + 1]
        cases = [m for m in CASE1.finditer(mbody)]
        if not cases:
            print(f"{slug}: {rel}: reset() has no `case 1:`: left")
            done = True
            break
        c = cases[0]
        m = MAKE.search(body, c.end())
        if m and mbody[c.end():m.start()].strip():
            m = None
        if not m:
            # `if (!ob[list[i]]) {` + the make_inventory statement + more (hy5 `maze2`, yszz `is_character()`)
            mb = MAKE_BRACE.search(body, c.end())
            if mb and mbody[c.end():mb.start()].strip():
                mb = None
            seg_end = mbody.find("break", c.end())
            seg = re.sub(r"\s+", " ", mbody[c.end():seg_end if seg_end > 0 else len(mbody)])
            if mb and not GUARDED_CASE.search(seg) and re.search(r"environment ?\( ?ob\[list\[i\]\]|ob\[list\[i\]\] ?->", seg):
                ind, cr = mb.group(1), mb.group(2)
                ins = f"{ind}if (!objectp(ob[list[i]])) break;{cr}\n"
                newbody = body[:mb.end()] + ins + body[mb.end():]
                print(f"{slug}: {rel}: reset() skips an entry make_inventory() could not make (inside the braces)")
                if apply_:
                    out = text[:i] + newbody + text[j + 1:]
                    open(path, "wb").write(out.encode("latin-1"))
            elif mb and GUARDED_CASE.search(seg):
                print(f"{slug}: {rel}: reset() already skips a 0 entry: left")
            else:
                print(f"{slug}: {rel}: `case 1:` is not followed by the usual make_inventory statement: left")
            done = True
            break
        rest = mbody[m.end():]
        nxt = re.sub(r"\s+", " ", rest).strip()[:260]
        if nxt.startswith("else"):
            print(f"{slug}: {rel}: the statement is followed by `else` (a 0 never reaches a call): left")
        elif re.match(r"if ?\( ?(!? ?objectp ?\( ?ob\[list\[i\]\]|ob\[list\[i\]\] ?(&&|\)|\|\|)|! ?\( ?ob\[list\[i\]\] ?\)|! ?ob\[list\[i\]\])", nxt):
            print(f"{slug}: {rel}: reset() already skips a 0 entry: left")
        elif re.match(r"if ?\( ?(environment ?\( ?ob\[list\[i\]\]|ob\[list\[i\]\] ?->)", nxt):
            ind, cr = m.group(1), m.group(2)
            ins = f"{ind}if (!objectp(ob[list[i]])) break;{cr}\n"
            newbody = body[:m.end()] + ins + body[m.end():]
            print(f"{slug}: {rel}: reset() skips an entry make_inventory() could not make")
            if apply_:
                out = text[:i] + newbody + text[j + 1:]
                open(path, "wb").write(out.encode("latin-1"))
        else:
            print(f"{slug}: {rel}: unknown statement after make_inventory in `case 1:` ({nxt[:60]}): left")
        done = True
        break
    if not done:
        print(f"{slug}: no room base with make_inventory in {', '.join(CANDIDATES)}: left")
        continue
    for rel in CANDIDATES:
        path = f"{REPO}/{w}/{rel}"
        if not os.path.isfile(path):
            continue
        text = open(path, "rb").read().decode("latin-1")
        if len(top_level_defs(text, "make_inventory")) != 1:
            continue
        out, n = guard_default(text, slug, rel)
        if n and apply_:
            open(path, "wb").write(out.encode("latin-1"))
        break
