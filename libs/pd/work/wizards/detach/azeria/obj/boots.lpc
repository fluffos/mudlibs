#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("Skin Boots");
    set_short("%^BOLD%^%^BLACK%^S%^RESET%^%^RED%^kin %^BOLD%^%^BLACK%^B%^RESET%^%^RED%^oots");
    set_long("%^BOLD%^%^BLACK%^These boots were formed from the skin of Arch-Angels.");
    set_id( ({ "skin boots" , "boots" }) );
    set_ac(9);
    set_mass(5);
     set_curr_value("gold",150+random(40));
    set_type("boots");
    set_limbs( ({ "left foot","right foot" }) );
}                  
int query_auto_load()
{
 if (wizardp(this_player())) return 1;
 return 1;
}
