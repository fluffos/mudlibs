#!/usr/bin/env python3
"""scripts/lpc_fix_predefined_macro.py [SLUG...] [--apply]

An LPC predefine that MudOS removed and FluffOS never had (KB 04 section 6.11).  The `COMPAT_BUSTER` entry of the FluffOS
ChangeLog took the unqualified `SAVE_EXTENSION` out of every LPC object ("use __SAVE_EXTENSION__"), so a lib written for an
older driver that spells `rm(ob->query_save_file() + SAVE_EXTENSION)` without a `#define` of its own gets `Undefined variable
'SAVE_EXTENSION'` and the object never loads: the 武林盟主 NPCs (`tang3`/`tang`/`meng-zhu`), the guild token, `suicide`, `purge`,
the TMI-2 virtual server and shell.  The same ChangeLog entry removed `USE_EUID`, `HAS_SOCKETS`, `HAS_SHADOWS` ... (corpus: only
admin debug commands under `#ifdef`, which stay dead); only a macro used as a value breaks a compile.

For each file that uses a renamed macro in code (comments and strings are masked) and reaches no `#define` of it (the file itself,
its includes, the config's `global include file`; `<x.h>`/"x.h" are looked up beside the file, in /include, /secure/include, /),
the macro becomes its `__NAME__` form (not inside an `#ifndef __NAME__` block: TMI-2's `mudlib.h` shim).  A file that defines the macro itself, or includes a header that does, is left alone: a
second definition would be a redefinition.  Wizard, backup and driver-source dirs, gitlink libs and the generated tree of
longyunmeng_binary are skipped.  Binary-safe.  Without --apply the plan is printed.  Re-run after a lib is extended: it is idempotent."""
import collections
import os
import re
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from lpc_fix_void_return import code_mask  # noqa: E402

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
RENAMES = {b"SAVE_EXTENSION": b"__SAVE_EXTENSION__"}
SKIP = re.compile(r"^/(u|w|wiz|wizard|wizards|open|players|realms|home)/|/(backup|backups|old|bak|log|doc|example|examples|bin)/|[-_.](bak|old|orphaned-driver-src)/")   # wizard HOMES at the top; cmds/wiz is code
INC = re.compile(rb'(?m)^[ \t]*#[ \t]*include[ \t]*([<"])([^>"\r\n]+)[>"]')


def tracked_files(slug):
    out = subprocess.run(["git", "ls-files", "-z", "--", f"libs/{slug}/work"], cwd=REPO, capture_output=True).stdout.split(b"\0")
    res = set()
    for f in out:
        try:
            p = f.decode("utf-8")
        except UnicodeDecodeError:
            continue
        res.add(p[len(f"libs/{slug}/work"):])
    return res


def global_include(slug):
    try:
        t = open(f"{REPO}/libs/{slug}/config.fluffos", encoding="utf-8", errors="replace").read()
    except OSError:
        return None
    m = re.search(r"(?m)^global include file\s*:\s*[<\"]?([^>\"\s]+)", t)
    return m.group(1) if m else None


class Lib:
    def __init__(self, slug):
        self.slug = slug
        self.files = tracked_files(slug)
        self.memo = {}

    def resolve(self, cur, name, quote):
        cand = []
        if quote == b'"':
            cand.append(os.path.normpath(os.path.dirname(cur) + "/" + name))
        for d in ("/include", "/", "/secure/include", "/inc", "/sys"):
            cand.append(os.path.normpath(d + "/" + name))
        for c in cand:
            if c in self.files:
                return c
        return None

    def reach(self, define, path, seen=frozenset()):
        key = (define, path)
        if key in self.memo:
            return self.memo[key]
        if path in seen:
            return False
        try:
            b = open(f"{REPO}/libs/{self.slug}/work{path}", "rb").read()
        except OSError:
            return False
        ok = bool(re.search(rb"(?m)^[ \t]*#[ \t]*define[ \t]+" + re.escape(define) + rb"\b", b))
        if not ok:
            for q, n in INC.findall(b):
                r = self.resolve(path, n.decode("utf-8", "replace"), q)
                if r and self.reach(define, r, seen | {path}):
                    ok = True
                    break
        self.memo[key] = ok
        return ok


def guarded_spans(b, new):
    """spans of `#ifndef <new> ... #endif` blocks: the compat shim of TMI-2 (`#ifndef __SAVE_EXTENSION__ / #define __SAVE_EXTENSION__
    SAVE_EXTENSION`) is dead on this driver and must keep spelling the old name"""
    spans = []
    for m in re.finditer(rb"(?m)^[ \t]*#[ \t]*ifndef[ \t]+" + re.escape(new) + rb"\b.*$", b):
        depth, pos = 1, m.end()
        for d in re.finditer(rb"(?m)^[ \t]*#[ \t]*(if|ifdef|ifndef|endif)\b", b[pos:]):
            depth += 1 if d.group(1) != b"endif" else -1
            if depth == 0:
                spans.append((m.start(), pos + d.end()))
                break
        else:
            spans.append((m.start(), len(b)))
    return spans


def fix(b, lib, path, glob_def):
    """return (new bytes, [macro names renamed]) for one file"""
    changed = []
    for old, new in RENAMES.items():
        if old not in b:
            continue
        use = re.compile(rb"(?<![A-Za-z0-9_])" + re.escape(old) + rb"(?![A-Za-z0-9_])")
        mask = code_mask(b, heredoc=True)
        skip = guarded_spans(b, new)
        spans = [m.span() for m in use.finditer(b) if mask[m.start()] and not any(a <= m.start() < z for a, z in skip)]
        if not spans or glob_def.get(old) or lib.reach(old, path):
            continue
        out, last = [], 0
        for s, e in spans:
            out.append(b[last:s])
            out.append(new)
            last = e
        out.append(b[last:])
        b = b"".join(out)
        changed.append((old.decode(), len(spans)))
    return b, changed


def main():
    args = sys.argv[1:]
    apply = "--apply" in args
    slugs = [a for a in args if not a.startswith("--")] or sorted(os.listdir(f"{REPO}/libs"))
    tot = files = 0
    per = collections.Counter()
    for slug in slugs:
        work = f"{REPO}/libs/{slug}/work"
        if slug == "longyunmeng_binary" or not os.path.isdir(work) or os.path.exists(f"{work}/.git"):
            continue
        lib = Lib(slug)
        gi = global_include(slug)
        gp = lib.resolve("/x", gi, b"<") if gi else None
        glob_def = {old: bool(gp and lib.reach(old, gp)) for old in RENAMES}
        for path in sorted(lib.files):
            if not path.endswith((".lpc", ".h")) or SKIP.search(path):
                continue
            p = work + path
            try:
                b = open(p, "rb").read()
            except OSError:
                continue
            out, ch = fix(b, lib, path, glob_def)
            if ch:
                n = sum(c for _, c in ch)
                tot += n
                files += 1
                per[slug] += 1
                print(f"FIX   {slug} {path}  " + ", ".join(f"{m} x{c}" for m, c in ch))
                if apply:
                    open(p, "wb").write(out)
    print(f"{tot} use(s) in {files} file(s) of {len(per)} lib(s)" + ("" if apply else " (plan only; --apply writes)"))


if __name__ == "__main__":
    main()
