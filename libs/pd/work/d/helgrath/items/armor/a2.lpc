#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("Iron Boots");
    set_short("%^ORANGE%^Ir%^BOLD%^%^BLACK%^on Boo%^RESET%^%^ORANGE%^ts%^RESET%^");
    set_long("These boots are made from a rusty old iron, found in "
"the lands of Azeria.");
    set_id( ({ "boots" , "iron boots" }) );
    set_ac(4);
    set_mass(10);
     set_curr_value("gold",50+random(40));
    set_type("boots");
    set_limbs( ({ "right foot","left foot" }) );
}                  
int query_auto_load()
{
 if (wizardp(this_player())) return 1;
 return 1;
}
