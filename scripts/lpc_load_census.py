#!/usr/bin/env python3
"""scripts/lpc_load_census.py [--n N] [--seed S] [--out DIR] [--cmds] SLUG...   |   scripts/lpc_load_census.py --report [--playable] [--out DIR]

A runtime census: load a seeded random sample of N objects (default 300) of each vendored lib in its own pristine tree
(tracked files plus the working-tree edits, like scripts/lpc_listcheck.sh) and classify the first error of each one that
does not load.  lpc_warnings.py compiles every file but never runs a create(), so an NPC that raises while it is being built
(a missing carried item, an unknown skill, a function the host lib never had) passes it; this sees those.

The sample is every tracked `.lpc` outside wizard, backup, include, data, log and adm directories (adm daemons load in a
boot order of their own) whose name is plain ASCII.  One result file per lib, `<out>/<slug>.json` (default
$LPC_SCRATCH/census): the sample size, the number that loaded, and per failing object its first error line.  `--report`
aggregates every result file (--playable: only libs whose meta.json says `playable`; the LDMud ports and
non-booting archives would swamp it): error classes (numbers, quoted names and paths blurred) by objects and libs, with an example.
--cmds loads every file of the wizard command directories (`/cmds/wiz`, `wizard`, `arch`, `adm`, `imm`, `creators`, ...) instead of a sample: the sample and the
mechanical fixers skip `/wiz/` and `/adm/` paths, so those commands were never compiled by anything but the whole-lib scan (default output $LPC_SCRATCH/census-cmds).
The driver runs under systemd-run with a 3 GB cap and a timeout when a user bus is available; otherwise plain `timeout` (Cloud Agent images without systemd). One lib takes about a minute plus the tree build."""
import collections
import json
import os
import random
import re
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SCR = os.environ.get("LPC_SCRATCH") or os.path.expanduser("~/.cache/lpc-scratch")
LPCC = os.environ.get("LPCC") or os.path.expanduser("~/src/fluffos/build-debug/src/lpcc")
SKIP = re.compile(r"/(u|w|wiz|wizard|wizards|open|players|backup|backups|old|bak|log|data|doc|docs|example|examples|include|adm|test|tests)/|[-_.](bak|old)/")
SAFE = re.compile(r"^[A-Za-z0-9_./-]+$")
# --cmds: the wizard command directories the sample leaves out (SKIP holds /wiz/, /wizard/ and /adm/): every one of them is loaded, none sampled
WIZCMD = re.compile(r"^/cmds/(wiz|wizard|wizards|arch|adm|imm|admin|creators?|immortal|debug|sys|dev|god|gods|app|ad|elder|sage|lord)/")


def _lpcc_cmd(timeout_s, *args):
    """Prefer a MemoryMax scope; fall back when no systemd user bus (Cloud Agent)."""
    capped = ["systemd-run", "--user", "--scope", "-q", "-p", "MemoryMax=3G", "-p", "MemorySwapMax=0",
              "timeout", str(timeout_s), *args]
    probe = subprocess.run(["systemd-run", "--user", "--scope", "-q", "true"], capture_output=True)
    if probe.returncode == 0:
        return capped
    return ["timeout", str(timeout_s), *args]


def sample(slug, n, seed, cmds=False):
    out = subprocess.run(["git", "ls-files", "-z", "--", f"libs/{slug}/work"], cwd=REPO, capture_output=True).stdout.split(b"\0")
    cand = []
    for f in out:
        try:
            p = f.decode("utf-8")
        except UnicodeDecodeError:
            continue
        if not p.endswith(".lpc"):
            continue
        rel = p[len(f"libs/{slug}/work"):]
        if cmds:
            if not WIZCMD.match(rel) or not SAFE.match(rel) or re.search(r"/(bak|old|backup|backups|test|tmp)/|[-_.](bak|old)(\.|$)", rel):
                continue
        elif SKIP.search(rel) or not SAFE.match(rel):
            continue
        cand.append(rel[:-4])
    random.Random(f"{slug}:{seed}").shuffle(cand)
    return sorted(cand[:n]), len(cand)


def build_tree(slug, dest):
    subprocess.run(["rm", "-rf", dest], check=True)
    subprocess.run([os.path.join(REPO, "scripts/pristine_tree.sh"), slug, "46300", dest], cwd=REPO, check=True,
                   stdout=subprocess.DEVNULL)
    os.makedirs(f"{dest}/libs/{slug}/work/log", exist_ok=True)
    sys.path.insert(0, os.path.join(REPO, "scripts"))
    import lpc_warnings as lw
    lw.sync_changes(slug, f"{dest}/libs/{slug}")


