#!/usr/bin/env python3
"""scripts/play_sweep_many.py [--probe sweep|combat|walk] [--shapes one|two|quick] [--timeout SECONDS] [--out DIR] [--tag TAG] LISTFILE | SLUG [SLUG...]

One lane of a corpus-wide play sweep (KB 08 10.16): runs scripts/play_sweep_lib.py over the libs one after another, a TSV and a log per lib in DIR
(default $LPC_SCRATCH/sweep_all) and one summary line per lib on stdout:

    SLUG <TAB> verbs <TAB> findings <TAB> console <TAB> screen <TAB> closed <TAB> stuck <TAB> seconds <TAB> status <TAB> first `score` answer

`status` is `done`, `timeout`, `noboot` (the unit did not open its port: a boot that failed on its own port is retried once on port 47000+N, an
ephemeral source port of the host can hold a lib's own) or `norobot` (the login robot did not get in).  A `console` row is the signal: the driver printed
an error while the verb ran (read the log, reproduce by hand, KB 08 10.16).  Start two lanes (two lists) at most; a lane that runs longer than two hours is
killed by the tool that tracks it, so give each lane a list of about eight libs.  LISTFILE has one slug per line (`#` comments allowed).
`--probe combat` runs scripts/play_combat_probe.py instead (a fight with the NPCs of the start room: KB 08 10.16); its summary line is
    SLUG <TAB> candidates <TAB> fights <TAB> findings <TAB> console <TAB> stuck <TAB> closed <TAB> seconds <TAB> status <TAB> the ids found in the start room
`--probe walk` runs scripts/play_walk_probe.py (a depth-first walk of the rooms a visitor reaches from the start room, at most 50 moves: what the code does when a
player ENTERS a room); its summary line is
    SLUG <TAB> rooms <TAB> moves <TAB> findings <TAB> console <TAB> screen <TAB> closed <TAB> seconds <TAB> status <TAB> the first room
The unit of a lib is stopped by play_sweep_lib.py itself; this script never touches a unit it did not start."""
import argparse
import os
import re
import shutil
import subprocess
import sys
import time

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SCR = os.environ.get("LPC_SCRATCH") or os.path.expanduser("~/.cache/lpc-scratch")


def one(slug, shapes, timeout, out, tag, port=0, probe="sweep"):
    tsv, log = f"{out}/{slug}.tsv", f"{out}/{slug}.log"
    if probe == "combat":
        cmd = [sys.executable, f"{REPO}/scripts/play_combat_probe.py", slug, "--tag", tag, "--seconds", "20", "--targets", "2", "--out", tsv]
    elif probe == "walk":
        cmd = [sys.executable, f"{REPO}/scripts/play_walk_probe.py", slug, "--tag", tag, "--moves", "50", "--out", tsv]
    else:
        cmd = [sys.executable, f"{REPO}/scripts/play_sweep_lib.py", slug, "--shapes", shapes, "--out", tsv]
    if port:
        cmd += ["--port", str(port)]
    env = dict(os.environ, PLAY_TAG=tag) if tag else os.environ
    t0 = time.time()
    try:
        with open(log, "w", encoding="utf-8") as f:
            r = subprocess.run(cmd, cwd=REPO, stdout=f, stderr=subprocess.STDOUT, env=env, timeout=timeout)
        status = "done" if r.returncode == 0 else "failed"
    except subprocess.TimeoutExpired:
        status = "timeout"
        # play_sweep_lib.py was killed before its `finally`: stop the unit it started (exact name)
        subprocess.run([f"{REPO}/scripts/play_stop.sh", slug + (f"-{tag}" if tag else "")], cwd=REPO, capture_output=True)
    text = open(log, encoding="utf-8", errors="replace").read()
    # the unit is stopped; its tree (a full copy of the lib: hundreds of MB) is not needed any more -- the log and the TSV stay.  Exact path, our own scratch tree.
    tree = f"{SCR}/play-{slug}" + (f"-{tag}" if tag else "")
    if os.path.isdir(tree) and os.path.dirname(tree) == SCR and os.path.basename(tree).startswith("play-"):
        shutil.rmtree(tree, ignore_errors=True)
    if status == "failed":
        if re.search(r"boot failed|did not open port", text):
            status = "noboot"
        elif "robot did not get in" in text:
            status = "norobot"
    return status, text, time.time() - t0


