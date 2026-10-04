#!/usr/bin/env python3
"""Scan one lib for compiler warnings the way the driver reports them, and
optionally fix the mechanical classes in libs/<slug>/work.

A mudlib never carries `#pragma no_warnings`; every warning is a fix
(docs/kb/04-compile-classes.md section 6.10).  The scan builds a site-like copy
(scripts/pristine_tree.sh: tracked files, the site's keep dirs), runs
`lpcc --batch` over every .lpc in ONE VM boot, and parses the whole output:

* the block printed before the first `===== path =====` header (master,
  simul_efun and every preloaded daemon are compiled there, not under their
  own header);
* warnings with no column (`file:13: warning: Macro ...`);
* repeats of one warning from several including files (deduplicated).

A file stops listing after its warning cap ("too many warnings in this file"),
so a clean first pass is not clean: --fix rescans until nothing changes.

Usage:
  scripts/lpc_warnings.py SLUG                 # scan, print the summary
  scripts/lpc_warnings.py SLUG --fix           # apply the mechanical fixes, rescan
  scripts/lpc_warnings.py SLUG --fix --public reset,help
        # nosave functions named here lose `nosave` and stay public; so does any
        # name that appears as `x->name(`, call_other(x, "name") or (: x, "name" :)
        # anywhere in the lib (printed). Every other one becomes `protected`

Mechanical fixes (positions come from the driver; columns are 1-based BYTES):
  Illegal to declare nosave function   -> `protected` (historic static), or just
                                          drop `nosave` beside private / for --public names
  Unused local variable                -> delete the declarator (rebuild the statement)
  negative constant range end          -> `..-N]` becomes `..<N]` (section 7.209)
  Unknown escape sequence              -> drop the backslash
  Unknown #pragma, ignored             -> delete the bare `#pragma name` line (`save_binary`;
                                          the driver already ignores it)
  Number of arguments ... disagrees    -> `varargs` on the declaration the warning is reported on
                                          (either side being varargs silences it; never makes a call fail)
  Non-void functions must return value -> the bare `return;` on the reported line becomes `return 0;`
                                          (a bare return already yields 0)
  Unused local variable                -> not touched when the name also appears inside an
                                          #if/#ifdef block of the same function (listed instead)
A lib's own compiler tests (Lil: /single/tests/) are broken on purpose; pass --skip '^/single/tests/'.
Everything else is listed for hand work (see KB 04 section 6.10 for the fixes).
Only vendored libs (work/ tracked here) are supported.

The edits touch libs/SLUG/work only, in binary mode (CRLF and LF both survive),
and never add or remove lines except a deleted declaration.  After --fix, boot
the lib on a pristine tree and run the usual batteries: `protected` makes a
call from another object fail, and the driver logs
`apply() with insufficient permission` on its console when that happens.
"""

import argparse
import collections
import os
import re
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
LPCC = os.environ.get("LPCC", os.path.expanduser("~/src/fluffos/build-debug/src/lpcc"))
DIAG = re.compile(r"^(\S+?):(\d+):(?:(\d+):)? (warning|error): (.*)$", re.M)
TYPES = r"(?:int|string|object|mixed|mapping|float|function|buffer|status|void|class\s+\w+)"


# ---------------------------------------------------------------- scanning

def run(cmd, **kw):
    return subprocess.run(cmd, check=True, **kw)


def build_tree(slug, dest):
    out = subprocess.run([os.path.join(REPO, "scripts", "pristine_tree.sh"), slug, "49999", dest],
                         capture_output=True, text=True)
    if out.returncode:
        sys.exit(out.stderr.strip() or out.stdout.strip())
    return os.path.join(dest, "libs", slug)


