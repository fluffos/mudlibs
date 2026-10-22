#!/usr/bin/env python3
"""scripts/play_item_probe.py SLUG --account NAME:PW [--items N | --files /clone/a,/obj/b] [--clone-verb clone] [--shapes ,ID,me,all] [--port P] [--tag T] [--out FILE] [--no-boot] [--pace S]

The verbs an item registers in `init()`, typed with the item in hand (KB 08 10.16): boots the lib as a play unit (`play_boot.sh`, unless --no-boot), logs in as the
seeded administrator (`--account`, the README's `## Admin account`) and for every item file clones it, picks it up (`get ID`, `get all`), looks at it, and sends each verb the
file's own `add_action("fn", "verb")` lines name with a few argument shapes (`--shapes`, `ID` is the item's id) while it reads the driver console and the screen: the code a
player runs with `drink` / `eat` / `wield` / `apply` / `read` / `open` ... in the hand, which the bare-verb sweeps (they try the command directories, not an item's verbs)
and the static dead-handler scan (it proves the function exists, not that it runs) do not run.  `--items N` takes N item files at random from the lib's tracked `.lpc` files
(a file that registers a verb with a literal `add_action`, does not inherit a room / NPC / daemon base, outside wizard / backup / data / command / std directories, one per
directory, a seeded shuffle); `--files` takes a comma list.  Output: `ITEM path ids=.. verbs=..`, `FINDING [console|screen|clone|connection-closed|needed-escape|stuck-reconnect]`
(the `Sweep` classes of playsweep.py), `N findings in M items`.  Nothing here knows a lib but the administrator's `clone` verb (`--clone-verb`)."""
import argparse
import os
import random
import re
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import play_login  # noqa: E402
from mudplay import Console  # noqa: E402
from play_sweep_lib import own_port  # noqa: E402
from playsweep import DRIVER_BAD, Sweep  # noqa: E402

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SCR = os.environ.get("LPC_SCRATCH") or os.path.expanduser("~/.cache/lpc-scratch")
SKIP = re.compile(r"/(u|w|wiz|wizard|wizards|open|players|backup|backups|bak|old|test|tests|tmp|data|log|include|adm|secure|cmds|doc|docs|std|lib|inherit|feature|daemon|realms|www|kungfu|skills)/|[-_.](bak|old)")
NOTITEM = re.compile(rb"(?m)^[ \t]*inherit[ \t]+[^;\n]*(ROOM|room|NPC|npc|MONSTER|monster|LIVING|living|DAEMON|daemon|CHAR|char|VENDOR|vendor)")
ADD = re.compile(rb'(?<![A-Za-z_])add_action\(\s*"(\w+)"\s*,\s*"([^"\n$%]{1,20})"')
IDS = re.compile(rb'set_name\([^;]*?\(\{\s*"([^"\n]+)"|\bset\(\s*"id"\s*,\s*\(\{\s*"([^"\n]+)"|\bset_id\(\s*\(\{\s*"([^"\n]+)"|\bset_name\(\s*"[^"\n]*"\s*,\s*"([^"\n]+)"')
DANGER = {"quit", "shutdown", "suicide", "die", "dest", "destruct", "exec", "update", "reboot", "halt", "passwd", "save"}


def item_files(slug, n):
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
            b = open(f"{REPO}/{p}", "rb").read(60000)
        except OSError:
            continue
        if NOTITEM.search(b) or not ADD.search(b):
            continue
        cand.append(rel[:-4])
    random.Random(f"{slug}:item").shuffle(cand)
    picked, dirs = [], set()
    for rel in cand:
        d = os.path.dirname(rel)
        if d in dirs and len(cand) > 3 * n:
            continue
        picked.append(rel)
        dirs.add(d)
        if len(picked) == n:
            break
    return picked, len(cand)


