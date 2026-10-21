#!/usr/bin/env python3
"""scripts/play_sweep_lib.py SLUG [--port P] [--no-boot] [--dirs d1,d2] [--wiz] [--shapes quick|full] [--burst PACE] [--start N] [--end M] [--skip v1,v2] [--out F]

A mortal-verb sweep of one lib (KB 08 10.16): boots the lib as a play unit (`play_boot.sh`, unless --no-boot), registers a character with the login robot
(`play_login.py`), takes the verbs from the file names under `work/cmds/` (and `secure/cmds/`, `lib/cmds/`: Dead Souls keeps its player commands there) (a leading or inner `_` is dropped: Discworld's `l_ook` is `look`, xkx's `_less` is `less`;
the wizard directories are left out unless --wiz: a mortal cannot run them) and sends every verb with a set of argument shapes (`playsweep.Sweep`): after each line it
reads the driver console and the screen, and probes the session so that a verb that opened a prompt (an editor, a dialogue) is closed with escape lines or the session
is reopened with a new character.  A finding is a console error / warning, a bad screen line, a closed connection or a session that needed escaping.

  --burst PACE   for a lib that throttles commands (Discworld's queue: `Queued command: i`): every verb's shapes are sent PACE seconds apart (1.3 for Discworld at a
                 two-second heart beat), the console is read once per verb, and only a verb that printed something wrong is re-run line by line to find the shape.
  --shapes       `quick` (4 shapes: none, `me`, a 300-character word, `你好 世界`; default) or `full` (the ten of playsweep.SHAPES).
  --dirs         comma-separated subdirectories of cmds/ (default: all but the wizard ones).
  --account      NAME:PASSWORD of a seeded account (discworld: fluffos:Mud@2026, an administrator; add --wiz to sweep the creator commands).
  --start/--end  slice of the sorted verb list, for a run in chunks of about an hour (a tracked job dies at two hours).

Output: `VERB n name` progress lines, `FINDING [kind] 'line': console=[...] screen='...'`, and a summary; --out also writes the findings as TSV (kind, line, console, screen).
The unit is stopped at the end (a unit this script booted).  Nothing here knows a lib: its login is the robot's, its verbs are file names."""
import argparse
import glob
import os
import subprocess
import sys
import time

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import play_login  # noqa: E402
from mudplay import Console  # noqa: E402
from playsweep import Sweep, SHAPES, DRIVER_BAD, SCREEN_BAD  # noqa: E402

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SCR = os.environ.get("LPC_SCRATCH") or os.path.expanduser("~/.cache/lpc-scratch")
WIZ_DIRS = {"wiz", "wizard", "wizards", "adm", "admin", "arch", "archwiz", "creator", "creators", "immortal", "immortals", "god", "gods", "lord", "lords", "elder", "domain",
            "dev", "developer", "sage", "sages", "wizzes", "imm", "wiztool", "admins", "builders", "arches", "cres"}
QUICK = ["", "me", "x" * 300, "你好 世界"]
SKIP = {"quit", "suicide", "password", "passwd", "chfn", "email", "shutdown", "reboot", "halt", "restart", "destruct", "dest", "exit", "logout", "bye", "kill_self", "retire",
        "delete", "rm", "quitgame", "disconnect"}


def own_port(slug):
    import json
    try:
        return int(json.load(open(f"{REPO}/libs/{slug}/meta.json"))["port"])
    except Exception:
        return 46400


