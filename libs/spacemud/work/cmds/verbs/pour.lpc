/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>
#include <setbit.h>

inherit VERB_OB;

//: COMMAND
// USAGE
//
//  |  ``pour <something>``
//  |  ``pour <something> <preposition> <something>``
//  |  ``pour <something> out``
//  |  ``empty <something>``
//
//  Pour the coffee, pour the cream into the cup, pour the rest out, empty it all out.
//
// .. TAGS: RST

void do_pour_obj(object ob)
{
   ob->pour(0, environment(this_body()));
}

/* default */
mixed indirect_pour_obj_wrd_obj(object ob1, string wrd, object ob2)
{
   return "You can't pour anything " + wrd + ob2->the_short() + "\n";
}

void do_pour_obj_wrd_obj(object ob1, string wrd, object ob2)
{
   ob1->pour(wrd, ob2);
}

void do_pour_obj_out(object ob)
{
   ob->pour(0, environment(this_body()));
}

void create()
{
   add_rules(({"OBJ", "OBJ WRD OBJ", "OBJ out"}), ({"empty"}));
}