def sync_changes(slug, lib):
    """Copy files that differ from HEAD (or are new) into the scan tree, and re-copy every file an earlier sync
    copied (a file edited back to HEAD's text would otherwise keep its edited copy in the scan tree); a file
    removed from the working tree is removed from the scan tree."""
    work = f"libs/{slug}/work"
    names = set()
    manifest = os.path.join(lib, ".synced")
    if os.path.isfile(manifest):
        names.update(n for n in open(manifest, encoding="utf-8").read().split("\n") if n)
    for args in (["diff", "--name-only", "HEAD", "--", work],
                 ["ls-files", "-o", "--exclude-standard", "--", work]):
        out = subprocess.run(["git", "-C", REPO] + args, capture_output=True, text=True).stdout
        names.update(n for n in out.split("\n") if n)
    for n in names:
        src = os.path.join(REPO, n)
        dst = os.path.join(lib, n[len(f"libs/{slug}/"):])
        if not os.path.isfile(src):                 # deleted from the working tree: delete it from the scan tree too
            if os.path.isfile(dst):
                os.remove(dst)
            continue
        os.makedirs(os.path.dirname(dst), exist_ok=True)
        with open(src, "rb") as a, open(dst, "wb") as b:
            b.write(a.read())
    with open(manifest, "w", encoding="utf-8") as fh:
        fh.write("\n".join(sorted(names)))
    return len(names)


def scan(lib, skips=()):
    work = os.path.join(lib, "work")
    objs = []
    for dp, dn, fn in os.walk(work):
        rel = os.path.relpath(dp, work)
        if rel == "log" or rel.startswith("log" + os.sep):
            continue
        for f in fn:
            if f.endswith(".lpc"):
                objs.append("/" + os.path.join("" if rel == "." else rel, f[:-4]).replace(os.sep, "/"))
    objs.sort()
    raw = subprocess.run([LPCC, "--batch", "config.fluffos"], cwd=lib, input="\n".join(objs) + "\n",
                         capture_output=True, text=True, errors="replace").stdout
    seen, rows = set(), []
    for m in DIAG.finditer(raw):
        f, ln, col, sev, msg = m.groups()
        if any(re.search(x, f) for x in skips):
            continue
        key = (f, ln, msg)
        if key in seen:
            continue
        seen.add(key)
        rows.append((f, int(ln), int(col or 0), sev, msg))
    npass = len(re.findall(r"^PASS ", raw, re.M))
    nfail = len(re.findall(r"^FAIL ", raw, re.M))
    return rows, npass, nfail, raw


def kind(msg):
    return re.sub(r"'[^']*'", "'X'", msg)[:100]


# ------------------------------------------------------------------ fixers

def read_lines(path):
    with open(path, "rb") as f:
        return f.read().decode("latin-1").split("\n")


def write_lines(path, lines):
    with open(path, "wb") as f:
        f.write("\n".join(lines).encode("latin-1"))


def nosave_function_names(work, rows):
    """Names declared `nosave` as functions, read from the driver's positions."""
    names = set()
    for f, ln, col, sev, msg in rows:
        if "nosave function" not in msg:
            continue
        L = read_lines(os.path.join(work, f.lstrip("/")))
        m = re.search(r"([A-Za-z_]\w*)\s*$", L[ln - 1][:col - 1])
        if m:
            names.add(m.group(1))
    return names


def external_callers(work, names):
    """name -> [(file, line)] where another object may call it: `x->name(`,
    call_other(x, "name") or (: x, "name" :).  Name collisions are common, so
    these functions are simply left public (what the lib did before the fix)."""
    hits = collections.defaultdict(list)
    if not names:
        return hits
    alt = "|".join(re.escape(n) for n in sorted(names))
    pats = [re.compile(r"->\s*(" + alt + r")\s*\("),
            re.compile(r"call_other\s*\([^,;]+,\s*\"(" + alt + r")\""),
            re.compile(r"\(:\s*[^,:()]+,\s*\"(" + alt + r")\"\s*:\)")]
    for dp, dn, fn in os.walk(work):
        rel = os.path.relpath(dp, work)
        if rel == "log" or rel.startswith("log" + os.sep):
            continue
        for f in fn:
            if not f.endswith((".lpc", ".h")):
                continue
            path = os.path.join(dp, f)
            with open(path, "rb") as fh:
                text = fh.read().decode("latin-1")
            for pat in pats:
                for m in pat.finditer(text):
                    before = text[max(0, m.start() - 14):m.start()]
                    if pat is pats[0] and re.search(r"this_object\(\)\s*$", before):
                        continue
                    hits[m.group(1)].append((os.path.relpath(path, work), text.count("\n", 0, m.start()) + 1))
    return hits


