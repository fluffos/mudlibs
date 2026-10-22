#!/usr/bin/env python3
"""scripts/play_goto_probe.py SLUG --account NAME:PW [--rooms /d/a/b,/d/c/d | --auto N] [--goto-verb goto] [--port P] [--tag T] [--out FILE] [--no-boot]

Rooms a visitor reaches only after a long walk, entered in one command (KB 08 10.16): boots the lib as a play unit (`play_boot.sh`, unless --no-boot), logs in as the
seeded administrator (`--account`, the README's `## Admin account`) and for every room `goto`es it, `look`s, and reads the driver console and the screen: the code that runs
when a player ENTERS a room (`init()`, `valid_enter`, a long description that is a function, an `item_desc` that is a function pointer, an aggressive NPC that was made by
`reset()`), which neither the load census (it loads, nobody enters) nor the walk probe (it only reaches the first 50 rooms of the start area) runs.  `--auto N` takes N rooms at
random from the lib's tracked files (a file that inherits a ROOM macro or a `/std/room`-like path, outside wizard / backup / data / include directories, plain ASCII names);
`--rooms` takes a comma list.  After the visit the `item_desc` nouns of the room are looked at as well (`look NOUN`, at most 6).  Output: `ROOM path title`, `FINDING [console|screen|goto|closed]`.
Nothing here knows a lib but the administrator's `goto` verb (`--goto-verb`)."""
import argparse
import os
import random
import re
import subprocess
import sys
import time

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import play_login  # noqa: E402
from mudplay import Console  # noqa: E402
from play_sweep_lib import own_port  # noqa: E402
from playsweep import DRIVER_BAD, SCREEN_BAD  # noqa: E402

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SCR = os.environ.get("LPC_SCRATCH") or os.path.expanduser("~/.cache/lpc-scratch")
SKIP = re.compile(r"/(u|w|wiz|wizard|wizards|open|players|backup|backups|bak|old|test|tests|tmp|data|log|include|adm|secure|cmds|doc|docs|std|lib|inherit|obj|clone|daemon|realms|www)/|[-_.](bak|old)")
ROOMINH = re.compile(rb"(?m)^[ \t]*inherit[ \t]+[^;\n]*(ROOM|room)")
GOTO_BAD = re.compile(r"(?i)(no such|not found|找不到|没有这个|can'?t find|couldn'?t find|cannot find|failed|无法|不能)")


def auto_rooms(slug, n):
    files = subprocess.run(["git", "ls-files", "-z", "--", f"libs/{slug}/work"], cwd=REPO, capture_output=True).stdout.split(b"\0")
    cand = []
    for f in files:
        try:
            p = f.decode("utf-8")
        except UnicodeDecodeError:
            continue
        rel = p[len(f"libs/{slug}/work"):]
        if not rel.endswith(".lpc") or SKIP.search(rel) or not re.match(r"^[A-Za-z0-9_./-]+$", rel) or rel.count("/") < 2:
            continue
        try:
            head = open(f"{REPO}/{p}", "rb").read(6000)
        except OSError:
            continue
        if ROOMINH.search(head) and re.search(rb"(?i)exit", open(f"{REPO}/{p}", "rb").read()):
            cand.append(rel[:-4])
    random.Random(f"{slug}:goto").shuffle(cand)
    return cand[:n], len(cand)


