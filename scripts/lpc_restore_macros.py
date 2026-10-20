#!/usr/bin/env python3
"""scripts/lpc_restore_macros.py [SLUG...] [--apply] [--list DIR]

A lib whose global header lost a base-class macro (KB 04 section 6.13).  `inherit F_DEALER;` where no header of the lib defines
`F_DEALER` is `syntax error, unexpected L_IDENTIFIER, expecting L_STRING or '('` and the whole object never loads (the NPC, room or
item); the base file itself is in the lib (`/feature/dealer.lpc`) and 131 other libs map the macro to it.  sjpl2/sjplii lost it
for 28 NPCs, xyzxiiylzymh and four siblings for their 80 `quest/game` rooms, fys for its 9 waist armors.

For every vendored lib: collect the macros any tracked file `#define`s (comments and wizard/backup dirs aside), find the live
`.lpc` files that `inherit IDENT;` with an all-caps IDENT nobody defines, and look the name up in the other libs' headers
(`#define IDENT "/path"`).  A definition is taken when the path exists in this lib as `.lpc` and either two or more libs agree
on it or the file name is the macro name in lower case (`WQA_ROOM` -> `wqa_room`).  The line `#define IDENT "/path"` goes
after the last `#define` of the lib's `global include file` (config.fluffos), in the file's own line ending.  A macro is
not restored when the lib also uses the token as something else (`IDENT =`, or declared as a variable or function anywhere): printed as SKIP.  Without --apply
the plan is printed; `--list DIR` writes `DIR/restore-SLUG.list` (the files to load-check, `/path.lpc` per line, for
scripts/lpc_listcheck.sh).  Binary-safe; idempotent: a restored macro is defined, so the next run finds nothing."""
import collections
import os
import re
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SKIP = re.compile(r"/(u|w|wiz|wizard|wizards|open|players|backup|backups|old|bak|log|data|doc|docs|example|examples)/|[-_.](bak|old)/|\.(bak|BAK|old|orig)\.lpc$")
INH = re.compile(rb"(?m)^[ \t]*inherit[ \t]+([A-Z][A-Z0-9_]*)[ \t]*;")
DEF = re.compile(rb"(?m)^[ \t]*#[ \t]*define[ \t]+([A-Za-z_][A-Za-z0-9_]*)")
DEFQ = re.compile(rb'(?m)^[ \t]*#[ \t]*define[ \t]+([A-Za-z_][A-Za-z0-9_]*)[ \t]+"([^"\n]+)"')


def tracked():
    out = subprocess.run(["git", "ls-files", "-z", "--", "libs"], cwd=REPO, capture_output=True).stdout.split(b"\0")
    by = collections.defaultdict(list)
    for f in out:
        try:
            p = f.decode("utf-8")
        except UnicodeDecodeError:
            continue
        parts = p.split("/")
        if len(parts) > 3 and parts[2] == "work" and parts[1] != "longyunmeng_binary":
            by[parts[1]].append("/" + "/".join(parts[3:]))
    return by


def global_header(slug, files):
    try:
        t = open(f"{REPO}/libs/{slug}/config.fluffos", encoding="utf-8", errors="replace").read()
    except OSError:
        return None
    m = re.search(r"(?m)^global include file\s*:\s*[<\"]?([^>\"\s]+)", t)
    if not m:
        return None
    name = m.group(1)
    if name.startswith("/"):
        return os.path.normpath(name) if os.path.normpath(name) in files else None
    for d in ("/include", "", "/secure/include", "/sys"):
        c = os.path.normpath(d + "/" + name)
        if c in files:
            return c
    return None


def lib_scan(slug, files):
    """-> (defined macro names, {IDENT: [live files inheriting it]}, {IDENT: bytes of every file mentioning it as a bare token})"""
    defs, miss, texts = set(), collections.defaultdict(list), {}
    for rel in files:
        if not rel.endswith((".lpc", ".h")):
            continue
        try:
            b = open(f"{REPO}/libs/{slug}/work{rel}", "rb").read()
        except OSError:
            continue
        if b"#" in b and not SKIP.search(rel):          # a macro a wizard directory's header defines is not defined for the live files
            for m in DEF.finditer(b):
                defs.add(m.group(1))
        if rel.endswith(".lpc") and b"inherit" in b and not SKIP.search(rel):
            for m in INH.finditer(b):
                miss[m.group(1)].append(rel)
                texts[(m.group(1), rel)] = b
    return defs, miss, texts


