#!/usr/bin/env python3
"""scripts/lpc_scan_unguarded_read.py [--libs SLUG ...] [--with-wizard] [--forms nested,twostep]

`read_file()` of a file the lib does not ship, handed to something that cannot take 0 (KB 06 7.285, 7.298, 7.300, 7.301, 7.326).  The old driver took 0 for an empty
text; this one raises (`Bad argument 1 to explode()`), and a command, a daemon's create() or an NPC's heart beat dies on a fresh tree, where the runtime file a running mud
writes (`/log/PARTY`, `/data/ladder.txt`, a counter) does not exist yet.  A text scan cannot know which file the game makes, so this lists the SITES: a literal path that is
not under `work/` and a use that is not guarded.  Two forms:

  nested    explode(read_file("/lit"), ...), trans_color(...), replace_string(...), sscanf(...)  -- no room for a guard on the same expression
  twostep   x = read_file("/lit"[, a, b]); and, within four lines, explode(x ...) / sscanf(x ...) / replace_string(x ...) / strlen(x) / x[...]

Comments are blanked first (a commented-out block is not a site).  A twostep site is dropped when a `file_size(` / `file_exists(` / `stringp(` / `catch` stands in the eight lines above it, when
the next lines test the variable (`if (!x)`, `x ||`, `x ?`).  Wizard and personal directories (`u/`, `wizards/`, `open/`, `cmds/wiz` ...), `www`/`cgi`, backup copies and old
directories are skipped unless --with-wizard.  Output, one line per site: `slug<TAB>file<TAB>line<TAB>path<TAB>form`; the summary goes to stderr.  Read each site before
fixing it: a guard three functions away (`if (!(x = get_number())) return 0;` before the read) is invisible here -- of 85 live twostep sites in 56 libs (2026-10-20) about a third
were real (`d/luoyang/obj/xiang.lpc` `/log/PARTY` in 8 xkx-lineage libs, `pettrainer` `/log/news`, a taskd `create()` reading three quest tables).  Fix: `x = read_file(...) || "";`
(`explode("", "\\n")` is `({})`) or a `file_size(f) > 0` test, as the guarded siblings do."""
import argparse
import os
import re
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
EXTS = (".lpc", ".c", ".h")
WIZ = re.compile(r"(^|/)(u|wizu|wizards|www|WWW|cgi|cgi-bin|open|test|tests|tmp|backup|doc|old|bak|bakcmds|players|realms|w|wiz|arch)/|(^|/)cmds/(wiz|arch|adm|imm|admin|wizard|creator|system)/|[ 复]")
NEST = re.compile(r'\b(explode|trans_color|replace_string|sscanf)\(\s*(?:trans_color\(\s*)?read_file\(\s*"(/[^"]+)"')
ASSIGN = re.compile(r'\b(\w+)\s*=\s*read_file\(\s*"(/[^"]+)"')


def strip_comments(t):
    """block and line comments blanked (line numbers kept); strings left alone"""
    out, i, n, st = [], 0, len(t), None
    while i < n:
        c, d = t[i], t[i:i + 2]
        if st is None:
            if d == "//":
                j = t.find("\n", i)
                j = n if j < 0 else j
                out.append(" " * (j - i))
                i = j
                continue
            if d == "/*":
                j = t.find("*/", i + 2)
                j = n if j < 0 else j + 2
                out.append(re.sub(r"[^\n]", " ", t[i:j]))
                i = j
                continue
            if c == '"':
                st = '"'
            out.append(c)
            i += 1
        else:
            if c == "\\" and i + 1 < n:
                out.append(t[i:i + 2])
                i += 2
                continue
            if c == st:
                st = None
            out.append(c)
            i += 1
    return "".join(out)


def sites(path, work, forms):
    try:
        text = open(path, encoding="utf-8", errors="replace").read()
    except OSError:
        return
    if "read_file" not in text:
        return
    ls = strip_comments(text).split("\n")
    for n, line in enumerate(ls, 1):
        if "read_file" not in line:
            continue
        if "nested" in forms:
            m = NEST.search(line)
            if m and not os.path.exists(work + m.group(2)) and "file_size(" not in line:
                ctx = "\n".join(ls[max(0, n - 6):n])
                if not re.search(r"file_size\(\s*\"?" + re.escape(m.group(2)), ctx):
                    yield n, m.group(2), "nested"
                continue
        if "twostep" in forms:
            m = ASSIGN.search(line)
            if not m:
                continue
            var, p = m.groups()
            if os.path.exists(work + p) or re.search(r"read_file\([^)]*\)\s*(\|\||\?)", line):
                continue
            nxt = "\n".join(ls[n:n + 4])
            if not re.search(r"\b(explode|sscanf|replace_string|strlen|sizeof)\(\s*" + re.escape(var) + r"\b|\b" + re.escape(var) + r"\[", nxt):
                continue
            ctx = "\n".join(ls[max(0, n - 9):n + 1])
            if re.search(r"\b(stringp|file_size|file_exists?|catch)\b", ctx):
                continue
            if re.search(r"\b(while|if|for)\s*\(\s*\(?\s*" + re.escape(var) + r"\s*=\s*read_file", line):
                continue   # the read is the loop / branch test itself
            if re.search(r"\bif\s*\(\s*!?\s*" + re.escape(var) + r"\b", "\n".join(ls[n - 1:n + 3])) or re.search(r"\b" + re.escape(var) + r"\b\s*(\|\||\?)", "\n".join(ls[n - 1:n + 2])):
                continue
            yield n, p, "twostep"


def main():
    sys.stdout.reconfigure(errors="surrogateescape")   # a file name that is not UTF-8 (GBK names in old archives) must not stop the scan
    ap = argparse.ArgumentParser()
    ap.add_argument("--libs", nargs="*", default=[])
    ap.add_argument("--with-wizard", action="store_true")
    ap.add_argument("--forms", default="nested,twostep")
    a = ap.parse_args()
    forms = set(a.forms.split(","))
    libs = a.libs or sorted(d for d in os.listdir(f"{REPO}/libs") if os.path.isdir(f"{REPO}/libs/{d}/work"))
    total = 0
    per = {}
    for slug in libs:
        work = f"{REPO}/libs/{slug}/work"
        if not os.path.isdir(work):
            continue
        for root, dirs, files in os.walk(work):
            rel_root = os.path.relpath(root, work)
            if rel_root != "." and not a.with_wizard and WIZ.search(rel_root + "/"):
                dirs[:] = []
                continue
            for f in files:
                if f.endswith(EXTS):
                    rel = os.path.normpath(os.path.join(rel_root, f))
                    for n, p, form in sites(os.path.join(root, f), work, forms):
                        print(f"{slug}\t{rel}\t{n}\t{p}\t{form}")
                        total += 1
                        per[slug] = per.get(slug, 0) + 1
    print(f"{total} site(s) in {len(per)} lib(s)", file=sys.stderr)


if __name__ == "__main__":
    main()
