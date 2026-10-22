#!/usr/bin/env python3
"""scripts/play_combat_auto.py SLUG [PORT] [--files N] [--seconds N]

The combat probe's clone mode (KB 08 10.16) with nothing to type: reads the lib's seeded administrator from its README, picks up to --files (6) NPC files of the lib and runs
`play_combat_probe.py SLUG --account NAME:PW --clone FILE,FILE,..` -- each file is cloned into the administrator's room and attacked at once, the driver console is read while
the fight runs, every driver line is a `FINDING [clone]` (the NPC does not compile / its `create()` raises) or a `FINDING [screen]` (the fight screen names an error).

NPC files: a tracked `.lpc` of `libs/SLUG/work` whose first 8 KB has `inherit ...MONSTER|NPC|monster|npc|GUARD|LIVING...`, one per directory (a seeded shuffle, the same files on
every run), outside wizard / backup / data / std / cmds / secure directories.  Admin: `gen_site_index.parse_admin()`, then the README's English bullets (`- **id**: `x``
`- **password**: `y``), then the prose form `fluffos` / `Mud@2026`.  A lib with no admin account in its README, no NPC file, or whose login the robot cannot answer exits 1 with
the reason on the last line: that lib is not tested (the exit code is the answer, not "clean").  Discworld and its forks need `--pace 2.5` (one command per heart beat): added by
the slug.  Output TSV: `$LPC_SCRATCH/combat/SLUG.tsv`.  One lib at a time (the nitan family refuses a second new character from the same IP; ports are per run)."""
import importlib.util
import os
import random
import re
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SCR = os.environ.get("LPC_SCRATCH") or os.path.expanduser("~/.cache/lpc-scratch")

SKIP = re.compile(r"/(u|w|wiz|wizard|wizards|open|players|backup|backups|old|bak|log|data|doc|docs|example|examples|include|adm|test|tests|std|lib|inherit|cmds|secure|realms|tmp|student|ftp|www)/|[-_.](bak|old)")
INH = re.compile(rb"(?m)^[ \t]*inherit[ \t]+[^;\n]*(MONSTER|NPC|monster|npc|GUARD|LIVING)")


def admin_of(slug):
    spec = importlib.util.spec_from_file_location("gsi", os.path.join(REPO, "scripts", "gen_site_index.py"))
    mod = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(mod)
    name, pw = mod.parse_admin(slug)
    if name and pw:
        return name, pw
    try:
        readme = open(os.path.join(REPO, "libs", slug, "README.md"), encoding="utf-8", errors="replace").read()
    except OSError:
        return None, None
    mm = re.search(r"(?mi)^[ \t]*[-*][ \t]+\*\*(?:id|账号|帐号|用户名)\*\*[ \t]*[:：][ \t]*`([^`]+)`.*?^[ \t]*[-*][ \t]+\*\*(?:password|密码)\*\*[ \t]*[:：][ \t]*`([^`]+)`", readme, re.S)
    if mm:
        return mm.group(1), mm.group(2)
    mm = re.search(r"`(fluffos)`\s*/\s*`([^`]+)`", readme)
    if mm:
        return mm.group(1), mm.group(2)
    if re.search(r"`fluffos`\s*/\s*see the standard", readme):
        return "fluffos", "Mud@2026"
    return None, None


def npc_files(slug, n):
    root = f"libs/{slug}/work"
    files = subprocess.run(["git", "ls-files", "-z", "--", root], cwd=REPO, capture_output=True).stdout.split(b"\0")
    cand = []
    for f in files:
        try:
            p = f.decode("utf-8")
        except UnicodeDecodeError:
            continue
        rel = p[len(root):]
        if not rel.endswith(".lpc") or SKIP.search(rel) or not re.match(r"^[A-Za-z0-9_./-]+$", rel):
            continue
        try:
            head = open(os.path.join(REPO, p), "rb").read(8000)
        except OSError:
            continue
        if INH.search(head):
            cand.append(rel)
    random.Random(slug).shuffle(cand)
    picked, dirs = [], set()
    for rel in cand:
        d = os.path.dirname(rel)
        if d in dirs and len(cand) > 6:
            continue
        picked.append(rel[:-4])
        dirs.add(d)
        if len(picked) == n:
            break
    return picked


def main():
    argv = sys.argv[1:]
    opts = {"--files": "6", "--seconds": "20"}
    args = []
    i = 0
    while i < len(argv):
        if argv[i] in opts and i + 1 < len(argv):
            opts[argv[i]] = argv[i + 1]
            i += 2
        else:
            args.append(argv[i])
            i += 1
    if not args:
        sys.exit(__doc__)
    slug = args[0]
    port = int(args[1]) if len(args) > 1 else 47900
    name, pw = admin_of(slug)
    if not name or not pw:
        sys.exit(f"{slug}: no admin account in the README")
    picked = npc_files(slug, int(opts["--files"]))
    if not picked:
        sys.exit(f"{slug}: no NPC files found")
    out_dir = os.path.join(SCR, "combat")
    os.makedirs(out_dir, exist_ok=True)
    cmd = ["python3", os.path.join(REPO, "scripts", "play_combat_probe.py"), slug, "--port", str(port), "--tag", "auto", "--account", f"{name}:{pw}",
           "--clone", ",".join(picked), "--seconds", opts["--seconds"], "--targets", "3", "--out", os.path.join(out_dir, f"{slug}.tsv")]
    if slug.startswith(("discworld", "dw_")):
        cmd += ["--pace", "2.5"]
    print("RUN", " ".join(cmd[2:]), flush=True)
    sys.exit(subprocess.run(cmd, cwd=REPO).returncode)


if __name__ == "__main__":
    main()
