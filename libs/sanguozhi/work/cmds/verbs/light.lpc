// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */
// ok
#include <verb.h>
inherit VERB_OB;

void do_light_str(string str) {
	object o;
	mixed ret;
	o=MYENV_OB(str);
	if(!o) return;
	(ret=o->direct_light_obj());
	if(ret==1)
	{
		o->do_light();
		return;
	}
	if(stringp(ret))
	{
		write(ret);
		return;
	}
	write("你没法点着"+o->short()+"。\n");
	return;
}

void do_light_str_with_str(string str , string str2) {
	object o1,o2;
	mixed ret;
	o1=MYENV_OB(str);
	if(!o1) return;
	o2=MYENV_OB(str2);
	if(!o2) return;
	ret=o1->direct_light_obj_with_obj(o1, 0);
	if(!ret)
		ret="你没法点着"+o1->short()+"。\n";
	if(stringp(ret))
	{
		write(ret);
		return;
	}
	ret=o2->indirect_light_obj_with_obj();
	if(!ret)
		ret=o2->short()+"点不了"+o1->short()+"。\n";
	if(stringp(ret))
	{
		write(ret);
		return;
	}

	o1->do_light(o2);

	return;
}

mixed * query_verb_info() {
    return ({ ({ "STR", "STR with STR" }) });
}

int need_to_see()
{
    return 0;
}
