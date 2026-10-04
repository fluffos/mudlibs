#!/usr/bin/env python3
"""scripts/lpc_fuzzy_patch.py PATCH WORKDIR [--strip N] [--apply] [--only SUBSTR]
Apply a unified diff to files whose formatting differs (spaces after keywords, brace placement, indent width): hunks
are matched on their text with ALL whitespace removed and blank lines ignored; context lines stay as the target has
them, '-' lines are removed, '+' lines are inserted re-indented by the target/hunk indent ratio.  Ambiguous or
missing matches are reported and left alone.  Prints one line per hunk; without --apply nothing is written.

Why: a sibling lib that went through the formatter (brassring: 2-space indent, `if (x)`) rejects 95% of the hunks of a
patch cut from a lib that did not (`patch -l` only folds runs of whitespace, it does not equate `if(` with `if (`).
Typical use: `git show COMMIT --format= -- libs/ds386/work > /tmp/p.patch; scripts/lpc_fuzzy_patch.py /tmp/p.patch
libs/brassring/work --apply`, then `scripts/lpc_warnings.py brassring --fix` for what was missed.  Read the result:
changed lines carry the patch's spelling, new lines the target's indent width."""
import re, sys, os, collections
args = sys.argv[1:]
patch, work = args[0], args[1]
strip = int(args[args.index("--strip") + 1]) if "--strip" in args else 4
apply_ = "--apply" in args
only = args[args.index("--only") + 1] if "--only" in args else None
norm = lambda s: re.sub(r"\s+", "", s)

def parse(path):
    files = collections.OrderedDict(); cur = None; hunk = None
    for raw in open(path, "rb").read().decode("latin-1").split("\n"):
        line = raw.rstrip("\r")
        if line.startswith("diff --git "):
            cur = None; hunk = None; continue
        if line.startswith("+++ "):
            p = line[4:].strip()
            if p == "/dev/null": cur = None; continue
            rel = "/".join(p.split("/")[strip:])
            cur = files.setdefault(rel, []); continue
        if line.startswith("--- "):
            continue
        if line.startswith("@@") and cur is not None:
            hunk = {"head": line, "lines": []}; cur.append(hunk); continue
        if hunk is not None and cur is not None and line[:1] in (" ", "+", "-"):
            hunk["lines"].append((line[0], line[1:]))
        elif hunk is not None and line.startswith("\\"):
            continue
        elif line.startswith("index ") or line.startswith("new file") or line.startswith("deleted file") or line.startswith("old mode") or line.startswith("new mode") or line.startswith("similarity"):
            continue
        elif line == "" and hunk is not None:
            hunk["lines"].append((" ", ""))
    return files

def indent_of(s):
    return len(s) - len(s.lstrip(" \t"))

stats = collections.Counter()
for rel, hunks in parse(patch).items():
    if only and only not in rel: continue
    path = os.path.join(work, rel)
    if not os.path.isfile(path):
        stats["missing-file"] += 1; continue
    raw = open(path, "rb").read().decode("latin-1")
    nl = "\r\n" if "\r\n" in raw else "\n"
    lines = raw.split(nl)
    changed = False
    for h in hunks:
        old = [(k, t) for k, t in h["lines"] if k in (" ", "-") and norm(t)]
        if not old:
            stats["pure-add-skipped"] += 1; print(f"SKIP  {rel} {h['head'][:40]}: pure insertion without context"); continue
        want = [norm(t) for k, t in old]
        idx = [(i, norm(l)) for i, l in enumerate(lines) if norm(l)]
        cand = []
        for a in range(len(idx) - len(want) + 1):
            if all(idx[a + b][1] == want[b] for b in range(len(want))):
                cand.append(a)
        if len(cand) != 1:
            stats["nomatch" if not cand else "ambiguous"] += 1
            print(f"{'AMBIG' if cand else 'MISS '} {rel} {h['head'][:44]}: {len(cand)} matches")
            continue
        a = cand[0]
        tline = [idx[a + b][0] for b in range(len(want))]      # target line numbers of the old (non-blank) lines
        # indent ratio from context lines
        ratios = []
        pos = 0
        for k, t in old:
            if k == " " and indent_of(t) > 0 and indent_of(lines[tline[pos]]) > 0:
                ratios.append(indent_of(lines[tline[pos]]) / indent_of(t))
            pos += 1
        ratio = sorted(ratios)[len(ratios) // 2] if ratios else 1.0
        # rebuild: walk the hunk lines; blank target lines between matched lines are kept
        out = []; pos = 0; first = tline[0]; last = tline[-1]; prev = first - 1
        for k, t in h["lines"]:
            if k == "+":
                n = indent_of(t); body = t.lstrip(" \t")
                if not body: continue
                out.append(" " * int(round(n * ratio)) + body)
            elif norm(t):
                ti = tline[pos]
                out.extend(lines[prev + 1:ti])
                if k == " ": out.append(lines[ti])
                prev = ti; pos += 1
        lines[first:last + 1] = out
        stats["applied"] += 1; changed = True
        print(f"OK    {rel} {h['head'][:44]} at line {first + 1}")
    if changed and apply_:
        open(path, "wb").write(nl.join(lines).encode("latin-1"))
print(dict(stats))
