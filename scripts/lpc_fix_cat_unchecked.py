#!/usr/bin/env python3
"""scripts/lpc_fix_cat_unchecked.py [--apply] [SLUG...]

The simulated efun `cat(file)` writes whatever `read_file()` answers; for a file
the archive does not ship, a directory (`file_size == -2`), or an unreadable path
`read_file()` answers `0`, which either passes `0` to `receive()`
(`Bad argument 1 to receive()  Expected: string or buffer Got: 0`) or prints `"0"`
to the user.  Becomes `... read_file(...) || "" ...` inside the unguarded `cat()`
function body (KB 06 section 7.297, 7.388).

Covers every live unguarded `sefun::cat()` definition (with comments/strings masked
so commented-out copies are untouched) across three body shapes:
  1. `write([efun::]read_file(...));` / `efun::write(...)` (including after
     `seteuid()`, `file_size()` upper-bound checks, or `valid_read()` checks)
  2. `message(..., [efun::]read_file(...), ...)`
  3. `var = [efun::]read_file(...);` where `var` is later written/passed without
     checking `stringp(var)` / `if (var)` (e.g. `bmxkx2001`, `chidi`, `kxkj1`).

Binary-safe, preserves line endings, idempotent.  Without --apply prints
`FIX<TAB>slug<TAB>/path` per file."""
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import lpc_scan_cond_assign as sc  # noqa: E402
import lpc_add_sefun as S  # noqa: E402
from lpc_fix_void_return import code_mask  # noqa: E402

REPO = sc.REPO
CAT_HEADER = re.compile(
    r"(?:^|\n)[ \t]*(?:(?:varargs|public|nomask)\s+)*(?:void|int|mixed|string)\s+cat\s*\([^)]*\)\s*\{"
)
HAS_GUARD_CODE = re.compile(
    r"stringp\s*\(|\!\s*stringp|file_size\s*\([^)]+\)\s*<\s*1|file_size\s*\([^)]+\)\s*<=\s*0"
)
HAS_GUARD_RAW = re.compile(rb'\|\|\s*""|\?\s*[^:]+:\s*""')
ASSIGN_RF = re.compile(r"(\w+)\s*=\s*(?:efun::)?read_file\s*\(")
WRITE_RF = re.compile(r"\b(?:efun::)?write\s*\(\s*(?:efun::)?read_file\s*\(")
MSG_START = re.compile(r"\b(?:efun::)?message\s*\(")
RF_START = re.compile(r"^(?:efun::)?read_file\s*\(")


def _blank_noncode(raw: bytes) -> str:
    m = code_mask(raw, heredoc=True)
    return bytearray(b if (flag or b == 10) else 32 for b, flag in zip(raw, m)).decode("latin1")


def _match_brace(s: str, open_pos: int) -> int:
    depth = 0
    for i in range(open_pos, len(s)):
        if s[i] == "{":
            depth += 1
        elif s[i] == "}":
            depth -= 1
            if depth == 0:
                return i
    return -1


def _match_paren(s: str, open_pos: int) -> int:
    depth = 0
    for i in range(open_pos, len(s)):
        if s[i] == "(":
            depth += 1
        elif s[i] == ")":
            depth -= 1
            if depth == 0:
                return i
    return -1


def _is_unguarded(mbody: str, rbody: bytes) -> bool:
    if "read_file(" not in mbody:
        return False
    if HAS_GUARD_RAW.search(rbody) or HAS_GUARD_CODE.search(mbody):
        return False
    mv = ASSIGN_RF.search(mbody)
    if mv:
        v = re.escape(mv.group(1))
        if re.search(rf"(?:if|while)\s*\(\s*!?\s*{v}\b", mbody):
            return False
        if re.search(rf"\b{v}\b[^;{{}}]*?(?:==|!=)\s*0", mbody):
            return False
        if re.search(rf"if\s*\(\s*\(?{v}\s*=\s*(?:efun::)?read_file\s*\(", mbody):
            return False
    return True


def patch_bytes(raw: bytes) -> bytes | None:
    masked = _blank_noncode(raw)
    inserts: list[int] = []
    for hm in CAT_HEADER.finditer(masked):
        body_start = hm.end() - 1
        body_end = _match_brace(masked, body_start)
        if body_end < 0:
            continue
        mbody = masked[hm.start() : body_end + 1]
        rbody = raw[hm.start() : body_end + 1]
        if not _is_unguarded(mbody, rbody):
            continue

        base = hm.start()
        found = False
        # 1. [efun::]write([efun::]read_file(...));
        for wm in WRITE_RF.finditer(mbody):
            rf_close = _match_paren(mbody, wm.end() - 1)
            if rf_close < 0:
                continue
            rest = mbody[rf_close + 1 :]
            if re.match(r"\s*\)\s*;", rest):
                inserts.append(base + rf_close + 1)
                found = True
        if found:
            continue

        # 2. [efun::]message(cls, [efun::]read_file(...), target, ...)
        for mm in MSG_START.finditer(mbody):
            p0 = mm.end() - 1
            p_end = _match_paren(mbody, p0)
            if p_end < 0:
                continue
            # Find first top-level comma (end of arg 1)
            depth = 0
            comma1 = -1
            for i in range(p0 + 1, p_end):
                c = mbody[i]
                if c in "({[":
                    depth += 1
                elif c in ")}]":
                    depth -= 1
                elif c == "," and depth == 0:
                    comma1 = i
                    break
            if comma1 < 0:
                continue
            j = comma1 + 1
            while j < p_end and mbody[j].isspace():
                j += 1
            rm = RF_START.match(mbody[j:p_end])
            if rm:
                rf_close = _match_paren(mbody, j + rm.end() - 1)
                if 0 <= rf_close < p_end and mbody[rf_close + 1 : p_end].lstrip().startswith(","):
                    inserts.append(base + rf_close + 1)
                    found = True
        if found:
            continue

        # 3. var = [efun::]read_file(...);
        for am in ASSIGN_RF.finditer(mbody):
            rf_close = _match_paren(mbody, am.end() - 1)
            if rf_close < 0:
                continue
            rest = mbody[rf_close + 1 :]
            if re.match(r"\s*;", rest):
                inserts.append(base + rf_close + 1)
                found = True

    if not inserts:
        return None
    out = raw
    for pos in sorted(set(inserts), reverse=True):
        out = out[:pos] + b' || ""' + out[pos:]
    return out


def main():
    a = sys.argv[1:]
    apply_ = "--apply" in a
    slugs = [x for x in a if not x.startswith("--")]
    n = 0
    for slug, _paths in sorted(sc.tracked(slugs).items()):
        if slug in sc.LDMUD or slug in sc.GENERATED:
            continue
        if os.path.exists(f"{REPO}/libs/{slug}/work/.git"):
            continue
        try:
            files = S.sefun_files(slug)
        except OSError:
            continue
        seen = set()
        for f in files:
            rp = os.path.realpath(f)
            if rp in seen:
                continue
            seen.add(rp)
            try:
                b = open(f, "rb").read()
            except OSError:
                continue
            patched = patch_bytes(b)
            if patched is None:
                continue
            rel = "/" + os.path.relpath(f, f"{REPO}/libs/{slug}/work")
            n += 1
            print(f"FIX\t{slug}\t{rel}")
            if apply_:
                open(f, "wb").write(patched)
    print(f"{n} file(s)", file=sys.stderr)


if __name__ == "__main__":
    main()
