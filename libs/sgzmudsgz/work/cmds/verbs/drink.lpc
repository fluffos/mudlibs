// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>
#include <setbit.h>
#include <verb.h>
//ok
inherit VERB_OB;

void do_drink_str(string str)
{
	object o;
	mixed ret;
	o=MYENV_OB(str);
	if(!o) return;
	if(ret=o->direct_drink_obj());
	if(ret==1)
	{
		o->drink_it();
		return;
	}
	if(stringp(ret))
	{
		write(ret);
		return;
	}
	write("你好象喝不成"+o->short()+"。\n");
	return;
}

// no need for drink from hoho:)
void do_drink_from_obj(object ob)
{
   if(!try_to_acquire(ob))
    return;
   ob->drink_from_it();
}

mixed * query_verb_info()
{
      return ({ ({ "STR" }) });
}
