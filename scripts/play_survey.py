#!/usr/bin/env python3
"""scripts/play_survey.py [--port 46300] [--cmds "look;score;i;who;help"] [--out FILE] [--skip "slug slug"] [--boot-timeout 240] [SLUG... | --all]

The login survey (KB 08 10.16): for each lib, boot it as a play unit (scripts/play_boot.sh: a pristine tree plus the working-tree edits of that lib), log in with the generic
robot (scripts/play_login.py: register a character on the fresh tree, the first game commands, quit), read what the driver printed meanwhile, and stop the unit.  A sweep or a
mechanical fix that touched thousands of files leaves no trace in the load gates when the broken path is a run-time one (registration, the first commands): this walks it.

One tab-separated line per lib on stdout and in --out (default $LPC_SCRATCH/play_survey.tsv):

  slug <TAB> result <TAB> steps <TAB> boot_errors <TAB> play_errors <TAB> first error line <TAB> last prompt

`result` is the robot's verdict (`in`: a game prompt was reached; `stuck`: it could not answer the dialogue; `closed`: the server closed the connection or never answered) or
`noboot` (the port did not open).  `boot_errors` counts the driver's error lines before the first connection, `play_errors` those printed during the login (playsweep.DRIVER_BAD).
A `stuck` lib is a lib with an unusual dialogue, not a verdict: look at it by hand (KB 08 10.16).  --all takes every vendored lib with a config.fluffos that is not a gitlink
(`realms` needs MySQL, a lib with its own driver build is skipped: SURVEY_SKIP / --skip).  The unit is stopped after each lib; nothing else is killed."""
import argparse
import os
import re
import subprocess
import sys
import time

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from playsweep import DRIVER_BAD  # noqa: E402

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SCR = os.environ.get("LPC_SCRATCH") or os.path.expanduser("~/.cache/lpc-scratch")
OWN_DRIVER = {"lima", "wilderness", "spacemud", "swmud"}        # play_boot.sh SLUG PORT DRIVER with the lib's own build: not a survey case
BORING = re.compile(r"^(Processing config file|Unable to open log file|Execution root|Initializing|Event backend|Loading |Accepting|Initializations complete|====|$)")


def all_slugs():
    out = subprocess.run(["git", "ls-files", "-s", "-z", "--", "libs"], cwd=REPO, capture_output=True).stdout.split(b"\0")
    gitlinks = set()
    for ln in out:
        if ln.startswith(b"160000 "):
            gitlinks.add(ln.split(b"\t", 1)[1].decode().split("/")[1])
    return [s for s in sorted(os.listdir(os.path.join(REPO, "libs"))) if os.path.isfile(os.path.join(REPO, "libs", s, "config.fluffos")) and s not in gitlinks]


def errors(text):
    return [ln.strip() for ln in text.split("\n") if ln.strip() and not BORING.match(ln.strip()) and DRIVER_BAD.search(ln)]


def survey_one(slug, port, cmds, boot_timeout):
    out = os.path.join(SCR, f"play-{slug}.out")
    t0 = time.time()
    try:
        r = subprocess.run([os.path.join(REPO, "scripts/play_boot.sh"), slug, str(port)], cwd=REPO, capture_output=True, text=True, timeout=boot_timeout)
    except subprocess.TimeoutExpired:
        return [slug, "noboot", "-", "-", "-", "play_boot.sh timed out", ""]
    try:
        if r.returncode != 0:
            return [slug, "noboot", "-", "-", "-", (r.stderr.strip().splitlines() or ["port did not open"])[-1][:160], ""]
        try:
            boot_text = open(out, encoding="utf-8", errors="replace").read()
        except OSError:
            boot_text = ""
        mark = len(boot_text.encode("utf-8", "replace"))
        i = boot_text.find("Loading simul_efun")
        if i < 0:
            i = boot_text.find("Loading master")
        boot_errs = errors(boot_text[i:] if i >= 0 else boot_text)           # the driver echoes its configuration first ("trace : 1", "#define __TRACE__"): not a message
        p = subprocess.run([sys.executable, os.path.join(REPO, "scripts/play_login.py"), str(port), "--quiet", "--cmds", cmds], cwd=REPO, capture_output=True, text=True, timeout=300)
        verdict = [ln for ln in p.stdout.splitlines() if ln.startswith("RESULT")]
        m = re.match(r"RESULT (\w+) steps=(\d+) last=(.*)", verdict[-1]) if verdict else None
        result, steps, last = (m.group(1), m.group(2), re.sub(r"\s+seconds=\d+$", "", m.group(3))[:100]) if m else ("closed", "0", (p.stderr or p.stdout)[-100:].replace("\n", " "))
        time.sleep(0.5)
        try:
            with open(out, "rb") as f:
                f.seek(mark)
                play_text = f.read().decode("utf-8", "replace")
        except OSError:
            play_text = ""
        play_errs = errors(play_text)
        first = (play_errs or boot_errs or [""])[0][:200]
        return [slug, result, steps, str(len(boot_errs)), str(len(play_errs)), first, last]
    except subprocess.TimeoutExpired:
        return [slug, "closed", "-", "-", "-", "play_login.py timed out", ""]
    finally:
        subprocess.run([os.path.join(REPO, "scripts/play_stop.sh"), slug], cwd=REPO, capture_output=True)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("slugs", nargs="*")
    ap.add_argument("--all", action="store_true")
    ap.add_argument("--port", type=int, default=46300)
    ap.add_argument("--cmds", default="look;score;i;who;help")
    ap.add_argument("--out", default=os.path.join(SCR, "play_survey.tsv"))
    ap.add_argument("--skip", default=os.environ.get("SURVEY_SKIP", ""))
    ap.add_argument("--boot-timeout", type=int, default=240)
    ap.add_argument("--append", action="store_true", help="keep the lines already in --out (a resumed survey skips the slugs it holds)")
    a = ap.parse_args()
    slugs = a.slugs or (all_slugs() if a.all else [])
    if not slugs:
        ap.error("no libs: name them or give --all")
    skip = set(a.skip.split()) | {"realms"} | OWN_DRIVER
    done = set()
    if a.append and os.path.exists(a.out):
        done = {ln.split("\t", 1)[0] for ln in open(a.out, encoding="utf-8") if ln.strip()}
    mode = "a" if a.append else "w"
    with open(a.out, mode, encoding="utf-8") as fo:
        for s in slugs:
            if s in skip or s in done:
                continue
            row = survey_one(s, a.port, a.cmds, a.boot_timeout)
            line = "\t".join(row)
            print(line, flush=True)
            fo.write(line + "\n")
            fo.flush()


if __name__ == "__main__":
    main()
