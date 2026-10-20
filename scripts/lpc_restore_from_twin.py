#!/usr/bin/env python3
"""scripts/lpc_restore_from_twin.py (SLUG... | --list FILE) [--any] [--refine] [--tail] [--apply] [--backup DIR] [--max-gap N] [--max-total N] [--any-run] [--verbose]

Punctuation a conversion lost (KB 03 section 4.6), put back from an intact copy of the same file in another lib.

A file that fails to compile, most often with a raw byte >= 0x80 in code (the `Illegal character 0xNN` of scripts/lpc_scan_high_bytes.py: the
text after a lost opening or closing quote is read as code) but also a statement without its `;`, a mapping entry without its `,`, a
function without its last `}}`, is compared with the file at the same path in every other lib whose copy has no such byte and whose own scan
did not report it (`.c` too, for the upstream gitlink libs).  The comparison ignores white space, so a copy that went through the formatter,
or the other lib's own layout, still matches.  When the damaged file is the donor's code *minus a few short runs* (every missing run at most
`--max-gap` bytes, default 4) and nothing else, the runs go back into the damaged file at the places the donor has them (attached to the
character before, as a `;` or `)` is; or right before the next one, as an opening quote or a `}` on its own line is), the file's own white space
and everything else untouched.  Only runs of `; , ( ) { } [ ]` and `"`, or the last letters of a keyword (`els` -> `else`), are put back: a donor that
differs by `/* */`, `:1` or a letter is another version of the file, not the same file after damage, and stays alone (`--any-run` lifts this).
The result is the donor's code character for character, so it cannot read differently from a copy that compiles; any other difference (a lost
half character, a different version, text the donor does not have) leaves the file alone, to be repaired by hand (scripts/lpc_fix_eaten_quote.py
for the lines that end in text and `;`).

After the runs are back, every one-line string literal that differs from the donor's only by white space (a formatter's `/ d / eastland / data` for
`/d/eastland/data`) takes the donor's text; `--refine` does only that, for files already identical to a donor but for such spacing.

`--tail` handles a file that ends in garbage (`locate_quest(this_player(), arg  厀) 鲦 ~m #  烎`: the end of the function went with a lone lead
byte): when the file is the donor's code up to a point and at most 80 bytes of text with raw high bytes follow, the donor's text from that point
on replaces them (the donor has at most 800 bytes there).

Without --apply the plan is printed: `slug<TAB>path<TAB>runs put back<TAB>donor`.  The damaged files are found by scanning the libs named (a
lib takes minutes; only files with a raw byte in code, unless `--any`), or read from `--list FILE`: one `slug<TAB>/path` per line, or the
`HB<TAB>slug<TAB>/path<TAB>...` lines of lpc_scan_high_bytes.py, or the files of a diagnostics file's syntax-type errors in that form (`--any`
then takes every listed file as damaged).  Wizard, backup, data and `old`/`bak` paths are skipped like the scanner does.  `--backup DIR` keeps
the original bytes of every file written.  Load-check the changed files afterwards (scripts/lpc_listcheck.sh, scripts/lpc_load_diff.py): HEAD
fails, the tree loads; put a file back from the backup when it did not fail before or still fails.
"""
import os
import re
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from lpc_fix_void_return import code_mask  # noqa: E402
from lpc_scan_high_bytes import SKIP  # noqa: E402

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
WS = frozenset(b" \t\r\n\f\v")
GENERATED = {"longyunmeng_binary", "wllz3"}


def raw_high_in_code(b):
    if not re.search(rb"[\x80-\xff]", b):
        return False
    m = code_mask(b, heredoc=True)
    return next((i for i, c in enumerate(b) if c >= 0x80 and m[i]), None) is not None


def squeeze(b):
    """(bytes without white space, position of each in b)"""
    out = bytearray()
    pos = []
    for i, c in enumerate(b):
        if c not in WS:
            out.append(c)
            pos.append(i)
    return bytes(out), pos


