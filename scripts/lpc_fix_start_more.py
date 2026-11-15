#!/usr/bin/env python3
"""scripts/lpc_fix_start_more.py [--apply] [SLUG...]

The pager `feature/more.lpc` (and its variants, including multi-parameter copies such as
`(string msg, int y)` or `(object who, string msg)`),

  void start_more(string msg) {
    write("\\n");
    more("", explode(msg, "\\n"), 0);
  }

is handed whatever `read_file()` answered: `me->start_more(read_file(HELP_DIR + "help/topics"))`,
`start_more(read_file(NEWS))`.  For a file the archive does not ship that is 0, and
`explode(0, "\\n")` raises (`Bad argument 1 to explode()  Expected: string Got: 0.`, ldtx: the
player command `help` without an argument); the old driver took 0 for an empty text.
Inserts `if (!stringp(VAR)) return;` as the first statement of any `start_more(...)` whose
balanced `{ ... }` body calls `explode(VAR, ...)` without a preceding `stringp(VAR)` / `!VAR` guard
inside that function (comments, strings and heredocs masked; KB 06 section 7.300).
Binary-safe (CRLF kept), idempotent.

Without --apply the plan is printed: `FIX<TAB>slug<TAB>/path`."""
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from lpc_fix_void_return import code_mask  # noqa: E402
import lpc_scan_cond_assign as sc  # noqa: E402

REPO = sc.REPO
HEAD = re.compile(rb"((?:(?:varargs|public|protected|nomask)\s+)*void\s+start_more\s*\(([^()]*)\)\s*\{)([ \t]*\r?\n|[ \t]*)")
PARAM = re.compile(rb"\bstring\s+(\w+)\b")


def brace_span(b, mask, open_at):
    depth = 0
    for i in range(open_at, len(b)):
        if not mask[i]:
            continue
        c = b[i]
        if c == 0x7B:
            depth += 1
        elif c == 0x7D:
            depth -= 1
            if depth == 0:
                return i + 1
    return -1


def plan(b):
    mask = code_mask(b, heredoc=True)
    for m in HEAD.finditer(b):
        if not mask[m.start()]:
            continue
        open_brace = m.end(1) - 1
        end = brace_span(b, mask, open_brace)
        if end < 0:
            continue
        body_code = bytes(b[i] if mask[i] else 0x20 for i in range(m.end(1), end))
        for pm in PARAM.finditer(m.group(2)):
            var = pm.group(1)
            em = re.search(rb"\bexplode\s*\(\s*" + var + rb"\b", body_code)
            if not em:
                continue
            pre = body_code[:em.start()]
            if re.search(rb"stringp\(\s*" + var + rb"\s*\)|!\s*" + var + rb"\b", pre):
                continue
            return m, var
    return None


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
            b = open(f, "rb").read()
            if b"start_more" not in b:
                continue
            hit = plan(b)
            if not hit:
                continue
            m, var = hit
            n += 1
            print(f"FIX\t{slug}\t{p}")
            if apply_:
                eol = b"\r\n" if b"\r\n" in b else b"\n"
                ins = eol + b"  if (!stringp(" + var + b")) return;"            # the pager gets 0 for a file the archive does not ship
                b = b[:m.end(1)] + ins + b[m.end(1):]
                open(f, "wb").write(b)
    print(f"{n} file(s)", file=sys.stderr)


if __name__ == "__main__":
    main()
