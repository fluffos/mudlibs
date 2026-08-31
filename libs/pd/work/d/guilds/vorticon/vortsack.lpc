#include <std.h>
inherit ARMOUR;
inherit BAG;

void init() {
    armour::init();
}

void create() {
    armour::create();
    bag_logic::create();
    set_id( ({"vorticon sack", "skin sack", "human skin sack", "sack"}) );
    set_name("sack");
    set_short("%^ORANGE%^hu%^BOLD%^m%^RESET%^%^RED%^an s%^ORANGE%^ki%^RED%^%^BOLD%^n s%^RESET%^%^ORANGE%^a%^BOLD%^c%^RESET%^%^BOLD%^%^RED%^k%^RESET%^");
    set_weight(9);
    set_long("%^RED%^%^BOLD%^The sack of choice for members of the Vorticon Guild.  Keep it closed [close sack] to keep thieves away, but open it [open sack] if you want to place things inside.%^RESET%^");
    set_curr_value("gold", 250);
    set_max_internal_encumbrance(800);
    set_possible_to_close(1);
    set_type("backpack");
    set_limbs( ({"torso"}) );
}

int query_auto_load() {

    if (living(environment()) && environment()->query_guild() == "vorticon")
	return 1;
}
