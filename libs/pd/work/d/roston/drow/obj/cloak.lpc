#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("cloak");
    set_short("%^BOLD%^%^BLACK%^Da%^WHITE%^r%^BLACK%^k Clo%^WHITE%^a"
      "%^BLACK%^k%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This cloak is made of a material, that "
      "seems to be cobwebs, it seems very strange to you.");
    set_id( ({ "cloak" , "dark cloak" }) );
    set_ac(3);
    set_wear("%^BOLD%^%^BLACK%^Shadows seem to surround you.");
    set_remove("%^BOLD%^%^BLACK%^The shadows leave you.");
    set_mass(16);
    set_curr_value("gold", 108);
    set_type("cloak");
    set_limbs( ({ "torso","head","right arm","left arm" }) );
}

int query_auto_load()
{
    if (wizardp(this_player())) return 1;
    if(this_player()->query_level() < 50) return 0;
    return 1;
}

