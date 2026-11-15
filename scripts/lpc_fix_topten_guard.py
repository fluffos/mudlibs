#!/usr/bin/env python3
"""Fix JackyBoy toptend empty/missing rank-file crashes and sscanf(astr, ...) bugs.

Scans vendored, non-duplicate playable mudlibs under libs/<slug>/work/ for
JackyBoy-derived /adm/daemons/toptend.lpc files and fixes:
1. file_size(<var>) == -1 -> <= 0 inside topten_query/topten_del/topten_add
   (and top_query/top_del/top_add). Leaves ban-file / helper checks untouched.
2. Post-topten_del read_file() empty/zero-return crashes in topten_add and
   topten_del by guarding !stringp(...) with empty-array fallback and filtering
   blank lines via - ({ "" }), reusing each file's own initial-entry creation
   block when the file becomes empty after topten_del. Also guards
   topten_query's explode(...) with - ({ "" }) and fixes shiji/sj/syxjl's
   write_file(f_name, str) missing overwrite flag (, 1).
3. Uncommented sscanf(<arr_var>, "...;%*s", ...) calls passing an array as arg 1
   and/or using != 3 on "%s(%s)%d;%*s" / "%s[%s]%d;%*s" / "%s(%s)%s;%*s"
   (changing != 3 to < 3, or != 2 to < 2 on shenmo's "(%s)%d;%*s", while
   leaving wxddym's already-correct != 4 untouched).

Default is dry-run; pass --apply to write changes.
"""

from __future__ import annotations

import argparse
import glob
import json
import os
import re
import sys

SKIP_NON_JACKYBOY = {
    "aoxiangtianji",
    "fengyun434",
    "mhxy",
    "mhxyqd",
    "sje",
    "tianlongbabu",
    "xiyouji2003",
    "xsfyssjb",
}

TARGET_FUNCS = {
    "topten_query",
    "topten_del",
    "topten_add",
    "top_query",
    "top_del",
    "top_add",
}


def detect_newline(raw: bytes) -> str:
    crlf = raw.count(b"\r\n")
    lf = raw.count(b"\n") - crlf
    return "\r\n" if crlf > lf else "\n"


def split_func_ranges(lines: list[str]) -> list[tuple[str, int, int]]:
    """Return (func_name, start_idx, end_idx) for top-level TARGET_FUNCS."""
    ranges: list[tuple[str, int, int]] = []
    i = 0
    n = len(lines)
    pat = re.compile(
        r"^(?:public\s+|private\s+|static\s+|nomask\s+)*"
        r"(?:string|int|void|mixed)\s+"
        r"(topten_query|topten_del|topten_add|top_query|top_del|top_add)\s*\("
    )
    while i < n:
        m = pat.match(lines[i].lstrip())
        # Ignore forward prototypes (ending with ';' without '{')
        if m and not lines[i].lstrip().startswith("//"):
            # Find opening brace within a couple of lines unless line ends with ';'
            j = i
            has_semi_first = False
            while j < n and j < i + 5:
                stripped = lines[j].split("//", 1)[0]
                if "{" in stripped:
                    break
                if ";" in stripped:
                    has_semi_first = True
                    break
                j += 1
            if not has_semi_first and j < n and "{" in lines[j].split("//", 1)[0]:
                fname = m.group(1)
                depth = 0
                k = j
                while k < n:
                    code = re.sub(r'"(?:\\.|[^"\\])*"', '""', lines[k].split("//", 1)[0])
                    depth += code.count("{") - code.count("}")
                    if depth <= 0 and k >= j:
                        ranges.append((fname, i, k))
                        i = k + 1
                        break
                    k += 1
                else:
                    i += 1
                continue
        i += 1
    return ranges


def find_closing_brace(lines: list[str], open_idx: int) -> int:
    depth = 0
    for idx in range(open_idx, len(lines)):
        code = re.sub(r'"(?:\\.|[^"\\])*"', '""', lines[idx].split("//", 1)[0])
        depth += code.count("{") - code.count("}")
        if depth <= 0:
            return idx
    return open_idx


