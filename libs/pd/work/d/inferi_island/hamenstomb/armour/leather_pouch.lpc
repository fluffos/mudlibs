#include <std.h>
#include <amun.h>
inherit ARMOUR;
inherit BAG; 

void init() {
    armour::init();
}                                                                       

void create() {
    armour::create();
    bag_logic::create();
    set_name("Black Leather Pouch");
    set_id( ({"pouch", "pack", "bag"}) );
    set_short("%^BOLD%^%^BLACK%^Black Leather Pouch%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This pouch is pure black and is used to hold items for its wearer.%^RESET%^" );
    set_weight(2);
    set_curr_value("gold", 22);
    set_possible_to_close(1);
    set_max_internal_encumbrance(500);
    set_type("backpack");
    set_limbs( ({"torso"}) );
}
int query_auto_load() {
    if (this_player()->query_level() >= 26)
	return 1;
}
