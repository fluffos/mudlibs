#!/usr/bin/env python3
"""Static hint for docs/kb/06-runtime-classes-2.md §7.203: list the
directories a lib writes into (save_object/write_file/rename/mkdir/cp/rm with
a literal or #define'd path, and log_file("sub/name") as log/sub) that a
fresh clone or the site's zip would not have: not a tracked directory and not
listed for the slug in scripts/wasm_keep_dirs.txt.  A directory that merely
exists in your working tree does not count (that is how the old check hid
Foundation I's log/secure).  A lib whose log_file() creates its own directory
(KB 05 §7.11) is fine either way.

Usage: python3 scripts/missing_write_dirs.py <slug> [<slug> ...]

Read-only. Expect noise: wizard areas (players/, w/, u/, d/..), rm targets and
rarely used admin commands show up too. A hit only matters when a command a
player or creator really runs writes there without making the directory
first; confirm by running that command on a pristine tree
(scripts/pristine_tree.sh).
"""
import os,re,sys,subprocess
from pathlib import Path
REPO=Path(__file__).resolve().parent.parent
WRITE=re.compile(r'\b(save_object|write_file|rename|mkdir|write_bytes|fopen|cp|rm)\s*\(\s*((?:"[^"\n]*"|[A-Z][A-Z_0-9]*)(?:\s*\+\s*(?:"[^"\n]*"|[A-Z][A-Z_0-9]*|[a-z_]\w*(?:\([^()\n]*\))?))*)')
LOGF=re.compile(r'\blog_file\s*\(\s*"([^"\n%]*/)[^"\n/%]*"')
DEF=re.compile(r'^#\s*define\s+([A-Z][A-Z_0-9]*)\s+"([^"\n]*)"',re.M)
def tracked_dirs(slug):
    out=subprocess.run(['git','-C',str(REPO),'ls-files','-z',f'libs/{slug}/work/'],capture_output=True).stdout.decode('utf-8','surrogateescape')
    dirs={'.'}; pre=f'libs/{slug}/work/'
    for f in out.split('\0'):
        if not f.startswith(pre): continue
        rel=Path(f[len(pre):]).parent
        while str(rel)!='.':
            dirs.add(rel.as_posix()); rel=rel.parent
    return dirs
def keep_dirs(slug):
    out=set()
    f=REPO/'scripts'/'wasm_keep_dirs.txt'
    if f.is_file():
        for line in f.read_text(encoding='utf-8',errors='replace').split('\n'):
            if line.startswith(slug+'\t'): out.add(line.split('\t',1)[1])
    return out
def run(slug):
    work=REPO/'libs'/slug/'work'
    if not work.is_dir(): return None
    tr=tracked_dirs(slug)|keep_dirs(slug)
    defs={}; files=[]
    for dp,dn,fn in os.walk(work):
        rel=Path(dp).relative_to(work).as_posix()
        if rel.split('/')[0] in ('doc','docs','backup','attic','old','u','log','www','temp') or '/attic' in rel: continue
        for f in fn:
            if f.endswith(('.lpc','.h','.c')): files.append(Path(dp)/f)
    texts={}
    for f in files:
        try: t=f.read_text(encoding='utf-8',errors='replace')
        except Exception: continue
        texts[f]=t
        if f.suffix=='.h':
            for m in DEF.finditer(t): defs.setdefault(m.group(1),m.group(2))
    found={}
    for f,t in texts.items():
        for m in WRITE.finditer(t):
            fn,arg=m.group(1),m.group(2)
            first=re.split(r'\s*\+\s*',arg)[0]
            if first.startswith('"'): lit=first.strip('"')
            else: lit=defs.get(first)
            if not lit or '%' in lit: continue
            lit=lit.lstrip('/')
            if '/' not in lit: continue
            d=lit.rsplit('/',1)[0]
            if not d or d.startswith('.'): continue
            found.setdefault(d,set()).add(f"{fn}@{f.relative_to(work).as_posix()}")
        for m in LOGF.finditer(t):
            d='log/'+m.group(1).strip('/')
            found.setdefault(d,set()).add(f"log_file@{f.relative_to(work).as_posix()}")
    missing={d:sorted(v)[:2] for d,v in found.items() if d not in tr}
    return missing
if __name__=='__main__':
    for slug in sys.argv[1:]:
        m=run(slug)
        if m is None: print(f"{slug}: no work/"); continue
        print(f"== {slug}: {len(m)} write targets whose directory is missing from the tree")
        for d,v in sorted(m.items())[:15]: print(f"   {d:<40} {v[0]}")
