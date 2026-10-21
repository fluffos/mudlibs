#!/usr/bin/env python3
"""scripts/lpc_fix_bare_arg.py [--apply] [--libs a,b] [--all-dirs] [--files F...]

Commands that raise when typed with no argument (KB 06 7.336).  A command called bare gets 0 in its string parameter, and `main(object me, string arg)` /
`cmd(string args)` that opens with `sscanf(arg, ..)`, `lower_case(arg)`, `present(arg, ..)`, `read_file(arg)`, `new(arg)`, `explode(arg, ..)`, `arg[0]`... kills
the command with a runtime trace (`Bad argument 1 to sscanf() Expected: string Got: 0.`); the old driver let most of them pass.  The first statement of the entry
function that mentions the parameter decides: when it is one of those calls, at the top level of the function body and with no test of the parameter before it, a
guard goes in front of it, at its indentation:

    if (!arg) return help(me);                  the file defines `int help(object me)` (the xkx family prints the usage there); a file that defines it BELOW
                                                the entry gets the prototype `int help(object me);` in front of the entry (the compiler says `Undefined function help`
                                                otherwise: 112 of the first 164 files), and a file this tool guarded without the prototype is repaired by running again
    if (!args) { write(GetHelp() + "\\n"); return 1; }    the file defines `string GetHelp()` (Dead Souls)
    if (!arg) return notify_fail("...\\n");       otherwise a one-line refusal, Chinese when the file has CJK text

Efuns that take a 0 without complaint (`strlen`, `sizeof`, `to_int`, `write`, `sprintf("%s")`) are not candidates; a pattern-based command system (Discworld's
`add_command`, Lima's argv) never passes 0 and is not scanned (`--libs` names what to scan; Discworld, Lima and their families are skipped by default).
`--files` takes repo-relative paths (`libs/<slug>/work/cmds/wiz/test.lpc`, no listing of every lib: fast) or names inside the lib.
Dry run by default: one line per file (`slug path line statement -> guard`), the totals on stderr.  Binary mode, the file's own line ending, idempotent; the gitlink
libs are never touched.  Check afterwards with `scripts/lpcc_eval.py` (call the entry with 0) or a bare-verb sweep (KB 08 10.16)."""
import os
import re
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
GITLINKS = {"nt7", "xkx100utf8", "fy2005", "nightmare3", "residuum", "sanguozhi", "oxidus", "deadsouls_fluffos"}
PATTERN_BASED = {"discworld", "dw_fluffos_v1", "dw_fluffos_v2", "skylib", "finalrealms", "ninetears", "lima", "swmud", "spacemud", "wilderness", "merentha", "morgengrauen",
                 "questmud", "nirvlp312", "aoh", "sticklib", "simud"}
WIZ = re.compile(r"(^|/)(wiz|wizard|adm|admin|admins|arch|archwiz|creator|creators|immortal|immortals|god|gods|lord|lords|elder|domain|imm|builders|builder|cres)(/|$)", re.I)
SKIPDIR = re.compile(r"(^|/)(old|bak|backup|attic|antiguo|oldcomandos|raw|u|wizards|w|realms|test|tmp)(/|$)")
ENTRY = re.compile(rb"(?m)^[ \t]*(?:varargs[ \t]+)?(?:static[ \t]+|nomask[ \t]+)?(?:int|mixed|void)[ \t]+(main|cmd)[ \t]*\(([^)]*)\)[ \t]*(\r?\n)?[ \t]*\{")
RISKY = r"\b(sscanf|lower_case|upper_case|capitalize|explode|strsrch|replace_string|read_file|file_size|file_exists|find_player|find_living|present|restore_object|load_object|new|clone_object|crypt|implode|get_dir|keys|values|write_file|rm|mkdir|rmdir|cp|rename|read_bytes|cat)\s*\(\s*{p}\b|\b{p}\s*\["
GUARD = r"(!\s*{p}\b|\b{p}\s*(==|!=)|stringp\s*\(\s*{p}|\bif\s*\(\s*{p}\s*\)|\bif\s*\(\s*{p}\s*&&|\b{p}\s*\?|\b{p}\s*\|\||\b{p}\s*&&|\bsizeof\s*\(\s*{p}\s*\)\s*(<|==)|!\s*sizeof\s*\(\s*{p}|{p}\s*=\s*\"\"|{p}\s*=\s*{p}\s*\|\|)"
CJK = re.compile(rb"[\xe4-\xe9][\x80-\xbf][\x80-\xbf]")
HELPDEF = re.compile(rb"(?m)^(?:int|mixed)[ \t]+help[ \t]*\(\s*object[^)]*\)")        # `return help(me);` needs a function that answers an int
HELPCALL = re.compile(r"if \(!\w+\) return help\(\w+\);")


def body_span(data, start):
    """index just after the matching `}` of the `{` at start (strings and // comments skipped)"""
    depth = 0
    i = start
    n = len(data)
    while i < n:
        c = data[i:i + 1]
        if c == b"{":
            depth += 1
        elif c == b"}":
            depth -= 1
            if depth == 0:
                return i + 1
        elif c == b'"':
            i += 1
            while i < n and data[i:i + 1] != b'"':
                if data[i:i + 1] == b"\\":
                    i += 1
                i += 1
        elif c == b"/" and data[i + 1:i + 2] == b"/":
            while i < n and data[i:i + 1] != b"\n":
                i += 1
            continue
        i += 1
    return n


