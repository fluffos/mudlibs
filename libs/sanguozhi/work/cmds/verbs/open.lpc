// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>
#include <setbit.h>
#include <verb.h>
inherit VERB_OB;

/* open <something destroyable> with <weapon> */
/* mixed direct_open_obj_with_obj(object ob1, object ob2) {
    if (!ob1) return 1;
    return ob1->test_flag(DESTROYABLE);
}

mixed indirect_open_obj_with_obj(object ob1, object ob2) {
    if (!ob2) return 1;
    if (ob2 == this_body()) return "多么古怪的想法啊...\n";
    return ob2->is_weapon();
} */

void open(object ob, object with)
{
    if (with) {
        try_to_acquire(with);
        if (with->is_weapon() && ob->test_flag(DESTROYABLE)) {
            this_body()->simple_action("$N试图打开$o，却暴力地用$p$o1把$o敲成了碎片。", ob, with);
            ob->remove();
            return;
        }
    }
    ob->open_with(with);
}

/* void do_open_obj_with_obj(object ob1, object ob2) {
    open(ob1, ob2);
} 

void do_open_up_obj(object ob) {
    open(ob, 0);
} */

void do_open_str(string str) {

	object o;
	mixed ret;
	o=ENVMY_OB(str);
	if(!o) {return;}
	ret=o->direct_open_obj();
	if(ret==1)
	{
		open(o,0);
		return;
	}
	if(!ret)
		ret=o->short()+"好象没法打开。\n";
	write(ret);
	return;
}

mixed * query_verb_info()
{
    return ({ ({ "STR", }) });
//    return ({ ({ "STR", "up OBJ", "OBJ with OBJ" }) });
}
