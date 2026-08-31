#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("robes");
    set_short("%^BOLD%^%^BLACK%^M%^WHITE%^i%^BLACK%^s%^RESET%^t%^BOLD%^%^BLACK%^y A%^WHITE%^r%^BLACK%^m%^RESET%^o%^BOLD%^%^WHITE%^u%^BLACK%^r%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^This Armour seems to be a blanket of black mist, magical powers swirl around it.");
    set_id( ({ "armour" , "misty armour" }) );
    set_ac(10);
    set_mass(40);
    set_value(80);
    set_type("armour");
    set_limbs( ({ "right hand","left hand","head","torso","left arm","right arm" }) );
}

int query_auto_load()
{
 if (wizardp(this_player())) return 1;
 return 1;
}
