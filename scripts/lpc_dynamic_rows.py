#!/usr/bin/env python3
"""scripts/lpc_dynamic_rows.py [--apply] [SLUG...]      (no SLUG: every vendored lib)

The `dynamic_location` / `dynamic_quest` tables of the xkx / Fengyun / Haiyang / Journey-to-the-West room-quest daemons
(`adm/daemons/questd.lpc`, `taskd.lpc`, `natured.lpc`, `teamjob.lpc` ...) are plain text, one source path per line:

    /d/baihuagu/baihuagu.c            (a room pool; the daemon does `load_object(roomlines[random(sizeof(roomlines))])`)
    /d/obj/quest/baowu1.c             (an item list: `new(quest)`, then `quest->set(...)` / `->move(...)`)

The archives wrote every row with the `.c` of the original sources.  The extraction renamed the files to `.lpc` and an explicit
extension is resolved exactly (KB 03 section 4.2), so `load_object("/d/x.c")` is 0 and `new("/d/obj/quest/x.c")` is 0: a daemon
that call_others the result raised in create() and never loaded (and took the cron daemon, the `give` hook and every
`QUEST_D->...` call with it); one that tests the result silently never spread a quest (xyj2006n `questd.lpc:153`, hy5
`natured.lpc` `base_name(room2)`).  No consumer of these tables mentions `.c` in code (checked over 152 files of 78 libs), so
the rows themselves are the defect: a row `X.c` whose file does not exist while `X.lpc` does becomes `X.lpc` (what
`xysylmhb` and `xlqy_new2007` already carry).  `children()`, `find_object()` and `base_name()` do not care about the
extension; only `load_object()` and `new()` do.

Only a table that the lib's own code reads with a literal `read_file("...")` / `read_table("...")` is touched (162 of the 309 files with
`.c` rows were copies and backups nothing reads: `dynamic_locationff`, `d/obj/quest/*` next to a `/kungfu/*` the daemon uses).

Rows whose file exists in neither spelling (content gaps of the archive: `fyzfqyy` has 2268) are counted and left, as are
rows that are not a bare path (a tab table read by `read_table()` has other columns), blank and `#` lines.  Edits are
byte-exact and keep every line ending.  Without --apply it prints the plan.  A lib whose work/ is a gitlink is left."""
import os
import re
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
args = sys.argv[1:]
apply_ = "--apply" in args
slugs = [a for a in args if a != "--apply"]
SOURCE_EXT = (".lpc", ".h", ".c", ".o", ".inc")
ROW = re.compile(rb"^(/?[A-Za-z0-9_\-./]+?)(?:\.c)+$")


def git(*a):
    return subprocess.run(["git", "-C", REPO] + list(a), capture_output=True).stdout


if not slugs:
    slugs = sorted(d for d in os.listdir(f"{REPO}/libs") if os.path.isdir(f"{REPO}/libs/{d}/work"))

def referenced():
    """{(slug, work-relative path)} of the tables a lib's code reads with a literal read_file() / read_table()"""
    ref = set()
    out = subprocess.run(["git", "-C", REPO, "grep", "-I", "-o", "-E", "--no-color", "-e",
                          r'read_(file|table)[ \t]*\([ \t]*"[^"]*dynamic_(location|quest)[^"]*"', "--", "libs/"],
                         capture_output=True).stdout
    for line in out.split(b"\n"):
        m = re.match(rb"libs/([^/]+)/work/[^:]*:.*?\"([^\"]+)\"", line)
        if m:
            ref.add((m.group(1).decode(), m.group(2).decode().lstrip("/")))
    return ref


REF = referenced()
total = [0, 0, 0]
for slug in slugs:
    w = f"libs/{slug}/work"
    if any(l.startswith(b"160000") for l in git("ls-files", "-s", "--", w).split(b"\n")):
        print(f"{slug}: work/ is a gitlink: left")
        continue
    work = f"{REPO}/{w}"
    files = [f for f in git("ls-files", "-z", "--", w).decode("utf-8", "surrogateescape").split("\0") if f]
    fixed = dead = files_changed = 0
    dead_ex = []
    for rel in files:
        base = os.path.basename(rel)
        if not (base.startswith("dynamic_location") or base.startswith("dynamic_quest")) or base.endswith(SOURCE_EXT):
            continue
        path = f"{REPO}/{rel}"
        if not os.path.isfile(path) or (slug, rel.split("/work/", 1)[1]) not in REF:
            continue
        raw = open(path, "rb").read()
        out, changed = [], False
        for line in raw.split(b"\n"):
            cr = b"\r" if line.endswith(b"\r") else b""
            body = line[:-1] if cr else line
            m = ROW.match(body)
            if m:
                stem = m.group(1).decode("utf-8", "surrogateescape")
                prefix = work if stem.startswith("/") else work + "/"
                if os.path.isfile(prefix + stem + ".c") and body.endswith(b".c") and not body.endswith(b".c.c"):
                    pass
                elif os.path.isfile(prefix + stem + ".lpc"):
                    body = m.group(1) + b".lpc"
                    fixed += 1
                    changed = True
                else:
                    dead += 1
                    if len(dead_ex) < 3:
                        dead_ex.append(stem + ".c")
            out.append(body + cr)
        if changed:
            files_changed += 1
            if apply_:
                open(path, "wb").write(b"\n".join(out))
    if fixed or dead:
        print(f"{slug}: {fixed} row(s) in {files_changed} file(s) `.c` -> `.lpc`; {dead} row(s) name a file that is not there"
              + (f" (e.g. {', '.join(dead_ex)})" if dead_ex else ""))
    total[0] += fixed
    total[1] += dead
    total[2] += files_changed
print(f"total: {total[0]} row(s) in {total[2]} file(s), {total[1]} dead row(s)" + ("" if apply_ else " (plan; --apply writes)"))
