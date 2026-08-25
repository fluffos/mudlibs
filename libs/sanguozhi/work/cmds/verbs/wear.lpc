// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>
#include <verb.h>
inherit VERB_OB;

void do_wear_str(string str)
{
	object o, *list;
	mixed ret;
	
	if( str=="all" ){
		list = all_inventory(this_body());
		list = filter_array(list, (: $1->direct_wear_obj()==1 :));
		foreach( o in list ) o->do_wear();
	} else {
		o = MY_OB(str);
		if( !o ) return;
		ret = o->direct_wear_obj();
		if( ret==1 ){
			o->do_wear();
			return;
		}
		if( !ret )
			ret = "你没法穿"+o->short()+"。\n";
		write(ret);
	}
	return;
}

mixed * query_verb_info() {
    return ({ ({ "STR" }) });
}

	
