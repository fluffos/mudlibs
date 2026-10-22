#!/usr/bin/env python3
"""scripts/lpc_daemon_call_plan.py triage ROWS.tsv... [--out PAIRS.tsv]
scripts/lpc_daemon_call_plan.py plan PAIRS.tsv ROWS.tsv... [--rank N] [--out PLAN.tsv]

The two steps between scripts/lpc_scan_daemon_calls.py (ROWS: `DAPI<TAB>slug<TAB>MACRO<TAB>daemon<TAB>func<TAB>nsites<TAB>file:line<TAB>kind`) and scripts/lpc_port_function.py
(PLAN: `daemon<TAB>func<TAB>target<TAB>PORT|NEED ...<TAB>donor`), KB 06 section 7.354.

`triage` groups the rows by (daemon path, function): the libs that call it, the libs whose copy of that daemon DOES define it (the donors), and whether the first call site uses the
result.  PAIRS.tsv is sorted by rank: 0 result used and a donor exists, 1 a donor exists (statement call), 2 result used and no donor, 3 the rest.  A pair with a donor is a function
one lineage has and the other lacks; without a donor the callers expect a function that nobody ships (a rename, a lost feature, an optional hook).

`plan` takes the pairs of rank <= N (default 1) and decides per (calling lib, function) whether the donor's definition can be copied into that lib's daemon: PORT when every function
the body calls, every global it names and every macro it uses is present in the target (a macro whose header the daemon does not include is NEED MACRO NAME(header)), every string
literal it compares or indexes with (a mapping key, a state name) occurs in the target daemon's source (the data shape matches), and the call sites in the target pass as many arguments
as the donor's function takes (`chinese_time(type, str)` of one lineage is not `chinese_time(seconds)` of another: 36 of 47 libs); anything else is NEED FN / GLOBAL / MACRO / UNK with
what is missing.  A PORT row is a candidate, not a proof: read the function (a getter or a formatter is safe, a function that changes state is a design question) and prove it live."""
import collections
import os
import re
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import lpc_scan_callout_targets as S  # noqa: E402
from lpc_fix_void_return import code_mask  # noqa: E402
from lpc_port_function import extract  # noqa: E402

_libs = {}
KW = set(b"if else while for foreach switch case default return break continue do in catch sizeof void int string object mixed mapping float status buffer function class varargs nomask private protected public static nosave inherit new ref".split())
IDENT = re.compile(rb"(?<![A-Za-z0-9_\"'.>])([A-Za-z_]\w*)")


def lib(slug):
    if slug not in _libs:
        _libs[slug] = S.Lib(slug)
    return _libs[slug]


def read_rows(files):
    rows = []
    for fn in files:
        for ln in open(fn, encoding="utf-8", errors="replace"):
            if ln.startswith("DAPI\t"):
                f = ln.rstrip("\n").split("\t")
                if len(f) >= 8:
                    rows.append(f)
    return rows


def all_libs():
    return sorted(d for d in os.listdir(os.path.join(REPO, "libs")) if os.path.isdir(os.path.join(REPO, "libs", d, "work")) and d not in S.GITLINKS)


def used(slug, site):
    f, line = site.rsplit(":", 1)
    try:
        t = lib(slug).read(f).split(b"\n")[int(line) - 1].decode("utf-8", "replace")
    except Exception:
        return "?"
    m = re.search(r"[A-Z][A-Z0-9_]*\s*->", t)
    pre = t[:m.start()].strip() if m else t.strip()
    return "stmt" if re.fullmatch(r"(?:else\s*)?[{}]?", pre) else "value"


def triage(files, out):
    rows = read_rows(files)
    pairs = collections.defaultdict(lambda: {"libs": {}, "kinds": set()})
    for _, slug, macro, daemon, fn, n, site, kind in rows:
        d = pairs[(daemon, fn)]
        d["libs"][slug] = (int(n), site)
        d["kinds"].add(kind)
    need = collections.defaultdict(set)
    for daemon, fn in pairs:
        need[daemon].add(fn)
    donors = collections.defaultdict(set)
    for slug in all_libs():
        files_ = subprocess.run(["git", "ls-files", "-z", "--", f"libs/{slug}/work"], cwd=REPO, capture_output=True).stdout
        have = {d for d in need if f"libs/{slug}/work{d}".encode() in files_}
        if not have:
            continue
        L = lib(slug)
        for d in have:
            try:
                vis, _, _ = L.all_defs(d)
            except Exception:
                continue
            for fn in need[d]:
                if fn.encode() in vis:
                    donors[(d, fn)].add(slug)
    res = []
    for (daemon, fn), d in pairs.items():
        first = next(iter(d["libs"].items()))
        u = used(first[0], first[1][1])
        dn = sorted(donors.get((daemon, fn), []))
        rank = 0 if (u == "value" and dn) else 1 if dn else 2 if u == "value" else 3
        res.append((rank, daemon, fn, len(d["libs"]), sum(v[0] for v in d["libs"].values()), u, ",".join(sorted(d["libs"])[:6]), ",".join(dn[:6]), first[0] + ":" + first[1][1], ",".join(sorted(d["kinds"]))))
    res.sort(key=lambda r: (r[0], -r[3], r[1], r[2]))
    with open(out, "w", encoding="utf-8") as f:
        f.write("rank\tdaemon\tfunc\tnlibs\tnsites\tused\tlibs\tdonors\tfirst\tkinds\n")
        for r in res:
            f.write("\t".join(str(x) for x in r) + "\n")
    print(f"{len(res)} pairs", dict(collections.Counter(r[0] for r in res)))


