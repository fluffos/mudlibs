// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** drop.c
**
*/

#include <mudlib.h>
#include <move.h>

inherit VERB_OB;



#include <mudlib.h>
#include <setbit.h>
#include <verb.h>
//ok
inherit VERB_OB;

void do_throw_str(string str)
{
	object o;
	mixed ret;
	o=MY_OB(str);
	if(!o) return;
	if(ret=o->throw());

	if (!ret) ret = "你没法抛"+o->short()+"。\n";

    if (stringp(ret)) {
        write(ret);
    }

		
}

mixed * query_verb_info()
{
    return ({ ({ "STR" })});
}

