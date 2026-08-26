#include <mudlib.h>
inherit VERB_OB;

void do_construct_str(string str)
{
   CONSTRUCTOR->construct_object(this_body(), str);
}

void do_construct()
{
   write("Construct what?\n");
}

void create()
{
   add_rules( ({ "", "STR" }), ({ "craft" }) );
}