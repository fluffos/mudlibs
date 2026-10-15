#!/usr/bin/env python3
"""scripts/lpc_action_index.py [SLUG...]   (report only)

query_action() indexing past the end of the skill's own move table (KB 06 section 7.243): `action[random(9) + 6]`
in a file whose `mapping *action` has 8 moves, `action[5]` with 5, `action[random(7)]` with 4.  Every attack that
draws such an index raises `Array index out of bounds` (kxkj's lonely-sword: 160 of 200 attacks at level 100).
Counts the top-level `([ ... ])` entries of `mapping *action = ({ ... })` and the largest literal index (a constant, or
`random(A) + B`), in code only, for kungfu/skill and daemon/skill.  A hit inside a branch only a perform's temp flag
reaches (xyj's `else return action[5];` under `query_temp("X_perform")`) is dead when nothing sets the flag: grep
for `set_temp("X_perform"` before fixing.  Prints lib, file, moves, largest index, the index expression."""
import collections
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from lpc_fix_void_return import code_mask  # noqa: E402

os.chdir(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
WANT = set(a for a in sys.argv[1:] if not a.startswith("-"))
skip=re.compile(r'/(u|w|open|players|backup|old|bak|log|data|doc)/')
IDX=re.compile(rb'\baction\s*\[\s*(?:random\s*\(\s*(\d+)\s*\)\s*(?:\+\s*(\d+))?|(\d+))\s*\]')
def count_actions(b,mask):
    m=re.search(rb'mapping\s*\*\s*action\s*=\s*\(\{',b)
    if not m: return None
    i=m.end(); depth=1; n=0; k=i
    while k<len(b) and depth>0:
        if mask[k]:
            if b[k:k+2]==b'([' : 
                if depth==1: n+=1
                depth+=1; k+=2; continue
            if b[k:k+2]==b'])' or b[k:k+2]==b'})':
                depth-=1; k+=2; continue
            if b[k:k+2]==b'({': depth+=1; k+=2; continue
        k+=1
    return n
res=[]
for s in sorted(os.listdir('libs')):
    if WANT and s not in WANT: continue
    W=f'libs/{s}/work'
    if os.path.exists(W+'/.git'): continue
    for d in ('kungfu/skill','daemon/skill'):
        D=f'{W}/{d}'
        if not os.path.isdir(D): continue
        for f in os.listdir(D):
            if not f.endswith('.lpc'): continue
            p=f'{D}/{f}'; b=open(p,'rb').read()
            if b'action[' not in b and b'action [' not in b: continue
            mask=code_mask(b)
            n=count_actions(b,mask)
            if not n: continue
            mx=-1; ex=None
            for m in IDX.finditer(b):
                if not mask[m.start()]: continue
                if m.group(3): v=int(m.group(3))
                else: v=int(m.group(1))-1+int(m.group(2) or 0)
                if v>mx: mx=v; ex=m.group(0).decode()
            if mx>=n: res.append((s,p[len(W):],n,mx,ex))
print(len(res),'files',len({r[0] for r in res}),'libs')
c=collections.Counter(r[1] for r in res)
print(c.most_common(25))
for r in res: print(*r, sep='\t')
