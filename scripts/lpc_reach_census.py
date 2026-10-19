#!/usr/bin/env python3
"""scripts/lpc_reach_census.py SLUG... [--max-rooms N] [--out DIR] [--load] [--dead]

What a visitor can reach, and whether it loads (KB 08 section 10.15).  scripts/lpc_load_census.py samples objects at random,
dead code and backup trees included; this walks the map from the lib's start room (`START_ROOM` / `ENTRY_ROOM` of its
headers) along the literal exits of each room (`"north": __DIR__"x"`, `"/d/y/z"`, `add_exit()`), and collects what the
rooms hold: the `objects` entries (`__DIR__"npc/guard": 2`) and the literal `new()` / `clone_object()` paths of the room
files.  Every room, NPC and item found this way is something a player meets.

Without --load only the static picture is printed: `REACH slug rooms=N objects=M dead_exits=K start=/d/...`.  With --load
each file is also loaded under catch() in a fresh pristine tree (scripts/pristine_tree.sh, the working-tree changes synced in,
memory capped) and the failures are printed as `FAIL slug depth path error`, nearest to the start first; the totals line is
`LOAD slug rooms ok/total objects ok/total`.  --dead lists the exits of reachable rooms that lead to no file
(`DEAD slug room dir -> target`: a player is stranded there).  --out DIR keeps DIR/SLUG.rooms / .objs (one `path` per line) and
DIR/SLUG.out (the raw `RT path -> result` lines).  A lib with no start room, or whose start room is not a file, is skipped
(`NOSTART`)."""
import collections
import os
import re
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import lpc_fix_dead_exits as D  # noqa: E402
from lpc_fix_void_return import code_mask  # noqa: E402

REPO = D.REPO
SCRATCH = os.environ.get("LPC_SCRATCH") or os.path.expanduser("~/.cache/lpc-scratch")
START = re.compile(rb'(?m)^[ \t]*#[ \t]*define[ \t]+(START_ROOM|ENTRY_ROOM|LOGIN_ROOM|DEFAULT_START|NEW_START|PLAYER_START)[ \t]+"(/[^"\n]+)"')
OBJ = re.compile(rb'(?:(__DIR__)\s*"([^"\n]+)"|"(/[^"\n]+)")\s*:\s*[0-9(]')
NEW = re.compile(rb'(?:\bnew|\bclone_object|\bcarry_object|\bunew)\s*\(\s*(?:(__DIR__)\s*"([^"\n]+)"|"(/[^"\n]+)")')


def start_room(slug, files):
    found = {}
    out = subprocess.run(["git", "grep", "-h", "-E", r"^\s*#\s*define\s+(START_ROOM|ENTRY_ROOM|LOGIN_ROOM|DEFAULT_START|NEW_START|PLAYER_START)\s+\"", "--", f"libs/{slug}/work"],
                         cwd=REPO, capture_output=True).stdout
    for m in START.finditer(out):
        found.setdefault(m.group(1).decode(), m.group(2).decode("utf-8", "replace"))
    for k in ("START_ROOM", "ENTRY_ROOM", "LOGIN_ROOM", "DEFAULT_START", "NEW_START", "PLAYER_START"):
        if k in found:
            return D.stem(found[k])
    return None


def room_contents(slug, rel):
    """-> (objects, new paths): stems named by the room file's `objects` mapping and by literal new()/clone_object()"""
    try:
        b = open(f"{REPO}/libs/{slug}/work{rel}", "rb").read()
    except OSError:
        return []
    mask = code_mask(b, heredoc=True)
    fdir = rel.rsplit("/", 1)[0]
    res = []
    for rx in (OBJ, NEW):
        for m in rx.finditer(b):
            if not D.in_code(mask, b, m.start()):
                continue
            if m.group(1):
                name = m.group(2).decode("utf-8", "replace")
                res.append(D.stem(os.path.normpath(fdir + "/" + (name[1:] if name.startswith("/") else name))))
            else:
                res.append(D.stem(os.path.normpath(m.group(3).decode("utf-8", "replace"))))
    return res


