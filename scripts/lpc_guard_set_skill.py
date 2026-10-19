#!/usr/bin/env python3
"""scripts/lpc_guard_set_skill.py [SLUG...] [--apply]

`set_skill()` of a skill the lib has no file for (KB 06 section 7.256).  The shared skill feature raises
`error("F_SKILL: No such skill (name)")`, and the caller is an NPC's `create()`: the NPC never loads, the room that
spawns it loses it (3,700 files in 169 libs call `set_skill()` with a name no skill file of their lib carries:
`magic-sword` for the wxddym/zxty maze bosses, `dragon` for the chidi dragons, `yijin-jing` for the Shaolin monks).
The skill is missing content, and the NPC is still worth having: chidi and fyzfqyy already skip the one skill instead
of aborting the whole object.

Inside the body of `set_skill()`, `map_skill()` and `prepare_skill()` (the three an NPC's `create()` calls) the
`error("F_SKILL ...")` call becomes `return` (`return 0` when the function is not void): the skill is not granted, the
mapping is not made, and the object goes on.  `map_skill("leg", ...)` names a base skill: bixiecanyang has no `leg`, nitan6
no `spells`, and the NPC died there too.  Only a file with one of the three and an `error("F_SKILL` in its body is
touched; a lib whose functions already guard (chidi, fyzfqyy: no error left; shzs/zzhj: `return notify_fail(...)`) is left
alone.  Comments and strings are masked; the file's own line endings are kept.
Without --apply the plan is printed (FIX lines, NOFIX lines for files that name F_SKILL but have no such error in
set_skill).  Idempotent."""
import os
import re
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from lpc_fix_void_return import code_mask  # noqa: E402

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SKIP = re.compile(r"/(u|w|wiz|wizard|wizards|open|players|backup|backups|old|bak|log|data|doc|docs|example|examples|bin|binaries)/|[-_.](bak|old|orphaned-driver-src)/|\.(bak|BAK|old|orig)(\.lpc)?$")
SIG = re.compile(rb"(?m)^[ \t]*((?:varargs[ \t]+)?(?:void|int|mixed|status)?)[ \t]*(?:set_skill|map_skill|prepare_skill)[ \t]*\(")


FSK = re.compile(rb'#[ \t]*define[ \t]+F_SKILL[ \t]+"([^"\n]+)"')


def tracked(slugs):
    out = subprocess.run(["git", "ls-files", "-z", "--"] + [f"libs/{s}/work" for s in slugs] if slugs else ["git", "ls-files", "-z", "--", "libs"],
                         cwd=REPO, capture_output=True).stdout.split(b"\0")
    for f in out:
        try:
            p = f.decode("utf-8")
        except UnicodeDecodeError:
            continue
        parts = p.split("/")
        if len(parts) > 3 and parts[2] == "work" and parts[1] != "longyunmeng_binary" and p.endswith((".lpc", ".h")) and not SKIP.search("/" + "/".join(parts[3:])):
            yield p


def match_close(code, i, open_c, close_c):
    """index of the bracket closing the one at i (code is the masked buffer: strings and comments blank)"""
    depth = 0
    for j in range(i, len(code)):
        c = code[j:j + 1]
        if c == open_c:
            depth += 1
        elif c == close_c:
            depth -= 1
            if depth == 0:
                return j
    return -1


def fix(b):
    """-> (new bytes, number of error() calls turned into return) or (None, reason)"""
    if b"F_SKILL" not in b or not re.search(rb"(?:set_skill|map_skill|prepare_skill)", b):
        return None, None
    mask = code_mask(b, heredoc=True)
    code = bytes(c if m else 32 for c, m in zip(b, mask))   # strings/comments blanked, same length
    edits = []
    for m in SIG.finditer(code):
        if not mask[m.start() + len(m.group(0)) - 1]:
            continue
        rtype = m.group(1).replace(b"varargs", b"").strip()
        p_open = m.end() - 1
        p_close = match_close(code, p_open, b"(", b")")
        if p_close < 0:
            continue
        k = p_close + 1
        while k < len(code) and code[k:k + 1] in b" \t\r\n":
            k += 1
        if code[k:k + 1] != b"{":
            continue    # a prototype
        end = match_close(code, k, b"{", b"}")
        if end < 0:
            continue
        for e in re.finditer(rb"(?<![A-Za-z0-9_])error[ \t]*\(", code[k:end]):
            s = k + e.start()
            if b'"F_SKILL' not in b[s:s + 40]:
                continue
            c = match_close(code, k + e.end() - 1, b"(", b")")
            if c < 0:
                continue
            edits.append((s, c + 1, b"return" if rtype in (b"", b"void") else b"return 0"))
    if not edits:
        return None, "no error(F_SKILL) in a set_skill/map_skill/prepare_skill body"
    out, last = [], 0
    for s, e, rep in sorted(edits):
        out.append(b[last:s])
        out.append(rep)
        last = e
    out.append(b[last:])
    return b"".join(out), len(edits)


def skill_targets(files):
    """-> {slug: {path of the file F_SKILL names}}: the shared skill feature the lib really inherits (backup and
    dated copies next to it are not edited)"""
    res = {}
    for p in files:
        if not p.endswith(".h"):
            continue
        try:
            b = open(f"{REPO}/{p}", "rb").read()
        except OSError:
            continue
        for m in FSK.finditer(b):
            t = m.group(1).decode("utf-8", "replace").lstrip("/")
            slug = p.split("/")[1]
            res.setdefault(slug, set()).update({t + ".lpc", t + ".c"} if not t.endswith((".lpc", ".c")) else {t})
    return res


def main():
    args = sys.argv[1:]
    apply = "--apply" in args
    slugs = [a for a in args if not a.startswith("--")]
    nfiles = nedits = 0
    libs = set()
    files = list(tracked(slugs))
    targets = skill_targets(files)
    for p in files:
        slug, rel = p.split("/")[1], "/".join(p.split("/")[3:])
        if rel not in targets.get(slug, {"feature/skill.lpc"}):
            continue
        full = f"{REPO}/{p}"
        try:
            b = open(full, "rb").read()
        except OSError:
            continue
        out, n = fix(b)
        if out is None:
            if n and b"set_skill" in b and b"F_SKILL: " in b:
                print(f"NOFIX {p}  ({n})")
            continue
        nfiles += 1
        nedits += n
        libs.add(p.split("/")[1])
        print(f"FIX   {p}  {n}")
        if apply:
            open(full, "wb").write(out)
    print(f"{nedits} error() call(s) in {nfiles} file(s) of {len(libs)} lib(s)" + ("" if apply else " (plan only; --apply writes)"))


if __name__ == "__main__":
    main()
