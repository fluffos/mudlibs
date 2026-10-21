#!/usr/bin/env python3
"""scripts/play_soak.py SLUG [--minutes N] [--port P] [--tag T] [--out FILE] [--no-boot]

A soak in a live session (KB 08 10.16): boots the lib as a play unit (`play_boot.sh`, unless --no-boot), registers a character with the login robot and idles for
--minutes minutes (default 15), sending `look` every 45 s (a few `score` and `i`) so the session stays alive while the lib's own timers run: heart beats, call_outs,
the cron / reset daemons, a room's `reset()` (most libs reset rooms every 15-30 minutes), weather and day/night, an NPC walking.  A bare-verb sweep, a fight or a
walk lasts minutes and never reaches those.  Every driver console line that looks like an error (playsweep.DRIVER_BAD) is collected with its minute; the summary groups
the lines by their text without numbers (`SOAK n x line`) and prints the first screen line the player saw with each (`FINDING [timer] ...`).  A closed connection
(the lib kicked the idle character, a shutdown or reboot timer: Discworld shut itself down 20 minutes after the boot) is `FINDING [closed]` with the minute.
The unit is stopped at the end (a unit this script booted)."""
import argparse
import collections
import os
import re
import subprocess
import sys
import time

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import play_login  # noqa: E402
from mudplay import Console  # noqa: E402
from play_sweep_lib import born_if_needed, own_port  # noqa: E402
from playsweep import DRIVER_BAD  # noqa: E402

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SCR = os.environ.get("LPC_SCRATCH") or os.path.expanduser("~/.cache/lpc-scratch")


def norm(line):
    return re.sub(r"\d+", "N", line.strip())[:160]


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("slug")
    ap.add_argument("--port", type=int, default=0)
    ap.add_argument("--tag", default=os.environ.get("PLAY_TAG", "sk"))
    ap.add_argument("--minutes", type=float, default=15.0)
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
    seen = collections.OrderedDict()
    try:
        con = Console(unit_out)
        m = play_login.login_session(port, name="sweepsa", steps=45)
        if m is None:
            raise SystemExit("the robot did not get in")
        m.read(0.5, 2)
        born_if_needed(m)
        t0 = time.time()
        con.new()
        n = 0
        last_screen = ""
        while time.time() - t0 < a.minutes * 60 and not m.closed:
            n += 1
            probe = ("look", "look", "score", "look", "i")[n % 5]
            try:
                last_screen = m.cmd(probe, idle=1.0, maxwait=8) or last_screen
            except Exception:
                break
            minute = (time.time() - t0) / 60
            for c in con.new():
                if c.strip() and DRIVER_BAD.search(c):
                    k = norm(c)
                    if k not in seen:
                        seen[k] = [0, minute, c.strip()[:200]]
                    seen[k][0] += 1
            end = time.time() + 45
            while time.time() < end and not m.closed:
                try:
                    m.read(1.0, 5.0)
                except Exception:
                    break
                for c in con.new():
                    if c.strip() and DRIVER_BAD.search(c):
                        k = norm(c)
                        if k not in seen:
                            seen[k] = [0, (time.time() - t0) / 60, c.strip()[:200]]
                        seen[k][0] += 1
        if m.closed:
            findings.append(("closed", f"{(time.time() - t0) / 60:.1f} min", "", " ".join(last_screen.split())[-160:]))
        print(f"SOAK {(time.time() - t0) / 60:.1f} minutes, {n} probes, {len(seen)} distinct console lines", flush=True)
        for k, (cnt, minute, raw) in seen.items():
            print(f"SOAK {cnt} x [{minute:.1f} min] {raw}", flush=True)
            findings.append(("timer", f"{cnt}x at {minute:.1f} min", raw, ""))
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
