#!/usr/bin/env python3
"""Port the fixes made in one lib to a sibling whose files carry the same code (KB 08 section 10.13).

  scripts/lpc_twin_port.py classify SRC DST --pre REV [--out FILE]
  scripts/lpc_twin_port.py adopt    SRC DST --pre REV [--apply] [--only SUBSTR ...]
  scripts/lpc_twin_port.py audit    SRC DST --pre REV [--only PATH ...]
  scripts/lpc_twin_port.py tokdiff  A B [--context N] [--stats]

SRC is the lib that was fixed (its work tree now), REV the commit before that fix; DST is the sibling, taken as it
is in HEAD.  Paths are relative to libs/<slug>/work.  Set TWIN_DST_TREE=<dir> to take (and write) DST's files from a
directory with the same relative layout instead of libs/<dst>/work -- a submodule lib's tree, e.g. the flattened
scratch tree of scripts/submodule_patch_scratch.py.  A token stream is the file's code without whitespace and
comments (strings and directives intact), so two files "carry the same code" when their streams are equal.

classify  every file SRC changed since REV -> `twin` (DST's tokens equal SRC's pre-fix tokens: the fix applies
          verbatim), `differs` (DST has its own code there) or `absent` (DST has no such file).
adopt     for the `twin` files, make DST's file equal SRC's fixed one.  When DST is the corpus formatter's output of
          the same sources (format(SRC pre) == DST byte for byte, checked per file) the new file is format(SRC post), so
          it stays formatted; when DST == SRC pre byte for byte it is SRC post as is.  Otherwise (same code, own
          whitespace or comments) the token edits SRC made are spliced into DST's text, so everything outside the
          edited spans keeps DST's style; a splice whose result does not have SRC post's tokens is SKIPPED, never
          written.  Without --apply it only prints what would change.
audit     for the `differs` files: token hunks SRC's pass made that DST does not have (a fuzzy or hand port left them
          out), and differences between the two libs that the port removed.  Empty output = the port is complete.
tokdiff   token-level diff of two files, blind to whitespace/comments/line breaks.

After `adopt --apply`, run scripts/lpc_warnings.py DST: the compile warnings that depend on a lib's other files
(inherit overlaps) are not carried by file identity and show up there.
"""
import difflib
import os
import re
import shutil
import subprocess
import sys
import tempfile
from collections import Counter

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
DST_TREE = os.environ.get("TWIN_DST_TREE")


def dst_path(dst, p):
    return os.path.join(DST_TREE or os.path.join(ROOT, "libs", dst, "work"), p)
FORMATTER = os.path.expanduser("~/src/fluffos/tools/lpc-syntax/bin/format-corpus.mjs")
TOK = re.compile(r'''
    //[^\n]*|/\*.*?\*/|"(?:\\.|[^"\\])*"|'(?:\\.|[^'\\])+'|@\w+|[A-Za-z_]\w*|0[xX][0-9a-fA-F]+|\d+\.\d*|\d+
    |\(:|:\)|\(\[|\]\)|\(\{|\}\)|->|\+\+|--|<<=|>>=|\.\.\.|\.\.|<<|>>|<=|>=|==|!=|&&|\|\||[-+*/%&|^]=|::|[^\s]
''', re.S | re.X)


def toks(data):
    return [m.group(0) for m in TOK.finditer(data.decode("utf-8", "replace"))
            if not (m.group(0).startswith("//") or m.group(0).startswith("/*"))]


def spans(data):
    """(latin-1 text, [(token, start, end)]) -- offsets are byte offsets; comments are not tokens"""
    text = data.decode("latin-1")
    return text, [(m.group(0), m.start(), m.end()) for m in TOK.finditer(text)
                  if not (m.group(0).startswith("//") or m.group(0).startswith("/*"))]


