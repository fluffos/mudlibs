#!/usr/bin/env python3
"""KB 05 §7.11 / §7.44: toptend writes /data/topten or /topten without
mkdir/assure_file → enter_world raises *Wrong permissions (No such
file or directory) and the master prints the 臭虫 WARNING.

Classic JackyBoy shape only: topten_save(string f_name, ...) +
write_file. Skips save_object mapping daemons and /open/topten single-
file lists.

Usage: scripts/lpc_fix_topten_dir.py [SLUG...] [--apply] [--list]
"""
from __future__ import annotations

import argparse
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
CREATE_MARK = "mkdir("  # after apply, create body holds mkdir of topten dir


def nl_of(raw: bytes) -> str:
    return "\r\n" if b"\r\n" in raw else "\n"


def topten_dir(text: str) -> str | None:
    """Absolute mudlib dir the daemon writes into, or None if unknown."""
    # "/data/topten/rich.txt" / "/topten/rich.txt" (define or literal)
    m = re.search(
        r'#\s*define\s+TOPTEN_\w+\s+"((?:/data)?/topten)/[^"]+"',
        text,
    )
    if m:
        return m.group(1)
    m = re.search(r'"((?:/data)?/topten)/[^"]+"', text)
    if m:
        return m.group(1)
    # DATA_DIR + "topten/rich.txt"  or  DATA_DIR "topten/..."
    if re.search(
        r'(?:#\s*define\s+TOPTEN_\w+\s+)?DATA_DIR\s*(?:\+\s*)?"topten/',
        text,
    ):
        return 'DATA_DIR + "topten"'
    return None


def resolve_via_globals(slug: str, text: str) -> str | None:
    if "TOPTEN_RICH" not in text:
        return None
    for rel in (
        "work/include/globals.h",
        "work/include/mudlib.h",
        "work/include/topten.h",
    ):
        p = ROOT / "libs" / slug / rel
        if not p.exists():
            continue
        g = p.read_text(encoding="utf-8", errors="replace")
        m = re.search(
            r'#\s*define\s+TOPTEN_RICH\s+"((?:/data)?/topten)/[^"]+"',
            g,
        )
        if m:
            return m.group(1)
        if re.search(
            r'#\s*define\s+TOPTEN_RICH\s+DATA_DIR\s*(?:\+\s*)?"topten/',
            g,
        ):
            return 'DATA_DIR + "topten"'
    return None


def is_target(text: str) -> bool:
    if re.search(r'mkdir\s*\([^)]*topten', text):
        return False
    if "/open/topten" in text:
        return False
    # JackyBoy source, or decompiled mixed/arg signatures (topten_save /
    # top_save) that still write /topten/*.txt
    if not (
        re.search(r"\btopten_save\s*\(\s*(?:string|mixed)", text)
        or re.search(r"\btop_save\s*\(\s*(?:string|mixed)", text)
    ):
        return False
    if "write_file" not in text:
        return False
    return True


def insert_create(text: str, nl: str, mkdir_expr: str) -> str | None:
    if re.search(r"(?:protected\s+)?void\s+create\s*\(", text):
        return None  # unexpected for this class; skip rather than merge
    block = (
        f"//{nl}"
        f"// KB 05 §7.11: runtime topten dir is gitignored; mkdir so{nl}"
        f"// enter_world → topten_save write_file(..., 1) does not raise.{nl}"
        f"protected void create() {{{nl}"
        f"  seteuid(ROOT_UID);{nl}"
        f"  mkdir({mkdir_expr});{nl}"
        f"}}{nl}"
        f"{nl}"
    )
    # Prefer just before topten_checkplayer / first void/int function after decls
    for pat in (
        r"(void topten_checkplayer\s*\()",
        r"(int topten_save\s*\()",
        r"(string topten_query\s*\()",
    ):
        m = re.search(pat, text)
        if m:
            return text[: m.start()] + block + text[m.start() :]
    return None


def insert_assure(text: str, nl: str) -> tuple[str, bool]:
    if re.search(r"assure_file\s*\(\s*f_name\s*\)", text):
        return text, False
    # inside topten_save, before write_file(f_name, ...
    pat = re.compile(
        r"(int topten_save\s*\([^)]*\)\s*\{.*?)(if\s*\(\s*!?\s*write_file\s*\(\s*f_name)",
        re.S,
    )
    m = pat.search(text)
    if not m:
        # looser: any write_file(f_name in topten_save region
        pat2 = re.compile(
            r"(int topten_save\s*\([^)]*\)\s*\{.*?)((?:if\s*\(.*?)?write_file\s*\(\s*f_name)",
            re.S,
        )
        m = pat2.search(text)
        if not m:
            return text, False
    insert = f"assure_file(f_name);{nl}  "
    return text[: m.start(2)] + insert + text[m.start(2) :], True