def deps(text):
    mask = code_mask(text, heredoc=True)
    header_end = text.index(b"{")
    declared, called, plain = set(), set(), set()
    for m in re.finditer(rb"\b(?:void|int|string|object|mixed|mapping|float|status|buffer|function)\b[ \t]*\**[ \t]*([A-Za-z_]\w*(?:[ \t]*(?:\[[^\]]*\])?[ \t]*(?:=[^,;()]*)?[ \t]*,[ \t]*\**[ \t]*[A-Za-z_]\w*)*)", text):
        declared |= set(re.findall(rb"[A-Za-z_]\w*", m.group(1)))
    for m in IDENT.finditer(text):
        if not mask[m.start()]:
            continue
        n = m.group(1)
        if n in KW or (m.start() < header_end and re.match(rb"[ \t\r\n]*\(", text[m.end():])):
            continue
        if n in declared:
            continue
        (called if text[m.end():m.end() + 40].lstrip().startswith(b"(") else plain).add(n)
    return called, plain


def efun_names():
    names = set()
    for base in (os.path.expanduser("~/src/fluffos/docs/efun"),):
        for dp, dn, fn in os.walk(base):
            names |= {f[:-3] for f in fn if f.endswith(".md")}
    return names | {"new", "clone_object", "load_object", "find_object", "this_player", "this_object", "environment", "present"}


def macros_of(slug, cache={}):
    if slug not in cache:
        d = {}
        L = lib(slug)
        for f in sorted(L.files):
            if f.endswith(".h") and not S.SKIP.search(f):
                for m in re.finditer(rb"(?m)^[ \t]*#[ \t]*define[ \t]+([A-Za-z_]\w*)", L.read(f)):
                    d.setdefault(m.group(1).decode(), os.path.basename(f))
        cache[slug] = d
    return cache[slug]


def sefuns_of(slug, cache={}):
    if slug not in cache:
        names = set()
        L = lib(slug)
        try:
            for ln in open(f"{REPO}/libs/{slug}/config.fluffos", encoding="utf-8", errors="replace"):
                m = re.match(r"\s*simulated efun file\s*:\s*(\S+)", ln)
                if m:
                    f = L.real("/" + m.group(1).lstrip("/"))
                    if f:
                        names |= L.all_defs(f)[0]
        except OSError:
            pass
        cache[slug] = names
    return cache[slug]


def call_arity(slug, site, macro, fn):
    try:
        f, line = site.rsplit(":", 1)
        lines = lib(slug).read(f).split(b"\n")
        text = b"\n".join(lines[int(line) - 1:int(line) + 3])
        m = re.search(re.escape(macro.encode()) + rb"\s*->\s*" + re.escape(fn.encode()) + rb"\s*\(", text)
        if not m:
            return None
        i, depth, n, any_, q = m.end(), 1, 0, False, None
        while i < len(text) and depth:
            c = text[i:i + 1]
            if q:
                if c == b"\\":
                    i += 1
                elif c == q:
                    q = None
            elif c in (b'"', b"'"):
                q, any_ = c, True
            elif c in b"([{":
                depth, any_ = depth + 1, True
            elif c in b")]}":
                depth -= 1
            elif c == b"," and depth == 1:
                n += 1
            elif not c.isspace():
                any_ = True
            i += 1
        return n + 1 if any_ else 0
    except Exception:
        return None


def param_count(text):
    head = text[:text.index(b"{")]
    inner = head[head.index(b"(") + 1:head.rindex(b")")].strip()
    var = b"varargs" in head[:head.index(b"(")]
    if not inner or inner == b"void":
        return 0, var
    depth, n = 0, 1
    for c in inner:
        if c in b"([{":
            depth += 1
        elif c in b")]}":
            depth -= 1
        elif c == 0x2C and depth == 0:
            n += 1
    return n, var


def global_re(name):
    return re.compile(rb"(?m)^[ \t]*(?:(?:nosave|static|private|protected|public|varargs)[ \t]+)*(?:int|string|object|mixed|mapping|float|status|function)[ \t]*\**[ \t]*(?:[A-Za-z_]\w*[ \t]*(?:=[^;]*)?,[ \t]*\**[ \t]*)*" + re.escape(name) + rb"\b")


