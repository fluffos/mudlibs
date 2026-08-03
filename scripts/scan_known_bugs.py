#!/usr/bin/env python3
"""Read-only scan of one lib's work/ tree for AGENTS.md's catalog of
recurring bug SIGNATURES -- complements scripts/lib_bulk_fix.py, which
blindly auto-applies a handful of exact-literal-match-safe fixes. Most
of the patterns here are too varied in exact wording across libs to
safely regex-replace (a wrong auto-fix silently corrupts working code),
so this only REPORTS candidates with file:line context for a human (or
agent) to triage in one pass, instead of rediscovering the same handful
of bug classes one boot-cycle at a time.

Not a substitute for actually booting the lib -- a clean scan does not
mean the lib boots; a hit does not always mean a real bug (read the
surrounding code before "fixing" anything it flags).

Usage: python3 scripts/scan_known_bugs.py <slug> [<slug> ...]
       python3 scripts/scan_known_bugs.py --all   (every libs/*/work)
"""
import os
import re
import sys

MUDLIB_ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
LIBS_DIR = os.path.join(MUDLIB_ROOT, "libs")
SKIP_DIRS = {"log", "save", "data", "binaries", ".git"}


def iter_source_files(work, names=None, exts=(".lpc", ".h")):
    for dirpath, dirnames, filenames in os.walk(work):
        dirnames[:] = [d for d in dirnames if d not in SKIP_DIRS]
        for fn in filenames:
            if names is not None:
                if fn.lower() in names:
                    yield os.path.join(dirpath, fn)
                continue
            if fn.endswith(exts):
                yield os.path.join(dirpath, fn)


def read(path):
    try:
        with open(path, encoding="utf-8", errors="surrogateescape") as f:
            return f.read()
    except OSError:
        return None


def line_no(content, pos):
    return content.count("\n", 0, pos) + 1


# Each checker: fn(work) -> list of "path:line: message" strings.

def check_convertd_backslash(work):
    hits = []
    pat = re.compile(r'\\"(,)?\r?\n')
    for f in iter_source_files(work, {"convertd.c", "convertd.lpc"}):
        content = read(f)
        if not content:
            continue
        n = len(pat.findall(content))
        if n:
            hits.append(f"{f}: {n}x §6.6 stray-backslash-before-quote "
                        "(convertd Greek/symbol table) -- fix: strip the \\")
    return hits


def check_absolute_angle_include(work):
    hits = []
    pat = re.compile(r'#include\s*<(/[^>]+)>')
    for f in iter_source_files(work):
        content = read(f)
        if not content:
            continue
        for m in pat.finditer(content):
            hits.append(f"{f}:{line_no(content, m.start())}: absolute-path "
                        f"angle-bracket include <{m.group(1)}> -- never "
                        "resolves under this driver's include-directories "
                        'search; fix: quote it, #include "..."')
    return hits


def check_is_chinese_byte_range(work):
    """Flags the actual buggy shape (a raw sub-256 byte-value comparison,
    e.g. `str[0] > 160`, or a `strlen(str) % 2` parity gate) -- NOT just
    any is_chinese() that happens to mention strlen(), since the correct
    fixed form (`strlen(str) >= 1 && str[0] >= 0x4e00 && str[0] <= 0x9fff`)
    also does a length check and would false-positive on a looser pattern."""
    hits = []
    fn_pat = re.compile(r'\bis_chinese\s*\(\s*string\b')
    bug_pat = re.compile(
        r'%\s*2\b|[<>]=?\s*(?:1\d\d|2[0-4]\d|25[0-5])\b(?!\d)')
    ok_pat = re.compile(r'0x4[eE]00|0x9[fF][fF][fF]')
    for f in iter_source_files(work, {"chinese.c", "chinese.lpc",
                                       "chinesed.lpc"}):
        content = read(f)
        if not content:
            continue
        for m in fn_pat.finditer(content):
            body_start = content.find("{", m.start())
            if body_start == -1:
                continue
            window = content[body_start:body_start + 300]
            if ok_pat.search(window):
                continue  # already the correct per-codepoint form
            if bug_pat.search(window):
                snippet = window.split("\n")[1][:80] if "\n" in window else window[:80]
                hits.append(f"{f}:{line_no(content, m.start())}: "
                            f"is_chinese() looks like the §8.1 GBK "
                            f"byte-range/parity bug (should be a per-"
                            f"codepoint 0x4e00-0x9fff check): {snippet!r}")
    return hits


