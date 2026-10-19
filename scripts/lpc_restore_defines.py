#!/usr/bin/env python3
"""scripts/lpc_restore_defines.py --diag DIR [SLUG...] [--min-rel N] [--apply] [--list DIR]

An all-caps macro a lib's objects use and no header of the lib defines (KB 04 section 6.16).  The compiler says
`Undefined variable 'MONEY_D'` or `Undefined function ARMOR_D`, the object never loads, and the rest of the file is never
looked at.  The siblings of the lib define the macro (`#define ARMOR_D(x) ("/clone/armor/" + x)`, `#define MSG_INDENT 8`,
`#define EVENT_D "/adm/daemons/eventd"`): this adds the definition to the lib's global header.

--diag DIR  the scan output of scripts/lpc_warnings.py (DIR/diag-SLUG.tsv: path, line, column, severity, message); the
            all-caps names of its `Undefined variable` / `Undefined function` rows are the macros wanted.
A definition is taken from the libs that define the name, weighted by how related they are to this lib (files carried byte
for byte, as in scripts/lpc_restore_bases.py); a name the lib itself defines in a header the objects do not include is reported, not
added (a second copy would collide where both are included).  It is added only when every literal path in its body exists in the lib (a directory
holding files, or a `.lpc`): `TROOP_D` for a lib without `/daemon/troop/` would only move the failure from compile time to the
first call.  A name with no path in its body (`MSG_INDENT 8`, `TYPE_WAIST "waist"`) needs the definition to be the same in two libs
or in a sibling with --min-rel (default 100) files in common.  A name the lib declares as a variable or function is left alone.
Refused outright: names that say who or where the mud is (`CREATOR`, `DOM_TITLE`, ports, URLs, addresses), names of one or two letters
(`ID`: it would expand inside every variable of that name), a macro continued over several lines (only its first line is read, and a
copy of that line ends in a backslash that swallows the next line of the header), and the young hobby repos (riftsds).
The line goes after the last `#define` of the lib's `global include file`, in the file's own line ending.  Without --apply
the plan is printed (DEFINE lines, SKIP lines with the reason); `--list DIR` writes DIR/defines-SLUG.list (the objects that
named the macro) for the load check.  Idempotent."""
import collections
import glob
import os
import pickle
import re
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import lpc_restore_macros as R  # noqa: E402

REPO = R.REPO
SCRATCH = os.environ.get("LPC_SCRATCH") or os.path.expanduser("~/.cache/lpc-scratch")
DEFANY = re.compile(rb'(?m)^[ \t]*#[ \t]*define[ \t]+([A-Z][A-Z0-9_]+)(\([^)\n]*\))?[ \t]+([^\n]*?)[ \t]*(?://[^\n]*)?\r?$')
# what names the mud (its name, address, web page, mail), not what the code needs: another lib's value would be wrong here
IDENTITY = re.compile(r"(?:^|_)(?:THIS_MUD|MUD_NAME|MUD_WEB|MUD_URL|BBS_ADDR|.*_ADDR|.*_URL|.*_IP|.*_PORT|.*EMAIL.*|ADMIN_.*|CHINESE_MUD_NAME|ENGLISH_MUD_NAME|MUD_ID|CREATOR|AUTHOR|DOM_TITLE|DOMAIN_TITLE|.*PAYPORT)$")
# a macro name of one or two letters (`ID`) would expand inside every variable of that name in the lib: never added
MIN_NAME = 3
# young hobby repos are not restored (AGENTS.md section 13.9)
SKIPLIBS = {"riftsds", "wllz3", "longyunmeng_binary"}    # the last two are generated trees (rebuild.sh + patch): their work/ is reproduced, never edited
WANT = re.compile(r"Undefined (?:variable|function) '?([A-Z][A-Z0-9_]+)'?")


def load_rel():
    p = os.path.join(SCRATCH, "relatedness.pkl")
    if os.path.exists(p):
        return pickle.load(open(p, "rb"))[0]
    sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
    import lpc_restore_bases as B
    return B.relatedness(False)[0]


_DEFINED = {}