def facts(slug, path):
    """(verbs, ids) the source of the item names"""
    try:
        b = open(f"{REPO}/libs/{slug}/work{path}.lpc", "rb").read(80000)
    except OSError:
        return [], []
    verbs = []
    for m in ADD.finditer(b):
        v = m.group(2).decode("utf-8", "replace")
        if v not in verbs and v not in DANGER:
            verbs.append(v)
    ids = []
    for m in IDS.finditer(b):
        w = next(g for g in m.groups() if g).decode("utf-8", "replace")
        if w not in ids:
            ids.append(w)
    return verbs, ids


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("slug")
    ap.add_argument("--account", required=True)
    ap.add_argument("--items", type=int, default=0)
    ap.add_argument("--files", default="")
    ap.add_argument("--clone-verb", default="clone")
    ap.add_argument("--shapes", default=",ID,me,all")
    ap.add_argument("--port", type=int, default=0)
    ap.add_argument("--tag", default=os.environ.get("PLAY_TAG", "it"))
    ap.add_argument("--no-boot", action="store_true")
    ap.add_argument("--out", default="")
    ap.add_argument("--pace", type=float, default=0.0)
    a = ap.parse_args()
    slug, port = a.slug, a.port or own_port(a.slug)
    files = [r for r in a.files.split(",") if r]
    if a.items:
        more, total = item_files(slug, a.items)
        files += more
        print(f"AUTO {len(more)} of {total} candidate item files", flush=True)
    if not files:
        sys.exit("no item files")
    suf = f"-{a.tag}" if a.tag else ""
    unit_out = f"{SCR}/play-{slug}{suf}.out"
    booted = False
    if not a.no_boot:
        env = dict(os.environ, PLAY_TAG=a.tag) if a.tag else os.environ
        r = subprocess.run([f"{REPO}/scripts/play_boot.sh", slug, str(port)], cwd=REPO, capture_output=True, text=True, env=env, timeout=400)
        if r.returncode != 0:
            sys.exit(f"boot failed: {r.stderr.strip()[-200:]}")
        booted = True
    nm, pw = a.account.split(":", 1)
    findings = []
    try:
        con = Console(unit_out)

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
        sw = Sweep(m, con, prompt_probe="look", prompt_rx=r".", relogin=login, idle=0.5 if not a.pace else a.pace, maxwait=4.0 if not a.pace else a.pace * 3, out=lambda s: print("   ", s[:300], flush=True))
        if a.pace:
            sw.use_sig = False
        done = 0
        for path in files:
            verbs, ids = facts(slug, path)
            base = os.path.basename(path)
            tid = (ids[0].split()[-1] if ids else base)
            out = sw.m.cmd(f"{a.clone_verb} {path}", idle=1.0, maxwait=8)
            cl = [c for c in con.new() if c.strip()]
            bad = [c for c in cl if DRIVER_BAD.search(c)]
            print(f"ITEM {path} ids={ids[:3]} verbs={verbs[:8]} clone={' '.join(out.split())[:60]!r} console={len(cl)} bad={len(bad)}", flush=True)
            if bad:
                for c in bad[:4]:
                    print("    ", c[:200], flush=True)
                findings.append(("clone", path, " | ".join(x[:160] for x in bad[:4]), " ".join(out.split())[-150:]))
                continue
            for pre in (f"get {tid}", "get all", f"look {tid}", f"i"):
                sw.one(pre)
            shapes = [s.replace("ID", tid) for s in a.shapes.split(",")]
            before = len(sw.findings)
            sw.run(verbs, shapes=shapes, skip=DANGER)
            for f in sw.findings[before:]:
                findings.append((f[0], path + " :: " + f[1], " | ".join(x[:140] for x in f[3][:3]), f[2][-150:]))
            done += 1
        sw.report()
        print(f"{len(findings)} findings in {done} items", flush=True)
        if a.out:
            with open(a.out, "w", encoding="utf-8") as f:
                for kind, p, cons, scr in findings:
                    f.write("\t".join([kind, p, cons.replace("\t", " ").replace("\n", " ")[:300], scr.replace("\t", " ").replace("\n", " ")[:200]]) + "\n")
    finally:
        if booted:
            subprocess.run([f"{REPO}/scripts/play_stop.sh", slug + (f"-{a.tag}" if a.tag else "")], cwd=REPO, capture_output=True)


if __name__ == "__main__":
    main()