def fix_text(text: str) -> tuple[str, list[str]]:
    nl = "\r\n" if "\r\n" in text and text.count("\r\n") >= text.count("\n") // 2 else "\n"
    lines = text.splitlines()
    changes: list[str] = []

    ranges = split_func_ranges(lines)
    if not ranges:
        return text, changes

    # Work bottom-up across target functions so line indices stay valid cleanly.
    for fname, start, end in reversed(ranges):
        is_query = fname in ("topten_query", "top_query")
        is_del = fname in ("topten_del", "top_del")
        is_add = fname in ("topten_add", "top_add")

        # 1. Fix file_size(...) == -1 -> <= 0 inside this function, and capture
        #    add's empty-file init block if needed.
        init_body_lines: list[str] | None = None
        i = start
        while i <= end:
            line = lines[i]
            if (
                not line.lstrip().startswith("//")
                and "file_size(" in line
                and re.search(r"==\s*-1", line)
            ):
                new_line = re.sub(r"==\s*-1", "<= 0", line, count=1)
                if new_line != line:
                    lines[i] = new_line
                    changes.append(f"{fname}:file_size<=0")

                if is_add and init_body_lines is None:
                    # Capture body of `if (file_size(...) <= 0) { ... }`
                    brace_line = i
                    if "{" not in lines[brace_line].split("//", 1)[0]:
                        if brace_line + 1 <= end and "{" in lines[brace_line + 1]:
                            brace_line += 1
                    if "{" in lines[brace_line].split("//", 1)[0]:
                        close_idx = find_closing_brace(lines, brace_line)
                        # Check for write_file(f_name, str) missing , 1 inside init block
                        for bi in range(brace_line, close_idx + 1):
                            if re.search(r"write_file\(\s*f_name\s*,\s*str\s*\)", lines[bi]):
                                lines[bi] = re.sub(
                                    r"write_file\(\s*f_name\s*,\s*str\s*\)",
                                    "write_file(f_name, str, 1)",
                                    lines[bi],
                                )
                                changes.append(f"{fname}:write_file_trunc")
                        init_body_lines = lines[brace_line + 1 : close_idx]
            elif is_add and init_body_lines is None and "file_size(" in line and "<= 0" in line:
                # Already <= 0 (e.g. re-run or previously patched init); still capture init body!
                brace_line = i
                if "{" not in lines[brace_line].split("//", 1)[0]:
                    if brace_line + 1 <= end and "{" in lines[brace_line + 1]:
                        brace_line += 1
                if "{" in lines[brace_line].split("//", 1)[0]:
                    close_idx = find_closing_brace(lines, brace_line)
                    for bi in range(brace_line, close_idx + 1):
                        if re.search(r"write_file\(\s*f_name\s*,\s*str\s*\)", lines[bi]):
                            lines[bi] = re.sub(
                                r"write_file\(\s*f_name\s*,\s*str\s*\)",
                                "write_file(f_name, str, 1)",
                                lines[bi],
                            )
                            changes.append(f"{fname}:write_file_trunc")
                    init_body_lines = lines[brace_line + 1 : close_idx]
            i += 1

        # 2. Function-specific guards and sscanf fixes
        if is_query:
            for idx in range(start, end + 1):
                line = lines[idx]
                if line.lstrip().startswith("//"):
                    continue
                if (
                    "explode(" in line
                    and "read_file(" in line
                    and '- ({ "" })' not in line
                    and '- ({""})' not in line
                    and ";" in line
                ):
                    new_line = re.sub(
                        r'(\bexplode\([^;]+?\))\s*;',
                        r'\1 - ({ "" });',
                        line,
                        count=1,
                    )
                    if new_line != line:
                        lines[idx] = new_line
                        changes.append(f"{fname}:filter_empty")
                        break

        elif is_del:
            # Find `str = read_file(...);` followed by `astr = explode(str, "\n");`
            # (or `v1 = read_file(...); v2 = explode(v1, "\n");`)
            for idx in range(start, end + 1):
                line = lines[idx]
                if line.lstrip().startswith("//"):
                    continue
                m_exp = re.match(
                    r'^([ \t]*)([A-Za-z_][A-Za-z0-9_]*)\s*=\s*explode\(\s*([A-Za-z_][A-Za-z0-9_]*)\s*,\s*"\\n"\s*\)\s*;\s*$',
                    line,
                )
                if m_exp and '- ({ "" })' not in line and '- ({""})' not in line:
                    indent, arr_var, str_var = m_exp.group(1), m_exp.group(2), m_exp.group(3)
                    # Check if already guarded nearby
                    prev_ctx = "\n".join(lines[max(start, idx - 3) : idx + 1])
                    if f"stringp({str_var})" in prev_ctx:
                        continue
                    lines[idx : idx + 1] = [
                        f'{indent}{arr_var} = stringp({str_var}) ? explode({str_var}, "\\n") - ({{ "" }}) : ({{ }});',
                        f"{indent}if (!sizeof({arr_var})) return 1;",
                    ]
                    end += 1
                    changes.append(f"{fname}:empty_guard")
                    break

        elif is_add:
            # Guard post-del `str = read_file(...); astr = explode(str, "\n");`
            # (or `v1 = read_file(...); v6 = explode(v1, "\n");`)
            idx = start
            while idx <= end:
                line = lines[idx]
                if line.lstrip().startswith("//"):
                    idx += 1
                    continue
                m_exp = re.match(
                    r'^([ \t]*)([A-Za-z_][A-Za-z0-9_]*)\s*=\s*explode\(\s*([A-Za-z_][A-Za-z0-9_]*)\s*,\s*"\\n"\s*\)\s*;\s*$',
                    line,
                )
                if m_exp and init_body_lines is not None:
                    indent, arr_var, str_var = m_exp.group(1), m_exp.group(2), m_exp.group(3)
                    prev_ctx = "\n".join(lines[max(start, idx - 5) : idx + 1])
                    next_ctx = "\n".join(lines[idx : min(end + 1, idx + 4)])
                    if (
                        ("topten_del" in prev_ctx or "top_del" in prev_ctx)
                        and f"stringp({str_var})" not in prev_ctx
                        and f"!sizeof({arr_var})" not in next_ctx
                    ):
                        # Re-indent init_body_lines cleanly to indent + "  " (or match unit)
                        body_indents = [
                            len(b) - len(b.lstrip(" \t"))
                            for b in init_body_lines
                            if b.strip()
                        ]
                        base_strip = min(body_indents) if body_indents else 0
                        step = "\t" if "\t" in indent else "  "
                        reindented = [
                            (indent + step + b[base_strip:]) if b.strip() else ""
                            for b in init_body_lines
                        ]
                        repl = [
                            f'{indent}{arr_var} = stringp({str_var}) ? explode({str_var}, "\\n") - ({{ "" }}) : ({{ }});',
                            f"{indent}if (!sizeof({arr_var})) {{",
                            *reindented,
                            f"{indent}}}",
                        ]
                        delta = len(repl) - 1
                        lines[idx : idx + 1] = repl
                        end += delta
                        idx += len(repl)
                        changes.append(f"{fname}:post_del_guard")
                        continue

                # Fix uncommented `sscanf(<arr>, "...;%*s", ...) != 3` / `< 3`
                # Split trailing // comment outside strings so `;%*s` in a comment
                # never alters code on the left (e.g. hhsj).
                code_part, sep, comment_part = line.partition("//")
                if ";%*s" in code_part and "sscanf(" in code_part:
                    new_code = code_part
                    if re.search(r"\bsscanf\(\s*astr\s*,", new_code):
                        new_code = re.sub(
                            r"\bsscanf\(\s*astr\s*,", "sscanf(astr[i],", new_code
                        )
                    elif re.search(r"\bsscanf\(\s*v6\s*,", new_code):
                        new_code = re.sub(
                            r"\bsscanf\(\s*v6\s*,", "sscanf(v6[v7],", new_code
                        )
                    # shenmo specific: `if (astr && sscanf(astr, "(%s)%d;%*s", id, data) != 2)`
                    if "if (astr && sscanf(" in new_code:
                        new_code = new_code.replace("if (astr && sscanf(", "if (sscanf(")
                    if '(%s)%d;%*s"' in new_code and re.search(r"!=\s*2\b", new_code):
                        new_code = re.sub(r"!=\s*2\b", "< 2", new_code)
                    elif (
                        re.search(r'%s[\(\[]%s[\]\)](?:%d|%s);%\*s"', new_code)
                        and re.search(r"!=\s*3\b", new_code)
                    ):
                        new_code = re.sub(r"!=\s*3\b", "< 3", new_code)

                    if new_code != code_part:
                        lines[idx] = new_code + sep + comment_part
                        changes.append(f"{fname}:sscanf")

                idx += 1

    if not changes:
        return text, []

    trailing = nl if text.endswith("\n") else ""
    return nl.join(lines) + trailing, changes


