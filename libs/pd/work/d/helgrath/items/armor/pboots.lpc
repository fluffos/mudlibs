#include <std.h>
inherit ARMOUR;
void create() {
    ::create();
    set_name("Plated Boots");
    set_short("Plated Boots%^RESET%^");
    set_long("Steal plates have been riveted to hardened leather to make great protection for the wearer.");
    set_id( ({ "boots" , "plated boots" }) );
    set_ac(4);
    set_mass(23);
    set_curr_value("gold",50+random(40));
    set_type("boots");
    set_limbs( ({ "right foot","left foot" }) );
}                  
int query_auto_load()
{
 if (wizardp(this_player())) return 1;
 return 1;
}
