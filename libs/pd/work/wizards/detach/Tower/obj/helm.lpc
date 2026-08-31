#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("mask");
    set_short("%^BOLD%^%^BLACK%^De%^RESET%^%^ORANGE%^mo%^BOLD%^%^BLACK%^n %^BOLD%^%^BLACK%^Ma%^RESET%^%^ORANGE%^s%^BOLD%^%^BLACK%^k%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This Mask seems to be a entire Demon Skull, covering your face, and head.");
    set_id( ({ "mask" , "demon mask" }) );
    set_ac(4);
    set_mass(5);
    set_value(11);
    set_type("helm");
    set_limbs( ({ "head" }) );
}

int query_auto_load()
{
 if (wizardp(this_player())) return 1;
 return 1;
}
