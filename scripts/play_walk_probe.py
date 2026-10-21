#!/usr/bin/env python3
"""scripts/play_walk_probe.py SLUG [--port P] [--tag T] [--moves N] [--out FILE] [--no-boot]

A walk in a live session (KB 08 10.16): boots the lib as a play unit (`play_boot.sh`, unless --no-boot), registers a character with the login robot and walks the
rooms a visitor reaches from the start room, depth first, at most --moves moves (default 50): at every room it `look`s, takes the directions named on the exits line
(and the next one) and tries each once; it steps back with the opposite direction.  A room is told from another by the first lines of its `look`.  It reports what a
bare-verb sweep cannot see, the code that runs when a player ENTERS a room (`valid_leave`, `init`, doors, a destination that does not load, an aggressive NPC):
every driver console line printed during a move (`FINDING [console]`), a screen that shows an error (`FINDING [screen]`: `couldn't find object`, `Failed to load`,
`Trace written`, a stack trace), a move that answers nothing, a character that died or a connection that closed (`FINDING [closed]`, the walk stops).  A refusal that is the
lib's own (`The door is closed`, `你不能往那个方向走`) is not a finding.  Output: `ROOM n title`, `MOVE dir -> title` lines and the findings; exit status 0 when it ran.
The unit is stopped at the end (a unit this script booted).  Nothing here knows a lib: exits come from the text of `look`."""
import argparse
import os
import re
import subprocess
import sys
import time

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import play_login  # noqa: E402
from mudplay import Console  # noqa: E402
from play_sweep_lib import born_if_needed, own_port  # noqa: E402
from playsweep import DRIVER_BAD, SCREEN_BAD  # noqa: E402
from play_combat_probe import exits_of, OPPOSITE  # noqa: E402

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SCR = os.environ.get("LPC_SCRATCH") or os.path.expanduser("~/.cache/lpc-scratch")
JUNK = re.compile(r"[^A-Za-z一-鿿]")
LOADERR = re.compile(r"(?i)(couldn'?t find object|failed to load|trace written|error in|runtime error|bad argument|too deep|不对劲|找不到|载入失败|無法載入|無法找到)")


def title_of(look):
    """the first lines of a `look`, letters and CJK only: the room's name and the start of its description"""
    lines = [JUNK.sub("", ln) for ln in look.splitlines()]
    lines = [ln for ln in lines if len(ln) >= 2]
    return "".join(lines[:2])[:40]


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("slug")
    ap.add_argument("--port", type=int, default=0)
    ap.add_argument("--tag", default=os.environ.get("PLAY_TAG", "wk"))
    ap.add_argument("--moves", type=int, default=50)
    ap.add_argument("--no-boot", action="store_true")
    ap.add_argument("--out", default="")
    a = ap.parse_args()
    slug, port = a.slug, a.port or own_port(a.slug)
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
        m = play_login.login_session(port, name="sweepwa", steps=45)
        if m is None:
            raise SystemExit("the robot did not get in")
        m.read(0.5, 2)
        born_if_needed(m)
        pre = [c for c in con.new() if c.strip()]
        for c in pre:
            if DRIVER_BAD.search(c):
                findings.append(("login", "", c[:200], ""))
        look = m.cmd("look", idle=1.0, maxwait=6)
        if not exits_of(look):
            look = m.cmd("look", idle=1.4, maxwait=8)
        con.new()
        visited = {title_of(look): 0}
        tried = {title_of(look): set()}
        path = []                       # directions taken from the start room, to step back with
        cur = title_of(look)
        print(f"ROOM 0 {cur!r} exits={exits_of(look)}", flush=True)
        moves = 0
        dead = False
        while moves < a.moves and not dead and not m.closed:
            todo = [d for d in exits_of(look) if d not in tried[cur]]
            if not todo:
                if not path:
                    break
                back = OPPOSITE.get(path[-1])
                path.pop()
                if not back:
                    break
                moves += 1
                m.cmd(back, idle=0.8, maxwait=5)
                look = m.cmd("look", idle=1.0, maxwait=6)
                cur = title_of(look)
                tried.setdefault(cur, set())
                continue
            d = todo[0]
            tried[cur].add(d)
            moves += 1
            txt = m.cmd(d, idle=0.8, maxwait=6)
            lines = [c for c in con.new() if c.strip()]
            bad = [c for c in lines if DRIVER_BAD.search(c)]
            if m.closed:
                findings.append(("closed", f"{cur} -> {d}", "", txt.strip()[-200:]))
                break
            if bad:
                findings.append(("console", f"{cur} -> {d}", " | ".join(x[:160] for x in bad[:4]), txt.strip()[-160:]))
            elif LOADERR.search(txt) or SCREEN_BAD.search(txt):
                findings.append(("screen", f"{cur} -> {d}", "", " ".join(txt.split())[-220:]))
            look = m.cmd("look", idle=1.0, maxwait=6)
            lines = [c for c in con.new() if c.strip()]
            bad2 = [c for c in lines if DRIVER_BAD.search(c)]
            if bad2:
                findings.append(("console", f"{cur} -> {d} (look)", " | ".join(x[:160] for x in bad2[:4]), ""))
            new = title_of(look)
            if re.search(r"(?i)(you are dead|you have died|你死了|死亡|ghost|鬼魂)", txt + look) and not exits_of(look):
                findings.append(("closed", f"{cur} -> {d}", "died", " ".join(txt.split())[-160:]))
                dead = True
            if new == cur or not new:
                print(f"MOVE {d} -> (stays) {' '.join(txt.split())[:80]!r}", flush=True)
                continue
            print(f"MOVE {d} -> {new!r} exits={exits_of(look)}", flush=True)
            path.append(d)
            if new not in visited:
                visited[new] = len(visited)
                tried[new] = set()
            else:
                tried.setdefault(new, set())
            cur = new
        print(f"VISITED {len(visited)} rooms in {moves} moves", flush=True)
        for kind, where, cons, scr in findings:
            print(f"FINDING [{kind}] {where!r}: {cons} | {scr!r}", flush=True)
        print(f"{len(findings)} findings", flush=True)
        if a.out:
            with open(a.out, "w", encoding="utf-8") as f:
                for kind, where, cons, scr in findings:
                    f.write("\t".join([kind, where, cons.replace("\t", " ").replace("\n", " ")[:300], scr.replace("\t", " ").replace("\n", " ")[:200]]) + "\n")
    finally:
        if booted:
            subprocess.run([f"{REPO}/scripts/play_stop.sh", slug + (f"-{a.tag}" if a.tag else "")], cwd=REPO, capture_output=True)


if __name__ == "__main__":
    main()
