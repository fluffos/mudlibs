// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>
#include <verb.h>

inherit VERB_OB;
inherit M_PARSING;
void do_unlock_str_with_str(string door,string key)
{
	object ob_d,ob_k;
	mixed ret;
	ob_d=MYENV_OB(door);
	if(!ob_d) return;
	ob_k=MY_OB(key);
	if(!ob_k) return;

	ret=ob_d->direct_unlock_obj_with_obj(ob_d, ob_k);
	if(!ret)
	{
		ret="你不能用"+ob_k->short()+"打开"+ob_d->short()+"。\n";
	}
	if(stringp(ret))
	{
		write(ret);
		return;
	}

	ob_d->unlock_with(ob_k);
}

void do_unlock_str(string str) {
	do_unlock_str_with_str(str,"key");
}

mixed * query_verb_info()
{
  return ({ ({ "STR", "STR with STR" }) });
}