def fix_nosave_functions(work, rows, public):
    sites = collections.defaultdict(dict)
    for f, ln, col, sev, msg in rows:
        if "nosave function" in msg:
            sites[f][ln] = col
    n_prot = n_drop = 0
    manual = []
    for f, lns in sites.items():
        path = os.path.join(work, f.lstrip("/"))
        L = read_lines(path)
        for ln in sorted(lns):
            col = lns[ln]
            idx = ln - 1
            pre = L[idx][:col - 1]
            mname = re.search(r"([A-Za-z_]\w*)\s*$", pre)
            name = mname.group(1) if mname else "?"
            start = idx
            while not re.search(r"\bnosave\b", L[start][:(col - 1 if start == idx else None)]):
                start -= 1
                if start < 0 or idx - start > 3 or re.search(r"[;{}]\s*\r?$", L[start]):
                    start = None
                    break
            if start is None:
                manual.append((f, ln, name, "no nosave token before the name"))
                continue
            seg = L[start:idx + 1]
            seg[-1] = seg[-1][:col - 1] + "\0" + seg[-1][col - 1:]
            text = "\n".join(seg)
            head = text[:text.index("\0")]
            m = None
            for m in re.finditer(r"\bnosave\b", head):
                pass
            if re.search(r"[;{}]", head[m.start():]):
                manual.append((f, ln, name, "statement boundary inside the declaration"))
                continue
            vis = re.search(r"\b(private|protected)\b", head[max(0, m.start() - 40):m.end() + 60])
            if not vis and start > 0 and re.fullmatch(r"\s*(?:(?:private|protected|public|static|nomask|varargs)\s+)+\s*", L[start - 1]):
                vis = re.search(r"\b(private|protected)\b", L[start - 1])   # `private` alone on the line above the head
            if vis or name in public:
                after = head[m.end():]
                after = after[1:] if after.startswith(" ") else after
                newhead = head[:m.start()] + after
                n_drop += 1
            else:
                newhead = head[:m.start()] + "protected" + head[m.end():]
                n_prot += 1
            new = (newhead + text[text.index("\0") + 1:]).split("\n")
            L[start:idx + 1] = new
        write_lines(path, L)
    return n_prot, n_drop, manual


def mask(src):
    """Same-length copy with comments and string/char literal contents blanked."""
    out = list(src)
    i, n = 0, len(src)
    while i < n:
        c = src[i]
        if c == '/' and i + 1 < n and src[i + 1] == '/':
            while i < n and src[i] != '\n':
                out[i] = ' '
                i += 1
        elif c == '/' and i + 1 < n and src[i + 1] == '*':
            while i < n and not (src[i] == '*' and i + 1 < n and src[i + 1] == '/'):
                if src[i] != '\n':
                    out[i] = ' '
                i += 1
            if i < n:
                out[i] = ' '
                out[i + 1] = ' '
                i += 2
        elif c == '"':
            i += 1
            while i < n and src[i] != '"':
                if src[i] == '\\':
                    out[i] = ' '
                    i += 1
                if i < n and src[i] != '\n':
                    out[i] = ' '
                i += 1
            i += 1
        elif c == "'":
            m = re.match(r"'(?:\\.|[^\\'])'", src[i:i + 4])
            if m:
                for k in range(i + 1, i + len(m.group(0)) - 1):
                    out[k] = ' '
                i += len(m.group(0))
            else:
                i += 1
        else:
            i += 1
    return "".join(out)


def find_open(masked, close):
    depth, i = 0, close
    while i >= 0:
        c = masked[i]
        if c == '}':
            depth += 1
        elif c == '{':
            depth -= 1
            if depth == 0:
                return i
        i -= 1
    return -1