def check_legal_name_parity(work):
    hits = []
    pat = re.compile(r'\bcheck_legal_name\b')
    parity_pat = re.compile(r'i\s*%\s*2\s*==\s*0|\[i\s*\.\.\s*<\s*0\s*\]')
    for f in iter_source_files(work, {"logind.c", "logind.lpc"}):
        content = read(f)
        if not content:
            continue
        for m in pat.finditer(content):
            # look at the next ~600 chars (the function body) for the
            # parity-gate / suffix-slice shape.
            window = content[m.start():m.start() + 600]
            if parity_pat.search(window):
                hits.append(f"{f}:{line_no(content, m.start())}: "
                            "check_legal_name() near an i%2==0 parity gate "
                            "or [i..<0] suffix slice -- likely the §8.1 "
                            "byte-pair-assumption bug (should be per-"
                            "codepoint, name[i..i])")
    return hits


def check_tell_room_bare_exclude(work):
    hits = []
    # message(..., exclude) where exclude has no "|| ({})" / "|| 0" guard
    # immediately before the closing paren.
    pat = re.compile(
        r'message\s*\(\s*"tell_room"\s*,\s*\w+\s*,\s*\w+\s*,\s*(\w+)\s*\)')
    for f in iter_source_files(work, {"message.c", "message.lpc"}):
        content = read(f)
        if not content:
            continue
        for m in pat.finditer(content):
            hits.append(f"{f}:{line_no(content, m.start())}: tell_room() "
                        f"forwards bare '{m.group(1)}' as message()'s "
                        "exclude arg with no || ({}) default -- §7.12, "
                        "crashes 'Bad argument 4 to EFUN message()' the "
                        "first time a 2-arg caller hits it")
    return hits


def check_log_error_channel_d(work):
    hits = []
    pat = re.compile(r'\blog_error\s*\(')
    guard_pat = re.compile(r'find_object\s*\(\s*CHANNEL_D\s*\)')
    for f in iter_source_files(work, {"master.c", "master.lpc"}):
        content = read(f)
        if not content:
            continue
        for m in pat.finditer(content):
            # function body: from this match to the next top-level "}\n\n"
            # or 800 chars, whichever first -- rough but good enough for a
            # scan.
            body_start = content.find("{", m.start())
            if body_start == -1:
                continue
            window = content[body_start:body_start + 800]
            if "CHANNEL_D" in window and "do_channel" in window \
                    and not guard_pat.search(window):
                hits.append(f"{f}:{line_no(content, m.start())}: "
                            "log_error() calls CHANNEL_D->do_channel() "
                            "without a find_object(CHANNEL_D) guard -- "
                            "§7.60, crashes 'Object cannot be loaded "
                            "during compilation' on the first compile "
                            "warning before CHANNEL_D preloads")
    return hits


def check_master_valid_read_delegates_blindly(work):
    hits = []
    pat = re.compile(
        r'int\s+valid_read\s*\([^)]*\)\s*\{([^{}]*(?:\{[^{}]*\}[^{}]*)*)\}')
    for f in iter_source_files(work, {"master.c", "master.lpc"}):
        content = read(f)
        if not content:
            continue
        for m in pat.finditer(content):
            body = m.group(1)
            if "SECURITY_D" in body and "this_object()" not in body:
                hits.append(f"{f}:{line_no(content, m.start())}: "
                            "valid_read() forwards straight to "
                            "SECURITY_D with no 'user == this_object()' "
                            "short-circuit -- the driver's own internal "
                            "load_object() security check passes the "
                            "MASTER OBJECT as 'user' when compiling a new "
                            "class (e.g. new(USER_OB) at registration); "
                            "if securityd denies unrecognized/falsy euids "
                            "this silently kills every new-player-body "
                            "compile with zero visible error (found on "
                            "xyj20032)")
    return hits


