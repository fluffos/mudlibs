/*
   jacket.c

   A sample armour
*/
inherit "/std/armour";

#include <macros.h>

void
create_armour()
{
    set_name("jacket");
    set_short("leather jacket");
    set_adj("leather"); add_adj("rugged");
    set_long("It is a very rugged looking jacket, quite nice though.\n");
    
    set_default_armour();
}

string
query_recover()
{
    return MASTER + ":" + query_arm_recover();
}

void
init_recover(string arg)
{
    init_arm_recover(arg);
}
