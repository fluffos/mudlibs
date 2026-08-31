#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("robes");
    set_short("%^BOLD%^%^YELLOW%^Golden Robes%^RESET%^");
    set_long("These Robes are made of a very old slik "
             "The Robes are %^BOLD%^%^YELLOW%^Golden.%^RESET%^ "); 
    set_id( ({ "robes" , "golden robes" }) );
    set_ac(5);
    set_mass(25);
    set_value(300);
    set_type("robe");
    set_limbs( ({ "torso","head" }) );
}

int query_auto_load()
{                                  
 if (wizardp(this_player())) return 1;
 return 0;
}
                              
