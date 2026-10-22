#!/usr/bin/env python3
"""scripts/play_combat_probe.py SLUG [--port P] [--tag T] [--seconds N] [--targets K] [--out FILE] [--no-boot] [--account NAME:PW --clone PATH[,PATH..] [--clone-verb V]] [--verbs kill,fight,attack,hit]

A fight in a live session (KB 08 10.16), the part of the game no bare-verb sweep reaches: boots the lib as a play unit (`play_boot.sh`, unless --no-boot), registers a
character with the login robot, reads the start room, takes the ids it shows in parentheses (`店小二(xiao er)`, `Guard (guard)`) and attacks each one with `kill ID`
(`fight ID` when `kill` answers with a refusal) for --seconds seconds (default 25: the combat rounds, the NPC's answer, the death of one side, the corpse, a ghost)
while it reads the driver console.  Every driver line printed during the fight is reported, with the screen tail of the target: `COMBAT <id> console=[...] screen='...'`.
A character that dies is logged in again (a ghost or a respawn is part of the test).  Nothing here knows a lib: ids come from the first `look`, the verbs are
`kill`/`fight`/`attack`/`hit` (`--verbs`).  A lib that lists no NPC where a visitor starts (Nightmare IV, Discworld, the Dead Souls family) is fought with the seeded administrator: `--account fluffos:Mud@2026 --clone /domains/Ylsrim/npc/traveller`
clones each file in the room, takes the id from the new line of the room (or the file name) and attacks it.  Exit status 0 when it ran; findings are lines starting `FINDING`.  The unit is stopped at the end (a unit this script booted)."""
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

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SCR = os.environ.get("LPC_SCRATCH") or os.path.expanduser("~/.cache/lpc-scratch")
ID_RX = re.compile(r"[\(（]([A-Za-z][A-Za-z0-9 _'\-]{1,30})[\)）]")
SELF = re.compile(r"^(fight|sweep)[a-z]{2}$")
REFUSAL = re.compile(r"(?i)(try .help|help index|unknown command|huh\?|not understand|don.t understand|no such command|what\?|don'?t see|no such|cannot|can't|not here|找不到|没有这个|不能|无法|什么\？|你要|whom|who\b|禁止|不允许|不准|forbid|not allowed|no fighting|peace)")


NOUNS = ("guard", "guardian", "soldier", "knight", "man", "woman", "boy", "girl", "child", "citizen", "peasant", "merchant", "shopkeeper", "bartender", "barkeep", "waiter",
         "priest", "cleric", "beggar", "mayor", "king", "thief", "wizard", "monk", "dog", "cat", "rat", "wolf", "goblin", "orc", "troll", "dwarf", "elf", "monster", "newbie")
DIRS = ("north", "south", "east", "west", "northeast", "northwest", "southeast", "southwest", "up", "down", "enter", "out")
OPPOSITE = {"north": "south", "south": "north", "east": "west", "west": "east", "northeast": "southwest", "southwest": "northeast", "northwest": "southeast",
            "southeast": "northwest", "up": "down", "down": "up", "enter": "out", "out": "enter"}


STOP = set("""north south east west northeast northwest southeast southwest up down exit exits door doors gate gates sign signs fountain statue road street path stair stairs hall room wall walls fire light sun moon air wind smell sound bazaar
shop shops tree trees rock rocks chair table bed water river lake sea forest sky cloud clouds ground floor ceiling bridge tower building house castle village town city entrance
corridor passage tunnel cave""".split())
LIVING = re.compile(r"(?i)\b(?:an?|the|some|two|three|four|several)\s+(?:[a-z'\-]+\s+){0,3}?([a-z][a-z'\-]{2,})\s+(?:is|are|stands?|sits?|lies|lurks?|waits?|guards?|wanders?|walks?|sleeps?|rests?|looks?|here)\b")


def noun_candidates(look):
    low = look.lower()
    out = [n for n in NOUNS if re.search(rf"\b{n}s?\b", low)]
    for m in LIVING.finditer(look):          # `A traveller is standing here.` (Nightmare IV lists no id): the noun is the id of a living thing in nearly every lib
        w = m.group(1).lower()
        for c in (w, w[:-1] if w.endswith("s") and len(w) > 4 else None):
            if c and c not in STOP and c not in out:
                out.append(c)
    return out


