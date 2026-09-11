// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>
#include <setbit.h>

inherit VERB_OB;


int can_cross_obj(object ob)
{
    return 1;
}


void do_cross_obj(object ob)
{
    ob->cross();
}

int direct_cross_obj(object ob)
{
    return 1;
}
  
array query_verb_info()
{
    return ({ ({ "OBJ" }) });
}
