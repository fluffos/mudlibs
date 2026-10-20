#!/usr/bin/env python3
"""scripts/lpc_fix_cat_unchecked.py [--apply] [SLUG...]

The simulated efun `cat(file)` of the Eastern Story / xkx lineage,

  void cat(string file) {
    write(read_file(file));
  }

writes whatever `read_file()` answers; for a file that is not there (a banner or MOTD the archive does not ship, a log file that only a running mud creates: `/log/login/notice`,
`/adm/etc/new.txt`) that is 0, and `write(0)` is an error in this driver (`Bad argument 1 to receive()  Expected: string or buffer Got: 0`), which aborts the caller: in the
login dialogue of xiyouji2006 and xyj2006zzzhx the "wrong client" banner died before the connection was closed.  The old driver printed nothing.  Becomes
`write(read_file(file) || "");` (KB 06 section 7.285, 7.296).  Only the statement that is the whole body of a function named `cat` in a simulated efun file is touched; other
`write(read_file(...))` lines are listed, not changed.  Binary-safe, idempotent.

Without --apply the plan is printed: `FIX<TAB>slug<TAB>/path` per file; the listed (untouched) shapes as `LIST<TAB>slug<TAB>/path:line<TAB>text`."""
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import lpc_scan_cond_assign as sc  # noqa: E402
import lpc_add_sefun as S  # noqa: E402

REPO = sc.REPO
CAT = re.compile(rb"((?:varargs\s+)?(?:void|int)\s+cat\s*\(\s*string\s+(\w+)\s*\)\s*\{\s*)write\(\s*read_file\(\s*\2\s*\)\s*\)\s*;")


def main():
    a = sys.argv[1:]
    apply_ = "--apply" in a
    slugs = [x for x in a if not x.startswith("--")]
    n = 0
    for slug, paths in sorted(sc.tracked(slugs).items()):
        if slug in sc.LDMUD or slug in sc.GENERATED:
            continue
        try:
            files = S.sefun_files(slug)
        except OSError:
            continue
        for f in files:
            try:
                b = open(f, "rb").read()
            except OSError:
                continue
            m = CAT.search(b)
            if not m:
                continue
            rel = "/" + os.path.relpath(f, f"{REPO}/libs/{slug}/work")
            n += 1
            print(f"FIX\t{slug}\t{rel}")
            if apply_:
                var = m.group(2)
                new = m.group(1) + b'write(read_file(' + var + b') || "");'
                open(f, "wb").write(b[:m.start()] + new + b[m.end():])
    print(f"{n} file(s)", file=sys.stderr)


if __name__ == "__main__":
    main()