def parse(text):
    res = {}
    for blk in re.split(r"(?m)^===== ", text)[1:]:
        name = blk.split(" =====", 1)[0].strip()
        if not re.search(r"(?m)^FAIL ", blk):
            res[name] = None
            continue
        lines = [l for l in blk.split("\n")[1:] if l.strip()]
        first = next((l for l in lines if re.search(r"error:|执行时段错误|couldn't|No such|Undefined|does not exist|Illegal|Bad ", l)), None)
        if first is None:
            first = next((l for l in lines if not l.startswith(("FAIL", "PASS", "错误", "Fail to load"))), "(no message)")
        m = re.search(r"执行时段错误：\*?(.*)", first)
        res[name] = (m.group(1) if m else re.sub(r"^\S+?:\d+:\d+: error: ", "", first)).strip()[:200]
    return res


def census(slug, n, seed, out, cmds=False):
    work = f"{REPO}/libs/{slug}/work"
    if slug == "longyunmeng_binary" or not os.path.isdir(work) or os.path.exists(f"{work}/.git"):
        return None
    objs, total = sample(slug, n, seed, cmds)
    if not objs:
        return None
    dest = f"{SCR}/census-tree-{slug}"
    build_tree(slug, dest)
    r = subprocess.run(_lpcc_cmd(900, LPCC, "--batch", "config.fluffos"), cwd=f"{dest}/libs/{slug}",
                       input="\n".join(o.lstrip("/") for o in objs) + "\n",
                       capture_output=True, text=True, errors="replace")
    res = parse(r.stdout)
    fails = {k: v for k, v in res.items() if v}
    # the driver's own run-time warnings (`/file.lpc:12: Warning: member_array(int, string) searches BYTES ...`, once per call site per VM): kept per lib
    warns = sorted({re.sub(r"^/", "", l.strip()) for l in r.stdout.split("\n") if ": Warning: " in l})[:60]
    data = {"slug": slug, "candidates": total, "sampled": len(objs), "answered": len(res), "loaded": sum(1 for v in res.values() if v is None),
            "failed": fails, "warnings": warns}
    os.makedirs(out, exist_ok=True)
    json.dump(data, open(f"{out}/{slug}.json", "w", encoding="utf-8"), ensure_ascii=False, indent=0)
    subprocess.run(["rm", "-rf", dest])
    return data


def blur(msg):
    m = re.sub(r"'[^']*'", "'X'", msg)
    m = re.sub(r"\([^)]*\)", "(X)", m)
    return re.sub(r"[0-9]+", "N", m)[:110]


def playable(slug):
    try:
        return json.load(open(f"{REPO}/libs/{slug}/meta.json", encoding="utf-8")).get("wasm_status") == "playable"
    except (OSError, ValueError):
        return False


def report(out, only_playable=False):
    c = collections.Counter()
    libs = collections.defaultdict(set)
    ex = {}
    tot = ok = 0
    nlibs = 0
    for fn in sorted(os.listdir(out)):
        if not fn.endswith(".json"):
            continue
        d = json.load(open(f"{out}/{fn}", encoding="utf-8"))
        if only_playable and not playable(d["slug"]):
            continue
        nlibs += 1
        tot += d["answered"]
        ok += d["loaded"]
        for obj, msg in d["failed"].items():
            k = blur(msg)
            c[k] += 1
            libs[k].add(d["slug"])
            ex.setdefault(k, (d["slug"], obj, msg))
    print(f"{nlibs} libs, {tot} objects answered, {ok} loaded ({100 * ok // max(tot, 1)}%), {tot - ok} failed")
    wc = collections.Counter()
    for fn in sorted(os.listdir(out)):
        if fn.endswith(".json"):
            d = json.load(open(f"{out}/{fn}", encoding="utf-8"))
            if only_playable and not playable(d["slug"]):
                continue
            for w in d.get("warnings", []):
                wc[re.sub(r"^\S+?:\d+: ", "", w)[:100]] += 1
    for k, n in wc.most_common(8):
        print(f"{n:5d} run-time warnings | {k}")
    for k, n in c.most_common(30):
        print(f"{n:5d} {len(libs[k]):3d} libs | {k} | e.g. {ex[k][0]} {ex[k][1]}")


def main():
    args = sys.argv[1:]
    n, seed, out = 300, 1, f"{SCR}/census"
    for flag in ("--n", "--seed", "--out"):
        if flag in args:
            i = args.index(flag)
            val = args[i + 1]
            del args[i:i + 2]
            if flag == "--n":
                n = int(val)
            elif flag == "--seed":
                seed = int(val)
            else:
                out = val
    if "--report" in args:
        report(out, "--playable" in args)
        return
    cmds = "--cmds" in args
    if cmds:
        n = 10 ** 9
        if out == f"{SCR}/census":
            out = f"{SCR}/census-cmds"
    for slug in [a for a in args if not a.startswith("--")]:
        d = census(slug, n, seed, out, cmds)
        if d:
            print(f"{slug}: {d['loaded']}/{d['answered']} loaded ({d['sampled']} sampled of {d['candidates']})", flush=True)
        else:
            print(f"{slug}: skipped", flush=True)


if __name__ == "__main__":
    main()
