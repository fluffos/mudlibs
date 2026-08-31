#include <std.h>

#include <caves.h>

inherit ARMOUR;

void create() {
::create();
    set_name("heavy platemail");
    set_short("Heavy %^BOLD%^%^BLACK%^Platemail%^RESET%^");
    set_long("Well made platemail which gives satisfaction protection.");
    set_id(({"armour", "platemail"}));
    set_ac(20);
    set_mass(50);
    set_value(150);
    set_type("armour");
    set_limbs(({"torso", "left arm", "right arm", "left leg", "right leg"}));
}

int query_auto_load() { 
    if (this_player() ->query_level() > 49) return 1;

}
