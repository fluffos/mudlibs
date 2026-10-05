#!/usr/bin/env python3
"""scripts/lpc_case_paths.py [--apply] SLUG...

Paths the code names in one case and the archive stores in another (KB 03 section 5, KB 04 section 6.1).  The archives
come from Windows and DOS hosts that ignore case: files are stored as `BAMBOO1.C`, `d/SHAOLIN/`, `BAGUA.H`, `Mojie/`,
while the code says `__DIR__ "bamboo1"`, `"/d/shaolin/..."`, `#include "bagua.h"`.  On this driver (case-sensitive file
system) every such room, NPC, item and header is missing: the exit leads nowhere, `carry_object()` returns 0, the include
fails and takes the file with it.  The scan does not see it (a `.C` file is not an `.lpc` file) until the name is right.

What this does, per lib (gitlink libs are refused):
  1. lists the tracked files of work/ and the directories above them;
  2. reads every string literal of every `.lpc`/`.h`/`.C`/`.H` file (comments, here-documents and `#if 0` blocks are
     masked) that looks like a path -- `"/d/city/foo"`, `"d/city/foo.c"`, `__DIR__ "foo"`, `#include "x.h"` / `<x.h>` --
     and resolves it as the driver would: `foo` and `foo.c` mean `foo.lpc`, an include means that very file;
  3. a reference that does not resolve exactly but does when case (and, for objects, the `.C` / `.c` / `.LPC` extension)
     is ignored names a real path in the wrong case.  Every directory component and every file name with such a
     reference is renamed to lower case (`.C` -> `.lpc`, `.H` -> `.h`), and every reference to a path that moved --
     the wrong ones and the ones that were right in the old spelling -- is rewritten to the new spelling
     (`__DIR__ "x"` relative to the new directory);
  4. skips, and lists, a rename whose target already exists, a name that two renames would give the same target, a
     `.C` file that is not valid UTF-8 (convert it with iconv first), and a reference that two real paths could mean.

Without --apply it prints the plan; --convert also transcodes a GB18030 `.C`/`.H` file it renames (the archives
converted everything else already).  The moves are staged (`git add -A`, retried while another git process holds the index lock); edited files keep their line endings; paths that only some
other code names (a computed `"/d/" + zone + "/room"`) cannot be seen.  Run scripts/lpc_warnings.py afterwards: files that
were never loaded can show errors of their own, and the empty old directories are removed only when nothing is in them."""
import collections
import os
import re
import subprocess
import sys
import time

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from lpc_src import mask  # noqa: E402

args = sys.argv[1:]
apply_ = "--apply" in args
convert_ = "--convert" in args
list_path = None
if "--list" in args:
    i = args.index("--list")
    list_path = args[i + 1]
    del args[i:i + 2]
slugs = [a for a in args if not a.startswith("--")]
if not slugs:
    sys.exit(__doc__)

OBJ_EXT = (".lpc", ".LPC", ".c", ".C")
CODE_EXT = (".lpc", ".LPC", ".c", ".C", ".h", ".H")
PATH = re.compile(r"^/?[A-Za-z0-9_.~+-]+(?:/[A-Za-z0-9_.~+-]*)+$")
INC_ANGLE = re.compile(rb'^[ \t]*#[ \t]*include[ \t]*<([^>\n]+)>', re.M)


def git(*a):
    return subprocess.run(["git", "-c", "core.quotepath=false", "-C", REPO] + list(a), capture_output=True)


def gitlink(slug):
    out = git("ls-files", "-s", "--", f"libs/{slug}/work").stdout.decode("utf-8", "replace")
    return any(l.startswith("160000") for l in out.split("\n"))


def lower_ext(ext):
    return {".C": ".lpc", ".c": ".lpc", ".LPC": ".lpc", ".H": ".h"}.get(ext, ext)