def item_nouns(slug, room, n=6):
    """the keys of the room's `item_desc` mapping, from its source (the nouns a visitor can `look` at)"""
    try:
        b = open(f"{REPO}/libs/{slug}/work{room}.lpc", "rb").read()
    except OSError:
        return []
    m = re.search(rb'item_desc"?\s*,\s*\(\[(.*?)\]\)\s*\)', b, re.S)
    if not m:
        return []
    out = []
    for k in re.findall(rb'"([A-Za-z][A-Za-z0-9 _\'-]{1,20})"\s*:', m.group(1)):
        w = k.decode()
        if w not in out:
            out.append(w)
    return out[:n]


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("slug")
    ap.add_argument("--account", required=True)
    ap.add_argument("--rooms", default="")
    ap.add_argument("--auto", type=int, default=0)
    ap.add_argument("--goto-verb", default="goto")
    ap.add_argument("--port", type=int, default=0)
    ap.add_argument("--tag", default=os.environ.get("PLAY_TAG", "gt"))
    ap.add_argument("--no-boot", action="store_true")
    ap.add_argument("--out", default="")
    ap.add_argument("--pace", type=float, default=0.0)
    a = ap.parse_args()
    slug, port = a.slug, a.port or own_port(a.slug)
    rooms = [r for r in a.rooms.split(",") if r]
    if a.auto:
        more, total = auto_rooms(slug, a.auto)
        rooms += more
        print(f"AUTO {len(more)} of {total} candidate rooms", flush=True)
    if not rooms:
        sys.exit("no rooms")
    suf = f"-{a.tag}" if a.tag else ""
    unit_out = f"{SCR}/play-{slug}{suf}.out"
    booted = False
    if not a.no_boot:
        env = dict(os.environ, PLAY_TAG=a.tag) if a.tag else os.environ
        r = subprocess.run([f"{REPO}/scripts/play_boot.sh", slug, str(port)], cwd=REPO, capture_output=True, text=True, env=env, timeout=400)
        if r.returncode != 0:
            sys.exit(f"boot failed: {r.stderr.strip()[-200:]}")
        booted = True
    findings = []
    try:
        con = Console(unit_out)
        nm, pw = a.account.split(":", 1)

        def login():
            m = play_login.login_session(port, name=nm, pw=pw, steps=45, existing=True)
            if m is None:
                raise SystemExit("the robot did not get in as " + nm)
            m.read(0.5, 2)
            if a.pace:
                orig = m.cmd

                def cmd(line, idle=0.6, maxwait=6.0):
                    return orig(line, idle=max(idle, a.pace), maxwait=max(maxwait, a.pace * 3))
                m.cmd = cmd
            return m

        m = login()
        con.new()
        visited = 0
        for r in rooms:
            if m.closed:
                findings.append(("closed", r, "", ""))
                try:
                    m = login()
                except SystemExit as e:
                    print(e, flush=True)
                    break
                con.new()
            txt = m.cmd(f"{a.goto_verb} {r}", idle=1.0, maxwait=8)
            lines = [c for c in con.new() if c.strip()]
            look = m.cmd("look", idle=1.0, maxwait=6)
            lines += [c for c in con.new() if c.strip()]
            title = " ".join(look.split())[:70]
            bad = [c for c in lines if DRIVER_BAD.search(c)]
            print(f"ROOM {r} | {title} | goto={' '.join(txt.split())[:50]!r} console={len(lines)} bad={len(bad)}", flush=True)
            for c in bad[:4]:
                print("    ", c[:200], flush=True)
            if bad:
                findings.append(("console", r, " | ".join(x[:160] for x in bad[:4]), " ".join(txt.split())[-150:]))
            else:
                mm = SCREEN_BAD.search(txt + look)
                if mm:
                    s = txt + look
                    findings.append(("screen", r, "", " ".join(s[max(0, mm.start() - 80):mm.end() + 80].split())))
                elif GOTO_BAD.search(txt) and not look.strip():
                    findings.append(("goto", r, "", " ".join(txt.split())[:150]))
            for noun in item_nouns(slug, r):
                t2 = m.cmd(f"look {noun}", idle=0.8, maxwait=6)
                l2 = [c for c in con.new() if c.strip()]
                b2 = [c for c in l2 if DRIVER_BAD.search(c)]
                if b2:
                    print(f"    look {noun}: console", " | ".join(x[:150] for x in b2[:2]), flush=True)
                    findings.append(("console", r + " look " + noun, " | ".join(x[:160] for x in b2[:4]), " ".join(t2.split())[-150:]))
                elif SCREEN_BAD.search(t2):
                    mm = SCREEN_BAD.search(t2)
                    findings.append(("screen", r + " look " + noun, "", " ".join(t2[max(0, mm.start() - 80):mm.end() + 80].split())))
            visited += 1
        for kind, r, cons, scr in findings:
            print(f"FINDING [{kind}] {r!r}: {cons} | {scr!r}", flush=True)
        print(f"{len(findings)} findings in {visited} rooms", flush=True)
        if a.out:
            with open(a.out, "w", encoding="utf-8") as f:
                for kind, r, cons, scr in findings:
                    f.write("\t".join([kind, r, cons.replace("\t", " ").replace("\n", " ")[:300], scr.replace("\t", " ").replace("\n", " ")[:200]]) + "\n")
    finally:
        if booted:
            subprocess.run([f"{REPO}/scripts/play_stop.sh", slug + (f"-{a.tag}" if a.tag else "")], cwd=REPO, capture_output=True)


if __name__ == "__main__":
    main()
