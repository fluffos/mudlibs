#include <std.h>

inherit ARMOUR;

void create() {
    ::create();
    set_name("%^ORANGE%^ta%^RESET%^il%^ORANGE%^ti%^RESET%^es%^RESET%^");
    set_short("%^ORANGE%^ta%^RESET%^il %^ORANGE%^ti%^RESET%^es%^RESET%^");
    set_id(({ "ties", "tail ties", "tailties" }));
    set_long("They can be %^BOLD%^%^BLACK%^tied%^RESET%^ onto any %^ORANGE%^tail%^RESET%^.");
    set_weight(2);
    set_curr_value("gold", 5);
    set_type("armour");
    set_limbs(({ "tail" }));
    set_ac(2);
}

int query_auto_load()
{
    if(this_player()->query_level() > 20) return 1;
}
