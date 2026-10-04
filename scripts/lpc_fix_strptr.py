#!/usr/bin/env python3
"""scripts/lpc_fix_strptr.py SLUG [--apply]

Turn the `(: "name" :)` pointers the driver flags (`Function pointer returning string constant is NOT a function
call`, KB 04 section 6.10) into real pointers, `(: name :)`.  When `name` is defined later in the same file a forward
prototype, copied from the definition, goes in front of the function that uses the pointer (a pointer to a function
that is not declared yet does not compile).  A name defined nowhere in the file is assumed inherited: the pointer is
fixed and no prototype is written; if it is not inherited either the file stops compiling and says so.

The pointers have never run on this driver, so read each target afterwards and call it once live: one that prints
instead of returning its text raises a run-time error the first time it is used (Praxis stone.lpc, KB 04 6.10).
Diagnostics come from /tmp/lpcw-SLUG/diagnostics.tsv (scripts/lpc_warnings.py); without --apply this only lists the
sites.  Edits are byte-exact (line endings kept).

--comma also rewrites the object form `(: this_object(), "name" :)`, which the compiler reads as a comma expression
(the pointer returns "name" and nothing warns), by grepping every .lpc of the lib instead of reading diagnostics;
see KB 04 section 6.10.  Pointers on another object (`(: ob, "name" :)`) are listed, never rewritten."""
import collections
import os
import re
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
KEYWORDS = r"(?!(?:if|for|foreach|while|switch|return|else|do|case|catch|sscanf|inherit)\b)"
MODS = r"(?:(?:varargs|private|protected|public|nomask|static|nosave)\s+)*"
TYPE = r"(?:(?:void|int|string|object|mixed|mapping|float|function|status|buffer)\s*\**\s*)?"
# a function head at column 0: modifiers, optional return type, name, argument list, optional body on the same line
FUNC_HEAD = re.compile(rb"^(?!\s)(" + MODS.encode() + TYPE.encode() + rb")" + KEYWORDS.encode() +
                       rb"(\w+)\s*\(([^()]*)\)\s*(\{.*)?\s*$")


STRP = rb'\(:\s*"(\w+)"\s*:\)'
COMMA = re.compile(rb'\(:\s*this_object\(\)\s*,\s*"(\w+)"\s*:\)')
OTHER = re.compile(rb'\(:\s*(?!this_object\(\))(?:previous_object\(\)|find_object\([^)]*\)|ob|obj|target|who)\s*,\s*"\w+"\s*:\)')


def main():
    if len(sys.argv) < 2:
        sys.exit(__doc__)
    slug = sys.argv[1]
    apply = "--apply" in sys.argv
    work = f"{REPO}/libs/{slug}/work"
    tsv = f"/tmp/lpcw-{slug}/diagnostics.tsv"
    if "--work" in sys.argv:          # test hooks: another work root / diagnostics file
        work = sys.argv[sys.argv.index("--work") + 1]
    if "--tsv" in sys.argv:
        tsv = sys.argv[sys.argv.index("--tsv") + 1]
    rows = [l.rstrip("\n").split("\t") for l in open(tsv, encoding="utf-8", errors="replace")]
    sites = collections.defaultdict(list)
    for f, ln, col, sev, msg in rows:
        if msg.startswith("Function pointer returning string constant"):
            sites[f].append((int(ln), int(col)))
    if "--comma" in sys.argv:
        for dp, dn, fn in os.walk(work):
            for name in fn:
                if not name.endswith(".lpc"):
                    continue
                path = os.path.join(dp, name)
                for k, l in enumerate(open(path, "rb").read().split(b"\n")):
                    if COMMA.search(l):
                        sites["/" + os.path.relpath(path, work).replace(os.sep, "/")].append((k + 1, 1))
                    elif OTHER.search(l):
                        print(f"NOT REWRITTEN (other object) {os.path.relpath(path, work)}:{k + 1}: {l.strip()[:90]!r}")
    for f, lst in sorted(sites.items()):
        path = work + f
        lines = open(path, "rb").read().split(b"\n")
        done, edits = set(), []
        for ln, col in sorted(set(lst), reverse=True):
            i = ln - 1
            text = lines[i]
            m = re.search(STRP, text) or COMMA.search(text)
            if not m:
                print(f"NO MATCH {f}:{ln}: {text[:90]!r}")
                continue
            name = m.group(1)
            eol = b"\r" if text.endswith(b"\r") else b""
            fixed = re.sub(STRP.replace(rb'(\w+)', name), b"(: " + name + b" :)", text)
            fixed = re.sub(COMMA.pattern.replace(rb'(\w+)', name), b"(: " + name + b" :)", fixed)
            defidx = None
            for k, l in enumerate(lines):
                h = FUNC_HEAD.match(l.rstrip(b"\r"))
                if h and h.group(2) == name:
                    defidx = k
                    break
            if defidx is None:
                print(f"{f}:{ln}: {name.decode()} is not defined in the file (inherited?): pointer only")
                proto, start = None, None
            elif defidx < i:
                print(f"{f}:{ln}: {name.decode()} is defined above its use: pointer only")
                proto, start = None, None
            else:
                head = re.sub(rb"\s*\{.*$", b"", lines[defidx].rstrip(b"\r"))
                proto = head + b";"
                start = None
                for k in range(i, -1, -1):
                    if FUNC_HEAD.match(lines[k].rstrip(b"\r")):
                        start = k
                        break
                if start is None:
                    print(f"{f}:{ln}: no enclosing function head found: add the prototype of {name.decode()} by hand")
                    proto = None
                else:
                    print(f"{f}:{ln}: {name.decode()}: pointer + prototype `{proto.decode(errors='replace')}` before line {start + 1}")
            if apply:
                lines[i] = fixed
                if proto is not None and (name, start) not in done:
                    done.add((name, start))
                    edits.append((start, proto + eol))
        if apply:
            for start, proto in sorted(edits, reverse=True):
                lines[start:start] = [proto]
            open(path, "wb").write(b"\n".join(lines))


if __name__ == "__main__":
    main()