def splice(pre, post, dst):
    """Apply the token edits that turn `pre` into `post` to `dst` (whose tokens equal pre's), keeping dst's text
    outside the edited spans.  Returns bytes, or None when dst is not a token twin of pre or the result is wrong."""
    tp_text, tp = spans(pre)
    tq_text, tq = spans(post)
    td_text, td = spans(dst)
    a, b = [t[0] for t in tp], [t[0] for t in tq]
    if a != [t[0] for t in td]:
        return None
    edits = []
    for tag, i1, i2, j1, j2 in difflib.SequenceMatcher(None, a, b, autojunk=False).get_opcodes():
        if tag == "equal":
            continue
        snippet = tq_text[tq[j1][1]:tq[j2 - 1][2]] if j2 > j1 else ""
        if i2 > i1:
            start, end = td[i1][1], td[i2 - 1][2]
            if j2 == j1:                                   # a deletion: take the blank line with it
                s0, e0 = start, end
                while s0 > 0 and td_text[s0 - 1] in " \t":
                    s0 -= 1
                while e0 < len(td_text) and td_text[e0] in " \t":
                    e0 += 1
                if (s0 == 0 or td_text[s0 - 1] == "\n") and (e0 >= len(td_text) or td_text[e0] in "\r\n"):
                    start, end = s0, e0 + (2 if td_text[e0:e0 + 2] == "\r\n" else 1 if e0 < len(td_text) else 0)
            edits.append((start, end, snippet))
        else:                                              # an insertion after the previous token
            pos = td[i1 - 1][2] if i1 > 0 else 0
            gap = tq_text[tq[j1 - 1][2]:tq[j1][1]] if j1 > 0 and j1 < len(tq) else " "
            sep = ("\n" + gap.rsplit("\n", 1)[1]) if "\n" in gap else " "
            edits.append((pos, pos, sep + snippet))
    out = td_text
    for start, end, rep in sorted(edits, reverse=True):
        out = out[:start] + rep + out[end:]
    result = out.encode("latin-1")
    return result if [t[0] for t in spans(result)[1]] == b else None


def show(rev_path):
    r = subprocess.run(["git", "show", rev_path], cwd=ROOT, capture_output=True)
    return r.stdout if r.returncode == 0 else None


def read(path):
    return open(path, "rb").read() if os.path.exists(path) else None


def hunks(a, b):
    sm = difflib.SequenceMatcher(None, a, b, autojunk=False)
    return [(tuple(a[i1:i2]), tuple(b[j1:j2]), i1, j1) for tag, i1, i2, j1, j2 in sm.get_opcodes() if tag != "equal"]


def changed_paths(src, pre):
    out = subprocess.run(["git", "diff", "--name-only", pre, "--", f"libs/{src}/work"], cwd=ROOT,
                         capture_output=True, text=True).stdout.split("\n")
    pref = f"libs/{src}/work/"
    return [n[len(pref):] for n in out if n.startswith(pref)]


def sides(src, dst, pre, p):
    """(src_pre, src_post, dst_head) bytes or None"""
    return (show(f"{pre}:libs/{src}/work/{p}"), read(os.path.join(ROOT, "libs", src, "work", p)),
            read(dst_path(dst, p)) if DST_TREE else show(f"HEAD:libs/{dst}/work/{p}"))


def classify(src, dst, pre):
    rows = []
    for p in changed_paths(src, pre):
        sp, so, dh = sides(src, dst, pre, p)
        if sp is None or so is None:
            rows.append((p, "new-or-deleted"))
        elif dh is None:
            rows.append((p, "absent"))
        else:
            rows.append((p, "twin" if toks(sp) == toks(dh) else "differs"))
    return rows


def run_formatter(paths):
    r = subprocess.run(["node", FORMATTER], input="\n".join(paths) + "\n", capture_output=True, text=True)
    refused = set()
    for line in r.stderr.splitlines():
        m = re.search(r"(?:ERROR|MISMATCH, refusing to write)[^/]*?(/\S+?)(?::|$)", line)
        if m:
            refused.add(m.group(1))
    return refused


def cmd_classify(a):
    rows = classify(a.src, a.dst, a.pre)
    c = Counter(r[1] for r in rows)
    print(dict(c))
    if a.out:
        open(a.out, "w").write("\n".join("\t".join(r) for r in rows) + "\n")
    else:
        for r in rows:
            print("\t".join(r))


