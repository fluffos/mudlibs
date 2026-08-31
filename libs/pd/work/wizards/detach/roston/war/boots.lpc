#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("War Boots");
    set_short("%^BOLD%^%^BLACK%^W%^RED%^a%^BLACK%^r "
"%^BLACK%^B%^RESET%^%^RED%^o%^BOLD%^%^BLACK%^o%^RESET%^%^RED%^t%^BOLD%^%^BLACK%^s%^RESET%^");
    set_long("These boots are forged for the dwarven war mages.");
    set_id( ({ "boots" , "war boots" }) );
    set_ac(16);
    set_wear("%^BOLD%^%^BLUE%^The power of war rush's into you.");
    set_remove("%^YELLOW%^The powers leave you.");
    set_mass(14);
    set_value(610);
    set_type("boots");
    set_limbs( ({ "right foot","left foot" }) );
}                  
int query_auto_load()
{
 if (wizardp(this_player())) return 1;
 return 1;
}  
