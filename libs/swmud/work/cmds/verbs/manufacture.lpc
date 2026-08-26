#include <mudlib.h>
inherit VERB_OB;

void do_manufacture_str(string str)
{
   MANUFACTURER->manufacture_object(this_body(), str);
}

void do_manufacture()
{
   write("Manufacture what?\n");
}

void create()
{
   add_rules( ({ "", "STR" }) );
}