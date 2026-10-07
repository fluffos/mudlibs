#!/usr/bin/env python3
"""scripts/lpc_nitan_family_fixes.py SLUG

The hand fixes of the nitan_ceshi compile-warning pass (2026-10-06, ae7fbb619a5), for the nitan-family libs whose copies
of these files differ from nitan_ceshi's so scripts/lpc_twin_port.py does not carry them.  Each edit is applied only where
its exact shape is present, and the script prints how many places it changed per file:
  logind.lpc / fingerd.lpc   locals read only under `#ifdef DB_SAVE` / `#ifndef NO_FEE` declared under the same condition
  questd.lpc                 the empty last `else if ((total_count % 10) == 0) { /* ... */ }`
  natured.lpc                the no-op `lt[LT_MON];`
  combatd.lpc                the no-op `your_temp["guarding"];`
  genmap / traverser / youming   the empty `#define DEBUG` -> a no-op function (no variadic macros in this driver)
  luan2 / men2               the unreachable `"\\n";` after `return`
  backupd.lpc                `/*` inside a comment ("enchase/*jewel1*")
Run the warning scan afterwards; nothing here changes behaviour."""
import re, sys
import os
if len(sys.argv) != 2:
    sys.exit(__doc__)
slug=sys.argv[1]; base=os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "libs", slug, "work") + "/"
def sub(p, pat, rep, flags=0):
    try: b=open(base+p,'rb').read()
    except FileNotFoundError: print(f'  {p}: absent'); return
    b2,n=re.subn(pat,rep,b,flags=flags)
    print(f'  {p}: {n}')
    if n: open(base+p,'wb').write(b2)
NL=rb'(\r?\n)'
sub('adm/daemons/fingerd.lpc',
    rb'  string msg, mud, where;(\r?\n)  int public_flag;\r?\n  string cname;\r?\n  string email, \*ret;\r?\n  string sql, ip_number;\r?\n  string \*res;\r?\n  int flag;\r?\n',
    rb'  string msg, mud;\1  int public_flag;\1  string cname;\1  string email;\1#ifdef DB_SAVE\1  string where, *ret;\1  string sql, ip_number;\1  string *res;\1  int flag;\1#endif\1')
sub('adm/daemons/logind.lpc', rb'(  object ppl, \*usr;(\r?\n))  string where;\r?\n  string \*res;\r?\n', rb'\1#ifdef DB_SAVE\2  string where;\2  string *res;\2#endif\2')
sub('adm/daemons/logind.lpc', rb'(protected void get_cruisepwd\(string pass, object ob\) \{(\r?\n))  string sites;\r?\n  string passwd;\r?\n', rb'\1#ifdef DB_SAVE\2  string sites;\2  string passwd;\2#endif\2')
sub('adm/daemons/logind.lpc', rb'(  object user;(\r?\n))  string \*res, str, str1, str2;\r?\n  int on, fee, i, rec = 0;\r?\n', rb'\1#ifndef NO_FEE\2  string *res, str, str1, str2;\2  int on, fee, i;\2#endif\2  int rec = 0;\2')
sub('adm/daemons/questd.lpc', rb'(\n    )\} else if \(\(total_count % 10\) == 0\) \{(\r?\n      /\*.*?\*/\r?\n)    \}\r?\n',
    lambda m: m.group(1) + b'}\n    // (total_count % 10) == 0:' + m.group(2), re.S)
sub('adm/daemons/natured.lpc', rb'\n[ \t]*lt\[LT_MON\];[ \t]*\r?(?=\n)', b'')
sub('adm/daemons/combatd.lpc', rb'\n[ \t]*your_temp\["guarding"\];[ \t]*\r?(?=\n)', b'')
for p in ['clone/obj/genmap.lpc','clone/obj/traverser.lpc','kungfu/skill/linji-zhuang/youming.lpc']:
    sub(p, rb'^#define DEBUG[ \t]*(\r?)$', rb'#define DEBUG debug_off\1\nprivate void debug_off(string fmt, mixed args...) {}\1', re.M)
for p in ['d/jingzhou/luan2.lpc','d/lingjiu/men2.lpc']:
    sub(p, rb'(NOR;\r?\n)  "\\n";\r?\n', rb'\1')
sub('adm/daemons/backupd.lpc', rb'"enchase/\*(jewel\d)\*"', rb'"enchase/" + "*\1*"')