def statements(masked, a, b):
    """(start, end) of the depth-0 statements of masked[a:b] that end with ';'."""
    i, depth, start = a, 0, None
    while i < b:
        c = masked[i]
        if start is None and not c.isspace() and c not in '{}':
            start = i
        if c in '([{':
            depth += 1
        elif c in ')]}':
            depth -= 1
            if depth == 0 and c == '}':
                start = None
        elif c == ';' and depth == 0:
            if start is not None:
                yield (start, i + 1)
            start = None
        i += 1


def split_commas(masked, a, b):
    parts, depth, s = [], 0, a
    for i in range(a, b):
        c = masked[i]
        if c in '([{':
            depth += 1
        elif c in ')]}':
            depth -= 1
        elif c == ',' and depth == 0:
            parts.append((s, i))
            s = i + 1
    parts.append((s, b))
    return parts


def conditional_lines(masked):
    """Per-line flag: is this line inside an #if/#ifdef/#ifndef ... #endif block
    (directive lines themselves excluded).  Used to spot a local that looks unused
    only because the branch that uses it is not compiled on this driver."""
    flags, depth = [], 0
    for line in masked.split("\n"):
        m = re.match(r"\s*#\s*(\w+)", line)
        if m:
            d = m.group(1)
            if d in ("if", "ifdef", "ifndef"):
                depth += 1
            elif d == "endif" and depth:
                depth -= 1
            flags.append(False)
        else:
            flags.append(depth > 0)
    return flags


def used_in_conditional(masked, flags, name, a, b, skip_a, skip_b):
    """True if `name` occurs in masked[a:b] (outside the declarator being
    removed, masked[skip_a:skip_b]) on a line inside a preprocessor conditional."""
    for m in re.finditer(r"\b" + re.escape(name) + r"\b", masked[a:b]):
        p = a + m.start()
        if skip_a <= p < skip_b:
            continue
        if flags[masked.count("\n", 0, p)]:
            return True
    return False


def fix_unused_locals(work, rows):
    by_file = collections.defaultdict(list)
    for f, ln, col, sev, msg in rows:
        if msg.startswith("Unused local variable"):
            by_file[f].append((ln, col, re.search(r"'([^']*)'", msg).group(1)))
    removed = 0
    manual = []
    for f, items in by_file.items():
        path = os.path.join(work, f.lstrip("/"))
        with open(path, "rb") as fh:
            src = fh.read().decode("latin-1")
        lines = src.split("\n")
        masked = mask(src)
        cflags = conditional_lines(masked)
        scopes = collections.defaultdict(set)
        for ln, col, name in items:
            if col <= 0:
                manual.append((f, ln, name, "no column"))
                continue
            scopes[sum(len(x) + 1 for x in lines[:ln - 1]) + col - 1].add(name)
        edits = {}
        for close, names in scopes.items():
            where = src.count("\n", 0, close) + 1
            if close >= len(masked) or masked[close] != '}':
                manual += [(f, where, n, "no } at the reported position") for n in names]
                continue
            op = find_open(masked, close)
            if op < 0:
                manual += [(f, where, n, "no matching {") for n in names]
                continue
            remaining = set(names)
            for (s, e) in statements(masked, op + 1, close):
                m = re.match(r"\s*(?:nosave\s+)?(" + TYPES + r")\b", masked[s:e])
                if not m:
                    continue
                tend = s + m.end()
                parsed = []
                for (ds, de) in split_commas(masked, tend, e - 1):
                    dm = re.match(r"\s*(\**)\s*([A-Za-z_]\w*)\s*(=.*)?$", masked[ds:de], re.S)
                    if not dm:
                        parsed = None
                        break
                    parsed.append((dm.group(2), ds, de, dm.group(3)))
                if not parsed:
                    continue
                drop = [d for d in parsed if d[0] in remaining]
                if not drop:
                    continue
                for d in list(drop):
                    if used_in_conditional(masked, cflags, d[0], op + 1, close, d[1], d[2]):
                        manual.append((f, src.count("\n", 0, d[1]) + 1, d[0],
                                       "also named inside an #if/#ifdef branch that this driver does not "
                                       "compile: move the declaration into that branch by hand"))
                        remaining.discard(d[0])
                        drop.remove(d)
                        continue
                    if d[3] and "(" in d[3]:
                        manual.append((f, src.count("\n", 0, d[1]) + 1, d[0],
                                       "initializer calls something: " + src[d[1]:d[2]].strip()[:60]))
                        remaining.discard(d[0])
                        drop.remove(d)
                if not drop:
                    continue
                keep = [d for d in parsed if d not in drop]
                remaining -= {d[0] for d in drop}
                removed += len(drop)
                if not keep:
                    a = s
                    while a > 0 and src[a - 1] in " \t":
                        a -= 1
                    b = e
                    if b < len(src) and src[b] == '\r':
                        b += 1
                    if b < len(src) and src[b] == '\n' and (a == 0 or src[a - 1] == '\n'):
                        b += 1
                    edits[(a, b)] = ""
                else:
                    gap = re.match(r"[ \t]*", src[keep[0][1]:keep[0][2]]).group(0) if keep[0] is parsed[0] else " "
                    edits[(s, e)] = src[s:tend] + (gap or " ") + ", ".join(src[d[1]:d[2]].strip() for d in keep) + ";"
            manual += [(f, where, n, "declaration not found at the top of its scope") for n in remaining]
        for (a, b), rep in sorted(edits.items(), reverse=True):
            src = src[:a] + rep + src[b:]
        if edits:
            with open(path, "wb") as fh:
                fh.write(src.encode("latin-1"))
    return removed, manual


