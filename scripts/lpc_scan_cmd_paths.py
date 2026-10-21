#!/usr/bin/env python3
"""scripts/lpc_scan_cmd_paths.py [--calls] [--inlib] [SLUG...]

String literals `"/cmds/<dir>/<name>"` whose file the lib does not ship (KB 06 section 7.344).  A command called by path
(`"/cmds/adm/bag"->main(me, "<...>")`, `new("/cmds/adm/stdnpc")`, `this_player()->move("/cmds/std/quitroom")`) raises
`call_other() couldn't find object` when the archive lacks the file: the sleeping bag of 18 libs left its player deaf, the jiuyin book's `du`
was a command the lib had renamed to `study`, a jail room could not `quit`.

For every tracked `.lpc` / `.c` / `.h` outside wizard, backup and doc directories (comments blanked) each literal that is a plain path
(`/cmds/` + letters, digits, `_ . / -`, no trailing slash) is looked up as `PATH`, `PATH.lpc`, `PATH.c` and as a directory.  Prints
`slug<TAB>file<TAB>line<TAB>path<TAB>the source line`.
  --calls   only the literals used as a call target: `"path"->f(`, `call_other|new|load_object|clone_object|find_object("path"`, `->move("path"`
  --inlib   add the in-lib alternatives by file name (`/cmds/usr/skills` when the call names `/cmds/skill/skills`): the stale-path cases
The gitlink libs are skipped.  Read every hit: a path inside `#define`, a `previous_object()` comparison or an unused macro is not a bug; a call site that
is reachable and whose command the lib never had (a gang module, a match system) is a content gap and takes a `file_size(PATH ".lpc") > 0` guard
(KB 06 section 7.308); a path the lib kept under another directory or name is a one-word fix."""
import os
import re
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
GITLINKS = {"nt7", "xkx100utf8", "fy2005", "nightmare3", "residuum", "sanguozhi", "oxidus", "deadsouls_fluffos"}
LIT = re.compile(rb'"(/cmds/[A-Za-z0-9_./-]*[A-Za-z0-9_])"')
SKIP = re.compile(r"/(old|bak|backup|raw|u|w|doc|docs|realms|test)/")


def main():
    argv = sys.argv[1:]
    calls = "--calls" in argv
    inlib = "--inlib" in argv
    libs = [a for a in argv if not a.startswith("--")] or sorted(
        d for d in os.listdir(f"{REPO}/libs") if os.path.isdir(f"{REPO}/libs/{d}/work"))
    n = 0
    for slug in libs:
        if slug in GITLINKS:
            continue
        out = subprocess.run(["git", "ls-files", "-z", "--", f"libs/{slug}/work"], cwd=REPO, capture_output=True).stdout
        names = [p.decode("utf-8", "surrogateescape") for p in out.split(b"\0") if p]
        have = set(names)
        pre = f"libs/{slug}/work"
        byname = {}
        if inlib:
            for f in names:
                if f.endswith((".lpc", ".c")):
                    byname.setdefault(os.path.basename(f).rsplit(".", 1)[0], []).append(f[len(pre):].rsplit(".", 1)[0])
        for rel in names:
            if not rel.endswith((".lpc", ".c", ".h")) or SKIP.search(rel[len(pre):]):
                continue
            try:
                data = open(f"{REPO}/{rel}", "rb").read()
            except OSError:
                continue
            if b'"/cmds/' not in data:
                continue
            txt = re.sub(rb"/\*.*?\*/", lambda m: b"\n" * m.group(0).count(b"\n"), data, flags=re.S)
            txt = re.sub(rb"//[^\n]*", b"", txt)
            for m in LIT.finditer(txt):
                path = m.group(1).decode("latin-1")
                cands = [pre + path, pre + path + ".lpc", pre + path + ".c"]
                if path.endswith(".c"):
                    cands = [pre + path, pre + path[:-2] + ".lpc"]
                if any(c in have for c in cands) or any(x.startswith(pre + path + "/") for x in names):
                    continue
                ls = txt.rfind(b"\n", 0, m.start()) + 1
                le = txt.find(b"\n", m.end())
                ctx = txt[ls:le if le >= 0 else len(txt)].strip().decode("utf-8", "replace")
                if calls:
                    p = re.escape(path)
                    if not (re.search(r'"%s"\s*->' % p, ctx) or re.search(r'(call_other|new|load_object|clone_object|find_object)\s*\(\s*"%s"' % p, ctx)
                            or re.search(r'move\s*\(\s*"%s"' % p, ctx)):
                        continue
                line = txt[:m.start()].count(b"\n") + 1
                extra = ""
                if inlib:
                    base = os.path.basename(path).rsplit(".", 1)[0]
                    alts = [a for a in byname.get(base, []) if a != path.rsplit(".", 1)[0]]
                    extra = "\t" + (",".join(alts[:3]) or "-")
                n += 1
                print(f"{slug}\t{rel[len(pre):]}\t{line}\t{path}\t{ctx[:120]}{extra}")
    print(f"{n} literal(s)", file=sys.stderr)


if __name__ == "__main__":
    main()
