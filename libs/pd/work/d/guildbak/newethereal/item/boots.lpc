#include <std.h>

inherit ARMOUR;

void create() {
    ::create();
    set_name("boots");
    set("id", ({"cloud boots", "boots"}) );
    set_short("%^CYAN%^Cl%^RESET%^ou%^CYAN%^d b%^RESET%^oo%^CYAN%^ts%^RESET%^");
    set_long("These strange clouds form to your feet, making you feel like you "
      "are walking on air!");
    set_ac(5);
    set_type("boots");
    set_limbs( ({"right foot", "left foot"}) );
}

int query_auto_load() {
    if (this_player()->query_guild() == "ethereal")
	return 1;
}


