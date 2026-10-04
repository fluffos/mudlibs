#!/usr/bin/env python3
"""scripts/submodule_patch_scratch.py build|export SLUG [options]

Develop (or regenerate) the catalog patches of a `submodule-patch` lib whose upstream keeps `.c` names (lima).  The scanners
and fixers in this directory work on `libs/SLUG/work` of a repo whose files are `.lpc`; a submodule's worktree is upstream's
and must stay clean.  So the work happens in a scratch repo:

  build SLUG [--dest DIR] [--below N]
      DIR (default /tmp/scratch-SLUG) gets
        orig/              upstream HEAD of libs/SLUG/work with the compat patches numbered below N applied (default: all
                           patches already in libs/SLUG/patches, i.e. the baseline a NEW patch set starts from; pass
                           --below 3 to regenerate patches 0003 and up)
        repo/              a git repo with scripts/ (a copy), libs/SLUG/{config.fluffos,overlay} and libs/SLUG/work = the
                           mudlib directory (meta.json upstream.mudlib_subdir) with every `.c` renamed to `.lpc` and every
                           `#include "x.c"` rewritten to `.lpc`, committed as the baseline
      Then, in DIR/repo: LPCC=<driver build>/lpcc python3 scripts/lpc_warnings.py SLUG [--fix], lpc_name_winner.py, ...
      exactly as for a vendored lib.  Build the tree once per pin; never edit libs/SLUG/work in the main repo.

  export SLUG [--dest DIR] [--stage NAME:PREFIX,PREFIX ...] [--first-number N]
      Renames the scratch tree back to upstream's names, diffs it against orig/ and writes sequential patches to
      DIR/patches/: patch N removes the `#pragma no_warnings` lines (if the baseline has them), the following ones carry the
      files under each --stage prefix (paths relative to the mudlib directory, e.g. `std/`), in the order given; a file
      that matches no stage is an error.  Every patch is `git apply -p1` from work/ (paths `a/lib/...`).  The last step
      checks that the patches rebuild the scratch tree byte for byte.

Copy the result into libs/SLUG/patches/ and run `python3 scripts/apply_lib_patches.py SLUG --work <git archive copy>`.
A scan of the real tree needs a `.c`-aware batch: apply the patches to a copy of upstream and feed lpcc every `.c` object."""
import argparse
import json
import os
import re
import shutil
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def meta(slug):
    with open(f"{REPO}/libs/{slug}/meta.json", encoding="utf-8") as fh:
        return json.load(fh)


def patches_below(slug, below):
    d = f"{REPO}/libs/{slug}/patches"
    names = sorted(n for n in os.listdir(d) if n.endswith(".patch")) if os.path.isdir(d) else []
    return [n for n in names if below is None or int(n.split("-")[0]) < below]


