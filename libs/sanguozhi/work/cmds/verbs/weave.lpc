// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>
#include <verb.h>
 
inherit VERB_OB;
 
void do_weave_str(string str) {

	object o;
	mixed ret;
	o=MY_OB(str);
	if(!o) {return;}
	ret=o->direct_weave_obj();
	if(ret==1)
	{
	    o->weave();
		return;
	}
	if(!ret)
		ret=o->short()+"好象没法编织。\n";
	write(ret);
	return;
}

/*void do_weave_obj_with_obj(object ob1, object ob2) {
    ob2->use("weave", ob1);
} */
 
mixed * query_verb_info()
{
  return ({ ({ "STR",  }) });
//  return ({ ({ "OBJ", "OBJ with OBJ" }) });
}