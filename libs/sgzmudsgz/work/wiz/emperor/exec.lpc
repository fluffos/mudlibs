#include <mudlib.h>
#include <security.h>
inherit M_ACCESS;
create() { set_privilege(1); }

mixed exec_foo(){ return SGHOME("xmxm")->load_npc((SGHOME("xmxm")->check_npc("pos","sc"))[0])->stat_me();}
