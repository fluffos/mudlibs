// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** dig.c  by Rust.  Shows off the fact that we can be smart about finding
** out what people mean.
*/

// all seem rubbish to me hehe
// ok
#include <mudlib.h>
#include <verb.h>
inherit VERB_OB;
void do_dig_str_with_str(string st1, string st2)
{
	object ob1,ob2;
	ob1=ENVMY_OB(st1);
	if(!ob1){ return;}
	ob2=MY_OB(st2);
	if(!ob2){ return;}
    if(!ob2->can_dig_with_obj())
	{
		write(ob2->short()+"好象没法用来挖东西。\n");
		return;
	}
	if(!ob1->is_digable())
	{
		write(ob1->short()+"好象不能挖。\n");
		return;
	}
	ob2->do_digging(ob1);
}
mixed * query_verb_info()
{
    return ({ ({ "STR with STR", }) });
}
