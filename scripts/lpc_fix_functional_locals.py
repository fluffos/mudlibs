#!/usr/bin/env python3
"""scripts/lpc_fix_functional_locals.py [--apply] [SLUG...]

`me->edit((: this_object(), ({ "do_to", me, arg }) :));`: the call_other function pointer `(: object, ({ "fn", args... }) :)` takes constants only; a local
variable inside the array makes the compiler read the whole pointer as an expression functional and stop with
`Illegal to use local variable in functional.`  The object does not load.  The commands that open the line editor and call back into themselves are the
carriers: `to` (say / tell / chat in many lines), `describe`, `plan`, `sig` / `signature`, `song`.  The pointer that does the same and takes locals is the
efun-pointer form: `(: call_other, this_object(), "do_to", me, arg :)` -- the bound arguments are evaluated when the pointer is made, and what the
caller of the pointer passes (the editor's `evaluate(callback, text)`) is appended after them, so `do_to(me, arg, text)` receives the text.

The rewrite is made for `(: this_object(), ({ "name", ident, ident... }) :)` -- the first array element a string, every other element a bare name -- in
code only (comments and strings stay).  Wizard home directories (/u/, /w/, /wiz/ at the top of the tree), backups and `last_modify/` copies are skipped
like the other mechanical fixers do; `cmds/wiz/` is code and is fixed.  Binary-safe, idempotent.  Without --apply the plan is printed
(`FIX<TAB>slug<TAB>/path<TAB>n`)."""
import os
import re
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from lpc_fix_void_return import code_mask  # noqa: E402

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
TOP = re.compile(r"^/(u|w|wiz|wizard|wizards|open|players|realms|home)/")
ANY = re.compile(r"/(backup|backups|old|bak|log|data|example|examples|test|tests|tmp|attic|last_modify)/|[-_.](bak|old)/|\.(bak|BAK|old|orig)(\.lpc)?$")
GENERATED = {"wllz3", "longyunmeng_binary"}
RX = re.compile(rb'\(:\s*this_object\(\)\s*,\s*\(\{\s*("[A-Za-z_0-9]+")\s*,\s*([A-Za-z_]\w*(?:\s*,\s*[A-Za-z_]\w*)*)\s*\}\)\s*:\)')


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
    return {s: f for s, f in by.items() if s not in gitlinks and s not in GENERATED and (not slugs or s in slugs)}


def fix(b):
    mask = code_mask(b)
    edits = []
    for m in RX.finditer(b):
        if mask[m.start()]:
            edits.append((m.start(), m.end(), b"(: call_other, this_object(), " + m.group(1) + b", " + re.sub(rb"\s+", b" ", m.group(2)) + b" :)"))
    if not edits:
        return None, 0
    out = bytearray(b)
    for s, e, rep in reversed(edits):
        out[s:e] = rep
    return bytes(out), len(edits)


def main():
    a = sys.argv[1:]
    apply_ = "--apply" in a
    slugs = {x for x in a if not x.startswith("--")}
    total = files = 0
    for slug, paths in sorted(tracked(slugs).items()):
        for p in paths:
            rel = "/" + p.split("/work/", 1)[1]
            if TOP.search(rel) or ANY.search(rel):
                continue
            try:
                b = open(os.path.join(REPO, p), "rb").read()
            except OSError:
                continue
            if b"(:" not in b or b"this_object()" not in b:
                continue
            new, n = fix(b)
            if not n:
                continue
            print(f"FIX\t{slug}\t{rel}\t{n}")
            total += n
            files += 1
            if apply_:
                with open(os.path.join(REPO, p), "wb") as fh:
                    fh.write(new)
    print(f"{total} functional(s) in {files} file(s) {'fixed' if apply_ else 'fixable'}", file=sys.stderr)


if __name__ == "__main__":
    main()