def plan_file(data):
    """list of (insert_at, indent, statement, guard) edits for one file (at most one per entry function)"""
    out = []
    nl = b"\r\n" if data.count(b"\r\n") * 2 > data.count(b"\n") else b"\n"
    for m in ENTRY.finditer(data):
        params = re.findall(rb"string\s+\*?\s*(\w+)", m.group(2))
        if not params:
            continue
        p = params[0].decode("latin-1")
        objp = re.findall(rb"object\s+(\w+)", m.group(2))
        me = objp[0].decode("latin-1") if objp else "me"
        open_brace = m.end() - 1
        help_def = HELPDEF.search(data)
        proto_needed = help_def is not None and HELPDEF.search(data, 0, m.start()) is None   # help() is defined below the entry and has no prototype: the compiler needs one
        help_proto = re.sub(rb"\s+", b" ", help_def.group(0)) + b";" if help_def else b""
        end = body_span(data, open_brace)
        body = data[open_brace:end]
        risky = re.compile(RISKY.replace("{p}", re.escape(p)))
        guard = re.compile(GUARD.replace("{p}", re.escape(p)))
        lines = body.split(b"\n")
        depth = lines[0].count(b"{") - lines[0].count(b"}")           # the line with the opening brace itself
        pos = len(lines[0]) + 1
        for ln in lines[1:]:
            line = ln.decode("utf-8", "replace")
            s = line.strip()
            line_start = pos
            pos += len(ln) + 1
            at_depth = depth
            depth += line.count("{") - line.count("}")
            if not s or s.startswith(("//", "/*", "*")):
                continue
            if not re.search(r"\b" + re.escape(p) + r"\b", s):
                continue
            if guard.search(s):
                if m.group(1) == b"main" and HELPCALL.fullmatch(s) and proto_needed:
                    out.append((m.start(), b"", "(prototype)", help_proto + nl))
                break
            if risky.search(s) and at_depth == 1:
                indent = re.match(rb"[ \t]*", ln).group(0)
                abs_pos = open_brace + line_start
                has_help = help_def is not None
                has_gethelp = re.search(rb"(?m)^string[ \t]+GetHelp[ \t]*\(", data) is not None
                if has_help and m.group(1) == b"main":
                    g = f"if (!{p}) return help({me});".encode()
                    if proto_needed:
                        out.append((m.start(), b"", "(prototype)", help_proto + nl))
                elif has_gethelp:
                    g = ("if (!" + p + ") { write(this_object()->GetHelp() + \"\\n\"); return 1; }").encode()
                else:
                    msg = "指令格式有误，请参考 help。".encode("utf-8") if CJK.search(data) else b"Argument needed."
                    g = b'if (!' + p.encode() + b') return notify_fail("' + msg + b'\\n");'
                out.append((abs_pos, indent, s, g + nl))
                break
            # a mention that is neither a test nor a risky call (`log_file(.., arg)`, `write(arg)`, a mention inside a nested block) does not decide: look on
    return out, nl


def main():
    apply = "--apply" in sys.argv
    all_dirs = "--all-dirs" in sys.argv
    libs = None
    files = []
    argv = sys.argv[1:]
    for i, a in enumerate(argv):
        if a == "--libs" and i + 1 < len(argv):
            libs = argv[i + 1].split(",")
        elif a == "--files":
            files = [x for x in argv[i + 1:] if not x.startswith("--")]
    cand = sorted(d for d in os.listdir(f"{REPO}/libs") if os.path.isdir(f"{REPO}/libs/{d}/work"))
    total = 0
    nfiles = 0
    per = {}
    # repo-relative file names need no `git ls-files` of every lib (that listing is the slow part of a run over a few hundred libs)
    direct = {}
    for f in files:
        mm = re.match(r"libs/([^/]+)/work/", f)
        if mm:
            direct.setdefault(mm.group(1), []).append(f)
    if len(direct) and sum(len(v) for v in direct.values()) != len(files):
        direct = {}                                    # a name inside the lib: list every lib's files as before
    for slug in cand:
        if slug in GITLINKS or (libs and slug not in libs) or (not libs and slug in PATTERN_BASED):
            continue
        if files and direct and slug not in direct:
            continue
        if files and slug in direct:
            names = direct[slug]
        else:
            out = subprocess.run(["git", "ls-files", "-z", "--", f"libs/{slug}/work"], cwd=REPO, capture_output=True).stdout
            names = [p.decode("utf-8", "surrogateescape") for p in out.split(b"\0") if p]
        for rel in names:
            if not rel.endswith((".lpc", ".c")):
                continue
            inner = rel[len(f"libs/{slug}/work/"):]
            if files and rel not in files and inner not in files:
                continue
            if not files:
                if not ("/cmds/" in "/" + inner or inner.startswith(("cmds/", "secure/cmds/", "lib/cmds/"))):
                    continue
                if SKIPDIR.search(inner) or (not all_dirs and not WIZ.search(inner)):
                    continue
            path = f"{REPO}/{rel}"
            try:
                data = open(path, "rb").read()
            except OSError:
                continue
            edits, nl = plan_file(data)
            if not edits:
                continue
            nfiles += 1
            total += len(edits)
            per[slug] = per.get(slug, 0) + 1
            for pos, indent, stmt, g in edits:
                lineno = data[:pos].count(b"\n") + 1
                print(slug + "\t" + inner + "\t" + str(lineno) + "\t" + stmt[:70] + "  ->  " + g.decode("utf-8", "replace").strip()[:80])
            if apply:
                for pos, indent, stmt, g in sorted(edits, reverse=True):
                    data = data[:pos] + indent + g + data[pos:]
                open(path, "wb").write(data)
    print(f"{nfiles} file(s), {total} guard(s) in {len(per)} lib(s)" + ("" if apply else " (dry run)"), file=sys.stderr)


if __name__ == "__main__":
    main()
