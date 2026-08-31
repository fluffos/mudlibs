#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("Iron Plate");
    set_short("%^ORANGE%^Ir%^BOLD%^%^BLACK%^on Pla%^RESET%^%^ORANGE%^te%^RESET%^");
    set_long("This Iron Plate was forged by the best blacksmith in "
"all of Azeria. It seems to have a rusty tint to it.");
    set_id( ({ "plate" , "iron plate" }) );
    set_ac(8);
    set_mass(40);
     set_curr_value("gold",150+random(40));
    set_type("body armour");
    set_limbs( ({ "torso" }) );
}                  
int query_auto_load()
{
 if (wizardp(this_player())) return 1;
 return 1;
}
