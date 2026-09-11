// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>
#include <setbit.h>
#include <verb.h>
//ok
inherit M_PARSING;
inherit VERB_OB;

int do_fill_it(object ob, object with)
{
    if (!with) 
	{
        with = present("water", this_body()) || present("water", environment(this_body()));
        if (!with) 
		{
            write("用什么？\n");
            return 1;
        }
//        write("(with water)\n");
        with=load_object("/obj/water"); // modified by fire
    }
    ob->fill_with(with);
}

void do_fill_str(string str)
{
	object o;
	mixed ret;
	o=MYENV_OB(str);
	if(!o) {return;}
	ret=o->direct_fill_obj();
	if(ret==1)
	{
		do_fill_it(o,0);
		return;
	}
	if(!ret)
		ret=o->short()+"好象没法盛东西。\n";
	write(ret);
	return;

}
// this part later
/*void do_fill_obj_with_obj(object ob1, object ob2) {
    do_fill_it(ob1, ob2);
}*/

mixed * query_verb_info(string rule)
{
	return ({ ({ "STR" }) });
}