def fix_range_ends(work, rows):
    n = 0
    manual = []
    by_file = collections.defaultdict(set)
    for f, ln, col, sev, msg in rows:
        if msg.startswith("A negative constant as the second element"):
            by_file[f].add((ln, col))
    for f, sites in by_file.items():
        path = os.path.join(work, f.lstrip("/"))
        L = read_lines(path)
        for ln, col in sites:
            line = L[ln - 1]
            m = re.search(r"(\.\.\s*)-\s*(\d+)(\s*)$", line[:col - 1])
            if not m or line[col - 1:col] != "]":
                manual.append((f, ln, "?", "range end not recognised"))
                continue
            L[ln - 1] = line[:m.start()] + m.group(1) + "<" + m.group(2) + m.group(3) + line[col - 1:]
            n += 1
        write_lines(path, L)
    return n, manual


HEAD_RE = re.compile(r"^(?P<ind>[ \t]*)(?:(?:private|protected|public|static|nomask|nosave|deprecated)\s+)*"
                     r"(?:" + TYPES + r")[ \t]*\**[ \t]*$")


def fix_arg_counts(work, rows):
    """`Number of arguments to 'f' disagrees with previous definition`: the driver
    (compiler.cc define_new_function) stays quiet when EITHER declaration is
    varargs, and varargs never makes a call fail that passed before (it only skips
    the optional call_other type check and the compile-time 'Wrong number of
    arguments' error), so the declaration the warning is reported on gets
    `varargs` -- KB 04 section 6.10.  Only a head that starts its line
    (`[modifiers] type name(`) is edited; anything else is listed."""
    n = 0
    manual = []
    by_file = collections.defaultdict(set)
    for f, ln, col, sev, msg in rows:
        m = re.match(r"Number of arguments to '(\w+)' disagrees", msg)
        if m:
            by_file[f].add((ln, col, m.group(1)))
    for f, items in by_file.items():
        path = os.path.join(work, f.lstrip("/"))
        with open(path, "rb") as fh:
            src = fh.read().decode("latin-1")
        masked = mask(src)
        lines = src.split("\n")
        starts = [0]
        for x in lines:
            starts.append(starts[-1] + len(x) + 1)
        depth_at = []
        d = 0
        for c in masked:
            depth_at.append(d)
            if c == '{':
                d += 1
            elif c == '}':
                d -= 1
        edits = set()
        for ln, col, name in items:
            end = starts[ln - 1] + (col - 1 if col > 0 else len(lines[ln - 1]))
            cands = [m for m in re.finditer(r"(?<![\w>:.])" + re.escape(name) + r"\s*\(", masked[:end + 1])
                     if depth_at[m.start()] == 0]
            if not cands:
                manual.append((f, ln, name, "no definition head found before the reported position"))
                continue
            pos = cands[-1].start()
            ls = masked.rfind("\n", 0, pos) + 1
            head = masked[ls:pos]
            hm = HEAD_RE.match(head)
            if not hm or "varargs" in head:
                manual.append((f, src.count("\n", 0, pos) + 1, name, "declaration head is not a plain `modifiers type` line"))
                continue
            edits.add(ls + len(hm.group("ind")))
        for p in sorted(edits, reverse=True):
            src = src[:p] + "varargs " + src[p:]
            n += 1
        if edits:
            with open(path, "wb") as fh:
                fh.write(src.encode("latin-1"))
    return n, manual


