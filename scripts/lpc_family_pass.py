#!/usr/bin/env python3
"""scripts/lpc_family_pass.py ROOT SIB... --pre REV [--no-adopt] [--skip-heredoc]

The warnings pass of a sibling lib, after the root of its family is done and committed (KB 08 section 10.13):

  1. lpc_twin_port.py adopt ROOT SIB --pre REV --apply     the fixes of the files that carry the root's code
  2. lpc_warnings.py SIB --fix                              scan; the mechanical classes
  3. lpc_diamonds.py --fix-redundant, lpc_fix_void_override.py, lpc_fix_macro_redef.py, lpc_fix_prototype_types.py,
     lpc_move_decl.py, lpc_fix_no_effect.py, then lpc_fix_heredoc_terminator.py (each reads the scan of step 2 and edits
     SIB; the last one needs no scan)
  4. lpc_warnings.py SIB --fix; lpc_name_winner.py; lpc_warnings.py SIB --fix   (the winners only after the redundant
     inherits are gone)
  5. which files fail here and not in the root's last scan (/tmp/lpcw-ROOT/diagnostics.tsv), and the other way round.

REV is the commit before the root's fix (its tree is the pre-image the siblings are compared with).  Every step's tail
goes to /tmp/fdtest/fam_SIB.log (the directory is created); the final numbers are printed.  Nothing is committed: read
`git diff --shortstat -- libs/SIB`, run the load check (/tmp/fdtest/listcheck_chunks.sh style: HEAD vs tree), write the
NOTES.md section, `git add -u libs/SIB`.  One sibling at a time (each scan is a full lpcc boot over every file)."""
import os
import re
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
args = sys.argv[1:]
pre = None
if "--pre" in args:
    i = args.index("--pre")
    pre = args[i + 1]
    del args[i:i + 2]
adopt = "--no-adopt" not in args
heredoc = "--skip-heredoc" not in args
args = [a for a in args if not a.startswith("--no-") and a != "--skip-heredoc"]
if len(args) < 2 or (adopt and not pre):
    sys.exit(__doc__)
root, sibs = args[0], args[1:]
os.makedirs("/tmp/fdtest", exist_ok=True)


def run(cmd, log):
    p = subprocess.run(cmd, cwd=REPO, capture_output=True, text=True)
    out = (p.stdout + p.stderr).rstrip("\n").split("\n")
    log.write("$ " + " ".join(cmd) + "\n" + "\n".join(out[-6:]) + "\n")
    log.flush()
    return p.stdout + p.stderr


def summary(text):
    m = re.search(r"(\d+) files compile, (\d+) do not; (\d+) distinct diagnostics", text)
    return tuple(int(x) for x in m.groups()) if m else None


def error_files(slug):
    out = set()
    try:
        for line in open(f"/tmp/lpcw-{slug}/diagnostics.tsv", errors="replace"):
            f = line.rstrip("\n").split("\t")
            if len(f) >= 5 and f[3] == "error":
                out.add(f[0])
    except OSError:
        pass
    return out


for sib in sibs:
    log = open(f"/tmp/fdtest/fam_{sib}.log", "w")
    if adopt:
        run(["python3", "scripts/lpc_twin_port.py", "classify", root, sib, "--pre", pre], log)
        run(["python3", "scripts/lpc_twin_port.py", "adopt", root, sib, "--pre", pre, "--apply"], log)
    first = run(["python3", "scripts/lpc_warnings.py", sib, "--fix"], log)
    # the first block of the report is the scan before the fixes
    before = summary(first)
    # redundant inherits first: a leaf that inherits what its base already has needs no wrapper function
    for tool in (["scripts/lpc_diamonds.py", sib, "--fix-redundant", "--apply"],
                 ["scripts/lpc_fix_void_override.py", sib, "--apply"],
                 ["scripts/lpc_fix_macro_redef.py", sib, "--apply"],
                 ["scripts/lpc_fix_prototype_types.py", "--apply", sib],
                 ["scripts/lpc_move_decl.py", sib, "--apply"],
                 ["scripts/lpc_fix_no_effect.py", sib, "--apply"]):
        run(["python3"] + tool, log)
    if heredoc:
        run(["python3", "scripts/lpc_fix_heredoc_terminator.py", "--apply", sib], log)
    # the name winners read the inherits that are LEFT: rescan after the redundant ones are gone, or the wrappers
    # name a scope that no longer exists (`Unable to find the inherited function 'f' in file 'skill'`, xbtxiii 24 files)
    run(["python3", "scripts/lpc_warnings.py", sib, "--fix"], log)
    run(["python3", "scripts/lpc_name_winner.py", sib, "--apply"], log)
    second = run(["python3", "scripts/lpc_warnings.py", sib, "--fix"], log)
    after = summary(second.split("after fixing")[-1]) or summary(second)
    mine, theirs = error_files(sib), error_files(root)
    log.write(f"files failing here, not in {root}: {sorted(mine - theirs)}\n")
    log.write(f"files failing in {root}, not here: {sorted(theirs - mine)}\n")
    log.close()
    print(f"{sib}: after adopt+fix {before} -> {after}; only here {len(mine - theirs)}, only in {root} {len(theirs - mine)}; "
          f"see /tmp/fdtest/fam_{sib}.log")