def cmd_adopt(a):
    rows = [r for r in classify(a.src, a.dst, a.pre) if r[1] == "twin"]
    if a.only:
        rows = [r for r in rows if any(o in r[0] for o in a.only)]
    tmp = tempfile.mkdtemp(prefix="twin-")
    todo = []
    for p, _ in rows:
        sp, so, dh = sides(a.src, a.dst, a.pre, p)
        for tag, data in (("pre", sp), ("post", so)):
            f = os.path.join(tmp, tag, p)
            os.makedirs(os.path.dirname(f), exist_ok=True)
            open(f, "wb").write(data)
        todo.append((p, sp, so, dh))
    refused = run_formatter([os.path.join(tmp, t, p) for p, *_ in todo for t in ("pre", "post")])
    n = Counter()
    for p, sp, so, dh in todo:
        fpre = read(os.path.join(tmp, "pre", p))
        fpost = read(os.path.join(tmp, "post", p))
        refused_any = os.path.join(tmp, "pre", p) in refused or os.path.join(tmp, "post", p) in refused
        if not refused_any and fpre == dh and toks(fpost) == toks(so):
            new, how = fpost, "format"
        elif sp == dh:
            new, how = so, "raw"
        else:
            new = splice(sp, so, dh)
            how = "splice" if new is not None else "SKIPPED"
        dst_file = dst_path(a.dst, p)
        cur = read(dst_file)
        n[how] += 1
        if how == "SKIPPED" or cur != new:
            print(f"{how:10s} {'same' if cur == new else 'changes':8s} {p}")
        if a.apply and new is not None and cur != new:
            open(dst_file, "wb").write(new)
    shutil.rmtree(tmp, ignore_errors=True)
    print(dict(n), "applied" if a.apply else "dry run (use --apply)")


def cmd_audit(a):
    rows = [r for r in classify(a.src, a.dst, a.pre) if r[1] == "differs"]
    if a.only:
        rows = [r for r in rows if r[0] in a.only]
    for p, _ in rows:
        sp, so, dh = sides(a.src, a.dst, a.pre, p)
        dc = read(dst_path(a.dst, p))
        tpre, tpost, thead, tcur = toks(sp), toks(so), toks(dh), toks(dc)
        d0, d1 = hunks(tpre, thead), hunks(tpost, tcur)
        c0 = Counter((h[0], h[1]) for h in d0)
        c1 = Counter((h[0], h[1]) for h in d1)
        only1 = [h for h in d1 if c1[(h[0], h[1])] > c0.get((h[0], h[1]), 0)]
        only0 = [h for h in d0 if c0[(h[0], h[1])] > c1.get((h[0], h[1]), 0)]
        if not only1 and not only0:
            continue
        print(f"######## {p}  (own differences before {len(d0)}, now {len(d1)})")
        for h in only1:
            print(f"  [{a.src} has, {a.dst} lacks] ...{' '.join(tpost[max(0, h[2] - 5):h[2]])} | {a.src}: "
                  f"{' '.join(h[0])[:200]!r}  {a.dst}: {' '.join(h[1])[:200]!r}")
        for h in only0:
            print(f"  [difference gone]          ...{' '.join(tpre[max(0, h[2] - 5):h[2]])} | {a.src} pre: "
                  f"{' '.join(h[0])[:200]!r}  {a.dst} head: {' '.join(h[1])[:200]!r}")


def cmd_tokdiff(a):
    x, y = toks(read(a.a)), toks(read(a.b))
    sm = difflib.SequenceMatcher(None, x, y, autojunk=False)
    nd = 0
    for tag, i1, i2, j1, j2 in sm.get_opcodes():
        if tag == "equal":
            continue
        nd += 1
        if not a.stats:
            print(f"@@ {tag} a[{i1}:{i2}] b[{j1}:{j2}]\n   ...{' '.join(x[max(0, i1 - a.context):i1])}\n"
                  f" - {' '.join(x[i1:i2])}\n + {' '.join(y[j1:j2])}\n   {' '.join(x[i2:i2 + a.context])}...")
    print(f"{nd} hunks; {len(x)} vs {len(y)} tokens")
    sys.exit(1 if nd else 0)


def main():
    import argparse
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    for name in ("classify", "adopt", "audit"):
        s = sub.add_parser(name)
        s.add_argument("src")
        s.add_argument("dst")
        s.add_argument("--pre", required=True)
        if name == "classify":
            s.add_argument("--out")
        if name == "adopt":
            s.add_argument("--apply", action="store_true")
        if name in ("adopt", "audit"):
            s.add_argument("--only", nargs="*", default=[])
    t = sub.add_parser("tokdiff")
    t.add_argument("a")
    t.add_argument("b")
    t.add_argument("--context", type=int, default=4)
    t.add_argument("--stats", action="store_true")
    a = ap.parse_args()
    {"classify": cmd_classify, "adopt": cmd_adopt, "audit": cmd_audit, "tokdiff": cmd_tokdiff}[a.cmd](a)


main()