def fix_bare_returns(work, rows):
    """`Non-void functions must return a value`: reported on the line of a bare
    `return;` inside a function with a return type.  A bare return already yields
    0, so `return 0;` says the same thing without the warning.  In-line edit."""
    n = 0
    manual = []
    by_file = collections.defaultdict(set)
    for f, ln, col, sev, msg in rows:
        if msg.startswith("Non-void functions must return a value"):
            by_file[f].add(ln)
    for f, lns in by_file.items():
        path = os.path.join(work, f.lstrip("/"))
        L = read_lines(path)
        for ln in sorted(lns):
            new, k = re.subn(r"\breturn\s*;", "return 0;", L[ln - 1])
            if k:
                L[ln - 1] = new
                n += k
            else:
                manual.append((f, ln, L[ln - 1].strip()[:60], "no bare `return;` on the reported line"))
        write_lines(path, L)
    return n, manual


def fix_pragmas(work, rows):
    """`#pragma save_binary` and friends: the driver reports "Unknown #pragma,
    ignored" and ignores the line, so a bare pragma line is just deleted.  Runs
    as its own pass before the others, because it removes lines."""
    n = 0
    manual = []
    by_file = collections.defaultdict(set)
    for f, ln, col, sev, msg in rows:
        if msg.startswith("Unknown #pragma"):
            by_file[f].add(ln)
    for f, lns in by_file.items():
        path = os.path.join(work, f.lstrip("/"))
        L = read_lines(path)
        for ln in sorted(lns, reverse=True):
            if re.match(r"\s*#\s*pragma\s+\w+\s*$", L[ln - 1]):
                del L[ln - 1]
                n += 1
            else:
                manual.append((f, ln, L[ln - 1].strip(), "not a bare #pragma line"))
        write_lines(path, L)
    return n, manual


def fix_escapes(work, rows):
    n = 0
    manual = []
    by_file = collections.defaultdict(set)
    for f, ln, col, sev, msg in rows:
        m = re.match(r"Unknown escape sequence '(\\.)'", msg)
        if m:
            by_file[f].add((ln, col, m.group(1)))
    for f, sites in by_file.items():
        path = os.path.join(work, f.lstrip("/"))
        L = read_lines(path)
        for ln, col, seq in sorted(sites, reverse=True):
            line = L[ln - 1]
            i = line.rfind(seq, 0, col + 1)
            if i < 0:
                i = line.find(seq)
            if i < 0:
                manual.append((f, ln, seq, "escape not found on the line"))
                continue
            L[ln - 1] = line[:i] + seq[1:] + line[i + 2:]
            n += 1
        write_lines(path, L)
    return n, manual


# -------------------------------------------------------------------- main

