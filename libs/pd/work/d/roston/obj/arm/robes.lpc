#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("robes");
    set_short("%^BOLD%^%^YELLOW%^Golden Robes%^RESET%^");
    set_long("These Robes are made of a very old silk "
             "The Robes are %^BOLD%^%^YELLOW%^Golden.%^RESET%^ "); 
    set_id( ({ "robes" , "golden robes" }) );
    set_ac(2);
    set_mass(25);
    set_curr_value("gold", 40);
    set_type("robes");
    set_limbs( ({ "torso","head" }) );
}

int query_auto_load()
{                                  
 if (wizardp(this_player())) return 1;
 return 0;
}
                              
