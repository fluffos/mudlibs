#include <std.h>
#include <halloween.h>

inherit OBJECT;

void create()
{
 ::create();
 set_name("broom stick");
 set_short("%^BLACK%^%^BOLD%^Br%^RESET%^%^ORANGE%^oo%^BLACK%^%^BOLD%^m"
           "st%^RESET%^%^ORANGE%^i%^RESET%^%^BLACK%^%^BOLD%^ck "
           "%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^f th%^RESET%^%^ORANGE%^e"
           "%^RESET%^ %^BOLD%^%^BLACK%^n%^RESET%^%^ORANGE%^or%^BOLD%^"
           "%^BLACK%^th%^RESET%^");

 set_long("This is the magical broomstick belonging to the witch of the north.");
 set_mass(1);
 set_value(1);
 set_id( ({ "broomstick", "nbroom" }) );
 set_property("no steal", 1);
}

int check_finish_quest()
{
 if (present("ebroom", this_player() ) &&
     present("wbroom", this_player() ) )
   {
   write("The broomsticks meld together.\nA huge lightning bolt shoots off the tip of the glowing broomstick.\nThe broomstick shatters into a million peices.");
    HALLOWEEN_D->continue_quest(0);
    present("ebroom", this_player())->remove();
    present("wbroom", this_player())->remove();
    present("nbroom", this_player())->remove();
    return 1;
   }
}
int get()
{
 call_out("check_finish_quest", 0);
 write("The broomstick hums in your hands.");
 
return 1;
}


