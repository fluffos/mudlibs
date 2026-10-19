#!/usr/bin/env python3
"""scripts/lpc_add_sefun.py NAME SLUG... [--apply]

A simulated efun a sibling lib has and this lib's sefun files never had (KB 06 section 7.262): the callers die with `Undefined function NAME`
(and `Invalid argument types to '+' ( string vs unknown )` on the lines that use its result).  NAME is one of

  space   `space(n)` -- a string of n blanks (with `itoa(n)`, which it uses).  The cover-drawing book base `/std/item/book.lpc` of the xkyx family
          (the 40 `/obj/book/*.lpc` of wqfy, zzfy and zzfy3 are byte for byte the ones xkyx3b ships) writes its cover with `space(4)`; the xkyx
          sefun file `string.lpc` holds `atoi`, `itoa` and `space`, the fy-family file `atoi.lpc` only the first.
  unew    `unew(file)`, `new()` that honours the "unique" limit (scripts/lpc_add_unew.py, kept for the nitan family's wave).

`space` is appended to the sefun file that already defines `atoi` (the simulated efun object's own includes are searched), else to the
`object.lpc` of the sefun directory or the single sefun file, like unew.  A lib that defines the name already is skipped.
Binary-safe, line endings of the target kept; without --apply the plan is printed.  Idempotent."""
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import lpc_add_unew as U  # noqa: E402

REPO = U.REPO
SPACE = '''
// 将数字转换成字符串
string itoa(int n) {
  return sprintf("%d", n);
}

// 返回规定的空格数
string space(int n) {
  return sprintf("%" + itoa(n) + "s", "");
}
'''
DEF = {
    "space": re.compile(rb"(?m)^\s*(?:varargs\s+)?string\s+space\s*\("),
    "itoa": re.compile(rb"(?m)^\s*(?:varargs\s+)?string\s+itoa\s*\("),
}


def sefun_files(slug):
    """the files of the simulated efun object: the object itself and what it #includes (quoted absolute paths)"""
    cfg = open(f"{REPO}/libs/{slug}/config.fluffos", encoding="utf-8", errors="replace").read()
    m = re.search(r"(?m)^simulated efun file\s*:\s*(\S+)", cfg)
    if not m:
        return []
    base = f"{REPO}/libs/{slug}/work"
    p = m.group(1)
    f = base + (p if p.endswith(".lpc") else p + ".lpc")
    out = []
    if os.path.exists(f):
        out.append(f)
        for inc in re.findall(rb'(?m)^\s*#\s*include\s+"(/[^"\n]+)"', open(f, "rb").read()):
            q = base + inc.decode("utf-8", "replace")
            if os.path.exists(q):
                out.append(q)
    d = base + p
    if os.path.isdir(d):
        out += [os.path.join(d, x) for x in sorted(os.listdir(d)) if x.endswith(".lpc")]
    return out


def main():
    args = sys.argv[1:]
    apply = "--apply" in args
    pos = [a for a in args if not a.startswith("--")]
    if len(pos) < 2 or pos[0] not in ("space", "unew"):
        print(__doc__)
        return
    name, slugs = pos[0], pos[1:]
    if name == "unew":
        os.execv(sys.executable, [sys.executable, os.path.join(os.path.dirname(os.path.abspath(__file__)), "lpc_add_unew.py")] + slugs + (["--apply"] if apply else []))
    for slug in slugs:
        files = sefun_files(slug)
        if not files:
            print(f"SKIP  {slug}: no simulated efun file found")
            continue
        texts = {f: open(f, "rb").read() for f in files}
        have = {n: next((f for f, t in texts.items() if rx.search(t)), None) for n, rx in DEF.items()}
        if have["space"]:
            print(f"SKIP  {slug}: space() is defined in /{os.path.relpath(have['space'], REPO + '/libs/' + slug + '/work')}")
            continue
        tgt = next((f for f, t in texts.items() if re.search(rb"(?m)^\s*(?:varargs\s+)?int\s+atoi\s*\(", t) and f.endswith(".lpc")), None)
        if not tgt:
            tgt = U.target(slug)
        if not tgt:
            print(f"SKIP  {slug}: nowhere to put it")
            continue
        text = open(tgt, "rb").read()
        body = SPACE
        if have["itoa"]:      # keep the lib's own itoa(): drop ours
            body = body.split("// 返回规定的空格数")[1]
            body = "\n// 返回规定的空格数" + body
        eol = b"\r\n" if b"\r\n" in text else b"\n"
        add = body.encode("utf-8").replace(b"\n", eol)
        if not text.endswith(b"\n"):
            text += eol
        print(f"ADD   {slug}: space()" + ("" if have["itoa"] else " + itoa()") + f" -> /{os.path.relpath(tgt, REPO + '/libs/' + slug + '/work')}")
        if apply:
            open(tgt, "wb").write(text + add)


if __name__ == "__main__":
    main()
