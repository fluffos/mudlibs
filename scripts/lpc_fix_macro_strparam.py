#!/usr/bin/env python3
"""scripts/lpc_fix_macro_strparam.py [--apply] [--list] SLUG [FILE...]

`#define MON(x) BASE + "mon/" + "x"`: a macro parameter named inside a string literal.  A traditional (K&R) preprocessor replaces it there -- the old MudOS the 1990s libs
were written for did -- so `MON(queen)` was `BASE + "mon/" + "queen"`; FluffOS follows ANSI C: the argument is NOT replaced inside a string, `MON(queen)` is `.../mon/x`.  Every
room exit, monster, weapon and shop item named through such a macro points at a file called `x`: the areas of Mortal Remains (mortremains: 81 macros in 25 headers, `/d/Ancients`,
`/d/Prime/Norva`, `Petzoo`, `Cyanide`, `/d/attic/Prime/Tormeid`, `Sigil`, `/std/buy_only_shop`, the mage / priest spell headers) cannot be walked and no monster comes (KB 06 section 7.352).

FluffOS has the ANSI stringize operator: `"x"` becomes `#x`, and a path that ends in the parameter, `"/d/Ancients/rooms/x"`, becomes `"/d/Ancients/rooms/" #x` (adjacent string
literals are one literal).  Only the two safe shapes are rewritten: (a) a string literal that is exactly a parameter name, (b) a string literal that ends in `/` + a parameter name.
A parameter inside a longer text (`sprintf("%-*s", n, s)`, `"Oops, file not found!"` with a parameter called `file`) is not a use of the idiom and is printed as SKIP; a body the
tool cannot read cleanly is printed too.  Code comments and wizard / backup directories are skipped.  Binary mode, the file's own line endings, idempotent (a rewritten body has no
`"x"` left).  Dry run by default; `--apply` writes; `--list` prints the rewritten bodies."""
import os
import re
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SKIP = re.compile(r"/(u|w|wiz|wizard|wizards|players|backup|backups|bak|old|test|tests|tmp|data|log|realms|doc|docs)/|[-_.](bak|old)")  # `/open/` is playable world (Taiwanese / dreamofseven-style libs), not a wizard home
DEF = re.compile(rb"(?m)^([ \t]*#[ \t]*define[ \t]+[A-Za-z_]\w*\(([A-Za-z_\w, \t]*)\)[ \t]*)((?:[^\r\n\\]|\\\r?\n)*)")
STR = re.compile(rb'"((?:[^"\\\r\n]|\\.)*)"')


def fix_body(params, body):
    """(new body, [rewritten literals], [skipped literals])"""
    done, skipped = [], []

    def one(m):
        lit = m.group(1)
        if lit in params:
            done.append(lit)
            return b"#" + lit
        for p in params:
            if lit.endswith(b"/" + p) and not re.search(rb"(?<![A-Za-z0-9_])" + re.escape(p) + rb"(?![A-Za-z0-9_])", lit[:-len(p)]):
                done.append(lit)
                return b'"' + lit[:-len(p)] + b'" #' + p
        for p in params:
            if re.search(rb"(?<![A-Za-z0-9_])" + re.escape(p) + rb"(?![A-Za-z0-9_])", lit):
                skipped.append(lit)
                break
        return m.group(0)
    return STR.sub(one, body), done, skipped


def fix(b):
    out, last, changes, skips = [], 0, [], []
    for m in DEF.finditer(b):
        params = [p.strip() for p in m.group(2).split(b",") if p.strip()]
        if not params:
            continue
        nb, done, skipped = fix_body(params, m.group(3))
        for s in skipped:
            skips.append((m.group(1).strip().decode("utf-8", "replace")[:60], s.decode("utf-8", "replace")[:60]))
        if done:
            out.append(b[last:m.start(3)])
            out.append(nb)
            last = m.end(3)
            changes.append((m.group(1).strip().decode("utf-8", "replace")[:60], nb.strip().decode("utf-8", "replace")[:100]))
    out.append(b[last:])
    return b"".join(out), changes, skips


def main():
    argv = sys.argv[1:]
    apply, listing = "--apply" in argv, "--list" in argv
    args = [a for a in argv if not a.startswith("--")]
    if not args:
        sys.exit(__doc__)
    slug, files = args[0], args[1:]
    root = f"libs/{slug}/work"
    if not files:
        out = subprocess.run(["git", "grep", "-l", "-E", r'^[[:space:]]*#[[:space:]]*define[[:space:]]+[A-Za-z_][A-Za-z_0-9]*\(', "--", root], cwd=REPO, capture_output=True, text=True).stdout.split()
        files = [f for f in out if f.endswith((".h", ".lpc", ".c", ".inc")) and not SKIP.search(f[len(root):])]
    nfix = nmac = 0
    for f in sorted(files):
        p = f if os.path.isabs(f) else os.path.join(REPO, f)
        b = open(p, "rb").read()
        nb, ch, sk = fix(b)
        for name, lit in sk:
            print(f"SKIP {f[len(root):] if f.startswith(root) else f}: {name} ... \"{lit}\" (a parameter inside a longer text: not the idiom)")
        if not ch:
            continue
        nfix += 1
        nmac += len(ch)
        print(f"{'FIX' if apply else 'would fix'} {f[len(root):] if f.startswith(root) else f}: {len(ch)} macro(s)")
        if listing:
            for name, body in ch:
                print(f"    {name} -> {body}")
        if apply:
            open(p, "wb").write(nb)
    print(f"{nmac} macro(s) in {nfix} file(s)" + ("" if apply else " (plan only; --apply writes)"), file=sys.stderr)


if __name__ == "__main__":
    main()
