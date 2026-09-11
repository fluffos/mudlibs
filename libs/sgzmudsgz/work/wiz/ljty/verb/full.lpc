// recover.c by fire on Jec 30 1997
// this cmd is just used for test period for player to
// recover the hp
#include <mudlib.h>
#include <ansi.h>
#include <sanguo.h>
inherit CMD;
void main() 
{
	int p_tmp;
	p_tmp=this_body()->query_sg_max_hp();
	this_body()->set_cur_max_hp(p_tmp);
	this_body()->set_cur_hp(p_tmp);
	this_body()->simple_action(HIG+
        "$N运起天地神功；一瞬间，一切伤痛全化为无。\n"+NOR);
}
