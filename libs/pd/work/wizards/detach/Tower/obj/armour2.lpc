#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("armour");
    set_short("%^BOLD%^%^WHITE%^Le%^RESET%^%^ORANGE%^ath%^BOLD%^%^WHITE%^er Ar%^RESET%^%^ORANGE%^mo%^BOLD%^%^WHITE%^ur%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^This armour is made from a deep orange leather.");
    set_id( ({ "armour" , "leather armour" }) );
    set_ac(8);
    set_mass(32);
    set_value(50);
    set_type("armour");
    set_limbs( ({ "head","torso","left arm","right arm" }) );
}

int query_auto_load()
{
 if (wizardp(this_player())) return 1;
 return 1;
}
