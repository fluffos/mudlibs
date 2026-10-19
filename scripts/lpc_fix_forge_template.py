#!/usr/bin/env python3
"""scripts/lpc_fix_forge_template.py [SLUG...] [--apply]

The player-forged weapon templates of the xkx lineage (`d/npc/m_weapon/weapon/m_sword.lpc`, `m_blade`, `m_staff`, `m_whip`, `m_club`, `m_hammer`,
`m_bian`, `d/quanzhen*/obj/m_sword.lpc` ...) read the forge data from `this_player()` in `create()`:

    me = this_player();
    //读入数据
    if (me) {
      w_name = me->query("weapon/name");  w_lv = me->query("weapon/lv"); ...
      set_desc(w_lv, w_or, w_name);

That is a player.  An NPC that carries the template (`carry_object("/d/npc/m_weapon/weapon/m_sword")`: the alliance leader `clone/npc/meng-zhu`, the
death-area gargoyles, ...) is created while some other living is the command giver; the dbase of an NPC holds `weapon` as the *file name string*, so
`me->query("weapon/lv")` answers that string and `switch (w_lv)` in `set_desc()` dies with `Bad argument 1 to switch  Expected: int  Got: "/d/npc/..."`
(the NPC and the room whose reset created it never load; KB 06 section 7.275).  The old driver let the switch fall through to its default.

The fix tests what the code reads: `if (me && mapp(me->query("weapon"))) {`.  Binary-safe, line endings kept; without --apply the plan is printed
(FIX lines, one per file); idempotent."""
import os
import re
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
PAT = re.compile(rb"(me = this_player\(\);[ \t]*\r?\n[ \t]*//\xe8\xaf\xbb\xe5\x85\xa5\xe6\x95\xb0\xe6\x8d\xae[ \t]*\r?\n[ \t]*)if[ \t]*\([ \t]*me[ \t]*\)([ \t]*\{)")


_HAS = {}


def has_m_weapon(slug):
    """does the lib define M_WEAPON in its headers?"""
    if slug not in _HAS:
        r = subprocess.run(["grep", "-r", "-l", "-a", "-E", r"define[ \t]+M_WEAPON", f"{REPO}/libs/{slug}/work/include"], capture_output=True)
        _HAS[slug] = bool(r.stdout.strip())
    return _HAS[slug]


def main():
    args = sys.argv[1:]
    apply = "--apply" in args
    only = [a for a in args if not a.startswith("--")]
    raw = subprocess.run(["git", "-c", "core.quotepath=false", "grep", "-l", "-a", "-P", r"me = this_player\(\);", "--", "libs/*/work/*.lpc"], cwd=REPO,
                         capture_output=True).stdout.split(b"\n")
    n = 0
    for r in raw:
        if not r:
            continue
        rel = r.decode("utf-8", "surrogateescape")
        slug = rel.split("/")[1]
        if (only and slug not in only) or slug in ("wllz3", "longyunmeng_binary"):
            continue
        full = os.path.join(REPO, rel)
        b = open(full, "rb").read()
        if b"m_weapon" not in b and b"weapon/name" not in b:
            continue
        if not has_m_weapon(slug):
            continue        # wuhanzhan: no M_WEAPON base at all, the templates never compiled (a lost-macro case, KB 04 section 6.16)
        new, k = PAT.subn(lambda m: m.group(1) + b'if (me && mapp(me->query("weapon")))' + m.group(2), b)
        if not k:
            continue
        n += 1
        print(f"FIX   {slug} /{rel.split('/work/', 1)[1]}")
        if apply:
            open(full, "wb").write(new)
    print(f"{n} file(s)" + ("" if apply else " (plan only; --apply writes)"))


if __name__ == "__main__":
    main()
