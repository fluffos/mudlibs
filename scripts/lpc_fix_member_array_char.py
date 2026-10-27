#!/usr/bin/env python3
"""scripts/lpc_fix_member_array_char.py [--apply] [SLUG...]

`member_array('/', str)`, `member_array('"', value) != -1`: the int-in-string form of member_array() is a BYTE search (strchr): its start offset and its
result are byte offsets, and only a single byte can match.  The FluffOS of 2026-10-18 (923cdbc0) logs one warning per call site, at run time, when the
byte answer differs from the character answer, i.e. the string holds non-ASCII text before the match (`/pkuxkx std/json.lpc`: every Chinese string a JSON
encoder tests for a quote).  On UTF-8 text the offset is also wrong for `str[0..idx-1]`, which counts characters.  `strsrch(str, "c")` is the same search by
character: the same -1 when absent, the same index for ASCII text, the character index otherwise.

`member_array('c', STR)` becomes `strsrch(STR, "c")` when STR is a string: a string literal, a name declared `string` (a plain `string`, not `string *`) in the
enclosing function, its parameters or the file, or a call of a string-valued efun/sefun (lower_case, read_file, replace_string, sprintf, ...).  The character
literal is rewritten as the one-character string (`'\\n'` -> `"\\n"`, `'"'` -> `"\\""`, `'\\''` -> `"'"`).  A call with a third argument (a start offset: strsrch() has
none), an array literal, a name declared `mixed` / `int *`, or any other expression is listed, not touched.  LDMud libs (the ports whose sources are LDMud's) are
skipped: their member_array is another efun.  Only code is touched; wizard, backup and test directories are skipped like the other mechanical fixers do.
Binary-safe, idempotent.  Without --apply the plan is printed (`FIX<TAB>slug<TAB>/path<TAB>n` and `LIST<TAB>slug<TAB>/path:line<TAB>why: call`)."""
import os
import re
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from lpc_fix_void_return import code_mask, depth_map  # noqa: E402
from lpc_fix_bad_assign import decl_for  # noqa: E402

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SKIP = re.compile(r"/(u|w|wiz|wizard|wizards|players|backup|backups|old|bak|log|data|doc|docs|example|examples|test|tests|tmp|attic)/|[-_.](bak|old)/|\.(bak|BAK|old|orig)(\.lpc)?$")
GENERATED = {"wllz3", "longyunmeng_binary"}
LDMUD = {"aoh", "morgengrauen", "nirvlp312", "simud", "sticklib", "skylib", "sluggymud", "swmud", "spacemud", "wilderness", "immaster", "amylaarmini", "mundoscuro",
         "ageofelements", "acme", "scratch", "paomud", "sagenwelt", "xxsj"}
CALL = re.compile(rb"member_array\s*\(")
CHAR = re.compile(rb"\s*'(\\.|[^'\\])'\s*$")
STRFUNCS = (b"lower_case", b"upper_case", b"capitalize", b"read_file", b"replace_string", b"sprintf", b"implode", b"trim", b"query_verb", b"remove_ansi",
            b"strip_ansi", b"base_name", b"file_name", b"save_variable", b"string_encode", b"string_decode")
ESC = {b"\\n": b"\\n", b"\\t": b"\\t", b"\\r": b"\\r", b"\\b": b"\\b", b"\\\\": b"\\\\", b"\\'": b"'", b'\\"': b'\\"', b"\\e": b"\\e"}


def tracked(slugs):
    out = subprocess.run(["git", "ls-files", "-s", "-z", "--", "libs"], cwd=REPO, capture_output=True).stdout.split(b"\0")
    gitlinks, by = set(), {}
    for ent in out:
        if not ent:
            continue
        meta, _, path = ent.partition(b"\t")
        try:
            p = path.decode("utf-8")
        except UnicodeDecodeError:
            continue
        parts = p.split("/")
        if len(parts) < 3 or parts[0] != "libs":
            continue
        slug = parts[1]
        if meta.split()[0] == b"160000":
            gitlinks.add(slug)
            continue
        if len(parts) > 3 and parts[2] == "work" and p.endswith((".lpc", ".h")):
            by.setdefault(slug, []).append(p)
    return {s: f for s, f in by.items() if s not in gitlinks and s not in GENERATED and s not in LDMUD and (not slugs or s in slugs)}