def lib_defines(slug, name):
    """does any header or source of the lib `#define` this name (cached per lib)"""
    if slug not in _DEFINED:
        out = subprocess.run(["git", "grep", "-h", "-oE", r"^[ \t]*#[ \t]*define[ \t]+[A-Za-z_][A-Za-z0-9_]*", "--", f"libs/{slug}/work"],
                             cwd=REPO, capture_output=True).stdout.decode("utf-8", "replace").split("\n")
        _DEFINED[slug] = {re.sub(r"^[ \t]*#[ \t]*define[ \t]+", "", x) for x in out if x}
    return name in _DEFINED[slug]


def lib_source_defines(slug, name):
    """object files (not headers, not wizard or backup dirs) of the lib that `#define` the name themselves: a template macro"""
    out = subprocess.run(["git", "grep", "-l", "-E", r"^[ \t]*#[ \t]*define[ \t]+" + re.escape(name) + r"\b", "--", f"libs/{slug}/work"],
                         cwd=REPO, capture_output=True).stdout.decode("utf-8", "replace").split("\n")
    return [f for f in out if f and not f.endswith((".h", ".hd")) and not R.SKIP.search(f)]


def main():
    args = sys.argv[1:]
    apply = "--apply" in args
    diag = listdir = None
    min_rel = 100
    for flag in ("--diag", "--list", "--min-rel"):
        if flag in args:
            i = args.index(flag)
            v = args[i + 1]
            del args[i:i + 2]
            if flag == "--diag":
                diag = v
            elif flag == "--list":
                listdir = v
            else:
                min_rel = int(v)
    if not diag:
        sys.exit(__doc__)
    only = [a for a in args if not a.startswith("--")]
    rel = load_rel()
    by = R.tracked()
    want = collections.defaultdict(lambda: collections.defaultdict(set))   # slug -> NAME -> objects
    for f in glob.glob(os.path.join(diag, "diag-*.tsv")):
        slug = os.path.basename(f)[5:-4]
        if only and slug not in only:
            continue
        for l in open(f, encoding="utf-8", errors="replace"):
            p = l.rstrip("\n").split("\t")
            if len(p) >= 5:
                m = WANT.match(p[4])
                if m and not R.SKIP.search(p[0]) and not IDENTITY.match(m.group(1)) and len(m.group(1)) >= MIN_NAME and slug not in SKIPLIBS:
                    want[slug][m.group(1)].add(p[0])
    names = {n for d in want.values() for n in d}
    # every definition of a wanted name, with the lib and the header it sits in
    defs = collections.defaultdict(list)   # NAME -> [(slug, header rel, params, body)]
    for slug, fs in by.items():
        for rr in fs:
            # headers only; another lib's wizard and backup dirs do not count, the lib's own (u/x/globals.h) do
            if not rr.endswith(".h"):
                continue
            wiz = bool(R.SKIP.search(rr))
            if wiz and slug not in want:
                continue
            try:
                b = open(f"{REPO}/libs/{slug}/work{rr}", "rb").read()
            except OSError:
                continue
            if b"define" not in b:
                continue
            for m in DEFANY.finditer(b):
                n = m.group(1).decode()
                if m.group(3).rstrip().endswith(b"\\"):
                    continue    # a macro continued over several lines: only its first line is read here, so it is never copied
                if n in names:
                    defs[n].append((slug, rr, (m.group(2) or b"").decode("utf-8", "replace"), re.sub(rb"\s+", b" ", m.group(3)).decode("utf-8", "replace"), wiz))
    tot = tot_objs = 0
    for T in sorted(want):
        if T not in by or os.path.exists(f"{REPO}/libs/{T}/work/.git"):
            continue
        files = set(by[T])
        hdr = R.global_header(T, files)
        add = []
        for name, objs in sorted(want[T].items(), key=lambda kv: -len(kv[1])):
            alld = defs.get(name, [])
            own_real = [c for c in alld if c[0] == T and not c[4]]
            own_wiz = [c for c in alld if c[0] == T and c[4]]
            cands = [c[:4] for c in alld if c[0] != T and not c[4]]
            src_defs = lib_source_defines(T, name)
            if src_defs and not own_real:
                print(f"SKIP  {T} {name}: {src_defs[0].split('/work', 1)[1]} defines it itself ({len(src_defs)} file(s)): a template macro of the object files, not a lost header line")
                continue
            if own_real:
                # the lib defines it, in a header these objects do not reach: a second copy in the global header would
                # collide with the first wherever both are included, so the fix is an #include in the object, not a define
                print(f"SKIP  {T} {name}: the lib defines it in {own_real[0][1]}; {len(objs)} object(s) do not include that header")
                continue
            if own_wiz:
                # only a wizard's private header defines it (shenmo's u/xdao/globals.h): the lib's own definition, out of reach
                if len({(c[2], c[3]) for c in own_wiz}) > 1:
                    print(f"SKIP  {T} {name}: {len(own_wiz)} wizard headers define it, differently ({own_wiz[0][1]} ...)")
                    continue
                pick = (f"the lib's own, from {own_wiz[0][1]}", own_wiz[0][2], own_wiz[0][3], 99999)
            else:
                score = collections.defaultdict(lambda: [0, set()])
                for slug, rr, params, body in cands:
                    s = score[(params, body)]
                    s[0] = max(s[0], rel.get((T, slug), 0))
                    s[1].add(slug)
                if not score:
                    print(f"SKIP  {T} {name}: defined in no lib ({len(objs)} object(s))")
                    continue
                (params, body), (r, libs) = max(score.items(), key=lambda kv: (kv[1][0], len(kv[1][1])))
                if r < min_rel and len(libs) < 2:
                    print(f"SKIP  {T} {name}: one lib defines it ({sorted(libs)[0]}, {r} files in common)")
                    continue
                pick = (f"{len(libs)} lib(s), best {r} files in common", params, body, r)
            why, params, body, r = pick
            paths = [p.rstrip("/") for p in re.findall(r'"(/[^"]*)"', body)]
            bad = None
            for pth in paths:
                if not pth:
                    continue
                if not (any(f.startswith(pth + "/") for f in files) or pth in files or pth + ".lpc" in files or pth + ".c" in files):
                    bad = pth
                    break
            if bad:
                print(f"SKIP  {T} {name}: {bad} is not in the lib ({len(objs)} object(s))")
                continue
            if not paths and not own_wiz and len({(c[2], c[3]) for c in cands}) > 1 and r < min_rel:
                print(f"SKIP  {T} {name}: the libs disagree on its value")
                continue
            # a body that names another macro (`DAEMON_DIR "reward_d"`, `MASTER_OB`) only moves the failure if the lib does not define that one
            nostr = re.sub(r"/\*.*?\*/", "", re.sub(r'"(?:\\.|[^"\\])*"', '""', body))
            missing = sorted(t for t in set(re.findall(r"\b[A-Z][A-Z0-9_]{2,}\b", nostr)) - set(re.findall(r"\w+", params)) - {name} if not lib_defines(T, t))
            if missing:
                print(f"SKIP  {T} {name}: its body uses {missing[0]}, which the lib does not define ({len(objs)} object(s))")
                continue
            hit = subprocess.run(["git", "grep", "-lE", r"\b(int|string|object|mixed|mapping|float|void|status|varargs)[ \t*]+" + name + r"\b", "--", f"libs/{T}/work"],
                                 cwd=REPO, capture_output=True).stdout.decode("utf-8", "replace").split("\n")
            if any(h and not R.SKIP.search(h) for h in hit):
                print(f"SKIP  {T} {name}: the lib declares that name as a variable or function")
                continue
            add.append((name, params, body, why, objs))
        if not add:
            continue
        if not hdr:
            print(f"NOHDR {T}: no global include file to put " + ", ".join(a[0] for a in add))
            continue
        for name, params, body, why, objs in add:
            tot += 1
            tot_objs += len(objs)
            print(f"DEFINE {T} {name}{params} = {body}  ({why}; {len(objs)} object(s)) in {hdr}")
        if listdir:
            os.makedirs(listdir, exist_ok=True)
            open(f"{listdir}/defines-{T}.list", "w", encoding="utf-8").write("\n".join(sorted({o for a in add for o in a[4]})) + "\n")
        if apply:
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
            new = [("#define %s%s %s" % (n, pr, bd)).encode("utf-8") + (b"\r" if eol == b"\r\n" else b"") for n, pr, bd, _, _ in add]
            if last < 0:
                lines = lines + new if not b.endswith(b"\n") else lines[:-1] + new + [b""]
            else:
                lines[last + 1:last + 1] = new
            open(p, "wb").write(b"\n".join(lines))
    print(f"{tot} macro(s) for {tot_objs} object(s)" + ("" if apply else " (plan only; --apply writes)"))


if __name__ == "__main__":
    main()
