#!/usr/bin/env python3
"""scripts/lpc_restore_bases.py [SLUG...] [--min-rel N] [--apply] [--list DIR] [--refresh]

A base class the lib never shipped, restored from a sibling lib (KB 04 section 6.15).  `inherit INDOOR_ROOM;` where no header
of the lib defines `INDOOR_ROOM`, or `inherit "/std/room/class_guild";` where the file is not in the lib, and every object that
inherits it fails to load.  scripts/lpc_restore_macros.py already restores the macro when the lib has the file; this tool
handles the rest, where the file itself is missing (riftsds' 213 `INDOOR_ROOM` rooms, wxddym's `WQA_ROOM`, zzfy's `BOOK`).

The donor is a lib that has the file (for a macro: a lib whose header defines it as that path) and is a sibling of this one:
relatedness is the number of files the two libs carry byte for byte (same path, same blob) that at most 60 libs carry, so
shared boilerplate does not count; --min-rel (default 100) is the least a donor must share.  A macro line and the donor's
file are added (the file at the same path, the donor's bytes, so the donor's line endings stay); a macro the lib already defines
is left alone, and a path the lib already has is never overwritten.  Files this adds are untracked: run `git add -N` on them
(the listcheck sees them), verify with scripts/lpc_listcheck.sh on the base and the objects that inherit it, and take back what
does not load.  The base may itself inherit a base the lib lacks: run the tool again, it finds that one too.
Without --apply the plan is printed (ADOPT lines); `--list DIR` writes DIR/bases-SLUG.list (the base files and their users,
`/path.lpc` per line) for the load check; `--refresh` rebuilds the relatedness cache.
`--skip SLUG,SLUG` leaves libs out (young hobby repos the museum does not restore).  --apply records what it added in
$LPC_SCRATCH/bases-applied-SLUG.json; `--undo SLUG /path[ /path...]` takes a base back (the file, its macro line)."""
import collections
import json
import os
import pickle
import re
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import lpc_restore_macros as R  # noqa: E402

REPO = R.REPO
SCRATCH = os.environ.get("LPC_SCRATCH") or os.path.expanduser("~/.cache/lpc-scratch")
CACHE = os.path.join(SCRATCH, "relatedness.pkl")
INHL = re.compile(rb'(?m)^[ \t]*inherit[ \t]+"([^"\n]+)"[ \t]*;')


def relatedness(refresh):
    if not refresh and os.path.exists(CACHE):
        return pickle.load(open(CACHE, "rb"))
    out = subprocess.run(["git", "ls-files", "-s", "-z", "--", "libs"], cwd=REPO, capture_output=True).stdout.split(b"\0")
    by = collections.defaultdict(dict)
    for e in out:
        if not e:
            continue
        try:
            meta, path = e.split(b"\t", 1)
            p = path.decode("utf-8")
        except (ValueError, UnicodeDecodeError):
            continue
        parts = p.split("/", 3)
        if len(parts) < 4 or parts[2] != "work" or parts[1] == "longyunmeng_binary" or not p.endswith((".lpc", ".h", ".c")):
            continue
        by[parts[1]][parts[3]] = meta.split()[1]
    idx = collections.defaultdict(list)
    for s, d in by.items():
        for p, sha in d.items():
            idx[(p, sha)].append(s)
    rel = collections.defaultdict(int)
    for libs in idx.values():
        if 2 <= len(libs) <= 60:
            for a in libs:
                for b in libs:
                    if a != b:
                        rel[(a, b)] += 1
    res = (dict(rel), {s: len(d) for s, d in by.items()})
    os.makedirs(SCRATCH, exist_ok=True)
    pickle.dump(res, open(CACHE, "wb"))
    return res


def rejected(slug):
    """bases an earlier run took back (they load but do not fit): never proposed again"""
    p = f"{SCRATCH}/bases-rejected-{slug}.json"
    return set(json.load(open(p))) if os.path.exists(p) else set()


