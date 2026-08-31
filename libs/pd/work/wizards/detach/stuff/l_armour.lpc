#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("Dark Centaur Armour");
    set_short("%^BOLD%^%^BLACK%^D%^WHITE%^a%^BLACK%^r%^WHITE%^k "
"%^BLACK%^C%^WHITE%^e%^BLACK%^n%^WHITE%^t%^BLACK%^a%^WHITE%^u%^BLACK%^r "
"%^WHITE%^A%^BLACK%^r%^WHITE%^m%^BLACK%^o%^WHITE%^u%^BLACK%^r%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This Armour belongs to the bigest "
  "and evilest centaur in the lands of Primal Darkness.");
    set_id( ({ "armour" , "centaur armour","dark centaur armour" }) );
    set_ac(17);
    set_mass(55);
    set_wear("%^BOLD%^%^BLACK%^The powers of evil wrap around your body.");
    set_remove("%^BOLD%^%^WHITE%^You feel the evilness leave your body.");
    set_value(0);
    set_type("body armour");
    set_limbs( ({ "head","torso","right arm","left arm","left foreleg","right foreleg","right rear leg","left rear leg","tail" }) );
}

int query_auto_load()
{
 if (wizardp(this_player())) return 1;
 return 1;
}
