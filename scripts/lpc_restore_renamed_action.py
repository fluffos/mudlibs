#!/usr/bin/env python3
"""scripts/lpc_restore_renamed_action.py [--apply] --commit SHA --pairs FILE

Puts back an `add_action("handler", "verb");` statement that `lpc_fix_dead_add_action.py` removed (KB 06 section 7.349), under the name of the function the object
really has.  The removal was right (the statement named a function nobody defines: `*Function for verb 'list' not found.`), but where the object's lib defines the
SAME job under the other lineage's name -- a shopkeeper that registered the xkx-style `do_list` while its `F_VENDOR` defines the fy-style `do_vendor_list`, or the
reverse (160 files in 20 libs) -- the verb is gone for good, and the function that would answer it sits unused.

FILE has `slug<TAB>/path/in/the/mudlib.lpc<TAB>old_handler<TAB>new_handler` lines.  For each file the removal commit's diff (`git diff SHA^ SHA -U0`) is read: a hunk that only
deletes lines and deletes the statement `add_action("old_handler", "verb")` on a line of its own gets that line back, with `new_handler` in place of `old_handler`
(indentation, verb, trailing comment and the file's own line ending kept), between the line before the hunk and the line after it, which are looked up in the file as it is now
(exactly one place, or the one nearest to the old position; none: printed as MANUAL).  Idempotent (a file that already holds the statement is skipped).  Binary mode.
Dry run by default; `--apply` writes."""
import collections
import os
import re
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
HUNK = re.compile(rb"^@@ -(\d+)(?:,(\d+))? \+(\d+)(?:,(\d+))? @@")


def git(*a):
    return subprocess.run(["git", *a], cwd=REPO, capture_output=True).stdout


def hunks(sha, path):
    out = git("diff", "-U0", "--no-color", f"{sha}^", sha, "--", path)
    cur = None
    res = []
    for ln in out.split(b"\n"):
        m = HUNK.match(ln)
        if m:
            cur = {"old": int(m.group(1)), "n_old": int(m.group(2)) if m.group(2) is not None else 1, "n_new": int(m.group(4)) if m.group(4) is not None else 1, "del": [], "add": []}
            res.append(cur)
        elif cur is not None and ln.startswith(b"-") and not ln.startswith(b"---"):
            cur["del"].append(ln[1:])
        elif cur is not None and ln.startswith(b"+") and not ln.startswith(b"+++"):
            cur["add"].append(ln[1:])
    return res


