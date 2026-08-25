// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** mount.c
*/

#include <verb.h>
inherit VERB_OB;


void do_mount_str(string str)
{
	object o;
	mixed ret;
	o=ENV_OB(str);
	if(!o) {return;}
	ret=o->is_horse();
	if(ret==1)
	{
                o->ride();
		return;
	}
	if(!ret)
		ret="你没法骑"+o->short()+"。\n";
	write(ret);
	return;
} 

mixed * query_verb_info()
{
    return ({ ({ "STR" }),({"ride"}) });
}