def undo(slug, paths):
    """take back adopted bases: delete the file, drop the macro line the manifest names"""
    mf = json.load(open(f"{SCRATCH}/bases-applied-{slug}.json"))
    hdr = f"{REPO}/libs/{slug}/work{mf['header']}" if mf.get("header") else None
    for P in paths:
        ent = next((e for e in mf["added"] if e["path"] == P), None)
        if not ent:
            print(f"UNDO  {slug} {P}: not in the manifest")
            continue
        f = f"{REPO}/libs/{slug}/work{P}.lpc"
        if os.path.exists(f):
            subprocess.run(["git", "reset", "-q", "--", f"libs/{slug}/work{P}.lpc"], cwd=REPO, capture_output=True)
            os.remove(f)
        if ent.get("macro") and hdr:
            b = open(hdr, "rb").read()
            out = re.sub(rb"(?m)^#define %s +\"%s\"\r?\n" % (re.escape(ent["macro"].encode()), re.escape(P.encode())), b"", b)
            if out != b:
                open(hdr, "wb").write(out)
        mf["added"] = [e for e in mf["added"] if e["path"] != P]
        rj = rejected(slug)
        rj.add(P)
        json.dump(sorted(rj), open(f"{SCRATCH}/bases-rejected-{slug}.json", "w"))
        print(f"UNDO  {slug} {P}")
    json.dump(mf, open(f"{SCRATCH}/bases-applied-{slug}.json", "w"), indent=1)


def norm(path):
    q = path.lstrip("/")
    q = q[:-2] if q.endswith(".c") else q[:-4] if q.endswith(".lpc") else q
    return "/" + q