def process(slug):
    if gitlink(slug):
        print(f"{slug}: work/ is a gitlink, not edited in place")
        return
    pre = f"libs/{slug}/work/"
    names = [n.decode("utf-8", "replace") for n in git("ls-files", "-z", "--", f"libs/{slug}/work").stdout.split(b"\0") if n]
    rels = sorted(n[len(pre):] for n in names if n.startswith(pre))
    P = set(rels)
    n_lpc = sum(1 for r in rels if r.endswith(".lpc"))
    n_c = sum(1 for r in rels if r.endswith(".c"))
    if n_c > n_lpc:
        print(f"{slug}: {n_c} `.c` files against {n_lpc} `.lpc`: the lib keeps its native extension, not edited")
        return
    D = set()
    for r in rels:
        d = os.path.dirname(r)
        while d and d not in D:
            D.add(d)
            d = os.path.dirname(d)
    ci = collections.defaultdict(set)         # lower path -> real paths (files and dirs)
    ci_obj = collections.defaultdict(set)     # lower path without object extension -> real object files
    for p in P | D:
        ci[p.lower()].add(p)
    for p in P:
        b, e = os.path.splitext(p)
        if e in OBJ_EXT:
            ci_obj[b.lower()].add(p)
    cfg = open(f"{REPO}/libs/{slug}/config.fluffos", errors="replace").read()
    m = re.search(r"include directories\s*:\s*(.*)", cfg)
    inc_dirs = [d.strip().strip("/") for d in m.group(1).split(":") if d.strip()] if m else ["include"]
    tops = {p.split("/")[0].lower() for p in P | D}

    def resolve_obj(p):
        """-> (real path, exact?) of an object reference (no leading slash), or None / 'ambiguous'"""
        stem = p[:-2] if p.endswith(".c") else (p[:-4] if p.endswith(".lpc") else p)
        if stem + ".lpc" in P:
            return stem + ".lpc", True
        if p in D:
            return p, True
        hit = ci_obj.get(stem.lower()) or ci.get(p.lower())
        if hit:
            return (next(iter(hit)), False) if len(hit) == 1 else "ambiguous"
        return None

    def resolve_file(p):
        if p in P:
            return p, True
        hit = ci.get(p.lower())
        if hit:
            return (next(iter(hit)), False) if len(hit) == 1 else "ambiguous"
        return None

    # ---- references: (file, start, end, kind, text, real path, exact)
    refs = []
    ambiguous = []
    texts = {}
    spans = {}
    for rel in rels:
        if os.path.splitext(rel)[1] not in CODE_EXT:
            continue
        try:
            raw = open(f"{REPO}/{pre}{rel}", "rb").read()
        except OSError:
            continue
        text = raw.decode("latin-1")
        texts[rel] = text
        mk = mask(text)
        d = os.path.dirname(rel)
        spans[rel] = [m_.span() for m_ in re.finditer(r'"[ ]*"', mk)]
        for lit in re.finditer(r'"[ ]*"', mk):
            a, b = lit.span()
            s = text[a + 1:b - 1]
            before = mk[:a].rstrip()
            if before.endswith("__DIR__"):
                kind, cand = "dir", s
                if not re.match(r"^[A-Za-z0-9_.~+/-]+$", s) or s.startswith("/"):
                    continue
                full = os.path.normpath((d + "/" if d else "") + s)
                r = resolve_obj(full)
            elif re.search(r"#[ \t]*include[ \t]*$", before):
                if not re.match(r"^[A-Za-z0-9_.~+/-]+$", s):
                    continue
                kind = "inc"
                paths = [os.path.normpath((d + "/" if d else "") + s)] + [os.path.normpath(i + "/" + s) for i in inc_dirs]
                if s.startswith("/"):
                    paths = [s.lstrip("/")]
                r = None
                for full in paths:
                    rr = resolve_file(full)
                    if rr == "ambiguous":
                        r = rr
                        break
                    if rr and rr[1]:          # an exact hit wins
                        r = rr
                        break
                    if rr and r is None:      # else the first hit that differs in case
                        r = rr
            else:
                if not PATH.match(s) or "/" not in s.strip("/"):
                    continue
                full = os.path.normpath(s.lstrip("/"))
                if full.split("/")[0].lower() not in tops:
                    continue
                kind = "abs"
                r = resolve_obj(full) if not s.endswith((".h", ".H", ".o")) else resolve_file(full)
            if r == "ambiguous":
                ambiguous.append((rel, s))
                continue
            if r:
                refs.append((rel, a + 1, b - 1, kind, s, r[0], r[1]))
        for mt in INC_ANGLE.finditer(raw):
            s = mt.group(1).decode("latin-1").strip()
            for i in inc_dirs:
                full = os.path.normpath(i + "/" + s)
                r = resolve_file(full)
                if r and r != "ambiguous":
                    refs.append((rel, mt.start(1), mt.end(1), "angle", s, r[0], r[1]))
                    if r[1]:
                        break
    # ---- which prefixes of which real paths get renamed: those a reference spells in another case
    def comps(path):
        return path.split("/")

    def strip_obj_ext(c):
        for e in OBJ_EXT:
            if c.endswith(e):
                return c[:-len(e)]
        return c

    def ref_path(rel, kind, s, real):
        d = os.path.dirname(rel)
        if kind == "dir":
            return os.path.normpath((d + "/" if d else "") + s)
        if kind in ("abs",):
            return os.path.normpath(s.lstrip("/"))
        cand = [os.path.normpath((d + "/" if d else "") + s)] + [os.path.normpath(i + "/" + s) for i in inc_dirs]
        if s.startswith("/"):
            cand = [os.path.normpath(s.lstrip("/"))]
        return next((c for c in cand if c.lower() == real.lower()), None)

    affected = set()          # real prefixes (as in the tree) whose last component changes
    for rel, a, b, kind, s, real, exact in refs:
        is_obj = kind in ("dir", "abs") and real in P and os.path.splitext(real)[1] in OBJ_EXT
        if kind == "angle":
            cand = [os.path.normpath(i + "/" + s) for i in inc_dirs]
            rp = next((c for c in cand if c.lower() == real.lower()), None)
        else:
            rp = ref_path(rel, kind, s, real)
        if rp is None:
            continue
        rc, pc = comps(real), comps(rp)
        if len(pc) != len(rc):
            continue
        for i in range(len(rc)):
            x, y = pc[i], rc[i]
            if i == len(rc) - 1 and is_obj:
                x, y = strip_obj_ext(x), strip_obj_ext(y)
            if x != y and x.lower() == y.lower():
                affected.add("/".join(rc[:i + 1]))
        if is_obj and os.path.splitext(real)[1] in (".C", ".c", ".LPC"):
            affected.add(real)

    def final_component(prefix_path, comp):
        if prefix_path in P:                      # a file
            base, e = os.path.splitext(comp)
            return base.lower() + lower_ext(e)
        return comp.lower()

    def final(path):
        cs = comps(path)
        out = []
        for i, c in enumerate(cs):
            pref = "/".join(cs[:i + 1])
            out.append(final_component(pref, c) if pref in affected else c)
        return "/".join(out)

    renames = {}
    for f in rels:
        nf = final(f)
        if nf != f:
            renames[f] = nf
    skipped = []
    conversions = []
    targets = collections.defaultdict(list)
    for f in rels:
        targets[renames.get(f, f)].append(f)
    for t, fs in list(targets.items()):
        if len(fs) > 1:
            for f in fs:
                if f in renames:
                    other = [x for x in fs if x != f][0]
                    skipped.append((f, f"target {t} is also the name of {other}"))
                    del renames[f]
    for f in list(renames):
        if os.path.splitext(f)[1] in (".C", ".H", ".LPC", ".c"):
            try:
                open(f"{REPO}/{pre}{f}", "rb").read().decode("utf-8")
            except UnicodeDecodeError:
                ok = False
                if convert_:
                    try:
                        open(f"{REPO}/{pre}{f}", "rb").read().decode("gb18030")
                        ok = True
                    except UnicodeDecodeError:
                        pass
                if ok:
                    conversions.append(f)
                else:
                    skipped.append((f, "not valid UTF-8 (--convert transcodes GB18030 files)"))
                    del renames[f]
            except OSError:
                pass

    kids_of = collections.defaultdict(list)
    for f in rels:
        d = os.path.dirname(f)
        while d:
            kids_of[d].append(f)
            d = os.path.dirname(d)

    def new_of(path):
        """where a real file or directory ends up (None when its files do not move together)"""
        if path in P:
            return renames.get(path, path)
        n = len(comps(path))
        outs = {"/".join(comps(renames.get(k, k))[:n]) for k in kids_of.get(path, [])}
        return outs.pop() if len(outs) == 1 else None

    # ---- reference rewrites: only the components that were renamed change; the rest of the literal stays as written
    def rewrite(lit, real):
        nf = new_of(real)
        if nf is None or nf == real:
            return lit
        oc, nc = comps(real), comps(nf)
        is_obj = real in P and os.path.splitext(real)[1] in OBJ_EXT
        toks = lit.split("/")
        out = list(toks)
        i, j = len(toks) - 1, len(oc) - 1
        first = True
        while i >= 0 and j >= 0:
            t = toks[i]
            if t in ("", "."):
                i -= 1
                continue
            if t == "..":
                break
            if oc[j] != nc[j]:
                if first and is_obj:
                    suffix = ".c" if t.endswith(".c") else (".lpc" if t.endswith(".lpc") else "")
                    out[i] = os.path.splitext(nc[j])[0] + suffix
                else:
                    out[i] = nc[j]
            first = False
            i -= 1
            j -= 1
        return "/".join(out)

    edits = collections.defaultdict(list)    # file -> [(a, b, new)]
    for rel, a, b, kind, s, real, exact in refs:
        new = rewrite(s, real)
        if new != s:
            edits[rel].append((a, b, new))
    nref = sum(len(v) for v in edits.values())
    print(f"{slug}: {len(rels)} files; {len(renames)} file(s) renamed, {nref} reference(s) rewritten in {len(edits)} file(s); "
          f"{len(skipped)} skipped, {len(ambiguous)} ambiguous reference(s)")
    # strings that still hold an old upper-case directory name as a path fragment: a computed path the scan cannot see
    old_dirs = set()
    for f, nf in renames.items():
        oc, nc = comps(f), comps(nf)
        for x, y in zip(oc[:-1], nc[:-1]):
            if x != y:
                old_dirs.add(x)
    frag = collections.Counter()
    frag_ex = {}
    if old_dirs:
        pat = re.compile(r"(?:^|/)(" + "|".join(re.escape(x) for x in sorted(old_dirs, key=len, reverse=True)) + r")(?:/|$)")
        edited_spans = {(rel, a) for rel, es in edits.items() for a, b, nw in es}
        for rel, sp in spans.items():
            text = texts[rel]
            for a, b in sp:
                if (rel, a + 1) in edited_spans:
                    continue
                lit = text[a + 1:b - 1]
                m_ = pat.search(lit)
                if m_:
                    frag[m_.group(1)] += 1
                    frag_ex.setdefault(m_.group(1), (rel, lit[:50]))
    if frag:
        print(f"   path fragments with an old upper-case directory name that stay as they are: {sum(frag.values())} "
              f"({', '.join(f'{k} x{v}' for k, v in frag.most_common(5))})")
        for k, (rel, lit) in list(frag_ex.items())[:3]:
            print(f"      e.g. {rel}: {lit!r}")
    if os.environ.get("DEBUG"):
        k = 0
        for rel, es in sorted(edits.items()):
            for a, b, nw in es:
                if k < int(os.environ["DEBUG"]):
                    print(f"   edit {rel}: {texts[rel][a:b]!r} -> {nw!r}")
                    k += 1
    shown = 0
    for f in sorted(renames):
        if shown < int(os.environ.get("SHOW", "6")):
            print(f"   mv {f} -> {renames[f]}")
            shown += 1
    for f, why in skipped[:8]:
        print(f"   skip {f}: {why}")
    for rel, s in ambiguous[:4]:
        print(f"   ambiguous {rel}: {s!r}")
    if list_path:
        # objects to load-check: the renamed objects (new and old name), the files that were edited and the files that
        # name a renamed path (they load a different object now)
        objs = set()
        for f, nf in renames.items():
            for x in (f, nf):
                if x.endswith(OBJ_EXT):
                    objs.add("/" + os.path.splitext(x)[0] + ".lpc")
        for rel in edits:
            if rel.endswith(OBJ_EXT):
                objs.add("/" + os.path.splitext(rel)[0] + ".lpc")
        for rel, a, b, kind, s_, real, exact in refs:
            if (real in renames or new_of(real) not in (None, real)) and rel.endswith(OBJ_EXT):
                objs.add("/" + os.path.splitext(rel)[0] + ".lpc")
        open(list_path, "w").write("\n".join(sorted(objs)) + "\n")
        print(f"   {len(objs)} object(s) to load-check written to {list_path}")
    if not apply_:
        return
    # ---- apply: edit contents (in memory, at the old path), then move
    for rel, es in edits.items():
        text = texts[rel]
        out = []
        pos = 0
        for a, b, new in sorted(es):
            out.append(text[pos:a])
            out.append(new)
            pos = b
        out.append(text[pos:])
        newtext = "".join(out)
        open(f"{REPO}/{pre}{rel}", "wb").write(newtext.encode("latin-1"))
    for f in conversions:
        fp = f"{REPO}/{pre}{f}"
        open(fp, "wb").write(open(fp, "rb").read().decode("gb18030").encode("utf-8"))
    moved = []
    for f, nf in sorted(renames.items(), key=lambda kv: kv[0]):
        src, dst = f"{REPO}/{pre}{f}", f"{REPO}/{pre}{nf}"
        if not os.path.exists(src):
            continue
        os.makedirs(os.path.dirname(dst), exist_ok=True)
        os.rename(src, dst)
        moved.append(f)
    # stage every move in a few git calls (a concurrent `git commit` holds .git/index.lock for a moment: retry)
    paths = [pre + f for f in moved] + [pre + renames[f] for f in moved]
    for i in range(0, len(paths), 300):
        for attempt in range(180):
            r = git("add", "-A", "--", *paths[i:i + 300])
            if r.returncode == 0 or b"index.lock" not in r.stderr:
                break
            time.sleep(1)
        if r.returncode:
            print(f"   git add failed: {r.stderr.decode('utf-8', 'replace').strip()[:150]}")
    # remove directories the moves emptied
    for d in sorted(D, key=lambda x: -x.count("/")):
        full = f"{REPO}/{pre}{d}"
        try:
            os.rmdir(full)
        except OSError:
            pass


for s in slugs:
    process(s)
