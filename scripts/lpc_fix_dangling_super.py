#!/usr/bin/env python3
"""scripts/lpc_fix_dangling_super.py --diag DIR [SLUG...] [--apply] [--all-files]

A call to an inherited function the parents do not have (KB 04 section 6.10, KB 06 section 7.259).  `::create();` at the end of
`create()`, `::init();` in a book's `init()`, `::setup();` in an NPC: the object inherits a base (a unique-item feature, a book,
an NPC class) that defines no `create()` / `init()` / `setup()`, and the driver says `Unable to find the inherited function
'create'.`  The old driver took a call with nothing behind it for a no-op that returns 0, so the line was written against bases
that have the function in some lineage and was harmless against the ones that do not; here the object never compiles.

--diag DIR  the scan output of scripts/lpc_warnings.py (DIR/diag-SLUG.tsv).  Every row `Unable to find the inherited function
            'fn'.` names a file and a line; the `::fn(...)` / `scope::fn(...)` call on that line is the one.  When the driver
            also says `in file 'unique'`, that scope picks `unique::init()` over a neighbour `cloth::init()` in the same window.
A call written as a statement (`::create();`) is deleted (the whole line when nothing else is on it); `return ::fn(...);` becomes
`return;` in a void function and `return 0;` in any other.  A call inside an expression (`if (::do_advance(str))`,
`ret = ::checking(me, ob);`), the body of an `if` or `else` without braces, a macro, or a line that holds several `::` calls is
left (SKIP with the reason): there the missing base is the real defect.  Exact-line match is tried before SKIP when several
`::fn(` share the near-line window and no `in file` scope is present.
Only files whose every error is such a dangling call are edited: a file that also has an `inherit` the lib cannot resolve gets
the message because its parent is missing, and removing the call would drop the parent's `create()` once the base is restored
(--all-files edits the others too).  Comments, strings and here-docs are masked; the file's own line endings are kept; wizard,
backup and example dirs are skipped.  Without --apply the plan is printed (FIX lines: `lib file:line before -> after`).
Idempotent: a deleted call is no longer reported."""
import collections
import glob
import os
import re
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from lpc_fix_void_return import code_mask  # noqa: E402

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SKIP = re.compile(r"/(u|w|wiz|wizard|wizards|players|backup|backups|old|bak|log|data|doc|docs|example|examples|test|tmp|attic)/|[-_.](bak|old|orphaned-driver-src)/|\.(bak|BAK|old|orig)(\.lpc)?$")
EFUNS = set()
for _f in glob.glob(os.path.expanduser("~/src/fluffos/docs/efun/*/*.md")):
    EFUNS.add(os.path.basename(_f)[:-3])
MSG = re.compile(r"Unable to find the inherited function '([^']+)'(?: in file '([^']+)')?")
KEYWORDS = {b"return", b"else", b"do", b"case", b"default", b"in", b"if", b"while", b"for", b"foreach", b"switch", b"catch"}
TYPES = re.compile(rb"^(?:(?:private|static|nomask|varargs|public|protected|nosave|atomic)\s+)*([A-Za-z_]\w*(?:\s+[A-Za-z_]\w*)?)\s*\**\s*[A-Za-z_]\w*\s*\(")


def match_close(code, i, open_c, close_c):
    depth = 0
    for j in range(i, len(code)):
        c = code[j:j + 1]
        if c == open_c:
            depth += 1
        elif c == close_c:
            depth -= 1
            if depth == 0:
                return j
    return -1


def functions(code):
    """-> [(body_start, body_end, is_void)] of the top-level functions of the masked buffer"""
    res = []
    depth = 0
    last = 0          # end of the previous top-level construct
    i = 0
    n = len(code)
    while i < n:
        c = code[i:i + 1]
        if c == b"{":
            if depth == 0:
                head = code[last:i]
                head = re.sub(rb"(?m)^[ \t]*#[^\n]*", b"", head).strip()
                m = TYPES.match(head) if head.endswith(b")") else None
                end = match_close(code, i, b"{", b"}")
                if m is not None and end > 0:
                    t = m.group(1).split()
                    t = [x for x in t if x not in (b"varargs", b"static", b"nomask", b"private", b"public", b"protected", b"nosave", b"atomic")]
                    res.append((i, end, bool(t) and t[-1] == b"void"))
                if end < 0:
                    break
                i = end + 1
                last = i
                continue
            depth += 1
        elif c == b"}":
            depth -= 1
        elif c == b";" and depth == 0:
            last = i + 1
        i += 1
    return res


