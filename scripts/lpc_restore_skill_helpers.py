#!/usr/bin/env python3
"""scripts/lpc_restore_skill_helpers.py [SLUG...] [--apply] [--list DIR]

A helper function the skill files call and the lib's skill base never defined (KB 06 section 7.261).  The basic martial arts
(`daemon/skill/boxing`, `houquan`, `westsword`, `taiji-quan` ...) choose their move with `action[NewRandom(i, 20, level/5)]`;
`NewRandom()` and the `sum()` under it belong to the skill base the other Eastern Story libs ship (`inherit/skill/skill.lpc`,
`std/skill.lpc`), but the Journey-to-the-West family (xyj, sjsh, xiyouji ...), dtxy, fy2mg and others carry a `/std/skill.lpc`
without them, so every skill that calls it dies with `Undefined function NewRandom` and the characters that have the skill
fall back to bare hands.

For each lib whose `SKILL` base (the `#define SKILL "/std/skill"` of its headers) lacks the helper while a live file that
inherits that base calls it without defining it, the helper (the text 115 libs share, with the `sum()` it needs) is appended
to the base, in the base's line ending.  A base that already defines `sum` is left and reported.  Wizard, backup and example
dirs are not counted.  Without --apply the plan is printed (ADD lines: lib, base, number of callers); `--list DIR` writes
DIR/helpers-SLUG.list (the callers, `/path.lpc` per line) for the load check; idempotent.

HELPERS is a table (helper name -> text and the names it defines) so another helper of the same kind joins by adding a row."""
import os
import re
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SKIP = re.compile(r"/(u|w|wiz|wizard|wizards|open|players|backup|backups|old|bak|log|data|doc|docs|example|examples|test|tmp|attic)/|[-_.](bak|old|orphaned-driver-src)/|\.(bak|BAK|old|orig)(\.lpc)?$")

NEWRANDOM = """
// The following two functions are used to modify the random function
// for shaolin wugong.

int sum(int n, int base, int d) {
  return (n * (2 * base + (n - 1) * d) / 2);
}

int NewRandom(int n, int base, int d) {
  int i = 1;
  int randnum = random(sum(n, base, d));

  if (sum(6, base, d) < randnum) {
    i = 7;
    while (sum(i, base, d) < randnum)
      i++;
  } else {
    while (sum(i, base, d) < randnum)
      i++;
  }
  return (i - 1);
}
"""
# helper called, names its text defines, text
HELPERS = [("NewRandom", ("sum", "NewRandom"), NEWRANDOM)]


def tracked():
    files = {}
    for f in subprocess.run(["git", "ls-files", "-z", "--", "libs"], cwd=REPO, capture_output=True).stdout.split(b"\0"):
        try:
            p = f.decode("utf-8")
        except UnicodeDecodeError:
            continue
        parts = p.split("/", 3)
        if len(parts) == 4 and parts[2] == "work" and parts[1] != "longyunmeng_binary" and p.endswith((".lpc", ".h")):
            files.setdefault(parts[1], []).append(parts[3])
    return files


def skill_base(slug, files):
    for h in ("include/globals.h", "include/config.h", "include/skill.h"):
        p = f"{REPO}/libs/{slug}/work/{h}"
        if os.path.exists(p):
            m = re.search(rb'#[ \t]*define[ \t]+SKILL[ \t]+"([^"\n]+)"', open(p, "rb").read())
            if m:
                path = m.group(1).decode("utf-8", "replace").lstrip("/")
                for cand in (path, path + ".lpc"):
                    if cand in files:
                        return m.group(1).decode(), cand
    return None, None


def main():
    args = sys.argv[1:]
    apply = "--apply" in args
    listdir = None
    if "--list" in args:
        i = args.index("--list")
        listdir = args[i + 1]
        del args[i:i + 2]
    only = [a for a in args if not a.startswith("--")]
    by = tracked()
    nlibs = nfiles = 0
    for slug in sorted(only or by):
        if slug not in by or os.path.exists(f"{REPO}/libs/{slug}/work/.git"):
            continue
        macro, base = skill_base(slug, set(by[slug]))
        if not base:
            continue
        bpath = f"{REPO}/libs/{slug}/work/{base}"
        bt = open(bpath, "rb").read()
        for call, defines, text in HELPERS:
            if re.search(rb"(?<![A-Za-z0-9_])" + call.encode() + rb"[ \t]*\(", bt) and re.search(rb"(?m)^[ \t]*(?:varargs[ \t]+)?int[ \t]+" + call.encode() + rb"[ \t]*\(", bt):
                continue
            blocked = [d for d in defines if d != call and re.search(rb"(?m)^[ \t]*(?:varargs[ \t]+|static[ \t]+|private[ \t]+)*(?:int|mixed|void|string)[ \t]+" + d.encode() + rb"[ \t]*\(", bt)]
            callers = []
            for rel in by[slug]:
                if SKIP.search("/" + rel) or rel == base:
                    continue
                try:
                    t = open(f"{REPO}/libs/{slug}/work/{rel}", "rb").read()
                except OSError:
                    continue
                if call.encode() + b"(" not in t:
                    continue
                if not (re.search(rb"inherit[ \t]+SKILL[ \t]*;", t) or (b'inherit "' + macro.encode() + b'"') in t):
                    continue
                if re.search(rb"(?m)^[ \t]*(?:varargs[ \t]+)?int[ \t]+" + call.encode() + rb"[ \t]*\(", t):
                    continue
                callers.append(rel)
            if not callers:
                continue
            if blocked:
                print(f"SKIP  {slug} {base}: already defines {', '.join(blocked)}; {len(callers)} caller(s) of {call}()")
                continue
            nlibs += 1
            nfiles += len(callers)
            if listdir:
                os.makedirs(listdir, exist_ok=True)
                open(f"{listdir}/helpers-{slug}.list", "w", encoding="utf-8").write("\n".join("/" + c for c in sorted(callers)) + "\n")
            print(f"ADD   {slug} {base}: {call}() for {len(callers)} skill file(s), e.g. {callers[0]}")
            if apply:
                crlf = b"\r\n" in bt and bt.count(b"\r\n") == bt.count(b"\n")
                add = text.encode("utf-8")
                if crlf:
                    add = add.replace(b"\n", b"\r\n")
                nl = b"\r\n" if crlf else b"\n"
                if not bt.endswith(b"\n"):
                    bt += nl
                open(bpath, "wb").write(bt + add)
    print(f"{nlibs} lib(s), {nfiles} skill file(s)" + ("" if apply else " (plan only; --apply writes)"))


if __name__ == "__main__":
    main()
