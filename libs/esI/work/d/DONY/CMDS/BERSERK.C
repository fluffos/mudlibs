#include <mudlib.h>
// #include "/u/d/dony/cmds/_berserk.c"
// #include "/u/d/dony/cmds/_kk.c"
inherit "/u/d/dony/cmds/_berserk";
inherit OBJECT;
void create()
{
	set_name("berserk spell", "狂暴术");
	add("id",({"spell"}));
	set_short("狂暴术");
	set_long(@C_LONG
狂暴术可以让你对敌人作狂暴攻击，你只要打(berserk)就可以了
。
C_LONG
	);
        set("prevent_drop",1);        
}       
int query_auto_load() { return 1; }

void init()
{
   add_action("cmd_berserk","berserk");
   add_action("cmd_faq","test");
} 
