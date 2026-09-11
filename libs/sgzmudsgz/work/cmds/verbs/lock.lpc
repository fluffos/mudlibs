// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>
#include <verb.h>
inherit VERB_OB;
inherit M_PARSING;

/* void do_lock_obj_with_obj(object ob1, object ob2) {
    ob1->lock_with(ob2);
} */

void do_lock_str_with_str(string door,string key)
{
	object ob_d,ob_k;
	mixed ret;
	ob_d=MYENV_OB(door);
	if(!ob_d) return;
	ob_k=MY_OB(key);
	if(!ob_k) return;

	ret=ob_d->direct_lock_obj_with_obj();
	if(!ret)
	{
		ret="没法用"+ob_k->short()+"锁"+ob_d->short()+"。\n";
	}
	if(stringp(ret))
	{
		write(ret);
		return;
	}
    ob_d->lock_with(ob_k);
}

void do_lock_str(string str)
{
	do_lock_str_with_str(str,"key");
}

mixed * query_verb_info()
{
    return ({ ({ "STR", "STR with STR" }) });

}