def main():
    argv = sys.argv[1:]
    apply = "--apply" in argv
    sha = pairs_file = None
    for i, a in enumerate(argv):
        if a == "--commit":
            sha = argv[i + 1]
        elif a == "--pairs":
            pairs_file = argv[i + 1]
    if not sha or not pairs_file:
        sys.exit(__doc__)
    want = collections.defaultdict(list)           # file -> [(old, new)]
    for ln in open(pairs_file, encoding="utf-8"):
        f = ln.rstrip("\n").split("\t")
        if len(f) >= 4:
            want[f"libs/{f[0]}/work{f[1]}"].append((f[2], f[3]))
    done = manual = skipped = 0
    for path, pairs in sorted(want.items()):
        cur_b = open(f"{REPO}/{path}", "rb").read() if os.path.exists(f"{REPO}/{path}") else None
        if cur_b is None:
            print(f"MANUAL {path}: the file is gone")
            manual += 1
            continue
        nl = b"\r\n" if cur_b.count(b"\r\n") * 2 > cur_b.count(b"\n") else b"\n"
        cur = cur_b.split(b"\n")
        pre = git("show", f"{sha}^:{path}").split(b"\n")
        inserts = []                                  # (index to insert after, new line bytes)
        have0 = {x.strip().rstrip(b"\r") for x in cur}
        sk0 = skipped
        collapsed = []                                # (index of the `void init() {}` line, the lines that replace it)
        for h in hunks(sha, path):
            if h["add"] and [x.strip() for x in h["add"]] == [b"void init() {}"] and h["del"]:      # the removal left an empty init(): it comes back with the statement
                block, hit = [], False
                for d in h["del"]:
                    m = None
                    for old, new in pairs:
                        m = re.match(rb'^([ \t]*)add_action\(\s*"' + re.escape(old.encode()) + rb'"\s*,\s*"([^"]*)"\s*\)\s*;[ \t\r]*(//.*)?$', d)
                        if m:
                            block.append(d.replace(b'"' + old.encode() + b'"', b'"' + new.encode() + b'"', 1).rstrip(b"\r"))
                            hit = True
                            break
                    if not m and not re.match(rb"^[ \t]*add_action\(", d):
                        block.append(d.rstrip(b"\r"))
                if hit and all(b_.strip() in have0 for b_ in block if b"add_action" in b_):
                    skipped += 1
                elif hit:
                    spots = [i for i in range(len(cur)) if cur[i].rstrip(b"\r").strip() == b"void init() {}"]
                    if len(spots) == 1:
                        collapsed.append((spots[0], block))
                    else:
                        print(f"MANUAL {path}:{h['old']}: {len(spots)} places hold `void init() {{}}`")
                        manual += 1
                continue
            if h["add"] or not h["del"]:
                continue
            keep = []
            for d in h["del"]:
                for old, new in pairs:
                    m = re.match(rb'^([ \t]*)add_action\(\s*"' + re.escape(old.encode()) + rb'"\s*,\s*"([^"]*)"\s*\)\s*;[ \t\r]*(//.*)?$', d)
                    if m:
                        keep.append(d.replace(b'"' + old.encode() + b'"', b'"' + new.encode() + b'"', 1).rstrip(b"\r"))
                        break
            if not keep:
                continue
            if all(k.strip() in have0 for k in keep):                 # restored by an earlier run
                skipped += 1
                continue
            start = h["old"]                          # 1-based number of the first deleted line in the old file
            prev = pre[start - 2].rstrip(b"\r") if start >= 2 else None
            nxt = pre[start - 1 + len(h["del"])].rstrip(b"\r") if start - 1 + len(h["del"]) < len(pre) else None
            spots = [i for i in range(len(cur) - 1) if cur[i].rstrip(b"\r") == prev and (nxt is None or cur[i + 1].rstrip(b"\r") == nxt)]
            if not spots:
                print(f"MANUAL {path}:{start}: the lines around the removed statement are not in the file any more")
                manual += 1
                continue
            at = min(spots, key=lambda i: abs(i - (start - 2)))
            if len(spots) > 1:
                print(f"NOTE {path}:{start}: {len(spots)} places match, took the one nearest to the old position (line {at + 1})")
            inserts.append((at, keep))
        if not inserts and not collapsed:
            if skipped == sk0:
                print(f"NOHUNK {path}: no hunk of the commit deleted a statement for " + ", ".join(o for o, _ in pairs))
                manual += 1
            continue
        # a file that already holds a statement for the new handler is left alone
        have = [x.strip().rstrip(b"\r") for x in cur]
        ops = []                                      # (index, kind, payload): applied from the bottom up so the indices stay valid
        for at, keep in inserts:
            for k in keep:
                if k.strip() in have:
                    skipped += 1
                else:
                    ops.append((at + 1, "ins", k))
        for idx, block in collapsed:
            ops.append((idx, "rep", block))
        if not ops:
            continue
        eol = b"\r" if nl == b"\r\n" else b""
        for idx, kind, payload in sorted(ops, key=lambda t: -t[0]):
            if kind == "ins":
                cur.insert(idx, payload + eol)
            else:
                cur[idx:idx + 1] = [b_ + eol for b_ in payload]
        done += len(ops)
        shown = [k.strip().decode("utf-8", "replace") for _, kind, p_ in ops if kind == "ins" for k in [p_]] + \
                [b_.strip().decode("utf-8", "replace") for _, kind, p_ in ops if kind == "rep" for b_ in p_ if b"add_action" in b_]
        print(f"{'RESTORE' if apply else 'would restore'} {path}: " + ", ".join(shown))
        if apply:
            open(f"{REPO}/{path}", "wb").write(b"\n".join(cur))
    print(f"{done} statement(s) {'restored' if apply else 'to restore'}, {manual} MANUAL, {skipped} already present", file=sys.stderr)


if __name__ == "__main__":
    main()
