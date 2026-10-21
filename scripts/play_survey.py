#!/usr/bin/env python3
"""scripts/play_survey.py [--port N] [--cmds "look;score;i;who;help"] [--out FILE] [--skip "slug slug"] [--boot-timeout 240] [SLUG... | --all]

The login survey (KB 08 10.16): for each lib, boot it as a play unit (scripts/play_boot.sh: a pristine tree plus the working-tree edits of that lib), log in with the generic
robot (scripts/play_login.py: register a character on the fresh tree, the first game commands, quit), read what the driver printed meanwhile, and stop the unit.  A sweep or a
mechanical fix that touched thousands of files leaves no trace in the load gates when the broken path is a run-time one (registration, the first commands): this walks it.

One tab-separated line per lib on stdout and in --out (default $LPC_SCRATCH/play_survey.tsv):

  slug <TAB> result <TAB> steps <TAB> boot_errors <TAB> play_errors <TAB> first error line <TAB> last prompt <TAB> saved [<TAB> relogin]

`result` is the robot's verdict (`in`: a game prompt was reached; `stuck`: it could not answer the dialogue; `closed`: the server closed the connection or never answered) or
`noboot` (the port did not open).  `boot_errors` counts the driver's error lines before the first connection, `play_errors` those printed during the login (playsweep.DRIVER_BAD).
With --relogin the ninth column is the second visit of the same character (`in:0`, `stuck:0`, `closed:2:first console error`): a character that was saved and does not load again is a restore or password-check bug.  `saved` counts the files whose path has `sweepzq` in it (the robot's character: `data/user/s/sweepzq.o`, but also `data/user/s/sweepzq/login.o` of the per-user-directory libs) in the unit's tree after the login and the `quit`: 0 for an `in` row is a lib that did not persist the character -- a denied `save_object()`
(yhyxcs: `valid_write()` compared the file without the `.o` and recursed, KB 06 7.309) or a lib that saves elsewhere / later: look.  A `stuck` lib is a lib with an unusual dialogue, not a verdict: look at it by hand (KB 08 10.16).  --all takes every vendored lib with a config.fluffos that is not a gitlink
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


def own_port(slug):
    """the port the lib's config.fluffos names: a master whose connect() switches on MUD_PORT (ES2: dfgsiiv13b, huoying, naruto) refuses every other port"""
    try:
        m = re.search(r"(?m)^port number\s*:\s*(\d+)", open(os.path.join(REPO, "libs", slug, "config.fluffos"), encoding="utf-8", errors="replace").read())
        return int(m.group(1)) if m else None
    except OSError:
        return None


def survey_one(slug, port, cmds, boot_timeout, relogin=False):
    port = port or own_port(slug) or 46300
    out = os.path.join(SCR, f"play-{slug}.out")
    t0 = time.time()
    try:
        r = subprocess.run([os.path.join(REPO, "scripts/play_boot.sh"), slug, str(port)], cwd=REPO, capture_output=True, text=True, timeout=boot_timeout)
    except subprocess.TimeoutExpired:
        return [slug, "noboot", "-", "-", "-", "play_boot.sh timed out", "", "-", "-"]
    try:
        mp = re.search(r"listening on port (\d+)", r.stdout or "")
        if mp:
            port = int(mp.group(1))          # the port the driver really listens on (a lib that sets it outside `port number`)
        if r.returncode != 0:
            return [slug, "noboot", "-", "-", "-", (r.stderr.strip().splitlines() or ["port did not open"])[-1][:160], "", "-", "-"]
        try:
            boot_text = open(out, encoding="utf-8", errors="replace").read()
        except OSError:
            boot_text = ""
        # a daemon that loads thousands of saved players on its first heart beat (nt1's `closed`, KB 06 7.107) keeps the driver busy for a minute after the port
        # opened: wait until the console has been quiet for 8 s (at most 150 s) before the robot logs in, or its first answers are "silence" and the row says stuck
        quiet_since, last_size, t_wait = time.time(), -1, time.time()
        while time.time() - t_wait < 150:
            size = os.path.getsize(out) if os.path.exists(out) else 0
            if size != last_size:
                last_size, quiet_since = size, time.time()
            elif time.time() - quiet_since >= 8:
                break
            time.sleep(1)
        try:
            boot_text = open(out, encoding="utf-8", errors="replace").read()
        except OSError:
            pass
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
        tree = os.path.join(SCR, f"play-{slug}", "libs", slug, "work")
        found = subprocess.run(["find", tree, "-ipath", "*sweepzq*", "-type", "f"], capture_output=True, text=True).stdout.split()
        again = "-"
        if relogin and found and result == "in":                    # the second visit: the saved character must load (restore_object, the password check, the first look)
            mark2 = os.path.getsize(out) if os.path.exists(out) else 0
            for wait in (25, 100, 0):                               # a second visit right after the quit is refused for 20 s (xkx), 120 s (jhfy3): wait and try again
                p2 = subprocess.run([sys.executable, os.path.join(REPO, "scripts/play_login.py"), str(port), "--quiet", "--existing", "--cmds", "look;score"], cwd=REPO, capture_output=True, text=True, timeout=300)
                v2 = [ln for ln in p2.stdout.splitlines() if ln.startswith("RESULT")]
                m2 = re.match(r"RESULT (\w+) steps=(\d+)(?: last=(.*))?", v2[-1]) if v2 else None
                if not (m2 and m2.group(1) == "closed") or not wait:
                    break
                time.sleep(wait)                                      # the xkx family refuses a reconnect for 20 s after a quit ("您刚刚断线，20秒钟之内不能连线进入"), and an ES quit finishes a few seconds after the link closed: a reconnect before that meets the old body and its pending quit
            time.sleep(0.5)
            try:
                with open(out, "rb") as f:
                    f.seek(mark2)
                    text2 = f.read().decode("utf-8", "replace")
            except OSError:
                text2 = ""
            errs2 = errors(text2)
            again = f"{m2.group(1) if m2 else 'closed'}:{len(errs2)}" + (f":{errs2[0][:120]}" if errs2 else "")
        return [slug, result, steps, str(len(boot_errs)), str(len(play_errs)), first, last, str(len(found)), again]
    except subprocess.TimeoutExpired:
        return [slug, "closed", "-", "-", "-", "play_login.py timed out", "", "-", "-"]
    finally:
        subprocess.run([os.path.join(REPO, "scripts/play_stop.sh"), slug], cwd=REPO, capture_output=True)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("slugs", nargs="*")
    ap.add_argument("--all", action="store_true")
    ap.add_argument("--port", type=int, default=0, help="one port for every lib (default: each lib's own `port number` of config.fluffos, which some masters hard-code in connect())")
    ap.add_argument("--cmds", default="look;score;i;who;help")
    ap.add_argument("--out", default=os.path.join(SCR, "play_survey.tsv"))
    ap.add_argument("--skip", default=os.environ.get("SURVEY_SKIP", ""))
    ap.add_argument("--boot-timeout", type=int, default=240)
    ap.add_argument("--append", action="store_true", help="keep the lines already in --out (a resumed survey skips the slugs it holds)")
    ap.add_argument("--relogin", action="store_true", help="after the first visit and its quit, log in again as the same character (only when files named sweepzq* were saved): the ninth column is `result:console errors[:first]`")
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
            row = survey_one(s, a.port, a.cmds, a.boot_timeout, a.relogin)
            line = "\t".join(row)
            print(line, flush=True)
            fo.write(line + "\n")
            fo.flush()


if __name__ == "__main__":
    main()
