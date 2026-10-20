#!/usr/bin/env python3
"""scripts/lpc_format_changed.py [--apply] FILE... (or the list on stdin)

The fix-pass formatter step of KB 08 section 9, done safely.  Runs the corpus formatter
(~/src/fluffos/tools/lpc-syntax/bin/format-corpus.mjs) in --check mode on the HEAD copy and on the working copy of
each changed .lpc/.h file:
  - HEAD copy normalized, working copy not: the edit broke the layout; with --apply the file is formatted (only the
    edited lines move);
  - HEAD copy not normalized, or refused by the formatter (it did not parse): the file was never formatted; left in its own
    style (formatting it would rewrite it end to end and bury the fix);
  - both normalized: nothing to do.
Never writes a file the formatter would rewrite for reasons older than the edit.  Without --apply the plan is
printed.  HEAD copies go to $LPC_SCRATCH/fmt-head (default ~/.cache/lpc-scratch)."""
import os
import shutil
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
FMT = os.path.expanduser("~/src/fluffos/tools/lpc-syntax/bin/format-corpus.mjs")
SCR = os.path.join(os.environ.get("LPC_SCRATCH") or os.path.expanduser("~/.cache/lpc-scratch"), "fmt-head")


def would(paths):
    """(paths the formatter's --check would reformat, paths it refuses: a parse error, a literal it would change)"""
    if not paths:
        return set(), set()
    r = subprocess.run(["node", FMT, "--check"], input="\n".join(paths) + "\n", capture_output=True, text=True)
    reform = {l[len("would reformat: "):] for l in r.stdout.splitlines() if l.startswith("would reformat: ")}
    refused = set()
    for l in r.stderr.splitlines():
        if "refusing to write: " in l:
            refused.add(l.split("refusing to write: ", 1)[1].split(": ")[0])
        elif l.startswith(("READ ERROR ", "FORMAT ERROR ")):
            refused.add(l.split(" ", 2)[2].split(": ")[0])
    return reform, refused


def main():
    args = sys.argv[1:]
    apply = "--apply" in args
    files = [a for a in args if not a.startswith("--")] or [l.strip() for l in sys.stdin if l.strip()]
    files = [os.path.relpath(os.path.abspath(f), REPO) for f in files if f.endswith((".lpc", ".h"))]
    shutil.rmtree(SCR, ignore_errors=True)
    head = {}
    for f in files:
        r = subprocess.run(["git", "-C", REPO, "show", f"HEAD:{f}"], capture_output=True)
        if r.returncode:
            continue   # new file: judged on the working copy alone
        p = os.path.join(SCR, f)
        os.makedirs(os.path.dirname(p), exist_ok=True)
        open(p, "wb").write(r.stdout)
        head[f] = p
    h_reform, h_refused = would(list(head.values()))
    h = h_reform | h_refused          # a HEAD copy the formatter refuses (it did not parse: lost quotes, a stray byte) was never formatted either
    t, _ = would([os.path.join(REPO, f) for f in files])
    todo = []
    for f in files:
        if os.path.join(REPO, f) not in t:
            continue
        if f in head and head[f] in h:
            print(f"KEEP  {f}  (never formatted)")
            continue
        print(f"FMT   {f}")
        todo.append(os.path.join(REPO, f))
    if apply and todo:
        r = subprocess.run(["node", FMT], input="\n".join(todo) + "\n", capture_output=True, text=True)
        print(r.stdout.strip().splitlines()[-1] if r.stdout.strip() else r.stderr.strip())
    print(f"{len(files)} file(s), {len(todo)} to format" + ("" if apply else " (plan only; --apply writes)"))


if __name__ == "__main__":
    main()
