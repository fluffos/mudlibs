// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>
#include <setbit.h>
#include <verb.h>
//ok
inherit VERB_OB;

void do_bite_str(string str)
{
	object o;
	mixed ret;
	o=MY_OB(str);
	if(!o) return;
	if(ret=o->direct_bite_obj());
	if(ret==1)
	{
		o->eat_it();
		return;
	}
	if(stringp(ret))
	{
		write(ret);
		return;
	}
	write("你好象咬不动"+o->short()+"。\n");
	return;
		
}
/* void do_bite_obj(object ob)
{
    if (!try_to_acquire(ob))
	return;

    ob->eat_it();
} */

mixed * query_verb_info()
{
    return ({ ({ "STR" }), ({ "eat" }) });
}
