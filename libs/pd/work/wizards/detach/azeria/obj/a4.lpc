#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("Bronze Boots");
    set_short("%^ORANGE%^Br%^BOLD%^%^WHITE%^on%^RESET%^ze Bo%^BOLD%^%^WHITE%^o%^RESET%^%^ORANGE%^ts%^RESET%^");
    set_long("These Boots are made from the deepest colored bronze.");
    set_id( ({ "boots" , "bronze boots" }) );
    set_ac(8);
    set_mass(10);
     set_curr_value("gold",150+random(40));
    set_type("boots");
    set_limbs( ({ "right foot","left foot" }) );
}                  
int query_auto_load()
{
 if (wizardp(this_player())) return 1;
 return 1;
}