def check_socket_daemon_not_gutted(work):
    hits = []
    pat = re.compile(r'\bsocket_(create|bind|listen|accept|connect|write)\s*\(')
    for f in iter_source_files(work):
        base = os.path.basename(f).lower()
        if base not in {"httpd.c", "httpd.lpc", "dns_master.c",
                         "dns_master.lpc", "payd.c", "payd.lpc",
                         "mudlistd.c", "mudlistd.lpc", "ftpd.c", "ftpd.lpc"}:
            continue
        content = read(f)
        if not content:
            continue
        n = len(pat.findall(content))
        if n:
            hits.append(f"{f}: {n}x raw socket_*() call(s), not yet gutted "
                        "-- §7.52 (sockets package unavailable under WASM); "
                        "check external callers via grep before deciding "
                        "whole-file-disable vs selective-entry-point-gut")
    return hits


def check_non_utf8_source(work):
    hits = []
    for f in iter_source_files(work):
        content = read(f)
        if content is None:
            continue
        try:
            content.encode("utf-8")
        except UnicodeEncodeError:
            hits.append(f"{f}: contains surrogate-escaped (non-UTF8) bytes "
                        "-- a leftover raw GBK file the original bulk "
                        "conversion pass missed; fix: iconv -c -f GB18030 "
                        "-t UTF-8")
    return hits


def check_is_killing_object_vs_string(work):
    hits = []
    decl_pat = re.compile(r'\bis_killing\s*\(\s*string\b')
    call_pat = re.compile(r'\bis_killing\s*\(\s*(me|who|ob|ob\[i\])\s*\)')
    has_string_decl = any(
        decl_pat.search(read(f) or "")
        for f in iter_source_files(work, {"attack.c", "attack.lpc"}))
    if not has_string_decl:
        return hits
    for f in iter_source_files(work):
        content = read(f)
        if not content:
            continue
        for m in call_pat.finditer(content):
            hits.append(f"{f}:{line_no(content, m.start())}: "
                        f"is_killing({m.group(1)}) passes an object where "
                        "is_killing(string id) is declared -- §7.50 type "
                        "mismatch")
    return hits


CHECKS = [
    ("convertd-backslash", check_convertd_backslash),
    ("absolute-include", check_absolute_angle_include),
    ("is_chinese-byte-range", check_is_chinese_byte_range),
    ("check_legal_name-parity", check_legal_name_parity),
    ("tell_room-bare-exclude", check_tell_room_bare_exclude),
    ("log_error-channel_d", check_log_error_channel_d),
    ("master-valid_read-blind", check_master_valid_read_delegates_blindly),
    ("socket-daemon-not-gutted", check_socket_daemon_not_gutted),
    ("non-utf8-source", check_non_utf8_source),
    ("is_killing-object-vs-string", check_is_killing_object_vs_string),
]


def scan_lib(slug):
    work = os.path.join(LIBS_DIR, slug, "work")
    if not os.path.isdir(work):
        print(f"{slug}: no work/ dir, skipping")
        return
    total = 0
    print(f"=== {slug} ===")
    for name, fn in CHECKS:
        hits = fn(work)
        total += len(hits)
        if hits:
            print(f"-- {name} ({len(hits)}) --")
            for h in hits:
                print(f"  {h}")
    if not total:
        print("  (no known-pattern hits)")
    print()


def main():
    args = sys.argv[1:]
    if not args:
        print(__doc__)
        sys.exit(1)
    if args == ["--all"]:
        slugs = sorted(s for s in os.listdir(LIBS_DIR)
                       if os.path.isdir(os.path.join(LIBS_DIR, s, "work")))
    else:
        slugs = args
    for slug in slugs:
        scan_lib(slug)


if __name__ == "__main__":
    main()
