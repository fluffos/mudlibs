#!/usr/bin/env python3
"""Repair files of a Latin-1 lib that the onboarding decoded as GB18030 (KB 03).

GB18030 turns each pair of Latin-1 high bytes (Finnish ä ö) into one CJK character and, on an invalid
pair, drops the high byte together with the ASCII byte after it (a space, a period, a closing quote:
`pitää pysty` -> `pit鋝 pystyclear...`, `"ä"` -> a string that never ends).  raw/ has the original bytes.

  python3 scripts/latin1_misdecode_repair.py SLUG [--apply] [--prefix RAWSUBDIR]

For every raw file with high bytes it aligns raw lines and work lines (difflib on the lines' ASCII
skeletons) and replaces a work line by the correct Latin-1 -> UTF-8 decoding of its raw line only when
the two skeletons differ by nothing but characters deleted right after a high byte of the raw line.  A
work line that was edited later (anything inserted or changed) is left alone and counted.  Line endings
are kept."""
import difflib, os, sys
args = sys.argv[1:]; apply_ = "--apply" in args; args = [a for a in args if a != "--apply"]
slug = args[0]
prefix = args[args.index("--prefix") + 1] if "--prefix" in args else "lib"
REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
RAW = f"{REPO}/libs/{slug}/raw/{prefix}"; WORK = f"{REPO}/libs/{slug}/work"

def skel(s): return "".join(c for c in s if ord(c) < 128)
def only_eaten(lat, w):
    """True when w's skeleton is lat's skeleton minus characters that directly follow a high byte."""
    a, b = skel(lat), skel(w)
    if a == b: return True
    # positions in a that sit right after a non-ASCII char of lat
    after = set(); k = 0
    for i, c in enumerate(lat):
        if ord(c) >= 128:
            after.add(k)
        else:
            k += 1
    sm = difflib.SequenceMatcher(None, a, b, autojunk=False)
    for op, i1, i2, j1, j2 in sm.get_opcodes():
        if op == "equal": continue
        if op != "delete": return False
        # difflib may credit an identical neighbour (`""`): accept either side of the high byte
        if any(i not in after and (i + 1) not in after for i in range(i1, i2)): return False
        if i2 - i1 > 2: return False
    return True

stats = {"files": 0, "lines": 0, "kept_edited": 0}
for dp, dn, fn in os.walk(RAW):
    for f in fn:
        rp = os.path.join(dp, f); rel = os.path.relpath(rp, RAW)
        wrel = rel[:-2] + ".lpc" if rel.endswith(".c") else rel
        wp = os.path.join(WORK, wrel)
        if not os.path.isfile(wp): continue
        rb = open(rp, "rb").read()
        if not any(b > 127 for b in rb): continue
        wraw = open(wp, "rb").read()
        try: wt = wraw.decode("utf-8")
        except UnicodeDecodeError: continue
        nl = "\r\n" if "\r\n" in wt else "\n"
        rl = [l.rstrip(b"\r").decode("latin-1") for l in rb.split(b"\n")]
        wl = wt.split(nl)
        rs = [skel(l).strip() for l in rl]; ws = [skel(l).strip() for l in wl]
        sm = difflib.SequenceMatcher(None, rs, ws, autojunk=False)
        changed = 0
        for op, i1, i2, j1, j2 in sm.get_opcodes():
            if op == "equal":
                pairs = zip(range(i1, i2), range(j1, j2))
            elif op == "replace" and (i2 - i1) == (j2 - j1):
                pairs = zip(range(i1, i2), range(j1, j2))
            else:
                continue
            for i, j in pairs:
                lat = rl[i]
                if all(ord(c) < 128 for c in lat): continue
                if wl[j] == lat: continue
                # keep the work line's own leading whitespace (a formatter may have reindented it)
                if only_eaten(lat.strip(), wl[j].strip()):
                    lead = wl[j][:len(wl[j]) - len(wl[j].lstrip())]
                    wl[j] = lead + lat.strip() if wl[j].strip() else lat
                    changed += 1
                else:
                    stats["kept_edited"] += 1
        if changed:
            stats["files"] += 1; stats["lines"] += changed
            if apply_: open(wp, "wb").write(nl.join(wl).encode("utf-8"))
print(stats)