def build(slug, dest, below):
    m = meta(slug)
    sub = (m.get("upstream") or {}).get("mudlib_subdir", "")
    orig, repo = f"{dest}/orig", f"{dest}/repo"
    for d in (orig, repo):
        shutil.rmtree(d, ignore_errors=True)
    os.makedirs(orig)
    arch = subprocess.Popen(["git", "-C", f"{REPO}/libs/{slug}/work", "archive", "HEAD"], stdout=subprocess.PIPE)
    subprocess.run(["tar", "-x", "-C", orig], stdin=arch.stdout, check=True)
    arch.wait()
    for n in patches_below(slug, below):
        subprocess.run(["git", "apply", "-p1", f"{REPO}/libs/{slug}/patches/{n}"], cwd=orig, check=True)
        print("baseline patch", n)
    work = f"{repo}/libs/{slug}/work"
    shutil.copytree(f"{orig}/{sub}" if sub else orig, work, symlinks=True)
    for dp, dn, fn in os.walk(work):
        for f in fn:
            p = os.path.join(dp, f)
            if f.endswith(".c"):
                os.rename(p, p[:-2] + ".lpc")
                p = p[:-2] + ".lpc"
            if p.endswith((".lpc", ".h")):
                src = open(p, "rb").read()
                new = re.sub(rb'(?m)^([ \t]*#[ \t]*include[ \t]+"[^"]*)\.c"', rb'\1.lpc"', src)
                if new != src:
                    open(p, "wb").write(new)
    shutil.copy(f"{REPO}/libs/{slug}/config.fluffos", f"{repo}/libs/{slug}/config.fluffos")
    if os.path.isdir(f"{REPO}/libs/{slug}/overlay"):
        shutil.copytree(f"{REPO}/libs/{slug}/overlay", f"{repo}/libs/{slug}/overlay", symlinks=True)
    shutil.copytree(f"{REPO}/scripts", f"{repo}/scripts", symlinks=True)
    for cmd in (["git", "init", "-q"], ["git", "add", "-A"],
                ["git", "-c", "user.email=a@b", "-c", "user.name=scratch", "commit", "-q", "-m", "base"]):
        subprocess.run(cmd, cwd=repo, check=True, stdout=subprocess.DEVNULL)
    print(f"scratch repo {repo}  (orig tree {orig}; mudlib directory {sub or '.'})")


def rename_back(tree):
    for dp, dn, fn in os.walk(tree):
        for f in fn:
            p = os.path.join(dp, f)
            if f.endswith(".lpc"):
                os.rename(p, p[:-4] + ".c")
                p = p[:-4] + ".c"
            if p.endswith((".c", ".h")):
                src = open(p, "rb").read()
                new = re.sub(rb'(?m)^([ \t]*#[ \t]*include[ \t]+"[^"]*)\.lpc"', rb'\1.c"', src)
                if new != src:
                    open(p, "wb").write(new)


def tree_diff(base, a, b):
    out = subprocess.run(["git", "-c", "core.autocrlf=false", "diff", "--no-index", "--no-color", a, b], cwd=base,
                         capture_output=True).stdout.decode("utf-8", "surrogateescape")
    out = re.sub(rf"(?m)^(diff --git a/){re.escape(a)}/(\S+) b/{re.escape(b)}/(\S+)", r"\1\2 b/\3", out)
    out = re.sub(rf"(?m)^--- a/{re.escape(a)}/", "--- a/", out)
    out = re.sub(rf"(?m)^\+\+\+ b/{re.escape(b)}/", "+++ b/", out)
    return out