def iter_targets(slugs: list[str] | None) -> list[tuple[str, str]]:
    out: list[tuple[str, str]] = []
    for p in sorted(glob.glob("libs/*/work/adm/daemons/toptend.lpc")):
        slug = p.split("/")[1]
        if slugs and slug not in slugs:
            continue
        if slug in SKIP_NON_JACKYBOY:
            continue
        meta_path = f"libs/{slug}/meta.json"
        if not os.path.exists(meta_path):
            continue
        with open(meta_path, encoding="utf-8") as mf:
            meta = json.load(mf)
        if meta.get("hosting", "vendored") != "vendored":
            continue
        if meta.get("duplicate_of"):
            continue
        if meta.get("wasm_status") != "playable":
            continue
        out.append((slug, p))
    return out


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--apply", action="store_true", help="Write changes to disk")
    ap.add_argument("slugs", nargs="*", help="Optional subset of lib slugs")
    args = ap.parse_args()

    targets = iter_targets(args.slugs or None)
    modified = 0
    for slug, path in targets:
        raw = open(path, "rb").read()
        try:
            text = raw.decode("utf-8")
        except UnicodeDecodeError:
            print(f"SKIP non-UTF-8: {path}", file=sys.stderr)
            continue
        new_text, changes = fix_text(text)
        if not changes:
            continue
        modified += 1
        print(f"{'FIX' if args.apply else 'WOULD FIX'} {slug}: {', '.join(changes)}")
        if args.apply:
            with open(path, "wb") as f:
                f.write(new_text.encode("utf-8"))

    print(
        f"Summary: scanned={len(targets)} modified={modified} mode={'apply' if args.apply else 'dry-run'}"
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
