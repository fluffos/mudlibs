#!/usr/bin/env python3
"""scripts/lpc_fix_visitor_count.py [--apply] [SLUG...]

The visitor counter of the Eastern Story / xkx login daemon,

  int howmany_visitor() {
    int num = 0;
    string content, format;
    content = read_file(VISITORS);                // "/log/mud/MUDVISITOR", "/data/mud/MUDVISITOR", COUNTER, BBSVISITOR ...
    sscanf(content, "%s %d", format, num);
    ...
    return num;
  }

reads a file that only a running mud writes; `.gitignore` keeps the log and data directories (and `MUDVISITOR`, `visitor.cnt`) out of the repository, so a clone, a pristine tree
and the site have none, `read_file()` answers 0 and `sscanf(0, ...)` raises (`Bad argument 1 to sscanf  Expected: string Got: 0.`).  `logon()` calls the function for every
connection (wqfy, zzfy3): the new connection is closed (`new_conn_handler: logon() ... has failed, the user is disconnected`) and nobody can log in.  The old driver took
the 0 for an empty string.  Adds `if (!stringp(content)) return 0;` right after the read (the form xkx100, xiakexing100 and zzfy already had) to every `howmany_visitor()` whose
first use of the text is a `sscanf()` with no test of the variable in between (KB 06 section 7.298).  Binary-safe (CRLF kept), idempotent.

Without --apply the plan is printed: `FIX<TAB>slug<TAB>/path<TAB>line`."""
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from lpc_fix_void_return import code_mask  # noqa: E402
import lpc_scan_cond_assign as sc  # noqa: E402

REPO = sc.REPO
FUNC = re.compile(rb"\bint\s+howmany_visitor\s*\(\s*\)\s*\{")
READ = re.compile(rb"(?m)^([ \t]*)([A-Za-z_]\w*)[ \t]*=[ \t]*read_file[ \t]*\([^;\n]*\)[ \t]*;[ \t]*(\r?\n)")


def plan(b):
    """[(offset to insert at, text to insert, line)] for the unguarded reads"""
    mask = code_mask(b)
    out = []
    for fm in FUNC.finditer(b):
        if not mask[fm.start()]:
            continue
        depth, i, end = 1, fm.end(), None
        while i < len(b):
            if mask[i]:
                if b[i] == 0x7b:
                    depth += 1
                elif b[i] == 0x7d:
                    depth -= 1
                    if depth == 0:
                        end = i
                        break
            i += 1
        if end is None:
            continue
        body = b[fm.end():end]
        for rm in READ.finditer(body):
            var = rm.group(2)
            rest = body[rm.end():]
            use = re.search(rb"\bsscanf\s*\(\s*" + var + rb"\s*,", rest)
            if not use:
                continue
            between = rest[:use.start()]
            if re.search(rb"\b" + var + rb"\b", between):
                continue                                # something tests or uses the text before the sscanf
            if re.search(rb"(?:if|while)\s*\([^)]*\b" + var + rb"\b[^)]*\)[^;{]*\bsscanf", rest[:use.end()]):
                continue
            at = fm.end() + rm.end()
            line = b.count(b"\n", 0, at)
            out.append((at, rm.group(1) + b"if (!stringp(" + var + b")) return 0;" + rm.group(3), line))
    return out


def main():
    a = sys.argv[1:]
    apply_ = "--apply" in a
    slugs = [x for x in a if not x.startswith("--")]
    n = 0
    for slug, paths in sorted(sc.tracked(slugs).items()):
        if slug in sc.LDMUD or slug in sc.GENERATED:
            continue
        for full in paths:
            p = "/" + full.split("/work/", 1)[1]
            if sc.TOP.search(p) or sc.ANY.search(p):
                continue
            f = os.path.join(REPO, full)
            try:
                b = open(f, "rb").read()
            except OSError:
                continue
            if b"howmany_visitor" not in b:
                continue
            hits = plan(b)
            if not hits:
                continue
            for at, ins, line in hits:
                n += 1
                print(f"FIX\t{slug}\t{p}\t{line}")
            if apply_:
                for at, ins, line in sorted(hits, key=lambda h: -h[0]):
                    b = b[:at] + ins + b[at:]
                open(f, "wb").write(b)
    print(f"{n} site(s)", file=sys.stderr)


if __name__ == "__main__":
    main()
