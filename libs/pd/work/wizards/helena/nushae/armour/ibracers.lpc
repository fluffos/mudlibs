#include <std.h>

inherit ARMOUR;

void create() {
  ::create();
    set_name("bracers");
    set_short("%^BOLD%^%^BLACK%^Iron %^RESET%^bracers");
    set_id(({ "iron bracers", "bracers" }));
    set_long("%^BOLD%^%^BLACK%^Two bracers made of tough iron mined straight from the Iron Mines of NuShae.");
    set_weight(5);
    set_curr_value("gold", 100-random(30));
    set_type("bracers");
    set_limbs(({ "left arm", "right arm" }));
    set_ac(2);
}

int query_auto_load() {
    if (this_player()->query_level() >= 25) return 1;
    return 0;
}