def export(slug, dest, stages, first):
    m = meta(slug)
    sub = (m.get("upstream") or {}).get("mudlib_subdir", "")
    orig, repo = f"{dest}/orig", f"{dest}/repo"
    exp = f"{dest}/export"
    shutil.rmtree(exp, ignore_errors=True)
    final = f"{exp}/final/{sub or '.'}"
    os.makedirs(os.path.dirname(final) if sub else exp + "/final", exist_ok=True)
    shutil.copytree(f"{repo}/libs/{slug}/work", final, symlinks=True)
    rename_back(final)
    base = f"{orig}/{sub}" if sub else orig
    changed = []
    for dp, dn, fn in os.walk(final):
        for f in fn:
            p = os.path.join(dp, f)
            rel = os.path.relpath(p, final)
            q = os.path.join(base, rel)
            if not os.path.exists(q) or open(p, "rb").read() != open(q, "rb").read():
                changed.append(rel)
    gone = [os.path.relpath(os.path.join(dp, f), base) for dp, dn, fn in os.walk(base) for f in fn
            if not os.path.exists(os.path.join(final, os.path.relpath(os.path.join(dp, f), base)))]
    if gone:
        sys.exit(f"files missing from the scratch tree: {gone[:5]}")
    prag = [r for r in changed if re.search(rb"(?m)^#pragma no_warnings", open(os.path.join(base, r), "rb").read())]
    plan = [("remove-no_warnings-pragma", None)] if prag else []
    for st in stages:
        name, prefixes = st.split(":", 1)
        plan.append((name, tuple(prefixes.split(","))))
    rest = [r for r in changed if r not in prag and not any(r.startswith(p) for _, ps in plan if ps for p in ps)]
    if rest:
        sys.exit(f"changed files outside every stage: {rest[:8]} ({len(rest)})")
    os.makedirs(f"{dest}/patches", exist_ok=True)
    prev = f"{exp}/s0"
    shutil.copytree(base, prev, symlinks=True)
    shutil.rmtree(f"{dest}/patches")
    os.makedirs(f"{dest}/patches")
    number = first
    for idx, (name, prefixes) in enumerate(plan, start=1):
        cur = f"{exp}/s{idx}"
        shutil.copytree(prev, cur, symlinks=True)
        if prefixes is None:
            for r in prag:
                p = os.path.join(cur, r)
                src = open(p, "rb").read()
                open(p, "wb").write(re.sub(rb"(?m)^#pragma no_warnings[ \t]*\r?\n", b"", src, count=1))
        else:
            for r in changed:
                if r.startswith(prefixes) and r not in prag or (r in prag and r.startswith(prefixes)):
                    os.makedirs(os.path.dirname(os.path.join(cur, r)), exist_ok=True)
                    shutil.copyfile(os.path.join(final, r), os.path.join(cur, r))
        # git diff --no-index wants plain relative dirs under one parent; the mudlib subdir becomes the path prefix
        a, b = f"s{idx-1}", f"s{idx}"
        text = tree_diff(exp, a, b)
        if sub:
            text = re.sub(r"(?m)^(diff --git a/)", rf"\1{sub}/", text)
            text = re.sub(r"(?m)^(diff --git a/\S+ b/)", rf"\1{sub}/", text)
            text = re.sub(r"(?m)^--- a/", f"--- a/{sub}/", text)
            text = re.sub(r"(?m)^\+\+\+ b/", f"+++ b/{sub}/", text)
        fname = f"{dest}/patches/{number:04d}-{name}.patch"
        open(fname, "w", encoding="utf-8", errors="surrogateescape").write(text)
        print(f"{os.path.basename(fname)}: {len(re.findall(r'(?m)^diff --git', text))} files, {text.count(chr(10))} lines")
        prev = cur
        number += 1
    r = subprocess.run(["diff", "-r", prev, final], capture_output=True, text=True)
    if r.returncode:
        sys.exit("the staged patches do not rebuild the scratch tree:\n" + r.stdout[:400])
    # and the patch files themselves, applied to a fresh upstream copy
    chk = f"{exp}/check"
    shutil.copytree(orig, chk, symlinks=True)
    for fn in sorted(os.listdir(f"{dest}/patches")):
        subprocess.run(["git", "apply", "-p1", f"{dest}/patches/{fn}"], cwd=chk, check=True)
    r = subprocess.run(["diff", "-r", f"{chk}/{sub}" if sub else chk, final], capture_output=True, text=True)
    print("patches rebuild the scratch tree byte for byte:", r.returncode == 0)
    print(f"patches in {dest}/patches")


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    ap.add_argument("cmd", choices=["build", "export"])
    ap.add_argument("slug")
    ap.add_argument("--dest", default=None)
    ap.add_argument("--below", type=int, default=None, help="build: baseline = patches numbered below N (default all)")
    ap.add_argument("--stage", action="append", default=[], help="export: NAME:PREFIX,PREFIX (repeatable, in order)")
    ap.add_argument("--first-number", type=int, default=3)
    a = ap.parse_args()
    dest = a.dest or f"/tmp/scratch-{a.slug}"
    if a.cmd == "build":
        build(a.slug, dest, a.below)
    else:
        export(a.slug, dest, a.stage, a.first_number)


if __name__ == "__main__":
    main()
