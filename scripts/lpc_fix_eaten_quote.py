#!/usr/bin/env python3
"""scripts/lpc_fix_eaten_quote.py SLUG... [--apply]

A closing `"` lost in the GBK -> UTF-8 conversion (KB 03, `iconv -c` eats a real byte next to an invalid one): the
archive had a stray lead byte right before the quote (`"发作身亡了\\xf7";`), the converter dropped the pair, and the
line became `return name + HIM "发作身亡了;`.  The string then runs on into the following lines, the file stops with a
syntax error or `Illegal character`, and everything that inherits or includes it fails to load: the nitan family's
`/inherit/condition/damo.lpc` (every 达摩 poison condition), xyj's `hmeng014` book, `shijie5` rooms.

Only lines with an odd number of double quotes (escapes and character constants aside) whose last string ends in CJK
text directly followed by the statement's end, `;` or `);` (an optional `//` comment after it), get the quote back
before that end.  A string continued on purpose over several lines ends a line with text, not with `;`.  Comment lines
are skipped.  Binary-safe (works on the UTF-8 text line by line, line endings kept).  Without --apply the plan is
printed.  Load-check the files afterwards (scripts/lpc_listcheck.sh): HEAD fails, the working tree loads."""
import os
import re
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SKIP = re.compile(r"/(u|w|open|players|backup|old|bak|log|data|doc)/")
END = re.compile(r'([　-鿿＀-￯])(\s*\)?\s*;\s*(?://.*)?)$')


def odd_quotes(line):
    s = re.sub(r"\\.", "", line)
    s = re.sub(r"'.'", "", s)
    return s.count('"') % 2 == 1


def fix_text(t):
    lines = t.split("\n")
    n = 0
    for i, raw in enumerate(lines):
        line = raw[:-1] if raw.endswith("\r") else raw
        cr = "\r" if raw.endswith("\r") else ""
        if '"' not in line or line.lstrip().startswith(("//", "*", "/*")):
            continue
        if not odd_quotes(line):
            continue
        m = END.search(line)
        if not m:
            continue
        # the last quote must open the unterminated string: text after it, up to the end, has no quote
        last = line.rfind('"')
        if last > m.start(1):
            continue
        lines[i] = line[:m.end(1)] + '"' + line[m.end(1):] + cr
        n += 1
    return "\n".join(lines), n


def main():
    args = sys.argv[1:]
    apply = "--apply" in args
    tot = 0
    for slug in [a for a in args if not a.startswith("--")]:
        work = f"{REPO}/libs/{slug}/work"
        if os.path.exists(f"{work}/.git"):
            continue
        for dp, dn, fn in os.walk(work):
            if SKIP.search(dp[len(work):] + "/"):
                continue
            for f in fn:
                if not f.endswith((".lpc", ".h")):
                    continue
                p = os.path.join(dp, f)
                b = open(p, "rb").read()
                if b'"' not in b:
                    continue
                try:
                    t = b.decode("utf-8")
                except UnicodeDecodeError:
                    continue
                out, n = fix_text(t)
                if n:
                    tot += n
                    print(f"FIX   {slug} {p[len(work):]}  {n}")
                    if apply:
                        open(p, "wb").write(out.encode("utf-8"))
    print(f"{tot} line(s)" + ("" if apply else " (plan only; --apply writes)"))


if __name__ == "__main__":
    main()
