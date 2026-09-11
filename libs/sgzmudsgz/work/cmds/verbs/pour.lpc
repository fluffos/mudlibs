// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>
#include <setbit.h>

inherit M_PARSING;
inherit VERB_OB;

/* default */
mixed indirect_pour_obj_in_obj(object ob1, object ob2) {
    return "你无法把任何东西倒在" + ob2->short() + "里面。\n";
}

void do_pour_obj_in_obj(object ob1, object ob2) {
    ob1->pour_into(ob2);
}

mixed * query_verb_info(string rule)
{
return ({ ({ "OBJ in OBJ" }) });
}