def keep_rel(mkdir_expr: str) -> str | None:
    if mkdir_expr == 'DATA_DIR + "topten"':
        return "data/topten"
    if mkdir_expr == '"/data/topten"':
        return "data/topten"
    if mkdir_expr == '"/topten"':
        return "topten"
    return None


def process(slug: str, apply: bool) -> str:
    path = ROOT / "libs" / slug / "work/adm/daemons/toptend.lpc"
    if not path.exists():
        return f"SKIP {slug}: no toptend.lpc"
    raw = path.read_bytes()
    nl = nl_of(raw)
    text = raw.decode("utf-8")
    if not is_target(text):
        return f"SKIP {slug}: not JackyBoy topten_save target"
    d = topten_dir(text) or resolve_via_globals(slug, text)
    if not d:
        return f"SKIP {slug}: cannot resolve topten dir"
    mkdir_expr = d if d.startswith("DATA_DIR") else f'"{d}"'
    new = insert_create(text, nl, mkdir_expr)
    if new is None:
        return f"SKIP {slug}: already has create()"
    new, assured = insert_assure(new, nl)
    if new == text:
        return f"SKIP {slug}: no change"
    if apply:
        path.write_bytes(new.encode("utf-8"))
    note = f"OK {slug}: mkdir({mkdir_expr})" + (" +assure" if assured else " (assure already)")
    return note


def add_keep_dirs(entries: list[tuple[str, str]]) -> int:
    """Append missing slug\\trel lines; keep file sorted by slug then path."""
    kp = ROOT / "scripts/wasm_keep_dirs.txt"
    lines = kp.read_text(encoding="utf-8").splitlines(keepends=True)
    existing = set()
    body = []
    for ln in lines:
        if not ln.strip() or ln.startswith("#"):
            body.append(ln)
            continue
        parts = ln.rstrip("\n").rstrip("\r").split("\t", 1)
        if len(parts) == 2:
            existing.add((parts[0], parts[1]))
        body.append(ln)
    added = 0
    for slug, rel in entries:
        if (slug, rel) in existing:
            continue
        # insert after last line of same slug, else alpha by slug
        insert_at = None
        last_same = None
        for i, ln in enumerate(body):
            if ln.startswith("#") or not ln.strip():
                continue
            parts = ln.rstrip("\n").rstrip("\r").split("\t", 1)
            if len(parts) != 2:
                continue
            s, p = parts
            if s == slug:
                last_same = i
                if p > rel and insert_at is None:
                    insert_at = i
            elif s > slug and insert_at is None and last_same is None:
                insert_at = i
        if insert_at is None:
            insert_at = (last_same + 1) if last_same is not None else len(body)
        body.insert(insert_at, f"{slug}\t{rel}\n")
        existing.add((slug, rel))
        added += 1
    if added:
        kp.write_text("".join(body), encoding="utf-8")
    return added


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("slugs", nargs="*")
    ap.add_argument("--apply", action="store_true")
    ap.add_argument("--list", action="store_true")
    args = ap.parse_args()
    if args.slugs:
        slugs = args.slugs
    else:
        slugs = sorted(
            p.relative_to(ROOT / "libs").parts[0]
            for p in (ROOT / "libs").glob("*/work/adm/daemons/toptend.lpc")
        )
    results = []
    keeps: list[tuple[str, str]] = []
    for slug in slugs:
        path = ROOT / "libs" / slug / "work/adm/daemons/toptend.lpc"
        if not path.exists():
            continue
        raw = path.read_bytes()
        text = raw.decode("utf-8", errors="replace")
        if not is_target(text):
            if args.list:
                continue
            continue
        d = topten_dir(text) or resolve_via_globals(slug, text)
        if not d:
            results.append(f"SKIP {slug}: cannot resolve topten dir")
            continue
        if args.list:
            mkdir_expr = d if d.startswith("DATA_DIR") else f'"{d}"'
            print(f"{slug}\t{mkdir_expr}")
            continue
        msg = process(slug, args.apply)
        results.append(msg)
        if args.apply and msg.startswith("OK"):
            if d.startswith("DATA_DIR") or d == "/data/topten":
                keeps.append((slug, "data/topten"))
            elif d == "/topten":
                keeps.append((slug, "topten"))
    if args.list:
        return 0
    for r in results:
        print(r)
    ok = sum(1 for r in results if r.startswith("OK"))
    skip = sum(1 for r in results if r.startswith("SKIP"))
    print(f"summary: OK={ok} SKIP={skip}")
    if args.apply and keeps:
        n = add_keep_dirs(keeps)
        print(f"wasm_keep_dirs added={n}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