def verbs_of(tree, dirs, wiz, roots=("cmds", "secure/cmds", "lib/cmds", "lib/secure/cmds")):
    out = set()
    for r in roots:
        root = f"{tree}/{r}"
        for d in sorted(os.listdir(root)) if os.path.isdir(root) else []:
            full = os.path.join(root, d)
            if not os.path.isdir(full) or (dirs and d not in dirs) or (not dirs and not wiz and d.lower() in WIZ_DIRS):
                continue
            for f in glob.glob(full + "/**/*.lpc", recursive=True) + glob.glob(full + "/**/*.c", recursive=True):
                n = os.path.basename(f).rsplit(".", 1)[0].replace("_", "")
                if n and "." not in n and not n.startswith(("base", "cmd", "std", "inherit")):
                    out.add(n)
    return sorted(out)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("slug")
    ap.add_argument("--port", type=int, default=0)
    ap.add_argument("--no-boot", action="store_true")
    ap.add_argument("--dirs", default="")
    ap.add_argument("--wiz", action="store_true")
    ap.add_argument("--shapes", default="quick", choices=["quick", "full"])
    ap.add_argument("--burst", type=float, default=0.0)
    ap.add_argument("--start", type=int, default=0)
    ap.add_argument("--end", type=int, default=100000)
    ap.add_argument("--skip", default="")
    ap.add_argument("--idle", type=float, default=0.6)
    ap.add_argument("--probe", default="look")
    ap.add_argument("--out", default="")
    ap.add_argument("--tag", default=os.environ.get("PLAY_TAG", ""))
    ap.add_argument("--account", default="", help="NAME:PASSWORD of an account the lib already has (an admin seeded in the tree): the sweep logs in as it, and again after a reconnect")
    a = ap.parse_args()
    port = a.port or own_port(a.slug)
    suf = f"-{a.tag}" if a.tag else ""
    unit_out = f"{SCR}/play-{a.slug}{suf}.out"
    tree = f"{SCR}/play-{a.slug}{suf}/libs/{a.slug}/work"
    booted = False
    if not a.no_boot:
        env = dict(os.environ, PLAY_TAG=a.tag) if a.tag else os.environ
        r = subprocess.run([f"{REPO}/scripts/play_boot.sh", a.slug, str(port)], cwd=REPO, capture_output=True, text=True, env=env, timeout=400)
        if r.returncode != 0:
            sys.exit(f"boot failed: {r.stderr.strip()[-200:]}")
        booted = True
    try:
        vs = verbs_of(tree, [d for d in a.dirs.split(",") if d], a.wiz)[a.start:a.end]
        skip = SKIP | {s for s in a.skip.split(",") if s}
        shapes = SHAPES if a.shapes == "full" else QUICK
        con = Console(unit_out)
        names = [0]

        def login():
            names[0] += 1
            n = names[0]
            if a.account:
                acc, _, accpw = a.account.partition(":")
                m = play_login.login_session(port, name=acc, pw=accpw or "Test1234", steps=45, existing=True)
            else:
                m = play_login.login_session(port, name="sweep" + chr(97 + n // 26 % 26) + chr(97 + n % 26), steps=45)
            if m is None:
                raise SystemExit("the robot did not get in")
            m.read(0.5, 2)
            return m

        state = {"m": login()}

        def relogin():
            try:
                state["m"].close()
            except Exception:
                pass
            state["m"] = login()
            return state["m"]

        sw = Sweep(state["m"], con, prompt_probe=a.probe, prompt_rx=r".", relogin=relogin, idle=a.idle, maxwait=max(4.0, 6 * a.idle), probe_idle=a.idle,
                   out=lambda s: print(s, flush=True))
        print(f"{len(vs)} verbs, {len(shapes)} shapes, port {port}", flush=True)
        for i, v in enumerate(vs):
            if v in skip:
                continue
            print("VERB", a.start + i, v, flush=True)
            if not a.burst:
                sw.run([v], shapes, skip)
                continue
            m = sw.m
            con.new()
            for sh in shapes:
                m.send((v + " " + sh).strip())
                time.sleep(a.burst)
                m.read(0.05, 0.3)
            time.sleep(2.5)
            txt = m.read(1.5, 8.0)
            cons = [c for c in con.new() if c.strip() and DRIVER_BAD.search(c)]
            if m.closed:
                sw._record("connection-closed", v, txt, cons)
                sw.m = relogin()
                continue
            if cons or SCREEN_BAD.search(txt):
                for sh in shapes:
                    line = (v + " " + sh).strip()
                    sw.m.send(line)
                    time.sleep(1.2)
                    t = sw.m.read(1.5, 6.0) + (time.sleep(1.2) or sw.m.read(1.0, 3.0))
                    c = [x for x in con.new() if x.strip() and DRIVER_BAD.search(x)]
                    if c:
                        sw._record("console", line, t, c)
                    elif SCREEN_BAD.search(t):
                        sw._record("screen", line, t, [])
            ok, t = sw._alive()
            if not ok and not sw._back_to_loop(v):
                sw._record("stuck-reconnect", v, t, [])
                sw.m = relogin()
        by = sw.report()
        if a.out:
            with open(a.out, "w", encoding="utf-8") as f:
                for kind, line, scr, cons in sw.findings:
                    f.write("\t".join([kind, line[:120].replace("\t", " "), " | ".join(cons[:3]).replace("\t", " ").replace("\n", " ")[:300], scr.replace("\t", " ").replace("\n", " ")[:200]]) + "\n")
        print("FINAL", {k: len(x) for k, x in by.items()}, flush=True)
    finally:
        if booted:
            subprocess.run([f"{REPO}/scripts/play_stop.sh", a.slug + (f"-{a.tag}" if a.tag else "")], cwd=REPO, capture_output=True)


if __name__ == "__main__":
    main()