def summary(text):
    verbs = re.search(r"^(\d+) verbs", text, re.M)
    by = {}
    m = re.search(r"^FINAL (\{.*\})", text, re.M)
    if m:
        try:
            by = eval(m.group(1), {"__builtins__": {}})
        except Exception:
            by = {}
    n = sum(by.values()) if by else len(re.findall(r"^FINDING", text, re.M))
    return int(verbs.group(1)) if verbs else 0, n, by


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("slugs", nargs="+")
    ap.add_argument("--probe", default="sweep", choices=["sweep", "combat", "walk"])
    ap.add_argument("--shapes", default="one", choices=["one", "two", "quick"])
    ap.add_argument("--timeout", type=int, default=1500)
    ap.add_argument("--out", default=f"{SCR}/sweep_all")
    ap.add_argument("--tag", default="sa")
    a = ap.parse_args()
    slugs = []
    for s in a.slugs:
        if os.path.isfile(s):
            slugs += [x.strip() for x in open(s, encoding="utf-8") if x.strip() and not x.startswith("#")]
        else:
            slugs.append(s)
    os.makedirs(a.out, exist_ok=True)
    for i, slug in enumerate(slugs):
        status, text, secs = one(slug, a.shapes, a.timeout, a.out, a.tag, 0, a.probe)
        if status == "noboot":
            status, text, secs2 = one(slug, a.shapes, a.timeout, a.out, a.tag, 47000 + i, a.probe)
            secs += secs2
        if a.probe == "combat":
            cands = re.search(r"^CANDIDATES (\[.*\])", text, re.M)
            ids = cands.group(1) if cands else ""
            kinds = {k: len(re.findall(rf"^FINDING \[{k}\]", text, re.M)) for k in ("console", "stuck", "screen", "connection-closed", "login")}
            print("\t".join(map(str, [slug, ids.count(",") + 1 if ids not in ("", "[]") else 0, len(re.findall(r"^COMBAT ", text, re.M)), len(re.findall(r"^FINDING ", text, re.M)),
                                       kinds["console"] + kinds["login"], kinds["stuck"] + kinds["screen"], kinds["connection-closed"], int(secs), status, ids[:80]])), flush=True)
            continue
        if a.probe == "walk":
            first = re.search(r"^ROOM 0 (.*?) exits=", text, re.M)
            visited = re.search(r"^VISITED (\d+) rooms in (\d+) moves", text, re.M)
            kinds = {k: len(re.findall(rf"^FINDING \[{k}\]", text, re.M)) for k in ("console", "screen", "closed", "login")}
            print("\t".join(map(str, [slug, visited.group(1) if visited else 0, visited.group(2) if visited else 0, len(re.findall(r"^FINDING ", text, re.M)),
                                       kinds["console"] + kinds["login"], kinds["screen"], kinds["closed"], int(secs), status, (first.group(1) if first else "")[:50]])), flush=True)
            continue
        verbs, n, by = summary(text)
        kinds = {k: by.get(k, 0) for k in ("console", "screen", "connection-closed", "stuck-reconnect")}
        d = re.search(r"^DEPTH score \| (.*)$", text, re.M)
        depth = d.group(1)[:50] if d else ""
        print("\t".join(map(str, [slug, verbs, n, kinds["console"], kinds["screen"], kinds["connection-closed"], kinds["stuck-reconnect"], int(secs), status, depth])), flush=True)


if __name__ == "__main__":
    main()
