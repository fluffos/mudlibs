#!/usr/bin/env python3
"""scripts/lpc_transplant_function.py --lib SLUG --from DONOR --path /feature/damage.lpc --name set_ghost [--name N ...] [--var "mapping skill_prepare;" --after "mapping skill_map;"] [--apply]

A function the sibling lib's file has and this lib's file lost (KB 06 section 7.262).  `me->set_ghost(1)` in the wooden-man NPCs
of xkxz2 and xkxc98sj, `prepare_skill()` in the transplanted NPCs of sjpl2: the callers are there, the function of the base file is
not, and the object never compiles (`Undefined function set_ghost`).  The donor (a lib that carries the same file, found with
the table `scripts/lpc_scan_missing_funcs.py` prints) holds the function; this copies it, body and the comment lines directly above
it, into the same file of SLUG, after that file's last function, in the target's line ending.  The target must not define the name
already; the identifiers the function uses that the target file does not mention (globals the donor's file declares, helper
functions) are printed as UNRESOLVED -- a global the target lacks is transplanted with the function by adding it by hand or
choosing another donor.  `--var DECL --after LINE` adds a global declaration (skipped when the file has it) on the line after the
first line that is exactly LINE.  Without --apply the plan and the text are printed.  One run is one lib and one file; repeat per file."""
import os
import re
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from lpc_fix_void_return import code_mask  # noqa: E402

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
KW = set("""if else for while do switch case default break continue return foreach in void int string object mapping mixed float status
varargs static nomask private protected public nosave class function buffer catch sizeof typeof new inherit include define ifdef endif
""".split())


def efuns():
    s = set()
    import glob
    for f in glob.glob(os.path.expanduser("~/src/fluffos/docs/efun/*/*.md")):
        s.add(os.path.basename(f)[:-3])
    return s


def match_close(code, i, o, c):
    d = 0
    for j in range(i, len(code)):
        ch = code[j:j + 1]
        if ch == o:
            d += 1
        elif ch == c:
            d -= 1
            if d == 0:
                return j
    return -1


def find_function(b, name):
    """-> (start, end) of the function `name` at top level (comment lines directly above included) or None"""
    mask = code_mask(b, heredoc=True)
    code = bytes(c if m else 32 for c, m in zip(b, mask))
    pat = re.compile(rb"(?m)^[ \t]*(?:(?:varargs|static|nomask|private|protected|public)[ \t]+)*(?:void|int|string|mixed|object|mapping|float|status|function)[ \t]*[*]*[ \t]*" + re.escape(name.encode()) + rb"[ \t]*\(")
    for m in pat.finditer(code):
        po = m.end() - 1
        pc = match_close(code, po, b"(", b")")
        if pc < 0:
            continue
        k = pc + 1
        while k < len(code) and code[k:k + 1] in b" \t\r\n":
            k += 1
        if code[k:k + 1] != b"{":
            continue
        e = match_close(code, k, b"{", b"}")
        if e < 0:
            continue
        s = m.start()
        # the comment lines directly above
        lines = b[:s].split(b"\n")
        keep = 0
        while keep < len(lines) - 1 and re.match(rb"\s*//", lines[-2 - keep]):
            keep += 1
        if keep:
            s -= sum(len(x) + 1 for x in lines[-1 - keep:-1])
        return s, e + 1
    return None


def main():
    args = sys.argv[1:]
    apply = "--apply" in args
    opt = {"--lib": None, "--from": None, "--path": None, "--var": None, "--after": None}
    names = []
    i = 0
    rest = []
    while i < len(args):
        if args[i] in opt:
            opt[args[i]] = args[i + 1]
            i += 2
        elif args[i] == "--name":
            names.append(args[i + 1])
            i += 2
        else:
            rest.append(args[i])
            i += 1
    if not (opt["--lib"] and opt["--from"] and opt["--path"] and (names or opt["--var"])):
        sys.exit(__doc__)
    lib, donor, path = opt["--lib"], opt["--from"], opt["--path"].lstrip("/")
    tp = f"{REPO}/libs/{lib}/work/{path}"
    dp = f"{REPO}/libs/{donor}/work/{path}"
    tb = open(tp, "rb").read()
    db = open(dp, "rb").read()
    crlf_t = b"\r\n" in tb and tb.count(b"\r\n") == tb.count(b"\n")
    crlf_d = b"\r\n" in db and db.count(b"\r\n") == db.count(b"\n")
    ef = efuns()
    ttext = tb.decode("utf-8", "replace")
    out = []
    var_done = False
    if opt["--var"]:
        decl, after = opt["--var"].strip(), (opt["--after"] or "").strip()
        lines = tb.split(b"\n")
        have = any(l.strip().rstrip(b"\r") == decl.encode() for l in lines)
        where = next((i for i, l in enumerate(lines) if l.strip().rstrip(b"\r") == after.encode()), -1) if after else -1
        if have:
            print(f"SKIP  {lib} {path}: already declares `{decl}`")
        elif where < 0:
            print(f"SKIP  {lib} {path}: no line `{after}` to put `{decl}` after")
        else:
            print(f"PLAN  {lib} {path}: `{decl}` after line {where + 1}")
            if apply:
                lines.insert(where + 1, decl.encode() + (b"\r" if crlf_t else b""))
                tb = b"\n".join(lines)
                var_done = True
    for name in names:
        if find_function(tb, name):
            print(f"SKIP  {lib} {path}: already defines {name}()")
            continue
        r = find_function(db, name)
        if not r:
            print(f"SKIP  {donor} {path}: no {name}()")
            continue
        text = db[r[0]:r[1]]
        if crlf_d:
            text = text.replace(b"\r\n", b"\n")
        t = text.decode("utf-8", "replace")
        clean = re.sub(r'"(?:\\.|[^"\\])*"', '""', re.sub(r"//[^\n]*", "", re.sub(r"/\*.*?\*/", "", t, flags=re.S)))
        idents = set(re.findall(r"[A-Za-z_]\w*", clean))
        declared = set(re.findall(r"(?:void|int|string|object|mapping|mixed|float|status|function)\s*[*]*\s*([A-Za-z_]\w*)", clean))
        unresolved = sorted(x for x in idents - declared - KW - ef if not re.search(r"(?<![A-Za-z0-9_])" + re.escape(x) + r"(?![A-Za-z0-9_])", ttext) and x != name)
        print(f"PLAN  {lib} {path}: {name}() from {donor}, {t.count(chr(10)) + 1} line(s)" + (f"; UNRESOLVED {unresolved}" if unresolved else ""))
        print("      " + t.strip().replace("\n", "\n      "))
        out.append(t)
    if apply and var_done and not out:
        open(tp, "wb").write(tb)
        print(f"wrote the declaration to {lib} {path}")
    if apply and out:
        nl = b"\r\n" if crlf_t else b"\n"
        add = ("\n" + "\n\n".join(x.strip("\n") for x in out) + "\n").encode("utf-8").replace(b"\n", nl)
        if not tb.endswith(b"\n"):
            tb += nl
        open(tp, "wb").write(tb + add)
        print(f"wrote {len(out)} function(s)" + (" and a declaration" if var_done else "") + f" to {lib} {path}")


if __name__ == "__main__":
    main()
