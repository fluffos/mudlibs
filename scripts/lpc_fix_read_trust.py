#!/usr/bin/env python3
"""scripts/lpc_fix_read_trust.py [--apply] [--list] SLUG [SLUG...]

An ES2-style `adm/daemons/securityd.lpc` keeps its read rules in tables (`trusted_read`, `exclude_read`) and only trusts the wizard statuses by default: the rest of the
rules were saved by the admin in `data/static/securityd.o`, which no archive of these libs ships.  Every object that is not a wizard, a room, an NPC, an item (euid `Domain`, from
`creator_file()` of `/d`, `/obj`, `/clone`) then reads NOTHING: `read_file()` answers 0 from the master's `valid_read()` (a denied read raises nothing, it just answers 0).  23 libs
show it (`read_file("/d/<area>/x.lpc", 1, 1)` from an object at `/d/<area>/`: hell, nt1, nte, ntii, revive, sjshv2578bb, wlqxcmudlib, wxddym, xkxc98sj, xkxz2, xyj20032, yanhuangwuhun,
yhwhckdm, yhwhpublicfi, yhyxs, zhonghua2, zhongjidiyu, zhyx, zjdy2008wzb, zjdyaryl, zjdywzb, zjdyzj, zjmudhell): the 36 chapters of the Red Chamber and the Journey to the West that
`d/obj/books-nonskill/hmeng*.lpc` print through `start_more(read_file(..))` (xyj20032, sjshv2578bb), the poem club `/d/city/clubpoem` that cannot even load (its `new_poem()` runs
`sscanf(read_file(..), ..)` from `init()`), every wxddym maze (`read_file(__DIR__ "maze.map")`: the maze rooms get no map), nt1's quest killers and card game help (`__DIR__ "fam1"`,
`__DIR__ "helppai"`).  The later Nitan versions solved it in code (nt6: `(func == "restore_object" || func == "read_file") && sscanf(file, "/d/%*s") && in_same_dir(file, base_name(user))`).

This adds the same kind of rule to `valid_read()` of the lib, in front of its `if (!euid) return 0;`: a `read_file()` of a file under `/d/` by a `Domain` object, and a `read_file()` of a file in
the directory of the reading object (`__DIR__ "x"`, a subdirectory included).  Nothing else changes: `/data`, `/adm`, `/log`, `/u` stay what the lib's rules make them, and a wizard
(not `Domain`) reads what he read.  Idempotent (the block carries a marker).  Dry run unless `--apply`; the file's own line endings are kept."""
import os
import re
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
MARK = "KB 06 7.374"
BLOCK = [
    "// A Domain object reads the game text under /d, and every object the files next to it (`__DIR__ \"maze.map\"`, a book's `text/` directory): the trust rules the admin",
    "// saved (data/static/securityd.o) are not in the archive and without them such a read answers 0 (" + MARK + ").",
    "if (func == \"read_file\" && objectp(user)) {",
    "  string own;",
    "",
    "  if (euid == \"Domain\" && sscanf(file, \"/d/%*s\")) return 1;",
    "  own = base_name(user);",
    "  own = own[0..strsrch(own, \"/\", -1)];",
    "  if (strlen(file) > strlen(own) && file[0..strlen(own) - 1] == own) return 1;",
    "}",
    "",
]


def plan(data):
    """-> (insert_at, text) or a reason string"""
    nl = "\r\n" if data.count("\r\n") * 2 > data.count("\n") else "\n"
    if MARK in data:
        return "already"
    m = re.search(r"(?m)^int[ \t]+valid_read[ \t]*\(", data)
    if not m:
        return "no valid_read"
    end = re.search(r"(?m)^\}", data[m.end():])
    if not end:
        return "no end of valid_read"
    span_end = m.end() + end.start()
    g = re.search(r"(?m)^([ \t]*)if[ \t]*\([ \t]*![ \t]*euid[ \t]*\)[ \t]*return[ \t]+0;", data[m.end():span_end])
    if not g:
        return "no `if (!euid) return 0;`"
    at = m.end() + g.start()
    ind = g.group(1)
    # a comment line directly above (`// Get the euid and status of the user.`) stays with its statement
    prev = re.search(r"([ \t]*//[^\n]*euid[^\n]*\n)$", data[:at])
    if prev:
        at -= len(prev.group(1))
    text = "".join((ind + ln if ln else "") + nl for ln in BLOCK)
    return at, text


def main():
    argv = sys.argv[1:]
    apply, listing = "--apply" in argv, "--list" in argv
    names = [a for a in argv if not a.startswith("--")]
    if not names:
        sys.exit(__doc__)
    for slug in names:
        p = os.path.join(REPO, "libs", slug, "work", "adm", "daemons", "securityd.lpc")
        try:
            raw = open(p, "rb").read()
        except OSError:
            print(f"{slug}: no securityd.lpc")
            continue
        data = raw.decode("utf-8", "surrogateescape")
        r = plan(data)
        if isinstance(r, str):
            print(f"{slug}: {r}")
            continue
        at, text = r
        line = data.count("\n", 0, at) + 1
        print(f"{slug}: rule goes before line {line}" + ("" if apply else " (plan only)"))
        if apply:
            open(p, "wb").write((data[:at] + text + data[at:]).encode("utf-8", "surrogateescape"))


if __name__ == "__main__":
    main()
