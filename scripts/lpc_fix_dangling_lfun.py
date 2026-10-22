#!/usr/bin/env python3
"""scripts/lpc_fix_dangling_lfun.py [--apply] [--list] SLUG [FILE...]

A function pointer `(: name :)` to a function the object does not define raises `*Undefined lfun pointer called: name` when it is used (KB 06 section 7.355):
`ask guard about job` for `"job" : (: ask_job :)` in an `inquiry` mapping, `look sign` for an `item_desc` pair, the random `chat()` pick of a `(: do_chat :)` element of a
`chat_msg` / `chat_msg_combat` array (the rest of that heart beat's `chat()` is skipped).  `lpc_port_function.py --lfun` puts the function back where a sibling lineage still has
it; this tool handles the rest, the pointers whose body is lost, never written or commented out by the author (about 800 lines in 180 libs after the donors were used).

The line that holds nothing but the pair / the element (`"job" : (: ask_job :),`, `(: do_chat :),`, with an optional trailing `//` comment) is commented out and says why:

    // "job" : (: ask_job :),  // no such function in this lib: the pointer raised (KB 06 7.355)

so a lib that gains the function later shows what to put back.  The topic (item, chat line) answers as an unknown one instead of raising.  Left alone, listed as LEFT: a pointer in
the middle of a line (`call_out((: f :), 3)`, `set("eat_func", (: f :))`, `add_command(..)`), a key that is not a quoted string, a continued macro line, and EVERY hit of a file whose `#include` closure
names a file the lib does not have (chidi's `guojing` includes `zzzjob.lpc` / `teamjob.lpc`: `ask_job` was defined in them, the NPC does not even compile, and the pointer is not what is broken), and EVERY hit of a file with no `inherit` at all: an include fragment (hy5 / hymud `quest/menpai/romnpc2.lpc`, the Shen Shu `quest/shenshu/npc/action.lpc` in five libs: `(: perform_action, "unarmed.ji" :)` pointers of a `mapping *pfm` that NPC files `#include`; the first run commented out 2,911 such lines, every one of them valid in the includer, and restored them).  Idempotent (a commented line
is not a hit any more).  The hits come from `lpc_scan_callout_targets.py --kinds=lfun SLUG` (the object's own, included and inherited functions, macros resolved, inactive `#ifdef`
regions skipped); binary mode, the file's own line endings.  Dry run unless `--apply`; `--list` prints every line."""
import os
import re
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import lpc_scan_callout_targets as S  # noqa: E402

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
NOTE = b"  // no such function in this lib: the pointer raised (KB 06 7.355)"


def hits(slug):
    out = subprocess.run([sys.executable, os.path.join(REPO, "scripts", "lpc_scan_callout_targets.py"), "--kinds=lfun", slug], cwd=REPO, capture_output=True).stdout
    rows = []
    for line in out.split(b"\n"):
        p = line.split(b"\t")
        if len(p) >= 6 and p[0] == b"HIT" and p[1] == b"lfun" and p[2].decode() == slug:
            rows.append((p[3].decode("utf-8", "replace"), p[4].decode(), int(p[5])))
    return rows


INCLUDE = re.compile(rb'(?m)^[ \t]*#[ \t]*include[ \t]+(["<])([^">\r\n]+)[">]')


def unresolved_includes(lib, f, seen=None):
    """the `#include` names of f (and of the headers it pulls in) that no file of the lib answers"""
    seen = seen if seen is not None else set()
    if f in seen:
        return []
    seen.add(f)
    bad = []
    fdir = os.path.dirname(f) + "/"
    for m in INCLUDE.finditer(S.strip_comments(lib.read(f))):
        name = m.group(2).decode("utf-8", "replace")
        if name.startswith("/"):
            cands = [os.path.normpath(name)]
        else:
            cands = [os.path.normpath(fdir + name)] if m.group(1) == b'"' else []
            cands += [os.path.normpath(d + "/" + name) for d in lib.incdirs] + [os.path.normpath("/" + name)]
        for c in cands:
            if c in lib.files:
                bad += unresolved_includes(lib, c, seen)
                break
        else:
            bad.append(name)
    return bad