def plan(b, rows):
    """-> (edits [(start, end, replacement, line, before, after)], skips [(line, fn, reason)])

    rows are (line, fn) or (line, fn, scope).  scope is the driver's `in file 'unique'`
    basename when the call was written `unique::init()` next to a live `cloth::init()`:
    without it the near-line window sees two `::init(` and the row was SKIP.
    """
    mask = code_mask(b, heredoc=True)
    code = bytes(c if m else 32 for c, m in zip(b, mask))
    funcs = None
    starts = [0]
    for m in re.finditer(rb"\n", b):
        starts.append(m.end())

    def line_of(pos):
        lo, hi = 0, len(starts)
        while lo + 1 < hi:
            mid = (lo + hi) // 2
            if starts[mid] <= pos:
                lo = mid
            else:
                hi = mid
        return lo + 1

    def call_scope(m):
        """Identifier immediately before `::fn(` (`unique` of `unique::init()`), else None."""
        s0 = m.start()
        w = re.search(rb"([A-Za-z_]\w*)[ \t]*$", code[max(0, s0 - 60):s0])
        if w and w.group(1) not in KEYWORDS:
            return w.group(1).decode()
        return None

    edits, skips = [], []
    for row in sorted(rows, key=lambda r: (r[0], r[1])):
        ln, fn = row[0], row[1]
        scope = row[2] if len(row) > 2 else None
        if fn in EFUNS:
            skips.append((ln, fn, "an efun: in a simul_efun file the call is `efun::%s(`, not a missing parent" % fn))
            continue
        if fn.startswith("init_"):
            skips.append((ln, fn, "a weapon/armor constructor: the type name is wrong, not the parent missing"))
            continue
        pat = re.compile(rb"::[ \t]*" + re.escape(fn.encode()) + rb"[ \t]*\(")
        cands = [m for m in pat.finditer(code) if ln - 3 <= line_of(m.start()) <= ln + 1 and mask[m.end() - 1]]
        if scope:
            scoped = [m for m in cands if (call_scope(m) or "").lower() == scope.lower()]
            if len(scoped) == 1:
                cands = scoped
            elif not scoped:
                # basename of a path (`feature/unique` → `unique`)
                base = scope.rsplit("/", 1)[-1].lower()
                scoped = [m for m in cands if (call_scope(m) or "").lower() == base]
                if len(scoped) == 1:
                    cands = scoped
        if len(cands) != 1:
            # Prefer the call that sits on the reported line when several `::fn(` share a window
            on_line = [m for m in cands if line_of(m.start()) == ln]
            if len(on_line) == 1:
                cands = on_line
        if len(cands) != 1:
            skips.append((ln, fn, "%d `::%s(` calls near the line" % (len(cands), fn)))
            continue
        m = cands[0]
        s = m.start()
        # a scope name belongs to the call (`unique::init()`), a keyword in front of the `::` does not (`return ::init()`)
        w = re.search(rb"([A-Za-z_]\w*)[ \t]*$", code[max(0, s - 60):s])
        if w and w.group(1) not in KEYWORDS:
            s = s - (len(code[max(0, s - 60):s]) - w.start(1))
        p_open = m.end() - 1
        p_close = match_close(code, p_open, b"(", b")")
        if p_close < 0:
            skips.append((ln, fn, "unbalanced parentheses"))
            continue
        k = p_close + 1
        while k < len(code) and code[k:k + 1] in b" \t\r\n":
            k += 1
        j = s - 1
        while j >= 0 and code[j:j + 1] in b" \t\r\n":
            j -= 1
        prev = code[j:j + 1] if j >= 0 else b";"
        lstart = starts[line_of(s) - 1]
        if code[lstart:s].lstrip().startswith(b"#"):
            skips.append((ln, fn, "inside a macro"))
            continue
        if code[k:k + 1] != b";":
            skips.append((ln, fn, "the call is part of an expression"))
            continue
        before = b[s:k + 1].decode("utf-8", "replace")
        before = re.sub(r"\s+", " ", before)
        if prev in (b";", b"{", b"}"):
            # a statement: delete it, with its line when nothing else is on it
            e = k + 1
            ls = lstart
            le = b.find(b"\n", e)
            le = len(b) if le < 0 else le + 1
            if not b[ls:s].strip() and not b[e:le].strip():
                edits.append((ls, le, b"", ln, before, "(line deleted)"))
            else:
                e2 = e
                while e2 < len(b) and b[e2:e2 + 1] in b" \t":
                    e2 += 1
                edits.append((s, e2 if b[e2:e2 + 1] not in b"\r\n" else e, b"", ln, before, "(deleted)"))
        elif re.search(rb"(?<![A-Za-z0-9_])return$", code[max(0, s - 8):j + 1]):
            if funcs is None:
                funcs = functions(code)
            void = None
            for bs, be, isv in funcs:
                if bs < s < be:
                    void = isv
            if void is None:
                skips.append((ln, fn, "return outside a function the scan found"))
                continue
            rs = j + 1 - len(b"return")
            rep = b"return;" if void else b"return 0;"
            edits.append((rs, k + 1, rep, ln, before, rep.decode()))
        else:
            skips.append((ln, fn, "after `%s`" % code[max(0, j - 6):j + 1].decode("utf-8", "replace").strip()))
    return edits, skips