def exits_of(look):
    """the directions named on the exits line (and the next one); without such a line, in the last three lines: `seeps out of the walls` is not an exit"""
    lines = look.splitlines()
    zone = [ln + " " + (lines[i + 1] if i + 1 < len(lines) else "") for i, ln in enumerate(lines) if re.search(r"(?i)exit|出口|出路", ln)]
    low = " ".join(zone).lower() if zone else " ".join(lines[-3:]).lower()
    return [d for d in DIRS if re.search(rf"\b{d}\b", low)]


def candidates(look):
    out = []
    for ln in look.splitlines():
        for m in ID_RX.finditer(ln):
            cid = m.group(1).strip().lower()
            if cid and cid not in out and not SELF.match(cid) and not cid.startswith(("exits", "出口")):
                out.append(cid)
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("slug")
    ap.add_argument("--port", type=int, default=0)
    ap.add_argument("--tag", default=os.environ.get("PLAY_TAG", "cb"))
    ap.add_argument("--seconds", type=float, default=25.0)
    ap.add_argument("--targets", type=int, default=3)
    ap.add_argument("--no-boot", action="store_true")
    ap.add_argument("--out", default="")
    ap.add_argument("--account", default="", help="NAME:PASSWORD of a seeded account (an administrator): log in as it instead of registering a character")
    ap.add_argument("--clone", default="", help="comma list of NPC files the account clones into its room, each one is fought")
    ap.add_argument("--clone-verb", default="clone")
    ap.add_argument("--verbs", default="kill,fight,attack,hit")
    ap.add_argument("--pace", type=float, default=0.0, help="seconds to wait for each answer at least (Discworld queues one command per heart beat: 2.5)")
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
        n = [0]

        def paced(mm):
            if a.pace and mm is not None:
                orig = mm.cmd

                def cmd(line, idle=0.6, maxwait=6.0):
                    return orig(line, idle=max(idle, a.pace), maxwait=max(maxwait, a.pace * 3))
                mm.cmd = cmd
            return mm

        def login(first=False):
            m = None
            if a.account:
                nm, pw = a.account.split(":", 1)
                m = play_login.login_session(port, name=nm, pw=pw, steps=45, existing=True)
                if m is None:
                    raise SystemExit("the robot did not get in as " + nm)
                m.read(0.5, 2)
                return paced(m)
            if not first:                       # the first character again (a lib that rations new accounts per IP would refuse a fresh name)
                m = play_login.login_session(port, name="sweepca", steps=45, existing=True)
            if m is None:
                m = play_login.login_session(port, name="sweepc" + chr(97 + n[0] % 26), steps=45)
                n[0] += 1
            if m is None:
                raise SystemExit("the robot did not get in")
            m.read(0.5, 2)
            born_if_needed(m)
            return paced(m)

        m = login(first=True)
        pre = [c for c in con.new() if c.strip()]
        if pre:
            print("LOGIN console:", " | ".join(x[:120] for x in pre[:6]), flush=True)
            for c in pre:
                if DRIVER_BAD.search(c):
                    findings.append(("login", "", c[:200], ""))
        look = m.cmd("look", idle=0.8, maxwait=6)
        cands = candidates(look)
        if not cands:                           # the first answer after a login can be the tail of the welcome text
            look = m.cmd("look", idle=1.2, maxwait=8)
            cands = candidates(look)
        con.new()
        if not cands:
            cands = noun_candidates(look)
        walked = []
        back = None
        while not cands and len(walked) < 6 and not m.closed and not a.clone:           # no one here: walk on, an NPC is a few rooms away
            ex = [d for d in exits_of(look) if d != back] or exits_of(look)
            if not ex:
                break
            step = ex[0]
            walked.append(step)
            back = OPPOSITE.get(step)
            m.cmd(step, idle=0.8, maxwait=6)
            look = m.cmd("look", idle=1.0, maxwait=6)
            cands = candidates(look) or noun_candidates(look)
        if walked:
            print("WALKED", walked, flush=True)
        con.new()
        if not cands:
            print("LOOK", " ".join(look.split())[:300], flush=True)
        print("CANDIDATES", cands, flush=True)
        if not cands and not a.clone:
            print("no ids in the start room: nothing to fight", flush=True)
        fights = [0]

        def fight_one(tgt):
            """attack tgt with the verbs in order; True when a fight took place"""
            nonlocal m
            lines, screen, first = [], "", ""
            refused = True
            for verb in [v for v in a.verbs.split(",") if v]:
                txt = m.cmd(f"{verb} {tgt}", idle=1.0, maxwait=6)
                first = first or " ".join(txt.split())[:110]
                screen += txt
                if m.closed:
                    break
                refused = bool(REFUSAL.search(txt[-200:]))
                if not refused:
                    break
            if refused and not m.closed:           # a sign, a board, a door: not a living thing here
                lines += [c for c in con.new() if c.strip()]
                bad = [c for c in lines if DRIVER_BAD.search(c)]
                if bad:
                    findings.append(("console", tgt, " | ".join(x[:160] for x in bad[:4]), screen.strip()[-200:]))
                    print(f"REFUSED {tgt} bad={len(bad)}", flush=True)
                    for c in bad[:4]:
                        print("    ", c[:200], flush=True)
                return False
            fights[0] += 1
            t0 = time.time()
            while time.time() - t0 < a.seconds and not m.closed:
                screen += m.read(1.5, 3.0)
                lines += [c for c in con.new() if c.strip()]
            if m.closed:
                findings.append(("connection-closed", tgt, "", screen.strip()[-200:]))
                m = login()
                con.new()
                return True
            for probe in ("look", "score", "i"):
                try:
                    screen += m.cmd(probe, idle=0.8, maxwait=5)
                except Exception:
                    break
            lines += [c for c in con.new() if c.strip()]
            bad = [c for c in lines if DRIVER_BAD.search(c)]
            print(f"COMBAT {tgt} first={first!r} rounds={screen.count(chr(10))} console={len(lines)} bad={len(bad)} screen={' '.join(screen.split())[-120:]!r}", flush=True)
            for c in bad[:8]:
                print("    ", c[:200], flush=True)
            if bad:
                findings.append(("console", tgt, " | ".join(x[:160] for x in bad[:4]), screen.strip()[-200:]))
            elif SCREEN_BAD.search(screen):
                mm = SCREEN_BAD.search(screen)
                findings.append(("screen", tgt, "", " ".join(screen[max(0, mm.start() - 80):mm.end() + 80].split())))
            # a dead character: a ghost or a respawn is fine, a stuck session is not
            try:
                ok = m.cmd("look", idle=0.8, maxwait=5)
            except Exception:
                ok = ""
            if m.closed or not ok.strip():
                findings.append(("stuck", tgt, "", screen.strip()[-200:]))
                try:
                    m.close()
                except Exception:
                    pass
                m = login()
                con.new()
            return True

        if a.clone:                              # clone, fight at once (a wanderer such as Googol leaves the room within a heart beat), next file
            for path in [x for x in a.clone.split(",") if x]:
                if m.closed:
                    break
                out = m.cmd(f"{a.clone_verb} {path}", idle=1.0, maxwait=8)
                cl = [c for c in con.new() if c.strip()]
                print("CLONE", path, "|", " ".join(out.split())[:110], flush=True)
                bad = [c for c in cl if DRIVER_BAD.search(c)]
                for c in bad[:4]:
                    print("    ", c[:200], flush=True)
                if bad:
                    findings.append(("clone", path, " | ".join(x[:160] for x in bad[:4]), out.strip()[-200:]))
                look = m.cmd("look", idle=1.0, maxwait=6)
                base = os.path.basename(path).rsplit(".", 1)[0]
                tried = []
                for c in [base] + candidates(look) + noun_candidates(look):
                    if c and c not in tried and c not in DIRS:
                        tried.append(c)
                print("CANDIDATES", tried[:6], flush=True)
                for tgt in tried[:6]:
                    if fight_one(tgt):
                        break
        else:
            for tgt in cands[:10]:
                if fights[0] >= a.targets or m.closed:
                    break
                fight_one(tgt)
        for kind, tgt, cons, scr in findings:
            print(f"FINDING [{kind}] {tgt!r}: {cons} | {scr!r}", flush=True)
        print(f"{len(findings)} findings", flush=True)
        if a.out:
            with open(a.out, "w", encoding="utf-8") as f:
                for kind, tgt, cons, scr in findings:
                    f.write("\t".join([kind, tgt, cons.replace("\t", " ").replace("\n", " ")[:300], scr.replace("\t", " ").replace("\n", " ")[:200]]) + "\n")
    finally:
        if booted:
            subprocess.run([f"{REPO}/scripts/play_stop.sh", slug + (f"-{a.tag}" if a.tag else "")], cwd=REPO, capture_output=True)


if __name__ == "__main__":
    main()
