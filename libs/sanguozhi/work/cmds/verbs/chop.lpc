// chop.c by fire@lima on Nov 19,1998
#include <mudlib.h>
#include <verb.h>
inherit VERB_OB;
void do_chop_str_with_str(string st1, string st2)
{
	object ob1,ob2;
	ob1=ENVMY_OB(st1);
	if(!ob1){ return;}
	ob2=MY_OB(st2);
	if(!ob2){ return;}
    if(!ob2->can_chop_with_obj())
	{
		write(ob2->short()+"好象没法用来砍东西。\n");
		return;
	}
	if(!ob1->is_choppable())
	{
		write(ob1->short()+"好象不能砍。\n");
		return;
	}
	ob2->do_chopping(ob1);
}
mixed * query_verb_info()
{
    return ({ ({ "STR with STR", }) });
}
