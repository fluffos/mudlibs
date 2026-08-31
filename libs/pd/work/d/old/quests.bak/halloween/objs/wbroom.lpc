#include <std.h>
#include <halloween.h>

inherit OBJECT;

void create()
{
 ::create();
 set_name("broom stick");

set_short("%^BLACK%^%^BOLD%^Br%^RESET%^%^BOLD%^%^CYAN%^oo%^BLACK%^%^BOLD%^m"
           "st%^RESET%^%^BOLD%^%^CYAN%^i%^RESET%^%^BLACK%^%^BOLD%^ck "
           "%^RESET%^%^BOLD%^%^CYAN%^o%^BOLD%^%^BLACK%^f th%^RESET%^%^BOLD%^%^CYAN%^e"
           "%^RESET%^ %^BOLD%^%^BLACK%^w%^RESET%^%^BOLD%^%^CYAN%^es%^BOLD%^"
           "%^BLACK%^t%^RESET%^");

 set_long("This is the magical broomstick belonging to the witch of the east.");
 set_mass(1);
 set_value(1);
 set_id( ({ "broomstick", "wbroom" }) );
 set_property("no steal", 1);
}
 
int get()
{
 if (present("nbroom", this_player()))
   {
    present("nbroom", this_player())->get();
    return 1;
   }
 
 write("The broomstick glows brightly.");
 return 1;
}