def plan(pairs_file, rows_files, maxrank, out):
    rows = read_rows(rows_files)
    targets = collections.defaultdict(set)
    sites = {}
    for _, slug, macro, daemon, fn, n, site, kind in rows:
        targets[(daemon, fn)].add(slug)
        sites[(daemon, fn, slug)] = (site, macro)
    efuns = efun_names()
    counts = collections.Counter()
    with open(out, "w", encoding="utf-8") as o:
        for ln in open(pairs_file, encoding="utf-8"):
            f = ln.rstrip("\n").split("\t")
            if f[0] == "rank" or int(f[0]) > maxrank:
                continue
            daemon, fn, donors = f[1], f[2], f[7].split(",") if f[7] else []
            text = donor = dbytes = None
            for d in donors:
                b = lib(d).read(daemon)
                r = extract(b, fn) if b else None
                if r:
                    text, donor, dbytes = r[2], d, b
                    break
            if text is None:
                o.write(f"{daemon}\t{fn}\t-\tNOTEXT\t\n")
                counts["NOTEXT"] += 1
                continue
            called, plain = deps(text)
            dvis = lib(donor).all_defs(daemon)[0]
            for t in sorted(targets[(daemon, fn)]):
                L = lib(t)
                tb = L.read(daemon)
                if not tb:
                    continue
                vis = L.all_defs(daemon)[0]
                sef = sefuns_of(t)
                need_fn, need_glob, need_mac, unk = [], [], [], []
                for c in sorted(called):
                    if c in vis or c in sef:
                        continue
                    if c in dvis:
                        need_fn.append(c.decode())
                    elif c.decode() not in efuns:
                        unk.append(c.decode())
                am = macros_of(t)
                for p in sorted(plain):
                    ps = p.decode()
                    if ps in efuns:
                        continue
                    if global_re(p).search(dbytes):
                        if not global_re(p).search(tb):
                            need_glob.append(ps)
                    elif ps in am:
                        if not re.search(rb'#[ \t]*include[ \t]+[<"][^>"\n]*' + re.escape(am[ps].encode()) + rb'[>"]', tb):
                            need_mac.append(f"{ps}({am[ps]})")
                    elif re.fullmatch(r"[A-Z_][A-Z0-9_]*", ps):
                        need_mac.append(ps)
                    else:
                        unk.append(ps)
                strs = sorted({m.group(1).decode("utf-8", "replace") for m in re.finditer(rb'"((?:[^"\\\n]|\\.)+)"', text)
                               if len(m.group(1)) >= 3 and m.group(1) not in tb and re.fullmatch(rb"[A-Za-z_][A-Za-z_0-9 ]*", m.group(1))})
                if strs:
                    unk.append("STR " + "/".join(strs[:3]))
                site = sites.get((daemon, fn, t))
                if site:
                    ca = call_arity(t, site[0], site[1], fn)
                    npar, var = param_count(text)
                    if ca is not None and not (ca == npar or (ca < npar and var)):
                        unk.append(f"ARGS call={ca} def={npar}")
                if need_fn or need_glob or need_mac or unk:
                    v = "NEED " + ";".join(x for x in (("FN " + ",".join(need_fn)) if need_fn else "", ("GLOBAL " + ",".join(need_glob)) if need_glob else "",
                                                         ("MACRO " + ",".join(need_mac)) if need_mac else "", ("UNK " + ",".join(unk[:4])) if unk else "") if x)
                    counts["NEED"] += 1
                else:
                    v = "PORT"
                    counts["PORT"] += 1
                o.write(f"{daemon}\t{fn}\t{t}\t{v}\t{donor}\n")
    print(dict(counts))


def main():
    argv = sys.argv[1:]
    if not argv or argv[0] not in ("triage", "plan"):
        sys.exit(__doc__)
    out = argv[argv.index("--out") + 1] if "--out" in argv else None
    maxrank = int(argv[argv.index("--rank") + 1]) if "--rank" in argv else 1
    rest = [a for i, a in enumerate(argv[1:], 1) if not a.startswith("--") and (i < 2 or argv[i - 1] not in ("--out", "--rank"))]
    scratch = os.environ.get("LPC_SCRATCH") or os.path.expanduser("~/.cache/lpc-scratch")
    os.makedirs(os.path.join(scratch, "daemon_calls"), exist_ok=True)
    if argv[0] == "triage":
        triage(rest, out or os.path.join(scratch, "daemon_calls", "pairs.tsv"))
    else:
        plan(rest[0], rest[1:], maxrank, out or os.path.join(scratch, "daemon_calls", "plan.tsv"))


if __name__ == "__main__":
    main()