def literal_spans(b):
    """(start, end) of every double-quoted string literal in code (comments and char constants skipped; a literal may run over lines)"""
    spans = []
    i, n = 0, len(b)
    while i < n:
        c = b[i:i + 1]
        if b[i:i + 2] == b"//":
            j = b.find(b"\n", i)
            i = n if j < 0 else j
            continue
        if b[i:i + 2] == b"/*":
            j = b.find(b"*/", i + 2)
            i = n if j < 0 else j + 2
            continue
        if c == b'"' or (c == b"'" and (b[i + 2:i + 3] == b"'" or b[i + 1:i + 2] == b"\\")):
            j = i + 1
            while j < n and b[j:j + 1] != c and not (c == b"'" and b[j:j + 1] == b"\n"):
                j += 2 if b[j:j + 1] == b"\\" else 1
            if c == b'"':
                spans.append((i, min(j + 1, n)))
            i = j + 1
            continue
        i += 1
    return spans


def refine_literals(d, c):
    """d with every one-line string literal that differs from the donor's only by white space (a formatter's `/ d / eastland / data` for
    `/d/eastland/data`) replaced by the donor's; (bytes, count), or None when the two do not have the same number of literals"""
    sd, sc = literal_spans(d), literal_spans(c)
    if len(sd) != len(sc):
        return None
    edits = []
    for (a, b), (x, y) in zip(sd, sc):
        ld, lc = d[a:b], c[x:y]
        if ld != lc and b"\n" not in ld and b"\n" not in lc and squeeze(ld)[0] == squeeze(lc)[0]:
            edits.append((a, b, lc))
    out = bytearray(d)
    for a, b, lc in sorted(edits, reverse=True):
        out[a:b] = lc
    return bytes(out), len(edits)


def plan_tail(d, c, dsq, csq, max_garbage=80, max_tail=800):
    """(d_cut, c_cut) when d is c's code up to a point and then at most max_garbage bytes of garbage (a conversion that lost the end
    of the file and left bytes >= 0x80 in code), c has at most max_tail bytes after that point: d[:d_cut] + c[c_cut:] is c's code."""
    dn, dp = dsq
    cn, cp = csq
    n = 0
    m = min(len(dn), len(cn))
    while n < m and dn[n] == cn[n]:
        n += 1
    if n == len(dn) or n == len(cn):
        return None                                   # one is a prefix of the other: a truncation, not garbage
    if len(dn) - n > max_garbage or len(cn) - n > max_tail or n < 0.9 * len(dn):
        return None
    if not any(b >= 0x80 for b in dn[n:]):
        return None                                   # the damage must show as raw bytes
    d_cut = dp[n - 1] + 1 if n else 0
    c_cut = cp[n - 1] + 1 if n else 0
    return d_cut, c_cut


PUNCT = frozenset(b';,(){}[]"')
KEYWORDS = {b"else", b"return", b"while", b"break", b"continue", b"switch", b"default", b"case", b"foreach", b"inherit", b"include", b"void", b"string", b"object", b"mapping", b"mixed", b"int", b"float"}


def allowed_run(d, off, run):
    """A run worth putting back: closing/opening punctuation a conversion drops, or the last letters of a keyword."""
    if all(b in PUNCT for b in run):
        return True
    if run.isalpha():
        a = off
        while a > 0 and (d[a - 1:a].isalpha() or d[a - 1:a] == b"_"):
            a -= 1
        e = off
        while e < len(d) and (d[e:e + 1].isalpha() or d[e:e + 1] == b"_"):
            e += 1
        return d[a:off] + run + d[off:e] in KEYWORDS
    return False


def plan_inserts(d, c, max_gap, max_total, dsq=None, csq=None, any_run=False):
    dsq = dsq or squeeze(d)
    csq = csq or squeeze(c)
    for window in (12, 5):
        r = _plan(d, c, max_gap, max_total, dsq, csq, any_run, window)
        if r is not None:
            return r
    return None


