// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <verb.h>
//ok
inherit VERB_OB;

void do_climb_str(string str) {
	object o;
	mixed ret;
	o=ENV_OB(str);
	if(!o) {return;}
	ret=o->direct_climb_obj();
	if(ret==1)
	{
		o->climb();
		return;
	}
	if(!ret)
		ret=o->short()+"好象没法爬。\n";
	write(ret);
	return;
}

void do_climb_up_obj(object ob) {
    ob->climb("up");
}

void do_climb_down_obj(object ob) {
    ob->climb("down");
}
// up and down will consider later
mixed * query_verb_info() {
    return ({ ({ "STR" }) });
}
