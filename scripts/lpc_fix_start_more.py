#!/usr/bin/env python3
"""scripts/lpc_fix_start_more.py [--apply] [SLUG...]

The pager of the Eastern Story / xkx lineage, `feature/more.lpc`,

  void start_more(string msg) {
    write("\\n");
    more("", explode(msg, "\\n"), 0);
  }

is handed whatever `read_file()` answered: `me->start_more(read_file(HELP_DIR + "help/topics"))`, `start_more(read_file(NEWS))`.  For a file the archive does not ship that is 0, and
`explode(0, "\\n")` raises (`Bad argument 1 to explode()  Expected: string Got: 0.`, ldtx: the player command `help` without an argument); the old driver took 0 for an empty text.
The 47 + 11 + 9 + 5 copies that already begin with `if (!stringp(msg))` / `if (!msg ...) return;` are the pattern this adds: `if (!stringp(msg)) return;` as the first statement of a
`start_more(string msg)` whose body calls `explode(msg, ...)` and has no such test in its first four lines (KB 06 section 7.300).  Binary-safe (CRLF kept), idempotent.

Without --apply the plan is printed: `FIX<TAB>slug<TAB>/path`."""
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import lpc_scan_cond_assign as sc  # noqa: E402

REPO = sc.REPO
HEAD = re.compile(rb"((?:varargs\s+)?void\s+start_more\s*\(\s*string\s+(\w+)\s*\)\s*\{)([ \t]*\r?\n|[ \t]*)")


def plan(b):
    m = HEAD.search(b)
    if not m:
        return None
    var = m.group(2)
    body = b[m.end():m.end() + 600]
    first = b"\n".join(body.split(b"\n")[:5])
    if b"explode(" + var not in body[:400]:
        return None
    if re.search(rb"stringp\(\s*" + var + rb"\s*\)|!\s*" + var + rb"\b", first):
        return None
    return m


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
            if not p.endswith(("/more.lpc", "/more.h")) and b"start_more" not in open(os.path.join(REPO, full), "rb").read(200000):
                continue
            f = os.path.join(REPO, full)
            b = open(f, "rb").read()
            m = plan(b)
            if not m:
                continue
            n += 1
            print(f"FIX\t{slug}\t{p}")
            if apply_:
                eol = b"\r\n" if b"\r\n" in b else b"\n"
                ins = eol + b"  if (!stringp(" + m.group(2) + b")) return;"            # the pager gets 0 for a file the archive does not ship
                b = b[:m.end(1)] + ins + b[m.end(1):]
                open(f, "wb").write(b)
    print(f"{n} file(s)", file=sys.stderr)


if __name__ == "__main__":
    main()