def summary(rows, npass, nfail):
    kinds = collections.Counter((r[3], kind(r[4])) for r in rows)
    print(f"  {npass} files compile, {nfail} do not; {len(rows)} distinct diagnostics")
    for (sev, k), v in kinds.most_common():
        files = len({r[0] for r in rows if (r[3], kind(r[4])) == (sev, k)})
        print(f"  {v:5d} {sev:7s} {k}  [{files} file(s)]")


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    ap.add_argument("slug")
    ap.add_argument("--fix", action="store_true", help="apply the mechanical fixes and rescan")
    ap.add_argument("--public", default="", help="comma list of nosave functions to leave public")
    ap.add_argument("--rounds", type=int, default=8)
    ap.add_argument("--tree", default=None, help="scan tree (default /tmp/lpcw-SLUG)")
    ap.add_argument("--list", type=int, default=3, help="examples per remaining kind")
    ap.add_argument("--skip", action="append", default=[],
                    help="regex of file paths to leave alone (repeatable); use it for a lib's own "
                         "compiler tests that are broken on purpose, e.g. --skip '^/single/tests/'")
    a = ap.parse_args()
    if not os.path.isfile(LPCC):
        sys.exit(f"lpcc not found at {LPCC} (build target lpcc in ~/src/fluffos/build-debug)")
    dest = a.tree or f"/tmp/lpcw-{a.slug}"
    lib = build_tree(a.slug, dest)
    work = os.path.join(REPO, "libs", a.slug, "work")
    public = set(x for x in a.public.split(",") if x)
    sync_changes(a.slug, lib)
    rows, npass, nfail, raw = scan(lib, a.skip)
    print(f"{a.slug}: scan 1")
    summary(rows, npass, nfail)
    manual_all = []
    if a.fix:
        npr, mpr = fix_pragmas(work, rows)
        if npr:
            print(f"unknown #pragma lines deleted: {npr}")
            sync_changes(a.slug, lib)
            rows, npass, nfail, raw = scan(lib, a.skip)     # line numbers moved
        manual_all += mpr
        hits = external_callers(work, nosave_function_names(work, rows))
        if hits:
            print("kept public (a call_other-style use exists elsewhere; check whether it is the same function):")
            for n in sorted(hits):
                print("   %-22s %s" % (n, ", ".join("%s:%d" % h for h in hits[n][:3]) + (" ..." if len(hits[n]) > 3 else "")))
        for rnd in range(1, a.rounds + 1):
            public |= set(external_callers(work, nosave_function_names(work, rows)))
            np_, nd_, m1 = fix_nosave_functions(work, rows, public)
            nr_, m2 = fix_range_ends(work, rows)
            ne_, m3 = fix_escapes(work, rows)
            sync_changes(a.slug, lib)
            rows2, npass, nfail, raw = scan(lib, a.skip)       # unused-local positions need a rescan after other edits
            na_, m5 = fix_arg_counts(work, rows2)              # in-line edit: keeps every line number
            nb_, m6 = fix_bare_returns(work, rows2)            # in-line edit
            nu_, m4 = fix_unused_locals(work, rows2)
            manual_all = m1 + m4 + m5 + m6
            changed = np_ + nd_ + nr_ + ne_ + na_ + nb_ + nu_
            print(f"round {rnd}: nosave functions {np_} protected + {nd_} dropped, range ends {nr_}, "
                  f"escapes {ne_}, varargs added {na_}, bare returns {nb_}, unused locals {nu_}")
            sync_changes(a.slug, lib)
            rows, npass, nfail, raw = scan(lib, a.skip)
            if not changed:
                break
        print(f"{a.slug}: after fixing")
        summary(rows, npass, nfail)
        if manual_all:
            print("not fixed automatically:")
            for m in manual_all:
                print("   ", m)
    left = [r for r in rows if r[3] == "warning" or r[3] == "error"]
    shown = collections.Counter()
    for r in left:
        k = (r[3], kind(r[4]))
        shown[k] += 1
        if shown[k] <= a.list:
            print(f"  {r[3]:7s} {r[0]}:{r[1]}: {r[4][:110]}")
    tsv = os.path.join(dest, "diagnostics.tsv")
    with open(tsv, "w") as fh:
        fh.write("\n".join("\t".join(map(str, r)) for r in rows) + "\n")
    print(f"scan tree {lib}   full list {tsv}   raw lpcc output not kept (re-run to see it)")
    if a.fix:
        print("next: git diff --stat libs/%s; boot a pristine tree and run the batteries; "
              "grep the console for 'insufficient permission'" % a.slug)
    sys.exit(0 if not any(r[3] == "warning" for r in rows) else 1)


if __name__ == "__main__":
    main()