def _plan(d, c, max_gap, max_total, dsq, csq, any_run, window):
    """Offsets in d at which bytes of c go (list of (offset, bytes)), or None.  d must be c's code with short runs missing:
    every run c has and d lacks is at most max_gap bytes long, all together at most max_total bytes, and the two agree everywhere else
    (white space ignored).  After a mismatch the next 12 bytes (fewer at the end; 5 when two gaps are close) decide which run was lost."""
    dn, dp = dsq
    cn, cp = csq
    if len(cn) - len(dn) < 1 or len(cn) - len(dn) > max_total:
        return None
    ins = []
    i = j = 0
    total = 0
    while j < len(cn):
        if i < len(dn) and dn[i] == cn[j]:
            i += 1
            j += 1
            continue
        k = min(window, len(dn) - i)
        gap = None
        for g in range(1, max_gap + 1):
            if j + g > len(cn):
                break
            if cn[j + g:j + g + k] == dn[i:i + k] and (k == window or j + g + k == len(cn)):
                gap = g
                break
        if gap is None:
            return None
        run = cn[j:j + gap]
        total += gap
        if total > max_total:
            return None
        pc = cp[j]
        pe = cp[j + gap - 1]
        before_ws = pc == 0 or c[pc - 1] in WS
        if i >= len(dn):
            off = len(d)
        elif not before_ws and i > 0:
            off = dp[i - 1] + 1                    # attached to the character before it (`)`, `;`, a closing quote)
        else:
            off = dp[i]                            # starts something (an opening quote, a `}` on its own line): right before the next character
        if not any_run and not allowed_run(d, off, bytes(run)):
            return None
        ins.append((off, bytes(run)))
        j += gap
    if i != len(dn):
        return None
    return ins


def apply_inserts(d, ins):
    out = bytearray(d)
    for off, run in sorted(ins, key=lambda t: t[0], reverse=True):
        out[off:off] = run
    return bytes(out)


def failing_files():
    """{lib: set of paths with an error row} from the newest scan diagnostics under $LPC_SCRATCH (empty when there are none)"""
    import glob
    scratch = os.environ.get("LPC_SCRATCH", os.path.expanduser("~/.cache/lpc-scratch"))
    newest = {}
    for pat in (f"{scratch}/fresh/out*/diag-*.tsv", f"{scratch}/tkfix/diag/*.tsv"):
        for p in glob.glob(pat):
            b = os.path.basename(p)
            slug = b[5:-4] if b.startswith("diag-") else b[:-4]
            if slug not in newest or os.path.getmtime(p) > os.path.getmtime(newest[slug]):
                newest[slug] = p
    out = {}
    for slug, p in newest.items():
        errs = set()
        for ln in open(p, encoding="utf-8", errors="replace"):
            f = ln.rstrip("\n").split("\t")
            if len(f) >= 5 and f[3] == "error":
                errs.add(f[0])
        out[slug] = errs
    return out


