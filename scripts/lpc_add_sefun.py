#!/usr/bin/env python3
"""scripts/lpc_add_sefun.py NAME SLUG... [--apply]

A simulated efun a sibling lib has and this lib's sefun files never had (KB 06 section 7.262): the callers die with `Undefined function NAME`
(and `Invalid argument types to '+' ( string vs unknown )` on the lines that use its result).  NAME is one of

  space   `space(n)` -- a string of n blanks (with `itoa(n)`, which it uses).  The cover-drawing book base `/std/item/book.lpc` of the xkyx family
          (the 40 `/obj/book/*.lpc` of wqfy, zzfy and zzfy3 are byte for byte the ones xkyx3b ships) writes its cover with `space(4)`; the xkyx
          sefun file `string.lpc` holds `atoi`, `itoa` and `space`, the fy-family file `atoi.lpc` only the first.
  unew    `unew(file)`, `new()` that honours the "unique" limit (scripts/lpc_add_unew.py, kept for the nitan family's wave).
  tail    `tail(file)` -- the MudOS efun this driver does not have: the `tail` wizard command of 15 libs (`cmds/wiz/tail.lpc` calls `tail(file)`) does not
          compile without it (KB 06 section 7.291).  The compatible version of the Discworld family: the last 1080 bytes from the first full line, `write()`n;
          1 when the file is there, 0 otherwise.
  dump_socket_status
          `dump_socket_status()` -- the MudOS efun this driver does not have: the `socket` / `dumpsocket` wizard commands of 77 libs (`write(dump_socket_status());`)
          do not compile without it (KB 06 section 7.291).  Built from `socket_status()` under `#ifdef __PACKAGE_SOCKETS__` (the WASM build has no sockets: the
          table is just its header there, as in the Discworld stub).

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
DSS = '''
// dump_socket_status(): the MudOS efun is gone from this driver; the same table, built from socket_status()
// (a driver without the sockets package -- the WASM build -- has no sockets to list: the table is its header only)
string dump_socket_status() {
  string ret = sprintf("%-3s %-10s %-9s %-22s %s\\n", "Fd", "State", "Mode", "Local Address", "Remote Address");
#ifdef __PACKAGE_SOCKETS__
  {
    mixed *all = socket_status();
    int n;

    for (n = 0; n < sizeof(all); n++)
      if (arrayp(all[n]) && sizeof(all[n]) >= 5)
        ret += sprintf("%-3d %-10s %-9s %-22s %s\\n", all[n][0], all[n][1], all[n][2], all[n][3], all[n][4]);
  }
#endif
  return ret;
}
'''
TAIL = '''
// tail(file): the MudOS efun is gone from this driver; the same report (the last 20 lines or so of a file), as Discworld's compatible sefun
int tail(string fname) {
  int offset = file_size(fname);
  string str;

  if (offset < 0)
    return 0;
  offset -= 54 * 20;
  if (offset < 0)
    offset = 0;
  str = read_bytes(fname, offset, 1080);
  if (!str)
    return 0;
  if (offset)
    str = str[strsrch(str, "\\n") + 1..];
  write(str);
  return 1;
}
'''
DEF = {
    "space": re.compile(rb"(?m)^\s*(?:varargs\s+)?string\s+space\s*\("),
    "itoa": re.compile(rb"(?m)^\s*(?:varargs\s+)?string\s+itoa\s*\("),
    "tail": re.compile(rb"(?m)^\s*(?:varargs\s+)?(?:int|string|void|mixed)\s+tail\s*\("),
    "dump_socket_status": re.compile(rb"(?m)^\s*(?:varargs\s+)?string\s+dump_socket_status\s*\("),
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
    if len(pos) < 2 or pos[0] not in ("space", "unew", "dump_socket_status", "tail"):
        print(__doc__)
        return
    name, slugs = pos[0], pos[1:]
    if name == "unew":
        os.execv(sys.executable, [sys.executable, os.path.join(os.path.dirname(os.path.abspath(__file__)), "lpc_add_unew.py")] + slugs + (["--apply"] if apply else []))
    if name in ("dump_socket_status", "tail"):
        TEXT = DSS if name == "dump_socket_status" else TAIL
        for slug in slugs:
            files = sefun_files(slug)
            if not files:
                print(f"SKIP  {slug}: no simulated efun file found")
                continue
            texts = {f: open(f, "rb").read() for f in files}
            have = next((f for f, t in texts.items() if DEF[name].search(t)), None)
            if have:
                print(f"SKIP  {slug}: {name}() is defined in /{os.path.relpath(have, REPO + '/libs/' + slug + '/work')}")
                continue
            tgt = U.target(slug)
            if not tgt:
                print(f"SKIP  {slug}: nowhere to put it")
                continue
            text = open(tgt, "rb").read()
            eol = b"\r\n" if b"\r\n" in text else b"\n"
            add = TEXT.encode("utf-8").replace(b"\n", eol)
            if not text.endswith(b"\n"):
                text += eol
            print(f"ADD   {slug}: {name}() -> /{os.path.relpath(tgt, REPO + '/libs/' + slug + '/work')}")
            if apply:
                open(tgt, "wb").write(text + add)
        return
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