def main():
    args = sys.argv[1:]
    apply = "--apply" in args
    refresh = "--refresh" in args
    min_rel = 100
    listdir = None
    if "--min-rel" in args:
        i = args.index("--min-rel")
        min_rel = int(args[i + 1])
        del args[i:i + 2]
    if "--list" in args:
        i = args.index("--list")
        listdir = args[i + 1]
        del args[i:i + 2]
    skip = set()
    if "--skip" in args:
        i = args.index("--skip")
        skip = set(args[i + 1].split(","))
        del args[i:i + 2]
    if "--undo" in args:
        i = args.index("--undo")
        undo(args[i + 1], args[i + 2:])
        return
    only = [a for a in args if not a.startswith("--") and a not in skip]
    rel, _size = relatedness(refresh)
    by = R.tracked()
    fileset = {s: set(f) for s, f in by.items()}
    scans = {s: R.lib_scan(s, fileset[s]) for s in (only or by) if s in by and s not in skip and not os.path.exists(f"{REPO}/libs/{s}/work/.git")}
    defs = collections.defaultdict(list)           # macro -> [(slug, path)]
    for slug, fs in by.items():
        for r in fs:
            if not r.endswith(".h") or R.SKIP.search(r):
                continue
            try:
                b = open(f"{REPO}/libs/{slug}/work{r}", "rb").read()
            except OSError:
                continue
            for m in R.DEFQ.finditer(b):
                defs[m.group(1).decode()].append((slug, m.group(2).decode("utf-8", "replace")))
    have_path = collections.defaultdict(set)       # normalized path -> libs that have it
    for slug, fs in fileset.items():
        for r in fs:
            if r.endswith(".lpc"):
                have_path[r[:-4]].add(slug)
    tot_pairs = tot_users = 0
    for T in sorted(only or scans):
        if T not in scans:
            continue
        defs_T, miss, texts = scans[T]
        plan = []                                  # (macro or None, path, donor, rel, users)
        rej = rejected(T)
        for ident, users in sorted(miss.items(), key=lambda kv: -len(kv[1])):
            if ident in defs_T:
                continue
            name = ident.decode()
            best = None
            for D, path in defs.get(name, []):
                if D == T:
                    continue
                P = norm(path)
                if P in rej:
                    continue
                if P in have_path and D in have_path[P] and T not in have_path[P]:
                    r = rel.get((T, D), 0)
                    if best is None or r > best[0]:
                        best = (r, D, P)
            if best and best[0] >= min_rel:
                plan.append((name, best[2], best[1], best[0], users))
        # literal inherits of files this lib lacks
        lit = collections.defaultdict(list)
        for rr in fileset[T]:
            if not rr.endswith(".lpc") or R.SKIP.search(rr):
                continue
            try:
                b = open(f"{REPO}/libs/{T}/work{rr}", "rb").read()
            except OSError:
                continue
            if b"inherit" not in b:
                continue
            for m in INHL.finditer(b):
                P = norm(m.group(1).decode("utf-8", "replace"))
                if P not in {x[:-4] for x in fileset[T] if x.endswith(".lpc")}:
                    lit[P].append(rr)
        for P, users in sorted(lit.items(), key=lambda kv: -len(kv[1])):
            best = None
            for D in have_path.get(P, ()):
                if D != T and P not in rej:
                    r = rel.get((T, D), 0)
                    if best is None or r > best[0]:
                        best = (r, D)
            if best and best[0] >= min_rel:
                plan.append((None, P, best[1], best[0], users))
        if not plan:
            continue
        hdr = R.global_header(T, fileset[T])
        add_macros, adopt = [], {}
        for name, P, D, r, users in plan:
            print(f"ADOPT {T} {name or '(literal)'} {P}.lpc <- {D} (rel {r}, {len(users)} user(s))")
            adopt[P] = D
            if name:
                add_macros.append((name, P))
            tot_pairs += 1
            tot_users += len(users)
        if add_macros and not hdr:
            print(f"NOHDR {T}: no global include file to put " + ", ".join(m for m, _ in add_macros))
        if listdir:
            os.makedirs(listdir, exist_ok=True)
            seen = sorted({u for *_, users in plan for u in users} | {P + ".lpc" for P in adopt})
            open(f"{listdir}/bases-{T}.list", "w", encoding="utf-8").write("\n".join(seen) + "\n")
        if not apply:
            continue
        manifest = []
        for P, D in adopt.items():
            dst = f"{REPO}/libs/{T}/work{P}.lpc"
            if os.path.exists(dst):
                continue
            os.makedirs(os.path.dirname(dst), exist_ok=True)
            open(dst, "wb").write(open(f"{REPO}/libs/{D}/work{P}.lpc", "rb").read())
            manifest.append({"path": P, "donor": D, "macro": next((m for m, q in add_macros if q == P), None),
                             "users": sorted({u for _n, q, _d, _r, us in plan if q == P for u in us})[:60]})
        if add_macros and hdr:
            p = f"{REPO}/libs/{T}/work{hdr}"
            b = open(p, "rb").read()
            eol = b"\r\n" if b"\r\n" in b else b"\n"
            lines = b.split(b"\n")
            last = -1
            for i, l in enumerate(lines):
                if re.match(rb"[ \t]*#[ \t]*define\b", l):
                    last = i
                    while lines[last].rstrip(b"\r").endswith(b"\\") and last + 1 < len(lines):
                        last += 1
            new = [("#define %-24s \"%s\"" % (n, pth)).encode("utf-8") + (b"\r" if eol == b"\r\n" else b"") for n, pth in add_macros]
            if last < 0:
                lines = lines + new if not b.endswith(b"\n") else lines[:-1] + new + [b""]
            else:
                lines[last + 1:last + 1] = new
            open(p, "wb").write(b"\n".join(lines))
        if manifest:
            os.makedirs(SCRATCH, exist_ok=True)
            mp = f"{SCRATCH}/bases-applied-{T}.json"
            old = json.load(open(mp)) if os.path.exists(mp) else {"header": hdr, "added": []}
            have = {e["path"] for e in manifest}
            old["added"] = [e for e in old["added"] if e["path"] not in have] + manifest
            old["header"] = old.get("header") or hdr
            json.dump(old, open(mp, "w"), indent=1)
    print(f"{tot_pairs} base(s) for {tot_users} user file(s)" + ("" if apply else " (plan only; --apply writes)"))


if __name__ == "__main__":
    main()