def main():
    args = sys.argv[1:]
    apply = "--apply" in args
    verbose = "--verbose" in args
    anyfile = "--any" in args
    refine = "--refine" in args
    tail = "--tail" in args
    any_run = "--any-run" in args
    backup = args[args.index("--backup") + 1] if "--backup" in args else None
    mg = 4
    mt = 4000
    if "--max-gap" in args:
        mg = int(args[args.index("--max-gap") + 1])
    if "--max-total" in args:
        mt = int(args[args.index("--max-total") + 1])
    lst = None
    if "--list" in args:
        lst = args[args.index("--list") + 1]
    slugs = [a for a in args if not a.startswith("--") and not a.isdigit() and a != lst and a != backup]
    cand = []
    if lst:
        seen = set()
        for ln in open(lst, encoding="utf-8", errors="replace"):
            f = ln.rstrip("\n").split("\t")
            if f and f[0] == "HB":
                f = f[1:]
            if len(f) < 2 or not f[1].startswith("/") or (f[0], f[1]) in seen:
                continue
            seen.add((f[0], f[1]))
            slug, rel = f[0], f[1]
            if slug in GENERATED or (slugs and slug not in slugs) or SKIP.search(rel) or not rel.endswith((".lpc", ".h")):
                continue
            cand.append((slug, rel, f"libs/{slug}/work{rel}"))
    else:
        if not slugs:
            sys.exit(__doc__)
        for slug in slugs:
            files = subprocess.run(["git", "ls-files", "-z", "--", f"libs/{slug}/work"], cwd=REPO, capture_output=True).stdout.split(b"\0")
            for f in files:
                try:
                    p = f.decode()
                except UnicodeDecodeError:
                    continue
                if not p.endswith((".lpc", ".h")) or slug in GENERATED:
                    continue
                rel = "/" + p.split("/work/", 1)[1]
                if SKIP.search(rel):
                    continue
                cand.append((slug, rel, p))
    # only the damaged ones need donors
    damaged = []
    for slug, rel, p in cand:
        try:
            if anyfile or raw_high_in_code(open(os.path.join(REPO, p), "rb").read()):
                damaged.append((slug, rel, p))
        except OSError:
            continue
    cand = damaged
    libs = sorted(d for d in os.listdir(f"{REPO}/libs") if os.path.isdir(f"{REPO}/libs/{d}/work") and d not in GENERATED)
    donors = {}                                # rel -> [(lib, path)]
    want = {rel for _, rel, _ in cand}
    for lib in libs:
        base = f"{REPO}/libs/{lib}/work"
        for rel in want:
            for r in (rel, rel[:-4] + ".c" if rel.endswith(".lpc") else None):
                if r and os.path.isfile(base + r) and not os.path.islink(base + r):
                    donors.setdefault(rel, []).append((lib, base + r))
    cache = {}
    bad = failing_files()
    done = fail = 0
    for slug, rel, p in cand:
        try:
            d = open(os.path.join(REPO, p), "rb").read()
        except OSError:
            continue
        if not anyfile and not raw_high_in_code(d):
            continue
        best = None
        dsq = squeeze(d)
        for lib, q in donors.get(rel, []):
            if lib == slug:
                continue
            tail = q[len(f"{REPO}/libs/{lib}/work"):]
            if tail in bad.get(lib, ()) or (tail[:-2] + ".lpc") in bad.get(lib, ()):
                continue                          # the donor's own scan did not compile it
            if q not in cache:
                try:
                    cb = open(q, "rb").read()
                except OSError:
                    cb = None
                cache[q] = (cb, squeeze(cb)) if cb is not None and not raw_high_in_code(cb) else None
            if cache[q] is None:
                continue
            c, csq = cache[q]
            if tail:
                cut = plan_tail(d, c, dsq, csq)
                if cut:
                    best = ((d[:cut[0]] + c[cut[1]:], 1), lib)
                    break
                continue
            if refine:
                if csq[0] == dsq[0]:
                    r = refine_literals(d, c)
                    if r and r[1]:
                        best = (r, lib)
                        break
                continue
            if len(csq[0]) - len(dsq[0]) < 1 or len(csq[0]) - len(dsq[0]) > mt:
                continue
            ins = plan_inserts(d, c, mg, mt, dsq, csq, any_run)
            if ins is not None and (best is None or len(ins) < len(best[0])):
                best = (ins, lib)
                if len(ins) == 1:
                    break
        if not best:
            fail += 1
            if verbose:
                print(f"-\t{slug}\t{rel}")
            continue
        ins, lib = best
        if refine or tail:
            out = ins[0]
            ins = [None] * ins[1]
        else:
            out = apply_inserts(d, ins)
            dcache = cache[[q for l, q in donors.get(rel, []) if l == lib][0]][0]
            r = refine_literals(out, dcache)
            if r and r[1]:
                out = r[0]
        if raw_high_in_code(out):
            fail += 1
            if verbose:
                print(f"-(still high)\t{slug}\t{rel}")
            continue
        done += 1
        print(f"{slug}\t{rel}\t{len(ins)}\t{lib}")
        if apply:
            if backup:
                bp = os.path.join(backup, p)
                os.makedirs(os.path.dirname(bp), exist_ok=True)
                with open(bp, "wb") as fh:
                    fh.write(d)
            with open(os.path.join(REPO, p), "wb") as fh:
                fh.write(out)
    print(f"{done} file(s) {'restored' if apply else 'restorable'}, {fail} damaged file(s) without a donor that differs by quotes only", file=sys.stderr)


if __name__ == "__main__":
    main()
