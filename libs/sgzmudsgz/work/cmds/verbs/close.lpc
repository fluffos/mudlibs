// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>
#include <verb.h>
#include <setbit.h>
// ok
inherit VERB_OB;

mixed can_close_obj(object ob)
{
   return 1;
}

mixed do_close_str(string str) {
	object o;
	mixed ret;
	o=ENVMY_OB(str);
	if(!o) {return;}
	ret=o->direct_close_obj();
	if(ret==1)
	{
		o->close();
		return;
	}
	if(!ret)
		ret=o->short()+"好象没法关。\n";
	write(ret);
	return;
}

mixed * query_verb_info() {
  return ({ ({ "STR" }) });
}