def main():
    args = sys.argv[1:]
    apply = "--apply" in args
    listdir = None
    if "--list" in args:
        i = args.index("--list")
        listdir = args[i + 1]
        del args[i:i + 2]
    only = [a for a in args if not a.startswith("--")]
    by = tracked()
    scans = {s: lib_scan(s, set(f)) for s, f in by.items()}
    corpus = collections.defaultdict(lambda: collections.defaultdict(set))   # macro -> path -> libs defining it
    for slug, fs in by.items():
        for rel in fs:
            if not rel.endswith(".h") or SKIP.search(rel):
                continue
            try:
                b = open(f"{REPO}/libs/{slug}/work{rel}", "rb").read()
            except OSError:
                continue
            for m in DEFQ.finditer(b):
                corpus[m.group(1).decode()][m.group(2).decode("utf-8", "replace")].add(slug)
    tot_files = tot_macros = 0
    for slug in sorted(only or by):
        if slug not in by or os.path.exists(f"{REPO}/libs/{slug}/work/.git"):
            continue
        files = set(by[slug])
        defs, miss, texts = scans[slug]
        add = []
        for ident, users in sorted(miss.items(), key=lambda kv: -len(kv[1])):
            if ident in defs:
                continue
            name = ident.decode()
            cands = []
            for path, libs in corpus.get(name, {}).items():
                q = path.lstrip("/")
                q = q[:-2] if q.endswith(".c") else q[:-4] if q.endswith(".lpc") else q
                if "/" + q + ".lpc" in files and (len(libs) >= 2 or os.path.basename(q) == name.lower()):
                    cands.append(("/" + q, len(libs)))
            if not cands:
                continue
            path = sorted(cands, key=lambda c: -c[1])[0][0]
            # the token used as anything but a base class: leave it
            other = False
            for rel in users[:200]:
                b = texts[(ident, rel)]
                if re.search(rb"(?<![A-Za-z0-9_])" + ident + rb"\s*=[^=]|\b(?:int|string|object|mixed|mapping|float)\s+\*?" + ident + rb"\b", b):
                    other = True
                    break
            if other:
                print(f"SKIP  {slug} {name}: the token is also assigned or declared")
                continue
            add.append((name, path, users))
        if not add:
            continue
        # a name the lib declares as a variable or function would break once it is a macro
        names = "|".join(a[0] for a in add)
        g = subprocess.run(["git", "grep", "-lE", r"\b(int|string|object|mixed|mapping|float|void|status|varargs)[ \t*]+(" + names + r")\b", "--", f"libs/{slug}/work"],
                           cwd=REPO, capture_output=True).stdout.decode("utf-8", "replace").split("\n")
        g = [x for x in g if x and not SKIP.search(x)]
        if g:
            for n, _, _ in list(add):
                hit = subprocess.run(["git", "grep", "-lE", r"\b(int|string|object|mixed|mapping|float|void|status|varargs)[ \t*]+" + n + r"\b", "--", f"libs/{slug}/work"],
                                     cwd=REPO, capture_output=True).stdout.decode("utf-8", "replace").split("\n")
                hit = [x for x in hit if x and not SKIP.search(x)]
                if hit:
                    print(f"SKIP  {slug} {n}: declared as a variable or function in {hit[0]}")
                    add = [a for a in add if a[0] != n]
            if not add:
                continue
        hdr = global_header(slug, files)
        if not hdr:
            print(f"NOHDR {slug}: no global include file to put " + ", ".join(a[0] for a in add))
            continue
        p = f"{REPO}/libs/{slug}/work{hdr}"
        b = open(p, "rb").read()
        eol = b"\r\n" if b"\r\n" in b else b"\n"
        lines = b.split(b"\n")
        last = -1
        for i, l in enumerate(lines):
            if re.match(rb"[ \t]*#[ \t]*define\b", l):
                last = i
                while lines[last].rstrip(b"\r").endswith(b"\\") and last + 1 < len(lines):
                    last += 1
        new = [("#define %-24s \"%s\"" % (n, pth)).encode("utf-8") + (b"\r" if eol == b"\r\n" else b"") for n, pth, _ in add]
        if last < 0:
            lines = lines + new if not b.endswith(b"\n") else lines[:-1] + new + [b""]
        else:
            lines[last + 1:last + 1] = new
        for n, pth, users in add:
            tot_files += len(users)
            tot_macros += 1
            print(f"RESTORE {slug} {n} -> {pth}  ({len(users)} file(s)) in {hdr}")
        if apply:
            open(p, "wb").write(b"\n".join(lines))
        if listdir:
            os.makedirs(listdir, exist_ok=True)
            seen = sorted({rel for _, _, u in add for rel in u})
            open(f"{listdir}/restore-{slug}.list", "w", encoding="utf-8").write("\n".join(seen) + "\n")
    print(f"{tot_macros} macro(s) restored for {tot_files} file(s)" + ("" if apply else " (plan only; --apply writes)"))


if __name__ == "__main__":
    main()