def shape(line, name):
    """'pair' / 'elem' for a line that holds only the pointer (as a mapping pair or an array element), else None"""
    n = re.escape(name.encode())
    ptr = rb"\(:[ \t]*" + n + rb"(?:[ \t]*,[^\r\n]*?)?[ \t]*:\)"
    tail = rb"[ \t]*,?[ \t]*(?://[^\r\n]*)?\r?$"
    if re.match(rb'^[ \t]*"(?:[^"\\\r\n]|\\.)*"[ \t]*:[ \t]*' + ptr + tail, line):
        return "pair"
    if re.match(rb"^[ \t]*" + ptr + tail, line):
        return "elem"
    return None


def fix(b, rows):
    """returns (new bytes, [(line number, text)], [(line number, text)]).  The scanner reports a name once per file (its first line): every other line of the file that holds
    the same pointer in a fixable shape is taken too (`"leave": (: expell_me :),` after `"出门": (: expell_me :),`)"""
    lines = b.split(b"\n")
    done, left = [], []
    names = {name for _ln, name in rows}
    todo = set(rows)
    for i, text in enumerate(lines):
        if b"(:" not in text:
            continue
        for name in names:
            if (i + 1, name) not in todo and shape(text, name):
                todo.add((i + 1, name))
    for ln, name in sorted(todo):
        if ln < 1 or ln > len(lines):
            continue
        s = lines[ln - 1]
        if lines[ln - 1].rstrip(b"\r").endswith(b"\\"):
            left.append((ln, s.decode("utf-8", "replace").strip()))
            continue
        if shape(s, name) is None:
            left.append((ln, s.decode("utf-8", "replace").strip()))
            continue
        eol = b"\r" if s.endswith(b"\r") else b""
        body = s[:-1] if eol else s
        indent = body[:len(body) - len(body.lstrip(b" \t"))]
        lines[ln - 1] = indent + b"// " + body.lstrip(b" \t") + NOTE + eol
        done.append((ln, body.strip().decode("utf-8", "replace")))
    return b"\n".join(lines), done, left


def main():
    argv = sys.argv[1:]
    apply, listing = "--apply" in argv, "--list" in argv
    args = [a for a in argv if not a.startswith("--")]
    if not args:
        sys.exit(__doc__)
    slug, only = args[0], set(args[1:])
    root = os.path.join(REPO, "libs", slug, "work")
    byfile = {}
    for f, name, ln in hits(slug):
        if only and f not in only:
            continue
        byfile.setdefault(f, []).append((ln, name))
    nfile = nfix = nleft = 0
    lib = S.Lib(slug) if byfile else None
    for f, rows in sorted(byfile.items()):
        p = root + f
        b = open(p, "rb").read()
        if not re.search(rb"(?m)^[ \t]*inherit\b", b):
            nleft += len(rows)           # no `inherit` at all: an include fragment (`mapping *pfm = ({ (: perform_action, "x" :), .. })`, a `::set_skills()` body) whose pointers are created in the includer
            if listing:
                print(f"LEFT {f}: {len(rows)} hit(s), the file has no inherit: an include fragment, its pointers bind to the object that includes it")
            continue
        miss = unresolved_includes(lib, f)
        if miss:
            nleft += len(rows)
            if listing:
                print(f"LEFT {f}: {len(rows)} hit(s), the file's #include closure lacks {', '.join(sorted(set(miss)))}")
            continue
        nb, done, left = fix(b, rows)
        nleft += len(left)
        if listing:
            for ln, t in left:
                print(f"LEFT {f}:{ln}: {t[:110]}")
        if not done:
            continue
        nfile += 1
        nfix += len(done)
        print(f"{'FIX' if apply else 'would fix'} {f}: {len(done)} line(s)")
        if listing:
            for ln, t in done:
                print(f"    {ln}: {t[:110]}")
        if apply:
            open(p, "wb").write(nb)
    print(f"{slug}: {nfix} line(s) in {nfile} file(s), {nleft} left" + ("" if apply else " (plan only; --apply writes)"), file=sys.stderr)


if __name__ == "__main__":
    main()
