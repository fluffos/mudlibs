#!/usr/bin/env python3
"""Rewrite LDMud string escapes in save files into the bytes FluffOS restores (KB 03).

LDMud's save_object() writes a newline inside a string as the two characters `\\n` (and a tab as
`\\t`).  FluffOS writes a newline as a raw CR byte and its restore_object() turns `\\X` back into a
plain `X`, so every LDMud-saved newline comes back as a literal `n` (mail, board posts, player
descriptions).  Inside quoted strings this script turns `\\n` into a CR byte and `\\t` into a tab;
`\\"` and `\\\\` mean the same in both drivers and are kept.  `\\r` is kept too: FluffOS cannot hold
a CR in a restored string at all (a raw CR restores as a newline).

  python3 scripts/ldmud_save_newlines.py [--apply] [--all] PATH...

PATH is a file or a directory (walked for `*.o`).  Only files that start with LDMud's `#N:M` version
line are touched unless --all is given."""
import os, re, sys

args = sys.argv[1:]
apply_ = "--apply" in args
all_ = "--all" in args
paths = [a for a in args if not a.startswith("--")]
HDR = re.compile(rb"#\d+:\d+\r?\n")


def fix(data):
    out = bytearray(); n = 0; i = 0; L = len(data); instr = False
    while i < L:
        c = data[i]
        if instr:
            if c == 0x5C and i + 1 < L:          # backslash: an escape pair
                e = data[i + 1]
                if e == 0x6E: out.append(0x0D); n += 1   # \n -> CR (FluffOS's saved newline)
                elif e == 0x74: out.append(0x09); n += 1  # \t -> tab
                else: out += data[i:i + 2]
                i += 2; continue
            if c == 0x22: instr = False
            elif c == 0x0A: instr = False            # a broken string never runs past its line
        elif c == 0x22:
            instr = True
        out.append(c); i += 1
    return bytes(out), n


def files():
    for p in paths:
        if os.path.isdir(p):
            for root, _, fs in os.walk(p):
                for f in sorted(fs):
                    if f.endswith(".o"): yield os.path.join(root, f)
        else:
            yield p


nf = ne = 0
for f in files():
    d = open(f, "rb").read()
    if not all_ and not HDR.match(d): continue
    new, n = fix(d)
    if not n: continue
    nf += 1; ne += n
    if apply_: open(f, "wb").write(new)
print(f"{nf} files, {ne} escapes" + ("" if apply_ else " (dry run)"))