def split_call(b, mask, open_at):
    """(end_index_of_closing_paren, [arg byte ranges]) of the call whose `(` is at open_at, or None"""
    depth, i, start, args = 0, open_at, open_at + 1, []
    while i < len(b):
        if mask[i]:
            c = b[i]
            if c in b"([{":
                depth += 1
            elif c in b")]}":
                depth -= 1
                if depth == 0:
                    args.append((start, i))
                    return i, args
            elif c == 0x2c and depth == 1:
                args.append((start, i))
                start = i + 1
        i += 1
    return None


def string_like(b, mask, dep, expr, at):
    """True when the argument expression `expr` (bytes, located at `at`) is certainly a string"""
    e = expr.strip()
    if re.fullmatch(rb'"(?:[^"\\\n]|\\.)*"', e):
        return True
    m = re.fullmatch(rb"[A-Za-z_]\w*", e)
    if m:
        d = decl_for(b, mask, dep, e.decode(), at)
        if d:
            t0, t1, star = d
            return b[t0:t1] == b"string" and star is None
        return False
    m = re.match(rb"([A-Za-z_]\w*)\s*\(", e)
    return bool(m and m.group(1) in STRFUNCS and e.endswith(b")"))


def fix(b):
    if not CALL.search(b):
        return None, 0, []
    mask = code_mask(b)
    dep = depth_map(b, mask)
    edits, listed = [], []
    for m in CALL.finditer(b):
        if not mask[m.start()]:
            continue
        open_at = m.end() - 1
        sc = split_call(b, mask, open_at)
        if not sc:
            continue
        end, args = sc
        line = b.count(b"\n", 0, m.start()) + 1
        text = re.sub(rb"\s+", b" ", b[m.start():end + 1]).decode("utf-8", "replace")[:100]
        a1 = b[args[0][0]:args[0][1]]
        cm = CHAR.match(a1)
        if not cm:
            continue                       # not a character literal first argument: an array search
        if len(args) != 2:
            listed.append((line, "start offset: " + text))
            continue
        lit = cm.group(1)
        if lit.startswith(b"\\"):
            if lit not in ESC:
                listed.append((line, "escape: " + text))
                continue
            sl = ESC[lit]
        else:
            sl = lit
            if sl == b'"':
                sl = b'\\"'
        expr = b[args[1][0]:args[1][1]]
        if not string_like(b, mask, dep, expr, args[1][0]):
            listed.append((line, "not a certain string: " + text))
            continue
        edits.append((m.start(), end + 1, b'strsrch(' + expr.strip() + b', "' + sl + b'")'))
    if not edits:
        return None, 0, listed
    # nested calls: apply the outermost edits only (an inner one is rewritten by the next run)
    edits.sort()
    keep, last_end = [], -1
    for s, e, rep in edits:
        if s >= last_end:
            keep.append((s, e, rep))
            last_end = e
    out = bytearray(b)
    for s, e, rep in reversed(keep):
        out[s:e] = rep
    return bytes(out), len(keep), listed


def main():
    a = sys.argv[1:]
    apply_ = "--apply" in a
    slugs = {x for x in a if not x.startswith("--")}
    total = files = lst = 0
    for slug, paths in sorted(tracked(slugs).items()):
        for p in paths:
            rel = "/" + p.split("/work/", 1)[1]
            if SKIP.search(rel):
                continue
            try:
                b = open(os.path.join(REPO, p), "rb").read()
            except OSError:
                continue
            if b"member_array" not in b or b"'" not in b:
                continue
            new, n, listed = fix(b)
            for ln, why in listed:
                print(f"LIST\t{slug}\t{rel}:{ln}\t{why}")
                lst += 1
            if not n:
                continue
            print(f"FIX\t{slug}\t{rel}\t{n}")
            total += n
            files += 1
            if apply_:
                with open(os.path.join(REPO, p), "wb") as fh:
                    fh.write(new)
    print(f"{total} call(s) in {files} file(s) {'fixed' if apply_ else 'fixable'}, {lst} listed", file=sys.stderr)


if __name__ == "__main__":
    main()