def main():
    args = sys.argv[1:]
    apply = "--apply" in args
    allfiles = "--all-files" in args
    diag = None
    if "--diag" in args:
        i = args.index("--diag")
        diag = args[i + 1]
        del args[i:i + 2]
    only = [a for a in args if not a.startswith("--")]
    if not diag:
        sys.exit(__doc__)
    nedit = nfile = nskip = 0
    libs = set()
    for f in sorted(glob.glob(os.path.join(diag, "diag-*.tsv"))):
        slug = os.path.basename(f)[5:-4]
        if only and slug not in only:
            continue
        if not os.path.isdir(f"{REPO}/libs/{slug}/work") or os.path.exists(f"{REPO}/libs/{slug}/work/.git") or slug == "longyunmeng_binary":
            continue
        errs = collections.defaultdict(list)    # path -> [(line, message)]
        for l in open(f, encoding="utf-8", errors="replace"):
            p = l.rstrip("\n").split("\t")
            if len(p) >= 5 and p[3] == "error" and not SKIP.search(p[0]):
                errs[p[0]].append((int(p[1]), p[4]))
        for path, rr in sorted(errs.items()):
            rows = []
            for ln, msg in rr:
                mm = MSG.match(msg)
                if not mm:
                    continue
                rows.append((ln, mm.group(1), mm.group(2)) if mm.group(2) else (ln, mm.group(1)))
            if not rows:
                continue
            if len(rows) != len(rr) and not allfiles:
                continue
            full = f"{REPO}/libs/{slug}/work{path}"
            try:
                b = open(full, "rb").read()
            except OSError:
                continue
            edits, skips = plan(b, rows)
            for ln, fn, why in skips:
                nskip += 1
                print(f"SKIP  {slug} {path}:{ln} ::{fn}(): {why}")
            if not edits:
                continue
            nfile += 1
            nedit += len(edits)
            libs.add(slug)
            for s, e, rep, ln, before, after in edits:
                print(f"FIX   {slug} {path}:{ln} {before} -> {after}")
            if apply:
                out, last = [], 0
                for s, e, rep, ln, before, after in sorted(edits):
                    out.append(b[last:s])
                    out.append(rep)
                    last = e
                out.append(b[last:])
                open(full, "wb").write(b"".join(out))
    print(f"{nedit} call(s) in {nfile} file(s) of {len(libs)} lib(s), {nskip} left" + ("" if apply else " (plan only; --apply writes)"))


if __name__ == "__main__":
    main()
