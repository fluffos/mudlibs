#!/usr/bin/env python3
"""scripts/lpc_damage_types.py [SLUG...]   (report only)

receive_damage()/receive_wound() called with a type the lib's own feature/damage.lpc rejects (KB 06 section 7.241):
xkx-lineage content (jing/qi/neili/jingli) imported into an ES/xyj lib that keeps gin/kee/sen, or the reverse, or a
resource passed as damage (`receive_damage("neili", -5)` for `add("neili", -5)`).  The call raises
`F_DAMAGE: 伤害种类错误` at run time, so practising such a skill or taking such a hit stops with an error.  Reads each lib's
allowed types from the `type != "..."` tests in receive_damage()/receive_wound(); skips wizard, backup and data dirs.
Prints files per lib and the offending types; writes $LPC_SCRATCH/damage_types.json."""
import collections
import json
import os
import re
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SCRATCH = os.environ.get("LPC_SCRATCH") or os.path.expanduser("~/.cache/lpc-scratch")
os.chdir(REPO)
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from lpc_fix_void_return import code_mask  # noqa: E402
WANT = set(a for a in sys.argv[1:] if not a.startswith("-"))
out=collections.defaultdict(list)
allowed_of={}
for s in sorted(os.listdir('libs')):
    if WANT and s not in WANT: continue
    W=f'libs/{s}/work'; f=f'{W}/feature/damage.lpc'
    if not os.path.isfile(f) or os.path.exists(W+'/.git'): continue
    d=open(f,'rb').read().decode('utf-8','replace')
    allowed={}
    for fn in ('receive_damage','receive_wound'):
        i=d.find('int '+fn+'(')
        if i<0: continue
        a=set(re.findall(r'type\s*!=\s*"(\w+)"',d[i:i+1500]))
        if a: allowed[fn]=a
    if not allowed: continue
    allowed_of[s]=allowed.get('receive_damage',set())
    pat=re.compile(rb'(receive_damage|receive_wound)\(\s*"(\w+)"')
    for dp,dn,fn in os.walk(W):
        if re.search(r'/(u|w|open|players|backup|old|bak|log|data|doc)(/|$)',dp[len(W):]): continue
        for x in fn:
            if not x.endswith('.lpc'): continue
            p=os.path.join(dp,x); b=open(p,'rb').read()
            ms=list(pat.finditer(b))
            if not ms: continue
            mask=code_mask(b)
            for m in ms:
                if not mask[m.start()]: continue
                func=m.group(1).decode(); t=m.group(2).decode()
                if func in allowed and t not in allowed[func]:
                    out[s].append((p[len(W):],func,t))
tot=collections.Counter()
for s,v in out.items():
    for f,func,t in v: tot[(s,t)]+=1
bylib=collections.Counter({s:len({f for f,_,_ in v}) for s,v in out.items()})
for s,n in bylib.most_common(): print(n,s,sorted({t for f,_,t in out[s]}),sorted(allowed_of[s]))
print('TOTAL files',sum(bylib.values()),'libs',len(bylib))
json.dump({s:v for s,v in out.items()},open(f'{SCRATCH}/damage_types.json','w'))
