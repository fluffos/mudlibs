#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("mask");
    set_short("%^BOLD%^%^RED%^Bl%^BOLD%^%^BLACK%^oo%^BOLD%^%^RED%^d M%^BLACK%^as%^RED%^k");
    set_long("%^BOLD%^%^RED%^This Mask, is formed from Blood. It is magical enchanted to protect your face.");
    set_id( ({ "mask" , "blood mask" }) );
    set_ac(9);
    set_mass(2);
    set_value(25);
    set_type("mask");
    set_limbs( ({ "head" }) );
}

int query_auto_load()
{
 if (wizardp(this_player())) return 1;
 return 1;
}