def main():
    args = sys.argv[1:]
    load = "--load" in args
    show_dead = "--dead" in args
    maxrooms = 30000
    outdir = None
    if "--max-rooms" in args:
        i = args.index("--max-rooms")
        maxrooms = int(args[i + 1])
        del args[i:i + 2]
    if "--out" in args:
        i = args.index("--out")
        outdir = args[i + 1]
        del args[i:i + 2]
    only = [a for a in args if not a.startswith("--")]
    by = D.tracked()
    for slug in only:
        if slug not in by or os.path.exists(f"{REPO}/libs/{slug}/work/.git"):
            continue
        files = by[slug]
        stems = {D.stem(f) for f in files}
        st = start_room(slug, files)
        if not st or st not in stems:
            print(f"NOSTART {slug}: start room {st}")
            continue
        depth = {st: 0}
        queue = collections.deque([st])
        objs = {}
        dead = 0
        while queue and len(depth) < maxrooms:
            r = queue.popleft()
            ex, _b = D.parse_exits(slug, r + ".lpc")
            for d, tgt, s, e, kind, text in ex:
                if tgt in stems:
                    if tgt not in depth:
                        depth[tgt] = depth[r] + 1
                        queue.append(tgt)
                else:
                    dead += 1
                    if show_dead:
                        print(f"DEAD  {slug} {r} {d} -> {tgt}")
            for o in room_contents(slug, r + ".lpc"):
                if o in stems and o not in depth and o not in objs:
                    objs[o] = depth[r]
        print(f"REACH {slug} rooms={len(depth)} objects={len(objs)} dead_exits={dead} start={st}")
        if outdir:
            os.makedirs(outdir, exist_ok=True)
            open(f"{outdir}/{slug}.rooms", "w", encoding="utf-8").write("\n".join(sorted(x[1:] for x in depth)) + "\n")
            open(f"{outdir}/{slug}.objs", "w", encoding="utf-8").write("\n".join(sorted(x[1:] for x in objs)) + "\n")
        if not load:
            continue
        todo = sorted(depth, key=lambda x: depth[x]) + sorted(objs, key=lambda x: objs[x])
        res = load_paths(slug, [x[1:] for x in todo])
        ok = {"room": 0, "obj": 0}
        tot = {"room": len(depth), "obj": len(objs)}
        fails = []
        for x in todo:
            kind = "room" if x in depth else "obj"
            r = res.get(x[1:])
            if r is None and x[1:] not in res:
                continue
            if r is None:
                ok[kind] += 1
            else:
                fails.append((depth.get(x, objs.get(x, 0)), kind, x, r[:110]))
        if outdir:
            with open(f"{outdir}/{slug}.out", "w", encoding="utf-8") as fh:
                for x in todo:
                    if x[1:] in res:
                        fh.write(f"RT {x[1:]} -> {res[x[1:]] or 'ok'}\n")
        for dpt, kind, p, r in sorted(fails)[:200]:
            print(f"FAIL  {slug} {dpt} {kind} {p} {r}")
        print(f"LOAD  {slug} rooms {ok['room']}/{tot['room']} objects {ok['obj']}/{tot['obj']} (not answered: {sum(1 for x in todo if x[1:] not in res)})")


CATCH_T = '''void create() {
  object o; mixed e; string f;
  seteuid(getuid());
  foreach (f in ({
    %s
  })) {
    o = 0;
    e = catch(o = load_object(f));
    debug_message(sprintf("RT %%s -> %%s", f, stringp(e) ? replace_string(e, "\\n", " | ") : (o ? "ok" : "NOLOAD")));
  }
}
'''


def load_paths(slug, paths):
    """-> {path: first error or None}: the paths loaded in a pristine tree of the lib (working-tree edits included), the
    `(no message)` ones again under catch()"""
    import lpc_load_census as C
    dest = f"{SCRATCH}/reach-tree-{slug}"
    C.build_tree(slug, dest)
    res = {}
    cmd = ["systemd-run", "--user", "--scope", "-q", "-p", "MemoryMax=3G", "-p", "MemorySwapMax=0", "timeout", "1800", C.LPCC, "--batch", "config.fluffos"]
    cwd = f"{dest}/libs/{slug}"
    for i in range(0, len(paths), 600):
        r = subprocess.run(cmd, cwd=cwd, input="\n".join(paths[i:i + 600]) + "\n", capture_output=True, text=True, errors="replace")
        res.update(C.parse(r.stdout))
    quiet = [p for p, v in res.items() if v and "(no message)" in v]
    if quiet:
        work = f"{cwd}/work"
        os.makedirs(f"{work}/zz_rt", exist_ok=True)
        body = ",\n    ".join('"%s"' % p for p in quiet)
        open(f"{work}/zz_rt/t.lpc", "w").write(CATCH_T % body)
        r = subprocess.run(cmd, cwd=cwd, input="zz_rt/t\n", stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True, errors="replace")
        for l in r.stdout.split("\n"):
            m = re.match(r"RT (\S+(?: \(\d+\))?) -> (.*)", l)
            if m and m.group(1) in res and m.group(2).strip() != "ok":
                res[m.group(1)] = re.sub(r"\s*\|.*$", "", m.group(2))[:200]
    subprocess.run(["rm", "-rf", dest])
    return res


if __name__ == "__main__":
    main()
